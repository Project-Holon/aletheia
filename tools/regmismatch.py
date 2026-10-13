#!/usr/bin/env python3
"""Verify the "register mismatch" class of layout/register_mismatch.txt.

A register mismatch is a function whose best C draft compiles to the same size as
the original and to the same instructions, except for the choice of registers and
the order of independent instructions inside a basic block.  Such functions count
in the coverage percentage as their own class (see tools/coveragemap.py) until a
later pass makes them byte-exact.

Rows of layout/register_mismatch.txt (columns separated by white space; a '#'
starts a comment; the note is the rest of the line):

    region  address  isa  draft-path  note

    region   a match.py region name (ov070, twl, ...)
    address  0x-prefixed hexadecimal
    isa      thumb or arm
    draft    path of the C draft, relative to the repository root
    note     free text

The compiled function is named func_<ADDRESS> in the draft.

The rule, checked for each row:
  1. compiled size equals the original size;
  2. every instruction is equal after replacing r0-r12 by a placeholder (opcode,
     condition, immediates, shifts, offsets, sp/lr/pc operands all identical);
  3. the instruction order may differ only inside a basic block, and only by
     swapping instructions that are independent (no register, flag or memory
     dependence, judged with the registers of both versions);
  4. every branch and call target is equal (targets are compared as absolute
     addresses), the basic-block boundaries are the same, and every
     literal-pool word is equal (relocated words are compared by address).

Usage:
    python tools/regmismatch.py                  every row
    python tools/regmismatch.py --addr 0x0272F0BC  one row
    python tools/regmismatch.py -v               also print the instruction diffs

Exit status: 0 when every row passes, 1 when any row fails.
"""
import argparse
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

TABLE = os.path.join(ROOT, "layout", "register_mismatch.txt")

_REGNAMES = {"sb": "r9", "sl": "r10", "fp": "r11", "ip": "r12"}
_REG = re.compile(r"\b(?:r(?:1[0-2]|[0-9])|sb|sl|fp|ip)\b")
_IMM = re.compile(r"#(-?)0x([0-9a-f]+)")


def read_rows(path=TABLE):
    """[{region, addr, thumb, src, note, line}] from the table file."""
    rows = []
    if not os.path.exists(path):
        return rows
    with open(path, encoding="utf-8") as fh:
        for n, raw in enumerate(fh, 1):
            line = raw.strip()
            if not line or line.startswith("#"):
                continue
            parts = line.split(None, 4)
            if len(parts) < 4:
                continue
            region, addr, isa, src = parts[:4]
            note = parts[4] if len(parts) > 4 else ""
            rows.append({"region": region, "addr": int(addr, 0), "thumb": isa.lower() == "thumb",
                         "src": src, "note": note, "line": n})
    return rows


def norm_region(region):
    m = re.match(r"^(?:overlay_|ov)(\d+)$", region)
    return "ov%03d" % int(m.group(1)) if m else region


_CACHE_PATH = os.path.join(ROOT, "build", "cache", "regmismatch_sizes.json")


def sizes(path=TABLE):
    """[{region, addr, size, name, thumb}] for the coverage tools.

    The size is the code size of the draft's compile (equal to the original's size once
    the row passes).  It is cached in build/cache/regmismatch_sizes.json under the
    draft's size and modification time, so the coverage tools do not compile on every run.
    """
    import json
    try:
        with open(_CACHE_PATH, encoding="utf-8") as fh:
            cache = json.load(fh)
    except Exception:
        cache = {}
    out = []
    dirty = False
    for row in read_rows(path):
        src = row["src"] if os.path.isabs(row["src"]) else os.path.join(ROOT, row["src"])
        if not os.path.exists(src):
            print("regmismatch: draft %s of %08X is missing, row skipped" % (row["src"], row["addr"]),
                  file=sys.stderr)
            continue
        st = os.stat(src)
        key = "%s:%08X" % (row["region"], row["addr"])
        stamp = [st.st_size, int(st.st_mtime)]
        ent = cache.get(key)
        if not ent or ent.get("stamp") != stamp or ent.get("thumb") != row["thumb"]:
            res = analyse(row)
            ent = {"stamp": stamp, "size": res["size"], "thumb": row["thumb"]}
            cache[key] = ent
            dirty = True
        if ent["size"] > 0:
            out.append({"region": norm_region(row["region"]), "addr": row["addr"], "size": ent["size"],
                        "name": "func_%08X" % row["addr"], "thumb": row["thumb"]})
    if dirty:
        try:
            os.makedirs(os.path.dirname(_CACHE_PATH), exist_ok=True)
            with open(_CACHE_PATH, "w", encoding="utf-8", newline=chr(10)) as fh:
                json.dump(cache, fh, indent=1)
        except OSError:
            pass
    return out


