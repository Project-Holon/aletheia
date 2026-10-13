#!/usr/bin/env python3
"""sdkrename.py: give functions their real SDK/library names across the tree.

A rename map is a TSV with the columns

    old  new  address  region  isa  note

(`#` lines are comments).  `old` is the name the tree uses today (usually
func_XXXXXXXX), `new` the vendor symbol name, `address` and `region` where the
function sits, `isa` arm|thumb.  `note` is free text (the evidence flags).

For every row the tool

  1. refuses the rename when `new` already names something else anywhere:
     a manifest entry (layout/matched/**/*.json), a layout/symbols_sdk.json
     row, a header `symbols:` row or a `function:`/`address:` header pair at
     another address, or a definition in a source file that no manifest entry
     at this address accounts for (static helpers, inline functions);
     a type, variable or field of that name also blocks it;
  2. replaces `old` by `new` on word boundaries in every .c/.h file under the
     roots (default src/game and src/matched): code, `function:` header lists
     and `symbols:` rows alike;
  3. adds a `symbols:` row `new address isa [region]` to each changed file
     that references `new` without defining it and has no row for it (match.py
     resolves a relocation in a TU only through a row or an address-bearing
     name);
  4. renames the manifest entries (`name`, and `functions` lists of unit
     entries) whose name is `old`; source paths are not changed.  A unit
     entry whose member list changes gets an `addresses` list parallel to
     `functions` (each member's address, tools/fnaddr.py), so the counting
     tools still place a member whose new name carries no address.

With --local-ok, a row whose note holds `bind:local` (the vendor symbol is
static in its object) is not refused because the name exists at another
address (another region's manifest entry, symbols_sdk.json row, header row or
definition): a static function may share its name with a function in another
object.  The row is still refused when a src/game file other than the
defining one uses the old name in code (a static function cannot be called by
name from another TU) or when the name is a type, variable or field.  After
the rename, the definition and its file-scope prototypes in the files that
define the function at this address get `static` (an `extern` is replaced).

A row whose `old` is itself a vendor-style name (not func_/sub_/unit_ plus
its own address) is a byte-equality misname: the same name stays right at
other addresses.  Such a row is applied only to the files that mean this
address (scoped): the src/matched file whose header names `old` at the
address, files whose `symbols:` row gives `old` this address, the src/game
file of the region that covers the address and defines `old`, and files that
only mention `old` in comments and give the address in hex.  Every other file
keeps `old`.  The same `old` may then appear in several rows (one per
address), and with --local-ok the same `bind:local` `new` too.  --no-scope
applies every row to every file, as before.

Dry run by default (prints what would change); --apply writes.  A file that
already holds both `old` and `new` is renamed and reported (two declarations
of one function under two names may then need merging by hand).

    python tools/sdkrename.py --build-twl docs/restructure/twl_vendor.tsv --out MAP
    python tools/sdkrename.py --map MAP                 # dry run
    python tools/sdkrename.py --map MAP --apply
"""
import argparse
import collections
import csv
import glob
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import fnaddr  # noqa: E402  (unit member addresses, recorded before a rename)

SYM_ROW = re.compile(r'^\s*\*\s+([A-Za-z_][A-Za-z0-9_]*)\s+(0[xX][0-9A-Fa-f]+)\s+(thumb|arm|data)\b(.*)$')
SYMBOLS_OPEN = re.compile(r'^\s*\*?\s*symbols\s*:\s*$', re.I)
HDR_FIELD = re.compile(r'^\s*\*\s*(function|address|region)\s*:\s*(.*?)\s*$')
MASK = re.compile(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'', re.S)

# flags of docs/restructure/twl_vendor.tsv that name one symbol with evidence
SINGLE_FLAGS = {'OK', 'by_neighbour_object', 'by_order', 'NEAR',
                'vendor_shorter_than_extent', 'WEAK_SMALL'}


def rel(p):
    return os.path.relpath(p, ROOT).replace(os.sep, '/')


