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

CODE_SECTION_RE = re.compile(r"^\.(text|itcm|init|dtcm)")


class Pattern:
    __slots__ = ("name", "data", "runs", "thumb", "size", "concrete", "key", "klen")

    def __init__(self, name, data, runs, thumb):
        self.name = name
        self.data = data
        self.runs = runs          # list of (offset, bytes) concrete runs
        self.thumb = thumb
        self.size = len(data)
        self.concrete = sum(len(b) for _, b in runs)
        self.key = None
        self.klen = 0


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

    # Relocation offsets per target section.
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
            relocs[target].append((off, info & 0xFF))

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

        for off, rtype in relocs.get(shndx, ()):
            if off < value or off >= value + size:
                continue
            lo, width = RELOC_MASK.get(rtype, RELOC_DEFAULT)
            start = off - value + lo
            for k in range(start, min(start + width, size)):
                if k >= 0:
                    mask[k] = 0

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
        out.append(Pattern(name, bytes(blob), runs, thumb))
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


def find_archives(include_demos=False):
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


def verify(regdata, start, p):
    for off, blob in p.runs:
        s = start + off
        if regdata[s:s + len(blob)] != blob:
            return False
    return True


def scan(regions, patterns, progress=True):
    """patterns: list of Pattern.  Returns dict pattern_index -> [(region, addr)]."""
    arm_idx = {n: {} for n in KEY_LENS}
    thm_idx = {n: {} for n in KEY_LENS}
    usable = 0
    for i, p in enumerate(patterns):
        if p.size < MIN_SIZE or p.concrete < MIN_CONCRETE:
            continue
        key, klen = pattern_key(p)
        if key is None:
            continue
        p.key, p.klen = key, klen
        tbl = thm_idx if p.thumb else arm_idx
        tbl[klen].setdefault(key, []).append(i)
        usable += 1

    arm_tbls = [(n, arm_idx[n]) for n in KEY_LENS if arm_idx[n]]
    thm_tbls = [(n, thm_idx[n]) for n in KEY_LENS if thm_idx[n]]

    hits = defaultdict(list)
    for reg in regions:
        d = reg.data
        n = len(d)
        if progress:
            sys.stderr.write("  scanning %-24s %8d bytes\r" % (reg.name, n))
            sys.stderr.flush()
        # ARM: function entries are word aligned.
        for pos in range(0, n - 3, 4):
            for klen, tbl in arm_tbls:
                cand = tbl.get(d[pos:pos + klen])
                if cand:
                    for pi in cand:
                        p = patterns[pi]
                        if pos + p.size <= n and verify(d, pos, p):
                            hits[pi].append((reg.name, reg.base + pos))
        # Thumb: halfword aligned.
        for pos in range(0, n - 3, 2):
            for klen, tbl in thm_tbls:
                cand = tbl.get(d[pos:pos + klen])
                if cand:
                    for pi in cand:
                        p = patterns[pi]
                        if pos + p.size <= n and verify(d, pos, p):
                            hits[pi].append((reg.name, reg.base + pos))
    if progress:
        sys.stderr.write(" " * 60 + "\r")
    return hits, usable


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
            for p in build_patterns(obj, want_data=want_data):
                sig = (p.name, p.thumb, p.data, tuple((o, len(b)) for o, b in p.runs))
                idx = seen.get(sig)
                if idx is None:
                    idx = len(patterns)
                    seen[sig] = idx
                    patterns.append(p)
                prov[idx].append((ap, mname))
                by_archive[ap].add(idx)
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

    # candidates per region: (start, size, concrete, -pattern order) for greedy
    cands = defaultdict(list)
    for pi, locs in hits.items():
        uniq = sorted(set(locs))
        if len(uniq) > MAX_HITS:
            continue
        p = patterns[pi]
        for reg, addr in uniq:
            cands[reg].append((addr, p.size, p.concrete, prov_score(pi), pi))

    # Greedy, biggest and most-concrete first: a 12-byte pattern that happens
    # to sit inside a longer function that also matched is a false positive.
    resolved = {}
    dropped_overlap = 0
    contested = 0
    for reg, lst in cands.items():
        lst.sort(key=lambda c: (-c[1], -c[2], -c[3], patterns[c[4]].name))
        taken = []           # sorted list of (start, end)
        for addr, size, concrete, sc, pi in lst:
            end = addr + size
            clash = False
            for ts, te in taken:
                if addr < te and ts < end:
                    clash = True
                    break
            if clash:
                if (reg, addr) in resolved:
                    contested += 1
                else:
                    dropped_overlap += 1
                continue
            taken.append((addr, end))
            taken.sort()
            resolved[(reg, addr)] = pi

    name_addrs = defaultdict(list)
    for (reg, addr), pi in resolved.items():
        name_addrs[patterns[pi].name].append((reg, addr))

    # An object whose functions matched more than once in the same region is
    # corroborated: several independent patterns landed in the same module.
    obj_region = defaultdict(int)
    for (reg, addr), pi in resolved.items():
        ap, mname = pick_source(pi)
        obj_region[(reg, ap, mname)] += 1

    entries = []
    for (reg, addr), pi in resolved.items():
        ap, mname = pick_source(pi)
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
    layout_dir = os.path.join(ROOT, "layout")
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
