#!/usr/bin/env python3
"""
tables.py -- registry and round-trip checker for the large "custom format,
no decoder" table archives surveyed in this pass: a/0/5/7, a/1/9/4, a/1/7/8,
a/0/2/0, a/1/2/3, a/1/6/9, a/2/1/4, a/1/0/8, a/1/2/5, a/1/6/8, a/2/1/5.

Written from scratch for the aletheia asset lane. Stdlib only, depends
only on narc.py.

--------------------------------------------------------------------------
What this module actually knows, per archive
--------------------------------------------------------------------------
Two archives have a decompiled reader backing the framing (see docs/ASSETS.md,
"Large custom table pass" section, for the full address/file trail):

  a/1/2/3  -- per-species (650 sub-files, sub-file 0 empty) variable list:
              [u16 count][u16 move_id * count]. Reader: ov021 func_021C40F8
              (0x021C40F8), which calls func_02048F60(archive_id=0x7B, member=
              species_id, heap) and then linear-searches the returned array
              for a move id -- the egg-move-list shape.

  a/0/2/0  -- per-species (650 sub-files) single u16 field. Reader: ov021
              func_021C4504 (0x021C4504), which calls
              func_02048F74(dst, archive_id=0x14, member=species_id, mode=0,
              size_out) and returns the 2-byte result as a u16. Matches the
              "evolution-family/base-species index" value pattern icons.py
              already noted (runs of 2-4 identical consecutive values).

For the rest, no call site of func_02048F60/func_02048DDC/func_02048D00/
func_02048D54/func_02048F4C/func_02048F74/func_02048F88 in asm/arm9 or
asm/overlays loads that archive's id as an immediate register value ahead of
the call (checked by scripted backward-scan over every such call site found
in asm/arm9/main.s and asm/overlays/*.s) -- so their framing below is read
from the bytes alone:

  a/1/6/9  -- 951 sub-files, fixed 16-byte records. Five u16 fields (offsets
              0,2,4,6,8, each under ~512/768), two u8 fields (offsets 10,11,
              small ranges), one more u16 (offset 12), 2 zero pad bytes
              (14-15). Domain not identified.

  a/2/1/4  -- 1000 sub-files, fixed 16-byte records, the same field shape as
              a/1/6/9 one notch wider (high bytes reach 2 instead of 1).
              Domain not identified.

  a/1/0/8  -- 282 sub-files (281 real + 1 52-byte outlier), fixed 28-byte
              records: a 12-byte header (two u32 fields always 1, then three
              zero u32-worth of bytes) followed by four 4-byte blocks at
              offsets 12/16/20/24 (each: one wide-range byte, one narrower
              byte, two narrow/boolean bytes). Domain not identified.

  a/1/2/5  -- 428 sub-files (matches a/0/1/2's 427 zones + 1), variable size
              4..2178 bytes. Leads with a u32 whose value does not equal
              record_length minus a constant header size across samples
              (162 vs 172-8, 372 vs 392-8 do not agree on one header size),
              so this is read as an opaque per-zone blob, not decoded into
              fields.

  a/0/5/7  -- already identified and decompiled by a separate pass, see
              docs/ASSETS.md "Script virtual machine located and
              decompiled": this is the script-bytecode archive. Reader is
              ov010 func_02158D78 (loads archive id 0x39 = 57); a sub-file
              is a u32 entry-offset table terminated by the halfword
              0xFD13, code immediately after. 469/899 sub-files carry that
              table (2592 entry points decoded, 90.7% land cleanly on a
              flow-ending opcode or the next entry); the other 430 are 8-28
              byte side tables, not scripts, and remain unidentified. Kept
              opaque here (raw copy) since the bytecode decode itself lives
              in that doc section, not in a converter.

  a/1/9/4  -- 652 sub-files, fixed 4-byte records. Offsets 0-1 read as one
              u16 take only 5 distinct values across all 652 records (one
              value -- 10512 -- on 388/652, i.e. a heavily-skewed default);
              offset 2 is a separate byte with 17 values clustered 97-127.
              Domain not identified (a size-class-plus-scale-factor shape
              is plausible but unconfirmed).

  a/1/7/8  -- 649 sub-files (no sentinel -- one less than the usual 650),
              fixed 249-byte records, 181/249 byte offsets vary, all bounded
              under 128. Census's "text banks" guess does not hold up: text.py
              operates on u16 code-unit message files with a length-prefixed
              string table, and a/1/7/8 has neither shape. Read as an opaque
              blob.

  a/1/6/8  -- 315 sub-files. CONFIRMED exact framing: [u16 group_id]
              [u16 count][u16 member_id * count] (round-trips byte-identical
              by construction since the array is read back verbatim). 222/315
              records have len(members) == count; the other 93 have
              len(members) == count + 1, where the extra leading member
              equals the record's own group_id (a self-inclusive variant).
              Max member id seen: 950.

  a/2/1/5  -- 315 sub-files, the same [group_id][count][member_id*count]
              framing, 315/315 exact (no self-inclusive variant here). Max
              member id seen: 988.

              a/1/6/8's max member (950) sits just under a/1/6/9's 951
              records, and a/2/1/5's max member (988) sits just under
              a/2/1/4's 1000 records -- circumstantial but suggestive that
              a/1/6/8 indexes a/1/6/9 and a/2/1/5 indexes a/2/1/4. Not
              confirmed by any decompiled accessor.

--------------------------------------------------------------------------
Usage
--------------------------------------------------------------------------
    python tools/assets/tables.py --list ARCHIVE
    python tools/assets/tables.py --dump ARCHIVE N
    python tools/assets/tables.py --verify ARCHIVE
    python tools/assets/tables.py --stats ARCHIVE
    python tools/assets/tables.py --list-archives
"""

