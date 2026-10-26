#!/usr/bin/env python3
"""guardaudit.py: every __MWERKS__ guard in src/game must be archived.

Lists each `#if(n)def __MWERKS__` / `#if defined(__MWERKS__)` block (file, line, kind guess,
enclosing function or the names used in it) and matches it to a row of docs/ORIGINAL_BUGS.tsv
(same file, and the row's function is the enclosing function or is named in the block, or the
row's line lies in the block).  Reports guards with no row and rows with no guard.  A guard that
is not an original-bug guard (compiler switch, inline asm choice) is listed in ALLOWLIST below
with the reason, or gets a `kind: other` row in the TSV.

    python tools/guardaudit.py            report; exit 1 when something is unmatched
    python tools/guardaudit.py --list     print every guard with its kind and matching rows
    python tools/guardaudit.py --tsv      print draft ORIGINAL_BUGS.tsv rows for unmatched guards
    python tools/guardaudit.py --apply    append those rows to docs/ORIGINAL_BUGS.tsv (claim it first)

Kinds: return (a `return` in the block), prototype (declarations at file level), call (a call
in a function body), other.
"""
import argparse
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, "src", "game")
TSV = os.path.join(ROOT, "docs", "ORIGINAL_BUGS.tsv")

# (file relative to the repo root, function or declared name or "*") -> reason.
# Guards that are not original-bug guards.
ALLOWLIST = {
    ("src/game/types.h", "BW_OFFSETOF"):
        "definition guard: the same offset value on both builds, no behaviour difference",
}

# Rows for guards that declare nothing: (file, enclosing function or "*") -> (kind, DS, host, host same?).
MANUAL = {
    ("src/game/ov020/event_mapchange.c", "EVENT_MAPCHANGE_CreateByMode"):
        ("A", "an unknown mode falls off the end; r0 is not set", "returns 0", "no"),
    ("src/game/ov052/field_gimmick_bsubway.c", "FIELD_GIMMICK_BSUBWAY_StartTrain"):
        ("C", "stores the r0 that FLDEFF_BTRAIN_Start leaves (the header declares it void) in train->effect",
         "calls without storing; train->effect is not set", "no"),
    ("src/game/ov070/itemmenu.c", "ITEMMENU_Init"):
        ("D", "MYITEM_SAVEDATA_CompactAllPockets gets the bag filter as a second argument; the definition takes one",
         "calls with the definition's argument", "yes"),
    ("src/game/ov071/monolith_tool.c", "MONOLITH_TOOL_InitPalAnm"):
        ("A", "falls off the end; r0 is what the last PALANM_SetAutoTransfer call left", "returns 0", "no"),
    ("src/game/ov110/pms_input.c", "PMS_INPUT_Create"):
        ("D", "calls the PMSI_PARAM_GetUiInputMode thunk with the param; it jumps to UI_GetInputMode, which takes none",
         "calls UI_GetInputMode directly", "yes"),
    ("src/game/ov110/pms_input.c", "PMS_INPUT_UiSwitchMenu"):
        ("A", "falls off the end; r0 is what PMS_INPUT_VIEW_UpdateEditFocus left", "returns 0", "no"),
    ("src/game/ov110/pms_input.c", "PMS_INPUT_UiSwitchBrowse"):
        ("A", "falls off the end; r0 is what PMS_INPUT_VIEW_UpdateCategoryFocus left", "returns 0", "no"),
    ("src/game/ov110/pms_input.c", "PMS_INPUT_UiSwitchWordList"):
        ("A", "falls off the end; r0 is what the word list view call left", "returns 0", "no"),
    ("src/game/ov115/wifilogin_disp.c", "WIFILOGIN_DISP_StepCheckAccount"):
        ("D", "APP_ENV_IsWirelessAvailable gets the work pointer; the definition takes no argument",
         "calls without the argument", "yes"),
    ("src/game/ov121/mystery.c", "MYSTERY_CreateReceivedMon"):
        ("D", "POKE_TOOL_Create gets a 0 after the id; it is the high word of the 64-bit id",
         "calls with the definition's arguments", "yes"),
    ("src/game/ov121/mystery_album.c", "MYSTERY_ALBUM_CreateAlbumView"):
        ("D", "POKE_TOOL_Create gets a 0 after the id; it is the high word of the 64-bit id",
         "calls with the definition's arguments", "yes"),
    ("src/game/ov121/mystery_net.c", "MYSTERY_NET_BuildPokemonFromRecord"):
        ("other", "empty guard left behind (both branches are empty)", "none; remove the guard", "yes"),
    ("src/game/ov123/gsync_message.c", "GSYNC_MESSAGE_PrintId"):
        ("C", "returns the r0 that MSGDATA_ReadString leaves (the header declares it void)", "returns 0", "no"),
    ("src/game/ov129/wf2dmap_scene.c", "WF2DMAP_SCENE_Draw"):
        ("other", "empty guard left behind (both branches are empty)", "none; remove the guard", "yes"),
    ("src/game/ov183/br_codein.c", "BR_CODEIN_BATTLE_REC_SET_DATA"):
        ("D", "BATTLE_REC_SetData gets the save control as a fourth argument; the definition takes three",
         "macro drops the argument", "yes"),
    ("src/game/ov195/shinka_demo.c", "SHINKA_DEMO_YESNO_MENU_CREATE"):
        ("D", "YESNO_MENU_Create gets one more argument than the definition takes", "macro drops it", "yes"),
    ("src/game/ov195/shinka_demo.c", "SHINKA_DEMO_SETUP_SUB_BG_ARG"):
        ("D", "SHINKA_DEMO_GRAPHIC_SetupSubBg gets an argument; the definition takes none", "macro drops it", "yes"),
    ("src/game/ov172/ctvt_camera.c", "CTVT_IS_RUN_ON_TWL"):
        ("D", "OS_IsRunOnTwl gets an int argument; the definition takes none", "macro drops it", "yes"),
}
# Guards that only add a header include on the host: kind other.
INCLUDE_ONLY = "host includes a header that the DS build declares locally or gets from an earlier include"

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

