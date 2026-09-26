#!/usr/bin/env python3
"""Territory map for parallel decompilation of arm9_main.

Reads the generated listings in asm/arm9/src/*.s (produced by tools/disasm.py),
classifies every function in the region, and groups the ones that are still
open into disjoint work packets that separate agents can claim without
touching each other's addresses.

Nothing here reads or writes game data: the listings are the only input that
carries bytes, and only addresses, sizes, symbol names and counts come out.

Inputs
------
  asm/arm9/src/*.s        function labels, instruction addresses, byte widths
  asm/arm9/src_itcm/*.s   same, for the ITCM autoload (tail-call thunk scan only)
  asm/overlays/*.s        same, for all 237 overlays (tail-call thunk scan only)
  layout/units_arm9.json  translation unit file order, base addresses, sizes
  layout/symbols_sdk.txt  SDK symbols recovered by tools/libmatch.py
  layout/runtime_arm9.txt mwccarm/MSL runtime library functions identified by
                          wave 18B (docs/notes/pkt_0209BDBC_runtime_library.c.txt),
                          same file shape as symbols_sdk.txt
  layout/matched/         manifest shards, one per work packet, read through
                          match.load_manifest_entries
  layout/file_anchors.txt __FILE__ literal-pool anchors harvested by
                          tools/fileanchors.py; feeds the --targets "guess"
                          column and the --packet anchor listing

Output
------
  layout/worklist.json    inventory summary plus one entry per work packet

Classification
--------------
Precedence is sdk > runtime > matched > open, with one documented exception:

  sdk       the function's address carries an SDK symbol in symbols_sdk.txt
            for region arm9.  These come from hybrid library linking and are
            NOT decompilation targets.  A handful of them are also listed in
            the manifest as sdk_calibration entries; those stay classified
            sdk and are counted separately as sdk_matched.  A label that
            falls strictly inside a sized SDK symbol (layout/symbols_sdk.json)
            is an interior kernel of that symbol and is classified sdk too
            (owner decision 2026-09-23; sdk_interior flag).
  runtime   the function's address is listed in layout/runtime_arm9.txt: the
            mwccarm/MSL runtime helper library, linked in as hand-written
            assembly.  Also NOT decompilation targets, excluded from the
            open pool and from the coverage denominator exactly like sdk.
  matched   covered by a manifest entry, either directly or as a member of a
            game_unit entry's function list, including sibling functions a
            game_unit's source file defines but its "functions" list omits
            (see find_unit_member_addrs).  Read only.
  open      everything else.  These are the decompilation targets and the
            only functions that end up inside packets.

The exception: when an address carries both an SDK symbol and a matched
entry of kind game or game_unit, the matched entry wins only when the SDK row
is weak (flagged '?' or its name is duplicated in the region); the function is
then classified matched, with the losing SDK name recorded as sdk_conflict.
A strong SDK row always wins.
libmatch.py flags short library functions with no sibling evidence as weak
(the trailing '?' column in symbols_sdk.txt), and a byte-exact game match at
the same address is stronger evidence than a weak library pattern.  The
count of such conflicts is reported as sdk_conflicts; a non-zero count is a
hint that symbols_sdk.txt has more false positives shadowing game code.

Packet grouping
---------------
Open functions are walked in address order.  A packet break is forced when

  - an sdk or matched function sits between two consecutive open functions
    (packets never straddle foreign territory), or
  - the distance from the end of the previous function to the start of the
    next one exceeds GAP_SPLIT_BYTES (0x200) of non-code, or
  - the packet already holds SOFT_MAX_FUNCS functions or SOFT_MAX_CODE bytes
    of code, whichever comes first.

The soft caps sit inside the 20-40 function / 2-4 KB band the packets aim
for, so a packet closes as soon as either target is reached.

Merge rule for --refresh
------------------------
--refresh recomputes the whole inventory (so new matches and new SDK symbols
are picked up) while keeping the orchestrator's bookkeeping alive.  An
existing packet is PINNED, meaning its id, its boundaries and every field the
orchestrator owns (status, plus any extra keys it added such as an assignee
or a note) are carried over verbatim, when both of these hold:

  1. every function address it lists is still classified open, and
  2. the set of open functions now falling inside [start, end] is exactly the
     set the packet lists.

Derived fields of a pinned packet (sizes, hints, caller counts) are still
recomputed, because those depend on the listings rather than on the split.

A packet that fails either test is dissolved: its functions return to the
free pool and are regrouped, and any status it carried is dropped.  Dissolved
packets are named in the refresh report so a claim is never lost silently.
Pinned packets act as hard boundaries for the regrouping pass, so a claimed
packet can never gain or lose addresses behind the agent's back.

Refresh is idempotent: refreshing immediately after a build pins every
packet and reproduces the same file byte for byte.

Usage
-----
  python tools/worklist.py                  build layout/worklist.json
  python tools/worklist.py --force          rebuild, discarding all statuses
  python tools/worklist.py --refresh        recompute, keeping claims
  python tools/worklist.py --summary        print the coverage summary
  python tools/worklist.py --packet ID      print one packet in detail, each function marked
                                            matched or OPEN (only OPEN lines are work)
  python tools/worklist.py --packet ID --open-only   list just the open functions
"""

import argparse
import glob
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

UNITS_JSON = os.path.join(ROOT, "layout", "units_arm9.json")
SYMBOLS_SDK = os.path.join(ROOT, "layout", "symbols_sdk.txt")
SYMBOLS_SDK_JSON = os.path.join(ROOT, "layout", "symbols_sdk.json")
RUNTIME_ARM9 = os.path.join(ROOT, "layout", "runtime_arm9.txt")
MATCHED_DIR = os.path.join(ROOT, "layout", "matched")
FILE_ANCHORS = os.path.join(ROOT, "layout", "file_anchors.txt")
PROC_HINTS = os.path.join(ROOT, "layout", "proc_hints.txt")
OUT_JSON = os.path.join(ROOT, "layout", "worklist.json")

REGION = "arm9"
RUNTIME_REGION = "arm9_main"

# packet shaping
SOFT_MAX_FUNCS = 30          # inside the 20-40 band
SOFT_MAX_CODE = 3072         # inside the 2-4 KB band
GAP_SPLIT_BYTES = 0x200      # non-code run that forces a break
DATA_ADJACENT_BYTES = 0x100  # data run that earns the data-adjacent flag
THUNK_PRINT_LIMIT = 40       # --summary caps its thunk listing here

DATA_DIRECTIVES = (".word", ".byte", ".short", ".hword", ".ascii", ".asciz", ".space")

RE_LABEL = re.compile(r"^([A-Za-z_.$][A-Za-z0-9_.$]*):")
RE_FUNC_LABEL = re.compile(r"^func_([0-9A-Fa-f]{8}):")
RE_ORG = re.compile(r"^\.org\s+(0x[0-9A-Fa-f]+|\d+)")
RE_ADDR_BYTES = re.compile(
    r"/\*\s+([0-9A-F]{8})(?:\s\s((?:[0-9A-F]{2})(?:\s[0-9A-F]{2})*))?"
)
RE_FUNC_REF = re.compile(r"\bfunc_([0-9A-Fa-f]{8})\b")
RE_WORD_VALUE = re.compile(r"^\.word\s+0x([0-9A-Fa-f]{8})")

BRANCH_MNEMONICS = ("b", "bl", "blx", "bx")


def hexa(addr):
    return "0x%08X" % addr


# ---------------------------------------------------------------- inputs


def load_units():
    with open(UNITS_JSON, encoding="utf-8") as fh:
        doc = json.load(fh)
    return doc


