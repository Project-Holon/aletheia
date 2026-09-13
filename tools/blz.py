#!/usr/bin/env python3
"""
blz.py -- BLZ (backwards LZ77) codec used by NitroSDK / TWL-SDK.

Written from scratch for the aletheia project. Stdlib only, single file.
Usable both as a library (``decompress`` / ``compress``) and as a CLI.

--------------------------------------------------------------------------
Container layout
--------------------------------------------------------------------------
A BLZ container is a plain byte string whose *tail* carries the metadata.
Reading from the very end of the container:

    [-4:]   u32  inc_len   additional decompressed length
    [-8:-4] u32  (hdr_len << 24) | enc_len

  inc_len   how many bytes the decompressed image is LONGER than the
            container. If this field is zero the container holds raw,
            uncompressed data and nothing is to be done.
  enc_len   low 24 bits. Length of the *encoded region*, measured from the
            end of the container backwards. It covers the compressed byte
            stream, any alignment padding, and the 8 footer bytes.
  hdr_len   top 8 bits of the same word. Size of the trailer that is NOT
            part of the compressed byte stream, i.e. padding + the 8 footer
            bytes. Observed values are 0x08..0x0B (0..3 padding bytes).

From those three numbers:

    dec_len = len(container) - enc_len      # verbatim prefix, never encoded
    pak_len = enc_len - hdr_len             # compressed byte stream length
    raw_len = dec_len + enc_len + inc_len   # size of the decompressed image

So the container is::

    | verbatim prefix (dec_len) | compressed stream (pak_len) | pad | footer |
    |<---------------------- len(container) ------------------------------->|
    |<-- dec_len -->|<------------------ enc_len ------------------------->|
                                                              |<-hdr_len-->|

--------------------------------------------------------------------------
Byte stream
--------------------------------------------------------------------------
The compressed stream is an ordinary LZ77 stream that has been *reversed*:
it is produced by encoding the reversed plaintext and then reversing the
result. Decoding therefore works by reversing the stream back, decoding
forwards, and reversing the produced bytes again. Equivalently (and this is
what the hardware does) the decoder walks both pointers backwards from the
end of the image, which is why the format is called "backwards LZ".

Once un-reversed the stream is:

    u8 flags                 8 tokens, most significant bit first
      bit clear -> u8        one literal byte
      bit set   -> u16 be    pos = value & 0x0FFF, len = (value >> 12) + 3
                             copy `len` bytes from `pos + 3` bytes back in
                             the already produced output

Matches are 3..18 bytes long and reach 3..4098 bytes back. Back references
may reach into the verbatim prefix, so decoding must keep the whole image in
one buffer.

--------------------------------------------------------------------------
Note on ARM9
--------------------------------------------------------------------------
The ARM9 secure area (first 0x4000 bytes) is never part of the compressed
stream; it simply falls inside the verbatim prefix. Passing ``--start
0x4000`` is therefore only an assertion about where the encoded region may
begin, not a different decode -- both spellings produce the same image.
"""

import argparse
import os
import struct
import sys

FOOTER_SIZE = 8
MIN_MATCH = 3
MAX_MATCH = 18
MIN_DISP = 3
MAX_DISP = 0x1002
HDR_LEN_MIN = 0x08
HDR_LEN_MAX = 0x0B


class BlzError(Exception):
    """Raised for any malformed or inconsistent BLZ container."""


# ---------------------------------------------------------------------------
# decoding
# ---------------------------------------------------------------------------

def parse_footer(container):
    """Return (dec_len, pak_len, raw_len, hdr_len, enc_len, inc_len).

    ``container`` is the bytes of the BLZ container alone (no extra prefix).
    Raises BlzError if the numbers do not describe a consistent container.
    """
    n = len(container)
    if n < FOOTER_SIZE:
        raise BlzError(f"container is only {n} bytes, too small for a footer")

    inc_len = struct.unpack_from("<I", container, n - 4)[0]
    word = struct.unpack_from("<I", container, n - 8)[0]
    enc_len = word & 0x00FFFFFF
    hdr_len = (word >> 24) & 0xFF

    if inc_len == 0:
        # Not compressed at all; the whole container is the image.
        return (n, 0, n, 0, 0, 0)

    if not (HDR_LEN_MIN <= hdr_len <= HDR_LEN_MAX):
        raise BlzError(
            f"header length 0x{hdr_len:02X} is outside the legal range "
            f"0x{HDR_LEN_MIN:02X}..0x{HDR_LEN_MAX:02X}; this does not look "
            "like a BLZ container"
        )
    if enc_len > n:
        raise BlzError(
            f"encoded length 0x{enc_len:X} exceeds the container size 0x{n:X}"
        )
    if enc_len < hdr_len:
        raise BlzError(
            f"encoded length 0x{enc_len:X} is smaller than the header length "
            f"0x{hdr_len:X}"
        )

    dec_len = n - enc_len
    pak_len = enc_len - hdr_len
    raw_len = dec_len + enc_len + inc_len
    return (dec_len, pak_len, raw_len, hdr_len, enc_len, inc_len)


