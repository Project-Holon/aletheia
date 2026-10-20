#!/usr/bin/env python3
"""mkcast.py: finish what tools/mkheaders.py could not convert.

mkheaders leaves a caller's extern declarations in place when the definition's
prototype does not compile against the caller (a pointer passed as an int, a
callback of another type, a result stored in another type).  This tool takes
those callers, applies the whole plan (all externs removed, owner headers
included), compiles, and for every conversion error on a call line adds the
cast the old declaration hid:

  * an argument whose parameter is a pointer or function pointer gets a cast to
    the parameter type (integer parameters are never cast, a cast would add
    code);
  * a call whose result is stored in another type gets a cast to that type.

The result must compile and be EXACT (tools/gameverify.py).  A file that does
not get there is put back as it was and listed.

    python tools/mkcast.py --files LIST [--jobs N]
"""
import argparse
import concurrent.futures
import os
import re
import shutil
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import mkheaders as mk  # noqa: E402
import match  # noqa: E402
import gameverify as gv  # noqa: E402

LOGLINE = re.compile(r"^(.*?):(\d+): (.*)$")


def compile_log(path):
    raw = open(path, encoding="latin1").read()
    _h, st = gv.settings_of(raw)
    work = tempfile.mkdtemp(prefix="mkc_")
    try:
        obj, _c, log, _rc = match.compile_tu(path, st["compiler"], st["flags"].split(), st["isa"] == "thumb",
                                             st["lang"] or None, work)
    finally:
        shutil.rmtree(work, ignore_errors=True)
    return obj is not None, log


def errors_of(path, log):
    """{line: [message parts]} for the errors that sit in the file itself."""
    out = {}
    base = os.path.basename(path)
    for l in log.split("\n"):
        m = LOGLINE.match(l.strip())
        if not m:
            continue
        where = m.group(1).replace(chr(92), "/")
        if os.path.basename(where) != base or m.group(3).startswith("warning"):
            continue
        out.setdefault(int(m.group(2)), []).append(m.group(3).strip())
    return out


def split_args(text, start):
    """Offsets of the arguments of the call whose '(' is at text[start]; returns ([(s, e)], end of call)."""
    depth = 0
    args = []
    s = start + 1
    i = start
    while i < len(text):
        c = text[i]
        if c in "([{":
            depth += 1
        elif c in ")]}":
            depth -= 1
            if depth == 0:
                if text[s:i].strip():
                    args.append((s, i))
                return args, i + 1
        elif c == "," and depth == 1:
            args.append((s, i))
            s = i + 1
        i += 1
    return args, len(text)


def param_types(proto):
    m = re.match(r"^(.*?)\b(\w+)\s*\((.*)\)\s*$", " ".join(proto.replace("extern", " ").split()).rstrip(";"), re.S)
    if not m:
        return None, []
    inner = m.group(3).strip()
    ps = []
    if inner and inner != "void":
        for p in mk.pn.split_params(inner):
            ps.append(p.strip())
    return m.group(1).strip(), ps


def type_of_param(p):
    """Cast text of a parameter (name dropped), or None when it is not a pointer type."""
    if "(" in p:                                   # function pointer
        m = re.match(r"^(.*?)\(\s*\*\s*(\w*)\s*\)\s*\((.*)\)$", p, re.S)
        if not m:
            return None
        return "%s(*)(%s)" % (m.group(1).strip() + " ", m.group(3).strip())
    if "*" not in p:
        return None
    toks = mk.strip_name(p)
    out = []
    for t in toks:
        out.append(t)
    txt = " ".join(out).replace(" *", " *").replace("* *", "**")
    return re.sub(r"\s+\*", " *", txt).replace(" * ", " *")


def fix_line(text, lineno, parts, defs):
    """Add casts to the calls on (or just above) lineno.  Returns the new text or None."""
    lines = text.split("\n")
    lo = max(0, lineno - 4)
    base = sum(len(l) + 1 for l in lines[:lo])
    window = "\n".join(lines[lo:lineno])
    changed = False
    for name, (ret, ps) in defs.items():
        for m in list(re.finditer(r"\b%s\s*\(" % re.escape(name), window))[::-1]:
            op = m.end() - 1
            args, endc = split_args(window, op)
            edits = []
            for j, (s, e) in enumerate(args):
                if j >= len(ps):
                    break
                ct = type_of_param(ps[j])
                if ct is None:
                    continue
                a = window[s:e].strip()
                if a.startswith("(" + ct + ")") or a in ("0", "NULL", "(void *)0"):
                    continue
                lead = window[s:e][:len(window[s:e]) - len(window[s:e].lstrip())]
                edits.append((s, e, "%s(%s)%s" % (lead, ct, a if re.fullmatch(r"[\w.>\-\[\]]+|&\w[\w.>\-\[\]]*", a) else "(" + a + ")")))
            for s, e, t in sorted(edits, reverse=True):
                window = window[:s] + t + window[e:]
                changed = True
    if not changed:
        return None
    out = "\n".join(lines[:lo] + [window] + lines[lineno:])
    return out


