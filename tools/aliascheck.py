#!/usr/bin/env python3
"""aliascheck.py: a function declared under a second name.

A caller names a function through a `symbols:` header row (name, address, isa,
optional region) and an `extern` declaration.  The linker resolves the name by
address, so a caller may use a name other than the one the defining file uses
for that address, and everything still builds.  The two names then drift
apart: a rename of the definition leaves the caller's name behind.

This tool lists every such pair.  The definitions come from tools/fnaddr.py:
each src/game source is compiled with its own header settings and laid out
from its `address:`, which gives {function name: address} per file and region.
(Overlays share RAM windows, so a definition is keyed by region and address.)

Checked uses:

  * every `symbols:` row of kind arm or thumb in a src/game .c file
    (a row without a region names an ARM9 main or ITCM function);
  * every identifier of the form func_XXXXXXXX / sub_XXXXXXXX in the code of a
    src/game .c file, looked up in the file's own region and in ARM9.

A use is a mismatch when the definition at that region and address has another
name.  Known second externs are listed in ALLOWED (name, address) and skipped.

    python tools/aliascheck.py            print the mismatches, exit 1 if any
    python tools/aliascheck.py --tsv      tab separated: file line name address region definition
    python tools/aliascheck.py --jobs N   compile in N parallel jobs
"""
import argparse
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)

GAME = os.path.join(ROOT, "src", "game")

# (use name, address): a second extern that is documented and stays.
ALLOWED = {
    ("MIi_CpuClearFastAlias", None),
    # The front end expands memset calls inline (small constant sizes become
    # stores), so a call must keep that name: under the definition's name
    # (MSL_C_LIB_MemsetPtr, MI_CpuFill8) the code differs (gameverify DIFF).
    ("memset", None),
    # A second declaration of the same function with other parameter types:
    # unified under the definition's name and prototype the code differs
    # (gameverify DIFF, 2026-10-19), so the second name is load-bearing.
    ("func_020061E4_2", None),
    ("func_020355D8x", None),
}
# Files whose `symbols:` rows may give the file's own functions a second name
# (none: ov213/comm_btl_demo_main.c unified in wave 18 once its caller
# prototypes matched the definitions).
ALLOWED_FILES = set()
# Symbols the compiler front end writes into a call itself (soft-float and
# integer helpers) or that startup code names: the object file carries these
# names whatever the C source says, so the caller cannot use the name that
# layout/runtime_arm9.txt or the definition file gave the routine.
COMPILER_SYMBOLS = re.compile(
    r"_(?:[fd](?:add|sub|mul|div|flt|fltu|fix|fixu|gr|geq|ls|leq|eq|neq|sqrt)"
    r"|u32_div_f|s32_div_f|ull_mul|ll_\w+|fp_init)|__call_static_initializers")
DEF_FILE = {}   # (region, address, name) -> the src/game file that defines it
# Regions a row without a region may name.
MAIN_REGIONS = ("arm9", "arm9_autoload0_ITCM")

HDR = re.compile(r"\s*/\*.*?\*/", re.S)
ROW = re.compile(r"^\s*\*\s+(\S+)\s+(0x[0-9A-Fa-f]+)\s+(arm|thumb|data)\b\s*(\S*)\s*$")
ADDRNAME = re.compile(r"\b((?:ov\d+_)?(?:func|sub)_([0-9A-Fa-f]{8}))\b")


def game_sources():
    out = []
    for d, _dirs, files in os.walk(GAME):
        for f in files:
            if f.endswith(".c"):
                out.append(os.path.join(d, f))
    return sorted(out)


def read_head(path):
    with open(path, "r", encoding="utf-8", errors="replace", newline="") as fh:
        raw = fh.read()
    m = HDR.match(raw)
    return raw, (m.group(0) if m else "")


def header_fields(head):
    h = {}
    for line in head.splitlines():
        m = re.match(r"^\s*\*?\s*(address|region):\s*(\S+)", line)
        if m:
            h.setdefault(m.group(1), m.group(2))
    return h


