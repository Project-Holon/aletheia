#!/usr/bin/env python3
"""
sseqsynth.py -- sample-based SSEQ renderer for the aletheia asset lane.
Stdlib only, written from scratch for this project. Produces real-timbre
`.wav` files (this ROM's own SWAV samples, not a generic MIDI synth) from
`wb_sound_data.sdat`'s SSEQ sequences.

--------------------------------------------------------------------------
(1) SEQ -> BANK resolution
--------------------------------------------------------------------------
Settled this pass, in `sdat.py`'s `seq_record()` (see that method's
docstring for the full byte-level trace): the SEQ INFO record carries a
**direct** BANK-table index at bytes +4:+6 (u16 LE), no PLAYER indirection
needed. This corrects the previous lane's conclusion (which read those 2
bytes as separate u8 "volume"/"channel_pressure" fields and, finding no
usable BANK reference, guessed SEQ -> PLAYER -> BANK instead).

The PLAYER hypothesis was tested directly and is a dead end: all 7 of this
SDAT's PLAYER INFO records were decoded this pass (`sdat.py`'s
`player_record()`) as `u8 seq_max, u8 pad, u16 channel_bitmask, u32
heap_size` -- 8 bytes, confirmed by every record producing a plausible
small `seq_max` (1 for all 7) and a small number of distinct `heap_size`
buckets (0, 2000, 10200), with no field anywhere that could index a
1986-slot BANK table. PLAYER selects a channel/heap allocation group
(`PLAYER_BGM`, `PLAYER_SE_PSG`, ...), not an instrument bank.

With bytes +4:+6 reread as one u16, **940/940 (100%)** of populated SEQ
records resolve to a real `bank_record()` (verified programmatically, not
just spot-checked), and the resolved BANK's SYMB name matches the SEQ's own
name for every case sampled: `SEQ_BGM_TITLE` -> `BANK_MUS_WB_TITLE`,
`SEQ_BGM_GYM` -> `BANK_MUS_WB_GYM`, `SEQ_BGM_VS_NORAPOKE` ->
`BANK_MUS_WB_VS_NORAPOKE`, `SEQ_SE_MESSAGE` -> `BANK_SE_WB_MESSAGE`, and
`SEQ_PV001` (a 1-note, 8-event sequence -- Tempo, ProgramChange, Volume,
Pan, one Note at pitch 60 dur 0, TrackEnd -- exactly the shape of a cry
trigger, not a real melody) -> `BANK_PV001`. That last one is this pass's
"known cry-bearing sequence" verification the mission asked for: BANK_PV001
resolves through its own `wave_arc[0]` to WAVARC 1, a real one-shot PCM/
ADPCM sample, and `--verify-cry` below renders it end to end through this
same code path used for BGM.

--------------------------------------------------------------------------
(2) Voice model
--------------------------------------------------------------------------
Per SSEQ track, a small stack-based bytecode interpreter (not a linear
disassemble-then-schedule pass like sseq2midi.py -- this one actually
executes `Jump`/`Call`/`Return` as control flow, per the mission brief)
walks `sseq.decode_event()` from each track's `OpenTrack`-declared start
offset, maintaining: absolute tick, current `ProgramChange` patch, Volume/
Expression/Pan/Transpose. Every `Note` event records a (tick, note,
velocity, patch, volume, expression, pan) tuple and advances the track's
own tick counter by the note's duration (matching this format's own
"note duration also gates the next event" convention, same as
sseq2midi.py). `Jump` is followed for real: a forward jump (target > here)
is taken unconditionally (safe, monotonic, can't loop); a backward jump
(the real-SSEQ loop idiom, per sseq2midi.py's own docstring) is taken once
per mission brief ("render one loop plus one repeat") and refused the
second time it's reached, ending that track. `Call`/`Return` push/pop a
real return-address stack. `0xA0`/`0xA1`/`0xA2` (Random/GetVariable/If) are
treated as no-ops per the mission brief: since this project's own SSEQ
opcode table (see sseq.py) never reverse-engineered their argument shapes
(genuinely undocumented in this codebase), they're skipped by a best-effort
fixed byte count (5/2/1 bytes respectively, the commonly-cited public sizes
for Rand's s16/s16 range, GetVariable's u8 var number, and If's bare
opcode) rather than by re-deriving their real layout -- a labelled
approximation, not a verified decode (see "Known inaccuracies" below). Any
other unrecognised opcode still ends that track's render at that point,
the same honest fallback `sseq.py`/`sseq2midi.py` already use.

Per note-on, the instrument is resolved from the bank's `Sbnk` instrument
table at index = current patch number (matching sseq2midi.py's own
program-number convention):
  - type 1 (single-region PCM): its one wave_arc/wave_id/base_note/ADSR/pan
    record is used directly.
  - type 16 (drum kit): one region per note in [low_note, high_note];
    region index = played_note - low_note (clamped) picks the region
    directly.
  - type 17 (key split): the ascending `split_points` list picks the
    first region whose split point is >= the played note (falling back
    to the last region if the note is above every split point) -- the
    standard "key range" split convention.
  - type 0 (empty) / type 2 / type 3 (still-undecoded PSG-shaped types):
    no wave to play; the note is silently dropped (documented gap, not a
    crash).

The resolved region's `wave_arc` is a **local** index (0-3) into the
*owning BANK's own* `wave_arc[4]` table (`sdat.bank_record()`), which
supplies the *global* WAVARC index, whose `wavarc_fileid()` gives the FAT
file ID for the actual `SWAR` archive; `wave_id` then selects the `Swav`
inside it (same pointer chain as the worked Pikachu-cry example in
docs/ASSETS.md, just driven by a real SEQ instead of by hand). `Swar`
parses are cached per global WAVARC index within one render (many notes
share the same wave archive).

Pitch: the SWAV's decoded PCM16 samples are resampled by linear
interpolation at rate `2**((played_note - base_note) / 12) * native_rate /
output_rate` (semitone-ratio pitch shift, standard equal-tempered
resampling). Looping: if the SWAV's `loop_flag` is set, playback past the
loop point wraps back into `[loop_start, total_len)` for as long as the
note needs to sustain; a one-shot (non-looping) SWAV is instead always
played out to at least its own natural length regardless of how short the
SSEQ note's own gate duration is (this matters for cries specifically --
SEQ_PV001's Note has `duration=0`, meaning the *sequence* moves on
immediately, but the cry itself is a one-shot sample meant to ring out on
its own hardware channel independent of the sequencer's own clock; without
this rule the cry would render as near-silence). The loop point itself
(`loop_offset_words`, in 4-byte units of the *encoded* SWAV data) is
converted to a decoded-PCM16 sample index per wave_type: PCM8 has 4
samples/word, PCM16 has 2 samples/word, ADPCM has 8 samples/word minus the
1-word (4-byte) predictor/index seed header that isn't itself a decoded
sample.

Envelope: a simple, deliberately non-authoritative linear ADSR (see "Known
inaccuracies" -- this SBNK field's real curve shape/scale was never
independently pinned down, see sbnk.py's own docstring) built from the
instrument's `attack`/`decay`/`sustain`/`release` u8 fields, byte value
used directly as a fraction of each stage's own max time (attack max
0.15 s, decay max 0.3 s, release max 0.4 s, release floored at 0.02 s to
avoid a zero-length click) -- so a low byte (the overwhelmingly common
case in real regions sampled: attack/decay are 0 or 1 almost everywhere)
means a fast stage. This direction was picked empirically, not from a
spec: the inverse direction (high byte = fast) made ordinary melodic BGM
notes render almost silent, because most regions' attack byte is 0-1 and
note gates are often shorter than a slow attack ramp would need to reach
audible volume. Sustain level is `sustain / 127`. Per-note gain
combines the track's current Volume and Expression (each 0-127, linear,
not the hardware's real dB-style curve -- another documented
approximation) with the SEQ INFO record's own overall `volume` field; pan
(0-127, 64 = center) is a simple linear (not equal-power) left/right
crossfade. Tempo: `Tempo` events (BPM, 0xE1) build a piecewise tempo map
converting ticks to real seconds at 48 ticks/quarter (same assumed Nitro
Composer convention `sseq2midi.py` already uses); the first tempo found
across any track is reported as "master tempo".

Mixing: every note's resampled+enveloped+panned mono waveform is summed
into a float64 stereo buffer at 32768 Hz, then the whole buffer is
peak-normalised down (never up) if it would otherwise clip int16 range,
and a short linear fade-out is applied over its last second (per the
mission brief's "render one loop plus one repeat then fade") before
quantising to 16-bit stereo PCM and writing a standard `.wav`.

--------------------------------------------------------------------------
Known inaccuracies (honest, not hidden)
--------------------------------------------------------------------------
- ADSR curve shape/scale is a guessed linear approximation, not derived
  from real hardware timing -- sbnk.py's own instrument docstring already
  flags attack/decay/sustain/release as "0-127-ish", not independently
  derived. The *direction* assumed here (higher byte = faster stage) is
  itself an assumption, not verified against real playback.
- Volume/Expression/master `volume` combine as plain linear multiplication,
  not the hardware's actual (almost certainly logarithmic/dB) curve.
- Pan is linear crossfade, not equal-power panning.
- Portamento, modulation (ModDepth/ModSpeed/ModType/ModRange/ModDelay),
  SweepPitch, PitchBendRange, and Tie/Mono are documented no-ops here (same
  scope line the mission brief draws) -- pitch bend itself is also not
  applied to the audio (unlike sseq2midi.py's MIDI pitch-wheel mapping,
  there is no equivalent "wheel" concept in a direct sample renderer without
  re-triggering resample ratios mid-note, which this pass does not do).
- `0xA0`/`0xA1`/`0xA2` are skipped by an assumed fixed byte count (see
  "Voice model" above), not a verified argument decode; on the rare file
  where this guess is wrong, bytecode past that point desyncs and the
  track's render ends early (falls into the same "unrecognised opcode"
  stop as any other gap).
- SBNK instrument types 2/3 (still-unidentified; only 51/122 and 124/155
  of their records pass sbnk.py's region-plausibility check, so they are
  not reliably the same wave-bearing shape as 1/16/17) are silently
  dropped -- no wave data is trusted for them.
- `sbnk.py`'s region decode for types 16/17 was corrected this pass (fixed
  field order and a 10-byte, not 12-byte, record -- see sbnk.py's
  docstring): every region of every type-16/17 instrument in this SDAT
  (8700 regions total) now passes the wave_id/wave_arc/note/ADSR
  plausibility check, not just the first region as before, so
  `resolve_instrument_region()` no longer needs a first-region fallback
  for implausible later regions.
- Loop detection only recognises one backward `Jump` per track (same
  limitation as sseq2midi.py); a track that loops through a `Call`/
  `Return` pair or a longer jump chain instead just plays through once.
"""

