#!/usr/bin/env python3
"""splitfile.py: split (or merge and split) src/game files into pieces by address.

    python tools/splitfile.py FILE [FILE ...] --cuts CUTS [--out DIR | --install]
                              [--dup-inline] [--check] [--header-suffix _shared_types.h]

Input: one or more merged .c files of one region (several files are treated as
one virtual file in the order given, which is how a merge is done: the pieces
cut from the concatenation).  Cut table CUTS: one piece per line,
    <start address hex> <piece file name>        # comments allowed
sorted by address.  A piece name may repeat: a later row continues that piece
at another address range, which is how a non-contiguous piece (a merge of a
second range into an existing file) is written.  A function belongs to the piece
with the greatest start address at or below the function's address.  The function address comes from
the name (func_XXXXXXXX, sub_XXXXXXXX or any name ending in 8 hex digits) or
from a --addrmap TSV (name <tab> address).

What the tool writes, per piece:
  * a file header comment (file:, function: list, address:, symbols rows the
    piece uses; compiler/flags/lang/isa/status copied from the first input);
  * the includes the piece uses (every include is scanned for the names it
    defines; unused includes are dropped), then the shared headers it needs;
  * only the declarations, types, macros, prototypes and extern data its
    functions use (transitive, by identifier), in their original order, with
    the comment block that sat above each chunk;
  * its functions in original order.  Function bodies are cut by brace
    matching, never by regex.
Macros keep their positional meaning: a use sees the definition that was active
at its place in the original file (#define/#undef sequences are replayed).
A prototype missing in the original is synthesised from the definition when a
piece calls a function of another piece and the definition came first.

Shared declarations: a type, enum, struct or single-definition macro used by
two or more pieces goes into one header per owner piece (the lowest-address
piece that uses it), named <piece stem><header-suffix>, with include guards;
a header includes the lower headers it needs.  Prototypes and extern data stay
in each piece.

Statics: a static function, static inline or C-defined data object belongs to
the piece that uses it.  Used by two or more pieces it cannot be split: the
tool lists it and the pieces to keep together and exits with status 2 without
writing anything.  --dup-inline copies a `static inline` function into every
piece that uses it instead.  An unused static goes to the piece of the next
function.

Output goes to --out DIR (default: next to the first input, not written when
--check is given).  --install writes the pieces and headers into the directory
of the first input, deletes the input files (a file whose name equals a piece
name is overwritten) and does nothing else.  Afterwards run
`python tools/gameverify.py --file P`, `tools/gamecheck.py --region R` and
`tools/gamelink.py N`.  Pieces written outside src/game need ../../matched to
resolve (a junction named src/matched next to the scratch src/game tree).
--prefer-last: when merged files declare the same function differently, the later file's
prototype is kept in the piece; the call sites of the earlier file then need casts (the
compiler lists them).  Pragmas (#pragma ...) are replayed per piece for the functions that
sat under them.  Only LF output; the tool never edits the inputs unless --install is given.
"""
import argparse
import os
import re
import sys

BS = chr(92)
ADDR_TAIL = re.compile(r'(?:^|_)([0-9A-Fa-f]{8})$')
WORD = re.compile(r'[A-Za-z_]\w*')
KEYWORDS = set('''auto break case char const continue default do double else enum extern float for goto if
inline int long register return short signed sizeof static struct switch typedef union unsigned void volatile
while asm'''.split())


# ---------------------------------------------------------------- lexing

def strip_comments_strings(t):
    """Same length as t, comments and string/char literal bodies blanked (newlines kept)."""
    out = []
    i = 0
    n = len(t)
    while i < n:
        c = t[i]
        if t.startswith('/*', i):
            j = t.find('*/', i + 2)
            j = n if j < 0 else j + 2
            out.append(re.sub(r'[^\n]', ' ', t[i:j]))
            i = j
        elif t.startswith('//', i):
            j = t.find('\n', i)
            j = n if j < 0 else j
            out.append(' ' * (j - i))
            i = j
        elif c in '"\'':
            j = i + 1
            while j < n and t[j] != c:
                if t[j] == BS:
                    j += 1
                j += 1
            j += 1
            out.append(c + ' ' * (j - i - 2) + c)
            i = j
        else:
            out.append(c)
            i += 1
    return ''.join(out)


def split_header(raw):
    """(header comment lines, index of first line after it). A file without a leading comment has none."""
    lines = raw.split('\n')
    if not lines or not lines[0].lstrip().startswith('/*'):
        return [], 0
    for i, ln in enumerate(lines):
        if '*/' in ln:
            return lines[:i + 1], i + 1
    return [], 0


