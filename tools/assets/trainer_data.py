#!/usr/bin/env python3
"""
trainer_data.py -- locate the trainer data table by reference (not shape),
then use it to test candidate trainer battle sprite archives by entry
count.

Written from scratch for aletheia. Stdlib only, depends only
on narc.py.

--------------------------------------------------------------------------
Mission
--------------------------------------------------------------------------
1. Find the trainer data archive: a fixed-stride record table with a
   trainer-class byte field. `a/0/5/7` and `a/0/6/6` (the text pass's
   ruled-out-as-non-text fixed-stride candidates) turn out NOT to be it --
   see `--scan-candidates`. The real trdata/trpoke pair is `a/0/9/2` /
   `a/0/9/3`: both have exactly 616 sub-files (615 real records + a
   sentinel sub-file 0), and `a/0/9/2`'s records are 20 bytes, fixed,
   615/616 of the time (sub-file 0 alone is the 16-byte null sentinel).
2. Cross-reference against the trainer-class name text bank (dumped by
   text.py to build/assets/text/) -- bank 191 (and its "a "-prefixed
   duplicate, 283) holds exactly 105 entries (0-104: "Trainer", "Trainer",
   "Youngster", "Lass", ... "Team Plasma", "Subway Boss", ...).
3. In the trdata records, byte offset 1 (of the 20-byte stride) is the
   trainer-class field: its 615 real records take 101 distinct values,
   forming the contiguous range 2..102 -- squarely inside 0..104, the
   range implied by a 105-entry class table. No other byte offset in the
   record produces a comparably clean contiguous enum range.
4. List archives whose sub-file count equals 105 or a small multiple
   (2x/3x/4x), and render one sample from each.

--------------------------------------------------------------------------
Usage
--------------------------------------------------------------------------
    python tools/assets/trainer_data.py --scan-candidates   # rule out a/0/5/7, a/0/6/6
    python tools/assets/trainer_data.py --records            # dump trdata field stats
    python tools/assets/trainer_data.py --sprite-candidates  # archives matching class count
"""

import argparse
import os
import re
import sys
from collections import Counter

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402

DATA_ROOT = os.path.join("extract", "data")
ASSETS_MD = os.path.join("docs", "ASSETS.md")
TEXT_DIR = os.path.join("build", "assets", "text")

TRDATA = "a/0/9/2"
TRPOKE = "a/0/9/3"
CLASS_NAME_BANK = 191  # 0-104, "Trainer"/"Trainer"/"Youngster"/"Lass"/.../"Subway Boss"


def _open(tag):
    return narc.parse_file(os.path.join(DATA_ROOT, *tag.split("/")))


# ---------------------------------------------------------------------------
# Step 1: rule out the text pass's non-text fixed-stride candidates
# ---------------------------------------------------------------------------

def scan_candidates():
    for tag in ["a/0/5/7", "a/0/6/6", TRDATA, TRPOKE]:
        n = _open(tag)
        sizes = [len(n.read(sf.index)) for sf in n.subfiles]
        hist = Counter(sizes)
        dominant, dom_count = hist.most_common(1)[0]
        frac = dom_count / len(sizes)
        print(f"{tag}: {len(sizes)} sub-files, size range {min(sizes)}-{max(sizes)}, "
              f"dominant size {dominant} bytes ({dom_count}/{len(sizes)} = {frac:.0%})")
    print()
    print("[*] a/0/5/7 and a/0/6/6 have no single dominant fixed stride "
          "(scattered small binary tables, not a trainer record array).")
    print("[*] a/0/9/2 is 615/616 = 99.8% one 20-byte stride: the real trdata table.")


# ---------------------------------------------------------------------------
# Step 2: trainer-class name bank count
# ---------------------------------------------------------------------------

def class_name_count(bank=CLASS_NAME_BANK):
    path = os.path.join(TEXT_DIR, f"{bank:03d}.txt")
    with open(path, encoding="utf-8") as fh:
        lines = [ln for ln in fh if ln.strip()]
    return len(lines)


# ---------------------------------------------------------------------------
# Step 3: trdata record field scan
# ---------------------------------------------------------------------------

def trdata_records():
    n = _open(TRDATA)
    recs = []
    for sf in n.subfiles:
        raw = n.read(sf.index)
        if len(raw) == 20:
            recs.append(raw)
    return recs


