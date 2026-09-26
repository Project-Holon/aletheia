#!/usr/bin/env python3
"""Render the coverage treemaps as one fused SVG per subject.

Two subjects, each one image with two panels stacked (group view above, original-source-file
view below) and a small title on each panel:

  docs/coverage_overlays.svg   the 237 overlays, one block per overlay, functions inside
  docs/coverage_map.svg        the ARM9 static image, one block per translation unit

Tile area is code bytes. Colours: matched exact, matched resting on sole-ref, open, SDK
(excluded), runtime (excluded). Only addresses, sizes and names are drawn; no game bytes.

Usage:
    python3 tools/coveragemap.py                 both images
    python3 tools/coveragemap.py --arm9          docs/coverage_map.svg only
    python3 tools/coveragemap.py --overlays      docs/coverage_overlays.svg only
"""
import argparse
import bisect
import glob
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import worklist  # noqa: E402
import ovstats  # noqa: E402

COL = {"matched": "#2f9e5b", "matched2": "#3fb96e", "sole": "#8fd3a8", "open": "#34393b", "open2": "#3d4245",
       "sdk": "#262b30", "matched_sdk": "#2f8fb0", "runtime": "#3a3629", "bg": "#15181a", "line": "#0d0f10",
       "ink": "#e6e9e6", "muted": "#8f978f", "title": "#c9d2c9"}

HDR_RANGE = re.compile(r"address range\s+0x([0-9A-Fa-f]+)\.\.0x([0-9A-Fa-f]+)\s+\(0x([0-9A-Fa-f]+) bytes\)")
HDR_CODE = re.compile(r"classified\s+0x([0-9A-Fa-f]+) bytes code")
LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_.]*):\s*$")
ORG = re.compile(r"^\s*\.org\s+0x([0-9A-Fa-f]+)")
INSN = re.compile(r"/\*\s*([0-9A-Fa-f]{8})\s+((?:[0-9A-Fa-f]{2} )+)\*/")
FUNCNAME = re.compile(r"^(?:func|sub)_")


def squarify(items, x, y, w, h):
    """items: list of (value, payload) sorted descending. Returns [(x, y, w, h, payload)]."""
    total = sum(v for v, _ in items)
    out = []
    if not total or w <= 0 or h <= 0:
        return out
    scale = w * h / total
    rest = list(items); row = []; rx, ry, rw, rh = x, y, w, h

    def worst(row, ln):
        s = sum(v * scale for v, _ in row); mx = max(v * scale for v, _ in row); mn = min(v * scale for v, _ in row)
        return max(ln * ln * mx / (s * s), s * s / (ln * ln * mn))

    def layout(row):
        nonlocal rx, ry, rw, rh
        s = sum(v * scale for v, _ in row)
        if rw >= rh:
            cw = s / rh; cy = ry
            for v, p in row:
                ch = v * scale / cw; out.append((rx, cy, cw, ch, p)); cy += ch
            rx += cw; rw -= cw
        else:
            ch = s / rw; cx = rx
            for v, p in row:
                cw = v * scale / ch; out.append((cx, ry, cw, ch, p)); cx += cw
            ry += ch; rh -= ch

    while rest:
        ln = min(rw, rh); it = rest[0]
        if not row or worst(row + [it], ln) <= worst(row, ln):
            row.append(it); rest.pop(0)
        else:
            layout(row); row = []
    if row:
        layout(row)
    return out


def read_anchors():
    """[(region_token, address, source_name)] from layout/file_anchors.txt, all regions."""
    out = []
    path = os.path.join(ROOT, "layout", "file_anchors.txt")
    if not os.path.exists(path):
        return out
    for ln in open(path):
        p = ln.split()
        if ln.startswith("#") or len(p) < 5:
            continue
        try:
            addr = int(p[1], 16)
        except ValueError:
            continue
        out.append((p[2], addr, p[4]))
    return out


def _group_by_anchor(funcs, anchors, region_filter, tail_key):
    """Attribute each function to the last anchor at or before it, within one region."""
    sel = sorted((a, n) for reg, a, n in anchors if region_filter(reg))
    starts = [a for a, _ in sel]
    merged = []
    for a, name in sel:
        if not merged or merged[-1][1] != name:
            merged.append((a, name))
    if not merged:
        return {}
    mstarts = [a for a, _ in merged]
    groups = {}
    for fn in funcs:
        i = bisect.bisect_right(mstarts, fn["addr"]) - 1
        if i < 0:
            key = tail_key
        elif i == len(merged) - 1:
            key = "%s (no anchor past 0x%08X)" % (merged[i][1], merged[i][0])
        else:
            key = merged[i][1]
        groups.setdefault(key, []).append(fn)
    return groups


