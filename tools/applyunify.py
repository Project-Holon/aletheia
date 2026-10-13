#!/usr/bin/env python3
"""applyunify.py: apply the unified structs of tools/globalunify.py to the
matched files, so every file that declares a global uses ONE struct type for it.
Every changed file is verified byte-exact the way tools/protofix.py does it
(GCC syntax check plus match.py verdicts with --lang c99 and without --lang);
a change is kept only if the verdicts stay equal to the original ones.

Input (from globalunify.py)
  globals.tsv          verdict per global (SAME and MIXED with a unified struct)
  unified_structs.h    one proposed struct per global, with its ptr/object view

What it does for each selected global
  1. Writes src/matched/include/G_<Struct>.h (include guard, builtin type
     spellings, forward declarations for foreign struct pointers).  One header
     per struct name.  A type name the header cannot spell (unknown typedef) is
     replaced by void * for pointers, or the global is skipped.
  2. In every matched file that declares the global (same region and address;
     aliases g_/d_/s_ with the same address count) it
       - replaces the extern declaration by `extern struct N *g;` (pointer view)
         or `extern struct N g;` (object view; array dimensions are kept),
       - adds `#include "../include/G_<Struct>.h"`,
       - rewrites the field accesses made through the old view BY OFFSET:
         g->f10, ((struct T *)g)->f10, g[i].f10, g.f10, ((struct T *)&g)->f10
         (the old field at offset N becomes the unified field at offset N),
       - for a scalar view in a MIXED global (void *, u8 *, ...) changes only the
         declaration and casts uses back to the old scalar type where the old
         type is not void * (so arithmetic keeps its meaning),
       - removes the file's local struct when nothing else uses it (or when it
         has the unified name and its field names are a subset of the unified
         ones).
  3. Verifies the file.  Attempt 1 is the clean rewrite.  If it fails and
     --no-cast-fallback is absent, attempt 2 also casts the bare uses of the
     global back to the old view type and the right hand side of assignments to
     the new type (the old local struct then stays).  If several globals share a
     file and the joint change fails, they are retried one at a time.
  4. Never modifies a file before its verification passed.  A kept change backs
     the original up under <out>/backup/ first.

The match run needs only the repository image data (extract/, asm/, layout/) that
tools/match.py finds by its own absolute path.  --root only moves where the
matched sources (src/matched and its include folder) are read and written.

usage
  python tools/applyunify.py [--root DIR] [--globals g_A,g_B | @file] [--limit N]
         [--jobs 4] [--out DIR] [--dry-run] [--no-verify] [--no-cast-fallback]
         [--tsv globals.tsv] [--structs unified_structs.h]
"""
import argparse
import collections
import concurrent.futures as cf
import difflib
import os
import re
import shutil
import sys
import tempfile
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import globalunify as gu  # noqa: E402
import protofix as pf  # noqa: E402

REPO = pf.ROOT
SCRATCH = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'scratch')
DEF_GU = SCRATCH + '/gu'
DEF_OUT = SCRATCH + '/applyunify'

GLOBAL_RE = gu.GLOBAL_RE
IDENT_RE = re.compile(r'[A-Za-z_]\w*')
INT_RE = re.compile(r'0[xX][0-9a-fA-F]+|\d+')

TYPE_MAP = {
    'u8': 'unsigned char', 'u16': 'unsigned short', 'u32': 'unsigned int',
    's8': 'signed char', 's16': 'signed short', 's32': 'signed int',
    'bool': 'unsigned char', 'BOOL': 'int', 'fx32': 'int', 'fx16': 'short',
    'f32': 'float', 'f64': 'double', 'u64': 'unsigned long long',
    's64': 'long long', 'fx64': 'long long', 'size_t': 'unsigned int',
}
BUILTIN_WORDS = {'unsigned', 'signed', 'char', 'short', 'int', 'long', 'float', 'double',
                 'void', 'const', 'volatile'}


def _load_scope(raw, m):
    """gu.load_scope that also reads the G_*.h headers this tool writes."""
    sc = gu.Scope()
    pat = r'^[ \t]*#[ \t]*include[ \t]+"([^"]*(?:Obj\d+|G_\w+)\.h)"'
    for im in re.finditer(pat, raw, re.M):
        pth = os.path.normpath(os.path.join(gu.ROOT, 'src', 'matched', 'include', os.path.basename(im.group(1))))
        key = (pth, os.path.getmtime(pth) if os.path.exists(pth) else 0)
        if key not in gu._INC_CACHE:
            try:
                r2 = open(pth, 'rb').read().decode('latin1')
                s2 = gu.Scope()
                gu.parse_defs(pf.mask(r2), s2)
                gu._INC_CACHE[key] = s2
            except OSError:
                gu._INC_CACHE[key] = None
        s2 = gu._INC_CACHE[key]
        if s2:
            sc.structs.update(s2.structs)
            sc.typedefs.update(s2.typedefs)
    gu.parse_defs(m, sc)
    return sc


gu.load_scope = _load_scope


class Skip(Exception):
    """A global (or one file/global pair) cannot be rewritten; str(e) is the reason."""


# ---------------------------------------------------------------------------
# unified structs
# ---------------------------------------------------------------------------

BLK_RE = re.compile(
    r'^struct (\w+) \{ /\* (\S+) (\S+), (\d+) views, (\w+)[^\n]*\*/\n(.*?)^\};\n'
    r'/\* extern struct (\w+) (\*?)(\S+?);\s+\((ptr|object) view\) \*/', re.S | re.M)


class Uni:
    """One unified struct (plain data)."""
    pass


def sanitize_body(body, sname):
    """Rewrite the field lines so the header needs no typedef.  Returns
    (new_body, forward_tags) or raises Skip."""
    out = []
    fwd = set()
    for line in body.split('\n'):
        if not line.strip():
            continue
        cm = ''
        mc = re.search(r'\s*/\*.*?\*/\s*$', line)
        if mc:
            cm = mc.group(0)
            line = line[:mc.start()]
        s = line.strip()
        if s.startswith('void (*'):
            out.append('    ' + s + cm.rstrip())
            continue
        mm = re.match(r'^(.*?)\s*(\w+)((?:\[[^\]]*\])*);$', s)
        if not mm:
            raise Skip('unparsable field line: ' + s[:60])
        ty, name, dims = mm.groups()
        words = re.findall(r'[A-Za-z_]\w*|\*', ty)
        isptr = '*' in words
        nw = []
        i = 0
        bad = None
        while i < len(words):
            w = words[i]
            if w == 'struct' and i + 1 < len(words):
                nw += ['struct', words[i + 1]]
                if isptr:
                    fwd.add(words[i + 1])
                i += 2
                continue
            if w == '*':
                nw.append('*')
            elif w in TYPE_MAP:
                nw.append(TYPE_MAP[w])
            elif w in BUILTIN_WORDS:
                nw.append(w)
            else:
                bad = w
                nw.append(w)
            i += 1
        if bad:
            if isptr:
                nw = ['void', '*']
            else:
                raise Skip('unknown field type ' + bad)
        t = ' '.join(nw).replace(' *', ' *').replace('* *', '**')
        t = re.sub(r'\*\s+\*', '**', t)
        out.append('    %s%s%s%s;%s' % (t, '' if t.endswith('*') else ' ', name, dims, cm.rstrip()))
    return '\n'.join(out), fwd


