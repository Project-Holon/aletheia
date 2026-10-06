#!/usr/bin/env python3
"""tuboundary.py -- propose translation unit (TU) boundaries from concrete evidence.

Every game function is matched as its own file, but the original program was
built from source files, each compiled as one TU whose functions are laid out
contiguously by the linker. This tool proposes where those TUs start and end,
for the ARM9 static module, its ITCM autoload, the DSi twl block and every
overlay, and it states the evidence behind every boundary and grouping.
Nothing is guessed: a cut between two neighbouring functions is only called a
boundary, or a same-TU link, when a named evidence class says so.

A "cut" k is the position between function k-1 and function k of one region
(functions sorted by address). Each evidence class emits, per cut, either
boundary evidence (B) or glue evidence (G, "both sides are one TU").

Evidence classes (each is one function, testable alone)
-------------------------------------------------------
 1 anchors   __FILE__ strings (layout/file_anchors.txt). Same name on two
             anchored functions glues every cut between them; a name change
             between two adjacent known functions is a boundary.
 2 data      pooled data references. 2a: a data object (or string) referenced
             by 2..K functions within a short span glues that span. 2b: strings
             are laid out in TU order, so a string address that goes backwards
             against function order inside a local window glues the cut. 2c: a
             "data jump": the nearest data referenced before and after the cut
             skips over objects that only far away functions use.
 3 settings  compiler version, flags, -lang (3a, from layout/matched shards and
             the header of the unit shard) or ISA arm/thumb (3b, from the
             listing, all functions) changes between neighbours.
 4 padding   gap between the end of a function (code and literal pool) and the
             next function start, larger than the in-TU norm. The norm is
             measured on cuts proven in-TU by class 1.
 5 library   SDK / NitroSystem / MSL functions with a known vendor object
             (layout/sdk_class.json, layout/symbols_sdk.txt). Same object glues,
             a different object or a vendor/game switch is a boundary.
 6 callers   static call locality: a function whose every caller (and function
             pointer reference) sits in a small neighbourhood, and never anywhere
             else in the image, is glued to that neighbourhood.

Evidence is calibrated against class 1 (anchors) in calibration.md: precision
and recall of each class on cuts whose truth the anchors fix. A boundary class
is allowed to split TUs in the final proposal only if its false positive rate on
cuts proven in-TU is at most MAX_FPR and it hits at least MIN_HITS proven
boundaries or boundary-bearing anchor gaps and flags at least MIN_ENRICH times
more often inside such gaps than on proven in-TU cuts; a glue class needs precision
MIN_PRECISION on MIN_LABELED labeled cuts. Otherwise it is listed as unverified
and does not take part.

Inputs (read only): asm/arm9/*.s, asm/twl/twl.s, asm/overlays/ovNNN.s (ov230
uses asm/ov230d/ov230d.s), layout/file_anchors.txt, layout/data_objects.json,
layout/sdk_class.json, layout/symbols_sdk.txt, layout/matched/*/*.json.

Outputs (default dir given by --out): tu_proposal.tsv, boundaries.tsv,
calibration.md, summary.md, tu_fragments.tsv (glued groups inside each TU run)
and listings.pickle (parse cache, keyed on listing mtime and size). Addresses, names and counts only; no game bytes.

Usage
-----
    python tools/tuboundary.py --out DIR
    python tools/tuboundary.py --out DIR --region ov010   (one region)
"""
import argparse
import bisect
import collections
import glob
import json
import os
import pickle
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

MIN_PRECISION = 0.90
MIN_LABELED = 20
MAX_FPR = 0.03      # boundary classes: flagged share of cuts proven in-TU
MIN_ENRICH = 1.5    # boundary classes: flag rate inside YES gaps over the rate on NO cuts
MIN_HITS = 1        # boundary classes: hits on proven boundaries or on boundary-bearing gaps
DATA_K = 4          # a datum referenced by more than this many functions is global
DATA_SPAN = 24      # max function-index span of a 2a link
MONO_WIN = 6        # window (functions with string refs) for 2b
CALLER_DIST = 8     # class 6 neighbourhood, in function indices

INSN = re.compile(r"/\*\s*([0-9A-Fa-f]{8})\s+((?:[0-9A-Fa-f]{2} )*[0-9A-Fa-f]{2})(?:\s\s|\s*\*/)")
WORD = re.compile(r"^\s*\.word\s+(0x[0-9A-Fa-f]+)\s+/\*\s*([0-9A-Fa-f]{8})(?:\s+->\s+(\S+))?")
LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_.]*):\s*$")
TYPEFN = re.compile(r"^\s*\.type\s+(\S+),\s*%function")
BRANCH = re.compile(r"^\s+(?:bl|blx|b|b[a-z]{2})(?:\.[nw])?\s+([A-Za-z_][A-Za-z0-9_]*)\b")
HDR_RANGE = re.compile(r"address range\s+0x([0-9A-Fa-f]+)\.\.0x([0-9A-Fa-f]+)")
HDR_BSS = re.compile(r"bss\s+0x([0-9A-Fa-f]+)\.\.0x([0-9A-Fa-f]+)")
HDR_FUNCS = re.compile(r"functions\s+(\d+)")
FUNADDR = re.compile(r"(?:func|sub)_([0-9A-Fa-f]{8})$")


def scratch_default():
    return os.path.join(os.environ.get("TEMP", "."), "tu")


# ---------------------------------------------------------------- listings

def listing_files():
    """region -> (listing path).  All code regions of the image."""
    out = {}
    out["arm9"] = os.path.join(ROOT, "asm/arm9/main.s")
    out["arm9_autoload0_ITCM"] = os.path.join(ROOT, "asm/arm9/itcm.s")
    out["arm9_autoload1_main_twl"] = os.path.join(ROOT, "asm/arm9/autoload1_main_twl.s")
    out["arm9_autoload2_main_twl"] = os.path.join(ROOT, "asm/arm9/autoload2_main_twl.s")
    out["arm9_vram_lcdc"] = os.path.join(ROOT, "asm/arm9/vram_lcdc.s")
    out["twl"] = os.path.join(ROOT, "asm/twl/twl.s")
    for p in sorted(glob.glob(os.path.join(ROOT, "asm/overlays/ov[0-9][0-9][0-9].s"))):
        reg = os.path.basename(p)[:-2]
        out[reg] = p
    # overlay 230 carries encrypted ranges in the plain listing: use the decrypted view
    out["ov230"] = os.path.join(ROOT, "asm/ov230d/ov230d.s")
    return out


