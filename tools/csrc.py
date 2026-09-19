#!/usr/bin/env python3
"""csrc.py -- compile the matched C sources and hand their bytes to build.py.

This is the bridge between ``tools/match.py`` (which proves that a C source
reproduces a range of the original image) and ``tools/build.py`` (which
assembles ``asm/`` into the regions the ROM is built from).  Nothing here
re-implements the compiler invocation, the ELF reader, the translation-unit
layout or the relocation resolver: all of that is imported from ``match.py``,
so there is still exactly one implementation of each in the repository and a
change to the matching rules cannot drift away from the shipping build.

What it adds is the step ``match.py`` deliberately does not take: turning a
verified comparison into *bytes that go into the image*.

    entry in a layout/matched/ shard
        -> compile with mwccarm at the recorded flags
        -> extract the function, or lay out the whole translation unit
        -> resolve every relocation at the entry's real address
        -> insist the result is EXACT and fully concrete
        -> emit a Splice: (region, offset, bytes)

``build.py`` then overwrites that range of the assembled region image.  The
mechanism is deliberately a byte splice into the flat region image rather than
an object-level link: the assembled region is already linked at its final
address, the compiled unit is placed and relocated at its final address, and
at that point the two are just bytes.  A real ``mwld`` link, with the C objects
and the ``asm/`` objects fed to one linker script, is the eventual shape;
nothing here forecloses it, because the placement and relocation logic that a
link would need is exactly what ``match.py`` already performs and what this
module drives.

Refusing to splice is the point of the ``EXACT`` requirement.  If a matched C
file regresses, the build fails and prints the same two-column diff
``match.py`` prints.  It never falls back to the assembly, because a silent
fallback would mean the ROM still verifies while the C in the tree is wrong,
which is the one failure mode this whole exercise exists to rule out.
"""

from __future__ import annotations

import json
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
if os.path.join(ROOT, "tools") not in sys.path:
    sys.path.insert(0, os.path.join(ROOT, "tools"))

import match  # noqa: E402


MANIFEST = match.MANIFEST


class CSourceError(Exception):
    """A matched C file did not reproduce its range.  Fatal, never ignored."""

    def __init__(self, message, detail=""):
        Exception.__init__(self, message)
        self.detail = detail


class Splice:
    """One verified range of compiler output, ready to go into the image."""

    __slots__ = ("name", "address", "size", "data", "source", "kind",
                 "region", "nrelocs", "nresolved", "functions")

    def __init__(self, name, address, data, source, kind, region,
                 nrelocs=0, nresolved=0, functions=None):
        self.name = name
        self.address = address
        self.size = len(data)
        self.data = data
        self.source = source
        self.kind = kind
        self.region = region
        self.nrelocs = nrelocs
        self.nresolved = nresolved
        self.functions = functions or []

    @property
    def end(self):
        return self.address + self.size

    def __repr__(self):
        return "<Splice %s %08X+%d>" % (self.name, self.address, self.size)


# ---------------------------------------------------------------------------
# the manifest
# ---------------------------------------------------------------------------

def load_manifest(path=None):
    """Every manifest entry, from every shard under layout/matched/.

    The manifest is one file per work packet now, so there is nothing to
    concatenate here: match.load_manifest_entries is the single reader and it
    is also what fails loudly if a pre-shard layout/matched.json is still in
    the tree.  ``path`` names one shard file when a caller wants just that
    one (a packet agent checking its own work), and is otherwise None.
    """
    if path is None or path == MANIFEST:
        return match.load_manifest_entries()
    if os.path.isdir(path):
        raise CSourceError("%s: pass a single shard file or nothing" % path)
    if not os.path.isfile(path):
        return []
    with open(path, "r", encoding="utf-8") as fh:
        return json.load(fh).get("functions", [])


