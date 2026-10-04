"""Struct generation from solved classes, and text-level rewriting of raw-offset accesses.

Struct fields are chosen from the observed accesses of one class:
  * candidates are (offset, width) pairs seen in accesses (arrays excluded);
  * a candidate must be naturally aligned (offset % width == 0);
  * overlapping candidates: keep the one with more accesses (ties: wider), drop the others (their sites stay raw);
  * gaps become `unsigned char pad_XXXX[n]`.
A site is converted when an accepted field has exactly the site's offset.  The converted text is
  ((struct S *)v)->fK                      same type as the field
  *(T *)&((struct S *)v)->fK               type differs (pointer vs integer, sign, narrower width at the same offset)
so no behaviour changes and the original access type is kept.
Sites with any other base expression E (`*(T *)(E + K)`) become ((struct S *)(E))->fK; sites nested in
the base of another site are rewritten inside out.
"""
import re, collections

CT = {(1, False): 'unsigned char', (1, True): 'signed char', (2, False): 'unsigned short', (2, True): 'short',
      (4, False): 'unsigned int', (4, True): 'int', (8, False): 'unsigned long long', (8, True): 'long long'}

class Struct:
    def __init__(self, name):
        self.name = name; self.fields = []      # (off, width, kind, signed, count)
        self.size = 0
        self.by_off = {}

    def text(self, nl='\n'):
        out = ['struct %s {' % self.name]
        pos = 0
        for off, w, kind, sg, cnt in self.fields:
            if off > pos: out.append('    unsigned char pad_%X[%d];' % (pos, off - pos))
            if kind == 'ptr': t = 'void *'
            elif kind == 'float': t = 'float'
            else: t = CT[(w, sg)]
            out.append('    %s f%X;' % (t, off))
            pos = off + w
        out.append('};')
        return nl.join(out) + nl

def build_struct(name, acc):
    cnt = collections.Counter(); info = {}
    for off, w, kind, sg, wr, src in acc:
        if kind == 'arr': continue
        key = (off, w)
        cnt[key] += 1
        d = info.setdefault(key, {'ptr': 0, 'int': 0, 'float': 0, 'sg': 0, 'us': 0})
        d[kind] += 1
        if kind == 'int':
            if sg: d['sg'] += 1
            else: d['us'] += 1
    # merge same-offset accesses of different widths into candidates per (off,w)
    cands = []
    for (off, w), n in cnt.items():
        if w not in (1, 2, 4, 8) or off < 0 or off % w != 0: continue
        d = info[(off, w)]
        kind = 'ptr' if d['ptr'] else ('float' if d['float'] and not d['int'] else 'int')
        if kind == 'ptr' and w != 4: kind = 'int'
        sg = d['sg'] > d['us']
        cands.append((n, w, off, kind, sg))
    cands.sort(key=lambda c: (-c[0], -c[1], c[2]))
    taken = []
    for n, w, off, kind, sg in cands:
        if any(off < o2 + w2 and o2 < off + w for o2, w2, k2, s2, n2 in taken): continue
        taken.append((off, w, kind, sg, n))
    taken.sort()
    st = Struct(name)
    st.fields = [(o, w, k, s, n) for o, w, k, s, n in taken]
    st.size = max((o + w for o, w, k, s, n in taken), default=0)
    st.by_off = {o: (w, k, s) for o, w, k, s, n in taken}
    return st

PAT = re.compile(r'\*\s*\(\s*(?P<ty>[^()]*?)\s*\*\s*\)\s*\(\s*(?:\(\s*[^()]*?\*\s*\)\s*)?(?P<var>[A-Za-z_]\w*)\s*(?:\+\s*(?P<k>0[xX][0-9A-Fa-f]+|\d+)[uUlL]*)?\s*\)')
PAT_ZERO = re.compile(r'\*\s*\(\s*(?P<ty>[^()]*?)\s*\*\s*\)\s*(?P<var>[A-Za-z_]\w*)')
CASTRE = re.compile(r'\(\s*(?P<ty>[^()]*?)\s*\*\s*\)')
KTAIL = re.compile(r'\s*(?P<k>0[xX][0-9A-Fa-f]+|\d+)[uUlL]*\s*$')
IDENT = re.compile(r'[A-Za-z_]\w*')
SPACE = ' \t\r\n'

