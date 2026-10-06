"""Instruction scheduler capture and replay (Scheduler.c, SchedulerARM9.c).

The scheduler driver 0x50D810 runs twice for ARM at -O4: pass "pre" before
register colouring (vregs) and pass "post" after it (physical registers);
for Thumb only "post" runs.  Per block it builds a dependence DAG by a
backward walk, then picks one ready node per cycle.

``capture`` records every scheduled block: nodes in program order with own
latency, height, deadline, predecessor count, successor edges with
latencies and the memory instruction's alias object; then, per cycle, the
ready list the pick routine saw and the node it chose.

``simulate`` is the measured pick rule.  It reproduces captured orders and
answers "what order would this DAG give with an edge added or removed, or a
node inserted" without compiling.
"""
import struct

import alias
import common

A_NODE = 0x50D6E6             # node built: eax = node (backward walk)
A_PICK = 0x50D4E0             # pick entry: [esp+4] ready list, [esp+8] cycle
A_PICKED = 0x50D779           # pick returned: eax = chosen node (0 = none this cycle)

# node layout
N_NEXT, N_SUCC, N_INSN = 0x00, 0x08, 0x0C
N_OWN, N_DESC, N_READY, N_DEADLINE, N_HEIGHT, N_PREDS = 0x10, 0x12, 0x14, 0x16, 0x18, 0x1A
# successor edge: +0 next, +4 target node, +8 latency (u16)
INS_CALL = 0x8                # insn flag: call (holds the issue slot)


class SchedTracer:
    def __init__(self, want=None):
        self.bt = alias.BlockTracker(want)
        self.bt.listeners.append(self.on_block)
        self.names = common.Names()
        self.blocks = []
        self.cur = None
        self.raw_nodes = []
        self.idx = {}

    def install(self, d):
        self.bt.install(d)
        d.bp(A_NODE, self.on_node)
        d.bp(alias.A_DAG_BUILT, self.on_built)
        d.bp(A_PICK, self.on_pick)
        d.bp(A_PICKED, self.on_picked)

    def on_block(self, d, c):
        func, pas, n = self.bt.block
        self.cur = {"func": func, "pass": pas, "block": n, "nodes": [], "cycles": [], "picks": []}
        self.blocks.append(self.cur)
        self.raw_nodes = []
        self.idx = {}

    def _live(self):
        return self.cur is not None and self.bt.block is not None

    def on_node(self, d, c):
        if self._live():
            self.raw_nodes.append(c.eax)

    def _edges(self, d, n):
        out = []
        e = d.u32(n + N_SUCC)
        while e:
            out.append((d.u32(e + 4), d.u16(e + 8)))
            e = d.u32(e)
        return out

    def on_built(self, d, c):
        if not self._live():
            return
        order = self.raw_nodes[::-1]          # built backwards: reverse = program order
        self.idx = {p: i for i, p in enumerate(order)}
        for n in order:
            raw = d.read(n, 0x1C)
            ins = struct.unpack_from("<I", raw, N_INSN)[0]
            own, desc, ready, dl, h, pc = struct.unpack_from("<HHHHHH", raw, N_OWN)
            fl = d.u32(ins + common.INS_FLAGS)
            ao = alias.describe_ao(d, d.u32(ins + common.INS_ALIAS), self.names) if fl & 6 else None
            self.cur["nodes"].append({
                "text": common.format_insn(d, ins, self.names),
                "flags": fl, "ao": ao, "own": own, "desc": desc, "ready": ready,
                "deadline": dl, "height": h, "preds": pc,
                "edges": [(self.idx.get(t, -1), lat) for t, lat in self._edges(d, n)]})

    def on_pick(self, d, c):
        if not self._live() or not self.idx:
            return
        cyc = d.u16(c.esp + 8)
        n = d.u32(c.esp + 4)
        cands = []
        while n:
            raw = d.read(n, 0x1C)
            _own, _desc, ready, dl, h, pc = struct.unpack_from("<HHHHHH", raw, N_OWN)
            if pc == 0:
                rc = sum(1 for t, _l in self._edges(d, n) if d.u16(t + N_PREDS) == 1)
                cands.append({"node": self.idx.get(n, -1), "ready": ready, "deadline": dl,
                              "height": h, "release": rc})
            n = struct.unpack_from("<I", raw, N_NEXT)[0]
        self.cur["cycles"].append({"cycle": cyc, "ready": cands})

    def on_picked(self, d, c):
        if not self._live() or not self.idx:
            return
        node = self.idx.get(c.eax, -1) if c.eax else None
        if self.cur["cycles"]:
            self.cur["cycles"][-1]["chosen"] = node
        if node is not None:
            self.cur["picks"].append(node)


