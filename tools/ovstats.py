"""Overlay census and coverage.

The arm9 figure in ``tools/worklist.py --summary`` counts only the always-resident
game code.  The game itself is mostly overlays: 237 chunks in the ROM, loaded on
demand, sharing addresses with each other.  This tool measures them so the
headline number stops meaning "arm9 only".

Sources, all generated, none committed as bytes:

  asm/overlays/ov*.s        listing per overlay, from ``tools/disasm.py overlay --all``
  layout/matched/ov*/pkt_*.json   shards, written by ``tools/match.py manifest --verify``
  layout/worklist.json      the arm9 summary block, for the combined figure

Usage:

    python tools/ovstats.py                 per-overlay table and totals
    python tools/ovstats.py --overlay ov010 one overlay in full
    python tools/ovstats.py --json          machine-readable

A function's extent here is the distance to the next label in the same listing,
which is the rule the arm9 side uses for a row without a unit.  Two caveats, both
deliberate: the code bytes come from each listing's own header, so they include
any SDK code mixed into the overlay (there is no per-overlay SDK symbol table
yet, unlike ``layout/symbols_sdk.txt`` for arm9), and only functions with a shard
entry are counted as matched.  EXACT and EXACT* both count.
"""
import argparse
import bisect
import glob
import itertools
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import stampcache  # noqa: E402  (stamp-validated pickle caches)

HDR_RANGE = re.compile(r"address range\s+0x([0-9A-Fa-f]+)\.\.0x([0-9A-Fa-f]+)\s+\(0x([0-9A-Fa-f]+) bytes\)")
HDR_CODE = re.compile(r"classified\s+0x([0-9A-Fa-f]+) bytes code\s+\(([0-9.]+)%\),\s+0x([0-9A-Fa-f]+) bytes data")
HDR_FUNCS = re.compile(r"functions\s+(\d+)")
FUNCNAME = re.compile(r"^(?:func|sub)_[0-9A-Fa-f]{6,8}$")
LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_.]*):\s*$")
ORG = re.compile(r"^\s*\.org\s+0x([0-9A-Fa-f]+)")
# An instruction line's comment is "/* ADDRESS  BYTES */", or "/* ADDRESS  BYTES  text */" for
# an .inst line that carries its decoding; pool words have no byte field and do not match.
INSN = re.compile(r"/\*\s*([0-9A-Fa-f]{8})\s+((?:[0-9A-Fa-f]{2} )*[0-9A-Fa-f]{2})(?:\s\s|\s*\*/)")
MATCHED = ("EXACT", "EXACT*")

# Per-region SDK symbol addresses, from layout/symbols_sdk.json (region: "ovNNN").
_SDK = {}


def sdk_addrs(region):
    if not _SDK:
        sys.path.insert(0, os.path.join(ROOT, "tools"))
        import sdkclass
        for reg, d in sdkclass.union().items():
            _SDK.setdefault(reg, set()).update(d)
        _SDK.setdefault("__loaded__", set())
    return _SDK.get(region, set())


def scan_listing(path):
    """(head, labels, insns) from one read of a listing.

    head    the first 18 lines joined (the header block)
    labels  [(address, label)] for every function label, in address order
    insns   [(address, byte count)] for every decoded instruction line

    Each line is tested with INSN once, and only when it holds "/*", the one
    thing every instruction comment starts with.  The labels follow the rule
    of listing_labels() and the sizes the rule of function_code_bytes()."""
    base = None
    out = []
    insns = []
    head = []
    pending = None
    insn_search = INSN.search
    label_match = LABEL.match
    with open(path, encoding="utf-8", errors="replace") as fh:
        for n, line in enumerate(fh):
            if n < 18:
                head.append(line)
            if base is None:
                m = HDR_RANGE.search(line)
                if m:
                    base = int(m.group(1), 16)
            m = insn_search(line) if "/*" in line else None
            if m:
                insns.append((int(m.group(1), 16), len(m.group(2).split())))
            if pending:
                if m:
                    out.append((int(m.group(1), 16), pending))
                    pending = None
                    continue
                mo = ORG.match(line)
                if mo:
                    out.append((base + int(mo.group(1), 16), pending))
                    pending = None
                    continue
            c = line[:1]
            if c == "_" or c.isalpha():
                ml = label_match(line)
                if ml:
                    # extents are bounded by function labels only: loc_ and pool_ labels sit
                    # inside a function and would truncate most of them
                    pending = ml.group(1) if FUNCNAME.match(ml.group(1)) else None
    out.sort()
    return "".join(head), out, insns