def load_sdk_symbols():
    """address -> symbol name, restricted to the arm9 static region."""
    syms = {}
    with open(SYMBOLS_SDK, encoding="utf-8") as fh:
        for line in fh:
            line = line.split("#", 1)[0].strip()
            if not line:
                continue
            parts = line.split()
            if len(parts) < 4:
                continue
            addr_s, name, _lib, region = parts[0], parts[1], parts[2], parts[3]
            if region != REGION:
                continue
            try:
                addr = int(addr_s, 16)
            except ValueError:
                continue
            # duplicate addresses would mean two symbols on one entry point;
            # keep the first, which is the order libmatch.py emitted.
            syms.setdefault(addr, name)
    return syms


def load_sdk_overrulable():
    """Addresses whose SDK row a matched game entry may overrule.

    Only weak rows qualify: rows flagged `?` by libmatch.py, or rows whose
    symbol name appears more than once in the file (any region) (a pattern that fired
    at several places cannot name all of them). A strong row wins over a
    matched file (audit 2026-09-23, finding 3): the function leaves both the
    numerator and the denominator as SDK.
    """
    rows = []
    with open(SYMBOLS_SDK, encoding="utf-8") as fh:
        for line in fh:
            line = line.split("#", 1)[0].strip()
            parts = line.split()
            if len(parts) < 4:
                continue
            try:
                addr = int(parts[0], 16)
            except ValueError:
                continue
            rows.append((addr, parts[1], parts[3], "?" in parts[4:]))
    # duplicates are counted over every region in the file
    counts = {}
    for _a, name, _r, _w in rows:
        counts[name] = counts.get(name, 0) + 1
    return set(a for a, name, region, weak in rows
               if region == REGION and (weak or counts[name] > 1))


def load_sdk_extents():
    """[(start, end, name)] for every SDK symbol with a known size in the arm9
    static region, from libmatch.py's JSON.  A disassembler label that falls
    strictly inside one of these ranges is not a function: it is an interior
    kernel of a hand-written SDK routine (MI_CpuCopy, MI_CpuMove) that pops
    without pc and falls into a shared tail.  Owner decision 2026-09-23: the
    sdk class covers a symbol's full size, so such labels leave the open pool
    and the coverage denominator like the symbol itself.
    """
    if not os.path.exists(SYMBOLS_SDK_JSON):
        return []
    with open(SYMBOLS_SDK_JSON, encoding="utf-8") as fh:
        doc = json.load(fh)
    out = []
    for s in doc.get("symbols", []):
        if s.get("region") != REGION:
            continue
        size = int(s.get("size") or 0)
        if size <= 0:
            continue
        out.append((int(s["address"]), int(s["address"]) + size, s["name"]))
    out.sort()
    return out


def sdk_interior(extents, addr):
    """name+offset when addr lies strictly inside an SDK symbol's extent."""
    import bisect
    pos = bisect.bisect_right(extents, (addr, 1 << 40, "")) - 1
    if pos < 0:
        return None
    start, end, name = extents[pos]
    if start < addr < end:
        return "%s+0x%X" % (name, addr - start)
    return None


def load_runtime_symbols():
    """address -> symbol name for the mwccarm/MSL runtime library table.

    Same file shape as symbols_sdk.txt (see load_sdk_symbols), but a
    separate file because this table has nothing to do with hybrid SDK
    linking: it is the runtime.a soft-float / 64-bit integer helper library
    identified by wave 18B (docs/notes/pkt_0209BDBC_runtime_library.c.txt),
    linked in as hand-written assembly and never decompilable C.
    """
    syms = {}
    if not os.path.exists(RUNTIME_ARM9):
        return syms
    with open(RUNTIME_ARM9, encoding="utf-8") as fh:
        for line in fh:
            line = line.split("#", 1)[0].strip()
            if not line:
                continue
            parts = line.split()
            if len(parts) < 4:
                continue
            addr_s, name, _lib, region = parts[0], parts[1], parts[2], parts[3]
            if region != RUNTIME_REGION:
                continue
            try:
                addr = int(addr_s, 16)
            except ValueError:
                continue
            syms.setdefault(addr, name)
    return syms


RE_UNIT_MEMBER_DEF = re.compile(
    r"^[A-Za-z_][\w \*]*[A-Za-z0-9_]_([0-9A-Fa-f]{8})\s*\([^;{]*\)\s*$"
)

_UNIT_MEMBER_CACHE = {}


def find_unit_member_addrs(source_path):
    """Function addresses DEFINED (not merely declared) in a matched source.

    A game_unit manifest entry sometimes names only its entry address even
    though the file it points at defines sibling functions compiled into
    the same translation unit (a unit merged from previously separate
    matched files; src/matched/unit_02045C44.c is one example, defining
    both func_02045C44 and func_02045CAC while the manifest's "functions"
    list names only the former). Scanning the definitions in the file
    directly catches those without editing layout/matched/: a line is a
    definition rather than an extern declaration when it is not itself an
    `extern` line and does not end in a semicolon.
    """
    if source_path in _UNIT_MEMBER_CACHE:
        return _UNIT_MEMBER_CACHE[source_path]
    addrs = set()
    full = os.path.join(ROOT, source_path.replace("/", os.sep))
    try:
        with open(full, encoding="utf-8", errors="replace") as fh:
            for raw in fh:
                line = raw.strip()
                if not line or line.startswith("extern") or line.startswith("//") \
                        or line.startswith("*") or line.startswith("/*"):
                    continue
                m = RE_UNIT_MEMBER_DEF.match(line)
                if m:
                    addrs.add(int(m.group(1), 16))
    except OSError:
        pass
    _UNIT_MEMBER_CACHE[source_path] = addrs
    return addrs


SOLE_REF_SUBKINDS = ("data", "code", "string", "self")


def sole_ref_subkind(item):
    """The sub-kind name ("data"/"code"/"string"/"self") of one item.

    Since the 2026-09-21 widening, tools/match.py's sole_ref_sites() records
    each item as "<subkind>:0xADDRESS" (e.g. "code:0x02067998").  A shard
    written before the widening carries the bare "0xADDRESS" the single
    original (data-only) sub-kind used; that legacy shape is read as "data",
    the sub-kind it always meant.
    """
    if ":" in item:
        return item.split(":", 1)[0]
    return "data"


def load_matched():
    """address -> dict(name, entry, kind) for everything the shards cover.

    The manifest is sharded (layout/matched/<region>/<packet>.json), and
    match.load_manifest_entries is its one reader: reading the files here as
    well would mean two implementations of the shard union and of the check
    that refuses a stale pre-shard layout/matched.json.

    Beyond the manifest's own "functions" list, a game_unit entry's source
    file is scanned for sibling function definitions the list omits (see
    find_unit_member_addrs); those are recorded with "implied": True so a
    stale open packet that only becomes matched through this cross-check can
    be reported as such by --check and --refresh.
    """
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import match  # noqa: E402

    cover = {}
    for ent in match.load_manifest_entries():
        if ent.get("region") != REGION:
            continue
        # status gate (audit 2026-09-23, finding 4): only a verified shard
        # entry counts; plain `manifest` writes "unverified".
        if ent.get("status") not in match.MATCHED_STATUS:
            continue
        name = ent.get("name", "")
        kind = ent.get("kind", "")
        addrs = []
        if ent.get("address"):
            addrs.append((int(ent["address"], 16), name))
        for member in ent.get("functions", []) or []:
            m = re.search(r"([0-9A-Fa-f]{8})$", member)
            if m:
                addrs.append((int(m.group(1), 16), member))
        sole = ((ent.get("evidence") or {}).get("sole-ref")) or []
        for addr, who in addrs:
            cover.setdefault(addr, {"name": who, "entry": name, "kind": kind,
                                    "sole_ref": list(sole)})
        # `sole` items are "<subkind>:0xADDRESS" since the 2026-09-21
        # sole-ref widening (tools/match.py sole_ref_sites()); a shard
        # written before that widening carries the bare "0xADDRESS" the
        # single original (data) sub-kind used, and is read the same way by
        # sole_ref_subkind() below.
        if kind == "game_unit" and ent.get("source"):
            listed = set(a for a, _who in addrs)
            for addr in find_unit_member_addrs(ent["source"]):
                if addr in listed:
                    continue
                cover.setdefault(
                    addr,
                    {
                        "name": "func_%08X" % addr,
                        "entry": name,
                        "kind": kind,
                        "implied": True,
                    },
                )
    return cover