def blank(m):
    return re.sub(r'[^\n]', ' ', m.group(0))


def header_span(text):
    """(start, end) of the leading block comment, or None."""
    m = re.match(r'\s*/\*.*?\*/', text, re.S)
    return (m.start(), m.end()) if m else None


def parse_header(text):
    """{'function': [...], 'address': int|None, 'region': str, 'rows': {name: addr}}."""
    out = {'function': [], 'address': None, 'region': '', 'rows': {}}
    hs = header_span(text)
    if not hs:
        return out
    for line in text[hs[0]:hs[1]].splitlines():
        m = HDR_FIELD.match(line)
        if m and m.group(1) == 'function' and not out['function']:
            out['function'] = [x.strip() for x in m.group(2).split(',') if x.strip()]
        elif m and m.group(1) == 'address' and out['address'] is None:
            try:
                out['address'] = int(m.group(2).split()[0], 16)
            except (ValueError, IndexError):
                pass
        elif m and m.group(1) == 'region' and not out['region']:
            out['region'] = m.group(2).split()[0] if m.group(2) else ''
        r = SYM_ROW.match(line)
        if r:
            out['rows'].setdefault(r.group(1), int(r.group(2), 16))
    return out


def source_files(roots):
    for root in roots:
        for dp, _dn, fn in os.walk(os.path.join(ROOT, root)):
            for f in fn:
                if f.endswith(('.c', '.h')):
                    yield os.path.join(dp, f)


def load_manifests():
    """[(path, data)] of every layout/matched/**/*.json."""
    out = []
    for p in sorted(glob.glob(os.path.join(ROOT, 'layout', 'matched', '**', '*.json'), recursive=True)):
        try:
            with open(p, encoding='utf-8') as fh:
                out.append((p, json.load(fh)))
        except (OSError, ValueError):
            pass
    return out


def manifest_names(manifests):
    """{name: {(region, address)}} over every manifest entry."""
    out = collections.defaultdict(set)
    for _p, d in manifests:
        for e in d.get('functions', []):
            try:
                out[e['name']].add((e.get('region') or d.get('region'), int(str(e['address']), 16)))
            except (KeyError, ValueError):
                pass
    return out


def sdk_names():
    out = collections.defaultdict(set)
    p = os.path.join(ROOT, 'layout', 'symbols_sdk.json')
    if os.path.exists(p):
        with open(p, encoding='utf-8') as fh:
            for s in json.load(fh)['symbols']:
                out[s['name']].add((s['region'], int(s['address'])))
    return out


def read_map(path):
    rows = []
    with open(path, encoding='utf-8') as fh:
        for line in fh:
            if not line.strip() or line.startswith('#'):
                continue
            f = line.rstrip('\r\n').split('\t')
            if f[0] == 'old':
                continue
            rows.append({'old': f[0], 'new': f[1], 'address': int(f[2], 16),
                         'region': f[3], 'isa': f[4] if len(f) > 4 else 'arm',
                         'note': f[5] if len(f) > 5 else ''})
    return rows


def build_twl(tsv, out):
    """Write a map from docs/restructure/twl_vendor.tsv; print the rows left out."""
    keep, skipped = [], []
    with open(tsv, encoding='utf-8') as fh:
        for r in csv.DictReader(fh, delimiter='\t'):
            flags = set(r['flags'].split(',')) if r['flags'] else set()
            if not r['vendor_symbol'] or 'NO_MATCH' in flags:
                continue
            if any(f.startswith('AMBIGUOUS') for f in flags) or not flags <= SINGLE_FLAGS:
                skipped.append((r['address'], r['our_name'], r['flags'], r['all_candidates']))
                continue
            if r['our_name'] == r['vendor_symbol']:
                continue
            note = '' if flags == {'OK'} else 'flag:' + r['flags']
            keep.append((r['our_name'], r['vendor_symbol'], r['address'], 'twl', 'arm',
                         ('%s %s %s' % (r['vendor_archive'].split('/')[-1], r['object'], note)).strip()))
    with open(out, 'w', encoding='utf-8', newline='\n') as fh:
        fh.write('old\tnew\taddress\tregion\tisa\tnote\n')
        for k in keep:
            fh.write('\t'.join(k) + '\n')
    print('map rows: %d -> %s' % (len(keep), out))
    for s in skipped:
        cands = sorted({c.split(':')[-1] for c in s[3].split(';') if c})
        print('skipped %s %s %s: %s' % (s[0], s[1], s[2], ', '.join(cands[:8])))