# ---------------------------------------------------------------------------
# decoding
# ---------------------------------------------------------------------------

class Ins:
    __slots__ = ("addr", "size", "raw", "mnem", "ops", "norm", "reads", "writes",
                 "kind", "target", "lit", "mem")

    def __init__(self):
        self.lit = None
        self.target = None
        self.mem = None


def _cs(thumb):
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_ARM,
                     (capstone.CS_MODE_THUMB if thumb else capstone.CS_MODE_ARM)
                     | capstone.CS_MODE_LITTLE_ENDIAN)
    md.detail = True
    return md


def _regname(md, r):
    return md.reg_name(r)


def _decode_all(data, base, thumb, words):
    """Decode into a list of Ins; `words` is the set of pool offsets (4-byte data words)."""
    import capstone
    from capstone import arm_const as A
    md = _cs(thumb)
    out = []
    off = 0
    n = len(data)
    while off < n:
        if off in words:
            ins = Ins()
            ins.addr = base + off
            ins.size = 4
            ins.raw = data[off:off + 4]
            ins.kind = "pool"
            ins.mnem = ".word"
            ins.norm = None
            ins.reads = ins.writes = frozenset()
            out.append(ins)
            off += 4
            continue
        got = list(md.disasm(data[off:off + 4], base + off, 1))
        ins = Ins()
        ins.addr = base + off
        if not got:
            ins.size = 2 if thumb else 4
            ins.raw = data[off:off + ins.size]
            ins.kind = "undec"
            ins.mnem = ".raw"
            ins.norm = ("raw", ins.raw)
            ins.reads = ins.writes = frozenset()
            out.append(ins)
            off += ins.size
            continue
        c = got[0]
        ins.size = c.size
        ins.raw = data[off:off + c.size]
        ins.mnem = c.mnemonic
        ins.kind = "op"
        text = c.op_str
        regs_r, regs_w = c.regs_access()
        reads = {md.reg_name(r) for r in regs_r}
        writes = {md.reg_name(r) for r in regs_w}
        # branches and calls: target in the text is absolute already
        is_call = c.mnemonic.startswith(("bl", "blx")) and not c.mnemonic.startswith(("bic", "blt")) \
            and (c.mnemonic.split(".")[0] in ("bl", "blx") or re.match(r"^blx?(eq|ne|cs|hs|cc|lo|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?$", c.mnemonic))
        is_branch = bool(re.match(r"^b(eq|ne|cs|hs|cc|lo|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?(\.w|\.n)?$", c.mnemonic)) \
            or c.mnemonic in ("bx", "cbz", "cbnz") or bool(re.match(r"^bx(eq|ne|cs|hs|cc|lo|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)$", c.mnemonic))
        writes_pc = "pc" in writes
        if is_call:
            ins.kind = "call"
        elif is_branch or writes_pc:
            ins.kind = "branch"
        # pc-relative literal load
        for op in c.operands:
            if op.type == A.ARM_OP_MEM and md.reg_name(op.mem.base) == "pc" and c.mnemonic.startswith("ldr"):
                pc = ((c.address + 4) & ~3) if thumb else c.address + 8
                ins.lit = pc + op.mem.disp
        # normalise registers (r0-r12 -> R); sp/lr/pc stay
        norm = _REG.sub("R", text)
        if ins.lit is not None:
            norm = re.sub(r"\[pc[^\]]*\]", "[lit]", norm)
        ins.norm = (c.mnemonic, norm)
        # dependence resources
        rr = {x for x in reads if x not in ("pc",)}
        ww = {x for x in writes if x not in ("pc",)}
        if c.update_flags:
            ww.add("flags")
        cc = c.cc
        if cc not in (A.ARM_CC_AL, A.ARM_CC_INVALID):
            rr.add("flags")
        if re.match(r"^(adc|sbc|rsc)", c.mnemonic):
            rr.add("flags")
        if "cpsr" in rr:
            rr.discard("cpsr"); rr.add("flags")
        if "cpsr" in ww:
            ww.discard("cpsr"); ww.add("flags")
        mn = c.mnemonic
        if ins.lit is None:
            load = re.match(r"^(ldr|ldm|pop|swp)", mn)
            store = re.match(r"^(str|stm|push|swp)", mn)
            if load or store:
                # ("r", base, disp, width, is_store) for [base, #imm]; "?" when not analysable
                info = "?"
                if re.match(r"^(ldr|str)(b|h|sb|sh|d)?(eq|ne|cs|hs|cc|lo|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?$", mn)                         and not c.writeback:
                    for op in c.operands:
                        if op.type == A.ARM_OP_MEM and op.mem.index == 0 and op.mem.base != 0:
                            bname = md.reg_name(op.mem.base)
                            m2 = re.match(r"^(?:ldr|str)(sb|sh|b|h|d)?", mn)
                            width = {"b": 1, "sb": 1, "h": 2, "sh": 2, "d": 8}.get(m2.group(1), 4)
                            info = ("r", bname, op.mem.disp, width, bool(store))
                if info == "?":
                    info = ("?", bool(store))
                ins.mem = info
        if ins.kind in ("call", "branch"):
            rr.add("BARRIER"); ww.add("BARRIER")
        ins.reads = frozenset(rr)
        ins.writes = frozenset(ww)
        out.append(ins)
        off += c.size
    return out


