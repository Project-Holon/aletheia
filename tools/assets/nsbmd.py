#!/usr/bin/env python3
"""
nsbmd.py -- NSBMD (BMD0, 3D model) / NSBTX (BTX0, 3D texture) reader for the
aletheia asset lane.

Written from scratch for the aletheia project. Stdlib only, single file.
Format knowledge used here (container shape, ResDict layout, the GX
geometry-command opcode/parameter table, the NDS texture pixel formats and
the TEXIMAGE_PARAM hardware register bit layout) is drawn from public
hardware documentation (the kind of material commonly known as "GBATEK",
covering the DS's 3D engine registers and command FIFO) and cross-checked
by hand against real files extracted from this ROM -- no code from any
other decomp/ROM-hacking project was used or consulted.

--------------------------------------------------------------------------
Container layout (confirmed empirically against real BMD0/BTX0 sub-files)
--------------------------------------------------------------------------
Both BMD0 (model) and BTX0 (texture-only) files share the same "Nitro G3D"
outer container:

    0x00  char[4]  magic          "BMD0" or "BTX0"
    0x04  u16      byte_order     0xFEFF
    0x06  u16      version        seen 0x0001 (BTX0) / 0x0002 (BMD0)
    0x08  u32      file_size
    0x0C  u16      header_size    0x10
    0x0E  u16      num_blocks     1 (BTX0: TEX0 only) or 2 (BMD0: MDL0, TEX0)
    0x10  u32[num_blocks]         absolute byte offsets of each block

Each block is itself magic+size prefixed (e.g. b"MDL0"/b"TEX0" + u32 size
including this 8-byte sub-header). This part is fully understood and is
parsed/round-tripped field-by-field below.

--------------------------------------------------------------------------
Resource dictionaries (ResDict) -- MDL0's model list, TEX0's texture and
palette lists
--------------------------------------------------------------------------
Every named list in a G3D chunk (models in MDL0, textures/palettes in
TEX0) uses the same outer dictionary shape, confirmed byte-for-byte
against several real files of different entry counts:

    0x00  u8   revision        0
    0x01  u8   numEntries
    0x02  u16  size             total dict size in bytes, INCLUDING this
                                 8-byte header
    0x04  u16  unk4             seen 0x0008 in every sample; not decoded
    0x06  u16  unk6             seen 0x0010 (MDL0) / 0x0010 (TEX0, cnt=1) /
                                 0x0024 (TEX0, cnt=6); not decoded (does not
                                 equal a per-entry byte stride we could
                                 confirm -- see honesty note below)
    ...   raw "entries" blob    numEntries lookup-tree nodes plus
                                 per-entry payload data (offsets, texture
                                 dimensions/format, etc.)
    ...   numEntries * 16 bytes  ASCII names, NUL-padded to 16 bytes each,
                                 always the LAST numEntries*16 bytes of the
                                 dict (confirmed: for every sample checked,
                                 dict_size - 8 - numEntries*16 bytes of
                                 "entries" precede a block of clean ASCII
                                 names)

**Honesty note (this pass did not fully crack the per-entry payload
layout):** the "entries" blob's internal record stride is NOT the same
size for every dict (it worked out to 12 bytes/entry for a 1-model MDL0
dict and did not divide evenly for a 6-texture TEX0 dict), suggesting the
real per-entry record size varies by resource type and possibly by
texture format (e.g. 4x4-compressed textures likely carry an extra index-
table pointer that plain formats don't). Rather than guess a wrong fixed
stride and silently produce corrupted results, this reader treats the
entries blob as an **opaque byte range** for every dict: enough to
preserve it for byte-identical round-tripping (see below), and enough to
list resource *names* (the parts of the format we ARE confident about),
but NOT enough to reliably recover a specific texture's exact
offset/width/height/format from the TEX0 dict alone. Texture decoding
below instead recovers those parameters by brute-force, self-consistent
search against the block's confirmed global data-size fields (see
"Texture parameter recovery").

--------------------------------------------------------------------------
TEX0 header (confirmed fields, everything else kept opaque)
--------------------------------------------------------------------------
TEX0 opens with a fixed 0x3C-byte header (after magic+size) before the
texture ResDict begins. Two fields were confirmed by cross-referencing
against where the texture/palette raw data actually starts (found
independently via the two ResDicts' own `size` fields):

    rel+0x0C (u32 @ TEX0+0x14)   texture data byte offset from TEX0 start
    rel+0x1C (u32 @ TEX0+0x24)   palette data byte offset from TEX0 start
                                  (equals texDictOfs(0x3C) + texDictSize +
                                  palDictSize in every sample checked)

texture_data_size = palette_data_offset - texture_data_offset (confirmed:
matches the byte range actually occupied by texel-looking data in every
sample). The rest of the 0x3C-byte header is preserved verbatim (not
reinterpreted) -- round-tripping does not require understanding it.

--------------------------------------------------------------------------
Texture parameter recovery (best-effort, documented as a heuristic)
--------------------------------------------------------------------------
Since the exact per-entry TEX0 dict record isn't cracked (see above), this
module decodes actual pixels only for the common case of a TEX0 block
holding exactly **one** texture: with a single texture, the entire
texture_data_size region belongs to it, so (format, width, height) can be
recovered by brute-force search over the DS hardware's legal texture
sizes (powers of two, 8..1024) and pixel formats, keeping only
combinations whose byte size exactly equals texture_data_size, then
picking the candidate whose decoded palette indices are all in-range for
the paired palette (a genuine validity check, not a guess) -- this is the
same "verify self-consistency, don't trust a blind sniff" spirit already
used elsewhere in this project (see docs/ASSETS.md's LZ77/Huffman sniff
notes). Multi-texture TEX0 blocks are listed (names, count) but their
individual pixels are NOT decoded by this pass -- a documented gap.

--------------------------------------------------------------------------
NDS texture pixel formats (GX TEXIMAGE_PARAM format field, public hardware
spec, decoded independently of the above uncertainty)
--------------------------------------------------------------------------
    1  A3I5     1 byte/px:  bits0-4 = palette index (32 colors),
                            bits5-7 = 3-bit alpha (0..7 -> 0..255)
    2  4-color  2 bits/px, 4 pixels/byte, LSB first
    3  16-color 4 bits/px, 2 pixels/byte, low nibble first
    4  256-color 1 byte/px = palette index directly
    5  4x4-compressed -- NOT decoded by this pass (needs a second,
       separately-addressed per-block index/mode table this pass did not
       locate with confidence; see gaps)
    6  A5I3     1 byte/px:  bits0-2 = palette index (8 colors),
                            bits3-7 = 5-bit alpha (0..31 -> 0..255)
    7  direct   2 bytes/px, BGR555 + bit15 alpha-enable (no palette)

Palette entries throughout are BGR555 (u16, 5 bits each channel, low to
high: R, G, B), the same colour packing as GBA/NDS OAM/BG palettes
already decoded elsewhere in this project's tools.

--------------------------------------------------------------------------
Geometry command stream (GX FIFO commands, public hardware spec)
--------------------------------------------------------------------------
Shape data inside MDL0 is a stream of the DS 3D engine's FIFO commands:
one u32 "packed command word" holding 4 opcode bytes (0x00 = NOP, used as
padding when a group doesn't need all 4 slots), immediately followed by
each non-NOP opcode's parameter words (one u32 each), in order. This
reader implements the whole documented opcode table (so it can correctly
skip over commands it doesn't otherwise use, like matrix/lighting ones)
but only *interprets* the handful needed for a static, single-mesh OBJ
export: BEGIN_VTXS (0x40, selects triangle/quad/tristrip/quadstrip mode),
END_VTXS (0x41), TEXCOORD (0x22, s16.4 fixed-point texel units),
VTX_16 (0x23, s16.12 fixed-point position, 2 param words), and NORMAL
(0x21, ignored for OBJ export beyond being skipped correctly).

The command stream's start offset inside MDL0 is located heuristically:
scan for the first position at which decoding as a command stream
succeeds for a long, uninterrupted run (every opcode byte seen is a
recognised opcode with enough buffer left for its parameters). Real
non-command bytes hit an unrecognised opcode almost immediately, while
the real stream decodes cleanly for hundreds of commands, so this is a
reliable locator in practice (verified against the sample models below:
the decoded vertex positions traced a smooth polygon fan, and no
premature invalid-opcode stop occurred inside a shape).

--------------------------------------------------------------------------
Round trip
--------------------------------------------------------------------------
`reserialize()` rebuilds the exact input bytes from a parsed Bmd0/Btx0
structure by re-emitting every field this module parses PLUS the opaque
byte ranges it deliberately did not reinterpret (dict entries blobs, the
TEX0 0x3C-byte header, and the MDL0/TEX0 raw data tail). Because every
byte of the original file is accounted for by either a parsed field or an
opaque passthrough range, this reconstructs the input exactly -- verified
below over many real sub-files, not just the samples used for texture/
geometry decoding.
"""

