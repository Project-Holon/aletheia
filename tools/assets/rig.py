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
--------------------------------------------------------------------------
Usage
--------------------------------------------------------------------------
    python tools/assets/rig.py 25                  # species 25 (Pikachu)
    python tools/assets/rig.py 25 --cells-only      # contact sheet only
    python tools/assets/rig.py 25 --pose            # contact sheet + pose
    python tools/assets/rig.py --all                # every species/form
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402
import battle_sprite as bs  # noqa: E402  (parse_nclr, PNG writer, bgr555)

ARCHIVE_PATH = os.path.join("extract", "data", "a", "0", "0", "4")
OUT_DIR = os.path.join("build", "assets", "rig")

BLOCK_STRIDE = 20
LOCAL_NCGR_MAIN = 2       # main tile sheet
LOCAL_NCER = 4            # cell bank
LOCAL_NANR = 5            # cell animation: names every node's cell
LOCAL_NMCR = 6            # multi-cell resource (rest pose)
LOCAL_PALETTE_NORMAL = 18

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
        self.tile_data = body[data_ofs:data_ofs + data_size]
        self.tile_count = len(self.tile_data) // TILE_BYTES_4BPP
        self.width = tile_num_x * 8
        self.height = tile_num_y * 8
        self.pixels = self._unpack()

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
    __slots__ = ("num_oam", "cell_attr", "oams")

    def __init__(self, num_oam, cell_attr, oams):
        self.num_oam = num_oam
        self.cell_attr = cell_attr
        self.oams = oams


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
        cell_data_ofs, mapping_type, _reserved = struct.unpack_from("<III", body, 4)
        self.num_cells = num_cells
        self.mapping_type = mapping_type

        cell_hdrs = []
        for i in range(num_cells):
            off = cell_data_ofs + i * 8
            num_oam, cell_attr, oam_ofs = struct.unpack_from("<HHI", body, off)
            cell_hdrs.append((num_oam, cell_attr, oam_ofs))

        oam_arr_start = cell_data_ofs + num_cells * 8
        self.cells = []
        for num_oam, cell_attr, oam_ofs in cell_hdrs:
            oams = []
            for i in range(num_oam):
                off = oam_arr_start + oam_ofs + i * 6
                a0, a1, a2 = struct.unpack_from("<HHH", body, off)
                oams.append(Oam(a0, a1, a2))
            self.cells.append(Cell(num_oam, cell_attr, oams))


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
#                                  this tool; the paired local-5 NANR sub-
#                                  file is used instead, see LOCAL_NANR)
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
        self.num_multi_cell = num_multi_cell
        self.signature = sig

        self.groups = []
        all_nodes = []
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
        self.nodes = all_nodes

    def rest_pose(self):
        """The first multi-cell group's own node list -- a complete,
        self-contained assembly (see module docstring)."""
        if not self.groups:
            return []
        return self.groups[0].nodes


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
        self._frame_ofs = frame_ofs
        self._frame_data_ofs = frame_data_ofs

        self.sequences = []
        for i in range(num_seq):
            off = seq_ofs + i * 16
            n_frames, loop_start = struct.unpack_from("<HH", body, off)
            anim_type, play_mode, frames_ofs = struct.unpack_from("<III", body, off + 4)
            self.sequences.append(
                NanrSequence(n_frames, loop_start, anim_type, play_mode, frames_ofs))

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
        """Return (cellIdx, px, py) for one frame, decoding whichever of the
        three frame-data record shapes this sequence's element type selects,
        or None if unavailable. Scale/rotation are ignored: every frame-0
        record in this archive reads rotZ 0 and sx/sy 4096 (FX32 1.0)."""
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
            return cell_idx, 0, 0
        if etype == ANIM_ELEMENT_T:
            px, py = struct.unpack_from("<hh", self._body, base + 4)
            return cell_idx, px, py
        px, py = struct.unpack_from("<hh", self._body, base + 12)
        return cell_idx, px, py


def parse_nanr(data):
    return Nanr(data)


# ---------------------------------------------------------------------------
# Compositing
# ---------------------------------------------------------------------------

def render_oam(ncgr, oam):
    """Return one OAM's pixel block (rows of 4bpp indices), flips applied.

    The OAM's tile index is a **two-dimensional** block index into the sheet
    (row `idx // tile_num_x`, column `idx % tile_num_x`), so an OAM wider or
    taller than one block steps by `tile_num_x` per row, not by its own
    width. Species 25's cell 0 proves this from the data alone: a 16x16 OAM
    at index 99 sits next to an 8x16 OAM at index 101, which can only avoid
    overlapping if the first consumes 99/100 and 131/132 rather than
    99/100/101/102."""
    tiles_w = oam.w // 8
    tiles_h = oam.h // 8
    px = [[0] * oam.w for _ in range(oam.h)]
    for ty in range(tiles_h):
        for tx in range(tiles_w):
            tile_index = oam.tile_idx + ty * ncgr.tile_num_x + tx
            nib = ncgr.block_pixels(tile_index)
            for ly in range(8):
                for lx in range(8):
                    px[ty * 8 + ly][tx * 8 + lx] = nib[ly * 8 + lx]
    if oam.hflip:
        px = [row[::-1] for row in px]
    if oam.vflip:
        px = px[::-1]
    return px


