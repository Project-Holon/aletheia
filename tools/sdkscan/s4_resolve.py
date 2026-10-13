"""Stage 4: resolve candidates per start, write sdk_vendor.tsv (or val_<region>.tsv for validation)"""
import sys, pickle, json, collections, os
import os; R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))).replace(chr(92), '/')
sys.path.insert(0, R + '/tools')
import sdkobj as so
from libmatch import classify, read_archive, Obj
REGIONS_OUT = None if len(sys.argv) < 2 else sys.argv[1]   # 'twl' for validation
V = pickle.load(open('vendor.pkl', 'rb'))
S, hits = pickle.load(open('hits.pkl', 'rb'))
starts, names, file_of, codesz = pickle.load(open('starts.pkl', 'rb'))
regs = so.regions()
cat = json.load(open(R + '/layout/symbols_sdk.json'))
prof_rank = {p['profile']: i for i, p in enumerate(cat['profiles'])}
catalogue = {}
for s in ([] if os.environ.get('NOCAT') else cat['symbols']):
    catalogue[(s['region'], s['address'])] = s


def profile(rel):
    tree, build, variant, thumb, lib = classify(R + '/sdk/' + rel)
    if variant == 'TWL':
        variant = 'TWL.HYB' if '.HYB' in os.path.basename(rel) else 'TWL.LTD'
    return '%s/%s%s' % (build, variant, '.thumb' if thumb else '')


PR = {}


def prank(rel):
    if rel not in PR:
        p = profile(rel)
        PR[rel] = (prof_rank.get(p, 99), classify(R + '/sdk/' + rel)[0])
    return PR[rel]


AR = {}
import struct
VW = {}


def view_of(rel, mem):
    k = (rel, mem)
    if k not in VW:
        v = None
        try:
            if rel not in AR:
                AR[rel] = {}
                for n, b in read_archive(R + '/sdk/' + rel):
                    AR[rel].setdefault(n, b)
            b = AR[rel].get(mem)
            if b is not None:
                v = so.ObjView(Obj(mem, b))
        except Exception:
            v = None
        VW[k] = v
    return VW[k]



SECOFF = {}


def secoff(rel, mem, shndx):
    k = (rel, mem)
    if k not in SECOFF:
        d = {}
        v = view_of(rel, mem)
        if v is not None:
            off = 0
            for i, sec in enumerate(v.obj.sections):
                if sec[1] == 1 and (sec[2] & 4):
                    al = max(sec[8], 1)
                    off = (off + al - 1) // al * al
                    d[i] = off
                    off += sec[5]
        SECOFF[k] = d
    return SECOFF[k].get(shndx, 0)


by_reg = collections.defaultdict(list)
for i, (r, a, off) in enumerate(S):
    by_reg[r].append(i)
extent = {}
for r, l in by_reg.items():
    end = regs[r].base + len(regs[r].data)
    for j, i in enumerate(l):
        nx = S[l[j + 1]][1] if j + 1 < len(l) else end
        extent[i] = nx - S[i][1]

# cluster support: an object placed at one base (section base = address - value)
sup = collections.defaultdict(float)
seen = set()
for si, hl in hits.items():
    r, a, off = S[si]
    for mis, vi in hl:
        e = V[vi]
        rel, mem, sym, bind, cm, th, shndx, val, sz, body, mask, funcs = e
        oo = secoff(rel, mem, shndx) + val
        key = (r, rel, mem, a - oo)
        if (key, oo) in seen:
            continue
        seen.add((key, oo))
        sup[key] += min(sum(mask), 64) * (1.0 if mis == 0 else 0.5)


def own_w(e, mis):
    return min(sum(e[10]), 64) * (1.0 if mis == 0 else 0.5)


def libobj(rel, mem):
    return (classify(R + '/sdk/' + rel)[4], mem)


LO = {}


def lo(rel, mem):
    k = (rel, mem)
    if k not in LO:
        LO[k] = libobj(rel, mem)
    return LO[k]