class Chunk:
    __slots__ = ('idx', 'kind', 'raw', 'lead', 'clean', 'words', 'defs', 'name', 'static', 'inline',
                 'src', 'virtual', 'macro', 'op', 'sig', 'srcs', 'file')

    def __init__(self):
        self.idx = 0
        self.kind = ''      # include pp type proto extern data fdef sdef
        self.raw = ''       # source text of the chunk lines
        self.lead = ''      # comment block (and blank-line free text) before it
        self.clean = ''
        self.words = set()
        self.defs = set()
        self.name = None
        self.static = False
        self.inline = False
        self.src = ''
        self.virtual = False
        self.macro = None
        self.op = None      # define / undef
        self.sig = ''
        self.srcs = set()
        self.file = 0


def parse_chunks(raw, first_line):
    """Top-level chunks of the text after first_line: (chunks, trailing comment text)."""
    clean = strip_comments_strings(raw)
    rl = raw.split('\n')
    cl = clean.split('\n')
    n = len(cl)
    res = []
    i = first_line
    prev_end = first_line - 1
    while i < n:
        if cl[i].strip() == '':
            i += 1
            continue
        start = i
        s = cl[i].strip()
        if s.startswith('#'):
            j = i
            while cl[j].rstrip().endswith(BS):
                j += 1
            end = j
        else:
            depth = 0
            j = i
            seen = False
            while j < n:
                t = cl[j]
                for ch in t:
                    if ch == '{':
                        depth += 1
                        seen = True
                    elif ch == '}':
                        depth -= 1
                ts = t.rstrip()
                if depth == 0:
                    if ts.endswith(';'):
                        break
                    if ts.endswith('}') and seen:
                        break
                j += 1
            end = min(j, n - 1)
        lead_lines = rl[prev_end + 1:start]
        while lead_lines and lead_lines[0].strip() == '':
            lead_lines.pop(0)
        while lead_lines and lead_lines[-1].strip() == '':
            lead_lines.pop()
        c = Chunk()
        c.raw = '\n'.join(rl[start:end + 1])
        c.clean = '\n'.join(cl[start:end + 1])
        c.lead = '\n'.join(lead_lines)
        res.append(c)
        prev_end = end
        i = end + 1
    tail = [x for x in rl[prev_end + 1:]]
    while tail and tail[-1].strip() == '':
        tail.pop()
    while tail and tail[0].strip() == '':
        tail.pop(0)
    return res, '\n'.join(tail)


def declarator_names(text):
    """Identifiers declared by `... name[, name2];` pieces (array, pointer and function-pointer forms)."""
    names = set()
    for part in split_top(text, ','):
        part = re.sub(r'\[[^\]]*\]', '', part)
        part = re.sub(r'=.*', '', part, flags=re.S)
        m = re.search(r'\(\s*\*+\s*([A-Za-z_]\w*)\s*\)', part)
        if m:
            names.add(m.group(1))
            continue
        ids = [w for w in WORD.findall(part) if w not in KEYWORDS]
        if ids:
            names.add(ids[-1])
    return names


def split_top(text, sep):
    out = []
    depth = 0
    cur = []
    for ch in text:
        if ch in '({[':
            depth += 1
        elif ch in ')}]':
            depth -= 1
        if ch == sep and depth == 0:
            out.append(''.join(cur))
            cur = []
        else:
            cur.append(ch)
    out.append(''.join(cur))
    return out


