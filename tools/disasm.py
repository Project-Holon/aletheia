#!/usr/bin/env python3
"""
disasm.py -- honest ARM/Thumb disassembly listings for aletheia.

Written from scratch. The only third-party dependency is Capstone, which is
used purely as a generic instruction decoder; every piece of analysis here
(entry point discovery, mode tracking, literal pool handling, function
boundary detection, code/data classification, output formatting) is original.

    pip install capstone

Usage
-----
    python tools/disasm.py arm9
    python tools/disasm.py arm9 --split
    python tools/disasm.py overlay 12
    python tools/disasm.py overlay --all
    python tools/disasm.py twl
    python tools/disasm.py ov230d

Output goes to asm/arm9/*.s, asm/overlays/ov###.s, asm/twl/twl.s and
asm/ov230d/ov230d.s (overlay 230 after its own decryptor, tools/ovcrypt.py).
With ``--split`` the ARM9 static module and the ITCM autoload are additionally
written as ordered translation units under asm/arm9/src/ and
asm/arm9/src_itcm/, described by the committed manifests
layout/units_arm9.json and layout/units_itcm.json.
``tools/build.py`` reassembles either form and proves both produce the same
bytes.

How the analysis works
----------------------
The guiding rule is: never guess. A byte is emitted as an instruction only if
a chain of reasoning starting at a known entry point reached it. Everything
else becomes ``.word`` / ``.byte`` data. That makes the listing incomplete
rather than wrong, which is the useful failure mode for a decompilation.

1. Seeds. Each region starts with a set of (address, thumb) pairs:
     - the ARM9 entry point for the main region;
     - the entries of every static initialiser array we can locate (for
       autoload blocks the info entry points at a NULL terminated array, for
       overlays the table gives an explicit start..end range);
     - the base of an autoload block that begins with ARM code.
   Function pointers carry their mode in bit 0, exactly as BX expects.

2. Recursive traversal. From each seed we walk forwards decoding one
   instruction at a time, stopping at an unconditional branch, an
   unconditional return, or a byte that has already been classified.
   Branch and call targets are queued; BLX with an immediate flips the
   instruction set, B/BL keep it.

3. Literal pools. A PC-relative load reserves its target word as data before
   anything else can claim it. Because pools sit between functions, this is
   also what keeps a linear walk from running off the end of a function into
   the constant pool that follows it. Pool words that look like code
   pointers become candidate seeds, but only when the byte they point at is
   still unclassified and carries a recognisable prologue.

4. Prologue sweep. Whatever is still unclassified is scanned, at the natural
   alignment, for function prologues: ``stmfd sp!, {..., lr}`` and
   ``str lr, [sp, #-4]!`` in ARM, ``push {..., lr}`` in Thumb. Each hit is a
   new seed and step 2 runs again. This repeats to a fixed point.

   The sweep deliberately recognises only prologues that save ``lr``, because
   that is the one pattern common enough in data to be worth the false
   positives and rare enough elsewhere to stay safe. A leaf function that
   saves no registers at all, or saves some without ``lr``, is invisible to
   it. The analysis is per region, so a function whose only callers live in
   another region (an overlay calling into the ARM9 static module) is
   invisible too. ``layout/function_starts.txt`` is the escape hatch for
   exactly those cases: a small committed list of addresses, each with the
   call site elsewhere in the image that attests it. Entries are added as
   seeds before the trace, so they are traced and validated like any other
   seed rather than trusted blindly.

   ``layout/data_objects.txt`` works the other way round: its ``range`` rows
   declare a data object with both ends attested (see that file's header).
   Before any seed is traced, every byte of a declared range is classified
   data, so no sweep, pool word or trace can put a function inside it, and a
   seed that lands inside one is refused and recorded as a conflict. The
   range start gets a ``d_02xxxxxx`` label in the listing.

5. Emission. Call targets become ``func_02xxxxxx``, other branch targets
   become ``loc_02xxxxxx``, pool words become ``pool_02xxxxxx``. Branch
   operands and PC-relative loads are rewritten to reference those labels so
   the listing says what the code means rather than where it happened to be
   assembled.

Reassembly
----------
The listings are meant to be assembled back into the original bytes, and
``tools/build.py`` proves that they are. Three mechanisms keep the output
exact:

* ``.syntax unified`` plus ``-mcpu=arm946e-s``, so GNU as reads the same
  dialect Capstone prints;
* ``.org`` guards before every label, which pin each block to its offset
  inside the region and turn any size drift into a loud assembler error
  instead of a silent cascade of shifted bytes;
* a raw-encoding escape hatch. Any instruction GNU as would re-encode
  differently is emitted as ``.inst`` / ``.inst.n`` / ``.inst.w`` with the
  decode kept in the comment. Three things trigger it: a non-canonical ARM
  modified immediate (the assembler always picks the smallest rotation), a
  branch whose target lies outside the region being assembled, and anything
  listed for this region in ``layout/reasm_quirks.json``, which
  ``tools/build.py --write-quirks`` fills in from a real assemble-and-compare
  run.

Mnemonic side index
--------------------
The raw-encoding escape hatch above means the mnemonic column of a listing
is incomplete on its own: a ``.inst``/``.inst.n``/``.inst.w`` line carries
its real mnemonic only in the trailing comment, so a naive text scan for,
say, ``movs`` silently misses every one of those. Alongside every directory
of listings this tool writes, it also writes ``inst_index.txt``: one line
per raw-encoded instruction with its address, region, mnemonic and operands,
gitignored along with the rest of ``asm/``. ``scan_mnemonics(region)`` reads
a region's listing plus its ``inst_index.txt`` and yields ``(addr, mnemonic,
operands)`` for every instruction in address order, raw-encoded or not, so
other tools never have to special-case ``.inst`` lines themselves.
"""

import argparse
import bisect
import json
import os
import re
import struct
import sys

try:
    import capstone
    from capstone import arm as cs_arm
except ImportError:  # pragma: no cover - environment problem, not logic
    print("error: capstone is not installed; run: pip install capstone",
          file=sys.stderr)
    raise SystemExit(2)


# Capstone renamed some ARM enum members between major versions.
def _cs_const(*names):
    for n in names:
        v = getattr(cs_arm, n, None)
        if v is not None:
            return v
    raise AttributeError("none of %s exist in this capstone build" % (names,))


CC_AL = _cs_const("ARM_CC_AL", "ARMCC_AL")
OP_IMM = _cs_const("ARM_OP_IMM")
OP_MEM = _cs_const("ARM_OP_MEM")
OP_REG = _cs_const("ARM_OP_REG")
REG_PC = _cs_const("ARM_REG_PC")
REG_LR = _cs_const("ARM_REG_LR")

UNK, CODE, DATA = 0, 1, 2

# Thumb `push` of a contiguous tail of the argument registers ({r3}, {r2,r3},
# {r1-r3}, {r0-r3}): the first instruction of a variadic function, which spills
# its register arguments next to the stacked ones before the lr-saving push.
VARARG_PUSHES = frozenset([0xB408, 0xB40C, 0xB40E, 0xB40F])

# ARM condition suffixes, needed to tell a conditional call ("bllt") from a
# plain branch ("blt"): both start with "bl".
CONDS = ("eq", "ne", "cs", "hs", "cc", "lo", "mi", "pl", "vs", "vc",
         "hi", "ls", "ge", "lt", "gt", "le", "al")
BRANCH_MNEMONICS = frozenset(["b"] + ["b" + c for c in CONDS])
CALL_MNEMONICS = frozenset(
    ["bl", "blx"] + ["bl" + c for c in CONDS] + ["blx" + c for c in CONDS])


class DisasmError(Exception):
    pass


# ---------------------------------------------------------------------------
# region model
# ---------------------------------------------------------------------------

class Region:
    """A contiguous chunk of loaded code with a known virtual base address."""

    def __init__(self, name, base, data, source, seeds=None, note=""):
        self.name = name
        self.base = base
        self.data = bytes(data)
        self.source = source
        self.note = note
        self.end = base + len(self.data)
        self.seeds = list(seeds or [])

        self.kind = bytearray(len(self.data))       # UNK / CODE / DATA
        self.insns = {}                             # offset -> InsnRec
        self.funcs = set()                          # addresses
        self.locs = set()                           # addresses
        self.pools = {}                             # address -> width
        self.mode_at = {}                           # offset -> thumb bool
        self.veneers = {}                           # address -> (size, target)
        self.conflicts = []
        self.declared = {}                          # start -> end, data
        self.far_branch = []                        # (lo, hi): bl is a far branch inside

    def contains(self, addr):
        return self.base <= addr < self.end

    def off(self, addr):
        return addr - self.base

    def word(self, addr):
        o = addr - self.base
        if o < 0 or o + 4 > len(self.data):
            return None
        return struct.unpack_from("<I", self.data, o)[0]


class InsnRec:
    __slots__ = ("addr", "size", "text", "thumb", "raw")

    def __init__(self, addr, size, text, thumb, raw):
        self.addr = addr
        self.size = size
        self.text = text
        self.thumb = thumb
        self.raw = raw


# ---------------------------------------------------------------------------
# analysis
# ---------------------------------------------------------------------------

