#!/usr/bin/env python3
"""
modcrypt.py -- DSi modcrypt (AES-128-CTR) decryption for the TWL binaries.

Written from scratch for aletheia. Stdlib only, single file.

Why
---
A DSi-enhanced cart can encrypt up to two ROM ranges ("modcrypt areas") with
AES-128 in counter mode.  Header 0x1C bit 1 enables it; area 1 is
(header 0x220 offset, header 0x224 size) and area 2 is (0x228, 0x22C).  On
this cart area 1 is ROM 0x0C403000 + 0x4000, which is exactly the first
0x4000 bytes of arm9i.bin (header 0x1C0).  extract/arm9i.bin keeps the ROM
bytes as they are (the ROM rebuild needs them); this module returns a
decrypted copy in memory for delink.py.

Key schedule (public DSi header documentation)
----------------------------------------------
  retail (header 0x1C bit 2 clear and header 0x1BF bit 7 clear):
    KeyX = "Nintendo" + gamecode[0:4] + reversed(gamecode[0:4])
    KeyY = header[0x350:0x360]          (first 16 bytes of the ARM9i HMAC)
    Key  = ((KeyX xor KeyY) + C) rol 42  (128-bit arithmetic, little endian)
  debug: Key = header[0x000:0x010]
  counter: header[0x300:0x310] for area 1 (ARM9 HMAC), [0x314:0x324] area 2

C is the key-scrambler constant of the DSi AES engine.  It is NOT part of
this repository and never written by any tool here: it is read at run time
from a file the user supplies (see below) and checked against KEY_SHA1, the
SHA-1 of its 16 little-endian bytes, so a wrong file is refused instead of
producing garbage.  A digest cannot be turned back into the constant.

Where the constant comes from, in this order
--------------------------------------------
  --dsi-key PATH       a 16-byte file holding C, little endian
  --dsi-bios PATH      a dump to scan for those 16 bytes (any offset)
  ALETHEIA_DSI_KEY     same as --dsi-key
  ALETHEIA_DSI_BIOS    same as --dsi-bios

Keep the file outside the repository; no default path inside it is read.

Note on BIOS dumps: the scrambler constant lives in the AES hardware, not in
BIOS ROM.  A 64 KB DSi ARM9 BIOS dump was scanned byte by byte (both byte
orders, all 128 rotations) and does not contain it, so --dsi-bios only
succeeds on a file that really holds the 16 bytes; --dsi-key is the path
that works.  Without any source the TWL region is skipped and every other
tool behaves as before.

CLI
---
  python tools/modcrypt.py check  [--dsi-key P | --dsi-bios P]
  python tools/modcrypt.py arm9i  [--dsi-key P | --dsi-bios P] -o OUT
      (OUT must be under build/ or extract/: both are gitignored)
"""

import argparse
import hashlib
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# SHA-1 of the 16 little-endian bytes of the key-scrambler constant.
KEY_SHA1 = "7234bbc738ce1160df2b24aebb3894af069f7ae3"
MASK128 = (1 << 128) - 1


class KeyMissing(Exception):
    """No usable scrambler constant was supplied."""


# ---------------------------------------------------------------------------
# AES-128 (encryption direction only; CTR never needs the inverse cipher)
# ---------------------------------------------------------------------------

def _xtime(a):
    a <<= 1
    return (a ^ 0x11B) if a & 0x100 else a


def _build_sbox():
    # multiplicative inverse in GF(2^8) followed by the affine map
    exp, log = [0] * 512, [0] * 256
    x = 1
    for i in range(255):
        exp[i] = x
        log[x] = i
        x ^= _xtime(x)          # multiply by the generator 3
    for i in range(255, 512):
        exp[i] = exp[i - 255]
    sbox = [0] * 256
    for a in range(256):
        inv = 0 if a == 0 else exp[255 - log[a]]
        s = inv
        for k in range(1, 5):
            s ^= ((inv << k) | (inv >> (8 - k))) & 0xFF
        sbox[a] = s ^ 0x63
    return sbox


_SBOX = _build_sbox()
_X2 = [_xtime(a) for a in range(256)]