def load_file_anchors():
    """[(pool_site, filename)] __FILE__ anchors in arm9_main, sorted by site.

    Reads layout/file_anchors.txt (tools/fileanchors.py's output): each row
    is a __FILE__ literal-pool word, a compiler-generated attestation of
    which translation unit a block of code came from. Restricted to
    arm9_main, the only region this tool groups into packets; missing file
    means no anchors (the --targets guess and --packet listing degrade
    gracefully, they don't require it).
    """
    anchors = []
    if not os.path.isfile(FILE_ANCHORS):
        return anchors
    with open(FILE_ANCHORS, encoding="utf-8") as fh:
        for line in fh:
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            parts = line.split(None, 4)
            if len(parts) != 5:
                continue
            pool_site_s, _func_s, region, _str_addr_s, name = parts
            if region != "arm9_main":
                continue
            try:
                pool_site = int(pool_site_s, 16)
            except ValueError:
                continue
            anchors.append((pool_site, name))
    anchors.sort()
    return anchors


# ---------------------------------------------------------- tail-call thunks
#
# A one-section-per-function compiler cannot branch directly to another
# translation unit's function, so a same-module tail call is not a `bl`, it
# is a pool word and a `bx` (docs/idioms/tail-call-is-a-pool-word-and-bx.md):
#
#   ldr  r3, pool_XXXXXXXX     /* = target */
#   bx   r3
#
# No scan built on branch instructions ever sees this, which means neither
# inv["callers"] (built from the edges parse_unit reads out of the arm9_main
# listing) nor match.image_call_sites() (the image-wide index --targets uses
# for fan-in, built the same way) count a call to the thunk as a call to
# whatever it forwards to. disasm.py already traces the two-instruction body
# as an ordinary function (a `bx` is an unconditional return, so the trace
# stops there cleanly), so the shape shows up in the listings as a labelled
# func_XXXXXXXX with exactly this ldr/bx pair and nothing else -- a plain
# text scan is enough to find every one of them, image-wide.

RE_THUNK_FUNC = re.compile(r"^func_([0-9A-Fa-f]{8}):$")
RE_THUNK_LDR = re.compile(r"^ldr(?:\.w)?\s+(\w+),\s*pool_([0-9A-Fa-f]{8})\b")
RE_THUNK_BX = re.compile(r"^bx\s+(\w+)\b")
RE_THUNK_POOL_LABEL = re.compile(r"^pool_([0-9A-Fa-f]{8}):$")
RE_THUNK_WORD = re.compile(r"^\.word\s+0x([0-9A-Fa-f]{8})")


def _thunk_candidates_in_file(path):
    """[(func_addr, target)] tail-call thunks found in one listing file."""
    try:
        with open(path, encoding="utf-8", errors="replace") as fh:
            lines = [ln.strip() for ln in fh]
    except OSError:
        return []

    # Literal pools stay inside the translation unit that references them
    # (disasm.py's TU split never cuts a span mid-pool), so one forward pass
    # per file is enough to resolve every pool_XXXXXXXX label to its value.
    pool_value = {}
    for i, line in enumerate(lines):
        m = RE_THUNK_POOL_LABEL.match(line)
        if m and i + 1 < len(lines):
            wm = RE_THUNK_WORD.match(lines[i + 1])
            if wm:
                pool_value[int(m.group(1), 16)] = int(wm.group(1), 16)

    out = []
    i, n = 0, len(lines)
    while i < n:
        fm = RE_THUNK_FUNC.match(lines[i])
        if not fm:
            i += 1
            continue
        func_addr = int(fm.group(1), 16)
        j = i + 1
        if j < n and not lines[j]:
            j += 1
        lm = RE_THUNK_LDR.match(lines[j]) if j < n else None
        if not lm:
            i += 1
            continue
        reg, pool_addr_s = lm.group(1), lm.group(2)
        k = j + 1
        bm = RE_THUNK_BX.match(lines[k]) if k < n else None
        if not bm or bm.group(1) != reg:
            i += 1
            continue
        target = pool_value.get(int(pool_addr_s, 16))
        if target is not None:
            out.append((func_addr, target & ~1))
        i = k + 1
    return out


ITCM_UNITS_JSON = os.path.join(ROOT, "layout", "units_itcm.json")


def _unit_files(units_json_path):
    """Listing file paths straight from a units_*.json manifest.

    Reading the manifest's own file list, rather than globbing the split
    directory, matters here: disasm.py's split never deletes a previous
    run's leftover unit files when the cut points move, so a stale
    directory can hold overlapping .s files that would otherwise double- or
    triple-count the same thunk.
    """
    if not os.path.isfile(units_json_path):
        return []
    with open(units_json_path, encoding="utf-8") as fh:
        doc = json.load(fh)
    return [os.path.join(ROOT, u["file"].replace("/", os.sep))
           for u in doc["units"]]


def find_tail_call_thunks():
    """Every tail-call thunk image-wide: [{addr, target, region}], by addr."""
    thunks = []
    for path in _unit_files(UNITS_JSON) + _unit_files(ITCM_UNITS_JSON):
        for addr, target in _thunk_candidates_in_file(path):
            thunks.append({"addr": addr, "target": target, "region": "arm9"})
    for path in sorted(glob.glob(os.path.join(ROOT, "asm", "overlays", "*.s"))):
        base = os.path.basename(path)
        region = base[:-2] if base.endswith(".s") else base   # "ov010"
        for addr, target in _thunk_candidates_in_file(path):
            thunks.append({"addr": addr, "target": target, "region": region})
    thunks.sort(key=lambda t: t["addr"])
    return thunks


# ---------------------------------------------------------------- listings


class Item(object):
    """One sized thing in a listing: an instruction or a data directive."""

    __slots__ = ("addr", "size", "code")

    def __init__(self, addr, size, code):
        self.addr = addr
        self.size = size
        self.code = code


def parse_unit(path, base, size):
    """Parse one listing.

    Returns (funcs, items, edges, word_refs) where

      funcs      list of dicts with addr, isa, unit info, in address order
      items      list of Item in address order covering the whole unit
      edges      list of (source_func_addr_or_None, target_addr, mnemonic)
      word_refs  list of (source_func_addr_or_None, word_value)
    """
    funcs = []
    items = []
    edges = []
    word_refs = []

    cur = base
    cur_func = None
    pending_thumb_func = False
    mode = "arm"

    with open(path, encoding="utf-8") as fh:
        for raw in fh:
            line = raw.strip()
            if not line or line.startswith("/*") or line.startswith("*"):
                continue

            m = RE_LABEL.match(line)
            if m:
                fm = RE_FUNC_LABEL.match(line)
                if fm:
                    addr = int(fm.group(1), 16)
                    cur = addr
                    isa = "thumb" if pending_thumb_func else mode
                    funcs.append({"addr": addr, "isa": isa})
                    cur_func = addr
                    pending_thumb_func = False
                continue

            if line.startswith(".") and not line.startswith(".inst"):
                tok = line.split()[0]
                if tok == ".org":
                    om = RE_ORG.match(line)
                    if om:
                        cur = base + int(om.group(1), 0)
                    continue
                if tok == ".thumb_func":
                    pending_thumb_func = True
                    continue
                if tok == ".thumb":
                    mode = "thumb"
                    continue
                if tok == ".arm":
                    mode = "arm"
                    continue
                if tok in (".global", ".type", ".syntax", ".section", ".align", ".end"):
                    continue
                if tok in DATA_DIRECTIVES:
                    sz = data_size(tok, line)
                    am = RE_ADDR_BYTES.search(line)
                    if am:
                        cur = int(am.group(1), 16)
                    items.append(Item(cur, sz, False))
                    wm = RE_WORD_VALUE.match(line)
                    if wm:
                        word_refs.append((cur_func, int(wm.group(1), 16)))
                    cur += sz
                    continue
                # unknown directive with no width: ignore
                continue

            # instruction; .inst.n / .inst.w are raw encodings and count as code
            am = RE_ADDR_BYTES.search(line)
            if not am:
                continue
            cur = int(am.group(1), 16)
            byte_group = am.group(2)
            if byte_group:
                sz = len(byte_group.split())
            else:
                sz = 2 if mode == "thumb" else 4
            items.append(Item(cur, sz, True))

            mnem = line.split()[0].lower()
            for rm in RE_FUNC_REF.finditer(line.split("/*")[0]):
                edges.append((cur_func, int(rm.group(1), 16), mnem))
            cur += sz

    # .inst.n and friends start with '.' and were skipped above; recover them
    return funcs, items, edges, word_refs


