#!/usr/bin/env python3
"""
sdat.py -- SDAT (NitroSDK sound archive) container reader for the aletheia
asset lane. Currently targets wb_sound_data.sdat, the ROM's single top-level
sound archive.

Written from scratch for the aletheia project. Stdlib only, single file.
No game data is written anywhere by this module; it only reports structure
(counts, names, offsets/sizes) to stdout / an optional JSON summary.

--------------------------------------------------------------------------
SDAT container layout (public NitroSDK-format knowledge, not sourced from
any other decomp project's code)
--------------------------------------------------------------------------
File header (0x40 bytes):
    0x00  char[4]  magic          "SDAT"
    0x04  u16      byte_order     0xFEFF-style BOM marker
    0x06  u16      version
    0x08  u32      file_size
    0x0C  u16      header_size    always 0x40
    0x0E  u16      block_count    always 4
    0x10  u32      symb_offset
    0x14  u32      symb_size
    0x18  u32      info_offset
    0x1C  u32      info_size
    0x20  u32      fat_offset
    0x24  u32      fat_size
    0x28  u32      file_offset
    0x2C  u32      file_size2
    0x30  ...      reserved, padding to 0x40

SYMB block (string tables, all offsets relative to the block's own start,
i.e. the byte right after "SYMB"+size):
    0x00  char[4]  magic "SYMB"
    0x04  u32      size
    0x08  8 x u32  offsets to 8 "Record" tables, in this fixed order:
                   SEQ, SEQARC, BANK, WAVARC, PLAYER, GROUP, PLAYER2, STRM
    each Record table:
        u32       count
        count x u32  offset (relative to SYMB start) to a NUL-terminated
                     ASCII name string
    (an offset of 0 anywhere in these tables means "no name for this slot")

INFO block (per-entry metadata, offsets relative to the block's own start):
    0x00  char[4]  magic "INFO"
    0x04  u32      size
    0x08  8 x u32  offsets to 8 "Info" tables, same order as SYMB's records
    each Info table:
        u32       count
        count x u32  offset (relative to INFO start) to a per-entry record,
                     or 0 for an absent entry. This reader only uses the
                     count (it should match the matching SYMB record count)
                     and does not decode the per-type record layouts (they
                     differ: SEQ records carry a fileID+bank+volume etc.,
                     BANK records carry a fileID+4 wave-archive slot ids,
                     WAVARC records carry a fileID+flags, STRM records
                     carry a fileID+playback params) -- out of scope here,
                     this lane only needs counts/names per resource type.

FAT block:
    0x00  char[4]  magic "FAT "
    0x04  u32      size
    0x08  u32      count
    then `count` x 16-byte records:
        u32  file_offset   (absolute, from the start of the SDAT file)
        u32  file_size
        u32  reserved (0)
        u32  reserved (0)

FILE block:
    0x00  char[4]  magic "FILE"
    0x04  u32      size
    then `count` (== FAT's count) x sub-blocks, each:
        u32  block_size    (size of this sub-block, header included)
        20 bytes reserved
        block_size-24 bytes of file data (an SSEQ/SBNK/SWAR/STRM chunk,
        itself further chunked with its own magic -- not decoded here)
    In practice each FAT entry's (file_offset, file_size) already gives the
    exact byte range of the raw resource; the FILE block's own sub-headers
    are redundant with FAT for extraction purposes, so this reader only
    parses FAT and cross-checks against the FILE block's declared size.
"""

import argparse
import json
import os
import struct
import sys


class SdatError(Exception):
    pass


RECORD_NAMES = ["SEQ", "SEQARC", "BANK", "WAVARC", "PLAYER", "GROUP", "PLAYER2", "STRM"]


def _cstr(data, offset):
    end = data.index(b"\x00", offset)
    return data[offset:end].decode("ascii", errors="replace")


def _read_section(data, pos, expect_magic):
    if pos + 8 > len(data):
        raise SdatError(f"section at 0x{pos:X} runs past end of file "
                         f"(expected {expect_magic!r})")
    magic, size = struct.unpack_from("<4sI", data, pos)
    if magic != expect_magic:
        raise SdatError(f"expected section {expect_magic!r} at 0x{pos:X}, found {magic!r}")
    if pos + size > len(data):
        raise SdatError(f"section {expect_magic!r} claims size 0x{size:X}, past end of file")
    return magic, size, data[pos:pos + size]


