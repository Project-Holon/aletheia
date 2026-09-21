#!/usr/bin/env python3
"""Render the ARM9 game-code coverage map as two SVG treemaps (docs/coverage_map.svg,
docs/coverage_map_files.svg).

Tile area is code bytes. Blocks: the translation units of the ARM9 static image
(layout/units_arm9.json), then the same functions grouped by original source file
(layout/file_anchors.txt); each block subdivided into its functions. Colours: matched exact,
matched resting on sole-ref, open, SDK (excluded), runtime (excluded). Only addresses,
sizes and names are drawn; no game bytes.

Usage: python3 tools/coveragemap.py [-o docs/coverage_map.svg] [--width 1200] [--height 640]
"""
import argparse, bisect, json, os, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import worklist  # noqa: E402

COL = {"matched": "#2f9e5b", "matched2": "#3fb96e", "sole": "#8fd3a8", "open": "#34393b", "open2": "#3d4245",
       "sdk": "#262b30", "runtime": "#3a3629", "bg": "#15181a", "line": "#0d0f10", "ink": "#e6e9e6", "muted": "#8f978f"}


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


def families(funcs):
    """Group functions by original source file, inferred from the __FILE__ anchors in
    layout/file_anchors.txt: the image was linked file after file, so every function from one
    file's anchored function up to the next file's anchored function is attributed to the first
    file (edges are fuzzy by a few functions). Functions past the last anchor form one block."""
    anch = []
    for ln in open(os.path.join(ROOT, "layout", "file_anchors.txt")):
        p = ln.split()
        if ln.startswith("#") or len(p) < 5 or p[2] != "arm9_main":
            continue
        anch.append((int(p[1], 16), p[4]))
    anch.sort()
    merged = []
    for a, name in anch:
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


def panel(o, groups, labels, y0, W, H):
    """Draw one treemap panel of groups (list of (label, [fn])) into rows o, between y0 and y0+H."""
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
        o.append('<rect x="%.1f" y="%.1f" width="%.1f" height="%.1f" fill="none" stroke="%s" stroke-width="2"/>' % (ux + 1, uy + 1, uw - 2, uh - 2, COL["line"]))
        if lab:
            text = "%s %d%%" % (label, round(100 * um / ug) if ug else 0)
            o.append('<text x="%.1f" y="%.1f" font-size="10" fill="%s">%s</text>'
                     % (ux + 5, uy + 12, COL["ink"], esc(text[:max(int((uw - 8) / 6.2), 4)])))


def esc(s):
    return s.replace("&", "&amp;").replace("<", "&lt;")


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--out", default=os.path.join(ROOT, "docs", "coverage_map.svg"))
    ap.add_argument("--width", type=int, default=1200)
    ap.add_argument("--height", type=int, default=640)
    a = ap.parse_args(argv)
    inv = worklist.build_inventory()
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
    W, PH, top = a.width, a.height, 34
    H = top + PH + 18
    fam = families(inv["funcs"])
    ugroups = [(units[i]["file"].split("/")[-1][:-2], per[i]) for i in range(len(units))]
    views = ((a.out, "translation unit of the split ARM9 image", ugroups),
             (a.out[:-4] + "_files.svg" if a.out.endswith(".svg") else a.out + ".files.svg",
              "original source file (__FILE__ anchors; the upper half of the image has no anchors and is one block)", sorted(fam.items())))
    for out, what, groups in views:
        o = ['<svg xmlns="http://www.w3.org/2000/svg" width="%d" height="%d" viewBox="0 0 %d %d" font-family="ui-monospace,Menlo,monospace">' % (W, H, W, H),
             '<rect width="%d" height="%d" fill="%s"/>' % (W, H, COL["bg"]),
             '<text x="10" y="21" font-size="14" fill="%s">ARM9 game code: %.2f%% exact (%s of %s bytes; %.2f points rest on sole-ref)</text>'
             % (COL["ink"], 100 * matched / game, format(matched, ","), format(game, ","), 100 * sole / game)]
        lx = W - 10
        for label, key in (("runtime", "runtime"), ("SDK", "sdk"), ("open", "open"), ("sole-ref", "sole"), ("matched", "matched")):
            lx -= 8 * len(label) + 26
            o.append('<rect x="%d" y="11" width="11" height="11" fill="%s"/><text x="%d" y="21" font-size="11" fill="%s">%s</text>'
                     % (lx, COL[key], lx + 15, COL["muted"], label))
        panel(o, groups, None, top, W, PH)
        o.append('<text x="10" y="%d" font-size="10" fill="%s">blocks: %s</text>' % (H - 5, COL["muted"], esc(what)))
        o.append("</svg>")
        with open(out, "w", encoding="utf-8") as fh:
            fh.write("\n".join(o))
        print("wrote %s: %d blocks, %d functions, %.2f%% exact" % (os.path.relpath(out, ROOT), len(groups), sum(len(g) for _, g in groups), 100 * matched / game))


if __name__ == "__main__":
    main()
