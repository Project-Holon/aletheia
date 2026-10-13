#!/usr/bin/env python3
"""gamelink.py -- link one overlay from its src/game files with mwldarm.

For overlay N the script

  1. compiles every top-level file of src/game/ovNNN/ with the compiler, flags,
     lang and isa of its header (match.compile_tu), one object per file;
  2. writes the data between the files (and any code no file covers) as binary
     sections taken from the extracted overlay image.  THIS READS THE IMAGE: the
     check below only says anything about the byte ranges the src/game files
     produce, the rest is copied.  Gap sections also carry typed function
     symbols for callees that lie inside a gap;
  3. writes one tiny object ("stubs.o") with a typed function symbol for every
     callee outside the overlay (arm9, other overlays).  Typed means: a section
     of its own and a $a or $t mapping symbol, the way mwccarm marks ARM and
     Thumb code.  Data symbols stay absolute assignments in the .lcf;
  4. generates a linker command file with one memory region per file, gap and
     stub at its original address, and runs
         mwldarm -proc arm946e -interworking -nostdlib -nodefaults -main "" ...
  5. compares the linked image with the original overlay byte for byte.

Why typed stubs and -interworking: an absolute symbol has no ARM/Thumb type, so
the linker emits BL where the original has BLX.  With a real symbol and
-interworking the linker picks BLX itself.  See docs/restructure/BUILD_FROM_GAME.md.

Regions: overlay ids, `itcm`, `arm9_main` (--skip=STEM,STEM leaves files whose
name starts with a stem to the image).  Data sections of a file are placed at
the original address; names missing from every header are read from the original
code (image evidence).

usage
    python tools/gamelink.py 12 11 14        # overlay ids
    python tools/gamelink.py itcm
    python tools/gamelink.py arm9_main --skip=unit_020911D4
Output is in build/gamelink/ovNNN/.
"""

from __future__ import annotations

import bisect
import json
import os
import re
import shutil
import struct
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(ROOT, "tools"))

import match            # noqa: E402
import gamebuild        # noqa: E402
OUT_OVERRIDE = None
import protofix as pf   # noqa: E402

LD = os.path.join(ROOT, "tools", "mwccarm", "mwccarm", "dsi", "1.1p1", "mwldarm.exe")
OUT = os.path.join(ROOT, "build", "gamelink")


# ---------------------------------------------------------------- ELF32 LE io

