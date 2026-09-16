#!/usr/bin/env python3
"""
map_shapes.py -- per-shape textured OBJ export for `a/0/0/8` map/building/
dungeon models, built on top of `nsbmd.py`'s newly-cracked shape-dictionary
descriptor layout (see nsbmd.py's "MDL0 shape dictionary" section).

Written from scratch for aletheia. Stdlib only.

--------------------------------------------------------------------------
What this does that plain `nsbmd.py obj` could not
--------------------------------------------------------------------------
`nsbmd.py`'s existing `obj`/`write_obj` path decodes a model's ENTIRE GX
command stream as one merged mesh (no per-shape boundaries, no material
assignment). This script instead:

  1. locates the model's shape ResDict and decodes each shape's own 16-byte
     descriptor (`nsbmd.find_shape_dict` / `nsbmd.shape_descriptors`,
     confirmed record layout: itemTag/size/flag/dlOffset/dlSize);
  2. decodes each shape's own bounded GX byte range separately
     (`nsbmd.decode_shape_dl`), instead of one merged decode -- real
     per-shape face groups, not a fabricated split;
  3. reads the render-command bytecode (`nsbmd.find_render_commands`) to
     get each shape's bound material index, and the material ResDict's
     names (numeric-suffixed, e.g. `pk_l_mado_4`) to recover the real
     texture name each shape uses (`pk_l_mado_4` -> `pk_l_mado`);
  4. looks up and decodes that real texture from `a/0/1/4` (the shared
     terrain/building texture archive, confirmed in the earlier map-model
     pass), and normalises each shape's UVs against ITS OWN texture's real
     decoded size (not one texture borrowed for the whole merged mesh);
  5. writes one OBJ with a `g`/`usemtl` group per shape, a matching `.mtl`,
     and the PNGs actually used.

--------------------------------------------------------------------------
Wrapper stripping (`a/0/0/8`, confirmed in the earlier map-model pass)
--------------------------------------------------------------------------
Each `a/0/0/8` sub-file is `header || BMD0-model || per-tile-grid || tail`.
This script strips the header the same way the earlier pass did:
`payload = raw[raw.find(b"BMD0"):]`, then hands `payload` to
`nsbmd.parse_container`.

--------------------------------------------------------------------------
UV normalisation rule (confirmed, not assumed)
--------------------------------------------------------------------------
`gx_decode`'s TEXCOORD values are already texel units (s16.4 fixed-point,
divided down in `nsbmd.gx_decode`) -- confirmed by the existing `cmd_obj`
UV-normalisation code in `nsbmd.py`, which divides by a guessed texture's
pixel width/height to land in the usual OBJ 0..1 range, and by direct
inspection here: raw decoded UVs for real shapes run into the tens/
hundreds (texel-scale), never a small 0..1-ish range on their own. This
script does the same divide, per shape, against THAT SHAPE's own real
texture dimensions (recovered from the material link, not guessed) --
this is the "UV scaling by texture size" normalisation the mission asks
about. No DS material-record texture-coordinate-transform SCALE field
(TEXIMAGE_PARAM bits 14-15, "coord xform") was found to need separate
handling beyond this: the material ResDict's own per-entry record layout
is a separate, still-uncracked structure (see nsbmd.py's pre-existing
TEX0 "honesty note"; the MDL0 material dict's OWN entries were not
decoded this pass, only its NAMES, which is all the texture link needs) --
so any additional scale/offset/rotation a material's texture matrix might
apply is a documented, not-yet-investigated gap, not silently ignored.
"""

import argparse
import glob
import os
import re
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc as narcmod  # noqa: E402
import nsbmd  # noqa: E402

A008_PATH = os.path.join("extract", "data", "a", "0", "0", "8")
A014_GLOB_DIR = os.path.join("extract", "data", "a", "0", "1", "4")


def strip_wrapper(raw):
    pos = raw.find(b"BMD0")
    if pos < 0:
        raise nsbmd.Nsbmd0Error("no BMD0 magic found in a/0/0/8 sub-file")
    return raw[pos:]


def find_material_dict(dicts, shape_off, shape_to_mat, tex_archive):
    """The MDL0 material dict, identified structurally rather than by a
    fixed naming convention: `pl_00_00`'s materials all carry a numeric
    variant suffix over the real texture name (`pk_l_mado_4` ->
    `pk_l_mado`), but this turned out to be model-specific, not a project-
    wide rule -- `map24_23`'s material dict instead uses the BARE real
    texture name directly for a first use, only appending `_<n>` for a
    repeat-use variant (e.g. `sea_mizu1_1` alongside plain `sea_mizu1`).

    So instead of requiring every name to match a suffix pattern, this
    scores every non-shape, non-palette (`_pl`-suffixed) candidate dict by
    how many of its names -- tried both as-is and with any trailing
    `_<digits>` stripped -- are REAL texture names known to `tex_archive`
    (the actual a/0/1/4 archive index, not a guess), and additionally
    requires the dict be large enough to cover every material index the
    render-command bytecode actually references. The dict scoring highest
    wins; this is a genuine cross-check against real data, not a blind
    heuristic."""
    max_mat_id = max(shape_to_mat.values(), default=-1)
    best = None
    best_score = -1
    for off, rd in dicts:
        if off == shape_off or rd.count == 0:
            continue
        if all(nm.endswith("_pl") for nm in rd.names):
            continue  # palette-name dict
        if rd.count <= max_mat_id:
            continue  # too small to be indexed by the highest material id used
        score = 0
        for nm in rd.names:
            base = re.sub(r"_\d+$", "", nm)
            if nm in tex_archive.name_to_subfile or base in tex_archive.name_to_subfile:
                score += 1
        if score > best_score:
            best_score = score
            best = (off, rd)
    return best


