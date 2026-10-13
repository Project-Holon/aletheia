"""Stage 5: objects table, renames, mixes, boundary cuts. Reads resolved.pkl."""
import sys, pickle, collections, os, re, csv
import os; R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))).replace(chr(92), '/')
sys.path.insert(0, R + '/tools')
from libmatch import classify
out, dis = pickle.load(open('resolved.pkl', 'rb'))
rows = [r for _, r, _ in out]
W = {r['address'] + r['region']: w for _, r, w in out}
# only rows with a vendor identification
for r in rows:
    r['_addr'] = int(r['address'], 16)
    r['_ok'] = bool(r['obj'])
    r['_lib'] = classify(R + '/sdk/' + r['arch'])[4] if r['arch'] else ''
_dg = collections.defaultdict(list)
for r in rows:
    if r['_ok'] and r['link'] == 'global':
        _dg[(r['region'], r['obj'], r['sym'])].append(r)
for v in _dg.values():
    if len(v) > 1:
        for r in v:
            r['flags'] += ',DUP_GLOBAL'
bykey = collections.defaultdict(list)
for r in rows:
    if r['_ok']:
        bykey[(r['region'], r['_lib'], r['obj'])].append(r)
# split into instances at repeated symbols
instances = []
reg_rows = collections.defaultdict(list)
for r in rows:
    reg_rows[r['region']].append(r)
for l in reg_rows.values():
    l.sort(key=lambda r: r['_addr'])
import bisect
matched_addr = {}
for reg, l in reg_rows.items():
    matched_addr[reg] = [(r['_addr'], (r['_lib'], r['obj'])) for r in l if r['_ok'] and not r['flags'].endswith('WEAK_SMALL') and 'WEAK_SMALL' not in r['flags']]
for k, l in bykey.items():
    reg = k[0]
    l.sort(key=lambda r: r['_addr'])
    ma = matched_addr[reg]
    pos = [x[0] for x in ma]
    cur = []
    seen = set()
    for r in l:
        split = False
        if r['sym'] in seen:
            split = True
        elif cur:
            i = bisect.bisect_right(pos, cur[-1]['_addr'])
            j = bisect.bisect_left(pos, r['_addr'])
            for q in range(i, j):
                if ma[q][1] != (k[1], k[2]):
                    split = True
                    break
        if split:
            instances.append((k, cur))
            cur = []
            seen = set()
        cur.append(r)
        seen.add(r['sym'])
    if cur:
        instances.append((k, cur))
inst_of = {}
objrows = []
nfun = {}
import pickle as _p
V = None
for (reg, lib, mem), l in instances:
    lo = l[0]['_addr']
    hi = l[-1]['_addr'] + int(l[-1]['extent'])
    ids = {id(x) for x in l}
    gap = [x for x in reg_rows[reg] if lo <= x['_addr'] < hi and id(x) not in ids]
    files = sorted({x['file'] for x in l})
    comp = collections.Counter(x['comment'] for x in l).most_common(1)[0][0]
    dw = collections.Counter(x['dwarf'] for x in l if x['dwarf']).most_common(1)
    conc_ok = sum(1 for x in l if 'WEAK_SMALL' not in x['flags'] and x['flags'].startswith('OK'))
    near = sum(1 for x in l if x['flags'].startswith('NEAR'))
    conf0 = 'HIGH' if conc_ok >= 1 and len(l) >= 1 and any(int(x['vsize']) >= 32 and x['flags'].startswith('OK') for x in l) else 'LOW'
    conf = 'LOW' if (len(l) <= 2 and any('DUP_GLOBAL' in x['flags'] for x in l)) else conf0
    iid = (reg, lib, mem, lo)
    for x in l:
        inst_of[x['address'] + x['region']] = iid
    objrows.append(dict(library=lib, object=mem, region=reg, n_funcs=len(l), addr_lo='0x%08X' % lo, addr_hi='0x%08X' % hi,
                        gap=','.join('%08X' % x['_addr'] for x in gap), n_files=len(files), files=','.join(files),
                        compiler=comp, dwarf=dw[0][0] if dw else '', n_near=near, confidence=conf,
                        gap_nomatch=sum(1 for x in gap if not x['_ok']), _lo=lo, _hi=hi, _l=l, _gap=gap, _iid=iid))
