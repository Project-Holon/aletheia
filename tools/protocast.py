#!/usr/bin/env python3
"""protocast.py: make calls agree with the callee's definition by casts at the call.

A caller of a function declares it with its own `extern` that differs from the
definition (a stand-in struct, a narrower integer, a pointer where the
definition takes an integer).  tools/mkheaders.py replaces such a declaration by
the definition's header only when the caller still compiles to the same bytes.
This tool prepares the caller: at every call of a mismatching function it adds
the casts that keep the bytes of the old declaration while the call type checks
against the definition.

  parameter, integer in both:      cast to the declared (old) type
  parameter, pointer in both:      cast to void * (unless the old type is void *)
  parameter, integer -> pointer:   cast to void *
  parameter, pointer -> integer:   cast to the definition's integer type
  return value, any pair:          the whole call is cast to the declared type

Mismatches that need a decision by hand (a void definition whose result the
caller uses, a different parameter count, a function pointer parameter) are
listed and left alone.  A file is kept only when tools/gameverify.py still says
EXACT (or MATCH, when it was before); otherwise the file is restored.

    python tools/protocast.py --files LIST [--log OUT] [--dry]
"""
import argparse
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import protocheck as pc  # noqa: E402

ENTRY = re.compile(r"^(src/game/\S+):(\d+)\s+(\S+)\s+\[(.*)\]$")
INTS = {"u8", "s8", "char", "u16", "s16", "u32", "s32", "u64", "s64"}
KEYW = {"return", "else", "do", "case", "goto", "sizeof", "typedef", "if", "while", "for", "switch"}


def parse_sig(text):
    """'ret (p1, p2)' -> (ret, [params] or None for unproto)."""
    text = text.strip()
    m = re.match(r"(.*?)\s*\((.*)\)\s*(\(src/game/\S+\))?$", text)
    if not m:
        return None
    ret = m.group(1).strip()
    inner = m.group(2).strip()
    if inner == "?":
        return ret, None
    if inner == "":
        return ret, []
    return ret, [p.strip() for p in inner.split(", ")]


def is_ptr(t):
    return t.endswith("*")


def tytext(t):
    """Canonical type text -> C spelling."""
    if t.endswith("*"):
        base = t.rstrip("*")
        return base.strip() + " " + "*" * (len(t) - len(base))
    return t


def read_entries(pc_text, prefixes):
    ents = []
    lines = pc_text.split("\n")
    i = 0
    while i < len(lines):
        m = ENTRY.match(lines[i])
        if m and any(m.group(1).startswith(p) for p in prefixes) and i + 2 < len(lines):
            ents.append((m.group(1), int(m.group(2)), m.group(3), m.group(4).split(","),
                         lines[i + 1].replace("declared", "", 1), lines[i + 2].replace("defined", "", 1)))
            i += 3
        else:
            i += 1
    return ents


def plan(entry):
    """(ret_cast or None, [param cast or None], manual reason or None)."""
    _f, _l, name, kinds, dtxt, ftxt = entry
    d = parse_sig(dtxt)
    f = parse_sig(ftxt)
    if not d or not f:
        return None, [], "unparsed"
    dret, dpar = d
    fret, fpar = f
    ret_cast = None
    if dret != fret:
        if fret == "void":
            if dret != "void":
                return None, [], "definition is void, caller declares " + dret
        elif dret == "void":
            ret_cast = None
        elif dret.startswith("@fnptr") or fret.startswith("@fnptr"):
            return None, [], "function pointer return"
        else:
            ret_cast = tytext(dret)
    if dpar is None:
        return ret_cast, [], "unproto"
    if len(dpar) != len(fpar):
        return None, [], "parameter count %d against %d" % (len(dpar), len(fpar))
    casts = []
    for dp, fp in zip(dpar, fpar):
        if dp == fp:
            casts.append(None)
        elif fp.startswith("@fnptr") or dp.startswith("@fnptr"):
            casts.append(None)
            casts[-1] = "FN"
        elif is_ptr(dp) and is_ptr(fp):
            casts.append(None if dp == "void*" else "void *")
        elif dp in INTS and fp in INTS:
            casts.append(tytext(dp))
        elif dp in INTS and is_ptr(fp):
            casts.append("void *")
        elif is_ptr(dp) and fp in INTS:
            casts.append(fp)
        else:
            casts.append("?")
    return ret_cast, casts, None


def split_top(text, op, cl):
    return pc.split_args(text, op, cl)


def is_decl_context(code, start):
    """True when the identifier at `start` follows a type (a declaration, not a call)."""
    j = start - 1
    while j >= 0 and code[j] in " \t\n":
        j -= 1
    if j < 0:
        return True
    c = code[j]
    if c in ".>":
        # member access or pointer: -> and . are calls through objects, never ours
        return True
    if c == "*":
        k = j - 1
        while k >= 0 and code[k] in " \t\n":
            k -= 1
        # ident * name(  is a declaration when the thing before * is an identifier; but a deref
        # of a call follows an operator
        return k >= 0 and (code[k].isalnum() or code[k] == "_") and not re.search(r"\b(return|case|else)\s*$", code[:k + 1])
    if c.isalnum() or c == "_":
        m = re.search(r"([A-Za-z_]\w*)\s*$", code[:j + 1])
        return not (m and m.group(1) in KEYW)
    return False


def apply_file(path, items, report):
    raw = open(path, encoding="latin1", newline="").read()
    crlf = "\r\n" in raw
    text, changed = cast_text(raw.replace("\r\n", "\n"), items, report)
    if changed:
        open(path, "w", encoding="latin1", newline="").write(text.replace("\n", "\r\n") if crlf else text)
    return raw, changed


