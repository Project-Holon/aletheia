#!/usr/bin/env python3
"""gamecheck.py: is every verified function in the restructured tree exactly once?

src/game/<region>/ is built from src/matched/ by tools/restructure.py and then
edited by merge lanes.  This check makes sure nothing was lost or doubled on
the way: every function that has an EXACT/EXACT* verification entry (its own, or
as a member of a verified unit) must be defined exactly once among the .c files
of src/game/<region>/ (merged files and the member files in TU folders).

A function is recognised by the address in its name (func_/sub_XXXXXXXX), or by
its name in the verification entry (vendor names such as _start).

usage
  python tools/gamecheck.py [--tree src/game] [--region ovNNN] [--list N]
"""
import argparse
import collections
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import protofix as pf  # noqa: E402
import restructure as rs  # noqa: E402

ADDR = re.compile(r'([0-9A-Fa-f]{8})$')


def tree_files(tree, region):
    """Paths of the .c files under tree/region (scratch files starting with _ left out)."""
    for dp, _dn, fn in os.walk(os.path.join(tree, region)):
        for f in fn:
            if f.endswith('.c') and not f.startswith('_'):
                yield os.path.join(dp, f)


def defined_in_tree(tree, region):
    """({address or name: [files]}, all text) of the top-level definitions."""
    out = collections.defaultdict(list)
    texts = []
    for p in tree_files(tree, region):
        try:
            raw = open(p, encoding='latin1').read()
        except OSError:
            continue
        texts.append(raw)
        m = pf.mask(raw)
        tab = pf.depth_table(m)
        rel = os.path.relpath(p, ROOT).replace(os.sep, '/')
        for mm in pf.DECL_RE.finditer(m):
            if mm.group(5) != '{' or pf.depth_at(tab, mm.start()) != 0:
                continue
            am = ADDR.search(mm.group(3))
            out[int(am.group(1), 16) if am else mm.group(3)].append(rel)
    return out, '\n'.join(texts)


def is_veneer(region, x):
    """True if the image holds a linker veneer (match.linker_gap) at x."""
    import match
    try:
        r = match.find_region(x, region)
    except SystemExit:
        return False
    i = x - r.base
    return 0 <= i < len(r.data) and bool(match._veneer_size(r.data, i))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--tree', default=os.path.join(ROOT, 'src', 'game'))
    ap.add_argument('--region', action='append')
    ap.add_argument('--list', type=int, default=10)
    a = ap.parse_args()
    idx = rs.shard_index()
    regions = a.region or sorted(d for d in os.listdir(a.tree) if os.path.isdir(os.path.join(a.tree, d)))
    tot_missing = tot_dup = tot_ok = 0
    for region in regions:
        # Linker veneers are linker output, not source: a src/matched entry
        # for one is not a function the restructured tree has to define.
        want = {x for (r, x) in idx if r == region and not is_veneer(region, x)}
        have, blob = defined_in_tree(a.tree, region)

        def present(x):
            nm = idx[(region, x)][1].get('name')
            if x in have or nm in have:
                return True
            # asm functions and other forms the declaration pattern misses
            nm = nm or 'func_%08X' % x
            return re.search(r'^[^;\n]*\b%s\s*\([^;]*$' % re.escape(nm), blob, re.M) is not None

        missing = sorted(x for x in want if not present(x))
        dup = sorted(x for x, fs in have.items() if isinstance(x, int) and len(fs) > 1 and x in want)
        tot_missing += len(missing)
        tot_dup += len(dup)
        tot_ok += len(want) - len(missing)
        if missing or dup:
            print('%-20s verified %5d  missing %4d  doubled %4d' % (region, len(want), len(missing), len(dup)))
            for x in missing[:a.list]:
                print('    missing %08X  (%s)' % (x, idx[(region, x)][0]))
            for x in dup[:a.list]:
                print('    doubled %08X  %s' % (x, ', '.join(have[x])))
    print('functions present: %d, missing: %d, doubled: %d' % (tot_ok, tot_missing, tot_dup))
    sys.exit(1 if tot_missing or tot_dup else 0)


if __name__ == '__main__':
    main()
