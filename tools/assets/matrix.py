#!/usr/bin/env python3
"""
matrix.py -- decoder for the map matrix archive `a/0/0/9`, 255 sub-files,
each one zone-transition matrix that a zone record's `+0x04` lane (see
zones.py) selects.

Written from scratch for the aletheia asset lane. Stdlib only.

This is not a fresh discovery pass: the format below is exactly the one
docs/ASSETS.md attests in "Zone to map model SOLVED: record +0x04 is a
matrix id into `a/0/0/9`, whose cells are u32 `a/0/0/8` indices", derived
there from the decompiled path `sub_02013B44` -> `func_02159B94` ->
`func_02048F60` -> `func_02159D04`. This module only decodes the bytes the
way that section says `func_02159D04` reads them; it does not re-derive
the format.

--------------------------------------------------------------------------
Sub-file layout (per docs/ASSETS.md)
--------------------------------------------------------------------------
    +0x00  u16             mode (only 0 and 1 occur; only mode matters,
                            the upper half of the word holding it is
                            never read by the game)
    +0x02  u16             unread (pad)
    +0x04  u16             width
    +0x06  u16             height
    +0x08  u32 x width*height   map grid: `a/0/0/8` sub-file index per
                            cell, 0xFFFFFFFF = empty
    +0x08 + 4*w*h  u32 x width*height   zone grid, ONLY when mode == 1:
                            zone id per cell

When mode is not 1 there is no second block; the runtime fills the
(fixed-size, 900-entry) zone grid with the caller's single zone id
instead, so a mode-0 matrix belongs to exactly one zone by construction.

--------------------------------------------------------------------------
CLI
--------------------------------------------------------------------------
    python tools/assets/matrix.py --list
        Per matrix: id, mode, width, height, cell count, distinct map ids.

    python tools/assets/matrix.py --dump N
        Print matrix N's map grid as a text matrix ("." for the empty
        sentinel, the map id otherwise); for a mode-1 matrix, also print
        the zone grid.

    python tools/assets/matrix.py --verify
        Re-pack every sub-file from parsed fields and compare byte-for-
        byte against the original.

    python tools/assets/matrix.py --stitch N
        Place every chunk's 32x32 walkability bitmap (map_grid.py's
        per-tile grid byte[4]) at its matrix cell position in one PNG
        under build/assets/maps/ (gitignored, not committed). Only makes
        sense for a mode-1 matrix (matrix 0 or 175, the Unova overworld
        halves); also reports, per chunk border, what fraction of edge
        tiles agree on walkability with the neighbouring chunk's facing
        edge, as a quantitative stand-in for "do roads/rivers line up".
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402
import map_grid  # noqa: E402
import nsbmd  # noqa: E402

A009_PATH = os.path.join("extract", "data", "a", "0", "0", "9")
A008_PATH = os.path.join("extract", "data", "a", "0", "0", "8")
STITCH_OUT_DIR = os.path.join("build", "assets", "maps")
CHUNK_TILES = 32

EMPTY_CELL = 0xFFFFFFFF
HEADER_FMT = "<HHHH"
HEADER_SIZE = 8


class MatrixError(Exception):
    pass


def load_archive():
    return narc.parse_file(A009_PATH)


def parse_matrix(raw, matrix_id):
    if len(raw) < HEADER_SIZE:
        raise MatrixError(f"matrix {matrix_id}: sub-file too short for header "
                           f"({len(raw)} bytes)")
    mode, pad, width, height = struct.unpack_from(HEADER_FMT, raw, 0)
    n = width * height
    block1_off = HEADER_SIZE
    block1_end = block1_off + 4 * n
    if block1_end > len(raw):
        raise MatrixError(f"matrix {matrix_id}: map grid ({width}x{height}) "
                           f"runs past end of sub-file ({len(raw)} bytes)")
    map_grid = list(struct.unpack_from(f"<{n}I", raw, block1_off))

    zone_grid = None
    block2_end = block1_end
    if mode == 1:
        block2_off = block1_end
        block2_end = block2_off + 4 * n
        if block2_end > len(raw):
            raise MatrixError(f"matrix {matrix_id}: mode 1 but zone grid "
                               f"({width}x{height}) runs past end of sub-file "
                               f"({len(raw)} bytes)")
        zone_grid = list(struct.unpack_from(f"<{n}I", raw, block2_off))

    return {
        "matrix_id": matrix_id,
        "mode": mode,
        "pad": pad,
        "width": width,
        "height": height,
        "map_grid": map_grid,
        "zone_grid": zone_grid,
        "total_len": len(raw),
        "used_len": block2_end,
    }


def pack_matrix(m):
    out = bytearray()
    out += struct.pack(HEADER_FMT, m["mode"], m["pad"], m["width"], m["height"])
    n = m["width"] * m["height"]
    out += struct.pack(f"<{n}I", *m["map_grid"])
    if m["mode"] == 1:
        out += struct.pack(f"<{n}I", *m["zone_grid"])
    return bytes(out)


def load_all(a009=None):
    a009 = a009 or load_archive()
    return [parse_matrix(a009.read(i), i) for i in range(a009.file_count)]


# ---------------------------------------------------------------------------
# --list
# ---------------------------------------------------------------------------

def cmd_list(args):
    a009 = load_archive()
    matrices = load_all(a009)
    mode_hist = {}
    for m in matrices:
        mode_hist[m["mode"]] = mode_hist.get(m["mode"], 0) + 1
    print(f"a/0/0/9: {a009.file_count} matrices, mode histogram "
          f"{sorted(mode_hist.items())}")
    for m in matrices:
        cells = m["map_grid"]
        distinct = sorted(set(c for c in cells if c != EMPTY_CELL))
        empty_ct = sum(1 for c in cells if c == EMPTY_CELL)
        print(f"matrix {m['matrix_id']:3d}: mode={m['mode']} "
              f"{m['width']:2d}x{m['height']:2d} cells={len(cells):4d} "
              f"empty={empty_ct:4d} distinct_map_ids={len(distinct):4d}")


# ---------------------------------------------------------------------------
# --dump
# ---------------------------------------------------------------------------

def _format_grid(grid, width, height, empty_value=None, cell_width=4):
    lines = []
    for row in range(height):
        vals = []
        for col in range(width):
            v = grid[row * width + col]
            if empty_value is not None and v == empty_value:
                vals.append(".".rjust(cell_width))
            else:
                vals.append(str(v).rjust(cell_width))
        lines.append(" ".join(vals))
    return "\n".join(lines)


def cmd_dump(args):
    a009 = load_archive()
    if not (0 <= args.dump < a009.file_count):
        raise MatrixError(f"matrix id {args.dump} out of range "
                           f"(0..{a009.file_count - 1})")
    m = parse_matrix(a009.read(args.dump), args.dump)
    print(f"matrix {m['matrix_id']}: mode={m['mode']} "
          f"{m['width']}x{m['height']}, map grid "
          f"(sentinel 0x{EMPTY_CELL:08x} shown as '.'):")
    print(_format_grid(m["map_grid"], m["width"], m["height"], EMPTY_CELL))
    if m["mode"] == 1:
        print()
        print(f"matrix {m['matrix_id']}: zone grid:")
        print(_format_grid(m["zone_grid"], m["width"], m["height"]))


# ---------------------------------------------------------------------------
# --verify
# ---------------------------------------------------------------------------

def cmd_verify(args):
    a009 = load_archive()
    ok = fail = 0
    for i in range(a009.file_count):
        raw = a009.read(i)
        try:
            m = parse_matrix(raw, i)
        except MatrixError as exc:
            print(f"  matrix {i}: parse error: {exc}", file=sys.stderr)
            fail += 1
            continue
        repacked = pack_matrix(m)
        if repacked == raw:
            ok += 1
        else:
            fail += 1
            print(f"  matrix {i}: round-trip MISMATCH "
                  f"(orig {len(raw)} bytes, repacked {len(repacked)} bytes)",
                  file=sys.stderr)
    print(f"a/0/0/9: {ok}/{a009.file_count} matrices round-trip byte-identical "
          f"({fail} failed)")
    return 0 if fail == 0 else 1


# ---------------------------------------------------------------------------
# --sentinel-check: report the empty sentinel and how many cells carry it,
# across every matrix (the reporting --list leaves out for brevity).
# ---------------------------------------------------------------------------

def cmd_sentinel_check(args):
    a009 = load_archive()
    matrices = load_all(a009)
    total_cells = 0
    total_empty = 0
    sentinels_seen = set()
    for m in matrices:
        for c in m["map_grid"]:
            total_cells += 1
            if c > 648:
                sentinels_seen.add(c)
                total_empty += 1
    print(f"empty sentinel value: 0x{EMPTY_CELL:08x} ({EMPTY_CELL})")
    print(f"distinct out-of-range (>648) values seen: "
          f"{sorted(hex(v) for v in sentinels_seen)}")
    print(f"cells carrying the sentinel: {total_empty}/{total_cells}")


# ---------------------------------------------------------------------------
# --stitch: place each chunk's walkability bitmap at its matrix position
# ---------------------------------------------------------------------------

def _chunk_walkable_grid(a008, map_id):
    """Returns a flat list of CHUNK_TILES*CHUNK_TILES 0/1 values (byte[4] of
    map_grid.py's per-tile grid, the high-confidence walkable flag), or
    None if the map id has no ordinary 32x32 grid to read."""
    raw = a008.read(map_id)
    info = map_grid.parse_wrapper(raw)
    if not info["grids"]:
        return None
    grid = info["grids"][0]
    if grid["width"] != CHUNK_TILES or grid["height"] != CHUNK_TILES:
        return None
    records = map_grid.read_records(raw, grid)
    return [r[4] for r in records]


def cmd_stitch(args):
    a009 = load_archive()
    if not (0 <= args.stitch < a009.file_count):
        raise MatrixError(f"matrix id {args.stitch} out of range "
                           f"(0..{a009.file_count - 1})")
    m = parse_matrix(a009.read(args.stitch), args.stitch)
    width, height = m["width"], m["height"]
    a008 = narc.parse_file(A008_PATH)

    px_w = width * CHUNK_TILES
    px_h = height * CHUNK_TILES
    rgba = bytearray(px_w * px_h * 4)

    def set_px(x, y, r, g, b):
        o = (y * px_w + x) * 4
        rgba[o] = r
        rgba[o + 1] = g
        rgba[o + 2] = b
        rgba[o + 3] = 255

    # Missing-chunk color (a cell with no map, or one that failed to read
    # as an ordinary 32x32 grid) vs the two walkable-flag colors.
    MISSING = (60, 20, 20)
    BLOCKED = (20, 20, 20)
    WALKABLE = (235, 235, 235)

    chunk_cache = {}  # map_id -> walkable grid, or None
    placed = 0
    missing = 0
    for row in range(height):
        for col in range(width):
            map_id = m["map_grid"][row * width + col]
            wg = None
            if map_id != EMPTY_CELL:
                if map_id not in chunk_cache:
                    try:
                        chunk_cache[map_id] = _chunk_walkable_grid(a008, map_id)
                    except Exception:
                        chunk_cache[map_id] = None
                wg = chunk_cache[map_id]
            ox, oy = col * CHUNK_TILES, row * CHUNK_TILES
            if wg is None:
                missing += 1
                for ty in range(CHUNK_TILES):
                    for tx in range(CHUNK_TILES):
                        set_px(ox + tx, oy + ty, *MISSING)
                continue
            placed += 1
            for ty in range(CHUNK_TILES):
                for tx in range(CHUNK_TILES):
                    v = wg[ty * CHUNK_TILES + tx]
                    set_px(ox + tx, oy + ty, *(WALKABLE if v else BLOCKED))

    os.makedirs(STITCH_OUT_DIR, exist_ok=True)
    out_path = os.path.join(STITCH_OUT_DIR, f"matrix{args.stitch}_walkability.png")
    nsbmd.write_png_rgba8(out_path, px_w, px_h, bytes(rgba))

    print(f"matrix {args.stitch}: {width}x{height} chunks, "
          f"{placed} placed, {missing} missing/empty/non-32x32")
    print(f"stitched image: {px_w}x{px_h} px -> {out_path}")

    # Border-continuity check: for every pair of adjacent PLACED chunks,
    # compare the facing edge's walkable flags tile-for-tile.
    def border_agreement(row, col, drow, dcol):
        map_id_a = m["map_grid"][row * width + col]
        nrow, ncol = row + drow, col + dcol
        if not (0 <= nrow < height and 0 <= ncol < width):
            return None
        map_id_b = m["map_grid"][nrow * width + ncol]
        if map_id_a == EMPTY_CELL or map_id_b == EMPTY_CELL:
            return None
        wg_a = chunk_cache.get(map_id_a)
        wg_b = chunk_cache.get(map_id_b)
        if wg_a is None or wg_b is None:
            return None
        if dcol == 1:   # b is to the right of a: a's right column vs b's left column
            a_edge = [wg_a[t * CHUNK_TILES + (CHUNK_TILES - 1)] for t in range(CHUNK_TILES)]
            b_edge = [wg_b[t * CHUNK_TILES + 0] for t in range(CHUNK_TILES)]
        else:            # b is below a: a's bottom row vs b's top row
            a_edge = wg_a[(CHUNK_TILES - 1) * CHUNK_TILES: CHUNK_TILES * CHUNK_TILES]
            b_edge = wg_b[0: CHUNK_TILES]
        agree = sum(1 for x, y in zip(a_edge, b_edge) if x == y)
        return agree, CHUNK_TILES

    total_agree = total_tiles = pairs = 0
    for row in range(height):
        for col in range(width):
            for drow, dcol in ((0, 1), (1, 0)):
                res = border_agreement(row, col, drow, dcol)
                if res is None:
                    continue
                agree, tiles = res
                total_agree += agree
                total_tiles += tiles
                pairs += 1
    if pairs:
        print(f"border continuity: {pairs} adjacent chunk-pair edges checked, "
              f"{total_agree}/{total_tiles} edge tiles agree on walkability "
              f"({100.0 * total_agree / total_tiles:.1f}%)")
    else:
        print("border continuity: no adjacent placed chunk pairs to check")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group()
    g.add_argument("--list", action="store_true", help="print all matrices")
    g.add_argument("--dump", type=int, metavar="N",
                   help="dump matrix N's grid(s) as text")
    g.add_argument("--verify", action="store_true",
                   help="byte-identical repack check, every sub-file")
    g.add_argument("--sentinel-check", action="store_true",
                   help="report the empty sentinel and its prevalence")
    g.add_argument("--stitch", type=int, metavar="N",
                   help="stitch matrix N's per-chunk walkability bitmaps "
                        "into one PNG under build/assets/maps/")
    args = ap.parse_args(argv)

    try:
        if args.dump is not None:
            cmd_dump(args)
        elif args.verify:
            return cmd_verify(args)
        elif args.sentinel_check:
            cmd_sentinel_check(args)
        elif args.stitch is not None:
            cmd_stitch(args)
        else:
            cmd_list(args)
    except MatrixError as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 2
    return 0


if __name__ == "__main__":
    sys.exit(main())
