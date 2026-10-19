#!/usr/bin/env python3
"""onelink.py: link ARM9 static + ITCM + every code overlay in ONE mwldarm run.

tools/gamelink.py links each region (ARM9 static, ITCM, each overlay) with its own
mwldarm run.  The original build ran one link with one linker command file: the static
module, the autoloads and every overlay (a MEMORY region with the O flag per overlay,
all overlays sharing one address range, as in the NitroSDK .lcf.template).  This tool
does the same from the objects gamelink.py builds.

    python tools/onelink.py capture [--jobs N] [REGION ...]   # build the objects (gamelink, data mode)
    python tools/onelink.py link    [--only REGION ...]       # one generated .lcf, one mwldarm run
    python tools/onelink.py compare                           # every output section vs the region links

capture reuses gamelink.py as is: it runs each region in data mode and keeps the files of the
last mwldarm call (build/onelink/regions/<region>/: the objects, the region's .lcf, the region's
own result).  link merges those inputs into one .lcf (symbols that two regions define with
different meanings get a per-region name) and runs mwldarm once.  Output is in build/onelink/
(not tracked).  Notes: docs/restructure/ONELINK.md.
"""

from __future__ import annotations

import argparse
import json
import os
import re
import shutil
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

BUILD = os.path.join(ROOT, "build", "onelink")
REGIONS = os.path.join(BUILD, "regions")
PY = sys.executable


def region_list():
    out = ["arm9_main", "itcm"]
    for d in sorted(os.listdir(os.path.join(ROOT, "src", "game"))):
        m = re.fullmatch(r"ov(\d{3})", d)
        if m:
            out.append(d)
    return out


def region_args(r):
    """(gamelink region id, keyword arguments of link_overlay)"""
    if r == "arm9_main":
        return "arm9_main", dict(data=True, extra=os.path.join(ROOT, "build", "datac", "arm9"))
    if r == "itcm":
        return "itcm", dict(extra=os.path.join(ROOT, "build", "datac", "itcm"))
    n = int(r[2:])
    extra = os.path.join(ROOT, "build", "datac", "ov230" if n == 230 else r)
    return n, dict(data=True, extra=extra)


# ------------------------------------------------------------------ capture

def capture_one(r):
    """Child process: run gamelink for region r and keep the inputs of its last mwldarm call."""
    import gamelink as gl
    gl.OUT = os.path.join(BUILD, "gl")
    snap = os.path.join(REGIONS, r)
    real = subprocess

    class Shim:
        def __getattr__(self, k):
            return getattr(real, k)

        def run(self, cmd, *a, **kw):
            p = real.run(cmd, *a, **kw)
            if cmd and cmd[0] == gl.LD and p.returncode == 0:
                cwd = kw["cwd"]
                shutil.rmtree(snap, ignore_errors=True)
                os.makedirs(snap)
                for f in os.listdir(cwd):
                    if os.path.isfile(os.path.join(cwd, f)):
                        shutil.copyfile(os.path.join(cwd, f), os.path.join(snap, f))
            return p
    gl.subprocess = Shim()
    rid, kw = region_args(r)
    res = gl.link_overlay(rid, **kw)
    # the final result of the region run (what a per-region link gives), kept for compare
    pub = os.path.join(gl.OUT + ("_data" if kw.get("data") else ""), r)
    for f in ("ov.bin", "ov.json"):
        if os.path.exists(os.path.join(pub, f)):
            shutil.copyfile(os.path.join(pub, f), os.path.join(snap, "region_" + f))
    ok = bool(res.get("ok"))
    print("%s %s" % (r, "PASS" if ok else "FAIL " + str(res.get("why", res.get("diffs", "")))[:200]))
    return 0 if ok else 1


def cmd_capture(a):
    regs = a.regions or region_list()
    os.makedirs(REGIONS, exist_ok=True)

    def one(r):
        p = subprocess.run([PY, os.path.abspath(__file__), "_capture", r], cwd=ROOT, capture_output=True, text=True)
        line = (p.stdout.strip().splitlines() or ["%s no output: %s" % (r, p.stderr.strip()[-200:])])[-1]
        print(line, flush=True)
        return p.returncode
    t = time.time()
    with ThreadPoolExecutor(a.jobs) as ex:
        rcs = list(ex.map(one, regs))
    print("capture: %d regions, %d failed, %.0f s" % (len(regs), sum(1 for x in rcs if x), time.time() - t))
    return 1 if any(rcs) else 0



