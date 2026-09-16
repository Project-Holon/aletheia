#!/usr/bin/env python3
"""
inventory.py -- survey extract/data/ and classify every NitroFS file.

Written from scratch for aletheia. Stdlib only, single file.

Walks extract/data/ (the 247 NitroFS files unpacked by tools/ndsrom.py),
and for every leaf file reports:

  * path (relative to extract/data/), size
  * container type: "NARC" (magic b"NARC") or "raw" (anything else, which
    in this ROM means either a single BIOS-compressed blob, an SDAT sound
    archive, or an unrecognised/Game Freak custom format)
  * for a NARC: sub-file count, a histogram of sub-file magics (the first
    4 bytes of each sub-file, printable ASCII or hex), a histogram of
    sub-file compression headers (LZ77/LZ11/Huffman4/Huffman8/RLE/none)
  * a best-effort category guess (see ``guess_category`` below) -- these
    are heuristics over magic/count/size only, not verified against any
    external file list, and are labelled as guesses throughout.

Usage:
    python tools/assets/inventory.py                 print table, write JSON
    python tools/assets/inventory.py --json-only      suppress the table
"""

import argparse
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402


DATA_ROOT = os.path.join("extract", "data")
OUT_JSON = os.path.join("build", "assets", "inventory.json")

# NITRO chunk magics seen in this ROM's NARCs, and what they mean.
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


def compression_label(raw):
    info = narc.sniff_compression(raw)
    if info is None:
        return "none"
    return info[0]


def scan_narc(path, size):
    n = narc.parse_file(path)
    magic_hist = {}
    comp_hist = {}
    sizes = []
    for sub in n.subfiles:
        data = n.read(sub.index)
        sizes.append(len(data))
        mlabel = magic_label(sub.magic)
        magic_hist[mlabel] = magic_hist.get(mlabel, 0) + 1
        clabel = compression_label(data)
        comp_hist[clabel] = comp_hist.get(clabel, 0) + 1
    return {
        "container": "NARC",
        "sub_file_count": n.file_count,
        "magic_histogram": magic_hist,
        "compression_histogram": comp_hist,
        "sub_file_size_min": min(sizes) if sizes else 0,
        "sub_file_size_max": max(sizes) if sizes else 0,
        "sub_file_size_total": sum(sizes),
    }


def scan_raw(path, size, head):
    info = narc.sniff_compression(head + b"\x00" * 4) if len(head) < 4 else None
    # Re-sniff properly against the real file head (4 bytes is enough).
    comp = narc.sniff_compression(head)
    magic = head[:4]
    result = {
        "container": "raw",
        "sub_file_count": 0,
        "magic_histogram": {magic_label(magic): 1},
        "compression_histogram": {},
    }
    if magic == b"SDAT":
        result["compression_histogram"] = {"none": 1}
    elif comp is not None:
        result["compression_histogram"] = {comp[0]: 1}
        result["whole_file_decompressed_size"] = comp[1]
    else:
        result["compression_histogram"] = {"none": 1}
    return result


# ---------------------------------------------------------------------------
# category guessing
# ---------------------------------------------------------------------------

def guess_category(rel_path, size, info):
    """Best-effort category guess. Returns (category, note). Everything here
    is a heuristic over magic/count/size, not ground truth -- label as a
    guess wherever it is reported."""
    magics = info.get("magic_histogram", {})
    count = info.get("sub_file_count", 0)
    lower = rel_path.lower()

    if magics.get("SDAT (sound archive)") or "SDAT" in magics:
        return ("sound (SDAT archive)", "magic is SDAT, unambiguous")
    if lower.endswith(".sdat"):
        return ("sound (SDAT archive)", "file extension + SDAT magic")

    gfx_tile = magics.get("NCGR (tile/character data)", 0)
    gfx_pal = magics.get("NCLR (palette)", 0)
    gfx_scr = magics.get("NSCR (screen/map)", 0)
    gfx_cell = magics.get("NCER (cell bank)", 0) + magics.get("NANR (cell animation)", 0)
    model = magics.get("NSBMD (model)", 0) + magics.get("NSBTX (texture)", 0)

    is_sprite_like = (gfx_tile + gfx_cell) > 0 and info["container"] == "NARC"
    is_map_like = gfx_scr > 0 and gfx_tile > 0 and gfx_cell == 0

    if model > 0:
        return ("3D model/texture data (guess)", f"{model} BMD0/BTX0 sub-files")

    if is_map_like:
        return ("map/tileset graphics (guess)", "NSCR+NCGR without NCER cells")

    if is_sprite_like:
        # Pokemon Black has 649 species; sprite NARCs tend to carry a
        # handful of sub-files per species (front/back/shiny palettes etc),
        # so a count in the low thousands with small per-entry sizes and
        # heavy NCGR/NCLR/NCER mix is our best signal for "creature sprites".
        if count >= 1500:
            return ("pokemon battle sprites (guess)",
                    f"{count} sub-files, large multiple of species count "
                    "(~649) suggests per-species front/back/shiny/anim sets")
        if 300 <= count < 1500:
            return ("pokemon/trainer sprites (guess)",
                    f"{count} sub-files, order of magnitude of species or "
                    "trainer-class count")
        if 20 <= count < 300:
            return ("trainer/item/UI sprites (guess)",
                    f"{count} sub-files, too few for full species roster")
        return ("small sprite/icon set (guess)", f"only {count} sub-files")

    if info["container"] == "raw":
        comp = info.get("compression_histogram", {})
        if "LZ77" in comp or "LZ11" in comp:
            return ("single compressed blob (guess: font/graphic)",
                    "raw file, one BIOS-compressed payload, no NARC wrapper")
        return ("unknown raw format", "no NITRO magic, no compression header")

    if info["container"] == "NARC" and gfx_tile == 0 and gfx_pal == 0 and gfx_scr == 0 and gfx_cell == 0 and model == 0:
        others = magics
        # No recognised NITRO graphics chunk anywhere in this archive.
        if count > 500:
            return ("text banks (guess)",
                    f"{count} sub-files, no NITRO graphics magics: shape "
                    "matches per-message/per-string text archives")
        if count > 0:
            return ("scripts/data tables (guess)",
                    f"{count} sub-files, no NITRO graphics magics: "
                    "Game Freak custom format, no legible magic")
        return ("unknown", "empty or unparseable NARC")

    return ("unknown", "did not match any heuristic")


