#!/usr/bin/env python3
"""
ovcrypt.py -- overlay 230's own code decryptor, replayed on the image.

Written from scratch for aletheia. Stdlib only, single file.

Why
---
Overlay 230 (y9 entry 230, RAM 0x02187F00..0x021899A0) keeps most of its
code encrypted in the ROM file.  Its static initialisers decrypt it in place
when FS_LoadOverlay -> FS_StartOverlay runs them, and only then are the
bytes code.  The ARM9 image calls into those decrypted bytes: ica_anime's
func_02011D9C loads ov230 and BLXes 0x021882A0, 0x02188354 and 0x02188390,
which in the ROM bytes are ciphertext.  extract/overlays_dec/y9_0230.bin
keeps the bytes as the ROM holds them (the ROM rebuild needs them; nothing
here changes that file or asm/overlays/ov230.s).  This module replays the
game's decryption on a copy and returns the decrypted view, region
`ov230d`, which delink.py / `ovcrypt.py write` store as extract/ov230d.bin
and `disasm.py ov230d` lists as asm/ov230d/ov230d.s.

The scheme, as read from ov230's code (wave 21, lanes H2 and T)
----------------------------------------------------------------
Every entry of ov230's static-initialiser array (0x02189974..0x0218998C,
five non-zero words) points at a three-instruction entry thunk

    E:   orr  r0, pc, #0         ; r0 = E + 8
         adds r0, r0, #4         ; r0 = E + 12, never zero
         bne  loc_02188A48       ; tail-jump into the decryptor, lr intact

so the decryptor's argument is the table that follows the thunk, at E + 12
(0x02188414 for the first initialiser, func_02188408).  The table is a list
of (start word, end word) pairs ending at a start word of 0.  The decryptor
(loc_02188A48, with its classifier func_02188A0C, its cache flush
func_021889E4 and the three pool words at 0x02188B3C) does, per pair:

    size  = end   - END - BIAS       END  = pool 0x02188B3C (ov230's end)
    addr  = start - BIAS             BIAS = the immediate of `sub r4/r8, #`
    key   = KEY                      KEY  = pool 0x02188B40, reset per range
    for each word w at addr .. addr + (size & ~3):
        cls = classify(w)            (func_02188A0C, on the stored word)
        cls 1 (cond 1111, BLX imm) or 3 (B):
            w' = ((w & 0xFF000000) ^ 0x01000000)
                 | ((w + DELTA) & 0x00FFFFFF)   DELTA = pool 0x02188B44
            key = (key ^ (w' >> 24)) & 0x00FFFFFF
        cls 2 (BL): w ^= 0x01000000, then as cls 0
        cls 0 (anything else):
            w' = w ^ key
            key = (w ^ (w' >> 8)) & 0x00FFFFFF
        store w'
    flush the range from the caches; zero the pair; next pair

So branch words keep their shape (B and BL swap, the offset moves by
DELTA words) and every other word is XORed with a key rolled from the
previous plaintext and ciphertext.  END, KEY, DELTA and BIAS are not
constants of this file: they are read from the pool words and instruction
immediates of the decryptor itself, whose bytes
[0x021889E4, 0x02188B48) are first checked against DECRYPTOR_SHA1 (the
digest of the code this reading was made from; a digest cannot be turned
back into the code).  A different image is refused, not decrypted by a
guess.

Evidence and checks (each failure raises CryptError; nothing is written)
------------------------------------------------------------------------
  1. the decryptor bytes hash to DECRYPTOR_SHA1;
  2. every non-zero static-initialiser entry decodes as the entry thunk
     above and its `bne` lands on the decryptor; the table address is
     computed from the thunk's own immediates (E + 8 + imm1 + imm2), not
     assumed.  An initialiser of any other shape would be code this module
     does not model, so it refuses the whole overlay;
  3. every range is word aligned, non-empty, a whole number of words, inside
     ov230's image, disjoint from every other range, and disjoint from the
     decryptor, its pool, every entry thunk and every table (so the order
     the initialisers run in, and the decryptor zeroing its own thunk and
     table words behind it, cannot change any decrypted byte);
  4. every range decrypts to different bytes (it really was ciphertext);
  5. every decrypted range is a clean ARM function (clean_arm_function()):
     no unconditional-space, undefined or non-p15 coprocessor encoding; a
     walk from its first word along the fall-through and every in-range
     `b` reaches every word of the range and never leaves it (a `b` out of
     the range or a fall-through past its end would be running into the
     next slot); `bl`/`blx` land inside ov230; and the last word is an
     unconditional return (`bx lr`, `ldm sp!, {..., pc}`, `ldr pc, [sp],
     #4` or `mov pc, lr`).
disasm.py ov230d then traces every range start with Capstone and refuses
the listing unless each start is a traced function whose whole range is
code (a second, independent decoder).

The result on this image: five initialisers, 28 ranges.  Tables 0, 1 and 3
hold 0x24-byte ARM thunk slots (the table at 0x02188414 names the six
slots 0x021882A0 + n * 0x3C; each ends in `ldm sp!, {pc}` into the
dispatcher at 0x02188C60, and the six words after each slot are its plain
parameter block); table 2 holds the dispatcher and the two helpers it
calls; table 4 holds seven more functions.  The dispatcher decrypts, calls
and re-encrypts a second-layer body at call time; that layer is NOT
replayed here: the view is exactly the memory state after the static
initialisers returned (less the zeroed thunk and table words, which the
view keeps so the listing still shows the table that produced it; none of
them is inside a range, check 3).

Use
---
  python tools/ovcrypt.py check        run every check, print the ranges
  python tools/ovcrypt.py write        ... and write extract/ov230d.bin
  python tools/ovcrypt.py selftest     refusal cases on mutated copies
  python tools/ovcrypt.py encrypt IN OUT   plain (linked) ov230 image -> ROM bytes

encrypt() is the inverse of the decryptor: tools/romlink.py links src/game/ov230
(the code of the decrypted view, tools/gamelink.py 230) and writes the ROM file
of overlay 230 from that plaintext, not from the image.  Every range is
encrypted word by word, the result is decrypted again and must equal the input.

match.py attests an `ov230d`-hinted call target only at a range start of
this view (entry_points()) that asm/ov230d/ov230d.s labels; see the
"decrypted ov230" section there.
"""