# ------------------------------------------------------------------ link

import gamelink as gl  # noqa: E402

TAGS = {"arm9_main": "A9", "itcm": "IT"}
ZBAND = 0x0E000000          # gamelink parks companion anchors and dead data above this
OVERLAY_FLAGS = "(RWXO)"


def tag_of(r):
    return TAGS.get(r) or "o" + r[2:]


class Region:
    pass


def parse_lcf(text):
    mem, secs, assigns = [], [], []
    inmem = False
    insec = False
    for ln in text.splitlines():
        if ln.startswith("MEMORY"):
            inmem, insec = True, False
        elif ln.startswith("SECTIONS"):
            inmem, insec = False, True
        elif ln.startswith("}"):
            inmem = insec = False
        elif inmem:
            m = re.fullmatch(r" (\S+) : ORIGIN = 0x([0-9A-F]+), LENGTH = 0x([0-9A-F]+)", ln)
            mem.append((m.group(1), int(m.group(2), 16), int(m.group(3), 16)))
        elif insec:
            m = re.fullmatch(r" (\.\S+) : \{(.*)\} > (\S+)", ln)
            if m:
                secs.append((m.group(1), m.group(2), m.group(3)))
                continue
            m = re.fullmatch(r" (\S+) = (.+);", ln)
            assigns.append((m.group(1), m.group(2)))
    return mem, secs, assigns


def load_regions(names):
    regs = []
    for idx, r in enumerate(names):
        d = os.path.join(REGIONS, r)
        if not os.path.exists(os.path.join(d, "ov.lcf")):
            print("skip %s: no capture" % r)
            continue
        R = Region()
        R.name, R.tag, R.dir, R.idx = r, tag_of(r), d, idx
        R.mem, R.secs, R.assigns = parse_lcf(open(os.path.join(d, "ov.lcf")).read())
        j = json.load(open(os.path.join(d, "region_ov.json")))
        R.base, R.size, R.ok, R.gaps, R.standin = j["base"], j["size"], j["ok"], j["gaps"], j["standin"]
        R.is_ov = r.startswith("ov")
        data, secs, syms = gl.read_elf(os.path.join(d, "ov.elf"))
        R.esecs = {s["idx"]: s for s in secs}
        R.esyms = syms
        R.objs = sorted(f for f in os.listdir(d) if f.endswith(".o"))
        regs.append(R)
    return regs


def sec_of(R, y):
    return R.esecs[y["shndx"]]["name"] if 0 < y["shndx"] < 0xFF00 else None


def analyse(R):
    """Global definitions, stub symbols and function table of a region's own link."""
    R.stubs = []        # (name, address with thumb bit, section name)
    R.gdefs = {}        # name -> (value, type, section name)  defined in the region's own objects
    R.funcs = []        # (addr, size, name, global, secname)
    lcfdef = set(n for n, e in R.assigns)       # the linker puts these in a section too
    R.maps = []         # (address, 'a'|'t'|'d') mapping symbols of the linked region
    for y in R.esyms:
        if y["name"] in ("$a", "$t", "$d") and 0 < y["shndx"] < 0xFF00:
            R.maps.append((R.esecs[y["shndx"]]["addr"] + y["value"] if False else y["value"], y["name"][1], y["shndx"]))
    R.maps.sort()
    for y in R.esyms:
        n = y["name"]
        if not n or n[0] in "$@." or y["shndx"] == 0 or y["shndx"] == 0xFFF1:
            continue
        if n in lcfdef:
            continue
        bind, typ = y["info"] >> 4, y["info"] & 15
        sn = sec_of(R, y)
        if sn is None:
            continue
        if re.fullmatch(r"c\d+", sn):
            R.stubs.append((n, y["value"], sn))
            continue
        if bind == 1:
            R.gdefs[n] = (y["value"], typ, sn)
        if typ == 2:
            R.funcs.append((y["value"] & ~1, y["size"], n, bind == 1, sn))
    R.funcs.sort()


