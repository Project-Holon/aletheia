#!/usr/bin/env python3
"""
verify_all.py -- archive-wide, sub-file-level round-trip sweep over every
NitroFS archive recorded in the asset census (`build/assets/census.json`).

Written from scratch for aletheia. Stdlib only, single file.

--------------------------------------------------------------------------
What this checks, per sub-file
--------------------------------------------------------------------------
1. Compression layer: if a sub-file is LZ77 (tag 0x10) or LZ11 (tag 0x11)
   compressed, it is decompressed with `narc.py`'s decoders and the
   decompressed bytes are re-compressed with `lz77.py`/`lz11.py` and
   compared against the original raw bytes -- byte-identical required.
   Huffman/RLE-compressed sub-files (no encoder exists in this project,
   see those modules' docstrings) are decompressed but not re-compressed;
   they cannot reach a full original-byte verdict and are reported as
   "skipped", not "pass", even if the decoded content itself verifies.

2. Format layer: the (decompressed, or original if uncompressed) payload's
   first 4 bytes are sniffed for a recognised NITRO/G3D magic and handed to
   the matching converter's parser; the parser's own `encode()` (or
   equivalent) is compared byte-for-byte against the payload. Recognised
   magics: NCLR/NCGR/NCER/NANR/NMCR/NMAR (`rig.py` + `battle_sprite.py`),
   NSCR (`background.py`), NSBMD/NSBTX and this project's other three G3D
   container kinds BCA0/BTA0/BTP0/BMA0 (`nsbmd.py` -- see its module-level
   `G3D_MAGICS`; only BMD0/BTX0's own MDL0/TEX0 blocks are decoded field by
   field, the animation containers are round-tripped at the container level
   only, their block contents kept opaque, same honesty level as this
   project's other "opaque blob" formats), NFTR (`font.py`, checked at the
   glyph-record grain via `Font.glyph_record_bytes`), and SDAT (identified
   by magic only -- this project has no byte-level SDAT round trip, see
   `sdat.py`'s module docstring; always reported "skipped", never "fail").
   Anything else ("plain"/unrecognised magic, or too short for one) is
   "skipped": this is exactly the census's "custom format, no decoder"
   territory, not a bug to chase here.

A sub-file's overall verdict:
    fail    -- the compression re-encode mismatched, OR a recognised
               format's decode/encode mismatched or raised.
    skipped -- no recognised format magic, OR the format verified but the
               sub-file's own compression kind has no encoder (Huffman/RLE),
               so the original raw bytes are not fully reproducible here.
    pass    -- every byte of the original sub-file is reproduced: either
               uncompressed with a verified format, or LZ77/LZ11-compressed
               with both the compression and the format layer verified.

--------------------------------------------------------------------------
Usage
--------------------------------------------------------------------------
    python tools/assets/verify_all.py                # every census archive
    python tools/assets/verify_all.py --archive a/0/6/4
    python tools/assets/verify_all.py --out build/assets/verify_all.json
"""

import argparse
import json
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402
import lz77  # noqa: E402
import lz11  # noqa: E402
import rig  # noqa: E402
import battle_sprite as bs  # noqa: E402
import background  # noqa: E402
import nsbmd  # noqa: E402
import font  # noqa: E402

EXTRACT_ROOT = os.path.join("extract", "data")
CENSUS_PATH = os.path.join("build", "assets", "census.json")
OUT_PATH = os.path.join("build", "assets", "verify_all.json")

FORMAT_DECODERS = {
    b"RGCN": lambda p: rig.parse_ncgr(p).encode() == p,
    b"RLCN": lambda p: bs.parse_nclr_full(p).encode() == p,
    b"RECN": lambda p: rig.parse_ncer(p).encode() == p,
    b"RNAN": lambda p: rig.parse_nanr(p).encode() == p,
    b"RCMN": lambda p: rig.parse_nmcr(p).encode() == p,
    b"RAMN": lambda p: rig.parse_nmar(p).encode() == p,
    b"RCSN": lambda p: background.parse_nscr(p).encode() == p,
    b"RTFN": lambda p: _verify_nftr(p),
}


def _verify_nftr(payload):
    f = font.Font(payload, 0)
    for gi in range(f.glyph_count):
        _start, orig = f._glyph_slice(gi)
        if f.glyph_record_bytes(gi) != orig:
            return False
    return True


def archive_path(name):
    if name.endswith(".narc") or "/" not in name:
        return os.path.join(EXTRACT_ROOT, name)
    return os.path.join(EXTRACT_ROOT, *name.split("/"))


