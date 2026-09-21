#!/usr/bin/env python3
"""Source permuter for near misses.

Takes a C file that already compiles to nearly the right bytes and searches
source-level rewrites that this compiler is known to be sensitive to
(declaration order, initialiser placement, operand order, named temporaries,
volatile/const, case order) looking for the spelling that closes the gap.

Every candidate is scored with match.py's own machinery -- `run_one()`,
`resolve_relocations()` and `compare()` -- so a mismatch count printed here
is byte for byte the count `match.py one --diff` reports for the same file.

Usage
-----
    python3 tools/permute.py --src src/pending/func_020454E0.c \\
        --func func_020454E0 --addr 0x020454E0 --arm \\
        --mode hill --budget 200 --seed 1 --out /tmp/best.c

    --src FILE           the C translation unit to permute
    --func NAME          the function symbol to extract and compare
    --addr 0xADDR        the address to compare it against
    --thumb | --arm      instruction set (never inferred here; pass one)
    --cc VERSION         compiler under tools/mwccarm/mwccarm/dsi (1.1p1)
    --flags "..."        compiler flags (default -O4,p)
    --budget N           number of candidate compiles (default 60)
    --seed S             RNG seed, for a reproducible search
    --out FILE           write the best source found here
    --mode random|hill   random samples 1- and 2-mutation variants of the
                         baseline; hill keeps the best source so far, applies
                         single mutations to it, accepts any improvement, and
                         restarts from the baseline when it stalls
    --jobs N             parallel compiles (default 4)
    --list               print the mutations available on this source and exit

Ranking is (size correct, mismatch count).  A variant with 0 concrete
mismatches and no wildcarded relocation site is reported EXACT; one whose
only remaining difference is at wildcarded relocation fields is MATCH, and
the unresolved sites are named.

Nothing is written outside --out and the process's own temp directories.
"""

import argparse
import hashlib
import os
import random
import re
import sys
import threading

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import match  # noqa: E402  (match.py is the scoring machinery, by design)


# ---------------------------------------------------------------------------
# source model: header / prelude / the one function body we rewrite
# ---------------------------------------------------------------------------

class Source:
    """A C file split into (prelude, body-lines, tail).

    `body` is the statement region of the target function: everything between
    the line holding the opening brace of its definition and the matching
    closing brace.  Mutations only ever touch `body` plus, for parameter
    rewrites, the signature line itself.
    """

    def __init__(self, text, func):
        self.text = text
        self.func = func
        lines = text.split("\n")
        self.lines = lines
        self.sig_i, self.open_i, self.close_i = self._locate(lines, func)

    @staticmethod
    def _locate(lines, func):
        pat = re.compile(r"(^|[^\w])" + re.escape(func) + r"\s*\(")
        start = None
        for i, ln in enumerate(lines):
            if ln.lstrip().startswith(("extern", "//", "*", "/*")):
                continue
            if pat.search(ln) and ";" not in ln.split("//")[0]:
                start = i
                break
        if start is None:
            raise SystemExit("permute: no definition of %s in the source" % func)
        # the opening brace may be on the signature line or a later one
        depth = 0
        open_i = None
        for i in range(start, len(lines)):
            for ch in lines[i]:
                if ch == "{":
                    if open_i is None:
                        open_i = i
                    depth += 1
                elif ch == "}":
                    depth -= 1
                    if depth == 0 and open_i is not None:
                        return start, open_i, i
        raise SystemExit("permute: unbalanced braces in %s" % func)

    def body(self):
        return self.lines[self.open_i + 1:self.close_i]

    def with_body(self, body):
        out = list(self.lines[:self.open_i + 1]) + list(body) + \
            list(self.lines[self.close_i:])
        return Source("\n".join(out), self.func)

    def with_lines(self, lines):
        return Source("\n".join(lines), self.func)

    def render(self):
        return "\n".join(self.lines)


# ---------------------------------------------------------------------------
# a mutation is (name, line-number, apply(Source) -> Source|None)
# ---------------------------------------------------------------------------

class Mutation:
    __slots__ = ("name", "line", "fn")

    def __init__(self, name, line, fn):
        self.name = name
        self.line = line
        self.fn = fn

    def __repr__(self):
        return "%s@L%d" % (self.name, self.line)

    def apply(self, src):
        try:
            return self.fn(src)
        except Exception:
            return None


# --- small C-aware helpers -------------------------------------------------

TYPE_WORDS = ("void", "char", "short", "int", "long", "signed", "unsigned",
              "float", "double", "const", "volatile", "struct", "union",
              "enum", "static", "register")
_TYPEDEFISH = re.compile(r"^(u8|u16|u32|u64|s8|s16|s32|s64|f32|f64|"
                         r"BOOL|bool|size_t|[A-Z]\w*)$")

