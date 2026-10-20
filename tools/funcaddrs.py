#!/usr/bin/env python3
"""funcaddrs.py: the address of every function that src/game defines.

Each top-level file of src/game/<region>/ is compiled the way tools/gameverify.py
compiles it (header compiler, flags, lang, isa) and laid out from its header
`address:` like match.layout_tu (linker veneers taken from the image).  Every
function symbol of the object, static or not, gets an address (file base plus
the symbol offset), an isa (from the $a/$t mapping symbols) and a size (the
symbol size).  The bytes of each function are then compared with the image at
that address (relocation holes wildcarded); a function that disagrees is
reported; a file with any mismatch gives no rows (it is mid-edit).

A file marked `contiguous: no` (a piece) takes its function addresses from its
`symbols:` block, and a runtime-kind file (arm9 functions that are all rows of
layout/runtime_arm9.txt) from that table; neither is compared with the image
here (gameverify does it per function).  Data-only files have no rows.

usage
  python tools/funcaddrs.py table [--out layout/function_addrs.tsv] [--check]
        compile every file, cross-check against the image and write the table
        (--check: write nothing, exit 1 when the committed table differs)
  python tools/funcaddrs.py unlisted [--region R]
        non-static functions a file defines that its `function:` header omits
  python tools/funcaddrs.py headers [--dry-run] [--lane NAME]
        add the omitted non-static functions to each file's `function:` list
        in address order (header comment only)
  python tools/funcaddrs.py noaddr
        listed functions that no manifest entry gives an address
  python tools/funcaddrs.py manifest [--dry-run]
        write the missing member addresses into the unit entries of
        layout/matched and add a shard for each listed function no entry
        places (kind game, source = its src/game file)

Output is sorted and deterministic.  Python 3 stdlib only.
"""
import argparse
import concurrent.futures as cf
import os
import re
import shutil
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)

TREE = os.path.join(ROOT, "src", "game")
TABLE = os.path.join(ROOT, "layout", "function_addrs.tsv")
COLS = ["region", "address", "name", "isa", "size", "file", "static"]
STB_LOCAL = 0
HEADER_FN = r"^( \* function:[ \t]*)(.*(?:\n \*   .*)*)"


def settings_of(raw):
    import protofix as pf
    h = pf.parse_header(raw)
    cc = (h.get("compiler") or "1.1p1").strip()
    cc = cc[4:] if cc.startswith("dsi/") else cc
    fl = re.sub(r"-proc\s+arm946e", "", h.get("flags") or "").strip() or "-O4,p"
    return h, {"compiler": cc, "flags": fl, "lang": (h.get("lang") or "").strip(),
               "isa": ((h.get("isa") or "thumb").split() or ["thumb"])[0]}


def source_files(tree=TREE, region=None):
    """[(region dir, path)] of the top-level .c files, sorted."""
    out = []
    for r in sorted(d for d in os.listdir(tree) if os.path.isdir(os.path.join(tree, d))):
        if region and r != region:
            continue
        base = os.path.join(tree, r)
        for f in sorted(os.listdir(base)):
            if f.endswith(".c") and not f.startswith("_"):
                out.append((r, os.path.join(base, f)))
    return out


def rel(path):
    return os.path.relpath(path, ROOT).replace(os.sep, "/")


