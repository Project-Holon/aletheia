#!/usr/bin/env python3
"""
classify_rig_failures.py -- one-off diagnostic for the asset lane's rig-
archive verify_all failures (a/0/5/2, a/0/0/4, a/1/5/0, a/1/3/2, a/1/7/9).

Written from scratch for the aletheia project. Stdlib only, single file.
Not part of the regular verify pipeline; run by hand, output read by the
person running it, nothing else depends on it.

For every sub-file (same verdict logic as verify_all.py's `verify_subfile`,
reproduced here so the classification can be attached to a fail without a
second pass) this reports, for each fail:
  - lz_reencode_mismatch: first differing byte offset in the compressed
    stream, plus the (length, disp) token active at that offset in both the
    original stream and our recompressed one (decoded by walking each
    stream's token sequence, not by re-running compress() blindly).
  - decode_error: try_decompress raised, or the format parser raised.
  - nns_block_mismatch: decode succeeded but encode() != payload; reports
    the first differing byte offset and, where the payload is a generic
    Nitro chunked container (16-byte file header + sequence of magic+size
    blocks), which block that offset falls in.

Sub-file classification runs under `multiprocessing.Pool` (LZ11 recompress
on the tile-sheet locals is a genuine ~0.5-1s-per-file hot path on this
project's pure-Python hash-chain encoder for repetitive pixel data, not a
bug -- a single-threaded pass over one of the two 14285-sub-file rig
archives takes on the order of 20-30 minutes; the parallel pass here takes
under 5 minutes on 8 workers).

Usage:
    python tools/assets/classify_rig_failures.py a/0/5/2
    python tools/assets/classify_rig_failures.py a/0/0/4
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402
import lz77  # noqa: E402
import lz11  # noqa: E402
import rig  # noqa: E402
import battle_sprite as bs  # noqa: E402

EXTRACT_ROOT = os.path.join("extract", "data")

FORMAT_DECODERS = {
    b"RGCN": lambda p: rig.parse_ncgr(p),
    b"RLCN": lambda p: bs.parse_nclr_full(p),
    b"RECN": lambda p: rig.parse_ncer(p),
    b"RNAN": lambda p: rig.parse_nanr(p),
    b"RCMN": lambda p: rig.parse_nmcr(p),
    b"RAMN": lambda p: rig.parse_nmar(p),
}


def archive_path(name):
    return os.path.join(EXTRACT_ROOT, *name.split("/"))


def tokenize_lz77(data):
    """Walk a BIOS LZ77 (0x10) stream and yield (kind, plain_ofs, comp_ofs,
    length, disp) per token, 'kind' one of 'lit'/'match'. Mirrors
    narc.decompress_lz77's own walk exactly, just recording tokens instead
    of only the decoded bytes."""
    dec_size = data[1] | (data[2] << 8) | (data[3] << 16)
    out = bytearray()
    sp = 4
    n = len(data)
    while len(out) < dec_size:
        flags = data[sp]
        comp_ofs_flag = sp
        sp += 1
        for bit in range(8):
            if len(out) >= dec_size:
                break
            if flags & (0x80 >> bit):
                b0, b1 = data[sp], data[sp + 1]
                comp_ofs = sp
                sp += 2
                length = (b0 >> 4) + 3
                disp = (((b0 & 0x0F) << 8) | b1) + 1
                yield ("match", len(out), comp_ofs, length, disp)
                base = len(out) - disp
                for i in range(length):
                    out.append(out[base + i])
            else:
                comp_ofs = sp
                yield ("lit", len(out), comp_ofs, 1, 0)
                out.append(data[sp])
                sp += 1
        _ = comp_ofs_flag


def tokenize_lz11(data):
    """Same as tokenize_lz77 but for NDS LZ11 (0x11), mirroring
    narc.decompress_lz11's walk."""
    dec_size = data[1] | (data[2] << 8) | (data[3] << 16)
    sp = 4
    n = len(data)
    if dec_size == 0:
        import struct
        dec_size = struct.unpack_from("<I", data, sp)[0]
        sp += 4
    out = bytearray()
    while len(out) < dec_size:
        flags = data[sp]
        sp += 1
        for bit in range(8):
            if len(out) >= dec_size:
                break
            if not (flags & (0x80 >> bit)):
                comp_ofs = sp
                yield ("lit", len(out), comp_ofs, 1, 0)
                out.append(data[sp])
                sp += 1
                continue
            comp_ofs = sp
            b0 = data[sp]
            sp += 1
            indicator = b0 >> 4
            if indicator == 0:
                length = (((b0 & 0x0F) << 4) | (data[sp] >> 4)) + 0x11
                disp = (((data[sp] & 0x0F) << 8) | data[sp + 1]) + 1
                sp += 2
            elif indicator == 1:
                length = (((b0 & 0x0F) << 12) | (data[sp] << 4) | (data[sp + 1] >> 4)) + 0x111
                disp = (((data[sp + 1] & 0x0F) << 8) | data[sp + 2]) + 1
                sp += 3
            else:
                length = indicator + 1
                disp = (((b0 & 0x0F) << 8) | data[sp]) + 1
                sp += 1
            yield ("match", len(out), comp_ofs, length, disp)
            base = len(out) - disp
            for i in range(length):
                out.append(out[base + i])


