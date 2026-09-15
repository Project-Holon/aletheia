#!/usr/bin/env python3
"""
events.py -- container framing for `a/0/0/3` (472 sub-files) and `a/0/6/6`
(601 sub-files), the two variable-length NARCs flagged by an earlier asset
pass as the likely home of per-map door/warp/NPC/trigger records (see
docs/ASSETS.md, "Map attribute hunt" section, "(2) Separate per-zone NARC
search").

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
              u32  field_x         a genuine per-record field (not a
                                   coincidence: paired 1:1 with a real,
                                   verified offset), but its semantics are
                                   NOT confirmed this pass. Checked and
                                   ruled out: it is not record length
                                   (0/7861 pairs archive-wide satisfy
                                   field_x == next_offset - this_offset),
                                   and it is not a constant type tag (only
                                   163/472 files have every field_x share
                                   the same top 3 bytes). Its high-24-bit
                                   histogram is dominated by 0xE000
                                   (5576/7861) and 0x000000 (1096/7861)
                                   with a long tail of ~40 other values --
                                   consistent with a packed type+pointer
                                   or type+small-int word from the record's
                                   own bytecode, but that is a guess, not
                                   verified here.
    record[k] payload:  raw bytes from record_offset[k] to
                        record_offset[k+1] (or body_size for the last
                        record) -- variable length, bytecode-shaped (no
                        recognisable fixed sub-stride found), NOT decoded
                        by this module beyond byte-exact extraction.

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
Doors/warps: not confirmed this pass
--------------------------------------------------------------------------
Neither archive's sub-file count (472, 601) equals `a/0/0/8`'s 649 map
files, and this ROM has no usable BTNF names outside one unrelated NARC
(`a/2/3/2`, see docs/ASSETS.md's "BTNF name table results") and no
separate zone/map lookup table has been found anywhere in this archive
set, so there is no confirmed way to line up an `a/0/0/3` or `a/0/6/6`
index with a specific `a/0/0/8` map file and its walkable-tile grid
(tools/assets/map_grid.py). Without that alignment, the coordinate/
walkable cross-check this pass was asked to attempt cannot be performed
honestly -- reported here as a real gap, not skipped silently.
`a/0/0/3` remains the stronger of the two candidates for holding
door/warp/NPC/trigger data (bytecode-shaped variable records, no
language-count pattern, matches the earlier pass's guess), but which
record type within it is a door/warp specifically is still open.

--------------------------------------------------------------------------
CLI
--------------------------------------------------------------------------
    python tools/assets/events.py --list [--archive {0003,0666,both}]
        Per-file record/group counts.

    python tools/assets/events.py --dump 0003 INDEX
    python tools/assets/events.py --dump 0666 INDEX
        Dump one sub-file as typed records (offset/field_x/length for
        0003; start/length for 0666).

    python tools/assets/events.py --verify [--archive {0003,0666,both}]
        Re-pack every sub-file from its parsed structure and compare
        byte-for-byte against the original. This is the acceptance bar
        for the framing above.
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402

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
    g.add_argument("--verify", action="store_true")
    args = ap.parse_args(argv)

    if args.list:
        cmd_list(args)
    elif args.dump:
        cmd_dump(args)
    elif args.verify:
        cmd_verify(args)


if __name__ == "__main__":
    main()
