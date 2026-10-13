#!/usr/bin/env python3
"""SDK library identification and symbol recovery.

Reads the CodeWarrior-built static libraries under ``sdk/``, turns every
function-sized symbol into a relocation-masked byte pattern, and looks those
patterns up in the decompressed ARM9 image and overlays produced by
``tools/delink.py``.

Nothing here is derived from another decompilation project: the archives are
Unix ``ar``, the members are ELF32 little-endian ARM relocatables, and both
formats are read with a minimal reader written for this file.

Usage:

    python tools/libmatch.py scan            # full run, writes layout/symbols_sdk.txt
    python tools/libmatch.py variants        # per-variant-family match counts only
    python tools/libmatch.py anchors         # report the known anchor addresses

Outputs (addresses and symbol names only, no game bytes):

    layout/symbols_sdk.txt     address, name, library(member), region
    layout/symbols_sdk.json    same plus the per-library summary
"""

from __future__ import annotations

import argparse
import json
import os
import re
import struct
import sys
import time
from collections import defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# ---------------------------------------------------------------------------
# ar
# ---------------------------------------------------------------------------

AR_MAGIC = b"!<arch>\n"


def read_archive(path):
    """Yield (member_name, member_bytes) for a Unix ar archive.

    Handles the GNU long-name table (``//`` plus ``/<offset>`` references),
    the BSD ``#1/<len>`` form and the plain trailing-slash names CodeWarrior
    emits.  Symbol-table members (``/``, ``__.SYMDEF``) are skipped.
    """
    with open(path, "rb") as fh:
        data = fh.read()
    if not data.startswith(AR_MAGIC):
        return
    pos = len(AR_MAGIC)
    longnames = b""
    while pos + 60 <= len(data):
        hdr = data[pos:pos + 60]
        if hdr[58:60] not in (b"`\n", b"`\x00"):
            # Not a valid header; give up rather than resync blindly.
            break
        raw_name = hdr[0:16].decode("latin1")
        try:
            size = int(hdr[48:58].decode("latin1").strip() or "0")
        except ValueError:
            break
        body = data[pos + 60:pos + 60 + size]
        pos += 60 + size + (size & 1)

        name = raw_name.rstrip()
        if name in ("/", "__.SYMDEF", "__.SYMDEF SORTED", "/SYM64/"):
            continue
        if name == "//":
            longnames = body
            continue
        if name.startswith("/") and name[1:].isdigit():
            off = int(name[1:])
            end = longnames.find(b"/\n", off)
            if end < 0:
                end = longnames.find(b"\0", off)
            name = longnames[off:end].decode("latin1")
        elif name.startswith("#1/"):
            nlen = int(name[3:])
            name = body[:nlen].rstrip(b"\0").decode("latin1")
            body = body[nlen:]
        name = name.rstrip("/")
        if not name:
            continue
        yield name, body


# ---------------------------------------------------------------------------
# ELF32
# ---------------------------------------------------------------------------

SHT_PROGBITS = 1
SHT_SYMTAB = 2
SHT_STRTAB = 3
SHT_RELA = 4
SHT_NOBITS = 8
SHT_REL = 9

STT_OBJECT = 1
STT_FUNC = 2

# Relocation widths, in bytes of the encoded field that the linker rewrites.
# Types are the ARM ELF ABI numbers; the value is how many bytes of the
# 4-byte word at the relocation offset have to be wildcarded.
RELOC_MASK = {
    1: (0, 3),    # R_ARM_PC24         low 24 bits of the word
    2: (0, 4),    # R_ARM_ABS32
    3: (0, 4),    # R_ARM_REL32
    5: (0, 2),    # R_ARM_ABS16
    8: (0, 1),    # R_ARM_ABS8
    10: (0, 4),   # R_ARM_THM_CALL (THM_PC22)  both halfwords
    15: (0, 3),   # R_ARM_XPC25
    16: (0, 4),   # R_ARM_THM_XPC22
    28: (0, 3),   # R_ARM_CALL
    29: (0, 3),   # R_ARM_JUMP24
    30: (0, 4),   # R_ARM_THM_JUMP24
}
RELOC_DEFAULT = (0, 4)

# ARM BL relocations whose top byte the linker may rewrite.  An unconditional
# ARM ``bl`` (0xEB) to a Thumb target is turned into ``blx imm`` by the linker,
# which sets the top byte to 0xFA or 0xFB (the H bit carries imm bit 1).  The
# TwlSDK code in the ARM9 static image calls ARM code, so it never shows this;
# TwlDWC libraries in the overlays call Thumb-built libraries and do.  That
# byte is checked against exactly these three values, never wildcarded.
BL_RELOCS = (1, 28)        # R_ARM_PC24, R_ARM_CALL
# Relocations whose field is a branch displacement: the image target can be
# decoded from the linked instruction (ARM b/bl/blx, Thumb bl/blx pair).
ARM_BRANCH_RELOCS = (1, 15, 28, 29)
THM_BRANCH_RELOCS = (10, 16)
BRANCH_RELOCS = ARM_BRANCH_RELOCS + THM_BRANCH_RELOCS
BL_TOP = 0xEB
BLX_TOPS = bytes((0xEB, 0xFA, 0xFB))


