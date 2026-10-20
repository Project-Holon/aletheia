#!/usr/bin/env python3
"""twlnames.py: give the twl data objects their registry names in src/game/twl.

layout/data_objects.json (key twl_data, written by tools/datareg.py, defined by tools/twldata.py)
names every data object that no src/game/twl file writes: DSPi_StaticComponentG711,
MIi_GetWramBankMasterFuncs, DSPi_SoundPriority, ... The sources still use the placeholder names
(data_02707CB4) or raw addresses ((char *)0x02732D54).  For every file of src/game/twl this tool

  1. renames each `symbols:` header entry and identifier whose address is an object of the registry
     (data_02732D78 -> DSPi_SoundPriority);
  2. replaces a cast of an object's raw address, `(char *)0x02732D54` or `(void *)0x02732D74`, by the
     object's name, adds `extern char NAME[];` after the first #include and the entry to the header
     `symbols:` block.

The link keeps its bytes: the companion of tools/twldata.py defines the name at the same address.

    python tools/twlnames.py                # dry run: list the edits
    python tools/twlnames.py --apply        # write the files
    python tools/twlnames.py --apply --file dsp_util.c ...

Verify afterwards: `python tools/gameverify.py --file src/game/twl/<file>`, `python tools/twllink.py`
and `python tools/twllink.py --version=white`.  A file another lane holds must be left to that lane.
"""
from __future__ import annotations

import argparse
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

import datareg    # noqa: E402

TWL = os.path.join(ROOT, "src", "game", "twl")
SYM = re.compile(r"^( \*\s+)(\S+)(\s+0x([0-9A-Fa-f]{8})\s+data\b.*)$")
CAST = re.compile(r"\(\s*(?:char|void|u8)\s*\*\s*\)\s*0x([0-9A-Fa-f]{8})\b")


def registry():
    with open(datareg.REG_PATH, encoding="utf-8") as fh:
        objs = json.load(fh)["regions"][datareg.REG_KEY["twl"]]["objects"]
    return {int(o["addr"], 16): o["name"] for o in objs}


def edit(text, names):
    """-> (new text, [description of each edit])"""
    log = []
    lines = text.split("\n")
    ren = {}
    last_sym = None
    for i, ln in enumerate(lines):
        m = SYM.match(ln)
        if m:
            last_sym = i
            a = int(m.group(4), 16)
            if a in names and m.group(2) != names[a]:
                ren[m.group(2)] = names[a]
                lines[i] = m.group(1) + names[a] + m.group(3)
    body = "\n".join(lines)
    for old, new in sorted(ren.items()):
        body, n = re.subn(r"\b%s\b" % re.escape(old), new, body)
        log.append("rename %s -> %s (%d)" % (old, new, n))
    added = {}

    def cast(m):
        a = int(m.group(1), 16)
        if a in names:
            added[a] = names[a]
            return names[a]
        return m.group(0)
    body = CAST.sub(cast, body)
    if added:
        lines = body.split("\n")
        have = {SYM.match(ln).group(2) for ln in lines if SYM.match(ln)}
        # header symbols
        close = max(i for i, ln in enumerate(lines) if SYM.match(ln)) + 1 if last_sym is not None else None
        if close is None:
            close = next(i for i, ln in enumerate(lines) if ln.startswith(" * symbols:")) + 1
        new_syms = [" *   %s  0x%08X  data twl" % (n, a) for a, n in sorted(added.items()) if n not in have]
        lines[close:close] = new_syms
        inc = next(i for i, ln in enumerate(lines) if ln.startswith("#include"))
        decl = ["extern char %s[];" % n for _a, n in sorted(added.items())]
        lines[inc + 1:inc + 1] = decl
        body = "\n".join(lines)
        log.append("raw address -> name: %s" % ", ".join(n for _a, n in sorted(added.items())))
    return body, log


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--file", nargs="*", help="file names in src/game/twl (default: all)")
    a = ap.parse_args(argv)
    names = registry()
    changed = 0
    for f in sorted(a.file or [x for x in os.listdir(TWL) if x.endswith(".c")]):
        path = os.path.join(TWL, f)
        with open(path, encoding="utf-8", newline="") as fh:
            text = fh.read()
        new, log = edit(text, names)
        if new == text:
            continue
        changed += 1
        print("%s: %s" % (f, "; ".join(log)))
        if a.apply:
            with open(path, "w", encoding="utf-8", newline="") as fh:
                fh.write(new)
    print("%d file%s %s" % (changed, "" if changed == 1 else "s", "written" if a.apply else "to change (dry run)"))
    return 0


if __name__ == "__main__":
    sys.exit(main())
