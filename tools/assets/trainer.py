#!/usr/bin/env python3
"""
trainer.py -- decoder for the `" APS12_1"`-wrapped sprite format, default
archive `a/0/0/6` (733 sub-files; previously guessed "trainer sprites" by
an earlier lane, now cracked at the byte level but reclassified -- see
docs/ASSETS.md "a/0/0/6 wrapper cracked" for the full writeup). The same
wrapper turns up in 10 more archives (41 more sub-files, pass `--archive`
to point at any of them) -- see docs/ASSETS.md "the other 41 `" APS12_1"`
wrappers found and decoded" for that pass's findings (a shared
particle/weather-effect icon format, not a second trainer-sprite home).

Written from scratch for the aletheia project. Stdlib only, single file.

--------------------------------------------------------------------------
Format (recovered by inspection of sub-files 0, 1, 100)
--------------------------------------------------------------------------
Outer wrapper, fixed 8-byte magic ``" APS12_1"`` (literal ASCII, not a
reversed NITRO-style tag) followed by a small header:

    0x00  char[8]  magic            " APS12_1"
    0x08  u16      field_a          unclear (1, 2, 1 on the three samples)
    0x0A  u16      frame_count      CONFIRMED: exact count of embedded
                                     " TPS" sub-chunks (1, 2, 8 on the three
                                     samples -- verified by literally
                                     counting " TPS" magic occurrences)
    0x0C  u32      reserved         always 0
    0x10  u32      size_a           "leading chunk" size, meaning unresolved
    0x14  u32      size_b           size of the run of " TPS" chunks (does
                                     NOT reliably equal TPS-scan sum; do not
                                     rely on it to bound the TPS scan)
    0x18  u32      size_c           size_b + size_c == file size, always
    0x1C  u32      reserved         always 0
    0x20  ...      unresolved       small table, not decoded (looked like
                                     OAM/position records: repeating groups
                                     of 4 u16 at some samples, not confirmed)

Body: `frame_count` " TPS" sub-chunks placed back-to-back (found by
scanning for the literal 4-byte tag ``b" TPS"``, NOT by trusting size_a/
size_b -- their relationship to the real TPS byte offsets was not fully
pinned down). Each " TPS" chunk:

    +0x00  char[4]  magic            " TPS"
    +0x04  u32      tag              constant 0x00010221 on every sample
    +0x08  u32      pixel_bytes      CONFIRMED constant 0x400 (1024) on
                                      every one of the 8 frames sampled --
                                      a format-level fixed canvas size, the
                                      same convention as the battle-sprite
                                      archive's fixed 0x20000 payload
                                      (see docs/ASSETS.md "battle sprite
                                      archive").
    +0x0C  u32      pixel_bytes+0x20 running total (not used by this reader)
    +0x10  u32      subtable_len     small, varies ~0x14-0x1c across
                                      samples; a short unresolved
                                      descriptor table follows the fixed
                                      36-byte header
    +0x14  u32      chunk_total      this chunk's approximate total size
                                      (header + subtable + pixel data);
                                      close to but not exactly equal to the
                                      real inter-chunk distance on the last
                                      frame in a sample (that frame's real
                                      extent runs to end of file, to include
                                      the trailing palette) -- not used by
                                      this reader, which finds chunk
                                      boundaries by re-scanning for the next
                                      " TPS" tag instead.
    +0x18  u32      reserved (0)
    +0x1C  u32      chunk_total (repeated)
    +0x20  u32      reserved (0)
    +0x24  ...      subtable_len bytes, unresolved
    ...    1024 bytes of pixel data (see below)

Pixel format (recovered by autocorrelation + visual confirmation): each
1024-byte frame is a **32x32, 8-bit-per-pixel canvas where only the HIGH
nibble of each byte carries a 4-bit palette index (0-15)**; the low nibble
only ever takes the value 0x0 or 0x8 in every sample checked, i.e. it is
a 1-bit flag (bit 3), not additional color resolution. This is NOT the
"2-pixels-per-byte packed 4bpp" layout used by the battle-sprite archive
(`a/1/3/4`) -- that interpretation was tried first and produces pure
vertical-stripe noise at every candidate width; the byte-granular "top
nibble = index" interpretation is what produces a clean, recognizable
32x32 shape (confirmed visually for all three samples: aps_0 is a
symmetric vertical spindle/glint shape, aps_1 is a 4-point sparkle plus
two ring/reticle shapes across its two frames, aps_100 is a single filled
circular blob repeated across all 8 frames -- consistent with an animated
particle/glint effect, NOT a full-body human trainer portrait). Autocorrelation
on an isolated single-frame payload peaks at stride 32 bytes (score 0.70,
next-highest non-harmonic candidate 0.63), confirming the 32-pixel row
width independent of the visual read.

**Reclassification**: given none of the three sampled entries show a
human silhouette, `a/0/0/6` is likely NOT the trainer full-body sprite
archive despite its file count (733) being close to Black/White's trainer
class count -- it is more consistent with a small animated icon/particle/
effect-sprite archive (733 could just as easily be one entry per some
other per-trainer-or-per-move resource). Not re-searched against other
NARCs in this pass; flagged as an open question in docs/ASSETS.md.

Palette: the **last 32 bytes of the whole sub-file** are a raw 16-entry
BGR555 palette (index 0 conventionally unused/black), shared by every
frame in that sub-file. Confirmed on all three samples: aps_0 and aps_1
both carry a nearly-empty palette (all zero except index 14 = white
0x7FFF -- a plausible "glint" palette), aps_100 carries a full 14-color
palette from index 2 onward. All 16 entries have bit 15 clear (valid
BGR555) in every sample, which would not hold for random bytes.

--------------------------------------------------------------------------
Usage
--------------------------------------------------------------------------
    python tools/assets/trainer.py 0                  # decode sub-file 0
    python tools/assets/trainer.py 1
    python tools/assets/trainer.py 100
    python tools/assets/trainer.py --all               # all 733 (best-effort)
"""

