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
Usage
--------------------------------------------------------------------------
    python tools/assets/rig.py 25                  # species 25 (Pikachu)
    python tools/assets/rig.py 25 --cells-only      # contact sheet only
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
# NMCR (RCMN) -- multi-cell resource (rest-pose node placement)
# ---------------------------------------------------------------------------

class McNode:
    __slots__ = ("label_index", "x", "y", "cell_index")

    def __init__(self, label_index, x, y, cell_index):
        self.label_index = label_index
        self.x = x
        self.y = y
        self.cell_index = cell_index


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
        mc_ofs_field, = struct.unpack_from("<I", body, 4)
        node_ofs_field, = struct.unpack_from("<I", body, 8)
        self.num_multi_cell = num_multi_cell
        self.signature = sig
        mc_abs = 4 + mc_ofs_field       # self-relative
        node_abs = 8 + node_ofs_field   # self-relative

        self.mc_entries = []
        for i in range(num_multi_cell):
            off = mc_abs + i * 10
            f0, f1, f2, f3, f4 = struct.unpack_from("<Hhhhh", body, off)
            self.mc_entries.append((f0, f1, f2, f3, f4))

        node_bytes = body[node_abs:bsize - 8]
        n_nodes = len(node_bytes) // 8
        self.nodes = []
        for i in range(n_nodes):
            off = i * 8
            label, x, y = struct.unpack_from("<hhh", node_bytes, off)
            tag = node_bytes[off + 6]
            cell_index = node_bytes[off + 7]
            self.nodes.append(McNode(label, x, y, cell_index))

        # First multi-cell entry's node count (field index 2) selects the
        # leading span of `nodes` that forms a complete one-of-each-part
        # rest pose -- see module docstring.
        self.rest_pose_count = self.mc_entries[0][2] if self.mc_entries else n_nodes

    def rest_pose(self):
        return self.nodes[:self.rest_pose_count]


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


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("species", type=int, help="species/form index (25 = Pikachu)")
    ap.add_argument("--archive", default=ARCHIVE_PATH)
    ap.add_argument("--out", default=OUT_DIR)
    ap.add_argument("--anim", type=int, default=0, help="animation index (informational; "
                     "only animation 0 / the NMCR rest pose is actually rendered)")
    ap.add_argument("--frame", type=int, default=0, help="frame index (informational; "
                     "see module docstring -- frame 0 is assumed == rest pose)")
    ap.add_argument("--cells-only", action="store_true",
                     help="only render the per-cell contact sheet, skip the pose")
    args = ap.parse_args(argv)

    os.makedirs(args.out, exist_ok=True)
    n = narc.parse_file(args.archive)

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
    print(f"[*] NMCR: {nmcr.num_multi_cell} multi-cell entries, "
          f"{len(nmcr.nodes)} node records, rest pose uses first "
          f"{nmcr.rest_pose_count}")

    w, h, flat = compose_rest_pose(ncgr, ncer, nmcr.rest_pose())
    out_path = os.path.join(args.out, f"{args.species:04d}_a{args.anim}_f{args.frame}.png")
    bs.write_png_rgb8(out_path, w, h, indices_to_rgb(flat, palette))
    print(f"[*] wrote {out_path} ({w}x{h})")
    return 0


if __name__ == "__main__":
    sys.exit(main())
