#!/usr/bin/env python3
"""renamefile.py: rename and merge src/game .c files in one safe step, keeping
every reference in sync.

usage
  python tools/renamefile.py TABLE.tsv [--dry-run | --apply] [--verify] [--link]
                             [--skip-failed] [--log FILE] [--emit-reverse FILE] [--allow-unit-names]
                             [--scan PATH ...]

TABLE.tsv: one row per old file, tab separated: old path, new path[, note].
Paths are src/game/<dir>/<file>.c or <dir>/<file>.c.  Lines starting with # and
blank lines are ignored.  A header row (first cell "old") is ignored.

  * Several old paths with one new path are a MERGE.  The old files must be
    consecutive in the address order of their directory (no other top-level
    file lies between them).  They merge in address order through
    restructure.merge (union of the header function list and symbols rows,
    identical prelude declarations once, include order of the first file),
    then the header status line and the header notes of all members are kept.
    A conflicting type or declaration, or members whose compile settings differ,
    fails the group; nothing of that group is written.
  * <stem>_types.h next to an old .c follows it to <newstem>_types.h.  Two
    headers of one merge group merge the same way (items deduplicated, include
    guard rebuilt); two different definitions of one type fail the group.
  * Other companions named <stem>.<ext> (.zdata.c, .zpre.c, ...) are renamed with a
    1:1 rename and make a merge group fail (merge them by hand first).
  * The new name must be snake_case (a-z, 0-9, _) ending in .c (or the real name,
    with its case, of an SDK/vendor object in layout/symbols_sdk.json), in the same
    directory as the old file, and must not exist unless it is one of the group's
    own old files.  Old files must be under src/game.  Plain file operations.

Updated references
  * #include "..." lines in every .c/.h/.inc/.md under src/ that resolve to a
    renamed header, rewritten relative to the including file (so "../ovNNN/x.h"
    forms follow).
  * the `file:` line of each moved .c, and the include guard of each moved header.
  * bare mentions of an old unit_XXXXXXXX stem (comments, MERGE.md, ...) in the
    files of the same directory tree src/game/<dir>/ (`unit_X`, `unit_X.c`,
    `unit_X_types.h`; `unit_X_p02` is left alone).
  * full paths src/game/<dir>/<old> in layout/ (not layout/matched), docs/restructure/
    and any --scan PATH (file or directory): gamegaps.tsv, json, txt, md.
  tools/ (gamecheck, gameverify, gamelink, linkstats, coveragemap) scan the
  directories, so they need no edit.
Not handled (reported at the end): old stems left in other files (tools/*.py
comments, docs/*.md, docs/idioms, other regions' comments), progress/report.json
(regenerate with tools/progress_report.py), datagen output (datalink.json is
keyed by stem: re-run tools/datagen.py), `<dir>/<stem>.c` forms without src/game.

--verify runs gameverify --file for each new .c and gamecheck --region for each
touched directory after --apply (--link also runs gamelink for them).
--emit-reverse FILE writes the table that undoes the 1:1 renames (merges cannot
be undone).  Run it while no lane edits the touched files.
"""
import argparse
import collections
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
GAME = 'src/game'
NAME_RE = re.compile(r'^[a-z][a-z0-9]*(?:_[a-z0-9]+)*\.c$')
UNIT_RE = re.compile(r'^unit_[0-9A-F]{8}$')
_SDK_STEMS = []


def sdk_object_stems():
    """Object stems of the SDK/vendor objects (layout/symbols_sdk.txt and
    layout/sdk_class.json): such a file keeps the object's real name and case
    (os_spinLock.c), the way the original SDK source file was called."""
    if not _SDK_STEMS:
        import json
        st = set()
        try:
            for line in open(os.path.join(ROOT, 'layout', 'symbols_sdk.txt'), encoding='utf-8'):
                m = re.search(r'\(([^()]+)\.o\)', line)
                if m:
                    st.add(m.group(1))
        except OSError:
            pass
        try:
            d = json.load(open(os.path.join(ROOT, 'layout', 'sdk_class.json'), encoding='utf-8'))
            for reg in d.get('regions', {}).values():
                for e in reg.values():
                    m = e.get('member')
                    if m and m.endswith('.o'):
                        st.add(m[:-2])
        except (OSError, ValueError):
            pass
        _SDK_STEMS.append(st)
    return _SDK_STEMS[0]


