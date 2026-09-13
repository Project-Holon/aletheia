#!/usr/bin/env python3
"""
delink.py -- build a memory layout description of the game from extract/.

Written from scratch for the aletheia project. Stdlib only, single file
(imports blz.py from the same directory).

What it does
------------
1. BLZ-decompresses extract/arm9.bin into extract/arm9_dec.bin and checks the
   result against the build-info structure the SDK links into the binary.
2. Splits the decompressed ARM9 into the static module plus the autoload
   blocks, and classifies each autoload block by its destination address.
3. Parses extract/y9.bin into one record per overlay, and BLZ-decompresses
   every overlay whose table entry is flagged compressed into
   extract/overlays_dec/ (originals are never touched).
4. Writes layout/layout.json and layout/layout.txt.

Neither output file contains any game bytes: they hold addresses, sizes,
counts and names only, which is why layout/ is committed while extract/ is
not.

ARM9 build info
---------------
The ROM header word at 0x88 gives the ARM9-relative offset of the build-info
structure (0xFB0 on this cart). Its fields, all u32:

  +0x00  autoload_infos_start    virtual address of the autoload info table
  +0x04  autoload_infos_end      one past its last entry
  +0x08  autoload_blocks         virtual address of the packed block payloads
  +0x0C  bss_start
  +0x10  bss_end
  +0x14  compressed_code_end
  +0x18  sdk_version
  +0x1C  nitrocode               0xDEC00621
  +0x20  nitrocode_rev           0x2106C0DE (byte-reversed nitrocode)

A second structure of the same shape sits just before it (0xF7C here) with
nitrocode 0xDEC01463 / 0x6314C0DE. That one describes the TWL (DSi) side:
its autoload table lives inside arm9i.bin, not inside arm9.bin. The startup
code only walks it when the DSi header copy in shared WRAM says the cart was
booted in TWL mode, so it is recorded for documentation and then ignored.

Autoload info entry (16 bytes, SDK5)
------------------------------------
  +0x00  u32  ram_address        where the block is copied to
  +0x04  u32  code_size          bytes copied from the packed payload area
  +0x08  u32  static_init_start  pointer to a NULL-terminated array of
                                 static initialiser function pointers
  +0x0C  u32  bss_size           bytes zeroed immediately after the block

The +0x08 field is NOT a CRC and not an init callback: the startup routine at
0x02004BB4 loads it into r0 and calls the helper at 0x02004D50, which walks
the pointed-at array until it hits a zero word and appends those words to a
global constructor list. The +0x0C field is then passed straight to memset
together with the copy destination end, which is what makes it the bss size.
"""

import argparse
import json
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import blz  # noqa: E402

OVERLAY_ENTRY_SIZE = 32
AUTOLOAD_ENTRY_SIZE = 16
NITROCODE = 0xDEC00621
NITROCODE_REV = 0x2106C0DE
NITROCODE_TWL = 0xDEC01463
NITROCODE_TWL_REV = 0x6314C0DE

MAX_SANE_SIZE = 8 * 1024 * 1024

# Overlay table flag byte (top 8 bits of the last word of an entry).
OVL_FLAG_COMPRESSED = 0x01
OVL_FLAG_SIGNED = 0x02

# Address ranges used to name an autoload destination. These are hardware
# regions, not guesses about this particular game.
ADDRESS_KINDS = [
    (0x01FF8000, 0x02000000, "ITCM"),
    (0x027C0000, 0x027E0000, "DTCM"),
    (0x027E0000, 0x02800000, "DTCM"),
    (0x02000000, 0x02400000, "MAIN"),
    (0x02400000, 0x03000000, "MAIN_TWL"),
    (0x03000000, 0x03800000, "WRAM"),
    (0x03800000, 0x04000000, "WRAM_ARM7"),
    (0x06800000, 0x06900000, "VRAM_LCDC"),
]


class LayoutError(Exception):
    """Raised when the extracted data does not match what we expect."""


def u32(buf, off):
    return struct.unpack_from("<I", buf, off)[0]


