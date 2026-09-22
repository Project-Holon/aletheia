#!/usr/bin/env python3
"""permuter.py -- an allocation-aware source permuter for near misses.

The successor of tools/permute.py.  That tool rewrites *lines*; this one rewrites the
function's abstract syntax tree (pycparser) with mutations chosen for what actually moves
the Metrowerks back end.  mwccarm allocates registers by Chaitin graph colouring: values
are numbered in the order the optimised IR creates them, spill cost is
flow_weight * (2 * uses + definitions), copies are coalesced, and each value takes the
lowest legal colour in simplify order.  Register choice therefore follows first-definition
order, use and definition counts, copy insertion, live-range shape and address-taking,
not the spelling of an expression.  Every mutation here targets one of those, and every
mutation is value-preserving: the function still computes the same thing.

Scoring goes through match.run_one() exactly as `match.py one` does (same evidence rules,
same wildcarding), then adds an instruction-level score in the style of decomp-permuter:
aligned mnemonics with different registers cost little, inserted or deleted instructions
cost a lot.  That gives the search a gradient where "concrete bytes out" is flat.

Usage:
  python3 tools/permuter.py --src FILE --func NAME --addr 0xADDR (--thumb|--arm)
        [--cc 1.1p1] [--flags "-O4,p"] [--budget N] [--seed S] [--jobs J]
        [--mode anneal|hill|random] [--out FILE] [--focus VAR[,VAR]] [--types]
        [--list] [--explain]

  --list     print the mutation sites available on the function, no compiles
  --explain  compile once and print the register-substitution map of the residue
  --focus    only mutate statements that mention these identifiers
  --types    also allow local/parameter integer type changes (not value-preserving
             in general; every such variant is labelled 'type:' in the output)

Requires pycparser (python3 -m pip install --user pycparser).  Sources that use inline
asm or preprocessor macros in the function body are not parseable here; use permute.py.
"""
import argparse, copy, difflib, hashlib, os, random, re, subprocess, sys, threading, time
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import match  # noqa: E402

try:
    from pycparser import c_ast, c_generator, c_parser
except ImportError:  # pragma: no cover
    sys.exit("permuter: pycparser is required: python3 -m pip install --user pycparser")

INT_TYPES = ("int", "u32", "s32", "u16", "s16", "u8", "s8", "BOOL", "unsigned", "long")

# ---------------------------------------------------------------------------
# program = verbatim header comment + parsed rest
# ---------------------------------------------------------------------------


class Program:
    def __init__(self, text, func):
        self.func = func
        m = re.match(r"\s*/\*.*?\*/", text, re.S)
        self.header = m.group(0) if m else ""
        rest = text[len(self.header):]
        self.directives = [ln for ln in rest.split("\n") if ln.lstrip().startswith("#")]
        stripped = re.sub(r"/\*.*?\*/", "", rest, flags=re.S)
        stripped = re.sub(r"//[^\n]*", "", stripped)
        stripped = re.sub(r"^\s*#.*$", "", stripped, flags=re.M)
        try:
            self.ast = c_parser.CParser().parse(stripped, "<src>")
        except Exception as exc:
            raise SystemExit("permuter: cannot parse the source (%s); use tools/permute.py" % str(exc)[:160])
        self.fidx = None
        for i, ext in enumerate(self.ast.ext):
            if isinstance(ext, c_ast.FuncDef) and ext.decl.name == func:
                self.fidx = i
        if self.fidx is None:
            raise SystemExit("permuter: no definition of %s in the source" % func)
        self.gen = c_generator.CGenerator()
        self.functypes = {}   # name -> return type node
        self.globals = {}     # name -> type node
        for ext in self.ast.ext:
            if isinstance(ext, c_ast.Decl) and isinstance(ext.type, c_ast.FuncDecl):
                self.functypes[ext.name] = ext.type.type
            elif isinstance(ext, c_ast.Decl) and ext.name:
                self.globals[ext.name] = ext.type
            elif isinstance(ext, c_ast.FuncDef):
                self.functypes[ext.decl.name] = ext.decl.type.type

    def funcdef(self):
        return self.ast.ext[self.fidx]

    def render(self, fdef=None):
        ext = list(self.ast.ext)
        if fdef is not None:
            ext[self.fidx] = fdef
        tu = c_ast.FileAST(ext)
        body = self.gen.visit(tu)
        parts = [self.header] + self.directives + [body]
        return "\n".join(p for p in parts if p is not None) + "\n"


# ---------------------------------------------------------------------------
# AST helpers
# ---------------------------------------------------------------------------

def walk(node):
    """Yield (node, parent, attr, index) for every node under `node`, depth first."""
    stack = [(node, None, None, None)]
    while stack:
        n, p, a, i = stack.pop()
        yield n, p, a, i
        for attr, child in reversed(list(n.children())):
            m = re.match(r"(\w+)(?:\[(\d+)\])?", attr)
            stack.append((child, n, m.group(1), int(m.group(2)) if m.group(2) else None))


def set_child(parent, attr, idx, new):
    if idx is None:
        setattr(parent, attr, new)
    else:
        getattr(parent, attr)[idx] = new


def compounds(fdef):
    """Every Compound in the body (statement lists we can edit)."""
    return [n for n, _, _, _ in walk(fdef.body) if isinstance(n, c_ast.Compound) and n.block_items]


def stmt_slots(fdef):
    """(compound, index) for every statement position in the function."""
    out = []
    for c in compounds(fdef):
        for i in range(len(c.block_items)):
            out.append((c, i))
    return out


def ids_of(node):
    return {n.name for n, _, _, _ in walk(node) if isinstance(n, c_ast.ID)}


def has_call(node):
    return any(isinstance(n, c_ast.FuncCall) for n, _, _, _ in walk(node))


def writes_of(node):
    """Identifiers a statement may write (assignment targets, ++/--, address-taken, and
    the base of any pointer/array/member store).  Calls write everything ('*')."""
    out = set()
    for n, _, _, _ in walk(node):
        if isinstance(n, c_ast.Assignment):
            out |= base_ids(n.lvalue)
        elif isinstance(n, c_ast.UnaryOp) and n.op in ("p++", "p--", "++", "--"):
            out |= base_ids(n.expr)
        elif isinstance(n, c_ast.UnaryOp) and n.op == "&":
            out |= base_ids(n.expr)
        elif isinstance(n, c_ast.FuncCall):
            out.add("*")
    return out


def base_ids(lv):
    """The identifiers an lvalue depends on; a store through a pointer counts as a write
    to '*mem' as well, so that two memory statements are never reordered."""
    out = set()
    if isinstance(lv, c_ast.ID):
        out.add(lv.name)
    elif isinstance(lv, (c_ast.StructRef, c_ast.ArrayRef, c_ast.UnaryOp)):
        out.add("*mem")
        out |= ids_of(lv)
    else:
        out |= ids_of(lv)
    return out


def reads_of(node):
    r = ids_of(node)
    if any(isinstance(n, c_ast.UnaryOp) and n.op == "&" for n, _, _, _ in walk(node)):
        r.add("*mem")
    if any(isinstance(n, (c_ast.StructRef, c_ast.ArrayRef)) or
           (isinstance(n, c_ast.UnaryOp) and n.op == "*") for n, _, _, _ in walk(node)):
        r.add("*mem")
    if has_call(node):
        r.add("*")
    return r


def mem_accesses(node, writes):
    """(base, field) for every memory access in `node`: field is the member name for p->f /
    s.f, a constant index for a[3], or None when unknown (then it may alias anything)."""
    out = set()
    for n, p, a, k in walk(node):
        is_store = isinstance(p, c_ast.Assignment) and a == "lvalue" or \
            (isinstance(p, c_ast.UnaryOp) and p.op in ("p++", "p--", "++", "--", "&"))
        if writes != is_store and not (writes is False and is_store and isinstance(p, c_ast.Assignment) and p.op != "="):
            continue
        if isinstance(n, c_ast.StructRef):
            base = n.name.name if isinstance(n.name, c_ast.ID) else None
            if isinstance(n.name, c_ast.UnaryOp) and n.name.op == "*" and isinstance(n.name.expr, c_ast.ID):
                base = n.name.expr.name
            out.add((base, n.field.name))
        elif isinstance(n, c_ast.ArrayRef):
            base = n.name.name if isinstance(n.name, c_ast.ID) else None
            out.add((base, "[%d]" % const_val(n.subscript) if const_val(n.subscript) is not None else None))
        elif isinstance(n, c_ast.UnaryOp) and n.op == "*":
            out.add((None, None))
    return out