DECL_RE = re.compile(
    r"^(?P<ind>\s*)(?P<type>(?:(?:const|volatile|static|register|struct|union|enum|unsigned|signed)\s+)*"
    r"[A-Za-z_]\w*(?:\s+\w+)*?)\s+(?P<rest>[A-Za-z_*][^;]*);\s*$")

KEYWORD_STARTS = ("if", "for", "while", "switch", "return", "do", "else",
                  "break", "continue", "goto", "case", "default", "sizeof")


def is_decl(line):
    """True if `line` looks like a plain local declaration."""
    s = line.strip()
    if not s.endswith(";") or s.startswith(("//", "/*", "*")):
        return False
    m = DECL_RE.match(line.rstrip())
    if not m:
        return False
    head = m.group("type").split()[0]
    if head in KEYWORD_STARTS:
        return False
    if head in TYPE_WORDS or _TYPEDEFISH.match(head):
        # `x = f(y);` also matches DECL_RE when x is a typedef-ish name; a
        # real declaration has no top-level '=' before the first declarator
        # name... which is not decidable textually, so use the cheap test:
        # a declaration's `rest` starts with an identifier or '*'.
        rest = m.group("rest").strip()
        if "=" in m.group("type"):
            return False
        return bool(re.match(r"^[*A-Za-z_]", rest))
    return False


def decl_names(line):
    m = DECL_RE.match(line.rstrip())
    if not m:
        return []
    out = []
    for part in split_top(m.group("rest"), ","):
        part = part.strip().lstrip("*").strip()
        nm = re.match(r"([A-Za-z_]\w*)", part)
        if nm:
            out.append(nm.group(1))
    return out


def split_top(text, sep):
    """Split on `sep` at paren/bracket depth 0."""
    out, depth, cur = [], 0, ""
    i = 0
    while i < len(text):
        ch = text[i]
        if ch in "([{":
            depth += 1
        elif ch in ")]}":
            depth -= 1
        if depth == 0 and text.startswith(sep, i) and len(sep) == 1:
            out.append(cur)
            cur = ""
            i += 1
            continue
        cur += ch
        i += 1
    out.append(cur)
    return out


def indent_of(line):
    return line[:len(line) - len(line.lstrip())]


def idents(text):
    return set(re.findall(r"[A-Za-z_]\w*", text))


def assigned_in(stmt):
    """Identifiers this statement plausibly writes."""
    out = set()
    s = stmt.strip().rstrip(";")
    for m in re.finditer(r"([A-Za-z_]\w*)\s*(?:\[[^\]]*\])?\s*"
                         r"(?:\.\w+|->\w+)*\s*(?:[-+*/%&|^]|<<|>>)?=(?!=)", s):
        out.add(m.group(1))
    for m in re.finditer(r"(\+\+|--)\s*([A-Za-z_]\w*)", s):
        out.add(m.group(2))
    for m in re.finditer(r"([A-Za-z_]\w*)\s*(\+\+|--)", s):
        out.add(m.group(1))
    # any call may write through a pointer argument: treat calls as opaque
    if re.search(r"[A-Za-z_]\w*\s*\(", s):
        out.add("\0call")
    return out


def is_simple_stmt(line):
    """A one-line statement that is not a declaration, label or block."""
    s = line.strip()
    if not s.endswith(";") or s.startswith(("//", "/*", "*", "#")):
        return False
    if "{" in s or "}" in s:
        return False
    word = re.match(r"([A-Za-z_]\w*)", s)
    if word and word.group(1) in KEYWORD_STARTS:
        return False
    return not is_decl(line)


def decl_blocks(body):
    """Runs of >= 2 consecutive declaration lines: [(start, end_exclusive)]."""
    out = []
    i = 0
    while i < len(body):
        if is_decl(body[i]):
            j = i
            while j < len(body) and is_decl(body[j]):
                j += 1
            if j - i >= 2:
                out.append((i, j))
            i = j
        else:
            i += 1
    return out


# --- mutation generators ---------------------------------------------------

def gen_decl_permute(src):
    """Permute the order of declarations inside one declaration block."""
    body = src.body()
    out = []
    for (a, b) in decl_blocks(body):
        for i in range(a, b - 1):
            def mk(i=i):
                def fn(s):
                    bd = list(s.body())
                    bd[i], bd[i + 1] = bd[i + 1], bd[i]
                    return s.with_body(bd)
                return fn
            out.append(Mutation("decl-swap", src.open_i + 2 + i, mk()))
        if b - a >= 3:
            def mkrev(a=a, b=b):
                def fn(s):
                    bd = list(s.body())
                    bd[a:b] = list(reversed(bd[a:b]))
                    return s.with_body(bd)
                return fn
            out.append(Mutation("decl-reverse", src.open_i + 2 + a, mkrev()))
    return out


