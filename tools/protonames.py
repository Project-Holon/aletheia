#!/usr/bin/env python3
"""Give prototypes the parameter names of their function's definition.

A file often declares a function it calls with placeholder parameter names
(`extern void FOO_Bar(int a0, u32 a1);`) while the definition names them
(`void FOO_Bar(int heapId, u32 size)`).  This copies the definition's names into
every prototype of that function, but only for parameters whose prototype name is
a placeholder (aN, argN, paramN, pN) and only when the parameter counts agree.
Parameter names in a prototype do not reach the object code, so the change is
byte-neutral; it is still verified like any other edit.

A name resolves in the prototype's own region first, then in arm9 (every overlay
calls arm9), then anywhere in the tree if it is defined exactly once.  A name defined twice in that scope (file statics) is skipped.

    python tools/protonames.py                 dry run: counts per region
    python tools/protonames.py --list          dry run: every change
    python tools/protonames.py --apply [--changed OUT]   write; OUT lists changed files
"""
import argparse
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GAME = os.path.join(ROOT, "src", "game")
sys.path.insert(0, os.path.join(ROOT, "tools"))
import placeholdernames as ph  # noqa: E402

PLACEHOLDER = re.compile(r"^(?:a|arg|param|p)[0-9]$")
IDENT = re.compile(r"[A-Za-z_]\w*")
KEYWORDS = {"void", "const", "volatile", "struct", "union", "enum", "unsigned", "signed",
            "int", "char", "short", "long", "float", "double", "register"}


def split_params(text):
    out, depth, cur = [], 0, ""
    for ch in text:
        if ch in "([":
            depth += 1
        elif ch in ")]":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur)
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur)
    return out


def param_name(p):
    """(name, start, end) of the declared name in one parameter text, or None."""
    if "(" in p or p.strip() in ("void", "...", ""):
        return None
    q = re.sub(r"\[[^\]]*\]\s*$", "", p.rstrip())
    m = list(IDENT.finditer(q))
    if len(m) < 2:
        return None          # a type alone, no name
    last = m[-1]
    if last.group(0) in KEYWORDS:
        return None
    return last.group(0), last.start(), last.end()


def region_of(path):
    return os.path.relpath(path, GAME).replace(os.sep, "/").split("/")[0]


def decls(path):
    """(name, params text, params start, params end, is_definition) for each top-level declaration."""
    raw = open(path, encoding="latin1", newline="").read()
    code = ph.strip_comments(raw)
    depth_at = []
    depth = 0
    for line in code.split(ph.NL):
        depth_at.append(depth)
        depth = max(0, depth + line.count("{") - line.count("}"))
    starts = [0]
    for i, ch in enumerate(code):
        if ch == ph.NL:
            starts.append(i + 1)
    import bisect
    out = []
    for s in re.finditer(r"\b([A-Za-z_]\w*)\s*\(((?:[^;{}()]|\([^;{}()]*\))*)\)\s*(?=[{;])", code, re.S):
        no = bisect.bisect_right(starts, s.start())
        if depth_at[no - 1] != 0:
            continue
        name = s.group(1)
        if name in ("if", "while", "for", "switch", "return", "sizeof"):
            continue
        after = code[s.end():].lstrip()[:1]
        out.append((name, s.group(2), s.start(2), s.end(2), after == "{"))
    return raw, out


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--changed")
    a = ap.parse_args()
    files = list(ph.files_under([GAME]))
    defs = {}
    parsed = {}
    for f in files:
        raw, ds = decls(f)
        parsed[f] = (raw, ds)
        for name, params, _s, _e, is_def in ds:
            if is_def:
                key = (region_of(f), name)
                names = [param_name(p) for p in split_params(params)]
                defs.setdefault(key, []).append([n[0] if n else None for n in names])
    # a name defined once in the whole tree also resolves from any region (an overlay
    # calling another overlay's function, ITCM, the SDK regions)
    anywhere = {}
    for (_r, n), lst in defs.items():
        anywhere.setdefault(n, []).extend(lst)
    changed_files = []
    per_region = {}
    for f in files:
        raw, ds = parsed[f]
        reg = region_of(f)
        edits = []
        for name, params, s, e, is_def in ds:
            if is_def:
                continue
            cands = defs.get((reg, name)) or defs.get(("arm9", name)) or anywhere.get(name)
            if not cands or len(cands) != 1:
                continue
            dnames = cands[0]
            plist = split_params(params)
            if len(plist) != len(dnames):
                continue
            pos = s
            new_parts = []
            taken = {pn[0] for pn in (param_name(p) for p in plist) if pn}
            changed = False
            for p, dn in zip(plist, dnames):
                pn = param_name(p)
                if pn and PLACEHOLDER.match(pn[0]) and dn and not PLACEHOLDER.match(dn) and dn not in taken:
                    p = p[:pn[1]] + dn + p[pn[2]:]
                    taken.add(dn)
                    changed = True
                new_parts.append(p)
            if changed:
                new = ",".join(new_parts)
                # the comment-stripped text has the same offsets as the raw text
                if raw[s:e].count("/*") == 0 and raw[s:e].count("//") == 0:
                    edits.append((s, e, new, name))
        if not edits:
            continue
        per_region[reg] = per_region.get(reg, 0) + len(edits)
        if a.list:
            for s, e, new, name in edits:
                print("%s\t%s\t(%s) -> (%s)" % (os.path.relpath(f, ROOT).replace(os.sep, "/"), name,
                                                " ".join(raw[s:e].split()), " ".join(new.split())))
        if a.apply:
            out = raw
            for s, e, new, _n in sorted(edits, reverse=True):
                out = out[:s] + new + out[e:]
            open(f, "w", encoding="latin1", newline="").write(out)
            changed_files.append(os.path.relpath(f, ROOT).replace(os.sep, "/"))
    total = sum(per_region.values())
    for r in sorted(per_region, key=lambda r: -per_region[r]):
        print("%-22s %5d prototypes" % (r, per_region[r]))
    print("prototypes %s: %d in %d regions" % ("renamed" if a.apply else "to rename", total, len(per_region)))
    if a.changed and a.apply:
        open(a.changed, "w").write("\n".join(changed_files) + "\n")


if __name__ == "__main__":
    main()
