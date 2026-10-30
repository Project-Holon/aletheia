#!/usr/bin/env python3
"""
jarewrite.py -- rewrite the mechanical Japanese differences of src/game files.

    python tools/jarewrite.py [--target black_ja] [--dry-run] [--apply] FILE... [--call NAME:ARG ...]

A Black function and its Japanese twin (the pairing of tools/langcheck.py, which this tool runs
first) are walked call by call.  For each call of a listed callee (default: GF_PANIC_Fail,
GF_PANIC_FailPrintf and GFL_HEAP_Alloc* with the line number argument) the value that the
Japanese code loads into the line argument is read from the target listing (mov/movs immediate,
literal pool load, copy, adds) and set against the value Black loads.  The k-th such call in the
English source function is then rewritten:

  line literal       L  ->  PM_SRC_LINE(L, japanese line)       (source line numbers)
  GF_PANIC_Fail(S, 0, E) where Japanese passes a file string, a line and an expression
                     ->  GF_PANIC_Fail(PM_LANG_JA(S, str_ja_FILE), PM_SRC_LINE(0, LINE),
                                       PM_LANG_JA(E, str_ja_EXPR))
  with  extern const char str_ja_XXXXXXXX[];  declared under #if LANGUAGE == LANGUAGE_JAPANESE
  (XXXXXXXX: the string's address in black_ja).

A site is rewritten only when the Black value read from the listing equals the literal of the
English source (a check that the call is the right one) and the site is not already converted.
Without --apply the tool lists what it would change (dry run, the default).  With --apply each
file is backed up (build/lanes/JP-T2/bak/), edited, then checked: gameverify --file must be EXACT
and langcheck for the target must not report more differing functions; otherwise the file is
restored.  Output is deterministic.  Stdlib only.
"""
import argparse
import os
import re
import shutil
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)

DEFAULT_CALLS = ["GF_PANIC_Fail:1", "GF_PANIC_FailPrintf:1", "GFL_HEAP_Alloc:4", "GFL_HEAP_AllocClear:4",
                 "WORDSET_SetSlotNumber:5"]
# Callees whose argument is the digit width (isHalfWidth: Japanese 0, the others 1), not a line.
DIGIT_CALLS = {"WORDSET_SetSlotNumber"}
CALL_RE = re.compile(r"\bbl?x?(?:\.\w+)?\s+(\S+)")
HEX_RE = re.compile(r"0x([0-9A-F]{8})")
LBL_RE = re.compile(r"^\s*(?:[A-Za-z_]\w*):\s*$")


def parse_insns(lines):
    """[(address, text)] of the instructions of a function body (labels give (None, 'label'))."""
    out = []
    for l in lines:
        m = re.match(r"\s*([a-z][\w.]*)\s*(.*?)\s*(?:/\*\s*([0-9A-F]{8}).*?\*/.*)?$", l)
        if LBL_RE.match(l):
            out.append((None, "label"))
        elif m and not l.strip().startswith("."):
            out.append((m.group(3), (m.group(1) + " " + m.group(2)).strip() + " ;" + l))
        elif l.strip().startswith(".inst.w"):
            c = re.search(r"/\*\s*([0-9A-F]{8})", l)
            out.append((c.group(1) if c else None, "call ;" + l))
    return out


def pools(lines):
    d = {}
    for k, l in enumerate(lines):
        m = re.match(r"(pool_[0-9A-F]{8}|lit_[0-9A-F]{8}):", l)
        if m:
            for l2 in lines[k + 1:k + 3]:
                w = re.match(r"\s*\.word\s+(0x[0-9A-Fa-f]+)", l2)
                if w:
                    d[m.group(1)] = int(w.group(1), 16)
                    break
    return d


