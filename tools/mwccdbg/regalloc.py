"""Register allocator capture and replay (Coloring.c, InterferenceGraph.c).

``capture`` compiles once under the debugger and records, per function,
register class and colouring round: the pcode the allocator sees, every
interference node (vreg, bound variable, spill cost, degree, flags,
neighbours), the simplify push order, the select pop order with the free
colour set each node saw, and spill rounds.  With ``vregs`` it also watches
the vreg counter and records who created each vreg, in order.

``simplify`` and ``select`` are the measured model of the two phases; they
reproduce the captured stack order and every colour.  ``replay`` runs them
on a capture, optionally with a node moved in the pop order or with a set of
vregs renumbered (what a different declaration order does).
"""
import struct

import common

# ---- addresses in mwccarm.exe dsi/1.1p1 -------------------------------------
A_COLOR_CLASS = 0x526D79      # per-class loop, class byte just stored
A_ROUND = 0x526E2A            # before the interference graph build (each round)
A_SIMPLIFY = 0x526630         # SimplifyGraph entry (graph complete)
A_SIMPLIFY_K = 0x526645       # simplify: eax = K (usable colours)
A_PUSH_LOW1 = 0x5266F9        # simplify: low-degree push, node in esi
A_PUSH_SPILL = 0x526869       # simplify: spill-candidate push, node in esi
A_PUSH_LOW2 = 0x52692C        # simplify: low-degree push after a spill pick, node in edx
A_SELECT = 0x5269D0           # SelectColors entry, [esp+4] = stack head
A_PICK_PRE = 0x526A9E         # select: about to pick, ebx = node, esi = free mask
A_PICK_POST = 0x526AB8        # select: after the pick, ebx = node
A_SPILLED = 0x526B34          # select: node marked spilled (ebx)
A_SPILL_ROUND = 0x526EA0      # colouring failed: insert spill code, retry

G_CLASS = 0x6674A4            # s8 current register class
G_FIRST = 0x651158            # int[class] number of physical registers
G_COUNT = 0x65A820            # int[class] registers incl. virtual (the vreg counter)
G_NODES = 0x65C274            # node array, 0x3C bytes per register

NODE_SZ = 0x3C
CLASS_NAMES = {0: "gpr", 1: "fpr"}
FLAG_NAMES = [(1, "spilled"), (2, "simplified"), (4, "coalesced"), (0x80, "nospill"),
              (0x200, "pair"), (0x400, "inf"), (0x1000, "even"), (0x2000, "follows")]

# spill-pick scores of the two special flags (float max and half of it)
SCORE_NOSPILL = 3.4028234663852886e+38
SCORE_INF = 1.7014117331926443e+38
# starting colour set and the callee-saved registers claimed, in order
VOLATILE = {"arm": [0, 1, 2, 3, 12, 14], "thumb": [0, 1, 2, 3]}
CALLEE = {"arm": [4, 5, 6, 7, 8, 9, 10, 11], "thumb": [4, 5, 6, 7]}


def flagstr(f):
    s = [n for b, n in FLAG_NAMES if f & b]
    rest = f & ~sum(b for b, _ in FLAG_NAMES)
    if rest:
        s.append("0x%x" % rest)
    return "|".join(s) or "-"


# ---------------------------------------------------------------------------
# capture
# ---------------------------------------------------------------------------