def classify(c):
    t = c.clean.strip()
    c.words = set(WORD.findall(t)) - KEYWORDS
    if t.startswith('#'):
        m = re.match(r'#\s*(\w+)\s*(.*)', t, re.S)
        d = m.group(1)
        rest = m.group(2)
        if d == 'include':
            c.kind = 'include'
            mm = re.search(r'["<]([^">]+)[">]', c.raw)
            c.src = mm.group(1) if mm else ''
            c.words = set()
        elif d in ('define', 'undef'):
            c.kind = 'pp'
            c.op = d
            nm = WORD.match(rest.strip())
            c.macro = nm.group(0) if nm else None
            c.defs = {c.macro} if c.macro else set()
            # words used by the body (not the macro name)
            body = rest.strip()[len(c.macro):] if c.macro else ''
            if d == 'define' and body.startswith('('):
                pm = re.match(r'\(([^)]*)\)', body)
                params = set(WORD.findall(pm.group(1))) if pm else set()
                c.words = (set(WORD.findall(body[pm.end():])) if pm else set()) - params - KEYWORDS
            elif d == 'define':
                c.words = set(WORD.findall(body)) - KEYWORDS
            else:
                c.words = set()
        else:
            c.kind = 'pp'
            c.op = d
            c.macro = None
        return
    # function definition?
    if t.endswith('}'):
        k = t.index('{')
        pre = t[:k].rstrip()
        if pre.endswith(')') and not re.match(r'typedef\b', pre):
            body_start = k
            m = re.search(r'([A-Za-z_]\w*)\s*\(', pre)
            nm = m.group(1) if m else None
            words = pre.split('(')[0]
            c.name = nm
            c.static = bool(re.search(r'\bstatic\b', words))
            c.inline = bool(re.search(r'\binline\b', words))
            c.kind = 'sdef' if c.static else 'fdef'
            c.defs = {nm}
            # signature: raw text up to the body brace
            c.sig = signature_of(c)
            return
    first = t.split()[0] if t.split() else ''
    if first == 'typedef':
        c.kind = 'type'
        c.defs = type_names(t)
        return
    if re.match(r'(struct|union|enum)\b', first):
        brace = t.find('{')
        semi = t.rfind(';')
        if brace >= 0 or re.match(r'(struct|union|enum)\s+\w+\s*;$', t):
            c.kind = 'type'
            c.defs = type_names(t)
            return
    # prototype / extern var / data definition
    body = t.rstrip(';')
    is_ext = bool(re.match(r'extern\b', t))
    # function prototype: an identifier directly before the first '(' (a function-pointer
    # variable has `(*name)` there instead; pointer parameters do not count)
    k = body.find('(')
    before = body[:k].rstrip() if k >= 0 else ''
    m = re.search(r'([A-Za-z_]\w*)$', before)
    if k >= 0 and m and m.group(1) not in KEYWORDS and '=' not in before:
        c.kind = 'proto'
        c.name = m.group(1)
        c.defs = {c.name}
        return
    c.kind = 'extern' if is_ext else 'data'
    c.static = bool(re.search(r'\bstatic\b', body))
    c.defs = declarator_names(re.sub(r'\b(extern|static|const|volatile)\b', '', body.split('=')[0]
                                      if '=' in body else body))
    if c.kind == 'data':
        c.kind = 'ddef'


def signature_of(c):
    raw_lines = c.raw.split('\n')
    cl_lines = c.clean.split('\n')
    out = []
    for r, k in zip(raw_lines, cl_lines):
        if '{' in k:
            out.append(r[:k.index('{')].rstrip())
            break
        out.append(r)
    sig = '\n'.join(out).strip()
    return re.sub(r'\b(static|inline)\s+', '', sig) + ';'


def type_names(t):
    names = set()
    t0 = t.rstrip(';')
    m = re.match(r'(?:typedef\s+)?(struct|union|enum)\s+([A-Za-z_]\w*)', t0)
    if m:
        names.add(m.group(2))
    # enumerators
    if re.search(r'\benum\b', t0) and '{' in t0:
        k = t0.index('{')
        depth = 0
        e = k
        for i in range(k, len(t0)):
            if t0[i] == '{':
                depth += 1
            elif t0[i] == '}':
                depth -= 1
                if depth == 0:
                    e = i
                    break
        inner = t0[k + 1:e]
        # only the top-level enum body of an enum (not enums nested in structs: approximate)
        if re.match(r'(?:typedef\s+)?enum\b[^{]*$', t0[:k]):
            for part in split_top(inner, ','):
                w = WORD.match(part.strip())
                if w:
                    names.add(w.group(0))
    if t.startswith('typedef') or True:
        if '{' in t0:
            depth = 0
            e = None
            for i, ch in enumerate(t0):
                if ch == '{':
                    depth += 1
                elif ch == '}':
                    depth -= 1
                    if depth == 0:
                        e = i
                        break
            tail = t0[e + 1:] if e is not None else ''
        else:
            tail = re.sub(r'^\s*typedef\b', '', t0)
            if not t.startswith('typedef'):
                tail = ''
        if t.startswith('typedef'):
            names |= declarator_names(tail)
    return names


# ---------------------------------------------------------------- header scan of includes

_inc_cache = {}


def include_names(path, seen=None):
    """Names defined by a header file (recursively through its own includes); None when unreadable."""
    path = os.path.normpath(path)
    if path in _inc_cache:
        return _inc_cache[path]
    seen = seen or set()
    if path in seen:
        return set()
    seen.add(path)
    try:
        raw = open(path, newline='', encoding='latin1').read().replace('\r\n', '\n')
    except OSError:
        _inc_cache[path] = None
        return None
    hdr, first = split_header(raw)
    names = set()
    chunks, _tail = parse_chunks(raw, first if hdr else 0)
    for c in chunks:
        classify(c)
        if c.kind == 'include':
            sub = include_names(os.path.join(os.path.dirname(path), c.src), seen)
            if sub is None:
                _inc_cache[path] = None
                return None
            names |= sub
        else:
            names |= c.defs
            if c.kind == 'fdef' or c.kind == 'sdef':
                names.add(c.name)
    _inc_cache[path] = names
    return names


