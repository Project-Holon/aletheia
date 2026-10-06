#!/usr/bin/env python3
"""Look inside mwccarm dsi/1.1p1 while it compiles one file.

Runs the repo's compiler under a small Win32 debugger with breakpoints in
its register allocator, scheduler, alias analysis and IRO passes, and
prints what they decided and why.  See tools/mwccdbg/README.md.

    python tools/mwccdbg/mwccdbg.py regalloc SRC.c [--vregs] [--json OUT]
    python tools/mwccdbg/mwccdbg.py regalloc-replay SRC.c|CAP.json [--move V --after W]
                                    [--renumber V1,V2,...]
    python tools/mwccdbg/mwccdbg.py sched SRC.c [--pass pre|post] [--block N] [--json OUT]
    python tools/mwccdbg/mwccdbg.py sched-replay SRC.c|CAP.json [--pass P --block N]
                                    [--add U:V:LAT] [--remove U:V] [--insert X:POS:OWN]
    python tools/mwccdbg/mwccdbg.py alias SRC.c [--pass P] [--block N] [--window A,B]
    python tools/mwccdbg/mwccdbg.py cse SRC.c [--names LO-HI]
    python tools/mwccdbg/mwccdbg.py ir SRC.c --at POINT|ADDR [--hit N] [--raw]
    python tools/mwccdbg/mwccdbg.py passes SRC.c
    python tools/mwccdbg/mwccdbg.py edit SRC.c [--skip-sched pre] [--set-ready P:B:N=C] ...
    python tools/mwccdbg/mwccdbg.py pe secs|imports|strings RE|xref HEX|calls HEX|dis HEX [LEN]

SRC.c defaults (function, ISA, -lang, flags) come from its header, as in
match.py; --func, --thumb/--arm, --lang, -O and --extra override them.
"""
import argparse
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

import alias  # noqa: E402
import common  # noqa: E402
import edit  # noqa: E402
import iro  # noqa: E402
import passes  # noqa: E402
import pe32  # noqa: E402
import regalloc  # noqa: E402
import scheduler  # noqa: E402


def tail(settings, work, a):
    """Disassembly of the produced function and the verdict against the image."""
    if not getattr(a, "no_disasm", False):
        print("\n" + "=" * 72 + "\noutput object:")
        print("\n".join(common.disasm_function(settings, work.obj)))
    v = common.verdict(settings, work.obj)
    if v:
        print("match.py verdict: %s" % v)


def save_json(path, data):
    if path:
        with open(path, "w") as fh:
            json.dump(data, fh, indent=1)
        print("[capture written to %s]" % path, file=sys.stderr)


NO_BLOCKS = ("no scheduled block matches (the driver skips entry and exit blocks, so a "
             "single-block function has none)")


def is_capture(path):
    return path.lower().endswith(".json")


# ---------------------------------------------------------------------------

def cmd_regalloc(a):
    s = common.Settings(a)
    with common.Work(a.keep) as w:
        funcs = regalloc.capture(s, w, pcode=not a.no_pcode, vregs=a.vregs)
        print("# %s" % s.describe())
        print(regalloc.report(funcs, show_pcode=not a.no_pcode, only_class=a.cls))
        tail(s, w, a)
    save_json(a.json, funcs)


def cmd_regalloc_replay(a):
    if is_capture(a.src):
        with open(a.src) as fh:
            funcs = json.load(fh)
    else:
        s = common.Settings(a)
        with common.Work(a.keep) as w:
            funcs = regalloc.capture(s, w, pcode=False)
    if (a.move is None) != (a.after is None):
        raise SystemExit("--move and --after go together")
    groups = [[int(x.strip().lstrip("v")) for x in g.split(",")] for g in a.renumber]
    print(regalloc.replay(funcs, a.func, a.cls, a.round, a.move, a.after, groups))


def cmd_sched(a):
    s = common.Settings(a)
    with common.Work(a.keep) as w:
        blocks = scheduler.capture(s, w)
        print("# %s" % s.describe())
        sel = scheduler.select_blocks(blocks, a.pass_, a.block, a.min_nodes)
        print(scheduler.report(sel, cycles=not a.no_cycles) if sel else NO_BLOCKS)
        tail(s, w, a)
    save_json(a.json, blocks)


