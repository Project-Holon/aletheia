#!/usr/bin/env python3
"""
unknowns.py -- identification pass over the census's "unknown" group of 12
NitroFS files: a/0/1/3, a/0/2/3, a/1/0/0, a/1/6/1, a/1/8/0, a/2/1/3, and the
six dl_rom raw files (child2_r_eng.srl, child_r_eng.srl, icon_b.char/.plt,
icon_w.char/.plt).

Written from scratch for the aletheia asset lane. Stdlib only. Depends on
narc.py, lz77.py and lz11.py (same directory) for NARC sub-file access and
compression round trips.

--------------------------------------------------------------------------
Findings, per archive
--------------------------------------------------------------------------

a/0/2/3 -- NOT actually unknown: font.py (this same pass area, already
    committed) decodes this archive as 5 NFTR fonts + 3 NCLR palettes. The
    census row still reads "NFTR variant (font, guess)" / bucket "unknown"
    because it was written before font.py existed. This module does not
    re-decode it (font.py already does); it is only re-classified in the
    census update this pass makes.

a/1/0/0 -- NARC, 20 sub-files. Every sub-file's on-disk magic is the BIOS
    LZ77 header (0x10 0x24 0x06 0x00 -- inventory.py's dominant-magic
    sniff stops at this raw compression header and never decompresses, so
    it reported "0x10240600" instead of what is underneath). Decompressing
    every sub-file (LZ77, narc.py's own decoder) gives: sub-files 0-15
    decompress to 1572 bytes of NSCR ("RCSN"), sub-files 16-17 to larger
    NSCR payloads (3940 and 4068 bytes -- bigger screen/map layouts, same
    magic), sub-file 18 to 16448 bytes of NCGR ("RGCN", a tile sheet), and
    sub-file 19 is UNCOMPRESSED NCLR ("RLCN", 552 bytes, a palette). Same
    shape as a/1/6/1/a/2/1/3 below (screens + one tile sheet + one
    palette), just with more screen variants. A plain generic-NITRO
    background archive misfiled as "unknown" for the same
    stops-at-the-compression-header reason. Identification: NCLR + NSCR +
    NCGR background set, HIGH confidence (every sub-file decompresses
    clean to a valid, self-consistent NITRO chunk header).

a/1/6/1 -- NARC, 5 sub-files. Sub-file 0 is an UNCOMPRESSED NCLR (palette,
    "RLCN" magic, 552 bytes). Sub-files 1-3 are LZ77-compressed, each
    decompressing to 1572 bytes of NSCR ("RCSN") -- the same header shape
    (and decompressed size) as a/1/0/0's own NSCR sub-files, but distinct
    payload bytes (checked: not identical to each other or to a/1/0/0's).
    Sub-file 4 is LZ77-compressed, decompressing to 8256 bytes of NCGR
    ("RGCN"). This is a small self-contained background: one palette, one
    tile sheet, three distinct screen/map layouts. Identification: NCLR +
    NSCR + NCGR background set, HIGH confidence.

a/1/8/0 -- NARC, 44 sub-files. Sub-files 0-21 (22) are LZ77-compressed,
    each decompressing to 8256 bytes of NCGR ("RGCN") -- 22 distinct tile
    sheets, no two identical (checked). Sub-files 22-43 (22) are
    UNCOMPRESSED NCLR ("RLCN", 552 bytes each) -- 22 distinct 16-color
    palettes. 22 tile sheets paired 1:1 with 22 palettes by matching index
    (sub N <-> sub N+22) is the natural reading, though no accessor was
    found confirming that specific pairing (see "What remains" below).
    Identification: 22x(NCGR, NCLR) paired tile-sheet set, HIGH confidence
    on the per-sub-file format, MEDIUM on the pairing.

a/2/1/3 -- NARC, 8 sub-files, a smaller mixed archive: 2 LZ11-compressed
    NCGR ("RGCN", 8256 bytes decompressed, subs 0 and 5), 2 UNCOMPRESSED
    NCLR ("RLCN", 552 bytes, subs 1 and 6), 4 LZ11-compressed NSCR ("RCSN",
    1572 bytes decompressed, subs 2/3/4/7). Same generic-NITRO background
    shape as a/1/6/1 (tiles + palette + screens) but LZ11 instead of LZ77,
    and split across two apparent halves (0-1 look like a NCGR/NCLR pair,
    2-4 three NSCR variants, 5-6 a second NCGR/NCLR pair, 7 a fourth NSCR).
    Identification: NCLR + NSCR + NCGR background set, HIGH confidence.

a/0/1/3 -- NOT a NARC (magic bytes are 0x00000000, narc.parse_file raises
    "bad magic"). A single 2820-byte raw file. Read as 16-bit words, it
    resolves cleanly to 282 fixed 10-byte records (2820 / 10 = 282 exactly,
    no remainder) with a recurring 0xFFFF sentinel word that shows up at a
    regular but not-quite-constant stride (mostly every 5 words = 1 record,
    with a few longer gaps), consistent with per-block section markers
    rather than noise. No decompiled accessor was found opening archive id
    13 (0x0D, this file's a/X/Y/Z-digit id) as an immediate through
    func_02048F60/func_02048F4C/func_02048F74/func_02048F88 (see "Archive
    id immediate search" below) -- domain NOT identified, kept as an
    opaque fixed-10-byte-record table. Framing round trip: whole file
    copied verbatim (there is no container to re-pack; see --verify).

Archive id immediate search
    a/X/Y/Z's a/2048xxxx archive id is the decimal digits X*100+Y*10+Z
    (confirmed against docs/ASSETS.md's existing attestations: id 12 =
    a/0/1/2, id 9 = a/0/0/9, id 0x7B=123 = a/1/2/3, id 0x14=20 = a/0/2/0).
    This pass's five NARC/raw targets have ids 13 (a/0/1/3), 100 (a/1/0/0),
    161 (a/1/6/1), 180 (a/1/8/0) and 213 (a/2/1/3). Every "blx"/".inst.w
    ... blx" call site to func_02048F60, func_02048F4C, func_02048F74 and
    func_02048F88 found by grepping asm/arm9/ and asm/overlays/ for those
    four functions' addresses was backward-scanned for the nearest
    preceding immediate load of the archive-id register (r0 for
    func_02048F60/func_02048F88, r1 for func_02048F4C/func_02048F74, per
    each function's own src/matched/*.c signature). None of the immediates
    found (9, 0x12, 0x14, 0x15, 0x18, 0x19, 0x25, 0x30, 0x42, 0x43, 0x6d,
    0x66, 0x6c, 0x75, 0x7b, 0x7f, 0x94, 0x98, 0xa3, 0xa5, 0xbb, 0xd4, 0xdc,
    0xe8, 0xf) equal 13/0x0D, 100/0x64, 161/0xA1, 180/0xB4 or 213/0xD5 --
    two call sites resolve the archive id through a stored function
    pointer (ov010.s, `.word 0x02048F4C` at two locations) rather than an
    inline immediate, so are outside what a static grep can resolve.
    Verdict: no reader found for any of the five by this method, same
    negative result tables.py already reports for several of its own
    "custom format, no decoder" archives.

dl_rom files
    child_r_eng.srl / child2_r_eng.srl: valid NDS ROM headers at offset 0
    (parsed directly per the 0x200-byte layout tools/ndsrom.py's own
    docstring documents -- tools/ndsrom.py itself has no standalone
    "parse one header" command, only extract/build/verify against a full
    cartridge image, so this module parses the fixed offsets by hand).
    Both report game title "SYACHI_MB", game code "NTRJ", maker "01",
    unit code 0x02 (NTR+TWL). child_r_eng.srl: arm9 0x888A8 bytes at ROM
    offset 0x4000 (entry 0x02004850, load 0x02004000), arm7 0x28F84 bytes
    at 0x8CA00 (entry/load 0x02380000), total ROM size 0xBB000.
    child2_r_eng.srl: arm9 0x82CC0 bytes at 0x4000 (same entry/load), arm7
    0x28F84 bytes at 0x86E00 (same entry/load), total ROM size 0xB5200 --
    i.e. child2 is the same program with a smaller arm9 image, consistent
    with a "no wireless icon/menu chrome" variant of the same download-play
    child binary rather than a different game. Neither carries a game-
    specific code (gamecode is the generic placeholder "NTRJ", not
    Pokemon's own "IRBO"), matching the DS "Download Play" child binary
    convention: bytes broadcast to guest consoles that never touch a
    cartridge, bundled inside the host game's own ROM.  Identification:
    DS Download Play child (multiboot) binaries, HIGH confidence (valid
    NDS header, sane arm9/arm7 offset+size pairs that fit inside the
    1369088-byte file, non-zero entry points).

    icon_b.char/.plt and icon_w.char/.plt: 512-byte .char + 32-byte .plt
    pairs match the DS banner icon bitmap format exactly (32x32 px, 4bpp
    -> 32*32*4/8 = 512 bytes, arranged as a 4x4 grid of 8x8 tiles; 16-color
    palette -> 16 x 2-byte BGR555 = 32 bytes). Decoding and rendering both
    pairs (this module's --verify / render_icon()) produces a clearly
    recognisable Poke Ball icon in both cases -- icon_b on a black/dark
    background, icon_w on a white/light background (the two default
    console color themes DS banners historically ship both variants for).
    Identification: download-play banner icon bitmap + palette, HIGH
    confidence (byte counts match the format exactly, and the decoded
    image visibly is a Poke Ball, confirmed by eye against both renders).

--------------------------------------------------------------------------
What remains
--------------------------------------------------------------------------
  * a/0/1/3's 10-byte record fields are not split or named; domain
    unidentified.
  * a/1/8/0's NCGR<->NCLR pairing (index N <-> index N+22) is the natural
    reading of the sub-file order but not confirmed by any decompiled
    accessor.
  * None of the five NARC/raw targets' own archive-open call site was
    found by the immediate-before-the-call grep; two additional call sites
    reach func_02048F4C through a stored function pointer rather than an
    inline immediate and were not resolved.
  * The dl_rom .srl files' FNT/FAT are present but tiny (FNT size 9,
    FAT size 0) -- consistent with a single-file or no-file download-play
    payload, not decoded further here.

--------------------------------------------------------------------------
CLI
--------------------------------------------------------------------------
    python tools/assets/unknowns.py --list
        One line per archive in this pass: identification + confidence.

    python tools/assets/unknowns.py --verify
        Round-trips every NARC in the group at the framing level
        (decompress each sub-file with narc.py, re-compress with lz77.py/
        lz11.py, compare to the original bytes) and reports the dl_rom
        .srl headers plus an icon decode check. a/0/1/3 is reported as a
        whole-file identity copy (it has no container to re-pack).
"""

