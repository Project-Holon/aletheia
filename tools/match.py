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
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile
from collections import defaultdict

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

SDK_INCLUDE = os.path.join(ROOT, "sdk", "TwlSDK", "include")

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
                 "locals", "sites")

    def __init__(self, name, data, mask, thumb, section, relocs, locals_=None):
        self.name = name
        self.data = data        # bytes as the compiler emitted them
        self.mask = mask        # bytearray, 1 = concrete, 0 = linker-rewritten
        self.thumb = thumb
        self.section = section
        self.relocs = relocs    # list of (offset, type, symbol name, addend)
        self.locals = locals_ or {}   # symbol -> offset within self.data
        self.sites = []         # filled in by resolve_relocations()

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
    return FuncBytes(name, blob, mask, thumb, obj.secnames[shndx], rels,
                     locals_)


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


def listing_files(region):
    if region == "arm9":
        d = os.path.join(ROOT, "asm", "arm9", "src")
    elif region.startswith("arm9_autoload0"):
        d = os.path.join(ROOT, "asm", "arm9", "src_itcm")
    elif region.startswith("ov"):
        p = os.path.join(ROOT, "asm", "overlays", "ov%s.s" % region[2:])
        return [p] if os.path.exists(p) else []
    else:
        return []
    if not os.path.isdir(d):
        return []
    return [os.path.join(d, f) for f in sorted(os.listdir(d)) if f.endswith(".s")]


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
                    elif s.startswith("loc_") and s.endswith(":"):
                        pending_thumb = None
        except OSError:
            continue
    _FUNC_STARTS[region] = starts
    return starts


def target_extent(addr, region):
    """(size, thumb) of the original function, or (None, None) if unknown."""
    starts = scan_listing(region)
    if addr not in starts:
        return None, None
    thumb = starts[addr]
    later = sorted(a for a in starts if a > addr)
    size = (later[0] - addr) if later else None
    return size, thumb


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
# Six classes of evidence are accepted, and the class is reported per site so
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
#            .thumb_func, or a recognised veneer); `sole-ref/string` (the
#            start of a NUL-terminated printable run, even when the preceding
#            object is a table rather than a string); `sole-ref/self` (the
#            target is in a data section and the ROM word at the site already
#            names it -- relocation agreement is the proof).  See
#            attest_sole_ref().
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
    out = []
    for sub in ("src", "src_itcm"):
        d = os.path.join(ROOT, "asm", "arm9", sub)
        if os.path.isdir(d):
            out += [os.path.join(d, f) for f in sorted(os.listdir(d))
                    if f.endswith(".s")]
    return out


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


def overlay_label(addr):
    """(region, thumb) if an overlay's own listing labels `addr`, else None."""
    for name in regions_containing(addr):
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


def attest_overlay_label(addr, kind, lo, hi, region_hint=None):
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
    if region_hint is not None:
        if region_hint not in candidates:
            return None
        pool = [region_hint]
    else:
        pool = candidates
    labeled = [name for name in pool
               if scan_listing(name).get(addr) == (kind == "thumb")]
    if len(labeled) != 1:
        return None
    sites = [s for s in image_call_sites(addr) if not lo <= s < hi]
    if not sites:
        return None
    return "label", len(sites), sites[0]


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


def names_known_code(value):
    """True when `value` is an interworking pointer at a known function."""
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
    known = sdk_addresses().get(target)
    if known is not None:
        return known == thumb
    found = overlay_label(target)
    if found is not None:
        return found[1] == thumb
    return False


def veneer_at(addr):
    """(size, pointer word address, target) if `addr` is an ARM veneer."""
    if addr & 3:
        return None
    region = _region_at(addr)
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
    if value is None or not names_known_code(value):
        return None
    if (value & ~1) == addr:
        return None
    return size, addr + ptr_off, value


def attest_veneer(addr, kind, lo, hi):
    """The `veneer` class.  Returns (class, witnesses, site) or None."""
    if kind != "arm":
        return None
    found = veneer_at(addr)
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


def sdk_addresses():
    """{address: (name, thumb)} from layout/symbols_sdk.json, the inverse of
    sdk_symbols().  Kept separately because attest_sdk() looks a call or
    ABS32 *target* up by address, the same direction runtime_addresses()
    already looks runtime_arm9.txt up in.
    """
    if "a" in _SDK_ADDRS:
        return _SDK_ADDRS["a"]
    out = {}
    for name, (addr, thumb) in sdk_symbols().items():
        out.setdefault(addr, (name, thumb))
    _SDK_ADDRS["a"] = out
    return out