def kind_at(R, addr):
    """'arm' or 'thumb' by the mapping symbols of the region's link (None: data or unknown)."""
    import bisect
    k = bisect.bisect_right(R.maps, (addr, "z", 1 << 30)) - 1
    if k >= 0 and R.maps[k][1] in "at":
        return "thumb" if R.maps[k][1] == "t" else "arm"
    return None


def covering(R, addr):
    """The function of region R that contains addr: (start, size, name, global, secname) or None."""
    import bisect
    k = bisect.bisect_right(R.funcs, (addr, 1 << 32, "", True, "")) - 1
    if k >= 0:
        f = R.funcs[k]
        if f[0] <= addr < f[0] + max(f[1], 1):
            return f
    return None


def section_at(R, addr):
    import bisect
    if not hasattr(R, "_secidx"):
        R._secidx = sorted((s["addr"], s["addr"] + s["size"], s["idx"]) for s in R.esecs.values()
                           if s["type"] == 1 and s["size"] and not re.fullmatch(r"c\d+", s["name"]))
    k = bisect.bisect_right(R._secidx, (addr, 1 << 40, 1 << 30)) - 1
    if k >= 0 and R._secidx[k][0] <= addr < R._secidx[k][1]:
        return R.esecs[R._secidx[k][2]]
    return None


def add_gap_symbols(path, add):
    """add: [(name, offset, kind)] typed global function symbols in the gap object `path`."""
    d, secs, syms = gl.read_elf(path)
    sec = [s for s in secs if s["name"] == ".gap"][0]
    data = d[sec["off"]:sec["off"] + sec["size"]]
    out = []
    for y in syms:
        if not y["name"]:
            continue
        out.append((y["name"], y["shndx"], y["value"], y["size"], (y["info"] & 15) == 2, (y["info"] >> 4) == 1))
    for n, off, k in add:
        out.append(("$t" if k == "thumb" else "$a", 1, off, 0, True, False))
        out.append((n, 1, off, 0, True, True))
    gl.write_elf(path, [(".gap", 3, data, 1)], out)


def trim_stubs(path, cneed, keepnames):
    """Rewrite a region's stubs.o with only the stub sections `cneed` ('cJ') and, in them, only the
    names in `keepnames` (the others are defined by the real code in the one link)."""
    d, secs, syms = gl.read_elf(path)
    out_secs, newidx = [], {}
    for sec in secs:
        m = re.fullmatch(r"\.cal(\d+)", sec["name"])
        if m and "c" + m.group(1) in cneed:
            out_secs.append((sec["name"], sec["flags"], d[sec["off"]:sec["off"] + sec["size"]], sec["align"]))
            newidx[sec["idx"]] = len(out_secs)
    out = []
    for y in syms:
        if not y["name"] or y["shndx"] not in newidx:
            continue
        if y["name"][0] == "$" or y["name"] in keepnames:
            out.append((y["name"], newidx[y["shndx"]], y["value"], y["size"], (y["info"] & 15) == 2, (y["info"] >> 4) == 1))
    gl.write_elf(path, out_secs, out)


