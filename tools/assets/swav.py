#!/usr/bin/env python3
"""
swav.py -- SWAR (wave archive) / SWAV (single wave) reader for the
aletheia asset lane. Stdlib only, written from scratch for this project.

--------------------------------------------------------------------------
Format (established empirically against extract/data/wb_sound_data.sdat's
real WAVARC entries, cross-checked against the SBNK instrument that
references them -- see docs/ASSETS.md's audio-formats section for the
worked example that pins this layout down; general block shape agrees
with the publicly documented NitroSDK "generic section" convention also
used by SDAT/SBNK/SSEQ)
--------------------------------------------------------------------------

SWAR file:
    0x00  char[4]  magic "SWAR"
    0x04  u16      byte_order (0xFEFF)
    0x06  u16      version
    0x08  u32      file_size
    0x0C  u16      header_size (0x10)
    0x0E  u16      block_count (1)
    0x10  char[4]  "DATA"
    0x14  u32      block_size
    0x18  32 bytes reserved (always zero in every instance sampled)
    0x38  u32      wave_count
    0x3C  wave_count x u32   absolute file offset to each SWAV record
    ...   SWAV records (see below), back to back; a wave's byte length is
          not stored directly -- it is (next wave's offset - this wave's
          offset), or (file end - offset) for the last wave. This was
          confirmed empirically: offset[1] - offset[0] equals exactly
          12 + (loopOffset + nonLoopLength) * 4 for every sample checked.

SWAV record (embedded in a SWAR at each offset above):
    0x00  u8   wave_type      (0 = PCM8, 1 = PCM16, 2 = IMA-ADPCM)
    0x01  u8   loop_flag      (0 = one-shot, 1 = loop)
    0x02  u16  sample_rate    (Hz)
    0x04  u16  timer_val      (hardware timer reload value, -0x1000000/rate;
                                not needed for decoding, kept for completeness)
    0x06  u16  loop_offset    (loop point, in 4-byte words, from the start
                                of the sample data that follows this header)
    0x08  u32  nonloop_length (length of the post-loop-point region, in
                                4-byte words)
    0x0C  ...  sample data, length = (loop_offset + nonloop_length) * 4
               bytes, wave-type-dependent encoding:
                 PCM8:  signed 8-bit samples, 1 byte/sample
                 PCM16: signed 16-bit LE samples, 2 bytes/sample
                 ADPCM: a 4-byte seed header (s16 initial predictor,
                        u8 initial step-table index, u8 reserved/0),
                        then standard IMA-ADPCM nibbles (2/byte, low
                        nibble first) -- see adpcm.py

wave_type 1 (PCM16) was never observed in this ROM's WAVARC entries (a
1494-archive scan found only PCM8 and IMA-ADPCM); the PCM16 path below is
implemented from the same documented record layout but not empirically
exercised against real data from this ROM.
"""

import argparse
import os
import struct
import sys
import wave as wavemod

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import adpcm  # noqa: E402

WAVE_TYPE_PCM8 = 0
WAVE_TYPE_PCM16 = 1
WAVE_TYPE_ADPCM = 2


class SwavError(Exception):
    pass


