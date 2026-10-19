#!/usr/bin/env python3
"""narrowcheck.py: parameters and locals typed narrower than the value they carry.

mwcc keeps a full register for a u8/u16 parameter, so a narrow type can match the
DS bytes while the value is really a pointer or a 32-bit word.  A host compiler
narrows it and the port breaks.  For every function defined in src/game this tool
looks at each parameter and local of an 8- or 16-bit integer type and lists the
uses that need more bits.

Tiers
  strong  the value is used as a pointer: cast to a pointer, dereferenced with
          arithmetic, `x->f`, assigned to a pointer variable, passed to a pointer
          parameter of a known prototype, returned from a pointer function,
          stored through a cast to a pointer type; or compared to a constant
          outside the type's range; or declared as a pointer by another
          prototype of the same function.
  medium  another prototype declares it u32/s32; the value is stored through a cast to a 32-bit type, passed to a 32-bit
          parameter, or returned from a 32-bit function.  Often legitimate
          (zero extension); --medium lists them.

    python tools/narrowcheck.py              strong hits
    python tools/narrowcheck.py --medium     strong and medium hits
    python tools/narrowcheck.py --tsv        rows: tier file line func var type kind evidence
    python tools/narrowcheck.py --notes      also grep notes for "as u16" style remarks
    python tools/narrowcheck.py FILE ...     limit to these files (repo-relative)
"""
import argparse
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import protocheck as pc  # noqa: E402

ROOT = pc.ROOT
GAME = pc.GAME
NARROW = {"u8": (0, 255), "s8": (-128, 127), "char": (-128, 127), "u16": (0, 65535), "s16": (-32768, 32767)}
DECLSTART = re.compile(r"(?:^|(?<=[;{}]))\s*(?:register\s+|static\s+|const\s+|volatile\s+)*"
                       r"((?:(?:unsigned|signed|char|short|int|long|[A-Za-z_]\w*)\s+)*?(?:unsigned|signed|char|short|[A-Za-z_]\w*))"
                       r"\s+(\**)\s*(\w+)\s*(\[[^\]]*\])?\s*(?==|;|,)")


def wide(t):
    if t is None:
        return False
    if t.endswith("*") or t.startswith("@fnptr"):
        return True
    k = pc.int_kind(t)
    return bool(k and k[0] >= 32)


def is_ptr(t):
    return bool(t) and (t.endswith("*") or t.startswith("@fnptr"))


def body_of(code, extra):
    i = extra["par_end"]
    j = code.find("{", i)
    if j < 0:
        return None
    d = 0
    for k in range(j, len(code)):
        c = code[k]
        if c == "{":
            d += 1
        elif c == "}":
            d -= 1
            if d == 0:
                return j + 1, k
    return None


def param_list(types, ptext):
    """[(name, canon type)] of a definition's parameters."""
    out = []
    t = ptext.strip()
    if t in ("", "void"):
        return out
    import protonames as pn
    for p in pn.split_params(t):
        p = p.strip()
        if p == "..." or "(" in p:
            out.append((None, "@fnptr"))
            continue
        p2 = re.sub(r"(\w*)\s*(?:\[[^\]]*\]\s*)+", lambda m: " * " + m.group(1) + " ", p)
        toks = re.findall(r"[A-Za-z_]\w*|\*", p2)
        toks = [x for x in toks if x not in pc.KW]
        name = None
        if len(toks) >= 2 and re.match(r"[A-Za-z_]", toks[-1]) and toks[-1] not in pc.SCALARS \
                and toks[-2] not in ("struct", "union", "enum"):
            prev = toks[-2]
            if prev == "*" or prev in pc.SCALARS or types.is_type_name(prev):
                name = toks[-1]
                toks = toks[:-1]
        out.append((name, types.canon(toks)))
    return out


def locals_of(types, body):
    out = {}
    for m in DECLSTART.finditer(body):
        base, stars, name, arr = m.group(1), m.group(2), m.group(3), m.group(4)
        toks = re.findall(r"[A-Za-z_]\w*", base)
        if toks and toks[0] in pc.NOT_TYPE_WORDS:
            continue
        if not toks:
            continue
        if not all(t in pc.SCALARS or t in ("struct", "union", "enum") or types.is_type_name(t) or t in pc.KW
                   for t in toks) and toks[0] not in ("struct", "union", "enum"):
            continue
        toks = [t for t in toks if t not in pc.KW]
        if not toks:
            continue
        ctoks = toks + ["*"] * len(stars) + (["*"] if arr else [])
        out[name] = types.canon(ctoks)
    return out


