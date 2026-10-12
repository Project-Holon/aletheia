#!/usr/bin/env python3
"""gameverify.py: compile every merged file of src/game/ and compare it with the
original bytes.

Each merged file (src/game/<region>/<tu>.c or <tu>_pNN.c) carries a header with
its first function address, region, isa, compiler, flags and lang.  It is compiled
once as a translation unit and its .text compared with the image from that
address (match.py run_tu, the `tu` command), in its own -lang mode.  Member files
inside TU folders are copies of verified src/matched files and are compiled the
same way when --members is given.

usage
  python tools/gameverify.py [--tree src/game] [--region R] [--members] [--report TSV]
"""
import argparse
import csv
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import protofix as pf  # noqa: E402
import restructure as rs  # noqa: E402
import gamesyms as gs  # noqa: E402


def settings_of(raw):
    h = pf.parse_header(raw)
    cc = (h.get('compiler') or '1.1p1').strip()
    cc = cc[4:] if cc.startswith('dsi/') else cc
    fl = re.sub(r'-proc\s+arm946e', '', h.get('flags') or '').strip() or '-O4,p'
    return h, {'compiler': cc, 'flags': fl, 'lang': (h.get('lang') or '').strip(),
               'isa': ((h.get('isa') or 'thumb').split() or ['thumb'])[0]}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--tree', default=os.path.join(ROOT, 'src', 'game'))
    ap.add_argument('--region', action='append')
    ap.add_argument('--members', action='store_true')
    ap.add_argument('--report')
    ap.add_argument('--file', action='append', help='verify only these files (any region)')
    a = ap.parse_args()
    regions = a.region or sorted(d for d in os.listdir(a.tree) if os.path.isdir(os.path.join(a.tree, d)))
    if a.file:
        regions = [None]
    rows, bad, nmatch = [], 0, 0
    for region in regions:
        files = []
        if region is None:
            files = [os.path.abspath(f) for f in a.file]
            region = ''
        else:
            base = os.path.join(a.tree, region)
            for dp, _dn, fn in os.walk(base):
                top = os.path.normpath(dp) == os.path.normpath(base)
                if not top and not a.members:
                    continue
                files += [os.path.join(dp, f) for f in fn if f.endswith('.c') and not f.startswith('_')]
        for p in sorted(files):
            try:
                raw = open(p, encoding='latin1').read()
            except OSError:
                continue                        # removed while the check ran (a lane merged it)
            if raw.startswith('\xef\xbb\xbf'):
                raw = raw[3:]
            h, st = settings_of(raw)
            try:
                addr = int(h.get('address', '0'), 16)
            except ValueError:
                addr = 0
            reg = (h.get('region') or region).strip()
            badsym = gs.lint(raw.replace('\r\n', '\n'))
            if badsym:
                v = {'header': 'bad symbols row: %s' % badsym[0][0].strip()}
            elif not addr:
                v = {'header': 'no address'}
            else:
                v = rs.verify(p, reg, addr, st)
            ok = rs.lang_ok(v, st) if (addr and not badsym) else False
            bad += 0 if ok else 1
            rel = os.path.relpath(p, ROOT).replace(os.sep, '/')
            nmatch += 1 if ok and (v.get(st['lang'] or 'nolang', '').startswith('MATCH')) else 0
            rows.append({'file': rel, 'ok': 'yes' if ok else 'NO',
                         'verdict': ' '.join('%s=%s' % kv for kv in v.items())[:300]})
            if not ok:
                print('NOT EXACT  %s  %s' % (rel, rows[-1]['verdict'][:160]), flush=True)
    print('files: %d, not exact: %d, MATCH (relocations wildcarded): %d' % (len(rows), bad, nmatch))
    if a.report:
        with open(a.report, 'w', newline='', encoding='utf-8') as f:
            w = csv.DictWriter(f, ['file', 'ok', 'verdict'], delimiter='\t')
            w.writeheader()
            w.writerows(rows)
    sys.exit(1 if bad else 0)


if __name__ == '__main__':
    main()
