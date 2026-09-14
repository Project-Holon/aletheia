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
    local 5    RNAN/NANR   cell animation (not used here)
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

**Tile addressing: dense (tile_idx * 32 bytes), not the declared 256-byte
mapping-type-4 boundary.** The fifth lane pass found the NCER's declared
`mapping_type = 4` boundary does not reproduce a clean image against this
NCGR, but `tile_idx * 32` (packing tiles back-to-back with no boundary
padding, matching how the NCGR's own tile array is laid out) does. This
module uses the confirmed-working dense addressing.

--------------------------------------------------------------------------
NMCR (RCMN) format -- multi-cell resource: rest-pose node placement
--------------------------------------------------------------------------
Recovered by inspection this pass, no outside documentation used (the
`RCMN`/`RAMN` expansion guess itself -- "multi-cell resource" / "multi-cell
animation resource" -- is from docs/ASSETS.md's earlier inventory pass).
16-byte common file header, one block, magic `KBCM` (on-disk reversal of
"MCBK", Multi-Cell Bank). The MCBK body's own sub-header IS self-relative
(each offset field is added to its OWN field position to get the absolute
target -- a different convention from NCER's KBEC above, confirmed by the
two offset fields both landing exactly on the start of the two tables that
follow):

    0x00  u16  num_multi_cell    (2 for species 25: two alternate posed
                                   assemblies sharing one node table)
    0x02  u16  signature         0xBEEF constant (seen verbatim in NMAR
                                  too, a resource-validity marker)
    0x04  u32  mc_array_ofs      self-relative -> multi-cell descriptor
                                  array (10 bytes/entry, fields not fully
                                  decoded: entry 0 for species 25 is
                                  (0, 0, 10, 10, 80), entry 1 is
                                  (0, 7, 8, -19, 32); the third field lines
                                  up with a node count for entry 0 -- see
                                  below -- but the rest is not pinned down)
    0x08  u32  node_array_ofs    self-relative -> node placement array
    0x0C  u32  reserved (0)
    0x10  u32  reserved (0)
    0x14  u16  unk (10 for species 25; matches entry-0's node count)
    0x16  u16  unk (10 for species 25)

Node placement array: fixed 8-byte records (no length prefix; count is
implied by the enclosing multi-cell entry / block size), found by locating
every record's constant tag byte (always 0x20) at a fixed 8-byte stride
end-to-end across the whole array -- for species 25, 19 records fit the
152-byte array exactly with the tag landing at the same relative offset in
every one:

    0x00  s16  label_index   index into the paired NCER's LBAL name table
                              (20 names for species 25: 10 body-part names,
                              then the same 10 again with an "_2" suffix --
                              docs/ASSETS.md's fifth pass already read
                              these as Japanese body-part words). Verified:
                              across all 19 records the label indices cover
                              0-19 with exactly one collision (7 "te02" is
                              skipped in favour of 17 "te02_2"), i.e. one
                              instance of every named part.
    0x02  s16  x              node placement x offset (small signed pixel
                              delta, -6..17 across the sample)
    0x04  s16  y              node placement y offset (-35..9)
    0x06  u8   tag            constant 0x20 in every record sampled
    0x07  u8   cell_index     which of the paired NCER's cells to draw for
                              this node; cycles 1,2,...,9,0 with period 10
                              across the 19 records (i.e. `(record_index +
                              1) % 10`) -- consistent with the NCER's cell
                              array being authored in a fixed rotation
                              rather than the cell index correlating with
                              body-part identity directly.

The first `num_multi_cell` entry's node count (10 for species 25) lines up
exactly with the array's first 10 records covering every label 0-9 once
(with the label-7/17 substitution above already inside that span) -- a
complete, non-duplicated one-of-each-part assembly. This module renders
that first 10-record span as "multi-cell 0" / the rest pose. The second
multi-cell entry's exact node sub-range was not pinned down (the fields
in its 10-byte descriptor don't cleanly resolve to a start+count the way
entry 0's does) and is not used by this tool.

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
NANR (RNAN) format, corrected -- frame-entry / frame-data indirection
(eighth lane pass; supersedes the seventh pass's "raw curve value" reading)
--------------------------------------------------------------------------
The mission for this pass supplied the generic NNS_G2D NANR layout (frame
entries distinct from frame-data records, three frame-data shapes keyed by
element type) and asked for byte-level re-verification against species 25.
That re-verification **holds, with the frame-entry/frame-data split fully
confirmed and the frame-data shape pinned down empirically**:

`KNBA` (ABNK) body, unchanged from the seventh pass's header read
(block-relative, all three offsets exact): `num_sequences(u16)=20,
num_elements(u16)=403, seq_array_ofs(u32)=24, elem_array_ofs(u32)=344,
elem_array_end(u32)=3568`.

**Element-array records are FRAME ENTRIES, not raw curve values** -- the
seventh pass's `value(s32), six(u16), sentinel(u16)=0xBEEF` read is the
*same bytes*, re-verified and reinterpreted: `sentinel` is 0xBEEF in **all
403 records without exception** (confirmed by direct scan, not sampling),
and the field the seventh pass called `six` (claimed constant 6) actually
**varies** (2, 3, 4, 6, 12, 36, 50, 84, ... -- checked directly, the
"constant 6" was a sampling artifact from only inspecting the first few
records). This is exactly the mission's `{offset_to_frame_data(u32),
duration(u16), pad(u16)=0xBEEF}` frame-entry shape: `offset_to_frame_data`
(the seventh pass's "value") is a **byte offset**, not a curve sample, and
`duration` (the seventh pass's "six") is a real per-frame duration that
varies as a duration should.

**`offset_to_frame_data` is relative to the byte immediately after the
element array** (i.e. relative to `elem_array_end`, not to the file or
block start) -- confirmed two ways: (1) every one of the 403 offsets is
`0 <= offset <= 1480`, and the region from `elem_array_end` to the body's
actual end (`5064` for species 25) is exactly `1496` bytes, so `1480 + 16
== 1496` lands the largest offset's record exactly at the body boundary;
(2) decoding the pointed-to bytes at that base as frame-data (next
paragraph) produces small, sane field values, while every other tried base
(body-relative, block-relative, self-relative-to-the-offset-field)
produced nonsense.

**Frame-data record shape: type 1 (SRT), 16 bytes, confirmed by a fixed-
point tell**: `{cellIdx(u16), rotZ(u16), sx(s32), sy(s32), px(s16),
py(s16)}`. Decoded at species 25's frame-data offsets, `sx`/`sy` read as
**4096 in the overwhelming majority of records** -- 4096 = 0x1000 = 1<<12,
i.e. **1.0 in NNS_G2D's standard FX32 20.12 fixed-point format**, exactly
the "no scaling" identity value a rest-pose/frame-0 SRT record should
carry. This is strong, format-specific confirmation of the mission's type-1
SRT shape (not a guess dressed up -- 4096 as a bare integer would be an
absurd pixel-scale value, but is the textbook FX32 identity scale).
`cellIdx` in these records reads small integers in the valid 0-10 cell
range (mostly 10, occasionally 9), `px`/`py` read small values (0-3 in the
sample), consistent with a translation curve whose frame-0 value is at or
near the animation's rest position -- matching the seventh pass's own
triangle-wave observation (previously misattributed to *element array*
values 0/8/16/24/... which were actually **byte offsets into this table**,
not curve samples; re-reading the *pointed-to* `py` fields directly gives
the much smaller, physically sensible 0/1/2/3/2 triangle wave that was
actually the curve).

**Not every offset is 16-byte-aligned** (315 of 403 are multiples of 16;
most of the rest are multiples of 8, consistent with some sequences using
the mission's 8-byte type-2 "T" shape `{cellIdx(u16), pad(u16), px(s16),
py(s16)}` instead of type 1 -- this tool tries 16 bytes first for any
lookup and does not fully disambiguate per-sequence which of the three
shapes applies, since the sequence-record field that should select it
(constant `1` across all 20 of species 25's sequences, see below) does not
visibly vary here). Type-0 `{cellIdx(u16)}` (2 bytes) is not exercised by
this dataset (no offsets that only make sense at 2-byte granularity were
found) and is unimplemented.

**Sequence record, reconciled with the mission's field list**: the
sequence record is still the seventh pass's 16-byte, 5-field struct
`elem_start(u32), num_frames(u16), field_c(u16)=1 constant,
field_d(u16... read as u32)=2 constant, field_e(u32)`. Mapping this onto
the mission's named fields `{num_frames, start_frame_index, animation_type,
play_mode, offset_to_frames}`: `elem_start` is `start_frame_index` (an
*index* into the element/frame-entry array, not a byte offset -- re-
confirmed, every sequence's `elem_start + num_frames` stays inside
`num_elements=403`), `num_frames` matches by name and behavior directly,
`field_c`/`field_d` are plausibly `animation_type`/`play_mode` (both
constant across every one of species 25's 20 sequences, so their exact
value-to-meaning mapping isn't distinguishable from this one species'
data). **`field_e` does NOT behave as `offset_to_frames`** in the sense of
"a pointer to this sequence's own frame-data sub-table": it increases
monotonically across the sequence array (0, 144, 392, 536, ... 3216) but by
amounts that don't correlate with `num_frames * any constant frame-data
stride`, and its largest value (3216) is smaller than `elem_array_end`
(3568) -- i.e. it points *inside* the frame-entry array, not at the
frame-data region past it. Left unresolved and unused by this tool (frame
lookups go through `elem_start` into the shared frame-entry array, which is
sufficient to reach frame 0 of every sequence).

--------------------------------------------------------------------------
NMCR (RCMN) node record, re-verified against the mission's proposed layout
-- mission's literal field order does NOT match this game's bytes
--------------------------------------------------------------------------
The mission proposed each node record as `{cellAnimIdx(u16), nodeAttr(u8),
pad(u8), posX(s16), posY(s16)}` (8 bytes). This tool re-decoded species 25's
19 node records under that exact layout and compared against the sixth/
seventh pass's `{label_index(s16), x(s16), y(s16), tag(u8)=0x20,
cell_index(u8)}` reading, byte-for-byte, **and the mission's literal layout
produces nonsense while the existing reading remains internally
consistent**:

- Mission layout's `posY` (bytes 6-7 as a signed 16-bit int) evaluates to
  32, 288, 544, 800, 1056, ... for successive nodes -- a suspiciously exact
  arithmetic progression (`256 * cell_index + 32`) that is just the
  existing reading's constant tag byte `0x20` (=32) in the low byte and its
  rotating `cell_index` (0-9) in the high byte, reinterpreted as one 16-bit
  value. This is not a plausible pixel position for a small overworld
  sprite's body part.
- The existing reading's `x`/`y` (bytes 2-5, two separate s16 fields) decode
  as small values (-35..9) that order top-to-bottom by real body-part
  height exactly as the seventh pass found (ears highest, feet lowest) --
  a physically sensible placement signal that the mission's split
  `nodeAttr(u8)/pad(u8)` reading of the same two bytes would destroy.

**Conclusion: the mission's abstract NMCR node description (index + attr
byte + position) is the right shape of idea -- an index field, then
placement data -- but this game's concrete on-disk field order is not the
generic layout as stated.** This tool keeps the sixth/seventh pass's
verified reading (`label_index` doubles as the mission's `cellAnimIdx`,
since it was already independently confirmed to be a valid index into
NANR's 20-entry sequence array by shared LBAL name matching) rather than
adopting the mission's literal byte order, which measurably produces worse
(nonsensical) numbers on this data.

**`cell_index`'s real role, revisited**: this pass tried using NANR's own
frame-0 `cellIdx` (previous section) as an alternative per-node cell
selector instead of NMCR's own `cell_index` byte. It does not work as a
drop-in replacement -- across species 25's 10 rest-pose nodes, the NANR
frame-0 `cellIdx` reads `10` for 7 of them (one shared cell for most
"different" body parts, which cannot be right for an assembled figure with
visually distinct parts), so **this tool keeps using NMCR's own
`cell_index` byte for cell selection**, and additionally now applies each
node's NANR sequence's frame-0 `(px, py)` as a small delta on top of the
NMCR node's `(x, y)` (hypothesis (c) from the seventh pass, actually
executed this time) -- since the deltas are mostly `(0, 0)` or a pixel or
two, this measurably changes almost nothing about the render, consistent
with frame 0 being at or near the rest position.

**Placement strategy re-tested, not changed**: the mission's literal
placement formula (`node.posX + data.px + oam.x`, i.e. summing the node
position directly onto each OAM's own hardware x/y with no re-centering)
was re-run this pass (species 25, using NMCR's own verified `cell_index`)
and, **again**, produces a scattered arrangement with no coherent
silhouette -- the same failure mode the sixth and seventh passes already
documented for the "sum" strategy, now confirmed a third time on the
byte-corrected data. The seventh pass's bbox-center-anchor strategy (place
each cell's own OAM-bounding-box *center* at the node's `(x, y)`, preserving
each OAM's position relative to that center) remains the best-looking of
every strategy tried and is what `compose_pose()` still uses. **The
mission's "recognizable creature" bar is still not met for any of the
three species rendered this pass** -- see docs/ASSETS.md for the full,
honest writeup; this is reported directly rather than dressed up.

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
LOCAL_NANR = 5            # cell animation (frame-0 SRT delta)
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
        bitdepth, _pad, _flag = struct.unpack_from("<IHH", body, 4)
        _unk1, data_size, data_ofs = struct.unpack_from("<III", body, 12)
        self.tile_num_x = tile_num_x
        self.tile_num_y = tile_num_y
        self.tile_data = body[data_ofs:data_ofs + data_size]
        self.tile_count = len(self.tile_data) // TILE_BYTES_4BPP

    def tile_nibbles(self, tile_index):
        """Return the 64 pixel-index nibbles (row-major, 8x8) for one tile."""
        off = tile_index * TILE_BYTES_4BPP
        tile = self.tile_data[off:off + TILE_BYTES_4BPP]
        out = [0] * 64
        for ly in range(8):
            row = tile[ly * 4:ly * 4 + 4]
            for lx4 in range(4):
                b = row[lx4]
                out[ly * 8 + lx4 * 2] = b & 0x0F
                out[ly * 8 + lx4 * 2 + 1] = (b >> 4) & 0x0F
        return out


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

class NanrSequence:
    __slots__ = ("elem_start", "num_frames")

    def __init__(self, elem_start, num_frames):
        self.elem_start = elem_start
        self.num_frames = num_frames


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
        num_seq, num_elem = struct.unpack_from("<HH", body, 0)
        seq_ofs, elem_ofs, elem_end = struct.unpack_from("<III", body, 4)
        self.num_sequences = num_seq
        self.num_elements = num_elem
        self._elem_ofs = elem_ofs
        self._frame_data = body[elem_end:]

        self.sequences = []
        for i in range(num_seq):
            off = seq_ofs + i * 16
            elem_start, num_frames = struct.unpack_from("<IH", body, off)
            self.sequences.append(NanrSequence(elem_start, num_frames))

    def frame_entry(self, seq_index, frame_index=0):
        """Return (offset_to_frame_data, duration) for one frame entry, or
        None if the sequence has no frames at that index (e.g. the empty
        feet curves, num_frames=0)."""
        if not (0 <= seq_index < len(self.sequences)):
            return None
        seq = self.sequences[seq_index]
        if not (0 <= frame_index < seq.num_frames):
            return None
        off = self._elem_ofs + (seq.elem_start + frame_index) * 8
        fofs, duration, _sentinel = struct.unpack_from("<iHH", self._body, off)
        return fofs, duration

    def frame_data_srt(self, seq_index, frame_index=0):
        """Return (cellIdx, rotZ, sx, sy, px, py) for one frame's type-1 SRT
        frame-data record, or None if unavailable. sx/sy are FX32 (20.12
        fixed point, 4096 == 1.0)."""
        entry = self.frame_entry(seq_index, frame_index)
        if entry is None:
            return None
        fofs, _duration = entry
        rec = self._frame_data[fofs:fofs + 16]
        if len(rec) < 16:
            return None
        cell_idx, rot_z = struct.unpack_from("<HH", rec, 0)
        sx, sy = struct.unpack_from("<ii", rec, 4)
        px, py = struct.unpack_from("<hh", rec, 12)
        return cell_idx, rot_z, sx, sy, px, py


def parse_nanr(data):
    return Nanr(data)


# ---------------------------------------------------------------------------
# Compositing
# ---------------------------------------------------------------------------

def render_oam(ncgr, oam):
    """Return (w, h, nibble_list) for one OAM's pixel block, flips applied."""
    tiles_w = oam.w // 8
    tiles_h = oam.h // 8
    px = [[0] * oam.w for _ in range(oam.h)]
    for ty in range(tiles_h):
        for tx in range(tiles_w):
            tile_index = oam.tile_idx + ty * tiles_w + tx
            if tile_index >= ncgr.tile_count:
                continue
            nib = ncgr.tile_nibbles(tile_index)
            for ly in range(8):
                for lx in range(8):
                    px[ty * 8 + ly][tx * 8 + lx] = nib[ly * 8 + lx]
    if oam.hflip:
        px = [row[::-1] for row in px]
    if oam.vflip:
        px = px[::-1]
    return px


def compose_pose(ncgr, ncer, nodes, nanr=None):
    """Blit every node's cell onto a shared canvas using the mission's
    composer semantics, re-verified against species 25's real bytes this
    pass (see module docstring for the byte-level derivation):

      * **Cell selection**: a node does NOT choose its own cell via its
        on-disk `cell_anim_slot` byte (that field is positional only, per
        the mission, and this pass confirms it just cycles 0-9 twice with
        no evident per-part meaning). Instead, the cell is
        `NANR.sequences[node.anim_seq_idx].frames[0].data.cellIdx` -- i.e.
        each node names an *animation sequence*, and that sequence's own
        frame-0 SRT frame-data record says which NCER cell to draw. Species
        25's 20 nodes' `anim_seq_idx` values cover the NANR's 20 sequences
        exactly once each, a clean bijection (see module docstring).
        A node whose sequence has no frame-0 data (empty sequence, `nanr`
        returns None) is skipped -- there is no defined fallback.

      * **Placement**: the node's (posX, posY) is a straight translation
        applied to the whole assembled cell -- each OAM keeps its own
        cell-local (x, y) and the node's (x, y) is added on top, with no
        bounding-box re-centering (the previous pass's bbox-center-anchor
        strategy was a workaround for the wrong cell assignment above, not
        a real part of the format). SRT scale is identity and rotation is
        0 at frame 0 (confirmed by the eighth pass: sx/sy read 4096 ==
        FX32 1.0), so no scale/rotation transform is applied here either.
    """
    placements = []  # (abs_x, abs_y, px_rows)
    minx = miny = 10**9
    maxx = maxy = -10**9
    for node in nodes:
        cell_idx = None
        if nanr is not None:
            srt = nanr.frame_data_srt(node.anim_seq_idx, 0)
            if srt is not None:
                cell_idx = srt[0]
        if cell_idx is None or cell_idx >= len(ncer.cells):
            continue
        cell = ncer.cells[cell_idx]
        if not cell.oams:
            continue
        for oam in cell.oams:
            rows = render_oam(ncgr, oam)
            ax = node.x + oam.x
            ay = node.y + oam.y
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


def compose_rest_pose(ncgr, ncer, nodes, apply_node_offset=False):
    """Blit every node's cell onto a canvas sized to the content's bounding
    box (plus a small margin). Returns (width, height, palette_index grid)
    as a flat list, background index 0.

    `apply_node_offset` controls whether the NMCR node's own (x, y) field
    (see module docstring) is added on top of each OAM's own cell-local
    (x, y). Default is **off**: empirically, summing the two scatters the
    11 cells across a much larger area with no coherent silhouette, while
    using each cell's OAM coordinates directly (as if every cell already
    shares one coordinate frame) produces a noticeably more spatially
    coherent -- if still sparse and not confidently "recognizable" --
    blob with a plausible red cheek-mark accent. This suggests the NMCR
    node (x, y) fields are not a simple rest-pose translation added to the
    OAM position; their real role (a per-animation-frame delta applied on
    top of a zero rest position? a bounding/hit-box hint unrelated to
    rendering?) was not resolved this pass. Pass `apply_node_offset=True`
    to see the (worse) node-translated result for comparison."""
    placements = []  # (abs_x, abs_y, px_rows)
    minx = miny = 10**9
    maxx = maxy = -10**9
    for node in nodes:
        if node.cell_index >= len(ncer.cells):
            continue
        cell = ncer.cells[node.cell_index]
        for oam in cell.oams:
            rows = render_oam(ncgr, oam)
            ax = (node.x if apply_node_offset else 0) + oam.x
            ay = (node.y if apply_node_offset else 0) + oam.y
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
    # later placements (higher OAM/cell index order) drawn on top, skipping
    # background index 0 so parts don't stomp each other's silhouette edges
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