def classify_address(addr):
    for lo, hi, name in ADDRESS_KINDS:
        if lo <= addr < hi:
            return name
    return "OTHER"


# ---------------------------------------------------------------------------
# ARM9
# ---------------------------------------------------------------------------

def find_build_info(image, base, hint=None):
    """Return (offset, fields) for the NTR build-info structure.

    ``hint`` is the ARM9-relative offset from ROM header word 0x88 when we
    have it. It is verified rather than trusted; if it does not check out we
    scan for the nitrocode pair instead.
    """
    def check(off):
        if off < 0 or off + 0x24 > len(image):
            return None
        fields = struct.unpack_from("<9I", image, off)
        if fields[7] != NITROCODE or fields[8] != NITROCODE_REV:
            return None
        return fields

    if hint is not None:
        fields = check(hint)
        if fields is not None:
            return hint, fields

    for off in range(0, len(image) - 0x24, 4):
        fields = check(off)
        if fields is not None:
            return off, fields
    raise LayoutError(
        "no ARM9 build-info structure found (nitrocode 0x%08X not present)"
        % NITROCODE
    )


def find_twl_build_info(image):
    """Return (offset, fields) for the TWL build-info structure, or None.

    The TWL structure is shorter than the NTR one: four u32 fields followed
    by the nitrocode pair, 0x18 bytes in total.
    """
    for off in range(0, len(image) - 0x18, 4):
        fields = struct.unpack_from("<6I", image, off)
        if fields[4] == NITROCODE_TWL and fields[5] == NITROCODE_TWL_REV:
            return off, fields[:4]
    return None


def analyse_arm9(arm9_raw, load_addr, entry, build_info_hint):
    """Decompress ARM9 and validate it against its own build info."""
    image = blz.decompress(arm9_raw, 0)
    base = load_addr
    end_va = base + len(image)

    bi_off, f = find_build_info(image, base, build_info_hint)
    (ai_start, ai_end, blocks, bss_start, bss_end,
     comp_end, sdk_version, _nc, _ncr) = f

    def inside(va):
        return base <= va <= end_va

    if not (inside(ai_start) and inside(ai_end)):
        raise LayoutError(
            "autoload info table 0x%08X..0x%08X does not lie inside the "
            "decompressed ARM9 image 0x%08X..0x%08X"
            % (ai_start, ai_end, base, end_va)
        )
    if ai_end < ai_start or (ai_end - ai_start) % AUTOLOAD_ENTRY_SIZE:
        raise LayoutError(
            "autoload info table length 0x%X is not a multiple of %d"
            % (ai_end - ai_start, AUTOLOAD_ENTRY_SIZE)
        )
    if end_va != ai_end:
        raise LayoutError(
            "decompressed ARM9 ends at 0x%08X but the autoload info table "
            "ends at 0x%08X; the two must coincide"
            % (end_va, ai_end)
        )
    if not inside(blocks):
        raise LayoutError(
            "autoload block payloads at 0x%08X lie outside the image" % blocks
        )

    count = (ai_end - ai_start) // AUTOLOAD_ENTRY_SIZE
    autoloads = []
    payload = blocks
    for i in range(count):
        off = (ai_start - base) + i * AUTOLOAD_ENTRY_SIZE
        ram, size, init_start, bss_size = struct.unpack_from("<4I", image, off)
        if size > MAX_SANE_SIZE or bss_size > MAX_SANE_SIZE:
            raise LayoutError(
                "autoload %d: implausible sizes (code 0x%X, bss 0x%X)"
                % (i, size, bss_size)
            )
        kind = classify_address(ram)
        if kind == "OTHER":
            raise LayoutError(
                "autoload %d: destination 0x%08X is in no known hardware "
                "region" % (i, ram)
            )
        if payload + size > ai_start:
            raise LayoutError(
                "autoload %d: payload 0x%08X+0x%X overruns the info table at "
                "0x%08X" % (i, payload, size, ai_start)
            )
        autoloads.append({
            "index": i,
            "kind": kind,
            "ram_start": ram,
            "ram_end": ram + size,
            "code_size": size,
            "bss_size": bss_size,
            "bss_start": ram + size,
            "bss_end": ram + size + bss_size,
            "static_init_start": init_start,
            "src_offset": payload - base,
            "src_ram": payload,
        })
        payload += size

    if payload != ai_start:
        raise LayoutError(
            "autoload payloads end at 0x%08X but the info table starts at "
            "0x%08X; the block area is not fully accounted for"
            % (payload, ai_start)
        )

    info = {
        "load_address": base,
        "entry_point": entry,
        "rom_size": len(arm9_raw),
        "decompressed_size": len(image),
        "build_info_offset": bi_off,
        "build_info": {
            "autoload_infos_start": ai_start,
            "autoload_infos_end": ai_end,
            "autoload_blocks": blocks,
            "bss_start": bss_start,
            "bss_end": bss_end,
            "compressed_code_end": comp_end,
            "sdk_version": sdk_version,
        },
        "static": {
            "name": "arm9_main",
            "ram_start": base,
            "ram_end": blocks,
            "size": blocks - base,
            "src_offset": 0,
            "bss_start": bss_start,
            "bss_end": bss_end,
            "bss_size": bss_end - bss_start,
        },
        "autoloads": autoloads,
    }

    twl = find_twl_build_info(image)
    if twl is not None:
        toff, tf = twl
        info["twl_build_info_offset"] = toff
        info["twl_build_info"] = {
            "autoload_infos_start": tf[0],
            "autoload_infos_end": tf[1],
            "autoload_blocks": tf[2],
            "compressed_code_end": tf[3],
            "note": "describes arm9i.bin, walked only when booted in TWL mode",
        }

    return image, info


