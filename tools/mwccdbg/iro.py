"""Front-end optimiser (IRO) inspection: CSE temps and IR dumps.

IRO works on a linear IR per block before CodeGen.  Compiler temps are
named "@N" by one unique-name generator (0x445730, counter at 0x62586A);
IRO_CommonSubs (0x595500) names its CSE temps through 0x595360, so the
creation order of the temps (which decides their spill slot order: a lower
@N gets a higher slot) can be traced to the CSE run and IR node that made
each one.

``cse_trace`` prints every CSE temp with its run number, node index and
expression.  ``name_trace`` prints every @N in a range with a heuristic
call chain.  ``dump`` prints the whole IR as expression trees at any
breakpoint hit (a named pass entry or an address).
"""
import struct

import common
import pe32

A_CSE = 0x595500              # IRO_CommonSubs entry
A_CSE_NAME = 0x595360         # CSE temp-naming routine (one call per CSE run)
A_CSE_CREATE = 0x595410       # inside it: ebp = IR node that gets a temp, esi = block
A_UNIQUE_NAME = 0x445730      # unique name generator for @N
G_NAME_COUNTER = 0x62586A     # u32: the N of the name being made
G_IRO_BLOCKS = 0x65B094       # first IRO block

B_FIRST, B_LAST, B_NEXT = 0x18, 0x1C, 0x38
N_KIND, N_TYPE, N_CSE, N_A, N_B, N_NEXT = 0x00, 0x01, 0x1A, 0x2A, 0x2E, 0x3E
NODE_SZ = 0x44
E_OBJ, E_INT = 0x18, 0x1C     # ENode: object (OBJREF), integer value (INTCONST)
T_INTCONST, T_OBJREF = 0x34, 0x3B

OPS = {0x04: "*", 0x09: "MUL", 0x0F: "ADD", 0x10: "SUB", 0x11: "SHL", 0x12: "SHR",
       0x32: "CAST"}

# Pass entry points, named as the research lanes read them from the dump
# labels and call graph.  ``ir --at`` and ``passes`` accept these names.
POINTS = {
    "looptop": (0x4FE76B, "top of the IRO pass loop"),
    "copyprop": (0x5834B0, "IRO copy propagation"),
    "exprprop": (0x583D20, "IRO expression propagation"),
    "dclt": (0x569480, "IRO_DoCommonLoopTransformations"),
    "mie": (0x59A670, "IRO_MoveInvariantExpressions"),
    "cse": (A_CSE, "IRO_CommonSubs"),
    "csename": (A_CSE_NAME, "CSE temp naming (one call per CSE run)"),
    "sr": (0x5B40D0, "IRO strength reduction"),
    "dotransf": (0x58CD00, "IRO transformation driver"),
    "after-cse1": (0x4FEBB5, "in the IRO loop, right after the first CSE run"),
}


def point(spec):
    """(address, label) for a point name or a hex address."""
    if spec.lower() in POINTS:
        return POINTS[spec.lower()][0], spec.lower()
    try:
        return int(spec, 16), spec
    except ValueError:
        raise SystemExit("unknown point %r; names: %s" % (spec, ", ".join(sorted(POINTS))))


def walk(d):
    """[(block index, node ptr, raw bytes)] for the whole IRO linear IR."""
    out = []
    b = d.u32(G_IRO_BLOCKS)
    bi = 0
    while b:
        x, last = d.u32(b + B_FIRST), d.u32(b + B_LAST)
        while x:
            out.append((bi, x, d.read(x, NODE_SZ)))
            if x == last:
                break
            x = d.u32(x + N_NEXT)
        b = d.u32(b + B_NEXT)
        bi += 1
    return out


class Expr:
    """Expression text of IR nodes, with names cached."""

    def __init__(self, names):
        self.names = names

    def leaf(self, d, raw):
        typ = raw[N_TYPE]
        a = struct.unpack_from("<I", raw, N_A)[0]
        try:
            e = d.read(a, 0x20)
        except OSError:
            return "?"
        if typ == T_INTCONST:
            return "#%d" % struct.unpack_from("<i", e, E_INT)[0]
        ob = struct.unpack_from("<I", e, E_OBJ)[0]
        s = self.names.obj(d, ob) or "obj%x" % ob
        return "&" + s if typ == T_OBJREF else s

    def tree(self, d, x, depth=0):
        """Expression of node ``x`` read recursively from memory."""
        if depth > 12:
            return ".."
        raw = d.read(x, NODE_SZ)
        kind, typ = raw[N_KIND], raw[N_TYPE]
        a, b = struct.unpack_from("<II", raw, N_A)
        op = OPS.get(typ, "op%02x" % typ)
        if kind == 1:
            return self.leaf(d, raw)
        if kind == 2:
            return "%s(%s)" % (op, self.tree(d, a, depth + 1))
        if kind == 3:
            return "%s(%s, %s)" % (op, self.tree(d, a, depth + 1), self.tree(d, b, depth + 1))
        return "t%d" % kind


