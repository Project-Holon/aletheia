#!/usr/bin/env python3
"""
inner_magic_census.py -- histogram the INNER magic of every sub-file across
every NARC under extract/data/, decompressing LZ77/LZ11/Huffman/RLE payloads
first instead of relying on the compressed sub-file's own opaque header byte.

Written from scratch for the aletheia project. Stdlib only, single file.

--------------------------------------------------------------------------
Why this pass exists
--------------------------------------------------------------------------
`tools/assets/inventory.py` already histograms every sub-file's magic, but
it does so on the RAW on-disk bytes: a compressed sub-file's "magic" in that
histogram is its BIOS compression tag byte (0x10/0x11/0x20+/0x30), not what
it decompresses to. `tools/assets/trainer_locate.py --widen` goes further
(decompresses to check for a large NCGR specifically) but only ever asks
"is there an NCGR with >=100 tiles", not "what is the full population of
decompressed magics in this archive, and does that population look like a
per-trainer NCGR+NCER+NANR bundle". No earlier pass in this project has
built a true post-decompression magic census over every sub-file of every
archive. This module closes that gap directly, per this pass's mission.

--------------------------------------------------------------------------
Method
--------------------------------------------------------------------------
For every NARC under extract/data/ (non-NARC leaf files -- SDAT archives,
lone compressed blobs -- are skipped; they have no sub-files to census) and
every one of its sub-files:

  - If the sub-file opens with a recognised BIOS compression header
    (LZ77/LZ11/Huffman4/Huffman8/RLE, via narc.sniff_compression), decompress
    it (narc.try_decompress -- all four kinds are implemented, not just
    LZ77/LZ11) and record the FIRST 4 BYTES OF THE DECOMPRESSED PAYLOAD as
    its inner magic, plus the decompressed size (from the payload actually
    produced, which matches the header's own declared size since
    try_decompress verifies this by construction).
  - If decompression fails outright (a recognised header but the decoder
    raises, e.g. a malformed stream) it is counted separately as
    "<kind>-undecodable" and excluded from the magic histogram.
  - Otherwise (no compression header) the sub-file's own first 4 bytes are
    its magic directly, with its on-disk size as the "decompressed" size.

Every magic is labelled through inventory.py's own KNOWN_MAGICS table (so
"RGCN" reads as "NCGR (tile/character data)" etc, matching this project's
existing vocabulary) with the same printable-ASCII / hex fallback for
unrecognised tags.

--------------------------------------------------------------------------
Shortlist rule (this pass's mission)
--------------------------------------------------------------------------
An archive is shortlisted when its per-archive inner-magic histogram has
RGCN (NCGR) + RECN (NCER) + RNAN (NANR) ALL present (a genuine "bundle", not
just one or two of the three) and the combined count of those three magics
falls in [100, 400] -- the mission's own band for "~150 Gen 5 trainer
classes, each with a front sprite and possibly a back sprite and an
animation".

For each shortlisted archive, every NCER (RECN) sub-file (compressed or not,
via the same decompress-first path) is parsed (both the 8-byte "simple"
cell-info-type-0 records `rig.Ncer` handles and the 16-byte "extended"
bounding-box cell-info-type-1 records `overworld.parse_ncer_shared` handles
-- this module has its own small generic parser covering both, see
`parse_ncer_generic`) and every cell's OAM bounding box is computed (the
same per-OAM union-of-rects approach as `overworld.render_cell`). An archive
passes the OAM-size filter if at least one cell's bounding box is >=64px in
BOTH width and height.

--------------------------------------------------------------------------
Usage
--------------------------------------------------------------------------
    python tools/assets/inner_magic_census.py                 full census, print summary + shortlist
    python tools/assets/inner_magic_census.py --json build/assets/inner_magic_census.json
    python tools/assets/inner_magic_census.py --archive extract/data/a/0/1/2   single-archive detail
"""

import argparse
import json
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402
import rig  # noqa: E402  (Oam -- shape/size -> pixel bbox decode; TILE_BYTES_4BPP)
import battle_sprite as bs  # noqa: E402  (parse_nclr, write_png_rgb8)