ENC = 'latin1'
ALLOW_UNIT = [False]        # --allow-unit-names: a unit_XXXXXXXX.c target (undoing a rename)
TEXT_EXT = ('.c', '.h', '.inc', '.md')
KEY_LINE = re.compile(r'^\s*\*\s*(file|unit|function|address|packet|region|compiler|flags|lang|isa|status):')


def rd(rel):
    with open(os.path.join(ROOT, rel), encoding=ENC, newline='') as f:
        return f.read()


def wr(rel, text):
    p = os.path.join(ROOT, rel)
    os.makedirs(os.path.dirname(p), exist_ok=True)
    with open(p, 'w', encoding=ENC, newline='') as f:
        f.write(text)


def norm(p):
    p = p.strip().replace('\\', '/')
    if os.path.isabs(p):
        p = os.path.relpath(p, ROOT).replace(os.sep, '/')
    p = os.path.normpath(p).replace(os.sep, '/')
    if not p.startswith('src/'):
        p = GAME + '/' + p
    return p


def read_table(path):
    rows = []
    with open(path, encoding='utf-8') as f:
        for ln, line in enumerate(f, 1):
            line = line.rstrip('\r\n')
            if not line.strip() or line.lstrip().startswith('#'):
                continue
            cells = line.split('\t')
            if ln == 1 and cells[0].strip().lower() in ('old', 'old path'):
                continue
            if len(cells) < 2:
                sys.exit('%s:%d: need old path and new path' % (path, ln))
            rows.append((cells[0], cells[1], ln))
    return rows


def header_of(text):
    m = re.match(r'\s*/\*.*?\*/', text, re.S)
    return m.group(0) if m else ''


def header_field(text, key):
    m = re.search(r'^\s*\*\s*%s:\s*(.*?)\s*$' % key, header_of(text), re.M)
    return m.group(1) if m else ''


def header_address(text):
    try:
        return int(header_field(text, 'address').split()[0], 16)
    except (ValueError, IndexError):
        return 0


def stem_of(rel):
    return os.path.basename(rel)[:-2]


def top_files(d):
    out = []
    full = os.path.join(ROOT, d)
    for f in os.listdir(full):
        if f.endswith('.c') and not f.startswith('_') and os.path.isfile(os.path.join(full, f)):
            out.append(d + '/' + f)
    return out


def companions(rel):
    """Files next to rel named <stem>.<ext> (not rel itself) and <stem>_types.h."""
    d, f = os.path.dirname(rel), os.path.basename(rel)
    stem = f[:-2]
    out = {'types': None, 'other': []}
    for g in os.listdir(os.path.join(ROOT, d)):
        if g == f:
            continue
        if g == stem + '_types.h':
            out['types'] = d + '/' + g
        elif g.startswith(stem + '.') and os.path.isfile(os.path.join(ROOT, d, g)):
            out['other'].append(d + '/' + g)
    return out


# ---------------------------------------------------------------------------
# header (.h) merge
# ---------------------------------------------------------------------------

def strip_guard(text):
    """(guard name or None, body) of a header text."""
    t = text.replace('\r\n', '\n')
    m = re.search(r'^#ifndef\s+(\w+)[ \t]*\n#define\s+\1\b[^\n]*\n', t, re.M)
    if not m:
        return None, t
    pre = t[:m.start()]
    ends = [x.start() for x in re.finditer(r'^#endif\b[^\n]*$', t, re.M)]
    tail = t[ends[-1]:] if ends else ''
    body = t[m.end():ends[-1]] if ends else t[m.end():]
    del tail
    return m.group(1), pre + body