def dump(settings, work, addr, hit=1, raw_words=False):
    """IR text at the ``hit``-th time the breakpoint at ``addr`` is reached."""
    names = common.Names()
    ex = Expr(names)
    state = {"n": 0, "lines": None}

    def on_hit(d, c):
        state["n"] += 1
        if state["n"] != hit:
            return
        nodes = walk(d)
        idx = {x: i for i, (_b, x, _r) in enumerate(nodes)}
        exprs = {}
        L = []
        for i, (bi, x, raw) in enumerate(nodes):
            kind, typ = raw[N_KIND], raw[N_TYPE]
            if raw_words:
                words = []
                for o in range(0x12, 0x3E, 4):
                    v = struct.unpack_from("<I", raw, o)[0]
                    words.append("N%d" % idx[v] if v in idx else "%x" % v)
                L.append("N%d B%d t%02x n%02x fl%s %s" % (i, bi, kind, typ, raw[2:6].hex(),
                                                        " ".join(words)))
                continue
            a, b = struct.unpack_from("<II", raw, N_A)
            cse = struct.unpack_from("<I", raw, N_CSE)[0]
            op = OPS.get(typ, "op%02x" % typ)
            if kind == 1:
                s = ex.leaf(d, raw)
            elif kind == 2:
                s = "%s(%s)" % (op, exprs.get(a, "N%s" % idx.get(a)))
            elif kind == 3:
                s = "%s(%s, %s)" % (op, exprs.get(a, "N%s" % idx.get(a)),
                                    exprs.get(b, "N%s" % idx.get(b)))
            else:
                s = "t%d n%02x" % (kind, typ)
            if len(s) > 160:
                s = "N%d" % i
            exprs[x] = s
            L.append("N%d B%d t%d %s%s  = %s" % (i, bi, kind, "CSE " if cse else "", op, s))
        state["lines"] = L

    common.run(settings, work, lambda d: d.bp(addr, on_hit))
    if state["lines"] is None:
        return "breakpoint reached %d time(s); hit %d never happened" % (state["n"], hit)
    return "\n".join(state["lines"])


def cse_trace(settings, work):
    """Every CSE temp as it is named: @N, CSE run, IR node index, expression."""
    ex = Expr(common.Names())
    st = {"run": 0, "pending": None}
    L = []

    def on_run(d, c):
        st["run"] += 1

    def on_create(d, c):
        node = c.ebp
        g = 0
        for _bi, x, _raw in walk(d):
            if x == node:
                break
            g += 1
        st["pending"] = "CSE run %d  node N%d  %s" % (st["run"], g, ex.tree(d, node)[:120])

    def on_name(d, c):
        if st["pending"]:
            L.append("@%d  %s" % (d.u32(G_NAME_COUNTER), st["pending"]))
            st["pending"] = None

    def install(d):
        d.bp(A_CSE_NAME, on_run)
        d.bp(A_CSE_CREATE, on_create)
        d.bp(A_UNIQUE_NAME, on_name)
    common.run(settings, work, install)
    L.append("%d CSE run(s), %d temp(s) named by CSE" % (st["run"], len(L)))
    return "\n".join(L)


def name_trace(settings, work, lo, hi, depth=14):
    """Every @N with lo <= N <= hi, with likely return addresses on the stack."""
    pe = pe32.PE(common.compiler_exe())
    _name, sva, vsz, _raw, _rsz = pe.text()

    def is_ret(v):
        if not (sva + 6 <= v < sva + vsz):
            return False
        b5 = pe.read(v - 5, 5)
        if b5[0] == 0xE8:                                   # call rel32
            return True
        b6 = pe.read(v - 6, 6)
        if b6[0] == 0xFF and (b6[1] & 0x38) == 0x10:        # call [mem32]
            return True
        b3 = pe.read(v - 3, 3)
        if b3[0] == 0xFF and (b3[1] & 0x38) == 0x10 and (b3[1] & 0xC0) == 0x40:  # call [reg+d8]
            return True
        b2 = pe.read(v - 2, 2)
        return b2[0] == 0xFF and (b2[1] & 0xF8) == 0xD0      # call reg
    L = []

    def on_name(d, c):
        n = d.u32(G_NAME_COUNTER)
        if not lo <= n <= hi:
            return
        chain = []
        stack = d.read(c.esp, 1600)
        for k in range(0, len(stack), 4):
            v = struct.unpack_from("<I", stack, k)[0] - d.delta
            if is_ret(v):
                chain.append("%x" % v)
                if len(chain) >= depth:
                    break
        L.append("@%d  %s" % (n, " ".join(chain)))
    common.run(settings, work, lambda d: d.bp(A_UNIQUE_NAME, on_name))
    return "\n".join(L)