def cmd_sched_replay(a):
    if is_capture(a.src):
        with open(a.src) as fh:
            blocks = json.load(fh)
    else:
        s = common.Settings(a)
        with common.Work(a.keep) as w:
            blocks = scheduler.capture(s, w)
    if a.block is None:
        if a.add or a.remove or a.insert:
            raise SystemExit("edits need --block (and --pass when the function has both passes)")
        bad = 0
        if not scheduler.select_blocks(blocks, a.pass_):
            print(NO_BLOCKS)
            return
        for b in scheduler.select_blocks(blocks, a.pass_):
            ok = scheduler.model_agrees(scheduler.simulate(*scheduler.model_inputs(b)), b["picks"])
            bad += not ok
            print("%-5s block %-3d %3d nodes  model %s" % (
                b["pass"], b["block"], len(b["nodes"]), "agrees" if ok else "DIFFERS"))
        print("%d block(s), model differs on %d" % (len(scheduler.select_blocks(blocks, a.pass_)), bad))
        return
    sel = scheduler.select_blocks(blocks, a.pass_, a.block)
    if len(sel) != 1:
        raise SystemExit("--block %d matches %d blocks; give --pass pre|post" % (a.block, len(sel)))
    print(scheduler.replay(sel[0], a.add, a.remove, a.insert))


def cmd_alias(a):
    s = common.Settings(a)
    with common.Work(a.keep) as w:
        print("# %s" % s.describe())
        if a.window:
            w0, w1 = (int(x, 16) for x in a.window.split(","))
            print(alias.window_log(s, w, w0, w1))
            return
        tr = alias.capture(s, w)
        blocks = [b for b in tr.blocks
                  if (not a.pass_ or b["pass"] == a.pass_)
                  and (a.block is None or b["block"] == a.block)]
        print(alias.report(blocks, a.min_insns))


def cmd_cse(a):
    s = common.Settings(a)
    with common.Work(a.keep) as w:
        print("# %s" % s.describe())
        if a.names:
            m = re.match(r"(\d+)-(\d+)$", a.names)
            if not m:
                raise SystemExit("--names wants LO-HI, for example 300-450")
            print(iro.name_trace(s, w, int(m.group(1)), int(m.group(2)), a.depth))
        else:
            print(iro.cse_trace(s, w))


def cmd_ir(a):
    s = common.Settings(a)
    addr, label = iro.point(a.at)
    with common.Work(a.keep) as w:
        text = iro.dump(s, w, addr, a.hit, a.raw)
    head = "# %s\n# IR at %s (%x), hit %d" % (s.describe(), label, addr, a.hit)
    if a.out:
        with open(a.out, "w") as fh:
            fh.write(head + "\n" + text + "\n")
        print("[IR written to %s]" % a.out)
    else:
        print(head)
        print(text)


def cmd_passes(a):
    s = common.Settings(a)
    with common.Work(a.keep) as w:
        print("# %s" % s.describe())
        print(passes.trace(s, w, a.loop))


def cmd_edit(a):
    s = common.Settings(a)
    if not (a.skip_sched or a.skip_block or a.set_ready or a.force_alias or a.skip_call
            or a.skip_func or a.jump):
        raise SystemExit("no edit given")
    with common.Work(a.keep) as w:
        print("# %s" % s.describe())
        log = edit.run(s, w, a)
        print("edits applied:" if log else "no edit fired (check the block/node numbers)")
        for x in log:
            print("  " + x)
        tail(s, w, a)


def cmd_pe(a):
    pe = pe32.PE(common.compiler_exe())
    if a.what == "secs":
        print("base %x entry %x" % (pe.base, pe.entry))
        for name, va, vsz, _raw, _rsz in pe.secs:
            print("%-8s %08x %x" % (name, va, vsz))
    elif a.what == "imports":
        for addr, n in sorted(pe.imports.items()):
            print("%08x %s" % (addr, n))
    elif a.what == "strings":
        pat = re.compile(a.arg, re.I)
        for va, text in pe.strings():
            if pat.search(text):
                print("%08x %s" % (va, text))
    elif a.what in ("xref", "calls"):
        v = int(a.arg, 16)
        hits = pe.xrefs_imm(v) if a.what == "xref" else pe.calls_to(v)
        for x in hits:
            print("%08x  in %08x" % (x, pe.func_start(x) or 0))
    elif a.what == "dis":
        for ins in pe.disasm(int(a.arg, 16), int(a.len, 0)):
            print("%08x  %-8s %s" % (ins.address, ins.mnemonic, ins.op_str))


# ---------------------------------------------------------------------------