def value(ins, i, reg, pool, depth=0):
    """Value of `reg` before instruction i, or None."""
    if depth > 6:
        return None
    j = i - 1
    while j >= 0:
        _a, t = ins[j]
        if t == "label":
            return None
        txt = t.split(" ;")[0]
        ln = t
        if txt.startswith("call") or re.match(r"bl\b|blx\b", txt):
            if reg in ("r0", "r1", "r2", "r3"):
                return None
        else:
            m = re.match(r"(\w+?)s?\s+(\w+),\s*(.*)$", txt)
            if m and m.group(2) == reg and not txt.startswith(("cmp", "cmn", "tst", "str", "b")):
                op, rest = m.group(1), m.group(3)
                if op in ("mov", "mov.w"):
                    mm = re.match(r"#(-?0x[0-9a-fA-F]+|-?\d+)$", rest)
                    if mm:
                        return int(mm.group(1), 0)
                    if re.match(r"r\d+$", rest):
                        return value(ins, j, rest, pool, depth + 1)
                    return None
                if op == "ldr":
                    mm = re.match(r"(pool_[0-9A-F]{8})", rest)
                    return pool.get(mm.group(1)) if mm else None
                if op == "add":
                    mm = re.match(r"#(-?0x[0-9a-fA-F]+|-?\d+)$", rest)
                    if mm:
                        v = value(ins, j, reg, pool, depth + 1)
                        return None if v is None else v + int(mm.group(1), 0)
                    mm = re.match(r"(r\d+),\s*#0$", rest)
                    if mm:
                        return value(ins, j, mm.group(1), pool, depth + 1)
                if op == "lsl":                  # movs rN,#k; lsls rN,rN,#s: a line of k << s
                    mm = re.match(r"(?:(r\d+),\s*)?#(0x[0-9a-fA-F]+|\d+)$", rest)
                    if mm:
                        v = value(ins, j, mm.group(1) or reg, pool, depth + 1)
                        return None if v is None else v << int(mm.group(2), 0)
                return None
        j -= 1
    return None


def stack_arg(ins, i, slot, pool):
    """Value stored at [sp, #4*slot] before the call at i (slot 0 = fifth argument)."""
    pat = re.compile(r"str\s+(r\d+),\s*\[sp(?:,\s*#(0x[0-9a-fA-F]+|\d+))?\]")
    for j in range(i - 1, max(i - 14, -1), -1):
        t = ins[j][1].split(" ;")[0]
        if ins[j][1] == "label":
            return None
        m = pat.match(t)
        if m and (int(m.group(2), 0) if m.group(2) else 0) == 4 * slot:
            return value(ins, j, m.group(1), pool)
    return None


def call_sites(lines, callee_names, pool, region_pool=None):
    """[(callee, regs{0..3}, argfn)] in listing order; callee_names: {address: name}."""
    ins = parse_insns(lines)
    out = []
    for i, (_a, t) in enumerate(ins):
        txt = t.split(" ;")[0]
        full = t
        addr = None
        h = HEX_RE.findall(full.split(" ;", 1)[-1]) if " ;" in full else []
        m = re.search(r"(?:blx?|bl\.w)\s+(?:func_)?([0-9A-F]{8})\b", full)
        if m:
            addr = int(m.group(1), 16)
        elif h and ("blx" in full or "call" in txt):
            addr = int(h[-1], 16)
        if addr is None:
            continue
        if addr in callee_names:
            out.append((callee_names[addr], i, ins, pool))
    return out


def mask(src):
    """Source with comments and strings blanked (same length)."""
    def blank(m):
        return re.sub(r"[^\n]", " ", m.group(0))
    return re.sub(r"/\*.*?\*/|//[^\n]*|\"(?:\\.|[^\"\\])*\"|'(?:\\.|[^'\\])*'", blank, src, flags=re.S)


def balanced(txt, i, o="(", c=")"):
    d = 0
    for k in range(i, len(txt)):
        if txt[k] == o:
            d += 1
        elif txt[k] == c:
            d -= 1
            if d == 0:
                return k
    return -1


def split_args(txt, a, b):
    """[(start, end)] of the arguments between a and b (offsets inside txt)."""
    out, d, s = [], 0, a
    for k in range(a, b):
        ch = txt[k]
        if ch in "([{":
            d += 1
        elif ch in ")]}":
            d -= 1
        elif ch == "," and d == 0:
            out.append((s, k))
            s = k + 1
    out.append((s, b))
    return out


def func_span(mtxt, name):
    for m in re.finditer(r"(?m)^[A-Za-z_][^\n;{}]*?\b%s\s*\(" % re.escape(name), mtxt):
        p = balanced(mtxt, m.end() - 1)
        if p < 0:
            continue
        k = p + 1
        while k < len(mtxt) and mtxt[k] in " \t\r\n":
            k += 1
        if k < len(mtxt) and mtxt[k] == "{":
            return k, balanced(mtxt, k, "{", "}")
    return None


def fmt_like(tok, v):
    t = tok.strip()
    if t.lower().startswith("0x"):
        h = format(v, "X" if t[2:] == t[2:].upper() and re.search("[A-F]", t[2:]) else "x")
        return "0x" + h
    return str(v)


def num(expr):
    e = expr.strip()
    if re.fullmatch(r"[0-9xXa-fA-F+\-*() ]+", e) and not re.search(r"[g-wyzG-WYZ]", e):
        try:
            return eval(e, {"__builtins__": {}})
        except Exception:
            return None
    return None