def families_arm9(funcs, anchors):
    """Group by original source file, inferred from the ARM9 __FILE__ anchors."""
    sel = sorted((a, n) for reg, a, n in anchors if reg == "arm9_main")
    merged = []
    for a, name in sel:
        if not merged or merged[-1][1] != name:
            merged.append((a, name))
    starts = [a for a, _ in merged]
    groups = {}
    for fn in funcs:
        i = bisect.bisect_right(starts, fn["addr"]) - 1
        if i < 0:
            key = "before first anchor"
        elif i == len(merged) - 1:
            key = "no __FILE__ anchor (0x%08X..)" % merged[i][0]
        else:
            key = merged[i][1]
        groups.setdefault(key, []).append(fn)
    return groups


def listing_labels(path):
    """([(address, name)], span_end) for one listing, address-ordered."""
    base = None
    span_end = 0
    out = []
    pending = None
    with open(path, encoding="utf-8", errors="replace") as fh:
        for line in fh:
            if base is None:
                m = HDR_RANGE.search(line)
                if m:
                    base = int(m.group(1), 16)
                    span_end = int(m.group(2), 16)
            if pending:
                m = INSN.search(line)
                if m:
                    out.append((int(m.group(1), 16), pending)); pending = None; continue
                m = ORG.match(line)
                if m and base is not None:
                    out.append((base + int(m.group(1), 16), pending)); pending = None; continue
            m = LABEL.match(line)
            if m:
                # Only function labels bound an extent: the listings carry internal branch
                # labels (loc_) and pool labels (pool_) inside a function, and sizing to the
                # next label of any kind truncates most functions.
                pending = m.group(1) if FUNCNAME.match(m.group(1)) else None
                continue
            m = INSN.search(line)
            if m:
                continue
    out.sort()
    return out, span_end


def shard_status(region):
    """{name: status} for every function in one region's shards."""
    entries = {}
    for shard in glob.glob(os.path.join(ROOT, "layout", "matched", region, "pkt_*.json")):
        try:
            d = json.load(open(shard, encoding="utf-8"))
        except Exception:
            continue
        for f in d.get("functions", []):
            if isinstance(f, dict) and f.get("name"):
                entries[f["name"]] = f.get("status", "")
    return entries


_SDK = {}


def sdk_addrs(region):
    """{address} of catalogued SDK symbol starts for one overlay region."""
    if not _SDK:
        p = os.path.join(ROOT, "layout", "symbols_sdk.json")
        if os.path.exists(p):
            for e in json.load(open(p, encoding="utf-8")).get("symbols", []):
                _SDK.setdefault(str(e.get("region")), set()).add(int(e["address"]))
        _SDK["__loaded__"] = set()
    return _SDK.get(region, set())


def overlay_functions():
    """Every traced function in every overlay listing, sized to the next label.

    A function whose start is a catalogued SDK symbol is SDK code: matched SDK
    when a shard reproduces it, plain SDK otherwise.  Everything else is game.
    """
    funcs = []
    for path in sorted(glob.glob(os.path.join(ROOT, "asm", "overlays", "ov*.s"))):
        region = os.path.basename(path)[:-2]
        if not region[2:].isdigit():
            continue
        labels, span_end = listing_labels(path)
        entries = shard_status(region)
        sdk = sdk_addrs(region)
        for i, (addr, name) in enumerate(labels):
            if not FUNCNAME.match(name):
                continue
            end = labels[i + 1][0] if i + 1 < len(labels) else span_end
            size = end - addr
            if size <= 0:
                continue
            status = entries.get(name, "")
            exact = status.startswith(("EXACT", "EXACT*"))
            if addr in sdk:
                cls = "matched_sdk" if exact else "sdk"
            else:
                cls = "matched" if exact else "open"
            funcs.append({"addr": addr, "name": name, "code_bytes": size, "region": region,
                          "cls": cls, "sole_ref": False})
    return funcs