# ---------------------------------------------------------------- the unit (virtual file)

class Unit:
    def __init__(self):
        self.head = {}
        self.order = []
        self.symbols = []     # raw rows
        self.chunks = []
        self.tail = ''
        self.dir = ''


def parse_header(lines):
    head = {}
    syms = []
    insym = False
    for ln in lines:
        m = re.match(r'^ \*\s?(\w+):\s*(.*)$', ln)
        if m and not insym:
            head[m.group(1)] = m.group(2).strip()
            if m.group(1) == 'symbols':
                insym = True
            continue
        if insym:
            m = re.match(r'^ \*\s+(\S.*)$', ln)
            if m:
                syms.append(m.group(1).rstrip())
    return head, syms


def load(paths, addrmap):
    u = Unit()
    u.dir = os.path.dirname(os.path.abspath(paths[0]))
    seen_syms = set()
    seen_chunk = {}
    for k, p in enumerate(paths):
        raw = open(p, newline='', encoding='latin1').read()
        if '\r\n' in raw:
            raw = raw.replace('\r\n', '\n')
        hdr, first = split_header(raw)
        head, syms = parse_header(hdr)
        if k == 0:
            u.head = head
        for r in syms:
            nm = r.split()[0]
            if nm not in seen_syms:
                seen_syms.add(nm)
                u.symbols.append(r)
        chunks, tail = parse_chunks(raw, first)
        if tail.strip() and k == len(paths) - 1:
            u.tail = tail
        for c in chunks:
            classify(c)
            c.file = k
            c.srcs = {k}
            if len(paths) > 1:
                # an exact duplicate of a declaration of an earlier file is shared with that file's chunk
                if c.kind in ('type', 'proto', 'extern', 'include') or (c.kind == 'pp' and c.op == 'define'):
                    key = (c.kind, re.sub(r'\s+', ' ', c.raw.strip()))
                    if key in seen_chunk and k not in seen_chunk[key].srcs:
                        seen_chunk[key].srcs.add(k)
                        continue
                    seen_chunk.setdefault(key, c)
            u.chunks.append(c)
    for i, c in enumerate(u.chunks):
        c.idx = i
    return u


def func_addr(name, addrmap):
    if name in addrmap:
        return addrmap[name]
    m = ADDR_TAIL.search(name)
    return int(m.group(1), 16) if m else None


# ---------------------------------------------------------------- analysis