def plan_file(path, target, calls):
    """Return (edits, externs, notes) for one file."""
    import match  # noqa: F401
    import white_map
    import langcheck
    import json
    import targets
    white_map.set_target(target)
    rel = os.path.relpath(path, ROOT).replace("\\", "/")
    funcs = []
    with open(os.path.join(ROOT, "layout", "function_addrs.tsv"), encoding="utf-8") as fh:
        next(fh)
        by_name = {}
        for row in fh:
            p = row.rstrip("\n").split("\t")
            if len(p) >= 6:
                by_name[p[2]] = (p[0], int(p[1], 16))
                if p[5] == rel:
                    funcs.append((int(p[1], 16), p[2], p[0]))
    funcs.sort()
    cache_p = os.path.join(targets.build_dir(target), "langcheck_map.json")
    try:
        cache = json.load(open(cache_p, encoding="utf-8"))
    except (OSError, ValueError):
        cache = {}
    tasm = os.path.join(targets.build_dir(target), "asm")
    src = open(path, encoding="latin1", newline="").read()
    msrc = mask(src)
    spec = {}
    for c in calls:
        n, a = c.split(":")
        spec[n] = int(a)
    cn_b, cn_t = {}, {}
    for n, a in spec.items():
        for nm, (rg, ad) in by_name.items():
            if nm == n or (n.endswith("Alloc") and nm.startswith(n) and False):
                cn_b[ad & ~1] = nm
                try:
                    cn_t[white_map.to_white(ad, None) & ~1] = nm
                except KeyError:
                    pass
    lists = {}
    edits, externs, notes = [], [], []
    for baddr, name, region in funcs:
        key = "%s:%X" % (region, baddr)
        if key not in cache:
            continue
        if region not in lists:
            lb, lt = langcheck.listing(os.path.join(ROOT, "asm"), region), langcheck.listing(tasm, region)
            lists[region] = (lb, langcheck.index(lb), pools(lb), lt, langcheck.index(lt), pools(lt))
        lb, ib, pb, lt, it, pt = lists[region]
        ta = cache[key][0]
        if baddr & ~1 not in ib or ta not in it:
            continue
        sb = call_sites(langcheck.body(lb, ib[baddr & ~1]), cn_b, pb)
        st = call_sites(langcheck.body(lt, it[ta]), cn_t, pt)
        if not sb:
            continue
        span = func_span(msrc, name)
        if span is None:
            notes.append("%s: function not found in the source" % name)
            continue
        bs, be = span
        srcc = [m for m in re.finditer(r"\b(%s)\s*\(" % "|".join(map(re.escape, spec)), msrc[bs:be])]
        if not (len(sb) == len(st) == len(srcc)):
            notes.append("%s: call counts differ (black %d, target %d, source %d)" % (name, len(sb), len(st), len(srcc)))
            continue
        for (cb, ib_, insb, plb), (ct, it_, inst, plt), sm in zip(sb, st, srcc):
            if cb != ct or sm.group(1) != cb:
                notes.append("%s: call order differs" % name)
                break
            idx = spec[cb]

            def line_of(ins_, i_, pl_):
                if idx < 4:
                    return value(ins_, i_, "r%d" % idx, pl_)
                return stack_arg(ins_, i_, idx - 4, pl_)
            vb, vt = line_of(insb, ib_, plb), line_of(inst, it_, plt)
            op = bs + sm.end() - 1
            cl = balanced(msrc, op)
            args = split_args(msrc, op + 1, cl)
            if idx >= len(args):
                continue
            a0, a1 = args[idx]
            expr = src[a0:a1]
            if "PM_SRC_LINE" in expr:
                m2 = re.search(r"PM_SRC_LINE\(\s*(.*?)\s*,\s*(.*?)\s*\)\s*$", expr, re.S)
                jv = num(m2.group(2)) if m2 else None
                if m2 and jv is not None and vt is not None and jv != vt:
                    notes.append("%s: existing PM_SRC_LINE has %s, Japanese has 0x%X" % (name, m2.group(2), vt))
                continue
            ev = num(expr)
            if vb is None or vt is None or ev is None or ev != vb:
                if vb is not None and vt is not None and vb != vt:
                    notes.append("%s: %s line %s (black %s, ja %s) not paired" % (name, cb, expr.strip(), vb, vt))
                continue
            lead = expr[:len(expr) - len(expr.lstrip())]
            tok = expr.strip()
            if cb in DIGIT_CALLS:
                if vb == 1 and vt == 0 and tok == "1":
                    edits.append((a0, a1, a0, "PM_LANG_HALF_WIDTH_DIGITS", lead))
                continue
            if vb == vt and not (cb.startswith("GF_PANIC") and vb == 0):
                continue
            if cb.startswith("GF_PANIC") and vb == 0 and vt != 0 and len(args) == 3:
                f_b = value(insb, ib_, "r0", plb)
                x_b = value(insb, ib_, "r2", plb)
                f_t, x_t = value(inst, it_, "r0", plt), value(inst, it_, "r2", plt)
                if None in (f_b, x_b, f_t, x_t) or f_b != x_b:
                    notes.append("%s: panic strings not readable" % name)
                    continue
                s0, s2 = src[args[0][0]:args[0][1]].strip(), src[args[2][0]:args[2][1]].strip()
                new0 = "PM_LANG_JA(%s, str_ja_%08X)" % (s0, f_t)
                new2 = "PM_LANG_JA(%s, str_ja_%08X)" % (s2, x_t)
                new1 = "PM_SRC_LINE(0, %s)" % fmt_like("0x0", vt) if False else "PM_SRC_LINE(0, 0x%X)" % vt
                edits.append((args[0][0], args[0][1], args[0][0], new0, lead))
                edits.append((a0, a1, a0, new1, lead))
                edits.append((args[2][0], args[2][1], args[2][0], new2, lead))
                externs += [f_t, x_t]
            else:
                edits.append((a0, a1, a0, "PM_SRC_LINE(%s, %s)" % (tok, fmt_like(tok, vt)), lead))
    return src, sorted(set(edits)), sorted(set(externs)), notes


