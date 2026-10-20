#!/usr/bin/env python3
"""ptrfix.py: pointers cast to 32-bit integers become uptr / sptr (lane P3PTR, wave 20 phase 3).

A 64-bit host truncates `(u32)p`.  hostcheck reports each such cast (-Wpointer-to-int-cast)
with the column of its opening parenthesis.  This tool rewrites exactly those casts:

    (u32) (unsigned int) (unsigned long)      ->  (uptr)
    (int) (s32) (long) (long int) (signed ...) ->  (sptr)

uptr and sptr are typedefs in src/game/types.h (u32 and s32 under mwcc, so the DS bytes
do not change; the host gets the pointer width).  The rewrite keeps the signedness of the
original cast.  A hit whose text at the reported column is not one of these casts (a cast
inside a macro body, a narrow cast such as (u8)) is listed and left alone.

With --sinks the tool also retypes the integer that a pointer cast reads.  An
int-to-pointer hit `(T *)name` where `name` is a plain identifier declared in the same
function (a local) or as a parameter of a static function, or a file-level static,
with an integer type, gets the type uptr (sptr when it was signed).  A declaration list
`u32 a, b;` keeps its order: names that stay u32 stay in the first statement.  Every
other sink (a field, a call result, an index, a hardware address) is counted per kind
as "left" for the waiting list.  The sinks pass repeats until nothing changes, since a
retyped variable moves the next hit.

With --verify the rewritten files are compared with the original bytes through
gameverify; a file that is no longer EXACT goes back to its old text.

  python tools/ptrfix.py FILE ...                 dry run: count rewrites and skips per file
  python tools/ptrfix.py --list FILE ...          also print every rewrite and skip
  python tools/ptrfix.py --sinks FILE ...         also retype the integers the casts read
  python tools/ptrfix.py --apply FILE ...         write the files
  python tools/ptrfix.py --apply --verify FILE ...  write, run gameverify, undo files that are not EXACT
  python tools/ptrfix.py --all-free --claims PATH --lane P3PTR
                                                  every src/game .c file nobody holds
  python tools/ptrfix.py --apply ... --claims PATH --lane P3PTR
                                                  claim each file through claims.py first

Files are repo-relative (src/game/...).  Without --claims the files are not checked.
After --apply run: gameverify --file on the files, hostcheck, gamelink.
"""
import argparse
import glob
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import hostcheck  # noqa: E402

UNS = ('u32', 'unsigned int', 'unsigned long', 'unsigned')
SIG = ('s32', 'int', 'long', 'long int', 'signed int', 'signed long', 'signed')
CAST_RE = re.compile(r'\(\s*(?:const\s+)?(u32|s32|(?:unsigned|signed)(?:\s+(?:int|long))?|long(?:\s+int)?|int)\s*\)')


INT = r'(?:unsigned\s+int|signed\s+int|u32|s32|int|unsigned)'
LONG_RE = r'(?:unsigned\s+long|signed\s+long|long\s+int|long)'
PTRCAST_RE = re.compile(r'\(\s*(?:const\s+|volatile\s+)*(?:struct\s+|union\s+|enum\s+)?\w+(?:\s+\w+)*?\s*\*+\s*\)'
                        r'\s*\(?\s*(\w+)\b(?!\s*(?:\(|\[|\.|->))')
STMT_RE = re.compile(r'^(\s*)((?:static\s+|register\s+|const\s+|volatile\s+)*)(' + INT
                     + r')\s+([^;(){}*]*);\s*(?://.*)?$')


def scan(rel, text):
    """host 64-bit hits of `text` taken as file rel: (line, col, kind, function)."""
    path = os.path.join(ROOT, rel)
    src = hostcheck.blank_asm(text)
    d = os.path.dirname(os.path.abspath(path))
    hostcheck.PTRHITS.pop(path, None)
    hostcheck.ptrcheck(path, src, d)
    return hostcheck.PTRHITS.get(path, [])


