#!/usr/bin/env python3
"""protofix2.py: algorithmic, evidence-driven repair of extern declarations.

The matched C files carry their own `extern` declarations.  Many differ from the
callee's definition.  protofix.py aligns a declaration to the definition and keeps
the change only when the caller still compiles and the match verdict holds.  Most
changes failed that test because the caller then needs a cast or a different call.
This tool repairs the caller by rule and keeps the result only when it verifies.

Every decision is a deterministic rule over evidence: GCC diagnostics (JSON, with
exact source ranges), the definitions, and the original assembly listing.  There
is no search over source variants, no permuter and no model judgement at run time.

Layers
  edit engine       byte-span edits, conflict-free application, line-ending aware
  diagnostics       GCC -fdiagnostics-format=json, classified by message pattern
  verification      pf.evaluate / pf.compare_eval (both compile modes, tu for units,
                    GCC syntax check) against the verdicts of the original file
  transactions      all-or-nothing sets of file edits, deterministic isolation of the
                    failing declarations (divide and conquer over the unit list)
  families          callee (region, address) -> definition file + declarer files,
                    ordered callee-first
  stages            2 cast repair, 3 type propagation, 4 argument count, 5 width,
                    6 void versus value (see the --stage option)

usage
  python tools/protofix2.py score   [--out DIR]
  python tools/protofix2.py run     [--stage N] [--files LIST | --glob G | --sample N]
                                    [--jobs 6] [--out DIR] [--dry-run]
  python tools/protofix2.py show FILE          show proposals, repaired text diff, no write
"""
import argparse
import bisect
import collections
import concurrent.futures as cf
import csv
import difflib
import fnmatch
import json
import os
import pickle
import random
import re
import shutil
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import protofix as pf  # noqa: E402

ROOT = pf.ROOT
GCC = pf.GCC
SP = ('<home>/AppData/Local/Temp/claude/<project>/'
      'd965be22-e087-410a-b91d-ae680804241d/scratchpad')
DEFAULT_OUT = SP + '/protofix2'

# ---------------------------------------------------------------------------
# edit engine
# ---------------------------------------------------------------------------


class Edit:
    """Replace text[start:end] by new.  A pure insertion has start == end."""
    __slots__ = ('start', 'end', 'new', 'unit', 'why')

    def __init__(self, start, end, new, unit=None, why=''):
        self.start, self.end, self.new, self.unit, self.why = start, end, new, unit, why

    def key(self):
        return (self.start, self.end, self.new)

    def __repr__(self):
        return 'Edit(%d,%d,%r,%s,%s)' % (self.start, self.end, self.new, self.unit, self.why)


def apply_edits(text, edits):
    """Apply as many non-overlapping edits as possible, in span order.  Returns
    (new text, accepted, deferred).  Identical edits count once.  Two insertions at
    one offset both apply in the order given.  An edit that overlaps an accepted
    one is deferred (the caller re-diagnoses and produces it again)."""
    seen, uniq = set(), []
    for e in edits:
        if e.key() in seen:
            continue
        seen.add(e.key())
        uniq.append(e)
    order = sorted(range(len(uniq)), key=lambda i: (uniq[i].start, uniq[i].end, i))
    acc, dfr, last_end, last_start = [], [], -1, -1
    for i in order:
        e = uniq[i]
        if e.start < last_end or (e.start == last_start and e.end > e.start and last_end > last_start):
            dfr.append(e)
            continue
        acc.append(e)
        last_end = max(last_end, e.end)
        last_start = e.start
    out, pos = [], 0
    for e in acc:
        out.append(text[pos:e.start])
        out.append(e.new)
        pos = e.end
    out.append(text[pos:])
    return ''.join(out), acc, dfr


def file_eol(text, pos=0):
    """Line ending in use near pos (CRLF when the first line break after pos has CR)."""
    i = text.find('\n', pos)
    if i < 0:
        i = text.find('\n')
    return '\r\n' if i > 0 and text[i - 1] == '\r' else '\n'


def read_text(path):
    with open(path, 'rb') as f:
        return f.read().decode('latin1')


def write_text(path, text):
    with open(path, 'wb') as f:
        f.write(text.encode('latin1'))


def eol_signature(text):
    """Multiset of line endings: the proof that a rewrite kept every ending."""
    return (text.count('\r\n'), text.count('\n') - text.count('\r\n'),
            text.count('\r') - text.count('\r\n'))


# ---------------------------------------------------------------------------
# GCC diagnostics with ranges
# ---------------------------------------------------------------------------

class Diag:
    __slots__ = ('kind', 'msg', 'caret', 'start', 'finish', 'notes', 'line', 'macro', 'note', 'strict')

    def __repr__(self):
        return 'Diag(%s %r @%s [%s,%s])' % (self.kind, self.msg, self.caret, self.start, self.finish)


def line_offsets(text):
    offs = [0]
    for m in re.finditer('\n', text):
        offs.append(m.end())
    return offs


def _loc_off(offs, loc):
    return offs[loc['line'] - 1] + loc.get('byte-column', loc.get('column', 1)) - 1


# Pointer conversions GCC only warns about but the DS compiler rejects ("illegal
# implicit conversion from 'unsigned char *' to 'const char *'").  GCC reports them
# as errors with the option name; they only propose casts (see diag_edits) and are
# never counted as remaining errors, so a conversion the original already had
# does not fail a trial.
STRICT = ('-Werror=pointer-sign', '-Werror=discarded-qualifiers',
          '-Werror=discarded-array-qualifiers')


def gcc_json(text, workdir, name='f.c'):
    """Run GCC on text.  Returns a list of Diag (errors only, each with children notes).
    Offsets index text (latin1: one char per byte).  finish is exclusive.  Diag.strict
    marks an error raised only by the STRICT options."""
    os.makedirs(workdir, exist_ok=True)
    p = os.path.join(workdir, name)
    write_text(p, text)
    so, both = pf.sh([GCC, '-fsyntax-only', '-std=c99', '-fno-builtin'] + list(STRICT) +
                     ['-fdiagnostics-format=json', p])
    # stderr holds the JSON array; `sh` returns stdout and stdout+stderr
    err = both[len(so):].strip() if both.startswith(so) else both.strip()
    return parse_gcc_json(err, text)


def parse_gcc_json(err, text):
    out = []
    i = err.find('[')
    if i < 0:
        return out
    try:
        arr, _ = json.JSONDecoder().raw_decode(err[i:])
    except ValueError:
        return out
    offs = line_offsets(text)
    for d in arr:
        if d.get('kind') != 'error':
            continue
        x = Diag()
        x.kind, x.msg = d['kind'], d['message']
        x.strict = d.get('option', '') in STRICT
        x.caret = x.start = x.finish = None
        x.line = None
        x.macro = False
        x.note = ''
        locs = d.get('locations') or []
        if locs:
            l0 = locs[0]
            x.line = l0['caret']['line']
            try:
                x.caret = _loc_off(offs, l0['caret'])
                if 'start' in l0 and 'finish' in l0:
                    x.start = _loc_off(offs, l0['start'])
                    x.finish = _loc_off(offs, l0['finish']) + 1
            except (IndexError, KeyError):
                x.caret = x.start = x.finish = None
        x.notes = [c['message'] for c in d.get('children', []) if c.get('kind') == 'note']
        out.append(x)
    return out


# ---------------------------------------------------------------------------
# small C helpers
# ---------------------------------------------------------------------------

def balanced(s):
    d = 0
    for c in s:
        if c in '([{':
            d += 1
        elif c in ')]}':
            d -= 1
            if d < 0:
                return False
    return d == 0


_SIMPLE = re.compile(r'^(?:[A-Za-z_]\w*|0[xX][0-9A-Fa-f]+[uUlL]*|\d+[uUlL]*)$')


def is_postfix_simple(expr):
    """True when expr is a primary or postfix expression (no top-level operator), so a
    cast can precede it without extra parentheses."""
    e = expr.strip()
    if not e:
        return False
    if e[0] == '(' and matching(e, 0) == len(e) - 1:
        return True
    m = re.match(r'[A-Za-z_]\w*|0[xX][0-9A-Fa-f]+[uUlL]*|\d+[uUlL]*', e)
    if not m:
        return False
    i = m.end()
    while i < len(e):
        c = e[i]
        if c in ' \t\r\n':
            i += 1
        elif c in '([':
            j = matching(e, i)
            if j < 0:
                return False
            i = j + 1
        elif c == '.' or e.startswith('->', i):
            i += 1 if c == '.' else 2
            while i < len(e) and e[i] in ' \t':
                i += 1
            m2 = re.match(r'[A-Za-z_]\w*', e[i:])
            if not m2:
                return False
            i += m2.end()
        else:
            return False
    return True


def matching(s, i):
    """Index of the bracket matching s[i], or -1."""
    o = s[i]
    c = {'(': ')', '[': ']', '{': '}'}[o]
    d = 0
    for j in range(i, len(s)):
        if s[j] == o:
            d += 1
        elif s[j] == c:
            d -= 1
            if d == 0:
                return j
    return -1


def strip_aka(t):
    t = re.sub(r"\s*\{aka [^}]*\}", '', t).strip()
    return t.strip("'")


def cast_text(ctype, expr):
    """`(T)expr` or `(T)(expr)`."""
    e = expr.strip()
    return '(%s)%s' % (ctype, e if is_postfix_simple(e) else '(' + e + ')')


def span_trim(text, s, e):
    while s < e and text[s] in ' \t\r\n':
        s += 1
    while e > s and text[e - 1] in ' \t\r\n':
        e -= 1
    return s, e


def rhs_span(text, mk, pos):
    """Span of the right-hand side after the `=` at pos: up to the `;` or `,` at depth 0,
    or an unmatched closer."""
    i = pos + 1
    d = 0
    n = len(text)
    start = i
    while i < n:
        c = text[i]
        if c in '([{':
            d += 1
        elif c in ')]}':
            if d == 0:
                break
            d -= 1
        elif c in ';,' and d == 0:
            break
        i += 1
    return span_trim(text, start, i)


# ---------------------------------------------------------------------------
# declarations: declarator-level proposals (handles `extern int f(int), g(int *);`)
# ---------------------------------------------------------------------------

class Dcl:
    """One declarator of a function declaration whose callee has a known definition."""
    pass


class Stmt:
    """One declaration statement, possibly with several declarators."""
    pass


def _split_declarators(m, a, b):
    """Split m[a:b] (from the first declarator name to the last `)`) into declarators:
    list of (stars, name, params_start, params_end) with params_* indexing inside the
    parentheses.  None when the text does not have the shape name(...), name(...)."""
    out = []
    i = a
    first = True
    while i < b:
        mm = re.compile(r'\s*(\**)\s*(' + pf.NAME_RE + r')\s*\(' if not first else
                        r'()(' + pf.NAME_RE + r')\s*\(').match(m, i)
        if not mm:
            return None
        op = mm.end() - 1
        cl = matching(m, op)
        if cl < 0 or cl >= b:
            return None
        out.append((mm.group(1), mm.group(2), op + 1, cl, mm.start(2), cl + 1))
        i = cl + 1
        while i < b and m[i] in ' \t\r\n':
            i += 1
        if i < b:
            if m[i] != ',':
                return None
            i += 1
        first = False
    return out


def parse_stmts(fi):
    """All function-declaration statements of the file, as Stmt objects."""
    out = []
    m, raw = fi.mask, fi.raw
    for mm in pf.DECL_RE.finditer(m):
        pre, ret_txt, name, params, term = mm.groups()
        if term != ';':
            continue
        rt = pf.tokens(ret_txt)
        if not rt or any(t in pf.STOP_WORDS for t in rt):
            continue
        d = pf.depth_at(fi.tab, mm.start())
        parts = _split_declarators(m, mm.start(3), mm.end(4) + 1)
        if not parts:
            continue
        s = Stmt()
        s.start, s.end = mm.start(2), mm.end(4) + 1          # `ret name(...)` ... `)`
        s.prefix = pre
        s.ret_txt = ret_txt
        s.block = d != 0
        s.cstart = pf.construct_start(m, fi.tab, mm.start())
        ls = m.rfind('\n', 0, mm.start()) + 1
        s.indent = re.match(r'[ \t]*', raw[ls:]).group(0)
        s.declarators = []
        for k, (stars, nm, ps, pe, ns, ne) in enumerate(parts):
            dc = Dcl()
            dc.stmt = s
            dc.k = k
            dc.name = nm
            dc.stars = stars
            dc.params_txt = raw[ps:pe]
            dc.span = (ns, ne)
            dc.line = raw.count('\n', 0, ns) + 1
            s.declarators.append(dc)
        out.append(s)
    return out


def old_ret_text(dc):
    """Return type text of the declarator as written (base type, own stars)."""
    base = re.sub(r'\s+', ' ', dc.stmt.ret_txt).strip()
    if dc.k == 0:
        return base
    base = re.sub(r'(\s*\*)+$', '', base).strip()
    return (base + ' ' + dc.stars).strip() if dc.stars else base


