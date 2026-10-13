#!/usr/bin/env python3
"""filesplit.py: propose how to split src/game files along original source file lines.

Every function whose literal pool carries a __FILE__ string is anchored to the
original source file it was compiled from (layout/file_anchors.txt, written by
tools/fileanchors.py).  When one src/game file holds functions anchored to more
than one file name, the file mixes several original files.  This tool proposes
where to cut.  It never edits src/; its output is a TSV plus a readable summary.

Method, per region (all src/game files of the region are one address-ordered
sequence, so a run of functions at the start or end of a file is judged against
its neighbour in the previous or next file):

1. Order the region's functions by address.  Mark each anchored function with
   its original file name.  A function anchored to two names is flagged.
2. A run of unanchored functions between two anchored functions of the same
   file stays in that file.  A run between anchored functions of different
   files A and B (A first in link order) holds one cut: functions before the
   cut are A, the rest B.  The cut is decided by evidence per function:
     (a) data ownership.  Every pool word of an anchored function that points
         into data (rodata, data, bss: any address above the last instruction
         of the region) is a point (address, file).  Addresses reached from two
         files are shared and dropped.  Link order puts each object's data in
         the same file order as its code, so the points split into sections
         wherever the file order resets.  A pool word of an unanchored function
         that lies between two points of the same file in one section is owned
         by that file.  This covers strings (the __FILE__ string sits inside
         its object's string pool), rodata, .data and .bss (d) alike.
     (b) static-call locality.  An unanchored function with no caller outside
         its region, whose callers (branches and pool-word function pointers)
         all belong to one file, belongs to that file.  Iterated to a fixpoint.
     (c) ISA change.  Only used when (a) and (b) leave several equally good
         cut positions: if exactly one of them is an ARM/Thumb transition, it
         is proposed with confidence "probable".
3. Confidence of a cut:
     certain    the anchored neighbours are adjacent, or the evidence allows
                exactly one cut position with no contradiction;
     probable   evidence allows several positions and the ISA change picks one;
     ambiguous  several positions remain (the range is reported), or the
                evidence contradicts itself.

Also reported: renames (a file whose only anchor name differs from its own
name) and anchors that sit in non-contiguous runs of a file (interleaved).

usage
  python tools/filesplit.py [--all | --file src/game/arm9/net_state.c ...]
         [--region R] [--tsv out.tsv] [--summary out.txt] [--renames out.tsv]
"""
import argparse
import bisect
import collections
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import protofix as pf  # noqa: E402

ANCHORS = os.path.join(ROOT, 'layout', 'file_anchors.txt')
TREE = os.path.join(ROOT, 'src', 'game')
HEX8 = re.compile(r'([0-9A-Fa-f]{8})$')
PART = re.compile(r'_p\d\d$')
STRUCT_TOK = re.compile(r'\bstruct\s+([A-Za-z_]\w*)')
GLUE = {}                    # region -> [(lo, hi, classes)] fragments proven one TU (tuboundary glue)
HINTS = {}                   # region -> {cut address: classes} located boundary hints (tuboundary)
STRUCTS = {}                 # (path, function name) -> struct tags used in signature and body


# --------------------------------------------------------------------------
# inputs
# --------------------------------------------------------------------------

def region_name(r):
    if r == 'arm9_main':
        return 'arm9'
    m = re.match(r'overlay_(\d+)$', r)
    if m:
        return 'ov%03d' % int(m.group(1))
    return r


def load_anchors():
    """{(region, function address): sorted list of file names}"""
    out = collections.defaultdict(set)
    with open(ANCHORS) as f:
        for line in f:
            if line.startswith('#') or not line.strip():
                continue
            p = line.split()
            if len(p) < 5:
                continue
            nm = re.split(r'[\\/]', p[4])[-1].lower()
            out[(region_name(p[2]), int(p[1], 16))].add(nm)
    return {k: sorted(v) for k, v in out.items()}


def src_files(only=None):
    """[(region, path)] of the .c files under src/game (scratch files left out)."""
    out = []
    for dp, _dn, fn in os.walk(TREE):
        for f in sorted(fn):
            if not f.endswith('.c') or f.startswith('_'):
                continue
            p = os.path.join(dp, f)
            rel = os.path.relpath(p, TREE).replace(os.sep, '/')
            out.append((rel.split('/')[0], p))
    out.sort(key=lambda x: x[1])
    return out


class Func:
    __slots__ = ('addr', 'name', 'path', 'region', 'files', 'isa', 'size',
                 'label', 'vote', 'vkind', 'assigned', 'conf', 'datarefs', 'ptrlocs',
                 'structs', 'extra', 'ordw', 'glued', 'hint')


