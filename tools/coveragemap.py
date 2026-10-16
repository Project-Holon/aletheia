#!/usr/bin/env python3
"""Render the coverage treemaps as one fused SVG per subject.

Two subjects, each one image with two panels stacked (group view above, original-source-file
view below) and a small title on each panel:

  docs/coverage_overlays.svg   the 237 overlays, one block per overlay, functions inside
  docs/coverage_map.svg        the ARM9 static image, one block per translation unit

Tile area is code bytes. Colours: matched exact, matched resting on sole-ref, register
mismatch (counted, to be finished: layout/register_mismatch.txt), open, placeholder (an
EXACT entry whose source holds no code, tools/placeholders.py: counted as unmatched),
SDK (excluded), runtime (excluded). Only addresses, sizes and names are drawn; no game bytes.

Usage:
    python3 tools/coveragemap.py                 both images
    python3 tools/coveragemap.py --arm9          docs/coverage_map.svg only
    python3 tools/coveragemap.py --overlays      docs/coverage_overlays.svg only
"""
import argparse
import bisect
import glob
import itertools
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import worklist  # noqa: E402
import ovstats  # noqa: E402
import regmismatch  # noqa: E402  (layout/register_mismatch.txt)
import placeholders  # noqa: E402  (EXACT entries whose source holds no code)
import fnaddr  # noqa: E402  (function addresses whatever the name)

# One palette per map, after the three legendaries of Pokemon Black and White:
# Reshiram (white, flame) for the ARM9 map, Zekrom (electric blue, near black,
# red eye) for the overlays, Kyurem (ice, yellow) for twl.  set_palette() picks
# one before a map is drawn; COL is the palette in use.
PALETTES = {
    "arm9": {"matched": "#eef1f5", "matched2": "#dfe3e8", "sole": "#f6cfb4", "open": "#36343a", "open2": "#3e3b41",
             "sdk": "#2e2623", "matched_sdk": "#ff8a3d", "runtime": "#33301f", "matched_runtime": "#f5c86a",
             "regmm": "#d9304a", "placeholder": "#b04fd0", "placeholder_sdk": "#6b3a7a",
             "bg": "#1a1817", "line": "#0f0e0d",
             "ink": "#f4f2ef", "muted": "#a39d96", "title": "#e2ddd6"},
    "overlays": {"matched": "#1e9bff", "matched2": "#45b0ff", "sole": "#bfe4ff", "open": "#25282e", "open2": "#2c3037",
                 "sdk": "#211f2e", "matched_sdk": "#0f1e4d", "runtime": "#1b2a30", "matched_runtime": "#3ee6ff",
                 "regmm": "#e5303a", "placeholder": "#c45cff", "placeholder_sdk": "#5e2f80",
                 "bg": "#0e0f12", "line": "#060708",
                 "ink": "#e4e8ee", "muted": "#7d8592", "title": "#c3cad4"},
    "twl": {"matched": "#7fd0e6", "matched2": "#9ddcee", "sole": "#cdebf3", "open": "#323a40", "open2": "#3a434a",
            "sdk": "#232b33", "matched_sdk": "#5d86b0", "runtime": "#2d3338", "matched_runtime": "#c7d3dc",
            "regmm": "#f2cf3a", "placeholder": "#d070e0", "placeholder_sdk": "#6e3a78",
            "bg": "#161b1f", "line": "#0c0f11",
            "ink": "#e3edf2", "muted": "#8d9ba5", "title": "#c8d6de"},
}
COL = dict(PALETTES["arm9"])


def set_palette(name):
    COL.clear()
    COL.update(PALETTES[name])


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
        # A region with no __FILE__ anchor is one group; returning {} dropped its
        # functions from the source-file panel and left empty holes there.
        return {tail_key: list(funcs)} if funcs else {}
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


def regmm_note(nbytes):
    return (" (incl. %s bytes register mismatch)" % format(nbytes, ",")) if nbytes else ""


def placeholder_note(nbytes, sdk_bytes=0):
    """Headline note for placeholder bytes (unmatched; tools/placeholders.py)."""
    parts = []
    if nbytes:
        parts.append("%s B game placeholder" % format(nbytes, ","))
    if sdk_bytes:
        parts.append("%s B SDK placeholder" % format(sdk_bytes, ","))
    return (" [%s, unmatched]" % ", ".join(parts)) if parts else ""