def has_types(rel, text):
    """True when uptr and sptr resolve in this file (it includes types.h, directly or not)."""
    path = os.path.join(ROOT, rel)
    src = hostcheck.blank_asm(text) + chr(10) + 'uptr p3ptr_probe_u;' + chr(10) + 'sptr p3ptr_probe_s;' + chr(10)
    cmd = [hostcheck.GCC64[0]] + hostcheck.PTR_FLAGS + ['-iquote', os.path.dirname(path), '-I', os.path.dirname(path),
                                                         '-I', hostcheck.SDK_INCLUDE, '-']
    p = subprocess.run(cmd, input=src.encode('latin1'), stdout=subprocess.PIPE, stderr=subprocess.STDOUT, cwd=ROOT)
    return b"unknown type name 'uptr'" not in p.stdout and b"unknown type name 'sptr'" not in p.stdout


def new_type(word):
    return 'uptr' if ' '.join(word.split()) in UNS else 'sptr'


def split_top(lst):
    out, depth, cur = [], 0, ''
    for ch in lst:
        if ch in '([{':
            depth += 1
        elif ch in ')]}':
            depth -= 1
        if ch == ',' and depth == 0:
            out.append(cur)
            cur = ''
        else:
            cur += ch
    out.append(cur)
    return out


def classify_other(row, col):
    """kind of an int-to-pointer hit whose operand is not a plain identifier."""
    m = re.match(r'\(\s*(?:const\s+|volatile\s+)*[\w\s]+?(?:\s*\*)+\s*\)\s*(.*)', row[col - 1:])
    if not m:
        return 'other'
    r = m.group(1)
    if re.match(r'\w+\s*\(', r):
        return 'call'
    if re.match(r'[A-Z_0-9]+\b(?!\s*[(\.\[-])', r) or re.match(r'(0x[0-9A-Fa-f]+|\d+)\b', r):
        return 'macro'
    if re.match(r'\w+\s*(->|\.)', r):
        return 'field'
    if re.match(r'\w+\s*\[', r):
        return 'index'
    return 'other'


def find_decl(lines, ln, name):
    """declaration of the integer `name` seen from line ln (1-based): (kind, line index, match) or None."""
    start = -1
    for i in range(ln - 2, -1, -1):
        if lines[i].startswith('}'):
            start = i
            break
    brace = None
    for i in range(start + 1, ln):
        if lines[i].startswith('{') or (lines[i].rstrip().endswith('{') and not lines[i].startswith((' ', '\t'))):
            brace = i
            break
    header = ' '.join(lines[start + 1:(brace if brace is not None else start + 1)])
    static_fn = re.search(r'(?:^|\s)static\b', header) is not None
    pat_param = re.compile(r'(?<![\w*])(' + INT + r')\s+' + re.escape(name) + r'\s*(?=[,)])')
    for i in range(ln - 1, start, -1):
        row = lines[i]
        m = STMT_RE.match(row)
        if m and (brace is None or i > brace):
            decls = split_top(m.group(4))
            if any(re.match(r'\s*' + re.escape(name) + r'\s*(=.*)?$', x, re.S) for x in decls):
                return ('local', i, m)
        if brace is not None and i < brace:
            mp = pat_param.search(row)
            if mp:
                return ('param' if static_fn else 'param-extern', i, mp)
    return None


def find_static(lines, name):
    pat = re.compile(r'^(static\s+(?:const\s+)?)(' + INT + r')\s+' + re.escape(name) + r'\s*(?==|;|,|\[)')
    for i, row in enumerate(lines):
        m = pat.match(row)
        if m:
            return i, m
    return None


