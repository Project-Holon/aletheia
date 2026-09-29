#!/usr/bin/env python3
"""Function-level matching harness.

Compiles one C (or C++) translation unit with a CodeWarrior / Freescale ARM
front end from ``tools/mwccarm/mwccarm/dsi/``, pulls a named function's bytes
out of the resulting ELF object, and compares them with the original bytes at
a target address in the game image.

Bytes the linker would have rewritten are handled in one of two ways.  Where
the target symbol's address is known and independently attested, the harness
does the linker's job: it places the code at its target address and writes
the relocation field itself (Thumb BL/BLX pairs, ARM B/BL displacements,
ABS32 words), so the comparison covers every byte.  Where the address is not
known, or is only "known" from the bytes about to be compared, the field
stays wildcarded and the entry cannot reach EXACT.  See "symbol addresses"
below for the honesty rule that draws that line; it is the whole reason this
file has a symbol map at all.

Verdicts:

    EXACT    every byte identical, relocation fields included
    MATCH    identical except at relocation fields that stayed wildcarded
             because their target address has no independent witness
    SIZE     the compiler produced a different number of bytes
    DIFF     same size, but concrete bytes differ

Usage:

    python tools/match.py one  --src src/matched/foo.c --func Foo \\
        --addr 0x02075DD8 --cc 1.1p1
    python tools/match.py one  ... --diff            # two-column disassembly
    python tools/match.py sweep --src ... --func ... --addr ...
    python tools/match.py sweep ... --cpp            # also try -lang c++
    python tools/match.py tu   --src ... --addr ...  # whole translation unit
    python tools/match.py tu   ... --suggest-split   # where to cut a MATCH unit
    python tools/match.py manifest --verify          # every shard of layout/matched/
    python tools/match.py manifest --verify --shard pkt_0209CE10
    python tools/match.py selftest                   # the attestation rules
    python tools/match.py idioms                     # regenerate the idiom index

The manifest is one file per work packet under ``layout/matched/<region>/``,
so two agents working different packets never write the same file.  See
"manifest shards" below and docs/PARALLEL.md.

Nothing from ``sdk/`` or ``vendor/`` is copied here; SDK headers are only ever
reached through ``-I sdk/TwlSDK/include`` at compile time.
"""

from __future__ import annotations

import argparse
import bisect
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

# The ELF32 reader, the ar reader and the relocation width table all come from
# libmatch.py; there is exactly one implementation of each in this repository.
from libmatch import (  # noqa: E402
    Obj, cstr, load_regions, RELOC_MASK, RELOC_DEFAULT,
    SHT_PROGBITS, SHT_RELA, SHT_REL, STT_FUNC,
)
from cw import versions_dir, verkey  # noqa: E402
import env as toolenv  # noqa: E402  (compiler location and wine runner)

SDK_INCLUDE = "sdk/TwlSDK/include"

# ---------------------------------------------------------------------------
# compiler configuration
# ---------------------------------------------------------------------------

# Flags every configuration carries.  These are not a guess: -proc arm946e is
# the hardware, -enum int and -char signed are what the SDK's commondefs set,
# and -interworking is required for a ROM that mixes ARM and Thumb.
BASE_FLAGS = [
    "-proc", "arm946e",
    "-enum", "int",
    "-Cpp_exceptions", "off",
    "-interworking",
    "-char", "signed",
    "-msgstyle", "gcc",
]

# Optimisation spellings the sweep crosses with every compiler version.
# mwccarm writes the speed/space bias as a suffix on -O4; -Otime / -Ospace do
# not exist in this front end (they are rejected), which is why the list uses
# the comma spelling only.
SWEEP_OPTS = [
    ["-O4,p"],
    ["-O4,s"],
    ["-O4"],
    ["-O3"],
    ["-O2"],
    ["-O1"],
    ["-O0"],
]

SWEEP_EXTRA = [
    ["-O4,p", "-inline", "off"],
    ["-O4,p", "-inline", "all"],
    ["-O4,p", "-ipa", "function"],
    ["-O4,s", "-inline", "off"],
]


def compiler_path(version):
    p = toolenv.mwcc_exe(version)
    if not os.path.exists(p):
        raise SystemExit("no such compiler: dsi/%s (%s)" % (version, p))
    return p


def all_versions():
    return [n for n, _p in versions_dir()]


# ---------------------------------------------------------------------------
# compile
# ---------------------------------------------------------------------------

def compile_tu(src, version, flags, thumb, lang, workdir, sdk_include=True,
               extra_includes=()):
    """Compile one TU.  Returns (obj_path, cmdline, stdout+stderr, rc)."""
    exe = compiler_path(version)
    cmd = [exe] + list(BASE_FLAGS) + list(flags)
    if thumb:
        cmd += ["-thumb"]
    if lang:
        cmd += ["-lang", lang]
    cmd += ["-ir", os.path.dirname(os.path.abspath(src)) or "."]
    if sdk_include and os.path.isdir(SDK_INCLUDE):
        cmd += ["-I+" + SDK_INCLUDE]
    for inc in extra_includes:
        cmd += ["-I+" + inc]
    obj = os.path.join(workdir, "tu.o")
    cmd += ["-c", "-o", obj, os.path.abspath(src)]

    env = dict(os.environ)
    env.setdefault("MWLibraries", workdir)
    env.setdefault("MWLibraryFiles", " ")
    toolenv.wine_env(env)
    try:
        cmd = toolenv.windows_cmd(cmd)
    except toolenv.EnvError as exc:
        return None, cmd, str(exc), 127
    try:
        p = subprocess.run(cmd, cwd=workdir, capture_output=True, timeout=900, env=env)

    except Exception as exc:
        return None, cmd, str(exc), 127
    text = (p.stdout + b"\n" + p.stderr).decode("latin1", "replace")
    if p.returncode != 0 or not os.path.exists(obj):
        return None, cmd, text, p.returncode
    return obj, cmd, text, 0


# ---------------------------------------------------------------------------
# object inspection
# ---------------------------------------------------------------------------

class FuncBytes:
    """A function extracted from a relocatable object."""

    __slots__ = ("name", "data", "mask", "thumb", "section", "relocs",
                 "locals", "sites", "anon")

    def __init__(self, name, data, mask, thumb, section, relocs, locals_=None):
        self.name = name
        self.data = data        # bytes as the compiler emitted them
        self.mask = mask        # bytearray, 1 = concrete, 0 = linker-rewritten
        self.thumb = thumb
        self.section = section
        self.relocs = relocs    # list of (offset, type, symbol name, addend)
        self.locals = locals_ or {}   # symbol -> offset within self.data
        self.sites = []         # filled in by resolve_relocations()
        self.anon = {}          # "@N" local data object -> its bytes

    @property
    def size(self):
        return len(self.data)


def read_symbols(obj):
    si = obj.symtab_index()
    if si < 0:
        return [], b""
    symsec = obj.sections[si]
    strtab = obj._strtab(obj.sections[symsec[6]])
    out = []
    for i in range(symsec[5] // 16):
        nameoff, value, size, info, other, shndx = struct.unpack_from(
            "<IIIBBH", obj.data, symsec[4] + i * 16)
        out.append((cstr(strtab, nameoff), value, size, info & 0xF, info >> 4, shndx))
    return out, strtab


def section_relocs(obj, target_index):
    """Return [(offset, rtype, symbol_name, addend)] for one section.

    mwccarm writes SHT_RELA, so the addend is explicit; the SHT_REL branch is
    kept because the ELF reader supports both and the addend is then whatever
    the field already holds, which the caller reads for itself.
    """
    syms, _ = read_symbols(obj)
    out = []
    for s in obj.sections:
        if s[1] not in (SHT_RELA, SHT_REL) or s[7] != target_index:
            continue
        rela = (s[1] == SHT_RELA)
        entsz = s[9] or (12 if rela else 8)
        for j in range(s[5] // entsz):
            base = s[4] + j * entsz
            off, info = struct.unpack_from("<II", obj.data, base)
            addend = struct.unpack_from("<i", obj.data, base + 8)[0] if rela else 0
            rtype = info & 0xFF
            symi = info >> 8
            sname = syms[symi][0] if symi < len(syms) else ""
            out.append((off, rtype, sname, addend))
    out.sort()
    return out


_ITANIUM_RE = re.compile(r"^_Z(N?)(\d+)(.*)$")


def demangle(name):
    """Recover the source name from the two manglings mwccarm emits.

    In ``-lang c++`` this front end writes Itanium-style ``_Z<len><name>...``
    (and ``_ZN<len><ns><len><name>...`` for a member); older CodeWarrior
    output uses ``<name>__<signature>``.  Only the trailing identifier is
    needed here, because --func names the function as it is written in the
    source.
    """
    m = _ITANIUM_RE.match(name)
    if m:
        rest = m.group(3)
        n = int(m.group(2))
        last = rest[:n]
        rest = rest[n:]
        # Nested names repeat <len><ident>; the last one is the function.
        while m.group(1) == "N":
            m2 = re.match(r"^(\d+)(.*)$", rest)
            if not m2:
                break
            n = int(m2.group(1))
            last = m2.group(2)[:n]
            rest = m2.group(2)[n:]
        return last
    i = name.find("__")
    if i > 0:
        return name[:i]
    return name


def extract_function(obj_path, func, prefer_thumb=None):
    """Pull one function out of a CodeWarrior object.  Returns FuncBytes."""
    with open(obj_path, "rb") as fh:
        obj = Obj(os.path.basename(obj_path), fh.read())
    if not obj.ok:
        raise SystemExit("cannot parse %s as ELF32 ARM" % obj_path)
    syms, _ = read_symbols(obj)

    cands = []
    for name, value, size, typ, bind, shndx in syms:
        if typ != STT_FUNC or shndx == 0 or shndx >= len(obj.sections):
            continue
        if name != func and demangle(name) != func:
            continue
        cands.append((name, value, size, shndx))
    if not cands:
        avail = sorted({n for n, v, s, t, b, sh in syms
                        if t == STT_FUNC and sh and sh < len(obj.sections)})
        raise SystemExit("function %r not found in %s; object defines: %s"
                         % (func, os.path.basename(obj_path), ", ".join(avail) or "(none)"))
    if len(cands) > 1:
        exact = [c for c in cands if c[0] == func]
        if exact:
            cands = exact
    name, value, size, shndx = cands[0]

    sec = obj.sections[shndx]
    if sec[1] != SHT_PROGBITS:
        raise SystemExit("%s is not in a PROGBITS section" % name)
    body = obj.section_data(shndx)
    if size == 0:
        size = len(body) - value
    if value + size > len(body):
        raise SystemExit("%s runs past its section" % name)
    blob = bytes(body[value:value + size])

    mask = bytearray(b"\x01" * size)
    rels = []
    for off, rtype, sname, addend in section_relocs(obj, shndx):
        if off < value or off >= value + size:
            continue
        lo, width = RELOC_MASK.get(rtype, RELOC_DEFAULT)
        start = off - value + lo
        for k in range(start, min(start + width, size)):
            if k >= 0:
                mask[k] = 0
        rels.append((off - value, rtype, sname, addend))

    # ARM mapping symbols say which instruction set the function was emitted in.
    thumb = bool(prefer_thumb)
    maps = sorted((v, n) for n, v, sz, t, b, sh in syms
                  if sh == shndx and n in ("$a", "$t", "$d"))
    cur = None
    for mv, mn in maps:
        if mv <= value and mn in ("$a", "$t"):
            cur = mn
        elif mv > value:
            break
    if cur is not None:
        thumb = (cur == "$t")

    # Any symbol of this same section lands at a known offset inside the
    # extracted blob, so a reference to it resolves without a symbol map.
    locals_ = {n: v - value for n, v, sz, t, b, sh in syms
               if sh == shndx and not n.startswith("$")
               and value <= v < value + size}
    fb = FuncBytes(name, blob, mask, thumb, obj.secnames[shndx], rels,
                   locals_)
    # The compiler's anonymous data objects (`@N` initializer templates) the
    # function relocates against, with their bytes, for the `template` rule.
    wanted = set(r[2] for r in rels)
    for n, v, sz, t, b, sh in syms:
        if (n in wanted and n.startswith("@") and t == 1 and sz > 0
                and 0 < sh < len(obj.sections)
                and obj.sections[sh][1] == SHT_PROGBITS):
            fb.anon[n] = bytes(obj.section_data(sh)[v:v + sz])
    return fb


# ---------------------------------------------------------------------------
# target bytes
# ---------------------------------------------------------------------------

_REGION_CACHE = {}


def load_all_regions():
    if "regions" in _REGION_CACHE:
        return _REGION_CACHE["regions"]
    with open(os.path.join(ROOT, "layout", "layout.json")) as fh:
        layout = json.load(fh)
    extract = os.path.join(ROOT, layout.get("extract_dir", "extract"))
    regs = load_regions(layout, extract, overlays=True)
    _REGION_CACHE["regions"] = regs
    return regs


def find_region(addr, name=None):
    for r in load_all_regions():
        if name is not None:
            if r.name == name:
                return r
            continue
        if r.base <= addr < r.base + len(r.data):
            return r
    if name is not None:
        raise SystemExit("no region named %r" % name)
    raise SystemExit("address %#010x is in no known region" % addr)


def target_bytes(addr, size, region=None):
    r = find_region(addr, region)
    off = addr - r.base
    if off < 0 or off + size > len(r.data):
        raise SystemExit("%#010x+%d runs past region %s" % (addr, size, r.name))
    return r.name, bytes(r.data[off:off + size])


# ---------------------------------------------------------------------------
# the target's own function extent, from the generated listings
# ---------------------------------------------------------------------------

_FUNC_STARTS = {}


def unit_files(sub, manifest, root=None):
    """The split listings named by a layout/units_*.json manifest.

    disasm.py --split never deletes the files of an earlier run, so the
    directory can hold stale units whose labels no longer exist; only the
    files the current manifest lists are read.  Without a manifest, fall
    back to every .s file in the directory."""
    root = root or ROOT
    d = os.path.join(root, "asm", "arm9", sub)
    if not os.path.isdir(d):
        return []
    try:
        with open(os.path.join(root, "layout", manifest)) as fh:
            units = json.load(fh)["units"]
        return [os.path.join(root, u["file"]) for u in units
                if os.path.exists(os.path.join(root, u["file"]))]
    except (OSError, ValueError, KeyError):
        return [os.path.join(d, f) for f in sorted(os.listdir(d))
                if f.endswith(".s")]


def listing_files(region):
    if region == "arm9":
        return unit_files("src", "units_arm9.json")
    elif region.startswith("arm9_autoload0"):
        return unit_files("src_itcm", "units_itcm.json")
    elif region == OV230D_REGION:
        # before the ovNNN branch: `ov230d` is not asm/overlays/ov230d.s
        return ov230d_listing_files()
    elif region.startswith("ov"):
        p = os.path.join(ROOT, "asm", "overlays", "ov%s.s" % region[2:])
        return [p] if os.path.exists(p) else []
    elif region == TWL_REGION:
        return twl_listing_files()
    else:
        return []


def scan_listing(region):
    """Return {addr: is_thumb} for every func_ label the listings declare."""
    if region in _FUNC_STARTS:
        return _FUNC_STARTS[region]
    starts = {}
    for path in listing_files(region):
        # disasm.py emits ".thumb" / ".arm" as the section-wide state and
        # ".thumb_func" immediately before each Thumb entry point, with the
        # ".type" directive sitting between that and the label.
        mode_thumb = False
        pending_thumb = None
        try:
            with open(path, "r", errors="replace") as fh:
                for line in fh:
                    s = line.strip()
                    if s == ".thumb_func":
                        pending_thumb = True
                        continue
                    if s in (".thumb", ".code 16"):
                        mode_thumb = True
                        continue
                    if s in (".arm", ".code 32"):
                        mode_thumb = False
                        continue
                    if s.startswith("func_") and s.endswith(":"):
                        a = int(s[5:-1], 16)
                        starts[a] = mode_thumb if pending_thumb is None else True
                        pending_thumb = None
                    elif s.startswith("veneer_") and s.endswith(":"):
                        a = int(s[7:-1], 16)
                        starts[a] = False
                        pending_thumb = None
                    elif s.startswith("loc_") and s.endswith(":"):
                        pending_thumb = None
        except OSError:
            continue
    if region == TWL_REGION:
        starts.setdefault(0x02707CB4, None)
        starts.setdefault(0x02732D54, None)
    _FUNC_STARTS[region] = starts
    return starts


def target_extent(addr, region):
    """(size, thumb) of the original function, or (None, None) if unknown."""
    starts = scan_listing(region)
    if addr not in starts or starts[addr] is None:
        return None, None
    thumb = starts[addr]
    later = sorted(a for a in starts if a > addr)
    size = (later[0] - addr) if later else None
    return size, thumb


_LABEL_ORDER = {}


def next_listing_label(addr, region):
    """The first listing label strictly after addr, or None.

    Unlike target_extent() this answers for an address that is not itself a
    listing label (an SDK entry whose first word disasm.py wrote as data and
    whose label it put on the second instruction).
    """
    import bisect
    order = _LABEL_ORDER.get(region)
    if order is None:
        order = _LABEL_ORDER[region] = sorted(scan_listing(region))
    pos = bisect.bisect_right(order, addr)
    return order[pos] if pos < len(order) else None


# ---------------------------------------------------------------------------
# symbol addresses
# ---------------------------------------------------------------------------
#
# Resolving a relocation means writing the value the linker would have
# written, which needs the target symbol's address.  Everything below exists
# to answer one question honestly: do we know that address from something
# other than the very bytes we are about to compare?
#
# THE HONESTY RULE
#
# A relocation site may only be resolved when its target address is attested
# by evidence that lies OUTSIDE the byte range under comparison.  Reading the
# pool word that the comparison is going to check, and then "verifying" that
# the pool word has the value we just read out of it, proves nothing: the
# check would pass for any address whatsoever.  That is the circularity this
# guards against, and it is why every witness recorded below carries the
# address of the instruction or pool word it came from, and why
# ``attest()`` rejects a witness that falls inside the compared range.
#
# These classes of evidence are accepted, and the class is reported per site so
# a reader can weigh them separately:
#
#   label    disasm.py put a func_XXXXXXXX label at that address, i.e. it
#            traced real code there, AND some branch elsewhere in the image
#            calls that label.  This is the strong class: the address exists
#            in the listings independently of any literal.  "Elsewhere in the
#            image" means the whole image in both directions: a branch from
#            an overlay into arm9_main is the same kind of evidence as one
#            from arm9_main, and a callee that lives in an overlay is still a
#            function.  See xregion_calls(), image_call_sites() and
#            attest_overlay_label().
#
#   veneer   the address holds an ARM linker veneer: twelve (or eight) bytes
#            at a fixed encoding that load a constant into ip or pc and branch
#            to it, with the constant naming a known function.  A complete
#            self-contained entry point nothing can fall into, read entirely
#            from outside the compared range.  See attest_veneer().
#
#   literal  the exact word appears in at least one literal pool at a
#            different address.  bss and data addresses can only ever be
#            attested this way, because nothing disassembles bss.  It is the
#            weaker class, and the requirement that the witness be a pool
#            word (a site some instruction actually loads from) rather than
#            any stray matching word is what keeps it meaningful.
#
#   string   the address is the start of a NUL-terminated printable run whose
#            position is fixed by the terminator of the run before it.  For
#            __FILE__ arguments, whose address appears in exactly one literal
#            pool in the whole image: the one under test.  See attest_string()
#            for the seven conditions that keep it narrow.
#
#   matched  an EXACT manifest entry covers the address: our own compiled
#            proof, verified byte for byte against the original over a range
#            that is not the one under test, says what lives there.  The one
#            class whose witness is not a reading of the image.  See "the
#            `matched` class" below for why one-way dependence on an already
#            verified entry is sound and why self-reference is refused.
#
#   local    the symbol is defined inside the object we just compiled, so its
#            address follows from where we placed the translation unit.  No
#            image evidence is involved at all.
#
#   sole-ref the layout itself recognises what the address lands on, without a
#            second referrer.  Four sub-kinds, tried last of all, after every
#            other class has failed: `sole-ref/data` (an object START in a
#            data section, alignment satisfied, never an interior address);
#            `sole-ref/code` (exactly a traced function start, respecting
#            .thumb_func, or a recognised veneer; an overlay label in exactly
#            one overlay of the hinted pool; or, for a `twl`-hinted site, a
#            func_ label in asm/twl/twl.s, a listing disassembled from the
#            byte-verified decrypted TWL region; or, for an `ov230d`-hinted
#            site, a checked decrypted range start of overlay 230 that
#            asm/ov230d/ov230d.s labels, see "decrypted ov230");
#            `sole-ref/string` (the
#            start of a NUL-terminated printable run, even when the preceding
#            object is a table rather than a string); `sole-ref/self` (the
#            target is in a data section and the ROM word at the site already
#            names it -- relocation agreement is the proof).  See
#            attest_sole_ref().
#
#   overlay_id  an ABS32 data site whose declared value is an overlay index
#            (FS_OVERLAY_ID), which no address-based class can reach.  All
#            three must hold: the value is an overlay id listed in
#            layout/layout.json; a pc-relative load in the function under
#            test addresses exactly that site (decoded from the code, so
#            unlabelled continuation words of a pool run count); and the
#            loaded value reaches the id register of a call to an
#            OVERLAY_ID_CONSUMERS entry, a call site that resolved on its
#            own evidence.  Tried after everything else, once the
#            function's other sites are known.  See attest_overlay_id().
#
#   linker   an ABS32 site the function's own vendor object (located with
#            zero mismatches) relocates against an SDK_* symbol no member of
#            its archive defines, with the value derived from layout.json or
#            held at the same symbol's slot in another located row of that
#            archive.  See "vendor-object rules" and attest_linker().
#
#   template an ABS32 site the vendor object relocates against its local
#            `@N` initializer; the declared address holds the member's
#            template bytes, and no other aligned address of the ARM9 static
#            module (or, for an overlay row, of that overlay) does, or every
#            other such address is another template of the archive relocated
#            at a located row's slot outside the range.  See
#            attest_template().  (A `.bss` section symbol may also be named,
#            attest_section_rel(); that adds no class.)
#
# A site with no accepted witness stays wildcarded and the entry stays MATCH,
# with the reason printed.  Nothing is ever back-filled from the original.

_LABEL_DEF_RE = re.compile(r"^func_([0-9A-Fa-f]{8}):")
_POOL_DEF_RE = re.compile(r"^pool_([0-9A-Fa-f]{8}):")
_CALL_RE = re.compile(
    r"^\s*b[a-z]*\s+func_([0-9A-Fa-f]{8})\s+/\*\s*([0-9A-Fa-f]{8})")
_WORD_RE = re.compile(
    r"^\s*\.word\s+0x([0-9A-Fa-f]{8})\s+/\*\s*([0-9A-Fa-f]{8})")

# A branch whose target is in another region.  disasm.py cannot name such a
# target with a label, so it emits the raw encoding and decodes the target in
# the address comment:
#
#   .inst.w 0xF6B5FB9C   /* 0215ED2C  B5 F6 9C FB  bl 0x02014468  (outside this region) */
#
# The left group is the call site, the right one the target.  This is a real
# branch instruction in the image, so it is `label`-class evidence exactly the
# way an in-region `bl func_XXXXXXXX` is; the only difference is which file it
# is written in.
_XCALL_RE = re.compile(
    r"/\*\s+([0-9A-Fa-f]{8})\s.*?\b(?:blx|bl|b)\s+0x([0-9A-Fa-f]{8})\s+"
    r"\(outside this region\)")


class Evidence:
    """What the generated listings say about addresses, with provenance."""

    __slots__ = ("labels", "calls", "pool_words")

    def __init__(self):
        self.labels = {}          # addr -> thumb
        self.calls = defaultdict(list)      # addr -> [site addr]
        self.pool_words = defaultdict(list)  # value -> [pool site addr]


_EVIDENCE = {}


def evidence_files():
    """Listings scanned for symbol evidence: the whole ARM9 image."""
    return (unit_files("src", "units_arm9.json") +
            unit_files("src_itcm", "units_itcm.json"))


def evidence():
    """Scan the ARM9 listings once for labels, call sites and pool words."""
    if "e" in _EVIDENCE:
        return _EVIDENCE["e"]
    ev = Evidence()
    files = evidence_files()
    if not files:
        print("warning: no listings under asm/arm9/; every relocation will "
              "stay wildcarded.\n         run: python tools/disasm.py arm9 "
              "--split", file=sys.stderr)
    for path in files:
        pools = set()
        try:
            fh = open(path, "r", errors="replace")
        except OSError:
            continue
        with fh:
            pending_thumb = None
            mode_thumb = False
            for line in fh:
                s = line.strip()
                if s == ".thumb_func":
                    pending_thumb = True
                    continue
                if s in (".thumb", ".code 16"):
                    mode_thumb = True
                    continue
                if s in (".arm", ".code 32"):
                    mode_thumb = False
                    continue
                m = _LABEL_DEF_RE.match(s)
                if m:
                    ev.labels[int(m.group(1), 16)] = (
                        mode_thumb if pending_thumb is None else True)
                    pending_thumb = None
                    continue
                m = _POOL_DEF_RE.match(s)
                if m:
                    pools.add(int(m.group(1), 16))
                    continue
                m = _CALL_RE.match(line)
                if m:
                    ev.calls[int(m.group(1), 16)].append(int(m.group(2), 16))
                    continue
                m = _WORD_RE.match(line)
                if m:
                    site = int(m.group(2), 16)
                    if site in pools:
                        ev.pool_words[int(m.group(1), 16)].append(site)
    _EVIDENCE["e"] = ev
    return ev


# ---------------------------------------------------------------------------
# cross-region call evidence
# ---------------------------------------------------------------------------
#
# evidence() reads the ARM9 static module only, because that is where every
# matched entry lives and scanning it is cheap.  But "a branch somewhere else
# in the image calls that label" is not a claim about one region: a leaf in
# arm9_main whose only callers sit in overlays is still a function, and the
# instruction that proves it is still an instruction.  The 72 MB of overlay
# listings are therefore scanned lazily, and only when the ARM9 evidence has
# already failed to attest an address, so the common path never pays for it.
#
# Only branch instructions feed this index.  Pool words in overlays are
# deliberately NOT admitted: the `literal` class is the weak one, its witness
# has to be a word disasm.py classified as a literal pool, and widening it to
# 237 regions would weaken it without closing anything.
#
# Re-examined 2026-09-27 for the six unresolved data sites of ov010
# func_02155478 (0x021D3FE8, 0x021BB6A4, 0x021F03C4, 0x021E75D8, 0x02208C40,
# 0x021B74AC), and still refused.  An overlay pool word is only a witness for
# the same object when its region sees the same overlay at the address: the
# address lies in one overlay window only, or the pool word is in the site's
# own overlay.  All six addresses lie in 2 to 17 overlapping windows.  The
# ov010 words naming them (0x0216C970, 0x021713C0, ...) sit in code
# disasm.py did not trace, so no decoded load makes them pool words; the two
# labelled pool words (ov021 0x021CB620 -> 0x021BB6A4, ov174 0x021B6C28 ->
# 0x021B74AC) are in overlays whose own window covers the address, so they
# name their own objects, not ov100's or ov101's.  A rule with those guards
# closes none of the six, and one without them accepts wrong answers.

_XCALLS = {}


def xregion_listing_files():
    out = []
    d = os.path.join(ROOT, "asm", "overlays")
    if os.path.isdir(d):
        out += [os.path.join(d, f) for f in sorted(os.listdir(d))
                if f.endswith(".s")]
    d = os.path.join(ROOT, "asm", "arm9")
    if os.path.isdir(d):
        out += [os.path.join(d, f) for f in sorted(os.listdir(d))
                if f.endswith(".s")]
    return out


def xregion_calls():
    """{target addr: [call site addr]} for branches that leave their region."""
    if "x" in _XCALLS:
        return _XCALLS["x"]
    out = defaultdict(list)
    for path in xregion_listing_files():
        try:
            fh = open(path, "r", errors="replace")
        except OSError:
            continue
        with fh:
            for line in fh:
                # Cheap reject first; the marker is in every line that matters
                # and in almost none that does not.
                if "outside this region" not in line:
                    continue
                m = _XCALL_RE.search(line)
                if m:
                    out[int(m.group(2), 16)].append(int(m.group(1), 16))
    _XCALLS["x"] = out
    return out


# ---------------------------------------------------------------------------
# overlay-resident callees
# ---------------------------------------------------------------------------
#
# xregion_calls() indexes the branches that LEAVE a region.  The other half of
# the picture is the region they arrive in: an ARM9 function that calls an
# address inside an overlay (0x0200A3D0 calls 0x021DFDB8) had no way to attest
# that target, because the `label` class only ever looked at the ARM9
# listings and an overlay address never has a label there.
#
# The address space of the overlays is shared: 237 overlays are loaded into a
# handful of the same windows, so one address is inside several of them and
# they disagree about what is there.  That is why the rule below demands a
# label rather than settling for "two branches point at it": the label says
# some overlay's listing actually traced code at that address, and the branch
# says something in the image calls it.  Both halves have to hold, and the
# ISA the label carries has to be the ISA the source declares.
#
# The scans are lazy and per region: only the overlays that can hold the one
# address being asked about are ever read.

_REGIONS_AT = {}


def regions_containing(addr):
    """Names of every region whose address window holds `addr`.

    More than one overlay can answer, because overlays share load windows.
    """
    if addr in _REGIONS_AT:
        return _REGIONS_AT[addr]
    out = [r.name for r in load_all_regions()
           if r.base <= addr < r.base + len(r.data)]
    _REGIONS_AT[addr] = out
    return out


_REGION_CALLS = {}


def region_calls(name):
    """{target: [site]} for branches inside one region's own listing."""
    if name in _REGION_CALLS:
        return _REGION_CALLS[name]
    out = defaultdict(list)
    for path in listing_files(name):
        try:
            fh = open(path, "r", errors="replace")
        except OSError:
            continue
        with fh:
            for line in fh:
                m = _CALL_RE.match(line)
                if m:
                    out[int(m.group(1), 16)].append(int(m.group(2), 16))
    _REGION_CALLS[name] = out
    return out


def overlay_label(addr, region=None):
    """(region, thumb) if an overlay's own listing labels `addr`, else None.

    `region` is the region the site belongs to, and it wins when it holds the
    address.  Overlays share load windows, so the same address is labelled in
    several of them with different ISAs; without a preference the first region
    in load order answers, and a call that is correct in ov114 is refused as an
    ISA conflict because ov016 labels that address as ARM.  Measured cost of the
    old behaviour: about 113 callee addresses in ov114 alone, plus whole wrapper
    families in ov208, ov099 and ov093.
    """
    names = regions_containing(addr)
    if region is not None and region in names:
        starts = scan_listing(region)
        if addr in starts:
            return region, starts[addr]
    for name in names:
        if not name.startswith("ov"):
            continue
        starts = scan_listing(name)
        if addr in starts:
            return name, starts[addr]
    return None


def image_call_sites(addr):
    """Every branch in the image that targets `addr`, from any region.

    Three indexes feed this: the ARM9 in-region branches evidence() already
    reads, the cross-region branches xregion_calls() reads from all 242
    listings, and -- new here -- the in-region branches of whichever overlays
    hold the address.
    """
    sites = set(evidence().calls.get(addr, ()))
    sites |= set(xregion_calls().get(addr, ()))
    for name in regions_containing(addr):
        if name.startswith("ov"):
            sites |= set(region_calls(name).get(addr, ()))
    return sorted(sites)


def overlay_candidates(addr):
    """Names, sorted, of every overlay whose load window holds `addr`.

    Overlays share a handful of RAM windows, so this is routinely more than
    one name; `attest_overlay_label()` is what decides whether that is
    resolvable.
    """
    return sorted(n for n in regions_containing(addr) if n.startswith("ov"))


def attest_overlay_label(addr, kind, lo, hi, region_hint=None,
                         site_region=None):
    """The `label` class for an address that lives in an overlay.

    Conditions, each a separate refusal:

      1. the address is inside at least one overlay region of
         layout/layout.json;
      2. among the overlay(s) to consider, EXACTLY ONE has a generated
         listing that carries a `func_` label at the address with the ISA
         the source declares, i.e. disasm.py traced real code of the right
         instruction set there in that overlay.  Overlays overlap in address
         space, so more than one candidate having a label -- even a
         same-ISA one -- is ambiguity, not evidence: nothing here says which
         overlay was actually loaded when the call happened, so a wrong pick
         would be a guess wearing the `label` class's evidentiary standing.
         `region_hint`, when given, narrows the candidates to that one
         overlay before this check runs, which is how a source file resolves
         the ambiguity instead of this function guessing;
      3. at least one branch anywhere in the image targets the address from
         outside the compared range.

    `region_hint` comes from the pending/matched source's own `symbols:`
    line (a fourth token naming the overlay, e.g. `ov021`); see
    `declared_symbols()`.  A hint that names a region the address is not
    even inside is refused outright, the same as no evidence at all.

    The verdict is reported as `label`, not as a class of its own, because it
    is the same evidence with a wider index: a traced entry point plus a real
    branch instruction that calls it.
    """
    if kind not in ("thumb", "arm"):
        return None
    candidates = overlay_candidates(addr)
    if not candidates:
        return None
    # _overlay_pool() (w6 tools lane, 2026-09-29): a site whose own overlay's
    # window holds the address sees only that overlay there, so another
    # overlay's label at the same address is a different function and says
    # nothing; otherwise the hint, otherwise every candidate.
    pool, _fixed = _overlay_pool(addr, region_hint, site_region, candidates)
    labeled = [name for name in pool
               if scan_listing(name).get(addr) == (kind == "thumb")
               and not on_ciphertext(name, addr)]
    if len(labeled) != 1:
        return None
    # The branch witness: ARM9 in-region branches, branches that leave their
    # own region, and the labelled overlay's own in-region branches.  Not
    # image_call_sites(), which also admits the in-region branches of every
    # OTHER overlay mapped over the address; those target that overlay's own
    # code there, not this one's.
    sites = set(evidence().calls.get(addr, ()))
    sites |= set(xregion_calls().get(addr, ()))
    sites |= set(region_calls(labeled[0]).get(addr, ()))
    sites = [s for s in sorted(sites) if not lo <= s < hi]
    if not sites:
        return None
    return "label", len(sites), sites[0]


# ---------------------------------------------------------------------------
# TWL-resident callees (region `twl`, 2026-09-24)
# ---------------------------------------------------------------------------
#
# The DSi-mode autoload block of arm9i.bin (0x02700000..0x02732DA0, region
# `twl` of layout/layout.json) is code the ARM9 image calls on TWL hardware.
# Its listing, asm/twl/twl.s, exists only after delink.py decrypted arm9i
# with a user-supplied DSi key (tools/modcrypt.py) and disasm.py twl ran;
# without it nothing here attests anything.
#
# A `symbols:` line names such a callee with a fourth token `twl`
# (`func_027300F0  0x027300F0  arm  twl`), mirroring the ovNNN hint.  The
# token is required: an address in the TWL window is never looked up on the
# strength of the address alone, so a source that means an ARM9 or overlay
# address cannot be resolved against the TWL listing by accident.  The rule
# is the overlay `label` rule with a single candidate:
#
#   1. the token is `twl` and the address lies inside the declared window;
#   2. asm/twl/twl.s carries a `func_` label there with the declared ISA
#      (disasm.py traced real code of that instruction set there);
#   3. at least one branch in the image targets the address from outside the
#      compared range (the cross-region index, or the twl listing's own
#      branches).
#
#   3a. INTRA-TWL MUTUAL WITNESS (2026-09-26): condition 3 is also satisfied
#       when the only callers of `addr` live inside the range under test, but
#       every such caller belongs to a TWL function that is already EXACT.
#       Rationale: an EXACT entry's address is established independently (byte-
#       for-byte proof against the original over a non-overlapping range), so
#       a call from inside it to `addr` is real evidence that `addr` is a
#       function entry at that address.  The honesty rule bars reading the
#       compared range's own bytes as evidence; it does not bar using the
#       independently proven address of a caller that happens to live there.
#       This is the `matched`-class argument applied to intra-block TWL calls:
#       the caller's address is known from matched_addresses(), not from the
#       bytes we are about to check.  A caller that is not yet EXACT (MATCH or
#       absent from the manifest) is refused, because its own address is still
#       uncertain.  twl_containing_func() locates the enclosing function for
#       any in-range call site address.
#
# The region is never part of the ARM9 denominator: tools/worklist.py and
# the coverage figures do not read it.

TWL_REGION = "twl"
_TWL = {}


def twl_window():
    """(lo, hi) of region `twl` from layout/layout.json, or None."""
    if "w" not in _TWL:
        w = None
        try:
            with open(os.path.join(ROOT, "layout", "layout.json")) as fh:
                tw = json.load(fh).get("twl")
            if tw:
                w = (tw["ram_start"], tw["ram_end"])
        except (OSError, ValueError, KeyError):
            w = None
        _TWL["w"] = w
    return _TWL["w"]


TWL_LISTING = os.path.join(ROOT, "asm", "twl", "twl.s")


def twl_listing_files():
    p = TWL_LISTING
    return [p] if os.path.exists(p) else []


def twl_label(addr):
    """True/False (thumb) if the twl listing labels `addr`, else None."""
    w = twl_window()
    if w is None or not w[0] <= addr < w[1]:
        return None
    return scan_listing(TWL_REGION).get(addr)


def twl_containing_func(site):
    """Start address of the TWL function that contains `site`, or None.

    Uses the sorted func_ labels from the TWL listing.  Returns the largest
    label address that is <= `site` and lies in the TWL window.  Called only
    from attest_twl_label() to implement the intra-TWL mutual-witness rule
    (rule 3a): if the function containing the call site is already EXACT, the
    site is accepted as witness evidence even when it falls inside lo..hi.
    """
    w = twl_window()
    if w is None:
        return None
    starts = scan_listing(TWL_REGION)
    if not starts:
        return None
    keys = sorted(starts)
    # bisect_right gives the insertion point after all keys <= site;
    # subtract 1 to get the last key <= site.
    idx = bisect.bisect_right(keys, site) - 1
    if idx < 0:
        return None
    func_start = keys[idx]
    if not w[0] <= func_start < w[1]:
        return None
    return func_start


def attest_twl_label(addr, kind, lo, hi, region_hint=None):
    """The `label` class for a TWL-resident callee; see the rule above."""
    if region_hint != TWL_REGION or kind not in ("thumb", "arm"):
        return None
    th = twl_label(addr)
    if th is None or th != (kind == "thumb"):
        return None
    sites = set(xregion_calls().get(addr, ()))
    sites |= set(region_calls(TWL_REGION).get(addr, ()))
    outside = sorted(s for s in sites if not lo <= s < hi)
    if outside:
        return "label", len(outside), outside[0]
    # Rule 3a: no external caller exists, but an intra-range call site from
    # an already-EXACT TWL function is equally trustworthy evidence.  The
    # EXACT entry's address was established over a non-overlapping range;
    # its call into addr is a real branch instruction, not a byte we are
    # about to verify.  Only EXACT callers qualify; a MATCH caller's own
    # address is still uncertain and cannot vouch for addr.
    exact_addrs = matched_addresses()
    mutual = sorted(
        s for s in sites
        if lo <= s < hi
        and twl_containing_func(s) in exact_addrs
    )
    if mutual:
        return "label", len(mutual), mutual[0]
    return None


def attest_sole_ref_twl_code(addr, kind, region_hint=None):
    """`sole-ref/code` for a TWL label.  (class, n, site, "code")/None.

    The overlay rule (attest_sole_ref_overlay_code()) with the twl listing
    as its only candidate: the site's `symbols:` line carries the `twl`
    token, the address lies inside the twl window, and asm/twl/twl.s has a
    `func_` label exactly there with the declared ISA.  That listing is
    disassembled from the decrypted TWL region, which delink.py writes only
    after verifying it: the key matches its recorded SHA-1, the decrypted
    BLZ stream decodes with every byte consumed, and the clear tail agrees
    byte for byte with the undecrypted file.  No outside
    branch is required, which is what separates it from attest_twl_label():
    it is for the callee whose only caller image-wide is the range under
    test (func_0206DC00's two DSi-only callees).  Without the listing (no
    key) twl_label() finds nothing and the rule refuses.
    """
    if region_hint != TWL_REGION or kind not in ("thumb", "arm"):
        return None
    th = twl_label(addr)
    if th is None or th != (kind == "thumb"):
        return None
    return "sole-ref", 1, addr, "code"


# ---------------------------------------------------------------------------
# decrypted ov230 (region `ov230d`, 2026-09-24)
# ---------------------------------------------------------------------------
#
# Overlay 230 decrypts most of its own code when it is loaded: its static
# initialisers run a decryptor over 28 ranges (tools/ovcrypt.py has the
# scheme and the evidence).  The ROM bytes there, and so asm/overlays/ov230.s,
# are ciphertext; the code the game runs exists only in the decrypted view
# extract/ov230d.bin, listed by `disasm.py ov230d` as asm/ov230d/ov230d.s.
# ica_anime's func_02011D9C loads ov230 and BLXes three of its thunk slots.
#
# The design is region `twl`'s (a separately listed, verified derived view,
# reached only through an explicit token), with one more condition:
#
#   1. the `symbols:` line carries the token `ov230d`
#      (`func_021882A0  0x021882A0  arm  ov230d`).  The plain `ov230` token
#      keeps meaning ov230's ROM listing, so no existing hint changes meaning
#      and an address is never looked up in the decrypted view on the
#      strength of the address alone;
#   2. the address is the START of a range ovcrypt.py decrypted and checked
#      in this run (entry_points(): decryptor hash, table read from the
#      initialiser's own immediates, every range a clean ARM function ending
#      in a return, no range running into the next).  An interior address,
#      a still-encrypted second-layer body or plain code outside the ranges
#      is refused, even where the listing has a label;
#   3. extract/ov230d.bin is byte-identical to that fresh decryption (so the
#      listing was not built from a stale or hand-made view);
#   4. asm/ov230d/ov230d.s carries a `func_` label there with the declared
#      ISA (disasm.py traced it, and refuses the listing unless every range
#      traced as one function of code).
#
# With an outside branch to the address as well that is `label`
# (attest_ov230d_label()); without one it is `sole-ref/code`
# (attest_sole_ref_ov230d_code()), the class the twl callees of
# func_0206DC00 use: the label sits on real decrypted code the game
# executes, not on ciphertext.
#
# The converse guard, on_ciphertext(): a func_ label of ov230's ROM listing
# inside a decrypted range is a label on ciphertext (a function_starts.txt
# seed would make one), and the overlay rules above never accept it.

OV230D_REGION = "ov230d"
OV230D_LISTING = os.path.join(ROOT, "asm", "ov230d", "ov230d.s")
_OV230D = {}


def ov230d_listing_files():
    p = OV230D_LISTING
    return [p] if os.path.exists(p) else []


def ov230d_view():
    """ovcrypt's checked View of ov230, or None (refuse everything)."""
    if "v" not in _OV230D:
        v = None
        try:
            import ovcrypt
            v = ovcrypt.load(ROOT)
            with open(os.path.join(ROOT, "extract", ovcrypt.VIEW_FILE),
                      "rb") as fh:
                if fh.read() != v.data:
                    v = None
        except Exception:       # CryptError, a missing file: no evidence
            v = None
        _OV230D["v"] = v
    return _OV230D["v"]


def on_ciphertext(region, addr):
    """True when `region`'s ROM bytes at `addr` are ov230 ciphertext."""
    if region != "ov230":
        return False
    v = ov230d_view()
    return v is not None and v.range_at(addr) is not None


def ov230d_label(addr):
    """True/False (thumb) if the decrypted listing labels a range start."""
    v = ov230d_view()
    if v is None or addr not in v.entry_points():
        return None
    return scan_listing(OV230D_REGION).get(addr)


def attest_ov230d_label(addr, kind, lo, hi, region_hint=None):
    """The `label` class for a decrypted ov230 entry; see the rule above."""
    if region_hint != OV230D_REGION or kind not in ("thumb", "arm"):
        return None
    th = ov230d_label(addr)
    if th is None or th != (kind == "thumb"):
        return None
    sites = set(xregion_calls().get(addr, ()))
    sites |= set(region_calls(OV230D_REGION).get(addr, ()))
    sites = sorted(s for s in sites if not lo <= s < hi)
    if not sites:
        return None
    return "label", len(sites), sites[0]


def attest_sole_ref_ov230d_code(addr, kind, region_hint=None):
    """`sole-ref/code` for a decrypted ov230 entry.  (class, n, site, "code").

    Conditions 1-4 of the rule above and no outside branch: for the thunk
    slot whose only caller image-wide is the range under test (ica_anime's
    three probes).  The evidence is the decrypted code itself: a range the
    game's own initialiser decrypts and flushes, checked to be a whole ARM
    function, and traced there by disasm.py."""
    if region_hint != OV230D_REGION or kind not in ("thumb", "arm"):
        return None
    th = ov230d_label(addr)
    if th is None or th != (kind == "thumb"):
        return None
    return "sole-ref", 1, addr, "code"


# ---------------------------------------------------------------------------
# the `veneer` class
# ---------------------------------------------------------------------------
#
# A tail call from Thumb game code to an ARM library routine goes through a
# literal pool word and a `bx`, and sometimes the word the linker wrote is not
# the routine's address but the address of a twelve-byte ARM stub that jumps
# there.  0x02005794 and 0x020057A0 both load 0x02072788, and the bytes at
# 0x02072788 are
#
#   E59FC000   ldr ip, [pc, #0]
#   E12FFF1C   bx  ip
#   0208970C   .word SND_SetMasterVolume
#
# That is a linker veneer.  It has no symbol, disasm.py classifies it as data
# because it has no prologue and nothing branches to it, and the only words in
# the whole image that name it are the two pool words inside the range under
# test.  So `label` has no label, `literal` has no outside witness, and the
# range caps at MATCH with every concrete byte right.
#
# The evidence the other classes cannot see is the stub itself.  Twelve bytes
# at a fixed encoding that load a constant into ip and branch to it are a
# complete, self-contained entry point: nothing falls into them, they cannot
# be anything but a call target, and they lie outside the compared range.
# Reading them never touches the pool word whose value is about to be checked,
# so the honesty rule is satisfied, and a wrong claim still fails loudly as
# DIFF exactly as it does for `literal` and `string`.
#
# The rule is deliberately narrow, and only ARM forms are admitted:
#
#   1. the declared kind is `arm`.  A veneer body is ARM code; a claim that
#      the address is Thumb or data is refused;
#   2. the address is four-aligned and inside a region;
#   3. the words there are one of exactly two encodings, compared whole and
#      not masked:
#          E59FC000 E12FFF1C <ptr>     ldr ip, [pc, #0]; bx ip
#          E51FF004 <ptr>              ldr pc, [pc, #-4]
#   4. <ptr> names code: with the Thumb bit stripped it is inside a region,
#      aligned for the ISA its low bit declares, and it is either a `func_`
#      label in that region's listing or a symbol of layout/symbols_sdk.json,
#      with the same ISA.  A stray triple of data words does not have a third
#      word that names a known function;
#   5. the veneer does not point at itself;
#   6. every byte of the veneer, the pointer word included, lies outside the
#      compared range.
#
# The Thumb shape `ldr r3, [pc, #0]; bx r3; .word target` is deliberately NOT
# recognised, even though the linker also emits it (0x021DFDB8 in ov228 is
# one).  mwccarm emits exactly those eight bytes for a Thumb tail call with no
# argument set-up, and src/matched/unit_02005C3C.c is two committed instances
# of it, so the shape is not a linker signature and could not carry a claim
# about what the address is.  The ARM forms are: this front end compiles an
# ARM tail call to a direct `b` with a relocation, and `ip` is the
# procedure-call scratch register the ABI reserves for exactly this use.

VENEER_ARM_LDR_IP = 0xE59FC000      # ldr ip, [pc, #0]
VENEER_ARM_BX_IP = 0xE12FFF1C       # bx  ip
VENEER_ARM_LDR_PC = 0xE51FF004      # ldr pc, [pc, #-4]


def _region_at(addr):
    for r in load_all_regions():
        if r.base <= addr < r.base + len(r.data):
            return r
    return None


_SDK_BY_ADDR = {}


def sdk_addresses():
    """{address: thumb} for every recovered SDK symbol."""
    if "a" in _SDK_BY_ADDR:
        return _SDK_BY_ADDR["a"]
    out = {}
    p = os.path.join(ROOT, "layout", "symbols_sdk.json")
    if os.path.exists(p):
        with open(p) as fh:
            for e in json.load(fh)["symbols"]:
                out.setdefault(e["address"], bool(e["thumb"]))
    _SDK_BY_ADDR["a"] = out
    return out


def names_known_code(value, region=None):
    """True when `value` is an interworking pointer at a known function.

    `region` is the region the pointer word sits in.  An overlay-window
    target is read from the overlay(s) _overlay_pool() admits for a word in
    that region (its own overlay when its window holds the target), and
    exactly one of them may label it; the first labelled overlay in load
    order no longer answers (w6 tools lane, 2026-09-29)."""
    thumb = bool(value & 1)
    target = value & ~1
    if thumb:
        if target & 1:
            return False
    elif target & 3:
        return False
    if _region_at(target) is None:
        return False
    known = evidence().labels.get(target)
    if known is not None:
        return known == thumb
    if overlay_windows(target):
        pool, _fixed = _overlay_pool(target, None, region,
                                     overlay_candidates(target))
        isas = set()
        for n in pool:
            th = scan_listing(n).get(target)
            if th is None:
                th = sdk_region_isa(n, target)
            if th is not None:
                isas.add((n, th))
        if len(isas) != 1:
            return False
        return isas.pop()[1] == thumb
    known = sdk_addresses().get(target)
    if known is not None:
        return known == thumb
    return False


def veneer_at(addr, site_region=None, region_hint=None):
    """(size, pointer word address, target) if `addr` is an ARM veneer.

    The veneer's bytes are read from witness_region(): an overlay-window
    address is read from the overlay the site may see there, never from the
    first overlay in load order (w6 tools lane, 2026-09-29)."""
    if addr & 3:
        return None
    region = witness_region(addr, site_region, region_hint)
    if region is None:
        return None
    off = addr - region.base
    data = region.data

    def word(k):
        if off + k + 4 > len(data):
            return None
        return struct.unpack_from("<I", data, off + k)[0]

    w0 = word(0)
    if w0 == VENEER_ARM_LDR_IP and word(4) == VENEER_ARM_BX_IP:
        size, ptr_off = 12, 8
    elif w0 == VENEER_ARM_LDR_PC:
        size, ptr_off = 8, 4
    else:
        return None
    value = word(ptr_off)
    if value is None or not names_known_code(value, region.name):
        return None
    if (value & ~1) == addr:
        return None
    return size, addr + ptr_off, value


def attest_veneer(addr, kind, lo, hi, site_region=None, region_hint=None):
    """The `veneer` class.  Returns (class, witnesses, site) or None."""
    if kind != "arm":
        return None
    found = veneer_at(addr, site_region, region_hint)
    if found is None:
        return None
    size, ptr_at, _value = found
    if addr < hi and lo < addr + size:
        return None
    return "veneer", 1, ptr_at


# ---------------------------------------------------------------------------
# the `runtime` class
# ---------------------------------------------------------------------------
#
# mwccarm links a handful of hand-written ARM routines out of MSL/runtime.a
# for things C cannot express: the 64-bit shift/multiply/divide helpers, the
# soft-float arithmetic, the divide-by-zero check.  layout/runtime_arm9.txt
# is calibration wave 18B's identification of those addresses (see
# docs/notes/pkt_0209BDBC_runtime_library.c.txt).  They are never compiled
# from this project's C, so disasm.py never traces a func_ label at one --
# there is no prologue this front end emitted to recognise -- and a call to
# one is frequently the ONLY branch to it anywhere in the image (three of the
# four Thumb BL/BLX sites in the whole ROM that reach 0x0209C074 are inside
# src/pending/sub_02018E34.c itself), so the `label` class could never carry
# it even if a label existed: every witness would be inside the range under
# test.
#
# The table entry is the witness, and it satisfies the honesty rule the same
# way layout/symbols_sdk.json does for SDK symbols: it is read from a file
# that is never part of any compared byte range, established by calibration
# independently of any single call site, not by tracing branches in the
# image at all.  This is the identical evidentiary move symbol_address()
# already makes for `sdk_symbols()` (see its "tag" argument) -- a curated,
# externally verified address/name table trusted directly -- given a class
# of its own here because, unlike an SDK symbol, a runtime routine is never
# also independently `label`-attestable, so it needs a path that does not
# route through a func_ label at all.
#
# ARM only: every routine in runtime.a is ARM code (this front end never
# compiles its own runtime support Thumb), so a Thumb declaration against a
# table address is refused rather than silently trusted.

_RUNTIME_ADDRS = {}


def runtime_addresses():
    """{address: name} from layout/runtime_arm9.txt."""
    if "a" in _RUNTIME_ADDRS:
        return _RUNTIME_ADDRS["a"]
    out = {}
    p = os.path.join(ROOT, "layout", "runtime_arm9.txt")
    if os.path.exists(p):
        with open(p, "r", errors="replace") as fh:
            for line in fh:
                line = line.strip()
                if not line or line.startswith("#"):
                    continue
                parts = line.split()
                if len(parts) < 2:
                    continue
                try:
                    addr = int(parts[0], 16)
                except ValueError:
                    continue
                out[addr] = parts[1]
    _RUNTIME_ADDRS["a"] = out
    return out


def attest_runtime(addr, kind):
    """The `runtime` class.  Returns (class, witnesses, site) or None."""
    if kind != "arm":
        return None
    if addr not in runtime_addresses():
        return None
    return "runtime", 1, addr


_SDK_SYMS = {}


def sdk_symbols():
    """{name: (address, thumb)} from layout/symbols_sdk.json."""
    if "s" in _SDK_SYMS:
        return _SDK_SYMS["s"]
    out = {}
    p = os.path.join(ROOT, "layout", "symbols_sdk.json")
    if os.path.exists(p):
        with open(p) as fh:
            for e in json.load(fh)["symbols"]:
                out.setdefault(e["name"], (e["address"], bool(e["thumb"])))
    _SDK_SYMS["s"] = out
    return out


_SDK_ADDRS = {}


def sdk_addr_index():
    """{address: (name, thumb)} from layout/symbols_sdk.json, the inverse of
    sdk_symbols().  Kept separately because attest_sdk() looks a call or
    ABS32 *target* up by address, the same direction runtime_addresses()
    already looks runtime_arm9.txt up in.
    """
    if "a" in _SDK_ADDRS:
        return _SDK_ADDRS["a"]
    out = {}
    p = os.path.join(ROOT, "layout", "symbols_sdk.json")
    if os.path.exists(p):
        with open(p) as fh:
            for e in json.load(fh)["symbols"]:
                out.setdefault(e["address"], (e["name"], bool(e["thumb"])))
    _SDK_ADDRS["a"] = out
    return out


def attest_sdk(addr, kind, site_region=None, region_hint=None):
    """The `sdk` class.  Returns (class, witnesses, site) or None.

    layout/symbols_sdk.json is libmatch.py's signature-matcher recovery of
    the TwlSDK/runtime library symbol table: an address it names is, like a
    layout/runtime_arm9.txt entry, established independently of any single
    call site in this image, by comparing against the vendor library object
    files rather than by tracing branches here at all.  A call or ABS32
    target at a catalogued SDK address is therefore its own witness the same
    way a runtime routine is -- see "the `runtime` class" above, whose
    argument this class makes for the same reason and needs for the same
    reason (single-call leaf SDK wrappers can otherwise have no witness in
    the image outside the very range under test: DWC_GetCheckNintendoZone-
    WorkSize and PXI_InitFifo are both examples).  Unlike `runtime`, the SDK
    table carries a per-symbol ISA rather than being ARM-only, so the
    declared kind is checked against that symbol's own `thumb` flag instead
    of being fixed to one instruction set.
    """
    if kind not in ("thumb", "arm"):
        return None
    if overlay_windows(addr):
        # An overlay-window address (w6 tools lane, 2026-09-29): the table
        # has one row per (region, address), and sdk_addr_index() keeps
        # whichever came first, so an ov114 row could attest an ov016 call.
        # Only rows of the overlay(s) _overlay_pool() admits count (the
        # site's own overlay when its window holds the address, else the
        # hint, else every candidate), and exactly one of them may carry a
        # row there.
        pool, _fixed = _overlay_pool(addr, region_hint, site_region,
                                     overlay_candidates(addr))
        rows = [(n, sdk_region_isa(n, addr)) for n in pool]
        rows = [(n, th) for n, th in rows if th is not None]
        if len(rows) != 1:
            return None
        thumb = rows[0][1]
    else:
        found = sdk_addr_index().get(addr)
        if found is None:
            return None
        _name, thumb = found
    if bool(thumb) != (kind == "thumb"):
        return None
    return "sdk", 1, addr


_MATCHED_SYMS = {}


def matched_symbols():
    """{name: (address, thumb)} from the manifest shards."""
    if "m" in _MATCHED_SYMS:
        return _MATCHED_SYMS["m"]
    out = {}
    for e in load_manifest_entries():
        out.setdefault(e["name"], (int(e["address"], 16), e.get("isa") == "thumb"))
    _MATCHED_SYMS["m"] = out
    return out


# A C identifier that encodes its own address: func_02045A38, sub_0201F41C.
# This is the naming convention the generated listings already use, so a
# source that spells an extern this way needs no declaration block at all.
_ADDR_NAME_RE = re.compile(r"^(?:func|sub)_(0[0-9A-Fa-f]{7})$")


class Decl:
    """One entry of a source file's `symbols:` block."""

    __slots__ = ("name", "addr", "kind", "origin", "region", "align")

    def __init__(self, name, addr, kind, origin, region=None, align=None):
        self.name = name
        self.addr = addr
        self.kind = kind        # "thumb", "arm" or "data"
        self.origin = origin    # "header" or "name"
        self.region = region    # overlay hint, e.g. "ov021", or None
        self.align = align      # declared type's alignment, or None


def declared_symbols(fields):
    """Parse the `symbols:` block of a matched source file's header.

    A line is normally `name 0xADDR kind`.  A fourth token is either the
    declared type's alignment (`a1`, `a2`, `a4`, `a8`, `a16`, read by the
    `sole-ref` class) or the overlay
    the address lives in (`func_021D21C0  0x021D21C0  thumb  ov021`), for a
    callee that only exists in an overlay: overlays overlap in address
    space, so without this the `label` class has no way to know which of
    several overlapping candidates the author means, and refuses rather than
    guess.  See attest_overlay_label().  The token `twl` names region
    `twl` (the DSi-mode block of arm9i.bin) the same way; see
    attest_twl_label().  The token `ov230d` names overlay 230 as its own
    decryptor leaves it (asm/ov230d/ov230d.s); see "decrypted ov230".
    """
    out = {}
    for line in fields.get("symbols_lines", []):
        parts = line.split()
        if len(parts) not in (3, 4, 5):
            raise SystemExit(
                "bad symbols: line %r (want 'name 0xADDR kind [overlay] "
                "[aN]')" % line)
        name, addr, kind = parts[:3]
        if kind not in ("thumb", "arm", "data"):
            raise SystemExit("bad symbol kind %r for %s" % (kind, name))
        region = align = None
        for extra in parts[3:]:
            if re.match(r"^a[0-9]+$", extra):
                # the declared type's alignment, which the `sole-ref` class
                # checks the address against
                if align is not None:
                    raise SystemExit("bad symbols: line %r (two alignment "
                                     "tokens)" % line)
                align = int(extra[1:])
                if align not in (1, 2, 4, 8, 16):
                    raise SystemExit(
                        "bad alignment %r for %s: want a1/a2/a4/a8/a16"
                        % (extra, name))
            else:
                if region is not None:
                    raise SystemExit("bad symbols: line %r (two overlay "
                                     "tokens)" % line)
                region = extra
        if region == "arm9":
            # `arm9` claims the always-resident ARM9 image.  Checked, then
            # dropped: an ARM9 address needs no hint, so the line resolves
            # exactly as the same line without the token.  On an address
            # an overlay window holds it is a wrong claim, refused loudly.
            if overlay_windows(int(addr, 0)):
                raise SystemExit(
                    "bad symbols: line %r (`arm9` on an address an overlay "
                    "window holds)" % line)
            region = None
        out[name] = Decl(name, int(addr, 0), kind, "header", region, align)
    return out


def symbol_address(name, decls):
    """(address, kind, origin) for a relocation target, or None.

    Order: an explicit `symbols:` entry wins, then the address-bearing
    naming convention, then the recovered SDK symbol table, then the matched
    manifest.  None of these is evidence on its own; attest() decides.
    """
    d = decls.get(name)
    if d is not None:
        return d.addr, d.kind, "header"
    m = _ADDR_NAME_RE.match(name)
    if m:
        addr = int(m.group(1), 16)
        th = evidence().labels.get(addr)
        return addr, ("thumb" if th else "arm"), "name"
    for src, tag in ((sdk_symbols(), "symbols_sdk"),
                     (matched_symbols(), "manifest")):
        if name in src:
            addr, th = src[name]
            return addr, ("thumb" if th else "arm"), tag
    return None


# ---------------------------------------------------------------------------
# the declared ISA of a call target
# ---------------------------------------------------------------------------
#
# A `symbols:` line names an address AND an instruction set, and the
# instruction set decides which instruction is written: _encode_thumb_branch()
# emits BL for a Thumb target and BLX for an ARM one, which is exactly the
# rewrite the linker performs.  A wrong tag therefore does not fail to
# resolve, it resolves to the other instruction: a `thumb` tag on an ARM
# callee writes BL where the original holds BLX and the entry comes out DIFF
# for a reason that has nothing to do with the C.
#
# The declaration is a claim about the image, and the image usually knows the
# answer independently of it: a func_ label carries the ISA disasm.py traced
# at that address, an ARM linker veneer is ARM by construction, and every
# entry of layout/symbols_sdk.json records a per-symbol ISA.  So the tag is
# cross-checked against that evidence before a call is encoded.  A conflict is
# a bug in the source file, not a matching result, and is refused loudly; an
# address the image says nothing about keeps the declaration and says so in
# the per-site report, so a reader can see which claims carried no check.

_SDK_BY_REGION = {}


def sdk_region_isa(region, addr):
    """thumb flag of the layout/symbols_sdk.json row that `region` itself
    carries at `addr`, or None.  sdk_addresses() keys by address alone, so
    at an address several overlays share it answers with whichever row came
    first; this asks one region only."""
    if "r" not in _SDK_BY_REGION:
        out = {}
        p = os.path.join(ROOT, "layout", "symbols_sdk.json")
        if os.path.exists(p):
            with open(p) as fh:
                for e in json.load(fh)["symbols"]:
                    out.setdefault((e.get("region"), e["address"]),
                                   bool(e["thumb"]))
        _SDK_BY_REGION["r"] = out
    return _SDK_BY_REGION["r"].get((region, addr))


def _own_overlay_isa(name, addr):
    """("thumb"/"arm", where) from overlay `name`'s own label, then its own
    SDK row, or None."""
    th = scan_listing(name).get(addr)
    if th is not None:
        return ("thumb" if th else "arm"), \
            "the func_%08X label in %s" % (addr, name)
    th = sdk_region_isa(name, addr)
    if th is not None:
        return ("thumb" if th else "arm"), \
            "the %s row of layout/symbols_sdk.json" % name
    return None


def isa_evidence(addr, region=None, hint=None):
    """("thumb"/"arm", where) the image says `addr` is, or None.

    Three readings, strongest first: a func_ label in a generated listing,
    the ARM shape of a linker veneer, and the ISA flag of a recovered SDK
    symbol.  None of these is an attestation of the ADDRESS -- that is
    attest()'s job -- they only say what is at it if anything is.

    Overlays share load windows, so which overlay answers matters:

      - `hint` is the overlay the source's `symbols:` line names for the
        callee (the fourth token, e.g. `ov021`).  When it names an overlay
        whose window holds the address, that overlay alone answers, by its
        label and then its own SDK row, exactly as the hint already governs
        the `label` class in attest_overlay_label(); another overlay's label
        at the same address is a different function and says nothing.  With
        neither, the ISA is unevidenced and the declaration is noted.
      - otherwise `region`, the region the site belongs to, answers first
        when its window holds the address, again by label and then by its
        own SDK row (the ov175 call to its own ARM DWC row at 0x021DF490 was
        refused because an ov119 Thumb label answered ahead of it);
      - only when neither applies does the first labelled overlay in load
        order answer, then the non-overlay readings.
    """
    th = evidence().labels.get(addr)
    if th is not None:
        return ("thumb" if th else "arm"), \
            "the func_%08X label in asm/arm9" % addr
    cands = overlay_candidates(addr)
    if hint is not None and hint in cands:
        return _own_overlay_isa(hint, addr)
    if region is not None and region in cands:
        found = _own_overlay_isa(region, addr)
        if found is not None:
            return found
    found = overlay_label(addr, region)
    if found is not None:
        region, th = found
        return ("thumb" if th else "arm"), \
            "the func_%08X label in %s" % (addr, region)
    th = twl_label(addr)
    if th is not None:
        return ("thumb" if th else "arm"), \
            "the func_%08X label in asm/twl" % addr
    if veneer_at(addr, region, hint) is not None:
        return "arm", "the ARM linker veneer at %08X" % addr
    th = sdk_addresses().get(addr)
    if th is not None:
        return ("thumb" if th else "arm"), "layout/symbols_sdk.json"
    return None


def isa_conflict(addr, kind, region=None, hint=None):
    """(image isa, where) when the image contradicts `kind`, else None."""
    if kind not in ("thumb", "arm"):
        return None
    found = isa_evidence(addr, region, hint)
    if found is None or found[0] == kind:
        return None
    return found


# ---------------------------------------------------------------------------
# the `string` class
# ---------------------------------------------------------------------------
#
# A __FILE__ argument to a debug allocator is a pointer into the packed string
# area, and the address of a string there normally appears in exactly one
# literal pool: the pool of the one function that passes it.  That pool is the
# range under comparison, so the `literal` class discards its only witness and
# the entry caps at MATCH even though every concrete byte is right.
#
# There is honest evidence the other classes cannot see, and it is in the data
# rather than in any instruction.  Strings are emitted end to end, each one
# NUL-terminated and the next one aligned up, so the START of a string is
# fixed by the END of the string before it:
#
#   020A70AC  6D 79 73 74 61 74 75 73 2E 63 00 | 00 | 70 6C 61 79 ...
#             m  y  s  t  a  t  u  s  .  c  \0  pad  p  l  a  y
#                                          ^          ^
#                                    terminator     0x020A70B8 follows
#                                    at 020A70B6    by construction
#
# That derivation uses only bytes outside the compared range, so it satisfies
# the honesty rule, and it is not circular: it never reads the pool word whose
# value it is about to check.  What it establishes is that 0x020A70B8 is a
# string start, not that it is THE string the source meant, exactly as the
# `literal` class establishes that an object lives at an address without
# saying it is the right one.  A wrong claim still fails: the resolved word is
# compared against the original and comes out DIFF.
#
# The rule is deliberately narrow.  Every one of these must hold:
#
#   1. the declared kind is `data` (a string is not code);
#   2. the bytes at `addr` are >= MIN_STRING_CHARS printable ASCII followed
#      by a NUL, entirely inside one region;
#   3. immediately before `addr` there are k NUL bytes, 1 <= k <=
#      MAX_STRING_PAD: one terminator plus the padding after it;
#   4. `addr` is the ONLY address in that padding window at which a string
#      begins, so the previous terminator fixes one address and not a range
#      of candidates.  See "the padding window" below;
#   5. the bytes before those NULs are themselves >= MIN_STRING_CHARS
#      printable ASCII, so the NUL at addr-k is a string terminator and not
#      a zero word in a data blob;
#   6. no func_ label falls anywhere in the two strings, so this is not being
#      run over code that happens to decode as text;
#   7. the whole witness neighbourhood lies outside the compared range.
#
# The forward direction ("a neighbouring string's start") adds nothing and is
# not implemented: a string's own terminator already fixes its end, so only
# its start needs an outside witness.  The other route to that start, a
# reference from outside the compared range, is the existing `literal` class
# and is tried first.
#
# THE PADDING WINDOW
#
# The rule used to require k <= 4 and, when k > 1, that `addr` be the first
# four-aligned address after the terminator: one terminator plus at most three
# bytes of alignment.  That refused 0x020A706C, which is "box_savedata.c" and
# names the original source file of src/matched/unit_020079BC.c: the
# terminator of "save_control.c" is at 0x020A7062 and the next ten bytes,
# terminator included, are NUL, so k is 10 and the first four-aligned address
# after the terminator is 0x020A7064 rather than 0x020A706C.
#
# The extra padding is real and it is not alignment.  Measured over the whole
# ARM9 image, of the 404 string starts that have a well-formed string in front
# of them the k distribution is
#
#     k =  1   2   3   4   5   7  10
#        265  47  40  47   2   2   1
#
# and every k > 4 sits at a four-aligned address one or two whole words past
# the one alignment alone would have chosen: the linker left one or two dead
# words between two string sections.  10 is the largest run anywhere in the
# image, so the bound is MAX_STRING_PAD = 12, the next multiple of four above
# it: a terminator plus at most three bytes of alignment plus at most two dead
# words.  A run of NULs longer than any the string area actually contains is
# refused rather than walked across.
#
# Widening the window costs nothing in soundness as long as the address stays
# uniquely determined, which is what condition (4) now checks directly: every
# address strictly between the terminator and `addr` is examined, and the rule
# refuses unless `addr` is the only one of them at which a NUL-terminated
# printable run of at least MIN_STRING_CHARS characters begins.  The old
# four-alignment test was a proxy for that; this is the property itself, and
# it is what makes "the terminator before it fixes its start" a statement
# about one address.  Condition (5) still demands a real string immediately
# before the run, which is what keeps the rule out of the zero blobs that
# follow the string area.

MIN_STRING_CHARS = 4
# One terminator, up to three bytes of alignment, up to two dead words.  The
# bound comes from the measured distribution above; see "the padding window".
MAX_STRING_PAD = 12
MAX_STRING_BYTES = 256      # a longer run is a text blob, not a literal

# A table of code pointers has at least this many consecutive entries, and the
# scan of them stops at this many so a run into unrelated data cannot run away.
MIN_TABLE_ENTRIES = 2
MAX_TABLE_ENTRIES = 0x400


def _printable_run_forward(data, off, limit):
    """Length of the printable ASCII run at `off`, NUL-terminated, or None."""
    n = 0
    while off + n < limit and n <= MAX_STRING_BYTES:
        b = data[off + n]
        if b == 0:
            return n if n else None
        if b < 0x20 or b > 0x7E:
            return None
        n += 1
    return None


def _printable_run_backward(data, off):
    """Length of the printable ASCII run ending at `off` inclusive.

    A format string can embed \\t, \\n or \\r ahead of its own NUL
    terminator (e.g. "!![%x][%x]\\n" at 0x020A7E40, immediately before
    "gf_standard.c" at 0x020A7E4C): those bytes are part of the run's
    content, not the run's terminator, which stays NUL and is handled by
    the caller.  Only they are admitted below 0x20; any other control byte
    still ends the run.
    """
    n = 0
    while off - n >= 0 and n <= MAX_STRING_BYTES:
        b = data[off - n]
        if (b < 0x20 and b not in (0x09, 0x0A, 0x0D)) or b > 0x7E:
            break
        n += 1
    return n


def attest_string(addr, lo, hi, site_region=None, region_hint=None):
    """The `string` class.  Returns (class, witnesses, site) or None.

    See the commentary above for the seven conditions; each one of them is a
    separate `return None` here so that a reader can check them off.  The
    bytes are read from witness_region(): for a site in an overlay, that
    overlay's own image when its window holds the address, never another
    overlay mapped over the same window.
    """
    region = witness_region(addr, site_region, region_hint)
    if region is None:
        return None
    data = region.data
    base = region.base
    off = addr - base

    # (2) a NUL-terminated printable run starts here
    length = _printable_run_forward(data, off, len(data))
    if length is None or length < MIN_STRING_CHARS:
        return None

    # (3) the terminator of the string before, plus its alignment padding
    k = 0
    while k < MAX_STRING_PAD and off - k - 1 >= 0 and data[off - k - 1] == 0:
        k += 1
    if k < 1:
        return None

    # (4) no other address in the padding window starts a string, so the
    #     previous terminator fixes this address and not a range of them
    prev_nul = addr - k
    for cand in range(prev_nul + 1, addr):
        n = _printable_run_forward(data, cand - base, len(data))
        if n is not None and n >= MIN_STRING_CHARS:
            return None

    # (5) that NUL has to terminate a string, not sit in a zero blob
    if off - k - 1 < 0:
        return None
    prev_len = _printable_run_backward(data, off - k - 1)
    if prev_len < MIN_STRING_CHARS:
        return None
    prev_start = prev_nul - prev_len

    # (6) neither run may be code: the ARM9 labels, and for an overlay's
    #     bytes that overlay's own listing labels too
    for lbl in evidence().labels:
        if prev_start <= lbl <= addr + length:
            return None
    if region.name.startswith("ov"):
        for lbl in scan_listing(region.name):
            if prev_start <= lbl <= addr + length:
                return None

    # (7) none of the witness bytes may be inside the compared range
    if prev_start < hi and lo < addr + length + 1:
        return None

    return "string", 1, prev_nul


# ---------------------------------------------------------------------------
# the `data_table` class
# ---------------------------------------------------------------------------
#
# Some data objects are named by exactly one literal pool word: the pool of
# the single function that uses them.  That pool sits inside the compared
# range, so `literal` discards its only witness and the site caps at MATCH
# even though every concrete byte is right.  This is the shape the handoff
# names as blocking the gf_font dispatchers and the clact handler tables: a
# function-pointer table that the source declares as an extern and loads
# through one pool word.
#
# The object itself lives at a different address from the function, and its
# own bytes can say what it is: a run of pointers into loaded code, that is, a
# table of function pointers.  The pool word tells the resolver WHICH address
# to look at; the evidence is the target's shape, read entirely from outside
# the compared range, so the honesty rule is satisfied.
#
# This is deliberately weaker than `literal`.  It does not name a second
# reference, it reads a shape, so it cannot by itself say the declared address
# is THE object the source meant.  It does not need to: the resolved word is
# still compared against the original, and a wrong declaration resolves to a
# different word and comes out DIFF, exactly as for `literal` and `string`.
# What it must not do is resolve a plain data declaration, so every one of
# these has to hold, each a separate refusal below:
#
#   1. the declared kind is `data` (this class never applies to code);
#   2. the address is four-aligned and inside a loaded region;
#   3. the address is not a traced code entry point (no func_ label there);
#   4. some instruction actually loads the address, i.e. the word the source
#      declares appears in a literal pool (the reference is real, not a guess);
#   5. the compared range does not hold the object: at least its first eight
#      bytes lie outside lo..hi, so no witness is the range under test;
#   6. the words there are at least MIN_TABLE_ENTRIES consecutive pointers
#      into loaded regions, which is what a jump or dispatch table is.  The
#      run ends at the first word that is zero or not an in-region pointer.

def attest_data_table(addr, lo, hi, site_region=None, region_hint=None):
    """The `data_table` class.  Returns (class, witnesses, site) or None.

    The table's words are read from witness_region(), as for `string`."""
    if addr & 3:
        return None
    ev = evidence()
    if addr in ev.labels:
        return None
    if not (ev.pool_words.get(addr) or ev.pool_words.get(addr | 1)):
        return None
    regions = load_all_regions()
    region = witness_region(addr, site_region, region_hint)
    if region is None:
        return None
    if region.name.startswith("ov") and addr in scan_listing(region.name):
        return None
    if not (addr + 8 <= lo or hi <= addr):
        return None
    data = region.data
    off = addr - region.base
    n = 0
    while n < MAX_TABLE_ENTRIES and off + (n + 1) * 4 <= len(data):
        w = int.from_bytes(data[off + n * 4: off + n * 4 + 4], "little")
        if w == 0:
            break
        p = w & ~1
        inside = False
        for r in regions:
            if r.base <= p < r.base + len(r.data):
                inside = True
                break
        if not inside:
            break
        n += 1
    if n < MIN_TABLE_ENTRIES:
        return None
    return "data_table", n, addr


# ---------------------------------------------------------------------------
# the `sole-ref` class
# ---------------------------------------------------------------------------
#
# Approved as a new evidence class after the wave-20 handoff.  It exists for
# the shape `literal` and `data_table` both leave stranded: a static object
# that exactly one function in the image references, through one pool word,
# and whose contents are not pointers.  `sub_0209E904_Tbl` in
# `src/pending/func_020213F8.c` is the canonical instance.  The pool word is
# inside the compared range, so `literal` discards its only witness; the
# object is a run of u16 pairs, so `data_table` refuses it too; and nothing
# in the image branches to data, so `label` never applies.  Every concrete
# byte of such a file is right and it is stuck at MATCH.
#
# What the class rests on is NOT a second reference.  It is the LAYOUT: the
# delinked image's own structure says there is an object beginning at that
# address, and that statement is read entirely from files that are never part
# of any compared range (layout/layout.json, layout/symbols_sdk.json,
# layout/file_anchors.txt and the generated listings' block structure).  It is
# the weakest class in the set and is tried last, after every other class has
# failed, so an address any stronger class can carry never reports as
# `sole-ref`.
#
# It is still falsifiable in exactly the way `literal`, `string` and
# `data_table` are: the resolved word is written into the bytes and compared
# against the original, so a wrong declaration resolves to a wrong word and
# comes out DIFF.  What the class buys is permission to write the word at all.
#
# Three conditions, each a separate refusal in attest_sole_ref():
#
#   (a) THE ADDRESS IS IN DATA.  It lies inside a loaded region of
#       layout/layout.json, and inside that region it is a data address and
#       not a code one: the generated listings classify every byte of the
#       image, and the address must fall on a byte the listings emit as a
#       `.word`/`.byte`/`.short`/`.ascii` datum rather than as an
#       instruction, and must not lie inside any traced function's extent
#       (from the first byte of a func_ label to the start of the next
#       block).  A bss address, which no listing covers because bss is not
#       in the image, qualifies through the layout's own bss_start/bss_end
#       instead.  A code address is refused outright.
#
#   (b) THE ADDRESS IS AN OBJECT BOUNDARY.  Something the project already
#       carries has to name exactly that address as the START of an object.
#       Four sources, and only these four, because they are the only ones
#       this layout has (see data_object_starts() for what each contributes
#       in the ARM9 image):
#
#         * a data label the listings emit at that address.  disasm.py emits
#           `pool_XXXXXXXX` for a literal pool and `veneer_XXXXXXXX` for a
#           linker stub; it emits no `d_`/`g_`/`tbl_` labels at all, so those
#           spellings are accepted if they ever appear but contribute nothing
#           today;
#         * a data symbol of layout/symbols_sdk.json.  Today every recovered
#           SDK symbol in that file is a function, so this source likewise
#           contributes nothing yet; it is here so that a data symbol added
#           later is honoured without a code change;
#         * a file anchor: the `string_addr` column of layout/file_anchors.txt
#           is the start of a __FILE__ literal, which is an object boundary
#           the harvester established from outside any compared range;
#         * the start of a `.word` run the listings emit as its own block,
#           i.e. the first data address after a run of instructions.  This is
#           disasm.py's own block structure (`_block_starts`), the closest
#           thing a stripped image has to an object-file boundary.
#
#       An address that is merely INTERIOR to one of those objects is
#       refused.  That is the condition that keeps the class narrow: it does
#       not let a caller point at an arbitrary offset into rodata and call
#       the layout a witness.  0x0209E904 (the func_020213F8 blocker above)
#       is interior to the 0x0209D86C run and is refused for exactly this
#       reason.
#
#   (c) THE ALIGNMENT HOLDS.  The site's declared type has an alignment, and
#       the address has to satisfy it.  A `symbols:` line may state it as a
#       fourth token (`a1`, `a2`, `a4`, `a8`); without one, an ABS32 data
#       reference is assumed to want the four-byte alignment mwccarm gives an
#       ordinary extern, which is the conservative reading.  An address that
#       does not meet it cannot be the object the source declares.
#
# The above is now `sole-ref/data` specifically: one of three named
# sub-kinds under the `sole-ref` class, every one still tried only after
# every stronger class has failed.
#
# WIDENED 2026-09-21.  The owner decided to widen the class to the standard
# other matching-decompilation projects use: the address the original pool
# word names is accepted whenever it lands on something the layout
# recognises, without requiring a second referrer.  That standard already
# describes `sole-ref/data` above; the widening adds two more shapes the
# layout can equally well recognise on its own:
#
#   `sole-ref/code` (attest_sole_ref_code()): the address is exactly a
#   traced function start -- a func_ label, respecting the .thumb_func ISA
#   marker, or a recognised linker veneer.  This is the function-pointer and
#   single-caller-callee shape: the same evidence `label` and `veneer`
#   already trust, minus the requirement of an outside branch, which is
#   exactly the case those two classes cannot reach.  An address that is not
#   precisely a label start (an offset into a function, an unrecognised
#   shape) is refused.
#
#   `sole-ref/string` (attest_sole_ref_string()): the address begins a
#   NUL-terminated printable run in the listings, accepted even when the
#   `string` class's stronger condition -- a real string immediately before
#   it -- fails because the preceding object is a data table.  See
#   docs/idioms/a-string-after-a-data-table-has-no-witness.md for the case
#   this closes ("mail.c", "wifilist.c").
#
# A FOURTH SUB-KIND, 2026-09-21: `sole-ref/self`
# (attest_sole_ref_self()).  The three above all still ask the layout to
# recognise the target as an object start, a function start or a string.
# The community standard asks less: a relocation site is matched when the
# relocation names the same address the original word names, with no
# second-referrer requirement, and a file-local table used by exactly one
# function is the normal case.  `self` is that standard, under two guards:
#
#   (a) the target is in a data section (rodata, data or bss) and not
#       inside any code extent -- the same in_data_section() test
#       `sole-ref/data` condition (a) uses.  Code targets keep their
#       existing rules; a target inside a code extent never qualifies;
#   (b) the ROM word at the relocation site equals the word this
#       resolution is about to write there.  A byte-correct compile
#       implies it, but the class asserts it at the site rather than
#       leaning on the later comparison.
#
# Rationale: the ROM word names the address, so relocation agreement is
# itself the proof.  The site is still falsifiable exactly as the others
# are -- a wrong declaration names a different address, the words disagree,
# and the class refuses before the comparison ever runs.
#
# Each sub-kind is recorded per site in the shard evidence as
# "<subkind>:0xADDRESS" (sole_ref_sites()), so `grep sole-ref
# layout/matched` and `tools/worklist.py --summary` can break the class's
# coverage share down by sub-kind rather than reporting one number.
#
# The class never applies outside `data`/`thumb`/`arm`: see attest_sole_ref()
# for the dispatch by `kind`.

# Alignment tokens a `symbols:` line may carry, and the default for a data
# extern with none.
SOLE_REF_DEFAULT_ALIGN = 4

_DATA_DIRECTIVE_RE = re.compile(
    r"^\s*\.(word|byte|short|hword|2byte|4byte|ascii|asciz|string|space|zero)\b")
_LINE_ADDR_RE = re.compile(r"/\*\s*([0-9A-Fa-f]{8})[\s*]")
# The encoding bytes disasm.py prints after the address of an instruction
# line ("/* 0216FED6  F8 BD */"); their count is the instruction's length.
_LINE_BYTES_RE = re.compile(r"/\*\s*[0-9A-Fa-f]{8}((?:[ \t]+[0-9A-F]{2}\b)+)")
_DATA_LABEL_RE = re.compile(
    r"^(pool|veneer|d|g|tbl)_([0-9A-Fa-f]{8}):$")

_LAYOUT_DATA = {}


def _scan_data_structure():
    """Classify the ARM9 image's bytes and find its data object starts.

    One pass over the same listings evidence() reads.  Returns

        (code_addrs, data_addrs, object_starts, func_extents)

    where `object_starts` is the set of addresses at which the listings, the
    SDK symbol table or the file-anchor table say an object begins, and
    `func_extents` is [(lo, hi)] for every traced function.

    The listings are split into overlapping unit files, so the same address
    is described by more than one file; they agree, and the union is taken.
    """
    if "d" in _LAYOUT_DATA:
        return _LAYOUT_DATA["d"]
    code = set()
    data = set()
    starts = set()
    func_at = {}
    for path in evidence_files():
        prev_data = False
        try:
            fh = open(path, "r", errors="replace")
        except OSError:
            continue
        with fh:
            for line in fh:
                s_ = line.strip()
                m = _DATA_LABEL_RE.match(s_)
                if m:
                    starts.add(int(m.group(2), 16))
                    continue
                ma = _LINE_ADDR_RE.search(line)
                if ma is None:
                    continue
                addr = int(ma.group(1), 16)
                if _DATA_DIRECTIVE_RE.match(line):
                    data.add(addr)
                    if not prev_data:
                        # the first datum after code: disasm.py emitted a new
                        # block here, which is a run start.
                        starts.add(addr)
                    prev_data = True
                else:
                    code.add(addr)
                    prev_data = False
    # a func_ label's extent, so an address inside traced code is refused even
    # when some other unit file happens not to cover it.
    labels = sorted(evidence().labels)
    all_code = sorted(code)
    extents = []
    import bisect
    for a in labels:
        i = bisect.bisect_right(all_code, a)
        end = a
        # walk forward through contiguous code addresses
        while i < len(all_code) and all_code[i] - end <= 4:
            end = all_code[i]
            i += 1
        extents.append((a, end + 4))
    # SDK data symbols (none today: every entry of symbols_sdk.json is a
    # function) and file anchors.
    for e in _sdk_symbol_records():
        if e.get("kind") == "data" or e.get("data") is True:
            starts.add(int(e["address"]) if not isinstance(e["address"], str)
                       else int(e["address"], 0))
    starts |= file_anchor_starts()
    out = (code, data, starts, extents)
    _LAYOUT_DATA["d"] = out
    return out


def _sdk_symbol_records():
    """The raw records of layout/symbols_sdk.json."""
    path = os.path.join(ROOT, "layout", "symbols_sdk.json")
    if not os.path.exists(path):
        return []
    try:
        with open(path, "r", encoding="utf-8") as fh:
            return json.load(fh).get("symbols", [])
    except (OSError, ValueError):
        return []


_ANCHORS = {}


def file_anchor_starts():
    """String addresses from layout/file_anchors.txt.

    Column 4 of that table is the address of a __FILE__ literal, which is the
    start of an object: the harvester established it from pool sites, and the
    table is read from a file that is never part of a compared range.
    """
    if "a" in _ANCHORS:
        return _ANCHORS["a"]
    out = set()
    path = os.path.join(ROOT, "layout", "file_anchors.txt")
    try:
        with open(path, "r", errors="replace") as fh:
            for line in fh:
                if line.startswith("#"):
                    continue
                parts = line.split()
                if len(parts) >= 4:
                    try:
                        out.add(int(parts[3], 16))
                    except ValueError:
                        continue
    except OSError:
        pass
    _ANCHORS["a"] = out
    return out


def data_object_starts():
    """Every address at which this layout says a data object begins."""
    return _scan_data_structure()[2]


def in_data_section(addr):
    """True when `addr` is a data address of a loaded region, not a code one.

    Three ways to be data: the listings emit a datum there; the layout puts
    it in bss (which no listing covers, because bss is not in the image); or
    -- refused -- the listings emit an instruction there, or the address is
    inside a traced function's extent.
    """
    code, data, _starts, extents = _scan_data_structure()
    if addr in code:
        return False
    import bisect
    lows = [lo for lo, _hi in extents]
    i = bisect.bisect_right(lows, addr) - 1
    if i >= 0 and extents[i][0] <= addr < extents[i][1]:
        return False
    if addr in data:
        return True
    # the listings record the start of each datum; a halfword or byte inside a .word (or a
    # byte inside a .hword) is data too, and objects are only halfword or byte aligned when
    # their element type is
    if (addr & ~1) in data or (addr & ~3) in data:
        return True
    return addr in bss_addresses_probe(addr)


def _bss_ranges():
    """(lo, hi) for every bss range layout/layout.json declares."""
    if "bss" in _LAYOUT_DATA:
        return _LAYOUT_DATA["bss"]
    out = []
    try:
        with open(os.path.join(ROOT, "layout", "layout.json")) as fh:
            lay = json.load(fh)
    except (OSError, ValueError):
        _LAYOUT_DATA["bss"] = out
        return out
    a9 = lay.get("arm9") or {}
    for blk in [a9.get("static") or {}] + list(a9.get("autoloads") or []):
        lo = blk.get("bss_start")
        hi = blk.get("bss_end")
        if lo and hi and hi > lo:
            out.append((lo, hi))
    for ov in lay.get("overlays") or []:
        lo, hi = ov.get("bss_start"), ov.get("bss_end")
        if lo and hi and hi > lo:
            out.append((lo, hi))
    tw = lay.get("twl") or {}
    lo, hi = tw.get("bss_start"), tw.get("bss_end")
    if lo and hi and hi > lo:
        out.append((lo, hi))
    _LAYOUT_DATA["bss"] = out
    return out


def bss_addresses_probe(addr):
    """A one-element set holding `addr` when it is in bss, else empty.

    Spelled as a set so in_data_section() reads uniformly; bss is far too
    large to enumerate.
    """
    for lo, hi in _bss_ranges():
        if lo <= addr < hi:
            return {addr}
    return set()


# ---------------------------------------------------------------------------
# the data-object map
# ---------------------------------------------------------------------------
#
# data_object_starts() above recovers boundaries from the listings' own block
# structure, which is coarse: disasm.py emits the whole rodata tail
# 0x0209D86C-0x020A8FE4 as ONE block, so exactly one address in 47 kB is a
# start and every other reference into it is refused as "interior".
#
# layout/data_objects.txt is the finer map, built by tools/datamap.py from
# sources that all lie outside any compared range: literal-pool words in every
# ARM9 unit listing and every overlay listing, NUL-terminated string runs,
# `symbols:` data lines of src/matched files whose entries are EXACT, and a
# clearly-labelled periodic-structure heuristic.
#
# The evidence has to be OUTSIDE the range under test, exactly as for every
# other class.  A `pool` row carries its referring sites, so a start whose
# only referrer is inside lo..hi does not count: a lone reference never
# attests its own start.  A `string`, `data-decl` or `table-guess` row carries
# no site, because its witness is a file (the image's own NUL structure, a
# verified source, the map itself) and not an address inside the image.
#
# `table-guess` is a heuristic with no witness at all and is NEVER accepted
# here; it is written to the map for a reader, not for the matcher.

_DATA_MAP = {}

_MAP_SITE_RE = re.compile(r"pool word at 0x([0-9A-Fa-f]{8})")

# Kinds of layout/data_objects.txt row the class will accept.  `table-guess`
# is deliberately absent: a repeated stride is a guess, not a witness.
SOLE_REF_MAP_KINDS = ("pool", "string", "data-decl")


def data_object_map():
    """{addr: (kind, [referrer sites], evidence text)} from the map file.

    Loaded once and cached.  A missing file is not an error: the class then
    falls back to data_object_starts() alone, which is what it used before
    the map existed.
    """
    if "m" in _DATA_MAP:
        return _DATA_MAP["m"]
    out = {}
    path = os.path.join(ROOT, "layout", "data_objects.txt")
    try:
        fh = open(path, "r", errors="replace")
    except OSError:
        _DATA_MAP["m"] = out
        return out
    with fh:
        for line in fh:
            if line.startswith("#") or not line.strip():
                continue
            parts = line.split(None, 3)
            if len(parts) < 3 or not parts[1].startswith("0x"):
                continue
            if parts[0] != "arm9":
                continue        # overlay rows: overlay_declared_starts()
            try:
                addr = int(parts[1], 16)
            except ValueError:
                continue
            ev = parts[3].rstrip("\n") if len(parts) > 3 else ""
            sites = [int(m, 16) for m in _MAP_SITE_RE.findall(ev)]
            if (addr in out and out[addr][0] in SOLE_REF_MAP_KINDS
                    and parts[2] not in SOLE_REF_MAP_KINDS):
                # a hand `range` (or `table-guess`) row sharing its start
                # with an accepted row never displaces that row
                continue
            out[addr] = (parts[2], sites, ev)
    _DATA_MAP["m"] = out
    return out


def _map_attests(addr, lo, hi):
    """True when the map says an object starts at `addr` on outside evidence.

    `lo`/`hi` are the compared range.  A row whose every referring site lies
    inside it is refused: the range under test may not witness its own start.
    """
    row = data_object_map().get(addr)
    if row is None:
        return False
    kind, sites, _ev = row
    if kind not in SOLE_REF_MAP_KINDS:
        return False
    if kind == "pool":
        # at least one referrer outside the compared range
        return any(not (lo <= s < hi) for s in sites)
    # string / data-decl: the witness is a file, never an address in the image
    return True


# ---------------------------------------------------------------------------
# documented ARM9 I/O registers (for `sole-ref/data`)
# ---------------------------------------------------------------------------
#
# An I/O register is not an object any listing or map can witness: nothing
# in the image starts there.  Its address is fixed by the hardware, so the
# witness is the hardware documentation.  Source: GBATEK (Martin Korth,
# problemkaputt.de/gbatek.htm), sections "DS I/O Map" (ARM9 column) and
# "DSi I/O Map" / "DSi Control Registers (SCFG)" / "DSi New Shared WRAM" /
# "DSi New DMA (NDMA)" / "DSi Cameras" / "DSi XpertTeak (DSP)".  The TwlSDK
# drop under sdk/ carries no register headers (include/ holds 21 files, none
# of them ioreg_*.h), so the list is curated from GBATEK, not read from the
# SDK.  Keys are register START addresses, values their width in bytes;
# rows below are only registers the ARM9 can address.  A sole-ref/data
# address in 0x04xxxxxx is accepted only when it is a key here and the
# declared type's alignment fits the width.

def _io_run(base, width, count):
    """`count` consecutive registers of `width` bytes starting at `base`."""
    return {base + i * width: width for i in range(count)}


# 2D engine registers, offsets from 0x04000000 (engine A) / 0x04001000 (B):
# DISPCNT, DISPSTAT, VCOUNT, BG0..3CNT, BG0..3 H/VOFS, BG2/BG3 PA..PD, X, Y,
# WIN0H..WINOUT, MOSAIC, BLDCNT, BLDALPHA, BLDY, MASTER_BRIGHT.  DISPSTAT and
# VCOUNT exist only for engine A.
_IO_2D = {0x00: 4, 0x08: 2, 0x0A: 2, 0x0C: 2, 0x0E: 2,
          0x10: 2, 0x12: 2, 0x14: 2, 0x16: 2, 0x18: 2, 0x1A: 2, 0x1C: 2,
          0x1E: 2,
          0x20: 2, 0x22: 2, 0x24: 2, 0x26: 2, 0x28: 4, 0x2C: 4,
          0x30: 2, 0x32: 2, 0x34: 2, 0x36: 2, 0x38: 4, 0x3C: 4,
          0x40: 2, 0x42: 2, 0x44: 2, 0x46: 2, 0x48: 2, 0x4A: 2,
          0x4C: 2, 0x50: 2, 0x52: 2, 0x54: 2, 0x6C: 2}


def _io_regs_arm9():
    r = {}
    for base in (0x04000000, 0x04001000):
        r.update({base + off: w for off, w in _IO_2D.items()})
    r.update({0x04000004: 2, 0x04000006: 2})                 # DISPSTAT, VCOUNT
    r.update({0x04000060: 2, 0x04000064: 4, 0x04000068: 4})  # 3DCNT, CAPCNT, MMEM FIFO
    r.update(_io_run(0x040000B0, 4, 12))                     # DMA0..3 SAD/DAD/CNT
    r.update(_io_run(0x040000E0, 4, 4))                      # DMA0..3 FILL
    r.update(_io_run(0x04000100, 2, 8))                      # TM0..3 CNT_L/CNT_H
    r.update({0x04000130: 2, 0x04000132: 2})                 # KEYINPUT, KEYCNT
    r.update({0x04000180: 2, 0x04000184: 2, 0x04000188: 4})  # IPCSYNC, FIFOCNT, SEND
    r.update({0x040001A0: 2, 0x040001A2: 2, 0x040001A4: 4})  # AUXSPICNT/DATA, ROMCTRL
    r.update(_io_run(0x040001A8, 1, 8))                      # gamecard command
    r.update({0x040001B0: 4, 0x040001B4: 4, 0x040001B8: 2, 0x040001BA: 2})
    r.update({0x04000204: 2, 0x04000208: 4, 0x04000210: 4, 0x04000214: 4})
    r.update(_io_run(0x04000240, 1, 10))                     # VRAMCNT_A..G, WRAMCNT, H, I
    r.update({0x04000280: 2, 0x04000290: 8, 0x04000298: 8,
              0x040002A0: 8, 0x040002A8: 8})                 # divider
    r.update({0x040002B0: 2, 0x040002B4: 4, 0x040002B8: 8})  # square root
    r.update({0x04000300: 1, 0x04000304: 2})                 # POSTFLG, POWCNT1
    r[0x04000320] = 1                                        # RDLINES_COUNT
    r.update(_io_run(0x04000330, 2, 8))                      # EDGE_COLOR
    r[0x04000340] = 1                                        # ALPHA_TEST_REF
    r.update({0x04000350: 4, 0x04000354: 2, 0x04000356: 2,
              0x04000358: 4, 0x0400035C: 2})                 # CLEAR_*, FOG_*
    r.update(_io_run(0x04000360, 1, 32))                     # FOG_TABLE
    r.update(_io_run(0x04000380, 2, 32))                     # TOON_TABLE
    r.update(_io_run(0x04000400, 4, 16))                     # GXFIFO
    r.update(_io_run(0x04000440, 4, 13))                     # MTX_MODE..MTX_TRANS
    r.update(_io_run(0x04000480, 4, 12))                     # COLOR..PLTT_BASE
    r.update(_io_run(0x040004C0, 4, 5))                      # DIF_AMB..SHININESS
    r.update({0x04000500: 4, 0x04000504: 4, 0x04000540: 4, 0x04000580: 4,
              0x040005C0: 4, 0x040005C4: 4, 0x040005C8: 4})
    r.update({0x04000600: 4, 0x04000604: 4, 0x04000610: 2})  # GXSTAT, RAM_COUNT, 1DOT
    r.update(_io_run(0x04000620, 4, 4))                      # POS_RESULT
    r.update(_io_run(0x04000630, 2, 3))                      # VEC_RESULT
    r.update(_io_run(0x04000640, 4, 16))                     # CLIPMTX_RESULT
    r.update(_io_run(0x04000680, 4, 9))                      # VECMTX_RESULT
    r.update({0x04100000: 4, 0x04100010: 4})                 # IPCFIFORECV, card data
    # DSi ARM9 additions
    r.update({0x04004000: 1, 0x04004004: 2, 0x04004006: 2,
              0x04004008: 4, 0x04004010: 2})                 # SCFG A9ROM/CLK/RST/EXT/MC
    r.update(_io_run(0x04004040, 4, 9))                      # MBK1..MBK9
    r[0x04004100] = 4                                        # NDMAGCNT
    r.update(_io_run(0x04004104, 4, 28))                     # NDMA0..3, 7 words each
    r.update({0x04004200: 2, 0x04004202: 2, 0x04004204: 4,
              0x04004210: 4, 0x04004214: 4})                 # CAM_MCNT/CNT/DAT/SOFS/EOFS
    r.update({0x04004300 + 4 * i: 2 for i in range(14)})    # DSP_PDATA..DSP_REP2
    return r


IO_REGS_ARM9 = _io_regs_arm9()


def attest_sole_ref_data(addr, align=None, lo=0, hi=0):
    """The `sole-ref/data` sub-kind.  Returns (class, witnesses, site) or None.

    This is the original (wave-20) `sole-ref` rule, unchanged: see conditions
    (a), (b) and (c) in the commentary above.  Condition (b) is satisfied
    either by the listings' own block structure (data_object_starts()) or by
    layout/data_objects.txt, and in the latter case only on evidence outside
    `lo`..`hi`.  Two ranges no loaded region covers have their own branch
    (2026-09-27, replacing an unconditional pass added in 0b639465): I/O
    space accepts only a documented register start (IO_REGS_ARM9), and main
    RAM below the ARM9 image only an outside object start or a traced label.
    """
    # I/O space: only the START of a documented ARM9 register (IO_REGS_ARM9);
    # an interior byte, a gap or an undocumented address is refused.  The
    # table gives the width, so with no declared alignment the register
    # start is the whole condition; a declared alignment must divide the
    # address and not exceed the register's width.
    if 0x04000000 <= addr < 0x05000000:
        width = IO_REGS_ARM9.get(addr)
        if width is None:
            return None
        if align is not None and (align > width or addr % align):
            return None
        return "sole-ref", 1, addr, "data"
    # An overlay-window address is attest_sole_ref_overlay_data()'s job
    # (w6 tools lane, 2026-09-29).  This ARM9 rule used to take it too:
    # in_data_section() counts every overlay's bss as data and
    # layout/data_objects.txt carries every overlay's pool words, so an
    # ov021 pool word naming its own object could carry an ov016 site.
    if overlay_windows(addr):
        return None
    # (a) inside a data section, never code
    region = _region_at(addr)
    in_bss = bool(bss_addresses_probe(addr))
    if region is None and not in_bss:
        # main RAM below the ARM9 image (0x02000000..the static module's
        # load address) is in no loaded region, so the section test cannot
        # run; only an outside object start (listing block structure, or a
        # map row whose evidence lies outside lo..hi) or a traced label
        # carries it.  Anything else, interior or unknown, is refused.
        if not (0x02000000 <= addr < 0x02008000):
            return None
        if (addr not in data_object_starts()
                and not _map_attests(addr, lo, hi)
                and addr not in evidence().labels):
            return None
        a = SOLE_REF_DEFAULT_ALIGN if align is None else align
        if a > 1 and (addr % a):
            return None
        return "sole-ref", 1, addr, "data"
    if not in_data_section(addr):
        return None
    # (b) the start of a known object, not its interior
    if addr not in data_object_starts() and not _map_attests(addr, lo, hi):
        return None
    # (c) the declared type's alignment
    a = SOLE_REF_DEFAULT_ALIGN if align is None else align
    if a > 1 and (addr % a):
        return None
    return "sole-ref", 1, addr, "data"


def attest_sole_ref_code(addr, kind, site_region=None, region_hint=None):
    """The `sole-ref/code` sub-kind.  Returns (class, witnesses, site) or None.

    Widened 2026-09-21 to the standard other matching-decompilation projects
    use: the address in the original pool word is accepted when it lands on
    something the layout recognises, without requiring a second referrer.
    This is the code counterpart of `sole-ref/data`: a function pointer
    stored in a pool, or a single-caller callee, whose only reference is the
    pool word under test, so `label` has no outside call to carry it and
    `literal` discards its only witness.

    The rule is narrow and reuses evidence `label`/`veneer` already trust:

      * a traced function start -- a `func_XXXXXXXX` label `disasm.py` put in
        the ARM9 listings, whose ISA is the `.thumb_func` marker it recorded
        there (the same map `label` reads, `evidence().labels`); or
      * a recognised linker veneer at the address (`veneer_at()`), which is
        ARM by construction.

    It refuses an address that is not exactly a label start or a veneer: no
    interior offset, no guess.  It does not require an outside branch --
    that is what `label` already covers, and this class exists for exactly
    the case where no such branch exists.
    """
    if kind not in ("thumb", "arm"):
        return None
    thumb = evidence().labels.get(addr)
    if thumb is not None:
        if (thumb and kind != "thumb") or (not thumb and kind != "arm"):
            return None
        return "sole-ref", 1, addr, "code"
    if kind == "arm" and veneer_at(addr, site_region, region_hint) is not None:
        return "sole-ref", 1, addr, "code"
    return None


def attest_sole_ref_string(addr, lo, hi, site_region=None, region_hint=None):
    """The `sole-ref/string` sub-kind.  Returns (class, witnesses, site) or None.

    Widened 2026-09-21 alongside `sole-ref/code` and `sole-ref/data`: a
    `__FILE__`-style site whose address begins a NUL-terminated printable run
    in the listings, accepted even when the `string` class's stronger
    condition -- a real string, not a data table, immediately before it --
    fails.  This is exactly the shape
    docs/idioms/a-string-after-a-data-table-has-no-witness.md documents:
    "mail.c" and "wifilist.c" are each preceded by a static table rather than
    a string, so the previous terminator does not fix their start the way
    `attest_string()` requires, but the layout still says a printable,
    NUL-terminated run begins exactly there.

    Conditions, each a separate refusal:

      1. the bytes at `addr` are a NUL-terminated printable ASCII run of at
         least MIN_STRING_CHARS characters, entirely inside one region (the
         same test `attest_string()` uses for condition 2);
      2. `addr` is a real run START, not an offset into a longer one: the
         byte immediately before it is NOT itself printable ASCII.  Without
         this, any address one or more characters into a longer string is
         "a NUL-terminated printable run" in its own right -- 0x020A7005 is
         "fl_use.c\0", one byte into "gfl_use.c\0" -- which would make the
         sub-kind accept an arbitrary mid-string offset as if it were an
         object boundary.  This is the string counterpart of `sole-ref/code`
         and `sole-ref/data` each demanding an exact object START;
      3. `addr` is in a data section, not in code: the same test
         `sole-ref/data` condition (a) uses (in_data_section()), so this
         never fires on an instruction stream that happens to decode as
         text, whether or not disasm.py put a func_ label at that exact
         offset -- a byte in the middle of a function with no label of its
         own is still refused;
      4. the whole run lies outside the compared range.

    It does not require anything about what precedes the run being a
    terminator: that is the difference from `attest_string()`, and exactly
    what lets it carry the data-table-neighbour case `attest_string()` must
    refuse.  It still requires the byte before to not be printable text, so
    an arbitrary interior offset of an unrelated table or string is refused
    exactly as an interior offset of a known object is refused for
    `sole-ref/data`.

    The bytes come from witness_region() and, for an overlay's bytes,
    condition 3 is that overlay's own in_overlay_data() (w6 tools lane,
    2026-09-29): the first region in load order, and in_data_section()'s
    "any overlay's bss is data", let another overlay's text carry a site.
    """
    region = witness_region(addr, site_region, region_hint)
    if region is None:
        return None
    data = region.data
    base = region.base
    off = addr - base
    length = _printable_run_forward(data, off, len(data))
    if length is None or length < MIN_STRING_CHARS:
        return None
    if off > 0:
        prev = data[off - 1]
        if 0x20 <= prev <= 0x7E:
            return None             # addr is interior to a longer run
    if region.name.startswith("ov"):
        if not in_overlay_data(region.name, addr):
            return None
    elif not in_data_section(addr):
        return None
    if addr < hi and lo < addr + length + 1:
        return None
    return "sole-ref", 1, addr, "string"


def rom_word_at(addr):
    """The little-endian 32-bit word the original image holds at `addr`.

    None when the address is not inside a loaded region (bss, or off-image):
    there is no ROM word to read, so a caller that needs one must refuse.
    """
    region = _region_at(addr)
    if region is None:
        return None
    off = addr - region.base
    if off < 0 or off + 4 > len(region.data):
        return None
    return struct.unpack_from("<I", region.data, off)[0]


def attest_sole_ref_self(addr, kind, site=None, expect=None,
                         site_region=None):
    """The `sole-ref/self` sub-kind.  Returns (class, witnesses, site) or None.

    Added 2026-09-21.  The community standard (objdiff, decomp.dev, the pret
    projects) is that a relocation site is matched when the relocation names
    the same address the original word names: there is no second-referrer
    requirement, and a file-local table referenced by exactly one function is
    the normal case, not a suspicious one.  The three sub-kinds above still
    ask the layout to recognise the target as an object, a function or a
    string; `self` asks only what that standard asks -- the ROM word at this
    very site already names this address, and the address is data.

    Two guards, and they are the whole class:

      (a) THE TARGET IS DATA.  `in_data_section(addr)` -- the same test
          `sole-ref/data` condition (a) uses.  A target inside a traced
          function's extent, or on a byte the listings emit as an
          instruction, NEVER qualifies: code targets keep their existing
          rules (`label`, `veneer`, `runtime`, `sole-ref/code`), which is
          where the ISA and the entry-point evidence live.  Only rodata,
          data and bss addresses reach this class.

      (b) THE ROM WORD AGREES.  The word the original image holds at the
          relocation site equals the word this resolution is about to write
          there.  A byte-correct compile implies it -- the comparison would
          catch a mismatch anyway -- but it is asserted explicitly here, so
          the class states its own evidence rather than borrowing the
          comparison's.  A site with no readable ROM word (bss, off-image)
          is refused, as is one whose word differs.

    `site` is the link-time address of the relocation site and `expect` the
    word about to be written there; without both, there is nothing to agree
    with and the class refuses.
    """
    if kind != "data":
        return None
    if site is None or expect is None:
        return None
    # An overlay-window target is attest_sole_ref_overlay_self()'s job; the
    # site word is read from the site's own region, never the first region
    # in load order that holds `site` (w6 tools lane, 2026-09-29).
    if overlay_windows(addr):
        return None
    if not in_data_section(addr):
        return None
    if site_region is not None and site_region.startswith("ov"):
        word = rom_word_in(site_region, site)
    else:
        word = rom_word_at(site)
    if word is None or word != (expect & 0xFFFFFFFF):
        return None
    return "sole-ref", 1, addr, "self"


# ---------------------------------------------------------------------------
# sole-ref and matched for overlay-resident targets (2026-09-23)
# ---------------------------------------------------------------------------
#
# Every sole-ref sub-kind above reads the ARM9 listings only: evidence(),
# _scan_data_structure() and layout/data_objects.txt describe arm9_main and
# its autoloads.  An overlay address therefore reached none of them, and a
# call or pool word into an overlay whose only referrer is the range under
# test capped its file at MATCH however the overlay's own listing described
# the target.  The functions below give the overlay listings
# (asm/overlays/ovNNN.s) the same standing, with the one extra question the
# ARM9 image never raises: overlays share RAM windows, so an address is
# inside several of them, and the rule has to know which one is meant.
#
# WHICH OVERLAY
#
# _overlay_pool() answers it the way attest_overlay_label() does, with one
# narrowing that rule does not need:
#
#   1. a region hint on the `symbols:` line (a fourth or fifth token
#      `ovNNN`) names the overlay; a hint naming an overlay whose window does
#      not hold the address is refused outright;
#   2. without one, when the function under test itself lives in an overlay
#      whose window holds the address, that overlay is meant: two overlays
#      that share a window are never resident together, so code in ov010
#      that names an address in ov010's window names ov010's byte there;
#   3. otherwise every overlay whose window holds the address is a
#      candidate, and the rule must find EXACTLY ONE candidate that
#      qualifies.  Two qualifying candidates are ambiguity, never evidence.
#
# Every rule here is reached only from attest_sole_ref() (after the ARM9
# sub-kinds have refused) or from attest_matched(), and attest_sole_ref() is
# itself tried after every stronger class, so no address an existing rule
# resolves changes class.

_OV_DATA = {}
_ORG_RE = re.compile(r"^\s*\.org\s+(0x[0-9A-Fa-f]+|\d+)")
_BYTE_RE = re.compile(r"^\s*\.byte\s+([^/]*)")


def _overlay_region(name):
    for r in load_all_regions():
        if r.name == name:
            return r
    return None


def _overlay_bss_table():
    """{overlay name: (bss lo, bss hi)} from layout/layout.json."""
    if "bss" not in _OV_DATA:
        out = {}
        try:
            with open(os.path.join(ROOT, "layout", "layout.json")) as fh:
                lay = json.load(fh)
        except (OSError, ValueError):
            lay = {}
        for ov in lay.get("overlays") or []:
            lo, hi = ov.get("bss_start"), ov.get("bss_end")
            if lo and hi and hi > lo:
                out["ov%03d" % ov["id"]] = (lo, hi)
        _OV_DATA["bss"] = out
    return _OV_DATA["bss"]


def overlay_declared_starts(name):
    """Object starts layout/data_objects.txt declares for overlay `name`.

    Rows whose region column is an overlay name (`ov115  0x021D6338 ...`).
    The listing cannot carry these: disasm.py has no data-start input, so a
    table it prints inside a pool block gets no start of its own. Each row's
    evidence column must say what fixes the start.
    """
    out = set()
    path = os.path.join(ROOT, "layout", "data_objects.txt")
    try:
        fh = open(path, "r", errors="replace")
    except OSError:
        return out
    with fh:
        for line in fh:
            parts = line.split(None, 3)
            if len(parts) < 3 or parts[0] != name:
                continue
            try:
                out.add(int(parts[1], 16))
            except ValueError:
                continue
    return out


def overlay_data_structure(name):
    """The per-overlay data map of one overlay listing.

    The overlay counterpart of _scan_data_structure(), read from
    asm/overlays/<name>.s alone.  Returns

        (code_addrs, data_addrs, object_starts, func_extents, pool_refs)

    `object_starts` holds every address the listing itself says an object
    begins at: a `pool_`/`veneer_`/`d_`/`g_`/`tbl_` label, and the first
    datum of every `.word`/`.byte` run that follows code (disasm.py emitted
    a new block there).  `pool_refs` is {value: [pool site]} for every word
    under a `pool_` label, i.e. a word some instruction of this overlay
    actually loads.  `.byte` lines carry no address comment; their address
    follows from the `.org` directive before them.
    """
    key = ("s", name)
    if key in _OV_DATA:
        return _OV_DATA[key]
    code, data, starts = set(), set(), set()
    ilen = {}                   # instruction address -> length in bytes
    pool_refs = defaultdict(list)
    reg = _overlay_region(name)
    base = reg.base if reg is not None else 0
    for path in listing_files(name):
        prev_data = False
        in_pool = False
        cur = None                  # the offset .org last pinned, for .byte
        try:
            fh = open(path, "r", errors="replace")
        except OSError:
            continue
        with fh:
            for line in fh:
                s_ = line.strip()
                m = _DATA_LABEL_RE.match(s_)
                if m:
                    starts.add(int(m.group(2), 16))
                    in_pool = m.group(1) == "pool"
                    continue
                mo = _ORG_RE.match(line)
                if mo:
                    cur = int(mo.group(1), 0)
                    continue
                ma = _LINE_ADDR_RE.search(line)
                if ma is None:
                    mb = _BYTE_RE.match(line)
                    if mb and cur is not None:
                        n = len([t for t in mb.group(1).split(",")
                                 if t.strip()])
                        addr = base + cur
                        for k in range(n):
                            data.add(addr + k)
                        if not prev_data:
                            starts.add(addr)
                        prev_data = True
                        cur += n
                    continue
                addr = int(ma.group(1), 16)
                cur = None
                if _DATA_DIRECTIVE_RE.match(line):
                    data.add(addr)
                    if not prev_data:
                        starts.add(addr)
                    prev_data = True
                    if in_pool:
                        mw = _WORD_RE.match(line)
                        if mw:
                            pool_refs[int(mw.group(1), 16)].append(addr)
                else:
                    code.add(addr)
                    mb = _LINE_BYTES_RE.search(line)
                    if mb:
                        ilen[addr] = len(mb.group(1).split())
                    prev_data = False
                in_pool = False
    starts |= overlay_declared_starts(name) & data
    import bisect
    all_code = sorted(code)
    extents = []
    # An extent runs over contiguous instructions and ends where its last
    # instruction does.  The length is the byte count the listing prints
    # (2 for most Thumb lines, 4 for ARM and Thumb `bl`); a line without
    # bytes counts as 4, the old assumption.  Taking every instruction as 4
    # bytes made a Thumb function that ends in a 2-byte instruction swallow
    # the first halfword of the data after it (ov010 func_0216FEAC ends in
    # the `pop` at 0x0216FED6 and was taken to run to 0x0216FEDA, hiding the
    # rodata word at 0x0216FED8), and let an extent bridge a 2-byte gap.
    for a in sorted(scan_listing(name)):
        i = bisect.bisect_right(all_code, a)
        end = a + ilen.get(a, 4)
        while i < len(all_code) and all_code[i] <= end:
            end = all_code[i] + ilen.get(all_code[i], 4)
            i += 1
        extents.append((a, end))
    out = (code, data, starts, extents, pool_refs)
    _OV_DATA[key] = out
    return out


def in_overlay_data(name, addr):
    """True when `addr` is data, not code, in overlay `name`.

    The overlay counterpart of in_data_section(): a datum of that overlay's
    listing (or a halfword/byte inside one), or that overlay's own bss; never
    an instruction and never inside a traced function's extent.
    """
    reg = _overlay_region(name)
    bss = _overlay_bss_table().get(name)
    in_img = reg is not None and reg.base <= addr < reg.base + len(reg.data)
    in_bss = bss is not None and bss[0] <= addr < bss[1]
    if in_bss and not in_img:
        return True
    if not in_img:
        return False
    code, data, _starts, extents, _refs = overlay_data_structure(name)
    if addr in code:
        return False
    import bisect
    lows = [lo_ for lo_, _hi in extents]
    i = bisect.bisect_right(lows, addr) - 1
    if i >= 0 and extents[i][0] <= addr < extents[i][1]:
        return False
    return addr in data or (addr & ~1) in data or (addr & ~3) in data


def overlay_windows(addr):
    """Sorted names of every overlay whose image or bss holds `addr`."""
    out = set(overlay_candidates(addr))
    for name, (lo, hi) in _overlay_bss_table().items():
        if lo <= addr < hi:
            out.add(name)
    return sorted(out)


def _is_arm9_address(addr):
    if 0x04000000 <= addr < 0x05000000 or 0x02000000 <= addr < 0x02008000:
        return True
    r = _region_at(addr)
    return r is not None and not r.name.startswith("ov")


def _overlay_pool(addr, region_hint, site_region, windows=None):
    """(overlays to consider, fixed) per the WHICH OVERLAY rule above.

    `fixed` is True when a hint or the site's own overlay fixed the choice,
    which is what lets an ARM9 pool word stand as a referrer (below).
    Returns ([], False) for a hint whose window does not hold the address.
    """
    wins = overlay_windows(addr) if windows is None else windows
    # The site's own window first (w6 tools lane, 2026-09-29): overlays
    # that share a window are never resident together, so while code of
    # `site_region` runs, an address inside that overlay's image or bss can
    # only be that overlay's byte.  A hint naming another overlay there is
    # physically impossible and is refused, not obeyed.  The window test
    # always reads image AND bss (overlay_windows()), whatever `windows`
    # the caller narrowed the candidates to.
    if _own_window(site_region, addr):
        if region_hint is not None and region_hint != site_region:
            return [], False
        return ([site_region] if site_region in wins else []), True
    if region_hint is not None:
        if region_hint not in wins:
            return [], False
        return [region_hint], True
    return wins, len(wins) == 1


def _own_window(site_region, addr):
    """True when `site_region` is an overlay whose image or bss holds addr."""
    return (site_region is not None and OVERLAY_NAME_RE.match(site_region)
            is not None and site_region in overlay_windows(addr))


def witness_region(addr, site_region=None, region_hint=None):
    """The one region whose BYTES may witness `addr`, or None.

    Every class that reads the original image at the target address (the
    `string` and `data_table` classes, `sole-ref/string`, the veneer shape)
    reads it here, never from whichever region load_all_regions() lists
    first (w6 tools lane, 2026-09-29).  Overlays share RAM windows, so the
    first region holding 0x021DE555 was ov021's `...land_data_patch.c` while
    the site under test, in ov016, meant ov016's own .bss at 0x021DE558.

      - An address in no overlay window is always-resident (ARM9 static,
        its autoloads, the TWL block): its region answers.
      - Otherwise the overlay comes from _overlay_pool() and must be FIXED:
        the site's own overlay when its window (image or bss) holds the
        address; else the `symbols:` hint; else the only overlay whose
        window holds it.  Several candidate windows and nothing to choose
        between them is refused: another overlay's bytes are never read on
        the strength of the address alone.
      - The chosen overlay's image must hold the address (a bss address has
        no bytes to read).
    """
    if not overlay_windows(addr):
        return _region_at(addr)
    pool, fixed = _overlay_pool(addr, region_hint, site_region)
    if not fixed or len(pool) != 1:
        return None
    r = _overlay_region(pool[0])
    if r is None or not r.base <= addr < r.base + len(r.data):
        return None
    return r


def _overlay_start_attested(name, addr, lo, hi, fixed):
    """True when overlay `name` says an object starts at `addr`.

    Either the listing's own block structure / labels carry the start, or a
    pool word names it from OUTSIDE the compared range: a pool word of the
    same overlay, or, when the overlay is fixed, an ARM9 pool word.  A lone
    reference inside lo..hi never attests its own start, exactly as for
    layout/data_objects.txt's `pool` rows.
    """
    _code, _data, starts, _ext, refs = overlay_data_structure(name)
    if addr in starts:
        return True
    if any(not lo <= s < hi for s in refs.get(addr, ())):
        return True
    if fixed and any(not lo <= s < hi
                     for s in evidence().pool_words.get(addr, ())):
        return True
    return False


def _hint_contested(addr, region_hint):
    """True when a `symbols:` overlay hint cannot choose at `addr`.

    A hint is the source's own unchecked claim. It is refused when another
    overlay mapped over the same window also has an object start at the
    address: the hint alone cannot say which of the two the word was
    written for (audit 2026-09-23, finding 6). Applied to the overlay
    sole-ref/data sub-kind outright, and to sole-ref/self through
    self_hint_accepted() (seed round 10b).
    """
    if region_hint is None:
        return False
    for other in overlay_windows(addr):
        if other != region_hint and addr in overlay_data_structure(other)[2]:
            return True
    return False


def self_hint_accepted(addr, region_hint, loaded_ids):
    """May a `symbols:` overlay hint choose the overlay for sole-ref/self?

    Yes when the hint is uncontested at `addr` (_hint_contested(): no other
    overlay mapped over the window has an object start there).  When it IS
    contested, yes only when the function under test itself attests the
    hinted overlay's id through the `overlay_id` class: `loaded_ids` is the
    set of overlay indices its `overlay_id` sites resolved to, i.e. the
    overlays it loads.  A function that loads ovNNN and names an address in
    ovNNN's window names ovNNN's byte there: the two are resident together,
    which is exactly what the hint claims.  Anything else is the source's
    unchecked claim and is refused (seed round 10b).
    """
    if region_hint is None or not _hint_contested(addr, region_hint):
        return True
    m = re.match(r"ov(\d+)$", region_hint)
    return bool(m) and int(m.group(1)) in loaded_ids


def attest_sole_ref_overlay_data(addr, align=None, lo=0, hi=0,
                                 region_hint=None, site_region=None):
    """`sole-ref/data` for an overlay address.  (class, n, site, "data")/None.

    The same three conditions as attest_sole_ref_data(), each read from the
    selected overlay's own listing (overlay_data_structure()):

      (a) the address is data in that overlay (in_overlay_data());
      (b) it is an object START there (_overlay_start_attested());
      (c) the declared alignment holds.

    Exactly one overlay of the pool may qualify.  When neither a hint nor
    the site's own overlay fixed the choice, exactly one candidate may even
    hold DATA at the address: a start in one overlay is no evidence while
    another overlapping overlay also has data there, because nothing says
    which of the two the pool word was written for.
    """
    if _is_arm9_address(addr):
        return None                     # ARM9: attest_sole_ref_data()'s job
    pool, fixed = _overlay_pool(addr, region_hint, site_region)
    if not pool:
        return None
    if _hint_contested(addr, region_hint):
        return None
    a = SOLE_REF_DEFAULT_ALIGN if align is None else align
    if a > 1 and (addr % a):
        return None
    data_in = [n for n in pool if in_overlay_data(n, addr)]
    if not fixed and len(data_in) != 1:
        return None
    ok = [n for n in data_in
          if _overlay_start_attested(n, addr, lo, hi, fixed)]
    if len(ok) != 1:
        return None
    return "sole-ref", 1, addr, "data"


def rom_word_in(region_name, addr):
    """The original word at `addr` in the named region, or None."""
    reg = _overlay_region(region_name) if region_name else None
    if reg is None:
        return None
    off = addr - reg.base
    if off < 0 or off + 4 > len(reg.data):
        return None
    return struct.unpack_from("<I", reg.data, off)[0]


def attest_sole_ref_overlay_self(addr, kind, site=None, expect=None,
                                 region_hint=None, site_region=None):
    """`sole-ref/self` for an overlay address.  (class, n, site, "self")/None.

    attest_sole_ref_self()'s two guards, overlay-aware: (a) the target is
    data, not code, in exactly one overlay of the pool (in_overlay_data());
    (b) the original word at the relocation site, read from the region the
    function under test lives in, equals the word about to be written.
    """
    if kind != "data" or site is None or expect is None:
        return None
    if _is_arm9_address(addr):
        return None
    # The hint check for this sub-kind needs the function's other sites (a
    # contested hint stands only when the function loads the hinted overlay,
    # self_hint_accepted()), so resolve_relocations() applies it after the
    # `overlay_id` pass.  Callers without sites (attest() alone) see the
    # unguarded answer.
    pool, _fixed = _overlay_pool(addr, region_hint, site_region)
    if len([n for n in pool if in_overlay_data(n, addr)]) != 1:
        return None
    if site_region is not None and site_region.startswith("ov"):
        word = rom_word_in(site_region, site)
    else:
        word = rom_word_at(site)
    if word is None or word != (expect & 0xFFFFFFFF):
        return None
    return "sole-ref", 1, addr, "self"


def attest_sole_ref_overlay_code(addr, kind, region_hint=None,
                                 site_region=None):
    """`sole-ref/code` for an overlay label.  (class, n, site, "code")/None.

    The ARM9 rule (attest_sole_ref_code()) with the overlay listings as the
    label index: the address is exactly a `func_` label, with the declared
    ISA, in exactly one overlay of the pool.  No outside branch is required,
    which is what separates it from the overlay branch of `label`: it is for
    the callee whose only caller image-wide is the range under test.
    """
    if kind not in ("thumb", "arm"):
        return None
    pool, _fixed = _overlay_pool(addr, region_hint, site_region,
                                 overlay_candidates(addr))
    labeled = [n for n in pool
               if scan_listing(n).get(addr) == (kind == "thumb")
               and not on_ciphertext(n, addr)]
    if len(labeled) != 1:
        return None
    return "sole-ref", 1, addr, "code"


def attest_sole_ref(addr, kind, align=None, lo=0, hi=0,
                    site=None, expect=None, region_hint=None,
                    site_region=None):
    """The `sole-ref` class.  Returns (class, witnesses, site, subkind) or None.

    Tried only after every other class has failed, for every `kind`.  Three
    named sub-kinds, dispatched by `kind`; see attest_sole_ref_data(),
    attest_sole_ref_code(), attest_sole_ref_string() and
    attest_sole_ref_self() for what each
    accepts and refuses.  `subkind` is one of "data", "code", "string" or
    "self"; `site`/`expect` are the relocation site's link-time address and
    the word about to be written there, which only `sole-ref/self` reads.
    and attest() propagates it onto the resolved Site so the shard record
    can name which one carried a given address.

    `region_hint` (the `symbols:` line's overlay token) and `site_region`
    (the region the function under test lives in) are read only by the
    overlay rules, which run after the ARM9 sub-kinds have refused: see
    "sole-ref and matched for overlay-resident targets" above.
    """
    if kind == "data":
        proof = attest_sole_ref_data(addr, align, lo, hi)
        if proof is not None:
            return proof
        proof = attest_sole_ref_string(addr, lo, hi, site_region, region_hint)
        if proof is not None:
            return proof
        proof = attest_sole_ref_self(addr, kind, site, expect, site_region)
        if proof is not None:
            return proof
        proof = attest_sole_ref_overlay_data(addr, align, lo, hi,
                                             region_hint, site_region)
        if proof is not None:
            return proof
        return attest_sole_ref_overlay_self(addr, kind, site, expect,
                                            region_hint, site_region)
    if kind in ("thumb", "arm"):
        proof = attest_sole_ref_code(addr, kind, site_region, region_hint)
        if proof is not None:
            return proof
        proof = attest_sole_ref_overlay_code(addr, kind, region_hint,
                                             site_region)
        if proof is not None:
            return proof
        proof = attest_sole_ref_twl_code(addr, kind, region_hint)
        if proof is not None:
            return proof
        return attest_sole_ref_ov230d_code(addr, kind, region_hint)
    return None


# ---------------------------------------------------------------------------
# the `matched` class
# ---------------------------------------------------------------------------
#
# The four image classes above all ask the same question of the original
# bytes: does something OUTSIDE the compared range say what lives at this
# address?  There is a fifth answer, and it is not in the image at all: for an
# address this project has already matched, our own compiled proof says what
# lives there.
#
# An EXACT manifest entry is the statement "this source file, compiled with
# this configuration and placed at this address, reproduces the original bytes
# there, relocation fields included".  Reproducing the bytes of a function at
# 0x02018DB4 is a far stronger claim about 0x02018DB4 than "some pool word
# elsewhere holds that number": it pins the entry point, its instruction set
# and its whole body.  So a call site whose target is covered by an EXACT
# entry has a witness, and the witness is a compilation, not a byte of the
# range under test.
#
# WHY THIS IS NOT CIRCULAR
#
# Two separate arguments, one for each way the circularity could come back.
#
#   * A witness may not be the range under test.  The entry being verified
#     cannot witness itself: that is exactly "read the answer out of the bytes
#     and then confirm the bytes contain the answer", the tautology the
#     honesty rule exists to refuse.  The rule here is therefore by SOURCE
#     FILE: an entry whose `source` is the file under test is discarded, which
#     covers both `manifest --verify` re-checking a committed entry and a
#     pending file that happens to name its own address.
#
#   * One-way dependence on an already-verified entry is sound.  Every entry
#     in the manifest was verified against the ORIGINAL bytes, over its own
#     address range, using evidence that never mentions the file under test:
#     the manifest is EXACT-only and pending files are deliberately out of it,
#     so no committed entry's verification could have consulted one.  The
#     dependence therefore has a direction, from the file being promoted to
#     entries that already stood without it, and the graph of "who witnessed
#     whom at the moment of verification" is acyclic.
#
#     Even the symmetric case that arises later, when a promoted file becomes
#     a witness for an entry that witnessed it, is not a tautology, because
#     neither check is a lookup: each of the two is a byte comparison against
#     the original image over a range disjoint from the other's.  A wrong
#     address still resolves to a wrong instruction and still comes out DIFF,
#     which is the same falsifiability the `literal` and `string` classes
#     rest on.  What would be circular, and is refused, is a range attesting
#     itself.
#
# What counts as covered, and the refusals, are in attest_matched():
#
#   1. the entry's kind is one the project verifies against game bytes
#      (`game`, `game_unit`, `sdk_calibration`);
#   2. its status is EXACT or EXACT*.  A MATCH entry proves nothing about a
#      relocation target -- its own relocation fields are still wildcards --
#      and is refused;
#   3. the address is the entry's own address, or one of the member function
#      addresses its unit layout records in `functions:`.  A unit that
#      reproduces 264 bytes covering two functions attests both entry points;
#   4. the entry's source file is not the file under test;
#   5. the ISA is the entry's, and it has to be the ISA the source declares.
#      An entry compiled `-thumb` is not evidence for an `arm` extern.
#
# The class never applies to `data`: an entry attests the code it reproduced,
# not an object some instruction in it happens to load.

MATCHED_KINDS = ("game", "game_unit", "sdk", "sdk_unit", "sdk_calibration", "runtime")
MATCHED_STATUS = ("EXACT", "EXACT*")


def matched_index(entries):
    """{address: [(entry name, source, isa, region)]} for the EXACT entries.

    A list per address, because overlays share RAM windows: two overlay
    shards can each hold an EXACT entry at the same address, and
    attest_matched() has to know which overlay each one proves.

    Written against a list rather than reading the manifest itself so that
    the selftest can hand it entries the manifest does not contain, which is
    the only way to exercise the status and kind refusals: the manifest is
    EXACT-only by construction.
    """
    out = {}
    for e in entries:
        if e.get("kind") not in MATCHED_KINDS:
            continue
        if e.get("status") not in MATCHED_STATUS:
            continue
        isa = "thumb" if e.get("isa") == "thumb" else "arm"
        who = (e["name"], e.get("source", ""), isa, e.get("region") or "arm9")
        addrs = [int(e["address"], 16)]
        # A unit entry records the functions its compared range covered; each
        # of those addresses is pinned by the same byte comparison.
        for n in e.get("functions") or []:
            m = _ADDR_NAME_RE.match(n)
            if m:
                addrs.append(int(m.group(1), 16))
        # A runtime entry names its members by vendor name; `covers` holds
        # the runtime rows its per-function comparisons reproduced.
        for c in e.get("covers") or []:
            addrs.append(int(c, 16))
        for a in addrs:
            lst = out.setdefault(a, [])
            if who not in lst:
                lst.append(who)
    return out


_MATCHED_AT = {}


def matched_addresses():
    """matched_index() over every manifest shard."""
    if "a" not in _MATCHED_AT:
        _MATCHED_AT["a"] = matched_index(load_manifest_entries())
    return _MATCHED_AT["a"]


EXTERNAL_SOURCE = "external:"


def source_key(path):
    """A source path spelled the way the manifest records it, or None.

    None only for no path at all.  A file outside the repository (a lane's
    scratchpad copy, another drive on Windows) gets the key
    "external:<absolute path>".  It cannot be any manifest entry's `source`
    (those are repo-relative), so the `matched` class's self-reference check
    has an answer for it.  Returning None here used to make attest_matched()
    refuse outright, so every `matched` callee of a scratch copy came out
    "no witness outside" while the same file inside the repo resolved them
    (0x021DA6B8: 80 of 83 from the scratchpad, 83 of 83 from scratch/).
    """
    if not path:
        return None
    ab = os.path.abspath(path)
    try:
        rel = os.path.relpath(ab, ROOT)
    except ValueError:          # another drive on Windows
        rel = "../"
    rel = rel.replace("\\", "/")
    if rel.startswith("../"):
        return EXTERNAL_SOURCE + ab.replace("\\", "/")
    return rel


def _matched_overlay_ok(addr, kind, region, region_hint, site_region):
    """Whether an EXACT entry of overlay `region` proves the call meant.

    The matched-overlay rule (2026-09-23).  An entry under
    layout/matched/ovNNN/ proves what that overlay holds at the address;
    overlays share RAM windows, so it attests the site only when that
    overlay is the one meant, decided by the WHICH OVERLAY rule of
    _overlay_pool(): the `symbols:` hint names it, or the function under
    test lives in it, or, with neither, no other overlay whose window holds
    the address carries a `func_` label of the declared ISA there or an
    EXACT entry of its own (the entry's overlay is then the only candidate
    anything says is code of that ISA at that address).
    """
    wins = overlay_candidates(addr)
    # the site's own window first, as in _overlay_pool() (w6 tools lane,
    # 2026-09-29): a hint naming another overlay there cannot be obeyed
    if _own_window(site_region, addr):
        return site_region == region and region_hint in (None, region)
    if region_hint is not None:
        return region_hint == region
    thumb = kind == "thumb"
    others = [n for n in wins if n != region]
    entries = matched_addresses().get(addr, [])
    for n in others:
        if scan_listing(n).get(addr) == thumb:
            return False
        if any(w[3] == n for w in entries):
            return False
    return True


def attest_matched(addr, kind, src=None, region_hint=None, site_region=None):
    """The `matched` class.  Returns (class, witnesses, site) or None.

    `src` is the source file under test, in manifest spelling.  Without it
    self-reference cannot be checked, so the class refuses outright rather
    than risk an entry witnessing itself.  An entry from an overlay shard
    (region `ovNNN`) attests only when _matched_overlay_ok() says that
    overlay is the one meant; `region_hint` and `site_region` feed it.
    """
    if kind not in ("thumb", "arm"):
        return None
    if src is None:
        return None
    found = matched_addresses().get(addr)
    if not found:
        return None
    if not found[0][3].startswith("ov"):
        # ARM9 and autoload entries: the rule as it always was, on the
        # first entry recorded at the address.
        _name, source, isa, _region = found[0]
        if source == src:
            return None         # an entry may not witness its own file
        if isa != kind:
            return None
        return "matched", 1, addr
    for _name, source, isa, region in found:
        if source == src:
            return None         # an entry may not witness its own file
    for _name, source, isa, region in found:
        if isa != kind:
            continue
        if not _matched_overlay_ok(addr, kind, region, region_hint,
                                   site_region):
            continue
        return "matched", 1, addr
    return None


def attest(addr, kind, lo, hi, src=None, region_hint=None, align=None,
           site=None, expect=None, site_region=None):
    """Independent evidence for `addr`, or None.

    `lo`..`hi` is the byte range under comparison; a witness inside it does
    not count, because that is the range whose contents the resolved value
    is about to be checked against.  `src` is the source file under test,
    which the `matched` class needs to refuse self-reference.  `region_hint`
    is an overlay name from the source's own `symbols:` line, used only by
    the overlay branch of the `label` class to resolve which of several
    overlapping overlays is meant.  `align` is the alignment the site's
    declared type demands, which only the `sole-ref` class consults.
    Returns (class, witness_count, example_site), except for `sole-ref`,
    which appends a fourth element naming the sub-kind ("data"/"code"/
    "string"/"self"); callers that only need the class name still read
    element 0.  `site` is the relocation site's link-time address and
    `expect` the word about to be written there; only `sole-ref/self`
    consults them, and without them that sub-kind refuses.  `site_region`
    is the region the function under test lives in; only the overlay rules
    of `matched` and `sole-ref` read it (see "sole-ref and matched for
    overlay-resident targets").
    """
    ev = evidence()
    if kind in ("thumb", "arm"):
        if addr in ev.labels:
            sites = [s for s in ev.calls.get(addr, ()) if not lo <= s < hi]
            if sites:
                return "label", len(sites), sites[0]
            # Nothing in this region calls the label.  A branch from another
            # region is the same kind of evidence, so look there before
            # falling back to the weaker classes.  The scan is lazy because
            # it reads every overlay listing.
            sites = [s for s in xregion_calls().get(addr, ())
                     if not lo <= s < hi]
            if sites:
                return "label", len(sites), sites[0]
            # A labelled function nobody in this image calls directly is
            # still a real function (disasm.py traced code there), but the
            # only thing that names it may be the literal we are checking.
            # Fall through to the literal class rather than claim "label".
        else:
            # No label in the ARM9 listings.  The address may still be an
            # overlay-resident function; the index is wider but the standard
            # is the same, a traced entry point plus an outside branch to it.
            if region_hint == TWL_REGION:
                proof = attest_twl_label(addr, kind, lo, hi, region_hint)
            elif region_hint == OV230D_REGION:
                proof = attest_ov230d_label(addr, kind, lo, hi, region_hint)
            else:
                proof = attest_overlay_label(addr, kind, lo, hi, region_hint,
                                             site_region)
            if proof is not None:
                return proof
        # A curated vendor-library entry (MSL/runtime.a) needs neither a
        # label nor an outside call: see "the `runtime` class" above for why
        # that table carries the same evidentiary standing as
        # layout/symbols_sdk.json does for SDK symbols.
        proof = attest_runtime(addr, kind)
        if proof is not None:
            return proof
        # A recovered TwlSDK/runtime library entry, the same evidentiary
        # standing as the `runtime` class above but sourced from
        # layout/symbols_sdk.json instead of layout/runtime_arm9.txt, and not
        # restricted to ARM.  Tried after `runtime` because the two tables
        # are curated independently and neither takes precedence; in
        # practice they do not overlap.
        proof = attest_sdk(addr, kind, site_region, region_hint)
        if proof is not None:
            return proof
    want = addr | 1 if kind == "thumb" else addr
    sites = [s for s in ev.pool_words.get(want, ()) if not lo <= s < hi]
    if sites:
        return "literal", len(sites), sites[0]
    if kind == "arm":
        proof = attest_veneer(addr, kind, lo, hi, site_region, region_hint)
        if proof is not None:
            return proof
    if kind == "data":
        proof = attest_string(addr, lo, hi, site_region, region_hint)
        if proof is not None:
            return proof
        proof = attest_data_table(addr, lo, hi, site_region, region_hint)
        if proof is not None:
            return proof
    # Last, because it is the one class that is not a reading of the original
    # image: our own compiled proof that the target address holds a function
    # we already reproduced byte for byte.
    # A source outside the repo (source_key()'s external key) can be a copy
    # of the very entry at `addr`, which the by-file rule cannot see, so for
    # it an entry inside the compared range is refused: that would be the
    # range attesting itself.
    if not (src and src.startswith(EXTERNAL_SOURCE) and lo <= addr < hi):
        proof = attest_matched(addr, kind, src, region_hint, site_region)
        if proof is not None:
            return proof
    # Last of all, after every other class has failed: the layout's own
    # statement that a data object, a traced function or a printable string
    # begins at this address.  See "the `sole-ref` class" above.  Every kind
    # is tried here, code included: sole-ref/code exists for exactly the
    # function pointers and single-caller callees that never reach `label`.
    proof = attest_sole_ref(addr, kind, align, lo, hi, site, expect,
                            region_hint, site_region)
    if proof is not None:
        return proof
    return None


# ---------------------------------------------------------------------------
# the `overlay_id` class
# ---------------------------------------------------------------------------
#
# FS_OVERLAY_ID(name) is an absolute linker symbol whose value is the
# overlay's index in the y9 table, so a function that loads an overlay by
# name carries an ABS32 pool word holding a small integer (see
# docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).  No
# address-based class can reach it: 0x72 is not a location, nothing is
# traced there, and the one pool word that holds it is usually the one under
# comparison, so `literal` discards its only witness.  `sole-ref` fails for
# the same reason, because nothing in the layout starts at 0x00000072.
#
# What makes such a word an overlay id is not its value alone (any small
# integer is a small integer) but what the code does with it.  The class is
# therefore a statement about the function under test, and all three of
# these must hold, each a separate refusal in attest_overlay_id():
#
#   1. the declared value is a valid overlay index: an `id` listed in the
#      `overlays` array of layout/layout.json (237 entries, 0..236).  The
#      layout, never the ROM, is the authority;
#   2. the site is a real pool word of the function: some pc-relative load
#      in the function's own code (Thumb `ldr Rd, [pc, #imm]`, ARM
#      `ldr Rd, [pc, #+-imm]`) addresses exactly the site.  The load is
#      decoded from the instruction bytes, not read off a listing label,
#      because the listings miss these words: a pool run gets a pool_ label
#      only on its first word (0x0200F228 and 0x0200F22C are unlabelled
#      continuation words of func_0200F17C's run), and some pools are
#      printed as Thumb code or as unlabelled .word runs (func_02010AC4,
#      func_0200F234).  The load instruction is a concrete byte of the
#      comparison, so it is checked against the original like any other;
#   3. the loaded value reaches a known overlay-loading call as the id
#      argument: walking forward in straight-line code from that load, the
#      first call is to an entry of OVERLAY_ID_CONSUMERS, and the register
#      that entry reads the id from still holds the loaded value (loaded
#      there, or copied there, and not overwritten since).  The call has to be a
#      relocation site that has itself resolved under some other class (a
#      `bl`/`blx`, or a pool word a `bx`/`blx Rm` jumps through), so the
#      consumer's identity rests on independent evidence.  The value may be
#      copied between registers on the way (`adds r0, r7, #0`, `mov`), and
#      an unconditional `b` is followed, since the path stays single; an
#      instruction the walker does not model, a conditional branch, a data
#      word, a call to anything else, or more than OVERLAY_ID_WALK steps
#      ends the walk and refuses.
#
# The witness is inside the compared range by construction, which the
# honesty rule normally forbids.  It is admissible here for the reason
# `local` is: the value is never read from the word being checked.  It comes
# from the declaration, and the three conditions restrict what a declaration
# may say to 237 values fed to a loader's id parameter.  A declaration with
# the wrong id is still a valid index and still resolves, then comes out
# DIFF against the original, exactly as a wrong `literal` does.  Tried after
# every other class, and only for ABS32 data sites, because it needs the
# function's call sites to be resolved first.

# A bound on the walk, not part of the evidence: every step is decoded and
# its effect on the id register tracked, and the walk stops on anything it
# does not model.  8 was too short for the ov010 main sequence
# (func_02155478), where mwccarm fills a record field by field between the
# pool load of the id and the call: ov100's id is 19 steps from its call
# (13 str/ldr to other registers, a `mov`, an `adds r5`, a `b` back to the
# shared call block, a copy to r3), ov195's 15 and ov119's 10, each step an
# instruction the walker already models.  The bound only keeps a `b` loop
# from spinning.
OVERLAY_ID_WALK = 24

# Callee address -> (name, register the overlay id arrives in, how verified).
# Every entry was verified by reading the code; the register column is the
# one the id travels in, which is not always the first argument.
OVERLAY_ID_CONSUMERS = {
    # TwlSDK fs_overlay.o, layout/symbols_sdk.txt: FS_LoadOverlay(target, id)
    # and FS_UnloadOverlay(target, id) take the FSOverlayID second.
    0x02079264: ("FS_LoadOverlay", 1, "layout/symbols_sdk.txt"),
    0x020792B8: ("FS_UnloadOverlay", 1, "layout/symbols_sdk.txt"),
    # src/matched/arm9/sub_02034AC4.c (EXACT): passes its argument to
    # FS_LoadOverlay's id parameter.
    0x02034AC4: ("sub_02034AC4", 0, "src/matched/arm9/sub_02034AC4.c"),
    # src/matched/arm9/sub_02034A5C.c (EXACT): finds the registration holding its
    # argument and hands it to sub_02034A3C, which calls
    # FS_UnloadOverlay(0, entry->handle) (src/matched/arm9/sub_02034A3C.c).
    0x02034A5C: ("sub_02034A5C", 0, "src/matched/arm9/sub_02034A5C.c"),
    # The proc system.  src/matched/arm9/func_02031538.c (EXACT) stores its r0 at
    # Proc+4, which src/matched/arm9/func_020315F0.c (EXACT) passes to
    # func_02034AC4 on the first step and to func_02034A5C on the last.
    0x02031538: ("func_02031538", 0, "src/matched/arm9/func_02031538.c"),
    # src/matched/arm9/func_020314F4.c (EXACT): forwards its r1 to
    # func_02031538's r0.
    0x020314F4: ("func_020314F4", 1, "src/matched/arm9/func_020314F4.c"),
    # src/matched/arm9/func_02031348.c (EXACT): an `ldr ip; bx ip` tail thunk to
    # func_020314F4, so r1 passes through untouched.
    0x02031348: ("func_02031348", 1, "src/matched/arm9/func_02031348.c"),
    # Not matched; read from the listing (asm/arm9/src/013_0202EC44.s,
    # 0x020312CC..0x020312F0): mov r4, r0 ... mov r1, r4; bl func_020314F4.
    0x020312CC: ("func_020312CC", 0, "listing 0x020312CC..0x020312F0"),
    # src/matched/arm9/func_020120B4.c (EXACT): func_02031348(p->f8, id, a, b)
    # with the caller's r1 passed through.
    0x020120B4: ("func_020120B4", 1, "src/matched/arm9/func_020120B4.c"),
    # src/matched/arm9/func_020124AC.c (EXACT): stores its r1 (a1) in the
    # descriptor and calls func_02034AC4(a1) with it unchanged, so the id
    # arrives in r1.  Read from the matched source 2026-09-27.
    0x020124AC: ("func_020124AC", 1, "src/matched/arm9/func_020124AC.c"),
}

_OVERLAY_IDS = {}


def overlay_ids():
    """The set of overlay indices layout/layout.json lists."""
    if "ids" not in _OVERLAY_IDS:
        out = set()
        try:
            with open(os.path.join(ROOT, "layout", "layout.json")) as fh:
                lay = json.load(fh)
        except (OSError, ValueError):
            lay = {}
        for ov in lay.get("overlays") or []:
            if isinstance(ov.get("id"), int):
                out.add(ov["id"])
        _OVERLAY_IDS["ids"] = out
    return _OVERLAY_IDS["ids"]


_NO_DEST = -1       # an instruction that writes no general register


def _thumb_dest(hw):
    """The register a 16-bit Thumb instruction writes, _NO_DEST, or None.

    None means the walker does not model the instruction and must stop.
    """
    top = hw >> 11
    if top <= 0x03:                          # lsl/lsr/asr/add/sub reg, imm3
        return hw & 7
    if top in (0x04, 0x06, 0x07):            # movs / adds / subs imm8
        return (hw >> 8) & 7
    if top == 0x05:                          # cmp imm8
        return _NO_DEST
    if (hw & 0xFC00) == 0x4000:              # ALU register ops
        op = (hw >> 6) & 0xF
        return _NO_DEST if op in (8, 10, 11) else hw & 7
    if (hw & 0xFC00) == 0x4400:              # hi-register add / cmp / mov
        op = (hw >> 8) & 3
        if op == 1:
            return _NO_DEST
        if op == 3:
            return None                      # bx / blx, seen by the caller
        rd = ((hw >> 4) & 8) | (hw & 7)
        return None if rd == 15 else rd
    if top == 0x09:                          # ldr Rd, [pc, #imm]
        return (hw >> 8) & 7
    if top in (0x0A, 0x0B):                  # load/store, register offset
        return _NO_DEST if ((hw >> 9) & 7) < 3 else hw & 7
    if 0x0C <= top <= 0x11:                  # load/store, immediate offset
        return hw & 7 if hw & 0x0800 else _NO_DEST
    if top in (0x12, 0x13):                  # sp-relative load/store
        return (hw >> 8) & 7 if hw & 0x0800 else _NO_DEST
    if top in (0x14, 0x15):                  # add Rd, pc / sp
        return (hw >> 8) & 7
    if (hw & 0xFF00) == 0xB000:              # add / sub sp, #imm
        return _NO_DEST
    return None


def _arm_dest(w):
    """The register an ARM instruction writes, _NO_DEST, or None."""
    if (w >> 28) == 0xF:
        return None
    kind = (w >> 25) & 7
    rd = (w >> 12) & 0xF
    if kind in (0, 1):
        if kind == 0 and (w & 0x90) == 0x90:
            # multiplies, swaps and halfword transfers: only the plain
            # pre-indexed halfword forms are modelled
            if (w & 0x60) == 0 or (w & 0x01200000) != 0x01000000:
                return None
            if w & 0x00100000:
                return None if rd == 15 else rd
            return _NO_DEST
        op = (w >> 21) & 0xF
        if 8 <= op <= 11:
            return _NO_DEST if w & 0x00100000 else None   # tst..cmn / msr
        return None if rd == 15 else rd
    if kind in (2, 3):
        if kind == 3 and w & 0x10:
            return None
        if (w & 0x01200000) != 0x01000000:         # post-index or writeback
            return None
        if not w & 0x00100000:
            return _NO_DEST
        return None if rd == 15 else rd
    return None


def _pc_load(fb, j):
    """(Rd, literal offset, size) if the instruction at j is a pc load."""
    if fb.thumb:
        if j + 2 > len(fb.data):
            return None
        hw = struct.unpack_from("<H", fb.data, j)[0]
        if (hw & 0xF800) == 0x4800:
            return (hw >> 8) & 7, ((j + 4) & ~3) + (hw & 0xFF) * 4, 2
        return None
    if j + 4 > len(fb.data) or j & 3:
        return None
    w = struct.unpack_from("<I", fb.data, j)[0]
    if (w & 0x0F7F0000) == 0x051F0000 and (w >> 28) != 0xF:
        imm = w & 0xFFF
        lit = j + 8 + (imm if w & 0x00800000 else -imm)
        return (w >> 12) & 0xF, lit, 4
    return None


def _consumer_of(site):
    """The OVERLAY_ID_CONSUMERS entry a resolved site names, or None."""
    if site is None or not site.resolved or site.value is None:
        return None
    return OVERLAY_ID_CONSUMERS.get(site.value & ~1)


def _copy_source(fb, j):
    """Rm when the instruction at j is a plain register copy Rd <- Rm."""
    if fb.thumb:
        hw = struct.unpack_from("<H", fb.data, j)[0]
        if (hw & 0xFFC0) == 0x1C00:          # adds Rd, Rn, #0
            return (hw >> 3) & 7
        if (hw & 0xFFC0) == 0x0000:          # movs Rd, Rm (lsls #0)
            return (hw >> 3) & 7
        if (hw & 0xFF00) == 0x4600:          # mov Rd, Rm (hi registers)
            return (hw >> 3) & 0xF
        return None
    w = struct.unpack_from("<I", fb.data, j)[0]
    if (w & 0xFFEF0FF0) == 0xE1A00000:       # mov{s} Rd, Rm, unconditional
        return w & 0xF
    return None


def _walk_to_consumer(fb, start, reg, by_off):
    """Follow the value loaded into `reg` from offset `start` to a call.

    The value may be copied to other registers on the way (mwccarm parks an
    id in a callee-saved register and copies it into r0 for each call), so
    the walk tracks the set of registers that hold it.  Returns (consumer
    entry, call offset) when the first call is an overlay-id consumer whose
    id register holds the value, else None.
    """
    holds = set([reg])          # registers that still hold the loaded value
    pooled = {}                 # register -> literal offset it was loaded from
    j = start
    step = 2 if fb.thumb else 4
    for _ in range(OVERLAY_ID_WALK):
        if j + step > len(fb.data):
            return None
        st = by_off.get(j)
        if st is not None:
            if st.rtype in _THUMB_BRANCH or st.rtype in _ARM_BRANCH:
                ent = _consumer_of(st)
                if ent is not None and ent[1] in holds:
                    return ent, j
            return None         # a call to something else, or a data word
        if fb.thumb:
            hw = struct.unpack_from("<H", fb.data, j)[0]
            if (hw & 0xFF07) in (0x4700, 0x4780):      # bx / blx Rm
                rm = (hw >> 3) & 0xF
                ent = _consumer_of(by_off.get(pooled.get(rm)))
                if ent is not None and ent[1] in holds:
                    return ent, j
                return None
            if (hw & 0xF800) == 0xE000:                 # b, unconditional
                disp = hw & 0x7FF
                j = j + 4 + ((disp - 0x800 if disp & 0x400 else disp) << 1)
                if not 0 <= j < len(fb.data):
                    return None
                continue
            dest = _thumb_dest(hw)
        else:
            w = struct.unpack_from("<I", fb.data, j)[0]
            if (w & 0x0FFFFFD0) == 0x012FFF10:         # bx / blx Rm
                rm = w & 0xF
                ent = _consumer_of(by_off.get(pooled.get(rm)))
                if ent is not None and ent[1] in holds:
                    return ent, j
                return None
            if (w & 0xFF000000) == 0xEA000000:         # b, unconditional
                disp = w & 0xFFFFFF
                if disp & 0x800000:
                    disp -= 0x1000000
                j = j + 8 + (disp << 2)
                if not 0 <= j < len(fb.data):
                    return None
                continue
            dest = _arm_dest(w)
        if dest is None:
            return None
        if dest != _NO_DEST:
            if _copy_source(fb, j) in holds:
                holds.add(dest)
            else:
                holds.discard(dest)
                if not holds:
                    return None
            load = _pc_load(fb, j)
            if load is not None:
                pooled[dest] = load[1]
            else:
                pooled.pop(dest, None)
        j += step
    return None


def attest_overlay_id(fb, st, value, sites, place):
    """The `overlay_id` class for ABS32 data site `st`.

    `value` is the word the declaration says goes there, `sites` every
    relocation site of `fb` after the other classes have run, and `place`
    the address `fb` is compared at.  Returns (class, 1, load address).
    """
    # (1) a valid overlay index in the layout
    if value not in overlay_ids():
        return None
    by_off = dict((s.off, s) for s in sites)
    step = 2 if fb.thumb else 4
    for j in range(0, len(fb.data) - step + 1, step):
        if j in by_off:
            continue
        load = _pc_load(fb, j)
        # (2) a pc-relative load in the function addresses exactly the site
        if load is None or load[1] != st.off:
            continue
        # (3) the loaded register reaches a consumer's id parameter
        found = _walk_to_consumer(fb, j + load[2], load[0], by_off)
        if found is not None:
            ent, call = found
            st.note = ("overlay %d, loaded into r%d at %08X, id argument of "
                       "%s at %08X" % (value, load[0], place + j, ent[0],
                                       place + call))
            return "overlay_id", 1, place + j
    return None


# ---------------------------------------------------------------------------
# vendor-object rules: `linker`, `template` and section-relative .bss
# ---------------------------------------------------------------------------
#
# Three kinds of relocation target have no witness any address-based class
# can give, because nothing in the image names them from outside the
# compared range: a linker-defined absolute (SDK_OVERLAY_NUMBER is 0xED, not
# a location), a compiler-generated initializer template (`@12151`, a local
# with no name a `symbols:` line could share with our compile), and a
# relocation against a section symbol (`.bss`+0 in os_spinlock.o).  All
# three occur in SDK functions whose vendor object is in sdk/, and the vendor
# object states what the relocated word IS.  The rules below accept a site
# only when two independent sources agree: the vendor object says which
# symbol the word at this slot is, and the image or the layout proves the
# value.  A value match alone never passes.
#
# Common precondition (vendor_function()): the function under test has
# exactly one layout/symbols_sdk.json row at `place` in the ARM9 static
# region, and tools/sdkobj.py's locate() finds that row's member with ZERO
# concrete mismatches against the image (every byte outside the member's own
# relocation fields agrees).  That is what makes the member's relocation
# table a statement about the image rather than about some other build.  The
# member's relocation at the site's offset must be the same type (ABS32) as
# ours.
#
#   linker    (attest_linker())  the member relocates the slot against an
#             UNDEFINED symbol X (shndx 0) whose name is our relocation's
#             name, spelled SDK_[A-Z0-9_]+, with addend 0 on both sides, and
#             X is defined in no member of the member's archive (so only the
#             linker can supply it).  The value must then be proven one of
#             two ways, never by the word under comparison:
#               (a) LINKER_LAYOUT names X and its derivation from
#                   layout/layout.json equals the declared value (a
#                   derivation that disagrees refuses outright, (b) is not
#                   tried);
#               (b) another SDK row of the same archive, also located with
#                   zero mismatches, relocates X (ABS32, addend 0) at a slot
#                   outside the compared range, and the image word there
#                   equals the declared value; every such slot has to agree,
#                   one disagreeing slot refuses.
#   template  (attest_template())  the member relocates the slot against a
#             LOCAL data object named `@N` (the compiler's anonymous
#             initializer), of size S > 0 in a PROGBITS section, with no
#             relocation inside it, addend 0 on both sides.  The source
#             names the address with a `symbols:` line whose name is the
#             member's `@N` (the only stable spelling; our own compile's
#             `@M` number differs).  Accepted when the S template bytes
#             contain a non-zero byte, the declared address is aligned to
#             the template section's alignment and lies in an ARM9 static
#             data section, the image holds exactly those S bytes there, the
#             byte pattern occurs at no other aligned address of the ARM9
#             static module, and our compile's own `@M` object (when the
#             compiled object is at hand) has the same S bytes.
#
#             OVERLAYS (2026-09-29).  This rule, and only this one, also
#             runs for an SDK row whose region is an overlay: the row is
#             looked up in the region the code is compared in (never guessed
#             from the address, since overlays share windows) and located
#             with 0 mismatches as above.  The template's module is then
#             that overlay (a member's local `@N` is linked with its code):
#             the declared address must be in that overlay's image and be
#             data in its listing (in_overlay_data()), and uniqueness is
#             over that overlay's aligned addresses.  `linker` and `.bss`
#             stay ARM9-only.
#
#             PRONG (b), ELIMINATION.  When the pattern occurs at more than
#             one aligned address of the module (dwc_encsession.o holds two
#             byte-identical 17-byte `hextbl` templates, @16077 and
#             @16117), the site is still accepted when every OTHER
#             occurrence is claimed by a different template: a row of the
#             same archive in the same region, located with 0 mismatches,
#             relocates (ABS32, addend 0) a local `@K` with the same bytes,
#             in a PROGBITS section without SHF_MERGE, at a slot outside the
#             compared range, and the image word at that slot is that
#             occurrence.  Distinct local objects in non-merge sections
#             occupy disjoint storage, so the remaining occurrence is the
#             only one `@N` can be.  Refused when any claim word is not an
#             occurrence, another template claims the declared address, two
#             templates claim one address, a claim of `@N` itself points
#             elsewhere, or any occurrence stays unclaimed.
#   .bss      (attest_section_rel())  a `symbols:` line may name `.bss`
#             (the section symbol mwccarm writes for a function-local
#             static) with the address of the object's .bss base.  Accepted
#             only when the member relocates the slot against its own .bss
#             section symbol with the same addend we do, the member's whole
#             .bss placed at that base lies in the ARM9 static module's .bss
#             (layout.json static bss_start..bss_end), the base is aligned to
#             the member's .bss alignment, and the ordinary attest() still
#             finds a witness for base+addend.  This rule adds no evidence of
#             its own: it only lets a section-relative relocation be named;
#             the witness is whatever class attest() reports.  (The exact
#             placement of one member's .bss is not in any file we have; the
#             static module's .bss range is the bound the layout gives.)

LINKER_NAME_RE = re.compile(r"^SDK_[A-Z0-9_]+$")
ANON_NAME_RE = re.compile(r"^@[0-9]+$")
SECTION_NAMES = (".bss",)

_VENDOR = {}


def _layout_json():
    if "layout" not in _VENDOR:
        with open(os.path.join(ROOT, "layout", "layout.json")) as fh:
            _VENDOR["layout"] = json.load(fh)
    return _VENDOR["layout"]


def _overlay_number(lay):
    n = (lay.get("counts") or {}).get("overlays")
    if not isinstance(n, int) or n != len(lay.get("overlays") or []):
        return None             # the two layout statements must agree
    return n


# X -> (derivation from layout.json, how it is derived).  Only symbols whose
# value is by definition a layout figure.
LINKER_LAYOUT = {
    # the number of entries in the y9 overlay table
    "SDK_OVERLAY_NUMBER": (_overlay_number,
                           "layout.json counts.overlays (= len(overlays))"),
    # the TWL-only main-memory autoload block of arm9i.bin, which layout.json
    # carries as region `twl`
    "SDK_LTDAUTOLOAD_LTDMAIN_START": (
        lambda lay: (lay.get("twl") or {}).get("ram_start"),
        "layout.json twl.ram_start"),
    "SDK_LTDAUTOLOAD_LTDMAIN_BSS_END": (
        lambda lay: (lay.get("twl") or {}).get("bss_end"),
        "layout.json twl.bss_end"),
}


def _sdkobj():
    if "mod" not in _VENDOR:
        import sdkobj           # noqa: E402  (tools/ is already on sys.path)
        _VENDOR["mod"] = sdkobj
    return _VENDOR["mod"]


OVERLAY_NAME_RE = re.compile(r"^ov[0-9]{3}$")


def _vendor_region(place, region, overlays=False):
    """The region the vendor rules may run in for a function at `place`:
    'arm9', or (only when `overlays` is set, which the `template` rule alone
    does) the overlay `region` names, when that overlay's image holds
    `place`.  An overlay is never guessed from the address: overlays share
    RAM windows, so only the region the code is compared in can say which
    one is meant."""
    if overlays and region is not None and OVERLAY_NAME_RE.match(region):
        r = _overlay_region(region)
        if r is None or not r.base <= place < r.base + len(r.data):
            return None
        return region
    if region not in (None, "arm9"):
        return None
    r = _region_at(place)
    if r is None or r.name != "arm9":
        return None
    return "arm9"


def vendor_function(place, region=None, overlays=False):
    """The vendor member of the SDK row at `place`, located with 0 mismatches.

    Returns a dict (row, archive, view, sym, relocs {off: (rtype, symidx,
    addend)}) or None.  None whenever the row is missing or ambiguous, or the
    member disagrees with the image anywhere outside its relocation fields.
    `overlays` admits an overlay row (see _vendor_region()); only the
    `template` rule passes it.
    """
    reg = _vendor_region(place, region, overlays)
    if reg is None:
        return None
    key = ("fn", reg, place)
    if key in _VENDOR:
        return _VENDOR[key]
    so = _sdkobj()
    out = None
    rows = [r for r in so.sdk_table()
            if r["address"] == place and r["region"] == reg]
    if len(rows) == 1:
        try:
            got, _tried = so.locate(rows[0])
        except Exception:           # an unreadable archive refuses
            got = None
        if got is not None and got[7] == 0:
            arch, view, sym, _body, _mask, rels, _thumb, _mis = got
            out = {"row": rows[0], "archive": arch, "view": view, "sym": sym,
                   "relocs": {off: (rt, si, add) for off, rt, si, add in rels}}
    _VENDOR[key] = out
    return out


def _vendor_site(vf, off, rtype):
    """(symbol tuple, addend) of the member's relocation at `off`, or None."""
    if vf is None:
        return None
    got = vf["relocs"].get(off)
    if got is None or got[0] != rtype:
        return None
    _rt, si, add = got
    syms = vf["view"].syms
    if si >= len(syms):
        return None
    return syms[si], (add or 0)


def vf_member_name(place, region=None, overlays=False):
    vf = vendor_function(place, region, overlays)
    if vf is None:
        return "?"
    return "%s(%s)" % (os.path.basename(vf["archive"]), vf["row"]["object"])


def _archive_defines(archive, name):
    """True when any member of `archive` defines `name` (shndx != 0)."""
    key = ("def", archive)
    if key not in _VENDOR:
        so = _sdkobj()
        from libmatch import read_archive  # noqa: E402
        defined = set()
        if archive.endswith(".o"):
            with open(archive, "rb") as fh:
                members = [(os.path.basename(archive), fh.read())]
        else:
            members = list(read_archive(archive))
        for n, b in members:
            o = Obj(n, b)
            if not o.ok:
                continue
            for s in so.ObjView(o).syms:
                if s[5] != 0 and s[0]:
                    defined.add(s[0])
        _VENDOR[key] = defined
    return name in _VENDOR[key]


def _image_word(addr):
    r = _region_at(addr)
    if r is None:
        return None
    off = addr - r.base
    if off < 0 or off + 4 > len(r.data):
        return None
    return struct.unpack_from("<I", r.data, off)[0]


def _region_word(reg_name, addr):
    """The image word at `addr` in the named region (an overlay's own bytes,
    never whichever region happens to hold the address first)."""
    r = _overlay_region(reg_name)
    if r is None:
        return None
    off = addr - r.base
    if off < 0 or off + 4 > len(r.data):
        return None
    return struct.unpack_from("<I", r.data, off)[0]


def _linker_sites(vf, name):
    """[(site addr, image word)] where another ARM9 row of vf's archive
    relocates `name` (ABS32, undefined, addend 0); each such row is located
    with 0 mismatches by vendor_function()."""
    key = ("lsites", vf["archive"], name)
    if key in _VENDOR:
        return _VENDOR[key]
    so = _sdkobj()
    lib = vf["row"]["lib"]
    out = []
    for row in so.sdk_table():
        if row["region"] != "arm9" or row["lib"] != lib:
            continue
        if row["address"] == vf["row"]["address"]:
            continue
        other = vendor_function(row["address"], "arm9")
        if other is None or other["archive"] != vf["archive"]:
            continue
        syms = other["view"].syms
        for off, (rt, si, add) in sorted(other["relocs"].items()):
            if rt != R_ARM_ABS32 or (add or 0) != 0 or si >= len(syms):
                continue
            s = syms[si]
            if s[0] != name or s[5] != 0:
                continue
            site = row["address"] + off
            out.append((site, _image_word(site)))
    _VENDOR[key] = out
    return out


def attest_linker(place, off, name, value, addend, lo, hi, region=None):
    """The `linker` class.  (class, witnesses, site, note) or None.

    `place` is where the function under test is compared, `off` the site's
    offset in it, `name` our relocation's symbol, `value` the word the
    declaration would write there.  See the commentary above.
    """
    if not LINKER_NAME_RE.match(name or "") or addend != 0:
        return None
    vf = vendor_function(place, region)
    got = _vendor_site(vf, off, R_ARM_ABS32)
    if got is None:
        return None
    sym, vadd = got
    if sym[0] != name or sym[5] != 0 or vadd != 0:
        return None
    if _archive_defines(vf["archive"], name):
        return None
    member = vf_member_name(place, region)
    derive = LINKER_LAYOUT.get(name)
    if derive is not None:
        want = derive[0](_layout_json())
        if want is None or want != value:
            return None
        return ("linker", 1, value,
                "%s is undefined in %s; value = %s" % (name, member, derive[1]))
    sites = [(s, w) for s, w in _linker_sites(vf, name) if not lo <= s < hi]
    if not sites or any(w != value for _s, w in sites):
        return None
    return ("linker", len(sites), sites[0][0],
            "%s is undefined in %s; the archive's other located rows relocate "
            "it at slots holding this value" % (name, member))


def vendor_template(place, off, region=None):
    """(member's @N name, template bytes, alignment) for the slot, or None.

    The one vendor rule that also runs in an overlay (see attest_template())."""
    vf = vendor_function(place, region, overlays=True)
    got = _vendor_site(vf, off, R_ARM_ABS32)
    if got is None:
        return None
    sym, vadd = got
    name, val, size, typ, bind, shndx = sym
    if (not ANON_NAME_RE.match(name or "") or vadd != 0 or typ != 1
            or bind != 0 or size <= 0 or shndx == 0):
        return None
    obj = vf["view"].obj
    if shndx >= len(obj.sections) or obj.sections[shndx][1] != SHT_PROGBITS:
        return None
    for roff, _rt, _si, _add in vf["view"].relocs.get(shndx, ()):
        if val <= roff < val + size:
            return None             # a template with relocations: refuse
    body = bytes(obj.section_data(shndx)[val:val + size])
    if len(body) != size:
        return None
    return name, body, obj.sections[shndx][8] or 1


def _template_hits(pattern, align, addr, region=None):
    """Every `align`-aligned address of the ARM9 static module (or, with an
    overlay `region`, of that overlay's image) holding `pattern`."""
    r = _template_region(addr, region)
    if r is None:
        return []
    data = bytes(r.data)
    seen = []
    i = data.find(pattern)
    while i >= 0:
        if (r.base + i) % align == 0:
            seen.append(r.base + i)
        i = data.find(pattern, i + 1)
    return seen


def _template_unique(pattern, align, addr, region=None):
    """True when `pattern` occurs in the ARM9 static module (or, with an
    overlay `region`, in that overlay's image) at `addr` and at no other
    `align`-aligned address of it."""
    return _template_hits(pattern, align, addr, region) == [addr]


SHF_MERGE = 0x10


def _template_claims(vf, pattern, reg_name, lo, hi):
    """[(template key, image word)] for every slot outside [lo, hi) at which
    a row of vf's archive in region `reg_name`, located with 0 mismatches,
    relocates (ABS32, addend 0) a local `@K` template whose bytes are
    `pattern`.  The key is (archive, object, @K), which names one template:
    a member's `@K` is local, and its section has no SHF_MERGE, so two keys
    are two disjoint objects in the link."""
    key = ("tclaims", vf["archive"], reg_name, pattern, lo, hi)
    if key in _VENDOR:
        return _VENDOR[key]
    so = _sdkobj()
    lib = vf["row"]["lib"]
    out = []
    for row in so.sdk_table():
        if row["region"] != reg_name or row["lib"] != lib:
            continue
        other = vendor_function(row["address"], reg_name, overlays=True)
        if other is None or other["archive"] != vf["archive"]:
            continue
        obj = other["view"].obj
        syms = other["view"].syms
        for off, (rt, si, add) in sorted(other["relocs"].items()):
            site = row["address"] + off
            if rt != R_ARM_ABS32 or (add or 0) != 0 or si >= len(syms):
                continue
            if lo <= site < hi:
                continue
            name, val, size, typ, bind, shndx = syms[si]
            if (not ANON_NAME_RE.match(name or "") or typ != 1 or bind != 0
                    or size != len(pattern) or shndx == 0
                    or shndx >= len(obj.sections)):
                continue
            sec = obj.sections[shndx]
            if sec[1] != SHT_PROGBITS or sec[2] & SHF_MERGE:
                continue
            if bytes(obj.section_data(shndx)[val:val + size]) != pattern:
                continue
            out.append(((other["archive"], row["object"], name),
                        _region_word(reg_name, site)))
    _VENDOR[key] = out
    return out


def _template_by_elimination(vf, name, pattern, hits, addr, reg_name, lo,
                             hi):
    """True when the other aligned occurrences of `pattern` are each claimed
    by a different template of vf's archive, leaving `addr` as the only one
    `name` can be.  See attest_template(), prong (b)."""
    sec = vf["view"].obj.sections
    mine = (vf["archive"], vf["row"]["object"], name)
    claims = _template_claims(vf, pattern, reg_name, lo, hi)
    owner = {}
    for tkey, word in claims:
        if word is None or word not in hits:
            return False            # a slot not at an occurrence: refuse
        if tkey == mine:
            if word != addr:
                return False        # our own template seen elsewhere
            continue
        if word == addr:
            return False            # another template claims our address
        if owner.setdefault(word, tkey) != tkey:
            return False            # two templates at one address
    others = set(hits) - {addr}
    return bool(others) and others == set(owner)


def _template_region(addr, region):
    """The region whose image must hold a template at `addr`: the ARM9
    static module, or the overlay the function under test is compared in
    (a member's local `@N` is linked into the same module as its code).
    None when `addr` is not in that image."""
    if region is not None and OVERLAY_NAME_RE.match(region):
        r = _overlay_region(region)
    else:
        r = _region_at(addr)
        if r is not None and r.name != "arm9":
            r = None
    if r is None or not r.base <= addr < r.base + len(r.data):
        return None
    return r


def attest_template(place, off, addr, addend, ours=None, region=None,
                    lo=None, hi=None):
    """The `template` class.  (class, witnesses, site, note) or None.

    `lo`/`hi` bound the compared range (default: the SDK row's extent);
    prong (b) reads only slots outside it.

    `addr` is the declared address of the member's `@N`; `ours` is our own
    compile's template bytes, or None when the compiled object is not at
    hand (the quick self-test calls it that way).
    """
    if addend != 0:
        return None
    got = vendor_template(place, off, region)
    if got is None:
        return None
    name, body, align = got
    if not any(body):
        return None
    r = _template_region(addr, region)
    if r is None or addr % align:
        return None
    if r.name == "arm9":
        if not in_data_section(addr):
            return None
    elif not in_overlay_data(r.name, addr):
        return None
    o = addr - r.base
    if bytes(r.data[o:o + len(body)]) != body:
        return None
    if ours is not None and bytes(ours) != body:
        return None
    where = "the ARM9 static module" if r.name == "arm9" else r.name
    member = vf_member_name(place, region, True)
    hits = _template_hits(body, align, addr, r.name)
    if hits == [addr]:
        return ("template", 1, addr,
                "%s (%d bytes) of %s: the image holds the member's template "
                "here and nowhere else in %s"
                % (name, len(body), member, where))
    vf = vendor_function(place, region, overlays=True)
    if lo is None or hi is None:
        lo, hi = place, place + vf["row"]["size"]
    if not _template_by_elimination(vf, name, body, hits, addr, r.name,
                                    lo, hi):
        return None
    return ("template", len(hits) - 1, addr,
            "%s (%d bytes) of %s: %d aligned copies in %s; every other copy "
            "is another template of the archive, relocated at a located "
            "row's slot outside this range" % (name, len(body), member,
                                               len(hits), where))


def attest_section_rel(place, off, name, base, addend, lo, hi, src=None,
                       region=None):
    """A section-relative `.bss` target: (attest()'s proof, note) or None.

    `base` is the declared address of the member's .bss start."""
    if name not in SECTION_NAMES:
        return None
    vf = vendor_function(place, region)
    got = _vendor_site(vf, off, R_ARM_ABS32)
    if got is None:
        return None
    sym, vadd = got
    _sname, val, _size, typ, _bind, shndx = sym
    obj = vf["view"].obj
    if (typ != 3 or shndx == 0 or shndx >= len(obj.sections)
            or obj.secnames[shndx] != name or val != 0 or vadd != addend):
        return None
    sec = obj.sections[shndx]
    sec_size, sec_align = sec[5], sec[8] or 1
    if addend < 0 or addend >= max(sec_size, 1) or base % sec_align:
        return None
    static = (_layout_json().get("arm9") or {}).get("static") or {}
    b_lo, b_hi = static.get("bss_start"), static.get("bss_end")
    if not isinstance(b_lo, int) or not isinstance(b_hi, int):
        return None
    if not (b_lo <= base and base + sec_size <= b_hi):
        return None
    # exactly the call the resolver makes for any ABS32 data site, so the
    # witness classes (sole-ref/self included) apply unchanged
    proof = attest(base + addend, "data", lo, hi, src, None, None,
                   place + off, (base + addend) & 0xFFFFFFFF,
                   site_region=region)
    if proof is None:
        return None
    return proof, ("%s+%#x of %s, based at %08X in the ARM9 static .bss"
                   % (name, addend, vf_member_name(place, region), base))


# ---------------------------------------------------------------------------
# relocation resolution
# ---------------------------------------------------------------------------

class Site:
    """One relocation site after an attempt to resolve it."""

    __slots__ = ("off", "rtype", "name", "addend", "resolved", "value",
                 "cls", "witnesses", "witness", "reason", "note", "subkind")

    def __init__(self, off, rtype, name, addend):
        self.off = off
        self.rtype = rtype
        self.name = name
        self.addend = addend
        self.resolved = False
        self.value = None
        self.cls = ""
        self.witnesses = 0
        self.witness = 0
        self.reason = ""
        self.note = ""
        self.subkind = ""       # set only for a "sole-ref" site; see attest()

    def describe(self):
        what = "%s %s" % (RELOC_NAMES.get(self.rtype, "r%d" % self.rtype),
                          self.name)
        if self.resolved:
            return "+%04X %-28s -> %08X  [%s%s%s]" % (
                self.off, what, self.value, self.cls,
                (" x%d, e.g. %08X" % (self.witnesses, self.witness))
                if self.witnesses else "",
                ("; " + self.note) if self.note else "")
        return "+%04X %-28s -> unresolved: %s" % (self.off, what, self.reason)


# Relocation types this resolver knows how to encode.  Anything else is left
# wildcarded rather than guessed at.
R_ARM_PC24, R_ARM_ABS32 = 1, 2
R_ARM_THM_CALL, R_ARM_THM_XPC22 = 10, 16
R_ARM_CALL, R_ARM_JUMP24, R_ARM_THM_JUMP24 = 28, 29, 30

_THUMB_BRANCH = (R_ARM_THM_CALL, R_ARM_THM_XPC22, R_ARM_THM_JUMP24)
_ARM_BRANCH = (R_ARM_PC24, R_ARM_CALL, R_ARM_JUMP24)


def _encode_thumb_branch(data, off, place, target, thumb_target, addend):
    """Write a Thumb BL/BLX pair.  Returns False if it cannot be encoded.

    The ARM ELF ABI result for R_ARM_THM_CALL is X = ((S + A) | T) - P, and
    mwccarm writes A = -4, which is the Thumb PC bias, so X is already the
    displacement the instruction pair encodes: the core computes
    ``target = PC + 4 + D``.  BLX is the one wrinkle: it word-aligns the PC
    before adding, so when the instruction sits at an odd word offset the
    encoded displacement has to be 2 larger to land on the same address.
    That is the ``(P + 4) & 3`` term, and it is what makes this agree with
    the ``blx`` at 0x0200851A in the original.

    Which of BL and BLX is written is decided here rather than by the
    compiler: mwccarm emits a plain BL for every call to an extern, because
    it cannot see the callee's instruction set, and the linker rewrites it
    to BLX when the target turns out to be ARM.  Resolving a relocation
    means doing exactly that rewrite.
    """
    hw2 = struct.unpack_from("<H", data, off + 2)[0]
    if (hw2 & 0xF800) not in (0xF800, 0xE800):
        return False
    disp = (target + addend) - place
    if thumb_target:
        op = 0xF800                     # BL, stays in Thumb
    else:
        op = 0xE800                     # BLX, swaps to ARM
        disp += (place + 4) & 3
        if disp & 3:
            return False                # BLX must reach a word boundary
    if disp < -(1 << 22) or disp >= (1 << 22):
        return False
    struct.pack_into("<HH", data, off,
                     0xF000 | ((disp >> 12) & 0x7FF),
                     op | ((disp >> 1) & 0x7FF))
    return True


def _encode_arm_branch(data, off, place, target, addend, thumb_target=False):
    """Write an ARM B/BL displacement, or a BLX(immediate) into Thumb.

    X = (S + A) - P, field = X >> 2.  The addend mwccarm writes carries the
    ARM PC bias (-8) the same way the Thumb one carries -4, so no further
    bias is applied here.

    Interworking the other way from `_encode_thumb_branch` above: an ARM
    caller's `bl`/`blx` into a Thumb callee is legal and is exactly BLX
    (immediate).  That encoding is unconditional (the top nibble is fixed
    to 1111 rather than carrying a real condition) and steals the low bit
    of the halfword-granular displacement into bit 24 of the instruction
    (`H`), since ARM code is always word-aligned but the Thumb target need
    not be: `target = place + 8 + disp`, `disp = imm32 = H:imm24:'0'`
    sign-extended.  Confirmed against the real site at 0x02091180
    (`blx #0x2004490`, a two-instruction Thumb stub): the formula below
    reproduces the image's 0xFAFDCCC2 exactly.
    """
    word = struct.unpack_from("<I", data, off)[0]
    disp = (target + addend) - place
    if thumb_target:
        if disp & 1 or disp < -(1 << 25) or disp >= (1 << 25):
            return False                # BLX must reach a halfword boundary
        val25 = disp >> 1
        h = val25 & 1
        imm24 = (val25 >> 1) & 0xFFFFFF
        struct.pack_into("<I", data, off, 0xFA000000 | (h << 24) | imm24)
        return True
    if disp & 3 or disp < -(1 << 25) or disp >= (1 << 25):
        return False
    struct.pack_into("<I", data, off,
                     (word & 0xFF000000) | ((disp >> 2) & 0xFFFFFF))
    return True


def _resolve_vendor_named(fb, st, place, decls, lo, hi, src, region):
    """(target, "data") for an `@N` or `.bss` relocation the vendor object
    names, with st's class, witness and note set; None (st.reason set)."""
    name, off, addend = st.name, st.off, st.addend
    if name in SECTION_NAMES:
        d = decls.get(name)
        if d is None:
            st.reason = ("no address for %r: a section-relative target needs "
                         "a `%s 0xADDR data` symbols: line" % (name, name))
            return None
        got = attest_section_rel(place, off, name, d.addr, addend, lo, hi,
                                 src, region)
        if got is None:
            st.reason = ("%s+%#x at %08X: the vendor object does not relocate "
                         "this slot against its own %s with this addend, the "
                         "base is not in the ARM9 static .bss, or no witness "
                         "attests %08X" % (name, addend, d.addr, name,
                                           d.addr + addend))
            return None
        proof, note = got
        st.cls, st.witnesses, st.witness = proof[:3]
        if proof[0] == "sole-ref" and len(proof) > 3:
            st.subkind = proof[3]
        st.note = note
        return d.addr, "data"
    vt = vendor_template(place, off, region)
    if vt is None or vt[0] not in decls:
        st.reason = ("no address for %r: a compiler template is named by the "
                     "vendor object's own @N at this slot (%s), which the "
                     "symbols: block does not declare"
                     % (name, vt[0] if vt else "no vendor template here"))
        return None
    d = decls[vt[0]]
    proof = attest_template(place, off, d.addr, addend,
                            getattr(fb, "anon", {}).get(name), region, lo, hi)
    if proof is None:
        st.reason = ("%s declared at %08X: the image does not hold the "
                     "vendor template there uniquely, or our template "
                     "differs" % (vt[0], d.addr))
        return None
    st.cls, st.witnesses, st.witness = proof[:3]
    st.note = proof[3]
    return d.addr, d.kind


def resolve_relocations(fb, place, decls, size=None, src=None, region=None):
    """Fill in every relocation of `fb` whose target we can attest.

    `place` is the address the code is being compared at, so a site at
    offset o would be linked at place + o.  Sites that resolve have their
    mask bytes turned back on, so the byte comparison covers them; sites
    that do not keep their wildcards and record why.  `src` is the source
    file under test, in manifest spelling: the `matched` class needs it to
    refuse an entry that would witness its own file.  `region` is the region
    the code is compared in, which the overlay rules of `matched` and
    `sole-ref` read; None keeps every rule to its pre-overlay behaviour.
    """
    data = bytearray(fb.data)
    mask = bytearray(fb.mask)
    lo, hi = place, place + (size if size is not None else len(fb.data))
    sites = []
    ovid_later = []
    self_later = []
    for off, rtype, name, addend in fb.relocs:
        st = Site(off, rtype, name, addend)
        sites.append(st)
        place_at = place + off

        if name in fb.locals:
            target = place + fb.locals[name]
            kind = "thumb" if fb.thumb else "arm"
            st.cls = "local"
        elif ANON_NAME_RE.match(name) or name in SECTION_NAMES:
            # A compiler template or a section symbol: only the vendor
            # object can say what the slot is (see "vendor-object rules").
            got = _resolve_vendor_named(fb, st, place, decls, lo, hi, src,
                                        region)
            if got is None:
                continue
            target, kind = got
            if kind != "data" or rtype != R_ARM_ABS32:
                st.reason = "%s: only an ABS32 data site is named this way" % name
                continue
        else:
            info = symbol_address(name, decls)
            if info is None:
                st.reason = ("no address for %r: not in the symbols: block, "
                             "not an address-bearing name, not in "
                             "layout/symbols_sdk.json" % name)
                continue
            target, kind, origin = info
            if rtype in _THUMB_BRANCH or rtype in _ARM_BRANCH:
                # The declared ISA picks BL against BLX, so a wrong tag
                # resolves to the wrong instruction rather than failing to
                # resolve.  Cross-check it against the image before encoding.
                found = isa_evidence(
                    target, region,
                    decls[name].region if name in decls else None)
                if (found is None and name in decls
                        and decls[name].region == OV230D_REGION):
                    # the decrypted ov230 listing answers only for a site
                    # that names it (see "decrypted ov230" above)
                    th = ov230d_label(target)
                    if th is not None:
                        found = (("thumb" if th else "arm"),
                                 "the func_%08X label in asm/ov230d" % target)
                if found is not None and found[0] != kind:
                    raise SystemExit(
                        "ISA conflict for %s at %08X: the source declares "
                        "%s, the image says %s (%s).  Fix the symbols: block "
                        "(address from %s); refusing to resolve the call at "
                        "+%04X." % (name, target, kind, found[0], found[1],
                                    origin, off))
                if found is None:
                    st.note = "declared %s, no image evidence for the ISA" % kind
            region_hint = decls[name].region if name in decls else None
            align = decls[name].align if name in decls else None
            # For an ABS32 data site, the word this resolution is about to
            # write is fully determined here; `sole-ref/self` needs it, and
            # the site's link-time address, to check that the original image
            # already names the same address at the same place.
            self_site = self_expect = None
            if rtype == R_ARM_ABS32 and kind == "data":
                self_site = place_at
                self_expect = (target + addend) & 0xFFFFFFFF
            proof = attest(target, kind, lo, hi, src, region_hint, align,
                           self_site, self_expect, site_region=region)
            if proof is None and rtype == R_ARM_ABS32 and kind == "data":
                # A linker-defined absolute the vendor object names at this
                # slot (see "vendor-object rules").
                lk = attest_linker(place, off, name,
                                   (target + addend) & 0xFFFFFFFF, addend,
                                   lo, hi, region)
                if lk is not None:
                    proof = lk[:3]
                    st.note = lk[3]
            if proof is None and rtype == R_ARM_ABS32 and kind == "data":
                # Retried as `overlay_id` once every other site is known.
                ovid_later.append((st, (target + addend) & 0xFFFFFFFF))
            if proof is None:
                st.reason = ("%08X (%s, from %s) has no witness outside "
                             "%08X..%08X" % (target, kind, origin, lo, hi))
                if kind in ("thumb", "arm"):
                    cands = overlay_candidates(target)
                    if len(cands) > 1:
                        st.reason += (
                            "; %d overlays overlap this address (%s), none "
                            "resolvable without a region hint on the "
                            "symbols: line" % (len(cands), ", ".join(cands)))
                    elif cands and region_hint is None:
                        st.reason += ("; %s overlaps this address but has "
                                      "no func_ label there" % cands[0])
                continue
            if (proof[0] == "sole-ref" and len(proof) > 3
                    and proof[3] == "self" and region_hint is not None
                    and not _is_arm9_address(target)
                    and _hint_contested(target, region_hint)):
                # Decided after the `overlay_id` pass: self_hint_accepted().
                self_later.append((st, proof, region_hint,
                                   (target + addend) & 0xFFFFFFFF))
                st.reason = ("%08X: the %s hint is contested (another overlay "
                             "in the window starts an object there) and this "
                             "function loads no overlay %s through an "
                             "overlay_id site" % (target, region_hint,
                                                  region_hint))
                continue
            st.cls, st.witnesses, st.witness = proof[:3]
            if st.cls == "sole-ref" and len(proof) > 3:
                st.subkind = proof[3]

        ok = False
        if rtype == R_ARM_ABS32:
            val = (target + addend) & 0xFFFFFFFF
            if kind == "thumb":
                val |= 1            # ((S + A) | T), the interworking bit
            struct.pack_into("<I", data, off, val)
            st.value = val
            ok = True
        elif rtype in _THUMB_BRANCH:
            ok = _encode_thumb_branch(data, off, place_at, target,
                                      kind == "thumb", addend)
            st.value = target
        elif rtype in _ARM_BRANCH:
            ok = _encode_arm_branch(data, off, place_at, target, addend,
                                    thumb_target=(kind == "thumb"))
            st.value = target
        else:
            st.reason = "relocation type %d is not implemented" % rtype
            continue
        if not ok:
            st.reason = "cannot encode a %s to %08X here" % (
                RELOC_NAMES.get(rtype, "r%d" % rtype), target)
            continue

        st.resolved = True
        width = RELOC_MASK.get(rtype, RELOC_DEFAULT)[1]
        for k in range(off, min(off + width, len(mask))):
            mask[k] = 1

    # The `overlay_id` class reads the function's other sites (the loader
    # call has to have resolved on its own), so it runs after all of them.
    for st, val in ovid_later:
        proof = attest_overlay_id(fb, st, val, sites, place)
        if proof is None:
            continue
        st.cls, st.witnesses, st.witness = proof
        st.reason = ""
        struct.pack_into("<I", data, st.off, val)
        st.value = val
        st.resolved = True
        width = RELOC_MASK.get(R_ARM_ABS32, RELOC_DEFAULT)[1]
        for k in range(st.off, min(st.off + width, len(mask))):
            mask[k] = 1

    # A contested overlay hint on a sole-ref/self site stands only when this
    # function loads the hinted overlay (self_hint_accepted()).
    loaded = set(s.value for s in sites
                 if s.resolved and s.cls == "overlay_id")
    for st, proof, hint, val in self_later:
        if not self_hint_accepted(proof[2], hint, loaded):
            continue
        st.cls, st.witnesses, st.witness = proof[:3]
        st.subkind = proof[3]
        st.reason = ""
        st.note = "%s hint: this function loads %s (overlay_id)" % (hint, hint)
        struct.pack_into("<I", data, st.off, val)
        st.value = val
        st.resolved = True
        width = RELOC_MASK.get(R_ARM_ABS32, RELOC_DEFAULT)[1]
        for k in range(st.off, min(st.off + width, len(mask))):
            mask[k] = 1

    fb.data = bytes(data)
    fb.mask = mask
    fb.sites = sites
    return sites


# ---------------------------------------------------------------------------
# comparison
# ---------------------------------------------------------------------------

class Result:
    __slots__ = ("status", "size", "target_size", "diffs", "note", "log",
                 "func", "target", "region")

    def __init__(self, status, note="", log=""):
        self.status = status
        self.note = note
        self.log = log
        self.size = 0
        self.target_size = None
        self.diffs = []
        self.func = None
        self.target = b""
        self.region = ""


def compare(fb, tgt):
    """EXACT / MATCH / DIFF plus the list of differing offsets.

    A byte outside `fb.mask` is a relocation field that stayed wildcarded
    because `resolve_relocations()` could not attest its target (see the
    verdicts table at the top of this file).  Literal byte equality there
    is not evidence of anything: the compiler's own unresolved guess can
    coincide with the image by simple adjacency (a PC24 branch to the
    address right past the function's own extent, say) without the target
    ever having been independently witnessed.  EXACT therefore requires
    every byte to be both hard (`fb.mask` all 1) and equal; a wildcarded
    byte that happens to match still only earns MATCH.
    """
    if len(fb.data) != len(tgt):
        return "SIZE", []
    hard = [i for i in range(len(tgt)) if fb.mask[i] and fb.data[i] != tgt[i]]
    if hard:
        return "DIFF", hard
    if fb.data == tgt and all(fb.mask):
        return "EXACT", []
    return "MATCH", []


# ---------------------------------------------------------------------------
# display
# ---------------------------------------------------------------------------

def disasm(data, base, thumb):
    """[(addr, size, text)] via capstone, or a hex fallback."""
    try:
        import capstone
    except ImportError:
        step = 2 if thumb else 4
        return [(base + i, step, data[i:i + step].hex(" "))
                for i in range(0, len(data) - step + 1, step)]
    md = capstone.Cs(capstone.CS_ARCH_ARM,
                     (capstone.CS_MODE_THUMB if thumb else capstone.CS_MODE_ARM)
                     | capstone.CS_MODE_LITTLE_ENDIAN)
    out = []
    for ins in md.disasm(data, base):
        out.append((ins.address, ins.size,
                    ("%s %s" % (ins.mnemonic, ins.op_str)).strip()))
    consumed = sum(s for _a, s, _t in out)
    if consumed < len(data):
        out.append((base + consumed, len(data) - consumed,
                    ".byte " + data[consumed:].hex(" ")))
    return out


def print_diff(fb, tgt, addr, relmap):
    """Two-column instruction listing, original on the left."""
    left = disasm(tgt, addr, fb.thumb)
    right = disasm(fb.data, addr, fb.thumb)
    by_off_l = {a - addr: (s, t) for a, s, t in left}
    by_off_r = {a - addr: (s, t) for a, s, t in right}
    offs = sorted(set(by_off_l) | set(by_off_r))
    print("  %-10s %-38s | %-38s" % ("offset", "ORIGINAL @ %08X" % addr, "COMPILED"))
    print("  " + "-" * 90)
    for off in offs:
        ls, lt = by_off_l.get(off, (0, ""))
        rs, rt = by_off_r.get(off, (0, ""))
        n = max(ls, rs, 1)
        lb = tgt[off:off + n]
        rb = fb.data[off:off + n]
        wild = any(off + k < len(fb.mask) and not fb.mask[off + k] for k in range(n))
        if lb == rb:
            flag = " "
        elif wild:
            flag = "~"
        else:
            flag = "*"
        rel = relmap.get(off, "")
        print("  %s +%04X    %-38s | %-38s %s"
              % (flag, off, lt or lb.hex(" "), rt or rb.hex(" "), rel))
    print("  legend: '*' concrete mismatch, '~' relocation field (wildcarded)")


RELOC_NAMES = {1: "PC24", 2: "ABS32", 3: "REL32", 10: "THM_CALL", 15: "XPC25",
               16: "THM_XPC22", 28: "CALL", 29: "JUMP24", 30: "THM_JUMP24"}


def print_sites(fb, indent="  "):
    """Per-site relocation report: what resolved, on what evidence."""
    if not fb.sites:
        return
    nres = sum(1 for s in fb.sites if s.resolved)
    print("%srelocations: %d of %d resolved"
          % (indent, nres, len(fb.sites)))
    for s in fb.sites:
        print("%s  %s" % (indent, s.describe()))


def reloc_map(fb):
    by_off = {s.off: s for s in fb.sites}
    out = {}
    for off, t, s, _a in fb.relocs:
        tag = "<- %s %s" % (RELOC_NAMES.get(t, "r%d" % t), s)
        st = by_off.get(off)
        if st is not None:
            tag += " [resolved: %s]" % st.cls if st.resolved else " [wildcard]"
        out[off] = tag
    return out


# ---------------------------------------------------------------------------
# one run
# ---------------------------------------------------------------------------

def run_one(src, func, addr, version, flags, thumb, lang, region=None,
            keep=False, sdk_include=True):
    work = tempfile.mkdtemp(prefix="bwmatch_")
    try:
        obj, cmd, log, rc = compile_tu(src, version, flags, thumb, lang, work,
                                       sdk_include=sdk_include)
        if obj is None:
            r = Result("CCERR", note=first_line(log), log=log)
            return r
        fb = extract_function(obj, func, prefer_thumb=thumb)
        reg = find_region(addr, region)
        tsize, tthumb = target_extent(addr, reg.name)
        n = len(fb.data)
        resolve_relocations(fb, addr, declared_symbols(read_header(src)),
                            src=source_key(src), region=reg.name)
        rname, tgt = target_bytes(addr, n, region=reg.name)
        status, diffs = compare(fb, tgt)
        r = Result(status, log=log)
        r.func = fb
        r.target = tgt
        r.region = rname
        r.size = n
        r.target_size = tsize
        r.diffs = diffs
        if tsize is not None and tsize != n:
            r.note = "listing says the original is %d bytes, compiled %d" % (tsize, n)
            if status in ("EXACT", "MATCH"):
                r.status = status + "*"
        if tthumb is not None and tthumb != fb.thumb:
            r.note = (r.note + "; " if r.note else "") + \
                "ISA mismatch: original is %s, compiled %s" % (
                    "Thumb" if tthumb else "ARM", "Thumb" if fb.thumb else "ARM")
            r.status = "ISA"
        return r
    finally:
        if keep:
            print("  kept %s" % work)
        else:
            shutil.rmtree(work, ignore_errors=True)


def first_line(text):
    for line in text.replace("\r", "").split("\n"):
        line = line.strip()
        if line and ("error" in line.lower() or "fatal" in line.lower()):
            return line[:200]
    for line in text.replace("\r", "").split("\n"):
        if line.strip():
            return line.strip()[:200]
    return ""


# ---------------------------------------------------------------------------
# commands
# ---------------------------------------------------------------------------

def parse_addr(s):
    return int(s, 0)


def resolve_isa(addr, region, args):
    if args.thumb:
        return True
    if args.arm:
        return False
    reg = find_region(addr, region)
    _sz, th = target_extent(addr, reg.name)
    if th is not None:
        return th
    # Fall back to the SDK symbol table, which records the ISA per symbol.
    p = os.path.join(ROOT, "layout", "symbols_sdk.json")
    if os.path.exists(p):
        with open(p) as fh:
            for e in json.load(fh)["symbols"]:
                if e["address"] == addr:
                    return bool(e["thumb"])
    return False


def cmd_one(args):
    addr = parse_addr(args.addr)
    thumb = resolve_isa(addr, args.region, args)
    flags = args.flags.split() if args.flags else ["-O4,p"]
    r = run_one(args.src, args.func, addr, args.cc, flags, thumb, args.lang,
                region=args.region, keep=args.keep,
                sdk_include=not args.no_sdk_include)
    print("%-10s %s @ %08X (%s, %s)"
          % (r.status, args.func, addr, r.region or args.region or "?",
             "Thumb" if thumb else "ARM"))
    print("  compiler dsi/%s  flags: %s%s%s"
          % (args.cc, " ".join(BASE_FLAGS + flags),
             " -thumb" if thumb else "",
             (" -lang " + args.lang) if args.lang else ""))
    if r.status == "CCERR":
        print(r.log)
        return 2
    print("  compiled %d bytes, %d relocation site(s)"
          % (r.size, len(r.func.relocs)))
    print_sites(r.func)
    if r.target_size is not None:
        print("  listing extent for the original: %d bytes" % r.target_size)
    if r.note:
        print("  note: %s" % r.note)
    if r.status.startswith("EXACT") or r.status.startswith("MATCH"):
        if args.diff:
            print_diff(r.func, r.target, addr, reloc_map(r.func))
        return 0
    print("  %d concrete byte(s) differ" % len(r.diffs))
    print_diff(r.func, r.target, addr, reloc_map(r.func))
    return 1


def cmd_sweep(args):
    addr = parse_addr(args.addr)
    thumb = resolve_isa(addr, args.region, args)
    versions = args.cc.split(",") if args.cc else all_versions()
    opts = list(SWEEP_OPTS)
    if args.extra:
        opts += SWEEP_EXTRA
    langs = [args.lang or ("c99" if not args.cpp else "c++")]
    if args.cpp:
        langs = ["c99", "c++"]

    print("sweep %s @ %08X  (%s)  src=%s"
          % (args.func, addr, "Thumb" if thumb else "ARM",
             os.path.relpath(args.src, ROOT).replace("\\", "/")))
    rows = []
    best = []
    for lang in langs:
        header = "  %-9s" % ("lang " + lang) + "".join(
            "%-12s" % " ".join(o) for o in opts)
        print(header)
        for v in versions:
            cells = []
            for o in opts:
                r = run_one(args.src, args.func, addr, v, o, thumb, lang,
                            region=args.region,
                            sdk_include=not args.no_sdk_include)
                cell = r.status
                if r.status == "DIFF":
                    cell = "D%d" % len(r.diffs)
                elif r.status == "SIZE":
                    cell = "S%+d" % (r.size - (r.target_size or r.size))
                    if r.target_size is None:
                        cell = "S%d" % r.size
                elif r.status == "CCERR":
                    cell = "err"
                cells.append(cell)
                rows.append({"cc": v, "lang": lang, "flags": " ".join(o),
                             "status": r.status, "diffs": len(r.diffs),
                             "size": r.size, "note": r.note})
                if r.status.startswith(("EXACT", "MATCH")):
                    best.append((v, lang, " ".join(o), r.status))
            print("  %-9s" % v + "".join("%-12s" % c for c in cells))
    print()
    if best:
        print("matching configurations (%d):" % len(best))
        for v, lang, o, st in best:
            print("  %-8s  lang %-4s  %-22s  %s" % (v, lang, o, st))
    else:
        print("no configuration matched; closest:")
        rows.sort(key=lambda r: (r["status"] != "DIFF", r["diffs"] or 10 ** 6))
        for r in rows[:6]:
            print("  %-8s  lang %-4s  %-22s  %s (%d concrete diffs, %d bytes)"
                  % (r["cc"], r["lang"], r["flags"], r["status"],
                     r["diffs"], r["size"]))
    if args.json:
        with open(args.json, "w", newline="\n") as fh:
            json.dump({"func": args.func, "address": addr, "thumb": thumb,
                       "src": os.path.relpath(args.src, ROOT).replace("\\", "/"),
                       "results": rows}, fh, indent=1)
        print("\nwrote %s" % args.json)
    return 0 if best else 1


# ---------------------------------------------------------------------------
# whole translation units
# ---------------------------------------------------------------------------

SHF_EXECINSTR = 0x4

# The linker fills the gap between two code sections with zero bytes.  This is
# not an assumption: it is what the original image shows at 0x0200854A and
# 0x0200857A, and a TU comparison that reproduced everything except the fill
# would come out DIFF rather than EXACT.
SECTION_FILL = 0x00


class TULayout:
    """Every code section of one object, concatenated the way a linker would.

    CodeWarrior emits one PROGBITS section per function, in source order, each
    with its own alignment (4 for Thumb and ARM alike).  So the byte image of a
    translation unit is not something the compiler hands over directly: it is
    the sections laid end to end, each aligned up, with the gaps filled.  That
    is what this builds, so that a whole source file can be compared against a
    byte range of the original the same way one function is.
    """

    __slots__ = ("data", "mask", "parts", "relocs", "locals")

    def __init__(self, data, mask, parts, relocs, locals_=None):
        self.data = data        # bytes, the laid-out image
        self.mask = mask        # bytearray, 1 = concrete
        self.parts = parts      # [(offset, size, pad_before, [names])]
        self.relocs = relocs    # [(offset, type, symbol, addend)]
        self.locals = locals_ or {}   # symbol -> offset within self.data

    @property
    def size(self):
        return len(self.data)


def layout_tu(obj_path):
    """Lay out every executable section of an object end to end."""
    with open(obj_path, "rb") as fh:
        obj = Obj(os.path.basename(obj_path), fh.read())
    if not obj.ok:
        raise SystemExit("cannot parse %s as ELF32 ARM" % obj_path)
    syms, _ = read_symbols(obj)

    bysec = defaultdict(list)
    allsec = defaultdict(list)
    for name, value, size, typ, bind, shndx in syms:
        if shndx and shndx < len(obj.sections) and not name.startswith("$"):
            allsec[shndx].append((value, name))
        if typ == STT_FUNC and shndx and shndx < len(obj.sections):
            bysec[shndx].append((value, name))

    data = bytearray()
    mask = bytearray()
    parts = []
    relocs = []
    locals_ = {}
    for i, s in enumerate(obj.sections):
        if s[1] != SHT_PROGBITS or not (s[2] & SHF_EXECINSTR) or not s[5]:
            continue
        align = s[8] or 1
        pad = (-len(data)) % align
        data += bytes([SECTION_FILL]) * pad
        mask += b"\x01" * pad
        base = len(data)
        body = obj.section_data(i)
        data += body
        mask += b"\x01" * len(body)
        for off, rtype, sname, addend in section_relocs(obj, i):
            lo, width = RELOC_MASK.get(rtype, RELOC_DEFAULT)
            start = base + off + lo
            for k in range(start, min(start + width, len(mask))):
                if k >= base:
                    mask[k] = 0
            relocs.append((base + off, rtype, sname, addend))
        for v, n in allsec.get(i, []):
            locals_.setdefault(n, base + v)
        names = [n for _v, n in sorted(bysec.get(i, []))]
        parts.append((base, len(body), pad, names))
    return TULayout(bytes(data), mask, parts, relocs, locals_)


def run_tu(src, addr, version, flags, thumb, lang, region=None, keep=False,
           sdk_include=True):
    work = tempfile.mkdtemp(prefix="bwtu_")
    try:
        obj, cmd, log, rc = compile_tu(src, version, flags, thumb, lang, work,
                                       sdk_include=sdk_include)
        if obj is None:
            r = Result("CCERR", note=first_line(log), log=log)
            return r, None
        tl = layout_tu(obj)
        reg = find_region(addr, region)
        rname, tgt = target_bytes(addr, tl.size, region=reg.name)
        fake = FuncBytes("<tu>", tl.data, tl.mask, bool(thumb), ".text",
                         tl.relocs, tl.locals)
        resolve_relocations(fake, addr, declared_symbols(read_header(src)),
                            src=source_key(src), region=reg.name)
        status, diffs = compare(fake, tgt)
        r = Result(status, log=log)
        r.func = fake
        r.target = tgt
        r.region = rname
        r.size = tl.size
        r.diffs = diffs
        return r, tl
    finally:
        if keep:
            print("  kept %s" % work)
        else:
            shutil.rmtree(work, ignore_errors=True)


# ---------------------------------------------------------------------------
# suggest-split
# ---------------------------------------------------------------------------
#
# The honesty rule refuses a witness inside the compared range, and the
# documented remedy for a unit that trips over that is to cut the file so that
# the witness stops being part of what is under test.  See
# docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.  Choosing
# the cut by hand means listing every external reference of the proposed range
# and counting its witnesses elsewhere in the image, which is exactly what the
# attestation indexes already know, so this reports it instead.
#
# It reports.  It never edits a source file, and it never claims a cut is
# right: a cut it calls viable still has to be written and still has to come
# out EXACT.  What it establishes is the negative half, which is the expensive
# half to find by hand: which cuts cannot work, and which function is
# over-constrained and has to be left out.
#
# Two constraints pull against each other and both are modelled:
#
#   * a call to a function defined in the same range is the `local` class and
#     needs no image evidence, so cutting a callee out of a range can break a
#     site that was fine;
#   * a call to a function defined elsewhere needs a witness outside the
#     range, so keeping the only caller and the callee together destroys the
#     only witness there is.
#
# THE PAIRWISE CASE ACROSS TWO FILES needs no new machinery and the manifest
# already handles it: resolve_relocations() sets the compared range to the one
# unit being compiled and nothing else, so a call site sitting in a sibling
# file's range is simply outside, and each of the two files is a witness for
# the other.  src/matched/unit_02008B08.c and src/matched/unit_02008B4C.c are
# a committed instance, and so are unit_0200902C.c and unit_02009050.c.  The
# two are separate compilations and separate manifest entries, and the build
# splices them independently, so nothing about the pair is special except that
# neither may contain both call sites.  suggest_split() reports such a pair as
# two adjacent viable pieces.


def manifest_function_addresses():
    """{address: (entry name, source path)} for every matched function."""
    out = {}
    for e in load_manifest_entries():
        names = e.get("functions") or [e["name"]]
        for n in names:
            m = _ADDR_NAME_RE.match(n)
            if m:
                out.setdefault(int(m.group(1), 16), (e["name"], e.get("source", e.get("src", ""))))
    return out


def _site_targets(fb, tl, addr, decls):
    """[(offset, name, target, kind, local_offset or None)] for every site."""
    out = []
    for off, rtype, name, addend in fb.relocs:
        if name in fb.locals:
            out.append((off, name, addr + fb.locals[name], None,
                        fb.locals[name]))
            continue
        info = symbol_address(name, decls)
        if info is None:
            out.append((off, name, None, None, None))
            continue
        target, kind, _origin = info
        out.append((off, name, target, kind, None))
    return out


def _piece_bounds(tl, addr, i, j):
    lo = addr + tl.parts[i][0]
    hi = addr + (tl.parts[j][0] if j < len(tl.parts) else tl.size)
    return lo, hi


def suggest_split(src, addr, tl, fb, decls, region=None):
    """Report the cuts that would give every relocation an outside witness."""
    parts = tl.parts
    n = len(parts)
    sites = _site_targets(fb, tl, addr, decls)
    matched_at = manifest_function_addresses()

    part_of = []
    for off, name, target, kind, loc in sites:
        k = 0
        for i, (base, size, _pad, _names) in enumerate(parts):
            if base <= off < base + size:
                k = i
        part_of.append(k)

    def site_ok(idx, lo, hi):
        off, name, target, kind, loc = sites[idx]
        if target is None:
            return False, "no address for %r" % name
        if loc is not None:
            inside = lo <= addr + loc < hi
            return inside, ("local" if inside
                            else "%08X leaves the range" % (addr + loc))
        # the same hint and site region resolve_relocations() passes, so the
        # split report agrees with the verdict on overlay callees
        hint = decls[name].region if name in decls else None
        proof = attest(target, kind, lo, hi, source_key(src), hint,
                       site_region=region)
        if proof is None:
            return False, "%08X has no witness outside %08X..%08X" % (
                target, lo, hi)
        return True, proof[0]

    feasible = {}
    for i in range(n):
        for j in range(i + 1, n + 1):
            lo, hi = _piece_bounds(tl, addr, i, j)
            ok = True
            for idx in range(len(sites)):
                if not (i <= part_of[idx] < j):
                    continue
                good, _why = site_ok(idx, lo, hi)
                if not good:
                    ok = False
                    break
            feasible[(i, j)] = ok

    # Partition the unit into consecutive feasible pieces, leaving out as few
    # functions as possible and, at equal cost, using as few pieces as
    # possible.  (dropped, pieces, back-pointer).
    INF = (10 ** 6, 10 ** 6, None)
    best = [INF] * (n + 1)
    best[0] = (0, 0, None)
    for j in range(1, n + 1):
        cand = []
        for i in range(j):
            if best[i][0] >= 10 ** 6 or not feasible[(i, j)]:
                continue
            cand.append((best[i][0], best[i][1] + 1, ("cut", i)))
        if best[j - 1][0] < 10 ** 6:
            cand.append((best[j - 1][0] + 1, best[j - 1][1], ("drop", j - 1)))
        if cand:
            best[j] = min(cand)

    print()
    print("suggest-split: %d function section(s), %d relocation site(s)"
          % (n, len(sites)))
    print("  the whole range as one file is %s"
          % ("viable" if feasible.get((0, n)) else "NOT viable"))

    lo_all, hi_all = _piece_bounds(tl, addr, 0, n)
    print()
    print("  sites, judged against the whole range:")
    for idx, (off, name, target, kind, loc) in enumerate(sites):
        good, why = site_ok(idx, lo_all, hi_all)
        print("    +%04X %-28s %s" % (off, name, why if not good else
                                      "resolved [%s]" % why))
        if good:
            continue
        if target is None:
            continue
        witnesses = sorted(set(image_call_sites(target))
                           | set(evidence().pool_words.get(
                               target | 1 if kind == "thumb" else target, ())))
        inside = [w for w in witnesses if lo_all <= w < hi_all]
        print("          witnesses image wide: %d, of them inside this "
              "range: %d" % (len(witnesses), len(inside)))
        for w in witnesses[:6]:
            print("            %08X%s" % (w, "  (inside)" if w in inside
                                          else ""))
        owner = matched_at.get(target)
        if owner is not None:
            print("          %08X is already matched, in %s (%s): pulling it "
                  "into this range would make the site `local`"
                  % (target, owner[0], owner[1]))

    print()
    if best[n][0] >= 10 ** 6:
        print("  no partition of this unit into consecutive pieces is viable")
        return 1
    cuts = []
    j = n
    while j > 0:
        kind_, i = best[j][2]
        cuts.append((kind_, i, j))
        j = i if kind_ == "cut" else j - 1
    cuts.reverse()
    dropped, pieces, _bp = best[n]
    print("  best partition: %d piece(s), %d function(s) left out"
          % (pieces, dropped))
    for kind_, i, j in cuts:
        lo, hi = _piece_bounds(tl, addr, i, j if kind_ == "cut" else i + 1)
        names = []
        for k in range(i, j if kind_ == "cut" else i + 1):
            names += [n for n in parts[k][3] if not n.startswith("$")] \
                or ["(unlabelled)"]
        print("    %-5s %08X..%08X  %s"
              % ("piece" if kind_ == "cut" else "OUT", lo, hi,
                 ", ".join(names)))
    return 0


def cmd_tu(args):
    addr = parse_addr(args.addr)
    thumb = resolve_isa(addr, args.region, args)
    flags = args.flags.split() if args.flags else ["-O4,p"]
    r, tl = run_tu(args.src, addr, args.cc, flags, thumb, args.lang,
                   region=args.region, keep=args.keep,
                   sdk_include=not args.no_sdk_include)
    print("%-10s translation unit @ %08X (%s, %s)"
          % (r.status, addr, r.region or args.region or "?",
             "Thumb" if thumb else "ARM"))
    print("  compiler dsi/%s  flags: %s%s%s"
          % (args.cc, " ".join(BASE_FLAGS + flags),
             " -thumb" if thumb else "",
             (" -lang " + args.lang) if args.lang else ""))
    if r.status == "CCERR":
        print(r.log)
        return 2
    print("  %d code section(s), %d bytes laid out, %d relocation site(s)"
          % (len(tl.parts), r.size, len(tl.relocs)))
    print("  %-10s %-6s %-5s %s" % ("address", "size", "pad", "symbol(s)"))
    for base, size, pad, names in tl.parts:
        print("  %08X   %-6d %-5d %s"
              % (addr + base, size, pad, ", ".join(names) or "(none)"))
    print_sites(r.func)
    if getattr(args, "suggest_split", False):
        suggest_split(args.src, addr, tl, r.func,
                      declared_symbols(read_header(args.src)),
                      region=r.region or args.region)
    if r.status in ("EXACT", "MATCH"):
        if args.diff:
            print_diff(r.func, r.target, addr, reloc_map(r.func))
        return 0
    if r.status == "SIZE":
        print("  laid out %d bytes; nothing to compare against a fixed extent"
              % r.size)
        return 1
    print("  %d concrete byte(s) differ" % len(r.diffs))
    print_diff(r.func, r.target, addr, reloc_map(r.func))
    return 1


# ---------------------------------------------------------------------------
# manifest
# ---------------------------------------------------------------------------

# The manifest is sharded: one file per work packet, under
# layout/matched/<region>/<shard>.json.  See "manifest shards" below.
MANIFEST_DIR = os.path.join(ROOT, "layout", "matched")
LEGACY_MANIFEST = os.path.join(ROOT, "layout", "matched.json")

# Kept as a name because csrc.py and the docs referred to it; it is the shard
# directory now, not a file.
MANIFEST = MANIFEST_DIR

HEADER_RE = re.compile(
    r"^\s*\*?\s*(address|region|compiler|flags|lang|isa|status|function|unit"
    r"|packet)\s*:\s*(.+?)\s*$",
    re.IGNORECASE)

# A `function:` list can run over several lines; a continuation is a comment
# line that is nothing but identifiers and commas.  Prose in the same comment
# never looks like that, so this does not swallow the description.
CONT_RE = re.compile(r"^\s*\*\s*([A-Za-z_][A-Za-z0-9_]*\s*,\s*)*"
                     r"[A-Za-z_][A-Za-z0-9_]*\s*,?\s*$")


# Up to two trailing tokens after the kind, an overlay name (`ovNNN`) and an
# alignment (`aN`), in either order; declared_symbols() refuses two of the
# same sort.
SYMBOL_RE = re.compile(
    r"^\s*\*\s+([A-Za-z_][A-Za-z0-9_]*|@[0-9]+|\.bss)\s+"
    r"(0[xX][0-9A-Fa-f]+)\s+"
    r"(thumb|arm|data)(?:\s+(ov230d|ov\d{3}|twl|arm9|a\d{1,2}))?"
    r"(?:\s+(ov230d|ov\d{3}|twl|arm9|a\d{1,2}))?"
    r"\s*$")
# The start of a `symbols:` line (name and address), whatever follows.  A
# line inside the block that has this shape but not SYMBOL_RE's is an error,
# never the end of the block: before 2026-09-29 an `arm9` token silently
# ended the block and every later line was dropped (w6 tools lane).
SYMBOL_SHAPE_RE = re.compile(
    r"^\s*\*\s+([A-Za-z_][A-Za-z0-9_]*|@[0-9]+|\.bss)\s+0[xX][0-9A-Fa-f]+")
SYMBOLS_OPEN_RE = re.compile(r"^\s*\*?\s*symbols\s*:\s*$", re.IGNORECASE)


def read_header(path):
    """Parse the leading block comment of a matched source file.

    Besides the scalar `address:` / `flags:` / ... fields, the header may
    carry a `symbols:` block naming the address of every extern the file
    references:

        symbols:
          sub_0201F41C        0x0201F41C  thumb
          sub_0200575C_Table  0x020A6C58  data

    The block is what lets match.py resolve relocations instead of
    wildcarding them.  Declaring an address here is a claim, not evidence:
    see the honesty rule above for what the harness demands before it
    believes one.
    """
    fields = {}
    last = None
    in_symbols = False
    with open(path, "r", errors="replace") as fh:
        for line in fh:
            if line.lstrip().startswith("*/"):
                break
            if in_symbols:
                m = SYMBOL_RE.match(line)
                if m:
                    fields.setdefault("symbols_lines", []).append(
                        " ".join(g for g in m.groups() if g))
                    continue
                if SYMBOL_SHAPE_RE.match(line):
                    raise SystemExit(
                        "%s: bad symbols: line %r (want 'name 0xADDR "
                        "thumb|arm|data [ovNNN|ov230d|twl|arm9] [aN]')"
                        % (path, line.strip()))
                in_symbols = False
            if SYMBOLS_OPEN_RE.match(line):
                in_symbols = True
                last = None
                continue
            m = HEADER_RE.match(line)
            if m:
                last = m.group(1).lower()
                fields[last] = m.group(2)
                continue
            if last == "function" and CONT_RE.match(line):
                fields["function"] = fields["function"].rstrip(",") + ", " + \
                    line.strip().lstrip("*").strip()
                continue
            last = None
            s = line.strip()
            if s and not s.startswith(("/*", "*", "//")) and fields:
                break
    return fields


SRC_DIRS = [
    ("src/calib", "sdk_calibration"),
    # The source tree is region/category partitioned.  A file's directory
    # fixes its kind, so kind is derived, never authored: the arm9/itcm/ov/twl
    # split is the region and the _sdk suffix is membership in the
    # tools/sdkclass.py union (the archive placement scan).  src/pending
    # mirrors this and is never collected here.
    ("src/matched/arm9", "game"),
    ("src/matched/arm9_sdk", "sdk"),
    ("src/matched/itcm", "game"),
    ("src/matched/itcm_sdk", "sdk"),
    ("src/matched/ov", "game"),
    ("src/matched/ov_sdk", "sdk"),
    ("src/matched/twl", "game"),
    ("src/matched/twl_sdk", "sdk"),
]

# Where an entry lands when its source names no packet.  Everything matched
# before tools/worklist.py existed is in the first of these.
DEFAULT_SHARD = {"src/matched": "legacy", "src/calib": "calib"}

SHARD_NOTE = ("matched function inventory for one work packet: addresses, "
              "names and compiler configuration only, no game bytes")


# ---------------------------------------------------------------------------
# manifest shards
# ---------------------------------------------------------------------------
#
# layout/matched.json used to be one file, which made a manifest write the one
# genuinely serial step of a parallel wave: every agent that finished a packet
# had to queue behind the integrator.  It is now one file per packet,
#
#     layout/matched/<region>/<shard>.json
#
# with <shard> taken from the `packet:` line in the source file's header, so
# an agent working pkt_0209CE10 writes layout/matched/arm9/pkt_0209CE10.json
# and nothing else.  Two agents never touch the same file, so the merge is a
# directory union and needs no integrator in the loop.
#
# Shard ids are archival, not live: worklist.py dissolves a packet once its
# functions stop being open, but the shard that recorded that work keeps its
# name for ever.  That is why the id comes from the source header rather than
# from a lookup in layout/worklist.json, which would move entries between
# shards on every refresh.

def shard_of(reldir, header):
    """Which shard an entry belongs in: its packet, or the directory default."""
    pkt = (header.get("packet") or "").strip()
    if pkt:
        if not re.match(r"^[A-Za-z0-9_.-]+$", pkt):
            raise SystemExit("bad packet id %r: use pkt_XXXXXXXX" % pkt)
        return pkt
    return DEFAULT_SHARD.get(reldir, "legacy")


def shard_path(region, shard):
    return os.path.join(MANIFEST_DIR, region, shard + ".json")


def shard_files():
    """Every shard file on disk, in a stable order."""
    out = []
    if not os.path.isdir(MANIFEST_DIR):
        return out
    for region in sorted(os.listdir(MANIFEST_DIR)):
        d = os.path.join(MANIFEST_DIR, region)
        if not os.path.isdir(d):
            continue
        for fn in sorted(os.listdir(d)):
            if fn.endswith(".json"):
                out.append(os.path.join(d, fn))
    return out


def shard_doc(region, shard, entries):
    return {
        "tool": "tools/match.py",
        "version": 2,
        "note": SHARD_NOTE,
        "region": region,
        "shard": shard,
        "base_flags": " ".join(BASE_FLAGS),
        "functions": sorted(entries, key=lambda e: int(e["address"], 16)),
    }


def shard_text(doc):
    return json.dumps(doc, indent=1) + "\n"


_MANIFEST_ENTRIES = {}


def load_manifest_entries(check_legacy=True):
    """Every entry of every shard, address-sorted.

    This is the one reader; csrc.py and worklist.py call it rather than
    opening any manifest file of their own.
    """
    if "e" in _MANIFEST_ENTRIES:
        return _MANIFEST_ENTRIES["e"]
    entries = []
    seen = {}
    for path in shard_files():
        with open(path, "r", encoding="utf-8") as fh:
            doc = json.load(fh)
        for e in doc.get("functions", []):
            # The region is part of the identity, not just the address: overlays share
            # load addresses, so ov016 and ov093 legitimately both define func_021CDA0C
            # and they are different code.  A repeat inside one region is still the
            # defect this check exists for (a source claimed twice, or a stale shard).
            key = (e.get("region", ""), e["address"], e.get("kind", ""), e["name"])
            if key in seen:
                # A repeat inside one region is still the defect this check exists for (a source
                # claimed twice, or a stale shard left behind by a packet rename).  But aborting
                # here takes the whole tree down, including every unrelated `match.py one` compile,
                # and concurrent filers see each other's half-written shards.  So: report it,
                # prefer the shard written last, and keep going.
                prev_path, prev_entry = seen[key]
                newer = os.path.getmtime(path) > os.path.getmtime(prev_path)
                sys.stderr.write(
                    "warning: manifest shards disagree: %s is in both %s and %s; using %s\n"
                    % (e["name"], os.path.relpath(prev_path, ROOT),
                       os.path.relpath(path, ROOT),
                       os.path.relpath(path if newer else prev_path, ROOT)))
                if newer:
                    try:
                        entries.remove(prev_entry)
                    except ValueError:
                        pass
                    seen[key] = (path, e)
                    entries.append(e)
                continue
            seen[key] = (path, e)
            entries.append(e)
    entries.sort(key=lambda e: (int(e["address"], 16), e.get("kind", ""),
                                e["name"]))
    if check_legacy:
        check_legacy_manifest(entries)
    _MANIFEST_ENTRIES["e"] = entries
    return entries


def _entry_key(entries):
    """A content fingerprint that ignores key order and entry order."""
    return json.dumps(sorted((json.dumps(e, sort_keys=True) for e in entries)))


def check_legacy_manifest(entries):
    """Fail loudly if the pre-shard layout/matched.json is still around.

    Leaving both in the tree is the one way this refactor can silently lose
    work: a tool that reads the old file and a tool that reads the shards
    would disagree about what is matched, and the build would splice one set
    while the manifest recorded another.
    """
    if not os.path.exists(LEGACY_MANIFEST):
        return
    with open(LEGACY_MANIFEST, "r", encoding="utf-8") as fh:
        old = json.load(fh).get("functions", [])
    rel = os.path.relpath(LEGACY_MANIFEST, ROOT).replace("\\", "/")
    if not entries:
        raise SystemExit(
            "%s still exists and there are no manifest shards.\n"
            "  The manifest is sharded now.  Migrate once with:\n"
            "      python tools/match.py manifest --migrate" % rel)
    if _entry_key(old) != _entry_key(entries):
        raise SystemExit(
            "%s still exists and disagrees with layout/matched/ "
            "(%d entries against %d).\n"
            "  Two sources of truth for what is matched is exactly the "
            "failure this refactor removes.\n"
            "  Reconcile by hand, or re-run the one-time migration:\n"
            "      python tools/match.py manifest --migrate"
            % (rel, len(old), len(entries)))
    raise SystemExit(
        "%s still exists alongside layout/matched/ with the same content.\n"
        "  Delete it; the shards are the manifest now:\n"
        "      python tools/match.py manifest --migrate" % rel)


# ---------------------------------------------------------------------------
# building the manifest from the sources
# ---------------------------------------------------------------------------

def collect_sources():
    """[(shard, region, source path, header, kind, reldir)] for every entry."""
    out = []
    for reldir, kind in SRC_DIRS:
        srcdir = os.path.join(ROOT, *reldir.split("/"))
        if not os.path.isdir(srcdir):
            continue
        for fn in sorted(os.listdir(srcdir)):
            if not fn.endswith((".c", ".cpp")):
                continue
            path = os.path.join(srcdir, fn)
            h = read_header(path)
            if "address" not in h:
                continue
            addr = int(h["address"], 0)
            region = h.get("region") or find_region(addr).name
            out.append((shard_of(reldir, h), region, path, h, kind,
                        reldir + "/" + fn))
    return out


def sole_ref_sites(result):
    """Sorted, de-duplicated `sole-ref` sites of one verification.

    Reads the per-site report resolve_relocations() already built, so there
    is no second notion of what rested on the class.  Each entry is spelled
    "<subkind>:0xADDRESS" ("data"/"code"/"string"/"self"), e.g.
    "code:0x02067998",
    so a shard entry's evidence names which sub-kind carried the site and
    `grep sole-ref layout/matched` or worklist.py's summary can break the
    share down.  Returns [] when the entry used none, which is what keeps an
    unaffected shard byte-stable.
    """
    fb = getattr(result, "func", None)
    sites = getattr(fb, "sites", None) if fb is not None else None
    if not sites:
        return []
    out = set()
    for st in sites:
        if st.resolved and st.cls == "sole-ref" and st.value is not None:
            out.add((st.subkind or "data", st.value & ~1))
    return ["%s:0x%08X" % (k, a) for k, a in sorted(out)]


def sdk_sites(result):
    """Sorted, de-duplicated `sdk` sites of one verification.

    Same shape as sole_ref_sites(), for the `sdk` class (attest_sdk(),
    layout/symbols_sdk.json): an entry that rests on it says so, per site,
    so `grep '"sdk"' layout/matched` lists every entry that depends on a
    recovered SDK address as its only witness.  Returns [] when the entry
    used none.
    """
    fb = getattr(result, "func", None)
    sites = getattr(fb, "sites", None) if fb is not None else None
    if not sites:
        return []
    out = set()
    for st in sites:
        if st.resolved and st.cls == "sdk" and st.value is not None:
            out.add(st.value & ~1)
    return ["0x%08X" % a for a in sorted(out)]


# ---------------------------------------------------------------------------
# the `runtime` manifest kind
# ---------------------------------------------------------------------------
#
# layout/runtime_arm9.txt lists the mwccarm/MSL runtime.a routines (soft
# float, 64-bit divide, compares): hand-written library assembly, not game
# C, and tools/worklist.py keeps those rows out of the game figure.  A file
# under src/matched that reproduces them (asm blocks) is still a real
# byte-for-byte comparison, but filing it as `game` would make worklist's
# classifier treat the row as proven game code and count it there.  So an
# entry whose address is a runtime_arm9.txt row gets kind `runtime`:
#
#   * each name in the header's `function:` list must be a runtime_arm9.txt
#     row; each one the file defines (`asm ... name(`) is compiled and
#     compared on its own at that row's address, the same comparison
#     `match.py one` makes, whether or not the header says `unit: yes`
#     (members of these files are not contiguous, so a unit compare would
#     be the wrong test);
#   * `covers` lists every runtime row inside the compared bytes of those
#     functions (a merged asm body covers the interior entry points it
#     branches into), and every name in the header must be covered;
#   * the status is EXACT only when every comparison is EXACT or EXACT*
#     (EXACT* when any is), else the first failing verdict.
#
# worklist.py classifies a `runtime` entry's rows as runtime with a matched
# name, never as game; the coverage map draws them as matched runtime.

_RUNTIME_ASM_DEF = r"^[ \t]*asm\b[^;{(]*\b%s[ \t]*\("


def runtime_entry_status(path, header, addr, flags, lang, region):
    """(status, covers, note) for a `runtime` kind entry; see above."""
    rt = runtime_addresses()
    by_name = dict((n, a) for a, n in rt.items())
    names = [n.strip() for n in header.get("function", "").split(",")
             if n.strip()]
    try:
        with open(path, "r", errors="replace") as fh:
            text = fh.read()
    except OSError:
        return "CCERR", [], "cannot read %s" % path
    if not names:
        return "DIFF", [], "no function: names"
    for n in names:
        if n not in by_name:
            return "DIFF", [], "%s is not a layout/runtime_arm9.txt row" % n
    if by_name[names[0]] != addr:
        return "DIFF", [], "address is not the first function's row"
    covers = set()
    statuses = []
    for n in names:
        if not re.search(_RUNTIME_ASM_DEF % re.escape(n), text, re.M):
            continue
        a = by_name[n]
        r = run_one(path, n, a, header.get("compiler", "1.1p1"),
                    flags.split(), False, lang, region=region)
        statuses.append((n, r.status))
        if r.status in MATCHED_STATUS:
            covers.update(x for x in rt if a <= x < a + r.size)
    bad = [(n, st) for n, st in statuses if st not in MATCHED_STATUS]
    if not statuses:
        return "DIFF", [], "the file defines none of its functions"
    if bad:
        return bad[0][1], sorted(covers), "%s: %s" % bad[0]
    missing = [n for n in names if by_name[n] not in covers]
    if missing:
        return "DIFF", sorted(covers), "not covered: " + ", ".join(missing)
    star = any(st == "EXACT*" for _n, st in statuses)
    return ("EXACT*" if star else "EXACT"), sorted(covers), ""


def entry_from_source(path, header, kind, rel, verify=False):
    """One manifest entry, optionally recompiled to record a live status."""
    h = header
    fn = os.path.basename(path)
    addr = int(h["address"], 0)
    flags = h.get("flags", "-O4,p")
    lang = h.get("lang", "c99")
    region = h.get("region") or find_region(addr).name
    names = [n.strip() for n in h.get("function", "").split(",") if n.strip()]
    if not names:
        names = [os.path.splitext(fn)[0]]
    thumb = (h.get("isa", "").lower() == "thumb")
    if not h.get("isa"):
        thumb = resolve_isa(addr, region,
                            argparse.Namespace(thumb=False, arm=False))
    is_unit = h.get("unit", "").strip().lower() in ("yes", "true", "1")
    runtime_kind = (kind == "game" and region == "arm9"
                    and addr in runtime_addresses())
    if runtime_kind:
        kind, is_unit = "runtime", False
    covers = None
    # The header's `status:` is never trusted (audit 2026-09-23, finding 4):
    # without --verify the entry records "unverified", which no coverage
    # reader counts (worklist.load_matched filters on MATCHED_STATUS).
    status = "unverified"
    if verify and runtime_kind:
        status, covers, _note = runtime_entry_status(path, h, addr, flags,
                                                     lang, region)
        sole, sdk_ev = [], []
    elif verify:
        if is_unit:
            r, _tl = run_tu(path, addr, h.get("compiler", "1.1p1"),
                            flags.split(), thumb, lang, region=region)
        else:
            r = run_one(path, names[0], addr, h.get("compiler", "1.1p1"),
                        flags.split(), thumb, lang, region=region)
        status = r.status
        # Auditability: the `sole-ref` class is the weakest in the set, so an
        # entry that rests on it says so, per site, in the manifest itself.
        # `grep sole-ref layout/matched` then lists every entry that depends
        # on the class.  An entry that uses no such site records nothing, so
        # every shard that predates the class stays byte for byte identical.
        sole = sole_ref_sites(r)
        sdk_ev = sdk_sites(r)
    entry = {
        "name": os.path.splitext(fn)[0] if is_unit else names[0],
        "address": "0x%08X" % addr,
        "kind": (kind + "_unit") if is_unit else kind,
        "region": region,
        "source": rel,
        "compiler": "dsi/" + h.get("compiler", "1.1p1"),
        "lang": lang,
        "isa": "thumb" if thumb else "arm",
        "flags": " ".join(BASE_FLAGS) + " " + flags +
                 (" -thumb" if thumb else "") + " -lang " + lang,
        "status": status,
    }
    # The compared length, only when it runs past the listing extent (the
    # next listing label after the address, which need not itself be a
    # label): run_one() compares the compiled function's full length at its
    # address, so the bytes past that label (interior labels of one vendor
    # symbol) are verified too, and worklist.py credits such a label only
    # when this field covers it (owner decision 2026-09-28).  An entry whose
    # compared bytes stop at or before the next label records nothing.
    if verify and not is_unit and not runtime_kind and r.size:
        nxt = next_listing_label(addr, find_region(addr, region).name)
        if nxt is not None and addr + r.size > nxt:
            entry["compared_bytes"] = r.size
    if is_unit:
        entry["functions"] = names
    if runtime_kind:
        entry["functions"] = names
        if covers is not None:
            entry["covers"] = ["0x%08X" % a for a in covers]
    if verify and (sole or sdk_ev):
        entry["evidence"] = {}
        if sole:
            entry["evidence"]["sole-ref"] = sole
        if sdk_ev:
            entry["evidence"]["sdk"] = sdk_ev
    return entry


def write_shards(by_shard, only=None):
    """Write the shards whose content changed.  Returns [(path, changed)]."""
    out = []
    for (region, shard), entries in sorted(by_shard.items()):
        if only is not None and (region, shard) not in only:
            continue
        path = shard_path(region, shard)
        text = shard_text(shard_doc(region, shard, entries))
        old = None
        if os.path.exists(path):
            with open(path, "r", encoding="utf-8", newline="") as fh:
                old = fh.read()
        if old == text:
            out.append((path, False))
            continue
        os.makedirs(os.path.dirname(path), exist_ok=True)
        with open(path, "w", encoding="utf-8", newline="\n") as fh:
            fh.write(text)
        out.append((path, True))
    return out


def match_shard_id(wanted, by_shard):
    """Resolve a --shard argument to one (region, shard) key."""
    keys = sorted(by_shard)
    w = wanted.replace("\\", "/")
    exact = [k for k in keys if "%s/%s" % k == w or k[1] == w]
    if len(exact) == 1:
        return exact[0]
    if not exact:
        raise SystemExit("no such shard: %s\n  known shards: %s"
                         % (wanted, ", ".join("%s/%s" % k for k in keys)))
    raise SystemExit("ambiguous shard %r: %s"
                     % (wanted, ", ".join("%s/%s" % k for k in exact)))


def manifest_duplicates(docs):
    """{(region, address): [(shard, name, kind, source), ...]} for every
    address that more than one shard entry of one region claims.

    `docs` is [(shard path, parsed shard)].  The key is the region and the
    address only: a function's identity is its address (tree brief, addendum
    3), so two entries that differ only in name or kind (an old game copy
    next to a newer sdk one, a renamed file next to its predecessor) are the
    same claim made twice.  Unit entries are keyed the same way, by the
    header address they carry, so a unit and a function entry at one address
    are a duplicate too.  Overlays share load addresses, which is why the
    region stays in the key.
    """
    seen = defaultdict(list)
    for rel, doc in docs:
        for e in doc.get("functions", []):
            if not isinstance(e, dict):
                continue
            try:
                addr = "0x%08X" % int(str(e.get("address")), 16)
            except ValueError:
                addr = e.get("address")
            seen[(e.get("region"), addr)].append(
                (rel, e.get("name"), e.get("kind"), e.get("source")))
    return {k: v for k, v in seen.items() if len(v) > 1}


def manifest_check():
    """Report duplicate manifest entries and json files shard_files() ignores.

    The one defect that silently corrupts coverage and the build is a shard
    entry that exists twice (two entries claiming one region+address, whatever
    their name or kind; see manifest_duplicates()), or
    a shard file that is not named so shard_files() reads it at all (the twl
    shards were twl_audio.json / twl_sys.json for a while).  This is the
    cheap, read-only gate for both.
    """
    read = set(os.path.normcase(os.path.abspath(p)) for p in shard_files())
    on_disk = []
    for dirpath, _dirs, files in os.walk(MANIFEST_DIR):
        for fn in files:
            if fn.endswith(".json"):
                on_disk.append(os.path.join(dirpath, fn))
    unread = [p for p in sorted(on_disk)
              if os.path.normcase(os.path.abspath(p)) not in read]
    docs = []
    for p in shard_files():
        try:
            with open(p, encoding="utf-8") as fh:
                docs.append((os.path.relpath(p, ROOT), json.load(fh)))
        except Exception as exc:       # unparseable is itself a defect
            unread.append(p)
            sys.stderr.write("unparseable shard: %s (%s)\n"
                             % (os.path.relpath(p, ROOT), exc))
            continue
    dups = manifest_duplicates(docs)
    if unread:
        print("%d json file(s) under layout/matched/ are not read by shard_files():"
              % len(unread))
        for p in unread:
            print("  ", os.path.relpath(p, ROOT))
    if dups:
        print("%d address(es) claimed by more than one manifest entry:"
              % len(dups))
        for (region, addr), claims in sorted(dups.items()):
            print("  %s %s" % (region, addr))
            for rel, name, kind, source in claims:
                print("      %-40s %-8s %-28s %s"
                      % (rel.replace("\\", "/"), kind, name, source))
    if not unread and not dups:
        print("manifest check: clean (%d shard file(s), no duplicates, no unread json)"
              % len(read))
        return 0
    return 1


def cmd_manifest(args):
    if getattr(args, "check", False):
        return manifest_check()
    if args.migrate:
        return migrate_manifest()

    sources = collect_sources()
    if os.path.exists(LEGACY_MANIFEST):
        # A stale pre-shard file is never harmless: it would leave two
        # disagreeing answers to "what is matched" in the tree.
        check_legacy_manifest([entry_from_source(p, h, k, rel)
                               for _s, _r, p, h, k, rel in sources])

    meta = defaultdict(list)
    for shard, region, path, header, kind, rel in sources:
        meta[(region, shard)].append((path, header, kind, rel))
    by_shard = {k: [] for k in meta}

    only = None
    if args.shard:
        only = {match_shard_id(args.shard, by_shard)}

    force = getattr(args, "force", False)
    jobs = getattr(args, "jobs", None) or os.cpu_count() or 4

    to_verify = []
    for key, items in sorted(meta.items()):
        if only is not None and key not in only:
            continue
        by_shard[key] = [None] * len(items)
        region, shard = key
        sp = shard_path(region, shard)
        cached_entries = {}
        if args.verify and not force and os.path.exists(sp):
            try:
                smtime = os.path.getmtime(sp)
                with open(sp, "r", encoding="utf-8") as fh:
                    doc = json.load(fh)
                for e in doc.get("functions", []):
                    if isinstance(e, dict) and e.get("source"):
                        cached_entries[os.path.normcase(os.path.normpath(e["source"]))] = (smtime, e)
            except Exception:
                cached_entries = {}

        for idx, (path, header, kind, rel) in enumerate(items):
            norm_rel = os.path.normcase(os.path.normpath(rel))
            if args.verify and not force and norm_rel in cached_entries:
                smtime, e = cached_entries[norm_rel]
                if os.path.getmtime(path) <= smtime and e.get("status") in MATCHED_STATUS:
                    by_shard[key][idx] = e
                    continue
            to_verify.append((key, idx, (path, header, kind, rel)))

    def do_work(task):
        k, idx, (p, h, kd, r) = task
        entry = entry_from_source(p, h, kd, r, verify=args.verify)
        return k, idx, entry

    if to_verify:
        if args.verify and len(to_verify) > 1:
            with ThreadPoolExecutor(max_workers=min(jobs, len(to_verify))) as ex:
                for k, idx, entry in ex.map(do_work, to_verify):
                    by_shard[k][idx] = entry
        else:
            for task in to_verify:
                k, idx, entry = do_work(task)
                by_shard[k][idx] = entry

    clean_shards = {}
    for k, v in by_shard.items():
        if only is not None and k not in only:
            continue
        valid_entries = [e for e in v if e is not None and (not args.verify or e.get("status") in MATCHED_STATUS)]
        if valid_entries:
            clean_shards[k] = valid_entries
        elif args.verify and v:
            # every entry failed verification: the shard on disk would keep claiming
            # them, so remove it rather than leave stale matched entries counted
            stale = shard_path(*k)
            if os.path.exists(stale):
                os.remove(stale)
                print("removed %s: no entry verifies" % os.path.relpath(stale, ROOT))
    written = write_shards(clean_shards, only=only)

    total = sum(len(v) for k, v in by_shard.items()
                if only is None or k in only)
    nchanged = sum(1 for _p, c in written if c)
    print("%s: %d shard(s), %d entr(ies), %d rewritten"
          % ("manifest" if only is None else "shard " + args.shard,
             len(written), total, nchanged))
    bad = 0
    for key in sorted(by_shard):
        if only is not None and key not in only:
            continue
        region, shard = key
        print("  %s/%s.json" % (region, shard))
        for e in sorted(by_shard[key], key=lambda e: int(e["address"], 16)):
            print("    %-10s %-16s %-30s %-10s %s"
                  % (e["address"], e["kind"], e["name"], e["compiler"],
                     e["status"]))
            if args.verify and e["status"] not in MATCHED_STATUS:
                bad += 1
    if args.verify and bad:
        print("\n%d entr(ies) are not EXACT/EXACT*" % bad, file=sys.stderr)
        return 1
    return 0


def migrate_manifest():
    """One-time move from layout/matched.json to layout/matched/<region>/."""
    sources = collect_sources()
    by_shard = defaultdict(list)
    for shard, region, path, header, kind, rel in sources:
        by_shard[(region, shard)].append(
            entry_from_source(path, header, kind, rel))
    if os.path.exists(LEGACY_MANIFEST):
        with open(LEGACY_MANIFEST, "r", encoding="utf-8") as fh:
            old = json.load(fh).get("functions", [])
        fresh = [e for v in by_shard.values() for e in v]
        old_addrs = {(e["address"], e.get("kind"), e["name"]) for e in old}
        new_addrs = {(e["address"], e.get("kind"), e["name"]) for e in fresh}
        if old_addrs - new_addrs:
            raise SystemExit(
                "refusing to migrate: %d entr(ies) in layout/matched.json "
                "have no source file any more: %s"
                % (len(old_addrs - new_addrs),
                   ", ".join(sorted(n for _a, _k, n in old_addrs - new_addrs))))
        if new_addrs - old_addrs:
            print("  note: %d entr(ies) are new since layout/matched.json: %s"
                  % (len(new_addrs - old_addrs),
                     ", ".join(sorted(n for _a, _k, n in new_addrs - old_addrs))))
    for path, changed in write_shards(by_shard):
        print("  %-46s %s" % (os.path.relpath(path, ROOT).replace("\\", "/"),
                              "written" if changed else "unchanged"))
    if os.path.exists(LEGACY_MANIFEST):
        os.remove(LEGACY_MANIFEST)
        print("  removed layout/matched.json")
    print("migrated %d entr(ies) into %d shard(s)"
          % (sum(len(v) for v in by_shard.values()), len(by_shard)))
    return 0


# ---------------------------------------------------------------------------
# the idiom index
# ---------------------------------------------------------------------------
#
# Compiler idioms used to live inside docs/MATCHING.md, which made them the
# one piece of shared prose every packet agent wanted to append to, and so the
# second serialisation point after the manifest.  They are one file each under
# docs/idioms/ now, and MATCHING.md carries a generated index instead.  An
# agent adds a file; the integrator runs this and the index catches up.
#
# Each file opens with an H1 title and a `summary:` line:
#
#     # ldrsh with a register offset is a signedness tell
#
#     summary: Thumb ldrsh has no immediate form, so one register-offset
#     load among immediate ones says the field is signed.

IDIOMS_DIR = os.path.join(ROOT, "docs", "idioms")
MATCHING_DOC = os.path.join(ROOT, "docs", "MATCHING.md")
IDIOM_BEGIN = "<!-- idioms:begin -->"
IDIOM_END = "<!-- idioms:end -->"


def read_idioms():
    """[(slug, title, summary)] for every docs/idioms/*.md, slug-sorted."""
    out = []
    if not os.path.isdir(IDIOMS_DIR):
        return out
    for fn in sorted(os.listdir(IDIOMS_DIR)):
        if not fn.endswith(".md") or fn == "README.md":
            continue
        path = os.path.join(IDIOMS_DIR, fn)
        title = summary = ""
        with open(path, "r", encoding="utf-8", errors="replace") as fh:
            lines = fh.read().replace("\r\n", "\n").split("\n")
        for i, line in enumerate(lines):
            if not title and line.startswith("# "):
                title = line[2:].strip()
                continue
            if line.lower().startswith("summary:"):
                summary = line.split(":", 1)[1].strip()
                j = i + 1
                while j < len(lines) and lines[j].strip():
                    summary += " " + lines[j].strip()
                    j += 1
                break
        slug = fn[:-3]
        if not title:
            raise SystemExit("docs/idioms/%s has no '# title' line" % fn)
        if not summary:
            raise SystemExit("docs/idioms/%s has no 'summary:' line" % fn)
        out.append((slug, title, " ".join(summary.split())))
    return out


def idiom_index_text(idioms):
    lines = [IDIOM_BEGIN,
             "",
             "%d idiom%s, one file each under `docs/idioms/`."
             % (len(idioms), "" if len(idioms) == 1 else "s"),
             ""]
    for slug, title, summary in idioms:
        lines.append("- [%s](idioms/%s.md): %s" % (title, slug, summary))
    lines += ["", IDIOM_END]
    return "\n".join(lines)


def cmd_idioms(args):
    idioms = read_idioms()
    with open(MATCHING_DOC, "r", encoding="utf-8", newline="") as fh:
        doc = fh.read()
    i = doc.find(IDIOM_BEGIN)
    j = doc.find(IDIOM_END)
    if i < 0 or j < 0 or j < i:
        raise SystemExit(
            "docs/MATCHING.md has no %s / %s block to regenerate"
            % (IDIOM_BEGIN, IDIOM_END))
    new = doc[:i] + idiom_index_text(idioms) + doc[j + len(IDIOM_END):]
    if new == doc:
        print("docs/MATCHING.md idiom index is up to date (%d idiom(s))"
              % len(idioms))
        return 0
    if args.check:
        print("docs/MATCHING.md idiom index is stale; run "
              "python tools/match.py idioms")
        return 1
    with open(MATCHING_DOC, "w", encoding="utf-8", newline="") as fh:
        fh.write(new)
    print("rewrote the idiom index in docs/MATCHING.md (%d idiom(s))"
          % len(idioms))
    for slug, title, _s in idioms:
        print("  %-34s %s" % (slug, title))
    return 0


# ---------------------------------------------------------------------------
# selftest
# ---------------------------------------------------------------------------
#
# attest() is the whole honesty argument, so it is the thing worth testing.
# Every case below is a NEGATIVE one or its matching positive: the point is
# never that a witness was found, it is that a witness inside the compared
# range, or no witness at all, is refused.

# The packed string area these cases read.  0x020A70AC is "mystatus.c", whose
# NUL at 0x020A70B6 fixes where "playtime.c" begins at 0x020A70B8.
STR_MYSTATUS = 0x020A70AC
STR_PLAYTIME = 0x020A70B8

# 0x0201F41C is a labelled function called from all over arm9.
FUNC_LABELLED = 0x0201F41C
# 0x02014468 is labelled but called from arm9 only inside the id 0x1C range;
# the witnesses that carry it are two `bl`s in ov010 and ov020.
FUNC_XREGION = 0x02014468
# 0x020AA260 is a data object eighteen literal pools name.
DATA_LITERAL = 0x020AA260

# 0x02072788 is a linker veneer in front of SND_SetMasterVolume: no label, no
# branch to it anywhere in the image, and the only two words that hold its
# address are the pool words of src/matched/unit_02005794.c.
VENEER = 0x02072788
# Veneer-shaped, but its pointer word names nothing this project can confirm
# is a function, so the veneer rule refuses it: a long-branch stub whose
# target lies in arm9i, outside every region in layout/layout.json.  (The
# earlier fixture 0x02030BBC became a confirmed veneer once its target
# 0x020305C4 was seeded and matched.)
VENEER_UNCONFIRMED = 0x02006D3C
# The same job in Thumb, and deliberately not recognised: mwccarm emits these
# eight bytes for a tail call, and 0x02005C3C is a committed instance of it in
# src/matched/unit_02005C3C.c.
THUMB_THUNK = 0x02005C3C
# 0x021DFDB8 is the linker's Thumb form of the same thing, in ov228.
OVERLAY_THUMB_THUNK = 0x021DFDB8

# 0x021D5440 is a Thumb function of ov093 that nothing in arm9 labels, called
# from many sites in ov093 and elsewhere.  Eleven overlays overlap this
# address; only ov093 labels it, which is what makes the un-hinted case
# unambiguous.
OVERLAY_FUNC = 0x021D5440
# region `twl`: 0x027300F0 is called only by `bl` at 0x0206DCA4, inside
# func_0206DC00 (0x0206DC00..0x0206DDA4 covers both TWL call sites);
# 0x0206DBF4 is an ARM9 function (func_0206DBF4, matched).
TWL_FUNC = 0x027300F0
TWL_CALLER_LO = 0x0206DC00
TWL_CALLER_HI = 0x0206DDA4
TWL_ARM9_ADDR = 0x0206DBF4
# The second DSi-only callee of func_0206DC00 (ARM, `bl` at 0x0206DD40), and
# the literal-pool word just before TWL_FUNC (not a label).
TWL_FUNC2 = 0x0272FEF4
TWL_POOL = 0x027300EC
# decrypted ov230: ica_anime's probe targets (slots 0, 3, 4 of the table at
# 0x02188414), its own extent, a plain ov230 function outside every
# decrypted range, and a second-layer encrypted body at ov230's base
OV230D_SLOTS = (0x021882A0, 0x02188354, 0x02188390)
OV230D_CALLER_LO = 0x02011D9C
OV230D_CALLER_HI = 0x02011D9C + 272
OV230D_PLAIN = 0x02188A0C
OV230D_BODY = 0x02187F00
OVERLAY_FUNC_REGION = "ov093"
# A candidate overlay of OVERLAY_FUNC's address window that does NOT label
# it, for exercising a region_hint that resolves to nothing.
OVERLAY_FUNC_WRONG_REGION = "ov016"

# Which overlay answers for the ISA of a shared address.  0x021DF490 is
# DWC_ScGetLoginCertificate, an ARM row of layout/symbols_sdk.json in ov175,
# which its own listing does not label; ov119 labels the same address as a
# Thumb function, and ov093 (also holding it) has neither.  The real site is
# the call at +0x1C4 of ov175 func_021DA6B8.
ISA_OWN_SDK = 0x021DF490
ISA_OWN_SDK_REGION = "ov175"
ISA_OWN_SDK_OTHER = "ov119"
ISA_OWN_SDK_NEITHER = "ov093"
# 0x021A153C: ov009 labels an ARM function there (DWC ProcessIncomingData);
# ov021 has a seeded Thumb thunk (layout/function_starts.txt), and the ov010
# `bl` of func_02169AB8 reaches the ov021 one.  ov175's window does not hold
# the address.
ISA_HINTED = 0x021A153C
ISA_HINTED_OVERLAY = "ov021"
ISA_HINTED_SITE = "ov010"
ISA_HINT_OUTSIDE = "ov175"

# 0x021D21C0: the callee of src/pending/func_02028A7C.c and its two siblings
# (see docs/AGENT-BRIEF.md's cross-region label paragraph).  Real ARM9-to-
# overlay call sites name it (the header's `symbols:` block was derived from
# exactly those), but no candidate overlay's generated listing traces a
# func_ label there -- disasm.py's per-overlay tracer only follows branches
# it can see inside that overlay, and every site that calls this address is
# in arm9, so it never had a reason to visit these bytes.  Three overlays
# overlap the address (ov016, ov021, ov093); this is therefore the "report
# the candidates and refuse" case, not a labelled positive, and it is the
# same shape whether or not the ambiguity is the reason: zero of the three
# candidates label it either way.
OVERLAY_XCALL_UNLABELLED = 0x021D21C0
OVERLAY_XCALL_CANDIDATES = ("ov016", "ov021", "ov093")

# The `runtime` class.  0x0209C074 is _ll_shl, one of the three sites
# src/pending/sub_02018E34.c calls it from; those three ARE every Thumb
# BL/BLX in the image that reaches it, so `label` could never carry this
# address even with a func_ label.  0x0209C078 is four bytes in (the middle
# of the same routine, per layout/runtime_arm9.txt's next entry starting
# well past it) and is not itself a table entry.
RUNTIME_LL_SHL = 0x0209C074
RUNTIME_NOT_AN_ENTRY = 0x0209C078

# The `sdk` class.  Both are single-call leaf SDK wrappers with no other
# direct caller or literal-pool reference anywhere in the image (see
# docs/notes/pkt_sdk_witness -- the two src/pending sites this class was
# added to close), so `label`/`literal`/`sole-ref` all refuse them and only
# layout/symbols_sdk.json's own catalogued address carries the proof.  Both
# are ARM per their symbols_sdk.json `thumb` flag.
SDK_DWC_WORKSIZE = 0x0205CF24    # DWC_GetCheckNintendoZoneWorkSize
SDK_PXI_INITFIFO = 0x020884A4    # PXI_InitFifo
# FUNC_LABELLED (above) is a real game function, absent from
# layout/symbols_sdk.json entirely, for the negative case.

# A Thumb entry point nothing labels: its only witness anywhere is the pool
# word at 0x020049F8, so the `literal` class attests the ADDRESS while the
# image says nothing at all about the instruction set at it.  This is the case
# where a declared ISA has to be trusted, and noted.
ISA_UNEVIDENCED = 0x02005124

# "box_savedata.c": ten NUL bytes separate it from the terminator of
# "save_control.c", which is more alignment than the string class used to
# allow.  0x020A7068 is the empty string inside that run.
STR_BOX_SAVEDATA = 0x020A706C
# "land_data_patch.c" in ov021's image, and .bss in ov016's window: the
# cross-overlay witness cases (w6 tools lane, 2026-09-29).
XOV_STRING = 0x021DE558
STR_EMPTY_IN_PADDING = 0x020A7068
# A string in ov009 whose NUL run is 40 bytes, past MAX_STRING_PAD.
STR_FAR_NEIGHBOUR = 0x021A4618

# The pair at 0x02008B08 / 0x02008B4C: OS_GetOwnerRtcOffset is reached from
# 0x02008B26 and 0x02008B7C and from nowhere else in the ROM.  It is also a
# catalogued layout/symbols_sdk.json entry, so since the `sdk` class was
# added it now attests via `sdk` rather than falling through to
# `sole-ref/code` once both call sites share one compared range; see the
# pairwise cases below.
OS_GETOWNERRTCOFFSET = 0x02087D08

# The `matched` class.  func_02018DB4 is the party-area dispatcher: the `bl` at
# 0x02017E2E in src/matched/unit_02017E1C.c is the only branch to it anywhere
# in the image, so with that file's range under test no image class has a
# witness left.  src/matched/sub_02018DB4.c is the EXACT entry that does.
MATCHED_CALLEE = 0x02018DB4
MATCHED_CALLEE_SRC = "src/matched/arm9/sub_02018DB4.c"
MATCHED_CALLER_SRC = "src/matched/arm9/unit_02017E1C.c"
MATCHED_CALLER_LO, MATCHED_CALLER_HI = 0x02017E1C, 0x02017E40
# func_0200B6E0 is not the address of src/matched/unit_0200B67C.c, it is the
# second function that unit's layout records: the same byte comparison covered
# it, so the entry attests it too.
# --- the sole-ref class ----------------------------------------------------
# 0x020A7004 is the __FILE__ string of gfl_use.c: layout/file_anchors.txt
# records it as an object start, so condition (b) holds there, and it is well
# inside the rodata blob so condition (a) does too.  It is also the start of a
# NUL-terminated run whose left neighbour terminates, so the `string` class
# carries it first -- which is exactly what the ordering case below checks.
SOLE_REF_ANCHOR = 0x020A7004
# 0x020963F4 is a `.word` run start disasm.py emitted as its own block, four
# aligned but not eight, which is the alignment case.  No pool word in the
# image names it, so it is also the pure case: only this class can carry it.
SOLE_REF_RUN_START = 0x020963F4
# 0x02004F7C is another run start, and one literal pool word does name it, so
# it is the ordering case: `literal` answers first and the class only speaks
# once that witness is inside the compared range.
SOLE_REF_ALSO_LITERAL = 0x02004F7C
# interior to the 0x0209D86C run, and named by nothing at all: no block start,
# no pool word anywhere in the image, no string, no declaration.  The address
# the class must refuse however wide the compared range.
SOLE_REF_INTERIOR = 0x0209D900
# a traced ARM function in the middle of a code section.
SOLE_REF_CODE = 0x02096670

# --- sole-ref/code, sole-ref/string (widened 2026-09-21) -------------------
# 0x02005230 is a real func_ label (Thumb) with no in-region call
# (evidence().calls has no entry for it) and no cross-region branch either
# (xregion_calls() agrees): the `label` class has no witness at all, and
# nothing pools it either, so `attest()` used to refuse it outright.  It is
# the pure sole-ref/code case: a traced function start, carried on the
# layout alone.
SOLE_REF_CODE_LABEL = 0x02005230
# one halfword past the label above: still inside the function's own first
# instruction, not itself a label start.  sole-ref/code must refuse an
# address that is merely interior to a traced function.
SOLE_REF_CODE_NONLABEL = 0x02005232
# "mail.c" (0x020A716C) and "wifilist.c" (0x020A7198): both immediately
# follow a static table rather than a string (see
# docs/idioms/a-string-after-a-data-table-has-no-witness.md), so
# attest_string()'s condition 5 refuses them, and each name is passed by
# exactly one function, so `literal` has no outside witness either.  The
# layout still says a NUL-terminated printable run begins exactly there.
SOLE_REF_STRING_AFTER_TABLE = 0x020A716C

# --- sole-ref/self (2026-09-21) -------------------------------------------
# A real ABS32-shaped site: the pool word at 0x020049D4 holds 0x02004F94,
# which is a rodata address (in_data_section() agrees) and no code extent
# covers it.  This is the positive `self` case -- relocation agreement is
# the whole evidence, no second referrer anywhere.
SOLE_REF_SELF_SITE = 0x020049D4
SOLE_REF_SELF_TARGET = 0x02004F94
# The pool word at 0x020052E0 holds 0x0200FB6D, a Thumb function pointer:
# 0x0200FB6C is inside a traced function's extent, so in_data_section()
# refuses it and `self` must too, however well the ROM word agrees.  Code
# targets keep their existing rules (`label`, `veneer`, `sole-ref/code`).
SOLE_REF_SELF_CODE_SITE = 0x020052E0
SOLE_REF_SELF_CODE_TARGET = 0x0200FB6C
# one byte into "gfl_use.c" (SOLE_REF_ANCHOR + 1): also a NUL-terminated
# printable run in its own right ("fl_use.c"), but NOT a run start -- the
# byte before it is printable too.  sole-ref/string must refuse an address
# that is merely an offset into a longer run, exactly as sole-ref/code
# refuses an offset into a traced function and sole-ref/data refuses an
# offset into a known object.
SOLE_REF_STRING_INTERIOR = SOLE_REF_ANCHOR + 1

# --- the data-object map (layout/data_objects.txt, tools/datamap.py) -------
# 0x020050AC is in the rodata of the ARM9 static module.  disasm.py emits no
# block start there and no ARM9 pool word names it; the ONLY reference to it
# anywhere in the image is a literal-pool word in ov009's listing.  That is
# the map's own case: evidence read from a file no ARM9 comparison ever
# includes.
SOLE_REF_MAP_OVERLAY = 0x020050AC
SOLE_REF_MAP_OVERLAY_SITE = 0x02157588
# 0x02004F94 has exactly one referrer image-wide, the pool word at 0x020049D4.
# Outside that range the map attests it; with that one site inside the range
# under test, the start has no witness left and the class must refuse it,
# because a lone reference never attests its own start.
SOLE_REF_MAP_LONE = 0x02004F94
SOLE_REF_MAP_LONE_SITE = 0x020049D4
# one word past SOLE_REF_MAP_OVERLAY, and before the next map start at
# 0x020050C4: an address BETWEEN two map starts is interior to neither's
# object and is refused.
SOLE_REF_MAP_BETWEEN = 0x020050B0

MATCHED_MEMBER = 0x0200B6E0
MATCHED_MEMBER_SRC = "src/matched/arm9/unit_0200B67C.c"

# --- the overlay rules of sole-ref and matched (2026-09-23) ----------------
# 0x02156460: a Thumb func_ label in ov009 (ov010 overlaps the address and
# does not label it); its only caller image-wide is the bl at 0x0200F7A8
# inside src/pending/sub_0200F734.c (0x0200F734..0x0200F7B8), so `label`
# has no outside branch and only the overlay sole-ref/code rule carries it.
OV_CODE_SOLE = 0x02156460
OV_CODE_SOLE_REGION = "ov009"
OV_CODE_SOLE_LO, OV_CODE_SOLE_HI = 0x0200F734, 0x0200F7B8
# 0x0215E334: a callee of src/pending/func_02012704.c that neither ov009 nor
# ov010 labels.
OV_CODE_UNLABELLED = 0x0215E334
# 0x02155244: labelled Thumb in BOTH ov009 and ov010, the ambiguity case.
OV_CODE_TWICE = 0x02155244
# 0x0216FEDC: ov010 data (ov009 has code there) that the listing's block
# structure does not start; the one pool word naming it anywhere is
# pool_02155470 in ov010.  Outside that site's range it is an ov010 object
# start; with the site inside the range it has no witness left.
OV_DATA_POOLED = 0x0216FEDC
# Extent ends (2026-09-27).  ov010 func_0216FEAC is Thumb and ends in the
# 2-byte `pop {..., pc}` at 0x0216FED6; the rodata word {1, 0} at 0x0216FED8
# follows it directly and is pooled once, at 0x02155474 inside
# func_02155328.  ov009 func_02157280 is ARM (last instruction at
# 0x02157288) and ov009 func_021A3248 is Thumb ending in a 4-byte `bl` at
# 0x021A328C: their extents must still close 4 bytes after that start.
OV_EXT_THUMB2 = 0x0216FEAC
OV_EXT_THUMB2_END = 0x0216FED8
OV_EXT_ARM, OV_EXT_ARM_END = 0x02157280, 0x0215728C
OV_EXT_BL, OV_EXT_BL_END = 0x021A3248, 0x021A3290
OV_EXT_USER_LO, OV_EXT_USER_HI = 0x02155328, 0x02155478   # func_02155328
OV_DATA_INTERIOR = 0x216fee8   # ov010 data, not a start, no pool referrer
OV_DATA_POOLED_SITE = 0x02155470
# 0x021D6338 (src/pending/func_02010AC4.c): ov021's listing starts a block
# there, ov016 and ov115 overlap the address and hold data too, and ov115
# declares an object start there in layout/data_objects.txt (its proc table).
OV_DATA_SHARED = 0x021D6338
# 0x02171F3C: the ov010 byte table of the 0x02167394 callee (wave 14,
# game_beacon.c).  Its only reference is the word at 0x021673A4 inside that
# function (0x02167394..0x021673A8), so no start rule can carry it; the
# overlay self rule does, with the site read from ov010.
OV_DATA_SELF = 0x02171F3C
OV_DATA_SELF_SITE = 0x021673A4
OV_DATA_SELF_LO, OV_DATA_SELF_HI = 0x02167394, 0x021673A8
# 0x02168800: src/matched/func_02168800.c, an EXACT entry of the ov010
# shard; ov009 overlaps the address and labels nothing there.
OV_MATCHED = 0x02168800
OV_MATCHED_REGION = "ov010"
OV_MATCHED_SRC = "src/matched/ov/func_02168800.c"
OV_MATCHED_CALLER_SRC = "src/pending/overlay_selftest.c"
# func_021DC2D8 (EXACT, layout/matched/ov175/pkt_021DC2D8.json), called at
# 0x021DA82C by func_021DA6B8 (0x021DA6B8..0x021DADA8).
OV175_MATCHED = 0x021DC2D8
OV175_CALLER_LO = 0x021DA6B8
OV175_CALLER_HI = 0x021DADA8


def _matched_fixture(status="EXACT", kind="game_unit"):
    """A manifest entry the manifest does not contain.

    The status and kind refusals cannot be exercised against the real shards,
    because the manifest is EXACT-only and holds no other kind, so they are
    tested at matched_index() with an entry built here.
    """
    return {"name": "unit_0BADF000", "address": "0x0BADF000",
            "kind": kind, "status": status, "isa": "thumb",
            "source": "src/matched/unit_0BADF000.c",
            "functions": ["func_0BADF000", "func_0BADF010"]}


def _resolve_one_call(addr, kind, place=0x02008000, hint=None, region=None):
    """Resolve a lone Thumb BL whose target is declared `addr` / `kind`.

    Four bytes of code and one R_ARM_THM_CALL, built by hand rather than
    compiled: the point is the resolver's treatment of the declaration, not
    the code around the call.  `hint` is the overlay token of the symbols
    line, `region` the region the site belongs to.
    """
    name = "isa_selftest_callee"
    fb = FuncBytes("isa_selftest_caller", b"\x00\xF0\x00\xF8",
                   bytearray(b"\x01\x01\x00\x00"), True, ".text",
                   [(0, R_ARM_THM_CALL, name, -4)])
    decls = {name: Decl(name, addr, kind, "header", region=hint)}
    return resolve_relocations(fb, place, decls, region=region)[0]


# func_02004490: the Thumb `svc #3; bx lr` stub called by an ARM `blx` at
# 0x02091180 (see docs/notes/func_02091150.c.txt).  Real ARM-caller-into-
# Thumb-callee interworking site used to selftest _encode_arm_branch's BLX
# path.
ARM_TO_THUMB_CALLEE = 0x02004490
ARM_TO_THUMB_PLACE = 0x02091180


def _resolve_one_arm_call(addr, kind, place=ARM_TO_THUMB_PLACE):
    """Resolve a lone ARM bl whose target is declared `addr` / `kind`.

    Mirrors `_resolve_one_call` above, but in ARM mode: the encoder has to
    choose between a plain B/BL (same-ISA target) and a BLX(immediate)
    (Thumb target).  Returns the FuncBytes so the caller can inspect the
    actual encoded word, not just whether resolution succeeded.
    """
    name = "arm_isa_selftest_callee"
    fb = FuncBytes("arm_isa_selftest_caller", b"\x00\x00\x00\xEB",
                   bytearray(b"\x00\x00\x00\x01"), False, ".text",
                   [(0, R_ARM_CALL, name, -8)])
    decls = {name: Decl(name, addr, kind, "header")}
    resolve_relocations(fb, place, decls)
    return fb


def _call_refused(addr, kind, hint=None, region=None):
    """True when resolving such a call fails loudly instead of encoding it."""
    try:
        _resolve_one_call(addr, kind, hint=hint, region=region)
    except SystemExit:
        return True
    return False


# The `overlay_id` class, exercised on the byte shape of func_0215FA34
# (ov010): `ldr r0, [pc, #4]; ldr r3, [pc, #8]; bx r3; mov r8, r8`, then the
# id word and the callee word.  Built by hand like _resolve_one_call, so each
# refusal changes exactly one thing.
OVID_THUNK = bytes.fromhex("0148 024B 1847 C046")
OVID_LOADER = 0x02034AC4        # sub_02034AC4, an OVERLAY_ID_CONSUMERS entry
OVID_PLACE = 0x0215FA34
# One past the 237 overlays (0..236) would be 0xED, but 0xED is a real pooled
# constant elsewhere and `literal` attests it; 0xEE has no witness in any
# other class, so it isolates the overlay-index check.
OVID_PAST_LAST = 0xEE


def _resolve_ovid(value, callee=OVID_LOADER, code=OVID_THUNK, id_off=8,
                  callee_off=12, callee_kind="arm"):
    """(resolved, class) of the id site of a hand-built overlay-id thunk."""
    size = max(len(code), id_off + 4, callee_off + 4)
    data = bytearray(size)
    data[:len(code)] = code
    mask = bytearray(b"\x01" * size)
    for o in (id_off, callee_off):
        mask[o:o + 4] = b"\x00\x00\x00\x00"
    fb = FuncBytes("ovid_selftest", bytes(data), mask, True, ".text",
                   [(id_off, R_ARM_ABS32, "ovid_selftest_id", 0),
                    (callee_off, R_ARM_ABS32, "ovid_selftest_callee", 0)])
    decls = {"ovid_selftest_id": Decl("ovid_selftest_id", value, "data",
                                      "header"),
             "ovid_selftest_callee": Decl("ovid_selftest_callee", callee,
                                          callee_kind, "header")}
    sites = resolve_relocations(fb, OVID_PLACE, decls)
    st = [x for x in sites if x.name == "ovid_selftest_id"][0]
    return st.resolved, st.cls


_OVID_SRC = """\
/*
 * selftest fixture, compiled from a string; not part of the tree.
 * symbols:
 *   abs_id_14      0x00000014  data
 *   sub_02034AC4   0x02034AC4  arm
 */
extern unsigned char abs_id_14[];
extern void sub_02034AC4(const void *id);
void func_0215FA34(void)
{
    sub_02034AC4(abs_id_14);
}
"""


def _selftest_overlay_id():
    """End to end: the ov010 thunk func_0215FA34 is EXACT on `overlay_id`."""
    out = []
    work = tempfile.mkdtemp(prefix="bwself_")
    try:
        src = os.path.join(work, "ovid_selftest.c")
        with open(src, "w", newline="\n") as fh:
            fh.write(_OVID_SRC)
        r = run_one(src, "func_0215FA34", 0x0215FA34, "1.1p1", ["-O4,p"],
                    True, "c99", region="ov010")
        _check(out, "overlay_id: func_0215FA34 (ov010, id 0x14 into "
                    "sub_02034AC4) is EXACT end to end", r.status, "EXACT")
        # sole-ref/self on a contested ov115 hint, end to end: accepted in
        # func_02010AC4, which loads ov115; refused in the same function
        # once its ov115 id is declared as ov123's (no ov115 load left).
        p10 = None
        for dp, _dn, fns in os.walk(os.path.join(ROOT, "src", "matched")):
            if "func_02010AC4.c" in fns:
                p10 = os.path.join(dp, "func_02010AC4.c")
                break
        text = open(p10).read()
        acc = os.path.join(work, "selfhint_acc.c")
        with open(acc, "w", newline="\n") as fh:
            fh.write(text)
        r = run_one(acc, "func_02010AC4", 0x02010AC4, "1.1p1", ["-O4,p"],
                    True, "c99")
        _check(out, "sole-ref/self hint: func_02010AC4 (ov115 hint, "
                    "contested by ov021, loads ov115) is EXACT end to end",
               r.status, "EXACT")
        ref = os.path.join(work, "selfhint_ref.c")
        bad = re.sub(r"(ov115_id\s+)0x00000073", r"\g<1>0x0000007B", text)
        with open(ref, "w", newline="\n") as fh:
            fh.write(bad)
        r = run_one(ref, "func_02010AC4", 0x02010AC4, "1.1p1", ["-O4,p"],
                    True, "c99")
        _check(out, "sole-ref/self hint: with no ov115 load the contested "
                    "0x021D6338 site is refused",
               any(st.name == "d_021D6338" and not st.resolved
                   and "hint is contested" in st.reason
                   for st in getattr(r.func, "sites", None) or ()),
               True)
    finally:
        shutil.rmtree(work, ignore_errors=True)
    return out


def _check(results, name, got, want):
    ok = got == want
    results.append((ok, name, got, want))
    return ok


def cmd_selftest(args):
    res = []

    def cls(proof):
        return proof[0] if proof else None

    # --- the label class -------------------------------------------------
    _check(res, "label: an outside caller attests a labelled function",
           cls(attest(FUNC_LABELLED, "thumb", 0, 0)), "label")
    _check(res, "label: every call-site witness inside the compared range "
                "is refused by the label class itself",
           evidence().calls.get(FUNC_LABELLED, None) is not None and
           not [s for s in evidence().calls.get(FUNC_LABELLED, ())
                if not 0x02000000 <= s < 0x03000000], True)
    _check(res, "label: with no call witness left, attest() now falls "
                "through to sole-ref/code -- FUNC_LABELLED is still a real "
                "traced label start, just no longer reached by any outside "
                "branch in this synthetic image-wide range",
           cls(attest(FUNC_LABELLED, "thumb", 0x02000000, 0x03000000)),
           "sole-ref")

    # --- the cross-region label class ------------------------------------
    _check(res, "label: a bl from another region attests the target",
           cls(attest(FUNC_XREGION, "thumb", 0x02008828, 0x020089A8)), "label")
    _check(res, "label: an image-wide compared range leaves the label class "
                "no outside caller, but sole-ref/code still carries the "
                "traced label start",
           cls(attest(FUNC_XREGION, "thumb", 0x02000000, 0x03000000)),
           "sole-ref")

    # --- the label class, overlay-resident callees -------------------------
    _check(res, "label: an overlay's own listing attests a callee in it",
           cls(attest(OVERLAY_FUNC, "thumb", 0, 0)), "label")
    _check(res, "label: the overlay label's ISA has to be the declared ISA",
           cls(attest(OVERLAY_FUNC, "arm", 0, 0)), None)
    _check(res, "label: an image-wide compared range refuses an overlay "
                "callee too (the label rule itself; attest() now falls "
                "through to the overlay sole-ref/code rule, see below)",
           cls(attest_overlay_label(OVERLAY_FUNC, "thumb", 0x02000000,
                                    0x03000000)), None)
    # (0x021DFDB8, the earlier fixture, is labelled in ov228 since seed
    # round 9; 0x0215E334 is still labelled by neither candidate overlay.)
    _check(res, "label: an overlay address no overlay labels is refused",
           cls(attest(OV_CODE_UNLABELLED, "thumb", 0, 0)), None)
    _check(res, "label: a region_hint naming the labelled overlay succeeds "
                "the same way",
           cls(attest(OVERLAY_FUNC, "thumb", 0, 0,
                      region_hint=OVERLAY_FUNC_REGION)), "label")
    _check(res, "label: a region_hint naming a candidate that does not "
                "label it is refused",
           cls(attest(OVERLAY_FUNC, "thumb", 0, 0,
                      region_hint=OVERLAY_FUNC_WRONG_REGION)), None)
    _check(res, "label: a region_hint naming an overlay whose window does "
                "not even hold the address is refused",
           cls(attest(OVERLAY_FUNC, "thumb", 0, 0, region_hint="ov001")),
           None)
    _check(res, "label: three overlapping overlays are the real candidate "
                "list for the field_sound_system.c callee",
           overlay_candidates(OVERLAY_XCALL_UNLABELLED),
           sorted(OVERLAY_XCALL_CANDIDATES))
    # Since the overlay_021 seed for 0x021D21C0 (layout/function_starts.txt)
    # exactly one of the three candidates labels it, so the un-hinted call
    # resolves to that one; with the hint it resolves the same way, and a
    # hint naming a candidate that does not label it is refused.
    _check(res, "label: exactly one of the three candidates now labels the "
                "field_sound_system.c callee, so the un-hinted call resolves",
           cls(attest(OVERLAY_XCALL_UNLABELLED, "thumb", 0, 0)), "label")
    _check(res, "label: the same call with the matching hint resolves too",
           cls(attest(OVERLAY_XCALL_UNLABELLED, "thumb", 0, 0,
                      region_hint="ov021")), "label")
    _check(res, "label: a hint naming a candidate that does not label the "
                "callee is refused",
           cls(attest(OVERLAY_XCALL_UNLABELLED, "thumb", 0, 0,
                      region_hint="ov016")), None)

    # --- the label class, TWL-resident callees (region `twl`) -------------
    # With a DSi key the real asm/twl/twl.s answers; without one (the
    # listing cannot exist) the rule is exercised on an injected label table
    # holding just the traced start, and the result says which it was.
    real_twl = bool(twl_listing_files()) and twl_window() is not None
    saved = (_TWL.get("w"), _FUNC_STARTS.get(TWL_REGION),
             _REGION_CALLS.get(TWL_REGION))
    if not real_twl:
        _TWL["w"] = (0x02700000, 0x02732DA0)
        _FUNC_STARTS[TWL_REGION] = {TWL_FUNC: False}
        _REGION_CALLS[TWL_REGION] = defaultdict(list)
    how = "asm/twl/twl.s" if real_twl else "injected label table, no key"
    try:
        _check(res, "twl: a traced ARM start named with the twl token and "
                    "called from the ARM9 image is attested (%s)" % how,
               cls(attest(TWL_FUNC, "arm", 0, 0, region_hint="twl")),
               "label")
        _check(res, "twl: an interior address (start + 4) is refused (%s)"
                    % how,
               cls(attest_twl_label(TWL_FUNC + 4, "arm", 0, 0, "twl")), None)
        _check(res, "twl: the label's ISA has to be the declared ISA (%s)"
                    % how,
               cls(attest_twl_label(TWL_FUNC, "thumb", 0, 0, "twl")), None)
        _check(res, "twl: with the only call sites inside the compared range "
                    "the rule refuses (%s)" % how,
               cls(attest_twl_label(TWL_FUNC, "arm", TWL_CALLER_LO,
                                    TWL_CALLER_HI, "twl")), None)
        _check(res, "twl: without the twl token the TWL address is not "
                    "looked up (%s)" % how,
               cls(attest_twl_label(TWL_FUNC, "arm", 0, 0, None)), None)
        _check(res, "twl: an ARM9 address is not attested via the twl token",
               cls(attest_twl_label(TWL_ARM9_ADDR, "arm", 0, 0, "twl")),
               None)
    finally:
        for key, val, cache in (("w", saved[0], _TWL),
                                (TWL_REGION, saved[1], _FUNC_STARTS),
                                (TWL_REGION, saved[2], _REGION_CALLS)):
            if val is None:
                cache.pop(key, None)
            else:
                cache[key] = val

    # --- the runtime class ---------------------------------------------
    _check(res, "runtime: a curated MSL/runtime.a entry attests itself, no "
                "label or outside call needed",
           cls(attest(RUNTIME_LL_SHL, "arm", 0, 0)), "runtime")
    _check(res, "runtime: every witness inside the compared range is still "
                "irrelevant -- the table is never in any compared range",
           cls(attest(RUNTIME_LL_SHL, "arm", 0x0209C000, 0x0209C100)),
           "runtime")
    _check(res, "runtime: a Thumb declaration against an ARM table entry is "
                "refused",
           cls(attest(RUNTIME_LL_SHL, "thumb", 0, 0)), None)
    _check(res, "runtime: an address inside the runtime range that is not "
                "itself a listed entry does not attest",
           cls(attest(RUNTIME_NOT_AN_ENTRY, "arm", 0, 0)), None)

    # --- the sdk class -----------------------------------------------------
    _check(res, "sdk: a catalogued layout/symbols_sdk.json address attests "
                "itself, no label or outside call needed "
                "(DWC_GetCheckNintendoZoneWorkSize)",
           cls(attest(SDK_DWC_WORKSIZE, "arm", 0, 0)), "sdk")
    _check(res, "sdk: a second catalogued address, same class (PXI_InitFifo)",
           cls(attest(SDK_PXI_INITFIFO, "arm", 0, 0)), "sdk")
    _check(res, "sdk: every witness inside the compared range is still "
                "irrelevant -- the table is never in any compared range",
           cls(attest(SDK_DWC_WORKSIZE, "arm", 0x0205CF00, 0x0205CF40)),
           "sdk")
    _check(res, "sdk: a Thumb declaration against an ARM-flagged sdk entry "
                "is refused",
           cls(attest(SDK_DWC_WORKSIZE, "thumb", 0, 0)), None)
    _check(res, "sdk: an ordinary game address not in symbols_sdk.json does "
                "not attest via this class",
           cls(attest_sdk(FUNC_LABELLED, "thumb")), None)

    # --- the veneer class --------------------------------------------------
    # VENEER's address is now also named by two real literal pool words
    # (0x0200579C, 0x020057A8: untraced "ldr r3, [pc, #4]; movs r0, #0;
    # bx r3" accessors that call through it, found by disasm.py's
    # index_hidden_pool_words()), and `attest()` tries the `literal` class
    # before `veneer`, so the overall address-level resolution now honestly
    # reports the stronger evidence first. The two range-exclusion checks
    # below are specifically about the veneer class's own logic, so they
    # go straight at attest_veneer() rather than through attest(), the same
    # way the string class's negatives go straight at attest_string() above.
    _check(res, "veneer: a linker veneer attests its own address",
           cls(attest(VENEER, "arm", 0, 0)), "literal")
    _check(res, "veneer: in isolation, a linker veneer attests its own "
                "address",
           cls(attest_veneer(VENEER, "arm", 0, 0)), "veneer")
    _check(res, "veneer: a compared range covering the veneer is refused",
           cls(attest_veneer(VENEER, "arm", 0x02072780, 0x020727A0)), None)
    _check(res, "veneer: a compared range covering only its pointer word is "
                "refused",
           cls(attest_veneer(VENEER, "arm", 0x02072790, 0x02072794)), None)
    _check(res, "veneer: the class never applies to a Thumb symbol",
           cls(attest_veneer(VENEER, "thumb", 0, 0)), None)
    _check(res, "veneer: the class never applies to data",
           cls(attest_veneer(VENEER, "data", 0, 0)), None)
    _check(res, "veneer: a pointer word that names no known function is "
                "refused",
           veneer_at(VENEER_UNCONFIRMED), None)
    _check(res, "veneer: the Thumb tail-call shape is not a veneer",
           veneer_at(THUMB_THUNK), None)
    _check(res, "veneer: nor is the linker's own Thumb form",
           veneer_at(OVERLAY_THUMB_THUNK), None)

    # --- the symbols: header line --------------------------------------------
    # An overlay token and an alignment token may both follow the kind, in
    # either order; before this the header regex took only one and a line
    # with both silently ended the block.
    def _parse_symbols(lines):
        fd, tmp = tempfile.mkstemp(suffix=".c", prefix="bwsyms_")
        with os.fdopen(fd, "w") as fh:
            fh.write("/*\n * symbols:\n")
            for ln in lines:
                fh.write(" *   %s\n" % ln)
            fh.write(" */\n")
        try:
            decls = declared_symbols(read_header(tmp))
        finally:
            os.remove(tmp)
        return sorted((d.name, d.region, d.align) for d in decls.values())
    _check(res, "symbols: an overlay token and an alignment token coexist, "
                "in either order",
           _parse_symbols(["g_A  0x021DFC00  data  ov228  a4",
                           "g_B  0x021DFC10  data  a2  ov228",
                           "f_C  0x021DFDB8  thumb  ov228"]),
           [("f_C", "ov228", None), ("g_A", "ov228", 4),
            ("g_B", "ov228", 2)])
    _check(res, "symbols: the ov230d token parses as the region hint and "
                "does not end the block",
           _parse_symbols(["f_F  0x021882A0  arm  ov230d",
                           "f_G  0x0215FA00  thumb  ov010"]),
           [("f_F", "ov230d", None), ("f_G", "ov010", None)])
    _check(res, "symbols: the twl token parses as the region hint and does "
                "not end the block",
           _parse_symbols(["f_D  0x027300F0  arm  twl",
                           "f_E  0x0206DBF4  arm"]),
           [("f_D", "twl", None), ("f_E", None, None)])

    # --- the literal class -----------------------------------------------
    _check(res, "literal: eighteen pool words attest a data address",
           cls(attest(DATA_LITERAL, "data", 0, 0)), "literal")
    _check(res, "literal: pool words inside the compared range are refused",
           cls(attest(DATA_LITERAL, "data", 0x02000000, 0x03000000)), None)

    # --- the string class ------------------------------------------------
    # The positive case: the pool word under test is the only thing in the
    # image that names 0x020A70B8, so `literal` cannot carry it and only the
    # neighbouring terminator can.
    _check(res, "string: a preceding terminator attests a string start",
           cls(attest(STR_PLAYTIME, "data", 0x0200857C, 0x020085A0)), "string")
    # The negatives go straight at attest_string, because attest() would
    # answer `literal` from the one pool word that does name the string and
    # the point here is what the string rule alone accepts.
    _check(res, "string: the witness bytes inside the compared range are "
                "refused",
           cls(attest_string(STR_PLAYTIME, 0x020A7000, 0x020A7100)), None)
    _check(res, "string: a compared range that merely touches the neighbour "
                "is refused",
           cls(attest_string(STR_PLAYTIME, 0x020A70B6, 0x020A70B7)), None)
    _check(res, "string: the middle of a string is not a string start",
           cls(attest_string(STR_PLAYTIME + 1, 0, 0)), None)
    _check(res, "string: the last character of a string is not one either",
           cls(attest_string(STR_MYSTATUS + 9, 0, 0)), None)
    _check(res, "string: a code address is refused even if it decodes as "
                "text",
           cls(attest_string(FUNC_LABELLED, 0, 0)), None)
    _check(res, "string: the class never applies to a code symbol",
           cls(attest(STR_PLAYTIME, "thumb", 0x0200857C, 0x020085A0)), None)
    # Zero-filled data after the string area: a NUL run before it, but nothing
    # printable, so condition (5) refuses it.
    _check(res, "string: a zero blob is not a terminated neighbour",
           cls(attest_string(0x020A70D0, 0, 0)), None)
    # The padding window: ten NULs, two dead words past the alignment, and
    # 0x020A706C is still the only address in the run at which a string
    # begins.
    _check(res, "string: a wide NUL run still fixes one start",
           cls(attest_string(STR_BOX_SAVEDATA, 0, 0)), "string")
    _check(res, "string: the empty string inside that run is not a start",
           cls(attest_string(STR_EMPTY_IN_PADDING, 0, 0)), None)
    _check(res, "string: a NUL run longer than the measured bound is refused",
           cls(attest_string(STR_FAR_NEIGHBOUR, 0, 0)), None)
    _check(res, "string: the wide window still refuses a witness inside the "
                "compared range",
           cls(attest_string(STR_BOX_SAVEDATA, 0x020A7000, 0x020A7100)), None)

    # --- cross-overlay witnesses (w6 tools lane, 2026-09-29) ---------------
    # 0x021DE558 starts "land_data_patch.c" in ov021's image; ov016's window
    # holds the same address as its own .bss.  The ov016 function
    # func_021BD7F4 names ov016's object there, and the `string` class used
    # to attest it from ov021's bytes (the first region in load order).
    _check(res, "xov: a string in ov021's bytes never attests an ov016 site "
                "whose own window holds the address",
           cls(attest_string(XOV_STRING, 0, 0, site_region="ov016")), None)
    _check(res, "xov: nor does an ov021 hint on an ov016 site in its own "
                "window",
           cls(attest_string(XOV_STRING, 0, 0, site_region="ov016",
                             region_hint="ov021")), None)
    _check(res, "xov: attest() for that ov016 site is not `string` (it may "
                "still stand on ov016's own .bss object start)",
           cls(attest(XOV_STRING, "data", 0, 0, site_region="ov016")) ==
           "string", False)
    _check(res, "xov: the same string attests an ov021 site (its own bytes)",
           cls(attest_string(XOV_STRING, 0, 0, site_region="ov021")),
           "string")
    _check(res, "xov: sole-ref/string reads ov021's own bytes for an ov021 "
                "site",
           cls(attest_sole_ref_string(XOV_STRING, 0, 0, "ov021")),
           "sole-ref")
    _check(res, "xov: with no site overlay and nine overlapping windows the "
                "address picks no overlay's bytes",
           (cls(attest_string(XOV_STRING, 0, 0)),
            cls(attest_string(XOV_STRING, 0, 0, site_region="arm9"))),
           (None, None))
    _check(res, "xov: an ARM9 site with an ov021 hint reads ov021's bytes",
           cls(attest_string(XOV_STRING, 0, 0, site_region="arm9",
                             region_hint="ov021")), "string")
    _check(res, "xov: witness_region() keeps ARM9 addresses on the ARM9 "
                "image",
           witness_region(STR_BOX_SAVEDATA, "ov016").name, "arm9")

    # --- the sole-ref class ------------------------------------------------
    # The layout's own statement that a data object begins at an address, and
    # the weakest class in the set: tried only after every other has failed,
    # `data` only, object STARTS only, and the declared alignment has to hold.
    _check(res, "sole-ref: the literal class carries an object start that a "
                "pool word also names, and answers first",
           cls(attest(SOLE_REF_ALSO_LITERAL, "data", 0, 0)), "literal")
    _check(res, "sole-ref: with that one pool witness inside the compared "
                "range, the layout's object start carries it instead",
           cls(attest(SOLE_REF_ALSO_LITERAL, "data",
                      0x02000000, 0x03000000)), "sole-ref")
    _check(res, "sole-ref: a data address at a known object start that no "
                "pool word names at all is the class's own case",
           cls(attest(SOLE_REF_RUN_START, "data", 0, 0)), "sole-ref")
    _check(res, "sole-ref: a file anchor is an object start too, but the "
                "string class is stronger and answers first",
           cls(attest(STR_PLAYTIME, "data", 0x0200857C, 0x020085A0)),
           "string")
    _check(res, "sole-ref: once the string and literal classes have failed, "
                "the anchor still attests the address",
           cls(attest(SOLE_REF_ANCHOR, "data", 0x02000000, 0x03000000)),
           "sole-ref")
    _check(res, "sole-ref: an address inside a code section is refused",
           cls(attest_sole_ref(SOLE_REF_CODE, "data")), None)
    _check(res, "sole-ref: and attest() does not reach the class for it "
                "either",
           cls(attest(SOLE_REF_CODE, "data", 0x02000000, 0x03000000)), None)
    _check(res, "sole-ref: an address interior to a labelled object is "
                "refused",
           cls(attest_sole_ref(SOLE_REF_INTERIOR, "data")), None)
    _check(res, "sole-ref: one byte past an object start is not a start",
           cls(attest_sole_ref(SOLE_REF_ANCHOR + 1, "data", align=1)), None)
    _check(res, "sole-ref: the declared type's alignment has to hold",
           cls(attest_sole_ref(SOLE_REF_RUN_START, "data", align=8)), None)
    _check(res, "sole-ref: the same address at the alignment it does meet "
                "is accepted",
           cls(attest_sole_ref(SOLE_REF_RUN_START, "data", align=4)),
           "sole-ref")
    _check(res, "sole-ref: the class never applies to a code symbol",
           cls(attest_sole_ref(SOLE_REF_RUN_START, "arm")), None)
    _check(res, "sole-ref: a data address the layout carries no object start "
                "for is refused however wide the compared range",
           cls(attest(SOLE_REF_INTERIOR, "data", 0x02000000, 0x03000000)),
           None)
    _check(res, "sole-ref: the layout does carry usable object starts",
           len(data_object_starts()) > 0, True)

    # --- sole-ref/code (widened 2026-09-21) ---------------------------------
    # The address in the original pool word is accepted when it lands on a
    # traced function start, without requiring a second referrer: covers
    # function pointers and single-caller callees the `label` class cannot
    # reach for lack of an outside branch.
    _check(res, "sole-ref/code: a traced label start with no outside "
                "caller at all is carried by the layout alone",
           cls(attest_sole_ref_code(SOLE_REF_CODE_LABEL, "thumb")),
           "sole-ref")
    _check(res, "sole-ref/code: attest() reaches the same result once "
                "label/literal/veneer/matched have all failed",
           cls(attest(SOLE_REF_CODE_LABEL, "thumb", 0, 0)), "sole-ref")
    _check(res, "sole-ref/code: the wrong ISA for that same label is "
                "refused, exactly as isa_evidence() would refuse it",
           cls(attest_sole_ref_code(SOLE_REF_CODE_LABEL, "arm")), None)
    _check(res, "sole-ref/code: an address merely interior to the function "
                "-- one halfword past the label -- is not a label start "
                "and is refused",
           cls(attest_sole_ref_code(SOLE_REF_CODE_NONLABEL, "thumb")), None)
    _check(res, "sole-ref/code: attest() refuses it too",
           cls(attest(SOLE_REF_CODE_NONLABEL, "thumb", 0, 0)), None)
    _check(res, "sole-ref/code: the class never applies to a data symbol",
           cls(attest_sole_ref_code(SOLE_REF_CODE_LABEL, "data")), None)
    _check(res, "sole-ref/code: a recognised ARM veneer is carried the same "
                "way as a func_ label start",
           cls(attest_sole_ref_code(VENEER, "arm")), "sole-ref")

    # --- sole-ref/string (widened 2026-09-21) -------------------------------
    # A __FILE__-style site whose address begins a NUL-terminated printable
    # run, even when the preceding object is a table rather than a string
    # (docs/idioms/a-string-after-a-data-table-has-no-witness.md): "mail.c"
    # and "wifilist.c" are each closed by this sub-kind.
    _check(res, "sole-ref/string: a __FILE__ string after a data table, "
                "which attest_string() must refuse for lack of a "
                "terminator in front of it, is carried by the layout alone",
           cls(attest_sole_ref_string(SOLE_REF_STRING_AFTER_TABLE, 0, 0)),
           "sole-ref")
    _check(res, "sole-ref/string: the string class itself still refuses "
                "the same address (no preceding string)",
           cls(attest_string(SOLE_REF_STRING_AFTER_TABLE, 0, 0)), None)
    _check(res, "sole-ref/string: with its one literal-pool witness inside "
                "the compared range too, attest() falls all the way "
                "through to sole-ref/string",
           cls(attest(SOLE_REF_STRING_AFTER_TABLE, "data",
                      0x02008F00, 0x02008F80)),
           "sole-ref")
    _check(res, "sole-ref/string: a non-printable data run is refused",
           cls(attest_sole_ref_string(SOLE_REF_RUN_START, 0, 0)), None)
    _check(res, "sole-ref/string: an address one byte into a longer "
                "printable run is not itself a run START and is refused, "
                "exactly as an offset into a known object is refused for "
                "sole-ref/data",
           cls(attest_sole_ref_string(SOLE_REF_STRING_INTERIOR, 0, 0)), None)
    _check(res, "sole-ref/string: a witness inside the compared range is "
                "refused",
           cls(attest_sole_ref_string(SOLE_REF_STRING_AFTER_TABLE,
                                      SOLE_REF_STRING_AFTER_TABLE - 0x10,
                                      SOLE_REF_STRING_AFTER_TABLE + 0x10)),
           None)

    # --- sole-ref/self (2026-09-21) ----------------------------------------
    # The community standard: the relocation names the address the original
    # word already names, the target is data, and that is the proof.  Two
    # guards and nothing else -- a data target, and ROM-word agreement at
    # the site.
    _check(res, "sole-ref/self: a lone pool word naming a rodata start is "
                "carried by relocation agreement alone",
           cls(attest_sole_ref_self(SOLE_REF_SELF_TARGET, "data",
                                    SOLE_REF_SELF_SITE,
                                    SOLE_REF_SELF_TARGET)),
           "sole-ref")
    _check(res, "sole-ref/self: it names itself as the sub-kind",
           (attest_sole_ref_self(SOLE_REF_SELF_TARGET, "data",
                                 SOLE_REF_SELF_SITE,
                                 SOLE_REF_SELF_TARGET) or (None,))[-1],
           "self")
    _check(res, "sole-ref/self: a target inside a code extent is refused, "
                "however exactly the ROM word agrees",
           cls(attest_sole_ref_self(SOLE_REF_SELF_CODE_TARGET, "data",
                                    SOLE_REF_SELF_CODE_SITE,
                                    SOLE_REF_SELF_CODE_TARGET | 1)),
           None)
    _check(res, "sole-ref/self: that code target really is what "
                "in_data_section() refuses",
           in_data_section(SOLE_REF_SELF_CODE_TARGET), False)
    _check(res, "sole-ref/self: a word differing from the ROM word at the "
                "site is refused",
           cls(attest_sole_ref_self(SOLE_REF_SELF_TARGET, "data",
                                    SOLE_REF_SELF_SITE,
                                    SOLE_REF_SELF_TARGET + 4)),
           None)
    _check(res, "sole-ref/self: with no site or expected word there is "
                "nothing to agree with, and the class refuses",
           cls(attest_sole_ref_self(SOLE_REF_SELF_TARGET, "data")), None)
    _check(res, "sole-ref/self: the class never applies to a code symbol "
                "kind",
           cls(attest_sole_ref_self(SOLE_REF_SELF_TARGET, "thumb",
                                    SOLE_REF_SELF_SITE,
                                    SOLE_REF_SELF_TARGET)), None)
    _check(res, "sole-ref/self: the dispatcher reaches it only after data, "
                "string and every stronger class have failed",
           (attest_sole_ref(SOLE_REF_SELF_TARGET, "data", 4,
                            SOLE_REF_MAP_LONE_SITE - 0x40,
                            SOLE_REF_MAP_LONE_SITE + 0x40,
                            SOLE_REF_SELF_SITE,
                            SOLE_REF_SELF_TARGET) or (None,))[-1],
           "self")
    _check(res, "sole-ref/self: rom_word_at() reads the site's original "
                "word, and refuses an address outside every loaded region",
           (rom_word_at(SOLE_REF_SELF_SITE), rom_word_at(0x00000000)),
           (SOLE_REF_SELF_TARGET, None))

    # --- the data-object map -----------------------------------------------
    # layout/data_objects.txt (tools/datamap.py) is the finer set of
    # boundaries: the listings' own block structure emits the whole rodata
    # tail as one 47 kB run, so almost every reference into it used to be
    # refused as interior.  The map's evidence still has to lie OUTSIDE the
    # range under test.
    _check(res, "map: the map loads and carries object starts",
           len(data_object_map()) > 0, True)
    _check(res, "map: a start attested only by an overlay pool word is "
                "accepted",
           cls(attest_sole_ref(SOLE_REF_MAP_OVERLAY, "data")), "sole-ref")
    _check(res, "map: that start is not one the listings' block structure "
                "already carried",
           SOLE_REF_MAP_OVERLAY in data_object_starts(), False)
    _check(res, "map: a start with one referrer outside the range is "
                "accepted",
           cls(attest_sole_ref(SOLE_REF_MAP_LONE, "data", 4, 0, 0)),
           "sole-ref")
    _check(res, "map: a start whose only referrer is inside the range under "
                "test is refused -- a lone reference never attests its own "
                "start",
           cls(attest_sole_ref(SOLE_REF_MAP_LONE, "data", 4,
                               SOLE_REF_MAP_LONE_SITE - 0x40,
                               SOLE_REF_MAP_LONE_SITE + 0x40)), None)
    _check(res, "map: an address between two map starts is refused",
           cls(attest_sole_ref(SOLE_REF_MAP_BETWEEN, "data", 4, 0, 0)), None)
    _check(res, "map: the map never accepts a table-guess row, which is a "
                "heuristic and not a witness",
           "table-guess" in SOLE_REF_MAP_KINDS, False)
    _check(res, "map: the map's evidence does not override the code refusal",
           cls(attest_sole_ref(SOLE_REF_CODE, "data", 4, 0, 0)), None)
    _check(res, "map: nor the alignment refusal, isolated to the data "
                "sub-kind (the dispatcher may still fall through to "
                "sole-ref/string for the same address; see below)",
           cls(attest_sole_ref_data(SOLE_REF_MAP_OVERLAY, align=16)), None)

    # --- sole-ref/data outside the loaded regions (2026-09-27) -------------
    # I/O registers are witnessed by the hardware documentation
    # (IO_REGS_ARM9, curated from GBATEK); the unloaded main RAM below the
    # ARM9 image only by an outside object start.  Neither range is a
    # blanket pass.
    _check(res, "io: a documented DSi register start (CAM_CNT 0x04004202, "
                "a2) is accepted",
           cls(attest_sole_ref_data(0x04004202, align=2)), "sole-ref")
    _check(res, "io: a documented DS register start with no declared "
                "alignment (IME 0x04000208) is accepted",
           cls(attest_sole_ref_data(0x04000208)), "sole-ref")
    _check(res, "io: an undocumented 0x04 address is refused",
           cls(attest_sole_ref_data(0x04000FF0)), None)
    _check(res, "io: the interior of a 32-bit register (DISPCNT + 2) is "
                "refused",
           cls(attest_sole_ref_data(0x04000002, align=2)), None)
    _check(res, "io: a declared alignment wider than the register "
                "(0x04004202, a4) is refused",
           cls(attest_sole_ref_data(0x04004202, align=4)), None)
    _check(res, "low RAM: an address below the ARM9 image with no object "
                "start or label is refused",
           cls(attest_sole_ref_data(0x02000800)), None)
    _check(res, "low RAM: an interior ARM9 rodata address under "
                "0x02008000 is refused (no blanket low-area pass)",
           cls(attest_sole_ref_data(SOLE_REF_MAP_BETWEEN, align=4)), None)

    # --- sole-ref/code for overlay labels (2026-09-23) ---------------------
    _check(res, "ov sole-ref/code: an overlay label whose only caller is "
                "inside the range is carried by attest()",
           (attest(OV_CODE_SOLE, "thumb", OV_CODE_SOLE_LO, OV_CODE_SOLE_HI)
            or (None,))[::3], ("sole-ref", "code"))
    _check(res, "ov sole-ref/code: the label rule itself still refuses it",
           cls(attest_overlay_label(OV_CODE_SOLE, "thumb", OV_CODE_SOLE_LO,
                                    OV_CODE_SOLE_HI)), None)
    _check(res, "ov sole-ref/code: a hint naming the labelling overlay "
                "attests",
           cls(attest_sole_ref_overlay_code(OV_CODE_SOLE, "thumb",
                                            OV_CODE_SOLE_REGION)),
           "sole-ref")
    _check(res, "ov sole-ref/code: a hint naming an overlapping overlay "
                "that does not label it is refused",
           cls(attest_sole_ref_overlay_code(OV_CODE_SOLE, "thumb", "ov010")),
           None)
    _check(res, "ov sole-ref/code: code under test in the other overlay "
                "names that overlay's byte, and is refused",
           cls(attest_sole_ref_overlay_code(OV_CODE_SOLE, "thumb",
                                            site_region="ov010")), None)
    _check(res, "ov sole-ref/code: the label's ISA has to be the declared "
                "one",
           cls(attest_sole_ref_overlay_code(OV_CODE_SOLE, "arm")), None)
    _check(res, "ov sole-ref/code: an offset into the function is refused",
           cls(attest_sole_ref_overlay_code(OV_CODE_SOLE + 2, "thumb")),
           None)
    _check(res, "ov sole-ref/code: an address no overlay labels is refused",
           cls(attest(OV_CODE_UNLABELLED, "thumb", 0x02012704, 0x02012798)),
           None)
    _check(res, "ov sole-ref/code: two overlapping overlays labelling it is "
                "ambiguity without a hint",
           cls(attest_sole_ref_overlay_code(OV_CODE_TWICE, "thumb")), None)
    _check(res, "ov sole-ref/code: the hint resolves that ambiguity",
           cls(attest_sole_ref_overlay_code(OV_CODE_TWICE, "thumb",
                                            "ov010")), "sole-ref")

    # --- sole-ref/code for TWL labels (2026-09-24) -------------------------
    # func_0206DC00's two DSi-only callees have no caller outside it, so the
    # `label` rule refuses them and sole-ref/code over asm/twl/twl.s carries
    # them.  Without a key the rule is exercised on an injected label table.
    real_twl = bool(twl_listing_files()) and twl_window() is not None
    saved = (_TWL.get("w"), _FUNC_STARTS.get(TWL_REGION),
             _REGION_CALLS.get(TWL_REGION), TWL_LISTING)
    if not real_twl:
        _TWL["w"] = (0x02700000, 0x02732DA0)
        _FUNC_STARTS[TWL_REGION] = {TWL_FUNC: False, TWL_FUNC2: False}
        _REGION_CALLS[TWL_REGION] = defaultdict(list)
    how = "asm/twl/twl.s" if real_twl else "injected label table, no key"
    lo, hi = TWL_CALLER_LO, TWL_CALLER_HI
    try:
        for a in (TWL_FUNC, TWL_FUNC2):
            _check(res, "twl sole-ref/code: 0x%08X, called only from inside "
                        "the compared range, is carried by attest() (%s)"
                        % (a, how),
                   (attest(a, "arm", lo, hi, region_hint="twl")
                    or (None,))[::3], ("sole-ref", "code"))
        _check(res, "twl sole-ref/code: an interior address (start + 4) is "
                    "refused (%s)" % how,
               cls(attest_sole_ref(TWL_FUNC + 4, "arm", lo=lo, hi=hi,
                                   region_hint="twl")), None)
        _check(res, "twl sole-ref/code: the pool word before the start is "
                    "refused (%s)" % how,
               cls(attest_sole_ref(TWL_POOL, "arm", lo=lo, hi=hi,
                                   region_hint="twl")), None)
        _check(res, "twl sole-ref/code: the label's ISA has to be the "
                    "declared one (%s)" % how,
               cls(attest_sole_ref(TWL_FUNC, "thumb", lo=lo, hi=hi,
                                   region_hint="twl")), None)
        _check(res, "twl sole-ref/code: without the twl token the address "
                    "is not looked up (%s)" % how,
               cls(attest_sole_ref(TWL_FUNC, "arm", lo=lo, hi=hi)), None)
        _check(res, "twl sole-ref/code: an ovNNN hint does not reach the "
                    "twl listing (%s)" % how,
               cls(attest_sole_ref(TWL_FUNC, "arm", lo=lo, hi=hi,
                                   region_hint="ov093")), None)
        _check(res, "twl sole-ref/code: an ARM9 address is not attested via "
                    "the twl token",
               cls(attest_sole_ref_twl_code(TWL_ARM9_ADDR, "arm", "twl")),
               None)
        # No key: the listing path names a file that does not exist.
        _FUNC_STARTS.pop(TWL_REGION, None)
        globals()["TWL_LISTING"] = os.path.join(ROOT, "asm", "twl",
                                                "missing_twl.s")
        _check(res, "twl sole-ref/code: without asm/twl/twl.s (no key) the "
                    "rule refuses",
               cls(attest_sole_ref(TWL_FUNC, "arm", lo=lo, hi=hi,
                                   region_hint="twl")), None)
    finally:
        globals()["TWL_LISTING"] = saved[3]
        for key, val, cache in (("w", saved[0], _TWL),
                                (TWL_REGION, saved[1], _FUNC_STARTS),
                                (TWL_REGION, saved[2], _REGION_CALLS)):
            if val is None:
                cache.pop(key, None)
            else:
                cache[key] = val

    # --- decrypted ov230 (region `ov230d`, 2026-09-24) ----------------------
    # ica_anime's three BLX targets are thunk slots ov230's initialiser
    # decrypts (tools/ovcrypt.py).  Without asm/ov230d/ov230d.s (disasm.py
    # ov230d not run yet) the rule is exercised on an injected label table
    # holding the checked range starts, and the result says which it was.
    import ovcrypt
    real_ovd = bool(ov230d_listing_files())
    saved = (_OV230D.get("v"), _FUNC_STARTS.get(OV230D_REGION),
             _REGION_CALLS.get(OV230D_REGION), _FUNC_STARTS.get("ov230"))
    view = ov230d_view()
    if not real_ovd and view is not None:
        _FUNC_STARTS[OV230D_REGION] = dict(
            [(a, False) for a in view.entry_points()] +
            [(OV230D_PLAIN, False)])
        _REGION_CALLS[OV230D_REGION] = defaultdict(list)
    how = "asm/ov230d/ov230d.s" if real_ovd else "injected label table"
    lo, hi = OV230D_CALLER_LO, OV230D_CALLER_HI
    try:
        _check(res, "ov230d: ovcrypt.py decrypts and checks ov230 and the "
                    "three probe targets are range starts",
               view is not None and all(a in view.entry_points()
                                        for a in OV230D_SLOTS), True)
        for a in OV230D_SLOTS:
            _check(res, "ov230d sole-ref/code: slot 0x%08X, called only from "
                        "inside func_02011D9C, is carried by attest() (%s)"
                        % (a, how),
                   (attest(a, "arm", lo, hi, region_hint="ov230d")
                    or (None,))[::3], ("sole-ref", "code"))
        a = OV230D_SLOTS[0]
        _check(res, "ov230d: an interior address (slot + 4) is refused",
               cls(attest(a + 4, "arm", lo, hi, region_hint="ov230d")), None)
        _check(res, "ov230d: the label's ISA has to be the declared one",
               cls(attest(a, "thumb", lo, hi, region_hint="ov230d")), None)
        _check(res, "ov230d: without a token the decrypted view is not "
                    "looked up",
               cls(attest(a, "arm", lo, hi)), None)
        _check(res, "ov230d: the twl token does not reach it",
               cls(attest(a, "arm", lo, hi, region_hint="twl")), None)
        _check(res, "ov230d: the plain ov230 token (the ROM listing, "
                    "ciphertext there) does not reach it",
               cls(attest(a, "arm", lo, hi, region_hint="ov230")), None)
        _check(res, "ov230d: a hint for an address outside the decrypted "
                    "ranges is refused even where the decrypted listing "
                    "labels real plain code (func_%08X, %s)"
                    % (OV230D_PLAIN, how),
               (scan_listing(OV230D_REGION).get(OV230D_PLAIN),
                cls(attest(OV230D_PLAIN, "arm", lo, hi,
                           region_hint="ov230d"))), (False, None))
        # a label planted on the second-layer ciphertext at ov230's base
        _FUNC_STARTS[OV230D_REGION] = dict(scan_listing(OV230D_REGION))
        _FUNC_STARTS[OV230D_REGION][OV230D_BODY] = False
        _check(res, "ov230d: a label on still-encrypted bytes outside the "
                    "decrypted ranges is refused",
               cls(attest(OV230D_BODY, "arm", lo, hi,
                          region_hint="ov230d")), None)
        # a label on ciphertext in ov230's ROM listing (what a
        # function_starts.txt seed there would create)
        _FUNC_STARTS["ov230"] = dict(scan_listing("ov230"))
        _FUNC_STARTS["ov230"][a] = False
        _check(res, "ov230d: a label on ciphertext in the ROM listing is "
                    "refused by the overlay label and sole-ref/code rules",
               (on_ciphertext("ov230", a),
                cls(attest(a, "arm", lo, hi, region_hint="ov230")),
                cls(attest_overlay_label(a, "arm", 0, 0, "ov230")),
                cls(attest_sole_ref_overlay_code(a, "arm", "ov230"))),
               (True, None, None, None))
        _FUNC_STARTS["ov230"] = saved[3]
        if saved[3] is None:
            _FUNC_STARTS.pop("ov230", None)
        # a slot that fails the clean-function check: the view is refused
        # as a whole and nothing is attested
        real_load = ovcrypt.load

        def _bad_load(root=None, extract_dir=None):
            with open(os.path.join(ROOT, "layout", "layout.json")) as fh:
                o = ovcrypt.overlay_record(json.load(fh))
            with open(os.path.join(ROOT, "extract",
                                   o["decompressed_file"]), "rb") as fh:
                img = bytearray(fh.read())
            off = OV230D_SLOTS[0] - o["ram_start"]
            img[off + 3] ^= 0x0F          # the slot decrypts to garbage
            return ovcrypt.decrypt(bytes(img), o["ram_start"],
                                   ovcrypt.sinit_entries(img, o))
        ovcrypt.load = _bad_load
        _OV230D.pop("v", None)
        try:
            try:
                _bad_load()
                why = "accepted"
            except ovcrypt.CryptError as exc:
                why = ("not a clean ARM function" in str(exc))
            _check(res, "ov230d: a slot failing the clean-function check "
                        "makes ovcrypt refuse, and nothing is attested",
                   (why, ov230d_view(),
                    cls(attest(a, "arm", lo, hi, region_hint="ov230d"))),
                   (True, None, None))
        finally:
            ovcrypt.load = real_load
    finally:
        for key, val, cache in (("v", saved[0], _OV230D),
                                (OV230D_REGION, saved[1], _FUNC_STARTS),
                                (OV230D_REGION, saved[2], _REGION_CALLS),
                                ("ov230", saved[3], _FUNC_STARTS)):
            if val is None:
                cache.pop(key, None)
            else:
                cache[key] = val

    # --- overlay extents end at the real instruction length (2026-09-27) ---
    def _ext_end(name, start):
        for lo_, hi_ in overlay_data_structure(name)[3]:
            if lo_ == start:
                return hi_
        return None
    _check(res, "ov extent: a Thumb function ending in a 2-byte instruction "
                "ends 2 bytes after it, not 4",
           _ext_end("ov010", OV_EXT_THUMB2), OV_EXT_THUMB2_END)
    _check(res, "ov extent: the word right after it is data again",
           in_overlay_data("ov010", OV_EXT_THUMB2_END), True)
    _check(res, "ov extent: its last instruction is still inside the extent",
           in_overlay_data("ov010", OV_EXT_THUMB2_END - 2), False)
    _check(res, "ov extent: an ARM function still ends 4 bytes after its "
                "last instruction",
           _ext_end("ov009", OV_EXT_ARM), OV_EXT_ARM_END)
    _check(res, "ov extent: a Thumb function ending in a 4-byte bl still "
                "ends 4 bytes after it",
           _ext_end("ov009", OV_EXT_BL), OV_EXT_BL_END)
    _check(res, "ov extent: the freed word is the first datum after code, "
                "so the listing's block structure starts an object there",
           OV_EXT_THUMB2_END in overlay_data_structure("ov010")[2], True)
    _check(res, "ov extent: and sole-ref/data attests it for the function "
                "that pools it",
           (attest(OV_EXT_THUMB2_END, "data", OV_EXT_USER_LO,
                   OV_EXT_USER_HI) or (None,))[::3],
           ("sole-ref", "data"))
    _check(res, "ov extent: its last halfword of code is still refused as "
                "data",
           cls(attest_sole_ref_overlay_data(OV_EXT_THUMB2_END - 2, 2)), None)

    # --- sole-ref/data and /self for overlay data (2026-09-23) --------------
    _check(res, "ov sole-ref/data: an overlay pool word outside the range "
                "attests an ov010 object start",
           (attest(OV_DATA_POOLED, "data", 0, 0) or (None,))[::3],
           ("sole-ref", "data"))
    _check(res, "ov sole-ref/data: that start is not in the listing's own "
                "block structure",
           OV_DATA_POOLED in overlay_data_structure("ov010")[2], False)
    _check(res, "ov sole-ref/data: its lone referrer inside the range "
                "leaves no witness",
           cls(attest_sole_ref_overlay_data(OV_DATA_POOLED, 4,
                                            OV_DATA_POOLED_SITE - 0x40,
                                            OV_DATA_POOLED_SITE + 0x40)),
           None)
    # OV_DATA_POOLED + 4 stopped being usable here once ov010's regenerated
    # listing gained a pool word naming it (a pooled address IS an object
    # start); OV_DATA_INTERIOR is a data word with no start and no referrer.
    _check(res, "ov sole-ref/data: an address between starts is refused",
           cls(attest_sole_ref_overlay_data(OV_DATA_INTERIOR)), None)
    _check(res, "ov sole-ref/data: the alignment refusal holds",
           cls(attest_sole_ref_overlay_data(OV_DATA_POOLED, 8)), None)
    _check(res, "ov sole-ref/data: a hint whose window does not hold the "
                "address is refused",
           cls(attest_sole_ref_overlay_data(OV_DATA_POOLED,
                                            region_hint="ov001")), None)
    _check(res, "ov sole-ref/data: un-hinted, a start in one overlay is "
                "refused while an overlapping overlay also holds data there",
           cls(attest_sole_ref_overlay_data(OV_DATA_SHARED)), None)
    # Until seed round 10 this case expected the ov021 hint to attest. ov115
    # now declares its proc table there (layout/data_objects.txt), so two
    # overlays start an object at the address and no hint may choose.
    _check(res, "ov sole-ref/data: an ov115 hint at 0x021D6338 is refused "
                "too, because ov021's listing also starts a block there",
           cls(attest_sole_ref_overlay_data(OV_DATA_SHARED,
                                            region_hint="ov115")), None)
    _check(res, "ov sole-ref/data: an ov021 hint at 0x021D6338 is refused "
                "(ov115's proc table; another overlay in the window also "
                "has an object start there)",
           cls(attest_sole_ref_overlay_data(0x021D6338,
                                            region_hint="ov021")), None)
    _check(res, "ov sole-ref/data: an overlay code address is refused",
           cls(attest_sole_ref_overlay_data(OV_CODE_SOLE,
                                            region_hint="ov009")), None)
    _check(res, "ov sole-ref/data: an ARM9 address is left to the ARM9 "
                "rules",
           cls(attest_sole_ref_overlay_data(SOLE_REF_ANCHOR)), None)
    _check(res, "ov sole-ref/self: the single-pool ov010 table is carried "
                "by ROM-word agreement read from ov010",
           (attest(OV_DATA_SELF, "data", OV_DATA_SELF_LO, OV_DATA_SELF_HI,
                   site=OV_DATA_SELF_SITE, expect=OV_DATA_SELF,
                   site_region="ov010") or (None,))[::3],
           ("sole-ref", "self"))
    _check(res, "ov sole-ref/self: no start rule carries that table",
           cls(attest_sole_ref_overlay_data(OV_DATA_SELF, 4, OV_DATA_SELF_LO,
                                            OV_DATA_SELF_HI,
                                            site_region="ov010")), None)
    _check(res, "ov sole-ref/self: a disagreeing word is refused",
           cls(attest_sole_ref_overlay_self(OV_DATA_SELF, "data",
                                            OV_DATA_SELF_SITE,
                                            OV_DATA_SELF + 4,
                                            site_region="ov010")), None)
    # --- sole-ref/self overlay hint (seed round 10b) ------------------------
    _check(res, "ov sole-ref/self hint: contested ov115 at 0x021D6338 is "
                "accepted when the function loads ov115 (overlay_id 0x73)",
           self_hint_accepted(0x021D6338, "ov115", {115, 123}), True)
    _check(res, "ov sole-ref/self hint: the same hint is refused when the "
                "function loads no ov115",
           self_hint_accepted(0x021D6338, "ov115", {123}), False)
    _check(res, "ov sole-ref/self hint: the rival ov021 hint is refused "
                "without an ov021 load",
           self_hint_accepted(0x021D6338, "ov021", {115}), False)
    _check(res, "ov sole-ref/self hint: contested ov179 at 0x021B68D8 "
                "(func_0202F9F8) stands on its ov179 load",
           self_hint_accepted(0x021B68D8, "ov179", {88, 179}), True)
    _check(res, "ov sole-ref/self hint: and falls without it",
           self_hint_accepted(0x021B68D8, "ov179", {88}), False)
    _check(res, "ov sole-ref/self hint: an uncontested hint needs no load "
                "(0x021D654C, only ov115 starts an object there)",
           self_hint_accepted(0x021D654C, "ov115", set()), True)
    _check(res, "ov sole-ref/self: a code target is refused",
           cls(attest_sole_ref_overlay_self(OV_CODE_SOLE, "data",
                                            OV_CODE_SOLE_LO + 0x74,
                                            OV_CODE_SOLE,
                                            region_hint="ov009")), None)

    # --- matched-overlay (2026-09-23) ---------------------------------------
    _check(res, "matched-overlay: an EXACT ov010 entry attests a call with "
                "the ov010 hint",
           cls(attest_matched(OV_MATCHED, "thumb", OV_MATCHED_CALLER_SRC,
                              OV_MATCHED_REGION)), "matched")
    _check(res, "matched-overlay: and from code under test in ov010",
           cls(attest_matched(OV_MATCHED, "thumb", OV_MATCHED_CALLER_SRC,
                              site_region=OV_MATCHED_REGION)), "matched")
    _check(res, "matched-overlay: and un-hinted, the one overlapping "
                "overlay (ov009) saying nothing is code there",
           cls(attest_matched(OV_MATCHED, "thumb", OV_MATCHED_CALLER_SRC)),
           "matched")
    _check(res, "matched-overlay: a hint naming the other overlay is refused",
           cls(attest_matched(OV_MATCHED, "thumb", OV_MATCHED_CALLER_SRC,
                              "ov009")), None)
    _check(res, "matched-overlay: code under test in the other overlay is "
                "refused",
           cls(attest_matched(OV_MATCHED, "thumb", OV_MATCHED_CALLER_SRC,
                              site_region="ov009")), None)
    _check(res, "matched-overlay: the entry may not witness its own file",
           cls(attest_matched(OV_MATCHED, "thumb", OV_MATCHED_SRC,
                              OV_MATCHED_REGION)), None)
    _check(res, "matched-overlay: the ISA has to be the entry's",
           cls(attest_matched(OV_MATCHED, "arm", OV_MATCHED_CALLER_SRC,
                              OV_MATCHED_REGION)), None)
    _check(res, "matched-overlay: the index records the entry's overlay",
           [w[3] for w in matched_addresses().get(OV_MATCHED, [])],
           [OV_MATCHED_REGION])

    # --- matched-overlay from a scratch copy outside the repo (2026-09-28) ---
    # ov175 0x021DA6B8 measured from a lane's scratchpad left 0x021DC2D8 (an
    # EXACT ov175 entry) "no witness outside" with the ov175 hint, because
    # source_key() gave None for a path outside ROOT and attest_matched()
    # refuses a None source.  Seven overlays share that window.
    ext = source_key(os.path.join(os.path.dirname(ROOT), "elsewhere",
                                  "func_021DA6B8.c"))
    _check(res, "source_key: a file outside the repo gets an external key "
                "no manifest source can equal",
           bool(ext) and ext.startswith(EXTERNAL_SOURCE), True)
    _check(res, "matched-overlay: an EXACT ov175 entry attests a call from "
                "an ov175 scratch copy outside the repo with the ov175 hint",
           cls(attest(OV175_MATCHED, "thumb", OV175_CALLER_LO,
                      OV175_CALLER_HI, ext, "ov175",
                      site_region="ov175")), "matched")
    _check(res, "matched-overlay: the same entry does not attest for a "
                "different overlay (ov119) overlapping the window",
           cls(attest_matched(OV175_MATCHED, "thumb", ext, "ov119",
                              site_region="ov119")), None)
    _check(res, "matched: from an external copy, an entry inside the "
                "compared range never attests",
           cls(attest(OV175_MATCHED, "thumb", OV175_MATCHED,
                      OV175_MATCHED + 0x18, ext, "ov175",
                      site_region="ov175")) == "matched", False)

    # --- two files attesting each other ------------------------------------
    # The pairwise case needs no machinery of its own: a compared range is one
    # translation unit, so a call site in a sibling file is simply outside it.
    # Both witnesses inside one range is what caps such a file at MATCH.
    _check(res, "pairwise: a sibling file's call site is an outside witness",
           cls(attest(OS_GETOWNERRTCOFFSET, "arm", 0x02008B4C, 0x02008C20)),
           "label")
    _check(res, "pairwise: one range holding both call sites leaves the "
                "label class no outside caller, but OS_GetOwnerRtcOffset is "
                "also a catalogued symbols_sdk.json entry, so the `sdk` "
                "class carries it before sole-ref/code is ever tried",
           cls(attest(OS_GETOWNERRTCOFFSET, "arm", 0x02008AEC, 0x02008C20)),
           "sdk")

    # --- the matched class -------------------------------------------------
    # The one class whose witness is not a reading of the image: an EXACT
    # manifest entry, i.e. our own compiled proof of what lives at an address.
    _check(res, "matched: an EXACT entry attests an address no image class "
                "can",
           cls(attest(MATCHED_CALLEE, "thumb", MATCHED_CALLER_LO,
                      MATCHED_CALLER_HI, MATCHED_CALLER_SRC)), "matched")
    _check(res, "matched: no manifest witness without a file under test, "
                "but sole-ref/code still carries the label start itself",
           cls(attest(MATCHED_CALLEE, "thumb", MATCHED_CALLER_LO,
                      MATCHED_CALLER_HI)), "sole-ref")
    _check(res, "matched: an entry may not witness its own source file, but "
                "sole-ref/code does not consult the manifest at all and "
                "still carries the label start",
           cls(attest(MATCHED_CALLEE, "thumb", 0x02000000, 0x03000000,
                      MATCHED_CALLEE_SRC)), "sole-ref")
    _check(res, "matched: the entry's ISA has to be the declared ISA",
           cls(attest(MATCHED_CALLEE, "arm", MATCHED_CALLER_LO,
                      MATCHED_CALLER_HI, MATCHED_CALLER_SRC)), None)
    _check(res, "matched: the class never applies to data",
           cls(attest_matched(MATCHED_CALLEE, "data", MATCHED_CALLER_SRC)),
           None)
    _check(res, "matched: a unit entry attests the member functions its "
                "layout records",
           cls(attest(MATCHED_MEMBER, "thumb", 0x02000000, 0x03000000,
                      MATCHED_CALLER_SRC)), "matched")
    _check(res, "matched: not even a member address witnesses its own file, "
                "but it is still a traced label start for sole-ref/code",
           cls(attest(MATCHED_MEMBER, "thumb", 0x02000000, 0x03000000,
                      MATCHED_MEMBER_SRC)), "sole-ref")
    _check(res, "matched: an EXACT entry covers its address and every "
                "function of its layout",
           sorted(matched_index([_matched_fixture()])),
           [0x0BADF000, 0x0BADF010])
    _check(res, "matched: a MATCH-status entry is not a witness",
           matched_index([_matched_fixture(status="MATCH")]), {})
    _check(res, "matched: an EXACT* entry is one",
           sorted(matched_index([_matched_fixture(status="EXACT*")])),
           [0x0BADF000, 0x0BADF010])
    _check(res, "matched: a kind that is not verified against game bytes is "
                "refused",
           matched_index([_matched_fixture(kind="note")]), {})
    _check(res, "runtime kind: a runtime entry's covered rows are matched "
                "witnesses like a unit's members",
           sorted(matched_index([dict(_matched_fixture(kind="runtime"),
                                      functions=["__fsub", "__fadd"],
                                      covers=["0x0BADF000", "0x0BADF020"])])),
           [0x0BADF000, 0x0BADF020])
    try:
        import worklist as _wl
        _rt_row = min(runtime_addresses())
        _ent = {"name": "__rt", "address": "0x%08X" % _rt_row,
                "kind": "runtime", "region": "arm9", "status": "EXACT",
                "functions": ["__rt"], "covers": ["0x%08X" % _rt_row]}
        _cov = _wl.cover_from_entries([_ent], MATCHED_STATUS)
        _fn = {"addr": _rt_row}
        _wl.classify(_fn, _cov, {}, set(), [], runtime_addresses())
        _check(res, "runtime kind: worklist files a runtime entry's row as "
                    "runtime with a matched name, never as game",
               (_fn.get("cls"), "matched_name" in _fn), ("runtime", True))
        _fn2 = {"addr": _rt_row}
        _wl.classify(_fn2, _wl.cover_from_entries(
            [dict(_ent, kind="game")], MATCHED_STATUS), {}, set(), {},
            runtime_addresses())
        _check(res, "runtime kind: the same row filed as game would enter the "
                    "game figure, which is why match.py never files it so",
               _fn2.get("cls"), "matched")
        _check(res, "runtime kind: an unverified runtime entry covers nothing",
               _wl.cover_from_entries([dict(_ent, status="unverified")],
                                      MATCHED_STATUS), {})

        # SDK interior label (owner decision 2026-09-28): credited to its
        # parent only when the parent's EXACT/EXACT* entry compared bytes
        # past the label (compared_bytes, written by entry_from_source).
        _pext = [(0x0BADF000, 0x0BADF100, "SDK_Parent")]
        _pent = {"name": "SDK_Parent", "address": "0x0BADF000",
                 "kind": "sdk", "region": "arm9", "status": "EXACT",
                 "compared_bytes": 0x100}

        def _interior(ent, label=0x0BADF040):
            f = {"addr": label}
            cov = _wl.cover_from_entries([ent], MATCHED_STATUS)
            _wl.classify(f, cov, {}, set(), _pext, {})
            return (f.get("cls"), f.get("matched_name"),
                    f.get("matched_interior", False))
        _check(res, "sdk interior: a label the parent's EXACT entry compared "
                    "past is credited to the parent",
               _interior(_pent), ("sdk", "SDK_Parent+0x40", True))
        _check(res, "sdk interior: an EXACT* parent credits it the same way",
               _interior(dict(_pent, status="EXACT*")),
               ("sdk", "SDK_Parent+0x40", True))
        _check(res, "sdk interior: a compared range that stops at the label "
                    "leaves it open",
               _interior(dict(_pent, compared_bytes=0x40)),
               ("sdk", None, False))
        _check(res, "sdk interior: a parent entry with no compared_bytes "
                    "leaves it open",
               _interior({k: v for k, v in _pent.items()
                          if k != "compared_bytes"}), ("sdk", None, False))
        _check(res, "sdk interior: an unverified parent leaves it open",
               _interior(dict(_pent, status="unverified")),
               ("sdk", None, False))
        _check(res, "sdk interior: a MATCH parent leaves it open",
               _interior(dict(_pent, status="MATCH")), ("sdk", None, False))
    except ImportError:
        _check(res, "runtime kind: tools/worklist.py importable", False, True)
    # manifest --check: one address claimed twice in one region is a
    # duplicate whatever the two entries' name or kind; overlays that share a
    # load address are not.
    _dg = {"name": "func_0BADF000", "address": "0x0BADF000", "kind": "game",
           "region": "arm9", "source": "src/matched/arm9/func_0BADF000.c"}
    _check(res, "manifest check: two entries for one address that differ only "
                "in kind (game vs sdk) are a duplicate",
           sorted(manifest_duplicates([
               ("a.json", {"functions": [_dg]}),
               ("b.json", {"functions": [dict(_dg, kind="sdk")]})])),
           [("arm9", "0x0BADF000")])
    _check(res, "manifest check: two entries for one address that differ in "
                "name and source are a duplicate",
           sorted(manifest_duplicates([
               ("a.json", {"functions": [_dg, dict(
                   _dg, name="OS_Thing", source="src/matched/arm9/x.c")]})])),
           [("arm9", "0x0BADF000")])
    _check(res, "manifest check: a unit entry at a function entry's address "
                "is a duplicate",
           sorted(manifest_duplicates([
               ("a.json", {"functions": [_dg]}),
               ("b.json", {"functions": [dict(_dg, kind="game_unit",
                                              name="unit_x",
                                              functions=["func_0BADF000"])]})])),
           [("arm9", "0x0BADF000")])
    _check(res, "manifest check: one address in two overlay regions is not a "
                "duplicate",
           manifest_duplicates([
               ("a.json", {"functions": [dict(_dg, region="ov016")]}),
               ("b.json", {"functions": [dict(_dg, region="ov093")]})]), {})
    _check(res, "manifest check: distinct addresses are not a duplicate",
           manifest_duplicates([
               ("a.json", {"functions": [
                   _dg, dict(_dg, address="0x0BADF004")]})]), {})
    _rt_hdr = {"address": "0x%08X" % min(runtime_addresses()),
               "function": runtime_addresses()[min(runtime_addresses())],
               "region": "arm9", "isa": "arm", "unit": "yes"}
    _check(res, "runtime kind: a src/matched file at a runtime_arm9.txt row "
                "is filed as runtime, never game or game_unit",
           entry_from_source("x.c", _rt_hdr, "game", "src/matched/x.c")["kind"],
           "runtime")
    _check(res, "runtime kind: any other arm9 address stays game",
           entry_from_source("x.c", dict(_rt_hdr, address="0x02008534",
                                         unit="no", function="sub_02008534"),
                             "game", "src/matched/x.c")["kind"], "game")

    # --- compare(): a wildcarded byte that happens to match is not EXACT --
    # The real case (see sub_02049800 / func_0204982C): an unresolved PC24
    # target one byte past the function's own extent can encode a branch
    # displacement the compiler's own guess and the image agree on by plain
    # adjacency, with no witness for the target ever having been found.
    # Byte equality alone must not be read as "every byte was verified".
    def cmp_case(data, mask, tgt):
        fb = FuncBytes("cmp_selftest", data, bytearray(mask), True, ".text", [])
        return compare(fb, tgt)[0]

    _check(res, "compare: fully hard bytes that match are EXACT",
           cmp_case(b"\xAA\xBB\xCC\xDD", [1, 1, 1, 1], b"\xAA\xBB\xCC\xDD"),
           "EXACT")
    _check(res, "compare: a wildcarded byte that happens to equal the image "
                "is capped at MATCH, adjacency is not attestation",
           cmp_case(b"\xAA\xBB\xCC\xDD", [1, 1, 0, 1], b"\xAA\xBB\xCC\xDD"),
           "MATCH")
    _check(res, "compare: a wildcarded byte still lets a hard mismatch fail "
                "the entry",
           cmp_case(b"\xAA\xBB\xCC\xDD", [1, 1, 0, 1], b"\x00\xBB\xCC\xDD"),
           "DIFF")

    # --- the declared ISA of a call target ---------------------------------
    def conflict(addr, kind):
        return (isa_conflict(addr, kind) or (None, None))[0]

    _check(res, "isa: a func_ label is read as the ISA of its address",
           isa_evidence(FUNC_LABELLED)[0], "thumb")
    _check(res, "isa: a veneer is ARM by construction",
           isa_evidence(VENEER)[0], "arm")
    _check(res, "isa: an overlay label carries an ISA too",
           isa_evidence(OVERLAY_FUNC)[0], "thumb")
    _check(res, "isa: a declaration the evidence agrees with is no conflict",
           conflict(FUNC_LABELLED, "thumb"), None)
    _check(res, "isa: a thumb declaration against ARM evidence conflicts",
           conflict(VENEER, "thumb"), "arm")
    _check(res, "isa: an arm declaration against Thumb evidence conflicts",
           conflict(FUNC_LABELLED, "arm"), "thumb")
    _check(res, "isa: a data declaration is not an ISA claim",
           conflict(FUNC_LABELLED, "data"), None)
    _check(res, "isa: an address the image says nothing about has no evidence",
           isa_evidence(ISA_UNEVIDENCED), None)
    _check(res, "isa: a call whose declared ISA conflicts is refused",
           _call_refused(VENEER, "thumb"), True)
    # --- which overlay answers for a shared address ------------------------
    def isa_of(*a):
        return (isa_evidence(*a) or (None,))[0]

    _check(res, "isa: the site's own region answers by its own SDK row ahead "
                "of another overlay's label (ov175 row vs ov119 label)",
           isa_of(ISA_OWN_SDK, ISA_OWN_SDK_REGION), "arm")
    _check(res, "isa: that SDK row is looked up per region, not by address",
           (sdk_region_isa(ISA_OWN_SDK_REGION, ISA_OWN_SDK),
            sdk_region_isa(ISA_OWN_SDK_OTHER, ISA_OWN_SDK)), (False, None))
    _check(res, "isa: the real ov175 call declared arm now resolves",
           _resolve_one_call(ISA_OWN_SDK, "arm",
                             region=ISA_OWN_SDK_REGION).resolved, True)
    _check(res, "isa: the same call declared thumb is refused",
           _call_refused(ISA_OWN_SDK, "thumb", region=ISA_OWN_SDK_REGION),
           True)
    _check(res, "isa: another overlay's label still answers when the site's "
                "region has neither and the hint names that overlay",
           isa_of(ISA_OWN_SDK, ISA_OWN_SDK_NEITHER,
                        ISA_OWN_SDK_OTHER), "thumb")
    _check(res, "isa: a hint naming an overlay with neither label nor row "
                "leaves the ISA unevidenced; neither the site region's row "
                "nor another overlay's label answers for it",
           isa_evidence(ISA_OWN_SDK, ISA_OWN_SDK_REGION, ISA_OWN_SDK_NEITHER),
           None)
    _check(res, "isa: the hinted overlay's label governs over another "
                "overlay's label (ov021 Thumb thunk vs ov009 ARM label)",
           isa_of(ISA_HINTED, ISA_HINTED_SITE, ISA_HINTED_OVERLAY),
           "thumb")
    _check(res, "isa: without the hint the first labelling overlay answers",
           isa_of(ISA_HINTED, ISA_HINTED_SITE), "arm")
    _check(res, "isa: a hint whose window does not hold the address is not "
                "a hint",
           isa_of(ISA_HINTED, ISA_HINTED_SITE, ISA_HINT_OUTSIDE),
           "arm")
    _check(res, "isa: the hinted call declared thumb resolves, declared arm "
                "is refused",
           (_resolve_one_call(ISA_HINTED, "thumb", hint=ISA_HINTED_OVERLAY,
                              region=ISA_HINTED_SITE).resolved,
            _call_refused(ISA_HINTED, "arm", hint=ISA_HINTED_OVERLAY,
                          region=ISA_HINTED_SITE)), (True, True))
    _check(res, "isa: a call whose declared ISA agrees resolves unremarked",
           (lambda s: (s.resolved, s.note))(
               _resolve_one_call(FUNC_LABELLED, "thumb")), (True, ""))
    _check(res, "isa: a call the image cannot check resolves with a note",
           (lambda s: (s.resolved, bool(s.note)))(
               _resolve_one_call(ISA_UNEVIDENCED, "thumb")), (True, True))
    _check(res, "isa: an ARM bl/blx into a declared Thumb target encodes "
                "BLX(immediate), the real 0x02091180 -> 0x02004490 site",
           (lambda fb: (fb.sites[0].resolved, "%08X" % struct.unpack_from(
               "<I", fb.data, 0)[0]))(
               _resolve_one_arm_call(ARM_TO_THUMB_CALLEE, "thumb")),
           (True, "FAFDCCC2"))
    _check(res, "isa: an ARM bl into a same-ISA ARM target still encodes a "
                "plain B-family displacement",
           (lambda fb: fb.sites[0].resolved)(
               _resolve_one_arm_call(VENEER, "arm")), True)

    # --- the overlay_id class -------------------------------------------
    _check(res, "overlay_id: a valid overlay index loaded into the id "
                "register of a loader resolves",
           _resolve_ovid(0x14), (True, "overlay_id"))
    _check(res, "overlay_id: a valid overlay index is refused when the "
                "function calls no loader",
           _resolve_ovid(0x14, callee=FUNC_LABELLED, callee_kind="thumb"),
           (False, ""))
    _check(res, "overlay_id: a word no pc-relative load addresses is not a "
                "pool word and is refused",
           _resolve_ovid(0x14, id_off=16), (False, ""))
    _check(res, "overlay_id: a value past the last overlay in the layout "
                "is refused",
           _resolve_ovid(OVID_PAST_LAST), (False, ""))
    _check(res, "overlay_id: the value past the last overlay is really past "
                "it", OVID_PAST_LAST > max(overlay_ids()), True)
    _check(res, "overlay_id: an id loaded into the wrong register for the "
                "loader is refused",
           _resolve_ovid(0x14, code=bytes.fromhex("0149 024B 1847 C046")),
           (False, ""))
    _check(res, "overlay_id: an id register overwritten before the call is "
                "refused",
           _resolve_ovid(0x14, code=bytes.fromhex("0148 024B 0020 1847")),
           (False, ""))
    # The long walk (2026-09-27): `ldr r0, [pc, #0x24]; ldr r3, [pc,
    # #0x28]`, sixteen `str r1, [r5, #0x64]` (no general register written),
    # then `bx r3`: 18 steps from the load to the call.
    _long = "0948 0A4B" + " 6966" * 16 + " 1847 C046"
    _check(res, "overlay_id: a walk longer than the old 8-step bound, all "
                "modelled stores, resolves",
           _resolve_ovid(0x14, code=bytes.fromhex(_long), id_off=0x28,
                         callee_off=0x2C), (True, "overlay_id"))
    _check(res, "overlay_id: on the long walk an id register clobbered "
                "just before the call is still refused",
           _resolve_ovid(0x14, code=bytes.fromhex(
               "0948 0A4B" + " 6966" * 15 + " 0020 1847 C046"),
               id_off=0x28, callee_off=0x2C), (False, ""))
    _check(res, "overlay_id: a walk past OVERLAY_ID_WALK steps is refused",
           _resolve_ovid(0x14, code=bytes.fromhex(
               "1048 114B" + " 6966" * 30 + " 1847 C046"),
               id_off=0x44, callee_off=0x48), (False, ""))
    _check(res, "overlay_id: func_020124AC takes the id in r1",
           OVERLAY_ID_CONSUMERS[0x020124AC][1], 1)

    # --- vendor-object rules: linker, template, section-relative .bss -----
    fslo, fshi = 0x02078D34, 0x02078EB0          # FS_LoadOverlayInfo
    solo, sohi = 0x0207902C, 0x02079164          # FS_StartOverlay
    thlo, thhi = 0x02085264, 0x020853B0          # OS_InitThread
    _check(res, "linker: SDK_OVERLAY_NUMBER at FS_LoadOverlayInfo+0x174 is "
                "layout.json's overlay count (0xED)",
           cls(attest_linker(fslo, 0x174, "SDK_OVERLAY_NUMBER", 0xED, 0,
                             fslo, fshi)), "linker")
    _check(res, "linker: a declared value the layout does not derive (0xEC) "
                "is refused",
           attest_linker(fslo, 0x174, "SDK_OVERLAY_NUMBER", 0xEC, 0,
                         fslo, fshi), None)
    _check(res, "linker: a slot the vendor object relocates against another "
                "symbol (FSiOverlayContext at +0x170) is refused",
           attest_linker(fslo, 0x170, "SDK_OVERLAY_NUMBER", 0xED, 0,
                         fslo, fshi), None)
    _check(res, "linker: SDK_LTDAUTOLOAD_LTDMAIN_START / _BSS_END are "
                "layout.json twl ram_start / bss_end",
           (cls(attest_linker(solo, 0x120, "SDK_LTDAUTOLOAD_LTDMAIN_START",
                              0x02700000, 0, solo, sohi)),
            cls(attest_linker(solo, 0x124, "SDK_LTDAUTOLOAD_LTDMAIN_BSS_END",
                              0x02735B40, 0, solo, sohi))),
           ("linker", "linker"))
    _check(res, "linker: the twl bound swapped between the two slots is "
                "refused",
           attest_linker(solo, 0x120, "SDK_LTDAUTOLOAD_LTDMAIN_START",
                         0x02735B40, 0, solo, sohi), None)
    got = attest_linker(thlo, 0x120, "SDK_SYS_STACKSIZE", 0x1800, 0,
                        thlo, thhi)
    _check(res, "linker: SDK_SYS_STACKSIZE in OS_InitThread is witnessed by "
                "OS_GetInitArenaHi's slot 0x02086684 (os_arena.o relocates "
                "the same symbol)",
           got[:3] if got else None, ("linker", 1, 0x02086684))
    _check(res, "linker: a value the other slots do not hold (0x1000) is "
                "refused",
           attest_linker(thlo, 0x120, "SDK_SYS_STACKSIZE", 0x1000, 0,
                         thlo, thhi), None)
    _check(res, "linker: the other row's slot inside the compared range is "
                "not a witness",
           attest_linker(thlo, 0x120, "SDK_SYS_STACKSIZE", 0x1800, 0,
                         0x02086594, 0x020866A0), None)
    _check(res, "linker: a name outside SDK_* (OSi_ThreadInfo) never "
                "qualifies",
           attest_linker(thlo, 0x118, "OSi_ThreadInfo", 0x02150FEC, 4,
                         thlo, thhi), None)
    _check(res, "linker: a function with no located SDK row (game "
                "sub_02005E50) is refused",
           attest_linker(0x02005E50, 0x10, "SDK_OVERLAY_NUMBER", 0xED, 0,
                         0x02005E50, 0x02005E70), None)
    hmlo = 0x020816FC                           # MATH_CalcHMACSHA1
    _check(res, "template: @12151 of dgt_sha1.o is the 28 bytes at "
                "0x020A5CB8, uniquely",
           cls(attest_template(hmlo, 0x84, 0x020A5CB8, 0)), "template")
    _check(res, "template: a declared address 4 bytes off is refused",
           attest_template(hmlo, 0x84, 0x020A5CBC, 0), None)
    _check(res, "template: our compile's template differing from the "
                "member's is refused",
           attest_template(hmlo, 0x84, 0x020A5CB8, 0,
                           ours=bytes.fromhex("10000000" "40000000") + bytes(20)), None)
    _check(res, "template: a slot the member relocates against a function "
                "(MATH_SHA1Init at +0x88) is refused",
           attest_template(hmlo, 0x88, 0x020A5CB8, 0), None)
    # overlay templates (2026-09-29)
    gslo = 0x02194614                           # ov009 ClosePendingCallbacks
    _check(res, "template/ov: @14079 of gstats.o is the 16 bytes at "
                "0x021A1A54 in ov009, uniquely",
           cls(attest_template(gslo, 0xD4, 0x021A1A54, 0, region="ov009")),
           "template")
    _check(res, "template/ov: @13818 of gstats.o (256 bytes) at 0x021A1A64 "
                "in ov009, uniquely",
           cls(attest_template(0x02193F00, 0xC0, 0x021A1A64, 0,
                               region="ov009")), "template")
    _check(res, "template/ov: the same overlay row with no region named is "
                "refused (an overlay is never guessed from the address)",
           attest_template(gslo, 0xD4, 0x021A1A54, 0), None)
    _check(res, "template/ov: an address 16 bytes off (another ov009 datum) "
                "is refused",
           attest_template(gslo, 0xD4, 0x021A1A64, 0, region="ov009"), None)
    _check(res, "template/ov: our compile's template differing from the "
                "member's is refused",
           attest_template(gslo, 0xD4, 0x021A1A54, 0, region="ov009",
                           ours=bytes(16)), None)
    evlo, cblo = 0x021C99D0, 0x021C9B64         # ov114 dwc_encsession.o
    _check(res, "template/ov (b): @16077 at 0x021CE1B8; the other copy "
                "0x021CE1CC is @16117 at CompleteCallback's slot",
           cls(attest_template(evlo, 0x184, 0x021CE1B8, 0, region="ov114")),
           "template")
    _check(res, "template/ov (b): @16117 at 0x021CE1CC by the converse "
                "elimination",
           cls(attest_template(cblo, 0x224, 0x021CE1CC, 0, region="ov114")),
           "template")
    _check(res, "template/ov (b): @16077 declared at the copy @16117 "
                "claims is refused",
           attest_template(evlo, 0x184, 0x021CE1CC, 0, region="ov114"), None)
    _check(res, "template/ov (b): with the claiming slot inside the "
                "compared range, the other copy is unclaimed: refused",
           attest_template(evlo, 0x184, 0x021CE1B8, 0, region="ov114",
                           lo=evlo, hi=cblo + 0x238), None)
    _check(res, "template/ov: the right row named in the wrong overlay "
                "(ov009) is refused",
           attest_template(evlo, 0x184, 0x021CE1B8, 0, region="ov009"), None)
    _check(res, "template/ov: `linker` stays ARM9-only (no vendor row "
                "for an overlay place)",
           vendor_function(evlo, "ov114"), None)
    lklo, lkhi = 0x02084B90, 0x02084C1C          # OS_InitLock
    got = attest_section_rel(lklo, 0x80, ".bss", 0x02150FCC, 0, lklo, lkhi)
    _check(res, ".bss: os_spinlock.o's .bss+0 at 0x02150FCC is named and "
                "keeps attest()'s witness",
           got[0][0] if got else None, "sole-ref")
    _check(res, ".bss: a base outside the ARM9 static .bss is refused",
           attest_section_rel(lklo, 0x80, ".bss", 0x020A5CB8, 0,
                              lklo, lkhi), None)
    _check(res, ".bss: an addend the member does not use is refused",
           attest_section_rel(lklo, 0x80, ".bss", 0x02150FCC, 4,
                              lklo, lkhi), None)
    _check(res, ".bss: a slot the member relocates against a function is "
                "refused",
           attest_section_rel(lklo, 0x44, ".bss", 0x02150FCC, 0,
                              lklo, lkhi), None)
    _check(res, "symbols: `@N` and `.bss` lines parse, `.text` does not",
           (bool(SYMBOL_RE.match(" *   @12151  0x020A5CB8  data")),
            bool(SYMBOL_RE.match(" *   .bss    0x02150FCC  data")),
            bool(SYMBOL_RE.match(" *   .text   0x02000000  data"))),
           (True, True, False))
    _check(res, "function_starts: 0x02004EA8 (crt0 bx lr stub) is a traced "
                "ARM function start",
           evidence().labels.get(0x02004EA8), False)

    # --- stale split listings ---------------------------------------------
    with tempfile.TemporaryDirectory() as tmp:
        os.makedirs(os.path.join(tmp, "asm", "arm9", "src"))
        os.makedirs(os.path.join(tmp, "layout"))
        for name in ("000_02000000.s", "000_02000004.s"):
            with open(os.path.join(tmp, "asm", "arm9", "src", name), "w") as fh:
                fh.write("func_%s:" % name[4:12] + chr(10))
        with open(os.path.join(tmp, "layout", "units_arm9.json"), "w") as fh:
            json.dump({"units": [{"file": "asm/arm9/src/000_02000000.s"}]}, fh)
        _check(res, "listings: a stale split file absent from units_arm9.json "
                    "is not read, so its bogus label cannot cut an extent",
               [os.path.basename(f) for f in unit_files("src",
                                                         "units_arm9.json", tmp)],
               ["000_02000000.s"])

    # --- the three documented end-to-end behaviours -----------------------
    if not args.quick:
        res += _selftest_resolution()
        res += _selftest_overlay_id()

    bad = [r for r in res if not r[0]]
    for ok, name, got, want in res:
        print("  %-4s %s" % ("ok" if ok else "FAIL", name))
        if not ok:
            print("       got %r, want %r" % (got, want))
    print("\n%d case(s), %d failure(s)" % (len(res), len(bad)))
    return 1 if bad else 0


_SELFTEST_SRC = """\
/*
 * selftest fixture, compiled from a string; not part of the tree.
 * symbols:
 *   sub_02005E50_Obj  %s  data
 */
typedef unsigned int u32;
struct S { u32 unk00; u32 unk04; u32 unk08; };
extern struct S sub_02005E50_Obj;

int sub_02005E50(void)
{
    return sub_02005E50_Obj.unk08 != 0;
}
"""


def _selftest_resolution():
    """declared right -> EXACT, declared wrong -> DIFF, unknown -> MATCH.

    These are the three behaviours docs/MATCHING.md claims for the resolver,
    run end to end through the compiler against a function whose single ABS32
    the `literal` class carries.
    """
    cases = [
        ("0x020AA260", "EXACT", "resolver: the declared address is right"),
        # Another address the literal class attests, so it resolves and then
        # has to fail the byte comparison.  This is the case that proves
        # resolution does not make matching easier to pass.
        ("0x020AA1AC", "DIFF", "resolver: a wrong but attested address "
                               "still fails"),
        # Nothing in the image names this, so the field stays a wildcard.
        ("0x020AFFF0", "MATCH", "resolver: an unattested address stays a "
                                "wildcard"),
    ]
    out = []
    work = tempfile.mkdtemp(prefix="bwself_")
    try:
        for addr_text, want, name in cases:
            src = os.path.join(work, "selftest.c")
            with open(src, "w", newline="\n") as fh:
                fh.write(_SELFTEST_SRC % addr_text)
            r = run_one(src, "sub_02005E50", 0x02005E50, "1.1p1", ["-O4,p"],
                        True, "c99", region="arm9")
            _check(out, name, r.status, want)
    finally:
        shutil.rmtree(work, ignore_errors=True)
    return out


def cmd_show(args):
    """Disassemble the original bytes at an address, as a writing aid."""
    addr = parse_addr(args.addr)
    reg = find_region(addr, args.region)
    size, thumb = target_extent(addr, reg.name)
    if args.size:
        size = parse_addr(args.size)
    if size is None:
        size = 0x40
    if args.thumb:
        thumb = True
    if args.arm:
        thumb = False
    _n, data = target_bytes(addr, size, region=reg.name)
    print("%s %08X..%08X (%d bytes, %s)"
          % (reg.name, addr, addr + size, size, "Thumb" if thumb else "ARM"))
    for a, sz, txt in disasm(data, addr, bool(thumb)):
        off = a - addr
        print("  %08X  %-12s %s" % (a, data[off:off + sz].hex(" "), txt))
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="command", required=True)

    def common(p):
        p.add_argument("--src", required=True, help="C/C++ translation unit")
        p.add_argument("--func", required=True, help="function symbol to extract")
        p.add_argument("--addr", required=True, help="target address, e.g. 0x02075DD8")
        p.add_argument("--region", help="region name; inferred from the address by default")
        p.add_argument("--thumb", action="store_true", help="force Thumb")
        p.add_argument("--arm", action="store_true", help="force ARM")
        p.add_argument("--lang", help="-lang value (c99, c++, ...)")
        p.add_argument("--no-sdk-include", action="store_true",
                       help="do not add -I sdk/TwlSDK/include")

    p1 = sub.add_parser("one", help="one compiler configuration")
    common(p1)
    p1.add_argument("--cc", default="1.1p1", help="compiler dir under dsi/")
    p1.add_argument("--flags", default="-O4,p", help="optimisation flags")
    p1.add_argument("--diff", action="store_true", help="always print the diff")
    p1.add_argument("--keep", action="store_true")

    p2 = sub.add_parser("sweep", help="all compilers crossed with flag variants")
    common(p2)
    p2.add_argument("--cc", help="comma-separated subset of compiler dirs")
    p2.add_argument("--extra", action="store_true", help="add inline/ipa variants")
    p2.add_argument("--cpp", action="store_true", help="also sweep -lang c++")
    p2.add_argument("--json", help="write the full matrix here")

    p5 = sub.add_parser("tu", help="compare a whole translation unit against a byte range")
    p5.add_argument("--src", required=True, help="C/C++ translation unit")
    p5.add_argument("--addr", required=True, help="address the unit starts at")
    p5.add_argument("--region")
    p5.add_argument("--thumb", action="store_true")
    p5.add_argument("--arm", action="store_true")
    p5.add_argument("--lang")
    p5.add_argument("--no-sdk-include", action="store_true")
    p5.add_argument("--cc", default="1.1p1")
    p5.add_argument("--flags", default="-O4,p")
    p5.add_argument("--diff", action="store_true")
    p5.add_argument("--keep", action="store_true")
    p5.add_argument("--suggest-split", action="store_true",
                    dest="suggest_split",
                    help="report which re-cuts of this range would give "
                         "every relocation a witness outside it; writes "
                         "nothing")

    p3 = sub.add_parser("manifest",
                        help="rebuild the layout/matched/ shards from src/")
    p3.add_argument("--verify", action="store_true",
                    help="recompile each entry and record the live status")
    p3.add_argument("--shard", metavar="ID",
                    help="act on one shard only, e.g. pkt_0209CE10 or "
                         "arm9/legacy; this is what a packet agent runs")
    p3.add_argument("--migrate", action="store_true",
                    help="one-time move from layout/matched.json to the "
                         "shards, then delete the old file")
    p3.add_argument("--check", action="store_true",
                    help="report duplicate manifest entries and shard json "
                         "files that shard_files() does not read")
    p3.add_argument("--force", action="store_true",
                    help="re-verify all entries even if unchanged on disk")
    p3.add_argument("-j", "--jobs", type=int, default=os.cpu_count() or 4,
                    help="parallel verification workers (default: all cores)")

    p6 = sub.add_parser("idioms",
                        help="regenerate the docs/idioms index in docs/MATCHING.md")
    p6.add_argument("--check", action="store_true",
                    help="report whether the index is stale, write nothing")

    p7 = sub.add_parser("selftest",
                        help="exercise attest() and the relocation resolver")
    p7.add_argument("--quick", action="store_true",
                    help="skip the cases that invoke the compiler")

    p4 = sub.add_parser("show", help="disassemble the original bytes at an address")
    p4.add_argument("--addr", required=True)
    p4.add_argument("--size")
    p4.add_argument("--region")
    p4.add_argument("--thumb", action="store_true")
    p4.add_argument("--arm", action="store_true")

    args = ap.parse_args(argv)
    return {"one": cmd_one, "sweep": cmd_sweep, "tu": cmd_tu,
            "manifest": cmd_manifest, "show": cmd_show,
            "idioms": cmd_idioms, "selftest": cmd_selftest}[args.command](args)


if __name__ == "__main__":
    sys.exit(main())
