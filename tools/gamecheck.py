#!/usr/bin/env python3
"""gamecheck.py: is every verified function in the restructured tree exactly once?

src/game/<region>/ is built from src/matched/ by tools/restructure.py and then
edited by merge lanes.  This check makes sure nothing was lost or doubled on
the way: every function that has an EXACT/EXACT* verification entry (its own, or
as a member of a verified unit) must be defined exactly once among the .c files
of src/game/<region>/ (merged files and the member files in TU folders).

The verified functions are found by address: entries' `address` fields, and the
members of unit entries placed by tools/fnaddr.py (the entry's `addresses`, a
func_XXXXXXXX name, or the unit's compiled layout), never only by a name that
carries an address (restructure.shard_index).  A definition in the tree is
recognised by the address in its name (func_/sub_XXXXXXXX), or by its name when
the verification entries give that name one address in the region (a real name
after a rename, a vendor name such as _start); doubles are found by address the
same way.  A function
that the tree defines under another name (an SDK name the verification entry
does not carry, such as OSi_ReferSymbol at 0x02004EB0, entry func_02004EB0 of
unit_02004EAC) is recognised by its place: the file of the region whose header
address is the closest one at or below the address is compiled and laid out
like `gameverify` does (match.layout_tu), and a function symbol of that object
that lands on the address, and that the file defines at top level, counts.
gameverify's EXACT for that file is what proves the bytes there.  Runtime-kind
files (functions not contiguous) are not used for this.

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
import fnaddr  # noqa: E402  (function addresses whatever the name)

ADDR = re.compile(r'([0-9A-Fa-f]{8})$')
# A top-level function definition or prototype of ANY name.  protofix.DECL_RE
# matches only func_/sub_XXXXXXXX names, so a function renamed to a real name
# would not be seen as defined at all.
DEF_RE = re.compile(r'^[ \t]*((?:(?:extern|static)\s+)*)([A-Za-z_][\w\s\*]*?)\b([A-Za-z_]\w*)'
                    r'\s*\(([^;{}]*)\)\s*([;{])', re.M)


SELF_ROW = re.compile(r'^\s*\*\s+([A-Za-z_]\w*)\s+0[xX]([0-9A-Fa-f]{8})\s+(?:thumb|arm)\b(.*)$')


def header_rows(raw):
    """{name: address} of the code rows (`name 0xADDR thumb|arm [region]`) in the
    leading comment of a source file.  A row without a region tag, or tagged with
    the file's own region, may name a function the file defines (a renamed
    function the layout estimate cannot place)."""
    m = re.match(r'\s*/\*.*?\*/', raw, re.S)
    out = {}
    if not m:
        return out
    for line in m.group(0).split('\n'):
        r = SELF_ROW.match(line)
        if r:
            out[r.group(1)] = (int(r.group(2), 16), r.group(3).split())
    return out


ROWDEF = {}   # address -> files defining a function whose header row gives that address


def tree_files(tree, region):
    """Paths of the .c files under tree/region (scratch files starting with _ left out)."""
    for dp, _dn, fn in os.walk(os.path.join(tree, region)):
        for f in fn:
            if f.endswith('.c') and not f.startswith('_'):
                yield os.path.join(dp, f)


def region_names(idx, region):
    """{name: address} for the names the verification entries of one region give
    one address (an entry's own name, a unit member's name: restructure.shard_index,
    which places members by address through tools/fnaddr.py).  A name given to
    two addresses (static functions of two files) is left out."""
    seen = {}
    for (r, x), (_src, ent) in idx.items():
        if r != region:
            continue
        for n in {ent.get('name')} - {None, ''}:
            seen.setdefault(n, set()).add(x)
    return {n: next(iter(xs)) for n, xs in seen.items() if len(xs) == 1}


def defined_in_tree(tree, region, names=None):
    """({address or name: [files]}, all text) of the top-level definitions.

    A definition is keyed by the address in its name (func_/sub_XXXXXXXX), else
    by the address `names` (region_names) gives its name, else by its name."""
    out = collections.defaultdict(list)
    ROWDEF.clear()
    texts = []
    for p in tree_files(tree, region):
        try:
            raw = open(p, encoding='latin1').read()
        except OSError:
            continue
        texts.append(raw)
        m = pf.mask(raw)
        tab = pf.depth_table(m)
        rows = header_rows(raw)
        rel = os.path.relpath(p, ROOT).replace(os.sep, '/')
        for mm in DEF_RE.finditer(m):
            if mm.group(5) != '{' or pf.depth_at(tab, mm.start()) != 0:
                continue
            nm = mm.group(3)
            # only a func_/sub_XXXXXXXX name is an address (not a helper such
            # as rd8_021592D8 that only ends in one)
            am = fnaddr.name_address(nm)
            if am is not None:
                key = am
            elif names and nm in names:
                key = names[nm]
            else:
                key = nm
            if am is None and nm in rows and (not rows[nm][1] or region in rows[nm][1]):
                # a renamed function the file defines and gives an address row
                ROWDEF.setdefault(rows[nm][0], []).append(rel)
            out[key].append(rel)
    return out, '\n'.join(texts)


_PLACED = {}


def placed_functions(path, region):
    """{address: name} of the function symbols of the file at `path`, laid out
    from its header address the way gameverify compiles it ({} on any error)."""
    if path in _PLACED:
        return _PLACED[path]
    out = {}
    import shutil
    import tempfile
    import match
    import gameverify as gv
    work = tempfile.mkdtemp(prefix='bwgc_')
    try:
        raw = open(path, encoding='latin1').read()
        h, st = gv.settings_of(raw)
        addr = int(h.get('address', '0'), 16)
        if addr and gv.runtime_kind(path, (h.get('region') or region).strip()) is None \
                and gv.piece_kind(path, (h.get('region') or region).strip()) is None:
            flags = st['flags'].split() if st['flags'] else ['-O4,p']
            obj, _c, _l, _r = match.compile_tu(path, st['compiler'], flags, st['isa'] == 'thumb',
                                               st['lang'] or None, work)
            if obj is not None:
                tl = match.layout_tu(obj)
                for n in tl.local_isa:
                    if n in tl.locals:
                        out[addr + tl.locals[n]] = n
    except (Exception, SystemExit):
        out = {}
    finally:
        shutil.rmtree(work, ignore_errors=True)
    _PLACED[path] = out
    return out


def file_starts(tree, region):
    """Sorted [(header address, path)] of the top-level files of tree/region."""
    out = []
    base = os.path.join(tree, region)
    for p in tree_files(tree, region):
        if os.path.normpath(os.path.dirname(p)) != os.path.normpath(base):
            continue
        try:
            h = pf.parse_header(open(p, encoding='latin1').read())
            out.append((int(h.get('address', '0'), 16), p))
        except (OSError, ValueError):
            continue
    return sorted(x for x in out if x[0])


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
        have, blob = defined_in_tree(a.tree, region, region_names(idx, region))

        def present(x):
            ent = idx[(region, x)][1]
            nm = ent.get('name')
            if x in have or nm in have or x in ROWDEF:
                return True
            # a unit entry is named after its file; its first listed
            # function is the one at the entry's address (vendor names)
            fl = ent.get('functions') or []
            names = [nm or 'func_%08X' % x]
            if str(ent.get('kind', '')).endswith('_unit') and fl:
                names.append(fl[0])
            if any(n in have for n in names):
                return True
            # asm functions and other forms the declaration pattern misses
            return any(re.search(r'^[^;\n]*\b%s\s*\([^;]*$' % re.escape(n), blob, re.M) is not None
                       for n in names)

        missing = sorted(x for x in want if not present(x))
        if missing:
            import bisect
            starts = file_starts(a.tree, region)
            keys = [st for st, _p in starts]

            def placed(x):
                i = bisect.bisect_right(keys, x) - 1
                if i < 0:
                    return False
                p = starts[i][1]
                n = placed_functions(p, region).get(x)
                rel = os.path.relpath(p, ROOT).replace(os.sep, '/')
                if n is None:
                    return False
                if rel in have.get(n, []):
                    return True
                # forms the declaration pattern misses (asm, empty bodies): a
                # line of the file itself that opens a definition of n
                txt = pf.mask(open(p, encoding='latin1').read())
                return re.search(r'^[^;\n]*\b%s\s*\([^;]*$' % re.escape(n), txt, re.M) is not None
            missing = [x for x in missing if not placed(x)]
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