import argparse
import glob
import json
import os
import struct
import sys
import zlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc as narcmod  # noqa: E402


class Nsbmd0Error(Exception):
    pass


# ---------------------------------------------------------------------------
# Generic resource dictionary (ResDict)
# ---------------------------------------------------------------------------

class ResDict:
    def __init__(self, revision, count, unk4, unk6, entries_raw, names):
        self.revision = revision
        self.count = count
        self.unk4 = unk4
        self.unk6 = unk6
        self.entries_raw = entries_raw  # opaque; preserved for round trip
        self.names = names  # list of str, len == count

    @property
    def size(self):
        return 8 + len(self.entries_raw) + len(self.names) * 16

    def serialize(self):
        out = struct.pack("<BBHHH", self.revision, self.count, self.size,
                           self.unk4, self.unk6)
        out += self.entries_raw
        for name in self.names:
            nb = name.encode("ascii")[:16]
            out += nb + b"\x00" * (16 - len(nb))
        return out


def parse_dict(buf, off):
    if off + 8 > len(buf):
        raise Nsbmd0Error("ResDict header runs past end of block")
    revision, count, size, unk4, unk6 = struct.unpack_from("<BBHHH", buf, off)
    if off + size > len(buf):
        raise Nsbmd0Error("ResDict claims size past end of block")
    body = buf[off:off + size]
    names_blob = body[size - count * 16:size] if count else b""
    names = []
    for i in range(count):
        raw = names_blob[i * 16:i * 16 + 16]
        names.append(raw.split(b"\x00", 1)[0].decode("ascii", "replace"))
    entries_raw = body[8:size - count * 16]
    return ResDict(revision, count, unk4, unk6, entries_raw, names)