import argparse
import hashlib
import json
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

OVERLAY_ID = 230
REGION = "ov230d"
VIEW_FILE = "ov230d.bin"

# The decryptor as read from the image: cache flush func_021889E4,
# classifier func_02188A0C, loc_02188A48 and its three pool words.
DECRYPTOR_SPAN = (0x021889E4, 0x02188B48)
DECRYPTOR_SHA1 = "6695c80eccf06b9fca7682cee76bd7a9e67023dd"
DECRYPTOR = 0x02188A48
# Instructions inside that span whose operands carry the parameters.
LDR_END = 0x02188A60        # ldr r7, =END
LDR_KEY = 0x02188A88        # ldr r6, =KEY
LDR_DELTA = 0x02188A90      # ldr sl, =DELTA
SUB_BIAS_SIZE = 0x02188A74  # sub r4, r0, #BIAS
SUB_BIAS_ADDR = 0x02188A78  # sub r8, r1, #BIAS

MAX_TABLE = 64              # pairs per table; a runaway read is refused
M32 = 0xFFFFFFFF


class CryptError(Exception):
    """The image is not the one this reading of the decryptor was made on,
    or a decrypted range fails a check."""


def _u32(mem, base, addr):
    off = addr - base
    if off < 0 or off + 4 > len(mem):
        raise CryptError("read of 0x%08X outside ov230" % addr)
    return struct.unpack_from("<I", mem, off)[0]


def _arm_imm(word):
    """The rotated 8-bit immediate of an ARM data-processing word."""
    rot = ((word >> 8) & 0xF) * 2
    v = word & 0xFF
    return ((v >> rot) | (v << (32 - rot))) & M32 if rot else v


def _ldr_literal(mem, base, addr):
    """The word an `ldr rX, [pc, #+imm]` at addr loads."""
    w = _u32(mem, base, addr)
    if (w & 0x0FFF0000) != 0x059F0000 or (w >> 28) != 0xE:
        raise CryptError("0x%08X is not `ldr rX, [pc, #+imm]`" % addr)
    return _u32(mem, base, addr + 8 + (w & 0xFFF))


def _sext24(w):
    v = w & 0xFFFFFF
    return v - 0x1000000 if v & 0x800000 else v


def _branch_target(addr, w):
    return (addr + 8 + (_sext24(w) << 2)) & M32


# ---------------------------------------------------------------------------
# the decryptor
# ---------------------------------------------------------------------------

