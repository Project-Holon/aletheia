#!/usr/bin/env python3
"""sdkobj.py -- show the vendor object behind one recovered SDK symbol.

Given an SDK symbol name or address (layout/symbols_sdk.json), find the
archive member that defines it, and print, side by side with the image bytes
at the recovered address:

  * the member's code for that symbol, one instruction per line, every
    relocation shown by SYMBOL NAME (callee, global, string literal) with the
    image address the linker resolved it to and that address's status
    (matched / open SDK / game);
  * the callee and global list as a C declaration block plus the house-header
    `symbols:` lines, with each callee's prototype taken from the DWARF of the
    callee's OWN object (arity and types from the definition, never the call
    site);
  * the symbol's own DWARF prototype, parameters, locals and their locations;
  * the object's other symbols with sizes;
  * the object's .comment string (the mwccarm build that compiled it) and the
    tools/mwccarm front end that writes the identical string.

Only addresses, names, types and disassembly are printed; nothing is written.
The archives under sdk/ are read with tools/libmatch.py's own ar and ELF
readers.  Disassembly uses Capstone as a plain instruction decoder, as
tools/disasm.py does; without it the listing falls back to hex words.

    python tools/sdkobj.py OS_ExitThread
    python tools/sdkobj.py 0x020854B0
    python tools/sdkobj.py 0x02191234 --region ov009
    python tools/sdkobj.py OS_ExitThread --types      # also dump struct layouts
    python tools/sdkobj.py OS_ExitThread --brief      # decls + prototype only
    python tools/sdkobj.py --open --region arm9       # open SDK rows, biggest first
    python tools/sdkobj.py --selftest
"""

from __future__ import annotations

import argparse
import glob
import json
import os
import struct
import sys
from collections import defaultdict

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)

from libmatch import (  # noqa: E402
    Obj, RELOC_DEFAULT, RELOC_MASK, SHT_PROGBITS, SHT_REL, SHT_RELA,
    STT_FUNC, STT_OBJECT, classify, cstr, find_archives, load_regions,
    read_archive,
)

try:
    import capstone  # noqa: F401
    _HAVE_CS = True
except Exception:  # pragma: no cover
    _HAVE_CS = False

RELOC_NAMES = {
    1: "PC24", 2: "ABS32", 3: "REL32", 5: "ABS16", 8: "ABS8", 10: "THM_CALL",
    15: "XPC25", 16: "THM_XPC22", 28: "CALL", 29: "JUMP24", 30: "THM_JUMP24",
}
BRANCH_RELOCS = {1, 15, 28, 29}
THUMB_BRANCH_RELOCS = {10, 16, 30}

# The .comment string each tools/mwccarm front end writes, measured by
# compiling a one-line TU with every build (2026-09-27).  The string is the
# compiler's own version stamp, so an archive member carrying one of these
# was built by exactly that front end (1.6sp1 and 1.6sp2 share a stamp).
COMMENT_TO_CC = {
    "Metrowerks C/C++ for ARM 4.0.0.1018": "dsi/1.1",
    "Metrowerks C/C++ for ARM 4.0.0.1024": "dsi/1.1p1",
    "Metrowerks C/C++ for ARM 4.0.0.1026": "dsi/1.2",
    "Metrowerks C/C++ for ARM 4.0.0.1027": "dsi/1.2p1",
    "Metrowerks C/C++ for ARM 4.0.0.1028": "dsi/1.2p2",
    "Metrowerks C/C++ for ARM 4.0.0.1034": "dsi/1.3",
    "Metrowerks C/C++ for ARM 4.0.0.1036": "dsi/1.3p1",
    "Metrowerks C/C++ for ARM 4.0.0.1051": "dsi/1.6sp1 or dsi/1.6sp2",
    "Metrowerks C/C++ for ARM 2.0.0.79": "../1.2/sp2",
    "Metrowerks C/C++ for ARM 3.0.0.136": "../2.0/sp2",
    "Metrowerks C/C++ for ARM 3.0.0.137": "../2.0/sp2p2",
}

BUILD_ORDER = {"Rom": 0, "Release": 1, "Debug": 2}

# ---------------------------------------------------------------------------
# project tables
# ---------------------------------------------------------------------------

_CACHE = {}


def sdk_table():
    if "sdk" not in _CACHE:
        with open(os.path.join(ROOT, "layout", "symbols_sdk.json"), encoding="utf-8") as fh:
            _CACHE["sdk"] = json.load(fh)["symbols"]
    return _CACHE["sdk"]


def matched_table():
    """{(region, addr): name} over every shard, nested game_unit entries too."""
    if "m" in _CACHE:
        return _CACHE["m"]
    out = {}

    def walk(reg, entries):
        for f in entries or []:
            if not isinstance(f, dict):
                continue
            a = f.get("address")
            if a:
                a = int(a, 16) if isinstance(a, str) else a
                out[(str(f.get("region") or reg).lower(), a)] = f.get("name", "")
            if f.get("functions"):
                walk(reg, f["functions"])

    for p in glob.glob(os.path.join(ROOT, "layout", "matched", "**", "*.json"), recursive=True):
        try:
            with open(p, encoding="utf-8") as fh:
                sh = json.load(fh)
        except Exception:
            continue
        reg = str(sh.get("region") or "").lower()
        walk(reg, sh.get("functions") or sh.get("entries"))
    _CACHE["m"] = out
    return out


