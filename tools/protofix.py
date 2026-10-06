#!/usr/bin/env python3
"""protofix.py: make each matched file's extern declarations agree with the
callee's real definition, and keep a change only when it verifies.

What it does
  1. Reads every src/matched/**/*.c.  For each defined function it records
     the prototype, keyed by (region, address).  Types in the prototype are
     resolved to builtin types, u8..s32, or "struct X" (pointer only).
  2. For each file it finds every function declaration (file scope or block
     scope).  The callee is found through the header `symbols:` line (name,
     address, optional region token) and the file's own region.  Names that
     encode their address (func_XXXXXXXX) are used when no symbols line
     exists.  A declaration is skipped when the callee is not unique.
  3. It rewrites the declaration to the definition's return type and
     parameter types.  Call statements, returns and bodies are never touched.
     It adds `struct X;` forward declarations and missing u8..s32 typedefs.
     Bytes outside the edited spans are kept byte for byte (CRLF and LF).
  4. Each candidate file goes to a scratch directory first.  The tool runs
     match.py (`one`, or `tu` for unit files, each with --lang c99 and without
     --lang) and the GCC syntax check on the original and on the candidate.
     The candidate is kept only if all verdicts equal the original verdicts and
     GCC shows no new error message.  If the whole file fails, each declaration
     is tried alone.  Failed declarations go to reverted.csv.
  5. src/pending is never edited.  `--pending-report` lists pending declarers.

usage
  python tools/protofix.py [--dry-run] [--jobs 6] [--glob 'src/matched/ov/ov217_*']
                           [--files LIST] [--out DIR] [--no-verify] [--limit N]
  python tools/protofix.py --dump FILE        show defs, decls and proposals
  python tools/protofix.py --pending-report   write pending.csv, no edits
"""
import argparse
import bisect
import collections
import concurrent.futures as cf
import csv
import fnmatch
import os
import pickle
import re
import shutil
import subprocess
import sys
import time

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
GCC = os.path.join(ROOT, 'tools', 'gcc-arm', 'xpack-arm-none-eabi-gcc-14.2.1-1.1',
                   'bin', 'arm-none-eabi-gcc.exe')
DEFAULT_OUT = ('<home>/AppData/Local/Temp/claude/<project>/'
               'd965be22-e087-410a-b91d-ae680804241d/scratchpad/protofix')

NAME_RE = r'(?:func|sub)_[0-9A-Fa-f]{8}'
BUILTIN = set('int char short long unsigned signed void float double const volatile'.split())
SKIPWORDS = {'inline', '__inline', 'register', 'extern', 'static'}
STD = {'u8': 'unsigned char', 'u16': 'unsigned short', 'u32': 'unsigned int',
       's8': 'signed char', 's16': 'signed short', 's32': 'signed int'}
STD_LINE = {'u8': 'typedef unsigned char  u8;', 'u16': 'typedef unsigned short u16;',
            'u32': 'typedef unsigned int   u32;', 's8': 'typedef signed char    s8;',
            's16': 'typedef signed short   s16;', 's32': 'typedef signed int     s32;'}
STOP_WORDS = {'return', 'else', 'do', 'case', 'goto', 'sizeof', 'if', 'while', 'for',
              'switch', 'typedef', 'default', 'break', 'continue'}

# ---------------------------------------------------------------------------
# text helpers
# ---------------------------------------------------------------------------

_MASK_RE = re.compile(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'|'
                      r'^[ \t]*#(?:[^\n]*\\\n)*[^\n]*', re.S | re.M)


def _blank(m):
    return re.sub(r'[^\n]', ' ', m.group(0))


def mask(s):
    """Blank comments, strings, char literals and preprocessor lines (same length)."""
    return _MASK_RE.sub(_blank, s)


def depth_table(m):
    pos, dep, d = [], [], 0
    for i, c in enumerate(m):
        if c == '{':
            d += 1
            pos.append(i)
            dep.append(d)
        elif c == '}':
            d -= 1
            pos.append(i)
            dep.append(d)
    return pos, dep


def depth_at(tab, p):
    pos, dep = tab
    i = bisect.bisect_left(pos, p)
    return dep[i - 1] if i else 0


def split_top(s):
    out, d, cur = [], 0, ''
    for c in s:
        if c in '([':
            d += 1
        if c in ')]':
            d -= 1
        if c == ',' and d == 0:
            out.append(cur)
            cur = ''
        else:
            cur += c
    out.append(cur)
    return out


def tokens(t):
    return re.findall(r'\*|\.\.\.|[A-Za-z_]\w*|\d+', t)


def tok_text(toks):
    s = ' '.join(toks)
    return re.sub(r'\*( \*)+', lambda m: m.group(0).replace(' ', ''), s)


# ---------------------------------------------------------------------------
# header
# ---------------------------------------------------------------------------

