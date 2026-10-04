import sys, pickle, collections, zlib
import solve, oracle

def load(path): return pickle.load(open(path, 'rb'))

def solve_all(allev, mode='typed', min_own=1, pre_sz=None, constrain=True, prefix=False):
    sv = solve.Solver(congruence=False, pre_sz=pre_sz, constrain=constrain)
    for rel, evs in allev.items():
        sv.cur_rel = rel
        for e in evs: sv.add(e)
    solve.link_calls(sv, mode, min_own=min_own, prefix=prefix)
    return sv

def sites_of(sv, allocs):
    out = {}
    for tmp, key, consts, src in sv.csz:
        for j, c in enumerate(consts):
            if (key, j) in allocs and c: out[sv.names[tmp]] = c
    return out

def eval_sites(sv, sites):
    sizes = collections.defaultdict(set)
    for k, c in sites.items():
        i = sv.ids.get(k)
        if i is None: continue
        sizes[sv.find(i)].add(c)
    cons = multi = over = 0; acc_bad = 0; acc_ok = 0
    ratios = []
    for r, ss in sizes.items():
        if not sv.accs[r]: continue
        sp = oracle.span_of(sv, r); n = len(sv.accs[r])
        if len(ss) > 1: multi += 1; acc_bad += n
        elif sp > min(ss): over += 1; acc_bad += n
        else:
            cons += 1; acc_ok += n; ratios.append(sp / min(ss))
    eval_sites.ratios = ratios
    return cons, multi, over, acc_ok, acc_bad

if __name__ == '__main__':
    allev = load(sys.argv[1]); mo = int(sys.argv[2]) if len(sys.argv) > 2 else 1
    sv0 = solve_all(allev, 'typed', mo, constrain=False)
    allocs = oracle.discover_allocators(sv0)
    sites = sites_of(sv0, allocs)
    train = {k: c for k, c in sites.items() if zlib.crc32(k.encode()) & 1 == 0}
    test = {k: c for k, c in sites.items() if zlib.crc32(k.encode()) & 1 == 1}
    print('allocators', sorted(allocs), '| sites', len(sites), 'train', len(train), 'test', len(test))
    print('unconstrained : test sites -> consistent %d, multi-size %d, span>size %d | accesses ok %d, bad %d' % eval_sites(sv0, test))
    sv1 = solve_all(allev, 'typed', mo, pre_sz=train, constrain=True)
    print('constrained   : test sites -> consistent %d, multi-size %d, span>size %d | accesses ok %d, bad %d' % eval_sites(sv1, test))
    print('refused merges by kind:', dict(sv1.refused))
    res0, t0, _, _ = solve.analyse(sv0); res1, t1, _, _ = solve.analyse(sv1)
    print('classes: %d -> %d | largest: %d -> %d' % (len(res0), len(res1), max(r['n_acc'] for r in res0), max(r['n_acc'] for r in res1)))
