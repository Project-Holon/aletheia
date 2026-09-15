#!/usr/bin/env python3
"""
events.py -- container framing for `a/0/0/3` (472 sub-files) and `a/0/6/6`
(601 sub-files). Both were flagged by an earlier asset pass as the likely
home of per-map door/warp/NPC/trigger records (see docs/ASSETS.md, "Map
attribute hunt" section, "(2) Separate per-zone NARC search"), but the
script-VM pass that followed the field-script interpreter's own code (see
docs/ASSETS.md, "Script virtual machine located and decompiled") settled
the question for `a/0/0/3`: it is reached through the zone record's `+0x0a`
lane as a `field_x`-indexed *message bank*, not a bytecode/event table --
the real script archive is `a/0/5/7` (tools/assets/scripts.py). This
module therefore both frames `a/0/0/3`'s container (the index table over
variable-length records) AND decrypts those records as text, through the
same cipher as `a/0/0/2` (tools/assets/text.py): `field_x & 0xFFFF` is the
record's length in u16 code units, and `key = (index + 3) * 0x2983`
(rotate left 3 after every code unit), with `index` the record's own
position inside its sub-file (0-based). `a/0/6/6` is unaffected by this
finding; its role remains open (see below).

Written from scratch for the aletheia asset lane. Stdlib only.

Both archives fail the "fixed-stride record array" hypothesis this pass
started from (checked directly: no divisor of every sub-file's body size
yields a byte offset where hand-picked samples show bounded, map-sized
coordinate values -- because there IS no fixed stride, see below). What
both actually are is a small self-describing header followed by N
variable-length byte blocks; this module locates the header fields and the
blocks precisely enough for a byte-identical repack, without decoding the
blocks' own internal bytecode (that would be guessing at semantics this
pass cannot verify -- see docs/ASSETS.md for what's confirmed vs open).

--------------------------------------------------------------------------
`a/0/0/3` framing (HIGH confidence, confirmed on all 472 sub-files)
--------------------------------------------------------------------------
Outer header, 16 bytes:
    0x00  u16  tag          always 1
    0x02  u16  count        N, the number of records in this file (1-481)
    0x04  u32  body_size    == file size - 16, true on 472/472 files
    0x08  u32  reserved     always 0
    0x0C  u32  header_len   always 16 (self-referencing: same convention
                             as the a/0/0/8 wrapper header, see
                             tools/assets/map_grid.py)

Body (body_size bytes, starts right after the outer header):
    0x00  u32  body_size_dup   == the outer header's body_size, on
                                 472/472 files (a second, redundant
                                 length check)
    0x04  N * 8-byte index entries, each:
              u32  record_offset   byte offset of this record's data,
                                   relative to the START OF THE BODY (i.e.
                                   counted from the body_size_dup word).
                                   entry[0].record_offset always equals
                                   4 + 8*N (immediately past this table,
                                   confirmed 472/472); the whole sequence
                                   is strictly increasing with no
                                   duplicates, confirmed 472/472 -- the
                                   table is real, not coincidental noise
                                   (the odds of N-1 independent random
                                   words happening to sort increasing,
                                   for N up to 481, rule that out).
              u32  field_x         CONFIRMED this pass (docs/ASSETS.md,
                                   "`a/0/0/3` is the text bank, and
                                   `field_x` is a length"): `field_x &
                                   0xFFFF` is the record's encrypted length
                                   in u16 code units. Decrypting all 7861
                                   records of all 472 sub-files and reading
                                   the code unit at `length - 1` gives the
                                   string terminator 0xFFFF in 7861/7861
                                   cases. The top byte is a flag, 0xE0 on
                                   6139 records and 0x00 on 1096, with a
                                   small tail of other values whose meaning
                                   is still open.
    record[k] payload:  raw bytes from record_offset[k] to
                        record_offset[k+1] (or body_size for the last
                        record) -- variable length. This is the record's
                        RAW (encrypted) code-unit stream; decode_record()
                        below decrypts it to code points (see "Decoding
                        records as text").

--------------------------------------------------------------------------
`a/0/6/6` framing (HIGH confidence, confirmed on all 601 sub-files)
--------------------------------------------------------------------------
Outer header:
    0x00  u32  group_count G   one of {1, 2, 3, 5, 8} archive-wide
                                (574 files at G=1, 23 at G=2, 2 at G=5,
                                1 at G=3, 1 at G=8)
    0x04  G * 14 u32 words, but NOT 14*G independent values: every
          consecutive run of 14 words is IDENTICAL (confirmed on every
          group in all 601 files -- 641 groups total, all pass), so there
          are really only G distinct values here, each repeated 14 times.
          Why 14 is an open question (see docs/ASSETS.md); this module
          treats the block of 14 as one field and does not attempt to
          explain the redundancy.
    header_len = 4 + 4*14*G = 4 + 56*G. group_value[0] always equals
    header_len exactly (confirmed 601/601): the first group's data starts
    right past the header, same self-referencing convention as `a/0/0/3`
    and the a/0/0/8 wrapper.

Group data: group[k] spans group_value[k] .. group_value[k+1] (or file end
for the last group). Group sizes vary widely within and across files (no
fixed stride found: the 20 most common group sizes archive-wide each
account for well under 10% of all 641 groups) -- this reads as G
variable-length blocks, not a per-tile array. G's small, discrete range
(1/2/3/5/8, never anything else) is more consistent with a per-resource
count of LANGUAGE-variant blocks (matching this NARC's existing inventory
category guess, "text banks") than with a per-map object list, which
argues against this archive being the door/warp table; see docs/ASSETS.md.

--------------------------------------------------------------------------
Doors/warps: ruled out for `a/0/0/3`, still open for `a/0/6/6`
--------------------------------------------------------------------------
`a/0/0/3` is a message bank, not an event/door/warp table (see the module
docstring above): the zone record's `+0x0a` lane indexes it directly
(values 2..468 against 472 sub-files), and every record decrypts to a
plausible game string (e.g. sub-file 5's records 0-2 decrypt to "Ha ha
ha", "My, my. My.", "I'm tired"). The door/warp/NPC/trigger table, if
there is a dedicated one at all, is not this archive.

`a/0/6/6` is unaffected by the above and remains open: neither archive's
sub-file count lines up with `a/0/0/8`'s 649 map files on its own, this
ROM has no usable BTNF names outside one unrelated NARC (`a/2/3/2`, see
docs/ASSETS.md's "BTNF name table results"), and no separate zone/map
lookup table has been found anywhere in this archive set, so there is
still no confirmed way to line up an `a/0/6/6` index with a specific
`a/0/0/8` map file and its walkable-tile grid (tools/assets/map_grid.py).
Its small, discrete group-count range (1/2/3/5/8) reads more like a
per-resource language-variant count than a per-map object list (see
above), which argues against it being the door/warp table either, but
nothing has replaced it as a candidate this pass.

--------------------------------------------------------------------------
`a/0/6/6` reader search (this pass): no code found, per-language
hypothesis weakened
--------------------------------------------------------------------------
This pass looked for the reader by decimal-digit archive-id decoding:
`a/0/6/6` as decimal 66 is the immediate `0x42`, the same convention that
identified `a/1/2/5` as `0x7d` (125) and `a/1/2/6` as `0x7e` (126) next to
each other inside `func_0216237C` in ov010. Grepped archive-wide (ARM9
`main.s` and all 237 `asm/overlays/*.s` files) for the immediate `0x42`
(or decimal `66`) loaded into `r0`/`r1` within 20 lines ahead of a call to
any of the NARC-loader-family functions named in the mission
(`func_02048F60`, `func_02048F74`, `func_02048DDC`, `func_02048D00`,
`func_02048D54`, `func_02048F4C`, `func_02048F88`, `func_020490A8`,
`func_02049030`) or the generic loader `func_0204A1BC` that `a/0/5/7`'s
own reader uses (see scripts.py): **zero matches**. `0x42` does appear
very often elsewhere in the image (loop counts, buffer sizes, unrelated
immediates in overlays as far from the field system as the battle/menu
overlays ov093/ov094/ov119), but never immediately ahead of one of these
loader calls. This is a negative result from a real, archive-wide search,
not an absence of search.

The per-language hypothesis was tested two ways and both come back
against it:

- **Header language count**: no "number of languages" constant was
  found anywhere in the decompiled ARM9 code or `docs/` to check the
  group-count range {1, 2, 3, 5, 8} against; there is nothing attested
  to compare it to.
- **`a/0/0/2`'s own language structure**: `tools/assets/text.py` parses
  every one of `a/0/0/2`'s 288 sub-files with `sectionCount` always `1`
  (see text.py's module docstring, "Message-file container format") --
  the game's own confirmed text-bank archive carries no per-language
  grouping at all, single section on every sub-file, every sub-file
  sampled. If `a/0/6/6`'s `G in {1,2,3,5,8}` were a per-resource count of
  language variants, the one archive already proven to hold game text
  would be expected to show the same kind of grouping somewhere, and it
  does not. This does not disprove the hypothesis (the two archives could
  simply use different layouts for the same idea), but it removes the
  one piece of supporting analogy this pass could check.

Data hypotheses from the mission's fallback were also tested against the
zone header table (`tools/assets/zones.py`, 427 records): of the lanes
still without an attested accessor, only `field_02` (max 273) and
`field_18` (max 424) have a range that fits inside `a/0/6/6`'s 601
sub-files (or `a/0/0/3`'s 472-sub-file message-bank range) at all; every
other open lane's range is far too large (`field_14`, `field_20`: max
65535; `packed_1a`: max 1140; `packed_1c`: max 17984; `flags`: max
60736). That range fit is weak evidence on its own -- nearly any 16-bit
lane with a few hundred distinct small values would pass it -- and
neither lane has an accessor read in code that was found to treat it as
an `a/0/6/6` or `a/0/0/3` index, so this is reported as a plausibility
note, not a confirmed lane. **`a/0/6/6`'s role is still open.**

--------------------------------------------------------------------------
CLI
--------------------------------------------------------------------------
    python tools/assets/events.py --list [--archive {0003,0666,both}]
        Per-file record/group counts.

    python tools/assets/events.py --dump 0003 INDEX
    python tools/assets/events.py --dump 0666 INDEX
        Dump one sub-file as typed records (offset/field_x/length for
        0003; start/length for 0666).

    python tools/assets/events.py --groups N
        Dump `a/0/6/6` sub-file N's group records: group_count, the
        single repeated 14-fold header value per group, each group's
        start offset and size, and the first bytes of its payload.

    python tools/assets/events.py --verify [--archive {0003,0666,both}]
        Re-pack every sub-file from its parsed structure and compare
        byte-for-byte against the original. This is the acceptance bar
        for the framing above.

    python tools/assets/events.py --text N
        Decrypt and print every message in `a/0/0/3` sub-file N (its
        message-bank interpretation; see "Decoding records as text").
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402
import text  # noqa: E402 -- shares the cipher (rotl16) and renderer

A0003_PATH = os.path.join("extract", "data", "a", "0", "0", "3")
A0666_PATH = os.path.join("extract", "data", "a", "0", "6", "6")


class EventsError(Exception):
    pass


# ---------------------------------------------------------------------------
# a/0/0/3
# ---------------------------------------------------------------------------

def parse_0003(raw):
    """Parse one `a/0/0/3` sub-file. Returns a dict: tag, count, reserved,
    header_len, body_size, body_size_dup, entries (list of
    {record_offset, field_x, payload} dicts, payload relative to body
    start). Raises EventsError if any of the confirmed invariants (see
    module docstring) do not hold -- this module only claims to round-trip
    files that match the framing it was written against.
    """
    if len(raw) < 20:
        raise EventsError("sub-file too short for a/0/0/3 header")
    tag, count, body_size, reserved, header_len = struct.unpack_from(
        "<HHIII", raw, 0)
    if header_len != 16:
        raise EventsError(f"header_len {header_len} != 16")
    if body_size != len(raw) - 16:
        raise EventsError(
            f"body_size {body_size} != len(raw)-16 {len(raw) - 16}")
    body = raw[16:]
    if len(body) < 4 + 8 * count:
        raise EventsError("body too short for the declared record count")
    body_size_dup = struct.unpack_from("<I", body, 0)[0]
    if body_size_dup != body_size:
        raise EventsError(f"body_size_dup {body_size_dup} != {body_size}")

    raw_entries = struct.unpack_from("<%dI" % (count * 2), body, 4)
    offsets = raw_entries[0::2]
    xs = raw_entries[1::2]
    if list(offsets) != sorted(set(offsets)) or len(set(offsets)) != count:
        raise EventsError("record offsets not strictly increasing")
    if count and offsets[0] != 4 + 8 * count:
        raise EventsError("first record offset does not follow the table")

    entries = []
    for k in range(count):
        start = offsets[k]
        end = offsets[k + 1] if k + 1 < count else body_size
        if end < start or end > len(body):
            raise EventsError(f"record {k} span {start}..{end} out of range")
        entries.append({
            "record_offset": start,
            "field_x": xs[k],
            "payload": body[start:end],
        })

    return {
        "tag": tag,
        "count": count,
        "reserved": reserved,
        "header_len": header_len,
        "body_size": body_size,
        "entries": entries,
    }


def pack_0003(parsed):
    """Inverse of parse_0003: reconstruct the exact original bytes."""
    count = parsed["count"]
    header = struct.pack("<HHIII", parsed["tag"], count, parsed["body_size"],
                          parsed["reserved"], parsed["header_len"])
    table = bytearray()
    for e in parsed["entries"]:
        table += struct.pack("<II", e["record_offset"], e["field_x"])
    body = struct.pack("<I", parsed["body_size"]) + bytes(table)
    body += b"".join(e["payload"] for e in parsed["entries"])
    return header + body


# ---------------------------------------------------------------------------
# Decoding `a/0/0/3` records as text (message bank)
# ---------------------------------------------------------------------------
#
# Same cipher as a/0/0/2 (tools/assets/text.py): key = (index + 3) * 0x2983,
# rotate left 3 bits after every code unit, XOR each code unit with the
# (rotating) key. `index` is the record's own 0-based position inside its
# sub-file -- NOT a byte offset -- confirmed by decrypting sub-file 5's
# records 0-2 to "Ha ha ha", "My, my. My.", "I'm tired" (docs/ASSETS.md,
# "`a/0/0/3` is the text bank, and `field_x` is a length").
#
# `field_x & 0xFFFF` gives the record's length in u16 code units (confirmed
# 7861/7861 via the terminator check, see module docstring); this module
# decodes up to that many units, or until the raw payload runs out,
# whichever is shorter -- so an undersized payload degrades to a short
# (possibly unterminated) string rather than raising.

def decode_record(entry, rec_index):
    """Decrypt one a/0/0/3 record (an `entries[k]` dict from parse_0003).
    `rec_index` is the record's 0-based position inside its own sub-file
    (the cipher's `index`, not the same thing as record_offset). Returns
    the list of decoded code points (terminator included, if reached)."""
    length = entry["field_x"] & 0xFFFF
    payload = entry["payload"]
    key = (rec_index + 3) * 0x2983 & 0xFFFF
    out = []
    pos = 0
    for _ in range(length):
        if pos + 2 > len(payload):
            break
        w = struct.unpack_from("<H", payload, pos)[0]
        out.append(w ^ key)
        pos += 2
        key = text.rotl16(key, 3)
    return out


# ---------------------------------------------------------------------------
# a/0/6/6
# ---------------------------------------------------------------------------

SLOT_REPEAT = 14


def parse_0666(raw):
    """Parse one `a/0/6/6` sub-file. Returns a dict: group_count,
    header_len, groups (list of {start_offset, payload} dicts, payload
    is the raw group bytes). Raises EventsError if the confirmed
    invariants (see module docstring) do not hold.
    """
    if len(raw) < 4:
        raise EventsError("sub-file too short for a/0/6/6 header")
    group_count = struct.unpack_from("<I", raw, 0)[0]
    nslots = group_count * SLOT_REPEAT
    header_len = 4 + 4 * nslots
    if header_len > len(raw):
        raise EventsError(f"header_len {header_len} exceeds file size")
    slots = struct.unpack_from("<%dI" % nslots, raw, 4)

    group_starts = []
    for g in range(group_count):
        block = slots[g * SLOT_REPEAT:(g + 1) * SLOT_REPEAT]
        if len(set(block)) != 1:
            raise EventsError(f"group {g}'s {SLOT_REPEAT} slots are not identical")
        group_starts.append(block[0])

    if group_count and group_starts[0] != header_len:
        raise EventsError("first group does not start at header_len")
    if group_starts != sorted(set(group_starts)) or \
            len(set(group_starts)) != group_count:
        raise EventsError("group start offsets not strictly increasing")

    groups = []
    for g in range(group_count):
        start = group_starts[g]
        end = group_starts[g + 1] if g + 1 < group_count else len(raw)
        if end < start or end > len(raw):
            raise EventsError(f"group {g} span {start}..{end} out of range")
        groups.append({"start_offset": start, "payload": raw[start:end]})

    return {
        "group_count": group_count,
        "header_len": header_len,
        "groups": groups,
    }


def pack_0666(parsed):
    """Inverse of parse_0666: reconstruct the exact original bytes."""
    group_count = parsed["group_count"]
    slots = bytearray()
    for g in parsed["groups"]:
        word = struct.pack("<I", g["start_offset"])
        slots += word * SLOT_REPEAT
    out = struct.pack("<I", group_count) + bytes(slots)
    out += b"".join(g["payload"] for g in parsed["groups"])
    return out


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def _load(archive):
    path = A0003_PATH if archive == "0003" else A0666_PATH
    return narc.parse_file(path)


def cmd_list(args):
    archives = ["0003", "0666"] if args.archive == "both" else [args.archive]
    for archive in archives:
        n = _load(archive)
        parse_fn = parse_0003 if archive == "0003" else parse_0666
        key = "count" if archive == "0003" else "group_count"
        print(f"=== a/{'0/0/3' if archive == '0003' else '0/6/6'} "
              f"({n.file_count} sub-files) ===")
        for i in range(n.file_count):
            raw = n.read(i)
            try:
                parsed = parse_fn(raw)
                print(f"{i}\t{len(raw)}\t{parsed[key]}")
            except EventsError as exc:
                print(f"{i}\t{len(raw)}\tPARSE ERROR: {exc}")


def cmd_dump(args):
    archive, index = args.dump
    index = int(index)
    n = _load(archive)
    raw = n.read(index)
    if archive == "0003":
        parsed = parse_0003(raw)
        print(f"a/0/0/3#{index}: tag={parsed['tag']} count={parsed['count']} "
              f"body_size={parsed['body_size']}")
        for k, e in enumerate(parsed["entries"]):
            print(f"  [{k}] offset={e['record_offset']} "
                  f"field_x=0x{e['field_x']:08x} len={len(e['payload'])} "
                  f"payload[:16]={e['payload'][:16].hex()}")
    else:
        parsed = parse_0666(raw)
        print(f"a/0/6/6#{index}: group_count={parsed['group_count']} "
              f"header_len={parsed['header_len']}")
        for k, g in enumerate(parsed["groups"]):
            print(f"  [{k}] start={g['start_offset']} len={len(g['payload'])} "
                  f"payload[:16]={g['payload'][:16].hex()}")


def cmd_groups(args):
    n = _load("0666")
    raw = n.read(args.groups)
    parsed = parse_0666(raw)
    print(f"a/0/6/6#{args.groups}: group_count={parsed['group_count']} "
          f"header_len={parsed['header_len']} file_size={len(raw)}")
    for k, g in enumerate(parsed["groups"]):
        print(f"  group[{k}]: repeated_value(x14)={g['start_offset']} "
              f"size={len(g['payload'])} "
              f"payload[:16]={g['payload'][:16].hex()}")


def cmd_text(args):
    n = _load("0003")
    raw = n.read(args.text)
    parsed = parse_0003(raw)
    print(f"a/0/0/3#{args.text}: {parsed['count']} records")
    for k, e in enumerate(parsed["entries"]):
        plain = decode_record(e, k)
        terminated = bool(plain) and plain[-1] == text.TERMINATOR
        print(f"[{k}]\t{text.render(plain)}"
              f"{'' if terminated else '  <unterminated>'}")


def cmd_verify(args):
    archives = ["0003", "0666"] if args.archive == "both" else [args.archive]
    for archive in archives:
        n = _load(archive)
        parse_fn = parse_0003 if archive == "0003" else parse_0666
        pack_fn = pack_0003 if archive == "0003" else pack_0666
        ok = 0
        fail = 0
        for i in range(n.file_count):
            raw = n.read(i)
            try:
                parsed = parse_fn(raw)
                repacked = pack_fn(parsed)
            except EventsError as exc:
                print(f"a/{archive}#{i}: PARSE ERROR: {exc}")
                fail += 1
                continue
            if repacked == raw:
                ok += 1
            else:
                fail += 1
                print(f"a/{archive}#{i}: round-trip MISMATCH "
                      f"(orig {len(raw)}, repacked {len(repacked)})")
        label = "a/0/0/3" if archive == "0003" else "a/0/6/6"
        print(f"{label}: {ok}/{n.file_count} round-trip OK ({fail} failed)")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--archive", choices=["0003", "0666", "both"],
                     default="both")
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--list", action="store_true")
    g.add_argument("--dump", nargs=2, metavar=("ARCHIVE", "INDEX"))
    g.add_argument("--groups", type=int, metavar="N")
    g.add_argument("--verify", action="store_true")
    g.add_argument("--text", type=int, metavar="N")
    args = ap.parse_args(argv)

    if args.list:
        cmd_list(args)
    elif args.dump:
        cmd_dump(args)
    elif args.groups is not None:
        cmd_groups(args)
    elif args.verify:
        cmd_verify(args)
    elif args.text is not None:
        cmd_text(args)


if __name__ == "__main__":
    main()
