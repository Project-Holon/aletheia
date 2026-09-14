#!/usr/bin/env python3
"""
verify_compression.py -- decode every Huffman4/Huffman8/RLE sub-file found
under extract/data/ and confirm the decoded size matches the size declared
in the BIOS-style compression header.

Written from scratch for the aletheia project. Stdlib only, single file.

This is the verification step for narc.py's decompress_huffman() and
decompress_rle(): it does not write any decoded game data anywhere tracked,
it only reports pass/fail counts (and, for failures, the failing sub-file's
address so it can be re-examined).

Usage:
    python tools/assets/verify_compression.py
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402

DATA_ROOT = os.path.join("extract", "data")


def walk_files(root):
    for dirpath, dirnames, filenames in os.walk(root):
        dirnames.sort()
        for fn in sorted(filenames):
            yield os.path.join(dirpath, fn)


def main():
    if not os.path.isdir(DATA_ROOT):
        print(f"error: {DATA_ROOT} not found (run tools/ndsrom.py extract first)",
              file=sys.stderr)
        return 2

    totals = {"Huffman4": [0, 0], "Huffman8": [0, 0], "RLE": [0, 0]}  # [pass, fail]
    failures = []  # (kind, narc_path, sub_index, reason)

    for path in walk_files(DATA_ROOT):
        with open(path, "rb") as fh:
            head = fh.read(4)
        if head != b"NARC":
            continue
        try:
            n = narc.parse_file(path)
        except narc.NarcError as exc:
            print(f"[!] {path}: NARC parse error: {exc}", file=sys.stderr)
            continue
        for sub in n.subfiles:
            raw = n.read(sub.index)
            info = narc.sniff_compression(raw)
            if info is None:
                continue
            kind, dec_size = info
            if kind not in totals:
                continue
            try:
                if kind in ("Huffman4", "Huffman8"):
                    dec = narc.decompress_huffman(raw)
                else:
                    dec = narc.decompress_rle(raw)
                if len(dec) == dec_size:
                    totals[kind][0] += 1
                else:
                    totals[kind][1] += 1
                    failures.append((kind, path, sub.index,
                                      f"decoded 0x{len(dec):X} bytes, "
                                      f"header declared 0x{dec_size:X}"))
            except narc.NarcError as exc:
                totals[kind][1] += 1
                failures.append((kind, path, sub.index, str(exc)))

    rel_root = DATA_ROOT.replace(os.sep, "/")
    print(f"[*] scanned {rel_root} for Huffman4/Huffman8/RLE sub-files")
    for kind, (ok, bad) in totals.items():
        total = ok + bad
        print(f"    {kind:<10} {ok:4d}/{total:4d} decoded size matched "
              f"({bad} failed)" if total else f"    {kind:<10} 0/0 (none found)")

    if failures:
        print(f"\n[!] {len(failures)} failure(s):")
        for kind, path, idx, reason in failures:
            rel = path.replace("\\", "/")
            print(f"    {kind} {rel} sub-file #{idx}: {reason}")
        return 1

    print("\n[*] all Huffman4/Huffman8/RLE sub-files round-tripped to the declared size")
    return 0


if __name__ == "__main__":
    sys.exit(main())
