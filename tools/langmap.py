#!/usr/bin/env python3
"""langmap.py: address maps from English Black to the other cartridges, for a port that runs
one build (English layout) on every European cartridge.

For each target, every global function and data object of every region is looked up by name in
the target's own passing data-mode link (build/gamelink_data/<region>_<target>/ov.elf) and in
Black's (build/gamelink_data/<region>/ov.elf).  Run it after `romlink.py --relink` of the targets.

Output (addresses, sizes and offsets only, no game bytes):
  layout/langmap/<target>.tsv           region, english_start, english_end, target_start, owner: runs
                                        of consecutive objects that move by the same amount (an
                                        English address A in [english_start, english_end) is
                                        A - english_start + target_start in the target).  A
                                        region's rows outside its own extent (an overlay's place,
                                        or for the ARM9 everything outside the overlays' places)
                                        are its reference rows: the objects of other regions it
                                        links to or its data points at, each with the shift of
                                        the region that owns the object, so a run never bridges
                                        two overlays that share a window.  owner is the region
                                        whose own run the row is (the row's region for its own
                                        rows, '?' for an object no region owns): where overlays
                                        share a window, the row of the overlay loaded with the
                                        region is the one that holds
  layout/langmap/word_pairs.tsv         the pointer words of a region's data (objects of the same
                                        size in both links) whose target value the rows do not
                                        give, or that more than one of its rows holds read back
                                        from the target: target, region, the English value, the
                                        target value
                                        (pointers into the middle of data laid out differently,
                                        and into data with no object of the same name)
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
import bisect
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


def extents():
    """{region: (lo, hi)} of every overlay's English place, .bss included."""
    import json
    lay = json.load(open(os.path.join(ROOT, 'layout', 'layout.json'), encoding='utf-8'))
    return {'ov%03d' % o['id']: (o['ram_start'], max(o['ram_end'], o['bss_end']))
            for o in lay['overlays']}


def is_own(g, ea, ext):
    """Whether English address ea lies in region g's own place."""
    if g in ext:
        lo, hi = ext[g]
        return lo <= ea < hi
    return not any(lo <= ea < hi for lo, hi in ext.values())


def data_words(img, lo, hi):
    """{offset: word} of the aligned words of [lo, hi) in a linked image."""
    d, secs = img[0], img[1]
    if lo & 3:
        return {}
    for s in secs:
        if s['type'] == 1 and s['addr'] <= lo and hi <= s['addr'] + s['size']:
            return {a - lo: struct.unpack_from('<I', d, s['off'] + a - s['addr'])[0]
                    for a in range(lo, hi - 3, 4)}
    return {}


def find_row(rows, ea):
    """The shift of the run holding ea, or None."""
    for a, b, c in rows:
        if a <= ea < b:
            return c - a
    return None


