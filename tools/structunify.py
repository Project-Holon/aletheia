#!/usr/bin/env python3
"""structunify.py: merge the per-function struct views of a src/game file into
one struct per object, retype the pointer parameters and rewrite the accesses.

The input style is the one the lane cleanup starts from:

    void f(u8 *p) { ((struct Obj02204 *)p)->fF84 = 0; }

where `struct Obj02204` is a header from src/matched/include (or a renamed copy
in a region header such as gsync_types.h) that holds only the fields one
function touched.  Accesses through a cast to a struct of the region header
(`((Work *)p)->x`) are views too, so a file can be run again.  The tool

  1. segments the file and finds every view access ((struct V *)ROOT)->path;
  2. resolves path to (offset, size, kind) with the layout of V (pycparser on
     the view header, unions and nested structs included);
  3. makes one node per (function, pointer variable) and joins nodes into
     objects: same pointer flow first (call arguments, assignments, callbacks
     with one pointer parameter; tiny-prefix callees attach only to the single
     group they touch); then by role: groups with the same parameter name and
     index and compatible layouts (no overlap with another start or size, no
     function in both, no pointer-field parent/child pair) join the host with
     the most shared members; small groups with no shared member join the best
     compatible host by the role rule alone (--no-orphans turns this off);
  4. folds an object into the existing named struct a node is typed with (a pad
     is split, a member inside a byte array becomes an anonymous union lane),
     otherwise emits a new typedef struct (largest layout, pads between fields,
     anonymous union lanes only where views overlap with another start/size);
     members of the same offset and size but another kind (u32/s32/pointer,
     u16/s16) use the majority type and the minority sites read *(T *)&p->f
     (--clash union gives an anonymous union instead); a pointer member typed
     more precisely than the view's void * is read as (void *)p->f;
  5. retypes a pointer parameter or local when every other use is safe (not
     assigned, not address-taken, not dereferenced, function address not taken):
     p->f without cast, p + K as (u8 *)p + K, p = call() as (S *)call(), prototypes
     in the file updated, casts added at call sites that pass the object to a
     differently typed parameter and where it reaches a retyped one, and
     *(T *)(p + K) turned into p->member when the struct has that member;
  6. drops Obj includes that are no longer used and deletes unreferenced view
     structs of the region header;
  7. verifies by compiling the file (match.run_tu, the gameverify rule) and
     repairs failures: functions whose bytes change are kept as views and the
     rest is rewritten again; on a compile error or no convergence each group is
     tried alone (full, then casts only) and a group that fails is rolled back;
     the groups that pass are added one at a time.  The files that include an
     edited header are verified with tools/gameverify.py at the end.

usage
  python tools/structunify.py FILE [FILE ...] [--header H] [--dry] [-v]
        [--names g0=Name,...] [--clash cast|union] [--no-orphans]
        [--orphan-max 4] [--soft 0.34] [--min-shared 3]

New structs go to --header, else to the *_types.h the file includes, else to
the .c file.  Files run one after the other (a shared header is re-read for
each).  --dry prints the groups and writes nothing.  Nothing is staged or
committed; run tools/gamesyms.py --file F --apply afterwards as the brief says.
"""
import argparse
import collections
import copy
import os
import re
import subprocess
import sys
import time

from pycparser import c_parser, c_ast, c_generator

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)

# ---------------------------------------------------------------- text utils


def mask(text):
    """Blank comments, strings, char literals and preprocessor lines; keep
    every offset and newline."""
    out = list(text)
    i, n = 0, len(text)
    while i < n:
        c = text[i]
        if c == '/' and i + 1 < n and text[i + 1] == '*':
            j = text.find('*/', i + 2)
            j = n if j < 0 else j + 2
            for k in range(i, j):
                if out[k] != '\n':
                    out[k] = ' '
            i = j
        elif c == '/' and i + 1 < n and text[i + 1] == '/':
            j = text.find('\n', i)
            j = n if j < 0 else j
            for k in range(i, j):
                out[k] = ' '
            i = j
        elif c in '"\'':
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == '\\' else 1
            for k in range(i + 1, min(j, n)):
                if out[k] != '\n':
                    out[k] = ' '
            i = j + 1
        else:
            i += 1
    lines = ''.join(out).split('\n')
    cont = False
    for k, l in enumerate(lines):
        if cont or l.lstrip().startswith('#'):
            cont = l.rstrip().endswith('\\')
            lines[k] = ' ' * len(l)
        else:
            cont = False
    return '\n'.join(lines)


def match_close(s, i, op='(', cl=')'):
    d = 0
    for k in range(i, len(s)):
        if s[k] == op:
            d += 1
        elif s[k] == cl:
            d -= 1
            if d == 0:
                return k
    return -1


def split_commas(s):
    res, d, cur = [], 0, ''
    for c in s:
        if c in '([{':
            d += 1
        elif c in ')]}':
            d -= 1
        if c == ',' and d == 0:
            res.append(cur)
            cur = ''
        else:
            cur += c
    if cur.strip():
        res.append(cur)
    return res


class Func:
    def __init__(self, name, start, lp, rp, params):
        self.name = name
        self.start = start
        self.lp, self.rp = lp, rp
        self.open = self.close = -1
        self.params = params   # [(type_text, name|None, (start, end))]


def parse_params(masked, lp, rp):
    res, pos = [], lp + 1
    for part in split_commas(masked[lp + 1:rp]):
        st, pos = pos, pos + len(part) + 1
        if part.strip() in ('', 'void'):
            continue
        m = re.match(r'^(\s*)(.*?[\s\*])(\w+)\s*(\[[^\]]*\])?\s*$', part, re.S)
        if m and '(' not in part:
            res.append((m.group(2).strip(), m.group(3), (st + len(m.group(1)), st + len(part.rstrip()))))
        else:
            res.append((part.strip(), None, (st, st + len(part))))
    return res


def head_func(masked, last, i):
    """Return a Func for the text masked[last:i] (ends before '{') or None."""
    head = masked[last:i]
    hs = head.strip()
    if not hs.endswith(')') or '=' in hs or hs.startswith(('typedef', 'struct', 'union', 'enum')) and '(' not in hs:
        return None
    rp = last + head.rindex(')')
    d, lp = 0, -1
    for q in range(rp, last - 1, -1):
        if masked[q] == ')':
            d += 1
        elif masked[q] == '(':
            d -= 1
            if d == 0:
                lp = q
                break
    mm = re.search(r'(\w+)\s*$', masked[last:lp]) if lp > 0 else None
    if not mm:
        return None
    k = last + (len(head) - len(head.lstrip()))
    return Func(mm.group(1), k, lp, rp, parse_params(masked, lp, rp))


def segment(masked):
    """Top-level function definitions and top-level ';' statements."""
    funcs, stmts = [], []
    depth, last, cur = 0, 0, None
    for i, c in enumerate(masked):
        if c == '{':
            if depth == 0:
                cur = head_func(masked, last, i)
                if cur:
                    cur.open = i
            depth += 1
        elif c == '}':
            depth -= 1
            if depth == 0:
                if cur:
                    cur.close = i
                    funcs.append(cur)
                    cur = None
                    last = i + 1
        elif c == ';' and depth == 0:
            stmts.append((last, i + 1))
            last = i + 1
    return funcs, stmts


# ------------------------------------------------------------------- layouts

SCALAR = {
    'unsigned char': ('u8', 1), 'char': ('c8', 1), 'signed char': ('s8', 1),
    'unsigned short': ('u16', 2), 'short': ('s16', 2), 'signed short': ('s16', 2),
    'unsigned int': ('u32', 4), 'int': ('s32', 4), 'signed int': ('s32', 4),
    'unsigned': ('u32', 4), 'unsigned long': ('u32', 4), 'long': ('s32', 4),
    'float': ('f32', 4), 'unsigned long long': ('u64', 8), 'long long': ('s64', 8),
    'signed long long': ('s64', 8), 'double': ('f64', 8),
}
BASE_TYPEDEFS = {
    'u8': 'unsigned char', 's8': 'signed char', 'u16': 'unsigned short', 's16': 'short',
    'u32': 'unsigned int', 's32': 'int', 'u64': 'unsigned long long', 's64': 'long long',
    'BOOL': 'int', 'vu8': 'unsigned char', 'vu16': 'unsigned short', 'vu32': 'unsigned int',
    'fx32': 'int', 'fx16': 'short', 'f32': 'float',
}
KIND_CT = {'u8': 'u8', 's8': 's8', 'c8': 'char', 'u16': 'u16', 's16': 's16', 'u32': 'u32',
           's32': 's32', 'f32': 'float', 'u64': 'u64', 's64': 's64', 'f64': 'double', 'ptr': 'void *'}
KIND_SUF = {'u8': 'b', 's8': 'c', 'c8': 'c', 'u16': 'h', 's16': 's', 'u32': 'u', 's32': 'i',
            'ptr': 'p', 'u64': 'q', 's64': 'q', 'f32': 'x', 'f64': 'x'}


PARSER = c_parser.CParser()


class Unres(Exception):
    pass


class Leaf:
    __slots__ = ('off', 'size', 'kind', 'count', 'path', 'name', 'ct', 'pad', 'line', 'esize')

    def __init__(self, off, esize, kind, count, path, name, ct, pad=False, line=0):
        self.off, self.esize, self.kind, self.count = off, esize, kind, count
        self.size = esize * count
        self.path, self.name, self.ct, self.pad, self.line = path, name, ct, pad, line

    def __repr__(self):
        return 'Leaf(%#x,%s,%s%s,%s)' % (self.off, self.kind, self.esize,
                                         '*%d' % self.count if self.count > 1 else '', self.path)


