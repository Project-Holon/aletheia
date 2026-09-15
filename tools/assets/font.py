#!/usr/bin/env python3
"""
font.py -- NFTR (on-disk magic "RTFN") font decoder for the aletheia asset
lane.

Written from scratch for the aletheia project. Stdlib only, single file.
Depends only on narc.py (same directory) for NARC sub-file access.

--------------------------------------------------------------------------
The archive: `a/0/2/3`
--------------------------------------------------------------------------
8 sub-files: 5 RTFN (NFTR) fonts at indices 0-4, then 3 RLCN (NCLR)
palettes at indices 5-7 (16 colors each, uncompressed). The palettes are
NOT used by the glyph decoder below -- see "What remains" -- they are
recorded here only because they live in the same archive.

    #0  264360 bytes  12x15, 5064 glyphs  (main/large font)
    #1  162768 bytes  10x10, 5064 glyphs  (small font)
    #2  218520 bytes  11x13, 5064 glyphs  (medium font)
    #3    1684 bytes  13x8,    32 glyphs  (digits + a few letters + gender
                                           marks + fullwidth digits -- a
                                           special-purpose stat/level font)
    #4    2396 bytes  12x12,   41 glyphs  (digits 1-9, A-Z, circled digits
                                           -- a special-purpose ranking/
                                           ordinal font)

--------------------------------------------------------------------------
Container format (confirmed against real bytes, every field below was
cross-checked against at least 2 of the 5 fonts, usually all 5)
--------------------------------------------------------------------------
NFTR is the same generic NITRO chunked-container shape as NARC/NCGR/NCLR
(see narc.py's docstring): a 16-byte file header (magic "RTFN" on disk =
"NFTR" read forward, BOM 0xFFFE, version, file_size, header_size=0x10,
section_count), then a fixed sequence of named chunks, each chunk(4) +
size(4) + body.

Chunk order on disk: FNIF ("FINF"), PLGC ("CGLP"), HDWC ("CWDH"), then one
or more PAMC ("CMAP") chunks.

FINF body (20 bytes), fields confirmed by their own cross-reference (the
three u32s at +8/+12/+16 are byte offsets, relative to the start of this
NFTR sub-file, of the CGLP/CWDH/first-CMAP chunk BODY -- i.e. 8 bytes past
that chunk's own magic+size -- and every one of them lands exactly on a
real chunk body start found by walking the chunks sequentially, for all
5 fonts):
    0x00  u8   unknown, 0 in every font sampled
    0x01  u8   font pixel height (line feed), varies per font (15/10/13/8/12)
    0x02  u8x3 unknown, 0 in every font sampled
    0x05  u8   unknown, varies (13/11/11/14/13) -- not needed below
    0x06  u8   unknown, equals the byte at 0x05 in 4 of 5 fonts
    0x07  u8   1 in every font sampled (encoding flag, guess)
    0x08  u32  CGLP body offset
    0x0C  u32  CWDH body offset
    0x10  u32  first CMAP body offset

CGLP body header (8 bytes), then glyph_count * cell_size bytes of glyph
records back-to-back, glyph_count computed as (chunk body bytes after this
8-byte header) / cell_size, confirmed to be an exact integer for all 5
fonts with no remainder:
    0x00  u8   cell width, pixels
    0x01  u8   cell height, pixels
    0x02  u16  cell_size -- bytes per glyph record, metrics + bitmap
    0x04  u8   unknown, varies per font
    0x05  u8   unknown, varies per font
    0x06  u16  bits per pixel -- literal value 2 in every font sampled,
                NOT an enum code (confirmed below, it is the actual bpp)

One glyph record = 3 metric bytes + a packed bitmap:
    byte 0  s8  left bearing (x offset before drawing)
    byte 1  u8  drawn glyph width, pixels
    byte 2  u8  total advance width, pixels
    then ceil(cell_width * cell_height * bpp / 8) bytes of bitmap,
    cell_width * cell_height pixels, bpp bits each, packed MSB-first with
    NO per-row byte alignment (the bit stream runs continuously across
    row boundaries) -- confirmed because cell_size - 3 exactly equals
    ceil(w*h*bpp/8) for bpp=2 and fails for every other bpp (1/4/8) tried,
    for all 5 fonts: e.g. font #0, 12x15 = 180 px * 2 bit = 360 bit =
    45 bytes + 3 metric bytes = 48 = the real cell_size.

This 3-byte-metrics-then-bitmap shape is not a guess: it is exactly what
`src/matched/sub_0201DC44.c` (gf_font.c's glyph hand-off, status EXACT)
says -- "the glyph bitmap ... starts three bytes into the glyph record,
and the record's own three metric bytes ... are copied into the caller's
... descriptor" -- and the MSB-first, straddling-aware bit reader it feeds
is `src/matched/sub_0201E4D4.c` (also EXACT), which this module's decoder
reproduces byte-for-byte (see ``_unpack_bits``/``_pack_bits`` below).

The bpp=2 (4 brightness levels) reading also matches
`docs/notes` commentary on `func_0201DD78` ("the 4x4x4x4 colour
expansion"): the renderer builds a 4-level tint ramp from an RGB request
at draw time rather than reading color out of a palette, which is why the
3 NCLR palettes in this archive (16 colors each) don't correspond to the
glyph bit depth -- they are not the font's pixel colors.

CWDH ("HDWC") is located (its body offset is in FINF, its own chunk
header gives a byte count) but its internal record layout is NOT cracked
this pass -- tried 1-, 2- and 4-byte fixed records at several header
lengths, none gives a glyph_count that lines up with anything confirmable
against the real per-glyph metrics already recovered from CGLP itself (see
"What remains" in docs/ASSETS.md). This module does not need it: every
render/verify/widths operation here uses CGLP's own embedded 3-byte
metrics, which is what `sub_0201DC44.c` shows the real renderer uses for
layout too.

--------------------------------------------------------------------------
CMAP: character code -> glyph index (confirmed directly against text.py)
--------------------------------------------------------------------------
CMAP is a linked list of chunks (each chunk's body holds a "next chunk body
offset" u32, 0 = end of chain), each covering one of three shapes:
    method 0  "direct range": firstChar..lastChar map to consecutive glyph
               indices starting at one stored value
    method 1  "table": firstChar..lastChar map 1:1 to a stored array of u16
               glyph indices (0xFFFF = no glyph)
    method 2  "scan": a stored count, then that many (charCode, glyphIndex)
               u16 pairs, unsorted

Font #0's first CMAP chunk is method 0, first=0x20, last=0x7E, base glyph
index 0 -- i.e. **glyph index N (0..94) is character code 0x20+N**, for
every printable ASCII character. That is exactly the identity text.py
uses for ASCII code points (text.py: "Printable ASCII (0x20-0x7E) renders
as itself"), which is this module's ground-truth check -- see "Ground
truth check" below and the --render output.

--------------------------------------------------------------------------
Ground truth check performed by this module
--------------------------------------------------------------------------
Rendered glyph indices 0-94 of font #0 (the ASCII direct-range CMAP chunk)
to a terminal ASCII-art dump by hand during development and compared
every digit 0-9 (glyph index 16-25) and every capital A-Z (glyph index
33-58) against its expected shape: all 36 matched by eye (digits read as
digits, capitals read as their letters, including distinguishing marks
like the crossbar on 'A' and the two bumps on 'B'). 36/36, no mismatches.
`--render` reproduces this as a PNG contact sheet.

--------------------------------------------------------------------------
What remains
--------------------------------------------------------------------------
  * CWDH's internal record layout is not cracked (see above) -- not
    needed for anything implemented here, but it means there may be a
    second, possibly more precise, width source this module doesn't use.
  * The non-ASCII CMAP chunks (kana, fullwidth forms, a 4530-entry scan
    chunk covering the rest of Unicode) are walked and reported by
    --list, but --render only renders by raw glyph index, not by
    character code, so non-ASCII text is not exercised here.
  * The 3 NCLR palettes are parsed by no code in this module; their
    purpose in this archive is undetermined (see the bpp note above).
  * FINF bytes 0x01/0x05/0x06/0x07 are recorded but not fully explained
    (0x01 behaves like a line height; 0x05/0x06/0x07 are unknown).
"""