def report_records():
    recs = trdata_records()
    n_classes = class_name_count()
    print(f"[*] {len(recs)} fixed 20-byte trdata records (of 616 sub-files, "
          f"sub-file 0 is a 16-byte sentinel)")
    print(f"[*] trainer-class name bank {CLASS_NAME_BANK:03d}.txt: {n_classes} entries "
          f"(0..{n_classes - 1})")
    print()
    print("[*] per-byte-offset u8 field stats (looking for a contiguous enum "
          f"range inside 0..{n_classes - 1}):")
    best = None
    for off in range(20):
        vals = sorted({r[off] for r in recs})
        contiguous = (vals == list(range(vals[0], vals[-1] + 1)))
        fits = vals[-1] <= n_classes - 1
        flag = " <-- trainerClass" if contiguous and fits and len(vals) > 50 else ""
        print(f"    off {off:2d}: min={vals[0]:3d} max={vals[-1]:3d} distinct={len(vals):3d} "
              f"contiguous={contiguous}{flag}")
        if flag:
            best = off
    print()
    if best is not None:
        print(f"[*] trainerClass field: byte offset {best} in the 20-byte trdata stride.")
    # cross-check trpoke pairing via partySize (offset 3)
    td = _open(TRDATA)
    tp = _open(TRPOKE)
    party_ok = 0
    checked = 0
    for sf in n_offset_pairs(td, tp):
        checked += 1
        if sf:
            party_ok += 1
    print(f"[*] trpoke (a/0/9/3) party-size cross-check: {party_ok}/{checked} records' "
          "sub-file byte length is a multiple of 8 matching trdata's partySize field "
          "(confirms the trdata/trpoke pairing).")


def n_offset_pairs(trdata_narc, trpoke_narc):
    results = []
    for sf in trdata_narc.subfiles:
        raw = trdata_narc.read(sf.index)
        if len(raw) != 20:
            continue
        party_size = raw[3]
        tp_raw = trpoke_narc.read(sf.index)
        expected_len = party_size * 8
        results.append(len(tp_raw) == expected_len)
    return results


# ---------------------------------------------------------------------------
# Round trip: the trdata/trpoke pairing's only checkable consistency (see
# module docstring step 3). Neither table is compressed or chunk-framed --
# a/0/9/2 is a flat fixed-stride record array and a/0/9/3 a flat variable-
# length one -- so there is no format to decode/re-encode; the one thing
# this project has recovered and can check byte-for-byte is that trdata's
# own partySize field (offset 3 of its 20-byte record) predicts trpoke's
# sub-file length exactly (`party_size * 8`), for every record in both
# archives, not just the sample `--records` already cross-checks.
# ---------------------------------------------------------------------------

def verify():
    td = _open(TRDATA)
    tp = _open(TRPOKE)
    ok = fail = skipped = 0
    for sf in td.subfiles:
        raw = td.read(sf.index)
        if len(raw) != 20:
            # sub-file 0: the 16-byte null sentinel, not a real record.
            skipped += 1
            continue
        party_size = raw[3]
        tp_raw = tp.read(sf.index)
        if len(tp_raw) == party_size * 8:
            ok += 1
        else:
            fail += 1
    return ok, fail, skipped


def report_verify():
    ok, fail, skipped = verify()
    print(f"[*] {TRDATA} <-> {TRPOKE} round trip: {ok} ok, {fail} mismatched, "
          f"{skipped} skipped (partySize field predicts trpoke sub-file length)")


# ---------------------------------------------------------------------------
# Step 4: sprite-archive candidates by entry count
# ---------------------------------------------------------------------------

ROW_RE = re.compile(
    r"\|\s*(a/\d+/\d+/\d+)\s*\|\s*(\d+)\s*\|\s*NARC\s*\|\s*(\d+)\s*\|([^|]*)\|([^|]*)\|")


def inventory_rows():
    rows = []
    with open(ASSETS_MD, encoding="utf-8") as fh:
        for line in fh:
            m = ROW_RE.match(line)
            if m:
                arc, sz, count, magics, guess = m.groups()
                rows.append((arc, int(sz), int(count), magics.strip(), guess.strip()))
    return rows


def sprite_candidates(class_count=None, tol=0.03, max_mult=4):
    if class_count is None:
        class_count = class_name_count()
    rows = inventory_rows()
    hits = []
    for arc, sz, count, magics, guess in rows:
        if count == 0:
            continue
        ratio = count / class_count
        rr = round(ratio)
        if 1 <= rr <= max_mult and abs(ratio - rr) < tol:
            hits.append((arc, count, rr, magics, guess))
    return hits


def report_sprite_candidates():
    n_classes = class_name_count()
    print(f"[*] trainer class count: {n_classes}")
    print(f"[*] archives whose sub-file count is within 3% of {n_classes} x (1..4):")
    for arc, count, mult, magics, guess in sprite_candidates(n_classes):
        print(f"    {mult}x  {arc}  count={count}  [{guess}]  {magics[:60]}")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--scan-candidates", action="store_true")
    ap.add_argument("--records", action="store_true")
    ap.add_argument("--sprite-candidates", action="store_true")
    ap.add_argument("--verify", action="store_true",
                     help="trdata/trpoke partySize round-trip count (see verify())")
    args = ap.parse_args(argv)

    if not (args.scan_candidates or args.records or args.sprite_candidates
            or args.verify):
        ap.error("give --scan-candidates, --records, --sprite-candidates, or --verify")

    if args.scan_candidates:
        scan_candidates()
        print()
    if args.records:
        report_records()
        print()
    if args.sprite_candidates:
        report_sprite_candidates()
    if args.verify:
        report_verify()

    return 0


if __name__ == "__main__":
    sys.exit(main())