def attest_sdk(addr, kind):
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
    found = sdk_addresses().get(addr)
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
        out.setdefault(e["name"], (int(e["address"], 16), e["isa"] == "thumb"))
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
    guess.  See attest_overlay_label().
    """
    out = {}
    for line in fields.get("symbols_lines", []):
        parts = line.split()
        if len(parts) not in (3, 4):
            raise SystemExit(
                "bad symbols: line %r (want 'name 0xADDR kind [overlay]')"
                % line)
        if len(parts) == 3:
            name, addr, kind = parts
            extra = None
        else:
            name, addr, kind, extra = parts
        if kind not in ("thumb", "arm", "data"):
            raise SystemExit("bad symbol kind %r for %s" % (kind, name))
        region = align = None
        if extra is not None:
            if re.match(r"^a[0-9]+$", extra):
                # the declared type's alignment, which the `sole-ref` class
                # checks the address against
                align = int(extra[1:])
                if align not in (1, 2, 4, 8, 16):
                    raise SystemExit(
                        "bad alignment %r for %s: want a1/a2/a4/a8/a16"
                        % (extra, name))
            else:
                region = extra
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

def isa_evidence(addr):
    """("thumb"/"arm", where) the image says `addr` is, or None.

    Three readings, strongest first: a func_ label in a generated listing,
    the ARM shape of a linker veneer, and the ISA flag of a recovered SDK
    symbol.  None of these is an attestation of the ADDRESS -- that is
    attest()'s job -- they only say what is at it if anything is.
    """
    th = evidence().labels.get(addr)
    if th is not None:
        return ("thumb" if th else "arm"), \
            "the func_%08X label in asm/arm9" % addr
    found = overlay_label(addr)
    if found is not None:
        region, th = found
        return ("thumb" if th else "arm"), \
            "the func_%08X label in %s" % (addr, region)
    if veneer_at(addr) is not None:
        return "arm", "the ARM linker veneer at %08X" % addr
    th = sdk_addresses().get(addr)
    if th is not None:
        return ("thumb" if th else "arm"), "layout/symbols_sdk.json"
    return None


def isa_conflict(addr, kind):
    """(image isa, where) when the image contradicts `kind`, else None."""
    if kind not in ("thumb", "arm"):
        return None
    found = isa_evidence(addr)
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


def attest_string(addr, lo, hi):
    """The `string` class.  Returns (class, witnesses, site) or None.

    See the commentary above for the seven conditions; each one of them is a
    separate `return None` here so that a reader can check them off.
    """
    region = None
    for r in load_all_regions():
        if r.base <= addr < r.base + len(r.data):
            region = r
            break
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

    # (6) neither run may be code
    for lbl in evidence().labels:
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

def attest_data_table(addr, lo, hi):
    """The `data_table` class.  Returns (class, witnesses, site) or None."""
    if addr & 3:
        return None
    ev = evidence()
    if addr in ev.labels:
        return None
    if not (ev.pool_words.get(addr) or ev.pool_words.get(addr | 1)):
        return None
    regions = load_all_regions()
    region = None
    for r in regions:
        if r.base <= addr < r.base + len(r.data):
            region = r
            break
    if region is None:
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
            try:
                addr = int(parts[1], 16)
            except ValueError:
                continue
            ev = parts[3].rstrip("\n") if len(parts) > 3 else ""
            sites = [int(m, 16) for m in _MAP_SITE_RE.findall(ev)]
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


def attest_sole_ref_data(addr, align=None, lo=0, hi=0):
    """The `sole-ref/data` sub-kind.  Returns (class, witnesses, site) or None.

    This is the original (wave-20) `sole-ref` rule, unchanged: see conditions
    (a), (b) and (c) in the commentary above.  Condition (b) is satisfied
    either by the listings' own block structure (data_object_starts()) or by
    layout/data_objects.txt, and in the latter case only on evidence outside
    `lo`..`hi`.
    """
    # (a) inside a data section, never code
    region = _region_at(addr)
    in_bss = bool(bss_addresses_probe(addr))
    if region is None and not in_bss:
        return None
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


def attest_sole_ref_code(addr, kind):
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
    if kind == "arm" and veneer_at(addr) is not None:
        return "sole-ref", 1, addr, "code"
    return None


def attest_sole_ref_string(addr, lo, hi):
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
    """
    region = _region_at(addr)
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
    if not in_data_section(addr):
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