def wrap_result(text, lineno, parts, defs):
    """A call whose result is converted: cast the call to the destination type named by the error."""
    msg = " ".join(parts)
    m = re.search(r"from '([^']+)' to\s*'([^']+)'", msg)
    if not m:
        return None
    dst = m.group(2)
    lines = text.split("\n")
    l = lines[lineno - 1]
    for name in defs:
        mm = re.search(r"\b%s\s*\(" % re.escape(name), l)
        if not mm:
            continue
        args, endc = split_args(l, mm.end() - 1)
        if endc > len(l):
            continue
        if re.search(r"\(\s*%s\s*\)\s*$" % re.escape(dst), l[:mm.start()]):
            continue
        lines[lineno - 1] = l[:mm.start()] + "(%s)" % dst + l[mm.start():]
        return "\n".join(lines)
    return None


def process(idx, hdrs, f, log_rows):
    plan = mk.plan_caller(idx, hdrs, f)
    if not plan.removals:
        return "none", 0
    orig = plan.raw
    skip = set()
    for _round in range(30):
        res = attempt(idx, hdrs, f, plan, orig, skip, log_rows)
        if res[0] != "restart":
            return res
        skip |= res[1]
    mk.write(f, orig)
    return "failed: too many rounds", 0


def attempt(idx, hdrs, f, plan, orig, skip, log_rows):
    text, _a, _t = mk.apply_plan(idx, hdrs, plan, skip_owners=sorted(skip), inject=True)
    if text == orig:
        return "kept all", 0
    defs = {}
    for r in plan.removals:
        if r[3].file in skip:
            continue
        ret, ps = param_types(r[3].proto)
        if ret is not None:
            defs[r[2]] = (ret, ps, r[3].file)
    tried = set()
    for _ in range(150):
        mk.write(f, text)
        ok, log = compile_log(f)
        if ok:
            break
        errs = errors_of(f, log)
        progress = False
        for ln in sorted(errs):
            parts = errs[ln]
            new = None
            if (ln, "args") not in tried:
                tried.add((ln, "args"))
                new = fix_line(text, ln, parts, {k: v[:2] for k, v in defs.items()})
            if new is None and (ln, "res") not in tried:
                tried.add((ln, "res"))
                new = wrap_result(text, ln, parts, defs)
            if new is not None and new != text:
                text = new
                progress = True
                break
        if progress:
            continue
        # not fixable with a cast: the definition disagrees with the caller; keep the old declarations of that owner
        lines = text.split("\n")
        culprits = set()
        for ln in sorted(errs):
            win = "\n".join(lines[max(0, ln - 4):ln])
            for name, v in defs.items():
                if re.search(r"%s\s*\(" % re.escape(name), win):
                    culprits.add(v[2])
        culprits -= skip
        if culprits:
            for r in plan.removals:
                if r[3].file in culprits:
                    log_rows.append((mk.rel(f), r[2], r[4], r[3].proto, "no cast fixes it: " + " ".join(next(iter(sorted(errs.items())))[1])[:100]))
            return "restart", culprits
        mk.write(f, orig)
        first = next(iter(sorted(errs.items())), (0, ["?"]))
        return "failed: line %s %s" % (first[0], " ".join(first[1])[:150]), 0
    else:
        mk.write(f, orig)
        return "failed: no fixpoint", 0
    good, _m = mk.verify_file(f)
    if not good:
        # find the owner group that changes the bytes
        owners = sorted({r[3].file for r in plan.removals} - skip)
        bad = set()
        for of in owners:
            t2, _a, _t = mk.apply_plan(idx, hdrs, plan, skip_owners=sorted(set(owners) - {of} | skip), inject=True)
            mk.write(f, t2)
            ok2, _l = compile_log(f)
            if not ok2:
                continue
            if not mk.verify_file(f)[0]:
                bad.add(of)
        if bad:
            for r in plan.removals:
                if r[3].file in bad:
                    log_rows.append((mk.rel(f), r[2], r[4], r[3].proto, "bytes differ"))
            return "restart", bad
        mk.write(f, orig)
        return "bytes differ", 0
    return ("ok" if not skip else "partial"), len(plan.removals)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--files", required=True)
    ap.add_argument("--jobs", type=int, default=4)
    ap.add_argument("--report")
    a = ap.parse_args()
    files = sorted(mk.ph.files_under([mk.GAME]))
    idx = mk.Index(files)
    hdrs = mk.build_headers(idx)
    todo = [os.path.normpath(os.path.join(mk.ROOT, l.strip())) for l in open(a.files) if l.strip()]

    rows = []

    def work(f):
        return f, process(idx, hdrs, f, rows)

    with concurrent.futures.ThreadPoolExecutor(max_workers=a.jobs) as pool:
        for f, (st, n) in pool.map(work, todo):
            print("%-10s %s (%d externs removed)" % (st[:150], mk.rel(f), n), flush=True)
    if a.report:
        with open(a.report, "w", newline="\n") as fh:
            fh.write("file\tfunction\told prototype\tdefinition prototype\twhy\n")
            for r in rows:
                fh.write("\t".join(r) + "\n")


if __name__ == "__main__":
    main()