# phase A: candidates per start, provisional ordering
CS = {}
for si in range(len(S)):
    r, a, off = S[si]
    hl = hits.get(si)
    if not hl:
        continue
    cs = []
    cg = catalogue.get((r, a))
    for mis, vi in hl:
        e = V[vi]
        rel, mem, sym, bind, cm, th, shndx, val, sz, body, mask, funcs = e
        key = (r, rel, mem, a - (secoff(rel, mem, shndx) + val))
        ca = 1 if (cg and cg['name'] == sym and cg['object'] == mem) else 0
        cs.append(dict(mis=mis, vi=vi, e=e, sup=sup[key], cat=ca, pr=prank(rel), conc=sum(mask), lo=lo(rel, mem), nbo=0))
    for c in cs:
        c['nb'] = c['sup'] - own_w(c['e'], c['mis'])
    CS[si] = cs


def keyA(c):
    return (c['mis'] > 0, -c['cat'], -c['sup'], -c['nbo'], -c.get('rs', 0), c['mis'])


def oo_of(c):
    e = c['e']
    return secoff(e[0], e[1], e[6]) + e[7]


def order(c):
    return (keyA(c), c['pr'], oo_of(c), c['e'][0], c['e'][2])


def sort_all():
    for cs in CS.values():
        cs.sort(key=order)


sort_all()
# phase B: strong starts (not weak, winner unique by object) give the neighbour object of every start
for rnd in range(2):
    strong = {}
    for si, cs in CS.items():
        w = cs[0]
        if w['conc'] >= 12 or w['nb'] > 0 or w['cat']:
            tie_objs = {c['lo'] for c in cs if keyA(c) == keyA(w)}
            if len(tie_objs) == 1:
                strong[si] = w['lo']
    for r, l in by_reg.items():
        sl = [i for i in l if i in strong]
        import bisect
        pos = [S[i][1] for i in sl]
        for i in l:
            if i not in CS:
                continue
            k = bisect.bisect_left(pos, S[i][1])
            prev = sl[k - 1] if k > 0 else None
            nxt = sl[k + 1] if k + 1 < len(sl) and sl[k] == i else (sl[k] if k < len(sl) and sl[k] != i else None)
            if k < len(sl) and sl[k] == i:
                nxt = sl[k + 1] if k + 1 < len(sl) else None
            po = strong.get(prev) if prev is not None else None
            no = strong.get(nxt) if nxt is not None else None
            for c in CS[i]:
                c['nbo'] = (1 if po == c['lo'] else 0) + (1 if no == c['lo'] else 0)
    sort_all()

known = collections.defaultdict(set)
for s_ in ([] if os.environ.get('NOCAT') else cat['symbols']):
    known[s_['name']].add(s_['address'] & ~1)
BR_ARM = {1, 15, 28, 29}
BR_THM = {10, 16, 30}


def relscore(c, si):
    r, a, off = S[si]
    e = c['e']
    rel, mem, sym, bind, cm, th, shndx, val, sz, body, mask, funcs = e
    v = view_of(rel, mem)
    if v is None:
        return 0
    dd = regs[r].data
    sc = 0
    for roff, rt, symidx, add in v.relocs.get(shndx, ()):
        if not (val <= roff < val + sz) or symidx >= len(v.syms):
            continue
        nm, sv, ssz, styp, sbind, sshndx = v.syms[symidx]
        if styp == 3 or not nm or nm not in known:
            continue
        o = roff - val
        io = off + o
        if io + 4 > len(dd):
            continue
        if rt == 2:
            t = (struct.unpack_from('<I', dd, io)[0] - struct.unpack_from('<I', body, o)[0]) & 0xFFFFFFFF
        elif rt in BR_ARM:
            t = so.arm_branch_target(struct.unpack_from('<I', dd, io)[0], a + o)[0]
        elif rt in BR_THM:
            t = so.thumb_bl_target(bytes(dd[io:io + 4]), a + o)[0]
        else:
            continue
        sc += 1 if (t & ~1) in known[nm] else -1
    return sc


