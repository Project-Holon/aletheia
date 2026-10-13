#!/usr/bin/env python3
"""Generate gitignored include files that hold game bytes for .text data.

Some functions are followed, inside their code extent, by data words (key
tables, literal blocks) that a source file has to lay out in .text.  The bytes
come from the user's own extracted ROM and must never be written into a
committed file.  This tool reads them through tools/match.py (target_bytes)
and writes an include file under build/gen/ (build/ is gitignored).  The
source file includes it from inside an `asm` body:

    asm void data_0272EB9C(void)
    {
    #include "../../../build/gen/twl_0272EB9C.inc"
    }

Usage:
    python tools/gendata.py              # every entry of SPECS
    python tools/gendata.py NAME         # one entry
    python tools/gendata.py --addr 0x0272EB9C --size 64 --region twl --out x.inc
"""
import argparse
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)

OUT_DIR = os.path.join(ROOT, "build", "gen")

# name -> (address, size in bytes, region)
SPECS = {
    "twl_0272EB9C": (0x0272EB9C, 64, "twl"),
    "microcode_02004F94": (0x02004F94, 28, "arm9"),
    "microcode_02004FD4": (0x02004FD4, 40, "arm9"),
    "microcode_02004FFC": (0x02004FFC, 52, "arm9"),
    # ov119 pokemontrade_3d.c: the fx16 vertex table d_021E8190 (24 halfwords)
    "h16_ov119_021E8190": (0x021E8190, 48, "ov119"),
}


def render(data, words=False, halves=False):
    """dcd lines for an asm body, (words=True) C initialiser words, or
    (halves=True) C initialiser halfwords."""
    if halves:
        if len(data) % 2:
            raise SystemExit("size must be a multiple of 2")
        return "".join("    0x%04X,\n" % int.from_bytes(data[i:i + 2], "little")
                       for i in range(0, len(data), 2))
    if len(data) % 4:
        raise SystemExit("size must be a multiple of 4")
    lines = []
    for i in range(0, len(data), 4):
        w = int.from_bytes(data[i:i + 4], "little")
        lines.append(("    0x%08XUL," if words else "    dcd 0x%08X") % w)
    return "\n".join(lines) + "\n"


def generate(name, addr, size, region, out=None):
    import match
    _r, data = match.target_bytes(addr, size, region)
    path = out or os.path.join(OUT_DIR, name + ".inc")
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", newline="\n") as fh:
        fh.write(render(data, words=name.startswith("microcode_"), halves=name.startswith("h16_")))
    return path


def generate_all(missing_only=True):
    """Write every SPECS entry (only the missing ones by default)."""
    out = []
    for n in sorted(SPECS):
        path = os.path.join(OUT_DIR, n + ".inc")
        if missing_only and os.path.exists(path):
            continue
        addr, size, region = SPECS[n]
        out.append(generate(n, addr, size, region))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("name", nargs="?")
    ap.add_argument("--addr", type=lambda s: int(s, 0))
    ap.add_argument("--size", type=int)
    ap.add_argument("--region")
    ap.add_argument("--out")
    a = ap.parse_args()
    if a.addr is not None:
        if a.size is None:
            ap.error("--addr needs --size")
        name = a.name or ("%s_%08X" % (a.region or "x", a.addr))
        print(generate(name, a.addr, a.size, a.region, a.out))
        return
    names = [a.name] if a.name else sorted(SPECS)
    for n in names:
        if n not in SPECS:
            ap.error("unknown entry %r" % n)
        addr, size, region = SPECS[n]
        print(generate(n, addr, size, region))


if __name__ == "__main__":
    main()
