"""Struct inference, phase 2: union-find (Steensgaard style, field sensitive by offset) over extracted events."""
import sys, os, pickle, collections

class Solver:
    def __init__(self, congruence=False, pre_sz=None, constrain=True):
        self.congruence = congruence
        self.pre_sz = pre_sz or {}
        self.constrain = constrain
        self.refused = collections.Counter(); self.refusals = []
        self.debug_edges = None
        self.sz = []; self.span = []
        self.ids = {}; self.names = []
        self.parent = []; self.fields = []; self.accs = []
        self.embeds = []          # (parent node id, off, child node id)
        self.calls = []           # (caller-side node id, callee interface node id)
        self.csz = []             # (call-site result node id, callee key, const args, source)
        self.sites = []           # (var node id, K, width, kind, signed, line, col, form, var, ktext, file)
        self.cur_rel = None

    def nid(self, key):
        i = self.ids.get(key)
        if i is None:
            i = len(self.names); self.ids[key] = i; self.names.append(key)
            self.parent.append(i); self.fields.append(None); self.accs.append(None)
            c = self.pre_sz.get(key)
            self.sz.append({c} if c else None); self.span.append(0)
        return i

    def find(self, x):
        p = self.parent
        r = x
        while p[r] != r: r = p[r]
        while p[x] != r: p[x], x = r, p[x]
        return r

    def compatible(self, ra, rb):
        sa, sb = self.sz[ra], self.sz[rb]
        if not sa and not sb: return True
        both = (sa or set()) | (sb or set())
        if len(both) > 1: return False
        size = next(iter(both))
        if max(self.span[ra], self.span[rb]) > size: return False
        return True

    def union(self, a, b, kind='uni'):
        stack = [(a, b)]
        while stack:
            a, b = stack.pop()
            ra, rb = self.find(a), self.find(b)
            if ra == rb: continue
            if self.constrain and not self.compatible(ra, rb):
                self.refused[kind] += 1
                self.refusals.append((kind, self.names[a], self.names[b], sorted(self.sz[ra] or []), sorted(self.sz[rb] or []), self.span[ra], self.span[rb]))
                continue
            # small-to-large on accs
            la = len(self.accs[ra]) if self.accs[ra] else 0
            lb = len(self.accs[rb]) if self.accs[rb] else 0
            if la < lb: ra, rb = rb, ra
            if self.debug_edges is not None: self.debug_edges.append((a, b, kind))
            self.parent[rb] = ra
            if self.sz[rb]:
                self.sz[ra] = (self.sz[ra] or set()) | self.sz[rb]
            if self.span[rb] > self.span[ra]: self.span[ra] = self.span[rb]
            if self.accs[rb]:
                if self.accs[ra] is None: self.accs[ra] = self.accs[rb]
                else: self.accs[ra].extend(self.accs[rb])
                self.accs[rb] = None
            fb = self.fields[rb]
            if fb:
                fa = self.fields[ra]
                if fa is None: self.fields[ra] = fb
                else:
                    for off, chs in fb.items():
                        if off in fa:
                            if self.congruence: stack.append((fa[off][0], chs[0]))
                            fa[off].extend(chs)
                        else: fa[off] = chs
                self.fields[rb] = None

    def add(self, ev):
        k = ev[0]
        if k in ('uni', 'bind', 'ret'):
            self.union(self.nid(ev[1]), self.nid(ev[2]), k)
        elif k in ('call', 'callret'):
            self.calls.append((self.nid(ev[1]), self.nid(ev[2])))
        elif k == 'site':
            self.sites.append((self.nid(ev[1]),) + tuple(ev[2:]) + (self.cur_rel,))
        elif k == 'csz':
            self.csz.append((self.nid(ev[1]), ev[2], ev[3], ev[4]))
        elif k == 'acc':
            n = self.find(self.nid(ev[1]))
            if self.accs[n] is None: self.accs[n] = []
            self.accs[n].append((ev[2], ev[3], ev[4], ev[5], ev[6], ev[7]))
            if ev[4] != 'arr' and ev[2] + ev[3] > self.span[n]: self.span[n] = ev[2] + ev[3]
        elif k == 'fld':
            n = self.find(self.nid(ev[1])); off = ev[2]; ch = self.nid(ev[3])
            if self.fields[n] is None: self.fields[n] = {}
            f = self.fields[n]
            if off in f:
                if self.congruence: self.union(f[off][0], ch)
                f[off].append(ch)
            else: f[off] = [ch]
        elif k == 'emb':
            self.embeds.append((self.nid(ev[1]), ev[2], self.nid(ev[3])))

