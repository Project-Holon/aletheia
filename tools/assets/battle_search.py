#!/usr/bin/env python3
"""
battle_search.py -- new-angle search for the still-unlocated trainer battle
sprite archive: NOT assumed to be a NITRO NCGR/NCER bundle at all.

Written from scratch for aletheia. Stdlib only, single file.

--------------------------------------------------------------------------
Mission
--------------------------------------------------------------------------
Every previous pass (docs/ASSETS.md "Trainer battle sprite mission") that
assumed the trainer sprite is a standard NITRO NCGR/NCER OAM-cell rig came
up empty across 94 >=100-tile-NCGR archives and 38 >=64px-OAM archives.
This pass drops that assumption and instead looks for a **fixed-size
sub-file family**, the same style of evidence that cracked `a/0/0/6`'s
custom `" APS12_1"`/`" TPS"` wrapper (`tools/assets/trainer.py`) and the
battle-sprite archive `a/1/3/4`'s own fixed 0x20000 payload convention
(docs/ASSETS.md "battle sprite archive"): a plausible bitmap canvas at
battle-portrait scale (80x80, 96x96, 128x64 at 4bpp, or the 8bpp doubles)
occurring as a *repeated exact byte count* across many sub-files, with or
without a trailing/leading 32-byte (16-color) palette -- a much weaker
assumption than "this is a NITRO NCGR" and one nothing in this project has
swept for directly before.

Two independent scans, both over every one of the 247 files under
`extract/data/` (each opened as a NARC; files that don't parse as one are
skipped and counted):

1. **Fixed-size census** (`--sizes`): every sub-file's raw byte length,
   tabulated into a global histogram. Cross-referenced against the
   mission's candidate canvas sizes (4bpp 80x80/96x96/128x64, their 8bpp
   doubles, each with/without a trailing 32-byte palette) and, separately,
   every size with 100-400 total occurrences ROM-wide (the mission's
   population-size heuristic for "this looks like a per-trainer-class
   set", independent of whether it happens to match one of the guessed
   canvas sizes).
2. **Tag census** (`--tags`): every sub-file's first 4 and first 8 bytes,
   checked for "all printable ASCII" (0x20-0x7E) and not a magic this
   project already knows (the reversed NITRO chunk tags, `NARC`, BIOS
   compression headers, or the already-cracked `" APS12_1"`/`" TPS"`
   wrapper) -- the same style of signal that first found `a/0/0/6`'s
   wrapper. Tabulated by tag -> (archive count, total occurrence count),
   so a genuinely new wrapper magic stands out from one-off noise.

`--render` renders one sample sub-file from every fixed-size family that
has 100-400 total members, under every plausible layout the mission asks
for (linear 4bpp, linear 8bpp, and 8x8-tiled 4bpp, at the width implied by
the family's byte count and each guessed canvas shape), with a 16- or
256-step grayscale ramp (no palette assumed -- the mission's ask is
"identify", and a grayscale ramp avoids a wrong-palette false negative the
way `trainer_locate.py`'s raw tile-grid renders already do for the NITRO
search). Output under `build/assets/battle_search/`.

--------------------------------------------------------------------------
Usage
--------------------------------------------------------------------------
    python tools/assets/battle_search.py --sizes            # size census
    python tools/assets/battle_search.py --tags              # tag census
    python tools/assets/battle_search.py --render              # render candidate families
    python tools/assets/battle_search.py --all                  # all three
"""

import argparse
import os
import struct
import sys
import zlib
from collections import Counter, defaultdict

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402

ROOT = os.path.join("extract", "data")
OUT_DIR = os.path.join("build", "assets", "battle_search")

# ---------------------------------------------------------------------------
# Candidate bitmap sizes (mission's list)
# ---------------------------------------------------------------------------
CANVASES = [
    ("4bpp 80x80", 80, 80, 4, 3200),
    ("4bpp 96x96", 96, 96, 4, 4608),
    ("4bpp 128x64", 128, 64, 4, 4096),
    ("8bpp 80x80", 80, 80, 8, 6400),
    ("8bpp 96x96", 96, 96, 8, 9216),
    ("8bpp 128x64", 128, 64, 8, 8192),
]
PALETTE_BYTES = 32