def gen_decl_split(src):
    """`int a, b;` -> `int a; int b;`."""
    body = src.body()
    out = []
    for i, ln in enumerate(body):
        if not is_decl(ln):
            continue
        m = DECL_RE.match(ln.rstrip())
        parts = split_top(m.group("rest"), ",")
        if len(parts) < 2:
            continue

        def mk(i=i):
            def fn(s):
                bd = list(s.body())
                mm = DECL_RE.match(bd[i].rstrip())
                ind, ty = mm.group("ind"), mm.group("type")
                new = ["%s%s %s;" % (ind, ty, p.strip())
                       for p in split_top(mm.group("rest"), ",")]
                bd[i:i + 1] = new
                return s.with_body(bd)
            return fn
        out.append(Mutation("decl-split", src.open_i + 2 + i, mk()))
    return out


def gen_decl_join(src):
    """Two adjacent declarations of the same type -> one comma declaration."""
    body = src.body()
    out = []
    for i in range(len(body) - 1):
        if not (is_decl(body[i]) and is_decl(body[i + 1])):
            continue
        a = DECL_RE.match(body[i].rstrip())
        b = DECL_RE.match(body[i + 1].rstrip())
        if a.group("type").strip() != b.group("type").strip():
            continue
        if "=" in a.group("rest") or "=" in b.group("rest"):
            continue

        def mk(i=i):
            def fn(s):
                bd = list(s.body())
                aa = DECL_RE.match(bd[i].rstrip())
                bb = DECL_RE.match(bd[i + 1].rstrip())
                bd[i:i + 2] = ["%s%s %s, %s;" % (aa.group("ind"),
                                                 aa.group("type"),
                                                 aa.group("rest").strip(),
                                                 bb.group("rest").strip())]
                return s.with_body(bd)
            return fn
        out.append(Mutation("decl-join", src.open_i + 2 + i, mk()))
    return out


def gen_stmt_swap(src):
    """Swap two adjacent statements when neither reads what the other writes."""
    body = src.body()
    out = []
    for i in range(len(body) - 1):
        u, v = body[i], body[i + 1]
        if not (is_simple_stmt(u) and is_simple_stmt(v)):
            continue
        if indent_of(u) != indent_of(v):
            continue
        wu, wv = assigned_in(u), assigned_in(v)
        if "\0call" in wu and "\0call" in wv:
            continue  # two calls: order is observable, never reorder
        ru, rv = idents(u), idents(v)
        if (wu - {"\0call"}) & rv or (wv - {"\0call"}) & ru:
            continue
        if (wu - {"\0call"}) & (wv - {"\0call"}):
            continue
        if "\0call" in wu and ((wv - {"\0call"}) or rv & wu):
            continue
        if "\0call" in wv and (wu - {"\0call"}):
            continue

        def mk(i=i):
            def fn(s):
                bd = list(s.body())
                bd[i], bd[i + 1] = bd[i + 1], bd[i]
                return s.with_body(bd)
            return fn
        out.append(Mutation("stmt-swap", src.open_i + 2 + i, mk()))
    return out


def gen_init_split(src):
    """`int a = e;` -> `int a; ... a = e;` placed after the declaration block."""
    body = src.body()
    out = []
    blocks = decl_blocks(body)
    for i, ln in enumerate(body):
        if not is_decl(ln):
            continue
        m = DECL_RE.match(ln.rstrip())
        parts = split_top(m.group("rest"), ",")
        if len(parts) != 1 or "=" not in parts[0]:
            continue
        end = i + 1
        for (a, b) in blocks:
            if a <= i < b:
                end = b
                break

        def mk(i=i, end=end):
            def fn(s):
                bd = list(s.body())
                mm = DECL_RE.match(bd[i].rstrip())
                name, expr = split_top(mm.group("rest"), "=")[0], \
                    "=".join(split_top(mm.group("rest"), "=")[1:])
                name = name.strip()
                bare = name.lstrip("*").strip()
                bd[i] = "%s%s %s;" % (mm.group("ind"), mm.group("type"), name)
                bd.insert(end, "%s%s =%s;" % (mm.group("ind"), bare, expr))
                return s.with_body(bd)
            return fn
        out.append(Mutation("init-split", src.open_i + 2 + i, mk()))
    return out


def gen_init_fold(src):
    """`int a;` + a later `a = e;` -> `int a = e;` (only when adjacent-safe)."""
    body = src.body()
    out = []
    blocks = decl_blocks(body)
    ends = {b for (_a, b) in blocks}
    for i, ln in enumerate(body):
        if not is_decl(ln) or "=" in ln:
            continue
        names = decl_names(ln)
        if len(names) != 1:
            continue
        nm = names[0]
        blk_end = i + 1
        for (a, b) in blocks:
            if a <= i < b:
                blk_end = b
        # the first statement after the declaration block must assign it
        j = blk_end
        while j < len(body) and not body[j].strip():
            j += 1
        if j >= len(body) or not is_simple_stmt(body[j]):
            continue
        mm = re.match(r"^(\s*)" + re.escape(nm) + r"\s*=\s*(.+);\s*$",
                      body[j].rstrip())
        if not mm:
            continue

        def mk(i=i, j=j, nm=nm):
            def fn(s):
                bd = list(s.body())
                d = DECL_RE.match(bd[i].rstrip())
                a = re.match(r"^(\s*)" + re.escape(nm) + r"\s*=\s*(.+);\s*$",
                             bd[j].rstrip())
                bd[i] = "%s%s %s = %s;" % (d.group("ind"), d.group("type"),
                                           nm, a.group(2))
                del bd[j]
                return s.with_body(bd)
            return fn
        out.append(Mutation("init-fold", src.open_i + 2 + i, mk()))
    _ = ends
    return out


