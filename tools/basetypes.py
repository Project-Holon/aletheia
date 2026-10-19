#!/usr/bin/env python3
"""basetypes.py: replace every file's own base typedefs (u8, s32, fx32, BOOL, ...)
with one include of src/game/types.h.

A line `typedef unsigned int u32;` (or the long spelling, a `volatile` form, an
`enum { FALSE, TRUE } BOOL`) at file scope outside any #if block is removed; the
first removed line of a file becomes `#include "<path>/types.h"`.  A line whose
meaning differs from the one in types.h is left alone and listed.

    python tools/basetypes.py                 dry run: counts, lines left alone
    python tools/basetypes.py --apply         rewrite the files
    python tools/basetypes.py --apply FILE... only these files
"""
import argparse
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
GAME = os.path.join(ROOT, "src", "game")
TYPES_H = os.path.join(GAME, "types.h")

# name -> (volatile, canonical scalar)
STD = {
    "u8": (0, "u8"), "s8": (0, "s8"), "u16": (0, "u16"), "s16": (0, "s16"),
    "u32": (0, "u32"), "s32": (0, "s32"), "u64": (0, "u64"), "s64": (0, "s64"),
    "vu8": (1, "u8"), "vs8": (1, "s8"), "vu16": (1, "u16"), "vs16": (1, "s16"),
    "vu32": (1, "u32"), "vs32": (1, "s32"), "vu64": (1, "u64"), "vs64": (1, "s64"),
    "fx16": (0, "s16"), "fx32": (0, "s32"), "fx64": (0, "s64"),
    "f32": (0, "float"), "vf32": (1, "float"), "BOOL": (0, "s32"),
}
LINE_RE = re.compile(r"^[ \t]*typedef[ \t]+([A-Za-z_][\w \t]*?)[ \t]+(\w+)[ \t]*;[ \t]*(?:/\*.*?\*/[ \t]*)?$")
ENUM_BOOL_RE = re.compile(r"^[ \t]*typedef[ \t]+enum[ \t]*\{[ \t]*FALSE[ \t]*(?:=[ \t]*0[ \t]*)?,[ \t]*TRUE[ \t]*(?:=[ \t]*1[ \t]*)?\}[ \t]*BOOL[ \t]*;[ \t]*$")


def scalar_of(words):
    w = list(words)
    vol = 1 if "volatile" in w else 0
    w = [x for x in w if x != "volatile"]
    if len(w) == 1 and w[0] in STD and w[0] not in ("BOOL",):
        v, c = STD[w[0]]
        return v | vol, c
    uns = "unsigned" in w
    sig = "signed" in w
    w = [x for x in w if x not in ("signed", "unsigned")]
    if w == ["float"]:
        return vol, "float"
    if w.count("long") == 2 and all(x == "long" or x == "int" for x in w):
        return vol, "u64" if uns else "s64"
    if w in (["char"],):
        if uns:
            return vol, "u8"
        return (vol, "s8") if sig else (vol, "char")
    if w in (["short"], ["short", "int"]):
        return vol, "u16" if uns else "s16"
    if w in (["int"], ["long"], ["long", "int"], []):
        return vol, "u32" if uns else "s32"
    return None


def accepts(name, words):
    if name not in STD:
        return False
    got = scalar_of(words)
    return got is not None and got == STD[name]


def process(path, apply):
    raw = open(path, encoding="latin1", newline="").read()
    crlf = "\r\n" in raw
    text = raw.replace("\r\n", "\n")
    lines = text.split("\n")
    out, removed, left = [], 0, []
    in_comment = False
    ifdepth = 0
    first = None
    guard = None                 # name of the include guard, once seen
    stack = []                   # True for the include guard's #if, False for others
    seen_code = False
    for idx, ln in enumerate(lines):
        s = ln
        keep = True
        # comment tracking (a line that opens or closes a block comment is never a typedef line)
        stripped = s.strip()
        was_comment = in_comment
        i = 0
        tmp = s
        while True:
            if in_comment:
                j = tmp.find("*/")
                if j < 0:
                    break
                in_comment = False
                tmp = tmp[j + 2:]
            else:
                j = tmp.find("/*")
                if j < 0:
                    break
                k = tmp.find("*/", j + 2)
                if k < 0:
                    in_comment = True
                    break
                tmp = tmp[:j] + tmp[k + 2:]
        if not was_comment and not in_comment:
            m = re.match(r"\s*#\s*(if|ifdef|ifndef|else|elif|endif)\b", s)
            if m:
                kind = m.group(1)
                if kind == "endif":
                    if stack and not stack.pop():
                        ifdepth -= 1
                elif kind in ("else", "elif"):
                    pass
                else:
                    is_guard = False
                    if kind == "ifndef":
                        gm = re.match(r"\s*#\s*ifndef\s+(\w+)", s)
                        for nxt in lines[idx + 1:idx + 4]:
                            if nxt.strip() == "":
                                continue
                            if gm and re.match(r"\s*#\s*define\s+%s\b" % gm.group(1), nxt):
                                is_guard = True
                            break
                    stack.append(is_guard)
                    if is_guard:
                        guard = True
                    else:
                        ifdepth += 1
                seen_code = True
            elif ifdepth == 0 and "typedef" in s:
                if ENUM_BOOL_RE.match(s):
                    keep = False
                else:
                    mm = LINE_RE.match(s)
                    if mm:
                        words = mm.group(1).split()
                        name = mm.group(2)
                        if name in STD and "{" not in s:
                            if accepts(name, words):
                                keep = False
                            else:
                                left.append((path, s.strip()))
        if stripped and not was_comment and not in_comment and not stripped.startswith(('/*', '//', '*')):
            seen_code = True
        if keep:
            out.append(s)
        else:
            removed += 1
            if first is None:
                first = len(out)
                out.append(None)          # placeholder for the include
    if removed == 0:
        return 0, left
    inc = os.path.relpath(TYPES_H, os.path.dirname(path)).replace(os.sep, "/")
    out[first] = '#include "%s"' % inc
    # a blank line left behind by each removed typedef: collapse runs of blank lines to one
    new = []
    for ln in out:
        if ln == "" and new and new[-1] == "" :
            continue
        new.append(ln)
    res = "\n".join(new)
    if apply:
        if crlf:
            res = res.replace("\n", "\r\n")
        with open(path, "w", encoding="latin1", newline="") as fh:
            fh.write(res)
    return removed, left


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--changed", help="write the changed file list here")
    ap.add_argument("files", nargs="*")
    a = ap.parse_args()
    files = a.files
    if not files:
        for dp, _dn, fn in os.walk(GAME):
            for f in fn:
                if f.endswith((".c", ".h")) and f != "types.h" and os.path.join(dp, f) != TYPES_H:
                    files.append(os.path.join(dp, f))
    files = sorted(os.path.abspath(f) for f in files)
    nfiles = nlines = 0
    left_all, changed = [], []
    for f in files:
        n, left = process(f, a.apply)
        if n:
            nfiles += 1
            nlines += n
            changed.append(f)
        left_all += left
    print("files with base typedefs: %d, lines removed: %d" % (nfiles, nlines))
    print("lines left alone (different meaning or form): %d" % len(left_all))
    for p, l in left_all:
        print("  %s: %s" % (os.path.relpath(p, ROOT).replace(os.sep, "/"), l))
    if a.changed:
        with open(a.changed, "w", encoding="utf-8", newline="\n") as fh:
            fh.write("\n".join(os.path.relpath(c, ROOT).replace(os.sep, "/") for c in changed) + "\n")


if __name__ == "__main__":
    main()