KNOWN_MAGICS = {
    b"NARC", b"BTAF", b"BTNF", b"GMIF",
    b"RGCN", b"NCGR", b"RLCN", b"NCLR", b"RECN", b"NCER", b"RNAN", b"NANR",
    b"RCSN", b"NSCR", b"RCAB", b"NCBR",
    b"BMD0", b"BTX0", b"BCA0", b"BTP0", b"BTA0", b"BVA0",
    b"SDAT", b"RCMN", b"NMCR", b"RAMN", b"NMAR",
    b" APS", b" TPS",  # already-cracked a/0/0/6 wrapper
}


def _iter_all_files(root=ROOT):
    for dirpath, _dirs, files in os.walk(root):
        for fn in files:
            yield os.path.join(dirpath, fn)


def _rel(path, root=ROOT):
    return os.path.relpath(path, root).replace(os.sep, "/")


# ---------------------------------------------------------------------------
# Scan: collect (rel_path, index, size, head8) for every sub-file of every
# NARC under extract/data/. Non-NARC files are skipped (counted).
# ---------------------------------------------------------------------------

def scan_all():
    """Returns (records, not_narc). Each record is (rel_path, index,
    effective_size, head8, compressed) -- `effective_size` is the
    DECLARED decompressed size (from the BIOS compression header's own
    24-bit size field, via `narc.sniff_compression` -- no need to actually
    inflate every sub-file just to read this) when the sub-file opens with
    a recognised compression header, else the raw on-disk size. This
    matters: a compressed bitmap family would show a different COMPRESSED
    length per member (ratio depends on content) even though every member
    decompresses to the same fixed canvas size, so a size census over raw
    on-disk lengths alone would never see it as a "family" at all."""
    records = []
    not_narc = 0
    for path in sorted(_iter_all_files()):
        try:
            n = narc.parse_file(path)
        except Exception:  # noqa: BLE001
            not_narc += 1
            continue
        rel = _rel(path)
        for sf in n.subfiles:
            raw = n.read(sf.index)
            head = raw[:8]
            info = narc.sniff_compression(head)
            if info is not None:
                eff_size = info[1]
                compressed = True
            else:
                eff_size = len(raw)
                compressed = False
            records.append((rel, sf.index, eff_size, head, compressed))
    return records, not_narc


# ---------------------------------------------------------------------------
# Size census
# ---------------------------------------------------------------------------

def size_census(records):
    hist = Counter(size for _rel, _idx, size, _head, _comp in records)
    return hist


def report_sizes(records):
    hist = size_census(records)
    print(f"[*] {len(records)} sub-files total, {len(hist)} distinct sizes")
    print()
    print("[*] mission candidate canvas sizes (bitmap only, and +32-byte palette variants):")
    for name, w, h, bpp, sz in CANVASES:
        for label, target in ((f"{name} bare", sz), (f"{name} +pal", sz + PALETTE_BYTES),
                               (f"{name} pal-first", sz + PALETTE_BYTES)):
            cnt = hist.get(target, 0)
            if cnt:
                print(f"    {label} ({target} bytes): {cnt} sub-file(s)")
    print()
    print("[*] every size with 100-400 total ROM-wide occurrences (population heuristic):")
    pop_hits = sorted((sz, cnt) for sz, cnt in hist.items() if 100 <= cnt <= 400)
    for sz, cnt in pop_hits:
        archives = sorted({rel for rel, _idx, s, _h, _c in records if s == sz})
        print(f"    size {sz} ({sz} bytes): {cnt} sub-file(s) across {len(archives)} archive(s)"
              + (f" e.g. {archives[:3]}" if archives else ""))
    return hist, pop_hits


# ---------------------------------------------------------------------------
# Tag census
# ---------------------------------------------------------------------------

def _printable(b):
    return all(0x20 <= c < 0x7F for c in b)


