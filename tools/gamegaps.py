#!/usr/bin/env python3
"""gamegaps.py: find code bytes in the game image that no src/game function compiles.

Read-only on the repo.  Nothing is compiled and nothing outside --out is written.

Why this tool exists
--------------------
match.py, ovstats.py and datasort.py give a function the extent "label to the next
function label".  Code the listing printed as .word/.byte (no label, nothing
traced) therefore counts as covered whenever it sits inside the extent of the
function in front of it.  That hides small functions (bx lr leaves, setters,
tail-call stubs, linker veneers) and a few large functions between two parts.

How coverage is decided
-----------------------
For every region (arm9, the ITCM autoload, twl, every overlay; ov230 through the
decrypted view asm/ov230d) the tool

  1. Reads the listing(s) into a byte image: instruction bytes come from the comment
     of each instruction line (.inst lines included), data bytes from the .word,
     .byte and .short values.
  2. Reads src/game/<region>/**/*.c.  A function is "in src/game" when a top level
     definition for it exists: the name carries the address (func_XXXXXXXX,
     sub_XXXXXXXX, also with a prefix such as ov208_func_XXXXXXXX), or it is a
     vendor name that layout/matched/<region> maps to an address.  Header
     `function:` lists are read only to report entries that have no definition.
  3. Gives each such function its true extent, not the label extent:
       listing   the start is a traced instruction: extent = start to the end of its
                 last traced instruction before the next listing label, grown over
                 every literal pool word that one of its own `ldr rX, pool_...` names
       decode    when bytes follow that are not fill, when the start was printed as
                 data (a hidden stub), or when a listing label sits before the next
                 real function start (it may be interior, as in the mcss walker
                 func_02014D2C), the body is decoded with capstone: linear walk,
                 forward branches, literal pool reads, Thumb halfword switch tables
                 and ARM add-pc switch tables, until an unconditional return or
                 jump with no forward branch left.  A branch to a known function
                 start is a tail call, not an interior jump.
  4. Marks as covered by other means: SDK functions (layout/sdk_class.json and
     symbols_sdk.json sizes, shard entries of kind sdk, sdk_unit, sdk_calibration)
     and the arm9 runtime library (layout/runtime_arm9.txt, kind runtime shards).
  5. Takes the code range of the region (first listing byte to the start of the data
     tail in layout/data_objects.json; for ITCM and twl to the end of the last
     function) and removes everything covered.  What is left is walked piece by
     piece:
       pad       zero words and Thumb nop pairs (reported from 4 bytes)
       veneer    bx pc; nop; ldr ip,[pc]; bx ip; .word (16 bytes)
                 |  ldr pc,[pc,#-4]; .word  |  any piece whose listing label is
                 veneer_XXXXXXXX  |  the ov230 decryptor entries.
       tailstub  (class leaf, note "tailstub target=...") the 8 byte Thumb form
                 ldr r3,[pc]; bx r3; .word and the 12 byte ARM form
                 ldr ip,[pc]; bx ip; .word.  mwcc writes these for a one-call tail
                 stub (void f(void) { g(); }), so they are code to write.
       leaf      decodes to a complete function with no bl and no push of lr
       func      decodes to a complete function with a bl or a push/pop of lr
       frag      decodes cleanly but reaches the next function start without a
                 return (a function head cut off by an interior label)
       data      does not decode as a function (unreferenced pool words, tables,
                 the arm9 secure area)
     A code piece is `strong` when its start is a listing label, is referenced by a
     branch or pool word, or begins with push; otherwise `weak` (a weak piece must
     end in a real return).  kind=hidden: the piece starts at no listing label.
     kind=labeled: it starts at a listing function label that no src/game file
     defines.  The shard column holds the EXACT/EXACT* status when
     layout/matched records a game function at that address (it was verified once
     but src/game does not define it now).
  6. Writes one TSV row per piece (start, end, size, class, kind, shard, isa, conf,
     note, first instructions, neighbours in src/game, drafts found under --drafts)
     to DIR/gamegaps.tsv and a per region and class summary to
     DIR/gamegaps_summary.txt.

usage
  python tools/gamegaps.py --out DIR [--region ov039 ...] [--drafts GLOB ...]
                           [--min-size N] [--no-labeled-veneers]
  --drafts takes a glob of draft roots; each root holds <region>/ folders with files
  whose name contains the 8 digit address, e.g. 'SCRATCH/gapmatch*'.

limits
  Decoding is linear: a function whose last instruction is a call that never
  returns, an ARM `ldr pc,[pc,rX]` switch or data between two instructions that is
  not a pool or table can end early or fail; failing pieces fall to `data`.  Weak
  pieces can be data that happens to decode.  Region ov230 is a decrypted derived
  view; only labelled or referenced code is reported there.
"""
from __future__ import annotations

import argparse
import bisect
import collections
import glob
import json
import os
import re
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)

import capstone  # noqa: E402
from capstone import arm as carm  # noqa: E402

ADDR_MAX = 0x08000000

FUNC_LABEL = re.compile(r"^((?:func|sub|veneer)_([0-9A-F]{8})):\s*$")
ANY_LABEL = re.compile(r"^([A-Za-z_][\w.]*):\s*$")
RE_ORG = re.compile(r"^\s*\.org\s+(0x[0-9A-Fa-f]+|\d+)")
RE_HDR = re.compile(r"address range\s+0x([0-9A-Fa-f]{8})\.\.0x([0-9A-Fa-f]{8})")
RE_POOL = re.compile(r"\bpool_([0-9A-F]{8})\b")
RE_HEX8 = re.compile(r"0x(0[0-9A-Fa-f]{7})\b")
RE_SYM = re.compile(r"\b(?:func|sub|loc)_([0-9A-F]{8})\b")
RE_FUNCNAME = re.compile(r"(?:func|sub)_([0-9A-Fa-f]{8})$")
# a definition or declaration; the name may carry a region prefix such as ov208_func_021BC3BC,
# which protofix.DECL_RE (and so gamecheck.py) does not see
DECL = re.compile(r"^[ \t]*((?:(?:extern|static)\s+)*)([A-Za-z_][\w\s\*]*?)\b((?:[A-Za-z][A-Za-z0-9]*_)?(?:func|sub)_[0-9A-Fa-f]{8})\s*\(([^;{}]*)\)\s*([;{])", re.M)
# any top level function definition, for names that carry no address (vendor names, asm functions)
DEF_ANY = re.compile(r"^[ \t]*((?:(?:extern|static|asm|inline)\s+)*)([A-Za-z_][\w\s\*]*?)\b([A-Za-z_]\w*)\s*\(([^;{}]*)\)(?:\s*[^\s;{}()][^;{}()]*;)*\s*\{", re.M)
HEXPAIR = set("0123456789ABCDEF")