DIRECTIVE = re.compile(r"^\s*#\s*(if|ifdef|ifndef|elif|else|endif)\b(.*)$")
MW = re.compile(r"__MWERKS__")
IDENT = re.compile(r"[A-Za-z_]\w*")
KEYWORDS = {"if", "while", "for", "switch", "return", "sizeof", "else", "do", "extern", "static", "struct",
            "const", "void", "int", "char", "short", "long", "unsigned", "signed", "union", "enum",
            "typedef", "defined", "u8", "u16", "u32", "u64", "s8", "s16", "s32", "s64", "BOOL", "volatile",
            "case", "break", "goto", "default", "inline", "register"}


def blank_comments(text):
    """Replace comments and string bodies with spaces, keeping the line structure."""
    out = []
    i, n = 0, len(text)
    while i < n:
        c = text[i]
        if text.startswith("/*", i):
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
            out.append("".join(ch if ch == "\n" else " " for ch in text[i:j]))
            i = j
        elif text.startswith("//", i):
            j = text.find("\n", i)
            j = n if j < 0 else j
            out.append(" " * (j - i))
            i = j
        elif c in "\"'":
            j = i + 1
            while j < n and text[j] != c and text[j] != "\n":
                j += 2 if text[j] == "\\" else 1
            out.append(c + " " * max(0, j - i - 1) + (c if j < n and text[j] == c else ""))
            i = j + 1
        else:
            out.append(c)
            i += 1
    return "".join(out)


def mw_sense(expr):
    """'ds' when the true branch is the DS branch, 'host' when it is the host branch,
    'mixed' when other terms are involved, None when __MWERKS__ is not tested."""
    r = expr.strip()
    if not MW.search(r):
        return None
    if re.fullmatch(r"__MWERKS__|defined\s*\(\s*__MWERKS__\s*\)|defined\s+__MWERKS__", r):
        return "ds"
    if re.fullmatch(r"!\s*defined\s*\(\s*__MWERKS__\s*\)|!\s*defined\s+__MWERKS__", r):
        return "host"
    return "mixed"


def function_map(clean):
    """For each line, the name of the function whose body contains it (None at file level)."""
    func_at = [None] * len(clean)
    depth = 0
    cur = None
    head = ""
    for i, ln in enumerate(clean):
        if DIRECTIVE.match(ln):
            func_at[i] = cur
            continue
        func_at[i] = cur
        for ch_i, ch in enumerate(ln):
            if ch == "{":
                if depth == 0:
                    pre = (head + " " + ln[:ch_i])[-400:]
                    m = re.search(r"(\w+)\s*\([^;{}]*\)\s*$", pre.strip())
                    cur = m.group(1) if m and m.group(1) not in KEYWORDS else None
                    func_at[i] = cur or func_at[i]
                depth += 1
            elif ch == "}":
                depth -= 1
                if depth <= 0:
                    depth = 0
                    cur = None
                    head = ""
            elif ch == ";" and depth == 0:
                head = ""
        if depth == 0:
            head += " " + ln
    return func_at


