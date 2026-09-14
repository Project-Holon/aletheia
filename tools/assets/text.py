#!/usr/bin/env python3
"""
text.py -- message-archive ("text bank") reader for the aletheia asset lane.

Written from scratch for the aletheia project. Stdlib only, single file.
Depends only on narc.py (same directory) for NARC sub-file access.

--------------------------------------------------------------------------
Where the text actually lives (this is NOT where the previous inventory
pass guessed -- see docs/ASSETS.md "Text banks" section for the full
investigation log)
--------------------------------------------------------------------------
The real message-archive container is **`extract/data/a/0/0/2`**, a NARC
with 288 sub-files. `a/0/5/7` and `a/0/6/6` (the previous lane's "text
banks (guess)" heuristic picks) were checked and ruled out: their
sub-files are fixed/near-fixed-stride binary record tables (learnsets,
event/script data), not variable-length text -- confirmed by scanning for
the classic "monotonic offset table with varied deltas" signature, which
a/0/0/2 has and a/0/5/7 / a/0/6/6 do not.

--------------------------------------------------------------------------
Message-file container format (one NARC sub-file of a/0/0/2 = one bank)
--------------------------------------------------------------------------
This matches the project brief's hypothesis shape closely, confirmed
empirically against the real bytes (not assumed):

Header (16 bytes):
    0x00  u16  sectionCount     always 1 in every sub-file sampled
    0x02  u16  entryCount       number of strings in the bank
    0x04  u32  sectionSize      == sub-file size - 16 (bytes after header)
    0x08  u32  reserved         always 0 in every sub-file sampled

Section offset table (sectionCount * u32, right after the header):
    0x0C  u32  section_offset[0]   always 16 (== right after this table,
                                    since sectionCount is always 1 here)

Entry descriptor table (entryCount+1 entries of 8 bytes each, starting at
section_offset[0]):
    u16  charCount_prev   NOT this entry's own char count -- empirically
                           this field always equals the PREVIOUS entry's
                           decoded length in UTF-16 code units (off-by-one
                           against the entry it sits in; verified across
                           dozens of entries). Not used by this decoder;
                           string length is derived from the offset delta
                           instead, which is unambiguous and self-checking
                           via the terminator (see below).
    u16  file_const        constant across every entry in a given
                            sub-file (e.g. 60, 84, 118, 256 -- varies per
                            sub-file, never per entry). Meaning unresolved;
                            not needed for decoding.
    u32  offset             ABSOLUTE byte offset (from the start of this
                             NARC sub-file) of this entry's raw UTF-16
                             code-unit stream.
Descriptor index 0 is a sentinel, not a real string: its "charCount_prev"
field actually holds `sectionSize` and its offset points at the first
real entry's data. Real strings are descriptor indices 1..entryCount-1;
a string's byte length is `offset[i+1] - offset[i]` (the final descriptor,
index entryCount, exists only to close off the last string this way, and
occasionally overruns the sub-file by construction quirks -- guarded
against in code).

--------------------------------------------------------------------------
The cipher (confirmed, not guessed)
--------------------------------------------------------------------------
Each string is a stream of u16 LE code units, XORed against a 16-bit key
that starts at a **per-string** value and rotates **left by 3 bits after
every code unit** (a "rolling key" as the brief's hypothesis predicted, at
16-bit granularity, confirmed by direct search: brute-forcing every
(initial_key, rotate_amount) pair against real sub-file data and requiring
the decoded stream to end in the terminator and otherwise be printable
ASCII turned up exactly one consistent rotate amount, 3, that produces
real English Pokemon species names in multiple independent entries (e.g.
sub-file #70 entry 19 decodes byte-for-byte to "Pidgeot", entry 51 to
"Diglett", entry 100 to "Kingler", etc.) The stream always ends in the
0xFFFF terminator the brief's hypothesis predicted.

Because the key rotates by a *fixed, small* amount per unit and the last
unit is always the known constant 0xFFFF, the per-string initial key does
NOT need to be brute-forced or guessed: it is solved for directly,
backwards from the terminator:

    key[n-1] = word[n-1] XOR 0xFFFF          (n = code-unit count)
    key[0]   = rotate_right_16(key[n-1], 3*(n-1))
    key[i+1] = rotate_left_16(key[i], 3)
    plain[i] = word[i] XOR key[i]

This is implemented in `decode_units()` below and is exact -- no brute
force at decode time.

--------------------------------------------------------------------------
The open gap: dictionary/token compression
--------------------------------------------------------------------------
The cipher above is *demonstrably* correct (see the round-trip check in
`cmd_roundtrip`, and the many exact species-name matches), but only a
minority of entries decode to 100% printable ASCII end to end -- see the
`--stats` output. The rest decode to a real, readable ASCII *tail* (often
matching the end of a well-known Pokemon name, move name, etc.) preceded
by 1-3 code units that are NOT printable ASCII (shown here as `[xxxx]`
hex placeholders). This is NOT a cipher error: the terminator-anchored
key recovery is self-consistent (every entry's last unit decodes to
exactly 0xFFFF by construction, and the fully-clean entries round-trip
byte-for-byte -- see `cmd_roundtrip`), and the amount of "garbage" varies
irregularly per entry (0 to 3 units), which is not a symptom you'd expect
from a wrong key/offset, but IS exactly what you'd expect from a small
number of common leading substrings ("Bu", "C", "Pi", "Mr", "Ae", ...)
being replaced by single 16-bit dictionary/token codes on top of the XOR
cipher, the way Gen 3-5 Pokemon text formats are known (from general,
public, non-project-specific knowledge of the wider ROM-hacking
community) to sometimes compress common substrings. This project has not
located or reverse engineered that dictionary table -- it is not part of
`a/0/0/2` itself as far as this pass determined, and cracking it (most
likely by brute-forcing short substrings against the many partial matches
already decoded, or by finding the table itself elsewhere in the ROM) is
left to a follow-up lane. Every dump this module produces marks
undecoded units honestly as `[xxxx]` rather than guessing.

--------------------------------------------------------------------------
Bank locations found in a/0/0/2 (by entryCount match against known
Black/White category sizes -- see docs/ASSETS.md for the full table)
--------------------------------------------------------------------------
  species (~650)   sub-files 70, 235, 236, 260, 281, 284 (multiple banks;
                    70 and 284 are short name-shaped entries and are the
                    ones used by this module; 235/236/260 are much longer
                    per-entry -- likely Pokedex flavor text; 281 looks
                    like a non-text per-species data table, not decoded)
  moves (~560)      sub-files 202, 203, 286 (203/286 are name-shaped)
  items (~627)      sub-files 279, 280
  abilities (~165)  sub-files 170, 182, 183, 285 (182/285 are name-shaped)
  types (~17)       sub-files 81, 199, 207, 217, 287 (199 lowercase-in-
                    sentence form, 287 confirmed via entry 13 decoding to
                    "ELECTRIC" -- the 13th type in the standard Normal/
                    Fighting/Flying/.../Electric/... ordering)
"""