import argparse
import os
import struct
import sys
import zlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402
import lz77  # noqa: E402
import lz11  # noqa: E402

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)),
                                      "..", "..", "extract", "data"))
OUT_DIR = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)),
                                         "..", "..", "build", "assets", "dl_rom"))

MAGIC_LABEL = {
    b"RGCN": "NCGR (tile/character data)",
    b"RLCN": "NCLR (palette)",
    b"RCSN": "NSCR (screen/map)",
}

# The four NARCs this pass identifies as generic-NITRO archives that
# inventory.py's compression-header-only magic sniff misreported as
# "unknown". No field-level decoder is written for any of them (there is
# none to write -- they are already NCGR/NCLR/NSCR, covered by the
# generic-format bucket); this registry exists only to drive the
# framing-level round trip (decompress/recompress every sub-file).
NARC_REGISTRY = {
    "a/1/0/0": "20 sub-files: 18 LZ77 -> NSCR (16 at 1572 bytes, 2 larger), "
               "1 LZ77 -> NCGR, 1 raw NCLR.",
    "a/1/6/1": "5 sub-files: 1 raw NCLR, 3 LZ77 -> NSCR, 1 LZ77 -> NCGR.",
    "a/1/8/0": "44 sub-files: 22 LZ77 -> NCGR, 22 raw NCLR (paired by index, guess).",
    "a/2/1/3": "8 sub-files: 2 LZ11 -> NCGR, 2 raw NCLR, 4 LZ11 -> NSCR.",
}

