#!/usr/bin/env python3
"""
background.py -- NSCR (screen/tilemap) decoder for 2D backgrounds and UI
panels: title screen, main menu, battle backgrounds, box/bag UI, etc.

Written from scratch for the aletheia project. Stdlib only, single file.

--------------------------------------------------------------------------
NSCR (on-disk magic "RCSN") -- SCRN block
--------------------------------------------------------------------------
Standard Nitro resource shape, same convention as every other chunk this
project has already opened (NCGR/NCLR/NCER/NANR): a 16-byte common file
header (magic, byte-order mark, version, file size, header size, block
count) followed by one SCRN block (stored reversed on disk as "NRCS"):
magic(4) + size(4), then a 12-byte sub-header and the tile-entry array:

    0x00  u16  screen_width_px
    0x02  u16  screen_height_px
    0x04  u32  unknown        (0 in almost every sub-file scanned; a
                                handful of a/0/3/4's sub-files instead have
                                1 here -- meaning not determined, preserved
                                verbatim for round-trip)
    0x08  u32  data_size      screen_width_px/8 * screen_height_px/8 * 2,
                               confirmed exactly for every sub-file scanned
    0x0C  ...  data_size bytes of u16 screen entries, row-major,
               tiles_wide = screen_width_px/8 wide

Screen entry (u16, general NDS "BG screen format" convention, not sourced
from any decomp project):
    bits 0-9    tile_num     index into the paired NCGR's tile data
    bit 10      hflip
    bit 11      vflip
    bits 12-15  palette      which 16-color bank of the paired NCLR (4bpp
                              tilesets only; ignored for 8bpp)

Every NSCR sub-file sampled across the 12 archives this pass covers (the
full round-trip scan below is broader) has block_count == 1, `unknown`
head byte 0 or 1 with no other trailing bytes, and its own file_size field
exactly equal to header_size + block_size (no slack/padding past the
block) -- a clean, uniform shape with no compression seen on any NSCR
sub-file in the archives this pass opened.

--------------------------------------------------------------------------
Pairing rule (NCGR/NCLR <-> NSCR)
--------------------------------------------------------------------------
The mission's "standard grouping: consecutive NCGR, NCLR, NSCR triples"
does NOT hold in this ROM. Every background-shaped archive this pass
inspected is laid out as **grouped runs by chunk type**, not interleaved
triples: all of an archive's NCLR sub-files first, then all its NCGR
sub-files, then (sometimes) NCER/NANR, then all its NSCR sub-files --
confirmed by dumping the full per-archive magic sequence for 12 candidate
archives (see docs/ASSETS.md for the raw dumps). `a/0/0/1` is the one
partial exception found (NCLR, NCGR, NSCR x4, NCGR, NCLR -- a "sandwich",
not a triple either).

With no reliable index-arithmetic or count-based correspondence found (the
NCLR/NCGR/NSCR counts per archive do not divide evenly against each other
in most archives, e.g. `a/0/3/3` is 11 NCLR / 9 NCGR / 10 NSCR), this
module uses the same rule `overworld.py` already validated for `a/0/2/5`'s
irregular NCGR/NCLR interleave: **each NSCR pairs with the nearest
preceding NCGR sub-file index and the nearest preceding NCLR sub-file
index** (falling back to the nearest *following* one if the NSCR sits
before any NCGR/NCLR in the archive). In every grouped-run archive this
collapses to "the last NCGR and last NCLR before the NSCR run", i.e. one
shared tileset+palette for every screen in that archive -- validated by
rendering (see "Samples" below): every one of the 10 samples this pass
rendered comes out as a coherent tile grid (repeating structured patterns,
readable text-box borders, consistent color blocks), not palette-mismatch
noise, which is this project's established bar for accepting a pairing
heuristic (see `overworld.py`'s docstring for the same bar applied to
`a/0/2/5`). Known gap: because the rule always resolves to the *last*
NCLR/NCGR in a run, any earlier NCLR/NCGR sub-files in a multi-palette or
multi-tileset archive are never selected by this heuristic and are left
unexplored (e.g. `a/0/3/3`'s other 10 NCLR sub-files) -- no in-archive
evidence (index table, count match) was found to justify picking any of
them over the others, so this is reported as a limitation, not resolved.

--------------------------------------------------------------------------
Usage
--------------------------------------------------------------------------
    python tools/assets/background.py --sample                 # 10 samples
    python tools/assets/background.py --archive a/0/0/1 --index 2
    python tools/assets/background.py --verify                 # NSCR round trip
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402
import lz11  # noqa: E402
import battle_sprite as bs  # noqa: E402  (parse_nclr, write_png_rgb8)

EXTRACT_ROOT = os.path.join("extract", "data")
OUT_DIR = os.path.join("build", "assets", "backgrounds")

# Candidate archives: every "map/tileset graphics (guess)" / "trainer/item/UI
# sprites (guess)" archive from docs/ASSETS.md whose dominant-formats column
# lists NSCR, plus the two ruled-out-as-character "tileset/map bundle"
# archives noted in docs/ASSETS.md's "Ruled out, not pixel-verified" section
# (a/1/5/9, a/1/3/7) and titledemo.narc/soundstatus.narc by name (title/menu
# candidates by name alone).
CANDIDATE_ARCHIVES = [
    "a/0/0/1", "a/0/2/9", "a/0/3/3", "a/0/3/4", "a/0/4/6", "a/0/7/7",
    "a/1/0/2", "a/1/2/0", "a/1/4/3", "a/1/4/4", "a/1/5/9", "a/1/8/8",
    "a/1/9/2", "a/1/9/3", "a/2/0/6", "a/2/2/3", "a/1/3/7",
]
NAMED_CANDIDATES = ["soundstatus.narc", "titledemo.narc", "skb.narc"]


def archive_path(name):
    if name.endswith(".narc") or "/" not in name:
        return os.path.join(EXTRACT_ROOT, name)
    return os.path.join(EXTRACT_ROOT, *name.split("/"))


def _hdr(data):
    return struct.unpack_from("<4sHHIHH", data, 0)


# ---------------------------------------------------------------------------
# NSCR (RCSN) -- parse + byte-exact re-serialize
# ---------------------------------------------------------------------------

class NscrFile:
    def __init__(self, data):
        magic, bom, ver, fsize, hsize, nblk = _hdr(data)
        if magic != b"RCSN":
            raise ValueError(f"not an RCSN (NSCR) resource: {magic!r}")
        if nblk != 1:
            raise ValueError(f"NSCR with {nblk} blocks not supported by this round-tripper")
        pos = hsize
        bmagic, bsize = struct.unpack_from("<4sI", data, pos)
        if bmagic != b"NRCS":
            raise ValueError(f"expected NRCS (SCRN) block, found {bmagic!r}")
        body = data[pos + 8:pos + bsize]
        width, height, unk, dsize = struct.unpack_from("<HHII", body, 0)
        entry_bytes = body[12:12 + dsize]
        n = dsize // 2
        raw = struct.unpack_from(f"<{n}H", entry_bytes, 0)
        trailing = body[12 + dsize:]  # bytes after the declared entry array, if any

        self.bom = bom
        self.ver = ver
        self.hsize = hsize
        self.width = width
        self.height = height
        self.unk = unk
        self.trailing = trailing
        self.entries = [(v & 0x3FF, (v >> 10) & 1, (v >> 11) & 1, (v >> 12) & 0xF)
                         for v in raw]

    @property
    def tiles_wide(self):
        return self.width // 8

    @property
    def tiles_high(self):
        return self.height // 8

    def encode(self):
        """Re-serialize to the exact original uncompressed NSCR bytes."""
        packed = [tile | (hf << 10) | (vf << 11) | (pal << 12)
                  for tile, hf, vf, pal in self.entries]
        entry_bytes = struct.pack(f"<{len(packed)}H", *packed)
        body = struct.pack("<HHII", self.width, self.height, self.unk,
                            len(entry_bytes)) + entry_bytes + self.trailing
        bsize = 8 + len(body)
        block = b"NRCS" + struct.pack("<I", bsize) + body
        fsize = self.hsize + bsize
        file_hdr = struct.pack("<4sHHIHH", b"RCSN", self.bom, self.ver, fsize,
                                self.hsize, 1)
        return file_hdr + block


def parse_nscr(data):
    return NscrFile(data)


# ---------------------------------------------------------------------------
# NCGR (RGCN) -- tile data, 4bpp or 8bpp, with round-trip-safe extra-block
# passthrough (this format family carries an optional trailing SOPC block
# this pass does not need to decode, e.g. seen after a/0/0/1#1's RAHC block)
# ---------------------------------------------------------------------------

class NcgrTiles:
    def __init__(self, data):
        magic, bom, ver, fsize, hsize, nblk = _hdr(data)
        if magic != b"RGCN":
            raise ValueError(f"not an RGCN (NCGR) resource: {magic!r}")
        pos = hsize
        bmagic, bsize = struct.unpack_from("<4sI", data, pos)
        if bmagic != b"RAHC":
            raise ValueError(f"expected RAHC (CHAR) block, found {bmagic!r}")
        body = data[pos + 8:pos + bsize]
        tile_num_y, tile_num_x = struct.unpack_from("<HH", body, 0)
        bitdepth, = struct.unpack_from("<I", body, 4)
        _pad, flag = struct.unpack_from("<HH", body, 8)
        _unk1, data_size, data_ofs = struct.unpack_from("<III", body, 12)
        self.bitdepth = bitdepth
        self.bytes_per_tile = 64 if bitdepth == 4 else 32  # 8 = 8bpp per this ROM's convention (3=4bpp,4=8bpp)
        self.tile_data = body[data_ofs:data_ofs + data_size]
        self.tile_count = len(self.tile_data) // self.bytes_per_tile

    def tile_pixels(self, tile_index, hflip=0, vflip=0):
        """Return a flat 64-entry (8x8, row-major) list of palette indices
        for one tile, honouring the screen entry's flip bits."""
        off = tile_index * self.bytes_per_tile
        tile = self.tile_data[off:off + self.bytes_per_tile]
        out = [0] * 64
        if len(tile) < self.bytes_per_tile:
            return out  # tile index past the end of this NCGR's data: blank
        if self.bytes_per_tile == 32:  # 4bpp
            for ly in range(8):
                row = tile[ly * 4:ly * 4 + 4]
                for lx4 in range(4):
                    b = row[lx4]
                    out[ly * 8 + lx4 * 2] = b & 0x0F
                    out[ly * 8 + lx4 * 2 + 1] = (b >> 4) & 0x0F
        else:  # 8bpp
            out = list(tile)
        if hflip:
            out = [out[ly * 8 + (7 - lx)] for ly in range(8) for lx in range(8)]
        if vflip:
            out = [out[(7 - ly) * 8 + lx] for ly in range(8) for lx in range(8)]
        return out