import argparse
import os
import struct
import sys
import collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)),
                                      "..", "..", "extract", "data", "a"))


# ---------------------------------------------------------------------------
# Per-archive decode/encode pairs. Each entry in REGISTRY is
#   path: relative path under extract/data/a
#   decode(data) -> record (any picklable-ish structure)
#   encode(record) -> bytes, must satisfy encode(decode(data)) == data
#   note: one-line description for --list-archives
# Archives with no confirmed field decoder keep decode/encode as the
# identity (raw bytes); the round trip still holds at the framing level.
# ---------------------------------------------------------------------------

def _identity_decode(data):
    return bytes(data)


def _identity_encode(record):
    return bytes(record)


def _decode_u16_count_array(data):
    """[u16 count][u16 value * count], no leading group id. Used by a/1/2/3."""
    if len(data) < 2:
        return {"raw": bytes(data)}
    count = struct.unpack_from("<H", data, 0)[0]
    need = 2 + 2 * count
    if need > len(data):
        return {"raw": bytes(data)}
    values = list(struct.unpack_from("<%dH" % count, data, 2))
    return {"count": count, "values": values, "trailer": bytes(data[need:])}


def _encode_u16_count_array(record):
    if "raw" in record:
        return record["raw"]
    body = struct.pack("<H", record["count"])
    body += struct.pack("<%dH" % len(record["values"]), *record["values"])
    body += record["trailer"]
    return body


def _decode_u16_single(data):
    """Single u16 field. Used by a/0/2/0."""
    if len(data) != 2:
        return {"raw": bytes(data)}
    return {"value": struct.unpack_from("<H", data, 0)[0]}


def _encode_u16_single(record):
    if "raw" in record:
        return record["raw"]
    return struct.pack("<H", record["value"])


def _decode_group_members(data):
    """[u16 group_id][u16 count][u16 member_id * count]. Used by a/1/6/8,
    a/2/1/5. `count` is kept as read even where the member array is one
    longer (the self-inclusive variant a/1/6/8 shows in 93/315 records);
    the extra member, if present, is kept in `members` so the encode is
    still exact."""
    if len(data) < 4:
        return {"raw": bytes(data)}
    group_id, count = struct.unpack_from("<HH", data, 0)
    n_members = (len(data) - 4) // 2
    if 4 + 2 * n_members != len(data):
        return {"raw": bytes(data)}
    members = list(struct.unpack_from("<%dH" % n_members, data, 4))
    return {"group_id": group_id, "count": count, "members": members}


def _encode_group_members(record):
    if "raw" in record:
        return record["raw"]
    body = struct.pack("<HH", record["group_id"], record["count"])
    body += struct.pack("<%dH" % len(record["members"]), *record["members"])
    return body