def compile_file(region_dir, path):
    """(rows, note) for one file.  rows: dicts with region, addr, name, isa, size, static,
    bad (True when the bytes differ from the image).  note: why no rows, or ''."""
    import match
    raw = open(path, encoding="latin1").read()
    if raw.startswith("\xef\xbb\xbf"):
        raw = raw[3:]
    h, st = settings_of(raw)
    try:
        addr = int(h.get("address", "0"), 16)
    except ValueError:
        addr = 0
    reg = (h.get("region") or region_dir).strip()
    if not addr:
        return [], "no address"
    mh = match.read_header(path)
    piece = match.header_is_piece(mh)
    if reg == "arm9":
        names = [n.strip() for n in (mh.get("function") or "").split(",") if n.strip()]
        rt = set(match.runtime_addresses().values())
        if names and all(n in rt for n in names):
            return piece_rows(path, mh, st, reg, st["isa"] == "thumb", runtime=True), ""
    r = match.find_region(addr, reg)
    thumb = st["isa"] == "thumb"
    if piece:
        return piece_rows(path, mh, st, reg, thumb), ""
    work = tempfile.mkdtemp(prefix="bwfx_")
    try:
        flags = st["flags"].split() if st["flags"] else ["-O4,p"]
        obj, _cmd, log, _rc = match.compile_tu(path, st["compiler"], flags, thumb,
                                               st["lang"] or None, work)
        if obj is None:
            return [], "compile failed"
        image = memoryview(r.data)[addr - r.base:]
        tl = match.layout_tu(obj, image=image)
        with open(obj, "rb") as fh:
            o = match.Obj(os.path.basename(obj), fh.read())
        syms, _ = match.read_symbols(o)
    finally:
        shutil.rmtree(work, ignore_errors=True)
    if not tl.data:
        return [], "no code"
    rows = []
    for name, value, size, typ, bind, shndx in syms:
        if typ != match.STT_FUNC or not shndx or name not in tl.locals:
            continue
        off = tl.locals[name]
        isa = "thumb" if tl.local_isa.get(name, thumb) else "arm"
        n = size
        if n <= 0:
            continue
        a = addr + off
        want = bytes(tl.data[off:off + n])
        mask = bytearray(tl.mask[off:off + n])
        # a call site may be bl in the object and blx in the image (interworking):
        # the whole word of a relocation site is a wildcard
        for ro, _rt, _rn, _ra in tl.relocs:
            for k in range(max(ro, off), min(ro + 4, off + n)):
                mask[k - off] = 0
        have = bytes(r.data[a - r.base:a - r.base + n])
        bad = len(have) != n or any(m and x != y for m, x, y in zip(mask, want, have))
        rows.append({"region": reg, "addr": a, "name": name, "isa": isa, "size": n,
                     "static": bind == STB_LOCAL, "bad": bad})
    return rows, ""


def piece_rows(path, mh, st, reg, thumb, runtime=False):
    """Rows of a non-contiguous piece: each listed function's address comes from the file's
    `symbols:` block (match.piece_name_addresses); the size and the static flag from the
    object.  Not compared with the image here (gameverify does it per function)."""
    import match
    names = [n.strip() for n in (mh.get("function") or "").split(",") if n.strip()]
    if runtime:
        byaddr = match.runtime_addresses()
        by_name = {n: a for a, n in sorted(byaddr.items())}
    else:
        by_name = match.piece_name_addresses(mh, names)
    work = tempfile.mkdtemp(prefix="bwfx_")
    try:
        flags = st["flags"].split() if st["flags"] else ["-O4,p"]
        obj, _cmd, _log, _rc = match.compile_tu(path, st["compiler"], flags, thumb,
                                                st["lang"] or None, work)
        if obj is None:
            return []
        with open(obj, "rb") as fh:
            o = match.Obj(os.path.basename(obj), fh.read())
        syms, _ = match.read_symbols(o)
    finally:
        shutil.rmtree(work, ignore_errors=True)
    rows = []
    for name, value, size, typ, bind, shndx in syms:
        a = by_name.get(name)
        if typ != match.STT_FUNC or not shndx or size <= 0 or a is None:
            continue
        rows.append({"region": reg, "addr": a, "name": name, "isa": "thumb" if thumb else "arm",
                     "size": size, "static": bind == STB_LOCAL, "bad": False})
    if runtime:
        # asm labels inside a runtime function have no function symbol: a listed name that the
        # runtime table places gets a row of size 0
        got = {r["name"] for r in rows}
        for n in names:
            if n in by_name and n not in got:
                rows.append({"region": reg, "addr": by_name[n], "name": n,
                             "isa": "thumb" if thumb else "arm", "size": 0, "static": False,
                             "bad": False})
    return rows