def apply_regmm(funcs, regions):
    """Mark the register-mismatch rows of `regions` in a tile list.

    A row whose function already has a tile (a listing label) is reclassified, which also
    takes it out of matched; a row the listing does not label is added as a new tile and
    reported, so the denominator grows by its bytes.  Returns the list of added rows.
    """
    by_addr = {}
    for f in funcs:
        by_addr.setdefault((f["region"], f["addr"]), f)
    added = []
    for e in regmismatch.sizes():
        if e["region"] not in regions:
            continue
        f = by_addr.get((e["region"], e["addr"]))
        if f is not None:
            if f["cls"] in ("sdk", "matched_sdk"):
                continue
            f["cls"] = "regmm"
        else:
            funcs.append({"addr": e["addr"], "name": e["name"], "code_bytes": e["size"],
                          "region": e["region"], "cls": "regmm", "sole_ref": False})
            added.append(e)
            print("coveragemap: register mismatch %s %08X is not a label in the %s listing; "
                  "added %d bytes to the denominator" % (e["name"], e["addr"], e["region"], e["size"]))
    return added


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
                m = INSN.search(line) if "/*" in line else None
                if m:
                    out.append((int(m.group(1), 16), pending)); pending = None; continue
                m = ORG.match(line)
                if m and base is not None:
                    out.append((base + int(m.group(1), 16), pending)); pending = None; continue
            c = line[:1]
            if c == "_" or c.isalpha():
                m = LABEL.match(line)
                if m:
                    # Only function labels bound an extent: the listings carry internal branch
                    # labels (loc_) and pool labels (pool_) inside a function, and sizing to the
                    # next label of any kind truncates most functions.
                    pending = m.group(1) if FUNCNAME.match(m.group(1)) else None
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
    """{address} of catalogue SDK symbol starts for one region.

    The union of libmatch.py's catalog and tools/sdkclass.py's placement
    scan, so a region whose library member the catalog never listed (the
    whole DSi `twl` block) still classifies as SDK.
    """
    if not _SDK:
        sys.path.insert(0, os.path.join(ROOT, "tools"))
        import sdkclass
        for reg, d in sdkclass.union().items():
            _SDK.setdefault(reg, set()).update(d)
        _SDK["__loaded__"] = set()
    return _SDK.get(region, set())


def overlay_functions():
    """Every traced function in every overlay listing, sized by its instruction bytes.

    A function whose start is a catalogued SDK symbol is SDK code: matched SDK
    when a shard reproduces it, plain SDK otherwise.  Everything else is game.
    Labels, extents and the matched set come from tools/ovstats.py (entries keyed
    by address, an address counting only when it is a function label in its own
    listing), so the matched tiles add up to ovstats' matched bytes exactly.
    """
    funcs = []
    for path in sorted(glob.glob(os.path.join(ROOT, "asm", "overlays", "ov*.s"))):
        region = os.path.basename(path)[:-2]
        if not region[2:].isdigit():
            continue
        head = "".join(open(path, encoding="utf-8", errors="replace").readlines()[:18])
        m_range = HDR_RANGE.search(head)
        span_end = int(m_range.group(2), 16) if m_range else 0
        labels = ovstats.listing_labels(path)
        by_label = {}
        for a, name in labels:
            by_label.setdefault(name, a)
        matched, _uncounted = ovstats.matched_addresses(region, [a for a, _ in labels], by_label)
        sdk = sdk_addrs(region)
        code = ovstats.function_code_bytes(path, [a for a, _ in labels])
        seen = set()
        for addr, name in labels:
            # tiles are sized by instruction bytes, the measure ovstats and arm9 use
            if addr in seen:
                continue
            seen.add(addr)
            size = code[addr]
            if size <= 0:
                continue
            exact = addr in matched
            if addr in sdk:
                cls = "matched_sdk" if exact else "sdk"
            else:
                cls = "matched" if exact else "open"
            funcs.append({"addr": addr, "name": name, "code_bytes": size, "region": region,
                          "cls": cls, "sole_ref": False})
    return funcs


# Smallest tile drawn on its own, in square pixels.  Functions below it are pooled per
# colour into one tile, so every tile keeps the same inset and spacing; open (unmatched)
# functions are never pooled, so they always stay visible.
MIN_TILE_AREA = 6.0


