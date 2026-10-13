#!/usr/bin/env python3
"""globalunify.py: find the globals that different one-function files declare
with different types, and propose ONE struct per global.  Read-only on the
repository; it only writes its output directory.

Method
  1. Every src/matched/**/*.c is read (comments blanked).  Every extern
     declaration of a global data symbol is collected.  A global data symbol
     is a name g_XXXXXXXX, d_XXXXXXXX or s_XXXXXXXX, or a name that a header
     `symbols:` row marks `data`.  Block scope externs count too.
  2. A global is keyed by (region, name).  The region is the token of the
     symbols row (ovNNN) or arm9.  A view without a row takes the region of
     the other views of the same name when they agree, else the file region.
  3. A view is one of
       ptr-struct   extern struct S *g;      the pointee layout is the view
       obj-struct   extern struct S g;       the object layout is the view
       scalar       everything else (void *, u8 *, u32, u8[N], struct S **,
                    pointer to a struct with no body, ...)
     The layout of S comes from the file's own struct definitions, typedefs
     and src/matched/include/ObjNNNNN.h.  Nested structs and unions are
     flattened to leaf fields.  Fields named pad*/unk*/gap* that are byte
     arrays are gaps, not fields.  ARM rules: u8 1, u16 2, u32/int/pointer 4
     (alignment equal to size, 8 byte types aligned 4).
  4. Verdict per global
       SINGLE      one view only
       SAME        2+ views, struct views agree, no scalar view, or all views
                   are the same scalar type
       MIXED       struct views agree (or one) and scalar views also exist
                   (heuristic: the struct view wins, the rest pass the pointer)
       SCALARDIFF  only scalar views and they differ
       CONFLICT    two struct views disagree at an offset (different size, or
                   the same bytes as one field versus two), or one view is
                   obj-struct and another ptr-struct
     Views are merged in order of use count of their struct (majority first);
     a view that overlaps a merged field in a different way is a conflict.
  5. Unified struct name: the most common local struct name among the views
     (ties: not Struct_XXXXXXXX, then more fields, then alphabetical).  When
     two globals pick the same name for different layouts, the one with fewer
     views falls back to G_<addr> (G_<region>_<addr> for overlays).
  6. Function prototypes: tm_p6_final/decls.tsv rows are grouped per callee.

usage
  python tools/globalunify.py [--out DIR] [--decls decls.tsv] [--limit N]
"""
import argparse
import collections
import csv
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import protofix as pf  # noqa: E402

ROOT = pf.ROOT
SCRATCH = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'scratch')
DEFAULT_OUT = SCRATCH + '/gu'
DEFAULT_DECLS = SCRATCH + '/tm_p6_final/decls.tsv'

GLOBAL_RE = re.compile(r'^[gds]_[0-9A-Fa-f]{8}$')
TOK_RE = re.compile(r'0[xX][0-9a-fA-F]+|\d+|[A-Za-z_]\w*|<<|>>|[*\[\](){};,:=+\-/%&|~.]')
PAD_RE = re.compile(r'^(_?pad|unk|_?unk|gap|reserved|_?res|filler|_?padding)\w*$', re.I)
GENERIC_RE = re.compile(r'^(f|field_?|fld_?|x|o|off_?|unk_?|obj_|p|m_?)[0-9A-Fa-f]+$|^(pad|unk|gap)\w*$', re.I)

BUILTIN_SIZE = {
    'char': (1, 'int'), 'u8': (1, 'int'), 's8': (1, 'int'), 'bool': (1, 'int'),
    'short': (2, 'int'), 'u16': (2, 'int'), 's16': (2, 'int'),
    'int': (4, 'int'), 'long': (4, 'int'), 'u32': (4, 'int'), 's32': (4, 'int'),
    'BOOL': (4, 'int'), 'float': (4, 'float'), 'f32': (4, 'float'),
    'fx32': (4, 'int'), 'fx16': (2, 'int'), 'size_t': (4, 'int'),
    'u64': (8, 'int'), 's64': (8, 'int'), 'double': (8, 'float'), 'f64': (8, 'float'),
    'fx64': (8, 'int'), 'void': (1, 'int'),
}
QUAL = {'const', 'volatile', 'static', 'extern', 'register', 'inline', 'signed_'}


class Unresolved(Exception):
    pass


def toks(s):
    return TOK_RE.findall(s)


def eval_dim(ts):
    s = ' '.join(ts)
    if not re.fullmatch(r'[0-9a-fA-FxX\s+\-*/()<>|&%]*', s):
        raise Unresolved('dim ' + s)
    try:
        return int(eval(s.replace('/', '//'), {'__builtins__': {}}, {}))
    except Exception:
        raise Unresolved('dim ' + s)


def match_brace(m, i):
    d = 0
    n = len(m)
    while i < n:
        c = m[i]
        if c == '{':
            d += 1
        elif c == '}':
            d -= 1
            if d == 0:
                return i
        i += 1
    return -1


# ---------------------------------------------------------------------------
# scope: struct and typedef tables for one file
# ---------------------------------------------------------------------------

class Scope:
    def __init__(self):
        self.structs = {}    # tag -> (is_union, body_text) lazily parsed
        self.typedefs = {}   # name -> list of tokens (the type part, name removed) or ('struct', tag)
        self.cache = {}      # tag -> Layout | Unresolved
        self.busy = set()