def panel(o, groups, y0, W, H):
    """Draw one treemap panel of groups (list of (label, [fn])) into o, between y0 and y0+H."""
    items = sorted(((sum(f["code_bytes"] for f in fns), i) for i, (_, fns) in enumerate(groups) if fns), reverse=True)
    for ux, uy, uw, uh, i in squarify(items, 0, y0, W, H):
        label, fns = groups[i]
        ug = sum(f["code_bytes"] for f in fns if f["cls"] in ("open", "matched"))
        um = sum(f["code_bytes"] for f in fns if f["cls"] == "matched")
        lab = 14 if uw > 70 and uh > 26 else 0
        fitems = sorted(((f["code_bytes"], f) for f in fns), key=lambda t: -t[0])
        for fx, fy, fw, fh, f in squarify(fitems, ux + 2, uy + 2 + lab, uw - 4, uh - 4 - lab):
            if fw < 1.2 or fh < 1.2:
                continue
            k = f["cls"]
            if k == "matched":
                k = "sole" if f.get("sole_ref") else ("matched" if f["addr"] & 4 else "matched2")
            elif k == "open":
                k = "open" if f["addr"] & 4 else "open2"
            o.append('<rect x="%.1f" y="%.1f" width="%.1f" height="%.1f" fill="%s"/>'
                     % (fx + 0.3, fy + 0.3, max(fw - 0.6, 0.3), max(fh - 0.6, 0.3), COL[k]))
        o.append('<rect x="%.1f" y="%.1f" width="%.1f" height="%.1f" fill="none" stroke="%s" stroke-width="2"/>'
                 % (ux + 1, uy + 1, uw - 2, uh - 2, COL["line"]))
        if lab:
            text = "%s %d%%" % (label, round(100 * um / ug) if ug else 0)
            o.append('<text x="%.1f" y="%.1f" font-size="10" fill="%s">%s</text>'
                     % (ux + 5, uy + 12, COL["ink"], esc(text[:max(int((uw - 8) / 6.2), 4)])))


def esc(s):
    return s.replace("&", "&amp;").replace("<", "&lt;")


def render(out, headline, panel_titles, groups_pair, footnote, W, PH):
    """One SVG: headline, legend, then two titled panels stacked."""
    top, tith, gap, foot = 54, 20, 8, 20
    n = len(panel_titles)
    H = top + n * tith + n * PH + (n - 1) * gap + foot
    o = ['<svg xmlns="http://www.w3.org/2000/svg" width="%d" height="%d" viewBox="0 0 %d %d" font-family="ui-monospace,Menlo,monospace">' % (W, H, W, H),
         '<rect width="%d" height="%d" fill="%s"/>' % (W, H, COL["bg"]),
         '<text x="10" y="20" font-size="14" fill="%s">%s</text>' % (COL["ink"], esc(headline))]
    # legend on the line below the title, right-aligned
    lx = W - 10
    for label, key in (("runtime", "runtime"), ("SDK", "sdk"), ("matched SDK", "matched_sdk"),
                       ("open", "open"), ("sole-ref", "sole"), ("matched", "matched")):
        lx -= 8 * len(label) + 26
        o.append('<rect x="%d" y="31" width="11" height="11" fill="%s"/><text x="%d" y="41" font-size="11" fill="%s">%s</text>'
                 % (lx, COL[key], lx + 15, COL["muted"], label))
    for i, (title, groups) in enumerate(zip(panel_titles, groups_pair)):
        y = top + i * (tith + PH + gap)
        o.append('<text x="10" y="%d" font-size="11" fill="%s">%s</text>' % (y + 14, COL["title"], esc(title)))
        panel(o, groups, y + tith, W, PH)
    o.append('<text x="10" y="%d" font-size="10" fill="%s">%s</text>' % (H - 6, COL["muted"], esc(footnote)))
    o.append("</svg>")
    with open(out, "w", encoding="utf-8") as fh:
        fh.write("\n".join(o))
    return len(groups_pair)