# ---------------------------------------------------------------------------
# overlays
# ---------------------------------------------------------------------------

def analyse_overlays(extract_dir, out_dir, quiet=False):
    y9_path = os.path.join(extract_dir, "y9.bin")
    with open(y9_path, "rb") as fh:
        y9 = fh.read()
    if len(y9) % OVERLAY_ENTRY_SIZE:
        raise LayoutError(
            "y9.bin size 0x%X is not a multiple of %d"
            % (len(y9), OVERLAY_ENTRY_SIZE)
        )
    count = len(y9) // OVERLAY_ENTRY_SIZE

    overlays = []
    decompressed = 0
    for i in range(count):
        base = i * OVERLAY_ENTRY_SIZE
        (ov_id, ram, size, bss, init_start, init_end,
         file_id, last) = struct.unpack_from("<8I", y9, base)
        comp_size = last & 0x00FFFFFF
        flags = (last >> 24) & 0xFF
        compressed = bool(flags & OVL_FLAG_COMPRESSED)
        signed = bool(flags & OVL_FLAG_SIGNED)

        if ov_id != i:
            raise LayoutError(
                "overlay table entry %d declares id %d; the table is not in "
                "id order and the rest of the tooling assumes it is"
                % (i, ov_id)
            )
        if size > MAX_SANE_SIZE or bss > MAX_SANE_SIZE:
            raise LayoutError(
                "overlay %d: implausible sizes (code 0x%X, bss 0x%X)"
                % (ov_id, size, bss)
            )
        if init_end < init_start:
            raise LayoutError(
                "overlay %d: static init range 0x%08X..0x%08X is reversed"
                % (ov_id, init_start, init_end)
            )

        src_name = "y9_%04d.bin" % ov_id
        src = os.path.join(extract_dir, "overlays", src_name)
        if not os.path.isfile(src):
            raise LayoutError("overlay %d: %s is missing" % (ov_id, src))
        file_size = os.path.getsize(src)

        rec = {
            "id": ov_id,
            "file_id": file_id,
            "ram_start": ram,
            "ram_end": ram + size,
            "code_size": size,
            "bss_size": bss,
            "bss_start": ram + size,
            "bss_end": ram + size + bss,
            "static_init_start": init_start,
            "static_init_end": init_end,
            "static_init_count": (init_end - init_start) // 4,
            "flags": flags,
            "compressed": compressed,
            "signed": signed,
            "compressed_size": comp_size,
            "file_size": file_size,
            "file": "overlays/" + src_name,
        }

        if compressed:
            if comp_size == 0:
                raise LayoutError(
                    "overlay %d is flagged compressed but its compressed size "
                    "is zero" % ov_id
                )
            if comp_size > file_size:
                raise LayoutError(
                    "overlay %d: compressed size 0x%X exceeds the file size "
                    "0x%X" % (ov_id, comp_size, file_size)
                )
            with open(src, "rb") as fh:
                raw = fh.read()
            try:
                img = blz.decompress(raw[:comp_size], 0, expect_size=size)
            except blz.BlzError as exc:
                raise LayoutError(
                    "overlay %d: BLZ decode failed: %s" % (ov_id, exc)
                ) from exc
            dst_dir = os.path.join(out_dir, "overlays_dec")
            os.makedirs(dst_dir, exist_ok=True)
            dst = os.path.join(dst_dir, src_name)
            with open(dst, "wb") as fh:
                fh.write(img)
            rec["decompressed_file"] = "overlays_dec/" + src_name
            rec["decompressed_size"] = len(img)
            decompressed += 1
        else:
            if comp_size not in (0, file_size):
                raise LayoutError(
                    "overlay %d is not flagged compressed but its size field "
                    "0x%X matches neither 0 nor the file size 0x%X"
                    % (ov_id, comp_size, file_size)
                )
            if file_size != size:
                raise LayoutError(
                    "overlay %d: uncompressed file is 0x%X bytes but the "
                    "table says 0x%X" % (ov_id, file_size, size)
                )
            rec["decompressed_file"] = rec["file"]
            rec["decompressed_size"] = file_size

        overlays.append(rec)

    if not quiet:
        print("    %d overlays, %d BLZ-compressed, %d stored"
              % (count, decompressed, count - decompressed))
    return overlays