def cast_text(text, items, report):
    changed = 0
    for entry in items:
        name = entry[2]
        ret_cast, pcasts, why = plan(entry)
        if why and why != "unproto":
            report.append((entry[0], name, "manual: " + why))
            continue
        if why == "unproto":
            pcasts = []
        if ret_cast is None and not any(c and c not in ("FN", "?") for c in pcasts):
            if any(c in ("FN", "?") for c in pcasts):
                report.append((entry[0], name, "manual: parameter %s" % ("function pointer" if "FN" in pcasts else "mixed")))
            continue
        edits = []
        code = pc.strip_pp(__import__("placeholdernames").strip_comments(text))
        # string and char literals must not hide parens: they are kept as is, calls inside are rare
        for m in re.finditer(r"\b%s\s*\(" % re.escape(name), code):
            if is_decl_context(code, m.start()):
                continue
            op = m.end() - 1
            depth, i = 0, op
            while i < len(code):
                if code[i] == "(":
                    depth += 1
                elif code[i] == ")":
                    depth -= 1
                    if depth == 0:
                        break
                i += 1
            if depth:
                continue
            cl = i
            args = split_top(code, op, cl)
            for k, c in enumerate(pcasts):
                if c in (None, "FN", "?") or k >= len(args):
                    continue
                s, e = args[k]
                a = text[s:e]
                lead = len(a) - len(a.lstrip())
                body = a.strip()
                if re.match(r"^\(\s*%s\s*\)" % re.escape(c.replace("*", r"\*")).replace(r"\\\*", r"\*"), body):
                    continue
                edits.append((s + lead, e, "(%s)%s" % (c, body if re.match(r"^[\w.\[\]>-]+$|^\(.*\)$", body) else "(" + body + ")") + a[len(a.rstrip()):]))
            if ret_cast:
                after = code[cl + 1:cl + 4].lstrip()
                before = code[max(0, m.start() - 40):m.start()]
                if re.search(r"\(\s*%s\s*\)\s*$" % re.escape(ret_cast).replace(r"\ ", r"\s*").replace(r"\*", r"\*"), before):
                    continue
                if after[:1] in ("[", ".", "(") or after[:2] == "->":
                    edits.append((m.start(), m.start(), "((%s)" % ret_cast))
                    edits.append((cl + 1, cl + 1, ")"))
                else:
                    edits.append((m.start(), m.start(), "(%s)" % ret_cast))
        if not edits:
            continue
        edits.sort(key=lambda x: (x[0], x[1]))
        out = []
        pos = 0
        for s, e, t in edits:
            if s < pos:
                continue
            out.append(text[pos:s])
            out.append(t)
            pos = e
        out.append(text[pos:])
        new = "".join(out)
        if new != text:
            text = new
            changed += 1
    return text, changed


def gv(rel):
    r = subprocess.run([sys.executable, os.path.join(HERE, "gameverify.py"), "--file", rel],
                       capture_output=True, text=True, cwd=ROOT)
    out = r.stdout + r.stderr
    m = re.search(r"not exact: (\d+), MATCH \(relocations wildcarded\): (\d+), data-only[^:]*: (\d+)", out)
    return out, (m and int(m.group(1)))


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--files", required=True)
    ap.add_argument("--pc", help="saved protocheck output (default: run it)")
    ap.add_argument("--log")
    ap.add_argument("--dry", action="store_true")
    ap.add_argument("--fix", action="store_true", help="run protocheck --fix with these casts added first")
    ap.add_argument("--jobs", type=int, default=6)
    a = ap.parse_args()
    files = [l.strip() for l in open(a.files) if l.strip()]
    if a.pc:
        pc_text = open(a.pc, encoding="latin1").read()
    else:
        pc_text = subprocess.run([sys.executable, os.path.join(HERE, "protocheck.py")], capture_output=True, text=True, cwd=ROOT).stdout
    ents = read_entries(pc_text, files)
    byfile = {}
    for e in ents:
        if e[0] in files:
            byfile.setdefault(e[0], {}).setdefault(e[2], e)
    if a.fix:
        plans = {}
        for e in ents:
            plans.setdefault(e[0], {}).setdefault(e[2], e)
        rep = []

        def hook(rel, text, names):
            d = plans.get(rel, {})
            return cast_text(text, [d[n] for n in names if n in d], rep)[0]
        pc.PRECAST[0] = hook
        sys.argv = ["protocheck", "--fix", "--files", a.files, "--jobs", str(a.jobs)] + (["--log", a.log] if a.log else [])
        pc.main()
        return
    lg = open(a.log, "a") if a.log else None
    kept = rejected = 0
    for rel, d in sorted(byfile.items()):
        path = os.path.join(ROOT, rel)
        report = []
        raw, changed = apply_file(path, list(d.values()), report)
        for r in report:
            if lg:
                lg.write("  %s %s %s\n" % r)
        if not changed:
            print("%s: nothing to cast (%d listed)" % (rel, len(d)))
            continue
        if a.dry:
            open(path, "w", encoding="latin1", newline="").write(raw)
            print("%s: would change" % rel)
            continue
        out, bad = gv(rel)
        if bad == 0:
            kept += 1
            print("%s: kept" % rel)
        else:
            open(path, "w", encoding="latin1", newline="").write(raw)
            rejected += 1
            print("%s: rejected, restored  %s" % (rel, out.strip().split("\n")[0][:200]))
            if lg:
                lg.write("  REJECT %s %s\n" % (rel, out.strip().split("\n")[0][:300]))
    print("files kept: %d, restored: %d" % (kept, rejected))


if __name__ == "__main__":
    main()
