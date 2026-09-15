#!/usr/bin/env python3
"""
tables.py -- registry and round-trip checker for the "custom format, no
decoder" census bucket. First pass (see docs/ASSETS.md "Large custom table
pass"): a/0/5/7, a/1/9/4, a/1/7/8, a/0/2/0, a/1/2/3, a/1/6/9, a/2/1/4,
a/1/0/8, a/1/2/5, a/1/6/8, a/2/1/5. Second pass, the rest of that census
bucket (see "Group 2 custom table pass"): 75 more archives, registered in
_GROUP2 near the end of this file.

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


# ---------------------------------------------------------------------------
# Group 2 custom table pass: the rest of the census "custom format, no
# decoder" bucket not already in REGISTRY above (75 archives; two more
# census rows in this bucket, dwc/utility.bin and gfl_font.dat, are single
# raw files with no BTAF/BTNF/GMIF container and cannot go through
# narc.parse_file, so they are not in this registry; see docs/ASSETS.md).
#
# None of these 75 resolved to a confirmed field layout worth a dedicated
# encoder, so they are kept as raw per-sub-file copies (decode/encode =
# identity, which trivially round-trips byte-identical). Six did turn up a
# confirmed reader from the same scripted backward-scan used for the pass
# above (an immediate archive-id load ahead of a call to one of the seven
# accessor functions, across asm/arm9/main.s and every asm/overlays/*.s):
# a/0/4/8, a/0/8/7, a/0/9/1, a/1/3/2, a/1/4/6, a/1/4/7 -- see each entry's
# note below and docs/ASSETS.md "Group 2 custom table pass" for the call
# site address and the backward-scan method. Framing, per-offset histogram
# summary and identification/confidence for every archive are also in that
# doc section; the note below is the short form.
# ---------------------------------------------------------------------------

_GROUP2 = {
    "a/0/1/0": ("0/1/0", "Single sub-file, 752 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/0/1/5": ("0/1/5", "5 sub-files, fixed 16-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/0/1/7": ("0/1/7", "8 sub-files, fixed 404-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/0/3/6": ("0/3/6", "14 sub-files, variable 68..19320 bytes (dominant size 552 bytes on 2/14). No reader found among the seven accessor functions for this archive id. Identification: LZ11-compressed generic NITRO chunks: decompresses to RGCN/RCSN (NCGR/NCLR family, tile+palette). Confidence: HIGH (magic recovered after decompression)."),
    "a/0/3/7": ("0/3/7", "Single sub-file, 5376 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/0/3/8": ("0/3/8", "Single sub-file, 576 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/0/3/9": ("0/3/9", "18 sub-files, variable 80..4916 bytes (dominant size 552 bytes on 3/18). No reader found among the seven accessor functions for this archive id. Identification: LZ11-compressed generic NITRO chunks: decompresses to RGCN/RCSN, same family as a/0/3/6. Confidence: HIGH (magic recovered after decompression)."),
    "a/0/4/2": ("0/4/2", "Single sub-file, 1440 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/0/4/7": ("0/4/7", "80 sub-files, variable 64..65352 bytes (dominant size 552 bytes on 6/80). No reader found among the seven accessor functions for this archive id. Identification: Uncompressed mix of RGCN/RLCN (NCGR/NCLR) and BMD0/BTX0 (3D model/texture) sub-files. Confidence: MEDIUM-HIGH (direct magics, but a minority of the 80 sub-files, rest opaque)."),
    "a/0/4/8": ("0/4/8", "Single sub-file, 22376 bytes, opaque blob. Reader: arm9 func_0202A128 (0x0202A128) via func_02048F60(archive_id=0x30=48, member, heap); the same function also loads a/2/1/1 (archive id 0xd3=211) via func_0204A298 just before it, for the same member index. Identification: domain not identified despite the confirmed reader above. Confidence: LOW (reader confirmed, field semantics not decoded)."),
    "a/0/5/3": ("0/5/3", "19 sub-files, variable 28..1410 bytes (dominant size 92 bytes on 3/19). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/0/5/8": ("0/5/8", "17 sub-files, variable 4..784 bytes (dominant size 784 bytes on 4/17). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/0/6/0": ("0/6/0", "Single sub-file, 1672 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/0/6/1": ("0/6/1", "56 sub-files, fixed 780-byte records. No reader found among the seven accessor functions for this archive id. Identification: 780-byte records resolve into 15 repeated 52-byte sub-blocks (period confirmed by per-offset histogram). Confidence: MEDIUM (structural only, domain unclear)."),
    "a/0/6/2": ("0/6/2", "10 sub-files, fixed 780-byte records. No reader found among the seven accessor functions for this archive id. Identification: Same 15x52-byte sub-block period as a/0/6/1. Confidence: MEDIUM (structural only, domain unclear)."),
    "a/0/6/7": ("0/6/7", "98 sub-files, variable 68..5596 bytes (dominant size 244 bytes on 8/98). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/0/7/0": ("0/7/0", "6 sub-files, variable 640..6412 bytes (dominant size 3588 bytes on 1/6). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/0/7/9": ("0/7/9", "34 sub-files, variable 256..24420 bytes (dominant size 764 bytes on 2/34). No reader found among the seven accessor functions for this archive id. Identification: Most sub-files begin with the RLCN (NCLR palette) chunk tag uncompressed. Confidence: MEDIUM-HIGH (partial magic match, not exhaustively checked)."),
    "a/0/8/0": ("0/8/0", "Single sub-file, 72 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/0/8/1": ("0/8/1", "14 sub-files, variable 8..104 bytes (dominant size 8 bytes on 13/14). No reader found among the seven accessor functions for this archive id. Identification: 13/14 sub-files are 8 bytes: [u32 value close to 0x7fxx][u32 small count 0..10]; 1 outlier at 104 bytes. Confidence: LOW (framing only; a trig/scale-table guess is unconfirmed)."),
    "a/0/8/2": ("0/8/2", "2 sub-files, variable 0..780 bytes (dominant size 780 bytes on 1/2). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/0/8/6": ("0/8/6", "Single sub-file, 3294 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/0/8/7": ("0/8/7", "Single sub-file, 106 bytes, opaque blob. Reader: arm9 func_02006EA4 (0x02006EA4) via func_02048F74(dst, archive_id=0x57=87, member=0, mode=0, size_out), single sub-file (member is always 0). Identification: domain not identified despite the confirmed reader above. Confidence: LOW (reader confirmed, field semantics not decoded)."),
    "a/0/9/0": ("0/9/0", "Single sub-file, 7048 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/0/9/1": ("0/9/1", "Single sub-file, 1232 bytes, opaque blob. Reader: arm9 func_0202A298 and func_0202A310 (0x0202A298/0x0202A310) via func_02048F74(dst, archive_id=0x5b=91, member=0, mode=variable); both functions first search a table in a/0/9/0 (archive id 0x5a=90, via func_020490A8/func_020490F4) then read a/0/9/1 with the matched mode -- the two archives are used as a pair. Identification: domain not identified despite the confirmed reader above. Confidence: LOW (reader confirmed, field semantics not decoded)."),
    "a/0/9/7": ("0/9/7", "2 sub-files, variable 274..24888 bytes (dominant size 24888 bytes on 1/2). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/0/9/8": ("0/9/8", "10 sub-files, variable 650..1454 bytes (dominant size 1450 bytes on 4/10). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/0/9/9": ("0/9/9", "17 sub-files, variable 95..4568 bytes (dominant size 552 bytes on 2/17). No reader found among the seven accessor functions for this archive id. Identification: LZ77-compressed generic NITRO chunks: decompresses to RGCN/RCSN. Confidence: HIGH (magic recovered after decompression)."),
    "a/1/0/1": ("1/0/1", "Single sub-file, 672 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/1/0/5": ("1/0/5", "29 sub-files, fixed 188-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/1/0/9": ("1/0/9", "17 sub-files, fixed 4-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/1/1/1": ("1/1/1", "6 sub-files, variable 76..8260 bytes (dominant size 276 bytes on 1/6). No reader found among the seven accessor functions for this archive id. Identification: Nitro sound pair: sub-files include SBNK (sound bank) and SSEQ (sequence) chunks alongside raw PCM-ish blocks. Confidence: HIGH (standard chunk magics)."),
    "a/1/1/2": ("1/1/2", "6 sub-files, variable 76..8260 bytes (dominant size 276 bytes on 1/6). No reader found among the seven accessor functions for this archive id. Identification: Nitro sound pair: SBNK/SSEQ chunks present, same family as a/1/1/1. Confidence: HIGH (standard chunk magics)."),
    "a/1/1/3": ("1/1/3", "6 sub-files, variable 80..8260 bytes (dominant size 276 bytes on 1/6). No reader found among the seven accessor functions for this archive id. Identification: Nitro sound pair: SBNK/SSEQ chunks present, same family as a/1/1/1. Confidence: HIGH (standard chunk magics)."),
    "a/1/1/4": ("1/1/4", "6 sub-files, variable 92..8260 bytes (dominant size 276 bytes on 1/6). No reader found among the seven accessor functions for this archive id. Identification: Nitro sound pair: SBNK/SSEQ chunks present, same family as a/1/1/1. Confidence: HIGH (standard chunk magics)."),
    "a/1/1/7": ("1/1/7", "53 sub-files, fixed 36-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/1/1/9": ("1/1/9", "9 sub-files, variable 2..158 bytes (dominant size 134 bytes on 3/9). No reader found among the seven accessor functions for this archive id. Identification: One variant is a flat ascending u16 sequence (65,66,67,...); looks like a plain index/char table. Confidence: LOW (framing only)."),
    "a/1/2/1": ("1/2/1", "23 sub-files, variable 400..10476 bytes (dominant size 968 bytes on 8/23). No reader found among the seven accessor functions for this archive id. Identification: BMD0 (3D model) plus BCA0 (joint animation) and BMA0 (material animation) -- a model+animation set. Confidence: HIGH (standard G3D chunk magics)."),
    "a/1/2/7": ("1/2/7", "7 sub-files, variable 8..46976 bytes (dominant size 8 bytes on 4/7). No reader found among the seven accessor functions for this archive id. Identification: One of 7 sub-files is BMD0 (3D model); the rest are small opaque blocks. Confidence: LOW-MEDIUM (1/7 sub-files only)."),
    "a/1/3/2": ("1/3/2", "5 sub-files, fixed 40-byte records. Reader: arm9 func_0202AEEC (0x0202AEEC) via func_02048F88(archive_id=0x84=132, member, heap, mode=0, size=40), member taken from the caller's own second argument. Identification: domain not identified despite the confirmed reader above. Confidence: LOW (reader confirmed, field semantics not decoded)."),
    "a/1/3/6": ("1/3/6", "31 sub-files, fixed 8-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/1/4/6": ("1/4/6", "10 sub-files, fixed 28-byte records. Reader: an arm9 function around 0x0202B2xx (enclosing the call site at 0x0202B34C) first calls func_02049030(archive_id=0x92=146) for a record count, then loops member 0..count-1 through func_02048F74(dst, archive_id=0x92=146, member, mode=0) into consecutive 28-byte slots -- matches the 10 fixed 28-byte sub-files found by the byte survey. Identification: domain not identified despite the confirmed reader above. Confidence: LOW (reader confirmed, field semantics not decoded)."),
    "a/1/4/7": ("1/4/7", "3 sub-files, variable 27..43 bytes (dominant size 27 bytes on 1/3). Reader: arm9 func_0202C3E0 (0x0202C3E0) via a sequence of func_02048F74(dst, archive_id=0x93=147, member, mode=running_offset) calls (4 bytes, then 9x2 bytes, then two more variable chunks) that assemble one member's record piece by piece -- consistent with the variable 27/41/43-byte sizes found by the byte survey, read as a length-driven structure rather than one flat read. Identification: domain not identified despite the confirmed reader above. Confidence: LOW (reader confirmed, field semantics not decoded)."),
    "a/1/4/8": ("1/4/8", "18 sub-files, variable 8..28808 bytes (dominant size 8 bytes on 8/18). No reader found among the seven accessor functions for this archive id. Identification: 3 of 18 sub-files are BMD0 (3D model); the rest are opaque blocks 8..28808 bytes. Confidence: LOW-MEDIUM (minority of sub-files)."),
    "a/1/4/9": ("1/4/9", "Single sub-file, 32 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/1/5/2": ("1/5/2", "3 sub-files, variable 684..1700 bytes (dominant size 684 bytes on 1/3). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/1/5/4": ("1/5/4", "37 sub-files, variable 0..1024 bytes (dominant size 48 bytes on 30/37). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/1/5/6": ("1/5/6", "46 sub-files, variable 3100..6172 bytes (dominant size 3100 bytes on 44/46). No reader found among the seven accessor functions for this archive id. Identification: 44/46 sub-files are a fixed 3100 bytes; 2 outliers sit near double that (6172 bytes). Confidence: LOW (structural only, domain unclear)."),
    "a/1/5/8": ("1/5/8", "5 sub-files, variable 72..432 bytes (dominant size 144 bytes on 2/5). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/1/6/3": ("1/6/3", "7 sub-files, fixed 44-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/1/6/5": ("1/6/5", "13 sub-files, fixed 108-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/1/6/6": ("1/6/6", "9 sub-files, fixed 36-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/1/7/1": ("1/7/1", "14 sub-files, variable 12..23988 bytes (dominant size 9120 bytes on 1/14). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/1/7/4": ("1/7/4", "24 sub-files, fixed 124-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/1/7/5": ("1/7/5", "2 sub-files, fixed 36-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/1/7/9": ("1/7/9", "50 sub-files, fixed 64-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/1/8/5": ("1/8/5", "2 sub-files, fixed 8-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/1/8/6": ("1/8/6", "7 sub-files, variable 20..80 bytes (dominant size 50 bytes on 5/7). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/1/9/8": ("1/9/8", "Single sub-file, 255 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: LZ77-compressed, decompresses to RGCN (NCGR tile data). Confidence: HIGH (magic recovered after decompression)."),
    "a/2/0/3": ("2/0/3", "4 sub-files, variable 1448..4328 bytes (dominant size 4328 bytes on 1/4). No reader found among the seven accessor functions for this archive id. Identification: 1 of 4 sub-files is Huffman8-compressed; no recognised magic on any sub-file. Confidence: LOW (partial compression only)."),
    "a/2/0/8": ("2/0/8", "4 sub-files, variable 8..664 bytes (dominant size 664 bytes on 1/4). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/2/0/9": ("2/0/9", "Single sub-file, 856 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/2/1/1": ("2/1/1", "Single sub-file, 4528 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/2/1/2": ("2/1/2", "2 sub-files, variable 13964..20674 bytes (dominant size 20674 bytes on 1/2). No reader found among the seven accessor functions for this archive id. Identification: Both sub-files are RIFF/WAVE (raw PCM audio clips). Confidence: HIGH (RIFF/WAVE magic)."),
    "a/2/2/0": ("2/2/0", "13 sub-files, variable 280..253428 bytes (dominant size 552 bytes on 2/13). No reader found among the seven accessor functions for this archive id. Identification: Mix of RLCN/RCSN (NCLR/NCGR) and BMD0/BCA0 (model + joint animation) sub-files. Confidence: MEDIUM-HIGH (direct magics on several sub-files)."),
    "a/2/2/1": ("2/2/1", "7 sub-files, variable 2304..5504 bytes (dominant size 2496 bytes on 1/7). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/2/2/4": ("2/2/4", "4 sub-files, fixed 36-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/2/2/5": ("2/2/5", "151 sub-files, variable 15..39547 bytes (dominant size 2687 bytes on 12/151). No reader found among the seven accessor functions for this archive id. Identification: Every sub-file is LZ11-compressed; decompressed content has no recognised NITRO chunk magic. Confidence: LOW (compression confirmed, content unresolved)."),
    "a/2/2/6": ("2/2/6", "174 sub-files, variable 15..43305 bytes (dominant size 15 bytes on 12/174). No reader found among the seven accessor functions for this archive id. Identification: Every sub-file is LZ11-compressed; decompressed content has no recognised NITRO chunk magic, same family as a/2/2/5. Confidence: LOW (compression confirmed, content unresolved)."),
    "a/2/2/7": ("2/2/7", "Single sub-file, 494 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified)."),
    "a/2/2/9": ("2/2/9", "52 sub-files, variable 49812..209740 bytes (dominant size 49812 bytes on 7/52). No reader found among the seven accessor functions for this archive id. Identification: Each sub-file opens with an 'AB' 2-byte tag plus a u16 header-size field then a u32 offset table; large sizes (49812..209740 bytes) suggest an audio/stream container (domain guess, not confirmed). Confidence: LOW-MEDIUM (framing pattern only)."),
    "a/2/3/0": ("2/3/0", "64 sub-files, variable 58684..189924 bytes (dominant size 58684 bytes on 32/64). No reader found among the seven accessor functions for this archive id. Identification: Same 'AB'-tagged header-plus-offset-table framing as a/2/2/9, large sizes (58684..189924 bytes). Confidence: LOW-MEDIUM (framing pattern only)."),
    "a/2/3/1": ("2/3/1", "73 sub-files, variable 11653..30624 bytes (dominant size 13905 bytes on 1/73). No reader found among the seven accessor functions for this archive id. Identification: Every sub-file is LZ77-compressed; decompressed content has no recognised NITRO chunk magic. Confidence: LOW (compression confirmed, content unresolved)."),
    "a/2/3/2": ("2/3/2", "Single sub-file, 627 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: BTNF-named sub-file 0 is 'battle_pocket.dat'. Confidence: HIGH (BTNF name)."),
    "a/2/3/3": ("2/3/3", "2 sub-files, variable 86..99 bytes (dominant size 86 bytes on 1/2). No reader found among the seven accessor functions for this archive id. Identification: LZ77-compressed, decompresses to RGCN (NCGR tile data) on both sub-files. Confidence: HIGH (magic recovered after decompression)."),
}

for _tag, (_path, _note) in _GROUP2.items():
    REGISTRY[_tag] = {
        "path": _path,
        "decode": _identity_decode,
        "encode": _identity_encode,
        "note": _note,
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
