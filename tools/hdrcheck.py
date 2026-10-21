#!/usr/bin/env python3
"""hdrcheck.py: every .h under src/game must compile on its own.

For each header a one-line TU `#include "<header>"` is compiled twice:
  host: arm-none-eabi-gcc -fsyntax-only with the hostcheck flags (no __MWERKS__)
  ds:   mwcc with the gameverify defaults (dsi/1.1p1, -O4,p, c99, ARM)
A header that fails alone is listed with its first error.

usage: python tools/hdrcheck.py [--tree src/game] [--host-only | --ds-only] [-j N]
                                [--version white] [-v] [HEADER ...]
Exit status 0 when no header fails.
"""
import argparse
import concurrent.futures
import os
import shutil
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import hostcheck as hc  # noqa: E402

BS = chr(92)


def host_check(path):
    import subprocess
    d = os.path.dirname(path)
    src = '#include "%s"\n' % path.replace(BS, '/')
    flags = [f for f in hc.FLAGS if f != '-Wreturn-type']
    cmd = [hc.GCC[0]] + flags + ['-iquote', d, '-I', d, '-I', os.path.join(ROOT, 'src', 'game'),
                                 '-I', hc.SDK_INCLUDE, '-']
    p = subprocess.run(cmd, input=src.encode('latin1'), stdout=subprocess.PIPE,
                       stderr=subprocess.STDOUT, cwd=ROOT)
    out = p.stdout.decode('latin1', 'replace')
    errs = [l for l in out.split('\n') if ' error:' in l]
    if p.returncode == 0 and not errs:
        return None
    if errs and all(hc.ABI_RE.search(l) for l in errs):
        return None        # host ABI size checks (EABI 8-byte alignment): hostcheck counts them as abi
    return (errs[0] if errs else out[:200]).strip()


IR_MAP = {}
_PATCHED = []


def _patch(match):
    """compile_tu passes `-ir <dir of the TU>`; a header must see its own directory there, as the
    .c files next to it do.  The scratch TU dir is mapped to the header's directory."""
    if _PATCHED:
        return
    orig = match.toolenv.windows_cmd

    def wrapped(cmd, *a, **k):
        cmd = list(cmd)
        for i, x in enumerate(cmd[:-1]):
            if x == '-ir':
                real = IR_MAP.get(os.path.normcase(os.path.abspath(cmd[i + 1])))
                if real:
                    cmd[i + 1] = real
                    cmd[i + 2:i + 2] = ['-i', os.path.join(ROOT, 'src', 'game').replace(os.sep, '/')]
        return orig(cmd, *a, **k)
    match.toolenv.windows_cmd = wrapped
    _PATCHED.append(1)


def ds_check(path):
    import match
    _patch(match)
    work = tempfile.mkdtemp(prefix='hdrc_')
    try:
        tu = os.path.join(work, 'hc_tu.c')
        with open(tu, 'w', newline='') as fh:
            fh.write('#include "%s"\n' % path.replace(BS, '/'))
        IR_MAP[os.path.normcase(os.path.abspath(work))] = os.path.dirname(path)
        obj, _cmd, log, rc = match.compile_tu(tu, '1.1p1', ['-O4,p'], False, 'c99', work)
        if obj is None and not log.strip():
            log = 'no output'
        log = log.replace(chr(13), '')
        if obj is not None:
            return None
        lines = [l for l in log.split(chr(10)) if l.strip() and 'caused tool to abort' not in l]
        lines = [l for l in lines if 'warning' not in l] or lines
        return (lines[0].strip() if lines else 'rc=%d' % rc)[:300]
    finally:
        shutil.rmtree(work, ignore_errors=True)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--tree', default='src/game')
    ap.add_argument('--host-only', action='store_true')
    ap.add_argument('--ds-only', action='store_true')
    ap.add_argument('--version', default='black')
    ap.add_argument('-j', type=int, default=8)
    ap.add_argument('-v', action='store_true')
    ap.add_argument('files', nargs='*')
    a = ap.parse_args()
    os.environ['ALETHEIA_VERSION'] = a.version
    if a.files:
        hdrs = [os.path.abspath(f) for f in a.files]
    else:
        hdrs = []
        for dp, _dn, fn in os.walk(os.path.join(ROOT, a.tree)):
            hdrs += [os.path.join(dp, f) for f in fn if f.endswith('.h')]
    hdrs.sort()
    jobs = []
    for h in hdrs:
        if not a.ds_only:
            jobs.append((h, 'host', host_check))
        if not a.host_only:
            jobs.append((h, 'ds', ds_check))
    fails = {}
    with concurrent.futures.ThreadPoolExecutor(a.j) as ex:
        futs = {ex.submit(fn, h): (h, kind) for h, kind, fn in jobs}
        for f in concurrent.futures.as_completed(futs):
            h, kind = futs[f]
            try:
                r = f.result()
            except Exception as e:  # noqa: BLE001
                r = 'tool error: %s' % e
            if r:
                fails.setdefault(h, {})[kind] = r
    for h in sorted(fails):
        rel = os.path.relpath(h, ROOT).replace(BS, '/')
        for kind in ('host', 'ds'):
            if kind in fails[h]:
                print('FAIL %-4s %s: %s' % (kind, rel, fails[h][kind]))
    nh = sum(1 for h in fails if 'host' in fails[h])
    nd = sum(1 for h in fails if 'ds' in fails[h])
    print('hdrcheck: %d headers, host failing %d, ds failing %d' % (len(hdrs), nh, nd))
    return 1 if fails else 0


if __name__ == '__main__':
    sys.exit(main())