objrows.sort(key=lambda o: (o['region'], o['_lo']))
# low-confidence instances: tiny weak evidence and no catalogue row
nlow = 0
for o in objrows:
    if o['confidence'] == 'LOW' and not any(x['cat'] for x in o['_l']):
        for x in o['_l']:
            x['flags'] += ',LOW_CONFIDENCE'
            nlow += 1
print('low-confidence rows flagged', nlow)
vcols = ['address', 'region', 'our_name', 'our_size_code', 'our_extent', 'vendor_archive', 'object', 'vendor_symbol', 'linkage',
         'bytes_differing', 'vendor_size', 'comment', 'dwarf_source', 'flags', 'n_candidates', 'all_candidates', 'our_file',
         'catalogue', 'neighbour_support']
vkeys = ['address', 'region', 'our_name', 'size_code', 'extent', 'arch', 'obj', 'sym', 'link', 'mis', 'vsize', 'comment', 'dwarf',
         'flags', 'ncand', 'allc', 'file', 'cat', 'support']
with open('sdk_vendor.tsv', 'w', newline=chr(10)) as fh:
    fh.write(chr(9).join(vcols) + chr(10))
    for r in rows:
        fh.write(chr(9).join(str(r[k]) for k in vkeys) + chr(10))

cols = ['library', 'object', 'n_funcs', 'addr_lo', 'addr_hi', 'contiguous_gap_funcs_other_obj', 'n_files', 'our_files', 'compiler',
        'region', 'dwarf_source', 'n_near', 'confidence', 'n_gap_unmatched']
keys = ['library', 'object', 'n_funcs', 'addr_lo', 'addr_hi', 'gap', 'n_files', 'files', 'compiler', 'region', 'dwarf', 'n_near',
        'confidence', 'gap_nomatch']
with open('sdk_objects.tsv', 'w', newline='\n') as fh:
    fh.write('\t'.join(cols) + '\n')
    for o in objrows:
        fh.write('\t'.join(str(o[k]) for k in keys) + '\n')
pickle.dump([{k: v for k, v in o.items() if k not in ('_l', '_gap')} for o in objrows], open('objrows.pkl', 'wb'))
print('instances', len(objrows))
# tag every function: instance id (matched or gap inside object range), or GAME
tag = {}
for o in objrows:
    if o['confidence'] != 'HIGH':
        continue
    for x in o['_l']:
        tag[x['address'] + x['region']] = ('SDK', o['_iid'])
for o in objrows:
    if o['confidence'] != 'HIGH':
        continue
    for x in o['_gap']:
        k = x['address'] + x['region']
        if k not in tag:
            tag[k] = ('GAPSDK', o['_iid'])
for r in rows:
    k = r['address'] + r['region']
    if k not in tag:
        tag[k] = ('GAME', None)
pickle.dump((tag,), open('tags.pkl', 'wb'))
# per file analysis
byfile = collections.defaultdict(list)
for r in rows:
    if r['file'] != '-':
        byfile[r['file']].append(r)
mixes = []
for f, l in sorted(byfile.items()):
    l.sort(key=lambda r: r['_addr'])
    seq = [tag[r['address'] + r['region']] for r in l]
    objs = sorted({t[1] for t in seq if t[1]}, key=lambda i: i[3])
    n_game = sum(1 for t in seq if t[0] == 'GAME')
    n_sdk = sum(1 for t in seq if t[0] != 'GAME')
    mixes.append((f, l[0]['region'], len(l), n_sdk, n_game, objs))
with open('sdk_file_mix.tsv', 'w', newline='\n') as fh:
    fh.write('our_file\tregion\tn_funcs\tn_sdk_funcs\tn_game_funcs\tn_objects\tobjects\tclass\n')
    for f, reg, n, ns, ng, objs in mixes:
        if not objs:
            cl = 'GAME_ONLY'
        elif ng == 0 and len(objs) == 1:
            cl = 'ONE_OBJECT'
        elif ng == 0:
            cl = 'MULTI_OBJECT'
        elif len(objs) == 1:
            cl = 'OBJECT_PLUS_GAME'
        else:
            cl = 'MULTI_OBJECT_PLUS_GAME'
        fh.write('%s\t%s\t%d\t%d\t%d\t%d\t%s\t%s\n' % (f, reg, n, ns, ng, len(objs), ';'.join('%s:%s@%08X' % (i[1], i[2], i[3]) for i in objs), cl))
