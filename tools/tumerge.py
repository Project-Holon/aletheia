#!/usr/bin/env python3
"""Merge the parts of a split src/game TU, greedily, keeping every result EXACT.

usage: python tools/tumerge.py REGION TU [--apply] [--pair I J]

Parts are src/game/REGION/TU_pNN.c in address order. A part whose functions
are all linker veneers in the image is dropped (linker output; match.py takes
veneer bytes from the image). Then, from the first part, the longest run of
neighbours that merges (restructure.merge) and verifies with the same
verdict per lang as the members (EXACT stays EXACT) becomes one group.
Without --apply it only reports the groups. With --apply the groups are
written: one group gives TU.c (parts and the TU/ folder with MERGE.md are
removed), several give TU_p01.c.. renumbered without gaps.
--pair I J tries only parts I..J (1-based, inclusive) and reports the verdict.
"""
import argparse
import glob
import os
import re
import shutil
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, 'tools'))
import match as m           # noqa: E402
import restructure as rs    # noqa: E402
import gameverify as gv     # noqa: E402


def header(path):
    raw = open(path, encoding='latin1').read()
    h, st = gv.settings_of(raw)
    fl = re.search(r'function:\s*(.*)', raw.split('*/', 1)[0])
    names = re.findall(r'[A-Za-z_]\w*', fl.group(1)) if fl else []
    return names, int(h.get('address', '0'), 16), st


def veneer_part(path, region):
    names, addr, _st = header(path)
    adds = [int(n[5:], 16) for n in names if re.fullmatch(r'func_[0-9A-Fa-f]{8}', n)]
    if not adds or len(adds) != len(names):
        return False
    r = m.find_region(addr, region)
    return all(m._veneer_size(r.data, a - r.base) for a in adds)


def ok(verdict, settings):
    return rs.lang_ok(verdict, settings) and all(
        not v.startswith(('DIFF', 'SIZE', 'CCERR', 'ERROR')) for v in verdict.values())


def try_group(region, tu, members):
    funcs, start, st = [], None, None
    for p in members:
        n, a, s = header(p)
        funcs += n
        start = a if start is None else min(start, a)
        st = st or s
    rel = [os.path.relpath(p, ROOT).replace(os.sep, '/') for p in members]
    out = os.path.join(ROOT, 'src', 'game', region)
    text, problems, settings, _ren = rs.merge(rel, tu + '.c', region, start, funcs, out)
    if any(p.startswith('settings differ') for p in problems):
        return None, problems
    tmp = os.path.join(out, '_tumerge_%s_%d.c' % (tu, os.getpid()))
    with open(tmp, 'w', encoding='latin1', newline='\n') as f:
        f.write(text)
    try:
        v = rs.verify(tmp, region, start, settings)
    finally:
        os.remove(tmp)
    return (text if ok(v, settings) else None), v


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('region')
    ap.add_argument('tu')
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('--pair', nargs=2, type=int)
    a = ap.parse_args()
    d = os.path.join(ROOT, 'src', 'game', a.region)
    parts = sorted(glob.glob(os.path.join(d, a.tu + '_p[0-9][0-9].c')))
    if not parts:
        sys.exit('no parts for %s/%s' % (a.region, a.tu))
    keep = [p for p in parts if not veneer_part(p, a.region)]
    if len(keep) != len(parts):
        print('dropped %d veneer-only part(s)' % (len(parts) - len(keep)))
    if a.pair:
        i, j = a.pair
        text, v = try_group(a.region, a.tu, parts[i - 1:j])
        print('parts %d..%d: %s %s' % (i, j, 'ok' if text else 'FAIL', v))
        return 0
    groups, i = [], 0
    while i < len(keep):
        best, bj = None, i + 1
        for j in range(len(keep), i + 1, -1):
            text, v = try_group(a.region, a.tu, keep[i:j])
            if text:
                best, bj = text, j
                break
        groups.append((keep[i:bj], best))
        print('group %s: %s' % ([os.path.basename(p) for p in keep[i:bj]],
                                'merged' if best else 'single'))
        i = bj
    print('%d part(s) -> %d' % (len(parts), len(groups)))
    if not a.apply:
        return 0
    texts = []
    for members, text in groups:
        texts.append(text if text else open(members[0], encoding='latin1').read())
    for p in parts:
        os.remove(p)
    if len(texts) == 1:
        with open(os.path.join(d, a.tu + '.c'), 'w', encoding='latin1', newline='\n') as f:
            f.write(texts[0])
        folder = os.path.join(d, a.tu)
        if os.path.isdir(folder):
            shutil.rmtree(folder)
    else:
        for k, t in enumerate(texts, 1):
            name = '%s_p%02d.c' % (a.tu, k)
            t = re.sub(r'(file:\s*)\S+', lambda mm: mm.group(1) + name, t, count=1)
            with open(os.path.join(d, name), 'w', encoding='latin1', newline='\n') as f:
                f.write(t)
    print('written')
    return 0


if __name__ == '__main__':
    sys.exit(main())