def main(argv):
    targets = argv or DEFAULT
    os.makedirs(OUT, exist_ok=True)
    os.makedirs(FULL, exist_ok=True)
    regs = regions()
    ext = extents()
    blinks = {g: read(os.path.join(ROOT, 'build', 'gamelink_data', g, 'ov.elf')) for g in regs}
    black = {g: blinks[g][2] for g in regs}
    changed = ['target\tregion\tname\tkind\tenglish_addr\ttarget_addr\tenglish_size\ttarget_size']
    ptrs = ['target\tregion\tname\toffset\ttarget_value\thow']
    notmapped = ['target\tregion\tname\tenglish_addr\tenglish_size']
    pairs_out = ['target\tregion\tenglish_value\ttarget_value']
    for t in targets:
        rows = ['region\tname\tkind\tenglish_addr\ttarget_addr\tenglish_size\ttarget_size']
        runs = ['region\tenglish_start\tenglish_end\ttarget_start\towner']
        missing = []
        links = {}
        objs = {}           # region -> [(ea, ta, size, name, own)]
        owner = {}          # name -> the region whose own object it is
        owned = []          # (ea, ea + size, ta, region) of every region's own objects
        for g in regs:
            got = read(os.path.join(ROOT, 'build', 'gamelink_data', '%s_%s' % (g, t), 'ov.elf'))
            if got is None:
                missing.append(g)
                continue
            links[g] = got
            d, secs, ts = got
            objs[g] = []
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
                    own = is_own(g, ba, ext)
                    objs[g].append((ba, ta, bsz, name, own))
                    if own:
                        owner[name] = g
                        owned.append((ba, ba + bsz, ta, g))
        owned.sort()
        starts = [o[0] for o in owned]

        def owning(ea, delta):
            """The smallest own object (ea, end, ta, region) of any region that holds English
            address ea and moves by delta, or None."""
            i = bisect.bisect_right(starts, ea)
            best = None
            for j in range(i - 1, max(-1, i - 256), -1):
                a, b, c, g = owned[j]
                if a <= ea < b and c - a == delta and (best is None or b - a < best[1] - best[0]):
                    best = owned[j]
            return best

        own_runs = {g: runs_of([(ea, ta, sz) for ea, ta, sz, _n, o in objs[g] if o]) for g in links}

        def owner_run(region, ea, delta):
            """The run of region's own rows that holds English address ea with that shift."""
            for a, b, c in own_runs.get(region, ()):
                if a <= ea < b and c - a == delta:
                    return (a, b, c, region)
            return None

        for g in regs:
            if g not in links:
                continue
            # reference rows: the owning region's own run of each object the region links to
            # (the run stays inside that region's place, so it never spans two overlays), or the
            # object alone when no region owns it
            ref = set()
            for ea, ta, sz, name, o in objs[g]:
                if not o:
                    ref.add(owner_run(owner.get(name), ea, ta - ea) or (ea, ea + sz, ta, '?'))
            # the pointer words of the region's data, English and target value
            words = set()
            same = set()        # words of the same value in both, checked for ambiguity only
            for name, (ba, bsz, kind) in black[g].items():
                if kind != 'data' or not bsz or name not in links[g][2]:
                    continue
                ta, tsz, _k = links[g][2][name]
                if tsz != bsz:
                    continue
                wb = data_words(blinks[g], ba, ba + bsz)
                wt = data_words(links[g], ta, ta + tsz)
                for off, e in wb.items():
                    v = wt.get(off)
                    if v == e and 0x02000000 <= e < 0x02400000:
                        same.add((e, v))
                    if v is None or v == e or not 0x02000000 <= e < 0x02400000 or abs(v - e) > 0x4000:
                        continue
                    words.add((e, v))
            leftover = []
            for e, v in sorted(words):
                ea, delta = e & ~1, v - e
                if is_own(g, ea, ext):
                    if find_row(own_runs[g], ea) != delta:
                        leftover.append((e, v))
                    continue
                if any(a <= ea < b and c - a == delta for a, b, c, _o in ref):
                    continue
                hit = owning(ea, delta)
                if hit is None:
                    leftover.append((e, v))
                    continue
                ref.add(owner_run(hit[3], ea, delta) or hit)
            out = set((a, b, c, g) for a, b, c in own_runs[g])
            # a reference row stops at the region's own place
            for a, b, c, o in ref:
                if g in ext:
                    lo, hi = ext[g]
                    if a < lo:
                        out.add((a, min(b, lo), c, o))
                    if b > hi:
                        out.add((max(a, hi), b, c + max(a, hi) - a, o))
                else:
                    out.add((a, b, c, o))
            for ea, ee, ta, o in sorted(out):
                runs.append('%s\t0x%08X\t0x%08X\t0x%08X\t%s' % (g, ea, ee, ta, o))
            # a target value that more than one of the region's rows holds (overlays sharing a
            # window) is ambiguous read back: the pair settles it
            for e, v in sorted(words | same):
                if (e, v) in leftover:
                    continue
                back = set(v - ta + ea for ea, ee, ta, _o in out if ta <= (v & ~1) < ta + ee - ea)
                if (e, v) in same and (len(back) < 2 or e not in back):
                    continue        # one reading, or none: a number, or no row is needed
                if back != {e}:
                    leftover.append((e, v))
            for e, v in leftover:
                pairs_out.append('%s\t%s\t0x%08X\t0x%08X' % (t, g, e, v))
        write(os.path.join(FULL, t + '.tsv'), rows)
        write(os.path.join(OUT, t + '.tsv'), runs)
        print('%s: %d objects, %d runs%s' % (t, len(rows) - 1, len(runs) - 1,
                                            ('; no link for ' + ', '.join(missing)) if missing else ''))
    write(os.path.join(OUT, 'size_changed.tsv'), changed)
    write(os.path.join(OUT, 'size_changed_ptrs.tsv'), ptrs)
    write(os.path.join(OUT, 'not_mapped.tsv'), notmapped)
    write(os.path.join(OUT, 'word_pairs.tsv'), pairs_out)
    print('size_changed.tsv: %d rows, size_changed_ptrs.tsv: %d rows, not_mapped.tsv: %d rows, '
          'word_pairs.tsv: %d rows' % (len(changed) - 1, len(ptrs) - 1, len(notmapped) - 1,
                                       len(pairs_out) - 1))


if __name__ == '__main__':
    main(sys.argv[1:])