def merge_headers(texts, new_guard):
    import restructure as rs
    problems = []
    includes, inc_seen = [], set()
    out, seen, keyed = [], set(), {}
    for rel, text in texts:
        _g, body = strip_guard(text)
        items = rs.split_items('\n#define RNFT_SENTINEL 1\n' + body)[1:]
        for it in items:
            if it.kind == 'include':
                if it.key not in inc_seen:
                    inc_seen.add(it.key)
                    includes.append(it.text.strip() + '\n')
                continue
            if it.kind == 'blank':
                continue
            k = it.norm if it.norm else it.text.strip()
            if it.kind == 'pp' and re.match(r'#\s*(if|ifdef|ifndef|else|elif|endif)\b', k):
                out.append(it.text.strip('\n') + '\n')     # conditional lines keep their pairing
                continue
            if not k or k in seen:
                continue
            seen.add(k)
            key = None
            if it.kind in ('type', 'proto', 'data'):
                key = (it.kind, it.key)
            elif it.kind == 'pp':
                dm = re.match(r'\s*#\s*define\s+(\w+)', re.sub(r'/\*.*?\*/', '', it.text, flags=re.S).strip() or it.text)
                if dm:
                    key = ('define', dm.group(1))
            if key is not None:
                prev = keyed.get(key)
                if prev is not None and prev[0] != it.norm:
                    problems.append('%s %s defined differently (%s vs %s)' % (key[0], key[1], prev[1], rel))
                    continue
                keyed[key] = (it.norm, rel)
            out.append(it.text.strip('\n') + '\n')
    text = '#ifndef %s\n#define %s\n' % (new_guard, new_guard)
    if includes:
        text += ''.join(includes) + '\n'
    text += '\n'.join(out) + '\n#endif\n'
    return text, problems


# ---------------------------------------------------------------------------
# planning
# ---------------------------------------------------------------------------

class Group:
    def __init__(self, new, olds):
        self.new, self.olds = new, olds
        self.problems = []
        self.text = None            # new .c text (merge) or None
        self.htext = None           # new header text if headers merge
        self.hold = []              # old header paths
        self.hnew = None
        self.comp = []              # [(old, new)] other companion renames


def build_groups(rows):
    errs = []
    groups = collections.OrderedDict()
    seen_old = {}
    selfrows = {}
    for old, new, ln in rows:
        o, n = norm(old), norm(new)
        if o in seen_old:
            errs.append('line %d: %s listed twice' % (ln, o))
            continue
        seen_old[o] = n
        if not o.startswith(GAME + '/') or not n.startswith(GAME + '/'):
            errs.append('line %d: %s -> %s: only files under %s can be renamed' % (ln, o, n, GAME))
            continue
        if not o.endswith('.c') or not n.endswith('.c'):
            errs.append('line %d: only .c files (%s -> %s)' % (ln, o, n))
            continue
        if not os.path.isfile(os.path.join(ROOT, o)):
            errs.append('line %d: %s does not exist' % (ln, o))
            continue
        if os.path.dirname(o) == GAME or os.path.dirname(o) == os.path.dirname(GAME):
            errs.append('line %d: %s is not inside a src/game/<dir>' % (ln, o))
            continue
        if os.path.dirname(o) != os.path.dirname(n):
            errs.append('line %d: %s -> %s: the new file must stay in the same directory' % (ln, o, n))
            continue
        if not NAME_RE.match(os.path.basename(n)) and not (ALLOW_UNIT[0] and UNIT_RE.match(stem_of(n)))                 and not (os.path.basename(n).endswith('.c') and stem_of(n).lower() in {x.lower() for x in sdk_object_stems()}):
            errs.append('line %d: %s is not a snake_case .c name' % (ln, os.path.basename(n)))
            continue
        if o == n:
            selfrows[o] = ln        # an existing file that takes in the other members of its group
        groups.setdefault(n, Group(n, [])).olds.append(o)
    for o, ln in selfrows.items():
        if len(groups[o].olds) < 2:
            errs.append('line %d: %s maps to itself' % (ln, o))
    all_old = set(seen_old)
    for n, g in groups.items():
        if os.path.exists(os.path.join(ROOT, n)) and n not in g.olds:
            errs.append('%s already exists (not part of its own group)' % n)
        elif n in all_old and n not in g.olds:
            errs.append('%s is also an old file of another row' % n)
        for o in g.olds:
            if os.path.isdir(os.path.join(ROOT, o[:-2])):
                errs.append('%s: a folder %s/ exists next to it (not supported)' % (o, stem_of(o)))
    return list(groups.values()), errs