class Layout:
    """leaves: list of (off, size, kind, fmt, name, elem, weak_pad); size of struct."""
    def __init__(self, size, align, leaves):
        self.size, self.align, self.leaves = size, align, leaves

    def sig(self):
        return tuple((o, s) for o, s, *_ in self.leaves)


_INC_CACHE = {}


def load_scope(raw, m):
    sc = Scope()
    for im in re.finditer(r'^[ \t]*#[ \t]*include[ \t]+"([^"]*Obj\d+\.h)"', raw, re.M):
        p = os.path.normpath(os.path.join(ROOT, 'src', 'matched', 'include', os.path.basename(im.group(1))))
        if p not in _INC_CACHE:
            try:
                r2 = open(p, 'rb').read().decode('latin1')
                s2 = Scope()
                parse_defs(pf.mask(r2), s2)
                _INC_CACHE[p] = s2
            except OSError:
                _INC_CACHE[p] = None
        s2 = _INC_CACHE[p]
        if s2:
            sc.structs.update(s2.structs)
            sc.typedefs.update(s2.typedefs)
    parse_defs(m, sc)
    return sc


def parse_defs(m, sc):
    """Fill sc.structs and sc.typedefs from masked text (file scope only)."""
    # struct/union definitions
    for sm in re.finditer(r'(typedef\s+)?\b(struct|union)\s*(\w+)?\s*\{', m):
        b0 = sm.end() - 1
        b1 = match_brace(m, b0)
        if b1 < 0:
            continue
        # depth check: only file scope (count braces before)
        if m.count('{', 0, sm.start()) != m.count('}', 0, sm.start()):
            continue
        tag = sm.group(3)
        body = m[b0 + 1:b1]
        isu = sm.group(2) == 'union'
        names = []
        if sm.group(1):
            e = m.find(';', b1)
            names = re.findall(r'[A-Za-z_]\w*', m[b1 + 1:e]) if e > 0 else []
            stars = m[b1 + 1:e].count('*') if e > 0 else 0
        if tag:
            sc.structs.setdefault(tag, (isu, body))
        if sm.group(1):
            key = tag or ('_anon_' + (names[0] if names else str(sm.start())))
            sc.structs.setdefault(key, (isu, body))
            if names and not stars:
                sc.typedefs[names[0]] = ('struct', key)
            elif names and stars:
                sc.typedefs[names[0]] = ('structptr', key)
    # simple typedefs (no braces)
    for tm in re.finditer(r'\btypedef\b([^;{}]*);', m):
        if m.count('{', 0, tm.start()) != m.count('}', 0, tm.start()):
            continue
        ts = toks(tm.group(1))
        if not ts:
            continue
        # function pointer typedef: ... ( * name ) ( ... )
        if '(' in ts:
            i = ts.index('(')
            if i + 2 < len(ts) and ts[i + 1] == '*':
                sc.typedefs[ts[i + 2]] = ['fp']
            continue
        # name is the last word before optional dims
        j = len(ts)
        while j > 0 and ts[j - 1] == ']':
            while j > 0 and ts[j - 1] != '[':
                j -= 1
            j -= 1
        if j <= 0 or not re.match(r'[A-Za-z_]', ts[j - 1]):
            continue
        name = ts[j - 1]
        base = ts[:j - 1]
        dims = ts[j:]
        if base and base[0] == 'struct' and len(base) == 2 and not dims:
            sc.typedefs.setdefault(name, ('struct', base[1]))
        elif base and base[0] == 'struct' and len(base) == 3 and base[2] == '*':
            sc.typedefs.setdefault(name, ('structptr', base[1]))
        else:
            sc.typedefs.setdefault(name, base + dims)


# ---------------------------------------------------------------------------
# type resolution
# ---------------------------------------------------------------------------

class Ty:
    """Resolved type: kind int/float/ptr/fp/struct/enum, size, align, text, tag."""
    __slots__ = ('kind', 'size', 'align', 'text', 'tag', 'sc')

    def __init__(self, kind, size, align, text, tag=None):
        self.kind, self.size, self.align, self.text, self.tag = kind, size, align, text, tag


def words_to_ty(words, sc, depth=0):
    """words: base type tokens without stars/qualifiers."""
    words = [w for w in words if w not in QUAL]
    if not words:
        raise Unresolved('empty type')
    if depth > 8:
        raise Unresolved('typedef loop')
    if words[0] in ('struct', 'union'):
        if len(words) < 2:
            raise Unresolved('anon')
        return Ty('struct', 0, 0, words[0] + ' ' + words[1], words[1])
    if words[0] == 'enum':
        return Ty('int', 4, 4, ' '.join(words))
    if len(words) == 1 and words[0] in sc.typedefs and words[0] not in BUILTIN_SIZE:
        td = sc.typedefs[words[0]]
        if isinstance(td, tuple):
            if td[0] == 'struct':
                return Ty('struct', 0, 0, words[0], td[1])
            return Ty('ptr', 4, 4, 'struct %s *' % td[1])
        if td == ['fp']:
            return Ty('fp', 4, 4, words[0])
        # alias: resolve with stars and dims
        t = resolve_tokens(td, sc, depth + 1)
        t.text = words[0]
        return t
    # builtin combos
    w = [x for x in words if x not in ('signed', 'unsigned', 'int')] or ['int']
    if len(words) == 1 and words[0] in BUILTIN_SIZE:
        sz, k = BUILTIN_SIZE[words[0]]
        return Ty(k, sz, min(sz, 4), words[0])
    uns = 'unsigned' in words
    if w == ['long', 'long']:
        return Ty('int', 8, 4, ' '.join(words))
    if w == ['long', 'double']:
        return Ty('float', 8, 4, ' '.join(words))
    if len(w) == 1 and w[0] in ('char', 'short', 'long', 'int', 'float', 'double', 'void'):
        sz, k = BUILTIN_SIZE[w[0]]
        return Ty(k, sz, min(sz, 4), ' '.join(words))
    raise Unresolved('type ' + ' '.join(words))