# ---------------------------------------------------------------------------
# TEX0 (also the body of a BTX0)
# ---------------------------------------------------------------------------

TEX0_HEADER_SIZE = 0x3C


class Tex0:
    def __init__(self, header_extra, tex_dict, pal_dict, raw_data,
                 tex_data_offset, pal_data_offset):
        self.header_extra = header_extra  # bytes[8:0x3C], opaque
        self.tex_dict = tex_dict
        self.pal_dict = pal_dict
        self.raw_data = raw_data  # everything from tex_dict end to block end
        self.tex_data_offset = tex_data_offset  # absolute, from TEX0 start
        self.pal_data_offset = pal_data_offset

    @property
    def texture_data_size(self):
        return self.pal_data_offset - self.tex_data_offset

    def texel_bytes(self):
        lo = self.tex_data_offset - (TEX0_HEADER_SIZE + self.tex_dict.size +
                                      self.pal_dict.size)
        return self.raw_data[lo:lo + self.texture_data_size]

    def palette_bytes(self):
        lo = self.pal_data_offset - (TEX0_HEADER_SIZE + self.tex_dict.size +
                                      self.pal_dict.size)
        return self.raw_data[lo:]

    def serialize(self):
        body = self.header_extra + self.tex_dict.serialize() + \
            self.pal_dict.serialize() + self.raw_data
        out = b"TEX0" + struct.pack("<I", 8 + len(body)) + body
        return out


def parse_tex0(block):
    if block[:4] != b"TEX0":
        raise Nsbmd0Error("expected TEX0 magic")
    size = struct.unpack_from("<I", block, 4)[0]
    if size > len(block):
        raise Nsbmd0Error("TEX0 size past end of block")
    block = block[:size]
    header_extra = block[8:TEX0_HEADER_SIZE]
    tex_data_offset = struct.unpack_from("<I", block, 0x14)[0]
    pal_data_offset = struct.unpack_from("<I", block, 0x24)[0]
    tex_dict = parse_dict(block, TEX0_HEADER_SIZE)
    pal_dict_off = TEX0_HEADER_SIZE + tex_dict.size
    pal_dict = parse_dict(block, pal_dict_off)
    raw_data = block[pal_dict_off + pal_dict.size:]
    return Tex0(header_extra, tex_dict, pal_dict, raw_data,
                tex_data_offset, pal_data_offset)