def parse_header(raw):
    m = re.match(r'\s*/\*.*?\*/', raw, re.S)
    h = {'symbols': {}}
    if not m:
        return h
    in_sym = False
    for line in m.group(0).split('\n'):
        line = line.rstrip('\r')
        if re.match(r'^\s*\*\s*symbols:\s*$', line):
            in_sym = True
            continue
        if in_sym:
            sm = re.match(r'^\s*\*\s+(\w+)\s+(0x[0-9A-Fa-f]+)\s+(\w+)((?:\s+\w+)*)\s*$', line)
            if sm:
                reg = None
                for e in sm.group(4).split():
                    if not re.match(r'^a\d+$', e):
                        reg = e
                if reg == 'arm9':
                    reg = None
                h['symbols'].setdefault(sm.group(1), (int(sm.group(2), 16), sm.group(3), reg))
                continue
            if re.match(r'^\s*\*\s*$', line):
                continue
            in_sym = False
        mm = re.match(r'^\s*\*\s*([a-z_]+):\s*(.*?)\s*$', line)
        if mm:
            h.setdefault(mm.group(1), mm.group(2))
    return h


# ---------------------------------------------------------------------------
# typedef parsing and type resolution
# ---------------------------------------------------------------------------

class Unrep(Exception):
    pass


def parse_typedefs(m, tab):
    """name -> dict(kind, toks, tag, anon, sk).  File-scope typedefs only."""
    td = {}
    for mt in re.finditer(r'\btypedef\b', m):
        if depth_at(tab, mt.start()) != 0:
            continue
        i, d = mt.end(), 0
        while i < len(m):
            c = m[i]
            if c == '{':
                d += 1
            elif c == '}':
                d -= 1
            elif c == ';' and d == 0:
                break
            i += 1
        body = m[mt.end():i]
        if '{' in body:
            a = body.index('{')
            b = body.rindex('}')
            head, tail = tokens(body[:a]), body[b + 1:]
            kind = head[0] if head and head[0] in ('struct', 'union', 'enum') else 'struct'
            tag = head[1] if len(head) > 1 else None
            for dc in split_top(tail):
                tk = tokens(dc)
                if not tk:
                    continue
                name = tk[-1]
                stars = [x for x in tk[:-1] if x == '*']
                if stars:
                    td[name] = {'kind': 'alias', 'toks': [kind, tag or '<anon>'] + stars,
                                'tag': tag, 'anon': tag is None, 'sk': kind}
                else:
                    td[name] = {'kind': kind, 'toks': [], 'tag': tag, 'anon': tag is None}
            continue
        if '(' in body:
            mm = re.search(r'\(\s*\*?\s*(\w+)\s*\)', body)
            if mm:
                td[mm.group(1)] = {'kind': 'func', 'toks': [], 'tag': None}
            continue
        if '[' in body:
            tk = tokens(re.sub(r'\[[^\]]*\]', '', body))
            if tk:
                td[tk[-1]] = {'kind': 'array', 'toks': [], 'tag': None}
            continue
        pieces = split_top(body)
        first = tokens(pieces[0])
        if len(first) < 2:
            continue
        base = [x for x in first[:-1] if x != '*']
        stars0 = [x for x in first[:-1] if x == '*']
        td[first[-1]] = {'kind': 'alias', 'toks': base + stars0, 'tag': None}
        for p in pieces[1:]:
            tk = tokens(p)
            if tk:
                td[tk[-1]] = {'kind': 'alias', 'toks': base + [x for x in tk[:-1] if x == '*'],
                              'tag': None}
    return td


def resolve(toks, td, need, depth=0):
    """Resolve a type token list; need collects ('typedef',u8) and ('struct',X)."""
    if depth > 8:
        raise Unrep('typedef loop')
    out = []
    i = 0
    while i < len(toks):
        w = toks[i]
        if w == '*':
            out.append('*')
        elif w in SKIPWORDS:
            pass
        elif w in ('struct', 'union'):
            if i + 1 >= len(toks) or toks[i + 1] in BUILTIN:
                raise Unrep('bad %s' % w)
            out += [w, toks[i + 1]]
            need.add((w, toks[i + 1]))
            i += 1
        elif w == 'enum':
            out.append('int')
            i += 1
        elif w in BUILTIN:
            out.append(w)
        elif w in STD:
            out.append(w)
            need.add(('typedef', w))
        elif w in td:
            t = td[w]
            if t['kind'] == 'alias':
                if t.get('sk') in ('struct', 'union') and t.get('anon'):
                    raise Unrep('anonymous struct typedef %s' % w)
                out += resolve(t['toks'], td, need, depth + 1)
            elif t['kind'] in ('struct', 'union'):
                if t['anon'] or not t['tag']:
                    raise Unrep('anonymous struct typedef %s' % w)
                out += [t['kind'], t['tag']]
                need.add((t['kind'], t['tag']))
            elif t['kind'] == 'enum':
                out.append('int')
            else:
                raise Unrep('%s typedef %s' % (t['kind'], w))
        else:
            raise Unrep('unknown type %s' % w)
        i += 1
    for k, w in enumerate(out):
        if w in ('struct', 'union') and '*' not in out[k + 2:]:
            raise Unrep('struct by value')
    return out


def parse_param(p, td):
    """-> (toks, name, opaque)."""
    p = p.strip()
    if p == '...':
        return ['...'], '', None
    if '(' in p:
        return None, '', re.sub(r'\s+', ' ', p)
    p = re.sub(r'\[[^\]]*\]', '*', p)
    tk = tokens(p)
    name = ''
    if len(tk) >= 2:
        last = tk[-1]
        if (re.match(r'[A-Za-z_]', last) and last not in BUILTIN and last not in STD
                and last not in td and last not in SKIPWORDS
                and tk[-2] not in ('struct', 'union', 'enum')):
            name = last
            tk = tk[:-1]
    return tk, name, None