def build_plan(regs, work):
    """Decide names, aliases and the merged symbol assignments."""
    plan = dict(unresolved=[], ren={R.name: {} for R in regs})
    byname = {R.name: R for R in regs}
    # 1. stubs: find the definition in a region that holds the callee address
    stubmap = {}        # (region, stub name) -> (target region, target symbol name)
    adds_alias = {}     # (target region, obj file) -> [(new, old, off)]
    adds_gap = {}       # (target region, gap file) -> [(name, off, kind)]
    for R in regs:
        for n, val, sn in R.stubs:
            addr = val & ~1
            kind = kind_at(R, addr) or "arm"
            hit = None
            cands = [T for T in regs if T is not R and T.base <= addr < T.base + T.size
                     and kind_at(T, addr) in (None, kind)]
            def rank(T):
                c = covering(T, addr)
                exact = c is not None and c[0] == addr
                return (0 if exact else 1, 0 if kind_at(T, addr) == kind else 1)
            cands.sort(key=rank)
            for T in cands:
                g = T.gdefs.get(n)
                if g and (g[0] & ~1) == addr:
                    hit = (T, n)
                    break
            if hit is None:
                # every other case: a name of its own for this stub in the target's object (the
                # original link made one veneer per call, so each stub name stays a separate symbol)
                an = "%s__r%s" % (n, R.tag)
                for T in cands:
                    s = section_at(T, addr)
                    if s is None:
                        continue
                    m = re.fullmatch(r"g(\d+)", s["name"])
                    if m:
                        adds_gap.setdefault((T.name, "g%s.o" % m.group(1)), []).append((an, addr - s["addr"], kind))
                        hit = (T, an)
                        break
                    c = covering(T, addr)
                    if c:
                        m = re.fullmatch(r"t(\d+)(?:_\d+)?", c[4])
                        if m:
                            adds_alias.setdefault((T.name, "t%s.o" % m.group(1)), []).append((an, c[2], addr - c[0]))
                            hit = (T, an)
                            break
            if hit is None:
                plan["unresolved"].append((R.name, n, addr))
            else:
                stubmap[(R.name, n)] = hit
    # 2. add the missing symbols into the target objects
    for (rn, f), lst in adds_gap.items():
        T = byname[rn]
        add_gap_symbols(os.path.join(work, "%s_%s" % (T.tag, f)), lst)
    for (rn, f), lst in adds_alias.items():
        T = byname[rn]
        gl.add_alias_symbols(os.path.join(work, "%s_%s" % (T.tag, f)), lst)
    plan["stubmap"] = stubmap
    plan["added"] = (sum(len(v) for v in adds_gap.values()), sum(len(v) for v in adds_alias.values()))
    # 3. a global name that two regions define: the overlay copies get a per-region name
    owners = {}
    for R in regs:
        for n in R.gdefs:
            owners.setdefault(n, []).append(R)
    final = {}          # (region, name) -> final name
    for n, lst in owners.items():
        if len(lst) == 1:
            continue
        keep = [R for R in lst if not R.is_ov][:1]
        for R in lst:
            if R not in keep:
                final[(R.name, n)] = "%s__%s" % (n, R.tag)
                plan["ren"][R.name][n] = final[(R.name, n)]
    plan["final"] = final
    plan["ncollide"] = sum(1 for n, l in owners.items() if len(l) > 1)
    # 4. references of a stub: rename to the final name of the target definition
    for (rn, n), (T, m) in stubmap.items():
        fm = final.get((T.name, m), m)
        if fm != n:
            plan["ren"][rn][n] = fm
    return plan


def make_subst(m):
    """One compiled pattern for a whole rename map (one pass per text instead of one re.sub per
    key: the per-key form compiled millions of patterns and took minutes)."""
    if not m:
        return lambda text: text
    rx = re.compile(r"(?<![\w.])(%s)(?!\w)" % "|".join(re.escape(k) for k in sorted(m, key=len, reverse=True)))
    return lambda text: rx.sub(lambda mm: m[mm.group(1)], text)


