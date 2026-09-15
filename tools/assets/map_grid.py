#!/usr/bin/env python3
"""
map_grid.py -- decode and visualise `a/0/0/8` map/building/dungeon
sub-files' per-tile grid (the wrapper's "permission/height data" region,
directly following the BMD0 model), and the small size-table header that
wraps each sub-file.

Written from scratch for the aletheia asset lane. Stdlib only.

--------------------------------------------------------------------------
The record model (this module's attested shape -- retires the byte-lane
model the first three passes over this archive built from data alone)
--------------------------------------------------------------------------
This is solved from the game's own code, not guessed from the bytes: the
read path is `func_02169848` (ov010) -> the wrapper-tag vtable at
`0x021D3DDC` -> `func_021D14C4` (ov021, the record decoder) ->
`func_0218DBAC` -> `func_021AB504` (ov021, the terrain-class switch). See
`docs/notes/func_021D14C4_tile_record_reader.c.txt` for the disassembly
this module follows and `docs/ASSETS.md`'s "Per-tile grid record SOLVED"
section for the full writeup. Each 8-byte record is three fields, not
eight independent byte lanes:

    +0x00  u16   surface    bits 0..1: surface type (0 = flat, 1 = none,
                             2 = slope, resolved against the aux array
                             below). bits 2..15: index into a ROM-resident
                             table of s16 (x,y,z) normal triples -- the
                             table lives in ov021, not in this archive, so
                             this module decodes the INDEX, never the
                             vector itself.
    +0x02  u16   heightIndex  type 0: index into a ROM-resident u32 height
                             table (again not present in this archive).
                             type 2: index of the first record of the
                             auxiliary array described below.
    +0x04  u32   attribute  bit 31: which end of the type-2 aux search
                             walks from (stripped before the rest of the
                             word is used -- not part of the attribute).
                             bits 0..15: terrain id. bits 16..31: flags
                             (bit 0 walkable ground, bit 1 alternate
                             encounter set, bit 2 terrain-class gate).

The grid itself opens with a `u16, u16` (width, height) header; the first
record sits at `gridPtr + 4` (`gridPtr` is whatever wrapper offset the tag
points at); the stride is 8 and the index is `row * width + col`, exactly
as `func_021D14C4` computes it.

Immediately after the `width*height` records, before the wrapper's next
declared offset, sits the auxiliary slope/normal array the earlier passes
reported as "unexplained tail bytes": `func_021D14C4`'s type-2 search reads
it as 8-byte records, each four `u16`s read as two (normal index, height
index) pairs at `+0/+4` and `+2/+6`. Like the main record's own normal and
height fields, the actual vectors/heights these indices select are
ROM-resident tables this archive does not contain; what IS decoded here is
the pair structure and the indices themselves, which is as far as the
reader note attests. The search direction (attribute bit 31) picks which
end of this array the walk starts from.

--------------------------------------------------------------------------
Wrapper layout (recap; the size-table fields below double as the grid/aux
array boundaries once the record model above is applied -- this is also
new this pass: the earlier "grid end / tail start" offsets are really
"grid *and aux array* end", which is why `pl_00_00`'s extra 32 bytes
before that offset were unexplained until now)
--------------------------------------------------------------------------
Each `a/0/0/8` sub-file is:

    header (tag-dependent) || BMD0 model || grid(s) (+ trailing aux array
    each) || tail

The header starts with a 2-byte ASCII tag ("WB", "GC", "NG", "RD"), a u16
version/count, then a u32 equal to the header's own byte length (also the
BMD0 payload's start offset). The remaining header u32s are a small size
table of absolute byte offsets, read per-tag against the wrapper-tag
vtable's own grid-sampling shape (`WB`/default samples one grid slot,
`GC` samples two, `NG` samples none, `RD` samples one plus a dense
secondary block):

  WB (20 bytes, 572/649 files): one grid.
    u32@4  = header length (== BMD0 offset)
    u32@8  = BMD0 end / grid start
    u32@12 = grid end (records + aux array) / tail start
    u32@16 = total sub-file length

  GC (24 bytes, 47/649 files): two grids back to back, the vtable's
    `fn[+0x08]` sampling slot 0 at `u32@8` and slot 1 at `u32@12`.
    u32@4  = header length
    u32@8  = grid-1 start
    u32@12 = grid-1 end (+ aux) / grid-2 start
    u32@16 = grid-2 end (+ aux) / tail start
    u32@20 = total length

  NG (16 bytes, 22/649 files): no per-tile grid; the vtable's NG entry is
    a stub pair plus a separate initialiser, confirmed from the code to
    carry no grid-sampling call at all.
    u32@4  = header length
    u32@8  = BMD0 end
    u32@12 = total length

  RD (20 bytes, 8/649 files, all "wf_*"/"bc_*" water-surface models): one
    ordinary grid, then a second, denser block with no `u16,u16` header of
    its own: a 4-byte value (not a plausible dimension pair) followed by
    exactly `64*64*4 = 16384` bytes, the right size for a 64x64 grid of
    4-byte records. The vtable samples this block through the same
    decoder slot as any other grid, but its 4-byte record layout is not
    attested by the reader note (the note only covers the 8-byte main and
    aux records) and is left un-decoded here, same as before -- only its
    location and size are structural facts.
    u32@4  = header length
    u32@8  = grid-1 start (== BMD0 end)
    u32@12 = grid-1 end (+ aux) / dense-block start
    u32@16 = total length (dense-block end)

A tag this module does not recognise is treated like `GC` (two grids):
that is the wrapper-tag vtable's own `0xFFFFFFFF` catch-all entry, which
reuses `GC`'s three function pointers verbatim.

--------------------------------------------------------------------------
The terrain-class switch
--------------------------------------------------------------------------
`func_021AB504` (ported verbatim as `classify_terrain()` below) turns the
attribute word's id/flags pair into one of 9 small classes. Its only
caller drops a tile when the answer is 8 ("no terrain effect"):

    if id == 0x20: return 7
    if not (flags & 4): return 8
    switch id: 4->0  5->1  0x21->2  8->3  10->4  0x3d->5  0x3f,0x43->6
    default: return 8

--------------------------------------------------------------------------
CLI
--------------------------------------------------------------------------
    --dump     per-target text matrices: terrain id, terrain class,
               walkable flag, height index (plus the aux array, when a
               grid has one).
    --png      per-target false-colour PNGs for the same four lanes under
               build/assets/maps/ (gitignored), each with a `_legend.txt`
               naming the values/classes shown.
    --stats    archive-wide histograms (terrain id, terrain class, flag
               combinations) over every ordinary 8-byte-record grid in all
               649 sub-files, plus the two cross-checks documented in
               docs/ASSETS.md (id-1-vs-walkable-flag disagreement count,
               class-7-count == id-0x20-count).
    --verify   repack every sub-file from parsed fields (header, BMD0
               span copied verbatim, every grid's records and aux array,
               the RD dense block, and the trailing tail bytes) and
               compare byte-for-byte against the original, over all 649
               sub-files.
"""