def tag_census(records):
    tag4 = Counter()
    tag4_archives = defaultdict(set)
    tag8 = Counter()
    tag8_archives = defaultdict(set)
    for rel, _idx, _size, head, _comp in records:
        h4 = head[:4]
        if len(h4) == 4 and h4 not in KNOWN_MAGICS and _printable(h4):
            tag4[h4] += 1
            tag4_archives[h4].add(rel)
        h8 = head[:8]
        if len(h8) == 8 and h8[:4] not in KNOWN_MAGICS and _printable(h8):
            tag8[h8] += 1
            tag8_archives[h8].add(rel)
    return tag4, tag4_archives, tag8, tag8_archives


def report_tags(records):
    tag4, tag4_arch, tag8, tag8_arch = tag_census(records)
    print(f"[*] {len(tag4)} distinct printable-ASCII 4-byte head tags (not already known)")
    for tag, cnt in tag4.most_common(40):
        archs = sorted(tag4_arch[tag])
        print(f"    {tag!r}: {cnt} occurrence(s) in {len(archs)} archive(s) "
              f"e.g. {archs[:3]}")
    print()
    print(f"[*] {len(tag8)} distinct printable-ASCII 8-byte head tags (not already known)")
    for tag, cnt in tag8.most_common(40):
        archs = sorted(tag8_arch[tag])
        print(f"    {tag!r}: {cnt} occurrence(s) in {len(archs)} archive(s) "
              f"e.g. {archs[:3]}")
    return tag4, tag8


# ---------------------------------------------------------------------------
# Rendering candidate families
# ---------------------------------------------------------------------------

def write_png_gray(path, width, height, gray_pixels, bits=8, levels=256):
    """Minimal stdlib PNG writer, greyscale. `gray_pixels` are 0..levels-1
    palette indices, scaled to 0..255 -- no real palette assumed (mission:
    identify shape/legibility first, colors can come later)."""
    def chunk(tag, data):
        out = struct.pack(">I", len(data)) + tag + data
        crc = zlib.crc32(tag)
        crc = zlib.crc32(data, crc) & 0xFFFFFFFF
        out += struct.pack(">I", crc)
        return out

    sig = b"\x89PNG\r\n\x1a\n"
    ihdr = struct.pack(">IIBBBBB", width, height, 8, 0, 0, 0, 0)  # 8-bit greyscale
    raw = bytearray()
    scale = 255 / max(1, levels - 1)
    for y in range(height):
        raw.append(0)
        row = gray_pixels[y * width:(y + 1) * width]
        for v in row:
            raw.append(min(255, int(v * scale)))
    idat = zlib.compress(bytes(raw), 9)
    with open(path, "wb") as fh:
        fh.write(sig)
        fh.write(chunk(b"IHDR", ihdr))
        fh.write(chunk(b"IDAT", idat))
        fh.write(chunk(b"IEND", b""))