def file_proposals(fi, db, stats, skipped, tagset='KCWV'):
    """-> (stmts, dcls) where dcls are the declarators that differ from their
    definition (with tag, new text, need).  Every dcl has .rec (the callee record)."""
    stmts = parse_stmts(fi)
    dcls = []
    for s in stmts:
        for dc in s.declarators:
            dc.rec = None
            dc.fam = None
            rec, st = pf.find_callee(db, fi, dc.name)
            old_txt = re.sub(r'\s+', ' ', old_ret_text(dc) + ' ' + dc.name + '(' + dc.params_txt + ')')
            dc.old = old_txt
            if rec is None:
                stats['decl_' + st] += 1
                if st.startswith('ambiguous'):
                    skipped.append((fi.rel, dc.name, old_txt, 'unmappable: ' + st))
                continue
            if rec['unrep']:
                stats['decl_unrep'] += 1
                skipped.append((fi.rel, dc.name, old_txt,
                                'unrepresentable: %s (definition in %s)' % (rec['unrep'], rec['file'])))
                continue
            try:
                oret, oplist, _n = pf.resolve_proto(old_ret_text(dc), dc.params_txt, fi.td)
                okey = pf.norm_key(oret, oplist)
                dc.oret, dc.oplist = oret, [(t, n, o) for t, n, o in oplist]
            except pf.Unrep:
                okey = None
                dc.oret, dc.oplist = None, None
            dkey = pf.norm_key(rec['ret'], rec['params'])
            dc.fam = (rec['file'], rec['name'])
            if okey == dkey:
                stats['decl_same'] += 1
                continue
            dc.rec = rec
            dc.new = pf.render(dc.name, rec['ret'], rec['params'])
            dc.tag = pf.tags(okey, dkey) if okey else 'U'
            dc.need = set(rec['need'])
            dc.okey, dc.dkey = okey, dkey
            dcls.append(dc)
    return stmts, dcls


def class_of(tag):
    """Exclusive class of a tag string, in the order of the scoreboard."""
    if tag == 'U':
        return 'U'
    for c in 'KCVW':
        if c in tag:
            return c
    return 'cos'


def build_candidate(fi, dcls, active):
    """Text with the declarators in `active` (a set of Dcl) aligned to their
    definition.  Returns (text, dropped dcls)."""
    byst = collections.OrderedDict()
    for dc in dcls:
        if dc in active:
            byst.setdefault(dc.stmt, []).append(dc)
    props = []
    for s, lst in byst.items():
        p = SProp()
        p.start, p.end, p.cstart = s.start, s.end, s.cstart
        p.dcls = lst
        p.need = set()
        for dc in lst:
            p.need |= dc.need
        p.name = '+'.join(dc.name for dc in lst)
        if len(s.declarators) == 1:
            p.new = lst[0].new
        else:
            eol = file_eol(fi.raw, s.start)
            pieces = []
            base = re.sub(r'\s+', ' ', s.ret_txt).strip()
            for dc in s.declarators:
                if dc in lst:
                    pieces.append(dc.new)
                else:
                    if dc.k == 0:
                        pieces.append('%s %s(%s)' % (base, dc.name, dc.params_txt))
                    else:
                        b2 = re.sub(r'(\s*\*)+$', '', base).strip()
                        pieces.append('%s %s%s(%s)' % (b2, dc.stars, dc.name, dc.params_txt))
            sep = ';' + eol + s.indent + s.prefix
            p.new = sep.join(pieces)
        props.append(p)
    text, dropped = pf.build_text(fi, props)
    dd = []
    for p in dropped:
        dd += p.dcls
    return text, dd


class SProp(pf.Prop):
    """Statement-level proposal for pf.build_text (no __slots__: carries extra data)."""
    pass


# ---------------------------------------------------------------------------
# stage 2: cast repair
# ---------------------------------------------------------------------------

class Ctx:
    """What the repair rules know about one file."""

    def __init__(self, fi, dcls, active):
        self.fi = fi
        self.active = set(active)
        self.by_name = {}
        for dc in dcls:
            if dc in self.active:
                self.by_name.setdefault(dc.name, dc)
        self.stage = 9
        self.log = []          # (rule, name) of every edit emitted


def find_call_args(m, name, caret, argno):
    """Locate the innermost call `name(...)` whose argument number argno (1-based)
    contains the offset caret.  Returns (start, end) of the argument or None."""
    best = None
    for mm in re.finditer(r'(?<![\w])' + re.escape(name) + r'\s*\(', m):
        op = mm.end() - 1
        cl = matching(m, op)
        if cl < 0 or not (op < caret <= cl):
            continue
        args, d, cur = [], 0, op + 1
        for i in range(op + 1, cl):
            c = m[i]
            if c in '([{':
                d += 1
            elif c in ')]}':
                d -= 1
            elif c == ',' and d == 0:
                args.append((cur, i))
                cur = i + 1
        args.append((cur, cl))
        if argno > len(args):
            continue
        a, b = args[argno - 1]
        if a <= caret <= b and (best is None or op > best[0]):
            best = (op, a, b)
    if best is None:
        return None
    return best[1], best[2]


def call_parts(m, name, caret):
    """The innermost call `name(...)` that has caret between its name and its closing
    parenthesis.  Returns (name start, open, close, [arg spans]) or None."""
    best = None
    for mm in re.finditer(r'(?<![\w])' + re.escape(name) + r'\s*\(', m):
        op = mm.end() - 1
        cl = matching(m, op)
        if cl < 0 or not (mm.start() <= caret <= cl):
            continue
        args, d, cur = [], 0, op + 1
        for i in range(op + 1, cl):
            c = m[i]
            if c in '([{':
                d += 1
            elif c in ')]}':
                d -= 1
            elif c == ',' and d == 0:
                args.append((cur, i))
                cur = i + 1
        args.append((cur, cl))
        if not m[op + 1:cl].strip():
            args = []
        if best is None or mm.start() > best[0]:
            best = (mm.start(), op, cl, args)
    return best


_IMPURE = re.compile(r'[A-Za-z_]\w*\s*\(|\+\+|--|(?<![=!<>])=(?!=)')


def is_pure(expr):
    """No call, no assignment, no increment: evaluating it has no effect."""
    e = re.sub(r'\(\s*(?:struct\s+\w+|unsigned|signed|const|volatile|u8|u16|u32|s8|s16|s32|int|short|char|void|long)'
               r'[\w\s]*\**\s*\)', ' ', expr)
    return not _IMPURE.search(e)


def drop_args_edit(text, m, fname, caret, nparams, unit):
    """Delete the arguments beyond nparams of the call at caret when all are pure."""
    cp = call_parts(m, fname, caret)
    if cp is None:
        return None
    _s, op, cl, args = cp
    if len(args) <= nparams:
        return None
    for a, b in args[nparams:]:
        if not is_pure(m[a:b]):
            return None
    start = args[nparams - 1][1] if nparams else op + 1
    end = args[-1][1]
    if start >= end:
        return None
    return Edit(start, end, '', unit, 'drop-args')


def postfix_before(m, pos):
    """Span of the postfix expression that ends just before pos (operators excluded)."""
    i = pos
    while i > 0 and m[i - 1] in ' \t\r\n':
        i -= 1
    end = i
    while True:
        if i > 0 and m[i - 1] in ')]':
            c = m[i - 1]
            o = '(' if c == ')' else '['
            d = 0
            j = i - 1
            while j >= 0:
                if m[j] == c:
                    d += 1
                elif m[j] == o:
                    d -= 1
                    if d == 0:
                        break
                j -= 1
            if j < 0:
                return None
            i = j
            while i > 0 and m[i - 1] in ' \t':
                i -= 1
            # a call or subscript continues to the left with its callee
            if i > 0 and (m[i - 1].isalnum() or m[i - 1] in '_)]'):
                continue
            return None
        mm = re.search(r'[A-Za-z_]\w*$|0[xX][0-9A-Fa-f]+[uUlL]*$|\d+[uUlL]*$', m[max(0, i - 80):i])
        if not mm:
            return None
        i = i - (mm.end() - mm.start())
        j = i
        while j > 0 and m[j - 1] in ' \t':
            j -= 1
        if j >= 1 and m[j - 1] == '.' and not (j >= 2 and m[j - 2].isdigit()):
            i = j - 1
            while i > 0 and m[i - 1] in ' \t':
                i -= 1
            continue
        if j >= 2 and m[j - 2:j] == '->':
            i = j - 2
            while i > 0 and m[i - 1] in ' \t':
                i -= 1
            continue
        return i, end


def postfix_after(m, pos):
    """Span of the postfix expression that starts at or after pos."""
    i = pos
    n = len(m)
    while i < n and m[i] in ' \t\r\n':
        i += 1
    start = i
    mm = re.compile(r'[A-Za-z_]\w*|0[xX][0-9A-Fa-f]+[uUlL]*|\d+[uUlL]*').match(m, i)
    if not mm:
        return None
    i = mm.end()
    while i < n:
        c = m[i]
        if c in '([':
            j = matching(m, i)
            if j < 0:
                return None
            i = j + 1
        elif c == '.' or m.startswith('->', i):
            i += 1 if c == '.' else 2
            while i < n and m[i] in ' \t':
                i += 1
            m2 = re.compile(r'[A-Za-z_]\w*').match(m, i)
            if not m2:
                return None
            i = m2.end()
        else:
            break
    return start, i


def call_name_of(text, a, b):
    """Name of the function when text[a:b] is exactly a call `name(...)`."""
    mm = re.match(r'(' + pf.NAME_RE + r')\s*\(', text[a:b])
    if not mm:
        return None
    op = a + mm.end() - 1
    return mm.group(1) if matching(text, op) == b - 1 else None


_PASS = re.compile(r"passing argument (\d+) of '(\w+)' (makes pointer from integer|makes integer from pointer|"
                   r"from incompatible pointer type)")
_ASSIGN = re.compile(r"(assignment to|initialization of) '([^']+)'(?: \{aka '[^']*'\})? from "
                     r"(?:'[^']*'(?: \{aka '[^']*'\})? makes (?:pointer from integer|integer from pointer)|"
                     r"incompatible pointer type)")
_RETURN = re.compile(r"returning '[^']*'(?: \{aka '[^']*'\})? from a function with (?:incompatible )?"
                     r"return type '([^']+)'")
_WRAPMSG = re.compile(r"invalid type argument of|subscripted value is neither|invalid operands to binary|"
                      r"switch quantity not an integer|wrong type argument to|invalid operands to|"
                      r"used (?:struct|union) type value where scalar is required|"
                      r"incompatible type for argument")


_INT32_CAST = re.compile(r'\(\s*(?:u32|s32|int|unsigned int|unsigned|signed int|long|unsigned long)\s*\)')
_CAST_HEAD = re.compile(r'\(\s*(?:const\s+)?(?:(?:struct|union)\s+\w+|\w+)(?:\s+\w+)*\s*\*+\s*\)')


def strip_pointer_cast(expr):
    """expr without a leading pointer cast `(T *)` when the rest is one operand, so a
    new cast replaces the old one instead of stacking `(A *)((B *)x)`."""
    e = expr.strip()
    m = _CAST_HEAD.match(e) or _INT32_CAST.match(e)
    if not m:
        return expr
    rest = e[m.end():].strip()
    if rest.startswith('(') and matching(rest, 0) == len(rest) - 1:
        inner = rest[1:-1].strip()
        return inner if is_postfix_simple(inner) else rest
    return rest if is_postfix_simple(rest) else expr


def cast_edit(text, a, b, ctype, rule, unit):
    a, b = span_trim(text, a, b)
    if a >= b:
        return None
    expr = text[a:b]
    if not balanced(expr):
        return None
    if '*' in ctype:
        expr = strip_pointer_cast(expr)
    new = cast_text(ctype, expr)
    if new == expr:
        return None
    return Edit(a, b, new, unit, rule)


def ret_tag(dc):
    """'K' when the return type differs in pointer-ness, 'O' for another difference."""
    try:
        ra = dc.okey.split(' (', 1)[0]
        rb = dc.dkey.split(' (', 1)[0]
    except Exception:
        return ''
    if ra == rb:
        return ''
    return 'K' if (('*' in ra) != ('*' in rb)) else 'O'


def _changed_call_in(text, a, b, ctx):
    """True when text[a:b] calls a callee whose declaration this trial changed."""
    return any(re.search(r'(?<![\w])' + re.escape(n) + r'\s*\(', text[a:b]) for n in ctx.by_name)


