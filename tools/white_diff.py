#!/usr/bin/env python3
"""white_diff.py -- how Pokemon White differs from Black, per region and per function.

Reads extract/ (Black) and extract_white/ (White), both gitignored, plus the Black
layout and the generated asm/ listings for function boundaries.  Writes names,
addresses and byte counts only (docs/restructure/white_diff.tsv); never game bytes.

  python tools/white_diff.py [--out docs/restructure/white_diff.tsv]
                             [--json build/white/summary.json] [--only ov009,arm9]

Kinds in the TSV (one row per Black function, plus rows for White-only ranges):
  same      raw bytes identical at the same offset in the region (overlays all load 0x20 higher)
  constant  same region offset, relocation-wildcarded bytes equal, raw words differ
  shifted   relocation-wildcarded bytes equal at a different region offset
  differs   bytes differ beyond relocations (bytes = unmatched words * 4)
  new       White-only range (no Black counterpart), bytes = its excess length
Relocation wildcards: ARM B/BL/BLX displacement, Thumb BL pair halves, and words that
look like addresses (RAM, TCM, IO, VRAM).  A pure constant change inside such a word
is therefore classed constant, not differs; the region stats count those words.
"""
import argparse
import bisect
import difflib
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from white_align import mask_words  # noqa: E402

LABEL = re.compile(r'^(func_|veneer_|d_)([0-9A-F]{8}):')


def func_starts(asm_path):
    out = []
    with open(asm_path, 'r', errors='replace') as fh:
        for line in fh:
            if line[:1] in ('f', 'v', 'd'):
                m = LABEL.match(line)
                if m:
                    out.append((int(m.group(2), 16), m.group(1)))
    return out


def rd(p):
    with open(p, 'rb') as fh:
        return fh.read()


def u32_at(path, off):
    return int.from_bytes(rd(path)[off:off + 4], 'little')


def aligned_ops(mb, mw):
    if mb == mw:
        return [('equal', 0, len(mb), 0, len(mw))]
    sm = difflib.SequenceMatcher(None, mb, mw, autojunk=False)
    return sm.get_opcodes()


def classify(funcs, end, base_b, base_w, rb, rw, ops, region, rows):
    starts = [f[0] for f in funcs]
    eq = [(i1, i2, j1) for tag, i1, i2, j1, j2 in ops if tag == 'equal']
    eq_i1 = [e[0] for e in eq]
    for k, (a, kind) in enumerate(funcs):
        b = starts[k + 1] if k + 1 < len(funcs) else end
        if kind == 'd_':
            continue
        s, e = (a - base_b) // 4, (b - base_b) // 4
        if e <= s:
            continue
        covered = 0
        first_j = None
        shifts = set()
        rawdiff = 0
        p = max(bisect.bisect_right(eq_i1, s) - 1, 0)
        while p < len(eq) and eq[p][0] < e:
            i1, i2, j1 = eq[p]
            lo, hi = max(i1, s), min(i2, e)
            if lo < hi:
                covered += hi - lo
                if first_j is None:
                    first_j = j1 + (lo - i1) - (lo - s)
                shifts.add(j1 - i1)
                for w in range(lo, hi):
                    jw = j1 + w - i1
                    if rb[w * 4:w * 4 + 4] != rw[jw * 4:jw * 4 + 4]:
                        rawdiff += 1
            p += 1
        n = e - s
        baddr = '0x%08X' % a
        if covered == n:
            shift = next(iter(shifts)) if len(shifts) == 1 else None
            if shift is None:
                rows.append((region, baddr, '0x%08X' % (base_w + first_j * 4), 'shifted', rawdiff * 4))
            elif shift == 0:
                rows.append((region, baddr, '0x%08X' % (base_w + s * 4), 'same' if rawdiff == 0 else 'constant', rawdiff * 4))
            else:
                rows.append((region, baddr, '0x%08X' % (base_w + (s + shift) * 4), 'shifted', rawdiff * 4))
        else:
            waddr = '0x%08X' % (base_w + first_j * 4) if first_j is not None else '-'
            rows.append((region, baddr, waddr, 'differs', (n - covered) * 4))
    for tag, i1, i2, j1, j2 in ops:
        if tag in ('insert', 'replace') and (j2 - j1) > (i2 - i1):
            rows.append((region, '-', '0x%08X' % (base_w + j1 * 4), 'new', ((j2 - j1) - (i2 - i1)) * 4))


