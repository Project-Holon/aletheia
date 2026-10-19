#!/usr/bin/env python3
"""arm9data.py: data mode companions for the ARM9 static module.

    python tools/arm9data.py [--out=DIR] [--relink] [--data-start=0xADDR]
    python tools/gamelink.py arm9_main --data --extra=build/datac/arm9

Same design as `datagen.py companions` for the overlays (see there and
docs/restructure/BUILD_FROM_GAME.md "Data mode"), for the module that starts at
0x02004000.  Written to build/datac/arm9/ and build/gen/datac/arm9/ from the
user's own extract; nothing is written to src/ or to a tracked file.

What is cut into typed C objects:

  * the data tail: .rodata from the end of the code (the literal pool of the
    last function) up to the first .data object, then .data up to
    SDK_STATIC_BSS_START (0x020A9E80).  The module has no static-initialiser
    table, so the two sections follow each other without a terminator;
  * .bss from SDK_STATIC_BSS_START to SDK_STATIC_BSS_END;
  * _start_BuildParams (crt0_build.c), the six .version strings (sdk_version_*.c, 0x02005030..0x02005124) and the
    SHA-1 round constants (sha1.c, 0x02081E6C) are source now, not companions;
Every object gets an owner file (the file whose code refers to it, else the file of
a function it points at, ...) and a companion <stem>.zdata.c / <stem>.zpre.c with
the header of that file, exactly as datagen.py does it for an overlay.  An object
whose candidate owners all lie before the current file (the original link order is
not the order of the header addresses here: shared tables, MSL and SDK files that
src/game splits differently) goes to the file of the object before it; those are
counted in the stats as "shifted".  datalink.json adds "arm9", "nosinit" and
"fixed" (now always empty) to the keys datagen writes.
"""
from __future__ import annotations

import argparse
import bisect
import json
import os
import re
import struct
import sys
from collections import Counter

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import datareg   # noqa: E402
import datagen   # noqa: E402

RG = "arm9"
DATA_START = 0x020A6C58          # first .data object (the greedy owner order restarts here)


CHK = os.path.join(ROOT, "build", "datac", "_chk")


def compiled_order(path):
    """(names of the .rodata/.data objects in link order, names of the .bss objects) of
    a compiled companion, or None when it does not compile."""
    import gamebuild
    import match
    gl = datagen._gl()
    raw = open(path, encoding="latin1").read()
    _h, st = gamebuild._settings(raw)
    os.makedirs(CHK, exist_ok=True)
    obj, _cmd, _log, _rc = match.compile_tu(path, st["compiler"], st["flags"].split(), st["isa"] == "thumb",
                                          st["lang"] or None, CHK)
    if obj is None:
        return None
    _d, secs, syms = gl.read_elf(obj)
    kind = {x["idx"]: x["name"] for x in secs}
    dat, bss = [], []
    for y in sorted(syms, key=lambda y: (y["shndx"], y["value"])):
        if not y["name"] or not y["shndx"] or y["name"][0] in "$." or y["name"].endswith("_anchor"):
            continue
        k = kind.get(y["shndx"])
        if k in (".rodata", ".data"):
            dat.append(y["name"])
        elif k == ".bss":
            bss.append(y["name"])
    return dat, bss


def plain_elf(relink=False):
    gl = datagen._gl()
    elf = os.path.join(gl.OUT, "arm9_main", "ov.elf")
    if relink or not os.path.exists(elf) or not os.path.exists(os.path.join(gl.OUT, "arm9_main", "ov.lcf")):
        r = gl.link_overlay("arm9_main", verbose=False)
        if not os.path.exists(elf):
            raise RuntimeError("plain link of arm9_main failed: %s" % r.get("why"))
    return gl.read_elf(elf)


def header_of(text, drop_flags=True):
    hdr = re.match(r"\s*/\*.*?\*/", text, re.S).group(0)
    return re.sub(r"^(\s*\*\s*flags:.*?)\s+-(?:ipa\s+\w+|inline\s+deferred)\b", r"\1", hdr, flags=re.M)


