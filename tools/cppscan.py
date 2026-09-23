#!/usr/bin/env python3
"""Evidence gathering for the question "is the game's own code C or C++?".

The ARM9 image links two very different bodies of code: the Nintendo TWL SDK
(and the DWC / GameSpy networking stack), which is known C, and the game's own
code.  ``layout/symbols_sdk.json`` says which addresses belong to the former,
so every measurement here is reported twice: once for addresses attributed to
an SDK library and once for the rest, which is the game.

Four independent measurements, none of which is conclusive on its own:

  vtables   Runs of consecutive word-aligned pointers into code.  A CodeWarrior
            C++ vtable for this target is ``[0][typeinfo][fn0][fn1]...`` and the
            object's vptr holds the address of ``fn0``, so the discriminating
            shape is a pointer run preceded by two non-code words (the first
            being zero) whose first element is itself the value of some other
            word in the image.  A plain C jump table or state-machine dispatch
            table is the same run of pointers *without* that header, so both
            numbers are reported.

  dispatch  Indirect calls (``blx <reg>``), split by how the called register
            was produced: two constant-offset loads (the virtual-call shape),
            one constant-offset load (a function pointer field), a
            register-offset load (``table[index]()``, which a virtual call can
            never be, because a virtual call's slot offset is a compile-time
            constant), a literal load, and everything else.  C code written as
            ``obj->ops->method(obj)`` produces the two-level shape as well, so
            that count bounds C++ virtual dispatch from above rather than
            proving any of it; two further columns narrow it, by counting the
            sites whose outer load is at offset 0 of the object (where a C++
            vptr lives) and the sites that test the loaded pointer against zero
            before calling it, which a C++ virtual call never does.

  strings   Metrowerks / CodeWarrior C++ runtime and RTTI spellings that would
            appear in the image if the C++ runtime or RTTI were linked.

  runtime   The decisive one.  A probe translation unit is compiled with the
            project's own CodeWarrior front end in ``-lang c++`` to learn which
            runtime entry points C++ actually needs on this toolchain, then
            those names are looked for in every library under ``sdk/`` and the
            game's static-initialiser lists are censused.  Any global object
            with a constructor forces a ``__sinit_<file>`` entry into the
            module's static-initialiser list, and any ``new``/``delete`` forces
            an external reference to the MSL C++ runtime.

Usage:

    python tools/cppscan.py all                       # everything, all regions
    python tools/cppscan.py vtables  --regions named
    python tools/cppscan.py dispatch --regions arm9,ov021
    python tools/cppscan.py strings
    python tools/cppscan.py runtime  --cc 1.1p1

``--regions`` takes ``all`` (default), ``named`` (the arm9 static module, the
four autoload blocks and overlays 9, 16, 21 and 114) or a comma separated list
of region names.

Nothing from ``sdk/`` or ``vendor/`` is copied anywhere; the SDK archives are
only ever read, and the probe translation unit is written to a temporary
directory.  Output is addresses, counts and symbol names only.
"""

from __future__ import annotations

import argparse
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile
import time
from array import array
from collections import defaultdict, Counter

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
if os.path.join(ROOT, "tools") not in sys.path:
    sys.path.insert(0, os.path.join(ROOT, "tools"))

import env as toolenv  # noqa: E402  (compiler location and wine runner)
sys.path.insert(0, os.path.join(ROOT, "tools"))

# One ar reader, one ELF32 reader, one region loader in this repository.
from libmatch import (  # noqa: E402
    Obj, cstr, load_regions, read_archive, find_archives,
)

NAMED_REGIONS = ["arm9", "arm9_autoload0_ITCM", "arm9_autoload1_MAIN_TWL",
                 "arm9_autoload2_MAIN_TWL", "arm9_autoload3_VRAM_LCDC",
                 "ov009", "ov016", "ov021", "ov114"]


# ---------------------------------------------------------------------------
# image + attribution
# ---------------------------------------------------------------------------

