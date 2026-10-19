#!/usr/bin/env python3
"""white_align.py -- relocation-wildcard masking for comparing two builds of the same code.

Masks branch displacements (ARM B/BL/BLX immediate, Thumb BL/BLX pairs, including a pair
that straddles a word boundary) and address-like words (RAM, TCM, IO, VRAM pointers) so a
code block that only moved compares equal.  Stdlib only.
"""
import struct


def _first(h):
    return 0xF000 <= h <= 0xF7FF


def _second(h):
    return 0xE800 <= h <= 0xEFFF or 0xF800 <= h <= 0xFFFF


def _addr_like(w):
    return (0x01FF0000 <= w < 0x02800000 or 0x02FE0000 <= w < 0x03000000
            or 0x03800000 <= w < 0x03810000 or 0x04000000 <= w < 0x04100000
            or 0x06000000 <= w < 0x06A00000)


def mask_words(data):
    """Return a list of masked 32-bit words, one per aligned word of `data`."""
    n = len(data) // 4
    ws = struct.unpack('<%dI' % n, data[:n * 4])
    out = []
    prev_hi = 0
    for w in ws:
        lo, hi = w & 0xFFFF, w >> 16
        if _first(lo) and _second(hi):
            m = 0xF800 | (0xF800 << 16)
        elif (w >> 25) & 7 == 5:
            m = w & 0xFF000000
        else:
            m = w
            if _first(prev_hi) and _second(lo):
                lo &= 0xF800
                m = lo | (hi << 16)
            if _first(hi):
                hi &= 0xF800
                m = (m & 0xFFFF) | (hi << 16)
            if m == w and _addr_like(w):
                m = 0xADD00000
        prev_hi = hi if not (_first(lo) and _second(hi)) else 0
        out.append(m)
    return out
