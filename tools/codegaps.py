#!/usr/bin/env python3
"""codegaps.py: byte-complete check of the data the listings emit inside code.

Inside the code range of a region (first to last instruction the listing
decodes), every data item (.word, .short, .byte) must be explained as one of

  pool      a word read by a pc-relative load (Thumb `ldr rX, [pc, #n]`, ARM
            `ldr rX, [pc, #+-n]`, ldrh/ldrsb/ldrd literal forms) or `adr`
            (`add rX, pc, #n`) in the same region
  table     a switch / jump table: the run starts within three instructions
            after a dispatch (`add pc, rX`, `mov pc, rX`, ARM `add pc, pc, ..`
            or `ldr pc, [pc, rX, lsl #n]`)
  veneer    the pointer word of a linker veneer (match._veneer_size)
  padding   zero bytes or Thumb nops (0x46C0) between functions; a zero run of
            at most 16 bytes
  object    inside a declared data object of layout/data_objects.txt (a row
            that is not a `pool` row: string, data-decl, range, table-guess)

Everything else is unexplained.  An unexplained run is code nothing reaches
(dead code) or data nobody has named.  For each run the tool prints its
bytes, whether it starts with a push prologue, whether a return follows in
the run, and the nearest label before it.

usage: python tools/codegaps.py [--region R] [--tsv FILE] [--quiet] [--asm DIR]

--asm DIR reads the whole-region listings of another asm tree (arm9/main.s,
arm9/itcm.s, overlays/ovNNN.s, twl/twl.s, ov230d/ov230d.s), e.g. one written
by `python tools/disasm.py -o DIR ...`, instead of the asm/ units.
exit status 1 when any unexplained run remains.
"""
import argparse
import bisect
import os
import re
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import match  # noqa: E402

ROOT = match.ROOT
RE_ADDR = re.compile(r"/\*\s*([0-9A-F]{8})")
RE_INST = re.compile(r"/\*\s*([0-9A-F]{8})\s+((?:[0-9A-F]{2}\s?)+)")
RE_WORD = re.compile(r"^\s*\.word\s+(0x[0-9A-Fa-f]+|-?\d+)")
RE_BYTE = re.compile(r"^\s*\.byte\s+(.*?)\s*(?:/\*.*)?$")
RE_SHORT = re.compile(r"^\s*\.(?:short|hword|2byte)\s+(.*?)\s*(?:/\*.*)?$")

AUTOLOAD_FILES = {"arm9_autoload1_MAIN_TWL": "autoload1_main_twl.s",
                  "arm9_autoload2_MAIN_TWL": "autoload2_main_twl.s",
                  "arm9_autoload3_VRAM_LCDC": "vram_lcdc.s"}


ASM_DIR = None   # --asm: read the whole-region listings of another asm tree


def alt_listing(name):
    """The listing of a region under --asm DIR (the monolithic form that
    `disasm.py -o DIR` writes), or []."""
    d = ASM_DIR
    if name == "arm9":
        p = os.path.join(d, "arm9", "main.s")
    elif name.startswith("arm9_autoload0"):
        p = os.path.join(d, "arm9", "itcm.s")
    elif name in AUTOLOAD_FILES:
        p = os.path.join(d, "arm9", AUTOLOAD_FILES[name])
    elif name == "twl":
        p = os.path.join(d, "twl", "twl.s")
    elif name == "ov230d":
        p = os.path.join(d, "ov230d", "ov230d.s")
    elif name.startswith("ov"):
        p = os.path.join(d, "overlays", "ov%s.s" % name[2:])
    else:
        return []
    return [p] if os.path.exists(p) else []


def listing_paths(name):
    if ASM_DIR:
        return alt_listing(name)
    f = match.listing_files(name)
    if not f and name in AUTOLOAD_FILES:
        f = [os.path.join(ROOT, "asm", "arm9", AUTOLOAD_FILES[name])]
    return f