CALL_ARG_RE = re.compile(r"\b([A-Za-z_]\w*)\s*\(")


def gen_arg_temp(src):
    """`f(g(x))` -> `t = g(x); f(t)`, one named temporary per call argument."""
    body = src.body()
    out = []
    for i, ln in enumerate(body):
        s = ln.rstrip()
        if not is_simple_stmt(ln) and not s.strip().startswith("return"):
            continue
        if s.count("(") < 2:
            continue
        for m in CALL_ARG_RE.finditer(s):
            name = m.group(1)
            if name in KEYWORD_STARTS:
                continue
            op = s.index("(", m.start())
            depth, k = 0, op
            while k < len(s):
                if s[k] == "(":
                    depth += 1
                elif s[k] == ")":
                    depth -= 1
                    if depth == 0:
                        break
                k += 1
            if k >= len(s):
                continue
            args = split_top(s[op + 1:k], ",")
            for ai, arg in enumerate(args):
                a = arg.strip()
                # only lift an argument that is itself a call or a real expr
                if not re.search(r"[A-Za-z_]\w*\s*\(|[-+*/%&|^]|>>|<<", a):
                    continue
                if a.startswith("(") and a.endswith(")") and "(" not in a[1:-1]:
                    continue
                if len(a) < 4:
                    continue
                ty = _temp_type(a, src)
                if ty is None:
                    continue

                def mk(i=i, op=op, k=k, ai=ai, a=a, ty=ty):
                    def fn(s2):
                        bd = list(s2.body())
                        line = bd[i].rstrip()
                        args2 = split_top(line[op + 1:k], ",")
                        if ai >= len(args2) or args2[ai].strip() != a:
                            return None
                        tname = "pt_%d_%d" % (i, ai)
                        args2[ai] = " " + tname
                        bd[i] = line[:op + 1] + ",".join(args2) + line[k:]
                        ind = indent_of(line)
                        bd.insert(i, "%s%s %s = %s;" % (ind, ty, tname, a))
                        return s2.with_body(bd)
                    return fn
                out.append(Mutation("arg-temp[%s#%d]" % (name, ai),
                                    src.open_i + 2 + i, mk()))
    return out


def _temp_type(expr, src):
    """The type to give a lifted argument temporary, or None if unknown.

    A leading cast names the type outright; otherwise the expression must be
    a plain call to a function the file declares, and the prototype's return
    type is used.  Anything else is left alone rather than guessed at, since
    a wrong type would change the compiled bytes for reasons unrelated to
    the shape under test.
    """
    m = re.match(r"^\(\s*((?:const\s+|unsigned\s+|signed\s+|struct\s+)*"
                 r"[A-Za-z_]\w*\s*\**)\s*\)", expr)
    if m:
        return m.group(1).strip()
    c = re.match(r"^([A-Za-z_]\w*)\s*\(", expr)
    if c:
        for ln in src.lines:
            d = re.match(r"^\s*(?:extern\s+)?(.+?)\s+\**" +
                         re.escape(c.group(1)) + r"\s*\(", ln)
            if d and ";" in ln:
                t = d.group(1).strip()
                if "*" in ln.split(c.group(1))[0].split(t)[-1]:
                    t += " *"
                return t
        return None
    if re.match(r"^[A-Za-z_][\w.\->\[\]]*\s*[-+*/%&|^]|^[\w.\->\[\]]+$", expr):
        return None
    return None


PTR_DECL = re.compile(r"\*")