def region_stats(name, rb, rw, mb, mw, ops, base_b, base_w):
    nb = sum(i2 - i1 for t, i1, i2, j1, j2 in ops if t != 'equal')
    nw = sum(j2 - j1 for t, i1, i2, j1, j2 in ops if t != 'equal')
    rawdiff = 0
    for t, i1, i2, j1, j2 in ops:
        if t == 'equal':
            for w in range(i2 - i1):
                if rb[(i1 + w) * 4:(i1 + w) * 4 + 4] != rw[(j1 + w) * 4:(j1 + w) * 4 + 4]:
                    rawdiff += 1
    return dict(region=name, black_size=len(rb), white_size=len(rw), black_base=base_b, white_base=base_w,
                identical=(rb == rw), masked_equal=(mb == mw), unaligned_black_words=nb,
                unaligned_white_words=nw, reloc_or_const_words=rawdiff)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--out', default='docs/restructure/white_diff.tsv')
    ap.add_argument('--json', default='build/white/summary.json')
    ap.add_argument('--only', default=None)
    args = ap.parse_args()
    LB = json.load(open('layout/layout.json'))
    LW = json.load(open('build/white/layout/layout.json'))
    rows, stats = [], []
    only = set(args.only.split(',')) if args.only else None

    def run(name, rb, rw, base_b, base_w, asm, skip_words=0):
        if only and name not in only:
            return
        rb2, rw2 = rb[skip_words * 4:], rw[skip_words * 4:]
        base_b2, base_w2 = base_b + skip_words * 4, base_w + skip_words * 4
        mb, mw = mask_words(rb2), mask_words(rw2)
        ops = aligned_ops(mb, mw)
        st = region_stats(name, rb2, rw2, mb, mw, ops, base_b2, base_w2)
        st['skipped_prefix_bytes'] = skip_words * 4
        stats.append(st)
        if asm and os.path.isfile(asm):
            fs = sorted(f for f in func_starts(asm) if base_b2 <= f[0] < base_b2 + len(rb2))
            classify(fs, base_b2 + (len(rb2) // 4) * 4, base_b2, base_w2, rb2, rw2, ops, name, rows)
        else:
            kind = 'same' if st['identical'] else ('constant' if st['masked_equal'] else 'differs')
            rows.append((name, '0x%08X' % base_b2, '0x%08X' % base_w2, 'region-' + kind,
                         (st['unaligned_black_words'] + st['reloc_or_const_words']) * 4))

    ab, aw = rd('extract/arm9_dec.bin'), rd('extract_white/arm9_dec.bin')
    sb, sw = LB['arm9']['static'], LW['arm9']['static']
    run('arm9', ab[:sb['size']], aw[:sw['size']], sb['ram_start'], sw['ram_start'], 'asm/arm9/main.s',
        skip_words=0x800 // 4)
    asm_for = {'ITCM': 'asm/arm9/itcm.s', 'VRAM_LCDC': 'asm/arm9/vram_lcdc.s'}
    for i, (xb, xw) in enumerate(zip(LB['arm9']['autoloads'], LW['arm9']['autoloads'])):
        nm = 'arm9_autoload%d_%s' % (i, xb['kind'])
        rb_ = ab[xb['src_offset']:xb['src_offset'] + xb['code_size']]
        rw_ = aw[xw['src_offset']:xw['src_offset'] + xw['code_size']]
        run(nm, rb_, rw_, xb['ram_start'], xw['ram_start'], asm_for.get(xb['kind']))
    for ob, ow in zip(LB['overlays'], LW['overlays']):
        name = 'ov%03d' % ob['id']
        pb = 'extract/' + (ob.get('decompressed_file') or ob['file'])
        pw = 'extract_white/' + (ow.get('decompressed_file') or ow['file'])
        if not (os.path.isfile(pb) and os.path.isfile(pw)):
            stats.append(dict(region=name, note='missing file', black=pb, white=pw))
            continue
        run(name, rd(pb), rd(pw), ob['ram_start'], ow['ram_start'], 'asm/overlays/%s.s' % name)
    # Overlay 230 after both decryptor layers (tools/ovcrypt.py reads each version's own pins).
    if not only or 'ov230d' in only:
        import ovcrypt
        vb = ovcrypt.view_for('extract', ovcrypt.overlay_record(LB))
        vw = ovcrypt.view_for('extract_white', ovcrypt.overlay_record(LW))
        run('ov230d', bytes(vb.data), bytes(vw.data), vb.base, vw.base, 'asm/ov230d/ov230d.s')
    # The DSi side: White's dump holds a repeated 4 KiB filler page in place of the whole DSi area
    # (ROM 0xC400000..0xC45D400), so arm9i has no bytes to compare; the header still says how
    # much the container changed.
    tb, tw = LB.get('twl'), LW.get('twl')
    if (not only or 'twl' in only) and tb:
        wsz = u32_at('extract_white/header.bin', 0x1CC)
        rows.append(('twl', '0x%08X' % tb['ram_start'], '-', 'region-unavailable', tb['rom_size'] - wsz))
        stats.append(dict(region='twl', black_rom_size=tb['rom_size'], white_rom_size=wsz,
                          note='white dump has filler instead of the DSi area'))
    os.makedirs(os.path.dirname(args.json), exist_ok=True)
    with open(args.json, 'w') as fh:
        json.dump(stats, fh, indent=1)
    with open(args.out, 'w', newline='\n') as fh:
        fh.write('region\tblack_address\twhite_address\tkind\tbytes\n')
        for r in rows:
            fh.write('\t'.join(str(x) for x in r) + '\n')
    print('rows', len(rows), 'regions', len(stats))


if __name__ == '__main__':
    main()
