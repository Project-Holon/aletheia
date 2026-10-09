#!/usr/bin/env python3
"""gamesyms.py: keep the `symbols:` blocks of the merged src/game files whole.

match.py resolves a relocation only through a name in the header `symbols:`
block (or an address-bearing name).  A merged file that lost rows compares as
MATCH (relocations wildcarded) instead of EXACT.  This tool

  1. lints every block: each line between `symbols:` and the end of the header
     must parse with match.SYMBOL_RE (a prose line or a bad kind such as
     `code` hides every row after it);
  2. compiles the TU and, for each unresolved site whose name has no row, takes
     the row from the src/matched member files that hold the TU's functions.

--apply writes the fixes: `code` kinds become thumb|arm (listing label, else
the members' own row), prose lines move to just above `symbols:`, missing rows
are appended.  A file keeps its change only if its verdict is equal or better
(EXACT > MATCH; DIFF or worse is never accepted); otherwise it is restored.
Rows come only from the members' headers or from fixing an unparseable kind.

usage
  python tools/gamesyms.py [--region R] [--file F] [--apply] [--lint-only] [--all]

Without --all, a file is compiled only if its header status is not EXACT or its
lint found a problem (an EXACT header means every site already resolved).
"""
import argparse
import collections
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import match  # noqa: E402
import protofix as pf  # noqa: E402
import restructure as rs  # noqa: E402

# match.SYMBOL_SHAPE_RE ends in a backspace (a non-raw ), so it never matches;
# the lint keeps its own copy of the intended pattern.
SHAPE_RE = re.compile(r"^\s*\*\s+([A-Za-z_][A-Za-z0-9_]*|@[0-9]+|\.bss)\s+0[xX][0-9A-Fa-f]+")
RANK = {'EXACT': 2, 'MATCH': 1}
_MATCHED_INDEX = None
_SHARDS = None


# ---------------------------------------------------------------------------
# lint
# ---------------------------------------------------------------------------

def split_header(raw):
    """-> (lines, open_idx, close_idx): the header comment lines, the index of
    the `symbols:` line (or None) and of the closing `*/`."""
    lines = raw.split('\n')
    open_i = close_i = None
    for i, l in enumerate(lines):
        if close_i is None and open_i is None and match.SYMBOLS_OPEN_RE.match(l):
            open_i = i
        if l.lstrip().startswith('*/'):
            close_i = i
            break
    return lines, open_i, close_i


def row_like(l):
    """A line that is meant as a symbols row: name, address, a kind word."""
    if match.SYMBOL_RE.match(l):
        return True
    m = SHAPE_RE.match(l)
    if not m:
        return False
    rest = l.split()
    return len(rest) >= 4 and rest[3].lower() in ('thumb', 'arm', 'data', 'code')


def lint(raw):
    """-> list of (line, why) for every unparseable line in the symbols block.

    The block runs from `symbols:` to its last row-like line; match.read_header
    stops at the first line that is not a row, so a prose line, a blank ` *`
    line or a bad kind (`code`) before the last row hides every row after it.
    Prose after the last row is outside the block and is not reported."""
    lines, o, c = split_header(raw)
    if o is None or c is None:
        return []
    body = lines[o + 1:c]
    last_row = max((i for i, l in enumerate(body) if row_like(l)), default=-1)
    bad = []
    for i, l in enumerate(body[:last_row + 1]):
        if match.SYMBOL_RE.match(l):
            continue
        if not l.strip() or l.strip() == '*':
            bad.append((l, 'blank line before a later row'))
        elif row_like(l):
            bad.append((l, 'row the parser rejects'))
        else:
            bad.append((l, 'prose in the block'))
    return bad


def rewrite_block(raw, region):
    """Fix the block text: `code` kinds, prose moved above `symbols:`, blank
    lines inside the block dropped; text after the last row stays after it.
    -> (new raw, rows fixed, unfixable lines)."""
    lines, o, c = split_header(raw)
    if o is None or c is None:
        return raw, 0, []
    body = lines[o + 1:c]
    last_row = max((i for i, l in enumerate(body) if row_like(l)), default=-1)
    inner, tail = body[:last_row + 1], body[last_row + 1:]
    rows_raw = [l for l in inner if row_like(l)]
    prose = [l for l in inner if l.strip() and l.strip() != '*' and not row_like(l)]
    rows, fixed, left = [], 0, []
    for l in rows_raw:
        if match.SYMBOL_RE.match(l):
            rows.append(l)
            continue
        text = l.strip()[1:].strip()
        fb = [x.strip()[1:].strip() for x in rows_raw if x.split()[:1] == l.split()[:1]]
        new, why = rs.fix_symbol_row(text, region, fb)
        if new is None:
            left.append(l)
            rows.append(l)
        else:
            rows.append(' *   ' + new)
            fixed += 1
    # prose goes above `symbols:`, after the separator line that precedes it
    out = lines[:o] + prose + lines[o:o + 1] + rows + tail + lines[c:]
    return chr(10).join(out), fixed, left


# ---------------------------------------------------------------------------
# members
# ---------------------------------------------------------------------------