import argparse
import os
import struct
import sys
import zlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402

ARCHIVE_PATH = os.path.join("extract", "data", "a", "0", "2", "3")
OUT_DIR = os.path.join("build", "assets", "fonts")


class FontError(Exception):
    pass


# ---------------------------------------------------------------------------
# Bit packing -- MSB-first, straddles byte boundaries, no row alignment.
# Mirrors src/matched/sub_0201E4D4.c (read) byte for byte in behaviour.
# ---------------------------------------------------------------------------

def _unpack_bits(data, count, bpp):
    """Read `count` values of `bpp` bits each, MSB-first, from `data`."""
    out = []
    bitpos = 0
    total_bits = len(data) * 8
    for _ in range(count):
        val = 0
        for _b in range(bpp):
            if bitpos >= total_bits:
                val <<= 1
                bitpos += 1
                continue
            byte_i = bitpos // 8
            bit_off = bitpos % 8
            bit = (data[byte_i] >> (7 - bit_off)) & 1
            val = (val << 1) | bit
            bitpos += 1
        out.append(val)
    return out


def _pack_bits(values, bpp):
    """Inverse of ``_unpack_bits``: pack `values` (each < 2**bpp) MSB-first
    into bytes, padding the final byte with zero bits."""
    nbits = len(values) * bpp
    nbytes = (nbits + 7) // 8
    out = bytearray(nbytes)
    bitpos = 0
    for val in values:
        for b in range(bpp - 1, -1, -1):
            bit = (val >> b) & 1
            byte_i = bitpos // 8
            bit_off = bitpos % 8
            if bit:
                out[byte_i] |= (1 << (7 - bit_off))
            bitpos += 1
    return bytes(out)