def sink_pass(text, hits):
    """One pass: retype the integers that int-to-pointer casts read.
    Returns (text, retyped names, {(line, col): why it was left})."""
    lines = text.split('\n')
    left = {}
    edits = {}
    seen = set()
    for ln, col, kind, fn in sorted(set(hits)):
        if kind != 'int-to-ptr' or ln > len(lines) or (ln, col) in seen:
            continue
        seen.add((ln, col))
        row = lines[ln - 1]
        m = PTRCAST_RE.match(row, col - 1)
        if not m:
            left[(ln, col)] = classify_other(row, col)
            continue
        name = m.group(1)
        if re.match(r'^[A-Z_0-9]+$', name):
            left[(ln, col)] = 'macro'
            continue
        d = find_decl(lines, ln, name)
        if d is None:
            sd = find_static(lines, name)
            if sd is None:
                lg = re.search(r'(?<![\w*])' + LONG_RE + r'\s+(?:\w+\s*,\s*)*' + re.escape(name) + r'', text)
                left[(ln, col)] = 'long-typed' if lg else 'not-integer'
                continue
            edits.setdefault(sd[0], {})['static'] = sd[1]
            continue
        kind2, i, mm = d
        if kind2 == 'local':
            edits.setdefault(i, {}).setdefault('local', set()).add(name)
        elif kind2 == 'param':
            edits.setdefault(i, {}).setdefault('param', set()).add(name)
        else:
            left[(ln, col)] = 'param-extern'
    changed = []
    for i, e in sorted(edits.items()):
        if 'static' in e:
            ms = e['static']
            row = lines[i]
            lines[i] = row[:ms.start(2)] + new_type(ms.group(2)) + row[ms.end(2):]
            changed.append('static@%d' % (i + 1))
            continue
        for name in sorted(e.get('param', ())):
            row = lines[i]
            mp = re.search(r'(?<![\w*])(' + INT + r')\s+' + re.escape(name) + r'\s*(?=[,)])', row)
            if mp:
                lines[i] = row[:mp.start(1)] + new_type(mp.group(1)) + row[mp.end(1):]
                changed.append(name)
        if 'local' in e:
            row = lines[i]
            m = STMT_RE.match(row)
            if not m:
                continue
            indent, mods, typ = m.group(1), m.group(2), m.group(3)
            decls = [x.strip() for x in split_top(m.group(4))]
            names = e['local']
            nt = new_type(typ)
            runs = []
            for x in decls:
                t2 = nt if re.match(r'\w+', x).group(0) in names else typ
                if runs and runs[-1][0] == t2:
                    runs[-1][1].append(x)
                else:
                    runs.append((t2, [x]))
            tail = row[m.end(4):]
            lines[i] = indent + ' '.join('%s%s %s;' % (mods, t2, ', '.join(ds)) for t2, ds in runs)[:-1] + tail
            changed.extend(sorted(names))
    return '\n'.join(lines), changed, left


def rewrite(rel, sinks=False):
    """New text of one file.  Returns (text, done, skipped, old text, retyped names, left sinks)."""
    with open(os.path.join(ROOT, rel), encoding='latin1', newline='') as fh:
        old = fh.read()
    lines = old.split('\n')
    done, skipped, seen = [], [], set()
    for ln, col, kind, fn in sorted(set(scan(rel, old)), reverse=True):
        if kind != 'ptr-to-int' or (ln, col) in seen or ln > len(lines):
            continue
        seen.add((ln, col))
        row = lines[ln - 1]
        m = CAST_RE.match(row, col - 1)
        if not m:
            skipped.append((ln, col, row.strip()[:100]))
            continue
        new = '(uptr)' if ' '.join(m.group(1).split()) in UNS else '(sptr)'
        lines[ln - 1] = row[:col - 1] + new + row[m.end():]
        done.append((ln, col, m.group(0), new))
    text = '\n'.join(lines)
    retyped, left = [], {}
    if sinks:
        for _ in range(8):
            text2, changed, left = sink_pass(text, scan(rel, text))
            if text2 == text:
                break
            text = text2
            retyped.extend(changed)
    return text, sorted(done), sorted(skipped), old, retyped, left


def write_text(path, text):
    """Write latin1 text keeping every line ending; retry when the file is briefly locked."""
    import time
    for attempt in range(6):
        try:
            with open(path, 'w', encoding='latin1', newline='') as fh:
                fh.write(text)
            return
        except OSError:
            if attempt == 5:
                raise
            time.sleep(1.0 + attempt)