def diag_edits(d, text, m, ctx):
    """Edits that repair diagnostic d, or [] when no rule applies."""
    msg = d.msg
    out = []
    if d.strict:
        return strict_edits(d, text, m, ctx)
    mm = _PASS.match(msg)
    if mm:
        argno, fname = int(mm.group(1)), mm.group(2)
        ctype = None
        for n in d.notes:
            nm = re.match(r"expected '([^']+)'(?: \{aka '[^']*'\})? but argument is of type", n)
            if nm:
                ctype = nm.group(1)
        if ctype is None or d.caret is None:
            return out
        sp = find_call_args(m, fname, d.caret, argno)
        if sp is None and d.start is not None and d.finish is not None:
            sp = (d.start, d.finish)
        if sp is None:
            return out
        e = cast_edit(text, sp[0], sp[1], ctype, 'cast-arg', fname)
        return [e] if e else out
    mm = _ASSIGN.match(msg)
    if mm and d.caret is not None:
        ctype = mm.group(2)
        pos = d.caret
        if mm.group(1) == 'assignment to':
            if text[pos] != '=' or text[pos:pos + 2] == '==':
                return out
            a, b = rhs_span(text, m, pos)
            rule = 'cast-assign'
        else:
            a, b = rhs_span(text, m, pos - 1)
            rule = 'cast-init'
        e = cast_edit(text, a, b, ctype, rule, None)
        return [e] if e else out
    mm = _RETURN.match(msg)
    if mm and d.caret is not None:
        a, b = rhs_span(text, m, d.caret - 1)
        e = cast_edit(text, a, b, mm.group(1), 'cast-return', None)
        return [e] if e else out
    mm = re.match(r"too few arguments to function '(\w+)'", msg)
    if mm and d.caret is not None and ctx.stage >= 4:
        e, why = hidden_arg_edit(text, m, ctx, mm.group(1), d.caret)
        d.note = why
        return [e] if e else out
    mm = re.match(r"too many arguments to function '(\w+)'", msg)
    if mm and d.caret is not None:
        dc = ctx.by_name.get(mm.group(1))
        if dc is not None:
            e = drop_args_edit(text, m, mm.group(1), d.caret, len(dc.rec['params']), mm.group(1))
            return [e] if e else out
        return out
    if _WRAPMSG.match(msg) and d.caret is not None:
        # an operand is a call whose return class changed: restore the old return type
        cands = []
        for sp in (postfix_before(m, d.caret), postfix_after(m, d.caret + 1)):
            if sp:
                cands.append(sp)
        for a, b in cands:
            nm = call_name_of(text, a, b)
            dc = ctx.by_name.get(nm) if nm else None
            if dc is not None and ret_tag(dc) == 'K':
                old = old_ret_text(dc)
                if not old or old == 'void':
                    continue
                out.append(Edit(a, b, '(%s)' % cast_text(old, text[a:b]), nm, 'wrap-ret'))
                break
        return out
    return out


_SPASS = re.compile(r"(?:pointer targets in passing argument (\d+) of '(\w+)' differ in signedness|"
                    r"passing argument (\d+) of '(\w+)' discards '[^']*' qualifier)")
_SASSIGN = re.compile(r"pointer targets in (assignment|initialization) from '[^']*' to '([^']+)' "
                      r"differ in signedness")


def strict_edits(d, text, m, ctx):
    """Casts for a STRICT diagnostic, only where the trial changed the callee: an
    argument of a call to a changed declaration, or the right side of an
    assignment whose value comes from such a call."""
    mm = _SPASS.match(d.msg)
    if mm and d.caret is not None:
        argno = int(mm.group(1) or mm.group(3))
        fname = mm.group(2) or mm.group(4)
        if fname not in ctx.by_name:
            return []
        ctype = None
        for n in d.notes:
            nm = re.match(r"expected '([^']+)'(?: \{aka '[^']*'\})? but argument is of type", n)
            if nm:
                ctype = nm.group(1)
        sp = find_call_args(m, fname, d.caret, argno)
        if ctype is None or sp is None:
            return []
        e = cast_edit(text, sp[0], sp[1], ctype, 'cast-arg-sign', fname)
        return [e] if e else []
    mm = _SASSIGN.match(d.msg)
    if mm and d.caret is not None:
        pos = d.caret
        if mm.group(1) == 'assignment':
            if text[pos] != '=' or text[pos:pos + 2] == '==':
                return []
            a, b = rhs_span(text, m, pos)
        else:
            a, b = rhs_span(text, m, pos - 1)
        if not _changed_call_in(text, a, b, ctx):
            return []
        e = cast_edit(text, a, b, mm.group(2), 'cast-assign-sign', None)
        return [e] if e else []
    return []


def repair_text(text, ctx, workdir, cap=8):
    """Diagnose-repair loop.  Returns (text, remaining diagnostics)."""
    name = os.path.basename(ctx.fi.rel)
    diags = []
    for _ in range(cap):
        diags = gcc_json(text, workdir, name)
        if not diags:
            return text, []
        m = pf.mask(text)
        edits = []
        for d in diags:
            edits += diag_edits(d, text, m, ctx)
        hard = [d for d in diags if not d.strict]
        if not edits:
            return text, hard
        new, acc, dfr = apply_edits(text, edits)
        if new == text:
            return text, hard
        for e in acc:
            ctx.log.append((e.why, e.unit))
        text = new
    return text, [d for d in gcc_json(text, workdir, name) if not d.strict]


# ---------------------------------------------------------------------------
# transactions: verification and deterministic isolation
# ---------------------------------------------------------------------------

def norm_msg(msg):
    """Reason code of a diagnostic message (types and names blanked)."""
    k = re.sub(r"'[^']*'", "'X'", msg)
    k = re.sub(r"\{aka [^}]*\}", '', k)
    k = re.sub(r'\d+', 'N', k)
    return re.sub(r'\s+', ' ', k).strip()


def reason_code(why, rem=None):
    """Short reason code for a failed trial."""
    if why.startswith('verdict change'):
        m = re.match(r'verdict change: c99 (\w+\*?)->(\w+\*?), nolang (\w+\*?)->(\w+\*?)', why)
        if m:
            a, b, c, d = m.groups()
            if 'CCERR' in (b, d):
                return 'verdict: compile error in the DS compiler'
            return 'verdict: %s' % ('moved (%s/%s)' % (b, d))
        return 'verdict'
    if why.startswith('gcc error'):
        if rem:
            return 'gcc: ' + norm_msg(rem[0].msg) + ((' / ' + re.sub(r"'[^']*'|\d+", 'X', rem[0].note))
                                                    if rem[0].note else '')
        return 'gcc: ' + norm_msg(why[len('gcc error: error: '):])
    return why[:60]


class Trial:
    """One verification of a candidate: the text, the verdict, the reason."""

    def __init__(self, text, ok, why, rem, log=()):
        self.text, self.ok, self.why, self.rem, self.log = text, ok, why, rem, list(log)


class FileJob:
    """Everything needed to repair and verify one file."""

    def __init__(self, path, db, opt, stage_classes='KCVW', only=None, raw=None):
        self.path = path
        self.rel = os.path.relpath(path, ROOT).replace(os.sep, '/')
        self.opt = opt
        self.fi = pf.parse_file(path, self.rel)
        self.only = only
        self.ok_file = not (self.fi.has_include or 'address' not in self.fi.h)
        self.stats, self.skipped = collections.Counter(), []
        self.stmts, self.dcls = [], []
        if self.ok_file:
            self.stmts, self.dcls = file_proposals(self.fi, db, self.stats, self.skipped)
        if only is None:
            self.cands = [dc for dc in self.dcls if class_of(dc.tag) in stage_classes]
        else:
            self.cands = [dc for dc in self.dcls if dc.fam == only]
        # one folder per process: two family transactions in different workers can
        # verify the same declarer file at the same time
        self.tmp = os.path.join(opt['out'], 'tmp', '%d_%s' % (os.getpid(), re.sub(r'\W', '_', self.rel)))
        self.orig = None
        self.ntrials = 0

    def evaluate_orig(self):
        self.orig = pf.evaluate(self.fi, self.fi.raw, self.tmp)
        return not (self.orig['c99'].startswith('ERR') or self.orig['nolang'].startswith('ERR'))

    def trial(self, active, repair=True):
        """Build, repair and verify the candidate with the declarators in `active`.
        A verdict move with width differences among the declarators gets a second
        attempt with width-preserving casts."""
        t = self._trial(active, repair, False)
        if not t.ok and t.why.startswith('verdict change') and any(
                'W' in dc.tag or 'S' in dc.tag for dc in active):
            t2 = self._trial(active, repair, True)
            if t2.ok:
                return t2
        return t

    def _trial(self, active, repair, width):
        self.ntrials += 1
        text, dropped = build_candidate(self.fi, self.dcls, set(active))
        ctx = Ctx(self.fi, self.dcls, set(active))
        rem = []
        if width:
            text = apply_width(text, ctx)
        if repair:
            text, rem = repair_text(text, ctx, self.tmp)
        if rem:
            why = 'gcc error: ' + rem[0].msg
            return Trial(text, False, why, rem, ctx.log)
        ev = pf.evaluate(self.fi, text, self.tmp, self.orig)
        why = pf.compare_eval(self.orig, ev)
        return Trial(text, why is None, why or '', [], ctx.log)


def applied(job, acc, final):
    """The accepted declarators that the final text really carries: build_candidate
    drops a declarator it cannot place (a typedef defined after the use), and a
    trial with only dropped declarators verifies the unchanged text."""
    if not acc or final is None or final.text == job.fi.raw:
        return []
    _t, dropped = build_candidate(job.fi, job.dcls, set(acc))
    dd = set(dropped)
    return [dc for dc in acc if dc not in dd]


def isolate(job, units, base=None, budget=400):
    """Maximal verified subset of units by divide and conquer (deterministic).
    Returns (accepted units, final Trial or None, {unit: Trial of its failure})."""
    base = list(base or [])
    failed = {}
    last = [None]

    def solve(group, acc):
        if job.ntrials >= budget:
            for u in group:
                failed.setdefault(u, Trial('', False, 'trial budget', []))
            return acc
        t = job.trial(acc + group)
        if t.ok:
            last[0] = t
            return acc + group
        if len(group) == 1:
            failed[group[0]] = t
            return acc
        h = len(group) // 2
        acc = solve(group[:h], acc)
        return solve(group[h:], acc)

    acc = solve(list(units), base)
    return acc, (last[0] if acc != base else None), failed


# ---------------------------------------------------------------------------
# writing files
# ---------------------------------------------------------------------------

def backup_and_write(path, rel, orig_raw, final, outdir):
    """Write final over the repo file.  The file must still hold orig_raw (nobody else
    changed it), the backup goes to outdir/backup/rel, and line endings must be kept."""
    if read_text(path) != orig_raw:
        return 'file changed under us'
    o, n = eol_signature(orig_raw), eol_signature(final)
    if n[2] != o[2]:
        return 'line ending check failed %s -> %s' % (o, n)
    if o[0] == 0 and n[0] != 0:
        return 'line ending check failed (CRLF introduced)'
    if o[1] == 0 and n[1] != 0:
        return 'line ending check failed (LF introduced)'
    bk = os.path.join(outdir, 'backup', rel)
    os.makedirs(os.path.dirname(bk), exist_ok=True)
    if not os.path.exists(bk):
        write_text(bk, orig_raw)
    write_text(path, final)
    return None


class Result:
    def __init__(self):
        self.stats = collections.Counter()
        self.rules = collections.Counter()
        self.fixed_class = collections.Counter()
        self.fail_class = collections.Counter()
        self.fail_reason = collections.Counter()
        self.unsolved = []          # rows for unsolved.csv
        self.skipped = []
        self.changed = None
        self.diff = ''
        self.edits = []


def unified(rel, a, b):
    return ''.join(difflib.unified_diff(a.splitlines(True), b.splitlines(True),
                                        'a/' + rel, 'b/' + rel, n=1))


_DB = None


def worker_init(cache):
    global _DB
    with open(cache, 'rb') as f:
        _DB = pickle.load(f)


def process(args):
    path, opt = args
    res = Result()
    rel = os.path.relpath(path, ROOT).replace(os.sep, '/')
    try:
        _process(path, rel, opt, res)
    except Exception as e:
        import traceback
        res = Result()
        res.stats['file_exception'] += 1
        res.skipped.append((rel, '', '', 'exception: %r %s' % (e, traceback.format_exc()[-300:])))
    return res


def _process(path, rel, opt, res):
    job = FileJob(path, _DB, opt, opt.get('classes', 'KCVW'))
    res.stats.update(job.stats)
    res.skipped += job.skipped
    if not job.ok_file:
        res.stats['file_skipped_noheader_or_include'] += 1
        return
    res.stats['files_scanned'] += 1
    if not job.cands:
        return
    shutil.rmtree(job.tmp, ignore_errors=True)
    try:
        if not job.evaluate_orig():
            res.stats['file_orig_unverifiable'] += 1
            res.skipped.append((rel, '', '', 'original unverifiable: %s / %s' %
                                (job.orig['c99'], job.orig['nolang'])))
            return
        acc, final, failed = isolate(job, job.cands, budget=opt.get('budget', 400))
        acc = applied(job, acc, final)
        if not acc:
            final = None
        res.stats['trials'] += job.ntrials
        for dc in job.cands:
            c = class_of(dc.tag)
            if dc in acc:
                res.stats['decl_fixed'] += 1
                res.fixed_class[c] += 1
            else:
                t = failed.get(dc)
                code = reason_code(t.why, t.rem) if t else 'dropped (typedef after use)'
                res.stats['decl_unsolved'] += 1
                res.fail_class[c] += 1
                res.fail_reason[code] += 1
                res.unsolved.append((rel, dc.stmt.declarators[0].name if False else dc.name, dc.old, c,
                                     code))
        if not acc or final is None:
            res.stats['files_all_unsolved'] += 1
            return
        text = final.text
        # rules used by the final text
        for rule, unit in final.log:
            res.rules[rule] += 1
        res.changed = rel
        res.diff = unified(rel, job.fi.raw, text)
        res.stats['files_changed'] += 1
        if opt.get('dry_run'):
            return
        err = backup_and_write(path, rel, job.fi.raw, text, opt['out'])
        if err:
            res.stats['file_write_refused'] += 1
            res.stats['files_changed'] -= 1
            res.changed = None
            res.skipped.append((rel, '', '', err))
    finally:
        shutil.rmtree(job.tmp, ignore_errors=True)