# ---------------------------------------------------------------------------
# NFTR parsing
# ---------------------------------------------------------------------------

class CmapChunk:
    __slots__ = ("first", "last", "method", "next_off", "table", "pairs",
                 "base_index")

    def __init__(self):
        self.first = 0
        self.last = 0
        self.method = 0
        self.next_off = 0
        self.table = None   # method 1: list of glyph indices
        self.pairs = None   # method 2: list of (char, glyph_index)
        self.base_index = 0  # method 0: first glyph index of the range

    def lookup(self, code):
        if not (self.first <= code <= self.last) and self.method != 2:
            return None
        if self.method == 0:
            return self.base_index + (code - self.first)
        if self.method == 1:
            idx = self.table[code - self.first]
            return None if idx == 0xFFFF else idx
        if self.method == 2:
            for c, g in self.pairs:
                if c == code:
                    return g
            return None
        return None

    def describe(self):
        return f"0x{self.first:04X}-0x{self.last:04X} method={self.method}"


class Font:
    """One parsed RTFN (NFTR) sub-file."""

    def __init__(self, data, index):
        self.raw = data
        self.index = index
        self._parse(data)

    def _parse(self, data):
        if len(data) < 16 or data[:4] != b"RTFN":
            raise FontError("not an RTFN (NFTR) sub-file")
        _magic, _bom, _ver, _fsize, header_size, _seccount = \
            struct.unpack_from("<4sHHIHH", data, 0)

        finf_hdr = header_size
        finf_magic, finf_size = struct.unpack_from("<4sI", data, finf_hdr)
        if finf_magic != b"FNIF":
            raise FontError(f"expected FNIF chunk, found {finf_magic!r}")
        finf_body = data[finf_hdr + 8:finf_hdr + finf_size]
        self.line_height = finf_body[1]
        cglp_off, cwdh_off, cmap_off = struct.unpack_from("<III", finf_body, 8)
        self.cglp_off = cglp_off
        self.cwdh_off = cwdh_off

        # --- CGLP ---
        cglp_hdr = cglp_off - 8
        cglp_magic, cglp_size = struct.unpack_from("<4sI", data, cglp_hdr)
        if cglp_magic != b"PLGC":
            raise FontError(f"expected PLGC (CGLP) chunk, found {cglp_magic!r}")
        self.width, self.height = struct.unpack_from("<BB", data, cglp_off)
        self.cell_size = struct.unpack_from("<H", data, cglp_off + 2)[0]
        self.bpp = struct.unpack_from("<H", data, cglp_off + 6)[0]
        self.glyph_data_off = cglp_off + 8
        glyph_data_len = (cglp_off + cglp_size - 8) - self.glyph_data_off
        if self.cell_size == 0 or glyph_data_len % self.cell_size != 0:
            raise FontError("CGLP glyph data is not an exact multiple of cell_size")
        self.glyph_count = glyph_data_len // self.cell_size
        expect_bitmap_bytes = (self.width * self.height * self.bpp + 7) // 8
        self.bitmap_bytes = self.cell_size - 3
        if self.bitmap_bytes != expect_bitmap_bytes:
            raise FontError(
                f"cell_size {self.cell_size} doesn't match {self.width}x"
                f"{self.height} at {self.bpp}bpp (expected "
                f"{expect_bitmap_bytes + 3} bytes/glyph)")

        # --- CWDH: located, not decoded (see module docstring) ---
        cwdh_hdr = cwdh_off - 8
        cwdh_magic, cwdh_size = struct.unpack_from("<4sI", data, cwdh_hdr)
        if cwdh_magic != b"HDWC":
            raise FontError(f"expected HDWC (CWDH) chunk, found {cwdh_magic!r}")
        self.cwdh_body_len = cwdh_size - 8

        # --- CMAP chain ---
        self.cmap_chunks = []
        off = cmap_off
        seen = set()
        while off and off not in seen and off - 8 + 8 <= len(data):
            seen.add(off)
            hdr = off - 8
            cmagic, csize = struct.unpack_from("<4sI", data, hdr)
            if cmagic != b"PAMC":
                break
            body = data[off:off + csize - 8]
            chunk = CmapChunk()
            chunk.first, chunk.last, chunk.method, _pad = \
                struct.unpack_from("<HHHH", body, 0)
            chunk.next_off = struct.unpack_from("<I", body, 8)[0]
            payload = body[12:]
            if chunk.method == 0:
                chunk.base_index = struct.unpack_from("<H", payload, 0)[0]
            elif chunk.method == 1:
                n = chunk.last - chunk.first + 1
                chunk.table = list(struct.unpack_from(f"<{n}H", payload, 0))
            elif chunk.method == 2:
                cnt = struct.unpack_from("<H", payload, 0)[0]
                flat = struct.unpack_from(f"<{cnt * 2}H", payload, 2)
                chunk.pairs = list(zip(flat[0::2], flat[1::2]))
            self.cmap_chunks.append(chunk)
            off = chunk.next_off

    # -- glyph access --

    def _glyph_slice(self, index):
        if not (0 <= index < self.glyph_count):
            raise FontError(f"glyph index {index} out of range 0..{self.glyph_count - 1}")
        start = self.glyph_data_off + index * self.cell_size
        return start, self.raw[start:start + self.cell_size]

    def glyph_metrics(self, index):
        """Return (bearing, width, advance) for glyph `index`."""
        _start, rec = self._glyph_slice(index)
        bearing = rec[0] - 256 if rec[0] >= 128 else rec[0]
        return bearing, rec[1], rec[2]

    def glyph_pixels(self, index):
        """Return a flat row-major list of `width*height` pixel values
        (0..2**bpp - 1) for glyph `index`."""
        _start, rec = self._glyph_slice(index)
        bitmap = rec[3:3 + self.bitmap_bytes]
        return _unpack_bits(bitmap, self.width * self.height, self.bpp)

    def glyph_record_bytes(self, index):
        """Re-encode glyph `index` (metrics + bitmap) and return the bytes
        that should be byte-identical to the original record, for --verify."""
        bearing, width, advance = self.glyph_metrics(index)
        pixels = self.glyph_pixels(index)
        bitmap = _pack_bits(pixels, self.bpp)
        meta = bytes([bearing & 0xFF, width & 0xFF, advance & 0xFF])
        return meta + bitmap

    def code_to_index(self, code):
        for chunk in self.cmap_chunks:
            idx = chunk.lookup(code)
            if idx is not None:
                return idx
        return None


