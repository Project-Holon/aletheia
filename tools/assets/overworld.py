#!/usr/bin/env python3
"""
overworld.py -- render + NCGR round-trip for the `a/0/0/7` overworld sprite
archive.

Written from scratch for aletheia. Stdlib only, single file.

--------------------------------------------------------------------------
Archive identification (this pass)
--------------------------------------------------------------------------
`a/0/0/4` and `a/0/5/2` (previously guessed "overworld/menu sprites" in an
earlier inventory pass) turned out to be the animated Pokemon **battle**
rigs (see `tools/assets/rig.py`). This pass re-scanned every NARC under
`extract/data/` for the actual shape the mission describes -- an
NCGR+NCLR+NCER+NANR bundle with a few hundred to a couple thousand entries
and a 16x32/32x32 per-entry canvas -- by computing a full sub-file magic
histogram per archive (not just the inventory's top-2-magics summary) and
looking for archives where all four chunk types are present together at
the right scale.

**`a/0/0/7`** (779916 bytes, 1431 sub-files, "pokemon/trainer sprites
(guess)" in the original inventory) is the match:

    index 0        RLCN/NCLR   one shared palette, 48 colors = 3 x 16-color
                                4bpp sub-palettes. Every OAM's own attr2
                                pal bits are 0, but that is NOT which
                                sub-palette an entity's icon actually
                                uses -- see "Per-entity sub-palette
                                selection" below and `g_0209E474` in this
                                module: the real per-entity selector is a
                                separate ARM9 data table, not the NCER.
    index 1,3,5    RNAN/NANR   three byte-identical copies of one cell
                                animation definition (confirmed: the three
                                sub-files are byte-for-byte identical --
                                pure redundancy, not three different anims)
    index 2,4,6    RECN/NCER   three copies of one cell bank, each
                                declaring a DIFFERENT `mapping_type` (0, 1,
                                2 = the standard NDS OBJ 1D tile-mapping
                                boundary selector: 32B, 64B, 128B tile
                                stride respectively) with each cell's
                                `tile_idx` field scaled to match -- e.g.
                                cell 1's tile_idx is 16 in the mapping_type
                                0 copy, 8 in the mapping_type 1 copy, 4 in
                                the mapping_type 2 copy; 16*32 == 8*64 ==
                                4*128, all three resolve to the SAME byte
                                offset (0x200) into the per-entity NCGR.
                                This is three encodings of one cell bank at
                                different hardware tile-mapping
                                granularities, not three different banks --
                                confirmed by checking every cell's resolved
                                byte offset matches across all three copies.
                                This module always uses the mapping_type=0
                                copy (index 2) and dense `tile_idx * 32`
                                byte addressing (no boundary scaling
                                needed at that mapping type).
    index 7..1430  RGCN/NCGR,  715 per-entity tile sheets, each exactly
                   (empty)     1072 bytes (24-byte NCGR sub-header + 1024
                                bytes = 32 tiles of 4bpp data), each
                                immediately followed by one empty (0-byte)
                                placeholder sub-file in all but 6 of the
                                715 cases (where two NCGR sub-files are
                                back-to-back with no placeholder between --
                                not chased further, does not affect
                                rendering since sub-files are found by
                                magic, not by a fixed stride). No entity
                                NCGR is LZ11-compressed in this archive
                                (every one opens directly with "RGCN").

Each entity's own 32-tile NCGR pairs with the ONE shared NCER (3 cells:
cell 0 uses tile 0, cell 1 uses tile 16, cell 2 uses tile 0 again with a
1px-shifted bounding box) and the ONE shared NCLR. Cell shape/size for
every cell sampled is a plain 32x32 square OAM (shape=0, size=2) -- this
is the mission's expected overworld sprite canvas. Two of the three cells
use distinct tile data (tile 0 vs tile 16 -- the other 16 tiles of the
32-tile sheet); the third reuses tile 0. This reads as a small "idle bob"
or 2-frame animation cycle (typical for a static NDS overworld NPC sprite,
as opposed to a full 4-direction walk cycle) -- the real per-frame timeline
lives in the NANR block, which this pass has NOT decoded past its 16-byte
common header + ABNK sub-header (`num_anim`, `element_type`); the frame
duration/ordering fields inside ABNK are not resolved here. This module's
"sprite sheet" therefore renders **every cell of the shared NCER** against
one entity's own NCGR, left to right -- an honest "all frames" in the
sense of "every distinct pose this entity's cell bank defines", not a
verified real-time animation sequence.

715 entities is in a very plausible range for "every NPC/trainer-class
overworld graphic in Black/White" (`a/0/0/6`, 733 sub-files, is this
project's existing "trainer battle portrait" guess -- 715 is close but not
identical, consistent with the overworld and battle-portrait sets being
authored/counted slightly differently, e.g. a handful of portrait-only or
overworld-only entries).

--------------------------------------------------------------------------
NCGR round trip
--------------------------------------------------------------------------
`NcgrFile` below parses every header field of the per-entity NCGR sub-file
format (16-byte common file header + one RAHC/CHAR block: a 24-byte
sub-header of tile_num_y/tile_num_x/bitdepth/pad/flag/unk1/data_size/
data_ofs, then the raw tile data) and `encode()` reproduces the exact
original bytes from those stored fields plus the (decoded, then
re-packed) tile data -- no bytes are copied verbatim from the input, every
field is re-serialized. For any entry whose raw sub-file is LZ11-
compressed (none in `a/0/0/7`, but the encoder path exists and is
exercised by `--verify` against any archive containing compressed NCGR,
e.g. `a/0/6/4`/`a/0/7/2` from the same bundle family), `encode()` calls
`tools/assets/lz11.compress()` on the packed NCGR bytes and compares
against the original compressed bytes.

--------------------------------------------------------------------------
Usage
--------------------------------------------------------------------------
    python tools/assets/overworld.py --sample            # 10 sample entries
    python tools/assets/overworld.py 0                   # one entity by index
    python tools/assets/overworld.py --all                # every entity
    python tools/assets/overworld.py --verify              # NCGR round trip
    python tools/assets/overworld.py --verify --archive extract/data/a/0/6/4
"""