# ---------------------------------------------------------------------------
# scoreboard
# ---------------------------------------------------------------------------

def scoreboard(db, jobs=6, out=None):
    """Counts of non-matching declarations per exclusive class over src/matched."""
    files = pf.all_matched()
    cnt = collections.Counter()
    fset, cset = set(), set()
    rows = []
    legacy, lfiles = collections.Counter(), set()

    def one(p):
        try:
            fi = pf.parse_file(p)
        except Exception:
            return []
        if fi.has_include or 'address' not in fi.h:
            return []
        st, sk = collections.Counter(), []
        _s, dcls = file_proposals(fi, db, st, sk)
        for pr in pf.proposals(fi, db, collections.Counter(), []):
            legacy[class_of(pr.tag)] += 1
            if class_of(pr.tag) in ('K', 'C', 'V', 'W'):
                lfiles.add(fi.rel)
        return [(fi.rel, dc.name, dc.rec['name'], dc.rec['file'], dc.tag, class_of(dc.tag), dc.old, dc.new)
                for dc in dcls]

    with cf.ThreadPoolExecutor(jobs) as ex:
        for r in ex.map(one, files):
            rows += r
    for r in rows:
        cnt[r[5]] += 1
        if r[5] in ('K', 'C', 'V', 'W'):
            fset.add(r[0])
            cset.add((r[2], r[3]))
    real = sum(cnt[c] for c in 'KCVW')
    if out:
        with open(out, 'w', newline='') as f:
            w = csv.writer(f, delimiter='\t')
            w.writerow(['file', 'decl', 'callee', 'def_file', 'tags', 'class', 'old', 'new'])
            w.writerows(rows)
    return {'total': len(rows), 'real': real, 'K': cnt['K'], 'C': cnt['C'], 'V': cnt['V'],
            'W': cnt['W'], 'cosmetic': cnt['cos'], 'unknown': cnt['U'], 'real_files': len(fset),
            'real_callees': len(cset), 'legacy': dict(legacy), 'legacy_real_files': len(lfiles),
            'legacy_real': sum(legacy[c] for c in 'KCVW')}


def fmt_score(s):
    return ('total %d, real %d (pointer/int K %d, count C %d, void/value V %d, width W %d), '
            'cosmetic %d, unknown %d; real declarations sit in %d files, %d callees' %
            (s['total'], s['real'], s['K'], s['C'], s['V'], s['W'], s['cosmetic'], s['unknown'],
             s['real_files'], s['real_callees']) +
            '\nlegacy count (protofix one-line view, the brief figure): real %d, %s, in %d files' %
            (s['legacy_real'], ', '.join('%s %d' % (k, s['legacy'].get(k, 0)) for k in ('K', 'C', 'V', 'W', 'cos', 'U')),
             s['legacy_real_files']))


# ---------------------------------------------------------------------------
# driver
# ---------------------------------------------------------------------------

class Agg:
    def __init__(self, out):
        self.out = out
        self.stats = collections.Counter()
        self.rules = collections.Counter()
        self.fixed_class = collections.Counter()
        self.fail_class = collections.Counter()
        self.fail_reason = collections.Counter()
        self.n = 0
        self.t0 = time.time()

    def csv(self, name, rows, header):
        if not rows:
            return
        p = os.path.join(self.out, name)
        new = not os.path.exists(p)
        with open(p, 'a', newline='') as f:
            w = csv.writer(f)
            if new:
                w.writerow(header)
            w.writerows(rows)

    def add(self, r, dry):
        self.n += 1
        self.stats.update(r.stats)
        self.rules.update(r.rules)
        self.fixed_class.update(r.fixed_class)
        self.fail_class.update(r.fail_class)
        self.fail_reason.update(r.fail_reason)
        self.csv('unsolved.csv', r.unsolved, ['file', 'declaration_callee', 'declaration', 'class', 'reason'])
        self.csv('skipped.csv', r.skipped, pf.SK_HDR)
        if r.changed and not dry:
            with open(os.path.join(self.out, 'changed.txt'), 'a') as f:
                f.write(r.changed + '\n')

    def summary(self, final=False):
        s = self.stats
        L = ['# protofix2 summary', '',
             'state: %s, elapsed %.0f s, files scanned %d' % ('final' if final else 'running',
                                                              time.time() - self.t0, s['files_scanned']),
             '', '- files changed: %d' % s['files_changed'],
             '- declarations fixed: %d (K %d, C %d, V %d, W %d)' %
             (s['decl_fixed'], self.fixed_class['K'], self.fixed_class['C'], self.fixed_class['V'],
              self.fixed_class['W']),
             '- declarations unsolved: %d (K %d, C %d, V %d, W %d)' %
             (s['decl_unsolved'], self.fail_class['K'], self.fail_class['C'], self.fail_class['V'],
              self.fail_class['W']),
             '- files with nothing solved: %d' % s['files_all_unsolved'],
             '- files with unverifiable original: %d' % s['file_orig_unverifiable'],
             '- writes refused: %d' % s['file_write_refused'],
             '- file exceptions: %d' % s['file_exception'],
             '- trials: %d' % s['trials'], '', '## repair rules used (edits in kept files)', '']
        L += ['- %s: %d' % kv for kv in self.rules.most_common()]
        L += ['', '## unsolved reasons', '']
        L += ['- %d: %s' % (v, k) for k, v in self.fail_reason.most_common(40)]
        with open(os.path.join(self.out, 'summary.md'), 'w') as f:
            f.write('\n'.join(L) + '\n')


def select_files(a, db):
    files = pf.all_matched()
    rel = lambda p: os.path.relpath(p, ROOT).replace(os.sep, '/')
    if a.files:
        want = {l.strip().replace('\\', '/') for l in open(a.files) if l.strip()}
        files = [p for p in files if rel(p) in want]
    if a.glob:
        files = [p for p in files if fnmatch.fnmatch(rel(p), a.glob)]
    if a.sample:
        cand = files
        if a.only_real:
            # keep only files that have a real declaration
            keep = []
            with open(os.path.join(a.out, 'decls.tsv')) as f:
                have = {r.split('\t')[0] for i, r in enumerate(f) if i and r.split('\t')[5] in ('K', 'C', 'V', 'W')}
            cand = [p for p in files if rel(p) in have]
        rng = random.Random(a.seed)
        cand = sorted(cand)
        rng.shuffle(cand)
        files = sorted(cand[:a.sample])
    if a.limit:
        files = files[:a.limit]
    return files


# ---------------------------------------------------------------------------
# families: definition + declarers, call graph order
# ---------------------------------------------------------------------------

class FamIndex:
    """family (definition file, definition name) -> declarer files, and the call graph
    between families (a file that defines X and declares F gives the edge X -> F)."""

    def __init__(self):
        self.declarers = collections.defaultdict(set)     # fam -> {rel}
        self.defined = collections.defaultdict(list)      # rel -> [fam defined in it]
        self.declared = collections.defaultdict(set)      # rel -> {fam declared in it}

    @staticmethod
    def build(db, jobs=6, cache=None):
        if cache and os.path.exists(cache):
            try:
                with open(cache, 'rb') as f:
                    return pickle.load(f)
            except Exception:
                pass
        fx = FamIndex()
        files = pf.all_matched()

        def one(p):
            try:
                fi = pf.parse_file(p)
            except Exception:
                return None
            if fi.has_include or 'address' not in fi.h:
                return None
            stmts = parse_stmts(fi)
            fams = set()
            for s in stmts:
                for dc in s.declarators:
                    rec, st = pf.find_callee(db, fi, dc.name)
                    if rec is not None and not rec['unrep']:
                        fams.add((rec['file'], rec['name']))
            return fi.rel, fams, [(fi.rel, n) for n, _m, _r, _p in fi.defs]

        with cf.ThreadPoolExecutor(jobs) as ex:
            for r in ex.map(one, files):
                if r is None:
                    continue
                rel, fams, defs = r
                fx.declared[rel] |= fams
                for fam in fams:
                    fx.declarers[fam].add(rel)
                fx.defined[rel] = defs
        if cache:
            with open(cache, 'wb') as f:
                pickle.dump(fx, f)
        return fx

    def order(self):
        """All families, callee first (Tarjan SCCs, deterministic; members of a cycle in
        name order)."""
        nodes = sorted(set(self.declarers) | {fam for l in self.defined.values() for fam in l})
        edges = {n: set() for n in nodes}
        for rel, defs in self.defined.items():
            for fam in defs:
                if fam in edges:
                    edges[fam] |= {f for f in self.declared.get(rel, ()) if f != fam and f in edges}
        idx, low, onst, st, out = {}, {}, set(), [], []
        counter = [0]
        for root in nodes:
            if root in idx:
                continue
            work = [(root, iter(sorted(edges[root])))]
            idx[root] = low[root] = counter[0]
            counter[0] += 1
            st.append(root)
            onst.add(root)
            while work:
                v, it = work[-1]
                adv = False
                for w in it:
                    if w not in idx:
                        idx[w] = low[w] = counter[0]
                        counter[0] += 1
                        st.append(w)
                        onst.add(w)
                        work.append((w, iter(sorted(edges[w]))))
                        adv = True
                        break
                    if w in onst:
                        low[v] = min(low[v], idx[w])
                if adv:
                    continue
                work.pop()
                if work:
                    low[work[-1][0]] = min(low[work[-1][0]], low[v])
                if low[v] == idx[v]:
                    comp = []
                    while True:
                        w = st.pop()
                        onst.discard(w)
                        comp.append(w)
                        if w == v:
                            break
                    out.extend(sorted(comp))
        return out        # Tarjan emits callees (sinks) first


# ---------------------------------------------------------------------------
# definition edits
# ---------------------------------------------------------------------------

def find_def(fi, name):
    for n, mm, ret_txt, params in fi.defs:
        if n == name:
            return mm
    return None


def edit_definition(fi, name, params=None, ret=None):
    """New text of the definition file with the definition `name` given a new
    parameter list text (inside the parentheses) and/or a new return type text.
    Returns None when the definition is not found."""
    mm = find_def(fi, name)
    if mm is None:
        return None
    edits = []
    if params is not None:
        edits.append(Edit(mm.start(4), mm.end(4), params, name, 'def-params'))
    if ret is not None:
        edits.append(Edit(mm.start(2), mm.end(2), ret, name, 'def-ret'))
    text, acc, dfr = apply_edits(fi.raw, edits)
    return text


def rec_from_text(path, text, name):
    """Definition record (as build_db makes it) of `name` in text, or None."""
    fi = pf.FileInfo()
    fi.raw = text
    fi.h = pf.parse_header(text)
    fi.region = fi.h.get('region', '?')
    fi.mask = m = pf.mask(text)
    fi.tab = pf.depth_table(m)
    fi.td = pf.parse_typedefs(m, fi.tab)
    for mm in pf.DECL_RE.finditer(m):
        pre, ret_txt, nm, params, term = mm.groups()
        if nm != name or term != '{' or pf.depth_at(fi.tab, mm.start()) != 0:
            continue
        try:
            ret, pl, need = pf.resolve_proto(ret_txt, params, fi.td)
        except pf.Unrep as e:
            return None
        return {'ret': ret, 'params': pl, 'need': need, 'unrep': None, 'file': path, 'name': name}
    return None


def db_with(db, key, rec):
    """Copy of db whose definition at key (region, addr) is rec."""
    d2 = dict(db)
    defs = dict(db['defs'])
    defs[key] = [rec]
    d2['defs'] = defs
    return d2


def split_params(ptxt):
    t = ptxt.strip()
    if t in ('', 'void'):
        return []
    return [x.strip() for x in pf.split_top(t)]


def join_params(ps):
    return ', '.join(ps) if ps else 'void'


# ---------------------------------------------------------------------------
# family transactions
# ---------------------------------------------------------------------------

LOCK = None


class FileLock:
    """Cross-process lock around the write step (an O_EXCL file)."""

    def __init__(self, path):
        self.path = path

    def __enter__(self):
        for _ in range(6000):
            try:
                self.fd = os.open(self.path, os.O_CREAT | os.O_EXCL | os.O_WRONLY)
                return self
            except FileExistsError:
                time.sleep(0.05)
        raise RuntimeError('lock timeout')

    def __exit__(self, *a):
        os.close(self.fd)
        os.remove(self.path)