def load_fonts(archive_path):
    """Return (Narc, {sub_index: Font}) for every RTFN sub-file, and a list
    of NCLR sub-file indices found alongside them."""
    n = narc.parse_file(archive_path)
    fonts = {}
    palettes = []
    for sub in n.subfiles:
        if sub.magic == b"RTFN":
            fonts[sub.index] = Font(n.read(sub.index), sub.index)
        elif sub.magic == b"RLCN":
            palettes.append(sub.index)
    return n, fonts, palettes


# ---------------------------------------------------------------------------
# PNG writer -- 8-bit grayscale, stdlib zlib only.
# ---------------------------------------------------------------------------

def write_png_gray8(path, width, height, gray_bytes):
    def chunk(tag, data):
        out = struct.pack(">I", len(data)) + tag + data
        crc = zlib.crc32(tag)
        crc = zlib.crc32(data, crc) & 0xFFFFFFFF
        out += struct.pack(">I", crc)
        return out

    sig = b"\x89PNG\r\n\x1a\n"
    ihdr = struct.pack(">IIBBBBB", width, height, 8, 0, 0, 0, 0)
    raw = bytearray()
    for y in range(height):
        raw.append(0)
        raw.extend(gray_bytes[y * width:(y + 1) * width])
    idat = zlib.compress(bytes(raw), 9)
    parent = os.path.dirname(os.path.abspath(path))
    if parent:
        os.makedirs(parent, exist_ok=True)
    with open(path, "wb") as fh:
        fh.write(sig)
        fh.write(chunk(b"IHDR", ihdr))
        fh.write(chunk(b"IDAT", idat))
        fh.write(chunk(b"IEND", b""))