def resolve_proto(ret_txt, params_txt, td):
    need = set()
    ret = resolve(tokens(ret_txt), td, need)
    plist = []
    pt = params_txt.strip()
    ps = [] if pt in ('', 'void') else split_top(pt)
    for p in ps:
        tk, name, opq = parse_param(p, td)
        if opq is not None:
            ids = [x for x in tokens(opq) if re.match(r'[A-Za-z_]', x)]
            bad = [x for x in ids if x not in BUILTIN and x not in STD]
            if len(bad) > 1:
                raise Unrep('function pointer parameter')
            for x in ids:
                if x in STD:
                    need.add(('typedef', x))
            plist.append((None, '', opq))
        elif tk == ['...']:
            plist.append((['...'], '', None))
        else:
            plist.append((resolve(tk, td, need), name, None))
    return ret, plist, need


_SYN = [(r'\bunsigned char\b', 'u8'), (r'\bunsigned short\b', 'u16'), (r'\bunsigned int\b', 'u32'),
        (r'\bunsigned long\b', 'u32'), (r'\bunsigned\b(?! *(?:char|short|int|long))', 'u32'),
        (r'\bsigned char\b', 's8'), (r'\bsigned short\b', 's16'), (r'\bsigned int\b', 'int'),
        (r'\bs32\b', 'int'), (r'\blong\b', 'int'), (r'\bshort int\b', 'short'),
        (r'\bs16\b', 'short')]


def norm_toks(toks):
    t = ' '.join(toks).replace('*', ' * ')
    for a, b in _SYN:
        t = re.sub(a, b, t)
    return re.sub(r'\s+', ' ', t).strip().replace(' *', '*').replace('* ', '*')


def norm_key(ret, plist):
    ps = []
    for tk, name, opq in plist:
        ps.append('(' + re.sub(r'\s+', '', opq) + ')' if opq is not None else norm_toks(tk))
    return '%s (%s)' % (norm_toks(ret), ','.join(ps))


_W8, _W16 = ('u8', 's8', 'char'), ('u16', 's16', 'short')


def _width(t):
    t = t.replace('const', '').strip()
    return 8 if t in _W8 else 16 if t in _W16 else 32


def tags(a, b):
    """K pointer vs int, W width, C count, V void vs value, S signedness, P pointee."""
    ra, pa = a.split(' (', 1)
    rb, pb = b.split(' (', 1)
    pa = [x for x in pa.rstrip(')').split(',') if x]
    pb = [x for x in pb.rstrip(')').split(',') if x]
    out = set()
    if len(pa) != len(pb):
        out.add('C')
    for x, y, w in [(ra, rb, 'r')] + [(x, y, 'a') for x, y in zip(pa, pb)]:
        if x == y:
            continue
        if (x == 'void') != (y == 'void') and w == 'r':
            out.add('V')
            continue
        px, py = '*' in x, '*' in y
        if px and py:
            out.add('P')
        elif px != py:
            out.add('K')
        elif _width(x) != _width(y):
            out.add('W')
        else:
            out.add('S')
    return ''.join(sorted(out))


# ---------------------------------------------------------------------------
# per-file parse
# ---------------------------------------------------------------------------

DECL_RE = re.compile(r'^[ \t]*((?:(?:extern|static)\s+)*)([A-Za-z_][\w\s\*]*?)\b(' + NAME_RE +
                     r')\s*\(([^;{}]*)\)\s*([;{])', re.M)


class FileInfo:
    pass


def construct_start(m, tab, pos):
    """Line offset where the top-level construct holding pos begins."""
    if depth_at(tab, pos) == 0:
        return m.rfind('\n', 0, pos) + 1
    posl, depl = tab
    i = bisect.bisect_left(posl, pos) - 1
    while i >= 0 and not (depl[i] == 1 and m[posl[i]] == '{'):
        i -= 1
    q = posl[i] if i >= 0 else pos
    ls = m.rfind('\n', 0, q) + 1
    while ls > 0:
        pls = m.rfind('\n', 0, ls - 1) + 1
        prev = m[pls:ls].strip()
        if prev == '' or prev[-1] in ';}':
            break
        ls = pls
    return ls


def parse_file(path, rel=None, want_decls=True):
    with open(path, 'rb') as f:
        raw = f.read().decode('latin1')
    fi = FileInfo()
    fi.path = path
    fi.rel = rel or os.path.relpath(path, ROOT).replace(os.sep, '/')
    fi.raw = raw
    fi.h = parse_header(raw)
    fi.region = fi.h.get('region', '?')
    fi.mask = m = mask(raw)
    fi.tab = tab = depth_table(m)
    fi.td = parse_typedefs(m, tab)
    fi.has_include = bool(re.search(r'^[ \t]*#[ \t]*include(?![ \t]+"\.\./include/Obj\d+\.h")', raw, re.M))
    fi.defs, fi.decls = [], []
    for mm in DECL_RE.finditer(m):
        pre, ret_txt, name, params, term = mm.groups()
        rt = tokens(ret_txt)
        if not rt or any(t in STOP_WORDS for t in rt):
            continue
        d = depth_at(tab, mm.start())
        if term == '{':
            if d == 0:
                fi.defs.append((name, mm, ret_txt, params))
        elif want_decls:
            fi.decls.append((name, mm, ret_txt, params, d != 0))
    return fi