def resolve_tokens(ts, sc, depth=0):
    """ts: tokens of a type with stars and dims (no declarator name)."""
    ts = [t for t in ts if t not in QUAL]
    i = 0
    base = []
    while i < len(ts) and ts[i] not in ('*', '['):
        base.append(ts[i])
        i += 1
    ty = words_to_ty(base, sc, depth)
    stars = 0
    while i < len(ts) and ts[i] == '*':
        stars += 1
        i += 1
    if stars:
        ty = Ty('ptr', 4, 4, ty.text + ' ' + '*' * stars, ty.tag if ty.kind == 'struct' else None)
        ty.sc = (base, stars)
    dims = []
    while i < len(ts) and ts[i] == '[':
        j = ts.index(']', i)
        dims.append(eval_dim(ts[i + 1:j]) if j > i + 1 else 0)
        i = j + 1
    if dims:
        n = 1
        for d in dims:
            n *= d
        ty = Ty('array', ty.size * n, ty.align, ty.text, ty.tag)
        ty.sc = (dims, ty)
    return ty


# ---------------------------------------------------------------------------
# struct layout
# ---------------------------------------------------------------------------

def split_members(body):
    out, cur, d = [], [], 0
    for c in body:
        if c == '{':
            d += 1
        elif c == '}':
            d -= 1
        if c == ';' and d == 0:
            out.append(''.join(cur))
            cur = []
        else:
            cur.append(c)
    return [x for x in out if x.strip()]


def layout_of(tag, sc):
    if tag in sc.cache:
        r = sc.cache[tag]
        if isinstance(r, Unresolved):
            raise r
        return r
    if tag not in sc.structs:
        e = Unresolved('no body for ' + tag)
        sc.cache[tag] = e
        raise e
    if tag in sc.busy:
        raise Unresolved('recursive ' + tag)
    sc.busy.add(tag)
    try:
        isu, body = sc.structs[tag]
        lay = layout_body(body, isu, sc)
        sc.cache[tag] = lay
        return lay
    except Unresolved as e:
        sc.cache[tag] = e
        raise
    finally:
        sc.busy.discard(tag)


def align_up(x, a):
    return (x + a - 1) // a * a if a > 1 else x


