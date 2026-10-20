#!/usr/bin/env python3
"""widthinfer.py: settle the parameter and return types of a function from every caller at once.

Many callers keep a local `extern` because their prototype differs in width or pointer type
from the definition's header, and fixing one caller at a time breaks another.  For one
function this tool

  1. collects every declaration the tree makes of it (definition, header, local externs,
     the DS branch of `#ifdef __MWERKS__` guards) and every file that calls it;
  2. for each parameter (and the return type) with more than one type among them, writes
     each candidate type into the definition and into every declaration, in a scratch copy
     of src/game, and compiles the definition file and every caller with the flags of its
     own header (the gameverify settings);
  3. keeps the candidates under which the definition and all callers stay EXACT, and lists
     the callers that still need their own prototype (a true original mismatch, QUIRKS
     kind B).

Nothing under src/game is written by `infer`.  The scratch copy lives under --scratch
(default: <temp dir>/widthinfer) and is refreshed from src/game at each start.

    python tools/widthinfer.py infer NAME [NAME ...]   (NAME may be a glob such as 'BG_SYS_*') [--jobs N] [--max-callers N]
                                [--probe] [--full] [--cand FN.SLOT=TYPE] [--scratch DIR] [--tsv OUT] [--plan OUT.json]
    python tools/widthinfer.py list [--min-sites N]
    python tools/widthinfer.py apply PLAN.json [--apply]

infer    prints one table per function: parameter, definition type, types seen with their
         site counts, candidates that fit the definition and all tested callers, callers that
         disagree with the chosen type.  --plan writes the edits (offset, old text, new
         text) of the chosen types, with the disagreeing callers left alone.  --tsv writes
         the table rows.  --probe tests every parameter even when all declarations agree
         (shows which other widths would also fit).  --cand adds a candidate type the declarations do not show (a real struct for a
         stand-in u8 *).  --full tests every candidate on all callers.  --max-callers samples the callers
         (callers with a differing declaration of their own are always tested).
list     functions whose declarations disagree with the definition, by number of sites.
apply    replays a plan on src/game; dry run unless --apply.  An edit whose old text is not
         at its offset is skipped and listed (the file changed since the plan).  Claim the
         files first (tools/lane.py / claims.py).

Plans hold offsets of the snapshot taken at `infer`.  Other lanes change files meanwhile, so run
`infer --plan` and `apply --apply` back to back when the files are free.

A caller is judged against its own baseline: a file that is not EXACT before any edit is
reported and left out of the verdict.
"""
import argparse
import concurrent.futures as cf
import hashlib
import json
import os
import re
import shutil
import sys
import tempfile
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import protocheck as pc  # noqa: E402
import protonames as pn  # noqa: E402
import placeholdernames as ph  # noqa: E402

pc.DS_BUILD[0] = True        # sites and calls are read as the DS compiler sees them

INT_CANDS = ["u8", "s8", "u16", "s16", "u32", "s32"]
QUAL = ("extern", "static", "inline", "__inline")


# ---------------------------------------------------------------- scratch copy and compiling

def sync_scratch(scr):
    """Refresh <scr>/src/game from src/game (size and whole-second mtime decide)."""
    src, dst = pc.GAME, os.path.join(scr, "src", "game")
    marker = os.path.join(scr, "dirty.json")
    if os.path.exists(marker):                    # an earlier run stopped between write and restore
        for rel in json.load(open(marker)):
            s = os.path.join(src, rel)
            if os.path.exists(s):
                shutil.copy2(s, os.path.join(dst, rel))
        os.remove(marker)
    for dp, _dn, fn in os.walk(src):
        rel = os.path.relpath(dp, src)
        os.makedirs(os.path.join(dst, rel), exist_ok=True)
        for f in fn:
            s, d = os.path.join(dp, f), os.path.join(dst, rel, f)
            try:
                ss = os.stat(s)
                if os.path.exists(d):
                    ds = os.stat(d)
                    if ds.st_size == ss.st_size and int(ds.st_mtime) == int(ss.st_mtime):
                        continue
                shutil.copy2(s, d)
            except OSError:
                continue
    return dst


_SCR = [None]