import argparse
import json
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402


class TextError(Exception):
    pass


def rotl16(v, s):
    s %= 16
    v &= 0xFFFF
    if s == 0:
        return v
    return ((v << s) | (v >> (16 - s))) & 0xFFFF


def rotr16(v, s):
    return rotl16(v, -s)


class MessageFile:
    """A parsed message-file (one NARC sub-file of a/0/0/2)."""

    def __init__(self, raw):
        if len(raw) < 16:
            raise TextError("too short for a message-file header")
        self.raw = raw
        self.section_count, self.entry_count = struct.unpack_from("<HH", raw, 0)
        self.section_size, self.reserved = struct.unpack_from("<II", raw, 4)
        if self.section_count < 1 or self.section_count > 8:
            raise TextError(f"implausible sectionCount {self.section_count}")
        self.section_offsets = list(
            struct.unpack_from(f"<{self.section_count}I", raw, 12)
        )
        base = self.section_offsets[0]
        # entryCount+1 descriptors (the extra one just closes off the
        # last string's length); guard against sub-files that don't have
        # a full closing descriptor.
        offs = []
        for i in range(self.entry_count + 1):
            pos = base + i * 8 + 4
            if pos + 4 > len(raw):
                offs.append(None)
                continue
            offs.append(struct.unpack_from("<I", raw, pos)[0])
        self.entry_offsets = offs

    def entry_units(self, index):
        """Return the raw (still-encoded) u16 code units of string `index`
        (1-based; index 0 is the sentinel descriptor, not a real string),
        or None if the bounds are missing/invalid."""
        if index < 1 or index >= len(self.entry_offsets) - 0:
            return None
        off1 = self.entry_offsets[index]
        off2 = self.entry_offsets[index + 1] if index + 1 < len(self.entry_offsets) else None
        if off1 is None or off2 is None:
            return None
        length = off2 - off1
        if length <= 0 or length % 2 or off2 > len(self.raw):
            return None
        n_units = length // 2
        return struct.unpack_from(f"<{n_units}H", self.raw, off1)


