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
    python tools/gamelink.py arm9_main
    python tools/gamelink.py arm9_main --unplaced          # also link unplaced/*.c
    python tools/gamelink.py arm9_main --extra=DIR         # files of DIR replace/add
A file whose functions are not contiguous in the original is linked as several
runs, one .lcf region each (see code_pieces).
Output is in build/gamelink/ovNNN/.

Data mode (overlays only):
    python tools/datagen.py companions 12            # writes build/datac/ov012/
    python tools/gamelink.py 12 --data --extra=build/datac/ov012
The .rodata, .data and .bss of every file (and of the companion files
<stem>.zdata.c that tools/datagen.py writes) are not placed at header addresses
but linked as the overlay's data tail: one segment with the .rodata of all files
in link order, ALIGN(4), the static-initialiser terminator (WRITEW 0), ALIGN(32);
one segment with the .data; one with the .bss.  A companion is linked right after
its code file (a <stem>.zpre.c companion right before it); its anchor function goes
outside the overlay.  DIR/datalink.json (from datagen) gives the tail borders, the
linker aliases (second names of an object, names inside an object) and the files'
own data sections with their original addresses ("own"): those link in address
order, and one at a multiple of 4 is given 4-byte alignment.  Output is in
build/gamelink_data/ovNNN/.

Data mode for the ARM9 static module (tools/arm9data.py writes the companions):
    python tools/arm9data.py
    python tools/gamelink.py arm9_main --data --extra=build/datac/arm9
.rodata and .data (0x0209D870..SDK_STATIC_BSS_START) follow each other in one
segment (datalink.json "nosinit"), .bss is the third segment.  Only the sections
listed in "own" and those of the companions go to the tail; crt0's own .rodata and
the dead statics are placed as in the plain link.  _start_BuildParams (with the
.version strings, crt0.c) and the SHA-1 constants (sha1.c) are source and are placed
by their header symbols like crt0's other .rodata; "fixed" in datalink.json is empty.  The zero padding after a Thumb file is made
by the linker (ALIGN(4)).  An own section lying inside a bigger one is parked.
Left to the image: the secure area gaps (0x02004000..0x02004800).