def header_rows(head):
    """[(line offset, name, address, kind, region or None)] of the symbols block."""
    rows = []
    on = False
    for i, line in enumerate(head.splitlines()):
        if re.match(r"^\s*\*?\s*symbols:\s*$", line):
            on = True
            continue
        if not on:
            continue
        m = ROW.match(line)
        if m:
            reg = m.group(4) or None
            rows.append((i + 1, m.group(1), int(m.group(2), 16), m.group(3), reg))
        elif re.match(r"^\s*\*\s*$", line) or "*/" in line:
            break
    return rows


def definitions(paths, jobs):
    import fnaddr
    lay = fnaddr.layouts(paths, jobs=jobs)
    defs = {}
    failed = []
    for p in paths:
        lo = lay.get(p)
        if not lo:
            failed.append(p)
            continue
        _raw, head = read_head(p)
        f = header_fields(head)
        reg = f.get("region", "arm9")
        drel = os.path.relpath(p, ROOT).replace(os.sep, "/")
        for n, a in lo.items():
            if n == fnaddr.UNIT_SIZE_KEY:
                continue
            defs.setdefault((reg, a), set()).add(n)
            DEF_FILE[(reg, a, n)] = drel
    return defs, failed


def code_only(text):
    """`text` with comments and string literals blanked (line numbers kept)."""
    return re.sub(r"/\*.*?\*/|//[^\n]*|\"(?:\\.|[^\"\\\n])*\"",
                  lambda m: re.sub(r"[^\n]", " ", m.group(0)), text, flags=re.S)


def exempt(name, addr):
    return ((name, addr) in ALLOWED or (name, None) in ALLOWED
            or COMPILER_SYMBOLS.fullmatch(name) is not None)


def regions_for(row_region, fregion):
    if row_region:
        return (row_region,)
    return MAIN_REGIONS


def check(jobs=None):
    paths = game_sources()
    defs, failed = definitions(paths, jobs)
    rows_out = []
    for p in paths:
        raw, head = read_head(p)
        f = header_fields(head)
        fregion = f.get("region", "arm9")
        rel = os.path.relpath(p, ROOT).replace(os.sep, "/")
        seen = set()
        if rel in ALLOWED_FILES:
            continue
        for ln, name, addr, kind, rreg in header_rows(head):
            if kind == "data":
                continue
            seen.add(name)
            hit = None
            for reg in regions_for(rreg, fregion):
                d = defs.get((reg, addr))
                if d:
                    hit = (reg, d)
                    break
            if hit and name not in hit[1] and not exempt(name, addr):
                rows_out.append((rel, ln, name, addr, hit[0], sorted(hit[1])))
        # code only: a name quoted in a comment or a string is no use of it
        body = re.sub(r"/\*.*?\*/|//[^\n]*|\"(?:\\.|[^\"\\\n])*\"",
                      lambda m: re.sub(r"[^\n]", " ", m.group(0)), raw[len(head):], flags=re.S)
        base_line = head.count("\n")
        for m in ADDRNAME.finditer(body):
            use, a = m.group(1), int(m.group(2), 16)
            if use in seen:
                continue
            seen.add(use)
            hit = None
            for reg in (fregion,) + MAIN_REGIONS:
                d = defs.get((reg, a))
                if d:
                    hit = (reg, d)
                    break
            if hit and use not in hit[1] and not exempt(use, a) \
                    and not any(use.endswith(x) for x in hit[1]):
                ln = base_line + body.count("\n", 0, m.start()) + 1
                rows_out.append((rel, ln, use, a, hit[0], sorted(hit[1])))
    return rows_out, failed


# ------------------------------------------------------------------ fixing

PLACEHOLDER = re.compile(r"^(?:ov\d+_)?(?:func|sub)_[0-9A-Fa-f]{8}\w*$")


def chosen_name(defs):
    real = [d for d in defs if not PLACEHOLDER.match(d)]
    if len(real) == 1:
        return real[0]
    if not real and len(defs) == 1:
        return defs[0]
    return None


def rename_text(text, use, new, calls_only):
    """Rename `use` to `new` in a header row, and in the code either everywhere
    (word match) or only where it is followed by `(` (a call or prototype)."""
    n = 0

    def row(m):
        nonlocal n
        n += 1
        return m.group(1) + new + m.group(2)
    text = re.sub(r"(?m)^(\s*\*\s+)" + re.escape(use) + r"(\s+0x[0-9A-Fa-f]+\s+(?:arm|thumb)\b)",
                  row, text)
    pat = r"\b" + re.escape(use) + (r"\b(?=\s*\()" if calls_only else r"\b")
    head = HDR.match(text)
    hl = len(head.group(0)) if head else 0
    body, k = re.subn(pat, new, text[hl:])
    return text[:hl] + body, n + k