def parse_listing(path):
    """Parse one listing. Returns dict with header facts and a function list.

    Each function: name, addr, isa, code_end, pool_end, pools [(addr, value,
    target-name-or-None)], calls [names], insn count.  Veneers end the previous
    function's extent but are not functions.
    """
    res = {"range": None, "bss": None, "declared": None, "funcs": [], "veneers": []}
    cur = None
    pending_thumb = False
    in_pool = False
    last_label = None
    with open(path, "r", errors="replace") as fh:
        for ln in fh:
            if ln.startswith(" *"):
                m = HDR_RANGE.search(ln)
                if m and res["range"] is None:
                    res["range"] = (int(m.group(1), 16), int(m.group(2), 16))
                m = HDR_BSS.search(ln)
                if m:
                    res["bss"] = (int(m.group(1), 16), int(m.group(2), 16))
                m = HDR_FUNCS.search(ln)
                if m and res["declared"] is None and "functions" in ln[:20]:
                    res["declared"] = int(m.group(1))
                continue
            s = ln.rstrip("\n")
            if not s:
                continue
            st = s.lstrip()
            if st.startswith(".thumb_func"):
                pending_thumb = True
                continue
            if st.startswith(".org") or st.startswith(".global") or st.startswith(".byte") \
                    or st.startswith(".syntax") or st.startswith(".section") or st.startswith(".thumb") \
                    or st.startswith(".arm") or st.startswith(".end") or st.startswith(".align"):
                if st.startswith(".org"):
                    in_pool = False if in_pool and False else in_pool
                continue
            m = TYPEFN.match(s)
            if m:
                cur = {"name": m.group(1), "addr": None, "isa": "thumb" if pending_thumb else "arm",
                       "code_end": None, "pool_end": None, "pools": [], "calls": [],
                       "insns": 0, "veneer": False}
                res["funcs"].append(cur)
                pending_thumb = False
                in_pool = False
                continue
            m = LABEL.match(s)
            if m:
                name = m.group(1)
                last_label = name
                if name.startswith("veneer_"):
                    v = {"name": name, "addr": int(name[7:], 16)}
                    res["veneers"].append(v)
                    cur = None
                    in_pool = False
                    continue
                in_pool = name.startswith("pool_")
                continue
            m = INSN.search(s)
            if m and cur is not None and not st.startswith(".word"):
                a = int(m.group(1), 16)
                n = len(m.group(2).split())
                if cur["addr"] is None:
                    cur["addr"] = a
                cur["code_end"] = a + n
                cur["insns"] += 1
                b = BRANCH.match(s)
                if b:
                    cur["calls"].append(b.group(1))
                in_pool = False
                continue
            m = WORD.match(s)
            if m and cur is not None:
                a = int(m.group(2), 16)
                if cur["addr"] is None:
                    cur["addr"] = a
                if in_pool or last_label is not None and last_label.startswith("pool_"):
                    cur["pools"].append((a, int(m.group(1), 16), m.group(3)))
                    cur["pool_end"] = a + 4
                continue
    # drop functions never given an address (should not happen)
    res["funcs"] = [f for f in res["funcs"] if f["addr"] is not None]
    res["funcs"].sort(key=lambda f: f["addr"])
    return res


def load_listings(cache_path, only=None):
    files = listing_files()
    stamp = {r: (os.path.getmtime(p), os.path.getsize(p)) for r, p in files.items() if os.path.exists(p)}
    cache = {}
    if cache_path and os.path.exists(cache_path) and not only:
        try:
            with open(cache_path, "rb") as fh:
                c = pickle.load(fh)
            if c.get("stamp") == stamp:
                return c["data"], files
        except Exception:
            pass
    data = {}
    for r, p in files.items():
        if only and r != only:
            continue
        if not os.path.exists(p):
            continue
        data[r] = parse_listing(p)
    if cache_path and not only:
        with open(cache_path, "wb") as fh:
            pickle.dump({"stamp": stamp, "data": data}, fh)
    return data, files


# ---------------------------------------------------------------- inputs

def load_anchors():
    """region -> {function addr: set(names)}"""
    out = collections.defaultdict(lambda: collections.defaultdict(set))
    with open(os.path.join(ROOT, "layout/file_anchors.txt")) as fh:
        for ln in fh:
            if ln.startswith("#") or not ln.strip():
                continue
            p = ln.split()
            if len(p) < 5:
                continue
            reg = p[2]
            if reg == "arm9_main":
                reg = "arm9"
            elif reg.startswith("overlay_"):
                reg = "ov" + reg[8:]
            out[reg][int(p[1], 16)].add(p[4])
    return out


def load_data_objects():
    d = json.load(open(os.path.join(ROOT, "layout/data_objects.json")))
    out = {}
    for reg, v in d["regions"].items():
        objs = sorted((int(o["addr"], 16), o["size"], o["kind"]) for o in v["objects"])
        out[reg] = {"range": (int(v["range"][0], 16), int(v["range"][1], 16)), "objs": objs,
                    "starts": [o[0] for o in objs]}
    return out


def load_sdk():
    """region -> {addr: (lib, member)} from sdk_class.json and symbols_sdk.txt"""
    out = collections.defaultdict(dict)
    d = json.load(open(os.path.join(ROOT, "layout/sdk_class.json")))
    for reg, v in d["regions"].items():
        for a, e in v.items():
            out[reg][int(a, 16)] = (e.get("lib", "?"), e.get("member", "?"))
    with open(os.path.join(ROOT, "layout/symbols_sdk.txt")) as fh:
        for ln in fh:
            if ln.startswith("#") or not ln.strip():
                continue
            p = ln.split()
            if len(p) < 4:
                continue
            if p[2] == "game":
                continue    # placeholder: the function is game code, not a vendor object
            m = re.match(r"(.*)\((.*)\)$", p[2])
            lib, mem = (m.group(1), m.group(2)) if m else (p[2], p[2])
            lib = os.path.basename(lib)
            a = int(p[0], 16)
            out[p[3]].setdefault(a, (lib, mem))
    return out


def load_settings():
    """region -> {addr: (settings_tuple, kind, source)} from the matched shards.

    settings = (compiler, lang, flags with the isa switch removed).  A unit
    shard row (game_unit / sdk_unit) covers every function it lists.
    """
    out = collections.defaultdict(dict)
    for f in sorted(glob.glob(os.path.join(ROOT, "layout/matched/*/*.json"))):
        try:
            d = json.load(open(f))
        except Exception:
            continue
        for fn in d.get("functions", []):
            reg = fn.get("region")
            flags = re.sub(r"\s-(thumb|arm)\b", "", fn.get("flags", ""))
            key = (re.sub(r"^(dsi/)+", "dsi/", fn.get("compiler") or ""), fn.get("lang"), " ".join(flags.split()))
            addrs = []
            try:
                addrs.append(int(fn["address"], 16))
            except Exception:
                continue
            for nm in fn.get("functions", []) or []:
                m = FUNADDR.search(nm)
                if m:
                    addrs.append(int(m.group(1), 16))
            for a in addrs:
                prev = out[reg].get(a)
                if prev is None or (prev[1] == "sdk_calibration" and fn.get("kind") != "sdk_calibration"):
                    out[reg][a] = (key, fn.get("kind"), fn.get("source"))
    return out


# ---------------------------------------------------------------- evidence
# Evidence item: dict(cls, typ 'B'|'G', lo, hi, strength, detail).  lo..hi is the
# inclusive range of cuts the item speaks about; located when lo == hi.

def ev(cls, typ, lo, hi, strength, detail):
    return {"cls": cls, "typ": typ, "lo": lo, "hi": hi, "strength": strength, "detail": detail}


def ev_anchors(funcs, anchors):
    """Class 1.  Returns (items, names) where names[i] is the inherited name or None."""
    n = len(funcs)
    own = [None] * n
    conflicts = []
    for i, f in enumerate(funcs):
        s = anchors.get(f["addr"])
        if s:
            if len(s) > 1:
                conflicts.append((f["addr"], sorted(s)))
            own[i] = sorted(s)[0]
    names = [None] * n
    items = []
    last = None
    for i in range(n):
        if own[i] is None:
            continue
        if last is not None:
            j = last
            if own[j] == own[i]:
                for k in range(j + 1, i + 1):
                    names[k] = own[i]
                names[j] = own[i]
                items.append(ev(1, "G", j + 1, i, "proven", "same __FILE__ %s on %08X and %08X" % (
                    own[i], funcs[j]["addr"], funcs[i]["addr"])))
            else:
                items.append(ev(1, "B", j + 1, i, "proven", "__FILE__ %s on %08X then %s on %08X" % (
                    own[j], funcs[j]["addr"], own[i], funcs[i]["addr"])))
        if names[i] is None:
            names[i] = own[i]
        last = i
    return items, names, conflicts