def file_functions(region, path, shard_names):
    """[(name, address or None)] of the top-level definitions plus header list."""
    raw = open(path, 'rb').read().decode('latin1')
    h = pf.parse_header(raw)
    m = pf.mask(raw)
    tab = pf.depth_table(m)
    names = []
    for mm in pf.DECL_RE.finditer(m):
        if mm.group(5) != '{' or pf.depth_at(tab, mm.start()) != 0:
            continue
        names.append(mm.group(3))
        # end of the body: matching brace in the masked text
        d, q = 0, mm.end() - 1
        while q < len(m):
            c = m[q]
            if c == '{':
                d += 1
            elif c == '}':
                d -= 1
                if d == 0:
                    break
            q += 1
        STRUCTS[(path, mm.group(3))] = frozenset(STRUCT_TOK.findall(m[mm.start():q]))
    out, seen = [], set()
    for nm in names:
        am = HEX8.search(nm)
        if am:
            a = int(am.group(1), 16)
        elif nm in h['symbols']:
            a = h['symbols'][nm][0]
        else:
            a = shard_names.get((region, nm))
        if a is None or a in seen:
            if a is None:
                out.append((nm, None))
            continue
        seen.add(a)
        out.append((nm, a))
    return out


def shard_name_index():
    import restructure as rs
    out = {}
    for (reg, a), (_src, e) in rs.shard_index().items():
        nm = e.get('name')
        if nm:
            out[(reg, nm)] = a
    return out


def load_tuboundary(d):
    """Read tu_fragments.tsv (glue) and boundaries.tsv (boundary hints) written by tools/tuboundary.py."""
    fp = os.path.join(d, 'tu_fragments.tsv')
    if os.path.exists(fp):
        with open(fp) as f:
            next(f)
            for line in f:
                p = line.rstrip('\n').split('\t')
                if len(p) >= 8 and int(p[3]) >= 2 and p[7]:
                    GLUE.setdefault(region_name(p[0]), []).append((int(p[1], 16), int(p[2], 16), p[7]))
    bp = os.path.join(d, 'boundaries.tsv')
    if os.path.exists(bp):
        with open(bp) as f:
            next(f)
            for line in f:
                p = line.rstrip('\n').split('\t')
                if len(p) >= 7 and p[4] == 'B' and set(p[5].split(',')) - {'1', '5'}:
                    HINTS.setdefault(region_name(p[0]), {})[int(p[1], 16)] = p[5]


# --------------------------------------------------------------------------
# listing facts
# --------------------------------------------------------------------------

INSN = re.compile(r'^\t([a-z][\w.]*)\t(.*?)\s*/\* ([0-9A-F]{8})  ([0-9A-F]{2} [0-9A-F ]*)')
POOLL = re.compile(r'^pool_([0-9A-F]{8}):')
WORD = re.compile(r'^\t\.word\t0x([0-9A-F]{8})')
BSS = re.compile(r'\bbss 0x([0-9A-F]{8})\.\.')


class Facts:
    pass


def listing_facts(region):
    """Starts, calls, pool refs of one region from the generated listings."""
    import match
    fx = Facts()
    fx.starts = match.scan_listing(region)          # {addr: is_thumb}
    fx.order = sorted(fx.starts)
    fx.calls = []                                   # (site, target)
    fx.pools = []                                   # (site, pool word value)
    fx.code_end = 0
    fx.bss = None
    for path in match.listing_files(region):
        pending = None
        poolval = {}
        sites = []
        with open(path, errors='replace') as fh:
            for line in fh:
                if pending is not None:
                    mw = WORD.match(line)
                    if mw:
                        poolval[pending] = int(mw.group(1), 16)
                    pending = None
                mp = POOLL.match(line)
                if mp:
                    pending = int(mp.group(1), 16)
                    continue
                if line.startswith(' *') and fx.bss is None:
                    mb = BSS.search(line)
                    if mb:
                        fx.bss = int(mb.group(1), 16)
                    continue
                mi = INSN.match(line)
                if not mi:
                    continue
                mn, ops, addr = mi.group(1), mi.group(2), int(mi.group(3), 16)
                if mn.startswith('.'):
                    continue
                if addr > fx.code_end:
                    fx.code_end = addr
                mo = re.search(r'\bpool_([0-9A-F]{8})', ops)
                if mo and mn.startswith('ldr'):
                    sites.append((addr, int(mo.group(1), 16)))
                elif mn in ('bl', 'blx', 'b') or (mn[0] == 'b' and len(mn) <= 4 and mn not in ('bic', 'bx', 'bkpt')):
                    mc = re.match(r'func_([0-9A-F]{8})', ops)
                    if mc:
                        fx.calls.append((addr, int(mc.group(1), 16)))
        for a, pl in sites:
            if pl in poolval:
                fx.pools.append((a, poolval[pl]))
    return fx


def owner(fx, addr):
    i = bisect.bisect_right(fx.order, addr) - 1
    return fx.order[i] if i >= 0 else None


# --------------------------------------------------------------------------
# analysis
# --------------------------------------------------------------------------

class Cut:
    pass


def build_points(funcs, fx, order_of):
    """Sorted per-section data points [(addr, file)], conflicts removed."""
    by_addr = {}
    for f in funcs:
        lb = f.label or (f.vote if f.vkind == 'data' else None)
        if lb is None or lb not in order_of:
            continue
        for x in f.datarefs:
            by_addr.setdefault(x, set()).add(lb)
    pts = sorted((x, next(iter(s))) for x, s in by_addr.items() if len(s) == 1)
    shared = {x for x, s in by_addr.items() if len(s) > 1}
    # sections: a reset of the link-order index starts a new section
    seg, sid, prev = [], 0, -1
    for x, fl in pts:
        oi = order_of.get(fl, 0)
        if oi < prev:
            sid += 1
        prev = oi
        seg.append((x, fl, sid, oi))
    return seg, shared