# ---------------------------------------------------------------------------
# definition database
# ---------------------------------------------------------------------------

def all_matched():
    out = []
    for dp, dn, fn in os.walk(os.path.join(ROOT, 'src', 'matched')):
        for f in fn:
            if f.endswith('.c'):
                out.append(os.path.join(dp, f))
    out.sort()
    return out


def build_db(cache=None, jobs=6):
    if cache and os.path.exists(cache):
        try:
            with open(cache, 'rb') as f:
                db = pickle.load(f)
            if db.get('ver') == 3:
                return db
        except Exception:
            pass
    files = all_matched()
    defs = collections.defaultdict(list)

    def one(p):
        out = []
        try:
            fi = parse_file(p, want_decls=False)
        except Exception:
            return out
        if fi.h.get('status', '').startswith(('DIFF', 'PENDING')):
            return out
        for name, mm, ret_txt, params in fi.defs:
            addr = int(name[-8:], 16)
            try:
                ret, pl, need = resolve_proto(ret_txt, params, fi.td)
                rec = {'ret': ret, 'params': pl, 'need': need, 'unrep': None}
            except Unrep as e:
                rec = {'ret': None, 'params': None, 'need': set(), 'unrep': str(e)}
            rec['file'] = fi.rel
            rec['name'] = name
            out.append(((fi.region, addr), rec))
        return out

    with cf.ThreadPoolExecutor(jobs) as ex:
        for res in ex.map(one, files):
            for k, rec in res:
                defs[k].append(rec)
    db = {'ver': 3, 'defs': dict(defs)}
    if cache:
        with open(cache, 'wb') as f:
            pickle.dump(db, f)
    return db


NON_OVERLAY = ('arm9', 'twl', 'arm9_autoload0_ITCM')


_SHARD_SRC = None


def shard_sources():
    """{(region, address): source path} of every EXACT/EXACT* shard entry: the file
    the verification records name for that function."""
    global _SHARD_SRC
    if _SHARD_SRC is None:
        import glob
        import json
        _SHARD_SRC = {}
        for sp in glob.glob(os.path.join(ROOT, 'layout', 'matched', '*', '*.json')):
            try:
                with open(sp, encoding='utf-8') as f:
                    d = json.load(f)
            except Exception:
                continue
            for e in d.get('functions', []):
                if not isinstance(e, dict) or not str(e.get('status', '')).startswith('EXACT'):
                    continue
                try:
                    a = int(str(e.get('address')), 16)
                except ValueError:
                    continue
                _SHARD_SRC.setdefault((e.get('region') or d.get('region'), a), e.get('source'))
    return _SHARD_SRC


def find_callee(db, fi, name):
    """-> (rec or None, status)."""
    sym = fi.h['symbols'].get(name)
    if sym is not None:
        addr, kind, reg = sym
    else:
        addr, kind, reg = int(name[-8:], 16), None, None
    if kind == 'data':
        return None, 'data'
    defs = db['defs']
    if reg:
        cands = defs.get((reg, addr), [])
        regs = [reg] if cands else []
    else:
        regs = [r for r in {fi.region, *NON_OVERLAY} if (r, addr) in defs]
        cands = [d for r in regs for d in defs[(r, addr)]]
    if not cands:
        return None, 'nodef'
    if len(regs) > 1:
        return None, 'ambiguous region'
    if len(cands) > 1:
        # two files define the function: the one its verification record names wins
        src = shard_sources().get((regs[0], addr)) if regs else None
        pick = [d for d in cands if d['file'] == src]
        if len(pick) != 1:
            return None, 'ambiguous duplicate definitions'
        cands = pick
    rec = cands[0]
    if rec['file'] == fi.rel:
        return None, 'self'
    return rec, 'ok'


# ---------------------------------------------------------------------------
# proposals
# ---------------------------------------------------------------------------

class Prop:
    __slots__ = ('idx', 'name', 'start', 'end', 'old', 'new', 'tag', 'need', 'cstart',
                 'block', 'callee', 'line')


def render(name, ret, plist):
    ps = []
    for tk, pname, opq in plist:
        if opq is not None:
            ps.append(opq)
        elif tk == ['...']:
            ps.append('...')
        else:
            t = tok_text(tk)
            ps.append(t + ('' if t.endswith('*') else ' ') + pname if pname else t)
    rt = tok_text(ret)
    return '%s%s%s(%s)' % (rt, '' if rt.endswith('*') else ' ', name, ', '.join(ps) if ps else 'void')