def may_alias(x, y):
    """Two accesses (base, field) may touch the same memory unless both are named fields or
    constant indices of the same base object with different names."""
    bx, fx = x
    by, fy = y
    if fx is None or fy is None:
        return True
    if bx is not None and bx == by:
        return fx == fy
    # different base pointers: a struct field and an array slot never alias by name; two
    # struct fields with different names are taken as distinct objects (type-based rule)
    return fx == fy


def independent(a, b):
    """True when statements a and b can be swapped without changing the result."""
    wa, wb, ra, rb = writes_of(a), writes_of(b), reads_of(a), reads_of(b)
    if "*" in wa or "*" in wb:
        return False
    # register-level dependencies
    if (wa - {"*mem"}) & rb or (wb - {"*mem"}) & ra or (wa - {"*mem"}) & (wb - {"*mem"}):
        return False
    # memory-level dependencies, field by field
    if "*mem" in wa or "*mem" in wb:
        sa, sb = mem_accesses(a, True), mem_accesses(b, True)
        la, lb = mem_accesses(a, False), mem_accesses(b, False)
        for x in sa:
            if any(may_alias(x, y) for y in sb | lb):
                return False
        for y in sb:
            if any(may_alias(y, x) for x in la):
                return False
    return True


def is_simple_type(t):
    return isinstance(t, c_ast.TypeDecl) and isinstance(t.type, c_ast.IdentifierType)


def type_name(t):
    if isinstance(t, c_ast.TypeDecl) and isinstance(t.type, c_ast.IdentifierType):
        return " ".join(t.type.names)
    if isinstance(t, c_ast.PtrDecl):
        return type_name(t.type) + "*"
    return None


def mk_type(name, declname=None, quals=()):
    if name.endswith("*"):
        return c_ast.PtrDecl([], mk_type(name[:-1], declname, quals))
    return c_ast.TypeDecl(declname, list(quals), None, c_ast.IdentifierType(name.split()))


def mk_decl(name, typenode, init=None, quals=()):
    t = copy.deepcopy(typenode)
    # push the declname into the innermost TypeDecl
    inner = t
    while not isinstance(inner, c_ast.TypeDecl):
        inner = inner.type
    inner.declname = name
    if quals:
        inner.quals = list(set(inner.quals) | set(quals))
    return c_ast.Decl(name, [], None, [], [], t, init, None)


def const(v):
    return c_ast.Constant("int", str(v))


def const_val(n):
    if isinstance(n, c_ast.Constant) and n.type == "int":
        try:
            return int(n.value.rstrip("uUlL"), 0)
        except ValueError:
            return None
    return None


class Ctx:
    """Types of everything visible inside the function."""

    def __init__(self, prog, fdef):
        self.prog = prog
        self.fdef = fdef
        self.locals = {}
        self.params = {}
        self.addr_taken = {n.expr.name for n, _, _, _ in walk(fdef.body)
                           if isinstance(n, c_ast.UnaryOp) and n.op == "&" and isinstance(n.expr, c_ast.ID)}
        fd = fdef.decl.type
        if fd.args:
            for p in fd.args.params:
                if isinstance(p, c_ast.Decl) and p.name:
                    self.params[p.name] = p
        for n, _, _, _ in walk(fdef.body):
            if isinstance(n, c_ast.Decl) and n.name:
                self.locals[n.name] = n
        self.names = set(self.locals) | set(self.params) | set(prog.globals) | set(prog.functypes)

    def type_of(self, expr):
        """Best-effort type node of an expression, or None."""
        if isinstance(expr, c_ast.ID):
            d = self.locals.get(expr.name) or self.params.get(expr.name)
            if d is not None:
                return d.type
            g = self.prog.globals.get(expr.name)
            return g
        if isinstance(expr, c_ast.Cast):
            return expr.to_type.type
        if isinstance(expr, c_ast.FuncCall) and isinstance(expr.name, c_ast.ID):
            return self.prog.functypes.get(expr.name.name)
        if isinstance(expr, c_ast.Constant):
            return mk_type("int") if expr.type == "int" else None
        if isinstance(expr, c_ast.BinaryOp):
            if expr.op in ("<", ">", "<=", ">=", "==", "!=", "&&", "||"):
                return mk_type("int")
            lt, rt = self.type_of(expr.left), self.type_of(expr.right)
            if isinstance(lt, c_ast.PtrDecl) and expr.op in ("+", "-"):
                return lt
            return lt if is_simple_type(lt) else rt
        if isinstance(expr, c_ast.UnaryOp):
            if expr.op == "&":
                t = self.type_of(expr.expr)
                return c_ast.PtrDecl([], copy.deepcopy(t)) if t is not None else None
            if expr.op == "*":
                t = self.type_of(expr.expr)
                return t.type if isinstance(t, c_ast.PtrDecl) else None
            return self.type_of(expr.expr)
        if isinstance(expr, c_ast.ArrayRef):
            t = self.type_of(expr.name)
            return t.type if isinstance(t, (c_ast.PtrDecl, c_ast.ArrayDecl)) else None
        if isinstance(expr, c_ast.TernaryOp):
            return self.type_of(expr.iftrue)
        return None

    def fresh(self, base="t"):
        i = 0
        while True:
            n = "%s%d" % (base, i) if i else base
            if n not in self.names:
                self.names.add(n)
                return n
            i += 1


# ---------------------------------------------------------------------------
# mutations: each has sites(ctx) -> list and apply(ctx, site, rng) -> label or None
# they edit ctx.fdef in place (ctx.fdef is always a fresh deep copy)
# ---------------------------------------------------------------------------

MUTATIONS = []


def mutation(name, weight, unsafe=False):
    def deco(cls):
        cls.name, cls.weight, cls.unsafe = name, weight, unsafe
        MUTATIONS.append(cls)
        return cls
    return deco


def expr_sites(ctx, pred):
    """(parent, attr, idx, expr, stmt) for expressions inside statements of the body.

    Only expressions whose evaluation is unconditional within their own statement slot are
    offered: nothing under a nested block (those belong to the inner slot), nothing in a loop
    statement, and nothing on the right of && / || or in a ?: arm or a non-block if arm, so a
    mutation that inserts code before the statement (temp) cannot hoist a guarded read."""
    out = []
    for comp, i in stmt_slots(ctx.fdef):
        st = comp.block_items[i]
        if isinstance(st, (c_ast.While, c_ast.DoWhile, c_ast.For)):
            continue
        stack = [(st, None, None, None, False)]
        while stack:
            n, p, a, k, guarded = stack.pop()
            if p is not None and not guarded and not isinstance(p, (c_ast.Decl, c_ast.Typename, c_ast.Case)) and pred(n):
                out.append((p, a, k, n, comp, i))
            for attr, child in reversed(list(n.children())):
                m = re.match(r"(\w+)(?:\[(\d+)\])?", attr)
                name, idx = m.group(1), (int(m.group(2)) if m.group(2) else None)
                if isinstance(child, c_ast.Compound):
                    continue
                g = guarded
                if isinstance(n, c_ast.If) and name != "cond":
                    g = True
                if isinstance(n, c_ast.BinaryOp) and n.op in ("&&", "||") and name == "right":
                    g = True
                if isinstance(n, c_ast.TernaryOp) and name != "cond":
                    g = True
                if isinstance(n, (c_ast.While, c_ast.DoWhile, c_ast.For, c_ast.Switch)):
                    g = True
                stack.append((child, n, name, idx, g))
    return out