def declared_names(cbody):
    """Function names declared or renamed in a block: the name before the first '(' of each
    statement, and the first name after each #define / #undef."""
    names = []
    code = []
    for ln in cbody:
        m = re.match(r"\s*#\s*(?:define|undef)\s+(\w+)", ln)
        if m:
            names.append(m.group(1))
        elif not ln.lstrip().startswith("#"):
            code.append(ln)
    for st in " ".join(code).split(";"):
        m = re.search(r"(\w+)\s*\(", st)
        if m and m.group(1) not in KEYWORDS and m.group(1) not in names:
            names.append(m.group(1))
    return names


def scan_file(path):
    with open(path, encoding="utf-8", errors="replace", newline="") as f:
        raw = f.read()
    lines = raw.replace("\r\n", "\n").split("\n")
    clean = blank_comments("\n".join(lines)).split("\n")
    func_at = function_map(clean)
    stack = []
    out = []
    for i, ln in enumerate(clean):
        m = DIRECTIVE.match(ln)
        if not m:
            continue
        d, rest = m.group(1), m.group(2)
        if d in ("if", "ifdef", "ifndef"):
            if d == "if":
                expr = rest
            elif d == "ifdef":
                expr = "defined(%s)" % rest.strip()
            else:
                expr = "!defined(%s)" % rest.strip()
            stack.append([i, mw_sense(expr)])
        elif d == "endif" and stack:
            s, sense = stack.pop()
            if sense is None:
                continue
            cbody = clean[s + 1:i]
            names = []
            for x in IDENT.findall("\n".join(cbody)):
                if x not in KEYWORDS and x not in names:
                    names.append(x)
            out.append({"start": s + 1, "end": i + 1, "func": func_at[s], "sense": sense,
                        "names": names, "cbody": cbody, "decls": declared_names(cbody),
                        "body": lines[s + 1:i]})
    return out


def branches(cbody):
    """Split a guard body at its own #else / #elif (nested #if blocks stay whole); drop directives.
    Continuation lines of a #define are directives too."""
    out = [[]]
    depth = 0
    cont = False
    for ln in cbody:
        if cont:
            cont = ln.rstrip().endswith("\\")
            continue
        m = DIRECTIVE.match(ln)
        if m:
            d = m.group(1)
            if d in ("if", "ifdef", "ifndef"):
                depth += 1
            elif d == "endif":
                depth -= 1
            elif d in ("else", "elif") and depth == 0:
                out.append([])
        elif ln.lstrip().startswith("#"):
            cont = ln.rstrip().endswith("\\")
        else:
            out[-1].append(ln)
    return [chr(10).join(b) for b in out]


def split_problem(g):
    """A reason when a branch of the guard is not made of whole statements, else None."""
    for b in branches(g["cbody"]):
        code = b.strip()
        if not code:
            continue
        if code.count("{") != code.count("}"):
            return "unbalanced braces"
        if code.count("(") != code.count(")"):
            return "unbalanced parentheses"
        if code[-1] not in ";}":
            return "branch ends inside a statement"
    return None


def kind_guess(g):
    text = "\n".join(g["cbody"])
    if re.search(r"\breturn\b", text):
        return "return"
    if g["func"] is None:
        return "prototype"
    if re.search(r"\w\s*\(", text):
        return "call"
    return "other"


def load_rows():
    rows = []
    with open(TSV, encoding="utf-8") as f:
        hdr = f.readline().rstrip("\n").split("\t")
        for n, ln in enumerate(f, 2):
            ln = ln.rstrip("\n")
            if not ln.strip():
                continue
            c = ln.split("\t")
            c += [""] * (len(hdr) - len(c))
            file_, _, line = c[1].partition(":")
            rows.append({"n": n, "kind": c[0], "file": file_.strip(),
                         "line": int(line) if line.strip().isdigit() else None,
                         "func": c[2].strip(), "cols": c})
    return rows


