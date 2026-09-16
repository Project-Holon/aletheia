#!/usr/bin/env python3
"""
closure.py -- which matched translation units can be compiled for the host.

The native port (see port/README.md) compiles the *same* C files that
tools/csrc.py splices into the DS image.  A matched file can only be linked
on the host when every name it references is itself provided: by another
matched file, by our own SDK shim (port/sdk/), by the compiler runtime, or
by a deliberate stub (port/stubs/).  This script computes that closure
mechanically so port/CMakeLists.txt's source list can grow without anybody
guessing.

Inputs, all already in the tree, none of them game bytes:

  layout/matched/**/*.json   the manifest shards: address, name, source,
                             isa, status, and for a unit entry the list of
                             functions the unit defines
  src/matched/*.c            the `extern` declarations and the `symbols:`
                             header block of each matched file
  layout/symbols_sdk.txt     SDK library symbols (address + name)
  layout/runtime_arm9.txt    mwccarm/MSL runtime helpers (address + name)

Every referenced name is put in exactly one class:

  matched   defined by another EXACT matched source           (link it)
  sdk       an SDK library symbol                             (port/sdk/)
  runtime   an MSL/runtime.a helper such as _s32_div_f        (port/sdk/)
  open      a game function at a known address that nothing
            in src/matched/ defines yet                       (port/stubs/)
  data      a global object (the `data` kind in `symbols:`, or
            a g_ name) that lives in the ARM9 image           (port/sdk/)

A source is *closed* when it references nothing in the `open` or `data`
classes.  A source is *linkable* when the port supplies the open and data
names some other way; the port records those explicitly rather than
letting the linker decide.

Usage:

    python tools/port/closure.py --list-closed
    python tools/port/closure.py --seed src/matched/sub_02018A7C.c
    python tools/port/closure.py --seed-func func_02045E3C --cmake

`--seed` takes a source path or a function name (`--seed-func`) and walks
the call graph through matched files only.  `--cmake` prints the closure as
a CMake source list ready to paste into port/CMakeLists.txt.

This script reads only layout/ and src/; it writes nothing.
"""

from __future__ import annotations

import argparse
import glob
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

ADDR_NAME = re.compile(r"^(?:sub|func|unit)_0([0-9A-Fa-f]{7})$")
EXTERN_LINE = re.compile(r"^\s*extern\s+(.*?);", re.M | re.S)
IDENT = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")
SYMBOL_ROW = re.compile(r"^\s*\*\s+([A-Za-z_][A-Za-z0-9_]*)\s+(0x[0-9A-Fa-f]{8})\s+(thumb|arm|data)\s*$")
SYMBOLS_HDR = re.compile(r"^\s*\*\s*symbols:\s*$")

C_KEYWORDS = {
    "const", "volatile", "struct", "union", "enum", "unsigned", "signed",
    "char", "short", "int", "long", "float", "double", "void", "static",
    "inline", "register", "restrict", "extern", "typedef",
    "u8", "u16", "u32", "u64", "s8", "s16", "s32", "s64", "fx32", "fx16",
    "BOOL", "vu8", "vu16", "vu32", "vs8", "vs16", "vs32",
}


def read_symbol_table(path):
    """address -> name for the two-column layout/*.txt symbol files."""
    by_addr = {}
    by_name = {}
    full = os.path.join(ROOT, path)
    if not os.path.exists(full):
        return by_addr, by_name
    with open(full, encoding="utf-8") as fh:
        for line in fh:
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            parts = line.split()
            if len(parts) < 2:
                continue
            try:
                addr = int(parts[0], 16)
            except ValueError:
                continue
            by_addr.setdefault(addr, parts[1])
            by_name.setdefault(parts[1], addr)
    return by_addr, by_name