def build(region=None, jobs=None):
    """({file: rows}, {file: note}) for the whole tree."""
    files = source_files(region=region)
    res, notes = {}, {}

    def work(t):
        try:
            return t, compile_file(*t)
        except (Exception, SystemExit) as ex:
            return t, ([], "error: %s" % str(ex)[:80])
    with cf.ThreadPoolExecutor(max_workers=jobs or min(8, os.cpu_count() or 4)) as ex:
        for (rd, p), (rows, note) in ex.map(work, files):
            if not note and any(r["bad"] for r in rows):
                # the compiled bytes differ from the image (the file is mid-edit): its
                # addresses are not proven, so it gives no rows
                note = "image mismatch (%d functions)" % sum(1 for r in rows if r["bad"])
                rows = []
            res[rel(p)] = rows
            if note:
                notes[rel(p)] = note
    return res, notes


def table_lines(res):
    rows = []
    for f, rs_ in res.items():
        for r in rs_:
            rows.append((r["region"], r["addr"], r["name"], r["isa"], r["size"], f,
                         "yes" if r["static"] else "no"))
    rows.sort()
    out = ["\t".join(COLS)]
    for reg, a, n, isa, sz, f, s in rows:
        out.append("%s\t0x%08X\t%s\t%s\t%d\t%s\t%s" % (reg, a, n, isa, sz, f, s))
    return "\n".join(out) + "\n"


def listed_names(raw):
    """Names of the file's `function:` header (ordered)."""
    import match
    # raw header text, same parse as match.read_header
    m = re.search(r"^ \* function:[ \t]*(.*(?:\n \*   .*)*)", raw.split("*/", 1)[0], re.M)
    if not m:
        return []
    return [n for n in re.split(r"[,\s]+", m.group(1).replace("*", " ")) if n]


def unlisted(res):
    """[(file, name, addr)] of non-static functions missing from the file's function: list."""
    out = []
    for f, rows in res.items():
        raw = open(os.path.join(ROOT, f), encoding="latin1").read()
        have = set(listed_names(raw))
        for r in rows:
            if not r["static"] and r["name"] not in have:
                out.append((f, r["name"], r["addr"]))
    return sorted(out, key=lambda t: (t[0], t[2]))


def cmd_table(a):
    res, notes = build(a.region)
    bad = []
    text = table_lines(res)
    for f, n in sorted(notes.items()):
        print("skipped %s: %s" % (f, n))
    nrows = text.count("\n") - 1
    print("files %d, functions %d, files without rows %d" % (len(res), nrows, len(notes)))
    if a.check:
        cur = open(a.out, encoding="utf-8", newline="").read() if os.path.exists(a.out) else ""
        return 0 if cur == text and not bad else 1
    if not a.region:
        with open(a.out, "w", encoding="utf-8", newline="\n") as fh:
            fh.write(text)
    return 0


def cmd_unlisted(a):
    res, _n = build(a.region)
    u = unlisted(res)
    for f, n, ad in u:
        print("%s\t%s\t0x%08X" % (f, n, ad))
    print("unlisted: %d" % len(u), file=sys.stderr)
    return 0


def plan_header(raw, rows):
    """(new function: name list, replaced [(old, new)], added [name], absent [name]) for one
    file.  rows: the file's table rows (dicts with name, addr, static).

    A listed name the file does not define is replaced, in order, by the defined name that no
    list entry names, when both counts agree (the header carries a name the object does not).
    Every non-static function the list still omits is inserted in address order."""
    cur = listed_names(raw)
    defined = {r["name"]: r for r in rows}
    absent = [n for n in cur if n not in defined]
    spare = [r["name"] for r in sorted(rows, key=lambda r: r["addr"]) if r["name"] not in cur]
    names = list(cur)
    replaced = []
    if absent and len(absent) == len(spare):
        sub = dict(zip(absent, spare))
        names = [sub.get(n, n) for n in names]
        replaced = list(sub.items())
        absent = []
    have = set(names)
    added = []
    for r in sorted(rows, key=lambda r: r["addr"]):
        if r["static"] or r["name"] in have:
            continue
        pos = 0
        for i, c in enumerate(names):
            if c in defined and defined[c]["addr"] < r["addr"]:
                pos = i + 1
        names.insert(pos, r["name"])
        have.add(r["name"])
        added.append(r["name"])
    return names, replaced, added, absent