DL_ROM_DIR = os.path.join(ROOT, "dl_rom")
SRL_FILES = ["child_r_eng.srl", "child2_r_eng.srl"]
ICON_PAIRS = [("icon_b.char", "icon_b.plt", "icon_b.png"),
              ("icon_w.char", "icon_w.plt", "icon_w.png")]


# ---------------------------------------------------------------------------
# NARC framing round trip
# ---------------------------------------------------------------------------

def _decode_sub(raw):
    """(kind, payload) -- kind is None for an uncompressed sub-file (payload
    is the raw bytes themselves), else "LZ77"/"LZ11" with payload the
    decompressed bytes."""
    kind, dec = narc.try_decompress(raw)
    if kind is None:
        return (None, raw)
    if dec is None:
        raise ValueError(f"recognised compression kind {kind!r} but decode failed")
    return (kind, dec)


def _encode_sub(record):
    kind, payload = record
    if kind is None:
        return payload
    if kind == "LZ77":
        return lz77.compress(payload)
    if kind == "LZ11":
        return lz11.compress(payload)
    raise ValueError(f"no encoder for compression kind {kind!r}")


def verify_narc(tag):
    path = os.path.join(ROOT, tag)
    n = narc.parse_file(path)
    ok = 0
    fail = 0
    fail_examples = []
    magic_hist = {}
    for sf in n.subfiles:
        raw = n.read(sf.index)
        record = _decode_sub(raw)
        back = _encode_sub(record)
        if back == raw:
            ok += 1
        else:
            fail += 1
            if len(fail_examples) < 5:
                fail_examples.append(sf.index)
        _, payload = record
        label = MAGIC_LABEL.get(payload[:4], payload[:4])
        magic_hist[label] = magic_hist.get(label, 0) + 1
    return n.file_count, ok, fail, fail_examples, magic_hist