class Tracer:
    def __init__(self, want_func=None, pcode=True, trace_vregs=False):
        self.funcs = []
        self.cur = None
        self.cls = None
        self.rnd = None
        self.pcode = pcode
        self.trace_vregs = trace_vregs
        self.ft = common.FuncTracker(want_func)
        self.ft.listeners.append(self.on_func)
        self.names = common.Names()
        self._watching = False
        self._last_count = 0
        self._pending = None
        self._seen = set()

    def active(self):
        return self.cur is not None and self.ft.active()

    def node_index(self, d, ptr):
        return (ptr - d.u32(G_NODES)) // NODE_SZ

    def read_node(self, d, idx):
        raw = d.read(d.u32(G_NODES) + idx * NODE_SZ, NODE_SZ)
        obj = struct.unpack_from("<I", raw, 4)[0]
        num = struct.unpack_from("<i", raw, 0x28)[0]
        partner = struct.unpack_from("<I", raw, 0x34)[0]
        nbrs = []
        e = struct.unpack_from("<I", raw, 0x38)[0] if num >= self.cls["physical"] else 0
        guard = 0
        while e and guard < 10000:
            lo, hi = d.s32(e + 0xC), d.s32(e + 0x10)
            if num < hi:
                nbrs.append(hi)
                e = d.u32(e + 4)
            else:
                nbrs.append(lo)
                e = d.u32(e + 8)
            guard += 1
        return {"vreg": num, "obj": obj, "var": self.names.obj(d, obj),
                "cost": struct.unpack_from("<i", raw, 0xC)[0],
                "color": struct.unpack_from("<h", raw, 0x2C)[0],
                "flags": struct.unpack_from("<H", raw, 0x2E)[0],
                "degree": struct.unpack_from("<h", raw, 0x30)[0],
                "partner": self.node_index(d, partner) if partner else None,
                "neighbors": sorted(nbrs)}

    def dump_pcode(self, d):
        out = []
        cls, nphys = self.cls["cls"], self.cls["physical"]
        blk = d.u32(common.G_BLOCKS)
        bno = 0
        while blk and bno < 5000:
            for ins in common.block_insns(d, blk):
                for kind, rc, _fl, val, _obj in common.read_args(d, ins):
                    if kind == 0 and rc == cls and val >= nphys:
                        self._seen.add(val)
                if self.pcode:
                    out.append("B%-2d %s" % (bno, common.format_insn(d, ins, self.names, cls, nphys)))
            blk = d.u32(blk + common.BLK_NEXT)
            bno += 1
        return out

    def _pcode_len(self, d):
        n = 0
        blk = d.u32(common.G_BLOCKS)
        while blk:
            n += len(common.block_insns(d, blk))
            blk = d.u32(blk + common.BLK_NEXT)
        return n

    def _ret_addrs(self, d, esp, n=6):
        """Likely return addresses on the stack (word after an E8 call)."""
        out = []
        try:
            stack = d.read(esp, 0x400)
        except OSError:
            return out
        for k in range(0, len(stack), 4):
            v = struct.unpack_from("<I", stack, k)[0] - d.delta
            if 0x401005 <= v < 0x5B7000:
                try:
                    if d.u8(v - 5 + d.delta) == 0xE8:
                        out.append(v)
                except OSError:
                    pass
            if len(out) >= n:
                break
        return out

    # ---- callbacks ----------------------------------------------------
    def on_func(self, d, c, name):
        self.cur = {"name": name, "classes": [], "vregs": []}
        self.funcs.append(self.cur)
        if self.trace_vregs and not self._watching:
            self._last_count = d.s32(G_COUNT)
            d.watch_write(c, G_COUNT, self.on_count)
            self._watching = True

    def on_count(self, d, c):
        new = d.s32(G_COUNT)
        old = self._last_count
        self._last_count = new
        if not self.active():
            return
        if new != old + 1:
            self.cur["vregs"].append({"reset": new, "eip": c.eip - d.delta})
            return
        self.cur["vregs"].append({"vreg": old, "eip": c.eip - d.delta,
                                  "stack": self._ret_addrs(d, c.esp),
                                  "pcode": self._pcode_len(d)})

    def on_class(self, d, c):
        if not self.active():
            return
        cls = d.u8(G_CLASS)
        if cls >= 0x80:
            cls -= 0x100
        self.cls = {"class": CLASS_NAMES.get(cls, str(cls)), "cls": cls,
                    "physical": d.s32(G_FIRST + 4 * cls),
                    "count": d.s32(G_COUNT + 4 * cls), "rounds": []}
        self.cur["classes"].append(self.cls)

    def on_round(self, d, c):
        if not self.active() or self.cls is None:
            return
        self._seen = set()
        self.rnd = {"pcode": self.dump_pcode(d),
                    "count": d.s32(G_COUNT + 4 * self.cls["cls"]),
                    "nodes": [], "push": [], "stack": [], "picks": [],
                    "spilled": [], "failed": False}
        self.rnd["live"] = sorted(self._seen)
        self.cls["rounds"].append(self.rnd)

    def on_simplify(self, d, c):
        if not self.active() or self.rnd is None:
            return
        n = d.s32(G_COUNT + 4 * self.cls["cls"])
        self.rnd["count"] = n
        self.rnd["nodes"] = [self.read_node(d, i) for i in range(n)]

    def on_k(self, d, c):
        if self.active() and self.rnd is not None:
            self.rnd["k"] = c.eax

    def _push(self, d, ptr, why):
        if not self.active() or self.rnd is None:
            return
        deg = d.s16(ptr + 0x30)
        ent = {"vreg": self.node_index(d, ptr), "why": why, "degree": deg}
        if why == "spill-pick":
            if not self.rnd.get("costs_read"):
                # spill costs and the nospill/inf flags are filled in lazily, just before
                # the first spill pick (call at 0x526756); the node dump at entry still
                # holds zeros.  The simplified bit (2) is not part of that state.
                self.rnd["costs_read"] = True
                base = d.u32(G_NODES)
                for nd in self.rnd["nodes"]:
                    a = base + nd["vreg"] * NODE_SZ
                    nd["cost"] = d.s32(a + 0xC)
                    nd["flags"] = (d.u16(a + 0x2E) & ~2) | (nd["flags"] & 2)
            cost = d.s32(ptr + 0xC)
            ent["cost"] = cost
            ent["score"] = (cost / deg) if deg else None
        self.rnd["push"].append(ent)

    def on_select(self, d, c):
        if not self.active() or self.rnd is None:
            return
        p = d.u32(c.esp + 4)
        st = []
        while p and len(st) < 100000:
            st.append(self.node_index(d, p))
            p = d.u32(p)
        self.rnd["stack"] = st

    def on_pick_pre(self, d, c):
        if self.active() and self.rnd is not None:
            self._pending = (self.node_index(d, c.ebx), c.esi)

    def on_pick_post(self, d, c):
        if not self.active() or self.rnd is None or self._pending is None:
            return
        i, mask = self._pending
        self.rnd["picks"].append({"vreg": i, "free": mask, "color": d.s16(c.ebx + 0x2C)})

    def on_spilled(self, d, c):
        if self.active() and self.rnd is not None:
            self.rnd["spilled"].append(self.node_index(d, c.ebx))

    def on_spill_round(self, d, c):
        if self.active() and self.rnd is not None:
            self.rnd["failed"] = True

    def install(self, d):
        self.ft.install(d)
        d.bp(A_COLOR_CLASS, lambda d, c: self.on_class(d, c))
        d.bp(A_ROUND, lambda d, c: self.on_round(d, c))
        d.bp(A_SIMPLIFY, lambda d, c: self.on_simplify(d, c))
        d.bp(A_SIMPLIFY_K, lambda d, c: self.on_k(d, c))
        d.bp(A_PUSH_LOW1, lambda d, c: self._push(d, c.esi, "low-degree"))
        d.bp(A_PUSH_SPILL, lambda d, c: self._push(d, c.esi, "spill-pick"))
        d.bp(A_PUSH_LOW2, lambda d, c: self._push(d, c.edx, "low-degree"))
        d.bp(A_SELECT, lambda d, c: self.on_select(d, c))
        d.bp(A_PICK_PRE, lambda d, c: self.on_pick_pre(d, c))
        d.bp(A_PICK_POST, lambda d, c: self.on_pick_post(d, c))
        d.bp(A_SPILLED, lambda d, c: self.on_spilled(d, c))
        d.bp(A_SPILL_ROUND, lambda d, c: self.on_spill_round(d, c))


