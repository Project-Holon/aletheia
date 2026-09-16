#!/usr/bin/env python3
"""
trainer_locate.py -- characterize and render the trainer-battle-sprite
archive candidates from the "Locate pass: walking and trainer sprites"
(docs/ASSETS.md), plus a widen search and a Pokemon-rig tail check.

Written from scratch for aletheia. Stdlib only, single file.

Three jobs, each independently runnable from the CLI:

  1. `--candidates`: characterize `a/0/7/8` and `a/0/8/3` (both NCGR-
     bundle candidates the locate pass shortlisted for trainer battle
     sprites) and render 6 true-colour samples from each to
     `build/assets/trainer_candidates/`.
  2. `--widen`: re-scan every NARC under extract/data/ (via
     build/assets/inventory.json's magic/compression histograms, so only
     archives that could plausibly hold NCGR content are opened) for any
     NCGR sub-file whose CHAR header declares >=100 tiles (an 80x80+
     canvas at 4bpp), excluding `a/0/0/4`/`a/0/5/2` (already known
     Pokemon battle rigs). Renders one raw tile-grid sample per hit
     archive.
  3. `--rig-tail`: render `a/0/0/4` and `a/0/5/2`'s 65 "extra" 20-entry
     blocks past the ~649-species range (species indices 649..713) as
     cell contact sheets, reusing `rig.py`'s per-species renderer, to
     check whether trainer sprites were appended there instead of living
     in a separate archive.

Renders are "raw tile grids": every tile in a sub-file's tile data laid
out left-to-right, top-to-bottom in a roughly square grid, colored with
one palette (see per-mode notes below for which). This does NOT resolve
per-cell OAM placement/flip -- it is a fast, honest "what pixels are in
here" dump, not a composited sprite. Where an archive already has a
purpose-built renderer (`a/0/0/7` -> overworld.py, the Pokemon rigs ->
rig.py), this module reuses that instead of a raw dump.
"""

import argparse
import json
import math
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402
import rig  # noqa: E402  (Oam, render_oam, TILE_BYTES_4BPP, per-species rig renderer)
import battle_sprite as bs  # noqa: E402  (parse_nclr, write_png_rgb8)

INVENTORY_PATH = os.path.join("build", "assets", "inventory.json")
OUT_DIR = os.path.join("build", "assets", "trainer_candidates")
RIG_TAIL_OUT_DIR = os.path.join("build", "assets", "trainer_candidates", "rig_tail")

CANDIDATES = [
    os.path.join("extract", "data", "a", "0", "7", "8"),
    os.path.join("extract", "data", "a", "0", "8", "3"),
]

RIG_ARCHIVES = [
    os.path.join("extract", "data", "a", "0", "0", "4"),
    os.path.join("extract", "data", "a", "0", "5", "2"),
]
RIG_TAIL_SPECIES = range(649, 714)  # the 65 "extra" 20-entry blocks


def _hdr(data):
    magic, bom, ver, fsize, hsize, nblk = struct.unpack_from("<4sHHIHH", data, 0)
    return magic, bom, ver, fsize, hsize, nblk


# ---------------------------------------------------------------------------
# Minimal NCGR reader -- header fields + raw tile data only (no round trip;
# overworld.py/rig.py already own byte-exact NCGR encode/decode, this module
# only needs to read pixels for identification renders).
# ---------------------------------------------------------------------------

class RawNcgr:
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
        _pad, _flag = struct.unpack_from("<HH", body, 8)
        _unk1, data_size, data_ofs = struct.unpack_from("<III", body, 12)
        self.tile_num_x = tile_num_x
        self.tile_num_y = tile_num_y
        self.bitdepth = bitdepth
        self.data_size = data_size
        self.tile_data = body[data_ofs:data_ofs + data_size]
        self.tile_count = len(self.tile_data) // rig.TILE_BYTES_4BPP

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