def parse(name):
    """Items in address order: ('i', addr, size, thumb) / ('w', addr, size,
    value) / ('b', addr, size, bytes).  Plus the label addresses."""
    items = []
    labels = []
    locs = []
    for path in listing_paths(name):
        thumb = False
        base = None
        off = 0
        with open(path, errors="replace") as fh:
            for line in fh:
                s = line.strip()
                if s in (".thumb", ".code 16"):
                    thumb = True
                    continue
                if s in (".arm", ".code 32"):
                    thumb = False
                    continue
                if s.startswith(".org"):
                    off = int(s.split()[1].split("/")[0], 0)
                    continue
                if s.endswith(":") and not s.startswith("/"):
                    if s.startswith(("func_", "veneer_")):
                        labels.append(int(s.split("_")[1][:-1], 16))
                    elif s.startswith("loc_"):
                        locs.append(int(s[4:-1], 16))
                    continue
                m = RE_INST.search(line)
                if m and not s.startswith((".word", ".byte", ".short")):
                    a = int(m.group(1), 16)
                    n = len(m.group(2).split())
                    base = a - off
                    items.append(("i", a, n, thumb))
                    off += n
                    continue
                if s.startswith(".word"):
                    m = RE_WORD.match(line)
                    m2 = RE_ADDR.search(line)
                    if m2:
                        a = int(m2.group(1), 16)
                        base = a - off
                    elif base is not None:
                        a = base + off
                    else:
                        continue
                    v = int(m.group(1), 0) & 0xFFFFFFFF if m else 0
                    items.append(("w", a, 4, v))
                    off += 4
                    continue
                if s.startswith(".byte"):
                    m = RE_BYTE.match(line)
                    vals = [int(x, 0) & 0xFF for x in m.group(1).split(",") if x.strip()] if m else []
                    if base is not None and vals:
                        items.append(("b", base + off, len(vals), bytes(vals)))
                    off += len(vals)
                    continue
                m = RE_SHORT.match(line)
                if m and base is not None:
                    vals = [int(x, 0) & 0xFFFF for x in m.group(1).split(",") if x.strip()]
                    items.append(("b", base + off, 2 * len(vals),
                                  b"".join(struct.pack("<H", v) for v in vals)))
                    off += 2 * len(vals)
    items.sort(key=lambda x: x[1])
    parse.locs = set(locs)
    return items, sorted(set(labels))


def sext(v, b):
    return v - (1 << b) if v & (1 << (b - 1)) else v


def declared_objects():
    """{region: sorted [(start, end_or_None)]} of non-pool rows."""
    out = {}
    try:
        fh = open(os.path.join(ROOT, "layout", "data_objects.txt"), errors="replace")
    except OSError:
        return out
    rows = {}
    with fh:
        for line in fh:
            if line.startswith("#") or not line.strip():
                continue
            p = line.split(None, 3)
            if len(p) < 3:
                continue
            try:
                a = int(p[1], 16)
            except ValueError:
                continue
            end = None
            if p[2] == "range" and len(p) > 3:
                m = re.match(r"\s*(0x[0-9A-Fa-f]{8})", p[3])
                if m:
                    end = int(m.group(1), 16)
            rows.setdefault(p[0], []).append((a, end, p[2]))
    for k, v in rows.items():
        out[k] = sorted(set(v), key=lambda x: (x[0], x[2] != 'pool'))
    return out