def attest_sole_ref_self(addr, kind, site=None, expect=None):
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
    if not in_data_section(addr):
        return None
    word = rom_word_at(site)
    if word is None or word != (expect & 0xFFFFFFFF):
        return None
    return "sole-ref", 1, addr, "self"


def attest_sole_ref(addr, kind, align=None, lo=0, hi=0,
                    site=None, expect=None):
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
    """
    if kind == "data":
        proof = attest_sole_ref_data(addr, align, lo, hi)
        if proof is not None:
            return proof
        proof = attest_sole_ref_string(addr, lo, hi)
        if proof is not None:
            return proof
        return attest_sole_ref_self(addr, kind, site, expect)
    if kind in ("thumb", "arm"):
        return attest_sole_ref_code(addr, kind)
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

MATCHED_KINDS = ("game", "game_unit", "sdk_calibration")
MATCHED_STATUS = ("EXACT", "EXACT*")


def matched_index(entries):
    """{address: (entry name, source, isa)} for the EXACT entries given.

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
        who = (e["name"], e.get("source", ""), isa)
        addrs = [int(e["address"], 16)]
        # A unit entry records the functions its compared range covered; each
        # of those addresses is pinned by the same byte comparison.
        for n in e.get("functions") or []:
            m = _ADDR_NAME_RE.match(n)
            if m:
                addrs.append(int(m.group(1), 16))
        for a in addrs:
            out.setdefault(a, who)
    return out


_MATCHED_AT = {}


def matched_addresses():
    """matched_index() over every manifest shard."""
    if "a" not in _MATCHED_AT:
        _MATCHED_AT["a"] = matched_index(load_manifest_entries())
    return _MATCHED_AT["a"]


def source_key(path):
    """A source path spelled the way the manifest records it, or None."""
    if not path:
        return None
    try:
        rel = os.path.relpath(os.path.abspath(path), ROOT)
    except ValueError:          # another drive on Windows
        return None
    rel = rel.replace("\\", "/")
    return None if rel.startswith("../") else rel


def attest_matched(addr, kind, src=None):
    """The `matched` class.  Returns (class, witnesses, site) or None.

    `src` is the source file under test, in manifest spelling.  Without it
    self-reference cannot be checked, so the class refuses outright rather
    than risk an entry witnessing itself.
    """
    if kind not in ("thumb", "arm"):
        return None
    if src is None:
        return None
    found = matched_addresses().get(addr)
    if found is None:
        return None
    _name, source, isa = found
    if source == src:
        return None             # an entry may not witness its own file
    if isa != kind:
        return None
    return "matched", 1, addr


def attest(addr, kind, lo, hi, src=None, region_hint=None, align=None,
           site=None, expect=None):
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
    consults them, and without them that sub-kind refuses.
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
            proof = attest_overlay_label(addr, kind, lo, hi, region_hint)
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
        proof = attest_sdk(addr, kind)
        if proof is not None:
            return proof
    want = addr | 1 if kind == "thumb" else addr
    sites = [s for s in ev.pool_words.get(want, ()) if not lo <= s < hi]
    if sites:
        return "literal", len(sites), sites[0]
    if kind == "arm":
        proof = attest_veneer(addr, kind, lo, hi)
        if proof is not None:
            return proof
    if kind == "data":
        proof = attest_string(addr, lo, hi)
        if proof is not None:
            return proof
        proof = attest_data_table(addr, lo, hi)
        if proof is not None:
            return proof
    # Last, because it is the one class that is not a reading of the original
    # image: our own compiled proof that the target address holds a function
    # we already reproduced byte for byte.
    proof = attest_matched(addr, kind, src)
    if proof is not None:
        return proof
    # Last of all, after every other class has failed: the layout's own
    # statement that a data object, a traced function or a printable string
    # begins at this address.  See "the `sole-ref` class" above.  Every kind
    # is tried here, code included: sole-ref/code exists for exactly the
    # function pointers and single-caller callees that never reach `label`.
    proof = attest_sole_ref(addr, kind, align, lo, hi, site, expect)
    if proof is not None:
        return proof
    return None


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