def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    sub = ap.add_subparsers(dest="cmd", required=True)

    p = sub.add_parser("regalloc", help="interference graph, simplify and select order")
    common.add_compile_args(p)
    p.add_argument("--vregs", action="store_true",
                   help="watch the vreg counter: who creates each GPR vreg, in order")
    p.add_argument("--class", dest="cls", default="gpr", choices=("gpr", "fpr", "all"))
    p.add_argument("--no-pcode", action="store_true")
    p.add_argument("--no-disasm", action="store_true")
    p.add_argument("--json", help="write the raw capture (input of regalloc-replay)")
    p.set_defaults(fn=cmd_regalloc)

    p = sub.add_parser("regalloc-replay", help="replay simplify/select, try a pop order or vreg numbering")
    common.add_compile_args(p)
    p.add_argument("--class", dest="cls", default="gpr", choices=("gpr", "fpr"))
    p.add_argument("--round", type=int, default=-1, help="colouring round (default: last)")
    p.add_argument("--move", type=int, help="vreg to move in the pop order ...")
    p.add_argument("--after", type=int, help="... to right after this vreg")
    p.add_argument("--renumber", action="append", default=[], metavar="V1,V2,...",
                   help="give these vregs their sorted ids in this order (repeatable)")
    p.set_defaults(fn=cmd_regalloc_replay)

    p = sub.add_parser("sched", help="scheduler DAGs, ready lists and picks per block")
    common.add_compile_args(p)
    p.add_argument("--pass", dest="pass_", choices=("pre", "post"))
    p.add_argument("--block", type=int)
    p.add_argument("--min-nodes", type=int, default=2)
    p.add_argument("--no-cycles", action="store_true", help="omit the per-cycle ready lists")
    p.add_argument("--no-disasm", action="store_true")
    p.add_argument("--json", help="write the raw capture (input of sched-replay)")
    p.set_defaults(fn=cmd_sched)

    p = sub.add_parser("sched-replay", help="replay the pick rule, try edge and node edits")
    common.add_compile_args(p)
    p.add_argument("--pass", dest="pass_", choices=("pre", "post"))
    p.add_argument("--block", type=int)
    p.add_argument("--add", action="append", default=[], metavar="U:V:LAT")
    p.add_argument("--remove", action="append", default=[], metavar="U:V")
    p.add_argument("--insert", action="append", default=[], metavar="NAME:POS:OWN[:DESC]")
    p.set_defaults(fn=cmd_sched_replay)

    p = sub.add_parser("alias", help="alias objects and the scheduler's alias queries")
    common.add_compile_args(p)
    p.add_argument("--pass", dest="pass_", choices=("pre", "post"))
    p.add_argument("--block", type=int)
    p.add_argument("--min-insns", type=int, default=2)
    p.add_argument("--window", metavar="ON,OFF",
                   help="instead log predicate calls between two hex breakpoints")
    p.set_defaults(fn=cmd_alias)

    p = sub.add_parser("cse", help="CSE temps (@N) as IRO names them")
    common.add_compile_args(p)
    p.add_argument("--names", metavar="LO-HI", help="every @N in the range, with call chains")
    p.add_argument("--depth", type=int, default=14)
    p.set_defaults(fn=cmd_cse)

    p = sub.add_parser("ir", help="IRO linear IR as expressions at a pass or address")
    common.add_compile_args(p)
    p.add_argument("--at", required=True, help="point name (see `passes`) or hex address")
    p.add_argument("--hit", type=int, default=1)
    p.add_argument("--raw", action="store_true", help="raw node words instead of expressions")
    p.add_argument("--out", help="write to a file")
    p.set_defaults(fn=cmd_ir)

    p = sub.add_parser("passes", help="order of IRO and backend passes")
    common.add_compile_args(p)
    p.add_argument("--loop", action="store_true", help="also mark each IRO loop iteration")
    p.set_defaults(fn=cmd_passes)

    p = sub.add_parser("edit", help="change one compiler decision at run time")
    common.add_compile_args(p)
    p.add_argument("--skip-sched", action="append", default=[], choices=("pre", "post"))
    p.add_argument("--skip-block", action="append", default=[], metavar="P:B")
    p.add_argument("--set-ready", action="append", default=[], metavar="P:B:N=C")
    p.add_argument("--force-alias", action="append", default=[], metavar="P:B:I:J")
    p.add_argument("--skip-call", action="append", default=[], metavar="SITE[@H,..]")
    p.add_argument("--skip-func", action="append", default=[], metavar="ADDR[@H,..]")
    p.add_argument("--jump", action="append", default=[], metavar="FROM:TO[@H,..]")
    p.add_argument("--no-disasm", action="store_true")
    p.set_defaults(fn=cmd_edit)

    p = sub.add_parser("pe", help="static look at mwccarm.exe (no compile)")
    p.add_argument("what", choices=("secs", "imports", "strings", "xref", "calls", "dis"))
    p.add_argument("arg", nargs="?")
    p.add_argument("len", nargs="?", default="0x100")
    p.set_defaults(fn=cmd_pe)

    a = ap.parse_args(argv)
    a.fn(a)


if __name__ == "__main__":
    main()