import argparse
import math
import os
import struct
import sys
import wave as wavemod

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import sbnk  # noqa: E402
import sdat  # noqa: E402
import sseq  # noqa: E402
import swav  # noqa: E402

SAMPLE_RATE = 32768
TICKS_PER_QUARTER = 48
DEFAULT_BPM = 120
MAX_SECONDS_DEFAULT = 30.0
TAIL_PAD_SECONDS = 1.5      # extra buffer past the last note for release tails
FADE_SECONDS = 1.0          # linear fade applied to the render's last second

ATTACK_MAX = 0.15
DECAY_MAX = 0.30
RELEASE_MAX = 0.40
MIN_RELEASE = 0.02

MAX_STEPS_PER_TRACK = 300000
MAX_JUMP_REPEATS = 1        # a backward Jump fires once (loop body plays twice total)
MAX_CALL_DEPTH = 32
MAX_NOTE_SECONDS = 12.0     # safety cap on a single note's own render length


class SynthError(Exception):
    pass


# ---------------------------------------------------------------------------
# Track interpreter: real Jump/Call/Return control flow, per mission brief
# ---------------------------------------------------------------------------

def get_track_starts(data, data_offset):
    """Same header convention as sseq2midi.py's get_tracks(): track 0 opens
    with AllocTrack then a run of OpenTrack commands naming every other
    track's start offset. Returns {track_no: start_offset}."""
    open_tracks = {}
    pos = data_offset
    header_end = data_offset
    while True:
        try:
            ev, new_pos = sseq.decode_event(data, pos)
        except (sseq.SseqError, IndexError):
            break
        if ev["op"] == "AllocTrack":
            header_end = new_pos
            pos = new_pos
            continue
        if ev["op"] == "OpenTrack":
            open_tracks[ev["track_no"]] = ev["offset"]
            header_end = new_pos
            pos = new_pos
            continue
        break
    open_tracks[0] = header_end
    return open_tracks


