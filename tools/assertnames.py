#!/usr/bin/env python3
"""assertnames.py -- harvest the assert expression strings of the ROM.

The GF assert macro embeds its condition as a string (for example
``netID < GFL_NET_MACHINE_MAX``).  Those strings are the only place the
original developers' identifiers (locals, fields, constants, file statics)
appear in the image.  This tool finds every such string in every region,
finds the function whose literal pool references it, and writes a TSV:

    region  string_addr  function  expression  identifiers

Output goes to stdout (or --out FILE).  It writes no game data to the repo
by itself; the TSV holds expression text, so keep it out of git.

Usage: python tools/assertnames.py [--out FILE]
"""
import argparse
import bisect
import os
import re
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import match  # noqa: E402

RUN = re.compile(rb"[\x20-\x7e]{6,160}\x00")
OPS = re.compile(r"->|==|!=|<=|>=|&&|\|\||[<>]|\w\s*\[|\w\s*&\s*\w|!\s*\w")
IDENT = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")
C_KEYWORDS = {"if", "else", "NULL", "TRUE", "FALSE", "sizeof", "int", "u8",
              "u16", "u32", "s32", "BOOL"}
# identifiers that are plain data words of the SDK/runtime, not GF names
FUNC_LABEL = re.compile(r"^\s*\.type\s+(\w+),\s*%function", re.M)
ADDR_CMT = re.compile(r"/\*\s*([0-9A-Fa-f]{8})\s")
LABEL = re.compile(r"^(\w+):\s*$")


def looks_like_expr(s):
    if not OPS.search(s):
        return False
    ids = [i for i in IDENT.findall(s) if i not in C_KEYWORDS]
    if not ids:
        return False
    # text noise: many words separated by single spaces without operators
    if "://" in s or "<?" in s or "%" in s or "=" in s and "?" in s:
        return False
    if re.search(r"[@#$^`~]|\\", s) or s.startswith(("<", "-")):
        return False
    words = s.split()
    if len(words) > 8:
        return False
    # an expression has no sentence punctuation
    if re.search(r"[.,;:?]\s", s) or s.endswith((".", ",")):
        return False
    return True


def function_table(region):
    """Sorted (address, name) of the functions in a region's listings."""
    out = []
    for path in match.listing_files(region):
        try:
            lines = open(path, encoding="utf-8", errors="replace").read().split("\n")
        except OSError:
            continue
        for i, ln in enumerate(lines):
            m = re.match(r"\s*\.type\s+(\w+),\s*%function", ln)
            if not m:
                continue
            name = m.group(1)
            for j in range(i + 1, min(i + 6, len(lines))):
                a = ADDR_CMT.search(lines[j])
                if a:
                    out.append((int(a.group(1), 16), name))
                    break
    out.sort()
    return out


def classify(expr, fname):
    """Split identifiers into kinds by syntax."""
    ids = []
    for m in re.finditer(r"[A-Za-z_][A-Za-z0-9_]*(?:\s*(?:->|\.)\s*[A-Za-z_][A-Za-z0-9_]*|\s*\[[^\]]*\])*", expr):
        t = m.group(0).replace(" ", "")
        if t.split("->")[0] in C_KEYWORDS:
            continue
        ids.append(t)
    return ids


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out")
    args = ap.parse_args()
    rows = []
    for r in match.load_all_regions():
        data = bytes(r.data)
        cands = {}
        for m in RUN.finditer(data):
            s = m.group(0)[:-1].decode("ascii")
            # strings start at an aligned-or-not boundary; require preceding NUL
            st = m.start()
            if st and data[st - 1] != 0:
                continue
            if looks_like_expr(s):
                cands[r.base + st] = s
        if not cands:
            continue
        # pool words
        refs = {}
        n = len(data) & ~3
        for off in range(0, n, 4):
            v = struct.unpack_from("<I", data, off)[0]
            if v in cands:
                refs.setdefault(v, []).append(r.base + off)
        ft = function_table(r.name)
        addrs = [a for a, _ in ft]
        for a, s in sorted(cands.items()):
            if a not in refs:
                continue
            for site in refs[a]:
                k = bisect.bisect_right(addrs, site) - 1
                fn = ft[k][1] if k >= 0 else "?"
                rows.append((r.name, "%08X" % a, fn, s,
                             " ".join(classify(s, fn))))
    out = open(args.out, "w", encoding="utf-8") if args.out else sys.stdout
    out.write("region\tstring_addr\tfunction\texpression\tidentifiers\n")
    for row in rows:
        out.write("\t".join(row) + "\n")
    sys.stderr.write("%d rows\n" % len(rows))


if __name__ == "__main__":
    main()
