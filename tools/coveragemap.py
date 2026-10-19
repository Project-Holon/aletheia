#!/usr/bin/env python3
"""Render the coverage treemaps, one SVG per region plus one combined image.

  docs/coverage_map.svg        ARM9 main binary, one block per src/game file
  docs/coverage_overlays.svg   the overlays, one block per overlay holding its src/game files
  docs/coverage_twl.svg        DSi (TWL) and the ARM9 autoload blocks
  docs/coverage_all.svg        every region in one image, each with its own palette

Files come from progress/report.json (one unit per src/game file, by function address).
Tile area is code bytes. Only addresses, sizes and names are drawn; no game bytes.

Usage:
    python3 tools/coveragemap.py                 all four images
    python3 tools/coveragemap.py --arm9 | --overlays | --twl | --all
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



def esc(s):
    return s.replace("&", "&amp;").replace("<", "&lt;")


FONT = "system-ui, -apple-system, 'Segoe UI', sans-serif"
GAME = ("open", "matched", "regmm", "placeholder")
SDKC = ("sdk", "matched_sdk", "placeholder_sdk")


def hundredths(frac):
    """Percentage text with one decimal, never rounded up to 100.0 while bytes are missing."""
    p = int(frac * 1000 + 1e-9) / 10.0 if frac < 1 else 100.0
    return "%.1f%%" % p


def unit_index():
    """{(module, address): file stem} from progress/report.json (one unit per src/game file)."""
    path = os.path.join(ROOT, "progress", "report.json")
    idx = {}
    if not os.path.exists(path):
        return idx
    for u in json.load(open(path, encoding="utf-8"))["units"]:
        mod = u.get("metadata", {}).get("module_name", "")
        stem = u["name"].split("/", 1)[-1]
        for f in u.get("functions", []):
            idx[(mod, int(f["metadata"]["virtual_address"]))] = stem
    return idx


def file_groups(funcs, module_of, idx):
    """{module: {file label: [fn]}} for a tile list, by the src/game file that holds each function."""
    out = {}
    lost = 0
    for f in funcs:
        mod = module_of(f)
        stem = idx.get((mod, f["addr"]))
        if stem is None:
            label = "linker veneers"
            lost += f["code_bytes"]
        else:
            label = stem + ".c"
        out.setdefault(mod, {}).setdefault(label, []).append(f)
    if lost:
        print("coveragemap: %d bytes have no src/game file in progress/report.json" % lost)
    return out


class Canvas:
    """Collects tiles and outlines as one path per colour, so the SVG stays small."""

    def __init__(self):
        self.fill = {}
        self.line = {}
        self.text = []

    def rect(self, x, y, w, h, colour):
        self.fill.setdefault(colour, []).append("M%.1f %.1fh%.1fv%.1fh%.1fz" % (x, y, w, h, -w))

    def outline(self, x, y, w, h, colour):
        self.line.setdefault(colour, []).append("M%.1f %.1fh%.1fv%.1fh%.1fz" % (x, y, w, h, -w))

    def label(self, x, y, size, colour, s, weight=None):
        wt = ' font-weight="%s"' % weight if weight else ""
        self.text.append('<text x="%.1f" y="%.1f" font-size="%s" fill="%s"%s>%s</text>'
                         % (x, y, size, colour, wt, esc(s)))

    def emit(self, o):
        for c, d in self.fill.items():
            o.append('<path fill="%s" d="%s"/>' % (c, "".join(d)))
        for c, d in self.line.items():
            o.append('<path fill="none" stroke="%s" stroke-width="1.5" d="%s"/>' % (c, "".join(d)))
        o.extend(self.text)


def node_bytes(n):
    if "kids" in n:
        return sum(node_bytes(k) for k in n["kids"])
    return sum(f["code_bytes"] for f in n["fns"])


def draw_node(cv, pal, n, x, y, w, h):
    """Draw one node (a file with tiles, or a group of nodes) into the box x, y, w, h."""
    if w <= 1 or h <= 1:
        return
    if "kids" in n:
        lab = 13 if w > 56 and h > 26 else 0
        items = sorted(((node_bytes(k), i) for i, k in enumerate(n["kids"]) if node_bytes(k)), reverse=True)
        for kx, ky, kw, kh, i in squarify(items, x + 1, y + 1 + lab, w - 2, h - 2 - lab):
            draw_node(cv, pal, n["kids"][i], kx, ky, kw, kh)
        cv.outline(x + 1, y + 1, w - 2, h - 2, pal["line"])
        if lab:
            cv.label(x + 4, y + 11, 10, pal["ink"], n["label"][:max(int((w - 8) / 5.8), 3)], 600)
        return
    lab = 11 if w > 64 and h > 26 else 0
    for fx, fy, fw, fh, k in _unit_tiles(n["fns"], x, y + lab, w, h - lab):
        cv.rect(fx + 0.3, fy + 0.3, max(fw - 0.6, 0.3), max(fh - 0.6, 0.3), pal[k])
    cv.outline(x + 1, y + 1, w - 2, h - 2, pal["line"])
    if lab:
        cv.label(x + 4, y + 9, 8, pal["muted"], n["label"][:max(int((w - 8) / 4.9), 3)])


LEGEND = [("matched", "matched"), ("matched SDK", "matched_sdk"), ("matched runtime", "matched_runtime"),
          ("open", "open"), ("SDK", "sdk"), ("runtime", "runtime"), ("mismatch", "regmm"),
          ("placeholder", "placeholder"), ("SDK placeholder", "placeholder_sdk")]


def header(o, W, title, pct, subtitle, pal, legend):
    """Title, bold percentage and subtitle on the left; compact legend top right."""
    o.append('<text x="14" y="28" font-size="19" fill="%s"><tspan font-weight="600">%s</tspan>'
             '<tspan dx="12" font-weight="700" fill="%s">%s</tspan></text>'
             % (pal["ink"], esc(title), pal["matched"], pct))
    o.append('<text x="14" y="48" font-size="12" fill="%s">%s</text>' % (pal["muted"], esc(subtitle)))
    lx = W - 14
    for label, colours in reversed(legend):
        if isinstance(colours, str):
            colours = [colours]
        lx -= int(5.6 * len(label)) + 13 + 11 * len(colours) + 9
        for i, colour in enumerate(colours):
            o.append('<rect x="%d" y="20" width="9" height="9" rx="2" fill="%s"/>' % (lx + 11 * i, colour))
        o.append('<text x="%d" y="28.5" font-size="11" fill="%s">%s</text>'
                 % (lx + 11 * len(colours) + 2, pal["muted"], esc(label)))


HDR = 62


def svg_open(W, H, bg):
    return ['<svg xmlns="http://www.w3.org/2000/svg" width="%d" height="%d" viewBox="0 0 %d %d" '
            'font-family="%s">' % (W, H, W, H, FONT), '<rect width="%d" height="%d" fill="%s"/>' % (W, H, bg)]


def write(out, o):
    o.append("</svg>")
    with open(out, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("\n".join(o))


def render_map(out, m, W, H):
    """One image: header and one treemap panel of the map's source files."""
    pal = PALETTES[m["palette"]]
    o = svg_open(W, HDR + H + 8, pal["bg"])
    keys = {f["cls"] for f in m["funcs"]}
    header(o, W, m["title"], m["pct"], m["subtitle"], pal, [(l, pal[k]) for l, k in LEGEND if k in keys])
    cv = Canvas()
    items = sorted(((node_bytes(k), i) for i, k in enumerate(m["nodes"]) if node_bytes(k)), reverse=True)
    for kx, ky, kw, kh, i in squarify(items, 0, HDR, W, H):
        draw_node(cv, pal, m["nodes"][i], kx, ky, kw, kh)
    cv.emit(o)
    write(out, o)