CC_OK = (carm.ARM_CC_AL, carm.ARM_CC_INVALID)


# ----------------------------------------------------------------------------- listings

class Image:
    """Bytes of one region as the listing prints them."""

    def __init__(self):
        self.parts = []          # (addr, bytes, is_instr)
        self.labels = {}         # addr -> name (func_/sub_/veneer_)
        self.lmode = {}          # label addr -> 'thumb' | 'arm'
        self.poolref = {}        # instr addr -> pool addr
        self.refs = set()        # branch and pointer targets seen in the listing
        self.modes = []          # (addr, 't'|'a') mode changes in listing order
        self.lo = None
        self.hi = None

    def finish(self):
        parts = sorted(self.parts)
        self.lo = parts[0][0]
        self.hi = max(a + len(b) for a, b, _ in parts)
        n = self.hi - self.lo
        self.img = bytearray(n)
        self.kind = bytearray(n)          # 0 none, 1 instruction, 2 data
        ia, isz = [], []
        for a, b, ins in parts:
            o = a - self.lo
            self.img[o:o + len(b)] = b
            self.kind[o:o + len(b)] = b"\x01" * len(b) if ins else b"\x02" * len(b)
            if ins:
                ia.append(a)
                isz.append(len(b))
        self.ia, self.isz = ia, isz
        self.modes.sort()
        self.mode_addrs = [a for a, _ in self.modes]

    def mode_at(self, addr):
        i = bisect.bisect_right(self.mode_addrs, addr) - 1
        return self.modes[i][1] if i >= 0 else "t"

    def get(self, a, n):
        o = a - self.lo
        if o < 0 or o + n > len(self.img):
            return None
        return bytes(self.img[o:o + n])

    def covered_by_listing(self, a):
        o = a - self.lo
        return 0 <= o < len(self.kind) and self.kind[o] != 0


def parse_listing(path, im):
    base = None
    cur = None
    mode = "t"
    pend_thumb = False
    with open(path, encoding="utf-8", errors="replace") as fh:
        for raw in fh:
            if base is None:
                m = RE_HDR.search(raw)
                if m:
                    base = int(m.group(1), 16)
                    continue
            c0 = raw[:1]
            if c0 != "\t":
                if c0.isalpha() or c0 == "_":
                    m = FUNC_LABEL.match(raw.rstrip())
                    if m and cur is not None:
                        im.labels[cur] = m.group(1)
                        im.lmode[cur] = "thumb" if (pend_thumb or mode == "t") else "arm"
                    pend_thumb = False
                continue
            s = raw.strip()
            if not s:
                continue
            op = s.split(None, 1)[0]
            if op == ".org":
                m = RE_ORG.match(raw)
                cur = base + int(m.group(1), 0)
                continue
            if op == ".thumb":
                mode = "t"
                im.modes.append((cur if cur is not None else 0, "t"))
                continue
            if op == ".arm":
                mode = "a"
                im.modes.append((cur if cur is not None else 0, "a"))
                continue
            if op == ".thumb_func":
                pend_thumb = True
                continue
            if op in (".global", ".type", ".syntax", ".section", ".end", ".balign", ".align", ".text", ".size"):
                continue
            ci = raw.find("/*")
            body = raw[:ci] if ci >= 0 else raw
            toks = raw[ci + 2:].split() if ci >= 0 else []
            ca = None
            if toks and len(toks[0]) == 8:
                try:
                    ca = int(toks[0], 16)
                except ValueError:
                    ca = None
            if ca is not None:
                cur = ca
            if cur is None:
                continue
            if ci >= 0 and "0x" in body:
                for h in RE_HEX8.findall(body):
                    v = int(h, 16)
                    im.refs.add(v)
                    im.refs.add(v & ~1)
            if op == ".word":
                v = int(body.split(None, 1)[1].split()[0], 0) & 0xFFFFFFFF
                im.parts.append((cur, struct.pack("<I", v), False))
                cur += 4
            elif op == ".byte":
                vals = [int(x, 0) & 0xFF for x in body.split(None, 1)[1].split(",")]
                im.parts.append((cur, bytes(vals), False))
                cur += len(vals)
            elif op in (".short", ".hword"):
                vals = [int(x, 0) & 0xFFFF for x in body.split(None, 1)[1].split(",")]
                b = b"".join(struct.pack("<H", v) for v in vals)
                im.parts.append((cur, b, False))
                cur += len(b)
            elif op.startswith(".") and not op.startswith(".inst"):
                continue
            else:
                bl = bytearray()
                for t in toks[1:]:
                    if len(t) == 2 and t[0] in HEXPAIR and t[1] in HEXPAIR:
                        bl.append(int(t, 16))
                    else:
                        break
                if not bl:
                    continue
                im.parts.append((cur, bytes(bl), True))
                if len(bl) == 2 and 0x48 <= bl[1] <= 0x4F:
                    im.poolref.setdefault(cur, ((cur + 4) & ~3) + (bl[0] << 2))
                elif len(bl) == 4 and mode == "a" and (struct.unpack("<I", bytes(bl))[0] & 0x0F7F0000) == 0x051F0000:
                    w = struct.unpack("<I", bytes(bl))[0]
                    d = w & 0xFFF
                    im.poolref.setdefault(cur, cur + 8 + (d if w & 0x00800000 else -d))
                m = RE_POOL.search(body)
                if m:
                    im.poolref[cur] = int(m.group(1), 16)
                for sm in RE_SYM.findall(body):
                    v = int(sm, 16)
                    im.refs.add(v)
                for h in RE_HEX8.findall(toks and " ".join(toks) or ""):
                    v = int(h, 16)
                    im.refs.add(v)
                cur += len(bl)