def _classify(w):
    """func_02188A0C: 0 other, 1 BLX imm (cond 1111), 2 BL, 3 B."""
    b = (w >> 24) & 0xFF
    if (b & 0x0E) != 0x0A:
        return 0
    if (b & 0xF0) == 0xF0:
        return 1
    return 2 if b & 1 else 3


def _params(mem, base):
    """(END, KEY, DELTA, BIAS) read from the verified decryptor."""
    lo, hi = DECRYPTOR_SPAN
    if lo < base or hi - base > len(mem):
        raise CryptError("the decryptor span is outside this image")
    got = hashlib.sha1(bytes(mem[lo - base:hi - base])).hexdigest()
    if got != DECRYPTOR_SHA1:
        raise CryptError("the decryptor at 0x%08X..0x%08X hashes to %s, not "
                         "the code this module was read from (%s); refusing "
                         "to guess" % (lo, hi, got, DECRYPTOR_SHA1))
    end = _ldr_literal(mem, base, LDR_END)
    key = _ldr_literal(mem, base, LDR_KEY)
    delta = _ldr_literal(mem, base, LDR_DELTA)
    b1 = _arm_imm(_u32(mem, base, SUB_BIAS_SIZE))
    b2 = _arm_imm(_u32(mem, base, SUB_BIAS_ADDR))
    if b1 != b2:
        raise CryptError("the two bias immediates differ (0x%X, 0x%X)"
                         % (b1, b2))
    return end, key, delta, b1


def _entry_table(mem, base, entry):
    """Table address of an initialiser entry thunk, or CryptError."""
    w0, w1, w2 = (_u32(mem, base, entry + 4 * i) for i in range(3))
    # orr r0, pc, #imm1 ; adds r0, r0, #imm2 ; bne DECRYPTOR
    if (w0 & 0xFFFFF000) != 0xE38F0000:
        raise CryptError("initialiser 0x%08X: first word 0x%08X is not "
                         "`orr r0, pc, #imm`; this module models only the "
                         "decrypting entry thunk" % (entry, w0))
    if (w1 & 0xFFFFF000) != 0xE2900000:
        raise CryptError("initialiser 0x%08X: second word 0x%08X is not "
                         "`adds r0, r0, #imm`" % (entry, w1))
    if (w2 & 0xFF000000) != 0x1A000000 \
            or _branch_target(entry + 8, w2) != DECRYPTOR:
        raise CryptError("initialiser 0x%08X: third word 0x%08X is not "
                         "`bne 0x%08X`" % (entry, w2, DECRYPTOR))
    return (entry + 8 + _arm_imm(w0) + _arm_imm(w1)) & M32


def _decrypt_range(mem, base, addr, size, key, delta):
    for a in range(addr, addr + (size & ~3), 4):
        off = a - base
        w = struct.unpack_from("<I", mem, off)[0]
        c = _classify(w)
        if c in (1, 3):
            n = (((w & 0xFF000000) ^ 0x01000000)
                 | ((w + delta) & 0x00FFFFFF))
            key = (key ^ (n >> 24)) & 0x00FFFFFF
        else:
            if c == 2:
                w ^= 0x01000000
            n = w ^ key
            key = (w ^ (n >> 8)) & 0x00FFFFFF
        struct.pack_into("<I", mem, off, n & M32)


