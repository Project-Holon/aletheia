#!/usr/bin/env python3
"""namesync.py: do the evidence store and src/game name the same function the same way?

A manifest entry (layout/matched/**/*.json) names a function, or the members of
a unit, at an address.  src/game defines a function at the same (region, address)
under its own name.  Both are reviewed separately, so the names can drift apart
(a rename applied to one tree only).  This tool lists every pair that disagrees
and can rename the evidence side.

Method: every src/game source is compiled and laid out from its `address:`
(tools/aliascheck.definitions, tools/fnaddr), which gives {(region, address): name}.
Every manifest entry then yields (name, address) pairs through
tools/fnaddr.listed_functions (a unit contributes each member).  A pair whose
address is defined in src/game under another name is a mismatch.

    python tools/namesync.py              print the mismatches, exit 1 if any
    python tools/namesync.py --tsv        old new address region isa shard (a sdkrename-style map;
                                          `#` rows: the address has several definitions)
    python tools/namesync.py --targets    the repo files --apply would edit
    python tools/namesync.py --apply [--allow LIST] [--skip TSV]
                                          rename the evidence side to the src/game name: manifest
                                          entry names and unit member lists, and the evidence source
                                          of each entry (whole words, one regex pass per file; a
                                          target name the file already uses is skipped and reported)
    python tools/namesync.py --jobs N     compile in N parallel jobs

Rule that decides which side is right (wave 18): the src/game name wins.
Waves 15 to 17 audited it against the SDK tables, the callers and the module
prefix.  The evidence name wins only when the src/game name is not a usable
identifier of its module: the file's own prefix (bg_sys.c carries BG_SYS_)
is held by most of its functions and the src/game name is an outlier that does
not carry it while the evidence name does.  Such a case is renamed in src/game
first (tools/sdkrename.py) and then needs no row here.  A function that sits in a
file of another module (a MISC_ function in beacon.c) keeps its src/game name: the
file name is the stale part.
"""
import argparse
import glob
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)

import aliascheck  # noqa: E402
import fnaddr  # noqa: E402

WORD = r"(?<![A-Za-z0-9_])(%s)(?![A-Za-z0-9_])"


def game_definitions(jobs=None):
    """({(region, address): names}, failed paths) over every src/game source."""
    return aliascheck.definitions(aliascheck.game_sources(), jobs)


def manifest_entries():
    pat = os.path.join(ROOT, "layout", "matched", "**", "*.json")
    for f in sorted(glob.glob(pat, recursive=True)):
        try:
            d = json.load(open(f, encoding="utf-8"))
        except (OSError, ValueError):
            continue
        shard = os.path.relpath(f, ROOT).replace(os.sep, "/")
        for e in d.get("functions", []):
            yield shard, e


def mismatches(defs):
    out = []
    for shard, e in manifest_entries():
        region = e.get("region")
        if not region:
            continue
        for name, addr in fnaddr.listed_functions(e):
            if addr is None:
                continue
            d = defs.get((region, addr))
            if not d or name in d:
                continue
            out.append((name, sorted(d), addr, region, shard, e.get("name")))
    return out


def source_path(src):
    return os.path.join(ROOT, *str(src).split("/"))


def build_edits(rows):
    """(shards, sources) for the mismatch rows: shards maps a shard path to the
    {entry index: {old: new}} renames of its entries, sources maps an evidence
    source path to the {old: new} renames of the functions it holds."""
    by_shard = {}
    for name, d, addr, region, shard, _ent in rows:
        if len(d) == 1:
            by_shard.setdefault(shard, {})[(name, addr, region)] = d[0]
    shards = {}
    sources = {}
    addrs = {}
    for shard, mp in by_shard.items():
        data = json.load(open(os.path.join(ROOT, shard), encoding="utf-8"))
        ents = {}
        for k, e in enumerate(data.get("functions", [])):
            region = e.get("region") or data.get("region")
            ren = {}
            if fnaddr.is_unit(e):
                for n, a in fnaddr.member_addresses(e):
                    new = mp.get((n, a, region))
                    if new:
                        ren[n] = new
                        addrs.setdefault(e.get("source"), {})[n] = a
            else:
                new = mp.get((e.get("name"), fnaddr.entry_address(e), region))
                if new:
                    ren[e.get("name")] = new
                    addrs.setdefault(e.get("source"), {})[e.get("name")] = fnaddr.entry_address(e)
            if ren:
                ents[k] = ren
                if e.get("source"):
                    sources.setdefault(e["source"], {}).update(ren)
        if ents:
            shards[shard] = ents
    return shards, sources, addrs


ROWRX = re.compile(r"^(\s*\*\s+)(\S+)(\s+0x([0-9A-Fa-f]+)\s+(?:arm|thumb|data).*)$", re.M)


def header_row_addr(text, name):
    for m in ROWRX.finditer(text):
        if m.group(2) == name:
            return int(m.group(4), 16)
    return None


