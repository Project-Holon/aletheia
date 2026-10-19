#!/usr/bin/env python3
"""typemerge.py: define a family of types once, in one header.

Every full definition of one of NAMES (struct/union/enum with a body, by tag or
typedef name) and every plain alias of it (`typedef struct X X;`) is removed from
the src/game files that carry a copy.  The first removed statement of a file
becomes `#include "<path>/HEADER"`.  The header itself is not touched.

Nothing here knows whether the shared definition is the same layout as a local
copy: run tools/gameverify.py (and hostcheck) afterwards and put back the files
that no longer compile or match (--skip FILE keeps a file out of the run).

    python tools/typemerge.py --header src/game/fx.h --names VecFx32,MtxFx33
    python tools/typemerge.py --header src/game/fx.h --names ... --apply [--changed OUT] [--skip LIST]
"""
import argparse
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
GAME = os.path.join(ROOT, "src", "game")
NL = chr(10)


def mask(text):
    """Same-length copy with comments, strings, char literals and preprocessor lines blanked."""
    out = list(text)
    i, n = 0, len(text)
    line_start = True
    while i < n:
        c = text[i]
        if text.startswith("/*", i):
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
            for k in range(i, j):
                if out[k] != "\n":
                    out[k] = " "
            i = j
            continue
        if text.startswith("//", i):
            j = text.find("\n", i)
            j = n if j < 0 else j
            for k in range(i, j):
                out[k] = " "
            i = j
            continue
        if c in "\"'":
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == "\\" else 1
            for k in range(i, min(j + 1, n)):
                if out[k] != "\n":
                    out[k] = " "
            i = j + 1
            continue
        if c == "#" and not text[text.rfind(NL, 0, i) + 1:i].strip():
            j = i
            while j < n:
                e = text.find("\n", j)
                if e < 0:
                    j = n
                    break
                if text[e - 1] == "\\" or (e > 0 and text[e - 1] == "\r" and text[e - 2] == "\\"):
                    j = e + 1
                    continue
                j = e
                break
            for k in range(i, j):
                if out[k] != "\n":
                    out[k] = " "
            i = j
            continue
        i += 1
    return "".join(out)


def depth_at(m):
    d, cur = [], 0
    for ch in m:
        if ch == "{":
            d.append(cur)
            cur += 1
        elif ch == "}":
            cur -= 1
            d.append(cur)
        else:
            d.append(cur)
    return d


DEF_RE = re.compile(r"(?:\btypedef\s+)?\b(struct|union|enum)\s*([A-Za-z_]\w*)?\s*\{")


def match_brace(m, i):
    depth = 0
    for j in range(i, len(m)):
        if m[j] == "{":
            depth += 1
        elif m[j] == "}":
            depth -= 1
            if depth == 0:
                return j
    return -1


def find_spans(text, names):
    """(start, end) of each statement to remove; end is after the `;`."""
    m = mask(text)
    dm = depth_at(m)
    spans = []
    skipped = []
    for mm in DEF_RE.finditer(m):
        if dm[mm.start()] != 0:
            continue
        lb = mm.end() - 1
        rb = match_brace(m, lb)
        if rb < 0:
            continue
        semi = m.find(";", rb)
        if semi < 0:
            continue
        tail = m[rb + 1:semi]
        is_td = m[mm.start():mm.start() + 7] == "typedef"
        tag = mm.group(2)
        tdn = []
        if is_td:
            tdn = [p.strip() for p in tail.split(",")]
        hit = (tag in names) or any(t in names for t in tdn)
        if not hit:
            continue
        if is_td and (len(tdn) != 1 or not re.fullmatch(r"\w+", tdn[0])):
            skipped.append(text[mm.start():semi + 1][:60])
            continue
        if not is_td and tail.strip():
            skipped.append(text[mm.start():semi + 1][:60])
            continue
        if is_td and tdn[0] not in names and tag in names:
            skipped.append("tag only: " + text[mm.start():mm.start() + 50])
            continue
        spans.append((mm.start(), semi + 1))
    # plain aliases and forward declarations
    for mm in re.finditer(r"\btypedef\s+(?:struct|union|enum)\s+\w+\s+(\w+)\s*;", m):
        if dm[mm.start()] == 0 and mm.group(1) in names:
            spans.append((mm.start(), mm.end()))
    for mm in re.finditer(r"(?<![\w])(?:struct|union)\s+(\w+)\s*;", m):
        if dm[mm.start()] == 0 and mm.group(1) in names and \
                not m[:mm.start()].rstrip().endswith("typedef"):
            spans.append((mm.start(), mm.end()))
    # scalar and function-pointer typedefs of a listed name
    for mm in re.finditer(r"\btypedef\b[^;{}]*;", m):
        if dm[mm.start()] != 0:
            continue
        stmt = mm.group(0)
        fp = re.search(r"\(\s*\*\s*(\w+)\s*\)\s*\(", stmt)
        nm = fp.group(1) if fp else (re.findall(r"\w+", stmt)[-1] if "(" not in stmt else None)
        if nm in names and not re.match(r"typedef\s+(struct|union|enum)\s+\w+\s+\w+\s*;", stmt):
            spans.append((mm.start(), mm.end()))
    spans = sorted(set(spans))
    # drop spans nested inside another
    res = []
    for s in spans:
        if res and s[0] < res[-1][1]:
            continue
        res.append(s)
    return res, skipped


