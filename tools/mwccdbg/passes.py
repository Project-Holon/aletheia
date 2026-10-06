"""Pass order of one compile.

Breakpoints on the entry of the known IRO passes and backend passes print
the order in which they run, numbered per pass, under the function CodeGen
is working on (CodeGen names the function first, then runs IRO on it, then
the backend passes).  The numbers are the ``--hit`` values ``ir --at``
takes.
"""
import common
import iro

BACKEND = {
    "localcse": (0x514630, "backend local CSE (call site 0x47470A)"),
    "storeload": (0x521CD0, "memory store-load optimisation"),
    "peepfwd": (0x525C60, "peephole forward"),
    "colour": (0x526D50, "register colouring driver"),
    "sched": (0x50D810, "scheduler driver"),
    "switchopt": (0x52AEE0, "switch-table optimisation"),
}


def trace(settings, work, show_loop=False):
    events = []        # strings, or ("func", name) markers
    counts = {}

    def hook(name):
        def f(d, c):
            counts[name] = counts.get(name, 0) + 1
            events.append("%s#%d" % (name, counts[name]))
        return f

    def install(d):
        for name, (addr, _desc) in sorted(iro.POINTS.items()):
            if name in ("csename", "after-cse1") or (name == "looptop" and not show_loop):
                continue
            d.bp(addr, hook(name))
        for name, (addr, _desc) in BACKEND.items():
            d.bp(addr, hook(name))
        d.bp(common.A_FUNC_NAME,
             lambda d, c: events.append(("func", d.cstr(c.eax + 0xA, 128))))
        d.bp(common.A_SCHED_PRE_CALL, lambda d, c: events.append("(pre-RA)"))
        d.bp(common.A_SCHED_POST_CALL, lambda d, c: events.append("(post-RA)"))
    common.run(settings, work, install)
    out, line = [], ""
    for e in events:
        if isinstance(e, tuple):
            if line:
                out.append(line)
            line = "[CodeGen %s]" % e[1]
            continue
        if len(line) + len(e) + 1 > 100:
            out.append(line)
            line = "   "
        line += " " + e
    if line:
        out.append(line)
    out.append("")
    out.append("IRO points (names usable with `ir --at`):")
    for n, (a, desc) in sorted(iro.POINTS.items()):
        out.append("  %-10s %06x  %s" % (n, a, desc))
    out.append("backend passes:")
    for n, (a, desc) in sorted(BACKEND.items()):
        out.append("  %-10s %06x  %s" % (n, a, desc))
    return "\n".join(out)