class FamResult:
    def __init__(self, fam, rule):
        self.fam, self.rule = fam, rule
        self.ok = False
        self.reason = ''
        self.files = {}          # rel -> (old raw, new text)
        self.before = self.after = 0
        self.fixed = 0
        self.failed = []         # (rel, decl name, reason)


def family_tx(fam, def_path_rel, newdef_text, new_rec, key, db, fx, opt, rule, min_gain=1):
    """Verify the transaction `new definition + every declarer`.  Nothing is written.
    fam: (def file, name).  newdef_text: new text of the definition file.  new_rec:
    its definition record.  key: (region, addr) of the callee.  Returns FamResult
    with .files filled when ok."""
    res = FamResult(fam, rule)
    out = opt['out']
    def_path = os.path.join(ROOT, def_path_rel)
    djob = FileJob(def_path, db, opt)
    if not djob.ok_file:
        res.reason = 'definition file has no header or an include'
        return res
    shutil.rmtree(djob.tmp, ignore_errors=True)
    try:
        if not djob.evaluate_orig():
            res.reason = 'definition file original unverifiable'
            return res
        ev = pf.evaluate(djob.fi, newdef_text, djob.tmp, djob.orig)
        why = pf.compare_eval(djob.orig, ev)
        if why is not None:
            res.reason = 'definition: ' + reason_code(why)
            return res
    finally:
        shutil.rmtree(djob.tmp, ignore_errors=True)
    res.files[def_path_rel] = (djob.fi.raw, newdef_text)
    db2 = db_with(db, key, new_rec)
    before = after = fixed = 0
    for rel in sorted(fx.declarers[fam]):
        if rel == def_path_rel:
            continue
        p = os.path.join(ROOT, rel)
        j0 = FileJob(p, db, opt, only=fam)
        before += len(j0.cands)
        job = FileJob(p, db2, opt, only=fam)
        if not job.cands:
            continue
        shutil.rmtree(job.tmp, ignore_errors=True)
        try:
            if not job.evaluate_orig():
                after += len(job.cands)
                res.failed.append((rel, '', 'original unverifiable'))
                continue
            acc, final, failed = isolate(job, job.cands, budget=opt.get('budget', 400))
            acc = applied(job, acc, final)
            n_fixed = len(acc)
            fixed += n_fixed
            after += len(job.cands) - n_fixed
            for dc in job.cands:
                if dc not in acc:
                    t = failed.get(dc)
                    res.failed.append((rel, dc.name, reason_code(t.why, t.rem) if t else 'dropped'))
            if acc and final is not None:
                res.files[rel] = (job.fi.raw, final.text)
        finally:
            shutil.rmtree(job.tmp, ignore_errors=True)
    res.before, res.after, res.fixed = before, after, fixed
    if before - after >= min_gain:
        res.ok = True
    else:
        res.reason = 'no gain: mismatched declarations %d -> %d' % (before, after)
        res.files = {}
    return res


def commit_tx(res, out):
    """Write every file of an accepted transaction (backups first).  All or nothing:
    a file that changed on disk or a failed write restores everything."""
    if not res.ok:
        return 'not ok'
    done = []
    lock = os.path.join(out, 'write.lock')
    with FileLock(lock):
        for rel, (old, new) in res.files.items():
            if read_text(os.path.join(ROOT, rel)) != old:
                return 'file changed under us: ' + rel
            o, n = eol_signature(old), eol_signature(new)
            if n[2] != o[2] or (o[0] == 0 and n[0]) or (o[1] == 0 and n[1]):
                return 'line ending check failed: ' + rel
        try:
            for rel, (old, new) in res.files.items():
                bk = os.path.join(out, 'backup', rel)
                os.makedirs(os.path.dirname(bk), exist_ok=True)
                if not os.path.exists(bk):
                    write_text(bk, old)
                write_text(os.path.join(ROOT, rel), new)
                done.append(rel)
        except Exception as e:
            for rel in done:
                write_text(os.path.join(ROOT, rel), res.files[rel][0])
            return 'write failed: %r' % (e,)
    return None


# ---------------------------------------------------------------------------
# evidence from the original assembly (regargs index and scanner)
# ---------------------------------------------------------------------------

class Evidence:
    """Lazy wrapper around regargs.Index / Scanner: what the ORIGINAL code of a
    function reads, and where each argument register of a call comes from."""

    def __init__(self):
        import regargs
        self.R = regargs
        self.ix = regargs.Index()
        self.sc = regargs.Scanner(self.ix)
        self.byfile = {fi['path']: fi for fi in self.ix.files}
        self.taken = collections.Counter()
        for fi in self.ix.files:
            for d in fi['defs']:
                if d['asm']:
                    continue
                for nm in d['taken']:
                    cd = self.ix.resolve(fi, nm)
                    if cd:
                        self.taken[(cd['region'], cd['name'])] += 1
            for nm in fi['taken_rest']:
                cd = self.ix.resolve(fi, nm)
                if cd:
                    self.taken[(cd['region'], cd['name'])] += 1

    def rdef(self, rel, name):
        fi = self.byfile.get(rel)
        if not fi:
            return None, None
        for d in fi['defs']:
            if d['name'] == name:
                return fi, d
        return fi, None

    def reads(self, rel, name):
        fi, d = self.rdef(rel, name)
        if d is None or not d.get('addr'):
            return None
        return self.sc.reads(d['region'], d['addr'])

    def param_regs(self, d, i):
        first, nw = d['layout'][i]
        return ['r%d' % w for w in range(first, min(first + nw, 4))]


def rule_drop_unread(fam, ev, db):
    """Stage 4, rule 4.3: the definition declares trailing parameters whose registers
    the ORIGINAL code never reads.  New definition without them.  Returns
    (params text list, why) or (None, reason)."""
    fi, d = ev.rdef(*fam)
    if d is None or not d.get('addr') or not d['n'] or d['var']:
        return None, 'no regargs definition'
    R = ev.reads(*fam)
    if R is None:
        return None, 'callee reads undecidable'
    if ev.taken.get((d['region'], d['name'])):
        return None, 'address taken'
    unread = []
    for i in range(d['n']):
        regs = ev.param_regs(d, i)
        unread.append(bool(regs) and not any(r in R for r in regs))
    k = len(unread)
    while k > 0 and unread[k - 1]:
        k -= 1
    if k == len(unread):
        return None, 'no trailing unread parameter'
    return k, 'drop %d trailing unread parameter(s): original reads %s' % (len(unread) - k, sorted(R))


def declarer_protos(fam, fx, db):
    """[(rel, ret tokens, [(param tokens, name)], unresolved ret text, [param type text])]
    for every declaration of fam in its declarer files, or (None, reason)."""
    rel_def, name = fam
    out = []
    for rel in sorted(fx.declarers[fam]):
        if rel == rel_def:
            continue
        fi = pf.parse_file(os.path.join(ROOT, rel), rel)
        for nm, mm, ret_txt, params, _block in fi.decls:
            if nm != name:
                continue
            rec, st = pf.find_callee(db, fi, nm)
            if rec is None or (rec['file'], rec['name']) != fam:
                continue
            try:
                ret, pl, _need = pf.resolve_proto(ret_txt, params, fi.td)
            except pf.Unrep as e:
                return None, 'declaration in %s unreadable: %s' % (rel, e)
            texts = []
            for p in split_params(params):
                tk, pname, opq = pf.parse_param(p, fi.td)
                if opq is not None or tk == ['...']:
                    return None, 'declaration in %s has a function pointer or ...' % rel
                texts.append((pf.tok_text(tk), pname))
            out.append((rel, ret, pl, pf.tok_text(pf.tokens(ret_txt)), texts))
    if not out:
        return None, 'no declarers'
    return out, ''


_PORTABLE = pf.BUILTIN | set(pf.STD) | {'*'}


_WIDTH = {'u8': 1, 's8': 1, 'char': 1, 'u16': 2, 's16': 2, 'short': 2, 'u32': 4, 'int': 4}


def pick_type(keys_texts, def_key=None, mode='wide'):
    """One type for a position from the declarers' (norm key, text) pairs: the type
    they all use, else the widest integer type when it is unique at that width (a
    caller that passes a narrow value compiles the same against the wider type; the
    transaction checks it).  Returns (key, text, how) or None."""
    keys = {k for k, _t in keys_texts}
    if len(keys) == 1:
        k = next(iter(keys))
        return k, keys_texts[0][1], 'agree'
    if all('*' in k for k in keys):
        # pointers: the one specific type among generic ones (void *, char *, u8 *)
        spec = {k for k in keys if k not in _GENERIC_PTR}
        if len(spec) == 1:
            k = next(iter(spec))
            return k, next(t for kk, t in keys_texts if kk == k), 'specific'
        return None
    allk = keys | ({def_key} if def_key else set())
    if any(k not in _WIDTH for k in allk):
        return None
    if mode == 'narrow':
        low = min(_WIDTH[k] for k in keys)
        at_low = {k for k in keys if _WIDTH[k] == low}
        if len(at_low) != 1:
            return None
        k = next(iter(at_low))
        return k, next(t for kk, t in keys_texts if kk == k), 'narrowest'
    top = max(_WIDTH[k] for k in allk)
    at_top = {k for k in keys if _WIDTH[k] == top}
    if len(at_top) != 1 or any(_WIDTH[k] == top and k not in at_top for k in allk):
        return None
    k = next(iter(at_top))
    return k, next(t for kk, t in keys_texts if kk == k), 'widest'


_GENERIC_PTR = {'void*', 'char*', 'u8*', 's8*', 'const void*', 'const char*', 'const u8*'}


def better_type(dk, pk):
    """True when the definition's type dk may become pk.  Integers may change width
    or sign, an integer may become a pointer, a generic pointer (void *, char *, u8 *)
    may become a specific one.  A pointer never becomes an integer or a more generic
    pointer: the definition's own body is the better witness there."""
    if dk is None:
        return True
    dp, pp = '*' in dk, '*' in pk
    if not dp:
        return True
    if not pp:
        return False
    return dk in _GENERIC_PTR and pk not in _GENERIC_PTR


def key_text(k):
    """Spelling of a normalised type key: 'u8*' -> 'u8 *'."""
    return re.sub(r'\s*\*', ' *', k).replace('* *', '**').strip()


def rule_consensus(fam, fx, db, fi, mm, mode='wide'):
    """Give the definition the types its declarers' original code shows: per
    position, the type every declarer uses, else the widest integer type (pick_type);
    the parameter count every declarer uses, else the largest one when the extra
    positions have a type by the same rule.  Each declarer file is EXACT with its own
    declaration, so its declaration is evidence of what the call sends; the
    transaction verifies the new definition and every declarer.  Returns
    (params text, ret text or None, why) or (None, None, reason)."""
    decls, why = declarer_protos(fam, fx, db)
    if decls is None:
        return None, None, why
    rec = db['defs'].get((fi.region, int(fam[1][-8:], 16)), [None])[0]
    if rec is None or rec['unrep']:
        return None, None, 'definition record unavailable'
    if any(tk == ['...'] or tk is None for tk, _n, _o in rec['params']):
        return None, None, 'variadic or function pointer parameter in the definition'
    dps = split_params(fi.raw[mm.start(4):mm.end(4)])
    if len(dps) != len(rec['params']):
        return None, None, 'definition parameters unreadable'
    n = max(len(d[2]) for d in decls)

    def portable(t):
        sm = re.match(r'(const\s+)?(struct|union)\s+(\w+)\s*\*+$', t.strip())
        if sm:
            if re.search(r'\b%s\s+%s\b' % (sm.group(2), sm.group(3)), fi.mask[:mm.start()]) is None:
                fwd.add('%s %s;' % (sm.group(2), sm.group(3)))
            return True
        words = re.findall(r'[A-Za-z_]\w*|\*', t)
        return all(w in _PORTABLE for w in words) and all(
            pf.typedef_state(fi, w, mm.start()) is True for w in words if w in pf.STD)

    fwd = set()       # forward declarations the new types need
    changes = []      # (description, kind, index, text): one unit each, adds and drops grouped
    adds = []
    for i in range(n):
        kt = [(pf.norm_toks(d[2][i][0]), d[4][i][0]) for d in decls if len(d[2]) > i]
        dk = pf.norm_toks(rec['params'][i][0]) if i < len(dps) else None
        pick = pick_type(kt, dk, mode)
        if i >= len(dps):
            if pick is None or not portable(pick[1]):
                return None, None, 'added parameter %d has no portable type' % i
            pname = next((d[4][i][1] for d in decls if len(d[2]) > i and d[4][i][1]), '') or 'a%d' % i
            t = key_text(pick[0])
            adds.append(t + ('' if t.endswith('*') else ' ') + pname)
            continue
        if pick is None or pick[0] == dk or not better_type(dk, pick[0]) or not portable(pick[1]):
            continue
        _tk, pname, _o = pf.parse_param(dps[i], fi.td)
        t = key_text(pick[0])
        changes.append(('param %d %s (%s)' % (i, t, pick[2]), 'param', i,
                        t + ('' if t.endswith('*') else ' ') + (pname or 'a%d' % i)))
    if adds:
        changes.append(('add %d parameter(s)' % len(adds), 'add', len(dps), adds))
    if n < len(dps):
        # every declarer passes at most n arguments: the extra parameters are dummies
        # when the body never names them (the compile check refuses otherwise)
        changes.append(('drop %d parameter(s)' % (len(dps) - n), 'drop', n, None))
    dret = pf.norm_toks(rec['ret'])
    rp = pick_type([(pf.norm_toks(d[1]), d[3]) for d in decls], dret, mode)
    if (rp is not None and rp[0] != dret and 'void' not in (dret, rp[0]) and better_type(dret, rp[0])
            and portable(rp[1])):
        t = key_text(rp[0])
        changes.append(('return %s (%s)' % (t, rp[2]), 'ret', None, t + ('' if t.endswith('*') else ' ')))
    if not changes:
        return None, None, 'no position where the declarers give a portable type'
    rule_consensus.fwd = sorted(fwd)
    return dps, changes, '%d declarer(s)' % len(decls)