def render_contact_sheet(font, start, count, columns=16):
    count = min(count, font.glyph_count - start)
    rows = (count + columns - 1) // columns
    cell_w = font.width + 2
    cell_h = font.height + 2
    sheet_w = columns * cell_w
    sheet_h = rows * cell_h
    gray = bytearray([255] * (sheet_w * sheet_h))

    # brightest bg level is bpp-dependent: value 0 -> white background,
    # top pixel value -> near-black ink.
    max_val = (1 << font.bpp) - 1

    def put(x, y, v):
        if 0 <= x < sheet_w and 0 <= y < sheet_h:
            gray[y * sheet_w + x] = v

    for i in range(count):
        glyph_index = start + i
        col = i % columns
        row = i // columns
        ox = col * cell_w + 1
        oy = row * cell_h + 1
        pixels = font.glyph_pixels(glyph_index)
        for py in range(font.height):
            for px in range(font.width):
                v = pixels[py * font.width + px]
                gray_v = 255 - (v * 255 // max_val)
                put(ox + px, oy + py, gray_v)
    return sheet_w, sheet_h, bytes(gray)


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def cmd_list(args):
    n, fonts, palettes = load_fonts(args.archive)
    print(f"[*] {args.archive}: {n.file_count} sub-files, "
          f"{len(fonts)} RTFN font(s), {len(palettes)} RLCN palette(s) "
          f"(indices {palettes})")
    for idx in sorted(fonts):
        f = fonts[idx]
        print(f"  font #{idx}: {f.width}x{f.height} {f.bpp}bpp, "
              f"cell_size={f.cell_size} bytes, {f.glyph_count} glyphs, "
              f"line_height={f.line_height}, CWDH body={f.cwdh_body_len} bytes "
              f"(not decoded)")
        for c in f.cmap_chunks:
            extra = ""
            if c.method == 0:
                extra = f" base_index={c.base_index}"
            elif c.method == 2:
                extra = f" entries={len(c.pairs)}"
            print(f"      cmap {c.describe()}{extra}")
    return 0


def cmd_render(args):
    n, fonts, _palettes = load_fonts(args.archive)
    targets = sorted(fonts) if args.font is None else [args.font]
    for idx in targets:
        if idx not in fonts:
            print(f"error: no RTFN font at sub-file {idx}", file=sys.stderr)
            return 2
        f = fonts[idx]
        w, h, gray = render_contact_sheet(f, args.start, args.count, args.columns)
        out_path = os.path.join(args.out, f"font_{idx}.png")
        write_png_gray8(out_path, w, h, gray)
        shown = min(args.count, f.glyph_count - args.start)
        print(f"[*] font #{idx}: wrote {out_path} ({w}x{h}, "
              f"{shown} glyphs from index {args.start})")
    return 0


def cmd_widths(args):
    n, fonts, _palettes = load_fonts(args.archive)
    targets = sorted(fonts) if args.font is None else [args.font]
    for idx in targets:
        if idx not in fonts:
            print(f"error: no RTFN font at sub-file {idx}", file=sys.stderr)
            return 2
        f = fonts[idx]
        count = min(args.count, f.glyph_count - args.start)
        print(f"[*] font #{idx}: glyph metrics (bearing, width, advance), "
              f"indices {args.start}..{args.start + count - 1}")
        for i in range(count):
            gi = args.start + i
            bearing, width, advance = f.glyph_metrics(gi)
            ch = ""
            code = 0x20 + gi if gi < 95 else None  # ASCII direct-range chunk
            if code is not None and 0x20 <= code <= 0x7E:
                ch = f"  {chr(code)!r}"
            print(f"  #{gi:5d}  bearing={bearing:4d}  width={width:3d}  "
                  f"advance={advance:3d}{ch}")
    return 0


def cmd_verify(args):
    n, fonts, _palettes = load_fonts(args.archive)
    total_glyphs = 0
    total_ok = 0
    for idx in sorted(fonts):
        f = fonts[idx]
        ok = 0
        bad = []
        for gi in range(f.glyph_count):
            start, orig = f._glyph_slice(gi)
            redone = f.glyph_record_bytes(gi)
            if redone == orig:
                ok += 1
            else:
                bad.append(gi)
        total_glyphs += f.glyph_count
        total_ok += ok
        status = "OK" if not bad else f"{len(bad)} mismatches (first: {bad[:5]})"
        print(f"[*] font #{idx}: {ok}/{f.glyph_count} glyph records "
              f"byte-identical -- {status}")
    print(f"[*] total: {total_ok}/{total_glyphs} glyph records byte-identical "
          f"across {len(fonts)} fonts")
    return 0 if total_ok == total_glyphs else 1


def main(argv=None):
    ap = argparse.ArgumentParser(
        prog="font.py",
        description="Decode NFTR (RTFN) font archives.",
    )
    ap.add_argument("--archive", default=ARCHIVE_PATH,
                     help=f"NARC path (default: {ARCHIVE_PATH})")
    ap.add_argument("--font", type=int, default=None,
                     help="restrict to one RTFN sub-file index (default: all)")
    sub = ap.add_subparsers(dest="cmd", required=True)

    p = sub.add_parser("list", help="summarize every font in the archive")
    p.set_defaults(func=cmd_list)

    p = sub.add_parser("render", help="write a contact-sheet PNG per font")
    p.add_argument("--start", type=int, default=0, help="first glyph index")
    p.add_argument("--count", type=int, default=128, help="glyph count")
    p.add_argument("--columns", type=int, default=16)
    p.add_argument("--out", default=OUT_DIR)
    p.set_defaults(func=cmd_render)

    p = sub.add_parser("widths", help="dump per-glyph metrics")
    p.add_argument("--start", type=int, default=0)
    p.add_argument("--count", type=int, default=128)
    p.set_defaults(func=cmd_widths)

    p = sub.add_parser("verify", help="round-trip every glyph record")
    p.set_defaults(func=cmd_verify)

    args = ap.parse_args(argv)
    try:
        return args.func(args)
    except (FontError, narc.NarcError) as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