def word(name):
    return re.compile(r'(?<![A-Za-z0-9_])' + re.escape(name) + r'(?![A-Za-z0-9_])')


def defines(masked, name):
    """True when `masked` (comments blanked) holds a definition of function `name`.

    The name must open its line or follow only a return type on it, so a call
    in a condition (`if (name(x)) {`) is not taken for a definition."""
    return re.search(r'^[ 	]*(?:[A-Za-z_][A-Za-z0-9_ 	\*]*[ 	\*])?' + re.escape(name)
                     + r'\s*\([^;{}]*\)\s*\{', masked, re.M) is not None


DECL_KW = ('return', 'typedef', 'static', 'else', 'goto', 'case', 'do')


def make_static(text, name):
    """Text with file-scope declarations and the definition of `name` made static."""
    masked = MASK.sub(blank, text)
    rx = re.compile(r'^(extern[ 	]+)?([A-Za-z_][A-Za-z0-9_ 	\*]*?[ 	\*])' + re.escape(name) + r'\s*\(', re.M)
    out, last = [], 0
    for m in rx.finditer(masked):
        first = m.group(2).split()[0] if m.group(2).split() else ''
        if first in DECL_KW or re.search(r'\bstatic\b', m.group(2)):
            continue
        out.append(text[last:m.start()])
        out.append('static ' + text[m.start(2):m.end(2)])
        last = m.end(2)
    out.append(text[last:])
    return ''.join(out)


def non_function_use(masked, name):
    """True when `name` is used as a type, tag, variable or field."""
    n = re.escape(name)
    pats = [r'\b(?:struct|union|enum)\s+' + n + r'\b',
            r'\btypedef\b[^;]*\b' + n + r'\s*;',
            r'[.>]\s*' + n + r'\b(?!\s*\()',
            r'\b' + n + r'[ \t]+[\*A-Za-z_]']
    return any(re.search(p, masked) for p in pats)


ELSEWHERE = re.compile(r'^(manifest entry .* at |symbols_sdk\.json row at |.*: symbols row at |.*: defines it at |.*: defines a function of that name$|new name twice in the map$)')


def local_ok(rows, bad, files, texts, scopes=None):
    """Clear the refusals of `bind:local` rows that only name the function elsewhere.

    Returns {index: [defining files]} for the rows let through."""
    ok = {}
    game = [p for p in files if rel(p).startswith('src/game/')]
    for i, r in enumerate(rows):
        if 'bind:local' not in r['note'].split():
            continue
        why = bad.get(i, [])
        if any(not ELSEWHERE.match(w) for w in why):
            continue
        defs, users = [], []
        w_old = word(r['old'])
        for p in (files if not scopes or i not in scopes else sorted(scopes[i])):
            t = texts[p]
            if not w_old.search(t):
                continue
            masked = MASK.sub(blank, t)
            hdr = parse_header(t)
            here = (hdr['function'] == [r['old']] and hdr['address'] == r['address']) or                 (r['old'] in hdr['function'] and defines(masked, r['old'])) or                 (bool(scopes) and i in scopes and defines(masked, r['old']))
            if here:
                defs.append(p)
            elif p in game and w_old.search(masked):
                users.append(p)
        if users:
            bad[i] = why + ['%s: uses %s in code, so it cannot be static' % (rel(u), r['old']) for u in users]
            continue
        if not defs:
            bad[i] = why + ['no file defines %s' % r['old']]
            continue
        for w in why:
            print('LOCAL %s -> %s (0x%08X): allowed, %s' % (r['old'], r['new'], r['address'], w))
        bad.pop(i, None)
        ok[i] = defs
    return ok