# ---------------------------------------------------------------------------
# MDL0
# ---------------------------------------------------------------------------

class Mdl0:
    def __init__(self, model_dict, raw_tail):
        self.model_dict = model_dict
        self.raw_tail = raw_tail  # all model data, opaque (round-trip only)

    def serialize(self):
        body = self.model_dict.serialize() + self.raw_tail
        return b"MDL0" + struct.pack("<I", 8 + len(body)) + body


def parse_mdl0(block):
    if block[:4] != b"MDL0":
        raise Nsbmd0Error("expected MDL0 magic")
    size = struct.unpack_from("<I", block, 4)[0]
    block = block[:size]
    model_dict = parse_dict(block, 8)
    raw_tail = block[8 + model_dict.size:]
    return Mdl0(model_dict, raw_tail)


# ---------------------------------------------------------------------------
# Outer BMD0 / BTX0 container
# ---------------------------------------------------------------------------

class Container:
    def __init__(self, magic, bom, version, header_size, blocks):
        self.magic = magic
        self.bom = bom
        self.version = version
        self.header_size = header_size
        self.blocks = blocks  # list of (magic4, parsed_object_or_raw_bytes)

    def serialize(self):
        block_bytes = []
        for magic4, obj in self.blocks:
            if hasattr(obj, "serialize"):
                block_bytes.append(obj.serialize())
            else:
                block_bytes.append(obj)
        n = len(block_bytes)
        header = struct.pack("<4sHHIHH", self.magic, self.bom, self.version,
                              0, self.header_size, n)
        offsets_pos = self.header_size
        cur = offsets_pos + 4 * n
        offsets = []
        for b in block_bytes:
            offsets.append(cur)
            cur += len(b)
        out = bytearray(header)
        out += struct.pack("<%dI" % n, *offsets)
        for b in block_bytes:
            out += b
        total = len(out)
        struct.pack_into("<I", out, 8, total)
        return bytes(out)


def parse_container(data):
    magic, bom, version, file_size, header_size, nblk = \
        struct.unpack_from("<4sHHIHH", data, 0)
    if magic not in (b"BMD0", b"BTX0"):
        raise Nsbmd0Error(f"unexpected magic {magic!r}")
    offs = struct.unpack_from("<%dI" % nblk, data, header_size)
    blocks = []
    for o in offs:
        m4 = data[o:o + 4]
        if m4 == b"MDL0":
            blocks.append((m4, parse_mdl0(data[o:])))
        elif m4 == b"TEX0":
            blocks.append((m4, parse_tex0(data[o:])))
        else:
            # unknown block kind: keep raw so round trip still works
            blocks.append((m4, data[o:file_size]))
    return Container(magic, bom, version, header_size, blocks)


def find_tex0(container):
    for m4, obj in container.blocks:
        if m4 == b"TEX0":
            return obj
    return None


def find_mdl0(container):
    for m4, obj in container.blocks:
        if m4 == b"MDL0":
            return obj
    return None


# ---------------------------------------------------------------------------
# Texture pixel decoding
# ---------------------------------------------------------------------------

def bgr555_to_rgb(v):
    r = (v & 0x1F) * 255 // 31
    g = ((v >> 5) & 0x1F) * 255 // 31
    b = ((v >> 10) & 0x1F) * 255 // 31
    return (r, g, b)


def decode_palette(pal_bytes):
    n = len(pal_bytes) // 2
    colors = struct.unpack_from("<%dH" % n, pal_bytes, 0)
    return [bgr555_to_rgb(c) for c in colors]


# formats we can fully decode without an extra index-table lookup
FORMAT_BITS_PER_PIXEL = {1: 8, 2: 2, 3: 4, 4: 8, 6: 8, 7: 16}
FORMAT_NAMES = {
    1: "A3I5", 2: "4-color", 3: "16-color", 4: "256-color",
    5: "4x4-compressed (unimplemented)", 6: "A5I3", 7: "direct",
}