def _encrypt_range(mem, base, addr, size, key, delta):
    """The inverse of _decrypt_range on one range, word by word.

    A plaintext word p came from one of two paths of the decryptor:
      branch path (the stored word was a `b`/`blx` pair partner): p's top byte
        is 0xFA/0xFB (blx) or 0xnB with n != 0xF (bl).  The stored word is
        ((p & 0xFF000000) ^ 0x01000000) | ((p - DELTA) & 0xFFFFFF) and the key
        takes p's top byte;
      xor path: w = p ^ key is the stored word, or the stored word with its top
        byte's low bit flipped when w looks like a `b` (class 3: the stored
        word is then a `bl`, class 2).  A w that looks like blx or bl has no
        stored word that decrypts to p by this path.
    Each word is checked by running the decryptor's step on the result; a
    plaintext no path reproduces raises CryptError."""
    for a in range(addr, addr + (size & ~3), 4):
        off = a - base
        p = struct.unpack_from("<I", mem, off)[0]
        top = p >> 24
        n = None
        if top in (0xFA, 0xFB) or ((top & 0x0F) == 0x0B and (top >> 4) != 0xF):
            c = (((p & 0xFF000000) ^ 0x01000000) | ((p - delta) & 0x00FFFFFF)) & M32
            if _classify(c) in (1, 3):
                nkey = (key ^ (p >> 24)) & 0x00FFFFFF
                n = c
        if n is None:
            w = (p ^ key) & M32
            cls = _classify(w)
            if cls == 0:
                c = w
            elif cls == 3:
                c = w ^ 0x01000000          # stored as a bl, decrypted back to this b
            else:
                raise CryptError("0x%08X: plaintext 0x%08X has no stored word" % (a, p))
            nkey = (w ^ (p >> 8)) & 0x00FFFFFF
        else:
            c = n
        # the decryptor's step on c must give p and the same next key
        cc = _classify(c)
        if cc in (1, 3):
            q = (((c & 0xFF000000) ^ 0x01000000) | ((c + delta) & 0x00FFFFFF)) & M32
            k2 = (key ^ (q >> 24)) & 0x00FFFFFF
        else:
            cw = c ^ 0x01000000 if cc == 2 else c
            q = (cw ^ key) & M32
            k2 = (cw ^ (q >> 8)) & 0x00FFFFFF
        if q != p or k2 != nkey:
            raise CryptError("0x%08X: plaintext 0x%08X does not round-trip" % (a, p))
        struct.pack_into("<I", mem, off, c & M32)
        key = nkey


def encrypt(plain, base, sinit):
    """The ROM bytes of ov230 from its linked (decrypted) image: every range
    the initialisers name is encrypted, everything else is kept.  The ranges
    are found from the plain image's own initialiser entries and tables (the
    decryptor's reading, so the same checks); the result is decrypted again
    and must give `plain` back.  Raises CryptError otherwise."""
    mem = bytearray(plain)
    lo, hi = base, base + len(mem)
    end, key, delta, bias = _params(mem, base)
    if end != hi:
        raise CryptError("the decryptor's END 0x%08X is not ov230's end 0x%08X" % (end, hi))
    spans = []
    for entry in sinit:
        table = _entry_table(mem, base, entry)
        t = table
        while True:
            if (t - table) // 8 >= MAX_TABLE:
                raise CryptError("table 0x%08X: no terminator" % table)
            sw, ew = _u32(mem, base, t), _u32(mem, base, t + 4)
            t += 8
            spans.append((sw, ew))
            if _u32(mem, base, t) == 0:
                break
    for sw, ew in spans:
        size = (ew - end - bias) & M32
        addr = (sw - bias) & M32
        if addr % 4 or size == 0 or size % 4 or not (lo <= addr and addr + size <= hi):
            raise CryptError("pair (0x%08X, 0x%08X) is not a range inside ov230" % (sw, ew))
        _encrypt_range(mem, base, addr, size, key, delta)
    back = decrypt(bytes(mem), base, sinit)
    if back.data != bytes(plain):
        raise CryptError("the encrypted image does not decrypt back to the plain image")
    return bytes(mem)


# ---------------------------------------------------------------------------
# the clean-function check (stdlib ARMv5TE subset, no Capstone)
# ---------------------------------------------------------------------------

def _is_return(w):
    if (w >> 28) != 0xE:
        return False
    return (w == 0xE12FFF1E                           # bx lr
            or (w & 0xFFFF8000) == 0xE8BD8000         # ldm sp!, {..., pc}
            or w == 0xE49DF004                        # ldr pc, [sp], #4
            or w == 0xE1A0F00E)                       # mov pc, lr