def render_linear_4bpp(data, width):
    """2 pixels/byte, low nibble first (standard NDS 4bpp packing)."""
    n_pixels = len(data) * 2
    height = n_pixels // width
    out = [0] * (width * height)
    for i, b in enumerate(data[:width * height // 2]):
        out[i * 2] = b & 0x0F
        out[i * 2 + 1] = (b >> 4) & 0x0F
    return width, height, out, 16


def render_linear_8bpp(data, width):
    height = len(data) // width
    out = list(data[:width * height])
    return width, height, out, 256


def render_tiled_4bpp(data, tiles_w):
    """8x8-tile-ordered 4bpp: standard NCGR tile layout (32 bytes/tile,
    2px/byte, row-major within the tile, tiles row-major in the grid)."""
    n_tiles = len(data) // 32
    tiles_h = max(1, n_tiles // tiles_w) if tiles_w else 1
    width, height = tiles_w * 8, tiles_h * 8
    out = [0] * (width * height)
    for t in range(min(n_tiles, tiles_w * tiles_h)):
        tx, ty = t % tiles_w, t // tiles_w
        tile = data[t * 32:t * 32 + 32]
        for ly in range(8):
            row = tile[ly * 4:ly * 4 + 4]
            for lx4 in range(4):
                b = row[lx4] if lx4 < len(row) else 0
                px = tx * 8 + lx4 * 2
                py = ty * 8 + ly
                if px < width and py < height:
                    out[py * width + px] = b & 0x0F
                    if px + 1 < width:
                        out[py * width + px + 1] = (b >> 4) & 0x0F
    return width, height, out, 16


def render_family(name, sz, records, out_dir):
    """Pick one sample sub-file of exactly `sz` bytes and render it under
    every plausible layout implied by the mission's candidate canvases
    that this byte count could plausibly be (bare, or bare+32-byte
    palette stripped)."""
    hit = next(((rel, idx, comp) for rel, idx, s, _h, comp in records if s == sz), None)
    if hit is None:
        return []
    rel, idx, was_compressed = hit
    path = os.path.join(ROOT, *rel.split("/"))
    n = narc.parse_file(path)
    raw = n.read(idx)
    if was_compressed:
        kind, dec = narc.try_decompress(raw)
        if dec is None:
            return []
        raw = dec
    tag = rel.replace("/", "_")
    written = []

    # strip a trailing 32-byte palette candidate if present
    body_variants = [("full", raw)]
    if len(raw) > PALETTE_BYTES:
        body_variants.append(("minus_trailing_pal", raw[:-PALETTE_BYTES]))

    for variant_name, body in body_variants:
        for cname, w, h, bpp, csz in CANVASES:
            if bpp == 4 and len(body) * 2 >= w * h:
                width, height, out, levels = render_linear_4bpp(body, w)
                out_path = os.path.join(
                    out_dir, f"{tag}_sf{idx:04d}_sz{sz}_{variant_name}_lin4_{cname.replace(' ', '')}.png")
                write_png_gray(out_path, width, height, out, levels=levels)
                written.append(out_path)
            if bpp == 8 and len(body) >= w * h:
                width, height, out, levels = render_linear_8bpp(body, w)
                out_path = os.path.join(
                    out_dir, f"{tag}_sf{idx:04d}_sz{sz}_{variant_name}_lin8_{cname.replace(' ', '')}.png")
                write_png_gray(out_path, width, height, out, levels=levels)
                written.append(out_path)
        # 8x8-tiled 4bpp at the width implied by a square-ish tile grid
        n_tiles = len(body) // 32
        if n_tiles >= 4:
            import math
            tiles_w = max(1, round(math.sqrt(n_tiles)))
            width, height, out, levels = render_tiled_4bpp(body, tiles_w)
            out_path = os.path.join(
                out_dir, f"{tag}_sf{idx:04d}_sz{sz}_{variant_name}_tiled4.png")
            write_png_gray(out_path, width, height, out, levels=levels)
            written.append(out_path)
    return written


def render_candidates(records, pop_hits, out_dir):
    os.makedirs(out_dir, exist_ok=True)
    all_written = []
    for sz, cnt in pop_hits:
        try:
            w = render_family(f"family{sz}", sz, records, out_dir)
        except Exception as exc:  # noqa: BLE001 -- best-effort batch, log and continue
            print(f"[!] size {sz} ({cnt} members): skipped ({exc})")
            continue
        print(f"[*] size {sz} ({cnt} members): {len(w)} render(s) written")
        all_written.extend(w)
    return all_written


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--sizes", action="store_true", help="fixed-size census")
    ap.add_argument("--tags", action="store_true", help="printable-tag census")
    ap.add_argument("--render", action="store_true",
                     help="render one sample per 100-400-member fixed-size family")
    ap.add_argument("--all", action="store_true", help="run all three")
    ap.add_argument("--out", default=OUT_DIR)
    args = ap.parse_args(argv)

    if not (args.sizes or args.tags or args.render or args.all):
        ap.error("give --sizes, --tags, --render, or --all")

    print("[*] scanning every sub-file of every NARC under extract/data/ ...")
    records, not_narc = scan_all()
    print(f"[*] {len(records)} sub-files scanned, {not_narc} top-level file(s) were not a NARC")
    print()

    pop_hits = []
    if args.sizes or args.all:
        _hist, pop_hits = report_sizes(records)
        print()
    if args.tags or args.all:
        report_tags(records)
        print()
    if args.render or args.all:
        if not pop_hits:
            _hist, pop_hits = size_census(records), None
            pop_hits = sorted((sz, cnt) for sz, cnt in _hist.items() if 100 <= cnt <= 400)
        render_candidates(records, pop_hits, args.out)

    return 0


if __name__ == "__main__":
    sys.exit(main())