class Analyser:
    def __init__(self, region):
        self.r = region
        self.md_arm = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
        self.md_thumb = capstone.Cs(capstone.CS_ARCH_ARM,
                                    capstone.CS_MODE_THUMB)
        for md in (self.md_arm, self.md_thumb):
            md.detail = True
            md.skipdata = False
        self.queue = []
        self._decl = None       # (declared dict, size, sorted lows, items, flat)

    # -- helpers ---------------------------------------------------------

    def _decode(self, addr, thumb):
        r = self.r
        o = r.off(addr)
        md = self.md_thumb if thumb else self.md_arm
        window = r.data[o:o + 4]
        if len(window) < (2 if thumb else 4):
            return None
        for insn in md.disasm(window, addr, count=1):
            return insn
        return None

    def _free(self, off, size):
        k = self.r.kind
        if off < 0 or off + size > len(k):
            return False
        return all(v == UNK for v in k[off:off + size])

    def _mark(self, off, size, value):
        self.r.kind[off:off + size] = bytes([value]) * size

    def _in_declared(self, addr):
        d = self.r.declared
        ent = self._decl
        if ent is None or ent[0] is not d or ent[1] != len(d):
            items = sorted(d.items())
            flat = all(items[i][1] <= items[i + 1][0]
                       for i in range(len(items) - 1))
            ent = self._decl = (d, len(d), [lo for lo, _hi in items], items,
                                flat)
        if not ent[4]:
            # overlapping ranges: the first one in declaration order wins
            for lo, hi in d.items():
                if lo <= addr < hi:
                    return lo
            return None
        i = bisect.bisect_right(ent[2], addr) - 1
        if i >= 0 and ent[3][i][0] <= addr < ent[3][i][1]:
            return ent[3][i][0]
        return None

    def add_seed(self, addr, thumb, is_func=True):
        r = self.r
        if not r.contains(addr):
            return
        lo = self._in_declared(addr)
        if lo is not None:
            # A declared data object (layout/data_objects.txt `range` row)
            # is never code; a seed into one is a contradiction to report,
            # not a function to trace.
            r.conflicts.append((addr, lo))
            return
        if thumb:
            if addr & 1:
                return
        elif addr & 3:
            return
        if is_func:
            r.funcs.add(addr)
        else:
            r.locs.add(addr)
        self.queue.append((addr, thumb))

    # -- literal pools ---------------------------------------------------

    def _reserve_pool(self, addr, width):
        r = self.r
        if not r.contains(addr) or addr & 3:
            return
        o = r.off(addr)
        if o + width > len(r.data):
            return
        if r.kind[o:o + width] == bytes([DATA]) * width:
            r.pools[addr] = max(r.pools.get(addr, 0), width)
            return
        # A PC-relative load is strong evidence. If a previous trace guessed
        # code here, retract those instructions and record the conflict.
        for probe in range(o, o + width):
            if r.kind[probe] == CODE:
                for start in list(r.insns):
                    ins = r.insns[start]
                    if start <= probe < start + ins.size:
                        self._mark(start, ins.size, UNK)
                        del r.insns[start]
                        r.conflicts.append(
                            (r.base + start, r.base + addr))
        self._mark(o, width, DATA)
        r.pools[addr] = max(r.pools.get(addr, 0), width)

    def _pool_target(self, insn, thumb):
        """Address loaded from by a PC-relative load, or None."""
        if not insn.mnemonic.startswith(("ldr", "vldr")):
            return None, 0
        try:
            ops = insn.operands
        except capstone.CsError:
            return None, 0
        for op in ops:
            if op.type == OP_MEM and op.mem.base == REG_PC and op.mem.index == 0:
                if thumb:
                    pc = (insn.address + 4) & ~3
                else:
                    pc = insn.address + 8
                width = 8 if insn.mnemonic.startswith("ldrd") else 4
                return pc + op.mem.disp, width
        return None, 0

    # -- control flow ----------------------------------------------------

    @staticmethod
    def _branch_target(insn):
        try:
            ops = insn.operands
        except capstone.CsError:
            return None
        if len(ops) == 1 and ops[0].type == OP_IMM:
            return ops[0].imm
        return None

    # Instructions that write PC but are really comparisons or tests, so a
    # PC first operand does not mean "this is a jump".
    _NOT_WRITES = ("cmp", "cmn", "tst", "teq", "str", "stm", "push")

    def _is_return(self, insn):
        """True when control does not fall through to the next instruction."""
        m = insn.mnemonic.split(".")[0]
        if m.startswith("bx") and not m.startswith("bxj"):
            return True
        try:
            ops = insn.operands
        except capstone.CsError:
            return False
        if m.startswith(("pop", "ldm")):
            for op in ops:
                if op.type == OP_REG and op.reg == REG_PC:
                    return True
            return False
        if m.startswith(self._NOT_WRITES):
            return False
        # Anything else whose destination register is PC transfers control:
        # mov pc, lr / ldr pc, [..] / add pc, pc, rN (jump tables).
        if ops and ops[0].type == OP_REG and ops[0].reg == REG_PC:
            return True
        return False

    # -- the trace -------------------------------------------------------

    def trace(self):
        r = self.r
        while self.queue:
            addr, thumb = self.queue.pop()
            while True:
                if not r.contains(addr):
                    break
                o = r.off(addr)
                if r.kind[o] != UNK:
                    break
                insn = self._decode(addr, thumb)
                if insn is None or insn.size == 0:
                    break
                if not self._free(o, insn.size):
                    break

                pool_addr, pool_w = self._pool_target(insn, thumb)

                self._mark(o, insn.size, CODE)
                text = insn.mnemonic
                if insn.op_str:
                    text += "\t" + insn.op_str
                r.insns[o] = InsnRec(addr, insn.size, text, thumb,
                                     bytes(insn.bytes))
                r.mode_at[o] = thumb

                if pool_addr is not None:
                    self._reserve_pool(pool_addr, pool_w)

                mnem = insn.mnemonic.split(".")[0]   # drop ".w" / ".n"
                uncond = (insn.cc == CC_AL or insn.cc == 0)
                stop = False

                if mnem in CALL_MNEMONICS:
                    tgt = self._branch_target(insn)
                    flips = mnem.startswith("blx")
                    far = (tgt is not None and thumb and not flips
                           and any(lo <= addr < hi and lo <= tgt < hi
                                   for lo, hi in r.far_branch))
                    if far:
                        # A Thumb `bl` from inside a listed function to
                        # another point inside it is a far branch, not a
                        # call (layout/far_branch_functions.txt): the
                        # target is a label and nothing falls through.
                        self.add_seed(tgt, thumb, is_func=False)
                        stop = True
                    elif tgt is not None:
                        self.add_seed(tgt, (not thumb) if flips else thumb,
                                      is_func=True)
                elif mnem in BRANCH_MNEMONICS:
                    tgt = self._branch_target(insn)
                    if tgt is not None:
                        self.add_seed(tgt, thumb, is_func=False)
                    if uncond:
                        stop = True

                if self._is_return(insn) and uncond:
                    # ldr pc, [pc, #x] is a veneer: follow the stored pointer.
                    if pool_addr is not None:
                        val = r.word(pool_addr)
                        if val is not None:
                            self.add_seed(val & ~1, bool(val & 1), is_func=True)
                    stop = True

                if stop:
                    break
                addr += insn.size

    # -- seed validation -------------------------------------------------

    def validate(self, addr, thumb, min_insns=4, max_insns=4096):
        """Dry-run a candidate function without committing anything.

        Guessed entry points (prologue sweeps, pool words) are only accepted
        if the code they start really behaves like code: every instruction
        decodes, and the run reaches an unconditional return, or merges into
        code we already trust, within a sane number of instructions. Random
        data occasionally looks like a prologue, and this is what keeps those
        bytes classified as data instead of turning into plausible nonsense.
        """
        r = self.r
        a = addr
        count = 0
        while count < max_insns:
            if not r.contains(a):
                return False
            o = r.off(a)
            if r.kind[o] != UNK:
                # Falling into a known instruction of the same mode is a
                # normal tail merge; anything else means we mis-stepped.
                return (count >= min_insns and r.kind[o] == CODE
                        and r.mode_at.get(o) == thumb)
            insn = self._decode(a, thumb)
            if insn is None or insn.size == 0:
                return False
            if not self._free(o, insn.size):
                return False
            count += 1
            mnem = insn.mnemonic.split(".")[0]
            uncond = (insn.cc == CC_AL or insn.cc == 0)
            if self._is_return(insn) and uncond:
                return count >= min_insns
            if mnem in BRANCH_MNEMONICS and uncond:
                tgt = self._branch_target(insn)
                if tgt is None or not r.contains(tgt):
                    return False
                a = tgt
                continue
            a += insn.size
        return False

    # -- seeding passes --------------------------------------------------

    def seed_from_pools(self):
        """Pool words that point at a plausible function start."""
        r = self.r
        added = 0
        for paddr in sorted(r.pools):
            val = r.word(paddr)
            if val is None:
                continue
            thumb = bool(val & 1)
            target = val & ~1
            if not r.contains(target):
                continue
            if thumb and (target & 1):
                continue
            if not thumb and (target & 3):
                continue
            o = r.off(target)
            if r.kind[o] != UNK:
                continue
            if not self._has_prologue(o, thumb):
                continue
            if not self.validate(target, thumb):
                continue
            self.add_seed(target, thumb, is_func=True)
            added += 1
        return added

    def _has_prologue(self, off, thumb):
        d = self.r.data
        if thumb:
            if off + 2 > len(d):
                return False
            hw = struct.unpack_from("<H", d, off)[0]
            return (hw & 0xFF00) == 0xB500          # push {..., lr}
        if off + 4 > len(d):
            return False
        w = struct.unpack_from("<I", d, off)[0]
        if (w & 0x0FFF0000) == 0x092D0000 and (w & 0x4000):
            return True                              # stmfd sp!, {..., lr}
        if (w & 0x0FFFFFFF) == 0x052DE004:
            return True                              # str lr, [sp, #-4]!
        return False

    def sweep_prologues(self):
        r = self.r
        added = 0
        # ARM prologues on word alignment.
        for off in range(0, len(r.data) - 4, 4):
            if r.kind[off] != UNK:
                continue
            if self._has_prologue(off, False) and self.validate(
                    r.base + off, False):
                self.add_seed(r.base + off, False, is_func=True)
                added += 1
                self.trace()
        # Thumb prologues on halfword alignment.
        for off in range(0, len(r.data) - 2, 2):
            if r.kind[off] != UNK:
                continue
            if self._has_prologue(off, True) and self.validate(
                    r.base + off, True):
                # A variadic function opens with `push {r0-r3}` (or a tail of
                # the argument registers) and only then saves lr, so the
                # prologue found here is its second instruction.  Seed the
                # function at the argument push; seeding here would split it
                # into a 2-byte head and a headless body (ov021 0x021C6744).
                entry = off
                if off >= 2 and r.kind[off - 2] == UNK:
                    prev = struct.unpack_from("<H", r.data, off - 2)[0]
                    if prev in VARARG_PUSHES:
                        entry = off - 2
                self.add_seed(r.base + entry, True, is_func=True)
                added += 1
                self.trace()
        return added

    # -- linker veneers --------------------------------------------------
    #
    # mwld puts a stub in front of a call it cannot encode directly, and the
    # stub is invisible to everything above: it has no register-saving
    # prologue, so sweep_prologues() never fires on it, and nothing in the
    # image branches to it, because the whole point of it is that the pool
    # word the caller loads holds the stub's address rather than the real
    # callee's.  So twelve perfectly good bytes of ARM code get emitted as
    # three data words, and the address they sit at has no name.
    #
    # This labels them.  It is deliberately conservative in three ways:
    #
    #   * only the two ARM encodings are recognised, compared as whole 32-bit
    #     words and not masked:
    #         E59FC000 E12FFF1C <ptr>     ldr ip, [pc, #0]; bx ip
    #         E51FF004 <ptr>              ldr pc, [pc, #-4]
    #     The Thumb shape `ldr r3, [pc, #0]; bx r3; .word target` is NOT
    #     recognised, because mwccarm emits exactly those eight bytes for a
    #     Thumb tail call with no argument set-up and the shape therefore says
    #     nothing about who wrote it;
    #   * <ptr> has to name code this analysis already reached: with the Thumb
    #     bit stripped it must be inside this region, aligned for the ISA its
    #     low bit declares, and classified CODE in that mode.  A stray triple
    #     of data words does not have a third word that points at traced code;
    #   * nothing is seeded from a veneer and no byte changes classification.
    #     The pass runs after the trace has settled and only over bytes that
    #     are still UNK or DATA, so it adds a label and nothing else, and the
    #     listing reassembles to the same bytes it did before.

    VENEER_LDR_IP = 0xE59FC000          # ldr ip, [pc, #0]
    VENEER_BX_IP = 0xE12FFF1C           # bx  ip
    VENEER_LDR_PC = 0xE51FF004          # ldr pc, [pc, #-4]

    def _points_at_traced_code(self, value):
        r = self.r
        thumb = bool(value & 1)
        target = value & ~1
        if not thumb and (target & 3):
            return False
        if not r.contains(target):
            return False
        o = r.off(target)
        return r.kind[o] == CODE and r.mode_at.get(o) == thumb

    def mark_veneers(self):
        r = self.r
        found = 0
        for off in range(0, len(r.data) - 8, 4):
            if r.kind[off] == CODE:
                continue
            w0 = struct.unpack_from("<I", r.data, off)[0]
            if w0 == self.VENEER_LDR_IP:
                if off + 12 > len(r.data):
                    continue
                if struct.unpack_from("<I", r.data, off + 4)[0] != \
                        self.VENEER_BX_IP:
                    continue
                size, ptr_off = 12, 8
            elif w0 == self.VENEER_LDR_PC:
                size, ptr_off = 8, 4
            else:
                continue
            if off + size > len(r.data) or any(
                    r.kind[off + k] == CODE for k in range(size)):
                continue
            value = struct.unpack_from("<I", r.data, off + ptr_off)[0]
            if (value & ~1) == r.base + off:
                continue
            if not self._points_at_traced_code(value):
                continue
            if r.base + off in r.pools or r.base + off in r.funcs \
                    or r.base + off in r.locs:
                # Something already names this address; leave that name alone
                # rather than renaming a label the rest of the listing uses.
                continue
            r.veneers[r.base + off] = (size, value)
            found += 1
        return found

    def run(self):
        r = self.r
        for lo, hi in r.declared.items():
            self._mark(r.off(lo), hi - lo, DATA)
        for addr, thumb in r.seeds:
            self.add_seed(addr, thumb, is_func=True)
        self.trace()
        for _ in range(8):
            grew = self.seed_from_pools()
            if grew:
                self.trace()
            grew2 = self.sweep_prologues()
            if grew2:
                self.trace()
            if not grew and not grew2:
                break
        # Any instruction that lost its bytes to a pool retraction is gone;
        # make sure no stale record survives.
        for off in list(r.insns):
            if r.kind[off] != CODE:
                del r.insns[off]
        self.mark_veneers()