def layout_body(body, isu, sc):
    leaves = []
    off = 0
    maxal = 1
    size = 0
    nmem = 0
    bounds = []
    for mem in split_members(body):
        mt = toks(mem)
        if not mt:
            continue
        nmem += 1
        bounds.append(len(leaves))
        # inline struct/union member
        if mt[0] in ('struct', 'union') and (len(mt) > 1 and (mt[1] == '{' or (len(mt) > 2 and mt[2] == '{'))):
            b0 = mem.index('{')
            b1 = match_brace(mem, b0)
            inner = layout_body(mem[b0 + 1:b1], mt[0] == 'union', sc)
            rest = toks(mem[b1 + 1:])
            nm = rest[0] if rest and re.match(r'[A-Za-z_]', rest[0]) else ''
            dims = []
            k = 0
            while k < len(rest):
                if rest[k] == '[':
                    j = rest.index(']', k)
                    dims.append(eval_dim(rest[k + 1:j]))
                    k = j
                k += 1
            cnt = 1
            for dd in dims:
                cnt *= dd
            o = align_up(0 if isu else off, inner.align)
            for e in range(cnt):
                for (lo, ls, lk, lf, ln, le, lp) in inner.leaves:
                    leaves.append((o + e * inner.size + lo, ls, lk, lf, (nm + '.' + ln) if nm else ln, le, lp))
            maxal = max(maxal, inner.align)
            if isu:
                size = max(size, inner.size * cnt)
            else:
                off = o + inner.size * cnt
            continue
        if '{' in mem:
            raise Unresolved('brace member')
        decls = []
        cur = []
        d = 0
        for t in mt:
            if t in '([':
                d += 1
            if t in ')]':
                d -= 1
            if t == ',' and d == 0:
                decls.append(cur)
                cur = []
            else:
                cur.append(t)
        decls.append(cur)
        first = decls[0]
        k = 0
        while k < len(first) and first[k] not in ('*', '(', '[', ':'):
            k += 1
        if k < len(first) and first[k] in ('*', '('):
            base = first[:k]
        else:
            base = first[:max(k - 1, 0)]
        base = [b for b in base if b not in QUAL]
        if not base:
            raise Unresolved('member base: ' + mem.strip())
        bty = words_to_ty(base, sc)
        nbase = k if (k < len(first) and first[k] in ('*', '(')) else max(k - 1, 0)
        for di, dt in enumerate(decls):
            if di == 0:
                dt = first[nbase:]
            stars = 0
            while dt and dt[0] == '*':
                stars += 1
                dt = dt[1:]
            fp = False
            if dt and dt[0] == '(':
                # ( * name ) ( params )
                if len(dt) >= 4 and dt[1] == '*':
                    name = dt[2]
                    fp = True
                    dt = []
                else:
                    raise Unresolved('weird member ' + mem.strip())
            else:
                if not dt or not re.match(r'[A-Za-z_]', dt[0]):
                    raise Unresolved('member name: ' + mem.strip())
                name = dt[0]
                dt = dt[1:]
            dims = []
            bits = None
            j = 0
            while j < len(dt):
                if dt[j] == '[':
                    e = dt.index(']', j)
                    dims.append(eval_dim(dt[j + 1:e]))
                    j = e
                elif dt[j] == ':':
                    bits = eval_dim(dt[j + 1:j + 2])
                    break
                j += 1
            if fp:
                ety = Ty('fp', 4, 4, 'fp')
            elif stars:
                ety = Ty('ptr', 4, 4, bty.text + ' ' + '*' * stars, bty.tag if bty.kind == 'struct' else None)
            else:
                ety = bty
            cnt = 1
            for dd in dims:
                cnt *= dd
            if ety.kind == 'struct':
                inner = layout_of(ety.tag, sc)
                esize, eal = inner.size, inner.align
            else:
                esize, eal = ety.size, ety.align
            o = align_up(0 if isu else off, eal)
            fmt = None
            if fp:
                fmt = '%s'   # replaced below with the original declarator text
                fmt = 'FP:' + ' '.join(mt)
            else:
                fmt = ety.text + ' %s' if not ety.text.endswith('*') else ety.text + '%s'
            dimtxt = ''.join('[%d]' % dd for dd in dims)
            elem = esize
            if ety.kind == 'struct':
                for e in range(max(cnt, 1)):
                    for (lo, ls, lk, lf, ln, le, lp) in inner.leaves:
                        nm = name + ('[%d]' % e if dims else '') + '.' + ln
                        leaves.append((o + e * esize + lo, ls, lk, lf, nm, le, lp))
                tot = esize * cnt
            else:
                tot = esize * cnt
                if bits is not None:
                    tot = esize
                is_pad = bool(dims) and esize == 1 and PAD_RE.match(name)
                kind = ety.kind if not dims else 'array'
                leaves.append((o, tot, kind, fmt + (dimtxt if dims else ''), name, elem, is_pad))
            maxal = max(maxal, eal)
            if isu:
                size = max(size, tot)
            else:
                off = o + tot
    if isu:
        total = size
    else:
        total = off
    total = align_up(total, maxal)
    if isu and len(bounds) > 1:
        leaves = leaves[:bounds[1]]   # keep the first alternative only
    leaves.sort(key=lambda x: (x[0], x[1]))
    return Layout(total, maxal, leaves)


# ---------------------------------------------------------------------------
# collecting views
# ---------------------------------------------------------------------------

class View:
    pass


def decl_regex(names_re):
    return re.compile(r'\bextern\b([^;(){}]*?)\b(%s)\b\s*((?:\[[^\]]*\]\s*)*)(?=[;,=])' % names_re)


EXT_RE = re.compile(r'\bextern\b([^;(){}]*);')


def scan_file(path, rel, symset_extra, views, stats):
    raw = open(path, 'rb').read().decode('latin1')
    if 'extern' not in raw:
        return
    h = pf.parse_header(raw)
    m = pf.mask(raw)
    frg = h.get('region', '?')
    syms = h['symbols']
    sc = None
    for em in EXT_RE.finditer(m):
        txt = em.group(1)
        ts = toks(txt)
        if not ts or '(' in ts:
            continue
        # split declarators
        decls, cur, d = [], [], 0
        for t in ts:
            if t in '[(':
                d += 1
            if t in '])':
                d -= 1
            if t == ',' and d == 0:
                decls.append(cur)
                cur = []
            else:
                cur.append(t)
        decls.append(cur)
        first = decls[0]
        k = 0
        while k < len(first) and first[k] not in ('*', '['):
            k += 1
        words_all = first[:k]
        if k < len(first) and first[k] == '*':
            base = words_all
        else:
            base = words_all[:-1]
        base = [b for b in base if b not in QUAL]
        for di, dt in enumerate(decls):
            if di == 0:
                dt = first[len(base):]
                dt = [x for x in dt if x not in QUAL]
            stars = 0
            while dt and dt[0] == '*':
                stars += 1
                dt = dt[1:]
            if not dt or not re.match(r'[A-Za-z_]', dt[0]):
                continue
            name = dt[0]
            row = syms.get(name)
            isdata = bool(GLOBAL_RE.match(name)) or (row is not None and row[1] == 'data')
            if not isdata:
                continue
            rest = dt[1:]
            dims = []
            j = 0
            ok = True
            while j < len(rest):
                if rest[j] == '[':
                    e = rest.index(']', j)
                    try:
                        dims.append(eval_dim(rest[j + 1:e]) if e > j + 1 else 0)
                    except Unresolved:
                        dims.append(-1)
                    j = e
                j += 1
            if sc is None:
                sc = load_scope(raw, m)
            v = View()
            v.name, v.file, v.fregion = name, rel, frg
            v.region = row[2] if row and row[2] else None
            v.rowless = row is None
            v.addr = row[0] if row else (int(name[2:], 16) if GLOBAL_RE.match(name) else 0)
            v.stars, v.dims = stars, dims
            v.base = ' '.join(base)
            v.layout = None
            v.tag = None
            v.lname = None
            v.reason = ''
            try:
                bty = words_to_ty(base, sc)
            except Unresolved as e:
                bty = None
                v.reason = str(e)
            v.cls = 'scalar'
            if bty is not None and bty.kind == 'struct':
                v.tag = bty.tag
                level = stars
                if level <= 1 and not (level == 1 and dims):
                    try:
                        v.layout = layout_of(bty.tag, sc)
                        v.cls = 'ptr' if level == 1 else 'obj'
                        v.lname = bty.tag
                    except Unresolved as e:
                        v.reason = str(e)
            v.text = ' '.join(base) + ' ' + '*' * stars + ''.join('[%d]' % x for x in dims)
            v.text = re.sub(r'\s+', ' ', v.text).strip()
            if v.cls != 'scalar':
                v.text = v.text.replace(v.tag, v.tag)
            views.append(v)