def parse_unified(path, tsv_rows):
    """name of global -> Uni.  Header names that clash with different text get a
    G_<region>_<addr> fallback name."""
    text = open(path, 'rb').read().decode('latin1')
    unis = {}
    by_struct = {}   # struct name -> body text of first claimant
    for m in BLK_RE.finditer(text):
        sname, gname, region, nviews, verdict, body, e_name, star, e_glob, view = m.groups()
        row = tsv_rows.get((region, gname))
        if row is None:
            continue
        u = Uni()
        u.gname, u.region, u.verdict = gname, region, verdict
        u.cls = 'ptr' if view == 'ptr' else 'obj'
        u.skip = None
        u.fwd = set()
        try:
            nb, fwd = sanitize_body(body, sname)
            u.fwd = fwd
            sc = gu.Scope()
            gu.parse_defs(pf.mask('struct %s {\n%s\n};\n' % (sname, nb)), sc)
            lay = gu.layout_of(sname, sc)
        except Skip as e:
            u.skip = str(e)
            nb, lay = body, None
        except gu.Unresolved as e:
            u.skip = 'unified layout unresolved: ' + str(e)
            nb, lay = body, None
        if lay is not None:
            prev = by_struct.get(sname)
            if prev is not None and prev != nb:
                addr = gname[2:] if GLOBAL_RE.match(gname) else gname
                sname = 'G_%s' % addr if region == 'arm9' else 'G_%s_%s' % (region, addr)
            by_struct.setdefault(sname, nb)
        u.sname, u.body = sname, nb
        u.entries = []
        u.size = lay.size if lay else 0
        if lay is not None:
            for (o, s, k, fmt, n, e, pad) in lay.leaves:
                if pad:
                    continue
                dims = [int(x) for x in re.findall(r'\[(\d+)\]', fmt)] if k == 'array' else []
                u.entries.append({'off': o, 'size': s, 'kind': k, 'name': n, 'elem': e, 'dims': dims, 'fmt': fmt})
        u.header = header_text(u) if lay is not None else None
        unis[(region, gname)] = u
    return unis


def _san_words(words, allow_unknown_ptr=True):
    """Sanitise a list of type tokens; None when a type cannot be spelled."""
    out = []
    i = 0
    while i < len(words):
        w = words[i]
        if w == '*':
            out.append('*')
        elif w in ('struct', 'union', 'enum') and i + 1 < len(words):
            out += [w, words[i + 1]]
            i += 1
        elif w in TYPE_MAP:
            out.append(TYPE_MAP[w])
        elif w in BUILTIN_WORDS:
            out.append(w)
        elif i + 1 < len(words) and words[i + 1] == '*':
            out.append('void')
        else:
            return None
        i += 1
    t = ' '.join(out)
    t = re.sub(r'\s+\*', ' *', t)
    t = re.sub(r'\*\s+\*', '**', t)
    return t


def fp_decl(spec, uname):
    toks = spec[3:].split(' ')
    k = None
    for j in range(len(toks) - 3):
        if toks[j] == '(' and toks[j + 1] == '*' and toks[j + 3] == ')':
            k = j
            break
    if k is None:
        return None
    ret = _san_words(toks[:k])
    params = toks[k + 4:]
    if ret is None or len(params) < 2 or params[0] != '(' or params[-1] != ')':
        return None
    inner = params[1:-1]
    if '(' in inner or ')' in inner:
        return None
    plist, cur = [], []
    for t in inner:
        if t == ',':
            plist.append(cur)
            cur = []
        else:
            cur.append(t)
    plist.append(cur)
    outp = []
    for pt in plist:
        if not pt:
            continue
        if len(pt) >= 2 and IDENT_RE.fullmatch(pt[-1]) and pt[-1] not in TYPE_MAP and                 pt[-1] not in BUILTIN_WORDS and pt[-2] not in ('struct', 'union', 'enum'):
            pt = pt[:-1]
        sp = _san_words(pt)
        if sp is None:
            return None
        outp.append(sp)
    return '%s (*%s)(%s)' % (ret, uname, ', '.join(outp))


def finalize_unified(u, views):
    """Give the function pointer fields their real signatures (taken from the
    views) and rebuild the header text."""
    changed = False
    for ent in u.entries:
        if ent['kind'] != 'fp':
            continue
        cnt = collections.Counter()
        for v in views:
            if v.layout is None:
                continue
            for lf in v.layout.leaves:
                if lf[0] == ent['off'] and lf[2] == 'fp':
                    d = fp_decl(lf[3], ent['name'])
                    if d:
                        cnt[d] += 1
        decl = cnt.most_common(1)[0][0] if cnt else 'void (*%s)()' % ent['name']
        pat = re.compile(r'^    void \(\*%s\)\(void\);.*$' % re.escape(ent['name']), re.M)
        u.body, n = pat.subn(lambda mm: '    ' + decl + ';', u.body)
        changed = changed or n
        for t in re.findall(r'struct (\w+)', decl):
            u.fwd.add(t)
    big = max([v.layout.size for v in views if v.layout is not None and v.cls != 'scalar'] or [0])
    if big > u.size:
        u.body += chr(10) + '    unsigned char pad_%X[0x%X];' % (u.size, big - u.size)
        u.size = big
        changed = True
    if changed:
        u.header = header_text(u)


def header_text(u):
    guard = 'ALETHEIA_%s_H' % re.sub(r'\W', '_', hname(u).upper())
    L = ['#ifndef ' + guard, '#define ' + guard, '/* %s (%s) */' % (u.gname, u.region)]
    for t in sorted(u.fwd - {u.sname}):
        L.append('struct %s;' % t)
    L.append('struct %s {' % u.sname)
    L.append(u.body)
    L.append('};')
    L.append('#endif')
    return '\n'.join(L) + '\n'


def hname(u):
    return u.sname if u.sname.startswith('G_') else 'G_' + u.sname


# ---------------------------------------------------------------------------
# text helpers
# ---------------------------------------------------------------------------

def skip_ws(m, i):
    n = len(m)
    while i < n and m[i] in ' \t\r\n':
        i += 1
    return i


def match_close(m, i, op, cl):
    d = 0
    n = len(m)
    while i < n:
        c = m[i]
        if c == op:
            d += 1
        elif c == cl:
            d -= 1
            if d == 0:
                return i
        i += 1
    return -1