def matched_index():
    global _MATCHED_INDEX
    if _MATCHED_INDEX is None:
        idx = collections.defaultdict(list)
        for dp, _dn, fn in os.walk(os.path.join(ROOT, 'src', 'matched')):
            for f in fn:
                if f.endswith('.c'):
                    idx[f[:-2]].append(os.path.join(dp, f))
        _MATCHED_INDEX = idx
    return _MATCHED_INDEX


def member_files(funcs, region):
    """Paths of the src/matched files that define the TU's functions."""
    idx = matched_index()
    out = []
    for fn in funcs:
        cands = list(idx.get(fn, []))
        if not cands:
            for stem, paths in idx.items():
                if stem.endswith('_' + fn):
                    cands += paths
        if not cands:
            m = re.search(r'([0-9A-Fa-f]{8})$', fn)
            if m:
                global _SHARDS
                if _SHARDS is None:
                    _SHARDS = rs.shard_index()
                hit = _SHARDS.get((region, int(m.group(1), 16)))
                if hit and hit[0]:
                    cands = [os.path.join(ROOT, hit[0])]
        if len(cands) > 1:
            same = []
            for p in cands:
                try:
                    h = rs.header_fields(open(p, encoding='latin1').read())
                except OSError:
                    continue
                if (h.get('region') or '').strip() == region:
                    same.append(p)
            cands = same or cands
        for p in cands[:1]:
            if p not in out:
                out.append(p)
    return out


def header_rows(path, region):
    """Rows of a member's header comment, kind fixed -> list of row strings."""
    raw = open(path, encoding='latin1').read().replace('\r\n', '\n')
    hm = re.match(r'\s*/\*.*?\*/', raw, re.S)
    if not hm:
        return []
    rows = []
    raws = re.findall(r'^\s*\*\s+(\S+\s+0x[0-9A-Fa-f]+\s+\w+(?:\s+\w+)*)\s*$', hm.group(0), re.M)
    for r in raws:
        fb = [x for x in raws if x.split()[0] == r.split()[0]]
        new, _why = rs.fix_symbol_row(r, region, fb)
        if new:
            rows.append(new)
    return rows


def find_rows(name, members, region):
    """-> (row or None, why).  All members' rows for the name must agree."""
    got = collections.OrderedDict()
    for p in members:
        for r in header_rows(p, region):
            if r.split()[0] == name:
                key = tuple(t.lower() if i == 1 else t for i, t in enumerate(r.split()))
                got.setdefault(key, r)
    if not got:
        return None, 'no member row'
    if len(got) > 1:
        return None, 'members disagree: ' + ' | '.join(got.values())
    return next(iter(got.values())), ''


# ---------------------------------------------------------------------------
# compile
# ---------------------------------------------------------------------------

def compile_sites(path, raw):
    """-> (rank, verdict text, unresolved site list of (name, reason))."""
    import gameverify as gv
    h, st = gv.settings_of(raw)
    addr = int(h.get('address', '0'), 16)
    reg = (h.get('region') or '').strip()
    v = rs.verify(path, reg, addr, st)
    key = st['lang'] or 'nolang'
    stat = v.get(key, '')
    rank = RANK.get(stat.split()[0].rstrip('*:'), 0) if stat else 0
    sites = []
    try:
        r, _tl = match.run_tu(path, addr, st['compiler'], st['flags'].split(), st['isa'] == 'thumb',
                              st['lang'] or None, region=reg)
        for s in (getattr(r.func, 'sites', None) or []):
            if not s.resolved:
                sites.append((s.name, s.reason or ''))
    except (Exception, SystemExit) as e:
        sites.append(('?', 'run_tu failed: %r' % (e,)))
    return rank, stat[:80], sites


def add_rows(raw, rows):
    lines, o, c = split_header(raw)
    if c is None:
        return raw
    if o is None:
        add = [' *', ' * symbols:'] + [' *   ' + r for r in rows]
        return '\n'.join(lines[:c] + add + lines[c:])
    end = o + 1
    while end < c and match.SYMBOL_RE.match(lines[end]):
        end += 1
    return '\n'.join(lines[:end] + [' *   ' + r for r in rows] + lines[end:])


def cause(name, why):
    if why.startswith('members disagree'):
        return 'members disagree'
    if why == 'no member row':
        if name in ('.bss', '.data'):
            return 'section symbol %s: no member row' % name
        if name.startswith('@'):
            return 'compiler template @N: no member row'
        return 'name has no row in any member header'
    m = re.search(r'\((thumb|arm|data), from', why)
    if 'no witness outside' in why and m:
        return 'no outside witness: ' + m.group(1)
    if 'vendor object does not relocate' in why or 'lands in no declared static' in why:
        return 'file static (.bss/.data) slot'
    return why[:60]


