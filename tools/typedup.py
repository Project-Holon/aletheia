#!/usr/bin/env python3
"""typedup.py: list every type defined in more than one src/game file.

A "type name" is a typedef name or a struct/union/enum tag.  A definition is a
full body (`struct X { ... }`, `typedef struct { ... } X;`, `enum { ... } X`) at
file scope, in a .c or .h file under src/game.  Two headers that define the same
name cannot be included together, so every name must end up defined once.

Each name defined in more than one file is put in one class, by comparing its
definitions with the most common one:

  a0  every definition is the same text up to white space (member names included)
  a   same member types and offsets and same size; only member names differ
  b   same size and same member offsets, but a member type differs
  c   different layout (size or offsets differ)

Layouts use the compiler's rules (natural alignment, 64-bit members aligned to 4,
bit-fields packed into their declared unit).  Scalar types compare by width and
signedness (u32, unsigned int and unsigned long are one type).  A definition
whose size cannot be computed (unknown member type, unresolved array bound) is
compared by its member types only and flagged with a "?" after the class.

    python tools/typedup.py                  counts per class
    python tools/typedup.py --tsv OUT        one row per name: class, files, sizes
    python tools/typedup.py --names CLASS    names of one class (a0|a|b|c|bc)
    python tools/typedup.py --base           also list base typedefs (u8, s32, ...)
    python tools/typedup.py --conflicts [OUT.tsv]
                                             only the conflicts that cross files (see below)

Conflict mode.  A duplicate matters only when the type crosses files.  A name is a
conflict when
  (a) it is defined in a header and also defined in any other file,
  (b) two .c files define it and a function whose prototype names it is defined in one
      of them and mentioned (called or declared) in the other (a prototype that
      tools/mkheaders.py would export), or
  (c) two headers define it.
File-local private types that share a generic name in separate .c files are legal C
and are not counted.  The count is the number phase 1 and 2 drive to 0.
"""
import argparse
import collections
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
GAME = os.path.join(ROOT, "src", "game")
sys.path.insert(0, HERE)
import protocheck as pc  # noqa: E402

BASE = {"u8", "s8", "u16", "s16", "u32", "s32", "u64", "s64", "fx16", "fx32", "fx64", "BOOL",
        "vu8", "vu16", "vu32", "vu64", "vs8", "vs16", "vs32", "vs64", "f32", "vf32", "fx16c",
        "wchar_t", "size_t", "va_list"}
SCALAR_SIZE = {"u8": 1, "s8": 1, "char": 1, "u16": 2, "s16": 2, "u32": 4, "s32": 4,
               "u64": 8, "s64": 8, "float": 4, "double": 8, "void": 0}
KWQ = {"const", "volatile", "register", "static", "extern", "signed_"}


def files_of(tree):
    out = []
    for dp, _dn, fn in os.walk(tree):
        for f in fn:
            if f.endswith((".c", ".h")):
                out.append(os.path.join(dp, f))
    return sorted(out)


def depth_map(code):
    d, cur = [], 0
    for ch in code:
        if ch == "{":
            d.append(cur)
            cur += 1
        elif ch == "}":
            cur -= 1
            d.append(cur)
        else:
            d.append(cur)
    return d


def match_brace(code, i):
    """Index of the } matching the { at i, or -1."""
    depth = 0
    for j in range(i, len(code)):
        c = code[j]
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                return j
    return -1


DEF_RE = re.compile(r"(?:\btypedef\s+)?\b(struct|union|enum)\s*([A-Za-z_]\w*)?\s*\{")


class Def:
    __slots__ = ("name", "kind", "file", "body", "tag", "tdnames", "line")

    def __init__(self, name, kind, file, body, tag, tdnames, line):
        self.name, self.kind, self.file, self.body = name, kind, file, body
        self.tag, self.tdnames, self.line = tag, tdnames, line