def data_interval(f, seg, xs, shared):
    """(lo, hi) link-order bounds of the file that owns f, from its data pool words.

    A word between two points of one section is bounded by their files; words in
    the gap between two sections, or outside every section, give no bound."""
    lo, hi = -1, 1 << 30
    got = False
    for x in f.datarefs + f.ptrlocs:
        if x in shared:
            continue
        i = bisect.bisect_right(xs, x)
        l = seg[i - 1] if i > 0 else None
        h = seg[i] if i < len(seg) else None
        if l and l[0] == x:
            lo, hi, got = max(lo, l[3]), min(hi, l[3]), True
        elif l and h and l[2] == h[2]:
            lo, hi, got = max(lo, l[3]), min(hi, h[3]), True
    return (lo, hi) if got else None


def data_vote(iv, A, B, order_of):
    """File of the run's pair (A, B) that the interval proves, or None."""
    if iv is None:
        return None
    lo, hi = iv
    oa, ob = order_of[A], order_of[B]
    if lo > hi:
        return 'mixed'
    if hi <= oa:
        return A
    if lo >= ob:
        return B
    return None


def analyse_region(region, funcs, fx):
    """Fill label / vote / assigned / conf for the functions of one region.

    funcs is address ordered.  Returns the list of Cut objects."""
    ds = fx.bss if fx.bss else 1 << 32
    for f in funcs:
        f.datarefs = []
    pos = {f.addr: f for f in funcs}
    by_owner = collections.defaultdict(list)
    for site, val in fx.pools:
        if val > fx.code_end and val < 0x03000000:
            o = owner(fx, site)
            if o in pos:
                by_owner[o].append(val)
    for f in funcs:
        f.datarefs = sorted(set(by_owner.get(f.addr, ())))
    # function pointers stored in data: the table's location bounds the owner
    import match as _m
    rg = _m.find_region(funcs[0].addr, region)
    img, base = rg.data, rg.base
    ptr = collections.defaultdict(set)
    p0 = (fx.code_end + 4) & ~3
    for p in range(p0, min(base + len(img), fx.bss or (1 << 32)) - 3, 4):
        v = int.from_bytes(img[p - base:p - base + 4], 'little')
        t = v & ~1
        if t in pos and fx.starts.get(t) is not None and (v & 1) == (1 if fx.starts[t] else 0):
            ptr[t].add(p)
    for f in funcs:
        f.ptrlocs = sorted(ptr.get(f.addr, ()))
    # link order of files: first code address
    order_of = {}
    for f in funcs:
        if f.label is not None and f.label not in order_of:
            order_of[f.label] = len(order_of)
    seg = shared = xs = None
    # callers
    import match
    xin = match.xregion_calls()
    lo, hi = funcs[0].addr, fx.order[-1] + 0x10000
    callers = collections.defaultdict(set)
    for site, tgt in fx.calls:
        o = owner(fx, site)
        if o is not None and o != tgt:
            callers[tgt].add(o)
    for site, val in fx.pools:
        t = val & ~1
        if t in pos and (val & 1 or val == t):
            o = owner(fx, site)
            if o is not None and o != t:
                callers[t].add(o)
    public = {f.addr for f in funcs
              if any(not (lo <= s < hi) for s in xin.get(f.addr, ()))}
    # (a) data votes, per run between differently anchored functions; voted
    # functions add their own data words as points for the next round
    for f in funcs:
        f.vote, f.vkind = None, None
    anch0 = [i for i, f in enumerate(funcs) if f.label is not None]
    for _round in range(6):
        seg, shared = build_points(funcs, fx, order_of)
        xs = [s_[0] for s_ in seg]
        new = 0
        for i, j in zip(anch0, anch0[1:]):
            A, B = funcs[i].label, funcs[j].label
            if A == B:
                continue
            for f in funcs[i + 1:j]:
                if f.vkind == 'data':
                    continue
                v = data_vote(data_interval(f, seg, xs, shared), A, B, order_of)
                if v == 'mixed':
                    f.vkind = 'data-mixed'
                elif v is not None:
                    f.vote, f.vkind = v, 'data'
                    new += 1
        if not new:
            break
    # reverse call chains: F calls private helpers (sole caller F, no caller outside
    # the region) that already carry a file; F then votes for that file
    priv = collections.defaultdict(list)
    for g, cs in callers.items():
        if g in pos and g not in public and len(cs) == 1:
            priv[next(iter(cs))].append(g)
    changed = True
    while changed:
        changed = False
        for f in funcs:
            if f.label is not None or f.vote is not None or f.vkind == 'data-mixed':
                continue
            fl = None
            cs = callers.get(f.addr, ())
            if cs and f.addr not in public:
                fl = set()
                for c in cs:
                    cf = pos.get(c)
                    if cf is None:
                        fl = None
                        break
                    fl.add(cf.label or cf.vote)
                if fl is not None and (None in fl or len(fl) != 1):
                    fl = None
            if fl is None:
                gl = {pos[g].label or pos[g].vote for g in priv.get(f.addr, ())}
                if gl and None not in gl and len(gl) == 1:
                    fl = gl
            if fl:
                f.vote, f.vkind = next(iter(fl)), 'call'
                changed = True
    extra_evidence(funcs, fx, order_of, pos, ptr, callers, seg, shared, xs)
    # cuts
    cuts = []
    anch = [i for i, f in enumerate(funcs) if f.label is not None]
    for f in funcs:
        f.assigned, f.conf = None, None
    if not anch:
        return cuts
    for i in range(anch[0] + 1):
        funcs[i].assigned = funcs[anch[0]].label
    for i in range(anch[-1], len(funcs)):
        funcs[i].assigned = funcs[anch[-1]].label
    for a, b in zip(anch, anch[1:]):
        A, B = funcs[a].label, funcs[b].label
        run = funcs[a + 1:b]
        if A == B:
            for f in run:
                f.assigned = A
            funcs[a].assigned = A
            funcs[b].assigned = B
            continue
        c = decide(funcs[a], run, funcs[b])
        cuts.append(c)
        k = c.pick
        for j, f in enumerate(run):
            f.assigned = A if j < k else B
        funcs[a].assigned, funcs[b].assigned = A, B
    return cuts


