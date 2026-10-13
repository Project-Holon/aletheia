#!/usr/bin/env python3
"""Find placeholder sources: functions filed as matched whose source holds no real code.

A manifest entry is EXACT or EXACT* when match.py's comparison passes.  An `asm`
function with an empty body compiles to zero bytes, and a comparison over zero
bytes passes: run_one() compares len(compiled) bytes, so the verdict is EXACT, and
because the listing extent differs from the compiled size (0) it becomes EXACT*.
Such an entry holds the address without reproducing any of its code.  This module
finds those sources so the figures (tools/ovstats.py, tools/coveragemap.py,
tools/worklist.py) count them as their own class, `placeholder`, never as matched.

Rules.  A function definition is a placeholder when one of these holds for its body
(comments, strings and preprocessor lines are blanked first):

  P1 empty-asm      an `asm` function (or a C function whose whole body is one
                    `asm { }` / `__asm { }` block) whose body holds no statement
                    at all.  It compiles to no instructions.
  P2 no-insn-asm    an asm body whose statements are all directives that emit no
                    bytes (nofralloc, fralloc, frfree, entry, machine, .thumb,
                    .arm, .code, .text, .section, .global/.globl, .type, .size,
                    .func/.endfunc, .fnstart/.fnend, function labels).  It
                    compiles to no instructions.
  P3 padding-asm    an asm body whose byte-emitting statements are all padding:
                    `nop`, `mov r8, r8`, `.align`/`.balign`/`.p2align`,
                    `.space`/`.skip`/`.zero`/`.fill`, or a data directive
                    (`.word`/`.long`/`.4byte`/`.short`/`.hword`/`.2byte`/
                    `.byte`/`dcd`/`dcw`/`dcb`/`opword`) whose values are all 0.
                    It only occupies the address.

What is NOT a placeholder:

  * an empty C body (`void f(void) {}`): mwcc emits `bx lr` for it, a real
    instruction that matches a real empty function;
  * an asm function with real instructions, even when it stands in for C that is
    not written yet (docs/restructure/STANDINS.md): it reproduces the bytes;
  * a function the file does not define (a unit member reached as a label inside
    another function's bytes): it is never reclassified.

Claims checked: an entry's own name and address, every member its `functions`
list names (game_unit, sdk_unit), and, in tools/worklist.py, the sibling
definitions find_unit_member_addrs() credits to a game_unit (source_rule()).

Both sources are checked: the src/matched file the manifest entry names, and the
function's definition in src/game/<region>/ (the final tree; found by the address
in its name, or by its name).  Either one being a placeholder makes the entry a
placeholder; the reason says which (`matched:P1`, `game:P3`, ...).

usage
  python tools/placeholders.py              list every flagged entry
  python tools/placeholders.py --file X.c   classify every definition in one file
  python tools/placeholders.py --census     statement census of all asm bodies
"""
import argparse
import collections
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import stampcache  # noqa: E402

CLASS = "placeholder"

_MASK = re.compile(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'|'
                   r'^[ \t]*#(?:[^\n]*\\\n)*[^\n]*', re.S | re.M)
ADDR_NAME = re.compile(r"(?:func|sub)_([0-9A-Fa-f]{8})$")
IDENT_CALL = re.compile(r"([A-Za-z_]\w*)\s*\($")
INNER_ASM = re.compile(r"^\s*(?:asm|__asm|__asm__)\s*(?:volatile\s*)?\{(.*)\}\s*;?\s*$", re.S)
INCLUDE = re.compile(r"^[ \t]*#[ \t]*include\b", re.M)
LABEL = re.compile(r"^[A-Za-z_.@$][\w.@$]*\s*:")

# directives that emit no bytes (rule P2)
SILENT = {"nofralloc", "fralloc", "frfree", "entry", "machine", ".thumb", ".arm", ".code", ".code16",
          ".code32", ".text", ".section", ".global", ".globl", ".type", ".size", ".func", ".endfunc",
          ".fnstart", ".fnend", ".thumb_func", ".force_thumb", ".syntax", ".extern", ".local",
          ".weak", ".cantunwind"}
# padding that emits bytes but no code (rule P3)
PAD_ALIGN = {".align", ".balign", ".p2align", ".space", ".skip", ".zero", ".fill"}
PAD_DATA = {".word", ".long", ".4byte", ".int", ".short", ".hword", ".2byte", ".half", ".byte",
            "dcd", "dcw", "dcb", "dcdu", "dcwu", "opword"}


def mask(text):
    return _MASK.sub(lambda m: re.sub(r"[^\n]", " ", m.group(0)), text)


def _is_zero(tok):
    tok = tok.strip()
    try:
        return int(tok, 0) == 0
    except ValueError:
        return False