def run_track(data, start_pc):
    """Execute one track's bytecode as real control flow (Jump/Call/Return),
    per the mission brief. Returns (notes, tempo_events, end_tick) where
    notes is a list of dicts and tempo_events a list of (tick, bpm)."""
    pc = start_pc
    call_stack = []
    tick = 0
    program = 0
    volume, expression, pan, transpose = 127, 127, 64, 0
    notes = []
    tempo_events = []
    jump_visits = {}
    steps = 0
    n = len(data)
    while steps < MAX_STEPS_PER_TRACK:
        steps += 1
        if pc < 0 or pc >= n:
            break
        try:
            ev, new_pc = sseq.decode_event(data, pc)
        except (sseq.SseqError, IndexError):
            b = data[pc] if pc < n else None
            if b == 0xA0:      # Random: assumed s16 min, s16 max -> 5 bytes
                pc += 5
                continue
            if b == 0xA1:      # GetVariable: assumed u8 var_no -> 2 bytes
                pc += 2
                continue
            if b == 0xA2:      # If: bare opcode, treated as unconditional
                pc += 1
                continue
            break  # genuinely unrecognised opcode: end this track's render
        op = ev["op"]
        if op == "Note":
            notes.append({"tick": tick, "dur": ev["duration"],
                           "note": max(0, min(127, ev["note"] + transpose)),
                           "vel": ev["velocity"], "program": program,
                           "volume": volume, "expression": expression, "pan": pan})
            tick += ev["duration"]
            pc = new_pc
        elif op == "Rest":
            tick += ev["duration"]
            pc = new_pc
        elif op == "ProgramChange":
            program = ev["patch"]
            pc = new_pc
        elif op == "Pan":
            pan = ev["value"]
            pc = new_pc
        elif op == "Volume":
            volume = ev["value"]
            pc = new_pc
        elif op == "Expression":
            expression = ev["value"]
            pc = new_pc
        elif op == "Transpose":
            transpose = ev["value"]
            pc = new_pc
        elif op == "Tempo":
            tempo_events.append((tick, ev["value"]))
            pc = new_pc
        elif op == "Jump":
            target = ev["offset"]
            if target > pc:
                pc = target
            else:
                visits = jump_visits.get(pc, 0)
                if visits >= MAX_JUMP_REPEATS:
                    break
                jump_visits[pc] = visits + 1
                pc = target
        elif op == "Call":
            if len(call_stack) >= MAX_CALL_DEPTH:
                break
            call_stack.append(new_pc)
            pc = ev["offset"]
        elif op == "Return":
            if not call_stack:
                break
            pc = call_stack.pop()
        elif op == "TrackEnd":
            break
        else:
            # documented no-op: MasterVolume, PitchBendRange, Priority, Tie,
            # Portamento*, Mod*, ADSR set-commands, LoopStart/LoopEnd,
            # SweepPitch, ModDelay, VAR_OPS, OpenTrack/AllocTrack mid-track,
            # PitchBend
            pc = new_pc
    return notes, tempo_events, tick


