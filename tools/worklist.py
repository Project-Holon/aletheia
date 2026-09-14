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
  layout/units_arm9.json  translation unit file order, base addresses, sizes
  layout/symbols_sdk.txt  SDK symbols recovered by tools/libmatch.py
  layout/matched/         manifest shards, one per work packet, read through
                          match.load_manifest_entries

Output
------
  layout/worklist.json    inventory summary plus one entry per work packet

Classification
--------------
Precedence is sdk > matched > open, with one documented exception:

  sdk       the function's address carries an SDK symbol in symbols_sdk.txt
            for region arm9.  These come from hybrid library linking and are
            NOT decompilation targets.  A handful of them are also listed in
            the manifest as sdk_calibration entries; those stay classified
            sdk and are counted separately as sdk_matched.
  matched   covered by a manifest entry, either directly or as a member of a
            game_unit entry's function list.  Read only.
  open      everything else.  These are the decompilation targets and the
            only functions that end up inside packets.

The exception: when an address carries both an SDK symbol and a matched
entry of kind game or game_unit, the matched entry wins and the function is
classified matched, with the losing SDK name recorded as sdk_conflict.
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
  python tools/worklist.py --packet ID      print one packet in detail
"""

import argparse
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

UNITS_JSON = os.path.join(ROOT, "layout", "units_arm9.json")
SYMBOLS_SDK = os.path.join(ROOT, "layout", "symbols_sdk.txt")
MATCHED_DIR = os.path.join(ROOT, "layout", "matched")
OUT_JSON = os.path.join(ROOT, "layout", "worklist.json")

REGION = "arm9"

# packet shaping
SOFT_MAX_FUNCS = 30          # inside the 20-40 band
SOFT_MAX_CODE = 3072         # inside the 2-4 KB band
GAP_SPLIT_BYTES = 0x200      # non-code run that forces a break
DATA_ADJACENT_BYTES = 0x100  # data run that earns the data-adjacent flag

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


def load_matched():
    """address -> dict(name, entry, kind) for everything the shards cover.

    The manifest is sharded (layout/matched/<region>/<packet>.json), and
    match.load_manifest_entries is its one reader: reading the files here as
    well would mean two implementations of the shard union and of the check
    that refuses a stale pre-shard layout/matched.json.
    """
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import match  # noqa: E402

    cover = {}
    for ent in match.load_manifest_entries():
        if ent.get("region") != REGION:
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
        for addr, who in addrs:
            cover.setdefault(addr, {"name": who, "entry": name, "kind": kind})
    return cover


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
    matched = load_matched()
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
        proven_game = ment is not None and ment["kind"] in ("game", "game_unit")
        if addr in sdk and not proven_game:
            fn["cls"] = "sdk"
            fn["sdk_name"] = sdk[addr]
            if ment is not None:
                fn["matched_name"] = ment["name"]
        elif addr in matched:
            fn["cls"] = "matched"
            fn["matched_name"] = ment["name"]
            fn["matched_entry"] = ment["entry"]
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
        "matched": matched,
        "callers": callers,
        "pointers": pointers,
        "sdk_calls": sdk_calls,
        "region_end": region_end,
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
    counts = {"total": len(funcs), "sdk": 0, "matched": 0, "open": 0}
    bytes_by = {"sdk": 0, "matched": 0, "open": 0}
    sdk_matched = 0
    sdk_conflicts = []
    for f in funcs:
        counts[f["cls"]] += 1
        bytes_by[f["cls"]] += f["code_bytes"]
        if f["cls"] == "sdk" and "matched_name" in f:
            sdk_matched += 1
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
            "classification": "sdk > matched > open",
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
            "functions_matched": counts["matched"],
            "functions_open": counts["open"],
            "code_bytes_sdk": bytes_by["sdk"],
            "code_bytes_matched": bytes_by["matched"],
            "code_bytes_open": bytes_by["open"],
            "code_bytes_game": game_bytes,
            "packets": len(packets),
            "coverage_percent": round(coverage, 4),
            "sdk_conflicts": sdk_conflicts,
        },
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
    head = ["tool", "version", "note", "region", "base", "size", "policy", "summary"]
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
        "    of which calibrated    %6d  (manifest sdk_calibration entries)"
        % s["functions_sdk_also_matched"]
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
    print("  packets                  %6d" % s["packets"])
    print(
        "  coverage by bytes        %8.4f%%  (%d / %d game code bytes)"
        % (s["coverage_percent"], s["code_bytes_matched"], s["code_bytes_game"])
    )
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


def print_packet(doc, pid):
    p = doc["packets"].get(pid)
    if p is None:
        print("no such packet: %s" % pid, file=sys.stderr)
        return 1
    print(
        "%s  %s  %s..%s (code ends %s)"
        % (p["id"], p["status"], p["start"], p["end"], p.get("code_end", p["end"]))
    )
    print(
        "  %d functions, %d code bytes, isa %s, units %s"
        % (p["function_count"], p["code_bytes"], p["isa"], p["units"])
    )
    print("  files: %s" % ", ".join(p["files"]))
    print(
        "  external callers %d, external pointer refs %d, data-adjacent %d"
        % (p["external_callers"], p["external_pointer_refs"], p["data_adjacent_count"])
    )
    if p["sdk_calls"]:
        print("  SDK calls: %s" % ", ".join(p["sdk_calls"]))
    if p["entry_points"]:
        print("  entry points: %s" % ", ".join(p["entry_points"]))
    for f in p["functions"]:
        print(
            "    %s  %-5s %5d bytes code %4d%s"
            % (
                f["addr"],
                f["isa"],
                f["size"],
                f["code"],
                "  data-adjacent" if f["data_adjacent"] else "",
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
    """
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import match  # noqa: E402

    unlock_weights = load_pending_unlock_weights()

    rows = []
    for pkt in doc["packets"].values():
        pid = pkt["id"]
        for f in pkt["functions"]:
            addr = int(f["addr"], 16)
            fan_in = len(match.image_call_sites(addr))
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
    for r in top:
        r["guess"] = nearby_subsystem_guess(r["addr"], matched_sources) or ""

    return top


def print_targets(doc, limit):
    top = build_targets(doc, limit)
    print("top %d open targets by attestation-weighted fan-in" % len(top))
    print(
        "  %-12s %6s  %-14s %7s %7s %7s  %s"
        % ("address", "size", "packet", "fan_in", "unlock", "score", "guess")
    )
    for r in top:
        print(
            "  %-12s %6d  %-14s %7d %7d %7d  %s"
            % (
                hexa(r["addr"]),
                r["size"],
                r["packet"],
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

    if args.summary or args.packet or args.targets is not None:
        if have_old:
            with open(args.out, encoding="utf-8") as fh:
                doc = json.load(fh)
        else:
            inv = build_inventory()
            doc = build_document(inv, group_packets(inv))
        if args.packet:
            return print_packet(doc, args.packet)
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
