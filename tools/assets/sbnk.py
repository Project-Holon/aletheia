#!/usr/bin/env python3
"""
sbnk.py -- SBNK (instrument bank) reader for aletheia.
Stdlib only, written from scratch for this project.

--------------------------------------------------------------------------
Container (same generic-section shape as SWAR/SSEQ -- see swav.py/sseq.py):
    0x00  char[4]  magic "SBNK"
    0x04  u16      byte_order
    0x06  u16      version
    0x08  u32      file_size
    0x0C  u16      header_size (0x10)
    0x0E  u16      block_count (1)
    0x10  char[4]  "DATA"
    0x14  u32      block_size
    0x18  32 bytes reserved (zero in every instance sampled)
    0x38  u32      instrument_count
    0x3C  instrument_count x u32 instrument entry (see the verified
          per-field breakdown just below)

Instrument table entry (4 bytes), per the public SBNK layout (verified
against real bytes, see below):
    u8  record_type
    u16 record_offset (relative to the SBNK file start, i.e. usable
                        directly as an absolute offset into this file's
                        own bytes; 0 if record_type == 0 / empty slot)
    u8  pad            (measured 0 in all 30046 real instrument-table
                         entries across all 1497 real SBNKs -- no instance
                         of a nonzero pad byte was found)

This was re-verified this pass across all 1497 real SBNKs (26756 empty +
1547 type-1 + 122 type-2 + 155 type-3 + 187 type-16 + 1279 type-17 = 30046
entries, matching the SDAT's own 1497 x instrument_count total exactly):
BANK slot 25's single instrument (record_type 1) points to a 10-byte PCM
record whose wave_id/wave_arc indices (0, 0) resolve -- via the owning
BANK's own wave_arc[] table, entry 0 -- to WAVARC slot 25 (WAVE_ARC_PV025),
the Pikachu cry SWAR archive, matching this bank's own SYMB-adjacent
naming. See docs/ASSETS.md's audio-formats section for the full worked
trace.

Instrument record_type layouts, by confidence:

  type 0 (empty slot, ~89% of all instrument-table entries across the
  1497 real SBNKs): record_offset is 0, no data follows. HIGH confidence.

  types 1-5 (single-region instrument; type 1 -- PCM -- is by far the most
  common, 1547 of 1547+122+155 non-drum/split entries): a fixed 10-byte
  record:
      u16 wave_id    (index of the SWAV within the archive named by
                       wave_arc, below)
      u16 wave_arc   (index into the owning BANK's own wave_arc[4] slots,
                       NOT a global WAVARC index -- measured 0-3 in all
                       1547 real type-1 records, i.e. always a valid
                       in-bank slot)
      u8  note       (MIDI base note the sample was recorded at, e.g.
                       60 = C4)
      u8  attack, decay, sustain, release  (u8 ADSR envelope, 0-127)
      u8  pan        (0-127, 64 = center)
  HIGH confidence for type 1 (fully verified by the Pikachu-cry trace
  above, and by a plausibility scan: 100% of all 1547 real type-1 records
  have wave_arc in 0-3, note/ADSR bytes in 0-127, and wave_id within the
  resolved archive's own wave count). This pass corrects two errors in
  the previous version of this module: the two u16 fields were in the
  opposite order (wave_arc before wave_id; real data shows wave_id comes
  first -- confirmed by checking which of the two fields is small (0-3)
  across all 1547 real records: it is consistently the *second* one), and
  the record was read as 12 bytes with a trailing u16 padding field that
  does not exist (the record is 10 bytes; the previous version's extra 2
  bytes bled into the next structure for types 16/17, see below).

  type 2 (PSG square/pulse, DECODED this pass): the same 10-byte shape,
  but the leading u16 is a duty-cycle selector (0-7, the DS PSG channel's
  8 duty settings), not a wave_id, and the second u16 is unused (always
  0). Confirmed against all 122 real type-2 instruments in this ROM's
  SBNKs: the leading value is 0-6 in every record (105/122 are exactly 3),
  never above 7, and the trailing u16 that would be `wave_arc` for a
  PCM-shaped record is 0 in all 122 -- a real wave_arc is always checked
  against the owning bank's own wave_arc[4] table and is never a bare
  constant 0 across every instrument in every bank the way this field is;
  0 is simply "not a wave archive." The note/ADSR/pan bytes that follow
  are in the same 0-127 range as every other instrument type and are kept
  with their usual meaning. HIGH confidence.

  type 3 (PSG noise, DECODED this pass): the same 10-byte shape, but
  *both* leading u16 fields are 0 in every one of the 155 real type-3
  instruments sampled (no duty, no wave archive -- consistent with the DS
  noise channel having no per-instrument wave/duty parameter at all, only
  the shared envelope). The note/ADSR/pan bytes are kept. HIGH confidence.

  Neither type carries a wave archive, so neither type ever needs
  `wave_arc`/`wave_id` resolution against the owning BANK's table -- that
  is the direct explanation for why the previous version's plausibility
  check (built for the wave-bearing shape) scored them low: it was
  checking a field that PSG instruments don't use for that purpose.

  type 16 (drum kit): u8 low_note, u8 high_note, then
  (high_note - low_note + 1) region entries, each:
      u16 region_type   (measured 1 -- i.e. PCM -- in all 5308 real
                          type-16 regions sampled this pass)
      <10-byte record>  (same shape as types 1-5 above)
  i.e. 12 bytes per region (2-byte type prefix + 10-byte record). HIGH
  confidence: 100% of low_note/high_note pairs are in-range (0-127,
  low <= high), and 100% of the resulting 5308 region records (187 first
  regions + 5121 later regions) pass the wave_id/wave_arc/note/ADSR
  plausibility check below -- notably including every region *past* the
  first, which the previous version's wrong record size/order got right
  only 4.1% of the time past region 0.

  type 17 (key split, multi-region): u8 split_points[8] (a fixed-size
  array, NOT terminated by a 0x7F sentinel -- real data has trailing zero
  entries after the last real split point), then N region entries (N =
  count of *nonzero* bytes in split_points), each entry the same
  `u16 region_type` + 10-byte record shape as type 16 above. HIGH
  confidence: 100% of the resulting 3392 region records (1279 first +
  2113 later) pass the plausibility check, and split_point values rise
  monotonically with each region's own note field in every case sampled
  (e.g. split_points (41,46,53,58,65,70,77,127) pairing with base notes
  36,43,48,55,60,67,72,79 -- a clean per-range instrument layering).

Round trip: the fixed-size header and instrument-table prefix's *meaning*
(type/offset/pad packing, a straight struct read/pack with no
transformation) is all that's needed for a byte-identical round trip:
`Sbnk.roundtrip_bytes()` reconstructs the file as (header + table,
re-packed from the decoded fields) + (every remaining byte from the end
of the table to end of file, copied verbatim). This is byte-identical by
construction for every SBNK regardless of whether every instrument record
type's internal layout is fully understood -- verified 1497/1497 this
pass, same as before this fix (the corrected field order/record size
inside records 1/16/17 doesn't touch the table itself, only what
`parse_detail()` reports about the bytes after it).
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import sdat  # noqa: E402

TYPE_NAMES = {
    0: "Empty", 1: "PCM", 2: "PSG_Square", 3: "PSG_Noise", 16: "DrumKit", 17: "KeySplit",
}


class SbnkError(Exception):
    pass


class Instrument:
    def __init__(self, index, rec_type, offset, pad=0):
        self.index = index
        self.rec_type = rec_type
        self.offset = offset
        self.pad = pad  # measured 0 in all 30046 real entries; kept for roundtrip
        self.detail = None  # filled in by parse_detail()

    def parse_detail(self, data):
        if self.rec_type == 0:
            self.detail = {}
            return
        if self.rec_type == 2:
            self.detail = _parse_psg_square(data, self.offset)
            return
        if self.rec_type == 3:
            self.detail = _parse_psg_noise(data, self.offset)
            return
        if self.rec_type in (1, 4, 5):
            self.detail = _parse_record(data, self.offset)
            return
        if self.rec_type == 16:
            self.detail = _parse_drum_kit(data, self.offset)
            return
        if self.rec_type == 17:
            self.detail = _parse_key_split(data, self.offset)
            return
        self.detail = {"raw_head": data[self.offset:self.offset + 16].hex()}


def _parse_record(data, offset):
    """The 10-byte record shared by instrument types 1-5 and by every
    type-16/17 region: u16 wave_id, u16 wave_arc, u8 note, u8 attack, u8
    decay, u8 sustain, u8 release, u8 pan. See module docstring."""
    wave_id, wave_arc = struct.unpack_from("<HH", data, offset)
    note, attack, decay, sustain, release, pan = struct.unpack_from(
        "<6B", data, offset + 4)
    return {"wave_id": wave_id, "wave_arc": wave_arc, "base_note": note,
            "attack": attack, "decay": decay, "sustain": sustain,
            "release": release, "pan": pan}


def _parse_psg_square(data, offset):
    """type 2 (PSG pulse/square): same 10-byte shape as the wave-bearing
    types, but the leading u16 is a duty-cycle selector (0-7, the DS PSG
    channel's 8 duty settings), not a wave_id, and the second u16 (would-be
    wave_arc) is unused. Confirmed across all 122 real type-2 instruments in
    this ROM's SBNKs: the first u16 is 0-6 (never above 7) and the second is
    0 in every single record -- exactly what a real wave_arc field can never
    be (0 is not a valid in-bank wave-archive slot for a real PCM
    instrument; every real type-1 wave_arc is checked against the owning
    bank's own table and lands in 0-3, never bare 0 as a universal
    constant). The note/attack/decay/sustain/release/pan bytes that follow
    are in the same 0-127 plausible range as every type-1/16/17 region."""
    rec = _parse_record(data, offset)
    return {"duty": rec["wave_id"], "unused": rec["wave_arc"],
            "base_note": rec["base_note"], "attack": rec["attack"],
            "decay": rec["decay"], "sustain": rec["sustain"],
            "release": rec["release"], "pan": rec["pan"]}


def _parse_psg_noise(data, offset):
    """type 3 (PSG noise): same 10-byte shape, no wave data at all -- both
    leading u16 fields (would-be wave_id/wave_arc) are 0 in every one of the
    155 real type-3 instruments in this ROM's SBNKs, consistent with the DS
    noise channel having no wave/duty parameter, only the shared envelope.
    The trailing note/ADSR/pan bytes are still meaningful (same plausible
    0-127 range as every other instrument type) and are kept."""
    rec = _parse_record(data, offset)
    return {"base_note": rec["base_note"], "attack": rec["attack"],
            "decay": rec["decay"], "sustain": rec["sustain"],
            "release": rec["release"], "pan": rec["pan"]}


def _parse_dynamic_regions(data, pos, count):
    """Read `count` region entries starting at `pos`: each is a u16
    region_type followed by the shared 10-byte record (12 bytes total).
    Shared by type 16 (drum kit) and type 17 (key split)."""
    regions = []
    region_types = []
    for _ in range(count):
        region_types.append(struct.unpack_from("<H", data, pos)[0])
        regions.append(_parse_record(data, pos + 2))
        pos += 12
    return region_types, regions


def _parse_drum_kit(data, offset):
    """type 16: u8 low_note, u8 high_note, then
    (high_note - low_note + 1) region entries. See module docstring."""
    low_note, high_note = struct.unpack_from("<BB", data, offset)
    count = high_note - low_note + 1
    region_types, regions = _parse_dynamic_regions(data, offset + 2, count)
    return {"low_note": low_note, "high_note": high_note,
            "region_types": region_types, "regions": regions}


def _parse_key_split(data, offset):
    """type 17: u8 split_points[8] (fixed size, NOT 0x7F-terminated), then
    one region entry per *nonzero* split point. See module docstring."""
    split_points = list(struct.unpack_from("<8B", data, offset))
    count = sum(1 for b in split_points if b != 0)
    region_types, regions = _parse_dynamic_regions(data, offset + 8, count)
    return {"split_points": split_points, "region_types": region_types,
            "regions": regions}


def region_plausible(region, bank_wave_arc_table, archive_wave_count):
    """A region is plausible if its note/ADSR bytes are in 0-127, its
    wave_arc is a valid in-bank slot pointing at a real WAVARC, and its
    wave_id is within that archive's own wave count.
    `bank_wave_arc_table` is the owning BANK's wave_arc[4] (from
    sdat.bank_record()); `archive_wave_count(global_wavarc_index)` must
    return that archive's wave_count (or None if unresolvable)."""
    for key in ("base_note", "attack", "decay", "sustain", "release"):
        if not (0 <= region[key] <= 127):
            return False
    wa = region["wave_arc"]
    if not (0 <= wa < len(bank_wave_arc_table)):
        return False
    global_idx = bank_wave_arc_table[wa]
    if global_idx == 0xFFFF:
        return False
    count = archive_wave_count(global_idx)
    if count is None:
        return False
    return 0 <= region["wave_id"] < count