def gen_qualifier(src, word):
    """Add or remove `volatile`/`const` on a pointer-typed local or parameter."""
    out = []
    lines = src.lines
    cand = list(range(src.open_i + 1, src.close_i))
    cand += list(range(src.sig_i, src.open_i + 1))
    for i in cand:
        ln = lines[i]
        in_body = src.open_i < i < src.close_i
        if in_body and not is_decl(ln):
            continue
        if not in_body and "(" not in "".join(lines[src.sig_i:src.open_i + 1]):
            continue
        if word in ln:
            def mkdel(i=i, word=word):
                def fn(s):
                    ls = list(s.lines)
                    ls[i] = re.sub(r"\b" + word + r"\s+", "", ls[i], count=1)
                    return s.with_lines(ls)
                return fn
            out.append(Mutation("%s-drop" % word, i + 1, mkdel()))
            continue
        if not PTR_DECL.search(ln):
            continue
        if in_body:
            m = DECL_RE.match(ln.rstrip())
            if not m or "*" not in m.group("rest"):
                continue

            def mkadd(i=i, word=word):
                def fn(s):
                    ls = list(s.lines)
                    mm = DECL_RE.match(ls[i].rstrip())
                    ls[i] = "%s%s %s %s;" % (mm.group("ind"), word,
                                             mm.group("type"),
                                             mm.group("rest").strip())
                    return s.with_lines(ls)
                return fn
            out.append(Mutation("%s-add" % word, i + 1, mkadd()))
        else:
            # a parameter line: qualify each pointer parameter in turn.  The
            # qualifier goes in front of the whole type, and in front of the
            # `struct`/`union`/`enum` keyword when there is one.
            for pm in re.finditer(
                    r"((?:struct|union|enum)\s+)?([A-Za-z_]\w*)\s*\*\s*[A-Za-z_]\w*",
                    ln):
                st = pm.start(1) if pm.group(1) else pm.start(2)

                def mkp(i=i, word=word, st=st):
                    def fn(s):
                        ls = list(s.lines)
                        seg = ls[i]
                        ls[i] = seg[:st] + word + " " + seg[st:]
                        return s.with_lines(ls)
                    return fn
                out.append(Mutation("%s-param" % word, i + 1, mkp()))
    return out


def gen_case_reorder(src):
    """Move one `case` arm of a switch textually before the previous one."""
    body = src.body()
    out = []
    # collect top-level case labels with their arm extents inside each switch
    arms = []
    i = 0
    while i < len(body):
        if re.match(r"^\s*(case\b|default\b)", body[i]):
            j = i + 1
            depth = body[i].count("{") - body[i].count("}")
            while j < len(body):
                if depth <= 0 and re.match(r"^\s*(case\b|default\b)", body[j]):
                    break
                if depth <= 0 and re.match(r"^\s*\}", body[j]):
                    break
                depth += body[j].count("{") - body[j].count("}")
                j += 1
            arms.append((i, j))
            i = j
        else:
            i += 1
    for a in range(len(arms) - 1):
        (s1, e1), (s2, e2) = arms[a], arms[a + 1]
        if e1 != s2:
            continue

        def mk(s1=s1, e1=e1, e2=e2):
            def fn(s):
                bd = list(s.body())
                first, second = bd[s1:e1], bd[e1:e2]
                bd[s1:e2] = second + first
                return s.with_body(bd)
            return fn
        out.append(Mutation("case-swap", src.open_i + 2 + s1, mk()))
    return out


BINOPS = ["==", "!=", "+", "*", "&", "|"]


def gen_operand_swap(src):
    """Swap the operands of one `+ * & | == !=` occurrence."""
    body = src.body()
    out = []
    for i, ln in enumerate(body):
        s = ln.rstrip()
        for op in BINOPS:
            for m in _find_binops(s, op):
                def mk(i=i, op=op, pos=m):
                    def fn(s2):
                        bd = list(s2.body())
                        line = bd[i].rstrip()
                        r = _swap_at(line, pos, op)
                        if r is None:
                            return None
                        bd[i] = r
                        return s2.with_body(bd)
                    return fn
                out.append(Mutation("swap'%s'" % op, src.open_i + 2 + i, mk()))
    return out


def _find_binops(s, op):
    """Positions of `op` used as a binary operator at any depth."""
    out = []
    i = 0
    while True:
        i = s.find(op, i)
        if i < 0:
            break
        j = i + len(op)
        prev = s[i - 1] if i else ""
        nxt = s[j] if j < len(s) else ""
        i = j
        if op in ("+", "*", "&", "|"):
            if prev == op or nxt == op:        # ++  **  &&  ||
                continue
            if prev in "=<>!+-*/%&|^([,?:" or prev == "":
                continue                       # unary / part of a compound op
            if nxt == "=":
                continue                       # +=  *=  &=  |=
            if op == "*" and re.match(r"^\s*[A-Za-z_(]", s[j:]) and \
                    re.search(r"[(,]\s*$", s[:i]):
                continue                       # pointer declarator
        else:
            if prev in "!<>=" or nxt == "=":
                continue
        out.append(i - len(op))
    return out


# Operators of a DIFFERENT precedence next to a swap site would make the
# rewrite change the value, not just the operand order: `a * 2 + c` swapped
# around the `+` must become `c + a * 2`, and this scanner only ever sees the
# `2`.  Rather than parse expressions, refuse the swap whenever either
# operand abuts an arithmetic operator that is not the one being swapped.
_ADJACENT = "+-*/%<>&|^"


