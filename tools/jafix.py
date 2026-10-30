#!/usr/bin/env python3
"""jafix.py -- data addresses of a Japanese overlay from its own data-mode link.

A function of the overlay that the source compiles to the target's code loads the same objects
from its literal pools as the target does.  Where a pool word of the link differs from the
target's word at the same place, and the link's word points into a data object of the tail, the
target's word is where that object (at that offset) really is.  This finds objects that the
literal pools of the Black listing cannot place (a pool the target reordered or extended).

    python tools/jafix.py 135 --target black_ja        (or arm9 for the static module)

reads build/gamelink_data/ov135_black_ja/ (ov.bin, ov.elf) and build/datac_black_ja/ov135/datalink.json,
and writes build/black_ja/jafix_ov135.json ({Black address: target address}), which datagen
companions reads as pins.  Run it after a data-mode link; then datagen and the link again.
"""
import argparse
import json
import os
import struct
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import targets  # noqa: E402


def nm_syms(elf):
    tool = next(os.path.join(dp, f) for dp, _d, fs in os.walk(os.path.join(ROOT, "tools", "gcc-arm"))
                for f in fs if f == "arm-none-eabi-nm.exe" or f == "arm-none-eabi-nm")
    out = subprocess.run([tool, "-n", elf], capture_output=True, text=True).stdout
    res = {}
    for ln in out.splitlines():
        p = ln.split()
        if len(p) >= 3:
            res[p[2]] = int(p[0], 16)
    return res


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("overlay", help="overlay number, or arm9 for the static module")
    ap.add_argument("--target", required=True)
    a = ap.parse_args()
    t = a.target
    ext = targets.extract_dir(t)
    lay = json.load(open(os.path.join(targets.layout_dir(t), "layout.json"), encoding="utf-8"))
    if a.overlay == "arm9":
        rg, mod = "arm9", "arm9_main"
        st = lay["arm9"]["static"]
        tgt = open(os.path.join(ext, "arm9_dec.bin"), "rb").read()[st["src_offset"]:st["src_offset"] + st["size"]]
        base, end = st["ram_start"], st["ram_start"] + st["size"]
    else:
        n = int(a.overlay)
        rg = mod = "ov%03d" % n
        p = os.path.join(ext, "overlays_dec", "y9_%04d.bin" % n)
        if not os.path.exists(p):
            p = os.path.join(ext, "overlays", "y9_%04d.bin" % n)
        tgt = open(p, "rb").read()
        o = [x for x in lay["overlays"] if x["id"] == n][0]
        base, end = o["ram_start"], o["ram_start"] + o["code_size"]
    d = os.path.join(ROOT, "build", "gamelink_data", "%s_%s" % (mod, t))
    ours = open(os.path.join(d, "ov.bin"), "rb").read()
    dl = json.load(open(os.path.join(ROOT, "build", "datac_" + t, rg, "datalink.json"), encoding="utf-8"))
    syms = nm_syms(os.path.join(d, "ov.elf"))
    # the objects of the tail in our link: (our address, size, Black address)
    objs = sorted((syms[nm], sz, int(ba, 16)) for ba, sz, sec, _f, nm in dl["plan"]
                  if nm in syms and int(ba, 16) < 0xA0000000 and sec != ".bss")
    starts = [x[0] for x in objs]
    tail0 = min(starts) if starts else end
    fix_p = os.path.join(targets.build_dir(t), "jafix_%s.json" % rg)
    try:
        fix = {int(k, 16): v for k, v in json.load(open(fix_p)).items()}
    except (OSError, ValueError):
        fix = {}
    import bisect
    found = 0
    for off in range(0, min(len(ours), len(tgt), tail0 - base) - 3, 4):
        w_o, w_t = struct.unpack_from("<I", ours, off)[0], struct.unpack_from("<I", tgt, off)[0]
        if w_o == w_t or not (tail0 <= w_o < end + 0x10000) or not (base <= w_t < end):
            continue
        k = bisect.bisect_right(starts, w_o) - 1
        if k < 0:
            continue
        sa, sz, ba = objs[k]
        if not (sa <= w_o < sa + max(sz, 1)):
            continue
        fix[ba + (w_o - sa)] = w_t
        found += 1
    with open(fix_p, "w", newline="\n") as fh:
        json.dump({"%08X" % k: v for k, v in sorted(fix.items())}, fh, indent=0)
    print("%s %s: %d pool words, %d addresses in %s" % (rg, t, found, len(fix), os.path.relpath(fix_p, ROOT)))


if __name__ == "__main__":
    main()
