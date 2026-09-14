#!/usr/bin/env python3
"""
lz11.py -- NDS LZ11 encoder for the aletheia asset lane. The decoder
already lives in `tools/assets/narc.py` (`decompress_lz11`); this module
is compress-only and does not duplicate or re-export it.

Written from scratch for the aletheia project. Stdlib only, single file.

--------------------------------------------------------------------------
Recovered encoder policy
--------------------------------------------------------------------------
Method: same as `docs/NOTES.md` "Matching BLZ compression" -- decode an
original compressed sub-file back into its token stream, and diff a
candidate encoder's token choices against it position by position. Unlike
BLZ (a *backward*, in-place LZ77 used for ARM9/overlays), LZ11 here is a
plain **forward** LZ77 variant with a richer length encoding, and there is
no in-place-overlap safety margin to reconstruct -- every byte of every
sub-file is encoded (no verbatim tail), so the whole recovered policy is
just the match search itself:

* **greedy**, one decision per position, over the plaintext in its natural
  (forward) order -- no lazy matching. A plain greedy search (take the best
  match at the current position, never defer to check whether waiting one
  byte yields a better combined result) reproduces all 670 sub-files
  byte-for-byte once the two rules below are added, so there was no need
  to introduce lazy evaluation to explain any divergence.
* **matches may self-overlap**: unlike BLZ, `length` is allowed to exceed
  `displacement` (the standard LZ77 "run" trick, e.g. displacement 2 with
  any length repeats an alternating 2-byte pattern indefinitely). This is
  required -- forbidding it (as BLZ does) undercounts run lengths and
  diverges on the very first long solid-color run in every sample checked.
* **displacement 1 is never used**, even when it is the only way to reach
  the maximum match length (a run of N identical bytes with N < 4 is left
  as literals rather than encoded as a length-3 disp-1 match, which is
  cheaper). First divergence on `a/1/3/4` sub-file 25, plaintext offset
  194 (four repeated 0xCD bytes): the original leaves all four as literals
  even though a disp-1 length-3 match is available and legal by the format
  (the decoder itself places no floor above 1 on disp). Confirmed on all
  670 sub-files once the search excludes disp == 1: 0 remaining mismatches.
* **longest match wins, and among matches of the maximal length, the
  *farthest* (largest displacement) is encoded** -- the opposite tie-break
  from BLZ. Confirmed the same way: a nearest-tie candidate encoder
  matches sub-files 0 and 1 exactly but diverges on sub-file 25 at
  plaintext offset ~65810 (two adjacent maximal-length matches available,
  at displacement 2 and displacement 0x1000; the original picks 0x1000).
  Implemented by scanning window candidates farthest-to-nearest and
  updating the best match only on a *strictly* longer length, so the
  first (farthest) candidate reaching a given length is kept.
* field limits: minimum match length 3, maximum 0x10110 (the largest value
  the 3-token-size length encoding can express), window (maximum
  displacement) 0x1000, matching the decoder in `tools/assets/narc.py`.
* the shortest of the three token encodings that can express a given
  `length` is always used (this falls out of the length ranges being
  disjoint: 3-0x10 uses the 1-byte-indicator token, 0x11-0x110 the 8-bit-
  length token, 0x111-0x10110 the 16-bit-length token -- there is never a
  choice to make, so this is not an independent policy decision, just the
  format's own encoding table).

The round-trip harness (`compress(decompress(x)) == x` over all 670
sub-files of `a/1/3/4`) was run ad hoc, not committed as a script; the
result (670/670 exact) is recorded in `docs/ASSETS.md`.
"""

import bisect
import struct
import sys


MIN_MATCH = 3
MAX_MATCH = 0x10110
MAX_DISP = 0x1000