def check_contiguous(g):
    if len(g.olds) < 2:
        return
    d = os.path.dirname(g.olds[0])
    adr = {}
    for p in top_files(d):
        a = header_address(rd(p))
        adr[p] = a
    bad = [o for o in g.olds if not adr.get(o)]
    if bad:
        g.problems.append('merge member without a header address: %s' % ', '.join(bad))
        return
    order = sorted(adr, key=lambda p: (adr[p], p))
    idx = sorted(order.index(o) for o in g.olds)
    if idx != list(range(idx[0], idx[0] + len(idx))):
        between = [order[i] for i in range(idx[0], idx[-1] + 1) if order[i] not in g.olds]
        g.problems.append('non-contiguous merge: %s lie between the members' % ', '.join(between))
    g.olds.sort(key=lambda p: (adr[p], p))


def note_lines(text):
    """Free-text lines of the header comment (no key lines, symbols, Merged by line)."""
    hd = header_of(text)
    out, in_sym = [], False
    for line in hd.split('\n')[1:-1] if hd else []:
        if re.match(r'^\s*\*\s*symbols:\s*$', line):
            in_sym = True
            continue
        if in_sym:
            if re.match(r'^\s*\*\s+\S+\s+0x[0-9A-Fa-f]{8}\b', line) or re.match(r'^\s*\*\s*$', line):
                continue
            in_sym = False
        if KEY_LINE.match(line) or re.match(r'^\s*\*\s*$', line) or 'Merged by tools/restructure.py' in line:
            continue
        out.append(line.rstrip())
    return out


def plan_merge(g, hmap):
    import restructure as rs
    texts = [rd(o) for o in g.olds]
    d = os.path.dirname(g.new)
    region = header_field(texts[0], 'region') or os.path.basename(d)
    funcs, start = [], None
    for t in texts:
        for n in re.split(r'\s*,\s*', header_field(t, 'function')):
            if n and n not in funcs:
                funcs.append(n)
        a = header_address(t)
        start = a if start is None else min(start, a)
    out_dir = os.path.join(ROOT, d)
    text, problems, _settings, renamed = rs.merge(g.olds, os.path.basename(g.new), region, start, funcs, out_dir)
    for p in problems:
        g.problems.append(p)
    for r in renamed:
        print('note: %s: clashing local types renamed per member: %s' % (g.new, r))
    # status: the first member status that is not plain EXACT, else EXACT
    sts = [header_field(t, 'status') for t in texts]
    st = next((s for s in sts if s and s != 'EXACT'), 'EXACT')
    text = re.sub(r'^( \* status:\s+).*$', lambda m: m.group(1) + st, text, count=1, flags=re.M)
    # keep the free-text notes of every member
    notes = []
    for t in texts:
        for ln in note_lines(t):
            if ln not in notes:
                notes.append(ln)
    if notes:
        text = text.replace('\n */', '\n *\n' + '\n'.join(notes) + '\n */', 1) if ' * symbols:' not in text.split('*/', 1)[0] \
            else text.replace('\n *\n * symbols:', '\n *\n' + '\n'.join(notes) + '\n *\n * symbols:', 1)
    g.text = text


def plan_headers(g):
    heads = []
    for o in g.olds:
        c = companions(o)
        if c['types']:
            heads.append(c['types'])
        for x in c['other']:
            if len(g.olds) > 1:
                g.problems.append('%s has companion %s: merge it by hand first' % (o, x))
            else:
                g.comp.append((x, os.path.dirname(x) + '/' + os.path.basename(g.new)[:-2] + x[len(o) - 2:]))
    g.hold = heads
    if not heads:
        return
    g.hnew = os.path.dirname(g.new) + '/' + stem_of(g.new) + '_types.h'
    if os.path.exists(os.path.join(ROOT, g.hnew)) and g.hnew not in heads:
        g.problems.append('%s already exists' % g.hnew)
        return
    if len(heads) > 1:
        first_old_stem = stem_of(g.olds[0])
        gd, _b = strip_guard(rd(heads[0]))
        guard = gd.replace(first_old_stem.upper(), stem_of(g.new).upper()) if gd and first_old_stem.upper() in gd \
            else (gd or (os.path.basename(os.path.dirname(g.new)).upper() + '_' + stem_of(g.new).upper() + '_TYPES_H'))
        text, probs = merge_headers([(h, rd(h)) for h in heads], guard)
        g.htext = text
        for p in probs:
            g.problems.append('header merge: ' + p)


