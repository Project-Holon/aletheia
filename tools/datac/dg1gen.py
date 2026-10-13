#!/usr/bin/env python3
"""DG1 prototype: put an overlay's data tail into copies of its src/game files.

For overlay ovNNN:
  1. split the data tail (layout/data_objects.json range) into objects at every
     known start: registry starts, pool targets of the overlay code, header data
     names, the static-initialiser terminator ends;
  2. .rodata = tail start .. SINIT start, .data = SINIT end .. overlay end
     (the terminator word itself comes from the .lcf: WRITEW 0);
  3. give every object an owner file (code references, else pointer targets,
     else its neighbour) and check that owners are in link order per section;
  4. copy every top-level .c of src/game/ovNNN into build/dg1/ovNNN/src with
     includes made absolute; in the owner copy, fix the extern declaration
     (const for .rodata, no const for .data) and append the definition at the
     end of the file, after every function (mwccarm then emits it in definition
     order; data defined before the first function is sorted by size);
     initialisers come from build/gen/dg1/<region>_<addr>.inc, written here from
     the user's own extract;
  5. link with gamelink_dg.link_overlay(..., data_tail=...) and compare.

Nothing written here is committed: build/ is gitignored.
"""
import bisect
import json
import os
import re
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, ROOT + "/tools")
sys.path.insert(0, HERE)
import datareg  # noqa
import gamebuild  # noqa
import gamelink_dg as gl  # noqa
import match  # noqa

GEN = ROOT + "/build/gen/dg1"
OUTB = ROOT + "/build/dg1"

SCALAR = {
    "char": (1, True), "signed char": (1, True), "unsigned char": (1, False),
    "s8": (1, True), "u8": (1, False),
    "short": (2, True), "signed short": (2, True), "unsigned short": (2, False),
    "s16": (2, True), "u16": (2, False),
    "int": (4, True), "signed int": (4, True), "unsigned int": (4, False), "unsigned": (4, False),
    "long": (4, True), "unsigned long": (4, False), "s32": (4, True), "u32": (4, False),
    "fx32": (4, True), "fx16": (2, True),
}


def log(*a):
    print(*a, flush=True)


def region_info(rg):
    lay = datareg.load_layout()
    o = [x for x in lay["overlays"] if "ov%03d" % x["id"] == rg][0]
    base, img, lst = datareg.region_image(lay, rg)
    return o, base, img, lst


def file_list(rg):
    d = os.path.join(ROOT, "src/game", rg)
    res = []
    for f in sorted(os.listdir(d)):
        fp = os.path.join(d, f)
        if not f.endswith(".c") or f.startswith("_") or not os.path.isfile(fp):
            continue
        raw = open(fp, encoding="latin1").read()
        h, _st = gamebuild._settings(raw)
        res.append(dict(name=f, path=fp, raw=raw, addr=int(h["address"], 16),
                        hsyms=gl.header_symbols(raw)))
    res.sort(key=lambda x: x["addr"])
    return res


def func_names(rg):
    """address -> name of functions defined by the overlay's files, from the
    plain gamelink link of the unchanged files (build/gamelink/ovNNN/ov.elf)."""
    elf = os.path.join(ROOT, "build/dg1/base", rg, "ov.elf")
    _d, secs, syms = gl.read_elf(elf)
    res = {}
    for y in syms:
        if y["name"] and not y["name"].startswith("$") and y["shndx"] and (y["info"] & 15) == 2 \
                and "__" not in y["name"]:
            res.setdefault(y["value"] & ~1, y["name"])
    return res