print(collections.Counter(re.sub('.*\t', '', l.rstrip()) for l in open('sdk_file_mix.tsv').readlines()[1:]))
# objects split over files
with open('sdk_objects_split.tsv', 'w', newline='\n') as fh:
    fh.write('library\tobject\tregion\taddr_lo\taddr_hi\tn_funcs\tn_files\tfiles\n')
    for o in objrows:
        if o['n_files'] > 1:
            fh.write('%s\t%s\t%s\t%s\t%s\t%d\t%d\t%s\n' % (o['library'], o['object'], o['region'], o['addr_lo'], o['addr_hi'], o['n_funcs'], o['n_files'], o['files']))
# boundary cuts: adjacent functions (by address, same region and same file) whose tags differ
cuts = []
for f, l in sorted(byfile.items()):
    prev = None
    for r in l:
        t = tag[r['address'] + r['region']]
        if prev is not None:
            pt, pr = prev
            a = (pt[0] == 'GAME', pt[1])
            b = (t[0] == 'GAME', t[1])
            if a != b:
                cuts.append((f, r['region'], pr['address'], r['address'], pt, t, pr['our_name'], r['our_name']))
        prev = (t, r)


def lab(t):
    return 'GAME' if t[0] == 'GAME' else '%s:%s@%08X' % (t[1][1], t[1][2], t[1][3])


with open('sdk_boundary_cuts.tsv', 'w', newline='\n') as fh:
    fh.write('our_file\tregion\tleft_func_addr\tright_func_addr\tleft\tright\tkind\n')
    for f, reg, a1, a2, t1, t2, n1, n2 in cuts:
        kind = 'SDK_GAME' if (t1[0] == 'GAME') != (t2[0] == 'GAME') else 'OBJ_OBJ'
        fh.write('%s\t%s\t%s\t%s\t%s\t%s\t%s\n' % (f, reg, a1, a2, lab(t1), lab(t2), kind))
print('cuts', len(cuts), collections.Counter(('SDK_GAME' if (c[4][0] == 'GAME') != (c[5][0] == 'GAME') else 'OBJ_OBJ') for c in cuts))
# renames
ren = []
for r in rows:
    if not r['_ok']:
        continue
    nm, vs = r['our_name'], r['sym']
    if nm == vs:
        cl = 'SAME'
    elif re.fullmatch(r'(func|sub|unit)_[0-9A-Fa-f]{8}', nm) or re.search(r'_[0-9A-F]{8}$', nm):
        cl = 'PLACEHOLDER'
    else:
        cl = 'DIFFERENT'
    ren.append((r, cl))
c = collections.Counter(cl for _, cl in ren)
print(c)
tgt = collections.defaultdict(list)
for r, cl in ren:
    if cl != 'SAME':
        tgt[(r['sym'])].append(r)
CONF = {o['_iid']: o['confidence'] for o in objrows}
with open('sdk_renames.tsv', 'w', newline='\n') as fh:
    fh.write('address\tregion\tour_name\tvendor_symbol\tclass\tlinkage\tobject\tflags\tname_collision\tconfidence\tlibrary\n')
    for r, cl in ren:
        if cl == 'SAME':
            continue
        col = len(tgt[r['sym']]) > 1
        fh.write('\t'.join([r['address'], r['region'], r['our_name'], r['sym'], cl, r['link'], r['obj'], r['flags'], 'YES' if col else '', CONF.get(inst_of.get(r['address'] + r['region']), ''), r['_lib']]) + '\n')
# catalogue disagreement file
with open('sdk_catalogue_disagreements.tsv', 'w', newline='\n') as fh:
    fh.write('region\taddress\tour_name\tcatalogue\tthis_scan\n')
    for reg, a, nm, cg, why in dis:
        fh.write('%s\t0x%08X\t%s\t%s\t%s\n' % (reg, a, nm, cg, why))
print('dis', len(dis))