DATA_ROOT = os.path.join("extract", "data")
OUT_JSON = os.path.join("build", "assets", "inner_magic_census.json")
RENDER_OUT_DIR = os.path.join("build", "assets", "trainer_census")

# Same table as inventory.py's KNOWN_MAGICS -- kept local (read-only mirror)
# so this module has no import-order dependency on inventory.py.
KNOWN_MAGICS = {
    b"RGCN": "NCGR (tile/character data)",
    b"RLCN": "NCLR (palette)",
    b"RCSN": "NSCR (screen/map)",
    b"RECN": "NCER (cell bank)",
    b"RNAN": "NANR (cell animation)",
    b"BMD0": "NSBMD (model)",
    b"BTX0": "NSBTX (texture)",
    b"BCA0": "NSBCA (animation)",
    b"SDAT": "SDAT (sound archive)",
    b"RTCN": "NCLR variant / RTCN",
    b"NCBR": "raw character data, no BTAF-style chunk",
    b"RCMN": "NMCR (multi-cell resource, guess)",
    b"RAMN": "NMAR (multi-cell animation resource, guess)",
    b"BTA0": "NSBTA (texture SRT animation)",
    b"BTP0": "NSBTP (texture pattern animation)",
    b"BMA0": "NSBMA (material color animation)",
    b"BVA0": "NSBVA (visibility animation)",
    b"RTFN": "NFTR variant (font, guess)",
    b"SBNK": "SDAT sound bank sub-chunk",
    b"SSEQ": "SDAT sequence sub-chunk",
    b"SWAR": "SDAT wave archive sub-chunk",
}

BUNDLE_MAGICS = (b"RGCN", b"RECN", b"RNAN")  # NCGR, NCER, NANR
SHORTLIST_MIN = 100
SHORTLIST_MAX = 400
MIN_CELL_PX = 64


def magic_label(magic):
    if magic in KNOWN_MAGICS:
        return KNOWN_MAGICS[magic]
    try:
        s = magic.decode("ascii")
        if s.isprintable() and all(32 <= b < 127 for b in magic):
            return s
    except UnicodeDecodeError:
        pass
    return "0x" + magic.hex()


def inner_magic_and_size(raw):
    """Return (magic_bytes_or_None, decompressed_size, note) for one
    sub-file's INNER content: decompress first if a BIOS compression header
    is present, else use the raw bytes directly. `note` is "" for a clean
    read, or "<kind>-undecodable" if a recognised compression header's
    decoder failed."""
    info = narc.sniff_compression(raw)
    if info is None:
        magic = raw[:4] if len(raw) >= 4 else raw
        return magic, len(raw), ""
    kind, _declared_size = info
    try:
        _kind, dec = narc.try_decompress(raw)
    except narc.NarcError:
        return None, 0, f"{kind}-undecodable"
    if dec is None:
        return None, 0, f"{kind}-undecodable"
    magic = dec[:4] if len(dec) >= 4 else dec
    return magic, len(dec), ""


def census_archive(path):
    """Return a per-archive report dict."""
    n = narc.parse_file(path)
    magic_hist = {}          # label -> count
    undecodable_hist = {}    # "<kind>-undecodable" -> count
    per_magic_sizes = {}     # raw 4-byte magic -> [decompressed sizes]
    for sf in n.subfiles:
        raw = n.read(sf.index)
        magic, size, note = inner_magic_and_size(raw)
        if note:
            undecodable_hist[note] = undecodable_hist.get(note, 0) + 1
            continue
        label = magic_label(magic)
        magic_hist[label] = magic_hist.get(label, 0) + 1
        per_magic_sizes.setdefault(magic, []).append(size)
    bundle_count = sum(len(per_magic_sizes.get(m, [])) for m in BUNDLE_MAGICS)
    has_all_three = all(per_magic_sizes.get(m) for m in BUNDLE_MAGICS)
    return {
        "path": path,
        "sub_file_count": n.file_count,
        "inner_magic_histogram": magic_hist,
        "undecodable_histogram": undecodable_hist,
        "bundle_count": bundle_count,        # RGCN+RECN+RNAN combined
        "has_ncgr_ncer_nanr": has_all_three,
        "_per_magic_sizes": per_magic_sizes,  # internal use (shortlist OAM check)
    }


