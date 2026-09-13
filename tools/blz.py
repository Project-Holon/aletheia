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

For *compression* it is not optional: ``compress(image, ARM9_SECURE_AREA)``,
spelled ``--arm9`` on the command line, is what reproduces the original
container. Without that floor the encoder settles on a smaller verbatim
prefix that would overlap the secure area.

--------------------------------------------------------------------------
Matching
--------------------------------------------------------------------------
``compress`` reproduces the SDK compressor's bytes exactly for all 230
compressed containers in this ROM. The recovered search policy and the rule
that picks the verbatim prefix are derived, with the evidence, under
"Matching BLZ compression" in docs/NOTES.md.
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

# An ARM9 binary's secure area is never part of the encoded region, so the
# SDK compresses an ARM9 image with this as its minimum verbatim prefix.
ARM9_SECURE_AREA = 0x4000


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

def tokenize(rev):
    """Token stream for the reversed plaintext ``rev``.

    The search policy, recovered from the 230 compressed originals in this
    ROM (see docs/NOTES.md, "Matching BLZ compression"):

      * greedy, one decision per position, no lazy evaluation;
      * a match may not overlap itself, i.e. ``length <= displacement``;
      * among all matches of the maximal length the *smallest* displacement
        wins;
      * lengths 3..18, displacements 3..0x1002.

    Returns a list of ``(length, displacement)``; ``(1, 0)`` is a literal.
    """
    n = len(rev)
    toks = []
    i = 0
    while i < n:
        maxl = n - i
        if maxl > MAX_MATCH:
            maxl = MAX_MATCH
        best_len = 0
        best_disp = 0
        if maxl >= MIN_MATCH and i >= MIN_DISP:
            lo = i - MAX_DISP
            if lo < 0:
                lo = 0
            # ``rfind`` over [lo, i) returns the *last* start position whose
            # whole needle still fits below i, which is exactly "nearest
            # non-overlapping occurrence". Growing the needle one byte at a
            # time stops at the first length with no occurrence, so a
            # position costs best_len scans, not 0x1000 comparisons.
            j = rev.rfind(rev[i:i + MIN_MATCH], lo, i)
            if j >= 0:
                best_len, best_disp = MIN_MATCH, i - j
                length = MIN_MATCH + 1
                while length <= maxl:
                    j = rev.rfind(rev[i:i + length], lo, i)
                    if j < 0:
                        break
                    best_len, best_disp = length, i - j
                    length += 1
        if best_len:
            toks.append((best_len, best_disp))
            i += best_len
        else:
            toks.append((1, 0))
            i += 1
    return toks


def emit(rev, toks):
    """Serialise ``toks`` into the LZ77 byte stream (not yet reversed)."""
    out = bytearray()
    flag_pos = 0
    mask = 0
    i = 0
    for length, disp in toks:
        if mask == 0:
            flag_pos = len(out)
            out.append(0)
            mask = 0x80
        if disp:
            token = ((length - MIN_MATCH) << 12) | (disp - MIN_DISP)
            out.append(token >> 8)
            out.append(token & 0xFF)
            out[flag_pos] |= mask
        else:
            out.append(rev[i])
        i += length
        mask >>= 1
    return bytes(out)


def _boundaries(toks):
    """(produced, consumed) after each token, in decode order."""
    res = []
    produced = 0
    consumed = 0
    mask = 0
    for length, disp in toks:
        if mask == 0:
            consumed += 1
            mask = 0x80
        consumed += 2 if disp else 1
        produced += length
        mask >>= 1
        res.append((produced, consumed))
    return res