def _decode_fixed16(data):
    """Raw fixed 16-byte record, field split for --stats only (encode is
    the identity -- the field split is informational, not a re-encoding
    contract). Used by a/1/6/9, a/2/1/4."""
    if len(data) != 16:
        return {"raw": bytes(data)}
    u16s = struct.unpack_from("<5H", data, 0)
    b10, b11 = data[10], data[11]
    u16_12 = struct.unpack_from("<H", data, 12)[0]
    pad = data[14:16]
    return {"raw": bytes(data), "u16_0_8": u16s, "u8_10": b10, "u8_11": b11,
            "u16_12": u16_12, "pad_14": bytes(pad)}


def _decode_fixed28(data):
    """Raw fixed 28-byte record, field split for --stats only. Used by
    a/1/0/8 (the 52-byte outlier sub-file falls back to raw)."""
    if len(data) != 28:
        return {"raw": bytes(data)}
    h1, h2 = struct.unpack_from("<II", data, 0)
    h3 = struct.unpack_from("<I", data, 8)[0]
    blocks = []
    for off in (12, 16, 20, 24):
        blocks.append(tuple(data[off:off + 4]))
    return {"raw": bytes(data), "hdr1": h1, "hdr2": h2, "hdr3": h3,
            "blocks": blocks}


REGISTRY = {
    "a/1/2/3": {
        "path": "1/2/3",
        "decode": _decode_u16_count_array,
        "encode": _encode_u16_count_array,
        "note": "Egg-move list, per species. [u16 count][u16 move_id*count]. "
                "Reader: ov021 func_021C40F8 (0x021C40F8) via "
                "func_02048F60(archive_id=0x7B, member=species_id, heap).",
    },
    "a/0/2/0": {
        "path": "0/2/0",
        "decode": _decode_u16_single,
        "encode": _encode_u16_single,
        "note": "Per-species single u16 (evolution-family/base-species "
                "index, per icons.py). Reader: ov021 func_021C4504 "
                "(0x021C4504) via func_02048F74(dst, archive_id=0x14, "
                "member=species_id, mode=0, size_out).",
    },
    "a/1/6/9": {
        "path": "1/6/9",
        "decode": _decode_fixed16,
        "encode": lambda r: r["raw"],
        "note": "951 fixed 16-byte records: 5 u16 fields (0,2,4,6,8), 2 u8 "
                "fields (10,11), 1 u16 (12), 2 zero pad bytes (14-15). "
                "No reader found; domain not identified.",
    },
    "a/2/1/4": {
        "path": "2/1/4",
        "decode": _decode_fixed16,
        "encode": lambda r: r["raw"],
        "note": "1000 fixed 16-byte records, same shape as a/1/6/9 one "
                "notch wider. No reader found; domain not identified.",
    },
    "a/1/0/8": {
        "path": "1/0/8",
        "decode": _decode_fixed28,
        "encode": lambda r: r["raw"],
        "note": "282 sub-files (281 at 28 bytes, 1 outlier at 52 bytes): "
                "12-byte header (two u32=1, rest zero) + four 4-byte blocks "
                "at 12/16/20/24. No reader found; domain not identified.",
    },
    "a/1/2/5": {
        "path": "1/2/5",
        "decode": _identity_decode,
        "encode": _identity_encode,
        "note": "428 sub-files (427 zones + 1), variable 4..2178 bytes. "
                "Leading u32 does not resolve to one consistent header "
                "size across samples; kept opaque.",
    },
    "a/1/6/8": {
        "path": "1/6/8",
        "decode": _decode_group_members,
        "encode": _encode_group_members,
        "note": "315 sub-files. [u16 group_id][u16 count][u16 member*count], "
                "confirmed exact. 93/315 records carry one extra leading "
                "member equal to their own group_id. Max member id 950 "
                "(just under a/1/6/9's 951 records).",
    },
    "a/2/1/5": {
        "path": "2/1/5",
        "decode": _decode_group_members,
        "encode": _encode_group_members,
        "note": "315 sub-files, same group/count/members framing as "
                "a/1/6/8, 315/315 exact (no self-inclusive variant). Max "
                "member id 988 (just under a/2/1/4's 1000 records).",
    },
    "a/0/5/7": {
        "path": "0/5/7",
        "decode": _identity_decode,
        "encode": _identity_encode,
        "note": "Script-bytecode archive (see docs/ASSETS.md, 'Script "
                "virtual machine located and decompiled'). Reader: ov010 "
                "func_02158D78, archive id 0x39=57. Sub-file = u32 offset "
                "table terminated by halfword 0xFD13, code after it "
                "(469/899 sub-files); the other 430 are small side tables. "
                "Kept opaque here, raw copy only.",
    },
    "a/1/9/4": {
        "path": "1/9/4",
        "decode": _identity_decode,
        "encode": _identity_encode,
        "note": "652 fixed 4-byte records. Offsets 0-1 as a u16 take only "
                "5 distinct values (one on 388/652); offset 2 a separate "
                "byte clustered 97-127. Domain not identified.",
    },
    "a/1/7/8": {
        "path": "1/7/8",
        "decode": _identity_decode,
        "encode": _identity_encode,
        "note": "649 sub-files (no sentinel), fixed 249-byte records, "
                "181/249 offsets vary, all bounded under 128. Kept opaque; "
                "not a text.py message-file shape.",
    },
}