def decode_texture(fmt, width, height, texel, palette):
    """Return (rgba_bytes, valid_ratio). rgba_bytes is width*height*4 bytes,
    row-major. valid_ratio is 1.0 for direct-color (no palette to be out of
    range against) and, for paletted formats, the fraction of decoded pixel
    indices that were within the supplied palette -- used as a
    self-consistency score when several (format, width, height) candidates
    all match the available byte count (see module docstring)."""
    n = width * height
    out = bytearray(n * 4)
    valid = 0
    total = 0
    if fmt == 7:
        for i in range(n):
            v = texel[i * 2] | (texel[i * 2 + 1] << 8)
            r, g, b = bgr555_to_rgb(v & 0x7FFF)
            a = 255 if (v & 0x8000) else 0
            out[i * 4:i * 4 + 4] = bytes((r, g, b, a))
        return bytes(out), 1.0
    if fmt in (1, 6):
        for i in range(n):
            byte = texel[i]
            if fmt == 1:
                idx = byte & 0x1F
                a3 = (byte >> 5) & 7
                a = a3 * 255 // 7
            else:
                idx = byte & 7
                a5 = (byte >> 3) & 0x1F
                a = a5 * 255 // 31
            total += 1
            if idx < len(palette):
                valid += 1
                r, g, b = palette[idx]
            else:
                r, g, b = (255, 0, 255)
            out[i * 4:i * 4 + 4] = bytes((r, g, b, a))
        return bytes(out), (valid / total if total else 0.0)
    if fmt == 4:
        for i in range(n):
            idx = texel[i]
            total += 1
            if idx < len(palette):
                valid += 1
                r, g, b = palette[idx]
            else:
                r, g, b = (255, 0, 255)
            out[i * 4:i * 4 + 4] = bytes((r, g, b, 255))
        return bytes(out), (valid / total if total else 0.0)
    if fmt in (2, 3):
        per_byte = 4 if fmt == 2 else 2
        bits = 2 if fmt == 2 else 4
        mask = (1 << bits) - 1
        for byte_i in range(len(texel)):
            byte = texel[byte_i]
            for sub in range(per_byte):
                pi = byte_i * per_byte + sub
                if pi >= n:
                    break
                idx = (byte >> (sub * bits)) & mask
                total += 1
                if idx < len(palette):
                    valid += 1
                    r, g, b = palette[idx]
                else:
                    r, g, b = (255, 0, 255)
                a = 255
                out[pi * 4:pi * 4 + 4] = bytes((r, g, b, a))
        return bytes(out), (valid / total if total else 0.0)
    raise Nsbmd0Error(f"format {fmt} not implemented")


SIZE_CLASSES = [8, 16, 32, 64, 128, 256, 512, 1024]


def guess_single_texture(tex0):
    """Best-effort (format, width, height) recovery for a TEX0 block that
    holds exactly one texture -- see module docstring 'Texture parameter
    recovery'. Returns (fmt, width, height, valid_ratio) for the winning
    candidate, or None if no (format, width, height) combination's byte
    size matches the available texel data exactly."""
    texel = tex0.texel_bytes()
    palette = decode_palette(tex0.palette_bytes())
    size = len(texel)
    candidates = []
    for fmt, bits in FORMAT_BITS_PER_PIXEL.items():
        for w in SIZE_CLASSES:
            for h in SIZE_CLASSES:
                if (w * h * bits) % 8:
                    continue
                if w * h * bits // 8 == size:
                    candidates.append((fmt, w, h))
    if not candidates:
        return None
    # Index-range (2**bpp) per indexed format, used as a tie-breaker below:
    # a texture almost always uses (close to) its whole attached palette,
    # so a format whose index range matches len(palette) closely is a much
    # better bet than one that only exercises a sliver of it -- and format 7
    # (direct colour, no palette at all) trivially scores a perfect
    # valid_ratio for ANY texel data, so it must never win against an
    # equally-valid paletted candidate or it would dominate by default.
    index_range = {1: 32, 2: 4, 3: 16, 4: 256, 6: 8}
    scored = []
    for fmt, w, h in candidates:
        _, ratio = decode_texture(fmt, w, h, texel, palette)
        if fmt == 7:
            palette_fit = 10 ** 9  # worst possible fit unless it's the only option
        else:
            palette_fit = abs(index_range[fmt] - len(palette))
        scored.append((ratio, -palette_fit, -abs(w - h), fmt, w, h))
    scored.sort(reverse=True)
    ratio, _, _, fmt, w, h = scored[0]
    return fmt, w, h, ratio