def run_link(regs, plan, work, a):
    byname = {R.name: R for R in regs}
    ren = plan["ren"]
    stubmap = plan["stubmap"]
    # absolute symbol assignments
    groups = {}
    for R in regs:
        for n, e in R.assigns:
            groups.setdefault(n, {}).setdefault(e, []).append(R.name)
    dropped = set()
    allglob = {}
    for R in regs:
        for n in R.gdefs:
            allglob.setdefault(n, []).append(R)
    for n, ex in groups.items():
        # defined as an object symbol somewhere: the definition wins when it has this value
        if n in allglob:
            for e, rl in ex.items():
                lit = int(e, 16) if re.fullmatch(r"0x[0-9A-Fa-f]+", e) else None
                for D in allglob[n]:
                    v = D.gdefs[n][0]
                    if lit is not None and (v & ~1) == (lit & ~1) and D.gdefs[n][2] not in ("t", "g"):
                        for rn in rl:
                            dropped.add((rn, n))
                        break
        if n in allglob:
            # a kept assignment whose name an object defines elsewhere with another value
            for e, rl in ex.items():
                for rn in rl:
                    if (rn, n) not in dropped:
                        ren[rn][n] = "%s__%s" % (n, byname[rn].tag)
                        dropped.add((rn, "~" + n))
            continue
        keepers = [(e, rl) for e, rl in ex.items() if any((rn, n) not in dropped for rn in rl)]
        if len(keepers) > 1:
            keepers.sort(key=lambda t: (-len(t[1]), t[0]))
            for e, rl in keepers[1:]:
                for rn in rl:
                    if (rn, n) in dropped:
                        continue
                    ren[rn][n] = "%s__%s" % (n, byname[rn].tag)
    # symbols defined inside a section body (SINIT_START...): always per region
    for R in regs:
        for nm, body, mem in R.secs:
            for m in re.finditer(r"(\w+) = \.;", body):
                ren[R.name][m.group(1)] = "%s__%s" % (m.group(1), R.tag)
    for R in regs:
        m = ren[R.name]
        if not m:
            continue
        for f in R.objs:
            gl.rename_symbols(os.path.join(work, "%s_%s" % (R.tag, f)), m)
    mem_lines, sec_lines, asg_lines = [], [], []
    emitted = set()
    names = []
    for R in regs:
        t = R.tag
        m = ren[R.name]
        subst = make_subst(m)
        zoff = R.idx * 0x10000
        doff = R.idx * 0x100000
        cneed = set(sn for n, val, sn in R.stubs if (R.name, n) not in stubmap)
        keepmem = set()
        for nm, org, ln in R.mem:
            if re.fullmatch(r"c\d+", nm):
                continue
            if org >= 0x0F000000:
                org += doff
            elif org >= ZBAND:
                org += zoff
            keepmem.add(nm)
            mem_lines.append(" %s_%s %s: ORIGIN = 0x%08X, LENGTH = 0x%X" % (t, nm, OVERLAY_FLAGS + " " if R.is_ov else "", org, ln))
        for nm, body, mem in R.secs:
            if mem not in keepmem:
                continue
            body = re.sub(r"(\w+)\.o \(", lambda mm: "%s_%s.o (" % (t, mm.group(1)), body)
            body = subst(body)
            sec_lines.append(" .%s_%s : {%s} > %s_%s" % (t, nm[1:], body, t, mem))
        for n, e in R.assigns:
            if (R.name, n) in dropped:
                continue
            nn = m.get(n, n)
            e = subst(e)
            if (nn, e) in emitted:
                continue
            emitted.add((nn, e))
            asg_lines.append(" %s = %s;" % (nn, e))
        for f in R.objs:
            if f == "stubs.o":
                continue
            names.append("%s_%s" % (t, f))
    # the stubs no region of the link defines (the limited-mode autoload, ...): one typed stub per
    # address for the whole link
    xs = {}             # stub address -> [names]
    xk = {}             # stub address -> arm|thumb (mapping symbol of the region that has the stub)
    taken = {}
    for R in regs:
        for n, val, sn in R.stubs:
            if (R.name, n) in stubmap:
                continue
            nn = ren[R.name].get(n, n)
            if R.name != "arm9_main" or (nn in taken and taken[nn] != val):
                # one stub name per region: each region of the original link had its own veneers
                nn = "%s__x%s" % (n, R.tag)
                ren[R.name][n] = nn
                for f in R.objs:
                    gl.rename_symbols(os.path.join(work, "%s_%s" % (R.tag, f)), {n: nn})
            if nn not in taken:
                taken[nn] = val
                xs.setdefault(val, []).append(nn)
                xk[val] = kind_at(R, val & ~1) or "arm"
    if xs:
        secs_, sy_ = [], []
        for j, (val, ns) in enumerate(sorted(xs.items())):
            k = xk[val]
            secs_.append((".cal%d" % j, 6, bytes(2 if k == "thumb" else 4), 4 if k == "arm" else 2))
            sy_.append(("$t" if k == "thumb" else "$a", j + 1, 0, 0, True, False))
            for q, n in enumerate(ns):
                sy_.append((n, j + 1, 0, (2 if k == "thumb" else 4) if q == 0 else 0, True, True))
            mem_lines.append(" xs%d : ORIGIN = 0x%08X, LENGTH = 0x4" % (j, val & ~1))
            sec_lines.append(" .xs%d : { xstubs.o (.cal%d) } > xs%d" % (j, j, j))
        gl.write_elf(os.path.join(work, "xstubs.o"), secs_, sy_)
        names.append("xstubs.o")
    lcf = "MEMORY {\n" + "\n".join(mem_lines) + "\n}\nSECTIONS {\n" + "\n".join(sec_lines) + "\n" + "\n".join(asg_lines) + "\n}\n"
    open(os.path.join(work, "onelink.lcf"), "w", newline="\n").write(lcf)
    cmd = [gl.LD, "-proc", "arm946e", "-interworking", "-nostdlib", "-nodefaults", "-nodeadstrip", "-main", "",
           "-application", "-map", "-o", "onelink.elf", "onelink.lcf"] + names
    print("regions %d, objects %d, memory regions %d, unresolved stubs %d, added symbols %s, command %d chars" % (
        len(regs), len(names), len(mem_lines), len(plan["unresolved"]), plan["added"], sum(len(x) + 1 for x in cmd)))
    t0 = time.time()
    p = subprocess.run(cmd, cwd=work, capture_output=True, text=True)
    log = p.stdout + p.stderr
    open(os.path.join(work, "link.log"), "w").write(log)
    print("mwldarm: rc %d, %.0f s" % (p.returncode, time.time() - t0))
    errs = [l for l in log.splitlines() if l.startswith("#") and "Warning" not in l]
    for l in errs[:40]:
        print(l[:240])
    return p.returncode