def _init(scr):
    _SCR[0] = scr
    import match
    orig = match.compile_tu

    def wrap(*a, **k):
        old = match.ROOT
        match.ROOT = scr
        try:
            return orig(*a, **k)
        finally:
            match.ROOT = old
    match.compile_tu = wrap
    sys.path.insert(0, HERE)


def _verify(path):
    """(path, ok, status, first error) of one file compiled as gameverify does."""
    import match
    import gameverify as gv
    try:
        raw = open(path, encoding="latin1").read()
        h, st = gv.settings_of(raw)
        addr = int(h.get("address", "0"), 16)
        if not addr:
            return path, False, "no address", ""
        flags = st["flags"].split() if st["flags"] else ["-O4,p"]
        r, _tl = match.run_tu(path, addr, st["compiler"], flags, st["isa"] == "thumb", st["lang"] or None,
                              region=(h.get("region") or "").strip() or None)
    except (Exception, SystemExit) as e:
        return path, False, "ERROR", repr(e)[:120]
    err = ""
    for l in (r.log or "").splitlines():
        if re.search(r"\.[ch]:\d+:", l) and "warning" not in l:
            err = re.sub(r"^.*?(\w+\.[ch]:\d+:)", r"\1", l.strip())[:160]
            break
    return path, r.status.startswith(("EXACT", "MATCH")), r.status, err


class Runner:
    def __init__(self, scr, jobs):
        self.scr = scr
        self.pool = cf.ProcessPoolExecutor(max_workers=jobs, initializer=_init, initargs=(scr,))
        self.compiles = 0

    def run(self, paths):
        paths = list(paths)
        self.compiles += len(paths)
        return {p: (ok, st, er) for p, ok, st, er in self.pool.map(_verify, paths, chunksize=1)}


# ---------------------------------------------------------------- sites

class Site:
    def __init__(self, f, rec):
        (self.name, self.ret, self.params, self.line, self.is_def, self.static, self.ex) = rec
        self.file = f
        self.pkeys = None
        self.rkey = None


def norm_fn(t):
    return re.sub(r"\s+", "", t)


def slot_parts(site):
    """[(start, end, text)] of the parameter texts of a site, offsets into the cleaned code."""
    ptext, base = site.ex["ptext"], site.ex["par_start"]
    if not ptext.strip() or ptext.strip() == "void":
        return []
    out, off = [], 0
    for p in pn.split_params(ptext):
        out.append((base + off, base + off + len(p), p))
        off += len(p) + 1
    return out


def slot_key(canon, text, keytext):
    """Comparison key of one parameter: the canonical type, or for a function pointer
    (spelled out or by typedef name) its normalised spelling."""
    body = text.strip()
    if "(" in body:
        tmpl = re.sub(r"\(\s*\*\s*\w*\s*\)", "(*%s)", body, count=1)
        key = "@fn:" + norm_fn(tmpl)
        keytext.setdefault(key, tmpl)
        return key
    if canon.startswith("@fnptr"):
        r = pn.param_name(body)
        ty = body[:r[1]].strip() if r else body
        key = "@ty:" + norm_fn(ty)
        keytext.setdefault(key, ty)
        return key
    return canon


def set_keys(site, keytext):
    if site.params is None:
        site.pkeys = None
    else:
        parts = slot_parts(site)
        if len(parts) != len(site.params):
            site.pkeys = None
        else:
            site.pkeys = [slot_key(c, p[2], keytext) for c, p in zip(site.params, parts)]
    site.rkey = site.ret


# ---------------------------------------------------------------- rewriting

class FileCtx:
    def __init__(self, path, types):
        self.path = path
        self.raw = open(path, encoding="latin1", newline="").read()
        self.crlf = "\r" in self.raw
        self.recs, self.code, depths = pc.scan(path, types)
        self.semis = [i for i, ch in enumerate(self.code) if ch == ";" and depths[i] == 0]
        self.vis = pc.visible_typedefs(path)


def type_text(key, keytext, ctx, types, name):
    """Source text of a declaration of `name` with type `key` in file ctx, or None."""
    if key.startswith("@fn:"):
        return keytext[key].replace("%s", name)
    if key.startswith("@ty:"):
        return keytext[key] + (" " + name if name else "")
    t = pc.canon_text(types, key, ctx.code, ctx.vis)
    if t is None:
        return None
    return pc.join_name(t, name)