def parse_ncgr(data):
    return NcgrTiles(data)


# ---------------------------------------------------------------------------
# Compositing
# ---------------------------------------------------------------------------

def compose(nscr, ncgr, palette):
    """Render one NSCR against its paired NCGR tile data + NCLR palette.
    Returns (width, height, flat rgb list)."""
    tw, th = nscr.tiles_wide, nscr.tiles_high
    width, height = nscr.width, nscr.height
    rgb = [(0, 0, 0)] * (width * height)
    n_colors = len(palette)
    for ty in range(th):
        for tx in range(tw):
            idx = ty * tw + tx
            if idx >= len(nscr.entries):
                continue
            tile_num, hf, vf, pal = nscr.entries[idx]
            pixels = ncgr.tile_pixels(tile_num, hf, vf)
            if ncgr.bytes_per_tile == 32:
                base = pal * 16
            else:
                base = 0
            for ly in range(8):
                py = ty * 8 + ly
                row_off = py * width + tx * 8
                for lx in range(8):
                    p = pixels[ly * 8 + lx]
                    ci = base + p
                    rgb[row_off + lx] = palette[ci] if 0 <= ci < n_colors else (255, 0, 255)
    return width, height, rgb


# ---------------------------------------------------------------------------
# Archive-level helpers: nearest-preceding NCGR/NCLR lookup (see module
# docstring "Pairing rule")
# ---------------------------------------------------------------------------

