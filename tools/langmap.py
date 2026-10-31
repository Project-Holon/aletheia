#!/usr/bin/env python3
"""langmap.py: address maps from English Black to the other cartridges, for a port that runs
one build (English layout) on every European cartridge.

For each target, every global function and data object of every region is looked up by name in
the target's own passing data-mode link (build/gamelink_data/<region>_<target>/ov.elf) and in
Black's (build/gamelink_data/<region>/ov.elf).  Run it after `romlink.py --relink` of the targets.

Output (addresses, sizes and offsets only, no game bytes):
  layout/langmap/<target>.tsv           region, english_start, english_end, target_start: runs
                                        of consecutive objects that move by the same amount (an
                                        English address A in [english_start, english_end) is
                                        A - english_start + target_start in the target)
  layout/langmap/size_changed.tsv       the objects of every target whose size differs from
                                        English, with both addresses: a port takes those from
                                        the target's ROM instead of remapping the English ones
  layout/langmap/size_changed_ptrs.tsv  the pointer words of the size-changed data objects in
                                        the target: offset in the target object and the address
                                        the word holds in the target (from the link's
                                        relocations)
  layout/langmap/not_mapped.tsv         English data objects with no object of the same name in
                                        the target (data the target's link places by content,
                                        cut into other pieces, and secure-area pieces): a pointer
                                        into one of them has no run and needs the target's data
  build/langmap/<target>.tsv            the full table, one row per object: region, name, kind,
                                        english_addr, target_addr, english_size, target_size

usage: python tools/langmap.py [TARGET ...]     (default: white and the eight European targets)
"""
import os
import re
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import gamelink  # noqa: E402

DEFAULT = ['white', 'black_fr', 'white_fr', 'black_de', 'white_de', 'black_it', 'white_it',
           'black_es', 'white_es']
OUT = os.path.join(ROOT, 'layout', 'langmap')
FULL = os.path.join(ROOT, 'build', 'langmap')
R_ARM_ABS32 = 2


def read(path):
    """(elf bytes, sections, {name: (address, size, kind)}) of a link; None when missing."""
    if not os.path.exists(path):
        return None
    d, secs, ys = gamelink.read_elf(path)
    out = {}
    for y in ys:
        typ = y['info'] & 15
        if y['name'] and (y['info'] >> 4) == 1 and 0 < y['shndx'] < 0xFF00 and typ in (1, 2):
            out[y['name']] = (y['value'] & ~1, y['size'], 'func' if typ == 2 else 'data')
    return d, secs, out


def pointer_words(d, secs, lo, hi):
    """[(address, value, how)] of the pointer words in [lo, hi) of a linked image: its absolute
    32-bit relocations ('reloc').  An object the link took as one block of the target's own bytes
    has no relocations; then every aligned word whose value is a main-memory address is listed
    ('scan')."""
    out = [(a, v, 'reloc') for a, v in relocated_words(d, secs, lo, hi)]
    if out:
        return out
    for s in secs:
        if s['type'] == 1 and s['addr'] <= lo and hi <= s['addr'] + s['size']:
            for a in range((lo + 3) & ~3, hi - 3, 4):
                v, = struct.unpack_from('<I', d, s['off'] + a - s['addr'])
                if 0x02000000 <= v < 0x02400000:
                    out.append((a, v, 'scan'))
            break
    return out


def relocated_words(d, secs, lo, hi):
    """[(address, value)] of the absolute 32-bit relocations in [lo, hi) of a linked image."""
    out = []
    for r in secs:
        if r['type'] != 4 or not r['ent']:
            continue
        tgt = secs[r['info']]
        if not (tgt['addr'] <= lo < tgt['addr'] + tgt['size']):
            continue
        for k in range(r['size'] // r['ent']):
            off, info, _add = struct.unpack_from('<III', d, r['off'] + k * r['ent'])
            if info & 255 == R_ARM_ABS32 and lo <= off < hi:
                v, = struct.unpack_from('<I', d, tgt['off'] + off - tgt['addr'])
                out.append((off, v))
    return sorted(out)


def regions():
    base = os.path.join(ROOT, 'build', 'gamelink_data')
    return sorted(g for g in os.listdir(base) if re.match(r'^(arm9_main|ov\d{3})$', g)
                  and os.path.exists(os.path.join(base, g, 'ov.elf')))


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


def write(path, rows):
    with open(path, 'w', encoding='utf-8', newline='\n') as fh:
        fh.write('\n'.join(rows) + '\n')


def main(argv):
    targets = argv or DEFAULT
    os.makedirs(OUT, exist_ok=True)
    os.makedirs(FULL, exist_ok=True)
    regs = regions()
    black = {g: read(os.path.join(ROOT, 'build', 'gamelink_data', g, 'ov.elf'))[2] for g in regs}
    changed = ['target\tregion\tname\tkind\tenglish_addr\ttarget_addr\tenglish_size\ttarget_size']
    ptrs = ['target\tregion\tname\toffset\ttarget_value\thow']
    notmapped = ['target\tregion\tname\tenglish_addr\tenglish_size']
    for t in targets:
        rows = ['region\tname\tkind\tenglish_addr\ttarget_addr\tenglish_size\ttarget_size']
        runs = ['region\tenglish_start\tenglish_end\ttarget_start']
        missing = []
        for g in regs:
            got = read(os.path.join(ROOT, 'build', 'gamelink_data', '%s_%s' % (g, t), 'ov.elf'))
            if got is None:
                missing.append(g)
                continue
            d, secs, ts = got
            objs = []
            for name, (ba, bsz, kind) in sorted(black[g].items(), key=lambda kv: kv[1][0]):
                if name not in ts:
                    if kind == 'data' and bsz:
                        notmapped.append('%s\t%s\t%s\t0x%08X\t%d' % (t, g, name, ba, bsz))
                    continue
                ta, tsz, _k = ts[name]
                rows.append('%s\t%s\t%s\t0x%08X\t0x%08X\t%d\t%d' % (g, name, kind, ba, ta, bsz, tsz))
                if bsz != tsz:
                    changed.append('%s\t%s\t%s\t%s\t0x%08X\t0x%08X\t%d\t%d' % (t, g, name, kind, ba, ta, bsz, tsz))
                    if kind == 'data':
                        for a, v, how in pointer_words(d, secs, ta, ta + tsz):
                            ptrs.append('%s\t%s\t%s\t0x%X\t0x%08X\t%s' % (t, g, name, a - ta, v, how))
                # the link's own stand-in sections (0x0E000000 up) are not memory
                if bsz and '__v' not in name and ba < 0x02800000:
                    objs.append((ba, ta, bsz))
            for ea, ee, ta in runs_of(objs):
                runs.append('%s\t0x%08X\t0x%08X\t0x%08X' % (g, ea, ee, ta))
        write(os.path.join(FULL, t + '.tsv'), rows)
        write(os.path.join(OUT, t + '.tsv'), runs)
        print('%s: %d objects, %d runs%s' % (t, len(rows) - 1, len(runs) - 1,
                                            ('; no link for ' + ', '.join(missing)) if missing else ''))
    write(os.path.join(OUT, 'size_changed.tsv'), changed)
    write(os.path.join(OUT, 'size_changed_ptrs.tsv'), ptrs)
    write(os.path.join(OUT, 'not_mapped.tsv'), notmapped)
    print('size_changed.tsv: %d rows, size_changed_ptrs.tsv: %d rows, not_mapped.tsv: %d rows'
          % (len(changed) - 1, len(ptrs) - 1, len(notmapped) - 1))


if __name__ == '__main__':
    main(sys.argv[1:])