def data_keys(region, rec, dobj, fn_set):
    """Per function: set of data keys (object start, or exact address) referenced via pool words."""
    lo, hi = region_data_range(rec, dobj)
    if lo is None:
        return [set() for _ in rec["funcs"]], None
    starts = dobj["starts"] if dobj else []
    objs = dobj["objs"] if dobj else []
    out = []
    for f in rec["funcs"]:
        ks = set()
        for (_a, v, tgt) in f["pools"]:
            if tgt is not None or v in fn_set or (v & ~1) in fn_set:
                continue
            if lo <= v < hi:
                i = bisect.bisect_right(starts, v) - 1
                if i >= 0 and objs[i][0] <= v < objs[i][0] + objs[i][1]:
                    ks.add(objs[i][0])
                else:
                    ks.add(v)
        out.append(ks)
    return out, (lo, hi)


def region_data_range(rec, dobj):
    if dobj is None:
        return None, None
    lo = dobj["range"][0]
    hi = dobj["range"][1]
    if rec["bss"]:
        hi = max(hi, rec["bss"][1])
    return lo, hi


def ev_data(funcs, keys, dobj, region):
    """Class 2 (a, b, c)."""
    n = len(funcs)
    items = []
    refs = collections.defaultdict(list)
    for i, ks in enumerate(keys):
        for k in ks:
            refs[k].append(i)
    kind = {}
    if dobj:
        for a, s, kd in dobj["objs"]:
            kind[a] = kd
    # 2a
    for k, idx in refs.items():
        if 2 <= len(idx) <= DATA_K and idx[-1] - idx[0] <= DATA_SPAN:
            items.append(ev(2, "G", idx[0] + 1, idx[-1], "link", "2a data 0x%08X referenced by %d functions %08X..%08X" % (
                k, len(idx), funcs[idx[0]]["addr"], funcs[idx[-1]]["addr"])))
    # 2b: string order against function order
    strs = []   # (func idx, min string key, max string key)
    for i, ks in enumerate(keys):
        sk = [k for k in ks if kind.get(k) == "string" and 1 <= len(refs[k]) <= DATA_K]
        if sk:
            strs.append((i, min(sk), max(sk)))
    for p in range(1, len(strs)):
        left = strs[max(0, p - MONO_WIN):p]
        right = strs[p:p + MONO_WIN]
        # cut between strs[p-1] and strs[p] is not a single cut when functions sit between;
        # a violation glues the whole interval
        lmax = max(x[2] for x in left)
        rmin = min(x[1] for x in right)
        if rmin < lmax:
            a, b = strs[p - 1][0], strs[p][0]
            items.append(ev(2, "G", a + 1, b, "monotone", "2b string order reversed: 0x%08X seen before 0x%08X across %08X|%08X" % (
                lmax, rmin, funcs[a]["addr"], funcs[b]["addr"])))
    # 2c: data jump
    refs_f = collections.defaultdict(set)
    for k, idx in refs.items():
        for i in idx:
            refs_f[k].add(i)
    objstarts = dobj["starts"] if dobj else []
    objs = dobj["objs"] if dobj else []
    have = [i for i, ks in enumerate(keys) if ks]
    hpos = {i: p for p, i in enumerate(have)}
    for p in range(1, len(have)):
        a, b = have[p - 1], have[p]
        before = [k for q in have[max(0, p - 3):p] for k in keys[q] if len(refs[k]) <= DATA_K]
        after = [k for q in have[p:p + 3] for k in keys[q] if len(refs[k]) <= DATA_K]
        if not before or not after:
            continue
        hi_b, lo_a = max(before), min(after)
        if lo_a <= hi_b:
            continue
        i0 = bisect.bisect_right(objstarts, hi_b)
        i1 = bisect.bisect_left(objstarts, lo_a)
        foreign = 0
        fbytes = 0
        for q in range(i0, i1):
            oa = objs[q][0]
            users = refs.get(oa)
            if users and all(u < a - CALLER_DIST * 3 or u > b + CALLER_DIST * 3 for u in users):
                foreign += 1
                fbytes += objs[q][1]
        if foreign >= 1:
            items.append(ev(2, "B", a + 1, b, "jump", "2c data jump 0x%08X..0x%08X skips %d objects (%d bytes) used only by distant functions" % (
                hi_b, lo_a, foreign, fbytes)))
    return items


def band_of(kind_map, k):
    kd = kind_map.get(k)
    if kd is None:
        return "b"          # exact address outside every registry object: bss or unclassified
    return "s" if kd == "string" else "o"


def band_footprints(keys, kind_map):
    """band -> {function index: (min, max)} over data keys referenced by at most DATA_K functions."""
    refs = collections.defaultdict(int)
    for ks in keys:
        for k in ks:
            refs[k] += 1
    fp = {"s": {}, "o": {}, "b": {}}
    for i, ks in enumerate(keys):
        by = collections.defaultdict(list)
        for k in ks:
            if refs[k] <= DATA_K:
                by[band_of(kind_map, k)].append(k)
        for b, a in by.items():
            fp[b][i] = (min(a), max(a))
    return fp


def ev_dataorder(funcs, keys, dobj):
    """Class 7 (A): the linker lays each object's data out as one block, objects in text order, per band
    (s strings, o other data, b bss).  Two neighbouring functions whose private data in a band lies
    entirely below, with no shared datum, is boundary evidence only if the band order is the TU order:
    measured in calibration.md.  Located only for functions with adjacent indices."""
    items = []
    kind_map = {}
    if dobj:
        for a, sz, kd in dobj["objs"]:
            kind_map[a] = kd
    fp = band_footprints(keys, kind_map)
    for b, d in fp.items():
        for x in sorted(d):
            y = x + 1
            if y in d and d[y][0] > d[x][1]:
                items.append(ev("7" + b, "B", y, y, "medium", "7%s %08X data ..%08X below %08X.. of %08X" % (
                    b, funcs[x]["addr"], d[x][1], d[y][0], funcs[y]["addr"])))
    return items


def pair_order_stats(results, ctx):
    """Calibration of the pairwise ordering signal on every consecutive pair of functions that have private
    data in a band, with truth from anchors (YES: different names, NO: same name).  Not cut-located."""
    c = collections.Counter()
    for reg, r in results.items():
        if r["n"] == 0 or not r.get("keys"):
            continue
        dobj = ctx["dobj"].get(reg)
        if not dobj:
            continue
        kind_map = {a: kd for a, sz, kd in dobj["objs"]}
        fp = band_footprints(r["keys"], kind_map)
        names = r["names"]
        per = {}
        for b, d in fp.items():
            ids = sorted(d)
            for x, y in zip(ids, ids[1:]):
                if names[x] is None or names[y] is None:
                    continue
                lab = "YES" if names[x] != names[y] else "NO"
                mono = d[y][0] > d[x][1]
                c[(b, lab, "mono" if mono else "other")] += 1
                per.setdefault(b, {})[(x, y)] = (lab, mono)
        # cross-band agreement: pairs seen in two bands
        for b1, b2 in (("s", "o"), ("s", "b"), ("o", "b")):
            for key, (lab, m1) in per.get(b1, {}).items():
                if key in per.get(b2, {}):
                    c[("both", b1 + b2, lab, m1, per[b2][key][1])] += 1
    return c


def static_init_report(listings_files):
    """Static initialiser tables per region, from the layout tables and the extracted images."""
    import struct
    rows = []
    try:
        lay = json.load(open(os.path.join(ROOT, "layout/layout.json")))
    except Exception:
        return rows
    for o in lay["overlays"]:
        reg = "ov%03d" % o["id"]
        p = os.path.join(ROOT, "extract", o["decompressed_file"])
        if not os.path.exists(p):
            continue
        data = open(p, "rb").read()
        off = o["static_init_start"] - o["ram_start"]
        n = (o["static_init_end"] - o["static_init_start"]) // 4
        ws = [struct.unpack_from("<I", data, off + 4 * i)[0] for i in range(n)] if off >= 0 else []
        rows.append((reg, n, [w for w in ws if w]))
    return rows