def eval_dim(d, db=None):
    if isinstance(d, c_ast.Constant):
        return int(d.value.rstrip('uUlL'), 0)
    if isinstance(d, c_ast.BinaryOp):
        a, b = eval_dim(d.left), eval_dim(d.right)
        return {'-': a - b, '+': a + b, '*': a * b, '/': a // b if b else 0, '<<': a << b}[d.op]
    raise Unres('dim')


class TypeDB:
    """struct/typedef definitions gathered from headers; layouts on demand"""

    def __init__(self):
        self.typedefs = {}
        self.structs = {}
        self.names = {}
        self.cache = {}
        self.src = {}        # name -> (origin, start, end) of the defining statement
        self.gen = c_generator.CGenerator()
        self.base = 0
        self.bases = {}

    def parse_text(self, text, origin=None):
        m = mask(text)
        funcs, stmts = segment(m)
        known = ''.join('typedef int %s;' % n + chr(10) for n in BASE_TYPEDEFS)
        known += ''.join('typedef int %s;' % n + chr(10) for n in self.typedefs if n not in BASE_TYPEDEFS)
        ok = 0
        for a, b in stmts:
            chunk = m[a:b]
            if not chunk.strip() or ('struct' not in chunk and 'union' not in chunk and 'typedef' not in chunk):
                continue
            if re.match(r'\s*(extern|static)\b', chunk) and 'typedef' not in chunk:
                continue
            try:
                ast = PARSER.parse(known + chunk)
            except Exception:
                continue
            npre = known.count(chr(10))
            base = m[:a].count(chr(10)) - npre
            for e in ast.ext:
                if e.coord and e.coord.line <= npre:
                    continue
                inner0 = e.type if hasattr(e, 'type') else None
                while isinstance(inner0, c_ast.TypeDecl):
                    inner0 = inner0.type
                if inner0 is not None:
                    self.bases[id(inner0)] = (base, inner0)
                if isinstance(e, c_ast.Typedef):
                    if e.name in BASE_TYPEDEFS:
                        continue
                    t = e.type
                    self.typedefs[e.name] = t
                    inner = t
                    while isinstance(inner, c_ast.TypeDecl):
                        inner = inner.type
                    if isinstance(inner, (c_ast.Struct, c_ast.Union)):
                        if inner.name and inner.decls:
                            self.structs[inner.name] = inner
                            self.src[inner.name] = (origin, a + len(chunk) - len(chunk.lstrip()), b)
                        if inner.decls:
                            self.names[e.name] = inner
                            self.src[e.name] = (origin, a + len(chunk) - len(chunk.lstrip()), b)
                    known += 'typedef int %s;' % e.name + chr(10)
                    ok += 1
                elif isinstance(e, c_ast.Decl) and isinstance(e.type, (c_ast.Struct, c_ast.Union)) and e.type.decls:
                    self.structs[e.type.name] = e.type
                    self.src[e.type.name] = (origin, a + len(chunk) - len(chunk.lstrip()), b)
                    ok += 1
        return ok

    def scalar_of(self, names):
        n = ' '.join(names)
        if n in SCALAR:
            return SCALAR[n]
        if n in BASE_TYPEDEFS and n not in self.typedefs:
            return SCALAR[BASE_TYPEDEFS[n]]
        return None

    def resolve(self, t):
        if isinstance(t, (c_ast.PtrDecl, c_ast.FuncDecl)):
            return ('s', 'ptr', 4)
        if isinstance(t, c_ast.ArrayDecl):
            return ('arr', t.type, eval_dim(t.dim) if t.dim else 0)
        if isinstance(t, c_ast.TypeDecl):
            return self.resolve(t.type)
        if isinstance(t, (c_ast.Struct, c_ast.Union)):
            if t.decls is None:
                t = self.structs.get(t.name)
                if t is None:
                    raise Unres('struct')
            return ('agg', t)
        if isinstance(t, c_ast.IdentifierType):
            s = self.scalar_of(t.names)
            if s:
                return ('s', s[0], s[1])
            n = ' '.join(t.names)
            if n in self.names:
                return ('agg', self.names[n])
            if n in self.typedefs:
                return self.resolve(self.typedefs[n])
            raise Unres(n)
        raise Unres(str(type(t)))

    def tsize(self, t):
        r = self.resolve(t)
        if r[0] == 's':
            return r[2], (4 if r[1] == 'ptr' else r[2])
        if r[0] == 'arr':
            s, a = self.tsize(r[1])
            return s * r[2], a
        return self.sdl(r[1])

    def sdl(self, node, base=0, path='', out=None):
        isu = isinstance(node, c_ast.Union)
        off = mx = 0
        maxa = 1
        for d in node.decls or []:
            s, a = self.tsize(d.type)
            maxa = max(maxa, a)
            if not isu:
                off = (off + a - 1) // a * a
            o = base + (0 if isu else off)
            if out is not None:
                self.member(d, o, path, out)
            if isu:
                mx = max(mx, s)
            else:
                off += s
        sz = mx if isu else off
        return (sz + maxa - 1) // maxa * maxa, maxa

    def ctext(self, d):
        dd = copy.deepcopy(d)
        t = dd.type
        while not isinstance(t, c_ast.TypeDecl):
            t = t.type
        t.declname = '@@'
        dd.name = '@@'
        return self.gen.visit(dd)

    def member(self, d, o, path, out):
        t, dims = d.type, []
        while isinstance(t, c_ast.ArrayDecl):
            dims.append(eval_dim(t.dim) if t.dim else 0)
            t = t.type
        r = self.resolve(t)
        name = d.name
        line = (self.base + d.coord.line) if d.coord else 0
        if r[0] == 's':
            if name is None:
                return
            n = 1
            for x in dims:
                n *= x
            pad = bool(name.startswith('pad') and r[1] == 'u8' and dims)
            out.append(Leaf(o, r[2], r[1], n, path + name, name, self.ctext(d), pad, line))
        elif r[0] == 'agg':
            node = r[1]
            sz, _ = self.sdl(node)
            if dims:
                if len(dims) > 1 or dims[0] > 64:
                    raise Unres('bigarr')
                for i in range(dims[0]):
                    self.sdl(node, o + i * sz, '%s%s[%d].' % (path, name, i), out)
            else:
                self.sdl(node, o, path + (name + '.' if name else ''), out)
        else:
            raise Unres('member')

    def layout(self, name):
        if name in self.cache:
            r = self.cache[name]
            if isinstance(r, Exception):
                raise r
            return r
        node = self.structs.get(name) or self.names.get(name)
        try:
            if node is None:
                raise Unres('undefined ' + name)
            out = []
            self.base = self.bases.get(id(node), (0, 0))[0]
            sz, _ = self.sdl(node, 0, '', out)
            r = (sz, out)
        except Unres as e:
            self.cache[name] = e
            raise
        self.cache[name] = r
        return r


# ------------------------------------------------------------------ analysis

CASTRE = re.compile(r'\(\s*(?:const\s+|volatile\s+)*(?:struct\s+|union\s+)?[A-Za-z_]\w*(?:\s+[A-Za-z_]\w*)*\s*\*+\s*\)\s*')
VIEWRE = re.compile(r'\(\(\s*(?:struct\s+)?([A-Za-z_]\w*)\s*\*\s*\)')
GENERIC = re.compile(r'^(?:const\s+)?(?:u8|char|void|unsigned char|signed char|s8|struct\s+\w+)\s*\*$')


def strip_root(root):
    """strip casts and outer parens; return the bare identifier or None"""
    r = root.strip()
    for _ in range(8):
        r = r.strip()
        m = CASTRE.match(r)
        if m:
            r = r[m.end():]
            continue
        if r.startswith('(') and match_close(r, 0) == len(r) - 1:
            r = r[1:-1]
            continue
        break
    return r if re.match(r'^[A-Za-z_]\w*$', r) else None


def parse_path(m, pos):
    """member path after '->' at m[pos:]; returns (path_text, end, indices)"""
    i = pos
    n = len(m)
    out = []
    idx = []
    nend = pos
    while True:
        mm = re.compile(r'\s*([A-Za-z_]\w*)').match(m, i)
        if not mm:
            break
        out.append(mm.group(1))
        i = mm.end()
        nend = i
        while i < n and m[i] == '[':
            j = match_close(m, i, '[', ']')
            if j < 0:
                break
            idx.append(m[i + 1:j].strip())
            out[-1] += '[%s]' % ('#%d' % (len(idx) - 1))
            i = j + 1
        mm = re.compile(r'\s*\.').match(m, i)
        if mm:
            i = mm.end()
            out.append('.')
            continue
        break
    # rebuild path: names joined by '.'
    parts, cur = [], ''
    for t in out:
        if t == '.':
            parts.append(cur)
            cur = ''
        else:
            cur = t
    parts.append(cur)
    return parts, i, idx, nend


class Access:
    __slots__ = ('func', 'view', 'root', 'ident', 'start', 'end', 'lstart', 'leaf', 'idx', 'parts', 'vend', 'wrapped')


class Node:
    def __init__(self, func, ident):
        self.func, self.ident = func, ident
        self.acc = []
        self.ptype = None        # declared type text
        self.pindex = None       # parameter index or None for locals
        self.kind = 'local'      # param/local/other
        self.anchor = None       # typed with an existing named struct
        self.bad = False         # an access could not be resolved
        self.weak = False

    @property
    def key(self):
        return (self.func.name, self.ident)

    def leafkeys(self):
        return {(a.leaf.off, a.leaf.kind, a.leaf.esize, a.leaf.count) for a in self.acc}


class FileInfo:
    pass


def load_view(db, name, include_dir):
    if name in db.structs or name in db.names:
        return True
    p = os.path.join(include_dir, name + '.h')
    if os.path.exists(p):
        db.parse_text(open(p, encoding='utf-8', errors='replace').read(), p)
    return name in db.structs or name in db.names


def collect(path, text, db, include_dir):
    """accesses and nodes of one file"""
    m = mask(text)
    funcs, stmts = segment(m)
    fi = FileInfo()
    fi.masked, fi.funcs, fi.stmts = m, funcs, stmts
    fi.byname = {f.name: f for f in funcs}
    fi.nodes = {}
    fi.unresolved = collections.Counter()
    fi.nacc = 0
    fi.viewnames = set()
    for f in funcs:
        body = m[f.open:f.close + 1]
        decl_types = {nm: ty for ty, nm, _ in f.params if nm}
        pidx = {nm: i for i, (ty, nm, _) in enumerate(f.params) if nm}
        for vm in VIEWRE.finditer(body):
            s = f.open + vm.start()
            cl = match_close(m, s)
            if cl < 0:
                continue
            q = cl + 1
            while m[q] in ' \t\n':
                q += 1
            if m[q:q + 2] != '->':
                continue
            view = vm.group(1)
            if view not in db.structs and view not in db.names and not os.path.exists(os.path.join(include_dir, view + '.h')):
                continue
            fi.viewnames.add(view)
            root = m[f.open + vm.end():cl]
            parts, e, idx, nend = parse_path(m, q + 2)
            a = Access()
            a.func, a.view, a.root, a.start, a.end, a.vend = f, view, root, s, nend, cl
            a.lstart = e
            a.parts, a.idx = parts, idx
            a.ident = strip_root(root)
            a.leaf = None
            fi.nacc += 1
            if not load_view(db, view, include_dir):
                fi.unresolved['view ' + view] += 1
                continue
            try:
                _, leaves = db.layout(view)
            except Unres:
                fi.unresolved['layout ' + view] += 1
                continue
            want = '.'.join(re.sub(r'\[#\d+\]', '', p) for p in parts)
            lf = [l for l in leaves if l.path == want and not l.pad]
            if not lf:
                # array-of-struct path with literal indexes
                w2 = '.'.join(p.replace('[#', '[').replace(']', ']') for p in parts)
                lf = []
            if not lf:
                fi.unresolved['path ' + view + '.' + want] += 1
                continue
            a.leaf = lf[0]
            if a.ident is None:
                fi.unresolved['rootexpr'] += 1
                continue
            key = (f.name, a.ident)
            nd = fi.nodes.get(key)
            if nd is None:
                nd = Node(f, a.ident)
                fi.nodes[key] = nd
                if a.ident in pidx:
                    nd.kind, nd.pindex, nd.ptype = 'param', pidx[a.ident], decl_types[a.ident]
                else:
                    mm = re.search(r'([A-Za-z_][\w \t]*?\*+)\s*\b%s\b\s*(?:=|;|,)' % re.escape(a.ident), body)
                    if mm:
                        nd.ptype = mm.group(1).strip()
                    else:
                        nd.kind = 'other'
            nd.acc.append(a)
    return fi


# ----------------------------------------------------------------- grouping

PTRTYPE = re.compile(r'\*\s*$')


def retypable(ptype):
    return bool(ptype and GENERIC.match(ptype.strip()))


def getnode(fi, db, f, ident):
    key = (f.name, ident)
    nd = fi.nodes.get(key)
    if nd:
        return nd
    for i, (ty, nm, _) in enumerate(f.params):
        if nm == ident:
            if not PTRTYPE.search(ty):
                return None
            nd = Node(f, ident)
            nd.kind, nd.pindex, nd.ptype = 'param', i, ty
            bare = re.sub(r'\b(const|struct)\b', '', ty).replace('*', '').strip()
            if (bare in db.names or bare in db.structs) and not retypable(ty) and bare not in fi.viewnames:
                nd.anchor = bare
            fi.nodes[key] = nd
            return nd
    return None


def call_args(m, pos):
    """arguments of the call whose '(' is at pos"""
    cl = match_close(m, pos)
    return [a.strip() for a in split_commas(m[pos + 1:cl])] if cl > 0 else []


class UF:
    def __init__(self):
        self.p = {}

    def f(self, x):
        self.p.setdefault(x, x)
        while self.p[x] != x:
            self.p[x] = self.p[self.p[x]]
            x = self.p[x]
        return x

    def u(self, a, b):
        a, b = self.f(a), self.f(b)
        if a != b:
            self.p[b] = a
        return a


def build_edges(fi, db):
    m = fi.masked
    edges = []     # (nodeA, nodeB, kind)
    cannot = set()
    for f in fi.funcs:
        # ensure nodes for all pointer params
        for ty, nm, _ in f.params:
            if nm:
                getnode(fi, db, f, nm)
        body = m[f.open:f.close + 1]
        for cm in re.finditer(r'\b([A-Za-z_]\w*)\s*\(', body):
            callee = fi.byname.get(cm.group(1))
            if not callee or callee is f and False:
                continue
            args = call_args(m, f.open + cm.end() - 1)
            for i, a in enumerate(args):
                ident = strip_root(a)
                if not ident:
                    continue
                if ident in fi.byname and ident != f.name:
                    # callback registration: link the other pointer args to the
                    # callback's single pointer parameter
                    cb = fi.byname[ident]
                    cps = [n for n in (getnode(fi, db, cb, nm) for _, nm, _ in cb.params if nm) if n and n.acc]
                    if len(cps) == 1:
                        for j, b in enumerate(args):
                            if j == i:
                                continue
                            idb = strip_root(b)
                            nb = getnode(fi, db, f, idb) if idb else None
                            if nb and nb.acc is not None and nb is not cps[0]:
                                edges.append((nb, cps[0], 'cb'))
                    continue
                na = getnode(fi, db, f, ident)
                if not na or i >= len(callee.params) or not callee.params[i][1]:
                    continue
                nb = getnode(fi, db, callee, callee.params[i][1])
                if nb and nb is not na:
                    edges.append((na, nb, 'call'))
        for am in re.finditer(r'\b([A-Za-z_]\w*)\s*=\s*([^;=]*);', body):
            lhs, rhs = am.group(1), am.group(2)
            nl = fi.nodes.get((f.name, lhs))
            if nl is None:
                continue
            r = strip_root(rhs)
            if r:
                nr = getnode(fi, db, f, r)
                if nr and nr is not nl:
                    edges.append((nl, nr, 'alias'))
            else:
                for vm in VIEWRE.finditer(rhs):
                    root = rhs[vm.end():]
                    cl = match_close(rhs, vm.start())
                    rid = strip_root(rhs[vm.end():cl]) if cl > 0 else None
                    if rid and rid != lhs:
                        nr = getnode(fi, db, f, rid)
                        if nr:
                            cannot.add(frozenset((nl.key, nr.key)))
    return edges, cannot


def classify(a, b):
    """relation of leaf key a to leaf key b: same / soft / absorb / hard / free"""
    ao, ak, ae, ac = a
    bo, bk, be, bc = b
    asz, bsz = ae * ac, be * bc
    if a == b:
        return 'same'
    if ao == bo and asz == bsz:
        return 'soft'
    if ao + asz <= bo or bo + bsz <= ao:
        return 'free'
    # a scalar inside an array of the same kind
    if bc > 1 and ac == 1 and ak == bk and ae == be and bo <= ao and ao + asz <= bo + bsz and (ao - bo) % be == 0:
        return 'absorb'
    if bo <= ao and ao + asz <= bo + bsz:
        return 'insidebytes' if (bk in ('u8', 's8', 'c8') and bc > 1) else 'inside'
    return 'hard'


def compare(keysA, keysB, limit=None, inside_ok=False):
    """leaves of B against A: (hard, soft, same)"""
    hard = soft = same = 0
    sa = sorted(keysA)
    for b in keysB:
        if limit is not None and b[0] + b[2] * b[3] > limit:
            hard += 1
            continue
        rel = set()
        for a in sa:
            if a[0] >= b[0] + b[2] * b[3]:
                break
            rel.add(classify(b, a))
        rel.discard('free')
        if 'same' in rel or 'absorb' in rel:
            same += 1
        elif 'soft' in rel and 'hard' not in rel:
            soft += 1
        elif 'insidebytes' in rel and inside_ok and 'hard' not in rel:
            pass
        elif 'inside' in rel and inside_ok and 'hard' not in rel:
            soft += 1
        elif 'soft' in rel or 'hard' in rel or 'inside' in rel or 'insidebytes' in rel:
            hard += 1
    return hard, soft, same


class Group:
    def __init__(self, nodes):
        self.nodes = list(nodes)
        self.anchor = None
        self.name = None

    def keys(self, db=None):
        ks = set()
        for n in self.nodes:
            ks |= n.leafkeys()
        if self.anchor and db is not None:
            for l in db.layout(self.anchor)[1]:
                if not l.pad:
                    ks.add((l.off, l.kind, l.esize, l.count))
        return ks

    def funcs(self):
        return {n.func.name for n in self.nodes}


def make_groups(fi, db, args):
    edges, cannot = build_edges(fi, db)
    nodes = list(fi.nodes.values())
    for n in nodes:
        n.weak = len({(a.leaf.off) for a in n.acc}) <= 2 and bool(n.acc)
    uf = UF()
    for n in nodes:
        uf.f(n.key)
    byk = {n.key: n for n in nodes}

    def cl_ok(ra, rb, members):
        ga, gb = members[ra], members[rb]
        for x in ga:
            for y in gb:
                if frozenset((x, y)) in cannot:
                    return False
        return True

    members = {n.key: {n.key} for n in nodes}
    deferred = []
    for a, b, kind in edges:
        if a.weak != b.weak and (a.acc and b.acc):
            deferred.append((a, b))
            continue
        if (a.weak and b.weak):
            deferred.append((a, b))
            continue
        ra, rb = uf.f(a.key), uf.f(b.key)
        if ra == rb or not cl_ok(ra, rb, members):
            continue
        if a.anchor and b.anchor and a.anchor != b.anchor:
            continue
        r = uf.u(ra, rb)
        o = rb if r == ra else ra
        members[r] = members[ra] | members[rb]
    # weak nodes attach to the single strong group they touch
    touch = collections.defaultdict(set)
    for a, b in deferred:
        for w, s in ((a, b), (b, a)):
            if w.weak and (not s.weak or not s.acc):
                touch[w.key].add(uf.f(s.key))
    for wk, gs in touch.items():
        if len(gs) == 1:
            g = next(iter(gs))
            rw = uf.f(wk)
            if rw != g and cl_ok(rw, g, members) and len(members[rw]) == 1:
                r = uf.u(g, rw)
                members[r] = members[g] | members[rw]
    # no-view weak-only pairs: leave
    groups = collections.defaultdict(list)
    for n in nodes:
        groups[uf.f(n.key)].append(n)
    G = []
    for r, ns in groups.items():
        g = Group(ns)
        anch = {n.anchor for n in ns if n.anchor}
        g.anchor = sorted(anch)[0] if anch else None
        G.append(g)
    return G, cannot, edges


def role_key(n):
    return (n.pindex, n.ident, (n.ptype or '').replace(' ', ''))


def role_merge(G, db, cannot, args):
    """best-fit merge of groups sharing a parameter role with compatible layouts"""
    G = list(G)
    log = []

    def usable(g):
        return any(n.acc for n in g.nodes) or g.anchor

    def limit(g):
        return db.layout(g.anchor)[0] if g.anchor else None

    def roles(g):
        r = {role_key(n) for n in g.nodes if n.kind == 'param'}
        if g.anchor:
            r |= {role_key(n)[:2] for n in g.nodes}
        return r

    changed = True
    while changed:
        changed = False
        G.sort(key=lambda g: (0 if g.anchor else 1, len(g.keys(db))))
        # small groups first: they look for the best host
        order = sorted(range(len(G)), key=lambda i: (1 if G[i].anchor else 0, len(G[i].keys(db))))
        keys = [g.keys(db) if g else None for g in G]
        for i in order:
            b = G[i]
            if b is None or not usable(b) or b.anchor:
                continue
            kb = keys[i]
            rb = {role_key(n) for n in b.nodes if n.kind == 'param'}
            if not rb:
                continue
            best = []
            for j, a in enumerate(G):
                if a is None or j == i or not usable(a):
                    continue
                ra_ = {role_key(n) for n in a.nodes if n.kind == 'param'}
                anchor_role = bool(a.anchor) and any(rk[:2] in {x[:2] for x in rb} for rk in ra_ | {(n.pindex, n.ident) for n in a.nodes if n.kind == 'param'})
                if not (ra_ & rb) and not anchor_role:
                    continue
                if a.funcs() & b.funcs():
                    continue
                if any(frozenset((x.key, y.key)) in cannot for x in a.nodes for y in b.nodes):
                    continue
                ka = keys[j]
                h1, s1, sa = compare(ka, kb, limit(a), bool(a.anchor))
                if h1:
                    continue
                h2, s2, sb = compare(kb, ka)
                if a.anchor:
                    h2 = 0
                    s2 = 0
                elif h2:
                    continue
                if a.anchor:
                    need, softmax = 1, sa
                else:
                    need = max(1, min(args.min_shared, len(kb))) if len(ka) >= 8 else args.min_shared
                    softmax = args.soft * sa
                if sa < need or (s1 + s2) > softmax:
                    continue
                if sa - s1 - s2 < 1:
                    continue
                best.append((sa - s1 - s2, j, sa, s1 + s2))
            if not best:
                continue
            best.sort(reverse=True)
            top = [x for x in best if x[0] == best[0][0]]
            if len(top) > 1:
                anchors = {G[x[1]].anchor for x in top if G[x[1]].anchor}
                if len(anchors) > 1:
                    continue
                top.sort(key=lambda x: (0 if G[x[1]].anchor else 1, -len(keys[x[1]])))
                best = top
            _, j, sa, sf = best[0]
            log.append((len(G[j].nodes), len(b.nodes), sa, sf))
            G[j].nodes += b.nodes
            G[j].anchor = G[j].anchor or b.anchor
            keys[j] = G[j].keys(db)
            G[i] = None
            keys[i] = None
            changed = True
        G = [g for g in G if g is not None]
    return G, log




# ----------------------------------------------------------------- emission

def ksize(k):
    return k[2] * k[3]


def uniq(base, taken):
    n = base
    while n in taken:
        n += '_'
    taken.add(n)
    return n


def decl_line(ct, name):
    return ct.replace('@@', name) + ';'


PADT = ['unsigned char']


def pad_line(off, n, taken):
    return '%s %s[%d];' % (PADT[0], uniq('pad%X' % off, taken), n)


def key_names(keys, ctmap, taken, prefer):
    """unique member name per key"""
    names = {}
    for k in sorted(keys, key=lambda k: (k[0], -prefer.get(k, 0), -ksize(k), k[1])):
        base = 'f%X' % k[0]
        n = base
        if n in taken:
            n = base + '_' + KIND_SUF.get(k[1], 'x')
        if n in taken and k[3] > 1:
            n = '%s_%d' % (base, k[3])
        n = uniq(n, taken)
        names[k] = n
    return names


def emit_range(items, lo, hi, taken):
    """items: [(key, name, ct)] -> list of member lines covering [lo, hi)"""
    items = sorted(items, key=lambda it: (it[0][0], -ksize(it[0]), it[0][1]))
    clusters = []
    for it in items:
        k = it[0]
        if clusters and k[0] < clusters[-1][1]:
            clusters[-1][0].append(it)
            clusters[-1][1] = max(clusters[-1][1], k[0] + ksize(k))
        else:
            clusters.append([[it], k[0] + ksize(k)])
    lines, pos = [], lo
    for members, end in clusters:
        start = members[0][0][0]
        if start > pos:
            lines.append(pad_line(pos, start - pos, taken))
        lanes = []
        for it in members:
            k = it[0]
            for ln in lanes:
                if ln[-1][0][0] + ksize(ln[-1][0]) <= k[0]:
                    ln.append(it)
                    break
            else:
                lanes.append([it])
        def lane_lines(ln, base):
            out, p = [], base
            for it in ln:
                if it[0][0] > p:
                    out.append(pad_line(p, it[0][0] - p, taken))
                out.append(decl_line(it[2], it[1]))
                p = it[0][0] + ksize(it[0])
            return out
        if len(lanes) == 1:
            lines += lane_lines(lanes[0], start)
        else:
            lines.append('union {')
            for ln in lanes:
                if len(ln) == 1 and ln[0][0][0] == start:
                    lines.append('    ' + decl_line(ln[0][2], ln[0][1]))
                else:
                    lines.append('    struct {')
                    lines += ['        ' + x for x in lane_lines(ln, start)]
                    lines.append('    };')
            lines.append('};')
        pos = end
    if hi is not None and pos < hi:
        lines.append(pad_line(pos, hi - pos, taken))
    return lines


def indent(lines, n=1):
    return [('    ' * n + l) if l else l for l in lines]


def fmt_block(lines):
    """indent nested braces"""
    out, d = [], 1
    for l in lines:
        s = l.strip()
        if s.startswith('}'):
            d -= 1
        out.append('    ' * d + s)
        if s.endswith('{'):
            d += 1
    return out


def absorb_map(keys):
    """scalar keys contained in an array key of the same kind -> (array key, index)"""
    res = {}
    arrs = [k for k in keys if k[3] > 1]
    for k in keys:
        if k[3] != 1:
            continue
        for a in arrs:
            if a[1] == k[1] and a[2] == k[2] and a[0] <= k[0] and k[0] + k[2] <= a[0] + ksize(a) and (k[0] - a[0]) % k[2] == 0:
                res[k] = (a, (k[0] - a[0]) // k[2])
                break
    return res


class Plan:
    """canonical struct of one group"""

    def __init__(self):
        self.name = None
        self.path = {}        # key -> member path text
        self.struct_text = None
        self.edits = []       # (origin, start, end, newtext) on anchor definitions
        self.unplaced = set()
        self.vcast = set()    # pointer members typed more specifically than the views
        self.alias = {}       # key -> (plain C type, member path of the primary)


KIND_PREF = ['ptr', 'u32', 's32', 'u16', 's16', 'u8', 's8', 'c8']


def ct_plain(ct):
    if '(' in ct or '[' in ct:
        return None
    return ct.replace('@@', '').strip()


def split_clashes(keys, prefer, mode):
    """same-offset same-size scalar keys of different kinds: (primary keys, {alias: primary})"""
    if mode != 'cast':
        return set(keys), {}
    by = collections.defaultdict(list)
    for k in keys:
        if k[3] == 1:
            by[(k[0], k[2])].append(k)
    alias = {}
    for _, ks in by.items():
        if len(ks) > 1:
            ks.sort(key=lambda k: (-prefer.get(k, 0), KIND_PREF.index(k[1]) if k[1] in KIND_PREF else 99))
            for k in ks[1:]:
                alias[k] = ks[0]
    return {k for k in keys if k not in alias}, alias


def plan_new(group, name, ctmap, prefer, mode='cast'):
    pl = Plan()
    pl.name = name
    keys = set()
    for n in group.nodes:
        keys |= n.leafkeys()
    prim, alias = split_clashes(keys, prefer, mode)
    ab = absorb_map(prim)
    base = [k for k in prim if k not in ab]
    taken = set()
    names = key_names(base, ctmap, taken, prefer)
    items = [(k, names[k], ctmap[k]) for k in base]
    body = emit_range(items, 0, None, taken)
    pl.struct_text = ['typedef struct %s {' % name] + fmt_block(body) + ['} %s;' % name]
    for k in base:
        pl.path[k] = names[k]
    for k, (a, i) in ab.items():
        pl.path[k] = '%s[%d]' % (names[a], i)
    for k, pk in alias.items():
        c = ct_plain(ctmap[k])
        if c is None:
            pl.unplaced.add(k)
        else:
            pl.alias[k] = (c, pl.path[pk])
    pl.keys_layout = base
    pl.full = dict(pl.path)
    return pl


def anchor_index(db, name):
    """data leaves of the anchor by key -> best member path; pads separately"""
    size, leaves = db.layout(name)
    byk = collections.defaultdict(list)
    pads = []
    for l in leaves:
        if l.pad:
            pads.append(l)
        else:
            byk[(l.off, l.kind, l.esize, l.count)].append(l)
    return byk, pads, leaves


def plan_anchor(group, db, name, ctmap, prefer, origin_text, exclude=(), mode='cast'):
    """fold the group's keys into the existing struct `name`; edits are line
    replacements on the struct's defining text (origin_text maps origin->text)"""
    pl = Plan()
    pl.name = name
    keys = set()
    for n in group.nodes:
        keys |= n.leafkeys()
    keys -= set(exclude)
    pl.unplaced |= set(exclude)
    byk, pads, leaves = anchor_index(db, name)
    src = db.src.get(name)
    taken = set()
    for l in leaves:
        taken.add(l.name)
    allnames = set(re.findall(r'\b\w+\b', origin_text[src[0]][src[1]:src[2]])) if src else set()
    taken |= allnames
    arrs = [(k, ls) for k, ls in byk.items() if k[3] > 1]
    srcname = src[0] if src else None
    otext = origin_text.get(srcname, '').split('\n') if src else []

    def line_ok(line, nm):
        if line < 1 or line > len(otext):
            return False
        s = otext[line - 1]
        s = re.sub(r'/\*.*?\*/', '', s)
        return s.count(';') == 1 and '{' not in s and '}' not in s and nm in s

    def best_leaf(k):
        return sorted(byk[k], key=lambda l: (l.path.count('.'), len(l.path)))[0]

    todo_free = []   # (key, pad leaf)
    inside = collections.defaultdict(list)   # container key -> keys
    slots = {(a[0], ksize(a)) for a in byk if a[3] == 1}
    fresh = {k for k in keys if k not in byk and not (k[3] == 1 and (k[0], ksize(k)) in slots)}
    prim, pending = split_clashes(fresh, prefer, mode)
    keys = (keys - fresh) | prim
    for k in sorted(keys):
        if k in byk:
            pl.path[k] = best_leaf(k).path
            if k[1] == 'ptr':
                cc, vc = ct_plain(best_leaf(k).ct), ct_plain(ctmap[k])
                if cc and vc and cc != vc and vc.replace(' ', '') == 'void*' and cc.replace(' ', '') != 'void*':
                    pl.vcast.add(k)
            continue
        done = False
        if k[3] == 1:
            for a, ls in arrs:
                if a[1] == k[1] and a[2] == k[2] and a[0] <= k[0] and k[0] + k[2] <= a[0] + ksize(a) and (k[0] - a[0]) % k[2] == 0:
                    best = sorted(ls, key=lambda l: (l.path.count('.'), len(l.path)))[0]
                    pl.path[k] = '%s[%d]' % (best.path, (k[0] - a[0]) // k[2])
                    done = True
                    break
        if done:
            continue
        if mode == 'cast' and k[3] == 1 and ct_plain(ctmap[k]):
            same = [a for a in byk if a[0] == k[0] and ksize(a) == ksize(k) and a[3] == 1]
            if same:
                pl.alias[k] = (ct_plain(ctmap[k]), best_leaf(same[0]).path)
                continue
        pad = [p for p in pads if p.off <= k[0] and k[0] + ksize(k) <= p.off + p.size]
        if pad:
            todo_free.append((k, pad[0]))
            continue
        cont = [a for a in byk if a[0] <= k[0] and k[0] + ksize(k) <= a[0] + ksize(a) and line_ok(best_leaf(a).line, best_leaf(a).name)]
        if cont:
            cont.sort(key=lambda a: (ksize(a), a))
            inside[cont[0]].append(k)
            continue
        pl.unplaced.add(k)
    edits = {}
    bypad = collections.defaultdict(list)
    for k, p in todo_free:
        bypad[id(p)].append((k, p))
    for _, lst in bypad.items():
        p = lst[0][1]
        ks = [k for k, _ in lst]
        if not line_ok(p.line, p.name) or p.line in edits:
            pl.unplaced |= set(ks)
            continue
        nm = key_names(ks, ctmap, taken, prefer)
        lines = emit_range([(k, nm[k], ctmap[k]) for k in ks], p.off, p.off + p.size, taken)
        edits[p.line] = (lines, ks)
        for k in ks:
            pl.path[k] = nm[k]
    for a, ks in inside.items():
        leaf = best_leaf(a)
        if leaf.line in edits:
            pl.unplaced |= set(ks)
            continue
        nm = key_names(ks, ctmap, taken, prefer)
        lines = emit_range([(k, nm[k], ctmap[k]) for k in ks], leaf.off, None, taken)
        bare = len(lines) == 1 and not re.match(r'^(u8|unsigned char) pad', lines[0]) and ks and min(k[0] for k in ks) == leaf.off
        out = ['union {', '    ' + leaf.ct.replace('@@', leaf.name) + ';']
        if bare:
            out.append('    ' + lines[0])
        else:
            out.append('    struct {')
            out += ['        ' + x for x in lines]
            out.append('    };')
        out.append('};')
        edits[leaf.line] = (out, ks)
        prefix = leaf.path.rsplit('.', 1)[0] + '.' if '.' in leaf.path else ''
        for k in ks:
            pl.path[k] = prefix + nm[k]
    for k, pk in pending.items():
        c = ct_plain(ctmap[k])
        if c is not None and pk in pl.path:
            pl.alias[k] = (c, pl.path[pk])
        elif c is not None and pk in pl.alias:
            pl.alias[k] = (c, pl.alias[pk][1])
        else:
            pl.unplaced.add(k)
    pl.line_edits = (srcname, edits)
    pl.full = {k: best_leaf(k).path for k in byk}
    pl.full.update(pl.path)
    return pl




# ------------------------------------------------------------------ rewrite

KEYWORDS = {'if', 'while', 'for', 'switch', 'return', 'sizeof', 'do', 'else', 'case'}


def enclosing_call(m, s):
    """for a token at s: (callee name or None, argument index, bare) by scanning back"""
    depth, commas, i = 0, 0, s - 1
    while i >= 0:
        c = m[i]
        if c in ')]}':
            depth += 1
        elif c in '([{':
            if depth == 0:
                if c != '(':
                    return None, 0
                mm = re.search(r'([A-Za-z_]\w*)\s*$', m[:i])
                if not mm and m[:i].rstrip().endswith((')', ']')):
                    return '?', commas
                return (mm.group(1) if mm else None), commas
            depth -= 1
        elif c == ',' and depth == 0:
            commas += 1
        elif c == ';' and depth == 0:
            return None, 0
        i -= 1
    return None, 0


def use_kind(m, s, e):
    """how the identifier token m[s:e] is used"""
    before, after = m[:s].rstrip(), m[e:].lstrip()
    if before.endswith('.') or before.endswith('->'):
        return 'skip'
    if after.startswith('->'):
        return 'skip'
    if re.match(r'=(?!=)', after):
        if not before or before[-1] in ';{})' or before.endswith(('else', 'do')):
            return 'assign'
        return 'unsafe'
    if after[:2] in ('+=', '-=', '++', '--', '|=', '&=', '^='):
        return 'unsafe'
    if before.endswith('++') or before.endswith('--'):
        return 'unsafe'
    if before.endswith('&') and not before.endswith('&&'):
        return 'unsafe'
    if CASTRE.search(before) and CASTRE.search(before).end() == len(before):
        return 'ok'
    if re.match(r'\[', after):
        return 'index'
    if re.match(r'[+\-](?![>=+\-])', after):
        return 'arith'
    if before.endswith('*'):
        pb = before[:-1].rstrip()
        if not pb or pb[-1] in '(,=;{}!&|?:<>+-*/%' or pb.endswith('return'):
            return 'unsafe'
    if re.search(r'\breturn$', before) and re.match(r'[;)]', after):
        return 'return'
    if re.search(r'\breturn$', before):
        return 'unsafe'
    if before.endswith('=') and not re.search(r'[=!<>]=$', before) and not before.endswith('=='):
        return 'rhs'
    if before.endswith(('(', ',')) and after[:1] in (',', ')'):
        callee, ai = enclosing_call(m, s)
        if callee is None or callee in KEYWORDS:
            return 'ok'
        return ('arg', callee, ai)
    return 'ok'


def ident_uses(m, f, ident):
    body_s, body_e = f.open, f.close
    for mm in re.finditer(r'(?<![\w$])%s(?![\w$])' % re.escape(ident), m[body_s:body_e + 1]):
        yield body_s + mm.start(), body_s + mm.end()


def protos(fi):
    """name -> params of every prototype and definition in the file; also fi.protospans"""
    d = {}
    fi.protospans = collections.defaultdict(list)
    for f in fi.funcs:
        d[f.name] = f.params
    m = fi.masked
    for a, b in fi.stmts:
        if b - a > 600:
            continue
        s = m[a:b]
        if '=' in s or 'typedef' in s or '(' not in s:
            continue
        lp = s.index('(')
        mm = re.search(r'(\w+)\s*$', s[:lp])
        if not mm:
            continue
        rp = match_close(s, lp)
        if rp < 0:
            continue
        ps = parse_params(s, lp, rp)
        d.setdefault(mm.group(1), ps)
        fi.protospans[mm.group(1)].append((a, ps))
    return d


def is_void_ptr(t):
    return bool(re.match(r'^(const\s+)?void\s*\*$', t.strip()))


def orphan_merge(G, db, cannot, args):
    """small groups with no shared evidence join the best compatible group of the same
    parameter role (the brief's rule: same role, no offset with two sizes or kinds)"""
    G = list(G)
    merged = 0
    order = sorted(range(len(G)), key=lambda i: len(G[i].keys(db)))
    for i in order:
        b = G[i]
        if b is None or b.anchor:
            continue
        kb = b.keys(db)
        if len(kb) > args.orphan_max or not any(n.acc for n in b.nodes):
            continue
        rb = {role_key(n)[:2] for n in b.nodes if n.kind == 'param'}
        if not rb:
            continue
        cands = []
        for j, a in enumerate(G):
            if a is None or j == i:
                continue
            ra_ = {role_key(n)[:2] for n in a.nodes if n.kind == 'param'}
            if not (ra_ & rb) or (a.funcs() & b.funcs()):
                continue
            if any(frozenset((x.key, y.key)) in cannot for x in a.nodes for y in b.nodes):
                continue
            ka = a.keys(db)
            if not a.anchor and len(ka) <= args.orphan_max:
                continue
            h1, s1, sa = compare(ka, kb, db.layout(a.anchor)[0] if a.anchor else None, bool(a.anchor))
            if h1 or s1:
                continue
            if not a.anchor:
                h2, s2, _ = compare(kb, ka)
                if h2 or s2:
                    continue
            cands.append((sa, sum(len(n.acc) for n in a.nodes), 1 if a.anchor else 0, j))
        if not cands:
            continue
        cands.sort(reverse=True)
        top = [c for c in cands if c[:2] == cands[0][:2]]
        if len({G[c[3]].anchor for c in top if G[c[3]].anchor}) > 1:
            continue
        j = cands[0][3]
        G[j].nodes += b.nodes
        G[j].anchor = G[j].anchor or b.anchor
        G[i] = None
        merged += 1
    return [g for g in G if g is not None], merged


EOL = {}
CR = chr(13) + chr(10)
LF = chr(10)


def read_text(path):
    raw = open(path, newline='', encoding='utf-8', errors='surrogateescape').read()
    EOL[os.path.abspath(path)] = CR if CR in raw else LF
    return raw.replace(CR, LF)


def write_text(path, text):
    eol = EOL.get(os.path.abspath(path), LF)
    for attempt in range(8):
        try:
            with open(path, 'w', newline='', encoding='utf-8', errors='surrogateescape') as f:
                f.write(text.replace(LF, eol))
            return
        except OSError:
            if attempt == 7:
                raise
            time.sleep(1.5)   # OneDrive or a scanner may hold the file for a moment


def camel(stem):
    return ''.join(w[:1].upper() + w[1:] for w in re.split(r'[_\W]+', stem) if w)


def fmt_at(lines, base):
    out, d = [], 0
    for l in lines:
        s = l.strip()
        if s.startswith('}'):
            d -= 1
        out.append(base + '    ' * d + s)
        if s.endswith('{'):
            d += 1
    return out


def line_starts(text):
    st = [0]
    for i, c in enumerate(text):
        if c == '\n':
            st.append(i + 1)
    return st


def type_ref(db, name):
    return name if (name in db.typedefs or name in db.names) else 'struct ' + name


class Job:
    pass


def make_job(path, args):
    job = Job()
    job.path = os.path.abspath(path)
    job.dir = os.path.dirname(job.path)
    job.text = read_text(job.path)
    job.include_dir = os.path.join(ROOT, 'src', 'matched', 'include')
    # headers in the same directory that the file includes
    job.hdrs = []
    for im in re.finditer(r'^\s*#\s*include\s+"([^"]+)"', job.text, re.M):
        p = os.path.normpath(os.path.join(job.dir, im.group(1)))
        if os.path.exists(p) and os.path.dirname(p) == os.path.normpath(job.dir):
            job.hdrs.append(p)
    job.origin = {}
    db = TypeDB()
    for h in job.hdrs:
        t = read_text(h)
        job.origin[h] = t
        db.parse_text(t, h)
    job.db = db
    job.args = args
    PADT[0] = 'u8' if any(re.search(r'typedef\s+unsigned\s+char\s+u8\s*;', job.origin[h]) for h in job.hdrs) else 'unsigned char'
    if args.header:
        job.newhdr = os.path.abspath(args.header)
        if job.newhdr not in job.origin:
            job.origin[job.newhdr] = read_text(job.newhdr) if os.path.exists(job.newhdr) else None
    else:
        tl = [h for h in job.hdrs if h.endswith('_types.h')]
        job.newhdr = tl[0] if tl else None
    return job


def analyze(job):
    args = job.args
    fi = collect(job.path, job.text, job.db, job.include_dir)
    job.fi = fi
    G, cannot, edges = make_groups(fi, job.db, args)
    # groups typed with the same existing struct are one group
    byanch = {}
    out = []
    for g in G:
        if g.anchor:
            if g.anchor in byanch:
                byanch[g.anchor].nodes += g.nodes
                continue
            byanch[g.anchor] = g
        out.append(g)
    G, log = role_merge(out, job.db, cannot, args)
    job.orphans = 0
    if args.orphans:
        G, job.orphans = orphan_merge(G, job.db, cannot, args)
    for g in G:
        for n in g.nodes:
            n.group = g
    job.groups = [g for g in G if any(n.acc for n in g.nodes)]
    job.mergelog = log
    fi.rettypes = {}
    for f in fi.funcs:
        mm = re.match(r'^((?:static\s+|inline\s+)*)(.*?)%s\s*$' % re.escape(f.name), fi.masked[f.start:f.lp])
        if mm:
            fi.rettypes[f.name] = re.sub(r'\s+', ' ', mm.group(2)).strip().replace('* *', '**')
    fi.defined = set(re.findall(r'struct\s+(\w+)\s*{', fi.masked))
    job.protos = protos(fi)
    job.addr_taken = set()
    for f in fi.funcs:
        if re.search(r'(?<![\w.>])%s\b(?!\s*\()' % re.escape(f.name), fi.masked):
            job.addr_taken.add(f.name)
    stem =camel(os.path.splitext(os.path.basename(job.path))[0])
    used = set(job.db.structs) | set(job.db.typedefs)
    names = dict(kv.split('=') for kv in (args.names or '').split(',') if '=' in kv)
    job.groups.sort(key=lambda g: -sum(len(n.acc) for n in g.nodes))
    job.plans = []
    job.ctx = {}
    counter = 1
    for i, g in enumerate(job.groups):
        ctmap, prefer = {}, collections.Counter()
        for n in g.nodes:
            for a in n.acc:
                k = (a.leaf.off, a.leaf.kind, a.leaf.esize, a.leaf.count)
                ctmap.setdefault(k, a.leaf.ct)
                prefer[k] += 1
        try:
            if g.anchor:
                pl = plan_anchor(g, job.db, g.anchor, ctmap, prefer, job.origin, (), args.clash)
                pl.ref = type_ref(job.db, g.anchor)
                pl.is_new = False
                job.ctx[i] = (ctmap, prefer)
                pl.rebuild = lambda ex, g=g, ctmap=ctmap, prefer=prefer: plan_anchor(g, job.db, g.anchor, ctmap, prefer, job.origin, ex, args.clash)
            else:
                nm = names.get('g%d' % i)
                if not nm:
                    while '%sObj%d' % (stem, counter) in used:
                        counter += 1
                    nm = '%sObj%d' % (stem, counter)
                    used.add(nm)
                pl = plan_new(g, nm, ctmap, prefer, args.clash)
                pl.ref = nm
                pl.is_new = True
        except Unres:
            pl = None
        g.plan = pl
        job.plans.append(pl)
    return job


RAWPRE = re.compile(r'\*\s*\(\s*((?:const\s+)?[A-Za-z_][\w\s]*?)\s*\*\s*\)\s*\(\s*(?:\(\s*(?:u8|char|unsigned char|void|s8)\s*\*\s*\)\s*)?$')
RAWPOST = re.compile(r'\s*\+\s*(0[xX][0-9a-fA-F]+|\d+)\s*\)')


def raw_field(job, n, s, e, pl):
    """*(T *)(p + K) where the struct has a member of that type at K -> p->member"""
    m = job.fi.masked
    pm = RAWPRE.search(m[:s])
    qm = RAWPOST.match(m, e)
    if not pm or not qm:
        return None
    sc = job.db.scalar_of(pm.group(1).strip().split())
    if not sc:
        return None
    key = (int(qm.group(1), 0), sc[0], sc[1], 1)
    path = pl.full.get(key)
    if path is None:
        return None
    return (pm.start(), qm.end(), '%s->%s' % (n.ident, path))


def retype_check(job, n, pl=None):
    """cast edits and call-argument uses for retyping node n, or None if unsafe"""
    f, m = n.func, job.fi.masked
    spans = [(a.start, a.vend + 1) for a in n.acc]
    simple, argu = [], []
    nraw = 0
    ptype = n.ptype.strip()
    for s, e in ident_uses(m, f, n.ident):
        if any(x <= s < y for x, y in spans):
            continue
        if n.kind == 'param':
            if f.params[n.pindex][2][0] <= s < f.params[n.pindex][2][1]:
                continue
        rw = raw_field(job, n, s, e, pl) if pl is not None and getattr(pl, 'full', None) else None
        if rw:
            simple.append(rw)
            nraw += 1
            continue
        k = use_kind(m, s, e)
        if k == 'unsafe':
            return None
        if k in ('skip', 'ok'):
            continue
        if k == 'assign':
            q0 = e
            while m[q0] in ' \t\n':
                q0 += 1
            r0 = q0 + 1
            while m[r0] in ' \t\n':
                r0 += 1
            d, r1 = 0, r0
            while r1 < len(m):
                c = m[r1]
                if c in '([{':
                    d += 1
                elif c in ')]}':
                    if d == 0:
                        break
                    d -= 1
                elif c in ';,' and d == 0:
                    break
                r1 += 1
            rhs = m[r0:r1].rstrip()
            simple_call = re.match(r'^[A-Za-z_]\w*\s*\(', rhs) and match_close(rhs, rhs.index('(')) == len(rhs) - 1
            if simple_call or re.match(r'^[A-Za-z_]\w*$', rhs):
                simple.append((r0, r0, '@@REF@@ '))
            else:
                simple.append((r0, r0, '@@REF@@ ('))
                simple.append((r0 + len(rhs), r0 + len(rhs), ')'))
            continue
        if k == 'return':
            rt = job.fi.rettypes.get(f.name)
            if not rt or not rt.endswith('*'):
                return None
            simple.append((s, e, '(%s)%s' % (rt, n.ident)))
            continue
        if k == 'index':
            simple.append((s, e, '((%s)%s)' % (ptype, n.ident)))
        elif k in ('arith', 'rhs'):
            simple.append((s, e, '(%s)%s' % (ptype, n.ident)))
        else:
            argu.append((s, e, k[1], k[2]))
    return simple, argu, nraw


def opaque(job, ptype):
    """a `struct X *` parameter may be retyped only if struct X has no definition"""
    mm = re.match(r'^(?:const\s+)?struct\s+(\w+)', ptype.strip())
    return not mm or (mm.group(1) not in job.db.structs and mm.group(1) not in job.fi.defined)


def local_decl_span(job, n):
    f, m = n.func, job.fi.masked
    body = m[f.open:f.close + 1]
    t = re.escape(n.ptype.split('*')[0].strip())
    mm = re.search(r'(?<![\w])%s\s*\*\s*%s\b(?=\s*[=;])' % (t, re.escape(n.ident)), body)
    if not mm:
        return None
    return f.open + mm.start(), f.open + mm.end()


def text_of(job, s, e):
    return job.text[s:e].strip()


def call_arg_spans(m, pos):
    """(start, end) of each argument of the call whose '(' is at pos"""
    cl = match_close(m, pos)
    if cl < 0:
        return []
    res, d, st = [], 0, pos + 1
    for i in range(pos + 1, cl + 1):
        c = m[i]
        if c in '([{':
            d += 1
        elif c in ')]}':
            d -= 1
        if (c == ',' and d == 0) or i == cl:
            seg = m[st:i]
            if seg.strip():
                a = st + len(seg) - len(seg.lstrip())
                res.append((a, a + len(seg.strip())))
            st = i + 1
    return res


def build(job, modes, skip=frozenset()):
    """-> (c_text, {header: text}, stats) for the given {group index: mode}"""
    fi, db = job.fi, job.db
    m = fi.masked
    ced = []
    hed = collections.defaultdict(list)
    st = collections.Counter()
    new_structs = []
    active = {gi: md for gi, md in modes.items() if md > 0 and job.plans[gi]}
    retyped = {}
    for gi, md in active.items():
        if md != 2:
            continue
        g = job.groups[gi]
        for n in g.nodes:
            if n.func.name in skip:
                continue
            if not retypable(n.ptype) or not opaque(job, n.ptype) or n.kind not in ('param', 'local') or n.bad or n.anchor or n.func.name in job.addr_taken:
                continue
            if n.kind == 'local' and not local_decl_span(job, n):
                continue
            r = retype_check(job, n, job.plans[gi])
            if r is not None:
                retyped[n.key] = (gi, r)
    usedlines = collections.defaultdict(set)
    for gi, md in active.items():
        g, pl = job.groups[gi], job.plans[gi]
        if pl.is_new:
            new_structs.append(pl.struct_text)
        else:
            origin, edits = pl.line_edits
            for line, (lines, ks) in edits.items():
                otext = job.origin[origin]
                ls = line_starts(otext)
                s0 = ls[line - 1]
                e0 = ls[line] - 1 if line < len(ls) else len(otext)
                if otext[e0 - 1:e0] == '\r':
                    e0 -= 1
                ind = re.match(r'\s*', otext[s0:e0]).group(0)
                hed[origin].append((s0, e0, '\n'.join(fmt_at(lines, ind))))
        for n in g.nodes:
            if n.func.name in skip:
                continue
            rt = n.key in retyped
            for a in n.acc:
                key = (a.leaf.off, a.leaf.kind, a.leaf.esize, a.leaf.count)
                if key not in pl.path and key not in pl.alias:
                    st['left'] += 1
                    continue
                if key in pl.alias:
                    cty, ppath = pl.alias[key]
                else:
                    cty, ppath = None, pl.path[key]
                if rt:
                    base = a.ident
                    st['uncast'] += 1
                else:
                    base = '((%s *)%s)' % (pl.ref, a.root)
                target = '%s->%s' % (base, ppath)
                start = a.start
                if cty is None and key in pl.vcast:
                    post = job.text[a.end:a.end + 12]
                    q = a.start - 1
                    while q >= 0 and job.text[q] in ' ' + chr(9):
                        q -= 1
                    lval = re.match(r'^s*(=(?!=)|[+]{2}|--|[-+*/|&^]=|<<=|>>=)'.replace('s*', chr(92) + 's*'), post)
                    if q >= 1 and job.text[q] == '&' and job.text[q - 1] != '&':
                        start = q
                        new = '(void **)&' + target
                    elif lval or job.text[max(0, a.start - 2):a.start] in ('++', '--'):
                        new = '(*(void **)&%s)' % target
                    else:
                        new = '(void *)' + target
                    st['vcast'] += 1
                elif cty is None:
                    new = target
                else:
                    q = a.start - 1
                    while q >= 0 and job.text[q] in ' 	':
                        q -= 1
                    if q >= 1 and job.text[q] == '&' and job.text[q - 1] != '&':
                        pre = job.text[:q].rstrip()
                        cm = CASTRE.search(pre)
                        start = q
                        if cm and cm.end() == len(pre):
                            new = '&' + target
                        else:
                            new = '(%s *)&%s' % (cty, target)
                        st['alias'] += 1
                    else:
                        new = '(*(%s *)&%s)' % (cty, target)
                        st['alias'] += 1
                ced.append((start, a.end, new))
                st['acc'] += 1
            if rt:
                gi2, (simple, argu, nraw) = retyped[n.key]
                st['raw'] += nraw
                ced += [(x, y, z.replace('@@REF@@', '(%s *)' % pl.ref)) for x, y, z in simple]
                f = n.func
                if n.kind == 'param':
                    s0, e0 = f.params[n.pindex][2]
                    ced.append((s0, e0, '%s *%s' % (pl.ref, n.ident)))
                    # prototypes
                    for a0, ps in fi.protospans.get(f.name, ()):
                        if n.pindex < len(ps):
                            ty, nm_, (x, y) = ps[n.pindex]
                            ced.append((a0 + x, a0 + y, '%s *%s' % (pl.ref, nm_ or '')))
                else:
                    sp = local_decl_span(job, n)
                    ced.append((sp[0], sp[1], '%s *%s' % (pl.ref, n.ident)))
                for s, e, callee, ai in argu:
                    w = wrap_for(job, n, pl, callee, ai, retyped)
                    if w:
                        ced.append((s, e, '%s%s' % (w, n.ident)))
                        st['wraps'] += 1
                st['retyped'] += 1
    # arguments that reach a retyped parameter must have its type
    dest = {}
    for key, (gi, _r) in retyped.items():
        n = None
        for nn in job.groups[gi].nodes:
            if nn.key == key:
                n = nn
        if n is not None and n.kind == 'param':
            dest.setdefault(n.func.name, {})[n.pindex] = job.plans[gi].ref
    if dest:
        for f in fi.funcs:
            body = m[f.open:f.close + 1]
            for cm in re.finditer(r'\b([A-Za-z_]\w*)\s*\(', body):
                if cm.group(1) not in dest:
                    continue
                spans = call_arg_spans(m, f.open + cm.end() - 1)
                for ai, ref in dest[cm.group(1)].items():
                    if ai >= len(spans):
                        continue
                    s0, e0 = spans[ai]
                    arg = m[s0:e0]
                    ident = strip_root(arg)
                    if re.match(r'^(0|NULL|\(void \*\)0)$', arg.strip()):
                        continue
                    refname = ref.replace('struct ', '')
                    have = None
                    if ident and (f.name, ident) in retyped:
                        have = job.plans[retyped[(f.name, ident)][0]].ref
                    elif ident:
                        nn = fi.nodes.get((f.name, ident))
                        if nn is not None and nn.anchor:
                            have = type_ref(db, nn.anchor)
                    c0 = CASTRE.match(arg)
                    rest = arg[c0.end():].strip() if c0 else ''
                    if c0 and re.match(r'^[A-Za-z_]\w*$', rest):
                        castty = arg[:c0.end()]
                        if re.search(r'\b%s\b' % re.escape(refname), castty) or is_void_ptr(castty.strip()[1:-1]):
                            continue
                        if have == ref:
                            ced.append((s0, s0 + c0.end(), ''))
                            st['castsdropped'] += 1
                            continue
                        ced.append((s0, s0 + c0.end(), '(%s *)' % ref))
                    elif c0:
                        castty = arg[:c0.end()]
                        if re.search(r'\b%s\b' % re.escape(refname), castty) or is_void_ptr(castty.strip()[1:-1]):
                            continue
                        ced.append((s0, s0, '(%s *)(' % ref))
                        ced.append((e0, e0, ')'))
                    elif have == ref:
                        continue
                    elif ident:
                        ced.append((s0, s0, '(%s *)' % ref))
                    else:
                        ced.append((s0, s0, '(%s *)(' % ref))
                        ced.append((e0, e0, ')'))
                    st['argcasts'] += 1
    text = apply_edits(job.text, ced)
    hdrs = {}
    # headers: new structs and anchor edits
    if new_structs:
        block = '\n'.join('\n'.join(s) + '\n' for s in new_structs)
        if job.newhdr:
            ot = job.origin[job.newhdr] or ''
            if job.newhdr in hed or True:
                pos = ot.rfind('#endif')
                pos = len(ot) if pos < 0 else pos
                hed[job.newhdr].append((pos, pos, block + '\n'))
            if job.newhdr not in job.hdrs:
                inc = '#include "%s"\n' % os.path.basename(job.newhdr)
                li = [x.end() for x in re.finditer(r'^\s*#\s*include[^\n]*\n', text, re.M)]
                p2 = li[-1] if li else 0
                text = text[:p2] + inc + text[p2:]
        else:
            li = [x.end() for x in re.finditer(r'^\s*#\s*include[^\n]*\n', text, re.M)]
            p2 = li[-1] if li else 0
            text = text[:p2] + '\n' + block + text[p2:]
    return text, hed, st


def wrap_for(job, n, pl, callee, ai, retyped):
    fi = job.fi
    cf = fi.byname.get(callee)
    if cf and ai < len(cf.params) and cf.params[ai][1]:
        ck = (cf.name, cf.params[ai][1])
        if ck in retyped:
            return None if job.plans[retyped[ck][0]].ref == pl.ref else '(void *)'
    ps = job.protos.get(callee)
    if ps and ai < len(ps):
        T = ps[ai][0].strip()
        if is_void_ptr(T):
            return None
        bare = re.sub(r'\b(const|struct)\b', '', T).replace('*', '').strip()
        if T.endswith('*') and bare in (pl.ref, pl.ref.replace('struct ', '')):
            return None
        if GENERIC.match(T):
            return '(%s)' % T
        if T.endswith('*'):
            return '(void *)'
    return '(%s)' % n.ptype.strip()


def apply_edits(text, edits):
    edits = sorted(edits, key=lambda e: (e[0], e[1]))
    ok, prev = [], -1
    for e in edits:
        if e[0] < prev:
            continue
        ok.append(e)
        prev = e[1]
    for s, e, new in reversed(ok):
        text = text[:s] + new + text[e:]
    return text




def finalize(job, text, hed):
    """drop unused Obj includes, prune unreferenced region view structs, apply header edits"""
    m = mask(text)
    removed = 0
    for im in list(re.finditer(r'^[ \t]*#\s*include\s+"[^"]*/(Obj\w+)\.h"[^\n]*\n', text, re.M))[::-1]:
        nm = im.group(1)
        if not re.search(r'\b%s\b' % nm, m):
            text = text[:im.start()] + text[im.end():]
            removed += 1
    pruned = 0
    others = ''
    for f in os.listdir(job.dir):
        if f.endswith('.c') and os.path.abspath(os.path.join(job.dir, f)) != job.path:
            others += mask(open(os.path.join(job.dir, f), errors='replace').read())
    m = mask(text)
    for h in job.hdrs:
        ht = job.origin[h]
        hm = mask(ht)
        for v in sorted(job.fi.viewnames):
            src = job.db.src.get(v)
            if v not in job.db.structs or not src or src[0] != h:
                continue
            a, b = src[1], src[2]
            rest = hm[:a] + ' ' * (b - a) + hm[b:]
            pat = r'\b%s\b' % v
            if not (re.search(pat, m) or re.search(pat, others) or re.search(pat, rest)):
                hed[h].append((a, b, ''))
                pruned += 1
    hdrs = {h: apply_edits(job.origin[h] or '', es) for h, es in hed.items()}
    if pruned:
        for h in hdrs:
            hdrs[h] = re.sub(LF + '{4,}', LF * 3, hdrs[h])
    return text, hdrs, removed, pruned


# ------------------------------------------------------------ check + verify

def resolve_path(db, name, path):
    """offset, kind, esize of member `path` (may end in [k]) of struct `name`"""
    mm = re.match(r'^(.*?)(?:\[(\d+)\])?$', path)
    base, k = mm.group(1), mm.group(2)
    for l in db.layout(name)[1]:
        if l.path == base and not l.pad:
            if k is not None:
                return l.off + int(k) * l.esize, l.kind, l.esize, 1
            return l.off, l.kind, l.esize, l.count
    return None


def check_plan(job, gi):
    """re-parse the emitted/edited struct and confirm every key lands where intended"""
    pl = job.plans[gi]
    db2 = TypeDB()
    try:
        if pl.is_new:
            for h in job.hdrs:
                db2.parse_text(job.origin[h], h)
            db2.parse_text(chr(10).join(pl.struct_text))
            name = pl.name
        else:
            origin, edits = pl.line_edits
            for h in job.hdrs:
                t = job.origin[h]
                if h == origin:
                    es = []
                    ls = line_starts(t)
                    for line, (lines, ks) in edits.items():
                        s0 = ls[line - 1]
                        e0 = ls[line] - 1 if line < len(ls) else len(t)
                        es.append((s0, e0, '\n'.join(lines)))
                    t = apply_edits(t, es)
                db2.parse_text(t, h)
            name = job.groups[gi].anchor
        bad = set()
        for key, path in pl.path.items():
            r = resolve_path(db2, name, path)
            if r is None or r[0] != key[0] or r[1] != key[1] or r[2] != key[2]:
                bad.add(key)
        if bad:
            return bad
    except Unres as e:
        return 'unresolved ' + str(e)
    return None


LAST_OUT = ''


def run_verify(files):
    cmd = [sys.executable, os.path.join(HERE, 'gameverify.py')]
    for f in files:
        cmd += ['--file', f]
    r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    global LAST_OUT
    LAST_OUT = r.stdout + r.stderr
    mm = re.search(r'files: (\d+), not exact: (\d+), MATCH \(relocations wildcarded\): (\d+)', r.stdout)
    if not mm:
        return None
    return tuple(int(x) for x in mm.groups())


def write_state(job, modes, skip=frozenset()):
    text, hed, st = build(job, modes, skip)
    text, hdrs, removed, pruned = finalize(job, text, hed)
    st['includes'] = removed
    st['pruned'] = pruned
    write_text(job.path, text)
    for h, t in hdrs.items():
        write_text(h, t)
    for h in job.origin:
        if h not in hdrs and job.origin[h] is not None and os.path.exists(h):
            pass
    job.touched = set(hdrs)
    return st


def restore(job):
    write_text(job.path, job.text)
    for h, t in job.origin.items():
        if t is not None:
            write_text(h, t)
        elif os.path.exists(h):
            os.remove(h)


def includers(job):
    """files to verify: the file, plus every .c of its directory that includes a header we may edit"""
    res = [job.path]
    names = {os.path.basename(h) for h in job.origin}
    for f in sorted(os.listdir(job.dir)):
        fp = os.path.join(job.dir, f)
        if f.endswith('.c') and os.path.abspath(fp) != job.path:
            t = open(fp, errors='replace').read()
            if any(re.search(r'#\s*include\s+"%s"' % re.escape(n), t) for n in names):
                res.append(os.path.abspath(fp))
    return res


def verify_inproc(path, defined=None):
    """compile the file as gameverify does; -> (ok, differing function names or None, note)"""
    sys.path.insert(0, HERE)
    import match
    import gameverify as gv
    import protofix as pf
    raw = open(path, encoding='latin1').read()
    h, st = gv.settings_of(raw)
    addr = int(h.get('address', '0'), 16)
    region = (h.get('region') or '').strip()
    flags = st['flags'].split() if st['flags'] else ['-O4,p']
    thumb = st['isa'] == 'thumb'
    langs = [st['lang'] or None]
    res, diffs, note = {}, None, ''
    for lang in langs:
        try:
            r, _tl = match.run_tu(path, addr, st['compiler'], flags, thumb, lang, region=region)
        except (Exception, SystemExit) as e:
            res[lang or 'nolang'] = 'ERROR'
            note = repr(e)[:100]
            continue
        res[lang or 'nolang'] = r.status
        if r.status == 'CCERR':
            note = (r.note or '')[:160]
        if r.status == 'DIFF' and diffs is None and (lang or 'nolang') == (st['lang'] or 'nolang'):
            diffs = r.diffs
    key = st['lang'] or 'nolang'
    ok = res.get(key, '').startswith(('EXACT', 'MATCH'))
    names = None
    if diffs:
        fnames = [(int(m2.group(1), 16), m2.group(0)) for m2 in re.finditer(r'\b(?:\w*_)?(?:func|sub)_([0-9A-F]{8})\b', raw)]
        starts = sorted(defined) if defined else sorted({a for a, _ in fnames if a >= addr})
        names = set()
        for off in diffs[:400]:
            a = addr + off
            cand = [s for s in starts if s <= a]
            if cand:
                names.add(cand[-1])
    return ok, names, '%s %s' % (res, note)


def process(path, args):
    job = analyze(make_job(path, args))
    fi = job.fi
    n_views = len(fi.viewnames)
    n_acc = fi.nacc
    cand = []
    for gi, g in enumerate(job.groups):
        pl = job.plans[gi]
        if pl is None:
            continue
        err = check_plan(job, gi)
        for _ in range(3):
            if isinstance(err, set) and not pl.is_new:
                pl = job.plans[gi] = pl.rebuild(pl.unplaced | err)
                pl.ref = type_ref(job.db, job.groups[gi].anchor)
                pl.is_new = False
                pl.rebuild = lambda ex, g=g, gi=gi: plan_anchor(g, job.db, g.anchor, *job.ctx[gi], job.origin, ex, args.clash)
                err = check_plan(job, gi)
            else:
                break
        if err:
            if args.v:
                print('  group %d plan rejected: %s' % (gi, err if isinstance(err, str) else sorted(err)[:4]))
            job.plans[gi] = None
            continue
        cand.append(gi)
    print('%s: %d accesses, %d view structs, %d nodes, %d groups (%d plannable)'
          % (os.path.relpath(path, ROOT), n_acc, n_views, len(fi.nodes), len(job.groups), len(cand)))
    if fi.unresolved:
        print('  unresolved: %s' % dict(fi.unresolved.most_common(6)))
    if args.v or args.dry:
        for gi in cand:
            g, pl = job.groups[gi], job.plans[gi]
            print('  g%d %s %s: %d nodes, %d accesses, %d members, %d unplaced, funcs %s'
                  % (gi, pl.ref, 'new' if pl.is_new else 'anchor', len(g.nodes), sum(len(n.acc) for n in g.nodes),
                     len(pl.path), len(pl.unplaced), sorted(g.funcs())[:3]))
    if args.dry:
        return job
    files = includers(job)
    base = run_verify(files)
    if base is None:
        print('  baseline verify failed, skipping')
        return job
    base_bad = base[1] + base[2]
    fa = {}
    for f in fi.funcs:
        mm = re.search(r'([0-9A-F]{8})$', f.name)
        if mm:
            fa[int(mm.group(1), 16)] = f.name

    def attempt(modes, skip):
        st = write_state(job, modes, skip)
        ok, diff, note = verify_inproc(job.path, set(fa))
        if args.v:
            print('    try %s skip %d -> %s %s' % (sorted(modes.items()), len(skip), 'ok' if ok else 'FAIL', '' if ok else note[:150]))
        return ok, diff, st

    def settle(modes, skip):
        """write the state; on DIFF demote the differing functions and retry"""
        skip = set(skip)
        for _ in range(8):
            ok, diff, st = attempt(modes, skip)
            if ok:
                return True, skip, st
            names = {fa[a] for a in (diff or ()) if a in fa}
            if not names or names <= skip:
                return False, skip, st
            skip |= names
        return False, skip, st

    modes = {gi: 2 for gi in cand}
    skip = set()
    ok, skip, st = settle(modes, skip) if cand else (True, set(), collections.Counter())
    rolled = []
    if not ok:
        good = {}
        for gi in cand:
            for md in (2, 1):
                o, sk, _ = settle({gi: md}, set())
                if o:
                    good[gi] = (md, sk)
                    break
            else:
                rolled.append(gi)
        modes, skip = {}, set()
        for gi, (md, sk) in good.items():
            o, sk2, _ = settle({**modes, gi: md}, skip | sk)
            if o:
                modes[gi] = md
                skip = sk2
            else:
                rolled.append(gi)
        ok, skip, st = settle(modes, skip) if modes else (True, set(), collections.Counter())
        if not modes:
            restore(job)
    final = open(path, errors='replace').read()
    after = len(set(re.findall(r'struct\s+(Obj\w+|\w*Obj\d+)\s*\*', mask(final))))
    full = sum(1 for md in modes.values() if md == 2)
    part = sum(1 for md in modes.values() if md == 1)
    print('  views %d -> %d; accesses rewritten %d (casts dropped %d, left %d); params/locals retyped %d; raw offsets to fields %d; '
          'call casts %d; groups %d full, %d casts-only, %d rolled back; functions kept as views %d; '
          'includes dropped %d; view structs pruned %d; merged by role alone %d'
          % (n_views, after, st['acc'], st['uncast'], st['left'], st['retyped'], st['raw'], st['wraps'], full, part,
             len(rolled), len(skip), st['includes'], st['pruned'], job.orphans))
    for gi in rolled:
        g = job.groups[gi]
        print('  rolled back g%d %s (%d nodes, funcs %s)' % (gi, job.plans[gi].ref, len(g.nodes), sorted(g.funcs())[:4]))
    if skip:
        print('  kept as views (bytes changed otherwise): %s' % ', '.join(sorted(skip)[:12]) + (' ...' if len(skip) > 12 else ''))
    r = run_verify(files)
    print('  verify: %s (baseline %s)' % (r, base))
    return job


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('files', nargs='+')
    ap.add_argument('--header', help='header that receives new structs (default: the *_types.h the file includes, else the file)')
    ap.add_argument('--names', help='g0=Name,g1=Name for new structs (group order = access count)')
    ap.add_argument('--clash', choices=('cast', 'union'), default='cast', help='same-offset same-size members of different kinds: majority type plus *(T *)& at the minority sites, or an anonymous union')
    ap.add_argument('--no-orphans', dest='orphans', action='store_false', help='keep small groups without shared evidence apart')
    ap.add_argument('--orphan-max', type=int, default=4, dest='orphan_max', help='largest group (in members) merged by the role rule alone')
    ap.add_argument('--dry', action='store_true', help='analyse and print the groups only')
    ap.add_argument('-v', action='store_true')
    ap.add_argument('--soft', type=float, default=0.34, help='same-size kind clashes allowed per shared member in a role merge')
    ap.add_argument('--min-shared', type=int, default=3, dest='min_shared')
    a = ap.parse_args()
    for f in a.files:
        process(f, a)


if __name__ == '__main__':
    main()
