#!/usr/bin/env python3
"""mkheaders.py: one header per source file, declaring its public functions.

src/game .c files declare the functions they call with their own `extern`
prototypes, one copy per caller, and those copies drift from the definition
(tools/protocheck.py counts the disagreements).  The original build had one
header per module.  This tool rebuilds that:

  1. Index.  Every non-static function definition of every src/game .c file
     (name, prototype text copied from the definition, region, file) and every
     static one (never exported).  The declaration parser is the one of
     tools/protocheck.py (comments and preprocessor lines blanked, brace depth).
  2. Header.  `src/game/<region>/<stem>.h` for each source file with public
     functions: include guard, the prototypes copied from the definitions, a
     forward `struct X;` for each struct that is only named through a pointer,
     and `#include` of the header that defines any other type a prototype
     names.  Includes inside headers are written `../<region>/<file>`, which
     resolves from any top-level source file (the compiler looks a nested
     quote include up from the source file's folder, not the header's).  An
     existing `<stem>.h` is merged into: prototypes it lacks are added before
     its last `#endif`.  A function whose prototype needs a type that no header
     defines (a typedef or struct that only a .c file spells) is left out of
     the header and listed in the report.
  3. Rewrite a caller.  Each top-level `extern` function declaration whose
     function has exactly one definition in the caller's region, else in
     ARM9 (overlays share addresses, so a name resolves by region first), is
     removed, and `#include "<owner header>"` is put where the first of them
     stood.  Declarations of functions with no src/game definition (SDK
     prebuilt code, linker symbols) stay and are counted.  A base typedef
     (u32, s16, ...) that the header names and the caller does not have yet
     is added just before the include.
  4. Verify.  A rewritten caller is checked with tools/gameverify.py; when it
     is not EXACT, each owner group is tried alone, and a group that changes
     the bytes keeps the caller's old declarations (the definition's type is
     probably wrong, or the caller relied on another one).  Those cases are
     written to a report TSV: file, function, old prototype, new prototype.

    python tools/mkheaders.py --dry-run                   counts for the whole tree
    python tools/mkheaders.py --dry-run --region ov231    one region, per file
    python tools/mkheaders.py --apply --region ov231 [--report OUT.tsv] [--jobs N]

--apply writes the headers of every file in the selected regions and rewrites
every .c file in them (callers in other regions are not touched, so the
headers of a region stay valid for later conversions).  --files LIST restricts
the rewritten callers to the paths in LIST.
"""
import argparse
import collections
import concurrent.futures
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
GAME = os.path.join(ROOT, "src", "game")
sys.path.insert(0, HERE)
import protocheck as pc  # noqa: E402
import protonames as pn  # noqa: E402
import placeholdernames as ph  # noqa: E402

MAIN_REGIONS = ("arm9", "arm9_autoload0_ITCM")
QUALS = {"extern", "static", "inline", "__inline", "asm", "const", "volatile", "register", "auto"}
CKW = pc.SCALARS | QUALS | {"struct", "union", "enum", "typedef", "restrict"}
BASE_SPELL = {"u8": "unsigned char", "s8": "signed char", "u16": "unsigned short", "s16": "short",
              "u32": "unsigned int", "s32": "int", "u64": "unsigned long long", "s64": "long long"}


def rel(path):
    return os.path.relpath(path, ROOT).replace(os.sep, "/")


def region_of(path):
    return os.path.relpath(path, GAME).replace(os.sep, "/").split("/")[0]


def stem_of(path):
    return os.path.splitext(os.path.basename(path))[0]


def pc_clean_text(raw):
    return pc.strip_pp(ph.strip_comments(raw))


# ------------------------------------------------------------------ types

class TypeIndex:
    """Where each typedef name and struct/union/enum tag is defined."""

    def __init__(self, files):
        self.types = pc.Types(files)
        self.typedef_in = collections.defaultdict(set)   # name -> {header path}
        self.tag_in = collections.defaultdict(set)       # (kind, tag) -> {header path}
        for f in files:
            if not f.endswith(".h"):
                continue
            code = pc.clean(f)
            t = pc.Types([])
            t._scan(code)
            for name in t.alias:
                self.typedef_in[name].add(f)
            for m in re.finditer(r"\b(struct|union|enum)\s+(\w+)\s*\{", code):
                self.tag_in[(m.group(1), m.group(2))].add(f)
        self.base = set(n for n in self.types.alias if self.is_base(n))

    def is_base(self, name):
        res = self.types.alias.get(name)
        if not res or "@fnptr" in res:
            return False
        c = self.types.canon([name])
        return bool(pc.int_kind(c)) or c in ("float", "double")

    def base_spelling(self, name):
        c = self.types.canon([name])
        return BASE_SPELL.get(c, c)