def interesting_expr(n):
    return isinstance(n, (c_ast.BinaryOp, c_ast.FuncCall, c_ast.StructRef, c_ast.ArrayRef, c_ast.Cast)) or \
        (isinstance(n, c_ast.UnaryOp) and n.op in ("*", "-", "~", "!"))


def stmt_of_expr_is_decl_init(p):
    return isinstance(p, c_ast.Decl)


def same_expr(a, b, gen):
    return gen.visit(a) == gen.visit(b)


@mutation("temp", 100)
class TempForExpr:
    """Lift an expression into a named local: adds a value with its own definition point
    and use count, the single most effective allocation lever."""
    @staticmethod
    def sites(ctx):
        return expr_sites(ctx, interesting_expr)

    @staticmethod
    def apply(ctx, site, rng):
        p, a, k, expr, comp, i = site
        if isinstance(p, c_ast.Assignment) and a == "lvalue":
            return None
        if isinstance(p, c_ast.UnaryOp) and p.op == "&":
            return None
        if isinstance(expr, c_ast.FuncCall) and isinstance(p, c_ast.Compound):
            return None  # a bare call statement; nothing to lift
        if has_call(expr):
            # lifting a call ahead of the statement reorders side effects unless it is the
            # statement's only call; the scorer cannot see a changed call order or count
            ncalls = sum(1 for n, _, _, _ in walk(comp.block_items[i]) if isinstance(n, c_ast.FuncCall))
            if ncalls > 1:
                return None
        t = ctx.type_of(expr)
        if t is None or isinstance(t, c_ast.ArrayDecl):
            t = mk_type(rng.choice(("int", "u32", "s32")))
        if is_simple_type(t) and t.type.names == ["void"]:
            return None
        name = ctx.fresh("tmp")
        # where the assignment goes: right before the statement, or at first use
        newexpr = copy.deepcopy(expr)
        gen = ctx.prog.gen
        text = gen.visit(expr)
        replace_all = rng.random() < 0.25
        set_child(p, a, k, c_ast.ID(name))
        if replace_all:
            for n2, p2, a2, k2 in list(walk(comp.block_items[i])):
                if p2 is not None and n2 is not expr and not isinstance(n2, c_ast.ID) and gen.visit(n2) == text \
                        and not (isinstance(p2, c_ast.Assignment) and a2 == "lvalue"):
                    set_child(p2, a2, k2, c_ast.ID(name))
        decl = mk_decl(name, t)
        assign = c_ast.Assignment("=", c_ast.ID(name), newexpr)
        top = ctx.fdef.body
        if rng.random() < 0.3 and comp is top:
            decl.init = newexpr
            comp.block_items.insert(i, decl)
        else:
            insert_decl(top, decl)
            comp.block_items.insert(i, assign)
        return "temp(%s=%s)" % (name, text[:24])


def insert_decl(comp, decl):
    """Insert a declaration after the last leading declaration of a block."""
    j = 0
    while j < len(comp.block_items) and isinstance(comp.block_items[j], c_ast.Decl):
        j += 1
    comp.block_items.insert(j, decl)


@mutation("expand", 20)
class ExpandExpr:
    """Substitute a local's single assignment into its later uses in the same block
    (removes a value; the reverse of temp)."""
    @staticmethod
    def sites(ctx):
        out = []
        for comp, i in stmt_slots(ctx.fdef):
            st = comp.block_items[i]
            if isinstance(st, c_ast.Assignment) and st.op == "=" and isinstance(st.lvalue, c_ast.ID) \
                    and not has_call(st.rvalue) and not any(isinstance(n, c_ast.Assignment) for n, _, _, _ in walk(st.rvalue)):
                out.append((comp, i))
            if isinstance(st, c_ast.Decl) and st.init is not None and not has_call(st.init) and st.name:
                out.append((comp, i))
        return out

    @staticmethod
    def apply(ctx, site, rng):
        comp, i = site
        st = comp.block_items[i]
        name = st.lvalue.name if isinstance(st, c_ast.Assignment) else st.name
        rhs = st.rvalue if isinstance(st, c_ast.Assignment) else st.init
        if name in ctx.addr_taken or (ids_of(rhs) & ctx.addr_taken):
            return None
        deps = ids_of(rhs) | {"*mem"} if reads_of(rhs) & {"*mem"} else ids_of(rhs)
        # walk following statements; substitute uses until name or a dep is written
        done = 0
        for j in range(i + 1, len(comp.block_items)):
            s2 = comp.block_items[j]
            w = writes_of(s2)
            for n, p, a, k in list(walk(s2)):
                if isinstance(n, c_ast.ID) and n.name == name and p is not None and \
                        not (isinstance(p, c_ast.Assignment) and a == "lvalue") and not (isinstance(p, c_ast.UnaryOp) and p.op in ("&", "p++", "p--", "++", "--")):
                    set_child(p, a, k, copy.deepcopy(rhs))
                    done += 1
            if name in w or "*" in w or (w & deps):
                break
        if not done:
            return None
        if rng.random() < 0.5:
            # keep the original assignment only if the variable is still used somewhere
            still = any(isinstance(n, c_ast.ID) and n.name == name for n, _, _, _ in walk(ctx.fdef.body)
                        if n is not st)
            if not still and isinstance(st, c_ast.Assignment):
                del comp.block_items[i]
        return "expand(%s x%d)" % (name, done)


@mutation("reorder", 12)
class ReorderStmts:
    """Move a statement earlier or later in its block when nothing between depends on it:
    changes first-definition order, hence value numbering."""
    @staticmethod
    def sites(ctx):
        return [s for s in stmt_slots(ctx.fdef) if not isinstance(s[0].block_items[s[1]], c_ast.Decl)]

    @staticmethod
    def apply(ctx, site, rng):
        comp, i = site
        items = comp.block_items
        st = items[i]
        if isinstance(st, (c_ast.Label, c_ast.Case, c_ast.Default, c_ast.Return, c_ast.Goto, c_ast.Break, c_ast.Continue)):
            return None
        d = rng.choice((-3, -2, -1, -1, 1, 1, 2, 3))
        j = i
        step = 1 if d > 0 else -1
        for _ in range(abs(d)):
            nj = j + step
            if nj < 0 or nj >= len(items):
                break
            other = items[nj]
            if isinstance(other, (c_ast.Decl, c_ast.Label, c_ast.Case, c_ast.Default, c_ast.Return, c_ast.Goto, c_ast.Break, c_ast.Continue)):
                break
            if not independent(st, other):
                break
            j = nj
        if j == i:
            return None
        del items[i]
        items.insert(j, st)
        return "reorder(%+d)" % (j - i)


@mutation("hoist", 15)
class HoistLoad:
    """Move a local's memory-read assignment to the top of its block (definition early,
    long live range) or down to just before its first use (definition late)."""
    @staticmethod
    def sites(ctx):
        out = []
        for comp, i in stmt_slots(ctx.fdef):
            st = comp.block_items[i]
            if isinstance(st, c_ast.Assignment) and st.op == "=" and isinstance(st.lvalue, c_ast.ID) and not has_call(st.rvalue):
                out.append((comp, i))
        return out

    @staticmethod
    def apply(ctx, site, rng):
        comp, i = site
        items = comp.block_items
        st = items[i]
        name = st.lvalue.name
        if rng.random() < 0.5:
            # hoist: move up past independent statements to the earliest legal slot
            j = i
            while j > 0 and not isinstance(items[j - 1], (c_ast.Decl, c_ast.Label, c_ast.Case, c_ast.Default)) and independent(st, items[j - 1]):
                j -= 1
            how = "up"
        else:
            j = i
            while j + 1 < len(items) and name not in reads_of(items[j + 1]) and name not in writes_of(items[j + 1]) \
                    and independent(st, items[j + 1]) and not isinstance(items[j + 1], (c_ast.Label, c_ast.Case, c_ast.Default, c_ast.Return, c_ast.Goto)):
                j += 1
            how = "down"
        if j == i:
            return None
        del items[i]
        items.insert(j, st)
        return "hoist-%s(%s,%+d)" % (how, name, j - i)