def bare_texture_name(material_name):
    return re.sub(r"_\d+$", "", material_name)


def load_model(a008_narc, index):
    raw = a008_narc.read(index)
    payload = strip_wrapper(raw)
    container = nsbmd.parse_container(payload)
    mdl0 = nsbmd.find_mdl0(container)
    if mdl0 is None:
        raise nsbmd.Nsbmd0Error(f"a/0/0/8#{index}: no MDL0 block")
    name = mdl0.model_dict.names[0] if mdl0.model_dict.names else f"model{index}"
    return name, mdl0.raw_tail


def shape_export_data(buf, tex_archive):
    """Returns (shapes, mat_names, shape_to_mat) where `shapes` is a list
    of (shape_index, verts, uvs, faces) in shape-dict order (verts/uvs/
    faces local to that shape, decoded via nsbmd.decode_shape_dl), and
    shape_to_mat maps shape index -> material index (from the render
    command bytecode), possibly missing entries if the bytecode scan came
    up short."""
    dicts = nsbmd.find_resdicts(buf)
    shape_hit = nsbmd.find_shape_dict(buf, dicts)
    if shape_hit is None:
        raise nsbmd.Nsbmd0Error("no shape dict found (structural test failed)")
    shape_off, shape_rd = shape_hit
    dl_base, descs = nsbmd.shape_descriptors(buf, shape_off, shape_rd)

    _, shape_to_mat = nsbmd.find_render_commands(buf)

    mat_hit = find_material_dict(dicts, shape_off, shape_to_mat, tex_archive)
    mat_names = mat_hit[1].names if mat_hit is not None else []

    shapes = []
    for i, (itemTag, size, flag, dlOffset, dlSize) in enumerate(descs):
        verts, uvs, faces = nsbmd.decode_shape_dl(buf, dl_base, dlOffset, dlSize)
        if verts is None:
            verts, uvs, faces = [], [], []
        shapes.append((i, verts, uvs, faces))
    return shapes, mat_names, shape_to_mat


# ---------------------------------------------------------------------------
# a/0/1/4 texture archive lookup (built once, reused across map models)
# ---------------------------------------------------------------------------

class TextureArchive:
    """Lazily-decoded index over a/0/1/4's 282 NSBTX sub-files: cheap name
    scan up front (tex_dict.names only, no pixel decoding), full decode
    only for sub-files that actually get used."""

    def __init__(self, narc_path):
        self.narc = narcmod.parse_file(narc_path)
        self.name_to_subfile = {}
        for i in range(self.narc.file_count):
            raw = self.narc.read(i)
            if raw[:4] not in (b"BTX0", b"BMD0"):
                continue
            try:
                c = nsbmd.parse_container(raw)
            except nsbmd.Nsbmd0Error:
                continue
            tex0 = nsbmd.find_tex0(c)
            if tex0 is None:
                continue
            for name in tex0.tex_dict.names:
                self.name_to_subfile.setdefault(name, i)
        self._decoded_subfiles = {}  # subfile idx -> {name: (w, h, rgba)}

    def _decode_subfile(self, idx):
        if idx in self._decoded_subfiles:
            return self._decoded_subfiles[idx]
        raw = self.narc.read(idx)
        c = nsbmd.parse_container(raw)
        tex0 = nsbmd.find_tex0(c)
        out = {}
        for tr, pal_name, rgba, ratio in nsbmd.decode_all_textures(tex0):
            out[tr.name] = (tr.width, tr.height, rgba)
        self._decoded_subfiles[idx] = out
        return out

    def get(self, name):
        """Returns (width, height, rgba_bytes) or None if not found."""
        idx = self.name_to_subfile.get(name)
        if idx is None:
            return None
        return self._decode_subfile(idx).get(name)


# ---------------------------------------------------------------------------
# OBJ/MTL export
# ---------------------------------------------------------------------------