def split_commas(m, s, e):
    """Split m[s:e] at depth-0 commas; returns list of (start, end)."""
    out, d, b = [], 0, s
    for i in range(s, e):
        c = m[i]
        if c in '([{':
            d += 1
        elif c in ')]}':
            d -= 1
        elif c == ',' and d == 0:
            out.append((b, i))
            b = i + 1
    out.append((b, e))
    return out


def lit_int(t):
    t = t.strip()
    if INT_RE.fullmatch(t):
        return int(t, 0)
    return None


# ---------------------------------------------------------------------------
# access rewriting
# ---------------------------------------------------------------------------

class Ctx:
    """Per file and global state during a rewrite."""
    pass


def old_leaf_table(layout):
    d = {}
    for lf in layout.leaves:
        d.setdefault(lf[4], lf)
    return d


def leaf_dims(lf):
    return [int(x) for x in re.findall(r'\[(\d+)\]', lf[3])] if lf[2] == 'array' else []


def parse_chain(m, p, table, prefixes):
    """m[p:] starts at the first member name.  Returns (leaf, end) for the longest
    old leaf reached.  Raises Skip."""
    best = None
    cand = ''
    q = p
    sep = ''
    while True:
        q2 = skip_ws(m, q)
        im = IDENT_RE.match(m, q2)
        if not im:
            break
        cand = cand + sep + im.group()
        q = im.end()
        if cand in table:
            best = (table[cand], q)
        r = skip_ws(m, q)
        if m.startswith('.', r):
            sep = '.'
            q = r + 1
            continue
        mm = re.compile(r'\[\s*(0[xX][0-9a-fA-F]+|\d+)\s*\]\s*\.').match(m, r)
        if mm:
            c2 = cand + '[%d]' % int(mm.group(1), 0)
            if any(pn.startswith(c2 + '.') for pn in prefixes):
                cand = c2
                sep = '.'
                q = mm.end()
                continue
        break
    if best is None:
        if cand and any(pn.startswith(cand + '.') or pn.startswith(cand + '[') for pn in prefixes):
            raise Skip('access to a nested struct member as a whole (%s)' % cand)
        raise Skip('field %s not in the old layout' % (cand or '?'))
    return best


def unified_for(uni, off, esize, edim):
    """Entry covering offset off for an access of element size esize."""
    for e in uni.entries:
        if e['off'] <= off < e['off'] + max(e['size'], 1):
            return e
    return None