class Analysis:
    def __init__(self, u, cuts, addrmap, dup_inline):
        self.u = u
        self.cuts = cuts            # [(addr, name)]; a name may repeat (a piece
                                    # that continues at a second address range)
        self.pieces = []            # unique piece names, first-appearance order
        self.piece_start = []       # first cut address of each piece
        for a, n in cuts:
            if n not in self.pieces:
                self.pieces.append(n)
                self.piece_start.append(a)
        self.piece_of_cut = [self.pieces.index(n) for _a, n in cuts]
        self.dup_inline = dup_inline
        self.chunks = u.chunks
        self.owner = {}             # fdef idx -> piece index
        self.addr = {}
        self.build_defs(addrmap)

    def piece_of(self, a):
        k = None
        for i, (s, _n) in enumerate(self.cuts):
            if a >= s:
                k = i
        return None if k is None else self.piece_of_cut[k]

    def build_defs(self, addrmap):
        ch = self.chunks
        for c in ch:
            if c.kind == 'fdef':
                a = func_addr(c.name, addrmap)
                if a is None:
                    sys.exit('no address for function %s (name has no 8 hex digits; give --addrmap)' % c.name)
                k = self.piece_of(a)
                if k is None:
                    sys.exit('function %s at %08X is below the first cut' % (c.name, a))
                self.owner[c.idx] = k
                self.addr[c.idx] = a
        self.defs = {}          # name -> [chunk idx]  (everything except macros and function definitions)
        self.macro_ops = {}     # name -> [(idx, op)]
        self.fdefs = {}         # name -> fdef idx
        self.members = {}       # name -> sdef/ddef idx
        self.virtual = []       # synthesised prototypes
        protoed = set()
        for c in ch:
            if c.kind == 'pp' and c.macro and c.op in ('define', 'undef'):
                self.macro_ops.setdefault(c.macro, []).append((c.idx, c.op, c))
            elif c.kind == 'fdef':
                self.fdefs[c.name] = c.idx
            elif c.kind in ('sdef', 'ddef'):
                for n in c.defs or {c.name}:
                    self.members[n] = c.idx
            elif c.kind in ('type', 'proto', 'extern'):
                for n in c.defs:
                    self.defs.setdefault(n, []).append(c.idx)
                if c.kind == 'proto':
                    protoed.add(c.name)
        # synthesised prototypes for functions without one: virtual chunks keyed by position idx - 0.5
        self.vproto = {}
        for c in ch:
            if c.kind == 'fdef' and c.name not in protoed:
                v = Chunk()
                v.kind = 'proto'
                v.virtual = True
                v.name = c.name
                v.idx = c.idx - 0.5
                v.raw = c.sig
                v.clean = strip_comments_strings(c.sig)
                v.words = set(WORD.findall(v.clean)) - KEYWORDS
                v.defs = {c.name}
                v.lead = ''
                v.file = c.file
                v.srcs = {c.file}
                self.vproto[c.name] = v
        # includes
        self.inc_names = {}
        for c in ch:
            if c.kind == 'include':
                p = os.path.join(self.u.dir, c.src)
                names = include_names(p)
                self.inc_names[c.idx] = names
                if names is None:
                    print('warning: cannot read include %s; always kept' % c.src, file=sys.stderr)
        self.provider = {}
        for idx, names in self.inc_names.items():
            if names:
                for n in names:
                    self.provider.setdefault(n, []).append(idx)

    def active_macro(self, name, pos, usrc):
        last = None
        for idx, op, c in self.macro_ops.get(name, []):
            if idx < pos and usrc in c.srcs:
                last = (idx, op)
        if last and last[1] == 'define':
            return last[0]
        return None

    def resolve(self, w, pos, piece, usrc):
        """Chunks (real or virtual) a use of identifier w at position pos in file usrc refers to."""
        out = []
        if w in self.macro_ops:
            a = self.active_macro(w, pos, usrc)
            if a is not None:
                out.append(self.chunks[a])
        if w in self.defs:
            for i in self.defs[w]:
                c = self.chunks[i]
                if i < pos and usrc in c.srcs:
                    # a typedef of names an included header already defines is not needed
                    if c.kind == 'type' and c.defs and all(
                            any(usrc in self.chunks[j].srcs for j in self.provider.get(n, [])) for n in c.defs):
                        continue
                    out.append(c)
        if w in self.members:
            i = self.members[w]
            if usrc in self.chunks[i].srcs:
                out.append(self.chunks[i])
        if w in self.fdefs:
            i = self.fdefs[w]
            if self.owner[i] != piece and w in self.vproto and self.vproto[w].idx < pos                     and self.chunks[i].file == usrc:
                out.append(self.vproto[w])
        if w in self.provider and not out:
            cands = [i for i in self.provider[w] if usrc in self.chunks[i].srcs]
            if cands:
                out.append(self.chunks[min(cands)])
        return out

    def closure(self, seeds, piece):
        need = {}
        todo = [(c, c.idx) for c in seeds]
        while todo:
            c, pos = todo.pop()
            key = c.idx
            if key in need:
                continue
            need[key] = c
            # a macro body is expanded where it is used, so its names are looked up there
            if c.kind != 'pp':
                pos = c.idx
            for w in c.words:
                for d in self.resolve(w, pos, piece, c.file):
                    if d is c:
                        continue
                    if d.idx not in need:
                        todo.append((d, pos))
        return need

    def run(self):
        ch = self.chunks
        n = len(self.pieces)
        seeds = [[] for _ in range(n)]
        for c in ch:
            if c.kind == 'fdef':
                seeds[self.owner[c.idx]].append(c)
        need = [self.closure(seeds[k], k) for k in range(n)]
        # static users
        users = {}
        for k in range(n):
            for i, c in need[k].items():
                if c.kind in ('sdef', 'ddef'):
                    users.setdefault(i, set()).add(k)
        shared = {}
        for c in ch:
            if c.kind in ('sdef', 'ddef'):
                us = users.get(c.idx, set())
                if len(us) >= 2 and not (c.kind == 'sdef' and c.inline and self.dup_inline):
                    shared[c.idx] = sorted(us)
        self.shared_statics = shared
        if shared:
            return False
        # unused statics: piece of the next function (previous when none follows)
        for c in ch:
            if c.kind in ('sdef', 'ddef') and not users.get(c.idx):
                k = None
                for d in ch[c.idx + 1:]:
                    if d.kind == 'fdef':
                        k = self.owner[d.idx]
                        break
                if k is None:
                    for d in reversed(ch[:c.idx]):
                        if d.kind == 'fdef':
                            k = self.owner[d.idx]
                            break
                extra = self.closure([c], k)
                need[k].update(extra)
                users[c.idx] = {k}
                self.unused_static = getattr(self, 'unused_static', []) + [(c.name, self.pieces[k])]
        self.need = need
        # users of every chunk
        cu = {}
        for k in range(n):
            for i, c in need[k].items():
                cu.setdefault(i, set()).add(k)
        self.cu = cu
        # header assignment: shared typeish chunks
        self.hdr = {}
        multidef = {m for m, ops in self.macro_ops.items() if len(ops) > 1}
        for k in range(n):
            for i, c in need[k].items():
                if i in self.hdr or c.virtual:
                    continue
                us = cu[i]
                if len(us) < 2:
                    continue
                if c.kind == 'type' or (c.kind == 'pp' and c.op == 'define' and c.macro not in multidef):
                    self.hdr[i] = min(us)
        return True


