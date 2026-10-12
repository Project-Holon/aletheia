#!/usr/bin/env python3
"""Count src/game translation units that are one file, per area.

usage: python tools/tucount.py [OUT.tsv]

A TU is split when it has `<tu>_pNN.c` parts, or a `<tu>/` folder holding
.c member files next to its file. OUT.tsv (default
docs/restructure/split_tus.tsv) gets one row per split TU: region, tu,
part count, folder member count. Files starting with `_` are scratch and
left out.
"""
import collections
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GAME = os.path.join(ROOT, 'src', 'game')
AREAS = ('ARM9', 'Overlays', 'twl', 'ITCM')


def area(region):
    if region == 'arm9':
        return 'ARM9'
    if region == 'twl':
        return 'twl'
    if 'ITCM' in region:
        return 'ITCM'
    return 'Overlays'


def count():
    tot, whole, rows = collections.Counter(), collections.Counter(), []
    for region in sorted(os.listdir(GAME)):
        d = os.path.join(GAME, region)
        if not os.path.isdir(d):
            continue
        parts, singles, members = collections.Counter(), set(), collections.Counter()
        for f in os.listdir(d):
            p = os.path.join(d, f)
            if f.endswith('.c') and not f.startswith('_'):
                m = re.match(r'(.+)_p\d+\.c$', f)
                if m:
                    parts[m.group(1)] += 1
                else:
                    singles.add(f[:-2])
            elif os.path.isdir(p):
                n = sum(1 for g in os.listdir(p) if g.endswith('.c'))
                if n:
                    members[f] = n
        for tu in set(parts) | singles | set(members):
            n = parts.get(tu, 0) + (1 if tu in singles else 0) + members.get(tu, 0)
            a = area(region)
            tot[a] += 1
            if n == 1:
                whole[a] += 1
            else:
                rows.append((region, tu, parts.get(tu, 0), members.get(tu, 0)))
    return tot, whole, sorted(rows)


def main():
    out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, 'docs', 'restructure', 'split_tus.tsv')
    tot, whole, rows = count()
    for a in AREAS:
        if tot[a]:
            print('%-9s %4d / %4d  %.1f%%' % (a, whole[a], tot[a], 100.0 * whole[a] / tot[a]))
    w, t = sum(whole.values()), sum(tot.values())
    print('Total     %4d / %4d  %.1f%%' % (w, t, 100.0 * w / t))
    with open(out, 'w', newline='\n') as f:
        for r in rows:
            f.write('%s\t%s\t%d\t%d\n' % r)
    print('split', len(rows))


if __name__ == '__main__':
    main()
