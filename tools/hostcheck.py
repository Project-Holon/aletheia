#!/usr/bin/env python3
"""hostcheck.py: syntax-check every src/game .c file as C for a host compiler (GCC 14).

mwcc `asm` function bodies and `asm { }` blocks are hand-written ARM, not C:
they are blanked before the check (function bodies become `{}`, blocks `;`).
Each file runs through tools/gcc-arm's arm-none-eabi-gcc with
-S -o /dev/null -std=gnu99 -fshort-wchar -Werror=implicit-function-declaration.

A failure whose only errors are static-assert / size-check failures that come
from the host ABI (EABI aligns 64-bit members to 8 bytes, mwcc does not) is
counted apart as "abi" with the reason; every other failure is FAIL.

-Wreturn-type is on: "control reaches end of non-void function" is counted per
file as its own class (not a FAIL); phase checks drive the total to 0.

Pointer-width class: every file is also compiled with the bundled 64-bit mingw
gcc (-m64 -fsyntax-only) with -Wpointer-to-int-cast, -Wint-to-pointer-cast and
-Wint-conversion.  A pointer kept in an int/u32 truncates on a 64-bit host.
Counts are per file and per kind ("ptr-to-int", "int-to-ptr", "int-conv");
hits in headers are counted once per header line.  The phase checks drive the
total to 0.  --ptr-list FILE writes every hit (path:line:col kind function).
--no-ptr skips this class.

usage: python tools/hostcheck.py [--tree src/game] [-v] [--no-ptr]
                                 [--ptr-list FILE] [FILE ...]
"""
import argparse
import collections
import concurrent.futures
import glob
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
GCC = glob.glob(os.path.join(HERE, 'gcc-arm', '*', 'bin', 'arm-none-eabi-gcc.exe')
                + '') or glob.glob(os.path.join(HERE, 'gcc-arm', '*', 'bin', 'arm-none-eabi-gcc'))
BS = chr(92)
ALL = False
RETCOUNT = {}
RETLINES = {}
GCC64 = glob.glob(os.path.join(HERE, 'gcc-host', '*', 'bin', 'x86_64-w64-mingw32-gcc.exe'))     or glob.glob(os.path.join(HERE, 'gcc-host', '*', 'bin', 'x86_64-w64-mingw32-gcc'))
PTRHITS = {}
HDRHITS = {}
PTR_KINDS = {'pointer-to-int-cast': 'ptr-to-int', 'int-to-pointer-cast': 'int-to-ptr',
             'int-conversion': 'int-conv'}
PTR_RE = re.compile(r'^(.*?):(\d+):(\d+): (?:warning|error): (.*?) \[-W(pointer-to-int-cast|'
                    r'int-to-pointer-cast|int-conversion)\]')
PTR_FLAGS = ['-m64', '-fsyntax-only', '-std=gnu99', '-fshort-wchar', '-Wno-all', '-Wno-extra',
             '-Wpointer-to-int-cast', '-Wint-to-pointer-cast', '-Wint-conversion',
             '-Wno-error=int-conversion', '-Wno-error=implicit-function-declaration',
             '-Wno-error=incompatible-pointer-types', '-x', 'c']
PTR = True
SDK_INCLUDE = os.path.join(ROOT, 'sdk', 'TwlSDK', 'include')
FLAGS = ['-S', '-o', os.devnull, '-std=gnu99', '-fshort-wchar', '-Wno-all', '-Wno-extra', '-Wreturn-type',
         '-Werror=implicit-function-declaration', '-x', 'c']
# Documented exceptions: "path:function" pairs whose missing return is kept on
# purpose (the DS bytes need it) and tracked as missing-return rows in docs/DEBT.tsv.
RET_EXCEPTIONS = {
    ('src/game/arm9/zonedata.c', 'ZONEDATA_GetChangedZoneId'),
}
FUNC_RE = re.compile(r"In function '([^']*)'")
RET_RE = re.compile(r'^(.*?):(\d+):\d+: warning: control reaches end of non-void function')
ABI_RE = re.compile(r'static assertion failed|size of array .* is negative|'
                    r'(?:negative|zero) size|size of array is negative', re.I)