def site_edits(site, ctx, state, keytext, types):
    """Edit dict (pc.apply_edits form) that moves the site to `state`, or None if nothing changes.
    `state` maps a parameter index (or "ret") to the type key it takes; other slots stay as they are."""
    local, tags = [], []
    ex = site.ex
    if site.pkeys is not None:
        parts = slot_parts(site)
        for j, (s, e, p) in enumerate(parts):
            want = state.get(j)
            if want is None or want == site.pkeys[j]:
                continue
            body = p.strip()
            lead, trail = p[:len(p) - len(p.lstrip())], p[len(p.rstrip()):]
            if "(" in body:
                m = re.search(r"\(\s*\*\s*(\w*)\s*\)", body)
                name = m.group(1) if m else ""
            else:
                if re.search(r"\[[^\]]*\]\s*$", body):
                    continue
                r = pn.param_name(body)
                name = body[r[1]:r[2]] if r else ""
            t = type_text(want, keytext, ctx, types, name)
            if t is None:
                continue
            local.append((s, e, lead + t + trail))
            b = want.rstrip("* ")
            if b.startswith(("struct ", "union ")):
                tags.append((b, ex["name_start"]))
    if state.get("ret") not in (None, site.rkey):
        rt = pc.canon_text(types, state["ret"], ctx.code, ctx.vis)
        if rt is not None:
            pre = ctx.code[ex["pre_start"]:ex["name_start"]]
            lead = len(pre) - len(pre.lstrip())     # blanked directives and comments stay untouched
            q = " ".join(t for t in ex["pre_toks"] if t in QUAL)
            newpre = (q + " " if q else "") + rt + ("" if rt.endswith("*") else " ")
            local.append((ex["pre_start"] + lead, ex["name_start"], newpre))
            b = rt.rstrip("* ")
            if b.startswith(("struct ", "union ")):
                tags.append((b, ex["name_start"]))
    if not local:
        return None
    return dict(name=site.name, local=local, tags=tags, pos=ex["name_start"])


def file_edits(ctx, sites, state, keytext, types):
    es = []
    for s in sites:
        e = site_edits(s, ctx, state, keytext, types)
        if e:
            es.append(e)
    if not es:
        return []
    return pc.apply_edits(ctx.code, es, ctx.semis, types)


# ---------------------------------------------------------------- analysis of one function