def strip_name(text):
    """Parameter text without its declared name (and array suffix); same tokens otherwise."""
    text = re.sub(r"\[[^\]]*\]", " * ", text)
    toks = re.findall(r"[A-Za-z_]\w*|\*", text)
    if len(toks) >= 2 and re.match(r"[A-Za-z_]", toks[-1]) and toks[-1] not in CKW \
            and toks[-2] not in ("struct", "union", "enum"):
        return toks[:-1]
    return toks


def idents_of(text):
    """Type identifiers of one parameter (or of a return type with a dummy name).

    Returns [(kind, name, by_pointer)]: kind is 'typedef', 'struct', 'union', 'enum', or '?'."""
    res = []
    text = text.strip()
    if not text or text in ("void", "..."):
        return res
    if "(" in text:
        m = re.search(r"\(\s*\*+\s*\w*\s*\)\s*\(", text)
        if not m:
            return [("?", text, False)]
        head = text[:m.start()]
        depth, j = 1, m.end()
        while j < len(text) and depth:
            depth += {"(": 1, ")": -1}.get(text[j], 0)
            j += 1
        inner = text[m.end():j - 1]
        res += idents_of(head + " *")
        for p in pn.split_params(inner):
            res += idents_of(p)
        return res
    toks = strip_name(text)
    i = 0
    while i < len(toks):
        t = toks[i]
        if t in ("struct", "union", "enum") and i + 1 < len(toks):
            ptr = i + 2 < len(toks) and toks[i + 2] == "*"
            res.append((t, toks[i + 1], ptr))
            i += 2
            continue
        if t not in CKW and re.match(r"[A-Za-z_]", t):
            res.append(("typedef", t, False))
        i += 1
    return res


# ------------------------------------------------------------------ index

class Def:
    __slots__ = ("name", "file", "region", "proto", "line", "asm", "ptext", "ret")


def proto_text(code, ex):
    """The definition's declaration as a prototype: qualifiers dropped, whitespace collapsed."""
    pre = code[ex["pre_start"]:ex["name_start"]]
    toks = [t for t in pre.split() if t not in ("extern", "static", "asm", "inline", "__inline")]
    head = " ".join(toks)
    params = " ".join(code[ex["par_start"]:ex["par_end"]].split())
    name = code[ex["name_start"]:ex["par_start"]].strip().rstrip("(").strip()
    sep = "" if head.endswith("*") else " "
    return "%s%s%s(%s);" % (head, sep, name, params), head


class Index:
    def __init__(self, files):
        self.tindex = TypeIndex(files)
        self.defs = collections.defaultdict(list)       # name -> [Def] non-static
        self.by_file = collections.defaultdict(list)    # c file -> [Def] in order
        self.statics = collections.defaultdict(set)     # c file -> {name}
        self.decls = {}                                  # c file -> (code, depths, records)
        for f in files:
            if not f.endswith(".c"):
                continue
            recs, code, depths = pc.scan(f, self.tindex.types)
            self.decls[f] = (code, depths, recs)
            for name, ret, params, line, is_def, static, ex in recs:
                if not is_def:
                    continue
                if static or "inline" in ex["pre_toks"] or "__inline" in ex["pre_toks"]:
                    self.statics[f].add(name)
                    continue
                d = Def()
                d.name, d.file, d.region, d.line = name, f, region_of(f), line
                d.proto, d.ret = proto_text(code, ex)
                d.ptext = ex["ptext"]
                d.asm = "asm" in ex["pre_toks"]
                self.defs[name].append(d)
                self.by_file[f].append(d)

    def owner(self, caller, name):
        """The single Def a declaration in `caller` names, or (None, reason)."""
        reg = region_of(caller)
        for scope in ([reg], list(MAIN_REGIONS)):
            c = [d for d in self.defs.get(name, []) if d.region in scope]
            if len(c) == 1:
                return c[0], ""
            if len(c) > 1:
                return None, "defined %d times in %s" % (len(c), "/".join(scope))
        if self.defs.get(name):
            return None, "defined only in another region"
        return None, "no src/game definition"


# ---------------------------------------------------------------- headers

def guard_of(path):
    return "GAME_%s_%s_H" % (region_of(path).upper(), stem_of(path).upper())


def header_path(cfile):
    return os.path.splitext(cfile)[0] + ".h"


def header_inc(target):
    return "../%s/%s" % (region_of(target), os.path.basename(target))


def quoted_includes(path, raw=None):
    if raw is None:
        raw = open(path, encoding="latin1").read()
    return {os.path.basename(i) for i in re.findall(r'^\s*#\s*include\s+"([^"]+)"', raw, re.M)}