def apply_edits(src, edits, externs):
    out = src
    for s, e, _p, new, lead in sorted(edits, reverse=True):
        old = out[s:e]
        lead2 = old[:len(old) - len(old.lstrip())]
        out = out[:s] + lead2 + new + old[len(old.rstrip()):] + out[e:]
    if edits and "version.h" not in out:
        incs = list(re.finditer(r"(?m)^#include [^\n]*\n", out))
        pos = incs[0].end() if incs else 0      # some files include more headers after code: use the first
        out = out[:pos] + '#include "../version.h"\n' + out[pos:]
    if externs:
        decl = "#if LANGUAGE == LANGUAGE_JAPANESE\n" + "".join(
            "extern const char str_ja_%08X[];\n" % x for x in externs if "str_ja_%08X[]" % x not in out) + "#endif\n"
        if decl.count("extern"):
            incs = list(re.finditer(r"(?m)^#include [^\n]*\n", out))
            if "version.h" not in out:
                decl = '#include "../version.h"\n' + decl
            vh = re.search(r'(?m)^#include "\.\./version\.h"\n', out)
            pos = vh.end() if vh else (incs[0].end() if incs else 0)   # before any use in the file
            out = out[:pos] + decl + out[pos:]
    return out


def run(cmd):
    return subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)


def differ_count(target, path):
    r = run([sys.executable, "tools/langcheck.py", "--target", target, path])
    m = re.search(r": (\d+) of \d+ functions differ", r.stdout)
    return int(m.group(1)) if m else 10 ** 6


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[1])
    ap.add_argument("files", nargs="+")
    ap.add_argument("--target", default="black_ja")
    ap.add_argument("--dry-run", action="store_true", help="list the changes only (default)")
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--call", action="append", help="NAME:ARG, argument index of the line number")
    a = ap.parse_args()
    os.chdir(ROOT)
    os.environ["ALETHEIA_TARGET"] = a.target
    calls = a.call or DEFAULT_CALLS
    total = 0
    for f in a.files:
        path = os.path.abspath(f)
        rel = os.path.relpath(path, ROOT).replace("\\", "/")
        before = differ_count(a.target, path)
        src, edits, externs, notes = plan_file(path, a.target, calls)
        for n in notes:
            print("  note %s: %s" % (rel, n))
        print("%s: %d edits, %d externs, %d notes" % (rel, len(edits), len(externs), len(notes)))
        total += len(edits)
        for e in edits:
            print("    line %d: %s" % (src.count(chr(10), 0, e[0]) + 1, e[3]))
        if not edits or not a.apply or a.dry_run:
            continue
        bak = os.path.join(ROOT, "build", "lanes", "JP-T2", "bak", rel.replace("/", "__"))
        os.makedirs(os.path.dirname(bak), exist_ok=True)
        shutil.copyfile(path, bak)
        new = apply_edits(src, edits, externs)
        with open(path, "w", encoding="latin1", newline="") as fh:
            fh.write(new)
        ok = "EXACT" in run([sys.executable, "tools/gameverify.py", "--file", rel]).stdout
        after = differ_count(a.target, path) if ok else None
        if not ok or after is None or after > before:
            shutil.copyfile(bak, path)
            print("  REVERTED %s (exact=%s, differing %s -> %s)" % (rel, ok, before, after))
        else:
            print("  applied %s (differing functions %d -> %d)" % (rel, before, after))
    print("total edits: %d" % total)


if __name__ == "__main__":
    main()