def data_size(tok, line):
    body = line.split("/*")[0]
    body = body[len(tok):].strip()
    if tok == ".word":
        return 4 * max(1, len([x for x in body.split(",") if x.strip()]))
    if tok in (".short", ".hword"):
        return 2 * max(1, len([x for x in body.split(",") if x.strip()]))
    if tok == ".byte":
        return max(1, len([x for x in body.split(",") if x.strip()]))
    if tok == ".space":
        try:
            return int(body.split(",")[0], 0)
        except ValueError:
            return 0
    if tok in (".ascii", ".asciz"):
        # not emitted by disasm.py today; fall back to the address comment
        return 0
    return 0


def parse_all(units):
    funcs = []
    items = []
    edges = []
    word_refs = []
    for u in units["units"]:
        path = os.path.join(ROOT, u["file"].replace("/", os.sep))
        f, i, e, w = parse_unit(path, u["base"], u["size"])
        for fn in f:
            fn["unit"] = u["index"]
            fn["file"] = u["file"]
        funcs.extend(f)
        items.extend(i)
        edges.extend(e)
        word_refs.extend(w)
    funcs.sort(key=lambda x: x["addr"])
    items.sort(key=lambda x: x.addr)
    return funcs, items, edges, word_refs


# ---------------------------------------------------------------- inventory


def build_inventory():
    units = load_units()
    sdk = load_sdk_symbols()
    sdk_weak = load_sdk_overrulable()
    sdk_ext = load_sdk_extents()
    runtime = load_runtime_symbols()
    matched = load_matched()
    thunks = find_tail_call_thunks()
    funcs, items, edges, word_refs = parse_all(units)

    region_end = units["base"] + units["size"]

    # extents: a function runs to the next function label, per docs/MATCHING.md
    for idx, fn in enumerate(funcs):
        nxt = funcs[idx + 1]["addr"] if idx + 1 < len(funcs) else region_end
        fn["extent_end"] = nxt

    # walk the item list once, attributing code and data bytes to extents
    by_addr = {fn["addr"]: fn for fn in funcs}
    starts = [fn["addr"] for fn in funcs]
    for fn in funcs:
        fn["code_bytes"] = 0
        fn["data_bytes"] = 0
        fn["end"] = fn["addr"]

    import bisect

    for it in items:
        pos = bisect.bisect_right(starts, it.addr) - 1
        if pos < 0:
            continue
        fn = by_addr[starts[pos]]
        if it.addr >= fn["extent_end"]:
            continue
        if it.code:
            fn["code_bytes"] += it.size
            end = it.addr + it.size
            if end > fn["end"]:
                fn["end"] = end
        else:
            fn["data_bytes"] += it.size

    for fn in funcs:
        if fn["end"] <= fn["addr"]:
            fn["end"] = fn["extent_end"]
        fn["size"] = fn["end"] - fn["addr"]

    # data runs around each function, for the data-adjacent flag
    annotate_data_runs(funcs, items)

    # classification
    for fn in funcs:
        addr = fn["addr"]
        ment = matched.get(addr)
        proven_game = (ment is not None and ment["kind"] in ("game", "game_unit")
                       and (addr not in sdk or addr in sdk_weak))
        if addr in sdk and not proven_game:
            fn["cls"] = "sdk"
            fn["sdk_name"] = sdk[addr]
            if ment is not None:
                fn["matched_name"] = ment["name"]
        elif not proven_game and sdk_interior(sdk_ext, addr) is not None:
            # a label inside a sized SDK symbol: an interior kernel, not a
            # function (owner decision 2026-09-23, see load_sdk_extents)
            fn["cls"] = "sdk"
            fn["sdk_name"] = sdk_interior(sdk_ext, addr)
            fn["sdk_interior"] = True
            if ment is not None:
                fn["matched_name"] = ment["name"]
        elif addr in runtime and not proven_game:
            fn["cls"] = "runtime"
            fn["runtime_name"] = runtime[addr]
            if ment is not None:
                fn["matched_name"] = ment["name"]
        elif addr in matched:
            fn["cls"] = "matched"
            fn["matched_name"] = ment["name"]
            fn["matched_entry"] = ment["entry"]
            if ment.get("sole_ref"):
                # the entry that covers this function rests on the weakest
                # evidence class; the coverage line reports its share apart.
                fn["sole_ref"] = list(ment["sole_ref"])
            if ment.get("implied"):
                fn["matched_implied"] = True
            if addr in sdk:
                # libmatch.py put a weak SDK symbol here but match.py has since
                # proved the bytes are game code; the proof wins.
                fn["sdk_conflict"] = sdk[addr]
        else:
            fn["cls"] = "open"

    # cross reference graph
    callers = {}     # target addr -> set of source func addrs
    for src, tgt, _mn in edges:
        if tgt in by_addr and src is not None and src != tgt:
            callers.setdefault(tgt, set()).add(src)
    pointers = {}    # target addr -> set of source func addrs holding a pointer
    for src, val in word_refs:
        tgt = val & ~1
        if tgt in by_addr and src is not None and src != tgt:
            pointers.setdefault(tgt, set()).add(src)
    # sdk calls made from inside each function
    sdk_calls = {}   # source func addr -> set of sdk names
    for src, tgt, mn in edges:
        if src is None:
            continue
        if tgt in sdk and mn.startswith("b"):
            sdk_calls.setdefault(src, set()).add(sdk[tgt])
    for src, val in word_refs:
        tgt = val & ~1
        if src is not None and tgt in sdk and tgt in by_addr:
            sdk_calls.setdefault(src, set()).add(sdk[tgt])

    return {
        "units": units,
        "funcs": funcs,
        "by_addr": by_addr,
        "sdk": sdk,
        "runtime": runtime,
        "matched": matched,
        "callers": callers,
        "pointers": pointers,
        "sdk_calls": sdk_calls,
        "region_end": region_end,
        "thunks": thunks,
    }


def annotate_data_runs(funcs, items):
    """Record the contiguous data run before each function and after its extent."""
    # build a compact run list: (start, end, is_code)
    runs = []
    for it in items:
        if runs and runs[-1][2] == it.code and runs[-1][1] == it.addr:
            runs[-1][1] = it.addr + it.size
        else:
            runs.append([it.addr, it.addr + it.size, it.code])

    starts = [r[0] for r in runs]
    import bisect

    def data_run_covering(addr):
        pos = bisect.bisect_right(starts, addr) - 1
        if pos < 0 or pos >= len(runs):
            return 0
        r = runs[pos]
        if r[2] or addr >= r[1]:
            return 0
        return r[1] - r[0]

    for fn in funcs:
        # the run that ends where the function starts, and the run that begins
        # where its code stops (literal pool, then whatever data follows it
        # before the next function label)
        before = data_run_covering(fn["addr"] - 1)
        after = data_run_covering(fn["end"])
        fn["data_before"] = before
        fn["data_after"] = after
        fn["data_adjacent"] = (
            before >= DATA_ADJACENT_BYTES or after >= DATA_ADJACENT_BYTES
        )