def region_listings(region):
    """List of listing files for a region name."""
    if region == "arm9":
        us = json.load(open(os.path.join(ROOT, "layout", "units_arm9.json")))["units"]
        return [os.path.join(ROOT, u["file"]) for u in us]
    if region == "arm9_autoload0_ITCM":
        us = json.load(open(os.path.join(ROOT, "layout", "units_itcm.json")))["units"]
        return [os.path.join(ROOT, u["file"]) for u in us]
    if region == "twl":
        return [os.path.join(ROOT, "asm", "twl", "twl.s")]
    if region == "ov230":
        return [os.path.join(ROOT, "asm", "ov230d", "ov230d.s")]
    return [os.path.join(ROOT, "asm", "overlays", region + ".s")]


def all_regions():
    out = ["arm9", "arm9_autoload0_ITCM", "twl"]
    for p in sorted(glob.glob(os.path.join(ROOT, "asm", "overlays", "ov*.s"))):
        out.append(os.path.basename(p)[:-2])
    return out


# ----------------------------------------------------------------------------- src/game

class Src:
    """Functions defined in src/game, per region."""

    def __init__(self, tree):
        self.tree = tree
        self.unresolved = []
        import protofix as pf
        self.pf = pf

    def region(self, region):
        """(defs {addr: [rel files]}, header {addr: [rel files]})"""
        pf = self.pf
        defs = collections.defaultdict(list)
        hdr = collections.defaultdict(list)
        base = os.path.join(self.tree, region)
        names = shard_names(region)
        stats_unres = self.unresolved
        for dp, _dn, fn in os.walk(base):
            for f in sorted(fn):
                if not f.endswith(".c") or f.startswith("_"):
                    continue
                p = os.path.join(dp, f)
                try:
                    raw = open(p, encoding="latin1").read()
                except OSError:
                    continue
                rel = os.path.relpath(p, ROOT).replace(os.sep, "/")
                m = re.search(r"^\s*\*\s*function:\s*(.*)$", raw[:6000], re.M)
                if m:
                    for nm in re.findall(r"(?:func|sub)_([0-9A-Fa-f]{8})", m.group(1)):
                        hdr[int(nm, 16)].append(rel)
                masked = pf.mask(raw)
                tab = pf.depth_table(masked)
                for mm in DEF_ANY.finditer(masked):
                    if pf.depth_at(tab, mm.start()) != 0:
                        continue
                    nm = mm.group(3)
                    am = RE_FUNCNAME.search(nm)
                    if am:
                        defs[int(am.group(1), 16)].append(rel)
                    elif nm in names:
                        defs[names[nm]].append(rel)
                    elif nm not in ("if", "while", "for", "switch", "sizeof"):
                        stats_unres.append((region, nm, rel))
        return defs, hdr


def load_sdk(region):
    import sdkclass
    if not hasattr(load_sdk, "u"):
        load_sdk.u = sdkclass.union()
    return {a: e["size"] for a, e in load_sdk.u.get(region, {}).items()}


def shard_names(region):
    """{name: address} for every entry of layout/matched/<region>, for definitions whose name carries no address."""
    out = {}
    for p in glob.glob(os.path.join(ROOT, "layout", "matched", region, "*.json")):
        try:
            with open(p, encoding="utf-8") as fh:
                d = json.load(fh)
        except Exception:
            continue
        for f in d.get("functions", []):
            if not isinstance(f, dict):
                continue
            if f.get("name") and f.get("address"):
                try:
                    out.setdefault(f["name"], int(str(f["address"]), 16))
                except ValueError:
                    pass
            # a merged unit shard keeps its top level name (unit_XXXXXXXX) and lists the
            # member functions with their addresses; those are the names src/game defines
            # after a rename, so map them too
            mem = f.get("functions") or []
            addrs = f.get("addresses") or []
            for nm, ad in zip(mem, addrs):
                if not isinstance(nm, str) or not isinstance(ad, str):
                    continue
                try:
                    out.setdefault(nm, int(ad, 16))
                except ValueError:
                    pass
    return out


def load_shards(region):
    """({addr: kind} for SDK/runtime entries and their unit members, {addr: status} for game entries)
    from layout/matched/<region>/*.json.  Names and addresses only."""
    other, game = {}, {}
    for p in glob.glob(os.path.join(ROOT, "layout", "matched", region, "*.json")):
        try:
            with open(p, encoding="utf-8") as fh:
                d = json.load(fh)
        except Exception:
            continue
        for f in d.get("functions", []):
            if not isinstance(f, dict) or not f.get("address"):
                continue
            try:
                a = int(str(f["address"]), 16)
            except ValueError:
                continue
            kind = str(f.get("kind", ""))
            if kind.startswith("game"):
                game[a] = f.get("status", "")
                for nm in f.get("functions", []) or []:
                    mm = RE_FUNCNAME.search(nm) if isinstance(nm, str) else None
                    if mm:
                        game.setdefault(int(mm.group(1), 16), f.get("status", ""))
                continue
            other[a] = kind
            for nm in f.get("functions", []) or []:
                mm = RE_FUNCNAME.search(nm) if isinstance(nm, str) else None
                if mm:
                    other.setdefault(int(mm.group(1), 16), kind)
    return other, game


def load_runtime():
    out = set()
    p = os.path.join(ROOT, "layout", "runtime_arm9.txt")
    for ln in open(p, encoding="utf-8"):
        if ln.startswith("#") or not ln.strip():
            continue
        t = ln.split()
        try:
            out.add(int(t[0], 16))
        except ValueError:
            pass
    return out


def load_registry():
    p = os.path.join(ROOT, "layout", "data_objects.json")
    return json.load(open(p, encoding="utf-8"))["regions"]