def scan_file(path):
    """(defs, aliases): full definitions at file scope and plain `typedef X name;` aliases."""
    code = pc.clean(path)
    dm = depth_map(code)
    defs, aliases = [], []
    for m in DEF_RE.finditer(code):
        if dm[m.start()] != 0:
            continue
        # struct/union/enum must start a declaration (not be part of a cast or return type)
        kind, tag = m.group(1), m.group(2)
        lb = m.end() - 1
        rb = match_brace(code, lb)
        if rb < 0:
            continue
        body = code[lb + 1:rb]
        semi = code.find(";", rb)
        tail = code[rb + 1:semi] if semi >= 0 else ""
        is_td = bool(re.match(r"\s*typedef\b", code[m.start():m.start() + 8]))
        tdnames = []
        if is_td:
            for part in tail.split(","):
                nm = re.search(r"(\w+)\s*(\[[^\]]*\])?\s*$", part)
                if nm and part.count("*") == 0:
                    tdnames.append(nm.group(1))
        line = code.count("\n", 0, m.start()) + 1
        if "(" in tail and ")" in tail and not is_td:
            continue          # `struct X { } f(void) {...}`: a return type
        if tag:
            defs.append(Def(tag, kind, path, body, tag, tdnames, line))
        for n in tdnames:
            if n != tag:
                defs.append(Def(n, kind, path, body, tag, tdnames, line))
    for m in re.finditer(r"\btypedef\s+([^;{}]*);", code):
        if dm[m.start()] != 0:
            continue
        toks = re.findall(r"[A-Za-z_]\w*|\*", m.group(1))
        if "(" in m.group(1) or len(toks) < 2:
            continue
        aliases.append((toks[-1], " ".join(toks[:-1]), path))
    return defs, aliases


# ------------------------------------------------------------------ layouts

class Layout:
    def __init__(self):
        self.members = []   # (offset, size, type string, name)
        self.size = 0
        self.align = 1
        self.ok = True


def split_decls(body):
    """Member declarations of a struct body: top-level `;` separated, braces kept."""
    out, depth, cur = [], 0, []
    for ch in body:
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
        if ch == ";" and depth == 0:
            out.append("".join(cur))
            cur = []
        else:
            cur.append(ch)
    if "".join(cur).strip():
        out.append("".join(cur))
    return [s.strip() for s in out if s.strip()]


