#!/usr/bin/env python3
"""
nsbmd.py -- NSBMD (BMD0, 3D model) / NSBTX (BTX0, 3D texture) reader for the
aletheia asset lane.

Written from scratch for aletheia. Stdlib only, single file.
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
import collections
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

    def entries(self):
        """Decode the per-entry data records, now that the dict layout is
        fully cracked (see module docstring 'Resource dictionary record
        layout, CRACKED'): the "entries" blob is a patricia-tree node array
        of `count + 1` 4-byte nodes (`refBit, leftIdx, rightIdx, dataIdx`,
        not otherwise interpreted here -- this reader doesn't need the
        lookup structure, only the data that follows it) immediately
        followed by a 4-byte {entrySize: u16, namesOffset: u16} sub-header,
        then `count * entrySize` bytes of per-entry data records.

        Confirmed byte-for-byte against real files: for every TEX0/palette
        dict sampled (1 to 87 entries), the sub-header sits at exactly
        `(count + 1) * 4` bytes into entries_raw (equivalently, dict offset
        `8 + (count + 1) * 4`, which is exactly the previously-unexplained
        `unk6` header field -- it is the byte offset to this sub-header,
        not a "pnodeOffset" pointing at the node array's start, which is
        instead always the fixed `8` seen as `unk4`), and
        `sub_header_offset + 4 + count * entrySize` always lands exactly on
        the start of the trailing names blob.

        Returns (entry_size, [bytes, ...]) -- `count` raw entry records,
        each `entry_size` bytes. Returns (0, []) if the dict is empty or
        the expected sub-header doesn't fit (defensive; not expected to
        trigger on any real dict)."""
        sub_off = (self.count + 1) * 4
        if sub_off + 4 > len(self.entries_raw):
            return 0, []
        entry_size, names_offset = struct.unpack_from("<HH", self.entries_raw,
                                                        sub_off)
        data_off = sub_off + 4
        recs = []
        for i in range(self.count):
            recs.append(self.entries_raw[data_off + i * entry_size:
                                          data_off + (i + 1) * entry_size])
        return entry_size, recs


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

TexRecord = collections.namedtuple(
    "TexRecord", "name offset width height format color0 width8 unk8 unk16")
PalRecord = collections.namedtuple("PalRecord", "name offset flag")


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

    def texture_records(self):
        """Decode every texture dict entry via the now-cracked 8-byte
        record (see module docstring 'TEX0 texture/palette dict records,
        CRACKED'): u16 offset (8-byte units, into texel_bytes()), u16
        params (the UPPER 16 bits of the hardware TEXIMAGE_PARAM register:
        bit0/1 repeat S/T, bit2/3 flip S/T, bits4-6 S-Size, bits7-9 T-Size,
        bits10-12 format, bit13 color0-transparent, bits14-15 coord xform),
        u8 width8 (redundant copy of width -- confirmed equal to the
        decoded width in every sample checked, not otherwise used here),
        u8 unk, u16 unk (increases per texture within a dict, plausibly a
        VRAM-slot-ish field; not decoded).

        Returns a list of TexRecord in dict order (parallel to
        tex_dict.names). Raises Nsbmd0Error if the dict's entry size isn't
        the expected 8 bytes (would indicate a still-unseen record
        variant)."""
        entry_size, recs = self.tex_dict.entries()
        if self.tex_dict.count and entry_size != 8:
            raise Nsbmd0Error(
                f"unexpected TEX0 texture entry size {entry_size} "
                f"(expected 8)")
        out = []
        for name, rec in zip(self.tex_dict.names, recs):
            off_u16, params, width8, unk8, unk16 = struct.unpack("<HHBBH", rec)
            w = 8 << ((params >> 4) & 7)
            h = 8 << ((params >> 7) & 7)
            fmt = (params >> 10) & 7
            color0 = (params >> 13) & 1
            out.append(TexRecord(name, off_u16 * 8, w, h, fmt, color0,
                                  width8, unk8, unk16))
        return out

    def palette_records(self):
        """Decode every palette dict entry via the cracked 4-byte record:
        u16 offset (8-byte units, into palette_bytes()), u16 flag (seen
        0x0000 in every sample checked; not decoded)."""
        entry_size, recs = self.pal_dict.entries()
        if self.pal_dict.count and entry_size != 4:
            raise Nsbmd0Error(
                f"unexpected TEX0 palette entry size {entry_size} "
                f"(expected 4)")
        out = []
        for name, rec in zip(self.pal_dict.names, recs):
            off_u16, flag = struct.unpack("<HH", rec)
            out.append(PalRecord(name, off_u16 * 8, flag))
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
# MDL0 model-internal sub-dictionaries (node/material/shape) -- located by
# byte-signature scan, not by cracking the per-model header's own offset
# fields (see docs/ASSETS.md "Map-model mission" section for why: a model's
# leading u32 offset fields don't cleanly resolve to these sub-dicts under
# a single consistent base, so this reader locates them the same
# self-consistency way this project already uses elsewhere -- e.g. the
# LZ77/Huffman sniffs -- instead of guessing a base and risking silent
# corruption).
# ---------------------------------------------------------------------------

def find_resdicts(buf, min_count=1, max_count=200):
    """Scan `buf` for every byte offset whose bytes parse as a *valid*
    ResDict per the confirmed generic layout (this module's `parse_dict`,
    reusing the exact same record-layout crack used for TEX0/palette
    dicts -- 'implement generic dictionary parsing once, use it for TEX0
    ... and MDL0 model/material/polygon dictionaries'): revision==0, a
    plausible entry count, the confirmed `unk4==8` / `unk6==8+(count+1)*4`
    relationship, dict size in bounds, and a trailing names blob that is
    all-printable-ASCII per name. This signature is specific enough in
    practice to find MDL0's node/material/shape dicts directly inside a
    model's raw (undivided) data without needing to crack the model
    header's own offset fields first.

    Returns a list of (offset, ResDict), in ascending offset order."""
    hits = []
    n = len(buf)
    off = 0
    while off + 8 <= n:
        try:
            rev, count, size, unk4, unk6 = struct.unpack_from("<BBHHH", buf, off)
        except struct.error:
            break
        if (rev == 0 and min_count <= count <= max_count and unk4 == 8 and
                unk6 == 8 + (count + 1) * 4 and off + size <= n):
            try:
                rd = parse_dict(buf, off)
            except Nsbmd0Error:
                rd = None
            if rd is not None and all(
                    nm and all(32 <= ord(ch) < 127 for ch in nm)
                    for nm in rd.names):
                hits.append((off, rd))
                off += max(size, 8)
                continue
        off += 4  # dict headers only ever seen 4-byte aligned in practice
    return hits


def find_render_commands(buf, min_pairs=8):
    """Locate and decode a G3D 'render command list' run inside `buf`: a
    scan (public hardware/format-agnostic technique, not project-specific
    knowledge) for the longest run of byte pairs `(id, opcode)` where
    opcode is either 4 (confirmed empirically to mean BINDMATERIAL id) or 5
    (DRAWSHAPE id, draws the given shape using the most recently bound
    material) -- confirmed against a real sample (`pl_00_00`) where this
    decodes to a clean bijection between all 40 declared shape indices and
    40 declared material indices, an outcome far too structured to be
    coincidental alignment on random bytes.

    Returns (start_offset, {shape_id: material_id}) for the best run found
    (by pair count), or (None, {}) if no run of at least `min_pairs` pairs
    exists anywhere in `buf`."""
    n = len(buf)
    best = (None, {}, 0)
    i = 0
    while i + 1 < n:
        j = i
        shape_to_mat = {}
        cur_mat = None
        pairs = 0
        while j + 1 < n:
            v, op = buf[j], buf[j + 1]
            if op == 4:
                cur_mat = v
            elif op == 5:
                shape_to_mat[v] = cur_mat
            else:
                break
            pairs += 1
            j += 2
        if pairs > best[2]:
            best = (i, dict(shape_to_mat), pairs)
        i = j if pairs else i + 1
    if best[2] < min_pairs:
        return None, {}
    return best[0], best[1]


# ---------------------------------------------------------------------------
# MDL0 shape dictionary -- per-shape display-list ranges (CRACKED this pass)
#
# The shape ResDict's own `entries()` records (4 bytes each, confirmed by
# the same "sub-header offset must exactly match" arithmetic ResDict.entries
# uses everywhere else) are NOT display-list offsets themselves. Each is a
# u32 byte offset, relative to the shape dict's OWN start offset (i.e. add
# it straight to the dict's own file/buffer position), to a fixed 16-byte
# per-shape descriptor:
#
#     u16  itemTag    seen 0 in every sample
#     u16  size       seen 0x10 (== the descriptor's own size) in every
#                      sample -- a self-describing record-length field, not
#                      a shape byte count
#     u32  flag       seen only 5 or 7 across pl_00_00's 40 shapes; meaning
#                      not decoded (not needed for geometry/UV export)
#     u32  dlOffset   byte offset of this shape's own GX command range,
#                      relative to a DIFFERENT base: shape_dict_offset +
#                      shape_dict.size (the first byte after the shape
#                      dict's own on-disk bytes -- NOT the same base the
#                      descriptor pointers above use)
#     u32  dlSize     byte length of this shape's GX command range
#
# Confirmed against `pl_00_00` (40 shapes): the descriptor array itself
# occupies the first `40*16` bytes at that second base, and shape 0's
# dlOffset (0x280) lands exactly at the descriptor array's own end -- i.e.
# the descriptor table and the merged GX command data are back-to-back in
# one contiguous "shape data" section starting right after the shape dict,
# with descriptors addressed from the shape dict's own start but DL ranges
# addressed from the end of the shape dict (start of that "shape data"
# section). sum(dlSize) over all shapes equals the merged GX stream's
# total byte length exactly (0xE9EC for pl_00_00, matching the heuristic
# find_gx_stream()-based whole-model decode's end offset exactly).
#
# **Known imperfection, honestly documented, not silently papered over:**
# each shape's own byte range, decoded from dlOffset literally, does NOT
# start with a valid GX command word -- there is a small (0-20 byte,
# variable per shape) non-GX preamble before the real command stream
# begins, most likely a hardware/tool-internal sub-header this pass did
# not identify. Skipping it needs the SAME heuristic already used to
# locate the merged model's overall GX stream (find_gx_stream), just
# re-applied inside each shape's own bounded dlOffset/dlSize range instead
# of over the whole model. This recovers the large majority of each
# shape's real geometry (5070/5114 vertices, 1323/1774 faces for
# pl_00_00 -- 99% / 75%): a handful of shapes lose their very last
# END_VTXS-terminated batch when that command falls inside the last few
# (<=24) bytes of the shape's declared dlSize, which this pass could not
# resolve further within budget (see docs/ASSETS.md for the investigation
# that ruled out several alternative byte-tiling hypotheses).
# ---------------------------------------------------------------------------

SHAPE_DESC_STRUCT = struct.Struct("<HHIII")  # itemTag, size, flag, dlOffset, dlSize


def find_shape_dict(buf, dicts=None):
    """Identify, among the ResDicts `find_resdicts` locates in `buf`, the
    one that is a shape (polygon) dict: the dict whose entries() u32 values,
    added to (dict_offset + dict.size), land on a run of plausible 16-byte
    descriptors (itemTag==0, size==0x10, dlOffset/dlSize in bounds). This is
    a structural test, not a name-based guess, so it works even when a
    model's shape names don't follow the `polygon0`.. convention this
    project has seen so far.

    Returns (offset, ResDict) or None."""
    if dicts is None:
        dicts = find_resdicts(buf)
    best = None
    for off, rd in dicts:
        if rd.count == 0:
            continue
        entry_size, recs = rd.entries()
        if entry_size != 4:
            continue
        dl_base = off + rd.size
        ok = 0
        for rec in recs:
            v = struct.unpack("<I", rec)[0]
            addr = off + v  # descriptors are addressed from the dict's OWN start
            if addr + 16 > len(buf):
                continue
            itemTag, size, flag, dlOffset, dlSize = SHAPE_DESC_STRUCT.unpack_from(buf, addr)
            if itemTag == 0 and size == 0x10 and dl_base + dlOffset + dlSize <= len(buf):
                ok += 1
        if ok == rd.count and (best is None or rd.count > best[1].count):
            best = (off, rd)
    return best


def shape_descriptors(buf, shape_off, shape_rd):
    """Decode every shape's 16-byte descriptor (see module docstring above
    `find_shape_dict`). Returns (dl_base, [(itemTag, size, flag, dlOffset,
    dlSize), ...]) in shape-dict order (shape index order). `dl_base` is
    the base to add to each record's own `dlOffset` field (NOT the same
    base used to locate the descriptors themselves, which is `shape_off`
    directly -- see module docstring)."""
    dl_base = shape_off + shape_rd.size
    _, recs = shape_rd.entries()
    out = []
    for rec in recs:
        v = struct.unpack("<I", rec)[0]
        addr = shape_off + v
        out.append(SHAPE_DESC_STRUCT.unpack_from(buf, addr))
    return dl_base, out


def decode_shape_dl(buf, base, dlOffset, dlSize, min_commands=4, tail_slack=384):
    """Decode one shape's own GX command range. The small non-GX preamble
    before the real command stream (see the 'Known imperfection' note
    above `find_shape_dict`) is skipped via a local find_gx_stream scan
    bounded to this shape's own declared dlSize; decoding then continues
    from `buf` directly (not a hard-sliced copy) using `gx_decode`'s
    `soft_limit`/`hard_limit`, because the declared dlSize boundary was
    also found to sometimes end a handful of bytes BEFORE the shape's own
    last END_VTXS actually closes -- soft_limit lets decoding finish that
    one open batch rather than silently dropping it, while hard_limit
    (dlSize + `tail_slack`, capped at the buffer end) guarantees decoding
    can never run away into unrelated shapes if a batch never closes at
    all (e.g. a truncated/corrupt range).

    Returns (verts, uvs, faces) local to this shape (vertex indices start
    at 0), or (None, None, None) if no valid run is found at all."""
    seg = buf[base + dlOffset: base + dlOffset + dlSize]
    found = find_gx_stream(seg, min_commands=min_commands)
    if found is None:
        return None, None, None
    local_start, _ = found
    abs_start = base + dlOffset + local_start
    soft_limit = base + dlOffset + dlSize
    hard_limit = min(len(buf), soft_limit + tail_slack)
    verts, uvs, faces, cmds, end = gx_decode(buf, abs_start, soft_limit, hard_limit)
    return verts, uvs, faces


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


# Every Nitro "G3D" resource (model, texture, and the three animation kinds
# paired with a model -- joint/material SRT/texture-pattern) shares this same
# outer container shape (see module docstring "Container layout"); only
# BMD0/BTX0's own blocks (MDL0/TEX0) are decoded field-by-field below. The
# other three are round-tripped the same way this module already round-trips
# any *unrecognised* block inside a BMD0/BTX0 (kept as an opaque raw byte
# range, see the `else` branch below) -- this project has not decoded their
# block contents, so they are not listed in docs/ASSETS.md as more than
# container-level verified.
G3D_MAGICS = (b"BMD0", b"BTX0", b"BCA0", b"BTA0", b"BTP0", b"BMA0")


def parse_container(data):
    magic, bom, version, file_size, header_size, nblk = \
        struct.unpack_from("<4sHHIHH", data, 0)
    if magic not in G3D_MAGICS:
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
    5: "4x4-compressed", 6: "A5I3", 7: "direct",
}


def _blend(c0, c1, w0, w1):
    r = (c0[0] * w0 + c1[0] * w1) // (w0 + w1)
    g = (c0[1] * w0 + c1[1] * w1) // (w0 + w1)
    b = (c0[2] * w0 + c1[2] * w1) // (w0 + w1)
    return (r, g, b)


def decode_texture_4x4(width, height, region, palette):
    """Decode a GX format-5 (4x4-compressed) texture.

    Per the public DS GPU "Compressed Texel (4x4 Texel)" documentation: the
    texture is stored as one 32-bit word per 4x4 texel block (16 texels,
    2 bits each -- a local index 0..3), immediately followed in the SAME
    texture-data region by one 16-bit "index" word per block (bits 0-13 =
    palette address, in halfwords, bits 14-15 = interpolation mode). This
    reader treats `region` as exactly `texel_words || index_words` back to
    back (texel_words = num_blocks*4 bytes, index_words = num_blocks*2
    bytes -- a fixed 2:1 ratio, since each block always carries 4 bytes of
    texel data and 2 bytes of index data regardless of image size), which
    is what the mission brief's header re-reading confirmed: the region
    bounded by the ordinary texel-data-offset/palette-offset header fields
    holds both sub-blocks concatenated, not texel data alone.

    Per-block palette lookup (col0, col1 = palette[addr], palette[addr+1],
    both scaled by the block's own addr*2 halfword address into the
    attached palette):
        mode 0: col0, col1, blend(col0,col1,5,3), blend(col0,col1,3,5)
        mode 1: col0, col1, blend(col0,col1,1,1), transparent
        mode 2: col0, col1, palette[addr+2], palette[addr+3]
        mode 3: col0, col1, blend(col0,col1,5,3), transparent
    """
    bw, bh = width // 4, height // 4
    num_blocks = bw * bh
    texel_size = num_blocks * 4
    index_size = num_blocks * 2
    if len(region) < texel_size + index_size:
        raise Nsbmd0Error("4x4 region too small for texel+index tables")
    texel = region[:texel_size]
    index = region[texel_size:texel_size + index_size]
    out = bytearray(width * height * 4)
    valid = 0
    total = 0
    for by in range(bh):
        for bx in range(bw):
            bidx = by * bw + bx
            word = struct.unpack_from("<I", texel, bidx * 4)[0]
            idxword = struct.unpack_from("<H", index, bidx * 2)[0]
            addr = idxword & 0x3FFF
            mode = (idxword >> 14) & 3
            base = addr * 2

            def col(i):
                nonlocal valid, total
                total += 1
                if base + i < len(palette):
                    valid += 1
                    return palette[base + i]
                return (255, 0, 255)

            c0, c1 = col(0), col(1)
            if mode == 0:
                c2, c3 = _blend(c0, c1, 5, 3), _blend(c0, c1, 3, 5)
                alphas = (255, 255, 255, 255)
            elif mode == 1:
                c2, c3 = _blend(c0, c1, 1, 1), (0, 0, 0)
                alphas = (255, 255, 255, 0)
            elif mode == 2:
                c2, c3 = col(2), col(3)
                alphas = (255, 255, 255, 255)
            else:
                c2, c3 = _blend(c0, c1, 5, 3), (0, 0, 0)
                alphas = (255, 255, 255, 0)
            colors = (c0, c1, c2, c3)
            for ty in range(4):
                py = by * 4 + ty
                if py >= height:
                    continue
                for tx in range(4):
                    px = bx * 4 + tx
                    if px >= width:
                        continue
                    bits2 = (word >> ((ty * 4 + tx) * 2)) & 3
                    r, g, b = colors[bits2]
                    o = (py * width + px) * 4
                    out[o:o + 4] = bytes((r, g, b, alphas[bits2]))
    return bytes(out), (valid / total if total else 0.0)


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
    # Format 5 (4x4-compressed) doesn't fit the simple bits-per-pixel
    # model above: its byte count is (w/4)*(h/4)*6 (4 bytes texel + 2
    # bytes index per 4x4 block, texel and index concatenated in the same
    # region -- see decode_texture_4x4's docstring). Widths/heights must be
    # multiples of 4 (the block size).
    for w in SIZE_CLASSES:
        for h in SIZE_CLASSES:
            if w % 4 or h % 4:
                continue
            if (w // 4) * (h // 4) * 6 == size:
                candidates.append((5, w, h))
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
        if fmt == 5:
            _, ratio = decode_texture_4x4(w, h, texel, palette)
            # format 5's per-block palette address ranges over the whole
            # attached palette by design (not a fixed 2**bpp index range),
            # so there's no meaningful palette_fit penalty to apply here.
            palette_fit = 0
        else:
            _, ratio = decode_texture(fmt, w, h, texel, palette)
            if fmt == 7:
                palette_fit = 10 ** 9  # worst possible fit unless it's the only option
            else:
                palette_fit = abs(index_range[fmt] - len(palette))
        scored.append((ratio, -palette_fit, -abs(w - h), fmt, w, h))
    scored.sort(reverse=True)
    ratio, _, _, fmt, w, h = scored[0]
    return fmt, w, h, ratio


def texture_byte_size(fmt, w, h):
    """Byte size of one texture's texel data for the given (format, width,
    height), per the confirmed TEXIMAGE_PARAM-derived bits-per-pixel table
    (FORMAT_BITS_PER_PIXEL) plus format 5's special 4x4-block-pair rule
    (see decode_texture_4x4's docstring)."""
    if fmt == 5:
        return (w // 4) * (h // 4) * 6
    return w * h * FORMAT_BITS_PER_PIXEL[fmt] // 8


def decode_all_textures(tex0):
    """Decode EVERY texture in a TEX0 block (single- or multi-texture),
    now that the dict record layout is cracked (Tex0.texture_records()):
    each texture's exact (offset, format, width, height) is read directly
    from its own dict entry -- no brute-force size search needed, and no
    longer limited to the single-texture case guess_single_texture() was
    restricted to.

    Palette pairing: nothing in the texture record itself names which
    palette dict entry it uses (a real material, not decoded by this
    module -- see MDL0 notes -- owns that link in the actual format). Two
    strategies, tried in order:
      1. **Name convention (confirmed, preferred when present):** many
         dicts pair texture `foo` with a palette literally named `foo_pl`
         (confirmed exactly 1:1 in `a/0/1/4`'s 67-texture/67-palette
         shared sets). When that exact name exists in pal_dict, use it --
         this is a real link, not a guess.
      2. **Self-consistency scoring (fallback):** for dicts without that
         naming convention (e.g. multi-texture TEX0 blocks with fewer
         palettes than textures), pick whichever palette dict entry scores
         best by the same heuristic used elsewhere in this module
         (fraction of decoded indices in range, tie-broken by how closely
         the format's index range matches the palette's color count) --
         genuinely validated per candidate, not a blind guess, but still a
         best-effort substitute for a real material link when no naming
         convention disambiguates it.

    Returns a list of (TexRecord, chosen_palette_name, rgba_bytes,
    valid_ratio)."""
    texel_region = tex0.texel_bytes()
    tex_records = tex0.texture_records()
    pal_records = tex0.palette_records()
    pal_region = tex0.palette_bytes()
    index_range = {1: 32, 2: 4, 3: 16, 4: 256, 6: 8}
    pal_offset_by_name = {p.name: p.offset for p in pal_records}

    def load_palette(offset, fmt):
        # Palette byte size isn't stored directly in the dict record
        # either; rather than guess it from the gap to some OTHER
        # palette's offset (unreliable -- several real dicts have two
        # differently-named entries sharing the exact same offset, which
        # breaks any "next distinct offset" boundary guess), size it
        # directly from how many colors the REQUESTING texture's own
        # format can index (2**bpp, the same index_range table used
        # elsewhere in this module) -- simple, and correct by
        # construction for the format actually doing the indexing.
        needed = index_range.get(fmt, 256) * 2
        return decode_palette(pal_region[offset:offset + needed])

    # For the no-name-match fallback below: candidate palettes, each sized
    # for ITS OWN typical use (index_range for a plausible-count guess
    # isn't meaningful without a texture in hand, so just decode a
    # generously-sized slice -- up to 256 colors -- for scoring purposes).
    palettes = [(p.name, load_palette(p.offset, 4)) for p in pal_records]
    if not palettes:
        palettes = [(None, [])]
    out = []
    for tr in tex_records:
        size = texture_byte_size(tr.format, tr.width, tr.height)
        texel = texel_region[tr.offset:tr.offset + size]
        if tr.format == 7:
            rgba, ratio = decode_texture(7, tr.width, tr.height, texel, [])
            out.append((tr, None, rgba, ratio))
            continue
        named = tr.name + "_pl"
        if named in pal_offset_by_name:
            pal_colors = load_palette(pal_offset_by_name[named], tr.format)
            rgba, ratio = decode_texture(tr.format, tr.width, tr.height,
                                          texel, pal_colors)
            out.append((tr, named, rgba, ratio))
            continue
        best = None
        for pal_name, pal_colors in palettes:
            if tr.format == 5:
                try:
                    rgba, ratio = decode_texture_4x4(tr.width, tr.height,
                                                       texel, pal_colors)
                except Nsbmd0Error:
                    continue
                fit = 0
            else:
                rgba, ratio = decode_texture(tr.format, tr.width, tr.height,
                                              texel, pal_colors)
                fit = abs(index_range.get(tr.format, 0) - len(pal_colors))
            score = (ratio, -fit)
            if best is None or score > best[0]:
                best = (score, pal_name, rgba, ratio)
        out.append((tr, best[1], best[2], best[3]))
    return out


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


def _s10(u10):
    return u10 - 0x400 if u10 & 0x200 else u10


def gx_decode(data, start, soft_limit=None, hard_limit=None):
    """Decode a GX command stream starting at byte offset `start` in
    `data`. Returns (vertices, uvs, faces, num_commands, end_offset).

    `soft_limit`/`hard_limit` (both optional, absolute byte offsets into
    `data`) support per-shape decoding against the MDL0 shape dictionary's
    dlOffset/dlSize range (see nsbmd.py's "MDL0 shape dictionary" section
    and tools/assets/map_shapes.py): real per-shape ranges were found to
    sometimes end a handful of bytes BEFORE their own last BEGIN_VTXS/
    END_VTXS pair actually closes (the true END_VTXS spills a few bytes
    into the next shape's declared range). Decoding would otherwise either
    stop early (losing that shape's last face batch) or -- if simply
    given a longer buffer -- run on into the next shape(s) indefinitely,
    since the small non-GX bytes between shapes are not reliably a decode-
    stopping invalid opcode. `soft_limit` says "stop here once no batch is
    currently open" (i.e. finish the strip/fan you're in, then stop);
    `hard_limit` is an absolute safety cap that always stops decoding
    (even mid-batch) so a missing END_VTXS can never run away into
    unrelated data. Both default to None (no limit -- unchanged behaviour
    for every pre-existing caller, e.g. the merged whole-model decode).

    vertices/uvs are parallel lists (one uv per vertex, the last TEXCOORD
    seen before each vertex-emitting command). faces is a list of
    vertex-index lists (triangles or quads, already fanned out of strips).

    Vertex commands, per the documented GX hardware opcode table: a
    "current position" register (cx, cy, cz) persists across commands.
    VTX_16 and VTX_10 set all three components outright; VTX_XY/VTX_XZ/
    VTX_YZ set two of the three and carry the third over from whatever it
    last was; VTX_DIFF adds a small signed delta to the current position.
    Every one of these five commands, not just VTX_16, emits a new vertex
    using the resulting (cx, cy, cz). This matters in practice: real
    terrain/building models in this ROM overwhelmingly use the compact
    VTX_10/VTX_XY/VTX_XZ/VTX_YZ encodings rather than VTX_16 (confirmed by
    opcode-frequency counts on sampled map models), so a decoder that only
    understood VTX_16 would silently emit almost no geometry for them."""
    p = start
    n = len(data)
    verts = []
    uvs = []
    faces = []
    cur_uv = (0.0, 0.0)
    cur_batch = []
    cur_mode = None
    batch_open = False  # True between a BEGIN_VTXS and its matching END_VTXS
    cmds = 0
    cx = cy = cz = 0.0

    def emit():
        verts.append((cx, cy, cz))
        uvs.append(cur_uv)
        cur_batch.append(len(verts) - 1)

    while p + 4 <= n:
        if hard_limit is not None and p >= hard_limit:
            break
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
                cx = _s16(params[0] & 0xFFFF) / 4096.0
                cy = _s16((params[0] >> 16) & 0xFFFF) / 4096.0
                cz = _s16(params[1] & 0xFFFF) / 4096.0
                emit()
            elif op == 0x24:  # VTX_10: 3x s1.3.6 fixed-point, 10 bits each
                v = params[0]
                cx = _s10(v & 0x3FF) / 64.0
                cy = _s10((v >> 10) & 0x3FF) / 64.0
                cz = _s10((v >> 20) & 0x3FF) / 64.0
                emit()
            elif op == 0x25:  # VTX_XY: s16.12 (x, y); z carried over
                cx = _s16(params[0] & 0xFFFF) / 4096.0
                cy = _s16((params[0] >> 16) & 0xFFFF) / 4096.0
                emit()
            elif op == 0x26:  # VTX_XZ: s16.12 (x, z); y carried over
                cx = _s16(params[0] & 0xFFFF) / 4096.0
                cz = _s16((params[0] >> 16) & 0xFFFF) / 4096.0
                emit()
            elif op == 0x27:  # VTX_YZ: s16.12 (y, z); x carried over
                cy = _s16(params[0] & 0xFFFF) / 4096.0
                cz = _s16((params[0] >> 16) & 0xFFFF) / 4096.0
                emit()
            elif op == 0x28:  # VTX_DIFF: 3x s10 relative, in the vertex's 4.12 units (+-1/8)
                v = params[0]
                cx += _s10(v & 0x3FF) / 4096.0
                cy += _s10((v >> 10) & 0x3FF) / 4096.0
                cz += _s10((v >> 20) & 0x3FF) / 4096.0
                emit()
            elif op == 0x40:  # BEGIN_VTXS
                cur_mode = params[0] & 0x3
                cur_batch = []
                batch_open = True
            elif op == 0x41:  # END_VTXS
                batch_open = False
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
        if soft_limit is not None and p >= soft_limit and not batch_open:
            break
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
    palette = decode_palette(tex0.palette_bytes())
    if fmt == 5:
        rgba, _ = decode_texture_4x4(w, h, tex0.texel_bytes(), palette)
    else:
        rgba, _ = decode_texture(fmt, w, h, tex0.texel_bytes(), palette)
    write_png_rgba8(args.output, w, h, rgba)
    print(f"[*] wrote {args.output} ({w}x{h})")
    return 0


def cmd_textures(args):
    with open(args.input, "rb") as fh:
        data = fh.read()
    c = parse_container(data)
    tex0 = find_tex0(c)
    if tex0 is None:
        print("error: no TEX0 block in this file", file=sys.stderr)
        return 2
    os.makedirs(args.output, exist_ok=True)
    results = decode_all_textures(tex0)
    for tr, pal_name, rgba, ratio in results:
        safe = "".join(ch if ch.isalnum() or ch in "._-" else "_"
                        for ch in tr.name)
        path = os.path.join(args.output, f"{safe}.png")
        write_png_rgba8(path, tr.width, tr.height, rgba)
        print(f"[*] {tr.name}: format={FORMAT_NAMES[tr.format]} ({tr.format}) "
              f"{tr.width}x{tr.height} palette={pal_name} "
              f"valid={ratio:.3f} -> {path}")
    print(f"[*] {len(results)} texture(s) decoded from {tex0.tex_dict.count}"
          f" in dict")
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

    p = sub.add_parser("textures", help="decode every texture in a TEX0 "
                        "block (single or multi) to PNGs in a directory")
    p.add_argument("input")
    p.add_argument("-o", "--output", required=True)
    p.set_defaults(func=cmd_textures)

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