ADDR_NAME = re.compile(r'^(?:func|sub|unit)_([0-9A-Fa-f]{8})(?:_p\d+)?$')


def is_scoped(r):
    """True when the row renames a vendor-style name at one address only."""
    m = ADDR_NAME.match(r['old'])
    return not (m and int(m.group(1), 16) == r['address'])


def file_region(p, hdr):
    parts = rel(p).split('/')
    if hdr['region']:
        return hdr['region']
    return parts[2] if len(parts) > 3 and parts[1] == 'game' else ''


def scope_files(rows, files, texts):
    """{row index: set of files} for the scoped rows (see the module text)."""
    hdrs = {p: parse_header(texts[p]) for p in files}
    starts = collections.defaultdict(list)
    for p in files:
        if rel(p).startswith('src/game/') and hdrs[p]['address'] is not None:
            starts[file_region(p, hdrs[p])].append((hdrs[p]['address'], p))
    for v in starts.values():
        v.sort()
    out = {}
    for i, r in enumerate(rows):
        if not is_scoped(r):
            continue
        own = None
        for a, p in starts.get(r['region'], ()):
            if a <= r['address']:
                own = p
        w = word(r['old'])
        hexs = re.compile(r'0x0*%X\b' % r['address'], re.I)
        got = set()
        for p in files:
            t = texts[p]
            if not w.search(t):
                continue
            h = hdrs[p]
            masked = MASK.sub(blank, t)
            row = h['rows'].get(r['old'])
            if h['function'] == [r['old']] and h['address'] == r['address']:
                got.add(p)
            elif row is not None:
                if row == r['address']:
                    got.add(p)
            elif p == own and defines(masked, r['old']):
                got.add(p)
            elif not w.search(masked) and hexs.search(t):
                got.add(p)
        out[i] = got
    return out


def check_conflicts(rows, files, texts, manifests):
    """{index: [reasons]} for rows whose new name is taken."""
    man = manifest_names(manifests)
    sdk = sdk_names()
    news = {r['new'] for r in rows}
    rx = re.compile(r'(?<![A-Za-z0-9_])(' + '|'.join(re.escape(n) for n in sorted(news, key=len, reverse=True)) + r')(?![A-Za-z0-9_])') if news else None
    seen = collections.defaultdict(list)   # new -> [(file, header, masked)]
    if rx:
        for p in files:
            t = texts[p]
            if rx.search(t):
                masked = MASK.sub(blank, t)
                hdr = parse_header(t)
                for n in set(m.group(1) for m in rx.finditer(t)):
                    seen[n].append((p, hdr, masked))
    bad = {}
    for i, r in enumerate(rows):
        why = []
        tgt = (r['region'], r['address'])
        for key in man.get(r['new'], ()):
            if key != tgt:
                why.append('manifest entry %s at %s 0x%08X' % (r['new'], key[0], key[1]))
        for key in sdk.get(r['new'], ()):
            if key[1] != r['address']:
                why.append('symbols_sdk.json row at %s 0x%08X' % key)
        for p, hdr, masked in seen.get(r['new'], ()):
            a = hdr['rows'].get(r['new'])
            if a is not None and a != r['address']:
                why.append('%s: symbols row at 0x%08X' % (rel(p), a))
            if hdr['function'] == [r['new']] and hdr['address'] not in (None, r['address']):
                why.append('%s: defines it at 0x%08X' % (rel(p), hdr['address']))
            elif (defines(masked, r['new']) and tgt not in man.get(r['new'], ())
                  and tgt not in sdk.get(r['new'], ())
                  and not (hdr['function'] == [r['new']] and hdr['address'] == r['address'])):
                why.append('%s: defines a function of that name' % rel(p))
            if non_function_use(masked, r['new']):
                why.append('%s: used as a type, variable or field' % rel(p))
        if why:
            bad[i] = sorted(set(why))
    return bad