def get_tracks(seq):
    starts = get_track_starts(seq.data, seq.data_offset)
    tracks = {}
    for tno, start in starts.items():
        notes, tempo_events, end_tick = run_track(seq.data, start)
        tracks[tno] = {"notes": notes, "tempo_events": tempo_events, "end_tick": end_tick}
    return tracks


# ---------------------------------------------------------------------------
# Tempo map: tick -> seconds
# ---------------------------------------------------------------------------

def build_tempo_map(all_tempo_events, default_bpm=DEFAULT_BPM):
    events = sorted(set(all_tempo_events))
    if not events or events[0][0] != 0:
        events = [(0, default_bpm)] + events
    segments = []
    cur_tick, cur_time, cur_bpm = 0, 0.0, events[0][1]
    for tick, bpm in events[1:]:
        if tick == cur_tick:
            cur_bpm = bpm
            continue
        segments.append((cur_tick, cur_time, cur_bpm))
        seconds_per_tick = 60.0 / (cur_bpm * TICKS_PER_QUARTER)
        cur_time += (tick - cur_tick) * seconds_per_tick
        cur_tick, cur_bpm = tick, bpm
    segments.append((cur_tick, cur_time, cur_bpm))
    return segments


def tick_to_seconds(segments, tick):
    seg = segments[0]
    for s in segments:
        if s[0] <= tick:
            seg = s
        else:
            break
    start_tick, start_time, bpm = seg
    seconds_per_tick = 60.0 / (bpm * TICKS_PER_QUARTER)
    return start_time + (tick - start_tick) * seconds_per_tick