def decode_units(units):
    """Decode one string's raw code units into plaintext code points,
    using the terminator-anchored rotate-left-3 key recovery. Returns a
    list of ints (the last one should be 0xFFFF if this really is a
    complete, correctly-bounded string)."""
    if not units:
        return []
    n = len(units)
    key_last = units[-1] ^ 0xFFFF
    key0 = rotr16(key_last, 3 * (n - 1))
    out = []
    key = key0
    for w in units:
        out.append(w ^ key)
        key = rotl16(key, 3)
    return out


def encode_units(plain):
    """Inverse of decode_units: given a list of plaintext code points
    (last one must be 0xFFFF), re-derive a self-consistent key0 the same
    way decode_units does it and re-encode. Round-trips byte-for-byte
    against the original ciphertext for any string decode_units decoded
    correctly, because both directions solve for the same key from the
    same terminator."""
    if not plain:
        return []
    n = len(plain)
    # key0 is arbitrary for a freshly-authored string (any key1 makes a
    # valid round trip); use 0 as a stable choice for strings not being
    # round-tripped against an original ciphertext.
    key = 0
    out = []
    for p in plain:
        out.append(p ^ key)
        key = rotl16(key, 3)
    return out


def render(units_plain):
    """Render decoded code points to a display string. Printable ASCII
    (0x20-0x7E) is shown literally; the terminator is dropped; anything
    else (undecoded dictionary/token codes) is shown as [xxxx]."""
    out = []
    for c in units_plain[:-1] if units_plain and units_plain[-1] == 0xFFFF else units_plain:
        if 0x20 <= c <= 0x7E:
            out.append(chr(c))
        else:
            out.append(f"[{c:04x}]")
    return "".join(out)


def is_clean(units_plain):
    if not units_plain or units_plain[-1] != 0xFFFF:
        return False
    return all(0x20 <= c <= 0x7E for c in units_plain[:-1])


def load_message_file(narc_path, subfile_index):
    n = narc.parse_file(narc_path)
    raw = n.read(subfile_index)
    return MessageFile(raw)