def lbl(f):
    """File a function is known to belong to: its anchor, or a data proof."""
    return f.label or (f.vote if f.vkind == 'data' else None)


def section_of(x, seg, xs):
    """Section id of a data address, or None when it lies in no section's span."""
    i = bisect.bisect_right(xs, x)
    l = seg[i - 1] if i > 0 else None
    h = seg[i] if i < len(seg) else None
    if l and l[0] == x:
        return l[2]
    if l and h and l[2] == h[2]:
        return l[2]
    return None


def extra_evidence(funcs, fx, order_of, pos, ptr, callers, seg, shared, xs):
    """Soft evidence kinds: struct tags, callback groups, data order.

    Adds f.extra = [(kind, file)] to unlabeled functions and fx.order_words
    ({addr: {sid: (min, max)}} of private data words)."""
    for f in funcs:
        f.extra = []
        f.glued = False
        f.hint = None
    # glue fragments proven one TU (tuboundary classes 2 and 6): members share a file
    regn = funcs[0].region
    srt = [f.addr for f in funcs]
    for lo, hi, cl in GLUE.get(regn, ()):
        i, j = bisect.bisect_left(srt, lo), bisect.bisect_left(srt, hi)
        mem = funcs[i:j]
        for f in mem[1:]:
            f.glued = True
        ls = {lbl(f) or (f.vote if f.vkind == 'call' else None) for f in mem}
        ls.discard(None)
        if len(ls) == 1:
            x = next(iter(ls))
            for f in mem:
                if f.label is None and f.vote is None:
                    f.extra.append(('glue', x))
    for a_, cl in HINTS.get(regn, {}).items():
        k = bisect.bisect_left(srt, a_)
        if k < len(funcs) and funcs[k].addr == a_:
            funcs[k].hint = cl
    # struct tags owned by one file: at least two labeled functions use the tag and
    # every labeled function that uses it belongs to the same file
    users = collections.defaultdict(list)
    for f in funcs:
        lb = f.label or (f.vote if f.vkind in ('data', 'call') else None)
        if lb:
            for t in f.structs:
                users[t].append(lb)
    owned = {t: next(iter(set(v))) for t, v in users.items() if len(set(v)) == 1 and len(v) >= 2}
    for f in funcs:
        if f.label is not None or f.vote is not None:
            continue
        fs = {owned[t] for t in f.structs if t in owned}
        if len(fs) == 1:
            f.extra.append(('struct', next(iter(fs))))
    # callback groups: pointers in adjacent data slots, or pointers loaded by one function
    groups = []
    slots = sorted((p, t) for t, ps in ptr.items() for p in ps)
    cur = []
    for p, t in slots:
        if cur and p - cur[-1][0] > 4:
            groups.append({x[1] for x in cur})
            cur = []
        cur.append((p, t))
    if cur:
        groups.append({x[1] for x in cur})
    reg = collections.defaultdict(set)
    for site, val in fx.pools:
        t = val & ~1
        if t in pos and (val & 1 or val == t):
            o = owner(fx, site)
            if o is not None and o != t:
                reg[o].add(t)
    groups.extend(g for g in reg.values() if len(g) > 1)
    for g in groups:
        ls = {lbl(pos[a]) or (pos[a].vote if pos[a].vkind == 'call' else None) for a in g if a in pos}
        ls.discard(None)
        if len(ls) == 1:
            x = next(iter(ls))
            for a in g:
                f = pos.get(a)
                if f is not None and lbl(f) is None and not any(k == 'table' for k, _ in f.extra):
                    f.extra.append(('table', x))
    # data order: private data words of each function, per section
    cnt = collections.Counter()
    for f in funcs:
        for x in f.datarefs:
            cnt[x] += 1
    for f in funcs:
        d = {}
        for x in f.datarefs:
            if cnt[x] != 1 or x in shared:
                continue
            sid = section_of(x, seg, xs)
            if sid is None:
                continue
            lo, hi = d.get(sid, (x, x))
            d[sid] = (min(lo, x), max(hi, x))
        f.ordw = d