def render_arm9(a, anchors):
    inv = worklist.build_inventory()
    # An SDK row that a manifest entry covers (sdk_calibration, or a matched
    # entry at an SDK address) is matched SDK, not plain SDK.
    for fn in inv["funcs"]:
        if fn.get("cls") == "sdk" and fn.get("matched_name"):
            fn["cls"] = "matched_sdk"
    units = json.load(open(os.path.join(ROOT, "layout", "units_arm9.json")))["units"]
    ub = [u["base"] for u in units]
    per = [[] for _ in units]
    for fn in inv["funcs"]:
        if fn["code_bytes"] <= 0:
            continue
        per[bisect.bisect_right(ub, fn["addr"]) - 1].append(fn)
    game = sum(f["code_bytes"] for f in inv["funcs"] if f["cls"] in ("open", "matched"))
    matched = sum(f["code_bytes"] for f in inv["funcs"] if f["cls"] == "matched")
    sole = sum(f["code_bytes"] for f in inv["funcs"] if f.get("sole_ref"))
    sdk = sum(f["code_bytes"] for f in inv["funcs"] if f["cls"] in ("sdk", "matched_sdk"))
    matched_sdk = sum(f["code_bytes"] for f in inv["funcs"] if f["cls"] == "matched_sdk")
    ugroups = [(units[i]["file"].split("/")[-1][:-2], per[i]) for i in range(len(units))]
    fgroups = sorted(families_arm9(inv["funcs"], anchors).items())
    headline = "ARM9: %.2f%% exact game (%s / %s B; %.2f pts sole-ref); +%s matched SDK of %s" % (
        100 * matched / game, format(matched, ","), format(game, ","), 100 * sole / game,
        format(matched_sdk, ","), format(sdk, ","))
    render(a.arm9_out, headline, ("translation units", "source files"), [ugroups, fgroups],
           "tile area is code bytes", a.width, a.height)
    print("wrote %s: %d units + %d source-file groups, %.2f%% exact"
          % (os.path.relpath(a.arm9_out, ROOT), len(ugroups), len(fgroups), 100 * matched / game))


def render_overlays(a, anchors):
    funcs = overlay_functions()
    drawn = sum(f["code_bytes"] for f in funcs)
    matched = sum(f["code_bytes"] for f in funcs if f["cls"] == "matched")
    mfuncs = len([f for f in funcs if f["cls"] == "matched"])
    # Denominator is game code only: each listing's header code minus the catalogued SDK
    # symbol bytes (ovstats does the same split).  SDK and matched-SDK blocks are drawn but
    # never counted as game work.
    rows = ovstats.overlay_rows()
    game = sum(r["game_bytes"] for r in rows)
    matched_game = sum(r["matched_bytes"] for r in rows)
    matched_sdk = sum(r["matched_sdk_bytes"] for r in rows)
    sdk = sum(r["sdk_bytes"] for r in rows)
    regions = {}
    for f in funcs:
        regions.setdefault(f["region"], []).append(f)
    ugroups = sorted(regions.items())
    fgroups = []
    for reg, fns in ugroups:
        tok = "overlay_" + reg[2:]
        fam = _group_by_anchor(fns, anchors, lambda r, tok=tok: r == tok, "%s (no __FILE__ anchor)" % reg)
        for name, ff in fam.items():
            fgroups.append(("%s %s" % (reg, name), ff))
    fgroups.sort(key=lambda kv: -sum(f["code_bytes"] for f in kv[1]))
    headline = "Overlays: %.2f%% exact game (%s / %s B); +%s matched SDK of %s; %d/%d fns" % (
        100.0 * matched_game / game if game else 0.0, format(matched_game, ","), format(game, ","),
        format(matched_sdk, ","), format(sdk, ","), mfuncs, len(funcs))
    render(a.ov_out, headline, ("overlays", "source files"), [ugroups, fgroups],
           "tile area is code bytes; SDK and matched SDK are not game work", a.width, a.height)
    print("wrote %s: %d overlays, %d functions, %d bytes drawn, %.4f%% exact game of %d game bytes (+%d matched SDK of %d SDK)"
          % (os.path.relpath(a.ov_out, ROOT), len(ugroups), len(funcs), drawn,
             100.0 * matched_game / game if game else 0.0, game, matched_sdk, sdk))


# The always-resident ARM9 static image and the 237 overlays have their own maps.
# What is left is the DSi-mode `twl` region and the four ARM9 autoload blocks
# (ITCM plus the two MAIN_TWL stubs and VRAM_LCDC); they are code, they are not
# in either other map, and they need one of their own to be tracked at all.
AUX_REGIONS = [
    ("twl", "asm/twl/twl.s"),
    ("arm9_autoload0_ITCM", "asm/arm9/itcm.s"),
    ("arm9_autoload1_MAIN_TWL", "asm/arm9/autoload1_main_twl.s"),
    ("arm9_autoload2_MAIN_TWL", "asm/arm9/autoload2_main_twl.s"),
    ("arm9_autoload3_VRAM_LCDC", "asm/arm9/vram_lcdc.s"),
]


