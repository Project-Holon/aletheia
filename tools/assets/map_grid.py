#!/usr/bin/env python3
"""
map_grid.py -- decode and visualise `a/0/0/8` map/building/dungeon
sub-files' per-tile grid (the wrapper's "permission/height data" region,
directly following the BMD0 model, see docs/ASSETS.md's map-model
mission section), and the small size-table header that wraps each
sub-file.

Written from scratch for the aletheia asset lane. Stdlib only.

--------------------------------------------------------------------------
Wrapper layout (recap, see docs/ASSETS.md for the full writeup)
--------------------------------------------------------------------------
Each `a/0/0/8` sub-file is:

    header (variable length, tag-dependent) || BMD0 model || grid(s) || tail

The header always starts with a 2-byte ASCII tag ("WB", "GC", "NG", "RD"),
then a u16 (a small per-tag version/count), then a u32 whose value equals
the header's OWN byte length -- which doubles as "byte offset where the
BMD0 payload begins" (confirmed: `raw.find(b"BMD0") == that u32`, every
sample checked). The remaining header u32s are a small size table of
absolute byte offsets into the sub-file; what they mark differs by tag
(this pass pins all of them down, see TAG_LAYOUT below and the ASSETS.md
writeup):

  WB (20 bytes, 572/649 files): one grid.
    u32@4  = header length (== BMD0 offset)
    u32@8  = BMD0-block end / grid-1 start
    u32@12 = grid-1 end / tail start (previously "not pinned down" --
             this pass confirms it against the grid's own computed
             extent in every 32x32 sample; the one 64x64 sample seen
             (`pl_00_00`) leaves a 32-byte unexplained gap before this
             offset, see the gap note below)
    u32@16 = total sub-file length

  GC (24 bytes, 47/649 files): TWO grids back to back (new this pass --
    previously undocumented; every GC sample checked, all dungeon/room
    models, carries a second grid of the same shape immediately after
    the first, not a "tail").
    u32@4  = header length
    u32@8  = BMD0 end / grid-1 start
    u32@12 = grid-1 end / grid-2 start
    u32@16 = grid-2 end / tail start
    u32@20 = total length

  NG (16 bytes, 22/649 files): NO per-tile grid at all (new this pass --
    the tag plausibly stands for "No Grid": every NG sample scanned has
    zero bytes between the BMD0 end and the declared total length beyond
    a few bytes of padding, confirmed structurally, not guessed).
    u32@4  = header length
    u32@8  = BMD0 end (== total length minus a few trailing pad bytes)
    u32@12 = total length

  RD (20 bytes, 8/649 files, all "wf_*"/"bc_*" named models -- water
    surfaces on the current best reading of the names): one ordinary
    32x32/8-byte grid, THEN a second, denser block with no dimension
    header of its own: exactly 64*64*4 = 16384 bytes in every sample,
    directly abutting the first grid's end and running to the declared
    total length. Read as a second grid at 4x the resolution with a
    4-byte record (half the field width of the primary record) -- a
    plausible per-quarter-tile water-surface table given the file names,
    but not decoded past "it is exactly the right size for that shape"
    this pass (new finding, not previously documented; layout confidence
    is structural/size-only, semantic confidence is a guess).
    u32@4  = header length
    u32@8  = grid-1 start (== BMD0 end)
    u32@12 = grid-1 end / dense-block start
    u32@16 = total length (dense-block end)

--------------------------------------------------------------------------
The grid itself
--------------------------------------------------------------------------
Every grid opens with a `u16, u16` (width, height) pair -- 32x32 in every
outdoor/dungeon sample seen, but `pl_00_00` (the player's house) is
64x64: the grid resolution is NOT a fixed constant, it is read from the
file. Following that 4-byte header are `width*height` 8-byte records,
row-major (record i is column i%width, row i//width).

--------------------------------------------------------------------------
The 8-byte record's byte lanes (this pass's main result)
--------------------------------------------------------------------------
Confidence levels: HIGH = directly confirmed by a real, visually-checked
shape match against known geometry; MEDIUM = a real correlation found,
plausible but not independently cross-checked a second way; LOW = a
pattern noticed but not correlated against anything external.

  byte[4]  HIGH.   0/1 walkable flag. In `pl_00_00`, plotting this byte
           as a bitmap over the 64x64 grid reproduces the house's actual
           floor plan almost exactly: an open floor border, a large
           blocked interior blob whose outline matches where furniture
           and interior walls must be, and a real gap in the south wall
           at the model's only door-sized opening. In the outdoor chunk
           `map24_23`, this byte outlines scattered blocked patches
           (trees/rocks) against a mostly-open field, exactly the shape
           expected of a walkability mask, not a coincidence.
  byte[6]  HIGH.   Always equals byte[4] | 0x80 in every sample checked
           (0x80 when byte[4]=0, 0x81 when byte[4]=1) -- a redundant copy
           of the walkable bit with a constant high bit set (an
           "entry present/valid" flag paired with the low bit, on the
           current best reading; not independently useful beyond
           byte[4]).
  byte[2]  MEDIUM.  A quantized height/terrain-level code. In
           `map24_23`, the region where byte[2] steps 0 -> 1 -> 2 -> 3 -> 4
           over four consecutive tiles (a literal ramp shape) sits
           exactly on the boundary between two OBJ-sampled elevation
           bands (roughly y=+0.05 on the 0 side, y=-0.3..-0.4 on the 4
           side, sampled by bucketing exported vertices into grid cells
           and comparing per-cell height); the same lane also carries a
           big non-terrain outlier value (103 in `pl_00_00`, 54 in
           `map24_23`) on furniture/border tiles that isn't part of the
           smooth ramp, suggesting this lane is overloaded (terrain step
           id for most tiles, a different per-object code for a handful
           of special ones) -- not fully separated out this pass.
  byte[0]  MEDIUM.  An edge/boundary marker: near-zero everywhere except
           a thin line of nonzero values that traces the SAME
           ramp/cliff boundary byte[2] marks in `map24_23` (i.e. it
           looks like "this tile is a transition/edge tile" rather than
           a height value itself), and also lights up on the same
           furniture footprint as byte[2] in `pl_00_00` with a distinct
           small value per edge of the object (values 2/4/8/16/24 forming
           a bordered rectangle) -- read as an edge-type/interaction-side
           code, not confirmed against a specific gameplay behaviour.
  byte[1], byte[3], byte[5]  LOW.  Zero in every sample checked across
           all four target files; either unused/reserved in these
           particular maps or hold data this pass's samples didn't
           exercise.
  byte[7]  LOW.    Always 0x00 except a single isolated tile with 0x80
           seen once each in `map14_13` and `map24_23` (no shape
           correlation attempted -- too sparse in the samples on hand to
           say more).

  NOT FOUND: no lane in any of the four sample files distinguishes tall
  grass, water, ledges (one-way), stairs, or doors/warps from ordinary
  walkable floor -- the house's actual door tile decodes to the exact
  same 8-byte record as plain interior floor. The working hypothesis
  (not confirmed) is that these are handled by a separate event/warp/
  behaviour table elsewhere (not in this grid at all), consistent with
  finding zero lanes that vary at the one known door tile. This is
  reported as a real negative result, not a gap in effort: every lane
  was checked at that specific tile.

--------------------------------------------------------------------------
Gaps
--------------------------------------------------------------------------
- `pl_00_00`'s 64x64 grid ends 32 bytes before its header's declared
  grid-end offset; those 32 bytes (16 u16 values, no recognisable
  dimension header) are unexplained.
- GC's second grid and RD's dense secondary block are structurally
  located but not semantically decoded (what a GC dungeon's *second*
  32x32 layer represents, and what the RD dense block's 4-byte records
  mean, are both open).
- The tail bytes after the last grid (a handful to ~150 bytes in most
  samples) are not decoded.
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc as narcmod  # noqa: E402
import nsbmd  # noqa: E402

A008_PATH = os.path.join("extract", "data", "a", "0", "0", "8")

# (expected model name, a/0/0/8 index) -- the mission's named samples plus
# one extra outdoor chunk (map24_23) kept because it has far more terrain
# variety (11 distinct records vs map14_13's 4) and is what the height
# correlation above was actually measured against.
TARGETS = [
    ("pl_00_00", 120),
    ("map14_13", 44),
    ("map24_23", 0),
    ("m_dun0101_00_00", 279),
]


class WrapperError(Exception):
    pass


def parse_wrapper(raw):
    """Returns a dict describing one a/0/0/8 sub-file's wrapper: tag,
    header size table, BMD0 span, and every grid found (each a dict with
    width/height/record_size/data_offset/data_end), plus whatever bytes
    are left over as `tail_offset`/`tail_len`. Grids are located
    generically (by reading a u16,u16 dimension pair and checking the
    implied byte span fits in the file), not by hard-coding per-tag
    counts, so this also works on tags/shapes not in TAG_LAYOUT above.
    """
    if len(raw) < 8:
        raise WrapperError("sub-file too short")
    tag = raw[0:2]
    tag_ver = struct.unpack_from("<H", raw, 2)[0]
    header_len = struct.unpack_from("<I", raw, 4)[0]
    bmd0_off = raw.find(b"BMD0")
    if bmd0_off < 0:
        raise WrapperError("no BMD0 magic found")
    if header_len != bmd0_off:
        # documented as always true; keep going but flag it
        header_len = bmd0_off
    n_size_fields = (header_len - 8) // 4
    size_table = list(struct.unpack_from("<%dI" % n_size_fields, raw, 8))

    magic, bom, version, bmd0_file_size, c_header_size, nblk = \
        struct.unpack_from("<4sHHIHH", raw, bmd0_off)
    bmd0_end = bmd0_off + bmd0_file_size

    # Only the first grid is located purely by its self-describing
    # u16,u16 header (checked against a plausible size range). Any
    # FURTHER grid is only accepted if its dimensions exactly match the
    # first one -- the one confirmed multi-grid shape (GC-tagged dungeon
    # rooms carry two identical-size grids back to back). Without this
    # restriction, tail bytes (small unstructured integers) coincidentally
    # parse as a second "plausible" tiny grid (e.g. 17x1, 5x2) often
    # enough to be a real false-positive risk -- seen and ruled out on
    # `pl_00_00` and `map24_23` while writing this tool.
    grids = []
    pos = bmd0_end
    first_dims = None
    while pos + 4 <= len(raw):
        gw, gh = struct.unpack_from("<HH", raw, pos)
        if first_dims is None:
            if not (1 <= gw <= 128 and 1 <= gh <= 128):
                break
        elif (gw, gh) != first_dims:
            break
        data_off = pos + 4
        data_end = data_off + gw * gh * 8
        if data_end > len(raw):
            break
        grids.append({
            "width": gw, "height": gh, "record_size": 8,
            "header_offset": pos, "data_offset": data_off,
            "data_end": data_end,
        })
        if first_dims is None:
            first_dims = (gw, gh)
        pos = data_end

    tail_offset = pos
    tail_len = len(raw) - pos

    # RD-style dense secondary block (seen on all 8 "wf_*"/"bc_*" RD-tag
    # samples): a 4-byte value that does NOT read as a sane (width,
    # height) u16 pair (e.g. 4094,0 -- rejected by the grid scan above),
    # followed by exactly 64*64*4 = 16384 bytes -- the right size for a
    # 64x64 grid of 4-byte records, one quarter the record width of the
    # ordinary grid, at the same 64x64 resolution `pl_00_00`'s indoor
    # grid also happens to use. Detected purely by size (4 + 16384 bytes
    # exactly); the leading 4-byte value's meaning and the record
    # layout inside are NOT decoded this pass (LOW confidence / open gap
    # -- see module docstring).
    dense_grid = None
    if tail_len == 4 + 64 * 64 * 4:
        dense_header_value = struct.unpack_from("<I", raw, tail_offset)[0]
        dense_grid = {
            "width": 64, "height": 64, "record_size": 4,
            "header_offset": tail_offset, "header_value": dense_header_value,
            "data_offset": tail_offset + 4,
            "data_end": tail_offset + tail_len,
        }
        tail_offset = dense_grid["data_end"]
        tail_len = 0

    return {
        "tag": tag.decode("ascii", "replace"),
        "tag_ver": tag_ver,
        "header_len": header_len,
        "size_table": size_table,
        "bmd0_offset": bmd0_off,
        "bmd0_file_size": bmd0_file_size,
        "bmd0_end": bmd0_end,
        "grids": grids,
        "dense_grid": dense_grid,
        "tail_offset": tail_offset,
        "tail_len": tail_len,
        "total_len": len(raw),
    }


def read_records(raw, grid):
    """Returns a flat list of `width*height` byte-strings, each
    `record_size` bytes, row-major."""
    w, h, rs = grid["width"], grid["height"], grid["record_size"]
    off = grid["data_offset"]
    return [raw[off + i * rs: off + (i + 1) * rs] for i in range(w * h)]


def model_name(a008, index):
    raw = a008.read(index)
    pos = raw.find(b"BMD0")
    try:
        c = nsbmd.parse_container(raw[pos:])
        mdl0 = nsbmd.find_mdl0(c)
        if mdl0 is not None and mdl0.model_dict.names:
            return mdl0.model_dict.names[0]
    except nsbmd.Nsbmd0Error:
        pass
    return None


# ---------------------------------------------------------------------------
# Text dump
# ---------------------------------------------------------------------------

def dump_lane_text(records, width, height, lane, path):
    parent = os.path.dirname(os.path.abspath(path))
    if parent:
        os.makedirs(parent, exist_ok=True)
    with open(path, "w") as fh:
        for row in range(height):
            vals = (records[row * width + col][lane] for col in range(width))
            fh.write(" ".join(f"{v:02x}" for v in vals) + "\n")


def dump_header_info(info, name, path):
    parent = os.path.dirname(os.path.abspath(path))
    if parent:
        os.makedirs(parent, exist_ok=True)
    with open(path, "w") as fh:
        fh.write(f"model: {name}\n")
        fh.write(f"tag: {info['tag']} (tag_ver=0x{info['tag_ver']:04x})\n")
        fh.write(f"header_len: {info['header_len']}\n")
        fh.write(f"size_table (u32s after tag+header_len): {info['size_table']}\n")
        fh.write(f"bmd0_offset: {info['bmd0_offset']}\n")
        fh.write(f"bmd0_file_size: {info['bmd0_file_size']}\n")
        fh.write(f"bmd0_end: {info['bmd0_end']}\n")
        fh.write(f"total_len: {info['total_len']}\n")
        fh.write(f"n_grids: {len(info['grids'])}\n")
        for i, g in enumerate(info["grids"]):
            fh.write(f"  grid[{i}]: {g['width']}x{g['height']}, "
                     f"record_size={g['record_size']}, "
                     f"header_offset={g['header_offset']}, "
                     f"data=[{g['data_offset']}:{g['data_end']}]\n")
        if info["dense_grid"] is not None:
            g = info["dense_grid"]
            fh.write(f"  dense_grid (RD-style, no dim header): "
                     f"{g['width']}x{g['height']}, record_size={g['record_size']}, "
                     f"data=[{g['data_offset']}:{g['data_end']}]\n")
        fh.write(f"tail: [{info['tail_offset']}:{info['tail_offset']+info['tail_len']}] "
                 f"({info['tail_len']} bytes)\n")
        if info["tail_len"]:
            raw_tail = None  # filled in by caller if needed
            fh.write("tail_hex: (see raw sub-file; not duplicated here)\n")


# ---------------------------------------------------------------------------
# False-colour PNG per lane
# ---------------------------------------------------------------------------

# A small qualitative palette (distinct hues), extended by simple hashing
# if a lane has more distinct values than this covers.
_BASE_PALETTE = [
    (30, 30, 30), (220, 40, 40), (40, 160, 60), (50, 100, 220),
    (230, 190, 30), (200, 60, 200), (40, 200, 200), (240, 130, 30),
    (140, 90, 40), (230, 230, 230), (120, 40, 160), (40, 120, 40),
]


def value_color(rank, total):
    if rank < len(_BASE_PALETTE):
        return _BASE_PALETTE[rank]
    # deterministic fallback for lanes with lots of distinct values
    h = (rank * 2654435761) & 0xFFFFFF
    return (h & 0xFF, (h >> 8) & 0xFF, (h >> 16) & 0xFF)


def write_lane_png(records, width, height, lane, path, cell_px=8):
    vals = [r[lane] for r in records]
    uniq = sorted(set(vals))
    color_of = {v: value_color(i, len(uniq)) for i, v in enumerate(uniq)}
    px_w, px_h = width * cell_px, height * cell_px
    rgba = bytearray(px_w * px_h * 4)
    for row in range(height):
        for col in range(width):
            v = records[row * width + col][lane]
            r, g, b = color_of[v]
            for dy in range(cell_px):
                base_row = (row * cell_px + dy) * px_w
                for dx in range(cell_px):
                    o = (base_row + col * cell_px + dx) * 4
                    rgba[o] = r
                    rgba[o + 1] = g
                    rgba[o + 2] = b
                    rgba[o + 3] = 255
    nsbmd.write_png_rgba8(path, px_w, px_h, bytes(rgba))
    return uniq


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def process_target(a008, name, index, out_dir, do_dump, do_png):
    raw = a008.read(index)
    info = parse_wrapper(raw)
    real_name = model_name(a008, index) or name
    print(f"[*] a/0/0/8#{index} '{real_name}' -- tag={info['tag']} "
          f"n_grids={len(info['grids'])} dense_grid={'yes' if info['dense_grid'] else 'no'} "
          f"tail_len={info['tail_len']}")

    dump_header_info(info, real_name, os.path.join(out_dir, f"{name}_wrapper.txt"))

    all_grids = list(info["grids"])
    if info["dense_grid"] is not None:
        all_grids.append(info["dense_grid"])

    for gi, grid in enumerate(all_grids):
        records = read_records(raw, grid)
        w, h, rs = grid["width"], grid["height"], grid["record_size"]
        suffix = f"_grid{gi}" if len(all_grids) > 1 else "_grid"
        for lane in range(rs):
            if do_dump:
                path = os.path.join(out_dir, f"{name}{suffix}_lane{lane}.txt")
                dump_lane_text(records, w, h, lane, path)
            if do_png:
                path = os.path.join(out_dir, f"{name}{suffix}_lane{lane}.png")
                uniq = write_lane_png(records, w, h, lane, path)
                print(f"    grid{gi} lane{lane}: {len(uniq)} distinct values -> {path}")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--out", default=os.path.join("build", "assets", "maps"))
    ap.add_argument("--targets", nargs="*",
                     help="subset of target names to process (default: all)")
    ap.add_argument("--dump", action="store_true", help="write per-lane text matrices")
    ap.add_argument("--png", action="store_true", help="write per-lane false-colour PNGs")
    args = ap.parse_args(argv)

    if not args.dump and not args.png:
        args.dump = True
        args.png = True

    a008 = narcmod.parse_file(A008_PATH)
    os.makedirs(args.out, exist_ok=True)
    wanted = set(args.targets) if args.targets else None

    for name, index in TARGETS:
        if wanted is not None and name not in wanted:
            continue
        process_target(a008, name, index, args.out, args.dump, args.png)

    return 0


if __name__ == "__main__":
    sys.exit(main())
