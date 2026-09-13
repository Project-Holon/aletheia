#!/usr/bin/env python3
"""
disasm.py -- honest ARM/Thumb disassembly listings for the aletheia project.

Written from scratch. The only third-party dependency is Capstone, which is
used purely as a generic instruction decoder; every piece of analysis here
(entry point discovery, mode tracking, literal pool handling, function
boundary detection, code/data classification, output formatting) is original.

    pip install capstone

Usage
-----
    python tools/disasm.py arm9
    python tools/disasm.py overlay 12
    python tools/disasm.py overlay --all

Output goes to asm/arm9/*.s and asm/overlays/ov###.s.

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

5. Emission. Call targets become ``func_02xxxxxx``, other branch targets
   become ``loc_02xxxxxx``, pool words become ``pool_02xxxxxx``. Branch
   operands and PC-relative loads are rewritten to reference those labels so
   the listing says what the code means rather than where it happened to be
   assembled.

Fidelity caveat
---------------
The output is GNU as syntax and is meant to be reassembled eventually, but
that has not been demonstrated yet. Where Capstone renders an instruction in
a form that GNU as would reject or re-encode differently (notably rotated
immediates printed as ``#imm, #rot``), the bytes are emitted as ``.word``
with the decoded text in a comment instead of as an instruction.
"""

import argparse
import json
import os
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
        self.conflicts = []

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

    def add_seed(self, addr, thumb, is_func=True):
        r = self.r
        if not r.contains(addr):
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
                    if tgt is not None:
                        flips = mnem.startswith("blx")
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
                self.add_seed(r.base + off, True, is_func=True)
                added += 1
                self.trace()
        return added

    def run(self):
        r = self.r
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
    return None


def _rewrite_operands(region, rec):
    """Replace raw immediates with labels where we know what they mean."""
    text = rec.text
    parts = text.split("\t", 1)
    mnem = parts[0]
    ops = parts[1] if len(parts) > 1 else ""
    base_mnem = mnem.split(".")[0]

    if not ops:
        return text, None

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
                return "%s\t%s" % (mnem, lab), None
            if region.contains(tgt):
                return ("%s\t0x%08X" % (mnem, tgt),
                        "target not classified as code")
            return "%s\t0x%08X" % (mnem, tgt), "outside this region"

    # PC-relative loads: point them at the pool label we created.
    if "[pc" in ops:
        tgt = _pc_relative_target(rec)
        if tgt is not None and tgt in region.pools:
            head = ops.split(",")[0].strip()
            return "%s\t%s, pool_%08X" % (mnem, head, tgt), None

    return text, None


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


