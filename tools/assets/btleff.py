#!/usr/bin/env python3
"""
btleff.py -- battle effect-VM bytecode decode for `a/0/6/6` (601 sub-files)
and `a/0/6/7` (98 sub-files).

Written from scratch for the aletheia asset lane. Stdlib only.

--------------------------------------------------------------------------
Background: what `tools/assets/events.py` already established
--------------------------------------------------------------------------
`events.py` recovered `a/0/6/6`'s container framing (byte-identical repack,
601/601): a `u32 group_count G` (one of {1,2,3,5,8}), then G blocks of 14
IDENTICAL `u32` words (`SLOT_REPEAT` in events.py), then G variable-length
group payloads. `docs/ASSETS.md` ("Archive readers extended by
backward-register scan") also found the reader: overlay_094
`func_021F94F8` (`btlv_effvm.c`, the battle visual-effect VM's own object
constructor), which loads `a/0/6/6[effect_id]` via
`func_02048F60(archive_id=0x42, member=effect_id, heap)`. Everything below
is new this pass.

--------------------------------------------------------------------------
Group semantics: selected by a caller-supplied variant index, NOT a fixed
per-position slot
--------------------------------------------------------------------------
Inside `func_021F94F8` (ov094, `021F94F8`..`021F97E4`), after the archive
read, the constructor's own 5th argument (a small optional struct passed at
`[sp, #0x20]`) is consulted at instruction `021F968A`:

    ldrb  r1, [r5, #1]          ; requested group/variant index (u8)
    movs  r0, #0x38             ; 0x38 = 56 = one group's header block size
    muls  r0, r1, r0            ;        (4 + 14*4 = 56 bytes per group)
    adds  r6, r6, r0            ; r6 = 4 + 56 * requested_group

and just before that, the requested byte is bounds-checked directly against
the archive data itself (`021F967E`..`021F9688`): `ldrb r1,[data_ptr]` reads
byte 0 of the loaded `a/0/6/6` sub-file -- the low byte of `group_count`,
since `G` never exceeds 8 -- and if the caller's requested index is not
strictly less than it, the request is reset to 0 (`strb r0,[r5,#1]` with
r0=0). So **the group index is an explicit, bounds-checked caller
parameter** (read off the effect-invocation struct, one byte past its
first field), not a fixed-position/battler-slot selector baked into the
VM's own code. The eventual dispatch (`021F97A0`..`021F97C2`) is:

    r1 = *(data_ptr + r6)        ; the selected group's repeated slot word
                                  ; (any of its 14 copies -- all identical,
                                  ; see events.py -- so which of the 14 this
                                  ; particular call site reads from does not
                                  ; matter to the result)
    r1 = data_ptr + r1            ; -> selected group's payload start
    r0 = <vm context, arg 0>
    bl  func_0201127C             ; vm.c's "start at pc" -- see below

confirming the selected GROUP's payload -- not a "slot" -- is what becomes
the running script. `func_021F94F8` itself always requests slot 0 of group
0 when no struct is supplied (`r6 = 4` fixed, the `cmp r5,#0 / beq` skip
path at `021F951A`), and a second call site in the SAME function
(`021FC148`-adjacent region reached from opcode 70's handler below) reads
`a/0/6/7`'s group 0 the same way, always through byte offset 4 (slot 0) of
group 0's 14-word block. No call site observed this pass reads any slot
index other than 0 -- every one of the 14 repeated words always holds an
identical value (per events.py), so which slot a given call site happens
to hardcode cannot be distinguished by its *effect*, only by which byte
offset (`4 + 56*group + 4*slot`, slot 0..13) it happens to use. This pass
found the GROUP selector (a caller-supplied variant byte) but did not find
any call site that varies which of the 14 SLOTS it reads -- the 14-fold
redundancy itself stays unexplained (see "Remaining gaps").

--------------------------------------------------------------------------
The effect VM is the SAME engine as the field script VM (`vm.c`), with its
own, separate handler table
--------------------------------------------------------------------------
`func_021F94F8` starts the loaded bytecode with `bl func_0201127C` -- the
exact "start at a pc" entry point `docs/ASSETS.md`'s "Script virtual
machine" section names as part of the `vm.c` call family (`func_0201121C`
create, `func_0201127C` start, `func_02011298` step, `func_0201134C` fetch
u32 operand, `func_020113B4`/`func_020113C4` call/return, `sub_020113B0`
jump, `sub_02011290` stop). The VM CONTEXT itself, however, is a distinct
object: ov094 has exactly one call to `func_0201121C` (`021F945C`), with
its descriptor literal at `0x02209DCC`:

    0x02209DCC  u16 stack_cap = 0x10 (16)
    0x02209DCE  u16 ring_cap  = 0x08 (8)
    0x02209DD0  u32 cmd table = 0x02209E88
    0x02209DD4  u32 cmd count = 0x4E (78)

against the field VM's `{0x100, 0x40, 0x0217062C, 609}` in ov010 -- same
struct shape, completely separate table and instance, exactly the "same
machine, own table" the mission expected. **Handler table: `0x02209E88` in
overlay 94, 78 entries** (all resolved, all Thumb -- every table word's low
bit is set -- and all land inside ov094 itself, `021F9AB8`..`021FC448`;
unlike the field VM's table, none of the 78 pointers are NULL and none are
veneers into another overlay).

--------------------------------------------------------------------------
Operand widths: every one of the 78 opcodes is 4-byte (u32) operands only
--------------------------------------------------------------------------
Swept the same way `scripts.py` swept the field VM's 609 handlers: for each
of the 78 handler bodies (bounded by its own start address and the next
handler's start address, since the table is address-sorted), count direct
`bl`/`blx` calls to `func_02011330` (u16 fetch) and `func_0201134C` (u32
fetch), following one level of callee for any `bl` target that lands
inside ov094 itself (mirrors the field VM's "variable id fetched inside a
helper" case). Result: **`func_02011330` (u16 fetch) is never called by any
of the 78 handlers -- every operand fetch in this VM is 4 bytes**. Total
operand bytes per opcode (the opcode's own u16 excluded), read off the
`OPERAND_WIDTH` table below (all `('fixed', N)`, N a multiple of 4):
opcode 0 fetches 5 u32s (20 bytes) and is a plausible "play effect
resource" instruction (loads 5 params, then branches on two of them);
opcode 8 is the widest at 60 bytes (15 u32s); opcodes 5, 16, 17, 66, 71, 73
and 77 take no operands at all.

Four opcodes are control flow, identified by which vm.c call-family
function their handler itself calls (same method `scripts.py` used for the
field VM's opcodes 2/4/5/29/30/31/etc):

    opcode 77  calls sub_02011290 (stop)              -- script terminator
    opcode 70  calls func_020113B4 (call)              -- and, in the same
               handler (`021FC20C`), reads `a/0/6/7[computed member]` via
               `func_02048F60(archive_id=0x43, ...)`, then calls into
               `*(that_ptr) + *(that_ptr+4)` -- i.e. a/0/6/7's OWN group-0
               payload start, using the identical "offset 4 = payload
               start" convention -- so opcode 70 is "call an a/0/6/7
               sub-script as a subroutine"
    opcode 71  calls func_020113C4 (return)            -- pairs with 70
    opcodes 60, 61, 72, 74 call sub_020113B0 (jump)    -- branch opcodes

--------------------------------------------------------------------------
`a/0/6/7` shares `a/0/6/6`'s exact container framing
--------------------------------------------------------------------------
Checked directly (not inferred): `events.py`'s `parse_0666`/`pack_0666`,
unmodified, round-trip all 98 `a/0/6/7` sub-files byte-identical (see
`--verify` below). Sample sub-file 0: `group_count=1`, header_len=60
(`4 + 56*1`), and the 14-word block is `0x3c` (60) repeated 14 times --
the exact same shape as `a/0/6/6`. `a/0/6/7` is read by the same reader
family (`func_02048F60(archive_id=0x43, ...)`, opcode 70's handler above
and the constructor's own overflow path for effect ids past `a/0/6/6`'s
range, `021F9626` in `func_021F94F8`) and its payload is executed by the
same `func_0201127C`/`func_020113B4` entry points -- it is a second bank of
effect-VM scripts, callable as subroutines from `a/0/6/6` scripts (opcode
70) or run directly for effect ids that overflow `a/0/6/6`'s indexing.

--------------------------------------------------------------------------
CLI
--------------------------------------------------------------------------
    python tools/assets/btleff.py --list [--archive {0666,0667,both}]
        Per sub-file: group_count and each group's (start, size); confirms
        the 14-slot repetition for every group along the way.

    python tools/assets/btleff.py --disasm N [--archive {0666,0667}]
        Sub-file N: for every group, a linear opcode+operand sweep from the
        group's payload start using OPERAND_WIDTH, annotated with the
        control-flow tags above, stopping at the terminator opcode (77), a
        desync (opcode >= 78), or the group's own end.

    python tools/assets/btleff.py --verify
        Re-packs every a/0/6/6 and a/0/6/7 sub-file via events.py's
        parse_0666/pack_0666 and diffs against the original byte-for-byte.

    python tools/assets/btleff.py --check
        Runs the --disasm sweep over every group of every sub-file in both
        archives and reports the fraction that end cleanly: on the
        terminator opcode (77) with its (zero) operand fully inside the
        group, or by exhausting the group's bytes exactly (pos == len).
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402
import events  # noqa: E402 -- shares a/0/6/6 and a/0/6/7's container framing

A0666_PATH = events.A0666_PATH
A0667_PATH = os.path.join("extract", "data", "a", "0", "6", "7")

# ---------------------------------------------------------------------------
# The handler table
# ---------------------------------------------------------------------------
HANDLER_TABLE_ADDR = 0x02209E88
HANDLER_COUNT = 78

STOP_OPCODES = {77}
CALL_OPCODES = {70}
RETURN_OPCODES = {71}
JUMP_OPCODES = {60, 61, 72, 74}

# Total operand bytes per opcode (the opcode's own u16 excluded), read off
# each handler's own fetch calls to func_0201134C (u32 fetch) -- see the
# module docstring, "Operand widths" section, for the sweep method. Every
# entry is a multiple of 4: this VM never uses the 2-byte fetch at all.
OPERAND_WIDTH = {
    0: 20, 1: 40, 2: 24, 3: 24, 4: 8, 5: 0, 6: 4, 7: 44,
    8: 60, 9: 44, 10: 40, 11: 4, 12: 44, 13: 52, 14: 44, 15: 52,
    16: 0, 17: 0, 18: 28, 19: 36, 20: 24, 21: 28, 22: 24, 23: 24,
    24: 24, 25: 16, 26: 8, 27: 20, 28: 8, 29: 8, 30: 28, 31: 4,
    32: 20, 33: 32, 34: 8, 35: 4, 36: 4, 37: 24, 38: 16, 39: 20,
    40: 4, 41: 24, 42: 20, 43: 8, 44: 28, 45: 28, 46: 28, 47: 28,
    48: 8, 49: 20, 50: 4, 51: 8, 52: 36, 53: 4, 54: 32, 55: 36,
    56: 4, 57: 4, 58: 4, 59: 28, 60: 28, 61: 12, 62: 4, 63: 4,
    64: 8, 65: 12, 66: 0, 67: 28, 68: 4, 69: 24, 70: 12, 71: 0,
    72: 4, 73: 0, 74: 4, 75: 4, 76: 4, 77: 0,
}
assert len(OPERAND_WIDTH) == HANDLER_COUNT


def opcode_tag(opcode):
    if opcode in STOP_OPCODES:
        return "STOP"
    if opcode in CALL_OPCODES:
        return "CALL"
    if opcode in RETURN_OPCODES:
        return "RET"
    if opcode in JUMP_OPCODES:
        return "JUMP"
    return ""


class SweepResult:
    """One linear opcode sweep over a group's payload bytes."""

    def __init__(self):
        self.ops = []       # list of (pos, opcode, [u32 operand words])
        self.end_reason = None  # "stop" | "exact_end" | "desync" | "short"
        self.end_pos = 0