# ---------------------------------------------------------------------------
# merging
# ---------------------------------------------------------------------------

def generic(n):
    base = n.split('.')[-1]
    return bool(GENERIC_RE.match(base)) or bool(re.match(r'^(field|unk|f|x)_?[0-9A-Fa-f]+$', base, re.I))


def spec_score(kind, fmt):
    f = fmt.replace('FP:', 'fp ')
    if kind == 'fp':
        return 5
    if kind == 'ptr':
        if 'struct' in f:
            return 6
        if f.startswith('void'):
            return 3
        return 4
    if kind == 'float':
        return 3
    return 1


def sigtxt(f):
    o, s, k, fmt, n, e, p = f
    return '+0x%X size %d %s %s' % (o, s, k, n)


def merge_views(vs):
    """vs: struct views (with layouts) ordered majority-first.  Returns
    (merged fields dict off->entry, conflicts list)."""
    merged = []   # list of entries: dict(off,size,names,cands,kind)
    conflicts = []
    for v in vs:
        for f in v.layout.leaves:
            o, s, k, fmt, n, e, pad = f
            if pad:
                continue
            soft_in = (k == 'array' and generic(n))
            hit = None
            bad = None
            overl = []
            for ent in merged:
                eo, es = ent['off'], ent['size']
                if eo == o and es == s:
                    hit = ent
                    break
                if eo < o + s and o < eo + es:
                    overl.append(ent)
            if hit is not None:
                hit['cands'].append((k, fmt, n, e, v.file))
                if not soft_in:
                    hit['soft'] = False
                continue
            if overl:
                # an opaque generic array (fNN[..]) gives way to real fields
                if soft_in:
                    continue
                hard = [x for x in overl if not x.get('soft')]
                if hard:
                    conflicts.append((o, f, hard[0], v))
                    continue
                for x in overl:
                    merged.remove(x)
            merged.append({'off': o, 'size': s, 'soft': soft_in, 'cands': [(k, fmt, n, e, v.file)]})
    merged.sort(key=lambda x: x['off'])
    return merged, conflicts


def pick(ent):
    c = ent['cands']
    cnt = collections.Counter()
    best_name = None
    for k, fmt, n, e, fl in c:
        cnt[(k, fmt)] += 1
    # type: most specific, then most common
    kf = sorted(cnt.items(), key=lambda kv: (-spec_score(kv[0][0], kv[0][1]), -kv[1], kv[0][1]))
    k, fmt = kf[0][0]
    # name: non generic first, then most common
    nc = collections.Counter(n for kk, ff, n, e, fl in c if kk == k and ff == fmt)
    allnames = collections.Counter(n for kk, ff, n, e, fl in c)
    named = [(cn, n) for n, cn in allnames.items() if not generic(n)]
    if named:
        named.sort(key=lambda x: (-x[0], x[1]))
        best_name = named[0][1]
    else:
        best_name = sorted(allnames.items(), key=lambda kv: (-kv[1], kv[0]))[0][0]
    return k, fmt, best_name


def clean_name(n):
    n = n.replace('.', '_')
    n = re.sub(r'\[(\d+)\]', r'_\1', n)
    return n


def emit_struct(sname, merged, cmt=''):
    lines = ['struct %s {%s' % (sname, cmt)]
    pos = 0
    used = set()
    for ent in merged:
        o, s = ent['off'], ent['size']
        k, fmt, nm = pick(ent)
        nm = clean_name(nm)
        if o > pos:
            lines.append('    u8 pad_%X[0x%X];' % (pos, o - pos))
        base = 2
        n2 = nm
        while n2 in used:
            n2 = '%s_%X' % (nm, o)
        nm = n2
        used.add(nm)
        if fmt.startswith('FP:'):
            ft = fmt[3:]
            lines.append('    /* %s */ u32 %s;' % (ft, nm) if False else '    void (*%s)(void); /* offset 0x%X, %s */' % (nm, o, 'function pointer'))
        else:
            # array formats look like "type %s[N]"
            lines.append('    ' + (fmt % nm) + ';')
        pos = o + s
    lines.append('};')
    return '\n'.join(lines)


# ---------------------------------------------------------------------------
# main analysis
# ---------------------------------------------------------------------------