class Analysis:
    def __init__(self, name, types, scr_game, runner, texts, opts):
        self.name, self.types, self.runner, self.opts = name, types, runner, opts
        self.game = scr_game
        self.keytext = {}
        self.notes = []
        self.ctx = {}
        self.sites = []
        self.defsite = None
        self.callers = []
        self.skipped = None
        self.texts = texts
        self.extra = {}
        for spec in getattr(opts, "cand", None) or []:
            fn, _, rest = spec.partition(".")
            if fn != name:
                continue
            slot, _, ty = rest.partition("=")
            slot = "ret" if slot == "ret" else int(slot)
            toks = re.findall(r"[A-Za-z_]\w*|\*", ty)
            self.extra.setdefault(slot, []).append(types.canon([t for t in toks if t not in pc.KW]))

    def rel(self, p):
        return os.path.relpath(p, self.game).replace(os.sep, "/")

    def collect(self):
        word = re.compile(r"\b%s\b" % re.escape(self.name))
        files = [f for f, t in self.texts.items() if word.search(t)]
        defs = []
        for f in files:
            ctx = FileCtx(f, self.types)
            self.ctx[f] = ctx
            static_here = any(r[0] == self.name and r[5] for r in ctx.recs)
            for rec in ctx.recs:
                if rec[0] != self.name:
                    continue
                if static_here or rec[5]:
                    continue
                if "asm" in rec[6]["pre_toks"]:
                    continue
                s = Site(f, rec)
                self.sites.append(s)
                if s.is_def:
                    defs.append(s)
        if len(defs) != 1:
            self.skipped = "%d non-static definitions" % len(defs)
            return
        self.defsite = defs[0]
        if self.defsite.params is None:
            self.skipped = "definition without a prototype"
            return
        for s in self.sites:
            set_keys(s, self.keytext)
        if self.defsite.pkeys is None:
            self.skipped = "definition parameters not parsed"
            return
        call = re.compile(r"\b%s\s*\(" % re.escape(self.name))
        for f in files:
            ctx = self.ctx[f]
            if not f.endswith(".c"):
                continue
            site_pos = {s.ex["name_start"] for s in self.sites if s.file == f}
            n = sum(1 for m in call.finditer(ctx.code) if m.start() not in site_pos)
            if n or f == self.defsite.file:
                hdr = ctx.raw[:600]
                if re.search(r"^\s*(?:\*|//)?\s*address\s*:", hdr, re.M) or "address:" in ctx.raw[:2000]:
                    self.callers.append(f)
        self.callers = sorted(set(self.callers))
        if self.defsite.file not in self.callers:
            self.callers.append(self.defsite.file)

    # -- states
    def usable(self):
        """Sites that can be moved: prototyped, same parameter count as the definition."""
        n = len(self.defsite.pkeys)
        return [s for s in self.sites if s.pkeys is not None and len(s.pkeys) == n]

    def edits_for(self, state, skip_files=()):
        by_file = {}
        for s in self.usable():
            if s.file in skip_files:
                continue
            by_file.setdefault(s.file, []).append(s)
        out = {}
        for f, ss in by_file.items():
            es = file_edits(self.ctx[f], ss, state, self.keytext, self.types)
            if es:
                out[f] = es
        return out

    def evaluate(self, state, files, skip_files=()):
        """Write the edits for `state` into the scratch tree, compile `files`, restore."""
        edits = self.edits_for(state, skip_files)
        marker = os.path.join(os.path.dirname(os.path.dirname(self.game)), "dirty.json")
        rels = [self.rel(f) for f in edits]
        json.dump(rels, open(marker, "w"))
        try:
            for f, es in edits.items():
                raw = self.ctx[f].raw
                for s, e, t in sorted(es, key=lambda x: (x[0], x[1]), reverse=True):
                    raw = raw[:s] + t + raw[e:]
                open(f, "w", encoding="latin1", newline="").write(raw)
            res = self.runner.run(files)
        finally:
            for f in edits:
                open(f, "w", encoding="latin1", newline="").write(self.ctx[f].raw)
            os.remove(marker)
        return res, edits

    # -- slots
    def candidates(self, slot):
        """Ordered candidate keys for a slot ('ret' or index) and their site counts."""
        d = self.defsite
        count = {}
        for s in self.usable():
            k = s.rkey if slot == "ret" else s.pkeys[slot]
            count[k] = count.get(k, 0) + 1
        cur = d.rkey if slot == "ret" else d.pkeys[slot]
        cands = [cur] + sorted(k for k in count if k != cur)
        for k in self.extra.get(slot, []):
            if k not in cands:
                cands.append(k)
        ints = [k for k in count if pc.int_kind(k)]
        if ints and self.opts.probe:
            for k in INT_CANDS:
                if k not in cands:
                    cands.append(k)
        elif self.opts.probe and all(k.endswith("*") for k in count) and "void*" not in cands and slot != "ret":
            cands.append("void*")
        return cands, count

    def disagrees(self, slot):
        if slot in self.extra:
            return True
        keys = set()
        for s in self.usable():
            keys.add(s.rkey if slot == "ret" else s.pkeys[slot])
        return len(keys) > 1

    def analyze(self):
        if self.skipped or not self.callers:
            return None
        base = self.runner.run(self.callers)
        base_bad = sorted(f for f, v in base.items() if not v[0])
        good = [f for f in self.callers if base[f][0]]
        d = self.defsite
        if d.file not in good:
            self.skipped = "definition file %s is not EXACT before any edit (%s %s)" % (
                self.rel(d.file), base[d.file][1], base[d.file][2][:80])
            return None
        # callers with a differing declaration of their own are always tested
        own = set()
        for s in self.usable():
            if s.file != d.file and (s.rkey != d.rkey or s.pkeys != d.pkeys):
                own.add(s.file)
        self.own_set = own
        mx = self.opts.max_callers
        test = good
        if mx and len(good) > mx:
            keep = [f for f in good if f in own or f == d.file]
            rest = sorted((f for f in good if f not in own and f != d.file),
                          key=lambda f: hashlib.md5(self.rel(f).encode()).hexdigest())
            test = keep + rest[:max(0, mx - len(keep))]
        slots = list(range(len(d.pkeys))) + ["ret"]
        order = [sl for sl in slots if self.opts.probe or self.disagrees(sl)]
        # one slot at a time: the other slots of every site stay as they are, so a caller is
        # judged on this slot alone (a caller that needs two slots changed does not mask either)
        rows = {}
        chosen = {}
        for sl in order:
            rows[sl] = self.try_slot(sl, test)
            chosen[sl] = rows[sl]["chosen"]
        final, edits = self.evaluate(chosen, test)
        bad = [f for f in test if not final[f][0]]
        plan_edits = edits
        still = []
        if bad:
            final2, plan_edits = self.evaluate(chosen, test, skip_files=set(bad))
            still = [(self.rel(f), final2[f][1], final2[f][2]) for f in test if not final2[f][0]]
        return dict(state=chosen, rows=rows, base_bad=base_bad, tested=len(test), callers=len(self.callers),
                    disagree=[(self.rel(f), final[f][2]) for f in bad], still_bad=still,
                    plan_edits=plan_edits, own=len(own))

    def try_slot(self, slot, test):
        cands, count = self.candidates(slot)
        d = self.defsite
        cur = d.rkey if slot == "ret" else d.pkeys[slot]
        results = []
        for k in cands:
            r, _e = self.evaluate({slot: k}, [d.file])
            results.append(dict(key=k, def_ok=r[d.file][0], def_err=r[d.file][2], state={slot: k},
                                sites=count.get(k, 0)))
        # stage 1: the callers with a declaration of their own (they tell the candidates apart);
        # stage 2: all callers, for the candidates that did best in stage 1 and the current one
        own_files = [f for f in test if f in self.own_set]
        for c in results:
            c["fail"], c["callers_ok"], c["tested_all"] = [], 0, False
            if not c["def_ok"]:
                continue
            r, _e = self.evaluate(c["state"], own_files) if own_files else ({}, None)
            c["s1"] = sum(1 for f in own_files if not r[f][0])
        live = [c for c in results if c["def_ok"]]
        if live:
            best = min(c["s1"] for c in live)
            for c in live:
                if c["s1"] == best or c["key"] == cur or self.opts.full:
                    r, _e = self.evaluate(c["state"], test)
                    fails = [(self.rel(f), r[f][1], r[f][2]) for f in test if not r[f][0]]
                    c["callers_ok"], c["fail"], c["tested_all"] = len(test) - len(fails), fails, True
        fits = [c for c in results if c["def_ok"] and c["tested_all"] and not c["fail"]]
        rank = lambda c: (-c["callers_ok"], c["key"] != cur, -c["sites"], cands.index(c["key"]))
        live = [c for c in results if c["def_ok"] and c["tested_all"]]
        if fits:
            chosen = sorted(fits, key=lambda c: (c["key"] != cur, -c["sites"], cands.index(c["key"])))[0]["key"]
        elif live:
            chosen = sorted(live, key=rank)[0]["key"]
        else:
            chosen = cur
        return dict(cands=results, fits=[c["key"] for c in fits], chosen=chosen, cur=cur, count=count)