def consensus_text(dps, changes):
    """(params text, ret text or None, why) of the definition with `changes` applied."""
    ps, ret = list(dps), None
    for _d, kind, i, t in changes:
        if kind == 'param':
            ps[i] = t
        elif kind == 'ret':
            ret = t
    for _d, kind, i, t in changes:
        if kind == 'add':
            ps = ps + list(t)
        elif kind == 'drop':
            ps = ps[:i]
    return join_params(ps), ret, '; '.join(c[0] for c in changes)


# ---------------------------------------------------------------------------
# family driver
# ---------------------------------------------------------------------------

_FX = None
_EV = None


def fam_worker_init(cache, fxcache):
    global _DB, _FX, _EV
    with open(cache, 'rb') as f:
        _DB = pickle.load(f)
    with open(fxcache, 'rb') as f:
        _FX = pickle.load(f)
    _EV = None


def get_evidence():
    global _EV
    if _EV is None:
        _EV = Evidence()
    return _EV


_LVALUE = re.compile(r'^[A-Za-z_]\w*(?:\s*(?:->|\.)\s*[A-Za-z_]\w*|\s*\[[^\[\]]*\])*$')


def void_value_text(rule, fam, db, fi, mm):
    """A void definition whose callers all read a value of one type T.  void_tail:
    the last statement `lhs = expr;` gains `return lhs;`, a last call statement
    becomes `return call(...);`.  void_entry: a game function (not SDK) whose first
    parameter is a pointer and whose callers read a pointer returns that parameter.
    The transaction checks the bytes; the callers decide T.  Returns (text, why)."""
    rec = db['defs'].get((fi.region, int(fam[1][-8:], 16)), [None])[0]
    if rec is None or rec['unrep'] or pf.norm_toks(rec['ret']) != 'void':
        return None, 'definition is not void'
    decls, why = declarer_protos(fam, _FX, db)
    if decls is None:
        return None, why
    rp = pick_type([(pf.norm_toks(d[1]), d[3]) for d in decls])
    if rp is None or rp[0] == 'void':
        return None, 'callers do not read one value type'
    t = key_text(rp[0])
    sm = re.match(r'(?:const\s+)?(struct|union)\s+(\w+)', t)
    if sm and not re.search(r'\b%s\s+%s\b' % sm.groups(), fi.mask[:mm.start()]):
        return None, 'return type needs %s %s' % sm.groups()
    for w in re.findall(r'[A-Za-z_]\w*', t):
        if w in pf.STD:
            if pf.typedef_state(fi, w, mm.start()) is not True:
                return None, 'return type needs typedef %s' % w
        elif w not in pf.BUILTIN and w not in ('struct', 'union') and not (sm and w == sm.group(2)):
            return None, 'return type %s not portable' % t
    op = mm.end() - 1
    cl = matching(fi.mask, op)
    if cl < 0:
        return None, 'body unreadable'
    body = fi.mask[op + 1:cl]
    end = len(body.rstrip())
    if end == 0 or body[end - 1] != ';':
        return None, 'the body does not end with a statement'
    depth, st = 0, 0
    for i in range(end - 1):
        c = body[i]
        if c in '({[':
            depth += 1
        elif c in ')}]':
            depth -= 1
        if depth == 0 and c in ';{}':
            st = i + 1
    raw_stmt = body[st:end - 1]
    stmt = raw_stmt.strip()
    s0 = op + 1 + st + (len(raw_stmt) - len(raw_stmt.lstrip()))
    ls = fi.raw.rfind('\n', 0, s0) + 1
    indent = re.match(r'[ \t]*', fi.raw[ls:]).group(0)
    at = op + 1 + end
    eol = file_eol(fi.raw, ls)
    edits = [Edit(mm.start(2), mm.end(2), t + ('' if t.endswith('*') else ' '), fam[1], 'def-ret')]
    if rule == 'void_tail':
        am = re.match(r'^(.*?[^=!<>+\-*/%&|^])=(?!=)(.*)$', stmt, re.S)
        if am and _LVALUE.match(am.group(1).strip()):
            lhs = re.sub(r'\s+', ' ', fi.raw[s0:s0 + len(am.group(1))].strip())
            edits.append(Edit(at, at, eol + indent + 'return ' + lhs + ';', fam[1], 'def-return'))
            why = 'callers read %s: return the assigned %s' % (t, lhs)
        elif re.match(r'^[A-Za-z_]\w*\s*\(', stmt) and stmt.endswith(')'):
            edits.append(Edit(s0, s0, 'return ', fam[1], 'def-return'))
            why = 'callers read %s: return the last call' % t
        else:
            return None, 'last statement is neither an assignment nor a call'
    else:
        if '_sdk/' in fam[0]:
            return None, 'SDK function: the vendor prototype decides'
        ps = split_params(fi.raw[mm.start(4):mm.end(4)])
        if '*' not in rp[0] or not ps or not rec['params'] or '*' not in pf.norm_toks(rec['params'][0][0] or []):
            return None, 'not a pointer passed through'
        _tk, pname, _o = pf.parse_param(ps[0], fi.td)
        if not pname:
            return None, 'first parameter has no name'
        edits.append(Edit(at, at, eol + indent + 'return ' + pname + ';', fam[1], 'def-return'))
        why = 'callers read %s: return the first argument %s' % (t, pname)
    text, _a, _d = apply_edits(fi.raw, edits)
    return text, why


def make_newdef(rule, fam, db, subset=None):
    """-> (new definition text, new record, key, why) or (None, None, None, reason)."""
    rel, name = fam
    path = os.path.join(ROOT, rel)
    fi = pf.parse_file(path, rel)
    mm = find_def(fi, name)
    if mm is None:
        return None, None, None, 'definition not found'
    key = (fi.region, int(name[-8:], 16))
    ps = split_params(fi.raw[mm.start(4):mm.end(4)])
    if rule in ('consensus', 'consensus_narrow'):
        dps, changes, why = rule_consensus(fam, _FX, db, fi, mm,
                                           'narrow' if rule == 'consensus_narrow' else 'wide')
        if dps is None:
            return None, None, None, why
        if subset is not None:
            if subset >= len(changes):
                return None, None, None, 'no such change'
            changes = [changes[subset]]
        params, ret, what = consensus_text(dps, changes)
        why = '%s: %s' % (why, what)
        text = edit_definition(fi, name, params=params, ret=ret)
        used = ' '.join(c[3] if isinstance(c[3], str) else ' '.join(c[3] or []) for c in changes)
        fwd = [f for f in getattr(rule_consensus, 'fwd', []) if re.search(r'\b%s\b' % f[:-1].split()[1], used)]
        if text is not None and fwd:
            # struct X; lines go right before the definition's line
            ls = text.rfind('\n', 0, mm.start()) + 1
            eol = file_eol(text, ls)
            text = text[:ls] + ''.join(f + eol for f in fwd) + eol + text[ls:]
    elif rule == 'drop_unread':
        k, why = rule_drop_unread(fam, get_evidence(), db)
        if k is None:
            return None, None, None, why
        text = edit_definition(fi, name, params=join_params(ps[:k]))
    elif rule == 'void_return':
        r, why = rule_void_return(fam, get_evidence(), db)
        if r is None:
            return None, None, None, why
        c, cd, tgt = r
        rec = db['defs'].get((cd['region'], tgt))
        if not rec or not rec[0]['ret'] or rec[0]['unrep']:
            return None, None, None, 'callee record unavailable'
        rec = rec[0]
        for k, w in rec['need']:
            if k == 'typedef' and pf.typedef_state(fi, w, mm.start()) is not True:
                return None, None, None, 'return type needs typedef %s' % w
            if k in ('struct', 'union') and not re.search(r'\b%s\s+%s\b' % (k, w), fi.mask[:mm.start()]):
                return None, None, None, 'return type needs %s %s' % (k, w)
        op = mm.end() - 1
        cl = matching(fi.mask, op)
        bm = fi.mask[op + 1:cl]
        cms = None
        for cm in re.finditer(r'(?<![\w])' + re.escape(c['name']) + r'\s*\(', bm):
            cms = cm
        if cms is None:
            return None, None, None, 'call not found in the raw body'
        parts = call_parts(bm, c['name'], cms.start())
        if parts is None or not re.match(r'\s*;\s*$', bm[parts[2] + 1:]):
            return None, None, None, 'the call is not the last statement'
        at = op + 1 + parts[0]
        rt = pf.tok_text(rec['ret'])
        decls, _w = declarer_protos(fam, _FX, db)
        if decls:
            cp = pick_type([(pf.norm_toks(d[1]), d[3]) for d in decls])
            if cp is not None and cp[0] != 'void':
                ct = key_text(cp[0])
                csm = re.match(r'(?:const\s+)?(struct|union)\s+(\w+)', ct)
                ok = not csm or re.search(r'\b%s\s+%s\b' % csm.groups(), fi.mask[:mm.start()])
                for w in re.findall(r'[A-Za-z_]\w*', ct):
                    if w in pf.STD and pf.typedef_state(fi, w, mm.start()) is not True:
                        ok = False
                    elif w not in pf.STD and w not in pf.BUILTIN and w not in ('struct', 'union') and \
                            not (csm and w == csm.group(2)):
                        ok = False
                if ok:
                    rt = ct
                    why += ' (as %s, the type its callers read)' % ct
        edits = [Edit(mm.start(2), mm.end(2), rt + ' ' if not rt.endswith('*') else rt, name, 'def-ret'),
                 Edit(at, at, 'return ', name, 'def-return')]
        text, _a, _d = apply_edits(fi.raw, edits)
    elif rule in ('void_tail', 'void_entry'):
        text, why = void_value_text(rule, fam, db, fi, mm)
        if text is None:
            return None, None, None, why
    else:
        return None, None, None, 'unknown rule'
    if text is None or text == fi.raw:
        return None, None, None, 'no edit'
    rec = rec_from_text(rel, text, name)
    if rec is None:
        return None, None, None, 'new definition unreadable'
    return text, rec, key, why


def fam_task(args):
    fam, opt = args
    out = {'fam': fam, 'rows': [], 'written': []}
    for rule in opt['rules']:
        try:
            text, rec, key, why = make_newdef(rule, fam, _DB)
            if text is None:
                out['rows'].append((fam[0], fam[1], rule, 'n/a', 0, 0, 0, why))
                continue
            res = family_tx(fam, fam[0], text, rec, key, _DB, _FX, opt, rule)
            out['rows'].append((fam[0], fam[1], rule, 'ok' if res.ok else 'fail', res.before, res.after,
                                res.fixed, why if res.ok else res.reason))
            if not res.ok and rule in ('consensus', 'consensus_narrow') and '; ' in why:
                # all changes together failed: each change alone, best gain wins
                best = None
                for k in range(why.count('; ') + 1):
                    t2, rec2, key2, why2 = make_newdef(rule, fam, _DB, subset=k)
                    if t2 is None:
                        continue
                    r2 = family_tx(fam, fam[0], t2, rec2, key2, _DB, _FX, opt, rule)
                    out['rows'].append((fam[0], fam[1], rule + '/1', 'ok' if r2.ok else 'fail', r2.before,
                                        r2.after, r2.fixed, why2 if r2.ok else r2.reason))
                    if r2.ok and (best is None or r2.before - r2.after > best[0].before - best[0].after):
                        best = (r2, why2)
                if best is not None:
                    res, why = best
            if res.ok and not opt['dry_run']:
                err = commit_tx(res, opt['out'])
                if err:
                    out['rows'].append((fam[0], fam[1], rule, 'commit refused', 0, 0, 0, err))
                    continue
                out['written'] = sorted(res.files)
                out['fixed'] = res.fixed
                out['diffs'] = [unified(rel, o, n) for rel, (o, n) in sorted(res.files.items())]
                return out
            if res.ok:
                out['written'] = sorted(res.files)
                out['fixed'] = res.fixed
                out['diffs'] = [unified(rel, o, n) for rel, (o, n) in sorted(res.files.items())]
                return out
        except Exception as e:
            import traceback
            out['rows'].append((fam[0], fam[1], rule, 'exception', 0, 0, 0,
                                repr(e) + traceback.format_exc()[-200:]))
    return out