# ---------------------------------------------------------------- emission

def emit(an, outdir, suffix, check_only, prefer_last=False):
    u = an.u
    ch = an.chunks
    n = len(an.pieces)
    stems = [os.path.splitext(p)[0] for p in an.pieces]
    hname = {}
    owners = sorted(set(an.hdr.values()))
    for k in owners:
        hname[k] = stems[k] + suffix
    # chunk lists
    piece_chunks = [[] for _ in range(n)]
    hdr_chunks = {k: [] for k in owners}
    for k in range(n):
        for i in sorted(an.need[k], key=lambda x: x):
            c = an.need[k][i]
            if c.kind == 'include':
                continue
            if i in an.hdr:
                continue
            if c.kind == 'fdef' and an.owner[i] != k:
                continue
            piece_chunks[k].append(c)
    for i, k in an.hdr.items():
        hdr_chunks[k].append(ch[i])
    for k in hdr_chunks:
        hdr_chunks[k].sort(key=lambda c: c.idx)

    def direct_needs(chunks, unit_k, hdr_owner):
        """(include chunk idxs, header owners) referenced directly by these chunks."""
        incs = set()
        hs = set()
        for c in chunks:
            for w in c.words:
                for d in an.resolve(w, c.idx, unit_k, c.file):
                    if d is c:
                        continue
                    if d.kind == 'include':
                        incs.add(d.idx)
                    elif d.idx in an.hdr and an.hdr[d.idx] != hdr_owner:
                        hs.add(an.hdr[d.idx])
        return incs, hs

    # #pragma state (optimizer switches) is positional: replay it for the functions of each piece
    for k in range(n):
        extra = []
        cur = {}
        for f in sorted((c for c in piece_chunks[k] if c.kind in ('fdef', 'sdef')), key=lambda c: c.idx):
            fam_last = {}
            for x in ch[:f.idx]:
                if x.kind == 'pp' and x.op == 'pragma' and (x.srcs & f.srcs):
                    toks = x.clean.split()
                    fam_last[toks[1] if len(toks) >= 2 else '#pragma'] = x
            for fam, x in fam_last.items():
                toks = x.clean.split()
                val = toks[-1] if len(toks) >= 3 else 'on'
                state = None if val == 'reset' else x
                if cur.get(fam) is not state:
                    if state is not None or cur.get(fam) is not None:
                        extra.append((f.idx, x))
                    cur[fam] = state
        for fidx, x in extra:
            piece_chunks[k].append(x)
        piece_chunks[k].sort(key=lambda c: c.idx)
    # a macro defined again in a piece needs the #undef chunks that sat between the definitions
    for k in range(n):
        have = {c.idx for c in piece_chunks[k]}
        lastdef = {}
        add = []
        for c in sorted(piece_chunks[k], key=lambda c: c.idx):
            if c.kind == 'pp' and c.op == 'define':
                d0 = lastdef.get(c.macro)
                if d0 is not None:
                    for x in ch[int(d0.idx) + 1:int(c.idx)]:
                        if x.kind == 'pp' and x.op == 'undef' and x.macro == c.macro                                 and (x.srcs & c.srcs) and x.idx not in have:
                            add.append(x)
                            have.add(x.idx)
                lastdef[c.macro] = c
        piece_chunks[k] = sorted(piece_chunks[k] + add, key=lambda c: c.idx)
    # a name declared twice with different text in one piece (plus its shared headers) is a conflict
    # between the merged files.  Reported always; --prefer-last drops the declaration of the earlier
    # file from the piece (the call sites of that file then need casts, the compiler lists them).
    an.conflicts = []
    for k in range(n):
        vis = list(piece_chunks[k])
        incs, hs = direct_needs(piece_chunks[k], k, None)
        for j in hs:
            vis += hdr_chunks[j]
        seen = {}
        fwd = re.compile(r'(struct|union|enum)\s+\w+\s*;$')
        drop = set()
        for c in vis:
            if c.kind in ('type', 'proto', 'extern'):
                txt = re.sub(r'\s+', ' ', c.clean.strip())
                if fwd.match(txt):
                    continue
                for nm in c.defs:
                    if nm in seen and seen[nm][0] != txt and not (seen[nm][2] & c.srcs):
                        an.conflicts.append((an.pieces[k], nm, seen[nm][1], c.idx))
                        loser = seen[nm][1] if max(seen[nm][2]) < max(c.srcs) else c.idx
                        drop.add(loser)
                    seen.setdefault(nm, (txt, c.idx, c.srcs))
        if prefer_last and drop:
            # the later file's declaration takes the place of the dropped one (it must precede the uses)
            byname = {}
            for c in piece_chunks[k]:
                if c.kind == 'proto':
                    byname.setdefault(c.name, []).append(c)
            out = []
            moved = set()
            for c in piece_chunks[k]:
                if c.idx in drop and c.kind == 'proto':
                    win = [w for w in byname[c.name] if w.idx not in drop]
                    if win:
                        out.append(win[0])
                        moved.add(win[0].idx)
                    continue
                if c.idx in moved:
                    continue
                out.append(c)
            # a winner met before its replacement slot was emitted twice: keep the first occurrence
            seen_idx = set()
            piece_chunks[k] = [c for c in out if not (c.idx in seen_idx or seen_idx.add(c.idx))]
    # macros: a header chunk must not need a positional (multi-def) macro: checked by construction
    outputs = {}
    stats = []
    for k in owners:
        chunks = hdr_chunks[k]
        incs, hs = direct_needs(chunks, k, k)
        for j in hs:
            if j > k:
                sys.exit('header %s needs the later header %s' % (hname[k], hname[j]))
        hs.discard(k)
        guard = re.sub(r'[^A-Za-z0-9]', '_', hname[k]).upper()
        lines = ['#ifndef %s' % guard, '#define %s' % guard, '']
        for i in sorted(incs):
            lines.append(ch[i].raw)
        for j in sorted(hs):
            lines.append('#include "%s"' % hname[j])
        if incs or hs:
            lines.append('')
        lines.append(render(chunks))
        lines.append('')
        lines.append('#endif')
        outputs[hname[k]] = '\n'.join(lines) + '\n'
    for k in range(n):
        chunks = piece_chunks[k]
        incs, hs = direct_needs(chunks, k, None)
        # includes used by included headers' content are inside those headers
        fn_chunks = [c for c in chunks if c.kind == 'fdef']
        fns = sorted(fn_chunks, key=lambda c: an.addr[c.idx])
        body = render(chunks)
        usedtext = body + '\n' + '\n'.join(outputs[hname[j]] for j in sorted(hs))
        syms = [r for r in u.symbols if re.search(r'(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])' % re.escape(r.split()[0]), usedtext)]
        have = {r.split()[0] for r in syms}
        isa = (u.head.get('isa') or 'thumb').split()[0]
        region = u.head.get('region', '')
        usedwords = set(WORD.findall(strip_comments_strings(usedtext)))
        for nm, i in sorted(an.fdefs.items(), key=lambda kv: an.addr[kv[1]]):
            if an.owner[i] != k and nm in usedwords and nm not in have:
                syms.append('%s 0x%08X %s %s' % (nm, an.addr[i], isa, region))
        head = ['/*', ' * file:     %s' % an.pieces[k], ' * unit:     yes',
                ' * function: %s' % ', '.join(c.name for c in fns),
                ' * address:  0x%08X' % an.addr[fns[0].idx] if fns else ' * address:  0x%08X' % an.piece_start[k]]
        for key in ('region', 'compiler', 'flags', 'lang', 'isa', 'status'):
            if key in u.head:
                head.append(' * %-9s %s' % (key + ':', u.head[key]))
        head += [' *', ' * Cut from %s by tools/splitfile.py.' % ', '.join(os.path.basename(p) for p in an.inputs),
                 ' *', ' * symbols:']
        head += [' *   ' + r for r in syms]
        head.append(' */')
        lines = head
        for i in sorted(incs):
            lines.append(ch[i].raw)
        for j in sorted(hs):
            lines.append('#include "%s"' % hname[j])
        lines.append('')
        lines.append(body)
        if k == n - 1 and u.tail.strip():
            lines.append('')
            lines.append(u.tail)
        outputs[an.pieces[k]] = '\n'.join(lines).rstrip('\n') + '\n'
        stats.append((an.pieces[k], len(fns), outputs[an.pieces[k]].count('\n')))
    return outputs, stats, hname


