#!/usr/bin/env python3
"""globrename.py: give generic data symbols a module-prefixed name.

eidos maps every data symbol with an object-like macro.  A global named `site`,
`table` or `config` therefore rewrites the same word wherever a unit uses it as a
parameter, field or local.  This tool renames such symbols to the house form
(`s` + file module + object, as in `sPselSite`).

Input: tools/globrename.tsv, one row per rename: file (under src/game), old name,
new name.  For each row the tool edits that one file:
  - the `symbols:` row and every symbol use of the old name become the new name;
  - struct and union members, `.old` and `->old` accesses, parameters and locals
    that shadow the symbol keep the old name;
  - comments change only for names that are not plain English words.
A row whose new name already occurs as a word anywhere in src/game is refused.

    python tools/globrename.py            dry run: print each file's edit count and the shadowed spots
    python tools/globrename.py --apply    write the files
    python tools/globrename.py --diff F   print the changed lines of one file
"""
import argparse
import collections
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
GAME = os.path.join(ROOT, "src", "game")
TSV = os.path.join(HERE, "globrename.tsv")

# Plain words: a comment that says "the table" is prose, not the symbol.
PLAIN = set("""banks callbacks config config2 coords dims dst file files ids init motion mtx positions records
rects resources setup site sounds table vram zero object pool padding cfg limits Count Choose Focus Pos File
Error Flag Buffer Address count""".split())

ROW_RE = re.compile(r"^\s*\*\s+(\w+)\s+0x[0-9A-Fa-f]+")
STR_RE = re.compile(r'"(?:[^"\\]|\\.)*"|' + r"'(?:[^'\\]|\\.)*'")
DECL_PREFIX = r"(?:(?:const|unsigned|signed|struct|union|enum|static|volatile|register)\s+)*"


def strip_comments(lines):
    """Return (code, comment_only) per line: code has comments blanked to spaces."""
    out = []
    incom = False
    for l in lines:
        s = []
        i = 0
        n = len(l)
        while i < n:
            if incom:
                j = l.find("*/", i)
                if j < 0:
                    s.append(" " * (n - i))
                    i = n
                else:
                    s.append(" " * (j + 2 - i))
                    i = j + 2
                    incom = False
            else:
                if l.startswith("/*", i):
                    incom = True
                    s.append("  ")
                    i += 2
                elif l.startswith("//", i):
                    s.append(" " * (n - i))
                    i = n
                elif l[i] == '"':
                    j = i + 1
                    while j < n and l[j] != '"':
                        j += 2 if l[j] == "\\" else 1
                    s.append(l[i:j + 1])
                    i = j + 1
                else:
                    s.append(l[i])
                    i += 1
        out.append("".join(s))
    return out