def find_magic_indices(n, magic):
    return [sf.index for sf in n.subfiles if sf.magic == magic]


def nearest_preceding_or_following(sorted_indices, x):
    import bisect
    i = bisect.bisect_right(sorted_indices, x) - 1
    if i >= 0:
        return sorted_indices[i]
    j = bisect.bisect_left(sorted_indices, x)
    return sorted_indices[j] if j < len(sorted_indices) else None


def read_decompressed(n, index):
    raw = n.read(index)
    kind, dec = narc.try_decompress(raw)
    return (dec if dec is not None else raw), kind


def load_pair_for(n, nscr_index, ncgr_indices, nclr_indices):
    gi = nearest_preceding_or_following(ncgr_indices, nscr_index)
    li = nearest_preceding_or_following(nclr_indices, nscr_index)
    if gi is None or li is None:
        raise ValueError(f"sub-file {nscr_index}: archive has no usable NCGR/NCLR")
    ncgr_data, _ = read_decompressed(n, gi)
    nclr_data, _ = read_decompressed(n, li)
    ncgr = parse_ncgr(ncgr_data)
    palette = bs.parse_nclr(nclr_data)
    return ncgr, palette, gi, li


def render_one(n, nscr_index, ncgr_indices, nclr_indices, out_path):
    nscr_data, kind = read_decompressed(n, nscr_index)
    nscr = parse_nscr(nscr_data)
    ncgr, palette, gi, li = load_pair_for(n, nscr_index, ncgr_indices, nclr_indices)
    w, h, rgb = compose(nscr, ncgr, palette)
    bs.write_png_rgb8(out_path, w, h, rgb)
    return w, h, gi, li