def check(name, regs, objs):
    r = regs[name]
    items, labels = parse(name)
    data = r.data
    base = r.base

    def rd16(a):
        o = a - base
        return struct.unpack_from("<H", data, o)[0] if 0 <= o and o + 2 <= len(data) else None

    def rd32(a):
        o = a - base
        return struct.unpack_from("<I", data, o)[0] if 0 <= o and o + 4 <= len(data) else None

    insts = [x for x in items if x[0] == "i"]
    if not insts:
        return [], 0, {}
    lo = insts[0][1]
    hi = insts[-1][1] + insts[-1][2]
    # pc-relative reads
    reads = set()
    dispatch_end = []   # (addr after a dispatch instruction)
    for _, a, n, th in insts:
        if th:
            h = rd16(a)
            if h is None:
                continue
            if (h & 0xF800) == 0x4800:
                t = ((a + 4) & ~3) + ((h & 0xFF) << 2)
                reads.update(range(t, t + 4))
            elif (h & 0xF800) == 0xA000:
                t = ((a + 4) & ~3) + ((h & 0xFF) << 2)
                reads.update(range(t, t + 4))
            elif (h & 0xFF87) in (0x4487, 0x4687):
                dispatch_end.append(a + n)
        else:
            w = rd32(a)
            if w is None:
                continue
            if (w & 0x0F7F0000) == 0x051F0000:
                imm = w & 0xFFF
                t = a + 8 + (imm if (w >> 23) & 1 else -imm)
                reads.update(range(t, t + 4))
            elif (w & 0x0E400090) == 0x00400090 and ((w >> 16) & 0xF) == 0xF:
                imm = ((w >> 4) & 0xF0) | (w & 0xF)
                t = a + 8 + (imm if (w >> 23) & 1 else -imm)
                reads.update(range(t, t + 8))
            elif (w & 0x0FAF0000) == 0x028F0000 and (w & 0x0FFFF000) != 0x028FF000:
                rot = ((w >> 8) & 0xF) * 2
                v8 = w & 0xFF
                imm = ((v8 >> rot) | (v8 << (32 - rot))) & 0xFFFFFFFF if rot else v8
                t = a + 8 + (imm if (w >> 23) & 1 else -imm)
                reads.update(range(t, t + 4))
            elif (w & 0x0FFFF000) == 0x008FF000 or (w & 0x0F7FF000) == 0x071FF000 \
                    or (w & 0x0FFFFFF0) == 0x01A0F000:
                dispatch_end.append(a + n)
    # per item status
    def padding_bytes(b):
        return all(c == 0 for c in b) or (len(b) % 2 == 0 and all(
            b[i:i + 2] == b"\xc0\x46" for i in range(0, len(b), 2)))

    inst_order = [x[1] for x in insts]
    status = {}
    # table runs: contiguous data items starting within 3 instructions after a dispatch
    data_items = [x for x in items if x[0] != "i" and lo <= x[1] < hi]
    runs = []
    cur = []
    for it in data_items:
        if cur and it[1] == cur[-1][1] + cur[-1][2]:
            cur.append(it)
        else:
            if cur: runs.append(cur)
            cur = [it]
    if cur: runs.append(cur)
    dend_at = {}   # end address of a dispatch -> (address, thumb)
    for _, a, n, th in insts:
        if (a + n) in set(dispatch_end):
            dend_at[a + n] = (a, th)
    istarts = set(inst_order) | set(labels) | parse.locs
    table_items = set()
    ttargets = set()
    for run in runs:
        st = run[0][1]
        k = bisect.bisect_left(inst_order, st)
        found = None
        for p in inst_order[max(0, k - 3):k]:
            ii = insts[bisect.bisect_left(inst_order, p)]
            if p + ii[2] in dend_at:
                found = dend_at[p + ii[2]]
        if not found:
            continue
        B, th = found
        end_run = run[-1][1] + run[-1][2]
        t = st
        mn = end_run
        if th:
            while t + 2 <= min(end_run, mn):
                h = rd16(t)
                tg = (B + 4 + sext(h, 16)) & ~1
                if h is None or not (lo <= tg < hi):
                    break
                mn = min(mn, tg)
                ttargets.add(tg)
                t += 2
        else:
            while t + 4 <= min(end_run, mn):
                v = rd32(t)
                if v is None or not (lo <= (v & ~1) < hi):
                    break
                mn = min(mn, v & ~1)
                ttargets.add(v & ~1)
                t += 4
        for it in run:
            if it[1] < t:
                table_items.add(it[1])
    # veneer pointer words
    def in_veneer(a):
        for back in range(0, 16, 4):
            o = a - back - base
            if o < 0: break
            n = match._veneer_size(data, o)
            if n and back < n:
                return True
        return False
    ob = objs.get(name, [])
    ob_starts = [x[0] for x in ob]

    def in_object(a):
        i = bisect.bisect_right(ob_starts, a) - 1
        if i < 0: return False
        s, e, kd = ob[i]
        if kd == "pool":
            return False
        nxt = ob_starts[i + 1] if i + 1 < len(ob) else None
        e = e if e else nxt
        return e is not None and a < e
    # zero-run lengths
    zero_run = {}
    for run in runs:
        j = 0
        while j < len(run):
            if run[j][0] == "w" and run[j][3] == 0:
                k2 = j
                while k2 < len(run) and run[k2][0] == "w" and run[k2][3] == 0:
                    k2 += 1
                for t in range(j, k2): zero_run[run[t][1]] = (k2 - j) * 4
                j = k2
            else:
                j += 1
    cats = {"pool": 0, "table": 0, "veneer": 0, "padding": 0, "object": 0}
    unexpl = []
    for it in data_items:
        kind, a, n, v = it
        c = None
        if any((a + k) in reads for k in range(n)):
            c = "pool"
        elif a in table_items:
            c = "table"
        elif kind == "w" and in_veneer(a):
            c = "veneer"
        elif kind == "b" and padding_bytes(v):
            c = "padding"
        elif kind == "w" and v == 0 and zero_run.get(a, 99) <= 16:
            c = "padding"
        elif in_object(a):
            c = "object"
        if c: cats[c] += 1
        else: unexpl.append(it)
    # group unexplained into contiguous runs
    out = []
    cur = []
    for it in unexpl:
        if cur and it[1] == cur[-1][1] + cur[-1][2]:
            cur.append(it)
        else:
            if cur: out.append(cur)
            cur = [it]
    if cur: out.append(cur)
    res = []
    for run in out:
        a = run[0][1]
        size = run[-1][1] + run[-1][2] - a
        o = a - base
        b = bytes(data[o:o + size])
        thumbmode = None
        k = bisect.bisect_left(inst_order, a)
        if k:
            thumbmode = insts[k - 1][3]
        push = ret = False
        if thumbmode:
            for d in (0, 2):
                h = rd16(a + d)
                if h is not None and (h & 0xFF00) == 0xB500:
                    push = True
            for d in range(0, size - 1, 2):
                h = rd16(a + d)
                if (h & 0xFF00) == 0xBD00 or (h & 0xFF87) == 0x4700 and h != 0x4700:
                    ret = True
        else:
            w = rd32(a)
            push = w is not None and (w & 0xFFFF0000) == 0xE92D0000
            for d in range(0, size - 3, 4):
                w = rd32(a + d)
                if (w & 0x0FFFFFF0) == 0x012FFF10 or (w & 0x0FFF8000) == 0x08BD8000:
                    ret = True
        tt = sum(1 for x in ttargets if a <= x < a + size)
        ptrw = 0
        for d in range(0, size - 3, 4):
            v = rd32(a + d)
            if v is not None and base <= (v & ~1) < base + len(data):
                ptrw += 1
        li = bisect.bisect_right(labels, a) - 1
        lab = ("func_%08X+0x%X" % (labels[li], a - labels[li])) if li >= 0 else "-"
        res.append((name, a, size, "thumb" if thumbmode else "arm", int(push), int(ret), lab, b[:16].hex(), tt, ptrw))
    return res, len(data_items), cats