# ----------------------------------------------------------------------------- decoding

CS_T = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB)
CS_A = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
CS_T.detail = True
CS_A.detail = True


def dec1(md, b, addr):
    for i in md.disasm(b, addr, 1):
        return i
    return None


def is_ret(i, thumb):
    if i.cc not in CC_OK:
        return False
    m, o = i.mnemonic, i.op_str
    if m.startswith("bx") and not m.startswith("bxj"):
        return True
    if m.startswith("pop") and "pc" in o:
        return True
    if m.startswith("ldm") and "pc" in o:
        return True
    if m.startswith("mov") and o.replace(" ", "").startswith("pc,"):
        return True
    if m.startswith("ldr") and o.startswith("pc"):
        return True
    return False


def pool_of(i, thumb):
    """Literal pool address an `ldr rX, [pc, #imm]` reads, else None."""
    if not i.mnemonic.startswith("ldr") or not i.operands:
        return None
    for op in i.operands:
        if op.type == carm.ARM_OP_MEM and op.mem.base == carm.ARM_REG_PC and op.mem.index == 0:
            if thumb:
                return ((i.address + 4) & ~3) + op.mem.disp
            return i.address + 8 + op.mem.disp
    return None


class Trace:
    __slots__ = ("ok", "code_end", "end", "ins", "bl", "pushlr", "pools", "why", "mode", "first", "thumb", "plimit")


def trace(im, a, mode, limit, plimit=None, tails=None):
    """Decode a function starting at a in `mode` ('t' or 'a') and find its end.

    Follows the code linearly, notes forward branches and literal pool reads, and
    ends at an unconditional return or jump once no forward branch reaches past it.
    `limit` is the address the function must not reach (next known function start).
    """
    t = Trace()
    t.ok = False
    t.why = ""
    t.mode = mode
    t.thumb = mode == "t"
    t.ins = []
    t.bl = 0
    t.pushlr = False
    t.pools = set()
    t.first = None
    if plimit is None or plimit < limit:
        plimit = limit
    t.plimit = plimit
    md = CS_T if mode == "t" else CS_A
    step = 2 if mode == "t" else 4
    if a % step or a >= limit:
        t.why = "align"
        return t
    pos = a
    maxb = 0
    maxpool = 0
    conds = 0
    count = 0
    while pos < limit and count < 6000:
        sz = 4 if mode == "a" else 2
        b = im.get(pos, 4)
        if b is None:
            b = im.get(pos, 2)
            if b is None:
                t.why = "eof"
                return t
        i = dec1(md, b, pos)
        if i is None:
            t.why = "undecodable@%X" % pos
            return t
        count += 1
        end = pos + i.size
        if end > limit:
            t.why = "overrun"
            return t
        if t.first is None:
            t.first = i
        t.ins.append((pos, i.size, i.mnemonic, i.op_str))
        m, o = i.mnemonic, i.op_str
        if i.cc not in CC_OK:
            conds += 1
        if m == "udf" or m.startswith("bkpt"):
            t.why = "udf@%X" % pos
            return t
        if m.startswith("push") or m.startswith("stm"):
            if "lr" in o and i.cc in CC_OK:
                t.pushlr = True
        iid = i.id
        if iid in (carm.ARM_INS_BL, carm.ARM_INS_BLX):
            t.bl += 1
        pr = pool_of(i, mode == "t")
        if pr is not None:
            if pr >= plimit or pr < a:
                t.why = "pool out of range @%X" % pos
                return t
            t.pools.add(pr)
            maxpool = max(maxpool, pr + 4)
        # branches
        tgt = None
        if iid == carm.ARM_INS_B and i.operands and i.operands[0].type == carm.ARM_OP_IMM:
            tgt = i.operands[0].imm
        if tgt is not None:
            if i.cc in CC_OK:
                # unconditional b
                if a <= tgt < limit and tgt > pos and not (tails and tgt in tails and tgt > maxb):
                    maxb = max(maxb, tgt)
                    # skip over interior literal pool words
                    if tgt > end and _only_pools(im, t.pools, end, tgt):
                        pos = tgt
                        continue
                elif a <= tgt <= pos:
                    pass  # loop back
                # else: tail jump out of the function
                if end > maxb:
                    return _done(im, t, end, maxpool, limit, mode, conds)
                pos = end
                continue
            else:
                if not (a <= tgt < limit):
                    t.why = "cond branch out @%X" % pos
                    return t
                maxb = max(maxb, tgt)
                pos = end
                continue
        if mode == "a" and m.startswith("add") and o.startswith("pc, pc,"):
            # ARM switch: entry k is one instruction at pos+8+4k (b or a return), the
            # instruction at pos+4 is the fall-through; the case code follows the table
            n = None
            for x in reversed(t.ins[-5:-1]):
                if x[2].startswith("cmp") and "#" in x[3]:
                    try:
                        n = int(x[3].split("#")[1].split()[0].rstrip(","), 0) + 1
                    except ValueError:
                        n = None
                    break
            tpos = pos + 8
            k = 0
            while tpos + 4 <= limit and (n is None or k < n) and k < 1024:
                e = dec1(CS_A, im.get(tpos, 4) or b"", tpos)
                if e is None:
                    break
                if e.mnemonic == "b" and e.cc in CC_OK and e.operands and e.operands[0].type == carm.ARM_OP_IMM:
                    tg = e.operands[0].imm
                    if a <= tg < limit:
                        maxb = max(maxb, tg)
                elif not is_ret(e, False) or n is None and k > 0 and not is_ret(e, False):
                    break
                tpos += 4
                k += 1
            if n is None and k == 0:
                t.why = "switch table"
                return t
            pos = tpos
            continue
        if mode == "t" and m == "add" and o.replace(" ", "").startswith("pc,"):
            # Thumb switch: halfword offset table follows, case code after it
            tpos = end
            base = pos + 4
            mint = 1 << 60
            ent = 0
            while tpos < mint and tpos + 2 <= limit and ent < 512:
                hw = im.get(tpos, 2)
                if hw is None:
                    t.why = "table eof"
                    return t
                v = struct.unpack("<h", hw)[0]
                tg = base + v
                if tg > tpos:
                    mint = min(mint, tg)
                    maxb = max(maxb, tg)
                tpos += 2
                ent += 1
            if mint >= limit:
                t.why = "bad switch table"
                return t
            pos = (tpos + 3) & ~3 if tpos % 4 else tpos
            if pos < mint:
                pos = mint
            continue
        if is_ret(i, mode == "t"):
            if end > maxb:
                return _done(im, t, end, maxpool, limit, mode, conds)
            pos = end
            continue
        pos = end
    t.why = t.why or "no end"
    return t