class Obj:
    """A parsed ELF32 relocatable object."""

    __slots__ = ("name", "data", "sections", "secnames", "symbols", "ok")

    def __init__(self, name, data):
        self.name = name
        self.data = data
        self.sections = []
        self.secnames = []
        self.symbols = []
        self.ok = False
        try:
            self._parse()
            self.ok = True
        except Exception:
            self.ok = False

    def _parse(self):
        d = self.data
        if d[:4] != b"\x7fELF" or d[4] != 1 or d[5] != 1:
            raise ValueError("not ELF32 LE")
        e_machine, = struct.unpack_from("<H", d, 18)
        if e_machine != 40:
            raise ValueError("not EM_ARM")
        e_shoff, = struct.unpack_from("<I", d, 32)
        e_shentsize, e_shnum, e_shstrndx = struct.unpack_from("<HHH", d, 46)
        secs = []
        for i in range(e_shnum):
            secs.append(struct.unpack_from("<IIIIIIIIII", d, e_shoff + i * e_shentsize))
        self.sections = secs
        shstr = self._strtab(secs[e_shstrndx])
        self.secnames = [cstr(shstr, s[0]) for s in secs]
        # (name, value, size, type, bind, shndx) for every symbol-table row
        si = self.symtab_index()
        if si >= 0:
            symsec = secs[si]
            strtab = self._strtab(secs[symsec[6]])
            for i in range(symsec[5] // 16):
                nameoff, value, size, info, _other, shndx = struct.unpack_from(
                    "<IIIBBH", d, symsec[4] + i * 16)
                self.symbols.append((cstr(strtab, nameoff), value, size,
                                     info & 0xF, info >> 4, shndx))

    def _strtab(self, sec):
        return self.data[sec[4]:sec[4] + sec[5]]

    def section_data(self, idx):
        s = self.sections[idx]
        if s[1] == SHT_NOBITS:
            return b""
        return self.data[s[4]:s[4] + s[5]]

    def symtab_index(self):
        for i, s in enumerate(self.sections):
            if s[1] == SHT_SYMTAB:
                return i
        return -1


def cstr(tab, off):
    end = tab.find(b"\0", off)
    if end < 0:
        return tab[off:].decode("latin1")
    return tab[off:end].decode("latin1")


# ---------------------------------------------------------------------------
# pattern extraction
# ---------------------------------------------------------------------------

# .ltdmain: the TWL-only code section of the TwlSDK HYB/LTD libraries
CODE_SECTION_RE = re.compile(r"^\.(text|itcm|init|dtcm|ltdmain)")


class Pattern:
    __slots__ = ("name", "data", "runs", "thumb", "size", "concrete", "key", "klen",
                 "koff", "alts", "order", "glob", "refs", "refobjs", "span")

    def __init__(self, name, data, runs, thumb, alts=()):
        self.name = name
        self.data = data
        self.runs = runs          # list of (offset, bytes) concrete runs
        self.alts = tuple(alts)   # offsets of BL top bytes: one of BLX_TOPS
        self.thumb = thumb
        self.size = len(data)
        self.concrete = sum(len(b) for _, b in runs) + len(self.alts)
        self.key = None
        self.klen = 0
        self.koff = 0
        self.order = (0, 0)       # (section index, offset) in the source object
        self.glob = True          # STB_GLOBAL: defined once per link, so once per region
        self.refs = []            # named references, one tuple per source
                                  # object (see build_patterns and collect)
        self.refobjs = []         # per refs entry: the member names using it
        self.span = 0             # code bytes of the whole source object


def inplace_addend(body, off, rtype):
    """The addend a REL relocation keeps in the instruction or word, as the
    offset from the symbol that the reference reaches; None if not decoded."""
    if off + 4 > len(body):
        return None
    if rtype == 2:
        return struct.unpack_from("<i", body, off)[0]
    if rtype in ARM_BRANCH_RELOCS:
        imm = struct.unpack_from("<I", body, off)[0] & 0xFFFFFF
        if imm & 0x800000:
            imm -= 0x1000000
        return (imm << 2) + 8
    if rtype in THM_BRANCH_RELOCS:
        h1, h2 = struct.unpack_from("<HH", body, off)
        v = ((h1 & 0x7FF) << 12) | ((h2 & 0x7FF) << 1)
        if v & 0x400000:
            v -= 0x800000
        return v + 4
    return None


def section_symbol_at(syms, shndx, offset):
    """The named function or object symbol of section shndx that covers
    offset (an exact start first), or None."""
    best = None
    for sym in syms:
        name, value, size, typ, bind, sh = sym
        if sh != shndx or typ not in (STT_FUNC, STT_OBJECT) or not name:
            continue
        if value == offset:
            return sym
        if value <= offset < value + size and best is None:
            best = sym
    return best


def build_patterns(obj, want_data=False):
    """Return a list of Pattern for the function symbols of one object."""
    si = obj.symtab_index()
    if si < 0:
        return []
    symsec = obj.sections[si]
    strtab = obj._strtab(obj.sections[symsec[6]])
    nsyms = symsec[5] // 16
    symbase = symsec[4]
    d = obj.data

    syms = []
    for i in range(nsyms):
        nameoff, value, size, info, other, shndx = struct.unpack_from(
            "<IIIBBH", d, symbase + i * 16)
        syms.append((cstr(strtab, nameoff), value, size, info & 0xF, info >> 4, shndx))

    # Mapping symbols ($a / $t / $d) per section, to tell ARM from Thumb.
    mapping = defaultdict(list)
    for name, value, size, typ, bind, shndx in syms:
        if name in ("$a", "$t", "$d") and shndx < len(obj.sections):
            mapping[shndx].append((value, name))
    for v in mapping.values():
        v.sort()

    # Relocation offsets per target section, with the symbol and the addend
    # (RELA: explicit; REL: kept in place, read when the reference is used).
    relocs = defaultdict(list)
    for s in obj.sections:
        if s[1] not in (SHT_RELA, SHT_REL):
            continue
        target = s[7]
        entsz = 12 if s[1] == SHT_RELA else 8
        if s[9]:
            entsz = s[9]
        base = s[4]
        for j in range(s[5] // entsz):
            off, info = struct.unpack_from("<II", d, base + j * entsz)
            addend = None
            if s[1] == SHT_RELA:
                addend, = struct.unpack_from("<i", d, base + j * entsz + 8)
            relocs[target].append((off, info & 0xFF, info >> 8, addend))

    # Code bytes of the object: its functions sit within this many bytes of
    # each other once linked (used by the static-data test in Checker).
    span = sum(obj.sections[i][5] for i, n in enumerate(obj.secnames)
               if obj.sections[i][1] == SHT_PROGBITS and CODE_SECTION_RE.match(n))

    out = []
    for name, value, size, typ, bind, shndx in syms:
        if typ != STT_FUNC and not (want_data and typ == STT_OBJECT):
            continue
        if size == 0 or not name or name.startswith("$"):
            continue
        if shndx == 0 or shndx >= len(obj.sections):
            continue
        sec = obj.sections[shndx]
        if sec[1] != SHT_PROGBITS:
            continue
        secname = obj.secnames[shndx]
        if typ == STT_FUNC and not CODE_SECTION_RE.match(secname):
            continue
        body = obj.section_data(shndx)
        if value + size > len(body):
            continue
        blob = bytearray(body[value:value + size])
        mask = bytearray(b"\x01" * size)   # 1 = concrete, 0 = wildcard

        alts = []
        refs = []
        for off, rtype, symi, addend in relocs.get(shndx, ()):
            if off < value or off >= value + size:
                continue
            if not 0 < symi < len(syms):
                continue
            rname, rv, _rs, rtyp, rbind, rsh = syms[symi]
            if addend is None:
                addend = inplace_addend(body, off, rtype)
            elif rtype in ARM_BRANCH_RELOCS:
                addend += 8                 # RELA: S + A - P, A = -8 for "S"
            elif rtype in THM_BRANCH_RELOCS:
                addend += 4
            if rtyp == 3 and addend is not None:
                # Section symbol plus offset: name the symbol defined there
                # (CodeWarrior reaches statics this way), and keep the
                # addend relative to that symbol.
                hit = section_symbol_at(syms, rsh, addend)
                if hit is None:
                    continue
                rname, rv, _rs, rtyp, rbind, rsh = hit
                addend -= rv
            if not rname or rname.startswith("$") or rtyp == 3:
                continue
            # (offset in function, type, name, local, kind, addend)
            # kind: "func" for a defined function or any branch, "data" for
            # a defined data object, "" for an undefined symbol.
            if rtype in BRANCH_RELOCS or rtyp == STT_FUNC:
                kind = "func"
            elif rtyp == STT_OBJECT and rsh != 0:
                kind = "data"
            else:
                kind = ""
            refs.append((off - value, rtype, rname, rbind == 0, kind, addend or 0))
            lo, width = RELOC_MASK.get(rtype, RELOC_DEFAULT)
            start = off - value + lo
            for k in range(start, min(start + width, size)):
                if k >= 0:
                    mask[k] = 0
            top = off - value + 3
            if rtype in BL_RELOCS and top < size and blob[top] == BL_TOP:
                mask[top] = 0
                alts.append(top)

        thumb = False
        maps = mapping.get(shndx)
        if maps:
            cur = None
            for mv, mn in maps:
                if mv <= value and mn in ("$a", "$t"):
                    cur = mn
                elif mv > value:
                    break
            thumb = (cur == "$t")

        runs = []
        i = 0
        while i < size:
            if mask[i]:
                j = i
                while j < size and mask[j]:
                    j += 1
                runs.append((i, bytes(blob[i:j])))
                i = j
            else:
                i += 1
        pat = Pattern(name, bytes(blob), runs, thumb, sorted(set(alts)))
        pat.order = (shndx, value)
        pat.glob = bind == 1      # STB_LOCAL statics and weak symbols may repeat
        pat.refs = [tuple(refs)]
        pat.refobjs = [{obj.name}]
        pat.span = span
        out.append(pat)
    return out


# ---------------------------------------------------------------------------
# library discovery / variant classification
# ---------------------------------------------------------------------------

VARIANT_TOKENS = ("TWL.HYB", "TWL.LTD", "TWL", "NTR")


def classify(path):
    """Return (tree, build, variant, thumb, libname) for an archive path."""
    rel = os.path.relpath(path, os.path.join(ROOT, "sdk")).replace("\\", "/")
    parts = rel.split("/")
    tree = parts[0]
    build = ""
    for p in parts:
        if p in ("Debug", "Release", "Rom"):
            build = p
    base = os.path.basename(path)
    stem = base[:-2] if base.endswith(".a") else base[:-2]
    thumb = ".thumb" in stem
    stem_nothumb = stem.replace(".thumb", "")
    variant = "NTR"
    for tok in VARIANT_TOKENS:
        if stem_nothumb.endswith("." + tok):
            variant = tok
            stem_nothumb = stem_nothumb[: -(len(tok) + 1)]
            break
    libname = stem_nothumb
    return tree, build, variant, thumb, libname


_ARCHIVE_CACHE = {}


def find_archives(include_demos=False):
    # The sdk tree is large; walk it once per process.
    key = bool(include_demos)
    if key not in _ARCHIVE_CACHE:
        _ARCHIVE_CACHE[key] = _walk_archives(include_demos)
    return list(_ARCHIVE_CACHE[key])


def _walk_archives(include_demos=False):
    out = []
    sdk = os.path.join(ROOT, "sdk")
    for dirpath, dirnames, filenames in os.walk(sdk):
        rel = os.path.relpath(dirpath, sdk).replace("\\", "/")
        if not include_demos and "/build/demos/" in "/" + rel + "/":
            continue
        for fn in filenames:
            if fn.endswith(".a") or fn.endswith(".o"):
                out.append(os.path.join(dirpath, fn))
    out.sort()
    return out


# ---------------------------------------------------------------------------
# regions
# ---------------------------------------------------------------------------

class Region:
    __slots__ = ("name", "base", "data")

    def __init__(self, name, base, data):
        self.name = name
        self.base = base
        self.data = data


def load_regions(layout, extract_dir, overlays=True):
    regions = []
    a9 = layout["arm9"]
    path = os.path.join(extract_dir, a9["decompressed_file"])
    with open(path, "rb") as fh:
        img = fh.read()
    st = a9["static"]
    regions.append(Region("arm9", st["ram_start"],
                          img[st["src_offset"]:st["src_offset"] + st["size"]]))
    for al in a9["autoloads"]:
        sz = al["code_size"]
        regions.append(Region("arm9_autoload%d_%s" % (al["index"], al["kind"]),
                              al["ram_start"],
                              img[al["src_offset"]:al["src_offset"] + sz]))
    if "twl" in layout:
        twl = layout["twl"]
        p = os.path.join(extract_dir, twl["decompressed_file"])
        if os.path.exists(p):
            with open(p, "rb") as fh:
                img_twl = fh.read()
            sz = twl["code_size"]
            src_off = twl["src_offset"]
            regions.append(Region("twl", twl["ram_start"],
                                  img_twl[src_off:src_off + sz]))
    if overlays:
        for ov in layout["overlays"]:
            p = os.path.join(extract_dir, ov["decompressed_file"])
            if not os.path.exists(p):
                continue
            with open(p, "rb") as fh:
                regions.append(Region("ov%03d" % ov["id"], ov["ram_start"], fh.read()))
    return regions


# ---------------------------------------------------------------------------
# index + scan
# ---------------------------------------------------------------------------

MIN_SIZE = 8
MIN_CONCRETE = 12
MAX_HITS = 8          # a pattern matching more places than this is too generic
KEY_LENS = (16, 12, 8, 4)


def pattern_key(p):
    """Longest concrete prefix, truncated to a multiple of 4 up to 16 bytes."""
    if not p.runs or p.runs[0][0] != 0:
        return None, 0
    run = p.runs[0][1]
    n = min(len(run), p.size, 16)
    n -= n % 4
    if n < 4:
        return None, 0
    return run[:n], n


def pattern_key_at(p):
    """(key, klen, koff): the prefix key when there is one, else the first
    concrete run of at least 4 bytes, keyed at its offset.

    Only the index lookup moves; verify() still checks every concrete run
    from the function start.  Without the fallback a Thumb function that
    opens ``push {..,lr}; bl f`` (a 2-byte run, then the 4-byte THM_CALL
    wildcard) had no key at all and was never scanned.
    """
    key, n = pattern_key(p)
    if key is not None:
        return key, n, 0
    for off, run in p.runs:
        n = min(len(run), 16)
        n -= n % 4
        if n >= 4:
            return run[:n], n, off
    return None, 0, 0


def verify(regdata, start, p):
    for off, blob in p.runs:
        s = start + off
        if regdata[s:s + len(blob)] != blob:
            return False
    for off in p.alts:
        if regdata[start + off] not in BLX_TOPS:
            return False
    return True


def scan(regions, patterns, progress=True):
    """patterns: list of Pattern.  Returns dict pattern_index -> [(region, addr)]."""
    # Tables are keyed by (key offset, key length); offset 0 is the prefix.
    arm_idx = defaultdict(dict)
    thm_idx = defaultdict(dict)
    usable = 0
    for i, p in enumerate(patterns):
        if p.size < MIN_SIZE or p.concrete < MIN_CONCRETE:
            continue
        key, klen, koff = pattern_key_at(p)
        if key is None:
            continue
        p.key, p.klen, p.koff = key, klen, koff
        tbl = thm_idx if p.thumb else arm_idx
        tbl[(koff, klen)].setdefault(key, []).append(i)
        usable += 1

    def order(idx):
        return [(ko, kl, idx[(ko, kl)])
                for ko, kl in sorted(idx, key=lambda t: (t[0], -t[1]))]

    arm_tbls = order(arm_idx)
    thm_tbls = order(thm_idx)

    hits = defaultdict(list)
    for reg in regions:
        d = reg.data
        n = len(d)
        if progress:
            sys.stderr.write("  scanning %-24s %8d bytes\r" % (reg.name, n))
            sys.stderr.flush()
        # ARM: function entries are word aligned.
        for pos in range(0, n - 3, 4):
            for koff, klen, tbl in arm_tbls:
                cand = tbl.get(d[pos + koff:pos + koff + klen])
                if cand:
                    for pi in cand:
                        p = patterns[pi]
                        if pos + p.size <= n and verify(d, pos, p):
                            hits[pi].append((reg.name, reg.base + pos))
        # Thumb: halfword aligned.
        for pos in range(0, n - 3, 2):
            for koff, klen, tbl in thm_tbls:
                cand = tbl.get(d[pos + koff:pos + koff + klen])
                if cand:
                    for pi in cand:
                        p = patterns[pi]
                        if pos + p.size <= n and verify(d, pos, p):
                            hits[pi].append((reg.name, reg.base + pos))
    if progress:
        sys.stderr.write(" " * 60 + "\r")
    return hits, usable


# ---------------------------------------------------------------------------
# reference consistency
# ---------------------------------------------------------------------------

def branch_target(d, pos, base, rtype):
    """(address, thumb) that the linked branch at d[pos] reaches, or None."""
    if pos < 0 or pos + 4 > len(d):
        return None
    if rtype in ARM_BRANCH_RELOCS:
        w, = struct.unpack_from("<I", d, pos)
        imm = w & 0xFFFFFF
        if imm & 0x800000:
            imm -= 0x1000000
        t = base + pos + 8 + (imm << 2)
        if (w >> 25) == 0x7D:                   # blx imm: Thumb, H is bit 24
            return t + ((w >> 23) & 2), True
        return t, False
    if rtype in THM_BRANCH_RELOCS:
        h1, h2 = struct.unpack_from("<HH", d, pos)
        if (h1 & 0xF800) != 0xF000 or (h2 & 0xE800) != 0xE800:
            return None
        off = ((h1 & 0x7FF) << 12) | ((h2 & 0x7FF) << 1)
        if off & 0x400000:
            off -= 0x800000
        t = base + pos + 4 + off
        if (h2 & 0xF800) == 0xE800:             # blx: ARM target
            return t & ~3, False
        return t, True
    return None


class Checker:
    """Tests a placement against what its object's relocations name.

    A function of the object is placed at an address only if the addresses
    its references reach agree with that name:

      callee   every function it names (a branch, or an ABS32 code pointer)
               must be a place where that function's own bytes verify, when
               the callee is scannable at all (directly, or behind a
               load-and-branch forwarder).  A body whose "EL_LoadLibrary"
               call lands on game code is a lookalike, not EL_LinkFileEx.
      data     a global it loads must sit where the functions that verify at
               exactly one place (and so are placed with confidence) put
               it: a lookalike loads another global.
               A placement fails when at least half of its checkable callees
               and globals disagree, so one odd reference in a large function
               (a callee built from another variant) does not remove it.
      static   a static data object of its own object cannot be named by
               code outside that object.  A literal pool word equal to the
               static's address that an ldr in code loads, farther away than
               the object's code size, means the "static" is someone else's
               global.
    """

    def __init__(self, regions, patterns, hits):
        self.patterns = patterns
        self.hits = hits
        self.regions = {r.name: r for r in regions}
        # name -> scanned patterns of that name.  A name with any pattern that
        # was never scanned (too short, too few concrete bytes) is left out:
        # the copy the game links may be that one, so a miss proves nothing.
        self.by_name = defaultdict(list)
        blind = set()
        for i, p in enumerate(patterns):
            if p.key is None:
                blind.add(p.name)
            else:
                self.by_name[p.name].append(i)
        # Names with a pattern that was never scanned: a miss proves nothing,
        # unless a scanned pattern of the name verifies in the region of the
        # call target (then that is where the linked copy is).
        self.partial = {}
        for name in blind:
            if name in self.by_name:
                self.partial[name] = self.by_name.pop(name)
        self.names = set(p.name for p in patterns)
        self._hitset = {}
        self._words = {}

    def hitset(self, pi):
        h = self._hitset.get(pi)
        if h is None:
            h = self._hitset[pi] = set(self.hits.get(pi, ()))
        return h

    def target_regions(self, reg, t):
        """(regions that can hold t, determinate?).  An overlay's own range
        first, then the always-resident regions; another overlay's range is
        ambiguous (overlays share addresses)."""
        r = self.regions.get(reg)
        if r is not None and r.base <= t < r.base + len(r.data):
            return [reg], True
        res = [n for n, x in self.regions.items() if not n.startswith("ov")
               and x.base <= t < x.base + len(x.data)]
        if res:
            return res, True
        return [n for n, x in self.regions.items()
                if x.base <= t < x.base + len(x.data)], False

    def targets(self, pi, reg, addr, refs=None):
        """[(name, target, local, kind, rtype, word)] for the named references
        of pattern pi placed at (reg, addr); kind as in build_patterns, word
        the linked ABS32 literal (None for a branch).  refs: one of the
        pattern's reference sets, default the first."""
        r = self.regions.get(reg)
        if r is None:
            return []
        if refs is None:
            refs = self.patterns[pi].refs[0] if self.patterns[pi].refs else ()
        d = r.data
        out = []
        for off, rtype, name, local, kind, addend in refs:
            pos = addr - r.base + off
            if rtype in BRANCH_RELOCS:
                bt = branch_target(d, pos, r.base, rtype)
                if bt is None:
                    continue
                out.append((name, bt[0], local, "func", rtype, None))
            elif rtype == 2 and 0 <= pos and pos + 4 <= len(d):
                v, = struct.unpack_from("<I", d, pos)
                t = (v - (addend or 0)) & 0xFFFFFFFF
                k = kind or ("func" if name in self.names else "")
                if k == "func":
                    t &= ~1
                out.append((name, t, local, k, rtype, v))
        return out

    def thunk(self, reg, t):
        """Where a load-and-branch forwarder at t goes, or None.  Thumb
        ``ldr rN, [pc, #i]; bx rN`` and ARM ``ldr pc, [pc, #-4]`` or
        ``ldr ip, [pc]; bx ip``, each followed by the target word."""
        r = self.regions.get(reg)
        if r is None:
            return None
        d, o = r.data, t - r.base
        if o < 0 or o + 12 > len(d):
            return None
        h1, h2 = struct.unpack_from("<HH", d, o)
        if (h1 & 0xF800) == 0x4800 and h2 == 0x4700 | (((h1 >> 8) & 7) << 3):
            lit = ((t + 4) & ~3) + (h1 & 0xFF) * 4 - r.base
            if 0 <= lit and lit + 4 <= len(d):
                return struct.unpack_from("<I", d, lit)[0] & ~1
        w1, w2, w3 = struct.unpack_from("<III", d, o)
        if w1 == 0xE51FF004:
            return w2 & ~1
        if w1 == 0xE59FC000 and w2 == 0xE12FFF1C:
            return w3 & ~1
        return None

    def words(self, reg):
        w = self._words.get(reg)
        if w is None:
            w = self._words[reg] = defaultdict(list)
            r = self.regions[reg]
            d = r.data
            for pos in range(0, len(d) - 3, 4):
                w[struct.unpack_from("<I", d, pos)[0]].append(r.base + pos)
        return w

    def build_consensus(self, anchors):
        """Where each global a function names sits, by the functions that
        verify at exactly one place (anchors): {(region, name): {address:
        count}}.  Statics are left to the static test (two objects may each
        have a static of one name, and ar truncates member names)."""
        self.consensus = defaultdict(lambda: defaultdict(int))
        for pi, reg, addr in anchors:
            p = self.patterns[pi]
            if len(p.refs) != 1:
                continue
            for name, t, local, kind, rtype, word in self.targets(pi, reg, addr, p.refs[0]):
                if kind == "func" or word is None or name.startswith("_ZZ"):
                    continue
                if not local:
                    self.consensus[(reg, name)][t] += 1

    def code_names(self, reg, pos):
        """True when an ldr from a code position loads the word at pos:
        ARM ``ldr rd, [pc, #+-i]`` within 4 KiB before or after it, Thumb
        ``ldr rd, [pc, #i]`` within 1 KiB before it."""
        r = self.regions[reg]
        d, o = r.data, pos - r.base
        for q in range(max(0, o - 4104) & ~3, min(len(d) - 3, o + 4096), 4):
            w, = struct.unpack_from("<I", d, q)
            if (w & 0x0F7F0000) == 0x051F0000:
                imm = w & 0xFFF
                if q + 8 + (imm if w & 0x00800000 else -imm) == o:
                    return True
        for q in range(max(0, o - 1024) & ~1, o, 2):
            h, = struct.unpack_from("<H", d, q)
            if (h & 0xF800) == 0x4800 and ((q + 4) & ~3) + (h & 0xFF) * 4 == o:
                return True
        return False

    def bad(self, pi, reg, addr):
        """None, or why pattern pi cannot be the function at (reg, addr).
        A pattern shared by several objects passes when any object's
        references agree."""
        first = None
        for j, refs in enumerate(self.patterns[pi].refs or [()]):
            why = self._bad(pi, reg, addr, refs, j)
            if why is None:
                return None
            first = first or why
        return first

    def _bad(self, pi, reg, addr, refs, j=0):
        p = self.patterns[pi]
        agree, miss = set(), []             # checkable references, by name
        cons = getattr(self, "consensus", {})
        for name, t, local, kind, rtype, word in self.targets(pi, reg, addr, refs):
            if kind == "func":
                cands = self.by_name.get(name)
                tregs, _det = self.target_regions(reg, t)
                if not tregs:
                    continue
                spots = set((tr, t) for tr in tregs)
                for tr in tregs:
                    f = self.thunk(tr, t)
                    if f is not None:
                        spots.update((tr2, f) for tr2 in self.target_regions(tr, f)[0])
                if not cands:
                    part = self.partial.get(name)
                    if not part or not _det:
                        continue            # callee never scannable: no evidence
                    found = set()
                    for pj in part:
                        found |= set(a for r, a in self.hitset(pj) if r in tregs)
                    if not found:
                        continue
                    if spots & set((tr, a) for tr in tregs for a in found):
                        agree.add(name)
                    else:
                        miss.append((name, "calls %s at 0x%08X, but %s's bytes"
                                     " verify at 0x%08X" % (name, t, name, min(found))))
                    continue
                if any(sp in self.hitset(pj) for pj in cands for sp in spots):
                    agree.add(name)
                else:
                    miss.append((name, "calls %s at 0x%08X, where %s's bytes do not"
                                 " verify" % (name, t, name)))
            elif word is None or name.startswith("_ZZ"):
                # (_ZZ...: the static of an inline function, one copy shared
                # by every object that inlines it)
                continue
            elif not local:
                v = cons.get((reg, name))
                if not v:
                    continue
                best = max(v.items(), key=lambda kv: kv[1])[0]
                if v[best] > v.get(t, 0):
                    miss.append((name, "loads %s as 0x%08X, where the functions"
                                 " placed once put it at 0x%08X" % (name, t, best)))
                else:
                    agree.add(name)
            elif kind == "data":
                lo = addr - p.span - 4
                hi = addr + p.size + p.span + 4
                foreign = [a for a in self.words(reg).get(word, ())
                           if (a < lo or a >= hi) and self.code_names(reg, a)]
                if foreign:
                    return ("static %s at 0x%08X is also loaded by code at 0x%08X,"
                            " outside the object" % (name, t, foreign[0]))
        missed = set(n for n, _w in miss)
        if missed and len(missed) >= len(agree - missed):
            return "%s (%d of %d checkable references disagree)" % (
                miss[0][1], len(missed), len(missed | agree))
        return None


# ---------------------------------------------------------------------------
# driver
# ---------------------------------------------------------------------------

def collect(archives, want_data=False, verbose=False):
    """Parse archives into a deduplicated pattern list.

    Returns (patterns, provenance) where provenance[i] is a list of
    (archive_path, member_name) the pattern was seen in, and a dict
    archive_path -> set of pattern indices contributed.
    """
    patterns = []
    seen = {}
    prov = defaultdict(list)
    by_archive = defaultdict(set)
    obj_funcs = {}
    for ap in archives:
        try:
            if ap.endswith(".o"):
                members = [(os.path.basename(ap), open(ap, "rb").read())]
            else:
                members = list(read_archive(ap))
        except Exception as exc:
            if verbose:
                print("  skip %s: %s" % (ap, exc))
            continue
        for mname, mdata in members:
            obj = Obj(mname, mdata)
            if not obj.ok:
                continue
            placed = []
            for p in build_patterns(obj, want_data=want_data):
                sig = (p.name, p.thumb, p.data, tuple((o, len(b)) for o, b in p.runs),
                       p.alts)
                idx = seen.get(sig)
                if idx is None:
                    idx = len(patterns)
                    seen[sig] = idx
                    patterns.append(p)
                else:
                    q = patterns[idx]
                    if p.refs[0] not in q.refs:
                        # Same bytes, other callees (libdwcutil's scene
                        # objects share procInit2 bodies that call
                        # different helpers).
                        q.refs.append(p.refs[0])
                        q.refobjs.append(set())
                    q.refobjs[q.refs.index(p.refs[0])].add(mname)
                    q.span = max(q.span, p.span)
                prov[idx].append((ap, mname))
                by_archive[ap].add(idx)
                placed.append((p.order, idx))
            # The object's functions in section order, which is the order
            # the linker lays them out in (checked on libdwcutil's scene
            # objects in ov016 and on libaoss.o).  A list per member: ar
            # truncates names to 16 bytes, so two members can share one
            # (libdwcutil has two "scenesetusbready" and two
            # "sceneoptmovconfi").
            obj_funcs.setdefault((ap, mname), []).append(
                [i for _o, i in sorted(placed)])
    collect.obj_funcs = obj_funcs
    return patterns, prov, by_archive


def family_of(path):
    tree, build, variant, thumb, lib = classify(path)
    return "%s/%s/%s%s" % (tree, build, variant, ".thumb" if thumb else "")


def profile_of(path):
    """Variant family without the tree, i.e. what the game's link line chose."""
    tree, build, variant, thumb, lib = classify(path)
    if variant == "TWL":
        # crt0.HYB.TWL.o and friends are named the other way round.
        variant = "TWL.HYB" if ".HYB" in os.path.basename(path) else "TWL.LTD"
    return "%s/%s%s" % (build, variant, ".thumb" if thumb else "")


def run(args):
    t0 = time.time()
    layout_path = os.path.join(ROOT, "layout", "layout.json")
    with open(layout_path) as fh:
        layout = json.load(fh)
    extract_dir = os.path.join(ROOT, layout.get("extract_dir", "extract"))

    regions = load_regions(layout, extract_dir, overlays=not args.no_overlays)
    total_bytes = sum(len(r.data) for r in regions)
    print("regions: %d, %d bytes" % (len(regions), total_bytes))

    archives = find_archives(include_demos=args.demos)
    if args.only:
        archives = [a for a in archives if args.only in a.replace("\\", "/")]
    print("archives: %d" % len(archives))

    patterns, prov, by_archive = collect(archives, want_data=args.data, verbose=args.verbose)
    print("unique function patterns: %d (%.1fs)" % (len(patterns), time.time() - t0))

    hits, usable = scan(regions, patterns, progress=not args.quiet)
    print("usable patterns: %d, patterns with >=1 hit: %d (%.1fs)"
          % (usable, len(hits), time.time() - t0))

    # ------------------------------------------------------------------
    # Per-family / per-library statistics.
    # ------------------------------------------------------------------
    fam_tot = defaultdict(int)
    fam_hit = defaultdict(int)
    prof_tot = defaultdict(int)
    prof_hit = defaultdict(int)
    lib_tot = defaultdict(int)
    lib_hit = defaultdict(int)
    for ap, idxs in by_archive.items():
        fam = family_of(ap)
        prof = profile_of(ap)
        for i in idxs:
            p = patterns[i]
            if p.key is None:
                continue
            fam_tot[fam] += 1
            prof_tot[prof] += 1
            lib_tot[ap] += 1
            if i in hits:
                fam_hit[fam] += 1
                prof_hit[prof] += 1
                lib_hit[ap] += 1

    prof_rows = sorted(prof_tot, key=lambda f: -prof_hit[f])
    best_profile = prof_rows[0] if prof_rows else ""
    print("\nvariant profiles (matched / usable functions), all trees pooled:")
    for f in prof_rows:
        t, h = prof_tot[f], prof_hit[f]
        print("  %-24s %6d / %6d  %5.1f%%" % (f, h, t, 100.0 * h / t if t else 0))

    print("\nvariant families (matched / usable functions):")
    rows = sorted(fam_tot, key=lambda f: -fam_hit[f])
    for f in rows[:24]:
        t, h = fam_tot[f], fam_hit[f]
        print("  %-38s %6d / %6d  %5.1f%%" % (f, h, t, 100.0 * h / t if t else 0))

    # ------------------------------------------------------------------
    # Resolve addresses.  A pattern that lands in too many places is noise.
    # ------------------------------------------------------------------
    def prov_score(pi):
        """How well a pattern's provenance matches the winning profile."""
        best = -10
        for ap, _m in prov[pi]:
            s = 4 if profile_of(ap) == best_profile else 0
            if "/build/demos/" in ap.replace("\\", "/"):
                s -= 3
            if ".thumb" in os.path.basename(ap):
                s -= 1
            best = max(best, s)
        return best

    best_build, best_variant = best_profile.split("/", 1)

    def source_rank(ap):
        tree, build, variant, thumb, lib = classify(ap)
        prof = profile_of(ap)
        return (
            0 if prof == best_profile else 1,
            1 if "/build/demos/" in ap.replace("\\", "/") else 0,
            0 if build == best_build else 1,
            0 if profile_of(ap).split("/")[1].replace(".thumb", "") == best_variant else 1,
            len(ap),
        )

    def pick_source(pi):
        return sorted(prov[pi], key=lambda am: source_rank(am[0]))[0]

    # Support for one hit: other functions of the same object that hit exactly
    # one place, in the same region within 4 KiB.  It picks the real copy of
    # a global among same-shaped lookalikes (an object's functions are linked
    # together; a lookalike in game code has no such neighbours).
    obj_funcs = getattr(collect, "obj_funcs", {})
    sibs = defaultdict(set)                  # pattern -> patterns of its object
    for funcs_list in obj_funcs.values():
        for funcs in funcs_list:
            for pi in funcs:
                sibs[pi].update(funcs)
    once = {}
    for pi, locs in hits.items():
        u = set(locs)
        if len(u) == 1:
            once[pi] = next(iter(u))

    def support(pi, reg, addr):
        n = 0
        for pj in sibs.get(pi, ()):
            if pj != pi and pj in once:
                r2, a2 = once[pj]
                if r2 == reg and abs(a2 - addr) <= 0x1000:
                    n += 1
        return n

    checker = Checker(regions, patterns, hits)
    checker.build_consensus([(pi, loc[0], loc[1]) for pi, loc in once.items()])
    rejected = []                           # (reg, addr, name, reason)

    # candidates per region, for the greedy pass below
    cands = defaultdict(list)
    for pi, locs in hits.items():
        uniq = sorted(set(locs))
        if len(uniq) > MAX_HITS:
            continue
        p = patterns[pi]
        for reg, addr in uniq:
            why = checker.bad(pi, reg, addr)
            if why:
                rejected.append((reg, addr, p.name, why))
                continue
            cands[reg].append([addr, p.size, p.concrete, prov_score(pi), pi,
                               support(pi, reg, addr), 0])

    # Votes: how many candidate placements call (reg, addr) by this name.
    # Same-bytes functions of different names (OS_IsTickAvailable and
    # OS_IsVAlarmAvailable, NVRAMi_Read and NVRAMi_Write) are told apart by
    # the name their callers use.
    votes = defaultdict(int)
    for reg, lst in cands.items():
        for c in lst:
            seen_t = set()
            for refs in patterns[c[4]].refs:
                for name, t, _l, kind, _rt, _w in checker.targets(c[4], reg, c[0], refs):
                    if kind == "func":
                        seen_t.add((name, t))
            for name, t in seen_t:
                tregs, det = checker.target_regions(reg, t)
                if det:
                    for tr in tregs:
                        votes[(tr, t, name)] += 1
    for reg, lst in cands.items():
        for c in lst:
            c[6] = votes.get((reg, c[0], patterns[c[4]].name), 0)

    # Same bytes under several names (GX_GetBankForLCDC, GX_IsDispOn,
    # OS_IsTickAvailable, OS_IsAlarmAvailable ... are one 16-byte shape):
    # the bytes cannot say which name an address carries, so such a
    # placement needs a caller that names it (votes) or a sibling of its
    # object nearby (support).  Without either, the address stays unnamed.
    shape_names = defaultdict(set)
    for pi, locs in hits.items():
        shape_names[frozenset(locs)].add(patterns[pi].name)

    # Fit with what is already located.  Anchors are the functions that
    # verify at exactly one place under bytes no other name shares, so their
    # name at that address is certain.  Two checks split a same-bytes family
    # (gti2CloseAllConnectionsMap / ...HardMap, CAMERA_I2C*Core,
    # PM_Append*Callback) where callers and siblings within 4 KiB cannot:
    #   reloc  the placement's own named references (calls, tail-call and
    #          callback words) that land on an anchor: +1 when the anchor
    #          carries the referenced name, -1 when it carries another;
    #   adj    the function's section-order neighbours in its object (the
    #          linker lays an object's sections out in that order) found as
    #          anchors flush before or after it, with at most 3 bytes of
    #          alignment padding.
    # A dead-stripped neighbour gives no adjacency, never a penalty, so a
    # relocation that names an anchor outranks adjacency.  The greedy pass
    # below then runs again with its own placements as further anchors
    # (gt2CloseConnectionHard, PM_GetExitFactor share their bytes with other
    # names, so only the first round places them), until nothing changes.
    anchor = {}
    anchor_pi = {}
    for pi, loc in once.items():
        if len(shape_names[frozenset(hits[pi])]) == 1:
            anchor[loc] = patterns[pi].name
            anchor_pi[loc] = pi

    def data_of(placed):
        """{(region, data symbol): address} that every placed function
        naming the symbol agrees on (statics through their own name, not a
        section symbol or a string literal)."""
        seen = defaultdict(set)
        for (reg, addr), pi in placed.items():
            refs = patterns[pi].refs
            if len(refs) != 1:
                continue
            for name, t, _l, kind, _rt, word in checker.targets(pi, reg, addr, refs[0]):
                if kind == "func" or word is None or not name or name[0] in ".@"                         or name.startswith("_ZZ"):
                    continue
                seen[(reg, name)].add(t)
        return {k: next(iter(v)) for k, v in seen.items() if len(v) == 1}

    anchor_data = data_of(anchor_pi)

    all_by_name = defaultdict(list)         # every pattern, scanned or not
    for pj, p in enumerate(patterns):
        all_by_name[p.name].append(pj)

    def callee_fit(name, tr, t, anchor):
        """+1/-1/0: does the unnamed function at (tr, t) reference what the
        vendor function `name` references?  Reaches through small wrappers
        too short to scan (DWC_ScReportAddByteValue calls scimain.o's
        12-byte scReportAddByteValue, which tail-calls
        sciReportAddByteValue through a literal)."""
        for pj in all_by_name.get(name, ()):
            for refs in patterns[pj].refs or [()]:
                for n2, t2, _l, k2, _rt, _w in checker.targets(pj, tr, t, refs):
                    if k2 != "func":
                        continue
                    for tr2 in checker.target_regions(tr, t2)[0]:
                        got = anchor.get((tr2, t2))
                        if got is not None:
                            return 1 if got == n2 else -1
        return 0

    def reloc_fit(pi, reg, addr, anchor=anchor, data=None):
        if data is None:
            data = anchor_data
        best = None
        for refs in patterns[pi].refs or [()]:
            sc = 0
            for name, t, _l, kind, _rt, _w in checker.targets(pi, reg, addr, refs):
                if kind != "func":
                    # a data symbol the located functions put elsewhere
                    # (PM_AppendPreSleepCallback and ...PostSleepCallback
                    # differ only in which callback list they load)
                    v = data.get((reg, name)) if _w is not None else None
                    if v is not None:
                        sc += 1 if v == t else -1
                    continue
                tregs, det = checker.target_regions(reg, t)
                if not det:
                    continue
                for tr in tregs:
                    got = anchor.get((tr, t))
                    if got is not None:
                        sc += 1 if got == name else -1
                        break
                else:
                    for tr in tregs:
                        if (tr, t) not in resolved_now:
                            sc += callee_fit(name, tr, t, anchor)
                            break
            best = sc if best is None else max(best, sc)
        return best or 0

    resolved_now = {}                       # last greedy round's placements
    pos_of = defaultdict(list)              # pattern -> [(object list, index)]
    for funcs_list in obj_funcs.values():
        for funcs in funcs_list:
            for k, pj in enumerate(funcs):
                pos_of[pj].append((funcs, k))

    def adj_fit(pi, reg, addr, anchor=anchor):
        best = 0
        size = patterns[pi].size
        for funcs, k in pos_of.get(pi, ()):
            n = 0
            if k > 0:
                pp = funcs[k - 1]
                ps = patterns[pp].size
                if any(anchor.get((reg, addr - g - ps)) == patterns[pp].name
                       for g in range(4)):
                    n += 1
            if k + 1 < len(funcs):
                pn = funcs[k + 1]
                if any(anchor.get((reg, addr + size + g)) == patterns[pn].name
                       for g in range(4)):
                    n += 1
            best = max(best, n)
        return best

    for reg, lst in cands.items():
        for c in lst:
            c.append(reloc_fit(c[4], reg, c[0]))     # c[7]
            c.append(adj_fit(c[4], reg, c[0]))       # c[8]

    unsure = 0
    for reg in list(cands):
        keep = []
        for c in cands[reg]:
            pi = c[4]
            if (c[5] == 0 and c[6] == 0 and c[7] <= 0 and c[8] == 0
                    and len(shape_names[frozenset(hits[pi])]) > 1):
                rejected.append((reg, c[0], patterns[pi].name,
                                 "shares its bytes with other names at the"
                                 " same addresses, and no caller or sibling"
                                 " of its object says which"))
                unsure += 1
                continue
            keep.append(c)
        cands[reg] = keep

    # Greedy, biggest and most-concrete first: a 12-byte pattern that happens
    # to sit inside a longer function that also matched is a false positive.
    # Ties: the placement's references that land on anchors (reloc), the
    # name callers use (votes), section-order neighbours located flush
    # (adj), copies of one name by object support, then the object's section
    # order, which is the link order.  That splits same-bytes families
    # (GX_/GXS_LoadBGnScr, GX_ResetBankForX / GX_DisableBankForX) in the
    # order the object defines them; the name order used before gave the
    # alphabetically first name every copy.  A global is defined once per
    # link, so it is placed at most once per region; statics may repeat
    # (libdwcutil's scene objects each carry the same procInit).
    def greedy():
        resolved = {}
        stats = [0, 0, 0]                   # dropped_overlap, contested, twins
        taken_by_reg = {}
        placed_by_reg = {}
        for reg, lst in cands.items():
            lst.sort(key=lambda c: (-c[1], -c[2], -c[3], -c[7], -c[6], -c[8],
                                    -c[5], patterns[c[4]].order, c[0]))
            taken = taken_by_reg[reg] = []      # sorted list of (start, end)
            placed = placed_by_reg[reg] = set()  # global names placed in reg
            for addr, size, concrete, sc, pi, _sup, _votes, _rel, _adj in lst:
                if patterns[pi].glob and patterns[pi].name in placed:
                    stats[2] += 1
                    continue                    # leave the address to a twin
                end = addr + size
                clash = False
                for ts, te in taken:
                    if addr < te and ts < end:
                        clash = True
                        break
                if clash:
                    if (reg, addr) in resolved:
                        stats[1] += 1
                    else:
                        stats[0] += 1
                    continue
                taken.append((addr, end))
                taken.sort()
                resolved[(reg, addr)] = pi
                if patterns[pi].glob:
                    placed.add(patterns[pi].name)
        return resolved, stats, taken_by_reg, placed_by_reg

    rounds = 0
    while True:
        resolved, (dropped_overlap, contested, twins), taken_by_reg, placed_by_reg = greedy()
        resolved_now = resolved
        rounds += 1
        if rounds >= 5:
            break
        # Only placements that evidence chose count: bytes no other name
        # shares, or (reloc, votes) strictly better than every other name's
        # at that address.  Adjacency alone does not make a placement an
        # anchor: same-bytes siblings (DWC_ScReportAdd*Value all call the same
        # helpers) would otherwise vouch for each other's positions, and the
        # rounds would not settle.
        known = dict(anchor)
        known_pi = dict(anchor_pi)
        fit_at = defaultdict(list)
        for reg, lst in cands.items():
            for c in lst:
                fit_at[(reg, c[0])].append(((c[7], c[6]), c[4]))
        for loc, pi in resolved.items():
            if len(shape_names[frozenset(hits[pi])]) == 1:
                known.setdefault(loc, patterns[pi].name)
                known_pi.setdefault(loc, pi)
                continue
            mine = [f for f, pj in fit_at.get(loc, ()) if pj == pi]
            others = [f for f, pj in fit_at.get(loc, ())
                      if patterns[pj].name != patterns[pi].name]
            if mine and all(max(mine) > f for f in others):
                known.setdefault(loc, patterns[pi].name)
                known_pi.setdefault(loc, pi)
        known_data = data_of(known_pi)
        changed = False
        for reg, lst in cands.items():
            for c in lst:
                r7 = reloc_fit(c[4], reg, c[0], known, known_data)
                r8 = adj_fit(c[4], reg, c[0], known)
                if (r7, r8) != (c[7], c[8]):
                    c[7], c[8] = r7, r8
                    changed = True
        if not changed:
            break
    print("greedy placement: %d round(s)" % rounds)

    # Pass 2: a pattern that landed in more than MAX_HITS places is kept at
    # one of them only when it is the next (or previous) function, in the
    # section order of the source object, after (or before) a function
    # already resolved from that same object, and sits flush against it with
    # at most 3 bytes of alignment padding.  CodeWarrior gives each function
    # its own section and the linker lays an object's sections out in order,
    # so this is the sibling rule made positional.  Functions of the object
    # that are absent from the image (dead-stripped, or never scannable) may
    # be skipped; the nearest one in order that verifies there is taken.
    # TwlDWC libdwcutil's scene*.o objects each carry their own static
    # procInit / procInit2 / endScene, identical across objects, so every
    # copy exceeded MAX_HITS and was dropped.  Runs to a fixed point, so a
    # chain of such functions resolves outward from its anchor.
    source = {}                         # (reg, addr) -> (archive, member)

    def src_of(key):
        return source.get(key) or pick_source(resolved[key])

    multi_at = defaultdict(set)         # (reg, addr) -> {pattern index}
    for pi, locs in hits.items():
        uniq = set(locs)
        if len(uniq) > MAX_HITS:
            for loc in uniq:
                multi_at[loc].add(pi)
    # Callers that name an address (votes) and the placement's own
    # references veto a pass-2 placement: FATFS_GetLastError
    # (fatfs_request.o) and FATFSi_IsInitialized (fatfs_api.o) both fit flush
    # at twl 0x02704318 between their objects, and OS_Terminate's call there
    # names the latter.
    votes_at = defaultdict(dict)
    for (vr, va, vn), cnt in votes.items():
        votes_at[(vr, va)][vn] = cnt
    vetoed = 0
    adjacent = 0
    frontier = sorted(resolved)
    while frontier:
        nxt = []
        for reg, a2 in frontier:
            pi2 = resolved[(reg, a2)]
            e2 = a2 + patterns[pi2].size
            # The neighbour's own source first, then every other object that
            # carries the identical function (libdwcutil's scene objects
            # share bytes, so the first pass's pick can be a sister object).
            srcs = [src_of((reg, a2))]
            for am in sorted(prov[pi2], key=lambda am: source_rank(am[0])):
                if am not in srcs:
                    srcs.append(am)
            walks = []
            for src in srcs:
                for funcs in obj_funcs.get(src, ()):
                    if pi2 in funcs:
                        k = funcs.index(pi2)
                        walks += [(funcs[k + 1:], True, src),
                                  (funcs[:k][::-1], False, src)]
            for seq, forward, src in walks:
                done = False
                for pj in seq:
                    size = patterns[pj].size
                    for g in range(4):
                        addr = e2 + g if forward else a2 - g - size
                        if pj not in multi_at.get((reg, addr), ()):
                            continue
                        if (reg, addr) in resolved:
                            continue
                        if (patterns[pj].glob and patterns[pj].name
                                in placed_by_reg.setdefault(reg, set())):
                            continue
                        if checker.bad(pj, reg, addr):
                            continue
                        va = votes_at.get((reg, addr))
                        if ((va and not va.get(patterns[pj].name))
                                or reloc_fit(pj, reg, addr) < 0):
                            vetoed += 1
                            continue
                        end = addr + size
                        taken = taken_by_reg.setdefault(reg, [])
                        if any(addr < te and ts < end for ts, te in taken):
                            continue
                        taken.append((addr, end))
                        taken.sort()
                        resolved[(reg, addr)] = pj
                        if patterns[pj].glob:
                            placed_by_reg[reg].add(patterns[pj].name)
                        source[(reg, addr)] = src
                        nxt.append((reg, addr))
                        adjacent += 1
                        done = True
                        break
                    if done:
                        break
        frontier = sorted(nxt)
    print("pass 2: %d placements of patterns with >%d hits, each the next or"
          " previous function of a resolved neighbour's object (%d vetoed by"
          " callers or references)" % (adjacent, MAX_HITS, vetoed))

    print("reference checks: %d candidate placements rejected (a named callee"
          " whose bytes do not verify at the call target, or a static named from"
          " outside its object); %d copies of an already placed global left to"
          " a twin" % (len(rejected), twins))

    name_addrs = defaultdict(list)
    for (reg, addr), pi in resolved.items():
        name_addrs[patterns[pi].name].append((reg, addr))

    # An object whose functions matched more than once in the same region is
    # corroborated: several independent patterns landed in the same module.
    obj_region = defaultdict(int)
    for (reg, addr), pi in resolved.items():
        ap, mname = src_of((reg, addr))
        obj_region[(reg, ap, mname)] += 1

    entries = []
    for (reg, addr), pi in resolved.items():
        ap, mname = src_of((reg, addr))
        tree, build, variant, thumb, lib = classify(ap)
        entries.append({
            "address": addr,
            "name": patterns[pi].name,
            "lib": "%s/%s" % (tree, os.path.basename(ap)),
            "object": mname,
            "region": reg,
            "thumb": bool(patterns[pi].thumb),
            "size": patterns[pi].size,
            "concrete": patterns[pi].concrete,
            "dupes": len(name_addrs[patterns[pi].name]),
            "siblings": obj_region[(reg, ap, mname)],
        })
        if (reg, addr) in source:
            entries[-1]["adjacent"] = True      # placed by pass 2
    entries.sort(key=lambda e: (e["address"], e["name"]))

    strong = [e for e in entries if e["size"] >= 24 or e["siblings"] >= 2]
    print("\nresolved symbols: %d (%d candidates dropped as overlapping,"
          " %d contested addresses)" % (len(entries), dropped_overlap, contested))
    print("of those, %d are corroborated (>=24 bytes, or another function from"
          " the same object matched in the same region)" % len(strong))

    by_tree = defaultdict(int)
    for e in entries:
        by_tree[e["lib"].split("/")[0]] += 1
    print("per tree:")
    for t in sorted(by_tree):
        print("  %-16s %6d" % (t, by_tree[t]))
    best_family = best_profile

    # ------------------------------------------------------------------
    # Write output.
    # ------------------------------------------------------------------
    layout_dir = args.outdir or os.path.join(ROOT, "layout")
    txt = os.path.join(layout_dir, "symbols_sdk.txt")
    with open(txt, "w", newline="\n") as fh:
        fh.write("# SDK symbols recovered by tools/libmatch.py\n")
        fh.write("# addresses and names only; contains no game data\n")
        fh.write("# variant profile the game links: %s\n" % best_profile)
        fh.write("# columns: address  symbol  library(member)  region  [flags]\n")
        fh.write("#   flag ? = short (<24 bytes) and no sibling function from the\n")
        fh.write("#          same object matched in the same region: weaker evidence\n")
        for e in entries:
            flag = "" if (e["size"] >= 24 or e["siblings"] >= 2) else "  ?"
            fh.write("%08X  %-44s  %s(%s)  %s%s\n"
                     % (e["address"], e["name"], e["lib"], e["object"],
                        e["region"], flag))
        fh.write("\n# per-library summary: matched / usable functions.\n")
        fh.write("# Only libraries of the winning profile with at least one\n")
        fh.write("# match are listed; a high fraction means this exact library\n")
        fh.write("# build is the one the game links.\n")
        winners = [ap for ap in lib_tot
                   if profile_of(ap) == best_profile and lib_hit[ap] > 0]
        for ap in sorted(winners, key=lambda a: (-lib_hit[a], a)):
            fh.write("# %6d / %6d  %5.1f%%  %s\n"
                     % (lib_hit[ap], lib_tot[ap],
                        100.0 * lib_hit[ap] / lib_tot[ap],
                        os.path.relpath(ap, ROOT).replace("\\", "/")))

    summary = []
    for ap in sorted(lib_tot, key=lambda a: (-lib_hit[a], a)):
        tree, build, variant, thumb, lib = classify(ap)
        summary.append({
            "archive": os.path.relpath(ap, ROOT).replace("\\", "/"),
            "tree": tree, "build": build, "variant": variant, "thumb": thumb,
            "functions": lib_tot[ap], "matched": lib_hit[ap],
            "fraction": round(lib_hit[ap] / lib_tot[ap], 4) if lib_tot[ap] else 0.0,
        })

    js = os.path.join(layout_dir, "symbols_sdk.json")
    with open(js, "w", newline="\n") as fh:
        json.dump({
            "tool": "libmatch.py",
            "version": 1,
            "note": "addresses, names and library file names only; no game data",
            "best_profile": best_profile,
            "profiles": [
                {"profile": f, "functions": prof_tot[f], "matched": prof_hit[f],
                 "fraction": round(prof_hit[f] / prof_tot[f], 4) if prof_tot[f] else 0.0}
                for f in prof_rows
            ],
            "families": [
                {"family": f, "functions": fam_tot[f], "matched": fam_hit[f],
                 "fraction": round(fam_hit[f] / fam_tot[f], 4) if fam_tot[f] else 0.0}
                for f in sorted(fam_tot, key=lambda f: -fam_hit[f])
            ],
            "libraries": summary,
            "symbols": entries,
            "rejected": [{"address": a, "name": n, "region": r, "reason": w}
                         for r, a, n, w in sorted(rejected)],
        }, fh, indent=1)

    print("\nwrote %s (%d lines)" % (os.path.relpath(txt, ROOT), len(entries)))
    print("wrote %s" % os.path.relpath(js, ROOT))

    check_anchors(entries)
    print("\ntotal %.1fs" % (time.time() - t0))
    return 0


ANCHORS = {
    0x02004DF4: "MIi_UncompressBackward",
    0x02004BB4: "autoload walker",
    0x02004D50: "static init collector",
    0x02004ED4: "block copy",
    0x02004F20: "block clear",
}


def check_anchors(entries):
    found = {}
    for e in entries:
        if e["address"] in ANCHORS:
            found.setdefault(e["address"], []).append(e)
    print("\nanchors:")
    for addr in sorted(ANCHORS):
        got = found.get(addr)
        if got:
            print("  %08X  expected %-24s -> %s  [%s]"
                  % (addr, ANCHORS[addr], got[0]["name"], got[0]["lib"]))
        else:
            print("  %08X  expected %-24s -> NO MATCH" % (addr, ANCHORS[addr]))


def comments(args):
    """Report the CodeWarrior build string in each library's .comment sections."""
    archives = find_archives(include_demos=args.demos)
    if args.only:
        archives = [a for a in archives if args.only in a.replace("\\", "/")]
    per_tree = defaultdict(lambda: defaultdict(int))
    per_lib = {}
    for ap in archives:
        try:
            if ap.endswith(".o"):
                with open(ap, "rb") as fh:
                    members = [(os.path.basename(ap), fh.read())]
            else:
                members = list(read_archive(ap))
        except Exception:
            continue
        tree = classify(ap)[0]
        local = defaultdict(int)
        for mname, mdata in members:
            obj = Obj(mname, mdata)
            if not obj.ok:
                continue
            for i, n in enumerate(obj.secnames):
                if n == ".comment":
                    txt = obj.section_data(i).decode("latin1", "replace").strip("\0").strip()
                    if txt:
                        per_tree[tree][txt] += 1
                        local[txt] += 1
        if local:
            per_lib[ap] = dict(local)
    print("CodeWarrior build strings found in .comment, by SDK tree:")
    for tree in sorted(per_tree):
        print("  %s" % tree)
        for txt, n in sorted(per_tree[tree].items(), key=lambda kv: -kv[1]):
            print("    %6d objects  %s" % (n, txt))
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("command", nargs="?", default="scan",
                    choices=("scan", "variants", "anchors", "comments"))
    ap.add_argument("--only", help="substring filter on archive path")
    ap.add_argument("--demos", action="store_true",
                    help="also index the SDK demo helper libraries")
    ap.add_argument("--data", action="store_true",
                    help="also pattern-match STT_OBJECT data symbols")
    ap.add_argument("--no-overlays", action="store_true")
    ap.add_argument("--outdir",
                    help="write symbols_sdk.txt/.json here instead of layout/"
                         " (dry runs and diffs against the committed files)")
    ap.add_argument("-q", "--quiet", action="store_true")
    ap.add_argument("-v", "--verbose", action="store_true")
    args = ap.parse_args(argv)
    if args.command == "comments":
        return comments(args)
    if args.command == "variants":
        args.no_overlays = True
    return run(args)


if __name__ == "__main__":
    sys.exit(main())
