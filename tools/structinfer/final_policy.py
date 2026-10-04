import sys, collections, zlib
import pipeline, oracle, solve

def run(allev, mo=2, rounds=2, verbose=True, holdout=False):
    sv = pipeline.solve_all(allev, 'typed', mo, constrain=False, prefix=True)
    allocs = oracle.discover_allocators(sv)
    sites = pipeline.sites_of(sv, allocs)
    if verbose: print('round 0: allocators', len(allocs), 'sites', len(sites))
    for rd in range(1, rounds + 1):
        train = sites
        if holdout: train = {k: c for k, c in sites.items() if zlib.crc32(k.encode()) & 1 == 0}
        sv = pipeline.solve_all(allev, 'typed', mo, pre_sz=train, constrain=True, prefix=True)
        allocs2 = oracle.discover_allocators(sv, min_nt=20, min_fit=0.85, min_distinct=8)
        sites2 = pipeline.sites_of(sv, allocs2)
        if verbose: print('round %d: allocators %d sites %d, refused merges %s' % (rd, len(allocs2), len(sites2), dict(sv.refused)))
        if set(allocs2) == set(allocs) and len(sites2) == len(sites): break
        allocs, sites = allocs2, sites2
    return sv, allocs, sites

if __name__ == '__main__':
    allev = pipeline.load(sys.argv[1])
    sv, allocs, sites = run(allev)
    print('allocators:', sorted(allocs))
    c = pipeline.eval_sites(sv, sites)
    rt = pipeline.eval_sites.ratios
    res, tot, _, _ = solve.analyse(sv); res.sort(key=lambda r: -r['n_acc'])
    print('classes %d | largest %s | sized objects: consistent %d, multi %d, span>size %d | accesses in inconsistent %d | completeness >=0.95: %d of %d' % (
        len(res), [r['n_acc'] for r in res[:5]], c[0], c[1], c[2], c[4], sum(1 for x in rt if x >= 0.95), len(rt)))
    print('objects with size evidence: %d (%.1f%% of all accesses)' % (c[0] + c[1] + c[2], 100 * (c[3] + c[4]) / tot))