def _only_pools(im, pools, a, b):
    """True when every byte in [a, b) is a referenced literal pool word or fill."""
    x = a
    if x % 4:
        if im.get(x, 2) not in (b"\0\0", b"\xC0\x46"):
            return False
        x += 2
    while x + 4 <= b:
        if x not in pools and im.get(x, 4) != b"\0\0\0\0":
            return False
        x += 4
    if x < b and im.get(x, b - x) not in (b"\0\0", b"\xC0\x46"):
        return False
    return True


def _done(im, t, end, maxpool, limit, mode, conds):
    n = len(t.ins)
    if mode == "a" and n and conds * 2 > n:
        t.why = "too many conditions"
        return t
    t.code_end = end
    e = max(end, maxpool)
    if e % 4 == 2:
        f = im.get(e, 2)
        if f in (b"\0\0", b"\xC0\x46") and e + 2 <= t.plimit:
            e += 2
    if e > t.plimit:
        t.why = "pool beyond limit"
        return t
    t.end = e
    t.ok = True
    return t



def veneer_at(im, a, limit):
    """(size, note) when a linker veneer / tail-call stub pattern starts at a."""
    b = im.get(a, 16)
    if b is None:
        b = im.get(a, 8)
        if b is None:
            return None
    if len(b) >= 8 and a % 2 == 0:
        if b[0] == 0 and (b[1] & 0xF8) == 0x48 and b[3] == 0x47 and b[2] == ((b[1] & 7) << 3) and a + 8 <= limit:
            tgt = struct.unpack("<I", b[4:8])[0]
            return 8, "ldr r%d,[pc]; bx r%d; target=0x%08X %s" % (b[1] & 7, b[1] & 7, tgt, "thumb" if tgt & 1 else "arm")
    if len(b) >= 12 and a % 4 == 0 and b[:8] == bytes.fromhex("00C09FE5" "1CFF2FE1") and a + 12 <= limit:
        tgt = struct.unpack("<I", b[8:12])[0]
        return 12, "ldr ip,[pc]; bx ip; target=0x%08X %s" % (tgt, "thumb" if tgt & 1 else "arm")
    if len(b) >= 16 and a % 2 == 0 and b[:12] == bytes.fromhex("7847C046" "00C09FE5" "1CFF2FE1") and a + 16 <= limit:
        tgt = struct.unpack("<I", b[12:16])[0]
        return 16, "bx pc; nop; ldr ip,[pc]; bx ip; target=0x%08X" % tgt
    if len(b) >= 8 and a % 4 == 0 and b[:4] == bytes.fromhex("04F01FE5") and a + 8 <= limit:
        tgt = struct.unpack("<I", b[4:8])[0]
        return 8, "ldr pc,[pc,#-4]; target=0x%08X" % tgt
    return None


def fill_run(im, pos, end):
    """Length of a run of zero bytes or Thumb nop pairs (C0 46) starting at pos."""
    n = 0
    while pos + n < end:
        b = im.get(pos + n, 2)
        if b is None:
            break
        if b[0] == 0 and (len(b) < 2 or b[1] == 0):
            n += 2
        elif b == b"\xC0\x46" and (pos + n) % 2 == 0:
            n += 2
        else:
            break
    if pos + n > end:
        n = end - pos
    return n


# ----------------------------------------------------------------------------- per region

class Piece:
    __slots__ = ("a", "b", "cls", "kind", "isa", "conf", "note", "first", "nins", "bl", "pushlr")

    def __init__(self, a, b, cls, kind, isa="", conf="", note="", first="", nins=0, bl=0, pushlr=False):
        self.a, self.b, self.cls, self.kind = a, b, cls, kind
        self.isa, self.conf, self.note, self.first = isa, conf, note, first
        self.nins, self.bl, self.pushlr = nins, bl, pushlr


def traced_extent(im, S, B):
    """Extent of a function whose start S is a traced instruction (see module doc)."""
    ia, isz = im.ia, im.isz
    i0 = bisect.bisect_left(ia, S)
    i1 = bisect.bisect_left(ia, B)
    if i1 <= i0 or ia[i0] != S:
        return None
    ce = ia[i1 - 1] + isz[i1 - 1]
    pe = 0
    pr = im.poolref
    for k in range(i0, i1):
        p = pr.get(ia[k])
        if p is not None and p < B + 0x1000:
            pe = max(pe, p + 4)
    e = max(ce, min(pe, B))
    if e % 4 == 2 and e + 2 <= B and im.get(e, 2) in (b"\0\0", b"\xC0\x46"):
        e += 2
    return e


