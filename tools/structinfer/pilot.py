"""Pilot: rewrite raw-offset accesses of a random sample of files and verify each result with the real compile test."""
import sys, os, re, random, pickle, collections, tempfile, shutil, time
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, REPO + '/tools')
import protofix as P
from pycparser import c_ast
import pipeline, final_policy, rewrite, solve, extract

def NL(text):
    return chr(13) + chr(10) if chr(13) + chr(10) in text else chr(10)

INCLUDE_MODE = False

def test_sites(base, rel, text, sub, tmp, only_exact):
    """Convert exactly the sites in `sub`; True when the file still compiles to the same verdicts."""
    nl = NL(text)
    nt, nc, used, st = rewrite.apply_plan(text, sub, only_exact)
    if not nc: return True
    if INCLUDE_MODE:
        nt = rewrite.insert_includes(nt, list(used), nl)
        hd = {n: rewrite.header_text(s, nl) for n, s in used.items()}
    else:
        nt = rewrite.insert_structs(nt, used, first_func_line(text), nl); hd = None
    v, o, n = verify_text(base, rel, text, nt, tmp, hd)
    return v is None

def largest_passing(base, rel, text, plan, tmp, only_exact):
    """Divide and conquer: the largest set of sites (built greedily from halves) that passes together.
    Returns (sites, number of compiles).  Deterministic."""
    count = [0]
    def ok(sub):
        count[0] += 1
        return test_sites(base, rel, text, sub, tmp, only_exact)
    def solve(items, accepted):
        if not items: return accepted
        if ok(accepted + items): return accepted + items
        if len(items) == 1: return accepted
        mid = len(items) // 2
        accepted = solve(items[:mid], accepted)
        return solve(items[mid:], accepted)
    res = solve(list(plan), [])
    return res, count[0]

def first_func_line(text):
    raw = extract.strip_src(text.replace(chr(13)+chr(10), chr(10)).replace(chr(13), ' '))
    ast = extract.c_parser.CParser().parse(raw)
    best = None
    for ext in ast.ext:
        if isinstance(ext, c_ast.FuncDef) and ext.coord:
            best = ext.coord.line if best is None else min(best, ext.coord.line)
    return best

def build(allev, mo=2):
    sv, allocs, sites_alloc = final_policy.run(allev, mo=mo, verbose=False)
    roots = [i for i in range(len(sv.names)) if sv.parent[i] == i and sv.accs[i]]
    roots.sort(key=lambda r: -len(sv.accs[r]))
    structs = {}
    for n, r in enumerate(roots):
        structs[r] = rewrite.build_struct('Obj%05d' % n, sv.accs[r])
    bysite = collections.defaultdict(list)
    for s in sv.sites:
        node, k, w, kind, sg, line, col, form, var, ktext, rel = s
        bysite[rel].append((node, k, w, kind, sg, line, col, form, var, ktext))
    return sv, structs, bysite

def verify_text(base, rel, text_orig, text_new, tmp, headers=None):
    path = os.path.join(base, 'src', 'matched', rel)
    fi = P.parse_file(path, rel)
    sub = os.path.dirname(rel)
    orig = P.evaluate(fi, text_orig, tmp + '/o/' + sub)
    if orig['c99'] not in ('EXACT', 'EXACT*') and orig['c99'] != orig['nolang']:
        return 'orig-unstable', orig, None
    inc = tmp + '/n/include'
    os.makedirs(inc, exist_ok=True)
    for name, body in (headers or {}).items():
        open(os.path.join(inc, name + '.h'), 'wb').write(body.encode('latin1'))
    new = P.evaluate(fi, text_new, tmp + '/n/' + sub, orig)
    return P.compare_eval(orig, new), orig, new

