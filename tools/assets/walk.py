#!/usr/bin/env python3
"""
walk.py -- decode + render the `a/0/3/1`-shaped human walk-cycle archive
family (one archive per named character), and locate its siblings.

Written from scratch for aletheia. Stdlib only, single file.

--------------------------------------------------------------------------
Mission and starting point
--------------------------------------------------------------------------
The previous lane pass (docs/ASSETS.md "Unexpected real find: a/0/3/1 is a
genuine human overworld-character archive") found `a/0/3/1` (51012 bytes,
24 sub-files) renders a small human figure and structurally decodes as a
24-cell `NCER` (32x32 OAMs, `mapping_type=2`) against a 384-tile `NCGR`,
plus two smaller companion cell/tile sets (12-cell/192-tile,
11-cell/64-tile) -- but left the `NANR` timeline undecoded (that pass's
budget ran out before the animation-sequence split was resolved) and did
not check for sibling archives. This module finishes both.

--------------------------------------------------------------------------
NANR sequence partition -- the real per-sequence frame-count field
(NOT `overworld.SharedAnim`'s "0 always" field, and NOT the mission's
literal field order)
--------------------------------------------------------------------------
`a/0/3/1`'s three `RNAN` sub-files (index 1, 13, 19 -- the "main"/24-cell,
12-cell, and 11-cell sets respectively) share the exact same 3-block
KNBA/LBAL/TXEU shape `overworld.SharedAnim` already parses for `a/0/0/7`,
but `overworld.SharedAnim`'s frame-data reader (fixed 4-byte
`{cellIdx,sentinel=0xCCCC}` record, looked up by the element array's own
`offset_to_frame_data` field) does NOT decode this archive's frame-data
region correctly past the first few records (`bad sentinel` errors) -- the
byte layout is the same, but which bytes the elements/sequences actually
point at works out differently once every element in the array is used
(not just `a/0/0/7`'s tiny 3/12-element case).

The KNBA sequence record is the same 16-byte, 5-field shape
`rig.Nanr`/`overworld.SharedAnim` already read (`elem_start(u32)@0,
num_frames(u16)@4, field_c(u16)@6, field_d(u32)@8, field_e(u32)@12`), and
in every sequence sampled `num_frames` (the field at offset 4) reads **0**,
just like `a/0/0/7` -- confirmed not usable, again.

**What resolves it this time**: `field_e` (offset 12, the LAST field, not
the first) is a byte offset into the element array (`field_e / 8`, since
each element record is 8 bytes) that gives every sequence's *first*
element index, and consecutive sequences' `field_e/8` values, taken in
array order, form a **complete, gapless partition of every element index
from 0 to `num_elements`** -- confirmed exactly on all three of this
archive's `RNAN` sub-files (sums of consecutive differences equal
`num_elements` precisely: 40, 35, and 32 -- see docs/ASSETS.md for the
worked arithmetic). This is a materially different (and, for this
archive, fully verified) reading from `overworld.SharedAnim`'s use of the
FIRST sequence field as `elem_start` -- that field is not 0 here either,
but does not partition the element array cleanly (it clusters into a
handful of small values shared by multiple sequences, the same
"overlapping, not a partition" problem the tenth lane pass already
documented for `a/0/0/7`). This module's `Nanr2` class implements the
`field_e`-based reading and is kept separate from `overworld.SharedAnim`
(which is left as-is, matching its own already-shipped/verified use on
`a/0/0/7`/`a/0/2/5`) rather than changing shared code on a single new
archive's evidence.

Per-element frame data is the same 4-byte `{cellIdx(u16), sentinel(u16)
=0xCCCC}` record `overworld.SharedAnim` already decodes, looked up by each
element's own `offset_to_frame_data` field into the shared frame-data pool
(`body[elem_end:]`) -- this part of the format is unchanged, only the
*sequence*-to-*element-range* mapping needed correcting.

--------------------------------------------------------------------------
Result: `a/0/3/1`'s main (24-cell) NANR is a real 4-direction walk/run
cycle, not an idle bob
--------------------------------------------------------------------------
The main set's `LBAL` names 13 sequences: `top, bottom, left, right, rota,
top_loop, bottom_loop, left_loop, right_loop, top_run, bottom_run,
left_run, right_run` -- real direction words (unlike `a/0/0/7`'s generic
`CellAnimeN`), decoded frame counts (via the `field_e` partition):
`top/bottom/left/right` = 1 frame each (a static facing-pose per
direction), `rota` = 4 frames (an in-place turn), `*_loop` (walk) and
`*_run` = 4 frames each per direction. This is the mission's expected
walk cycle, confirmed at the byte level: **4 directions x 4-frame walk
loop, 4 directions x 4-frame run cycle, plus 4 static standing poses and
one 4-frame turn animation**, 40 elements total, exactly accounted for.

The 12-cell (`RECN`@12/15, `RNAN`@13/16, `NCGR`@14/17, 192 tiles) and
11-cell (`RECN`@18/21, `RNAN`@19/22, `NCGR`@20/23, 64 tiles,
`mapping_type=0`) companion sets decode cleanly under the same `field_e`
partition rule (sequence-count sums match `num_elements` exactly: 35 and
32) but keep generic `CellAnimeN`/`CellAnime01` style names -- consistent
with a bike/run-kit and a small idle-emote kit respectively (unconfirmed
by direct visual read this pass; rendered anyway since the mission asked
for every animation set). A fourth, tiny single-cell/single-frame set
(`RECN`@9, `RNAN`@8, `NCGR`@11, 4 tiles) is also present, undocumented by
name (`CellAnime0`) -- most likely a ground shadow blob (small, no
direction split, appears once per character), rendered as `shadow`.

--------------------------------------------------------------------------
NCGR round trip
--------------------------------------------------------------------------
No new code needed: `overworld.NcgrFile`/`.encode()` (already byte-exact
for `a/0/0/7` and `a/0/2/5`) parses and re-serializes `a/0/3/1`'s `RGCN`
sub-files unchanged -- same 16-byte file header + 24-byte `RAHC`
sub-header shape. `--verify` below just calls
`overworld.verify_round_trip()` directly.

--------------------------------------------------------------------------
Sibling search and character identification
--------------------------------------------------------------------------
`--scan-siblings` opens every NARC under `extract/data/` (247 files) and
flags any archive containing an `RNAN` sub-file whose `LBAL` name table
includes all of `top`, `bottom`, `left`, `right` (the exact direction-word
signature that distinguishes this bundle from `a/0/0/7`'s generic
`CellAnimeN` names) -- this is the "same exact bundle shape" the mission
asks for, checked by NANR sequence names rather than raw NCER cell count
alone (cell count is a weaker signal: `a/0/0/7`'s shared NCER also has a
small cell count, for an unrelated idle-bob archive).

No name/index table maps a hit archive to a specific character (player,
rival, an NPC class, ...) -- this project has not decoded a scripting/
overlay area that would carry that mapping, and none of these archives
carry a text label of their own. This module's `--report` therefore
identifies characters only by **visual inspection of the rendered walk
strips** (silhouette/outfit), which is the strongest evidence available
without that table; see docs/ASSETS.md for the per-archive writeup.

--------------------------------------------------------------------------
Usage
--------------------------------------------------------------------------
    python tools/assets/walk.py --sets                      # decode summary, a/0/3/1
    python tools/assets/walk.py --all                        # render every set, a/0/3/1
    python tools/assets/walk.py --all --archive extract/data/a/0/3/2 --char-index 1
    python tools/assets/walk.py --verify                     # NCGR round trip
    python tools/assets/walk.py --scan-siblings               # find the full NPC set
    python tools/assets/walk.py --render-siblings              # scan + render --all for each hit
"""