# ---------------------------------------------------------------- driver

def shown(key, keytext):
    if key.startswith("@fn:") or key.startswith("@ty:"):
        return keytext[key].replace("%s", "").replace("(*)", "(*)")
    return key


def load_tree(scr_game):
    files = sorted(ph.files_under([scr_game]))
    texts = {}
    for f in files:
        try:
            texts[f] = open(f, encoding="latin1", newline="").read()
        except OSError:
            pass
    return files, texts


def report(a, res, out_rows):
    name = a.name
    d = a.defsite
    print("=" * 78)
    print("%s  (%s:%d)  callers %d, tested %d, definition + local sites %d"
          % (name, a.rel(d.file), d.line, res["callers"], res["tested"], len(a.usable())))
    if res["base_bad"]:
        print("  not EXACT before any edit (left out): %s" % ", ".join(a.rel(f) for f in res["base_bad"][:8]))
    pnames = pc_names(d)
    for sl in sorted(res["rows"], key=lambda x: (x == "ret", x if x != "ret" else 0)):
        r = res["rows"][sl]
        label = "return" if sl == "ret" else "param %d (%s)" % (sl, pnames[sl] if sl < len(pnames) else "?")
        seen = ", ".join("%s x%d" % (shown(k, a.keytext), n) for k, n in sorted(r["count"].items(), key=lambda kv: -kv[1]))
        print("  %s: definition %s; seen %s" % (label, shown(r["cur"], a.keytext), seen))
        for c in r["cands"]:
            tag = "FITS" if c["key"] in r["fits"] else ("def fails" if not c["def_ok"] else
                                                          ("callers fail" if c["tested_all"] else "worse (own callers)"))
            extra = ""
            if not c["def_ok"]:
                extra = "  [%s]" % c["def_err"][:70]
            elif c["fail"] and c["tested_all"]:
                extra = "  %d/%d callers fail, e.g. %s" % (len(c["fail"]), res["tested"], c["fail"][0][0])
            print("      %-14s %-12s%s" % (shown(c["key"], a.keytext), tag, extra))
            if c["def_ok"] and c["tested_all"] and 0 < len(c["fail"]) <= 6:
                for fl in c["fail"]:
                    print("          fails: %s  %s" % (fl[0], fl[2][:100]))
        fails = []
        chosen = next(c for c in r["cands"] if c["key"] == r["chosen"])
        fails = chosen["fail"]
        out_rows.append((name, label, shown(r["cur"], a.keytext), seen, ",".join(shown(k, a.keytext) for k in r["fits"]),
                         shown(r["chosen"], a.keytext), ";".join(f[0] for f in fails[:12])))
    if res["disagree"]:
        print("  callers that keep their own prototype (kind B): %d" % len(res["disagree"]))
        for f, e in res["disagree"][:20]:
            print("      %s  %s" % (f, e[:110]))
    if res["still_bad"]:
        print("  still not EXACT with the plan applied: %d" % len(res["still_bad"]))
        for f, st, er in res["still_bad"][:10]:
            print("      %s  %s  %s" % (f, st[:30], er[:100]))
    nfile = len(res["plan_edits"])
    nedit = sum(len(v) for v in res["plan_edits"].values())
    print("  plan: %s -> %d edits in %d files (definition %s)"
          % ("; ".join("%s=%s" % (("ret" if sl == "ret" else sl), shown(res["rows"][sl]["chosen"], a.keytext))
                       for sl in res["rows"]), nedit, nfile, "changes" if any(v != (d.rkey if k == "ret" else d.pkeys[k]) for k, v in res["state"].items()) else "unchanged"))