def _swap_at(line, pos, op):
    """Swap the two operands around the binary `op` starting at `pos`.

    Returns None when the rewrite would not be value-preserving: the operand
    extents are found textually, so a neighbouring operator of another
    precedence means the true operand is wider than what was found.
    """
    if line[pos:pos + len(op)] != op:
        return None
    left = _operand_left(line, pos)
    right = _operand_right(line, pos + len(op))
    if left is None or right is None:
        return None
    (ls, le), (rs, re_) = left, right
    before = line[:ls].rstrip()
    after = line[re_:].lstrip()
    if before and before[-1] in _ADJACENT:
        return None
    if after and after[0] in _ADJACENT:
        return None
    lt, rt = line[ls:le].strip(), line[rs:re_].strip()
    if not lt or not rt or lt == rt:
        return None
    return line[:ls] + rt + " " + op + " " + lt + line[re_:]


_BOUND = set("=,;?:")


def _operand_left(line, pos):
    i = pos - 1
    while i >= 0 and line[i] == " ":
        i -= 1
    end = i + 1
    depth = 0
    while i >= 0:
        ch = line[i]
        if ch in ")]":
            depth += 1
        elif ch in "([":
            if depth == 0:
                break
            depth -= 1
        elif line[i - 1:i + 1] == "->":
            i -= 2
            continue
        elif depth == 0 and (ch in _BOUND or ch in "+-*/%&|^<>!"):
            break
        i -= 1
    start = i + 1
    while start < end and line[start] == " ":
        start += 1
    if start >= end:
        return None
    return (start, end)


def _operand_right(line, pos):
    i = pos
    while i < len(line) and line[i] == " ":
        i += 1
    start = i
    depth = 0
    while i < len(line):
        ch = line[i]
        if ch in "([":
            depth += 1
        elif ch in ")]":
            if depth == 0:
                break
            depth -= 1
        elif line[i:i + 2] == "->":
            i += 2
            continue
        elif depth == 0 and (ch in _BOUND or ch in "+*/%&|^<>!" or
                             (ch == "-" and line[i - 1] != "(")):
            break
        i += 1
    end = i
    while end > start and line[end - 1] == " ":
        end -= 1
    if end <= start:
        return None
    return (start, end)


NEZERO = re.compile(r"([A-Za-z_]\w*(?:(?:->|\.)\w+|\[[^\]]*\])*)\s*!=\s*0\b")


def gen_bangbang(src):
    """Rewrite `x != 0` in a value context as `!!x` (and back)."""
    body = src.body()
    out = []
    for i, ln in enumerate(body):
        s = ln.rstrip()
        if re.match(r"^\s*(if|while|for)\b", s):
            continue   # a control context, not a value context
        for m in NEZERO.finditer(s):
            def mk(i=i, span=m.span(), expr=m.group(1)):
                def fn(s2):
                    bd = list(s2.body())
                    line = bd[i].rstrip()
                    if line[span[0]:span[1]] != s2 and \
                            not line[span[0]:span[1]].startswith(expr):
                        return None
                    bd[i] = line[:span[0]] + "!!" + expr + line[span[1]:]
                    return s2.with_body(bd)
                return fn
            out.append(Mutation("ne0->!!", src.open_i + 2 + i, mk()))
        for m in re.finditer(r"!!\s*([A-Za-z_]\w*(?:(?:->|\.)\w+)*)", s):
            def mkb(i=i, span=m.span(), expr=m.group(1)):
                def fn(s2):
                    bd = list(s2.body())
                    line = bd[i].rstrip()
                    bd[i] = line[:span[0]] + expr + " != 0" + line[span[1]:]
                    return s2.with_body(bd)
                return fn
            out.append(Mutation("!!->ne0", src.open_i + 2 + i, mkb()))
    return out


GENERATORS = [gen_decl_permute, gen_decl_split, gen_decl_join, gen_stmt_swap,
              gen_init_split, gen_init_fold, gen_arg_temp, gen_case_reorder,
              gen_operand_swap, gen_bangbang]


def mutations(src):
    out = []
    for g in GENERATORS:
        try:
            out += g(src)
        except Exception:
            continue
    for word in ("volatile", "const"):
        try:
            out += gen_qualifier(src, word)
        except Exception:
            pass
    return out


# ---------------------------------------------------------------------------
# scoring, through match.py
# ---------------------------------------------------------------------------