def blank_asm(text):
    """Replace asm bodies by empty ones; returns text with line structure kept."""
    out = []
    i, n = 0, len(text)
    word = re.compile(r'(?:__asm|asm)\b')
    while i < n:
        c = text[i]
        if text.startswith('/*', i):
            j = text.find('*/', i + 2)
            j = n if j < 0 else j + 2
            out.append(text[i:j]); i = j; continue
        if text.startswith('//', i):
            j = text.find('\n', i)
            j = n if j < 0 else j
            out.append(text[i:j]); i = j; continue
        if c in '"\'':
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == BS else 1
            out.append(text[i:j + 1]); i = j + 1; continue
        if c == '#':
            # preprocessor line (with continuations)
            j = i
            while True:
                k = text.find('\n', j)
                if k < 0:
                    j = n; break
                if text[k - 1] == BS:
                    j = k + 1; continue
                j = k; break
            out.append(text[i:j]); i = j; continue
        m = word.match(text, i) if (c in 'a_' and (i == 0 or not (text[i - 1].isalnum() or text[i - 1] == '_'))) else None
        if m:
            j = m.end()
            # scan to the first ';' or '{' at depth 0 of parentheses
            depth = 0
            k = j
            while k < n:
                ch = text[k]
                if ch == '(':
                    depth += 1
                elif ch == ')':
                    depth -= 1
                elif depth == 0 and ch in ';{':
                    break
                k += 1
            if k >= n:
                out.append(text[i:]); break
            if text[k] == ';':
                out.append(text[j:k + 1]); i = k + 1; continue
            # body: balanced braces, ignoring comments and strings
            d = 0
            p = k
            while p < n:
                if text.startswith('/*', p):
                    q = text.find('*/', p + 2); p = n if q < 0 else q + 2; continue
                if text.startswith('//', p):
                    q = text.find('\n', p); p = n if q < 0 else q; continue
                ch = text[p]
                if ch in '"\'':
                    q = p + 1
                    while q < n and text[q] != ch:
                        q += 2 if text[q] == BS else 1
                    p = q + 1; continue
                if ch == '{':
                    d += 1
                elif ch == '}':
                    d -= 1
                    if d == 0:
                        p += 1; break
                p += 1
            body = text[k:p]
            nl = '\n' * body.count('\n')
            head = text[j:k]
            if head.strip() == '':
                out.append(';' + nl)            # asm { ... } block statement
            else:
                out.append(head + '{__builtin_unreachable();}' + nl)     # asm function definition
            i = p; continue
        out.append(c); i += 1
    return ''.join(out)


def ptrcheck(path, src, d):
    """Host 64-bit compile: collect pointer/integer conversion hits."""
    cmd = [GCC64[0]] + PTR_FLAGS + ['-iquote', d, '-I', d, '-I', SDK_INCLUDE, '-']
    p = subprocess.run(cmd, input=src.encode('latin1'), stdout=subprocess.PIPE,
                       stderr=subprocess.STDOUT, cwd=ROOT)
    fn, hits = None, []
    for l in p.stdout.decode('latin1', 'replace').split(chr(10)):
        mf = FUNC_RE.search(l)
        if mf:
            fn = mf.group(1)
        m = PTR_RE.match(l)
        if not m:
            continue
        f, ln, col, kind = m.group(1), int(m.group(2)), int(m.group(3)), PTR_KINDS[m.group(5)]
        if f == '<stdin>':
            hits.append((ln, col, kind, fn or '-'))
        else:
            ap = os.path.normpath(os.path.join(ROOT, f))
            HDRHITS[(os.path.relpath(ap, ROOT).replace(BS, '/'), ln, col, kind)] = fn or '-'
    PTRHITS[path] = sorted(set(hits))