class Sdat:
    def __init__(self, data, path=None):
        self.path = path
        self.data = data
        self._parse()

    def _parse(self):
        data = self.data
        if len(data) < 0x40:
            raise SdatError("file too small for an SDAT header")
        magic = data[0:4]
        if magic != b"SDAT":
            raise SdatError(f"bad magic {magic!r}, expected b'SDAT'")
        (self.byte_order, self.version, self.file_size, self.header_size,
         self.block_count) = struct.unpack_from("<HHIHH", data, 4)
        (symb_off, symb_size, info_off, info_size, fat_off, fat_size,
         file_off, file_size2) = struct.unpack_from("<8I", data, 0x10)

        _, _, symb_body = _read_section(data, symb_off, b"SYMB")
        _, _, info_body = _read_section(data, info_off, b"INFO")
        _, _, fat_body = _read_section(data, fat_off, b"FAT ")
        _, _, file_body = _read_section(data, file_off, b"FILE")

        self.symb = self._parse_symb(symb_body) if symb_size else None
        self.info_counts = self._parse_info_counts(info_body)
        self.info_body = info_body
        self._info_record_offsets = self._parse_info_record_offsets(info_body)
        self.fat = self._parse_fat(fat_body)
        self.file_block_size = len(file_body)

    def _parse_symb(self, body):
        record_offsets = struct.unpack_from("<8I", body, 8)
        out = {}
        for name, off in zip(RECORD_NAMES, record_offsets):
            if off == 0:
                out[name] = []
                continue
            count = struct.unpack_from("<I", body, off)[0]
            names = []
            for i in range(count):
                str_off = struct.unpack_from("<I", body, off + 4 + i * 4)[0]
                names.append(_cstr(body, str_off) if str_off else None)
            out[name] = names
        return out

    def _parse_info_counts(self, body):
        record_offsets = struct.unpack_from("<8I", body, 8)
        out = {}
        for name, off in zip(RECORD_NAMES, record_offsets):
            if off == 0:
                out[name] = 0
                continue
            count = struct.unpack_from("<I", body, off)[0]
            out[name] = count
        return out

    def _parse_info_record_offsets(self, body):
        """Per record type, the list of per-slot INFO-body byte offsets
        (0 = no record for that slot). INFO records are of a fixed size
        per type (SEQ/BANK = 12 bytes, WAVARC = 4 bytes, established
        empirically -- see docs/ASSETS.md's audio-formats section) and are
        packed densely; the offset table maps a sparse logical slot index
        to that dense array, skipping absent slots entirely."""
        section_offsets = struct.unpack_from("<8I", body, 8)
        out = {}
        for name, off in zip(RECORD_NAMES, section_offsets):
            if off == 0:
                out[name] = []
                continue
            count = struct.unpack_from("<I", body, off)[0]
            ptrs = struct.unpack_from(f"<{count}I", body, off + 4)
            out[name] = list(ptrs)
        return out

    def wavarc_fileid(self, index):
        """WAVARC INFO record: a single u32 fileId (4 bytes)."""
        ptr = self._info_record_offsets.get("WAVARC", [])[index]
        if ptr == 0:
            return None
        return struct.unpack_from("<I", self.info_body, ptr)[0]

    def bank_record(self, index):
        """BANK INFO record (12 bytes): u16 fileId, u16 reserved,
        u16 wave_arc[4] (indices into this SDAT's WAVARC table; 0xFFFF =
        unused slot)."""
        ptr = self._info_record_offsets.get("BANK", [])[index]
        if ptr == 0:
            return None
        file_id, _reserved = struct.unpack_from("<HH", self.info_body, ptr)
        wave_arc = list(struct.unpack_from("<4H", self.info_body, ptr + 4))
        return {"file_id": file_id, "wave_arc": wave_arc}

    def seq_record(self, index):
        """SEQ INFO record (12 bytes): u16 fileId, u16 reserved (always 0),
        u8 volume, u8 channel_pressure, u8 player_priority, u8 player_no,
        u8 unk_const, u8 player_sel, u16 reserved2 (always 0).

        Revised during the sseq2midi lane. The field previously labelled
        "bank" (a u16 read from +2) is always 0 across all 940 populated SEQ
        records, which can't be a real per-track BANK-table index --
        `bank_record(0)` has no INFO record at all (0/940 lookups would
        succeed). Byte-level re-inspection of the trailing 4 bytes (formerly
        lumped into "u32 reserved") found: byte +8 is 0x40 in 939/940
        records (the one exception is the degenerate `SEQ_PV_END` slot,
        whose whole tail is zero) -- effectively constant, so almost
        certainly a flag/padding byte, not a table index; byte +9 takes
        only 7 distinct small values (0-6) across all 940 records; bytes
        +10:12 are 0x0000 in every record sampled. Reading bytes +8:10 as
        one little-endian u16 (as an earlier version of this method did)
        happened to land on *valid* `bank_record()` rows purely by
        arithmetic coincidence (`256*sel + 0x40` lands in the densely-
        populated part of the 1986-slot BANK table often enough to look
        like a hit) -- not a real decode; that version is wrong and has
        been reverted.

        Byte +9's range (0-6) matches this SDAT's own `PLAYER` record count
        (7, see "SDAT internal structure" in docs/ASSETS.md) far better
        than a direct BANK index would, so `player_sel` is reported as its
        own field, most likely a PLAYER-table selector -- BANK resolution
        for a given SEQ likely goes SEQ -> PLAYER -> BANK, not SEQ -> BANK
        directly. PLAYER's own INFO record layout is not decoded (out of
        scope this pass, same as the module docstring already notes for
        SEQARC/GROUP/STRM internals), so this reader stops at reporting
        `player_sel` and does not resolve it to an actual BANK. Callers
        that need a real per-SEQ SBNK (e.g. `sseq2midi.py`'s program-number
        mapping) must pass an explicit BANK index rather than rely on this
        record."""
        ptr = self._info_record_offsets.get("SEQ", [])[index]
        if ptr == 0:
            return None
        (file_id, _reserved, vol, cpr, ppr, ply, unk_const,
         player_sel, _reserved2) = struct.unpack_from("<HHBBBBBBH", self.info_body, ptr)
        return {"file_id": file_id, "volume": vol, "channel_pressure": cpr,
                "player_priority": ppr, "player_no": ply,
                "unk_const": unk_const, "player_sel": player_sel}

    def raw_file(self, file_id):
        """Raw bytes of a FAT/FILE sub-blob (an SSEQ/SBNK/SWAR/STRM chunk)."""
        off, size = self.fat[file_id]
        return self.data[off:off + size]

    def _parse_fat(self, body):
        count = struct.unpack_from("<I", body, 8)[0]
        entries = []
        for i in range(count):
            base = 0xC + i * 16
            off, size = struct.unpack_from("<II", body, base)
            entries.append((off, size))
        return entries

    def names_for(self, record):
        """Return the SYMB name list for a record type, or a list of None
        (same length as INFO's count) if this SDAT has no SYMB block."""
        count = self.info_counts.get(record, 0)
        if self.symb is not None:
            names = self.symb.get(record, [])
            if len(names) == count:
                return names
        return [None] * count


