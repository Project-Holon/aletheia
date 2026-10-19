#!/usr/bin/env python3
"""Count or list placeholder names left in src/game: struct fields, parameters and locals
named by offset or position instead of by meaning.

  fields:  struct members named fXX, fieldXX, field_0xXX, unkXX, unk_XX, xXX (hex offset)
  params:  parameters of function definitions named aN, argN, paramN, pN
  proto:   the same in prototypes (extern declarations); counted apart
  locals:  locals named aN, argN, paramN, vN, tmpN, varN, localN

Comments are ignored. `pad` members are not counted: padding that nothing reads is a
legitimate name.

    python tools/placeholdernames.py                 summary per region and total
    python tools/placeholdernames.py --list PATH...  every hit (file:line kind name); PATH is
                                                     a file or a directory under src/game
"""
import argparse
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GAME = os.path.join(ROOT, "src", "game")

FIELD = re.compile(r"^\s+(?:const\s+|volatile\s+|struct\s+|unsigned\s+|signed\s+)*[A-Za-z_]\w*[\s\*]+\**"
                   # an offset spelling: a digit in it, upper-case hex, or at most two hex
                   # characters (fC, fa); a lower-case word such as `fade` is a real name
                   r"((?:f|x)(?:[0-9A-Fa-f]*[0-9][0-9A-Fa-f]*|[0-9A-F]{1,4}|[0-9A-Fa-f]{1,2})(?![0-9A-Za-z_])"
                   r"|(?:field_?(?:0x)?|unk_?(?:0x)?)[0-9A-Fa-f]{1,4})\s*(?:\[[^\]]*\]\s*)*(?::\s*\d+\s*)?;")
PARAM = re.compile(r"\b((?:a|arg|param|p)[0-9])\s*(?=[,\[]|$)")
LOCAL = re.compile(r"^\s+(?:const\s+|volatile\s+|register\s+|struct\s+|unsigned\s+|signed\s+)*[A-Za-z_]\w*[\s\*]+\**"
                   r"((?:a|arg|param|v|tmp|var|local)[0-9]+)\s*(?:\[[^\]]*\]\s*)*(?:=|;|,)")


def strip_comments(text):
    """Comments blanked, newlines kept, so line numbers stay right."""
    return re.sub(r"/\*.*?\*/|//[^\n]*", lambda m: re.sub(r"[^\n]", " ", m.group(0)), text, flags=re.S)


NL = chr(10)
DECL = re.compile(r"\b[A-Za-z_]\w*\s*\(((?:[^;{}()]|\([^;{}()]*\))*)\)\s*(?=[{;])", re.S)


def scan(path):
    text = strip_comments(open(path, encoding="latin1").read())
    hits = []
    # brace depth at every line start, so a top-level declaration can be told from a call
    depth_at = []
    depth = 0
    for line in text.split(NL):
        depth_at.append(depth)
        depth = max(0, depth + line.count("{") - line.count("}"))
    starts = [0]
    for i, ch in enumerate(text):
        if ch == NL:
            starts.append(i + 1)
    import bisect
    for s in DECL.finditer(text):
        no = bisect.bisect_right(starts, s.start())
        if depth_at[no - 1] != 0:
            continue
        kind = "param" if text[s.end():s.end() + 1] == "{" or text[s.end():].lstrip()[:1] == "{" else "proto"
        for p in PARAM.finditer(s.group(1)):
            hits.append((no, kind, p.group(1)))
    for no, line in enumerate(text.split(NL), 1):
        if depth_at[no - 1] > 0:
            m = FIELD.match(line)
            if m:
                hits.append((no, "field", m.group(1)))
                continue
            m = LOCAL.match(line)
            if m:
                hits.append((no, "local", m.group(1)))
    return hits


def files_under(paths):
    for p in paths:
        p = os.path.join(ROOT, p) if not os.path.isabs(p) else p
        if os.path.isfile(p):
            yield p
            continue
        for d, _, fs in os.walk(p):
            for f in sorted(fs):
                if f.endswith((".c", ".h")):
                    yield os.path.join(d, f)


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--list", nargs="+", metavar="PATH")
    a = ap.parse_args()
    if a.list:
        for f in files_under(a.list):
            rel = os.path.relpath(f, ROOT).replace(os.sep, "/")
            for no, kind, name in scan(f):
                print("%s:%d\t%s\t%s" % (rel, no, kind, name))
        return
    per = {}
    for f in files_under([GAME]):
        region = os.path.relpath(f, GAME).replace(os.sep, "/").split("/")[0]
        c = per.setdefault(region, {"field": 0, "param": 0, "local": 0, "proto": 0})
        for _, kind, _ in scan(f):
            c[kind] += 1
    tot = {"field": 0, "param": 0, "local": 0, "proto": 0}
    for r in sorted(per, key=lambda r: -sum(per[r].values())):
        c = per[r]
        if sum(c.values()):
            print("%-22s fields %5d  params %5d  locals %5d  prototype params %5d" % (r, c["field"], c["param"], c["local"], c["proto"]))
        for k in tot:
            tot[k] += c[k]
    print("placeholder names: fields %d, params %d, locals %d, total %d (plus %d prototype params)"
          % (tot["field"], tot["param"], tot["local"], tot["field"] + tot["param"] + tot["local"], tot["proto"]))


if __name__ == "__main__":
    main()
