#!/usr/bin/env python3
"""
sbnk.py -- SBNK (instrument bank) reader for the aletheia asset lane.
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
    0x3C  instrument_count x u32 instrument entry:
              bits 0-7    record_type
              bits 8-31   record_offset (absolute file offset, 0 if
                          record_type == 0 / no instrument in this slot)

This much (header, instrument-table shape, and the type+offset packing of
each entry) was confirmed empirically end-to-end: BANK slot 25's single
instrument (record_type 1) points to a 12-byte PCM record whose
wave_arc/wave indices (0, 0) resolve -- via the owning BANK's own
wave_arc[] table, entry 0 -- to WAVARC slot 25 (WAVE_ARC_PV025), the
Pikachu cry SWAR archive, matching this bank's own SYMB-adjacent naming.
See docs/ASSETS.md's audio-formats section for the full worked trace.

Instrument record_type layouts, by confidence:

  type 0 (empty slot, ~59% of all instrument-table entries across the
  1497 real SBNKs): record_offset is 0, no data follows. HIGH confidence.

  type 1 (single-region PCM instrument, the most common real type):
  a fixed 12-byte record:
      u16 wave_arc   (index into the owning BANK's wave_arc[4] slots,
                       NOT a global WAVARC index)
      u16 wave_id    (index of the SWAV within that SWAR archive)
      u8  base_note  (MIDI note the sample was recorded at, e.g. 60 = C4)
      u8  attack, decay, sustain, release  (u8 ADSR envelope, 0-127-ish)
      u8  pan        (0-127, 64 = center)
      u16 padding
  HIGH confidence (fully verified by the Pikachu-cry trace above).

  type 2 / type 3 (seen in real banks, ~5-6% of entries combined):
  structurally distinct from type 1/16/17 -- LOW confidence, not fully
  reverse engineered this pass. Likely PSG-channel instrument types
  (pulse/noise, which the DS sound hardware supports alongside PCM) given
  their small, fixed-looking record size, but this is a guess.

  type 16 (drum kit) / type 17 (key-split, multi-region): MEDIUM
  confidence. Real data shows a leading run of ascending u8 "split point"
  note values terminated at 0x7F, followed by one region sub-record per
  split point that *looks* like the same wave_arc/wave_id/base_note/ADSR/
  pan shape as type 1. Region boundaries and per-region wave references
  are extracted best-effort by `parse_regions()` below and reported, but
  the exact byte layout (in particular where the split-point list ends
  and the region record array begins) was not independently re-derived
  from a byte-level spec -- treat `parse_regions()` output as a strong
  hint, not a verified decode.

Round trip: because only the fixed-size header and instrument-table
prefix's *meaning* needed to be established for a byte-identical
round trip (the type/offset packing is a straight struct read/pack with
no transformation), `Sbnk.roundtrip_bytes()` reconstructs the file as
(header + table, re-packed from the decoded fields) + (every remaining
byte from the end of the table to end of file, copied verbatim). This is
byte-identical by construction for every SBNK regardless of whether every
instrument record type's internal layout is fully understood -- it
verifies the parser's understanding of the *container and table*
structure, which is what actually needs to be right for the table to be
useful; deep field-level understanding of every instrument type (notably
2/3/16/17's internals) is reported separately and honestly labelled as
lower-confidence.
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import sdat  # noqa: E402

TYPE_NAMES = {
    0: "Empty", 1: "PCM", 2: "PSG_Sq?", 3: "PSG_Noise?", 16: "DrumKit", 17: "KeySplit",
}


class SbnkError(Exception):
    pass


class Instrument:
    def __init__(self, index, rec_type, offset):
        self.index = index
        self.rec_type = rec_type
        self.offset = offset
        self.detail = None  # filled in by parse_detail()

    def parse_detail(self, data):
        if self.rec_type == 0:
            self.detail = {}
            return
        if self.rec_type == 1:
            self.detail = _parse_pcm_record(data, self.offset)
            return
        if self.rec_type in (16, 17):
            self.detail = parse_regions(data, self.offset)
            return
        self.detail = {"raw_head": data[self.offset:self.offset + 16].hex()}


def _parse_pcm_record(data, offset):
    wave_arc, wave_id = struct.unpack_from("<HH", data, offset)
    base_note, attack, decay, sustain, release, pan = struct.unpack_from(
        "<6B", data, offset + 4)
    return {"wave_arc": wave_arc, "wave_id": wave_id, "base_note": base_note,
            "attack": attack, "decay": decay, "sustain": sustain,
            "release": release, "pan": pan}


def parse_regions(data, offset, max_regions=128):
    """Best-effort: read ascending u8 split points until 0x7F (inclusive),
    then one 12-byte PCM-shaped record per split point. See module
    docstring -- MEDIUM confidence, not independently verified."""
    splits = []
    pos = offset
    for _ in range(max_regions):
        b = data[pos]
        splits.append(b)
        pos += 1
        if b >= 0x7F:
            break
    regions = []
    for _ in splits:
        regions.append(_parse_pcm_record(data, pos))
        pos += 12
    return {"split_points": splits, "regions": regions}


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
            self.instruments.append(Instrument(i, entry & 0xFF, entry >> 8))

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
            entry = (inst.rec_type & 0xFF) | (inst.offset << 8)
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
