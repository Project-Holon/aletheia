#!/usr/bin/env python3
"""Render the ARM9 game-code coverage map as an SVG treemap (docs/coverage_map.svg).

Tile area is code bytes. Top level: the translation units of the ARM9 static image
(layout/units_arm9.json), each subdivided into its functions. Colours: matched exact,
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
    W, H, top = a.width, a.height, 34
    esc = lambda s: s.replace("&", "&amp;").replace("<", "&lt;")
    o = ['<svg xmlns="http://www.w3.org/2000/svg" width="%d" height="%d" viewBox="0 0 %d %d" font-family="ui-monospace,Menlo,monospace">' % (W, H, W, H),
         '<rect width="%d" height="%d" fill="%s"/>' % (W, H, COL["bg"]),
         '<text x="10" y="21" font-size="14" fill="%s">ARM9 game code: %.2f%% exact (%s of %s bytes; %.2f points rest on sole-ref)</text>'
         % (COL["ink"], 100 * matched / game, format(matched, ","), format(game, ","), 100 * sole / game)]
    lx = W - 10
    for label, key in (("runtime", "runtime"), ("SDK", "sdk"), ("open", "open"), ("sole-ref", "sole"), ("matched", "matched")):
        lx -= 8 * len(label) + 26
        o.append('<rect x="%d" y="11" width="11" height="11" fill="%s"/><text x="%d" y="21" font-size="11" fill="%s">%s</text>'
                 % (lx, COL[key], lx + 15, COL["muted"], label))
    items = sorted(((sum(f["code_bytes"] for f in fns), i) for i, fns in enumerate(per) if fns), reverse=True)
    for ux, uy, uw, uh, i in squarify(items, 0, top, W, H - top):
        fns = per[i]
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
            o.append('<text x="%.1f" y="%.1f" font-size="10" fill="%s">%s %d%%</text>'
                     % (ux + 5, uy + 12, COL["ink"], esc(units[i]["file"].split("/")[-1][:-2]), round(100 * um / ug) if ug else 0))
    o.append("</svg>")
    with open(a.out, "w", encoding="utf-8") as fh:
        fh.write("\n".join(o))
    print("wrote %s: %d units, %d functions, %.2f%% exact" % (os.path.relpath(a.out, ROOT), len(items), sum(len(p) for p in per), 100 * matched / game))


if __name__ == "__main__":
    main()