def clean_arm_function(mem, base, start, size, lo, hi):
    """None if [start, start+size) is a clean ARM function, else the reason.

    lo..hi is the window `bl`/`blx` must land in (ov230's image)."""
    if start % 4 or size <= 0 or size % 4:
        return "range 0x%08X+0x%X is not whole aligned words" % (start, size)
    end = start + size
    seen = set()
    todo = [start]
    while todo:
        a = todo.pop()
        while True:
            if a in seen:
                break
            if not start <= a < end:
                return ("control runs from inside the range to 0x%08X, "
                        "outside 0x%08X..0x%08X" % (a, start, end))
            seen.add(a)
            w = _u32(mem, base, a)
            cond = w >> 28
            op = (w >> 25) & 7
            stop = False
            if cond == 0xF:
                if op != 5:
                    return "0x%08X: unconditional-space word 0x%08X" % (a, w)
                t = (_branch_target(a, w) | ((w >> 23) & 2))
                if not lo <= t < hi:
                    return "0x%08X: blx to 0x%08X outside ov230" % (a, t)
            elif (w & 0x0E000010) == 0x06000010:
                return "0x%08X: undefined encoding 0x%08X" % (a, w)
            elif op in (6, 7) and not ((w & 0x0F000010) == 0x0E000010
                                       and ((w >> 8) & 0xF) == 15):
                if (w & 0x0F000000) != 0x0F000000:          # swi is fine
                    return ("0x%08X: coprocessor word 0x%08X (only p15 "
                            "mcr/mrc exist here)" % (a, w))
            elif op == 5:
                t = _branch_target(a, w)
                if w & 0x01000000:                           # bl
                    if not lo <= t < hi:
                        return "0x%08X: bl to 0x%08X outside ov230" % (a, t)
                else:                                        # b
                    if not start <= t < end:
                        return ("0x%08X: b to 0x%08X leaves the range"
                                % (a, t))
                    todo.append(t)
                    stop = cond == 0xE
            elif (w & 0x0FFFFFF0) == 0x012FFF10:             # bx rN
                stop = cond == 0xE
            elif (w & 0x0E108000) == 0x08108000:             # ldm ..{pc}
                stop = cond == 0xE
            elif (w & 0x0C10F000) == 0x0410F000:             # ldr pc
                stop = cond == 0xE
            elif (op in (0, 1) and (w & 0xF000) == 0xF000
                  and not (op == 0 and (w & 0x90) == 0x90)
                  and not (0x8 <= ((w >> 21) & 0xF) <= 0xB)):
                stop = cond == 0xE                           # alu -> pc
            if stop:
                break
            a += 4
    missing = [a for a in range(start, end, 4) if a not in seen]
    if missing:
        return ("%d word(s) of the range are unreached from its start "
                "(first 0x%08X): data or an untraceable jump inside it"
                % (len(missing), missing[0]))
    last = _u32(mem, base, end - 4)
    if not _is_return(last):
        return ("the last word 0x%08X at 0x%08X is not an unconditional "
                "return" % (last, end - 4))
    return None


# ---------------------------------------------------------------------------
# the view
# ---------------------------------------------------------------------------

class View(object):
    """ov230 after its static initialisers ran.

    data     bytes of the decrypted image (same length and base as ov230)
    base     RAM address of data[0]
    ranges   [(start, size, table)] in the order the game decrypts them
    tables   [(entry thunk, table start, table end incl. terminator)]
    """

    def __init__(self, data, base, ranges, tables):
        self.data = bytes(data)
        self.base = base
        self.ranges = ranges
        self.tables = tables
        self.sha1 = hashlib.sha1(self.data).hexdigest()

    def entry_points(self):
        """{start: size} of every decrypted, checked range."""
        return {s: n for s, n, _t in self.ranges}

    def range_at(self, addr):
        """(start, size) of the decrypted range holding addr, or None."""
        for s, n, _t in self.ranges:
            if s <= addr < s + n:
                return s, n
        return None