def add_rs():
    for si, cs in CS.items():
        w = cs[0]
        grp = [c for c in cs if keyA(c) == keyA(w)]
        if len({(c['lo'], c['e'][2]) for c in grp}) > 1:
            for c in grp:
                c['rs'] = relscore(c, si)

add_rs()
sort_all()
for si, cs in CS.items():
    w = cs[0]
    if w['conc'] >= 12 and len({(c['lo'], c['e'][2]) for c in cs if keyA(c) == keyA(w)}) == 1:
        known[w['e'][2]].add(S[si][1] & ~1)
for si, cs in CS.items():
    for c in cs:
        c.pop('rs', None)
add_rs()
sort_all()
# phase C: identical-bytes siblings inside one object take the object's symbols in section order
last = {}
rows = {}
for r, l in by_reg.items():
    for si in l:
        cs = CS.get(si)
        if not cs:
            continue
        w = cs[0]
        grp = [c for c in cs if c['lo'] == w['lo'] and keyA(c) == keyA(w) and c['e'][0] == w['e'][0]]
        # same keyA across symbols of one object and one archive: a family of identical functions
        syms = {}
        for c in grp:
            syms.setdefault((c['e'][2], c['e'][7]), c)
        if len(syms) > 1:
            lk = (r, w['lo'])
            cand = sorted(syms.values(), key=oo_of)
            pick = None
            for c in cand:
                if oo_of(c) > last.get(lk, -1):
                    pick = c
                    break
            if pick is None:
                pick = cand[0]
            w = pick
            # keep the chosen row first
            cs.remove(w)
            cs.insert(0, w)
            w['family'] = True
        last[(r, w['lo'])] = oo_of(w)
        rows[si] = (w, cs)


DW = {}


def dwarf_src(rel, mem):
    k = (rel, mem)
    if k in DW:
        return DW[k]
    src = None
    try:
        if rel not in AR:
            AR[rel] = {}
            for n, b in read_archive(R + '/sdk/' + rel):
                AR[rel].setdefault(n, b)
        b = AR[rel].get(mem)
        if b is not None:
            o = Obj(mem, b)
            v = so.ObjView(o)
            d = so.dwarf_of(v)
            for t in d.top:
                if t.tag == 0x11 and 3 in t.attrs:
                    src = t.attrs[3]
                    break
    except Exception:
        src = None
    DW[k] = src
    return src


def ab(rel):
    return os.path.basename(rel)