def compose_pose(ncgr, ncer, nodes, nanr=None, frame=0):
    """Blit every node's cell onto a shared canvas, following the composer
    the game itself runs (`func_020643CC` walks the nodes, `func_0206419C`
    turns one node's current animation frame into a cell plus a translation;
    see the module docstring for the byte-level derivation):

      * **Cell selection**: a node names an *animation sequence* through its
        `anim_seq_idx` (`func_020627D8` indexes the NANR bank's sequence
        array with it, 16-byte stride). That sequence's current frame entry
        points at a frame-data record whose first u16 is the NCER cell index
        (`func_0206419C` +0x18: `func_02062D40` derefs the frame entry, then
        `func_0206285C` looks the cell up by the u16 at its +0). The node's
        own `cell_anim_slot` byte is not a cell index at all: it is the slot
        in the caller's array of 0x5C-byte cell-animation states
        (`func_02064648`). A node whose sequence has no such frame is
        skipped.

      * **Placement**: the node's (posX, posY) (`func_020643CC` +0x250,
        `func_020640DC`) plus the frame's own (px, py) translation
        (`func_0206419C`, SRT and T records both) is a straight translation
        of the whole cell; each OAM keeps its own cell-local (x, y). Scale
        is identity and rotation 0 at frame 0 (sx/sy read 4096 == FX32 1.0),
        so no affine transform is applied.

      * **Draw order**: nodes are emitted into the hardware OAM list in
        array order, and a lower OAM index draws in front, so the nodes are
        painted back-to-front here (last node first)."""
    placements = []  # (abs_x, abs_y, px_rows)
    minx = miny = 10**9
    maxx = maxy = -10**9
    for node in reversed(nodes):
        fd = nanr.frame_data(node.anim_seq_idx, frame) if nanr is not None else None
        if fd is None:
            continue
        cell_idx, px, py = fd
        if cell_idx >= len(ncer.cells):
            continue
        cell = ncer.cells[cell_idx]
        if not cell.oams:
            continue
        for oam in cell.oams:
            rows = render_oam(ncgr, oam)
            ax = node.x + px + oam.x
            ay = node.y + py + oam.y
            placements.append((ax, ay, rows))
            minx = min(minx, ax)
            miny = min(miny, ay)
            maxx = max(maxx, ax + oam.w)
            maxy = max(maxy, ay + oam.h)

    if not placements:
        return 1, 1, [0]

    margin = 2
    ox = -minx + margin
    oy = -miny + margin
    width = (maxx - minx) + margin * 2
    height = (maxy - miny) + margin * 2
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
    flat = [v for row in canvas for v in row]
    return width, height, flat


# ---------------------------------------------------------------------------
# Contact sheet (fallback / diagnostic deliverable)
# ---------------------------------------------------------------------------

def render_cells_contact_sheet(ncgr, ncer, palette):
    """Render each cell of the NCER individually (own local bounding box),
    laid out left-to-right in a contact sheet. Used both as the mission's
    documented fallback and as a useful debugging aid for the main pose."""
    cell_images = []
    for cell in ncer.cells:
        if not cell.oams:
            cell_images.append((1, 1, [0]))
            continue
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
            rows = render_oam(ncgr, oam)
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
        cell_images.append((w, h, [v for row in canvas for v in row]))

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


# ---------------------------------------------------------------------------
# I/O
# ---------------------------------------------------------------------------

def indices_to_rgb(pixels, palette):
    n = len(palette)
    return [palette[p] if 0 < p < n else (255, 0, 255) if p >= n else (16, 16, 16)
            for p in pixels]


def load_block(narc_obj, species, local):
    idx = species * BLOCK_STRIDE + local
    raw = narc_obj.read(idx)
    kind, dec = narc.try_decompress(raw)
    return dec if dec is not None else raw


