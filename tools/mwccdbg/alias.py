"""Alias objects and the scheduler's memory-dependence queries.

Every pcode memory instruction points at an alias object (AO) at insn+0x1C.
The scheduler's dependence builder asks, for each memory instruction, the
alias query 0x575070 against every earlier store (and, for stores, every
earlier load); a true answer becomes a DAG edge.  ``capture`` records, per
scheduled block, the instructions with their AOs, the global unknown-memory
set G, and every query with its answer.  ``force`` pairs make chosen queries
answer 1 (a run-time edit, used to prove which edge a residue needs).

``window`` mode instead logs the low-level predicate 0x574EF0 and its
wrappers between two breakpoints (for example around one CodeGen pass), to
see whether a pass asks alias questions at all.
"""
import common

A_BLOCK = 0x50D6A0            # per-block scheduler entry, [esp+4] = block
A_DAG_BUILT = 0x50D72F        # per-block scheduler: DAG complete
A_QUERY = 0x575070            # alias query, [esp+4] insn a, [esp+8] insn b
A_QUERY_RET = 0x575085        # alias query return, al = result
A_PRED = 0x574EF0             # AO predicate, [esp+4] AO a, [esp+8] AO b (3x3 kind table)
PRED_WRAPPERS = (0x575090, 0x575100, 0x575120, 0x5751D0, 0x574340, 0x575180)
G_UNKNOWN = 0x65C370          # AO of the global unknown-memory set

AO_OBJ, AO_OFF, AO_SIZE, AO_SET, AO_INDEX, AO_KIND = 0x14, 0x18, 0x1C, 0x28, 0x2C, 0x30
AO_KINDS = {0: "exact", 1: "obj+off", 2: "set"}
SET_WORDS = 8

INS_LOAD, INS_STORE, INS_VOLATILE = 0x2, 0x4, 0x80


def describe_ao(d, p, names):
    """One alias object as a dict (index, kind, object, offset, size, set bits)."""
    if not p:
        return None
    kind = d.u8(p + AO_KIND)
    obj = d.u32(p + AO_OBJ)
    out = {"index": d.s32(p + AO_INDEX), "kind": kind,
           "obj": names.obj(d, obj) or ("%08x" % obj if obj else None),
           "off": d.s32(p + AO_OFF), "size": d.s32(p + AO_SIZE)}
    if kind == 2:
        bs = d.u32(p + AO_SET)
        bits = []
        if bs:
            for w in range(SET_WORDS):
                v = d.u32(bs + 4 * w)
                bits += [w * 32 + b for b in range(32) if v >> b & 1]
        out["set"] = bits
    return out


def ao_text(a):
    if a is None:
        return "AO-"
    s = "AO%d %s" % (a["index"], AO_KINDS.get(a["kind"], "k%d" % a["kind"]))
    if a["kind"] == 2:
        s += " {%s}" % ranges(a.get("set", []))
    else:
        s += " %s off %d size %d" % (a["obj"], a["off"], a["size"])
    return s


def ranges(bits):
    out, i = [], 0
    while i < len(bits):
        j = i
        while j + 1 < len(bits) and bits[j + 1] == bits[j] + 1:
            j += 1
        out.append(str(bits[i]) if i == j else "%d..%d" % (bits[i], bits[j]))
        i = j + 1
    return ",".join(out)


def insn_kind(fl):
    s = []
    if fl & INS_LOAD:
        s.append("load")
    if fl & INS_STORE:
        s.append("store")
    if fl & INS_VOLATILE:
        s.append("volatile")
    return "/".join(s)


class BlockTracker:
    """Numbers scheduled blocks per (function, scheduler pass) and keeps the
    current block's instruction index.  Shared by alias, sched and edit."""

    def __init__(self, want=None):
        self.ft = common.FuncTracker(want)
        self.sp = common.SchedPass()
        self.counts = {}
        self.block = None        # (func, pass, index)
        self.ptr = None
        self.insns = []
        self.index = {}
        self.listeners = []

    def install(self, d):
        self.ft.install(d)
        self.sp.install(d)
        d.bp(A_BLOCK, self._on_block)

    def _on_block(self, d, c):
        if not self.ft.active():
            self.block = None
            return
        key = (self.ft.name, self.sp.label)
        n = self.counts.get(key, 0)
        self.counts[key] = n + 1
        self.block = (self.ft.name, self.sp.label, n)
        self.ptr = d.u32(c.esp + 4)
        self.insns = common.block_insns(d, self.ptr)
        self.index = {p: i for i, p in enumerate(self.insns)}
        for f in self.listeners:
            f(d, c)