@mutation("copy", 15)
class CopySplit:
    """Split a live range: after a point, refer to a fresh copy of the variable.  Adds a
    coalescable copy and a second value with its own definition (the 'r5/r6 swapped'
    residue is usually one of these)."""
    @staticmethod
    def sites(ctx):
        out = []
        for name, d in ctx.locals.items():
            if is_simple_type(d.type) or isinstance(d.type, c_ast.PtrDecl):
                out.append(name)
        for name, d in ctx.params.items():
            if is_simple_type(d.type) or isinstance(d.type, c_ast.PtrDecl):
                out.append(name)
        return out

    @staticmethod
    def apply(ctx, site, rng):
        name = site
        if name in ctx.addr_taken:
            return None   # a callee may write it through the pointer; a copy would go stale
        d = ctx.locals.get(name) or ctx.params.get(name)
        # find statements (in the top block only, to keep the rename well defined) that use it
        top = ctx.fdef.body
        uses = [i for i, st in enumerate(top.block_items) if name in ids_of(st) and not isinstance(st, c_ast.Decl)]
        if len(uses) < 2:
            return None
        cut = rng.choice(uses[1:])
        # every write to name after cut would break the copy; require none
        for st in top.block_items[cut:]:
            if name in writes_of(st):
                return None
        new = ctx.fresh(name + "_")
        for st in top.block_items[cut:]:
            for n, p, a, k in list(walk(st)):
                if isinstance(n, c_ast.ID) and n.name == name and p is not None:
                    set_child(p, a, k, c_ast.ID(new))
        insert_decl(top, mk_decl(new, d.type))
        top.block_items.insert(cut, c_ast.Assignment("=", c_ast.ID(new), c_ast.ID(name)))
        return "copy(%s->%s@%d)" % (name, new, cut)


@mutation("use", 10)
class AddUse:
    """Add a dead read of a variable (`if (x) {}`): raises its spill cost, which changes
    who gets spilled and the colouring order."""
    @staticmethod
    def sites(ctx):
        names = [n for n, d in ctx.locals.items() if is_simple_type(d.type) or isinstance(d.type, c_ast.PtrDecl)]
        names += [n for n, d in ctx.params.items() if is_simple_type(d.type) or isinstance(d.type, c_ast.PtrDecl)]
        return [(s, n) for s in stmt_slots(ctx.fdef) for n in names]

    @staticmethod
    def apply(ctx, site, rng):
        (comp, i), name = site
        if isinstance(comp.block_items[i], c_ast.Decl):
            return None
        comp.block_items.insert(i, c_ast.If(c_ast.ID(name), c_ast.Compound([]), None))
        return "use(%s)" % name


@mutation("selfassign", 5)
class SelfAssign:
    """`x = x;` adds a definition (changes spill cost and value numbering)."""
    @staticmethod
    def sites(ctx):
        names = [n for n, d in ctx.locals.items() if is_simple_type(d.type) or isinstance(d.type, c_ast.PtrDecl)]
        return [(s, n) for s in stmt_slots(ctx.fdef) for n in names]

    @staticmethod
    def apply(ctx, site, rng):
        (comp, i), name = site
        if isinstance(comp.block_items[i], c_ast.Decl):
            return None
        comp.block_items.insert(i, c_ast.Assignment("=", c_ast.ID(name), c_ast.ID(name)))
        return "selfassign(%s)" % name


@mutation("decl-order", 10)
class ReorderDecls:
    """Permute the leading declarations of a block (stack slot order; with an
    initialiser, definition order too)."""
    @staticmethod
    def sites(ctx):
        return [c for c in compounds(ctx.fdef) if sum(1 for s in c.block_items if isinstance(s, c_ast.Decl)) >= 2]

    @staticmethod
    def apply(ctx, site, rng):
        comp = site
        idx = [i for i, s in enumerate(comp.block_items) if isinstance(s, c_ast.Decl)]
        if len(idx) < 2:
            return None
        a, b = rng.sample(idx, 2)
        da, db = comp.block_items[a], comp.block_items[b]
        if (da.init is not None or db.init is not None) and not independent(da, db):
            return None
        comp.block_items[a], comp.block_items[b] = db, da
        return "decl-order(%s<->%s)" % (da.name, db.name)


@mutation("split-assign", 10)
class SplitAssignment:
    """`a = b op c` -> `a = b; a = a op c` (two definitions, one fewer temp)."""
    @staticmethod
    def sites(ctx):
        out = []
        for comp, i in stmt_slots(ctx.fdef):
            st = comp.block_items[i]
            if isinstance(st, c_ast.Assignment) and st.op == "=" and isinstance(st.lvalue, c_ast.ID) \
                    and isinstance(st.rvalue, c_ast.BinaryOp) and st.lvalue.name not in ids_of(st.rvalue.right):
                out.append((comp, i))
        return out

    @staticmethod
    def apply(ctx, site, rng):
        comp, i = site
        st = comp.block_items[i]
        name = st.lvalue.name
        first = c_ast.Assignment("=", c_ast.ID(name), st.rvalue.left)
        second = c_ast.Assignment("=", c_ast.ID(name), c_ast.BinaryOp(st.rvalue.op, c_ast.ID(name), st.rvalue.right))
        comp.block_items[i:i + 1] = [first, second]
        return "split-assign(%s)" % name


@mutation("compound", 3)
class CompoundAssign:
    """`x = x op y` <-> `x op= y`."""
    @staticmethod
    def sites(ctx):
        out = []
        for comp, i in stmt_slots(ctx.fdef):
            st = comp.block_items[i]
            if isinstance(st, c_ast.Assignment) and isinstance(st.lvalue, c_ast.ID):
                if st.op != "=" or (isinstance(st.rvalue, c_ast.BinaryOp) and isinstance(st.rvalue.left, c_ast.ID)
                                    and st.rvalue.left.name == st.lvalue.name and st.rvalue.op in "+-*&|^" + "<<>>"):
                    out.append((comp, i))
        return out

    @staticmethod
    def apply(ctx, site, rng):
        comp, i = site
        st = comp.block_items[i]
        if st.op == "=":
            st.op = st.rvalue.op + "="
            st.rvalue = st.rvalue.right
        else:
            st.rvalue = c_ast.BinaryOp(st.op[:-1], c_ast.ID(st.lvalue.name), st.rvalue)
            st.op = "="
        return "compound(%s)" % st.lvalue.name


@mutation("commute", 6)
class Commute:
    """Swap the operands of a commutative operator (operand order sets which value the
    IR creates first)."""
    @staticmethod
    def sites(ctx):
        return expr_sites(ctx, lambda n: isinstance(n, c_ast.BinaryOp) and n.op in ("+", "*", "&", "|", "^", "==", "!="))

    @staticmethod
    def apply(ctx, site, rng):
        p, a, k, e, comp, i = site
        if has_call(e.left) and has_call(e.right):
            return None
        e.left, e.right = e.right, e.left
        return "commute(%s)" % e.op