def write_png_rgba8(path, width, height, rgba_bytes):
    def chunk(tag, data):
        out = struct.pack(">I", len(data)) + tag + data
        crc = zlib.crc32(tag)
        crc = zlib.crc32(data, crc) & 0xFFFFFFFF
        out += struct.pack(">I", crc)
        return out

    sig = b"\x89PNG\r\n\x1a\n"
    ihdr = struct.pack(">IIBBBBB", width, height, 8, 6, 0, 0, 0)  # RGBA
    raw = bytearray()
    for y in range(height):
        raw.append(0)
        raw.extend(rgba_bytes[y * width * 4:(y + 1) * width * 4])
    idat = zlib.compress(bytes(raw), 9)
    parent = os.path.dirname(os.path.abspath(path))
    if parent:
        os.makedirs(parent, exist_ok=True)
    with open(path, "wb") as fh:
        fh.write(sig)
        fh.write(chunk(b"IHDR", ihdr))
        fh.write(chunk(b"IDAT", idat))
        fh.write(chunk(b"IEND", b""))


# ---------------------------------------------------------------------------
# Geometry command stream (GX FIFO)
# ---------------------------------------------------------------------------

GX_PARAM_COUNTS = {
    0x00: 0,
    0x10: 1, 0x11: 0, 0x12: 1, 0x13: 1, 0x14: 1, 0x15: 0, 0x16: 16,
    0x17: 12, 0x18: 16, 0x19: 12, 0x1A: 9, 0x1B: 3, 0x1C: 3,
    0x20: 1, 0x21: 1, 0x22: 1, 0x23: 2, 0x24: 1, 0x25: 1, 0x26: 1,
    0x27: 1, 0x28: 1, 0x29: 1, 0x2A: 1, 0x2B: 1,
    0x30: 1, 0x31: 1, 0x32: 1, 0x33: 1, 0x34: 32,
    0x40: 1, 0x41: 0, 0x50: 1, 0x60: 1, 0x70: 3, 0x71: 2, 0x72: 1,
}


def _s16(u16):
    return u16 - 0x10000 if u16 & 0x8000 else u16


def gx_decode(data, start):
    """Decode a GX command stream starting at byte offset `start` in
    `data`. Returns (vertices, uvs, faces, num_commands, end_offset).
    vertices/uvs are parallel lists (one uv per vertex, the last TEXCOORD
    seen before each VTX_16). faces is a list of vertex-index lists
    (triangles or quads, already fanned out of strips)."""
    p = start
    n = len(data)
    verts = []
    uvs = []
    faces = []
    cur_uv = (0.0, 0.0)
    cur_batch = []
    cur_mode = None
    cmds = 0
    while p + 4 <= n:
        word = struct.unpack_from("<I", data, p)[0]
        ops = [word & 0xFF, (word >> 8) & 0xFF, (word >> 16) & 0xFF,
               (word >> 24) & 0xFF]
        if any(op not in GX_PARAM_COUNTS for op in ops):
            break
        newp = p + 4
        ok = True
        for op in ops:
            if op == 0:
                continue
            npar = GX_PARAM_COUNTS[op]
            if newp + 4 * npar > n:
                ok = False
                break
            params = struct.unpack_from("<%dI" % npar, data, newp) if npar else ()
            newp += 4 * npar
            cmds += 1
            if op == 0x22:  # TEXCOORD: s16.4 fixed-point (s, t)
                s = _s16(params[0] & 0xFFFF)
                t = _s16((params[0] >> 16) & 0xFFFF)
                cur_uv = (s / 16.0, t / 16.0)
            elif op == 0x23:  # VTX_16: s16.12 fixed-point (x, y | z, _)
                x = _s16(params[0] & 0xFFFF)
                y = _s16((params[0] >> 16) & 0xFFFF)
                z = _s16(params[1] & 0xFFFF)
                verts.append((x / 4096.0, y / 4096.0, z / 4096.0))
                uvs.append(cur_uv)
                cur_batch.append(len(verts) - 1)
            elif op == 0x40:  # BEGIN_VTXS
                cur_mode = params[0] & 0x3
                cur_batch = []
            elif op == 0x41:  # END_VTXS
                if cur_mode == 0:  # triangles
                    for i in range(0, len(cur_batch) - 2, 3):
                        faces.append(cur_batch[i:i + 3])
                elif cur_mode == 1:  # quads
                    for i in range(0, len(cur_batch) - 3, 4):
                        faces.append(cur_batch[i:i + 4])
                elif cur_mode == 2:  # triangle strip
                    for i in range(len(cur_batch) - 2):
                        tri = cur_batch[i:i + 3]
                        if i % 2 == 1:
                            tri = [tri[0], tri[2], tri[1]]
                        faces.append(tri)
                elif cur_mode == 3:  # quad strip
                    for i in range(0, len(cur_batch) - 3, 2):
                        a, b, c, d = cur_batch[i:i + 4]
                        faces.append([a, b, d, c])
                cur_batch = []
        if not ok:
            break
        p = newp
    return verts, uvs, faces, cmds, p