def include_closure(path, seen=None):
    """Paths of the files a file includes by quoted path, directly or not."""
    seen = seen if seen is not None else set()
    if not os.path.isfile(path):
        return seen
    raw = open(path, encoding="latin1").read()
    for i in re.findall(r'^\s*#\s*include\s+"([^"]+)"', raw, re.M):
        q = os.path.normpath(os.path.join(os.path.dirname(path), i))
        if q not in seen:
            seen.add(q)
            include_closure(q, seen)
    return seen


PLAIN_INC = re.compile(r'^([ \t]*#[ \t]*include[ \t]+")([A-Za-z0-9_.]+\.h)(")', re.M)


def qualify_includes(path):
    """Quoted includes of a header that name a sibling by bare name become ../<region>/<name>.

    The compiler looks a nested quote include up from the top-level source file's folder, so a bare sibling
    name only resolves for a source in the header's own region; the qualified form resolves from any region.
    Returns True when the header changed."""
    raw = open(path, encoding="latin1", newline="").read()
    reg = region_of(path)
    folder = os.path.dirname(path)

    def fix(m):
        if os.path.isfile(os.path.join(folder, m.group(2))):
            return "%s../%s/%s%s" % (m.group(1), reg, m.group(2), m.group(3))
        return m.group(0)

    out = PLAIN_INC.sub(fix, raw)
    if out != raw:
        write(path, out)
        return True
    return False


def pick_header(cands, owner_file, closure):
    """Choose one defining header among several: the owner's own, else the region's, else ARM9's."""
    cands = sorted(cands)
    if len(cands) == 1:
        return cands[0]
    for tier in ([c for c in cands if os.path.normpath(c) in closure],
                 [c for c in cands if region_of(c) == region_of(owner_file)],
                 [c for c in cands if region_of(c) == "arm9"]):
        if tier:
            return tier[0]
    return None


def classify_def(idx, d, owner_inc):
    """Needs of one prototype: (ok, reason, headers, fwd_structs, base_names, local typedef lines)."""
    ti = idx.tindex
    headers, fwd, bases, locs = [], [], [], []
    ids = idents_of(d.ret + " x")
    if d.ptext.strip() not in ("", "void"):
        for p in pn.split_params(d.ptext):
            ids += idents_of(p)
    for kind, name, ptr in ids:
        if kind == "?":
            return False, "unparsed parameter", [], [], [], []
        if kind == "typedef":
            if name in ti.base:
                bases.append(name)
                continue
            if name not in ti.types.alias:
                return False, "unknown type %s" % name, [], [], [], []
            res = ti.types.alias[name]
            only = next(iter(res)) if len(res) == 1 else ""
            m = re.fullmatch(r"(struct|union) (\w+)", only)
            if m and (m.group(1), m.group(2)) not in ti.tag_in and only not in ti.types.anon:
                # an opaque struct that no header defines: the header spells the typedef itself
                fwd.append(only)
                loc = "typedef %s %s;" % (only, name)
                if loc not in locs:
                    locs.append(loc)
                continue
            h = pick_header(ti.typedef_in.get(name, ()), d.file, owner_inc)
            if h is None:
                return False, "type %s has no header" % name, [], [], [], []
            headers.append(h)
        elif kind != "enum" and ptr:
            fwd.append("%s %s" % (kind, name))
        else:
            h = pick_header(ti.tag_in.get((kind, name), ()), d.file, owner_inc)
            if h is None:
                return False, "%s %s needed complete, no header" % (kind, name), [], [], [], []
            headers.append(h)
    return True, "", headers, fwd, bases, locs


def build_headers(idx):
    """{c file: info}.  info: path, ok defs, skipped [(def, reason)], headers, fwd, bases."""
    out = {}
    for f, defs in idx.by_file.items():
        owner_inc = include_closure(f)
        ok, skipped = [], []
        headers, fwd, bases, locs = [], [], set(), []
        for d in defs:
            good, why, hs, fs, bs, ls = classify_def(idx, d, owner_inc)
            if not good:
                skipped.append((d, why))
                continue
            ok.append(d)
            headers += [h for h in hs if h not in headers]
            for s_ in fs:
                if s_ not in fwd:
                    fwd.append(s_)
            locs += [s for s in ls if s not in locs]
            bases.update(bs)
        out[f] = dict(path=header_path(f), ok=ok, skipped=skipped, headers=headers, fwd=fwd, bases=bases, locs=locs)
    return out


def marker(f):
    return "/* Public functions of %s.c, prototypes copied from their definitions. */" % stem_of(f)


