#!/usr/bin/env python3
"""
rig.py -- compose one posed frame from the `a/0/0/4` multi-cell rig archive.

Written from scratch for the aletheia project. Stdlib only, single file.

--------------------------------------------------------------------------
Mission
--------------------------------------------------------------------------
`a/0/0/4` (and its sibling `a/0/5/2`) stores, per species/form index N, a
20-sub-file block (`species*20 .. species*20+19`, see docs/ASSETS.md
"`a/0/0/4` block entries 0-17"). Local entries 0-8 are one complete,
self-contained Nitro 2D "poseable multi-part sprite" bundle:

    local 0/1  RGCN/NCGR   small tile sheet (duplicated, two LZ11 streams)
    local 2/3  RGCN/NCGR   main tile sheet  (duplicated, two LZ11 streams)
    local 4    RECN/NCER   cell bank: 11 cells / 17 OAMs, body-part cells
    local 5    RNAN/NANR   cell animation: per-part sequences, and
                           the only thing that says which cell a node draws
    local 6    RCMN/NMCR   multi-cell resource: rest-pose node placement
    local 7    RAMN/NMAR   multi-cell animation: per-animation transform
    local 8    (unknown, not decoded)

local 9-17 is a second, near-identical bundle (front/back or a variant),
local 18/19 are the normal/shiny NCLR palettes (`battle_sprite.py`'s
PALETTE_STRIDE/OFFSET constants).

This module parses NCGR (local 2, the main sheet), NCER (local 4, the cell
bank) and NMCR (local 6, the rest-pose node table) well enough to compose a
single assembled frame: one rendering per named body part (head, ears,
tail, arms, legs...), placed at the (x, y) offset the NMCR node table gives
it, using the tile data straight out of the block's own NCGR (NOT
`a/1/3/4` -- the fifth lane pass ruled that pairing out, see docs/ASSETS.md).

--------------------------------------------------------------------------
NCER (RECN) format -- generic NDS OAM cell bank, parsed here for the first
time as committed code (previously only characterised ad hoc)
--------------------------------------------------------------------------
16-byte common file header (magic/BOM/version/filesize/headersize/nblocks,
same shape as every other Nitro resource in this project), then an ordered
sequence of blocks (`nblocks` of them). The first block is always `KBEC`
(on-disk reversal of "CEBK", Cell Bank): a 16-byte sub-header,
NOT self-relative (offsets in it are relative to the KBEC block's own data
start, unlike NMCR/NMAR below):

    0x00  u16  num_cells
    0x02  u16  cell_info_type   (0 seen here; presumably selects the
                                  8-byte "simple" cell record used below vs.
                                  a 16-byte "extended" one with a bounding
                                  box, per the public NNS_G2D CEBK shape --
                                  not exercised, every cell here is simple)
    0x04  u32  cell_data_ofs    byte offset (from KBEC data start) to the
                                 cell array
    0x08  u32  mapping_type     OBJ character mapping mode (4 = 1D, 256B
                                 boundary per the NNS_G2D enum -- see the
                                 tile-addressing note below, which found
                                 this declared boundary is NOT what the
                                 pixels actually use)
    0x0C  u32  reserved

Cell array: `num_cells` entries of 8 bytes each (`num_oam(u16),
cell_attr(u16), oam_ofs(u32)`), `oam_ofs` a byte offset relative to the
start of the OAM array (immediately following the cell array). Confirmed
against species 25's local-4 NCER: 11 cells, `oam_ofs` values increase in
exact lockstep with the running `num_oam` total (cell 1 starts at
5*6=30 after cell 0's 5 OAMs, etc.) -- this pins the addressing precisely,
not a guess.

OAM array: standard GBA/NDS OAM attr0/attr1/attr2 triples, 6 bytes each
(3x u16, public well-known bitfield layout, no project-specific magic):

    attr0: bits0-7 y (s8), bits8-9 rot/scale+disable, bits10-11 obj mode,
           bits12-13 mosaic/color depth, bits14-15 shape
    attr1: bits0-8 x (s9), bits9-13 rotscale-param OR (bit12 hflip,
           bit13 vflip) when rotscale is off, bits14-15 size
    attr2: bits0-9 tile_idx, bits10-11 priority, bits12-15 palette

shape/size selects a pixel block size from the standard OBJ table:
square 8/16/32/64, wide 16x8/32x8/32x16/64x32, tall 8x16/8x32/16x32/32x64.

**Tile addressing: two-dimensional, over a linear (bitmap-format) sheet.**
This is the twelfth lane pass's correction and it is what finally made the
pose readable; every earlier pass read the OAM tile index as a dense
`tile_idx * 32` byte offset into an 8x8-tiled sheet, which is wrong twice
over. See the NCGR notes in `Ncgr`'s own docstring for the pixel storage
half; the addressing half is: an OAM's `tile_idx` is a block index into the
sheet's `tile_num_x`-wide grid of 8x8 blocks, so block `i` sits at column
`i % tile_num_x`, row `i // tile_num_x`, and an OAM taller than one block
steps by `tile_num_x` per block row rather than by its own width. Species
25's cell 0 proves it from the data alone: a 16x16 OAM at index 99 is
immediately followed by an 8x16 OAM at index 101, which can only avoid
overlapping if the first consumes blocks 99/100 and 131/132 (two rows of a
32-wide sheet) rather than the four consecutive blocks 99..102.

The cell array / OAM array split is separately pinned by the game's own
code: `func_020627F0` returns the address one past the last cell record
(8 bytes per cell, or 16 when the bank attribute's bit0 is set) and
`func_02062884` adds exactly that to every cell's own offset field, so a
cell's OAM offset is relative to the end of the cell array. That is what
this module already did, now confirmed rather than inferred.

--------------------------------------------------------------------------
NMCR (RCMN) format -- multi-cell resource: node placement
--------------------------------------------------------------------------
16-byte common file header, one block, magic `KBCM` (on-disk reversal of
"MCBK", Multi-Cell Bank). The bank header's offset fields are **plain byte
offsets from the block body's start**, not self-relative: `func_0206296C`
(docs/notes/func_0206296C.c.txt) adds the body address itself into them.

    0x00  u16  numMultiCell     2 for species 25 (two alternate assemblies)
    0x02  u16  signature        0xBEEF constant
    0x04  u32  mcArrayOfs       -> multi-cell descriptor array, 8 bytes each
    0x08  u32  nodeArrayBase    base the descriptors' node offsets are
                                 relative to
    0x0C  u32  reserved (0)
    0x10  u32  animBankOfs      embedded cell-animation bank body, or 0
                                 (0 here; the paired local-5 NANR is used)
    0x14  u16  unk / 0x16  u16  unk (both 10 for species 25)

    descriptor (8 bytes; the stride is what func_020629E8's `lsl #3` proves)
        0x00  u16  numNodes
        0x02  u16  numCellAnims   sizes the caller's cell-animation state
                                   array (func_02064648)
        0x04  u32  nodeArrayOffset, relative to nodeArrayBase

For species 25 the two descriptors read (numNodes=10, offset=0) and
(numNodes=10, offset=80) -- 80 == 10 * 8 -- so the two groups' node spans
are back-to-back and consume the body exactly. The node record itself is
documented below, under the section confirming it against func_020643CC.

--------------------------------------------------------------------------
NMAR (RAMN) format -- multi-cell animation: what was recovered
--------------------------------------------------------------------------
16-byte common file header, TWO blocks: `KNBA` (on-disk reversal of "ANBK",
Animation Node Bank) then `LBAL` (a single animation name -- "CellAnime0"
for species 25's local-7 NMAR, i.e. exactly one animation defined).

ANBK body (block-relative, not self-relative -- offsets 24/40/56 for
species 25 fit cleanly inside its 60-byte body, whereas self-relative
targets for the same fields would run past the end):

    0x00  u16  num_anim         1
    0x02  u16  element_type     2 (unconfirmed meaning; NNS_G2D
                                 conventionally distinguishes animation
                                 element shapes, e.g. translate-only vs.
                                 translate+rotate+scale -- not pinned down)
    0x04  u32  table_a_ofs      block-relative -> 16-byte region; decodes
                                 as small integers (2, 2, 2), not resolved
    0x08  u32  table_b_ofs      block-relative -> 16-byte region containing
                                 two (value, 0xBEEF) sentinel-tagged
                                 sub-records (values 0xA2=162, 0xBA=186 --
                                 plausibly per-frame or per-key byte
                                 offsets into a table beyond this block,
                                 but the file is only 107 bytes total so
                                 those offsets don't resolve inside NMAR
                                 itself; not chased further)
    0x0C  u32  table_c_ofs      block-relative -> 4-byte region, value
                                 (1, 0) -- plausibly a frame/key count of 1

**Not resolved this pass**: the actual per-frame transform values (if any
beyond the identity) that "CellAnime0" applies on top of NMCR's rest pose.
Given only one animation and (per table_c) a frame/key count that reads as
1, this tool assumes frame 0 of animation 0 IS the NMCR rest pose with no
additional transform -- a reasonable but unverified simplification flagged
here rather than silently assumed.

--------------------------------------------------------------------------
NANR (RNAN) format, corrected again -- the sequence record's real fields
(twelfth lane pass; supersedes the eighth pass's "elem_start index" reading,
which was the reason every node resolved to the same cell)
--------------------------------------------------------------------------
The eighth pass had the frame-entry / frame-data indirection right but the
**sequence record wrong**, and read frames out of the shared frame-entry
array at the wrong place. The game's own `KNBA` (ABNK) fixup routine at
0x02062688 states the whole layout unambiguously -- it walks the structure
adding base addresses to exactly the fields that are offsets, so the field
positions and the base each offset is relative to are both directly
observable, no guessing:

    bank (ABNK block body)
        0x00  u16  numSequences
        0x02  u16  numTotalFrames
        0x04  u32  offset -> sequence array   (relative to the body)
        0x08  u32  offset -> frame-entry array (relative to the body)
        0x0C  u32  offset -> frame-data pool   (relative to the body)
        0x14  u32  offset -> an embedded sub-resource, or 0

    sequence record, 16 bytes (stride pinned by func_020627D8's `lsl #4`,
    filed EXACT as src/matched/func_020627D8.c)
        0x00  u16  numFrames
        0x02  u16  loopStartFrameIdx
        0x04  u32  animType   low byte 0/1/2: see the frame-data shapes
        0x08  u32  playMode
        0x0C  u32  offset -> this sequence's own run of frame entries,
                    **relative to the bank's 0x08 frame-entry array**

    frame entry, 8 bytes
        0x00  u32  offset -> frame data, relative to the bank's 0x0C pool
        0x04  u16  duration (in frames)
        0x06  u16  0xBEEF sentinel

The fixup loop is the proof: it adds `bank->frameArray` into each sequence's
+0x0C field, then walks that sequence's own `numFrames` entries adding
`bank->frameDataPool` into each entry's first word. So a sequence's frames
are `frameArray[seq.frames_ofs/8 .. +numFrames)`, a contiguous run, and the
frame-entry array is partitioned among the sequences in order.

Species 25's bytes fit this exactly and nothing else: the 20 sequences'
`frames_ofs` values run 0, 144, 392, 536, ... 3216, each exactly the running
sum of the preceding `numFrames * 8`, and the last sequence's single frame
lands on entry 402 of 403 == `numTotalFrames`. A clean partition with zero
leftover entries.

**What the eighth pass read instead**: it took the u32 at +0x00 as a start
*index* into the frame-entry array and the u16 at +0x04 as `numFrames`. The
u32 at +0x00 is really `numFrames | loopStart << 16` and the u16 at +0x04 is
really `animType`'s low half, constant 1 or 2 here -- so every sequence
looked one frame long and every lookup landed on entry `numFrames` of the
shared array instead of on the sequence's own first frame. That is the whole
explanation for the eleventh pass's "7 of 8 nodes resolve to the same NCER
cell": those lookups were reading a near-arbitrary common region. With the
corrected walk, species 25's ten rest-pose nodes resolve to ten *distinct*
cells (6, 5, 10, 0, 3, 2, 1, 4, 7, 8 of 11).

**Frame-data record shapes**, selected by `animType & 0xFF` -- the mask is
the renderer's own, `func_0206419C` loads the sequence's +0x04 word and
masks it with 0xFF before the three-way branch:

    0  index     {u16 cellIdx}                       cell only
    1  SRT       {u16 cellIdx, u16 rotZ, s32 sx,     cell + full transform
                  s32 sy, s16 px, s16 py}            (16 bytes)
    2  T         {u16 cellIdx, u16 pad,              cell + translation
                  s16 px, s16 py}                    (8 bytes)

confirmed field by field against `func_0206419C`: it reads px/py at +4/+6 for
type 2 and at +0x0C/+0x0E for type 1, and for type 1 also feeds +0x04/+0x08
(sx, sy) and +0x02 (rotZ) to the matrix builders. The eighth pass's "sx/sy
read 4096 == FX32 1.0" observation stands and is why this module ignores the
transform for frame 0. All three shapes occur in this archive, so decoding by
element type (not always trying the 16-byte one) matters: species 25 uses
type 1 for most parts, type 2 for the head, type 0 for the feet.

--------------------------------------------------------------------------
NMCR (RCMN) multi-cell resource -- confirmed against the game's own walk
--------------------------------------------------------------------------
The eleventh pass's byte-level reading of the bank header, the 8-byte
descriptor and the 8-byte node record is **confirmed unchanged** by the two
routines that consume them:

  * `func_0206296C` (see docs/notes/func_0206296C.c.txt) fixes up the bank's
    +0x04 descriptor-array offset and +0x08 node-array base relative to the
    block body, then adds that base into each descriptor's own +0x04 offset.
    So descriptor offsets are body-relative and node offsets are relative to
    the +0x08 base, exactly as this module reads them.
  * `func_020643CC` walks one multi-cell's nodes at an 8-byte stride
    (`add r6, r0, r8, lsl #3`), reads the node's u16 at +0x00 and passes it
    straight to `func_020627D8` as a **sequence index**, reads the byte at
    +0x07 (`& 0xFF00 >> 8`) as the cell-animation *slot*, and passes the s16
    at +0x02 and the s16 at +0x04 to `func_020640DC` as the node's x and y
    translation. Node record, final:

        0x00  u16  animSeqIdx     index into the paired NANR sequence array
        0x02  s16  posX
        0x04  s16  posY
        0x06  u8   nodeAttr       0x20 or 0x21; low nibble 1 selects the
                                   "sum the whole sequence's durations"
                                   playback path in func_020643CC
        0x07  u8   cellAnimSlot   slot in the caller's array of 0x5C-byte
                                   cell-animation states, NOT a cell index
                                   (func_02064648 sizes that array from the
                                   descriptor's +0x02 `numCellAnims`, which
                                   is why this byte just counts 0, 1, 2, ...)

**Cell selection is therefore never the node's own business.** The node
names a sequence; the sequence's current frame names the cell. This module
does the same, at frame 0.

--------------------------------------------------------------------------
Charizard/Gengar detachment: four hypotheses checked archive-wide, all false
(see docs/ASSETS.md, "Charizard/Gengar detachment root-caused as genuine
authored placement data, not a decode bug"). No code change came out of this
pass. Checked and ruled out for all 713 parseable species/form blocks, not
just the two documented ones:
  * NMCR node-offset sign extension (`<Hhh`) -- correct 2's-complement s16.
  * NANR type-1/2 per-frame (px, py) -- already applied by `_frame_placements`;
    reads (0, 0) at every sampled frame for the actual offending nodes.
  * NCER's bank-level `cell_info_type` (extended/bounding-box cell records)
    -- `== 0` in all 713 blocks; the 16-byte extended record never occurs.
  * NMCR's embedded-animation-bank field (`animBankOfs`) -- `== 0` in all
    713 blocks; the sibling NANR sub-file is always the right source.
Gengar's (species 94) actual detached nodes were also re-identified by
connected-component analysis of the rendered pose, correcting an informal
description in the thirteenth pass: they are node-array positions 4, 5, 6
and 11 (NCER cells 6, 3, 2, 5), not positions 0/1 (which are small,
correctly-attached feet). One unrelated latent bug was found in the same
sweep and deliberately left unpatched: `Oam.pal` (the 4bpp OBJ palette-bank
nibble) is parsed but never applied in compositing; only 2 of 713 species
(301, 327) have any OAM with a nonzero bank, and this archive's per-species
NCLR is a plain 16-color table, so a naive `pal*16` offset would read past
the end of it without a second, larger palette source identified first.
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Usage
--------------------------------------------------------------------------
    python tools/assets/rig.py 25                  # species 25 (Pikachu)
    python tools/assets/rig.py 25 --cells-only      # contact sheet only
    python tools/assets/rig.py 25 --pose            # contact sheet + pose
    python tools/assets/rig.py --all                # every species/form
"""