def regions():
    if "r" not in _CACHE:
        with open(os.path.join(ROOT, "layout", "layout.json")) as fh:
            layout = json.load(fh)
        extract = os.path.join(ROOT, layout.get("extract_dir", "extract"))
        _CACHE["r"] = {r.name: r for r in load_regions(layout, extract, overlays=True)}
    return _CACHE["r"]


def image_bytes(region, addr, size):
    r = regions().get(region)
    if r is None:
        return None
    off = addr - r.base
    if off < 0 or off + size > len(r.data):
        return None
    return bytes(r.data[off:off + size])


def region_of_site(region):
    """Regions whose code a call from `region` can reach: itself and arm9 (+ITCM)."""
    out = [region]
    for n in ("arm9", "arm9_autoload0_ITCM", "arm9_autoload1_DTCM", "twl"):
        if n not in out:
            out.append(n)
    return out


def name_at(addr, region):
    """(name, status) for an image address reached from `region`."""
    m = matched_table()
    sdk = sdk_table()
    for reg in region_of_site(region):
        if (reg.lower(), addr) in m:
            nm = m[(reg.lower(), addr)]
            sd = [s for s in sdk if s["address"] == addr and s["region"] == reg]
            if sd and sd[0]["name"] != nm:
                nm = "%s (sdk %s)" % (nm, sd[0]["name"])
            return nm, "matched"
    for reg in region_of_site(region):
        sd = [s for s in sdk if s["address"] == addr and s["region"] == reg]
        if sd:
            return sd[0]["name"], "open-sdk"
    return "func_%08X" % addr, "game/unknown"


def lookup(target, region=None):
    """SDK table rows for a name or address, filtered by region."""
    sdk = sdk_table()
    try:
        addr = int(target, 0)
        rows = [s for s in sdk if s["address"] == addr]
    except ValueError:
        rows = [s for s in sdk if s["name"] == target]
    if region:
        rows = [s for s in rows if s["region"] == region]
    rows.sort(key=lambda s: (s["region"] != "arm9", s["region"], s["address"]))
    return rows


# ---------------------------------------------------------------------------
# archive members
# ---------------------------------------------------------------------------

def candidate_archives(lib):
    """Archives that could hold `lib` (tree/basename), Rom builds first."""
    tree, base = lib.split("/", 1) if "/" in lib else ("", lib)
    out = []
    for p in find_archives():
        if os.path.basename(p) != base:
            continue
        t, build, _v, _th, _n = classify(p)
        if tree and t != tree:
            continue
        out.append((BUILD_ORDER.get(build, 9), p))
    out.sort()
    return [p for _, p in out]


def member(archive, objname):
    key = (archive, objname)
    if key in _CACHE:
        return _CACHE[key]
    found = None
    if archive.endswith(".o"):
        if os.path.basename(archive) == objname:
            with open(archive, "rb") as fh:
                found = Obj(objname, fh.read())
    else:
        for n, b in read_archive(archive):
            if n.rstrip("/") == objname:
                found = Obj(n, b)
                break
    _CACHE[key] = found
    return found


