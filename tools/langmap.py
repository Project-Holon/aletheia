#!/usr/bin/env python3
"""langmap.py: address maps from English Black to the other cartridges, for a port that runs
one build (English layout) on every European cartridge.

For each target, every global function and data object of every region is looked up by name in
the target's own passing data-mode link (build/gamelink_data/<region>_<target>/ov.elf) and in
Black's (build/gamelink_data/<region>/ov.elf).  Run it after `romlink.py --relink` of the targets.

Output (addresses and sizes only, no game bytes):
  layout/langmap/<target>.tsv     region, english_start, english_end, target_start: runs of
                                  consecutive objects that move by the same amount (an English
                                  address A in [english_start, english_end) is
                                  A - english_start + target_start in the target)
  layout/langmap/size_changed.tsv the objects of every target whose size differs from English:
                                  a port takes those from the target's ROM instead of remapping
                                  the English ones
  build/langmap/<target>.tsv      the full table, one row per object: region, name, kind,
                                  english_addr, target_addr, english_size, target_size

usage: python tools/langmap.py [TARGET ...]     (default: white and the eight European targets)
"""
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import gamelink  # noqa: E402

DEFAULT = ['white', 'black_fr', 'white_fr', 'black_de', 'white_de', 'black_it', 'white_it',
           'black_es', 'white_es']
OUT = os.path.join(ROOT, 'layout', 'langmap')
FULL = os.path.join(ROOT, 'build', 'langmap')


def syms(path):
    """{name: (address, size, kind)} of the global functions and objects of a link."""
    if not os.path.exists(path):
        return None
    _d, _secs, ys = gamelink.read_elf(path)
    out = {}
    for y in ys:
        typ = y['info'] & 15
        if y['name'] and (y['info'] >> 4) == 1 and 0 < y['shndx'] < 0xFF00 and typ in (1, 2):
            out[y['name']] = (y['value'] & ~1, y['size'], 'func' if typ == 2 else 'data')
    return out


def regions():
    base = os.path.join(ROOT, 'build', 'gamelink_data')
    return sorted(d for d in os.listdir(base) if re.match(r'^(arm9_main|ov\d{3})$', d)
                  and os.path.exists(os.path.join(base, d, 'ov.elf')))


def runs_of(objs):
    """Runs of consecutive objects (sorted by English address) with one shift."""
    out = []
    cur = None
    for ea, ta, es in sorted(objs):
        if cur and ta - ea == cur[2] - cur[0] and ea >= cur[1]:
            cur[1] = max(cur[1], ea + es)
            continue
        if cur:
            out.append(cur)
        cur = [ea, ea + es, ta]
    if cur:
        out.append(cur)
    return out


def main(argv):
    targets = argv or DEFAULT
    os.makedirs(OUT, exist_ok=True)
    os.makedirs(FULL, exist_ok=True)
    regs = regions()
    black = {r: syms(os.path.join(ROOT, 'build', 'gamelink_data', r, 'ov.elf')) for r in regs}
    changed = ['target\tregion\tname\tkind\tenglish_size\ttarget_size']
    for t in targets:
        rows = ['region\tname\tkind\tenglish_addr\ttarget_addr\tenglish_size\ttarget_size']
        runs = ['region\tenglish_start\tenglish_end\ttarget_start']
        missing = []
        for r in regs:
            ts = syms(os.path.join(ROOT, 'build', 'gamelink_data', '%s_%s' % (r, t), 'ov.elf'))
            if ts is None:
                missing.append(r)
                continue
            objs = []
            for name, (ba, bsz, kind) in sorted(black[r].items(), key=lambda kv: kv[1][0]):
                if name not in ts:
                    continue
                ta, tsz, _k = ts[name]
                rows.append('%s\t%s\t%s\t0x%08X\t0x%08X\t%d\t%d' % (r, name, kind, ba, ta, bsz, tsz))
                if bsz != tsz:
                    changed.append('%s\t%s\t%s\t%s\t%d\t%d' % (t, r, name, kind, bsz, tsz))
                if bsz and '__v' not in name:
                    objs.append((ba, ta, bsz))
            for ea, ee, ta in runs_of(objs):
                runs.append('%s\t0x%08X\t0x%08X\t0x%08X' % (r, ea, ee, ta))
        with open(os.path.join(FULL, t + '.tsv'), 'w', encoding='utf-8', newline='\n') as fh:
            fh.write('\n'.join(rows) + '\n')
        with open(os.path.join(OUT, t + '.tsv'), 'w', encoding='utf-8', newline='\n') as fh:
            fh.write('\n'.join(runs) + '\n')
        print('%s: %d objects, %d runs%s' % (t, len(rows) - 1, len(runs) - 1,
                                            ('; no link for ' + ', '.join(missing)) if missing else ''))
    with open(os.path.join(OUT, 'size_changed.tsv'), 'w', encoding='utf-8', newline='\n') as fh:
        fh.write('\n'.join(changed) + '\n')
    print('size_changed.tsv: %d rows' % (len(changed) - 1))


if __name__ == '__main__':
    main(sys.argv[1:])
