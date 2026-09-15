#!/usr/bin/env python3
"""
sseq2midi.py -- convert a parsed SSEQ (see sseq.py) to a Standard MIDI File
(format 1) for the aletheia asset lane. Stdlib only, written from scratch
for this project.

--------------------------------------------------------------------------
Goal: make the music *audible* with a standard MIDI player/synth, not to
reproduce the DS's actual PCM/ADPCM sample playback (that needs SBNK/SWAV
sample-accurate synthesis -- see "Gaps" below and docs/ASSETS.md).

Track splitting
----------------
sseq.py's `disassemble()` walks the whole file linearly, in file-byte
order. SSEQ's own convention lays multiple tracks out back-to-back in
that same order (track 0's body, immediately followed by whichever track
the next `OpenTrack` names, and so on) -- confirmed structurally in
docs/ASSETS.md's SSEQ section. `get_tracks()` below re-derives track
boundaries from track 0's `AllocTrack`/`OpenTrack` header events (or
treats the whole file as one implicit track 0 when that header is absent,
as seen in short SFX sequences with no `AllocTrack` at all) and slices the
flat event list into one list per track, each producing one MIDI track
(format-1 "one MIDI track per SSEQ track", per the mission brief).

Tick unit
---------
SSEQ note/rest `duration` values are used directly as MIDI delta-ticks,
with the MIDI header's division set to 48 ticks per quarter note. This
is the widely-documented Nitro Composer convention (48 PPQN) for this
sequence format; it was not independently re-derived from this project's
own byte-level SSEQ work (which never needed an absolute tick rate, only
relative event ordering), so treat it as an assumed, not verified,
constant -- same honesty bar as the rest of this lane's opcode table.

Loop handling
-------------
Real SSEQ tracks loop via a backward `Jump` near the end of the track,
back to a point earlier in the same track's own byte range (not via the
`0xD4`/`0xFC` LoopStart/LoopEnd opcodes, which bound a small finite-repeat
region and are left as no-ops here, per the mission brief). This matches
what `sseq.py`'s own doctring already anchors on `SEQ_BGM_DUMMY`. Per
track: intro = events before the loop target, loop_body = events from the
loop target up to (not including) the Jump instruction itself. Output
event stream = intro + loop_body + loop_body (unrolled once, i.e. the
loop plays exactly twice) + TrackEnd. A track with no backward Jump is
emitted as-is (SFX sequences, and any BGM track whose loop convention
this pass didn't recognise) -- see coverage notes below.

Program / channel mapping
--------------------------
`ProgramChange` (opcode 0x81)'s `patch` value is mapped to a MIDI program
number as `patch % 128` (SSEQ patch numbers index a bank's 128-ish-slot
instrument table directly -- see sbnk.py -- so this is a direct, not
General-MIDI-accurate, mapping: it picks *a* program number, not the
"right" GM instrument, since this ROM's own SBNK/SWAV sample data has no
GM equivalent). When an `Sbnk` is supplied (`--bank-index`) and the patch
resolves to a `record_type == 16` (drum kit) instrument, the whole SSEQ
track is routed to MIDI channel 10 (index 9), matching General MIDI's own
percussion-channel convention, and its notes are left un-transposed
(drum maps are keyed by note number, not pitch). Non-drum tracks are
assigned melodic channels 1,2,3,...,9,11,12,...,16 in the order their
first Note event is seen (channel 10 reserved for drums; at most 15
melodic tracks get a distinct channel, further tracks wrap around --
SSEQ allows up to 16 tracks so this can collide on channel reuse for the
rare fully-loaded sequence, documented as a gap below).

**SEQ -> BANK resolution, corrected by a later (sseqsynth) lane.** This
docstring previously claimed `seq_record()` had no valid BANK-table index
and guessed SEQ -> PLAYER -> BANK instead; both were wrong. The real BANK
index turned out to be a direct u16 field in the SEQ INFO record, just
misread here as two separate u8 fields (see `sdat.py`'s `seq_record()`
docstring for the full corrected trace, and `sseqsynth.py`'s module
docstring for the sample-accurate renderer this mistake was found and
fixed for). `seq_record()` now returns it as `rec["bank"]`, resolved for
940/940 populated SEQ records, so `convert()`/`main()` below now resolve it
automatically when `--bank-index` is omitted; that flag still exists for
callers who want to force a different BANK than the SEQ record's own.

Other opcodes mapped to MIDI:
    Pan (0xC0)          -> CC 10 (SSEQ 0-127, 64=center; same range as MIDI)
    Volume (0xC1)        -> CC 7
    Expression (0xD5)    -> CC 11
    Transpose (0xC3)     -> added to subsequent Note values in this track
                             (not a MIDI event; MIDI has no track-transpose
                             message)
    PitchBend (0xC4, s8) -> MIDI pitch wheel, scaled into the 14-bit range
                             (`value * 128 + 8192`, clamped)
    Tempo (0xE1)         -> tempo meta event (BPM -> microseconds/quarter)

Left as no-ops (per the mission brief and this format's own scope):
MasterVolume, PitchBendRange, Priority, Tie, Portamento*, Mod*, ADSR
(Attack/Decay/Sustain/Release), LoopStart/LoopEnd's repeat-count semantics,
SweepPitch, ModDelay, all `0xB0`-`0xBD` variable ops, `Call`/`Return`
(rare; treated as a track-ending gap, see below), and any `RAW` fallback
event (an unrecognised opcode -- see sseq.py's own coverage notes;
playback for that track simply stops there, same honesty convention as
the rest of this lane).

Round trip / verification
--------------------------
`read_midi()` below is a minimal, from-scratch SMF reader (not reusing any
other project's MIDI code) used only to verify this module's own output:
it re-parses a written .mid file and reports track count, per-track note
count, and the first tempo meta event found, which `main()` prints per
file for the mission's "verify each file" requirement.
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import sbnk  # noqa: E402
import sdat  # noqa: E402
import sseq  # noqa: E402

TICKS_PER_QUARTER = 48
DRUM_CHANNEL = 9  # MIDI channel 10, 0-indexed
MELODIC_CHANNELS = [0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 15]


class MidiError(Exception):
    pass


# ---------------------------------------------------------------------------
# SSEQ -> per-track event list, with track boundaries + loop unrolling
# ---------------------------------------------------------------------------

def get_tracks(seq):
    """Split seq.disassemble()'s flat event list into per-track event lists
    using AllocTrack/OpenTrack (or a single implicit track 0 when absent).
    Returns a list of dicts: {track_no, start, end, events}, sorted by
    start offset (ascending file order, which is track playback order)."""
    events = seq.disassemble()
    open_tracks = {0: None}  # track_no -> start offset; track 0 filled below
    header_end = seq.data_offset
    for ev in events:
        if ev["op"] == "AllocTrack":
            header_end = ev["end"]
            continue
        if ev["op"] == "OpenTrack":
            open_tracks[ev["track_no"]] = ev["offset"]
            header_end = ev["end"]
            continue
        break  # first non-header event: header_end is now correct
    open_tracks[0] = header_end
    bounds = sorted((off, tno) for tno, off in open_tracks.items())
    tracks = []
    for i, (start, tno) in enumerate(bounds):
        end = bounds[i + 1][0] if i + 1 < len(bounds) else len(seq.data)
        tev = [e for e in events if start <= e["start"] < end]
        tracks.append({"track_no": tno, "start": start, "end": end, "events": tev})
    tracks.sort(key=lambda t: t["track_no"])
    return tracks


def unroll_loop(track_events, track_start):
    """Find a backward Jump within this track's own event list (a Jump
    whose target offset is >= track_start and < the Jump's own position --
    i.e. a loop back into earlier material in this same track, not a
    forward skip or a jump into another track). Returns a new event list
    with intro + loop_body*2 + trailing TrackEnd if found; otherwise the
    original event list unchanged."""
    jump_idx = None
    for i, ev in enumerate(track_events):
        if ev["op"] == "Jump" and track_start <= ev["offset"] < ev["start"]:
            jump_idx = i
            break
    if jump_idx is None:
        return track_events
    jump_ev = track_events[jump_idx]
    loop_target = jump_ev["offset"]
    intro = [e for e in track_events if e["start"] < loop_target]
    loop_body = [e for e in track_events if loop_target <= e["start"] < jump_ev["start"]]
    return intro + loop_body + loop_body + [{"op": "TrackEnd"}]


# ---------------------------------------------------------------------------
# MIDI file writing (from scratch: VLQ deltas, MThd/MTrk chunks)
# ---------------------------------------------------------------------------

def write_vlq(val):
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


def tempo_meta(bpm):
    if bpm <= 0:
        bpm = 120
    usec = round(60_000_000 / bpm)
    usec = max(1, min(usec, 0xFFFFFF))
    return b"\xFF\x51\x03" + usec.to_bytes(3, "big")


def build_track_events(track, sbnk_obj, channel):
    """Simulate one SSEQ track's event stream into a list of
    (abs_tick, sort_key, midi_bytes) tuples. `channel` is the MIDI channel
    (0-15) this whole track is pinned to (this lane assigns one channel per
    SSEQ track, not per-note)."""
    out = []
    abs_tick = 0
    transpose = 0
    last_tick = 0
    program_is_drum = False
    for ev in track["events"]:
        op = ev["op"]
        if op == "Note":
            note = max(0, min(127, ev["note"] + (0 if program_is_drum else transpose)))
            vel = max(1, min(127, ev["velocity"]))
            dur = max(0, ev["duration"])
            out.append((abs_tick, 3, bytes([0x90 | channel, note, vel])))
            out.append((abs_tick + dur, 0, bytes([0x80 | channel, note, 0])))
            abs_tick += dur
        elif op == "Rest":
            abs_tick += max(0, ev["duration"])
        elif op == "ProgramChange":
            patch = ev["patch"] % 128
            if sbnk_obj is not None:
                inst = None
                if 0 <= ev["patch"] < len(sbnk_obj.instruments):
                    inst = sbnk_obj.instruments[ev["patch"]]
                program_is_drum = inst is not None and inst.rec_type == 16
            out.append((abs_tick, 2, bytes([0xC0 | channel, patch])))
        elif op == "Pan":
            out.append((abs_tick, 2, bytes([0xB0 | channel, 10, ev["value"] & 0x7F])))
        elif op == "Volume":
            out.append((abs_tick, 2, bytes([0xB0 | channel, 7, ev["value"] & 0x7F])))
        elif op == "Expression":
            out.append((abs_tick, 2, bytes([0xB0 | channel, 11, ev["value"] & 0x7F])))
        elif op == "Transpose":
            transpose = ev["value"]
        elif op == "PitchBend":
            bend = max(0, min(16383, ev["value"] * 128 + 8192))
            out.append((abs_tick, 2, bytes([0xE0 | channel, bend & 0x7F, (bend >> 7) & 0x7F])))
        elif op == "Tempo":
            out.append((abs_tick, 1, tempo_meta(ev["value"])))
        elif op in ("TrackEnd", "LoopEnd", "Return", "RAW", "Call", "Jump"):
            break  # end of what this lane renders for this track
        # everything else: documented no-op (Mod*, ADSR, Portamento*,
        # MasterVolume, PitchBendRange, Priority, Tie, SweepPitch, ModDelay,
        # LoopStart's repeat count, VAR_OPS, AllocTrack/OpenTrack)
        last_tick = max(last_tick, abs_tick)
    return out, last_tick


def build_midi(seq, sbnk_obj=None, default_bpm=120):
    """Build a format-1 Standard MIDI File from a parsed Sseq. Returns
    (bytes, stats) where stats is a dict with per-track note counts, first
    tempo found (BPM), and track count, for the caller's own verification
    report."""
    tracks = get_tracks(seq)
    used_channels = 0
    stats = {"tracks": [], "tempo_bpm": None}
    midi_tracks = []
    for track in tracks:
        events = unroll_loop(track["events"], track["start"])
        # peek for a drum instrument to pin the channel before simulating
        is_drum = False
        if sbnk_obj is not None:
            for ev in events:
                if ev["op"] == "ProgramChange" and 0 <= ev["patch"] < len(sbnk_obj.instruments):
                    if sbnk_obj.instruments[ev["patch"]].rec_type == 16:
                        is_drum = True
                    break
        if is_drum:
            channel = DRUM_CHANNEL
        else:
            channel = MELODIC_CHANNELS[used_channels % len(MELODIC_CHANNELS)]
            used_channels += 1
        raw_events, last_tick = build_track_events({"events": events}, sbnk_obj, channel)
        note_count = sum(1 for _, prio, _ in raw_events if prio == 3)
        for _, _, data in raw_events:
            if data[:3] == b"\xFF\x51\x03" and stats["tempo_bpm"] is None:
                usec = int.from_bytes(data[3:6], "big")
                stats["tempo_bpm"] = round(60_000_000 / usec, 2)
        stats["tracks"].append({"track_no": track["track_no"], "channel": channel,
                                 "notes": note_count, "ticks": last_tick})
        midi_tracks.append(_encode_mtrk(raw_events, last_tick))
    if stats["tempo_bpm"] is None:
        stats["tempo_bpm"] = default_bpm
        # inject a default tempo at the very start of track 0 so playback
        # has a defined tempo even if the SSEQ never set one explicitly
        default_meta = tempo_meta(default_bpm)
        if midi_tracks:
            midi_tracks[0] = _encode_mtrk(
                [(0, 1, default_meta)] +
                [(t, p, d) for (t, p, d) in _decode_mtrk_deltas(midi_tracks[0])],
                stats["tracks"][0]["ticks"] if stats["tracks"] else 0)
    header = b"MThd" + struct.pack(">IHHH", 6, 1, len(midi_tracks), TICKS_PER_QUARTER)
    stats["track_count"] = len(midi_tracks)
    return header + b"".join(midi_tracks), stats


def _encode_mtrk(events, last_tick):
    events = sorted(events, key=lambda e: (e[0], e[1]))
    end_tick = max(last_tick, events[-1][0] if events else 0)
    body = bytearray()
    prev = 0
    for tick, _prio, data in events:
        delta = max(0, tick - prev)
        body += write_vlq(delta)
        body += data
        prev = tick
    body += write_vlq(max(0, end_tick - prev))
    body += b"\xFF\x2F\x00"  # end of track
    return b"MTrk" + struct.pack(">I", len(body)) + bytes(body)


def _decode_mtrk_deltas(mtrk_bytes):
    """Internal helper for the default-tempo injection above: re-expand one
    already-built MTrk chunk back into (abs_tick, priority, data) tuples
    (dropping the trailing End-of-Track meta, which _encode_mtrk re-adds)."""
    body = mtrk_bytes[8:]
    pos = 0
    tick = 0
    out = []
    while pos < len(body):
        val = 0
        while True:
            b = body[pos]
            pos += 1
            val = (val << 7) | (b & 0x7F)
            if not (b & 0x80):
                break
        tick += val
        status = body[pos]
        if status == 0xFF:
            mtype = body[pos + 1]
            length = body[pos + 2]
            data = body[pos:pos + 3 + length]
            pos += 3 + length
            if mtype == 0x2F:
                break
            out.append((tick, 1, data))
        else:
            data = body[pos:pos + 3]
            pos += 3
            out.append((tick, 2, data))
    return out


# ---------------------------------------------------------------------------
# Minimal SMF reader, for this module's own output verification
# ---------------------------------------------------------------------------

def read_midi(path):
    """Parse a .mid file written by this module (or any format-0/1 SMF with
    plain delta-time VLQs and no running-status compression, which is what
    build_midi() above always emits) and report division, track count,
    per-track note-on count, and the first tempo meta event's BPM."""
    with open(path, "rb") as fh:
        data = fh.read()
    if data[0:4] != b"MThd":
        raise MidiError("not an MThd file")
    hlen, fmt, ntrks, division = struct.unpack_from(">IHHH", data, 4)
    pos = 8 + hlen
    tracks = []
    tempo_bpm = None
    for _ in range(ntrks):
        if data[pos:pos + 4] != b"MTrk":
            raise MidiError(f"expected MTrk at 0x{pos:X}")
        tlen = struct.unpack_from(">I", data, pos + 4)[0]
        body = data[pos + 8:pos + 8 + tlen]
        pos += 8 + tlen
        p = 0
        note_on = 0
        running_status = None
        while p < len(body):
            val = 0
            while True:
                b = body[p]
                p += 1
                val = (val << 7) | (b & 0x7F)
                if not (b & 0x80):
                    break
            status = body[p]
            if status < 0x80:
                if running_status is None:
                    raise MidiError("running status with no prior status byte")
                status = running_status
            else:
                p += 1
                running_status = status if status < 0xF0 else running_status
            if status == 0xFF:
                mtype = body[p]
                length = body[p + 1]
                mdata = body[p + 2:p + 2 + length]
                p += 2 + length
                if mtype == 0x51 and tempo_bpm is None:
                    usec = int.from_bytes(mdata, "big")
                    tempo_bpm = round(60_000_000 / usec, 2) if usec else None
            elif status in (0xF0, 0xF7):
                length = body[p]
                p += 1 + length
            elif 0x80 <= status < 0xC0 or 0xE0 <= status < 0xF0:
                if status >= 0x90 and status < 0xA0 and body[p + 1] != 0:
                    note_on += 1
                p += 2
            else:
                p += 1
        tracks.append(note_on)
    return {"division": division, "track_count": ntrks, "notes_per_track": tracks,
            "tempo_bpm": tempo_bpm}


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def convert(sdat_obj, seq_index, bank_index=None):
    rec = sdat_obj.seq_record(seq_index)
    if rec is None:
        raise MidiError(f"SEQ index {seq_index} has no record")
    raw = sdat_obj.raw_file(rec["file_id"])
    seq = sseq.Sseq(raw)
    if bank_index is None:
        bank_index = rec["bank"]  # auto-resolved, see module docstring
    bnk = None
    if bank_index is not None:
        brec = sdat_obj.bank_record(bank_index)
        if brec is not None:
            bnk = sbnk.Sbnk(sdat_obj.raw_file(brec["file_id"]))
            bnk.parse_all_details()
    return build_midi(seq, sbnk_obj=bnk)