def emit(region, out_path, all_regions, header_extra=""):
    r = region
    os.makedirs(os.path.dirname(out_path), exist_ok=True)

    code_bytes = sum(1 for v in r.kind if v == CODE)
    data_bytes = len(r.kind) - code_bytes

    lines = []
    add = lines.append
    add("/*")
    add(" * %s" % r.name)
    add(" * generated by tools/disasm.py; do not edit, do not commit")
    add(" *")
    add(" * source        %s" % r.source)
    add(" * address range 0x%08X..0x%08X (0x%X bytes)"
        % (r.base, r.end, len(r.data)))
    add(" * classified    0x%X bytes code (%.1f%%), 0x%X bytes data (%.1f%%)"
        % (code_bytes, 100.0 * code_bytes / max(1, len(r.data)),
           data_bytes, 100.0 * data_bytes / max(1, len(r.data))))
    add(" * functions     %d" % len(r.funcs))
    if r.note:
        add(" *")
        add(" * %s" % r.note)
    if header_extra:
        for ln in header_extra.splitlines():
            add(" * %s" % ln)
    add(" *")
    add(" * Anything not reached from a known entry point is emitted as data")
    add(" * words rather than guessed at.")
    add(" */")
    add("")
    add("\t.section\t.text.%s, \"ax\", %%progbits" % _ident(r.name))
    add("")

    cur_thumb = None
    off = 0
    n = len(r.data)
    pending_data = []

    def flush_data():
        if not pending_data:
            return
        start = pending_data[0]
        buf = bytes(r.data[start:pending_data[-1] + 1])
        _emit_data(add, r, start, buf, all_regions)
        pending_data.clear()

    while off < n:
        addr = r.base + off
        if r.kind[off] == CODE and off in r.insns:
            flush_data()
            rec = r.insns[off]
            if rec.thumb != cur_thumb:
                add("")
                add("\t.thumb" if rec.thumb else "\t.arm")
                cur_thumb = rec.thumb
            lab = _label_for(r, addr)
            if lab:
                add("")
                if lab.startswith("func_"):
                    add("\t.global\t%s" % lab)
                    if rec.thumb:
                        add("\t.thumb_func")
                    add("\t.type\t%s, %%function" % lab)
                add("%s:" % lab)
            text, comment = _rewrite_operands(r, rec)
            raw = " ".join("%02X" % b for b in rec.raw)
            if _is_unassemblable(text):
                # Keep the bytes exact; the decode stays as documentation.
                for k in range(0, rec.size, 4):
                    chunk = rec.raw[k:k + 4]
                    if len(chunk) == 4:
                        add("\t.word\t0x%08X"
                            % struct.unpack("<I", chunk)[0]
                            + "\t\t/* %08X  %s  (not reassemblable as "
                              "written) */" % (addr + k,
                                               text.replace("\t", " ")))
                    else:
                        add("\t.byte\t%s"
                            % ", ".join("0x%02X" % b for b in chunk))
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
    add("\t.end")
    add("")

    with open(out_path, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("\n".join(lines))

    return {
        "region": r.name,
        "base": r.base,
        "size": len(r.data),
        "code_bytes": code_bytes,
        "data_bytes": data_bytes,
        "functions": len(r.funcs),
        "pools": len(r.pools),
        "conflicts": len(r.conflicts),
        "path": out_path,
    }


def _ident(name):
    return "".join(c if c.isalnum() or c == "_" else "_" for c in name)


def _emit_data(add, region, start, buf, all_regions):
    r = region
    add("")
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


def build_arm9_regions(layout, extract_dir):
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
        seeds=[(a9["entry_point"], False)],
        note="bss 0x%08X..0x%08X is not part of this image"
             % (st["bss_start"], st["bss_end"]))
    regions.append(main)

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
        regions.append(Region(name, al["ram_start"], data,
                              "extract/arm9_dec.bin + 0x%X" % al["src_offset"],
                              seeds=seeds, note=note))
    return regions


def build_overlay_region(layout, extract_dir, ov_id):
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
    note = ("static initialisers 0x%08X..0x%08X (%d entry/entries); "
            "bss 0x%08X..0x%08X"
            % (lo, hi, o["static_init_count"], o["bss_start"], o["bss_end"]))
    if o["compressed"]:
        note += "; BLZ compressed on ROM (0x%X bytes)" % o["compressed_size"]
    return Region("overlay_%03d" % ov_id, base, data,
                  "extract/" + o["decompressed_file"], seeds=seeds, note=note)


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def process(regions, out_dir, all_regions=None):
    stats = []
    ctx = all_regions if all_regions is not None else regions
    for r in regions:
        Analyser(r).run()
    for r in regions:
        path = os.path.join(out_dir, _region_filename(r))
        stats.append(emit(r, path, ctx))
    return stats


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


def cmd_arm9(args):
    layout = load_layout(args.layout)
    regions = build_arm9_regions(layout, args.extract)
    out_dir = os.path.join(args.out, "arm9")
    print("[*] arm9: %d region(s)" % len(regions))
    stats = process(regions, out_dir)
    print_stats(stats)
    for s in stats:
        print("[*] wrote %s" % s["path"])
    return 0


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
    for ov_id in ids:
        r = build_overlay_region(layout, args.extract, ov_id)
        Analyser(r).run()
        stats.append(emit(r, os.path.join(out_dir, _region_filename(r)), [r]))
    print("[*] overlays: %d region(s)" % len(stats))
    print_stats(stats)
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
    p.set_defaults(func=cmd_arm9)

    p = sub.add_parser("overlay", help="disassemble one or more overlays")
    p.add_argument("ids", nargs="*", type=int)
    p.add_argument("--all", "--all-overlays", dest="all", action="store_true",
                   help="disassemble every overlay in the table")
    p.set_defaults(func=cmd_overlay)

    args = ap.parse_args(argv)
    try:
        return args.func(args)
    except DisasmError as exc:
        print("error: %s" % exc, file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