def _expand_key(key):
    w = [list(key[i:i + 4]) for i in range(0, 16, 4)]
    rcon = 1
    for i in range(4, 44):
        t = list(w[i - 1])
        if i % 4 == 0:
            t = [_SBOX[b] for b in t[1:] + t[:1]]
            t[0] ^= rcon
            rcon = _xtime(rcon)
        w.append([a ^ b for a, b in zip(w[i - 4], t)])
    return [sum(w[4 * r:4 * r + 4], []) for r in range(11)]


def _encrypt_block(rk, block):
    s = [b ^ k for b, k in zip(block, rk[0])]
    for rnd in range(1, 11):
        s = [_SBOX[b] for b in s]
        # ShiftRows (state is column-major: byte index = 4*col + row)
        s = [s[(4 * ((c + r) % 4)) + r] for c in range(4) for r in range(4)]
        if rnd != 10:
            m = []
            for c in range(4):
                a0, a1, a2, a3 = s[4 * c:4 * c + 4]
                t = a0 ^ a1 ^ a2 ^ a3
                m += [a0 ^ t ^ _X2[a0 ^ a1], a1 ^ t ^ _X2[a1 ^ a2],
                      a2 ^ t ^ _X2[a2 ^ a3], a3 ^ t ^ _X2[a3 ^ a0]]
            s = m
        s = [b ^ k for b, k in zip(s, rk[rnd])]
    return bytes(s)


def _aes_ecb_encryptor(key):
    try:                                    # optional speed-up only
        from Crypto.Cipher import AES       # type: ignore
        c = AES.new(bytes(key), AES.MODE_ECB)
        return c.encrypt
    except ImportError:
        rk = _expand_key(bytes(key))
        return lambda blk: _encrypt_block(rk, blk)


def _selftest_aes():
    # FIPS-197 appendix C.1
    k = bytes(range(16))
    p = bytes.fromhex("00112233445566778899aabbccddeeff")
    want = "69c4e0d86a7b0430d8cdb78070b4c55a"
    rk = _expand_key(k)
    return _encrypt_block(rk, p).hex() == want


# ---------------------------------------------------------------------------
# the scrambler constant
# ---------------------------------------------------------------------------

def _check(blob):
    return len(blob) == 16 and hashlib.sha1(blob).hexdigest() == KEY_SHA1


def _scan(path):
    with open(path, "rb") as fh:
        data = fh.read()
    for off in range(0, len(data) - 15):
        if _check(data[off:off + 16]):
            return data[off:off + 16], off
    return None, None


def load_constant(dsi_key=None, dsi_bios=None):
    """(16 bytes, description of the source); raises KeyMissing."""
    tried = []
    sources = []
    if dsi_key:
        sources.append(("key", dsi_key))
    if dsi_bios:
        sources.append(("bios", dsi_bios))
    if not sources:
        if os.environ.get("ALETHEIA_DSI_KEY"):
            sources.append(("key", os.environ["ALETHEIA_DSI_KEY"]))
        if os.environ.get("ALETHEIA_DSI_BIOS"):
            sources.append(("bios", os.environ["ALETHEIA_DSI_BIOS"]))
    for kind, path in sources:
        if not os.path.isfile(path):
            tried.append("%s: no such file" % path)
            continue
        if kind == "key":
            with open(path, "rb") as fh:
                blob = fh.read()
            if _check(blob):
                return blob, "key file %s" % path
            tried.append("%s: not the 16-byte constant (digest mismatch)"
                         % path)
        else:
            blob, off = _scan(path)
            if blob is not None:
                return blob, "%s at offset %#x" % (path, off)
            tried.append("%s: the constant is not in this dump" % path)
    if not sources:
        raise KeyMissing(
            "no DSi key source (give --dsi-key/--dsi-bios or set "
            "ALETHEIA_DSI_KEY/ALETHEIA_DSI_BIOS)")
    raise KeyMissing("no usable DSi key source: " + "; ".join(tried))


# ---------------------------------------------------------------------------
# modcrypt
# ---------------------------------------------------------------------------

def area_key(header, const):
    """The normal AES key for this cart's modcrypt areas (16 bytes)."""
    debug = (header[0x1C] & 0x04) or (header[0x1BF] & 0x80)
    if debug:
        k = int.from_bytes(header[0:16], "little")
    else:
        gc = header[0x0C:0x10]
        keyx = int.from_bytes(b"Nintendo" + gc + gc[::-1], "little")
        keyy = int.from_bytes(header[0x350:0x360], "little")
        c = int.from_bytes(const, "little")
        k = ((keyx ^ keyy) + c) & MASK128
        k = ((k << 42) | (k >> 86)) & MASK128
    # the engine takes the key as a little-endian 128-bit number; a textbook
    # AES wants the bytes most significant first
    return k.to_bytes(16, "big")