def line_starts(text):
    st = [0]
    for m in re.finditer('\n', text): st.append(m.end())
    return st

def locate(text, ls, line, col, form, var, ktext):
    """Find the exact `*(T *)(...)` text of a recorded site.  The recorded column is the '(' of the cast."""
    if line - 1 >= len(ls): return None
    pos = ls[line - 1] + col - 1
    i = pos - 1
    while i >= 0 and text[i] in SPACE: i -= 1
    if i < 0 or text[i] != '*': return None
    pat = PAT_ZERO if form == 'zero' else PAT
    m = pat.match(text, i)
    if not m or m.group('var') != var: return None
    if form != 'zero':
        kk = m.group('k')
        if kk is None or int(kk, 0) != int(re.sub(r'[uUlL]+$', '', ktext), 0): return None
    return m

def plan_file(rel, sv, structs, root_of_node, sites):
    """sites: list of (node, K, width, kind, signed, line, col, form, var, ktext) for this file.
    returns list of (line, col, form, var, ktext, struct, off, width, kind, signed)."""
    out = []
    for node, k, w, kind, sg, line, col, form, var, ktext in sites:
        r = sv.find(node)
        st = structs.get(r)
        if st is None: continue
        f = st.by_off.get(k)
        if f is None: continue
        fw, fk, fs = f
        if w > fw: continue
        out.append((line, col, form, var, ktext, st, k, w, kind, sg))
    return out

def _match_paren(text, j):
    """text[j] == '(' -> index of the matching ')' or -1."""
    depth = 0
    for q in range(j, len(text)):
        c = text[q]
        if c == '(': depth += 1
        elif c == ')':
            depth -= 1
            if depth == 0: return q
    return -1

def parse_generic(text, i):
    """text[i] == '*' starts `*(T *)(E + K)`, `*(T *)(E)`, `*(T *)E` or `*((T *)(E))`.
    Returns (end, ty, left_start, left_end, ktext) or None.  E is text[left_start:left_end]."""
    n = len(text)
    def ws(j):
        while j < n and text[j] in SPACE: j += 1
        return j
    j = ws(i + 1); wrapped = 0
    while j < n and text[j] == '(' and not CASTRE.match(text, j):
        wrapped += 1; j = ws(j + 1)
    m = CASTRE.match(text, j)
    if not m: return None
    ty = m.group('ty').strip(); j = ws(m.end())
    if j >= n: return None
    if text[j] == '(':
        q = _match_paren(text, j)
        if q < 0: return None
        lo, hi = j + 1, q; j = q + 1
    else:
        mm = IDENT.match(text, j)
        if not mm: return None
        lo, hi = mm.start(), mm.end(); j = mm.end()
    for _ in range(wrapped):
        j = ws(j)
        if j >= n or text[j] != ')': return None
        j += 1
    while True:     # redundant outer parentheses: ((p + 4))
        a = lo
        while a < hi and text[a] in SPACE: a += 1
        b = hi
        while b > a and text[b - 1] in SPACE: b -= 1
        if a < b and text[a] == '(' and _match_paren(text, a) == b - 1: lo, hi = a + 1, b - 1
        else: break
    inner = text[lo:hi]
    depth = 0; cut = -1
    for q in range(len(inner) - 1, -1, -1):
        c = inner[q]
        if c == ')': depth += 1
        elif c == '(': depth -= 1
        elif c == '+' and depth == 0:
            if KTAIL.match(inner, q + 1): cut = q
            break
    if cut >= 0:
        ktext = KTAIL.match(inner, cut + 1).group('k'); le = lo + cut
    else:
        ktext = '0'; le = hi
    ls = lo
    while ls < le and text[ls] in SPACE: ls += 1
    while le > ls and text[le - 1] in SPACE: le -= 1
    if ls >= le: return None
    return j, ty, ls, le, ktext