def shared_legend(maps):
    """One entry per status: a swatch per region that has it (region palette), one label."""
    names = {"matched": "matched game code", "matched_sdk": "matched SDK", "matched_runtime": "matched runtime",
             "open": "open", "sdk": "SDK", "runtime": "runtime", "regmm": "mismatch",
             "placeholder": "placeholder", "placeholder_sdk": "SDK placeholder"}
    out = []
    for _, key in LEGEND:
        cols = [PALETTES[m["palette"]][key] for m in maps if any(f["cls"] == key for f in m["funcs"])]
        if cols:
            out.append((names[key], cols))
    return out


def render_all(out, maps, W, H):
    """One image with every region; each region's box keeps its own palette."""
    pal0 = PALETTES["overlays"]
    o = svg_open(W, HDR + H + 8, pal0["bg"])
    tot_m = sum(m["matched"] for m in maps)
    tot = sum(m["denom"] for m in maps)
    nf = sum(m["nfuncs"] for m in maps)
    header(o, W, "All regions", hundredths(tot_m / tot if tot else 0.0),
           "%s / %s bytes matched · %s functions · ARM9, overlays, DSi and autoloads"
           % (format(tot_m, ","), format(tot, ","), format(nf, ",")), pal0,
           shared_legend(maps))
    cv = Canvas()
    items = sorted(((sum(f["code_bytes"] for f in m["funcs"]), i) for i, m in enumerate(maps)), reverse=True)
    for bx, by, bw, bh, i in squarify(items, 0, HDR, W, H):
        m = maps[i]
        pal = PALETTES[m["palette"]]
        cv.rect(bx, by, bw, bh, pal["bg"])
        lab = 17
        cv.label(bx + 6, by + 13, 12, pal["ink"], "%s  %s" % (m["short"], m["pct"]), 700)
        sub = sorted(((node_bytes(k), j) for j, k in enumerate(m["nodes"]) if node_bytes(k)), reverse=True)
        for kx, ky, kw, kh, j in squarify(sub, bx, by + lab, bw, bh - lab):
            draw_node(cv, pal, m["nodes"][j], kx, ky, kw, kh)
        cv.outline(bx + 0.75, by + 0.75, bw - 1.5, bh - 1.5, pal["muted"])
    cv.emit(o)
    write(out, o)