def header_text(f, info, existing=None):
    """Text of a new header, or the merged text of an existing one (one written by this tool is redone)."""
    if existing is not None and marker(f) in existing:
        existing = None
    own = os.path.basename(info["path"])
    inc = [h for h in info["headers"] if os.path.basename(h) != own]
    fwd = list(info["fwd"])
    if existing is not None:
        have = set(re.findall(r"\b(\w+)\s*\(", pc_clean_text(existing)))
        add = [d.proto for d in info["ok"] if d.name not in have]
        if not add:
            return existing
        pre = "".join('#include "%s"\n' % header_inc(h) for h in inc if header_inc(h) not in existing)
        pre += "".join("%s;\n" % s for s in fwd if not re.search(r"\b%s\s*;" % re.escape(s), existing))
        i = existing.rfind("#endif")
        if i < 0:
            return existing.rstrip("\n") + "\n" + pre + "\n".join(add) + "\n"
        return existing[:i] + pre + "\n".join(add) + "\n\n" + existing[i:]
    g = guard_of(f)
    lines = ["#ifndef %s" % g, "#define %s" % g, "", marker(f), ""]
    for s in fwd:
        lines.append("%s;" % s)
    lines += info["locs"]
    if fwd or info["locs"]:
        lines.append("")
    for h in inc:
        lines.append('#include "%s"' % header_inc(h))
    if inc:
        lines.append("")
    lines += [d.proto for d in info["ok"]]
    lines += ["", "#endif"]
    return "\n".join(lines) + "\n"


# ---------------------------------------------------------------- callers

def visible_names(path, upto=None, seen=None, raw=None):
    """Typedef names visible in a file before offset `upto`: its own text and its quoted includes."""
    seen = seen if seen is not None else set()
    if path in seen or not os.path.isfile(path):
        return set()
    seen.add(path)
    if raw is None:
        raw = open(path, encoding="latin1").read()
    code = pc_clean_text(raw)
    if upto is not None:
        code = code[:upto]
        raw = raw[:upto]
    t = pc.Types([])
    t._scan(code)
    out = set(t.alias)
    for m in re.finditer(r'^[ \t]*#[ \t]*include[ \t]+"([^"]+)"', raw, re.M):
        out |= visible_names(os.path.normpath(os.path.join(os.path.dirname(path), m.group(1))), None, seen)
    return out


class Plan:
    def __init__(self, f):
        self.file = f
        self.removals = []     # (start, end, name, owner Def, old text)
        self.raw = None        # the caller's text when the plan was made (the offsets refer to it)
        self.keep = []         # (name, reason)


def plan_caller(idx, hdrs, f):
    code, depths, recs = idx.decls[f]
    raw = open(f, encoding="latin1", newline="").read()
    plan = Plan(f)
    plan.raw = raw
    if len(raw) != len(code):
        plan.keep.append(("*", "file text and parsed text differ in length"))
        return plan
    own = {d.name for d in idx.by_file.get(f, [])} | idx.statics.get(f, set())
    for name, ret, params, line, is_def, static, ex in recs:
        if is_def or static or ex["depth"] != 0 or "typedef" in ex["pre_toks"]:
            continue
        end = code.find(";", ex["par_end"])
        if end < 0 or code[ex["par_end"] + 1:end].strip():
            continue                              # not a plain declaration (declarator list, attribute)
        if name in own:
            continue                              # forward declaration of the file's own function
        d, why = idx.owner(f, name)
        if d is None:
            plan.keep.append((name, why))
            continue
        if d.file == f:
            continue
        info = hdrs.get(d.file)
        if info is None or d not in info["ok"]:
            why = "; ".join(w for dd, w in (info["skipped"] if info else []) if dd is d) or "no header"
            plan.keep.append((name, "owner header lacks it (%s)" % why))
            continue
        s = ex["pre_start"]
        while s < len(code) and code[s] in " \t\n":
            s += 1
        ls = raw.rfind("\n", 0, s) + 1
        if not raw[ls:s].strip():
            s = ls
        e = end + 1
        tail = raw[e:raw.find("\n", e) if raw.find("\n", e) >= 0 else len(raw)]
        if not tail.strip():
            e += len(tail) + 1
        if "#" in raw[s:e] or "/*" in raw[s:e] or "//" in raw[s:e]:
            plan.keep.append((name, "declaration holds a comment or directive"))
            continue
        plan.removals.append((s, min(e, len(raw)), name, d, " ".join(code[ex["pre_start"]:end + 1].split())))
    return plan