import argparse
import json
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402
import overworld as ow  # noqa: E402  (NcgrFile, parse_ncer_shared, render_cell/sheet, verify_round_trip)
import battle_sprite as bs  # noqa: E402  (parse_nclr, write_png_rgb8)

ARCHIVE_PATH = os.path.join("extract", "data", "a", "0", "3", "1")
OUT_DIR = os.path.join("build", "assets", "walk")
SIBLINGS_JSON = os.path.join("build", "assets", "walk", "siblings.json")

DIRECTION_WORDS = ("top", "bottom", "left", "right")

ELEM_SENTINEL = 0xBEEF
FRAMEDATA_SENTINEL = 0xCCCC


def _hdr(data):
    magic, bom, ver, fsize, hsize, nblk = struct.unpack_from("<4sHHIHH", data, 0)
    return magic, bom, ver, fsize, hsize, nblk


# ---------------------------------------------------------------------------
# NANR (RNAN) -- field_e-partitioned sequence decode (see module docstring)
# ---------------------------------------------------------------------------

class AnimFrame:
    __slots__ = ("cell_index", "duration")

    def __init__(self, cell_index, duration):
        self.cell_index = cell_index
        self.duration = duration


class AnimSequence:
    __slots__ = ("name", "elem_start", "num_frames", "frames")

    def __init__(self, name, elem_start, num_frames):
        self.name = name
        self.elem_start = elem_start
        self.num_frames = num_frames
        self.frames = []  # filled in by Nanr2.__init__


