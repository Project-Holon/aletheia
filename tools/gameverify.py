#!/usr/bin/env python3
"""gameverify.py: compile every merged file of src/game/ and compare it with the
original bytes.

Each merged file (src/game/<region>/<tu>.c or <tu>_pNN.c) carries a header with
its first function address, region, isa, compiler, flags and lang.  It is compiled
once as a translation unit and its .text compared with the image from that
address (match.py run_tu, the `tu` command), in its own -lang mode.  Member files
inside TU folders are copies of verified src/matched files and are compiled the
same way when --members is given.

Runtime-kind files (arm9 files whose `function:` names are all rows of
layout/runtime_arm9.txt, such as unit_020911D4_p03.c) are not contiguous, so a
whole-file compare would report DIFF.  Each of their functions is compared at
its own runtime_arm9.txt row instead (match.runtime_entry_status, the same
check `match.py manifest --verify` makes for a `runtime` entry).

A file marked `contiguous: no` is a non-contiguous C piece: one original whose
functions sit in two or more non-adjacent ranges, with another original
between them, so a whole-file compare would also report DIFF.  Each of its
functions is compared at its own address, taken from the file's `symbols:`
block, instead (match.piece_entry_status, the same check `match.py manifest
--verify` makes for a `pieces: true` game_unit).  The marker is absent from
every existing file, so no file takes this path until one is merged as a piece.

Data-only files (such as src/game/arm9/crt0.c before its code was merged in)
compile to an object with data sections and no code, so the text compare has
nothing to compare (EMPTY).  Their bytes are checked by tools/gamelink.py, which
places the data sections at their header addresses and compares the linked
image.  Such a file is reported on its own line, "DATA-ONLY ... (checked by
gamelink)", and is not counted as not exact.  The claim holds only while the
gamelink run of its region passes with an empty `unplaced_data` list.  Only an EMPTY verdict whose
object really has no code bytes and at least one data byte qualifies.

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


def runtime_kind(path, region):
    """The match.py header of an arm9 file whose functions are all runtime_arm9.txt rows, else None."""
    if region != 'arm9':
        return None
    import match
    h = match.read_header(path)
    names = [n.strip() for n in (h.get('function') or '').split(',') if n.strip()]
    rt = set(match.runtime_addresses().values())
    if names and all(n in rt for n in names):
        return h
    return None


def runtime_verify(path, h, addr, region):
    """Per-function verdict of a runtime-kind file, keyed like rs.verify."""
    import match
    lang = (h.get('lang') or 'c99').strip()
    st, _covers, note = match.runtime_entry_status(path, h, addr, h.get('flags', '-O4,p'), lang, region)
    return {lang: st + (': ' + note if note else '')}


def piece_kind(path, region):
    """The match.py header of a file marked non-contiguous (`contiguous: no`), else None.

    A non-contiguous piece is one original whose code sits in two or more
    non-adjacent ranges, with another original between them, so a whole-file
    compare would report DIFF.  The marker is absent from every existing file,
    so this returns None for all of them."""
    import match
    h = match.read_header(path)
    if match.header_is_piece(h):
        return h
    return None


def piece_verify(path, h, addr, region):
    """Per-function verdict of a non-contiguous piece, keyed like rs.verify."""
    import match
    lang = (h.get('lang') or 'c99').strip()
    st, _covers, note, _by_name = match.piece_entry_status(
        path, h, addr, h.get('flags', '-O4,p'), lang, region)
    return {lang: st + (': ' + note if note else '')}


def data_only(path, st):
    """True when `path` compiles to an object with data bytes and no code bytes."""
    import shutil
    import tempfile
    import match
    work = tempfile.mkdtemp(prefix='bwgv_')
    try:
        flags = st['flags'].split() if st['flags'] else ['-O4,p']
        obj, _cmd, _log, _rc = match.compile_tu(path, st['compiler'], flags, st['isa'] == 'thumb',
                                                st['lang'] or None, work)
        if obj is None:
            return False
        with open(obj, 'rb') as fh:
            o = match.Obj(os.path.basename(obj), fh.read())
        if not o.ok:
            return False
        code = data = 0
        for s in o.sections:
            if not s[2] & 2 or not s[5]:          # SHF_ALLOC, size
                continue
            if s[2] & 4:                          # SHF_EXECINSTR
                code += s[5]
            else:
                data += s[5]
        return code == 0 and data > 0
    finally:
        shutil.rmtree(work, ignore_errors=True)


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
    rows, bad, nmatch, ndata = [], 0, 0, 0
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
            elif runtime_kind(p, reg) is not None:
                v = runtime_verify(p, runtime_kind(p, reg), addr, reg)
            elif piece_kind(p, reg) is not None:
                v = piece_verify(p, piece_kind(p, reg), addr, reg)
            else:
                v = rs.verify(p, reg, addr, st)
            ok = rs.lang_ok(v, st) if (addr and not badsym) else False
            rel = os.path.relpath(p, ROOT).replace(os.sep, '/')
            if (not ok and addr and not badsym and v.get(st['lang'] or 'nolang', '').startswith('EMPTY')
                    and data_only(p, st)):
                ndata += 1
                rows.append({'file': rel, 'ok': 'data-only', 'verdict': 'data-only (checked by gamelink)'})
                print('DATA-ONLY  %s  (checked by gamelink)' % rel, flush=True)
                continue
            bad += 0 if ok else 1
            nmatch += 1 if ok and (v.get(st['lang'] or 'nolang', '').startswith('MATCH')) else 0
            rows.append({'file': rel, 'ok': 'yes' if ok else 'NO',
                         'verdict': ' '.join('%s=%s' % kv for kv in v.items())[:300]})
            if not ok:
                print('NOT EXACT  %s  %s' % (rel, rows[-1]['verdict'][:160]), flush=True)
    print('files: %d, not exact: %d, MATCH (relocations wildcarded): %d, data-only (checked by gamelink): %d'
          % (len(rows), bad, nmatch, ndata))
    if a.report:
        with open(a.report, 'w', newline='', encoding='utf-8') as f:
            w = csv.DictWriter(f, ['file', 'ok', 'verdict'], delimiter='\t')
            w.writeheader()
            w.writerows(rows)
    sys.exit(1 if bad else 0)


if __name__ == '__main__':
    main()