@mutation("compare", 5)
class Compare:
    """`a < b` <-> `b > a`, `a <= b` <-> `a < b + 1` for constants, `if (x)` <-> `if (x != 0)`."""
    @staticmethod
    def sites(ctx):
        return expr_sites(ctx, lambda n: isinstance(n, c_ast.BinaryOp) and n.op in ("<", ">", "<=", ">=")) + \
            [(n, "cond", None, n.cond, comp, i) for (_, _, _, n, comp, i) in expr_sites(ctx, lambda n: isinstance(n, (c_ast.If, c_ast.While, c_ast.DoWhile)))
             if getattr(n, "cond", None) is not None]

    @staticmethod
    def apply(ctx, site, rng):
        p, a, k, e, comp, i = site
        if isinstance(e, c_ast.BinaryOp) and e.op in ("<", ">", "<=", ">="):
            flip = {"<": ">", ">": "<", "<=": ">=", ">=": "<="}
            cv = const_val(e.right)
            if cv is not None and rng.random() < 0.5 and e.op in ("<=", ">=", "<", ">"):
                nxt = {"<=": ("<", cv + 1), ">=": (">", cv - 1), "<": ("<=", cv - 1), ">": (">=", cv + 1)}[e.op]
                e.op = nxt[0]
                e.right = const(nxt[1])
                return "compare(const)"
            e.op = flip[e.op]
            e.left, e.right = e.right, e.left
            return "compare(flip)"
        if isinstance(e, c_ast.BinaryOp) and e.op == "!=" and const_val(e.right) == 0:
            set_child(p, a, k, e.left)
            return "compare(!=0 drop)"
        if isinstance(e, c_ast.UnaryOp) and e.op == "!":
            set_child(p, a, k, c_ast.BinaryOp("==", e.expr, const(0)))
            return "compare(!->==0)"
        if not isinstance(e, c_ast.BinaryOp) or e.op not in ("<", ">", "<=", ">=", "==", "!=", "&&", "||"):
            set_child(p, a, k, c_ast.BinaryOp("!=", e, const(0)))
            return "compare(!=0 add)"
        return None


@mutation("addsub", 4)
class AddSub:
    """`a - c` <-> `a + (-c)` for constants."""
    @staticmethod
    def sites(ctx):
        return expr_sites(ctx, lambda n: isinstance(n, c_ast.BinaryOp) and n.op in ("+", "-") and const_val(n.right) is not None)

    @staticmethod
    def apply(ctx, site, rng):
        p, a, k, e, comp, i = site
        cv = const_val(e.right)
        if cv is None or cv == 0:
            return None
        e.op = "-" if e.op == "+" else "+"
        e.right = const(-cv) if cv > 0 else const(-cv)
        if e.right.value.startswith("-"):
            e.right = c_ast.UnaryOp("-", const(-cv))
        return "addsub"


@mutation("cast", 8)
class CastSimple:
    """Wrap an integer expression in a cast to its own width or to int."""
    @staticmethod
    def sites(ctx):
        return [s + (t,) for s in expr_sites(ctx, lambda n: isinstance(n, (c_ast.ID, c_ast.StructRef, c_ast.ArrayRef, c_ast.BinaryOp)))
                for t in ("self", "int", "u32", "s32")]

    @staticmethod
    def apply(ctx, site, rng):
        p, a, k, e, comp, i, target = site
        if isinstance(p, c_ast.Assignment) and a == "lvalue":
            return None
        if isinstance(p, c_ast.UnaryOp) and p.op in ("&", "p++", "p--", "++", "--"):
            return None
        t = ctx.type_of(e)
        tn = type_name(t) if t is not None else None
        if tn is None or tn.endswith("*"):
            return None
        if target == "self":
            target = tn
        set_child(p, a, k, c_ast.Cast(c_ast.Typename(None, [], None, mk_type(target)), e))
        return "cast(%s)" % target


@mutation("block", 6)
class InsBlock:
    """Wrap a run of statements in `if (1) {}` or `do {} while (0)`: changes the
    optimiser's block structure without changing the program."""
    @staticmethod
    def sites(ctx):
        return [s for s in stmt_slots(ctx.fdef) if not isinstance(s[0].block_items[s[1]], c_ast.Decl)]

    @staticmethod
    def apply(ctx, site, rng):
        comp, i = site
        items = comp.block_items
        n = rng.randint(1, min(4, len(items) - i))
        run = items[i:i + n]
        if any(isinstance(s, (c_ast.Decl, c_ast.Label, c_ast.Case, c_ast.Default)) for s in run):
            return None
        if rng.random() < 0.5:
            new = c_ast.If(const(1), c_ast.Compound(run), None)
            how = "if1"
        else:
            if any(isinstance(s, (c_ast.Break, c_ast.Continue)) for s2 in run for s, _, _, _ in walk(s2)):
                return None
            new = c_ast.DoWhile(const(0), c_ast.Compound(run))
            how = "do0"
        items[i:i + n] = [new]
        return "block(%s,%d)" % (how, n)


@mutation("pad", 2)
class PadDecl:
    """An unused local: mwcc keeps its stack slot, shifting every spill offset."""
    @staticmethod
    def sites(ctx):
        return [ctx.fdef.body]

    @staticmethod
    def apply(ctx, site, rng):
        name = ctx.fresh("pad")
        insert_decl(site, mk_decl(name, mk_type(rng.choice(("int", "u8", "u16")))))
        return "pad(%s)" % name


@mutation("volatile", 5)
class VolatileToggle:
    """Toggle volatile on a local or parameter (forces or releases a memory home)."""
    @staticmethod
    def sites(ctx):
        return [("l", n) for n in ctx.locals] + [("p", n) for n in ctx.params]

    @staticmethod
    def apply(ctx, site, rng):
        kind, name = site
        d = ctx.locals[name] if kind == "l" else ctx.params[name]
        inner = d.type
        while not isinstance(inner, c_ast.TypeDecl):
            if not hasattr(inner, "type"):
                return None
            inner = inner.type
        if "volatile" in inner.quals:
            inner.quals.remove("volatile")
            return "volatile-drop(%s)" % name
        inner.quals.append("volatile")
        return "volatile-add(%s)" % name


@mutation("addr", 3)
class AddressTake:
    """`(void)&x;` forces x to live in memory."""
    @staticmethod
    def sites(ctx):
        return [n for n, d in ctx.locals.items() if is_simple_type(d.type)]

    @staticmethod
    def apply(ctx, site, rng):
        name = site
        top = ctx.fdef.body
        j = 0
        while j < len(top.block_items) and isinstance(top.block_items[j], c_ast.Decl):
            j += 1
        top.block_items.insert(j, c_ast.Cast(c_ast.Typename(None, [], None, mk_type("void")), c_ast.UnaryOp("&", c_ast.ID(name))))
        return "addr(%s)" % name


@mutation("goto-ret", 5)
class GotoReturn:
    """An early `return;` becomes `goto` to a label before the closing brace (the image
    often keeps one exit block where mwcc would duplicate the epilogue)."""
    @staticmethod
    def sites(ctx):
        out = []
        for comp, i in stmt_slots(ctx.fdef):
            st = comp.block_items[i]
            if isinstance(st, c_ast.Return) and st.expr is None and comp is not ctx.fdef.body:
                out.append((comp, i))
        return out

    @staticmethod
    def apply(ctx, site, rng):
        comp, i = site
        top = ctx.fdef.body
        label = None
        for st in top.block_items:
            if isinstance(st, c_ast.Label) and st.name == "ret_exit":
                label = st
        if label is None:
            top.block_items.append(c_ast.Label("ret_exit", c_ast.Return(None)))
        comp.block_items[i] = c_ast.Goto("ret_exit")
        return "goto-ret"


@mutation("loop", 4)
class LoopForm:
    """`for` <-> `while` and `x++` <-> `x += 1` inside loop headers."""
    @staticmethod
    def sites(ctx):
        return [(n, p, a, k) for n, p, a, k in walk(ctx.fdef.body) if isinstance(n, (c_ast.For, c_ast.While)) and p is not None]

    @staticmethod
    def apply(ctx, site, rng):
        n, p, a, k = site
        if isinstance(n, c_ast.For):
            if n.init is not None and isinstance(n.init, c_ast.DeclList):
                return None
            body = n.stmt if isinstance(n.stmt, c_ast.Compound) else c_ast.Compound([n.stmt])
            if any(isinstance(s, c_ast.Continue) for s, _, _, _ in walk(body)):
                return None
            if n.next is not None:
                body.block_items = (body.block_items or []) + [n.next]
            w = c_ast.While(n.cond if n.cond is not None else const(1), body)
            if n.init is not None:
                set_child(p, a, k, c_ast.Compound([n.init, w]))
            else:
                set_child(p, a, k, w)
            return "loop(for->while)"
        return None