import argparse
import os
import struct
import sys
from collections import Counter

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc as narcmod  # noqa: E402
import nsbmd  # noqa: E402

A008_PATH = os.path.join("extract", "data", "a", "0", "0", "8")

# (expected model name, a/0/0/8 index) -- the mission's named samples plus
# one extra outdoor chunk (map24_23) kept because it has far more terrain
# variety than map14_13.
TARGETS = [
    ("pl_00_00", 120),
    ("map14_13", 44),
    ("map24_23", 0),
    ("m_dun0101_00_00", 279),
]

SURFACE_FLAT = 0
SURFACE_NONE = 1
SURFACE_SLOPE = 2

# func_021AB504, ported verbatim.
_CLASS_TABLE = {4: 0, 5: 1, 0x21: 2, 8: 3, 10: 4, 0x3d: 5, 0x3f: 6, 0x43: 6}


def classify_terrain(terrain_id, flags):
    """Port of func_021AB504 (ov021, pkt_021AB0F0, status EXACT).
    Returns the tile's terrain class, 0-7, or 8 for "no terrain effect"."""
    if terrain_id == 0x20:
        return 7
    if not (flags & 4):
        return 8
    return _CLASS_TABLE.get(terrain_id, 8)


class WrapperError(Exception):
    pass


def _unpack_grid(raw, start, end):
    """Parse one ordinary 8-byte-record grid spanning [start, end): a
    u16,u16 dimension header, width*height 8-byte records, then whatever
    bytes remain up to `end` as the auxiliary slope/normal array."""
    if end - start < 4:
        raise WrapperError(f"grid span [{start}:{end}] too short for a "
                            f"dimension header")
    gw, gh = struct.unpack_from("<HH", raw, start)
    if not (1 <= gw <= 128 and 1 <= gh <= 128):
        raise WrapperError(f"implausible grid dims {gw}x{gh} at {start}")
    data_off = start + 4
    main_end = data_off + gw * gh * 8
    if main_end > end:
        raise WrapperError(f"{gw}x{gh} grid's records run past its span "
                            f"({main_end} > {end})")
    aux_len = end - main_end
    if aux_len % 8 != 0:
        raise WrapperError(f"aux array length {aux_len} at {main_end} is "
                            f"not a multiple of 8")
    return {
        "width": gw, "height": gh,
        "header_offset": start,
        "data_offset": data_off, "data_end": main_end,
        "aux_offset": main_end, "aux_end": end, "aux_count": aux_len // 8,
    }