def token_at_comp_ofs(tokens, target_ofs):
    """Return the token whose comp_ofs is the last one <= target_ofs."""
    best = None
    for tok in tokens:
        if tok[2] <= target_ofs:
            best = tok
        else:
            break
    return best


def _fmt_token(tok):
    if tok is None:
        return "n/a"
    k, plain_ofs, comp_ofs, length, disp = tok
    if k == "lit":
        return f"literal@plain{plain_ofs}"
    return f"match@plain{plain_ofs} len={length} disp={disp}"


def _lz_diff_detail(kind, dec, raw, ours):
    """Detail string for an LZ77/LZ11 re-encode mismatch: first differing
    byte in the compressed stream, plus the token active there in each
    stream (original vs. ours)."""
    tokenize = tokenize_lz77 if kind == "LZ77" else tokenize_lz11
    first_diff = None
    for i in range(min(len(ours), len(raw))):
        if ours[i] != raw[i]:
            first_diff = i
            break
    if first_diff is None:
        first_diff = min(len(ours), len(raw))
    orig_tok = token_at_comp_ofs(list(tokenize(raw)), first_diff)
    our_tok = token_at_comp_ofs(list(tokenize(ours)), first_diff)
    return (f"first_diff_ofs={first_diff} len_ours={len(ours)} len_raw={len(raw)} "
            f"orig_token=[{_fmt_token(orig_tok)}] our_token=[{_fmt_token(our_tok)}]")


def _format_diff_detail(payload, enc):
    first_diff = None
    for i in range(min(len(enc), len(payload))):
        if enc[i] != payload[i]:
            first_diff = i
            break
    if first_diff is None:
        first_diff = min(len(enc), len(payload))
    loc = locate_block(payload, first_diff)
    detail = f"first_diff_ofs={first_diff} len_ours={len(enc)} len_orig={len(payload)}"
    if loc:
        bi, bmagic, in_block_ofs = loc
        detail += f" block={bi}({bmagic!r}) in_block_ofs={in_block_ofs}"
    return detail


def locate_block(payload, ofs):
    """Best-effort: if `payload` looks like a generic Nitro chunked
    container (16-byte file header, then `nblocks` blocks each starting
    with a 4-byte magic + 4-byte size), report which block index `ofs`
    falls in and the byte offset within that block. Returns None if the
    header doesn't parse as that shape."""
    if len(payload) < 16:
        return None
    nblocks = payload[14] | (payload[15] << 8)
    if nblocks == 0 or nblocks > 16:
        return None
    pos = 16
    for bi in range(nblocks):
        if pos + 8 > len(payload):
            return None
        magic = payload[pos:pos + 4]
        size = int.from_bytes(payload[pos + 4:pos + 8], "little")
        if size == 0 or size > len(payload):
            return None
        if pos <= ofs < pos + size:
            return (bi, magic, ofs - pos)
        pos += size
    return None