def sweep(payload):
    """Linear opcode+operand sweep of one group's payload bytes, using
    OPERAND_WIDTH. Stops at the terminator opcode (77, no operands), a
    desync (opcode >= HANDLER_COUNT), a truncated fetch (not enough bytes
    left for the declared operand width), or exhausting the payload
    exactly. Returns a SweepResult.
    """
    r = SweepResult()
    pos = 0
    n = len(payload)
    while True:
        if pos == n:
            r.end_reason = "exact_end"
            r.end_pos = pos
            return r
        if pos + 2 > n:
            r.end_reason = "short"
            r.end_pos = pos
            return r
        opcode = struct.unpack_from("<H", payload, pos)[0]
        if opcode not in OPERAND_WIDTH:
            r.end_reason = "desync"
            r.end_pos = pos
            return r
        width = OPERAND_WIDTH[opcode]
        op_start = pos
        pos += 2
        if pos + width > n:
            r.end_reason = "short"
            r.end_pos = op_start
            return r
        words = []
        for k in range(0, width, 4):
            words.append(struct.unpack_from("<I", payload, pos + k)[0])
        pos += width
        r.ops.append((op_start, opcode, words))
        if opcode in STOP_OPCODES:
            r.end_reason = "stop"
            r.end_pos = pos
            return r


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def _load(archive):
    path = A0666_PATH if archive == "0666" else A0667_PATH
    return narc.parse_file(path)


