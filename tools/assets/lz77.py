#!/usr/bin/env python3
"""
lz77.py -- BIOS "LZ77 UnComp" (type 0x10) encoder for the aletheia asset
lane. The decoder already lives in `tools/assets/narc.py`
(`decompress_lz77`); this module is compress-only and does not duplicate or
re-export it.

Written from scratch for the aletheia project. Stdlib only, single file.

--------------------------------------------------------------------------
Recovered encoder policy
--------------------------------------------------------------------------
Method: same approach as `lz11.py` -- decode an original compressed
sub-file back into its token stream and diff a candidate encoder's choices
against it, over the icon archive `a/1/6/7` (650 LZ77-compressed NCGR icon
payloads, `tools/assets/icons.py`). The recovered policy:

* **greedy**, one decision per position, no lazy matching -- same as LZ11.
* **matches may self-overlap** (length > displacement is legal and used),
  same "run" trick as LZ11.
* **displacement 1 is never used**, exactly the same exclusion as LZ11 (see
  `lz11.py`'s module docstring for the reasoning; the same rule reproduces
  byte-exact output here too, first divergence without it appears inside
  `a/1/6/7`'s repeated 0xCC filler tile).
* **longest match wins, and among matches of the maximal length, the
  *farthest* (largest displacement) is encoded** -- same tie-break as
  LZ11. Confirmed against all 650 LZ77 sub-files of `a/1/6/7`: 0 mismatches
  with "farthest wins", vs. divergences on multiple sub-files with
  "nearest wins".
* field limits, per the plain BIOS LZ77 token encoding (a single indicator
  byte, no extended-length forms like LZ11 has): minimum match length 3,
  maximum 18 (a 4-bit length field, `length = nibble + 3`), window (maximum
  displacement) 0x1000 (a 12-bit displacement field, `disp = field + 1`),
  matching the decoder in `tools/assets/narc.py`.

Round-trip result (`compress(decompress(x)) == x` over all 650 LZ77
sub-files of `a/1/6/7`): 650/650 exact. Recorded in `docs/ASSETS.md`.
"""

import struct
import sys


MIN_MATCH = 3
MAX_MATCH = 18  # 4-bit length field: length = field + 3, field in 0..15
MAX_DISP = 0x1000  # 12-bit displacement field: disp = field + 1


def _match_len(data, found, pos, max_len):
    """Longest run k (<= max_len) with data[found:found+k] == data[pos:pos+k].
    Self-overlap (k > pos - found) is allowed, same reasoning as lz11.py's
    `_match_len`: `data` already holds the full plaintext, so comparing
    data[found + k] for found + k >= pos yields exactly the byte a decoder
    would just have written."""
    k = 0
    while k < max_len and data[found + k] == data[pos + k]:
        k += 1
    return k


def find_longest_match(data, pos, window_start):
    """Return (length, disp) of the longest match for data[pos:] against
    data[window_start:pos], ties broken toward the farthest displacement
    (see module docstring), or (0, 0) if no match of length >= 3 exists.
    Displacement 1 is excluded. Brute-force scan (no hash chain): the
    payloads this format is used on in this project (`a/1/6/7`, 304 bytes
    decompressed) are small enough that this is fast in practice."""
    n = len(data)
    max_len = min(MAX_MATCH, n - pos)
    if max_len < MIN_MATCH:
        return 0, 0
    lo = max(window_start, pos - MAX_DISP)

    best_len = 0
    best_disp = 0
    # Scan window candidates farthest-to-nearest (ascending source position)
    # and update only on a *strictly* longer match, so the farthest
    # candidate reaching the maximum length wins ties -- see module
    # docstring.
    for found in range(lo, pos):
        if pos - found == 1:  # forbid disp == 1
            continue
        length = _match_len(data, found, pos, max_len)
        if length > best_len:
            best_len = length
            best_disp = pos - found
    if best_len < MIN_MATCH:
        return 0, 0
    return best_len, best_disp


def compress(data, window_start=0):
    """Encode `data` as a BIOS LZ77 (type 0x10) stream. `window_start` is
    the earliest position in `data` a match may reference (0 for a normal
    whole-buffer encode)."""
    n = len(data)
    header = bytes([0x10, n & 0xFF, (n >> 8) & 0xFF, (n >> 16) & 0xFF])

    out = bytearray()
    pos = 0
    while pos < n:
        flags = 0
        group = bytearray()
        for bit in range(8):
            if pos >= n:
                break
            length, disp = find_longest_match(data, pos, window_start)
            if length >= MIN_MATCH:
                flags |= (0x80 >> bit)
                l = length - 3
                d = disp - 1
                group.append((l << 4) | (d >> 8))
                group.append(d & 0xFF)
                pos += length
            else:
                group.append(data[pos])
                pos += 1
        out.append(flags)
        out.extend(group)
    return bytes(header + out)


def main(argv=None):
    import argparse
    ap = argparse.ArgumentParser(description="BIOS LZ77 encoder (compress only; "
                                  "see tools/assets/narc.py for the decoder)")
    ap.add_argument("input")
    ap.add_argument("-o", "--output", required=True)
    args = ap.parse_args(argv)
    with open(args.input, "rb") as fh:
        data = fh.read()
    enc = compress(data)
    with open(args.output, "wb") as fh:
        fh.write(enc)
    print(f"[*] {args.input}: {len(data)} -> {len(enc)} bytes -> {args.output}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