def load_proc_hints():
    """{packet_id: proc} for every packet row in layout/proc_hints.txt.

    tools/procscan.py classifies every ARM function's epilogue (pop into
    pc vs. restore-lr-then-bx-lr, see
    docs/idioms/an-arm-epilogue-of-pop-lr-then-bx-names-a-proc-arm7tdmi-unit.md)
    and aggregates a -proc verdict per packet there. A packet whose proc
    here is not "arm946e" (the pinned default) means an agent should pass
    that -proc from its first compile instead of discovering the DIFF the
    slow way. Missing file or missing row means no hint, not an error:
    this tool works fine without ever having run tools/procscan.py.
    """
    hints = {}
    if not os.path.isfile(PROC_HINTS):
        return hints
    with open(PROC_HINTS, encoding="utf-8") as fh:
        for line in fh:
            if not line.strip() or line.startswith("#"):
                continue
            parts = line.split()
            if len(parts) < 3 or parts[0] != "packet":
                continue
            hints[parts[1]] = parts[-1]
    return hints


# ---------------------------------------------------------------- packets


def packet_id(addr):
    return "pkt_%08X" % addr


def group_packets(inv, pinned_ranges=()):
    """Group open functions into packets, skipping pinned address ranges."""
    funcs = inv["funcs"]
    open_funcs = [f for f in funcs if f["cls"] == "open"]

    def is_pinned(addr):
        for lo, hi in pinned_ranges:
            if lo <= addr < hi:
                return True
        return False

    free = [f for f in open_funcs if not is_pinned(f["addr"])]

    idx_of = {f["addr"]: i for i, f in enumerate(funcs)}

    packets = []
    cur = []
    cur_code = 0

    def flush():
        if cur:
            packets.append(list(cur))

    prev = None
    for fn in free:
        brk = False
        if cur:
            # foreign territory between prev and fn?
            lo = idx_of[prev["addr"]] + 1
            hi = idx_of[fn["addr"]]
            for k in range(lo, hi):
                if funcs[k]["cls"] != "open" or is_pinned(funcs[k]["addr"]):
                    brk = True
                    break
            # large data gap
            if not brk and fn["addr"] - prev["end"] > GAP_SPLIT_BYTES:
                brk = True
            # size targets
            if not brk and (len(cur) >= SOFT_MAX_FUNCS or cur_code >= SOFT_MAX_CODE):
                brk = True
        if brk:
            flush()
            cur = []
            cur_code = 0
        cur.append(fn)
        cur_code += fn["code_bytes"]
        prev = fn
    flush()

    return [make_packet(inv, group) for group in packets]


def make_packet(inv, group):
    addrs = set(f["addr"] for f in group)
    start = group[0]["addr"]
    end = group[-1]["extent_end"]

    fn_entries = []
    sdk_call_names = set()
    for f in group:
        fn_entries.append(
            {
                "addr": hexa(f["addr"]),
                "end": hexa(f["end"]),
                "size": f["size"],
                "code": f["code_bytes"],
                "isa": f["isa"],
                "unit": f["unit"],
                "data_adjacent": bool(f["data_adjacent"]),
            }
        )
        sdk_call_names |= inv["sdk_calls"].get(f["addr"], set())

    callers_out = set()
    pointer_out = set()
    for f in group:
        for src in inv["callers"].get(f["addr"], ()):
            if src not in addrs:
                callers_out.add(src)
        for src in inv["pointers"].get(f["addr"], ()):
            if src not in addrs:
                pointer_out.add(src)

    entry_points = sorted(
        hexa(f["addr"])
        for f in group
        if (inv["callers"].get(f["addr"], set()) | inv["pointers"].get(f["addr"], set()))
        - addrs
    )

    units = sorted(set(f["unit"] for f in group))
    files = sorted(set(f["file"] for f in group))

    return {
        "id": packet_id(start),
        "status": "open",
        "start": hexa(start),
        # end is the last function's extent (the next function label anywhere
        # in the listing), which is what makes packets provably disjoint; a
        # packet whose last function is followed by a long data region has an
        # end far past its code.  code_end is where its last instruction stops.
        "end": hexa(end),
        "code_end": hexa(group[-1]["end"]),
        "units": units,
        "files": files,
        "function_count": len(group),
        "code_bytes": sum(f["code_bytes"] for f in group),
        "extent_bytes": end - start,
        "isa": sole_isa(group),
        "data_adjacent_count": sum(1 for f in group if f["data_adjacent"]),
        "sdk_calls": sorted(sdk_call_names),
        "external_callers": len(callers_out),
        "external_pointer_refs": len(pointer_out),
        "entry_points": entry_points,
        "functions": fn_entries,
    }


def sole_isa(group):
    kinds = set(f["isa"] for f in group)
    if len(kinds) == 1:
        return kinds.pop()
    return "mixed"


# ---------------------------------------------------------------- document


def build_document(inv, packets):
    funcs = inv["funcs"]
    counts = {"total": len(funcs), "sdk": 0, "runtime": 0, "matched": 0, "open": 0}
    bytes_by = {"sdk": 0, "runtime": 0, "matched": 0, "open": 0}
    sdk_matched = 0
    sdk_matched_bytes = 0
    sdk_conflicts = []
    for f in funcs:
        counts[f["cls"]] += 1
        bytes_by[f["cls"]] += f["code_bytes"]
        if f["cls"] == "sdk" and "matched_name" in f:
            sdk_matched += 1
            sdk_matched_bytes += f["code_bytes"]
        if "sdk_conflict" in f:
            sdk_conflicts.append(
                {
                    "addr": hexa(f["addr"]),
                    "sdk_name": f["sdk_conflict"],
                    "matched_name": f["matched_name"],
                }
            )

    game_bytes = bytes_by["matched"] + bytes_by["open"]
    coverage = (100.0 * bytes_by["matched"] / game_bytes) if game_bytes else 0.0

    # The share of the matched coverage that rests on the `sole-ref` class,
    # counted over the entries whose manifest record names at least one such
    # site.  Reported apart from the coverage figure, never folded into it.
    sole_funcs = [f for f in funcs
                  if f["cls"] == "matched" and f.get("sole_ref")]
    sole_bytes = sum(f["code_bytes"] for f in sole_funcs)
    sole_points = (100.0 * sole_bytes / game_bytes) if game_bytes else 0.0

    # Break that share down by sub-kind ("data"/"code"/"string"/"self",
    # the 2026-09-21 widening and the `self` sub-kind added with it): a
    # function whose sole_ref list names more than one sub-kind is counted
    # once in each sub-kind's function/byte total, exactly as it is already
    # counted once in the un-broken-down total above, so the sub-kind
    # totals do not have to sum to it.
    sole_by_kind = {}
    for sk in SOLE_REF_SUBKINDS:
        sk_funcs = [f for f in sole_funcs
                    if any(sole_ref_subkind(it) == sk
                           for it in f["sole_ref"])]
        sk_bytes = sum(f["code_bytes"] for f in sk_funcs)
        sole_by_kind[sk] = {
            "functions": len(sk_funcs),
            "code_bytes": sk_bytes,
            "coverage_percent": round(
                (100.0 * sk_bytes / game_bytes) if game_bytes else 0.0, 4),
        }

    packet_map = {}
    for p in packets:
        packet_map[p["id"]] = p

    return {
        "tool": "tools/worklist.py",
        "version": 1,
        "note": (
            "parallel work territory for arm9_main: addresses, sizes, symbol "
            "names and counts only, no game data"
        ),
        "region": "arm9_main",
        "base": inv["units"]["base"],
        "size": inv["units"]["size"],
        "policy": {
            "classification": "sdk > runtime > matched > open",
            "soft_max_funcs": SOFT_MAX_FUNCS,
            "soft_max_code_bytes": SOFT_MAX_CODE,
            "gap_split_bytes": GAP_SPLIT_BYTES,
            "data_adjacent_bytes": DATA_ADJACENT_BYTES,
            "statuses": ["open", "claimed:<agent>", "done", "blocked"],
        },
        "summary": {
            "functions_total": counts["total"],
            "functions_sdk": counts["sdk"],
            "functions_sdk_also_matched": sdk_matched,
            "code_bytes_sdk_also_matched": sdk_matched_bytes,
            "functions_runtime": counts["runtime"],
            "functions_matched": counts["matched"],
            "functions_open": counts["open"],
            "code_bytes_sdk": bytes_by["sdk"],
            "code_bytes_runtime": bytes_by["runtime"],
            "code_bytes_matched": bytes_by["matched"],
            "code_bytes_open": bytes_by["open"],
            "code_bytes_game": game_bytes,
            "packets": len(packets),
            "coverage_percent": round(coverage, 4),
            "functions_sole_ref": len(sole_funcs),
            "code_bytes_sole_ref": sole_bytes,
            "coverage_percent_sole_ref": round(sole_points, 4),
            "sole_ref_by_subkind": sole_by_kind,
            "sdk_conflicts": sdk_conflicts,
        },
        "thunks": inv["thunks"],
        "packets": packet_map,
    }