_NOT_UNK = re.compile(b"[^" + re.escape(bytes([UNK])) + b"]")


def index_hidden_pool_words(region, all_regions):
    """Second-chance literal-pool scan inside code-adjacent unclassified runs.

    Two real shapes hide a genuine PC-relative load from the tracer:

      - a computed jump (`add pc, rN`, a switch's dispatch) is a return as
        far as the tracer is concerned, because the case addresses are not
        statically known, so it stops right there; the case bodies that
        follow are real code all the same (see docs/ASSETS.md,
        "item_gfx_member ... a second copy of the word does exist at
        0x02020EF4", and src/pending/unit_02020E60.c);
      - an ordinary return (`bx lr`, `pop {..., pc}`, `bx ip`) followed by
        one or more further tiny functions with no `lr`-saving prologue,
        so the prologue sweep never seeds them either (see
        docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md; the
        20-byte `ldr ip, [pc, #4]; ldr r0, [pc, #4]; bx ip` stub right
        after func_02061C0C's own `bx ip` at 0x02061C30 is this shape, and
        its pool word at 0x02061C3C duplicates 0x02061C28, func_02061C0C's
        own pool entry for the same value).

    Both leave real PC-relative loads sitting in bytes nothing ever traced,
    so the words they load stay anonymous `.word`s instead of indexed pool
    entries. This only ever adds entries to `region.pools`; it never marks
    bytes CODE and never changes a byte that gets emitted, so it cannot
    affect reassembly. Three conditions all have to hold before a candidate
    word is accepted, so a coincidental byte pattern that happens to decode
    as `ldr` cannot manufacture a false witness:

      1. the load site is unclassified (UNK) and sits inside a run whose
         owner is known: walking backward from the run's start, first over
         any already-reserved pool words (DATA, real pool entries a traced
         instruction elsewhere claimed) and then landing on CODE, ties the
         run to the function whose body -- or whose body's own pool --
         ends exactly there, rather than to an unrelated blob elsewhere in
         the image. The owning instruction's mode (ARM or Thumb) decides
         how this scan itself decodes the run;
      2. a PC-relative load decodes at that position and its own computed
         target is itself still unclassified (UNK), i.e. the candidate
         word sits in a run nothing has claimed either -- not a word that
         is already a traced pool entry or code;
      3. the candidate word's value reads back as a plausible pointer: it
         falls inside the address range of some loaded region. Ordinary
         pool constants (626, 0xFFFF, ...) fail this and stay unindexed.

    The load and its target need not share the same contiguous UNK run: a
    single already-traced pool word can sit between them (as it does at
    0x02020EE4, wedged between the case bodies and the rest of their pool
    at 0x02020EE8..0x02020F04), and both sides are still real.
    """
    r = region
    an = Analyser(r)
    n = len(r.data)
    added = 0
    off = 0

    def _owner_thumb(po):
        """Thumb/ARM mode of the instruction ending exactly at `po`, or None."""
        for sz in (2, 4):
            cand = po - sz
            if cand < 0:
                continue
            rec = r.insns.get(cand)
            if rec is not None and cand + rec.size == po:
                return rec.thumb
        return None

    kind = r.kind
    while off < n:
        start = kind.find(UNK, off, n)
        if start < 0:
            break
        m = _NOT_UNK.search(kind, start, n)
        off = end = m.start() if m else n
        po = start
        while po > 0 and r.kind[po - 1] == DATA:
            po -= 1
        if po == 0 or r.kind[po - 1] != CODE:
            continue
        thumb = _owner_thumb(po)
        if thumb is None:
            continue
        step = 2 if thumb else 4
        h = start
        while h + step <= end:
            insn = an._decode(r.base + h, thumb)
            if insn is not None:
                target, width = an._pool_target(insn, thumb)
                if target is not None and target % 4 == 0 and r.contains(target):
                    to = r.off(target)
                    if r.kind[to] == UNK and target not in r.pools:
                        val = r.word(target)
                        if val is not None and any(
                                rr.contains(val) for rr in all_regions):
                            r.pools[target] = max(
                                r.pools.get(target, 0), width)
                            added += 1
            h += step
    return added


# ---------------------------------------------------------------------------
# emission
# ---------------------------------------------------------------------------

def _label_for(region, addr):
    if addr in region.funcs:
        return "func_%08X" % addr
    if addr in region.locs:
        return "loc_%08X" % addr
    if addr in region.pools:
        return "pool_%08X" % addr
    # A linker veneer is code the trace never reached, so it comes out as data
    # words; the label says what those words are.  It ranks last, so a veneer
    # that already carries a name the rest of the listing refers to keeps it.
    if addr in region.veneers:
        return "veneer_%08X" % addr
    if addr in region.declared:
        return "d_%08X" % addr
    return None