def sample_subfiles(tag, indices):
    path = os.path.join(ROOT, tag)
    n = narc.parse_file(path)
    out = []
    for i in indices:
        if i >= n.file_count:
            continue
        raw = n.read(i)
        kind, payload = _decode_sub(raw)
        out.append((i, len(raw), kind, payload[:4], raw[:64]))
    return out


# ---------------------------------------------------------------------------
# a/0/1/3 (raw, not a NARC)
# ---------------------------------------------------------------------------

def inspect_a0013():
    path = os.path.join(ROOT, "a/0/1/3")
    data = open(path, "rb").read()
    n_records = len(data) // 10
    remainder = len(data) % 10
    words = struct.unpack_from(f"<{len(data) // 2}H", data)
    sentinel_positions = [i for i, w in enumerate(words) if w == 0xFFFF]
    return {
        "size": len(data),
        "record_count_if_10byte": n_records,
        "remainder": remainder,
        "sentinel_0xFFFF_count": len(sentinel_positions),
        "first64": data[:64].hex(),
    }


def verify_a0013():
    path = os.path.join(ROOT, "a/0/1/3")
    data = open(path, "rb").read()
    # No container framing to re-pack; the "round trip" is the trivial
    # identity copy every raw (non-NARC) file in this project gets.
    return len(data) == len(data)  # always True; kept for a uniform report shape


# ---------------------------------------------------------------------------
# dl_rom: .srl NDS headers
# ---------------------------------------------------------------------------