def capture_key(names):
    """SHA-1 over every captured input of the regions (objects, region command files, region
    results) and over the tools that turn them into the link: equal key, equal link."""
    import hashlib
    h = hashlib.sha1()
    for f in ("onelink.py", "gamelink.py"):
        h.update(open(os.path.join(ROOT, "tools", f), "rb").read())
    for r in names:
        d = os.path.join(REGIONS, r)
        if not os.path.isdir(d):
            continue
        for f in sorted(os.listdir(d)):
            h.update(("%s/%s;" % (r, f)).encode())
            h.update(open(os.path.join(d, f), "rb").read())
    return h.hexdigest()


def cmd_link(a):
    names = a.only or region_list()
    work = os.path.join(BUILD, "link")
    keyf = os.path.join(work, "key.txt")
    key = capture_key(names)
    if not a.force and not a.only and os.path.exists(os.path.join(work, "onelink.elf"))             and os.path.exists(keyf) and open(keyf).read().strip() == key:
        print("link: captured inputs unchanged (key %s), reusing build/onelink/link/onelink.elf" % key[:12])
        return 0
    regs = load_regions(names)
    for R in regs:
        analyse(R)
    shutil.rmtree(work, ignore_errors=True)
    os.makedirs(work)
    for R in regs:
        for f in R.objs:
            shutil.copyfile(os.path.join(R.dir, f), os.path.join(work, "%s_%s" % (R.tag, f)))
    plan = build_plan(regs, work)
    rc = run_link(regs, plan, work, a)
    if rc == 0 and not a.only:
        open(keyf, "w").write(key)
    return rc



# ------------------------------------------------------------------ compare