class AliasTracer:
    def __init__(self, want=None, force=()):
        self.bt = BlockTracker(want)
        self.bt.listeners.append(self.on_block)
        self.names = common.Names()
        self.force = set(force)      # {(pass, block, i, j)} with i < j
        self.blocks = []
        self.cur = None
        self.pending = []
        self.forced = 0
        self.cur_open = False      # inside a block, before its DAG is complete

    def install(self, d):
        self.bt.install(d)
        d.bp(A_DAG_BUILT, lambda d, c: setattr(self, "cur_open", False))
        d.bp(A_QUERY, self.on_query)
        d.bp(A_QUERY_RET, self.on_query_ret)

    def on_block(self, d, c):
        func, pas, n = self.bt.block
        g = d.u32(G_UNKNOWN)
        rows = []
        for ins in self.bt.insns:
            fl = d.u32(ins + common.INS_FLAGS)
            ao = describe_ao(d, d.u32(ins + common.INS_ALIAS), self.names) if fl & 6 else None
            rows.append({"text": common.format_insn(d, ins, self.names), "flags": fl, "ao": ao})
        self.cur = {"func": func, "pass": pas, "block": n, "insns": rows,
                    "G": describe_ao(d, g, self.names) if g else None, "queries": []}
        self.cur_open = True
        self.blocks.append(self.cur)

    def on_query(self, d, c):
        self.pending.append((d.u32(c.esp + 4), d.u32(c.esp + 8)))

    def on_query_ret(self, d, c):
        if not self.pending:
            return
        a, b = self.pending.pop()
        if not self.cur_open or self.bt.block is None:
            return
        ia, ib = self.bt.index.get(a), self.bt.index.get(b)
        res = c.eax & 0xFF
        _f, pas, n = self.bt.block
        key = (pas, n) + tuple(sorted((ia, ib))) if ia is not None and ib is not None else None
        forced = False
        if key in self.force and not res:
            c.set("eax", (c.eax & ~0xFF) | 1)
            res, forced = 1, True
            self.forced += 1
        self.cur["queries"].append({"a": ia, "b": ib, "result": res, "forced": forced})


def report(blocks, min_insns=1):
    L = []
    for b in blocks:
        if len(b["insns"]) < min_insns:
            continue
        L.append("=" * 72)
        L.append("function %s  scheduler pass %s  block %d  (%d insns)" % (
            b["func"], b["pass"], b["block"], len(b["insns"])))
        if b["G"]:
            L.append("G (unknown memory) = %s" % ao_text(b["G"]))
        for i, r in enumerate(b["insns"]):
            extra = ""
            if r["ao"] is not None or r["flags"] & 6:
                extra = "   [%s] %s" % (insn_kind(r["flags"]), ao_text(r["ao"]))
            L.append("  %3d  %-44s%s" % (i, r["text"], extra))
        if b["queries"]:
            L.append("  alias queries (insn a, insn b -> may alias):")
            for q in b["queries"]:
                L.append("    I%s x I%s -> %d%s" % (q["a"], q["b"], q["result"],
                                                  "  FORCED" if q["forced"] else ""))
    return "\n".join(L)


def capture(settings, work, force=()):
    tr = AliasTracer(settings.func, force)
    common.run(settings, work, tr.install)
    return tr


def window_log(settings, work, w0, w1):
    """Predicate calls between breakpoints w0 (window on) and w1 (off)."""
    names = common.Names()
    state = {"on": False, "n": 0}
    L = []

    def ao_or_hex(d, x):
        try:
            if d.u8(x + AO_KIND) in (0, 1, 2):
                return ao_text(describe_ao(d, x, names))
        except OSError:
            pass
        return "%08x" % x

    def on(d, c):
        state["on"] = True
        L.append("@@ window on")

    def off(d, c):
        state["on"] = False
        L.append("@@ window off")

    def hook(addr):
        def f(d, c):
            if not state["on"]:
                return
            state["n"] += 1
            ra = d.u32(c.esp)
            a, b = d.u32(c.esp + 4), d.u32(c.esp + 8)
            if addr == A_PRED:
                L.append("  predicate from %x: %s | %s" % (ra, ao_or_hex(d, a), ao_or_hex(d, b)))
            else:
                L.append("  %x from %x: %08x %08x" % (addr, ra, a, b))
        return f

    def install(d):
        d.bp(w0, on)
        d.bp(w1, off)
        for a in (A_PRED,) + PRED_WRAPPERS:
            d.bp(a, hook(a))
    common.run(settings, work, install)
    L.append("%d predicate call(s) inside the window" % state["n"])
    return "\n".join(L)