def isa_name(f):
    return {True: 'thumb', False: 'arm', None: '?'}[f.isa]


HARD, MED, SOFT = 0, 1, 2
KIND_CLASS = {'data': HARD, 'order': HARD, 'call': MED, 'glue': MED, 'glued-cut': MED, 'struct': SOFT, 'table': SOFT}


# call, glue and glued-cut all come from caller locality: one family, not independent
FAMILY = {'data': 'data', 'order': 'data', 'call': 'call', 'glue': 'call', 'glued-cut': 'call',
          'struct': 'struct', 'table': 'table'}
CASE = {'double3ddisp.c': 'double3Ddisp.c', 'ghttpencryption.c': 'ghttpEncryption.c'}


def run_items(A, B, run):
    """[(kind, index, file)] of every vote inside a run (index in the run)."""
    items = []
    for j, f in enumerate(run):
        if f.vote is not None and f.vkind in KIND_CLASS:
            items.append((f.vkind, j, f.vote))
        for kd, fl in f.extra:
            items.append((kd, j, fl))
    return items


def order_forbidden(fa, run, fb):
    """Positions k (cut before run[k]) that break 'all data of A precedes all data of B'.

    Uses private data words per section; the anchored neighbours count as A and B."""
    n = len(run)
    seq = [fa] + list(run) + [fb]
    pre = [None] * (n + 2)      # pre[i]: per-section max over seq[:i]
    suf = [None] * (n + 2)
    acc = {}
    for i in range(n + 1):
        for sid, (lo, hi) in (getattr(seq[i], 'ordw', None) or {}).items():
            acc[sid] = max(acc.get(sid, hi), hi)
        pre[i + 1] = dict(acc)
    acc = {}
    for i in range(n + 1, 0, -1):
        for sid, (lo, hi) in (getattr(seq[i], 'ordw', None) or {}).items():
            acc[sid] = min(acc.get(sid, lo), lo)
        suf[i] = dict(acc)
    bad = {}
    for k in range(n + 1):
        # cut before run[k] = before seq[k + 1]
        for sid, mx in pre[k + 1].items():
            mn = suf[k + 1].get(sid)
            if mn is not None and mx > mn:
                bad[k] = sid
                break
    return bad


def decide(fa, run, fb):
    A, B, n = fa.label, fb.label, len(run)
    c = Cut()
    c.a, c.b, c.run, c.fa, c.fb = A, B, run, fa, fb
    items = run_items(A, B, run)
    forb = order_forbidden(fa, run, fb)
    # violations at each position, by class
    viol = []
    for k in range(n + 1):
        v = []
        for kd, j, fl in items:
            if (fl == A and j >= k) or (fl == B and j < k):
                v.append((kd, j, fl))
        if k in forb:
            v.append(('order', -1, ''))
        if (run[k] if k < n else fb).glued:
            v.append(('glued-cut', k, ''))
        viol.append(v)
    cost = []
    for k in range(n + 1):
        cl = [0, 0, 0]
        for kd, _j, _f in viol[k]:
            cl[KIND_CLASS[kd]] += 1
        cost.append(tuple(cl))
    best = min(cost)
    ks = [k for k in range(n + 1) if cost[k] == best]
    c.viol = sum(best)
    c.third = [f for f in run if f.vote not in (None, A, B) and f.vkind in KIND_CLASS]
    c.range = (ks[0], ks[-1])
    ev = []
    for j, f in enumerate(run):
        ks_ = []
        if f.vote is not None and f.vkind in KIND_CLASS:
            ks_.append('%s->%s' % (f.vkind, f.vote))
        elif f.vkind == 'data-mixed':
            ks_.append('data->mixed')
        ks_ += ['%s->%s' % (kd, fl) for kd, fl in f.extra]
        if ks_:
            ev.append('%08X:%s' % (f.addr, '+'.join(ks_)))
    if forb:
        ev.append('order-excludes:%d positions' % len(forb))
    c.ev = ev
    # strength of the pins: what rules out the positions next to the chosen cut
    def pin(k, other):
        if other < 0 or other > n:
            return 'edge'
        kinds = {kd for kd, _j, _f in viol[other]}
        hard = [kd for kd in kinds if KIND_CLASS[kd] == HARD]
        if hard:
            return 'hard:' + '+'.join(sorted(hard))
        fams = {FAMILY[kd] for kd in kinds}
        if len(fams) >= 2:
            return 'multi:' + '+'.join(sorted(kinds))
        return 'weak:' + '+'.join(sorted(kinds)) if kinds else 'none'
    seqisa = [fa.isa] + [f.isa for f in run] + [fb.isa]
    tr = [k for k in ks if seqisa[k] != seqisa[k + 1]]
    c.pins = ''
    hk = [k for k in ks if (run[k] if k < n else fb).hint]
    hint_all = [(run[k].addr, run[k].hint) for k in range(n) if run[k].hint]
    if hint_all:
        c.ev.append('boundary-hints:' + ','.join('%08X=%s' % x for x in hint_all[:6]))
    if n == 0:
        c.conf, c.pick, c.how = 'certain', 0, 'anchored functions adjacent'
    elif sum(best) == 0 and len(ks) == 1:
        k = ks[0]
        pl, pr = pin(k, k - 1), pin(k, k + 1)
        c.pins = '%s | %s' % (pl, pr)
        strong = all(x == 'edge' or x.startswith('hard') for x in (pl, pr))
        if strong and not c.third:
            c.conf = 'certain'
            c.how = 'pins: before=%s after=%s' % (pl, pr)
        else:
            c.conf = 'likely'
            c.how = 'one position, weak pins: before=%s after=%s' % (pl, pr)
        c.pick = k
    elif sum(best) == 0 and len(hk) == 1:
        k = hk[0]
        c.conf, c.pick = 'likely', k
        c.how = 'boundary hint (tuboundary class %s) picks one of %d positions' % ((run[k] if k < n else fb).hint, len(ks))
    elif sum(best) == 0 and len(tr) == 1 and len(ks) <= 4:
        c.conf, c.pick = 'likely', tr[0]
        c.how = 'ISA change picks one of %d positions' % len(ks)
    else:
        c.conf = 'unsure'
        c.pick = tr[0] if (sum(best) == 0 and tr) else ks[0]
        c.how = ('evidence contradicts itself (%d violations)' % sum(best) if sum(best) else
                 '%d positions remain (%s..%s)' % (
                     len(ks), '%08X' % (run[ks[0]].addr if ks[0] < n else fb.addr),
                     '%08X' % (run[ks[-1]].addr if ks[-1] < n else fb.addr)))
    return c