class Scorer:
    """Compile-and-compare with a content-addressed cache.

    Each call gets its own temp dir (match.run_one makes one per invocation),
    so a small thread pool is safe: the only shared state in match.py is its
    read-only evidence/symbol memo dicts, which are warmed once up front.
    """

    def __init__(self, cfg):
        self.cfg = cfg
        self.cache = {}
        self.lock = threading.Lock()
        self.compiles = 0

    def score(self, text):
        key = hashlib.sha1(text.encode("utf-8")).hexdigest()
        with self.lock:
            hit = self.cache.get(key)
        if hit is not None:
            return hit
        val = self._run(text, key)
        with self.lock:
            self.cache[key] = val
            self.compiles += 1
        return val

    def _run(self, text, key):
        c = self.cfg
        d = os.path.join(c["tmp"], key[:12])
        os.makedirs(d, exist_ok=True)
        path = os.path.join(d, os.path.basename(c["src"]))
        with open(path, "w") as fh:
            fh.write(text)
        try:
            r = match.run_one(path, c["func"], c["addr"], c["cc"], c["flags"],
                              c["thumb"], c["lang"], region=c["region"],
                              sdk_include=c["sdk_include"])
        except Exception as exc:
            return Score("CCERR", 10 ** 9, 0, 0, [], str(exc)[:120])
        if r.status == "CCERR":
            return Score("CCERR", 10 ** 9, 0, 0, [], match.first_line(r.log))
        wild = [s for s in (r.func.sites if r.func else []) if not s.resolved]
        size_ok = (r.target_size is None or r.target_size == r.size)
        nmiss = len(r.diffs) if r.status.startswith("DIFF") else 0
        if r.status == "SIZE":
            nmiss = 10 ** 6
        return Score(r.status, nmiss, r.size, r.target_size or 0,
                     [s.describe() for s in wild], r.note, size_ok)


class Score:
    __slots__ = ("status", "miss", "size", "target_size", "wild", "note",
                 "size_ok")

    def __init__(self, status, miss, size, target_size, wild, note,
                 size_ok=False):
        self.status = status
        self.miss = miss
        self.size = size
        self.target_size = target_size
        self.wild = wild
        self.note = note
        self.size_ok = size_ok

    def key(self):
        """Rank: size correct first, then the mismatch count."""
        return (0 if self.size_ok else 1, self.miss)

    def done(self):
        return self.status.startswith("EXACT") or self.status.startswith("MATCH")

    def __str__(self):
        return "%-7s %4d bytes  %s" % (
            self.status, self.size,
            "0 mismatches" if self.miss == 0 else
            ("size wrong (%d vs %d)" % (self.size, self.target_size)
             if self.miss >= 10 ** 6 else "%d mismatches" % self.miss))


# ---------------------------------------------------------------------------
# search
# ---------------------------------------------------------------------------

class Variant:
    __slots__ = ("text", "muts", "score")

    def __init__(self, text, muts, score):
        self.text = text
        self.muts = muts
        self.score = score


def apply_all(base, muts):
    """Apply a list of mutations, each re-derived against the current source."""
    src = base
    names = []
    for m in muts:
        nxt = m.apply(src)
        if nxt is None or nxt.render() == src.render():
            return None, None
        src = nxt
        names.append(repr(m))
    return src, names


def search_random(base, scorer, budget, rng, jobs):
    muts = mutations(base)
    if not muts:
        return []
    seen, plans = set(), []
    while len(plans) < budget * 3 and len(plans) < 4000:
        n = 1 if rng.random() < 0.55 else 2
        pick = tuple(sorted(rng.sample(range(len(muts)), min(n, len(muts)))))
        if pick in seen:
            if len(seen) >= min(4000, _ncombos(len(muts))):
                break
            continue
        seen.add(pick)
        plans.append([muts[i] for i in pick])
    rng.shuffle(plans)
    return _evaluate(base, plans, scorer, budget, jobs)


def _ncombos(n):
    return n + n * (n - 1) // 2


def _evaluate(base, plans, scorer, budget, jobs):
    """Score up to `budget` candidate plans, in parallel, stopping on a win."""
    from concurrent.futures import ThreadPoolExecutor
    out = []
    todo = []
    for plan in plans:
        src, names = apply_all(base, plan)
        if src is None:
            continue
        todo.append((src.render(), names))
        if len(todo) >= budget:
            break
    with ThreadPoolExecutor(max_workers=jobs) as ex:
        futs = {ex.submit(scorer.score, t): (t, n) for (t, n) in todo}
        for f in futs:
            pass
        for f, (t, n) in futs.items():
            sc = f.result()
            out.append(Variant(t, n, sc))
            if sc.done():
                for g in futs:
                    g.cancel()
                break
    return out