def _split_point(bounds):
    """Index of the last token the SDK keeps in the encoded region.

    ``D = produced - consumed`` at a token boundary is exactly how far the
    in-place decompressor's write pointer sits above its read pointer at that
    moment, and ``D`` at the final boundary is precisely ``inc_len +
    hdr_len``. The encoded region is therefore safe if and only if no earlier
    boundary has a larger ``D``.

    The SDK does not look for the best safe split. It compresses everything,
    and while the result is unsafe it retreats to the *first* boundary whose
    ``D`` exceeds the current total, then tries again. Truncating never
    changes the tokens that survive, so the whole fixpoint can be computed
    from a single pass.
    """
    d = [p - c for p, c in bounds]
    at = len(bounds) - 1
    while True:
        total = d[at]
        nxt = None
        for k in range(at + 1):
            if d[k] > total:
                nxt = k
                break
        if nxt is None:
            return at
        at = nxt


def compress(image, start=0):
    """Encode ``image[start:]`` into a BLZ container; returns the whole file.

    Reproduces the SDK compressor byte for byte, footer included: same token
    stream, same verbatim prefix, same padding. ``start`` is a *minimum*
    verbatim prefix; the encoder may leave more of the image unencoded but
    never less. For an ARM9 binary pass ``start=ARM9_SECURE_AREA``, which is
    what the SDK's own build step does.
    """
    if start < 0 or start > len(image):
        raise BlzError(f"start offset 0x{start:X} is outside the image")

    image = bytes(image)
    rev = image[start:][::-1]
    toks = tokenize(rev) if rev else []
    bounds = _boundaries(toks)

    at = _split_point(bounds) if bounds else -1
    if at < 0 or bounds[at][0] - bounds[at][1] <= 0:
        # Encoding did not pay off; store the image verbatim. A zero inc_len
        # is exactly how the format spells "not compressed".
        return image + struct.pack("<II", 0, 0)

    produced, pak_len = bounds[at]
    # The SDK builds the whole stream and then cuts it short, so the flag
    # byte of the group the cut lands in keeps the bits of the tokens that
    # were dropped. The decoder stops on the output count and never looks at
    # them, but they are part of the bytes we have to reproduce.
    stream = emit(rev, toks)[:pak_len]

    dec_len = start + (len(rev) - produced)
    pad = (-(dec_len + pak_len)) % 4
    hdr_len = FOOTER_SIZE + pad
    enc_len = pak_len + hdr_len
    file_len = dec_len + enc_len
    inc_len = len(image) - file_len
    if inc_len <= 0 or hdr_len > HDR_LEN_MAX:
        return image + struct.pack("<II", 0, 0)

    blob = bytearray()
    blob += image[:dec_len]
    blob += stream[::-1]
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
    start = ARM9_SECURE_AREA if args.arm9 else args.start
    out = compress(data, start)
    back = decompress(out, 0)
    if back != data:
        raise BlzError("self check failed: re-decompressing did not round trip")
    dec_len, pak_len, raw_len, hdr_len, enc_len, inc_len = parse_footer(out)
    print(f"[*] {args.input}: 0x{len(data):X} -> 0x{len(out):X} bytes "
          f"(round trip verified)")
    if inc_len:
        print(f"    dec_len 0x{dec_len:X}  pak_len 0x{pak_len:X}  "
              f"hdr_len 0x{hdr_len:02X}  inc_len 0x{inc_len:X}")
    else:
        print("    stored uncompressed (encoding did not pay off)")
    if args.output:
        _write(args.output, out)
        print(f"[*] wrote {args.output}")
    if args.reference:
        want = _read(args.reference)
        if out == want:
            print(f"[*] MATCH: identical to {args.reference}")
        else:
            where = next((i for i in range(min(len(out), len(want)))
                          if out[i] != want[i]), min(len(out), len(want)))
            print(f"[!] DIFFERS from {args.reference}: sizes 0x{len(out):X} vs "
                  f"0x{len(want):X}, first difference at 0x{where:X}")
            return 1
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
                   help="minimum verbatim prefix, in bytes (default 0)")
    p.add_argument("--arm9", action="store_true",
                   help="the input is an ARM9 image: keep the 0x4000 byte "
                        "secure area out of the encoded region")
    p.add_argument("--reference", metavar="FILE",
                   help="compare the result with FILE and report the first "
                        "difference (exit 1 if they differ)")
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