def ev_settings(funcs, settings):
    """Class 3a (compiler/flags/lang) and 3b (isa)."""
    items = []
    known = []
    for i, f in enumerate(funcs):
        s = settings.get(f["addr"])
        if s and s[1] != "sdk_calibration":
            known.append((i, s[0]))
    for (i, a), (j, b) in zip(known, known[1:]):
        if a != b:
            diff = []
            for nm, x, y in zip(("compiler", "lang", "flags"), a, b):
                if x != y:
                    diff.append("%s: '%s' -> '%s'" % (nm, x, y))
            items.append(ev("3a", "B", i + 1, j, "strong", "3a %08X vs %08X: %s" % (
                funcs[i]["addr"], funcs[j]["addr"], "; ".join(diff))))
    for i in range(1, len(funcs)):
        if funcs[i]["isa"] != funcs[i - 1]["isa"]:
            items.append(ev("3b", "B", i, i, "medium", "3b isa %s -> %s" % (funcs[i - 1]["isa"], funcs[i]["isa"])))
    return items


def gaps_of(funcs, region_end):
    """gap[k] for cut k (k>=1): bytes between the end of function k-1 (code and pool) and the start of k."""
    gaps = [None] * len(funcs)
    for k in range(1, len(funcs)):
        p = funcs[k - 1]
        end = max(x for x in (p["code_end"], p["pool_end"], p["addr"]) if x is not None)
        gaps[k] = funcs[k]["addr"] - end
    return gaps


def ev_padding(funcs, gaps, norm):
    items = []
    for k in range(1, len(funcs)):
        g = gaps[k]
        if g is not None and g > norm:
            items.append(ev(4, "B", k, k, "medium", "4 gap %d bytes after %08X (norm %d)" % (g, funcs[k - 1]["addr"], norm)))
    return items


def ev_library(funcs, sdk):
    items = []
    key = [sdk.get(f["addr"]) for f in funcs]
    for k in range(1, len(funcs)):
        a, b = key[k - 1], key[k]
        if a is None and b is None:
            continue
        if a is not None and b is not None and a == b:
            items.append(ev(5, "G", k, k, "proven", "5 same vendor object %s(%s)" % (a[0], a[1])))
        elif a is not None and b is not None:
            items.append(ev(5, "B", k, k, "proven", "5 vendor objects %s(%s) -> %s(%s)" % (a[0], a[1], b[0], b[1])))
        else:
            items.append(ev(5, "B", k, k, "proven", "5 vendor/game switch %s -> %s" % (
                "%s(%s)" % a if a else "game", "%s(%s)" % b if b else "game")))
    return items


def ev_callers(region, funcs, callers_of):
    """Class 6.  callers_of: addr -> set of (region, addr) callers (call or pointer reference)."""
    items = []
    idx = {f["addr"]: i for i, f in enumerate(funcs)}
    for i, f in enumerate(funcs):
        cs = callers_of.get(f["addr"], set())
        cs = {c for c in cs if c != (region, f["addr"])}
        if not cs:
            continue
        if any(c[0] != region for c in cs):
            continue
        ci = sorted(idx[c[1]] for c in cs if c[1] in idx)
        if len(ci) != len(cs):
            continue
        lo, hi = min(ci), max(ci)
        if hi - lo > CALLER_DIST:
            continue
        if i < lo - CALLER_DIST or i > hi + CALLER_DIST:
            continue
        a, b = min(i, lo), max(i, hi)
        if a == b:
            continue
        items.append(ev(6, "G", a + 1, b, "weak", "6 %08X called only from %s" % (
            f["addr"], ",".join("%08X" % funcs[c]["addr"] for c in ci[:4]))))
    return items


# ---------------------------------------------------------------- combine / calibrate

def truth_cuts(names):
    """cut k -> 'NO' (same inherited name), 'YES' (known, different), or None."""
    n = len(names)
    t = [None] * n
    for k in range(1, n):
        a, b = names[k - 1], names[k]
        if a is not None and b is not None:
            t[k] = "NO" if a == b else "YES"
    return t


def located(items):
    return [it for it in items if it["lo"] == it["hi"]]


def cut_map(items, n, typ):
    """cut -> list of located items of that type; ranges tracked separately."""
    m = collections.defaultdict(list)
    for it in items:
        if it["typ"] != typ:
            continue
        for k in range(it["lo"], it["hi"] + 1):
            if typ == "G" or it["lo"] == it["hi"]:
                m[k].append(it)
    return m


def analyse_region(region, rec, ctx):
    funcs = rec["funcs"]
    n = len(funcs)
    res = {"n": n, "funcs": funcs, "items": [], "names": [None] * n, "conflicts": [], "gaps": None}
    if n == 0:
        return res
    a_items, names, conflicts = ev_anchors(funcs, ctx["anchors"].get(region, {}))
    fn_set = {f["addr"] for f in funcs}
    keys, _rng = data_keys(region, rec, ctx["dobj"].get(region), fn_set)
    gaps = gaps_of(funcs, rec["range"][1] if rec["range"] else None)
    res["gaps"] = gaps
    res["keys"] = keys
    res["names"] = names
    res["conflicts"] = conflicts
    res["cls"] = {
        "1": a_items,
        "2": ev_data(funcs, keys, ctx["dobj"].get(region), region),
        "3": ev_settings(funcs, ctx["settings"].get(region, {})),
        "5": ev_library(funcs, ctx["sdk"].get(region, {})),
        "6": ev_callers(region, funcs, ctx["callers"].get(region, {})),
        "7": ev_dataorder(funcs, keys, ctx["dobj"].get(region)),
    }
    return res


def build_callers(listings):
    """region -> addr -> set((caller region, caller addr)) from bl/b targets and pool pointers."""
    nameaddr = {}
    for reg, rec in listings.items():
        nameaddr[reg] = {f["name"]: f["addr"] for f in rec["funcs"]}
    arm9 = nameaddr.get("arm9", {})
    out = collections.defaultdict(lambda: collections.defaultdict(set))
    for reg, rec in listings.items():
        own = nameaddr[reg]
        for f in rec["funcs"]:
            for t in f["calls"]:
                if t in own:
                    out[reg][own[t]].add((reg, f["addr"]))
                elif t in arm9:
                    out["arm9"][arm9[t]].add((reg, f["addr"]))
            for (_a, v, tgt) in f["pools"]:
                if tgt:
                    t = tgt
                    if t in own:
                        out[reg][own[t]].add((reg, f["addr"]))
                    elif t in arm9:
                        out["arm9"][arm9[t]].add((reg, f["addr"]))
    return out


def percentile_norm(vals, q):
    if not vals:
        return 0
    vals = sorted(vals)
    return vals[min(len(vals) - 1, int(q * len(vals)))]


