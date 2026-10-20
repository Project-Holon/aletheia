#!/usr/bin/env python3
"""fnaddr.py: the address of a function, whatever its name.

The counting and checking tools (ovstats, worklist, coveragemap, linkstats,
progress_report, placeholders, gamecheck, restructure.shard_index, and the
member indexes of match.py) used to find the members of a unit entry only by
names that carry an address (func_XXXXXXXX).  A tree-wide rename to real names
(tools/sdkrename.py) would then drop those members from every figure without
an error.  This module resolves them by address instead.

Sources, in order:

  1. the entry's own `address` field (every manifest entry has one);
  2. a unit entry's `addresses` list, parallel to its `functions` list, when
     the shard records one (match.py entry_from_source writes it when a member
     name carries no address; sdkrename writes it when it renames a member);
  3. a name of the form func_XXXXXXXX / sub_XXXXXXXX (also with a prefix such
     as ov010_func_XXXXXXXX);
  4. the unit's compiled layout: the source is compiled with its own header
     settings and laid out from its `address:` the way match.run_tu lays it out
     (match.layout_tu with the image, so linker veneers between sections are
     counted); every function symbol of the object then has an address.  The
     result is kept per source file under its stamp in build/cache/fnaddr.pkl,
     so a file is compiled again only when it changes.

Source 4 is used only for a member that 2 and 3 do not place, so a tree whose
member names all carry addresses compiles nothing.  defined_addresses() (every
function a unit's source places, siblings its list omits included) always uses
source 4.  A member that is a label inside another function's bytes has no
symbol in the object, so after a rename only source 2 places it: rename with
tools/sdkrename.py, which records the list first.

ALETHEIA_FNADDR_NO_COMPILE=1 turns source 4 off (a member that only it could
resolve stays unresolved; callers report it as uncounted).

    python tools/fnaddr.py --check      every EXACT unit: does each name that
                                        carries an address agree with the layout?
    python tools/fnaddr.py --selftest
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
import stampcache  # noqa: E402

ADDR_NAME = re.compile(r"(?:^|_)(?:func|sub)_([0-9A-Fa-f]{8})$")

# Reserved key in a compiled layout dict (layouts()/compile_layout()): the
# laid-out .text size of the source.  It is not a symbol name, so
# member_addresses() never looks it up and defined_addresses() filters it out;
# it is what lets a caller tell whether a listing label lies strictly inside
# this unit (tools/worklist.py's interior labels, docs/notes/pkt_02014D2C_boundary.c.txt).
UNIT_SIZE_KEY = "__size__"


def name_address(name):
    """The address a func_/sub_XXXXXXXX name carries, or None."""
    m = ADDR_NAME.search(str(name or ""))
    return int(m.group(1), 16) if m else None


def entry_address(e):
    try:
        return int(str(e.get("address")), 16) if e.get("address") else None
    except ValueError:
        return None


def is_unit(e):
    return str(e.get("kind", "")).endswith("_unit")


def _source_path(e):
    src = str(e.get("source") or e.get("src") or "").replace("\\", "/")
    if not src:
        return None
    return src if os.path.isabs(src) else os.path.join(ROOT, *src.split("/"))


# ---------------------------------------------------------------- layout (source 4)

_LAYOUT = {}          # source path -> {name: address} (this process)
_CACHE = {}


def _compile_disabled():
    return bool(os.environ.get("ALETHEIA_FNADDR_NO_COMPILE"))


def compile_layout(path, region=None):
    """{function name: address} of every function symbol of the source at `path`,
    compiled with its header settings and laid out from its `address:`.
    Raises on any failure (a failure is never cached)."""
    import match
    h = match.read_header(path)
    addr = int(h.get("address", "0"), 0)
    if not addr:
        raise ValueError("no address in %s" % path)
    flags = (h.get("flags") or "-O4,p").split()
    lang = h.get("lang") or "c99"
    reg = (h.get("region") or region or "").strip() or None
    r = match.find_region(addr, reg)
    isa = (h.get("isa") or "").strip().lower()
    if isa:
        thumb = isa.startswith("thumb")
    else:
        import argparse as _ap
        thumb = match.resolve_isa(addr, r.name, _ap.Namespace(thumb=False, arm=False))
    work = tempfile.mkdtemp(prefix="bwfa_")
    try:
        obj, _cmd, log, _rc = match.compile_tu(path, h.get("compiler", "1.1p1"), flags, thumb,
                                               lang, work)
        if obj is None:
            raise RuntimeError("compile failed: %s" % (log or "").strip().splitlines()[:1])
        tl = match.layout_tu(obj, image=memoryview(r.data)[addr - r.base:])
    finally:
        shutil.rmtree(work, ignore_errors=True)
    out = {}
    for _base, _size, _pad, names in tl.parts:
        for n in names:
            if n in tl.locals:
                out.setdefault(n, addr + tl.locals[n])
    out[UNIT_SIZE_KEY] = tl.size
    return out


def _cache():
    if "c" not in _CACHE:
        _CACHE["c"] = stampcache.Cache("fnaddr", owners=[__file__])
        _CACHE["st"], _CACHE["v"] = _CACHE["c"]._load()
        _CACHE["dirty"] = False
    return _CACHE["c"]


def _key(path):
    ab = os.path.abspath(path)
    try:
        rel = os.path.relpath(ab, ROOT).replace(os.sep, "/")
    except ValueError:
        return ab
    return ab if rel.startswith("../") else rel


def _header_stamp():
    """(count, newest mtime, total size) of the headers a source may include.
    A header edit changes a prototype or type and so a compiled layout, so
    the stamp of a source covers them too."""
    if "h" not in _CACHE:
        n = new = tot = 0
        for d, _dirs, files in os.walk(os.path.join(ROOT, "src", "game")):
            for f in files:
                if f.endswith(".h"):
                    try:
                        st = os.stat(os.path.join(d, f))
                    except OSError:
                        continue
                    n += 1
                    new = max(new, st.st_mtime_ns)
                    tot += st.st_size
        _CACHE["h"] = (n, new, tot)
    return _CACHE["h"]


def _stamp(path):
    try:
        st = os.stat(path)
    except OSError:
        return None
    return (st.st_mtime_ns, st.st_size) + _header_stamp()


def layouts(paths, region_of=None, jobs=None):
    """{path: {name: address} or None} for many sources, compiling the ones the
    cache does not hold in parallel.  None: the source did not compile."""
    _cache()
    out, todo = {}, []
    for p in dict.fromkeys(paths):
        if p in _LAYOUT:
            out[p] = _LAYOUT[p]
            continue
        s = _stamp(p)
        key = _key(p)
        cached = _CACHE["v"].get(key) if s is not None and _CACHE["st"].get(key) == s else None
        if isinstance(cached, dict) and UNIT_SIZE_KEY in cached:
            out[p] = _LAYOUT[p] = cached
            continue
        if s is None or _compile_disabled():
            out[p] = None
            continue
        todo.append((p, key, s))
    if todo:
        n = jobs or min(8, os.cpu_count() or 4)

        def work(t):
            try:
                return t, compile_layout(t[0], (region_of or {}).get(t[0]))
            except (Exception, SystemExit):
                return t, None
        with cf.ThreadPoolExecutor(max_workers=n) as ex:
            for (p, key, s), val in ex.map(work, todo):
                out[p] = _LAYOUT[p] = val
                if val is not None:
                    _CACHE["st"][key] = s
                    _CACHE["v"][key] = val
                    _CACHE["dirty"] = True
        if _CACHE["dirty"]:
            _CACHE["c"].save(_CACHE["st"], _CACHE["v"])
            _CACHE["dirty"] = False
    return out


def unit_layout(e):
    """{name: address} of the unit entry's compiled source, or None."""
    p = _source_path(e)
    if p is None:
        return None
    return layouts([p], {p: e.get("region")}).get(p)