def _match_len(data, found, pos, max_len):
    """Longest run k (<= max_len) with data[found:found+k] == data[pos:pos+k].
    `found` < `pos`; self-overlap (k > pos - found) is allowed and handled
    correctly because `data` already holds the full plaintext -- comparing
    data[found + k] for found + k >= pos is exactly the value a decoder
    would have just written, since the plaintext is fixed ahead of time.
    """
    k = 0
    while k < max_len and data[found + k] == data[pos + k]:
        k += 1
    return k


def find_longest_match(data, pos, window_start, chain):
    """Return (length, disp) of the longest match for data[pos:] against
    data[window_start:pos], ties broken toward the farthest displacement
    (see module docstring), or (0, 0) if no match of length >= 3 exists.
    Self-overlapping matches (length > disp) are allowed, matching plain
    forward LZ77 semantics; displacement 1 is excluded. `chain` maps a
    3-byte seed to the list of positions (ascending order) sharing that
    seed; window filtering happens here via `lo`.
    """
    n = len(data)
    max_len = min(MAX_MATCH, n - pos)
    if max_len < MIN_MATCH:
        return 0, 0
    seed = data[pos:pos + 3]
    candidates = chain.get(seed)
    if not candidates:
        return 0, 0
    lo = max(window_start, pos - MAX_DISP)

    best_len = 0
    best_disp = 0
    # `candidates` is in ascending position order, i.e. farthest (smallest
    # position / largest displacement) first. Scan forward from the first
    # in-window candidate and update only on a *strictly* longer match, so
    # the farthest candidate reaching the maximum length wins ties. This
    # (not "nearest wins", the BLZ policy) is what matches the original
    # encoder's own choices -- see the lz11.py module docstring.
    start = bisect.bisect_left(candidates, lo)
    for found in candidates[start:]:
        if found > pos - 2:  # forbid disp == 1 (see module docstring)
            break
        length = _match_len(data, found, pos, max_len)
        if length > best_len:
            best_len = length
            best_disp = pos - found
            if best_len == max_len:
                break
    if best_len < MIN_MATCH:
        return 0, 0
    return best_len, best_disp


def compress(data, window_start=0):
    """Encode `data` as an NDS LZ11 (type 0x11) stream. `window_start` is
    the earliest position in `data` a match may reference (0 for a normal
    whole-buffer encode)."""
    n = len(data)
    if n < 0x1000000:
        header = bytes([0x11, n & 0xFF, (n >> 8) & 0xFF, (n >> 16) & 0xFF])
    else:
        header = bytes([0x11, 0, 0, 0]) + struct.pack("<I", n)

    # 3-byte-seed hash chain over the whole buffer, positions kept in
    # ascending order per seed; entries older than the sliding window are
    # dropped lazily by find_longest_match (via the `lo` cutoff), not here,
    # since removing from the middle of a list is expensive and the window
    # is small enough that stale entries cost little to skip.
    chain = {}

    def index_position(p):
        if p + 3 <= n:
            seed = data[p:p + 3]
            chain.setdefault(seed, []).append(p)

    out = bytearray()
    pos = 0
    indexed_up_to = 0
    while pos < n:
        flags = 0
        group = bytearray()
        for bit in range(8):
            if pos >= n:
                break
            while indexed_up_to < pos:
                index_position(indexed_up_to)
                indexed_up_to += 1
            length, disp = find_longest_match(data, pos, window_start, chain)
            if length >= MIN_MATCH:
                flags |= (0x80 >> bit)
                d = disp - 1
                if length <= 0x10:
                    l = length - 1
                    group.append((l << 4) | (d >> 8))
                    group.append(d & 0xFF)
                elif length <= 0x110:
                    l = length - 0x11
                    group.append((l >> 4) & 0x0F)
                    group.append(((l & 0x0F) << 4) | (d >> 8))
                    group.append(d & 0xFF)
                else:
                    l = length - 0x111
                    group.append(0x10 | (l >> 12))
                    group.append((l >> 4) & 0xFF)
                    group.append(((l & 0x0F) << 4) | (d >> 8))
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
    ap = argparse.ArgumentParser(description="NDS LZ11 encoder (compress only; "
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