def capture(settings, work, pcode=True, vregs=False):
    tr = Tracer(settings.func, pcode=pcode, trace_vregs=vregs)
    common.run(settings, work, tr.install)
    funcs = [f for f in tr.funcs if f["classes"]]
    for f in funcs:
        f["isa"] = "thumb" if settings.thumb else "arm"
    return funcs


# ---------------------------------------------------------------------------
# report
# ---------------------------------------------------------------------------

def masknames(cls, m, nphys):
    return " ".join(common.regname(cls, k) for k in range(nphys) if m & (1 << k))


def report(funcs, show_pcode=True, only_class="gpr"):
    L = []
    for f in funcs:
        L.append("=" * 72)
        L.append("function %s" % f["name"])
        if f.get("vregs"):
            names = {}
            for cl in f["classes"]:
                for r in cl["rounds"]:
                    for n in r["nodes"]:
                        if n["var"]:
                            names.setdefault(n["vreg"], n["var"])
            L.append("GPR vreg creation order (vreg, bound variable, pcode length at birth, "
                     "writer eip, return addresses):")
            for v in f["vregs"]:
                if "reset" in v:
                    L.append("  counter reset to %d at %08x" % (v["reset"], v["eip"]))
                    continue
                L.append("  v%-4d %-10s pcode %-4d eip %08x  %s" % (
                    v["vreg"], names.get(v["vreg"], ""), v["pcode"], v["eip"],
                    " ".join("%08x" % x for x in v["stack"])))
        for cl in f["classes"]:
            if only_class != "all" and cl["class"] != only_class:
                continue
            cls, nphys = cl["cls"], cl["physical"]
            for ri, r in enumerate(cl["rounds"]):
                L.append("-" * 72)
                L.append("class %s  round %d  registers %d (physical %d)%s" % (
                    cl["class"], ri, r["count"], nphys,
                    "  FAILED -> spill code" if r["failed"] else ""))
                if show_pcode and r["pcode"]:
                    L.append("pcode at round start:")
                    L.extend("  " + x for x in r["pcode"])
                byv = {n["vreg"]: n for n in r["nodes"]}
                final = {p["vreg"]: p["color"] for p in r["picks"]}
                live = set(r.get("live", []))

                def lab(v):
                    n = byv.get(v)
                    nm = n["var"] if n and n["var"] else ""
                    return "v%d%s" % (v, "(" + nm + ")" if nm else "")
                L.append("nodes (virtual only):  vreg var cost degree flags -> colour | neighbours")
                for n in r["nodes"]:
                    if n["vreg"] < nphys or (n["vreg"] not in live and not n["neighbors"]):
                        continue
                    nb = " ".join(common.regname(cls, x) if x < nphys else "v%d" % x
                                  for x in n["neighbors"])
                    L.append("  v%-4d %-10s cost %-5d deg %-3d %-14s -> %-4s | %s" % (
                        n["vreg"], n["var"] or "", n["cost"], n["degree"], flagstr(n["flags"]),
                        common.regname(cls, final.get(n["vreg"], -1)), nb))
                L.append("simplify push order (first pushed = last coloured):")
                L.append("  (a sweep visits vregs in ascending order and pushes every node with "
                         "degree < K;")
                L.append("   K = %s; inside one sweep a higher vreg is pushed later, so it is "
                         "coloured earlier)" % r.get("k", "?"))
                sweep, prev = 0, None
                for k, p in enumerate(r["push"]):
                    if p["why"] == "spill-pick" or prev is None or p["vreg"] <= prev:
                        sweep += 1
                    prev = p["vreg"] if p["why"] != "spill-pick" else -1
                    if p["vreg"] not in live:
                        continue
                    extra = "  sweep %d" % sweep
                    if p["why"] == "spill-pick":
                        extra += "  cost %d / degree %d = %s" % (
                            p["cost"], p["degree"],
                            "%.3f" % p["score"] if p["score"] is not None else "-")
                    L.append("  %3d  %-14s %-10s deg-now %d%s" % (
                        k, lab(p["vreg"]), p["why"], p["degree"], extra))
                L.append("select order (stack top first):")
                for k, p in enumerate(r["picks"]):
                    if p["vreg"] not in live:
                        continue
                    if p["free"] == 0 and p["color"] < 0:
                        L.append("  %3d  %-14s free {}  -> none: claims the next callee-saved "
                                 "register, retries" % (k, lab(p["vreg"])))
                        continue
                    L.append("  %3d  %-14s free {%s}  -> %s" % (
                        k, lab(p["vreg"]), masknames(cls, p["free"], nphys),
                        common.regname(cls, p["color"])))
                L.append("  (pseudo-nodes not in the pcode are hidden)")
                if r["spilled"]:
                    L.append("spilled: " + " ".join(lab(v) for v in r["spilled"]))
    return "\n".join(L)