# --------------------------------------------------------------------------
# driver
# --------------------------------------------------------------------------

def unit_key(path):
    rel = os.path.relpath(path, TREE).replace(os.sep, '/')
    d, f = os.path.split(rel)
    return d + '/' + PART.sub('', f[:-2])


def collect(regions_only=None, files_only=None):
    anchors = load_anchors()
    shard_names = shard_name_index()
    regions = collections.defaultdict(list)       # region -> [Func]
    files = collections.OrderedDict()             # path -> [Func]
    unresolved = 0
    for region, path in src_files():
        if regions_only and region not in regions_only:
            continue
        fl = []
        for nm, a in file_functions(region, path, shard_names):
            if a is None:
                unresolved += 1
                continue
            f = Func()
            f.addr, f.name, f.path, f.region = a, nm, path, region
            f.files = anchors.get((region, a), [])
            f.label = f.files[0] if len(f.files) == 1 else None
            f.isa = None
            f.size = None
            f.vote = f.vkind = f.assigned = f.conf = None
            f.structs = STRUCTS.get((path, nm), frozenset())
            f.extra = []
            fl.append(f)
        files[path] = fl
        regions[region].extend(fl)
    return anchors, regions, files, unresolved


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--all', action='store_true')
    ap.add_argument('--file', action='append', help='src/game file to analyse (repeatable)')
    ap.add_argument('--region', action='append')
    ap.add_argument('--tsv')
    ap.add_argument('--summary')
    ap.add_argument('--renames')
    ap.add_argument('--tuboundary', help='directory with tuboundary.py output (tu_fragments.tsv, boundaries.tsv): glue and boundary-hint evidence')
    ap.add_argument('--proposals', help='write PREFIX_cuts.tsv and PREFIX_files.tsv (scored split proposals)')
    a = ap.parse_args()
    want = None
    if a.file:
        want = set(os.path.abspath(p) for p in a.file)
    if a.tuboundary:
        load_tuboundary(a.tuboundary)
    regs_only = set(a.region) if a.region else None
    if want and not regs_only:
        regs_only = {os.path.relpath(p, TREE).replace(os.sep, '/').split('/')[0] for p in want}
    if not (a.all or want or regs_only):
        ap.error('give --all, --file or --region')
    anchors, regions, files, unresolved = collect(regs_only)
    import match
    all_cuts = {}
    for region, funcs in sorted(regions.items()):
        funcs.sort(key=lambda f: f.addr)
        uniq, seen = [], set()
        for f in funcs:
            if f.addr not in seen:
                seen.add(f.addr)
                uniq.append(f)
        funcs[:] = uniq
        for f, g in zip(funcs, funcs[1:]):
            f.size = g.addr - f.addr
        lab = [f.label for f in funcs if f.label]
        mixed_region = any(x != y for x, y in zip(lab, lab[1:]))
        if not lab:
            continue
        if want:
            if not any(f.path in want for f in funcs):
                continue
        if not mixed_region:
            for f in funcs:
                f.assigned = lab[0]
            continue
        fx = listing_facts(region)
        for f in funcs:
            t = fx.starts.get(f.addr)
            f.isa = t
            if f is funcs[-1]:
                nxt = bisect.bisect_right(fx.order, f.addr)
                f.size = (fx.order[nxt] - f.addr) if nxt < len(fx.order) else None
        all_cuts[region] = analyse_region(region, funcs, fx)
    report(a, regions, files, all_cuts, anchors, unresolved, want)


def stem_of(path):
    return PART.sub('', os.path.basename(path)[:-2])


_TREE_NAMES = None