def _label(archive):
    return "a/0/6/6" if archive == "0666" else "a/0/6/7"


def cmd_list(args):
    archives = ["0666", "0667"] if args.archive == "both" else [args.archive]
    for archive in archives:
        n = _load(archive)
        print(f"=== {_label(archive)} ({n.file_count} sub-files) ===")
        for i in range(n.file_count):
            raw = n.read(i)
            try:
                parsed = events.parse_0666(raw)
            except events.EventsError as exc:
                print(f"{i}\tPARSE ERROR: {exc}")
                continue
            groups_desc = ", ".join(
                f"[{k}] start={g['start_offset']} size={len(g['payload'])}"
                for k, g in enumerate(parsed["groups"]))
            print(f"{i}\tgroup_count={parsed['group_count']}\t{groups_desc}")


def cmd_disasm(args):
    archive = args.archive
    n = _load(archive)
    raw = n.read(args.disasm)
    parsed = events.parse_0666(raw)
    print(f"{_label(archive)}#{args.disasm}: group_count={parsed['group_count']}")
    for k, g in enumerate(parsed["groups"]):
        print(f"  group[{k}] start={g['start_offset']} size={len(g['payload'])}")
        r = sweep(g["payload"])
        for op_start, opcode, words in r.ops:
            tag = opcode_tag(opcode)
            tag_str = f"  ; {tag}" if tag else ""
            words_str = " ".join(f"0x{w:08x}" for w in words)
            print(f"    +{op_start:<5d} op={opcode:<3d} {words_str}{tag_str}")
        print(f"    -- end: {r.end_reason} at +{r.end_pos} "
              f"(group size {len(g['payload'])})")