# ---------------------------------------------------------------------------
# Instrument / wave resolution
# ---------------------------------------------------------------------------

def resolve_instrument_region(bnk, program, played_note):
    """type 1 (single-region): its one record is used directly. type 16
    (drum kit): the region table is one entry per note in
    [low_note, high_note], so region index = played_note - low_note,
    clamped to the table -- the standard per-note drum-kit convention.
    type 17 (key split): regions are ordered by ascending split_points
    (verified this pass, see sbnk.py's docstring); the first split point
    >= played_note picks the region, falling back to the last region
    above every split point. Both 16 and 17 now use sbnk.py's corrected,
    100%-plausible region decode (10-byte record, u16 region_type prefix)
    -- no fallback-to-first-region approximation is needed any more."""
    if bnk is None or program < 0 or program >= len(bnk.instruments):
        return None
    inst = bnk.instruments[program]
    if inst.rec_type == 1:
        return inst.detail
    if inst.rec_type == 16:
        regions = inst.detail.get("regions", [])
        if not regions:
            return None
        idx = played_note - inst.detail["low_note"]
        idx = max(0, min(idx, len(regions) - 1))
        return regions[idx]
    if inst.rec_type == 17:
        splits = inst.detail.get("split_points", [])
        regions = inst.detail.get("regions", [])
        if not regions:
            return None
        chosen = None
        for sp, region in zip((s for s in splits if s != 0), regions):
            if played_note <= sp:
                chosen = region
                break
        if chosen is None:
            chosen = regions[-1]
        return chosen
    return None  # type 0 (empty) or 2/3 (undecoded, not reliably wave-shaped)


class WaveCache:
    def __init__(self, sdat_obj):
        self.sdat_obj = sdat_obj
        self._swar_cache = {}

    def get_swar(self, global_wavarc_index):
        if global_wavarc_index in self._swar_cache:
            return self._swar_cache[global_wavarc_index]
        file_id = self.sdat_obj.wavarc_fileid(global_wavarc_index)
        result = None
        if file_id is not None:
            raw = self.sdat_obj.raw_file(file_id)
            result = swav.Swar(raw)
        self._swar_cache[global_wavarc_index] = result
        return result


def resolve_wave(bank_rec, region, cache):
    local_arc = region["wave_arc"]
    wave_arc_table = bank_rec["wave_arc"]
    if local_arc < 0 or local_arc >= len(wave_arc_table):
        return None
    global_arc = wave_arc_table[local_arc]
    if global_arc == 0xFFFF:
        return None
    swar = cache.get_swar(global_arc)
    if swar is None:
        return None
    wave_id = region["wave_id"]
    if wave_id < 0 or wave_id >= len(swar.waves):
        return None
    return swar.waves[wave_id]


def decode_with_loop(w):
    """Decode a Swav to PCM16 samples and translate its loop_offset (in
    4-byte words of the *encoded* data) to a sample index in the decoded
    array. See module docstring's "Voice model" section for the per-type
    words-per-sample conversion."""
    samples = w.decode_pcm16()
    n = len(samples)
    if w.wave_type == swav.WAVE_TYPE_PCM8:
        loop_start = w.loop_offset_words * 4
    elif w.wave_type == swav.WAVE_TYPE_PCM16:
        loop_start = w.loop_offset_words * 2
    else:  # ADPCM: 8 decoded samples/word, minus the 1-word seed header
        loop_start = max(0, (w.loop_offset_words - 1) * 8)
    loop_start = max(0, min(loop_start, n))
    return samples, loop_start, n


