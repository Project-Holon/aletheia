#!/usr/bin/env python3
"""
battle_sprite.py -- decoder for the battle sprite archive `a/1/3/4`.

Written from scratch for the aletheia project. Stdlib only, single file.

--------------------------------------------------------------------------
Payload format (recovered by inspection, see docs/ASSETS.md)
--------------------------------------------------------------------------
`a/1/3/4` is a 670-entry NARC (649 species + a handful of forms/genders).
Every sub-file is LZ11-compressed (`tools/assets/narc.py`'s decoder), and
every one decompresses to *exactly* 0x20000 (131072) bytes -- the LZ11
header's own 24-bit size field is 0x020000 on all four samples checked
(indices 0, 1, 25, 150), so this is a format-level constant, not a
coincidence of the sample.

The decompressed payload carries **no NITRO chunk magic** (no RGCN/NCGR,
RLCN/NCLR, RECN/NCER, RNAN/NANR anywhere) and **no palette**: it is Game
Freak's own bare tile format, just raw 4bpp character (tile) data, nothing
else. Evidence for the layout:

- Sub-file 0 (species slot 0, presumably unused/reserved) decodes to the
  byte pair 0x00,0x80 repeated for the entire 131072 bytes -- a filler
  pattern, not real pixel data. Diffing every other sample against this
  filler isolates where real tile data lives.
- The isolated real-content region is bounded by **512-byte-aligned
  "rows"**: for sub-file 25 content runs start exactly every 0x200 bytes
  (0x0, 0x200, 0x400, ... up to 0x4000) with a content span of ~330-370
  bytes then filler for the rest of that row, repeating cleanly 32 times
  before the remaining 0x1C000 bytes are pure filler. For sub-file 1 the
  per-row content-start offset increases by ~2 bytes every row (137, 137,
  139, 139, 139, 141, ...) -- a smooth diagonal, i.e. a real silhouette
  edge, not noise, and every one of those offsets differs from a tile
  boundary by 1-31 bytes (not a coincidence of row alignment alone).
- 512 bytes / 32 bytes-per-4bpp-tile = 16 tiles. Standard NDS "2D" tile
  addressing (tile_index = tile_row * tiles_per_row + tile_col, each tile
  8x8 pixels/32 bytes) with **16 tiles per row = 128 px width** reproduces
  the observed 512-byte row stride exactly, and is consistent with the
  diagonal edge above only being tile-row-periodic (not tile-column-
  periodic), which is what a fixed image width + variable per-row content
  produces.
- 131072 bytes total / 512 bytes per 8px-tall tile-row = 256 tile-rows =
  2048 px of vertical canvas. Real content for the two smaller samples
  (species 1, 25) stops after 32 tile-rows (256 px), i.e. well short of
  the full canvas -- consistent with a **fixed maximum canvas sized for
  the largest sprite** (something like Wailord), with unused rows left as
  filler. Species 150 uses content-like bytes across the whole buffer,
  which is expected once "background = filler pattern" stops holding (a
  species whose own background/transparent index does not happen to equal
  the 0x0080 pattern will differ from the filler everywhere, not just
  where the silhouette is).

No palette (NCLR) sub-chunk was found anywhere in this archive's
sub-files, so pixel *color* cannot be reconstructed from `a/1/3/4` alone --
only pixel *index* (0-15, 4bpp). This tool renders index-as-grayscale
(index * 17, filling the 0-255 range) so shapes are visible without a
recovered palette; the real in-game palette is presumably paired in via
whichever code loads this archive (not investigated here, out of scope
for this lane).

A 128 x 2048 4bpp canvas is a plausible **multi-frame animation strip**:
128x128 would be a generous single sprite frame, and 2048 / 128 = 16
frames stacked vertically. The two small samples using exactly 32 tile-
rows (256 px = 2 stacked 128-px frames) is consistent with a simple
2-frame idle "breathing" animation, matching Black/White's known battle
sprite animation style, though this tool does not attempt to split frames
automatically (it renders the whole canvas; a human can visually locate
the frame boundary from the PNG once palette-less grayscale content is
visible).

--------------------------------------------------------------------------
Usage
--------------------------------------------------------------------------
    python tools/assets/battle_sprite.py 1                # decode sub-file 1
    python tools/assets/battle_sprite.py 1 --trim          # crop trailing filler
    python tools/assets/battle_sprite.py --all              # decode all 670
"""

import argparse
import os
import struct
import sys
import zlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402

ARCHIVE_PATH = os.path.join("extract", "data", "a", "1", "3", "4")
OUT_DIR = os.path.join("build", "assets", "battle")

CANVAS_WIDTH_PX = 128
TILES_PER_ROW = CANVAS_WIDTH_PX // 8
TILE_BYTES_4BPP = 32
ROW_STRIDE_BYTES = TILES_PER_ROW * TILE_BYTES_4BPP  # 512

# The species-0 slot is pure filler (0x00, 0x80 repeating) -- used as the
# reference pattern to detect "real content" rows when trimming.
FILLER_PERIOD = bytes([0x00, 0x80])


def decode_subfile_raw(data):
    """Decompress one a/1/3/4 sub-file (LZ11) to its 0x20000-byte payload."""
    kind, dec = narc.try_decompress(data)
    if kind != "LZ11" or dec is None:
        raise ValueError(f"expected an LZ11 sub-file, got kind={kind!r}")
    return dec