def format_result(magic, payload):
    """Returns True/False/None: None means no recognised decoder (skip)."""
    if magic in nsbmd.G3D_MAGICS:
        try:
            same, _out, _in = nsbmd.round_trip_check(payload)
        except Exception:  # noqa: BLE001 -- best-effort sweep
            return False
        return same
    if magic == b"SDAT":
        return None  # identified, no byte-level encoder (see module docstring)
    fn = FORMAT_DECODERS.get(magic)
    if fn is None:
        return None
    try:
        return bool(fn(payload))
    except Exception:  # noqa: BLE001 -- best-effort sweep
        return False


def _compressed_match(recompressed, raw):
    """Compare a re-compressed LZ77/LZ11 stream against the original
    sub-file bytes, tolerating up to 3 trailing zero bytes: NARC sub-file
    boundaries (BTAF's per-entry offsets) pad each sub-file up to a 4-byte
    boundary, and for a compressed sub-file whose own stream length isn't
    already a multiple of 4 that padding is zero bytes appended after the
    LZ77/LZ11 stream itself, outside what either codec's own decompressed-
    size field describes -- confirmed directly on `a/1/7/3` sub-files 20/21/
    30/31 (1-2 extra 0x00 bytes each, every other byte an exact match)."""
    if recompressed == raw:
        return True
    extra = len(raw) - len(recompressed)
    if not (0 < extra < 4):
        return False
    return raw[:len(recompressed)] == recompressed and raw[len(recompressed):] == b"\x00" * extra


def verify_subfile(raw):
    """Returns (verdict, magic_repr) for one sub-file, verdict in
    {"pass", "fail", "skipped"}."""
    try:
        kind, dec = narc.try_decompress(raw)
    except narc.NarcError:
        kind, dec = None, None

    if kind is not None and dec is None:
        # A compression header was recognised but decoding itself failed
        # (truncated/corrupt stream) -- a genuine failure, not a skip.
        return "fail", b""

    comp_ok = None  # None = not compressed, or no encoder for this kind
    if kind == "LZ77":
        comp_ok = _compressed_match(lz77.compress(dec), raw)
        payload = dec
    elif kind == "LZ11":
        comp_ok = _compressed_match(lz11.compress(dec), raw)
        payload = dec
    elif kind is not None:
        # Huffman/RLE: decoded, but no encoder exists to re-verify the
        # compressed bytes -- see module docstring.
        payload = dec
    else:
        payload = raw

    magic = payload[:4] if len(payload) >= 4 else b""
    fresult = format_result(magic, payload)

    if comp_ok is False or fresult is False:
        return "fail", magic
    if fresult is True and kind in (None, "LZ77", "LZ11"):
        return "pass", magic
    return "skipped", magic


def verify_archive(path):
    counts = {"pass": 0, "fail": 0, "skipped": 0}
    magic_counts = {}
    try:
        n = narc.parse_file(path)
    except Exception as exc:  # noqa: BLE001
        return counts, magic_counts, f"archive parse error: {exc}"
    for sf in n.subfiles:
        try:
            raw = n.read(sf.index)
        except Exception:  # noqa: BLE001
            counts["fail"] += 1
            continue
        verdict, magic = verify_subfile(raw)
        counts[verdict] += 1
        key = repr(magic)
        magic_counts[key] = magic_counts.get(key, 0) + 1
    return counts, magic_counts, None


def load_census_paths():
    with open(CENSUS_PATH, encoding="utf-8") as fh:
        census = json.load(fh)
    return [a["path"] for a in census["archives"]]


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--archive", default=None,
                     help="verify one archive (e.g. a/0/6/4) instead of the whole census")
    ap.add_argument("--out", default=OUT_PATH)
    args = ap.parse_args(argv)

    names = [args.archive] if args.archive else load_census_paths()

    results = {}
    totals = {"pass": 0, "fail": 0, "skipped": 0}
    t0 = time.time()
    for i, name in enumerate(names):
        path = archive_path(name)
        if not os.path.exists(path):
            results[name] = {"error": "missing on disk"}
            continue
        counts, magic_counts, err = verify_archive(path)
        entry = {"counts": counts, "magics": magic_counts}
        if err:
            entry["error"] = err
        results[name] = entry
        for k in totals:
            totals[k] += counts[k]

    elapsed = time.time() - t0
    out = {
        "generated_by": "tools/assets/verify_all.py",
        "archive_count": len(names),
        "elapsed_seconds": round(elapsed, 1),
        "totals": totals,
        "archives": results,
    }
    os.makedirs(os.path.dirname(args.out), exist_ok=True)
    with open(args.out, "w", encoding="utf-8") as fh:
        json.dump(out, fh, indent=1)

    print(f"[*] verified {len(names)} archives in {elapsed:.1f}s: "
          f"{totals['pass']} pass, {totals['fail']} fail, {totals['skipped']} skipped")
    print(f"[*] wrote {args.out}")
    return 0 if totals["fail"] == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