# ---------------------------------------------------------------------------
# report
# ---------------------------------------------------------------------------

def write_text_report(path, layout):
    a9 = layout["arm9"]
    lines = []
    add = lines.append
    add("aletheia memory layout")
    add("generated by tools/delink.py; addresses and sizes only, no game data")
    add("")
    add("ARM9")
    add("  ROM image          0x%06X bytes (BLZ compressed)"
        % a9["rom_size"])
    add("  decompressed       0x%06X bytes" % a9["decompressed_size"])
    add("  load address       0x%08X" % a9["load_address"])
    add("  entry point        0x%08X" % a9["entry_point"])
    add("  build info at      arm9 + 0x%X" % a9["build_info_offset"])
    add("  sdk_version        0x%08X" % a9["build_info"]["sdk_version"])
    add("")
    add("  region        ram start   ram end     size      src off   bss")
    st = a9["static"]
    add("  %-12s 0x%08X  0x%08X  0x%06X  0x%06X  0x%08X..0x%08X"
        % ("main", st["ram_start"], st["ram_end"], st["size"],
           st["src_offset"], st["bss_start"], st["bss_end"]))
    for al in a9["autoloads"]:
        add("  %-12s 0x%08X  0x%08X  0x%06X  0x%06X  0x%08X..0x%08X"
            % ("autoload%d/%s" % (al["index"], al["kind"]),
               al["ram_start"], al["ram_end"], al["code_size"],
               al["src_offset"], al["bss_start"], al["bss_end"]))
    add("")
    add("  autoload details")
    add("    #  kind      ram         code    bss     static_init")
    for al in a9["autoloads"]:
        add("    %-2d %-9s 0x%08X  0x%04X  0x%04X  0x%08X"
            % (al["index"], al["kind"], al["ram_start"], al["code_size"],
               al["bss_size"], al["static_init_start"]))
    if "twl_build_info" in a9:
        t = a9["twl_build_info"]
        add("")
        add("  TWL build info at arm9 + 0x%X (describes arm9i.bin)"
            % a9["twl_build_info_offset"])
        add("    autoload infos  0x%08X..0x%08X"
            % (t["autoload_infos_start"], t["autoload_infos_end"]))
        add("    autoload blocks 0x%08X" % t["autoload_blocks"])
        add("    compressed end  0x%08X" % t["compressed_code_end"])

    ovs = layout["overlays"]
    comp = sum(1 for o in ovs if o["compressed"])
    add("")
    add("Overlays (%d total, %d compressed, %d stored)"
        % (len(ovs), comp, len(ovs) - comp))
    add("  id   ram start   ram end     code    bss     file  fl  cmp  "
        "static_init")
    for o in ovs:
        add("  %-4d 0x%08X  0x%08X  0x%06X  0x%06X  %-5d 0x%02X %-4s "
            "0x%08X..0x%08X (%d)"
            % (o["id"], o["ram_start"], o["ram_end"], o["code_size"],
               o["bss_size"], o["file_id"], o["flags"],
               "yes" if o["compressed"] else "no",
               o["static_init_start"], o["static_init_end"],
               o["static_init_count"]))
    add("")

    with open(path, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("\n".join(lines))


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def cmd_run(args):
    extract_dir = os.path.abspath(args.extract)
    layout_dir = os.path.abspath(args.layout)

    header_path = os.path.join(extract_dir, "header.bin")
    arm9_path = os.path.join(extract_dir, "arm9.bin")
    for p in (header_path, arm9_path):
        if not os.path.isfile(p):
            raise LayoutError("missing %s; run ndsrom.py extract first" % p)

    with open(header_path, "rb") as fh:
        header = fh.read()
    with open(arm9_path, "rb") as fh:
        arm9_raw = fh.read()

    load_addr = u32(header, 0x28)
    entry = u32(header, 0x24)
    build_info_hint = u32(header, 0x88)

    print("[*] arm9 0x%X bytes, load 0x%08X, entry 0x%08X, build info hint "
          "0x%X" % (len(arm9_raw), load_addr, entry, build_info_hint))

    image, a9 = analyse_arm9(arm9_raw, load_addr, entry, build_info_hint)
    dec_path = os.path.join(extract_dir, "arm9_dec.bin")
    with open(dec_path, "wb") as fh:
        fh.write(image)
    a9["decompressed_file"] = "arm9_dec.bin"
    print("    decompressed to 0x%X bytes -> %s" % (len(image), dec_path))
    print("    validated: image ends at 0x%08X == autoload_infos_end"
          % (load_addr + len(image)))
    print("    %d autoload blocks: %s"
          % (len(a9["autoloads"]),
             ", ".join("%s@0x%08X" % (al["kind"], al["ram_start"])
                       for al in a9["autoloads"])))

    overlays = analyse_overlays(extract_dir, extract_dir, quiet=False)

    layout = {
        "tool": "delink.py",
        "version": 1,
        "note": "addresses, sizes and names only; contains no game data",
        "extract_dir": os.path.relpath(extract_dir, os.path.dirname(layout_dir))
        .replace(os.sep, "/"),
        "arm9": a9,
        "overlays": overlays,
        "counts": {
            "autoloads": len(a9["autoloads"]),
            "overlays": len(overlays),
            "overlays_compressed": sum(1 for o in overlays if o["compressed"]),
        },
    }

    os.makedirs(layout_dir, exist_ok=True)
    jpath = os.path.join(layout_dir, "layout.json")
    with open(jpath, "w", encoding="utf-8", newline="\n") as fh:
        json.dump(layout, fh, indent=1)
        fh.write("\n")
    tpath = os.path.join(layout_dir, "layout.txt")
    write_text_report(tpath, layout)
    print("[*] wrote %s" % jpath)
    print("[*] wrote %s" % tpath)
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(
        prog="delink.py",
        description="Describe the ARM9 and overlay memory layout of the game.",
    )
    ap.add_argument("-e", "--extract", default="extract",
                    help="directory produced by ndsrom.py extract")
    ap.add_argument("-l", "--layout", default="layout",
                    help="directory to write layout.json and layout.txt into")
    ap.set_defaults(func=cmd_run)
    args = ap.parse_args(argv)
    try:
        return args.func(args)
    except (LayoutError, blz.BlzError) as exc:
        print("error: %s" % exc, file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
