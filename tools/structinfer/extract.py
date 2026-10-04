"""Struct inference, phase 1: per-file extraction of access and flow events.

For one matched C file this produces a list of events:
  ('acc', node, off, width, kind, signed, write)   a memory access at byte offset `off` of the object `node` points to
  ('uni', node_a, node_b)                          the two nodes point to the same object (assignment, call, return)
  ('fld', node, off, child)                        the pointer stored at (node, off) points to object `child`
  ('emb', node, off, child)                        `child` is a sub-object that starts at (node, off) (bias != 0 flow)
A node is a string key.  Everything is deterministic and needs no judgement.
"""
import os, re, sys
from pycparser import c_parser, c_ast

# ---------------------------------------------------------------- text prep
def strip_src(src):
    out = []; i = 0; n = len(src)
    while i < n:
        if src.startswith('/*', i):
            j = src.find('*/', i + 2); j = n if j < 0 else j + 2
            out.append(re.sub(r'[^\n]', ' ', src[i:j])); i = j
        elif src.startswith('//', i):
            j = src.find('\n', i); j = n if j < 0 else j
            out.append(' ' * (j - i)); i = j
        else:
            out.append(src[i]); i += 1
    t = ''.join(out)
    return re.sub(r'(?m)^[ \t]*#.*$', '', t)

def parse_header(raw):
    m = re.match(r'\s*/\*.*?\*/', raw, re.S)
    h = {'symbols': {}}
    if not m: return h
    in_sym = False
    for line in m.group(0).split('\n'):
        line = line.rstrip('\r')
        if re.match(r'^\s*\*\s*symbols:\s*$', line): in_sym = True; continue
        if in_sym:
            sm = re.match(r'^\s*\*\s+(\w+)\s+(0x[0-9A-Fa-f]+)\s+(\w+)((?:\s+\w+)*)\s*$', line)
            if sm:
                reg = None
                for e in sm.group(4).split():
                    if not re.match(r'^a\d+$', e): reg = e
                if reg == 'arm9': reg = None
                h['symbols'].setdefault(sm.group(1), (int(sm.group(2), 16), sm.group(3), reg))
                continue
            if re.match(r'^\s*\*\s*$', line): continue
            in_sym = False
        mm = re.match(r'^\s*\*\s*([a-z_]+):\s*(.*?)\s*$', line)
        if mm: h.setdefault(mm.group(1), mm.group(2))
    return h

# ---------------------------------------------------------------- types
# ('i', size, signed) ('f', size) ('p', pointee) ('s', key) ('a', elem, n) ('v',) ('fn',)
I8, I16, I32 = ('i', 1, False), ('i', 2, False), ('i', 4, False)
BASE = {
    'char': ('i', 1, True), 'signed char': ('i', 1, True), 'unsigned char': ('i', 1, False),
    'short': ('i', 2, True), 'signed short': ('i', 2, True), 'unsigned short': ('i', 2, False),
    'short int': ('i', 2, True), 'unsigned short int': ('i', 2, False),
    'int': ('i', 4, True), 'signed': ('i', 4, True), 'signed int': ('i', 4, True),
    'unsigned': ('i', 4, False), 'unsigned int': ('i', 4, False),
    'long': ('i', 4, True), 'unsigned long': ('i', 4, False), 'long int': ('i', 4, True),
    'unsigned long int': ('i', 4, False),
    'long long': ('i', 8, True), 'unsigned long long': ('i', 8, False),
    'float': ('f', 4), 'double': ('f', 8), 'void': ('v',),
    'u8': I8, 's8': ('i', 1, True), 'u16': I16, 's16': ('i', 2, True), 'u32': I32, 's32': ('i', 4, True),
    'u64': ('i', 8, False), 's64': ('i', 8, True), 'BOOL': ('i', 4, True), 'fx32': ('i', 4, True),
    'fx16': ('i', 2, True),
}