def process(path, header, names, apply):
    raw = open(path, encoding="latin1", newline="").read()
    crlf = "\r\n" in raw
    text = raw.replace("\r\n", "\n")
    spans, skipped = find_spans(text, names)
    if not spans:
        return 0, skipped
    inc = os.path.relpath(header, os.path.dirname(path)).replace(os.sep, "/")
    inc_line = '#include "%s"' % inc
    already = inc_line in text
    out, pos = [], 0
    first = True
    # the header goes after the file's own types.h include (and the GAME_TYPES_ defines before it)
    tm = re.search(r'#include "[^"]*types\.h"[ \t]*\n', text)
    late = None
    if tm and spans[0][0] < tm.end() and not already and os.path.basename(header) != "types.h":
        late = tm.end()
        first = False
    for s, e in spans:
        # swallow the rest of the line and one following blank line
        while e < len(text) and text[e] in " \t":
            e += 1
        if e < len(text) and text[e] == "\n":
            e += 1
        if text[e:e + 1] == "\n":
            e += 1
        # trailing comment on the removed line stays out of the way: not handled
        out.append(text[pos:s])
        if first and not already:
            out.append(inc_line + "\n\n")
        first = False
        pos = e
    out.append(text[pos:])
    res = "".join(out)
    if late is not None:
        k = res.find(tm.group(0)) + len(tm.group(0))
        res = res[:k] + "\n" + inc_line + "\n" + res[k:]
    res = re.sub(r"\n{3,}", "\n\n", res) if False else res
    if apply:
        if crlf:
            res = res.replace("\n", "\r\n")
        with open(path, "w", encoding="latin1", newline="") as fh:
            fh.write(res)
    return len(spans), skipped


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--header", required=True)
    ap.add_argument("--names", required=True)
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--changed")
    ap.add_argument("--skip", help="file listing paths to leave alone")
    a = ap.parse_args()
    header = os.path.abspath(a.header)
    names = set(a.names.split(","))
    skip = set()
    if a.skip and os.path.exists(a.skip):
        skip = {os.path.abspath(os.path.join(ROOT, l.strip())) for l in open(a.skip) if l.strip()}
    changed, nspans, allskipped = [], 0, []
    for dp, _dn, fn in os.walk(GAME):
        for f in sorted(fn):
            p = os.path.abspath(os.path.join(dp, f))
            if not f.endswith((".c", ".h")) or p == header or p in skip:
                continue
            n, sk = process(p, header, names, a.apply)
            for s in sk:
                allskipped.append((p, s))
            if n:
                changed.append(p)
                nspans += n
    print("files changed: %d, statements removed: %d, left alone: %d" % (len(changed), nspans, len(allskipped)))
    for p, s in allskipped:
        print("  left: %s: %s" % (os.path.relpath(p, ROOT).replace(os.sep, "/"), s.replace("\n", " ")))
    if a.changed:
        with open(a.changed, "w", encoding="utf-8", newline="\n") as fh:
            fh.write("\n".join(os.path.relpath(c, ROOT).replace(os.sep, "/") for c in changed) + "\n")


if __name__ == "__main__":
    main()