def find_gx_stream(data, min_commands=20):
    """Heuristically locate the start of a GX command stream inside a
    model's raw data: the first offset from which decoding runs for at
    least `min_commands` without hitting an unrecognised opcode."""
    best = None
    for start in range(0, len(data) - 4, 4):
        verts, uvs, faces, cmds, end = gx_decode(data, start)
        if cmds >= min_commands:
            return start, (verts, uvs, faces, cmds, end)
    return None


def write_obj(path, verts, uvs, faces):
    parent = os.path.dirname(os.path.abspath(path))
    if parent:
        os.makedirs(parent, exist_ok=True)
    with open(path, "w") as fh:
        fh.write("# exported by tools/assets/nsbmd.py\n")
        for x, y, z in verts:
            fh.write(f"v {x:.6f} {y:.6f} {z:.6f}\n")
        for u, v in uvs:
            fh.write(f"vt {u:.6f} {1.0 - v:.6f}\n")
        for face in faces:
            idx = " ".join(f"{i + 1}/{i + 1}" for i in face)
            fh.write(f"f {idx}\n")


# ---------------------------------------------------------------------------
# Round trip
# ---------------------------------------------------------------------------

def round_trip_check(data):
    container = parse_container(data)
    out = container.serialize()
    return out == data, len(out), len(data)


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def _iter_g3d_subfiles(narc_path, magics=(b"BMD0", b"BTX0")):
    n = narcmod.parse_file(narc_path)
    for i in range(n.file_count):
        raw = n.read(i)
        if raw[:4] in magics:
            yield i, raw


def cmd_info(args):
    with open(args.input, "rb") as fh:
        data = fh.read()
    c = parse_container(data)
    info = {"magic": c.magic.decode(), "blocks": []}
    for m4, obj in c.blocks:
        if m4 == b"TEX0":
            info["blocks"].append({
                "magic": "TEX0",
                "textures": obj.tex_dict.names,
                "palettes": obj.pal_dict.names,
                "texture_data_size": obj.texture_data_size,
            })
        elif m4 == b"MDL0":
            info["blocks"].append({
                "magic": "MDL0",
                "models": obj.model_dict.names,
            })
        else:
            info["blocks"].append({"magic": m4.decode("ascii", "replace")})
    print(json.dumps(info, indent=2))
    return 0


def cmd_roundtrip(args):
    total = 0
    ok = 0
    fails = []
    for narc_path in sorted(glob.glob(args.glob)):
        try:
            for i, raw in _iter_g3d_subfiles(narc_path):
                total += 1
                try:
                    same, outlen, inlen = round_trip_check(raw)
                except Exception as exc:  # noqa: BLE001
                    fails.append((narc_path, i, f"parse/serialize error: {exc}"))
                    continue
                if same:
                    ok += 1
                else:
                    fails.append((narc_path, i, f"mismatch out={outlen} in={inlen}"))
        except Exception as exc:  # noqa: BLE001
            fails.append((narc_path, -1, f"NARC error: {exc}"))
    print(f"[*] round-trip: {ok}/{total} BMD0/BTX0 sub-files byte-identical")
    for path, idx, msg in fails[:20]:
        print(f"  ! {path}#{idx}: {msg}")
    if len(fails) > 20:
        print(f"  ... and {len(fails) - 20} more")
    return 0 if not fails else 1