def all_guards():
    res = []
    for dp, dn, fn in os.walk(SRC):
        dn.sort()
        for f in sorted(fn):
            if not f.endswith((".c", ".h")):
                continue
            p = os.path.join(dp, f)
            with open(p, encoding="utf-8", errors="replace") as fh:
                if "__MWERKS__" not in fh.read():
                    continue
            rel = os.path.relpath(p, ROOT).replace(os.sep, "/")
            for g in scan_file(p):
                g["file"] = rel
                g["kind"] = kind_guess(g)
                res.append(g)
    return res


def row_matches(g, r):
    if r["file"] != g["file"]:
        return False
    if r["line"] is not None and g["start"] <= r["line"] <= g["end"]:
        return True
    if r["func"] == "(includes)":
        return not g["decls"] and g["func"] is None and g["sense"] == "host"
    words = set(IDENT.findall(r["func"] + " " + r["cols"][3] + " " + r["cols"][4]))
    fn = r["func"]
    if fn and (fn == g["func"] or fn in g["names"]):
        return True
    return any(d in words for d in g["decls"])


def protocheck_tables():
    """(host definitions, DS declarations per file) from tools/protocheck.py."""
    import protocheck as pc
    files = sorted(pc.ph.files_under([pc.GAME]))
    types = pc.Types(files)
    pc.DS_BUILD[0] = False
    defs = {}
    for f in files:
        recs, _c, _d = pc.scan(f, types)
        for name, ret, params, line, is_def, static, ex in recs:
            if is_def and not static and "asm" not in ex["pre_toks"]:
                defs.setdefault(name, []).append((f, ret, params))
    return pc, types, defs


def host_same(pc, ret, params, dret, dparams):
    """('yes'|'check', reason) for a declaration (ret, params) against the definition."""
    why = []
    bad = []
    ok = True
    pairs = [(a, b, "argument") for a, b in zip(params or [], dparams or [])] + [(ret, dret, "return")]
    for a, b, what in pairs:
        k = pc.classify(a, b)
        if k is None:
            continue
        ka, kb = pc.int_kind(a), pc.int_kind(b)
        if k == "pointee":
            why.append("pointer types only")
        elif k in ("width", "sign") and ka and kb and ka[0] >= kb[0] and (k == "width" or ka[0] == 32):
            why.append("DS %s is as wide or wider; the host keeps the definition's width" % what)
        else:
            ok = False
            bad.append("%s %s: %s vs %s" % (what, k, a, b))
    return ("yes" if ok else "unsure"), "; ".join(sorted(set(why if ok else bad)))


