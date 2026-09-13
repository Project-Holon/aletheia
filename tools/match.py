#!/usr/bin/env python3
"""Function-level matching harness.

Compiles one C (or C++) translation unit with a CodeWarrior / Freescale ARM
front end from ``tools/mwccarm/mwccarm/dsi/``, pulls a named function's bytes
out of the resulting ELF object, and compares them with the original bytes at
a target address in the game image.

Bytes the linker would have rewritten are wildcarded from the object's own
relocation table (BL/BLX displacements, ABS32 words, and so on), so a function
that calls out or references a global can still be declared a match without
the project having a link step yet.

Verdicts:

    EXACT    every byte identical, relocation fields included
    MATCH    identical except at relocation-affected fields
    SIZE     the compiler produced a different number of bytes
    DIFF     same size, but concrete bytes differ

Usage:

    python tools/match.py one  --src src/matched/foo.c --func Foo \\
        --addr 0x02075DD8 --cc 1.1p1
    python tools/match.py one  ... --diff            # two-column disassembly
    python tools/match.py sweep --src ... --func ... --addr ...
    python tools/match.py sweep ... --cpp            # also try -lang c++
    python tools/match.py manifest                   # rebuild layout/matched.json

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

    __slots__ = ("name", "data", "mask", "thumb", "section", "relocs")

    def __init__(self, name, data, mask, thumb, section, relocs):
        self.name = name
        self.data = data        # bytes as the compiler emitted them
        self.mask = mask        # bytearray, 1 = concrete, 0 = linker-rewritten
        self.thumb = thumb
        self.section = section
        self.relocs = relocs    # list of (offset, type, symbol name)

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
    """Return [(offset, rtype, symbol_name)] for one section."""
    syms, _ = read_symbols(obj)
    out = []
    for s in obj.sections:
        if s[1] not in (SHT_RELA, SHT_REL) or s[7] != target_index:
            continue
        entsz = s[9] or (12 if s[1] == SHT_RELA else 8)
        for j in range(s[5] // entsz):
            off, info = struct.unpack_from("<II", obj.data, s[4] + j * entsz)
            rtype = info & 0xFF
            symi = info >> 8
            sname = syms[symi][0] if symi < len(syms) else ""
            out.append((off, rtype, sname))
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
    for off, rtype, sname in section_relocs(obj, shndx):
        if off < value or off >= value + size:
            continue
        lo, width = RELOC_MASK.get(rtype, RELOC_DEFAULT)
        start = off - value + lo
        for k in range(start, min(start + width, size)):
            if k >= 0:
                mask[k] = 0
        rels.append((off - value, rtype, sname))

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

    return FuncBytes(name, blob, mask, thumb, obj.secnames[shndx], rels)


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


def reloc_map(fb):
    return {off: "<- %s %s" % (RELOC_NAMES.get(t, "r%d" % t), s)
            for off, t, s in fb.relocs}


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
                if r.status in ("EXACT", "MATCH"):
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
# manifest
# ---------------------------------------------------------------------------

MANIFEST = os.path.join(ROOT, "layout", "matched.json")

HEADER_RE = re.compile(
    r"^\s*\*?\s*(address|region|compiler|flags|lang|isa|status|function)\s*:\s*(.+?)\s*$",
    re.IGNORECASE)


def read_header(path):
    """Parse the leading block comment of a matched source file."""
    fields = {}
    with open(path, "r", errors="replace") as fh:
        for line in fh:
            if line.lstrip().startswith("*/"):
                break
            m = HEADER_RE.match(line)
            if m:
                fields[m.group(1).lower()] = m.group(2)
                continue
            s = line.strip()
            if s and not s.startswith(("/*", "*", "//")) and fields:
                break
    return fields


SRC_DIRS = [("src/calib", "sdk_calibration"), ("src/matched", "game")]


def cmd_manifest(args):
    entries = []
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
            rel = reldir + "/" + fn
            flags = h.get("flags", "-O4,p")
            lang = h.get("lang", "c99")
            region = h.get("region") or find_region(addr).name
            names = [n.strip() for n in h.get("function", "").split(",") if n.strip()]
            if not names:
                names = [os.path.splitext(fn)[0]]
            thumb = (h.get("isa", "").lower() == "thumb")
            if not h.get("isa"):
                thumb = resolve_isa(addr, region, argparse.Namespace(thumb=False, arm=False))
            status = h.get("status", "")
            if args.verify:
                r = run_one(path, names[0], addr, h.get("compiler", "1.1p1"),
                            flags.split(), thumb, lang, region=region)
                status = r.status
            entries.append({
                "name": names[0],
                "address": "0x%08X" % addr,
                "kind": kind,
                "region": region,
                "source": rel,
                "compiler": "dsi/" + h.get("compiler", "1.1p1"),
                "lang": lang,
                "isa": "thumb" if thumb else "arm",
                "flags": " ".join(BASE_FLAGS) + " " + flags +
                         (" -thumb" if thumb else "") + " -lang " + lang,
                "status": status,
            })
    entries.sort(key=lambda e: int(e["address"], 16))
    with open(MANIFEST, "w", newline="\n") as fh:
        json.dump({
            "tool": "tools/match.py",
            "version": 1,
            "note": "matched function inventory: addresses, names and compiler "
                    "configuration only, no game bytes",
            "base_flags": " ".join(BASE_FLAGS),
            "functions": entries,
        }, fh, indent=1)
        fh.write("\n")
    print("wrote %s (%d function(s))"
          % (os.path.relpath(MANIFEST, ROOT), len(entries)))
    for e in entries:
        print("  %-10s %-16s %-30s %-8s %-10s %s"
              % (e["address"], e["kind"], e["name"], e["region"],
                 e["compiler"], e["status"]))
    return 0


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

    p3 = sub.add_parser("manifest", help="rebuild layout/matched.json from src/matched/")
    p3.add_argument("--verify", action="store_true",
                    help="recompile each entry and record the live status")

    p4 = sub.add_parser("show", help="disassemble the original bytes at an address")
    p4.add_argument("--addr", required=True)
    p4.add_argument("--size")
    p4.add_argument("--region")
    p4.add_argument("--thumb", action="store_true")
    p4.add_argument("--arm", action="store_true")

    args = ap.parse_args(argv)
    return {"one": cmd_one, "sweep": cmd_sweep,
            "manifest": cmd_manifest, "show": cmd_show}[args.command](args)


if __name__ == "__main__":
    sys.exit(main())