import argparse
import bisect
import math
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402
import battle_sprite as bs  # noqa: E402  (parse_nclr, PNG writer, bgr555)

ARCHIVE_PATH = os.path.join("extract", "data", "a", "0", "0", "4")
OUT_DIR = os.path.join("build", "assets", "rig")

# Default block size for `a/0/0/4` (species*20 .. species*20+19, see the
# module docstring). Any other rig-shaped archive (e.g. `a/0/7/2`'s
# candidate trainer battle rig, block size 8) is handled the same way via
# `--block-size` and `scan_rig_block`'s by-magic member detection below --
# no other per-archive local-offset table is needed.
BLOCK_STRIDE = 20

TILE_BYTES_4BPP = 32

SHAPE_SIZE_PX = {
    (0, 0): (8, 8),    (0, 1): (16, 16),  (0, 2): (32, 32),  (0, 3): (64, 64),
    (1, 0): (16, 8),   (1, 1): (32, 8),   (1, 2): (32, 16),  (1, 3): (64, 32),
    (2, 0): (8, 16),   (2, 1): (8, 32),   (2, 2): (16, 32),  (2, 3): (32, 64),
}


def _hdr(data):
    """Parse the common 16-byte Nitro resource file header."""
    magic, bom, ver, fsize, hsize, nblk = struct.unpack_from("<4sHHIHH", data, 0)
    return magic, hsize, nblk, fsize


def _patchwork(body, patches):
    """Reassemble `body` from a set of `(start_offset, reconstructed_bytes)`
    patches plus every byte of the original `body` that falls outside all
    of them, copied through verbatim.

    Used by every encode() below (NCGR/NCER/NANR/NMCR/NMAR): each patch is
    one region this project has decoded into named fields (re-serialized
    here to prove the decode was lossless), and whatever is left between/
    around the patches -- padding, a second NITRO block this project has
    not cracked (e.g. NCGR's optional SOPC, NCER/NANR's optional LBAL/TXEU),
    or any other opaque byte range -- is passed through untouched rather
    than reinterpreted. Same principle as background.py's `NscrFile.trailing`
    applied to possibly more than one known region."""
    patches = sorted(patches, key=lambda p: p[0])
    out = bytearray()
    pos = 0
    for start, data in patches:
        out += body[pos:start]
        out += data
        pos = start + len(data)
    out += body[pos:]
    return bytes(out)


def _encode_block(file_data, hsize, bmagic, bsize, body):
    """Re-serialize one Nitro resource file: the common 16-byte file header
    and every block's own magic+size are copied verbatim from `file_data`
    (including any block after the one this call reconstructs, e.g. a
    trailing SOPC/LBAL/TXEU block) -- only `body` (block 0's reconstructed
    body) comes from the caller. Declared size fields are never recomputed:
    at least one archive (`a/0/6/4` sub-file 0) has a file_size/block_size
    that overstates what the compressed stream actually contains, so the
    only byte-identical choice is to echo the literal original fields."""
    pos = hsize
    block = bmagic + struct.pack("<I", bsize) + body
    return file_data[:pos] + block + file_data[pos + bsize:]


# ---------------------------------------------------------------------------
# NCGR (RGCN) -- tile sheet
# ---------------------------------------------------------------------------