out = []
dis = []
for si, (r, a, off) in enumerate(S):
    if REGIONS_OUT is None and r == 'twl':
        continue
    if REGIONS_OUT is not None and r != REGIONS_OUT:
        continue
    nm = names.get((r, a)) or 'func_%08X' % a
    ext = extent[si]
    cz = codesz.get((r, a), 0)
    f = file_of.get((r, a), '-')
    cg = catalogue.get((r, a))
    cgs = ('%s:%s:%s' % (cg['lib'].split('/')[-1], cg['object'], cg['name'])) if cg else ''
    row = dict(address='0x%08X' % a, region=r, our_name=nm, size_code=cz, extent=ext, arch='', obj='', sym='', link='',
               mis='', vsize='', comment='', dwarf='', flags='', ncand=0, allc='', file=f, cat=cgs, support='')
    rw = rows.get(si)
    if rw is None:
        row['flags'] = 'NO_MATCH'
        out.append((si, row, None))
        if cg:
            dis.append((r, a, nm, cgs, 'no vendor hit'))
        continue
    w, cs = rw
    e = w['e']
    rel, mem, sym, bind, cm, th, shndx, val, sz, body, mask, funcs = e
    flags = []
    weak = w['conc'] < 12
    if weak and w['nb'] <= 0 and not w['cat'] and w['nbo'] < 2:
        row['flags'] = 'NO_MATCH,WEAK_UNSUPPORTED'
        row['ncand'] = len({(c['e'][1], c['e'][2]) for c in cs})
        row['allc'] = ';'.join(sorted({'%s:%s:%s' % (ab(c['e'][0]), c['e'][1], c['e'][2]) for c in cs}))[:300]
        out.append((si, row, None))
        if cg:
            dis.append((r, a, nm, cgs, 'weak/no support'))
        continue
    base = 'NEAR' if w['mis'] > 0 else 'OK'
    wk = (mem, sym)
    tie = [c for c in cs if c['lo'] != w['lo'] and keyA(c) == keyA(w)]
    weaker = [c for c in cs if c['lo'] != w['lo'] and (c['mis'] > 0) == (w['mis'] > 0)
              and c['mis'] == w['mis'] and keyA(c) != keyA(w)]
    if w.get('family'):
        flags.append('by_order')
    if tie:
        flags.append('AMBIGUOUS')
    if weaker:
        if any(c['cat'] < w['cat'] for c in weaker):
            flags.append('by_catalogue')
        else:
            flags.append('by_neighbour_object')
    if weak:
        flags.append('WEAK_SMALL')
    if ext - sz >= 32:
        flags.append('vendor_shorter_than_extent')
    if sz > ext:
        flags.append('vendor_longer_than_extent')
    eq = [c for c in cs if c['mis'] == w['mis']]
    allc = []
    for c in eq:
        t = '%s:%s:%s' % (ab(c['e'][0]), c['e'][1], c['e'][2])
        if t not in allc:
            allc.append(t)
    ncand = len({(c['e'][1], c['e'][2]) for c in eq})
    ds = dwarf_src(rel, mem)
    if ds is None:
        for c in eq:
            if c['e'][1] == mem:
                ds = dwarf_src(c['e'][0], mem)
                if ds:
                    break
    row.update(arch=rel, obj=mem, sym=sym, link=bind, mis=w['mis'], vsize=sz, comment=cm or '', dwarf=ds or '',
               flags=','.join([base] + flags), ncand=ncand,
               allc=';'.join(allc[:12]) + (';...' if len(allc) > 12 else ''), support=int(w['nb']))
    if cg and (cg['name'] != sym or cg['object'] != mem):
        dis.append((r, a, nm, cgs, 'mine %s:%s:%s' % (ab(rel), mem, sym)))
    out.append((si, row, w))
pickle.dump((out, dis), open('resolved%s.pkl' % (REGIONS_OUT or ''), 'wb'))
cols = ['address', 'region', 'our_name', 'our_size_code', 'our_extent', 'vendor_archive', 'object', 'vendor_symbol', 'linkage',
        'bytes_differing', 'vendor_size', 'comment', 'dwarf_source', 'flags', 'n_candidates', 'all_candidates', 'our_file',
        'catalogue', 'neighbour_support']
keys = ['address', 'region', 'our_name', 'size_code', 'extent', 'arch', 'obj', 'sym', 'link', 'mis', 'vsize', 'comment', 'dwarf',
        'flags', 'ncand', 'allc', 'file', 'cat', 'support']
fn = 'sdk_vendor.tsv' if REGIONS_OUT is None else 'val_%s.tsv' % REGIONS_OUT
with open(fn, 'w', newline='\n') as fh:
    fh.write('\t'.join(cols) + '\n')
    for si, row, w in out:
        fh.write('\t'.join(str(row[k]) for k in keys) + '\n')
print(len(out), 'rows', sum(1 for _, r, _ in out if r['arch']), 'with vendor', len(dis), 'catalogue disagreements')
if os.environ.get('DBG'):
    for si,(r,a,off) in enumerate(S):
        if r=='arm9' and a in (0x020808F4,0x02080908):
            for c in CS[si][:40]:
                print(hex(a),c['e'][2],c['e'][7],c['e'][0][-22:],keyA(c),c.get('rs'),c['nbo'])