def apply_plan(idx, hdrs, plan, skip_owners=(), inject=True, extra=(), late=False):
    """New text of the caller, the includes added, the base typedefs added."""
    f = plan.file
    raw = plan.raw
    rems = [r for r in plan.removals if r[3].file not in skip_owners]
    if not rems:
        return raw, [], []
    groups = collections.OrderedDict()
    for r in sorted(rems, key=lambda r: r[0]):
        groups.setdefault(r[3].file, []).append(r)
    already = quoted_includes(f, raw)
    reg = region_of(f)
    code = pc_clean_text(raw)
    inserts, added, typedefs = [], [], []
    vis = set()
    nl = chr(10)
    extra_text = ""
    extra = sorted(extra, key=lambda b: (b.startswith("inc:"), b))
    if extra:
        first = min(r[0] for items in groups.values() for r in items)
        have = visible_names(f, first, raw=raw)
        for b in sorted(extra):
            if b.startswith("inc:"):
                b = b[4:]
                # a header that defines a type another header of the group needs first
                inc0 = os.path.basename(b) if region_of(b) == reg else "../%s/%s" % (region_of(b), os.path.basename(b))
                if os.path.basename(b) not in already:
                    extra_text += '#include "%s"' % inc0 + nl
                    added.append(inc0)
            elif b.startswith("fwd:"):
                b = b[4:]
                res = next(iter(idx.tindex.types.alias[b]))
                extra_text += "typedef %s %s;" % (res, b) + nl
                typedefs.append(b)
            elif b not in have:
                extra_text += "typedef %s %s;" % (idx.tindex.base_spelling(b), b) + nl
                vis.add(b)
                typedefs.append(b)
    late_pos = None
    if late:
        # every include goes where the file first needs a declaration: before its first function definition
        # or the first use of a removed name, whichever is earlier (the file's own types stand above it)
        recs = idx.decls[f][2]
        cands = []
        for name, _r, _p, _l, is_def, static, ex in recs:
            if is_def and ex["depth"] == 0:
                q = ex["pre_start"]
                while q < len(code) and code[q] in " \t\n":
                    q += 1
                cands.append(q)
                break
        gone = [(r[0], r[1]) for r in rems]
        for r in rems:
            for m in re.finditer(r"\b%s\b" % re.escape(r[2]), code):
                if not any(a <= m.start() < b for a, b in gone):
                    cands.append(m.start())
                    break
        late_pos = min(cands) if cands else len(code)
        late_pos = code.rfind("\n", 0, late_pos) + 1
    for of, items in groups.items():
        hp = hdrs[of]["path"]
        s0 = late_pos if late_pos is not None else items[0][0]
        base = os.path.basename(hp)
        inc = base if reg == region_of(hp) else "../%s/%s" % (region_of(hp), base)
        text = ""
        pos = s0
        if inject:
            vis |= visible_names(f, s0, raw=raw)
            own = visible_names(hp)
            anywhere = visible_names(f, raw=raw)
            for b in sorted(hdrs[of]["bases"]):
                if b in vis or b in own:
                    continue
                m = re.compile(r"typedef[^;{}]*\b%s\s*;" % re.escape(b)).search(code, s0) if b in anywhere else None
                if m:
                    # the file spells it later: the include moves below that line
                    e = code.find(nl, m.end())
                    pos = max(pos, e + 1 if e >= 0 else len(code))
                    vis.add(b)
                    continue
                text += "typedef %s %s;" % (idx.tindex.base_spelling(b), b) + nl
                vis.add(b)
                typedefs.append(b)
            vis |= own
        if base not in already:
            text += '#include "%s"' % inc + nl
            added.append(inc)
        if extra_text:
            text = extra_text + text
            extra_text = ""
        if text:
            inserts.append((pos, text))
    rem = sorted((r[0], r[1]) for items in groups.values() for r in items)
    ops = []                                   # (start, kind, order, end, text); kind 1 = removal
    for st, en in rem:
        ops.append((st, 1, 0, en, ""))
    for i, (p0, t) in enumerate(inserts):
        for st, en in rem:
            if st < p0 < en:
                p0 = en                        # an include never lands inside a removed declaration
        ops.append((p0, 0, i, p0, t))
    out = raw
    for st, kind, _i, en, t in sorted(ops, reverse=True):
        out = out[:st] + t + out[en:]
    return out, added, typedefs


# ---------------------------------------------------------------- verify

def verify_file(path):
    p = subprocess.run([sys.executable, os.path.join(HERE, "gameverify.py"), "--file", path],
                       capture_output=True, text=True, cwd=ROOT)
    lines = p.stdout.strip().splitlines()
    last = lines[-1] if lines else ""
    return "not exact: 0," in last, "\n".join(lines[-3:])


def write(path, text):
    with open(path, "w", encoding="latin1", newline="") as fh:
        fh.write(text)


ERR = re.compile(r"^(.*?):(\d+): (?!warning)(.*)", re.M)