def fam_list(out, classes='KCVW'):
    """Families with a mismatching declaration of the given classes (from decls.tsv)."""
    fams = collections.Counter()
    with open(os.path.join(out, 'decls.tsv'), newline='') as f:
        r = csv.reader(f, delimiter='\t')
        next(r)
        for row in r:
            if row[5] in classes:
                fams[(row[3], row[2])] += 1
    return fams


def famrun(a, db):
    fxcache = os.path.join(a.out, 'fam.pkl')
    fx = FamIndex.build(db, a.jobs, fxcache)
    order = fx.order()
    fams = fam_list(a.out, a.classes)
    todo = [f for f in order if f in fams]
    if a.fam:
        todo = [f for f in todo if a.fam in f[1] or a.fam in f[0]]
    if a.sample:
        rng = random.Random(a.seed)
        rng.shuffle(todo)
        todo = todo[:a.sample]
    print('families: %d of %d' % (len(todo), len(order)), flush=True)
    opt = {'out': a.out, 'dry_run': a.dry_run, 'rules': a.rules.split(','), 'budget': a.budget}
    t0 = time.time()
    stat = collections.Counter()
    rowsf = os.path.join(a.out, 'families.csv')
    with cf.ProcessPoolExecutor(a.jobs, initializer=fam_worker_init, initargs=(os.path.join(a.out, 'defs.pkl'),
                                                                               fxcache)) as ex:
        for i, r in enumerate(ex.map(fam_task, [(f, opt) for f in todo], chunksize=1), 1):
            new = not os.path.exists(rowsf)
            with open(rowsf, 'a', newline='') as f:
                w = csv.writer(f)
                if new:
                    w.writerow(['def_file', 'name', 'rule', 'status', 'before', 'after', 'fixed', 'detail'])
                w.writerows(r['rows'])
            if r['written']:
                stat['families_done'] += 1
                stat['decls_fixed'] += r.get('fixed', 0)
                stat['files'] += len(r['written'])
                if not a.dry_run:
                    with open(os.path.join(a.out, 'changed.txt'), 'a') as f:
                        f.write(''.join(x + '\n' for x in r['written']))
                if a.diffs:
                    with open(a.diffs, 'a', newline='') as f:
                        f.write(''.join(r.get('diffs', [])).replace(chr(13), ''))
            if i % 10 == 0:
                print('%d/%d %s %.0fs' % (i, len(todo), dict(stat), time.time() - t0), flush=True)
    print(dict(stat))


# ---------------------------------------------------------------------------
# stage 4: hidden register arguments (too few arguments)
# ---------------------------------------------------------------------------

_MOVIMM = re.compile(r'^movs?\s+r\d+,\s*#(-?(?:0x[0-9a-fA-F]+|\d+))$')


def enclosing_def(m, caret):
    """(name, body start, body end) of the top-level function body containing caret."""
    best = None
    for mm in pf.DECL_RE.finditer(m):
        if mm.group(5) != '{':
            continue
        op = mm.end() - 1
        cl = matching(m, op)
        if op < caret < cl:
            best = (mm.group(3), op, cl)
    return best


def origin_expr(d, regs_origins, regs):
    """Expression for the argument held in regs, from the origin sets (union over bl
    sites), or (None, reason)."""
    if len(regs) != 1:
        return None, 'multi-word parameter'
    org = regs_origins[regs[0]]
    if not org:
        return None, 'no origin information'
    kinds = {o[0] for o in org}
    if kinds == {'entry'}:
        names = set()
        for o in org:
            pi = None
            w = int(o[1][1:]) if o[1] in ('r0', 'r1', 'r2', 'r3') else None
            if w is None:
                return None, 'callee-saved value of the caller\'s caller'
            for i, (first, nw) in enumerate(d['layout']):
                if first <= w < first + nw:
                    pi = i
            if pi is None or pi >= len(d['pnames']) or not d['pnames'][pi]:
                return None, 'incoming %s is not a declared parameter of the caller' % o[1]
            names.add(d['pnames'][pi])
        if len(names) == 1:
            return names.pop(), 'entry'
        return None, 'different incoming registers on different paths'
    if kinds == {'ins'} and len(org) == 1:
        o = next(iter(org))
        mm = _MOVIMM.match(o[2].strip())
        if mm:
            return mm.group(1), 'constant'
        return None, 'value computed by "%s"' % o[2]
    return None, 'origin kinds %s' % sorted(kinds)


def hidden_arg_edit(text, m, ctx, fname, caret):
    """Append the missing arguments of the call at caret, from the caller's original
    assembly.  Returns (Edit or None, reason)."""
    dc = ctx.by_name.get(fname)
    if dc is None:
        return None, 'callee not aligned'
    cp = call_parts(m, fname, caret)
    if cp is None:
        return None, 'call not found'
    ns, op, cl, args = cp
    k, n = len(args), len(dc.rec['params'])
    if k >= n:
        return None, 'not too few'
    enc = enclosing_def(m, caret)
    if enc is None:
        return None, 'no enclosing function'
    ev = get_evidence()
    fi_r = ev.byfile.get(ctx.fi.rel)
    if fi_r is None:
        return None, 'file not in regargs index'
    d = next((x for x in fi_r['defs'] if x['name'] == enc[0]), None)
    if d is None or not d.get('addr'):
        return None, 'caller definition unknown to regargs'
    cd = ev.ix.resolve(fi_r, fname)
    if cd is None or not cd.get('addr') or cd['n'] is None or cd['n'] != n:
        return None, 'callee definition mismatch'
    sites = ev.sc.sites_for(fi_r, d, cd['addr'])
    if not sites:
        return None, 'no bl site in the original'
    calls = [c for c in ev.R.def_calls(d) if c['name'] == fname]
    idx = len(re.findall(r'(?<![\w])' + re.escape(fname) + r'\s*\(', m[enc[1]:ns]))
    if len(sites) == len(calls) and idx < len(sites):
        ss = [sites[idx]]
    else:
        ss = sites
    extra = []
    for i in range(k, n):
        regs = ev.param_regs(cd, i)
        if not regs:
            return None, 'stack-passed parameter %d' % i
        opr = {r: frozenset().union(*[st[2].get(r, frozenset()) for st in ss]) for r in regs}
        ex, why = origin_expr(d, opr, regs)
        if ex is None:
            return None, 'param %d: %s' % (i, why)
        extra.append(ex)
    ins_at = args[-1][1] if args else op + 1
    new = (', ' if args else '') + ', '.join(extra)
    return Edit(ins_at, ins_at, new, fname, 'hidden-args'), 'ok'


# ---------------------------------------------------------------------------
# stage 5: width preserving casts (cast to the type the caller used to declare)
# ---------------------------------------------------------------------------

def real_calls(m, name):
    """[(name start, open, close, [arg spans], value_used)] for the calls of `name`
    in masked text m (declarations excluded)."""
    out = []
    for mm in re.finditer(r'(?<![\w])' + re.escape(name) + r'\s*\(', m):
        ns = mm.start()
        j = ns
        while j > 0 and m[j - 1] in ' \t\r\n':
            j -= 1
        prev = m[j - 1] if j > 0 else ';'
        wm = re.search(r'([A-Za-z_]\w*)\s*$', m[max(0, j - 40):j])
        word = wm.group(1) if wm else ''
        if (prev.isalnum() or prev in '_*') and word not in ('return', 'else', 'do', 'case'):
            if prev != '*' or word == '' or word not in ('return',):
                continue          # a declaration: `type name(`
        cp = call_parts(m, name, ns)
        if cp is None or cp[0] != ns:
            continue
        used = True
        if prev in ';{}' or word in ('else', 'do') or j == 0:
            used = False
        elif prev == ')':
            d, i = 0, j - 1
            while i >= 0:
                if m[i] == ')':
                    d += 1
                elif m[i] == '(':
                    d -= 1
                    if d == 0:
                        break
                i -= 1
            wk = re.search(r'([A-Za-z_]\w*)\s*$', m[max(0, i - 20):i])
            if wk and wk.group(1) in ('if', 'while', 'for', 'switch'):
                used = False
        out.append((cp[0], cp[1], cp[2], cp[3], used))
    return out


def _is_scalar(toks):
    return toks is not None and '*' not in toks and 'void' not in toks and 'struct' not in toks \
        and 'union' not in toks and toks != ['...']


def width_edits(text, ctx):
    """Casts to the OLD declared types where the new prototype differs in a scalar type:
    argument i gets (oldtype), a used return value gets (oldret)."""
    m = pf.mask(text)
    out = []
    for name, dc in ctx.by_name.items():
        if not getattr(dc, 'oplist', None) or not dc.okey:
            continue
        newp = dc.rec['params']
        oldp = dc.oplist
        diffs = []
        for i, ((nt, _n1, _o1), (ot, _n2, _o2)) in enumerate(zip(newp, oldp)):
            if _is_scalar(nt) and _is_scalar(ot) and pf.norm_toks(nt) != pf.norm_toks(ot):
                diffs.append((i, pf.tok_text(ot)))
        rdiff = None
        if _is_scalar(dc.rec['ret']) and _is_scalar(dc.oret) and pf.norm_toks(dc.rec['ret']) != pf.norm_toks(dc.oret):
            rdiff = pf.tok_text(dc.oret)
        if not diffs and not rdiff:
            continue
        for ns, op, cl, args, used in real_calls(m, name):
            for i, ot in diffs:
                if i < len(args):
                    a, b = span_trim(text, args[i][0], args[i][1])
                    if text[a:b].startswith('(%s)' % ot):
                        continue
                    e = cast_edit(text, a, b, ot, 'width-arg', name)
                    if e:
                        out.append(e)
            if rdiff and used and not re.search(r'\(\s*%s\s*\)\s*$' % re.escape(rdiff), text[max(0, ns - 40):ns]):
                out.append(Edit(ns, cl + 1, cast_text(rdiff, text[ns:cl + 1]), name, 'width-ret'))
    return out


def apply_width(text, ctx, rounds=4):
    for _ in range(rounds):
        new, acc, dfr = apply_edits(text, width_edits(text, ctx))
        if new == text:
            break
        for e in acc:
            ctx.log.append((e.why, e.unit))
        text = new
        if not dfr:
            break
    return text


# ---------------------------------------------------------------------------
# stage 6: void versus value (what does the ORIGINAL definition leave in r0?)
# ---------------------------------------------------------------------------

def return_origins(ev, region, addr):
    """(set of r0 origins at the returns, set of tail-call targets, n returns) of the
    original function at addr, or None when the bytes cannot be read."""
    sc, R = ev.sc, ev.R
    loc = sc.locate(addr, region)
    if not loc:
        return None
    fi = sc.func_insns(loc[0], addr & ~1, loc[1], isa_known=True)
    if not fi or not fi[0]:
        return None
    insns, thumb, data, base = fi
    IN = sc.analysis(loc[0], addr & ~1, fi)
    idx = {ins.address for ins in insns}
    orgs, tails, nret = set(), set(), 0
    for i, ins in enumerate(insns):
        if IN[i] is None:
            continue
        mn = ins.mnemonic.split('.')[0]
        bm = R.base_mnemonic(mn)
        if (bm == 'bx' and ins.op_str == 'lr') or (bm in R.POPS and 'pc' in ins.op_str) \
                or (bm == 'mov' and ins.op_str.replace(' ', '') == 'pc,lr'):
            nret += 1
            orgs |= set(IN[i].get('r0', ()))
        elif mn in R.BRANCHES and mn not in ('cbz', 'cbnz'):
            t = R.branch_target(ins)
            if t is not None and t not in idx:
                tails.add(t & ~1)
    return orgs, tails, nret


def rule_void_return(fam, ev, db):
    """The definition is void but its original code returns the value of its last call.
    Returns (edits, why) or (None, reason)."""
    rel, name = fam
    fi_r, d = ev.rdef(rel, name)
    if d is None or not d.get('addr'):
        return None, 'no regargs definition'
    if not d['void']:
        return None, 'definition is not void'
    ro = return_origins(ev, d['region'], d['addr'])
    if ro is None:
        return None, 'original bytes unreadable'
    orgs, tails, nret = ro
    targets = {o[2] & ~1 for o in orgs if o[0] == 'ret' and o[2] is not None}
    kinds = {o[0] for o in orgs}
    if tails and not orgs and nret == 0:
        targets = set(tails)
    elif tails:
        return None, 'both returns and tail jumps'
    elif kinds - {'ret'}:
        return None, 'r0 at return holds %s' % sorted(kinds)
    if len(targets) != 1:
        return None, 'returns the value of %d different calls' % len(targets)
    tgt = next(iter(targets))
    body = d['body']
    calls = []
    for c in ev.R.def_calls(d):
        cd = ev.ix.resolve(fi_r, c['name'])
        if cd is not None and cd.get('addr') and (cd['addr'] & ~1) == tgt:
            calls.append((c, cd))
    if not calls:
        return None, 'call to 0x%08X not found in the C body' % tgt
    c, cd = calls[-1]
    if cd['void']:
        return None, 'the callee %s is void' % cd['name']
    return (c, cd, tgt), 'returns the value of %s' % cd['name']