# ---------------------------------------------------------------------------
# comparison
# ---------------------------------------------------------------------------

def _pool_words(data, base, thumb, extra_pool=()):
    """Offsets of literal-pool words: targets of pc-relative loads."""
    md = _cs(thumb)
    from capstone import arm_const as A
    words = set()
    off = 0
    n = len(data)
    step = 2 if thumb else 4
    while off < n:
        got = list(md.disasm(data[off:off + 4], base + off, 1))
        if not got:
            off += step
            continue
        c = got[0]
        for op in c.operands:
            if op.type == A.ARM_OP_MEM and md.reg_name(op.mem.base) == "pc" and c.mnemonic.startswith("ldr"):
                pc = ((c.address + 4) & ~3) if thumb else c.address + 8
                t = pc + op.mem.disp - base
                if 0 <= t <= n - 4:
                    words.add(t)
        off += c.size
    return words


def _patched_compiled(fb, tgt, base):
    """Compiled bytes with unresolved ABS32 words filled from symbol names.

    Returns (bytes, list of problems).  A word that stays unresolved and whose symbol
    name carries no address is reported, not guessed.
    """
    data = bytearray(fb.data)
    problems = []
    for (off, typ, sym, addend) in fb.relocs:
        if off + 4 > len(data):
            continue
        if all(fb.mask[off:off + 4]):
            continue
        t = str(typ)
        if "ABS32" not in t and t != "2":
            problems.append("unresolved %s at +%04X (%s)" % (t, off, sym))
            continue
        m = re.search(r"([0-9A-Fa-f]{8})$", sym)
        if not m:
            problems.append("unresolved word at +%04X: symbol %s has no address" % (off, sym))
            continue
        val = (int(m.group(1), 16) + addend) & 0xFFFFFFFF
        data[off:off + 4] = val.to_bytes(4, "little")
    return bytes(data), problems


def _blocks(insns):
    """Basic-block start addresses: first instruction, targets, and after every branch/call."""
    starts = {insns[0].addr} if insns else set()
    for i, ins in enumerate(insns):
        if ins.kind in ("branch", "call") and i + 1 < len(insns):
            starts.add(insns[i + 1].addr)
        if ins.kind == "pool":
            starts.add(ins.addr)
        t = _target_of(ins)
        if t is not None:
            starts.add(t)
    return starts


def _target_of(ins):
    if ins.kind in ("branch", "call") and ins.norm and ins.norm[0] not in ("bx",):
        m = re.search(r"#0x([0-9a-f]+)$", ins.norm[1])
        if m:
            return int(m.group(1), 16)
    return None