# Thumb-entry linker veneers that carry a function label because a `bl` reaches
# them.  The linker writes them to switch from Thumb to an ARM target; no C
# produces `bx pc; nop` (C0 46), so they are not game code and their labels
# count neither as game nor as SDK functions.  Only the exact form match.py
# attests (the Thumb-entry `veneer` class) is recognised, compared whole:
#   bx pc; nop; ldr ip, [pc]; bx ip; .word target
# The ARM form `ldr ip, [pc]; bx ip; .word target` alone is NOT excluded: mwcc
# emits it for an ARM tail call (ov009 func_0216F008.c is EXACT C).
VENEER_THUMB = re.compile(
    r"^(?:func|sub)_([0-9A-F]{8}):[ \t]*\n[ \t]*bx\tpc[ \t]+/\*[ \t]*\1[ \t]+78 47[ \t]*\*/[ \t]*\n[ \t]*\n"
    r"[ \t]*\.org[ \t]+0x[0-9A-F]+[ \t]*\n[ \t]*\.byte\t0xC0, 0x46[ \t]*\n"
    r"[ \t]*\.word\t0xE59FC000[^\n]*\n[ \t]*\.word\t0xE12FFF1C\b", re.M)

# The ARM long-branch veneer `ldr pc, [pc, #-4]; .word target` (04 F0 1F E5): it
# only jumps to a far address (ov095 at 0x0689xxxx into arm9, ov172 into the TWL
# region).  mwcc never loads pc from a pool word, so it is linker output and is
# excluded like the Thumb form.  `ldr pc` is an unconditional jump, so a label
# that starts with it has no other code of its own.
VENEER_ARM = re.compile(
    r"^(?:func|sub)_([0-9A-F]{8}):[ \t]*\n[ \t]*ldr\tpc, pool_[0-9A-F]{8}[ \t]+/\*[ \t]*\1[ \t]+04 F0 1F E5[ \t]*\*/", re.M)


# ov230's hand-written decryptor entries: `orr r0, pc, #0; adds r0, r0, #4; bne
# decoder`, each followed by the descriptor table and ciphertext the decoder walks
# (tools/ovcrypt.py).  No compiler emits `orr r0, pc, #0`; the code they unlock
# is matched in the decrypted region ov230d.  They sit outside both sides of the
# figure, like the veneers; their extents are table and ciphertext, not code.
DECRYPT_THUNK = re.compile(
    r"^(?:func|sub)_([0-9A-F]{8}):[ \t]*\n[ \t]*orr\tr0, pc, #0[ \t]+/\*[ \t]*\1[ \t]+00 00 8F E3[ \t]*\*/[ \t]*\n"
    r"[ \t]*adds\tr0, r0, #4\b", re.M)


def veneer_labels(path):
    """Addresses of function labels in a listing that are linker veneers or
    hand-written decryptor entries (counted on neither side of the figure)."""
    with open(path, encoding="utf-8", errors="replace") as fh:
        text = fh.read().replace("\r\n", "\n")
    return ({int(m.group(1), 16) for m in VENEER_THUMB.finditer(text)}
            | {int(m.group(1), 16) for m in VENEER_ARM.finditer(text)}
            | {int(m.group(1), 16) for m in DECRYPT_THUNK.finditer(text)})


def listing_summary(path):
    """(head, labels, {function address: instruction bytes}, veneer addresses) for one listing."""
    head, labels, insns = scan_listing(path)
    return head, labels, code_bytes_from(insns, [a for a, _ in labels]), veneer_labels(path)


def listing_labels(path):
    """[(address, label)] for every label in a listing, in address order."""
    return scan_listing(path)[1]


def code_bytes_from(insns, addrs):
    """{function address: instruction bytes}: see function_code_bytes()."""
    starts = sorted(set(addrs))
    out = dict.fromkeys(starts, 0)
    out[None] = 0
    for a, size in insns:
        pos = bisect.bisect_right(starts, a) - 1
        out[starts[pos] if pos >= 0 else None] += size
    return out


_SHARDS = {}