def render(chunks):
    out = []
    prev = None
    for c in chunks:
        txt = (c.lead + '\n' if c.lead else '') + c.raw
        if prev is not None:
            out.append('')
        out.append(txt)
        prev = c
    return '\n'.join(out)


# ---------------------------------------------------------------- main

def piece_name(name):
    """Output piece names always end in .c (a missing or other extension is replaced)."""
    base = os.path.basename(name)
    d = name[:len(name) - len(base)]
    if base.lower().endswith('.c'):
        base = base[:-2] + '.c'
    else:
        base = os.path.splitext(base)[0] + '.c' if '.' in base else base + '.c'
    return d + base


def lf(text):
    """Output text always uses LF line ends."""
    return text.replace("\r\n", "\n").replace("\r", "\n")


def read_cuts(path):
    cuts = []
    for ln in open(path):
        ln = ln.split('#')[0].strip()
        if not ln:
            continue
        a, name = ln.split()[:2]
        cuts.append((int(a, 16), piece_name(name)))
    cuts.sort()
    # A repeated piece name is allowed: the piece continues at a second address
    # range (a merge of a non-contiguous piece into one output file).
    return cuts


def selftest():
    """piece_name keeps .c; lf strips CR; a cut table without extensions still yields .c pieces."""
    import shutil
    import tempfile
    assert piece_name('a') == 'a.c' and piece_name('a.c') == 'a.c' and piece_name('a.C') == 'a.c'
    assert piece_name('a.txt') == 'a.c' and piece_name('dir/b') == 'dir/b.c'
    assert lf("x\r\ny\rz\n") == "x\ny\nz\n"
    d = tempfile.mkdtemp(prefix='splitfile_selftest_')
    t = os.path.join(d, 'cuts.tsv')
    with open(t, 'w', newline='') as f:
        f.write("02000000 first\n02000100 second.txt\n")
    assert [n for _a, n in read_cuts(t)] == ['first.c', 'second.c']
    shutil.rmtree(d, ignore_errors=True)
    print('splitfile selftest: PASS')