def asm_statements(body):
    """Statements of an asm body (masked text), labels removed."""
    out = []
    for line in body.replace(";", "\n").split("\n"):
        s = line.strip()
        while True:
            m = LABEL.match(s)
            if not m:
                break
            s = s[m.end():].strip()
        if s:
            out.append(s)
    return out


def classify_asm(body):
    """Rule name (P1/P2/P3) when an asm body is a placeholder, else None."""
    stmts = asm_statements(body)
    if not stmts:
        return "P1"
    emitting = []
    for s in stmts:
        op = s.split(None, 1)[0].lower()
        if op in SILENT:
            continue
        emitting.append(s)
    if not emitting:
        return "P2"
    for s in emitting:
        parts = s.split(None, 1)
        op = parts[0].lower()
        args = parts[1] if len(parts) > 1 else ""
        if op == "nop" and not args:
            continue
        if op == "mov" and re.sub(r"\s", "", args).lower() == "r8,r8":
            continue
        if op in PAD_ALIGN:
            continue
        if op in PAD_DATA and args and all(_is_zero(a) for a in args.split(",")):
            continue
        return None
    return "P3"


def definitions(text):
    """[(name, is_asm, body_masked, body_has_include)] for the top-level function definitions."""
    m = mask(text)
    out = []
    depth = 0
    i = 0
    n = len(m)
    last_end = 0          # end of the previous top-level construct
    while i < n:
        c = m[i]
        if c == "{":
            if depth == 0:
                start = i
                header = m[last_end:i]
                if re.fullmatch(r"\s*(?:extern\s*|namespace\s*\w*\s*)", header):
                    # extern "C" { ... } / namespace X { ... }: step inside
                    i += 1
                    last_end = i
                    continue
                # body: matching brace
                d = 0
                j = i
                while j < n:
                    if m[j] == "{":
                        d += 1
                    elif m[j] == "}":
                        d -= 1
                        if d == 0:
                            break
                    j += 1
                body = m[start + 1:j]
                h = header.strip()
                if "(" in h and "=" not in h.split("(", 1)[0] and not re.search(r"\b(?:struct|union|enum)\s*\w*\s*$", h):
                    # function name: the identifier before the first top-level '(' group
                    # (old-style K&R parameter declarations may follow the ')')
                    k = h.find("(")
                    mm = IDENT_CALL.search(h[:k + 1])
                    if mm and mm.group(1) not in ("if", "while", "for", "switch", "sizeof"):
                        name = mm.group(1)
                        words = set(re.findall(r"[A-Za-z_]\w*", h[:mm.start()]))
                        is_asm = bool(words & {"asm", "__asm", "__asm__"})
                        if not is_asm:
                            im = INNER_ASM.match(body)
                            if im:
                                is_asm = True
                                body = im.group(1)
                        raw = text[start + 1:j]
                        out.append((name, is_asm, body, bool(INCLUDE.search(raw))))
                i = j + 1
                last_end = i
                continue
        elif c == ";" and depth == 0:
            last_end = i + 1
        i += 1
    return out


def classify_file(path):
    """{function name: rule or None} for every definition in one source file."""
    try:
        with open(path, encoding="latin1") as fh:
            text = fh.read()
    except OSError:
        return {}
    res = {}
    for name, is_asm, body, included in definitions(text):
        # an #include inside the body brings in generated words (tools/gendata.py
        # writes build/gen/*.inc from the user's ROM): bytes, not an empty body
        rule = classify_asm(body) if is_asm and not included else None
        # a name defined twice (should not happen) keeps the placeholder verdict
        if name not in res or rule:
            res[name] = rule
    return res


def _sources(top, skip_underscore=False):
    """Source files under top; src/game's scratch files start with '_' (gamecheck skips them)."""
    return [t for t in stampcache.walk_files(top, (".c", ".cpp"))
            if not (skip_underscore and os.path.basename(t[0]).startswith("_"))]


_STATE = {}


def _matched_index():
    if "matched" not in _STATE:
        files = (_sources(os.path.join(ROOT, "src", "matched"))
                 + _sources(os.path.join(ROOT, "src", "calib")))
        vals = stampcache.Cache("placeholders_matched", owners=[__file__]).sync(
            files, classify_file, key=lambda t: os.path.relpath(t[1], ROOT).replace(os.sep, "/"))
        _STATE["matched"] = vals
    return _STATE["matched"]


def _game_index():
    """{region: {address or name: rule or None}} for src/game."""
    if "game" not in _STATE:
        files = _sources(os.path.join(ROOT, "src", "game"), skip_underscore=True)
        vals = stampcache.Cache("placeholders_game", owners=[__file__]).sync(
            files, classify_file, key=lambda t: t[0])
        idx = {}
        for rel, defs in vals.items():
            region = rel.split("/", 1)[0]
            r = idx.setdefault(region, {})
            for name, rule in defs.items():
                am = ADDR_NAME.search(name)
                for key in ((int(am.group(1), 16),) if am else ()) + (name,):
                    if key not in r or rule:
                        r[key] = (rule, "src/game/" + rel)
        _STATE["game"] = idx
    return _STATE["game"]


