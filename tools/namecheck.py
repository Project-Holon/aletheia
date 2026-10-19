#!/usr/bin/env python3
"""Flag function names that may not say what the body does (for a human or lane to read).

Per function definition in src/game: its name, the functions its body calls, and flags:

  OFFSET   the name spells an offset or an address (GetField1C, Check09E0, Func1A3C, _0FE4)
  VERB     the name's verb disagrees with the callees: a Get/Is/Check/Has/Can whose body
           calls state-changing functions (Add, Remove, Delete, Set, Create, Alloc, Free,
           Learn, Start, Clear, Change), an Add/Insert that calls only Remove/Delete/Sub,
           a Remove/Delete/Sub that calls only Add/Insert, a Create/Init/Alloc that calls
           only Delete/Free/Exit
  PREFIX   the module prefix differs from the file's most common prefix (a function of
           another module, or a file holding several originals)

A flag is a reason to read the body, not a verdict.

    python tools/namecheck.py [PATH ...] [--flags OFFSET,VERB,PREFIX] [--all]
PATH is a file or a directory under src/game (default: all of src/game). Output is TSV:
file, line, name, flags, callees (first 12).
"""
import argparse
import collections
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import placeholdernames as ph  # noqa: E402

OFFSET = re.compile(r"(?:_(?:Get|Set|Check|Is|Has)?(?:Field|Unk|State|Flag|Word|Byte|Value|Param)[0-9A-F]{1,4}$"
                    r"|_Check[0-9A-F]{3,4}$|_Func[0-9A-F]{3,4}$|_Sub[0-9A-F]{2,4}$|_[0-9A-F]{4}$"
                    r"|_(?:Get|Set|Check|Create|Callback)_?[0-9A-F]{4}$)")
CHANGE = re.compile(r"(?:Add|Remove|Delete|Set|Create|Alloc|Free|Learn|Start|Clear|Change|Insert|Push|Pop|Write|Store|Init|Exit|Swap|Move)")
CALL = re.compile(r"\b([A-Za-z_]\w*)\s*\(")
KEYWORDS = {"if", "while", "for", "switch", "return", "sizeof", "do"}


def prefix(name):
    m = re.match(r"^([A-Z][A-Z0-9]*(?:_[A-Z][A-Z0-9]*)*?)_[A-Z][a-z]", name)
    return m.group(1) if m else None


def verb(name):
    m = re.match(r"^(?:[A-Z][A-Z0-9]*_)+([A-Z][a-z]+)", name)
    return m.group(1) if m else None


def defs(path):
    text = ph.strip_comments(open(path, encoding="latin1").read())
    out = []
    for m in re.finditer(r"^[A-Za-z_][^;{}()\n]*?\b([A-Za-z_]\w*)\s*\(([^;{}]*)\)\s*\{", text, re.M):
        name = m.group(1)
        if name in KEYWORDS:
            continue
        i = m.end()
        depth = 1
        while i < len(text) and depth:
            c = text[i]
            if c == "{":
                depth += 1
            elif c == "}":
                depth -= 1
            i += 1
        body = text[m.end():i]
        calls = [c for c in CALL.findall(body) if c not in KEYWORDS and c != name]
        out.append((text.count("\n", 0, m.start()) + 1, name, calls))
    return out


def flags_of(name, calls, fileprefix):
    fl = []
    if OFFSET.search(name):
        fl.append("OFFSET")
    v = verb(name)
    cv = [verb(c) or "" for c in calls]
    if v in ("Get", "Is", "Check", "Has", "Can") and any(CHANGE.match(x) for x in cv):
        fl.append("VERB")
    elif v in ("Add", "Insert") and any(x in ("Remove", "Delete", "Sub") for x in cv) and not any(x in ("Add", "Insert") for x in cv):
        fl.append("VERB")
    elif v in ("Remove", "Delete", "Sub") and any(x in ("Add", "Insert") for x in cv) and not any(x in ("Remove", "Delete", "Sub") for x in cv):
        fl.append("VERB")
    elif v in ("Create", "Init", "Alloc") and cv and all(x in ("Delete", "Free", "Exit") for x in cv):
        fl.append("VERB")
    p = prefix(name)
    if fileprefix and p and p != fileprefix and not p.startswith(fileprefix + "_") and not fileprefix.startswith(p + "_"):
        fl.append("PREFIX")
    return fl


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("paths", nargs="*")
    ap.add_argument("--flags", default="OFFSET,VERB,PREFIX")
    ap.add_argument("--all", action="store_true", help="also print unflagged functions")
    a = ap.parse_args()
    want = set(a.flags.split(","))
    paths = a.paths or [ph.GAME]
    total = collections.Counter()
    for f in ph.files_under(paths):
        if not f.endswith(".c"):
            continue
        ds = defs(f)
        pc = collections.Counter(prefix(n) for _, n, _ in ds if prefix(n))
        fp = pc.most_common(1)[0][0] if pc else None
        rel = os.path.relpath(f, ROOT).replace(os.sep, "/")
        for line, name, calls in ds:
            fl = [x for x in flags_of(name, calls, fp) if x in want]
            for x in fl:
                total[x] += 1
            if fl or a.all:
                print("%s\t%d\t%s\t%s\t%s" % (rel, line, name, ",".join(fl), " ".join(calls[:12])))
    sys.stderr.write("flags: %s\n" % dict(total))


if __name__ == "__main__":
    main()