def _tile_key(f):
    k = f["cls"]
    if k == "matched":
        return "sole" if f.get("sole_ref") else ("matched" if f["addr"] & 4 else "matched2")
    if k == "open":
        return "open" if f["addr"] & 4 else "open2"
    return k


def _unit_tiles(fns, ux, uy, uw, uh):
    """Tiles (x, y, w, h, colour key) for one unit drawn inside its 2-pixel border."""
    pad = 2 if uw > 6 and uh > 6 else 0
    x, y, w, h = ux + pad, uy + pad, uw - 2 * pad, uh - 2 * pad
    total = sum(f["code_bytes"] for f in fns)
    if w <= 0 or h <= 0 or not total:
        return []
    scale = w * h / total
    keep, pooled = [], {}
    for f in fns:
        k = _tile_key(f)
        if f["code_bytes"] * scale >= MIN_TILE_AREA or f["cls"] in ("open", "regmm", "placeholder", "placeholder_sdk"):
            keep.append((f["code_bytes"], k))
        else:
            pooled[k] = pooled.get(k, 0) + f["code_bytes"]
    items = sorted(keep + [(v, k) for k, v in pooled.items()], key=lambda t: -t[0])
    return squarify(items, x, y, w, h)


def panel(o, groups, y0, W, H):
    """Draw one treemap panel of groups (list of (label, [fn])) into o, between y0 and y0+H."""
    items = sorted(((sum(f["code_bytes"] for f in fns), i) for i, (_, fns) in enumerate(groups) if fns), reverse=True)
    for ux, uy, uw, uh, i in squarify(items, 0, y0, W, H):
        label, fns = groups[i]
        ug = sum(f["code_bytes"] for f in fns if f["cls"] in ("open", "matched", "regmm", "placeholder"))
        um = sum(f["code_bytes"] for f in fns if f["cls"] in ("matched", "regmm"))
        lab = 14 if uw > 70 and uh > 26 else 0
        tiles = _unit_tiles(fns, ux, uy + lab, uw, uh - lab)
        for fx, fy, fw, fh, k in tiles:
            o.append('<rect x="%.1f" y="%.1f" width="%.1f" height="%.1f" fill="%s"/>'
                     % (fx + 0.3, fy + 0.3, max(fw - 0.6, 0.3), max(fh - 0.6, 0.3), COL[k]))
        o.append('<rect x="%.1f" y="%.1f" width="%.1f" height="%.1f" fill="none" stroke="%s" stroke-width="2"/>'
                 % (ux + 1, uy + 1, uw - 2, uh - 2, COL["line"]))
        if lab:
            # a unit with no game bytes (all SDK or runtime) has no game percentage
            text = ("%s %d%%" % (label, round(100 * um / ug))) if ug else ("%s SDK" % label)
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
    # legend on the line below the title, right-aligned, showing only categories present in this map
    present_keys = set()
    for groups in groups_pair:
        for _, fns in groups:
            for f in fns:
                cls = f.get("cls")
                if f.get("sole_ref") and cls == "matched":
                    present_keys.add("sole")
                elif cls:
                    present_keys.add(cls)

    all_legend = [("runtime", "runtime"), ("matched runtime", "matched_runtime"),
                  ("SDK", "sdk"), ("matched SDK", "matched_sdk"), ("SDK placeholder", "placeholder_sdk"),
                  ("open", "open"), ("placeholder", "placeholder"), ("register mismatch", "regmm"),
                  ("sole-ref", "sole"), ("matched", "matched")]
    legend_items = [(label, key) for label, key in all_legend if key in present_keys]

    lx = W - 10
    for label, key in legend_items:
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
    set_palette("arm9")
    inv = worklist.build_inventory()
    thunks = {t["addr"] for t in inv.get("thunks", [])}
    for fn in inv["funcs"]:
        if fn.get("cls") == "sdk" and fn.get("matched_name"):
            fn["cls"] = "matched_sdk"
        if fn.get("cls") == "runtime" and fn.get("matched_name"):
            fn["cls"] = "matched_runtime"
        if fn.get("cls") == "sdk" and fn.get("placeholder"):
            fn["cls"] = "placeholder_sdk"    # worklist gave it no matched_name
        # an `open` function stays open: the caption must equal worklist's
    for e in regmismatch.sizes():       # no arm9 row exists today; supported when one is added
        if e["region"].startswith("arm9"):
            for fn in inv["funcs"]:
                if fn["addr"] == e["addr"] and fn.get("cls") in ("open", "matched"):
                    fn["cls"] = "regmm"
    units = json.load(open(os.path.join(ROOT, "layout", "units_arm9.json")))["units"]
    ub = [u["base"] for u in units]
    per = [[] for _ in units]
    for fn in inv["funcs"]:
        if fn["code_bytes"] <= 0:
            continue
        per[bisect.bisect_right(ub, fn["addr"]) - 1].append(fn)
    game = sum(f["code_bytes"] for f in inv["funcs"] if f["cls"] in ("open", "matched", "regmm", "placeholder"))
    regmm = sum(f["code_bytes"] for f in inv["funcs"] if f["cls"] == "regmm")
    matched = sum(f["code_bytes"] for f in inv["funcs"] if f["cls"] in ("matched", "regmm"))
    held = sum(f["code_bytes"] for f in inv["funcs"] if f["cls"] == "placeholder")
    held_sdk = sum(f["code_bytes"] for f in inv["funcs"] if f["cls"] == "placeholder_sdk")
    sole = sum(f["code_bytes"] for f in inv["funcs"] if f.get("sole_ref"))
    sdk = sum(f["code_bytes"] for f in inv["funcs"] if f["cls"] in ("sdk", "matched_sdk", "placeholder_sdk"))
    matched_sdk = sum(f["code_bytes"] for f in inv["funcs"] if f["cls"] == "matched_sdk")
    runtime = sum(f["code_bytes"] for f in inv["funcs"] if f["cls"] in ("runtime", "matched_runtime"))
    matched_runtime = sum(f["code_bytes"] for f in inv["funcs"] if f["cls"] == "matched_runtime")
    # Cross-check the arm9 tiles against ovstats' own arm9 figures, the same way
    # the overlay path checks its tiles against ovstats.overlay_rows: a future
    # disagreement between this inventory and the worklist summary must be a
    # loud failure, not a quietly wrong headline.  ovstats reads the same
    # numbers from layout/worklist.json's summary, so the two must agree.
    a9 = ovstats.arm9_summary()
    if a9:
        ov_game = int(a9.get("code_bytes_game", -1))
        ov_matched = int(a9.get("code_bytes_matched", -1))
        ov_funcs = int(a9.get("functions_matched", -1))
        n_matched = len([f for f in inv["funcs"] if f["cls"] in ("matched", "regmm")])
        if (game, matched, n_matched) != (ov_game, ov_matched, ov_funcs):
            sys.exit("coveragemap: arm9 tiles disagree with ovstats (layout/worklist.json): "
                     "game %d vs %d, matched %d vs %d, matched functions %d vs %d"
                     % (game, ov_game, matched, ov_matched, n_matched, ov_funcs))
    ugroups = [(units[i]["file"].split("/")[-1][:-2], per[i]) for i in range(len(units))]
    fgroups = sorted(families_arm9(inv["funcs"], anchors).items())
    rt_str = ("; +%s matched runtime of %s" % (format(matched_runtime, ","), format(runtime, ","))) if runtime else ""
    headline = "ARM9: %.2f%% exact game (%s / %s B; %.2f pts sole-ref)%s; +%s matched SDK of %s%s%s" % (
        100 * matched / game, format(matched, ","), format(game, ","), 100 * sole / game, regmm_note(regmm),
        format(matched_sdk, ","), format(sdk, ","), rt_str, placeholder_note(held, held_sdk))
    render(a.arm9_out, headline, ("translation units", "source files"), [ugroups, fgroups],
           "tile area is code bytes", a.width, a.height)
    print("wrote %s: %d units + %d source-file groups, %.2f%% exact"
          % (os.path.relpath(a.arm9_out, ROOT), len(ugroups), len(fgroups), 100 * matched / game))