def areas(header):
    """[(rom offset, size, counter bytes)] of the enabled modcrypt areas."""
    if not header[0x1C] & 0x02:
        return []
    out = []
    for i, (fo, iv) in enumerate(((0x220, 0x300), (0x228, 0x314))):
        off, size = struct.unpack_from("<II", header, fo)
        if size:
            out.append((off, size, header[iv:iv + 16]))
    return out


def ctr_crypt(data, key, ctr_bytes, block0=0):
    """AES-CTR in the DSi byte order: the counter is a little-endian 128-bit
    number, each keystream block is used byte-reversed."""
    enc = _aes_ecb_encryptor(key)
    ctr = int.from_bytes(ctr_bytes, "little") + block0
    out = bytearray(len(data))
    for i in range(0, len(data), 16):
        ks = enc(((ctr) & MASK128).to_bytes(16, "big"))[::-1]
        chunk = data[i:i + 16]
        out[i:i + len(chunk)] = bytes(a ^ b for a, b in zip(chunk, ks))
        ctr += 1
    return bytes(out)


def decrypt_region(header, rom_offset, data, const):
    """Return `data` (the bytes found at ROM `rom_offset`) with every part
    that falls inside an enabled modcrypt area decrypted."""
    out = bytearray(data)
    key = None
    for aoff, asize, iv in areas(header):
        lo = max(aoff, rom_offset)
        hi = min(aoff + asize, rom_offset + len(data))
        if lo >= hi:
            continue
        if key is None:
            key = area_key(header, const)
        # start on the 16-byte block boundary of the area
        blk = (lo - aoff) // 16
        lo_al = aoff + blk * 16
        pre = lo - lo_al
        seg = bytes(pre) + bytes(out[lo - rom_offset:hi - rom_offset])
        dec = ctr_crypt(seg, key, iv, blk)[pre:]
        out[lo - rom_offset:hi - rom_offset] = dec
    return bytes(out)


def arm9i_plain(extract_dir, dsi_key=None, dsi_bios=None):
    """(decrypted arm9i bytes, source note).  Raises KeyMissing."""
    with open(os.path.join(extract_dir, "header.bin"), "rb") as fh:
        header = fh.read()
    with open(os.path.join(extract_dir, "arm9i.bin"), "rb") as fh:
        raw = fh.read()
    rom_off = struct.unpack_from("<I", header, 0x1C0)[0]
    if not areas(header):
        return raw, "not modcrypted"
    const, src = load_constant(dsi_key, dsi_bios)
    return decrypt_region(header, rom_off, raw, const), src


def add_key_args(ap):
    ap.add_argument("--dsi-key", metavar="PATH", default=None,
                    help="16-byte file holding the DSi key-scrambler "
                         "constant (never commit it)")
    ap.add_argument("--dsi-bios", metavar="PATH", default=None,
                    help="dump to scan for that constant")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[1])
    ap.add_argument("cmd", choices=["check", "arm9i", "selftest"])
    ap.add_argument("--extract", default=os.path.join(ROOT, "extract"))
    ap.add_argument("-o", "--out", default=None)
    add_key_args(ap)
    a = ap.parse_args(argv)
    if a.cmd == "selftest":
        ok = _selftest_aes()
        print("aes fips-197 c.1: %s" % ("ok" if ok else "FAIL"))
        return 0 if ok else 1
    try:
        plain, src = arm9i_plain(a.extract, a.dsi_key, a.dsi_bios)
    except KeyMissing as e:
        print("modcrypt: %s" % e)
        return 2
    print("modcrypt: key constant from %s" % src)
    if a.cmd == "arm9i":
        if not a.out:
            ap.error("arm9i needs -o")
        rel = os.path.relpath(os.path.abspath(a.out), ROOT).replace("\\", "/")
        if not (rel.startswith("build/") or rel.startswith("extract/")):
            ap.error("-o must be under build/ or extract/ (gitignored)")
        os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
        with open(a.out, "wb") as fh:
            fh.write(plain)
        print("wrote %s (%d bytes)" % (a.out, len(plain)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