def main():
    if sys.argv[1:] == ['--selftest']:
        selftest()
        return
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('files', nargs='+')
    ap.add_argument('--cuts', required=True)
    ap.add_argument('--out')
    ap.add_argument('--install', action='store_true')
    ap.add_argument('--check', action='store_true')
    ap.add_argument('--dup-inline', action='store_true')
    ap.add_argument('--prefer-last', action='store_true',
                    help='on conflicting prototypes between merged files keep those of the later file')
    ap.add_argument('--addrmap')
    ap.add_argument('--header-suffix', default='_shared_types.h')
    a = ap.parse_args()
    addrmap = {}
    if a.addrmap:
        for ln in open(a.addrmap):
            f = ln.split()
            if len(f) >= 2:
                addrmap[f[0]] = int(f[1], 16)
    u = load(a.files, addrmap)
    cuts = read_cuts(a.cuts)
    an = Analysis(u, cuts, addrmap, a.dup_inline)
    an.inputs = a.files
    ok = an.run()
    if not ok:
        print('CANNOT SPLIT: statics shared across pieces (keep those pieces together or use --dup-inline):')
        for i, ks in sorted(an.shared_statics.items()):
            c = an.chunks[i]
            print('  %s %s (line chunk %d) used by: %s' % (c.kind, c.name or sorted(c.defs), i,
                                                          ', '.join(an.pieces[k] for k in ks)))
        sys.exit(2)
    outputs, stats, hname = emit(an, a.out, a.header_suffix, a.check, a.prefer_last)
    for name, nf, nl in stats:
        print('%-28s %4d functions %7d lines' % (name, nf, nl))
    for h in sorted(hname.values()):
        print('%-28s header %7d lines' % (h, outputs[h].count('\n')))
    for pc, nm, i1, i2 in an.conflicts:
        print('CONFLICT in %s: %s declared differently (chunks %d and %d)' % (pc, nm, i1, i2))
    for nm, pc in getattr(an, 'unused_static', []):
        print('unused static %s placed in %s' % (nm, pc))
    if a.check:
        return
    if a.install:
        outdir = u.dir
    else:
        outdir = a.out or u.dir
    os.makedirs(outdir, exist_ok=True)
    for name, text in outputs.items():
        with open(os.path.join(outdir, name), 'w', newline='', encoding='latin1') as f:
            f.write(lf(text))
    if a.install:
        keep = set(outputs)
        for p in a.files:
            if os.path.basename(p) not in keep:
                os.remove(p)
    print('wrote %d files to %s' % (len(outputs), outdir))


if __name__ == '__main__':
    main()