@mutation("struct-ref", 2)
class StructRefForm:
    """`p->f` <-> `(*p).f`."""
    @staticmethod
    def sites(ctx):
        return expr_sites(ctx, lambda n: isinstance(n, c_ast.StructRef))

    @staticmethod
    def apply(ctx, site, rng):
        p, a, k, e, comp, i = site
        if e.type == "->":
            e.type = "."
            e.name = c_ast.UnaryOp("*", e.name)
            return "struct-ref(->to.)"
        if isinstance(e.name, c_ast.UnaryOp) and e.name.op == "*":
            e.type = "->"
            e.name = e.name.expr
            return "struct-ref(.to->)"
        return None


@mutation("type", 8, unsafe=True)
class TypeChange:
    """Change a local's or parameter's integer type (width or signedness).  Not
    value-preserving in general; enabled with --types and labelled 'type:'."""
    TYPES = ("int", "u32", "s32", "u16", "s16", "u8", "s8")

    @staticmethod
    def sites(ctx):
        out = []
        for kind, table in (("l", ctx.locals), ("p", ctx.params)):
            for n, d in table.items():
                if is_simple_type(d.type) and type_name(d.type) in INT_TYPES:
                    out += [(kind, n, t) for t in TypeChange.TYPES if t != type_name(d.type)]
        return out

    @staticmethod
    def apply(ctx, site, rng):
        kind, name, new = site
        d = ctx.locals[name] if kind == "l" else ctx.params[name]
        cur = type_name(d.type)
        d.type.type.names = new.split()
        return "type:%s(%s:%s->%s)" % (kind, name, cur, new)


@mutation("ret-var", 6, unsafe=True)
class ReturnVar:
    """A void function returns one of its pointer or integer parameters or locals instead
    (the image keeps that value alive to the epilogue and colours around it).  A common
    reconstruction miss; signature change, so --types only."""
    @staticmethod
    def sites(ctx):
        rt = ctx.fdef.decl.type.type
        if not (is_simple_type(rt) and rt.type.names == ["void"]):
            return []
        names = [n for n, d in ctx.params.items() if is_simple_type(d.type) or isinstance(d.type, c_ast.PtrDecl)]
        names += [n for n, d in ctx.locals.items() if is_simple_type(d.type) or isinstance(d.type, c_ast.PtrDecl)]
        return names

    @staticmethod
    def apply(ctx, site, rng):
        name = site
        d = ctx.params.get(name) or ctx.locals.get(name)
        # return type = the variable's type
        newt = copy.deepcopy(d.type)
        inner = newt
        while not isinstance(inner, c_ast.TypeDecl):
            inner = inner.type
        inner.declname = ctx.fdef.decl.name
        ctx.fdef.decl.type.type = newt
        for n, p, a, k in list(walk(ctx.fdef.body)):
            if isinstance(n, c_ast.Return) and n.expr is None:
                n.expr = c_ast.ID(name)
        last = ctx.fdef.body.block_items[-1] if ctx.fdef.body.block_items else None
        if not isinstance(last, c_ast.Return):
            ctx.fdef.body.block_items.append(c_ast.Return(c_ast.ID(name)))
        return "type:ret-var(%s)" % name


def weighted_kinds(rng, allow_unsafe):
    kinds = [m for m in MUTATIONS if allow_unsafe or not m.unsafe]
    total = sum(m.weight for m in kinds)
    r = rng.random() * total
    for m in kinds:
        r -= m.weight
        if r <= 0:
            return m
    return kinds[-1]


def focus_ok(site, focus):
    if not focus:
        return True
    st = None
    if isinstance(site, tuple) and len(site) in (6, 7) and isinstance(site[4], c_ast.Compound):
        st = site[4].block_items[site[5]]
    elif isinstance(site, tuple) and len(site) == 2 and isinstance(site[0], c_ast.Compound):
        st = site[0].block_items[site[1]]
    elif isinstance(site, tuple) and len(site) == 2 and isinstance(site[0], tuple):
        return site[1] in focus
    elif isinstance(site, str):
        return site in focus
    elif isinstance(site, tuple) and len(site) in (2, 3) and site[0] in ("l", "p"):
        return site[1] in focus
    if st is None:
        return True
    return bool(ids_of(st) & focus)


def mutate(prog, fdef, rng, nmut, allow_unsafe, focus):
    """Apply nmut random mutations to a deep copy of fdef; returns (fdef, labels)."""
    fd = copy.deepcopy(fdef)
    labels = []
    tries = 0
    while len(labels) < nmut and tries < nmut * 12:
        tries += 1
        ctx = Ctx(prog, fd)
        kind = weighted_kinds(rng, allow_unsafe)
        sites = [s for s in kind.sites(ctx) if focus_ok(s, focus)]
        if not sites:
            continue
        site = rng.choice(sites)
        try:
            lab = kind.apply(ctx, site, rng)
        except Exception:
            lab = None
        if lab:
            labels.append(lab)
        else:
            fd = copy.deepcopy(fd) if lab is None and tries % 3 == 0 else fd
    return fd, labels


# ---------------------------------------------------------------------------
# scoring
# ---------------------------------------------------------------------------

RANK = {"EXACT": 0, "EXACT*": 0, "MATCH": 1, "MATCH*": 1, "DIFF": 2, "DIFF*": 2, "SIZE": 3, "SIZE*": 3}
P_REG, P_INS, P_DEL = 5, 100, 100


def disasm(data, thumb):
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB if thumb else capstone.CS_MODE_ARM)
    md.skipdata = True
    return [(i.mnemonic, i.op_str) for i in md.disasm(bytes(data), 0)]


def asm_score(comp_bytes, mask, tgt_bytes, thumb):
    """decomp-permuter style: align mnemonics; equal mnemonic with different operands costs
    P_REG per differing operand, inserted/deleted instructions cost P_INS/P_DEL."""
    cb = bytearray(comp_bytes)
    tb = bytearray(tgt_bytes)
    n = min(len(cb), len(tb))
    for i in range(n):
        if not mask[i]:
            tb[i] = cb[i]   # wildcarded relocation field: never a difference
    a = disasm(cb, thumb)
    b = disasm(tb, thumb)
    sm = difflib.SequenceMatcher(a=[x[0] for x in a], b=[x[0] for x in b], autojunk=False)
    score = 0
    regdiff = {}
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "equal":
            for x, y in zip(a[i1:i2], b[j1:j2]):
                if x[1] != y[1]:
                    fa, fb = [f.strip() for f in x[1].split(",")], [f.strip() for f in y[1].split(",")]
                    for p, q in zip(fa, fb):
                        if p != q:
                            score += P_REG
                            if re.fullmatch(r"(r\d+|sp|lr|ip|fp|sb|sl)", p) and re.fullmatch(r"(r\d+|sp|lr|ip|fp|sb|sl)", q):
                                regdiff[(q, p)] = regdiff.get((q, p), 0) + 1
                    score += P_REG * abs(len(fa) - len(fb))
        elif tag == "replace":
            score += P_REG * 2 * max(i2 - i1, j2 - j1) + P_INS * abs((i2 - i1) - (j2 - j1))
        elif tag == "insert":
            score += P_INS * (j2 - j1)
        elif tag == "delete":
            score += P_DEL * (i2 - i1)
    return score, regdiff


class Score:
    __slots__ = ("status", "miss", "asm", "size", "tsize", "wild", "note", "regdiff")

    def __init__(self, status, miss, asm, size, tsize, wild=(), note="", regdiff=None):
        self.status, self.miss, self.asm, self.size, self.tsize = status, miss, asm, size, tsize
        self.wild, self.note, self.regdiff = list(wild), note, regdiff or {}

    def key(self):
        # a variant that resolves fewer relocation sites is worse whatever its bytes say
        if self.size == self.tsize and self.status.startswith("DIFF"):
            return (RANK.get(self.status, 9), len(self.wild), 0, self.miss, self.asm)
        return (RANK.get(self.status, 9), len(self.wild), 1, self.asm, self.miss, abs(self.size - self.tsize))

    def done(self):
        return self.status in ("EXACT", "EXACT*", "MATCH", "MATCH*")

    def __str__(self):
        s = "%-6s asm=%-5d bytes-out=%-4d size=%d/%d" % (self.status, self.asm, self.miss, self.size, self.tsize)
        if self.wild:
            s += "  unresolved=%d" % len(self.wild)
        if self.note:
            s += "  " + self.note[:60]
        return s