def analyse_region(region, src, sdk_cache, runtime, registry, opts):
    files = region_listings(region)
    files = [f for f in files if os.path.exists(f)]
    if not files:
        return None
    im = Image()
    for f in files:
        parse_listing(f, im)
    if not im.parts:
        return None
    im.finish()
    defs, hdr = src.region(region) if os.path.isdir(os.path.join(src.tree, region)) else ({}, {})
    sdk = load_sdk(region)
    other, game_shard = load_shards(region)
    for a_, k_ in other.items():
        if k_.startswith("runtime"):
            runtime = set(runtime) | {a_}
        elif a_ not in sdk:
            sdk[a_] = 0
    rt = runtime if region == "arm9" else set()

    # code range
    reg = registry.get(region)
    code_lo = im.lo
    if reg:
        code_hi = int(reg["range"][0], 16)
    else:
        code_hi = None
    labels = im.labels
    sd = sorted(set(labels) | set(defs) | set(sdk) | rt)
    sd = [a for a in sd if im.lo <= a < im.hi]
    if code_hi is None:
        last = max([a for a in labels] + [0])
        e = traced_extent(im, last, im.hi) if last else None
        ia_end = im.ia[-1] + im.isz[-1] if im.ia else im.lo
        code_hi = max(ia_end, e or 0)
    code_hi = min(code_hi, im.hi)

    n = im.hi - im.lo
    cov = bytearray(n)       # 1 src, 2 sdk, 3 runtime

    def paint(a, b, v):
        a = max(a, im.lo)
        b = min(b, im.hi)
        for o in range(a - im.lo, b - im.lo):
            if cov[o] == 0:
                cov[o] = v

    stats = collections.Counter()
    src_ext = {}
    # source functions first, then SDK, then runtime.  fs holds the addresses known to be real
    # function starts; labels between two of them may be interior labels of one big function.
    fs = sorted(set(defs) | set(sdk) | rt)
    fset = set(fs)
    tails = fset | set(labels)
    for S in sorted(defs):
        if not (im.lo <= S < im.hi):
            stats["src_out_of_listing"] += 1
            continue
        i = bisect.bisect_right(sd, S)
        B = sd[i] if i < len(sd) else im.hi
        j = bisect.bisect_right(fs, S)
        N = fs[j] if j < len(fs) else im.hi
        mode = "t" if im.lmode.get(S, "thumb" if im.mode_at(S) == "t" else "arm") == "thumb" else "a"
        e = None
        if im.kind[S - im.lo] == 1:
            e = traced_extent(im, S, B)
            stats["src_traced"] += 1
        need = e is None or B < N or (e < B and fill_run(im, e, B) < B - e)
        if need:
            # decode the whole body: untraced code inside the function may read pool words past the
            # last traced instruction, and a label before the next real function start may be interior
            tr = trace(im, S, mode, N, N, tails)
            if not tr.ok and e is None:
                tr = trace(im, S, "a" if mode == "t" else "t", N, N, tails)
            if tr.ok:
                if e is None:
                    stats["src_swept"] += 1
                elif tr.end > e:
                    stats["src_traced_grown"] += 1
                e = max(e or 0, tr.end)
            elif e is None:
                e = B
                stats["src_untraceable"] += 1
        src_ext[S] = e
        paint(S, e, 1)
    for S in sorted(sdk):
        if not (im.lo <= S < im.hi):
            continue
        i = bisect.bisect_right(sd, S)
        B = sd[i] if i < len(sd) else im.hi
        e = S + sdk[S]
        t = traced_extent(im, S, B) if im.kind[S - im.lo] == 1 else None
        e2 = max(e, t or 0)
        if e2 <= S:
            tr = trace(im, S, "t" if im.lmode.get(S, "thumb") == "thumb" else "a", B)
            e2 = tr.end if tr.ok else B
        paint(S, e2, 2)
    for S in sorted(rt):
        if not (im.lo <= S < im.hi):
            continue
        i = bisect.bisect_right(sd, S)
        B = sd[i] if i < len(sd) else im.hi
        t = traced_extent(im, S, B) if im.kind[S - im.lo] == 1 else None
        paint(S, t or B, 3)

    # residue ranges inside the code range
    pieces = []
    o = code_lo - im.lo
    end_o = code_hi - im.lo
    ranges = []
    while o < end_o:
        if cov[o] or im.kind[o] == 0:
            o += 1
            continue
        s = o
        while o < end_o and not cov[o] and im.kind[o] != 0:
            o += 1
        ranges.append((s + im.lo, o + im.lo))

    refs = im.refs
    for ra, rb in ranges:
        pos = ra
        prev_func = False
        while pos < rb:
            nxt = bisect.bisect_right(sd, pos)
            limit = min(rb, sd[nxt] if nxt < len(sd) else rb)
            plimit = sd[nxt] if nxt < len(sd) else im.hi
            f = fill_run(im, pos, rb)
            if f:
                if f >= 4:
                    pieces.append(Piece(pos, pos + f, "pad", "hidden", note="fill"))
                pos += f
                continue
            is_label = pos in labels
            vz = veneer_at(im, pos, limit)
            if vz:
                size, note = vz
                isa = "thumb" if note.startswith(("ldr r", "bx pc")) else "arm"
                if note.startswith(("ldr r", "ldr ip")):
                    # compiler tail call (mwcc), real code: not a linker veneer
                    pieces.append(Piece(pos, pos + size, "leaf", "labeled" if is_label else "hidden",
                                        isa, "strong", "tailstub target=" + note.split("target=")[1],
                                        note.split("; target")[0], 2))
                else:
                    pieces.append(Piece(pos, pos + size, "veneer", "labeled" if is_label else "hidden",
                                        isa, "strong", note))
                pos += size
                prev_func = True
                continue
            pm = im.lmode.get(pos)
            if pm:
                order = ["t" if pm == "thumb" else "a"]
            else:
                order = ["t" if im.mode_at(pos) == "t" else "a"]
            order.append("a" if order[0] == "t" else "t")
            tr = None
            whys = []
            fragc = None
            for md in order:
                cand = trace(im, pos, md, limit, plimit, tails)
                whys.append("%s:%s" % (md, cand.why or "ok"))
                if not cand.ok and cand.why == "no end" and fragc is None and cand.ins:
                    fragc = cand
                if cand.ok:
                    # an interwork guess is only taken when the first choice failed
                    tr = cand
                    break
            if tr is not None:
                first = tr.first
                refd = pos in refs or ((pos | 1) in refs and tr.mode == "t")
                strong = is_label or refd or tr.pushlr or first.mnemonic.startswith("push")
                if not (strong or prev_func or pos == ra):
                    tr = None
                elif not strong:
                    # weak start: only accept a real return at the end and at least 4 bytes
                    lm = tr.ins[-1][2]
                    if tr.end - pos < 4 or not lm.startswith(("bx", "pop", "ldm", "mov", "ldr")):
                        tr = None
            if tr is not None and region == "ov230" and not (is_label or refd):
                tr = None      # the decrypted view has stray ciphertext; accept only labelled or referenced code
            if tr is not None:
                cls = "func" if (tr.bl or tr.pushlr) else "leaf"
                if tr.first.mnemonic == "orr" and tr.first.op_str == "ip, pc, pc":
                    cls = "veneer"     # ov230 hand-written decryptor entry
                elif is_label and labels[pos].startswith("veneer_"):
                    cls = "veneer"     # the listing itself names it a linker veneer
                note = []
                if cls == "veneer":
                    note.append("ov230 decryptor entry")
                if is_label:
                    note.append("label")
                if refd:
                    note.append("ref")
                if first.mnemonic.startswith("push"):
                    note.append("push")
                last = tr.ins[-1]
                if last[2].startswith("bx") and last[3] not in ("lr",):
                    note.append("tailcall")
                pieces.append(Piece(pos, tr.end, cls, "labeled" if is_label else "hidden",
                                    "thumb" if tr.mode == "t" else "arm", "strong" if strong else "weak",
                                    ",".join(note),
                                    "; ".join(("%s %s" % (x[2], x[3])).strip() for x in tr.ins[:4]),
                                    len(tr.ins), tr.bl, tr.pushlr))
                pos = tr.end
                prev_func = True
                continue
            if fragc is not None:
                first = fragc.first
                refd = pos in refs or ((pos | 1) in refs and fragc.mode == "t")
                if is_label or refd or first.mnemonic.startswith("push"):
                    pieces.append(Piece(pos, limit, "frag", "labeled" if is_label else "hidden",
                                        "thumb" if fragc.mode == "t" else "arm", "strong",
                                        "runs into next start" + (",label" if is_label else "") + (",ref" if refd else ""),
                                        "; ".join(("%s %s" % (x[2], x[3])).strip() for x in fragc.ins[:4]),
                                        len(fragc.ins), fragc.bl, fragc.pushlr))
                    pos = limit
                    prev_func = False
                    continue
            # data until the next strong candidate
            q = pos + 2
            found = None
            while q < limit:
                if q % 2 == 0:
                    b2 = im.get(q, 2)
                    cand_ok = False
                    if q in labels or q in refs or ((q | 1) in refs):
                        cand_ok = True
                    elif b2 is not None and b2[1] in (0xB5,) and q % 2 == 0:
                        cand_ok = True   # push {..., lr}
                    elif b2 is not None and (q % 4 == 0) and im.get(q, 4) is not None and im.get(q, 4)[3] == 0xE9 and im.get(q, 4)[2] in (0x2D, 0x6D):
                        cand_ok = True   # stmdb sp!, {...lr}
                    if cand_ok:
                        for md in (["t", "a"] if q % 4 else ["t", "a"]):
                            c2 = trace(im, q, md, limit, plimit, tails)
                            if c2.ok:
                                found = q
                                break
                        if found:
                            break
                q += 2
            dend = found if found else limit
            dend = max(dend, pos + 1)
            nptr = 0
            for x in range(pos & ~3, dend, 4):
                w = im.get(x, 4)
                if w and len(w) == 4:
                    v = struct.unpack("<I", w)[0]
                    if 0x01FF8000 <= v < 0x07000000:
                        nptr += 1
            pieces.append(Piece(pos, dend, "data", "labeled" if is_label else "hidden", "", "",
                                "ptrs=%d %s%s" % (nptr, " ".join(whys), " secure_area" if region == "arm9" and pos < 0x02004800 else "")))
            pos = dend
            prev_func = False
    return dict(region=region, im=im, defs=defs, hdr=hdr, sdk=sdk, shard=game_shard, pieces=pieces, src_ext=src_ext,
                code=(code_lo, code_hi), stats=stats, sd=sd)