# ---------------------------------------------------------------------------
# Envelope
# ---------------------------------------------------------------------------

def adsr_times(region):
    """Byte -> seconds direction picked empirically this pass, not from a
    spec: nearly every real instrument region sampled has attack/decay in
    {0, 1} (i.e. the overwhelmingly common case), which only sounds right
    -- audible melodic notes, not near-silent ones -- if a LOW byte means a
    FAST (short) stage, so byte value is used directly as a fraction of the
    stage's max time (not inverted). This also fits the cry instrument
    (BANK_PV001: attack=127, release=125) needing a long, audible release
    tail after its one-shot sample finishes, not an instant cutoff. Still
    an approximation -- see module docstring's "Known inaccuracies"."""
    attack = region["attack"] / 127.0 * ATTACK_MAX
    decay = region["decay"] / 127.0 * DECAY_MAX
    release = max(MIN_RELEASE, region["release"] / 127.0 * RELEASE_MAX)
    sustain_level = region["sustain"] / 127.0
    return attack, decay, sustain_level, release


def envelope_pre_release(t, attack_s, decay_s, sustain_level):
    if attack_s > 0 and t < attack_s:
        return t / attack_s
    t2 = t - attack_s
    if decay_s > 0 and t2 < decay_s:
        return 1.0 + (sustain_level - 1.0) * (t2 / decay_s)
    return sustain_level


def envelope_value(t, attack_s, decay_s, sustain_level, note_off_t, release_s):
    if t < note_off_t:
        return envelope_pre_release(t, attack_s, decay_s, sustain_level)
    level_at_off = envelope_pre_release(note_off_t, attack_s, decay_s, sustain_level)
    frac = (t - note_off_t) / release_s
    if frac >= 1.0:
        return 0.0
    return level_at_off * (1.0 - frac)


# ---------------------------------------------------------------------------
# Rendering
# ---------------------------------------------------------------------------

def render_note(note, region, w, mix_left, mix_right, sample_rate):
    samples, loop_start, total_len = decode_with_loop(w)
    if total_len == 0:
        return
    base_note = region["base_note"]
    pitch_ratio = 2.0 ** ((note["played_note"] - base_note) / 12.0)
    native_rate = w.sample_rate or 16000
    step = pitch_ratio * native_rate / sample_rate
    if step <= 0:
        return
    loop_flag = bool(w.loop_flag) and loop_start < total_len - 1

    attack_s, decay_s, sustain_level, release_s = adsr_times(region)
    note_off_rel = note["note_off_time"] - note["start_time"]
    if not loop_flag:
        natural_len_s = total_len / step / sample_rate
        note_off_rel = max(note_off_rel, natural_len_s)
    note_off_rel = max(0.0, note_off_rel)
    total_rel = min(MAX_NOTE_SECONDS, note_off_rel + release_s)
    n_out = max(1, int(round(total_rel * sample_rate)))

    pan_norm = max(-1.0, min(1.0, (note["pan"] - 64) / 64.0))
    gain = note["gain"]
    left_gain = gain * min(1.0, 1.0 - pan_norm)
    right_gain = gain * min(1.0, 1.0 + pan_norm)

    start_sample = int(round(note["start_time"] * sample_rate))
    out_len = len(mix_left)
    span = total_len - loop_start

    src_pos = 0.0
    for i in range(n_out):
        out_idx = start_sample + i
        if out_idx >= out_len:
            break
        if out_idx >= 0:
            i0 = int(src_pos)
            if loop_flag and i0 >= loop_start:
                if span > 0:
                    i0 = loop_start + (i0 - loop_start) % span
                else:
                    i0 = total_len - 1
                i1 = i0 + 1
                if i1 >= total_len:
                    i1 = loop_start
            elif i0 >= total_len - 1:
                i0 = total_len - 1
                i1 = total_len - 1
            else:
                i1 = i0 + 1
            frac = src_pos - int(src_pos)
            s0 = samples[i0]
            s1 = samples[i1]
            s = s0 + (s1 - s0) * frac
            t = i / sample_rate
            env = envelope_value(t, attack_s, decay_s, sustain_level, note_off_rel, release_s)
            val = s * env
            mix_left[out_idx] += val * left_gain
            mix_right[out_idx] += val * right_gain
        src_pos += step