def entry_flags(entry):
    """(version, flags list, lang, thumb) for one manifest entry.

    The manifest records the whole command line in ``flags``; the optimisation
    flags are whatever is not in match.BASE_FLAGS, ``-thumb`` or ``-lang X``.
    Reading them back from there rather than re-deriving them keeps the build
    honest: it compiles with the configuration the entry was verified under.

    ``compiler`` is written as ``dsi/<version>``, and ``<version>`` may itself be
    a relative path that escapes the dsi directory (``dsi/../1.2/sp2``) for a
    function whose original was built by a different front end. Only the
    ``dsi/`` prefix is peeled here, so the same string reaches
    match.compiler_path that verified the entry: taking the last path component
    (the old behaviour) turned ``dsi/../1.2/sp2`` into ``dsi/sp2`` and the chain
    then refused to build a file match.py had already verified.
    """
    version = entry["compiler"]
    if version.startswith("dsi/"):
        version = version[4:]
    lang = entry.get("lang", "c99")
    thumb = entry.get("isa", "thumb") == "thumb"
    words = entry.get("flags", "").split()
    base = list(match.BASE_FLAGS)
    opts = []
    i = 0
    while i < len(words):
        w = words[i]
        if base and w == base[0]:
            base.pop(0)
            i += 1
            continue
        if w == "-thumb":
            i += 1
            continue
        if w == "-lang":
            i += 2
            continue
        opts.append(w)
        i += 1
    return version, (opts or ["-O4,p"]), lang, thumb


# ---------------------------------------------------------------------------
# compiling one entry
# ---------------------------------------------------------------------------

def compile_entry(entry):
    """Compile one manifest entry and return a Splice.

    Raises CSourceError with a match.py-style diff if the result is not EXACT,
    or if any byte of it is still a wildcard (an unresolved relocation), which
    would mean the splice is not fully determined by the source.
    """
    src = os.path.join(ROOT, entry["source"].replace("/", os.sep))
    if not os.path.isfile(src):
        raise CSourceError("%s: no such source file" % entry["source"])
    addr = int(entry["address"], 16)
    version, flags, lang, thumb = entry_flags(entry)
    region = entry.get("region")
    is_unit = entry["kind"].endswith("_unit")

    if is_unit:
        res, _tl = match.run_tu(src, addr, version, flags, thumb, lang,
                                region=region)
    else:
        res = match.run_one(src, entry["name"], addr, version, flags, thumb,
                            lang, region=region)

    if res.status == "CCERR":
        raise CSourceError("%s: the compiler rejected %s"
                           % (entry["name"], entry["source"]),
                           res.log)
    fb = res.func
    if not res.status.startswith("EXACT"):
        raise CSourceError(
            "%s (%s) is %s at 0x%08X, not EXACT; refusing to splice"
            % (entry["name"], entry["source"], res.status, addr),
            _diff_text(fb, res.target, addr, res))
    if any(b == 0 for b in fb.mask):
        wild = sum(1 for b in fb.mask if b == 0)
        raise CSourceError(
            "%s: %d byte(s) are still relocation wildcards, so the bytes are "
            "not fully determined by the source; refusing to splice"
            % (entry["name"], wild),
            "\n".join("    " + s.describe() for s in fb.sites))

    nres = sum(1 for s in fb.sites if s.resolved)
    return Splice(entry["name"], addr, bytes(fb.data), entry["source"],
                  entry["kind"], res.region or region or "?",
                  len(fb.relocs), nres, entry.get("functions"))


def _diff_text(fb, target, addr, res):
    """match.py's own two-column diff, captured as text."""
    import io
    import contextlib
    buf = io.StringIO()
    with contextlib.redirect_stdout(buf):
        if res.note:
            print("    note: %s" % res.note)
        match.print_sites(fb, indent="    ")
        if fb is not None and target:
            match.print_diff(fb, target, addr, match.reloc_map(fb))
    return buf.getvalue()


# ---------------------------------------------------------------------------
# compiling the set
# ---------------------------------------------------------------------------