class Sizer:
    def __init__(self, defs, aliases):
        self.types = pc.Types([])
        for n, base, _p in aliases:
            self.types.alias.setdefault(n, set()).add(base)
        self.by_name = collections.defaultdict(list)
        for d in defs:
            self.by_name[d.name].append(d)
            for t in d.tdnames:
                self.types.alias.setdefault(t, set()).add("%s %s" % (d.kind, d.tag or t))
        self.cache = {}
        self.busy = set()

    def canon(self, toks):
        try:
            return self.types.canon(toks)
        except Exception:
            return " ".join(toks)

    def agg(self, name, kind=None):
        """Layout of a named aggregate: first definition that computes."""
        if name in self.cache:
            return self.cache[name]
        if name in self.busy:
            return None
        self.busy.add(name)
        res = None
        for d in self.by_name.get(name, []):
            res = self.layout(d)
            if res and res.ok:
                break
        self.busy.discard(name)
        self.cache[name] = res
        return res

    def type_size(self, toks):
        """(size, align) of a type token list, or None."""
        stars = toks.count("*")
        words = [t for t in toks if t != "*" and t not in KWQ]
        if stars:
            return 4, 4
        if not words:
            return None
        if words[0] in ("struct", "union") and len(words) > 1:
            lay = self.agg(words[1])
            return (lay.size, lay.align) if lay and lay.ok else None
        if words[0] == "enum":
            return 4, 4
        c = self.canon(words)
        if c.startswith("@fnptr"):
            return 4, 4
        if c in SCALAR_SIZE:
            s = SCALAR_SIZE[c]
            return s, min(s, 4) or 1
        if c.endswith("*"):
            return 4, 4
        if c.startswith(("struct ", "union ")):
            lay = self.agg(c.split()[1])
            return (lay.size, lay.align) if lay and lay.ok else None
        return None

    def layout(self, d):
        lay = Layout()
        if d.kind == "enum":
            lay.size, lay.align = 4, 4
            lay.members = [(0, 4, "enum", "")]
            return lay
        off = 0
        bit_unit = None        # (unit size, bits used) when inside a bit-field run
        for decl in split_decls(d.body):
            decl = decl.strip()
            if not decl:
                continue
            # nested aggregate with a body
            nm = re.match(r"(struct|union)\s*(\w*)\s*\{", decl)
            if nm:
                lb = decl.index("{")
                rb = match_brace(decl, lb)
                inner = Def(nm.group(2) or "", nm.group(1), d.file, decl[lb + 1:rb], nm.group(2), [], 0)
                sub = self.layout(inner)
                rest = decl[rb + 1:]
                dims = [self.dim(x) for x in re.findall(r"\[([^\]]*)\]", rest)]
                if not sub.ok or any(x is None for x in dims):
                    lay.ok = False
                    continue
                cnt = 1
                for x in dims:
                    cnt *= x
                bit_unit = None
                off = (off + sub.align - 1) // sub.align * sub.align
                lay.members.append((off, sub.size * cnt, "%s{%s}%s" % (
                    nm.group(1), ",".join("%d:%s" % (m[0], m[2]) for m in sub.members), dims), ""))
                lay.align = max(lay.align, sub.align)
                if d.kind == "union":
                    lay.size = max(lay.size, sub.size * cnt)
                else:
                    off += sub.size * cnt
                continue
            # function pointer member
            if re.search(r"\(\s*\*", decl):
                sz = al = 4
                bit_unit = None
                off = (off + 3) // 4 * 4
                lay.members.append((off, 4, "@fnptr", ""))
                lay.align = max(lay.align, 4)
                if d.kind == "union":
                    lay.size = max(lay.size, 4)
                else:
                    off += 4
                continue
            # ordinary declarators: type decl1, decl2
            first, *others = decl.split(",") if "{" not in decl else [decl]
            ftoks = re.findall(r"[A-Za-z_]\w*|\*|\d+", re.sub(r"\[[^\]]*\]|:\s*\w+", " ", first))
            bits_m = re.search(r":\s*(\w+)\s*$", first)
            if len(ftoks) < 2:
                lay.ok = False
                continue
            name1 = ftoks[-1]
            tt = ftoks[:-1]
            ts = self.type_size([t for t in tt])
            if ts is None:
                lay.ok = False
                ts = (0, 1)
            tsize, talign = ts
            ctype = self.canon([t for t in tt if t not in KWQ])
            decls = [(first, name1)]
            for o in others:
                ot = re.findall(r"[A-Za-z_]\w*|\*", re.sub(r"\[[^\]]*\]", " ", o))
                if ot:
                    decls.append((o, ot[-1]))
            for k, (txt, nm1) in enumerate(decls):
                ptr = txt.count("*") if k else 0
                size, align = (4, 4) if ptr else (tsize, talign)
                ty = ctype + "*" * ptr
                dims = [self.dim(x) for x in re.findall(r"\[([^\]]*)\]", txt)]
                if any(x is None for x in dims):
                    lay.ok = False
                    dims = [x if x is not None else 1 for x in dims]
                    ty += "[?]"
                cnt = 1
                for x in dims:
                    cnt *= x
                if dims:
                    ty += "".join("[%d]" % x for x in dims)
                bm = re.search(r":\s*(\w+)\s*$", txt)
                if bm and d.kind == "struct":
                    try:
                        nb = int(bm.group(1), 0)
                    except ValueError:
                        lay.ok = False
                        nb = 1
                    if bit_unit and bit_unit[0] == size and bit_unit[1] + nb <= size * 8:
                        bit_unit = (size, bit_unit[1] + nb)
                        lay.members.append((off - size + (bit_unit[1] - nb) // 8, 0, "%s:%d" % (ctype, nb), nm1))
                        continue
                    off = (off + align - 1) // align * align
                    bit_unit = (size, nb)
                    lay.members.append((off, size, "%s:%d" % (ctype, nb), nm1))
                    lay.align = max(lay.align, align)
                    off += size
                    continue
                bit_unit = None
                if d.kind == "union":
                    lay.members.append((0, size * cnt, ty, nm1))
                    lay.size = max(lay.size, size * cnt)
                else:
                    off = (off + align - 1) // align * align
                    lay.members.append((off, size * cnt, ty, nm1))
                    off += size * cnt
                lay.align = max(lay.align, align)
        if d.kind == "struct":
            lay.size = off
        lay.size = (lay.size + lay.align - 1) // lay.align * lay.align
        return lay

    def dim(self, text):
        t = text.strip()
        if not t:
            return 0
        try:
            return int(t, 0)
        except ValueError:
            pass
        if re.fullmatch(r"[\dxXa-fA-F+\-*/() <>|&~]+", t) and not re.search(r"[g-zG-Z_]", t):
            try:
                return int(eval(t.replace("/", "//"), {"__builtins__": {}}))
            except Exception:
                return None
        return None


def norm_text(body):
    return re.sub(r"\s+", " ", body).strip()


def classify(group):
    """group: list of (Def, Layout). Returns (class, flagged)."""
    flagged = any(not lay.ok for _d, lay in group)
    texts = collections.Counter(norm_text(d.body) for d, _l in group)
    if len(texts) == 1:
        return "a0", flagged
    sigs_t = collections.Counter(tuple((m[0], m[1], m[2]) for m in lay.members) for _d, lay in group)
    if len(sigs_t) == 1 and not flagged:
        return "a", flagged
    sigs_o = collections.Counter((lay.size, tuple((m[0], m[1]) for m in lay.members)) for _d, lay in group)
    if len(sigs_o) == 1 and not flagged:
        return "b", flagged
    if flagged:
        # fall back on member type sequences
        seq = collections.Counter(tuple(m[2] for m in lay.members) for _d, lay in group)
        if len(seq) == 1:
            return "a", flagged
        cnt = collections.Counter(len(lay.members) for _d, lay in group)
        if len(cnt) == 1:
            return "b", flagged
    return "c", flagged


def analyse(tree=GAME, base=False):
    all_defs, all_aliases = [], []
    for f in files_of(tree):
        d, a = scan_file(f)
        all_defs += d
        all_aliases += a
    sizer = Sizer(all_defs, all_aliases)
    by = collections.defaultdict(list)
    for d in all_defs:
        by[(d.name)].append(d)
    rows = []
    for name, ds in sorted(by.items()):
        files = sorted({d.file for d in ds})
        if len(files) < 2:
            continue
        group = []
        for d in ds:
            lay = sizer.layout(d)
            group.append((d, lay))
        cls, fl = classify(group)
        sizes = sorted({lay.size for _d, lay in group if lay.ok})
        rows.append((name, cls + ("?" if fl else ""), len(files), len(ds), sizes))
    # base typedef spellings
    spell = collections.defaultdict(collections.Counter)
    for n, b, _p in all_aliases:
        if n in BASE:
            spell[n][b] += 1
    return rows, spell, all_defs


def rel(p):
    return os.path.relpath(p, ROOT).replace(os.sep, "/")


def conflicts(tree, defs):
    """[(name, kind, files)] for the names that cross files; kind is a, b or c (see the docstring)."""
    import mkheaders as mk
    import placeholdernames as ph
    by = collections.defaultdict(list)
    for d in defs:
        by[d.name].append(d)
    multi = {}
    for n, ds in by.items():
        fs = sorted({d.file for d in ds})
        if len(fs) > 1:
            multi[n] = fs
    out = []
    pending = {}
    for n, fs in multi.items():
        nh = sum(1 for f in fs if f.endswith(".h"))
        if nh >= 2:
            out.append((n, "c", fs))
        elif nh == 1:
            out.append((n, "a", fs))
        else:
            pending[n] = fs
    if pending:
        idx = mk.Index(sorted(ph.files_under([tree])))
        alias = idx.tindex.types.alias
        # per .c file: type names its exported prototypes use, and the names of the public functions
        uses = collections.defaultdict(lambda: collections.defaultdict(set))   # file -> type name -> {func}
        for f, dl in idx.by_file.items():
            for d in dl:
                ids = mk.idents_of(d.ret + " x")
                if d.ptext.strip() not in ("", "void"):
                    for p in mk.pn.split_params(d.ptext):
                        ids += mk.idents_of(p)
                for kind, nm, _ptr in ids:
                    if kind == "?":
                        continue
                    names = {nm}
                    if kind == "typedef":
                        for r in alias.get(nm, ()):
                            m = re.fullmatch(r"(?:struct|union|enum) (\w+)", r)
                            if m:
                                names.add(m.group(1))
                    for x in names:
                        uses[f][x].add(d.name)
        text = {}
        for n, fs in pending.items():
            hit = False
            for a in fs:
                funcs = uses[a].get(n, ())
                for b in fs:
                    if b == a or hit:
                        continue
                    if b not in text:
                        text[b] = pc.clean(b)
                    if any(re.search(r"\b%s\b" % re.escape(fn), text[b]) for fn in funcs):
                        hit = True
                if hit:
                    break
            if hit:
                out.append((n, "b", fs))
    return sorted(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--tree", default=GAME)
    ap.add_argument("--tsv")
    ap.add_argument("--names")
    ap.add_argument("--base", action="store_true")
    ap.add_argument("--conflicts", nargs="?", const="-", metavar="OUT.tsv",
                    help="only the cross-file conflicts; optional TSV path")
    a = ap.parse_args()
    if a.conflicts:
        _r, _s, defs = analyse(a.tree)
        rows = conflicts(a.tree, defs)
        cnt = collections.Counter(r[1] for r in rows)
        print("conflicting type names: %d  (header+other file: %d, crossing prototype: %d, two headers: %d)" % (
            len(rows), cnt["a"], cnt["b"], cnt["c"]))
        if a.conflicts != "-":
            with open(a.conflicts, "w", encoding="utf-8", newline="\n") as fh:
                fh.write("name\tkind\tfiles\n")
                for n, k, fs in rows:
                    fh.write("%s\t%s\t%s\n" % (n, k, ",".join(rel(f) for f in fs)))
        return
    rows, spell, defs = analyse(a.tree)
    cnt = collections.Counter(r[1].rstrip("?") for r in rows)
    ndefs = sum(r[3] for r in rows)
    print("names defined in more than one file: %d (%d definitions in %d files)" % (
        len(rows), ndefs, len({d.file for d in defs if d.name in {r[0] for r in rows}})))
    for k in ("a0", "a", "b", "c"):
        flagged = sum(1 for r in rows if r[1] == k + "?")
        print("  class %-2s %5d   (size unknown for some definition: %d)" % (k, cnt[k], flagged))
    if a.base or True:
        multi = {n: c for n, c in spell.items() if len(c) > 1}
        print("base typedef names spelled more than one way: %d" % len(multi))
        if a.base:
            for n, c in sorted(spell.items()):
                print("  %-8s %s" % (n, dict(c)))
    if a.tsv:
        with open(a.tsv, "w", encoding="utf-8", newline="\n") as fh:
            fh.write("name\tclass\tfiles\tdefinitions\tsizes\n")
            for n, c, nf, nd, sz in rows:
                fh.write("%s\t%s\t%d\t%d\t%s\n" % (n, c, nf, nd, ",".join(map(str, sz))))
    if a.names:
        want = set(a.names.replace("bc", "b,c").split(","))
        for n, c, nf, nd, sz in rows:
            if c.rstrip("?") in want:
                print("%s\t%s\t%d files\tsizes %s" % (n, c, nf, sz))


if __name__ == "__main__":
    main()