def one_file(base, rel, sv, structs, bysite, only_exact, control=None):
    path = os.path.join(base, 'src', 'matched', rel)
    text = open(path, encoding='latin1', newline='').read()
    nl = '\r\n' if '\r\n' in text else '\n'
    plan = rewrite.plan_file(rel, sv, structs, None, bysite.get(rel, []))
    if control == 'sabotage':
        ls = rewrite.line_starts(text); newtext = text; nconv = 0
        for node, k, w, kind, sg, line, col, form, var, ktext in bysite.get(rel, []):
            if form == 'zero': continue
            m = rewrite.locate(text, ls, line, col, form, var, ktext)
            if m is None: continue
            kk = m.group('k'); s, e = m.start('k'), m.end('k')
            newk = hex(int(kk, 0) + 4) if kk.lower().startswith('0x') else str(int(kk) + 4)
            newtext = text[:s] + newk + text[e:]; nconv = 1
            break
        used = {}; stats = collections.Counter()
        return text, newtext, nconv, stats, 1
    if control == 'null':
        newtext, nconv, used, stats = text, 0, {}, collections.Counter()
    else:
        newtext, nconv, used, stats = rewrite.apply_plan(text, plan, only_exact)
        if nconv:
            if INCLUDE_MODE:
                newtext = rewrite.insert_includes(newtext, list(used), nl)
                one_file.headers = {n: rewrite.header_text(st, nl) for n, st in used.items()}
            else:
                newtext = rewrite.insert_structs(newtext, used, first_func_line(text), nl)
    return text, newtext, nconv, stats, len(plan)

if __name__ == '__main__':
    base = sys.argv[1]; pkl = sys.argv[2]; n = int(sys.argv[3]); seed = int(sys.argv[4]); mode = sys.argv[5]
    INCLUDE_MODE = len(sys.argv) > 6 and sys.argv[6] == 'inc'
    allev = pipeline.load(pkl)
    sv, structs, bysite = build(allev)
    cand = sorted(rel for rel, plan in bysite.items() if rel.startswith(('ov/', 'arm9/')) and rewrite.plan_file(rel, sv, structs, None, plan))
    print('files with at least one convertible site:', len(cand), '| sites total', sum(len(v) for v in bysite.values()), flush=True)
    random.seed(seed); sample = random.sample(cand, min(n, len(cand)))
    tmp = tempfile.mkdtemp(prefix='sipilot_')
    res = collections.Counter(); rows = []; t0 = time.time()
    for i, rel in enumerate(sample):
        try:
            text, newtext, nconv, stats, nplan = one_file(base, rel, sv, structs, bysite, only_exact=(mode == 'exact'), control=({'null': 'null', 'sabotage': 'sabotage'}.get(mode)))
            if mode not in ('null',) and nconv == 0: res['nothing converted'] += 1; continue
            verdict, orig, new = verify_text(base, rel, text, newtext, tmp, getattr(one_file, 'headers', None) if INCLUDE_MODE else None)
            if verdict is not None and verdict != 'orig-unstable' and mode in ('all', 'exact'):
                plan = rewrite.plan_file(rel, sv, structs, None, bysite.get(rel, []))
                good, ncomp = largest_passing(base, rel, text, plan, tmp, mode == 'exact')
                res['fallback: kept %d of %d sites (%d compiles)' % (len(good), len(plan), ncomp)] += 1
                if good: verdict = None; nconv = len(good)
        except Exception as e:
            res['exception'] += 1; rows.append((rel, 'exception ' + repr(e)[:100])); continue
        key = 'OK (identical verdicts)' if verdict is None else ('orig unstable' if verdict == 'orig-unstable' else verdict.split(':')[0])
        res[key] += 1
        rows.append((rel, nconv, nplan, dict(stats), verdict if verdict else 'OK'))
        if (i + 1) % 10 == 0: print('  %d/%d  %s  %.0fs' % (i + 1, len(sample), dict(res), time.time() - t0), flush=True)
    print('RESULT', mode, dict(res))
    for r in rows:
        if r[-1] != 'OK': print('  FAIL', r[0], r[1:])
    pickle.dump(rows, open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'pilot_%s_%d.pkl' % (mode, seed)), 'wb'))
    shutil.rmtree(tmp, ignore_errors=True)