class Scorer:
    """Compile-and-compare with a content-addressed cache.

    Variants are compiled in BATCHES: mwccarm accepts many source files per invocation and
    the cost is almost all process start-up under wine, so one start serves up to
    BATCH variants (measured: 8 files in 0.34 s against 0.33 s for one).  Each batch gets
    its own temp dir; the post-compile steps mirror match.run_one() exactly.
    """
    BATCH = 16

    def __init__(self, cfg):
        self.cfg = cfg
        self.cache = {}
        self.lock = threading.Lock()
        self.compiles = 0
        self.decls = match.declared_symbols(match.read_header(cfg["src"]))
        self.srckey = match.source_key(cfg["src"])
        self.reg = match.find_region(cfg["addr"], cfg["region"])
        self.tsize, self.tthumb = match.target_extent(cfg["addr"], self.reg.name)

    def score(self, text):
        return self.score_many([text])[0]

    def score_many(self, texts):
        keys = [hashlib.sha1(t.encode("utf-8")).hexdigest() for t in texts]
        with self.lock:
            todo = {k: t for k, t in zip(keys, texts) if k not in self.cache}
        items = list(todo.items())
        chunks = [items[i:i + self.BATCH] for i in range(0, len(items), self.BATCH)]
        if chunks:
            with ThreadPoolExecutor(max(1, min(len(chunks), self.cfg.get("jobs", 4)))) as ex:
                for res in ex.map(self._compile_batch, chunks):
                    with self.lock:
                        self.cache.update(res)
                        self.compiles += len(res)
        with self.lock:
            return [self.cache[k] for k in keys]

    def _compile_batch(self, items):
        c = self.cfg
        d = os.path.join(c["tmp"], items[0][0][:12])
        os.makedirs(d, exist_ok=True)
        paths = []
        for k, t in items:
            pth = os.path.join(d, "v_%s.c" % k[:12])
            with open(pth, "w") as fh:
                fh.write(t)
            paths.append(pth)
        exe = match.compiler_path(c["cc"])
        cmd = [exe] + list(match.BASE_FLAGS) + list(c["flags"])
        if c["thumb"]:
            cmd += ["-thumb"]
        if c["lang"]:
            cmd += ["-lang", c["lang"]]
        cmd += ["-nofail", "-ir", d]     # keep going past a file with errors
        if c["sdk_include"] and os.path.isdir(match.SDK_INCLUDE):
            cmd += ["-I+" + match.SDK_INCLUDE]
        cmd += ["-c"]
        env = dict(os.environ)
        env.setdefault("MWLibraries", d)
        env.setdefault("MWLibraryFiles", " ")
        env.setdefault("WINEDEBUG", "-all")
        env.setdefault("WINEDLLOVERRIDES", "mscoree,mshtml=")
        if sys.platform != "win32" and exe.endswith(".exe"):
            import shutil
            cmd = [shutil.which("wine64") or shutil.which("wine") or "wine64"] + cmd
        out = {}
        pending = list(zip(items, paths))
        t0 = time.time()
        # mwccarm aborts the whole invocation at the first file with an error, so the files
        # after it get no object: mark the culprit CCERR and re-run the survivors
        while pending:
            files = [pth for _, pth in pending]
            try:
                p = subprocess.run(cmd + files, cwd=d, capture_output=True, timeout=300, env=env)
                log = (p.stdout + b"\n" + p.stderr).decode("latin1", "replace")
            except Exception as exc:
                log = str(exc)
            rest = []
            culprit_seen = False
            for (k, t), pth in pending:
                obj = pth[:-2] + ".o"
                if os.path.exists(obj):
                    try:
                        out[k] = self._post(obj, pth)
                    except Exception as exc:
                        out[k] = Score("CCERR", 10 ** 6, 10 ** 9, 0, 0, note=str(exc)[:120])
                elif not culprit_seen:
                    culprit_seen = True
                    base = os.path.basename(pth)
                    err = next((ln.strip() for ln in log.split("\n") if base in ln), None)
                    out[k] = Score("CCERR", 10 ** 6, 10 ** 9, 0, 0, note=err or match.first_line(log))
                else:
                    rest.append(((k, t), pth))
            if len(rest) == len(pending):   # no progress at all: give up on the rest
                for (k, t), pth in rest:
                    out[k] = Score("CCERR", 10 ** 6, 10 ** 9, 0, 0, note=match.first_line(log))
                break
            pending = rest
        dt = time.time() - t0
        if dt > 30:
            print("  [warn] a batch of %d compiles took %.0fs" % (len(items), dt), flush=True)
        return out

    def _post(self, obj, srcpath):
        """The post-compile half of match.run_one()."""
        c = self.cfg
        fb = match.extract_function(obj, c["func"], prefer_thumb=c["thumb"])
        n = len(fb.data)
        match.resolve_relocations(fb, c["addr"], self.decls, src=self.srckey)
        _, tgt = match.target_bytes(c["addr"], n, region=self.reg.name)
        status, diffs = match.compare(fb, tgt)
        note = ""
        if self.tsize is not None and self.tsize != n:
            note = "listing says the original is %d bytes, compiled %d" % (self.tsize, n)
            if status in ("EXACT", "MATCH"):
                status += "*"
        if self.tthumb is not None and self.tthumb != fb.thumb:
            status = "ISA"
        tsize = self.tsize or n
        try:
            _, tgt_full = match.target_bytes(c["addr"], tsize, region=self.reg.name)
        except Exception:
            tgt_full = tgt
        asm, regdiff = asm_score(fb.data, fb.mask, tgt_full, fb.thumb)
        wild = [s.describe() for s in fb.sites if not s.resolved]
        miss = len(diffs) if status.startswith("DIFF") else 0
        return Score(status, miss, asm, n, tsize, wild, note, regdiff)


# ---------------------------------------------------------------------------
# search
# ---------------------------------------------------------------------------

class Variant:
    __slots__ = ("fdef", "labels", "score", "text")

    def __init__(self, fdef, labels, score, text):
        self.fdef, self.labels, self.score, self.text = fdef, labels, score, text


def evaluate(prog, scorer, plans, jobs):
    """plans: list of (fdef, labels). Compile in parallel; return Variants."""
    texts = [prog.render(fd) for fd, _ in plans]
    scores = scorer.score_many(texts)
    return [Variant(fd, labels, sc, t) for (fd, labels), sc, t in zip(plans, scores, texts)]