def _rewrite_operands(region, rec):
    """Replace raw immediates with labels where we know what they mean.

    Returns ``(text, comment, raw)``. ``raw`` is True when the instruction
    must be emitted as its literal encoding because no assemblable spelling
    would reproduce the original bytes.
    """
    text = rec.text
    parts = text.split("\t", 1)
    mnem = parts[0]
    ops = parts[1] if len(parts) > 1 else ""
    base_mnem = mnem.split(".")[0]

    if not ops:
        return text, None, False

    # Branch and call targets.
    if ops.startswith("#") and (base_mnem in BRANCH_MNEMONICS
                                or base_mnem in CALL_MNEMONICS):
        try:
            tgt = int(ops[1:], 0)
        except ValueError:
            tgt = None
        if tgt is not None:
            lab = _label_for(region, tgt)
            if lab:
                return "%s\t%s" % (mnem, lab), None, False
            # A target with no label cannot be spelled relative to anything
            # this region defines, so keep the encoding verbatim.
            if region.contains(tgt):
                return ("%s\t0x%08X" % (mnem, tgt),
                        "target not classified as code", True)
            return "%s\t0x%08X" % (mnem, tgt), "outside this region", True

    # PC-relative loads: point them at the pool label we created.
    if "[pc" in ops:
        tgt = _pc_relative_target(rec)
        if tgt is not None and tgt in region.pools:
            head = ops.split(",")[0].strip()
            return "%s\t%s, pool_%08X" % (mnem, head, tgt), None, False
        return text, "unresolved pc-relative operand", True

    return text, None, False


# --- exactness filters -----------------------------------------------------