def companions(out=None, relink=False, data_start=DATA_START):
    import match
    gl = datagen._gl()
    layout = datareg.load_layout()
    base, img, lst = datareg.region_image(layout, RG)
    reg = datagen.load_registry()[RG]
    st = layout["arm9"]["static"]
    end = base + len(img)
    bs, be = st["bss_start"], st["bss_end"]
    if bs != end:
        raise RuntimeError("bss does not follow the image: %X %X" % (bs, end))
    files = datagen._file_list(RG)
    fstarts = [f["addr"] for f in files]
    fidx = {f["name"][:-2]: i for i, f in enumerate(files)}
    _d, bsecs, bsyms = plain_elf(relink)
    cend = max([x["addr"] + x["size"] for x in bsecs
                if re.fullmatch(r"t\d+(_\d+)?", x["name"]) and base <= x["addr"] < end] + [0])
    t0 = cend
    s0 = data_start
    fnames = {}
    thumb_at = set(y["value"] & ~1 for y in bsyms if y["name"] == "$t")
    for y in bsyms:
        if y["name"] and not y["name"].startswith("$") and y["shndx"] and (y["info"] & 15) == 2 \
                and "__" not in y["name"]:
            a_ = y["value"] & ~1
            fnames.setdefault(a_, (y["name"], 1 if (y["value"] & 1 or a_ in thumb_at) else 0))
    fbyname = {}
    for a, (n, _th) in fnames.items():
        fbyname.setdefault(n, a)
    blockers = []

    # ---- object starts
    starts = set(int(x["addr"], 16) for x in reg["objects"] if t0 <= int(x["addr"], 16) < end)
    _ce, _data, _labels, words = datareg.scan_listing(lst)
    pool_refs = {}
    hdr_names = {}

    def refs_into(lo, hi, acc):
        for site, v in words:
            if site < t0 and lo <= v < hi:
                fi = bisect.bisect_right(fstarts, site) - 1
                if fi >= 0:
                    pool_refs.setdefault(v, set()).add(fi)
                acc.add(v)
        for fi, f in enumerate(files):
            for n, (a, k) in f["hsyms"].items():
                if k == "data" and lo <= a < hi and re.fullmatch(r"[A-Za-z_]\w*", n):
                    hdr_names.setdefault(a, {}).setdefault(fi, []).append(n)
                    acc.add(a)
            for n, a in datagen._names_in(f["raw"], lo, hi):
                lstn = hdr_names.setdefault(a, {}).setdefault(fi, [])
                if n not in lstn:
                    lstn.append(n)
                acc.add(a)

    refs_into(t0, end, starts)

    # the data sections the code files define themselves (plain link .lcf regions dN)
    lcf = open(os.path.join(gl.OUT, "arm9_main", "ov.lcf")).read()
    own_regions = [(int(m.group(1), 16), int(m.group(2), 16)) for m in
                   re.finditer(r"^\s*d\d+ : ORIGIN = 0x([0-9A-Fa-f]+), LENGTH = 0x([0-9A-Fa-f]+)", lcf, re.M)]
    own_file = {}
    own_secs = {}
    for m in re.finditer(r"^\s*(d\d+) : ORIGIN = 0x([0-9A-Fa-f]+)", lcf, re.M):
        t = re.search(r"^\s*\.%s : \{ t(\d+)\.o \(\.d\d+_(\d+)\)" % m.group(1), lcf, re.M)
        if t:
            a_ = int(m.group(2), 16)
            fi_ = int(t.group(1))
            if fi_ < len(files) and (t0 <= a_ < end or bs <= a_ < be):
                own_file[a_] = fi_
                own_secs.setdefault(files[fi_]["name"][:-2], []).append([int(t.group(2)), "%08X" % a_])

    def own_sections(lo, hi):
        return [(a, a + n) for a, n in own_regions if n and lo <= a < hi]
    own_occ = own_sections(t0, end)
    for a, b in own_occ:
        starts.add(a)
        starts.add(b)
    starts |= {t0, s0}
    cuts = sorted(set([a for a in starts if t0 <= a < end] + [end]))
    objs = []
    for i, a in enumerate(cuts[:-1]):
        b = cuts[i + 1]
        if any(x <= a < y for x, y in own_occ):
            continue
        if b - a < 4 and any(y == a for _x, y in own_occ) and (any(x == b for x, _y in own_occ) or b == s0) \
                and img[a - base:b - base] == bytes(b - a) \
                and not any(pool_refs.get(k) or hdr_names.get(k) for k in range(a, b)):
            continue          # alignment padding next to an own section: the link makes it
        objs.append(dict(addr=a, size=b - a, sec=".rodata" if a < s0 else ".data",
                         data=img[a - base:b - base], inner=[]))
    # zero merge, as datagen.py: an all-zero piece of .data joins its neighbour
    merged = []
    for ob in objs:
        if ob["sec"] == ".data" and ob["data"] == bytes(ob["size"]) and merged and merged[-1]["sec"] == ".data" \
                and merged[-1]["addr"] + merged[-1]["size"] == ob["addr"]:
            p = merged[-1]
            p["inner"] += [ob["addr"]] + ob["inner"]
            p["size"] += ob["size"]
            p["data"] += ob["data"]
            continue
        if merged and merged[-1]["sec"] == ".data" and merged[-1].get("lead_zero") \
                and merged[-1]["addr"] + merged[-1]["size"] == ob["addr"]:
            p = merged.pop()
            ob = dict(ob, addr=p["addr"], size=p["size"] + ob["size"], data=p["data"] + ob["data"],
                      inner=[ob["addr"]] + p["inner"] + ob["inner"])
        elif ob["sec"] == ".data" and ob["data"] == bytes(ob["size"]):
            ob["lead_zero"] = True
        merged.append(ob)
    objs = merged
    # .bss
    bocc = own_sections(bs, be)
    bstarts = {bs}
    refs_into(bs, be, bstarts)
    for a, b in bocc:
        bstarts |= {a, b}
    bc = sorted(x for x in bstarts | {be} if bs <= x <= be)
    for i, a in enumerate(bc[:-1]):
        if not any(x <= a < y for x, y in bocc):
            b = bc[i + 1]
            if b - a < 4 and any(y == a for _x, y in bocc) and any(x == b for x, _y in bocc) and not any(
                    pool_refs.get(k) or hdr_names.get(k) for k in range(a, b)):
                continue
            objs.append(dict(addr=a, size=b - a, sec=".bss", data=None, inner=[]))

    # ---- pointer words
    match.load_all_regions()
    objstart = [x["addr"] for x in objs]
    for ob in objs:
        ob["ptrs"] = {}
        if ob["data"] is None or ob["addr"] % 4 or ob["size"] % 4:
            continue
        for k in range(ob["size"] // 4):
            w = struct.unpack_from("<I", ob["data"], 4 * k)[0]
            if base <= w < t0 and (w & ~1) in fnames:
                n, th = fnames[w & ~1]
                if th == (w & 1):
                    ob["ptrs"][k] = ("func", n, 0)
            elif t0 <= w < end:
                j = bisect.bisect_right(objstart, w) - 1
                if j >= 0 and objs[j]["data"] is not None:
                    ob["ptrs"][k] = ("obj", j, w - objs[j]["addr"])
            elif bs <= w < be:
                j = bisect.bisect_right(objstart, w) - 1
                if j >= 0 and objs[j]["sec"] == ".bss" and w < objs[j]["addr"] + objs[j]["size"]:
                    ob["ptrs"][k] = ("obj", j, w - objs[j]["addr"])
            elif 0x01FF8000 <= w < 0x02400000 and not (base <= w < end):
                ev = match.isa_evidence(w & ~1, "arm9")
                if ev and ((ev[0] == "thumb") == bool(w & 1)):
                    ob["ptrs"][k] = ("ext", "func_%08X" % (w & ~1), 0)

    # ---- owners and link order
    for ob in objs:
        own = set()
        for a in range(ob["addr"], ob["addr"] + ob["size"]):
            own |= pool_refs.get(a, set())
        own |= set(hdr_names.get(ob["addr"], {}))
        ob["direct"] = sorted(own)
        ob["ptrown"] = sorted(set(bisect.bisect_right(fstarts, fbyname[nm]) - 1
                                  for kind, nm, _off in ob["ptrs"].values() if kind == "func"))
        ob["refown"] = []
    for ob in objs:
        for kind, j, _off in ob["ptrs"].values():
            if kind == "obj" and j < len(objs):
                objs[j]["refown"] = sorted(set(objs[j]["refown"]) | set(ob["direct"] or ob["ptrown"]))
    shifted = 0
    for sec in (".rodata", ".data", ".bss"):
        lst_ = [ob for ob in objs if ob["sec"] == sec]
        lo_, hi_ = {".rodata": (t0, s0), ".data": (s0, end), ".bss": (bs, be)}[sec]
        cur = None
        prev = lo_ - 1
        for ob in lst_:
            for a in sorted(own_file):
                if prev < a <= ob["addr"] and (cur is None or own_file[a] >= cur):
                    cur = own_file[a]
            prev = ob["addr"]
            cand = ob["direct"] or ob["ptrown"] or ob["refown"]
            cap = min([fi_ for a_, fi_ in own_file.items() if lo_ <= a_ < hi_ and a_ > ob["addr"]], default=None)
            if cand:
                ok = [c for c in cand if (cur is None or c >= cur) and (cap is None or c <= cap)]
                if not ok and cap is not None and (cur is None or cap >= cur) and max(cand) > cap:
                    ok = [cap]
                if not ok:
                    shifted += 1      # the candidates lie before the current file: stays with its neighbour
                    ob["owner"] = cur
                    ob["shifted"] = list(cand)
                    continue
                cur = ok[0]
            ob["owner"] = cur
        nxt = None
        for ob in reversed(lst_):
            if ob["owner"] is None:
                ob["owner"] = nxt if nxt is not None else 0
            nxt = ob["owner"]

    def obj_name(ob, fi):
        nms = hdr_names.get(ob["addr"], {}).get(fi, [])
        return nms[0] if nms else "dg_%08X" % ob["addr"]

    def obj_align(ob, fi):
        if ob["data"] is None:
            return 1
        text = files[fi]["raw"]
        name = obj_name(ob, fi)
        if ob["addr"] % 4 == 0 and ob["size"] % 4 == 0 and \
                (ob["ptrs"] or re.compile(datagen.FP_RE % re.escape(name), re.M).search(text)):
            return 4
        m = re.compile(datagen.DECL_RE % re.escape(name), re.M).search(text)
        if m and m.group("arr") is not None:
            bt = re.sub(r"\s+", " ", re.sub(r"\b(const|volatile)\b", "", m.group("pre")).strip())
            if bt in datagen.SCALAR:
                sz = datagen.SCALAR[bt][0]
                if ob["size"] % sz == 0 and ob["addr"] % sz == 0:
                    return sz
        return 1

    for sec in (".rodata", ".data"):
        lst_ = [ob for ob in objs if ob["sec"] == sec]
        for i in range(1, len(lst_)):
            ob, pv = lst_[i], lst_[i - 1]
            if ob["owner"] == pv["owner"]:
                continue
            j = i + 1
            while j < len(lst_) and lst_[j]["owner"] == ob["owner"] and \
                    lst_[j - 1]["addr"] + lst_[j - 1]["size"] == lst_[j]["addr"]:
                j += 1
            al = max(obj_align(x, ob["owner"]) for x in lst_[i:j])
            if ob["addr"] % al == 0:
                continue
            if pv["addr"] + pv["size"] == ob["addr"]:
                ob["owner"] = pv["owner"]
            else:
                blockers.append("%s %08X: section of %s starts below its alignment %d"
                                % (sec, ob["addr"], files[ob["owner"]]["name"], al))

    # ---- names
    for ob in objs:
        names = hdr_names.get(ob["addr"], {})
        ob["names"] = names
        own_names = names.get(ob["owner"], [])
        ob["name"] = own_names[0] if own_names else "dg_%08X" % ob["addr"]
        ob["inner_names"] = [(n, a - ob["addr"]) for a in ob["inner"]
                             for nms in hdr_names.get(a, {}).values() for n in nms]

    # ---- emit
    out = out or os.path.join(datagen.DATAC_OUT, RG)
    gen = os.path.join(datagen.DATAC_GEN, RG)
    for dd in (out, gen):
        if os.path.isdir(dd):
            for f in os.listdir(dd):
                if f.endswith((".c", ".inc", ".json")):
                    os.remove(os.path.join(dd, f))
        os.makedirs(dd, exist_ok=True)
    stats = dict(objects=len(objs), bytes=sum(x["size"] for x in objs if x["sec"] != ".bss"),
                 bss_bytes=sum(x["size"] for x in objs if x["sec"] == ".bss"), typed=0, raw=0, bss=0,
                 shifted=shifted)
    aliases = {}
    by_owner = {}
    defined = Counter(ob["name"] for ob in objs)
    seen_n = set()
    for ob in objs:
        ob["src_name"] = ob["name"]
        if defined[ob["name"]] > 1:
            if ob["name"] in seen_n:
                ob["name"] = "%s__%X" % (ob["name"], ob["addr"])
            seen_n.add(ob["src_name"])
    for fi in set(ob["owner"] for ob in objs):
        for sec in (".rodata", ".data", ".bss"):
            mine = [ob for ob in objs if ob["owner"] == fi and ob["sec"] == sec]
            if not mine:
                continue
            lo, hi = mine[0]["addr"], mine[-1]["addr"]
            inner = sorted(a for a, b in own_occ + (bocc if sec == ".bss" else []) if lo < a and b <= hi)
            inner += sorted(a for a, fo in own_file.items() if fo == fi and a > hi
                            and mine[0]["addr"] < a < {".rodata": s0, ".data": end, ".bss": be}[sec]
                            and not (sec != ".bss" and bs <= a < be))
            for ob in mine:
                ob["pre"] = bool(inner) and ob["addr"] < inner[0]
    renames = {}

    def name_for(fi_, n, target, a):
        if n not in defined and aliases.get(n, target) == target:
            aliases[n] = target
            return
        stem_ = files[fi_]["name"][:-2]
        if n in renames.get(stem_, {}):
            blockers.append("name %s means two objects in %s" % (n, files[fi_]["name"]))
            return
        en = "%s__%X" % (n, a)
        renames.setdefault(stem_, {})[n] = en
        if en != target:
            aliases[en] = target

    for ob in objs:
        by_owner.setdefault((ob["owner"], ".zpre" if ob.get("pre") else ".zdata"), []).append(ob)
        for fi_, nms in ob["names"].items():
            for n in nms:
                if n != ob["name"]:
                    name_for(fi_, n, ob["name"], ob["addr"])
        for a in ob["inner"]:
            for fi_, nms in hdr_names.get(a, {}).items():
                for n in nms:
                    name_for(fi_, n, "%s + %d" % (ob["name"], a - ob["addr"]), a)
    stats["aliases"] = len(aliases)
    stats["companions"] = len(by_owner)

    def inc(ob):
        return ("%s/%08X.inc" % (gen, ob["addr"])).replace("\\", "/")

    def write_inc(ob, vals):
        with open(inc(ob), "w", newline="\n") as fh:
            for k in range(0, len(vals), 16):
                fh.write("    " + ", ".join(vals[k:k + 16]) + ",\n")

    for (fi, suffix), lst_ in sorted(by_owner.items()):
        f = files[fi]
        text = f["raw"]
        hdr = header_of(text)
        fwd, defs, ext, bdefs = [], [], set(), []
        add_def = lambda t_: defs.append((name, t_))
        own_names = set(ob["name"] for ob in lst_)
        for ob in lst_:
            name = ob["name"]
            cq = "const " if ob["sec"] == ".rodata" else ""
            if ob["sec"] == ".bss":
                fwd.append("extern unsigned char %s[%d];" % (name, ob["size"]))
                bdefs.append("unsigned char %s[%d];" % (name, ob["size"]))
                stats["bss"] += 1
                continue
            m = re.compile(datagen.DECL_RE % re.escape(ob["src_name"]), re.M).search(text)
            fp = re.compile(datagen.FP_RE % re.escape(ob["src_name"]), re.M).search(text)
            base_t = None
            if m and m.group("arr") is not None:
                bt = re.sub(r"\s+", " ", re.sub(r"\b(const|volatile)\b", "", m.group("pre")).strip())
                if bt in datagen.SCALAR:
                    base_t = bt

            def ref(k, ob=ob):
                kind, nm, off = ob["ptrs"][k]
                if kind == "obj":
                    nm = objs[nm]["name"]
                    if nm not in own_names:
                        ext.add("extern char %s[];" % nm)
                    return "((char *)&%s + %d)" % (nm, off) if off else "&%s" % nm
                ext.add("extern char %s[];" % nm)
                stats["ptr_" + kind] = stats.get("ptr_" + kind, 0) + 1
                return nm

            words_ = [struct.unpack_from("<I", ob["data"], 4 * k)[0] for k in range(ob["size"] // 4)] \
                if ob["addr"] % 4 == 0 and ob["size"] % 4 == 0 else None
            if fp and words_ is not None:
                et = "void (*)(void)"
                vals = []
                for k, w in enumerate(words_):
                    if k in ob["ptrs"]:
                        vals.append("(%s)%s" % (et, ref(k)))
                    elif w:
                        blockers.append("%s[%d]: 0x%08X has no symbol (code outside every file)" % (name, k, w))
                        vals.append("(%s)0x%X" % (et, w))
                    else:
                        vals.append("0")
                write_inc(ob, vals)
                decl = "void (*%s%s[%d])(void)" % (cq, name, len(words_))
                fwd.append("extern %s;" % decl)
                add_def("%s = {\n#include \"%s\"\n};" % (decl, inc(ob)))
                stats["typed"] += 1
            elif ob["ptrs"] and words_ is not None:
                fields, vals = [], []
                for k, w in enumerate(words_):
                    if k in ob["ptrs"]:
                        fields.append("void *w%d;" % k)
                        vals.append("(void *)%s" % ref(k))
                    else:
                        fields.append("unsigned long w%d;" % k)
                        vals.append("0x%08X" % w)
                write_inc(ob, vals)
                fwd.append("struct %s_t { %s };" % (name, " ".join(fields)))
                fwd.append("extern %sstruct %s_t %s;" % (cq, name, name))
                add_def("%sstruct %s_t %s = {\n#include \"%s\"\n};" % (cq, name, name, inc(ob)))
                stats["raw"] += 1
            elif base_t and ob["size"] % datagen.SCALAR[base_t][0] == 0 and ob["addr"] % datagen.SCALAR[base_t][0] == 0:
                sz, sg = datagen.SCALAR[base_t]
                fmt = {1: "b", 2: "h", 4: "i"}[sz]
                fmt = fmt if sg else fmt.upper()
                vals = [str(v) if sg else "0x%X" % v for v in struct.unpack("<%d%s" % (ob["size"] // sz, fmt), ob["data"])]
                write_inc(ob, vals)
                bt2 = base_t if base_t in datagen.PLAIN else (
                    {1: "signed char", 2: "short", 4: "long"}[sz] if sg else
                    {1: "unsigned char", 2: "unsigned short", 4: "unsigned long"}[sz])
                fwd.append("extern %s%s %s[%d];" % (cq, bt2, name, ob["size"] // sz))
                add_def("%s%s %s[%d] = {\n#include \"%s\"\n};" % (cq, bt2, name, ob["size"] // sz, inc(ob)))
                stats["typed"] += 1
            else:
                if ob["data"] == bytes(len(ob["data"])) and not cq:
                    blockers.append("%s: all-zero object in .data (mwccarm would put it in .bss)" % name)
                write_inc(ob, ["0x%02X" % c for c in ob["data"]])
                fwd.append("extern %sunsigned char %s[%d];" % (cq, name, ob["size"]))
                add_def("%sunsigned char %s[%d] = {\n#include \"%s\"\n};" % (cq, name, ob["size"], inc(ob)))
                stats["raw"] += 1
        stem = f["name"][:-2]
        body = hdr + "\n/* companion of %s: its data, initialisers generated by tools/arm9data.py from the ROM */\n\n" % f["name"]
        body += "\n".join(sorted(ext - set("extern char %s[];" % n for n in own_names))) + "\n"
        body += "\n".join(fwd) + "\n\n"
        bnames = [ob["name"] for ob in lst_ if ob["sec"] == ".bss"]
        # mwccarm gives every initialised object a section of its own and writes them
        # in an order of its own (the objects of equal size come out as
        # reverse(definitions[:-1]) + definitions[-1:], unequal ones are grouped:
        # measured; ov012's merged .rodata keeps source order).  Try the plain and
        # the reversed form, keep the one the compiler turns into the address order
        # (compiled and read back here); if neither works split the run in halves,
        # each half its own companion <stem>.zdata_N.c (they link one after the other)
        nfile = [0]

        def put(chunk, first):
            nm_ = suffix if nfile[0] == 0 else "%s_%d" % (suffix, nfile[0])
            path = os.path.join(out, stem + nm_ + ".c")
            bd = bdefs if first else []

            def render(order):
                t_ = body + "void %s__%s_anchor(void) { }\n\n" % (stem, nm_[1:])
                t_ += "\n\n".join(d[1] for d in order) + "\n"
                if bd:
                    t_ += "\n/* .bss: mwccarm emits uninitialised definitions in reverse order */\n"
                    t_ += "\n".join(reversed(bd)) + "\n"
                return t_
            want = [d[0] for d in chunk]
            cands = [chunk] if len(chunk) < 3 else [chunk[-2::-1] + chunk[-1:], chunk]
            got = None
            for order in cands:
                with open(path, "w", encoding="latin1", newline="\n") as fh:
                    fh.write(render(order))
                if len(chunk) < 3 and not bd:
                    nfile[0] += 1
                    return
                got = compiled_order(path)
                if got is not None and got[0] == want and got[1] == (bnames if first else []):
                    nfile[0] += 1
                    return
            if len(chunk) > 1:
                h_ = len(chunk) // 2
                put(chunk[:h_], first)
                put(chunk[h_:], False)
                stats["split"] = stats.get("split", 0) + 1
                return
            blockers.append("%s: compiled order differs from the address order (%s)" % (
                stem + nm_, "compile failed" if got is None else "got %s" % (got[0][:6] + got[1][:3],)))
            nfile[0] += 1
        put(defs, True)

    # _start_BuildParams, the .version strings and the SHA-1 round constants are defined
    # in src/game/arm9/crt0_build.c, sdk_version_*.c and sha1.c now
    fixed = {}

    plan = [("%08X" % ob["addr"], ob["size"], ob["sec"], files[ob["owner"]]["name"], ob["name"]) for ob in objs]
    dl = dict(region="arm9_main", arm9=True, nosinit=True, tail=["%08X" % v for v in (t0, s0, s0, end)], sinit=[],
              bss=["%08X" % bs, "%08X" % be], fixed=fixed,
              aliases=aliases, renames=renames, own=own_secs, stats=stats, blockers=blockers, plan=plan,
              shifted=[("%08X" % ob["addr"], ob["size"], files[ob["owner"]]["name"], [files[c]["name"] for c in ob["shifted"]])
                       for ob in objs if ob.get("shifted")])
    with open(os.path.join(out, "datalink.json"), "w", newline="\n") as fh:
        json.dump(dl, fh, indent=1)
    stats["secure_arrays"], stats["secure_bytes"] = secure_area(out, base, img, bsecs)
    return dict(out=out, stats=stats, blockers=blockers)


SECURE_END = 0x02004800          # end of the secure area (0x02004000..0x02004800)
MARKER = bytes.fromhex("FFDEFFE7") * 3     # decrypted "encryObj" marker, 0xE7FFDEFF x3


def secure_area(out, base, img, bsecs):
    """Write secure_area_XX.c: the bytes of the secure area that no C file defines.

    The area holds the SVC thunks (src/game/arm9/svc_*.c) and, between them, the filler of the
    SDK's precompiled libsyscall.a (random, incompressible, no source exists).  Each range
    between the thunk files becomes one const array in a file of its own (the compiler puts all
    the arrays of one file into one section, and these must sit apart); the first 12 bytes
    (0xE7FFDEFF x3) are their own array.  Each header names its array as a data symbol at the
    original address, so gamelink places the section there, as for any data section whose file
    names its address.  Returns (number of arrays, their bytes)."""
    for f in os.listdir(out):
        if re.fullmatch(r"secure_area(_[0-9A-F]+)?\.c", f):
            os.remove(os.path.join(out, f))
    used = sorted((x["addr"], x["addr"] + x["size"]) for x in bsecs
                  if re.fullmatch(r"t\d+(_\d+)?", x["name"]) and base <= x["addr"] < SECURE_END)
    gaps = []
    cur = base
    for a, b in used + [(SECURE_END, SECURE_END)]:
        if a > cur:
            # the 2 zero bytes after a Thumb file (next file 4-aligned): the linker pads them
            if not (a - cur == 2 and cur % 4 == 2 and a % 4 == 0 and img[cur - base:a - base] == bytes(2)):
                gaps.append((cur, a))
        cur = max(cur, b)
    parts = []
    for a, b in gaps:
        if a == base and img[:12] == MARKER:
            parts.append((a, a + 12, True))
            a += 12
        parts.append((a, b, False))
    for a, b, mark in parts:
        n = "secure_area_%X" % (a - base)
        text = ["/*",
                " * file:     %s.c" % n,
                " * function: none",
                " * address:  0x%08X" % a,
                " * region:   arm9",
                " * compiler: dsi/1.1p1",
                " * flags:    -O4,p",
                " * lang:     c99",
                " * isa:      arm",
                " * status:   GENERATED",
                " *",
                " * Filler of the SDK's precompiled libsyscall.a around the SVC thunks (no source",
                " * exists), generated from the user's dump by tools/arm9data.py.  Never committed.",
                " *",
                " * symbols:",
                " *   %s  0x%08X  data" % (n, a),
                " */",
                "",
                "typedef unsigned char u8;",
                "typedef unsigned int u32;",
                ""]
        if mark:
            text += ["/* the decrypted encryObj marker: 0xE7FFDEFF three times */",
                     "const u32 %s[3] = { 0xE7FFDEFF, 0xE7FFDEFF, 0xE7FFDEFF };" % n]
        else:
            vals = ["0x%02X" % c for c in img[a - base:b - base]]
            text.append("const u8 %s[%d] = {" % (n, b - a))
            text += ["    " + ", ".join(vals[k:k + 12]) + "," for k in range(0, len(vals), 12)]
            text.append("};")
        with open(os.path.join(out, n + ".c"), "w", encoding="latin1", newline="\n") as fh:
            fh.write("\n".join(text) + "\n")
    return len(parts), sum(b - a for a, b, _m in parts)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out")
    ap.add_argument("--relink", action="store_true", help="redo the plain gamelink link first")
    ap.add_argument("--data-start", default=hex(DATA_START), help="address of the first .data object")
    a = ap.parse_args()
    r = companions(a.out, a.relink, int(a.data_start, 16))
    print("arm9 -> %s %s, %d blockers" % (os.path.relpath(r["out"], ROOT), r["stats"], len(r["blockers"])))
    for b in r["blockers"][:20]:
        print("  blocker:", b)
    return 0


if __name__ == "__main__":
    sys.exit(main())