def map_leaf(m, leaf, end, uni):
    """leaf: old leaf tuple, end: end of its name.  Returns (new_name_text, span_end)."""
    o, s, k, fmt, n, e, pad = leaf
    if pad:
        raise Skip('access to padding %s' % n)
    dims = leaf_dims(leaf)
    ents = {x['off']: x for x in uni.entries}
    r = skip_ws(m, end)
    if dims:
        if len(dims) > 1:
            raise Skip('multi-dimensional array field %s' % n)
        if m.startswith('[', r):
            c = match_close(m, r, '[', ']')
            if c < 0:
                raise Skip('unbalanced index')
            idx = lit_int(m[r + 1:c])
            if idx is not None:
                ab = o + idx * e
                ue = unified_for(uni, ab, e, 1)
                if ue is None:
                    raise Skip('no unified field at +0x%X (%s)' % (ab, n))
                if ue['off'] == ab and ue['size'] == e and not ue['dims']:
                    return ue['name'], c + 1, ue
                if ue['dims'] and len(ue['dims']) == 1 and ue['elem'] == e and (ab - ue['off']) % e == 0:
                    return '%s[%d]' % (ue['name'], (ab - ue['off']) // e), c + 1, ue
                raise Skip('indexed array element does not map (%s)' % n)
            ue = ents.get(o)
            if ue and ue['dims'] and len(ue['dims']) == 1 and ue['elem'] == e:
                return ue['name'], end, ue
            raise Skip('variable index into array field %s has no unified array' % n)
        ue = ents.get(o)
        if ue and ue['dims'] and ue['elem'] == e:
            return ue['name'], end, ue
        if ue and ue['size'] == s and not ue['dims']:
            return ue['name'], end, ue
        raise Skip('array field %s has no matching unified field' % n)
    ue = ents.get(o)
    if ue is None:
        raise Skip('no unified field at +0x%X (%s)' % (o, n))
    if ue['size'] == s:
        if ue['dims']:
            return ue['name'] + '[0]' if False else ue['name'], end
        return ue['name'], end, ue
    if ue['dims'] and len(ue['dims']) == 1 and ue['elem'] == s:
        return ue['name'] + '[0]', end, ue
    raise Skip('field %s size %d differs from unified field %s size %d' % (n, s, ue['name'], ue['size']))


CAST_BEFORE = re.compile(r'\(\s*\(\s*((?:struct\s+)?\w+)\s*\*\s*\)\s*(&?)\s*$')
DEREF_CAST_BEFORE = re.compile(r'\(\s*\*\s*\(\s*((?:struct\s+)?\w+)\s*\*\s*\)\s*&\s*$')
PAREN_AMP_BEFORE = re.compile(r'\(\s*&\s*$')


def words_to_tag(txt, scope):
    ws = txt.split()
    ty = gu.words_to_ty(ws, scope)
    if ty.kind != 'struct':
        raise Skip('cast type is not a struct')
    return ty.tag


def asm_spans(m):
    """Spans of asm { ... } bodies: symbol names there are left alone."""
    out = []
    for am in re.finditer(r'\basm\b', m):
        b = m.find('{', am.end())
        if b < 0 or ';' in m[am.end():b]:
            continue
        e = match_close(m, b, '{', '}')
        if e > 0:
            out.append((b, e))
    return out


def classify_uses(m, name, decl_spans):
    """Occurrence positions of name outside declaration spans."""
    out = []
    asms = asm_spans(m)
    for om in re.finditer(r'\b%s\b' % re.escape(name), m):
        i = om.start()
        if any(s <= i < e for s, e in decl_spans) or any(s <= i < e for s, e in asms):
            continue
        # a member of another struct
        k = i - 1
        while k >= 0 and m[k] in ' \t\r\n':
            k -= 1
        if k >= 1 and (m[k - 1:k + 1] == '->' or (m[k] == '.' and not (k >= 1 and m[k - 1] == '.'))):
            continue
        out.append(i)
    return out


def decl_edits(raw, m, name, newbase, cls, nl, keepdims=True):
    """Edits that replace the extern declaration(s) of name.  Returns (edits, spans, dimtext, base, stars)."""
    edits, spans = [], []
    found = []
    for em in gu.EXT_RE.finditer(m):
        s0, e0 = em.start(1), em.end(1)
        pieces = split_commas(m, s0, e0)
        hit = None
        for pi, (ps, pe) in enumerate(pieces):
            txt = m[ps:pe]
            if re.search(r'\b%s\b' % re.escape(name), txt):
                dm = re.match(r'^(.*?)((?:\*\s*)*)(%s)\s*((?:\[[^\]]*\]\s*)*)\s*$' % re.escape(name),
                              txt.strip(), re.S)
                if dm and (pi > 0 or True):
                    hit = (pi, dm)
                    break
        if hit is None:
            continue
        pi, dm = hit
        # base text: from piece 0
        p0 = m[pieces[0][0]:pieces[0][1]]
        r0 = raw[pieces[0][0]:pieces[0][1]]
        if pi == 0:
            base = dm.group(1)
        else:
            bm = re.match(r'^(.*?)((?:\*\s*)*[A-Za-z_]\w*\s*(?:\[[^\]]*\]\s*)*)\s*$', p0.strip(), re.S)
            base = bm.group(1) if bm else ''
        dims = dm.group(4).strip()
        found.append((em, pieces, pi, base.strip(), dm.group(2).count('*'), dims))
    if not found:
        raise Skip('declaration not found')
    first = None
    for em, pieces, pi, base, stars, dims in found:
        ls = raw.rfind(chr(10), 0, em.start()) + 1
        indent = re.match(r'[ 	]*', raw[ls:em.start()]).group(0)
        quals = ''.join(q + ' ' for q in re.findall(r'(const|volatile)', base))
        if cls == 'ptr':
            mine = 'extern %sstruct @@%s *%s;' % (quals, newbase, name)
        else:
            mine = 'extern %sstruct @@%s %s%s;' % (quals, newbase, name, dims if keepdims else '')
        others = []
        for k, (ps, pe) in enumerate(pieces):
            if k == pi:
                continue
            t = raw[ps:pe].strip()
            if k == 0:
                bm = re.match(r'^(.*?)((?:\*\s*)*[A-Za-z_]\w*\s*(?:\[[^\]]*\]\s*)*)$', t, re.S)
                t = bm.group(2) if bm else t
            others.append(t)
        rep = mine
        if others:
            btxt = re.sub(r'\s+', ' ', base).strip()
            rep += nl + indent + 'extern %s %s;' % (btxt, ', '.join(others))
        edits.append((em.start(), em.end(), rep))
        spans.append((em.start(), em.end()))
        if first is None:
            first = (base, stars, dims)
    return edits, spans, first


def find_struct_def(m, tag):
    """(start, end, typedef_names) of the file-scope definition of tag, or None."""
    for sm in re.finditer(r'(typedef\s+)?\b(struct|union)\s*(\w+)?\s*\{', m):
        if m.count('{', 0, sm.start()) != m.count('}', 0, sm.start()):
            continue
        b0 = sm.end() - 1
        b1 = gu.match_brace(m, b0)
        if b1 < 0:
            continue
        names = []
        end = b1 + 1
        if sm.group(1):
            e = m.find(';', b1)
            if e < 0:
                continue
            names = re.findall(r'[A-Za-z_]\w*', m[b1 + 1:e])
            end = e + 1
        else:
            e = m.find(';', b1)
            if e < 0 or m[b1 + 1:e].strip():
                continue
            end = e + 1
        key = sm.group(3) or ('_anon_' + (names[0] if names else str(sm.start())))
        if key == tag:
            return sm.start(), end, names
    return None


def count_refs(m, tag, tnames, span):
    n = 0
    pats = []
    if not tag.startswith('_anon_'):
        pats.append(r'\bstruct\s+%s\b' % re.escape(tag))
    for t in tnames:
        pats.append(r'\b%s\b' % re.escape(t))
    for p in pats:
        for om in re.finditer(p, m):
            if span and span[0] <= om.start() < span[1]:
                continue
            n += 1
    return n


def name_compat(layout, uni):
    ents = {e['off']: e for e in uni.entries}
    for (o, s, k, fmt, n, e, pad) in layout.leaves:
        if pad:
            continue
        if '.' in n or '[' in n:
            return False
        ue = ents.get(o)
        if ue is None or ue['name'] != n or ue['size'] != s:
            return False
    return True


# ---------------------------------------------------------------------------
# one global in one file
# ---------------------------------------------------------------------------

def norm_ty(t):
    return re.sub(r'\s+', '', t.replace('%s', ''))


def wrap_edits(edits, m, leaf, ue, head, send):
    """A pointer field whose unified type differs from the old one and that is
    dereferenced right away gets a cast back to the old type."""
    if leaf[2] != 'ptr' or ue is None or ue.get('fmt') is None:
        return
    if norm_ty(leaf[3]) == norm_ty(ue['fmt']):
        return
    r = skip_ws(m, send)
    if m.startswith('->', r) or m.startswith('[', r) or (m[r:r + 1] in ('+', '-') and m[r:r + 2] != '->'):
        t = leaf[3].replace('%s', '').strip()
        edits.append((head, head, '((%s)' % t))
        edits.append((send, send, ')'))


def other_field_idents(scope, tag):
    ids = set()
    for t, (isu, body) in scope.structs.items():
        if t == tag:
            continue
        ids.update(re.findall(r'[A-Za-z_]\w*', body))
    return ids


def rewrite_global(raw, m, scope, view, uni, fallback, nl, rename_all=False):
    """Edits (list of (s, e, text)) for one declared name; also info dict."""
    name = view.declname
    info = {'tags': set(), 'bare': 0, 'layout': view.layout, 'view': view}
    newbase = uni.sname
    scalar = view.cls == 'scalar'
    if scalar:
        if uni.cls == 'ptr' and view.dims:
            raise Skip('array view of a pointer-class global: %s' % view.text)
        if uni.cls == 'obj' and len(view.dims) > 1:
            raise Skip('multi-dimensional scalar view: %s' % view.text)
    edits, dspans, first = decl_edits(raw, m, name, newbase, uni.cls, nl, not scalar)
    uses = classify_uses(m, name, dspans)
    if scalar:
        edits += scalar_uses(raw, m, name, view, uni, uses, fallback)
        return edits, info
    table = old_leaf_table(view.layout)
    prefixes = list(table)
    handled = []
    for i in uses:
        e_end = i + len(name)
        before = m[max(0, i - 90):i]
        r = skip_ws(m, e_end)
        cm = CAST_BEFORE.search(before)
        dm = DEREF_CAST_BEFORE.search(before)
        tt = None
        if dm and m.startswith(')', r) and m.startswith('.', skip_ws(m, r + 1)):
            tt = dm.group(1)
            dot = skip_ws(m, r + 1)
            head_s = i - len(before) + dm.start()
            chain_p = dot + 1
        elif cm and m.startswith(')', r) and (m.startswith('->', skip_ws(m, r + 1)) or
                                               m.startswith('.', skip_ws(m, r + 1))):
            tt = cm.group(1)
            a2 = skip_ws(m, r + 1)
            kacc = '->' if m.startswith('->', a2) else '.'
            head_s = i - len(before) + cm.start()
            chain_p = a2 + len(kacc)
        if tt is not None:
            try:
                tg = words_to_tag(tt, scope)
                lay = gu.layout_of(tg, scope)
            except (Skip, gu.Unresolved) as ex:
                raise Skip('cast type %s unresolved: %s' % (tt, ex))
            tbl = old_leaf_table(lay)
            info['tags'].add(tg)
            leaf, lend = parse_chain(m, chain_p, tbl, list(tbl))
            newn, send, ue = map_leaf(m, leaf, lend, uni)
            rep = '%s%s%s' % (name, '->' if uni.cls == 'ptr' else '.', newn)
            edits.append((head_s, send, rep))
            wrap_edits(edits, m, leaf, ue, head_s, send)
            handled.append((head_s, send))
            continue
        # direct forms
        pos = None
        if uni.cls == 'ptr' and m.startswith('->', r) and not view.dims:
            pos = r + 2
        elif uni.cls == 'obj' and m.startswith('.', r) and not view.dims:
            pos = r + 1
        elif m.startswith('[', r):
            c = match_close(m, r, '[', ']')
            a2 = skip_ws(m, c + 1) if c > 0 else -1
            if c > 0 and m.startswith('.', a2):
                pos = a2 + 1
        if pos is not None:
            leaf, lend = parse_chain(m, pos, table, prefixes)
            newn, send, ue = map_leaf(m, leaf, lend, uni)
            fid = skip_ws(m, pos)
            edits.append((fid, send, newn))
            wrap_edits(edits, m, leaf, ue, i, send)
            handled.append((fid, send))
            continue
        # (&NAME)->f for object views
        pm = PAREN_AMP_BEFORE.search(before)
        if uni.cls == 'obj' and pm and m.startswith(')', r) and m.startswith('->', skip_ws(m, r + 1)):
            a2 = skip_ws(m, r + 1)
            leaf, lend = parse_chain(m, a2 + 2, table, prefixes)
            newn, send, ue = map_leaf(m, leaf, lend, uni)
            hs = i - len(before) + pm.start()
            edits.append((hs, send, '%s.%s' % (name, newn)))
            wrap_edits(edits, m, leaf, ue, hs, send)
            handled.append((hs, send))
            continue
        info['bare'] += 1
        if fallback:
            edits += bare_fallback(raw, m, name, view, uni, i)
    if rename_all:
        # the old struct name now means the unified struct: rename every
        # remaining member access made through variables of the old type
        firsts = {re.split(r'[.\[]', n)[0] for n in table if not gu.PAD_RE.match(n)}
        shared = firsts & other_field_idents(scope, view.tag)
        if shared:
            raise Skip('field name %s is also a member of another struct' % sorted(shared)[0])
        for om in re.finditer(r'(?:->|\.)\s*(%s)\b' % '|'.join(map(re.escape, sorted(firsts))), m):
            p0 = om.start(1)
            if any(a <= p0 < b for a, b in handled) or any(a <= p0 < b for a, b in dspans):
                continue
            leaf, lend = parse_chain(m, p0, table, prefixes)
            newn, send, ue = map_leaf(m, leaf, lend, uni)
            edits.append((p0, send, newn))
    return edits, info


def old_type_text(view):
    t = view.base + ' ' + '*' * view.stars
    return re.sub(r'\s+', ' ', t).replace(' *', ' *').strip()


def stmt_end(m, i):
    d = 0
    n = len(m)
    while i < n:
        c = m[i]
        if c in '([{':
            d += 1
        elif c in ')]}':
            d -= 1
            if d < 0:
                return i
        elif c == ';' and d == 0:
            return i
        elif c == ',' and d == 0:
            return i
        i += 1
    return -1


def bare_fallback(raw, m, name, view, uni, i):
    """Attempt-2 edits for one bare use at i."""
    e_end = i + len(name)
    r = skip_ws(m, e_end)
    # assignment: NAME = rhs  ->  NAME = (struct N *)(rhs)
    if m.startswith('=', r) and not m.startswith('==', r):
        se = stmt_end(m, r + 1)
        if se < 0:
            return []
        rhs = raw[r + 1:se].strip()
        if uni.cls != 'ptr':
            return []
        return [(r + 1, se, ' (struct @@%s *)(%s)' % (uni.sname, rhs))]
    before = m[max(0, i - 3):i].rstrip()
    if uni.cls == 'ptr':
        return [(i, e_end, '((%s)%s)' % (old_type_text(view), name))]
    if uni.cls == 'obj' and view.dims:
        return [(i, e_end, '((%s *)%s)' % (old_type_text(view), name))]
    if uni.cls == 'obj' and before.endswith('&') and not before.endswith('&&'):
        k = i - 1
        while m[k] in ' 	':
            k -= 1
        return [(k, e_end, '((%s *)&%s)' % (old_type_text(view), name))]
    return []


def scalar_uses(raw, m, name, view, uni, uses, fallback):
    """Casts back to the old scalar type for a MIXED global."""
    edits = []
    ptxt = old_type_text(view)
    if not view.dims and not (uni.cls == 'ptr' and view.stars >= 1):
        # plain scalar object over the unified storage: *(T *)&g keeps the
        # meaning for reads, writes, & and sizeof
        for i in uses:
            e_end = i + len(name)
            edits.append((i, e_end, '(*(%s *)&%s)' % (ptxt, name)))
        return edits
    base = re.sub(r'\b(const|volatile)\b', '', view.base).strip()
    is_void = (base == 'void' and view.stars == 1)
    for i in uses:
        e_end = i + len(name)
        r = skip_ws(m, e_end)
        before = m[max(0, i - 24):i]
        if re.search(r'sizeof\s*\(?\s*$', before):
            raise Skip('sizeof applied to the scalar view')
        lvalue = m.startswith('=', r) and not m.startswith('==', r)
        if lvalue:
            if fallback:
                se = stmt_end(m, r + 1)
                if se > 0:
                    rhs = raw[r + 1:se].strip()
                    if uni.cls == 'ptr':
                        edits.append((r + 1, se, ' (struct @@%s *)(%s)' % (uni.sname, rhs)))
            continue
        if uni.cls == 'ptr':
            amp = before.rstrip().endswith('&') and not before.rstrip().endswith('&&')
            if amp:
                k = i - 1
                while m[k] in ' \t':
                    k -= 1
                edits.append((k, e_end, '((%s *)&%s)' % (ptxt, name)))
                continue
            arith = bool(re.search(r'[+\-]\s*$', before) and not before.rstrip().endswith('->')) or \
                bool(re.match(r'\s*(\+|-(?!>))', m[r:r + 3]))
            if is_void and not arith:
                continue
            edits.append((i, e_end, '((%s)%s)' % (ptxt, name)))
        else:
            # object view over an array scalar view: cast the address
            elem = re.sub(r'\s+', ' ', view.base).strip()
            before_s = before.rstrip()
            if before_s.endswith('&') and not before_s.endswith('&&') and not m.startswith('[', r):
                raise Skip('address of the scalar array view')
            edits.append((i, e_end, '((%s *)&%s)' % (elem, name)))
    return edits


# ---------------------------------------------------------------------------
# a whole file
# ---------------------------------------------------------------------------

_GMASK_RE = re.compile(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'|'
                       r'^[ \t]*#[ \t]*(?!define\b)(?:[^\n]*\\\n)*[^\n]*', re.S | re.M)


def gmask(s):
    """Like protofix.mask, but the lines of #define stay visible (macro bodies
    use the globals too)."""
    return _GMASK_RE.sub(lambda mm: re.sub(r'[^\n]', ' ', mm.group(0)), s)


def apply_edits(text, edits):
    es = sorted(edits, key=lambda x: (x[0], x[1]))
    for a, b in zip(es, es[1:]):
        if b[0] < a[1]:
            raise Skip('overlapping edits')
    for s, e, r in reversed(es):
        text = text[:s] + r + text[e:]
    return text


def insert_includes(text, incs, nl):
    if not incs:
        return text
    m = pf.mask(text)
    # the raw text still has the #include lines; find the last top-level include
    last = None
    for im in re.finditer(r'^[ \t]*#[ \t]*include[^\n]*\n', text, re.M):
        last = im
    add = ''.join('#include "%s"%s' % (i, nl) for i in incs)
    if last is not None:
        pos = last.end()
        return text[:pos] + add + text[pos:]
    hm = re.match(r'\s*/\*.*?\*/[ \t]*\r?\n', text, re.S)
    pos = hm.end() if hm else 0
    tail = text[pos:]
    blank = tail.startswith(nl) or tail.startswith(chr(10))
    return text[:pos] + nl + add + ('' if blank else nl) + tail


class ClashSkip(Skip):
    def __init__(self, msg, key):
        Skip.__init__(self, msg)
        self.key = key


def rebuild(raw, globs, fallback, rel, root):
    """globs: list of (view, uni).  Returns new text."""
    text = raw
    for g in globs:
        # one global at a time: two globals may share one extern statement
        renames = set()
        while True:
            try:
                text = rebuild1(text, [g], fallback, rel, root, renames)
                break
            except ClashSkip as e:
                if e.key in renames:
                    raise
                renames.add(e.key)
    return text


def rebuild1(raw, globs, fallback, rel, root, renames):
    nl = '\r\n' if '\r\n' in raw else '\n'
    scope = gu.load_scope(raw, pf.mask(raw))
    m = gmask(raw)
    edits = []
    infos = []
    incs = []
    for view, uni in globs:
        e, info = rewrite_global(raw, m, scope, view, uni, fallback, nl, view.declname in renames)
        edits += e
        infos.append((view, uni, info))
        inc = os.path.relpath(os.path.join(root, 'src', 'matched', 'include', hname(uni) + '.h'),
                              os.path.dirname(os.path.join(root, rel))).replace(os.sep, '/')
        if inc not in incs:
            incs.append(inc)
    t1 = apply_edits(raw, edits)
    for view, uni, info in infos:
        tags = set(info['tags'])
        if view.cls != 'scalar' and view.tag:
            tags.add(view.tag)
        t1 = drop_old_struct(t1, view, uni, info, tags, nl, view.declname in renames)
    t1 = insert_includes(t1, [i for i in incs if i not in t1], nl)
    return t1.replace('@@', '')


def drop_old_struct(t1, view, uni, info, tags, nl, renamed):
    for tag in sorted(tags):
        m1 = pf.mask(t1)
        lay = info['layout']
        d = find_struct_def(m1, tag)
        if d is None:
            # defined by an included Obj header with the unified name
            if tag == uni.sname and re.fullmatch(r'Obj\d+', tag):
                im = re.search(r'^[ \t]*#[ \t]*include[ \t]+"(?:[^"\n]*/)?%s\.h"[ \t]*\r?\n' % re.escape(tag), t1, re.M)
                if im:
                    refs = count_refs(m1, tag, [], None)
                    if refs and not renamed and (lay is None or not name_compat(lay, uni)):
                        raise ClashSkip('name clash: struct %s from an include is still used with '
                                        'other field names' % tag, view.declname)
                    t1 = t1[:im.start()] + t1[im.end():]
            continue
        s, e, tn = d
        refs = count_refs(m1, tag, [], (s, e))
        refs_t = count_refs(m1, '_anon_', tn, (s, e)) if tn else 0
        if tag == uni.sname:
            if (refs or refs_t) and not renamed and (lay is None or not name_compat(lay, uni)):
                raise ClashSkip('name clash: local struct %s is still used with other field names' % tag,
                                view.declname)
        elif refs or refs_t:
            continue
        rep = ''
        if refs_t and tag == uni.sname:
            tail = re.search(r'\}\s*([^;]*);', m1[s:e])
            tl = tail.group(1) if tail else ''
            if '*' in tl or ',' in tl:
                raise Skip('typedef of struct %s still used' % tag)
            rep = 'typedef struct %s %s;' % (uni.sname, tn[0])
        # drop the definition with its line
        while e < len(t1) and t1[e] in ' \t':
            e += 1
        if t1.startswith('\r\n', e):
            e += 2
        elif t1.startswith('\n', e):
            e += 1
        ls = t1.rfind('\n', 0, s) + 1
        if t1[ls:s].strip() == '':
            s = ls
        if rep:
            t1 = t1[:s] + rep + nl + t1[e:]
            continue
        if t1[:s].endswith(nl + nl) and (t1.startswith(nl, e)):
            e += len(nl)
        t1 = t1[:s] + t1[e:]
    return t1


# ---------------------------------------------------------------------------
# verification
# ---------------------------------------------------------------------------

def stage_includes(text, realdir, mirdir, headers, root):
    """Copy what the file includes into the mirror tree."""
    for inc in re.findall(r'^[ \t]*#[ \t]*include[ \t]+"([^"\n]+)"', text, re.M):
        mp = os.path.normpath(os.path.join(mirdir, inc))
        base = os.path.basename(inc)
        if base in headers:
            os.makedirs(os.path.dirname(mp), exist_ok=True)
            with open(mp, 'wb') as f:
                f.write(headers[base].encode('latin1'))
            continue
        rp = os.path.normpath(os.path.join(realdir, inc))
        if os.path.isfile(rp) and not os.path.exists(mp):
            os.makedirs(os.path.dirname(mp), exist_ok=True)
            shutil.copyfile(rp, mp)


def evaluate2(fi, text, work, rel, root, headers, orig=None):
    mir = os.path.join(work, rel)
    mird = os.path.dirname(mir)
    os.makedirs(mird, exist_ok=True)
    stage_includes(text, os.path.dirname(os.path.join(root, rel)), mird, headers, root)
    with open(mir, 'wb') as f:
        f.write(text.encode('latin1'))
    g = pf.gcc_errors(mir)
    if orig is not None and (g - orig['gcc']):
        return {'c99': None, 'nolang': None, 'gcc': g}
    spec = pf.match_spec(fi, mir)
    return {'c99': pf.verdict(spec, 'c99'), 'nolang': pf.verdict(spec, None), 'gcc': g}


def worker_init():
    os.chdir(REPO)


def process_file(task):
    """task: dict(rel, root, globs=[(view, uni)], headers, opt).  Returns dict."""
    rel, root, opt = task['rel'], task['root'], task['opt']
    path = os.path.join(root, rel)
    res = {'rel': rel, 'rows': [], 'new': None, 'headers': {}, 'used': [], 'diff': ''}
    raw = open(path, 'rb').read().decode('latin1')
    headers = task['headers']
    work = tempfile.mkdtemp(prefix='au_', dir=opt['tmp'])
    try:
        fi = pf.parse_file(path, rel)
        orig = None
        if not opt['no_verify']:
            orig = evaluate2(fi, raw, work, rel, root, {}, None)

        def attempt(globs):
            """Returns (text or None, reason)."""
            last = None
            for fb in ([False, True] if opt['fallback'] else [False]):
                try:
                    t = rebuild(raw if not fb else raw, globs, fb, rel, root)
                except Skip as e:
                    last = str(e)
                    continue
                except Exception as e:  # keep going on a bug in one file
                    return None, 'internal error: %r' % (e,)
                if t == raw:
                    return None, 'no change'
                if opt['no_verify']:
                    return t, ''
                c = evaluate2(fi, t, work, rel, root, headers, orig)
                why = pf.compare_eval(orig, c)
                if why is None:
                    return t, ('cast fallback' if fb else '')
                last = why
            return None, last or 'unknown'

        globs = task['globs']
        t, why = attempt(globs)
        if t is not None:
            res['new'] = t
            res['used'] = [g[1].gname for g in globs]
            for v, u in globs:
                res['rows'].append((u.gname, 'applied', why))
        elif len(globs) > 1:
            # one at a time, cumulative
            cur_globs = []
            for g in globs:
                t2, why2 = attempt(cur_globs + [g])
                if t2 is not None:
                    cur_globs.append(g)
                    res['new'] = t2
                    res['rows'].append((g[1].gname, 'applied', why2))
                else:
                    res['rows'].append((g[1].gname, 'reverted', why2))
            res['used'] = [g[1].gname for g in cur_globs]
        else:
            res['rows'].append((globs[0][1].gname, 'reverted', why))
        if res['new'] is not None:
            res['diff'] = ''.join(difflib.unified_diff(raw.splitlines(True), res['new'].splitlines(True),
                                                       'a/' + rel, 'b/' + rel, n=1))
    except Exception as e:
        res['rows'] = [(g[1].gname, 'reverted', 'internal error: %r' % (e,)) for g in task['globs']]
        res['new'] = None
    finally:
        shutil.rmtree(work, ignore_errors=True)
    return res


# ---------------------------------------------------------------------------
# driver
# ---------------------------------------------------------------------------

def load_tsv(path):
    rows = {}
    for line in open(path, encoding='latin1').read().split('\n')[1:]:
        c = line.split('\t')
        if len(c) < 7 or c[4] not in ('SAME', 'MIXED') or not c[5]:
            continue
        rows[(c[1], c[0])] = {'name': c[0], 'region': c[1], 'verdict': c[4], 'struct': c[5],
                              'views': int(c[2])}
    return rows


def walk_matched(root):
    out = []
    for dp, dn, fn in os.walk(os.path.join(root, 'src', 'matched')):
        for f in fn:
            if f.endswith('.c'):
                out.append(os.path.join(dp, f))
    out.sort()
    return out


def collect_views(root, targets):
    """Views of the target globals: {(region, name): [view, ...]}."""
    gu.ROOT = root
    names = set()
    hexmap = collections.defaultdict(set)
    for (reg, n) in targets:
        names.add(n)
        if GLOBAL_RE.match(n):
            hexmap[n[2:].upper()].add(n)
    files = walk_matched(root)
    views = []
    stats = collections.Counter()
    tok = re.compile(rb'[A-Za-z_]\w*')
    for p in files:
        data = open(p, 'rb').read()
        if b'extern' not in data:
            continue
        ts = set(t.decode('latin1') for t in tok.findall(data))
        hit = bool(ts & names)
        if not hit:
            for t in ts:
                if len(t) == 10 and GLOBAL_RE.match(t) and t[2:].upper() in hexmap:
                    hit = True
                    break
        if not hit:
            continue
        rel = os.path.relpath(p, root).replace(os.sep, '/')
        try:
            gu.scan_file(p, rel, None, views, stats)
        except Exception as e:
            sys.stderr.write('scan error %s: %r\n' % (rel, e))
    for v in views:
        v.declname = v.name
    byname = collections.defaultdict(list)
    for v in views:
        byname[v.name].append(v)
    for name, vs in byname.items():
        known = {v.region or 'arm9' for v in vs if not v.rowless}
        for v in vs:
            if v.rowless:
                if len(known) == 1:
                    v.region = next(iter(known))
                else:
                    v.region = v.fregion if v.fregion.startswith('ov') and not known else 'arm9'
            elif not v.region:
                v.region = 'arm9'
    uniq = {}
    for v in views:
        uniq.setdefault((v.region, v.declname, v.file, v.text, v.lname), v)
    views = list(uniq.values())
    groups = collections.defaultdict(list)
    for v in views:
        groups[(v.region, v.addr or v.name)].append(v)
    out = {}
    for (reg, k), vs in groups.items():
        cnt = collections.Counter(v.name for v in vs)
        nm = sorted(cnt, key=lambda n: (0 if n.startswith('g_') else 1, -cnt[n], n))[0]
        if (reg, nm) in targets:
            for v in vs:
                if v.layout is not None:
                    v.layout = gu.Layout(v.layout.size, v.layout.align,
                                         [l[:6] + (bool(l[6]),) for l in v.layout.leaves])
            out[(reg, nm)] = vs
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--root', default=REPO)
    ap.add_argument('--globals')
    ap.add_argument('--limit', type=int, default=0)
    ap.add_argument('--jobs', type=int, default=4)
    ap.add_argument('--out', default=DEF_OUT)
    ap.add_argument('--dry-run', action='store_true')
    ap.add_argument('--no-verify', action='store_true')
    ap.add_argument('--no-cast-fallback', action='store_true')
    ap.add_argument('--tsv', default=DEF_GU + '/globals.tsv')
    ap.add_argument('--structs', default=DEF_GU + '/unified_structs.h')
    a = ap.parse_args()
    root = os.path.abspath(a.root)
    os.makedirs(a.out, exist_ok=True)
    os.chdir(REPO)
    t0 = time.time()
    rows = load_tsv(a.tsv)
    sel = None
    if a.globals:
        txt = a.globals
        if txt.startswith('@'):
            txt = open(txt[1:]).read().replace('\n', ',')
        sel = {x.strip() for x in txt.split(',') if x.strip()}
    keys = sorted(k for k in rows if sel is None or k[1] in sel)
    if a.limit:
        keys = keys[:a.limit]
    targets = {k: rows[k] for k in keys}
    unis_all = parse_unified(a.structs, targets)
    reasons = collections.Counter()
    grows = []   # (name, region, verdict, files, applied, reverted, skipped)
    frows = []   # (global, file, status, reason)
    unis = {}
    for k in keys:
        u = unis_all.get(k)
        if u is None:
            reasons['skipped: struct block missing in unified_structs.h'] += 1
            frows.append((k[1], '', 'skipped', 'struct block missing'))
            continue
        if u.skip:
            frows.append((k[1], '', 'skipped', u.skip))
            reasons['skipped: ' + re.sub(r'\d+', 'N', u.skip)[:60]] += 1
            continue
        unis[k] = u
    print('%d globals selected, %d with a usable unified struct' % (len(keys), len(unis)), flush=True)
    views = collect_views(root, set(unis))
    for k, u in unis.items():
        finalize_unified(u, views.get(k, []))
    hdrs = {}
    for k in sorted(unis):
        u = unis[k]
        prev = hdrs.setdefault(hname(u) + '.h', u.header)
        if prev != u.header:
            addr = k[1][2:] if GLOBAL_RE.match(k[1]) else k[1]
            u.sname = 'G_%s' % addr if k[0] == 'arm9' else 'G_%s_%s' % (k[0], addr)
            u.header = header_text(u)
            if hdrs.setdefault(hname(u) + '.h', u.header) != u.header:
                u.skip = 'header name %s is shared with a different layout' % hname(u)
                frows.append((k[1], '', 'skipped', u.skip))
                reasons['skipped: header name clash'] += 1
    unis = {k: u for k, u in unis.items() if not u.skip}
    views = {k: v for k, v in views.items() if k in unis}
    # tasks per file
    perfile = collections.defaultdict(list)
    counts = collections.defaultdict(collections.Counter)
    for k, vs in views.items():
        u = unis[k]
        for v in vs:
            perfile[v.file].append((v, u))
    headers_used = {}
    tasks = []
    tmp = os.path.join(a.out, 'work')
    os.makedirs(tmp, exist_ok=True)
    opt = {'no_verify': a.no_verify, 'fallback': not a.no_cast_fallback, 'tmp': tmp}
    for rel, gl in sorted(perfile.items()):
        # one view per (declared name); keep file order stable
        hd = {hname(u) + '.h': u.header for v, u in gl}
        tasks.append({'rel': rel, 'root': root, 'globs': gl, 'headers': hd, 'opt': opt})
    print('%d files to process, jobs %d' % (len(tasks), a.jobs), flush=True)
    changes = open(os.path.join(a.out, 'changes.diff'), 'w', encoding='latin1', newline='')
    backup = os.path.join(a.out, 'backup')
    nfiles_ok = 0
    inc_dir = os.path.join(root, 'src', 'matched', 'include')
    with cf.ProcessPoolExecutor(a.jobs, initializer=worker_init) as ex:
        for n, r in enumerate(ex.map(process_file, tasks, chunksize=1)):
            rel = r['rel']
            for (g, st, why) in r['rows']:
                if st == 'reverted' and why == 'no change':
                    st = 'unchanged'
                frows.append((g, rel, st, why))
                reg = None
                for kk in unis:
                    if kk[1] == g:
                        reg = kk
                        break
                counts[reg][st] += 1
                if st != 'applied':
                    reasons['%s: %s' % (st, re.sub(r'0x[0-9A-F]+|\d+', 'N', why)[:70])] += 1
                elif why:
                    reasons['applied (%s)' % why] += 1
                else:
                    reasons['applied'] += 1
            if r['new'] is not None and not a.dry_run and not a.no_verify:
                src = os.path.join(root, rel)
                bp = os.path.join(backup, rel)
                os.makedirs(os.path.dirname(bp), exist_ok=True)
                if not os.path.exists(bp):
                    shutil.copyfile(src, bp)
                os.makedirs(inc_dir, exist_ok=True)
                for hn in re.findall(r'^#include "[^"\n]*/(G_\w+\.h)"', r['new'], re.M):
                    hp = os.path.join(inc_dir, hn)
                    if not os.path.exists(hp):
                        with open(hp, 'wb') as f:
                            f.write(hdrs[hn].encode('latin1'))
                with open(src, 'wb') as f:
                    f.write(r['new'].encode('latin1'))
            if r['new'] is not None:
                nfiles_ok += 1
                changes.write(r['diff'])
            if (n + 1) % 50 == 0:
                print('%d/%d files, %d changed, %.0fs' % (n + 1, len(tasks), nfiles_ok, time.time() - t0),
                      flush=True)
    changes.close()
    shutil.rmtree(tmp, ignore_errors=True)
    # reports
    with open(os.path.join(a.out, 'files.tsv'), 'w', encoding='latin1', newline='') as f:
        f.write('global\tfile\tstatus\treason\n')
        for g, rel, st, why in frows:
            f.write('%s\t%s\t%s\t%s\n' % (g, rel, st, why.replace('\n', ' ').replace('\t', ' ')))
    pv = collections.Counter()
    gv = collections.Counter()
    fstat = collections.Counter()
    with open(os.path.join(a.out, 'globals.tsv'), 'w', newline='') as f:
        f.write('global\tregion\tverdict\tstruct\tfiles\tapplied\treverted\n')
        for k in keys:
            c = counts.get(k, collections.Counter())
            u = unis.get(k)
            ver = rows[k]['verdict']
            nf = len(views.get(k, []))
            f.write('%s\t%s\t%s\t%s\t%d\t%d\t%d\n' % (k[1], k[0], ver, u.sname if u else '', nf,
                                                        c['applied'], c['reverted']))
            gv[ver] += 1
            pv[(ver, 'files')] += nf
            pv[(ver, 'applied')] += c['applied']
            pv[(ver, 'reverted')] += c['reverted']
            if c['applied'] and not c['reverted']:
                pv[(ver, 'globals fully applied')] += 1
    with open(os.path.join(a.out, 'summary.md'), 'w') as f:
        f.write('# applyunify summary\n\nroot: %s%s\n\n' % (root, '  (dry run)' if a.dry_run else ''))
        f.write('| verdict | globals | file views | applied | reverted | globals fully applied |\n|---|---|---|---|---|---|\n')
        for ver in ('SAME', 'MIXED'):
            f.write('| %s | %d | %d | %d | %d | %d |\n' % (ver, gv[ver], pv[(ver, 'files')], pv[(ver, 'applied')],
                                                       pv[(ver, 'reverted')], pv[(ver, 'globals fully applied')]))
        f.write('\nFiles changed: %d.  Time %.0fs.\n\n## Reasons\n\n' % (nfiles_ok, time.time() - t0))
        for why, n in reasons.most_common():
            f.write('- %d  %s\n' % (n, why))
    print(open(os.path.join(a.out, 'summary.md')).read())


if __name__ == '__main__':
    main()