def calibrate(results, classes_B, classes_G):
    """Aggregate truth-labeled counts per evidence class over all regions."""
    stats = collections.defaultdict(lambda: collections.Counter())
    for reg, r in results.items():
        if r["n"] == 0:
            continue
        t = truth_cuts(r["names"])
        n = r["n"]
        allitems = r["all_items"]
        for cname in classes_B + classes_G:
            typ = "B" if cname in classes_B else "G"
            flagged = set()
            for it in allitems:
                if str(it["cls"]) == cname and it["typ"] == typ:
                    if typ == "G":
                        flagged.update(range(it["lo"], it["hi"] + 1))
                    elif it["lo"] == it["hi"]:
                        flagged.add(it["lo"])
            st = stats[cname]
            if typ == "B":
                for g in allitems:
                    if g["cls"] == 1 and g["typ"] == "B" and g["lo"] < g["hi"]:
                        st["gaps"] += 1
                        st["gap_cuts"] += g["hi"] - g["lo"] + 1
                        h = [k for k in range(g["lo"], g["hi"] + 1) if k in flagged]
                        st["gap_hit"] += 1 if h else 0
                        st["gap_flags"] += len(h)
            for k in range(1, n):
                lab = t[k]
                f = k in flagged
                if lab == "YES":
                    st["yes"] += 1
                    if f:
                        st["tp_yes" if typ == "B" else "wrong_glue"] += 1
                elif lab == "NO":
                    st["no"] += 1
                    if f:
                        st["fp_no" if typ == "B" else "ok_glue"] += 1
                else:
                    st["unk"] += 1
                    if f:
                        st["flag_unk"] += 1
    return stats


def qualifies(st, typ, cls=None):
    if typ == "B":
        # boundary truth is sparse (anchors rarely sit on both sides of a cut), so judge by
        # the false positive rate on NO cuts and by hits on YES cuts or YES gaps
        fp, no = st["fp_no"], st["no"]
        hits = st["tp_yes"] + st["gap_hit"]
        fpr = fp / no if no else 1.0
        gr = st["gap_flags"] / st["gap_cuts"] if st["gap_cuts"] else 0.0
        enriched = (gr >= MIN_ENRICH * fpr) if fpr > 0 else st["gap_flags"] >= 1
        ok = no >= MIN_LABELED and fpr <= MAX_FPR and hits >= MIN_HITS and enriched
        return ok, st["tp_yes"] + fp, (1.0 - fpr)
    tp, fp = st["ok_glue"], st["wrong_glue"]
    lab = tp + fp
    need = 1 if cls == "5" else MIN_LABELED   # vendor objects are byte verified; anchors rarely sit in them
    return lab >= need and lab and tp / lab >= MIN_PRECISION, lab, (tp / lab if lab else None)


# ---------------------------------------------------------------- final assembly

def assemble(region, r, qual, use_anchors=True):
    """Resolve cuts and build TUs. Returns (cuts, tus).

    cut state: 'B' boundary, 'G' glued, '?' undecided; with the evidence list.
    qual: set of class names allowed to split (B) / glue (G).
    """
    funcs = r["funcs"]
    n = r["n"]
    cuts = [None] * n
    items = r["all_items"]
    bmap = collections.defaultdict(list)
    gmap = collections.defaultdict(list)
    ranges = []
    for it in items:
        c = str(it["cls"])
        if not use_anchors and c == "1":
            continue
        if it["typ"] == "B":
            if it["lo"] == it["hi"]:
                bmap[it["lo"]].append(it)
            else:
                ranges.append(it)
        else:
            for k in range(it["lo"], it["hi"] + 1):
                gmap[k].append(it)
    # a hard boundary range with exactly one candidate cut by another qualified class is located
    for it in ranges:
        cand = [k for k in range(it["lo"], it["hi"] + 1)
                if any(str(x["cls"]) + "B" in qual for x in bmap.get(k, []))]
        if len(cand) == 1:
            bmap[cand[0]].append(dict(it, lo=cand[0], hi=cand[0],
                                      detail=it["detail"] + " (located by other evidence)"))
    states = [None] * n
    for k in range(1, n):
        bs = [x for x in bmap.get(k, []) if str(x["cls"]) + "B" in qual]
        gs = [x for x in gmap.get(k, []) if str(x["cls"]) + "G" in qual]
        hard_b = [x for x in bs if x["strength"] == "proven"]
        hard_g = [x for x in gs if x["strength"] == "proven"]
        if hard_b and not hard_g:
            states[k] = "B"
        elif hard_g and not hard_b:
            states[k] = "G"
        elif hard_b and hard_g:
            states[k] = "B" if str(hard_b[0]["cls"]) in ("1",) else ("G" if str(hard_g[0]["cls"]) in ("1",) else "B")
        elif bs and not gs:
            states[k] = "B"
        elif gs and not bs:
            states[k] = "G"
        elif gs and bs:
            states[k] = "C"   # conflict, treated as undecided
        else:
            states[k] = "?"
        cuts[k] = {"state": states[k], "b": bs, "g": gs}
    # An anchor name change between two anchored functions puts a boundary somewhere in the
    # range of cuts between them.  If every cut of the range but one is glued, that one is it.
    if use_anchors:
        r["range_conflicts"] = []
        for it in ranges:
            if it["cls"] != 1:
                continue
            free = [k for k in range(it["lo"], it["hi"] + 1) if states[k] != "G"]
            if len(free) == 1 and states[free[0]] != "B":
                k = free[0]
                states[k] = "B"
                cuts[k]["state"] = "B"
                cuts[k]["b"].append(dict(it, lo=k, hi=k, detail=it["detail"] + " (other cuts of the range are glued)"))
            elif not free:
                r["range_conflicts"].append(it["detail"])
    return cuts, states


def make_tus(region, r, cuts, states, qual, tu_hard):
    funcs = r["funcs"]
    n = r["n"]
    tus = []
    start = 0
    for k in range(1, n + 1):
        if k == n or states[k] == "B":
            tus.append((start, k - 1))
            start = k
    out = []
    for (a, b) in tus:
        internal = list(range(a + 1, b + 1))
        n_g = sum(1 for k in internal if states[k] == "G")
        n_q = len(internal) - n_g
        hard_internal = all(
            any(str(x["cls"]) in ("1", "5") and x["strength"] == "proven" for x in cuts[k]["g"]) for k in internal)
        left_ev = cuts[a]["b"] if a > 0 else None
        right_ev = cuts[b + 1]["b"] if b + 1 < n else None
        ends_ok = (a == 0 or left_ev) and (b + 1 == n or right_ev)
        left_hard = a == 0 or any(x["strength"] == "proven" for x in left_ev)
        right_hard = b + 1 == n or any(x["strength"] == "proven" for x in right_ev)
        if n_q == 0 and hard_internal and left_hard and right_hard and (b > a):
            conf = "proven"
        elif n_q == 0 and ends_ok:
            conf = "likely"
        else:
            conf = "weak"
        names = collections.Counter(r["names"][i] for i in range(a, b + 1) if r["names"][i])
        name = names.most_common(1)[0][0] if names else None
        classes = collections.Counter()
        for k in internal:
            for x in cuts[k]["g"]:
                classes["G" + str(x["cls"])] += 1
        for kk in (a, b + 1):
            if 0 < kk < n:
                for x in cuts[kk]["b"]:
                    classes["B" + str(x["cls"])] += 1
        groups = []
        g0 = a
        for k in range(a + 1, b + 2):
            if k == b + 1 or states[k] != "G":
                groups.append((g0, k - 1))
                g0 = k
        out.append({"a": a, "b": b, "conf": conf, "name": name, "n_unresolved": n_q,
                    "classes": classes, "groups": groups})
    return out


# ---------------------------------------------------------------- driver

def hexs(x):
    return "%08X" % x