def build(rg, verbose=True, mode="inline"):
    o, base, img, lst = region_info(rg)
    reg = json.load(open(ROOT + "/layout/data_objects.json"))["regions"][rg]
    t0 = int(reg["range"][0], 16)
    end = base + o["code_size"]
    s0, s1 = o["static_init_start"], o["static_init_end"]
    assert t0 <= s0 < s1 <= end, (hex(t0), hex(s0), hex(s1))
    # sinit holds only the NULL terminator: the linker writes it (WRITEW 0)
    assert img[s0 - base:s1 - base] == b"\0" * (s1 - s0) and s1 - s0 == 4, "sinit not a lone terminator"
    # .data starts at ALIGN(32) after the terminator (the overlay .lcf); the
    # zero bytes in between are linker padding, not an object
    ds = (s1 + 31) & ~31
    if img[s1 - base:ds - base] == bytes(ds - s1):
        s1 = ds
    files = file_list(rg)
    fstarts = [f["addr"] for f in files]
    fnames = func_names(rg)
    blockers = []

    # ---- object starts
    starts = set(int(x["addr"], 16) for x in reg["objects"])
    _ce, _data, _labels, words = datareg.scan_listing(lst)
    pool_refs = {}         # target -> set(file index)
    for site, v in words:
        if site < t0 and t0 <= v < end:
            fi = bisect.bisect_right(fstarts, site) - 1
            if fi >= 0:
                pool_refs.setdefault(v, set()).add(fi)
            starts.add(v)
    hdr_names = {}          # (file index, addr) -> [names]
    for fi, f in enumerate(files):
        for n, (a, k) in f["hsyms"].items():
            if k == "data" and t0 <= a < end:
                if re.fullmatch(r"[A-Za-z_]\w*", n):
                    hdr_names.setdefault(a, {}).setdefault(fi, []).append(n)
                starts.add(a)
        for m in re.finditer(r"\b([A-Za-z_]\w*_([0-9A-Fa-f]{8}))\b", f["raw"]):
            a = int(m.group(2), 16)
            if t0 <= a < end and not m.group(1).startswith("func_") and not m.group(1).startswith("sub_"):
                lstn = hdr_names.setdefault(a, {}).setdefault(fi, [])
                if m.group(1) not in lstn:
                    lstn.append(m.group(1))
                starts.add(a)
    # data the code files define themselves (string literals, statics): their
    # sections, placed by the plain link; they stay in the code file
    own_occ = []
    _d0, _bsecs0, _s0 = gl.read_elf(os.path.join(ROOT, "build/dg1/base", rg, "ov.elf"))
    for x in _bsecs0:
        if x["addr"] and t0 <= x["addr"] < end and x["size"] and x["name"].startswith(".d"):
            own_occ.append((x["addr"], x["addr"] + x["size"]))
            starts.add(x["addr"])
            starts.add(x["addr"] + x["size"])
    starts.add(t0)
    starts.add(s1)
    starts = sorted(a for a in starts if t0 <= a < end and not (s0 <= a < s1))
    if s0 not in starts:
        pass
    objs = []
    cuts = sorted(set(starts + [s0, s1, end]))
    for i, a in enumerate(cuts[:-1]):
        b = cuts[i + 1]
        if s0 <= a < s1 or any(x <= a < y for x, y in own_occ):
            continue
        objs.append(dict(addr=a, size=b - a, sec=".rodata" if a < s0 else ".data",
                         data=img[a - base:b - base], inner=[]))
    # an all-zero piece of .data cannot be a C object of its own (mwccarm puts
    # zero-initialised objects in .bss): it is the inside of a neighbour, so
    # merge it into the previous .data object (the first one into the next);
    # its names become linker aliases at an offset
    merged = []
    for ob in objs:
        if ob["sec"] == ".data" and ob["data"] == bytes(ob["size"]):
            if merged and merged[-1]["sec"] == ".data":
                p = merged[-1]
                p["inner"].append(ob["addr"])
                p["inner"].extend(ob["inner"])
                p["size"] += ob["size"]
                p["data"] += ob["data"]
                continue
        if merged and merged[-1]["sec"] == ".data" and merged[-1].get("lead_zero"):
            p = merged.pop()
            ob = dict(ob, addr=p["addr"], size=p["size"] + ob["size"], data=p["data"] + ob["data"],
                      inner=[ob["addr"]] + p["inner"] + ob["inner"])
        elif ob["sec"] == ".data" and ob["data"] == bytes(ob["size"]):
            ob["lead_zero"] = True
        merged.append(ob)
    objs = merged
    # .bss after the image: objects at code references, around the statics the
    # code files define themselves (their sections, from the plain link)
    bs, be = o["bss_start"], o["bss_end"]
    if be > bs:
        occ = []
        _d, bsecs, _s = gl.read_elf(os.path.join(ROOT, "build/dg1/base", rg, "ov.elf"))
        for x in bsecs:
            if x["addr"] and bs <= x["addr"] < be and x["size"] and x["name"].startswith(".d"):
                occ.append((x["addr"], x["addr"] + x["size"]))
        bstarts = {bs}
        for site, v in words:
            if site < t0 and bs <= v < be:
                fi = bisect.bisect_right(fstarts, site) - 1
                if fi >= 0:
                    pool_refs.setdefault(v, set()).add(fi)
                bstarts.add(v)
        for fi, f in enumerate(files):
            for n, (a, k) in f["hsyms"].items():
                if k == "data" and bs <= a < be:
                    hdr_names.setdefault(a, {}).setdefault(fi, []).append(n)
                    bstarts.add(a)
            for m in re.finditer(r"\b([A-Za-z_]\w*_([0-9A-Fa-f]{8}))\b", f["raw"]):
                a = int(m.group(2), 16)
                if bs <= a < be and not m.group(1).startswith(("func_", "sub_")):
                    lstn = hdr_names.setdefault(a, {}).setdefault(fi, [])
                    if m.group(1) not in lstn:
                        lstn.append(m.group(1))
                    bstarts.add(a)
        for a, b in occ:
            bstarts.add(a)
            bstarts.add(b)
        bc = sorted(x for x in bstarts | {be} if bs <= x <= be)
        for i, a in enumerate(bc[:-1]):
            if any(x <= a < y for x, y in occ):
                continue
            objs.append(dict(addr=a, size=bc[i + 1] - a, sec=".bss", data=None, inner=[]))

    # ---- pointer words
    objstart = [x["addr"] for x in objs]
    for ob in objs:
        ob["ptrs"] = {}
        if ob["data"] is None or ob["addr"] % 4 or ob["size"] % 4:
            continue
        for k in range(ob["size"] // 4):
            w = struct.unpack_from("<I", ob["data"], 4 * k)[0]
            if base <= w < t0 and (w & ~1) in fnames:
                ob["ptrs"][k] = ("func", fnames[w & ~1], 0)
            elif t0 <= w < end and not (s0 <= w < s1):
                j = bisect.bisect_right(objstart, w) - 1
                ob["ptrs"][k] = ("obj", j, w - objs[j]["addr"])
            elif 0x02000000 <= w < 0x02400000 and not (base <= w < end):
                ev = match.isa_evidence(w & ~1, "arm9")
                if ev and ((ev[0] == "thumb") == bool(w & 1)):
                    ob["ptrs"][k] = ("ext", "func_%08X" % (w & ~1), 0)

    # ---- owners
    for ob in objs:
        own = set()
        for a in range(ob["addr"], ob["addr"] + ob["size"]):
            own |= pool_refs.get(a, set())
            own |= set(hdr_names.get(a, {}).keys()) & set(
                fi for fi in hdr_names.get(a, {}) if a == ob["addr"])
        ob["direct"] = sorted(own)
        ptrown = set()
        for k, (kind, nm, _off) in ob["ptrs"].items():
            if kind == "func":
                a = [x for x, n in fnames.items() if n == nm][0]
                ptrown.add(bisect.bisect_right(fstarts, a) - 1)
        ob["ptrown"] = sorted(ptrown)
    for sec in (".rodata", ".data", ".bss"):
        lst_ = [ob for ob in objs if ob["sec"] == sec]
        cur = None
        for ob in lst_:
            cand = ob["direct"] or ob["ptrown"]
            if cand:
                ok = [c for c in cand if cur is None or c >= cur]
                if not ok:
                    blockers.append("%s %08X: owner %s before current file %d (link order)" % (sec, ob["addr"], cand, cur))
                    ob["owner"] = cur
                    continue
                if len(ok) > 1:
                    blockers.append("%s %08X: several owner files %s, took the first" % (sec, ob["addr"], ok))
                cur = ok[0]
            ob["owner"] = cur
        # leading objects with no owner: the first owner that follows
        nxt = None
        for ob in reversed(lst_):
            if ob["owner"] is None:
                ob["owner"] = nxt if nxt is not None else 0
            nxt = ob["owner"]

    # ---- names
    for i, ob in enumerate(objs):
        names = hdr_names.get(ob["addr"], {})
        ob["names"] = names           # fi -> [names]
        own_names = names.get(ob["owner"], [])
        ob["name"] = own_names[0] if own_names else "dg_%08X" % ob["addr"]
        ob["inner_names"] = [(n, a - ob["addr"]) for a in ob["inner"]
                             for nms in hdr_names.get(a, {}).values() for n in nms]
    # canonical name per address, used by every file
    canon = {ob["addr"]: ob["name"] for ob in objs}

    # ---- emit
    os.makedirs(GEN, exist_ok=True)
    srcdir = os.path.join(OUTB, rg, "src")
    if os.path.isdir(srcdir):
        for f in os.listdir(srcdir):
            os.remove(os.path.join(srcdir, f))
    os.makedirs(srcdir, exist_ok=True)
    import shutil as _sh
    _od = os.path.join(ROOT, "src/game", rg)
    for _f in os.listdir(_od):
        if not _f.endswith(".c") and os.path.isfile(os.path.join(_od, _f)):
            _t = open(os.path.join(_od, _f), encoding="latin1").read()
            _t = re.sub(r'#include\s+"((?:\.\./)+)', lambda m: '#include "%s' % os.path.normpath(
                os.path.join(_od, m.group(1))).replace("\\", "/") + "/", _t)
            open(os.path.join(srcdir, _f), "w", encoding="latin1", newline="").write(_t)
    stats = dict(objects=len(objs), typed=0, raw=0, alias=0, ptr_func=0, ptr_obj=0, ptr_ext=0,
                 renamed_refs=0, decl_fixed=0, decl_added=0, bytes=sum(x["size"] for x in objs))
    texts = {fi: f["raw"] for fi, f in enumerate(files)}
    tails = {fi: [] for fi in range(len(files))}
    externs_needed = {fi: set() for fi in range(len(files))}

    srcroot = ROOT + "/src/"
    for fi in texts:
        # absolute includes so the copy compiles from build/
        texts[fi] = re.sub(r'#include\s+"((?:\.\./)+)', lambda m: '#include "%s' % os.path.normpath(
            os.path.join(os.path.dirname(files[fi]["path"]), m.group(1))).replace("\\", "/") + "/", texts[fi])

    if mode == "companion":
        return emit_companion(rg, objs, files, texts, srcdir, stats, blockers,
                              dict(t0=t0, s0=s0, s1=s1, end=end, bss=(bs, be) if be > bs else None))

    # other names for the same address in any file -> canonical name (token rename)
    for ob in objs:
        for fi, nms in ob["names"].items():
            for n in nms:
                if n == ob["name"]:
                    continue
                if fi == ob["owner"]:
                    continue        # handled below (alias macro in the owner)
                texts[fi], c = re.subn(r"\b%s\b" % re.escape(n), ob["name"], texts[fi])
                stats["renamed_refs"] += c
                # after renaming, two extern lines may declare the canonical
                # name with different types: keep the first
                seen = False
                lines = texts[fi].split("\n")
                for li, l in enumerate(lines):
                    if re.match(r"\s*extern\b[^;()]*\b%s\b" % re.escape(ob["name"]), l):
                        if seen:
                            lines[li] = "/* dg1: duplicate */"
                        seen = True
                texts[fi] = "\n".join(lines)

    def inc_path(ob, suffix=""):
        return "%s/%s_%08X%s.inc" % (GEN, rg, ob["addr"], suffix)

    def write_inc(ob, vals, suffix=""):
        p = inc_path(ob, suffix)
        with open(p, "w", newline="\n") as fh:
            for k in range(0, len(vals), 16):
                fh.write("    " + ", ".join(vals[k:k + 16]) + ",\n")
        return p

    for i, ob in enumerate(objs):
        fi = ob["owner"]
        name = ob["name"]
        const = ob["sec"] == ".rodata"
        cq = "const " if const else ""
        text = texts[fi]
        # find the extern declaration in the owner file
        decl_re = re.compile(r"^[ \t]*extern\s+(?P<pre>[^;()=]*?)\b%s\s*(?P<arr>\[[^\]]*\])?\s*;[ \t]*$" % re.escape(name), re.M)
        m = decl_re.search(text)
        pre = arr = None
        if m:
            pre = m.group("pre").strip()
            arr = m.group("arr")
        base_t = None
        if pre is not None:
            bt = re.sub(r"\b(const|volatile|static)\b", "", pre).strip()
            bt = re.sub(r"\s+", " ", bt)
            if arr is not None and bt in SCALAR and "*" not in bt:
                base_t = bt
        # function pointer array: extern R (*[const] NAME[])(args);
        fp = re.compile(r"^[ \t]*extern\s+(?P<ret>[^;()=]*?)\(\s*\*\s*(?P<c>const\s+)?%s\s*\[[^\]]*\]\s*\)\s*(?P<args>\([^;]*\))\s*;[ \t]*$" % re.escape(name), re.M).search(text)
        if fp and ob["size"] % 4 == 0 and ob["addr"] % 4 == 0:
            ret, args = fp.group("ret").strip(), fp.group("args")
            et = "%s (*)%s" % (ret, args)
            vals = []
            for k in range(ob["size"] // 4):
                if k not in ob["ptrs"]:
                    w = struct.unpack_from("<I", ob["data"], 4 * k)[0]
                    if w:
                        stats["ptr_numeric"] = stats.get("ptr_numeric", 0) + 1
                        blockers.append("%s[%d]: 0x%08X has no symbol (code outside every file)" % (name, k, w))
                    vals.append("(%s)0x%X" % (et, w) if w else "0")
                    continue
                kind, nm, off = ob["ptrs"][k]
                if kind == "obj":
                    nm = objs[nm]["name"]
                if not re.search(r"\b%s\b" % re.escape(nm), text):
                    externs_needed[fi].add("extern char %s[];" % nm)
                stats["ptr_func"] += 1
                vals.append("(%s)%s" % (et, nm))
            write_inc(ob, vals)
            cc = "const " if const else ""
            newdecl = "extern %s (*%s%s[])%s;" % (ret, cc, name, args)
            if newdecl != fp.group(0).strip():
                stats["decl_fixed"] += 1
            text = text[:fp.start()] + newdecl + text[fp.end():]
            tails[fi].append("%s (*%s%s[%d])%s = {\n#include \"%s\"\n};" % (
                ret, cc, name, ob["size"] // 4, args, inc_path(ob)))
            stats["typed"] += 1
            stats.setdefault("fptr_tables", 0)
            stats["fptr_tables"] += 1
            texts[fi] = text
            continue
        if m is None and re.search(r"^[ \t]*extern\b[^;]*\b%s\b" % re.escape(name), text, re.M):
            blockers.append("%s: declaration form not handled" % name)
        # values
        if ob["ptrs"]:
            # word holder with pointer fields
            fields, vals = [], []
            for k in range(ob["size"] // 4):
                if k in ob["ptrs"]:
                    kind, nm, off = ob["ptrs"][k]
                    if kind == "func":
                        stats["ptr_func"] += 1
                        if not re.search(r"\b%s\b" % re.escape(nm), text):
                            externs_needed[fi].add("extern char %s[];" % nm)
                        vals.append("(void *)%s" % nm)
                    elif kind == "ext":
                        stats["ptr_ext"] += 1
                        if not re.search(r"\b%s\b" % re.escape(nm), text):
                            externs_needed[fi].add("extern char %s[];" % nm)
                        vals.append("(void *)%s" % nm)
                    else:
                        stats["ptr_obj"] += 1
                        tn = objs[nm]["name"]
                        if tn != name and objs[nm]["owner"] != fi and not re.search(r"\b%s\b" % re.escape(tn), text):
                            externs_needed[fi].add("extern char %s[];" % tn)
                        vals.append("(void *)((char *)&%s + %d)" % (tn, off) if off else "(void *)&%s" % tn)
                    fields.append("void *w%d;" % k)
                else:
                    fields.append("unsigned long w%d;" % k)
                    vals.append("0x%08X" % struct.unpack_from("<I", ob["data"], 4 * k)[0])
            raw_t = "struct %s__dg" % name
            raw_body = "struct %s__dg { %s }" % (name, " ".join(fields))
            rawname = name + "__dg" if pre is not None else name
            write_inc(ob, vals)
            decl_raw = "%s;\nextern %s%s %s;" % (raw_body, cq, raw_t, rawname)
            defn = "%s%s %s = {\n#include \"%s\"\n};" % (cq, raw_t, rawname, inc_path(ob))
            stats["raw"] += 1
            if pre is not None:
                stats["alias"] += 1
                mac = ("((%s%s *)&%s)" % (cq if "const" not in pre else "", pre, rawname)) if arr is not None else \
                      ("(*(%s%s *)&%s)" % (cq if "const" not in pre else "", pre, rawname))
                text = text[:m.start()] + decl_raw + "\n#define %s %s" % (name, mac) + text[m.end():]
            else:
                externs_needed[fi].add(decl_raw)
            tails[fi].append(defn)
        elif base_t is not None and ob["size"] % SCALAR[base_t][0] == 0 and ob["addr"] % SCALAR[base_t][0] == 0:
            sz, sg = SCALAR[base_t]
            fmt = {1: "b", 2: "h", 4: "i"}[sz]
            fmt = fmt if sg else fmt.upper()
            vals = [str(v) if sg else "0x%X" % v for v in struct.unpack("<%d%s" % (ob["size"] // sz, fmt), ob["data"])]
            write_inc(ob, vals)
            n = ob["size"] // sz
            newdecl = "extern %s%s %s[];" % (cq, base_t, name)
            if newdecl != m.group(0).strip():
                stats["decl_fixed"] += 1
            text = text[:m.start()] + newdecl + text[m.end():]
            tails[fi].append("%s%s %s[%d] = {\n#include \"%s\"\n};" % (cq, base_t, name, n, inc_path(ob)))
            stats["typed"] += 1
        else:
            # byte holder; existing declaration of another type -> alias macro
            vals = ["0x%02X" % c for c in ob["data"]]
            write_inc(ob, vals)
            rawname = name + "__dg" if pre is not None else name
            decl_raw = "extern %sunsigned char %s[];" % (cq, rawname)
            if pre is not None:
                stats["alias"] += 1
                pq = pre if ("const" in pre or not const) else "const " + pre
                mac = ("((%s *)%s)" % (pq, rawname)) if arr is not None else ("(*(%s *)%s)" % (pq, rawname))
                text = text[:m.start()] + decl_raw + "\n#define %s %s" % (name, mac) + text[m.end():]
            else:
                stats["decl_added"] += 1
                externs_needed[fi].add(decl_raw)
            tails[fi].append("%sunsigned char %s[%d] = {\n#include \"%s\"\n};" % (cq, rawname, ob["size"], inc_path(ob)))
            stats["raw"] += 1
        # second names for the same address in the owner file: alias macros
        for n in ob["names"].get(fi, []):
            if n == name:
                continue
            m2 = re.compile(r"^[ \t]*extern\s+(?P<pre>[^;()=]*?)\b%s\s*(?P<arr>\[[^\]]*\])?\s*;[ \t]*$" % re.escape(n), re.M).search(text)
            if not m2:
                blockers.append("%s: second name %s has no extern line" % (name, n))
                continue
            p2 = m2.group("pre").strip()
            tgt = name + "__dg" if (name + "__dg") in text else name
            mac = ("((%s *)%s)" % (p2, tgt)) if m2.group("arr") is not None else ("(*(%s *)%s)" % (p2, tgt))
            text = text[:m2.start()] + "#define %s %s" % (n, mac) + text[m2.end():]
            blockers.append("%s: second name %s in the same file (alias macro)" % (name, n))
        texts[fi] = text

    for fi, f in enumerate(files):
        t = texts[fi]
        if externs_needed[fi] or tails[fi]:
            t += "\n\n/* ---- dg1: data of this file, initialisers generated from the ROM ---- */\n"
            t += "\n".join(sorted(externs_needed[fi])) + "\n"
            t += "\n\n".join(tails[fi]) + "\n"
        with open(os.path.join(srcdir, f["name"]), "w", encoding="latin1", newline="\n") as fh:
            fh.write(t)
    plan = [(hex(ob["addr"]), ob["size"], ob["sec"], files[ob["owner"]]["name"], ob["name"],
             "ptr" if ob["ptrs"] else "") for ob in objs]
    return dict(srcdir=srcdir, t0=t0, s0=s0, s1=s1, end=end, stats=stats, blockers=blockers, plan=plan)


FP_RE = r"^[ \t]*extern\s+(?P<ret>[^;()=]*?)\(\s*\*\s*(?P<c>const\s+)?%s\s*\[[^\]]*\]\s*\)\s*(?P<args>\([^;]*\))\s*;[ \t]*$"
DECL_RE = r"^[ \t]*extern\s+(?P<pre>[^;()=]*?)\b%s\s*(?P<arr>\[[^\]]*\])?\s*;[ \t]*$"
PLAIN = ("char", "signed char", "unsigned char", "short", "unsigned short", "int", "unsigned int",
         "unsigned", "long", "unsigned long", "signed short", "signed int")


def emit_companion(rg, objs, files, texts, srcdir, stats, blockers, rng):
    """Mode 2: the code files stay as they are (includes made absolute); every
    file that owns data gets a companion TU <stem>.zdata.c with the same header
    settings, holding the definitions in layout order (after a dummy function,
    so mwccarm keeps definition order).  Types: function pointer tables and
    plain scalar arrays follow the code file's declaration; anything else is a
    byte array or a word struct with pointer fields.  Every other name a file
    uses for an object address becomes a linker alias (name = canon;)."""
    os.makedirs(GEN, exist_ok=True)
    aliases = {}
    by_owner = {}
    for i, ob in enumerate(objs):
        by_owner.setdefault(ob["owner"], []).append(ob)
        for fi, nms in ob["names"].items():
            for n in nms:
                if n != ob["name"]:
                    if n in aliases and aliases[n] != ob["name"]:
                        blockers.append("name %s means two objects (%s, %s)" % (n, aliases[n], ob["name"]))
                    aliases[n] = ob["name"]
        for n, off in ob["inner_names"]:
            aliases[n] = "%s + %d" % (ob["name"], off)
    stats["aliases"] = len(aliases)
    stats["companions"] = len(by_owner)

    def inc(ob):
        return "%s/%s_%08X.inc" % (GEN, rg, ob["addr"])

    def write_inc(ob, vals):
        with open(inc(ob), "w", newline="\n") as fh:
            for k in range(0, len(vals), 16):
                fh.write("    " + ", ".join(vals[k:k + 16]) + ",\n")

    for fi, f in enumerate(files):
        with open(os.path.join(srcdir, f["name"]), "w", encoding="latin1", newline="\n") as fh:
            fh.write(texts[fi])
    for fi, lst in by_owner.items():
        f = files[fi]
        text = texts[fi]
        hdr = re.match(r"\s*/\*.*?\*/", f["raw"], re.S).group(0)
        fwd, defs, ext, bdefs = [], [], set(), []
        own_names = set(ob["name"] for ob in lst)
        for ob in lst:
            name = ob["name"]
            const = ob["sec"] == ".rodata"
            cq = "const " if const else ""
            if ob["sec"] == ".bss":
                fwd.append("extern unsigned char %s[%d];" % (name, ob["size"]))
                bdefs.append("unsigned char %s[%d];" % (name, ob["size"]))
                stats["bss"] = stats.get("bss", 0) + 1
                continue
            m = re.compile(DECL_RE % re.escape(name), re.M).search(text)
            fp = re.compile(FP_RE % re.escape(name), re.M).search(text)
            base_t = None
            if m and m.group("arr") is not None:
                bt = re.sub(r"\s+", " ", re.sub(r"\b(const|volatile)\b", "", m.group("pre")).strip())
                if bt in SCALAR:
                    base_t = bt

            def ref(k):
                kind, nm, off = ob["ptrs"][k]
                if kind == "obj":
                    nm = objs[nm]["name"]
                    stats["ptr_obj"] = stats.get("ptr_obj", 0) + 1
                    if nm not in own_names:
                        ext.add("extern char %s[];" % nm)
                    return "((char *)&%s + %d)" % (nm, off) if off else "&%s" % nm
                ext.add("extern char %s[];" % nm)
                stats["ptr_" + kind] = stats.get("ptr_" + kind, 0) + 1
                return nm

            words = [struct.unpack_from("<I", ob["data"], 4 * k)[0] for k in range(ob["size"] // 4)] \
                if ob["addr"] % 4 == 0 and ob["size"] % 4 == 0 else None
            if fp and words is not None:
                # element type: keep only plain C in the signature (the companion
                # does not include the game headers)
                et = "void (*)(void)"
                vals = []
                for k, w in enumerate(words):
                    if k in ob["ptrs"]:
                        vals.append("(%s)%s" % (et, ref(k)))
                    elif w:
                        stats["ptr_numeric"] = stats.get("ptr_numeric", 0) + 1
                        blockers.append("%s[%d]: 0x%08X has no symbol (code outside every file)" % (name, k, w))
                        vals.append("(%s)0x%X" % (et, w))
                    else:
                        vals.append("0")
                write_inc(ob, vals)
                decl = "void (*%s%s[%d])(void)" % (cq, name, len(words))
                fwd.append("extern %s;" % decl)
                defs.append("%s = {\n#include \"%s\"\n};" % (decl, inc(ob)))
                stats["typed"] += 1
                stats["fptr_tables"] = stats.get("fptr_tables", 0) + 1
            elif ob["ptrs"] and words is not None:
                fields, vals = [], []
                for k, w in enumerate(words):
                    if k in ob["ptrs"]:
                        fields.append("void *w%d;" % k)
                        vals.append("(void *)%s" % ref(k))
                    else:
                        fields.append("unsigned long w%d;" % k)
                        vals.append("0x%08X" % w)
                write_inc(ob, vals)
                fwd.append("struct %s_t { %s };" % (name, " ".join(fields)))
                fwd.append("extern %sstruct %s_t %s;" % (cq, name, name))
                defs.append("%sstruct %s_t %s = {\n#include \"%s\"\n};" % (cq, name, name, inc(ob)))
                stats["raw"] += 1
                stats["ptr_structs"] = stats.get("ptr_structs", 0) + 1
            elif base_t and ob["size"] % SCALAR[base_t][0] == 0 and ob["addr"] % SCALAR[base_t][0] == 0:
                sz, sg = SCALAR[base_t]
                fmt = {1: "b", 2: "h", 4: "i"}[sz]
                fmt = fmt if sg else fmt.upper()
                vals = [str(v) if sg else "0x%X" % v for v in struct.unpack("<%d%s" % (ob["size"] // sz, fmt), ob["data"])]
                write_inc(ob, vals)
                bt2 = base_t if base_t in PLAIN else (
                    {1: "signed char", 2: "short", 4: "long"}[sz] if sg else
                    {1: "unsigned char", 2: "unsigned short", 4: "unsigned long"}[sz])
                fwd.append("extern %s%s %s[%d];" % (cq, bt2, name, ob["size"] // sz))
                defs.append("%s%s %s[%d] = {\n#include \"%s\"\n};" % (cq, bt2, name, ob["size"] // sz, inc(ob)))
                stats["typed"] += 1
            else:
                if ob["data"] == bytes(len(ob["data"])) and not const:
                    blockers.append("%s: all-zero object in .data (mwccarm would put it in .bss)" % name)
                write_inc(ob, ["0x%02X" % c for c in ob["data"]])
                fwd.append("extern %sunsigned char %s[%d];" % (cq, name, ob["size"]))
                defs.append("%sunsigned char %s[%d] = {\n#include \"%s\"\n};" % (cq, name, ob["size"], inc(ob)))
                stats["raw"] += 1
        stem = f["name"][:-2]
        body = hdr + "\n/* dg1 companion: data of %s, initialisers generated from the ROM */\n\n" % f["name"]
        body += "\n".join(sorted(ext - set("extern char %s[];" % n for n in own_names))) + "\n"
        body += "\n".join(fwd) + "\n\nvoid %s__zdata_anchor(void) { }\n\n" % stem
        body += "\n\n".join(defs) + "\n"
        if bdefs:
            body += "\n/* .bss: mwccarm emits uninitialised definitions in reverse order */\n"
            body += "\n".join(reversed(bdefs)) + "\n"
        with open(os.path.join(srcdir, stem + ".zdata.c"), "w", encoding="latin1", newline="\n") as fh:
            fh.write(body)
    plan = [(hex(ob["addr"]), ob["size"], ob["sec"], files[ob["owner"]]["name"], ob["name"],
             "ptr" if ob["ptrs"] else "") for ob in objs]
    return dict(srcdir=srcdir, stats=stats, blockers=blockers, plan=plan, aliases=aliases, **rng)



def run(rg, verbose=True, mode="inline"):
    r = build(rg, mode=mode)
    if verbose:
        for p in r["plan"]:
            log("  ", *p)
        log(rg, "stats", r["stats"])
        for b in r["blockers"]:
            log("  blocker:", b)
    oid = int(rg[2:])
    res = gl.link_overlay(oid, src_dir=r["srcdir"], data_tail=(r["t0"], r["s0"], r["s1"], r["end"]),
                          out=os.path.join(OUTB, "link"), data_aliases=r.get("aliases"), bss=r.get("bss"))
    log(rg, "PASS" if res["ok"] else "FAIL", {k: v for k, v in res.items() if k not in ("units",)})
    return r, res


if __name__ == "__main__":
    mode = "inline"
    for a in sys.argv[1:]:
        if a.startswith("--mode="):
            mode = a[7:]
            continue
        run(a, mode=mode)