def select(entries, keep=None):
    """Drop manifest entries that duplicate a larger one.

    The manifest deliberately records both ``sub_020084BC`` and the
    unit ``unit_020084BC`` that contains it, because both are documented
    results.  For the build only one of them may own a byte, so overlapping
    entries are resolved in favour of the widest coverage.  ``keep`` is a
    predicate on the address, used to skip entries outside the regions this
    run is building.
    """
    cand = [e for e in entries
            if keep is None or keep(int(e["address"], 16))]
    # Units first at equal address, so the wide entry wins the greedy pass
    # below even before any size is known.
    cand.sort(key=lambda e: (int(e["address"], 16),
                             0 if e["kind"].endswith("_unit") else 1))
    return cand


def resolve_overlaps(splices):
    """Greedily keep the widest non-overlapping set.  Returns (kept, dropped)."""
    order = sorted(splices, key=lambda s: (s.address, -s.size))
    kept, dropped = [], []
    for sp in order:
        if kept and sp.address < kept[-1].end:
            if sp.end <= kept[-1].end:
                dropped.append((sp, kept[-1]))
                continue
            raise CSourceError(
                "%s (0x%08X..0x%08X) partially overlaps %s "
                "(0x%08X..0x%08X); the manifest is inconsistent"
                % (sp.name, sp.address, sp.end, kept[-1].name,
                   kept[-1].address, kept[-1].end))
        kept.append(sp)
    return kept, dropped


def build_splices(manifest=None, keep=None, jobs=1, kinds=None,
                  progress=None):
    """Compile every applicable matched entry.  Returns (kept, dropped).

    Raises CSourceError on the first entry that does not reproduce its range.
    Evidence and region caches in match.py are warmed first, because they are
    lazily built globals and several threads would otherwise race to fill them.
    """
    entries = select(load_manifest(manifest), keep)
    if kinds is not None:
        entries = [e for e in entries if e["kind"] in kinds]
    if not entries:
        return [], []

    match.load_all_regions()
    match.evidence()
    match.sdk_symbols()
    match.matched_symbols()

    splices = []
    if jobs > 1:
        from concurrent.futures import ThreadPoolExecutor
        with ThreadPoolExecutor(max_workers=jobs) as pool:
            futs = [(e, pool.submit(compile_entry, e)) for e in entries]
            for e, f in futs:
                sp = f.result()
                splices.append(sp)
                if progress:
                    progress(sp)
    else:
        for e in entries:
            sp = compile_entry(e)
            splices.append(sp)
            if progress:
                progress(sp)
    return resolve_overlaps(splices)


# ---------------------------------------------------------------------------
# CLI: useful on its own to see what the build would splice
# ---------------------------------------------------------------------------

def main(argv=None):
    import argparse
    ap = argparse.ArgumentParser(
        prog="csrc.py",
        description="Compile the matched C sources and report what build.py "
                    "would splice into the image.")
    ap.add_argument("--manifest", default=None,
                    help="one shard file under layout/matched/ instead of all "
                         "of them")
    ap.add_argument("-j", "--jobs", type=int, default=4)
    args = ap.parse_args(argv)

    try:
        kept, dropped = build_splices(args.manifest, jobs=args.jobs)
    except CSourceError as exc:
        print("error: %s" % exc, file=sys.stderr)
        if exc.detail:
            print(exc.detail, file=sys.stderr)
        return 1

    total = sum(s.size for s in kept)
    print("  %-22s %-12s %7s  %-6s  %s"
          % ("entry", "address", "bytes", "relocs", "source"))
    for s in kept:
        print("  %-22s 0x%08X   %7d  %d/%-4d  %s"
              % (s.name, s.address, s.size, s.nresolved, s.nrelocs, s.source))
    for s, owner in dropped:
        print("  (%s is covered by %s, not spliced separately)"
              % (s.name, owner.name))
    print("\n%d entr(ies), %d bytes of compiler output" % (len(kept), total))
    return 0


if __name__ == "__main__":
    sys.exit(main())