def render_one(n, species, out_dir, filename=None, cells_sheet=True):
    """Render one species' cells contact sheet (optional) and composed pose.
    Returns the pose (w, h) on success. Raises on any parse/decode failure
    (caller decides whether to catch, e.g. for --all skipping empty slots)."""
    ncgr = parse_ncgr(load_block(n, species, LOCAL_NCGR_MAIN))
    ncer = parse_ncer(load_block(n, species, LOCAL_NCER))
    palette = bs.parse_nclr(load_block(n, species, LOCAL_PALETTE_NORMAL))
    nmcr = parse_nmcr(load_block(n, species, LOCAL_NMCR))
    try:
        nanr = parse_nanr(load_block(n, species, LOCAL_NANR))
    except Exception:  # noqa: BLE001 -- NANR delta is a best-effort refinement
        nanr = None

    if cells_sheet:
        sheet_w, sheet_h, sheet_flat = render_cells_contact_sheet(ncgr, ncer, palette)
        cells_path = os.path.join(out_dir, f"{species:04d}_cells.png")
        bs.write_png_rgb8(cells_path, sheet_w, sheet_h, indices_to_rgb(sheet_flat, palette))

    w, h, flat = compose_pose(ncgr, ncer, nmcr.rest_pose(), nanr=nanr)
    out_path = os.path.join(out_dir, filename or f"{species:04d}_pose.png")
    bs.write_png_rgb8(out_path, w, h, indices_to_rgb(flat, palette))
    return w, h, ncer, nmcr


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("species", type=int, nargs="?",
                     help="species/form index (25 = Pikachu). Not needed with --all.")
    ap.add_argument("--archive", default=ARCHIVE_PATH)
    ap.add_argument("--out", default=OUT_DIR)
    ap.add_argument("--anim", type=int, default=0, help="animation index (informational; "
                     "only animation 0 / the NMCR rest pose is actually rendered)")
    ap.add_argument("--frame", type=int, default=0, help="frame index (informational; "
                     "see module docstring -- frame 0 is assumed == rest pose)")
    ap.add_argument("--cells-only", action="store_true",
                     help="only render the per-cell contact sheet, skip the pose")
    ap.add_argument("--pose", action="store_true",
                     help="render the composed pose (NNNN_pose.png). This is the "
                     "default for single-species mode unless --cells-only is given; "
                     "explicit for clarity / parity with --all.")
    ap.add_argument("--all", action="store_true",
                     help="process every species/form index in the archive, writing "
                     "build/assets/rig/NNNN.png for each (skips slots that don't "
                     "parse as a valid NCGR/NCER/NMCR bundle, e.g. empty/padding "
                     "block indices)")
    args = ap.parse_args(argv)

    os.makedirs(args.out, exist_ok=True)
    n = narc.parse_file(args.archive)

    if args.all:
        max_species = n.file_count // BLOCK_STRIDE
        ok = 0
        skipped = 0
        for sp in range(max_species):
            try:
                render_one(n, sp, args.out, filename=f"{sp:04d}.png", cells_sheet=False)
                ok += 1
            except Exception as exc:  # noqa: BLE001 -- best-effort batch, log and continue
                skipped += 1
                print(f"[!] species {sp}: skipped ({exc})")
        print(f"[*] --all: {ok} rendered, {skipped} skipped, out={args.out}")
        return 0

    if args.species is None:
        ap.error("species is required unless --all is given")

    ncgr = parse_ncgr(load_block(n, args.species, LOCAL_NCGR_MAIN))
    ncer = parse_ncer(load_block(n, args.species, LOCAL_NCER))
    palette = bs.parse_nclr(load_block(n, args.species, LOCAL_PALETTE_NORMAL))

    print(f"[*] species {args.species}: NCGR {ncgr.tile_num_x}x{ncgr.tile_num_y} tiles "
          f"({ncgr.tile_count} total), NCER {ncer.num_cells} cells "
          f"({sum(c.num_oam for c in ncer.cells)} OAMs)")

    sheet_w, sheet_h, sheet_flat = render_cells_contact_sheet(ncgr, ncer, palette)
    cells_path = os.path.join(args.out, f"{args.species:04d}_cells.png")
    bs.write_png_rgb8(cells_path, sheet_w, sheet_h, indices_to_rgb(sheet_flat, palette))
    print(f"[*] wrote {cells_path} ({sheet_w}x{sheet_h}, {ncer.num_cells} cells)")

    if args.cells_only:
        return 0

    nmcr = parse_nmcr(load_block(n, args.species, LOCAL_NMCR))
    print(f"[*] NMCR: {nmcr.num_multi_cell} multi-cell groups, "
          f"{len(nmcr.nodes)} node records, rest pose uses group 0's "
          f"{len(nmcr.rest_pose())} nodes")
    try:
        nanr = parse_nanr(load_block(n, args.species, LOCAL_NANR))
        print(f"[*] NANR: {nanr.num_sequences} sequences, "
              f"{nanr.num_elements} frame entries")
    except Exception as exc:  # noqa: BLE001 -- NANR delta is best-effort
        nanr = None
        print(f"[!] NANR: not applied ({exc})")

    w, h, flat = compose_pose(ncgr, ncer, nmcr.rest_pose(), nanr=nanr)
    out_path = os.path.join(args.out, f"{args.species:04d}_pose.png")
    bs.write_png_rgb8(out_path, w, h, indices_to_rgb(flat, palette))
    print(f"[*] wrote {out_path} ({w}x{h})")
    return 0


if __name__ == "__main__":
    sys.exit(main())