def proposals(fi, db, stats, skipped):
    out = []
    for idx, (name, mm, ret_txt, params, block) in enumerate(fi.decls):
        rec, st = find_callee(db, fi, name)
        old_txt = re.sub(r'\s+', ' ', fi.raw[mm.start(2):mm.end(4) + 1]).strip()
        if rec is None:
            stats['decl_' + st] += 1
            if st.startswith('ambiguous'):
                skipped.append((fi.rel, name, old_txt, 'unmappable: ' + st))
            continue
        if rec['unrep']:
            stats['decl_unrep'] += 1
            skipped.append((fi.rel, name, old_txt,
                            'unrepresentable: %s (definition in %s)' % (rec['unrep'], rec['file'])))
            continue
        try:
            oret, oplist, _n = resolve_proto(ret_txt, params, fi.td)
            okey = norm_key(oret, oplist)
        except Unrep:
            okey = None
        dkey = norm_key(rec['ret'], rec['params'])
        if okey == dkey:
            stats['decl_same'] += 1
            continue
        p = Prop()
        p.idx = idx
        p.name = name
        p.start = mm.start(2)
        p.end = mm.end(4) + 1
        p.old = old_txt
        p.new = render(name, rec['ret'], rec['params'])
        p.tag = tags(okey, dkey) if okey else 'U'
        p.need = set(rec['need'])
        p.block = block
        p.callee = rec
        p.cstart = construct_start(fi.mask, fi.tab, mm.start())
        p.line = fi.raw.count('\n', 0, mm.start()) + 1
        out.append(p)
    return out


def typedef_state(fi, tname, pos):
    """True: defined before pos; False: defined only after; None: absent."""
    for mt in re.finditer(r'\btypedef\b[^;]*\b' + tname + r'\s*;', fi.mask):
        if depth_at(fi.tab, mt.start()) == 0:
            return mt.start() < pos
    return None


def build_text(fi, props):
    """Apply props.  Returns (text, dropped props)."""
    props = sorted(props, key=lambda p: p.start)
    if not props:
        return fi.raw, []
    ins = min(p.cstart for p in props)
    need_td, need_st = set(), set()
    for p in props:
        for k, w in p.need:
            (need_td.add(w) if k == 'typedef' else need_st.add((k, w)))
    bad, add_td = [], []
    for w in sorted(need_td):
        r = typedef_state(fi, w, ins)
        if r is None:
            add_td.append(w)
        elif r is False:
            bad.append(w)
    if bad:
        keep = [p for p in props if not any(('typedef', w) in p.need for w in bad)]
        dropped = [p for p in props if p not in keep]
        t, d2 = build_text(fi, keep)
        return t, dropped + d2
    text = fi.raw
    for p in sorted(props, key=lambda p: -p.start):
        text = text[:p.start] + p.new + text[p.end:]
    eol_pos = text.find('\n', ins)
    eol = '\r\n' if eol_pos > 0 and text[eol_pos - 1] == '\r' else '\n'
    lines = [STD_LINE[w] for w in add_td]
    for k, w in sorted(need_st):
        if not re.search(r'\b' + k + r'\s+' + w + r'\b', fi.mask[:ins]):
            lines.append('%s %s;' % (k, w))
    if lines:
        text = text[:ins] + ''.join(l + eol for l in lines) + text[ins:]
    return text, []


# ---------------------------------------------------------------------------
# verification
# ---------------------------------------------------------------------------

def sh(cmd, timeout=300):
    for attempt in range(2):
        try:
            r = subprocess.run(cmd, cwd=ROOT, capture_output=True, timeout=timeout)
            so = r.stdout.decode('utf-8', 'replace')
            both = so + '\n' + r.stderr.decode('utf-8', 'replace')
            if so.strip() or attempt == 1:
                return so, both
        except subprocess.TimeoutExpired:
            if attempt == 1:
                return '', 'timeout'
    return '', ''


CLI_MODE = False


def verdict(spec, lang):
    """Match verdict for spec.  In-process call of match.run_one/run_tu (same code as
    the CLI `one`/`tu` commands), or the CLI itself with --cli."""
    for attempt in range(2):
        if CLI_MODE:
            args = ([spec['kind'], '--src', spec['src'], '--addr', spec['addr'], '--region', spec['region'],
                     '--' + spec['isa']] + (['--cc', spec['cc']] if spec['cc'] != '1.1p1' else []) +
                    (['--flags', spec['flags']] if spec['flags'] else []) +
                    (['--func', spec['func']] if spec['kind'] == 'one' else []) +
                    (['--lang', lang] if lang else []))
            so, both = sh([sys.executable, os.path.join(ROOT, 'tools', 'match.py')] + args)
            w = (so.strip().split(chr(10)) or [''])[0].split()
            st = w[0] if w else ''
        else:
            try:
                import match
                addr = int(spec['addr'], 0)
                flags = spec['flags'].split() if spec['flags'] else ['-O4,p']
                thumb = spec['isa'] == 'thumb'
                if spec['kind'] == 'one':
                    r = match.run_one(spec['src'], spec['func'], addr, spec['cc'], flags, thumb, lang,
                                      region=spec['region'])
                else:
                    r = match.run_tu(spec['src'], addr, spec['cc'], flags, thumb, lang,
                                     region=spec['region'])[0]
                st = r.status
            except (Exception, SystemExit) as e:
                st = 'ERR:%r' % (e,)
        if st in ('EXACT', 'EXACT*', 'MATCH', 'SIZE', 'DIFF', 'CCERR'):
            return st
        last = st
    return 'ERR:' + str(last)[:80]