def pc_names(d):
    out = []
    for p in pn.split_params(d.ex["ptext"]) if d.ex["ptext"].strip() not in ("", "void") else []:
        m = re.search(r"\(\s*\*\s*(\w+)\s*\)", p)
        r = pn.param_name(p)
        out.append(m.group(1) if m else (r[0] if r else "?"))
    return out


def plan_rows(a, res):
    rows = []
    for f, es in sorted(res["plan_edits"].items()):
        raw = a.ctx[f].raw
        for s, e, t in sorted(es):
            rows.append(dict(file="src/game/" + a.rel(f), start=s, end=e, old=raw[s:e], new=t, function=a.name))
    return rows


def cmd_infer(args):
    t0 = time.time()
    scr = os.path.abspath(args.scratch or os.path.join(tempfile.gettempdir(), "widthinfer"))
    os.makedirs(scr, exist_ok=True)
    game = sync_scratch(scr)
    t1 = time.time()
    files, texts = load_tree(game)
    types = pc.Types(files)
    print("setup: sync %.0fs, index %.0fs" % (t1 - t0, time.time() - t1), flush=True)
    runner = Runner(scr, args.jobs)
    plan, tsv = [], []
    import fnmatch
    names = []
    for n in args.names:
        if any(c in n for c in "*?"):
            ids = set()
            for t in texts.values():
                ids.update(re.findall(r"(\w+)\s*\(", t))
            names += sorted(i for i in ids if fnmatch.fnmatchcase(i, n))
        else:
            names.append(n)
    for name in names:
        a = Analysis(name, types, game, runner, texts, args)
        a.collect()
        if a.skipped:
            print("%s: skipped (%s)" % (name, a.skipped))
            continue
        res = a.analyze()
        if res is None:
            print("%s: %s" % (name, a.skipped or "no callers"))
            continue
        report(a, res, tsv)
        plan += plan_rows(a, res)
    print("compiles: %d in %.0fs" % (runner.compiles, time.time() - t0))
    if args.tsv:
        with open(args.tsv, "w", newline="\n") as fh:
            fh.write("function\tslot\tdefinition\tseen\tfits_all\tchosen\tcallers_that_disagree\n")
            for r in tsv:
                fh.write("\t".join(r) + "\n")
    if args.plan:
        with open(args.plan, "w", newline="\n") as fh:
            json.dump(plan, fh, indent=1, sort_keys=True)
            fh.write("\n")
        print("plan: %d edits -> %s" % (len(plan), args.plan))