def load_decompressed(n, index):
    """Read sub-file `index` of NARC `n`, decompressing if it carries a
    recognised BIOS compression header. Returns raw bytes on failure to
    decompress (caller's magic check will then just fail cleanly)."""
    raw = n.read(index)
    try:
        kind, dec = narc.try_decompress(raw)
    except narc.NarcError:
        return raw
    return dec if dec is not None else raw


def render_tile_grid(ncgr, palette, pal_index=0, cols=None):
    """Lay out every tile of `ncgr` left-to-right, top-to-bottom in a
    roughly square grid. Returns (w, h, rgb_pixels)."""
    n = ncgr.tile_count
    if n == 0:
        return 1, 1, [(0, 0, 0)]
    if cols is None:
        cols = max(1, math.ceil(math.sqrt(n)))
    rows = math.ceil(n / cols)
    w, h = cols * 8, rows * 8
    canvas = [[0] * w for _ in range(h)]
    for i in range(n):
        tx, ty = i % cols, i // cols
        nib = ncgr.tile_nibbles(i)
        for ly in range(8):
            for lx in range(8):
                canvas[ty * 8 + ly][tx * 8 + lx] = nib[ly * 8 + lx]
    flat = [v for row in canvas for v in row]
    sub = palette[pal_index * 16:pal_index * 16 + 16]
    rgb = [sub[p] if 0 <= p < len(sub) else (255, 0, 255) for p in flat]
    return w, h, rgb


# ---------------------------------------------------------------------------
# Job 1: candidate archives a/0/7/8, a/0/8/3
# ---------------------------------------------------------------------------

def characterize(archive_path):
    """Print a run-length-encoded structure summary: consecutive sub-files
    of the same resource type collapse into one "kind xN" run, in archive
    order -- shows the bundle's actual layout (grouped-by-type vs
    per-entity-interleaved) at a glance."""
    n = narc.parse_file(archive_path)
    print(f"[*] {archive_path}: {n.file_count} sub-files")
    runs = []
    for sf in n.subfiles:
        kind = sf.magic.decode("ascii", "replace") if len(sf.magic) == 4 else "raw"
        if runs and runs[-1][0] == kind:
            runs[-1][1] += 1
        else:
            runs.append([kind, 1])
    print("    layout:", " ".join(f"{k}x{c}" for k, c in runs))

    ncgr_sizes = []
    for sf in n.subfiles:
        if sf.magic == b"RGCN":
            try:
                ncgr = RawNcgr(n.read(sf.index))
                ncgr_sizes.append(ncgr.tile_count)
            except Exception:  # noqa: BLE001
                pass
    if ncgr_sizes:
        print(f"    NCGR tile counts: min={min(ncgr_sizes)} max={max(ncgr_sizes)} "
              f"n={len(ncgr_sizes)} (>=64 tiles [64x64 canvas budget]: "
              f"{sum(1 for t in ncgr_sizes if t >= 64)})")

    ncer_count = sum(1 for sf in n.subfiles if sf.magic == b"RECN")
    nanr_count = sum(1 for sf in n.subfiles if sf.magic == b"RNAN")
    nclr_count = sum(1 for sf in n.subfiles if sf.magic == b"RLCN")
    print(f"    NCLR={nclr_count} NCER={ncer_count} NANR={nanr_count}")