ORCHESTRATOR_KEYS_SKIP = {
    "id",
    "start",
    "end",
    "code_end",
    "units",
    "files",
    "function_count",
    "code_bytes",
    "extent_bytes",
    "isa",
    "data_adjacent_count",
    "sdk_calls",
    "external_callers",
    "external_pointer_refs",
    "entry_points",
    "functions",
}


def refresh(inv, old_doc):
    """Regroup while pinning packets whose function sets are unchanged."""
    funcs = inv["funcs"]
    open_by_addr = {f["addr"]: f for f in funcs if f["cls"] == "open"}
    open_addrs = sorted(open_by_addr)

    import bisect

    pinned = []
    dissolved = []
    for pid, old in sorted(
        (old_doc.get("packets") or {}).items(), key=lambda kv: kv[1]["start"]
    ):
        try:
            want = [int(f["addr"], 16) for f in old["functions"]]
            lo = int(old["start"], 16)
            hi = int(old["end"], 16)
        except (KeyError, ValueError, TypeError):
            dissolved.append((pid, "malformed entry"))
            continue
        missing = [a for a in want if a not in open_by_addr]
        if missing:
            stale = []
            for a in missing:
                ment = inv["matched"].get(a)
                if ment is not None and ment.get("implied"):
                    stale.append(
                        "%s now matched under %s (stale packet id)"
                        % (hexa(a), ment["entry"])
                    )
            if stale:
                dissolved.append((pid, "; ".join(stale)))
            else:
                dissolved.append(
                    (pid, "%d function(s) no longer open, first %s"
                     % (len(missing), hexa(missing[0])))
                )
            continue
        i = bisect.bisect_left(open_addrs, lo)
        j = bisect.bisect_left(open_addrs, hi)
        now = open_addrs[i:j]
        if now != sorted(want):
            dissolved.append((pid, "function set changed inside the range"))
            continue
        pinned.append((pid, old, lo, hi, sorted(want)))

    pinned_ranges = [(lo, hi) for _pid, _old, lo, hi, _w in pinned]
    fresh = group_packets(inv, pinned_ranges)

    packets = []
    for pid, old, lo, hi, want in pinned:
        group = [open_by_addr[a] for a in want]
        rebuilt = make_packet(inv, group)
        rebuilt["id"] = pid          # keep the id even if the start moved
        for key, value in old.items():
            if key not in ORCHESTRATOR_KEYS_SKIP:
                rebuilt[key] = value  # status and anything else the orchestrator added
        packets.append(rebuilt)
    packets.extend(fresh)
    packets.sort(key=lambda p: int(p["start"], 16))
    return packets, [pid for pid, _why in dissolved], dissolved


# ---------------------------------------------------------------- emit


def dump(doc, path):
    """Write merge-friendly JSON: one packet per line, stable key order."""
    out = []
    out.append("{")
    head = ["tool", "version", "note", "region", "base", "size", "policy",
           "summary", "thunks"]
    for key in head:
        out.append(' %s: %s,' % (json.dumps(key), json.dumps(doc[key], sort_keys=True)))
    out.append(' "packets": {')
    ids = sorted(doc["packets"], key=lambda k: int(doc["packets"][k]["start"], 16))
    for i, pid in enumerate(ids):
        comma = "" if i == len(ids) - 1 else ","
        out.append(
            "  %s: %s%s"
            % (json.dumps(pid), json.dumps(doc["packets"][pid], sort_keys=True), comma)
        )
    out.append(" }")
    out.append("}")
    text = "\n".join(out) + "\n"
    with open(path, "w", encoding="utf-8", newline="\n") as fh:
        fh.write(text)
    return text