def decompress(data, start=0, expect_size=None):
    """Decompress a BLZ container embedded in ``data`` at offset ``start``.

    ``data[:start]`` is copied to the output verbatim and stays addressable by
    back references. Returns the decompressed image as ``bytes``.
    """
    if start < 0 or start > len(data):
        raise BlzError(f"start offset 0x{start:X} is outside the input")

    container = data[start:]
    dec_len, pak_len, raw_len, hdr_len, enc_len, inc_len = parse_footer(container)

    if inc_len == 0:
        out = bytes(data[:start]) + bytes(container)
        if expect_size is not None and len(out) != expect_size:
            raise BlzError(
                f"stored (uncompressed) container is 0x{len(out):X} bytes but "
                f"0x{expect_size:X} was expected"
            )
        return out

    total = start + raw_len
    if expect_size is not None and total != expect_size:
        raise BlzError(
            f"footer says the image is 0x{total:X} bytes but 0x{expect_size:X} "
            "was expected"
        )

    out = bytearray(total)
    # Verbatim prefix: anything before the container plus the container's own
    # unencoded head.
    head = start + dec_len
    out[:head] = data[:start + dec_len]

    # The encoded stream, un-reversed so we can decode forwards.
    stream = bytes(container[dec_len:dec_len + pak_len])[::-1]

    produced = bytearray()          # decoded bytes, in reverse image order
    want = raw_len - dec_len        # how many bytes the stream must produce
    sp = 0
    flags = 0
    mask = 0

    while len(produced) < want:
        if mask == 0:
            if sp >= len(stream):
                raise BlzError(
                    f"compressed stream ran out after {len(produced)} of "
                    f"{want} bytes (needed a flag byte)"
                )
            flags = stream[sp]
            sp += 1
            mask = 0x80

        if flags & mask:
            if sp + 1 >= len(stream):
                raise BlzError(
                    f"compressed stream ran out inside a match token after "
                    f"{len(produced)} of {want} bytes"
                )
            token = (stream[sp] << 8) | stream[sp + 1]
            sp += 2
            length = (token >> 12) + MIN_MATCH
            disp = (token & 0x0FFF) + MIN_MATCH
            if disp > len(produced):
                raise BlzError(
                    f"match at output byte {len(produced)} reaches {disp} "
                    f"bytes back, past the start of the decoded region"
                )
            if length > want - len(produced):
                length = want - len(produced)
            base = len(produced) - disp
            for i in range(length):
                produced.append(produced[base + i])
        else:
            if sp >= len(stream):
                raise BlzError(
                    f"compressed stream ran out after {len(produced)} of "
                    f"{want} literal bytes"
                )
            produced.append(stream[sp])
            sp += 1

        mask >>= 1

    if len(produced) != want:
        raise BlzError(
            f"decoder produced {len(produced)} bytes, expected {want}"
        )

    out[head:] = bytes(produced)[::-1]
    return bytes(out)


# ---------------------------------------------------------------------------
# encoding
# ---------------------------------------------------------------------------

def compress(image, start=0):
    """Encode ``image[start:]`` into a BLZ container; returns the whole file.

    This is a straightforward greedy encoder. It round-trips through
    ``decompress`` exactly, but unlike the SDK's own compressor it makes no
    attempt to leave a verbatim prefix large enough to guarantee that the
    hardware's *in place* decompression never overtakes its read pointer.
    Use it for tooling and experiments, not for producing a ROM that must
    boot, until that property has been verified separately.
    """
    if start < 0 or start > len(image):
        raise BlzError(f"start offset 0x{start:X} is outside the image")

    prefix = bytes(image[:start])
    body = bytes(image[start:])
    rev = body[::-1]

    # Greedy LZ77 over the reversed plaintext, with a simple 3-byte hash chain.
    out = bytearray()
    flag_pos = -1
    mask = 0
    heads = {}
    prev = [-1] * len(rev)
    i = 0
    n = len(rev)
    while i < n:
        if mask == 0:
            flag_pos = len(out)
            out.append(0)
            mask = 0x80

        best_len = 0
        best_disp = 0
        if i + MIN_MATCH <= n:
            key = rev[i:i + MIN_MATCH]
            cand = heads.get(key, -1)
            limit = i - MAX_DISP
            tries = 0
            while cand >= 0 and cand >= limit and tries < 64:
                disp = i - cand
                if disp >= MIN_DISP:
                    ml = 0
                    maxl = min(MAX_MATCH, n - i)
                    while ml < maxl and rev[cand + ml] == rev[i + ml]:
                        ml += 1
                    if ml > best_len:
                        best_len = ml
                        best_disp = disp
                        if ml == MAX_MATCH:
                            break
                cand = prev[cand]
                tries += 1

        if best_len >= MIN_MATCH:
            token = ((best_len - MIN_MATCH) << 12) | (best_disp - MIN_DISP)
            out.append((token >> 8) & 0xFF)
            out.append(token & 0xFF)
            out[flag_pos] |= mask
            step = best_len
        else:
            out.append(rev[i])
            step = 1

        for k in range(i, i + step):
            if k + MIN_MATCH <= n:
                key = rev[k:k + MIN_MATCH]
                prev[k] = heads.get(key, -1)
                heads[key] = k
        i += step
        mask >>= 1

    stream = bytes(out)[::-1]
    pad = (-(start + len(stream))) % 4
    hdr_len = FOOTER_SIZE + pad
    enc_len = len(stream) + hdr_len
    file_len = start + enc_len
    inc_len = len(image) - file_len

    if inc_len <= 0 or hdr_len > HDR_LEN_MAX:
        # Encoding did not pay off; store the image verbatim. A zero inc_len
        # is exactly how the format spells "not compressed".
        return bytes(image) + struct.pack("<II", 0, 0)

    blob = bytearray()
    blob += prefix
    blob += stream
    blob += b"\xFF" * pad
    blob += struct.pack("<II", (hdr_len << 24) | enc_len, inc_len)
    if len(blob) != file_len:
        raise BlzError("internal error: encoded container has the wrong size")
    return bytes(blob)


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def _read(path):
    with open(path, "rb") as fh:
        return fh.read()