def capture(settings, work):
    tr = SchedTracer(settings.func)
    common.run(settings, work, tr.install)
    return [b for b in tr.blocks if b["nodes"]]


def select_blocks(blocks, pas=None, block=None, min_nodes=1):
    out = []
    for b in blocks:
        if pas and b["pass"] != pas:
            continue
        if block is not None and b["block"] != block:
            continue
        if len(b["nodes"]) < min_nodes:
            continue
        out.append(b)
    return out


def report(blocks, cycles=True):
    L = []
    for b in blocks:
        L.append("=" * 72)
        L.append("function %s  scheduler pass %s  block %d  (%d nodes)" % (
            b["func"], b["pass"], b["block"], len(b["nodes"])))
        L.append("  idx  insn (program order)                        own  h  dl preds -> succ(lat)")
        for i, n in enumerate(b["nodes"]):
            L.append("  %3d  %-44s %3d %2d %3d %3d   -> %s" % (
                i, n["text"], n["own"], n["height"], n["deadline"], n["preds"],
                " ".join("%d(%d)" % e for e in n["edges"])))
        mem = [(i, n) for i, n in enumerate(b["nodes"]) if n["ao"] is not None]
        if mem:
            L.append("  memory operands:")
            for i, n in mem:
                L.append("  %3d  [%s] %s" % (i, alias.insn_kind(n["flags"]), alias.ao_text(n["ao"])))
        if cycles:
            L.append("  picks (ready candidates: node[ready dl h release]):")
            for cy in b["cycles"]:
                L.append("    cycle %-3d %-56s -> %s" % (
                    cy["cycle"],
                    " ".join("%d[r%d dl%d h%d rc%d]" % (r["node"], r["ready"], r["deadline"],
                                                        r["height"], r["release"])
                             for r in cy["ready"]),
                    "-" if cy.get("chosen") is None else cy["chosen"]))
        L.append("  pick order: %s" % " ".join(map(str, b["picks"])))
    return "\n".join(L)


def model_agrees(model, captured):
    """True when the model's pick order is the captured one."""
    return model == captured


# ---------------------------------------------------------------------------
# model
# ---------------------------------------------------------------------------

def heights(edges, own):
    n = len(own)
    h = [0] * n
    for i in range(n - 1, -1, -1):
        h[i] = own[i]
        for t, lat in edges[i]:
            h[i] = max(h[i], lat + h[t])
    return h


def simulate(edges, own, desc=None, issue=None):
    """Pick order of the list scheduler.  ``edges[i]`` = [(succ, latency)] in
    program-order indexes (edges point forward); ``own[i]`` = own latency.

    Height = longest latency path to the block end (own latency at leaves),
    deadline = max height - height.  Each cycle, among ready nodes (no
    unscheduled predecessor, ready cycle reached) the pick prefers: a node
    whose deadline is due over one that is not, then the larger release
    count (successors for which it is the last predecessor), then the
    larger height, then (pre pass only: ``desc`` given) the smaller desc
    field, then program order.  Picking a node makes each successor ready
    at cycle + edge latency; a call holds the issue slot for ``issue[i]``
    cycles (its own latency)."""
    n = len(own)
    h = heights(edges, own)
    top = max(h) if h else 0
    dl = [top - x for x in h]
    pc = [0] * n
    for i in range(n):
        for t, _l in edges[i]:
            pc[t] += 1
    ready = [0] * n
    done = [False] * n
    order = []
    cyc = 0
    while len(order) < n:
        best = None
        for i in range(n):
            if done[i] or pc[i] or ready[i] > cyc:
                continue
            if best is None:
                best = i
                continue
            bd, cd = dl[best] <= cyc, dl[i] <= cyc
            if bd != cd:
                if cd:
                    best = i
                continue
            a = sum(1 for t, _l in edges[i] if pc[t] == 1)
            b = sum(1 for t, _l in edges[best] if pc[t] == 1)
            if a != b:
                if a > b:
                    best = i
                continue
            if h[i] != h[best]:
                if h[i] > h[best]:
                    best = i
                continue
            if desc is not None and desc[i] < desc[best]:
                best = i
        if best is not None:
            done[best] = True
            order.append(best)
            for t, lat in edges[best]:
                pc[t] -= 1
                ready[t] = max(ready[t], cyc + lat)
            if issue is not None:
                cyc += issue[best] - 1
        cyc += 1
    return order