# ---------------------------------------------------------------------------
# walking
# ---------------------------------------------------------------------------

def walk_data(root):
    entries = []
    for dirpath, dirnames, filenames in os.walk(root):
        dirnames.sort()
        for fn in sorted(filenames):
            full = os.path.join(dirpath, fn)
            rel = os.path.relpath(full, root).replace(os.sep, "/")
            entries.append((rel, full))
    entries.sort(key=lambda t: t[0])
    return entries


def scan_all(root):
    results = []
    for rel, full in walk_data(root):
        size = os.path.getsize(full)
        with open(full, "rb") as fh:
            head = fh.read(4)
        if head == b"NARC":
            try:
                info = scan_narc(full, size)
            except narc.NarcError as exc:
                info = {"container": "NARC-parse-error", "error": str(exc),
                         "sub_file_count": 0, "magic_histogram": {},
                         "compression_histogram": {}}
        else:
            info = scan_raw(full, size, head)
        category, note = guess_category(rel, size, info)
        entry = {
            "path": rel,
            "size": size,
            **info,
            "category_guess": category,
            "category_note": note,
        }
        results.append(entry)
    return results


# ---------------------------------------------------------------------------
# reporting
# ---------------------------------------------------------------------------

def print_table(results):
    print(f"{'path':<22} {'size':>10} {'type':<6} {'subs':>6}  "
          f"{'dominant formats':<40} category (guess)")
    print("-" * 120)
    for e in results:
        magics = e.get("magic_histogram", {})
        top = sorted(magics.items(), key=lambda kv: -kv[1])[:3]
        dom = ", ".join(f"{k}x{v}" for k, v in top)
        ctype = e["container"]
        print(f"{e['path']:<22} {e['size']:>10} {ctype:<6} "
              f"{e.get('sub_file_count', 0):>6}  {dom:<40} {e['category_guess']}")


def summarize(results):
    total_narc = sum(1 for e in results if e["container"] == "NARC")
    total_raw = sum(1 for e in results if e["container"] == "raw")
    total_subs = sum(e.get("sub_file_count", 0) for e in results)
    magic_totals = {}
    comp_totals = {}
    for e in results:
        for k, v in e.get("magic_histogram", {}).items():
            magic_totals[k] = magic_totals.get(k, 0) + v
        for k, v in e.get("compression_histogram", {}).items():
            comp_totals[k] = comp_totals.get(k, 0) + v
    return {
        "files": len(results),
        "narc_files": total_narc,
        "raw_files": total_raw,
        "total_sub_files": total_subs,
        "magic_totals": magic_totals,
        "compression_totals": comp_totals,
    }


def main(argv=None):
    ap = argparse.ArgumentParser(
        prog="inventory.py",
        description="Inventory and classify every NitroFS file under extract/data/.",
    )
    ap.add_argument("--json-only", action="store_true",
                     help="skip the stdout table, only write the JSON summary")
    ap.add_argument("--root", default=DATA_ROOT,
                     help=f"data root to walk (default {DATA_ROOT})")
    ap.add_argument("--out", default=OUT_JSON,
                     help=f"where to write the JSON summary (default {OUT_JSON})")
    args = ap.parse_args(argv)

    if not os.path.isdir(args.root):
        print(f"error: {args.root} not found (run tools/ndsrom.py extract first)",
              file=sys.stderr)
        return 2

    results = scan_all(args.root)
    summary = summarize(results)

    if not args.json_only:
        print_table(results)
        print()
        print(f"[*] {summary['files']} files: {summary['narc_files']} NARC, "
              f"{summary['raw_files']} raw")
        print(f"[*] {summary['total_sub_files']} total sub-files across all NARCs")
        print("[*] magic totals:")
        for k, v in sorted(summary["magic_totals"].items(), key=lambda kv: -kv[1]):
            print(f"      {k:<30} {v}")
        print("[*] compression totals:")
        for k, v in sorted(summary["compression_totals"].items(), key=lambda kv: -kv[1]):
            print(f"      {k:<12} {v}")

    out_dir = os.path.dirname(args.out)
    if out_dir:
        os.makedirs(out_dir, exist_ok=True)
    with open(args.out, "w", encoding="utf-8") as fh:
        json.dump({"summary": summary, "files": results}, fh, indent=2)
    if not args.json_only:
        print(f"[*] wrote {args.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