def decrypt(image, base, sinit):
    """Replay ov230's static initialisers on a copy of `image`.

    `sinit` is the list of non-zero static-initialiser words in table order.
    Returns a View; raises CryptError on any failed check."""
    mem = bytearray(image)
    lo, hi = base, base + len(mem)
    end, key, delta, bias = _params(mem, base)
    if end != hi:
        raise CryptError("the decryptor's END 0x%08X is not ov230's end "
                         "0x%08X" % (end, hi))
    protected = [DECRYPTOR_SPAN]
    tables, ranges = [], []
    plan = []
    for entry in sinit:
        if entry & 1:
            raise CryptError("initialiser 0x%08X is Thumb; the entry thunk "
                             "is ARM" % entry)
        table = _entry_table(mem, base, entry)
        pairs = []
        t = table
        while True:
            if len(pairs) >= MAX_TABLE:
                raise CryptError("table 0x%08X: no terminator in %d pairs"
                                 % (table, MAX_TABLE))
            sw, ew = _u32(mem, base, t), _u32(mem, base, t + 4)
            pairs.append((sw, ew))
            t += 8
            # do { ... } while (*(sb += 8) != 0): the terminator is a zero
            # start word, read after the first pair has been used
            if _u32(mem, base, t) == 0:
                break
        tables.append((entry, table, t + 4))
        protected += [(entry, entry + 12), (table, t + 4)]
        plan.append((entry, table, pairs))
    for entry, table, pairs in plan:
        for sw, ew in pairs:
            size = (ew - end - bias) & M32
            addr = (sw - bias) & M32
            if addr % 4 or size == 0 or size % 4 or not (
                    lo <= addr and addr + size <= hi):
                raise CryptError("table 0x%08X: pair (0x%08X, 0x%08X) gives "
                                 "range 0x%08X+0x%X, not whole words inside "
                                 "ov230" % (table, sw, ew, addr, size))
            for s, n, t in ranges:
                if addr < s + n and s < addr + size:
                    raise CryptError("range 0x%08X+0x%X overlaps 0x%08X+0x%X"
                                     % (addr, size, s, n))
            for p0, p1 in protected:
                if addr < p1 and p0 < addr + size:
                    raise CryptError("range 0x%08X+0x%X overlaps the "
                                     "decryptor, a thunk or a table "
                                     "(0x%08X..0x%08X)" % (addr, size, p0, p1))
            before = bytes(mem[addr - base:addr + size - base])
            _decrypt_range(mem, base, addr, size, key, delta)
            if bytes(mem[addr - base:addr + size - base]) == before:
                raise CryptError("range 0x%08X+0x%X is unchanged by the "
                                 "decryptor" % (addr, size))
            ranges.append((addr, size, table))
    if not ranges:
        raise CryptError("no initialiser decrypts anything")
    for s, n, t in ranges:
        why = clean_arm_function(mem, base, s, n, lo, hi)
        if why is not None:
            raise CryptError("decrypted range 0x%08X+0x%X (table 0x%08X) is "
                             "not a clean ARM function: %s" % (s, n, t, why))
    return View(mem, base, ranges, tables)


def overlay_record(layout):
    for o in layout.get("overlays", ()):
        if o.get("id") == OVERLAY_ID:
            return o
    raise CryptError("layout.json has no overlay %d" % OVERLAY_ID)


def sinit_entries(image, o):
    base = o["ram_start"]
    out = []
    for a in range(o["static_init_start"], o["static_init_end"], 4):
        v = _u32(image, base, a)
        if v:
            out.append(v)
    return out


_CACHE = {}


def view_for(extract_dir, o):
    """Decrypt the overlay record `o`'s image under extract_dir."""
    path = os.path.join(extract_dir, o["decompressed_file"])
    try:
        with open(path, "rb") as fh:
            image = fh.read()
    except OSError as exc:
        raise CryptError("cannot read %s: %s" % (path, exc))
    if len(image) != o["code_size"]:
        raise CryptError("%s is 0x%X bytes, layout.json says 0x%X"
                         % (path, len(image), o["code_size"]))
    return decrypt(image, o["ram_start"], sinit_entries(image, o))


def load(root=None, extract_dir=None):
    """The View of this checkout's ov230 (cached), or CryptError."""
    root = root or ROOT
    key = (root, extract_dir)
    if key in _CACHE:
        return _CACHE[key]
    try:
        with open(os.path.join(root, "layout", "layout.json")) as fh:
            layout = json.load(fh)
    except (OSError, ValueError) as exc:
        raise CryptError("cannot read layout/layout.json: %s" % exc)
    if extract_dir is None:
        extract_dir = os.path.join(root, layout.get("extract_dir", "extract"))
    view = view_for(extract_dir, overlay_record(layout))
    _CACHE[key] = view
    return view


def write_view(extract_dir, view):
    """Write extract/ov230d.bin from a checked View; returns a status line."""
    path = os.path.join(extract_dir, VIEW_FILE)
    with open(path, "wb") as fh:
        fh.write(view.data)
    return ("%d initialiser(s), %d range(s) decrypted and checked, 0x%X "
            "bytes -> extract/%s" % (len(view.tables), len(view.ranges),
                                     len(view.data), VIEW_FILE))


# ---------------------------------------------------------------------------
# selftest: every refusal on a mutated copy of the real image
# ---------------------------------------------------------------------------