def aux_shard_status(region):
    """{name: status} for one aux region, whose shards live under itself or arm9/."""
    out = {}
    files = []
    d = os.path.join(ROOT, "layout", "matched", region)
    if os.path.isdir(d):
        files += glob.glob(os.path.join(d, "*.json"))
    files += glob.glob(os.path.join(ROOT, "layout", "matched", "arm9", "pkt_*.json"))
    for sh in files:
        try:
            data = json.load(open(sh, encoding="utf-8"))
        except Exception:
            continue
        for f in data.get("functions", []):
            if isinstance(f, dict) and f.get("name") and str(f.get("region")) == region:
                out[f["name"]] = f.get("status", "")
    return out


def aux_functions():
    funcs = []
    for region, rel in AUX_REGIONS:
        path = os.path.join(ROOT, rel)
        if not os.path.exists(path):
            continue
        head = "".join(open(path, encoding="utf-8", errors="replace").readlines()[:18])
        mr = HDR_RANGE.search(head); mc = HDR_CODE.search(head)
        code = int(mc.group(1), 16) if mc else 0
        code_end = (int(mr.group(1), 16) + code) if mr else 0
        labels, span_end = listing_labels(path)
        labels = [(a, n) for a, n in labels if a < code_end]
        entries = aux_shard_status(region)
        sdk = sdk_addrs(region)
        for i, (addr, name) in enumerate(labels):
            if not FUNCNAME.match(name):
                continue
            end = labels[i + 1][0] if i + 1 < len(labels) else code_end
            end = min(end, code_end)
            size = end - addr
            if size <= 0:
                continue
            st = entries.get(name, "")
            exact = st.startswith(("EXACT", "EXACT*"))
            if addr in sdk:
                cls = "matched_sdk" if exact else "sdk"
            else:
                cls = "matched" if exact else "open"
            funcs.append({"addr": addr, "name": name, "code_bytes": size, "region": region,
                          "cls": cls, "sole_ref": False})
    return funcs


def render_aux(a):
    funcs = aux_functions()
    drawn = sum(f["code_bytes"] for f in funcs)
    regions = {}
    for f in funcs:
        regions.setdefault(f["region"], []).append(f)
    ugroups = sorted(regions.items())
    game = sum(f["code_bytes"] for f in funcs if f["cls"] in ("open", "matched"))
    matched = sum(f["code_bytes"] for f in funcs if f["cls"] == "matched")
    matched_sdk = sum(f["code_bytes"] for f in funcs if f["cls"] == "matched_sdk")
    sdk = sum(f["code_bytes"] for f in funcs if f["cls"] in ("sdk", "matched_sdk"))
    headline = "TWL / ITCM / autoload: %.2f%% exact game (%s / %s B); +%s matched SDK of %s; %d fns" % (
        100.0 * matched / game if game else 0.0, format(matched, ","), format(game, ","),
        format(matched_sdk, ","), format(sdk, ","), len(funcs))
    render(a.twl_out, headline, ("regions",), [ugroups],
           "tile area is code bytes; the DSi twl region and the ARM9 autoload blocks", a.width, a.height)
    print("wrote %s: %d regions, %d functions, %d bytes drawn, %.2f%% exact game of %d (+%d matched SDK of %d)"
          % (os.path.relpath(a.twl_out, ROOT), len(ugroups), len(funcs), drawn,
             100.0 * matched / game if game else 0.0, game, matched_sdk, sdk))


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--out", default=os.path.join(ROOT, "docs", "coverage_map.svg"))
    ap.add_argument("--width", type=int, default=1200)
    ap.add_argument("--height", type=int, default=520)
    ap.add_argument("--arm9", action="store_true", help="write the ARM9 image only")
    ap.add_argument("--overlays", action="store_true", help="write the overlay image only")
    ap.add_argument("--twl", action="store_true", help="write the twl/ITCM/autoload image only")
    a = ap.parse_args(argv)
    a.arm9_out = a.out
    a.ov_out = os.path.join(ROOT, "docs", "coverage_overlays.svg")
    a.twl_out = os.path.join(ROOT, "docs", "coverage_twl.svg")
    anchors = read_anchors()
    do_all = not (a.arm9 or a.overlays or a.twl)
    if do_all or a.overlays:
        render_overlays(a, anchors)
    if do_all or a.arm9:
        render_arm9(a, anchors)
    if do_all or a.twl:
        render_aux(a)


if __name__ == "__main__":
    main()
