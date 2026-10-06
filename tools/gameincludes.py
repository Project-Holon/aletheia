#!/usr/bin/env python3
"""gameincludes.py: point every #include of a src/game file at the real header.

Merged files and folder members include the shared struct headers of
src/matched/include/ and a few SDK libc headers of src/matched/arm9_sdk/libc/.
Lanes that worked from a scratchpad copy wrote long or wrong relative paths.
This rewrites each such include to the relative path from the file's own folder.

usage
  python tools/gameincludes.py [--tree src/game]
"""
import argparse
import os
import re

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
INC = re.compile(r'(#\s*include\s*")([^"]+)(")')


def target(path):
    """The repo file an include path names, or None."""
    p = path.replace(chr(92), '/')
    m = re.search(r'(?:^|/)include/(Obj\d+\.h|G_\w+\.h)$', p)
    if m:
        return os.path.join(ROOT, 'src', 'matched', 'include', m.group(1))
    m = re.search(r'(?:^|/)(libc/.+\.h)$', p)
    if m:
        cand = os.path.join(ROOT, 'src', 'matched', 'arm9_sdk', m.group(1))
        if os.path.exists(cand):
            return cand
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--tree', default=os.path.join(ROOT, 'src', 'game'))
    a = ap.parse_args()
    nfiles = nfix = 0
    for dp, _dn, fn in os.walk(a.tree):
        for f in fn:
            if not f.endswith(('.c', '.h')):
                continue
            p = os.path.join(dp, f)
            raw = open(p, encoding='latin1', newline='').read()

            def fix(m):
                t = target(m.group(2))
                if t is None:
                    return m.group(0)
                rel = os.path.relpath(t, dp).replace(os.sep, '/')
                return m.group(1) + rel + m.group(3)
            new = INC.sub(fix, raw)
            if new != raw:
                nfiles += 1
                nfix += sum(1 for x, y in zip(INC.findall(raw), INC.findall(new)) if x != y)
                with open(p, 'w', encoding='latin1', newline='') as fh:
                    fh.write(new)
    print('rewrote %d include(s) in %d file(s)' % (nfix, nfiles))


if __name__ == '__main__':
    main()
