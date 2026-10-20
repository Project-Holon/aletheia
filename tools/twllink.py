#!/usr/bin/env python3
"""twllink.py -- link the DSi-mode block (twl) from src/game/twl/ with mwldarm.

The twl block is the code of arm9i.bin (0x02700000..0x02732DA0, bss to
0x02735B40).  This script runs the overlay link of tools/gamelink.py
(link_overlay) on it: every top-level file of src/game/twl/ is compiled with the
compiler of its header (unit_02731754.c uses ../2.0/sp2), callees outside the
block become typed stubs, data symbols absolute assignments, and the bytes
between files are C companions (tools/twldata.py: the DSP component
0x02707CB4..0x0272E9E8, four pointer tables, strings, one variable, the padding;
written to build/datac/twl from the user's own extract, never committed).  The
key data card_rom.c reads comes from build/gen.  With --image-gaps the bytes
between the files are binary sections from the image instead.  The image is
extract/arm9i_dec.bin (the decrypted, decompressed block; its first word is
not part of the block).  The result is compared byte for byte with the block.

gamelink.py knows overlays, `itcm` and `arm9_main`; this module adds the region
`twl` to its region table (overlay_info, SRC_DIR) without editing gamelink.py.

usage
    python tools/twllink.py [--version=white] [--image-gaps]
Output is in build/gamelink/twl/ (White: build/gamelink/twl_white/).
"""

from __future__ import annotations

import json
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

import gamelink         # noqa: E402

REGION = "twl"


def twl_block(white=False):
    """(ram_start, code bytes) of the twl block, from the extracted image (White: extract_white/)."""
    lay = os.path.join(ROOT, "build", "white", "layout", "layout.json") if white         else os.path.join(ROOT, "layout", "layout.json")
    t = json.load(open(lay, encoding="utf-8"))["twl"]
    img = open(os.path.join(ROOT, "extract_white" if white else "extract", t["decompressed_file"]), "rb").read()
    return t["ram_start"], img[t["src_offset"]:t["src_offset"] + t["code_size"]]


def install():
    """Teach gamelink.py the region `twl` (idempotent)."""
    if getattr(gamelink, "_twl_installed", False):
        return
    gamelink.SRC_DIR.setdefault(REGION, "twl")
    orig = gamelink.overlay_info
    orig_w = gamelink.white_overlay_info

    def overlay_info(ovid):
        if ovid == REGION:
            return twl_block()
        return orig(ovid)

    def white_overlay_info(ovid):
        if ovid == REGION:
            return twl_block(True)
        return orig_w(ovid)
    gamelink.overlay_info = overlay_info
    gamelink.white_overlay_info = white_overlay_info
    gamelink._twl_installed = True


def link_twl(image_gaps=False, **kw):
    """Link the block.  The data between the files comes from the companions of tools/twldata.py
    (written first) unless image_gaps is set."""
    install()
    if not image_gaps and "extra" not in kw:
        import twldata
        twldata.build(gamelink.VERSION == "white")
        kw["extra"] = twldata.out_dir(gamelink.VERSION == "white")
    return gamelink.link_overlay(REGION, **kw)


def main(argv):
    mode = {}
    for a in argv:
        if a in ("--version=white", "--version=black"):
            gamelink.VERSION = a[10:]
            os.environ["ALETHEIA_VERSION"] = a[10:]
        elif a == "--absolute":
            mode["absolute_only"] = True
        elif a.startswith("--skip="):
            mode["skip"] = tuple(x for x in a[7:].split(",") if x)
        elif a == "--image-gaps":
            mode["image_gaps"] = True
        elif a == "--no-interworking":
            mode["interworking"] = False
    r = link_twl(**mode)
    print("%s %s %s" % (REGION, "PASS" if r["ok"] else "FAIL",
                        {k: v for k, v in r.items() if k not in ("ov", "ok", "units")}))
    return 0 if r["ok"] else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