import argparse
import bisect
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402
import lz11  # noqa: E402
import battle_sprite as bs  # noqa: E402  (parse_nclr, write_png_rgb8)
import rig  # noqa: E402  (Oam, render_oam -- identical NCGR/OAM shape)

ARCHIVE_PATH = os.path.join("extract", "data", "a", "0", "0", "7")
OUT_DIR = os.path.join("build", "assets", "overworld")

# `a/0/2/5` -- tenth lane pass' second mission target, see module docstring
# addendum "a/0/2/5 -- second overworld-shaped archive" below.
ARCHIVE_PATH_2 = os.path.join("extract", "data", "a", "0", "2", "5")
OUT_DIR_2 = os.path.join("build", "assets", "overworld2")
ANIM_OUT_DIR = os.path.join("build", "assets", "overworld_anim")

LOCAL_PALETTE = 0
NANR_INDICES = (1, 3, 5)
NCER_INDICES = (2, 4, 6)   # mapping_type 0, 1, 2 -- this module uses NCER_INDICES[0]

# ---------------------------------------------------------------------------
# tenth lane pass addendum
# ---------------------------------------------------------------------------
# `a/0/2/5` mission: 1005 sub-files (552 RLCN + 451 RGCN + one shared RNAN at
# index 0 + one shared RECN at index 1). Unlike `a/0/0/7` (a single leading
# NCLR shared by all 715 entities), `a/0/2/5`'s NCGR/NCLR sub-files interleave
# after the shared NANR/NCER pair in an irregular pattern: mostly strict
# G,L,G,L,... alternation but with runs of 2-4 consecutive G's or L's
# scattered throughout (confirmed by direct scan -- not a fixed stride).
# There is no separate lookup table found for this pairing (no ARM9 table
# analogous to `a/0/0/7`'s `g_0209E474` was searched for or needed): this
# module pairs each RGCN with the **nearest preceding RLCN** sub-file index
# (the last palette seen scanning forward through the archive) -- this is
# "index arithmetic" in the loose sense of "closest lower index", not a
# fixed stride or an external table. Verified by rendering (see
# `render_entity_v2`): every one of the 10 samples this pass rendered comes
# out as a plausibly-colored, internally-consistent icon (see docstring
# note below on what these depict), not a garish/incoherent palette
# mismatch, which is the signal this pass used to accept the heuristic.
#
# This same "nearest preceding NCLR" rule generalizes cleanly to `a/0/0/7`
# too (that archive has exactly one RLCN sub-file, at index 0, so every
# entity's "nearest preceding" index is always 0) -- `render_entity` was
# kept as-is (its own explicit `LOCAL_PALETTE` constant) for the already-
# shipped/verified code path, and `render_entity_v2` below is the new,
# archive-generic version used by `--archive`-aware CLI flags.
#
# **Entity identification**: the 10 rendered samples (`build/assets/
# overworld2/`, entities 0/45/90/135/180/225/270/315/360/405 sampled evenly
# across the archive) are small (32-36px), single-OAM, true-color icons
# depicting a wide variety of distinct small objects, NOT a uniform shape:
# a purple/pink Poke Ball (entity 0), a grey faceted gem/stone (45, reads
# as an evolution stone), an orange flame/torch shape (90), a yellow
# curved banana-like item (135), a pink boot/shoe shape (180), a plain
# grey pebble/rock (225), an orange key or rocket-like shape (270), a red
# round berry-or-ball (315), a green card/badge with a dark stripe (360),
# and a pink/white round pill or macaron shape (405). This is a **general
# held/key-item icon set**, not narrowly Poke Balls (the first pass's
# initial read of a handful of early, ball-shaped samples was too narrow --
# corrected here after sampling across the full index range). This
# directly contradicts the "overworld/menu-sized character icon" guess
# from the locate pass in docs/ASSETS.md: `a/0/2/5` is NOT overworld
# entity sprites, it is a Bag/item-icon archive, consistent in kind (if
# not confirmed as the same archive) with the existing `a/0/4/5#0`
# "held-item icon sprite" finding elsewhere in docs/ASSETS.md. The 552
# NCLR vs. 451 NCGR count (101 more palettes than shapes) is plausible for
# an item set: some item icons likely share one outline/shape NCGR across
# multiple color variants (e.g. differently-colored versions of the same
# object), giving more distinct palettes than distinct tile sheets.