def _load_shards():
    """Every shard of the tree, once per run, through match.py's stamp cache
    (build/cache/shards.pkl): only the shard files that changed are parsed.
    An unparseable shard is skipped."""
    if not _SHARDS:
        import match
        files = match.shard_files_stamped()
        docs = match.shard_docs(files, on_error=lambda _t, _e: None)
        by_region = {}
        for name, path, _mt, _sz in files:
            if path in docs and name.startswith("pkt_"):
                by_region.setdefault(os.path.basename(os.path.dirname(path)), []).append(docs[path])
        _SHARDS["docs"] = docs
        _SHARDS["by_region"] = by_region
    return _SHARDS


def shard_docs_of(region):
    """[parsed shard] for layout/matched/<region>/pkt_*.json, in name order."""
    return _load_shards()["by_region"].get(region, [])


def cached_shard_doc(path):
    """The parsed shard at `path` (spelled as glob returns it), or None when it is
    missing or does not parse."""
    docs = _load_shards()["docs"]
    d = docs.get(path)
    if d is None:
        key = os.path.normcase(os.path.abspath(path))
        for p, doc in docs.items():
            if os.path.normcase(os.path.abspath(p)) == key:
                return doc
        try:
            with open(path, encoding="utf-8") as fh:
                d = json.load(fh)
        except Exception:
            return None
    return d


def shard_entries(overlay):
    """{key: status} for every function in an overlay's shards.

    Shards are read in sorted path order.  An entry is keyed by its own "address"
    field (by its name through the listing only when that field is missing), so a
    static name shared by several functions resolves to each of them and the same
    function listed in two shards is one address.  A unit entry (kind ``game_unit``
    or ``sdk_unit``: one translation unit compiled once, whose ``functions`` list
    names every member it reproduces, match.py attest_matched rule 3) also adds
    one key per member, the member's name.  A key counts as matched when any entry
    for it is EXACT or EXACT*; the result does not depend on read order or on
    which duplicate is seen first.
    """
    entries = {}

    def put(key, status):
        if key not in entries or (status.startswith(MATCHED) and not entries[key].startswith(MATCHED)):
            entries[key] = status

    for d in shard_docs_of(overlay):
        for f in d.get("functions", []):
            if not isinstance(f, dict) or not f.get("name"):
                continue
            try:
                key = int(str(f["address"]), 16) if f.get("address") else f["name"]
            except ValueError:
                key = f["name"]
            status = f.get("status", "")
            put(key, status)
            if str(f.get("kind", "")).endswith("_unit"):
                for member in f.get("functions", []):
                    if isinstance(member, str) and member:
                        put(member, status)
    return entries


MEMBER = re.compile(r"^(?:func|sub)_([0-9A-Fa-f]{8})$")


def matched_addresses(overlay, addrs, by_label):
    """(matched, uncounted) for one overlay.

    ``matched`` is the set of addresses with an EXACT/EXACT* shard entry that are
    function labels in the overlay's own listing (``addrs``).  An address that is
    not such a label is outside the denominator (its bytes are data, or sit in
    another function's extent), so it is never counted; it is returned in
    ``uncounted`` as (key, status) instead.  A member name that is not a label
    resolves through its ``func_XXXXXXXX`` spelling and is guarded the same way.
    """
    labelset = set(addrs)
    matched, uncounted = set(), []
    for key, status in shard_entries(overlay).items():
        if not status.startswith(MATCHED):
            continue
        a = key
        if isinstance(key, str):
            a = by_label.get(key)
            if a is None:
                m = MEMBER.match(key)
                a = int(m.group(1), 16) if m else None
        if a is not None and a in labelset:
            matched.add(a)
        else:
            uncounted.append((key, status))
    return matched, uncounted


def function_code_bytes(path, addrs):
    """{function address: instruction bytes} for a listing, the measure worklist.py uses
    for arm9.  Every decoded instruction is credited to the function label at or before
    it; pool words and data directives carry no byte field and are never counted, so a
    function is sized by its code alone, not by the distance to the next label.
    Instructions before the first label are returned under the key None."""
    return code_bytes_from(scan_listing(path)[2], addrs)