def add_row(text, name, addr, isa, region, file_region):
    """Text with a `symbols:` row for name added to the header."""
    hs = header_span(text)
    if not hs:
        return text
    nl = '\r\n' if '\r\n' in text else '\n'
    tok = '' if file_region == region else '  ' + region
    row = ' *   %s  0x%08X  %s%s' % (name, addr, isa, tok)
    head = text[hs[0]:hs[1]]
    lines = head.split(nl)
    opened = None
    last = None
    for k, line in enumerate(lines):
        if SYMBOLS_OPEN.match(line):
            opened = k
            last = k
        elif opened is not None and SYM_ROW.match(line):
            last = k
        elif opened is not None and last is not None and k > opened:
            if line.strip() not in ('*',) and not SYM_ROW.match(line):
                break
    if opened is not None:
        lines.insert(last + 1, row)
    else:
        # before the closing line of the comment
        close = len(lines) - 1
        if lines[close].strip() == '*/':
            lines[close:close] = [' *', ' * symbols:', row]
        else:
            return text
    return text[:hs[0]] + nl.join(lines) + text[hs[1]:]


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--map')
    ap.add_argument('--build-twl', metavar='TSV')
    ap.add_argument('--out')
    ap.add_argument('--roots', nargs='+', default=['src/game', 'src/matched'])
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('--no-rows', action='store_true', help='do not add symbols: rows')
    ap.add_argument('--changed', help='write the list of changed files here')
    ap.add_argument('--no-scope', action='store_true',
                    help='apply every row to every file (no address scoping of vendor-style old names)')
    ap.add_argument('--local-ok', action='store_true',
                    help='let rows noted bind:local through when the name only exists at other addresses, and make them static')
    a = ap.parse_args()
    if a.build_twl:
        build_twl(a.build_twl, a.out or 'sdkrename_map.tsv')
        return
    if not a.map:
        ap.error('--map or --build-twl')
    rows = read_map(a.map)
    files = list(source_files(a.roots))
    texts = {p: open(p, encoding='latin1', newline='').read() for p in files}
    manifests = load_manifests()

    scopes = {} if a.no_scope else scope_files(rows, files, texts)
    olds = collections.Counter(r['old'] for i, r in enumerate(rows) if i not in scopes)
    olds_at = collections.Counter((r['old'], r['address']) for r in rows)
    newc = collections.Counter(r['new'] for r in rows)
    bad = check_conflicts(rows, files, texts, manifests)
    for i, r in enumerate(rows):
        if olds[r['old']] > 1 or olds_at[(r['old'], r['address'])] > 1:
            bad.setdefault(i, []).append('old name twice in the map')
        if newc[r['new']] > 1:
            bad.setdefault(i, []).append('new name twice in the map')
    for i in scopes:
        if not scopes[i]:
            bad.setdefault(i, []).append('no file means %s at this address' % rows[i]['old'])
    statics = local_ok(rows, bad, files, texts, scopes) if a.local_ok else {}
    for i in sorted(bad):
        r = rows[i]
        print('REFUSED %s -> %s (0x%08X): %s' % (r['old'], r['new'], r['address'], '; '.join(bad[i])))
    good = [r for i, r in enumerate(rows) if i not in bad]

    changed = {}
    per_row = collections.Counter()
    both = []
    good_i = [i for i in range(len(rows)) if i not in bad]
    glob_rows = [rows[i] for i in good_i if i not in scopes]
    in_scope = collections.defaultdict(list)       # file -> scoped rows for it
    for i in good_i:
        for p in scopes.get(i, ()):
            in_scope[os.path.normpath(p)].append(rows[i])
    for p in files:
        file_rows = glob_rows + in_scope.get(os.path.normpath(p), [])
        if not file_rows:
            continue
        t = texts[p]
        rx = re.compile(r'(?<![A-Za-z0-9_])(' + '|'.join(re.escape(r['old']) for r in file_rows) + r')(?![A-Za-z0-9_])')
        by_old = {r['old']: r for r in file_rows}
        if not rx.search(t):
            continue
        hit = sorted(set(m.group(1) for m in rx.finditer(t)))
        masked_t = MASK.sub(blank, t)
        for o in hit:
            if word(by_old[o]['new']).search(masked_t):
                # the file already knows the function under its new name
                both.append((rel(p), o, by_old[o]['new']))
        new_t = rx.sub(lambda m: by_old[m.group(1)]['new'], t)
        hdr = parse_header(new_t)
        if not a.no_rows and hdr['rows'] is not None:
            masked = MASK.sub(blank, new_t)
            fr = hdr['region'] or ''
            for o in hit:
                r = by_old[o]
                n = r['new']
                if n in hdr['rows'] or n in hdr['function'] or defines(masked, n):
                    continue
                if not word(n).search(masked):
                    continue     # only in comments
                new_t = add_row(new_t, n, r['address'], r['isa'], r['region'], fr)
                hdr = parse_header(new_t)
        for i, defs in statics.items():
            if p in defs:
                new_t = make_static(new_t, rows[i]['new'])
        for o in hit:
            per_row[(o, by_old[o]['address'])] += 1
        if new_t != t:
            changed[p] = new_t

    # manifests
    man_changed = {}
    at = {(r['old'], r['address']): r for r in good}
    glob_old = {r['old']: r for r in glob_rows}
    for p, d in manifests:
        ch = False
        for e in d.get('functions', []):
            try:
                r = at.get((e.get('name'), int(str(e['address']), 16)))
            except (KeyError, ValueError):
                r = None
            if r:
                e['name'] = r['new']
                ch = True
            if 'functions' in e:
                unit_old = dict(glob_old)
                for r in in_scope.get(os.path.normpath(os.path.join(ROOT, e.get('source', ''))), ()):
                    unit_old[r['old']] = r
                fl = [unit_old[x]['new'] if x in unit_old else x for x in e['functions']]
                if fl != e['functions']:
                    # record each member's address before its name loses it, so the
                    # counting tools still place it (tools/fnaddr.py); an `addresses`
                    # list already there stays, parallel to the renamed list
                    if (str(e.get('kind', '')).endswith('_unit')
                            and len(e.get('addresses') or []) != len(e['functions'])):
                        got = fnaddr.member_addresses(e)
                        if all(x is not None for _n, x in got):
                            e['addresses'] = ['0x%08X' % x for _n, x in got]
                    e['functions'] = fl
                    ch = True
        if ch:
            man_changed[p] = d

    for f, o, n in both:
        print('NOTE %s holds both %s and %s (now one name; check for a doubled declaration)' % (f, o, n))
    print('rows: %d applied, %d refused' % (len(good), len(bad)))
    print('files: %d source, %d manifest' % (len(changed), len(man_changed)))
    unused = ['%s@%08X' % (r['old'], r['address']) for r in good if not per_row[(r['old'], r['address'])]]
    if unused:
        print('rows with no occurrence: %s' % ', '.join(unused))
    if a.changed:
        with open(a.changed, 'w', encoding='utf-8') as fh:
            for p in sorted(changed) + sorted(man_changed):
                fh.write(rel(p) + '\n')
    if not a.apply:
        for p in sorted(changed):
            print('  would change %s' % rel(p))
        for p in sorted(man_changed):
            print('  would change %s' % rel(p))
        return
    for p, t in changed.items():
        with open(p, 'w', encoding='latin1', newline='') as fh:
            fh.write(t)
    for p, d in man_changed.items():
        raw = open(p, encoding='utf-8', newline='').read()
        nl = '\r\n' if '\r\n' in raw else '\n'
        ind = 1 if re.search(r'^ "', raw, re.M) else 2
        s = json.dumps(d, indent=ind, ensure_ascii=False)
        with open(p, 'w', encoding='utf-8', newline='') as fh:
            fh.write(s.replace('\n', nl) + (nl if raw.endswith(('\n',)) else ''))
    print('written.')


if __name__ == '__main__':
    main()
