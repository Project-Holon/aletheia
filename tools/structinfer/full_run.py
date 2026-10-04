"""Full run of the struct rewrite on a scratch copy of the source tree.
Every file is rewritten, compiled in both modes and compared with the original verdicts, in parallel.
Nothing is written into the repository.  Output: results.tsv (one line per file), headers/ObjNNNNN.h,
and the rewritten files under out/src/matched/<dir>/.  Resumable."""
import sys, os, re, pickle, collections, tempfile, shutil, time, json
import concurrent.futures as cf
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import pilot, pipeline, rewrite

pilot.INCLUDE_MODE = True
G = {}

def init(base, pkl, out):
    G['base'] = base; G['out'] = out
    allev = pipeline.load(pkl)
    G['sv'], G['structs'], G['bysite'] = pilot.build(allev)

def work(rel):
    base, out, sv, structs, bysite = G['base'], G['out'], G['sv'], G['structs'], G['bysite']
    tmp = tempfile.mkdtemp(prefix='sifull_')
    try:
        path = os.path.join(base, 'src', 'matched', rel)
        text = open(path, encoding='latin1', newline='').read()
        nl = pilot.NL(text)
        plan = rewrite.plan_file(rel, sv, structs, None, bysite.get(rel, []))
        if not plan: return rel, 'no sites', 0, 0, {}
        nt, nc, used, st = rewrite.apply_plan(text, plan, False)
        if not nc: return rel, 'nothing convertible', 0, len(plan), {}
        newtext = rewrite.insert_includes(nt, list(used), nl)
        hd = {n: rewrite.header_text(s, nl) for n, s in used.items()}
        v, o, n = pilot.verify_text(base, rel, text, newtext, tmp, hd)
        kept = nc; ncomp = 1
        if v == 'orig-unstable':
            return rel, 'orig unstable', 0, len(plan), {}
        if v is not None:
            good, ncomp = pilot.largest_passing(base, rel, text, plan, tmp, False)
            ncomp += 1
            if not good: return rel, 'no site passes', 0, len(plan), {}
            nt, nc, used, st = rewrite.apply_plan(text, good, False)
            newtext = rewrite.insert_includes(nt, list(used), nl)
            hd = {n: rewrite.header_text(s, nl) for n, s in used.items()}
            v2, o, n = pilot.verify_text(base, rel, text, newtext, tmp, hd)
            if v2 is not None: return rel, 'subset failed', 0, len(plan), {}
            kept = nc
        dst = os.path.join(out, 'src', 'matched', rel)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        open(dst, 'wb').write(newtext.encode('latin1'))
        for name, body in hd.items():
            hp = os.path.join(out, 'src', 'matched', 'include', name + '.h')
            os.makedirs(os.path.dirname(hp), exist_ok=True)
            open(hp, 'wb').write(body.encode('latin1'))
        return rel, 'converted' if kept == len(plan) else 'converted (subset)', kept, len(plan), {'compiles': ncomp, 'structs': sorted(used)}
    except Exception as e:
        return rel, 'exception ' + repr(e)[:80], 0, 0, {}
    finally:
        shutil.rmtree(tmp, ignore_errors=True)

if __name__ == '__main__':
    base, pkl, out = sys.argv[1], sys.argv[2], sys.argv[3]
    limit = int(sys.argv[4]) if len(sys.argv) > 4 else 0
    os.makedirs(out, exist_ok=True)
    res_path = os.path.join(out, 'results.tsv')
    done = set()
    if os.path.exists(res_path):
        done = {l.split(chr(9))[0] for l in open(res_path, encoding='utf-8')}
    sv0 = None
    allev = pipeline.load(pkl)
    files = sorted(rel for rel in allev if rel.startswith(('ov/', 'arm9/')))
    if limit: files = files[:limit]
    files = [f for f in files if f not in done]
    print('files to process', len(files), flush=True)
    t0 = time.time(); c = collections.Counter(); sites_kept = 0; sites_plan = 0
    with open(res_path, 'a', encoding='utf-8') as rf:
        with cf.ProcessPoolExecutor(5, initializer=init, initargs=(base, pkl, out)) as ex:
            for i, (rel, status, kept, plan, extra) in enumerate(ex.map(work, files, chunksize=4)):
                c[status.split(' (')[0] if status.startswith('converted') else status] += 1
                sites_kept += kept; sites_plan += plan
                rf.write(chr(9).join([rel, status, str(kept), str(plan), json.dumps(extra)]) + chr(10)); rf.flush()
                if (i + 1) % 200 == 0:
                    print('%d/%d %s sites kept %d of %d  %.0fs' % (i + 1, len(files), dict(c), sites_kept, sites_plan, time.time() - t0), flush=True)
    print('DONE', dict(c), 'sites kept', sites_kept, 'of', sites_plan, '%.0fs' % (time.time() - t0))
