#!/usr/bin/env python3
"""
adpcm.py -- IMA-ADPCM codec for the aletheia asset lane's SWAV decoder.

This is the standard reference IMA-ADPCM algorithm (the same step/index
table and greedy-nibble-selection state machine documented publicly for
the format going back to the original 1992 IMA specification and used
verbatim by countless platforms, including the Nitro sound library's SWAV
wave format). Nothing here is sourced from another decomp project; the
table values and the encode/decode state machine are the standard public
IMA-ADPCM algorithm, re-typed from well-known first principles (4-bit
code = sign bit + 3 magnitude bits against a 89-entry exponential step
table, with a 16-entry index-adjustment table).

Used by tools/assets/swav.py to decode SWAV wave-type-2 (IMA-ADPCM)
samples to PCM16, and to re-encode PCM16 back to ADPCM nibbles to verify
the round trip byte-for-byte against the original sample data.
"""

STEP_TABLE = [
    7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23, 25, 28, 31,
    34, 37, 41, 45, 50, 55, 60, 66, 73, 80, 88, 97, 107, 118, 130, 143,
    157, 173, 190, 209, 230, 253, 279, 307, 337, 371, 408, 449, 494, 544, 598, 658,
    724, 796, 876, 963, 1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066, 2272, 2499, 2749, 3024,
    3327, 3660, 4026, 4428, 4871, 5358, 5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487, 12635, 13899,
    15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767,
]

INDEX_TABLE = [-1, -1, -1, -1, 2, 4, 6, 8, -1, -1, -1, -1, 2, 4, 6, 8]


def _clamp(v, lo, hi):
    return lo if v < lo else hi if v > hi else v


def decode_block(data, initial_predictor, initial_index, sample_count):
    """Decode `sample_count` IMA-ADPCM samples (packed 2 nibbles/byte, low
    nibble first) starting at the first sample AFTER the 4-byte SWAV block
    header (the header's predictor/index seed the state machine but are
    not themselves decoded samples). Returns a list of s16 PCM samples,
    NOT including the header's seed sample (matches how SWAV stores it:
    the header predictor is sample -1 / the loop-in value, actual audio
    samples start at nibble 0)."""
    predictor = initial_predictor
    index = initial_index
    out = []
    nibble_i = 0
    byte_i = 0
    while len(out) < sample_count:
        byte = data[byte_i]
        nibble = byte & 0xF if nibble_i == 0 else (byte >> 4) & 0xF
        predictor, index = _step(predictor, index, nibble)
        out.append(predictor)
        if nibble_i == 0:
            nibble_i = 1
        else:
            nibble_i = 0
            byte_i += 1
    return out


def _step(predictor, index, nibble):
    step = STEP_TABLE[index]
    diffq = step >> 3
    if nibble & 4:
        diffq += step
    if nibble & 2:
        diffq += step >> 1
    if nibble & 1:
        diffq += step >> 2
    if nibble & 8:
        predictor -= diffq
    else:
        predictor += diffq
    predictor = _clamp(predictor, -32768, 32767)
    index = _clamp(index + INDEX_TABLE[nibble], 0, len(STEP_TABLE) - 1)
    return predictor, index


def _greedy_nibble(diff, step):
    """Standard successive-approximation nibble choice for a given signed
    difference and step size (no clamp awareness)."""
    sign = 8 if diff < 0 else 0
    d = abs(diff)
    nib = 0
    if d >= step:
        nib |= 4
        d -= step
    half = step >> 1
    if d >= half:
        nib |= 2
        d -= half
    quarter = step >> 2
    if d >= quarter:
        nib |= 1
    return nib | sign


def encode_block(samples, initial_predictor, initial_index):
    """Encode PCM16 samples to IMA-ADPCM nibbles (packed 2/byte, low
    nibble first) using the standard greedy reference encoder: the same
    deterministic state machine as the decoder, choosing each nibble by
    successive-approximation against the step table rather than search.
    Returns (bytes, final_predictor, final_index).

    **Saturated-target search, confirmed against real data, not guessed**
    (see tools/assets/swav.py's round-trip verification and
    docs/ASSETS.md): plain successive approximation on `diff = target -
    predictor` is what the original encoder used almost everywhere (all
    but 38 of this ROM's 5400 real WAVARC ADPCM samples matched it
    directly), but whenever the target sample is already pinned to the
    s16 range's extreme (-32768 or 32767 -- i.e. the source audio clipped)
    the original encoder instead picked whichever of the 16 possible
    nibbles, after `_step()`'s clamp, lands the resulting predictor
    closest to that extreme -- not necessarily the plain greedy nibble.
    Two concrete failure shapes were found and both fit this one rule:

    1. `diff == 0` exactly (predictor already sitting at the clamp): the
       greedy magnitude is identical for both signs, so a naive encoder
       must pick a fixed default; the "subtract" nibble happens to stay
       clamped at the target (zero error) while "add" moves away from
       it, and the original encoder always chose "subtract" here.
    2. `diff != 0` but very close to a quarter-step rounding boundary
       (one real sample had `d` one unit short of `quarter`, so greedy
       correctly left the low bit clear by its own rule) where the
       *greedy* nibble leaves the predictor far from the clamped target,
       but a different nibble's clamped result lands exactly on it.

    Both are instances of "the encoder didn't need to be accurate here,
    it just needed to hit the clamp" -- a real encoder can get this
    almost for free by trying all 16 codes only in the rare case the
    target is already saturated, which is what this does. Off the clamp
    boundary this is never invoked and behaviour is unchanged (plain
    greedy, matching the original encoder in every non-saturated case
    checked)."""
    predictor = initial_predictor
    index = initial_index
    nibbles = []
    for s in samples:
        diff = s - predictor
        step = STEP_TABLE[index]

        if s in (-32768, 32767):
            best_nib = None
            best_err = None
            for cand in range(16):
                pred_cand, _ = _step(predictor, index, cand)
                err = abs(pred_cand - s)
                if best_err is None or err < best_err:
                    best_err = err
                    best_nib = cand
            # Tie-break toward the plain greedy choice, matching every
            # real sample checked where more than one nibble achieved
            # the same minimal error.
            greedy = _greedy_nibble(diff, step)
            pred_greedy, _ = _step(predictor, index, greedy)
            nib = greedy if abs(pred_greedy - s) == best_err else best_nib
        else:
            nib = _greedy_nibble(diff, step)
        predictor, index = _step(predictor, index, nib)
        nibbles.append(nib)

    out = bytearray()
    for i in range(0, len(nibbles) - 1, 2):
        out.append(nibbles[i] | (nibbles[i + 1] << 4))
    if len(nibbles) % 2 == 1:
        out.append(nibbles[-1])
    return bytes(out), predictor, index