class Image:
    """The decompressed regions plus everything needed to attribute a hit."""

    def __init__(self, want=None, listings=True, quiet=False):
        with open(os.path.join(ROOT, "layout", "layout.json")) as fh:
            self.layout = json.load(fh)
        extract = os.path.join(ROOT, self.layout.get("extract_dir", "extract"))
        regs = load_regions(self.layout, extract, overlays=True)
        if want:
            keep = set(want)
            regs = [r for r in regs if r.name in keep]
        self.regions = regs
        self.by_name = {r.name: r for r in regs}
        self.quiet = quiet
        self._sdk = None
        self._labels = {}
        self._data = {}
        self._thumb = {}
        self._listings = listings

    # -- SDK attribution ---------------------------------------------------

    @property
    def sdk(self):
        """region -> (sorted starts array, sorted ends array, names list)."""
        if self._sdk is None:
            path = os.path.join(ROOT, "layout", "symbols_sdk.json")
            per = defaultdict(list)
            if os.path.exists(path):
                with open(path) as fh:
                    for e in json.load(fh)["symbols"]:
                        per[e["region"]].append(
                            (e["address"], e["address"] + e["size"], e["name"]))
            self._sdk = {}
            for reg, lst in per.items():
                lst.sort()
                self._sdk[reg] = (array("I", [a for a, b, n in lst]),
                                  array("I", [b for a, b, n in lst]),
                                  [n for a, b, n in lst])
        return self._sdk

    def in_sdk(self, region, addr):
        ent = self.sdk.get(region)
        if not ent:
            return None
        starts, ends, names = ent
        import bisect
        i = bisect.bisect_right(starts, addr) - 1
        if i >= 0 and addr < ends[i]:
            return names[i]
        return None

    # -- the project's own disassembly listings ----------------------------

    def listing_files(self, region):
        if region == "arm9":
            d = os.path.join(ROOT, "asm", "arm9", "src")
            if os.path.isdir(d):
                return [os.path.join(d, f) for f in sorted(os.listdir(d))
                        if f.endswith(".s")]
            return [os.path.join(ROOT, "asm", "arm9", "main.s")]
        if region.startswith("arm9_autoload0"):
            d = os.path.join(ROOT, "asm", "arm9", "src_itcm")
            if os.path.isdir(d):
                return [os.path.join(d, f) for f in sorted(os.listdir(d))
                        if f.endswith(".s")]
            return [os.path.join(ROOT, "asm", "arm9", "itcm.s")]
        special = {
            "arm9_autoload1_MAIN_TWL": "autoload1_main_twl.s",
            "arm9_autoload2_MAIN_TWL": "autoload2_main_twl.s",
            "arm9_autoload3_VRAM_LCDC": "vram_lcdc.s",
        }
        if region in special:
            return [os.path.join(ROOT, "asm", "arm9", special[region])]
        if region.startswith("ov"):
            return [os.path.join(ROOT, "asm", "overlays", "%s.s" % region)]
        return []

    _FUNC_RE = re.compile(rb"(?m)^func_([0-9A-Fa-f]{8}):")
    _WORD_RE = re.compile(
        rb"(?m)^\t\.word\t0x[0-9A-Fa-f]{8}[^/\n]*/\* ([0-9A-Fa-f]{8})")
    _BYTE_RE = re.compile(rb"(?m)^\t\.byte\t[^/\n]*/\* ([0-9A-Fa-f]{8})")
    _THUMB_RE = re.compile(rb"\t\.thumb_func\n\t\.type\tfunc_([0-9A-Fa-f]{8})")

    def _parse_listing(self, region):
        """(func starts, data addresses, Thumb func starts) for one region."""
        funcs = array("I")
        datas = array("I")
        thumbs = array("I")
        for path in self.listing_files(region):
            if not os.path.exists(path):
                continue
            with open(path, "rb") as fh:
                blob = fh.read()
            funcs.extend(int(m.group(1), 16) for m in self._FUNC_RE.finditer(blob))
            datas.extend(int(m.group(1), 16) for m in self._WORD_RE.finditer(blob))
            datas.extend(int(m.group(1), 16) for m in self._BYTE_RE.finditer(blob))
            thumbs.extend(int(m.group(1), 16)
                          for m in self._THUMB_RE.finditer(blob))
        return (array("I", sorted(set(funcs))), array("I", sorted(set(datas))),
                array("I", sorted(set(thumbs))))

    def funcs(self, region):
        if region not in self._labels:
            if not self._listings:
                self._labels[region] = array("I")
                self._data[region] = array("I")
                self._thumb[region] = array("I")
            else:
                f, d, t = self._parse_listing(region)
                self._labels[region] = f
                self._data[region] = d
                self._thumb[region] = t
        return self._labels[region]

    def thumb_funcs(self, region):
        self.funcs(region)
        return self._thumb[region]

    def in_thumb_code(self, region, addr):
        """Is addr inside a function the disassembler emitted as Thumb?

        Returns None when there are no listings to consult, so the caller can
        decide whether to fall back to scanning everything.
        """
        if not self._listings:
            return None
        f = self.enclosing_func(region, addr)
        if f is None:
            return False
        import bisect
        t = self.thumb_funcs(region)
        i = bisect.bisect_left(t, f)
        return i < len(t) and t[i] == f

    def datawords(self, region):
        self.funcs(region)
        return self._data[region]

    def is_func_start(self, region, addr):
        import bisect
        a = self.funcs(region)
        i = bisect.bisect_left(a, addr)
        return i < len(a) and a[i] == addr

    def is_data(self, region, addr):
        import bisect
        a = self.datawords(region)
        i = bisect.bisect_left(a, addr)
        return i < len(a) and a[i] == addr

    def enclosing_func(self, region, addr):
        """Start address of the function whose extent contains addr, or None."""
        import bisect
        a = self.funcs(region)
        if not a:
            return None
        i = bisect.bisect_right(a, addr) - 1
        return a[i] if i >= 0 else None

    def word(self, reg, addr):
        o = addr - reg.base
        if o < 0 or o + 4 > len(reg.data):
            return None
        return struct.unpack_from("<I", reg.data, o)[0]


def pick_regions(image_names, spec):
    if spec in (None, "", "all"):
        return list(image_names)
    if spec == "named":
        return [n for n in NAMED_REGIONS if n in image_names]
    want = [s.strip() for s in spec.split(",") if s.strip()]
    out = []
    for w in want:
        alt = ("ov%03d" % int(w)) if w.isdigit() else w
        if w in image_names:
            out.append(w)
        elif alt in image_names:
            out.append(alt)
        else:
            raise SystemExit("no such region: %s" % w)
    return out


# ---------------------------------------------------------------------------
# 1. vtable-shaped pointer tables
# ---------------------------------------------------------------------------

class Table:
    __slots__ = ("region", "addr", "count", "targets", "thumb", "header",
                 "in_data", "in_func", "sdk_targets", "referenced", "span",
                 "control")

    def as_dict(self):
        return {k: getattr(self, k) for k in self.__slots__}


def prologue_entry(reg, a, thumb):
    """Does a function prologue sit at address a in this region?

    CodeWarrior opens a non-leaf Thumb function with PUSH and a non-leaf ARM
    function with STMFD sp! or STR lr,[sp,#-4]!.  This is the fallback entry
    oracle for targets the project's disassembler did not reach, and it is
    deliberately narrow: it accepts only those prologues.
    """
    o = a - reg.base
    if o < 0 or o + 4 > len(reg.data):
        return False
    if thumb:
        hw = struct.unpack_from("<H", reg.data, o)[0]
        return (hw & 0xFE00) == 0xB400           # PUSH {..}, PUSH {.., lr}
    if o & 3:
        return False
    w = struct.unpack_from("<I", reg.data, o)[0]
    return (w & 0xFFFF0000) == 0xE92D0000 or w == 0xE52DE004