def export_textured(model_name, buf, tex_archive, out_dir, out_basename=None):
    shapes, mat_names, shape_to_mat = shape_export_data(buf, tex_archive)

    base_for_name = out_basename or model_name
    safe = "".join(ch if ch.isalnum() or ch in "._-" else "_" for ch in base_for_name)
    obj_path = os.path.join(out_dir, f"{safe}.obj")
    mtl_path = os.path.join(out_dir, f"{safe}.mtl")
    tex_dir = os.path.join(out_dir, f"{safe}_textures")

    used_textures = {}  # bare_name -> (w, h, rgba) or None (not found)
    shape_records = []  # (shape_idx, verts, uvs, faces, texname_or_None)
    matched = 0
    for shape_idx, verts, uvs, faces in shapes:
        mat_idx = shape_to_mat.get(shape_idx)
        texname = None
        if mat_idx is not None and mat_idx < len(mat_names):
            texname = bare_texture_name(mat_names[mat_idx])
            matched += 1
        if texname is not None and texname not in used_textures:
            found = tex_archive.get(texname)
            used_textures[texname] = found
        shape_records.append((shape_idx, verts, uvs, faces, texname))

    # write PNGs for every texture that was actually found
    os.makedirs(tex_dir, exist_ok=True)
    for texname, found in used_textures.items():
        if found is None:
            continue
        w, h, rgba = found
        nsbmd.write_png_rgba8(os.path.join(tex_dir, f"{texname}.png"), w, h, rgba)

    # write MTL
    with open(mtl_path, "w") as fh:
        fh.write(f"# exported by tools/assets/map_shapes.py for {model_name}\n")
        for texname, found in used_textures.items():
            fh.write(f"newmtl {texname}\n")
            if found is not None:
                fh.write(f"map_Kd {os.path.basename(tex_dir)}/{texname}.png\n")
            fh.write("Kd 1.0 1.0 1.0\n\n")
        fh.write("newmtl _unassigned\nKd 0.6 0.6 0.6\n\n")

    # write OBJ, one group per shape, global vertex/uv index accounting
    v_count = 0
    face_report = []
    with open(obj_path, "w") as fh:
        fh.write(f"# exported by tools/assets/map_shapes.py -- {model_name}\n")
        fh.write(f"mtllib {os.path.basename(mtl_path)}\n")
        for shape_idx, verts, uvs, faces, texname in shape_records:
            if not verts:
                face_report.append((shape_idx, texname, 0, 0))
                continue
            wh = used_textures.get(texname) if texname else None
            tw, th = (wh[0], wh[1]) if wh else (1.0, 1.0)
            fh.write(f"g shape{shape_idx}\n")
            fh.write(f"usemtl {texname if texname else '_unassigned'}\n")
            for x, y, z in verts:
                fh.write(f"v {x:.6f} {y:.6f} {z:.6f}\n")
            for u, v in uvs:
                fh.write(f"vt {u / tw:.6f} {1.0 - v / th:.6f}\n")
            for face in faces:
                idx = " ".join(f"{v_count + i + 1}/{v_count + i + 1}" for i in face)
                fh.write(f"f {idx}\n")
            v_count += len(verts)
            face_report.append((shape_idx, texname, len(verts), len(faces)))

    return {
        "obj": obj_path,
        "mtl": mtl_path,
        "n_shapes": len(shapes),
        "n_matched": matched,
        "used_textures": {k: (v is not None) for k, v in used_textures.items()},
        "face_report": face_report,
    }


TARGETS = [
    # (expected model name, a/0/0/8 index, output basename)
    ("pl_00_00", 120, "pl_00_00_textured"),
    ("map24_23", 0, "map24_23"),
    ("map14_13", 44, "map14_13"),
    ("m_dun0101_00_00", 279, "m_dun0101_00_00"),
]


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--out", default=os.path.join("build", "assets", "maps"))
    ap.add_argument("--targets", nargs="*",
                     help="subset of target names to export (default: all)")
    args = ap.parse_args(argv)

    a008 = narcmod.parse_file(A008_PATH)
    print("[*] indexing a/0/1/4 texture archive (name scan only)...")
    tex_archive = TextureArchive(os.path.join("extract", "data", "a", "0", "1", "4"))
    print(f"[*] {len(tex_archive.name_to_subfile)} texture names indexed across "
          f"{tex_archive.narc.file_count} sub-files")

    os.makedirs(args.out, exist_ok=True)
    wanted = set(args.targets) if args.targets else None

    for expected_name, idx, out_basename in TARGETS:
        if wanted is not None and expected_name not in wanted:
            continue
        name, buf = load_model(a008, idx)
        print(f"\n[*] a/0/0/8#{idx} -> model '{name}' (raw_tail {len(buf)} bytes)")
        result = export_textured(name, buf, tex_archive, args.out, out_basename)
        n_ok = sum(1 for v in result["used_textures"].values() if v)
        n_missing = sum(1 for v in result["used_textures"].values() if not v)
        total_faces = sum(f for _, _, _, f in result["face_report"])
        zero_face = sum(1 for _, _, v, f in result["face_report"] if v and f == 0)
        print(f"    shapes: {result['n_shapes']}, matched to a material: "
              f"{result['n_matched']}")
        print(f"    distinct textures used: {len(result['used_textures'])} "
              f"({n_ok} decoded, {n_missing} not found in a/0/1/4)")
        print(f"    total faces across all shapes: {total_faces} "
              f"({zero_face} shapes decoded vertices but 0 faces)")
        print(f"    wrote {result['obj']}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