def render_overlays(a, anchors):
    set_palette("overlays")
    # Tiles and totals from one pass over the listings and shards (ovstats.overlay_rows
    # with funcs_out), so a session writing shards meanwhile cannot make them disagree.
    funcs = []
    rows = ovstats.overlay_rows(funcs_out=funcs)
    drawn = sum(f["code_bytes"] for f in funcs)
    matched = sum(f["code_bytes"] for f in funcs if f["cls"] == "matched")
    mfuncs = len([f for f in funcs if f["cls"] == "matched"])
    regmm = sum(f["code_bytes"] for f in funcs if f["cls"] == "regmm")
    rfuncs = len([f for f in funcs if f["cls"] == "regmm"])
    held = sum(f["code_bytes"] for f in funcs if f["cls"] == "placeholder")
    held_sdk = sum(f["code_bytes"] for f in funcs if f["cls"] == "placeholder_sdk")
    if (held, held_sdk) != (sum(r["placeholder_bytes"] for r in rows),
                            sum(r["placeholder_sdk_bytes"] for r in rows)):
        sys.exit("coveragemap: placeholder tiles disagree with ovstats")
    # Denominator is game code only: each listing's header code minus the catalogued SDK
    # symbol bytes (ovstats does the same split).  SDK and matched-SDK blocks are drawn but
    # never counted as game work.
    game = sum(r["game_bytes"] for r in rows)
    matched_game = sum(r["matched_bytes"] for r in rows)
    matched_sdk = sum(r["matched_sdk_bytes"] for r in rows)
    sdk = sum(r["sdk_bytes"] for r in rows)
    tiles_sdk = sum(f["code_bytes"] for f in funcs if f["cls"] == "matched_sdk")
    if regmm != sum(r["regmm_bytes"] for r in rows):
        sys.exit("coveragemap: register-mismatch tiles disagree with ovstats")
    if (matched, tiles_sdk) != (matched_game, matched_sdk):
        sys.exit("coveragemap: overlay tiles disagree with ovstats: matched game %d vs %d, "
                 "matched SDK %d vs %d" % (matched, matched_game, tiles_sdk, matched_sdk))
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
    # Function counts use the same split as the bytes: game functions over game functions,
    # SDK functions over SDK functions (the old single "%d/%d fns" mixed the two).
    gfuncs = len([f for f in funcs if f["cls"] in ("open", "matched", "regmm", "placeholder")])
    sfuncs = len([f for f in funcs if f["cls"] in ("sdk", "matched_sdk", "placeholder_sdk")])
    msfuncs = len([f for f in funcs if f["cls"] == "matched_sdk"])
    headline = ("Overlays: %.2f%% exact game (%s / %s B, %d/%d fns)%s; "
                "+%s matched SDK of %s (%d/%d fns)%s") % (
        100.0 * (matched_game + regmm) / game if game else 0.0, format(matched_game + regmm, ","), format(game, ","),
        mfuncs + rfuncs, gfuncs, regmm_note(regmm), format(matched_sdk, ","), format(sdk, ","), msfuncs, sfuncs,
        placeholder_note(held, held_sdk))
    render(a.ov_out, headline, ("overlays", "source files"), [ugroups, fgroups],
           "tile area is code bytes; SDK and matched SDK are not game work; register mismatch counts toward the percentage", a.width, a.height)
    print("wrote %s: %d overlays, %d functions, %d bytes drawn, %.4f%% exact game of %d game bytes%s (+%d matched SDK of %d SDK)"
          % (os.path.relpath(a.ov_out, ROOT), len(ugroups), len(funcs), drawn,
             100.0 * (matched_game + regmm) / game if game else 0.0, game, regmm_note(regmm), matched_sdk, sdk))


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
        # parsed shards come from match.py's stamp cache (build/cache/shards.pkl)
        data = ovstats.cached_shard_doc(sh)
        if data is None:
            continue
        for f in data.get("functions", []):
            if isinstance(f, dict) and f.get("name") and str(f.get("region")) == region:
                out[f["name"]] = f.get("status", "")
                # also by address: twl shards carry vendor names (AESi_Init) where the
                # listing labels the same address func_027073AC
                try:
                    a = int(str(f.get("address")), 16)
                except ValueError:
                    continue
                if not str(out.get(a, "")).startswith("EXACT"):
                    out[a] = f.get("status", "")
                # a unit's members by address (tools/fnaddr.py), whatever their names
                if str(f.get("kind", "")).endswith("_unit"):
                    for _n, ma in fnaddr.member_addresses(f):
                        if ma is not None and not str(out.get(ma, "")).startswith("EXACT"):
                            out[ma] = f.get("status", "")
    return out