def render_seq(sdat_obj, seq_index, bank_override=None, max_seconds=MAX_SECONDS_DEFAULT,
                default_bpm=DEFAULT_BPM):
    rec = sdat_obj.seq_record(seq_index)
    if rec is None:
        raise SynthError(f"SEQ index {seq_index} has no record")
    bank_index = bank_override if bank_override is not None else rec["bank"]
    brec = sdat_obj.bank_record(bank_index)
    bnk = None
    if brec is not None:
        bnk = sbnk.Sbnk(sdat_obj.raw_file(brec["file_id"]))
        bnk.parse_all_details()

    seq_raw = sdat_obj.raw_file(rec["file_id"])
    seq_obj = sseq.Sseq(seq_raw)
    tracks = get_tracks(seq_obj)

    all_tempo_events = []
    for t in tracks.values():
        all_tempo_events.extend(t["tempo_events"])
    tempo_map = build_tempo_map(all_tempo_events, default_bpm)
    master_bpm = tempo_map[0][2] if tempo_map else default_bpm
    if all_tempo_events:
        master_bpm = sorted(all_tempo_events)[0][1]

    cache = WaveCache(sdat_obj)
    seq_volume_gain = rec["volume"] / 127.0 if rec["volume"] else 1.0

    prepared_notes = []
    max_end_time = 0.0
    for t in tracks.values():
        for n in t["notes"]:
            start_time = tick_to_seconds(tempo_map, n["tick"])
            off_time = tick_to_seconds(tempo_map, n["tick"] + n["dur"])
            region = resolve_instrument_region(bnk, n["program"], n["note"])
            if region is None:
                continue
            gain = seq_volume_gain * (n["volume"] / 127.0) * (n["expression"] / 127.0) \
                * (n["vel"] / 127.0)
            prepared_notes.append({
                "start_time": start_time, "note_off_time": off_time,
                "played_note": n["note"], "pan": n["pan"], "gain": gain,
                "region": region,
            })
            max_end_time = max(max_end_time, off_time)

    total_seconds = min(max_seconds, max_end_time + TAIL_PAD_SECONDS) if prepared_notes else 0.5
    total_seconds = max(total_seconds, 0.25)
    n_samples = int(math.ceil(total_seconds * SAMPLE_RATE))
    mix_left = [0.0] * n_samples
    mix_right = [0.0] * n_samples

    notes_rendered = 0
    notes_dropped = 0
    for note in prepared_notes:
        if note["start_time"] * SAMPLE_RATE >= n_samples:
            notes_dropped += 1
            continue
        w = resolve_wave(brec, note["region"], cache) if brec is not None else None
        if w is None:
            notes_dropped += 1
            continue
        render_note(note, note["region"], w, mix_left, mix_right, SAMPLE_RATE)
        notes_rendered += 1

    peak = 0.0
    for v in mix_left:
        av = abs(v)
        if av > peak:
            peak = av
    for v in mix_right:
        av = abs(v)
        if av > peak:
            peak = av
    if peak > 32000.0:
        scale = 32000.0 / peak
        mix_left = [v * scale for v in mix_left]
        mix_right = [v * scale for v in mix_right]
        peak = 32000.0

    fade_samples = min(n_samples, int(FADE_SECONDS * SAMPLE_RATE))
    if fade_samples > 0:
        for i in range(fade_samples):
            idx = n_samples - fade_samples + i
            mult = 1.0 - (i / fade_samples)
            mix_left[idx] *= mult
            mix_right[idx] *= mult

    pcm = bytearray(n_samples * 4)
    for i in range(n_samples):
        lv = int(max(-32768, min(32767, round(mix_left[i]))))
        rv = int(max(-32768, min(32767, round(mix_right[i]))))
        struct.pack_into("<hh", pcm, i * 4, lv, rv)

    stats = {
        "seq_index": seq_index, "bank_index": bank_index,
        "bank_source": "seq_record" if bank_override is None else "override",
        "duration_seconds": total_seconds, "master_bpm": master_bpm,
        "note_events_total": sum(len(t["notes"]) for t in tracks.values()),
        "notes_rendered": notes_rendered, "notes_dropped": notes_dropped,
        "track_count": len(tracks), "peak_amplitude": peak,
    }
    return bytes(pcm), stats


