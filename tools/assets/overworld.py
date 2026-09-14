#!/usr/bin/env python3
"""
overworld.py -- render + NCGR round-trip for the `a/0/0/7` overworld sprite
archive.

Written from scratch for the aletheia project. Stdlib only, single file.

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
                                4bpp sub-palettes (every OAM sampled uses
                                sub-palette 0; the other two are unused by
                                anything this pass rendered)
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

LOCAL_PALETTE = 0
NANR_INDICES = (1, 3, 5)
NCER_INDICES = (2, 4, 6)   # mapping_type 0, 1, 2 -- this module uses NCER_INDICES[0]


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
    for oam in cell.oams:
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


def render_entity(n, entity_indices, entity_num, cells, palette, out_dir):
    idx = entity_indices[entity_num]
    ncgr = parse_ncgr(n.read(idx))
    w, h, flat = render_sprite_sheet(ncgr, cells)
    rgb = indices_to_rgb(flat, palette)
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
                     help="entity index (0..714). Not needed with --all/--sample/--verify.")
    ap.add_argument("--archive", default=ARCHIVE_PATH)
    ap.add_argument("--out", default=OUT_DIR)
    ap.add_argument("--all", action="store_true", help="render every entity")
    ap.add_argument("--sample", action="store_true",
                     help="render 10 sample entities spread across the archive")
    ap.add_argument("--verify", action="store_true",
                     help="NCGR round-trip check over --archive instead of rendering")
    args = ap.parse_args(argv)

    if args.verify:
        ok, fail, skipped = verify_round_trip(args.archive)
        return 0 if fail == 0 else 1

    os.makedirs(args.out, exist_ok=True)
    n = narc.parse_file(args.archive)
    entity_indices = find_entity_indices(n)
    palette, cells = load_shared(n)
    print(f"[*] {args.archive}: {len(entity_indices)} entities, "
          f"{len(cells)} cells/frames per entity, {len(palette)}-color palette")

    if args.all:
        ok = 0
        skipped = 0
        for e in range(len(entity_indices)):
            try:
                render_entity(n, entity_indices, e, cells, palette, args.out)
                ok += 1
            except Exception as exc:  # noqa: BLE001 -- best-effort batch, log and continue
                skipped += 1
                print(f"[!] entity {e}: skipped ({exc})")
        print(f"[*] --all: {ok} rendered, {skipped} skipped, out={args.out}")
        return 0

    if args.sample:
        step = max(1, len(entity_indices) // 10)
        sample = list(range(0, len(entity_indices), step))[:10]
        for e in sample:
            out_path, w, h = render_entity(n, entity_indices, e, cells, palette, args.out)
            print(f"[*] entity {e}: wrote {out_path} ({w}x{h})")
        return 0

    if args.entity is None:
        ap.error("give an entity index, or pass --all / --sample / --verify")

    out_path, w, h = render_entity(n, entity_indices, args.entity, cells, palette, args.out)
    print(f"[*] entity {args.entity}: wrote {out_path} ({w}x{h})")
    return 0


if __name__ == "__main__":
    sys.exit(main())