def draft_rows(unmatched):
    """TSV rows (kind, where, function, original, host, host same?) for guards of declarations,
    from the DS declaration in the block against the host definition."""
    pc, types, defs = protocheck_tables()
    pc.DS_BUILD[0] = True
    by_file = {}
    for g in unmatched:
        by_file.setdefault(g["file"], []).append(g)
    rows = []
    seen = set()
    for rel in sorted(by_file):
        recs, _c, _d = pc.scan(os.path.join(ROOT, rel), types)
        ds = {}
        for name, ret, params, line, is_def, static, ex in recs:
            if not is_def:
                ds.setdefault(name, []).append((line, ret, params))
        for g in by_file[rel]:
            man = MANUAL.get((rel, g["func"])) or next((MANUAL[(rel, n)] for n in g["decls"] if (rel, n) in MANUAL), None)
            where0 = "%s:%d" % (rel, g["start"])
            if man and (rel, g["func"]) not in seen:
                seen.add((rel, g["func"]))
                rows.append("	".join([man[0], where0, g["func"] or "", man[1], man[2], man[3]]))
                continue
            if man:
                continue
            if not g["decls"] and g["func"] is None and g["sense"] == "host":
                if (rel, "*include") not in seen:
                    seen.add((rel, "*include"))
                    rows.append("	".join(["other", where0, "(includes)", INCLUDE_ONLY, "includes it", "yes"]))
                continue
            for name in g["decls"]:
                if (rel, name) in seen:
                    continue
                seen.add((rel, name))
                cand = [d for d in ds.get(name, []) if g["start"] <= d[0] <= g["end"]] or ds.get(name, [])
                dfn = defs.get(name, [])
                where = "%s:%d" % (rel, g["start"])
                if (rel, name) in MANUAL:
                    m = MANUAL[(rel, name)]
                    rows.append("	".join([m[0], where, name, m[1], m[2], m[3]]))
                    continue
                if not cand or len(dfn) != 1:
                    text = " ".join(x.strip() for x in g["body"] if name in x and not x.lstrip().startswith("#"))
                    text = re.sub(r"\s*/\*.*?\*/", "", text)[:110] or "a renamed or macro form"
                    rows.append("	".join(["B", where, name, "DS declares the original form: %s" % text,
                                           "uses the header declaration", "unsure"]))
                    continue
                line, ret, params = cand[0]
                dfile, dret, dparams = dfn[0]
                kinds = pc.compare(dret, dparams or [], ret, params)
                ds_sig = pc.sig_text(ret, params)
                host_sig = pc.sig_text(dret, dparams)
                if "count" in kinds or "unproto" in kinds:
                    k = "D"
                    nds = len(params or [])
                    nho = len(dparams or [])
                    if params is None or nds >= nho:
                        same = "yes"
                        why = "the DS call passes extra or unprototyped arguments; the callee ignores them"
                    else:
                        same = "no"
                        why = "the DS call passes fewer arguments than the definition reads"
                elif kinds:
                    k = "B"
                    same, why = host_same(pc, ret, params, dret, dparams)
                else:
                    k, same, why = "B", "yes", "the guard keeps a header-equal declaration"
                rows.append("	".join([k, where, name,
                                       "DS declares %s; the definition is %s (%s)" % (ds_sig, host_sig, why),
                                       "uses the header declaration", same]))
    return rows


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--tsv", action="store_true")
    ap.add_argument("--apply", action="store_true",
                    help="append the draft rows to docs/ORIGINAL_BUGS.tsv (claim the file first)")
    a = ap.parse_args(argv)
    guards = all_guards()
    rows = load_rows()
    used = set()
    unmatched = []
    for g in guards:
        hits = [r for r in rows if row_matches(g, r)]
        used.update(r["n"] for r in hits)
        allowed = [k for k in ALLOWLIST
                   if k[0] == g["file"] and (k[1] == "*" or k[1] == g["func"] or k[1] in g["names"])]
        if not hits and not allowed:
            unmatched.append(g)
        if a.list:
            print("%s:%d-%d\t%s\t%s\t%s\t%s" % (g["file"], g["start"], g["end"], g["kind"], g["func"] or "-",
                                               ",".join(str(r["n"]) for r in hits) or ("allow" if allowed else "NONE"),
                                               g["sense"]))
    unguarded = [r for r in rows if r["n"] not in used and r["kind"] not in ("E", "other")]
    # a row whose host form is "same" and whose code has no guard is a valid archive of an unguarded case
    orphan = [r for r in unguarded if r["cols"][5].strip() != "yes"]
    for r in unguarded:
        if r not in orphan:
            print("  note: row %d (%s %s) has no guard, host same" % (r["n"], r["file"], r["func"][:40]))
    print("guards: %d in %d files; rows: %d" % (len(guards), len({g["file"] for g in guards}), len(rows)))
    print("guards with no row: %d" % len(unmatched))
    for g in unmatched:
        if a.tsv:
            pass
        else:
            print("  %s:%d-%d [%s] %s" % (g["file"], g["start"], g["end"], g["kind"],
                                          g["func"] or " ".join(g["names"][:4])))
    if a.tsv or a.apply:
        new = draft_rows(unmatched)
        if a.apply:
            with open(TSV, "a", encoding="utf-8", newline="") as f:
                for line in new:
                    f.write(line + chr(10))
            print("appended %d rows to docs/ORIGINAL_BUGS.tsv" % len(new))
        else:
            for line in new:
                print(line)
    bad = [(g, split_problem(g)) for g in guards]
    bad = [(g, w) for g, w in bad if w]
    print("guards that split a statement: %d" % len(bad))
    for g, w in bad:
        print("  %s:%d-%d %s" % (g["file"], g["start"], g["end"], w))
    print("rows with no guard: %d" % len(orphan))
    for r in orphan:
        print("  row %d: %s:%s %s (%s)" % (r["n"], r["file"], r["line"] or "", r["func"], r["kind"]))
    return 1 if unmatched or orphan or bad else 0


if __name__ == "__main__":
    sys.exit(main())