# ---------------------------------------------------------------------------
# model
# ---------------------------------------------------------------------------

def simplify(nodes, nphys, K):
    """Push order of SimplifyGraph; returns the pop order (stack top first).

    Sweeps visit candidate vregs (virtual, not coalesced) in ascending id and
    push every node with degree < K (degree counts precoloured neighbours; a
    pair node removes 2).  When a sweep pushes nothing, the spill pick takes
    the lowest cost/degree, scanning ids in descending order with strict <
    (ties keep the highest id); nospill and inf nodes score as huge.

    Costs and the nospill/inf flags are not set when the graph is complete:
    the allocator fills them in just before its first spill pick, and capture
    reads them then.  A capture made before that fix holds cost 0 and no
    flags, and the spill picks of such a capture do not replay."""
    deg = {v: len(n["neighbors"]) for v, n in nodes.items()}
    cand = [v for v in sorted(nodes) if v >= nphys and not nodes[v]["flags"] & 4]
    done, stack = set(), []
    while True:
        rem, changed = [], False
        for v in cand:
            if v in done:
                continue
            if deg[v] < K:
                for u in nodes[v]["neighbors"]:
                    if u in deg:
                        pair = nodes[v]["flags"] & 0x200 or nodes.get(u, {}).get("flags", 0) & 0x200
                        deg[u] -= 2 if pair else 1
                done.add(v)
                stack.append(v)
                changed = True
            else:
                rem.append(v)
        if changed:
            continue
        if not rem:
            break
        best, bs = None, None
        for v in sorted(rem, reverse=True):
            f = nodes[v]["flags"]
            if f & 0x80:
                sc = SCORE_NOSPILL
            elif f & 0x400:
                sc = SCORE_INF
            else:
                sc = nodes[v]["cost"] / deg[v] if deg[v] else 1e30
            if bs is None or sc < bs:
                best, bs = v, sc
        for u in nodes[best]["neighbors"]:
            if u in deg:
                deg[u] -= 1
        done.add(best)
        stack.append(best)
    return stack[::-1]