def compile_errors(path):
    """[(line, message)] of the compile errors of one source, [] when it compiles."""
    import tempfile
    import shutil
    import match
    import gameverify as gv
    raw = open(path, encoding="latin1").read()
    _h, st = gv.settings_of(raw)
    work = tempfile.mkdtemp(prefix="mkh_")
    try:
        obj, _cmd, log, _rc = match.compile_tu(path, st["compiler"], st["flags"].split(), st["isa"] == "thumb",
                                               st["lang"] or None, work)
    finally:
        shutil.rmtree(work, ignore_errors=True)
    if obj is not None:
        return []
    errs = []
    for m in ERR.finditer(log):
        where = m.group(1).replace(chr(92), "/")
        own = os.path.basename(where) == os.path.basename(path)
        if m.group(3).startswith("(included from"):
            continue
        errs.append((int(m.group(2)) if own else -1, m.group(3).strip(), None if own else where))
    return errs or [(0, log.strip()[:200], None)]


def culprits_of(text, errs, funcs):
    """{name: message} of the functions called on an error line (or in the two lines above it, for a call
    that spans lines).  A message that is not about a call's arguments or result explains nothing."""
    lines = text.split("\n")
    out = {}
    for ln, msg, _w in errs:
        if ln <= 0 or not re.search(r"implicit conversion|does not match|illegal operands|void|too many|too few|"
                                    r"not enough|argument|cannot convert|incompatible", msg):
            continue
        for lo in (ln - 1, max(0, ln - 3)):
            window = "\n".join(lines[lo:ln])
            hit = [fn for fn in funcs if re.search(r"\b%s\s*\(" % re.escape(fn), window)]
            if hit:
                for fn in hit:
                    out.setdefault(fn, msg)
                break
    return out


def norm_proto(t):
    """A prototype as (return tokens, name, parameter token tuples), parameter names dropped."""
    t = " ".join(t.replace("extern", " ").split()).rstrip(";").strip()
    m = re.match(r"^(.*?)\b(\w+)\s*\((.*)\)\s*$", t)
    if not m:
        return t
    params = []
    inner = m.group(3).strip()
    if inner and inner != "void":
        for p in pn.split_params(inner):
            params.append(" ".join(p.split()) if "(" in p else tuple(strip_name(p)))
    ret = tuple(x for x in re.findall(r"[A-Za-z_]\w*|\*", m.group(1)) if x != "extern")
    return ret, m.group(2), tuple(params)


def convert_caller(idx, hdrs, plan, inj):
    """Rewrite one caller with the includes where the externs stood; when that cannot be made to compile,
    again with them just before the file's first need.  Returns (state, externs removed, report rows)."""
    first = _convert(idx, hdrs, plan, inj, False)
    if first[0] != "failed":
        return first
    return _convert(idx, hdrs, plan, inj, True)