def apply_plan(text, plan, only_exact=False):
    """-> (new text, converted count, structs used, stats).  Edits are applied from the end of the text to the start."""
    ls = line_starts(text)
    edits = []; stats = collections.Counter()
    for line, col, form, var, ktext, st, k, w, kind, sg in plan:
        m = locate(text, ls, line, col, form, var, ktext) if form != 'expr' else None
        if m is not None:
            ty = m.group('ty').strip()
            d = {'s': m.start(), 'e': m.end(), 'ls': None, 'le': None, 'var': var}
        else:
            if line - 1 >= len(ls): stats['site not found'] += 1; continue
            i = ls[line - 1] + col - 2
            while i >= 0 and text[i] in SPACE: i -= 1
            if i < 0 or text[i] != '*': stats['site not found'] += 1; continue
            g = parse_generic(text, i)
            if g is None: stats['site not found'] += 1; continue
            end, ty, lo, hi, kt = g
            if int(kt, 0) != int(re.sub(r'[uUlL]+$', '', ktext), 0): stats['site not found'] += 1; continue
            d = {'s': i, 'e': end, 'ls': lo, 'le': hi, 'var': None}
            stats['general form'] += 1
        fw, fk, fs = st.by_off[k]
        same = (w == fw and ((kind == 'ptr') == (fk == 'ptr')) and (kind == 'ptr' or sg == fs)
                and (kind != 'ptr' or ty == 'void *')
                and 'volatile' not in ty and 'const' not in ty)
        if only_exact and not same: stats['skipped (type differs)'] += 1; continue
        stats['direct' if same else 'pun form'] += 1
        pre = '((struct %s *)' % st.name; post = ')->f%X' % k
        if d['var'] is None and not IDENT.fullmatch(text[d['ls']:d['le']]):
            pre += '('; post = ')' + post
        if not same: pre = '*(%s *)&' % ty + pre
        d['pre'], d['post'], d['st'], d['kids'] = pre, post, st, []
        edits.append(d)
    # a site inside the base expression of another site is rewritten inside out; other overlaps are dropped
    edits.sort(key=lambda d: (d['s'], -d['e']))
    roots = []; stack = []; acc = []
    for d in edits:
        while stack and d['s'] >= stack[-1]['e']: stack.pop()
        if stack:
            p = stack[-1]
            if p['ls'] is not None and d['s'] >= p['ls'] and d['e'] <= p['le']:
                p['kids'].append(d); stack.append(d); acc.append(d)
            else: stats['overlap dropped'] += 1
            continue
        roots.append(d); stack.append(d); acc.append(d)
    def render(lo, hi, kids):
        out = []; pos = lo
        for c in kids:
            out.append(text[pos:c['s']]); out.append(emit(c)); pos = c['e']
        out.append(text[pos:hi]); return ''.join(out)
    def emit(c):
        inner = c['var'] if c['ls'] is None else render(c['ls'], c['le'], c['kids'])
        return c['pre'] + inner + c['post']
    res = render(0, len(text), roots)
    structs_used = {}
    for d in acc: structs_used[d['st'].name] = d['st']
    return res, len(acc), structs_used, stats

def header_text(st, nl='\n'):
    g = 'ALETHEIA_%s_H' % st.name.upper()
    return nl.join(['#ifndef ' + g, '#define ' + g, st.text(nl).rstrip(nl), '#endif', ''])

def insert_includes(text, names, nl, prefix='../include/'):
    """Insert `#include "../include/ObjN.h"` lines right after the leading header comment."""
    if not names: return text
    m = re.match(r'\s*/\*.*?\*/[ \t]*(\r?\n)?', text, re.S)
    pos = m.end() if m else 0
    inc = ''.join('#include "%s%s.h"%s' % (prefix, n, nl) for n in sorted(names))
    return text[:pos] + inc + text[pos:]

def insert_structs(text, structs_used, first_func_line, nl):
    if not structs_used: return text
    blk = nl.join(st.text(nl).rstrip(nl) for st in sorted(structs_used.values(), key=lambda s: s.name)) + nl
    ls = line_starts(text)
    pos = ls[first_func_line - 1] if first_func_line - 1 < len(ls) else len(text)
    return text[:pos] + blk + text[pos:]