def link_calls(sv, mode='typed', min_own=1, max_iter=30, prefix=False, slack=0):
    """Join call-site values with callee interface nodes.
    mode 'all'   : always (plain Steensgaard).
    mode 'typed' : only when the callee itself reads (or stores pointers through) the interface node in its
                   own body, judged on a snapshot taken BEFORE any call link.
    prefix=True  : if the argument's own object is larger than the callee's view (snapshot spans), the callee
                   sees a PREFIX sub-object: record containment (arg contains param at offset 0), do not join."""
    n = len(sv.calls)
    own = {}; span0 = []; 
    if mode != 'all':
        for a, p in sv.calls:
            if p not in own:
                rp = sv.find(p)
                cnt = len(sv.accs[rp]) if sv.accs[rp] else 0
                own[p] = cnt >= min_own or bool(sv.fields[rp])
    for a, p in sv.calls:
        span0.append((sv.span[sv.find(a)], sv.span[sv.find(p)]))
    joined = skipped = emb = 0
    sv.prefix_edges = []
    for k, (a, p) in enumerate(sv.calls):
        if mode != 'all' and not own[p]:
            skipped += 1; continue
        if prefix and span0[k][0] > span0[k][1] + slack and span0[k][1] > 0:
            sv.prefix_edges.append((a, p)); emb += 1; continue
        sv.union(a, p, 'call'); joined += 1
    return joined, skipped, emb

def analyse(sv, top=12):
    cls = collections.defaultdict(list)
    for i in range(len(sv.names)):
        if sv.parent[i] == i and sv.accs[i]: cls[i] = sv.accs[i]
    files = collections.defaultdict(set)
    for i, key in enumerate(sv.names):
        if key[0] in 'VT':
            r = sv.find(i)
            if r in cls: files[r].add(key.split(':')[1])
    res = []
    tot_acc = 0; conf_acc = 0; conf_classes = 0
    for r, acc in cls.items():
        tot_acc += len(acc)
        cnt = {}
        for off, w, kind, sg, wr, src in acc:
            if kind == 'arr': continue
            cnt[(off, w)] = cnt.get((off, w), 0) + 1
        items = sorted(cnt)
        bad = set()
        for a in range(len(items)):
            o1, w1 = items[a]
            for b in range(a + 1, len(items)):
                o2, w2 = items[b]
                if o2 >= o1 + w1: break
                inside_a = o2 >= o1 and o2 + w2 <= o1 + w1
                inside_b = o1 >= o2 and o1 + w1 <= o2 + w2
                if inside_a or inside_b: continue
                bad.add(items[a]); bad.add(items[b])
        by_off = collections.defaultdict(set)
        for off, w in items: by_off[off].add(w)
        mx = max((o + w for (o, w) in items), default=0)
        n_bad = sum(cnt[k] for k in bad)
        kinds = collections.defaultdict(set)
        for off, w, kind, sg, wr, src in acc:
            if kind in ('ptr', 'int'): kinds[off].add(kind)
        res.append({'root': r, 'n_acc': len(acc), 'fields': len(by_off), 'span': mx, 'bad': len(bad), 'bad_acc': n_bad,
                    'files': len(files[r]), 'ptrs': sum(1 for x in acc if x[2] == 'ptr'),
                    'disguised': sum(1 for o, k in kinds.items() if len(k) > 1),
                    'puns': sum(1 for o, ws in by_off.items() if len(ws) > 1)})
        conf_acc += n_bad
        if bad: conf_classes += 1
    return res, tot_acc, conf_acc, conf_classes

def pointee_stats(sv):
    one = many = 0; fan = []
    for r in range(len(sv.names)):
        if sv.parent[r] != r or not sv.fields[r]: continue
        for off, chs in sv.fields[r].items():
            kids = {sv.find(c) for c in chs}
            kids = {k for k in kids if sv.accs[k] or sv.fields[k]}
            if len(kids) == 1: one += 1
            elif len(kids) > 1: many += 1; fan.append(len(kids))
    return one, many, sorted(fan)[-5:]