def cmd_verify(args):
    for archive in ("0666", "0667"):
        n = _load(archive)
        ok = 0
        fail = 0
        for i in range(n.file_count):
            raw = n.read(i)
            try:
                parsed = events.parse_0666(raw)
                repacked = events.pack_0666(parsed)
            except events.EventsError as exc:
                print(f"{_label(archive)}#{i}: PARSE ERROR: {exc}")
                fail += 1
                continue
            if repacked == raw:
                ok += 1
            else:
                fail += 1
                print(f"{_label(archive)}#{i}: round-trip MISMATCH "
                      f"(orig {len(raw)}, repacked {len(repacked)})")
        print(f"{_label(archive)}: {ok}/{n.file_count} round-trip OK "
              f"({fail} failed)")


def cmd_check(args):
    total_groups = 0
    clean = 0
    reasons = {}
    for archive in ("0666", "0667"):
        n = _load(archive)
        for i in range(n.file_count):
            raw = n.read(i)
            try:
                parsed = events.parse_0666(raw)
            except events.EventsError:
                continue
            for g in parsed["groups"]:
                total_groups += 1
                r = sweep(g["payload"])
                reasons[r.end_reason] = reasons.get(r.end_reason, 0) + 1
                if r.end_reason in ("stop", "exact_end"):
                    clean += 1
    pct = 100.0 * clean / total_groups if total_groups else 0.0
    print(f"groups swept: {total_groups}")
    for reason, count in sorted(reasons.items(), key=lambda kv: -kv[1]):
        print(f"  {reason}: {count} ({100.0 * count / total_groups:.1f}%)")
    print(f"clean (stop or exact_end): {clean}/{total_groups} ({pct:.1f}%)")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--list", action="store_true")
    g.add_argument("--disasm", type=int, metavar="N")
    g.add_argument("--verify", action="store_true")
    g.add_argument("--check", action="store_true")
    ap.add_argument("--archive", choices=["0666", "0667", "both"],
                     default="both")
    args = ap.parse_args(argv)

    if args.list:
        cmd_list(args)
    elif args.disasm is not None:
        if args.archive == "both":
            args.archive = "0666"
        cmd_disasm(args)
    elif args.verify:
        cmd_verify(args)
    elif args.check:
        cmd_check(args)


if __name__ == "__main__":
    main()