def select(nodes, order, isa="arm"):
    """Colours of SelectColors (GPR): each popped node takes the lowest free
    colour of the colour set; the set starts as r0-r3, ip, lr (Thumb: r0-r3)
    and, when nothing is free, the next callee-saved register (r4, r5, ...)
    is claimed and the node retries.  Pair/even rules are not modelled."""
    color = {i: i for i in range(16)}
    mask = set(VOLATILE[isa])
    nxt = list(CALLEE[isa])
    out = {}
    for v in order:
        while True:
            av = set(mask)
            for nb in nodes[v]["neighbors"]:
                c = color.get(nb, -1)
                if c is not None and c >= 0:
                    av.discard(c)
            if av:
                color[v] = out[v] = min(av)
                break
            if not nxt:
                color[v] = out[v] = -1
                break
            mask.add(nxt.pop(0))
    return out


def renumber(nodes, groups):
    """Give each group's vregs the group's sorted ids in the listed order.
    Returns (new nodes, map old -> new)."""
    m = {}
    for g in groups:
        for v, new in zip(g, sorted(g)):
            m[v] = new
    out = {}
    for v, n in nodes.items():
        nn = dict(n)
        nn["neighbors"] = [m.get(u, u) for u in n["neighbors"]]
        out[m.get(v, v)] = nn
    return out, m


def pick_round(funcs, func=None, cls="gpr", rnd=-1):
    f = next((x for x in funcs if func is None or x["name"] == func), None)
    if f is None:
        raise SystemExit("function %s not in the capture" % func)
    cl = next((c for c in f["classes"] if c["class"] == cls), None)
    if cl is None or not cl["rounds"]:
        raise SystemExit("no %s rounds for %s" % (cls, f["name"]))
    return f, cl, cl["rounds"][rnd]


def replay(funcs, func=None, cls="gpr", rnd=-1, move=None, after=None, groups=()):
    f, cl, r = pick_round(funcs, func, cls, rnd)
    nphys = cl["physical"]
    nodes = {n["vreg"]: n for n in r["nodes"]}
    live = set(r.get("live", []))
    K = r.get("k", 14)
    isa = f.get("isa") or ("thumb" if K == 8 else "arm")
    L = ["function %s  class %s  round %d of %d  K %d" % (
        f["name"], cl["class"], rnd % len(cl["rounds"]), len(cl["rounds"]), K)]
    order = simplify(nodes, nphys, K)
    L.append("simplify model reproduces the captured stack: %s" % (order == r["stack"]))
    base = select(nodes, r["stack"], isa)
    real = {p["vreg"]: p["color"] for p in r["picks"] if p["color"] >= 0}
    L.append("select model reproduces the captured colours: %s" % all(
        base.get(v) == c for v, c in real.items()))
    if any(nodes[v]["flags"] & 0x3200 for v in r["stack"] if v in live):
        L.append("note: pair/even nodes present; their colour rule is not modelled")
    alt, newid, label = None, {}, None
    if move is not None:
        o = [v for v in r["stack"] if v != move]
        o.insert(o.index(after) + 1, move)
        alt = select(nodes, o, isa)
        label = "v%d popped after v%d" % (move, after)
    elif groups:
        new_nodes, newid = renumber(nodes, groups)
        col = select(new_nodes, simplify(new_nodes, nphys, K), isa)
        alt = {v: col.get(newid.get(v, v), -1) for v in nodes}
        label = "renumbered " + "; ".join(",".join("v%d" % v for v in g) for g in groups)
    if label:
        L.append("alternative: " + label)
    L.append("  vreg  var        captured  alternative")
    for v in r["stack"]:
        if v not in live:
            continue
        b = real.get(v, base.get(v, -1))
        c = alt.get(v, -1) if alt is not None else b
        L.append("  v%-4d %-10s %-9s %-4s%s%s" % (
            v, nodes[v]["var"] or "", common.regname(0, b), common.regname(0, c),
            "  (now v%d)" % newid[v] if newid.get(v, v) != v else "",
            "   *" if b != c else ""))
    return "\n".join(L)