def render_candidate_samples(archive_path, out_dir, n_samples=6):
    """Render `n_samples` raw tile-grid samples spread across an archive's
    NCGR sub-files, each paired with the nearest PRECEDING NCLR sub-file
    (correct for a/0/8/3's per-group-local-palette layout; a best-effort
    approximation for a/0/7/8's single-shared-palette-bank-of-7 layout,
    where the true per-entity sub-palette selector is unknown -- flagged
    in the render filename)."""
    os.makedirs(out_dir, exist_ok=True)
    n = narc.parse_file(archive_path)
    tag = archive_path.replace(os.sep, "_")

    ncgr_indices = [sf.index for sf in n.subfiles if sf.magic == b"RGCN"]
    nclr_indices = [sf.index for sf in n.subfiles if sf.magic == b"RLCN"]
    if not ncgr_indices or not nclr_indices:
        print(f"[!] {archive_path}: no NCGR or no NCLR, skipping")
        return []

    step = max(1, len(ncgr_indices) // n_samples)
    sample_idx = ncgr_indices[::step][:n_samples]

    written = []
    for gidx in sample_idx:
        # nearest preceding NCLR (or the first NCLR if none precedes)
        pal_idx = max((i for i in nclr_indices if i < gidx), default=nclr_indices[0])
        try:
            palette = bs.parse_nclr(load_decompressed(n, pal_idx))
            ncgr = RawNcgr(load_decompressed(n, gidx))
        except Exception as exc:  # noqa: BLE001
            print(f"[!] sub-file {gidx}: skipped ({exc})")
            continue
        w, h, rgb = render_tile_grid(ncgr, palette)
        out_path = os.path.join(out_dir, f"{tag}_sf{gidx:04d}_pal{pal_idx:04d}.png")
        bs.write_png_rgb8(out_path, w, h, rgb)
        print(f"[*] sub-file {gidx} (pal {pal_idx}): {ncgr.tile_count} tiles, "
              f"{w}x{h} raw grid -> {out_path}")
        written.append(out_path)
    return written


# ---------------------------------------------------------------------------
# Job 2: widen search across every NARC for an 80x80+ (>=100 tile) NCGR
# ---------------------------------------------------------------------------

def find_widen_candidates(min_tiles=100, exclude=("a/0/0/4", "a/0/5/2")):
    """Re-derive the set of archives worth opening from inventory.json's
    already-computed full magic/compression histograms (avoids re-walking
    every one of 247 NitroFS files): any archive with an uncompressed NCGR
    sub-file (magic_histogram), OR any compressed sub-file at all (an NCGR
    could be hiding behind LZ11/Huffman/RLE without exposing its magic to
    the inventory pass, per the ninth lane pass's documented gap). Returns
    {archive_rel_path: [(sub_index, tile_count, compressed_bool), ...]}."""
    with open(INVENTORY_PATH) as f:
        inv = json.load(f)
    files = inv["files"]
    have_ncgr = {x["path"] for x in files if "NCGR (tile/character data)" in x["magic_histogram"]}
    have_compressed = {x["path"] for x in files
                        if any(k != "none" for k in x["compression_histogram"])}
    candidates = sorted((have_ncgr | have_compressed) - set(exclude))

    hits = {}
    for rel in candidates:
        path = os.path.join("extract", "data", *rel.split("/"))
        try:
            n = narc.parse_file(path)
        except Exception as exc:  # noqa: BLE001
            print(f"[!] {rel}: parse error ({exc})")
            continue
        for sf in n.subfiles:
            raw = n.read(sf.index)
            compressed = False
            if sf.magic == b"RGCN":
                payload = raw
            else:
                try:
                    kind, dec = narc.try_decompress(raw)
                except narc.NarcError:
                    continue
                if dec is None:
                    continue
                payload = dec
                compressed = True
            if len(payload) < 4 or payload[:4] != b"RGCN":
                continue
            try:
                ncgr = RawNcgr(payload)
            except Exception:  # noqa: BLE001
                continue
            if ncgr.tile_count >= min_tiles:
                hits.setdefault(rel, []).append((sf.index, ncgr.tile_count, compressed))
    return hits


def render_widen_samples(hits, out_dir):
    """Render one raw tile-grid sample (the sub-file with the most tiles)
    per hit archive, paired with the nearest preceding NCLR if the archive
    has one, else greyscale (palette index == intensity)."""
    os.makedirs(out_dir, exist_ok=True)
    written = []
    for rel in sorted(hits, key=lambda p: -max(t for _, t, _ in hits[p])):
        best_idx, best_tiles, compressed = max(hits[rel], key=lambda e: e[1])
        path = os.path.join("extract", "data", *rel.split("/"))
        n = narc.parse_file(path)
        nclr_indices = [sf.index for sf in n.subfiles if sf.magic == b"RLCN"]
        pal_idx = max((i for i in nclr_indices if i < best_idx), default=None)
        if pal_idx is None:
            pal_idx = min(nclr_indices, default=None)
        try:
            payload = load_decompressed(n, best_idx)
            ncgr = RawNcgr(payload)
            if pal_idx is not None:
                palette = bs.parse_nclr(load_decompressed(n, pal_idx))
            else:
                palette = [(i * 17, i * 17, i * 17) for i in range(16)]  # greyscale fallback
        except Exception as exc:  # noqa: BLE001
            print(f"[!] {rel}#{best_idx}: skipped ({exc})")
            continue
        w, h, rgb = render_tile_grid(ncgr, palette)
        tag = rel.replace("/", "_")
        out_path = os.path.join(out_dir, f"{tag}_sf{best_idx:04d}_{best_tiles}t.png")
        bs.write_png_rgb8(out_path, w, h, rgb)
        print(f"[*] {rel} sub-file {best_idx}: {best_tiles} tiles "
              f"(compressed={compressed}) -> {out_path}")
        written.append(out_path)
    return written


# ---------------------------------------------------------------------------
# Job 3: a/0/0/4 / a/0/5/2 rig-tail check (species 649..713)
# ---------------------------------------------------------------------------

def render_rig_tail(archive_path, out_dir, species_range=RIG_TAIL_SPECIES):
    os.makedirs(out_dir, exist_ok=True)
    n = narc.parse_file(archive_path)
    tag = archive_path.replace(os.sep, "_")
    ok, skipped = 0, 0
    for species in species_range:
        idx = species * rig.BLOCK_STRIDE
        if idx >= n.file_count:
            break
        try:
            rig.render_one(n, species, out_dir, filename=f"{tag}_tail{species:04d}_pose.png",
                            cells_sheet=True)
            # rig.render_one hardcodes the cells-sheet filename to
            # "{species:04d}_cells.png" (no override param) -- rename it so
            # a/0/0/4's and a/0/5/2's tail renders (same species range)
            # don't collide in a shared out_dir.
            default_cells = os.path.join(out_dir, f"{species:04d}_cells.png")
            tagged_cells = os.path.join(out_dir, f"{tag}_tail{species:04d}_cells.png")
            if os.path.exists(default_cells):
                os.replace(default_cells, tagged_cells)
            ok += 1
        except Exception as exc:  # noqa: BLE001
            skipped += 1
            print(f"[!] {archive_path} species(tail) {species}: skipped ({exc})")
    print(f"[*] {archive_path}: rig-tail {ok} rendered, {skipped} skipped, out={out_dir}")
    return ok, skipped


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--candidates", action="store_true",
                     help="characterize + render 6 samples each from a/0/7/8, a/0/8/3")
    ap.add_argument("--widen", action="store_true",
                     help="scan every NARC for an NCGR sub-file with >=100 tiles, render one "
                          "sample per hit archive")
    ap.add_argument("--min-tiles", type=int, default=100)
    ap.add_argument("--rig-tail", action="store_true",
                     help="render a/0/0/4 and a/0/5/2's species 649..713 tail blocks")
    ap.add_argument("--out", default=OUT_DIR)
    args = ap.parse_args(argv)

    if not (args.candidates or args.widen or args.rig_tail):
        ap.error("give at least one of --candidates / --widen / --rig-tail")

    if args.candidates:
        for path in CANDIDATES:
            characterize(path)
            render_candidate_samples(path, args.out)

    if args.widen:
        hits = find_widen_candidates(min_tiles=args.min_tiles)
        print(f"[*] {len(hits)} archives with an NCGR sub-file of >={args.min_tiles} tiles")
        render_widen_samples(hits, os.path.join(args.out, "widen"))

    if args.rig_tail:
        for path in RIG_ARCHIVES:
            render_rig_tail(path, RIG_TAIL_OUT_DIR)

    return 0


if __name__ == "__main__":
    sys.exit(main())
