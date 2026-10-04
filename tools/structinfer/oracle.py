"""Allocation-size oracle: independent evidence about which merged objects are consistent."""
import collections

def span_of(sv, r):
    m = 0
    for off, w, k, sg, wr, src in (sv.accs[r] or []):
        if k != 'arr': m = max(m, off + w)
    return m

def discover_allocators(sv, min_nt=30, min_fit=0.85, min_distinct=10, max_top_share=0.6):
    stat = collections.defaultdict(lambda: [0, 0, 0, collections.Counter()])
    for tmp, key, consts, src in sv.csz:
        r = sv.find(tmp)
        sp = span_of(sv, r) if sv.accs[r] else 0
        for j, c in enumerate(consts):
            if c is None or c <= 0 or c > 0x100000: continue
            s = stat[(key, j)]
            s[0] += 1; s[3][c] += 1
            if sp >= 8:
                s[2] += 1
                if sp <= c: s[1] += 1
    best = {}
    for (key, j), (n, fit, nt, cs) in stat.items():
        if nt < min_nt: continue
        if fit / nt < min_fit: continue
        if len(cs) < min_distinct: continue
        if cs.most_common(1)[0][1] / n > max_top_share: continue
        if key not in best or fit > best[key][0]: best[key] = (fit, j)
    return {(key, j) for key, (fit, j) in best.items()}

def evaluate(sv, allocs):
    sizes = collections.defaultdict(set)       # class root -> {sizes}
    nsites = collections.Counter()
    for tmp, key, consts, src in sv.csz:
        for j, c in enumerate(consts):
            if (key, j) in allocs and c:
                r = sv.find(tmp); sizes[r].add(c); nsites[r] += 1
    cons = incons_multi = incons_span = 0
    acc_cons = acc_bad = 0
    detail = []
    for r, ss in sizes.items():
        acc = len(sv.accs[r]) if sv.accs[r] else 0
        if acc == 0: continue
        sp = span_of(sv, r)
        if len(ss) > 1:
            incons_multi += 1; acc_bad += acc; detail.append((acc, 'multi-size', sorted(ss)[:4], sp, r))
        elif sp > min(ss):
            incons_span += 1; acc_bad += acc; detail.append((acc, 'span>size', sorted(ss), sp, r))
        else:
            cons += 1; acc_cons += acc
    tot = cons + incons_multi + incons_span
    return {'classes_with_size': tot, 'consistent': cons, 'multi_size': incons_multi, 'span_exceeds_size': incons_span,
            'acc_consistent': acc_cons, 'acc_inconsistent': acc_bad, 'detail': sorted(detail, reverse=True)}