def gcc_errors(path):
    so, both = sh([GCC, '-fsyntax-only', '-std=c99', '-w', '-fno-builtin', path])
    errs = collections.Counter()
    for line in both.split('\n'):
        if 'error' in line.lower():
            msg = re.sub(r'^.*?:\d+:\d+:\s*', '', line.strip())
            errs[msg] += 1
    return errs


def match_spec(fi, path):
    h = fi.h
    isa = (h.get('isa', 'thumb').split() or ['thumb'])[0]
    names = [n.strip() for n in h.get('function', '').split(',') if n.strip()]
    unit = h.get('unit', '').strip().lower() in ('yes', 'true', '1') or len(names) > 1
    if not names:
        names = [os.path.splitext(os.path.basename(fi.rel))[0]]
    cc = h.get('compiler', '1.1p1')
    if cc.startswith('dsi/'):
        cc = cc[4:]
    fl = h.get('flags', '-O4,p')
    return {'kind': 'tu' if unit else 'one', 'src': path, 'addr': h['address'], 'region': fi.region,
            'isa': isa, 'cc': cc, 'flags': '' if fl == '-O4,p' else fl, 'func': names[0]}


def evaluate(fi, text, tmpdir, orig=None):
    """Verdicts and gcc errors of text.  With orig given, a new gcc error stops early
    (the match runs are skipped; compare_eval reports the gcc error)."""
    os.makedirs(tmpdir, exist_ok=True)
    p = os.path.join(tmpdir, os.path.basename(fi.rel))
    for hn in re.findall(r'^[ \t]*#[ \t]*include[ \t]+"\.\./include/(Obj\d+\.h)"', text, re.M):
        hd = os.path.join(os.path.dirname(tmpdir), 'include')
        os.makedirs(hd, exist_ok=True)
        hs = os.path.join(ROOT, 'src', 'matched', 'include', hn)
        if os.path.exists(hs) and not os.path.exists(os.path.join(hd, hn)):
            shutil.copyfile(hs, os.path.join(hd, hn))
    with open(p, 'wb') as f:
        f.write(text.encode('latin1'))
    g = gcc_errors(p)
    if orig is not None and (g - orig['gcc']):
        return {'c99': None, 'nolang': None, 'gcc': g}
    spec = match_spec(fi, p)
    return {'c99': verdict(spec, 'c99'), 'nolang': verdict(spec, None), 'gcc': g}


def compare_eval(o, c):
    if c['c99'] is None:
        return 'gcc error: ' + sorted(c['gcc'] - o['gcc'])[0][:160]
    if o['c99'] != c['c99'] or o['nolang'] != c['nolang']:
        return 'verdict change: c99 %s->%s, nolang %s->%s' % (o['c99'], c['c99'], o['nolang'], c['nolang'])
    new = c['gcc'] - o['gcc']
    if new:
        return 'gcc error: ' + sorted(new)[0][:160]
    return None


# ---------------------------------------------------------------------------
# driver
# ---------------------------------------------------------------------------

SK_HDR = ['path', 'callee', 'declaration', 'reason']
RV_HDR = ['path', 'function', 'old_decl', 'new_decl', 'reason']


class Result:
    """What one file produced.  Plain data, so a worker process can return it."""

    def __init__(self):
        self.stats = collections.Counter()
        self.tagc = collections.Counter()
        self.revtag = collections.Counter()
        self.revreason = collections.Counter()
        self.revfunc = collections.Counter()
        self.skipped = []
        self.reverted = []
        self.changed = None
        self.diff = ''


def unified(fi, new):
    import difflib
    return ''.join(difflib.unified_diff(fi.raw.splitlines(True), new.splitlines(True),
                                        'a/' + fi.rel, 'b/' + fi.rel, n=1))


_DB = None


def worker_init(cache):
    global _DB
    with open(cache, 'rb') as f:
        _DB = pickle.load(f)


def process(args):
    """Worker entry: (path, options dict) -> Result.  Writes the repo file when kept."""
    path, opt = args
    global CLI_MODE
    CLI_MODE = opt.get('cli', False)
    res = Result()
    rel = os.path.relpath(path, ROOT).replace(os.sep, '/')
    try:
        _process(path, rel, opt, res)
    except Exception as e:
        res = Result()
        res.stats['file_exception'] += 1
        res.skipped.append((rel, '', '', 'exception: %r' % (e,)))
    return res