def drop_old_externs(text, use, new):
    """When the file already declares `new` (the definition's name) with an
    extern, that prototype is the definition's: drop the extern of the old
    name instead of renaming it into a second, conflicting declaration."""
    if re.search(r"(?m)^extern\b[^\n;]*\b" + re.escape(new) + r"\s*\([^\n]*\);", text):
        text = re.sub(r"(?m)^extern\b[^\n;]*\b" + re.escape(use) + r"\s*\([^\n]*\);[ \t]*\n", "", text)
    return text


def def_signature(def_rel, name):
    """The definition's head `ret name(params)` as one line, or None.  Looks
    for a line that starts a definition (`{` follows) or a prototype of the
    name in the defining file; whitespace is collapsed."""
    path = os.path.join(ROOT, *def_rel.split("/"))
    with open(path, "r", encoding="utf-8", newline="") as fh:
        raw = fh.read()
    pat = re.compile(r"(?m)^(?!extern\b)([A-Za-z_][\w \t\*]*?\b" + re.escape(name) +
                     r"\s*\([^;{}]*\))\s*\{")
    m = pat.search(raw)
    if not m:
        return None
    sig = re.sub(r"\s+", " ", m.group(1)).strip()
    sig = re.sub(r"^(?:static|inline|asm)\s+", "", sig)
    return sig


def adopt_signature(text, new, sig):
    """Replace every single-line extern of `new` by `extern <sig>;`."""
    pat = re.compile(r"(?m)^extern\b[^\n;]*\b" + re.escape(new) + r"\s*\([^\n]*\);[ \t]*$")
    if not pat.search(text) or sig is None:
        return text
    return pat.sub(lambda _m: "extern " + sig + ";", text)


def dedupe(text, names=()):
    """Drop a repeated symbols row (same name and address) and a repeated
    identical `extern` line made by renaming two names to one."""
    out, seen_rows, seen_ext, seen_fn = [], set(), set(), set()
    for line in text.split("\n"):
        m = re.match(r"^\s*\*\s+(\S+)\s+(0x[0-9A-Fa-f]+)\s+(arm|thumb|data)\b", line)
        if m:
            key = (m.group(1), int(m.group(2), 16))
            if key in seen_rows:
                continue
            seen_rows.add(key)
        elif line.startswith("extern ") and line.rstrip().endswith(";"):
            key = re.sub(r"\s+", " ", line.strip())
            if key in seen_ext:
                continue
            seen_ext.add(key)
            nm = [n for n in names if re.search(r"\b" + re.escape(n) + r"\s*\(", line)]
            if nm:
                # one declaration per renamed function: the first one stays
                if nm[0] in seen_fn:
                    continue
                seen_fn.add(nm[0])
        out.append(line)
    return "\n".join(out)


def verify_file(rel):
    import subprocess
    r = subprocess.run([sys.executable, os.path.join(HERE, "gameverify.py"), "--file", rel],
                       cwd=ROOT, capture_output=True, text=True)
    last = (r.stdout.strip().splitlines() or [""])[-1]
    if "not exact: 0," not in last:
        last = " | ".join((r.stdout + r.stderr).strip().splitlines()[-6:])
    return "not exact: 0," in last and "MATCH (relocations wildcarded): 0" in last, last