def overlay_rows(funcs_out=None):
    """One row of figures per overlay listing.

    With ``funcs_out`` (a list), also append one tile per traced function, built
    from the same labels, instruction sizes, SDK set and matched set as the row.
    coveragemap.py draws from that list, so its tiles and these totals come from a
    single read of each listing and shard set and cannot disagree when another
    session writes shards while the map is being generated.
    """
    rows = []
    # One read of each listing gives its header, labels and per-function code
    # bytes; none of the three depends on anything but the listing, so they
    # are kept under the listing's stamp (build/cache/ovstats_listings.pkl).
    tree = [t for t in stampcache.scan_files(os.path.join(ROOT, "asm", "overlays"), (".s",))
            if t[0].startswith("ov")]
    summaries = stampcache.Cache("ovstats_listings", owners=[__file__]).sync(tree, listing_summary)
    for path in [t[1] for t in tree]:
        overlay = os.path.basename(path)[:-2]
        if not overlay.startswith("ov") or not overlay[2:].isdigit():
            continue
        head, labels, code, veneers = summaries[path]
        m_range = HDR_RANGE.search(head)
        m_code = HDR_CODE.search(head)
        m_funcs = HDR_FUNCS.search(head)
        row = {
            "overlay": overlay,
            "code_bytes": int(m_code.group(1), 16) if m_code else 0,
            "data_bytes": int(m_code.group(3), 16) if m_code else 0,
            "listing_funcs": int(m_funcs.group(1)) if m_funcs else 0,
            "span": int(m_range.group(3), 16) if m_range else 0,
            "matched_bytes": 0,
            "matched_funcs": 0,
            "open_funcs": 0,
            "sdk_bytes": 0,
            "game_bytes": 0,
            "matched_sdk_bytes": 0,
            "matched_sdk_funcs": 0,
            "veneer_bytes": 0,
            "veneer_funcs": 0,
        }
        sdk = sdk_addrs(overlay)
        addrs = [a for a, _ in labels]
        by_label = {}
        for a, name in labels:
            by_label.setdefault(name, a)

        # Both sides of the figure use one measure, each function's instruction bytes
        # (function_code_bytes), as arm9 does; pools and data runs count nowhere.
        row["insn_bytes"] = sum(code.values())
        row["unattributed_bytes"] = code[None]
        for a in sorted(set(addrs)):
            if a in sdk:
                row["sdk_bytes"] += code[a]
        veneers = {a for a in veneers if a not in sdk and a in set(addrs)}
        for a in sorted(veneers):
            row["veneer_bytes"] += code[a]
            row["veneer_funcs"] += 1
        row["game_bytes"] = row["insn_bytes"] - row["sdk_bytes"] - row["veneer_bytes"]
        # Matched entries are keyed by address, and an address counts only when it is a
        # function label in this listing (matched_addresses), so every matched byte is
        # inside the denominator and a function listed twice counts once.
        matched, uncounted = matched_addresses(overlay, addrs, by_label)
        row["uncounted"] = ["0x%08X %s" % (k, st) if isinstance(k, int) else "%s %s" % (k, st)
                            for k, st in uncounted]
        for a in sorted(matched):
            if a in veneers:
                continue          # linker veneers sit outside both sides of the figure
            if a in sdk:
                row["matched_sdk_bytes"] += code[a]
                row["matched_sdk_funcs"] += 1
            else:
                row["matched_bytes"] += code[a]
                row["matched_funcs"] += 1
        if funcs_out is not None:
            seen = set()
            for a, name in labels:
                if a in seen or code[a] <= 0 or a in veneers:
                    continue
                seen.add(a)
                exact = a in matched
                if a in sdk:
                    cls = "matched_sdk" if exact else "sdk"
                else:
                    cls = "matched" if exact else "open"
                funcs_out.append({"addr": a, "name": name, "code_bytes": code[a], "region": overlay,
                                  "cls": cls, "sole_ref": False})
        rows.append(row)
    return rows