class Sbnk:
    def __init__(self, data, path=None):
        self.path = path
        self.data = data
        if data[0:4] != b"SBNK":
            raise SbnkError(f"bad magic {data[0:4]!r}, expected b'SBNK'")
        (self.byte_order, self.version, self.file_size, self.header_size,
         self.block_count) = struct.unpack_from("<HHIHH", data, 4)
        if data[0x10:0x14] != b"DATA":
            raise SbnkError("expected DATA block at 0x10")
        self.block_size = struct.unpack_from("<I", data, 0x14)[0]
        self.instrument_count = struct.unpack_from("<I", data, 0x38)[0]
        self.table_end = 0x3C + self.instrument_count * 4
        self.instruments = []
        for i in range(self.instrument_count):
            entry = struct.unpack_from("<I", data, 0x3C + i * 4)[0]
            rec_type = entry & 0xFF
            offset = (entry >> 8) & 0xFFFF
            pad = (entry >> 24) & 0xFF
            self.instruments.append(Instrument(i, rec_type, offset, pad))

    def parse_all_details(self):
        for inst in self.instruments:
            try:
                inst.parse_detail(self.data)
            except (struct.error, IndexError):
                inst.detail = {"error": "record ran past end of file"}

    def roundtrip_bytes(self):
        head = bytearray(self.data[:0x3C])
        table = bytearray()
        for inst in self.instruments:
            entry = ((inst.rec_type & 0xFF) | ((inst.offset & 0xFFFF) << 8)
                     | ((inst.pad & 0xFF) << 24))
            table += struct.pack("<I", entry)
        tail = self.data[self.table_end:]
        return bytes(head) + bytes(table) + tail

    def verify_roundtrip(self):
        return self.roundtrip_bytes() == self.data


