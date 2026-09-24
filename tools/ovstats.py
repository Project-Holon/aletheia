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
import glob
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

HDR_RANGE = re.compile(r"address range\s+0x([0-9A-Fa-f]+)\.\.0x([0-9A-Fa-f]+)\s+\(0x([0-9A-Fa-f]+) bytes\)")
HDR_CODE = re.compile(r"classified\s+0x([0-9A-Fa-f]+) bytes code\s+\(([0-9.]+)%\),\s+0x([0-9A-Fa-f]+) bytes data")
HDR_FUNCS = re.compile(r"functions\s+(\d+)")
FUNCNAME = re.compile(r"^(?:func|sub)_[0-9A-Fa-f]{6,8}$")
LABEL = re.compile(r"^([A-Za-z_][A-Za-z0-9_.]*):\s*$")
ORG = re.compile(r"^\s*\.org\s+0x([0-9A-Fa-f]+)")
INSN = re.compile(r"/\*\s*([0-9A-Fa-f]{8})\s+((?:[0-9A-Fa-f]{2} )+)\*/")
MATCHED = ("EXACT", "EXACT*")


def listing_labels(path):
    """[(address, label)] for every label in a listing, in address order."""
    with open(path, encoding="utf-8", errors="replace") as fh:
        base = None
        addr = None
        out = []
        pending = None
        for line in fh:
            if base is None:
                m = HDR_RANGE.search(line)
                if m:
                    base = int(m.group(1), 16)
                    addr = base
            if pending:
                m = INSN.search(line)
                if m:
                    out.append((int(m.group(1), 16), pending))
                    pending = None
                    continue
                m = ORG.match(line)
                if m:
                    out.append((base + int(m.group(1), 16), pending))
                    pending = None
                    continue
            m = LABEL.match(line)
            if m:
                # extents are bounded by function labels only: loc_ and pool_ labels sit
                # inside a function and would truncate most of them
                pending = m.group(1) if FUNCNAME.match(m.group(1)) else None
                continue
            m = ORG.match(line)
            if m and base is not None:
                addr = base + int(m.group(1), 16)
                continue
            m = INSN.search(line)
            if m:
                addr = int(m.group(1), 16)
    out.sort()
    return out


def shard_entries(overlay):
    """{name: status} for every function in an overlay's shards."""
    entries = {}
    for shard in glob.glob(os.path.join(ROOT, "layout", "matched", overlay, "pkt_*.json")):
        try:
            d = json.load(open(shard, encoding="utf-8"))
        except Exception:
            continue
        for f in d.get("functions", []):
            if isinstance(f, dict) and f.get("name"):
                entries[f["name"]] = f.get("status", "")
    return entries


def overlay_rows():
    rows = []
    for path in sorted(glob.glob(os.path.join(ROOT, "asm", "overlays", "ov*.s"))):
        overlay = os.path.basename(path)[:-2]
        if not overlay.startswith("ov") or not overlay[2:].isdigit():
            continue
        head = "".join(open(path, encoding="utf-8", errors="replace").readlines()[:18])
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
        }
        entries = shard_entries(overlay)
        if entries:
            labels = listing_labels(path)
            addrs = [a for a, _ in labels]
            by_label = {}
            for a, name in labels:
                by_label.setdefault(name, a)
            span_end = (int(m_range.group(2), 16) if m_range else 0)
            for name, status in entries.items():
                if not status.startswith(MATCHED):
                    continue
                a = by_label.get(name)
                if a is None:
                    continue
                after = [x for x in addrs if x > a]
                end = after[0] if after else span_end
                row["matched_bytes"] += max(0, end - a)
                row["matched_funcs"] += 1
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
                "overlay_data_bytes": ov_data,
                "overlay_listing_funcs": ov_funcs,
                "overlay_matched_bytes": ov_matched,
                "overlay_matched_funcs": ov_matched_funcs,
                "arm9_game_bytes": arm9_game,
                "arm9_matched_bytes": arm9_matched,
                "arm9_matched_funcs": arm9_funcs,
                "combined_game_bytes": arm9_game + ov_code,
                "combined_matched_bytes": arm9_matched + ov_matched,
            },
        }, sys.stdout, indent=1)
        return 0

    print("overlay code             : %d bytes (%.3f MB) in %d overlays, %d functions"
          % (ov_code, ov_code / 1048576.0, len(rows), ov_funcs))
    print("overlay data             : %d bytes (%.3f MB), not counted as work"
          % (ov_data, ov_data / 1048576.0))
    print("overlay matched          : %d bytes (%.4f%% of overlay code), %d functions"
          % (ov_matched, 100.0 * ov_matched / ov_code if ov_code else 0.0, ov_matched_funcs))
    print()
    print("arm9 game code           : %d bytes, %d matched (%.4f%%)"
          % (arm9_game, arm9_matched, 100.0 * arm9_matched / arm9_game if arm9_game else 0.0))
    total = arm9_game + ov_code
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