def merge_data(pieces):
    out = []
    for p in pieces:
        if out and p.cls == "data" and out[-1].cls == "data" and out[-1].b == p.a:
            out[-1].b = p.b
            continue
        out.append(p)
    return out


# ----------------------------------------------------------------------------- report

COLS = ["region", "start", "end", "size", "class", "kind", "shard", "isa", "conf", "note", "first_ins", "ins",
        "prev_src", "prev_file", "next_src", "next_file", "draft"]


def find_drafts(patterns):
    """{(region, addr): path} from files named <region>_func_<ADDR>.c (or *_<ADDR>.c) under the given globs."""
    out = {}
    for pat in patterns:
        for d in glob.glob(pat):
            if not os.path.isdir(d):
                continue
            region = os.path.basename(d)
            for dp, _dn, fn in os.walk(d):
                for f in fn:
                    if not f.endswith((".c", ".s", ".txt")):
                        continue
                    m = re.search(r"([0-9A-Fa-f]{8})", f)
                    if m:
                        rel = os.path.relpath(os.path.join(dp, f), os.path.dirname(os.path.dirname(d))).replace(os.sep, "/")
                        out.setdefault((region, int(m.group(1), 16)), []).append(rel)
    return out


def rows_for(res, drafts):
    im = res["im"]
    defs = res["defs"]
    starts = sorted(defs)
    rows = []
    for p in merge_data(res["pieces"]):
        i = bisect.bisect_right(starts, p.a)
        ps = starts[i - 1] if i else None
        j = bisect.bisect_left(starts, p.b)
        ns = starts[j] if j < len(starts) else None
        # a src function that begins inside the piece is not possible (covered), so ns >= p.b
        dr = []
        for (rg, a), ps_ in drafts.items():
            if rg == res["region"] and p.a <= a < p.b:
                dr += ps_
        first = ""
        r = dict(region=res["region"], start="0x%08X" % p.a, end="0x%08X" % p.b, size=p.b - p.a, **{"class": p.cls},
                 kind=p.kind, shard=res["shard"].get(p.a, ""), isa=p.isa, conf=p.conf, note=p.note, first_ins=p.first, ins=p.nins or "",
                 prev_src=("func_%08X" % ps) if ps is not None else "",
                 prev_file=defs[ps][0] if ps is not None else "",
                 next_src=("func_%08X" % ns) if ns is not None else "",
                 next_file=defs[ns][0] if ns is not None else "",
                 draft=";".join(sorted(set(dr))))
        rows.append(r)
    return rows