def cmd_compare(a):
    names = a.only or region_list()
    regs = load_regions(names)
    elf = os.path.join(BUILD, "link", "onelink.elf")
    data, secs, syms = gl.read_elf(elf)
    tags = {R.tag: R for R in regs}
    parts = {R.tag: [] for R in regs}
    other = []
    for s_ in secs:
        if s_["type"] != 1 or not s_["size"]:
            continue
        m = re.match(r"\.?([A-Za-z0-9]+?)_", s_["name"])
        if m and m.group(1) in tags:
            parts[m.group(1)].append(s_)
        else:
            other.append(s_)
    tot_ok = tot_img = tot_reg = 0
    rows = []
    for R in regs:
        rid, _kw = region_args(R.name)
        base, img = gl.overlay_info(rid)
        reg = open(os.path.join(R.dir, "region_ov.bin"), "rb").read()
        out = bytearray(len(img))
        got = bytearray(len(img))
        for s_ in parts[R.tag]:
            if base <= s_["addr"] < base + len(img):
                o = s_["addr"] - base
                n = min(s_["size"], len(img) - o)
                out[o:o + n] = data[s_["off"]:s_["off"] + n]
                got[o:o + n] = b"" * n
        skip = bytearray(len(img))          # bss stand-ins: bytes the region links take from the image
        for x, y in R.standin:
            skip[x - base:y - base] = b"" * (y - x)
        d_reg = [i for i in range(len(img)) if not skip[i] and (not got[i] or out[i] != reg[i])]
        d_img = [i for i in range(len(img)) if not skip[i] and (not got[i] or out[i] != img[i])]
        # where the region's own link differed from the extract (it is the reference for the first compare)
        rows.append((R.name, len(img), len(d_reg), len(d_img), [hex(base + i) for i in d_reg[:6]]))
    for r, n, dr, di, ex in rows:
        print("%-10s %8d bytes  vs region link: %6d differ  vs extract: %6d differ  %s" % (r, n, dr, di, " ".join(ex)))
    print("regions identical to their own link: %d of %d; identical to the extract: %d" % (
        sum(1 for r in rows if r[2] == 0), len(rows), sum(1 for r in rows if r[3] == 0)))
    return 0 if all(r[3] == 0 for r in rows) else 1


def extract_images(names=None):
    """Cut every region's image out of build/onelink/link/onelink.elf by output section prefix
    (A9_, IT_, oNNN_) as cmd_compare does.  The bytes of the .bss stand-in ranges are taken from
    the extract image (the region links do the same; they are not code or initialised data).
    -> {region: (bytes, dict(ok, gaps, standin, uncovered, why))}"""
    names = names or region_list()
    regs = load_regions(names)
    data, secs, _syms = gl.read_elf(os.path.join(BUILD, "link", "onelink.elf"))
    tags = {R.tag: R for R in regs}
    parts = {R.tag: [] for R in regs}
    for s_ in secs:
        if s_["type"] != 1 or not s_["size"]:
            continue
        m = re.match(r"\.?([A-Za-z0-9]+?)_", s_["name"])
        if m and m.group(1) in tags:
            parts[m.group(1)].append(s_)
    out = {}
    for R in regs:
        rid, _kw = region_args(R.name)
        base, img = gl.overlay_info(rid)
        buf = bytearray(len(img))
        got = bytearray(len(img))
        for s_ in parts[R.tag]:
            if base <= s_["addr"] < base + len(img):
                o = s_["addr"] - base
                n = min(s_["size"], len(img) - o)
                buf[o:o + n] = data[s_["off"]:s_["off"] + n]
                got[o:o + n] = b"" * n
        for x, y in R.standin:
            buf[x - base:y - base] = img[x - base:y - base]
            got[x - base:y - base] = b"" * (y - x)
        unc = sum(1 for g in got if not g)
        info = dict(ok=R.ok and unc == 0, gaps=[tuple(x) for x in R.gaps], standin=[tuple(x) for x in R.standin],
                    stale=False, uncovered=unc)
        if unc:
            info["why"] = "%d bytes of the region are in no section of the one link" % unc
        elif not R.ok:
            info["why"] = "the region's own link differed from the original"
        out[R.name] = (bytes(buf), info)
    return out


def main(argv):
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest="cmd", required=True)
    c = sub.add_parser("capture")
    c.add_argument("--jobs", type=int, default=8)
    c.add_argument("regions", nargs="*")
    k = sub.add_parser("link")
    k.add_argument("--only", nargs="*")
    k.add_argument("--force", action="store_true", help="link again even if the captured inputs are unchanged")
    m_ = sub.add_parser("compare")
    m_.add_argument("--only", nargs="*")
    h = sub.add_parser("_capture")
    h.add_argument("region")
    a = ap.parse_args(argv)
    if a.cmd == "_capture":
        return capture_one(a.region)
    if a.cmd == "capture":
        return cmd_capture(a)
    if a.cmd == "link":
        return cmd_link(a)
    if a.cmd == "compare":
        return cmd_compare(a)
    return 2


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