def unit_size(e):
    """The unit's compiled extent in bytes (its laid-out .text, linker veneers
    included), or None when its source does not compile.  A listing label that
    falls strictly inside [address, address + unit_size) is an interior branch
    target of that unit, not a function start of its own."""
    lay = unit_layout(e)
    if not lay:
        return None
    return lay.get(UNIT_SIZE_KEY)


# ---------------------------------------------------------------- members

def _listed(e):
    """[(name, address or None)] from the entry alone (sources 1-3)."""
    names = [n for n in (e.get("functions") or []) if isinstance(n, str) and n]
    rec = e.get("addresses") or []
    out = []
    for i, n in enumerate(names):
        a = None
        if len(rec) == len(names):
            try:
                a = int(str(rec[i]), 16)
            except ValueError:
                a = None
        if a is None:
            a = name_address(n)
        out.append((n, a))
    return out


def member_addresses(e):
    """[(name, address or None)] for the members a unit entry's `functions` list
    names, in list order (sources 2, 3, then 4).  For a non-unit entry: the
    entry's own (name, address)."""
    if not is_unit(e):
        return [(e.get("name", ""), entry_address(e))]
    out = _listed(e)
    if any(a is None for _n, a in out):
        lay = unit_layout(e) or {}
        out = [(n, a if a is not None else lay.get(n)) for n, a in out]
    return out


def listed_functions(e):
    """[(name, address or None)] for every function an entry claims by name:
    a unit's members (member_addresses), or for any other entry its own name
    and the names of a `functions` list (a runtime entry's vendor names, which
    resolve only through `covers`, so they come back with None)."""
    if is_unit(e):
        return member_addresses(e)
    out = [(e.get("name", ""), entry_address(e))]
    for n in e.get("functions") or []:
        if isinstance(n, str) and n and n != e.get("name"):
            out.append((n, name_address(n)))
    return out