def walk_narc_paths(root):
    out = []
    for dirpath, dirnames, filenames in os.walk(root):
        dirnames.sort()
        for fn in sorted(filenames):
            full = os.path.join(dirpath, fn)
            with open(full, "rb") as fh:
                head = fh.read(4)
            if head == b"NARC":
                out.append(full)
    return out


# ---------------------------------------------------------------------------
# Generic NCER parser: covers both cell_info_type 0 (8-byte simple cell
# records, `rig.Ncer`'s shape) and cell_info_type 1 (16-byte extended/bbox
# cell records, `overworld.parse_ncer_shared`'s shape) in one function, so
# the shortlist's OAM-size check works uniformly across archives without
# knowing in advance which layout a given NCER uses.
# ---------------------------------------------------------------------------

class GenericCell:
    __slots__ = ("num_oam", "oams")

    def __init__(self, num_oam, oams):
        self.num_oam = num_oam
        self.oams = oams


def parse_ncer_generic(data):
    magic, bom, ver, fsize, hsize, nblk = struct.unpack_from("<4sHHIHH", data, 0)
    if magic != b"RECN":
        raise ValueError(f"not an RECN (NCER) resource: {magic!r}")
    pos = hsize
    bmagic, bsize = struct.unpack_from("<4sI", data, pos)
    if bmagic != b"KBEC":
        raise ValueError(f"expected KBEC (CEBK) block, found {bmagic!r}")
    body = data[pos + 8:pos + bsize]
    num_cells, cell_info_type = struct.unpack_from("<HH", body, 0)
    cell_data_ofs, mapping_type, _reserved = struct.unpack_from("<III", body, 4)
    stride = 16 if cell_info_type == 1 else 8

    cell_hdrs = []
    for i in range(num_cells):
        off = cell_data_ofs + i * stride
        num_oam, cell_attr, oam_ofs = struct.unpack_from("<HHI", body, off)
        cell_hdrs.append((num_oam, oam_ofs))

    oam_arr_start = cell_data_ofs + num_cells * stride
    cells = []
    for num_oam, oam_ofs in cell_hdrs:
        oams = []
        for i in range(num_oam):
            off = oam_arr_start + oam_ofs + i * 6
            a0, a1, a2 = struct.unpack_from("<HHH", body, off)
            oams.append(rig.Oam(a0, a1, a2))
        cells.append(GenericCell(num_oam, oams))
    return cells, mapping_type, cell_info_type


def cell_bbox(cell):
    if not cell.oams:
        return 0, 0
    minx = miny = 10 ** 9
    maxx = maxy = -10 ** 9
    for oam in cell.oams:
        minx = min(minx, oam.x)
        miny = min(miny, oam.y)
        maxx = max(maxx, oam.x + oam.w)
        maxy = max(maxy, oam.y + oam.h)
    return maxx - minx, maxy - miny


# ---------------------------------------------------------------------------
# Shortlist rendering: mapping-type-aware OAM compositing.
#
# `trainer_locate.py`'s existing raw-tile-grid renderer lays out every tile
# of an NCGR in a plain grid -- it never resolves per-OAM placement, and
# (checked this pass) never applies a cell bank's own `mapping_type` (the
# 32B/64B/128B tile-stride boundary selector documented in
# `overworld.py`'s module docstring): reading a `mapping_type` 1 or 2 NCER's
# `tile_idx` field as a dense (mapping_type 0) tile index silently
# under-addresses every tile past the first, which is why an early version
# of this module's own probe render of `a/0/7/2` came out as a strip of
# disconnected pixel fragments floating in a green field until this was
# fixed. `render_oam_generic`/`render_cell_generic` below scale `tile_idx`
# by the cell's declared `mapping_type` (1/2/4 dense-4bpp-tiles per unit)
# before addressing the NCGR -- this is the "same generic compositing
# approach as `overworld.py --archive`" the mission asks for, since
# `overworld.py` itself only ever handles mapping_type 0 (a/0/0/7 and
# a/0/2/5 both happen to be mapping_type 0) and has no mapping-type-aware
# path of its own to call into for these archives' mapping_type 1/2 cells.
# ---------------------------------------------------------------------------