def main():
    ap = argparse.ArgumentParser(description="find code bytes no src/game function compiles")
    ap.add_argument("--out", required=True, help="output directory (gamegaps.tsv and gamegaps_summary.txt are written here)")
    ap.add_argument("--region", action="append")
    ap.add_argument("--tree", default=os.path.join(ROOT, "src", "game"))
    ap.add_argument("--drafts", action="append", default=[], help="glob of draft root dirs, each holding <region>/ subdirs, e.g. 'SP/gapmatch*'")
    ap.add_argument("--min-size", type=int, default=0)
    ap.add_argument("--no-labeled-veneers", action="store_true", help="leave out veneers that carry a listing label")
    a = ap.parse_args()

    src = Src(a.tree)
    runtime = load_runtime()
    registry = load_registry()
    dpats = []
    for g in a.drafts:
        dpats += glob.glob(os.path.join(g, "*"))
    drafts = find_drafts(dpats)
    regions = a.region or all_regions()
    os.makedirs(a.out, exist_ok=True)
    rows = []
    stat = {}
    for rg in regions:
        res = analyse_region(rg, src, None, runtime, registry, a)
        if res is None:
            continue
        rr = rows_for(res, drafts)
        # header-only entries: listed in a `function:` header but not defined
        stale = sorted(set(res["hdr"]) - set(res["defs"]) - set(res["sdk"]))
        res["stale"] = stale
        for r in rr:
            if a.no_labeled_veneers and r["class"] == "veneer" and r["kind"] == "labeled":
                continue
            if r["size"] < a.min_size:
                continue
            rows.append(r)
        stat[rg] = res
    with open(os.path.join(a.out, "gamegaps.tsv"), "w", encoding="utf-8", newline="") as fh:
        fh.write("\t".join(COLS) + "\n")
        for r in rows:
            fh.write("\t".join(str(r[c]).replace("\t", " ") for c in COLS) + "\n")
    # summary
    classes = ["pad", "veneer", "leaf", "func", "frag", "data"]
    by = collections.defaultdict(lambda: collections.defaultdict(lambda: [0, 0]))
    for r in rows:
        c = by[r["region"]][r["class"]]
        c[0] += 1
        c[1] += r["size"]
    lines = []
    lines.append("count/bytes of uncovered pieces per region and class")
    lines.append("%-20s" % "region" + "".join(" %12s" % c for c in classes) + "   src fns  code range")
    tot = {c: [0, 0] for c in classes}
    for rg in regions:
        if rg not in stat:
            continue
        d = by.get(rg, {})
        if not d:
            continue
        cells = []
        for c in classes:
            n, b = d.get(c, [0, 0])
            tot[c][0] += n
            tot[c][1] += b
            cells.append("%d/%d" % (n, b) if n else "-")
        lines.append("%-20s" % rg + "".join(" %12s" % x for x in cells)
                     + "   %7d  0x%08X-0x%08X" % (len(stat[rg]["defs"]), stat[rg]["code"][0], stat[rg]["code"][1]))
    lines.append("%-20s" % "TOTAL" + "".join(" %12s" % ("%d/%d" % tuple(tot[c])) for c in classes))
    lines.append("")
    lines.append("by kind (hidden = no listing label, labeled = starts at a listing function label)")
    for k in ("hidden", "labeled"):
        cells = []
        for c in classes:
            sel = [r for r in rows if r["kind"] == k and r["class"] == c]
            cells.append("%d/%d" % (len(sel), sum(r["size"] for r in sel)) if sel else "-")
        lines.append("%-20s" % k + "".join(" %12s" % x for x in cells))
    fn = [r for r in rows if r["class"] in ("leaf", "func", "frag")]
    lines.append("")
    lines.append("code pieces (leaf+func+frag): %d, %d bytes: strong %d, weak %d; hidden %d, labeled %d" % (
        len(fn), sum(r["size"] for r in fn), sum(1 for r in fn if r["conf"] == "strong"),
        sum(1 for r in fn if r["conf"] == "weak"), sum(1 for r in fn if r["kind"] == "hidden"),
        sum(1 for r in fn if r["kind"] == "labeled")))
    lost = [r for r in fn if r["shard"]]
    lines.append("code pieces whose start is a matched (EXACT/EXACT*) function in layout/matched but is not defined in "
                 "src/game: %d, %d bytes" % (len(lost), sum(r["size"] for r in lost)))
    big = sorted((r for r in fn if r["size"] >= 100), key=lambda r: -r["size"])
    lines.append("code pieces of 100 bytes or more: %d" % len(big))
    for r in big[:15]:
        lines.append("  %s %s %5d %-5s %-7s %s" % (r["region"], r["start"], r["size"], r["class"], r["kind"], r["draft"] and "draft" or ""))
    sc = collections.Counter()
    for r in stat.values():
        sc.update(r["stats"])
    lines.append("")
    lines.append("src/game functions: %d defined; extent from listing trace %d, from decode only %d, grown by decode %d, "
                 "untraceable (covered to the next label) %d" % (
                     sum(len(r["defs"]) for r in stat.values()), sc["src_traced"], sc["src_swept"],
                     sc["src_traced_grown"], sc["src_untraceable"]))
    stale_n = sum(len(stat[r]["stale"]) for r in stat)
    lines.append("header function: entries with no definition in the .c files and no SDK/runtime shard: %d" % stale_n)
    lines.append("definitions whose name resolves to no address (helpers, ignored): %d" % len(src.unresolved))
    lines.append("rows with a draft under --drafts: %d" % sum(1 for r in rows if r["draft"]))
    txt = "\n".join(lines) + "\n"
    with open(os.path.join(a.out, "gamegaps_summary.txt"), "w", encoding="utf-8") as fh:
        fh.write(txt)
    print(txt)

if __name__ == "__main__":
    main()