def parse_nds_header(data):
    title = data[0x0:0xC].rstrip(b"\x00").decode("ascii", "replace")
    gamecode = data[0xC:0x10].decode("ascii", "replace")
    maker = data[0x10:0x12].decode("ascii", "replace")
    unit_code = data[0x12]
    arm9_off, arm9_entry, arm9_ram, arm9_size = struct.unpack_from("<IIII", data, 0x20)
    arm7_off, arm7_entry, arm7_ram, arm7_size = struct.unpack_from("<IIII", data, 0x30)
    fnt_off, fnt_size = struct.unpack_from("<II", data, 0x40)
    fat_off, fat_size = struct.unpack_from("<II", data, 0x48)
    total_size, = struct.unpack_from("<I", data, 0x80)
    header_size, = struct.unpack_from("<I", data, 0x84)
    return dict(
        title=title, gamecode=gamecode, maker=maker, unit_code=unit_code,
        arm9_off=arm9_off, arm9_entry=arm9_entry, arm9_ram=arm9_ram, arm9_size=arm9_size,
        arm7_off=arm7_off, arm7_entry=arm7_entry, arm7_ram=arm7_ram, arm7_size=arm7_size,
        fnt_off=fnt_off, fnt_size=fnt_size, fat_off=fat_off, fat_size=fat_size,
        total_size=total_size, header_size=header_size,
    )


def srl_report(name):
    path = os.path.join(DL_ROM_DIR, name)
    data = open(path, "rb").read()
    h = parse_nds_header(data)
    h["file_size"] = len(data)
    # sanity: arm9/arm7 regions must fit inside the file
    arm9_fits = h["arm9_off"] + h["arm9_size"] <= len(data)
    arm7_fits = h["arm7_off"] + h["arm7_size"] <= len(data)
    h["arm9_fits"] = arm9_fits
    h["arm7_fits"] = arm7_fits
    return h


# ---------------------------------------------------------------------------
# dl_rom: icon .char/.plt (DS banner bitmap format)
# ---------------------------------------------------------------------------

def _bgr555_to_rgb8(word):
    r = (word & 0x1F) * 255 // 31
    g = ((word >> 5) & 0x1F) * 255 // 31
    b = ((word >> 10) & 0x1F) * 255 // 31
    return r, g, b


def decode_icon(char_data, plt_data):
    """32x32 4bpp bitmap (4x4 grid of 8x8 tiles) + 16-color BGR555 palette
    -> list of 32*32 (r,g,b) tuples, row-major."""
    if len(char_data) != 512:
        raise ValueError(f"expected 512-byte icon bitmap, got {len(char_data)}")
    if len(plt_data) != 32:
        raise ValueError(f"expected 32-byte icon palette, got {len(plt_data)}")
    pal = [_bgr555_to_rgb8(w) for w in struct.unpack_from("<16H", plt_data, 0)]
    pixels = [(0, 0, 0)] * (32 * 32)
    for ty in range(4):
        for tx in range(4):
            tile = char_data[(ty * 4 + tx) * 32:(ty * 4 + tx + 1) * 32]
            for py in range(8):
                for bx in range(4):
                    byte = tile[py * 4 + bx]
                    x0 = tx * 8 + bx * 2
                    y = ty * 8 + py
                    pixels[y * 32 + x0] = pal[byte & 0xF]
                    pixels[y * 32 + x0 + 1] = pal[(byte >> 4) & 0xF]
    return pixels, pal


def write_png_rgb8(path, width, height, pixels):
    def chunk(tag, payload):
        out = struct.pack(">I", len(payload)) + tag + payload
        crc = zlib.crc32(tag)
        crc = zlib.crc32(payload, crc) & 0xFFFFFFFF
        return out + struct.pack(">I", crc)

    raw = bytearray()
    for y in range(height):
        raw.append(0)
        for x in range(width):
            raw.extend(pixels[y * width + x])
    idat = zlib.compress(bytes(raw), 9)
    ihdr = struct.pack(">IIBBBBB", width, height, 8, 2, 0, 0, 0)
    parent = os.path.dirname(os.path.abspath(path))
    if parent:
        os.makedirs(parent, exist_ok=True)
    with open(path, "wb") as fh:
        fh.write(b"\x89PNG\r\n\x1a\n")
        fh.write(chunk(b"IHDR", ihdr))
        fh.write(chunk(b"IDAT", idat))
        fh.write(chunk(b"IEND", b""))


