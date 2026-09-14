#!/usr/bin/env python3
"""
sseq.py -- SSEQ (sequenced music/SFX bytecode) reader for the aletheia
asset lane. Stdlib only, written from scratch for this project.

--------------------------------------------------------------------------
Container (same generic-section shape as SWAR/SBNK -- see swav.py/sbnk.py):
    0x00  char[4]  magic "SSEQ"
    0x04  u16      byte_order
    0x06  u16      version
    0x08  u32      file_size
    0x0C  u16      header_size (0x10)
    0x0E  u16      block_count (1)
    0x10  char[4]  "DATA"
    0x14  u32      block_size
    0x18  u32      data_offset  (absolute offset, from the start of this
                                  file, to the first byte of track-0
                                  bytecode -- confirmed empirically: it is
                                  always exactly 0x1C, the byte right
                                  after this field)

Bytecode (the "opcode table" below): established empirically by
disassembling extract/data/wb_sound_data.sdat's SEQ_BGM_DUMMY (SDAT SEQ
slot 1000) and cross-checked structurally against public documentation of
the Nitro Composer / "SSEQ" event format (widely mirrored across NDS
homebrew community docs, not sourced from any decomp project's code).
Track 0 always opens with 0xFE (AllocTrack) then a run of 0x93
(OpenTrack) commands, one per additional track, each naming an absolute
file offset where that track's bytecode begins -- this shape was directly
observed and is the anchor that confirmed the whole table below.

Event grammar (byte at the event's start position selects the shape):
    0x00-0x7F  Note:      note=opcode, u8 velocity, varint duration
    0x80       Rest:      varint duration
    0x81       ProgramChange (instrument select): varint patch number
    0x93       OpenTrack: u8 track_no, u24 LE offset (track-0 only)
    0x94       Jump:      u24 LE offset
    0x95       Call:      u24 LE offset (paired with 0xFD Return)
    0xC0       Pan:              u8
    0xC1       Volume:           u8
    0xC2       MasterVolume:     u8
    0xC3       Transpose:        s8
    0xC4       PitchBend:        s8
    0xC5       PitchBendRange:   u8
    0xC6       Priority:         u8
    0xC7       (observed after 0xFD in real data; treated as a generic u8
                argument command -- see caveats)
    0xC8       Tie / Mono:       u8
    0xC9       PortamentoControl:u8
    0xCA       ModDepth:         u8
    0xCB       ModSpeed:         u8
    0xCC       ModType:          u8
    0xCD       ModRange:         u8
    0xCE       PortamentoOnOff:  u8
    0xCF       PortamentoTime:   u8
    0xD0       Attack:           u8
    0xD1       Decay:            u8
    0xD2       Sustain:          u8
    0xD3       Release:          u8
    0xD4       LoopStart:        u8 (repeat count, 0 = infinite)
    0xD5       Expression:       u8
    0xD6       (generic u8 argument, unconfirmed)
    0xB0-0xBD  variable ops (Set/Add/Sub/Mul/Div/Shift/Rand/compares):
                                  u8 var_no, s16 value
    0xE0       ModDelay:         u16
    0xE1       Tempo:            u16 (BPM)
    0xE3       SweepPitch:       s16
    0xFC       LoopEnd:          (no args)
    0xFD       Return:           (no args)
    0xFE       AllocTrack:       u16 track bitmask (track-0 only)
    0xFF       TrackEnd:         (no args)

Duration/patch "varint": MIDI-style variable-length quantity, 7 data bits
per byte, MSB-first, continuation while the top bit is set. Confirmed for
the (extremely common) single-byte case in real data; the multi-byte case
follows the standard, widely-documented convention for this format but was
not separately re-derived byte-by-byte in this pass.

Known gaps (honest, not fixed up): 0xA0 (Random) / 0xA1 (GetVariable) /
0xA2 (If) can appear in place of a literal argument almost anywhere a u8/
s16 value is expected, not just as top-level commands; this decoder does
not special-case that substitution. When the decoder meets a byte it does
not recognise as an event opcode, it stops interpreting events and emits
one final "RAW" pseudo-event carrying every remaining byte verbatim, so
disassembly never crashes and the round trip (dump() events re-encoded
back to bytes) always reproduces the original file exactly -- see
`roundtrip()`. `coverage()` reports what fraction of the bytecode was
covered by genuinely decoded events vs. swallowed by that raw fallback,
which is the honest per-file quality signal.
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import sdat  # noqa: E402

U8_ARG_OPS = {
    0xC0: "Pan", 0xC1: "Volume", 0xC2: "MasterVolume", 0xC5: "PitchBendRange",
    0xC6: "Priority", 0xC7: "Unk_C7", 0xC8: "Tie", 0xC9: "PortamentoControl",
    0xCA: "ModDepth", 0xCB: "ModSpeed", 0xCC: "ModType", 0xCD: "ModRange",
    0xCE: "PortamentoOnOff", 0xCF: "PortamentoTime", 0xD0: "Attack",
    0xD1: "Decay", 0xD2: "Sustain", 0xD3: "Release", 0xD4: "LoopStart",
    0xD5: "Expression", 0xD6: "Unk_D6",
}
S8_ARG_OPS = {0xC3: "Transpose", 0xC4: "PitchBend"}
U16_ARG_OPS = {0xE0: "ModDelay", 0xE1: "Tempo"}
S16_ARG_OPS = {0xE3: "SweepPitch"}
NO_ARG_OPS = {0xFC: "LoopEnd", 0xFD: "Return", 0xFF: "TrackEnd"}
VAR_OPS = {
    0xB0: "VarSet", 0xB1: "VarAdd", 0xB2: "VarSub", 0xB3: "VarMul",
    0xB4: "VarDiv", 0xB5: "VarShift", 0xB6: "VarRand", 0xB8: "VarEq",
    0xB9: "VarGe", 0xBA: "VarGt", 0xBB: "VarLe", 0xBC: "VarLt", 0xBD: "VarNe",
}


class SseqError(Exception):
    pass


def read_varint(data, pos):
    val = 0
    consumed = 0
    while True:
        b = data[pos + consumed]
        consumed += 1
        val = (val << 7) | (b & 0x7F)
        if not (b & 0x80):
            break
    return val, consumed


def write_varint(val):
    chunks = [val & 0x7F]
    val >>= 7
    while val:
        chunks.append(val & 0x7F)
        val >>= 7
    chunks.reverse()
    out = bytearray()
    for i, c in enumerate(chunks):
        last = (i == len(chunks) - 1)
        out.append(c if last else (c | 0x80))
    return bytes(out)


def _s8(b):
    return b - 256 if b >= 128 else b


def _u8_from_s8(v):
    return v & 0xFF


def decode_event(data, pos):
    """Decode one event at `data[pos]`. Returns (event_dict, new_pos).
    Raises SseqError (caught by the caller) on an unrecognised opcode."""
    op = data[pos]
    start = pos
    if op < 0x80:
        note = op
        vel = data[pos + 1]
        dur, consumed = read_varint(data, pos + 2)
        end = pos + 2 + consumed
        return {"op": "Note", "note": note, "velocity": vel, "duration": dur,
                "start": start, "end": end}, end
    if op == 0x80:
        dur, consumed = read_varint(data, pos + 1)
        end = pos + 1 + consumed
        return {"op": "Rest", "duration": dur, "start": start, "end": end}, end
    if op == 0x81:
        patch, consumed = read_varint(data, pos + 1)
        end = pos + 1 + consumed
        return {"op": "ProgramChange", "patch": patch, "start": start, "end": end}, end
    if op == 0x93:
        track_no = data[pos + 1]
        off = data[pos + 2] | (data[pos + 3] << 8) | (data[pos + 4] << 16)
        end = pos + 5
        return {"op": "OpenTrack", "track_no": track_no, "offset": off,
                "start": start, "end": end}, end
    if op in (0x94, 0x95):
        off = data[pos + 1] | (data[pos + 2] << 8) | (data[pos + 3] << 16)
        end = pos + 4
        name = "Jump" if op == 0x94 else "Call"
        return {"op": name, "offset": off, "start": start, "end": end}, end
    if op == 0xFE:
        mask = struct.unpack_from("<H", data, pos + 1)[0]
        end = pos + 3
        return {"op": "AllocTrack", "mask": mask, "start": start, "end": end}, end
    if op in NO_ARG_OPS:
        end = pos + 1
        return {"op": NO_ARG_OPS[op], "start": start, "end": end}, end
    if op in U8_ARG_OPS:
        val = data[pos + 1]
        end = pos + 2
        return {"op": U8_ARG_OPS[op], "value": val, "start": start, "end": end}, end
    if op in S8_ARG_OPS:
        val = _s8(data[pos + 1])
        end = pos + 2
        return {"op": S8_ARG_OPS[op], "value": val, "start": start, "end": end}, end
    if op in U16_ARG_OPS:
        val = struct.unpack_from("<H", data, pos + 1)[0]
        end = pos + 3
        return {"op": U16_ARG_OPS[op], "value": val, "start": start, "end": end}, end
    if op in S16_ARG_OPS:
        val = struct.unpack_from("<h", data, pos + 1)[0]
        end = pos + 3
        return {"op": S16_ARG_OPS[op], "value": val, "start": start, "end": end}, end
    if op in VAR_OPS:
        var_no = data[pos + 1]
        val = struct.unpack_from("<h", data, pos + 2)[0]
        end = pos + 4
        return {"op": VAR_OPS[op], "var_no": var_no, "value": val,
                "start": start, "end": end}, end
    raise SseqError(f"unrecognised opcode 0x{op:02X} at 0x{pos:X}")


def encode_event(ev):
    op = ev["op"]
    if op == "Note":
        return bytes([ev["note"], ev["velocity"]]) + write_varint(ev["duration"])
    if op == "Rest":
        return bytes([0x80]) + write_varint(ev["duration"])
    if op == "ProgramChange":
        return bytes([0x81]) + write_varint(ev["patch"])
    if op == "OpenTrack":
        o = ev["offset"]
        return bytes([0x93, ev["track_no"], o & 0xFF, (o >> 8) & 0xFF, (o >> 16) & 0xFF])
    if op in ("Jump", "Call"):
        o = ev["offset"]
        code = 0x94 if op == "Jump" else 0x95
        return bytes([code, o & 0xFF, (o >> 8) & 0xFF, (o >> 16) & 0xFF])
    if op == "AllocTrack":
        return bytes([0xFE]) + struct.pack("<H", ev["mask"])
    for code, name in NO_ARG_OPS.items():
        if op == name:
            return bytes([code])
    for code, name in U8_ARG_OPS.items():
        if op == name:
            return bytes([code, ev["value"] & 0xFF])
    for code, name in S8_ARG_OPS.items():
        if op == name:
            return bytes([code, _u8_from_s8(ev["value"])])
    for code, name in U16_ARG_OPS.items():
        if op == name:
            return bytes([code]) + struct.pack("<H", ev["value"])
    for code, name in S16_ARG_OPS.items():
        if op == name:
            return bytes([code]) + struct.pack("<h", ev["value"])
    for code, name in VAR_OPS.items():
        if op == name:
            return bytes([code, ev["var_no"]]) + struct.pack("<h", ev["value"])
    if op == "RAW":
        return ev["data"]
    raise SseqError(f"can't encode event {ev!r}")


class Sseq:
    def __init__(self, data, path=None):
        self.path = path
        self.data = data
        if data[0:4] != b"SSEQ":
            raise SseqError(f"bad magic {data[0:4]!r}, expected b'SSEQ'")
        (self.byte_order, self.version, self.file_size, self.header_size,
         self.block_count) = struct.unpack_from("<HHIHH", data, 4)
        if data[0x10:0x14] != b"DATA":
            raise SseqError("expected DATA block at 0x10")
        self.block_size = struct.unpack_from("<I", data, 0x14)[0]
        self.data_offset = struct.unpack_from("<I", data, 0x18)[0]

    def disassemble(self, start=None, end=None):
        """Linear disassembly from `start` (default: data_offset) to `end`
        (default: end of file). Does not follow Jump/Call -- it walks the
        bytes in file order, which matches this format's convention of
        laying tracks out back-to-back in the same order OpenTrack points
        to them. Falls back to one trailing RAW event on the first
        unrecognised opcode, so this never raises and always accounts for
        every byte in [start, end)."""
        data = self.data
        pos = self.data_offset if start is None else start
        stop = len(data) if end is None else end
        events = []
        while pos < stop:
            try:
                ev, new_pos = decode_event(data, pos)
            except (SseqError, IndexError):
                events.append({"op": "RAW", "start": pos, "end": stop,
                                "data": data[pos:stop]})
                pos = stop
                break
            if new_pos > stop:
                events.append({"op": "RAW", "start": pos, "end": stop,
                                "data": data[pos:stop]})
                pos = stop
                break
            events.append(ev)
            pos = new_pos
        return events

    def roundtrip_bytes(self, events):
        return b"".join(encode_event(e) for e in events)

    def verify_roundtrip(self):
        events = self.disassemble()
        original = self.data[self.data_offset:]
        rebuilt = self.roundtrip_bytes(events)
        return rebuilt == original, events

    def coverage(self, events):
        total = len(self.data) - self.data_offset
        raw = sum(len(e["data"]) for e in events if e["op"] == "RAW")
        if total == 0:
            return 1.0
        return 1.0 - (raw / total)


def parse_file(path):
    with open(path, "rb") as fh:
        return Sseq(fh.read(), path=path)


def format_event(ev):
    op = ev["op"]
    if op == "Note":
        return f"  Note       note={ev['note']:3d} vel={ev['velocity']:3d} dur={ev['duration']}"
    if op == "Rest":
        return f"  Rest       dur={ev['duration']}"
    if op == "ProgramChange":
        return f"  ProgramChange patch={ev['patch']}"
    if op == "OpenTrack":
        return f"  OpenTrack  track={ev['track_no']} offset=0x{ev['offset']:X}"
    if op in ("Jump", "Call"):
        return f"  {op:<10} offset=0x{ev['offset']:X}"
    if op == "AllocTrack":
        return f"  AllocTrack mask=0x{ev['mask']:04X}"
    if op == "RAW":
        return f"  RAW        {len(ev['data'])} unparsed bytes at 0x{ev['start']:X}"
    if "value" in ev:
        return f"  {op:<10} value={ev['value']}"
    if "var_no" in ev:
        return f"  {op:<10} var={ev['var_no']} value={ev['value']}"
    return f"  {op}"


def main(argv=None):
    ap = argparse.ArgumentParser(prog="sseq.py",
                                  description="Disassemble an SSEQ sequence's bytecode.")
    ap.add_argument("input", help="path to a raw SSEQ blob, or an SDAT to pull a SEQ from")
    ap.add_argument("--seq-index", type=int, help="SEQ index (when --input is an SDAT)")
    ap.add_argument("--max-events", type=int, default=200)
    ap.add_argument("--verify", action="store_true")
    args = ap.parse_args(argv)

    if args.seq_index is not None:
        s = sdat.parse_file(args.input)
        rec = s.seq_record(args.seq_index)
        if rec is None:
            print(f"[!] SEQ index {args.seq_index} has no record", file=sys.stderr)
            return 1
        raw = s.raw_file(rec["file_id"])
        seq = Sseq(raw)
    else:
        with open(args.input, "rb") as fh:
            seq = Sseq(fh.read())

    events = seq.disassemble()
    print(f"[*] {len(events)} events, data_offset=0x{seq.data_offset:X}, "
          f"coverage={seq.coverage(events):.1%}")
    for ev in events[:args.max_events]:
        print(format_event(ev))
    if len(events) > args.max_events:
        print(f"  ... ({len(events) - args.max_events} more events)")

    if args.verify:
        ok, _ = seq.verify_roundtrip()
        print(f"[*] round trip: {'OK' if ok else 'MISMATCH'}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