def selftest(root=None):
    """[(ok, name)] -- the real image passes; each mutation is refused."""
    root = root or ROOT
    with open(os.path.join(root, "layout", "layout.json")) as fh:
        o = overlay_record(json.load(fh))
    ext = os.path.join(root, "extract")
    with open(os.path.join(ext, o["decompressed_file"]), "rb") as fh:
        image = fh.read()
    base = o["ram_start"]
    sinit = sinit_entries(image, o)
    res = []

    def refused(name, img, entries=None, want=None):
        try:
            decrypt(img, base, sinit if entries is None else entries)
        except CryptError as exc:
            ok = want is None or want in str(exc)
            res.append((ok, name + ("" if ok else " [%s]" % exc)))
            return
        res.append((False, name + " [accepted]"))

    view = decrypt(image, base, sinit)
    eps = view.entry_points()
    res.append((all(a in eps and eps[a] == 0x24
                    for a in (0x021882A0, 0x02188354, 0x02188390)),
                "the real image decrypts; ica_anime's three BLX targets are "
                "0x24-byte range starts"))
    res.append((view.tables[0][1] == 0x02188414,
                "the first table is read at 0x02188414, computed from "
                "func_02188408's own immediates"))
    res.append((len(view.data) == len(image) and all(
        view.data[i] == image[i] for i in range(len(image))
        if view.range_at(base + i) is None),
        "bytes outside the decrypted ranges are unchanged"))

    def flip(addr, mask):
        m = bytearray(image)
        off = addr - base
        w = struct.unpack_from("<I", m, off)[0] ^ mask
        struct.pack_into("<I", m, off, w)
        return bytes(m)

    refused("a changed decryptor byte is refused (hash)",
            flip(0x02188B40, 1), want="hashes to")
    refused("a slot whose ciphertext decrypts to garbage fails the "
            "clean-function check", flip(0x021882A0, 0x0F000000),
            want="not a clean ARM function")
    refused("a slot whose last word no longer decrypts to a return fails "
            "the clean-function check", flip(0x021882C0, 0x00100000),
            want="not a clean ARM function")
    # table 0, pair 1: stretch the end by one word so slot 1 would run into
    # its own parameter block
    refused("a range stretched past the slot's return is refused",
            flip(0x02188420, 0x4), want="not a clean ARM function")
    refused("a range moved onto its own table is refused",
            flip(0x02188414, 0x021898A0 ^ (0x02188414 + 0x1600)),
            want="overlaps the decryptor, a thunk or a table")
    refused("a range moved outside ov230 is refused",
            flip(0x02188414, 0x021898A0 ^ 0x02300000),
            want="inside ov230")
    refused("an initialiser that is not the decrypting entry thunk is "
            "refused", image, entries=sinit + [0x02188A0C],
            want="entry thunk")
    return res


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[1])
    ap.add_argument("cmd", choices=("check", "write", "selftest", "encrypt"))
    ap.add_argument("files", nargs="*", help="encrypt: IN OUT")
    ap.add_argument("-e", "--extract", default=None,
                    help="extract directory (default: from layout.json)")
    args = ap.parse_args(argv)
    try:
        if args.cmd == "selftest":
            res = selftest()
            for ok, name in res:
                print("  %-4s %s" % ("ok" if ok else "FAIL", name))
            bad = sum(1 for ok, _ in res if not ok)
            print("\n%d case(s), %d failure(s)" % (len(res), bad))
            return 1 if bad else 0
        if args.cmd == "encrypt":
            if len(args.files) != 2:
                ap.error("encrypt takes IN OUT")
            with open(os.path.join(ROOT, "layout", "layout.json")) as fh:
                o = overlay_record(json.load(fh))
            with open(args.files[0], "rb") as fh:
                plain = fh.read()
            data = encrypt(plain, o["ram_start"], sinit_entries(plain, o))
            with open(args.files[1], "wb") as fh:
                fh.write(data)
            print("%d bytes encrypted -> %s" % (len(data), args.files[1]))
            return 0
        view = load(None, args.extract)
        for entry, table, tend in view.tables:
            n = sum(1 for _s, _n, t in view.ranges if t == table)
            print("[*] initialiser 0x%08X: table 0x%08X..0x%08X, %d range(s)"
                  % (entry, table, tend, n))
        for s, n, t in view.ranges:
            print("    0x%08X +0x%03X  (table 0x%08X)  clean ARM function"
                  % (s, n, t))
        print("[*] view sha1 %s" % view.sha1)
        if args.cmd == "write":
            ext = args.extract or os.path.join(ROOT, "extract")
            print("[*] %s" % write_view(ext, view))
        return 0
    except CryptError as exc:
        print("error: %s" % exc, file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
