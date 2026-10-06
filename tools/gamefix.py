#!/usr/bin/env python3
"""gamefix.py: repair what tools/gamecheck.py reports in the restructured tree.

1. A function defined twice: when one copy is a member file in a TU folder and
   every function that member file defines is also defined elsewhere in the
   region, the member file is a stray copy and is deleted.
2. A verified function defined nowhere: its src/matched file is copied into the
   folder of the TU whose address range holds it (tools/tuboundary.py proposal),
   with the include path rewritten, and the folder's MERGE.md gets a line.

usage
  python tools/gamefix.py --proposal TSV [--tree src/game] [--region R] [--dry-run]
"""
import argparse
import collections
import csv
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import gamecheck as gc  # noqa: E402
import protofix as pf  # noqa: E402
import restructure as rs  # noqa: E402


def defs_of(path):
    raw = open(path, encoding='latin1').read()
    m = pf.mask(raw)
    tab = pf.depth_table(m)
    out = set()
    for mm in pf.DECL_RE.finditer(m):
        if mm.group(5) == '{' and pf.depth_at(tab, mm.start()) == 0:
            am = gc.ADDR.search(mm.group(3))
            out.add(int(am.group(1), 16) if am else mm.group(3))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--proposal', required=True)
    ap.add_argument('--tree', default=os.path.join(ROOT, 'src', 'game'))
    ap.add_argument('--region', action='append')
    ap.add_argument('--dry-run', action='store_true')
    a = ap.parse_args()
    idx = rs.shard_index()
    with open(a.proposal, newline='', encoding='utf-8') as f:
        prop = list(csv.DictReader(f, delimiter='\t'))
    regions = a.region or sorted(d for d in os.listdir(a.tree) if os.path.isdir(os.path.join(a.tree, d)))
    stats = collections.Counter()
    for region in regions:
        have, blob = gc.defined_in_tree(a.tree, region)
        # 1. stray member copies
        for p in list(gc.tree_files(a.tree, region)):
            if os.path.dirname(os.path.normpath(p)) == os.path.normpath(os.path.join(a.tree, region)):
                continue                        # merged files stay
            mine = defs_of(p)
            rel = os.path.relpath(p, ROOT).replace(os.sep, '/')
            if mine and all(len([f for f in have.get(x, []) if f != rel]) >= 1 for x in mine):
                stats['stray member removed'] += 1
                if not a.dry_run:
                    rs.safe_remove(p)
                for x in mine:
                    have[x] = [f for f in have.get(x, []) if f != rel]
        # 1b. a small merged file whose functions all live in a bigger merged file
        #     (a lane merged a neighbouring one-function TU into its own file)
        tops = [p for p in gc.tree_files(a.tree, region)
                if os.path.dirname(os.path.normpath(p)) == os.path.normpath(os.path.join(a.tree, region))]
        sizes = {os.path.relpath(p, ROOT).replace(os.sep, '/'): defs_of(p) for p in tops}
        for p in sorted(tops, key=lambda q: len(sizes[os.path.relpath(q, ROOT).replace(os.sep, '/')])):
            rel = os.path.relpath(p, ROOT).replace(os.sep, '/')
            mine = sizes.get(rel)
            if not mine:
                continue
            others = [r for r in sizes if r != rel and sizes[r] and len(sizes[r]) > len(mine)]
            if all(any(x in sizes[o] for o in others) for x in mine):
                stats['smaller duplicate file removed'] += 1
                if not a.dry_run:
                    rs.safe_remove(p)
                    folder = p[:-2]
                    if os.path.isdir(folder) and not any(f.endswith('.c') for f in os.listdir(folder)):
                        import shutil
                        shutil.rmtree(folder, ignore_errors=True)
                del sizes[rel]
                for x in mine:
                    have[x] = [f for f in have.get(x, []) if f != rel]
        # 2. missing functions
        want = sorted(x for (r, x) in idx if r == region)
        rows = [r for r in prop if r['region'] == region]
        for x in want:
            src, e = idx[(region, x)]
            nm = e.get('name')
            if x in have and have[x] or (nm in have and have[nm]):
                continue
            if re.search(r'^[^;\n]*\b%s\s*\([^;]*$' % re.escape(nm or 'func_%08X' % x), blob, re.M):
                continue
            tu = next((r for r in rows if int(r['start'], 16) <= x < int(r['end'], 16)), None)
            name = (tu['name'] if tu else 'unplaced')
            name = name[:-2] if name.endswith('.c') else name
            d = os.path.join(a.tree, region, name)
            stats['missing placed'] += 1
            if a.dry_run:
                continue
            os.makedirs(d, exist_ok=True)
            dst = os.path.join(d, os.path.basename(src))
            if not os.path.exists(dst):
                t = open(os.path.join(ROOT, src), 'rb').read()
                inc = os.path.relpath(rs.INCLUDE_DIR, d).replace(os.sep, '/') + '/'
                t = t.replace(b'"../include/', b'"' + inc.encode())
                open(dst, 'wb').write(t)
                with open(os.path.join(d, 'MERGE.md'), 'a', encoding='utf-8', newline='\n') as fh:
                    fh.write('\n- `%s` was missing from the restructured tree and was added back from '
                             'src/matched (tools/gamefix.py); merge it into its neighbours.\n'
                             % os.path.basename(src))
            for y in defs_of(dst):
                have[y] = have.get(y, []) + [dst]
    print(dict(stats))


if __name__ == '__main__':
    main()