def search_hill(base, scorer, budget, rng, jobs):
    """Keep the best source so far; accept any single mutation that improves."""
    best_text = base.render()
    best_sc = scorer.score(best_text)
    best_muts = []
    results = [Variant(best_text, [], best_sc)]
    spent = 1
    restarts = 0
    cur = Source(best_text, base.func)
    cur_sc, cur_muts = best_sc, []
    while spent < budget:
        muts = mutations(cur)
        if not muts:
            break
        rng.shuffle(muts)
        batch = muts[:max(jobs, 1)]
        cands = []
        for m in batch:
            nxt = m.apply(cur)
            if nxt is None or nxt.render() == cur.render():
                continue
            cands.append((nxt.render(), cur_muts + [repr(m)]))
        if not cands:
            break
        from concurrent.futures import ThreadPoolExecutor
        with ThreadPoolExecutor(max_workers=jobs) as ex:
            scored = list(zip(cands, ex.map(lambda c: scorer.score(c[0]), cands)))
        spent += len(cands)
        improved = False
        for (text, names), sc in scored:
            results.append(Variant(text, names, sc))
            if sc.done():
                return results
            if sc.key() < cur_sc.key():
                cur, cur_sc, cur_muts = Source(text, base.func), sc, names
                improved = True
        if cur_sc.key() < best_sc.key():
            best_sc, best_text, best_muts = cur_sc, cur.render(), cur_muts
        if not improved:
            restarts += 1
            cur = Source(base.render(), base.func)
            cur_sc, cur_muts = results[0].score, []
            if restarts > 6:
                break
    _ = (best_muts,)
    return results


# ---------------------------------------------------------------------------
# main
# ---------------------------------------------------------------------------

def main(argv=None):
    ap = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--src", required=True)
    ap.add_argument("--func", required=True)
    ap.add_argument("--addr", required=True)
    ap.add_argument("--thumb", action="store_true")
    ap.add_argument("--arm", action="store_true")
    ap.add_argument("--cc", default="1.1p1")
    ap.add_argument("--flags", default="-O4,p")
    ap.add_argument("--lang", default=None)
    ap.add_argument("--region", default=None)
    ap.add_argument("--no-sdk-include", action="store_true")
    ap.add_argument("--budget", type=int, default=60)
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--out", default=None)
    ap.add_argument("--mode", choices=("random", "hill"), default="random")
    ap.add_argument("--jobs", type=int, default=4)
    ap.add_argument("--list", action="store_true",
                    help="print the available mutations and exit")
    args = ap.parse_args(argv)

    if not (args.thumb or args.arm):
        raise SystemExit("permute: pass --thumb or --arm; the ISA is never "
                         "guessed here")

    text = open(args.src).read()
    base = Source(text, args.func)

    if args.list:
        for m in mutations(base):
            print("%-22s line %d" % (m.name, m.line))
        return 0

    import tempfile
    tmp = tempfile.mkdtemp(prefix="permute_")
    cfg = {"src": args.src, "func": args.func, "addr": int(args.addr, 0),
           "cc": args.cc, "flags": args.flags.split(), "thumb": args.thumb,
           "lang": args.lang, "region": args.region,
           "sdk_include": not args.no_sdk_include, "tmp": tmp}

    # warm match.py's read-only memo dicts before any thread touches them
    match.evidence()
    match.sdk_symbols()
    match.matched_symbols()

    scorer = Scorer(cfg)
    base_sc = scorer.score(base.render())
    print("baseline  %s" % base_sc)
    if base_sc.status == "CCERR":
        print("  %s" % base_sc.note)
        return 2
    print("mutations available: %d" % len(mutations(base)))

    rng = random.Random(args.seed)
    if args.mode == "hill":
        results = search_hill(base, scorer, args.budget, rng, args.jobs)
    else:
        results = search_random(base, scorer, args.budget, rng, args.jobs)
    results.append(Variant(base.render(), [], base_sc))

    uniq = {}
    for v in results:
        k = hashlib.sha1(v.text.encode()).hexdigest()
        if k not in uniq:
            uniq[k] = v
    ranked = sorted(uniq.values(), key=lambda v: v.score.key())

    print()
    print("%-5s %-7s %6s %6s  %s" % ("rank", "status", "bytes", "miss",
                                     "mutations"))
    print("-" * 78)
    for i, v in enumerate(ranked[:10]):
        print("%-5d %-7s %6d %6s  %s"
              % (i + 1, v.score.status, v.score.size,
                 "size" if v.score.miss >= 10 ** 6 else v.score.miss,
                 ", ".join(v.muts) if v.muts else "(baseline)"))
    print("-" * 78)
    print("%d compiles, %d cached" % (scorer.compiles,
                                      len(scorer.cache) - scorer.compiles))

    best = ranked[0]
    if best.score.status.startswith("EXACT"):
        print("\nEXACT: %s" % (", ".join(best.muts) or "the baseline source"))
    elif best.score.status.startswith("MATCH"):
        print("\nMATCH (wildcarded relocation sites remain): %s"
              % (", ".join(best.muts) or "the baseline source"))
        for w in best.score.wild:
            print("  %s" % w)
    else:
        print("\nbest is still %s at %d mismatches (baseline %d)"
              % (best.score.status, best.score.miss, base_sc.miss))

    if args.out:
        with open(args.out, "w") as fh:
            fh.write(best.text)
        print("wrote %s" % args.out)
    return 0


if __name__ == "__main__":
    sys.exit(main())