import argparse
import os
import struct
import sys
import zlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402

ARCHIVE_PATH = os.path.join("extract", "data", "a", "0", "0", "6")
OUT_DIR = os.path.join("build", "assets", "trainers")

TPS_MAGIC = b" TPS"
TPS_FIXED_HEADER_LEN = 0x24  # magic + 8 u32 fields
FRAME_PIXEL_BYTES = 0x400    # 1024, legacy default only used as a fallback
FRAME_WIDTH = 32             # legacy default row width (non-square pb)
FRAME_HEIGHT = FRAME_PIXEL_BYTES // FRAME_WIDTH  # 32
PALETTE_BYTES = 32           # 16 BGR555 colors


def guess_canvas_width(pixel_bytes):
    """Infer a per-chunk canvas row width from the declared `pixel_bytes`
    (`pb`) field at TPS+0x08.

    41 " APS12_1" sub-files outside `a/0/0/6` (found by re-running
    `inner_magic_census.py` and filtering for the " APS" inner magic
    across every archive, not just `a/0/0/6`) declare `pb` values other
    than the 0x400 this module originally hard-coded: 0x40, 0x100, 0x200,
    0x1000, and 0x10000 all occur (see docs/ASSETS.md "the other 41 APS
    wrappers"). Where `pb` is a perfect square, treat the chunk as a
    square canvas of that side length -- 0x1000 (4096) = 64x64, 0x10000
    (65536) = 256x256, 0x400 (1024) = 32x32, 0x100 (256) = 16x16, 0x40
    (64) = 8x8 -- matching the mission's own worked examples (0x1000 =
    64x64, 0x1900 = 80x80, 0x2400 = 96x96). Non-square `pb` (only 0x200 =
    512 seen) falls back to the legacy fixed 32-pixel row width, since no
    sampled sub-file's small per-chunk sub-table carries an explicit
    width/height (every subtable byte checked across all 41 files is 0x00
    or a repeated 0x08/0x20/0x50 filler, never a plausible dimension
    pair -- see docs/ASSETS.md for the byte dumps checked)."""
    root = int(pixel_bytes ** 0.5)
    for cand in (root - 1, root, root + 1):
        if cand > 0 and cand * cand == pixel_bytes:
            return cand
    return FRAME_WIDTH