def parse_wrapper(raw):
    """Returns a dict describing one a/0/0/8 sub-file's wrapper: tag,
    header fields, BMD0 span, every ordinary grid (each with its aux
    array span), the RD-style dense block if present, and the tail span.
    Grid placement follows the per-tag size-table layout the wrapper-tag
    vtable attests (see module docstring), not generic probing.
    """
    if len(raw) < 8:
        raise WrapperError("sub-file too short")
    tag = raw[0:2].decode("ascii", "replace")
    tag_ver = struct.unpack_from("<H", raw, 2)[0]
    header_len = struct.unpack_from("<I", raw, 4)[0]
    bmd0_off = raw.find(b"BMD0")
    if bmd0_off < 0:
        raise WrapperError("no BMD0 magic found")
    if header_len != bmd0_off:
        header_len = bmd0_off
    n_size_fields = (header_len - 8) // 4
    size_table = list(struct.unpack_from("<%dI" % n_size_fields, raw, 8))

    magic, bom, version, bmd0_file_size, c_header_size, nblk = \
        struct.unpack_from("<4sHHIHH", raw, bmd0_off)
    bmd0_end = bmd0_off + bmd0_file_size

    grids = []
    dense_grid = None
    total_len = len(raw)

    # Grid placement follows the wrapper-tag vtable's own sampling shape:
    # WB samples one grid slot, GC samples two, NG samples none, RD
    # samples one plus a dense secondary block. An unrecognised tag is
    # not expected in this archive (the 4 tags above already account for
    # all 649 sub-files) but is treated like GC when its size table has
    # GC's 4 fields, and like WB otherwise -- matching the vtable's own
    # 0xFFFFFFFF catch-all, which reuses GC's function pointers.
    if tag == "NG":
        if len(size_table) != 2:
            raise WrapperError(f"NG sub-file with {len(size_table)} size "
                                f"fields, expected 2")
        bmd_end2, total = size_table
        tail_offset, tail_len = bmd_end2, total - bmd_end2
    elif tag == "GC" or (tag not in ("WB", "RD") and len(size_table) == 4):
        if len(size_table) != 4:
            raise WrapperError(f"{tag} sub-file with {len(size_table)} "
                                f"size fields, expected 4")
        g1_start, g1_end, g2_end, total = size_table
        grids.append(_unpack_grid(raw, g1_start, g1_end))
        grids.append(_unpack_grid(raw, g1_end, g2_end))
        tail_offset, tail_len = g2_end, total - g2_end
    elif tag == "RD":
        if len(size_table) != 3:
            raise WrapperError(f"RD sub-file with {len(size_table)} size "
                                f"fields, expected 3")
        g1_start, g1_end, total = size_table
        grids.append(_unpack_grid(raw, g1_start, g1_end))
        dense_len = total - g1_end
        if dense_len == 4 + 64 * 64 * 4:
            header_value = struct.unpack_from("<I", raw, g1_end)[0]
            dense_grid = {
                "width": 64, "height": 64, "record_size": 4,
                "header_offset": g1_end, "header_value": header_value,
                "data_offset": g1_end + 4, "data_end": total,
            }
            tail_offset, tail_len = total, 0
        else:
            tail_offset, tail_len = g1_end, dense_len
    else:  # WB, or an unrecognised tag with a WB-shaped (3-field) header
        if len(size_table) != 3:
            raise WrapperError(f"{tag} sub-file with {len(size_table)} "
                                f"size fields, expected 3")
        g1_start, g1_end, total = size_table
        grids.append(_unpack_grid(raw, g1_start, g1_end))
        tail_offset, tail_len = g1_end, total - g1_end

    return {
        "tag": tag,
        "tag_ver": tag_ver,
        "header_len": header_len,
        "size_table": size_table,
        "bmd0_offset": bmd0_off,
        "bmd0_file_size": bmd0_file_size,
        "bmd0_end": bmd0_end,
        "grids": grids,
        "dense_grid": dense_grid,
        "tail_offset": tail_offset,
        "tail_len": tail_len,
        "total_len": total_len,
    }