def read_elf(path):
    """Returns (sections, symbols).  sections: list of dict(name, type, flags,
    addr, off, size, align, idx); symbols: list of dict(name, value, size, info,
    shndx)."""
    d = open(path, "rb").read()
    shoff, = struct.unpack_from("<I", d, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", d, 0x2E)
    raw = [struct.unpack_from("<10I", d, shoff + i * shentsize) for i in range(shnum)]
    stro = raw[shstrndx][4]

    def nm(o, base):
        e = d.index(b"\0", base + o)
        return d[base + o:e].decode("latin1")
    secs = [dict(idx=i, name=nm(r[0], stro), type=r[1], flags=r[2], addr=r[3],
                 off=r[4], size=r[5], link=r[6], info=r[7], align=r[8], ent=r[9])
            for i, r in enumerate(raw)]
    syms = []
    for s in secs:
        if s["type"] == 2:
            strb = secs[s["link"]]["off"]
            for k in range(s["size"] // 16):
                o, v, sz, info, oth, shn = struct.unpack_from("<IIIBBH", d, s["off"] + k * 16)
                syms.append(dict(name=nm(o, strb), value=v, size=sz, info=info, shndx=shn))
    return d, secs, syms


def write_elf(path, sections, symbols):
    """sections: list of (name, flags, data, align).  symbols: list of
    (name, section_index_1based, value, size, is_func, is_global).  Local
    symbols are written first, as ELF requires."""
    shstr = b"\0"
    nameoff = {}

    def add_sh(n):
        nonlocal shstr
        nameoff[n] = len(shstr)
        shstr += n.encode() + b"\0"
    for s in sections:
        add_sh(s[0])
    for n in (".symtab", ".strtab", ".shstrtab"):
        add_sh(n)
    strtab = b"\0"
    ents = [struct.pack("<IIIBBH", 0, 0, 0, 0, 0, 0)]
    loc = [s for s in symbols if not s[5]]
    glb = [s for s in symbols if s[5]]
    for n, sec, val, size, fn, g in loc + glb:
        o = len(strtab)
        strtab += n.encode() + b"\0"
        info = ((1 if g else 0) << 4) | (2 if fn else 0)
        ents.append(struct.pack("<IIIBBH", o, val, size, info, 0, sec))
    symtab = b"".join(ents)
    body = b""
    hdrs = [struct.pack("<10I", *([0] * 10))]
    off = 0x34

    def put(data, align=4):
        nonlocal body, off
        pad = (-off) % align
        body += b"\0" * pad
        off += pad
        o = off
        body += data
        off += len(data)
        return o
    for n, fl, data, al in sections:
        o = put(data, max(al, 1))
        hdrs.append(struct.pack("<10I", nameoff[n], 1, fl, 0, o, len(data), 0, 0, al, 0))
    nsec = len(sections)
    o = put(symtab)
    hdrs.append(struct.pack("<10I", nameoff[".symtab"], 2, 0, 0, o, len(symtab),
                            nsec + 2, 1 + len(loc), 4, 16))
    o = put(strtab, 1)
    hdrs.append(struct.pack("<10I", nameoff[".strtab"], 3, 0, 0, o, len(strtab), 0, 0, 1, 0))
    o = put(shstr, 1)
    hdrs.append(struct.pack("<10I", nameoff[".shstrtab"], 3, 0, 0, o, len(shstr), 0, 0, 1, 0))
    shoff = off + ((-off) % 4)
    body += b"\0" * (shoff - off)
    hdr = bytearray(0x34)
    hdr[0:16] = b"\x7fELF\x01\x01\x01" + b"\0" * 9
    struct.pack_into("<HHIIIIIHHHHHH", hdr, 16, 1, 40, 1, 0, 0, shoff, 0x5000000,
                     0x34, 0, 0, 40, len(hdrs), len(hdrs) - 1)
    open(path, "wb").write(bytes(hdr) + body + b"".join(hdrs))


def add_alias_symbols(path, aliases):
    """Append global symbols to the object at `path`.  `aliases` is a list of
    (new_name, existing_name[, offset]): the new symbol copies value, type and
    section of the existing one (plus `offset`: an entry point inside a
    function, an asm label such as the runtime's _ll_udiv), so the linker sees
    a second, equally typed name for a function the file defines."""
    d, secs, syms = read_elf(path)
    st = [x for x in secs if x["type"] == 2][0]
    sx = secs[st["link"]]
    by = {y["name"]: y for y in syms if y["name"] and y["shndx"] != 0}
    strtab = bytearray(d[sx["off"]:sx["off"] + sx["size"]])
    sym = bytearray(d[st["off"]:st["off"] + st["size"]])
    for al in aliases:
        new, old = al[0], al[1]
        off = al[2] if len(al) > 2 else 0
        y = by[old]
        o = len(strtab)
        strtab += new.encode() + b"\0"
        sym += struct.pack("<IIIBBH", o, y["value"] + off, 0, y["info"] if not off else 0x12, 0, y["shndx"])
    buf = bytearray(d)
    while len(buf) % 4:
        buf += b"\0"
    so = len(buf)
    buf += sym
    to = len(buf)
    buf += strtab
    shoff, = struct.unpack_from("<I", d, 0x20)
    shent, = struct.unpack_from("<H", d, 0x2E)
    struct.pack_into("<II", buf, shoff + st["idx"] * shent + 16, so, len(sym))
    struct.pack_into("<II", buf, shoff + sx["idx"] * shent + 16, to, len(strtab))
    open(path, "wb").write(bytes(buf))


def rename_symbols(path, ren):
    """Rename symbols of the object at `path` (old -> new) by appending a new
    string table."""
    d, secs, syms = read_elf(path)
    st = [x for x in secs if x["type"] == 2][0]
    sx = secs[st["link"]]
    strtab = bytearray(d[sx["off"]:sx["off"] + sx["size"]])
    sym = bytearray(d[st["off"]:st["off"] + st["size"]])
    for k in range(len(sym) // 16):
        o = struct.unpack_from("<I", sym, k * 16)[0]
        e = strtab.index(b"\0", o)
        n = bytes(strtab[o:e]).decode("latin1")
        if n in ren:
            struct.pack_into("<I", sym, k * 16, len(strtab))
            strtab += ren[n].encode() + b"\0"
    buf = bytearray(d)
    while len(buf) % 4:
        buf += b"\0"
    so = len(buf)
    buf += sym
    to = len(buf)
    buf += strtab
    shoff, = struct.unpack_from("<I", d, 0x20)
    shent, = struct.unpack_from("<H", d, 0x2E)
    struct.pack_into("<II", buf, shoff + st["idx"] * shent + 16, so, len(sym))
    struct.pack_into("<II", buf, shoff + sx["idx"] * shent + 16, to, len(strtab))
    open(path, "wb").write(bytes(buf))


def set_align(path, al):
    """Set the alignment of sections ({index: align}); for a file that starts at
    an address that is not a multiple of 4."""
    d = bytearray(open(path, "rb").read())
    shoff, = struct.unpack_from("<I", d, 0x20)
    shent, = struct.unpack_from("<H", d, 0x2E)
    for i, a in al.items():
        struct.pack_into("<I", d, shoff + i * shent + 32, a)
    open(path, "wb").write(bytes(d))


def rename_sections(path, ren):
    """Give sections of the object at `path` new names ({index: name}) by
    appending to .shstrtab, so each data section can get its own place in the
    linker command file."""
    d = bytearray(open(path, "rb").read())
    shoff, = struct.unpack_from("<I", d, 0x20)
    shent, shnum, shstrndx = struct.unpack_from("<HHH", d, 0x2E)
    so, ss = struct.unpack_from("<II", d, shoff + shstrndx * shent + 16)
    tab = bytearray(d[so:so + ss])
    for i, n in ren.items():
        struct.pack_into("<I", d, shoff + i * shent, len(tab))
        tab += n.encode() + b"\0"
    while len(d) % 4:
        d += b"\0"
    no = len(d)
    d += tab
    struct.pack_into("<II", d, shoff + shstrndx * shent + 16, no, len(tab))
    open(path, "wb").write(bytes(d))


def externalize_sections(path, secs, names):
    """Make the symbols that live in sections `secs` (indices) undefined globals
    named names[(section, value)] and point every relocation at them.  Used for
    a second file that defines the same statics as another file: its references
    then go to the one placed copy."""
    d, st_secs, syms = read_elf(path)
    st = [x for x in st_secs if x["type"] == 2][0]
    sx = st_secs[st["link"]]
    strtab = bytearray(d[sx["off"]:sx["off"] + sx["size"]])
    sym = bytearray(d[st["off"]:st["off"] + st["size"]])
    buf = bytearray(d)
    new = {}
    nsym = len(sym) // 16
    for s in st_secs:
        if s["type"] != 4:
            continue
        for k in range(s["size"] // 12):
            o = s["off"] + 12 * k
            _o, info, _a = struct.unpack_from("<IIi", buf, o)
            y = syms[info >> 8]
            if y["shndx"] in secs:
                key = (y["shndx"], y["value"])
                if key not in new:
                    new[key] = nsym
                    strtab_o = len(strtab)
                    strtab += names[key].encode() + b"\0"
                    sym += struct.pack("<IIIBBH", strtab_o, 0, 0, 0x10, 0, 0)
                    nsym += 1
                struct.pack_into("<I", buf, o + 4, (new[key] << 8) | (info & 255))
    while len(buf) % 4:
        buf += b"\0"
    so = len(buf)
    buf += sym
    to = len(buf)
    buf += strtab
    shoff, = struct.unpack_from("<I", d, 0x20)
    shent, = struct.unpack_from("<H", d, 0x2E)
    struct.pack_into("<II", buf, shoff + st["idx"] * shent + 16, so, len(sym))
    struct.pack_into("<II", buf, shoff + sx["idx"] * shent + 16, to, len(strtab))
    open(path, "wb").write(bytes(buf))


CALL_RELS = (1, 10, 28, 29, 30, 109)   # PC24, THM_PC22, CALL, JUMP24, THM_JUMP24, ...


def call_sites(path):
    """[(name, rela section offset in file, index)] of every branch-and-link
    relocation against an undefined global symbol, in object order."""
    d, secs, syms = read_elf(path)
    res = []
    for s in secs:
        if s["type"] != 4:
            continue
        for k in range(s["size"] // 12):
            _o, info, _a = struct.unpack_from("<IIi", d, s["off"] + 12 * k)
            y = syms[info >> 8]
            if (info & 255) in CALL_RELS and y["shndx"] == 0 and (y["info"] >> 4) == 1 and y["name"]:
                res.append((y["name"], s["off"] + 12 * k))
    return res


def dup_call_symbols(path, newnames):
    """newnames: list of (name, new_name) in the order of call_sites() for the
    sites that get their own symbol.  Appends one undefined global symbol per
    entry and points that call relocation at it (the linker then makes one
    veneer per call site, as the original link did)."""
    d, secs, syms = read_elf(path)
    st = [x for x in secs if x["type"] == 2][0]
    sx = secs[st["link"]]
    strtab = bytearray(d[sx["off"]:sx["off"] + sx["size"]])
    sym = bytearray(d[st["off"]:st["off"] + st["size"]])
    buf = bytearray(d)
    byname = {}
    for i, y in enumerate(syms):
        if y["name"] and y["shndx"] == 0:
            byname[y["name"]] = y
    nsym = len(sym) // 16
    for site_off, new in newnames:
        _o, info, _a = struct.unpack_from("<IIi", buf, site_off)
        old = syms[info >> 8]
        o = len(strtab)
        strtab += new.encode() + b"\0"
        sym += struct.pack("<IIIBBH", o, 0, 0, old["info"], 0, 0)
        struct.pack_into("<I", buf, site_off + 4, (nsym << 8) | (info & 255))
        nsym += 1
    while len(buf) % 4:
        buf += b"\0"
    so = len(buf)
    buf += sym
    to = len(buf)
    buf += strtab
    shoff, = struct.unpack_from("<I", d, 0x20)
    shent, = struct.unpack_from("<H", d, 0x2E)
    struct.pack_into("<II", buf, shoff + st["idx"] * shent + 16, so, len(sym))
    struct.pack_into("<II", buf, shoff + sx["idx"] * shent + 16, to, len(strtab))
    open(path, "wb").write(bytes(buf))


# -------------------------------------------------------------------- driver

def lookup_symbol(name, ovid):
    """(address, kind) for a name the file headers do not list, from the same
    sources the resolver uses: a func_XXXXXXXX name carries its address and the
    ISA comes from match.isa_evidence (listings in asm/ and layout/symbols_sdk.json,
    which are image evidence); ovNNN_id is the overlay number; other names come
    from layout/symbols_sdk.json or the matched manifests.  None if unknown."""
    m = re.fullmatch(r"(?:func|sub)_([0-9A-Fa-f]{8})", name)
    if m:
        a = int(m.group(1), 16)
        ev = match.isa_evidence(a, region_name(ovid))
        return (a, ev[0]) if ev else None
    m = re.fullmatch(r"[gd]_([0-9A-Fa-f]{8})", name)
    if m:
        return int(m.group(1), 16), "data"
    m = re.fullmatch(r"ov(\d+)_id", name)
    if m:
        return int(m.group(1)), "data"
    for tab in (match.sdk_symbols(), match.matched_symbols()):
        if name in tab:
            a, th = tab[name]
            return a, "thumb" if th else "arm"
    return None


def header_symbols(raw):
    """All lines of the header's `symbols:` block, names with @ included (the
    shared parser stops at the first such name)."""
    res = {}
    m = re.match(r"\s*/\*.*?\*/", raw, re.S)
    if not m:
        return res
    on = False
    for line in m.group(0).splitlines():
        if re.match(r"^\s*\*?\s*symbols:\s*$", line):
            on = True
            continue
        if not on:
            continue
        sm = re.match(r"^\s*\*\s+(\S+)\s+(0x[0-9A-Fa-f]+)\s+(arm|thumb|data)\b", line)
        if sm:
            res.setdefault(sm.group(1), (int(sm.group(2), 16), sm.group(3)))
        elif re.match(r"^\s*\*\s*$", line):
            break
    return res


def follow_veneer(img, base, res):
    """If the branch target `res` = (addr, kind) is a linker veneer in the image
    (ARM `ldr pc, [pc, #-4]` or the Thumb `bx pc; nop; ldr ip; bx ip` form), return
    the address the veneer jumps to."""
    a, k = res
    i = a - base
    if 0 <= i < len(img) - 16:
        if img[i:i + 4] == bytes.fromhex("04f01fe5"):
            w = struct.unpack_from("<I", img, i + 4)[0]
            return (w & ~1, "thumb" if w & 1 else "arm")
        if img[i:i + 12] == bytes.fromhex("7847c04600c09fe51cff2fe1"):
            w = struct.unpack_from("<I", img, i + 12)[0]
            return (w & ~1, "thumb" if w & 1 else "arm")
    return res


def infer_from_relocs(t, name, img, base, rname, secaddr):
    """(address, kind) of an undefined `name`, read from the ORIGINAL code at
    the places where file `t` uses it: the pool word of an ABS32 relocation or
    the target of a branch-and-link.  `secaddr` maps an object section index to
    its linked address (from a first link).  Uses the image.  None if no site
    can be decoded."""
    d, secs, syms = read_elf(t["obj"])
    off = secaddr
    for s in secs:
        if s["type"] != 4 or s["info"] not in off:
            continue
        for k in range(s["size"] // 12):
            o, info, add = struct.unpack_from("<IIi", d, s["off"] + 12 * k)
            if syms[info >> 8]["name"] != name:
                continue
            typ = info & 255
            site = off[s["info"]] + o
            i = site - base
            if not 0 <= i < len(img) - 4:
                continue
            if typ == 2:
                w = struct.unpack_from("<I", img, i)[0] - add
                ev = match.isa_evidence(w & ~1, rname)
                return (w & ~1, ev[0]) if ev else (w, "data")
            if typ == 10:
                hi, lo = struct.unpack_from("<HH", img, i)
                if hi & 0xF800 != 0xF000:
                    continue
                v = ((hi & 0x7FF) << 12) | ((lo & 0x7FF) << 1)
                if v & 0x400000:
                    v -= 0x800000
                tgt = site + 4 + v
                return follow_veneer(img, base, (tgt & ~3, "arm") if lo & 0xF800 == 0xE800 else (tgt, "thumb"))
            if typ in (1, 28):
                w = struct.unpack_from("<I", img, i)[0]
                v = w & 0xFFFFFF
                if v & 0x800000:
                    v -= 0x1000000
                v <<= 2
                if (w >> 28) == 0xF:
                    v += (w >> 24 & 1) * 2
                    return follow_veneer(img, base, (site + 8 + v, "thumb"))
                return follow_veneer(img, base, (site + 8 + v, "arm"))
    return None


def def_address(t, name, ovid):
    """Original address of a function the file defines, or None: the header,
    a func_XXXXXXXX name, layout/runtime_arm9.txt (ARM9 only).  Not
    layout/symbols_sdk.json: some game files define a function under an SDK
    name that the SDK has at another address (CARD_SetPulledOutCallback in
    unit_02066B84, OS_KillThread in mystery_data)."""
    if name in t["syms"] and t["syms"][name][1] in ("arm", "thumb"):
        return t["syms"][name][0]
    m = re.fullmatch(r"(?:func|sub)_([0-9A-Fa-f]{8})", name)
    if m:
        return int(m.group(1), 16)
    if ovid in ("arm9_main", "itcm"):
        rt = {v: k for k, v in match.runtime_addresses().items()}
        if name in rt:
            return rt[name]
    return None


def code_pieces(t, ovid, base, end, starts):
    """Split the code sections of a file (mwccarm writes one .text section per
    function, in source order) into runs that are contiguous in the original.
    A run starts where a function's known original address lies outside the
    room of the current run (before its start, or at or past the next file's
    start): a file whose functions are not contiguous because other files lie
    between them, e.g. the MSL runtime parts.  Smaller differences are left to
    the linker (veneers, alignment; names can also sit a word into a function).  Returns a list of
    dict(sec, idxs, addr, size); the first run keeps the name .text, the
    others are renamed .txK so the .lcf can place them."""
    secs = t["secs"]
    names = {}
    for y in t["osyms"]:
        if y["name"] and not y["name"].startswith("$") and y["value"] == 0 and (y["info"] & 15) == 2:
            names.setdefault(y["shndx"], y["name"])
    runs = []
    cur = None
    for s in secs:
        a = def_address(t, names.get(s["idx"], ""), ovid)
        if a is not None and not (base <= a < end):
            a = None
        if cur is None:
            cur = dict(addr=t["addr"], idxs=[s["idx"]], size=s["size"])
            runs.append(cur)
            continue
        al = max(s["align"], 1)
        est = cur["addr"] + cur["size"]
        est += (-est) % al
        nxt = min([x for x in starts if x > cur["addr"]] + [end])
        if a is not None and not (cur["addr"] <= a < nxt):
            cur = dict(addr=a, idxs=[s["idx"]], size=s["size"])
            runs.append(cur)
            continue
        cur["size"] = est - cur["addr"] + s["size"]
        cur["idxs"].append(s["idx"])
    for k, r in enumerate(runs):
        r["sec"] = ".text" if k == 0 else ".tx%d" % k
    return runs or [dict(sec=".text", idxs=[], addr=t["addr"], size=0)]


def unit_room(tus, i, a, end):
    """True if address `a` lies in the room of one of the code runs of file i
    (from the run's start up to the next run of any file)."""
    return any(p["addr"] <= a < p["addr"] + p["room"] for p in tus[i]["pieces"])


def referenced_sections(d, path):
    """Indices of the sections that a relocation of the object at `path` points
    into (through a symbol defined there)."""
    _d, secs, syms = read_elf(path)
    res = set()
    for s in secs:
        if s["type"] != 4:
            continue
        for k in range(s["size"] // 12):
            _o, info, _a = struct.unpack_from("<IIi", _d, s["off"] + 12 * k)
            res.add(syms[info >> 8]["shndx"])
    return res


def region_name(ovid):
    return ovid if isinstance(ovid, str) else "ov%03d" % ovid


SRC_DIR = {"arm9_main": "arm9", "itcm": "arm9_autoload0_ITCM"}


def overlay_info(ovid):
    lay = json.load(open(os.path.join(ROOT, "layout", "layout.json"), encoding="utf-8"))
    if ovid == "arm9_main":
        a = lay["arm9"]
        st = a["static"]
        img = open(os.path.join(ROOT, "extract", a["decompressed_file"]), "rb").read()
        return st["ram_start"], img[st["src_offset"]:st["src_offset"] + st["size"]]
    if ovid == "itcm":
        a = lay["arm9"]
        al = a["autoloads"][0]
        img = open(os.path.join(ROOT, "extract", a["decompressed_file"]), "rb").read()
        return al["ram_start"], img[al["src_offset"]:al["src_offset"] + al["code_size"]]
    o = [x for x in lay["overlays"] if x["id"] == ovid][0]
    img = open(os.path.join(ROOT, "extract", o["decompressed_file"]), "rb").read()
    return o["ram_start"], img


def link_overlay(ovid, interworking=True, absolute_only=False, verbose=True, skip=(), src_dir=None, data_tail=None, out=None, data_aliases=None, bss=None):
    base, img = overlay_info(ovid)
    end = base + len(img)
    d = src_dir or os.path.join(ROOT, "src", "game", SRC_DIR.get(ovid) or region_name(ovid))
    work = os.path.join(out or OUT, region_name(ovid))
    shutil.rmtree(work, ignore_errors=True)
    os.makedirs(work)
    match.load_all_regions()
    match.evidence()

    tus = []          # (addr, stem, objpath, text size)
    syms = {}
    for f in sorted(os.listdir(d)):
        if not f.endswith(".c") or f.startswith("_") or not os.path.isfile(os.path.join(d, f)):
            continue
        if any(f.startswith(k) for k in skip):
            continue          # left to the image (a file another lane has open)
        raw = open(os.path.join(d, f), encoding="latin1").read()
        h, st = gamebuild._settings(raw)
        addr = int(h["address"], 16)
        tsyms = {n: (a, k) for n, (a, k, _r) in h["symbols"].items()}
        tsyms.update(header_symbols(raw))
        sub = os.path.join(work, f[:-2])
        os.makedirs(sub)
        obj, cmd, log, rc = match.compile_tu(os.path.join(d, f), st["compiler"],
                                             st["flags"].split(), st["isa"] == "thumb",
                                             st["lang"] or None, sub)
        if obj is None:
            return dict(ov=ovid, ok=False, why="compile %s: %s" % (f, log[:200]))
        _d, secs, osyms = read_elf(obj)
        alloc = [s for s in secs if s["flags"] & 2]
        names = sorted(set(s["name"] for s in alloc))
        tus.append(dict(addr=addr, stem=f[:-2], obj=obj, secs=alloc, osyms=osyms, names=names, syms=tsyms,
                        odata=_d))
    tus.sort(key=lambda t: t["addr"])

    other = sorted(set(n for t in tus for n in t["names"]) - {".text", ".data", ".rodata", ".bss"})
    if other:
        return dict(ov=ovid, ok=False, why="TU sections other than text/data: %s" % other)
    dgroups = []          # data sections of the files: (tu index, name, start, end, nobits)
    seen_data = {}
    unplaced = []
    dead_at = 0x0F000000  # unreferenced data sections go here, outside every region
    dead = 0
    for ti, t in enumerate(tus):
        t["dsecs"] = [x for x in t["secs"] if x["name"] != ".text"]
        t["secs"] = [x for x in t["secs"] if x["name"] == ".text"]
        used = referenced_sections(t["odata"], t["obj"])
        if data_tail:
            t["tail_secs"] = [x for x in t["dsecs"]]
            t["dsecs"] = []
        for x in t["dsecs"]:
            if x["idx"] not in used:
                # nothing refers to it (a function-local static const double the
                # compiler also put in the literal pool): the original link
                # dead-stripped it; -nodeadstrip keeps it, so park it outside
                x["addr"] = dead_at
                dead_at += (x["size"] + 7) & ~7
                dead += 1
                continue
            votes = {}
            for y in t["osyms"]:
                if y["shndx"] == x["idx"] and y["name"] in t["syms"] and t["syms"][y["name"]][1] == "data":
                    b = t["syms"][y["name"]][0] - y["value"]
                    votes[b] = votes.get(b, 0) + 1
            a = max(votes, key=lambda b: votes[b]) if votes else None
            if a is None and x["type"] == 1:
                blob = t["odata"][x["off"]:x["off"] + x["size"]]
                hits = [m.start() for m in re.finditer(re.escape(blob), img)]
                if len(hits) > 1:
                    # several equal strings: keep the one this file's own literal pool points at
                    code = img[t["addr"] - base:(tus[ti + 1]["addr"] if ti + 1 < len(tus) else end) - base]
                    hits = [h for h in hits if struct.pack("<I", base + h) in code]
                if len(hits) == 1:
                    a = base + hits[0]
                else:
                    unplaced.append("%s %s: %d places in the image" % (t["stem"], x["name"], len(hits)))
                    continue
            if a is None:
                unplaced.append("%s %s: no address" % (t["stem"], x["name"]))
                continue
            x["addr"] = a
        t["secren"] = {}
        t["dupsec"] = {}
        for x in t["dsecs"]:
            if "addr" not in x:
                continue
            key = (x["name"], x["addr"], x["size"], x["type"])
            if key in seen_data:
                t["dupsec"][x["idx"]] = seen_data[key]
                continue
            seen_data[key] = x["addr"]
            nm = ".d%d_%d" % (ti, x["idx"])
            t["secren"][x["idx"]] = nm
            dgroups.append((ti, nm, x["addr"], x["addr"] + x["size"], x["type"] == 8))
    for t in tus:
        t["defs"] = set(y["name"] for y in t["osyms"] if y["name"] and y["shndx"] != 0)
        t["pieces"] = [] if t["stem"].endswith(".zdata") else code_pieces(t, ovid, base, end, [u["addr"] for u in tus if not u["stem"].endswith(".zdata")])
        t["size"] = sum(s["size"] for s in t["secs"])
        t["end"] = t["addr"] + t["size"]
        for p in t["pieces"]:
            p["end"] = p["addr"] + p["size"]
    starts = sorted(p["addr"] for t in tus for p in t["pieces"])
    for t in tus:
        for p in t["pieces"]:
            nxt = [s for s in starts if s > p["addr"]]
            p["room"] = (nxt[0] if nxt else end) - p["addr"]
    defined = set()
    undef = set()
    for t in tus:
        for s in t["osyms"]:
            if s["name"] and s["shndx"] == 0 and (s["info"] >> 4) == 1:
                undef.add(s["name"])
            elif s["name"] and s["shndx"] != 0 and (s["info"] >> 4) == 1:
                defined.add(s["name"])
    undef -= defined
    undef -= set(data_aliases or {})
    # The same local name (site, config, ...) can mean different addresses in
    # different files.  Give each distinct meaning its own symbol name, renamed
    # in the object of the files that use it.
    first = {}
    gsyms = {}
    for t in tus:
        t["rename"] = {}
        for n, v in t["syms"].items():
            gsyms.setdefault(n, v)
    # one name defined by two files (the original had two functions of that name):
    # the later definition and the references whose header address falls in its
    # file get a second name
    defs_of = {}
    for ti, t in enumerate(tus):
        for y in t["osyms"]:
            if y["name"] and y["shndx"] != 0 and (y["info"] >> 4) == 1:
                defs_of.setdefault(y["name"], []).append(ti)
    for n, lst in defs_of.items():
        if len(lst) == 1:
            # defined once, but another file means a different address by this name
            u = tus[lst[0]]
            for ti, t in enumerate(tus):
                if ti == lst[0] or n not in t["syms"]:
                    continue
                a, k = t["syms"][n]
                if k in ("arm", "thumb") and not unit_room(tus, lst[0], a, end):
                    en = "%s__%X" % (n, a)
                    t["rename"][n] = en
                    syms[en] = (a, k)
                    undef.add(en)
        if len(lst) < 2:
            continue
        for k in range(1, len(lst)):
            tus[lst[k]]["rename"][n] = "%s__dup%d" % (n, k)
        for ti, t in enumerate(tus):
            if ti in lst or n not in t["syms"]:
                continue
            a = t["syms"][n][0]
            for k in range(1, len(lst)):
                if unit_room(tus, lst[k], a, end):
                    t["rename"][n] = "%s__dup%d" % (n, k)
    for t in tus:
        t["defs"] = set(t["rename"].get(n, n) for n in t["defs"])
    for t in tus:
        for y in t["osyms"]:
            n = y["name"]
            if not (n and y["shndx"] == 0 and (y["info"] >> 4) == 1 and n in undef):
                continue
            if n in t["syms"]:
                a, k = t["syms"][n]
            else:
                found = syms.get(n) or gsyms.get(n) or lookup_symbol(n, ovid)
                if found is None:
                    continue       # reported as missing below
                a, k = found
            key = (a, k)
            if n not in first:
                first[n] = key
                syms[n] = key
            elif first[n] != key:
                en = "%s__%X" % (n, a)
                t["rename"][n] = en
                syms[en] = key
                undef.add(en)

    # One symbol per call site of a function outside the overlay: the original
    # link made one veneer per call (also across files), mwldarm shares them.
    seen = {}
    for t in tus:
        t["dup"] = []
        for n, off in call_sites(t["obj"]):
            en = t["rename"].get(n, n)
            if en not in undef or en not in syms:
                continue
            a = syms[en][0]
            if base <= a < end:
                continue
            c = seen.get(en, 0)
            seen[en] = c + 1
            if c:
                nn = "%s__v%d" % (en, c)
                t["dup"].append((off, nn))
                syms[nn] = syms[en]
                undef.add(nn)

    addr2name = {}
    funcs1 = []     # (address, size, name) of the global functions of the first link

    def inner_entry(a):
        """(name, offset) if `a` lies inside a function defined by a file."""
        k = bisect.bisect_right(funcs1, (a, 1 << 32, "")) - 1
        if k >= 0:
            fa, fs, fn = funcs1[k]
            if fa < a < fa + fs:
                return fn, a - fa
        return None
    plan, pi, redone, renamed_again = [1, 2], 0, False, False
    while pi < len(plan):
        pas = plan[pi]
        pi += 1
        aliases = []
        # gaps between files, as binary sections from the image
        gaps = []
        if pas == 2:
            occ = [(p["addr"], p["end"]) for t in tus for p in t["pieces"]] + ([(data_tail[0], data_tail[3])] if data_tail else []) + [(a, b) for _ti, _n, a, b, _nb in dgroups
                                                          if a < end and b > base]
            cur = base
            for a, b in sorted(occ):
                if a > cur:
                    gaps.append((cur, a))
                elif a < cur:
                    who = [t["stem"] for t in tus for p in t["pieces"] if p["addr"] <= a < p["end"] or p["addr"] < cur <= p["end"]]
                    who += [tus[ti]["stem"] + " data" for ti, _n, x, y, _nb in dgroups if x <= a < y or x < cur <= y]
                    return dict(ov=ovid, ok=False, why="files or data overlap at %08X (%s)" % (a, ", ".join(who)))
                cur = b
            if cur < end:
                gaps.append((cur, end))

        def in_gap(a):
            for i, (g0, g1) in enumerate(gaps):
                if g0 <= a < g1:
                    return i
            return None

        def in_tu(a):
            return any(p["addr"] <= a < p["end"] for t in tus for p in t["pieces"])

        # classify undefined names
        ext_funcs, gap_funcs, absol, missing = [], {}, [], []
        for n in sorted(undef):
            if n not in syms:
                found = gsyms.get(n) or lookup_symbol(n, ovid)
                if found is None:
                    missing.append(n)
                    if pas == 1:
                        absol.append((n, tus[0]["addr"]))     # placeholder, in branch range
                    continue
                syms[n] = found
            a, k = syms[n]
            if k in ("arm", "thumb"):
                if absolute_only:
                    absol.append((n, a | (k == "thumb")))
                elif in_gap(a) is not None:
                    gap_funcs.setdefault(in_gap(a), []).append((n, a, k))
                elif in_tu(a) or (pas == 1 and base <= a < end):
                    if pas == 2 and a in addr2name:
                        aliases.append((n, addr2name[a]))   # second name of a function of a file
                    elif pas == 2 and inner_entry(a):
                        aliases.append((n,) + inner_entry(a))   # entry point inside a function
                    else:
                        absol.append((n, a | (k == "thumb")))
                else:
                    ext_funcs.append((n, a, k))
            else:
                absol.append((n, a))
        if missing and pas == 2:
            return dict(ov=ovid, ok=False, why="no address for %s" % missing[:6])
        pending = missing

        # objects
        mem, sect = [], []
        names = []
        for i, t in enumerate(tus):
            shutil.copy(t["obj"], os.path.join(work, "t%d.o" % i))
            mine = [al for al in aliases if al[1] in t["defs"]]
            if t["rename"]:
                rename_symbols(os.path.join(work, "t%d.o" % i), t["rename"])
            if mine:
                add_alias_symbols(os.path.join(work, "t%d.o" % i), mine)
            if t["dup"]:
                dup_call_symbols(os.path.join(work, "t%d.o" % i), t["dup"])
            if t["dupsec"]:
                nm = {}
                for (si, v) in [(y["shndx"], y["value"]) for y in t["osyms"] if y["shndx"] in t["dupsec"]]:
                    if (si, v) not in nm:
                        nm[(si, v)] = "__dup%d_%d_%d" % (i, si, v)
                        absol.append((nm[(si, v)], t["dupsec"][si] + v))
                externalize_sections(os.path.join(work, "t%d.o" % i), set(t["dupsec"]), nm)
            for p in t["pieces"]:
                if p["addr"] % 4 and p["idxs"]:
                    set_align(os.path.join(work, "t%d.o" % i), {p["idxs"][0]: 2 if p["addr"] % 4 == 2 else 1})
            ren = dict(t["secren"])
            for k, p in enumerate(t["pieces"]):
                if k:
                    ren.update({x: p["sec"] for x in p["idxs"]})
            if ren:
                rename_sections(os.path.join(work, "t%d.o" % i), ren)
            if t["stem"].endswith(".zdata"):
                # companion data TU: its anchor function goes outside the overlay
                mem.append(("z%d" % i, 0x0E000000 + 0x100 * i, 0x100))
                sect.append(" .z%d : { t%d.o (.text) } > z%d" % (i, i, i))
            for k, p in enumerate(t["pieces"]):
                tag = "t%d" % i if k == 0 else "t%d_%d" % (i, k)
                mem.append((tag, p["addr"], p["size"] if pas == 2 else p["room"]))
                sect.append(" .%s : { t%d.o (%s) } > %s" % (tag, i, p["sec"], tag))
            names.append("t%d.o" % i)
        if data_tail:
            t0, s0, s1, e0 = data_tail
            mem.append(("dtail", t0, e0 - t0))
            body = []
            for sname in (".rodata",):
                for i, t in enumerate(tus):
                    if any(x["name"] == sname for x in t["tail_secs"]):
                        body.append("t%d.o (%s)" % (i, sname))
            body.append(". = ALIGN(4); SINIT_START = .; WRITEW 0; SINIT_END = .;" + " WRITEW 0;" * ((s1 - s0 - 4) // 4))
            sect.append(" .dtail : { %s } > dtail" % " ".join(body))
            mem[-1] = ("dtail", t0, s1 - t0)
            mem.append(("ddata", s1, e0 - s1))
            body = []
            for sname in (".data",):
                for i, t in enumerate(tus):
                    if any(x["name"] == sname for x in t["tail_secs"]):
                        body.append("t%d.o (%s)" % (i, sname))
            sect.append(" .ddata : { %s } > ddata" % " ".join(body))
            if any(x["name"] == ".bss" for t in tus for x in t["tail_secs"]):
                if not bss:
                    return dict(ov=ovid, ok=False, why="bss in data mode but the overlay has no .bss")
                mem.append(("dbss", bss[0], bss[1] - bss[0]))
                sect.append(" .dbss : { %s } > dbss" % " ".join(
                    "t%d.o (.bss)" % i for i, t in enumerate(tus) if any(x["name"] == ".bss" for x in t["tail_secs"])))
        for j, (ti, nm, a, b, _nb) in enumerate(dgroups):
            mem.append(("d%d" % j, a, b - a))
            sect.append(" .d%d : { t%d.o (%s) } > d%d" % (j, ti, nm, j))
        for i, (g0, g1) in enumerate(gaps):
            data = img[g0 - base:g1 - base]
            secs = [(".gap", 3, data, 1)]
            sy = [("__gap%d" % i, 1, 0, 0, False, True)]
            if not any(a == g0 for _n, a, _k in gap_funcs.get(i, [])):
                sy.insert(0, ("$d", 1, 0, 0, True, False))
            for n, a, k in gap_funcs.get(i, []):
                sy.append(("$t" if k == "thumb" else "$a", 1, a - g0, 0, True, False))
                sy.append((n, 1, a - g0, 0, True, True))
            write_elf(os.path.join(work, "g%d.o" % i), secs, sy)
            mem.append(("g%d" % i, g0, g1 - g0))
            sect.append(" .g%d : { g%d.o (.gap) } > g%d" % (i, i, i))
            names.append("g%d.o" % i)
        if ext_funcs:
            secs, sy = [], []
            byaddr = {}
            for n, a, k in ext_funcs:
                byaddr.setdefault((a, k), []).append(n)
            for j, ((a, k), ns) in enumerate(sorted(byaddr.items())):
                secs.append((".cal%d" % j, 6, bytes(2 if k == "thumb" else 4), 4 if k == "arm" else 2))
                sy.append(("$t" if k == "thumb" else "$a", j + 1, 0, 0, True, False))
                for q, n in enumerate(ns):
                    sy.append((n, j + 1, 0,
                               (2 if k == "thumb" else 4) if q == 0 else 0, True, True))
                mem.append(("c%d" % j, a, 4))
                sect.insert(0, " .c%d : { stubs.o (.cal%d) } > c%d" % (j, j, j))
            write_elf(os.path.join(work, "stubs.o"), secs, sy)
            names.append("stubs.o")
        # a stub that falls inside the overlay would overlap its regions
        for n, a, k in ext_funcs:
            if base <= a < end:
                return dict(ov=ovid, ok=False, why="callee %s at %08X inside overlay, not in a gap or file" % (n, a))
        lcf = "MEMORY {\n" + "".join(" %s : ORIGIN = 0x%08X, LENGTH = 0x%X\n" % m for m in mem) + "}\n"
        lcf += "SECTIONS {\n" + "\n".join(sect) + "\n"
        lcf += "".join(" %s = 0x%08X;\n" % (n, a) for n, a in absol)
        lcf += "".join(" %s = %s;\n" % (n, c) for n, c in sorted((data_aliases or {}).items()))
        lcf += "}\n"
        open(os.path.join(work, "ov.lcf"), "w").write(lcf)
        cmd = [LD, "-proc", "arm946e"] + (["-interworking"] if interworking else []) + \
              ["-nostdlib", "-nodefaults", "-nodeadstrip", "-main", "", "-application", "-map",
               "-o", "ov.elf", "ov.lcf"] + names
        env = dict(os.environ)
        p = subprocess.run(cmd, cwd=work, capture_output=True, text=True, env=env)
        log = p.stdout + p.stderr
        open(os.path.join(work, "link.log"), "w").write(log)
        elf = os.path.join(work, "ov.elf")
        if p.returncode != 0 or not os.path.exists(elf):
            return dict(ov=ovid, ok=False, why="link failed: " + " | ".join(
                l for l in log.splitlines() if l.startswith("#") and "Warning" not in l)[:300])
        data, secs, esyms = read_elf(elf)
        if pas == 1:
            eaddr = {}
            for y in esyms:
                if y["name"] and y["shndx"] != 0 and not y["name"].startswith("$"):
                    eaddr.setdefault(y["name"], y["value"] & ~1)
            # a header that gives a defined name another address means a different function
            changed = False
            for t in tus:
                for n, (a, k) in t["syms"].items():
                    if k in ("arm", "thumb") and n in eaddr and n not in t["defs"] and n not in t["rename"]                             and eaddr[n] != (a & ~1) and n in defined:
                        en = "%s__%X" % (n, a)
                        t["rename"][n] = en
                        syms[en] = (a, k)
                        undef.add(en)
                        changed = True
            if changed and not renamed_again:
                renamed_again = True
                plan.insert(pi, 1)
        if pas == 1 and pending:
            for n in pending:
                for t in tus:
                    if not any(y["name"] == n and y["shndx"] == 0 for y in t["osyms"]):
                        continue
                    sa = {}
                    for y in t["osyms"]:
                        if y["shndx"] and y["value"] == 0 and y["name"] in eaddr and not y["name"].startswith("$"):
                            sa.setdefault(y["shndx"], eaddr[y["name"]])
                    r = infer_from_relocs(t, n, img, base, region_name(ovid), sa)
                    if r:
                        syms[n] = r
                        if not redone:
                            plan.insert(pi, 1)       # measure again with the real addresses (veneers)
                            redone = True
                        break
        if pas == 1:
            addr2name.clear()
            funcs1[:] = sorted((y["value"] & ~1, y["size"], y["name"]) for y in esyms
                               if y["name"] and y["shndx"] != 0 and (y["info"] & 15) == 2 and (y["info"] >> 4) == 1)
            for y in esyms:
                if y["name"] and y["shndx"] != 0 and (y["info"] & 15) == 2 and (y["info"] >> 4) == 1:
                    addr2name.setdefault(y["value"] & ~1, y["name"])
        out = bytearray(len(img))
        got = bytearray(len(img))
        for s in secs:
            if s["type"] == 1 and s["size"] and base <= s["addr"] < end:
                out[s["addr"] - base:s["addr"] - base + s["size"]] = data[s["off"]:s["off"] + s["size"]]
                got[s["addr"] - base:s["addr"] - base + s["size"]] = b"\1" * s["size"]
        if pas == 1:
            for t in tus:
                for p in t["pieces"]:
                    p["size"] = max(s["size"] for s in secs if s["type"] == 1 and s["addr"] == p["addr"])
                    p["end"] = p["addr"] + p["size"]
                t["size"] = sum(p["size"] for p in t["pieces"])
                t["end"] = t["pieces"][0]["end"] if t["pieces"] else t["addr"]
            continue
        # a .bss stand-in that sits inside the image: the original holds initialised
        # data there (the C file declares it uninitialised); take it from the image
        standin = 0
        for _ti, _n, a, b, nb in dgroups:
            if nb and base <= a < end:
                standin += min(b, end) - a
                out[a - base:min(b, end) - base] = img[a - base:min(b, end) - base]
                got[a - base:min(b, end) - base] = b"" * (min(b, end) - a)
        code_diff = []
        for t in tus:
            bad = [i for p in t["pieces"] for i in range(p["addr"] - base, p["end"] - base)
                   if out[i] != img[i] or not got[i]]
            if bad:
                code_diff.append((t["stem"], len(bad), [hex(base + b) for b in bad[:4]]))
        whole = bytes(out) == img
        open(os.path.join(work, "ov.bin"), "wb").write(bytes(out))
    tail_diff = None
    if data_tail:
        bad = [i for i in range(data_tail[0] - base, data_tail[3] - base) if out[i] != img[i] or not got[i]]
        tail_diff = (len(bad), [hex(base + b) for b in bad[:8]])
        lk = {y["name"]: y["value"] for y in esyms if y["name"] in ("SINIT_START", "SINIT_END")}
        tail_diff += ({k: hex(v) for k, v in lk.items()},)
    return dict(ov=ovid, ok=whole and not code_diff, tail_diff=tail_diff, gaps=[(hex(a), hex(b)) for a, b in gaps], files=len(tus), code_bytes=sum(t["size"] for t in tus),
                gap_bytes=sum(g1 - g0 for g0, g1 in gaps), size=len(img),
                bss_standin_bytes=standin, data_sections=len(dgroups), dead_data=dead, unplaced_data=unplaced, typed_stubs=len(ext_funcs), gap_funcs=sum(len(v) for v in gap_funcs.values()),
                absolute=len(absol), diffs=code_diff,
                units=[dict(stem=t["stem"], addr=t["addr"], end=t["end"],
                            pieces=[(p["addr"], p["end"]) for p in t["pieces"]]) for t in tus],
                split=[t["stem"] for t in tus if len(t["pieces"]) > 1])


def main(argv):
    mode = {}
    ids = []
    for a in argv:
        if a == "--absolute":
            mode["absolute_only"] = True
        elif a.startswith("--skip="):
            mode["skip"] = tuple(x for x in a[7:].split(",") if x)
        elif a == "--no-interworking":
            mode["interworking"] = False
        else:
            ids.append(a if a in SRC_DIR else int(a))
    rc = 0
    for i in ids:
        r = link_overlay(i, **mode)
        print("%s %s %s" % (region_name(i), "PASS" if r["ok"] else "FAIL", {k: v for k, v in r.items() if k not in ("ov", "ok", "units")}))
        rc |= 0 if r["ok"] else 1
    return rc


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