def resolve_relocations(fb, place, decls, size=None, src=None):
    """Fill in every relocation of `fb` whose target we can attest.

    `place` is the address the code is being compared at, so a site at
    offset o would be linked at place + o.  Sites that resolve have their
    mask bytes turned back on, so the byte comparison covers them; sites
    that do not keep their wildcards and record why.  `src` is the source
    file under test, in manifest spelling: the `matched` class needs it to
    refuse an entry that would witness its own file.
    """
    data = bytearray(fb.data)
    mask = bytearray(fb.mask)
    lo, hi = place, place + (size if size is not None else len(fb.data))
    sites = []
    for off, rtype, name, addend in fb.relocs:
        st = Site(off, rtype, name, addend)
        sites.append(st)
        place_at = place + off

        if name in fb.locals:
            target = place + fb.locals[name]
            kind = "thumb" if fb.thumb else "arm"
            st.cls = "local"
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
                found = isa_evidence(target)
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
                           self_site, self_expect)
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
                            src=source_key(src))
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
                            src=source_key(src))
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
                out.setdefault(int(m.group(1), 16), (e["name"], e["source"]))
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


def suggest_split(src, addr, tl, fb, decls):
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
        proof = attest(target, kind, lo, hi, source_key(src))
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
                      declared_symbols(read_header(args.src)))
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


SYMBOL_RE = re.compile(
    r"^\s*\*\s+([A-Za-z_][A-Za-z0-9_]*)\s+(0[xX][0-9A-Fa-f]+)\s+"
    r"(thumb|arm|data)(?:\s+(ov\d{3}|a\d{1,2}))?\s*$")
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


SRC_DIRS = [("src/calib", "sdk_calibration"), ("src/matched", "game")]

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
            key = (e["address"], e.get("kind", ""), e["name"])
            if key in seen:
                raise SystemExit(
                    "manifest shards disagree: %s is in both %s and %s"
                    % (e["name"], os.path.relpath(seen[key], ROOT),
                       os.path.relpath(path, ROOT)))
            seen[key] = path
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
    status = h.get("status", "")
    if verify:
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
    if is_unit:
        entry["functions"] = names
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


def cmd_manifest(args):
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

    for key, items in sorted(meta.items()):
        if only is not None and key not in only:
            continue
        for path, header, kind, rel in items:
            by_shard[key].append(
                entry_from_source(path, header, kind, rel, verify=args.verify))

    written = write_shards(
        {k: v for k, v in by_shard.items() if only is None or k in only},
        only=only)

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
            if args.verify and e["status"] != "EXACT":
                bad += 1
    if args.verify and bad:
        print("\n%d entr(ies) are not EXACT" % bad, file=sys.stderr)
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
OVERLAY_FUNC_REGION = "ov093"
# A candidate overlay of OVERLAY_FUNC's address window that does NOT label
# it, for exercising a region_hint that resolves to nothing.
OVERLAY_FUNC_WRONG_REGION = "ov016"

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
MATCHED_CALLEE_SRC = "src/matched/sub_02018DB4.c"
MATCHED_CALLER_SRC = "src/matched/unit_02017E1C.c"
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
MATCHED_MEMBER_SRC = "src/matched/unit_0200B67C.c"


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


def _resolve_one_call(addr, kind, place=0x02008000):
    """Resolve a lone Thumb BL whose target is declared `addr` / `kind`.

    Four bytes of code and one R_ARM_THM_CALL, built by hand rather than
    compiled: the point is the resolver's treatment of the declaration, not
    the code around the call.
    """
    name = "isa_selftest_callee"
    fb = FuncBytes("isa_selftest_caller", b"\x00\xF0\x00\xF8",
                   bytearray(b"\x01\x01\x00\x00"), True, ".text",
                   [(0, R_ARM_THM_CALL, name, -4)])
    decls = {name: Decl(name, addr, kind, "header")}
    return resolve_relocations(fb, place, decls)[0]


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


def _call_refused(addr, kind):
    """True when resolving such a call fails loudly instead of encoding it."""
    try:
        _resolve_one_call(addr, kind)
    except SystemExit:
        return True
    return False


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
                "callee too",
           cls(attest(OVERLAY_FUNC, "thumb", 0x02000000, 0x03000000)), None)
    _check(res, "label: an overlay address no overlay labels is refused",
           cls(attest(OVERLAY_THUMB_THUNK, "thumb", 0, 0)), None)
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

    # --- the three documented end-to-end behaviours -----------------------
    if not args.quick:
        res += _selftest_resolution()

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