def tree_names():
    global _TREE_NAMES
    if _TREE_NAMES is None:
        d = collections.defaultdict(list)
        for dp, _dn, fn in os.walk(TREE):
            for f in fn:
                if f.endswith('.c'):
                    d[f.lower()].append(os.path.relpath(os.path.join(dp, f), ROOT).replace(os.sep, '/'))
        _TREE_NAMES = d
    return _TREE_NAMES


def propose(rel, path, pieces, status, files, prop_rows, file_rows):
    """Cut rows and a file row for one mixed src/game file."""
    region = os.path.relpath(path, TREE).replace(os.sep, '/').split('/')[0]
    stem = stem_of(path).lower()
    names = tree_names()
    dests, pdesc = [], []
    for i, p in enumerate(pieces):
        nm = CASE.get(p['file'] or '?', p['file'] or '?')
        base = nm[:-2] if nm.endswith('.c') else nm
        if base.lower() == stem:
            d = 'keep ' + rel
        else:
            same = [x for x in names.get(nm.lower(), []) if x.split('/')[2] == region]
            if same:
                d = 'merge into ' + same[0]
            else:
                other = names.get(nm.lower(), [])
                d = 'new ' + os.path.dirname(rel) + '/' + nm
                if other:
                    d += ' (name also in ' + ', '.join(other[:2]) + ')'
        dests.append(d)
        s0, e0 = p['fs'][0], p['fs'][-1]
        pdesc.append('%s[%08X..%08X,%dfn]->%s' % (nm, s0.addr, e0.addr + (e0.size or 0), len(p['fs']), d))
    cert = [p['cut'].conf if p['cut'] is not None else 'unsure' for p in pieces[1:]]
    order = ['certain', 'likely', 'unsure']
    overall = max(cert, key=order.index) if cert else 'single'
    cert_at = ' '.join('%08X' % pieces[i]['fs'][0].addr for i in range(1, len(pieces))
                       if pieces[i]['cut'] is not None and pieces[i]['cut'].conf == 'certain')
    file_rows.append((rel, overall, len(pieces) - 1, cert_at, ' ; '.join(pdesc)))
    for i, p in enumerate(pieces[1:], 1):
        c = p['cut']
        pa = pieces[i - 1]
        s0 = p['fs'][0]
        if c is None:
            prop_rows.append((rel, i, '%08X' % s0.addr, '', pa['file'], p['file'], dests[i - 1], dests[i],
                              'unsure', 'cut sits at an edge of the anchored range; no run decided it', ''))
            continue
        lo = c.run[c.range[0]].addr if c.range[0] < len(c.run) else c.fb.addr
        hi = c.run[c.range[1]].addr if c.range[1] < len(c.run) else c.fb.addr
        rng = '%08X..%08X' % (lo, hi) if lo != hi else ''
        prop_rows.append((rel, i, '%08X' % s0.addr, rng, pa['file'], p['file'], dests[i - 1], dests[i],
                          c.conf, c.how, ' '.join(c.ev)))


def write_proposals(prefix, prop_rows, file_rows):
    with open(prefix + '_cuts.tsv', 'w') as f:
        f.write('\t'.join(['file', 'cut', 'cut_address', 'possible_range', 'from_original', 'to_original',
                           'from_destination', 'to_destination', 'certainty', 'reason', 'evidence']) + '\n')
        for r in prop_rows:
            f.write('\t'.join(str(x) for x in r) + '\n')
    with open(prefix + '_files.tsv', 'w') as f:
        f.write('\t'.join(['file', 'certainty', 'cuts', 'certain_cut_addresses', 'pieces']) + '\n')
        for r in file_rows:
            f.write('\t'.join(str(x) for x in r) + '\n')


