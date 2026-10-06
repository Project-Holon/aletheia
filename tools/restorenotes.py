#!/usr/bin/env python3
"""restorenotes.py: put the matched files' descriptive notes back above each function
in the restructured tree.

The one-function files in src/matched/ often carry prose in their header comment
(what the function does, why an odd construct is needed for the match, what the
evidence was).  tools/restructure.py and the merge lanes write a new header per
merged file and drop that prose.  This tool finds, for every function definition in
src/game/, the src/matched/ file that defines it, takes the prose lines of that
file's header (everything that is not a `key: value` field or the `symbols:` table),
and writes them as a comment right above the definition, unless that comment is
already there.

usage
  python tools/restorenotes.py [--tree src/game] [--dry-run]
"""
import argparse
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import protofix as pf  # noqa: E402

FIELD = re.compile(r'^\s*\*\s*(function|unit|address|packet|region|compiler|flags|lang|isa|status|file|'
                   r'blocker|evidence class)\s*:', re.I)


def notes_of(raw):
    """The prose lines of a matched file's header comment, or []."""
    m = re.match(r'\A\s*/\*(.*?)\*/', raw, re.S)
    if not m:
        return []
    out, in_sym = [], False
    for line in m.group(1).splitlines():
        if re.match(r'^\s*\*\s*symbols\s*:', line):
            in_sym = True
            continue
        if in_sym:
            if re.match(r'^\s*\*\s{2,}\S', line) or re.match(r'^\s*\*\s*$', line):
                continue
            in_sym = False
        if FIELD.match(line):
            continue
        t = re.sub(r'^\s*\*\s?', '', line).rstrip()
        out.append(t)
    while out and not out[0].strip():
        out.pop(0)
    while out and not out[-1].strip():
        out.pop()
    # collapse runs of blank lines
    res = []
    for t in out:
        if t.strip() or (res and res[-1].strip()):
            res.append(t)
    return res


def definitions_index():
    """{function name: matched source path} for every definition in src/matched."""
    idx = {}
    for dp, _dn, fn in os.walk(os.path.join(ROOT, 'src', 'matched')):
        for f in fn:
            if not f.endswith('.c'):
                continue
            p = os.path.join(dp, f)
            raw = open(p, encoding='latin1').read()
            for mm in pf.DECL_RE.finditer(pf.mask(raw)):
                if mm.group(5) == '{':
                    idx.setdefault(mm.group(3), []).append(p)
    return idx


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--tree', default=os.path.join(ROOT, 'src', 'game'))
    ap.add_argument('--dry-run', action='store_true')
    a = ap.parse_args()
    idx = definitions_index()
    cache = {}
    nfiles = nnotes = 0
    for dp, _dn, fn in os.walk(a.tree):
        for f in fn:
            if not f.endswith('.c'):
                continue
            p = os.path.join(dp, f)
            raw = open(p, encoding='latin1', newline='').read()
            m = pf.mask(raw)
            tab = pf.depth_table(m)
            edits = []
            for mm in pf.DECL_RE.finditer(m):
                if mm.group(5) != '{' or pf.depth_at(tab, mm.start()) != 0:
                    continue
                name = mm.group(3)
                srcs = idx.get(name, [])
                if len(srcs) != 1:
                    continue
                if os.path.basename(srcs[0]) == f:
                    continue                    # a member copy keeps its own header
                if srcs[0] not in cache:
                    cache[srcs[0]] = notes_of(open(srcs[0], encoding='latin1').read())
                notes = cache[srcs[0]]
                if not notes:
                    continue
                ls = raw.rfind('\n', 0, mm.start()) + 1
                before = raw[max(0, ls - 400):ls]
                if notes[0].strip() and notes[0].strip()[:40] in before:
                    continue
                eol = '\r\n' if raw[ls - 2:ls] == '\r\n' else '\n'
                block = '/*' + eol + ''.join((' * ' + t).rstrip() + eol for t in notes) + ' */' + eol
                edits.append((ls, block))
            if edits:
                for pos, block in sorted(edits, reverse=True):
                    raw = raw[:pos] + block + raw[pos:]
                nfiles += 1
                nnotes += len(edits)
                if not a.dry_run:
                    with open(p, 'w', encoding='latin1', newline='') as fh:
                        fh.write(raw)
    print('%s %d note(s) in %d file(s)' % ('would add' if a.dry_run else 'added', nnotes, nfiles))


if __name__ == '__main__':
    main()