Data mode pads (all regions): the 2 zero bytes after a Thumb file whose next item sits at a
multiple of 4 are made by the linker (ALIGN(4)), not copied from the image.  Every complete
run writes ov.json next to ov.bin (ok, gaps, bss stand-ins, SHA-1 of ov.bin): the ranges
of the result that came from the image.  tools/romlink.py reads it to build the whole ROM.
"""

from __future__ import annotations

import bisect
import hashlib
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

import match            # noqa: E402
import gamebuild        # noqa: E402
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
    by = {}
    for y in syms:
        if y["name"] and y["shndx"] != 0 and (y["name"] not in by or (y["info"] >> 4) == 1):
            by[y["name"]] = y          # a global name wins over a local one
    strtab = bytearray(d[sx["off"]:sx["off"] + sx["size"]])
    sym = bytearray(d[st["off"]:st["off"] + st["size"]])
    for al in aliases:
        new, old = al[0], al[1]
        off = al[2] if len(al) > 2 else 0
        y = by[old]
        o = len(strtab)
        strtab += new.encode() + b"\0"
        # always global: the old name may be a static (local) function of the file
        sym += struct.pack("<IIIBBH", o, y["value"] + off, 0, (0x10 | (y["info"] & 15)) if not off else 0x12, 0,
                           y["shndx"])
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
                if ev and not base <= w < base + len(img) and not re.search(r"asm/(arm9|twl)\b", ev[1]):
                    # outside the region, the answer may come from another overlay
                    # that shares the RAM window (a data word read as a Thumb
                    # function): without a static-module label it stays data
                    ev = None
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
    if ovid == 230:
        # overlay 230 keeps most of its code encrypted in the ROM: the code the game runs is
        # the decrypted view (tools/ovcrypt.py), so that is what src/game/ov230 is linked and
        # compared against; tools/romlink.py encrypts the linked result for the ROM
        import ovcrypt
        v = ovcrypt.load(ROOT)
        return o["ram_start"], v.data
    img = open(os.path.join(ROOT, "extract", o["decompressed_file"]), "rb").read()
    return o["ram_start"], img


def is_companion(stem):
    return re.search(r"\.z(data|pre|fix)(_\d+)?$", stem) is not None


def link_rank(stem):
    """A <stem>.zpre companion links before its code file, a .zdata one after it
    (<stem>.zdata_N, N = 1, 2, ...: the pieces of a split companion, in order)."""
    m = re.search(r"_(\d+)$", stem)
    n = int(m.group(1)) if m else 0
    return n if re.search(r"\.zpre(_\d+)?$", stem) else 100000 + n if is_companion(stem) else 50000


def registry_sizes(rname):
    """address -> size of the data objects of layout/data_objects.json for a region."""
    try:
        reg = json.load(open(os.path.join(ROOT, "layout", "data_objects.json")))["regions"]
    except (OSError, ValueError, KeyError):
        return {}
    r = reg.get({"arm9_main": "arm9"}.get(rname, rname)) or {}
    return {int(o["addr"], 16): o["size"] for o in r.get("objects", [])}


_RUN = {}          # per-run work dir and the dir that gets the results (see link_overlay)
PUBLISH = ("ov.elf", "ov.lcf", "ov.bin", "ov.json", "link.log")


def _publish(work, pub):
    """Copy the result files of a run to the shared dir, each one atomically."""
    os.makedirs(pub, exist_ok=True)
    for n in PUBLISH:
        src = os.path.join(work, n)
        if os.path.isfile(src):
            tmp = os.path.join(pub, ".%s.%d.tmp" % (n, os.getpid()))
            shutil.copyfile(src, tmp)
            for k in range(50):         # Windows refuses a replace while another run replaces the same file
                try:
                    os.replace(tmp, os.path.join(pub, n))
                    break
                except PermissionError:
                    if k == 49:
                        os.remove(tmp)
                        raise
                    time.sleep(0.05 * (k + 1) ** 0.5)


def link_overlay(*args, **kw):
    """Link one region. Every run works in its own dir OUT/<region>_<pid> so concurrent
    runs never collide; at exit the result files (ov.elf, ov.lcf, ov.bin, link.log) are
    copied to OUT/<region>/ (atomic per file, last run wins) and the run dir is removed."""
    _RUN.clear()
    try:
        return _link_overlay(*args, **kw)
    finally:
        work, pub = _RUN.get("work"), _RUN.get("pub")
        if work:
            try:
                _publish(work, pub)
            except OSError:
                pass
            shutil.rmtree(work, ignore_errors=True)
        _RUN.clear()


def _link_overlay(ovid, interworking=True, absolute_only=False, verbose=True, skip=(), unplaced_files=False, extra=None,
                  data=False):
    base, img = overlay_info(ovid)
    end = base + len(img)
    d = os.path.join(ROOT, "src", "game", SRC_DIR.get(ovid) or region_name(ovid))
    pub = os.path.join(OUT, region_name(ovid))
    work = os.path.join(OUT, "%s_%d" % (region_name(ovid), os.getpid()))
    data_tail = bss = None
    data_aliases = {}
    data_renames = {}
    own_tail = {}
    data_nosinit = False
    data_fixed = {}
    pad_ok = data      # the linker pads a Thumb file to the next 4-aligned one
    if data:
        # --data: the data sections of all files form the data tail (see the docstring)
        dl = os.path.join(extra or "", "datalink.json")
        if not extra or not os.path.exists(dl):
            return dict(ov=ovid, ok=False, why="--data needs --extra=DIR with DIR/datalink.json (tools/datagen.py companions)")
        dj = json.load(open(dl))
        data_tail = tuple(int(x, 16) for x in dj["tail"])        # rodata start, sinit start, data start, end
        bss = tuple(int(x, 16) for x in dj["bss"]) if dj.get("bss") else None
        data_aliases = dj.get("aliases", {})
        data_renames = dj.get("renames", {})     # file stem -> {name: its own name for another object}
        # the files' own data sections and their addresses in the original
        # (datagen.py from the plain link): they link in address order, and one
        # at a multiple of 4 gets that alignment (local array templates are
        # 1-aligned here but 4-aligned in the game's objects)
        own_tail = {stem: [(i, int(a, 16)) for i, a in v] for stem, v in dj.get("own", {}).items()}
        data_sinit = dj.get("sinit", [])
        data_nosinit = bool(dj.get("nosinit"))         # arm9_main: .rodata and .data follow each other
        data_fixed = {k: int(v, 16) for k, v in dj.get("fixed", {}).items()}   # companion stem -> address
        pub = os.path.join(OUT + "_data", region_name(ovid))
        work = os.path.join(OUT + "_data", "%s_%d" % (region_name(ovid), os.getpid()))
    shutil.rmtree(work, ignore_errors=True)
    os.makedirs(work)
    _RUN["work"], _RUN["pub"] = work, pub
    match.load_all_regions()
    match.evidence()

    tus = []          # (addr, stem, objpath, text size)
    syms = {}
    files = [(d, f) for f in sorted(os.listdir(d))]
    if unplaced_files and os.path.isdir(os.path.join(d, "unplaced")):
        # --unplaced: also link the stand-ins of unplaced/ at their header address
        files += [(os.path.join(d, "unplaced"), f) for f in sorted(os.listdir(os.path.join(d, "unplaced")))]
    if extra:
        # --extra=DIR: a file of DIR replaces the file of the same name, or is added
        # (to try a source change without touching src/)
        mine = set(f for f in os.listdir(extra) if f.endswith(".c"))
        files = [(x, f) for x, f in files if f not in mine] + [(extra, f) for f in sorted(mine)]
    for d, f in files:
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
    # a companion (<stem>.zdata.c) has the address of its code file and links after it
    # (<stem>.zpre.c: before it)
    tus.sort(key=lambda t: (t["addr"], link_rank(t["stem"])))

    other = sorted(set(n for t in tus for n in t["names"]) - {".text", ".data", ".rodata", ".bss"})
    if other:
        return dict(ov=ovid, ok=False, why="TU sections other than text/data: %s" % other)
    named_data = {}       # address -> size of the data objects the headers name
    _reg = registry_sizes(region_name(ovid))
    for t in tus:
        for _n, (a, k) in t["syms"].items():
            if k == "data" and base <= a < end:
                named_data[a] = max(named_data.get(a, 1), _reg.get(a, 1))
    named_sorted = sorted(named_data)

    def named_object_at(a, size):
        """True if [a, a+size) overlaps a header-named object (its registry size,
        else one byte) that does not start at a."""
        k = bisect.bisect_right(named_sorted, a + size - 1)
        for na in named_sorted[max(0, k - 8):k]:
            if na != a and na < a + size and a < na + named_data[na]:
                return True
        return False
    dgroups = []          # data sections of the files: (tu index, name, start, end, nobits)
    seen_data = {}
    unplaced = []
    dead_at = 0x0F000000  # unreferenced data sections go here, outside every region
    dead = 0
    # data mode: own sections of several files at one address (ov009
    # unit_02157280 has 0x78 bytes of the network statics that unit_021573C4
    # defines in 0xBC): the largest one links, the others are copies
    own_keep = {}
    for ti, t in enumerate(tus):
        sz = {x["idx"]: x["size"] for x in t["secs"]}
        for si, oa in own_tail.get(t["stem"], []):
            if si in sz and (oa not in own_keep or sz[si] > own_keep[oa][0]):
                own_keep[oa] = (sz[si], ti)
    own_inside = set()      # arm9_main: own sections inside another (a static the plain link places twice)
    if pad_ok:
        _ents = sorted((oa, -sz_, ti, si) for ti, t in enumerate(tus) for si, oa in own_tail.get(t["stem"], [])
                       for sz_ in [next((x["size"] for x in t["secs"] if x["idx"] == si), 0)])
        _hi = None
        for oa, nsz, ti, si in _ents:
            if _hi is not None and oa + (-nsz) <= _hi[1] and oa >= _hi[0] and (oa, -nsz) != (_hi[0], _hi[1] - _hi[0]):
                own_inside.add((ti, si))
            elif _hi is None or oa + (-nsz) > _hi[1]:
                _hi = (oa, oa + (-nsz))
    for ti, t in enumerate(tus):
        t["dsecs"] = [x for x in t["secs"] if x["name"] != ".text"]
        t["secs"] = [x for x in t["secs"] if x["name"] == ".text"]
        t["tail_secs"] = []
        if data_tail and ovid == "arm9_main":
            # arm9_main data mode: the sections listed in datalink.json "own" and every
            # section of a companion go to the tail; a "fixed" companion (none
            # now) links at its address; the other sections of a code file (crt0's
            # own .rodata inside the code range, dead statics) are placed as in the plain link
            if t["stem"] in data_fixed:
                pass
            elif is_companion(t["stem"]):
                t["tail_secs"], t["dsecs"] = t["dsecs"], []
            else:
                oi = set(si for si, _a in own_tail.get(t["stem"], []))
                t["tail_secs"] = [x for x in t["dsecs"] if x["idx"] in oi]
                t["dsecs"] = [x for x in t["dsecs"] if x["idx"] not in oi]
        elif data_tail:
            # data mode: every data section goes to the tail segments, in link order
            t["tail_secs"], t["dsecs"] = t["dsecs"], []
        used = referenced_sections(t["odata"], t["obj"])
        if data_tail and ovid != "arm9_main":
            # a dead section (see below) stays out of the tail too (ov016
            # unit_021C7768: the unused template @58 of `AREA a = {...}`)
            t["dsecs"] = [x for x in t["tail_secs"] if x["idx"] not in used and not any(
                y["shndx"] == x["idx"] and (y["info"] >> 4) == 1 for y in t["osyms"])]
            t["tail_secs"] = [x for x in t["tail_secs"] if x not in t["dsecs"]]
        for x in t["dsecs"]:
            if x["idx"] not in used and not any(y["shndx"] == x["idx"] and (y["info"] >> 4) == 1
                                                for y in t["osyms"]):
                # no relocation refers to it and it has no global name (a
                # function-local static const double the compiler also put in
                # the literal pool): the original link
                # dead-stripped it; -nodeadstrip keeps it, so park it outside
                x["addr"] = dead_at
                dead_at += (x["size"] + 7) & ~7
                dead += 1
                continue
            if t["stem"] in data_fixed:
                # a fixed companion: its one data section sits at the given address
                if x["type"] != 1 or x["name"] != ".rodata":
                    return dict(ov=ovid, ok=False, why="%s: fixed companion with a %s section" % (t["stem"], x["name"]))
                x["addr"] = data_fixed[t["stem"]]
                continue
            votes = {}
            for y in t["osyms"]:
                if y["shndx"] == x["idx"] and y["name"] in t["syms"] and t["syms"][y["name"]][1] == "data":
                    b = t["syms"][y["name"]][0] - y["value"]
                    votes[b] = votes.get(b, 0) + 1
            a = max(votes, key=lambda b: votes[b]) if votes else None
            if votes:
                top = [b for b in votes if votes[b] == votes[a]]
                al = max(x["align"], 1)
                if len(top) > 1 or a % al:
                    # a tie, or a base the section alignment forbids: the header
                    # addresses disagree with the object layout; report, do not guess
                    who = ["%s=%08X(+%X)" % (y["name"], t["syms"][y["name"]][0], y["value"]) for y in t["osyms"]
                           if y["shndx"] == x["idx"] and y["name"] in t["syms"] and t["syms"][y["name"]][1] == "data"]
                    return dict(ov=ovid, ok=False, why="%s %s: no single aligned base (%s; align %d): %s" % (
                        t["stem"], x["name"], ", ".join("%08X x%d" % (b, votes[b]) for b in sorted(votes)), al,
                        " ".join(who[:8])))
            if a is None and x["type"] == 1:
                blob = t["odata"][x["off"]:x["off"] + x["size"]]
                hits = [m.start() for m in re.finditer(re.escape(blob), img)]
                if len(hits) > 1:
                    # several equal strings: keep the one this file's own literal pool points at
                    code = img[t["addr"] - base:(tus[ti + 1]["addr"] if ti + 1 < len(tus) else end) - base]
                    hits = [h for h in hits if struct.pack("<I", base + h) in code] or hits
                if len(hits) > 1:
                    # keep the place the header names with an @ symbol, the compiler's
                    # own template of a function-local array (ov009 qr2: g_021A5A7C
                    # holds the same 6 bytes and the code points at both)
                    hits = [h for h in hits if any(
                        n.startswith("@") and v[0] == base + h for n, v in t["syms"].items())] or hits
                if len(hits) > 1:
                    # drop places inside an object the headers already name
                    hits = [h for h in hits if not named_object_at(base + h, len(blob))] or hits
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
        if data_tail:
            # data mode: a copy of another file's own section (own_keep) links
            # once, as in the plain link
            bysi = {x["idx"]: x for x in t["tail_secs"]}
            for si, oa in own_tail.get(t["stem"], []):
                x = bysi.get(si)
                if x is None:
                    continue
                if own_keep.get(oa, (0, ti))[1] != ti or (ti, si) in own_inside:
                    # references go to the kept copy; this one is parked
                    # outside every region (-nodeadstrip places every section)
                    t["dupsec"][si] = oa
                    t["tail_secs"].remove(x)
                    nm = ".d%d_%d" % (ti, si)
                    t["secren"][si] = nm
                    dgroups.append((ti, nm, dead_at, dead_at + x["size"], x["type"] == 8))
                    dead_at += (x["size"] + 7) & ~7
    for t in tus:
        t["defs"] = set(y["name"] for y in t["osyms"] if y["name"] and y["shndx"] != 0)
        t["pieces"] = [] if is_companion(t["stem"]) else \
            code_pieces(t, ovid, base, end, [u["addr"] for u in tus if not is_companion(u["stem"])])
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
    undef -= set(data_aliases)
    # The same local name (site, config, ...) can mean different addresses in
    # different files.  Give each distinct meaning its own symbol name, renamed
    # in the object of the files that use it.
    first = {}
    gsyms = {}
    for t in tus:
        t["rename"] = dict(data_renames.get(t["stem"], {}))
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

    addr2name = {}  # address -> (name, file index; -1 for a global name)
    funcs1 = []     # (address, size, name, file index) of the functions of the first link

    def inner_entry(a):
        """(name, offset, file index) if `a` lies inside a function defined by a file."""
        k = bisect.bisect_right(funcs1, (a, 1 << 32, "", 0)) - 1
        if k >= 0:
            fa, fs, fn, fti = funcs1[k]
            if fa < a < fa + fs:
                return fn, a - fa, fti
        return None
    plan, pi, redone, renamed_again = [1, 2], 0, False, False
    while pi < len(plan):
        pas = plan[pi]
        pi += 1
        aliases = []
        # gaps between files, as binary sections from the image
        gaps = []
        if pas == 2 and pad_ok:
            # arm9_main data mode: the 2 zero bytes after a Thumb file (next file at a
            # multiple of 4) are made by the linker (ALIGN(4) in the file's section),
            # not copied from the image
            allst = sorted([q["addr"] for t in tus for q in t["pieces"]] +
                           [a for _ti, _n, a, b, _nb in dgroups if base <= a < end] + [data_tail[0]])
            for t in tus:
                for p in t["pieces"]:
                    e_ = p["addr"] + p["size"]
                    p["pad"] = 0
                    up = (e_ + 3) & ~3
                    if e_ % 4 and up in allst and not any(e_ <= a < up for a in allst) and                             img[e_ - base:up - base] == bytes(up - e_):
                        p["pad"] = up - e_
                        p["size"] += p["pad"]
                        p["end"] += p["pad"]
        if pas == 2:
            occ = [(p["addr"], p["end"]) for t in tus for p in t["pieces"]] + [(a, b) for _ti, _n, a, b, _nb in dgroups
                                                          if a < end and b > base]
            if data_tail:
                occ.append((data_tail[0], data_tail[3]))
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
                        # second name of a function of a file (also of a static one:
                        # an absolute .lcf symbol at an odd address makes mwldarm
                        # misencode a backward Thumb BL by 2 bytes)
                        aliases.append((n, addr2name[a][0], 0, addr2name[a][1]))
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
            gdefs = set(t["rename"].get(y["name"], y["name"]) for y in t["osyms"]
                        if y["name"] and y["shndx"] != 0 and (y["info"] >> 4) == 1)
            # a global target: the file that defines it globally (other files may
            # have a static of the same name); a static target: its own file
            mine = [al[:3] for al in aliases if (al[1] in gdefs if al[3] == -1 else (al[3] == i and al[1] in t["defs"]))]
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
            t["own_tail"] = []          # data mode: (address, section kind, new name)
            kinds = {x["idx"]: (x["name"], x["align"]) for x in t["tail_secs"]}
            for si, oa in own_tail.get(t["stem"], []):
                if si in kinds:
                    ren[si] = ".own%d_%d" % (i, si)
                    t["own_tail"].append((oa, kinds[si][0], ren[si]))
                    if oa % 4 == 0 and kinds[si][1] < 4:
                        set_align(os.path.join(work, "t%d.o" % i), {si: 4})
            t["own_tail"].sort()
            if ren:
                rename_sections(os.path.join(work, "t%d.o" % i), ren)
            if is_companion(t["stem"]):
                # the anchor function of a companion goes outside the overlay
                mem.append(("z%d" % i, 0x0E000000 + 0x100 * i, 0x100))
                sect.append(" .z%d : { t%d.o (.text) } > z%d" % (i, i, i))
            for k, p in enumerate(t["pieces"]):
                tag = "t%d" % i if k == 0 else "t%d_%d" % (i, k)
                p["tag"] = tag
                if not p["idxs"]:
                    continue      # a file with data only
                mem.append((tag, p["addr"], p["size"] if pas == 2 else p["room"]))
                sect.append(" .%s : { t%d.o (%s)%s } > %s" % (tag, i, p["sec"], " . = ALIGN(4);" if p.get("pad") else "", tag))
            names.append("t%d.o" % i)
        if data_tail:
            t0, s0, s1, e0 = data_tail

            def tail_of(sname):
                out_ = []
                for i, t in enumerate(tus):
                    mine = [nm for _a, k, nm in t["own_tail"] if k == sname]
                    out_ += ["t%d.o (%s)" % (i, nm) for nm in mine]
                    if sum(1 for x in t["tail_secs"] if x["name"] == sname) > len(mine):
                        out_.append("t%d.o (%s)" % (i, sname))
                return " ".join(out_)
            if data_nosinit:
                # arm9_main: .rodata of all files in link order, then .data, no table
                mem.append(("dtail", t0, e0 - t0))
                sect.append(" .dtail : { %s %s } > dtail" % (tail_of(".rodata"), tail_of(".data")))
            else:
                # .rodata in link order, the static-initialiser table (the entries of
                # datalink.json "sinit", then the terminator), .data at ALIGN(32)
                sinit = "".join(" WRITEW %s;" % x for x in data_sinit)
                body = tail_of(".rodata") + " . = ALIGN(4); SINIT_START = .;%s WRITEW 0; SINIT_END = .;" % sinit
                if s1 > s0 + 4:
                    body += " . = ALIGN(32);"
                mem.append(("dtail", t0, s1 - t0))
                sect.append(" .dtail : { %s } > dtail" % body)
                mem.append(("ddata", s1, e0 - s1))
                # the overlay ends at ALIGN(32): zero padding after the last .data object
                sect.append(" .ddata : { %s . = ALIGN(32); } > ddata" % tail_of(".data"))
            if any(x["name"] == ".bss" for t in tus for x in t["tail_secs"]):
                if not bss:
                    return dict(ov=ovid, ok=False, why="data mode: .bss in the files but the overlay has no .bss")
                mem.append(("dbss", bss[0], bss[1] - bss[0]))
                sect.append(" .dbss : { %s } > dbss" % tail_of(".bss"))
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
        lcf += "".join(" %s = %s;\n" % (n, c) for n, c in sorted(data_aliases.items()))
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
            secfile = {}
            for x in secs:
                m = re.fullmatch(r"\.?t(\d+)(?:_\d+)?", x["name"])
                if m:
                    secfile[x["idx"]] = int(m.group(1))
            fsyms = []
            for y in esyms:
                if not (y["name"] and y["shndx"] != 0 and (y["info"] & 15) == 2) or y["name"][0] in "$@.":
                    continue
                if (y["info"] >> 4) == 1:
                    fsyms.append((y["value"] & ~1, y["size"], y["name"], -1))
                elif (y["info"] >> 4) == 0 and y["shndx"] in secfile:
                    # a static function: an alias for it must go into its own file
                    fsyms.append((y["value"] & ~1, y["size"], y["name"], secfile[y["shndx"]]))
            funcs1[:] = sorted(fsyms)
            for fa, _fs, fn, fti in sorted(fsyms, key=lambda z: z[3] != -1):
                addr2name.setdefault(fa, (fn, fti))
        out = bytearray(len(img))
        got = bytearray(len(img))
        for s in secs:
            if s["type"] == 1 and s["size"] and base <= s["addr"] < end:
                out[s["addr"] - base:s["addr"] - base + s["size"]] = data[s["off"]:s["off"] + s["size"]]
                got[s["addr"] - base:s["addr"] - base + s["size"]] = b"\1" * s["size"]
        if pas == 1:
            for t in tus:
                for p in t["pieces"]:
                    p["size"] = max([s["size"] for s in secs if s["type"] == 1 and s["name"] in (p["tag"], "." + p["tag"])] + [0])
                    p["end"] = p["addr"] + p["size"]
                t["size"] = sum(p["size"] for p in t["pieces"])
                t["end"] = t["pieces"][0]["end"] if t["pieces"] else t["addr"]
            continue
        # a .bss stand-in that sits inside the image: the original holds initialised
        # data there (the C file declares it uninitialised); take it from the image
        standin = 0
        standin_ranges = []
        for _ti, _n, a, b, nb in dgroups:
            if nb and base <= a < end:
                standin += min(b, end) - a
                standin_ranges.append((a, min(b, end)))
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
        # what in ov.bin came from the image instead of from the files: tools/romlink.py
        # lists these ranges (gaps = binary sections of the image, standin = .bss stand-ins)
        open(os.path.join(work, "ov.json"), "w", newline="\n").write(json.dumps(dict(
            ok=bool(whole and not code_diff), base=base, size=len(img), data_mode=bool(data_tail),
            gaps=[(g0, g1) for g0, g1 in gaps], standin=standin_ranges,
            sha1=hashlib.sha1(bytes(out)).hexdigest())))
    tail_diff = None
    if data_tail:
        bad = [i for i in range(data_tail[0] - base, data_tail[3] - base) if out[i] != img[i] or not got[i]]
        tail_diff = (len(bad), [hex(base + b) for b in bad[:8]])
    return dict(ov=ovid, ok=whole and not code_diff, tail_diff=tail_diff, files=len(tus), code_bytes=sum(t["size"] for t in tus),
                gap_bytes=sum(g1 - g0 for g0, g1 in gaps), size=len(img),
                bss_standin_bytes=standin, data_sections=len(dgroups), dead_data=dead, unplaced_data=unplaced, typed_stubs=len(ext_funcs), gap_funcs=sum(len(v) for v in gap_funcs.values()),
                absolute=len(absol), diffs=code_diff,
                units=[dict(stem=t["stem"], addr=t["addr"], end=t["end"],
                            pieces=[(p["addr"], p["end"]) for p in t["pieces"]]) for t in tus],
                split=[t["stem"] for t in tus if len(t["pieces"]) > 1])


def _selftest_child(tmp):
    global OUT, _link_overlay
    OUT = tmp

    def fake(ovid, **kw):
        work = os.path.join(OUT, "%s_%d" % (region_name(ovid), os.getpid()))
        os.makedirs(work)
        _RUN["work"], _RUN["pub"] = work, os.path.join(OUT, region_name(ovid))
        open(os.path.join(work, "ov.elf"), "w").write("elf %d" % os.getpid())
        open(os.path.join(work, "t0.o"), "w").write("x")
        return dict(ok=True)
    _link_overlay = fake
    return link_overlay(12)["ok"]


def selftest():
    """Four concurrent runs of one region: no collision, run dirs removed, result published."""
    import tempfile
    tmp = tempfile.mkdtemp(prefix="gamelink_selftest_")
    code = "import sys; sys.path.insert(0, %r); import gamelink; sys.exit(0 if gamelink._selftest_child(%r) else 1)" % (os.path.dirname(os.path.abspath(__file__)), tmp)
    procs = [subprocess.Popen([sys.executable, "-c", code]) for _ in range(4)]
    rcs = [p.wait() for p in procs]
    left = sorted(os.listdir(tmp))
    pub = os.path.join(tmp, region_name(12))
    ok = rcs == [0] * 4 and left == [region_name(12)] and sorted(os.listdir(pub)) == ["ov.elf"]
    shutil.rmtree(tmp, ignore_errors=True)
    print("gamelink selftest:", "PASS" if ok else "FAIL (rcs=%s left=%s)" % (rcs, left))
    return 0 if ok else 1


def main(argv):
    mode = {}
    ids = []
    if argv == ["--selftest"]:
        return selftest()
    for a in argv:
        if a == "--absolute":
            mode["absolute_only"] = True
        elif a.startswith("--skip="):
            mode["skip"] = tuple(x for x in a[7:].split(",") if x)
        elif a.startswith("--extra="):
            mode["extra"] = os.path.abspath(a[8:])
        elif a == "--unplaced":
            mode["unplaced_files"] = True
        elif a == "--data":
            mode["data"] = True
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