def main(argv=None):
    ap = argparse.ArgumentParser(
        prog="sseq2midi.py",
        description="Convert an SSEQ (raw or from an SDAT) to a Standard MIDI File.")
    ap.add_argument("input", help="path to a raw SSEQ blob, or an SDAT to pull a SEQ from")
    ap.add_argument("--seq-index", type=int, help="SEQ index (when --input is an SDAT)")
    ap.add_argument("--bank-index", type=int,
                     help="BANK index for program-number/drum-channel mapping "
                          "(optional -- auto-resolved from the SEQ record's own "
                          "bank field when omitted, see module docstring)")
    ap.add_argument("-o", "--output", required=True, help="output .mid path")
    ap.add_argument("--verify", action="store_true", help="read the .mid back and report")
    args = ap.parse_args(argv)

    if args.seq_index is not None:
        s = sdat.parse_file(args.input)
        midi_bytes, stats = convert(s, args.seq_index, args.bank_index)
    else:
        with open(args.input, "rb") as fh:
            seq = sseq.Sseq(fh.read())
        bnk = None
        if args.bank_index is not None:
            print("[!] --bank-index requires --input to be an SDAT; ignoring", file=sys.stderr)
        midi_bytes, stats = build_midi(seq, sbnk_obj=bnk)

    out_dir = os.path.dirname(args.output)
    if out_dir:
        os.makedirs(out_dir, exist_ok=True)
    with open(args.output, "wb") as fh:
        fh.write(midi_bytes)

    total_notes = sum(t["notes"] for t in stats["tracks"])
    print(f"[*] wrote {args.output}: {stats['track_count']} tracks, "
          f"tempo={stats['tempo_bpm']} BPM, {total_notes} notes total")
    for t in stats["tracks"]:
        print(f"    track {t['track_no']:2d} -> ch{t['channel']+1:2d}  "
              f"{t['notes']:5d} notes  {t['ticks']:6d} ticks")

    if args.verify:
        readback = read_midi(args.output)
        rb_notes = sum(readback["notes_per_track"])
        print(f"[*] verify: {readback['track_count']} tracks, "
              f"division={readback['division']}, tempo={readback['tempo_bpm']} BPM, "
              f"{rb_notes} notes total (read back)")
        if rb_notes != total_notes or readback["track_count"] != stats["track_count"]:
            print("[!] MISMATCH between written stats and read-back stats", file=sys.stderr)
            return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