class TrainerWrapperError(Exception):
    pass


def bgr555_to_rgb8(c):
    r = c & 0x1F
    g = (c >> 5) & 0x1F
    b = (c >> 10) & 0x1F
    return (r * 255 // 31, g * 255 // 31, b * 255 // 31)


def parse_palette(data):
    """Last 32 bytes of the sub-file: 16 raw BGR555 colors."""
    if len(data) < PALETTE_BYTES:
        raise TrainerWrapperError("sub-file too small to hold a trailing palette")
    tail = data[-PALETTE_BYTES:]
    colors = struct.unpack_from("<16H", tail, 0)
    return [bgr555_to_rgb8(c) for c in colors]


def find_tps_offsets(data):
    """Scan the whole sub-file for `" TPS"` tag occurrences, in order."""
    offs = []
    start = 8  # skip the outer " APS12_1" magic itself, which is 8 bytes
    while True:
        idx = data.find(TPS_MAGIC, start)
        if idx < 0:
            break
        offs.append(idx)
        start = idx + 4
    return offs


def parse_wrapper(data):
    """Parse the outer " APS12_1" header. Returns a dict of raw fields."""
    if len(data) < 0x20 or data[0:8] != b" APS12_1":
        raise TrainerWrapperError(f"bad outer magic {data[0:8]!r}")
    field_a, frame_count = struct.unpack_from("<HH", data, 0x08)
    size_a, size_b, size_c = struct.unpack_from("<III", data, 0x10)
    return {
        "field_a": field_a,
        "frame_count": frame_count,
        "size_a": size_a,
        "size_b": size_b,
        "size_c": size_c,
    }


def decode_frames(data):
    """Return a list of (width, height, pixel_indices) tuples, one per
    " TPS" sub-chunk found in `data`, plus the recovered 16-color palette.
    `pixel_indices` is a flat row-major bytearray of 4-bit palette indices
    (0-15), taken from the HIGH nibble of each pixel byte -- see the
    module docstring for why the low nibble is not used.

    Canvas size per chunk is generalised (see `guess_canvas_width()`): the
    declared `pb` field at TPS+0x08 gives the row width when `pb` is a
    perfect square, else the legacy fixed 32-pixel width is used. The
    pixel region itself is clipped to whatever room is actually available
    before the next " TPS" tag (or before the trailing 32-byte palette,
    for a sub-file's last chunk) -- the same clipped-length rule
    `parse_full()` uses for the re-encoder -- and any final partial row is
    dropped, exactly as before.
    """
    hdr = parse_wrapper(data)
    tps_offsets = find_tps_offsets(data)
    if not tps_offsets:
        raise TrainerWrapperError("no \" TPS\" sub-chunk found")
    palette = parse_palette(data)

    frames = []
    for k, off in enumerate(tps_offsets):
        if off + TPS_FIXED_HEADER_LEN + 4 > len(data):
            raise TrainerWrapperError(f"TPS chunk at 0x{off:X} header runs past EOF")
        pb, = struct.unpack_from("<I", data, off + 0x08)
        subtable_len, = struct.unpack_from("<I", data, off + 0x10)
        pix_start = off + TPS_FIXED_HEADER_LEN + subtable_len
        next_b = tps_offsets[k + 1] if k + 1 < len(tps_offsets) else len(data) - PALETTE_BYTES
        pixel_len = max(0, min(pb, next_b - pix_start))
        pixel_bytes = data[pix_start:pix_start + pixel_len]
        width = guess_canvas_width(pb)
        usable_rows = len(pixel_bytes) // width
        pixel_bytes = pixel_bytes[:usable_rows * width]
        if not pixel_bytes:
            raise TrainerWrapperError(f"TPS chunk at 0x{off:X}: no pixel data available")
        indices = bytearray(len(pixel_bytes))
        for i, b in enumerate(pixel_bytes):
            indices[i] = (b >> 4) & 0x0F
        frames.append((width, usable_rows, indices))

    if len(frames) != hdr["frame_count"]:
        # Not fatal -- report but keep going; frame_count is a useful cross
        # check, not a hard requirement for decoding.
        pass
    return hdr, palette, frames


# ---------------------------------------------------------------------------
# Minimal stdlib PNG writer (24-bit RGB), same shape as battle_sprite.py's
# ---------------------------------------------------------------------------

def write_png_rgb8(path, width, height, rgb_pixels):
    def chunk(tag, data):
        out = struct.pack(">I", len(data)) + tag + data
        crc = zlib.crc32(tag)
        crc = zlib.crc32(data, crc) & 0xFFFFFFFF
        out += struct.pack(">I", crc)
        return out

    sig = b"\x89PNG\r\n\x1a\n"
    ihdr = struct.pack(">IIBBBBB", width, height, 8, 2, 0, 0, 0)
    raw = bytearray()
    for y in range(height):
        raw.append(0)
        row = rgb_pixels[y * width:(y + 1) * width]
        for r, g, b in row:
            raw.extend((r, g, b))
    idat = zlib.compress(bytes(raw), 9)
    with open(path, "wb") as fh:
        fh.write(sig)
        fh.write(chunk(b"IHDR", ihdr))
        fh.write(chunk(b"IDAT", idat))
        fh.write(chunk(b"IEND", b""))


def indices_to_rgb(indices, palette):
    return [palette[p] if p < len(palette) else (255, 0, 255) for p in indices]


# ---------------------------------------------------------------------------
# Re-encoder (byte-identical round trip)
# ---------------------------------------------------------------------------
#
# `decode_frames()` above (used for the PNG dump) hard-codes a 32x32/1024-
# byte canvas and reads only the HIGH nibble of each pixel byte, on the
# strength of 3 samples (indices 0, 1, 100). Building the re-encoder and
# checking it against all 733 sub-files falsified both simplifications:
#
# 1. The per-" TPS"-chunk `pixel_bytes` field at +0x08 (called `pb` below)
#    is NOT a constant 0x400 -- sub-files 0 and 1 declare 0x1000 (4096).
#    The true per-chunk pixel region size is `pb`, clipped to whatever
#    room is actually available before the next " TPS" tag (or before the
#    trailing 32-byte palette, for the last chunk in a sub-file) -- this
#    clipped-length rule reproduces the exact original byte layout for
#    all 733 sub-files (see `verify_all_reencode()`).
# 2. The low nibble of each pixel byte is NOT a 1-bit flag restricted to
#    {0x0, 0x8}: scanning all 733 sub-files, 686 of them (94%) contain
#    pixel bytes whose low nibble takes a value outside {0, 8} (9.3% of
#    all 8,572,352 sampled pixel bytes). The {0,8}-only pattern held for
#    the 3 originally-sampled files because they happen to be
#    near-empty/single-color "glint" sprites; it does not generalise.
#    The true meaning of the low nibble (and of the byte as a whole -- is
#    it one 8-bit index, or "4-bit index + 4-bit something-else"?) is
#    still unresolved. This re-encoder does not guess: it treats each
#    pixel as one opaque byte (0-255) and reconstructs it verbatim, which
#    is both honest about the gap and sufficient for byte-identical round
#    tripping.
#
# Every other field this reader touches (outer header ints, per-chunk
# header ints, palette colors) round-trips through actual decoded values
# (struct.pack of the same ints / re-packed BGR555 words), not a raw byte
# copy -- only the two genuinely opaque regions (the leading "table" at
# +0x20 before the first " TPS", and each chunk's subtable_len-byte
# descriptor table) are carried through as opaque byte ranges, the same
# "decode what's understood, preserve the rest verbatim" approach already
# used by sbnk.py/nsbmd.py in this project.


class ApsReencodeError(Exception):
    pass


def parse_full(data):
    """Parse every byte of `data` into a structure `reencode_full()` can
    losslessly rebuild. Raises ApsReencodeError on any layout this parser
    doesn't recognise (rather than silently dropping bytes)."""
    if len(data) < 0x20 or data[0:8] != b" APS12_1":
        raise ApsReencodeError(f"bad outer magic {data[0:8]!r}")
    field_a, frame_count = struct.unpack_from("<HH", data, 0x08)
    reserved0c, = struct.unpack_from("<I", data, 0x0C)
    size_a, size_b, size_c = struct.unpack_from("<III", data, 0x10)
    reserved1c, = struct.unpack_from("<I", data, 0x1C)

    offs = find_tps_offsets(data)
    if not offs:
        raise ApsReencodeError("no \" TPS\" sub-chunk found")
    if offs[0] < 0x20:
        raise ApsReencodeError(f"first \" TPS\" at 0x{offs[0]:X}, before the "
                                f"0x20-byte outer header ends")
    pretps_raw = data[0x20:offs[0]]

    chunks = []
    for k, off in enumerate(offs):
        if off + 0x24 + 4 > len(data):
            raise ApsReencodeError(f"TPS chunk at 0x{off:X} header runs past EOF")
        tag, pb, rt, subtable_len, chunk_total, res18, chunk_total2, res20 = \
            struct.unpack_from("<8I", data, off + 4)
        subtable_off = off + TPS_FIXED_HEADER_LEN
        subtable_raw = data[subtable_off:subtable_off + subtable_len]
        pix_start = subtable_off + subtable_len
        next_b = offs[k + 1] if k + 1 < len(offs) else len(data) - PALETTE_BYTES
        pixel_len = max(0, min(pb, next_b - pix_start))
        pixel_bytes = data[pix_start:pix_start + pixel_len]
        gap_raw = data[pix_start + pixel_len:next_b]
        chunks.append({
            "tag": tag, "pb": pb, "rt": rt, "chunk_total": chunk_total,
            "res18": res18, "chunk_total2": chunk_total2, "res20": res20,
            "subtable_raw": subtable_raw, "pixel_bytes": pixel_bytes,
            "gap_raw": gap_raw,
        })

    if len(data) < PALETTE_BYTES:
        raise ApsReencodeError("sub-file too small to hold a trailing palette")
    palette_words = struct.unpack_from("<16H", data, len(data) - PALETTE_BYTES)
    # Full lossless decomposition of each BGR555(+unused bit15) word.
    palette = [(w & 0x1F, (w >> 5) & 0x1F, (w >> 10) & 0x1F, (w >> 15) & 0x1)
               for w in palette_words]

    return {
        "field_a": field_a, "frame_count": frame_count,
        "reserved0c": reserved0c, "size_a": size_a, "size_b": size_b,
        "size_c": size_c, "reserved1c": reserved1c,
        "pretps_raw": pretps_raw, "chunks": chunks, "palette": palette,
    }


def reencode_full(parsed):
    """Inverse of parse_full(): rebuild the exact sub-file bytes from the
    decoded structure."""
    out = bytearray()
    out += b" APS12_1"
    out += struct.pack("<HH", parsed["field_a"], parsed["frame_count"])
    out += struct.pack("<I", parsed["reserved0c"])
    out += struct.pack("<III", parsed["size_a"], parsed["size_b"], parsed["size_c"])
    out += struct.pack("<I", parsed["reserved1c"])
    out += parsed["pretps_raw"]
    for c in parsed["chunks"]:
        out += b" TPS"
        out += struct.pack("<8I", c["tag"], c["pb"], c["rt"],
                            len(c["subtable_raw"]), c["chunk_total"],
                            c["res18"], c["chunk_total2"], c["res20"])
        out += c["subtable_raw"]
        out += bytes(c["pixel_bytes"])
        out += c["gap_raw"]
    for r5, g5, b5, a1 in parsed["palette"]:
        word = (r5 & 0x1F) | ((g5 & 0x1F) << 5) | ((b5 & 0x1F) << 10) | ((a1 & 1) << 15)
        out += struct.pack("<H", word)
    return bytes(out)


def verify_all_reencode(archive_path=ARCHIVE_PATH):
    """Round-trip every sub-file in the archive through parse_full() +
    reencode_full(). Returns (ok, total, failures) where failures is a
    list of (index, reason) for the first few mismatches."""
    n = narc.parse_file(archive_path)
    ok = 0
    failures = []
    for i in range(n.file_count):
        raw = n.read(i)
        try:
            parsed = parse_full(raw)
            rebuilt = reencode_full(parsed)
        except Exception as exc:  # noqa: BLE001
            failures.append((i, f"error: {exc}"))
            continue
        if rebuilt == raw:
            ok += 1
        else:
            failures.append((i, f"mismatch: out={len(rebuilt)} in={len(raw)}"))
    return ok, n.file_count, failures


def archive_tag(archive_path):
    """`a/1/8/2`-style archive path -> `a_1_8_2` filename tag."""
    return os.path.normpath(archive_path).replace("extract" + os.sep + "data" + os.sep, "") \
        .replace(os.sep, "_").replace("/", "_")


def decode_one(narc_obj, index, out_dir, tag=None):
    raw = narc_obj.read(index)
    hdr, palette, frames = decode_frames(raw)
    paths = []
    prefix = f"{tag}_" if tag else ""
    for fi, (w, h, indices) in enumerate(frames):
        rgb = indices_to_rgb(indices, palette)
        out_path = os.path.join(out_dir, f"{prefix}{index:04d}_f{fi}.png")
        write_png_rgb8(out_path, w, h, rgb)
        paths.append(out_path)
    return hdr, palette, paths


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("index", type=int, nargs="?",
                     help="sub-file index to decode (omit with --all)")
    ap.add_argument("--all", action="store_true",
                     help="decode every sub-file in the archive (best-effort)")
    ap.add_argument("--verify-reencode", action="store_true",
                     help="round-trip every sub-file through the re-encoder "
                          "and report byte-identity counts")
    ap.add_argument("--archive", default=ARCHIVE_PATH,
                     help=f"NARC path (default: {ARCHIVE_PATH})")
    ap.add_argument("--out", default=OUT_DIR,
                     help=f"output directory (default: {OUT_DIR})")
    args = ap.parse_args(argv)

    if args.verify_reencode:
        ok, total, failures = verify_all_reencode(args.archive)
        print(f"[*] re-encode round trip: {ok}/{total} sub-files byte-identical")
        for idx, reason in failures[:20]:
            print(f"  ! sub-file {idx}: {reason}")
        if len(failures) > 20:
            print(f"  ... and {len(failures) - 20} more")
        return 0 if not failures else 1

    if not args.all and args.index is None:
        ap.error("give an index or pass --all")

    os.makedirs(args.out, exist_ok=True)
    n = narc.parse_file(args.archive)
    tag = archive_tag(args.archive) if os.path.normpath(args.archive) != os.path.normpath(ARCHIVE_PATH) else None

    if args.all:
        ok = 0
        fail = 0
        for i in range(n.file_count):
            try:
                decode_one(n, i, args.out, tag=tag)
                ok += 1
            except Exception as exc:
                fail += 1
                print(f"[!] sub-file {i}: {exc}", file=sys.stderr)
        print(f"[*] decoded {ok}/{n.file_count} sub-files to {args.out} ({fail} failed)")
        return 0 if fail == 0 else 1

    hdr, palette, paths = decode_one(n, args.index, args.out, tag=tag)
    print(f"[*] sub-file {args.index}: field_a={hdr['field_a']} "
          f"frame_count={hdr['frame_count']} "
          f"size_a=0x{hdr['size_a']:X} size_b=0x{hdr['size_b']:X} "
          f"size_c=0x{hdr['size_c']:X}")
    print(f"    palette: {palette}")
    for p in paths:
        print(f"    wrote {p}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