# ---------------------------------------------------------------------------
# Per-entity sub-palette selection
# ---------------------------------------------------------------------------
# The shared NCLR is 48 colors = 3x16-color sub-palettes, and which one a
# given entity's icon uses is NOT fixed (sub-palette 0 is wrong for most
# entities -- e.g. entity 25, the icon this pass identified by shape and
# position as Pikachu, renders purple at sub-palette 0 and yellow at
# sub-palette 2). The selector is `g_0209E474`, a real matched-code table:
# `sub_0201BB5C(species, form, half, isEgg)` in
# `src/pending/unit_0201BB5C.c` (MATCH-capped, 0 differing bytes) indexes
# this table by species number (or 650/651 for the plain/Manaphy egg, or
# `first + form + 651` for an alternate form) and returns either nibble of
# one packed byte: high nibble if `half != 0`, low nibble otherwise. Every
# entity this pass identified by eye (11 species across the Kanto starter
# lines plus Pikachu, Arcanine, Alakazam, Gengar, Gyarados, Kabutops,
# Snorlax, Mewtwo -- see docs/ASSETS.md) confirms `idx = species` lines up
# exactly with `a/0/0/7`'s own entity index, i.e. this module's entity N
# IS species/form index N into `g_0209E474`, and the icon always wants the
# LOW nibble (`half = 0`; the high nibble is some other, unrendered, half
# of the pair -- possibly a gendered recolor -- not used here).
#
# `g_0209E474` (RAM address 0x0209E474) lives in the ARM9 static region at
# `extract/arm9_dec.bin` offset 0x9A474 (== 0x0209E474 - the static
# region's RAM base 0x02004000, per `layout/layout.json`'s
# `arm9.static.ram_start`/`src_offset`).
ARM9_DEC_PATH = os.path.join("extract", "arm9_dec.bin")
SUBPAL_TABLE_OFFSET = 0x9A474   # arm9_dec.bin offset of g_0209E474
SUBPAL_TABLE_RAM_ADDR = 0x0209E474


def _hdr(data):
    magic, bom, ver, fsize, hsize, nblk = struct.unpack_from("<4sHHIHH", data, 0)
    return magic, bom, ver, fsize, hsize, nblk


# ---------------------------------------------------------------------------
# NCGR (RGCN) -- per-entity tile sheet, with byte-exact round trip
# ---------------------------------------------------------------------------