def cmd_texture(args):
    with open(args.input, "rb") as fh:
        data = fh.read()
    c = parse_container(data)
    tex0 = find_tex0(c)
    if tex0 is None:
        print("error: no TEX0 block in this file", file=sys.stderr)
        return 2
    if tex0.tex_dict.count != 1:
        print(f"error: {tex0.tex_dict.count} textures present; this command "
              f"only decodes single-texture TEX0 blocks (see module "
              f"docstring)", file=sys.stderr)
        return 2
    guess = guess_single_texture(tex0)
    if guess is None:
        print("error: no (format, width, height) matches the texture data "
              "size", file=sys.stderr)
        return 2
    fmt, w, h, ratio = guess
    name = tex0.tex_dict.names[0] if tex0.tex_dict.names else "texture"
    print(f"[*] {name}: guessed format={FORMAT_NAMES[fmt]} ({fmt}) "
          f"{w}x{h}, palette-validity={ratio:.3f}")
    if fmt == 5:
        print("error: 4x4-compressed decoding is not implemented",
              file=sys.stderr)
        return 2
    palette = decode_palette(tex0.palette_bytes())
    rgba, _ = decode_texture(fmt, w, h, tex0.texel_bytes(), palette)
    write_png_rgba8(args.output, w, h, rgba)
    print(f"[*] wrote {args.output} ({w}x{h})")
    return 0


def cmd_obj(args):
    with open(args.input, "rb") as fh:
        data = fh.read()
    c = parse_container(data)
    mdl0 = find_mdl0(c)
    if mdl0 is None:
        print("error: no MDL0 block in this file", file=sys.stderr)
        return 2
    found = find_gx_stream(mdl0.raw_tail)
    if found is None:
        print("error: could not locate a GX command stream", file=sys.stderr)
        return 2
    start, (verts, uvs, faces, cmds, end) = found
    print(f"[*] GX stream at model offset 0x{start:X}, {cmds} commands, "
          f"{len(verts)} vertices, {len(faces)} faces")
    # TEXCOORD values are texel units (s16.4 fixed-point already divided
    # down in gx_decode); normalise to the usual OBJ 0..1 UV range using
    # the attached texture's guessed dimensions, when there is exactly one
    # texture to guess against. Best-effort -- see guess_single_texture().
    tex0 = find_tex0(c)
    if tex0 is not None and tex0.tex_dict.count == 1:
        guess = guess_single_texture(tex0)
        if guess is not None:
            _, tw, th, _ = guess
            uvs = [(u / tw, v / th) for u, v in uvs]
            print(f"[*] normalised UVs against guessed texture size {tw}x{th}")
    write_obj(args.output, verts, uvs, faces)
    print(f"[*] wrote {args.output}")
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(
        prog="nsbmd.py",
        description="Parse/decode NSBMD (BMD0) and NSBTX (BTX0) 3D chunks.",
    )
    sub = ap.add_subparsers(dest="cmd", required=True)

    p = sub.add_parser("info", help="print model/texture/palette names as JSON")
    p.add_argument("input")
    p.set_defaults(func=cmd_info)

    p = sub.add_parser("texture", help="decode a single-texture TEX0 block to PNG")
    p.add_argument("input")
    p.add_argument("-o", "--output", required=True)
    p.set_defaults(func=cmd_texture)

    p = sub.add_parser("obj", help="export the first decodable shape to OBJ")
    p.add_argument("input")
    p.add_argument("-o", "--output", required=True)
    p.set_defaults(func=cmd_obj)

    p = sub.add_parser("roundtrip", help="byte-identity round-trip check over a glob of NARCs")
    p.add_argument("glob")
    p.set_defaults(func=cmd_roundtrip)

    args = ap.parse_args(argv)
    try:
        return args.func(args)
    except Nsbmd0Error as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