def write_wav(path, pcm_bytes, sample_rate=SAMPLE_RATE):
    out_dir = os.path.dirname(path)
    if out_dir:
        os.makedirs(out_dir, exist_ok=True)
    with wavemod.open(path, "wb") as wf:
        wf.setnchannels(2)
        wf.setsampwidth(2)
        wf.setframerate(sample_rate)
        wf.writeframes(pcm_bytes)


# ---------------------------------------------------------------------------
# Sanity checks (mission requirement: non-silent, peak not clipped, note
# events consumed)
# ---------------------------------------------------------------------------

def sanity_check(pcm_bytes, stats):
    n = len(pcm_bytes) // 4
    peak = 0
    nonzero = 0
    for i in range(n):
        lv, rv = struct.unpack_from("<hh", pcm_bytes, i * 4)
        for v in (lv, rv):
            av = abs(v)
            if av > peak:
                peak = av
            if av > 200:
                nonzero += 1
    non_silent = nonzero > (n * 0.01)
    not_clipped = peak < 32767
    events_consumed = stats["notes_rendered"] > 0
    return {"non_silent": non_silent, "not_clipped": not_clipped,
            "events_consumed": events_consumed, "measured_peak": peak,
            "audible_fraction": nonzero / (2 * n) if n else 0.0}


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main(argv=None):
    ap = argparse.ArgumentParser(
        prog="sseqsynth.py",
        description="Render an SSEQ sequence to a real-timbre .wav using its SWAV samples.")
    ap.add_argument("input", help="path to wb_sound_data.sdat")
    ap.add_argument("--seq-index", type=int, help="SEQ index")
    ap.add_argument("--seq-name", help="resolve SEQ by SYMB name instead of --seq-index")
    ap.add_argument("--bank-index", type=int,
                     help="override the BANK index instead of the SEQ record's own bank field")
    ap.add_argument("-o", "--output", required=True, help="output .wav path")
    ap.add_argument("--max-seconds", type=float, default=MAX_SECONDS_DEFAULT)
    ap.add_argument("--verify", action="store_true", help="run sanity checks and report")
    args = ap.parse_args(argv)

    s = sdat.parse_file(args.input)
    if args.seq_name:
        names = s.names_for("SEQ")
        try:
            seq_index = names.index(args.seq_name)
        except ValueError:
            print(f"[!] SEQ name {args.seq_name!r} not found", file=sys.stderr)
            return 1
    elif args.seq_index is not None:
        seq_index = args.seq_index
    else:
        print("[!] pass --seq-index or --seq-name", file=sys.stderr)
        return 1

    pcm, stats = render_seq(s, seq_index, bank_override=args.bank_index,
                              max_seconds=args.max_seconds)
    write_wav(args.output, pcm)
    print(f"[*] wrote {args.output}: {stats['duration_seconds']:.2f}s, "
          f"bank={stats['bank_index']} ({stats['bank_source']}), "
          f"tempo={stats['master_bpm']} BPM, tracks={stats['track_count']}, "
          f"notes {stats['notes_rendered']}/{stats['note_events_total']} rendered "
          f"({stats['notes_dropped']} dropped), peak={stats['peak_amplitude']:.0f}/32768")

    if args.verify:
        sc = sanity_check(pcm, stats)
        print(f"[*] sanity: non_silent={sc['non_silent']} not_clipped={sc['not_clipped']} "
              f"events_consumed={sc['events_consumed']} measured_peak={sc['measured_peak']} "
              f"audible_fraction={sc['audible_fraction']:.1%}")
        if not (sc["non_silent"] and sc["not_clipped"] and sc["events_consumed"]):
            print("[!] SANITY CHECK FAILED", file=sys.stderr)
            return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