def parse_file(path):
    with open(path, "rb") as fh:
        data = fh.read()
    return Sdat(data, path=path)


# ---------------------------------------------------------------------------
# cry / music / effect classification heuristic
# ---------------------------------------------------------------------------

def classify_seq_names(names):
    """Split SEQ (SSEQ, sequenced music/jingle) names into buckets by naming
    pattern only -- a heuristic, not verified against any external list.
    Pokemon SDAT naming in this generation commonly prefixes cries with
    "SE_POKE_" or similar and other sound effects with "SE_"; everything
    else that isn't obviously a sound effect is treated as music/jingle."""
    cry = []
    sfx = []
    music = []
    for n in names:
        if n is None:
            music.append(n)
            continue
        u = n.upper()
        if "CRY" in u or "POKE_" in u or "POKEMON_" in u:
            cry.append(n)
        elif u.startswith("SE_") or "_SE" in u or "SYS_SE" in u:
            sfx.append(n)
        else:
            music.append(n)
    return cry, music, sfx


def main(argv=None):
    ap = argparse.ArgumentParser(prog="sdat.py",
                                  description="Parse and inspect an SDAT sound archive.")
    ap.add_argument("input")
    ap.add_argument("--json", help="write a JSON summary to this path")
    args = ap.parse_args(argv)

    sdat = parse_file(args.input)
    print(f"[*] {args.input}: SDAT v{sdat.version:#06x}, {sdat.file_size} bytes, "
          f"{'SYMB present' if sdat.symb is not None else 'NO SYMB (unnamed)'}")
    print(f"[*] FAT: {len(sdat.fat)} file entries")
    total_fat_bytes = sum(sz for _, sz in sdat.fat)
    print(f"[*] FILE block: {sdat.file_block_size} bytes "
          f"(sum of FAT sizes: {total_fat_bytes} bytes)")
    print()
    for rec in RECORD_NAMES:
        count = sdat.info_counts.get(rec, 0)
        print(f"  {rec:<8} {count}")

    seq_names = sdat.names_for("SEQ")
    cry, music, sfx = classify_seq_names(seq_names)
    print()
    print(f"[*] SEQ (SSEQ) naming split (heuristic, not verified): "
          f"{len(cry)} cry-like, {len(music)} music/other, {len(sfx)} sfx-like")

    if args.json:
        summary = {
            "path": args.input,
            "file_size": sdat.file_size,
            "has_symb": sdat.symb is not None,
            "counts": sdat.info_counts,
            "fat_entries": len(sdat.fat),
            "seq_names": seq_names,
            "bank_names": sdat.names_for("BANK"),
            "wavarc_names": sdat.names_for("WAVARC"),
            "strm_names": sdat.names_for("STRM"),
            "seq_split": {"cry_like": cry, "music_other_count": len(music), "sfx_like": sfx},
        }
        out_dir = os.path.dirname(args.json)
        if out_dir:
            os.makedirs(out_dir, exist_ok=True)
        with open(args.json, "w", encoding="utf-8") as fh:
            json.dump(summary, fh, indent=2)
        print(f"[*] wrote {args.json}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