def cmd_list(args):
    files = sorted(ph.files_under([pc.GAME]))
    types = pc.Types(files)
    defs, decls = {}, {}
    for f in files:
        recs, _c, _d = pc.scan(f, types)
        for rec in recs:
            name, ret, params, line, is_def, static, ex = rec
            if static or "asm" in ex["pre_toks"]:
                continue
            (defs if is_def else decls).setdefault(name, []).append((f, rec))
    rows = []
    for name, dl in defs.items():
        if len(dl) != 1 or name not in decls:
            continue
        d = dl[0][1]
        bad = 0
        for f, r in decls[name]:
            if pc.compare(d[1], d[2] or [], r[1], r[2]):
                bad += 1
        if bad >= args.min_sites:
            rows.append((bad, len(decls[name]), name))
    for bad, n, name in sorted(rows, reverse=True):
        print("%5d of %5d  %s" % (bad, n, name))
    print("functions: %d" % len(rows))


def cmd_apply(args):
    plan = json.load(open(args.plan))
    by_file = {}
    for r in plan:
        by_file.setdefault(r["file"], []).append(r)
    done = skipped = 0
    for rel, rs in sorted(by_file.items()):
        p = os.path.join(ROOT, rel)
        raw = open(p, encoding="latin1", newline="").read()
        ok = [r for r in rs if raw[r["start"]:r["end"]] == r["old"]]
        for r in rs:
            if r not in ok:
                skipped += 1
                print("SKIP %s offset %d (%s): text changed" % (rel, r["start"], r["function"]))
        # edits of one file shift each other: apply from the end, each checked against the original text
        for r in sorted(ok, key=lambda r: (r["start"], r["end"]), reverse=True):
            raw = raw[:r["start"]] + r["new"] + raw[r["end"]:]
            done += 1
        if ok and args.apply:
            open(p, "w", encoding="latin1", newline="").write(raw)
        print("%s %s: %d edits" % ("wrote" if args.apply else "would write", rel, len(ok)))
    print("%s %d edits, skipped %d" % ("applied" if args.apply else "dry run:", done, skipped))


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    sub = ap.add_subparsers(dest="cmd", required=True)
    pi = sub.add_parser("infer")
    pi.add_argument("names", nargs="+")
    pi.add_argument("--jobs", type=int, default=os.cpu_count() or 4)
    pi.add_argument("--max-callers", type=int, default=0)
    pi.add_argument("--probe", action="store_true")
    pi.add_argument("--cand", action="append", metavar="FN.SLOT=TYPE",
                    help="extra candidate for a parameter index or ret, e.g. 'GAME_DATA_GetFieldSave.ret=struct FieldSave *'")
    pi.add_argument("--full", action="store_true", help="test every candidate on all callers (slow)")
    pi.add_argument("--scratch")
    pi.add_argument("--tsv")
    pi.add_argument("--plan")
    pl = sub.add_parser("list")
    pl.add_argument("--min-sites", type=int, default=1)
    pa = sub.add_parser("apply")
    pa.add_argument("plan")
    pa.add_argument("--apply", action="store_true")
    args = ap.parse_args()
    {"infer": cmd_infer, "list": cmd_list, "apply": cmd_apply}[args.cmd](args)


if __name__ == "__main__":
    main()