def cmd_headers(a):
    res, notes = build(a.region)
    only = set(x.replace("\\", "/") for x in (a.file or []))
    changed = 0
    nrep = nadd = 0
    for f, rows in sorted(res.items()):
        if f in notes and not rows:
            continue
        if only and f not in only:
            continue
        if a.skip_region and f.split("/")[2] in a.skip_region:
            continue
        p = os.path.join(ROOT, f)
        raw = open(p, encoding="latin1", newline="").read()
        m = re.search(HEADER_FN, raw, re.M)
        if m and m.end() > raw.index("*/"):
            m = None
        names, replaced, added, absent = plan_header(raw, rows)
        if not replaced and not added:
            continue
        if m:
            new = raw[:m.start()] + m.group(1) + ", ".join(names) + raw[m.end():]
        else:
            # no function: line: add one before the address: line
            am = re.search(r"^ \* address:", raw, re.M)
            if not am or am.start() > raw.index("*/"):
                print("no function: or address: line: %s" % f)
                continue
            new = raw[:am.start()] + " * function: " + ", ".join(names) + "\n" + raw[am.start():]
        changed += 1
        nrep += len(replaced)
        nadd += len(added)
        if a.list:
            print(f)
        if not a.dry_run:
            with open(p, "w", encoding="latin1", newline="") as fh:
                fh.write(new)
    print("files %s: %d (names replaced %d, names added %d)"
          % ("to change" if a.dry_run else "changed", changed, nrep, nadd))
    return 0


def cmd_check(a):
    """The port's two checks from the table: non-static functions a file defines but its
    function: list omits, and listed names no table row gives an address."""
    res, notes = build(a.region)
    unl, noaddr = [], []
    for f, rows in sorted(res.items()):
        if f in notes and not rows:
            continue
        raw = open(os.path.join(ROOT, f), encoding="latin1").read()
        cur = listed_names(raw)
        defined = {r["name"] for r in rows}
        unl += [(f, r["name"]) for r in rows if not r["static"] and r["name"] not in cur]
        noaddr += [(f, n) for n in cur if n not in defined]
    for f, n in unl:
        print("unlisted	%s	%s" % (f, n))
    for f, n in noaddr:
        print("no address	%s	%s" % (f, n))
    print("unlisted %d, listed without address %d, files skipped %d"
          % (len(unl), len(noaddr), len(notes)))
    return 1 if unl or noaddr else 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    sub = ap.add_subparsers(dest="cmd")
    t = sub.add_parser("table")
    t.add_argument("--out", default=TABLE)
    t.add_argument("--check", action="store_true")
    t.add_argument("--region")
    u = sub.add_parser("unlisted")
    u.add_argument("--region")
    hd = sub.add_parser("headers")
    hd.add_argument("--dry-run", action="store_true")
    hd.add_argument("--region")
    hd.add_argument("--file", action="append")
    hd.add_argument("--skip-region", action="append")
    hd.add_argument("--list", action="store_true")
    ck = sub.add_parser("check")
    ck.add_argument("--region")
    a = ap.parse_args(argv)
    if a.cmd == "table":
        return cmd_table(a)
    if a.cmd == "unlisted":
        return cmd_unlisted(a)
    if a.cmd == "headers":
        return cmd_headers(a)
    if a.cmd == "check":
        return cmd_check(a)
    ap.print_help()
    return 0


if __name__ == "__main__":
    sys.exit(main())