class Nanr2:
    """Decodes one `a/0/3/1`-shaped RNAN (KNBA + LBAL [+ trailing TXEU,
    not decoded]) using the `field_e`-based sequence partition described
    in the module docstring, instead of `overworld.SharedAnim`'s
    first-field reading (which does not partition this archive's element
    array cleanly)."""

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

        # sequence names (LBAL), if present -- same shape as overworld.SharedAnim
        names = [f"seq{i}" for i in range(num_seq)]
        pos2 = pos + bsize
        if pos2 < len(data):
            bmagic2, bsize2 = struct.unpack_from("<4sI", data, pos2)
            if bmagic2 == b"LBAL":
                lbody = data[pos2 + 8:pos2 + bsize2]
                raw_names = [s.decode("ascii", "replace")
                             for s in lbody[num_seq * 4:].split(b"\x00") if s]
                if len(raw_names) == num_seq:
                    names = raw_names

        # sequence records: elem_start(u32), num_frames(u16, unused -- see
        # docstring, reads 0), field_c(u16), field_d(u32), field_e(u32)
        raw_seqs = []
        for i in range(num_seq):
            off = seq_ofs + i * 16
            _elem_start_field, _nframes_field, _fc, _fd, field_e = \
                struct.unpack_from("<IHHII", body, off)
            raw_seqs.append(field_e // 8)  # element index this sequence starts at

        # partition: sort sequences by their starting element index, each
        # sequence's frame count is the gap to the next one's start (or to
        # num_elem for the last) -- see docstring for why this is the real
        # per-sequence boundary.
        order = sorted(range(num_seq), key=lambda i: raw_seqs[i])
        starts_sorted = [raw_seqs[i] for i in order]
        self.partition_exact = True
        self.sequences = [None] * num_seq
        for rank, i in enumerate(order):
            start = starts_sorted[rank]
            end = starts_sorted[rank + 1] if rank + 1 < len(order) else num_elem
            nframes = max(0, end - start)
            self.sequences[i] = AnimSequence(names[i], start, nframes)
        # sanity: every element index covered exactly once, 0..num_elem
        covered = sum(s.num_frames for s in self.sequences)
        if covered != num_elem:
            self.partition_exact = False

        # element array: {offset_to_frame_data(i32), duration(u16), sentinel(u16)}
        elements = []
        for i in range(num_elem):
            off = elem_ofs + i * 8
            fofs, duration, sentinel = struct.unpack_from("<iHH", body, off)
            if sentinel != ELEM_SENTINEL:
                raise ValueError(f"element {i}: bad sentinel {sentinel:#x}")
            elements.append((fofs, duration))

        frame_data = body[elem_end:]

        def decode_frame(fofs):
            # NOT a fixed record shape: offsets 0..15 of this archive's pool
            # are 4-byte {cellIdx(u16), sentinel(u16)=0xCCCC} records (the
            # same shape overworld.SharedAnim uses for a/0/0/7), but once
            # every element in this archive is actually exercised, offsets
            # 16+ turn out to be a DENSER, plain 2-byte-per-frame pool (just
            # cellIdx, no per-record sentinel -- confirmed by direct dump:
            # a/0/3/1's main RNAN's frame-data bytes 16.. step by exactly 2,
            # not 4, and only every 4th slot happens to hold 0xCCCC there,
            # which is data, not a delimiter). Reading a plain cellIdx u16
            # at `fofs` (no sentinel check) reproduces the right value in
            # BOTH regions -- in the 4-byte region `fofs` always lands on
            # the cellIdx half of the pair, never the sentinel half -- so
            # this module does not special-case the two regions at all.
            if fofs + 2 > len(frame_data):
                raise ValueError(f"frame-data offset {fofs} runs past the "
                                  f"{len(frame_data)}-byte frame-data region")
            cell_idx, = struct.unpack_from("<H", frame_data, fofs)
            return AnimFrame(cell_idx, duration=0)

        for seq in self.sequences:
            frames = []
            for e in range(seq.elem_start, seq.elem_start + seq.num_frames):
                fofs, duration = elements[e]
                fr = decode_frame(fofs)
                fr.duration = duration
                frames.append(fr)
            seq.frames = frames


def parse_nanr2(data):
    return Nanr2(data)


# ---------------------------------------------------------------------------
# Archive-level structure: locate the (RECN, RNAN, NCGR, NCLR) groups.
# `a/0/3/1` has each group duplicated (2 byte-identical-ish copies, same
# pattern as `a/0/0/7`'s 3 copies at different mapping types -- here it is
# literally a second on-disk copy, not a remapped one, per direct diff
# below); this module always uses the FIRST copy of each.
# ---------------------------------------------------------------------------

class AnimSet:
    """One (RECN cell bank, RNAN timeline, RGCN tile sheet) group."""

    def __init__(self, tag, ncer_idx, nanr_idx, ncgr_idx):
        self.tag = tag
        self.ncer_idx = ncer_idx
        self.nanr_idx = nanr_idx
        self.ncgr_idx = ncgr_idx


def find_anim_sets(n):
    """Group each RECN with its RNAN and RGCN by pure greedy
    nearest-unclaimed sub-file index, processing every RECN occurrence (not
    just distinct shapes) in ascending index order. `a/0/3/1`'s tile-count
    arithmetic was tried first (cells * tiles-per-cell == NCGR.tile_count)
    and does NOT generalize: the archive's 11-cell `mapping_type=0` set
    uses dense, possibly-overlapping tile addressing where total tiles used
    is not a clean multiple of the cell count, so no tile-count filter
    reliably picks its NCGR. Pure "closest not-yet-claimed sub-file index"
    (no format-specific filter at all) instead reproduces the exact correct
    pairing for every one of the archive's 7 RECN occurrences (2 copies
    each of the 24-cell, 12-cell and 11-cell sets, plus 1 shadow set),
    verified by hand against the archive's raw sub-file layout -- see
    module docstring. Returns one AnimSet per distinct (cell_count,
    mapping_type) shape (first/primary copy only; duplicate copies are
    still claimed correctly during the greedy walk so they don't steal an
    earlier set's RGCN/RNAN, they are just not returned as a second set)."""
    recn = [sf.index for sf in n.subfiles if sf.magic == b"RECN"]
    rnan = [sf.index for sf in n.subfiles if sf.magic == b"RNAN"]
    rgcn = [sf.index for sf in n.subfiles if sf.magic == b"RGCN"]

    recn_info = {}
    for idx in recn:
        cells, mt = ow.parse_ncer_shared(n.read(idx))
        recn_info[idx] = (len(cells), mt)

    rnan_avail = set(rnan)
    rgcn_avail = set(rgcn)
    seen_shapes = set()
    sets = []
    for r_idx in recn:
        ncells, mt = recn_info[r_idx]
        n_idx = min(rnan_avail, key=lambda x: abs(x - r_idx)) if rnan_avail else None
        if n_idx is not None:
            rnan_avail.discard(n_idx)
        g_idx = min(rgcn_avail, key=lambda x: abs(x - r_idx)) if rgcn_avail else None
        if g_idx is not None:
            rgcn_avail.discard(g_idx)
        shape = (ncells, mt)
        if shape in seen_shapes or n_idx is None or g_idx is None:
            continue
        seen_shapes.add(shape)
        sets.append(AnimSet(f"cells{ncells}_mt{mt}", r_idx, n_idx, g_idx))
    return sets


# ---------------------------------------------------------------------------
# Rendering
# ---------------------------------------------------------------------------

def load_palette(n):
    """First RLCN sub-file in the archive (all groups in a/0/3/1 share one
    48-color-class palette layout across copies; sub-palette 0 is used,
    matching the locate pass's finding that these are plain single-
    sub-palette 16-color NCLRs, unlike a/0/0/7's multi-bank shared one)."""
    for sf in n.subfiles:
        if sf.magic == b"RLCN":
            return bs.parse_nclr(n.read(sf.index))
    raise ValueError("archive has no RLCN (NCLR) sub-file")


def render_sequence_strip(ncgr, cells, frames, out_path, palette, pal_index=0):
    frame_cells = [cells[f.cell_index] for f in frames if f.cell_index < len(cells)]
    if not frame_cells:
        frame_cells = cells[:1]
    w, h, flat = ow.render_sprite_sheet(ncgr, frame_cells)
    rgb = ow.indices_to_rgb(flat, palette, pal_index=pal_index)
    bs.write_png_rgb8(out_path, w, h, rgb)
    return w, h


def render_character(archive_path, out_dir, char_index):
    """Render every animation set's every named sequence for one character
    archive to `{out_dir}/{char_index:04d}_{setname}_{seqname}.png`."""
    n = narc.parse_file(archive_path)
    palette = load_palette(n)
    sets = find_anim_sets(n)
    os.makedirs(out_dir, exist_ok=True)
    written = []
    summary = []
    for s in sets:
        cells, mt = ow.parse_ncer_shared(n.read(s.ncer_idx))
        ncgr = ow.parse_ncgr(n.read(s.ncgr_idx))
        if s.nanr_idx is None:
            continue
        anim = parse_nanr2(n.read(s.nanr_idx))
        set_tag = f"c{len(cells)}"
        for seq in anim.sequences:
            safe_name = seq.name.replace("/", "_")
            out_path = os.path.join(out_dir, f"{char_index:04d}_{set_tag}_{safe_name}.png")
            w, h = render_sequence_strip(ncgr, cells, seq.frames, out_path, palette)
            written.append(out_path)
            summary.append((set_tag, seq.name, seq.num_frames, w, h))
    return written, summary, sets


# ---------------------------------------------------------------------------
# Multi-entity block archives (`a/0/3/2` shape): many small characters
# packed into ONE archive sharing ONE palette, instead of `a/0/3/1`'s
# one-archive-per-character-with-duplicated-copies shape.
# ---------------------------------------------------------------------------
#
# `a/0/3/2` (97 sub-files) lays out as: 1 shared `RLCN` (256 colors = 16
# sub-palettes of 16), then a run of 16 `RGCN`, then 16 alternating
# `(RECN, RNAN)` pairs, then that whole (16 `RGCN`, 16 pairs) shape
# REPEATS once more -- 32 entities total in 2 blocks of 16. There is no
# per-entity duplication (unlike `a/0/3/1`'s 2 on-disk copies of every
# group) and no ARM9 sub-palette-selector table is needed: unlike
# `a/0/0/7` (every OAM's own `attr2` palette bits are 0, forcing an
# external ARM9 table lookup), every OAM in every one of this archive's
# cells carries its entity's real sub-palette index directly in its own
# `attr2` `pal` nibble -- confirmed constant across every cell within one
# entity (e.g. entity 0's OAMs are all `pal=2`, entity 1's all `pal=3`,
# ...) and NOT equal to the entity's position in its 16-entity block (a
# same-as-local-index guess was tried first and produces solid-black
# renders for several entities -- the real `pal` values are a scrambled
# permutation of a small set, not 0..15 in order). This module reads
# `cells[0].oams[0].pal` per entity instead of computing an index.
# 8 distinct `pal` values (0-7) were seen across block 1's 16 entities,
# each used by exactly 2 entities -- consistent with a 16-sub-palette
# bank where only the low half is populated, or two entities intentionally
# sharing a recolor. Block 1 entities (0-15) render as 4-cell/64-tile
# figures with only 5 sequences (`top/bottom/left/right/rota`, no loop or
# run); block 2 entities (16-31) render as 1-cell/16-tile figures with up
# to 9 sequences (adds `*_loop`). Neither block has the `*_run` sequences
# `a/0/3/1`'s player-class archive has -- see docs/ASSETS.md for the
# identification writeup.


def find_multi_entity_blocks(n):
    """Split an `a/0/3/2`-shaped archive into blocks of (rgcn_indices,
    [(recn_idx, rnan_idx), ...]) by walking sub-files in index order and
    collecting maximal runs: a run of consecutive `RGCN` starts a block,
    followed by a run of alternating `RECN`/`RNAN` pairs of the same
    length. Generalizes beyond exactly 2 blocks of 16 if a differently-
    sized archive of this same shape is found."""
    subs = n.subfiles
    i = 0
    blocks = []
    while i < len(subs):
        if subs[i].magic != b"RGCN":
            i += 1
            continue
        rgcn_run = []
        while i < len(subs) and subs[i].magic == b"RGCN":
            rgcn_run.append(subs[i].index)
            i += 1
        pairs = []
        while (i + 1 < len(subs) and subs[i].magic == b"RECN"
               and subs[i + 1].magic == b"RNAN" and len(pairs) < len(rgcn_run)):
            pairs.append((subs[i].index, subs[i + 1].index))
            i += 2
        if pairs:
            blocks.append((rgcn_run, pairs))
    return blocks


def render_multi_entity_archive(archive_path, out_dir, char_index_start=0):
    """Render every entity of an `a/0/3/2`-shaped archive: one strip per
    named sequence, to `{out_dir}/{char_index:04d}_{seqname}.png`, where
    `char_index` continues from `char_index_start`. Returns
    (written_paths, num_entities)."""
    n = narc.parse_file(archive_path)
    palette = load_palette(n)
    blocks = find_multi_entity_blocks(n)
    os.makedirs(out_dir, exist_ok=True)
    written = []
    char_index = char_index_start
    for rgcn_run, pairs in blocks:
        for g_idx, (r_idx, a_idx) in zip(rgcn_run, pairs):
            cells, mt = ow.parse_ncer_shared(n.read(r_idx))
            ncgr = ow.parse_ncgr(n.read(g_idx))
            anim = parse_nanr2(n.read(a_idx))
            # real per-entity sub-palette: each cell's own OAM attr2 `pal`
            # nibble (see module docstring -- NOT the entity's block index).
            subpal = cells[0].oams[0].pal if cells and cells[0].oams else 0
            for seq in anim.sequences:
                safe_name = seq.name.replace("/", "_")
                out_path = os.path.join(out_dir, f"{char_index:04d}_{safe_name}.png")
                render_sequence_strip(ncgr, cells, seq.frames, out_path, palette,
                                       pal_index=subpal)
                written.append(out_path)
            char_index += 1
    return written, char_index - char_index_start


# ---------------------------------------------------------------------------
# Sibling search
# ---------------------------------------------------------------------------

def _iter_all_narcs(root=os.path.join("extract", "data")):
    for dirpath, _dirs, files in os.walk(root):
        for fn in files:
            yield os.path.join(dirpath, fn)


def scan_siblings(root=os.path.join("extract", "data")):
    """Every archive with at least one RNAN whose LBAL names include all
    4 direction words -- the walk-cycle bundle signature (see module
    docstring). Returns [(rel_path, matching_rnan_indices, all_names)]."""
    hits = []
    for path in sorted(_iter_all_narcs(root)):
        try:
            n = narc.parse_file(path)
        except Exception:  # noqa: BLE001 -- not every extracted file is a NARC
            continue
        matches = []
        all_names = set()
        for sf in n.subfiles:
            if sf.magic != b"RNAN":
                continue
            try:
                anim = parse_nanr2(n.read(sf.index))
            except Exception:  # noqa: BLE001
                continue
            names = {a.name for a in anim.sequences}
            all_names |= names
            if all(w in names for w in DIRECTION_WORDS):
                matches.append(sf.index)
        if matches:
            rel = os.path.relpath(path, root).replace(os.sep, "/")
            hits.append((rel, matches, sorted(all_names)))
    return hits


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--archive", default=ARCHIVE_PATH)
    ap.add_argument("--out", default=OUT_DIR)
    ap.add_argument("--char-index", type=int, default=0,
                     help="character index used in output filenames (default 0)")
    ap.add_argument("--sets", action="store_true",
                     help="print the decoded anim-set/sequence summary for --archive")
    ap.add_argument("--all", action="store_true",
                     help="render every animation set's every sequence for --archive")
    ap.add_argument("--verify", action="store_true",
                     help="NCGR round trip over --archive (delegates to overworld.py)")
    ap.add_argument("--scan-siblings", action="store_true",
                     help="scan every NARC under extract/data/ for the walk-cycle bundle "
                          "signature (RNAN with top/bottom/left/right sequence names)")
    ap.add_argument("--render-siblings", action="store_true",
                     help="scan-siblings, then --all-render every hit to --out")
    ap.add_argument("--multi", action="store_true",
                     help="render --archive as a multi-entity block archive (a/0/3/2 "
                          "shape) instead of a single-character archive (a/0/3/1 shape)")
    args = ap.parse_args(argv)

    if args.verify:
        ok, fail, skipped = ow.verify_round_trip(args.archive)
        return 0 if fail == 0 else 1

    if args.sets:
        n = narc.parse_file(args.archive)
        sets = find_anim_sets(n)
        print(f"[*] {args.archive}: {len(sets)} animation set(s)")
        for s in sets:
            cells, mt = ow.parse_ncer_shared(n.read(s.ncer_idx))
            ncgr = ow.parse_ncgr(n.read(s.ncgr_idx))
            print(f"  set {s.tag}: RECN#{s.ncer_idx} ({len(cells)} cells, "
                  f"mapping_type={mt}) + RNAN#{s.nanr_idx} + RGCN#{s.ncgr_idx} "
                  f"({ncgr.tile_count} tiles)")
            if s.nanr_idx is not None:
                anim = parse_nanr2(n.read(s.nanr_idx))
                print(f"    partition exact: {anim.partition_exact} "
                      f"({anim.num_elements} elements)")
                for seq in anim.sequences:
                    cell_list = ",".join(str(f.cell_index) for f in seq.frames)
                    print(f"    seq '{seq.name}': {seq.num_frames} frame(s), cells=[{cell_list}]")
        return 0

    if args.multi:
        written, n_entities = render_multi_entity_archive(args.archive, args.out, args.char_index)
        print(f"[*] {args.archive}: {n_entities} entities, {len(written)} strip(s) written")
        return 0

    if args.all:
        written, summary, sets = render_character(args.archive, args.out, args.char_index)
        print(f"[*] {args.archive}: {len(sets)} anim set(s), {len(written)} strip(s) written")
        for set_tag, name, nframes, w, h in summary:
            print(f"    {set_tag}/{name}: {nframes} frame(s) -> {w}x{h}")
        return 0

    if args.scan_siblings or args.render_siblings:
        hits = scan_siblings()
        print(f"[*] {len(hits)} archive(s) with the walk-cycle bundle signature "
              f"(RNAN with top/bottom/left/right sequences):")
        for rel, matches, names in hits:
            print(f"    a/{rel}: RNAN#{matches} -- sequence names: {names}")
        os.makedirs(os.path.dirname(SIBLINGS_JSON), exist_ok=True)
        with open(SIBLINGS_JSON, "w") as f:
            json.dump([{"path": f"a/{rel}", "rnan_indices": matches, "names": names}
                       for rel, matches, names in hits], f, indent=2)
        print(f"[*] wrote {SIBLINGS_JSON}")

        if args.render_siblings:
            char_index = 0
            for rel, _matches, _names in hits:
                path = os.path.join("extract", "data", *rel.split("/"))
                n = narc.parse_file(path)
                n_recn = sum(1 for sf in n.subfiles if sf.magic == b"RECN")
                try:
                    if n_recn > 10:
                        # a/0/3/2 shape: many small characters packed into
                        # one archive (see render_multi_entity_archive).
                        written, n_entities = render_multi_entity_archive(
                            path, args.out, char_index)
                        print(f"[*] {rel}: multi-entity archive, {n_entities} "
                              f"character(s) starting at index {char_index:04d}, "
                              f"{len(written)} strips written")
                        char_index += n_entities
                    else:
                        written, summary, sets = render_character(path, args.out, char_index)
                        print(f"[*] char {char_index:04d} ({rel}): {len(written)} strips written")
                        char_index += 1
                except Exception as exc:  # noqa: BLE001 -- best-effort batch
                    print(f"[!] ({rel}): skipped ({exc})")
        return 0

    ap.error("give --sets, --all, --verify, --scan-siblings, or --render-siblings")


if __name__ == "__main__":
    sys.exit(main())