def defined_addresses(e):
    """{address: name} of every function the unit's compiled source places
    (siblings its `functions` list omits included); {} when it does not compile."""
    lay = unit_layout(e) or {}
    out = {}
    for n, a in lay.items():
        if n == UNIT_SIZE_KEY:
            continue
        out.setdefault(a, n)
    return out


def prefetch(entries):
    """Compile, in parallel, the units whose members need source 4."""
    paths, regs = [], {}
    for e in entries:
        if not is_unit(e):
            continue
        if any(a is None for _n, a in _listed(e)):
            p = _source_path(e)
            if p:
                paths.append(p)
                regs[p] = e.get("region")
    if paths:
        layouts(paths, regs)


def prefetch_layouts(entries):
    """Compile, in parallel, every unit entry's source whose layout the cache does
    not hold (defined_addresses() then needs no compile of its own)."""
    paths, regs = [], {}
    for e in entries:
        if is_unit(e):
            p = _source_path(e)
            if p:
                paths.append(p)
                regs[p] = e.get("region")
    if paths:
        layouts(paths, regs)


# ---------------------------------------------------------------- checks

def check(limit=20):
    """Every EXACT unit entry: do the names that carry an address agree with the
    compiled layout?  Returns the number of disagreements."""
    import match
    ents = [e for e in match.load_manifest_entries()
            if is_unit(e) and str(e.get("status", "")).startswith("EXACT")]
    paths = {}
    for e in ents:
        p = _source_path(e)
        if p:
            paths[p] = e.get("region")
    lay = layouts(list(paths), paths)
    bad = nolay = members = 0
    for e in ents:
        p = _source_path(e)
        L = lay.get(p)
        if L is None:
            nolay += 1
            continue
        for n, a in _listed(e):
            members += 1
            if a is None:
                continue
            if L.get(n) != a:
                bad += 1
                if bad <= limit:
                    print("disagree: %s %s member %s: name 0x%08X, layout %s"
                          % (e.get("region"), e["name"], n, a,
                             "0x%08X" % L[n] if n in L else "absent"))
    print("units %d, members %d, layout disagreements %d, units not compiled %d"
          % (len(ents), members, bad, nolay))
    return bad


def selftest():
    assert name_address("func_0215839C") == 0x0215839C
    assert name_address("ov010_func_02158378") == 0x02158378
    assert name_address("sub_02000000") == 0x02000000
    assert name_address("FOO_AddBadCafe") is None
    assert name_address("MI_CpuFill8") is None
    e = {"name": "u", "address": "0x02000000", "kind": "game_unit",
         "functions": ["FOO_Init", "func_02000010"], "addresses": ["0x02000000", "0x02000010"]}
    assert member_addresses(e) == [("FOO_Init", 0x02000000), ("func_02000010", 0x02000010)]
    e2 = dict(e, functions=["func_02000000", "func_02000010"])
    del e2["addresses"]
    assert member_addresses(e2) == [("func_02000000", 0x02000000), ("func_02000010", 0x02000010)]
    g = {"name": "BAR_Run", "address": "0x02000040", "kind": "game"}
    assert member_addresses(g) == [("BAR_Run", 0x02000040)]
    # source 4: a member no name or record places comes from the compiled layout
    # (here a stand-in held in the per-process table); a name the layout lacks
    # (a label inside another function) stays None
    src = os.path.join(ROOT, "src", "matched", "_fnaddr_selftest.c")
    _LAYOUT[src] = {"Foo_Init": 0x02000000, "Foo_Exit": 0x02000020}
    try:
        e3 = {"name": "unit_02000000", "address": "0x02000000", "kind": "game_unit",
              "source": "src/matched/_fnaddr_selftest.c",
              "functions": ["Foo_Init", "func_02000010", "Foo_Exit", "Foo_Label"]}
        assert member_addresses(e3) == [("Foo_Init", 0x02000000), ("func_02000010", 0x02000010),
                                        ("Foo_Exit", 0x02000020), ("Foo_Label", None)], member_addresses(e3)
        assert defined_addresses(e3) == {0x02000000: "Foo_Init", 0x02000020: "Foo_Exit"}
        # a recorded list wins over the name and the layout
        e4 = dict(e3, addresses=["0x02000000", "0x02000010", "0x02000020", "0x02000030"])
        assert [a for _n, a in member_addresses(e4)] == [0x02000000, 0x02000010, 0x02000020, 0x02000030]
        # a list of the wrong length is ignored
        e5 = dict(e3, addresses=["0x02000000"])
        assert member_addresses(e5) == member_addresses(e3)
    finally:
        _LAYOUT.pop(src, None)
    print("fnaddr selftest: ok")
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--selftest", action="store_true")
    a = ap.parse_args(argv)
    if a.selftest:
        return selftest()
    if a.check:
        return 1 if check() else 0
    ap.print_help()
    return 0


if __name__ == "__main__":
    sys.exit(main())