def _mem_conflict(a, b):
    if a.mem is None or b.mem is None:
        return False
    a_store = a.mem[4] if a.mem[0] == "r" else a.mem[1]
    b_store = b.mem[4] if b.mem[0] == "r" else b.mem[1]
    if not (a_store or b_store):
        return False        # two loads never conflict
    if a.mem[0] == "r" and b.mem[0] == "r" and a.mem[1] == b.mem[1]:
        lo1, hi1 = a.mem[2], a.mem[2] + a.mem[3]
        lo2, hi2 = b.mem[2], b.mem[2] + b.mem[3]
        return not (hi1 <= lo2 or hi2 <= lo1)
    return True


def _dependent(a, b):
    """True when a (earlier) and b (later) may not swap, under their own registers."""
    if a.writes & b.reads or a.writes & b.writes or a.reads & b.writes:
        return True
    return _mem_conflict(a, b)


def analyse(row, verbose=False):
    import match as M
    addr = row["addr"]
    src = row["src"]
    if not os.path.isabs(src):
        src = os.path.join(ROOT, src)
    func = "func_%08X" % addr
    thumb = row["thumb"]
    res = {"size": 0, "target_size": None, "diff_bytes": 0, "problems": [], "notes": [],
           "label": None}
    r = M.run_one(src, func, addr, "1.1p1", ["-O4,p"], thumb, None, region=row["region"])
    if r.status == "CCERR":
        res["problems"].append("compile error: %s" % r.note)
        return res
    fb = r.func
    res["size"] = len(fb.data)
    res["target_size"] = r.target_size
    tgt = r.target
    if fb.thumb != thumb:
        res["problems"].append("compiled ISA %s, row says %s" % ("Thumb" if fb.thumb else "ARM",
                                                                  "Thumb" if thumb else "ARM"))
    if len(tgt) != len(fb.data):
        res["problems"].append("size differs: original window %d, compiled %d" % (len(tgt), len(fb.data)))
    if r.target_size is not None and r.target_size != len(fb.data):
        res["notes"].append("listing extent is %d bytes, compiled %d" % (r.target_size, len(fb.data)))
    data, probs = _patched_compiled(fb, tgt, addr)
    res["problems"] += probs
    n = min(len(data), len(tgt))
    res["diff_bytes"] = sum(1 for i in range(n) if data[i] != tgt[i]) + abs(len(data) - len(tgt))
    if len(tgt) != len(data):
        return res

    # pool words: must be the same set in both versions
    pw_o = _pool_words(tgt, addr, thumb)
    pw_c = _pool_words(data, addr, thumb)
    if pw_o != pw_c:
        res["problems"].append("literal pool differs: original words at %s, compiled at %s"
                               % (sorted(hex(x) for x in pw_o - pw_c) or "-",
                                  sorted(hex(x) for x in pw_c - pw_o) or "-"))
    o = _decode_all(tgt, addr, thumb, pw_o)
    c = _decode_all(data, addr, thumb, pw_o)

    # pool words equal
    for a, b in zip(o, c):
        if a.kind == "pool" and a.raw != b.raw:
            res["problems"].append("pool word at %08X differs: original %08X, compiled %08X"
                                   % (a.addr, int.from_bytes(a.raw, "little"),
                                      int.from_bytes(b.raw, "little")))
    # literal loads: compare the value loaded
    litval = {}
    for ins_list, buf in ((o, tgt), (c, data)):
        for ins in ins_list:
            if ins.lit is not None and 0 <= ins.lit - addr <= len(buf) - 4:
                v = int.from_bytes(buf[ins.lit - addr:ins.lit - addr + 4], "little")
                ins.norm = (ins.norm[0], ins.norm[1] + " =%08X" % v)

    # instruction count and positions
    if [x.size for x in o] != [x.size for x in c] and len(o) != len(c):
        res["problems"].append("instruction sizes/counts differ (%d vs %d)" % (len(o), len(c)))
    so, sc = _blocks(o), _blocks(c)
    if so != sc:
        res["problems"].append("basic-block boundaries differ: %s"
                               % sorted(hex(x) for x in so ^ sc))
    bounds = sorted(so | sc | {addr + len(tgt)})

    # per-block comparison
    idx_o = {x.addr: i for i, x in enumerate(o)}
    ndiff_ins = 0
    reordered = 0
    for bi in range(len(bounds) - 1):
        lo, hi = bounds[bi], bounds[bi + 1]
        bo = [x for x in o if lo <= x.addr < hi]
        bc = [x for x in c if lo <= x.addr < hi]
        if [x.norm for x in bo] == [x.norm for x in bc] and all(
                (x.kind == "pool") == (y.kind == "pool") for x, y in zip(bo, bc)):
            for x, y in zip(bo, bc):
                if x.raw != y.raw:
                    ndiff_ins += 1
            continue
        # try a permutation
        if len(bo) != len(bc):
            res["problems"].append("block %08X..%08X: %d vs %d instructions" % (lo, hi, len(bo), len(bc)))
            continue
        used = [False] * len(bc)
        perm = []
        ok = True
        for x in bo:
            for j, y in enumerate(bc):
                if not used[j] and y.norm == x.norm and (x.kind == "pool") == (y.kind == "pool"):
                    used[j] = True
                    perm.append(j)
                    break
            else:
                ok = False
                res["problems"].append("block %08X..%08X: instruction at %08X (%s %s) has no counterpart"
                                       % (lo, hi, x.addr, x.mnem, x.norm[1] if x.norm else ""))
                break
        if not ok:
            continue
        bad = False
        for i in range(len(bo)):
            for j in range(i + 1, len(bo)):
                if perm[i] > perm[j]:
                    if _dependent(bo[i], bo[j]) or _dependent(bc[perm[j]], bc[perm[i]]) \
                            or bo[i].kind in ("branch", "call", "pool") or bo[j].kind in ("branch", "call", "pool"):
                        res["problems"].append(
                            "block %08X..%08X: dependent instructions %08X and %08X are reordered"
                            % (lo, hi, bo[i].addr, bo[j].addr))
                        bad = True
        if not bad:
            reordered += 1
        for x, y in zip(bo, bc):
            if x.raw != y.raw:
                ndiff_ins += 1
    res["ins_differ"] = ndiff_ins
    res["blocks_reordered"] = reordered
    res["instructions"] = len(o)
    return res