def analyze(out, decls_path, limit):
    os.makedirs(out, exist_ok=True)
    files = pf.all_matched()
    if limit:
        files = files[:limit]
    views = []
    stats = collections.Counter()
    for i, p in enumerate(files):
        rel = os.path.relpath(p, ROOT).replace(os.sep, '/')
        try:
            scan_file(p, rel, None, views, stats)
        except Exception as e:  # keep going, record
            stats['scan_errors'] += 1
            sys.stderr.write('scan error %s: %r\n' % (rel, e))
        if i % 5000 == 0:
            sys.stderr.write('%d/%d files, %d views\n' % (i, len(files), len(views)))
    # region assignment
    byname = collections.defaultdict(list)
    for v in views:
        byname[v.name].append(v)
    for name, vs in byname.items():
        known = {v.region or 'arm9' for v in vs if not v.rowless}
        for v in vs:
            if v.rowless:
                if len(known) == 1:
                    v.region = next(iter(known))
                else:
                    v.region = v.fregion if v.fregion.startswith('ov') and not known else 'arm9'
            elif not v.region:
                v.region = 'arm9'
    # dedupe views per (file, name, text)
    uniq = {}
    for v in views:
        uniq.setdefault((v.region, v.name, v.file, v.text, v.lname), v)
    views = list(uniq.values())
    groups = collections.defaultdict(list)
    for v in views:
        groups[(v.region, v.addr or v.name)].append(v)
    # alias names (lbl_, d_, s_ for one address) share one group; name = g_ form if present
    fixed = {}
    for (reg, k), vs in groups.items():
        names = collections.Counter(v.name for v in vs)
        nm = sorted(names, key=lambda n: (0 if n.startswith('g_') else 1, -names[n], n))[0]
        for v in vs:
            v.name = nm
        fixed[(reg, nm)] = vs
    groups = fixed

    results = []
    uh_lines = []
    used_names = {}   # unified name -> (layout sig, key)
    conflict_rows = []
    ordered = sorted(groups.items(), key=lambda kv: (-len(kv[1]), kv[0]))
    verdicts = collections.Counter()
    for key, vs in ordered:
        region, name = key
        nviews = len(vs)
        sviews = [v for v in vs if v.cls != 'scalar']
        scal = [v for v in vs if v.cls == 'scalar']
        # canonical distinct types
        def csig(v):
            return (v.text, v.lname, v.layout.sig() if v.layout else None,
                    tuple((l[3] if l[2] != 'array' else l[3]) for l in v.layout.leaves) if v.layout else None)
        distinct = len({csig(v) for v in vs})
        verdict = None
        merged = None
        confl = []
        note = ''
        if nviews == 1:
            verdict = 'SINGLE'
        else:
            levels = {v.cls for v in sviews}
            if sviews:
                # majority-first ordering by struct name frequency
                nc = collections.Counter(v.lname for v in sviews)
                ordv = sorted(sviews, key=lambda v: (-nc[v.lname], v.lname, v.file))
                if 'ptr' in levels and 'obj' in levels:
                    verdict = 'CONFLICT'
                    confl.append(('indirection', 'struct views mix pointer and object: ' +
                                  ', '.join(sorted({'%s %s' % (v.cls, v.lname) for v in sviews}))))
                    pv = [v for v in ordv if v.cls == ('ptr' if nc and ordv[0].cls == 'ptr' else 'obj')]
                    merged, _ = merge_views(pv)
                else:
                    merged, cf = merge_views(ordv)
                    if cf:
                        verdict = 'CONFLICT'
                        for (o, f, ent, v) in cf:
                            confl.append((o, '%s: %s (%s) vs merged +0x%X size %d (%s)' % (
                                v.file, sigtxt(f), v.lname, ent['off'], ent['size'],
                                ', '.join(sorted({c[2] for c in ent['cands']})[:3]))))
                if verdict is None:
                    if scal:
                        verdict = 'MIXED'
                        note = 'scalar views: ' + '; '.join(sorted({v.text for v in scal})[:6])
                    else:
                        verdict = 'SAME'
            else:
                verdict = 'SAME' if len({v.text for v in scal}) == 1 else 'SCALARDIFF'
        verdicts[verdict] += 1
        results.append((region, name, nviews, distinct, verdict, vs, merged, confl, note, nc if sviews else None))

    # unified struct emission (SAME and MIXED with struct views)
    emitted = []
    for (region, name, nviews, distinct, verdict, vs, merged, confl, note, nc) in results:
        if verdict not in ('SAME', 'MIXED') or not merged:
            continue
        sviews = [v for v in vs if v.cls != 'scalar']
        cls = sviews[0].cls
        if not merged:
            continue
        cands = collections.Counter(v.lname for v in sviews)
        def rank(item):
            n, c = item
            return (-c, 1 if re.match(r'^Struct_[0-9A-Fa-f]{6,8}$', n) else 0, n)
        best = sorted(cands.items(), key=rank)
        addr = name[2:] if GLOBAL_RE.match(name) else name
        gname = 'G_%s' % addr if region == 'arm9' else 'G_%s_%s' % (region, addr)
        chosen = gname
        lsig = tuple((e['off'], e['size']) for e in merged)
        for n, c in best:
            prev = used_names.get(n)
            if prev is None or prev[0] == lsig:
                chosen = n[6:] if n.startswith('_anon_') and (n[6:] not in used_names) else n
                used_names[n] = (lsig, (region, name))
                break
        emitted.append((region, name, nviews, verdict, chosen, merged, cls, best))

    # write outputs
    with open(os.path.join(out, 'globals.tsv'), 'w', newline='') as f:
        w = csv.writer(f, delimiter='\t', lineterminator='\n')
        w.writerow(['symbol', 'region', 'views', 'distinct_types', 'verdict', 'unified_struct', 'files'])
        un = {(e[0], e[1]): e[4] for e in emitted}
        for (region, name, nviews, distinct, verdict, vs, merged, confl, note, nc) in results:
            fl = sorted({os.path.basename(v.file)[:-2] for v in vs})
            w.writerow([name, region, nviews, distinct, verdict, un.get((region, name), ''),
                        ','.join(fl[:40]) + ('...(%d)' % len(fl) if len(fl) > 40 else '')])

    with open(os.path.join(out, 'unified_structs.h'), 'w', newline='') as f:
        f.write('/* Proposed unified structs, one per global whose views agree.\n'
                ' * Generated by tools/globalunify.py.  Offsets only the original code\n'
                ' * touches are named; gaps are u8 pad arrays.  Nested structs are\n'
                ' * flattened to leaf fields (names joined with _).  A global declared\n'
                ' * as ptr uses "extern struct X *g"; obj uses "extern struct X g". */\n\n')
        fwd = set()
        body = []
        for (region, name, nviews, verdict, chosen, merged, cls, best) in sorted(emitted, key=lambda e: (e[4], e[0], e[1])):
            for ent in merged:
                k, fmt, nm = pick(ent)
                for t in re.findall(r'struct (\w+)', fmt):
                    fwd.add(t)
            cm = ' /* %s %s, %d views, %s%s */' % (name, region, nviews, verdict, ', heuristic: struct view wins over scalar views' if verdict == 'MIXED' else '')
            body.append(emit_struct(chosen, merged, cm))
            body.append('extern struct %s %sg_%s%s; /* %s */\n' % (chosen, '*' if cls == 'ptr' else '', '', '', name) if False else
                        '/* extern struct %s %s%s;  (%s) */\n' % (chosen, '*' if cls == 'ptr' else '', name, 'ptr view' if cls == 'ptr' else 'object view'))
        own = {e[4] for e in emitted}
        for t in sorted(fwd - own):
            f.write('struct %s;\n' % t)
        f.write('\n')
        f.write('\n'.join(body))

    # conflicts.md
    crs = [r for r in results if r[4] == 'CONFLICT']
    crs.sort(key=lambda r: (-len(r[7]), -r[2], r[1]))
    with open(os.path.join(out, 'conflicts.md'), 'w', newline='') as f:
        f.write('# Struct view conflicts\n\n%d globals have conflicting struct views.  Worst first '
                '(by number of conflicting offsets, then views).\n\n' % len(crs))
        for (region, name, nviews, distinct, verdict, vs, merged, confl, note, nc) in crs[:150]:
            f.write('## %s (%s): %d views, %d conflicts\n\n' % (name, region, nviews, len(confl)))
            f.write('Struct names: %s\n\n' % ', '.join('%s x%d' % (k, c) for k, c in nc.most_common(8)))
            seen = set()
            for o, d in confl[:12]:
                key = (o, d)
                if key in seen:
                    continue
                seen.add(key)
                f.write('- %s: %s\n' % ('0x%X' % o if isinstance(o, int) else o, d))
            if len(confl) > 12:
                f.write('- ... %d more\n' % (len(confl) - 12))
            f.write('\n')

    # functions
    func_summary = write_funcs(out, decls_path)

    # summary
    tot = len(results)
    c = collections.Counter(r[4] for r in results)
    blocked = [r for r in results if r[3] > 1]
    same = [r for r in results if r[4] == 'SAME']
    same_blocked = [r for r in same if r[3] > 1]
    mixed = [r for r in results if r[4] == 'MIXED']
    mixed_struct = [r for r in mixed if r[6]]
    with open(os.path.join(out, 'summary.md'), 'w', newline='') as f:
        f.write('# globalunify summary\n\n')
        f.write('Files scanned: %d.  Extern views collected: %d (after per-file dedupe).  Scan errors: %d.\n\n' % (
            len(files), len(views), stats['scan_errors']))
        f.write('Global data symbols with at least one view: %d\n\n' % tot)
        f.write('| verdict | globals | views |\n|---|---|---|\n')
        for vd in ('SINGLE', 'SAME', 'MIXED', 'SCALARDIFF', 'CONFLICT'):
            f.write('| %s | %d | %d |\n' % (vd, c[vd], sum(r[2] for r in results if r[4] == vd)))
        f.write('\nSAME includes %d globals whose views are all the same scalar type (no struct).\n' % sum(
            1 for r in same if not any(v.cls != 'scalar' for v in r[5])))
        f.write('\n## Merge-blocking views\n\n')
        f.write('A global blocks a merge when its views have more than one distinct type '
                '(struct name, layout or scalar text).\n\n')
        f.write('- globals with more than one distinct type: %d, carrying %d views\n' % (
            len(blocked), sum(r[2] for r in blocked)))
        f.write('- of these, SAME (one unified struct fixes it): %d globals, %d views; '
                'after unification each keeps one declaration, so %d declarations are redundant\n' % (
                    len(same_blocked), sum(r[2] for r in same_blocked), sum(r[2] - 1 for r in same_blocked)))
        f.write('- MIXED with compatible struct views (heuristic): %d globals, %d views\n' % (
            len(mixed_struct), sum(r[2] for r in mixed_struct)))
        f.write('- SCALARDIFF (pick one scalar type, no struct needed): %d globals, %d views\n' % (
            c['SCALARDIFF'], sum(r[2] for r in results if r[4] == 'SCALARDIFF')))
        f.write('- CONFLICT (needs human or a wider struct decision): %d globals, %d views\n' % (
            c['CONFLICT'], sum(r[2] for r in results if r[4] == 'CONFLICT')))
        un_same = [e for e in emitted if e[3] == 'SAME']
        f.write('\nUnified structs emitted: %d (SAME %d, MIXED %d).  Named from a local struct: %d, '
                'fallback G_<addr>: %d.\n' % (len(emitted), len(un_same), len(emitted) - len(un_same),
                                              sum(1 for e in emitted if not e[4].startswith('G_')),
                                              sum(1 for e in emitted if e[4].startswith('G_'))))
        # view class totals
        vc = collections.Counter(v.cls for v in views)
        f.write('\nView classes: ptr-struct %d, obj-struct %d, scalar or opaque %d.\n' % (vc['ptr'], vc['obj'], vc['scalar']))
        why = collections.Counter(v.reason.split(' ')[0] + ' ' + (v.reason.split(' ')[1] if ' ' in v.reason else '')
                                  for v in views if v.reason)
        f.write('Views left scalar for a reason (top): %s\n' % '; '.join('%s x%d' % kv for kv in why.most_common(6)))
        f.write('\n## Worst blocked globals (most views)\n\n| symbol | region | views | distinct | verdict |\n|---|---|---|---|---|\n')
        for r in sorted(blocked, key=lambda r: -r[2])[:25]:
            f.write('| %s | %s | %d | %d | %s |\n' % (r[1], r[0], r[2], r[3], r[4]))
        f.write('\n' + func_summary)
    print(open(os.path.join(out, 'summary.md')).read())