# ---------------------------------------------------------------------------
# selftest
# ---------------------------------------------------------------------------

def selftest():
    """Unit tests of the engine pieces.  Returns a list of (ok, name)."""
    res = []

    def check(name, cond):
        res.append((bool(cond), name))

    # edit engine
    t = 'abcdefghij'
    out, acc, dfr = apply_edits(t, [Edit(2, 4, 'X'), Edit(6, 8, 'YY')])
    check('edits: two disjoint', out == 'abXefYYij' and not dfr)
    out, acc, dfr = apply_edits(t, [Edit(2, 6, 'X'), Edit(4, 8, 'Y')])
    check('edits: overlap deferred', out == 'abXghij' and len(dfr) == 1)
    out, acc, dfr = apply_edits(t, [Edit(2, 2, '('), Edit(2, 2, '['), Edit(2, 2, '(')])
    check('edits: inserts at one offset keep order, duplicate dropped', out == 'ab([cdefghij')
    out, acc, dfr = apply_edits(t, [Edit(2, 5, 'X'), Edit(2, 2, '(')])
    check('edits: insert before replacement at one offset', len(acc) == 2 or len(dfr) == 1)
    out, acc, dfr = apply_edits(t, [Edit(3, 5, 'X'), Edit(5, 5, '!')])
    check('edits: adjacent insert after replacement', out == 'abcX!fghij')
    # line endings
    check('eol: crlf', file_eol('a\r\nb\r\n') == '\r\n')
    check('eol: lf', file_eol('a\nb\n') == '\n')
    check('eol: mixed follows position', file_eol('a\r\nb\nc\n', 6) == '\n' and file_eol('a\r\nb\nc\n', 0) == '\r\n')
    check('eol signature', eol_signature('a\r\nb\nc\rd') == (1, 1, 1))
    # cast text
    check('cast: identifier', cast_text('u8 *', 'x') == '(u8 *)x')
    check('cast: subscript', cast_text('void *', 'p[3]') == '(void *)p[3]')
    check('cast: call', cast_text('u32', 'f(a, b)') == '(u32)f(a, b)')
    check('cast: member chain', cast_text('u32', 'a->b.c[2]') == '(u32)a->b.c[2]')
    check('cast: binary needs parens', cast_text('u8 *', 'a + 0x3F0') == '(u8 *)(a + 0x3F0)')
    check('cast: unary needs parens', cast_text('u8 *', '*p') == '(u8 *)(*p)')
    check('cast: replaces a pointer cast', cast_text('u8 *', strip_pointer_cast('(char *)(q + off)')) == '(u8 *)(q + off)')
    check('cast: replaces a 32-bit integer cast', strip_pointer_cast('(u32)h') == 'h')
    check('cast: keeps a narrowing cast', strip_pointer_cast('(u16)x') == '(u16)x')
    check('cast: keeps a cast that scales arithmetic', strip_pointer_cast('(char *)p + 4') == '(char *)p + 4')
    check('pick: unanimous', pick_type([('u16', 'u16'), ('u16', 'unsigned short')], 'u32')[0] == 'u16')
    check('pick: widest integer', pick_type([('u8', 'u8'), ('u32', 'u32')], 'u8')[0] == 'u32')
    check('pick: width tie of signs is no pick', pick_type([('u32', 'u32'), ('int', 'int')], 'u8') is None)
    check('pick: mixed pointers is no pick', pick_type([('u8*', 'u8 *'), ('void*', 'void *')], 'u8*') is None)
    check('policy: pointer never becomes an integer', not better_type('u8*', 'int'))
    check('policy: generic pointer becomes specific', better_type('void*', 'struct Foo*'))
    check('policy: specific pointer stays', not better_type('struct Foo*', 'void*'))
    check('pick: narrowest on request', pick_type([('u8', 'u8'), ('u32', 'u32')], 'u32', 'narrow')[0] == 'u8')
    check('pick: one specific pointer among generic ones',
          pick_type([('void*', 'void *'), ('struct Foo*', 'struct Foo *')])[0] == 'struct Foo*')
    check('pick: two specific pointers is no pick',
          pick_type([('struct A*', 'struct A *'), ('struct B*', 'struct B *')]) is None)
    check('cast: parenthesised', cast_text('u8 *', '(a + b)') == '(u8 *)(a + b)')
    check('cast: (a)+(b) is not one group', cast_text('int', '(a)+(b)') == '(int)((a)+(b))')
    check('cast: number', cast_text('void *', '0x20') == '(void *)0x20')
    check('cast: negative', cast_text('void *', '-1') == '(void *)(-1)')
    # spans
    s = 'x = f(a, (b, c)) ; y'
    a, b = rhs_span(s, s, s.index('='))
    check('rhs span stops at semicolon', s[a:b] == 'f(a, (b, c))')
    s = 'g(x = h(1), 2)'
    a, b = rhs_span(s, s, s.index('=') )
    check('rhs span stops at comma', s[a:b] == 'h(1)')
    s = 'g(x = h(1))'
    a, b = rhs_span(s, s, s.index('='))
    check('rhs span stops at unmatched closer', s[a:b] == 'h(1)')
    m = 'F(G(a, b), F(c, d + 1), e)'
    c = m.index('d +')
    sp = find_call_args(m, 'F', c, 2)
    check('call arg: second argument of F', sp and m[sp[0]:sp[1]].strip() == 'd + 1')
    sp = find_call_args(m, 'F', m.index('c, d'), 1)
    check('call arg: innermost F, first argument', sp and m[sp[0]:sp[1]].strip() == 'c')
    sp = find_call_args(m, 'G', m.index('b)'), 2)
    check('call arg: G second argument', sp and m[sp[0]:sp[1]].strip() == 'b')
    sp = find_call_args(m, 'F', m.index('a, b'), 1)
    check('call arg: outer F first argument contains G call', sp and m[sp[0]:sp[1]] == 'G(a, b)')
    s = 'return func_02175F3C()->field;'
    sp = postfix_before(s, s.index('->'))
    check('postfix before arrow', sp and s[sp[0]:sp[1]] == 'func_02175F3C()')
    sp = postfix_before(s, s.index('->') + 7)
    check('postfix before chain', sp and s[sp[0]:sp[1]] == 'func_02175F3C()->field')
    s = 'a & func_02175F3C(x)[1] + 2'
    sp = postfix_after(s, s.index('&') + 1)
    check('postfix after operator', sp and s[sp[0]:sp[1]] == 'func_02175F3C(x)[1]')
    check('call name', call_name_of('func_02175F3C(a, (b))', 0, 21) == 'func_02175F3C')
    check('call name rejects trailing', call_name_of('func_02175F3C(a).x', 0, 18) is None)
    # gcc json offsets (CRLF, tab)
    text = 'typedef unsigned int u32;\r\nextern void *f(void *);\r\nu32 g(u32 a)\r\n{\r\n\treturn f(a);\r\n}\r\n'
    ds = gcc_json(text, os.path.join(SP, 'protofix2', 'selftmp'), 'st.c')
    check('gcc json: one error', len(ds) >= 1)
    if ds:
        d = ds[0]
        fm = pf.mask(text)
        sp = find_call_args(fm, 'f', d.caret, 1) if d.caret is not None else None
        check('gcc json: caret inside argument (tab, CRLF)', sp and text[sp[0]:sp[1]].strip() == 'a')
    shutil.rmtree(os.path.join(SP, 'protofix2', 'selftmp'), ignore_errors=True)
    # declarator split
    sp = _split_declarators('int func_02000000(int),func_02000004(int *), *func_02000008(void)', 0,
                            len('int func_02000000(int),func_02000004(int *), *func_02000008(void)'))
    check('declarators: none because of the type prefix', sp is None)
    ln = 'func_02000000(int),func_02000004(int *), *func_02000008(void)'
    sp = _split_declarators(ln, 0, len(ln))
    check('declarators: three', sp and [x[1] for x in sp] == ['func_02000000', 'func_02000004', 'func_02000008']
          and sp[2][0] == '*')
    # isolation (fake job)
    class FakeJob:
        def __init__(self, bad, pairs=()):
            self.bad, self.pairs, self.ntrials = set(bad), pairs, 0

        def trial(self, active):
            self.ntrials += 1
            s = set(active)
            ok = not (s & self.bad) and not any(set(p) <= s for p in self.pairs)
            return Trial('', ok, '' if ok else 'bad', [])
    units = list(range(10))
    acc, fin, failed = isolate(FakeJob({3, 7}), units)
    check('isolate: maximal subset without bad units', sorted(acc) == [0, 1, 2, 4, 5, 6, 8, 9] and set(failed) == {3, 7})
    acc, fin, failed = isolate(FakeJob(set(), pairs=[(1, 2)]), units)
    check('isolate: pair conflict keeps one of two', len(acc) == 9 and len(failed) == 1)
    acc, fin, failed = isolate(FakeJob(set(units)), units)
    check('isolate: all bad', acc == [] and fin is None and len(failed) == 10)
    acc, fin, failed = isolate(FakeJob(set()), units)
    check('isolate: all good in one trial', len(acc) == 10 and not failed)
    j = FakeJob({5})
    isolate(j, units)
    check('isolate: deterministic and logarithmic', j.ntrials <= 12)
    return res


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('cmd', choices=('score', 'run', 'show', 'selftest', 'famrun'))
    ap.add_argument('file', nargs='?')
    ap.add_argument('--stage', type=int, default=2)
    ap.add_argument('--dry-run', action='store_true')
    ap.add_argument('--jobs', type=int, default=6)
    ap.add_argument('--glob')
    ap.add_argument('--files')
    ap.add_argument('--sample', type=int)
    ap.add_argument('--seed', type=int, default=1)
    ap.add_argument('--only-real', action='store_true')
    ap.add_argument('--limit', type=int)
    ap.add_argument('--classes', default='KCVW')
    ap.add_argument('--budget', type=int, default=400)
    ap.add_argument('--out', default=DEFAULT_OUT)
    ap.add_argument('--rebuild-db', action='store_true')
    ap.add_argument('--rules', default='drop_unread')
    ap.add_argument('--fam')
    ap.add_argument('--diffs', help='append the unified diff of every changed file to this file')
    a = ap.parse_args()
    if a.cmd == 'selftest':
        res = selftest()
        for ok, name in res:
            print('  %-4s %s' % ('ok' if ok else 'FAIL', name))
        bad = sum(1 for ok, _ in res if not ok)
        print('\n%d case(s), %d failure(s)' % (len(res), bad))
        sys.exit(1 if bad else 0)
    os.makedirs(a.out, exist_ok=True)
    cache = os.path.join(a.out, 'defs.pkl')
    if a.rebuild_db and os.path.exists(cache):
        os.remove(cache)
    db = pf.build_db(cache, a.jobs)
    if a.cmd == 'score':
        s = scoreboard(db, a.jobs, os.path.join(a.out, 'decls.tsv'))
        print(fmt_score(s))
        return
    if a.cmd == 'show':
        opt = {'out': a.out, 'dry_run': True, 'classes': a.classes}
        p = os.path.abspath(a.file)
        job = FileJob(p, db, opt, a.classes)
        for dc in job.cands:
            print('CAND', dc.line, dc.tag, dc.old, '->', dc.new)
        if not job.cands:
            return
        job.evaluate_orig()
        acc, final, failed = isolate(job, job.cands)
        for dc in job.cands:
            t = failed.get(dc)
            print('OK  ' if dc in acc else 'FAIL', dc.name, '' if dc in acc else reason_code(t.why, t.rem) + ' | ' + t.why[:200])
        if final:
            sys.stdout.write(unified(job.rel, job.fi.raw, final.text))
        shutil.rmtree(job.tmp, ignore_errors=True)
        return
    if a.cmd == 'famrun':
        famrun(a, db)
        return
    files = select_files(a, db)
    print('files: %d' % len(files), flush=True)
    opt = {'out': a.out, 'dry_run': a.dry_run, 'classes': a.classes, 'budget': a.budget}
    agg = Agg(a.out)
    with cf.ProcessPoolExecutor(a.jobs, initializer=worker_init, initargs=(cache,)) as ex:
        for r in ex.map(process, [(p, opt) for p in files], chunksize=1):
            agg.add(r, a.dry_run)
            if a.diffs and r.diff:
                with open(a.diffs, 'a', newline='') as f:
                    f.write(r.diff.replace(chr(13), ''))
            if agg.n % 25 == 0:
                agg.summary()
                print('%d/%d changed %d fixed %d unsolved %d %.0fs' %
                      (agg.n, len(files), agg.stats['files_changed'], agg.stats['decl_fixed'],
                       agg.stats['decl_unsolved'], time.time() - agg.t0), flush=True)
    agg.summary(True)
    print(open(os.path.join(a.out, 'summary.md')).read())


if __name__ == '__main__':
    main()