class ObjView:
    """Symbols, relocations and mapping symbols of one parsed member."""

    def __init__(self, obj):
        self.obj = obj
        d = obj.data
        si = obj.symtab_index()
        self.syms = []
        if si >= 0:
            ss = obj.sections[si]
            strtab = obj._strtab(obj.sections[ss[6]])
            for i in range(ss[5] // 16):
                no, val, size, info, other, shndx = struct.unpack_from("<IIIBBH", d, ss[4] + i * 16)
                self.syms.append((cstr(strtab, no), val, size, info & 0xF, info >> 4, shndx))
        self.mapping = defaultdict(list)
        for name, val, size, typ, bind, shndx in self.syms:
            if name in ("$a", "$t", "$d"):
                self.mapping[shndx].append((val, name))
        for v in self.mapping.values():
            v.sort()
        self.relocs = defaultdict(list)   # target section -> [(off, type, symidx, addend)]
        for s in obj.sections:
            if s[1] not in (SHT_RELA, SHT_REL):
                continue
            rela = s[1] == SHT_RELA
            ent = s[9] or (12 if rela else 8)
            for j in range(s[5] // ent):
                b = s[4] + j * ent
                off, info = struct.unpack_from("<II", d, b)
                add = struct.unpack_from("<i", d, b + 8)[0] if rela else None
                self.relocs[s[7]].append((off, info & 0xFF, info >> 8, add))
        for v in self.relocs.values():
            v.sort()

    def comment(self):
        for i, n in enumerate(self.obj.secnames):
            if n == ".comment":
                return self.obj.section_data(i).rstrip(b"\0").decode("latin1")
        return None

    def mode_at(self, shndx, off):
        cur = "$a"
        for v, n in self.mapping.get(shndx, ()):
            if v > off:
                break
            cur = n
        return cur

    def func_symbols(self, name):
        return [s for s in self.syms
                if s[0] == name and s[3] == STT_FUNC and s[2] and 0 < s[5] < len(self.obj.sections)
                and self.obj.sections[s[5]][1] == SHT_PROGBITS]

    def reloc_target_name(self, symidx, addend, field):
        """Readable name for a relocation's symbol (+addend)."""
        if symidx >= len(self.syms):
            return "?sym%d" % symidx
        name, val, size, typ, bind, shndx = self.syms[symidx]
        a = addend if addend is not None else field
        if typ == 3 or not name:   # STT_SECTION: resolve to the object's own symbol
            sec = self.obj.secnames[shndx] if shndx < len(self.obj.secnames) else "?"
            off = val + (a or 0)
            for n2, v2, s2, t2, b2, sh2 in self.syms:
                if sh2 == shndx and t2 in (STT_FUNC, STT_OBJECT) and v2 <= off < v2 + max(s2, 1):
                    return n2 + ("+%#x" % (off - v2) if off != v2 else "")
            return "%s+%#x" % (sec, off)
        if a and a not in (-8, -4):
            return "%s%+#x" % (name, a)
        return name


def reloc_field(rtype):
    return RELOC_MASK.get(rtype, RELOC_DEFAULT)


def extract(view, sym):
    name, val, size, typ, bind, shndx = sym
    body = view.obj.section_data(shndx)[val:val + size]
    mask = bytearray(b"\x01" * size)
    rels = []
    for off, rt, si, add in view.relocs.get(shndx, ()):
        if val <= off < val + size:
            lo, w = reloc_field(rt)
            for k in range(off - val + lo, min(off - val + lo + w, size)):
                mask[k] = 0
            rels.append((off - val, rt, si, add))
    thumb = view.mode_at(shndx, val) == "$t"
    return bytes(body), mask, rels, thumb


def locate(row, verbose=False):
    """Best (archive, view, symbol, bytes, mask, relocs, thumb, mismatches)."""
    img = image_bytes(row["region"], row["address"], row["size"])
    tried = []
    best = None
    for arch in candidate_archives(row["lib"]):
        o = member(arch, row["object"])
        if o is None or not o.ok:
            continue
        v = ObjView(o)
        for sym in v.func_symbols(row["name"]):
            body, mask, rels, thumb = extract(v, sym)
            if img is None or len(body) != len(img):
                mis = None
            else:
                mis = sum(1 for i in range(len(body)) if mask[i] and body[i] != img[i])
            tried.append((arch, mis))
            key = (mis is None, mis or 0)
            if best is None or key < best[0]:
                best = (key, (arch, v, sym, body, mask, rels, thumb, mis))
            if mis == 0:
                return best[1], tried
    return (best[1] if best else None), tried


# ---------------------------------------------------------------------------
# DWARF 2 (the members carry .debug_info/.debug_abbrev)
# ---------------------------------------------------------------------------

def uleb(d, p):
    r = s = 0
    while True:
        b = d[p]
        p += 1
        r |= (b & 0x7F) << s
        s += 7
        if not b & 0x80:
            return r, p


def sleb(d, p):
    r = s = 0
    while True:
        b = d[p]
        p += 1
        r |= (b & 0x7F) << s
        s += 7
        if not b & 0x80:
            if b & 0x40:
                r -= 1 << s
            return r, p


TAG = {0x01: "array", 0x04: "enum", 0x05: "param", 0x0d: "member", 0x0f: "ptr",
       0x10: "ref", 0x11: "cu", 0x13: "struct", 0x15: "functype", 0x16: "typedef",
       0x17: "union", 0x18: "varargs", 0x21: "subrange", 0x24: "base", 0x26: "const",
       0x28: "enumerator", 0x2e: "subprogram", 0x34: "variable", 0x35: "volatile",
       0x0b: "lexical_block"}
AT_NAME, AT_TYPE, AT_BYTE_SIZE, AT_LOCATION, AT_MEMBER_LOC = 0x03, 0x49, 0x0b, 0x02, 0x38
AT_UPPER, AT_COUNT, AT_EXTERNAL, AT_LOW_PC, AT_CONST_VALUE, AT_DECL = 0x2f, 0x37, 0x3f, 0x11, 0x1c, 0x3c


class Die:
    __slots__ = ("off", "tag", "attrs", "children", "parent")

    def __init__(self, off, tag):
        self.off = off
        self.tag = tag
        self.attrs = {}
        self.children = []
        self.parent = None


def read_form(d, p, form, addr_size=4):
    if form == 0x01:
        return struct.unpack_from("<I", d, p)[0], p + 4
    if form in (0x0b, 0x11, 0x0c):
        return d[p], p + 1
    if form in (0x05, 0x12):
        return struct.unpack_from("<H", d, p)[0], p + 2
    if form in (0x06, 0x13, 0x10):
        return struct.unpack_from("<I", d, p)[0], p + 4
    if form in (0x07, 0x14):
        return struct.unpack_from("<Q", d, p)[0], p + 8
    if form == 0x08:
        e = d.index(b"\0", p)
        return d[p:e].decode("latin1"), e + 1
    if form == 0x0a:
        n = d[p]
        return bytes(d[p + 1:p + 1 + n]), p + 1 + n
    if form == 0x03:
        n = struct.unpack_from("<H", d, p)[0]
        return bytes(d[p + 2:p + 2 + n]), p + 2 + n
    if form == 0x04:
        n = struct.unpack_from("<I", d, p)[0]
        return bytes(d[p + 4:p + 4 + n]), p + 4 + n
    if form == 0x09:
        n, p = uleb(d, p)
        return bytes(d[p:p + n]), p + n
    if form == 0x0d:
        return sleb(d, p)
    if form in (0x0f, 0x15):
        return uleb(d, p)
    if form == 0x0e:
        return struct.unpack_from("<I", d, p)[0], p + 4
    if form == 0x16:
        f, p = uleb(d, p)
        return read_form(d, p, f, addr_size)
    raise ValueError("DWARF form %#x" % form)


class Dwarf:
    def __init__(self, view):
        self.dies = {}
        self.top = []
        o = view.obj
        idx = {n: i for i, n in enumerate(o.secnames)}
        if ".debug_info" not in idx or ".debug_abbrev" not in idx:
            return
        ii = idx[".debug_info"]
        info = bytearray(o.section_data(ii))
        # apply .rela.debug_info (RELA: the field holds 0, S + A is the value)
        for off, rt, si, add in view.relocs.get(ii, ()):
            if add is None or off + 4 > len(info):
                continue
            s = view.syms[si] if si < len(view.syms) else None
            val = (s[1] if s else 0) + add
            struct.pack_into("<I", info, off, val & 0xFFFFFFFF)
        ab = o.section_data(idx[".debug_abbrev"])
        try:
            self._parse(bytes(info), ab)
        except Exception as exc:
            self.error = str(exc)

    def _abbrevs(self, ab, off):
        out = {}
        p = off
        while True:
            code, p = uleb(ab, p)
            if code == 0:
                return out
            tag, p = uleb(ab, p)
            ch = ab[p]
            p += 1
            specs = []
            while True:
                a, p = uleb(ab, p)
                f, p = uleb(ab, p)
                if a == 0 and f == 0:
                    break
                specs.append((a, f))
            out[code] = (tag, ch, specs)

    def _parse(self, d, ab):
        p = 0
        while p + 11 <= len(d):
            ulen, ver, aoff, asz = struct.unpack_from("<IHIB", d, p)
            end = p + 4 + ulen
            abbr = self._abbrevs(ab, aoff)
            q = p + 11
            stack = []
            while q < end:
                off = q
                code, q = uleb(d, q)
                if code == 0:
                    if stack:
                        stack.pop()
                    continue
                tag, ch, specs = abbr[code]
                die = Die(off, tag)
                for a, f in specs:
                    v, q = read_form(d, q, f, asz)
                    die.attrs[a] = v
                if stack:
                    die.parent = stack[-1]
                    stack[-1].children.append(die)
                else:
                    self.top.append(die)
                self.dies[off] = die
                if ch:
                    stack.append(die)
            p = end

    def find(self, name, tag=0x2e):
        for die in self.dies.values():
            if die.tag == tag and die.attrs.get(AT_NAME) == name and die.parent is not None \
                    and die.parent.tag == 0x11:
                return die
        for die in self.dies.values():
            if die.tag == tag and die.attrs.get(AT_NAME) == name:
                return die
        return None

    def tname(self, ref, depth=0):
        if ref is None:
            return "void"
        die = self.dies.get(ref)
        if die is None or depth > 12:
            return "?t%#x" % ref
        n = die.attrs.get(AT_NAME)
        t = die.attrs.get(AT_TYPE)
        if die.tag in (0x24, 0x16):
            return n or "?"
        if die.tag in (0x13, 0x17, 0x04):
            kw = {0x13: "struct", 0x17: "union", 0x04: "enum"}[die.tag]
            return "%s %s" % (kw, n or "<anon@%#x,%d>" % (die.off, die.attrs.get(AT_BYTE_SIZE, 0)))
        if die.tag == 0x0f:
            inner = self.dies.get(t)
            if inner is not None and inner.tag == 0x15:
                return self.tname(t, depth + 1)
            return self.tname(t, depth + 1) + " *"
        if die.tag == 0x10:
            return self.tname(t, depth + 1) + " &"
        if die.tag == 0x26:
            return "const " + self.tname(t, depth + 1)
        if die.tag == 0x35:
            return "volatile " + self.tname(t, depth + 1)
        if die.tag == 0x01:
            dims = ""
            for c in die.children:
                if c.tag == 0x21:
                    ub = c.attrs.get(AT_UPPER)
                    cnt = c.attrs.get(AT_COUNT)
                    dims += "[%s]" % (cnt if cnt is not None else (ub + 1 if isinstance(ub, int) else ""))
            return self.tname(t, depth + 1) + dims
        if die.tag == 0x15:
            args = [self.tname(c.attrs.get(AT_TYPE), depth + 1) for c in die.children if c.tag == 0x05]
            if any(c.tag == 0x18 for c in die.children):
                args.append("...")
            return "%s (*)(%s)" % (self.tname(t, depth + 1), ", ".join(args) or "void")
        return "%s?%#x" % (TAG.get(die.tag, "tag"), die.tag)

    def prototype(self, die):
        ps = []
        for c in die.children:
            if c.tag == 0x05:
                ps.append("%s %s" % (self.tname(c.attrs.get(AT_TYPE)), c.attrs.get(AT_NAME, "")))
            elif c.tag == 0x18:
                ps.append("...")
        static = "" if die.attrs.get(AT_EXTERNAL) else "static "
        return "%s%s %s(%s)" % (static, self.tname(die.attrs.get(AT_TYPE)),
                                 die.attrs.get(AT_NAME), ", ".join(ps) or "void")

    def struct_types(self, refs, limit=12):
        """Struct/union DIEs reachable from type refs through ptr/typedef/const/array."""
        seen, out = set(), []
        work = list(refs)
        while work and len(out) < limit:
            r = work.pop(0)
            if r is None or r in seen:
                continue
            seen.add(r)
            die = self.dies.get(r)
            if die is None:
                continue
            if die.tag in (0x13, 0x17):
                out.append(die)
                continue
            if die.tag in (0x0f, 0x16, 0x26, 0x35, 0x01, 0x10):
                work.append(die.attrs.get(AT_TYPE))
        return out


def loc_str(v):
    if not isinstance(v, (bytes, bytearray)) or not v:
        return ""
    op = v[0]
    if 0x50 <= op <= 0x6f:
        return "r%d" % (op - 0x50)
    if 0x70 <= op <= 0x8f:
        return "[r%d%+d]" % (op - 0x70, sleb(v, 1)[0])
    if op == 0x91:
        return "[fb%+d]" % sleb(v, 1)[0]
    if op == 0x03:
        return "@%#x" % struct.unpack_from("<I", v, 1)[0]
    if op == 0x90:
        return "r%d" % uleb(v, 1)[0]
    if op == 0x23:
        return "+%d" % uleb(v, 1)[0]
    return "loc:" + v.hex()


def member_off(v):
    if isinstance(v, (bytes, bytearray)) and v:
        op = v[0]
        if op in (0x23, 0x10):      # plus_uconst / constu
            return uleb(v, 1)[0]
        if op == 0x0c and len(v) >= 5:
            return struct.unpack_from("<I", v, 1)[0]
        if op == 0x0a and len(v) >= 3:
            return struct.unpack_from("<H", v, 1)[0]
        if op == 0x08 and len(v) >= 2:
            return v[1]
    if isinstance(v, int):
        return v
    return None


_DWARF = {}


def dwarf_of(view):
    k = id(view.obj)
    if k not in _DWARF:
        _DWARF[k] = Dwarf(view)
    return _DWARF[k]


def prototype_of(name, prefer_region="arm9"):
    """DWARF prototype of `name` from the member that defines it, or None."""
    rows = [s for s in sdk_table() if s["name"] == name]
    rows.sort(key=lambda s: s["region"] != prefer_region)
    for row in rows[:1]:
        for arch in candidate_archives(row["lib"]):
            o = member(arch, row["object"])
            if o is None or not o.ok:
                continue
            dw = dwarf_of(ObjView(o))
            die = dw.find(name)
            if die is not None:
                return dw.prototype(die)
            break
    return None


# ---------------------------------------------------------------------------
# disassembly and branch decoding
# ---------------------------------------------------------------------------

_MD = {}


def disasm(code, addr, thumb):
    """[(offset, size, text)] covering `code`; data-ish words as .word."""
    if not _HAVE_CS:
        step = 2 if thumb else 4
        return [(i, step, ".%s 0x%s" % ("hword" if thumb else "word", code[i:i + step][::-1].hex()))
                for i in range(0, len(code) - step + 1, step)]
    import capstone as cs
    key = bool(thumb)
    if key not in _MD:
        _MD[key] = cs.Cs(cs.CS_ARCH_ARM, cs.CS_MODE_THUMB if thumb else cs.CS_MODE_ARM)
    md = _MD[key]
    out = []
    i = 0
    while i < len(code):
        got = list(md.disasm(code[i:i + 4], addr + i, 1))
        if got:
            ins = got[0]
            out.append((i, ins.size, ("%s %s" % (ins.mnemonic, ins.op_str)).strip()))
            i += ins.size
        else:
            step = 2 if thumb else 4
            out.append((i, step, ".word 0x%s" % code[i:i + step][::-1].hex()))
            i += step
    return out


def arm_branch_target(word, pc):
    imm = word & 0xFFFFFF
    if imm & 0x800000:
        imm -= 1 << 24
    t = pc + 8 + (imm << 2)
    if (word >> 28) == 0xF:          # blx imm: H bit
        t += ((word >> 24) & 1) << 1
        return t, True
    return t, False


def thumb_bl_target(b, pc):
    hi, lo = struct.unpack_from("<HH", b, 0)
    off = ((hi & 0x7FF) << 12) | ((lo & 0x7FF) << 1)
    if off & 0x400000:
        off -= 1 << 23
    t = pc + 4 + off
    blx = (lo & 0xF800) == 0xE800
    if blx:
        t &= ~3
    return t, blx


# ---------------------------------------------------------------------------
# report
# ---------------------------------------------------------------------------

def symtype(v, si):
    if si >= len(v.syms):
        return None
    return v.syms[si]


def callee_isa(a, s):
    """ISA of a call target: bl keeps the caller's ISA, blx switches it."""
    img, off = a["img"], s["off"]
    if s["rtype"] in THUMB_BRANCH_RELOCS:
        return "arm" if thumb_bl_target(img[off:off + 4], 0)[1] else "thumb"
    if s["rtype"] in BRANCH_RELOCS:
        return "thumb" if (struct.unpack_from("<I", img, off)[0] >> 28) == 0xF else "arm"
    return "thumb" if s["target"] & 1 else "arm"


def analyse(row):
    got, tried = locate(row)
    if got is None:
        return None, tried
    arch, v, sym, body, mask, rels, thumb, mis = got
    img = image_bytes(row["region"], row["address"], row["size"])
    addr = row["address"]
    sites = []
    for off, rt, si, add in rels:
        lo, w = reloc_field(rt)
        field = struct.unpack_from("<i", body, off)[0] if off + 4 <= len(body) else 0
        name = v.reloc_target_name(si, add, field)
        s = symtype(v, si)
        kind = "data"
        if s is not None:
            if s[3] == STT_FUNC:
                kind = "func"
            elif s[3] == 3:
                kind = "local"
            elif s[3] == 0 and s[5] == 0 and rt in BRANCH_RELOCS | THUMB_BRANCH_RELOCS:
                kind = "func"
        tgt = None
        if img is not None and off + 4 <= len(img):
            word = struct.unpack_from("<I", img, off)[0]
            if rt in BRANCH_RELOCS:
                tgt, _ = arm_branch_target(word, addr + off)
            elif rt in THUMB_BRANCH_RELOCS:
                tgt, _ = thumb_bl_target(img[off:off + 4], addr + off)
            elif rt == 2:
                tgt = word
        sites.append({"off": off, "type": RELOC_NAMES.get(rt, str(rt)), "rtype": rt,
                      "name": name, "raw": s[0] if s else "", "kind": kind, "target": tgt,
                      "defined_here": bool(s and s[5] != 0 and s[3] != 3)})
    return {"row": row, "archive": arch, "view": v, "sym": sym, "body": body, "mask": mask,
            "thumb": thumb, "mismatches": mis, "img": img, "sites": sites}, tried


def print_listing(a, out):
    row, body, mask, img, v, sym = a["row"], a["body"], a["mask"], a["img"], a["view"], a["sym"]
    addr = row["address"]
    shndx, val = sym[5], sym[1]
    by_off = {s["off"]: s for s in a["sites"]}
    thumb = a["thumb"]
    # split by mapping symbols ($d = data words)
    spans = []
    mode = v.mode_at(shndx, val)
    pts = [(o - val, n) for o, n in v.mapping.get(shndx, ()) if val < o < val + len(body)]
    cur = 0
    for o, n in pts + [(len(body), None)]:
        if o > cur:
            spans.append((cur, o, mode))
        cur = o
        mode = n
    out.append("  off   address   object                                    image")
    for lo, hi, m in spans:
        if m == "$d":
            items = [(i, 4, ".word 0x%08x" % struct.unpack_from("<I", body, i)[0])
                     for i in range(lo, hi - 3, 4)]
            items_img = {i: ".word 0x%08x" % struct.unpack_from("<I", img, i)[0]
                         for i in range(lo, hi - 3, 4)} if img else {}
        else:
            items = disasm(body[lo:hi], addr + lo, m == "$t")
            items = [(lo + i, n, t) for i, n, t in items]
            items_img = {}
            if img:
                for i, n, t in disasm(img[lo:hi], addr + lo, m == "$t"):
                    items_img[lo + i] = t
        for i, n, text in items:
            ob = body[i:i + n]
            ib = img[i:i + n] if img else b""
            conc = all(ob[k] == ib[k] for k in range(len(ib)) if mask[i + k]) if ib else False
            same = ob == ib
            flag = "=" if same else ("~" if conc else "!")
            rel = ""
            for k in range(i, i + n):
                if k in by_off:
                    s = by_off[k]
                    rel = "  <%s %s>" % (s["type"], s["name"])
                    if s["target"] is not None:
                        tn, st = name_at(s["target"] & ~1 if s["kind"] != "data" else s["target"],
                                         row["region"])
                        rel += " -> %#010x %s [%s]" % (s["target"], tn, st) if st != "game/unknown" \
                            else " -> %#010x" % s["target"]
            if flag == "=" and not rel:
                out.append("  %04x  %08X  %-40s  =" % (i, addr + i, text))
            elif flag == "=":
                out.append("  %04x  %08X  %-40s  =%s" % (i, addr + i, text, rel))
            else:
                out.append("  %04x  %08X  %-40s %s %s%s" % (i, addr + i, text, flag,
                                                             items_img.get(i, ib.hex()), rel))


def report(row, types=False, brief=False):
    a, tried = analyse(row)
    out = []
    out.append("%s  %#010x  region %s  %d bytes  %s" % (row["name"], row["address"], row["region"],
                                                       row["size"], "thumb" if row.get("thumb") else "arm"))
    if a is None:
        out.append("  member %s of %s not found (tried %d archives)" % (row["object"], row["lib"], len(tried)))
        return "\n".join(out), None
    v = a["view"]
    st = matched_table().get((row["region"].lower(), row["address"]))
    out.append("  archive  %s (%s)" % (os.path.relpath(a["archive"], ROOT).replace("\\", "/"), row["object"]))
    out.append("  section  %s  value %#x  ISA %s" % (v.obj.secnames[a["sym"][5]], a["sym"][1],
                                                     "thumb" if a["thumb"] else "arm"))
    mis = a["mismatches"]
    out.append("  bytes    %s" % ("image unavailable" if mis is None else
                                  "%d concrete mismatches of %d concrete bytes%s" % (
                                      mis, sum(a["mask"]), "" if mis == 0 else "  (member differs from image)")))
    if len(tried) > 1:
        out.append("  tried    " + ", ".join("%s:%s" % (os.path.relpath(p, os.path.join(ROOT, "sdk")).split("/")[-2]
                                                         if "/" in os.path.relpath(p, os.path.join(ROOT, "sdk")).replace("\\", "/") else p,
                                                         m) for p, m in tried))
    cm = v.comment()
    out.append("  compiler %s  ->  %s" % (cm, COMMENT_TO_CC.get(cm, "no tools/mwccarm build writes this stamp")))
    out.append("  status   %s" % ("matched as %s" % st if st else "open"))

    dw = dwarf_of(v)
    die = dw.find(row["name"])
    out.append("")
    out.append("prototype (DWARF of the defining object):")
    if die is None:
        out.append("  (no DWARF subprogram named %s)" % row["name"])
        trefs = []
    else:
        out.append("  " + dw.prototype(die) + ";")
        trefs = [die.attrs.get(AT_TYPE)]

        def locals_(d, depth=1):
            for c in d.children:
                if c.tag in (0x05, 0x34):
                    trefs.append(c.attrs.get(AT_TYPE))
                    out.append("  %s%-6s %-34s %-20s %s" % ("  " * (depth - 1), TAG[c.tag],
                                                            dw.tname(c.attrs.get(AT_TYPE)),
                                                            c.attrs.get(AT_NAME, ""),
                                                            loc_str(c.attrs.get(AT_LOCATION))))
                elif c.tag == 0x0b:
                    locals_(c, depth + 1)
        locals_(die)

    # callees and globals
    out.append("")
    out.append("relocation targets (C names and image addresses):")
    decls, symlines, seen = [], [], set()
    for s in a["sites"]:
        key = s["name"]
        if key in seen:
            continue
        seen.add(key)
        t = s["target"]
        isfunc = s["kind"] == "func" or s["rtype"] in BRANCH_RELOCS | THUMB_BRANCH_RELOCS
        tn = st2 = ""
        if t is not None:
            tn, st2 = name_at(t & ~1 if isfunc else t, row["region"])
            if not isfunc and st2 == "game/unknown":
                tn, st2 = "g_%08X" % t, "data"
        out.append("  %-10s %-40s %s %s" % (s["type"], key,
                                            ("%#010x" % t) if t is not None else "?",
                                            ("%s [%s]" % (tn, st2)) if tn and tn != key else ("[%s]" % st2 if st2 else "")))
        base = s["raw"] if s["raw"] and s["kind"] != "local" else None
        if base is None and s["kind"] == "local" and "+" not in key and "." not in key:
            base = key
        if isfunc and base:
            p = prototype_of(base, row["region"])
            if p is None and s["defined_here"] and die is not None:
                d2 = dw.find(base)
                p = dw.prototype(d2) if d2 else None
            decls.append((p or "/* no DWARF */ void %s()" % base) + ";")
            if t is not None:
                th = callee_isa(a, s)
                symlines.append(" *   %-32s %#010x %s" % (base, t & ~1, th))
        elif base:
            var = dw.find(base, 0x34)
            if var is not None:
                trefs.append(var.attrs.get(AT_TYPE))
                decls.append("extern %s %s;" % (dw.tname(var.attrs.get(AT_TYPE)), base))
            else:
                decls.append("extern /* no DWARF */ int %s;" % base)
            if t is not None:
                symlines.append(" *   %-32s %#010x data" % (base, t))
        else:
            if t is not None:
                symlines.append(" *   %-32s %#010x data   (object-local %s)" % ("?", t, key))
    out.append("")
    out.append("declarations:")
    out.extend("  " + d for d in decls)
    out.append("")
    out.append("symbols: lines (house header):")
    out.extend(symlines or [" *   (none)"])

    if types:
        out.append("")
        out.append("struct layouts reachable from the prototype, locals and globals:")
        for sd in dw.struct_types(trefs):
            out.append("  %s  /* %d bytes */" % (dw.tname(sd.off), sd.attrs.get(AT_BYTE_SIZE, 0)))
            for m in sd.children:
                if m.tag == 0x0d:
                    mo = member_off(m.attrs.get(AT_MEMBER_LOC))
                    out.append("    +%-5s %-36s %s" % ("%#x" % mo if mo is not None else "?",
                                                       dw.tname(m.attrs.get(AT_TYPE)), m.attrs.get(AT_NAME, "")))

    if not brief:
        out.append("")
        out.append("listing ('=' identical, '~' differs only in relocated bits, '!' concrete difference):")
        print_listing(a, out)
        out.append("")
        out.append("other symbols in %s:" % row["object"])
        sdk_by_name = defaultdict(list)
        for s in sdk_table():
            if s["object"] == row["object"]:
                sdk_by_name[s["name"]].append(s)
        m = matched_table()
        for name, val, size, typ, bind, shndx in sorted(v.syms, key=lambda s: (s[3] != STT_FUNC, s[0])):
            if typ not in (STT_FUNC, STT_OBJECT) or not name or name[0] in "$." or shndx == 0:
                continue
            where = []
            for s in sdk_by_name.get(name, []):
                ok = (s["region"].lower(), s["address"]) in m
                where.append("%s:%#010x%s" % (s["region"], s["address"], " matched" if ok else ""))
            out.append("  %-4s %-6s %5d  %-36s %s" % ("func" if typ == STT_FUNC else "data",
                                                      "global" if bind else "local", size, name,
                                                      " ".join(where)))
    return "\n".join(out), a


# ---------------------------------------------------------------------------
# open rows
# ---------------------------------------------------------------------------

def open_rows(region):
    m = matched_table()
    pend = set()
    for p in glob.glob(os.path.join(ROOT, "src", "pending", "**", "*.c"), recursive=True):
        try:
            with open(p, encoding="utf-8", errors="replace") as fh:
                head = fh.read(600)
        except Exception:
            continue
        for line in head.splitlines():
            if line.strip().startswith("* address:"):
                try:
                    pend.add(int(line.split(":", 1)[1].strip(), 16))
                except ValueError:
                    pass
    rows = [s for s in sdk_table() if s["region"] == region and (region.lower(), s["address"]) not in m]
    rows.sort(key=lambda s: -s["size"])
    return rows, pend


# ---------------------------------------------------------------------------
# selftest
# ---------------------------------------------------------------------------

def selftest():
    """Known cases: a leaf with two calls, a system leaf, a thread function."""
    cases = [
        # (name, region, expect call relocations >= , expect compiler)
        ("CARD_CheckEnabled", "arm9", 2),
        ("OS_DisableInterrupts", "arm9", 0),
        ("OS_ExitThread", "arm9", 1),
    ]
    fails = 0
    for name, reg, ncalls in cases:
        rows = lookup(name, reg)
        if not rows:
            print("FAIL %s: not in symbols_sdk.json" % name)
            fails += 1
            continue
        a, tried = analyse(rows[0])
        if a is None:
            print("FAIL %s: member not found" % name)
            fails += 1
            continue
        calls = [s for s in a["sites"] if s["rtype"] in BRANCH_RELOCS | THUMB_BRANCH_RELOCS]
        named = all(s["name"] and not s["name"].startswith("?") for s in a["sites"])
        cm = a["view"].comment()
        ok = (a["mismatches"] == 0 and len(calls) >= ncalls and named and cm in COMMENT_TO_CC
              and all(s["target"] is not None for s in calls))
        # every call's image target must be the address the SDK table gives that name
        for s in calls:
            want = [r["address"] for r in sdk_table() if r["name"] == s["raw"]]
            if want and (s["target"] & ~1) not in want:
                ok = False
        print("%s %-22s %s %d relocs, %d calls, %s -> %s" % (
            "ok  " if ok else "FAIL", name, os.path.basename(a["archive"]), len(a["sites"]),
            len(calls), cm, COMMENT_TO_CC.get(cm)))
        fails += not ok
    # address form resolves to the same row as the name form
    r1 = lookup("OS_ExitThread", "arm9")
    r2 = lookup("%#x" % r1[0]["address"], "arm9") if r1 else []
    if not r2 or r2[0]["name"] != "OS_ExitThread":
        print("FAIL address lookup")
        fails += 1
    else:
        print("ok   address lookup %#x -> OS_ExitThread" % r1[0]["address"])
    # the DWARF prototype of a known function has the right arity
    p = prototype_of("OS_ExitThread")
    if not p or "(void)" not in p:
        print("FAIL DWARF prototype OS_ExitThread: %r" % p)
        fails += 1
    else:
        print("ok   DWARF %s" % p)
    print("selftest: %s" % ("PASS" if not fails else "%d FAIL" % fails))
    return 1 if fails else 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("target", nargs="?", help="SDK symbol name or address")
    ap.add_argument("--region", help="region of the row (arm9, ovNNN, ...); default prefers arm9")
    ap.add_argument("--types", action="store_true", help="dump struct layouts reachable from the function")
    ap.add_argument("--brief", action="store_true", help="header, prototype and declarations only")
    ap.add_argument("--all", action="store_true", help="report every row the target names, not just the first")
    ap.add_argument("--open", action="store_true", help="list open SDK rows of --region, biggest first")
    ap.add_argument("--limit", type=int, default=40)
    ap.add_argument("--selftest", action="store_true")
    args = ap.parse_args(argv)
    if args.selftest:
        return selftest()
    if args.open:
        reg = args.region or "arm9"
        rows, pend = open_rows(reg)
        print("%d open SDK rows in %s, %d bytes" % (len(rows), reg, sum(r["size"] for r in rows)))
        for r in rows[:args.limit]:
            print("  %#010x %6d  %-5s %-40s %s(%s)%s" % (r["address"], r["size"], "thumb" if r["thumb"] else "arm",
                                                      r["name"], os.path.basename(r["lib"]), r["object"],
                                                      "  [pending]" if r["address"] in pend else ""))
        return 0
    if not args.target:
        ap.error("target required")
    rows = lookup(args.target, args.region)
    if not rows:
        print("no symbols_sdk.json row for %s%s" % (args.target, " in " + args.region if args.region else ""))
        return 1
    for row in (rows if args.all else rows[:1]):
        text, _ = report(row, types=args.types, brief=args.brief)
        print(text)
        print()
    if len(rows) > 1 and not args.all:
        print("(%d rows name this target: %s; --all or --region to choose)" % (
            len(rows), ", ".join("%s:%#x" % (r["region"], r["address"]) for r in rows)))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