def model_inputs(block):
    """(edges, own, desc, issue) for simulate() from a captured block."""
    nodes = block["nodes"]
    edges = [list(x["edges"]) for x in nodes]
    own = [x["own"] for x in nodes]
    desc = [x["desc"] for x in nodes] if block["pass"] == "pre" else None
    issue = [x["own"] if x["flags"] & INS_CALL else 1 for x in nodes]
    return edges, own, desc, issue


def parse_node(tok, nmap):
    tok = tok.strip()
    if tok in nmap:
        return nmap[tok]
    raise SystemExit("unknown node %r (use a node index or an inserted node name)" % tok)


def replay(block, add=(), remove=(), insert=()):
    """Replay one captured block, then the same block with edits.

    add: "U:V:LAT"; remove: "U:V"; insert: "NAME:POS:OWN[:DESC]" (a new node
    placed before original node POS; give it edges with add)."""
    nodes = block["nodes"]
    n = len(nodes)
    edges, own, desc, issue = model_inputs(block)
    L = ["function %s  scheduler pass %s  block %d  (%d nodes)" % (
        block["func"], block["pass"], block["block"], n)]
    captured = block["picks"]
    base = simulate(edges, own, desc, issue)
    L.append("captured order: %s" % " ".join(map(str, captured)))
    L.append("model order:    %s   (%s)" % (" ".join(map(str, base)),
                                          "reproduces the capture" if model_agrees(base, captured)
                                          else "DIFFERS from the capture"))
    if not (add or remove or insert):
        return "\n".join(L)
    labels = [str(i) for i in range(n)]
    order = list(labels)
    attr = {labels[i]: (own[i], desc[i] if desc else 0, issue[i]) for i in range(n)}
    edges_by = {labels[i]: [(labels[t], lat) for t, lat in edges[i]] for i in range(n)}
    for spec in insert:
        parts = spec.split(":")
        if len(parts) not in (3, 4):
            raise SystemExit("--insert wants NAME:POS:OWN[:DESC], got %r" % spec)
        name, pos = parts[0], parts[1]
        if name in order or pos not in order:
            raise SystemExit("bad --insert %r (name in use or no node %s)" % (spec, pos))
        order.insert(order.index(pos), name)
        attr[name] = (int(parts[2]), int(parts[3]) if len(parts) == 4 else 0, 1)
        edges_by[name] = []
    nmap = {x: x for x in order}
    for spec in remove:
        u, v = (parse_node(t, nmap) for t in spec.split(":"))
        edges_by[u] = [(t, lat) for t, lat in edges_by[u] if t != v]
    for spec in add:
        u, v, lat = spec.split(":")
        u, v = parse_node(u, nmap), parse_node(v, nmap)
        if order.index(u) >= order.index(v):
            raise SystemExit("edge %s -> %s points backwards in program order" % (u, v))
        edges_by[u].append((v, int(lat)))
    pos = {x: i for i, x in enumerate(order)}
    e2 = [[(pos[t], lat) for t, lat in edges_by[x]] for x in order]
    o2 = [order[i] for i in simulate(e2, [attr[x][0] for x in order],
                                     [attr[x][1] for x in order] if desc else None,
                                     [attr[x][2] for x in order])]
    L.append("edited order:   %s" % " ".join(o2))
    L.append("edits: %s" % "; ".join(
        ["add %s" % a for a in add] + ["remove %s" % r for r in remove] +
        ["insert %s" % i for i in insert]))
    texts = {labels[i]: nodes[i]["text"] for i in range(n)}
    L.append("edited order with instructions:")
    for x in o2:
        L.append("  %-4s %s" % (x, texts.get(x, "(inserted)")))
    return "\n".join(L)