def codelike(x):
    return bool(x[4] or x[8] or (x[5] and not x[9]))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--region")
    ap.add_argument("--tsv")
    ap.add_argument("--quiet", action="store_true", help="counts only")
    ap.add_argument("--asm", help="asm tree to read (default: asm/ units)")
    args = ap.parse_args()
    if args.asm:
        global ASM_DIR
        ASM_DIR = os.path.abspath(args.asm)
    regs = {r.name: r for r in match.load_all_regions()}
    objs = declared_objects()
    names = [args.region] if args.region else sorted(regs)
    total = 0
    allrows = []
    for n in names:
        if n not in regs:
            sys.exit("no region " + n)
        res, nitems, cats = check(n, regs, objs)
        if not nitems and not res:
            continue
        total += len(res)
        allrows += res
        bytes_ = sum(x[2] for x in res)
        print("%-26s items %6d  " % (n, nitems) + " ".join("%s=%d" % kv for kv in cats.items())
              + "  UNEXPLAINED runs=%d bytes=%d" % (len(res), bytes_))
        if not args.quiet:
            for x in res:
                print("  %08X +%-5d %-5s push=%d ret=%d tt=%d ptrw=%d  %s  %s" % (x[1], x[2], x[3], x[4], x[5], x[8], x[9], x[6], x[7]))
    print("total unexplained runs: %d (code-like: %d, bytes %d)" % (total, sum(1 for x in allrows if codelike(x)), sum(x[2] for x in allrows if codelike(x))))
    if args.tsv:
        with open(args.tsv, "w") as fh:
            fh.write("region\taddress\tsize\tisa\tpush\tret\tnearest_label\tbytes16\ttable_targets\tptr_words\tcodelike\n")
            for x in allrows:
                fh.write("%s\t0x%08X\t%d\t%s\t%d\t%d\t%s\t%s\t%d\t%d\t%d\n" % (x + (int(codelike(x)),)))
    sys.exit(1 if total else 0)


if __name__ == "__main__":
    main()