def _process(path, rel, opt, res):
    db = _DB
    fi = parse_file(path, rel)
    if fi.has_include or 'address' not in fi.h:
        res.stats['file_skipped_noheader_or_include'] += 1
        return
    stats, skipped = collections.Counter(), []
    props = proposals(fi, db, stats, skipped)
    res.stats.update(stats)
    res.stats['files_scanned'] += 1
    res.skipped += skipped
    if not props:
        return
    fn = fi.h.get('function', os.path.basename(rel)).split(',')[0].strip()
    text, dropped = build_text(fi, props)
    for p in dropped:
        res.skipped.append((rel, p.name, p.old, 'typedef defined after use point'))
        res.stats['decl_typedef_after'] += 1
    props = [p for p in props if p not in dropped]
    if not props or text == fi.raw:
        return

    def keep(ok_props, final):
        res.stats['files_changed'] += 1
        for p in ok_props:
            res.stats['decl_fixed'] += 1
            for t in p.tag:
                res.tagc[t] += 1
        res.changed = rel
        res.diff = unified(fi, final)

    if opt['no_verify']:
        keep(props, text)
        return
    tmpd = os.path.join(opt['out'], 'tmp', re.sub(r'\W', '_', rel))
    bad, ok_props, final = [], [], fi.raw
    try:
        orig = evaluate(fi, fi.raw, tmpd)
        if orig['c99'].startswith('ERR') or orig['nolang'].startswith('ERR'):
            res.stats['file_orig_unverifiable'] += 1
            res.skipped.append((rel, '', '', 'original unverifiable: %s / %s' % (orig['c99'], orig['nolang'])))
            return
        why = compare_eval(orig, evaluate(fi, text, tmpd, orig))
        if why is None:
            ok_props, final = props, text
        elif len(props) > 24:
            bad = [(p, why) for p in props]
        else:
            cur = []
            for p in props:
                t, dr = build_text(fi, cur + [p])
                if dr:
                    bad.append((p, 'typedef defined after use point'))
                    continue
                w = compare_eval(orig, evaluate(fi, t, tmpd, orig))
                if w is None:
                    cur.append(p)
                else:
                    bad.append((p, w))
            ok_props = cur
            if cur:
                final, _ = build_text(fi, cur)
    finally:
        shutil.rmtree(tmpd, ignore_errors=True)
    for p, w in bad:
        res.revreason[w.split(':')[0] if w.startswith('verdict') else w[:70]] += 1
        for t in p.tag:
            res.revtag[t] += 1
        res.revfunc[p.name] += 1
        res.stats['decl_reverted'] += 1
        res.reverted.append((rel, fn, p.old, p.new, w))
    if not ok_props:
        res.stats['files_all_reverted'] += 1
        return
    keep(ok_props, final)
    if opt['dry_run']:
        return
    with open(path, 'rb') as f:
        if f.read().decode('latin1') != fi.raw:
            res.stats['file_changed_under_us'] += 1
            res.stats['files_changed'] -= 1
            res.changed = None
            res.reverted.append((rel, fn, '', '', 'file changed on disk during run'))
            return
    bk = os.path.join(opt['out'], 'backup', rel)
    os.makedirs(os.path.dirname(bk), exist_ok=True)
    with open(bk, 'wb') as f:
        f.write(fi.raw.encode('latin1'))
    with open(path, 'wb') as f:
        f.write(final.encode('latin1'))


class Agg:
    """Main-process aggregation, CSV output, summary."""

    def __init__(self, a):
        self.out = a.out
        self.stats = collections.Counter()
        self.tagc = collections.Counter()
        self.revtag = collections.Counter()
        self.revreason = collections.Counter()
        self.revfunc = collections.Counter()
        self.t0 = time.time()
        self.n = 0
        self.done = set()
        if a.resume:
            p = os.path.join(self.out, 'changed.txt')
            if os.path.exists(p):
                self.done |= {l.strip() for l in open(p) if l.strip()}
            p = os.path.join(self.out, 'reverted.csv')
            if os.path.exists(p):
                with open(p, newline='') as f:
                    self.done |= {r[0] for r in csv.reader(f) if r and r[0] != 'path'}

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
        self.tagc.update(r.tagc)
        self.revtag.update(r.revtag)
        self.revreason.update(r.revreason)
        self.revfunc.update(r.revfunc)
        self.csv('skipped.csv', r.skipped, SK_HDR)
        self.csv('reverted.csv', r.reverted, RV_HDR)
        if r.changed and not dry:
            with open(os.path.join(self.out, 'changed.txt'), 'a') as f:
                f.write(r.changed + '\n')
        if r.diff and dry:
            sys.stdout.write(r.diff)
            sys.stdout.flush()

    def summary(self, total, final=False):
        s = self.stats
        L = ['# protofix summary', '',
             'state: %s, elapsed %.0f s, files scanned %d of %d (this invocation)' %
             ('final' if final else 'running', time.time() - self.t0, s['files_scanned'], total), '',
             '## counts (this invocation; earlier invocations are in changed.txt and reverted.csv)', '',
             '- files changed: %d' % s['files_changed'],
             '- declarations fixed: %d' % s['decl_fixed'],
             '- declarations reverted: %d' % s['decl_reverted'],
             '- files with every proposal reverted: %d' % s['files_all_reverted'],
             '- declarations already equal to the definition: %d' % s['decl_same'],
             '- declarations with no definition in src/matched: %d' % s['decl_nodef'],
             '- declarations of data or self-defined functions: %d' % (s['decl_data'] + s['decl_self']),
             '- declarations skipped, ambiguous: %d' % (s['decl_ambiguous region'] +
                                                        s['decl_ambiguous duplicate definitions']),
             '- declarations skipped, unrepresentable: %d' % s['decl_unrep'],
             '- declarations skipped, typedef after use: %d' % s['decl_typedef_after'],
             '- files skipped (include or no header): %d' % s['file_skipped_noheader_or_include'],
             '- files with unverifiable original: %d' % s['file_orig_unverifiable'],
             '- files changed under us: %d' % s['file_changed_under_us'],
             '- files with an exception: %d' % s['file_exception'], '',
             '## fixed declarations per tag (K pointer/int, W width, C count, V void/value, '
             'S sign, P pointee, U old type unresolved)', '']
        L += ['- %s: %d' % (t, self.tagc[t]) for t in 'KWCVSPU']
        L += ['', '## reverted declarations per tag', '']
        L += ['- %s: %d' % (t, self.revtag[t]) for t in 'KWCVSPU']
        L += ['', '## revert reasons (top 15)', '']
        L += ['- %d: %s' % (v, k) for k, v in self.revreason.most_common(15)]
        L += ['', '## functions with most reverts (top 25)', '']
        L += ['- %s: %d' % (k, v) for k, v in self.revfunc.most_common(25)]
        with open(os.path.join(self.out, 'summary.md'), 'w') as f:
            f.write('\n'.join(L) + '\n')


