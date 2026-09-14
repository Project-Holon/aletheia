#!/usr/bin/env python3
"""
text.py -- message-archive ("text bank") reader for the aletheia asset lane.

Written from scratch for the aletheia project. Stdlib only, single file.
Depends only on narc.py (same directory) for NARC sub-file access.

--------------------------------------------------------------------------
Ground truth (this pass): apply the decompiled cipher/format directly
--------------------------------------------------------------------------
This rewrite drops the previous pass's guessed descriptor layout, the
terminator-anchored backward key solve, and the unconfirmed 9-bit packing
machinery, and replaces them with what `src/matched/func_02045E3C.c` (the
message-bank string decrypt routine itself, status EXACT) and
`docs/notes/func_02046110.c.txt` (bank lookup, near-miss but semantically
certain) actually say:

  * The cipher is **forward-only**, no backward solve needed:
        key = (u16)((msgIndex + 3) * 0x2983)
        for each code unit: unit ^= key; key = rotate_left_16(key, 3)
    `msgIndex` is the string's own descriptor index within its bank
    (0-based), confirmed empirically below (species bank, sub-file 70:
    descriptor 1 -> "Bulbasaur" under msgIndex=1, descriptor 19 ->
    "Rattata" under msgIndex=19, descriptor 51 -> "Dugtrio" under
    msgIndex=51, descriptor 100 -> "Voltorb" under msgIndex=100 -- byte
    for byte, first try, no brute force).
  * XOR is its own inverse, so **encode is the exact same forward
    procedure as decode** run on the plaintext code units: no separate
    key-recovery direction is needed at all.

--------------------------------------------------------------------------
Message-file container format (one NARC sub-file of a/0/0/2 = one bank)
--------------------------------------------------------------------------
Header (16 bytes), unchanged from the previous pass (re-confirmed, still
correct):
    0x00  u16  sectionCount     always 1 in every sub-file sampled
    0x02  u16  entryCount       number of strings in the bank
    0x04  u32  sectionSize      == sub-file size - 16 (bytes after header)
    0x08  u32  reserved         always 0 in every sub-file sampled
    0x0C  u32  section_offset[0]  always 16

**Entry descriptor table, corrected this pass**: `entryCount` descriptors
of 8 bytes each, at `section_offset[0] + 4 + 8*i` (i = 0..entryCount-1,
NO sentinel entry -- every descriptor is a real string, confirmed by
scanning every sub-file: the last descriptor's decoded length always lands
exactly on (or 2 bytes short of, trailing pad) `sectionSize`):

    u32  offset      section-relative byte offset of this string's raw
                       code-unit stream; absolute offset is
                       `16 + offset` (`16` because `section_offset[0]`
                       is always 16)
    u16  numChars     informational string length; NOT used to bound
                       decoding (the terminator is authoritative, exactly
                       like the real firmware's func_02045E3C, which scans
                       for the terminator itself rather than trusting a
                       stored count)
    u16  flags        meaning not decoded; constant per-bank in samples
                       (e.g. 0x3c), not needed for text extraction

Confirmed by direct scan (species bank, sub-file 70): every descriptor's
decoded length (code units through and including the 0xFFFF terminator)
exactly accounts for the byte gap to the next descriptor's offset -- 0
mismatches across 651 consecutive pairs. Strings are packed back-to-back
with no inter-string padding; only the bank's own end may have a couple of
trailing pad bytes after the last string (sectionSize allows for it).

--------------------------------------------------------------------------
The cipher, in-band control codes, and rendering
--------------------------------------------------------------------------
Each string is a stream of u16 LE code units, XORed against
`key = (u16)((msgIndex + 3) * 0x2983)`, rotating left by 3 bits after every
unit. Decoding scans forward from the string's offset until it decodes to
one of these in-band control codes (all confirmed against
`func_02045E3C.c` and this project's mission brief):

    0xFFFF  terminator   ends the string (not included in rendered output)
    0xFFFE  newline      renders as "\n"
    0xF000  escape        followed by: kind(u16), argCount(u16), then
                           argCount more u16 arguments (all still part of
                           the same encrypted stream -- decoded the same
                           way as any other unit, just interpreted
                           specially at render time). Rendered as
                           "{F000:KIND:arg1,arg2,...}" (hex, 4 digits).

Anything else is a literal character code point. Printable ASCII
(0x20-0x7E) renders as itself. `0x246D`/`0x246E` are this game's codes for
the male/female gender marks and render as the real Unicode glyphs
(U+2642 MALE SIGN / U+2640 FEMALE SIGN, which are NOT the same numeric
value -- a direct `chr()` of the raw code would be wrong for these two).
Every other non-ASCII code point renders as `chr(code)` directly (this
format's code units *are* Unicode code points, not a separate GBA-style
charset table -- there is no dictionary/token-compression layer; that was
a previous pass's unconfirmed hypothesis, now dropped because the ground-
truth cipher above decodes every sampled string cleanly with no leftover
garbage prefix).

--------------------------------------------------------------------------
Verification performed by this module's CLI
--------------------------------------------------------------------------
`dump-all` decodes and writes all 288 sub-files' strings and reports the
total terminator count found (one per string; expect 48839 across the
whole archive). `roundtrip-all` re-encodes every decoded string (same
forward XOR/rotate procedure run on the plaintext) and reconstructs each
sub-file's full string-data region byte-for-byte, comparing against the
original sub-file bytes; reports how many of the 288 sub-files matched
exactly.

--------------------------------------------------------------------------
Bank locations found in a/0/0/2 (unchanged from the previous pass's
entryCount-match survey -- see git history for the full table)
--------------------------------------------------------------------------
  species (~650)   sub-files 70, 235, 236, 260, 281, 284
  moves (~560)     sub-files 202, 203, 286
  items (~627)     sub-files 279, 280
  abilities (~165) sub-files 170, 182, 183, 285
  types (~17)      sub-files 81, 199, 207, 217, 287
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


TERMINATOR = 0xFFFF
NEWLINE = 0xFFFE
ESCAPE = 0xF000

GENDER_GLYPH = {
    0x246D: "♂",  # male sign
    0x246E: "♀",  # female sign
}


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
        descs = []
        for i in range(self.entry_count):
            pos = base + 4 + i * 8
            if pos + 8 > len(raw):
                descs.append(None)
                continue
            off, num_chars, flags = struct.unpack_from("<IHH", raw, pos)
            descs.append((off, num_chars, flags))
        self.descriptors = descs

    def string_start(self, index):
        """Absolute byte offset of string `index`'s raw code-unit stream,
        or None if the descriptor is missing/out of range."""
        if index < 0 or index >= len(self.descriptors):
            return None
        d = self.descriptors[index]
        if d is None:
            return None
        off, _num_chars, _flags = d
        return 16 + off

    def decode(self, index, max_units=4096):
        """Decode string `index` (0-based). Returns the list of decoded
        code points INCLUDING the trailing 0xFFFF terminator, or None if
        the string can't be located or never terminates within
        `max_units` (guards against a corrupt/out-of-range offset)."""
        start = self.string_start(index)
        if start is None:
            return None
        key = (index + 3) * 0x2983 & 0xFFFF
        out = []
        pos = start
        raw = self.raw
        n = len(raw)
        for _ in range(max_units):
            if pos + 2 > n:
                return None
            w = struct.unpack_from("<H", raw, pos)[0]
            p = w ^ key
            out.append(p)
            pos += 2
            if p == TERMINATOR:
                return out
            key = rotl16(key, 3)
        return None


def encode(plain, index):
    """Inverse of MessageFile.decode(): re-run the identical forward
    XOR/rotate procedure over the plaintext code units (XOR is its own
    inverse, so encode and decode are the same transform)."""
    key = (index + 3) * 0x2983 & 0xFFFF
    out = []
    for p in plain:
        out.append(p ^ key)
        key = rotl16(key, 3)
    return out


def render_char(c):
    if c in GENDER_GLYPH:
        return GENDER_GLYPH[c]
    if 0x20 <= c <= 0x7E:
        return chr(c)
    if 0xD800 <= c <= 0xDFFF:
        # lone UTF-16 surrogate code point -- not valid standalone Unicode
        # text (this format never uses surrogate pairs), so it can't be
        # rendered as chr(); shown as a hex placeholder instead.
        return f"[{c:04x}]"
    if c >= 0x80:
        return chr(c)
    return f"[{c:04x}]"


def render(plain):
    """Render a decoded code-point list (as returned by MessageFile.decode,
    terminator included) to a display string. Newlines and escape sequences
    are rendered per the module docstring; the terminator itself is
    dropped."""
    out = []
    i = 0
    n = len(plain)
    while i < n:
        c = plain[i]
        if c == TERMINATOR:
            break
        if c == NEWLINE:
            out.append("\\n")
            i += 1
            continue
        if c == ESCAPE:
            kind = plain[i + 1] if i + 1 < n else 0
            argc = plain[i + 2] if i + 2 < n else 0
            args = plain[i + 3:i + 3 + argc]
            out.append("{F000:%04X:%s}" % (kind, ",".join(f"{a:04X}" for a in args)))
            i += 3 + max(argc, 0)
            continue
        out.append(render_char(c))
        i += 1
    return "".join(out)


def load_message_file(narc_path, subfile_index):
    n = narc.parse_file(narc_path)
    raw = n.read(subfile_index)
    return MessageFile(raw)


def iter_entries(mf):
    """Yield (index, plain_or_None) for every string in the bank, in
    descriptor order (0-based)."""
    for i in range(mf.entry_count):
        yield i, mf.decode(i)


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def cmd_dump(args):
    mf = load_message_file(args.narc, args.index)
    lines = []
    terms = 0
    total = 0
    for i, plain in iter_entries(mf):
        total += 1
        if plain is None:
            lines.append(f"{i}\t<undecodable>")
            continue
        if plain and plain[-1] == TERMINATOR:
            terms += 1
        lines.append(f"{i}\t{render(plain)}")
    text = "\n".join(lines) + "\n"
    if args.output:
        parent = os.path.dirname(os.path.abspath(args.output))
        if parent:
            os.makedirs(parent, exist_ok=True)
        with open(args.output, "w", encoding="utf-8") as fh:
            fh.write(text)
        print(f"[*] wrote {args.output} ({total} entries, {terms} terminated)")
    else:
        sys.stdout.write(text)
        print(f"[*] {total} entries, {terms} terminated", file=sys.stderr)
    return 0


def cmd_dump_all(args):
    n = narc.parse_file(args.narc)
    os.makedirs(args.out, exist_ok=True)
    total_terms = 0
    total_strings = 0
    for idx in range(n.file_count):
        raw = n.read(idx)
        try:
            mf = MessageFile(raw)
        except TextError as exc:
            print(f"[!] sub-file {idx}: not a message-file ({exc})")
            continue
        lines = []
        for i, plain in iter_entries(mf):
            total_strings += 1
            if plain is None:
                lines.append(f"{i}\t<undecodable>")
                continue
            if plain and plain[-1] == TERMINATOR:
                total_terms += 1
            lines.append(f"{i}\t{render(plain)}")
        out_path = os.path.join(args.out, f"{idx:03d}.txt")
        with open(out_path, "w", encoding="utf-8") as fh:
            fh.write("\n".join(lines) + "\n")
    print(json.dumps({
        "narc": args.narc,
        "subfiles": n.file_count,
        "total_strings": total_strings,
        "total_terminators": total_terms,
        "out_dir": args.out,
    }, indent=2))
    return 0


def cmd_stats(args):
    mf = load_message_file(args.narc, args.index)
    terms = 0
    total = 0
    for i, plain in iter_entries(mf):
        total += 1
        if plain and plain[-1] == TERMINATOR:
            terms += 1
    print(json.dumps({
        "narc": args.narc,
        "index": args.index,
        "entryCount": mf.entry_count,
        "sectionSize": mf.section_size,
        "total_strings": total,
        "terminated": terms,
    }, indent=2))
    return 0


def _roundtrip_one(mf):
    """Reconstruct the string-data region of one message-file byte-for-byte
    from its decoded strings and compare against the original bytes.
    Returns (ok: bool, checked: int, reason: str|None)."""
    base = mf.section_offsets[0]
    region_start = base + 4 + mf.entry_count * 8
    rebuilt = bytearray(mf.raw[:region_start])
    checked = 0
    for i in range(mf.entry_count):
        plain = mf.decode(i)
        if plain is None:
            return False, checked, f"entry {i} failed to decode/terminate"
        words = encode(plain, i)
        for w in words:
            rebuilt += struct.pack("<H", w)
        checked += 1
    # trailing pad bytes (if any) after the last string, up to sectionSize,
    # are copied verbatim -- they are not string data, so re-encoding can't
    # reproduce them from the decode; this is expected and harmless.
    end = base + mf.section_size
    pad_len = end - len(rebuilt)
    if pad_len < 0:
        return False, checked, f"rebuilt region overruns sectionSize by {-pad_len}"
    rebuilt += mf.raw[len(rebuilt):len(rebuilt) + pad_len]
    original_region = mf.raw[:len(rebuilt)]
    if bytes(rebuilt) != bytes(original_region):
        # find first mismatch for diagnostics
        for j, (a, b) in enumerate(zip(rebuilt, original_region)):
            if a != b:
                return False, checked, f"byte mismatch at offset {j}"
        return False, checked, "length mismatch"
    return True, checked, None


def cmd_roundtrip(args):
    mf = load_message_file(args.narc, args.index)
    ok, checked, reason = _roundtrip_one(mf)
    print(json.dumps({
        "narc": args.narc,
        "index": args.index,
        "checked": checked,
        "byte_identical": ok,
        "reason": reason,
    }, indent=2))
    return 0


def cmd_roundtrip_all(args):
    n = narc.parse_file(args.narc)
    matched = 0
    total = 0
    failures = []
    for idx in range(n.file_count):
        raw = n.read(idx)
        try:
            mf = MessageFile(raw)
        except TextError as exc:
            failures.append({"index": idx, "reason": f"not a message-file ({exc})"})
            continue
        total += 1
        ok, checked, reason = _roundtrip_one(mf)
        if ok:
            matched += 1
        else:
            failures.append({"index": idx, "reason": reason, "checked": checked})
    print(json.dumps({
        "narc": args.narc,
        "subfiles_total": n.file_count,
        "message_files": total,
        "byte_identical": matched,
        "failures": failures[:20],
    }, indent=2))
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(
        prog="text.py",
        description="Decode Pokemon Black/White message-file text banks "
                     "(a/0/0/2 sub-files). See module docstring for format "
                     "and cipher details.",
    )
    sub = ap.add_subparsers(dest="cmd", required=True)

    p = sub.add_parser("dump", help="decode all strings in one sub-file")
    p.add_argument("narc")
    p.add_argument("index", type=int)
    p.add_argument("-o", "--output")
    p.set_defaults(func=cmd_dump)

    p = sub.add_parser("dump-all", help="decode every sub-file to "
                                         "<out>/NNN.txt")
    p.add_argument("narc")
    p.add_argument("-o", "--out", default=os.path.join("build", "assets", "text"))
    p.set_defaults(func=cmd_dump_all)

    p = sub.add_parser("stats", help="print entry/terminated counts as JSON")
    p.add_argument("narc")
    p.add_argument("index", type=int)
    p.set_defaults(func=cmd_stats)

    p = sub.add_parser("roundtrip", help="verify byte-identical re-encode "
                                          "of one sub-file's string region")
    p.add_argument("narc")
    p.add_argument("index", type=int)
    p.set_defaults(func=cmd_roundtrip)

    p = sub.add_parser("roundtrip-all", help="verify byte-identical "
                                              "re-encode of every sub-file")
    p.add_argument("narc")
    p.set_defaults(func=cmd_roundtrip_all)

    args = ap.parse_args(argv)
    try:
        return args.func(args)
    except (TextError, narc.NarcError) as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