def print_summary(doc):
    s = doc["summary"]
    print("arm9_main work territory")
    print("  functions total          %6d" % s["functions_total"])
    print(
        "  SDK excluded             %6d  (%5.1f%%)  %d bytes of code"
        % (
            s["functions_sdk"],
            100.0 * s["functions_sdk"] / max(1, s["functions_total"]),
            s["code_bytes_sdk"],
        )
    )
    print(
        "    of which matched SDK   %6d              %d bytes of code"
        % (s["functions_sdk_also_matched"], s.get("code_bytes_sdk_also_matched", 0))
    )
    print(
        "  runtime excluded         %6d              %d bytes of code"
        % (s["functions_runtime"], s["code_bytes_runtime"])
    )
    print(
        "  matched so far           %6d              %d bytes of code"
        % (s["functions_matched"], s["code_bytes_matched"])
    )
    print(
        "  open                     %6d              %d bytes of code"
        % (s["functions_open"], s["code_bytes_open"])
    )
    if s.get("sdk_conflicts"):
        print(
            "  SDK symbols overruled    %6d  (matched game code at an SDK address)"
            % len(s["sdk_conflicts"])
        )
        for c in s["sdk_conflicts"]:
            print("      %s  %s  ->  %s" % (c["addr"], c["sdk_name"], c["matched_name"]))
    thunks = doc.get("thunks") or []
    if thunks:
        print("  tail-call thunks         %6d  (ldr+bx forwarders; see"
              % len(thunks))
        print("    docs/idioms/tail-call-is-a-pool-word-and-bx.md; their "
              "callers count as callers of the target for fan-in)")
        shown = thunks if len(thunks) <= THUNK_PRINT_LIMIT else thunks[:THUNK_PRINT_LIMIT]
        for t in shown:
            print("      %-6s 0x%08X  ->  0x%08X"
                  % (t["region"], t["addr"], t["target"]))
        if len(thunks) > THUNK_PRINT_LIMIT:
            print("      ... %d more; see layout/worklist.json \"thunks\""
                  % (len(thunks) - THUNK_PRINT_LIMIT))
    print("  packets                  %6d" % s["packets"])
    print(
        "  coverage by bytes        %8.4f%%  (%d / %d game code bytes)"
        % (s["coverage_percent"], s["code_bytes_matched"], s["code_bytes_game"])
    )
    print(
        "    of which resting on sole-ref: %d bytes (%.4f percent points), "
        "%d function(s)"
        % (
            s.get("code_bytes_sole_ref", 0),
            s.get("coverage_percent_sole_ref", 0.0),
            s.get("functions_sole_ref", 0),
        )
    )
    by_kind = s.get("sole_ref_by_subkind") or {}
    if by_kind:
        parts = []
        for sk in SOLE_REF_SUBKINDS:
            row = by_kind.get(sk) or {}
            parts.append(
                "%s: %d bytes (%.4f pts), %d fn"
                % (sk, row.get("code_bytes", 0),
                   row.get("coverage_percent", 0.0),
                   row.get("functions", 0))
            )
        print("      by sub-kind -- " + "; ".join(parts))
    if s["packets"]:
        sizes = [p["function_count"] for p in doc["packets"].values()]
        codes = [p["code_bytes"] for p in doc["packets"].values()]
        print(
            "  packet shape             %d..%d functions, %d..%d code bytes, "
            "median %d functions"
            % (
                min(sizes),
                max(sizes),
                min(codes),
                max(codes),
                sorted(sizes)[len(sizes) // 2],
            )
        )
        byst = {}
        for p in doc["packets"].values():
            byst[p.get("status", "open")] = byst.get(p.get("status", "open"), 0) + 1
        print(
            "  packet status            "
            + ", ".join("%s=%d" % kv for kv in sorted(byst.items()))
        )


def print_packet(doc, pid, open_only=False):
    p = doc["packets"].get(pid)
    if p is None:
        print("no such packet: %s" % pid, file=sys.stderr)
        return 1
    # A packet's range is listed IN FULL whether or not a manifest entry already covers each
    # function. Picking targets from that list without the state below is how a lane re-derives
    # work that is already filed, so annotate every line and state the counts.
    matched = load_matched()
    n_matched = sum(1 for f in p["functions"] if int(f["addr"], 16) in matched)
    print(
        "%s  %s  %s..%s (code ends %s)"
        % (p["id"], p["status"], p["start"], p["end"], p.get("code_end", p["end"]))
    )
    print(
        "  %d functions, %d code bytes, isa %s, units %s"
        % (p["function_count"], p["code_bytes"], p["isa"], p["units"])
    )
    print("  files: %s" % ", ".join(p["files"]))
    proc = load_proc_hints().get(pid, "arm946e")
    if proc != "arm946e":
        print(
            "  proc hint: %s (tools/procscan.py; not the pinned arm946e -- "
            "pass -proc %s from the first compile, see layout/proc_hints.txt)"
            % (proc, proc)
        )
    print(
        "  external callers %d, external pointer refs %d, data-adjacent %d"
        % (p["external_callers"], p["external_pointer_refs"], p["data_adjacent_count"])
    )
    if p["sdk_calls"]:
        print("  SDK calls: %s" % ", ".join(p["sdk_calls"]))
    if p["entry_points"]:
        print("  entry points: %s" % ", ".join(p["entry_points"]))
    lo, hi = int(p["start"], 16), int(p["end"], 16)
    anchors = [a for a in load_file_anchors() if lo <= a[0] < hi]
    if anchors:
        print("  file anchors (__FILE__ pool words, see layout/file_anchors.txt):")
        for site, name in anchors:
            print("    0x%08X  %s" % (site, name))
    for f in p["functions"]:
        is_matched = int(f["addr"], 16) in matched
        if open_only and is_matched:
            continue
        print(
            "    %s  %-5s %5d bytes code %4d  %s%s"
            % (
                f["addr"],
                f["isa"],
                f["size"],
                f["code"],
                "matched" if is_matched else "OPEN   ",
                "  data-adjacent" if f["data_adjacent"] else "",
            )
        )
    print(
        "  %d of %d function(s) already covered by a manifest entry, %d open%s"
        % (
            n_matched,
            p["function_count"],
            p["function_count"] - n_matched,
            " (only OPEN lines are work)" if p["function_count"] != n_matched else "",
        )
    )
    return 0


# ---------------------------------------------------------------- targets
#
# --targets ranks OPEN functions by attestation-weighted fan-in, so an agent
# picking a fresh packet can see which open addresses would unlock the most
# other work first.  Two signals feed the score:
#
#   fan_in         every branch reference to the address anywhere in the
#                  image (arm9 + all 237 overlays).  This reuses match.py's
#                  own cross-region call index (image_call_sites) rather than
#                  re-deriving it from the arm9-only edges build_inventory()
#                  already parses for the packet-internal external_callers
#                  count, since that index does not see overlay callers.
#   unlock_weight  how many files under src/pending/ name this address in
#                  their header comment, read as a heuristic for "decompiling
#                  this address removes a blocker for a MATCH-capped file
#                  that is otherwise done".  This is a plain regex over
#                  0x02...... tokens in each header's text (up to the first
#                  "*/"), not a semantic parse of the prose: it will pick up
#                  any address mentioned for any reason, not only ones
#                  actually named as the missing witness.  A pending file's
#                  own "address:" line is excluded so it never counts as its
#                  own blocker.
#
# score = fan_in + 5 * unlock_weight, unlock evidence weighted higher because
# it names a concrete file sitting at MATCH for lack of exactly this address.
#
# fan_in also counts a tail-call thunk's own callers against its target (see
# find_tail_call_thunks): a `bl` to the thunk never shows up against the
# target in image_call_sites, since the thunk forwards with a pool word and
# a `bx`, not a branch.
#
# The printed "guess" column prefers the nearest __FILE__ pool anchor inside
# the same packet (layout/file_anchors.txt, tools/fileanchors.py) over the
# nearby-matched-neighbour subsystem heuristic below: an anchor is compiler-
# emitted evidence of which translation unit a block of code came from, not
# a guess by proximity.

PENDING_DIR = os.path.join(ROOT, "src", "pending")

RE_PENDING_ADDR = re.compile(r"0x(02[0-9A-Fa-f]{6})")
RE_PENDING_OWN_ADDR = re.compile(r"address:\s*0x([0-9A-Fa-f]{8})")
RE_SUBSYSTEM_NAME = re.compile(r"\n\s*\*\s+([a-z_][a-z0-9_]*\.c):")


def load_pending_unlock_weights():
    """address (int) -> number of src/pending/*.c headers that name it.

    Heuristic, documented above: a plain 0x02...... regex over each pending
    file's header comment, excluding that file's own address.
    """
    weights = {}
    if not os.path.isdir(PENDING_DIR):
        return weights
    for fname in sorted(os.listdir(PENDING_DIR)):
        if not fname.endswith(".c"):
            continue
        path = os.path.join(PENDING_DIR, fname)
        with open(path, encoding="utf-8", errors="replace") as fh:
            text = fh.read()
        header_end = text.find("*/")
        header = text[:header_end] if header_end != -1 else text
        own_m = RE_PENDING_OWN_ADDR.search(header)
        own = int(own_m.group(1), 16) if own_m else None
        named = set()
        for m in RE_PENDING_ADDR.finditer(header):
            addr = int(m.group(1), 16)
            if addr == own:
                continue
            named.add(addr)
        for addr in named:
            weights[addr] = weights.get(addr, 0) + 1
    return weights


def load_matched_sources():
    """sorted [(address, source_path)] for every matched arm9 function.

    Read straight from match.load_manifest_entries() (the same reader
    load_matched() uses), kept separate because the subsystem guess needs
    the source file path, which the address-only cover map does not carry.
    """
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import match  # noqa: E402

    out = []
    for ent in match.load_manifest_entries():
        if ent.get("region") != REGION:
            continue
        src = ent.get("source")
        if not src:
            continue
        addrs = []
        if ent.get("address"):
            addrs.append(int(ent["address"], 16))
        for member in ent.get("functions", []) or []:
            m = re.search(r"([0-9A-Fa-f]{8})$", member)
            if m:
                addrs.append(int(m.group(1), 16))
        for addr in addrs:
            out.append((addr, src))
    out.sort(key=lambda pair: pair[0])
    return out


_SUBSYSTEM_NAME_CACHE = {}


def subsystem_name_of(source_path):
    """The '<name>.c:' subsystem tag a matched file's prose names, if any.

    Several src/matched/ headers open a paragraph with a line like
    ' * waza_tool.c: ...', naming the conceptual subsystem the function
    belongs to even though the file itself is unit_ADDRESS.c.  Not every
    matched file has one; this returns None when it doesn't.
    """
    if source_path in _SUBSYSTEM_NAME_CACHE:
        return _SUBSYSTEM_NAME_CACHE[source_path]
    name = None
    full = os.path.join(ROOT, source_path.replace("/", os.sep))
    try:
        with open(full, encoding="utf-8", errors="replace") as fh:
            text = fh.read(4000)
    except OSError:
        text = ""
    m = RE_SUBSYSTEM_NAME.search(text)
    if m:
        name = m.group(1)
    _SUBSYSTEM_NAME_CACHE[source_path] = name
    return name


NEARBY_SUBSYSTEM_BYTES = 0x4000


def nearby_subsystem_guess(addr, matched_sources):
    """The subsystem name of the nearest matched neighbour, if one names one.

    Walks outward from the bisection point in both directions (closest
    address first) up to NEARBY_SUBSYSTEM_BYTES away, stopping at the first
    matched neighbour whose source file actually names a subsystem; most
    matched files don't, so this often has to look past the single nearest
    one.
    """
    import bisect

    addrs = [a for a, _src in matched_sources]
    i = bisect.bisect_left(addrs, addr)
    lo, hi = i - 1, i
    while lo >= 0 or hi < len(matched_sources):
        left_d = addr - addrs[lo] if lo >= 0 else None
        right_d = addrs[hi] - addr if hi < len(matched_sources) else None
        if left_d is not None and (right_d is None or left_d <= right_d):
            cand_addr, cand_src = matched_sources[lo]
            step = "lo"
        else:
            cand_addr, cand_src = matched_sources[hi]
            step = "hi"
        dist = abs(cand_addr - addr)
        if dist > NEARBY_SUBSYSTEM_BYTES:
            return None
        name = subsystem_name_of(cand_src)
        if name:
            return name
        if step == "lo":
            lo -= 1
        else:
            hi += 1
    return None


def build_targets(doc, limit):
    """Rank open, non-SDK functions by attestation-weighted fan-in.

    Reads the packet/function inventory straight from `doc` (the same
    structure --summary and --packet already read), so a stale
    layout/worklist.json is exactly as stale here as it is for those two
    modes: run --refresh first if that matters.

    fan_in also folds in tail-call thunks (see find_tail_call_thunks): a
    `bl`/`b` to a thunk's address never shows up against the thunk's target
    in match.image_call_sites(), because the thunk forwards with a pool word
    and a `bx`, not a branch. Every thunk whose target is this address adds
    its own caller count on top.

    guess prefers the nearest __FILE__ pool anchor (layout/file_anchors.txt,
    tools/fileanchors.py) inside the same packet as the target address, over
    the coarser nearby-matched-neighbour heuristic: an anchor is a real
    compiler-emitted attestation of a translation unit, not a guess by
    proximity, so it wins whenever the packet has one.
    """
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import match  # noqa: E402

    unlock_weights = load_pending_unlock_weights()

    thunk_callers_of = {}
    for t in doc.get("thunks") or []:
        thunk_callers_of.setdefault(t["target"], []).append(t["addr"])

    rows = []
    for pkt in doc["packets"].values():
        pid = pkt["id"]
        for f in pkt["functions"]:
            addr = int(f["addr"], 16)
            fan_in = len(match.image_call_sites(addr))
            for thunk_addr in thunk_callers_of.get(addr, ()):
                fan_in += len(match.image_call_sites(thunk_addr))
            unlock = unlock_weights.get(addr, 0)
            score = fan_in + 5 * unlock
            rows.append(
                {
                    "addr": addr,
                    "size": f["size"],
                    "packet": pid,
                    "fan_in": fan_in,
                    "unlock_weight": unlock,
                    "score": score,
                }
            )

    rows.sort(key=lambda r: (-r["score"], -r["fan_in"], r["addr"]))
    top = rows[:limit]

    matched_sources = load_matched_sources()
    anchors = load_file_anchors()
    for r in top:
        pkt = doc["packets"][r["packet"]]
        lo, hi = int(pkt["start"], 16), int(pkt["end"], 16)
        in_pkt = [(site, name) for site, name in anchors if lo <= site < hi]
        if in_pkt:
            _site, name = min(in_pkt, key=lambda sn: abs(sn[0] - r["addr"]))
            r["guess"] = name
        else:
            r["guess"] = nearby_subsystem_guess(r["addr"], matched_sources) or ""

    return top


def print_targets(doc, limit):
    top = build_targets(doc, limit)
    proc_hints = load_proc_hints()
    print("top %d open targets by attestation-weighted fan-in" % len(top))
    print(
        "  %-12s %6s  %-14s %8s %7s %7s %7s  %s"
        % ("address", "size", "packet", "proc", "fan_in", "unlock", "score", "guess")
    )
    for r in top:
        proc = proc_hints.get(r["packet"], "arm946e")
        print(
            "  %-12s %6d  %-14s %8s %7d %7d %7d  %s"
            % (
                hexa(r["addr"]),
                r["size"],
                r["packet"],
                proc if proc != "arm946e" else "",
                r["fan_in"],
                r["unlock_weight"],
                r["score"],
                r["guess"],
            )
        )
    return 0


# ---------------------------------------------------------------- main


def main(argv=None):
    ap = argparse.ArgumentParser(
        description="build and refresh the parallel decompilation work territory"
    )
    ap.add_argument("--refresh", action="store_true",
                    help="recompute while preserving packet statuses and boundaries")
    ap.add_argument("--summary", action="store_true",
                    help="print the coverage summary and exit")
    ap.add_argument("--packet", metavar="ID", help="print one packet in detail")
    ap.add_argument("--open-only", action="store_true",
                    help="with --packet, list only functions no manifest entry covers")
    ap.add_argument("--targets", nargs="?", const=30, type=int, default=None,
                    metavar="N",
                    help="print the top N open functions by attestation-"
                         "weighted fan-in (default 30)")
    ap.add_argument("--force", action="store_true",
                    help="rebuild from scratch, discarding every packet status")
    ap.add_argument("--out", default=OUT_JSON, help="output path")
    ap.add_argument("--check", action="store_true",
                    help="report whether a refresh would change the file, write nothing")
    args = ap.parse_args(argv)

    have_old = os.path.exists(args.out)

    if args.summary or args.packet or args.targets is not None or args.open_only:
        if have_old:
            with open(args.out, encoding="utf-8") as fh:
                doc = json.load(fh)
        else:
            inv = build_inventory()
            doc = build_document(inv, group_packets(inv))
        if args.packet:
            return print_packet(doc, args.packet, open_only=args.open_only)
        if args.open_only:
            print("--open-only needs --packet ID", file=sys.stderr)
            return 2
        if args.targets is not None:
            return print_targets(doc, args.targets)
        print_summary(doc)
        return 0

    inv = build_inventory()

    dissolved = []
    if (args.refresh or args.check) and have_old and not args.force:
        with open(args.out, encoding="utf-8") as fh:
            old_doc = json.load(fh)
        packets, _ids, dissolved = refresh(inv, old_doc)
    else:
        if have_old and not (args.force or args.refresh):
            print(
                "%s already exists; use --refresh to keep packet statuses or "
                "--force to discard them" % os.path.relpath(args.out, ROOT),
                file=sys.stderr,
            )
            return 2
        packets = group_packets(inv)

    doc = build_document(inv, packets)

    if args.check:
        text = json.dumps(doc, sort_keys=True)
        if dissolved:
            print("%d packet(s) would be stale after a refresh:" % len(dissolved))
            for pid, why in dissolved:
                print("  %s  %s" % (pid, why))
        if have_old:
            with open(args.out, encoding="utf-8") as fh:
                same = json.dumps(json.load(fh), sort_keys=True) == text
            print("unchanged" if same else "would change")
            return 0 if same else 1
        print("would create")
        return 1

    dump(doc, args.out)
    print("wrote %s" % os.path.relpath(args.out, ROOT))
    if dissolved:
        print("dissolved %d packet(s) whose territory moved:" % len(dissolved))
        for pid, why in dissolved:
            print("  %s  %s" % (pid, why))
    print_summary(doc)
    return 0


if __name__ == "__main__":
    sys.exit(main())