def decode_record(surface, height_index, attr_raw):
    surface_type = surface & 3
    normal_index = surface >> 2
    search_dir = (attr_raw >> 31) & 1
    attribute = attr_raw & 0x7fffffff
    terrain_id = attribute & 0xFFFF
    flags = (attribute >> 16) & 0xFFFF
    return {
        "surface_raw": surface, "height_index": height_index,
        "attr_raw": attr_raw,
        "surface_type": surface_type, "normal_index": normal_index,
        "search_dir": search_dir, "attribute": attribute,
        "terrain_id": terrain_id, "flags": flags,
        "walkable": flags & 1,
        "alt_encounter": (flags >> 1) & 1,
        "class_gate": (flags >> 2) & 1,
        "terrain_class": classify_terrain(terrain_id, flags),
    }


def read_records(raw, grid):
    """Returns a flat list of `width*height` decoded record dicts,
    row-major (record i is column i%width, row i//width)."""
    w, h = grid["width"], grid["height"]
    off = grid["data_offset"]
    out = []
    for i in range(w * h):
        surface, height_index, attr_raw = struct.unpack_from(
            "<HHI", raw, off + i * 8)
        out.append(decode_record(surface, height_index, attr_raw))
    return out


def pack_record(rec):
    return struct.pack("<HHI", rec["surface_raw"], rec["height_index"],
                        rec["attr_raw"])


def read_aux_records(raw, grid):
    """Returns the grid's trailing auxiliary slope/normal array: each
    8-byte record as two (normal index, height index) pairs, per the
    type-2 search func_021D14C4 walks. The actual normal vectors and
    height values these indices select live in ROM-resident tables this
    archive does not contain; only the indices are decoded."""
    off = grid["aux_offset"]
    out = []
    for i in range(grid["aux_count"]):
        a0, a1, a2, a3 = struct.unpack_from("<4H", raw, off + i * 8)
        out.append({
            "norm_a": a0, "height_a": a2,
            "norm_b": a1, "height_b": a3,
            "raw": (a0, a1, a2, a3),
        })
    return out


def pack_aux_record(aux):
    return struct.pack("<4H", *aux["raw"])


def read_dense_records(raw, grid):
    """RD's dense secondary block: located and sized exactly, but its
    4-byte record layout is not attested by the reader note, so this
    returns the 64*64 raw u32 words undecoded."""
    off = grid["data_offset"]
    n = grid["width"] * grid["height"]
    return list(struct.unpack_from(f"<{n}I", raw, off))


def pack_dense_records(values):
    return struct.pack(f"<{len(values)}I", *values)


