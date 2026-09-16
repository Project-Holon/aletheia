#!/usr/bin/env python3
"""
icons.py -- decoder for the small-icon archive `a/1/6/7`.

Written from scratch for aletheia. Stdlib only, single file.

--------------------------------------------------------------------------
Archive layout (recovered by inspection, see docs/ASSETS.md "Icon archive
a/1/6/7")
--------------------------------------------------------------------------
`a/1/6/7` is a 655-sub-file NARC:

    index 0        RLCN/NCLR palette, uncompressed, 552 bytes, 256 colors
    index 1, 3     RNAN/NANR (cell animation), uncompressed
    index 2, 4     RECN/NCER (cell bank), uncompressed
    index 5..654   650 icon graphics, one per species/form slot (species
                   index N lives at sub-file index N + 5), each a BIOS
                   LZ77-compressed (tag 0x10) RGCN/NCGR chunk

Every one of the 650 icon sub-files decompresses to *exactly* 304 bytes,
and the first 48 bytes (the whole NCGR common header + CHAR block header +
CHAR body sub-header) are byte-identical across all 650 -- confirmed by a
full scan, not just a sample. Only the last 256 bytes (the CHAR block's
tile data, 8 4bpp tiles of 32 bytes each) vary per icon.

The CHAR sub-header (standard NCGR "CHAR" block layout, general NDS
graphics format knowledge, not specific to any decomp project):

    0x00  u16 tiles_y       0xFFFF here = "unspecified, derive from data"
    0x02  u16 tiles_x       0xFFFF here = "unspecified, derive from data"
    0x04  u32 bitdepth      3 here = 4bpp (this ROM's own convention: 3 =
                             4bpp, 4 = 8bpp; not decoded from any outside
                             spec, just what the bitdepth value implies
                             once combined with the 256-color-capacity
                             palette below and the tile-count arithmetic)
    0x08  u32 unknown       constant 0x00200010 across all 650, meaning
                             not determined
    0x0C  u32 tile_flag     constant 0 (2D/linear tile mapping)
    0x10  u32 tile_data_size  256 (bytes) -- confirmed against every file
    0x14  u32 tile_data_offset  24 (bytes, i.e. right after this header) --
                             a self-consistency pointer, also confirmed

256 tile-data bytes / 32 bytes-per-4bpp-tile = 8 tiles. With a canvas 4
tiles wide (32 px) that is 2 tile-rows (16 px) tall. Evidence for "4 tiles
wide, real content in the left half only":

- Tiles at (column, row) = (2, 0), (3, 0), (2, 1), (3, 1) (the right two
  columns) are **exactly the byte pattern 0xCC repeated for all 32 bytes,
  in all 650 icon sub-files** -- a fixed sentinel/filler tile, the same
  "known filler pattern marks unused canvas" trick documented for the
  battle-sprite archive `a/1/3/4` (see `tools/assets/battle_sprite.py`),
  just with a different constant byte.
- The left two columns ((0, 0), (1, 0), (0, 1), (1, 1)) vary freely per
  icon and are where all the real pixel content lives.

So the real icon is **16x16 pixels, 4bpp**, packed into a 32x16 (4-tile x
2-tile) canvas whose right half is filler. 16x16 4bpp is 128 bytes -- this
matches the a-priori estimate for a small NDS icon exactly.

--------------------------------------------------------------------------
Palette
--------------------------------------------------------------------------
Sub-file 0 is a single shared RLCN/NCLR palette (`battle_sprite.parse_nclr`
parses it, same TTLP-block format used for the battle-sprite palettes).
It declares the full 256-color capacity a TTLP block can hold (data_size
0x200 = 512 bytes = 256 u16 BGR555 colors), so at a glance this looks like
"16 banks of 16 colors, one bank selected per species" -- the pattern the
mission brief expected ("a small shared palette bank with a per-species
palette index").

That turned out **not** to be what is actually stored: of the 256 color
slots, only **2 are non-zero** -- slot 0 (BGR555 0x7FFF = white) and slot 7
(also 0x7FFF = white); every other slot, across the entire 256-entry
table, is the literal zero word (which decodes to black). Banks 1-15 are
therefore all-black, not 15 more hand-picked species colors. This was
checked directly (`struct.unpack('<256H', ...)`, 254 zero words, 2 equal
to 0x7FFF) -- it is not a parsing bug in the TTLP reader (the same reader
is verified elsewhere against known battle-sprite colors, see
`docs/ASSETS.md` "Battle sprite colors").

Consequence: **this archive's icons are genuinely monochrome (black and
white), not full-color species icons with a per-species palette-bank
selector.** A systematic search (below) for a companion "per-species
palette index" table came up empty, which is now expected given the
palette itself carries no per-bank color information to select between.
This directly narrows what "species icons, true color" can mean for this
archive: this tool renders the real recovered palette (bank 0, the only
bank with any non-black color) rather than a synthetic grayscale ramp, but
that palette itself is just black-and-white. Whatever full-color species
icon set Black/White actually uses (if `a/1/6/7` is even that set, see
"Honesty notes" below) is not proven to be reachable from this archive
alone.

**Palette-index-table search performed and its result:** every NARC in
`extract/data/` was scanned for a sub-file count in 640-660 with a small,
uniform per-entry size (candidate for a one-byte-per-species palette/bank
selector). Two matches: `a/0/2/0` (650 entries x 2 bytes, values 0-649,
tightly grouped in runs of 2-4 consecutive identical values -- looks like
an evolution-family/base-species index, not a palette selector: cross-
checking it against `a/1/6/7`'s icon-content duplicate groups (below)
found no correlation) and `a/1/2/3` (650 entries, variable 0-34 bytes,
shape of a text/movepool table, not a fixed small record). Neither is a
confirmed palette-bank table. No 649/650/655-entry table of 1-byte
records with values capped at 15 (the range a 4bpp-bank selector would
need) was found anywhere in `extract/data/`.

--------------------------------------------------------------------------
Usage
--------------------------------------------------------------------------
    python tools/assets/icons.py --all              # render every icon
    python tools/assets/icons.py --all --roundtrip   # also verify round trip
    python tools/assets/icons.py 25                  # render species 25 only
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc      # noqa: E402
import lz77       # noqa: E402
import battle_sprite as bs  # noqa: E402  (parse_nclr, write_png_rgb8, indices_to_rgb)

ARCHIVE_PATH = os.path.join("extract", "data", "a", "1", "6", "7")
OUT_DIR = os.path.join("build", "assets", "icons")

PALETTE_INDEX = 0
FIRST_ICON_INDEX = 5
ICON_COUNT = 650

TILE_BYTES_4BPP = 32
CANVAS_TILES_WIDE = 4
FILLER_TILE = bytes([0xCC] * TILE_BYTES_4BPP)

ICON_WIDTH = 16
ICON_HEIGHT = 16
ICON_TILES_WIDE = 2
ICON_TILES_TALL = 2

# The whole 48-byte NCGR-common-header + CHAR-block-header + CHAR-body
# sub-header, byte-identical across all 650 icon sub-files (see module
# docstring). Captured once, reused to rebuild an exact payload from
# decoded pixels for the round-trip check.
_HEADER_TEMPLATE = bytes.fromhex(
    "5247434efffe010130010000100001005241484320010000"
    "ffffffff0300000010002000000000000001000018000000"
)
PAYLOAD_SIZE = len(_HEADER_TEMPLATE) + 256  # 304
TILE_DATA_OFFSET = len(_HEADER_TEMPLATE)    # 48


def decode_subfile_raw(data):
    """Decompress one a/1/6/7 icon sub-file (LZ77) to its 304-byte payload,
    checking the header matches the fixed template found across all 650."""
    kind, dec = narc.try_decompress(data)
    if kind != "LZ77" or dec is None:
        raise ValueError(f"expected an LZ77 icon sub-file, got kind={kind!r}")
    if len(dec) != PAYLOAD_SIZE:
        raise ValueError(f"unexpected decompressed size {len(dec)}, expected {PAYLOAD_SIZE}")
    if dec[:TILE_DATA_OFFSET] != _HEADER_TEMPLATE:
        raise ValueError("NCGR/CHAR header does not match the fixed template "
                          "(a genuinely varying header was not expected)")
    return dec


def unpack_icon_pixels(tile_data):
    """Extract the real 16x16 4bpp icon from the 256-byte, 8-tile (4 wide x
    2 tall) tile-data buffer. Tiles in columns 2-3 are filler (see module
    docstring) and are not read here; the caller can verify them separately.
    Returns a flat row-major bytearray of 256 nibble values (0-15)."""
    pixels = bytearray(ICON_WIDTH * ICON_HEIGHT)
    for ty in range(ICON_TILES_TALL):
        for tx in range(ICON_TILES_WIDE):
            tile_index = ty * CANVAS_TILES_WIDE + tx
            tile_off = tile_index * TILE_BYTES_4BPP
            for ly in range(8):
                row = tile_data[tile_off + ly * 4: tile_off + ly * 4 + 4]
                py = ty * 8 + ly
                for lx4 in range(4):
                    b = row[lx4]
                    px0 = tx * 8 + lx4 * 2
                    pixels[py * ICON_WIDTH + px0] = b & 0x0F
                    pixels[py * ICON_WIDTH + px0 + 1] = (b >> 4) & 0x0F
    return pixels


def check_filler(tile_data):
    """Return True iff the two right-hand tile columns (indices 2,3 and
    6,7) are exactly the 0xCC filler tile, as found in all 650 icons."""
    for tile_index in (2, 3, 6, 7):
        off = tile_index * TILE_BYTES_4BPP
        if tile_data[off:off + TILE_BYTES_4BPP] != FILLER_TILE:
            return False
    return True


def pack_icon_pixels(pixels):
    """Inverse of unpack_icon_pixels + the fixed filler: rebuild the exact
    256-byte tile-data buffer (8 tiles, 4 wide x 2 tall) from a 16x16
    nibble-pixel buffer, re-inserting the 0xCC filler tiles in columns 2-3."""
    tile_data = bytearray(8 * TILE_BYTES_4BPP)
    for tile_index in range(8):
        off = tile_index * TILE_BYTES_4BPP
        tile_data[off:off + TILE_BYTES_4BPP] = FILLER_TILE
    for ty in range(ICON_TILES_TALL):
        for tx in range(ICON_TILES_WIDE):
            tile_index = ty * CANVAS_TILES_WIDE + tx
            tile_off = tile_index * TILE_BYTES_4BPP
            for ly in range(8):
                py = ty * 8 + ly
                row = bytearray(4)
                for lx4 in range(4):
                    px0 = tx * 8 + lx4 * 2
                    lo = pixels[py * ICON_WIDTH + px0] & 0x0F
                    hi = pixels[py * ICON_WIDTH + px0 + 1] & 0x0F
                    row[lx4] = lo | (hi << 4)
                tile_data[tile_off + ly * 4: tile_off + ly * 4 + 4] = row
    return bytes(tile_data)


def pixels_to_payload(pixels):
    """Rebuild the full 304-byte decompressed NCGR payload from a 16x16
    nibble-pixel buffer, using the fixed header template."""
    tile_data = pack_icon_pixels(pixels)
    return _HEADER_TEMPLATE + tile_data


def load_palette(narc_obj):
    """Parse the shared RLCN/NCLR palette (sub-file 0). Returns a list of
    256 (r, g, b) tuples; only the first 16 (bank 0) carry any non-black
    color -- see module docstring."""
    raw = narc_obj.read(PALETTE_INDEX)
    return bs.parse_nclr(raw)


def render_all(narc_obj, out_dir, palette):
    os.makedirs(out_dir, exist_ok=True)
    bank0 = palette[:16]
    ok = 0
    fail = 0
    for species in range(ICON_COUNT):
        idx = species + FIRST_ICON_INDEX
        try:
            raw = narc_obj.read(idx)
            dec = decode_subfile_raw(raw)
            tile_data = dec[TILE_DATA_OFFSET:TILE_DATA_OFFSET + 256]
            if not check_filler(tile_data):
                raise ValueError("filler-tile check failed (unexpected real "
                                  "content in the padding columns)")
            pixels = unpack_icon_pixels(tile_data)
            rgb = bs.indices_to_rgb(pixels, bank0)
            out_path = os.path.join(out_dir, f"{species:04d}.png")
            bs.write_png_rgb8(out_path, ICON_WIDTH, ICON_HEIGHT, rgb)
            ok += 1
        except Exception as exc:
            fail += 1
            print(f"[!] species {species} (sub-file {idx}): {exc}", file=sys.stderr)
    print(f"[*] rendered {ok}/{ICON_COUNT} icons to {out_dir} ({fail} failed)")
    return ok, fail


def roundtrip_all(narc_obj):
    """Verify byte-identity for all 655 sub-files of the archive:
    - the 650 icon sub-files: decompress -> unpack pixels -> repack pixels
      -> rebuild the NCGR payload -> LZ77-compress -> compare to the
      original raw sub-file bytes.
    - the other 5 sub-files (palette, 2x NANR, 2x NCER): these carry no
      compression header (verified via narc.sniff_compression) and are
      stored as plain bytes in the NARC, so their "round trip" is the
      trivial identity copy; still counted so all 655 are covered.
    """
    ok = 0
    fail = 0
    fail_list = []
    for idx in range(narc_obj.file_count):
        raw = narc_obj.read(idx)
        if FIRST_ICON_INDEX <= idx < FIRST_ICON_INDEX + ICON_COUNT:
            try:
                dec = decode_subfile_raw(raw)
                tile_data = dec[TILE_DATA_OFFSET:TILE_DATA_OFFSET + 256]
                pixels = unpack_icon_pixels(tile_data)
                payload = pixels_to_payload(pixels)
                if payload != dec:
                    raise ValueError("repacked payload does not match decompressed original")
                enc = lz77.compress(payload)
                if enc != raw:
                    raise ValueError(f"re-compressed bytes differ (len {len(enc)} vs {len(raw)})")
            except Exception as exc:
                fail += 1
                fail_list.append((idx, str(exc)))
                continue
        else:
            info = narc.sniff_compression(raw)
            if info is not None:
                fail += 1
                fail_list.append((idx, f"unexpected compression header {info}"))
                continue
        ok += 1
    print(f"[*] round-trip: {ok}/{narc_obj.file_count} sub-files byte-identical ({fail} failed)")
    for idx, msg in fail_list[:20]:
        print(f"    [!] sub-file {idx}: {msg}", file=sys.stderr)
    return ok, fail


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("species", type=int, nargs="?",
                     help="species/form index to decode (0..649); omit with --all")
    ap.add_argument("--all", action="store_true", help="render every icon")
    ap.add_argument("--roundtrip", action="store_true",
                     help="also run the full 655-sub-file round-trip check")
    ap.add_argument("--archive", default=ARCHIVE_PATH)
    ap.add_argument("--out", default=OUT_DIR)
    args = ap.parse_args(argv)

    if not args.all and args.species is None and not args.roundtrip:
        ap.error("give a species index, --all, or --roundtrip")

    n = narc.parse_file(args.archive)
    palette = load_palette(n)

    if args.all:
        render_all(n, args.out, palette)

    if args.species is not None:
        idx = args.species + FIRST_ICON_INDEX
        raw = n.read(idx)
        dec = decode_subfile_raw(raw)
        tile_data = dec[TILE_DATA_OFFSET:TILE_DATA_OFFSET + 256]
        if not check_filler(tile_data):
            print("[!] filler-tile check failed", file=sys.stderr)
        pixels = unpack_icon_pixels(tile_data)
        rgb = bs.indices_to_rgb(pixels, palette[:16])
        os.makedirs(args.out, exist_ok=True)
        out_path = os.path.join(args.out, f"{args.species:04d}.png")
        bs.write_png_rgb8(out_path, ICON_WIDTH, ICON_HEIGHT, rgb)
        print(f"[*] species {args.species}: {len(raw)} bytes compressed -> "
              f"{ICON_WIDTH}x{ICON_HEIGHT} 4bpp RGB PNG -> {out_path}")

    if args.roundtrip:
        roundtrip_all(n)

    return 0


if __name__ == "__main__":
    sys.exit(main())
