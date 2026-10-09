#!/usr/bin/env python3
"""gamepromote.py: tidy src/game TUs that are already one piece.

Three cases:
  loose1   a TU folder that holds exactly one member file and no parts. The member
           is verified as a translation unit; on EXACT it becomes
           src/game/<region>/<tu>.c (header gets a `file:` line) and the folder goes.
  p01only  the TU is a single <tu>_p01.c with no other parts and no members: it is
           renamed <tu>.c (header `file:` line updated) and the folder, if any, goes.
  empty    a TU folder that holds no .c files while <tu>.c exists: the folder goes.

Nothing is written without --apply.

usage
  python tools/gamepromote.py [--tree src/game] [--region R] [--apply]
"""
import argparse
import os
import re
import shutil
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import gameverify as gv  # noqa: E402
import restructure as rs  # noqa: E402


def set_file_line(raw, name):
    if re.search(r'^ \* file:\s.*$', raw, re.M):
        return re.sub(r'^ \* file:\s.*$', ' * file:     %s' % name, raw, count=1, flags=re.M)
    return raw.replace('/*\n', '/*\n * file:     %s\n' % name, 1) if raw.startswith('/*\n') else raw


def verify(path, region):
    raw = open(path, encoding='latin1').read()
    if raw.startswith('\xef\xbb\xbf'):
        raw = raw[3:]
    h, st = gv.settings_of(raw)
    try:
        addr = int(h.get('address', '0').split(',')[0], 16)
    except ValueError:
        return False, 'no address'
    reg = (h.get('region') or region).strip()
    v = rs.verify(path, reg, addr, st)
    return rs.lang_ok(v, st), ' '.join('%s=%s' % kv for kv in v.items())[:160]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--tree', default=os.path.join(ROOT, 'src', 'game'))
    ap.add_argument('--region', action='append')
    ap.add_argument('--apply', action='store_true')
    a = ap.parse_args()
    regions = a.region or sorted(d for d in os.listdir(a.tree) if os.path.isdir(os.path.join(a.tree, d)))
    n = {'loose1': 0, 'loose1_fail': 0, 'p01only': 0, 'empty': 0}
    for region in regions:
        base = os.path.join(a.tree, region)
        ents = os.listdir(base)
        parts = {}
        singles = set()
        for e in ents:
            if e.startswith('_') or not e.endswith('.c'):
                continue
            m = re.match(r'(.+)_p(\d+)\.c$', e)
            if m:
                parts.setdefault(m.group(1), []).append(e)
            else:
                singles.add(e[:-2])
        dirs = [e for e in ents if os.path.isdir(os.path.join(base, e)) and e != 'unplaced']
        for d in sorted(dirs):
            dp = os.path.join(base, d)
            cs = [f for f in os.listdir(dp) if f.endswith('.c') and not f.startswith('_')]
            if d in parts:
                continue
            if not cs:
                if d in singles:
                    n['empty'] += 1
                    print('empty     %s/%s' % (region, d))
                    if a.apply:
                        shutil.rmtree(dp)
                continue
            if len(cs) == 1 and d not in singles:
                src = os.path.join(dp, cs[0])
                ok, why = verify(src, region)
                if not ok:
                    n['loose1_fail'] += 1
                    print('FAIL      %s/%s/%s  %s' % (region, d, cs[0], why))
                    continue
                n['loose1'] += 1
                print('loose1    %s/%s/%s -> %s.c' % (region, d, cs[0], d))
                if a.apply:
                    raw = open(src, encoding='latin1').read()
                    dst = os.path.join(base, d + '.c')
                    with open(dst, 'w', encoding='latin1', newline='') as f:
                        f.write(set_file_line(raw, d + '.c'))
                    ok2, why2 = verify(dst, region)
                    if not ok2:
                        os.remove(dst)
                        print('  REVERTED after move: %s' % why2)
                        n['loose1'] -= 1
                        n['loose1_fail'] += 1
                        continue
                    shutil.rmtree(dp)
        for tu, ps in sorted(parts.items()):
            if len(ps) != 1 or tu in singles:
                continue
            dp = os.path.join(base, tu)
            if os.path.isdir(dp) and any(f.endswith('.c') for f in os.listdir(dp)):
                continue
            n['p01only'] += 1
            print('p01only   %s/%s -> %s.c' % (region, ps[0], tu))
            if a.apply:
                src = os.path.join(base, ps[0])
                raw = open(src, encoding='latin1').read()
                with open(os.path.join(base, tu + '.c'), 'w', encoding='latin1', newline='') as f:
                    f.write(set_file_line(raw, tu + '.c'))
                os.remove(src)
                if os.path.isdir(dp):
                    shutil.rmtree(dp)
    print(n)


if __name__ == '__main__':
    main()