def aux_functions():
    funcs = []
    for region, rel in AUX_REGIONS:
        path = os.path.join(ROOT, rel)
        if not os.path.exists(path):
            continue
        with open(path, encoding="utf-8", errors="replace") as hf:
            head = "".join(itertools.islice(hf, 18))
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
            st = entries.get(addr) or entries.get(name, "")
            exact = st.startswith(("EXACT", "EXACT*"))
            if exact and (placeholders.is_placeholder(region, name)
                          or placeholders.is_placeholder(region, addr)):
                cls = "placeholder_sdk" if addr in sdk else "placeholder"
            elif addr in sdk:
                cls = "matched_sdk" if exact else "sdk"
            else:
                cls = "matched" if exact else "open"
            funcs.append({"addr": addr, "name": name, "code_bytes": size, "region": region,
                          "cls": cls, "sole_ref": False})
    apply_regmm(funcs, {r for r, _ in AUX_REGIONS})
    return funcs


def render_aux(a):
    set_palette("twl")
    funcs = aux_functions()
    drawn = sum(f["code_bytes"] for f in funcs)
    regions = {}
    for f in funcs:
        regions.setdefault(f["region"], []).append(f)
    ugroups = sorted(regions.items())
    game = sum(f["code_bytes"] for f in funcs if f["cls"] in ("open", "matched", "regmm", "placeholder"))
    regmm = sum(f["code_bytes"] for f in funcs if f["cls"] == "regmm")
    matched = sum(f["code_bytes"] for f in funcs if f["cls"] in ("matched", "regmm"))
    matched_sdk = sum(f["code_bytes"] for f in funcs if f["cls"] == "matched_sdk")
    sdk = sum(f["code_bytes"] for f in funcs if f["cls"] in ("sdk", "matched_sdk", "placeholder_sdk"))
    held = sum(f["code_bytes"] for f in funcs if f["cls"] == "placeholder")
    held_sdk = sum(f["code_bytes"] for f in funcs if f["cls"] == "placeholder_sdk")
    # The arm9 and overlay paths cross-check their tiles against ovstats, which
    # covers the overlays and arm9 only: no second tool measures twl, the ITCM
    # autoload or the MAIN_TWL/VRAM_LCDC blocks, so there is no ovstats figure
    # to mirror.  This path instead asserts its own partition, so a class added
    # without updating the sums above fails loudly rather than skewing the
    # headline silently.
    classes = ("open", "matched", "regmm", "placeholder", "sdk", "matched_sdk", "placeholder_sdk", "runtime",
               "matched_runtime")
    by_cls = {}
    for f in funcs:
        if f["cls"] not in classes:
            sys.exit("coveragemap: aux tile %s %08X has unknown class %r" % (f["region"], f["addr"], f["cls"]))
        by_cls[f["cls"]] = by_cls.get(f["cls"], 0) + f["code_bytes"]
    if sum(by_cls.values()) != drawn:
        sys.exit("coveragemap: aux classes do not partition the drawn bytes")
    if (by_cls.get("matched", 0) + by_cls.get("regmm", 0) != matched
            or by_cls.get("matched_sdk", 0) != matched_sdk
            or by_cls.get("open", 0) + by_cls.get("matched", 0) + by_cls.get("regmm", 0)
            + by_cls.get("placeholder", 0) != game):
        sys.exit("coveragemap: aux headline sums disagree with the tile classes")
    headline = "TWL / ITCM / autoload: %.2f%% exact game (%s / %s B)%s; +%s matched SDK of %s; %d fns%s" % (
        100.0 * matched / game if game else 0.0, format(matched, ","), format(game, ","), regmm_note(regmm),
        format(matched_sdk, ","), format(sdk, ","), len(funcs), placeholder_note(held, held_sdk))
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
    ap.add_argument("--ov-out", default=os.path.join(ROOT, "docs", "coverage_overlays.svg"),
                    help="overlay image path (default docs/coverage_overlays.svg)")
    ap.add_argument("--twl-out", default=os.path.join(ROOT, "docs", "coverage_twl.svg"),
                    help="twl/ITCM/autoload image path (default docs/coverage_twl.svg)")
    a = ap.parse_args(argv)
    a.arm9_out = a.out
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