def model_name(a008, index):
    raw = a008.read(index)
    pos = raw.find(b"BMD0")
    try:
        c = nsbmd.parse_container(raw[pos:])
        mdl0 = nsbmd.find_mdl0(c)
        if mdl0 is not None and mdl0.model_dict.names:
            return mdl0.model_dict.names[0]
    except nsbmd.Nsbmd0Error:
        pass
    return None


# ---------------------------------------------------------------------------
# Round trip
# ---------------------------------------------------------------------------

def repack_subfile(raw, info):
    tag_bytes = info["tag"].encode("ascii")
    header = bytearray()
    header += tag_bytes
    header += struct.pack("<H", info["tag_ver"])
    header += struct.pack("<I", info["header_len"])
    header += struct.pack("<%dI" % len(info["size_table"]), *info["size_table"])
    if len(header) != info["header_len"]:
        raise WrapperError("reconstructed header length mismatch")

    out = bytearray(header)
    # BMD0 payload: out of this mission's scope, copied verbatim.
    out += raw[info["bmd0_offset"]:info["bmd0_end"]]

    for grid in info["grids"]:
        out += struct.pack("<HH", grid["width"], grid["height"])
        for rec in read_records(raw, grid):
            out += pack_record(rec)
        for aux in read_aux_records(raw, grid):
            out += pack_aux_record(aux)

    if info["dense_grid"] is not None:
        g = info["dense_grid"]
        out += struct.pack("<I", g["header_value"])
        out += pack_dense_records(read_dense_records(raw, g))

    out += raw[info["tail_offset"]:info["tail_offset"] + info["tail_len"]]
    return bytes(out)


def cmd_verify(a008):
    ok = fail = 0
    for i in range(a008.file_count):
        raw = a008.read(i)
        try:
            info = parse_wrapper(raw)
            repacked = repack_subfile(raw, info)
        except WrapperError as exc:
            print(f"  #{i}: parse error: {exc}", file=sys.stderr)
            fail += 1
            continue
        if repacked == raw:
            ok += 1
        else:
            fail += 1
            print(f"  #{i}: round-trip MISMATCH (orig {len(raw)} bytes, "
                  f"repacked {len(repacked)} bytes)", file=sys.stderr)
    print(f"a/0/0/8: {ok}/{a008.file_count} sub-files round-trip "
          f"byte-identical ({fail} failed)")
    return 0 if fail == 0 else 1


# ---------------------------------------------------------------------------
# Text dump
# ---------------------------------------------------------------------------

def _write_matrix(records, width, height, field, path, fmt="{:3d}"):
    parent = os.path.dirname(os.path.abspath(path))
    if parent:
        os.makedirs(parent, exist_ok=True)
    with open(path, "w") as fh:
        for row in range(height):
            vals = (records[row * width + col][field] for col in range(width))
            fh.write(" ".join(fmt.format(v) for v in vals) + "\n")


DUMP_FIELDS = [
    ("terrain_id", "terrain_id", "{:3d}"),
    ("terrain_class", "class", "{:2d}"),
    ("walkable", "walkable", "{:1d}"),
    ("height_index", "height_index", "{:5d}"),
]


def dump_wrapper_info(info, name, path):
    parent = os.path.dirname(os.path.abspath(path))
    if parent:
        os.makedirs(parent, exist_ok=True)
    with open(path, "w") as fh:
        fh.write(f"model: {name}\n")
        fh.write(f"tag: {info['tag']} (tag_ver=0x{info['tag_ver']:04x})\n")
        fh.write(f"header_len: {info['header_len']}\n")
        fh.write(f"size_table: {info['size_table']}\n")
        fh.write(f"bmd0_offset: {info['bmd0_offset']}\n")
        fh.write(f"bmd0_end: {info['bmd0_end']}\n")
        fh.write(f"total_len: {info['total_len']}\n")
        fh.write(f"n_grids: {len(info['grids'])}\n")
        for i, g in enumerate(info["grids"]):
            fh.write(f"  grid[{i}]: {g['width']}x{g['height']}, "
                     f"records=[{g['data_offset']}:{g['data_end']}], "
                     f"aux=[{g['aux_offset']}:{g['aux_end']}] "
                     f"({g['aux_count']} aux records)\n")
        if info["dense_grid"] is not None:
            g = info["dense_grid"]
            fh.write(f"  dense_grid (RD-style, not semantically decoded): "
                     f"{g['width']}x{g['height']}, header_value="
                     f"{g['header_value']}, data=[{g['data_offset']}:"
                     f"{g['data_end']}]\n")
        fh.write(f"tail: [{info['tail_offset']}:"
                  f"{info['tail_offset'] + info['tail_len']}] "
                  f"({info['tail_len']} bytes)\n")