def code_pointer(img, reg, arm9, v, mode="either"):
    """Is v a pointer to a function entry, and is it Thumb?

    ``mode`` selects the entry oracle: ``listing`` trusts only the func_ labels
    the project's own disassembly produced, ``prologue`` only the instruction
    shape, ``either`` accepts both (the default, because the disassembler only
    reaches code it can prove is reachable and so misses real functions).
    """
    if v < 0x01000000 or v >= 0x0A000000:
        return False, False
    thumb = bool(v & 1)
    a = v & ~1
    for r, nm in ((reg, reg.name),
                  (arm9, "arm9") if arm9 is not None and reg.name != "arm9"
                  else (None, None)):
        if r is None or not (r.base <= a < r.base + len(r.data)):
            continue
        if mode in ("listing", "either") and img.is_func_start(nm, a):
            return True, thumb
        if mode in ("prologue", "either") and prologue_entry(r, a, thumb):
            return True, thumb
        return False, thumb
    return False, thumb


def find_tables(img, region, minlen=3, mode="either"):
    reg = img.by_name[region]
    arm9 = img.by_name.get("arm9")
    d = reg.data
    n = len(d) & ~3
    flags = bytearray(n // 4)
    thumbf = bytearray(n // 4)
    words = array("I")
    words.frombytes(d[:n])
    if sys.byteorder != "little":
        words.byteswap()
    for i, v in enumerate(words):
        ok, th = code_pointer(img, reg, arm9, v, mode)
        if ok:
            flags[i] = 1
            thumbf[i] = 1 if th else 0

    # every word value in the region, so "is this table's first slot the value
    # of some other word?" (the vptr initialiser) can be answered cheaply
    wordset = set(words)

    out = []
    i = 0
    nw = len(words)
    while i < nw:
        if not flags[i]:
            i += 1
            continue
        j = i
        while j < nw and flags[j]:
            j += 1
        if j - i >= minlen:
            addr = reg.base + i * 4
            tgts = [words[k] for k in range(i, j)]
            t = Table()
            t.region = region
            t.addr = addr
            t.count = j - i
            t.targets = tgts
            t.thumb = all(thumbf[k] for k in range(i, j))
            t.span = max(v & ~1 for v in tgts) - min(v & ~1 for v in tgts)
            # CodeWarrior vtable header: [offset-to-top = 0][typeinfo or 0]
            h0 = words[i - 2] if i >= 2 else None
            h1 = words[i - 1] if i >= 1 else None
            t.header = (h0 == 0 and h1 is not None and not flags[i - 1]
                        and (h1 == 0 or reg.base <= h1 < reg.base + len(d)))
            # control for the base rate of "a zero word happens to sit here":
            # the mirror image of the header, which means nothing at all
            t.control = (h1 == 0 and h0 is not None and h0 != 0)
            t.in_data = all(img.is_data(region, addr + 4 * k)
                            for k in range(j - i)) if img._listings else None
            f = img.enclosing_func(region, addr)
            t.in_func = bool(f is not None and not img.is_data(region, addr)) \
                if img._listings else None
            t.sdk_targets = sum(1 for v in tgts
                                if img.in_sdk(region, v & ~1) is not None)
            t.referenced = addr in wordset
            out.append(t)
        i = j
    return out


def cmd_vtables(args, img=None):
    img = img or Image(want=pick_regions(load_region_names(), args.regions),
                       listings=not args.no_listings)
    names = pick_regions([r.name for r in img.regions], args.regions)
    print("== 1. vtable-shaped pointer tables (runs of >= %d aligned words "
          "pointing at function entries)" % args.minlen)
    print("%-26s %7s %7s %7s %7s %7s %7s %7s"
          % ("region", "tables", "slots", "hdr", "hdr+ref", "ctl",
             "sdktgt", "jumptab"))
    tot = Counter()
    alltabs = []
    for name in names:
        tabs = find_tables(img, name, args.minlen, getattr(args, "entry", "either"))
        if not tabs and not args.verbose:
            continue
        sdk = [t for t in tabs if t.sdk_targets * 2 >= t.count]
        hdr = [t for t in tabs if t.header]
        hdrref = [t for t in hdr if t.referenced]
        indata = [t for t in tabs if t.in_data]
        # a switch/jump table: every target inside one function's extent and
        # close to the table itself
        jump = [t for t in tabs if t.span < 0x400]
        ctl = [t for t in tabs if t.control]
        print("%-26s %7d %7d %7d %7d %7d %7d %7d"
              % (name, len(tabs), sum(t.count for t in tabs),
                 len(hdr), len(hdrref), len(ctl), len(sdk), len(jump)))
        tot["ctl"] += len(ctl)
        tot["tables"] += len(tabs)
        tot["slots"] += sum(t.count for t in tabs)
        tot["in_data"] += len(indata)
        tot["hdr"] += len(hdr)
        tot["hdrref"] += len(hdrref)
        tot["sdk"] += len(sdk)
        tot["jump"] += len(jump)
        alltabs.extend(tabs)
    print("%-26s %7d %7d %7d %7d %7d %7d %7d"
          % ("TOTAL", tot["tables"], tot["slots"], tot["hdr"],
             tot["hdrref"], tot["ctl"], tot["sdk"], tot["jump"]))
    print("  (%d of %d tables sit entirely in words the disassembler"
          " classified as data)" % (tot["in_data"], tot["tables"]))
    print("  ctl     = control: preceded by [non-zero][0], the meaningless"
          " mirror of the header, as a base rate for a stray zero word")
    print("  hdr     = preceded by [0][0 or in-region pointer], the CodeWarrior"
          " vtable header shape")
    print("  hdr+ref = hdr, and the table's own address appears as a word"
          " elsewhere (a vptr initialiser would)")
    print("  sdktgt  = at least half the targets are inside a recovered SDK"
          " function")
    print("  jumptab = all targets within 0x400 of each other (switch table"
          " shape, not a vtable)")

    show = sorted(alltabs, key=lambda t: -t.count)
    if args.header_only:
        show = [t for t in show if t.header]
    print("\nlargest tables:")
    for t in show[:args.top]:
        print("  %-10s %08X  %3d slots  span %06X  %s%s%s%s sdk %d/%d"
              % (t.region, t.addr, t.count, t.span,
                 "thumb " if t.thumb else "arm   ",
                 "data " if t.in_data else "code ",
                 "HDR " if t.header else "    ",
                 "REF " if t.referenced else "    ",
                 t.sdk_targets, t.count))
    if args.json:
        with open(args.json, "w", newline="\n") as fh:
            json.dump([t.as_dict() for t in alltabs], fh, indent=1)
        print("wrote %s" % args.json)
    return alltabs


# ---------------------------------------------------------------------------
# 2. indirect dispatch shapes
# ---------------------------------------------------------------------------

# Thumb-1 encodings this needs.  The image is ARMv5TE, so BLX <reg> is the only
# register-form call and there is no Thumb-2 here.
def thumb_ldr_imm(hw):
    """(rd, rn, imm) for LDR rd,[rn,#imm], else None."""
    if (hw & 0xF800) == 0x6800:
        return hw & 7, (hw >> 3) & 7, ((hw >> 6) & 31) * 4
    return None


def thumb_ldr_lit(hw):
    """rd for LDR rd,=literal (PC relative), else None."""
    if (hw & 0xF800) == 0x4800:
        return (hw >> 8) & 7
    return None


def thumb_blx_reg(hw):
    if (hw & 0xFF87) == 0x4780:
        return (hw >> 3) & 15
    return None


def thumb_hi_mov(hw):
    """(rd, rm) for MOV rd,rm (including the high-register form), else None."""
    if (hw & 0xFF00) == 0x4600:
        return ((hw & 7) | ((hw >> 4) & 8)), (hw >> 3) & 15
    if (hw & 0xFE00) == 0x1C00 and ((hw >> 6) & 7) == 0:   # ADDS rd,rn,#0
        return hw & 7, (hw >> 3) & 7
    return None


def thumb_ldr_reg(hw):
    """(rd, rn, rm) for LDR rd,[rn,rm], else None.

    This is the register-offset form, i.e. ``table[index]``.  It matters a great
    deal here: a C++ virtual call always indexes the vtable at a constant slot,
    so it uses the immediate form; a C dispatch table indexed by a runtime value
    uses this one.
    """
    if (hw & 0xFE00) == 0x5800:
        return hw & 7, (hw >> 3) & 7, (hw >> 6) & 7
    return None


def thumb_ldr_sp(hw):
    if (hw & 0xF800) == 0x9800:
        return (hw >> 8) & 7
    return None


def thumb_pop(hw):
    """Register list of POP {..}, else None (POP {..,pc} included)."""
    if (hw & 0xFE00) == 0xBC00:
        return (hw & 0xFF) | (0x8000 if hw & 0x100 else 0)
    return None


def producer(hws, i, reg, window):
    """The most recent instruction before hws[i] that writes `reg`.

    Returns (kind, operands) where kind is one of ldr_imm / ldr_reg / ldr_lit /
    ldr_sp / mov / imm / unknown.  MOV chains are followed, so
    ``ldr r1,[r4,#8]; mov r3,r1; blx r3`` classifies on the load.
    """
    steps = 0
    while steps < 4:
        steps += 1
        found = None
        for k in range(1, window + 1):
            j = i - k
            if j < 0:
                break
            hw = hws[j]
            m = thumb_ldr_imm(hw)
            if m and m[0] == reg:
                return "ldr_imm", m, j
            m = thumb_ldr_reg(hw)
            if m and m[0] == reg:
                return "ldr_reg", m, j
            r = thumb_ldr_lit(hw)
            if r is not None and r == reg:
                return "ldr_lit", (r,), j
            r = thumb_ldr_sp(hw)
            if r is not None and r == reg:
                return "ldr_sp", (r,), j
            mv = thumb_hi_mov(hw)
            if mv and mv[0] == reg:
                found = (j, mv[1])
                break
            if (hw & 0xF800) == 0x2000 and ((hw >> 8) & 7) == reg:
                return "imm", (reg,), j
            pl = thumb_pop(hw)
            if pl is not None and (pl >> reg) & 1:
                return "pop", (reg,), j
        if found is None:
            return "unknown", (), -1
        i, reg = found
    return "unknown", (), -1



# ARM mode.  The SDK libraries are ARM, and so is a little of the ARM9 static
# module, so the same classification is run over ARM functions too.
def arm_ldr_imm(w):
    """(rd, rn, imm) for LDR rd,[rn,#imm] (immediate offset), else None."""
    if (w & 0x0E500000) == 0x04100000 and not (w & 0x02000000):
        imm = w & 0xFFF
        return (w >> 12) & 15, (w >> 16) & 15, imm if (w & 0x00800000) else -imm
    return None


def arm_ldr_reg(w):
    """(rd, rn, rm) for LDR rd,[rn,rm...] (register offset), else None."""
    if (w & 0x0E500010) == 0x06100000:
        return (w >> 12) & 15, (w >> 16) & 15, w & 15
    return None


def arm_blx_reg(w):
    if (w & 0x0FFFFFF0) == 0x012FFF30:
        return w & 15
    return None


def arm_mov_reg(w):
    if (w & 0x0FFF0FF0) == 0x01A00000:
        return (w >> 12) & 15, w & 15
    return None


def arm_producer(ws, i, reg, window):
    steps = 0
    while steps < 4:
        steps += 1
        found = None
        for k in range(1, window + 1):
            j = i - k
            if j < 0:
                break
            w = ws[j]
            m = arm_ldr_imm(w)
            if m and m[0] == reg:
                return "ldr_imm", m, j
            m = arm_ldr_reg(w)
            if m and m[0] == reg:
                return "ldr_reg", m, j
            mv = arm_mov_reg(w)
            if mv and mv[0] == reg:
                found = (j, mv[1])
                break
        if found is None:
            return "unknown", (), -1
        i, reg = found
    return "unknown", (), -1


# vcall     ldr rA,[rB,#i] ; ldr rC,[rA,#j] ; blx rC   two constant-offset loads
# obj_field ldr rC,[rB,#j] ; blx rC                    one constant-offset load
# tbl_field ldr rA,[rB,rI] ; ldr rC,[rA,#j] ; blx rC   table lookup, then a field
# indexed   ldr rC,[rB,rI] ; blx rC                    table[index]()
# literal   ldr rC,=fn ; blx rC                        a fixed function
# stack     the pointer came off the stack
# other     produced outside the window or by an unmodelled instruction
DISPATCH_KINDS = ("vcall", "obj_field", "tbl_field", "indexed", "literal",
                  "stack", "other")


def scan_dispatch(img, region, window=12, isa="both"):
    """Classify every ``blx <reg>`` in a region's code."""
    reg = img.by_name[region]
    d = reg.data
    n = len(d) & ~1
    hws = array("H")
    hws.frombytes(d[:n])
    if sys.byteorder != "little":
        hws.byteswap()

    counts = Counter()
    sdk_counts = Counter()
    sites = defaultdict(list)
    extra = Counter()
    for i in range(len(hws)) if isa in ("thumb", "both") else ():
        rm = thumb_blx_reg(hws[i])
        if rm is None:
            continue
        addr = reg.base + i * 2
        if img.in_thumb_code(region, addr) is False:
            continue          # ARM code or data: this halfword is not a blx
        kind1, ops1, at1 = producer(hws, i, rm, window)
        kind = "other"
        if kind1 == "ldr_imm":
            base = ops1[1]
            kind2, ops2, _at2 = producer(hws, at1, base, window * 2)
            if kind2 == "ldr_imm":
                kind = "vcall"
                if ops2[1] == 0:
                    extra["this"] += 1
                if ops2[2] == 0:
                    extra["vptr_at_0"] += 1
                # A C++ virtual call never tests the slot it just loaded; C
                # code calling an optional hook through a struct always does.
                if any(hws[k] == (0x2800 | (rm << 8))
                       for k in range(at1 + 1, i)):
                    extra["guarded"] += 1
            elif kind2 == "ldr_reg":
                kind = "tbl_field"
            else:
                kind = "obj_field"
        elif kind1 == "ldr_reg":
            kind = "indexed"
        elif kind1 == "ldr_lit":
            kind = "literal"
        elif kind1 in ("ldr_sp", "pop"):
            kind = "stack"
        counts[kind] += 1
        if img.in_sdk(region, addr) is not None:
            sdk_counts[kind] += 1
        if len(sites[kind]) < 60:
            sites[kind].append(addr)

    # ARM functions in the same region
    ws = array("I")
    ws.frombytes(d[:len(d) & ~3])
    if sys.byteorder != "little":
        ws.byteswap()
    for i in range(len(ws)) if isa in ("arm", "both") else ():
        rm = arm_blx_reg(ws[i])
        if rm is None:
            continue
        addr = reg.base + i * 4
        if img.in_thumb_code(region, addr) is not False:
            continue          # Thumb code or data: this word is not a blx
        kind1, ops1, at1 = arm_producer(ws, i, rm, window)
        kind = "other"
        if kind1 == "ldr_imm":
            base = ops1[1]
            kind2, ops2, _at2 = arm_producer(ws, at1, base, window * 2)
            if kind2 == "ldr_imm":
                kind = "vcall"
                if ops2[1] == 0:
                    extra["this"] += 1
                if ops2[2] == 0:
                    extra["vptr_at_0"] += 1
                if any(ws[k] & 0x0FFF0FFF == (0x03500000 | (rm << 16))
                       for k in range(at1 + 1, i)):
                    extra["guarded"] += 1
            elif kind2 == "ldr_reg":
                kind = "tbl_field"
            else:
                kind = "obj_field"
        elif kind1 == "ldr_reg":
            kind = "indexed"
        counts[kind] += 1
        extra["arm"] += 1
        if img.in_sdk(region, addr) is not None:
            sdk_counts[kind] += 1
            extra["arm_sdk"] += 1
        if len(sites[kind]) < 60:
            sites[kind].append(addr)
    return counts, sdk_counts, sites, extra


HDR = "%-26s" + " %8s" * len(DISPATCH_KINDS) + " %8s %6s %6s %6s"
ROW = "%-26s" + " %8d" * len(DISPATCH_KINDS) + " %8d %6d %6d %6d"


def cmd_dispatch(args, img=None):
    img = img or Image(want=pick_regions(load_region_names(), args.regions),
                       listings=not args.no_listings)
    names = pick_regions([r.name for r in img.regions], args.regions)
    print("== 2. Thumb indirect calls (blx <reg>), by how the called register"
          " was produced")
    print(HDR % (("region",) + DISPATCH_KINDS
                 + ("total", "this", "vp@0", "guard")))
    tot = Counter()
    sdktot = Counter()
    for name in names:
        c, s, sites, ex = scan_dispatch(img, name, args.window,
                                       getattr(args, "isa", "both"))
        total = sum(c.values())
        if not total and not args.verbose:
            continue
        print(ROW % ((name,) + tuple(c[k] for k in DISPATCH_KINDS)
                     + (total, ex["this"], ex["vptr_at_0"], ex["guarded"])))
        for k in DISPATCH_KINDS:
            tot[k] += c[k]
            sdktot[k] += s[k]
        for k in ("this", "vptr_at_0", "guarded", "arm", "arm_sdk"):
            tot[k] += ex[k]
        tot["total"] += total
        sdktot["total"] += sum(s.values())
        if args.show and c["vcall"]:
            print("     vcall sites: %s"
                  % " ".join("%08X" % a for a in sites["vcall"][:12]))
    print(ROW % (("TOTAL",) + tuple(tot[k] for k in DISPATCH_KINDS)
                 + (tot["total"], tot["this"], tot["vptr_at_0"],
                    tot["guarded"])))
    print(ROW % (("  in SDK code",) + tuple(sdktot[k] for k in DISPATCH_KINDS)
                 + (sdktot["total"], 0, 0, 0)))
    print(ROW % (("  game code",)
                 + tuple(tot[k] - sdktot[k] for k in DISPATCH_KINDS)
                 + (tot["total"] - sdktot["total"], 0, 0, 0)))
    print("  %d of the %d sites are in ARM functions (%d of those inside a"
          " recovered SDK function)" % (tot["arm"], tot["total"],
                                        tot["arm_sdk"]))
    gv = tot["vcall"] - sdktot["vcall"]
    gt = tot["total"] - sdktot["total"]
    if gt:
        print("  game code: vcall-shaped %d of %d indirect calls (%.1f%%)"
              % (gv, gt, 100.0 * gv / gt))
    print("  vcall     ldr rA,[rB,#i]; ldr rC,[rA,#j]; blx rC  two constant"
          " offsets: the virtual-call shape, and also C's obj->ops->fn()")
    print("  obj_field ldr rC,[rB,#j]; blx rC                  a function"
          " pointer field of a struct")
    print("  tbl_field ldr rA,[rB,rI]; ldr rC,[rA,#j]; blx rC  a table indexed"
          " at run time, then a field")
    print("  indexed   ldr rC,[rB,rI]; blx rC                  table[index]():"
          " a C dispatch table, never a virtual call")
    print("  this      vcall whose outer load was from r0 (the this/first"
          " argument)")
    print("  vp@0      vcall whose outer load was at offset 0 of the object,"
          " where a C++ vptr lives")
    print("  guard     vcall that tests the loaded pointer against 0 before"
          " calling it: a C optional hook, never a C++ virtual call")
    return tot, sdktot


# ---------------------------------------------------------------------------
# 3. C++ runtime / RTTI strings
# ---------------------------------------------------------------------------

# Spellings that only a C++ toolchain produces.  The first group is the
# CodeWarrior/Metrowerks pre-EABI mangling, the second the Itanium mangling this
# front end uses in -lang c++, the third the runtime and RTTI machinery.
CPP_TOKENS = [
    "__vt__", "__ti", "__RTTI", "__dt__", "__ct__", "__nw__", "__dl__",
    "__ptmf", "__construct_array", "__destroy_arr", "__destroy_new_array",
    "__register_global_object", "__deallocate", "__throw", "__cxa",
    "_ZTV", "_ZTI", "_ZTS", "_Znw", "_Znam", "_Zdl", "_Zda",
    "__cxxabiv", "typeinfo", "vtable", "operator new", "operator delete",
    "pure virtual", "bad_cast", "bad_typeid", "unwind", "Unwind",
    "std::", "basic_string", "__gxx", "__ptmf_call", "__ptmf_scall",
]

STR_RE = re.compile(rb"[\x20-\x7e]{5,}")


def cmd_strings(args, img=None):
    img = img or Image(want=pick_regions(load_region_names(), args.regions),
                       listings=False)
    names = pick_regions([r.name for r in img.regions], args.regions)
    print("== 3. C++ runtime / RTTI spellings in the image")
    toks = [t.encode("latin1") for t in CPP_TOKENS]
    hits = []
    total_strings = 0
    for name in names:
        reg = img.by_name[name]
        for m in STR_RE.finditer(reg.data):
            total_strings += 1
            s = m.group(0)
            for t, tok in zip(CPP_TOKENS, toks):
                if tok in s:
                    addr = reg.base + m.start()
                    hits.append((name, addr, t,
                                 s.decode("latin1")[:120],
                                 img.in_sdk(name, addr)))
                    break
    print("scanned %d regions, %d printable strings of >= 5 characters"
          % (len(names), total_strings))
    print("matches: %d" % len(hits))
    for name, addr, tok, s, sdk in hits[:args.top]:
        print("  %-10s %08X  [%s]  %s%s"
              % (name, addr, tok, s, "   (SDK: %s)" % sdk if sdk else ""))
    if not hits:
        print("  none: no C++ mangled name, RTTI type name, or C++ runtime"
              " diagnostic string appears anywhere in the image")
    by_tok = Counter(h[2] for h in hits)
    if by_tok:
        print("  by token: %s" % ", ".join("%s=%d" % kv
                                           for kv in by_tok.most_common()))
    return hits


# ---------------------------------------------------------------------------
# 4. what C++ actually needs on this toolchain, and whether the SDK has it
# ---------------------------------------------------------------------------

PROBE_CPP = r"""/* C++ feature probe.  Compiled only to read back which runtime entry
 * points this CodeWarrior front end emits references to; never linked,
 * never shipped.
 */
struct Base {
    int x;
    virtual void a(int);
    virtual int b();
    virtual ~Base();
};
struct Derived : Base {
    int y;
    virtual void a(int);
    virtual int b();
    virtual ~Derived();
};
void Base::a(int v) { x = v; }
int Base::b() { return x; }
Base::~Base() { x = 0; }
void Derived::a(int v) { y = v; }
int Derived::b() { return y; }
Derived::~Derived() { y = 0; }

int callit(Base *p) { p->a(3); return p->b(); }

typedef int (Base::*pmf)();
int callpmf(Base *p, pmf f) { return (p->*f)(); }

Derived *mk(void) { return new Derived(); }
void kill(Derived *d) { delete d; }
Derived *mkarr(void) { return new Derived[7]; }
void killarr(Derived *d) { delete [] d; }

static Derived g_static;
Derived *getg(void) { return &g_static; }
"""

PROBE_FLAGS = ["-proc", "arm946e", "-O4,p", "-enum", "int",
               "-Cpp_exceptions", "off", "-interworking", "-char", "signed",
               "-msgstyle", "gcc", "-thumb", "-lang", "c++"]


def object_symbols(data):
    """(defined, undefined) symbol name sets of one ELF32 relocatable."""
    obj = Obj("m", data)
    if not obj.ok:
        return set(), set()
    si = obj.symtab_index()
    if si < 0:
        return set(), set()
    sec = obj.sections[si]
    strtab = obj._strtab(obj.sections[sec[6]])
    dfn, und = set(), set()
    for i in range(sec[5] // 16):
        no, val, size, info, other, shndx = struct.unpack_from(
            "<IIIBBH", obj.data, sec[4] + i * 16)
        nm = cstr(strtab, no)
        if not nm or nm.startswith("$"):
            continue
        (und if shndx == 0 else dfn).add(nm)
    return dfn, und


def probe_compile(version, rtti):
    """Compile the probe with one front end.  ``version`` is a directory under
    tools/mwccarm/mwccarm/, either ``1.1p1`` (the dsi line, the default) or a
    two-part name such as ``2.0/sp2`` to reach an older tree."""
    exe = toolenv.mwcc_exe(version)
    if not os.path.exists(exe):
        raise SystemExit("no such compiler: %s" % version)
    work = tempfile.mkdtemp(prefix="cppscan_")
    try:
        src = os.path.join(work, "probe.cpp")
        with open(src, "w", newline="\n") as fh:
            fh.write(PROBE_CPP)
        obj = os.path.join(work, "probe.o")
        cmd = [exe] + PROBE_FLAGS + ["-RTTI", "on" if rtti else "off",
                                     "-c", "-o", obj, src]
        env = toolenv.wine_env(dict(os.environ))
        env.setdefault("MWLibraries", work)
        env.setdefault("MWLibraryFiles", " ")
        p = subprocess.run(toolenv.windows_cmd(cmd), cwd=work, capture_output=True,
                           timeout=180, env=env)
        if not os.path.exists(obj):
            return None, (p.stdout + p.stderr).decode("latin1", "replace")
        with open(obj, "rb") as fh:
            return fh.read(), ""
    finally:
        shutil.rmtree(work, ignore_errors=True)


# Symbols only a C++ compiler emits.  ``_ZZ<fn>E<var>`` is deliberately NOT in
# here: mwccarm mangles a function-local static that way even in plain C, so it
# is not evidence of anything and would otherwise swamp the result.
CPP_SYM_RE = re.compile(r"^(_ZN|_ZT[VIS]|_Zn[wa]|_Zd[la]|_Z\d"
                        r"|__cxa|__ptmf|__register_global_object"
                        r"|__construct_array|__destroy_arr|__destroy_new_array"
                        r"|__vt__|__ct__|__dt__|__nw__|__dl__|__throw)")
LOCAL_STATIC_RE = re.compile(r"^_ZZ")


def cmd_runtime(args, img=None):
    print("== 4a. what -lang c++ needs from the runtime on this toolchain")
    needed = []
    for rtti in (True, False):
        data, err = probe_compile(args.cc, rtti)
        if data is None:
            print("  %s -RTTI %s: compile failed: %s"
                  % (args.cc, "on" if rtti else "off", err.strip()[:200]))
            continue
        dfn, und = object_symbols(data)
        print("  mwccarm %s -RTTI %-3s  undefined: %s"
              % (args.cc, "on" if rtti else "off",
                 ", ".join(sorted(n for n in und if n)) or "(none)"))
        print("  %-20s     vtables/RTTI defined: %s"
              % ("", ", ".join(sorted(n for n in dfn
                                      if n.startswith(("_ZTV", "_ZTI", "_ZTS"))))
                 or "(none)"))
        if rtti:
            needed = sorted(n for n in und if n)
    print("  a vtable is emitted as [offset-to-top=0][typeinfo ptr]"
          "[virtual fn ptrs...] in .data, and the object's vptr points at the"
          " first function pointer")

    print("\n== 4b. does any library under sdk/ define a C++ runtime entry"
          " point, or any C++ symbol at all?")
    archives = find_archives(include_demos=True)
    if args.only:
        archives = [a for a in archives if args.only in a.replace("\\", "/")]
    cpp_defined = defaultdict(set)
    wanted_found = defaultdict(set)
    wanted = set(needed)
    nlocal = [0]
    nmembers = 0
    for ap in archives:
        try:
            if ap.endswith(".o"):
                with open(ap, "rb") as fh:
                    members = [(os.path.basename(ap), fh.read())]
            else:
                members = list(read_archive(ap))
        except Exception:
            continue
        for mname, mdata in members:
            nmembers += 1
            dfn, und = object_symbols(mdata)
            for nm in dfn:
                if CPP_SYM_RE.match(nm):
                    cpp_defined[nm].add(os.path.relpath(ap, ROOT))
                elif LOCAL_STATIC_RE.match(nm):
                    nlocal[0] += 1
                if nm in wanted:
                    wanted_found[nm].add(os.path.relpath(ap, ROOT))
    print("  scanned %d archives / %d object members under sdk/"
          % (len(archives), nmembers))
    print("  C++ runtime entry points the probe needs that sdk/ defines: %s"
          % (", ".join(sorted(wanted_found)) or "(none)"))
    print("  C++-only mangled symbols defined anywhere in sdk/: %d distinct"
          " name(s)" % len(cpp_defined))
    for nm in sorted(cpp_defined)[:20]:
        print("    %-40s %s" % (nm, sorted(cpp_defined[nm])[0]))
    print("  (%d _ZZ<fn>E<var> function-local statics ignored: mwccarm mangles"
          " those the same way in plain C)" % nlocal[0])

    print("\n== 4c. static-initialiser census (a global object with a"
          " constructor forces one entry)")
    for idx, kind, ptr, first in layout_autoload_sinit():
        print("  autoload %d (%-9s) list at %08X, first entry %s"
              % (idx, kind, ptr,
                 "%08X" % first if first is not None else "unreadable"))
    with open(os.path.join(ROOT, "layout", "layout.json")) as fh:
        layout = json.load(fh)
    regs = {r.name: r for r in load_regions(
        layout, os.path.join(ROOT, layout.get("extract_dir", "extract")),
        overlays=True)}
    nonempty = []
    for ov in layout["overlays"]:
        reg = regs.get("ov%03d" % ov["id"])
        if reg is None:
            continue
        s, e = ov.get("static_init_start", 0), ov.get("static_init_end", 0)
        vals = []
        for a in range(s, e, 4):
            o = a - reg.base
            if 0 <= o + 4 <= len(reg.data):
                vals.append(struct.unpack_from("<I", reg.data, o)[0])
        real = [v for v in vals if v]
        if real:
            nonempty.append((ov["id"], s, real))
    print("  overlays with a non-empty static-initialiser list: %d of %d"
          % (len(nonempty), len(layout["overlays"])))
    probe = Image(want=["ov%03d" % oid for oid, _s, _r in nonempty])
    for oid, s, real in nonempty:
        nf = len(probe.funcs("ov%03d" % oid))
        print("    ov%03d: the disassembler found %d function(s) in this"
              " overlay%s" % (oid, nf,
                              "; it is data, so these header fields are not a"
                              " static-initialiser list" if nf == 0 else ""))
    for oid, s, real in nonempty:
        print("    ov%03d at %08X: %s" % (oid, s, " ".join("%08X" % v
                                                           for v in real)))
    return 0


# ---------------------------------------------------------------------------
# driver
# ---------------------------------------------------------------------------

def layout_autoload_sinit():
    """(index, kind, list address, first word) for each ARM9 autoload block.

    The NitroSDK autoload walker hands each block's static-initialiser list to
    the appender, and the list is NULL terminated, so a first word of zero means
    the block registers no global constructor at all.
    """
    with open(os.path.join(ROOT, "layout", "layout.json")) as fh:
        layout = json.load(fh)
    extract = os.path.join(ROOT, layout.get("extract_dir", "extract"))
    regs = {r.name: r for r in load_regions(layout, extract, overlays=False)}
    out = []
    for al in layout["arm9"]["autoloads"]:
        name = "arm9_autoload%d_%s" % (al["index"], al["kind"])
        reg = regs.get(name)
        ptr = al.get("static_init_start", 0)
        first = None
        if reg is not None:
            o = ptr - reg.base
            if 0 <= o + 4 <= len(reg.data):
                first = struct.unpack_from("<I", reg.data, o)[0]
        out.append((al["index"], al["kind"], ptr, first))
    return out


def load_region_names():
    with open(os.path.join(ROOT, "layout", "layout.json")) as fh:
        layout = json.load(fh)
    names = ["arm9"]
    for al in layout["arm9"]["autoloads"]:
        names.append("arm9_autoload%d_%s" % (al["index"], al["kind"]))
    for ov in layout["overlays"]:
        names.append("ov%03d" % ov["id"])
    return names


def cmd_all(args):
    t0 = time.time()
    names = pick_regions(load_region_names(), args.regions)
    img = Image(want=names, listings=not args.no_listings)
    cmd_vtables(args, img)
    print()
    cmd_dispatch(args, img)
    print()
    cmd_strings(args, img)
    print()
    cmd_runtime(args, img)
    print("\ntotal %.1fs" % (time.time() - t0))
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="command", required=True)

    def common(p):
        p.add_argument("--regions", default="all",
                       help="all (default), named, or a comma separated list")
        p.add_argument("--no-listings", action="store_true",
                       help="do not read asm/*.s; disables the code/data and "
                            "function-entry oracles")
        p.add_argument("--top", type=int, default=40)
        p.add_argument("-v", "--verbose", action="store_true")

    p1 = sub.add_parser("vtables", help="pointer tables that look like vtables")
    common(p1)
    p1.add_argument("--minlen", type=int, default=3)
    p1.add_argument("--entry", default="either",
                    choices=("listing", "prologue", "either"),
                    help="which function-entry oracle a pointer target must satisfy")
    p1.add_argument("--header-only", action="store_true")
    p1.add_argument("--json", help="dump every table here")

    p2 = sub.add_parser("dispatch", help="indirect call shapes")
    common(p2)
    p2.add_argument("--window", type=int, default=12,
                    help="how many halfwords back to look for the producer")
    p2.add_argument("--show", action="store_true", help="print example sites")
    p2.add_argument("--isa", default="both", choices=("thumb", "arm", "both"),
                    help="restrict to Thumb functions (the game's own code) or "
                         "ARM functions (the SDK libraries)")

    p3 = sub.add_parser("strings", help="C++ runtime / RTTI spellings")
    common(p3)

    p4 = sub.add_parser("runtime", help="probe the compiler and search sdk/")
    common(p4)
    p4.add_argument("--cc", default="1.1p1", help="compiler dir under dsi/")
    p4.add_argument("--only", help="substring filter on archive path")

    p5 = sub.add_parser("all", help="every measurement")
    common(p5)
    p5.add_argument("--minlen", type=int, default=3)
    p5.add_argument("--entry", default="either",
                    choices=("listing", "prologue", "either"))
    p5.add_argument("--header-only", action="store_true")
    p5.add_argument("--json")
    p5.add_argument("--window", type=int, default=12)
    p5.add_argument("--show", action="store_true")
    p5.add_argument("--isa", default="both", choices=("thumb", "arm", "both"))
    p5.add_argument("--cc", default="1.1p1")
    p5.add_argument("--only")

    args = ap.parse_args(argv)
    if args.command == "all":
        return cmd_all(args)
    fn = {"vtables": cmd_vtables, "dispatch": cmd_dispatch,
          "strings": cmd_strings, "runtime": cmd_runtime}[args.command]
    fn(args)
    return 0


if __name__ == "__main__":
    sys.exit(main())