def apply_fixes(rows, only=None, adopt=False):
    by_file = {}
    regs_all = {}
    for rel, ln, use, a, reg, d in rows:
        by_file.setdefault(rel, []).append((use, a, reg, d))
        regs_all[(rel, use)] = reg
    report = []
    for rel, items in sorted(by_file.items()):
        if only and rel not in only:
            continue
        path = os.path.join(ROOT, *rel.split("/"))
        with open(path, "r", encoding="utf-8", newline="") as fh:
            orig = fh.read()
        plan, skipped = [], []
        regs = {u: regs_all[(rel, u)] for (r2, u) in regs_all if r2 == rel}
        rows_here = {(n, a) for n, a, _k, _r in
                     [(r[1], r[2], r[3], r[4]) for r in header_rows(read_head(path)[1])]}
        for use, a, reg, d in items:
            new = chosen_name(d)
            if new is None:
                skipped.append((use, "ambiguous: " + ",".join(d)))
            elif DEF_FILE.get((reg, a, new)) == rel:
                plan.append((use, new, True))
            elif re.search(r"\b" + re.escape(new) + r"\b", code_only(orig)) and (new, a) not in rows_here:
                skipped.append((use, "%s already used in the file" % new))
            else:
                plan.append((use, new, False))
        if not plan:
            report.append((rel, "SKIP", skipped))
            continue
        heads = {}
        for inc in re.findall(r'(?m)^#include\s+"([^"]+)"', orig):
            hp = os.path.join(os.path.dirname(path), inc)
            if os.path.isfile(hp):
                with open(hp, "r", encoding="utf-8", newline="") as fh:
                    heads[hp] = fh.read()
        ok, last = False, ""
        for calls_only in (True, False):
            text = orig
            for use, new, own in plan:
                if own:
                    # the file defines the function itself: its row and extern
                    # for the old name are redundant
                    text = re.sub(r"(?m)^\s*\*\s+" + re.escape(use) + r"\s+0x[0-9A-Fa-f]+\s+(?:arm|thumb)\b.*\n", "", text)
                    text = re.sub(r"(?m)^extern\b[^\n;]*\b" + re.escape(use) + r"\s*\([^\n]*\);[ \t]*\n", "", text)
                text = drop_old_externs(text, use, new)
                text, _n = rename_text(text, use, new, calls_only)
            text = dedupe(text, [n for _u, n, _o in plan])
            if adopt:
                for use, new, _o in plan:
                    dfile = next((DEF_FILE[k] for k in DEF_FILE if k[2] == new and
                                  k[0] == regs.get(use)), None)
                    if dfile and dfile != rel:
                        text = adopt_signature(text, new, def_signature(dfile, new))
            htext = {}
            for hp, ht in heads.items():
                t2 = ht
                for use, new, _o in plan:
                    t2 = re.sub(r"\b" + re.escape(use) + (r"\b(?=\s*\()" if calls_only else r"\b"),
                                new, t2)
                if t2 != ht:
                    htext[hp] = t2
            with open(path, "w", encoding="utf-8", newline="") as fh:
                fh.write(text)
            for hp, t2 in htext.items():
                with open(hp, "w", encoding="utf-8", newline="") as fh:
                    fh.write(t2)
            ok, last = verify_file(rel)
            if ok:
                break
            for hp in htext:
                with open(hp, "w", encoding="utf-8", newline="") as fh:
                    fh.write(heads[hp])
        if not ok:
            with open(path, "w", encoding="utf-8", newline="") as fh:
                fh.write(orig)
            report.append((rel, "REVERTED " + last, plan + skipped))
        else:
            report.append((rel, "OK", skipped + [("headers", sorted(os.path.relpath(h, ROOT) for h in htext))]))
    return report


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--tsv", action="store_true")
    ap.add_argument("--jobs", type=int, default=None)
    ap.add_argument("--adopt", action="store_true",
                    help="with --apply: also copy the definition's prototype into the caller")
    ap.add_argument("--apply", nargs="*", metavar="FILE",
                    help="rename each use to the definition's name (all files, or the named "
                         "repo-relative files), verify each file, revert the ones that fail")
    args = ap.parse_args(argv)
    rows, failed = check(args.jobs)
    if args.apply is not None:
        for rel, state, info in apply_fixes(rows, set(args.apply) or None, args.adopt):
            print("%s: %s %s" % (state, rel, info))
        return 0
    for rel, ln, name, a, reg, d in rows:
        if args.tsv:
            print("%s\t%d\t%s\t0x%08X\t%s\t%s" % (rel, ln, name, a, reg, ",".join(d)))
        else:
            print("%s:%d: %s 0x%08X [%s] is defined as %s" % (rel, ln, name, a, reg, ", ".join(d)))
    print("aliascheck: %d mismatch(es); %d source(s) did not compile" % (len(rows), len(failed)),
          file=sys.stderr)
    for p in failed[:20]:
        print("  no layout: %s" % os.path.relpath(p, ROOT).replace(os.sep, "/"), file=sys.stderr)
    return 1 if rows else 0


if __name__ == "__main__":
    sys.exit(main())