def rewrite_source(path, ren, addrs=None):
    """Rename whole words in an evidence source in one pass.  `ren` is {old: new},
    `addrs` {old: address of the function}.  Returns (new text or None when
    unchanged, [old names skipped]).

    A target name that the file already uses is a clash when it names another
    function (a callee at another address, common for the static helpers of the
    overlay demo code that share names across files).  Then the callee gets the
    name <target>_<ADDRESS> inside this file (its symbols: row, its declaration
    and its calls) and the function takes the target name.  Without a row that
    gives the callee's address the rename is skipped."""
    try:
        text = open(path, encoding="latin1", newline="").read()
    except OSError:
        return None, list(ren)
    skipped = []
    use = {}
    callee = {}
    code = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
    for old, new in ren.items():
        if not re.search(WORD % re.escape(old), text):
            continue
        if (re.search(WORD % re.escape(new), code) or header_row_addr(text, new) is not None) and new not in ren:
            ra = header_row_addr(text, new)
            mine = (addrs or {}).get(old)
            if ra is not None and mine is not None and ra == mine:
                use[old] = new
            elif ra is not None:
                callee[new] = "%s_%08X" % (new, ra)
                use[old] = new
            else:
                skipped.append(old)
            continue
        use[old] = new
    if not use:
        return None, skipped
    if callee:
        for name, alias in callee.items():
            # the symbols: row, declarations and calls of the other function
            text = re.sub(r"^(\s*\*\s+)%s(\s+0x[0-9A-Fa-f]+\s+(?:arm|thumb|data).*)$" % re.escape(name),
                          lambda m: m.group(1) + alias + m.group(2), text, flags=re.M)
            text = re.sub(r"(?<![A-Za-z0-9_.>])%s(?=\s*\()" % re.escape(name), alias, text)
    rx = re.compile(WORD % "|".join(re.escape(o) for o in sorted(use, key=len, reverse=True)))
    out = rx.sub(lambda m: use[m.group(1)], text)
    return (out if out != text else None), skipped


def apply_rows(rows, may_edit=lambda path: True):
    """Rename the evidence side to the src/game names.  Returns
    (changed shards, changed sources, skipped list)."""
    shards, sources, srcaddr = build_edits(rows)
    changed_src = {}
    skipped = []
    for src, ren in sources.items():
        if not may_edit(src):
            skipped.append((src, "not editable", sorted(ren)))
            continue
        text, sk = rewrite_source(source_path(src), ren, srcaddr.get(src))
        if sk:
            skipped.append((src, "target name already used", sk))
        if text is not None:
            changed_src[src] = text
    changed_shards = []
    for shard, ents in shards.items():
        if not may_edit(shard):
            skipped.append((shard, "not editable", []))
            continue
        path = os.path.join(ROOT, shard)
        raw = open(path, encoding="utf-8", newline="").read()
        data = json.loads(raw)
        for k, ren in ents.items():
            e = data["functions"][k]
            if fnaddr.is_unit(e):
                e["functions"] = [ren.get(n, n) if isinstance(n, str) else n
                                  for n in (e.get("functions") or [])]
            else:
                e["name"] = ren.get(e.get("name"), e.get("name"))
        txt = json.dumps(data, indent=1, ensure_ascii=False)
        if raw.endswith(chr(10)):
            txt += chr(10)
        open(path, "w", encoding="utf-8", newline="").write(txt)
        changed_shards.append(shard)
    for src, text in changed_src.items():
        open(source_path(src), "w", encoding="latin1", newline="").write(text)
    return changed_shards, changed_src, skipped


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split(chr(10))[0])
    ap.add_argument("--tsv", action="store_true")
    ap.add_argument("--jobs", type=int, default=None)
    ap.add_argument("--targets", action="store_true",
                    help="list the repo files --apply would edit (manifest shards and evidence sources)")
    ap.add_argument("--apply", action="store_true",
                    help="rename the evidence side to the src/game names (manifests and evidence sources)")
    ap.add_argument("--allow", metavar="LIST",
                    help="with --apply: edit only the repo paths listed in this file (one per line)")
    ap.add_argument("--skip", metavar="TSV",
                    help="leave the (old name, address) rows of this TSV out")
    a = ap.parse_args(argv)
    defs, failed = game_definitions(a.jobs)
    for p in failed:
        print("no layout: " + os.path.relpath(p, ROOT), file=sys.stderr)
    rows = mismatches(defs)
    skip = set()
    if a.skip:
        for line in open(a.skip, encoding="utf-8"):
            f = line.rstrip(chr(10)).split(chr(9))
            if len(f) >= 3 and not line.startswith("#"):
                skip.add((f[0], int(f[2], 16)))
    seen = set()
    uniq = []
    for r in rows:
        k = (r[0], r[2], r[3])
        if k in seen or (r[0], r[2]) in skip:
            continue
        seen.add(k)
        uniq.append(r)
    if a.targets:
        shards, sources, _addrs = build_edits(uniq)
        for f in sorted(set(shards) | set(sources)):
            print(f)
        return 0
    if a.apply:
        allow = None
        if a.allow:
            allow = {l.strip() for l in open(a.allow, encoding="utf-8") if l.strip()}
        sh, src, skipped = apply_rows(uniq, (lambda f: True) if allow is None else (lambda f: f in allow))
        print("namesync: %d shard(s), %d source(s) rewritten" % (len(sh), len(src)), file=sys.stderr)
        for f, why, names in skipped:
            print("skipped %s (%s) %s" % (f, why, " ".join(names[:6])), file=sys.stderr)
        return 0
    if a.tsv:
        for name, d, addr, region, shard, _e in uniq:
            line = chr(9).join([name, d[0], "0x%08X" % addr, region, "arm", shard])
            print(line if len(d) == 1 else "# " + line)
    else:
        for name, d, addr, region, shard, _e in uniq:
            print("%s: %s at 0x%08X [%s] is %s in src/game" % (shard, name, addr, region, "/".join(d)))
    print("namesync: %d mismatch(es)" % len(uniq), file=sys.stderr)
    return 1 if uniq else 0


if __name__ == "__main__":
    sys.exit(main())
