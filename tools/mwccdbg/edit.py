"""Run-time single-decision edits.

Compiles under the debugger and changes one decision inside the running
compiler, then prints the produced function and match.py's verdict.  Use it
to prove which decision a residue depends on before searching for source
that makes the compiler take it by itself.  Nothing is written to the
compiler binary.

Edits (all repeatable, block edits use the numbering ``sched`` prints):
  skip-sched pre|post     do not run that scheduler pass
  skip-block P:B          leave block B of scheduler pass P unscheduled
  set-ready P:B:N=C       set node N's ready cycle to C once the DAG is built
  force-alias P:B:I:J     make the alias query between insns I and J answer 1
  skip-call SITE[@H,..]   step over the 5-byte call at SITE (eax = 0)
  skip-func ADDR[@H,..]   return 0 at once from the routine at ADDR
  jump FROM:TO[@H,..]     resume at TO when FROM is reached
@H,.. limits an address edit to those hit numbers (1-based).
"""
import struct

import alias
import common
import scheduler

# scheduler call ranges skipped by --skip-sched (argument setup included)
SKIP_SCHED = {"pre": (0x47494C, 0x474980), "post": (0x474B3A, 0x474B60)}


def parse_hits(spec):
    """'ADDR@1,3' -> ('ADDR', {1, 3}); no '@' -> (spec, None)."""
    if "@" not in spec:
        return spec, None
    a, h = spec.split("@", 1)
    return a, {int(x) for x in h.split(",") if x}


def parse_block(spec, n):
    parts = spec.split(":")
    if len(parts) != n or parts[0] not in ("pre", "post"):
        raise SystemExit("bad block edit %r" % spec)
    return parts


class Editor:
    def __init__(self, settings, a):
        self.a = a
        self.log = []
        force = set()
        for spec in a.force_alias:
            p, b, i, j = parse_block(spec, 4)
            force.add((p, int(b)) + tuple(sorted((int(i), int(j)))))
        self.at = alias.AliasTracer(settings.func, force)
        self.st = scheduler.SchedTracer(settings.func)
        self.st.bt = self.at.bt            # one block numbering for both
        self.at.bt.listeners.append(self.st.on_block)
        self.skip_blocks = {(p, int(b)) for p, b in (parse_block(s, 2) for s in a.skip_block)}
        self.ready = {}
        for spec in a.set_ready:
            lhs, val = spec.split("=")
            p, b, n = parse_block(lhs, 3)
            self.ready.setdefault((p, int(b)), []).append((int(n), int(val)))

    def note(self, s):
        self.log.append(s)

    def install(self, d):
        self.at.install(d)
        d.bp(scheduler.A_NODE, self.st.on_node)
        d.bp(alias.A_DAG_BUILT, self.st.on_built)
        d.bp(alias.A_BLOCK, self.on_block)
        d.bp(alias.A_DAG_BUILT, self.on_built)
        ft = self.at.bt.ft
        for which in self.a.skip_sched:
            lo, hi = SKIP_SCHED[which]

            def skip(d, c, which=which, hi=hi):
                if ft.active():
                    d.jump(c, hi)
                    self.note("skipped scheduler pass %s in %s" % (which, ft.name))
            d.bp(lo, skip)
        for spec in self.a.skip_call:
            self._hit_edit(d, spec, "call")
        for spec in self.a.skip_func:
            self._hit_edit(d, spec, "func")
        for spec in self.a.jump:
            self._hit_edit(d, spec, "jump")

    def _hit_edit(self, d, spec, kind):
        addr_s, hits = parse_hits(spec)
        if kind == "jump":
            frm, to = (int(x, 16) for x in addr_s.split(":"))
        else:
            frm = int(addr_s, 16)
        count = [0]

        def f(d, c):
            count[0] += 1
            if hits is not None and count[0] not in hits:
                return
            if kind == "call":
                d.jump(c, frm + 5)
                c.set("eax", 0)
            elif kind == "func":
                ret = d.u32(c.esp)
                c.set("eip", ret)
                c.set("esp", c.esp + 4)
                c.set("eax", 0)
            else:
                d.jump(c, to)
            self.note("%s edit at %x, hit %d" % (kind, frm, count[0]))
        d.bp(frm, f)

    def on_block(self, d, c):
        if self.at.bt.block is None:
            return
        _f, p, b = self.at.bt.block
        if (p, b) in self.skip_blocks:
            ret = d.u32(c.esp)
            c.set("eip", ret)
            c.set("esp", c.esp + 4)
            self.note("left block %s:%d unscheduled" % (p, b))

    def on_built(self, d, c):
        if self.at.bt.block is None:
            return
        _f, p, b = self.at.bt.block
        order = self.st.raw_nodes[::-1]
        for n, val in self.ready.get((p, b), []):
            if n >= len(order):
                raise SystemExit("block %s:%d has %d nodes" % (p, b, len(order)))
            old = d.u16(order[n] + scheduler.N_READY)
            d.write(order[n] + scheduler.N_READY, struct.pack("<H", val))
            self.note("block %s:%d node %d ready %d -> %d" % (p, b, n, old, val))


def run(settings, work, a):
    ed = Editor(settings, a)
    common.run(settings, work, ed.install)
    if ed.at.forced:
        ed.note("%d alias query answer(s) forced to 1" % ed.at.forced)
    return ed.log