def select_files(a):
    files = all_matched()
    rel = lambda p: os.path.relpath(p, ROOT).replace(os.sep, '/')
    if a.files:
        want = {l.strip().replace('\\', '/') for l in open(a.files) if l.strip()}
        files = [p for p in files if rel(p) in want]
    if a.glob:
        files = [p for p in files if fnmatch.fnmatch(rel(p), a.glob)]
    if a.limit:
        files = files[:a.limit]
    return files


def pending_report(a, db):
    rows = []
    for dp, dn, fn in os.walk(os.path.join(ROOT, 'src', 'pending')):
        for f in fn:
            if f.endswith('.c'):
                fi = parse_file(os.path.join(dp, f))
                for pr in proposals(fi, db, collections.Counter(), []):
                    rows.append((fi.rel, pr.name, pr.old, pr.new, pr.tag))
    with open(os.path.join(a.out, 'pending.csv'), 'w', newline='') as f:
        w = csv.writer(f)
        w.writerow(['path', 'callee', 'old_decl', 'new_decl', 'tags'])
        w.writerows(rows)
    print('pending mismatches: %d' % len(rows))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--dry-run', action='store_true', help='verify but do not write')
    ap.add_argument('--no-verify', action='store_true', help='print diffs, no verification, no writes')
    ap.add_argument('--resume', action='store_true')
    ap.add_argument('--jobs', type=int, default=6)
    ap.add_argument('--glob')
    ap.add_argument('--files')
    ap.add_argument('--limit', type=int)
    ap.add_argument('--out', default=DEFAULT_OUT)
    ap.add_argument('--dump')
    ap.add_argument('--pending-report', action='store_true')
    ap.add_argument('--rebuild-db', action='store_true')
    ap.add_argument('--cli', action='store_true', help='run match.py as a subprocess')
    a = ap.parse_args()
    os.makedirs(a.out, exist_ok=True)
    cache = os.path.join(a.out, 'defs.pkl')
    if a.rebuild_db and os.path.exists(cache):
        os.remove(cache)
    db = build_db(cache, a.jobs)
    if a.dump:
        fi = parse_file(os.path.abspath(a.dump))
        print('region', fi.region, 'symbols', len(fi.h['symbols']), 'typedefs', sorted(fi.td))
        for name, mm, ret, params in fi.defs:
            rec = db['defs'].get((fi.region, int(name[-8:], 16)), [{}])[0]
            print('DEF', name, '|', re.sub(r'\s+', ' ', ret).strip(), '|', re.sub(r'\s+', ' ', params).strip(),
                  '->', rec.get('unrep') or render(name, rec['ret'], rec['params']))
        st, sk = collections.Counter(), []
        for pr in proposals(fi, db, st, sk):
            print('PROP line %d %s block=%s tag=%s\n   old: %s\n   new: %s  need=%s' %
                  (pr.line, pr.name, pr.block, pr.tag, pr.old, pr.new, sorted(pr.need)))
        print('stats', dict(st))
        for s in sk:
            print('SKIP', s)
        return
    if a.pending_report:
        pending_report(a, db)
        return
    files = select_files(a)
    agg = Agg(a)
    files = [p for p in files if os.path.relpath(p, ROOT).replace(os.sep, '/') not in agg.done]
    print('db: %d addresses; files: %d' % (len(db['defs']), len(files)), flush=True)
    opt = {'no_verify': a.no_verify, 'dry_run': a.dry_run or a.no_verify, 'out': a.out, 'cli': a.cli}
    with cf.ProcessPoolExecutor(a.jobs, initializer=worker_init, initargs=(cache,)) as ex:
        for r in ex.map(process, [(p, opt) for p in files], chunksize=1):
            agg.add(r, opt['dry_run'])
            if agg.n % 100 == 0:
                agg.summary(len(files))
                print('%d/%d  changed %d  fixed %d  reverted %d  %.0fs' %
                      (agg.n, len(files), agg.stats['files_changed'], agg.stats['decl_fixed'],
                       agg.stats['decl_reverted'], time.time() - agg.t0), flush=True)
    agg.summary(len(files), True)
    print(open(os.path.join(a.out, 'summary.md')).read())


if __name__ == '__main__':
    main()