# ---------------------------------------------------------------------------
# reference rewriting
# ---------------------------------------------------------------------------

class Rewriter:
    def __init__(self, groups):
        self.hmap = {}          # old header rel -> new header rel
        self.fmap = {}          # old rel (any moved file) -> new rel
        self.stems = collections.defaultdict(dict)    # dir -> {old stem: new stem}
        for g in groups:
            for o in g.olds:
                self.fmap[o] = g.new
                if UNIT_RE.match(stem_of(o)):
                    self.stems[os.path.dirname(o)][stem_of(o)] = stem_of(g.new)
            for h in g.hold:
                self.hmap[h] = g.hnew
                self.fmap[h] = g.hnew
            for a, b in g.comp:
                self.fmap[a] = b
        self.pat = {}
        for d, m in self.stems.items():
            names = sorted(m, key=len, reverse=True)
            self.pat[d] = re.compile(r'(?<![A-Za-z0-9_])(%s)(_types)?(?![A-Za-z0-9_])' % '|'.join(map(re.escape, names)))
        self.inc_re = re.compile(r'(#[ \t]*include[ \t]*")([^"\n]+)(")')
        self.count = collections.Counter()

    def includes(self, text, here):
        """Rewrite includes of text, which lives at (old) path `here`."""
        d = os.path.dirname(here)

        def sub(m):
            inc = m.group(2)
            res = os.path.normpath(os.path.join(d, inc)).replace(os.sep, '/')
            new = self.hmap.get(res)
            if new is None:
                return m.group(0)
            dest = os.path.dirname(self.fmap.get(here, here))
            rel = os.path.relpath(new, dest).replace(os.sep, '/')
            self.count['include'] += 1
            return m.group(1) + rel + m.group(3)
        return self.inc_re.sub(sub, text)

    def bare(self, text, d):
        p = self.pat.get(d)
        if not p:
            return text

        def sub(m):
            self.count['bare'] += 1
            return self.stems[d][m.group(1)] + (m.group(2) or '')
        return p.sub(sub, text)

    def guard(self, text, old_stem, new_stem):
        ou, nu = old_stem.upper(), new_stem.upper()

        def sub(m):
            return m.group(0).replace(ou, nu)
        return re.sub(r'^(#\s*(?:ifndef|define|endif)\b[^\n]*)$',
                      lambda m: sub(m) if ou in m.group(0) else m.group(0), text, flags=re.M)

    def paths(self, text):
        """Full src/game/<dir>/<file> mentions (tables, json)."""
        n = 0
        for old, new in self.fmap.items():
            if old not in text:
                continue
            stem_o = os.path.basename(old)
            pre = os.path.dirname(old) + '/'
            pat = re.compile(re.escape(pre + stem_o) + r'(?![A-Za-z0-9_])')
            text, k = pat.subn(new, text)
            n += k
        self.count['path'] += n
        return text


def file_line(text, newname):
    return re.sub(r'^( \* file:\s+)\S+', lambda m: m.group(1) + newname, text, count=1, flags=re.M)


def all_text_files(roots):
    for r in roots:
        full = os.path.join(ROOT, r)
        if os.path.isfile(full):
            yield r
            continue
        for dp, dn, fn in os.walk(full):
            for f in fn:
                yield os.path.relpath(os.path.join(dp, f), ROOT).replace(os.sep, '/')


