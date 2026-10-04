import sys, os, pickle, time, collections
import concurrent.futures as cf
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import extract

def work(args):
    path, rel = args
    try:
        return rel, extract.extract_file(path, rel), None
    except Exception as e:
        return rel, None, repr(e)[:100]

if __name__ == '__main__':
    root, out = sys.argv[1], sys.argv[2]
    base = os.path.join(root, 'src', 'matched')
    files = []
    for dp, dn, fn in os.walk(base):
        for f in fn:
            if f.endswith('.c'): files.append((os.path.join(dp, f), os.path.relpath(os.path.join(dp, f), base).replace(os.sep, '/')))
    files.sort(key=lambda x: x[1])
    t0 = time.time(); allev = {}; errs = collections.Counter(); ex_err = {}
    with cf.ProcessPoolExecutor(6) as ex:
        for rel, ev, err in ex.map(work, files, chunksize=32):
            if err:
                k = err.split(':')[0] + ':' + err.split(':')[-1][:40] if 'ParseError' in err else err[:60]
                errs[k] += 1; ex_err.setdefault(k, rel)
            else: allev[rel] = ev
    pickle.dump(allev, open(out, 'wb'))
    print('files', len(files), 'extracted', len(allev), 'errors', sum(errs.values()), 'events', sum(len(v) for v in allev.values()), '%.0fs' % (time.time() - t0))
    for k, v in errs.most_common(8): print(' ', v, k, '| e.g.', ex_err[k])