def report(a, regions, files, all_cuts, anchors, unresolved, want):
    rows = []                      # TSV rows
    out = []
    cutof = {}                     # id of the function after the cut -> Cut
    for region, cuts in all_cuts.items():
        for c in cuts:
            nxt = c.run[c.pick] if c.pick < len(c.run) else c.fb
            cutof[id(nxt)] = c
    # per-file analysis
    mixed_files = []
    for path, fl in files.items():
        if want and path not in want:
            continue
        if 'unplaced' in path.replace(os.sep, '/'):
            continue
        names = {f.label for f in fl if f.label}
        multi = [f for f in fl if len(f.files) > 1]
        asg = [f.assigned for f in sorted(fl, key=lambda f: f.addr)]
        distinct = []
        for x in asg:
            if x and (not distinct or distinct[-1] != x):
                distinct.append(x)
        if len(names) > 1 or len(set(distinct)) > 1 or multi:
            mixed_files.append((path, sorted(fl, key=lambda f: f.addr), names))
    anch_mixed = [m for m in mixed_files if len(m[2]) > 1]
    certain_only, ambiguous_files, new_certain = [], [], 0
    prop_rows, file_rows = [], []
    unit_files = collections.defaultdict(list)
    for path in files:
        unit_files[unit_key(path)].append(path)
    for path, fl, names in mixed_files:
        rel = os.path.relpath(path, ROOT).replace(os.sep, '/')
        # pieces
        pieces, cur = [], None
        for f in fl:
            if cur is None or f.assigned != cur['file']:
                cur = {'file': f.assigned, 'fs': [], 'cut': cutof.get(id(f))}
                pieces.append(cur)
            cur['fs'].append(f)
        cuts = [p['cut'] for p in pieces[1:] if p['cut'] is not None]
        confs = [c.conf for c in cuts]
        # a boundary with no Cut object is a unit boundary decision seen from the other file
        status = 'single'
        if len(pieces) > 1:
            ext = sum(1 for p_ in pieces[1:] if p_['cut'] is None)
            status = 'certain' if all(x == 'certain' for x in confs) and not ext else 'unsure'
            if status == 'unsure' and 'unsure' not in confs and not ext:
                status = 'likely'
        if status == 'certain':
            certain_only.append(rel)
            new_certain += len(pieces) - 1
        elif status in ('unsure', 'likely'):
            ambiguous_files.append(rel)
        propose(rel, path, pieces, status, files, prop_rows, file_rows)
        out.append('%s  [%s]  anchors: %s' % (rel, status, ', '.join(sorted(names)) or '-'))
        for i, p in enumerate(pieces):
            s, e = p['fs'][0], p['fs'][-1]
            end = e.addr + (e.size or 0)
            out.append('  piece %d  %s  %08X..%08X  %d functions' % (i + 1, p['file'], s.addr, end, len(p['fs'])))
            if i > 0 and p['cut'] is not None:
                c = p['cut']
                out.append('    cut before %08X  %s  (%s)' % (s.addr, c.conf, c.how))
                if c.ev:
                    out.append('      evidence: ' + ', '.join(c.ev[:12]) + (' ...' if len(c.ev) > 12 else ''))
                if c.third:
                    out.append('      note: %d functions vote for a third file: %s' % (
                        len(c.third), ', '.join(sorted({f.vote for f in c.third}))))
            elif i > 0:
                out.append('    cut before %08X  (anchored neighbours in another file; decided in that file)' % s.addr)
            rows.append((rel, i + 1, p['file'], '%08X' % s.addr, '%08X' % end, len(p['fs']),
                         ' '.join(f.name for f in p['fs']),
                         (p['cut'].conf if i > 0 and p['cut'] else ('' if i == 0 else 'external')),
                         (p['cut'].how if i > 0 and p['cut'] else ''),
                         ' '.join(p['cut'].ev) if i > 0 and p['cut'] else ''))
        if multi:
            out.append('  note: %d functions are anchored to two or more files: %s' % (
                len(multi), ', '.join(f.name for f in multi[:5])))
        out.append('')
    # interleaving
    inter = []
    for region, funcs in regions.items():
        seq = [f.label for f in sorted(funcs, key=lambda f: f.addr) if f.label]
        grp = [x for i, x in enumerate(seq) if i == 0 or seq[i - 1] != x]
        dup = [k for k, v in collections.Counter(grp).items() if v > 1]
        if dup:
            inter.append('%s: %s' % (region, ', '.join(sorted(dup))))
    # renames
    ren = []
    for path, fl in files.items():
        if 'unplaced' in path.replace(os.sep, '/'):
            continue
        names = {f.label for f in fl if f.label}
        anchored = [f for f in fl if f.files]
        if len(names) == 1 and not any(len(f.files) > 1 for f in fl):
            n = next(iter(names))
            stem = PART.sub('', os.path.basename(path)[:-2]).lower()
            if stem != n[:-2] and stem != n.rsplit('.', 1)[0]:
                ren.append((os.path.relpath(path, ROOT).replace(os.sep, '/'), n, len(anchored), len(fl)))
    summ = []
    summ.append('files with anchors naming more than one original file: %d' % len(anch_mixed))
    summ.append('files whose proposed assignment has more than one file: %d' % len(mixed_files))
    summ.append('  only certain cuts: %d  (would create %d new pieces)' % (len(certain_only), new_certain))
    summ.append('  with likely or unsure cuts: %d' % len(ambiguous_files))
    summ.append('functions whose name could not be resolved to an address: %d' % unresolved)
    summ.append('files whose single anchor name differs from the file name (renames): %d' % len(ren))
    if inter:
        summ.append('regions where one file name reappears after another (interleaved anchors):')
        summ.extend('  ' + x for x in inter)
    text = '\n'.join(summ) + '\n\n' + '\n'.join(out)
    if a.summary:
        open(a.summary, 'w').write(text + '\n')
    else:
        print(text)
    if a.tsv:
        with open(a.tsv, 'w') as f:
            f.write('file\tpiece\toriginal_file\tstart\tend\tfunctions_n\tfunctions\tcut_confidence\tcut_reason\tevidence\n')
            for r in rows:
                f.write('\t'.join(str(x) for x in r) + '\n')
    if a.proposals:
        write_proposals(a.proposals, prop_rows, file_rows)
    if a.renames:
        with open(a.renames, 'w') as f:
            f.write('file\tanchor_name\tanchored_functions\tfunctions\n')
            for r in ren:
                f.write('\t'.join(str(x) for x in r) + '\n')
    if a.summary:
        print('\n'.join(summ))


if __name__ == '__main__':
    main()
