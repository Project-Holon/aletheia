#!/usr/bin/env python3
"""
battle_sprite.py -- decoder for `a/1/3/4`.

**Name is now known to be a misnomer**: `a/1/3/4` is NOT trainer/Pokemon
battle sprite art. A dedicated asset lane pass rendered and eyeballed all
670 entries (`--contact-sheets`) and confirmed the archive is a rendered
cinematic (an intro-movie-shaped sequence featuring N) stored as full
256x256 16bpp frames -- see docs/ASSETS.md "a/1/3/4 hypothesis test -- NOT
trainer battle art, confirmed as opening-cinematic frame sequence" for the
full writeup. Use `--raw16` to decode the real (16bpp direct-color) pixel
format; the 4bpp-tiled path below (this module's original guess) is kept
only because it may still be correct for some other LZ11-no-magic archive,
not this one. The file was not renamed/restructured this pass (see that
section's "remaining gaps" for why).

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

# --------------------------------------------------------------------------
# Palette source (fourth asset lane pass, see docs/ASSETS.md "Battle sprite
# colors")
# --------------------------------------------------------------------------
# `a/1/3/4` itself carries no palette (confirmed in the third lane pass).
# `a/0/0/4` (14285 sub-files, previously guessed "overworld/menu sprites")
# turns out to hold real per-species NCLR (on-disk magic "RLCN") palettes at
# a fixed stride: for species/form index N, a normal-mode palette sits at
# sub-file index PALETTE_STRIDE*N + PALETTE_NORMAL_OFFSET and a shiny-mode
# palette immediately after it, at + PALETTE_SHINY_OFFSET. Recovered by
# scanning the RLCN sub-file indices across the whole archive (they land in
# pairs 20 apart with only one exception out of 1457 hits) and confirmed by
# decoding real colors: index 38/39 (species 1, Bulbasaur) is green-and-red,
# 518/519 (species 25, Pikachu) is yellow-and-brown, and 3018/3019 (species
# 150, Mewtwo) is lavender-purple for the normal palette and lime-green for
# the shiny one -- exactly Mewtwo's well-known shiny recolor. See
# docs/ASSETS.md for the full sanity-check writeup.
PALETTE_ARCHIVE_PATH = os.path.join("extract", "data", "a", "0", "0", "4")
PALETTE_STRIDE = 20
PALETTE_NORMAL_OFFSET = 18
PALETTE_SHINY_OFFSET = 19


def decode_subfile_raw(data):
    """Decompress one a/1/3/4 sub-file (LZ11) to its 0x20000-byte payload."""
    kind, dec = narc.try_decompress(data)
    if kind != "LZ11" or dec is None:
        raise ValueError(f"expected an LZ11 sub-file, got kind={kind!r}")
    return dec


## ---------------------------------------------------------------------------
## 16bpp direct-color decode (tenth asset lane pass -- see docs/ASSETS.md
## "a/1/3/4 IS the trainer battle art"). The whole 0x20000-byte decompressed
## payload is a linear (non-tiled), row-major 256x256 image of 16-bit
## little-endian A1BGR555 texels: bit 15 is an opacity flag (always set on
## every sample checked, i.e. fully opaque), bits 0-4/5-9/10-14 are 5-bit
## R/G/B channels. This supersedes the third-pass 4bpp-tiled-128-wide
## hypothesis for THIS archive specifically (unpack_4bpp_tiles() above is
## kept only because other archives may share the same LZ11-no-magic
## container shape -- see the sixth-pass writeup).
## ---------------------------------------------------------------------------

RAW16_WIDTH_PX = 256
RAW16_HEIGHT_PX = 256


def unpack_16bpp_direct(payload, width_px=RAW16_WIDTH_PX):
    """Unpack a linear 16bpp A1BGR555 buffer into a flat row-major list of
    (r, g, b) 8-bit tuples. `payload` must be exactly width_px * height_px * 2
    bytes (0x20000 for the 256x256 canvas this archive uses)."""
    n_pixels = len(payload) // 2
    height_px = n_pixels // width_px
    words = struct.unpack_from(f"<{width_px * height_px}H", payload, 0)
    return [bgr555_to_rgb8(w) for w in words], width_px, height_px


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


def write_png_rgb8(path, width, height, rgb_pixels):
    """Write a 24-bit RGB PNG using only zlib + struct. `rgb_pixels` is a
    flat row-major list/bytes of (r, g, b) tuples, one per pixel."""

    def chunk(tag, data):
        out = struct.pack(">I", len(data)) + tag + data
        crc = zlib.crc32(tag)
        crc = zlib.crc32(data, crc) & 0xFFFFFFFF
        out += struct.pack(">I", crc)
        return out

    sig = b"\x89PNG\r\n\x1a\n"
    ihdr = struct.pack(">IIBBBBB", width, height, 8, 2, 0, 0, 0)  # color type 2 = RGB
    raw = bytearray()
    for y in range(height):
        raw.append(0)  # filter type 0 (none) per scanline
        row = rgb_pixels[y * width:(y + 1) * width]
        for r, g, b in row:
            raw.extend((r, g, b))
    idat = zlib.compress(bytes(raw), 9)
    with open(path, "wb") as fh:
        fh.write(sig)
        fh.write(chunk(b"IHDR", ihdr))
        fh.write(chunk(b"IDAT", idat))
        fh.write(chunk(b"IEND", b""))


# ---------------------------------------------------------------------------
# NCLR (on-disk magic "RLCN") palette parsing
# ---------------------------------------------------------------------------
# Standard Nitro resource file shape (generic NDS graphics format, not
# specific to any decomp project): a 16-byte common file header (magic, byte
# order mark, version, file size, header size, block count) followed by one
# TTLP ("PLTT" reversed) block: magic(4) + size(4), then a body of
# bitdepth(u16) + padding(u16) + reserved(u32) + data_size(u32) +
# color_offset(u32), then the color_offset..color_offset+data_size region is
# the raw BGR555 color table (u16 little-endian per color).

def bgr555_to_rgb8(c):
    r = c & 0x1F
    g = (c >> 5) & 0x1F
    b = (c >> 10) & 0x1F
    return (r * 255 // 31, g * 255 // 31, b * 255 // 31)


def parse_nclr(data):
    """Parse an RLCN (NCLR) sub-file. Returns a list of (r, g, b) tuples."""
    if len(data) < 16 or data[:4] != b"RLCN":
        raise ValueError("not an RLCN (NCLR) sub-file")
    header_size, = struct.unpack_from("<H", data, 0x0C)
    pos = header_size
    if pos + 8 > len(data):
        raise ValueError("RLCN file header size runs past end of data")
    pmagic, psize = struct.unpack_from("<4sI", data, pos)
    if pmagic != b"TTLP":
        raise ValueError(f"expected TTLP block, found {pmagic!r}")
    body = data[pos + 8:pos + psize]
    if len(body) < 16:
        raise ValueError("TTLP body too small")
    bitdepth, _pad, _reserved, data_size, color_offset = \
        struct.unpack_from("<HHIII", body, 0)
    color_bytes = body[color_offset:color_offset + data_size]
    n_colors = len(color_bytes) // 2
    colors = struct.unpack_from(f"<{n_colors}H", color_bytes, 0)
    return [bgr555_to_rgb8(c) for c in colors]


def load_palette(palette_narc, index):
    """Read and parse the RLCN palette at `index` in `palette_narc`. Returns
    a list of (r, g, b) tuples (16 for a 4bpp palette), or raises."""
    raw = palette_narc.read(index)
    return parse_nclr(raw)


def palette_index_for(species_index, shiny=False):
    """The default pairing rule for `PALETTE_ARCHIVE_PATH`: species/form
    index N -> sub-file N*PALETTE_STRIDE + (shiny ? SHINY : NORMAL) offset.
    See the module docstring section above for how this was recovered."""
    offset = PALETTE_SHINY_OFFSET if shiny else PALETTE_NORMAL_OFFSET
    return species_index * PALETTE_STRIDE + offset


def indices_to_rgb(pixels, palette):
    n = len(palette)
    return [palette[p] if p < n else (0, 0, 0) for p in pixels]


def decode_one(narc_obj, index, out_dir, trim, palette=None, out_name=None):
    raw = narc_obj.read(index)
    payload = decode_subfile_raw(raw)
    if trim:
        payload = payload[:trim_filler_rows(payload)]
    pixels, w, h = unpack_4bpp_tiles(payload)
    name = out_name if out_name is not None else f"{index:04d}"
    out_path = os.path.join(out_dir, f"{name}.png")
    if palette is not None:
        rgb = indices_to_rgb(pixels, palette)
        write_png_rgb8(out_path, w, h, rgb)
    else:
        gray = indices_to_gray(pixels)
        write_png_gray8(out_path, w, h, gray)
    return out_path, w, h, len(raw)


def decode_one_raw16(narc_obj, index, out_dir, out_name=None):
    """Decode one `a/1/3/4` sub-file as a 256x256 16bpp direct-color image
    (see unpack_16bpp_direct() above). Returns (out_path, w, h, rgb_pixels)."""
    raw = narc_obj.read(index)
    payload = decode_subfile_raw(raw)
    rgb, w, h = unpack_16bpp_direct(payload)
    name = out_name if out_name is not None else f"{index:04d}"
    out_path = os.path.join(out_dir, f"{name}.png")
    write_png_rgb8(out_path, w, h, rgb)
    return out_path, w, h, rgb


def downsample_nearest(rgb_pixels, w, h, out_w, out_h):
    """Nearest-neighbor downsample, stdlib only (no PIL)."""
    out = [None] * (out_w * out_h)
    for oy in range(out_h):
        sy = min(h - 1, oy * h // out_h)
        for ox in range(out_w):
            sx = min(w - 1, ox * w // out_w)
            out[oy * out_w + ox] = rgb_pixels[sy * w + sx]
    return out


def build_contact_sheets(narc_obj, out_dir, thumb_px=64, per_sheet=25, stride=1,
                          start=0, end=None):
    """Render every `stride`-th sub-file (default: all) as a `thumb_px`
    square thumbnail, tiled `per_sheet` (default 5x5) per sheet, into
    `out_dir/sheet_NN.png`. Each thumbnail cell is labelled implicitly by
    its position; the mapping (position -> archive index) is printed and
    also returned as a list, since PNG has no text layer here."""
    os.makedirs(out_dir, exist_ok=True)
    end = narc_obj.file_count if end is None else end
    indices = list(range(start, end, stride))
    cols = int(per_sheet ** 0.5)
    rows = (per_sheet + cols - 1) // cols
    sheet_w, sheet_h = cols * thumb_px, rows * thumb_px

    sheets = []
    for sheet_start in range(0, len(indices), per_sheet):
        chunk = indices[sheet_start:sheet_start + per_sheet]
        canvas = [(0, 0, 0)] * (sheet_w * sheet_h)
        for cell, idx in enumerate(chunk):
            cx, cy = (cell % cols) * thumb_px, (cell // cols) * thumb_px
            try:
                raw = narc_obj.read(idx)
                payload = decode_subfile_raw(raw)
                rgb, w, h = unpack_16bpp_direct(payload)
                thumb = downsample_nearest(rgb, w, h, thumb_px, thumb_px)
            except Exception:  # noqa: BLE001 -- leave the cell black on failure
                continue
            for ty in range(thumb_px):
                row_off = (cy + ty) * sheet_w + cx
                canvas[row_off:row_off + thumb_px] = thumb[ty * thumb_px:(ty + 1) * thumb_px]
        sheet_no = sheet_start // per_sheet
        out_path = os.path.join(out_dir, f"sheet_{sheet_no:02d}.png")
        write_png_rgb8(out_path, sheet_w, sheet_h, canvas)
        sheets.append((out_path, chunk))
    return sheets


def color_distribution(palette, pixels, top_n=5):
    """Return the `top_n` most common non-background colors among `pixels`
    (by palette index), as (rgb, fraction_of_nonzero_pixels). Indices 0 and
    8 are treated as background/filler and excluded -- the species-0 filler
    pattern (bytes 0x00, 0x80 repeating) unpacks to 4bpp nibbles 0,0,0,8, and
    docs/ASSETS.md's "Battle sprite archive" section found this same pair
    dominating the real (non-filler) sprite content too, i.e. the actual
    in-sprite background/transparent index is a mix of 0 and 8, not just 0."""
    from collections import Counter
    counts = Counter(p for p in pixels if p not in (0, 8))
    total = sum(counts.values())
    out = []
    for idx, cnt in counts.most_common(top_n):
        rgb = palette[idx] if idx < len(palette) else (0, 0, 0)
        out.append((rgb, cnt / total if total else 0.0))
    return out


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
    ap.add_argument("--palette-archive", default=None,
                     help="NARC to pull an RLCN/NCLR palette from for real-"
                          f"color output (default when used without "
                          f"--palette-index: {PALETTE_ARCHIVE_PATH})")
    ap.add_argument("--palette-index", type=int, default=None,
                     help="explicit sub-file index into --palette-archive "
                          "(single-sprite mode only; --all always derives "
                          "the index per-sprite via the species*stride rule)")
    ap.add_argument("--shiny", action="store_true",
                     help="use the shiny-slot palette offset instead of normal")
    ap.add_argument("--sanity", action="store_true",
                     help="with --all and a palette archive, print the "
                          "dominant-color breakdown for species 1/25/150 "
                          "instead of writing every PNG")
    ap.add_argument("--raw16", action="store_true",
                     help="decode as the 256x256 16bpp direct-color cinematic-"
                          "frame format instead of the (wrong-for-this-archive) "
                          "4bpp tiled layout -- see docs/ASSETS.md 'a/1/3/4 "
                          "hypothesis test -- NOT trainer battle art'")
    ap.add_argument("--contact-sheets", action="store_true",
                     help="render every sub-file (or every --stride-th one) "
                          "as a thumbnail contact sheet under --out, 16bpp "
                          "direct-color, ignores --index/--trim/--palette-*")
    ap.add_argument("--stride", type=int, default=1,
                     help="with --contact-sheets, sample every Nth sub-file")
    ap.add_argument("--thumb-px", type=int, default=64,
                     help="with --contact-sheets, thumbnail side length")
    ap.add_argument("--per-sheet", type=int, default=25,
                     help="with --contact-sheets, thumbnails per sheet")
    args = ap.parse_args(argv)

    if args.contact_sheets:
        os.makedirs(args.out, exist_ok=True)
        n = narc.parse_file(args.archive)
        sheets = build_contact_sheets(n, args.out, thumb_px=args.thumb_px,
                                       per_sheet=args.per_sheet, stride=args.stride)
        print(f"[*] wrote {len(sheets)} contact sheet(s) to {args.out}")
        for out_path, chunk in sheets:
            print(f"    {out_path}: indices {chunk}")
        return 0

    if not args.all and args.index is None:
        ap.error("give an index or pass --all")

    os.makedirs(args.out, exist_ok=True)
    n = narc.parse_file(args.archive)

    palette_narc = None
    if args.palette_archive is not None or args.palette_index is not None or args.sanity:
        palette_path = args.palette_archive or PALETTE_ARCHIVE_PATH
        palette_narc = narc.parse_file(palette_path)

    if args.sanity:
        for species, label in [(1, "bulbasaur"), (25, "pikachu"), (150, "mewtwo")]:
            raw = n.read(species)
            payload = decode_subfile_raw(raw)
            payload = payload[:trim_filler_rows(payload)]
            pixels, w, h = unpack_4bpp_tiles(payload)
            pidx = palette_index_for(species, shiny=args.shiny)
            palette = load_palette(palette_narc, pidx)
            dist = color_distribution(palette, pixels)
            print(f"[*] species {species} ({label}), palette index {pidx}:")
            for rgb, frac in dist:
                print(f"      {rgb}  {frac * 100:5.1f}%")
        return 0

    if args.all:
        ok = 0
        fail = 0
        for i in range(n.file_count):
            try:
                if args.raw16:
                    decode_one_raw16(n, i, args.out)
                else:
                    palette = None
                    if palette_narc is not None:
                        pidx = palette_index_for(i, shiny=args.shiny)
                        palette = load_palette(palette_narc, pidx)
                    decode_one(n, i, args.out, args.trim, palette=palette)
                ok += 1
            except Exception as exc:
                fail += 1
                print(f"[!] sub-file {i}: {exc}", file=sys.stderr)
        print(f"[*] decoded {ok}/{n.file_count} sub-files to {args.out} "
              f"({fail} failed)")
        return 0 if fail == 0 else 1

    if args.raw16:
        out_path, w, h, _rgb = decode_one_raw16(n, args.index, args.out)
        print(f"[*] sub-file {args.index}: {w}x{h} 16bpp direct-color PNG -> {out_path}")
        return 0

    palette = None
    if palette_narc is not None:
        pidx = args.palette_index
        if pidx is None:
            pidx = palette_index_for(args.index, shiny=args.shiny)
        palette = load_palette(palette_narc, pidx)

    out_path, w, h, raw_size = decode_one(n, args.index, args.out, args.trim,
                                           palette=palette)
    kind = "RGB" if palette is not None else "grayscale"
    print(f"[*] sub-file {args.index}: {raw_size} bytes compressed -> "
          f"{w}x{h} 4bpp {kind} PNG -> {out_path}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