MAPPING_TYPE_TILE_MULTIPLIER = {0: 1, 1: 2, 2: 4}


class FlexNcgr:
    """NCGR tile reader covering BOTH `char_format` values seen in this
    ROM's NCGR sub-headers (offset 12 of the 24-byte RAHC sub-header,
    right after `pixel_fmt`/`mapping_type`; see `rig.Ncgr`'s docstring,
    which first identified this field):

      - char_format 0: tiled -- 8x8 blocks packed end to end in tile_data,
        addressed by flat index (`tile_data[idx*32:(idx+1)*32]` at 4bpp).
        `tile_num_x`/`tile_num_y` are sometimes a `0xFFFF` sentinel here
        (see docs/ASSETS.md, `a/0/2/5`) and MUST be ignored for addressing
        in that case -- this reader never allocates a `tile_num_x *
        tile_num_y` canvas for this branch, so the sentinel is harmless.
      - char_format 1: bitmap -- one linear `tile_num_x*8` x `tile_num_y*8`
        pixel image; a cell OAM's tile index addresses an 8x8 BLOCK
        POSITION in that image (`bx = (idx % tile_num_x) * 8, by = (idx //
        tile_num_x) * 8`), not a flat tile offset. `trainer_locate.RawNcgr`
        (dense-only) silently mis-renders this case as near-empty noise --
        confirmed this pass on `a/0/7/2`'s per-entity NCGR, char_format 1,
        which produced <5% nonzero pixels under dense addressing and a
        coherent icon once read as a bitmap (see checkpoint in
        docs/ASSETS.md, "trainer census" section).

    Only reads the first RAHC block; tolerant of `nblk` counts other than
    1 (matches `trainer_locate.RawNcgr`'s forgiving read, needed for some
    NCGR sub-files that declare extra trailing blocks this project does
    not otherwise decode)."""

    def __init__(self, data):
        magic, bom, ver, fsize, hsize, nblk = struct.unpack_from("<4sHHIHH", data, 0)
        if magic != b"RGCN":
            raise ValueError(f"not an RGCN (NCGR) resource: {magic!r}")
        pos = hsize
        bmagic, bsize = struct.unpack_from("<4sI", data, pos)
        if bmagic != b"RAHC":
            raise ValueError(f"expected RAHC (CHAR) block, found {bmagic!r}")
        body = data[pos + 8:pos + bsize]
        tile_num_y, tile_num_x = struct.unpack_from("<HH", body, 0)
        _pixel_fmt, _mapping_type, char_format = struct.unpack_from("<III", body, 4)
        data_size, data_ofs = struct.unpack_from("<II", body, 16)
        self.tile_num_x = tile_num_x
        self.tile_num_y = tile_num_y
        self.char_format = char_format
        self.tile_data = body[data_ofs:data_ofs + data_size]
        self.tile_count = len(self.tile_data) // rig.TILE_BYTES_4BPP

        self._bitmap = None
        self._bw = self._bh = 0
        if char_format == 1 and tile_num_x not in (0, 0xFFFF) and tile_num_y not in (0, 0xFFFF):
            self._bw, self._bh = tile_num_x * 8, tile_num_y * 8
            if self._bw * self._bh <= 4_000_000:  # sanity guard, never hit in this ROM
                px = [0] * (self._bw * self._bh)
                for i, b in enumerate(self.tile_data):
                    p = i * 2
                    if p + 1 >= len(px):
                        break
                    px[p] = b & 0x0F
                    px[p + 1] = (b >> 4) & 0x0F
                self._bitmap = px
                self.tile_count = tile_num_x * tile_num_y

    def tile_nibbles(self, tile_index):
        if self._bitmap is not None:
            bx = (tile_index % self.tile_num_x) * 8
            by = (tile_index // self.tile_num_x) * 8
            if by + 8 > self._bh or bx + 8 > self._bw:
                return [0] * 64
            out = []
            w = self._bw
            for ly in range(8):
                row = (by + ly) * w + bx
                out.extend(self._bitmap[row:row + 8])
            return out
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


def render_oam_generic(ncgr, oam, mapping_type):
    mul = MAPPING_TYPE_TILE_MULTIPLIER.get(mapping_type, 1)
    tiles_w = oam.w // 8
    tiles_h = oam.h // 8
    px = [[0] * oam.w for _ in range(oam.h)]
    base = oam.tile_idx * mul
    for ty in range(tiles_h):
        for tx in range(tiles_w):
            tidx = base + ty * tiles_w + tx
            if tidx >= ncgr.tile_count:
                continue
            nib = ncgr.tile_nibbles(tidx)
            for ly in range(8):
                for lx in range(8):
                    px[ty * 8 + ly][tx * 8 + lx] = nib[ly * 8 + lx]
    if oam.hflip:
        px = [row[::-1] for row in px]
    if oam.vflip:
        px = px[::-1]
    return px


def render_cell_generic(ncgr, cell, mapping_type):
    if not cell.oams:
        return 1, 1, [0]
    minx = min(o.x for o in cell.oams)
    miny = min(o.y for o in cell.oams)
    maxx = max(o.x + o.w for o in cell.oams)
    maxy = max(o.y + o.h for o in cell.oams)
    w, h = maxx - minx, maxy - miny
    canvas = [[0] * w for _ in range(h)]
    for oam in cell.oams:
        rows = render_oam_generic(ncgr, oam, mapping_type)
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


def upscale_nearest(flat, w, h, scale=6):
    W, H = w * scale, h * scale
    big = [0] * (W * H)
    for y in range(h):
        for x in range(w):
            v = flat[y * w + x]
            for sy in range(scale):
                for sx in range(scale):
                    big[(y * scale + sy) * W + x * scale + sx] = v
    return W, H, big


def find_ncer_samples(path, n_samples=2):
    """Return up to `n_samples` (ncer_index, ncgr_index, nclr_index,
    mapping_type) tuples for a shortlisted archive: the NCER sub-files with
    the largest cell bounding boxes (the mission's own "render two samples"
    -- biased toward the biggest cells, since that is what a trainer figure
    would need), each paired with the nearest PRECEDING NCGR and NCLR
    sub-file index in archive order."""
    n = narc.parse_file(path)
    ncgr_idx = []
    nclr_idx = []
    ncer_hits = []  # (area, ncer_index, mapping_type)
    for sf in n.subfiles:
        raw = n.read(sf.index)
        magic, _size, note = inner_magic_and_size(raw)
        if note:
            continue
        if magic == b"RGCN":
            ncgr_idx.append(sf.index)
        elif magic == b"RLCN":
            nclr_idx.append(sf.index)
        elif magic == b"RECN":
            info = narc.sniff_compression(raw)
            payload = raw
            if info is not None:
                _kind, payload = narc.try_decompress(raw)
            if payload is None:
                continue
            try:
                cells, mapping_type, _cit = parse_ncer_generic(payload)
            except Exception:  # noqa: BLE001
                continue
            best_area = 0
            for cell in cells:
                w, h = cell_bbox(cell)
                best_area = max(best_area, w * h)
            ncer_hits.append((best_area, sf.index, mapping_type))
    ncer_hits.sort(key=lambda t: -t[0])
    out = []
    for _area, cidx, mapping_type in ncer_hits[:n_samples]:
        gidx = max((i for i in ncgr_idx if i < cidx), default=(ncgr_idx[0] if ncgr_idx else None))
        lidx = max((i for i in nclr_idx if i < cidx), default=(nclr_idx[0] if nclr_idx else None))
        if gidx is None or lidx is None:
            continue
        out.append((cidx, gidx, lidx, mapping_type))
    return out


def load_decompressed_raw(n, index):
    raw = n.read(index)
    info = narc.sniff_compression(raw)
    if info is None:
        return raw
    _kind, dec = narc.try_decompress(raw)
    return dec if dec is not None else raw


def render_shortlist_samples(shortlist, out_dir=RENDER_OUT_DIR, n_samples=2):
    """Render up to `n_samples` composited (palette-applied, mapping-type-
    aware) cell samples per shortlisted archive, biased toward the largest
    cell bounding box in each archive -- the mission's "render two samples
    from each shortlisted archive with their palettes"."""
    os.makedirs(out_dir, exist_ok=True)
    written = []
    for r in shortlist:
        path = r["path"]
        tag = os.path.relpath(path, DATA_ROOT).replace(os.sep, "_").replace("/", "_")
        n = narc.parse_file(path)
        samples = find_ncer_samples(path, n_samples=n_samples)
        if not samples:
            print(f"[!] {path}: no NCER/NCGR/NCLR triple found, skipping render")
            continue
        for cidx, gidx, lidx, mapping_type in samples:
            try:
                ncgr = FlexNcgr(load_decompressed_raw(n, gidx))
                ncer_cells, _mt, _cit = parse_ncer_generic(load_decompressed_raw(n, cidx))
                palette = bs.parse_nclr(load_decompressed_raw(n, lidx))
            except Exception as exc:  # noqa: BLE001
                print(f"[!] {path} NCER#{cidx}: skipped ({exc})")
                continue
            best_cell = max(ncer_cells, key=lambda c: cell_bbox(c)[0] * cell_bbox(c)[1])
            w, h, flat = render_cell_generic(ncgr, best_cell, mapping_type)
            W, H, big = upscale_nearest(flat, w, h, scale=6)
            rgb = [palette[p] if 0 <= p < len(palette) else (255, 0, 255) for p in big]
            out_path = os.path.join(out_dir, f"{tag}_ncer{cidx:04d}_ncgr{gidx:04d}_pal{lidx:04d}.png")
            bs.write_png_rgb8(out_path, W, H, rgb)
            print(f"[*] {path} NCER#{cidx} (mapping_type={mapping_type}, ncgr#{gidx}, "
                  f"nclr#{lidx}): {w}x{h} cell -> {out_path}")
            written.append(out_path)
    return written


def archive_has_large_cell(path, min_px=MIN_CELL_PX):
    """True if any NCER sub-file in `path` has at least one cell whose OAM
    bounding box is >=min_px in BOTH width and height. Decompresses NCER
    sub-files that are LZ11/LZ77/Huffman/RLE-compressed first."""
    n = narc.parse_file(path)
    best = (0, 0)
    for sf in n.subfiles:
        raw = n.read(sf.index)
        magic, _size, note = inner_magic_and_size(raw)
        if note or magic != b"RECN":
            continue
        # Re-fetch the actual decompressed bytes (inner_magic_and_size only
        # returns the magic + size, not the payload).
        info = narc.sniff_compression(raw)
        payload = raw
        if info is not None:
            _kind, payload = narc.try_decompress(raw)
            if payload is None:
                continue
        try:
            cells, _mapping_type, _cell_info_type = parse_ncer_generic(payload)
        except Exception:  # noqa: BLE001 -- best-effort, skip malformed
            continue
        for cell in cells:
            w, h = cell_bbox(cell)
            if w * h > best[0] * best[1]:
                best = (w, h)
    return best[0] >= min_px and best[1] >= min_px, best


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def run_full_census(root=DATA_ROOT):
    paths = walk_narc_paths(root)
    reports = []
    for path in paths:
        try:
            reports.append(census_archive(path))
        except narc.NarcError as exc:
            print(f"[!] {path}: NARC parse error ({exc})", file=sys.stderr)
    return reports


def print_summary(reports):
    total_totals = {}
    for r in reports:
        for k, v in r["inner_magic_histogram"].items():
            total_totals[k] = total_totals.get(k, 0) + v
    print(f"[*] inner-magic census: {len(reports)} NARCs scanned")
    print("[*] inner-magic totals (post-decompression, ROM-wide):")
    for k, v in sorted(total_totals.items(), key=lambda kv: -kv[1]):
        print(f"      {k:<40} {v}")

    shortlist = [r for r in reports
                 if r["has_ncgr_ncer_nanr"]
                 and SHORTLIST_MIN <= r["bundle_count"] <= SHORTLIST_MAX]
    shortlist.sort(key=lambda r: r["bundle_count"])
    print(f"\n[*] shortlist (NCGR+NCER+NANR all present, combined count in "
          f"[{SHORTLIST_MIN},{SHORTLIST_MAX}]): {len(shortlist)} archive(s)")
    for r in shortlist:
        rel = os.path.relpath(r["path"], DATA_ROOT).replace(os.sep, "/")
        h = r["inner_magic_histogram"]
        print(f"      {rel:<16} bundle_count={r['bundle_count']:<5} "
              f"NCGR={h.get('NCGR (tile/character data)', 0)} "
              f"NCER={h.get('NCER (cell bank)', 0)} "
              f"NANR={h.get('NANR (cell animation)', 0)} "
              f"NCLR={h.get('NCLR (palette)', 0)}")
        has_large, best = archive_has_large_cell(r["path"])
        print(f"          largest NCER cell bbox: {best[0]}x{best[1]} "
              f"({'>=64x64: PASS' if has_large else '<64x64: fail'})")
    return shortlist


def print_archive_detail(path):
    r = census_archive(path)
    print(f"[*] {path}: {r['sub_file_count']} sub-files")
    print("    inner magic histogram:")
    for k, v in sorted(r["inner_magic_histogram"].items(), key=lambda kv: -kv[1]):
        print(f"      {k:<40} {v}")
    if r["undecodable_histogram"]:
        print("    undecodable:")
        for k, v in r["undecodable_histogram"].items():
            print(f"      {k:<40} {v}")
    print(f"    bundle_count (NCGR+NCER+NANR)={r['bundle_count']} "
          f"has_all_three={r['has_ncgr_ncer_nanr']}")
    has_large, best = archive_has_large_cell(path)
    print(f"    largest NCER cell bbox: {best[0]}x{best[1]} "
          f"({'>=64x64' if has_large else '<64x64'})")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--root", default=DATA_ROOT)
    ap.add_argument("--json", default=None,
                     help=f"write full per-archive census to this path (e.g. {OUT_JSON})")
    ap.add_argument("--archive", default=None,
                     help="single-archive detail instead of a full ROM-wide census")
    ap.add_argument("--render-shortlist", action="store_true",
                     help="render two mapping-type-aware, palette-applied samples per "
                          f"shortlisted archive to {RENDER_OUT_DIR}")
    args = ap.parse_args(argv)

    if args.archive:
        print_archive_detail(args.archive)
        return 0

    reports = run_full_census(args.root)
    shortlist = print_summary(reports)

    if args.render_shortlist:
        render_shortlist_samples(shortlist)

    if args.json:
        out_dir = os.path.dirname(args.json)
        if out_dir:
            os.makedirs(out_dir, exist_ok=True)
        serializable = []
        for r in reports:
            r2 = {k: v for k, v in r.items() if not k.startswith("_")}
            serializable.append(r2)
        with open(args.json, "w", encoding="utf-8") as fh:
            json.dump({
                "archives": serializable,
                "shortlist": [os.path.relpath(r["path"], DATA_ROOT).replace(os.sep, "/")
                               for r in shortlist],
            }, fh, indent=2)
        print(f"\n[*] wrote {args.json}")

    return 0


if __name__ == "__main__":
    sys.exit(main())