class NcgrFile:
    """Parses AND can re-serialize one NCGR sub-file (single RAHC/CHAR
    block, the only shape seen in this archive) byte-for-byte."""

    def __init__(self, data):
        magic, bom, ver, fsize, hsize, nblk = _hdr(data)
        if magic != b"RGCN":
            raise ValueError(f"not an RGCN (NCGR) resource: {magic!r}")
        if nblk != 1:
            raise ValueError(f"NCGR with {nblk} blocks not supported by this round-tripper")
        pos = hsize
        bmagic, bsize = struct.unpack_from("<4sI", data, pos)
        if bmagic != b"RAHC":
            raise ValueError(f"expected RAHC (CHAR) block, found {bmagic!r}")
        body = data[pos + 8:pos + bsize]
        tile_num_y, tile_num_x = struct.unpack_from("<HH", body, 0)
        bitdepth, = struct.unpack_from("<I", body, 4)
        pad, flag = struct.unpack_from("<HH", body, 8)
        unk1, data_size, data_ofs = struct.unpack_from("<III", body, 12)
        tile_data = body[data_ofs:data_ofs + data_size]
        trailing = body[data_ofs + data_size:]

        self.bom = bom
        self.ver = ver
        self.hsize = hsize
        self.tile_num_x = tile_num_x
        self.tile_num_y = tile_num_y
        self.bitdepth = bitdepth
        self.pad = pad
        self.flag = flag
        self.unk1 = unk1
        self.data_ofs = data_ofs
        self.tile_data = tile_data
        self.trailing = trailing          # bytes between tile data end and block end
        self.header_gap = body[24:data_ofs]  # bytes between the 24-byte sub-header
                                              # and data_ofs, if data_ofs > 24
        self.tile_count = len(tile_data) // rig.TILE_BYTES_4BPP
        # `unk1` (RAHC body offset 12) is the same field rig.Ncgr decodes and
        # names `char_format`: 1 means `tile_data` is one linear
        # `tile_num_x*8 x tile_num_y*8` raster image, 0 means sequential 8x8
        # tiled blocks. This class never named it, so `block_pixels()` below
        # (ported from rig.Ncgr's corrected two-dimensional addressing) reads
        # it as `self.unk1` rather than adding a second name for one field.
        self._sentinel_dims = (tile_num_x == 0xFFFF or tile_num_y == 0xFFFF)
        if self._sentinel_dims:
            self.width = self.height = 0
            self.pixels = None
        else:
            self.width = tile_num_x * 8
            self.height = tile_num_y * 8
            self.pixels = self._unpack()

    def tile_nibbles(self, tile_index):
        off = tile_index * rig.TILE_BYTES_4BPP
        tile = self.tile_data[off:off + rig.TILE_BYTES_4BPP]
        out = [0] * 64
        for ly in range(8):
            row = tile[ly * 4:ly * 4 + 4]
            for lx4 in range(4):
                b = row[lx4]
                out[ly * 8 + lx4 * 2] = b & 0x0F
                out[ly * 8 + lx4 * 2 + 1] = (b >> 4) & 0x0F
        return out

    def _unpack(self):
        """Return the sheet as a flat `width * height` list of 4bpp indices,
        low nibble first (left pixel). Ported from rig.Ncgr._unpack against
        this class's own fields (`tile_data`, `unk1` in place of
        `char_format`) -- the two classes store the same NCGR bytes, so the
        addressing carries over, but the attributes it reads do not, hence a
        fresh method rather than reusing rig.Ncgr's by name or alias."""
        w, h = self.width, self.height
        data = self.tile_data
        px = [0] * (w * h)
        if self.unk1 == 1:
            for i, b in enumerate(data):
                p = i * 2
                if p + 1 >= len(px):
                    break
                px[p] = b & 0x0F
                px[p + 1] = (b >> 4) & 0x0F
            return px
        for t in range(len(data) // rig.TILE_BYTES_4BPP):
            bx = (t % self.tile_num_x) * 8
            by = (t // self.tile_num_x) * 8
            if by + 8 > h:
                break
            base = t * rig.TILE_BYTES_4BPP
            for i in range(rig.TILE_BYTES_4BPP):
                b = data[base + i]
                p = (by + i // 4) * w + bx + (i % 4) * 2
                px[p] = b & 0x0F
                px[p + 1] = (b >> 4) & 0x0F
        return px

    def block_pixels(self, block_index):
        """Return the 64 pixel indices (row-major, 8x8) of one 8x8 block,
        addressed two-dimensionally: block `i` is at column
        `i % tile_num_x`, row `i // tile_num_x` of the unpacked sheet image.
        This is what `rig.render_oam` calls; `tile_nibbles` above is the
        older one-dimensional lookup this class used to expose instead, kept
        for any other caller still addressing tiles sequentially.

        **`a/0/0/7`'s per-entity NCGR declares the documented `tile_num_x`/
        `tile_num_y` == 0xFFFF "unspecified, derive from data" sentinel on
        every one of its 715 entries** (confirmed by direct read: index
        7/9/11 all read FFFF/FFFF) -- `__init__` already detects this
        (`_sentinel_dims`) and leaves `self.pixels` as `None`, since there is
        no real sheet width to place tiles into. The module docstring's own
        "index 2,4,6" section states the mapping_type=0 NCER copy this
        module always uses resolves every cell's OAM `tile_idx` by **dense
        `tile_idx * 32` byte addressing**, not a 2D sheet-grid lookup, so
        the 2D formula below both cannot run (no `self.pixels` to index)
        and was never the right addressing for this archive to begin with.
        Read the tile directly out of `tile_data` via `tile_nibbles`
        instead -- this is what silently produced an all-zero (background/
        transparent index) block for every OAM before this fix, rendering
        every entity as one flat color."""
        if self._sentinel_dims:
            return self.tile_nibbles(block_index)
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

    def encode(self):
        """Re-serialize to the exact original uncompressed NCGR bytes."""
        sub_hdr = struct.pack("<HHIHHIII", self.tile_num_y, self.tile_num_x,
                               self.bitdepth, self.pad, self.flag, self.unk1,
                               len(self.tile_data), self.data_ofs)
        body = sub_hdr + self.header_gap + self.tile_data + self.trailing
        bsize = 8 + len(body)
        block = b"RAHC" + struct.pack("<I", bsize) + body
        fsize = self.hsize + bsize
        file_hdr = struct.pack("<4sHHIHH", b"RGCN", self.bom, self.ver, fsize,
                                self.hsize, 1)
        return file_hdr + block


def parse_ncgr(data):
    return NcgrFile(data)


# ---------------------------------------------------------------------------
# NCER (RECN) -- shared cell bank, extended (bounding-box) cell records
# ---------------------------------------------------------------------------

class Cell:
    __slots__ = ("num_oam", "cell_attr", "oams")

    def __init__(self, num_oam, cell_attr, oams):
        self.num_oam = num_oam
        self.cell_attr = cell_attr
        self.oams = oams


def parse_ncer_shared(data):
    """Parse the shared NCER (cell_info_type 1: 16-byte extended cell
    records with a bounding box, vs. the 8-byte 'simple' records
    `rig.Ncer` handles for the Pokemon battle-rig archives). Returns a
    list of `Cell`, reusing `rig.Oam` for each OAM so `rig.render_oam`
    (dense `tile_idx * 32` addressing, matching this NCER's declared
    mapping_type 0) can be used unchanged."""
    magic, bom, ver, fsize, hsize, nblk = _hdr(data)
    if magic != b"RECN":
        raise ValueError(f"not an RECN (NCER) resource: {magic!r}")
    pos = hsize
    bmagic, bsize = struct.unpack_from("<4sI", data, pos)
    if bmagic != b"KBEC":
        raise ValueError(f"expected KBEC (CEBK) block, found {bmagic!r}")
    body = data[pos + 8:pos + bsize]
    num_cells, cell_info_type = struct.unpack_from("<HH", body, 0)
    cell_data_ofs, mapping_type, _reserved = struct.unpack_from("<III", body, 4)
    if cell_info_type != 1:
        raise ValueError(f"expected extended (bbox) cell records, got type {cell_info_type}")

    cell_hdrs = []
    for i in range(num_cells):
        off = cell_data_ofs + i * 16
        num_oam, cell_attr, oam_ofs = struct.unpack_from("<HHI", body, off)
        cell_hdrs.append((num_oam, cell_attr, oam_ofs))

    oam_arr_start = cell_data_ofs + num_cells * 16
    cells = []
    for num_oam, cell_attr, oam_ofs in cell_hdrs:
        oams = []
        for i in range(num_oam):
            off = oam_arr_start + oam_ofs + i * 6
            a0, a1, a2 = struct.unpack_from("<HHH", body, off)
            oams.append(rig.Oam(a0, a1, a2))
        cells.append(Cell(num_oam, cell_attr, oams))
    return cells, mapping_type


# ---------------------------------------------------------------------------
# Compositing: one entity's sprite sheet = every shared-NCER cell rendered
# against that entity's own NCGR, left to right.
# ---------------------------------------------------------------------------

def render_cell(ncgr, cell):
    if not cell.oams:
        return 1, 1, [0]
    minx = miny = 10 ** 9
    maxx = maxy = -10 ** 9
    for oam in cell.oams:
        minx = min(minx, oam.x)
        miny = min(miny, oam.y)
        maxx = max(maxx, oam.x + oam.w)
        maxy = max(maxy, oam.y + oam.h)
    w = maxx - minx
    h = maxy - miny
    canvas = [[0] * w for _ in range(h)]
    # Paint order: same attested rule as `rig.py`'s `_cell_local_raster` --
    # a cell's own OAM array is emitted into the hardware OAM list forward
    # (index 0 first, `func_02067998`), and a lower final OAM slot draws in
    # front, so a painter that blits forward and lets later writes win must
    # paint index 0 *last* (on top). Priority (attr2 bits 10-11) outranks
    # index when a cell mixes priorities.
    paint_order = sorted(range(len(cell.oams)),
                          key=lambda i: (cell.oams[i].priority, i), reverse=True)
    for i in paint_order:
        oam = cell.oams[i]
        rows = rig.render_oam(ncgr, oam)
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
    return w, h, [v for row in canvas for v in row]


def render_sprite_sheet(ncgr, cells):
    """Lay out every cell's rendered frame left to right with padding."""
    frames = [render_cell(ncgr, cell) for cell in cells]
    pad = 2
    sheet_h = max(h for _, h, _ in frames) + pad * 2
    sheet_w = sum(w for w, _, _ in frames) + pad * (len(frames) + 1)
    sheet = [[0] * sheet_w for _ in range(sheet_h)]
    cx = pad
    for w, h, flat in frames:
        for ly in range(h):
            for lx in range(w):
                sheet[pad + ly][cx + lx] = flat[ly * w + lx]
        cx += w + pad
    return sheet_w, sheet_h, [v for row in sheet for v in row]


def indices_to_rgb(pixels, palette, pal_index=0):
    sub = palette[pal_index * 16:pal_index * 16 + 16]
    n = len(sub)
    return [sub[p] if 0 <= p < n else (255, 0, 255) for p in pixels]


def load_subpalette_table(num_entities, arm9_dec_path=ARM9_DEC_PATH):
    """Read `g_0209E474`'s low nibble (`sub_0201BB5C`'s `half = 0` case) for
    entity indices 0..num_entities-1, one raw table byte per entity index
    (see the module-level note above -- entity index IS `g_0209E474` index
    for every sample this pass checked). Values outside 0..2 (there is no
    fourth sub-palette in this archive's NCLR) fall back to sub-palette 0 --
    this only happens for a handful of entries at the very end of the
    archive's index range, past where the alternate-form block's own
    indexing (`first + form + 651`, not a straight pass-through of the
    entity number) stops lining up with `a/0/0/7`'s own slot order; see
    docs/ASSETS.md."""
    with open(arm9_dec_path, "rb") as f:
        f.seek(SUBPAL_TABLE_OFFSET)
        raw = f.read(num_entities)
    table = []
    bad = 0
    for i in range(num_entities):
        b = raw[i] if i < len(raw) else 0
        subpal = b & 0xF
        if subpal > 2:
            subpal = 0
            bad += 1
        table.append(subpal)
    if bad:
        print(f"[!] subpalette table: {bad} of {num_entities} entities had an "
              f"out-of-range nibble (>2), fell back to sub-palette 0")
    return table


# ---------------------------------------------------------------------------
# Archive-level helpers
# ---------------------------------------------------------------------------

def find_entity_indices(n):
    """Every RGCN sub-file index, in archive order -- entity N is the N-th
    one (see module docstring: mostly a fixed (NCGR, empty) stride but not
    perfectly rigid, so this walks by magic rather than assuming a stride)."""
    out = []
    for sf in n.subfiles:
        if sf.magic == b"RGCN":
            out.append(sf.index)
    return out


def load_shared(n):
    palette = bs.parse_nclr(n.read(LOCAL_PALETTE))
    cells, mapping_type = parse_ncer_shared(n.read(NCER_INDICES[0]))
    assert mapping_type == 0, f"expected NCER_INDICES[0] to be the mapping_type=0 copy, got {mapping_type}"
    return palette, cells


def render_entity(n, entity_indices, entity_num, cells, palette, out_dir, subpal=0):
    idx = entity_indices[entity_num]
    ncgr = parse_ncgr(n.read(idx))
    w, h, flat = render_sprite_sheet(ncgr, cells)
    rgb = indices_to_rgb(flat, palette, subpal)
    out_path = os.path.join(out_dir, f"{entity_num:04d}.png")
    bs.write_png_rgb8(out_path, w, h, rgb)
    return out_path, w, h


# ---------------------------------------------------------------------------
# Archive-generic path (`--archive`-aware): finds the shared NCER by magic
# scan instead of a fixed index, and pairs each entity's own NCGR with its
# nearest-preceding NCLR sub-file instead of assuming one leading shared
# palette -- see the "tenth lane pass addendum" module docstring above for
# why this generalizes both `a/0/0/7` and `a/0/2/5` under one rule.
# ---------------------------------------------------------------------------

def find_magic_indices(n, magic):
    return [sf.index for sf in n.subfiles if sf.magic == magic]


def nearest_preceding(sorted_indices, x):
    """Index in `sorted_indices` that is the largest value <= x, or None."""
    i = bisect.bisect_right(sorted_indices, x) - 1
    return sorted_indices[i] if i >= 0 else None


def nearest_preceding_or_following(sorted_indices, x):
    """`nearest_preceding`, falling back to the nearest following index when
    there is no earlier one -- needed for `a/0/2/5` entity 0, whose own
    RGCN (sub-file index 2) comes before any RLCN in the archive (the
    shared RNAN/RECN pair occupies indices 0/1, and the first RLCN is at
    index 3, right after it)."""
    li = nearest_preceding(sorted_indices, x)
    if li is not None:
        return li
    i = bisect.bisect_left(sorted_indices, x)
    return sorted_indices[i] if i < len(sorted_indices) else None


def load_shared_v2(n):
    """Archive-generic shared-resource lookup: first RECN sub-file is the
    shared cell bank (works for both `a/0/0/7`, whose first RECN at index 2
    is the mapping_type=0 copy this module wants, and `a/0/2/5`, whose only
    RECN is at index 1); the full sorted list of RLCN indices is returned
    for per-entity nearest-preceding palette lookup."""
    ncer_indices = find_magic_indices(n, b"RECN")
    if not ncer_indices:
        raise ValueError("archive has no RECN (NCER) sub-file")
    cells, mapping_type = parse_ncer_shared(n.read(ncer_indices[0]))
    l_idx = find_magic_indices(n, b"RLCN")
    if not l_idx:
        raise ValueError("archive has no RLCN (NCLR) sub-file")
    return cells, l_idx


def render_entity_v2(n, entity_indices, entity_num, cells, l_idx, out_dir, subpal=0):
    """Like `render_entity`, but looks up this entity's own palette by
    nearest-preceding RLCN index instead of assuming one shared/fixed
    palette sub-file -- see module docstring addendum."""
    gi = entity_indices[entity_num]
    li = nearest_preceding_or_following(l_idx, gi)
    if li is None:
        raise ValueError(f"entity {entity_num} (sub-file {gi}): archive has no RLCN sub-file at all")
    palette = bs.parse_nclr(n.read(li))
    ncgr = parse_ncgr(n.read(gi))
    w, h, flat = render_sprite_sheet(ncgr, cells)
    rgb = indices_to_rgb(flat, palette, subpal)
    out_path = os.path.join(out_dir, f"{entity_num:04d}.png")
    bs.write_png_rgb8(out_path, w, h, rgb)
    return out_path, w, h, li


# ---------------------------------------------------------------------------
# `a/0/0/7` shared NANR: frame timeline decode (tenth lane pass)
# ---------------------------------------------------------------------------
# The mission asked for the per-entity animation timeline sequences, frames,
# cell index per frame, durations -- past what `rig.Nanr` (written for the
# much larger `a/0/0/4` species NANR) already decodes. `a/0/0/7`'s own
# shared NANR (index 1 of 3 byte-identical copies) is tiny (362 bytes, 3
# blocks) and, decoded byte-for-byte against `rig.Nanr`'s own KNBA/ABNK
# field layout, does NOT give usable per-sequence frame counts: the field
# `rig.Nanr` reads as `num_frames` (offset 4 of the 16-byte sequence record)
# is **0 for all 6 of this archive's sequences**, which cannot be the real
# frame count (every sequence needs at least 1 frame to render anything).
#
# What DOES decode cleanly:
#
# - A third block this archive's NANR has that `rig.Nanr` never needed to
#   read: `LBAL` (98 bytes) holds 6 NUL-terminated ASCII names --
#   "CellAnime0".."CellAnime5" -- one per sequence (`num_sequences=6`
#   matches exactly). These are **generic numbered names, not direction
#   words** (no "Down"/"Up"/"Left"/"Right" or similar) -- this is the
#   strongest single piece of evidence this pass found that `a/0/0/7`'s
#   entities are NOT full 4-direction walk-cycle sprites.
# - The element/frame-entry array (12 records, `elem_ofs=120`, confirmed
#   sentinel `0xBEEF` in every record, exactly as `rig.Nanr` already
#   decodes for species NANR) gives 12 `(offset_to_frame_data, duration)`
#   pairs.
# - The frame-data region past the element array (`body[elem_end:]`, 12
#   bytes for this archive) is NOT the 16-byte SRT or 8-byte "T" shape
#   `rig.Nanr` implements for species NANR -- it is a **new, smaller
#   4-byte record**: `{cellIdx(u16), sentinel(u16)=0xCCCC}` (a different
#   sentinel constant than the element array's own 0xBEEF, confirmed
#   present at every one of the frame-data region's 3 records here).
#   `offset_to_frame_data` values seen (0, 4, 8) are all multiples of 4,
#   consistent with this 4-byte stride, and `cellIdx` decodes to 0, 1, 2 --
#   exactly the shared NCER's 3 valid cell indices, which is what confirms
#   this reading (a `cellIdx` of 3+ would be nonsense against a 3-cell
#   NCER; every one of the 3 records lands in range).
#
# **What this pass renders as "the timeline"**: since the per-sequence
# frame-count field does not give usable per-sequence boundaries, and the
# 6 named sequences all draw from the same tiny 3-frame-data / 12-element
# pool (`elem_start` values across the 6 sequences are 1, 2, 2, 2, 2, 3 --
# heavily overlapping, not a clean partition of 0..11), this module renders
# the **entire 12-entry element/frame-data table, in array order**, as one
# animation strip per entity -- this is the mission's literal "all frames
# in order" for the one real, fully-decoded timeline this archive has,
# without pretending the 6-way sequence split is understood well enough to
# render separately. Decoded (cellIdx, duration) for all 12 elements:
# element 0: cell 0, duration 1; elements 1,3,5,7,9: cell 0, durations
# 8,12,24,40,90; elements 2,4,6,8: cell 1, durations 8,12,24,40; element 10:
# cell 2, duration 2; element 11: cell 0, duration 2. Cell 0/1 alternate
# with geometrically-doubling durations (8,12,24,40 growing, then 90) --
# consistent with a slow **idle bob** (two poses held for increasing
# durations, not a walk cycle), and cell 2 (the "1px-shifted" third cell
# noted in the main module docstring) appears once, briefly (duration 2),
# consistent with a short transient/blink frame rather than a fourth
# walking pose. This confirms and sharpens the existing "idle bob, not
# direction set" conclusion with real per-frame duration data.

NANR_ELEM_SENTINEL = 0xBEEF
NANR_FRAMEDATA_SENTINEL = 0xCCCC


class AnimFrame:
    __slots__ = ("cell_index", "duration")

    def __init__(self, cell_index, duration):
        self.cell_index = cell_index
        self.duration = duration


class SharedAnim:
    """Decodes one `a/0/0/7`-shaped shared NANR (KNBA + LBAL [+ trailing
    blocks, not decoded]) into a flat list of `AnimFrame` (the full
    element/frame-data table, in order) plus the raw sequence names."""

    def __init__(self, data):
        magic, bom, ver, fsize, hsize, nblk = _hdr(data)
        if magic != b"RNAN":
            raise ValueError(f"not an RNAN (NANR) resource: {magic!r}")
        pos = hsize
        bmagic, bsize = struct.unpack_from("<4sI", data, pos)
        if bmagic != b"KNBA":
            raise ValueError(f"expected KNBA (ABNK) block, found {bmagic!r}")
        body = data[pos + 8:pos + bsize]
        num_seq, num_elem = struct.unpack_from("<HH", body, 0)
        seq_ofs, elem_ofs, elem_end = struct.unpack_from("<III", body, 4)
        self.num_sequences = num_seq
        self.num_elements = num_elem

        self.sequence_elem_start = []
        for i in range(num_seq):
            off = seq_ofs + i * 16
            elem_start, = struct.unpack_from("<I", body, off)
            self.sequence_elem_start.append(elem_start)

        elements = []  # (frame_data_offset, duration)
        for i in range(num_elem):
            off = elem_ofs + i * 8
            fofs, duration, sentinel = struct.unpack_from("<iHH", body, off)
            if sentinel != NANR_ELEM_SENTINEL:
                raise ValueError(f"element {i}: bad sentinel {sentinel:#x}")
            elements.append((fofs, duration))

        frame_data = body[elem_end:]
        self.frames = []
        for fofs, duration in elements:
            rec = frame_data[fofs:fofs + 4]
            if len(rec) < 4:
                raise ValueError(f"frame-data offset {fofs} runs past end "
                                  f"of the {len(frame_data)}-byte frame-data region")
            cell_idx, sentinel = struct.unpack_from("<HH", rec, 0)
            if sentinel != NANR_FRAMEDATA_SENTINEL:
                raise ValueError(f"frame-data at offset {fofs}: bad sentinel {sentinel:#x}")
            self.frames.append(AnimFrame(cell_idx, duration))

        # sequence names, if an LBAL block follows KNBA (see module docstring)
        self.sequence_names = []
        pos2 = pos + bsize
        if pos2 < len(data):
            bmagic2, bsize2 = struct.unpack_from("<4sI", data, pos2)
            if bmagic2 == b"LBAL":
                lbody = data[pos2 + 8:pos2 + bsize2]
                # `num_seq` leading u32 offsets (one per sequence, into the
                # NUL-terminated name strings that follow), then the names
                # themselves -- confirmed against a/0/0/7's own LBAL: 6
                # offsets (24 bytes) then exactly 6 "CellAnimeN" strings.
                names = lbody[num_seq * 4:].split(b"\x00")
                self.sequence_names = [s.decode("ascii", "replace")
                                        for s in names if s]


def parse_shared_anim(data):
    return SharedAnim(data)


def render_animation_strip(ncgr, cells, anim, out_path):
    """Render `anim.frames` (in array order) left to right, one PNG per
    entity, in `build/assets/overworld_anim/`."""
    frame_cells = [cells[f.cell_index] for f in anim.frames
                   if f.cell_index < len(cells)]
    w, h, flat = render_sprite_sheet(ncgr, frame_cells)
    return w, h, flat


def render_entity_anim(n, entity_indices, entity_num, cells, l_idx, anim, out_dir, subpal=0):
    gi = entity_indices[entity_num]
    li = nearest_preceding_or_following(l_idx, gi)
    palette = bs.parse_nclr(n.read(li))
    ncgr = parse_ncgr(n.read(gi))
    w, h, flat = render_animation_strip(ncgr, cells, anim, None)
    rgb = indices_to_rgb(flat, palette, subpal)
    out_path = os.path.join(out_dir, f"{entity_num:04d}.png")
    bs.write_png_rgb8(out_path, w, h, rgb)
    return out_path, w, h


# ---------------------------------------------------------------------------
# NCGR round-trip verification
# ---------------------------------------------------------------------------

def verify_round_trip(archive_path):
    """Round-trip every RGCN sub-file in `archive_path`: decode (via
    narc.try_decompress if the sub-file is LZ11-compressed) to an NcgrFile,
    re-encode, re-compress with lz11.compress if the original was
    compressed, and compare byte-for-byte against the original sub-file."""
    n = narc.parse_file(archive_path)
    ok = 0
    fail = 0
    skipped = 0
    for sf in n.subfiles:
        raw = n.read(sf.index)
        kind, dec = narc.try_decompress(raw)
        if kind is not None and dec is None:
            skipped += 1
            continue
        payload = dec if dec is not None else raw
        if payload[:4] != b"RGCN":
            continue
        try:
            ncgr = parse_ncgr(payload)
            reenc = ncgr.encode()
        except Exception as exc:  # noqa: BLE001 -- best-effort batch, log and continue
            fail += 1
            print(f"[!] sub-file {sf.index}: parse/encode error ({exc})")
            continue
        if kind == "LZ11":
            reenc = lz11.compress(reenc)
        if reenc == raw:
            ok += 1
        else:
            fail += 1
            print(f"[!] sub-file {sf.index}: round trip mismatch "
                  f"({len(reenc)} bytes re-encoded vs {len(raw)} original)")
    print(f"[*] {archive_path}: NCGR round trip {ok} ok, {fail} mismatched, "
          f"{skipped} skipped (non-NCGR or undecodable)")
    return ok, fail, skipped


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("entity", type=int, nargs="?",
                     help="entity index. Not needed with --all/--sample/--verify/--anim*.")
    ap.add_argument("--archive", default=ARCHIVE_PATH,
                     help=f"NARC to read; {ARCHIVE_PATH} (default) or {ARCHIVE_PATH_2}")
    ap.add_argument("--out", default=None,
                     help=f"output dir (default {OUT_DIR} for the default archive, "
                          f"{OUT_DIR_2} for {ARCHIVE_PATH_2}, else {OUT_DIR})")
    ap.add_argument("--all", action="store_true", help="render every entity")
    ap.add_argument("--sample", action="store_true",
                     help="render 10 sample entities spread across the archive")
    ap.add_argument("--verify", action="store_true",
                     help="NCGR round-trip check over --archive instead of rendering")
    ap.add_argument("--anim", action="store_true",
                     help="render the full shared-NANR animation strip (all frames, in "
                          "array order) instead of the shared-NCER cell sheet")
    ap.add_argument("--anim-sample", action="store_true",
                     help="like --sample, but writes animation strips (see --anim) to "
                          f"{ANIM_OUT_DIR}")
    ap.add_argument("--anim-all", action="store_true",
                     help="like --all, but writes animation strips to " + ANIM_OUT_DIR)
    args = ap.parse_args(argv)

    if args.verify:
        ok, fail, skipped = verify_round_trip(args.archive)
        return 0 if fail == 0 else 1

    same_archive = os.path.normpath(args.archive) == os.path.normpath(ARCHIVE_PATH)
    out_dir = args.out
    if out_dir is None:
        out_dir = OUT_DIR if same_archive else (
            OUT_DIR_2 if os.path.normpath(args.archive) == os.path.normpath(ARCHIVE_PATH_2)
            else OUT_DIR)

    n = narc.parse_file(args.archive)
    entity_indices = find_entity_indices(n)
    cells, l_idx = load_shared_v2(n)
    # The ARM9 per-entity sub-palette selector table (`g_0209E474`) is only
    # confirmed/sized for `a/0/0/7`'s 715 entities -- every other archive
    # (including `a/0/2/5`, whose per-entity NCLR is already its own small
    # individually-paired palette, not a shared multi-bank one) uses
    # sub-palette 0 unconditionally.
    if same_archive:
        subpal_table = load_subpalette_table(len(entity_indices))
    else:
        subpal_table = [0] * len(entity_indices)

    if args.anim or args.anim_sample or args.anim_all:
        anim_indices = find_magic_indices(n, b"RNAN")
        if not anim_indices:
            ap.error(f"{args.archive} has no RNAN (NANR) sub-file")
        anim = parse_shared_anim(n.read(anim_indices[0]))
        names = ", ".join(anim.sequence_names) if anim.sequence_names else "(unnamed)"
        print(f"[*] {args.archive}: shared NANR -- {anim.num_sequences} sequence(s) "
              f"[{names}], {len(anim.frames)} frame-timeline entries: " +
              ", ".join(f"cell{f.cell_index}/{f.duration}f" for f in anim.frames))
        anim_out = ANIM_OUT_DIR if args.out is None else args.out
        os.makedirs(anim_out, exist_ok=True)

        def do_one(e):
            return render_entity_anim(n, entity_indices, e, cells, l_idx, anim, anim_out,
                                       subpal=subpal_table[e])

        if args.anim_all:
            ok = skipped = 0
            for e in range(len(entity_indices)):
                try:
                    do_one(e)
                    ok += 1
                except Exception as exc:  # noqa: BLE001 -- best-effort batch, log and continue
                    skipped += 1
                    print(f"[!] entity {e}: skipped ({exc})")
            print(f"[*] --anim-all: {ok} rendered, {skipped} skipped, out={anim_out}")
            return 0

        if args.anim_sample:
            step = max(1, len(entity_indices) // 10)
            for e in list(range(0, len(entity_indices), step))[:10]:
                out_path, w, h = do_one(e)
                print(f"[*] entity {e}: wrote {out_path} ({w}x{h})")
            return 0

        if args.entity is None:
            ap.error("--anim needs an entity index (or use --anim-sample/--anim-all)")
        out_path, w, h = do_one(args.entity)
        print(f"[*] entity {args.entity}: wrote {out_path} ({w}x{h})")
        return 0

    os.makedirs(out_dir, exist_ok=True)
    print(f"[*] {args.archive}: {len(entity_indices)} entities, "
          f"{len(cells)} cells/frames per entity")

    if args.all:
        ok = 0
        skipped = 0
        for e in range(len(entity_indices)):
            try:
                render_entity_v2(n, entity_indices, e, cells, l_idx, out_dir,
                                  subpal=subpal_table[e])
                ok += 1
            except Exception as exc:  # noqa: BLE001 -- best-effort batch, log and continue
                skipped += 1
                print(f"[!] entity {e}: skipped ({exc})")
        print(f"[*] --all: {ok} rendered, {skipped} skipped, out={out_dir}")
        return 0

    if args.sample:
        step = max(1, len(entity_indices) // 10)
        sample = list(range(0, len(entity_indices), step))[:10]
        for e in sample:
            out_path, w, h, li = render_entity_v2(n, entity_indices, e, cells, l_idx, out_dir,
                                                    subpal=subpal_table[e])
            print(f"[*] entity {e}: wrote {out_path} ({w}x{h}), palette sub-file {li}")
        return 0

    if args.entity is None:
        ap.error("give an entity index, or pass --all / --sample / --verify / --anim*")

    out_path, w, h, li = render_entity_v2(n, entity_indices, args.entity, cells, l_idx, out_dir,
                                            subpal=subpal_table[args.entity])
    print(f"[*] entity {args.entity}: wrote {out_path} ({w}x{h}), palette sub-file {li}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