def run(args):
    out_dir = args.out
    os.makedirs(out_dir, exist_ok=True)
    cache_path = os.path.join(out_dir, "listings.pickle")
    listings, files = load_listings(cache_path, args.region)
    ctx = {
        "anchors": load_anchors(),
        "dobj": load_data_objects(),
        "sdk": load_sdk(),
        "settings": load_settings(),
    }
    ctx["callers"] = build_callers(listings)

    results = {}
    for region in files:
        if region not in listings:
            continue
        results[region] = analyse_region(region, listings[region], ctx)

    # class 4 norm: calibrated on cuts proven in-TU by class 1
    ingap = []
    for region, r in results.items():
        if r["n"] == 0:
            continue
        t = truth_cuts(r["names"])
        for k in range(1, r["n"]):
            if t[k] == "NO" and r["gaps"][k] is not None:
                ingap.append(r["gaps"][k])
    norm = percentile_norm(ingap, 0.99) if ingap else 2
    gap_hist = collections.Counter(ingap)
    for region, r in results.items():
        if r["n"] == 0:
            r["all_items"] = []
            continue
        r["cls"]["4"] = ev_padding(r["funcs"], r["gaps"], norm)
        r["all_items"] = [it for c in ("1", "2", "3", "4", "5", "6", "7") for it in r["cls"][c]]
        # split class 3 label for calibration
    BCLS = ["1", "2", "3a", "3b", "4", "5", "7s", "7o", "7b"]
    GCLS = ["1", "2", "5", "6"]
    # calibration keys: B and G tracked separately via typ below
    stats = {}
    for typ, lst in (("B", BCLS), ("G", GCLS)):
        st = calibrate(results, lst if typ == "B" else [], lst if typ == "G" else [])
        for c in lst:
            stats[(c, typ)] = st[c]
    qual_info = {}
    qual_set = set()
    for (c, typ), st in stats.items():
        if c == "1":
            ok, lab, prec = True, st["yes"] + st["no"], 1.0
        else:
            ok, lab, prec = qualifies(st, typ, c)
        qual_info[(c, typ)] = (ok, lab, prec)
        if ok:
            qual_set.add(c + typ)

    # sensitivity of class 2a (K, span)
    write_all(args, results, listings, ctx, stats, qual_info, qual_set, norm, gap_hist, files)


def evaluate_final(results, qual_set, use_anchors):
    """Cut-level agreement of the final decision with the anchors truth."""
    c = collections.Counter()
    for region, r in results.items():
        if r["n"] == 0:
            continue
        cuts, states = assemble(region, r, qual_set, use_anchors)
        t = truth_cuts(r["names"])
        for g in r["all_items"]:
            if g["cls"] == 1 and g["typ"] == "B" and g["lo"] < g["hi"]:
                c["gaps"] += 1
                c["gap_split"] += any(states[k] == "B" for k in range(g["lo"], g["hi"] + 1))
        for k in range(1, r["n"]):
            if t[k] == "YES":
                c["yes"] += 1
                c["yes_B"] += states[k] == "B"
                c["yes_G"] += states[k] == "G"
            elif t[k] == "NO":
                c["no"] += 1
                c["no_B"] += states[k] == "B"
                c["no_G"] += states[k] == "G"
    return c