def unpack_4bpp_tiles(payload, width_px=CANVAS_WIDTH_PX):
    """Unpack a raw 4bpp NDS-tiled buffer into a row-major list of pixel
    index bytes (0-15), image width `width_px`. Standard NDS "2D" tile
    addressing: tile_index = tile_row * tiles_per_row + tile_col, each
    tile stored as 8 rows of 4 bytes (8 nibbles), low nibble first.
    """
    tiles_per_row = width_px // 8
    tile_count = len(payload) // TILE_BYTES_4BPP
    tile_rows = tile_count // tiles_per_row
    height_px = tile_rows * 8
    pixels = bytearray(width_px * height_px)
    for ty in range(tile_rows):
        for tx in range(tiles_per_row):
            tile_index = ty * tiles_per_row + tx
            tile_off = tile_index * TILE_BYTES_4BPP
            for ly in range(8):
                row_off = tile_off + ly * 4
                py = ty * 8 + ly
                dst_row = py * width_px + tx * 8
                for lx4 in range(4):
                    b = payload[row_off + lx4]
                    px0 = tx * 8 + lx4 * 2
                    pixels[py * width_px + px0] = b & 0x0F
                    pixels[py * width_px + px0 + 1] = (b >> 4) & 0x0F
    return pixels, width_px, height_px


def trim_filler_rows(payload):
    """Return the byte length of the leading region of `payload` up to
    (and including) the last 512-byte row that is not entirely the
    species-0 filler pattern. Used for --trim to avoid emitting mostly
    blank canvas for small sprites."""
    last_nonfiller_row = -1
    n_rows = len(payload) // ROW_STRIDE_BYTES
    for r in range(n_rows):
        row = payload[r * ROW_STRIDE_BYTES:(r + 1) * ROW_STRIDE_BYTES]
        is_filler = all(
            row[i] == FILLER_PERIOD[i % 2] for i in range(len(row))
        )
        if not is_filler:
            last_nonfiller_row = r
    if last_nonfiller_row < 0:
        return ROW_STRIDE_BYTES  # entirely filler; keep one row so the PNG isn't empty
    return (last_nonfiller_row + 1) * ROW_STRIDE_BYTES


# ---------------------------------------------------------------------------
# Minimal stdlib PNG writer (8-bit grayscale)
# ---------------------------------------------------------------------------

def write_png_gray8(path, width, height, gray_bytes):
    """Write an 8-bit grayscale PNG using only zlib + struct (no Pillow)."""

    def chunk(tag, data):
        out = struct.pack(">I", len(data)) + tag + data
        crc = zlib.crc32(tag)
        crc = zlib.crc32(data, crc) & 0xFFFFFFFF
        out += struct.pack(">I", crc)
        return out

    sig = b"\x89PNG\r\n\x1a\n"
    ihdr = struct.pack(">IIBBBBB", width, height, 8, 0, 0, 0, 0)  # color type 0 = grayscale
    raw = bytearray()
    for y in range(height):
        raw.append(0)  # filter type 0 (none) per scanline
        raw.extend(gray_bytes[y * width:(y + 1) * width])
    idat = zlib.compress(bytes(raw), 9)
    with open(path, "wb") as fh:
        fh.write(sig)
        fh.write(chunk(b"IHDR", ihdr))
        fh.write(chunk(b"IDAT", idat))
        fh.write(chunk(b"IEND", b""))


def indices_to_gray(pixels):
    return bytes((p * 17) & 0xFF for p in pixels)  # 0..15 -> 0..255


def decode_one(narc_obj, index, out_dir, trim):
    raw = narc_obj.read(index)
    payload = decode_subfile_raw(raw)
    if trim:
        payload = payload[:trim_filler_rows(payload)]
    pixels, w, h = unpack_4bpp_tiles(payload)
    gray = indices_to_gray(pixels)
    out_path = os.path.join(out_dir, f"{index:04d}.png")
    write_png_gray8(out_path, w, h, gray)
    return out_path, w, h, len(raw)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("index", type=int, nargs="?",
                     help="sub-file index to decode (omit with --all)")
    ap.add_argument("--all", action="store_true",
                     help="decode every sub-file in the archive")
    ap.add_argument("--trim", action="store_true",
                     help="crop trailing all-filler tile-rows from the output PNG")
    ap.add_argument("--archive", default=ARCHIVE_PATH,
                     help=f"NARC path (default: {ARCHIVE_PATH})")
    ap.add_argument("--out", default=OUT_DIR,
                     help=f"output directory (default: {OUT_DIR})")
    args = ap.parse_args(argv)

    if not args.all and args.index is None:
        ap.error("give an index or pass --all")

    os.makedirs(args.out, exist_ok=True)
    n = narc.parse_file(args.archive)

    if args.all:
        ok = 0
        fail = 0
        for i in range(n.file_count):
            try:
                out_path, w, h, raw_size = decode_one(n, i, args.out, args.trim)
                ok += 1
            except Exception as exc:
                fail += 1
                print(f"[!] sub-file {i}: {exc}", file=sys.stderr)
        print(f"[*] decoded {ok}/{n.file_count} sub-files to {args.out} "
              f"({fail} failed)")
        return 0 if fail == 0 else 1

    out_path, w, h, raw_size = decode_one(n, args.index, args.out, args.trim)
    print(f"[*] sub-file {args.index}: {raw_size} bytes compressed -> "
          f"{w}x{h} 4bpp grayscale PNG -> {out_path}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