def line_of(starts, pos):
    import bisect
    return bisect.bisect_right(starts, pos)


def stmt_bounds(code, pos, lo, hi):
    a = max(code.rfind(";", lo, pos), code.rfind("{", lo, pos), code.rfind("}", lo, pos))
    a = lo if a < 0 else a + 1
    b = code.find(";", pos, hi)
    b = hi if b < 0 else b
    return a, b


CAST_T = r"\(\s*([A-Za-z_][\w\s]*?(?:\s*\*)+)\s*\)"


PTR_ARG = re.compile(r"^(?:&\s*\w|\"|\(\s*[A-Za-z_][\w\s]*\*+\s*\))")
PTR_CAST_INT = re.compile(r"^\(\s*(?:u32|int|s32|u16|u8)\s*\)\s*(?:&\s*\w|\w+\s*\()")


PTRARGS = {}      # (callee, param index) -> call sites that pass something pointer-shaped to a 32-bit param


def caller_side(types, defs_by, rel, starts, lo, body, name, types_of, rows):
    """A call passes something pointer-shaped to a parameter whose definition is 8 or 16 bits."""
    for cm in re.finditer(r"([A-Za-z_]\w*)\s*\(", body):
        callee = cm.group(1)
        if callee in pc.NOT_TYPE_WORDS or callee in pc.SCALARS:
            continue
        cands = defs_by.get(callee)
        if not cands:
            continue
        sigs = {tuple(d[3] or ()) for d in cands}
        if len(sigs) != 1:
            continue
        cpar = list(sigs)[0]
        i = cm.end()
        depth = 1
        while i < len(body) and depth:
            if body[i] == "(":
                depth += 1
            elif body[i] == ")":
                depth -= 1
            i += 1
        if depth:
            continue
        for idx, (s, e) in enumerate(pc.split_args(body, cm.end() - 1, i - 1)):
            if idx >= len(cpar):
                continue
            arg = body[s:e].strip()
            mi = re.match(r"^\(\s*(?:u32|int|s32|unsigned int|unsigned)\s*\)\s*(\w+)$", arg)
            ptr = bool(PTR_ARG.match(arg)) or (arg in types_of and is_ptr(types_of[arg]))                 or bool(mi and mi.group(1) in types_of and is_ptr(types_of[mi.group(1)]))                 or bool(re.match(r"^\(\s*(?:u32|int|s32)\s*\)\s*&", arg))
            if ptr and cpar[idx] in ("u32", "s32"):
                PTRARGS.setdefault((callee, idx), []).append("%s in %s" % (rel, name))
            if ptr and cpar[idx] in NARROW:
                rows.append(("strong", rel, line_of(starts, lo + s), name, "%s(arg %d)" % (callee, idx),
                             "callee param %s" % cpar[idx], "caller-passes-pointer", arg))