def entry_targets(ent):
    """[(name, address or None)] an entry claims: its own name, and unit members."""
    out = []
    try:
        own = int(str(ent.get("address")), 16) if ent.get("address") else None
    except ValueError:
        own = None
    out.append((ent.get("name", ""), own))
    if str(ent.get("kind", "")).endswith("_unit"):
        for mem in ent.get("functions", []) or []:
            if isinstance(mem, str) and mem:
                am = ADDR_NAME.search(mem)
                out.append((mem, int(am.group(1), 16) if am else None))
    return out


def entry_reason(ent):
    """[(name, address, reason or None)] for every claim of one manifest entry."""
    midx = _matched_index()
    gidx = _game_index().get(str(ent.get("region", "")), {})
    src = str(ent.get("source", "")).replace("\\", "/")
    defs = midx.get(src)
    if defs is None:
        # a source outside src/matched and src/calib (a test file): read it directly
        path = src if os.path.isabs(src) else os.path.join(ROOT, src)
        defs = classify_file(path) if os.path.isfile(path) else {}
    out = []
    for name, addr in entry_targets(ent):
        reasons = []
        rule = defs.get(name)
        if rule:
            reasons.append("matched:%s" % rule)
        g = gidx.get(addr) if addr is not None else None
        if g is None:
            g = gidx.get(name)
        if g is not None and g[0]:
            reasons.append("game:%s (%s)" % (g[0], g[1]))
        out.append((name, addr, "; ".join(reasons) or None))
    return out


def source_rule(source, addr):
    """Rule for the definition of the function at `addr` (func_/sub_XXXXXXXX) in a
    src/matched source, or None."""
    src = str(source).replace("\\", "/")
    defs = _matched_index().get(src)
    if defs is None:
        path = src if os.path.isabs(src) else os.path.join(ROOT, src)
        defs = classify_file(path) if os.path.isfile(path) else {}
    for name, rule in defs.items():
        am = ADDR_NAME.search(name)
        if am and int(am.group(1), 16) == addr and rule:
            return rule
    return None


MATCHED = ("EXACT", "EXACT*")


def scan(entries):
    """{(region, key): (name, source, status, reason)} for the placeholder claims.

    Only entries whose status counts as matched (EXACT, EXACT*) are read.  Each claim
    is keyed twice, by (region, address) when it has one and by (region, name), so
    the figure code can test either.  A key is flagged only when every matched claim
    on it is a placeholder: a real EXACT entry for the same function keeps it matched."""
    claims = {}
    for ent in entries:
        st = str(ent.get("status", ""))
        if st not in MATCHED:
            continue
        region = ent.get("region")
        for name, addr, reason in entry_reason(ent):
            val = (name, ent.get("source", ""), st, reason)
            keys = {(region, name)}
            if addr is not None:
                keys.add((region, addr))
            for k in keys:
                claims.setdefault(k, []).append(val)
    return {k: v[0] for k, v in claims.items() if all(c[3] for c in v)}


def manifest_entries():
    import match
    return match.load_manifest_entries()


def flagged():
    """The scan() result over the whole manifest, computed once per run."""
    if "flagged" not in _STATE:
        _STATE["flagged"] = scan(manifest_entries())
    return _STATE["flagged"]


def is_placeholder(region, key):
    """True when (region, address or name) is a placeholder claim of a matched entry."""
    return (region, key) in flagged()


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--file", action="append", help="classify every definition in a file")
    ap.add_argument("--census", action="store_true", help="first-word census of asm bodies")
    a = ap.parse_args(argv)
    if a.file:
        for p in a.file:
            for name, rule in classify_file(p).items():
                print("%-40s %s" % (name, rule or "code"))
        return 0
    if a.census:
        c = collections.Counter()
        for t in _sources(os.path.join(ROOT, "src")):
            try:
                text = open(t[1], encoding="latin1").read()
            except OSError:
                continue
            for _name, is_asm, body, _inc in definitions(text):
                if not is_asm:
                    continue
                for s in asm_statements(body):
                    c[s.split(None, 1)[0].lower()] += 1
        for k, v in sorted(c.items(), key=lambda kv: -kv[1]):
            print("%8d %s" % (v, k))
        return 0
    seen = set()
    rows = []
    for (region, key), (name, src, st, reason) in flagged().items():
        if (region, name) in seen:
            continue
        seen.add((region, name))
        rows.append((str(region), name, st, src, reason))
    for r in sorted(rows):
        print("%-22s %-28s %-6s %s  [%s]" % r)
    print("%d placeholder claim(s)" % len(rows))
    return 0


if __name__ == "__main__":
    sys.exit(main())