def write_all(args, results, listings, ctx, stats, qual_info, qual_set, norm, gap_hist, files):
    out = args.out
    # ---- boundaries and TUs
    bfh = open(os.path.join(out, "boundaries.tsv"), "w")
    bfh.write("region\tcut_before_addr\tprev_func\tnext_func\tstate\tclasses\tconfidence\tdetails\n")
    tfh = open(os.path.join(out, "tu_proposal.tsv"), "w")
    tfh.write("region\tstart\tend\tfunctions\tname\tconfidence\tunresolved_cuts\tevidence\n")
    ffh = open(os.path.join(out, "tu_fragments.tsv"), "w")
    ffh.write("region\tstart\tend\tfunctions\ttu_start\ttu_confidence\tname\tglue_classes\n")
    totals = {}
    for region in files:
        r = results.get(region)
        if r is None:
            continue
        n = r["n"]
        tot = collections.Counter()
        tot["functions"] = n
        if n == 0:
            totals[region] = tot
            continue
        cuts, states = assemble(region, r, qual_set, True)
        tus = make_tus(region, r, cuts, states, qual_set, True)
        funcs = r["funcs"]
        # located boundaries
        for k in range(1, n):
            cs = cuts[k]
            allb = [x for x in r["all_items"] if x["typ"] == "B" and x["lo"] <= k <= x["hi"] and
                    (x["lo"] == x["hi"] or states[k] == "B")]
            if states[k] == "B" or allb:
                cl = sorted({str(x["cls"]) for x in allb})
                hard = any(x["strength"] == "proven" and str(x["cls"]) + "B" in qual_set for x in allb)
                if states[k] == "B":
                    conf = "proven" if hard else ("likely" if sum(str(x["cls"]) + "B" in qual_set for x in allb) >= 2 else "weak")
                else:
                    conf = "unverified"
                det = " | ".join(x["detail"] + ("" if x["lo"] == x["hi"] else " [range cuts %d..%d]" % (x["lo"], x["hi"]))
                                 for x in allb)
                bfh.write("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n" % (
                    region, hexs(funcs[k]["addr"]), funcs[k - 1]["name"], funcs[k]["name"],
                    states[k], ",".join(cl), conf, det))
        for t in tus:
            a, b = t["a"], t["b"]
            nf = b - a + 1
            tot[t["conf"]] += nf
            tot["tus_" + t["conf"]] += 1
            tot["tus"] += 1
            if t["name"]:
                nm = t["name"]
            else:
                nm = "unit_%s" % hexs(funcs[a]["addr"])
            ev_s = " ".join("%s=%d" % kv for kv in sorted(t["classes"].items()))
            end_addr = funcs[b]["addr"] if b == n - 1 else funcs[b + 1]["addr"]
            tfh.write("%s\t%s\t%s\t%d\t%s\t%s\t%d\t%s\n" % (
                region, hexs(funcs[a]["addr"]), hexs(end_addr), nf, nm, t["conf"], t["n_unresolved"], ev_s))
            for (ga, gb) in t["groups"]:
                gcl = collections.Counter(str(x["cls"]) for k in range(ga + 1, gb + 1) for x in cuts[k]["g"])
                gend = funcs[gb]["addr"] if gb == n - 1 else funcs[gb + 1]["addr"]
                ffh.write("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%s\n" % (
                    region, hexs(funcs[ga]["addr"]), hexs(gend), gb - ga + 1, hexs(funcs[a]["addr"]), t["conf"], nm,
                    " ".join("%s=%d" % kv for kv in sorted(gcl.items()))))
                if t["conf"] == "weak":
                    tot["weak_in_group2"] += (gb - ga + 1) if gb > ga else 0
                    tot["weak_singletons"] += 1 if gb == ga else 0
        totals[region] = tot
    bfh.close()
    tfh.close()
    ffh.close()

    # ---- calibration
    L = []
    L.append("# Calibration against __FILE__ anchors (class 1)\n")
    tot_yes = sum(s["yes"] for (c, t), s in stats.items() if (c, t) == ("1", "B"))
    s1 = stats[("1", "B")]
    L.append("Truth: a cut is NO (same TU) when both neighbouring functions carry the same inherited anchor name "
             "(function is anchored, or lies between two same-named anchored functions); YES (boundary) when both "
             "carry different names; otherwise unlabeled. Labeled cuts: %d NO, %d YES; unlabeled: %d.\n" % (
                 s1["no"], s1["yes"], s1["unk"]))
    L.append("Boundary classes (B): precision = TP/(TP+FP) over labeled flagged cuts; recall = TP/YES; "
             "FP rate = FP/NO. Glue classes (G): precision = glued NO / glued labeled; recall = glued NO / NO; "
             "wrong-glue rate = glued YES / YES. Only located evidence is counted for B (range evidence is not).\n")
    L.append("Rule: a glue class takes part when labeled glued cuts >= %d and precision >= %.2f; a boundary class "
             "takes part when its flagged share of NO cuts is <= %.2f and it hits >= %d YES cuts or YES gaps with an enrichment of at least %.1f (a "
             "YES gap is a pair of consecutive anchored functions with different names and unlabeled cuts between; "
             "hit = the class flags at least one located cut inside). Class 1 is the truth and always takes part.\n" % (
                 MIN_LABELED, MIN_PRECISION, MAX_FPR, MIN_HITS, MIN_ENRICH))
    notes = []
    L.append("| class | role | flagged on YES | flagged on NO | flagged unlabeled | precision | recall | FP/wrong rate | used |")
    L.append("|---|---|---|---|---|---|---|---|---|")
    for (c, typ) in sorted(stats):
        st = stats[(c, typ)]
        if c == "1":
            L.append("| 1 | %s | n/a | n/a | %d | truth | truth | truth | yes |" % (typ, st["flag_unk"]))
            continue
        ok, lab, prec = qual_info[(c, typ)]
        if typ == "B":
            tp, fp = st["tp_yes"], st["fp_no"]
            rec = tp / st["yes"] if st["yes"] else None
            fpr = fp / st["no"] if st["no"] else None
            L.append("| %s | B | %d | %d | %d | 1-FPR %s | %s (gaps hit %d/%d) | %s | %s |" % (
                c, tp, fp, st["flag_unk"], fmt(prec), fmt(rec), st["gap_hit"], st["gaps"], fmt(fpr),
                "yes" if ok else "no (FPR %s, hits %d, not enriched or too few)" % (fmt(fpr), tp + st["gap_hit"])))
            if st["gaps"]:
                pr = (st["gap_flags"] / st["gap_cuts"]) if st["gap_cuts"] else 0
                avg = st["gap_cuts"] / st["gaps"]
                base = fp / st["no"] if st["no"] else 0
                notes.append("class %s: flag rate per cut inside YES gaps %.4f vs on NO cuts %.4f (enrichment %s); gaps hit %d/%d; "
                             "chance level at the NO-cut rate over %.1f cuts per gap: %.1f hits" % (
                                 c, pr, base, ("%.1f" % (pr / base)) if base else "inf", st["gap_hit"], st["gaps"], avg,
                                 st["gaps"] * (1 - (1 - base) ** avg)))
        else:
            tp, fp = st["ok_glue"], st["wrong_glue"]
            rec = tp / st["no"] if st["no"] else None
            fpr = fp / st["yes"] if st["yes"] else None
            L.append("| %s | G | %d | %d | %d | %s | %s | %s | %s |" % (
                c, fp, tp, st["flag_unk"], fmt(prec), fmt(rec), fmt(fpr), "yes" if ok else "no (%s)" % why(lab, prec)))
    L.append("\nFor G rows the 'flagged on YES' column is wrong glue and 'flagged on NO' is correct glue.\n")
    L.extend("- " + x for x in notes)
    L.append("")
    L.append("## Class 4 norm\n")
    L.append("Gap histogram (bytes between the end of code and pool of a function and the next function start) on %d "
             "cuts proven in-TU by class 1:\n" % sum(gap_hist.values()))
    for g in sorted(gap_hist):
        L.append("- gap %d: %d" % (g, gap_hist[g]))
    L.append("\nThe norm used is the 99th percentile of that distribution: %d bytes. Gaps larger than the norm are "
             "class 4 boundary evidence.\n" % norm)
    # gap distribution at YES cuts
    yes_gap = collections.Counter()
    for region, r in results.items():
        if r["n"] == 0:
            continue
        t = truth_cuts(r["names"])
        for k in range(1, r["n"]):
            if t[k] == "YES" and r["gaps"][k] is not None:
                yes_gap[r["gaps"][k]] += 1
    L.append("Gap histogram on the %d cuts proven boundaries by class 1:\n" % sum(yes_gap.values()))
    for g in sorted(yes_gap):
        L.append("- gap %d: %d" % (g, yes_gap[g]))
    # combined
    for use_anchors, label in ((True, "all classes (class 1 included, so this is a consistency check)"),
                               (False, "class 1 withheld (honest estimate of what the other classes achieve)")):
        c = evaluate_final(results, qual_set, use_anchors)
        L.append("\n## Combined decision, %s\n" % label)
        L.append("- YES cuts %d: split %d (%s), glued %d, undecided %d" % (
            c["yes"], c["yes_B"], fmt(c["yes_B"] / c["yes"] if c["yes"] else None), c["yes_G"],
            c["yes"] - c["yes_B"] - c["yes_G"]))
        L.append("- YES gaps (consecutive anchored functions with different names, boundary somewhere between): %d, "
                 "of which %d contain at least one cut decided as boundary" % (c["gaps"], c["gap_split"]))
        L.append("- NO cuts %d: glued %d (%s), wrongly split %d (%s), undecided %d" % (
            c["no"], c["no_G"], fmt(c["no_G"] / c["no"] if c["no"] else None), c["no_B"],
            fmt(c["no_B"] / c["no"] if c["no"] else None), c["no"] - c["no_B"] - c["no_G"]))
    # ---- A: data side
    po = pair_order_stats(results, ctx)
    L.append("\n## Class 7 (A): data-side order\n")
    L.append("Hypothesis tested: the linker places each object's data as one block, blocks in text order. Claims checked:\n")
    L.append("- Alignment gaps mark object boundaries: FALSE at the string level. Strings are individually aligned (start "
             "addresses are 4-aligned for most strings, padding follows odd-length strings inside one TU). On consecutive "
             "string pairs with anchored owners (346 different-TU, 66 same-TU, measured once over all anchored regions) zero padding follows the first string in 74% of different-TU and 61% of same-TU pairs, and the next start phase mod 8 is 0 or 4 in 100% of different-TU and 89% of same-TU pairs (half 0, half 4: no 8-byte section alignment); a TU boundary adds no alignment beyond the per-string one, so data gaps carry no boundary signal. Strings by start phase: 4-aligned for 82% (ov021) and 89% (arm9) of strings, the rest 2-aligned or odd.")
    L.append("- Per band order: for consecutive functions that have private data (referenced by at most %d functions) "
             "in one band, 'below' means the second function's lowest address is above the first one's highest. "
             "Truth from anchors (YES different names, NO same name):\n" % DATA_K)
    L.append("| band | YES below | YES other | NO below | NO other | P(below given YES) | P(below given NO) |")
    L.append("|---|---|---|---|---|---|---|")
    for b, nm in (("s", "strings"), ("o", "other data"), ("b", "bss and unclassified")):
        yb, yo, nb, no_ = po[(b, "YES", "mono")], po[(b, "YES", "other")], po[(b, "NO", "mono")], po[(b, "NO", "other")]
        L.append("| %s | %d | %d | %d | %d | %s | %s |" % (nm, yb, yo, nb, no_,
                 fmt(yb / (yb + yo) if yb + yo else None), fmt(nb / (nb + no_) if nb + no_ else None)))
    L.append("")
    agree = collections.Counter()
    for k, v in po.items():
        if k[0] == "both":
            agree[(k[1], k[2], k[3] == k[4])] += v
    for bb in ("so", "sb", "ob"):
        L.append("- bands %s on pairs having data in both: YES pairs same verdict %d, differ %d; NO pairs same verdict %d, differ %d" % (
            bb, agree[(bb, "YES", True)], agree[(bb, "YES", False)], agree[(bb, "NO", True)], agree[(bb, "NO", False)]))
    L.append("\nA below-order pair is also what an in-TU run of strings laid out in function order looks like, so the "
             "signal separates TUs only as far as in-TU pairs share data or use data out of order (those are the "
             "other side of the table). Located boundary evidence uses only pairs of adjacent functions.\n")
    # ---- B: static initialisers
    L.append("\n## Class 8 (B): static initialisers\n")
    si = static_init_report(files)
    nz = [(r_, n_, w_) for r_, n_, w_ in si if w_]
    L.append("- overlays with a table: %d; all have exactly %d slot in the layout header except ov230 (%s); nonzero entries: %s" % (
        len(si), 1, ", ".join("%s:%d" % (r_, n_) for r_, n_, w_ in si if n_ != 1) or "none",
        ", ".join("%s:%d" % (r_, len(w_)) for r_, n_, w_ in nz) or "none"))
    for r_, n_, w_ in nz:
        asc = all(a < b for a, b in zip(w_, w_[1:]))
        L.append("- %s entries ascending: %s; entries %s" % (r_, asc, " ".join("%08X" % x for x in w_)))
        fa = {f["addr"] for f in results[r_]["funcs"]} if r_ in results else set()
        L.append("  - entries that are function starts in the listing: %d of %d; anchored: %d (ov230 holds decryption "
                 "stubs run at load, one per encrypted range group, not one per source file)" % (
                     sum(1 for x in w_ if (x & ~1) in fa), len(w_),
                     sum(1 for x in w_ if (x & ~1) in ctx["anchors"].get(r_, {}))))
    L.append("- ARM9 main: INITi_CallStaticInitializers (crt0) walks a null terminated table sheltered in DTCM; the table "
             "sits in no registry object with function targets, the listings carry no header for it; the autoload "
             "blocks (ITCM, DTCM, twl) start with data or code, not tables. Result: no per-TU entry list exists.")
    L.append("- Hypothesis (one entry per TU, in TU order): FALSE. 236 of 237 overlays hold a single zero terminator, "
             "ov230 holds %d non-source entries. No evidence emitted." % (len(nz[0][2]) if nz else 0))
    # ---- C: overlay bounds
    L.append("\n## Class 9 (C): region bounds and TU count bounds\n")
    forced = []
    minmax = []
    for region, r in results.items():
        if r["n"] == 0:
            continue
        nm = r["names"]
        anchored = [i for i in range(r["n"]) if nm[i] is not None]
        if not anchored:
            continue
        names_seq = []
        for i in anchored:
            if not names_seq or names_seq[-1] != nm[i]:
                names_seq.append(nm[i])
        first_a, last_a = anchored[0], anchored[-1]
        if first_a == 0 and last_a == r["n"] - 1 and len(set(names_seq)) == 1:
            forced.append((region, r["n"], names_seq[0]))
        minmax.append((region, len(names_seq), first_a, r["n"] - 1 - last_a))
    L.append("- Region start and end: cut 0 and cut n are TU boundaries in make_tus (hard), so a run touching a region "
             "edge needs evidence on its other side only; overlays are linked from whole objects, so this holds.")
    L.append("- Name changes along anchored functions give a lower bound of distinct TUs per region (sum over regions %d); "
             "no upper bound exists without a boundary class." % sum(m[1] for m in minmax))
    L.append("- Regions forced to exactly one TU (anchor on the first and the last function, one name): %d, holding %d functions" % (
        len(forced), sum(f[1] for f in forced)))
    for f_ in forced:
        L.append("  - %s: %d functions, %s" % f_)
    runs1 = 0
    runsf = 0
    for region, r in results.items():
        for it in r["all_items"]:
            if it["cls"] == 1 and it["typ"] == "G":
                runs1 += 1
                runsf += it["hi"] - it["lo"] + 1
    L.append("- Anchor same-name spans (one TU forced between two anchors of one name): %d spans covering %d cuts" % (runs1, runsf))
    edge_free = sum(1 for m in minmax if m[2] > 0 or m[3] > 0)
    L.append("- Regions with unanchored functions before the first or after the last anchor: %d of %d anchored regions; "
             "those edge runs hold at least one TU each, exactly one only when no other class splits them." % (edge_free, len(minmax)))
    # conflicts
    nconf = sum(len(r["conflicts"]) for r in results.values())
    L.append("\n## Input anomalies\n")
    L.append("- functions carrying more than one distinct __FILE__ name: %d" % nconf)
    L.append("- anchor gaps (different names) whose every cut is glued by another class, a contradiction: %d" % sum(
        len(r.get("range_conflicts", [])) for r in results.values()))
    for region, r in results.items():
        for (a, nm) in r["conflicts"][:5]:
            L.append("  - %s %08X: %s" % (region, a, ", ".join(nm)))
    open(os.path.join(out, "calibration.md"), "w").write("\n".join(L) + "\n")

    # ---- summary
    S = []
    S.append("# TU boundary proposal summary\n")
    S.append("Classes taking part: %s\n" % ", ".join(sorted(qual_set)))
    S.append("| region | listing | functions | declared | proven | likely | weak | TUs (p/l/w) | anchored fns | sdk fns |")
    S.append("|---|---|---|---|---|---|---|---|---|---|")
    gt = collections.Counter()
    for region in files:
        r = results.get(region)
        if r is None:
            S.append("| %s | MISSING | 0 | | | | | | | |" % region)
            continue
        t = totals.get(region, collections.Counter())
        rec = listings[region]
        nanch = sum(1 for f in r["funcs"] if f["addr"] in ctx["anchors"].get(region, {}))
        nsdk = sum(1 for f in r["funcs"] if f["addr"] in ctx["sdk"].get(region, {}))
        S.append("| %s | %s | %d | %s | %d | %d | %d | %d/%d/%d | %d | %d |" % (
            region, os.path.relpath(files[region], ROOT).replace(os.sep, "/"), r["n"],
            rec["declared"], t["proven"], t["likely"], t["weak"],
            t["tus_proven"], t["tus_likely"], t["tus_weak"], nanch, nsdk))
        for k in ("functions", "proven", "likely", "weak", "tus_proven", "tus_likely", "tus_weak", "tus",
                  "weak_in_group2", "weak_singletons"):
            gt[k] += t[k]
    S.append("| TOTAL | | %d | | %d | %d | %d | %d/%d/%d | | |" % (
        gt["functions"], gt["proven"], gt["likely"], gt["weak"], gt["tus_proven"], gt["tus_likely"], gt["tus_weak"]))
    S.append("\nUnassigned functions: none by construction, every function sits in some run; 'weak' rows are runs whose "
             "internal cuts are not all decided (they may hold several TUs). Weak functions: %d of %d." % (gt["weak"], gt["functions"]))
    S.append("\n## Evidence found, whole image (items; cuts covered)\n")
    cnt = collections.defaultdict(lambda: [0, 0])
    for r in results.values():
        for it in r["all_items"]:
            e = cnt[(str(it["cls"]), it["typ"])]
            e[0] += 1
            e[1] += it["hi"] - it["lo"] + 1
    for (c, t_), (ni, nc) in sorted(cnt.items()):
        S.append("- class %s %s: %d items, %d cuts%s" % (
            c, "boundary" if t_ == "B" else "glue", ni, nc, "" if (c + t_) in qual_set else " (not used)"))
    S.append("\n## Open ambiguities\n")
    S.append("- runs with undecided internal cuts: %d TUs hold %d functions; boundaries.tsv lists the evidence that exists" % (
        gt["tus_weak"], gt["weak"]))
    unver = sorted(c + t for c, t in qual_info if (c + t) not in qual_set)
    S.append("- classes measured but not allowed to split/glue (precision below threshold or too few labeled cuts): %s" % (", ".join(unver) or "none"))
    open(os.path.join(out, "summary.md"), "w").write("\n".join(S) + "\n")
    print("\n".join(S))
    print()
    print(open(os.path.join(out, "calibration.md")).read())


def fmt(x):
    return "n/a" if x is None else "%.3f" % x


def why(lab, prec):
    if lab < MIN_LABELED:
        return "only %d labeled" % lab
    return "precision %s" % fmt(prec)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--out", default=scratch_default())
    ap.add_argument("--region", default=None, help="analyse one region only")
    args = ap.parse_args()
    run(args)


if __name__ == "__main__":
    main()