def check(path):
    with open(path, encoding='latin1', newline='') as fh:
        src = blank_asm(fh.read())
    d = os.path.dirname(os.path.abspath(path))
    if PTR and GCC64:
        ptrcheck(path, src, d)
    cmd = [GCC[0]] + FLAGS + ['-iquote', d, '-I', d, '-I', SDK_INCLUDE, '-']
    p = subprocess.run(cmd, input=src.encode('latin1'), stdout=subprocess.PIPE,
                       stderr=subprocess.STDOUT, cwd=ROOT)
    out = p.stdout.decode('latin1', 'replace')
    rel = os.path.relpath(path, ROOT).replace(BS, '/')
    fn, lines = None, []
    for l in out.split(chr(10)):
        mf = FUNC_RE.search(l)
        if mf:
            fn = mf.group(1)
        m = RET_RE.match(l)
        if m and (rel, fn) not in RET_EXCEPTIONS:
            lines.append(m.group(2))
    RETCOUNT[path] = len(lines)
    RETLINES[path] = lines
    errs = [l for l in p.stdout.decode('latin1', 'replace').split('\n') if ' error:' in l]
    if p.returncode == 0 and not errs:
        return path, 'PASS', ''
    msgs = [re.sub(r'^.*? error:\s*', '', l) for l in errs]
    if msgs and all(ABI_RE.search(m) for m in msgs):
        return path, 'abi', 'size/alignment check differs on this host (EABI 8-byte alignment of 64-bit members): ' + msgs[0][:80]
    return path, 'FAIL', (' || '.join(msgs) if ALL and msgs else (msgs[0] if msgs else p.stdout.decode('latin1', 'replace')[:120]))[:(2000 if ALL else 140)]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--tree', default='src/game')
    ap.add_argument('-v', action='store_true')
    ap.add_argument('files', nargs='*')
    ap.add_argument('--no-ptr', action='store_true', help='skip the 64-bit pointer-width class')
    ap.add_argument('--ptr-list', metavar='FILE', help='write every pointer-width hit to FILE')
    ap.add_argument('-a', action='store_true', help='show every error of a failing file')
    a = ap.parse_args()
    global ALL, PTR
    ALL = a.a
    PTR = not a.no_ptr
    if PTR and not GCC64:
        raise SystemExit('no x86_64 mingw gcc under tools/gcc-host (use --no-ptr)')
    if not GCC:
        raise SystemExit('no arm-none-eabi-gcc under tools/gcc-arm')
    files = a.files or sorted(glob.glob(os.path.join(ROOT, a.tree, '**', '*.c'), recursive=True))
    cnt = collections.Counter()
    classes = collections.Counter()
    with concurrent.futures.ThreadPoolExecutor(max_workers=os.cpu_count() or 4) as ex:
        for path, st, why in ex.map(check, files):
            cnt[st] += 1
            rel = os.path.relpath(path, ROOT).replace(BS, '/')
            if st != 'PASS' or a.v:
                print('%s %s %s' % (st, rel, why))
            if st == 'FAIL':
                classes[re.sub(r"'[^']*'", "'X'", why)[:60]] += 1
    print('--- failure classes')
    for k, v in classes.most_common():
        print('%4d %s' % (v, k))
    tot = 0
    print('--- control reaches end of non-void function (per file)')
    for path, n in sorted(RETCOUNT.items()):
        if n:
            tot += n
            print('%4d %s%s' % (n, os.path.relpath(path, ROOT).replace(BS, '/'),
                              ' (line ' + ', '.join(RETLINES[path]) + ')' if a.v else ''))
    print('missing-return total %d' % tot)
    ptot = 0
    if PTR:
        print('--- pointers stored in integers on a 64-bit host (per file: ptr-to-int / int-to-ptr / int-conv)')
        per = collections.Counter()
        rows = []
        for path, hits in sorted(PTRHITS.items()):
            rel = os.path.relpath(path, ROOT).replace(BS, '/')
            for ln, col, kind, fn in hits:
                per[(rel, kind)] += 1
                rows.append((rel, ln, col, kind, fn))
        for (rel, ln, col, kind), fn in sorted(HDRHITS.items()):
            per[(rel, kind)] += 1
            rows.append((rel, ln, col, kind, fn))
        for rel in sorted({r for r, _ in per}):
            c = [per[(rel, k)] for k in ('ptr-to-int', 'int-to-ptr', 'int-conv')]
            ptot += sum(c)
            print('%4d %4d %4d %s' % (c[0], c[1], c[2], rel))
        print('pointer-width total %d' % ptot)
        if a.ptr_list:
            with open(a.ptr_list, 'w', newline=chr(10)) as fh:
                for r in sorted(rows):
                    fh.write(('%s:%d:%d' + chr(9) + '%s' + chr(9) + '%s') % r + chr(10))
    print('total %d: PASS %d, abi %d, FAIL %d' % (len(files), cnt['PASS'], cnt['abi'], cnt['FAIL']))
    return 1 if cnt['FAIL'] else 0


if __name__ == '__main__':
    sys.exit(main())