# ---------------------------------------------------------------------------
# Round trip
# ---------------------------------------------------------------------------

def verify_archive(path):
    n = narc.parse_file(path)
    ok = fail = skipped = 0
    for sf in n.subfiles:
        raw = n.read(sf.index)
        kind, dec = narc.try_decompress(raw)
        if kind is not None and dec is None:
            skipped += 1
            continue
        payload = dec if dec is not None else raw
        if payload[:4] != b"RCSN":
            continue
        try:
            nscr = parse_nscr(payload)
            reenc = nscr.encode()
        except Exception as exc:  # noqa: BLE001 -- best-effort batch, log and continue
            fail += 1
            print(f"[!] {path}#{sf.index}: parse/encode error ({exc})")
            continue
        if kind == "LZ11":
            reenc = lz11.compress(reenc)
        expected = raw if kind is not None else payload
        if reenc == expected:
            ok += 1
        else:
            fail += 1
            print(f"[!] {path}#{sf.index}: round trip mismatch")
    return ok, fail, skipped


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--archive", default=None, help="one archive, e.g. a/0/0/1 or soundstatus.narc")
    ap.add_argument("--index", type=int, default=None, help="one NSCR sub-file index to render")
    ap.add_argument("--sample", action="store_true", help="render 10 samples across candidate archives")
    ap.add_argument("--verify", action="store_true", help="NSCR round-trip check over all candidate archives")
    ap.add_argument("--out", default=OUT_DIR)
    args = ap.parse_args(argv)

    if args.verify:
        total_ok = total_fail = total_skip = 0
        for name in CANDIDATE_ARCHIVES + NAMED_CANDIDATES:
            path = archive_path(name)
            if not os.path.exists(path):
                continue
            ok, fail, skipped = verify_archive(path)
            print(f"[*] {name}: NSCR round trip {ok} ok, {fail} mismatched, {skipped} skipped")
            total_ok += ok
            total_fail += fail
            total_skip += skipped
        print(f"[*] TOTAL: {total_ok} ok, {total_fail} mismatched, {total_skip} skipped")
        return 0 if total_fail == 0 else 1

    os.makedirs(args.out, exist_ok=True)

    if args.archive and args.index is not None:
        path = archive_path(args.archive)
        n = narc.parse_file(path)
        ncgr_indices = find_magic_indices(n, b"RGCN")
        nclr_indices = find_magic_indices(n, b"RLCN")
        safe_name = args.archive.replace("/", "_").replace(".narc", "")
        out_path = os.path.join(args.out, f"{safe_name}_{args.index}.png")
        w, h, gi, li = render_one(n, args.index, ncgr_indices, nclr_indices, out_path)
        print(f"[*] wrote {out_path} ({w}x{h}), NCGR#{gi}, NCLR#{li}")
        return 0

    if args.sample:
        # Spread 10 samples across the candidate archive list: one NSCR per
        # archive (the first one), cycling through archives until 10 are
        # rendered, so the sample set covers many archives, not many screens
        # of the same one.
        rendered = 0
        for name in CANDIDATE_ARCHIVES + NAMED_CANDIDATES:
            if rendered >= 10:
                break
            path = archive_path(name)
            if not os.path.exists(path):
                continue
            try:
                n = narc.parse_file(path)
            except Exception as exc:  # noqa: BLE001
                print(f"[!] {name}: failed to parse ({exc})")
                continue
            nscr_indices = find_magic_indices(n, b"RCSN")
            if not nscr_indices:
                continue
            ncgr_indices = find_magic_indices(n, b"RGCN")
            nclr_indices = find_magic_indices(n, b"RLCN")
            pick = nscr_indices[0]
            safe_name = name.replace("/", "_").replace(".narc", "")
            out_path = os.path.join(args.out, f"{safe_name}_{pick}.png")
            try:
                w, h, gi, li = render_one(n, pick, ncgr_indices, nclr_indices, out_path)
            except Exception as exc:  # noqa: BLE001
                print(f"[!] {name}#{pick}: skipped ({exc})")
                continue
            print(f"[*] {name}#{pick}: wrote {out_path} ({w}x{h}), NCGR#{gi}, NCLR#{li}")
            rendered += 1
        print(f"[*] --sample: {rendered} rendered, out={args.out}")
        return 0

    ap.error("give --archive/--index, or --sample, or --verify")


if __name__ == "__main__":
    sys.exit(main())