def process(path, a, stats):
    rel = os.path.relpath(path, ROOT).replace(os.sep, '/')
    raw0 = open(path, encoding='latin1', newline='').read()
    crlf = '\r\n' in raw0
    raw = raw0.replace('\r\n', '\n')
    h = pf.parse_header(raw)
    region = (h.get('region') or '').strip()
    status = (h.get('status') or '').strip()
    bad = lint(raw)
    funcs = [f.strip() for f in (h.get('function') or '').split(',') if f.strip()]
    if not bad and status.startswith('EXACT') and not a.all:
        return
    msg = []
    new = raw
    fixed = 0
    left = []
    if bad:
        msg.append('lint %d bad' % len(bad))
        stats['bad_lines'] += len(bad)
        if a.verbose:
            for l, why in bad:
                msg.append('  [%s] %s' % (why, l.strip()))
        new, fixed, left = rewrite_block(raw, region)
        if left:
            msg.append('unfixable: ' + '; '.join(l.strip() for l in left))
        # prose that stays above `symbols:` can not be a row; a remaining bad line is a failure
    if a.lint_only:
        if msg:
            print('%s: %s' % (rel, ' '.join(msg)))
        return
    # compile the (possibly lint-fixed) text to find unresolved sites
    tmp = path + '.gamesyms.tmp.c'
    added = []
    unresolved = []
    try:
        base_rank, base_stat, base_sites = compile_sites(path, raw)
        if new == raw:
            rank, stat, sites = base_rank, base_stat, base_sites
        else:
            with open(tmp, 'w', encoding='latin1', newline='') as f:
                f.write(new)
            rank, stat, sites = compile_sites(tmp, new)
        members = None
        seen = set()
        for name, reason in sites:
            if name in seen:
                continue
            seen.add(name)
            if 'no address for' not in reason:
                unresolved.append((name, reason[:90]))
                continue
            if members is None:
                members = member_files(funcs, region)
            row, why = find_rows(name, members, region)
            if row is None:
                unresolved.append((name, why))
            else:
                added.append(row)
        if added:
            new2 = add_rows(new, added)
            with open(tmp, 'w', encoding='latin1', newline='') as f:
                f.write(new2)
            rank2, stat2, sites2 = compile_sites(tmp, new2)
            new, rank, stat = new2, rank2, stat2
            unresolved = [(n, r[:90]) for n, r in sites2]
    finally:
        try:
            os.remove(tmp)
        except OSError:
            pass
    if rank == 2 and re.search(r'^ \* status:\s+MATCH\s*$', new, re.M):
        new = re.sub(r'^( \* status:\s+)MATCH\s*$', r'\g<1>EXACT', new, count=1, flags=re.M)
        msg.append('status line MATCH -> EXACT')
    changed = new != raw
    keep = changed and rank >= base_rank and a.apply
    msg.append('verdict %s -> %s' % (base_stat.split(':')[0], stat.split(':')[0]))
    if added:
        msg.append('added %d' % len(added))
    if fixed:
        msg.append('fixed %d' % fixed)
    if changed and a.apply and not keep:
        msg.append('REVERTED (worse)')
    if keep:
        with open(path + '.gamesyms.bak', 'w', encoding='latin1', newline='') as f:
            f.write(raw0)
        out = new.replace('\n', '\r\n') if crlf else new
        with open(path, 'w', encoding='latin1', newline='') as f:
            f.write(out)
        os.remove(path + '.gamesyms.bak')
        if rank > base_rank:
            msg.append('now EXACT')
            stats['to_exact'] += 1
        stats['files_changed'] += 1
        stats['rows_fixed'] += fixed
        stats['rows_added'] += len(added)
    elif changed:
        stats['would_change'] += 1
        stats['rows_fixed'] += fixed
        stats['rows_added'] += len(added)
    for n, why in unresolved:
        stats['unresolved'][cause(n, why)] += 1
    if unresolved:
        msg.append('unresolved %d: %s' % (len(unresolved), '; '.join('%s (%s)' % u for u in unresolved[:6])))
    print('%s: %s' % (rel, ' | '.join(msg)), flush=True)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--tree', default=os.path.join(ROOT, 'src', 'game'))
    ap.add_argument('--region')
    ap.add_argument('--file', action='append')
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('--lint-only', action='store_true')
    ap.add_argument('--all', action='store_true', help='compile files whose header status is EXACT too')
    ap.add_argument('--verbose', action='store_true')
    a = ap.parse_args()
    files = []
    if a.file:
        files = [os.path.abspath(f) for f in a.file]
    else:
        for dp, _dn, fn in os.walk(a.tree):
            rg = os.path.relpath(dp, a.tree).split(os.sep)[0]
            if a.region and rg != a.region:
                continue
            files += [os.path.join(dp, f) for f in fn if f.endswith('.c') and not f.startswith('_')]
    stats = collections.Counter()
    stats['unresolved'] = collections.Counter()
    for p in sorted(files):
        process(p, a, stats)
    print('files with bad lines: lines %d' % stats['bad_lines'])
    print('files changed %d, rows fixed %d, rows added %d, became EXACT %d, would change %d'
          % (stats['files_changed'], stats['rows_fixed'], stats['rows_added'], stats['to_exact'],
             stats['would_change']))
    for k, n in stats['unresolved'].most_common():
        print('  unresolved %5d  %s' % (n, k))


if __name__ == '__main__':
    main()