class Swav:
    def __init__(self, wave_type, loop_flag, sample_rate, timer_val,
                 loop_offset_words, nonloop_length_words, sample_data):
        self.wave_type = wave_type
        self.loop_flag = loop_flag
        self.sample_rate = sample_rate
        self.timer_val = timer_val
        self.loop_offset_words = loop_offset_words
        self.nonloop_length_words = nonloop_length_words
        self.sample_data = sample_data  # raw bytes exactly as stored

    @property
    def total_bytes(self):
        return (self.loop_offset_words + self.nonloop_length_words) * 4

    @classmethod
    def parse(cls, blob, offset, end):
        wave_type, loop_flag = blob[offset], blob[offset + 1]
        sample_rate, timer_val, loop_offset = struct.unpack_from(
            "<HHH", blob, offset + 2)
        nonloop_length = struct.unpack_from("<I", blob, offset + 8)[0]
        data_start = offset + 12
        total = (loop_offset + nonloop_length) * 4
        data_end = data_start + total
        if data_end > end:
            raise SwavError(
                f"SWAV at 0x{offset:X} declares {total} bytes of sample "
                f"data, runs past the next record / end of archive")
        sample_data = blob[data_start:data_end]
        return cls(wave_type, loop_flag, sample_rate, timer_val,
                    loop_offset, nonloop_length, sample_data)

    def decode_pcm16(self):
        """Decode to a list of signed 16-bit PCM samples, regardless of
        source wave_type."""
        if self.wave_type == WAVE_TYPE_PCM8:
            n = len(self.sample_data)
            return [s * 256 for s in struct.unpack(f"<{n}b", self.sample_data)]
        elif self.wave_type == WAVE_TYPE_PCM16:
            n = len(self.sample_data) // 2
            return list(struct.unpack(f"<{n}h", self.sample_data[:n * 2]))
        elif self.wave_type == WAVE_TYPE_ADPCM:
            pred0, idx0 = struct.unpack_from("<hB", self.sample_data, 0)
            nibble_bytes = self.sample_data[4:]
            count = len(nibble_bytes) * 2
            return adpcm.decode_block(nibble_bytes, pred0, idx0, count)
        else:
            raise SwavError(f"unknown wave_type {self.wave_type}")

    def reencode(self):
        """Re-encode sample_data from its decoded PCM16 form, byte-for-byte
        against the original -- used to verify the decoder round-trips.
        Returns the re-encoded bytes (compare to self.sample_data)."""
        samples = self.decode_pcm16()
        if self.wave_type == WAVE_TYPE_PCM8:
            n = len(samples)
            clipped = [max(-128, min(127, s // 256)) for s in samples]
            return struct.pack(f"<{n}b", *clipped)
        elif self.wave_type == WAVE_TYPE_PCM16:
            n = len(samples)
            return struct.pack(f"<{n}h", *samples)
        elif self.wave_type == WAVE_TYPE_ADPCM:
            pred0, idx0 = struct.unpack_from("<hB", self.sample_data, 0)
            nibbles, _, _ = adpcm.encode_block(samples, pred0, idx0)
            return self.sample_data[:4] + nibbles
        else:
            raise SwavError(f"unknown wave_type {self.wave_type}")

    def write_wav(self, path):
        samples = self.decode_pcm16()
        os.makedirs(os.path.dirname(path) or ".", exist_ok=True)
        with wavemod.open(path, "wb") as w:
            w.setnchannels(1)
            w.setsampwidth(2)
            w.setframerate(self.sample_rate or 16000)
            w.writeframes(struct.pack(f"<{len(samples)}h", *samples))


class Swar:
    def __init__(self, data, path=None):
        self.path = path
        self.data = data
        self._parse()

    def _parse(self):
        data = self.data
        if data[0:4] != b"SWAR":
            raise SwavError(f"bad magic {data[0:4]!r}, expected b'SWAR'")
        (self.byte_order, self.version, self.file_size, self.header_size,
         self.block_count) = struct.unpack_from("<HHIHH", data, 4)
        if data[0x10:0x14] != b"DATA":
            raise SwavError("expected DATA block at 0x10")
        self.block_size = struct.unpack_from("<I", data, 0x14)[0]
        wave_count = struct.unpack_from("<I", data, 0x38)[0]
        offsets = struct.unpack_from(f"<{wave_count}I", data, 0x3C)
        self.wave_offsets = offsets
        self.waves = []
        for i, off in enumerate(offsets):
            end = offsets[i + 1] if i + 1 < wave_count else len(data)
            self.waves.append(Swav.parse(data, off, end))


def parse_file(path):
    with open(path, "rb") as fh:
        return Swar(fh.read(), path=path)


def verify_roundtrip(swar):
    """Returns (ok_count, total_count, first_failure_or_None)."""
    ok = 0
    fail = None
    for i, w in enumerate(swar.waves):
        re = w.reencode()
        if re == w.sample_data:
            ok += 1
        elif fail is None:
            fail = (i, w.wave_type)
    return ok, len(swar.waves), fail


def main(argv=None):
    ap = argparse.ArgumentParser(prog="swav.py",
                                  description="Parse an SWAR wave archive, "
                                              "write WAV files, verify round trip.")
    ap.add_argument("input", help="path to a raw SWAR blob (extracted via sdat.py's FAT)")
    ap.add_argument("--wav-out", help="directory to write one .wav per wave slot")
    ap.add_argument("--verify", action="store_true", help="verify byte-identical re-encode")
    args = ap.parse_args(argv)

    swar = parse_file(args.input)
    print(f"[*] {args.input}: SWAR, {len(swar.waves)} wave(s)")
    for i, w in enumerate(swar.waves):
        kind = {0: "PCM8", 1: "PCM16", 2: "ADPCM"}.get(w.wave_type, f"?{w.wave_type}")
        print(f"  wave {i}: {kind} loop={w.loop_flag} rate={w.sample_rate}Hz "
              f"bytes={w.total_bytes}")
        if args.wav_out:
            w.write_wav(os.path.join(args.wav_out, f"{i:03d}.wav"))
    if args.verify:
        ok, total, fail = verify_roundtrip(swar)
        print(f"[*] round trip: {ok}/{total} waves byte-identical re-encode"
              + (f" (first failure: wave {fail[0]} type {fail[1]})" if fail else ""))
    return 0


if __name__ == "__main__":
    sys.exit(main())