class FileCtx:
    def __init__(self, ast):
        self.typedefs = {}      # name -> decl type node (resolved lazily)
        self.structs = {}       # tag/key -> AST Struct/Union node
        self.layout = {}        # key -> dict or None
        self.anon = 0
        for ext in ast.ext:
            if isinstance(ext, c_ast.Typedef):
                self.typedefs[ext.name] = ext.type
                self._collect(ext.type)
            elif isinstance(ext, c_ast.Decl):
                self._collect(ext.type)
            elif isinstance(ext, c_ast.FuncDef):
                pass

    def _collect(self, t):
        # register struct/union definitions that carry a body, at any nesting depth
        while t is not None:
            if isinstance(t, (c_ast.Struct, c_ast.Union)):
                if t.decls is not None:
                    key = t.name or ('anon%d' % id(t))
                    self.structs.setdefault(key, t)
                    for d in t.decls: self._collect(d.type)
                return
            if isinstance(t, (c_ast.TypeDecl, c_ast.PtrDecl, c_ast.ArrayDecl)):
                t = t.type
            elif isinstance(t, c_ast.FuncDecl):
                t = t.type
            else:
                return

    def tdesc(self, t, depth=0):
        """AST type node -> descriptor, or None."""
        if depth > 12 or t is None: return None
        if isinstance(t, c_ast.TypeDecl): return self.tdesc(t.type, depth + 1)
        if isinstance(t, c_ast.PtrDecl): return ('p', self.tdesc(t.type, depth + 1) or ('v',))
        if isinstance(t, c_ast.ArrayDecl):
            e = self.tdesc(t.type, depth + 1)
            n = self.const(t.dim)
            return ('a', e, n if n is not None else 0) if e else None
        if isinstance(t, c_ast.FuncDecl): return ('fn',)
        if isinstance(t, c_ast.IdentifierType):
            nm = ' '.join(t.names)
            if nm in BASE: return BASE[nm]
            if len(t.names) == 1 and t.names[0] in self.typedefs:
                return self.tdesc(self.typedefs[t.names[0]], depth + 1)
            nm2 = nm.replace('unsigned ', 'unsigned ')
            return BASE.get(nm2)
        if isinstance(t, (c_ast.Struct, c_ast.Union)):
            key = t.name if t.name in self.structs else None
            if t.decls is not None: key = t.name or ('anon%d' % id(t)); self.structs.setdefault(key, t)
            if key is None and t.name: key = t.name
            return ('s', key, isinstance(t, c_ast.Union)) if key else None
        if isinstance(t, c_ast.Enum): return I32
        return None

    def const(self, e):
        if e is None: return None
        if isinstance(e, c_ast.Constant):
            try: return int(re.sub(r'[uUlL]+$', '', e.value), 0)
            except Exception: return None
        if isinstance(e, c_ast.UnaryOp) and e.op == '-':
            v = self.const(e.expr); return -v if v is not None else None
        if isinstance(e, c_ast.BinaryOp):
            a, b = self.const(e.left), self.const(e.right)
            if a is None or b is None: return None
            try:
                return {'+': a + b, '-': a - b, '*': a * b, '<<': a << b, '/': a // b if b else None}.get(e.op)
            except Exception: return None
        if isinstance(e, c_ast.Cast): return self.const(e.expr)
        return None

    def size_align(self, d):
        if d is None: return None
        k = d[0]
        if k == 'i': return d[1], min(d[1], 4) if d[1] < 8 else 8
        if k == 'f': return d[1], d[1]
        if k == 'p': return 4, 4
        if k == 'v': return 1, 1
        if k == 'a':
            sa = self.size_align(d[1])
            if sa is None: return None
            return sa[0] * d[2], sa[1]
        if k == 's':
            lay = self.get_layout(d[1])
            if lay is None: return None
            return lay['size'], lay['align']
        return None

    def get_layout(self, key):
        if key in self.layout: return self.layout[key]
        self.layout[key] = None
        node = self.structs.get(key)
        if node is None or node.decls is None: return None
        is_union = isinstance(node, c_ast.Union)
        off = 0; mx = 1; fields = {}; size = 0
        for dcl in node.decls:
            if dcl.bitsize is not None: return None          # bitfields: no layout (prototype)
            d = self.tdesc(dcl.type)
            sa = self.size_align(d)
            if sa is None: return None
            sz, al = sa; mx = max(mx, al)
            if is_union:
                o = 0; size = max(size, sz)
            else:
                o = (off + al - 1) // al * al; off = o + sz; size = off
            if dcl.name: fields[dcl.name] = (o, d)
        size = (size + mx - 1) // mx * mx
        lay = {'fields': fields, 'size': size, 'align': mx, 'union': is_union}
        self.layout[key] = lay
        return lay

def region_key(region, addr, token):
    if token: return token
    if region and region.startswith('ov') and addr >= 0x02100000: return region
    return 'arm9'

ADDR_RE = re.compile(r'^(?:func|sub)_([0-9A-Fa-f]{8})$')

class Extractor:
    def __init__(self, rel, raw):
        self.rel = rel
        self.h = parse_header(raw)
        self.region = self.h.get('region', '')
        ast = c_parser.CParser().parse(strip_src(raw), filename=rel)
        self.ast = ast
        self.cx = FileCtx(ast)
        self.ev_out = []
        self._sites_seen = set()
        self._memo = {}
        self.tmp = 0
        self.func = None
        self.locals = {}

    # --- keys
    def callee_key(self, name):
        sym = self.h['symbols'].get(name)
        if sym:
            addr, kind, tok = sym
            if kind == 'data': return None
            return (region_key(self.region, addr, tok), addr)
        m = ADDR_RE.match(name)
        if not m: return None
        addr = int(m.group(1), 16)
        return (region_key(self.region, addr, None), addr)

    def newtmp(self):
        self.tmp += 1
        return 'T:%s:%s:%d' % (self.rel, self.func or '-', self.tmp)

    def emit(self, *e): self.ev_out.append(e)
    def src(self): return self.rel + ':' + str(self.func)

    def var_node(self, name):
        if name in self.locals: return 'V:%s:%s:%s' % (self.rel, self.func, name)
        return 'G:%s:%s' % (self.rel, name)

    # --- values: ('o', node, bias, desc) = pointer-like value into object `node` at byte `bias`; ('c', k); None
    def run(self):
        for ext in self.ast.ext:
            if isinstance(ext, c_ast.FuncDef): self.funcdef(ext)
        return self.ev_out

    def funcdef(self, fd):
        name = fd.decl.name
        m = ADDR_RE.match(name)
        self.func = name; self.locals = {}
        self.fkey = None
        if m:
            addr = int(m.group(1), 16)
            self.fkey = (region_key(self.region, addr, None), addr)
        ft = fd.decl.type
        self.rettype = self.cx.tdesc(ft.type) if isinstance(ft, c_ast.FuncDecl) else None
        if isinstance(ft, c_ast.FuncDecl) and ft.args:
            for i, p in enumerate(ft.args.params):
                if isinstance(p, c_ast.Decl) and p.name:
                    self.locals[p.name] = self.cx.tdesc(p.type)
                    if self.fkey:
                        self.emit('bind', self.var_node(p.name), 'P:%s:%08X:%d' % (self.fkey[0], self.fkey[1], i))
        self.stmt(fd.body)

    # --- statements
    def stmt(self, s):
        if s is None: return
        if isinstance(s, c_ast.Compound):
            for it in (s.block_items or []): self.stmt(it)
        elif isinstance(s, c_ast.Decl):
            if s.name and not isinstance(s.type, c_ast.FuncDecl):
                self.locals[s.name] = self.cx.tdesc(s.type)
                if s.init is not None:
                    v = self.ev(s.init)
                    self.flow_to(self.var_node(s.name), v)
        elif isinstance(s, c_ast.Return):
            if s.expr is not None:
                v = self.ev(s.expr)
                if self.fkey and v is not None and v[0] == 'o' and v[2] == 0: self.emit('ret', 'R:%s:%08X' % self.fkey, v[1])
        elif isinstance(s, (c_ast.If,)):
            self.ev(s.cond); self.stmt(s.iftrue); self.stmt(s.iffalse)
        elif isinstance(s, (c_ast.While, c_ast.DoWhile)):
            self.ev(s.cond); self.stmt(s.stmt)
        elif isinstance(s, c_ast.For):
            if s.init is not None:
                if isinstance(s.init, c_ast.DeclList):
                    for d in s.init.decls: self.stmt(d)
                else: self.ev(s.init)
            if s.cond is not None: self.ev(s.cond)
            if s.next is not None: self.ev(s.next)
            self.stmt(s.stmt)
        elif isinstance(s, c_ast.Switch):
            self.ev(s.cond); self.stmt(s.stmt)
        elif isinstance(s, (c_ast.Case, c_ast.Default)):
            for it in (s.stmts or []): self.stmt(it)
        elif isinstance(s, c_ast.Label):
            self.stmt(s.stmt)
        elif isinstance(s, (c_ast.Break, c_ast.Continue, c_ast.Goto, c_ast.EmptyStatement, c_ast.Pragma)):
            pass
        elif isinstance(s, c_ast.ExprList):
            for e in s.exprs: self.ev(e)
        else:
            try: self.ev(s)
            except Exception: pass

    # --- flows
    def flow_to(self, dst_node, v):
        if v is None or v[0] != 'o': return
        _, node, bias, _d = v
        if bias == 0: self.emit('uni', dst_node, node)
        else: self.emit('emb', node, bias, dst_node)

    def scale_of(self, d):
        """element size for pointer arithmetic on a value of descriptor d (ints and byte pointers: 1)."""
        if d is None: return None
        if d[0] == 'p':
            sa = self.cx.size_align(d[1]); return sa[0] if sa else None
        return 1

    # --- expressions
    def ev(self, e):
        r = self._ev(e)
        self._memo[id(e)] = r
        return r

    def _ev(self, e):
        if e is None: return None
        t = type(e)
        if t is c_ast.Constant:
            k = self.cx.const(e)
            return ('c', k) if k is not None else None
        if t is c_ast.ID:
            n = e.name
            if n in self.locals:
                return ('o', self.var_node(n), 0, self.locals[n])
            return None
        if t is c_ast.Cast:
            v = self.ev(e.expr)
            d = self.cx.tdesc(e.to_type.type) if isinstance(e.to_type, c_ast.Typename) else None
            if v is not None and v[0] == 'o': return ('o', v[1], v[2], d)
            return v
        if t is c_ast.BinaryOp:
            a = self.ev(e.left); b = self.ev(e.right)
            if e.op in ('+', '-'):
                for p, q, sign in ((a, b, 1), (b, a, 1 if e.op == '+' else None)):
                    if p is not None and p[0] == 'o' and q is not None and q[0] == 'c':
                        if sign is None: continue
                        sc = self.scale_of(p[3])
                        if sc is None: return None
                        k = q[1] * sc * (1 if e.op == '+' else -1)
                        return ('o', p[1], p[2] + k, p[3])
                if e.op == '-' and a is not None and a[0] == 'o' and b is not None and b[0] == 'c':
                    pass
            if e.op in ('+', '-', '*', '<<', '>>', '&', '|', '^') and a and b and a[0] == 'c' and b[0] == 'c':
                try:
                    return ('c', {'+': a[1] + b[1], '-': a[1] - b[1], '*': a[1] * b[1], '<<': a[1] << b[1],
                                  '>>': a[1] >> b[1], '&': a[1] & b[1], '|': a[1] | b[1], '^': a[1] ^ b[1]}[e.op])
                except Exception: return None
            return None
        if t is c_ast.UnaryOp:
            if e.op == '*':
                v = self.ev(e.expr)
                self.note_site(e)
                return self.deref(v, None, write=False)
            if e.op == '&':
                return self.addr_of(e.expr)
            if e.op in ('sizeof',): return None
            if e.op in ('p++', 'p--', '++', '--'):
                self.ev(e.expr); return None
            self.ev(e.expr); return None
        if t is c_ast.StructRef:
            return self.structref(e, write=False)
        if t is c_ast.ArrayRef:
            return self.arrayref(e, write=False)
        if t is c_ast.FuncCall:
            return self.call(e)
        if t is c_ast.Assignment:
            return self.assign(e)
        if t is c_ast.TernaryOp:
            self.ev(e.cond); a = self.ev(e.iftrue); b = self.ev(e.iffalse)
            if a is not None and b is not None and a[0] == 'o' and b[0] == 'o' and a[2] == 0 and b[2] == 0:
                self.emit('uni', a[1], b[1]); return a
            return a or b
        if t is c_ast.ExprList:
            v = None
            for x in e.exprs: v = self.ev(x)
            return v
        if t is c_ast.Typename: return None
        return None

    def note_site(self, e):
        """Record where a raw-offset access `*(T *)(v + K)` sits in the text (for the rewriter)."""
        if id(e) in self._sites_seen: return
        self._sites_seen.add(id(e))
        x = e.expr
        if not isinstance(x, c_ast.Cast) or not isinstance(x.to_type, c_ast.Typename): return
        td = self.cx.tdesc(x.to_type.type)
        if td is None or td[0] != 'p': return
        pd = td[1]
        inner = x.expr; form = None; var = None; kt = None; k = 0
        if isinstance(inner, c_ast.ID):
            form, var, kt, k = 'zero', inner.name, '0', 0
        elif isinstance(inner, c_ast.BinaryOp) and inner.op == '+' and isinstance(inner.right, c_ast.Constant):
            l = inner.left; kt = inner.right.value; k = self.cx.const(inner.right)
            if k is None: return
            if isinstance(l, c_ast.ID): form, var = 'id', l.name
            elif isinstance(l, c_ast.Cast) and isinstance(l.expr, c_ast.ID): form, var = 'cast', l.expr.name
            else: form = 'expr'
        else:
            form = 'expr'; kt = '0'; k = 0
        if form == 'expr':
            # any other base expression E: `*(T *)(E + K)` or `*(T *)(E)`; E must be a value of a known
            # class at bias 0, so that `((struct S *)(E))->fK` is the same address
            if isinstance(inner, c_ast.BinaryOp) and inner.op == '+' and isinstance(inner.right, c_ast.Constant):
                left = inner.left; kt = inner.right.value; kc = self.cx.const(inner.right)
                if kc is None: return
            else:
                left = inner; kt = '0'; kc = 0
            v = self._memo.get(id(left))
            if v is None or v[0] != 'o' or v[2] != 0: return
            sc = self.scale_of(v[3])
            if sc is None: return
            k = kc * sc
            if pd[0] == 'i': kind, width, sg = 'int', pd[1], pd[2]
            elif pd[0] == 'p': kind, width, sg = 'ptr', 4, False
            else: return
            c = x.coord
            if c is None: return
            self.emit('site', v[1], k, width, kind, sg, c.line, c.column, 'expr', '', kt)
            return
        if var not in self.locals: return
        if form != 'zero':
            v = self.ev(inner)      # byte offset after pointer scaling (an int * variable steps by 4)
            if v is None or v[0] != 'o': return
            k = v[2]
        if pd[0] == 'i': kind, width, sg = 'int', pd[1], pd[2]
        elif pd[0] == 'p': kind, width, sg = 'ptr', 4, False
        else: return
        c = x.coord
        if c is None: return
        self.emit('site', self.var_node(var), k, width, kind, sg, c.line, c.column, form, var, kt)

    def deref(self, v, desc, write):
        """*v : an access.  desc = static type of the deref'd lvalue (pointee of v's type)."""
        if v is None or v[0] != 'o': return None
        _, node, bias, d = v
        pd = d[1] if d is not None and d[0] == 'p' else None
        if desc is not None: pd = desc
        if pd is None: return None
        return self.access(node, bias, pd, write)

    def access(self, node, bias, pd, write):
        k = pd[0]
        if k == 'i':
            self.emit('acc', node, bias, pd[1], 'int', pd[2], write, self.src()); return None
        if k == 'f':
            self.emit('acc', node, bias, pd[1], 'float', False, write, self.src()); return None
        if k == 'p':
            self.emit('acc', node, bias, 4, 'ptr', False, write, self.src())
            child = self.newtmp()
            self.emit('fld', node, bias, child)
            return ('o', child, 0, pd)
        if k == 'a':
            # access to an array element start: strided region
            es = self.cx.size_align(pd[1]);
            self.emit('acc', node, bias, es[0] if es else 1, 'arr', False, write, self.src()); return None
        if k == 's':
            # a struct-typed lvalue: it IS an embedded sub-object at bias
            child = self.newtmp()
            self.emit('emb', node, bias, child)
            return ('o', child, 0, ('p', pd))
        return None

    def addr_of(self, x):
        # &*p, &p->f, &arr[i]: pointer into the object
        if isinstance(x, c_ast.UnaryOp) and x.op == '*':
            return self.ev(x.expr)
        if isinstance(x, c_ast.StructRef):
            r = self.structref(x, write=False, take_addr=True); return r
        if isinstance(x, c_ast.ArrayRef):
            r = self.arrayref(x, write=False, take_addr=True); return r
        self.ev(x); return None

    def structref(self, e, write, take_addr=False):
        base = e.name
        if e.type == '->':
            bv = self.ev(base)
            if bv is None or bv[0] != 'o': return None
            _, node, bias, d = bv
            if d is None or d[0] != 'p' or d[1][0] != 's': return None
            sd = d[1]
        else:  # '.'  on a struct lvalue: resolve through the lvalue chain
            bv = self.lvalue(base)
            if bv is None: return None
            node, bias, sd = bv
            if sd[0] != 's': return None
        lay = self.cx.get_layout(sd[1])
        if lay is None: return None
        f = lay['fields'].get(e.field.name)
        if f is None: return None
        off, fd = f
        if take_addr:
            return ('o', node, bias + off, ('p', fd))
        return self.access(node, bias + off, fd, write)

    def lvalue(self, x):
        """lvalue of struct/array type -> (node, bias, desc) or None."""
        if isinstance(x, c_ast.StructRef):
            bv = None
            if x.type == '->':
                v = self.ev(x.name)
                if v is None or v[0] != 'o' or v[3] is None or v[3][0] != 'p' or v[3][1][0] != 's': return None
                node, bias, sd = v[1], v[2], v[3][1]
            else:
                r = self.lvalue(x.name)
                if r is None: return None
                node, bias, sd = r
                if sd[0] != 's': return None
            lay = self.cx.get_layout(sd[1])
            if lay is None: return None
            f = lay['fields'].get(x.field.name)
            if f is None: return None
            return node, bias + f[0], f[1]
        if isinstance(x, c_ast.ArrayRef):
            base = self.lvalue(x.name)
            if base is None:
                v = self.ev(x.name)
                if v is None or v[0] != 'o' or v[3] is None or v[3][0] != 'p': return None
                ed = v[3][1]; node, bias = v[1], v[2]
            else:
                node, bias, ad = base
                if ad[0] != 'a': return None
                ed = ad[1]
            sa = self.cx.size_align(ed)
            if sa is None: return None
            idx = self.cx.const(x.subscript)
            if idx is None: self.ev(x.subscript); idx = 0
            return node, bias + idx * sa[0], ed
        if isinstance(x, c_ast.UnaryOp) and x.op == '*':
            v = self.ev(x.expr)
            if v is None or v[0] != 'o' or v[3] is None or v[3][0] != 'p': return None
            return v[1], v[2], v[3][1]
        return None

    def arrayref(self, e, write, take_addr=False):
        r = self.lvalue(e)
        if r is None:
            self.ev(e.subscript); return None
        node, bias, d = r
        if take_addr: return ('o', node, bias, ('p', d))
        return self.access(node, bias, d, write)

    def call(self, e):
        name = e.name.name if isinstance(e.name, c_ast.ID) else None
        args = e.args.exprs if e.args is not None else []
        vals = [self.ev(a) for a in args]
        if name is None: return None
        key = self.callee_key(name)
        if key is None: return None
        consts = [(self.cx.const(a)) for a in args]
        for i, v in enumerate(vals):
            if v is not None and v[0] == 'o':
                pn = 'P:%s:%08X:%d' % (key[0], key[1], i)
                if v[2] == 0: self.emit('call', v[1], pn)
                else: self.emit('emb', v[1], v[2], pn)
        tmp = self.newtmp()
        self.emit('callret', tmp, 'R:%s:%08X' % key)
        if any(c is not None for c in consts):
            self.emit('csz', tmp, '%s:%08X' % key, tuple(consts), self.src())
        return ('o', tmp, 0, None)

    def assign(self, e):
        rv = self.ev(e.rvalue)
        lhs = e.lvalue
        if isinstance(lhs, c_ast.ID):
            if lhs.name in self.locals:
                if e.op == '=':
                    self.flow_to(self.var_node(lhs.name), rv)
            return rv
        # memory store
        lv = None
        if isinstance(lhs, c_ast.UnaryOp) and lhs.op == '*':
            v = self.ev(lhs.expr)
            self.note_site(lhs)
            pd = v[3][1] if (v is not None and v[0] == 'o' and v[3] is not None and v[3][0] == 'p') else None
            lv = self.deref(v, pd, write=True) if pd is not None else None
        elif isinstance(lhs, c_ast.StructRef):
            lv = self.structref(lhs, write=True)
        elif isinstance(lhs, c_ast.ArrayRef):
            lv = self.arrayref(lhs, write=True)
        if lv is not None and e.op == '=' and rv is not None and rv[0] == 'o':
            # a pointer value stored into a pointer field: lv is the child object of that field
            if rv[2] == 0: self.emit('uni', lv[1], rv[1])
            else: self.emit('emb', rv[1], rv[2], lv[1])
        return rv

def extract_file(path, rel):
    raw = open(path, encoding='latin1').read()
    ex = Extractor(rel, raw)
    return ex.run()

if __name__ == '__main__':
    p = sys.argv[1]
    for e in extract_file(p, os.path.basename(p)): print(e)