def make_map(short, title, palette, funcs, nodes, game, game_matched, game_funcs, sdk, sdk_matched):
    if game:
        pct = hundredths(game_matched / game)
        sub = "%s / %s game bytes · %s functions · SDK %s bytes" % (
            format(game_matched, ","), format(game, ","), format(game_funcs, ","), format(sdk, ","))
        denom, matched = game, game_matched
    else:
        # no game code in this map: the SDK figure is the headline
        game_funcs = len([f for f in funcs if f["cls"] in SDKC])
        pct = hundredths(sdk_matched / sdk if sdk else 0.0)
        sub = "%s SDK bytes · %s functions" % (format(sdk, ","), format(game_funcs, ","))
        denom, matched = sdk, sdk_matched
    return {"short": short, "title": title, "palette": palette, "funcs": funcs, "nodes": nodes,
            "pct": pct, "subtitle": sub, "denom": denom, "matched": matched, "nfuncs": game_funcs}


def build_arm9(idx):
    inv = worklist.build_inventory()
    for fn in inv["funcs"]:
        if fn.get("cls") == "sdk" and fn.get("matched_name"):
            fn["cls"] = "matched_sdk"
        if fn.get("cls") == "runtime" and fn.get("matched_name"):
            fn["cls"] = "matched_runtime"
        if fn.get("cls") == "sdk" and fn.get("placeholder"):
            fn["cls"] = "placeholder_sdk"
    for e in regmismatch.sizes():
        if e["region"].startswith("arm9"):
            for fn in inv["funcs"]:
                if fn["addr"] == e["addr"] and fn.get("cls") in ("open", "matched"):
                    fn["cls"] = "regmm"
    funcs = [f for f in inv["funcs"] if f["code_bytes"] > 0]
    game = sum(f["code_bytes"] for f in funcs if f["cls"] in GAME)
    matched = sum(f["code_bytes"] for f in funcs if f["cls"] in ("matched", "regmm"))
    n_matched = len([f for f in funcs if f["cls"] in ("matched", "regmm")])
    sdk = sum(f["code_bytes"] for f in funcs if f["cls"] in SDKC)
    a9 = ovstats.arm9_summary()
    if a9:
        want = (int(a9.get("code_bytes_game", -1)), int(a9.get("code_bytes_matched", -1)),
                int(a9.get("functions_matched", -1)))
        if (game, matched, n_matched) != want:
            sys.exit("coveragemap: arm9 tiles disagree with ovstats (layout/worklist.json): %r vs %r"
                     % ((game, matched, n_matched), want))
    groups = file_groups(funcs, lambda f: "arm9", idx).get("arm9", {})
    nodes = [{"label": k, "fns": v} for k, v in sorted(groups.items())]
    gfuncs = len([f for f in funcs if f["cls"] in GAME])
    return make_map("ARM9", "ARM9 main binary", "arm9", funcs, nodes, game, matched, gfuncs, sdk, 0)