def _convert(idx, hdrs, plan, inj, late):
    f = plan.file
    orig = plan.raw
    owners = sorted({r[3].file for r in plan.removals})
    rows = []
    excluded = set()

    seen_rows = set()

    def row(r, why):
        if r[2] in seen_rows:
            return
        seen_rows.add(r[2])
        same = norm_proto(r[4]) == norm_proto(r[3].proto)
        rows.append((rel(f), r[2], r[4], r[3].proto, "same type" if same else "types differ", why))

    extra = set()

    def build():
        return apply_plan(idx, hdrs, plan, skip_owners=sorted(excluded), inject=inj, extra=sorted(extra),
                          late=late)[0]

    # 1. compile errors name the callers' disagreements: drop the owner groups they touch
    for _ in range(40):
        text = build()
        write(f, text)
        errs = compile_errors(f)
        if not errs:
            break
        need = set()
        for _l, msg, _w in errs:
            m = re.search(r"undefined identifier '(\w+)'", msg)
            if not m:
                continue
            nm = m.group(1)
            if nm in idx.tindex.base:
                need.add(nm)
            elif nm in idx.tindex.typedef_in:
                h = pick_header(idx.tindex.typedef_in[nm], f, include_closure(f))
                if h:
                    need.add("inc:" + os.path.abspath(h).replace(os.sep, "/"))
            elif nm in idx.tindex.types.alias and len(idx.tindex.types.alias[nm]) == 1 and \
                    re.fullmatch(r"(struct|union) \w+", next(iter(idx.tindex.types.alias[nm]))) and \
                    next(iter(idx.tindex.types.alias[nm])) not in idx.tindex.types.anon:
                need.add("fwd:" + nm)           # an opaque struct typedef that only .c files spell
        need -= extra
        if need and inj:
            extra |= need          # a types header the include brings needs a base typedef or another header first
            continue
        # a type defined twice (the caller and a header, or two headers): the groups whose headers define it go
        redef = {}
        for _l, msg, _w in errs:
            m = re.search(r"identifier '(\w+)' redeclared|tag '(\w+)' redefined|redefinition of '(\w+)'", msg)
            if m:
                redef.setdefault(m.group(1) or m.group(2) or m.group(3), msg)
        if redef:
            own_names = set(visible_names(f, raw=orig))
            for e in extra:
                if e.startswith("inc:"):
                    ep = os.path.normpath(e[4:])
                    own_names |= {n for n, hs in idx.tindex.typedef_in.items() if any(os.path.normpath(h) == ep for h in hs)}
            order = sorted((of for of in owners if of not in excluded),
                           key=lambda of: min(r[0] for r in plan.removals if r[3].file == of))
            dropped = False
            for x, msg in redef.items():
                defining = []
                for of in order:
                    names = set()
                    for h in include_closure(hdrs[of]["path"]) | {os.path.normpath(hdrs[of]["path"])}:
                        h = os.path.normpath(h)
                        if any(os.path.normpath(c) == h for c in idx.tindex.typedef_in.get(x, ())) or \
                           any(os.path.normpath(c) == h for k, v in idx.tindex.tag_in.items() if k[1] == x for c in v):
                            names.add(h)
                    if names:
                        defining.append(of)
                drop = defining if x in own_names else defining[1:]
                for of in drop:
                    if of in excluded:
                        continue
                    excluded.add(of)
                    dropped = True
                    for r in plan.removals:
                        if r[3].file == of:
                            row(r, "type %s is defined twice (%s)" % (x, "caller and header" if x in own_names else "two headers"))
            if dropped:
                continue
        # an error inside a header belongs to the owner group whose include brought that header in last
        hdr_hits = set()
        for _l, msg, where in errs:
            if where is None or not where.endswith(".h"):
                continue
            tail = os.path.normpath(where)
            order = [of for of in owners if of not in excluded]
            hit = [of for of in order if any(os.path.normpath(c).endswith(os.path.basename(tail))
                                             for c in include_closure(hdrs[of]["path"]) | {hdrs[of]["path"]})]
            if hit:
                pos = {r[3].file: r[0] for r in sorted(plan.removals, key=lambda r: -r[0])}
                hdr_hits.add((max(hit, key=lambda of: pos.get(of, 0)), msg))
        if hdr_hits:
            for of, msg in sorted(hdr_hits):
                if of in excluded:
                    continue
                excluded.add(of)
                for r in plan.removals:
                    if r[3].file == of:
                        row(r, "header conflict: " + msg[:100])
            continue
        funcs = [r[2] for r in plan.removals if r[3].file not in excluded]
        cul = culprits_of(text, errs, funcs)
        cul = {k: v for k, v in cul.items()}
        if not cul:
            # an error that no function explains: give the whole file back
            write(f, orig)
            for r in plan.removals:
                row(r, "compile error: " + errs[0][1][:120])
            return "failed", 0, rows
        for r in plan.removals:
            if r[2] in cul and r[3].file not in excluded:
                excluded.add(r[3].file)
        for r in plan.removals:
            if r[2] in cul:
                row(r, "compile error: " + cul[r[2]][:120])
    else:
        write(f, orig)
        return "failed", 0, rows
    if len(excluded) == len(owners):
        write(f, orig)
        return "failed", 0, rows
    # 2. the compiled file must be EXACT; when it is not, find the owner group that changed the bytes
    ok, _m = verify_file(f)
    if not ok:
        good = []
        for of in owners:
            if of in excluded:
                continue
            t = apply_plan(idx, hdrs, plan, skip_owners=[o for o in owners if o != of], inject=inj,
                           extra=sorted(extra), late=late)[0]
            write(f, t)
            if verify_file(f)[0]:
                good.append(of)
            else:
                excluded.add(of)
                for r in plan.removals:
                    if r[3].file == of:
                        row(r, "bytes differ")
        if not good:
            write(f, orig)
            return "failed", 0, rows
        write(f, build())
        if not verify_file(f)[0]:
            write(f, orig)
            return "failed", 0, rows
    n = sum(1 for r in plan.removals if r[3].file not in excluded)
    return ("ok" if not excluded else "partial"), n, rows


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--region", action="append")
    ap.add_argument("--files", help="file with repo paths: only these callers are rewritten")
    ap.add_argument("--report", help="TSV of cases where the definition's prototype changed the bytes")
    ap.add_argument("--keep", help="TSV of externs that stay (no definition, ambiguous, header lacks it)")
    ap.add_argument("--skipped", help="TSV of functions left out of their header")
    ap.add_argument("--jobs", type=int, default=4)
    ap.add_argument("--no-inject", action="store_true", help="do not add missing base typedefs")
    a = ap.parse_args()
    if not (a.dry_run or a.apply):
        ap.error("give --dry-run or --apply")
    files = sorted(ph.files_under([GAME]))
    idx = Index(files)
    regions = set(a.region) if a.region else None
    hdrs = build_headers(idx)          # headers of every region: a caller may include any of them
    only = None
    if a.files:
        only = {os.path.normpath(os.path.join(ROOT, l.strip())) for l in open(a.files) if l.strip()}

    nhdr = sum(1 for i in hdrs.values() if i["ok"])
    nfun = sum(len(i["ok"]) for i in hdrs.values())
    nskip = sum(len(i["skipped"]) for i in hdrs.values())
    existing = sum(1 for i in hdrs.values() if i["ok"] and os.path.exists(i["path"]))
    print("source files with public functions: %d" % nhdr)
    print("public functions in headers: %d  (left out for an unwritable type: %d)" % (nfun, nskip))
    print("headers that already exist (merged): %d" % existing)
    reasons = collections.Counter()
    for i in hdrs.values():
        for d, why in i["skipped"]:
            reasons[re.sub(r"\b(type|enum|struct|union) \w+", r"\1 X", why)] += 1
    for why, n in reasons.most_common(8):
        print("   %5d  %s" % (n, why))

    callers = [f for f in files if f.endswith(".c") and (regions is None or region_of(f) in regions)
               and (only is None or os.path.normpath(f) in only)]
    plans = {}
    totals = collections.Counter()
    keeps = collections.Counter()
    keep_rows = []
    for f in callers:
        plan = plan_caller(idx, hdrs, f)
        plans[f] = plan
        if plan.removals:
            totals["files"] += 1
            totals["externs removed"] += len(plan.removals)
            totals["includes added"] += len({r[3].file for r in plan.removals})
        for name, why in plan.keep:
            keeps[re.sub(r"\(.*", "", why).strip()] += 1
            keep_rows.append((rel(f), name, why))
        if a.dry_run and (a.region or only) and plan.removals:
            print("%s: remove %d externs, include %s" % (rel(f), len(plan.removals),
                  ", ".join(sorted({os.path.basename(r[3].file)[:-2] + ".h" for r in plan.removals}))))
    print("callers rewritten: %d files, %d externs removed, %d includes added"
          % (totals["files"], totals["externs removed"], totals["includes added"]))
    print("externs kept: %d" % sum(keeps.values()))
    for why, n in keeps.most_common():
        print("   %6d  %s" % (n, why))
    if a.keep:
        with open(a.keep, "w", newline="\n") as fh:
            for r in sorted(keep_rows):
                fh.write("\t".join(r) + "\n")
    if a.skipped:
        with open(a.skipped, "w", newline="\n") as fh:
            for f, i in sorted(hdrs.items()):
                for d, why in i["skipped"]:
                    fh.write("%s\t%s\t%s\n" % (rel(f), d.name, why))
    if a.dry_run:
        return

    wrote = 0
    need = {f for f, i in hdrs.items() if i["ok"] and regions and region_of(f) in regions}
    for plan in plans.values():
        need.update(r[3].file for r in plan.removals)
    for f in sorted(need):
        i = hdrs[f]
        if not i["ok"]:
            continue
        hp = i["path"]
        ex = open(hp, encoding="latin1", newline="").read() if os.path.exists(hp) else None
        text = header_text(f, i, ex)
        if ex != text:
            write(hp, text)
            wrote += 1
    print("headers written: %d" % wrote)
    closure = set()
    for f in need:
        if hdrs[f]["ok"]:
            closure.add(os.path.normpath(hdrs[f]["path"]))
            closure |= include_closure(hdrs[f]["path"])
    fixed = sum(1 for h in sorted(closure) if h.endswith(".h") and qualify_includes(h))
    print("headers whose bare sibling includes were qualified: %d" % fixed)

    report, bad = [], []

    def work(f):
        plan = plans[f]
        if not plan.removals:
            return f, None
        return f, convert_caller(idx, hdrs, plan, not a.no_inject)

    with concurrent.futures.ThreadPoolExecutor(max_workers=a.jobs) as pool:
        for f, res in pool.map(work, callers):
            if res is None:
                continue
            st, n, rows = res
            report += rows
            print("%-8s %s  (%d externs removed)" % (st, rel(f), n), flush=True)
            if st != "ok":
                bad.append(f)
    if a.report:
        with open(a.report, "w", newline="\n") as fh:
            fh.write("file\tfunction\told prototype\tdefinition prototype\tprototypes\twhy\n")
            for r in report:
                fh.write("\t".join(r) + "\n")
    print("callers not fully converted: %d" % len(bad))


if __name__ == "__main__":
    main()