def _open(tag):
    entry = REGISTRY[tag]
    path = os.path.join(ROOT, entry["path"])
    return narc.parse_file(path), entry


def cmd_list(tag):
    n, entry = _open(tag)
    print(f"{tag}: {n.file_count} sub-files")
    print(f"  {entry['note']}")


def cmd_list_archives():
    for tag in REGISTRY:
        print(tag)


def cmd_dump(tag, index):
    n, entry = _open(tag)
    data = n.read(index)
    record = entry["decode"](data)
    print(f"{tag} sub-file {index}: {len(data)} bytes")
    print(f"  raw: {data.hex()}")
    if isinstance(record, dict) and "raw" not in record:
        print(f"  decoded: {record}")
    elif isinstance(record, dict):
        shown = {k: v for k, v in record.items() if k != "raw"}
        if shown:
            print(f"  decoded (partial): {shown}")
        else:
            print("  decoded: (opaque, no field split)")


def cmd_verify(tag):
    n, entry = _open(tag)
    decode, encode = entry["decode"], entry["encode"]
    ok = 0
    fail = 0
    fail_examples = []
    for sf in n.subfiles:
        data = n.read(sf.index)
        record = decode(data)
        try:
            back = encode(record)
        except Exception as exc:
            back = None
        if back == data:
            ok += 1
        else:
            fail += 1
            if len(fail_examples) < 5:
                fail_examples.append(sf.index)
    total = n.file_count
    print(f"{tag}: round trip {ok}/{total} byte-identical")
    if fail:
        print(f"  {fail} failures, first indices: {fail_examples}")


def cmd_stats(tag):
    n, entry = _open(tag)
    sizes = collections.Counter()
    for sf in n.subfiles:
        sizes[sf.size] += 1
    print(f"{tag}: {n.file_count} sub-files")
    print("size histogram (size:count), most common first:")
    for size, count in sizes.most_common(20):
        print(f"  {size}: {count}")
    print(f"min size {min(sizes)} max size {max(sizes)}")

    # Per-offset u8 histograms over the dominant fixed size, if one exists.
    dominant_size, dom_count = sizes.most_common(1)[0]
    if dom_count < 2 or dominant_size == 0:
        return
    recs = [n.read(sf.index) for sf in n.subfiles if sf.size == dominant_size]
    if len(recs) < 4:
        return
    print(f"\nper-offset u8 histogram over the {dom_count} "
          f"{dominant_size}-byte sub-files:")
    for off in range(min(dominant_size, 64)):
        vals = [r[off] for r in recs]
        c = collections.Counter(vals)
        print(f"  off {off:3d}  min={min(vals):3d} max={max(vals):3d} "
              f"nunique={len(c):4d}")
    if dominant_size > 64:
        print(f"  ... ({dominant_size - 64} more offsets not shown)")


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--list", metavar="ARCHIVE")
    p.add_argument("--dump", nargs=2, metavar=("ARCHIVE", "N"))
    p.add_argument("--verify", metavar="ARCHIVE")
    p.add_argument("--stats", metavar="ARCHIVE")
    p.add_argument("--list-archives", action="store_true")
    args = p.parse_args(argv)

    if args.list_archives:
        cmd_list_archives()
    elif args.list:
        cmd_list(args.list)
    elif args.dump:
        cmd_dump(args.dump[0], int(args.dump[1]))
    elif args.verify:
        cmd_verify(args.verify)
    elif args.stats:
        cmd_stats(args.stats)
    else:
        p.print_help()
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