def _classify_one(item):
    """Worker for multiprocessing.Pool: classify one (idx, raw) sub-file.
    Returns (idx, None) for pass/skipped, or (idx, (cls, detail)) for fail."""
    idx, raw = item
    try:
        kind, dec = narc.try_decompress(raw)
    except narc.NarcError:
        kind, dec = None, None

    cls = None
    detail = None
    payload = None

    if kind is not None and dec is None:
        cls, detail = "decode_error", f"{kind} decode returned None"
    elif kind in ("LZ77", "LZ11"):
        recompress = lz77.compress if kind == "LZ77" else lz11.compress
        ours = recompress(dec)
        ok = _tolerant(ours, raw)
        if not ok:
            cls, detail = "lz_reencode_mismatch", _lz_diff_detail(kind, dec, raw, ours)
        else:
            payload = dec
    else:
        payload = raw

    if cls is None and payload is not None:
        magic = payload[:4] if len(payload) >= 4 else b""
        fn = FORMAT_DECODERS.get(magic)
        if fn is not None:
            try:
                obj = fn(payload)
                enc = obj.encode()
            except Exception as exc:  # noqa: BLE001
                cls, detail = "decode_error", f"{type(exc).__name__}: {exc}"
            else:
                if enc != payload:
                    cls, detail = "nns_block_mismatch", _format_diff_detail(payload, enc)

    if cls is None:
        return (idx, None)
    return (idx, (cls, detail))


def main(argv):
    if len(argv) != 1:
        print("usage: classify_rig_failures.py <archive path, e.g. a/0/5/2>")
        return 1
    name = argv[0]
    path = archive_path(name)
    n = narc.parse_file(path)

    raws = []
    read_errors = []
    for sf in n.subfiles:
        try:
            raws.append((sf.index, n.read(sf.index)))
        except Exception as exc:  # noqa: BLE001
            read_errors.append((sf.index, str(exc)))

    import multiprocessing
    import time
    t_start = time.time()
    nproc = min(8, os.cpu_count() or 4)
    groups = {}
    total_fail = 0
    for idx, err in read_errors:
        groups.setdefault("read_error", []).append((idx, idx // 20, idx % 20, err))
        total_fail += 1

    with multiprocessing.Pool(processes=nproc) as pool:
        done = 0
        for idx, result in pool.imap(_classify_one, raws, chunksize=8):
            done += 1
            if done % 2000 == 0:
                print(f"...progress {done}/{len(raws)} elapsed={time.time()-t_start:.1f}s", flush=True)
            if result is None:
                continue
            cls, detail = result
            total_fail += 1
            groups.setdefault(cls, []).append((idx, idx // 20, idx % 20, detail))

    print(f"=== {name}: {total_fail} failing sub-files (elapsed {time.time()-t_start:.1f}s) ===")
    for cls, items in sorted(groups.items()):
        print(f"\n-- class: {cls} ({len(items)}) --")
        by_member = {}
        for idx, block, member, detail in items:
            by_member.setdefault(member, []).append(idx)
        print(f"   member positions (mod 20): { {m: len(v) for m, v in sorted(by_member.items())} }")
        for idx, block, member, detail in items:
            print(f"   idx={idx} block={block} member={member}: {detail}")
    return 0


def _tolerant(recompressed, raw):
    if recompressed == raw:
        return True
    extra = len(raw) - len(recompressed)
    if not (0 < extra < 4):
        return False
    return raw[:len(recompressed)] == recompressed and raw[len(recompressed):] == b"\x00" * extra


def _format_ok(magic, payload):
    fn = FORMAT_DECODERS.get(magic)
    if fn is None:
        return None
    try:
        return fn(payload).encode() == payload
    except Exception:  # noqa: BLE001
        return False


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