def main():
    ap = argparse.ArgumentParser(description='rename and merge src/game .c files (see the top of this file)')
    ap.add_argument('table')
    ap.add_argument('--dry-run', action='store_true')
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('--verify', action='store_true')
    ap.add_argument('--link', action='store_true')
    ap.add_argument('--skip-failed', action='store_true', help='apply the good groups, report the failed ones')
    ap.add_argument('--log')
    ap.add_argument('--emit-reverse')
    ap.add_argument('--allow-unit-names', action='store_true',
                    help='accept unit_XXXXXXXX.c as a new name (to undo a rename with the reverse table)')
    ap.add_argument('--scan', action='append', default=[])
    a = ap.parse_args()
    if a.apply == a.dry_run and not a.emit_reverse:
        sys.exit('give exactly one of --dry-run, --apply')

    ALLOW_UNIT[0] = a.allow_unit_names
    rows = read_table(a.table)
    if a.emit_reverse:
        cnt = collections.Counter(norm(n) for _o, n, _l in rows)
        with open(a.emit_reverse, 'w', encoding='utf-8', newline='\n') as f:
            for o, n, _l in rows:
                if cnt[norm(n)] == 1:
                    f.write('%s\t%s\n' % (norm(n), norm(o)))
                else:
                    f.write('# merged into %s, cannot be undone: %s\n' % (norm(n), norm(o)))
        print('reverse table written to', a.emit_reverse)
        if not (a.apply or a.dry_run):
            return
    groups, errs = build_groups(rows)
    if errs:
        print('TABLE ERRORS:')
        for e in errs:
            print('  ' + e)
        sys.exit(2)
    for g in groups:
        check_contiguous(g)
        plan_headers(g)
    for g in groups:
        if len(g.olds) > 1 and not g.problems:
            plan_merge(g, None)
    failed = [g for g in groups if g.problems]
    for g in failed:
        print('FAILED GROUP %s <- %s' % (g.new, ', '.join(g.olds)))
        for p in g.problems:
            print('    ' + p)
    if failed and not a.skip_failed:
        print('%d group(s) failed; nothing written' % len(failed))
        sys.exit(1)
    groups = [g for g in groups if not g.problems]

    rw = Rewriter(groups)
    writes = collections.OrderedDict()      # rel -> text
    deletes = []
    edits = []                              # (kind, text) for the dry-run listing

    moved_src = set(rw.fmap)
    # 1. moved / merged files
    for g in groups:
        if len(g.olds) > 1:
            text = g.text
            here = g.olds[0]
            text = rw.includes(text, here)
            text = rw.bare(text, os.path.dirname(g.new))
            text = file_line(text, os.path.basename(g.new))
            # identical include lines after the rewrite
            seen, lines = set(), []
            for ln in text.split('\n'):
                if ln.startswith('#include') and ln in seen:
                    continue
                seen.add(ln)
                lines.append(ln)
            writes[g.new] = '\n'.join(lines)
            edits.append('MERGE  %s <- %s' % (g.new, ' + '.join(os.path.basename(o) for o in g.olds)))
        else:
            o = g.olds[0]
            text = rd(o)
            text = rw.includes(text, o)
            text = rw.bare(text, os.path.dirname(g.new))
            text = file_line(text, os.path.basename(g.new))
            writes[g.new] = text
            edits.append('RENAME %s -> %s' % (o, g.new))
        deletes += [o for o in g.olds if o != g.new]
        if g.hold:
            if g.htext is not None:
                htext = rw.includes(g.htext, g.hold[0])
                htext = rw.bare(htext, os.path.dirname(g.new))
            else:
                htext = rw.includes(rd(g.hold[0]), g.hold[0])
                htext = rw.bare(htext, os.path.dirname(g.new))
                htext = rw.guard(htext, stem_of(g.olds[0]), stem_of(g.new))
            writes[g.hnew] = htext
            deletes += [h for h in g.hold if h != g.hnew]
            edits.append('HEADER %s <- %s' % (g.hnew, ' + '.join(os.path.basename(h) for h in g.hold)))
        for x, y in g.comp:
            t = rd(x)
            t = rw.includes(t, x)
            t = rw.bare(t, os.path.dirname(y))
            writes[y] = t
            deletes.append(x)
            edits.append('COMPANION %s -> %s' % (x, y))

    # 2. every other file under src/
    for rel in all_text_files(['src']):
        if rel in moved_src or rel in writes or not rel.endswith(TEXT_EXT):
            continue
        try:
            t0 = rd(rel)
        except OSError:
            continue
        if '#' not in t0 and not any(s in t0 for s in ('unit_',)):
            continue
        t1 = rw.includes(t0, rel)
        if rel.startswith(GAME + '/'):
            t1 = rw.bare(t1, os.path.dirname(rel))
        if t1 != t0:
            writes[rel] = t1
            edits.append('EDIT   %s' % rel)

    # 3. tables
    scan = ['layout', 'docs/restructure'] + a.scan
    for rel in all_text_files(scan):
        if rel.startswith('layout/matched/') or rel in writes or rel in deletes:
            continue
        try:
            t0 = rd(rel)
        except (OSError, UnicodeError):
            continue
        if GAME not in t0:
            continue
        t1 = rw.paths(t0)
        if t1 != t0:
            writes[rel] = t1
            edits.append('TABLE  %s' % rel)

    for e in edits:
        print(e)
    if a.dry_run:
        import difflib
        for rel, text in writes.items():
            src = next((o for g in groups for o in g.olds + g.hold + [x for x, _y in g.comp]
                        if rw.fmap.get(o) == rel), rel)
            try:
                old = rd(src).split(chr(10))
            except OSError:
                continue
            new = text.split(chr(10))
            ch = [l for l in difflib.unified_diff(old, new, lineterm='', n=0) if l[:1] in '+-' and l[:3] not in ('+++', '---')]
            if len(old) > 0 and len(ch) > 40 and len({l for l in ch}) > 40:
                print('  %s: %d lines differ (merged file)' % (rel, len(ch)))
                continue
            for l in ch[:24]:
                print('  %s: %s' % (rel, l[:160]))
    print('groups: %d, files written: %d, files removed: %d, include edits: %d, bare stem edits: %d, path edits: %d'
          % (len(groups), len(writes), len(deletes), rw.count['include'], rw.count['bare'], rw.count['path']))

    # leftovers report
    left = collections.Counter()
    olds = {stem_of(o) for g in groups for o in g.olds if UNIT_RE.match(stem_of(o))}
    if olds:
        pat = re.compile('|'.join(sorted(map(re.escape, olds))))
        for rel in all_text_files(['tools', 'docs', 'progress', 'README.md', 'src']):
            if rel.startswith('docs/restructure/') or rel.endswith(('.pyc',)) or '__pycache__' in rel or rel in writes or rel in deletes:
                continue
            try:
                t = rd(rel)
            except (OSError, UnicodeError):
                continue
            if pat.search(t):
                left[os.path.dirname(rel) or rel] += 1
    if left:
        print('old stems still mentioned (not edited), files per directory:')
        for k, v in sorted(left.items()):
            print('    %s: %d' % (k, v))

    if a.dry_run:
        return

    # apply: write new, then remove old
    for rel, text in writes.items():
        wr(rel, text)
    for rel in deletes:
        if rel in writes:
            continue
        try:
            os.remove(os.path.join(ROOT, rel))
        except FileNotFoundError:
            pass
    if a.log:
        with open(a.log, 'a', encoding='utf-8', newline='\n') as f:
            for e in edits:
                if not e.startswith(('EDIT', 'TABLE')):
                    f.write(e + '\n')
    print('applied')

    if a.verify:
        rc = 0
        news = [g.new for g in groups]
        for i in range(0, len(news), 20):
            cmd = [sys.executable, os.path.join(HERE, 'gameverify.py')]
            for n in news[i:i + 20]:
                cmd += ['--file', os.path.join(ROOT, n)]
            print('$ gameverify --file x%d' % len(news[i:i + 20]), flush=True)
            rc |= subprocess.call(cmd, cwd=ROOT)
        for d in sorted({os.path.basename(os.path.dirname(n)) for n in news}):
            print('$ gamecheck --region %s' % d, flush=True)
            rc |= subprocess.call([sys.executable, os.path.join(HERE, 'gamecheck.py'), '--region', d], cwd=ROOT)
            if a.link:
                reg = ('arm9_main' if d == 'arm9' else 'itcm' if d.startswith('arm9_autoload0') else str(int(d[2:])))
                print('$ gamelink %s' % reg, flush=True)
                rc |= subprocess.call([sys.executable, os.path.join(HERE, 'gamelink.py'), reg], cwd=ROOT)
        sys.exit(1 if rc else 0)


if __name__ == '__main__':
    main()
