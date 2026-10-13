import sys, os, json, traceback, io, contextlib
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
os.chdir(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
import dg1gen, gamelink_dg as gl
MODE = os.environ.get("DG1_MODE", "companion")
res = {}
for rg in sys.argv[1:]:
    oid = int(rg[2:])
    try:
        b = gl.link_overlay(oid, out=os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))), "build/dg1/base"))
        if not b["ok"]:
            res[rg] = dict(stage="baseline", why=b.get("why") or str(b.get("diffs"))[:200]); print(rg, res[rg], flush=True); continue
        f = io.StringIO()
        with contextlib.redirect_stdout(f):
            r, l = dg1gen.run(rg, verbose=False, mode=MODE)
        res[rg] = dict(stage="data", ok=l["ok"], why=l.get("why"), tail_diff=l.get("tail_diff"), gaps=l.get("gaps"),
                       stats=r["stats"], blockers=r["blockers"], absolute=l.get("absolute"), diffs=l.get("diffs"))
    except BaseException as e:
        res[rg] = dict(stage="exception", why="%s: %s" % (type(e).__name__, e))
    print(rg, {k: v for k, v in res[rg].items() if k not in ("stats",)}, flush=True)
out = os.path.join(os.path.dirname(os.path.abspath(__file__)), "batch_%s.json" % os.environ.get("DG1_TAG", "x"))
json.dump(res, open(out, "w"), indent=1)
