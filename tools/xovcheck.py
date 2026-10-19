#!/usr/bin/env python3
"""Flag header `symbols:` rows that may name the wrong overlay's function.

Overlays share the address space, so one address holds different functions in different
overlays.  A row `NAME 0xADDR isa ovT` in a file of region R says: R calls ovT's function at
ADDR.  This is suspicious when R rarely refers to ovT while another overlay U, which R refers
to often (it is loaded together with R), defines a different function at ADDR.

    python tools/xovcheck.py [--min-common N] [--max-rare N]
Prints: file, row name, its overlay, and the candidate overlay's function at that address.
"""
import argparse
import collections
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GAME = os.path.join(ROOT, "src", "game")
ROW = re.compile(r"^ \*\s+([A-Za-z_]\w*)\s+0x([0-9A-Fa-f]{8})\s+(arm|thumb)\s+(ov\d{3})\b", re.M)
FUNC = re.compile(r"^ \* function:\s*(.*)$", re.M)
ADDR = re.compile(r"^ \* address:\s*0x([0-9A-Fa-f]{8})", re.M)

# Rows checked against the region link and the overlay load calls, and found correct.  Key: (file, row
# name); value: why the named overlay is the one loaded when the caller runs.
ALLOWED = {
    ("src/game/ov010/scrcmd_bridge_gimmick.c", "FIELD_GIMMICK_BRIDGE_ResetSave"):
        "the command loads ov047 itself (GF_OVERLAY_Load of id 0x2F) around the call",
    ("src/game/ov010/scrcmd_symbol.c", "PDC_CreateArgs"):
        "the caller loads ov098 (GF_OVERLAY_Load) before the call and unloads it after",
    ("src/game/ov021/pleasure_boat.c", "DAILY_LAYOUT_Generate"):
        "the caller loads ov036 (GF_OVERLAY_Load of id 0x24) around the call",
    ("src/game/ov021/scrcmd_encount.c", "FIELD_FK_DEMO_StartEvent"):
        "ov056 is the FK demo overlay: the sibling command StartFkDemoSubProc loads it with "
        "FIELD_SUBPROC_Start(ov56_id); no gimmick id maps to ov056 in gFieldGimmickOverlayIds, "
        "so the ov039 candidate (cart lanes) cannot be loaded for this command",
    ("src/game/ov021/scrcmd_gimmick.c", "FIELD_GIMMICK_LIFT_CallEvent"):
        "gFieldGimmickOverlayIds maps the lift gimmick (id 8) to ov044; the command is the lift's own, "
        "the ov052 candidate belongs to the battle subway gimmick",
    ("src/game/ov021/scrcmd_gimmick.c", "FIELD_GIMMICK_LIFT_SnapLiftToBottom"):
        "same as LIFT_CallEvent: lift gimmick (id 8) is ov044; ov064 is the arc effect gimmick",
    ("src/game/ov021/scrcmd_gimmick.c", "FIELD_GIMMICK_SWITCH_TOGGLE_StartSecondarySwitchEvent"):
        "gFieldGimmickOverlayIds maps the switch toggle gimmick (id 9) to ov045; ov064 is the arc "
        "effect gimmick",
}


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--min-common", type=int, default=3)
    ap.add_argument("--max-rare", type=int, default=2)
    a = ap.parse_args()
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import fnaddr
    defined = collections.defaultdict(dict)    # region -> {addr: name}
    rows = []
    for d in sorted(os.listdir(GAME)):
        p = os.path.join(GAME, d)
        if not os.path.isdir(p):
            continue
        for f in sorted(os.listdir(p)):
            if not f.endswith(".c"):
                continue
            path = os.path.join(p, f)
            text = open(path, encoding="latin1").read(60000)
            for m in ROW.finditer(text):
                rows.append((d, path, m.group(1), int(m.group(2), 16), m.group(4)))
            if re.fullmatch(r"ov\d{3}", d):
                try:
                    lay = fnaddr.compile_layout(path)
                except Exception:
                    continue
                for n, ad in lay.items():
                    if not n.startswith("$") and n != fnaddr.UNIT_SIZE_KEY:
                        defined[d][ad & ~1] = n
    refs = collections.defaultdict(collections.Counter)
    for r, _p, _n, _ad, t in rows:
        refs[r][t] += 1
    hits = 0
    for r, path, name, ad, t in rows:
        if t == r or refs[r][t] > a.max_rare:
            continue
        if (os.path.relpath(path, ROOT).replace(os.sep, "/"), name) in ALLOWED:
            continue
        for u, c in refs[r].most_common():
            if u in (t, r) or c < a.min_common:
                continue
            other = defined.get(u, {}).get(ad)
            if other and other != name:
                print("%s\t%s\t%s\t%s has %s (refs %d)" % (os.path.relpath(path, ROOT).replace(os.sep, "/"),
                                                           name, t, u, other, c))
                hits += 1
                break
    sys.stderr.write("%d suspicious rows\n" % hits)


if __name__ == "__main__":
    main()