def dump_aux_text(aux_records, path):
    parent = os.path.dirname(os.path.abspath(path))
    if parent:
        os.makedirs(parent, exist_ok=True)
    with open(path, "w") as fh:
        for i, a in enumerate(aux_records):
            fh.write(f"{i:4d}: norm_a={a['norm_a']:5d} height_a="
                     f"{a['height_a']:5d}  norm_b={a['norm_b']:5d} "
                     f"height_b={a['height_b']:5d}\n")


# ---------------------------------------------------------------------------
# False-colour PNG per lane, with a legend
# ---------------------------------------------------------------------------

_BASE_PALETTE = [
    (30, 30, 30), (220, 40, 40), (40, 160, 60), (50, 100, 220),
    (230, 190, 30), (200, 60, 200), (40, 200, 200), (240, 130, 30),
    (140, 90, 40), (230, 230, 230), (120, 40, 160), (40, 120, 40),
]


def value_color(rank, total):
    if rank < len(_BASE_PALETTE):
        return _BASE_PALETTE[rank]
    h = (rank * 2654435761) & 0xFFFFFF
    return (h & 0xFF, (h >> 8) & 0xFF, (h >> 16) & 0xFF)


def write_field_png(records, width, height, field, path, cell_px=8):
    vals = [r[field] for r in records]
    uniq = sorted(set(vals))
    color_of = {v: value_color(i, len(uniq)) for i, v in enumerate(uniq)}
    px_w, px_h = width * cell_px, height * cell_px
    rgba = bytearray(px_w * px_h * 4)
    for row in range(height):
        for col in range(width):
            v = records[row * width + col][field]
            r, g, b = color_of[v]
            for dy in range(cell_px):
                base_row = (row * cell_px + dy) * px_w
                for dx in range(cell_px):
                    o = (base_row + col * cell_px + dx) * 4
                    rgba[o] = r
                    rgba[o + 1] = g
                    rgba[o + 2] = b
                    rgba[o + 3] = 255
    nsbmd.write_png_rgba8(path, px_w, px_h, bytes(rgba))
    return uniq, color_of


_CLASS_MEANING = {
    0: "encounter family (id 4)", 1: "encounter family (id 5)",
    2: "encounter family (id 0x21)", 3: "id 8", 4: "id 10",
    5: "id 0x3d", 6: "id 0x3f/0x43", 7: "id 0x20", 8: "no terrain effect",
}


def write_legend(path, field, uniq, color_of):
    parent = os.path.dirname(os.path.abspath(path))
    if parent:
        os.makedirs(parent, exist_ok=True)
    with open(path, "w") as fh:
        fh.write(f"legend for field '{field}' ({len(uniq)} distinct values)\n")
        for v in uniq:
            r, g, b = color_of[v]
            line = f"  value {v:6d}  rgb({r},{g},{b})"
            if field == "terrain_class":
                line += f"  {_CLASS_MEANING.get(v, '?')}"
            fh.write(line + "\n")


# ---------------------------------------------------------------------------
# --stats: archive-wide histograms and the two cross-checks
# ---------------------------------------------------------------------------