def write_funcs(out, decls_path):
    if not os.path.exists(decls_path):
        return '## Functions\n\n(decls.tsv missing)\n'
    rows = list(csv.DictReader(open(decls_path, newline=''), delimiter='\t'))
    by = collections.defaultdict(list)
    for r in rows:
        if r.get('callee'):
            by[r['callee']].append(r)
    reg_cache = {}

    def region_of(p):
        if p in reg_cache:
            return reg_cache[p]
        reg = '?'
        try:
            with open(os.path.join(ROOT, p), 'rb') as f:
                head = f.read(1500).decode('latin1')
            mm = re.search(r'^\s*\*\s*region:\s*(\S+)', head, re.M)
            reg = mm.group(1) if mm else '?'
        except OSError:
            pass
        reg_cache[p] = reg
        return reg

    outrows = []
    for callee, rs in by.items():
        olds = collections.Counter(r['old'] for r in rs)
        files = sorted({r['file'] for r in rs})
        reg = region_of(rs[0]['def_file']) if rs[0].get('def_file') else '?'
        news = collections.Counter(r['new'] for r in rs)
        outrows.append((callee, reg, len(files), len(olds), news.most_common(1)[0][0], olds, files, rs))
    outrows.sort(key=lambda x: (-x[2], x[0]))
    with open(os.path.join(out, 'funcs.tsv'), 'w', newline='') as f:
        w = csv.writer(f, delimiter='\t', lineterminator='\n')
        w.writerow(['callee', 'region', 'declaring_files', 'distinct_old_decls', 'definition_decl', 'old_decls', 'classes'])
        for callee, reg, nf, no, new, olds, files, rs in outrows:
            w.writerow([callee, reg, nf, no, new, ' | '.join('%s x%d' % kv for kv in olds.most_common()),
                        ','.join(sorted({r['class'] for r in rs}))])
    cls = collections.Counter(r['class'] for r in rows)
    s = ['## Functions (from decls.tsv)\n']
    s.append('Disagreeing declarations: %d rows, %d callees; %d callees have 2 or more disagreeing '
             'declarations, %d have 2 or more distinct wrong spellings.\n' % (
                 len(rows), len(outrows), sum(1 for x in outrows if x[2] > 1), sum(1 for x in outrows if x[3] > 1)))
    s.append('By class: ' + ', '.join('%s %d' % kv for kv in cls.most_common()) + '\n')
    bareg = collections.Counter(x[1] for x in outrows)
    s.append('Callees by region (top): ' + ', '.join('%s %d' % kv for kv in bareg.most_common(8)) + '\n')
    s.append('\nWorst callees (declaring files): ' + ', '.join('%s x%d' % (x[0], x[2]) for x in outrows[:10]) + '\n')
    s.append('Full list: funcs.tsv\n')
    return '\n'.join(s)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--out', default=DEFAULT_OUT)
    ap.add_argument('--decls', default=DEFAULT_DECLS)
    ap.add_argument('--limit', type=int, default=0)
    a = ap.parse_args()
    analyze(a.out, a.decls, a.limit)


if __name__ == '__main__':
    main()