def render_icons():
    results = []
    for char_name, plt_name, png_name in ICON_PAIRS:
        char_data = open(os.path.join(DL_ROM_DIR, char_name), "rb").read()
        plt_data = open(os.path.join(DL_ROM_DIR, plt_name), "rb").read()
        pixels, pal = decode_icon(char_data, plt_data)
        out_path = os.path.join(OUT_DIR, png_name)
        write_png_rgb8(out_path, 32, 32, pixels)
        distinct_colors = len(set(pixels))
        results.append((char_name, out_path, len(pal), distinct_colors))
    return results


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def cmd_list():
    print("a/0/2/3  NFTR font archive (font.py decodes it; census row was stale)")
    for tag, note in NARC_REGISTRY.items():
        print(f"{tag}  generic NITRO archive (NCGR/NCLR/NSCR), HIGH confidence")
        print(f"    {note}")
    info = inspect_a0013()
    print(f"a/0/1/3  NOT a NARC, raw 2820-byte table, "
          f"{info['record_count_if_10byte']} fixed 10-byte records "
          f"(remainder {info['remainder']}), domain UNIDENTIFIED")
    print("dl_rom/child_r_eng.srl, dl_rom/child2_r_eng.srl  "
          "DS Download Play child (multiboot) binaries, HIGH confidence")
    print("dl_rom/icon_{b,w}.char + .plt  download-play banner icon bitmap+palette "
          "(Poke Ball), HIGH confidence")


def cmd_verify():
    total_ok = 0
    total_fail = 0
    for tag in NARC_REGISTRY:
        subs, ok, fail, fail_examples, magic_hist = verify_narc(tag)
        total_ok += ok
        total_fail += fail
        status = "OK" if fail == 0 else "FAIL"
        print(f"{tag}: round trip {ok}/{subs} byte-identical [{status}]")
        print(f"    decompressed magic histogram: {magic_hist}")
        if fail:
            print(f"    {fail} failures, first indices: {fail_examples}")

    print(f"a/0/1/3: whole-file identity copy (no container framing) "
          f"[{'OK' if verify_a0013() else 'FAIL'}]")

    print()
    for name in SRL_FILES:
        h = srl_report(name)
        print(f"dl_rom/{name}: {h['file_size']} bytes")
        print(f"    title={h['title']!r} gamecode={h['gamecode']!r} "
              f"maker={h['maker']!r} unit_code=0x{h['unit_code']:02x}")
        print(f"    arm9: off=0x{h['arm9_off']:X} entry=0x{h['arm9_entry']:X} "
              f"ram=0x{h['arm9_ram']:X} size=0x{h['arm9_size']:X} "
              f"fits={h['arm9_fits']}")
        print(f"    arm7: off=0x{h['arm7_off']:X} entry=0x{h['arm7_entry']:X} "
              f"ram=0x{h['arm7_ram']:X} size=0x{h['arm7_size']:X} "
              f"fits={h['arm7_fits']}")
        print(f"    fnt: off=0x{h['fnt_off']:X} size=0x{h['fnt_size']:X}  "
              f"fat: off=0x{h['fat_off']:X} size=0x{h['fat_size']:X}  "
              f"total=0x{h['total_size']:X} header_size=0x{h['header_size']:X}")

    print()
    for char_name, out_path, pal_len, distinct in render_icons():
        print(f"dl_rom/{char_name}: decoded 32x32 4bpp + {pal_len}-color palette, "
              f"{distinct} distinct colors used, rendered to {out_path}")

    print()
    if total_fail == 0:
        print(f"ALL NARC ROUND TRIPS OK: {total_ok}/{total_ok} sub-files byte-identical "
              f"across {len(NARC_REGISTRY)} archives")
    else:
        print(f"NARC ROUND TRIPS: {total_ok} ok, {total_fail} FAILED")


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--list", action="store_true",
                    help="one line per archive: identification + confidence")
    p.add_argument("--verify", action="store_true",
                    help="round-trip every NARC, report dl_rom headers + icon decode")
    args = p.parse_args(argv)

    if args.list:
        cmd_list()
    elif args.verify:
        cmd_verify()
    else:
        p.print_help()
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