def build_overlays(idx):
    funcs = []
    rows = ovstats.overlay_rows(funcs_out=funcs)
    matched = sum(f["code_bytes"] for f in funcs if f["cls"] == "matched")
    regmm = sum(f["code_bytes"] for f in funcs if f["cls"] == "regmm")
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
    per = file_groups(funcs, lambda f: f["region"], idx)
    nodes = []
    for reg in sorted(per):
        kids = [{"label": k, "fns": v} for k, v in sorted(per[reg].items())]
        nodes.append({"label": reg, "kids": kids})
    gfuncs = len([f for f in funcs if f["cls"] in GAME])
    return make_map("Overlays", "Overlays (%d)" % len(glob.glob(os.path.join(ROOT, "asm", "overlays", "ov*.s"))), "overlays", funcs, nodes,
                    game, matched_game + regmm, gfuncs, sdk, matched_sdk)


def build_aux(idx):
    funcs = aux_functions()
    game = sum(f["code_bytes"] for f in funcs if f["cls"] in GAME)
    matched = sum(f["code_bytes"] for f in funcs if f["cls"] in ("matched", "regmm"))
    sdk = sum(f["code_bytes"] for f in funcs if f["cls"] in SDKC)
    matched_sdk = sum(f["code_bytes"] for f in funcs if f["cls"] == "matched_sdk")
    classes = set(GAME) | set(SDKC) | {"runtime", "matched_runtime"}
    for f in funcs:
        if f["cls"] not in classes:
            sys.exit("coveragemap: aux tile %s %08X has unknown class %r" % (f["region"], f["addr"], f["cls"]))
    per = file_groups(funcs, lambda f: f["region"], idx)
    nodes = []
    for reg in sorted(per):
        kids = [{"label": k, "fns": v} for k, v in sorted(per[reg].items())]
        nodes.append({"label": reg, "kids": kids})
    gfuncs = len([f for f in funcs if f["cls"] in GAME])
    return make_map("DSi and autoloads", "DSi and autoloads (TWL, ITCM)", "twl", funcs, nodes,
                    game, matched, gfuncs, sdk, matched_sdk)


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--out", default=os.path.join(ROOT, "docs", "coverage_map.svg"))
    ap.add_argument("--width", type=int, default=1200)
    ap.add_argument("--height", type=int, default=520)
    ap.add_argument("--arm9", action="store_true", help="write the ARM9 image only")
    ap.add_argument("--overlays", action="store_true", help="write the overlay image only")
    ap.add_argument("--twl", action="store_true", help="write the twl/ITCM/autoload image only")
    ap.add_argument("--all", action="store_true", help="write the combined image only")
    ap.add_argument("--ov-out", default=os.path.join(ROOT, "docs", "coverage_overlays.svg"))
    ap.add_argument("--twl-out", default=os.path.join(ROOT, "docs", "coverage_twl.svg"))
    ap.add_argument("--all-out", default=os.path.join(ROOT, "docs", "coverage_all.svg"))
    a = ap.parse_args(argv)
    idx = unit_index()
    do_all = not (a.arm9 or a.overlays or a.twl or a.all)
    maps = {}
    todo = [("arm9", a.arm9, build_arm9, a.out, a.height),
            ("overlays", a.overlays, build_overlays, a.ov_out, a.height + 40),
            ("twl", a.twl, build_aux, a.twl_out, a.height - 220)]
    for name, flag, build, out, h in todo:
        if do_all or flag or a.all:
            maps[name] = build(idx)
            if do_all or flag:
                render_map(out, maps[name], a.width, h)
                m = maps[name]
                print("wrote %s: %s %s | %s" % (os.path.relpath(out, ROOT), m["title"], m["pct"], m["subtitle"]))
    if do_all or a.all:
        render_all(a.all_out, [maps["arm9"], maps["overlays"], maps["twl"]], a.width, a.height + 300)
        print("wrote %s" % os.path.relpath(a.all_out, ROOT))


if __name__ == "__main__":
    main()