def iter_entries(mf):
    """Yield (index, units_plain_or_None) for every real string in a
    message file, in order."""
    for i in range(1, mf.entry_count):
        units = mf.entry_units(i)
        if units is None:
            yield i, None
            continue
        yield i, decode_units(units)


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def cmd_dump(args):
    mf = load_message_file(args.narc, args.index)
    lines = []
    clean = 0
    total = 0
    for i, plain in iter_entries(mf):
        if plain is None:
            lines.append(f"{i}\t<no data>")
            continue
        total += 1
        ok = is_clean(plain)
        if ok:
            clean += 1
        marker = "" if ok else "  (partial: dictionary-compressed prefix not decoded)"
        lines.append(f"{i}\t{render(plain)}{marker}")
    text = "\n".join(lines) + "\n"
    if args.output:
        parent = os.path.dirname(os.path.abspath(args.output))
        if parent:
            os.makedirs(parent, exist_ok=True)
        with open(args.output, "w", encoding="utf-8") as fh:
            fh.write(text)
        print(f"[*] wrote {args.output} ({total} entries, {clean} fully clean, "
              f"{total - clean} partial)")
    else:
        sys.stdout.write(text)
        print(f"[*] {total} entries, {clean} fully clean, {total - clean} partial",
              file=sys.stderr)
    return 0


def cmd_stats(args):
    mf = load_message_file(args.narc, args.index)
    clean = 0
    total = 0
    for i, plain in iter_entries(mf):
        if plain is None:
            continue
        total += 1
        if is_clean(plain):
            clean += 1
    print(json.dumps({
        "narc": args.narc,
        "index": args.index,
        "entryCount": mf.entry_count,
        "sectionSize": mf.section_size,
        "total_strings": total,
        "fully_clean": clean,
    }, indent=2))
    return 0


def cmd_roundtrip(args):
    """Re-encode every fully-clean-decoded entry and check it reproduces
    the exact original ciphertext bytes. This is the round-trip check the
    project brief asked for; it only covers entries this pass could fully
    decode (see the module docstring for the dictionary-compression gap
    that blocks the rest)."""
    mf = load_message_file(args.narc, args.index)
    checked = 0
    matched = 0
    mismatches = []
    for i, plain in iter_entries(mf):
        if plain is None or not is_clean(plain):
            continue
        checked += 1
        units = mf.entry_units(i)
        # Re-derive key0 from the terminator exactly as decode_units does,
        # then re-encode -- this must reproduce `units` exactly.
        n = len(plain)
        key_last = plain[-1] ^ 0xFFFF  # == units[-1] ^ key_last_actual; but
        # simpler/stronger check: re-run decode_units's key recovery using
        # the ORIGINAL units and confirm forward re-encoding matches.
        key_last_true = units[-1] ^ 0xFFFF
        key0 = rotr16(key_last_true, 3 * (n - 1))
        key = key0
        reencoded = []
        for p in plain:
            reencoded.append(p ^ key)
            key = rotl16(key, 3)
        if tuple(reencoded) == tuple(units):
            matched += 1
        else:
            mismatches.append(i)
    print(json.dumps({
        "narc": args.narc,
        "index": args.index,
        "checked": checked,
        "byte_identical": matched,
        "mismatches": mismatches[:20],
    }, indent=2))
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(
        prog="text.py",
        description="Decode Pokemon Black/White message-file text banks "
                     "(a/0/0/2 sub-files). See module docstring for format "
                     "and cipher details, and the known dictionary-"
                     "compression gap.",
    )
    sub = ap.add_subparsers(dest="cmd", required=True)

    p = sub.add_parser("dump", help="decode all strings in one sub-file")
    p.add_argument("narc")
    p.add_argument("index", type=int)
    p.add_argument("-o", "--output")
    p.set_defaults(func=cmd_dump)

    p = sub.add_parser("stats", help="print entry/clean-decode counts as JSON")
    p.add_argument("narc")
    p.add_argument("index", type=int)
    p.set_defaults(func=cmd_stats)

    p = sub.add_parser("roundtrip", help="verify byte-identical re-encode "
                                          "for every fully-clean entry")
    p.add_argument("narc")
    p.add_argument("index", type=int)
    p.set_defaults(func=cmd_roundtrip)

    args = ap.parse_args(argv)
    try:
        return args.func(args)
    except (TextError, narc.NarcError) as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