class Ncgr:
    """One RAHC (CHAR) character sheet, unpacked into a flat pixel image.

    The RAHC body is 24 bytes followed by the pixel array:

        0x00  u16  tile_num_y     sheet height in 8x8 blocks
        0x02  u16  tile_num_x     sheet width in 8x8 blocks
        0x04  u32  pixel_fmt      3 = 4bpp (every sheet in this archive)
        0x08  u32  mapping_type   0 here
        0x0C  u32  char_format    0 = tiled (8x8 blocks laid end to end),
                                   1 = bitmap (a plain linear image, row
                                   after row, `tile_num_x * 8` px wide)
        0x10  u32  data_size
        0x14  u32  data_ofs

    **`char_format` is load-bearing and was the pixel-layout bug this pass
    fixed**: the rig's main sheet (local 2) declares 1, so its bytes are a
    linear 256x128 image, not an 8x8-tiled one. Reading it as tiled turns
    every body part into 8-pixel-tall horizontal streaks, which is exactly
    what every render from the fifth lane pass onward showed. The small
    local-0 sheet declares 0 and really is tiled, so both are supported.

    Either way the sheet is exposed as one `w x h` pixel-index image and a
    cell OAM's tile index selects the 8x8 block at
    `(idx % tile_num_x, idx // tile_num_x)` -- see `block_pixels()`."""

    def __init__(self, data):
        magic, hsize, nblk, fsize = _hdr(data)
        if magic != b"RGCN":
            raise ValueError(f"not an RGCN (NCGR) resource: {magic!r}")
        pos = hsize
        bmagic, bsize = struct.unpack_from("<4sI", data, pos)
        if bmagic != b"RAHC":
            raise ValueError(f"expected RAHC (CHAR) block, found {bmagic!r}")
        body = data[pos + 8:pos + bsize]
        tile_num_y, tile_num_x = struct.unpack_from("<HH", body, 0)
        pixel_fmt, mapping_type, char_format = struct.unpack_from("<III", body, 4)
        data_size, data_ofs = struct.unpack_from("<II", body, 16)
        self.tile_num_x = tile_num_x
        self.tile_num_y = tile_num_y
        self.pixel_fmt = pixel_fmt
        self.mapping_type = mapping_type
        self.char_format = char_format
        self.data_ofs = data_ofs
        self.tile_data = body[data_ofs:data_ofs + data_size]
        self.tile_count = len(self.tile_data) // TILE_BYTES_4BPP
        # tile_num_x/y of 0xFFFF is a documented NDS CHAR-block sentinel for
        # "unspecified, derive from data" (see icons.py's module docstring,
        # which names the same field in the small-icon archive). This
        # project has not recovered a real width for that case -- eagerly
        # allocating a pixel buffer from the literal 0xFFFF x 0xFFFF would
        # either be wrong or (the bug this pass fixed) exhaust memory, so
        # rendering is simply skipped; round-tripping never needed pixels.py
        # rendering to begin with, only `tile_data` and the header fields.
        self._sentinel_dims = (tile_num_x == 0xFFFF or tile_num_y == 0xFFFF)
        if self._sentinel_dims:
            self.width = self.height = 0
            self.pixels = None
        else:
            self.width = tile_num_x * 8
            self.height = tile_num_y * 8
            self.pixels = self._unpack()
        # Round-trip state: `data` may carry a second block this project does
        # not decode (e.g. SOPC, see module docstring and docs/ASSETS.md's
        # "trainer rig NCGR round trip" note) -- kept verbatim by encode().
        self._raw = data
        self._hsize = hsize
        self._bmagic = bmagic
        self._bsize = bsize
        self._body = body

    def encode(self):
        """Re-serialize to the exact original (decompressed) NCGR bytes.
        The 24-byte RAHC head is rebuilt from the decoded fields; the pixel
        data is rebuilt from `tile_data`; everything else (any gap before
        `data_ofs`, any bytes after the declared tile data within this
        block, and any block after RAHC) is copied through verbatim."""
        head = struct.pack("<HHIIIII", self.tile_num_y, self.tile_num_x,
                            self.pixel_fmt, self.mapping_type, self.char_format,
                            len(self.tile_data), self.data_ofs)
        patches = [(0, head), (self.data_ofs, self.tile_data)]
        body = _patchwork(self._body, patches)
        return _encode_block(self._raw, self._hsize, self._bmagic, self._bsize, body)

    def _unpack(self):
        """Return the sheet as a flat `width * height` list of 4bpp indices,
        low nibble first (left pixel)."""
        w, h = self.width, self.height
        data = self.tile_data
        px = [0] * (w * h)
        if self.char_format == 1:
            for i, b in enumerate(data):
                p = i * 2
                if p + 1 >= len(px):
                    break
                px[p] = b & 0x0F
                px[p + 1] = (b >> 4) & 0x0F
            return px
        for t in range(len(data) // TILE_BYTES_4BPP):
            bx = (t % self.tile_num_x) * 8
            by = (t // self.tile_num_x) * 8
            if by + 8 > h:
                break
            base = t * TILE_BYTES_4BPP
            for i in range(TILE_BYTES_4BPP):
                b = data[base + i]
                p = (by + i // 4) * w + bx + (i % 4) * 2
                px[p] = b & 0x0F
                px[p + 1] = (b >> 4) & 0x0F
        return px

    def block_pixels(self, block_index):
        """Return the 64 pixel indices (row-major, 8x8) of one 8x8 block,
        addressed two-dimensionally: block `i` is at column `i % tile_num_x`,
        row `i // tile_num_x` of the sheet image."""
        bx = (block_index % self.tile_num_x) * 8
        by = (block_index // self.tile_num_x) * 8
        if by + 8 > self.height:
            return [0] * 64
        w = self.width
        out = []
        for ly in range(8):
            row = (by + ly) * w + bx
            out.extend(self.pixels[row:row + 8])
        return out

    # kept under its old name: every caller wants "the 8x8 block at index"
    tile_nibbles = block_pixels


def parse_ncgr(data):
    return Ncgr(data)


# ---------------------------------------------------------------------------
# NCER (RECN) -- cell bank
# ---------------------------------------------------------------------------

class Oam:
    __slots__ = ("y", "shape", "x", "hflip", "vflip", "size", "tile_idx",
                 "priority", "pal", "w", "h")

    def __init__(self, attr0, attr1, attr2):
        y = attr0 & 0xFF
        self.y = y - 256 if y >= 128 else y
        self.shape = (attr0 >> 14) & 0x3
        x = attr1 & 0x1FF
        self.x = x - 512 if x >= 256 else x
        rot_scale = (attr0 >> 8) & 0x1
        self.hflip = bool((attr1 >> 12) & 0x1) if not rot_scale else False
        self.vflip = bool((attr1 >> 13) & 0x1) if not rot_scale else False
        self.size = (attr1 >> 14) & 0x3
        self.tile_idx = attr2 & 0x3FF
        self.priority = (attr2 >> 10) & 0x3
        self.pal = (attr2 >> 12) & 0xF
        self.w, self.h = SHAPE_SIZE_PX.get((self.shape, self.size), (8, 8))


class Cell:
    __slots__ = ("num_oam", "cell_attr", "oams", "bounds")

    def __init__(self, num_oam, cell_attr, oams, bounds=None):
        self.num_oam = num_oam
        self.cell_attr = cell_attr
        self.oams = oams
        # (max_x, max_y, min_x, min_y), s16 each -- only present when the
        # bank's cell_info_type is 1 ("extended" records); None for the
        # plain 8-byte ("simple") record shape. See Ncer's module docstring.
        self.bounds = bounds


class Ncer:
    def __init__(self, data):
        magic, hsize, nblk, fsize = _hdr(data)
        if magic != b"RECN":
            raise ValueError(f"not an RECN (NCER) resource: {magic!r}")
        pos = hsize
        bmagic, bsize = struct.unpack_from("<4sI", data, pos)
        if bmagic != b"KBEC":
            raise ValueError(f"expected KBEC (CEBK) block, found {bmagic!r}")
        body = data[pos + 8:pos + bsize]
        num_cells, cell_info_type = struct.unpack_from("<HH", body, 0)
        cell_data_ofs, mapping_type, reserved = struct.unpack_from("<III", body, 4)
        self.num_cells = num_cells
        self.cell_info_type = cell_info_type
        self.mapping_type = mapping_type

        # cell_info_type selects the cell record shape (the NNS_G2D CEBK
        # convention, confirmed against real data this pass -- see
        # docs/ASSETS.md "NCER extended cell records"): 0 is the 8-byte
        # "simple" record this module originally only supported (num_oam,
        # cell_attr, oam_ofs); 1 is a 16-byte "extended" record with the
        # same three fields plus a (max_x, max_y, min_x, min_y) s16
        # bounding box. Confirmed against a/1/0/3 sub-file 1: reading cells
        # at an 8-byte stride put oam_ofs values at nonsense (garbage, out-
        # of-range) byte offsets; at a 16-byte stride every oam_ofs lines
        # up exactly with the running num_oam*6 total, the same lockstep
        # check the module docstring already uses to pin the simple shape.
        record_stride = 16 if cell_info_type == 1 else 8
        cell_hdrs = []
        for i in range(num_cells):
            off = cell_data_ofs + i * record_stride
            num_oam, cell_attr, oam_ofs = struct.unpack_from("<HHI", body, off)
            bounds = struct.unpack_from("<hhhh", body, off + 8) if record_stride == 16 else None
            cell_hdrs.append((num_oam, cell_attr, oam_ofs, bounds))

        oam_arr_start = cell_data_ofs + num_cells * record_stride
        self.cells = []
        for num_oam, cell_attr, oam_ofs, bounds in cell_hdrs:
            oams = []
            for i in range(num_oam):
                off = oam_arr_start + oam_ofs + i * 6
                a0, a1, a2 = struct.unpack_from("<HHH", body, off)
                oams.append(Oam(a0, a1, a2))
            self.cells.append(Cell(num_oam, cell_attr, oams, bounds))

        # Round-trip state. The OAM array (and anything past it, e.g. this
        # format's optional LBAL/TXEU blocks after KBEC) is kept verbatim:
        # only the 16-byte KBEC head and the cell array are rebuilt from
        # decoded fields, per module docstring / docs/ASSETS.md.
        self._raw = data
        self._hsize = hsize
        self._bmagic = bmagic
        self._bsize = bsize
        self._body = body
        self._cebk_reserved = reserved
        self._cell_data_ofs = cell_data_ofs
        self._record_stride = record_stride
        self._cell_hdrs = cell_hdrs

    def encode(self):
        """Re-serialize to the exact original (decompressed) NCER bytes."""
        head = struct.pack("<HHIII", self.num_cells, self.cell_info_type,
                            self._cell_data_ofs, self.mapping_type,
                            self._cebk_reserved)
        parts = []
        for n, a, o, bounds in self._cell_hdrs:
            rec = struct.pack("<HHI", n, a, o)
            if bounds is not None:
                rec += struct.pack("<hhhh", *bounds)
            parts.append(rec)
        cell_array = b"".join(parts)
        patches = [(0, head), (self._cell_data_ofs, cell_array)]
        body = _patchwork(self._body, patches)
        return _encode_block(self._raw, self._hsize, self._bmagic, self._bsize, body)


def parse_ncer(data):
    return Ncer(data)


# ---------------------------------------------------------------------------
# NMCR (RCMN) -- multi-cell resource: rest-pose node placement
#
# Corrected this pass against the mission's composer semantics, byte-
# verified against species 25's real data (not a repeat of the previous
# pass's 10-byte-descriptor guess, which this replaces):
#
# Bank header (24 bytes; the 8-byte common file header is separate and
# already stripped by `_hdr`/`body` above):
#     0x00  u16  numMultiCell
#     0x02  u16  signature       0xBEEF constant
#     0x04  u32  mcArrayOfs      ABSOLUTE byte offset (from body start) of
#                                  the multi-cell descriptor array -- NOT
#                                  self-relative to its own field position;
#                                  the previous pass's "+4" self-relative
#                                  correction was checked against real bytes
#                                  this pass and does not fit (produces a
#                                  descriptor array that overlaps the header
#                                  and decodes to nonsense numNodes/offset
#                                  values). The bare field value lines up
#                                  exactly with the header's own end (24
#                                  bytes in, matching the two trailing u16
#                                  "unk" fields below) when used directly.
#     0x08  u32  nodeArrayOfs    ABSOLUTE byte offset (from body start) of
#                                  the node array; same correction as above.
#     0x0C  u32  reserved (0)
#     0x10  u32  animBankOfs     embedded NANR body offset, or 0 (unused by
#                                  this tool; the block's own separate NANR
#                                  sub-file is used instead, see
#                                  `scan_rig_block`/`load_rig_block`)
#     0x14  u16  unk (10 for species 25)
#     0x16  u16  unk (10 for species 25)
#
# Multi-cell descriptor array (8 bytes/entry, `numMultiCell` entries,
# starting at `mcArrayOfs`) -- confirmed 8-byte stride by
# `src/matched/func_020629E8.c`'s `lsl #3` indexing (EXACT status) and by
# `docs/notes/func_0206296C.c.txt`'s `struct MultiCellData { u16 numNodes;
# u16 unk02; u32 nodes; }` (near-miss but semantically certain):
#     0x00  u16  numNodes
#     0x02  u16  numSlots (unk02 in the decompiled struct; not decoded)
#     0x04  u32  nodeArrayOffset   relative to `nodeArrayOfs` above
#
# For species 25: descriptor 0 = (numNodes=10, nodeArrayOffset=0) and
# descriptor 1 = (numNodes=10, nodeArrayOffset=80) -- 80 == 10 nodes * 8
# bytes, so the two multi-cell groups' node spans are exactly back-to-back
# (bytes [nodeArrayOfs, nodeArrayOfs+80) and [+80, +160)) and together
# consume the entire rest of the body with zero leftover bytes. This is a
# clean, exact fit (unlike the previous pass's 19-node/one-collision
# reading, which came from a wrong node-array base 8 bytes too far in).
#
# Node record (8 bytes), per the mission's proposed layout, byte-verified:
#     0x00  u16  animSeqIdx   index into the paired NANR's sequence array
#                              (NOT a name-table/LBAL index as the previous
#                              pass read it -- see compose_pose())
#     0x02  s16  posX         translation applied to the whole assembled
#                              cell (see compose_pose())
#     0x04  s16  posY
#     0x06  u8   nodeAttr     constant 0x20 across every record sampled
#     0x07  u8   cellAnimSlot positional slot index (cycles 0-9); NOT used
#                              for cell selection (see compose_pose())
# For species 25, the 20 nodes' `animSeqIdx` values cover 0-19 exactly
# once each (10 in each multi-cell group) -- a clean bijection with the
# NANR's 20 sequences, unlike the previous pass's LBAL-name reading which
# needed a label collision to explain its 19-node count.
# ---------------------------------------------------------------------------

class McNode:
    __slots__ = ("anim_seq_idx", "x", "y", "node_attr", "cell_anim_slot")

    def __init__(self, anim_seq_idx, x, y, node_attr, cell_anim_slot):
        self.anim_seq_idx = anim_seq_idx
        self.x = x
        self.y = y
        self.node_attr = node_attr
        self.cell_anim_slot = cell_anim_slot


class McGroup:
    __slots__ = ("num_nodes", "unk02", "nodes")

    def __init__(self, num_nodes, unk02, nodes):
        self.num_nodes = num_nodes
        self.unk02 = unk02
        self.nodes = nodes


class Nmcr:
    def __init__(self, data):
        magic, hsize, nblk, fsize = _hdr(data)
        if magic != b"RCMN":
            raise ValueError(f"not an RCMN (NMCR) resource: {magic!r}")
        pos = hsize
        bmagic, bsize = struct.unpack_from("<4sI", data, pos)
        if bmagic != b"KBCM":
            raise ValueError(f"expected KBCM (MCBK) block, found {bmagic!r}")
        body = data[pos + 8:pos + bsize]
        num_multi_cell, sig = struct.unpack_from("<HH", body, 0)
        mc_abs, = struct.unpack_from("<I", body, 4)
        node_abs, = struct.unpack_from("<I", body, 8)
        reserved, = struct.unpack_from("<I", body, 12)
        self.num_multi_cell = num_multi_cell
        self.signature = sig
        self.mc_array_ofs = mc_abs
        self.node_array_ofs = node_abs
        self.reserved = reserved
        # `mc_abs` is the authoritative end of this header -- it is NOT a
        # fixed 16 bytes for every archive (species 25's a/0/0/4 puts it at
        # 24, with two more fields -- animBankOfs, and the two "unk"
        # u16s -- in between; a/0/6/4's trainer-rig-shaped NMCR puts it at
        # 20, one field narrower). Rather than hardcode either shape, bytes
        # [16, mc_abs) are left as an undecoded, verbatim-preserved gap (see
        # encode()) and only the fields the module docstring actually reads
        # at every site are exposed as attributes.

        self.groups = []
        all_nodes = []
        group_bases = []
        for i in range(num_multi_cell):
            off = mc_abs + i * 8
            num_nodes, unk02, node_ofs = struct.unpack_from("<HHI", body, off)
            base = node_abs + node_ofs
            nodes = []
            for j in range(num_nodes):
                noff = base + j * 8
                if noff + 8 > len(body):
                    break
                anim_seq_idx, x, y = struct.unpack_from("<Hhh", body, noff)
                node_attr = body[noff + 6]
                cell_anim_slot = body[noff + 7]
                nodes.append(McNode(anim_seq_idx, x, y, node_attr, cell_anim_slot))
            self.groups.append(McGroup(num_nodes, unk02, nodes))
            all_nodes.extend(nodes)
            group_bases.append((off, node_ofs, base))
        self.nodes = all_nodes

        self._raw = data
        self._hsize = hsize
        self._bmagic = bmagic
        self._bsize = bsize
        self._body = body
        self._group_bases = group_bases  # (descriptor_ofs, node_ofs, node_base)

    def rest_pose(self):
        """The first multi-cell group's own node list -- a complete,
        self-contained assembly (see module docstring)."""
        if not self.groups:
            return []
        return self.groups[0].nodes

    def encode(self):
        """Re-serialize to the exact original (decompressed) NMCR bytes."""
        head = struct.pack("<HHIII", self.num_multi_cell, self.signature,
                            self.mc_array_ofs, self.node_array_ofs, self.reserved)
        patches = [(0, head)]
        for group, (desc_ofs, node_ofs, base) in zip(self.groups, self._group_bases):
            patches.append((desc_ofs, struct.pack("<HHI", group.num_nodes,
                                                    group.unk02, node_ofs)))
            node_bytes = b"".join(
                struct.pack("<HhhBB", n.anim_seq_idx, n.x, n.y, n.node_attr,
                            n.cell_anim_slot)
                for n in group.nodes)
            if node_bytes:
                patches.append((base, node_bytes))
        body = _patchwork(self._body, patches)
        return _encode_block(self._raw, self._hsize, self._bmagic, self._bsize, body)


def parse_nmcr(data):
    return Nmcr(data)


# ---------------------------------------------------------------------------
# NMAR (RAMN) -- multi-cell animation (best-effort; see module docstring)
# ---------------------------------------------------------------------------

class Nmar:
    def __init__(self, data):
        magic, hsize, nblk, fsize = _hdr(data)
        if magic != b"RAMN":
            raise ValueError(f"not an RAMN (NMAR) resource: {magic!r}")
        pos = hsize
        bmagic, bsize = struct.unpack_from("<4sI", data, pos)
        if bmagic != b"KNBA":
            raise ValueError(f"expected KNBA (ANBK) block, found {bmagic!r}")
        body = data[pos + 8:pos + bsize]
        num_anim, element_type = struct.unpack_from("<HH", body, 0)
        self.num_anim = num_anim
        self.element_type = element_type
        self.anim_names = []
        pos2 = pos + bsize
        if pos2 < len(data):
            bmagic2, bsize2 = struct.unpack_from("<4sI", data, pos2)
            if bmagic2 == b"LBAL":
                lbody = data[pos2 + 8:pos2 + bsize2]
                # u32 offset, then a NUL-terminated name string
                s = lbody[4:].split(b"\x00", 1)[0]
                try:
                    self.anim_names.append(s.decode("ascii"))
                except UnicodeDecodeError:
                    pass

        # Round-trip state. Only the 4-byte (num_anim, element_type) head is
        # decoded; the rest of the body (table_a/table_b, see module
        # docstring "what was recovered") and any block after KNBA (e.g. the
        # LBAL just read above, or TXEU) are preserved verbatim.
        self._raw = data
        self._hsize = hsize
        self._bmagic = bmagic
        self._bsize = bsize
        self._body = body

    def encode(self):
        """Re-serialize to the exact original (decompressed) NMAR bytes."""
        head = struct.pack("<HH", self.num_anim, self.element_type)
        body = _patchwork(self._body, [(0, head)])
        return _encode_block(self._raw, self._hsize, self._bmagic, self._bsize, body)


def parse_nmar(data):
    return Nmar(data)


# ---------------------------------------------------------------------------
# NANR (RNAN) -- cell animation: frame-entry / frame-data indirection
# (corrected this pass; see module docstring "NANR (RNAN) format, corrected")
# ---------------------------------------------------------------------------

ANIM_ELEMENT_INDEX = 0    # {u16 cellIdx} (padded to 4 bytes)
ANIM_ELEMENT_SRT = 1      # {u16 cellIdx, u16 rotZ, s32 sx, s32 sy, s16 px, s16 py}
ANIM_ELEMENT_T = 2        # {u16 cellIdx, u16 pad, s16 px, s16 py}


class NanrSequence:
    __slots__ = ("num_frames", "loop_start", "anim_type", "play_mode",
                 "frames_ofs")

    def __init__(self, num_frames, loop_start, anim_type, play_mode, frames_ofs):
        self.num_frames = num_frames
        self.loop_start = loop_start
        self.anim_type = anim_type
        self.play_mode = play_mode
        self.frames_ofs = frames_ofs

    @property
    def element_type(self):
        """The frame-data record shape, 0/1/2 (see ANIM_ELEMENT_*). The
        renderer masks the 32-bit field with 0xFF (func_0206419C +0x4C)."""
        return self.anim_type & 0xFF


class Nanr:
    def __init__(self, data):
        magic, hsize, nblk, fsize = _hdr(data)
        if magic != b"RNAN":
            raise ValueError(f"not an RNAN (NANR) resource: {magic!r}")
        pos = hsize
        bmagic, bsize = struct.unpack_from("<4sI", data, pos)
        if bmagic != b"KNBA":
            raise ValueError(f"expected KNBA (ABNK) block, found {bmagic!r}")
        body = data[pos + 8:pos + bsize]
        self._body = body
        num_seq, num_frames_total = struct.unpack_from("<HH", body, 0)
        seq_ofs, frame_ofs, frame_data_ofs = struct.unpack_from("<III", body, 4)
        self.num_sequences = num_seq
        self.num_elements = num_frames_total
        self._seq_ofs = seq_ofs
        self._frame_ofs = frame_ofs
        self._frame_data_ofs = frame_data_ofs

        self.sequences = []
        for i in range(num_seq):
            off = seq_ofs + i * 16
            n_frames, loop_start = struct.unpack_from("<HH", body, off)
            anim_type, play_mode, frames_ofs = struct.unpack_from("<III", body, off + 4)
            self.sequences.append(
                NanrSequence(n_frames, loop_start, anim_type, play_mode, frames_ofs))
        self._time_cache = {}

        # Round-trip state. Only the 16-byte ABNK head and the sequence
        # array (at seq_ofs) are decoded into fields; the frame-entry array
        # and frame-data region (frame_ofs/frame_data_ofs) are not broken
        # out into their own attributes above, so they -- along with any
        # block after KNBA (e.g. LBAL/TXEU) -- are preserved verbatim.
        self._raw = data
        self._hsize = hsize
        self._bmagic = bmagic
        self._bsize = bsize

    def encode(self):
        """Re-serialize to the exact original (decompressed) NANR bytes."""
        head = struct.pack("<HHIII", self.num_sequences, self.num_elements,
                            self._seq_ofs, self._frame_ofs, self._frame_data_ofs)
        seq_array = b"".join(
            struct.pack("<HHIII", s.num_frames, s.loop_start, s.anim_type,
                        s.play_mode, s.frames_ofs)
            for s in self.sequences)
        patches = [(0, head)]
        if seq_array:
            patches.append((self._seq_ofs, seq_array))
        body = _patchwork(self._body, patches)
        return _encode_block(self._raw, self._hsize, self._bmagic, self._bsize, body)

    def frame_entry(self, seq_index, frame_index=0):
        """Return (offset_to_frame_data, duration) for one frame entry, or
        None when the sequence has no frame at that index.

        The frame entry lives at `frameArrayBase + seq.frames_ofs +
        8*frame_index` -- `seq.frames_ofs` is a byte offset into the one
        shared frame-entry array, NOT an index, and it is the only thing
        that says where a sequence's frames start (see module docstring)."""
        if not (0 <= seq_index < len(self.sequences)):
            return None
        seq = self.sequences[seq_index]
        if not (0 <= frame_index < seq.num_frames):
            return None
        off = self._frame_ofs + seq.frames_ofs + frame_index * 8
        fofs, duration, _sentinel = struct.unpack_from("<IHH", self._body, off)
        return fofs, duration

    def frame_data(self, seq_index, frame_index=0):
        """Return `(cellIdx, px, py, sx, sy, rotZ)` for one frame, decoding
        whichever of the three frame-data record shapes this sequence's
        element type selects, or None if unavailable. `sx`/`sy` are FX32
        (4096 == 1.0) and `rotZ` is in 1/65536 of a turn; index (type 0) and
        T (type 2) records carry no scale/rotation field at all, so they
        report the identity (4096, 4096, 0) -- indistinguishable, at the
        byte level, from a type-1 record that happens to read identity,
        which is what every frame-0 SRT record sampled in this archive
        does."""
        if not (0 <= seq_index < len(self.sequences)):
            return None
        entry = self.frame_entry(seq_index, frame_index)
        if entry is None:
            return None
        fofs, _duration = entry
        base = self._frame_data_ofs + fofs
        etype = self.sequences[seq_index].element_type
        need = {ANIM_ELEMENT_INDEX: 2, ANIM_ELEMENT_SRT: 16, ANIM_ELEMENT_T: 8}
        if etype not in need or base + need[etype] > len(self._body):
            return None
        cell_idx, = struct.unpack_from("<H", self._body, base)
        if etype == ANIM_ELEMENT_INDEX:
            return cell_idx, 0, 0, 4096, 4096, 0
        if etype == ANIM_ELEMENT_T:
            px, py = struct.unpack_from("<hh", self._body, base + 4)
            return cell_idx, px, py, 4096, 4096, 0
        rot_z, = struct.unpack_from("<H", self._body, base + 2)
        sx, sy = struct.unpack_from("<ii", self._body, base + 4)
        px, py = struct.unpack_from("<hh", self._body, base + 12)
        return cell_idx, px, py, sx, sy, rot_z

    # -----------------------------------------------------------------
    # Per-frame timeline (this pass): a sequence's frame entries carry a
    # duration in NDS frames each; playback sums them to know which frame
    # entry a given elapsed time `t` (also in NDS frames) falls in, and
    # loops from `loopStartFrameIdx` once the sequence's own total is
    # exceeded -- the same summing loop `func_020643CC` runs at 0x020644B8
    # (see module docstring "the NANR sequence record"), just evaluated at
    # an arbitrary `t` instead of only accumulating forward.
    # -----------------------------------------------------------------

    def _frame_times(self, seq_index):
        """Cumulative start time of every frame in a sequence, plus a
        trailing sentinel equal to the sequence's total duration:
        `starts[i] <= t < starts[i + 1]` selects frame `i`. Cached per
        sequence (species 25's longest sequence is 31 frames, so this is
        cheap even uncached, but --anim-all calls it per species)."""
        cached = self._time_cache.get(seq_index)
        if cached is not None:
            return cached
        seq = self.sequences[seq_index]
        starts = []
        t = 0
        for i in range(seq.num_frames):
            starts.append(t)
            entry = self.frame_entry(seq_index, i)
            duration = entry[1] if entry is not None else 1
            t += max(duration, 1)  # a zero-duration frame must not stall time
        starts.append(t)
        self._time_cache[seq_index] = starts
        return starts

    def total_duration(self, seq_index):
        """A sequence's total playback length in NDS frames (one pass
        through all its frames, before any looping)."""
        if not (0 <= seq_index < len(self.sequences)):
            return 0
        return self._frame_times(seq_index)[-1]

    def frame_index_at_time(self, seq_index, t):
        """The frame index active at elapsed time `t` (NDS frames, `t >=
        0`), looping from `loopStartFrameIdx` once the sequence's own
        total duration is exceeded."""
        if not (0 <= seq_index < len(self.sequences)):
            return 0
        seq = self.sequences[seq_index]
        if seq.num_frames <= 1:
            return 0
        starts = self._frame_times(seq_index)
        total = starts[-1]
        if total <= 0:
            return 0
        loop_start = min(max(seq.loop_start, 0), seq.num_frames - 1)
        et = t
        if et >= total:
            loop_time = starts[loop_start]
            loop_len = total - loop_time
            et = loop_time if loop_len <= 0 else loop_time + (et - total) % loop_len
        idx = bisect.bisect_right(starts, et) - 1
        return max(0, min(idx, seq.num_frames - 1))


def parse_nanr(data):
    return Nanr(data)


NDS_FPS = 59.8261  # standard NDS/GBA refresh rate; NANR durations are in NDS
                    # frames, GIF delays are centiseconds -- this is the
                    # conversion assumed (not stated anywhere in this
                    # archive; the closest thing to ground truth in-project)


def _driving_sequence(nanr, nodes):
    """The node whose own sequence has the longest total playback duration
    -- every other node's sequence is shorter and simply loops (via
    `Nanr.frame_index_at_time`) while the driving one plays through once."""
    return max((nd.anim_seq_idx for nd in nodes), key=lambda si: nanr.total_duration(si))


def animation_frame_times(nanr, nodes, max_frames=32):
    """All distinct frame times (NDS frames, elapsed since t=0) over one
    loop of an animated node group: the frame-start boundaries of the
    driving sequence (`_driving_sequence`). Capped at `max_frames` entries
    per the mission's "or the first 32 frames" fallback."""
    if nanr is None or not nodes:
        return [0]
    driving = _driving_sequence(nanr, nodes)
    times = nanr._frame_times(driving)[:-1]
    if not times:
        times = [0]
    if len(times) > max_frames:
        times = times[:max_frames]
    return times


def animation_delays_cs(nanr, nodes, times):
    """GIF frame delays (centiseconds) for `times`, converting the NANR
    duration unit (NDS frames) via `NDS_FPS`. The last delay wraps back to
    the driving sequence's own total duration (its loop point) rather than
    guessing a repeat of the first gap."""
    if nanr is None or not nodes or not times:
        return [10] * max(len(times), 1)
    driving = _driving_sequence(nanr, nodes)
    total = nanr.total_duration(driving)
    delays = []
    for i, t in enumerate(times):
        nxt = times[i + 1] if i + 1 < len(times) else max(total, t + 1)
        delays.append(max(2, round(max(nxt - t, 1) * 100.0 / NDS_FPS)))
    return delays


# ---------------------------------------------------------------------------
# Compositing
# ---------------------------------------------------------------------------

def render_oam(ncgr, oam, n_pal_colors=16):
    """Return one OAM's pixel block (rows of 4bpp indices), flips applied.

    The OAM's tile index is a **two-dimensional** block index into the sheet
    (row `idx // tile_num_x`, column `idx % tile_num_x`), so an OAM wider or
    taller than one block steps by `tile_num_x` per row, not by its own
    width. Species 25's cell 0 proves this from the data alone: a 16x16 OAM
    at index 99 sits next to an 8x16 OAM at index 101, which can only avoid
    overlapping if the first consumes 99/100 and 131/132 rather than
    99/100/101/102.

    `oam.pal` (the 4bpp OBJ palette-bank nibble) is applied as a `pal * 16`
    row offset into the caller's palette **only** when that palette actually
    has `(pal + 1) * 16` rows (`n_pal_colors`, the length of
    `build_bank_palette()`'s concatenation of every NCLR in the block) --
    otherwise the bank is left at 0, same as before this pass, since a
    single 16-color NCLR has no second bank to offset into. Index 0 (the
    transparent/background index) is never offset, matching what every
    compositing path already treats as "draw nothing"."""
    bank_ok = (oam.pal * 16 + 16) <= n_pal_colors
    offset = oam.pal * 16 if bank_ok else 0
    tiles_w = oam.w // 8
    tiles_h = oam.h // 8
    px = [[0] * oam.w for _ in range(oam.h)]
    for ty in range(tiles_h):
        for tx in range(tiles_w):
            tile_index = oam.tile_idx + ty * ncgr.tile_num_x + tx
            nib = ncgr.block_pixels(tile_index)
            for ly in range(8):
                for lx in range(8):
                    v = nib[ly * 8 + lx]
                    px[ty * 8 + ly][tx * 8 + lx] = v + offset if v else 0
    if oam.hflip:
        px = [row[::-1] for row in px]
    if oam.vflip:
        px = px[::-1]
    return px


def _apply_srt(x, y, sx, sy, rot_z):
    """Scale then rotate a cell-local point `(x, y)` about the cell's own
    origin (the node+frame translation point): `sx`/`sy` are FX32 (4096 ==
    1.0), `rot_z` is 1/65536 of a turn. Forward direction only -- used to
    find the post-transform bounding box of a cell (`_cell_frame_raster`);
    per-pixel sampling itself goes through `_inverse_srt` below, mirroring
    how DS OAM affine sprites actually render (hardware inverse-maps each
    *output* pixel through the matrix, it does not forward-map input
    pixels)."""
    fx = x * sx / 4096.0
    fy = y * sy / 4096.0
    if rot_z:
        theta = rot_z * (2.0 * math.pi / 65536.0)
        c, s = math.cos(theta), math.sin(theta)
        fx, fy = fx * c - fy * s, fx * s + fy * c
    return fx, fy


def _inverse_srt(x, y, sx, sy, rot_z):
    """Invert `_apply_srt`: map a post-transform cell-local coordinate `(x,
    y)` back to the pre-transform source coordinate it was sampled from.
    The forward transform is scale-then-rotate (`output = R(theta) @ S @
    input`), so the inverse is un-rotate-then-un-scale (`input = S^-1 @
    R(-theta) @ output`) -- this is the actual per-pixel operation DS OAM
    affine sprites perform: for every pixel of the (possibly enlarged,
    double-size-mode) output canvas, inverse-map through PA/PB/PC/PD about
    the sprite centre and nearest-neighbour-sample the source tile."""
    if rot_z:
        theta = -rot_z * (2.0 * math.pi / 65536.0)
        c, s = math.cos(theta), math.sin(theta)
        x, y = x * c - y * s, x * s + y * c
    sx = sx or 4096
    sy = sy or 4096
    return x * 4096.0 / sx, y * 4096.0 / sy


def _cell_local_raster(ncgr, cell, n_pal_colors=16):
    """Render one cell's OAMs onto a local canvas at identity placement (an
    OAM's `(x, y)` is already relative to the cell's own origin -- see
    module docstring). Returns `(ox, oy, width, height, flat_pixels)`
    where `(ox, oy)` is the position of the cell origin `(0, 0)` within the
    returned canvas: a cell-local coordinate `(x, y)` is canvas index `(x +
    ox, y + oy)`. Shared by the contact sheet and by `_cell_frame_raster`'s
    per-pixel SRT resampling. `n_pal_colors` is forwarded to `render_oam()`
    to gate the palette-bank offset -- see that function's docstring."""
    if not cell.oams:
        return 0, 0, 1, 1, [0]
    minx = miny = 10**9
    maxx = maxy = -10**9
    for oam in cell.oams:
        minx = min(minx, oam.x)
        miny = min(miny, oam.y)
        maxx = max(maxx, oam.x + oam.w)
        maxy = max(maxy, oam.y + oam.h)
    w = maxx - minx
    h = maxy - miny
    canvas = [[0] * w for _ in range(h)]
    for oam in cell.oams:
        rows = render_oam(ncgr, oam, n_pal_colors)
        for ly, row in enumerate(rows):
            py = oam.y - miny + ly
            if not (0 <= py < h):
                continue
            for lx, v in enumerate(row):
                if v == 0:
                    continue
                px = oam.x - minx + lx
                if 0 <= px < w:
                    canvas[py][px] = v
    return -minx, -miny, w, h, [v for row in canvas for v in row]


def _cell_frame_raster(ncgr, cell, sx, sy, rot_z, n_pal_colors=16):
    """One cell, transformed by one frame's SRT, as a single flat raster --
    the per-pixel counterpart to the twelfth/thirteenth passes' rigid
    per-OAM placement offset. Matches the DS OAM affine-sprite algorithm:
    compose the cell into a temporary canvas at identity (`_cell_local_
    raster`), then inverse-map every pixel of the (generally larger,
    double-size-mode-like) output canvas through the frame's SRT about the
    cell origin (`_inverse_srt`) and nearest-neighbour-sample the identity
    canvas. Returns `(ox, oy, width, height, flat_pixels)` in the same
    `(ox, oy)`-is-the-origin's-canvas-position convention as `_cell_local_
    raster`."""
    src_ox, src_oy, src_w, src_h, src_flat = _cell_local_raster(ncgr, cell, n_pal_colors)
    if sx == 4096 and sy == 4096 and rot_z == 0:
        return src_ox, src_oy, src_w, src_h, src_flat

    # Source bbox in cell-local (origin-relative) coordinates.
    lx0, ly0 = -src_ox, -src_oy
    lx1, ly1 = lx0 + src_w, ly0 + src_h
    corners = [(lx0, ly0), (lx1, ly0), (lx0, ly1), (lx1, ly1)]
    fwd = [_apply_srt(x, y, sx, sy, rot_z) for x, y in corners]
    margin = 1  # nearest-neighbour rounding slop at the output edge
    minx = math.floor(min(p[0] for p in fwd)) - margin
    maxx = math.ceil(max(p[0] for p in fwd)) + margin
    miny = math.floor(min(p[1] for p in fwd)) - margin
    maxy = math.ceil(max(p[1] for p in fwd)) + margin
    out_w = max(maxx - minx, 1)
    out_h = max(maxy - miny, 1)
    out = [[0] * out_w for _ in range(out_h)]
    for oy in range(out_h):
        ly = miny + oy
        for ox in range(out_w):
            lx = minx + ox
            sxl, syl = _inverse_srt(lx, ly, sx, sy, rot_z)
            six = round(sxl) - lx0
            siy = round(syl) - ly0
            if 0 <= six < src_w and 0 <= siy < src_h:
                v = src_flat[siy * src_w + six]
                if v:
                    out[oy][ox] = v
    return -minx, -miny, out_w, out_h, [v for row in out for v in row]


def _frame_placements(ncgr, ncer, nodes, nanr, frame_idx_for_node, n_pal_colors=16):
    """One frame's (abs_x, abs_y, px_rows) placements for every node, plus
    the bbox they cover. `frame_idx_for_node(node)` resolves each node's own
    frame index (so callers can drive nodes at a shared time or all at a
    fixed frame). `n_pal_colors` gates the OAM palette-bank offset -- see
    `render_oam()`'s docstring."""
    placements = []
    minx = miny = 10**9
    maxx = maxy = -10**9
    for node in reversed(nodes):
        fd = None
        if nanr is not None:
            fd = nanr.frame_data(node.anim_seq_idx, frame_idx_for_node(node))
        if fd is None:
            continue
        cell_idx, px, py, sx, sy, rot_z = fd
        if cell_idx >= len(ncer.cells):
            continue
        cell = ncer.cells[cell_idx]
        if not cell.oams:
            continue
        identity = sx == 4096 and sy == 4096 and rot_z == 0
        if identity:
            for oam in cell.oams:
                rows = render_oam(ncgr, oam, n_pal_colors)
                ax = node.x + px + oam.x
                ay = node.y + py + oam.y
                placements.append((ax, ay, rows))
                minx = min(minx, ax)
                miny = min(miny, ay)
                maxx = max(maxx, ax + oam.w)
                maxy = max(maxy, ay + oam.h)
        else:
            # Non-identity: per-pixel resample the whole cell as one block
            # (see `_cell_frame_raster`) instead of moving each OAM as a
            # rigid, unrotated rectangle.
            ox, oy, w, h, flat = _cell_frame_raster(ncgr, cell, sx, sy, rot_z, n_pal_colors)
            rows = [flat[r * w:(r + 1) * w] for r in range(h)]
            ax = node.x + px - ox
            ay = node.y + py - oy
            placements.append((ax, ay, rows))
            minx = min(minx, ax)
            miny = min(miny, ay)
            maxx = max(maxx, ax + w)
            maxy = max(maxy, ay + h)
    return placements, minx, miny, maxx, maxy


def _raster(placements, ox, oy, width, height):
    canvas = [[0] * width for _ in range(height)]
    for ax, ay, rows in placements:
        for ly, row in enumerate(rows):
            py = ay + oy + ly
            if py < 0 or py >= height:
                continue
            for lx, v in enumerate(row):
                if v == 0:
                    continue
                px = ax + ox + lx
                if 0 <= px < width:
                    canvas[py][px] = v
    return [v for row in canvas for v in row]


def compose_pose_multi(ncgr, ncer, nodes, nanr, times, n_pal_colors=16):
    """Compose one frame per elapsed time in `times` (NDS frames, per node
    via `Nanr.frame_index_at_time` -- see the module docstring's per-frame
    composition rule), all onto **one shared canvas size** so an animation
    strip/GIF doesn't jitter frame to frame. Returns `(width, height,
    [flat_pixels_per_time])`. `n_pal_colors` gates the OAM palette-bank
    offset -- see `render_oam()`'s docstring."""
    per_frame = []
    minx = miny = 10**9
    maxx = maxy = -10**9
    for t in times:
        def frame_idx_for_node(node, _t=t):
            return nanr.frame_index_at_time(node.anim_seq_idx, _t) if nanr else 0
        placements, fminx, fminy, fmaxx, fmaxy = _frame_placements(
            ncgr, ncer, nodes, nanr, frame_idx_for_node, n_pal_colors)
        per_frame.append(placements)
        if placements:
            minx = min(minx, fminx)
            miny = min(miny, fminy)
            maxx = max(maxx, fmaxx)
            maxy = max(maxy, fmaxy)

    if minx > maxx:
        return 1, 1, [[0] for _ in times]

    margin = 2
    ox = -minx + margin
    oy = -miny + margin
    width = (maxx - minx) + margin * 2
    height = (maxy - miny) + margin * 2
    frames = [_raster(placements, ox, oy, width, height) for placements in per_frame]
    return width, height, frames


def compose_pose(ncgr, ncer, nodes, nanr=None, t=0, n_pal_colors=16):
    """Blit every node's cell onto a shared canvas at one elapsed time `t`
    (NDS frames; `t=0` is the classic single "rest pose" render), following
    the composer the game itself runs (`func_020643CC` walks the nodes,
    `func_0206419C` turns one node's current animation frame into a cell
    plus a translation; see the module docstring for the byte-level
    derivation):

      * **Cell selection**: a node names an *animation sequence* through its
        `anim_seq_idx` (`func_020627D8` indexes the NANR bank's sequence
        array with it, 16-byte stride). That sequence's frame entry active
        at time `t` (`Nanr.frame_index_at_time`, summing frame durations the
        same way `func_020643CC`'s 0x020644B8 loop does, looping from
        `loopStartFrameIdx` past the sequence's own total) points at a
        frame-data record whose first u16 is the NCER cell index
        (`func_0206419C` +0x18: `func_02062D40` derefs the frame entry, then
        `func_0206285C` looks the cell up by the u16 at its +0). The node's
        own `cell_anim_slot` byte is not a cell index at all: it is the slot
        in the caller's array of 0x5C-byte cell-animation states
        (`func_02064648`). A node whose sequence has no such frame is
        skipped.

      * **Placement**: the node's (posX, posY) (`func_020643CC` +0x250,
        `func_020640DC`) plus the frame's own (px, py) translation
        (`func_0206419C`, SRT and T records both) is a straight translation
        of the whole cell; each OAM keeps its own cell-local (x, y), summed
        the same way. A type-1 (SRT) frame's (sx, sy, rotZ) affine transform
        is applied about the cell's own origin (the node+frame translation
        point) when not identity -- see `_apply_srt` -- though every frame-0
        record sampled in this archive reads rotZ 0 and sx/sy 4096 (FX32
        1.0), which is why earlier passes never needed it.

      * **Draw order**: nodes are emitted into the hardware OAM list in
        array order, and a lower OAM index draws in front, so the nodes are
        painted back-to-front here (last node first)."""
    width, height, frames = compose_pose_multi(ncgr, ncer, nodes, nanr, [t], n_pal_colors)
    return width, height, frames[0]


# ---------------------------------------------------------------------------
# Contact sheet (fallback / diagnostic deliverable)
# ---------------------------------------------------------------------------

def render_cells_contact_sheet(ncgr, ncer, palette):
    """Render each cell of the NCER individually (own local bounding box),
    laid out left-to-right in a contact sheet. Used both as the mission's
    documented fallback and as a useful debugging aid for the main pose."""
    n_pal_colors = len(palette) if palette else 16
    cell_images = []
    for cell in ncer.cells:
        _ox, _oy, w, h, flat = _cell_local_raster(ncgr, cell, n_pal_colors)
        cell_images.append((w, h, flat))

    pad = 4
    sheet_h = max(h for _, h, _ in cell_images) + pad * 2
    sheet_w = sum(w for w, _, _ in cell_images) + pad * (len(cell_images) + 1)
    sheet = [[0] * sheet_w for _ in range(sheet_h)]
    cx = pad
    for w, h, flat in cell_images:
        for ly in range(h):
            for lx in range(w):
                sheet[pad + ly][cx + lx] = flat[ly * w + lx]
        cx += w + pad
    flat_sheet = [v for row in sheet for v in row]
    return sheet_w, sheet_h, flat_sheet


def render_animation_strip(frame_w, frame_h, frames):
    """Lay out an animation's frames left-to-right, all sharing `compose_
    pose_multi`'s uniform per-frame canvas, for a single contact-sheet-style
    PNG export."""
    pad = 2
    sheet_w = frame_w * len(frames) + pad * (len(frames) + 1)
    sheet_h = frame_h + pad * 2
    sheet = [[0] * sheet_w for _ in range(sheet_h)]
    cx = pad
    for flat in frames:
        for ly in range(frame_h):
            for lx in range(frame_w):
                sheet[pad + ly][cx + lx] = flat[ly * frame_w + lx]
        cx += frame_w + pad
    return sheet_w, sheet_h, [v for row in sheet for v in row]


# ---------------------------------------------------------------------------
# GIF89a writer -- stdlib only, own LZW encoder (no `Image`/`gif` module
# anywhere in the stdlib to build on)
# ---------------------------------------------------------------------------

def _gif_lzw_encode(indices, min_code_size):
    """The standard GIF variant of LZW: codes start at `min_code_size + 1`
    bits, a Clear code (`1 << min_code_size`) resets the string table, an
    End code (`clear + 1`) closes the stream, the table grows one code per
    new string up to 12-bit codes (4096 entries) and then force-clears.
    Returns the packed code stream as raw bytes (LSB-first bit packing, the
    format GIF's image-data sub-blocks expect)."""
    clear_code = 1 << min_code_size
    end_code = clear_code + 1
    reset_code_size = min_code_size + 1
    reset_next_code = end_code + 1

    code_size = reset_code_size
    next_code = reset_next_code
    table = {(i,): i for i in range(clear_code)}

    bitbuf = 0
    bitcount = 0
    out = bytearray()

    def emit(code):
        nonlocal bitbuf, bitcount
        bitbuf |= code << bitcount
        bitcount += code_size
        while bitcount >= 8:
            out.append(bitbuf & 0xFF)
            bitbuf >>= 8
            bitcount -= 8

    emit(clear_code)
    w = ()
    for sym in indices:
        wc = w + (sym,)
        if wc in table:
            w = wc
            continue
        emit(table[w])
        if next_code < 4096:
            table[wc] = next_code
            next_code += 1
            if next_code > (1 << code_size) and code_size < 12:
                code_size += 1
        else:
            emit(clear_code)
            table = {(i,): i for i in range(clear_code)}
            next_code = reset_next_code
            code_size = reset_code_size
        w = (sym,)
    if w:
        emit(table[w])
    emit(end_code)
    if bitcount > 0:
        out.append(bitbuf & 0xFF)
    return bytes(out)


def _gif_sub_blocks(data):
    """Split raw bytes into GIF's length-prefixed sub-blocks (max 255 bytes
    each), terminated by a zero-length block."""
    out = bytearray()
    for i in range(0, len(data), 255):
        chunk = data[i:i + 255]
        out.append(len(chunk))
        out.extend(chunk)
    out.append(0)
    return bytes(out)


def write_gif(path, width, height, frames, palette, delays_cs, loop=True):
    """Write a GIF89a with one global color table (from the NCLR palette,
    padded to the next power of two) and one image per element of `frames`
    (each a flat `width * height` list of palette indices). `delays_cs` is
    the per-frame delay in centiseconds. Loops forever unless `loop` is
    False (Netscape 2.0 application extension, the de facto standard)."""
    n_colors = max(len(palette), 2)
    color_bits = 1
    while (1 << color_bits) < n_colors:
        color_bits += 1
    color_bits = min(color_bits, 8)
    table_size = 1 << color_bits

    gct = bytearray()
    for i in range(table_size):
        r, g, b = palette[i] if i < len(palette) else (0, 0, 0)
        gct.extend((r, g, b))

    out = bytearray()
    out += b"GIF89a"
    out += struct.pack("<HH", width, height)
    out.append(0x80 | (0x7 << 4) | (color_bits - 1))  # GCT present, color res, GCT size
    out.append(0)  # background color index
    out.append(0)  # pixel aspect ratio (unused)
    out += gct
    if loop:
        out += (b"\x21\xFF\x0BNETSCAPE2.0\x03\x01\x00\x00\x00")

    min_code_size = max(color_bits, 2)
    for i, flat in enumerate(frames):
        delay = delays_cs[i] if i < len(delays_cs) else (delays_cs[-1] if delays_cs else 10)
        out.append(0x21)  # extension introducer
        out.append(0xF9)  # graphic control label
        out.append(4)     # block size
        out.append(0x04)  # disposal method 1 (do not dispose) << 2, no transparency
        out += struct.pack("<H", delay)
        out.append(0)     # transparent color index (unused)
        out.append(0)     # block terminator

        out.append(0x2C)  # image descriptor
        out += struct.pack("<HHHH", 0, 0, width, height)
        out.append(0)     # no local color table, not interlaced

        lzw = _gif_lzw_encode(flat, min_code_size)
        out.append(min_code_size)
        out += _gif_sub_blocks(lzw)

    out.append(0x3B)  # trailer
    with open(path, "wb") as fh:
        fh.write(out)


# ---------------------------------------------------------------------------
# I/O
# ---------------------------------------------------------------------------

def indices_to_rgb(pixels, palette):
    n = len(palette)
    return [palette[p] if 0 < p < n else (255, 0, 255) if p >= n else (16, 16, 16)
            for p in pixels]


def load_block(narc_obj, species, local, block_size=BLOCK_STRIDE):
    idx = species * block_size + local
    raw = narc_obj.read(idx)
    kind, dec = narc.try_decompress(raw)
    return dec if dec is not None else raw


# ---------------------------------------------------------------------------
# Generalized block scanning -- classify a rig bundle's members by their own
# post-decompression magic instead of a fixed per-archive local-offset table.
#
# `a/0/0/4` (block size 20) and `a/0/7/2` (block size 8, the trainer battle
# sprite candidate -- see docs/ASSETS.md) do not share a local-offset layout:
# `a/0/0/4` duplicates both its NCGR sheets into 4 entries (0/1 small, 2/3
# main) and carries two NCLR palettes (normal/shiny) at the far end of a
# 20-wide block; `a/0/7/2` has exactly one NCGR per sheet, one NCLR, and an
# extra unidentified no-magic member, all inside an 8-wide block. Scanning by
# magic (picking the largest RGCN member as the "main" sheet, which also
# happens to correctly disambiguate `a/0/0/4`'s duplicates) works for both
# without hardcoding either archive's layout.
# ---------------------------------------------------------------------------

RIG_MAGICS = {
    b"RGCN": "ncgr",
    b"RECN": "ncer",
    b"RNAN": "nanr",
    b"RCMN": "nmcr",
    b"RAMN": "nmar",
    b"RLCN": "nclr",
}


def scan_rig_block(narc_obj, block_start, block_size):
    """Classify every sub-file of one block by its post-decompression magic.
    Returns `{kind: [(local_index, data), ...]}` in local-index order, `kind`
    one of `RIG_MAGICS`'s values. Sub-files with no recognized magic (e.g.
    `a/0/7/2`'s local 6, a plain `u32 == 1` with no NITRO header) are
    skipped, not raised on.

    Scanning **every** local in the block (not just the handful the old
    fixed-offset code ever touched) means this now decompresses locals no
    prior pass ever exercised -- e.g. `a/0/0/4`'s second near-identical
    bundle (local 9-17) and duplicate NCGR copies. A handful of those carry
    corrupt/truncated LZ11 streams (`narc.NarcError`) that have nothing to
    do with whichever member this call actually needs, so a decompression
    failure on one local must not sink the whole block -- it is treated the
    same as an unrecognized magic (skipped), not raised on. Regression-
    caught: without this, `--all` on `a/0/0/4` dropped from 712/714 to
    681/714 species, because a bad stream in an unused duplicate now killed
    species that decode perfectly well from their real members."""
    found = {}
    for local in range(block_size):
        idx = block_start + local
        if idx >= narc_obj.file_count:
            break
        raw = narc_obj.read(idx)
        try:
            _kind, dec = narc.try_decompress(raw)
        except Exception:  # noqa: BLE001 -- a corrupt/irrelevant local must not sink the block
            continue
        data = dec if dec is not None else raw
        if len(data) < 4:
            continue
        kind = RIG_MAGICS.get(data[:4])
        if kind:
            found.setdefault(kind, []).append((local, data))
    return found


def load_rig_block(narc_obj, block_start, block_size):
    """One rig bundle's raw (post-decompression) member bytes, selected by
    magic (`scan_rig_block`) rather than a fixed local-offset table. Returns
    `(ncgr_data, ncer_data, nmcr_data, nanr_data_or_None, nclr_data_or_None,
    nclr_all)`. NCGR/NCER/NMCR are required (raises `ValueError` naming the
    missing member if absent); NANR/NCLR are best-effort (animation and
    palette are refinements, not required for a bare cell layout).
    `nclr_all` is every NCLR member found in the block, in local order (e.g.
    `a/0/0/4`'s normal-then-shiny pair) -- see `build_bank_palette()` below,
    used to apply an OAM's palette-bank nibble as a row offset into the
    concatenation of all of a block's own NCLR palettes."""
    found = scan_rig_block(narc_obj, block_start, block_size)
    ncgrs = found.get("ncgr", [])
    if not ncgrs:
        raise ValueError(f"block at sub-file {block_start}: no RGCN (NCGR) member")
    ncgr_data = max(ncgrs, key=lambda t: len(t[1]))[1]  # largest = main sheet
    ncers = found.get("ncer", [])
    if not ncers:
        raise ValueError(f"block at sub-file {block_start}: no RECN (NCER) member")
    ncer_data = ncers[0][1]
    nmcrs = found.get("nmcr", [])
    if not nmcrs:
        raise ValueError(f"block at sub-file {block_start}: no RCMN (NMCR) member")
    nmcr_data = nmcrs[0][1]
    nanrs = found.get("nanr", [])
    nanr_data = nanrs[0][1] if nanrs else None
    nclrs = found.get("nclr", [])
    nclr_data = nclrs[0][1] if nclrs else None
    nclr_all = [d for _loc, d in nclrs]
    return ncgr_data, ncer_data, nmcr_data, nanr_data, nclr_data, nclr_all


def build_bank_palette(nclr_all):
    """Concatenate every NCLR member of a block, in local order, into one
    palette-bank table: rows 0-15 from the first NCLR, 16-31 from the
    second, and so on. This is what an OAM's `pal` (attr2 bits12-15, the
    4bpp OBJ palette-bank selector -- parsed since the rig-detachment pass
    but never applied before this one) actually indexes into, at least for
    the 2 of 713 `a/0/0/4` species (301, 327) that use a nonzero bank: both
    have exactly 2 NCLR members (a normal/shiny pair, same as every other
    species in this archive) and every OAM with `pal == 1` picks colors
    that -- checked by eye -- belong with the *second* NCLR's palette, not
    the first's. Returns `None` if there are no NCLR members at all (the
    caller falls back to `DEFAULT_PALETTE`)."""
    if not nclr_all:
        return None
    pal = []
    for data in nclr_all:
        pal.extend(bs.parse_nclr(data))
    return pal


DEFAULT_PALETTE = [(128, 128, 128)] * 16  # fallback only when a block has no NCLR at all


def render_one(n, species, out_dir, block_size=BLOCK_STRIDE, filename=None, cells_sheet=True):
    """Render one species' cells contact sheet (optional) and composed pose.
    Returns the pose (w, h) on success. Raises on any parse/decode failure
    (caller decides whether to catch, e.g. for --all skipping empty slots)."""
    ncgr_data, ncer_data, nmcr_data, nanr_data, nclr_data, nclr_all = load_rig_block(
        n, species * block_size, block_size)
    ncgr = parse_ncgr(ncgr_data)
    ncer = parse_ncer(ncer_data)
    palette = build_bank_palette(nclr_all) or DEFAULT_PALETTE
    n_pal_colors = len(palette)
    nmcr = parse_nmcr(nmcr_data)
    nanr = None
    if nanr_data is not None:
        try:
            nanr = parse_nanr(nanr_data)
        except Exception:  # noqa: BLE001 -- NANR delta is a best-effort refinement
            nanr = None

    if cells_sheet:
        sheet_w, sheet_h, sheet_flat = render_cells_contact_sheet(ncgr, ncer, palette)
        cells_path = os.path.join(out_dir, f"{species:04d}_cells.png")
        bs.write_png_rgb8(cells_path, sheet_w, sheet_h, indices_to_rgb(sheet_flat, palette))

    w, h, flat = compose_pose(ncgr, ncer, nmcr.rest_pose(), nanr=nanr, n_pal_colors=n_pal_colors)
    out_path = os.path.join(out_dir, filename or f"{species:04d}_pose.png")
    bs.write_png_rgb8(out_path, w, h, indices_to_rgb(flat, palette))
    return w, h, ncer, nmcr


def render_animation(n, species, out_dir, block_size=BLOCK_STRIDE, group=0, max_frames=32,
                      strip=True, gif_filename=None):
    """Render one species' animated node group (`Nmcr.groups[group]`) as a
    strip PNG (`NNNN_anim.png`, only when `strip` is True) and a looping GIF
    (`NNNN.gif` by default). Returns `(num_frames, gif_path)`. Raises on any
    parse/decode failure or a group with no working NANR (caller decides
    whether to catch)."""
    ncgr_data, ncer_data, nmcr_data, nanr_data, nclr_data, nclr_all = load_rig_block(
        n, species * block_size, block_size)
    ncgr = parse_ncgr(ncgr_data)
    ncer = parse_ncer(ncer_data)
    palette = build_bank_palette(nclr_all) or DEFAULT_PALETTE
    n_pal_colors = len(palette)
    nmcr = parse_nmcr(nmcr_data)
    if nanr_data is None:
        raise ValueError(f"species {species}: no NANR member (required for animation)")
    nanr = parse_nanr(nanr_data)  # required here, not best-effort

    if not (0 <= group < len(nmcr.groups)):
        raise ValueError(f"species {species} has no multi-cell group {group}")
    nodes = nmcr.groups[group].nodes
    if not nodes:
        raise ValueError(f"species {species} group {group} has no nodes")

    times = animation_frame_times(nanr, nodes, max_frames=max_frames)
    delays = animation_delays_cs(nanr, nodes, times)
    w, h, frames = compose_pose_multi(ncgr, ncer, nodes, nanr, times, n_pal_colors=n_pal_colors)

    if strip:
        sw, sh, sflat = render_animation_strip(w, h, frames)
        strip_path = os.path.join(out_dir, f"{species:04d}_anim.png")
        bs.write_png_rgb8(strip_path, sw, sh, indices_to_rgb(sflat, palette))

    gif_path = os.path.join(out_dir, gif_filename or f"{species:04d}.gif")
    gif_palette = _gif_palette(palette)
    n = len(gif_palette)
    gif_frames = [[p if 0 <= p < n else n - 1 for p in flat] for flat in frames]
    write_gif(gif_path, w, h, gif_frames, gif_palette, delays)
    return len(frames), gif_path


def _gif_palette(palette):
    """A palette for the GIF's color table matching `indices_to_rgb`'s PNG
    convention: index 0 is the dark-gray "transparent/background" index
    (not the NCLR's own color 0), every other index is the NCLR color at
    that slot."""
    gp = list(palette) if palette else [(0, 0, 0)]
    gp[0] = (16, 16, 16)
    return gp


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("species", type=int, nargs="?",
                     help="species/form index (25 = Pikachu). Not needed with --all.")
    ap.add_argument("--archive", default=ARCHIVE_PATH)
    ap.add_argument("--out", default=OUT_DIR)
    ap.add_argument("--block-size", type=int, default=BLOCK_STRIDE,
                     help="sub-files per species/class block (20 for a/0/0/4's rig; "
                     "8 for a/0/7/2's candidate trainer battle rig -- see "
                     "docs/ASSETS.md). Block members are found by their own "
                     "post-decompression magic (scan_rig_block), not by a fixed "
                     "local-offset table, so this is the only per-archive knob needed.")
    ap.add_argument("--group", type=int, default=0,
                     help="which NMCR multi-cell group to pose/animate (0 default; "
                     "group 1 is a second, independent animation on the same rig "
                     "topology, not a corrective rest assembly -- see docs/ASSETS.md)")
    ap.add_argument("--frame", type=int, default=0,
                     help="elapsed time in NDS frames for a single --pose render "
                     "(0 = the classic static rest pose)")
    ap.add_argument("--cells-only", action="store_true",
                     help="only render the per-cell contact sheet, skip the pose")
    ap.add_argument("--pose", action="store_true",
                     help="render the composed pose (NNNN_pose.png). This is the "
                     "default for single-species mode unless --cells-only is given; "
                     "explicit for clarity / parity with --all.")
    ap.add_argument("--anim", action="store_true",
                     help="render an animation strip (NNNN_anim.png) and looping "
                     "GIF (NNNN.gif) for the given species, using --group's node "
                     "list over one full loop (or the first 32 distinct frame "
                     "times, whichever is smaller)")
    ap.add_argument("--max-frames", type=int, default=32,
                     help="cap on distinct frame times sampled per animation (32 default)")
    ap.add_argument("--all", action="store_true",
                     help="process every species/form index in the archive, writing "
                     "build/assets/rig/NNNN.png for each (skips slots that don't "
                     "parse as a valid NCGR/NCER/NMCR bundle, e.g. empty/padding "
                     "block indices)")
    ap.add_argument("--anim-all", action="store_true",
                     help="render a looping GIF (build/assets/rig/NNNN.gif) for "
                     "every species in the archive's --group animation (no strip "
                     "PNGs; skips slots that don't parse or have no NANR)")
    args = ap.parse_args(argv)

    os.makedirs(args.out, exist_ok=True)
    n = narc.parse_file(args.archive)

    if args.anim_all:
        max_species = n.file_count // args.block_size
        ok = 0
        skipped = 0
        for sp in range(max_species):
            try:
                render_animation(n, sp, args.out, block_size=args.block_size, group=args.group,
                                  max_frames=args.max_frames, strip=False)
                ok += 1
            except Exception as exc:  # noqa: BLE001 -- best-effort batch, log and continue
                skipped += 1
                print(f"[!] species {sp}: skipped ({exc})")
        print(f"[*] --anim-all: {ok} GIFs rendered, {skipped} skipped, out={args.out}")
        return 0

    if args.all:
        max_species = n.file_count // args.block_size
        ok = 0
        skipped = 0
        for sp in range(max_species):
            try:
                render_one(n, sp, args.out, block_size=args.block_size,
                           filename=f"{sp:04d}.png", cells_sheet=False)
                ok += 1
            except Exception as exc:  # noqa: BLE001 -- best-effort batch, log and continue
                skipped += 1
                print(f"[!] species {sp}: skipped ({exc})")
        print(f"[*] --all: {ok} rendered, {skipped} skipped, out={args.out}")
        return 0

    if args.species is None:
        ap.error("species is required unless --all is given")

    ncgr_data, ncer_data, nmcr_data, nanr_data, nclr_data, nclr_all = load_rig_block(
        n, args.species * args.block_size, args.block_size)
    ncgr = parse_ncgr(ncgr_data)
    ncer = parse_ncer(ncer_data)
    palette = build_bank_palette(nclr_all) or DEFAULT_PALETTE
    n_pal_colors = len(palette)

    print(f"[*] species {args.species}: NCGR {ncgr.tile_num_x}x{ncgr.tile_num_y} tiles "
          f"({ncgr.tile_count} total), NCER {ncer.num_cells} cells "
          f"({sum(c.num_oam for c in ncer.cells)} OAMs)")

    sheet_w, sheet_h, sheet_flat = render_cells_contact_sheet(ncgr, ncer, palette)
    cells_path = os.path.join(args.out, f"{args.species:04d}_cells.png")
    bs.write_png_rgb8(cells_path, sheet_w, sheet_h, indices_to_rgb(sheet_flat, palette))
    print(f"[*] wrote {cells_path} ({sheet_w}x{sheet_h}, {ncer.num_cells} cells)")

    if args.cells_only:
        return 0

    nmcr = parse_nmcr(nmcr_data)
    print(f"[*] NMCR: {nmcr.num_multi_cell} multi-cell groups, "
          f"{len(nmcr.nodes)} node records, rest pose uses group 0's "
          f"{len(nmcr.rest_pose())} nodes")
    nanr = None
    if nanr_data is not None:
        try:
            nanr = parse_nanr(nanr_data)
            print(f"[*] NANR: {nanr.num_sequences} sequences, "
                  f"{nanr.num_elements} frame entries")
        except Exception as exc:  # noqa: BLE001 -- NANR delta is best-effort
            nanr = None
            print(f"[!] NANR: not applied ({exc})")
    else:
        print("[!] NANR: no member found in this block")

    if args.anim:
        if not (0 <= args.group < len(nmcr.groups)):
            ap.error(f"species {args.species} has no multi-cell group {args.group}")
        num_frames, gif_path = render_animation(
            n, args.species, args.out, block_size=args.block_size,
            group=args.group, max_frames=args.max_frames)
        strip_path = os.path.join(args.out, f"{args.species:04d}_anim.png")
        print(f"[*] animation: group {args.group}, {num_frames} distinct frame "
              f"times sampled (cap {args.max_frames})")
        print(f"[*] wrote {strip_path}")
        print(f"[*] wrote {gif_path}")
        return 0

    group = nmcr.groups[args.group].nodes if 0 <= args.group < len(nmcr.groups) \
        else nmcr.rest_pose()
    w, h, flat = compose_pose(ncgr, ncer, group, nanr=nanr, t=args.frame, n_pal_colors=n_pal_colors)
    out_path = os.path.join(args.out, f"{args.species:04d}_pose.png")
    bs.write_png_rgb8(out_path, w, h, indices_to_rgb(flat, palette))
    print(f"[*] wrote {out_path} ({w}x{h})")
    return 0


if __name__ == "__main__":
    sys.exit(main())