def _arm_imm_is_canonical(word):
    """False when an ARM modified immediate uses a non-minimal rotation.

    GNU as always picks the smallest rotation that can express a value, so an
    instruction encoded with any other rotation would come back with
    different bytes even though the disassembly is correct.
    """
    if (word >> 25) & 0x7 != 0b001:
        return True
    op = (word >> 21) & 0xF
    s = (word >> 20) & 1
    if op in (0b1000, 0b1001, 0b1010, 0b1011) and not s:
        # MSR immediate / undefined space: not a data-processing immediate.
        return True
    rot = (word >> 8) & 0xF
    imm8 = word & 0xFF
    value = ((imm8 >> (2 * rot)) | (imm8 << (32 - 2 * rot))) & 0xFFFFFFFF \
        if rot else imm8
    for i in range(0, 32, 2):
        v = ((value << i) | (value >> (32 - i))) & 0xFFFFFFFF if i else value
        if v <= 0xFF:
            return (i // 2) == rot and v == imm8
    return False


def _thumb_encoding_is_preferred(hw):
    """False when GNU as would pick the other 16-bit form for this spelling.

    Two Thumb-1 pairs are ambiguous once the operands are written out:

    * ``adds rX, rX, #imm3`` (T1, 0001 11x) versus ``adds rX, #imm8`` (T2).
      When Rd == Rn the assembler always takes the imm8 form, so a T1
      encoding of the same operands cannot be spelled.
    * ``adds rX, rY, #0`` (T1 with imm3 == 0) versus ``movs rX, rY``, which
      Capstone prints as ``adds``/``movs`` inconsistently; the imm3 == 0 case
      is covered by the rule above only when Rd == Rn.
    """
    if (hw & 0xFC00) == 0x1C00:              # ADD/SUB register-plus-imm3, T1
        rd = hw & 0x7
        rn = (hw >> 3) & 0x7
        if rd == rn:
            return False
    if (hw & 0xFF00) == 0x4400:               # ADD (register, high), T2
        rd = (hw & 0x7) | ((hw >> 4) & 0x8)
        rm = (hw >> 3) & 0xF
        if rd < 8 and rm < 8:
            # Written out as "add rX, rY" with two low registers, the
            # assembler reads a flag-setting ADD and only Thumb-2 has a
            # non-flag-setting 32-bit form, so it refuses outright.
            return False
        if rm == 13 and rd != 13:
            # Capstone spells this "add rX, sp, rX"; the assembler reads the
            # three-operand ADD and reaches for a 32-bit encoding.
            return False
    if (hw & 0xFF00) == 0x4600:                # MOV (register, high), T1
        rd = (hw & 0x7) | ((hw >> 4) & 0x8)
        rm = (hw >> 3) & 0xF
        if rd < 8 and rm < 8:
            # "mov rX, rY" with two low registers means LSLS on Thumb-1, so
            # the assembler rejects the high-register form it would need.
            return False
    return True


def _needs_raw(rec, text):
    """True when this instruction has to be emitted as its literal encoding."""
    if _is_unassemblable(text):
        return True
    if not rec.thumb and rec.size == 4:
        word = struct.unpack("<I", rec.raw)[0]
        if not _arm_imm_is_canonical(word):
            return True
    if rec.thumb and rec.size == 2:
        if not _thumb_encoding_is_preferred(
                struct.unpack("<H", rec.raw)[0]):
            return True
    return False


def _pc_relative_target(rec):
    """Recompute a PC-relative load target from the raw encoding."""
    if rec.thumb:
        if rec.size == 2:
            hw = struct.unpack("<H", rec.raw)[0]
            if (hw & 0xF800) == 0x4800:                 # ldr rN, [pc, #imm8]
                return ((rec.addr + 4) & ~3) + (hw & 0xFF) * 4
            return None
        lo, hi = struct.unpack("<HH", rec.raw)
        if (lo & 0xFF7F) == 0xF85F:                     # ldr.w rN, [pc, #imm12]
            imm = hi & 0xFFF
            up = bool(lo & 0x0080)
            base = (rec.addr + 4) & ~3
            return base + imm if up else base - imm
        return None
    w = struct.unpack("<I", rec.raw)[0]
    # cond 010 P=1 U B=0 W=0 L=1, Rn = PC: the U bit (0x00800000) is masked
    # out of the comparison and read separately as the sign.
    if (w & 0x0F7F0000) == 0x051F0000:
        imm = w & 0xFFF
        return rec.addr + 8 + (imm if (w & 0x00800000) else -imm)
    return None


def _pool_comment(region, addr, value, all_regions):
    bits = []
    lab = None
    if region.contains(value & ~1):
        lab = _label_for(region, value & ~1)
        if lab and (value & 1):
            lab += " (thumb)"
    if lab:
        bits.append("-> " + lab)
    else:
        for other in all_regions:
            if other is region:
                continue
            if other.contains(value):
                bits.append("-> %s+0x%X" % (other.name, value - other.base))
                break
    raw = struct.pack("<I", value)
    if all(0x20 <= b < 0x7F for b in raw):
        bits.append("'%s'" % raw.decode("ascii"))
    return "  ".join(bits)


def _is_unassemblable(text):
    """True for renderings GNU as would reject or re-encode differently.

    The one case that actually occurs is Capstone spelling a modified
    immediate it could not fold as two operands, "#imm, #rot". Rather than
    emit something an assembler would turn into different bytes, the caller
    falls back to a .word with the decoded text in a comment.
    """
    parts = text.split("\t", 1)
    if len(parts) < 2 or "[" in parts[1]:
        return False
    ops = [p.strip() for p in parts[1].split(",")]
    if len(ops) < 2:
        return False
    if not ops[-1].startswith("#") or not ops[-2].startswith("#"):
        return False
    try:
        rot = int(ops[-1][1:], 0)
    except ValueError:
        return False
    return 0 < rot < 32


def emit(region, out_path, all_regions, header_extra="", quirks=None,
        inst_index=None):
    return emit_range(region, out_path, 0, len(region.data), all_regions,
                      header_extra=header_extra, quirks=quirks,
                      inst_index=inst_index)


def emit_range(region, out_path, start_off, end_off, all_regions,
               header_extra="", quirks=None, unit=None, inst_index=None):
    """Write the listing for ``region[start_off:end_off]`` to ``out_path``.

    ``.org`` offsets are relative to ``start_off``, so a translation unit
    assembles standalone and still pins every block to its own address.
    """
    r = region
    quirks = quirks or frozenset()
    if os.path.dirname(out_path):
        os.makedirs(os.path.dirname(out_path), exist_ok=True)

    code_bytes = sum(1 for v in r.kind[start_off:end_off] if v == CODE)
    span = end_off - start_off
    data_bytes = span - code_bytes
    org_base = r.base + start_off

    lines = []
    add = lines.append
    add("/*")
    add(" * %s" % r.name)
    add(" * generated by tools/disasm.py; do not edit, do not commit")
    add(" *")
    add(" * source        %s" % r.source)
    if unit is not None:
        add(" * unit          %d of %s" % (unit[0], unit[1]))
    add(" * address range 0x%08X..0x%08X (0x%X bytes)"
        % (org_base, r.base + end_off, span))
    add(" * classified    0x%X bytes code (%.1f%%), 0x%X bytes data (%.1f%%)"
        % (code_bytes, 100.0 * code_bytes / max(1, span),
           data_bytes, 100.0 * data_bytes / max(1, span)))
    nfuncs = sum(1 for a in r.funcs if start_off <= a - r.base < end_off)
    add(" * functions     %d" % nfuncs)
    nven = sum(1 for a in r.veneers if start_off <= a - r.base < end_off)
    if nven:
        add(" * linker veneers %d (labelled veneer_XXXXXXXX; see"
            " tools/disasm.py mark_veneers)" % nven)
    if r.note:
        add(" *")
        add(" * %s" % r.note)
    if header_extra:
        for ln in header_extra.splitlines():
            add(" * %s" % ln)
    add(" *")
    add(" * Anything not reached from a known entry point is emitted as data")
    add(" * words rather than guessed at. .org directives pin each block to")
    add(" * its offset so the assembler catches any drift immediately.")
    add(" */")
    add("")
    add("\t.syntax\tunified")
    add("\t.section\t.text.%s, \"ax\", %%progbits" % _ident(r.name))
    add("")

    cur_thumb = None
    off = start_off
    pending_data = []

    def flush_data():
        if not pending_data:
            return
        start = pending_data[0]
        buf = bytes(r.data[start:pending_data[-1] + 1])
        _emit_data(add, r, start, buf, all_regions, org_base)
        pending_data.clear()

    while off < end_off:
        addr = r.base + off
        if r.kind[off] == CODE and off in r.insns \
                and off + r.insns[off].size <= end_off:
            flush_data()
            rec = r.insns[off]
            if rec.thumb != cur_thumb:
                add("")
                add("\t.thumb" if rec.thumb else "\t.arm")
                cur_thumb = rec.thumb
            lab = _label_for(r, addr)
            if lab:
                add("")
                add("\t.org\t0x%X" % (addr - org_base))
                if lab.startswith("func_"):
                    add("\t.global\t%s" % lab)
                    if rec.thumb:
                        add("\t.thumb_func")
                    add("\t.type\t%s, %%function" % lab)
                elif lab.startswith("loc_"):
                    add("\t.global\t%s" % lab)
                add("%s:" % lab)
            text, comment, force_raw = _rewrite_operands(r, rec)
            if addr in quirks:
                force_raw = True
                comment = (comment + "; " if comment else "") + \
                    "re-encoded by the assembler, kept verbatim"
            raw = " ".join("%02X" % b for b in rec.raw)
            if force_raw or _needs_raw(rec, text):
                _emit_raw_insn(add, rec, addr, text, comment)
                if inst_index is not None:
                    parts = text.split("\t", 1)
                    mnem = parts[0]
                    ops = parts[1] if len(parts) > 1 else ""
                    inst_index.append((addr, r.name, mnem, ops))
            else:
                line = "\t%s" % text
                pad = max(1, 44 - len(line.expandtabs(8)))
                line += " " * pad + "/* %08X  %s%s */" % (
                    addr, raw, ("  " + comment) if comment else "")
                add(line)
            off += rec.size
        else:
            pending_data.append(off)
            off += 1

    flush_data()
    add("")
    add("\t.org\t0x%X" % (end_off - start_off))
    add("\t.end")
    add("")

    _write_if_changed(out_path, "\n".join(lines))

    return {
        "region": r.name,
        "base": org_base,
        "size": span,
        "code_bytes": code_bytes,
        "data_bytes": data_bytes,
        "functions": nfuncs,
        "pools": sum(1 for a in r.pools if start_off <= a - r.base < end_off),
        "conflicts": len(r.conflicts),
        "path": out_path,
    }


def _emit_raw_insn(add, rec, addr, text, comment):
    """Emit an instruction as its literal encoding.

    ``.inst`` keeps the bytes exact while still telling the assembler this is
    code, so mapping symbols and disassembly of the rebuilt object stay
    right; a bare ``.word`` would not.
    """
    note = text.replace("\t", " ")
    if comment:
        note += "  (%s)" % comment
    if rec.thumb:
        if rec.size == 2:
            value = struct.unpack("<H", rec.raw)[0]
            directive = "\t.inst.n\t0x%04X" % value
        else:
            lo, hi = struct.unpack("<HH", rec.raw)
            directive = "\t.inst.w\t0x%08X" % ((lo << 16) | hi)
    else:
        directive = "\t.inst\t0x%08X" % struct.unpack("<I", rec.raw)[0]
    pad = max(1, 44 - len(directive.expandtabs(8)))
    add(directive + " " * pad + "/* %08X  %s  %s */"
        % (addr, " ".join("%02X" % b for b in rec.raw), note))


def _ident(name):
    return "".join(c if c.isalnum() or c == "_" else "_" for c in name)


# ---------------------------------------------------------------------------
# mnemonic side index
# ---------------------------------------------------------------------------
#
# See "Mnemonic side index" in the module docstring. ``inst_index.txt`` is
# written once per directory of listings (asm/arm9/, asm/arm9/src/,
# asm/arm9/src_itcm/, asm/overlays/) from the ``inst_index`` lists the emit
# functions above populate, and ``scan_mnemonics`` is the reader other tools
# are meant to import instead of re-deriving this themselves.

INST_INDEX_HEADER = [
    "# machine-readable index of .inst / .inst.n / .inst.w lines",
    "# generated by tools/disasm.py; ephemeral (asm/ is gitignored), not committed",
    "# every instruction the assembler could not round-trip as text, with its",
    "# real mnemonic and operands; see disasm.scan_mnemonics() for a reader",
    "# that merges this with the listing to cover every instruction",
    "# columns: address  region  mnemonic  operands",
]


def _write_if_changed(path, text):
    """Write `text` (UTF-8, LF) unless the file already holds exactly it, so an
    unchanged listing keeps its modification time and the stamp caches of the
    other tools stay valid."""
    data = text.encode("utf-8")
    try:
        with open(path, "rb") as fh:
            if fh.read() == data:
                return
    except OSError:
        pass
    with open(path, "wb") as fh:
        fh.write(data)


def write_inst_index(entries, path):
    """Write one inst_index.txt from a list of (addr, region, mnemonic, ops)."""
    if os.path.dirname(path):
        os.makedirs(os.path.dirname(path), exist_ok=True)
    lines = list(INST_INDEX_HEADER)
    for addr, region, mnem, ops in sorted(entries, key=lambda e: (e[1], e[0])):
        lines.append("%08X  %-24s %-10s %s" % (addr, region, mnem, ops))
    _write_if_changed(path, "\n".join(lines) + "\n")


def _read_all_inst_index(path):
    """Every (addr, region, mnemonic, ops) row in an inst_index.txt file."""
    out = []
    if not os.path.isfile(path):
        return out
    with open(path, encoding="utf-8") as fh:
        for line in fh:
            line = line.rstrip("\n")
            if not line or line.startswith("#"):
                continue
            parts = line.split(None, 3)
            if len(parts) < 3:
                continue
            addr_s, region, mnem = parts[0], parts[1], parts[2]
            ops = parts[3] if len(parts) > 3 else ""
            try:
                addr = int(addr_s, 16)
            except ValueError:
                continue
            out.append((addr, region, mnem, ops))
    return out


def _read_inst_index(path, region_name):
    return [(addr, mnem, ops)
           for addr, region, mnem, ops in _read_all_inst_index(path)
           if region == region_name]


_LISTING_ADDR_RE = re.compile(r"/\*\s*([0-9A-Fa-f]{8})\b")


def _parse_listing_mnemonics(path):
    """(addr, mnemonic, operands) for every ordinary (non-.inst) line."""
    out = []
    if not os.path.isfile(path):
        return out
    with open(path, encoding="utf-8") as fh:
        for raw_line in fh:
            s = raw_line.strip()
            if not s or s.startswith("*") or s.startswith("/*"):
                continue
            if s.startswith("."):        # directives, incl. .inst/.inst.n/.inst.w
                continue
            if s.endswith(":"):          # label
                continue
            m = _LISTING_ADDR_RE.search(s)
            if not m:
                continue
            addr = int(m.group(1), 16)
            code = s.split("/*", 1)[0].replace("\t", " ").strip()
            parts = code.split(None, 1)
            if not parts:
                continue
            mnem = parts[0]
            ops = parts[1] if len(parts) > 1 else ""
            out.append((addr, mnem, ops))
    return out


def _region_listing_paths(region_name, out_dir="asm"):
    """(list of .s paths, inst_index.txt path) for a region name.

    Prefers the split translation-unit listings (asm/arm9/src/*.s and
    asm/arm9/src_itcm/*.s) when they exist, since those are what
    tools/worklist.py and the manifest reader actually consume; falls back
    to the single whole-region listing (asm/arm9/main.s, itcm.s, ...)
    otherwise. Overlays are never split.
    """
    if region_name.startswith("overlay_"):
        ov_dir = os.path.join(out_dir, "overlays")
        s_path = os.path.join(ov_dir, "ov%s.s" % region_name.split("_")[1])
        return [s_path], os.path.join(ov_dir, "inst_index.txt")
    if region_name == "twl":
        twl_dir = os.path.join(out_dir, "twl")
        return ([os.path.join(twl_dir, "twl.s")],
                os.path.join(twl_dir, "inst_index.txt"))
    if region_name == OV230D:
        d = os.path.join(out_dir, OV230D)
        return ([os.path.join(d, OV230D + ".s")],
                os.path.join(d, "inst_index.txt"))

    arm9_dir = os.path.join(out_dir, "arm9")
    split_sub = {"arm9_main": "src", "arm9_itcm": "src_itcm"}.get(region_name)
    if split_sub:
        split_dir = os.path.join(arm9_dir, split_sub)
        if os.path.isdir(split_dir):
            s_paths = sorted(
                os.path.join(split_dir, f)
                for f in os.listdir(split_dir)
                if f.endswith(".s")
            )
            return s_paths, os.path.join(split_dir, "inst_index.txt")

    fname = region_name.replace("arm9_", "", 1) + ".s"
    return [os.path.join(arm9_dir, fname)], os.path.join(arm9_dir, "inst_index.txt")


def scan_mnemonics(region, out_dir="asm"):
    """Yield ``(addr, mnemonic, operands)`` for every instruction in a region.

    ``region`` is a region name as tools/disasm.py itself uses (e.g.
    "arm9_main", "arm9_itcm", "overlay_010"). Reads the already-generated
    listing for ordinary instructions and ``inst_index.txt`` for the
    ``.inst``/``.inst.n``/``.inst.w`` lines the listing keeps in raw
    encoding, and merges the two by address so callers never see the split.
    Both files must already exist (run tools/disasm.py first); missing
    files are treated as empty rather than raising.
    """
    s_paths, index_path = _region_listing_paths(region, out_dir)
    rows = []
    for path in s_paths:
        rows.extend(_parse_listing_mnemonics(path))
    rows.extend(_read_inst_index(index_path, region))
    rows.sort(key=lambda t: t[0])
    for addr, mnem, ops in rows:
        yield addr, mnem, ops


def _emit_data(add, region, start, buf, all_regions, org_base=None):
    r = region
    if org_base is None:
        org_base = r.base
    add("")
    add("\t.org\t0x%X" % (r.base + start - org_base))
    i = 0
    while i < len(buf):
        addr = r.base + start + i
        if addr % 4 == 0 and len(buf) - i >= 4:
            lab = _label_for(r, addr)
            if lab:
                add("%s:" % lab)
            value = struct.unpack_from("<I", buf, i)[0]
            note = _pool_comment(r, addr, value, all_regions)
            line = "\t.word\t0x%08X" % value
            pad = max(1, 44 - len(line.expandtabs(8)))
            line += " " * pad + "/* %08X%s */" % (
                addr, ("  " + note) if note else "")
            add(line)
            i += 4
        else:
            run = []
            while i < len(buf) and (
                    (r.base + start + i) % 4 != 0 or len(buf) - i < 4):
                run.append(buf[i])
                i += 1
            add("\t.byte\t%s" % ", ".join("0x%02X" % b for b in run))


# ---------------------------------------------------------------------------
# layout plumbing
# ---------------------------------------------------------------------------

def load_layout(layout_dir):
    path = os.path.join(layout_dir, "layout.json")
    if not os.path.isfile(path):
        raise DisasmError(
            "%s is missing; run: python tools/delink.py" % path)
    with open(path, "r", encoding="utf-8") as fh:
        return json.load(fh)


def read_file(path):
    if not os.path.isfile(path):
        raise DisasmError("missing %s; run tools/delink.py first" % path)
    with open(path, "rb") as fh:
        return fh.read()


def _init_array_from_pointer(data, base, ptr, limit=4096):
    """Read a NULL terminated array of function pointers at ``ptr``."""
    out = []
    off = ptr - base
    if off < 0 or off + 4 > len(data):
        return out
    for _ in range(limit):
        if off + 4 > len(data):
            break
        val = struct.unpack_from("<I", data, off)[0]
        if val == 0:
            break
        out.append((val, off))
        off += 4
    return out


FUNCTION_STARTS = "function_starts.txt"
DATA_OBJECTS = "data_objects.txt"


def load_declared_data(layout_dir, region):
    """Declared data ranges inside `region`, from layout/data_objects.txt.

    Only `range` rows are read (`region start range end evidence...`): a
    data object whose start AND end are attested, which is what lets the
    whole extent be classified data rather than just its first byte.  The
    region column is `arm9` (matched against every ARM9 region by address)
    or `ovNNN` (overlay_NNN).  Returns {start: end}, end exclusive.
    """
    path = os.path.join(layout_dir, DATA_OBJECTS)
    if not os.path.isfile(path):
        return {}
    if region.name.startswith("overlay_"):
        want = "ov" + region.name.split("_")[1]
    else:
        want = "arm9"
    out = {}
    with open(path, "r", encoding="utf-8", errors="replace") as fh:
        for lineno, line in enumerate(fh, 1):
            if line.startswith("#") or not line.strip():
                continue
            parts = line.split(None, 4)
            if len(parts) < 4 or parts[2] != "range" or parts[0] != want:
                continue
            try:
                lo, hi = int(parts[1], 16), int(parts[3], 16)
            except ValueError:
                raise DisasmError("%s:%d: a range row wants 'region start "
                                  "range end evidence'" % (path, lineno))
            if hi <= lo:
                raise DisasmError("%s:%d: empty range" % (path, lineno))
            if not (region.contains(lo) and region.base < hi <= region.end):
                continue
            out[lo] = hi
    return out


FAR_BRANCH_FUNCTIONS = "far_branch_functions.txt"


def load_far_branch_functions(layout_dir, region_name):
    """(lo, hi) ranges of functions whose Thumb `bl` reach their own body.

    Same three-plus-comment format as function_starts.txt:

        overlay_021  0x021CA5C4  0x021CB6D0  # evidence

    A Thumb `bl` from inside [lo, hi) to inside [lo, hi) is traced as a
    far branch (label, no fall-through) instead of a call (function start).
    """
    path = os.path.join(layout_dir, FAR_BRANCH_FUNCTIONS)
    if not os.path.isfile(path):
        return []
    out = []
    with open(path, "r", encoding="utf-8") as fh:
        for lineno, raw in enumerate(fh, 1):
            line = raw.split("#", 1)[0].strip()
            if not line:
                continue
            parts = line.split()
            if len(parts) != 3:
                raise DisasmError("%s:%d: want 'region lo hi'" % (path, lineno))
            if parts[0] != region_name:
                continue
            out.append((int(parts[1], 16), int(parts[2], 16)))
    return out


def load_function_starts(layout_dir, region_name):
    """Extra entry points for one region, from the committed override list.

    The file is three whitespace separated columns plus a free-form comment:

        arm9_main  0x020084D4  thumb  # bl from ov021 at 0x02193BA0

    Only addresses that the region-local analysis provably cannot reach on
    its own belong here, and the comment must name the evidence.  Each entry
    is fed through ``add_seed`` like any other seed, so a wrong address does
    not silently become plausible nonsense: the trace and, where a guess is
    involved, ``validate`` still have to accept it.
    """
    path = os.path.join(layout_dir, FUNCTION_STARTS)
    if not os.path.isfile(path):
        return []
    out = []
    with open(path, "r", encoding="utf-8") as fh:
        for lineno, raw in enumerate(fh, 1):
            line = raw.split("#", 1)[0].strip()
            if not line:
                continue
            parts = line.split()
            if len(parts) != 3:
                raise DisasmError("%s:%d: want 'region address isa'"
                                  % (path, lineno))
            reg, addr, isa = parts
            if reg != region_name:
                continue
            if isa not in ("thumb", "arm"):
                raise DisasmError("%s:%d: isa must be thumb or arm" % (path, lineno))
            out.append((int(addr, 16), isa == "thumb"))
    return out


def build_arm9_regions(layout, extract_dir, layout_dir="layout"):
    a9 = layout["arm9"]
    image = read_file(os.path.join(extract_dir, "arm9_dec.bin"))
    if len(image) != a9["decompressed_size"]:
        raise DisasmError(
            "extract/arm9_dec.bin is 0x%X bytes but layout.json says 0x%X; "
            "rerun tools/delink.py" % (len(image), a9["decompressed_size"]))

    regions = []
    st = a9["static"]
    main = Region(
        "arm9_main", st["ram_start"],
        image[st["src_offset"]:st["src_offset"] + st["size"]],
        "extract/arm9_dec.bin + 0x%X (decompressed ARM9 static module)"
        % st["src_offset"],
        seeds=[(a9["entry_point"], False)]
              + load_function_starts(layout_dir, "arm9_main"),
        note="bss 0x%08X..0x%08X is not part of this image"
             % (st["bss_start"], st["bss_end"]))
    regions.append(main)
    main.declared = load_declared_data(layout_dir, main)
    main.far_branch = load_far_branch_functions(layout_dir, main.name)

    for al in a9["autoloads"]:
        data = image[al["src_offset"]:al["src_offset"] + al["code_size"]]
        kind = al["kind"].lower()
        name = "arm9_%s" % kind if kind not in ("main_twl", "other") \
            else "arm9_autoload%d_%s" % (al["index"], kind)
        if sum(1 for x in regions if x.name == name):
            name = "arm9_autoload%d_%s" % (al["index"], kind)
        seeds = []
        note = "autoload block %d, copied from ARM9 + 0x%X at boot" % (
            al["index"], al["src_offset"])
        init = al["static_init_start"]
        ptrs = _init_array_from_pointer(data, al["ram_start"], init)
        for val, poff in ptrs:
            seeds.append((val & ~1, bool(val & 1)))
        if ptrs:
            note += "; %d static initialiser(s) at 0x%08X" % (
                len(ptrs), init)
        seeds += load_function_starts(layout_dir, name)
        regions.append(Region(name, al["ram_start"], data,
                              "extract/arm9_dec.bin + 0x%X" % al["src_offset"],
                              seeds=seeds, note=note))
        regions[-1].declared = load_declared_data(layout_dir, regions[-1])
    return regions


def build_overlay_region(layout, extract_dir, ov_id, layout_dir="layout"):
    ovs = layout["overlays"]
    if ov_id < 0 or ov_id >= len(ovs):
        raise DisasmError("overlay %d does not exist (0..%d)"
                          % (ov_id, len(ovs) - 1))
    o = ovs[ov_id]
    data = read_file(os.path.join(extract_dir,
                                  o["decompressed_file"].replace("/", os.sep)))
    if len(data) != o["code_size"]:
        raise DisasmError(
            "overlay %d is 0x%X bytes but the table says 0x%X"
            % (ov_id, len(data), o["code_size"]))

    seeds = []
    base = o["ram_start"]
    lo, hi = o["static_init_start"], o["static_init_end"]
    for a in range(lo, hi, 4):
        off = a - base
        if 0 <= off + 4 <= len(data):
            val = struct.unpack_from("<I", data, off)[0]
            if val:
                seeds.append((val & ~1, bool(val & 1)))
    seeds += load_function_starts(layout_dir, "overlay_%03d" % ov_id)
    note = ("static initialisers 0x%08X..0x%08X (%d entry/entries); "
            "bss 0x%08X..0x%08X"
            % (lo, hi, o["static_init_count"], o["bss_start"], o["bss_end"]))
    if o["compressed"]:
        note += "; BLZ compressed on ROM (0x%X bytes)" % o["compressed_size"]
    reg = Region("overlay_%03d" % ov_id, base, data,
                 "extract/" + o["decompressed_file"], seeds=seeds, note=note)
    reg.declared = load_declared_data(layout_dir, reg)
    reg.far_branch = load_far_branch_functions(layout_dir, reg.name)
    return reg


def build_twl_region(layout, extract_dir, layout_dir="layout"):
    """Region `twl`: the DSi-mode autoload block of arm9i.bin, or None.

    Its bytes exist only after delink.py decrypted and decompressed arm9i
    with a user-supplied key (extract/arm9i_dec.bin); without them the
    region is skipped, never guessed.  Seeds are the static initialiser
    array the autoload entry points at plus layout/function_starts.txt rows
    for `twl`; the trace, pool reservation and prologue sweep then run as
    for any region.  Branches from the ARM9 image into the window are
    deliberately not seeds: a label they created would rest on the very
    call site a matched function might be tested on."""
    tw = layout.get("twl")
    if not tw:
        return None
    path = os.path.join(extract_dir, tw["decompressed_file"])
    if not os.path.isfile(path):
        return None
    image = read_file(path)
    if len(image) != tw["decompressed_size"]:
        raise DisasmError(
            "extract/%s is 0x%X bytes but layout.json says 0x%X; rerun "
            "tools/delink.py with the DSi key"
            % (tw["decompressed_file"], len(image), tw["decompressed_size"]))
    data = image[tw["src_offset"]:tw["src_offset"] + tw["code_size"]]
    seeds = []
    ptrs = _init_array_from_pointer(data, tw["ram_start"],
                                    tw["static_init_start"])
    for val, _poff in ptrs:
        seeds.append((val & ~1, bool(val & 1)))
    seeds += load_function_starts(layout_dir, "twl")
    note = ("DSi-mode autoload block, arm9i + 0x%X (decrypted, "
            "decompressed); %d static initialiser(s) at 0x%08X; bss "
            "0x%08X..0x%08X is not part of this image"
            % (tw["src_offset"], len(ptrs), tw["static_init_start"],
               tw["bss_start"], tw["bss_end"]))
    return Region("twl", tw["ram_start"], data,
                  "extract/%s + 0x%X" % (tw["decompressed_file"],
                                         tw["src_offset"]),
                  seeds=seeds, note=note)


OV230D = "ov230d"


def build_ov230d_region(layout, extract_dir, layout_dir="layout"):
    """Region `ov230d`: overlay 230 as its static initialisers leave it.

    ov230 decrypts most of its own code in place when it is loaded
    (tools/ovcrypt.py).  asm/overlays/ov230.s lists the ROM bytes, which
    are ciphertext there; this region lists extract/ov230d.bin, the view
    ovcrypt.py writes after replaying the decryptor and checking every
    range.  The file is recomputed from extract/overlays_dec/y9_0230.bin
    here and must agree byte for byte, so a stale view is refused.  Seeds
    are ov230's static initialisers, the start of every decrypted range (the
    decryptor's table is what says code begins there: it is the range the
    game decrypts and flushes from the caches) and layout/function_starts.txt
    rows for `ov230d`; the decryptor's tables are declared data.  The ROM
    listing and the ROM rebuild never see this region.  Returns None when
    the view has not been written."""
    import ovcrypt
    path = os.path.join(extract_dir, ovcrypt.VIEW_FILE)
    if not os.path.isfile(path):
        return None
    o = ovcrypt.overlay_record(layout)
    image = read_file(os.path.join(
        extract_dir, o["decompressed_file"].replace("/", os.sep)))
    try:
        view = ovcrypt.decrypt(image, o["ram_start"],
                               ovcrypt.sinit_entries(image, o))
    except ovcrypt.CryptError as exc:
        raise DisasmError("ov230d: %s" % exc)
    data = read_file(path)
    if data != view.data:
        raise DisasmError("extract/%s does not match a fresh decryption of "
                          "extract/%s; rerun: python tools/ovcrypt.py write"
                          % (ovcrypt.VIEW_FILE, o["decompressed_file"]))
    seeds = [(e, False) for e, _t, _x in view.tables]
    seeds += [(s, False) for s, _n, _t in view.ranges]
    seeds += load_function_starts(layout_dir, OV230D)
    note = ("overlay 230 after its %d static initialiser(s) decrypted %d "
            "range(s) in place (tools/ovcrypt.py); a derived view, never "
            "built into the ROM" % (len(view.tables), len(view.ranges)))
    reg = Region(OV230D, o["ram_start"], data,
                 "extract/%s (derived from extract/%s)"
                 % (ovcrypt.VIEW_FILE, o["decompressed_file"]),
                 seeds=seeds, note=note)
    reg.declared = {t: x for _e, t, x in view.tables}
    reg.ov_ranges = list(view.ranges)
    return reg


def check_ov230d_trace(r):
    """Every decrypted range must be a traced function, all code."""
    for s, n, _t in r.ov_ranges:
        o = r.off(s)
        if s not in r.funcs or any(k != CODE for k in r.kind[o:o + n]):
            raise DisasmError(
                "ov230d: the trace does not cover decrypted range "
                "0x%08X+0x%X as one function of code; refusing the listing"
                % (s, n))


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def load_quirks(layout_dir, region_name):
    """Addresses this region must emit verbatim, from build.py's findings."""
    path = os.path.join(layout_dir, "reasm_quirks.json")
    if not os.path.isfile(path):
        return frozenset()
    with open(path, "r", encoding="utf-8") as fh:
        doc = json.load(fh)
    return frozenset(int(a, 16)
                     for a in doc.get("regions", {}).get(region_name, []))


def process(regions, out_dir, all_regions=None, layout_dir="layout"):
    stats = []
    ctx = all_regions if all_regions is not None else regions
    inst_index = []
    for r in regions:
        Analyser(r).run()
    for r in regions:
        index_hidden_pool_words(r, ctx)
    for r in regions:
        path = os.path.join(out_dir, _region_filename(r))
        stats.append(emit(r, path, ctx,
                          quirks=load_quirks(layout_dir, r.name),
                          inst_index=inst_index))
    write_inst_index(inst_index, os.path.join(out_dir, "inst_index.txt"))
    return stats


# ---------------------------------------------------------------------------
# translation unit splitting
# ---------------------------------------------------------------------------

# A unit is cut when it has collected at least this many functions and the
# next block boundary is safe, or earlier at a large run of data.
UNIT_TARGET_FUNCS = 180
UNIT_MAX_FUNCS = 300
UNIT_MIN_FUNCS = 40
BIG_DATA_RUN = 0x800


def _literal_spans(region):
    """(lo, hi) byte spans an instruction and the pool word it loads cover.

    A translation unit boundary must not fall inside one of these: GNU as
    resolves a PC-relative literal load at assembly time and can only do so
    when the pool sits in the same object file.
    """
    spans = []
    for off, rec in region.insns.items():
        tgt = _pc_relative_target(rec)
        if tgt is None:
            continue
        width = region.pools.get(tgt, 4)
        a, b = rec.addr, tgt + width
        spans.append((min(a, tgt), max(b, rec.addr + rec.size)))
    return spans


def _block_starts(region):
    """Offsets at which a new emitted block begins (a label or a data run)."""
    starts = set()
    off = 0
    n = len(region.data)
    in_data = False
    while off < n:
        addr = region.base + off
        if region.kind[off] == CODE and off in region.insns:
            in_data = False
            if addr in region.funcs:
                starts.add(off)
            off += region.insns[off].size
        else:
            if not in_data:
                starts.add(off)
                in_data = True
            off += 1
    return sorted(starts)


def plan_units(region):
    """Choose ordered (start_off, end_off) spans covering the whole region.

    A cut is made when the current unit has collected enough functions and
    the next block boundary is safe, or earlier at a large run of data, which
    is the closest thing to an object-file boundary a stripped image offers.
    Small regions scale the thresholds down so they still split at their own
    natural data boundaries instead of collapsing into one unit.
    """
    n = len(region.data)
    total_funcs = len(region.funcs)
    target = UNIT_TARGET_FUNCS
    min_funcs = UNIT_MIN_FUNCS
    big_run = BIG_DATA_RUN
    if total_funcs < UNIT_TARGET_FUNCS:
        # A region far smaller than one unit's worth of functions still gets
        # split, into roughly three units, so the same manifest-driven build
        # path is exercised for it instead of degenerating to one file.
        target = max(3, (total_funcs + 2) // 3)
        min_funcs = max(1, total_funcs // 4)
        big_run = max(0x40, min(BIG_DATA_RUN, n // 8))
    starts = _block_starts(region)
    if 0 not in starts:
        starts.insert(0, 0)
    spans = _literal_spans(region)

    def safe(off):
        addr = region.base + off
        # A Thumb literal load rounds PC down to a word boundary, and the
        # assembler only gets that right if the unit's own start address is
        # word aligned. It is also what keeps the linker from inserting
        # padding between two units.
        if addr & 3:
            return False
        for lo, hi in spans:
            if lo < addr < hi:
                return False
        return True

    # Length of the contiguous data run beginning at each block start.
    def data_run(off):
        if region.kind[off] == CODE:
            return 0
        end = off
        while end < n and region.kind[end] != CODE:
            end += 1
        return end - off

    units = []
    cut = 0
    funcs = 0
    for off in starts:
        if off <= cut:
            if region.base + off in region.funcs:
                funcs += 1
            continue
        addr = region.base + off
        is_func = addr in region.funcs
        big = data_run(off) >= big_run
        want = (funcs >= target
                or (big and funcs >= min_funcs)
                or funcs >= UNIT_MAX_FUNCS)
        if want and safe(off):
            units.append((cut, off))
            cut = off
            funcs = 0
        if is_func:
            funcs += 1
    if cut < n:
        units.append((cut, n))
    return units


def split_region(region, out_dir, all_regions, layout_dir, manifest_name,
                 repo_root):
    units = plan_units(region)
    quirks = load_quirks(layout_dir, region.name)
    os.makedirs(out_dir, exist_ok=True)
    entries = []
    inst_index = []
    for i, (lo, hi) in enumerate(units):
        base = region.base + lo
        fname = "%03d_%08X.s" % (i, base)
        path = os.path.join(out_dir, fname)
        st = emit_range(region, path, lo, hi, all_regions, quirks=quirks,
                        unit=(i, "%d translation units" % len(units)),
                        inst_index=inst_index)
        entries.append({
            "index": i,
            "file": os.path.relpath(path, repo_root).replace("\\", "/"),
            "base": base,
            "size": hi - lo,
            "functions": st["functions"],
            "code_bytes": st["code_bytes"],
        })
    manifest = {
        "tool": "disasm.py --split",
        "version": 1,
        "note": "ordered translation units for %s; file order, base addresses "
                "and sizes only, no game data" % region.name,
        "region": region.name,
        "base": region.base,
        "size": len(region.data),
        "units": entries,
    }
    mpath = os.path.join(layout_dir, manifest_name)
    with open(mpath, "w", encoding="utf-8", newline="\n") as fh:
        json.dump(manifest, fh, indent=1)
        fh.write("\n")
    write_inst_index(inst_index, os.path.join(out_dir, "inst_index.txt"))
    return entries, mpath


def _region_filename(r):
    if r.name.startswith("overlay_"):
        return "ov%s.s" % r.name.split("_")[1]
    return r.name.replace("arm9_", "") + ".s"


def print_stats(stats):
    total_code = sum(s["code_bytes"] for s in stats)
    total_size = sum(s["size"] for s in stats)
    print("    %-22s %9s %9s %7s %6s %6s"
          % ("region", "size", "code", "code%", "funcs", "pools"))
    for s in stats:
        print("    %-22s 0x%07X 0x%07X %6.1f%% %6d %6d"
              % (s["region"], s["size"], s["code_bytes"],
                 100.0 * s["code_bytes"] / max(1, s["size"]),
                 s["functions"], s["pools"]))
        if s["conflicts"]:
            print("      (%d instruction(s) retracted where a literal pool "
                  "overlapped a traced run)" % s["conflicts"])
    if len(stats) > 1:
        print("    %-22s 0x%07X 0x%07X %6.1f%%"
              % ("TOTAL", total_size, total_code,
                 100.0 * total_code / max(1, total_size)))


SPLIT_MANIFESTS = {
    "arm9_main": ("units_arm9.json", "src"),
    "arm9_itcm": ("units_itcm.json", "src_itcm"),
}


def cmd_arm9(args):
    layout = load_layout(args.layout)
    regions = build_arm9_regions(layout, args.extract, args.layout)
    out_dir = os.path.join(args.out, "arm9")
    print("[*] arm9: %d region(s)" % len(regions))
    stats = process(regions, out_dir, layout_dir=args.layout)
    print_stats(stats)
    for s in stats:
        print("[*] wrote %s" % s["path"])
    if args.split:
        repo = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
        for r in regions:
            entry = SPLIT_MANIFESTS.get(r.name)
            if not entry:
                continue
            manifest_name, sub = entry
            units, mpath = split_region(
                r, os.path.join(out_dir, sub), regions, args.layout,
                manifest_name, repo)
            print("[*] %s: %d translation unit(s) -> %s/%s/, manifest %s"
                  % (r.name, len(units), out_dir.replace("\\", "/"), sub,
                     mpath.replace("\\", "/")))
            fc = [u["functions"] for u in units]
            print("    functions per unit: min %d, max %d, total %d"
                  % (min(fc), max(fc), sum(fc)))
    return 0


_LAYOUT_BY_DIR = {}


def _overlay_job(job):
    """Disassemble one overlay: (region name, stats, inst_index rows)."""
    layout_dir, extract, ov_id, out_dir = job
    layout = _LAYOUT_BY_DIR.get(layout_dir)
    if layout is None:
        layout = _LAYOUT_BY_DIR[layout_dir] = load_layout(layout_dir)
    r = build_overlay_region(layout, extract, ov_id, layout_dir)
    Analyser(r).run()
    index_hidden_pool_words(r, [r])
    rows = []
    st = emit(r, os.path.join(out_dir, _region_filename(r)), [r],
              quirks=load_quirks(layout_dir, r.name), inst_index=rows)
    return r.name, st, rows


def cmd_overlay(args):
    layout = load_layout(args.layout)
    if args.all:
        ids = list(range(len(layout["overlays"])))
    else:
        if not args.ids:
            raise DisasmError("give one or more overlay ids, or --all")
        ids = args.ids
    out_dir = os.path.join(args.out, "overlays")
    stats = []
    inst_index = []
    touched = set()
    jobs = [(args.layout, args.extract, ov_id, out_dir) for ov_id in ids]
    workers = min(os.cpu_count() or 1, len(jobs))
    if workers > 1:
        # One overlay is independent of the others, so each runs in its own
        # process.  map() yields the results in id order, which keeps the
        # statistics and inst_index.txt rows in the order of a serial run.
        from concurrent.futures import ProcessPoolExecutor
        with ProcessPoolExecutor(max_workers=workers) as ex:
            results = list(ex.map(_overlay_job, jobs))
    else:
        results = [_overlay_job(j) for j in jobs]
    for name, st, rows in results:
        touched.add(name)
        stats.append(st)
        inst_index.extend(rows)
    print("[*] overlays: %d region(s)" % len(stats))
    print_stats(stats)
    # Merge with whatever inst_index.txt already had for overlays not
    # touched by this run, so disassembling a handful of ids at a time
    # never drops the other overlays' entries.
    index_path = os.path.join(out_dir, "inst_index.txt")
    kept = [e for e in _read_all_inst_index(index_path) if e[1] not in touched]
    write_inst_index(kept + inst_index, index_path)
    return 0


def cmd_twl(args):
    layout = load_layout(args.layout)
    r = build_twl_region(layout, args.extract, args.layout)
    if r is None:
        print("[*] twl: skipped (no decrypted arm9i; run tools/delink.py "
              "with --dsi-key, see tools/modcrypt.py)")
        return 0
    out_dir = os.path.join(args.out, "twl")
    inst_index = []
    Analyser(r).run()
    index_hidden_pool_words(r, [r])
    stats = [emit(r, os.path.join(out_dir, "twl.s"), [r],
                  quirks=load_quirks(args.layout, r.name),
                  inst_index=inst_index)]
    write_inst_index(inst_index, os.path.join(out_dir, "inst_index.txt"))
    print("[*] twl: 1 region")
    print_stats(stats)
    print("[*] wrote %s" % stats[0]["path"])
    return 0


def cmd_ov230d(args):
    layout = load_layout(args.layout)
    r = build_ov230d_region(layout, args.extract, args.layout)
    if r is None:
        print("[*] ov230d: skipped (no extract/ov230d.bin; run: python "
              "tools/ovcrypt.py write)")
        return 0
    out_dir = os.path.join(args.out, OV230D)
    inst_index = []
    Analyser(r).run()
    check_ov230d_trace(r)
    index_hidden_pool_words(r, [r])
    stats = [emit(r, os.path.join(out_dir, OV230D + ".s"), [r],
                  quirks=load_quirks(args.layout, r.name),
                  inst_index=inst_index)]
    write_inst_index(inst_index, os.path.join(out_dir, "inst_index.txt"))
    print("[*] ov230d: 1 region, %d decrypted range(s) traced as functions"
          % len(r.ov_ranges))
    print_stats(stats)
    print("[*] wrote %s" % stats[0]["path"])
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(
        prog="disasm.py",
        description="Disassemble ARM9 and overlay regions into asm/ listings.")
    ap.add_argument("-e", "--extract", default="extract")
    ap.add_argument("-l", "--layout", default="layout")
    ap.add_argument("-o", "--out", default="asm")
    sub = ap.add_subparsers(dest="cmd", required=True)

    p = sub.add_parser("arm9", help="disassemble the ARM9 static module and "
                                    "its autoload blocks")
    p.add_argument("--split", action="store_true",
                   help="also write ordered translation units under "
                        "asm/arm9/src/ plus layout/units_*.json manifests")
    p.set_defaults(func=cmd_arm9)

    p = sub.add_parser("overlay", help="disassemble one or more overlays")
    p.add_argument("ids", nargs="*", type=int)
    p.add_argument("--all", "--all-overlays", dest="all", action="store_true",
                   help="disassemble every overlay in the table")
    p.set_defaults(func=cmd_overlay)

    p = sub.add_parser("twl", help="disassemble the DSi-mode autoload block "
                                   "(needs the decrypted arm9i)")
    p.set_defaults(func=cmd_twl)

    p = sub.add_parser("ov230d", help="disassemble overlay 230 as its static "
                                      "initialisers decrypt it (needs "
                                      "extract/ov230d.bin, tools/ovcrypt.py)")
    p.set_defaults(func=cmd_ov230d)

    args = ap.parse_args(argv)
    try:
        return args.func(args)
    except DisasmError as exc:
        print("error: %s" % exc, file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