def listing_label(region, addr):
    """True when `addr` is a function label in the region's asm listing."""
    import glob
    cands = []
    if region == "twl":
        cands = [os.path.join(ROOT, "asm", "twl", "twl.s")]
    elif region.startswith("ov"):
        cands = [os.path.join(ROOT, "asm", "overlays", region + ".s")]
    else:
        cands = glob.glob(os.path.join(ROOT, "asm", "*", region + ".s"))
    pat = re.compile(r"^func_%08X:" % addr, re.I)
    for p in cands:
        if os.path.exists(p):
            with open(p, encoding="utf-8", errors="replace") as fh:
                for line in fh:
                    if pat.match(line):
                        return True
    return False


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--table", default=TABLE)
    ap.add_argument("--addr", help="check only this address")
    ap.add_argument("-v", "--verbose", action="store_true")
    a = ap.parse_args(argv)
    rows = read_rows(a.table)
    if a.addr:
        want = int(a.addr, 0)
        rows = [r for r in rows if r["addr"] == want]
    if not rows:
        print("regmismatch: no rows")
        return 0
    failed = 0
    for row in rows:
        try:
            res = analyse(row, a.verbose)
        except SystemExit as e:
            res = {"size": 0, "target_size": None, "diff_bytes": 0, "problems": [str(e)], "notes": []}
        ok = not res["problems"]
        failed += 0 if ok else 1
        print("%s  %s %08X (%s, %s)  %d B, %s bytes differ, %s instructions differ, %s block(s) reordered"
              % ("PASS" if ok else "FAIL", row["region"], row["addr"], "Thumb" if row["thumb"] else "ARM",
                 row["src"], res["size"], res["diff_bytes"], res.get("ins_differ", "?"),
                 res.get("blocks_reordered", "?")))
        for p in res["problems"]:
            print("      problem: " + p)
        for p in res["notes"]:
            print("      note: " + p)
        if not listing_label(row["region"], row["addr"]):
            print("      note: %08X is not a function label in the %s asm listing yet" % (row["addr"], row["region"]))
    print("%d row(s), %d fail" % (len(rows), failed))
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