def cmd_stats(a008):
    id_hist = Counter()
    class_hist = Counter()
    flag_hist = Counter()
    total_records = 0
    disagree = 0
    id_0x20_count = 0

    for i in range(a008.file_count):
        raw = a008.read(i)
        try:
            info = parse_wrapper(raw)
        except WrapperError as exc:
            print(f"  #{i}: skipped ({exc})", file=sys.stderr)
            continue
        for grid in info["grids"]:
            for rec in read_records(raw, grid):
                total_records += 1
                tid = rec["terrain_id"]
                flags = rec["flags"]
                id_hist[tid] += 1
                class_hist[rec["terrain_class"]] += 1
                flag_hist[flags] += 1
                if tid == 0x20:
                    id_0x20_count += 1
                if (tid == 1) != bool(flags & 1):
                    disagree += 1

    print(f"[*] a/0/0/8 terrain statistics over {total_records} records "
          f"(every ordinary 8-byte-record grid, all {a008.file_count} "
          f"sub-files)")
    print(f"    terrain id histogram (top 15): {id_hist.most_common(15)}")
    print(f"    terrain class histogram: {dict(sorted(class_hist.items()))}")
    print(f"    flag-word histogram (top 15): {flag_hist.most_common(15)}")
    print()
    print(f"    id==1 vs walkable-flag disagreement: {disagree} records "
          f"(expected 7377)")
    print(f"    class 7 count: {class_hist.get(7, 0)}  "
          f"id==0x20 count: {id_0x20_count}  (expected equal, 2096)")


# ---------------------------------------------------------------------------
# --dump / --png per target
# ---------------------------------------------------------------------------

def process_target(a008, name, index, out_dir, do_dump, do_png):
    raw = a008.read(index)
    info = parse_wrapper(raw)
    real_name = model_name(a008, index) or name
    print(f"[*] a/0/0/8#{index} '{real_name}' -- tag={info['tag']} "
          f"n_grids={len(info['grids'])} dense_grid="
          f"{'yes' if info['dense_grid'] else 'no'} tail_len={info['tail_len']}")

    dump_wrapper_info(info, real_name, os.path.join(out_dir, f"{name}_wrapper.txt"))

    for gi, grid in enumerate(info["grids"]):
        records = read_records(raw, grid)
        w, h = grid["width"], grid["height"]
        suffix = f"_grid{gi}" if len(info["grids"]) > 1 else "_grid"
        for field, label, fmt in DUMP_FIELDS:
            if do_dump:
                path = os.path.join(out_dir, f"{name}{suffix}_{label}.txt")
                _write_matrix(records, w, h, field, path, fmt)
            if do_png:
                path = os.path.join(out_dir, f"{name}{suffix}_{label}.png")
                uniq, color_of = write_field_png(records, w, h, field, path)
                write_legend(os.path.join(out_dir, f"{name}{suffix}_{label}_legend.txt"),
                             field, uniq, color_of)
                print(f"    grid{gi} {label}: {len(uniq)} distinct values -> {path}")
        if grid["aux_count"] and do_dump:
            dump_aux_text(read_aux_records(raw, grid),
                           os.path.join(out_dir, f"{name}{suffix}_aux.txt"))
            print(f"    grid{gi}: {grid['aux_count']} aux records -> "
                  f"{name}{suffix}_aux.txt")


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--out", default=os.path.join("build", "assets", "maps"))
    ap.add_argument("--targets", nargs="*",
                     help="subset of target names to process (default: all)")
    ap.add_argument("--dump", action="store_true", help="write per-field text matrices")
    ap.add_argument("--png", action="store_true", help="write per-field false-colour PNGs")
    ap.add_argument("--stats", action="store_true",
                     help="archive-wide terrain id/class/flag histograms "
                          "over all 649 sub-files")
    ap.add_argument("--verify", action="store_true",
                     help="byte-identical repack check, every sub-file")
    args = ap.parse_args(argv)

    if not (args.dump or args.png or args.stats or args.verify):
        args.dump = True
        args.png = True

    a008 = narcmod.parse_file(A008_PATH)

    if args.verify:
        return cmd_verify(a008)

    if args.stats:
        cmd_stats(a008)

    if args.dump or args.png:
        os.makedirs(args.out, exist_ok=True)
        wanted = set(args.targets) if args.targets else None
        for name, index in TARGETS:
            if wanted is not None and name not in wanted:
                continue
            process_target(a008, name, index, args.out, args.dump, args.png)

    return 0


if __name__ == "__main__":
    sys.exit(main())