class Index:
    def __init__(self):
        self.entries = []          # one dict per shard entry
        self.by_addr = {}          # address -> entry
        self.defines = {}          # function name -> source path
        self.sources = {}          # source path -> entry
        self.externs = {}          # source path -> [names]
        self.symbols = {}          # source path -> {name: (addr, kind)}
        self.sdk_by_addr, self.sdk_by_name = read_symbol_table("layout/symbols_sdk.txt")
        self.rt_by_addr, self.rt_by_name = read_symbol_table("layout/runtime_arm9.txt")
        self._load_shards()
        self._load_sources()

    def _load_shards(self):
        pattern = os.path.join(ROOT, "layout", "matched", "**", "*.json")
        for path in sorted(glob.glob(pattern, recursive=True)):
            with open(path, encoding="utf-8") as fh:
                shard = json.load(fh)
            for fn in shard.get("functions", []):
                if fn.get("status") not in ("EXACT", "EXACT*"):
                    continue
                entry = {
                    "name": fn["name"],
                    "address": int(fn["address"], 16),
                    "source": fn["source"].replace("\\", "/"),
                    "isa": fn.get("isa", "arm"),
                    "region": fn.get("region", "arm9"),
                    "status": fn["status"],
                    "shard": os.path.basename(path),
                    "functions": fn.get("functions") or [fn["name"]],
                }
                self.entries.append(entry)
                self.by_addr[entry["address"]] = entry
                self.sources[entry["source"]] = entry
                for name in entry["functions"]:
                    self.defines.setdefault(name, entry["source"])
                # `unit_0204ABCD` is a file name, not a symbol; the real lead
                # function keeps its own sub_/func_ spelling in `functions`.
                self.defines.setdefault(entry["name"], entry["source"])

    def _load_sources(self):
        for source in self.sources:
            full = os.path.join(ROOT, source)
            if not os.path.exists(full):
                self.externs[source] = []
                self.symbols[source] = {}
                continue
            with open(full, encoding="utf-8", errors="replace") as fh:
                text = fh.read()
            self.symbols[source] = self._parse_symbols(text)
            self.externs[source] = self._parse_externs(text)

    @staticmethod
    def _parse_symbols(text):
        out = {}
        in_block = False
        for line in text.splitlines():
            if SYMBOLS_HDR.match(line):
                in_block = True
                continue
            if in_block:
                m = SYMBOL_ROW.match(line)
                if m:
                    out[m.group(1)] = (int(m.group(2), 16), m.group(3))
                elif line.strip().startswith("*/") or not line.strip().startswith("*"):
                    in_block = False
        return out

    @staticmethod
    def _parse_externs(text):
        # Strip comments first so prose that mentions `extern` cannot match.
        stripped = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
        stripped = re.sub(r"//[^\n]*", " ", stripped)
        names = []
        for decl in EXTERN_LINE.findall(stripped):
            # The declared name is the last identifier before the first '('
            # (a function) or the last identifier overall (an object).
            head = decl.split("(")[0]
            idents = [i for i in IDENT.findall(head) if i not in C_KEYWORDS]
            if idents:
                names.append(idents[-1])
        return names

    def classify(self, source, name):
        """Return (klass, detail) for one name referenced by one source."""
        owner = self.defines.get(name)
        if owner and owner != source:
            return "matched", owner
        if owner == source:
            return "local", source

        addr = None
        sym = self.symbols.get(source, {}).get(name)
        if sym:
            addr, kind = sym
            if kind == "data":
                return "data", "0x%08X" % addr
        else:
            m = ADDR_NAME.match(name)
            if m:
                addr = int("0" + m.group(1), 16)

        if name in self.rt_by_name or (addr is not None and addr in self.rt_by_addr):
            return "runtime", name
        if name in self.sdk_by_name or (addr is not None and addr in self.sdk_by_addr):
            return "sdk", self.sdk_by_name.get(name) and name or self.sdk_by_addr.get(addr, name)
        if addr is not None:
            owner = self.by_addr.get(addr)
            if owner and owner["source"] != source:
                # Same address, different spelling of the name.  The DS build
                # resolves relocations by address and does not care; a host
                # linker resolves by name and does.  Every one of these needs
                # a forwarder in port/sdk/aliases.c.
                if name not in owner["functions"] and name != owner["name"]:
                    return "alias", "%s in %s" % (owner["functions"][0], owner["source"])
                return "matched", owner["source"]
            return "open", "0x%08X" % addr
        return "data", name

    def refs(self, source):
        out = []
        for name in self.externs.get(source, []):
            klass, detail = self.classify(source, name)
            if klass == "local":
                continue
            out.append((name, klass, detail))
        return out

    def closure(self, seeds):
        """Transitively pull in matched sources; report what stays open."""
        seen = []
        queue = list(seeds)
        open_refs = {}
        while queue:
            source = queue.pop(0)
            if source in seen:
                continue
            seen.append(source)
            for name, klass, detail in self.refs(source):
                if klass == "matched":
                    if detail not in seen and detail not in queue:
                        queue.append(detail)
                    continue
                if klass == "alias":
                    owner = detail.split(" in ", 1)[1]
                    if owner not in seen and owner not in queue:
                        queue.append(owner)
                open_refs.setdefault((name, klass, detail), []).append(source)
        return seen, open_refs

    def resolve_seed(self, seed):
        seed = seed.replace("\\", "/")
        if seed in self.sources:
            return seed
        if seed.endswith(".c"):
            for source in self.sources:
                if source.endswith("/" + os.path.basename(seed)):
                    return source
        owner = self.defines.get(seed)
        if owner:
            return owner
        raise SystemExit("closure.py: no matched source defines %r" % seed)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[1])
    ap.add_argument("--seed", action="append", default=[],
                    help="matched source path (repeatable)")
    ap.add_argument("--seed-func", action="append", default=[],
                    help="function name whose defining source seeds the walk")
    ap.add_argument("--list-closed", action="store_true",
                    help="every matched source whose externs are all matched/sdk/runtime")
    ap.add_argument("--cmake", action="store_true",
                    help="print the closure as a CMake source list")
    args = ap.parse_args(argv)

    idx = Index()

    if args.list_closed:
        closed, openish = [], 0
        for source in sorted(idx.sources):
            refs = idx.refs(source)
            bad = [r for r in refs if r[1] in ("open", "data", "alias")]
            if bad:
                openish += 1
            else:
                closed.append(source)
        print("matched sources: %d" % len(idx.sources))
        print("closed (matched + sdk + runtime only): %d" % len(closed))
        print("open (needs a stub or a data provider): %d" % openish)
        for source in closed:
            print("  " + source)
        return 0

    seeds = [idx.resolve_seed(s) for s in args.seed]
    seeds += [idx.resolve_seed(s) for s in args.seed_func]
    if not seeds:
        ap.error("give --seed or --seed-func, or --list-closed")

    sources, open_refs = idx.closure(seeds)

    if args.cmake:
        for source in sorted(sources):
            print("    ${BW_ROOT}/%s" % source)
        return 0

    print("closure of %s: %d matched translation units" % (", ".join(seeds), len(sources)))
    for source in sorted(sources):
        entry = idx.sources[source]
        print("  %-38s %s %-6s %s" % (source, entry["status"], entry["isa"],
                                      ",".join(entry["functions"])))
    print()
    buckets = {}
    for (name, klass, detail), users in sorted(open_refs.items()):
        buckets.setdefault(klass, []).append((name, detail, users))
    for klass in ("sdk", "runtime", "alias", "open", "data"):
        rows = buckets.get(klass, [])
        if not rows:
            continue
        print("%s (%d):" % (klass, len(rows)))
        for name, detail, users in rows:
            print("  %-28s %-12s <- %s" % (name, detail,
                                           ", ".join(os.path.basename(u) for u in users)))
        print()
    return 0


if __name__ == "__main__":
    sys.exit(main())