def _write(path, data):
    parent = os.path.dirname(os.path.abspath(path))
    if parent:
        os.makedirs(parent, exist_ok=True)
    with open(path, "wb") as fh:
        fh.write(data)


def cmd_decompress(args):
    data = _read(args.input)
    start = args.start
    dec_len, pak_len, raw_len, hdr_len, enc_len, inc_len = parse_footer(
        data[start:])
    print(f"[*] {args.input}: 0x{len(data):X} bytes, container at 0x{start:X}")
    if inc_len == 0:
        print("    footer inc_len == 0: container is stored uncompressed")
    else:
        print(f"    hdr_len 0x{hdr_len:02X}  enc_len 0x{enc_len:X}  "
              f"inc_len 0x{inc_len:X}")
        print(f"    verbatim prefix 0x{start + dec_len:X}  "
              f"stream 0x{pak_len:X}  image 0x{start + raw_len:X}")
    out = decompress(data, start)
    print(f"    decompressed to 0x{len(out):X} bytes")
    if args.output:
        _write(args.output, out)
        print(f"[*] wrote {args.output}")
    return 0


def cmd_compress(args):
    data = _read(args.input)
    out = compress(data, args.start)
    back = decompress(out, 0)
    if back != data:
        raise BlzError("self check failed: re-decompressing did not round trip")
    print(f"[*] {args.input}: 0x{len(data):X} -> 0x{len(out):X} bytes "
          f"(round trip verified)")
    if args.output:
        _write(args.output, out)
        print(f"[*] wrote {args.output}")
    return 0


def cmd_info(args):
    data = _read(args.input)
    dec_len, pak_len, raw_len, hdr_len, enc_len, inc_len = parse_footer(
        data[args.start:])
    print(f"file size      0x{len(data):X}")
    print(f"container at   0x{args.start:X}")
    print(f"hdr_len        0x{hdr_len:02X}")
    print(f"enc_len        0x{enc_len:X}")
    print(f"inc_len        0x{inc_len:X}")
    print(f"dec_len        0x{dec_len:X}")
    print(f"pak_len        0x{pak_len:X}")
    print(f"raw_len        0x{raw_len:X}  (image 0x{args.start + raw_len:X})")
    return 0


def _hexint(text):
    return int(text, 0)


def main(argv=None):
    ap = argparse.ArgumentParser(
        prog="blz.py",
        description="Decode and encode NitroSDK BLZ (backwards LZ77) data.",
    )
    sub = ap.add_subparsers(dest="cmd", required=True)

    p = sub.add_parser("decompress", help="decode a BLZ container")
    p.add_argument("input")
    p.add_argument("-o", "--output")
    p.add_argument("--start", type=_hexint, default=0,
                   help="offset where the container begins (default 0)")
    p.set_defaults(func=cmd_decompress)

    p = sub.add_parser("compress", help="encode a file as a BLZ container")
    p.add_argument("input")
    p.add_argument("-o", "--output")
    p.add_argument("--start", type=_hexint, default=0,
                   help="leave this many leading bytes unencoded")
    p.set_defaults(func=cmd_compress)

    p = sub.add_parser("info", help="print the footer fields only")
    p.add_argument("input")
    p.add_argument("--start", type=_hexint, default=0)
    p.set_defaults(func=cmd_info)

    args = ap.parse_args(argv)
    try:
        return args.func(args)
    except BlzError as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