def analyse(types, defs_by, decls_by, path, code, starts, rec, rows):
    name, ret, params, line, is_def, static, extra = rec
    bb = body_of(code, extra)
    if not bb:
        return
    lo, hi = bb
    body = code[lo:hi]
    plist = param_list(types, extra["ptext"])
    vars_ = {}
    for n, t in plist:
        if n:
            vars_[n] = ("param", t)
    for n, t in locals_of(types, body).items():
        if n not in vars_:
            vars_[n] = ("local", t)
    narrow = {n: (k, t) for n, (k, t) in vars_.items() if t in NARROW}
    types_of = {n: t for n, (k, t) in vars_.items()}
    rel = os.path.relpath(path, ROOT).replace(os.sep, "/")
    caller_side(types, defs_by, rel, starts, lo, body, name, types_of, rows)
    if not narrow:
        return

    def add(tier, var, kind, pos, ev):
        k, t = narrow[var]
        ev = re.sub(r"\s+", " ", ev).strip()[:140]
        rows.append((tier, rel, line_of(starts, lo + pos), name, var, "%s %s" % (k, t), kind, ev))

    for var in narrow:
        vt = narrow[var][1]
        rng = NARROW[vt]
        W = r"\b%s\b" % re.escape(var)
        # pointer casts and arithmetic
        for m in re.finditer(CAST_T + r"\s*\(?\s*" + W, body):
            if "*" in m.group(1):
                a, b = stmt_bounds(body, m.start(), 0, len(body))
                add("strong", var, "cast-to-pointer", m.start(), body[a:b])
        for m in re.finditer(W + r"\s*->", body):
            a, b = stmt_bounds(body, m.start(), 0, len(body))
            add("strong", var, "arrow", m.start(), body[a:b])
        # store through a cast, and plain assignment
        for m in re.finditer(r"=\s*" + W + r"\s*;", body):
            if body[max(0, m.start() - 1)] in "=!<>+-*/&|^%":
                continue
            a, b = stmt_bounds(body, m.start(), 0, len(body))
            lhs = body[a:m.start()].strip()
            cm = re.match(r"\*\s*" + CAST_T, lhs) or re.match(r"\(\s*\*\s*" + CAST_T, lhs)
            if cm:
                t = types.canon(re.findall(r"[A-Za-z_]\w*|\*", cm.group(1)))
                if is_ptr(t[:-1] if t.endswith("*") else t):
                    add("strong", var, "store-pointer", m.start(), body[a:b])
                elif wide(t[:-1] if t.endswith("*") else t):
                    add("medium", var, "store-32", m.start(), body[a:b])
                continue
            mm = re.fullmatch(r"(\w+)", lhs)
            if mm and mm.group(1) in types_of and mm.group(1) != var and is_ptr(types_of[mm.group(1)]):
                add("strong", var, "assign-pointer", m.start(), body[a:b])
        # derefs: *(T *)(x + n)
        for m in re.finditer(r"\*\s*" + CAST_T + r"\s*\(\s*" + W + r"\s*[+\-)]", body):
            a, b = stmt_bounds(body, m.start(), 0, len(body))
            add("strong", var, "deref-arith", m.start(), body[a:b])
        # comparisons with constants
        for m in re.finditer(W + r"\s*(==|!=|<=|>=|<|>)\s*(-?(?:0[xX][0-9a-fA-F]+|\d+))\b", body):
            v = int(m.group(2), 0)
            if v < rng[0] or v > rng[1]:
                a, b = stmt_bounds(body, m.start(), 0, len(body))
                add("strong", var, "range-compare", m.start(), body[a:b])
        for m in re.finditer(r"\b(-?(?:0[xX][0-9a-fA-F]+|\d+))\s*(==|!=|<=|>=|<|>)\s*" + W, body):
            v = int(m.group(1), 0)
            if v < rng[0] or v > rng[1]:
                a, b = stmt_bounds(body, m.start(), 0, len(body))
                add("strong", var, "range-compare", m.start(), body[a:b])
        # return
        for m in re.finditer(r"\breturn\s+" + W + r"\s*;", body):
            if is_ptr(ret):
                add("strong", var, "return-pointer", m.start(), "return " + var)
            elif wide(ret):
                add("medium", var, "return-32", m.start(), "return " + var)
    # call arguments
    for cm in re.finditer(r"\b([A-Za-z_]\w*)\s*\(", body):
        callee = cm.group(1)
        if callee in pc.NOT_TYPE_WORDS or callee in pc.SCALARS or callee == name:
            continue
        cands = defs_by.get(callee)
        if not cands:
            continue
        sigs = {tuple(d[3] or ()) for d in cands}
        if len(sigs) != 1:
            continue
        cpar = list(sigs)[0]
        i = cm.end()
        depth = 1
        while i < len(body) and depth:
            if body[i] == "(":
                depth += 1
            elif body[i] == ")":
                depth -= 1
            i += 1
        if depth:
            continue
        for idx, (s, e) in enumerate(pc.split_args(body, cm.end() - 1, i - 1)):
            arg = body[s:e].strip()
            if arg in narrow and idx < len(cpar):
                pt = cpar[idx]
                if is_ptr(pt):
                    add("strong", arg, "arg-pointer-param", s, "%s(... %s ...) param %d is %s" % (callee, arg, idx, pt))
                elif (callee, idx) in PTRARGS:
                    add("strong", arg, "arg-ptrlike-param", s, "%s(... %s ...) param %d is %s and %s passes a pointer there" % (
                        callee, arg, idx, pt, PTRARGS[(callee, idx)][0]))
                elif wide(pt):
                    add("medium", arg, "arg-32-param", s, "%s(... %s ...) param %d is %s" % (callee, arg, idx, pt))
    # other prototypes declare the parameter wider
    if not static:
        for d in decls_by.get(name, []):
            dpar = d[3]
            if dpar is None or len(dpar) != len(plist):
                continue
            for idx, (n, t) in enumerate(plist):
                if n in narrow and wide(dpar[idx]):
                    k, _ = narrow[n]
                    rows.append(("strong" if is_ptr(dpar[idx]) else "medium",
                                 os.path.relpath(path, ROOT).replace(os.sep, "/"), line, name, n,
                                 "%s %s" % (k, t), "proto-wider",
                                 "declared %s in %s:%d" % (dpar[idx], d[0], d[4])))


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("files", nargs="*")
    ap.add_argument("--medium", action="store_true")
    ap.add_argument("--tsv", action="store_true")
    ap.add_argument("--notes", action="store_true")
    a = ap.parse_args()
    allfiles = sorted(pc.ph.files_under([GAME]))
    types = pc.Types(allfiles)
    scans = {}
    defs_by = {}
    decls_by = {}
    for f in allfiles:
        recs, code, _d = pc.scan(f, types)
        starts = [0]
        for i, ch in enumerate(code):
            if ch == "\n":
                starts.append(i + 1)
        scans[f] = (recs, code, starts)
        for rec in recs:
            name, ret, params, line, is_def, static, extra = rec
            if static:
                continue
            if is_def:
                if "asm" in extra["pre_toks"]:
                    continue
                defs_by.setdefault(name, []).append((pc.region_of(f), f, ret, params, line, extra))
            else:
                decls_by.setdefault(name, []).append((os.path.relpath(f, ROOT).replace(os.sep, "/"), name, ret, params, line))
    dflat = {n: [(d[0], d[1], d[2], d[3]) for d in l] for n, l in defs_by.items()}
    dflat_unique = {n: l for n, l in dflat.items()}
    # decl-by-name keyed only when the definition is unique
    dbn = {n: v for n, v in decls_by.items() if n in defs_by and len(defs_by[n]) == 1}
    want = None
    if a.files:
        want = {os.path.abspath(os.path.join(ROOT, f)) for f in a.files}
    rows = []
    for f in allfiles:           # pass 1: which 32-bit parameters receive pointers somewhere
        recs, code, starts = scans[f]
        for rec in recs:
            if rec[4] and "asm" not in rec[6]["pre_toks"]:
                analyse(types, dflat_unique, dbn, f, code, starts, rec, [])
    for f in allfiles:
        if want is not None and os.path.abspath(f) not in want:
            continue
        recs, code, starts = scans[f]
        for rec in recs:
            if rec[4] and "asm" not in rec[6]["pre_toks"]:
                analyse(types, dflat_unique, dbn, f, code, starts, rec, rows)
    seen = set()
    out = []
    for r in rows:
        key = r[:7]
        if key in seen:
            continue
        seen.add(key)
        if r[0] == "medium" and not a.medium:
            continue
        out.append(r)
    out.sort(key=lambda r: (r[0] != "strong", r[1], r[2]))
    if a.tsv:
        for r in out:
            print("\t".join(str(x) for x in r))
    else:
        for r in out:
            print("%s %s:%d %s %s (%s) [%s]\n    %s" % r)
    funcs = {(r[1], r[3], r[4]) for r in out}
    print("hits: %d (strong %d, medium %d), distinct parameters or locals: %d" % (
        len(out), sum(1 for r in out if r[0] == "strong"), sum(1 for r in out if r[0] == "medium"), len(funcs)),
        file=sys.stderr)
    if a.notes:
        pat = r"as u16|as u8|as s16|as s8|closes it"
        try:
            res = subprocess.run(["grep", "-rnE", pat, "src/game", "src/matched", "docs"], cwd=ROOT,
                                 capture_output=True, text=True, errors="replace").stdout
        except OSError:
            res = ""
        for ln in res.splitlines():
            print("NOTE " + ln[:200])
    return 0


if __name__ == "__main__":
    sys.exit(main())
