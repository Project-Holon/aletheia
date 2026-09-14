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


def encode_block(samples, initial_predictor, initial_index):
    """Encode PCM16 samples to IMA-ADPCM nibbles (packed 2/byte, low
    nibble first) using the standard greedy reference encoder: the same
    deterministic state machine as the decoder, choosing each nibble by
    successive-approximation against the step table rather than search.
    Returns (bytes, final_predictor, final_index)."""
    predictor = initial_predictor
    index = initial_index
    nibbles = []
    for s in samples:
        diff = s - predictor
        sign = 8 if diff < 0 else 0
        if diff < 0:
            diff = -diff
        step = STEP_TABLE[index]
        nib = 0
        diffq = step >> 3
        d = diff
        if d >= step:
            nib |= 4
            d -= step
            diffq += step
        half = step >> 1
        if d >= half:
            nib |= 2
            d -= half
            diffq += half
        quarter = step >> 2
        if d >= quarter:
            nib |= 1
            diffq += quarter
        nib |= sign
        predictor, index = _step(predictor, index, nib)
        nibbles.append(nib)

    out = bytearray()
    for i in range(0, len(nibbles) - 1, 2):
        out.append(nibbles[i] | (nibbles[i + 1] << 4))
    if len(nibbles) % 2 == 1:
        out.append(nibbles[-1])
    return bytes(out), predictor, index