def arm9_summary():
    try:
        d = json.load(open(os.path.join(ROOT, "layout", "worklist.json"), encoding="utf-8"))
        return d.get("summary", {})
    except Exception:
        return {}


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--overlay", help="show one overlay in full, e.g. ov010")
    ap.add_argument("--json", action="store_true", help="machine-readable output")
    ap.add_argument("--top", type=int, default=15, help="rows in the table (default 15)")
    args = ap.parse_args()

    rows = overlay_rows()
    if not rows:
        print("no overlay listings found: run python tools/disasm.py overlay --all first")
        return 1

    ov_code = sum(r["code_bytes"] for r in rows)
    ov_matched = sum(r["matched_bytes"] for r in rows)
    ov_funcs = sum(r["listing_funcs"] for r in rows)
    ov_matched_funcs = sum(r["matched_funcs"] for r in rows)
    ov_data = sum(r["data_bytes"] for r in rows)
    ov_sdk = sum(r["sdk_bytes"] for r in rows)
    ov_game = sum(r["game_bytes"] for r in rows)
    ov_matched_sdk = sum(r["matched_sdk_bytes"] for r in rows)
    ov_matched_sdk_funcs = sum(r["matched_sdk_funcs"] for r in rows)
    ov_veneer = sum(r["veneer_bytes"] for r in rows)
    ov_veneer_funcs = sum(r["veneer_funcs"] for r in rows)
    arm9 = arm9_summary()
    arm9_game = int(arm9.get("code_bytes_game", 0))
    arm9_matched = int(arm9.get("code_bytes_matched", 0))
    arm9_funcs = int(arm9.get("functions_matched", 0))

    if args.overlay:
        sel = [r for r in rows if r["overlay"] == args.overlay]
        if not sel:
            print("no such overlay: %s" % args.overlay)
            return 1
        r = sel[0]
        print("%s: code %d bytes, data %d bytes, %d functions in the listing, %d matched (%d bytes)"
              % (r["overlay"], r["code_bytes"], r["data_bytes"], r["listing_funcs"],
                 r["matched_funcs"], r["matched_bytes"]))
        return 0

    if args.json:
        json.dump({
            "overlays": rows,
            "totals": {
                "overlay_count": len(rows),
                "overlay_code_bytes": ov_code,
                "overlay_sdk_bytes": ov_sdk,
                "overlay_game_bytes": ov_game,
                "overlay_data_bytes": ov_data,
                "overlay_listing_funcs": ov_funcs,
                "overlay_matched_bytes": ov_matched,
                "overlay_matched_funcs": ov_matched_funcs,
                "overlay_matched_sdk_bytes": ov_matched_sdk,
                "overlay_matched_sdk_funcs": ov_matched_sdk_funcs,
                "overlay_veneer_bytes": ov_veneer,
                "overlay_veneer_funcs": ov_veneer_funcs,
                "arm9_game_bytes": arm9_game,
                "arm9_matched_bytes": arm9_matched,
                "arm9_matched_funcs": arm9_funcs,
                "combined_game_bytes": arm9_game + ov_game,
                "combined_matched_bytes": arm9_matched + ov_matched,
            },
        }, sys.stdout, indent=1)
        return 0

    print("overlay code             : %d bytes (%.3f MB) in %d overlays, %d functions"
          % (ov_code, ov_code / 1048576.0, len(rows), ov_funcs))
    print("overlay data             : %d bytes (%.3f MB), not counted as work"
          % (ov_data, ov_data / 1048576.0))
    print("overlay SDK code         : %d bytes (%.1f%% of overlay code), excluded from the denominator"
          % (ov_sdk, 100.0 * ov_sdk / ov_code if ov_code else 0.0))
    print("overlay game code        : %d bytes, %d functions" % (ov_game, ov_matched_funcs))
    print("overlay matched (game)   : %d bytes (%.4f%% of game code), %d functions"
          % (ov_matched, 100.0 * ov_matched / ov_game if ov_game else 0.0, ov_matched_funcs))
    print("overlay matched SDK      : %d bytes (%.4f%% of SDK code), %d functions"
          % (ov_matched_sdk, 100.0 * ov_matched_sdk / ov_sdk if ov_sdk else 0.0, ov_matched_sdk_funcs))
    print()
    print("arm9 game code           : %d bytes, %d matched (%.4f%%)"
          % (arm9_game, arm9_matched, 100.0 * arm9_matched / arm9_game if arm9_game else 0.0))
    total = arm9_game + ov_game
    matched = arm9_matched + ov_matched
    print("combined game code       : %d bytes (%.3f MB), %d matched (%.4f%%)"
          % (total, total / 1048576.0, matched, 100.0 * matched / total if total else 0.0))
    print("  arm9 share of game code: %.2f%%" % (100.0 * arm9_game / total if total else 0.0))
    print()
    print("%-8s %10s %10s %9s %9s" % ("overlay", "code B", "matched B", "funcs", "matched"))
    for r in sorted(rows, key=lambda x: -x["code_bytes"])[:args.top]:
        print("%-8s %10d %10d %9d %9d%s" % (
            r["overlay"], r["code_bytes"], r["matched_bytes"], r["listing_funcs"], r["matched_funcs"],
            "" if r["matched_funcs"] == 0 else "  %.2f%%" % (100.0 * r["matched_bytes"] / r["code_bytes"])))
    print()
    print("overlays with any matched function: %d of %d"
          % (len([r for r in rows if r["matched_funcs"]]), len(rows)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