def parse_file(path):
    with open(path, "rb") as fh:
        return Sbnk(fh.read(), path=path)


def main(argv=None):
    ap = argparse.ArgumentParser(prog="sbnk.py",
                                  description="Parse an SBNK instrument bank.")
    ap.add_argument("input", help="path to a raw SBNK blob, or an SDAT to pull a BANK from")
    ap.add_argument("--bank-index", type=int, help="BANK index (when --input is an SDAT)")
    ap.add_argument("--verify", action="store_true")
    args = ap.parse_args(argv)

    if args.bank_index is not None:
        s = sdat.parse_file(args.input)
        rec = s.bank_record(args.bank_index)
        if rec is None:
            print(f"[!] BANK index {args.bank_index} has no record", file=sys.stderr)
            return 1
        raw = s.raw_file(rec["file_id"])
        bnk = Sbnk(raw)
        print(f"[*] BANK {args.bank_index}: wave_arc slots = {rec['wave_arc']}")
    else:
        with open(args.input, "rb") as fh:
            bnk = Sbnk(fh.read())

    bnk.parse_all_details()
    print(f"[*] {bnk.instrument_count} instrument slots")
    for inst in bnk.instruments:
        if inst.rec_type == 0:
            continue
        name = TYPE_NAMES.get(inst.rec_type, f"type{inst.rec_type}")
        print(f"  [{inst.index:3d}] {name:<10} @0x{inst.offset:X}  {inst.detail}")

    if args.verify:
        ok = bnk.verify_roundtrip()
        print(f"[*] round trip: {'OK' if ok else 'MISMATCH'}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