def verify_files(rels):
    """Run gameverify on the files; returns the set of repo-relative paths that are not EXACT."""
    bad = set()
    for i in range(0, len(rels), 8):
        cmd = [sys.executable, os.path.join(HERE, 'gameverify.py')]
        for r in rels[i:i + 8]:
            cmd += ['--file', os.path.join(ROOT, r)]
        p = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, cwd=ROOT)
        for l in p.stdout.decode('latin1', 'replace').split('\n'):
            if l.startswith('NOT EXACT'):
                bad.add(l.split()[2])
    return bad


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('files', nargs='*')
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('--list', action='store_true')
    ap.add_argument('--sinks', action='store_true', help='also retype the integers that pointer casts read')
    ap.add_argument('--verify', action='store_true', help='with --apply: gameverify, undo files not EXACT')
    ap.add_argument('--all-free', action='store_true', help='every src/game .c file nobody holds (needs --claims)')
    ap.add_argument('--claims', help='path of claims.py')
    ap.add_argument('--lane', default='P3PTR')
    ap.add_argument('--left-tsv', metavar='FILE', help='write every sink left open: file line kind')
    a = ap.parse_args()
    files = [f.replace(os.sep, '/') for f in a.files]
    owner = None
    if a.claims:
        sys.path.insert(0, os.path.dirname(os.path.abspath(a.claims)))
        import claims
        db = claims.load()
        owner = lambda f: [l for l in claims.owner(f, db) if l != a.lane]
    if a.all_free:
        if not owner:
            raise SystemExit('--all-free needs --claims')
        files = sorted(os.path.relpath(p, ROOT).replace(os.sep, '/')
                       for p in glob.glob(os.path.join(ROOT, 'src', 'game', '**', '*.c'), recursive=True))
    tot_done = tot_skip = tot_ret = 0
    leftrows = []
    written = {}
    for rel in files:
        if owner and owner(rel):
            if not a.all_free:
                print('HELD %s by %s' % (rel, ','.join(owner(rel))))
            continue
        new, done, skipped, old, retyped, left = rewrite(rel, a.sinks)
        for (ln, col), why in sorted(left.items()):
            leftrows.append((rel, ln, why))
        if not done and not skipped and not retyped and not left:
            continue
        tot_done += len(done)
        tot_skip += len(skipped)
        tot_ret += len(retyped)
        kinds = {}
        for why in left.values():
            kinds[why] = kinds.get(why, 0) + 1
        print('%s: %d casts, %d skipped, %d retyped%s' % (
            rel, len(done), len(skipped), len(retyped),
            (', left ' + ' '.join('%s=%d' % kv for kv in sorted(kinds.items()))) if kinds else ''))
        if a.list:
            for ln, col, was, now in done:
                print('  %d:%d %s -> %s' % (ln, col, was, now))
            for ln, col, txt in skipped:
                print('  SKIP %d:%d %s' % (ln, col, txt))
            if retyped:
                print('  RETYPED ' + ' '.join(retyped))
        if a.apply and new != old:
            if a.claims:
                r = subprocess.run([sys.executable, a.claims, 'claim', a.lane, rel], stdout=subprocess.PIPE,
                                   stderr=subprocess.STDOUT)
                if r.returncode != 0 or b'refus' in r.stdout.lower():
                    print('  claim refused, skipped')
                    continue
            write_text(os.path.join(ROOT, rel), new)
            written[rel] = old
    if a.apply and a.verify and written:
        bad = verify_files(sorted(written))
        for rel in sorted(bad):
            write_text(os.path.join(ROOT, rel), written[rel])
            print('UNDONE (not EXACT) %s' % rel)
        print('verified %d files, %d undone' % (len(written), len(bad)))
    if a.left_tsv:
        with open(a.left_tsv, 'w', newline='\n') as fh:
            for rel, ln, why in leftrows:
                fh.write('%s\t%d\t%s\n' % (rel, ln, why))
    print('total: %d casts, %d skipped, %d retyped%s' % (tot_done, tot_skip, tot_ret,
                                                       '' if a.apply else ' (dry run)'))


if __name__ == '__main__':
    main()