def rename_text(text, old, new):
    """Return (new_text, edits, shadows) for one rename in one text."""
    nl = "\r\n" if "\r\n" in text else "\n"
    lines = text.split(nl)
    code = strip_comments(lines)
    code = [STR_RE.sub(lambda m: m.group(0)[0] + " " * (len(m.group(0)) - 2) + m.group(0)[-1], c) for c in code]
    word = re.compile(r"(?<![\w])" + re.escape(old) + r"(?![\w])")
    stack = []          # block kinds: 'struct', 'block', 'init'
    shadow_until = []   # stack depths at which a shadow opened
    edits = []          # (line index, start, end)
    shadows = []
    paren = 0
    stmt = ""           # text of the current statement since its last boundary
    stmt_has_param = False
    tok_re = re.compile(r"[{}();]|(?<![\w])" + re.escape(old) + r"(?![\w])")
    for li, c in enumerate(code):
        if c.lstrip().startswith("#") and paren == 0:
            stmt = ""
            continue
        seg = 0
        for m in tok_re.finditer(c):
            col, tok = m.start(), m.group(0)
            stmt += c[seg:col]
            seg = m.end()
            if tok == "{":
                if re.search(r"\b(struct|union|enum)\b[^;(){}=]*$", stmt) and "=" not in stmt:
                    kind = "struct"
                elif "=" in stmt and paren == 0:
                    kind = "init"
                else:
                    kind = "block"
                if kind == "block" and stmt_has_param and not stack:
                    shadow_until.append(0)         # parameters shadow the whole body
                stack.append(kind)
                stmt = ""
                stmt_has_param = False
            elif tok == "}":
                if stack:
                    stack.pop()
                while shadow_until and shadow_until[-1] >= len(stack):
                    shadow_until.pop()
                stmt = ""
                stmt_has_param = False
            elif tok == "(":
                paren += 1
                stmt += "("
            elif tok == ")":
                paren = max(0, paren - 1)
                stmt += ")"
            elif tok == ";":
                if paren == 0:
                    stmt = ""
                    stmt_has_param = False
                else:
                    stmt += ";"
            else:
                before = c[:col].rstrip()
                stmt += old
                if before.endswith(".") or before.endswith("->"):
                    continue
                if "struct" in stack:
                    continue
                depth = len(stack)
                if depth == 0 and paren > 0:
                    stmt_has_param = True
                    shadows.append((li + 1, "param"))
                    continue
                if depth > 0 and paren == 0 \
                        and re.match(r"\s*" + DECL_PREFIX + r"\w+(\s+\w+)?\s*[\*\s]*$", c[:col]) \
                        and re.match(r"\s*(\[[^\]]*\]\s*)*(=|;|,)", c[col + len(old):]) \
                        and not re.match(r"\s*(return|else|goto|case)\b", c[:col]):
                    if re.match(r"\s*static\b", c[:col]):
                        edits.append((li, col, col + len(old)))     # a function static is the symbol
                        continue
                    shadow_until.append(depth - 1)
                    shadows.append((li + 1, "local"))
                    continue
                if shadow_until:
                    continue
                edits.append((li, col, col + len(old)))
        stmt += c[seg:] + " "
    # comments and symbol rows
    by_line = collections.defaultdict(list)
    for li, a, b in edits:
        by_line[li].append((a, b))
    for li, l in enumerate(lines):
        if li in by_line:
            continue
        cm = ROW_RE.match(l)
        if cm and cm.group(1) == old:
            a = l.index(old)
            by_line[li].append((a, a + len(old)))
            continue
        if old in PLAIN:
            continue
        # comment text: occurrences outside the code part
        if code[li] == l:
            continue
        for m in word.finditer(l):
            if code[li][m.start():m.end()].strip() == "":
                if l[:m.start()].rstrip().endswith((".", "->")):
                    continue
                by_line[li].append((m.start(), m.end()))
    count = 0
    for li, spans in by_line.items():
        l = lines[li]
        for a, b in sorted(set(spans), reverse=True):
            l = l[:a] + new + l[b:]
            count += 1
        lines[li] = l
    return nl.join(lines), count, shadows


def drop_duplicate(text, old, new):
    """The file already declares `new` (a shared symbol): drop the row and the extern of `old`."""
    if not re.search(r"^\s*\*\s+" + re.escape(new) + r"\s+0x", text, re.M):
        return text
    text = re.sub(r"^\s*\*\s+" + re.escape(old) + r"\s+0x[^\n]*\n", "", text, count=1, flags=re.M)
    text = re.sub(r"^extern [^;\n]*\b" + re.escape(old) + r"\b\s*(\[[^\]]*\])*\s*;[^\n]*\n", "", text, flags=re.M)
    return text


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--diff")
    ap.add_argument("--only")
    a = ap.parse_args()
    rows = []
    for l in open(TSV, encoding="utf8"):
        l = l.rstrip("\n")
        if l and not l.startswith("#"):
            rows.append(l.split("\t"))
    words = collections.Counter()
    for d, _, fs in os.walk(GAME):
        for f in fs:
            if f.endswith((".c", ".h")):
                for w in set(re.findall(r"\w+", open(os.path.join(d, f), encoding="utf8", errors="replace").read())):
                    words[w] += 1
    bad = 0
    byfile = collections.defaultdict(list)
    for f, old, new, *flag in rows:
        if a.only and f != a.only:
            continue
        if words.get(new) and not flag:
            print("REFUSED %s %s -> %s: new name already used" % (f, old, new))
            bad += 1
            continue
        byfile[f].append((old, new, bool(flag)))
    for f, rs in sorted(byfile.items()):
        path = os.path.join(GAME, f)
        data = open(path, encoding="utf8", errors="surrogateescape", newline="").read()
        orig = data
        total = 0
        allsh = []
        for old, new, shared in rs:
            if shared:
                data = drop_duplicate(data, old, new)
            data, n, sh = rename_text(data, old, new)
            total += n
            allsh += [(old, ln, k) for ln, k in sh]
        print("%-52s %3d edits %s" % (f, total, ("shadow " + ",".join("%s@%d:%s" % x for x in allsh)) if allsh else ""))
        if a.diff == f:
            ol, nl_ = orig.split("\n"), data.split("\n")
            for i, (x, y) in enumerate(zip(ol, nl_)):
                if x != y:
                    print("%5d - %s\n      + %s" % (i + 1, x.strip()[:150], y.strip()[:150]))
        if a.apply and data != orig:
            open(path, "w", encoding="utf8", errors="surrogateescape", newline="").write(data)
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
