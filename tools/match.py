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
    p = os.path.join(ROOT, "tools", "mwccarm", "mwccarm", "dsi", version, "mwccarm.exe")
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
    try:
        p = subprocess.run(cmd, cwd=workdir, capture_output=True, timeout=180, env=env)
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
# Four classes of evidence are accepted, and the class is reported per site so
# a reader can weigh them separately:
#
#   label    disasm.py put a func_XXXXXXXX label at that address, i.e. it
#            traced real code there, AND some branch elsewhere in the image
#            calls that label.  This is the strong class: the address exists
#            in the listings independently of any literal.  "Elsewhere in the
#            image" means the whole image: a branch from an overlay into
#            arm9_main is the same kind of evidence as one from arm9_main,
#            and a leaf whose callers all live in overlays is not less of a
#            function for it.  See xregion_calls().
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
#   local    the symbol is defined inside the object we just compiled, so its
#            address follows from where we placed the translation unit.  No
#            image evidence is involved at all.
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

    __slots__ = ("name", "addr", "kind", "origin")

    def __init__(self, name, addr, kind, origin):
        self.name = name
        self.addr = addr
        self.kind = kind        # "thumb", "arm" or "data"
        self.origin = origin    # "header" or "name"


def declared_symbols(fields):
    """Parse the `symbols:` block of a matched source file's header."""
    out = {}
    for line in fields.get("symbols_lines", []):
        parts = line.split()
        if len(parts) != 3:
            raise SystemExit("bad symbols: line %r (want 'name 0xADDR kind')"
                             % line)
        name, addr, kind = parts
        if kind not in ("thumb", "arm", "data"):
            raise SystemExit("bad symbol kind %r for %s" % (kind, name))
        out[name] = Decl(name, int(addr, 0), kind, "header")
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
#   3. immediately before `addr` there are k NUL bytes, 1 <= k <= 4: one
#      terminator plus at most three bytes of alignment padding;
#   4. `addr` is where that padding rule has to land, i.e. k == 1 (packed) or
#      `addr` is the first 4-aligned address after the terminator.  Without
#      this the previous terminator would fix a range of candidate starts
#      rather than one address;
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

MIN_STRING_CHARS = 4
MAX_STRING_PAD = 4          # terminator plus at most three alignment bytes
MAX_STRING_BYTES = 256      # a longer run is a text blob, not a literal


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
    """Length of the printable ASCII run ending at `off` inclusive."""
    n = 0
    while off - n >= 0 and n <= MAX_STRING_BYTES:
        b = data[off - n]
        if b < 0x20 or b > 0x7E:
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

    # (4) the padding rule has to put the string exactly here
    prev_nul = addr - k
    if k > 1 and addr != ((prev_nul + 1 + 3) & ~3):
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


def attest(addr, kind, lo, hi):
    """Independent evidence for `addr`, or None.

    `lo`..`hi` is the byte range under comparison; a witness inside it does
    not count, because that is the range whose contents the resolved value
    is about to be checked against.  Returns (class, witness_count,
    example_site).
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
    want = addr | 1 if kind == "thumb" else addr
    sites = [s for s in ev.pool_words.get(want, ()) if not lo <= s < hi]
    if sites:
        return "literal", len(sites), sites[0]
    if kind == "data":
        proof = attest_string(addr, lo, hi)
        if proof is not None:
            return proof
    return None


# ---------------------------------------------------------------------------
# relocation resolution
# ---------------------------------------------------------------------------

class Site:
    """One relocation site after an attempt to resolve it."""

    __slots__ = ("off", "rtype", "name", "addend", "resolved", "value",
                 "cls", "witnesses", "witness", "reason")

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

    def describe(self):
        what = "%s %s" % (RELOC_NAMES.get(self.rtype, "r%d" % self.rtype),
                          self.name)
        if self.resolved:
            return "+%04X %-28s -> %08X  [%s%s]" % (
                self.off, what, self.value, self.cls,
                (" x%d, e.g. %08X" % (self.witnesses, self.witness))
                if self.witnesses else "")
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


def _encode_arm_branch(data, off, place, target, addend):
    """Write an ARM B/BL displacement.  X = (S + A) - P, field = X >> 2.

    The addend mwccarm writes carries the ARM PC bias (-8) the same way the
    Thumb one carries -4, so no further bias is applied here.  Interworking
    the other way (an ARM BL whose target is Thumb becomes BLX) is not
    implemented: no matched entry needs it yet, and a site it cannot encode
    stays wildcarded rather than being guessed at.
    """
    word = struct.unpack_from("<I", data, off)[0]
    disp = (target + addend) - place
    if disp & 3 or disp < -(1 << 25) or disp >= (1 << 25):
        return False
    struct.pack_into("<I", data, off,
                     (word & 0xFF000000) | ((disp >> 2) & 0xFFFFFF))
    return True


def resolve_relocations(fb, place, decls, size=None):
    """Fill in every relocation of `fb` whose target we can attest.

    `place` is the address the code is being compared at, so a site at
    offset o would be linked at place + o.  Sites that resolve have their
    mask bytes turned back on, so the byte comparison covers them; sites
    that do not keep their wildcards and record why.
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
            proof = attest(target, kind, lo, hi)
            if proof is None:
                st.reason = ("%08X (%s, from %s) has no witness outside "
                             "%08X..%08X" % (target, kind, origin, lo, hi))
                continue
            st.cls, st.witnesses, st.witness = proof

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
            ok = (kind != "thumb"
                  and _encode_arm_branch(data, off, place_at, target, addend))
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
    """EXACT / MATCH / DIFF plus the list of differing offsets."""
    if len(fb.data) != len(tgt):
        return "SIZE", []
    hard = [i for i in range(len(tgt)) if fb.mask[i] and fb.data[i] != tgt[i]]
    if hard:
        return "DIFF", hard
    if fb.data == tgt:
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
        resolve_relocations(fb, addr, declared_symbols(read_header(src)))
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
        resolve_relocations(fake, addr, declared_symbols(read_header(src)))
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
    r"(thumb|arm|data)\s*$")
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
                        " ".join(m.groups()))
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
    _check(res, "label: every witness inside the compared range is refused",
           cls(attest(FUNC_LABELLED, "thumb", 0x02000000, 0x03000000)), None)

    # --- the cross-region label class ------------------------------------
    _check(res, "label: a bl from another region attests the target",
           cls(attest(FUNC_XREGION, "thumb", 0x02008828, 0x020089A8)), "label")
    _check(res, "label: an image-wide compared range refuses even those",
           cls(attest(FUNC_XREGION, "thumb", 0x02000000, 0x03000000)), None)

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