def search(prog, scorer, args, rng, log):
    base_fd = prog.funcdef()
    base = evaluate(prog, scorer, [(base_fd, [])], 1)[0]
    log("baseline  %s" % base.score)
    if base.score.status == "CCERR":
        log("the regenerated baseline does not compile; the parser lost something (see --out)")
        return [base]
    if base.score.done():
        return [base]
    focus = set(args.focus.split(",")) if args.focus else set()
    elite = [base]           # best distinct variants, sorted by key
    seen = {hashlib.sha1(base.text.encode()).hexdigest()}
    cur = base
    stall = 0
    dry = 0
    nb = 0
    t0 = time.time()
    while scorer.compiles < args.budget:
        plans = []
        for _ in range(max(args.jobs, 1) * Scorer.BATCH // 2):
            if scorer.compiles + len(plans) >= args.budget:
                break
            # parent: mostly the current point; sometimes another elite; rarely the base
            r = rng.random()
            parent = cur if r < 0.7 else (rng.choice(elite) if r < 0.95 else base)
            temp = 1 + int(stall > 8) + int(stall > 20)      # broaden when stuck
            nmut = rng.choice([1] * 4 + [2] * 2 + [3]) if temp == 1 else rng.choice([1, 2, 2, 3, 3, 4])
            fd, labels = mutate(prog, parent.fdef, rng, nmut, args.types, focus)
            if not labels:
                continue
            plans.append((fd, parent.labels + labels))
        if not plans:
            log("no applicable mutations left")
            break
        cap = int(len(base.text) * 1.5) + 400
        rendered = [(pl, prog.render(pl[0])) for pl in plans]
        plans = [pl for pl, txt in rendered if len(txt) <= cap and hashlib.sha1(txt.encode()).hexdigest() not in seen]
        if not plans:
            dry += 1
            if dry > 30:
                log("search space exhausted (%d distinct variants)" % len(seen))
                break
            continue
        dry = 0
        vs = evaluate(prog, scorer, plans, args.jobs)
        improved = False
        for v in vs:
            h = hashlib.sha1(v.text.encode()).hexdigest()
            if h in seen:
                continue
            seen.add(h)
            if v.score.key() < cur.score.key():
                cur = v
                improved = True
                log("  %5d  %s  <- %s" % (scorer.compiles, v.score, " ; ".join(v.labels[-4:])))
            if v.score.status != "CCERR":
                elite.append(v)
        elite.sort(key=lambda x: x.score.key())
        del elite[12:]
        nb += 1
        if nb % 5 == 0 or improved:
            log("  [%4.0fs] compiles=%-5d batch=%-2d distinct=%-5d stall=%-3d cur=%s | best=%s" % (
                time.time() - t0, scorer.compiles, len(vs), len(seen), stall, cur.score, elite[0].score))
        if improved:
            stall = 0
        else:
            stall += 1
            if stall > 0 and stall % 15 == 0:
                # drift: continue from a random elite member so the walk does not sit on one point
                cur = rng.choice(elite[:6])
                log("  %5d  plateau, drifting to  %s" % (scorer.compiles, cur.score))
        if cur.score.done():
            break
    log("compiles %d in %.0fs" % (scorer.compiles, time.time() - t0))
    elite.sort(key=lambda x: x.score.key())
    return elite


def search_hill(prog, scorer, args, rng, log):
    """Exhaust every single mutation site of every kind from the current best, accept the
    best improvement, repeat.  Deterministic and complete for small functions."""
    base = evaluate(prog, scorer, [(prog.funcdef(), [])], 1)[0]
    log("baseline  %s" % base.score)
    if base.score.status == "CCERR" or base.score.done():
        return [base]
    focus = set(args.focus.split(",")) if args.focus else set()
    cur = base
    elite = [base]
    while scorer.compiles < args.budget:
        plans = []
        for kind in MUTATIONS:
            if kind.unsafe and not args.types:
                continue
            ctx = Ctx(prog, cur.fdef)
            sites = [s for s in kind.sites(ctx) if focus_ok(s, focus)]
            rng.shuffle(sites)
            seen_txt = set()
            for si, site in enumerate(sites[:40]):
                # a site can have several variants (random choices inside apply): try a few
                for draw in range(4):
                    fd = copy.deepcopy(cur.fdef)
                    c2 = Ctx(prog, fd)
                    sites2 = [s for s in kind.sites(c2) if focus_ok(s, focus)]
                    if si >= len(sites2):
                        break
                    try:
                        lab = kind.apply(c2, sites2[si], random.Random(rng.random()))
                    except Exception:
                        lab = None
                    if not lab:
                        continue
                    txt = prog.render(fd)
                    if txt in seen_txt:
                        continue
                    seen_txt.add(txt)
                    plans.append((fd, cur.labels + [lab]))
        if not plans:
            break
        plans = plans[:max(1, args.budget - scorer.compiles)]
        vs = evaluate(prog, scorer, plans, args.jobs)
        vs = [v for v in vs if v.score.status != "CCERR"]
        elite += vs
        elite.sort(key=lambda x: x.score.key())
        del elite[12:]
        best = min(vs, key=lambda v: v.score.key()) if vs else None
        if best is None or best.score.key() >= cur.score.key():
            log("no single mutation improves %s (%d tried)" % (cur.score, len(plans)))
            break
        cur = best
        log("  %5d  %s  <- %s" % (scorer.compiles, cur.score, cur.labels[-1]))
        if cur.score.done():
            break
    return elite


# ---------------------------------------------------------------------------
# cli
# ---------------------------------------------------------------------------

def read_header(src):
    head = open(src, errors="replace").read(12000).split("*/", 1)[0]
    g = lambda k: (re.search(r"^ \* %s:\s+(\S+)" % k, head, re.M) or [None, None])[1]
    return dict(cc=g("compiler"), isa=g("isa"), lang=g("lang"), region=g("region"),
                flags=(re.search(r"^ \* flags:\s+(.*)$", head, re.M) or [None, None])[1])


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--src", required=True)
    ap.add_argument("--func", required=True)
    ap.add_argument("--addr", required=True)
    ap.add_argument("--thumb", action="store_true")
    ap.add_argument("--arm", action="store_true")
    ap.add_argument("--cc", default=None)
    ap.add_argument("--flags", default=None)
    ap.add_argument("--lang", default=None)
    ap.add_argument("--region", default=None)
    ap.add_argument("--no-sdk-include", action="store_true")
    ap.add_argument("--budget", type=int, default=200)
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--jobs", type=int, default=4)
    ap.add_argument("--mode", choices=("anneal", "hill", "random"), default="anneal")
    ap.add_argument("--out", default=None)
    ap.add_argument("--focus", default=None)
    ap.add_argument("--types", action="store_true")
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--explain", action="store_true")
    ap.add_argument("--quiet", action="store_true")
    args = ap.parse_args(argv)
    if args.thumb == args.arm:
        h = read_header(args.src)
        if h["isa"] in ("thumb", "arm"):
            args.thumb = h["isa"] == "thumb"
        else:
            sys.exit("permuter: pass --thumb or --arm")
    h = read_header(args.src)
    cc = args.cc or h["cc"] or "1.1p1"
    flags = args.flags or h["flags"] or "-O4,p"
    lang = args.lang or h["lang"]
    region = args.region or h["region"]
    text = open(args.src, encoding="utf-8", errors="replace").read()
    prog = Program(text, args.func)
    log = (lambda s: None) if args.quiet else (lambda s: print(s, flush=True))

    if args.list:
        ctx = Ctx(prog, copy.deepcopy(prog.funcdef()))
        for m in MUTATIONS:
            try:
                n = len(m.sites(ctx))
            except Exception:
                n = 0
            print("%-13s weight %3d  sites %4d%s" % (m.name, m.weight, n, "  (needs --types)" if m.unsafe else ""))
        return 0

    match.evidence()
    tmp = os.path.join("/tmp", "permuter-%d" % os.getpid())
    os.makedirs(tmp, exist_ok=True)
    cfg = dict(src=args.src, func=args.func, addr=int(args.addr, 0), cc=cc, flags=flags.split(), thumb=args.thumb, lang=lang,
               region=region, sdk_include=not args.no_sdk_include, tmp=tmp, jobs=args.jobs)
    scorer = Scorer(cfg)
    if args.explain:
        v = evaluate(prog, scorer, [(prog.funcdef(), [])], 1)[0]
        print("baseline  %s" % v.score)
        if v.score.regdiff:
            print("register substitutions (image -> compiled), by count:")
            for (q, p), n in sorted(v.score.regdiff.items(), key=lambda kv: -kv[1])[:16]:
                print("  %-4s -> %-4s  x%d" % (q, p, n))
        for w in v.score.wild:
            print("  unresolved: " + w)
        return 0
    rng = random.Random(args.seed)
    if args.mode == "hill":
        results = search_hill(prog, scorer, args, rng, log)
    else:
        results = search(prog, scorer, args, rng, log)
    best = results[0]
    print("best      %s" % best.score)
    if best.labels:
        print("mutations " + " ; ".join(best.labels))
    if args.out:
        with open(args.out, "w", encoding="utf-8") as fh:
            fh.write(best.text)
        print("wrote %s" % args.out)
    return 0 if best.score.done() else 1


if __name__ == "__main__":
    sys.exit(main())
