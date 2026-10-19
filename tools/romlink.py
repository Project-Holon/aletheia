#!/usr/bin/env python3
"""romlink.py: build the whole .nds from src/game and compare it with the original.

    python tools/romlink.py                    # reuse the region links in build/, build, compare
    python tools/romlink.py --relink           # redo every region link first (slow: about 15 minutes)
    python tools/romlink.py --onelink          # link ARM9, ITCM and all overlays in ONE mwldarm run (tools/onelink.py)
    python tools/romlink.py --image-fallback   # a region that did not link keeps its image bytes (listed)
    python tools/romlink.py --out build/rom/aletheia.nds --report build/rom/report.json

What it does:

 1. regions.  Every region is linked in data mode by tools/gamelink.py:
      overlays  tools/datamode_all.py  (datagen companions + gamelink N --data)
      arm9      tools/arm9data.py      + gamelink arm9_main --data --extra=build/datac/arm9
      ITCM      the two zero pads of the block (companions written here, build/datac/itcm)
                + gamelink itcm --extra=build/datac/itcm
    Without --relink the existing build/gamelink*/<region>/ov.bin is reused, but only if
    its ov.json says it linked identical (ok) and is older than no source file of the
    region; a region that is not usable stops the run (or takes --image-fallback).
 2. small pieces with no src/game file, written as C into build/datac/autoload/ and
    compiled with the game compiler:
      autoload table      4 entries of 16 bytes from layout.json (address, size,
                          static initialiser start, bss size)
      MAIN_TWL / VRAM_LCDC blocks (160 + 32 and 32 bytes): data words from the extract
    overlays that hold no code (57 of 237): code_size zero bytes from layout.json.
 3. arm9_dec.bin = static module + ITCM + 3 small autoload blocks + table, then
    build.py pack_arm9 (BLZ with the build-info fixpoint); every compressed overlay with
    the same compressor.  All written into build/rom/pack/.
 4. ndsrom.py build extract --override build/rom/pack -> the ROM.  Everything else
    (header, ARM7, banner, file system, overlay table, the DSi block, the game data
    files) stays the user's own dump (never committed).
 5. compare with the original ROM (manifest rom_path): SHA-1 of the image, per file what
    differs, and the exact list of bytes that did not come from our source.

With --onelink, step 1 is different: the companions and pads of step 1 are written, then
tools/onelink.py captures every region's link inputs and links all 182 regions in one mwldarm
run (docs/restructure/ONELINK.md); each region's image is cut from that one ELF by section name
prefix.  A capture newer than every input is reused, and the link is reused when the hashes of
the captured objects did not change.  Steps 2 to 5 are the same.

Nothing is written to src/ or to a tracked file; everything goes to build/.
"""
import argparse
import hashlib
import json
import os
import re
import struct
import subprocess
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOLS = os.path.join(ROOT, "tools")
sys.path.insert(0, TOOLS)

LAYOUT = os.path.join(ROOT, "layout", "layout.json")
BUILD = os.path.join(ROOT, "build")
GL = os.path.join(BUILD, "gamelink")
GLD = os.path.join(BUILD, "gamelink_data")
AUTO = os.path.join(BUILD, "datac", "autoload")
ITCM_C = os.path.join(BUILD, "datac", "itcm")
PACK = os.path.join(BUILD, "rom", "pack")
PY = sys.executable


def sh(cmd, **kw):
    return subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, **kw)


def load_layout():
    with open(LAYOUT, encoding="utf-8") as fh:
        lay = json.load(fh)
    ext = os.path.join(ROOT, lay["extract_dir"])
    with open(os.path.join(ext, "manifest.json"), encoding="utf-8") as fh:
        man = json.load(fh)
    return lay, ext, man


# ---------------------------------------------------------------------------
# 1. regions
# ---------------------------------------------------------------------------

def code_overlay_ids(lay):
    have = {int(m.group(1)) for d in os.listdir(os.path.join(ROOT, "src", "game"))
            for m in [re.fullmatch(r"ov(\d{3})", d)] if m}
    code = [o["id"] for o in lay["overlays"] if o["id"] in have]
    stub = [o["id"] for o in lay["overlays"] if o["id"] not in have]
    return code, stub


def link_itcm():
    """ITCM: the block starts with 0x20 bytes before its first function and ends at a
    multiple of 32 after the last one.  That is linker alignment padding: a first link
    leaves the two ranges as gaps, they are written as two zero arrays (C, build/datac/itcm)
    and the block is linked again with no gap.  (The link compares the result with the
    original, so a pad that was not zero would fail.)"""
    os.makedirs(ITCM_C, exist_ok=True)
    for f in os.listdir(ITCM_C):
        if f.startswith("itcm_pad_"):
            os.remove(os.path.join(ITCM_C, f))
    sh([PY, "tools/gamelink.py", "itcm", "--extra=build/datac/itcm"])
    j = json.load(open(os.path.join(GL, "itcm", "ov.json")))
    for k, (a, b) in enumerate(j["gaps"]):
        name = "%d" % k
        text = ("/*\n * file:     itcm_pad_NAME.c\n * address:  0xADDR\n"
                " * region:   arm9_autoload0_ITCM\n * compiler: dsi/1.1p1\n * flags:    -O4,p\n"
                " * lang:     c99\n * isa:      arm\n * status:   EXACT\n *\n * symbols:\n"
                " *   itcm_pad_NAME  0xADDR  data\n */\n"
                "/* linker alignment padding of the ITCM block, written by tools/romlink.py */\n"
                "const unsigned int itcm_pad_NAME[COUNT] = { 0 };\n")
        text = text.replace("NAME", name).replace("ADDR", "%08X" % a).replace("COUNT", str((b - a) // 4))
        with open(os.path.join(ITCM_C, "itcm_pad_%s.c" % name), "w", newline="\n") as fh:
            fh.write(text)
    r = sh([PY, "tools/gamelink.py", "itcm", "--extra=build/datac/itcm"])
    return r.stdout + r.stderr


OV230_C = os.path.join(BUILD, "datac", "ov230")


def link_ov230_blobs(lay):
    """Overlay 230: the bytes of its decrypted view that no src/game file writes.  The view
    (tools/ovcrypt.py) has the first-layer ranges and the second-layer bodies opened; the link
    of src/game/ov230 is compared with it and tools/ovcrypt.py encrypt() seals both layers again
    for the ROM.  Bodies not yet matched in C (and a few data words between the functions) are
    gaps of the first data-mode link; each gap is written as one `asm` function of DCD words
    (from the user's own extract, build/datac/ov230, never committed, like the ITCM pads) and the
    overlay is linked again with no gap.  The link compares the result with the decrypted view,
    so a wrong word fails it.  When every body is matched there are no gaps."""
    import ovcrypt
    o = next(x for x in lay["overlays"] if x["id"] == 230)
    view = ovcrypt.load(ROOT)
    os.makedirs(OV230_C, exist_ok=True)
    for f in os.listdir(OV230_C):
        if f.startswith("sealed_blob_"):
            os.remove(os.path.join(OV230_C, f))
    extra = "--extra=build/datac/ov230"
    sh([PY, "tools/gamelink.py", "230", "--data", extra])
    j = json.load(open(os.path.join(GLD, "ov230", "ov.json")))
    with open(os.path.join(GLD, "ov230", "blobs.json"), "w") as fh:
        json.dump([list(x) for x in j["gaps"]], fh)
    for a, b in j["gaps"]:
        name = "OV230_SealedBlob_%08X" % a
        words = struct.unpack_from("<%dI" % ((b - a) // 4), view.data, a - o["ram_start"])
        text = ("/*\n * file:     sealed_blob_%08X.c\n * function: %s\n * address:  0x%08X\n"
                " * region:   ov230d\n * compiler: dsi/1.1p1\n * flags:    -O4,p\n * lang:     c99\n"
                " * isa:      arm\n * status:   EXACT\n *\n * symbols:\n *   %s  0x%08X  arm  ov230d\n */\n"
                "/* generated by tools/romlink.py from the extract at build time; not committed. Sealed"
                " second-layer bytes and data words of the decrypted view that no src/game file holds */\n"
                "asm void %s(void)\n{\n%s\n}\n") % (a, name, a, name, a, name,
                                                   "\n".join("    DCD     0x%08X" % w for w in words))
        with open(os.path.join(OV230_C, "sealed_blob_%08X.c" % a), "w", newline="\n") as fh:
            fh.write(text)
    r = sh([PY, "tools/gamelink.py", "230", "--data", extra])
    return r.stdout + r.stderr


def relink_all(lay, jobs, only=None):
    code, _stub = code_overlay_ids(lay)
    log = []
    t = time.time()
    r = sh([PY, "tools/datamode_all.py", "--jobs", str(jobs)] + [str(i) for i in (only or [])])
    log.append(r.stdout.strip())
    if not only or 230 in only:
        log.append(link_ov230_blobs(lay).strip()[-300:])
    r = sh([PY, "tools/arm9data.py"])
    log.append(r.stdout.strip()[-400:])
    r = sh([PY, "tools/gamelink.py", "arm9_main", "--data", "--extra=build/datac/arm9"])
    log.append(r.stdout.strip()[-300:])
    log.append(link_itcm().strip()[-300:])
    print("relink: %.0f s" % (time.time() - t))
    return log


def region_dir(name):
    return os.path.join(GL if name == "itcm" else GLD, name)


def newest_source(name):
    d = os.path.join(ROOT, "src", "game", {"arm9_main": "arm9", "itcm": "arm9_autoload0_ITCM"}.get(name, name))
    best = 0.0
    for dp, _dn, fns in os.walk(d):
        if os.sep + "unplaced" in dp or os.sep + "members" in dp:
            continue
        for f in fns:
            if f.endswith((".c", ".h")):
                best = max(best, os.path.getmtime(os.path.join(dp, f)))
    return best


def load_region(name, size):
    """-> (bytes or None, info dict).  info: ok, why, gaps, standin, stale."""
    d = region_dir(name)
    jp, bp = os.path.join(d, "ov.json"), os.path.join(d, "ov.bin")
    if not (os.path.exists(jp) and os.path.exists(bp)):
        return None, dict(ok=False, why="no ov.json/ov.bin (run with --relink)")
    j = json.load(open(jp))
    data = open(bp, "rb").read()
    info = dict(ok=bool(j["ok"]), gaps=[tuple(x) for x in j["gaps"]], standin=[tuple(x) for x in j["standin"]],
                stale=newest_source(name) > os.path.getmtime(jp), data_mode=j.get("data_mode"))
    if hashlib.sha1(data).hexdigest() != j["sha1"]:
        info.update(ok=False, why="ov.bin does not belong to ov.json (a later failed run)")
    elif len(data) != size:
        info.update(ok=False, why="size %d, layout says %d" % (len(data), size))
    elif not info["ok"]:
        info["why"] = "last complete link differed from the original"
    return data, info


# ---------------------------------------------------------------------------
# 1b. the one link (--onelink)
# ---------------------------------------------------------------------------

ONELINK_STAMP = os.path.join(BUILD, "onelink", "capture.ok")


def newest_input():
    """Newest mtime of everything a capture reads: src/game, layout, the link tools."""
    best = 0.0
    for top, exts in (("src/game", (".c", ".h")), ("layout", (".json",))):
        for dp, _dn, fns in os.walk(os.path.join(ROOT, top)):
            for f in fns:
                if f.endswith(exts):
                    best = max(best, os.path.getmtime(os.path.join(dp, f)))
    for f in ("gamelink.py", "onelink.py", "datagen.py", "arm9data.py", "match.py", "ovcrypt.py", "romlink.py"):
        p = os.path.join(TOOLS, f)
        if os.path.exists(p):
            best = max(best, os.path.getmtime(p))
    return best


def onelink_prepare(lay, jobs, force):
    """Companions and pads (as --relink writes them), then onelink capture; skipped when the last
    capture is newer than every input.  Then onelink link (cached on the captured objects)."""
    from concurrent.futures import ThreadPoolExecutor
    code, _stub = code_overlay_ids(lay)
    t = time.time()
    fresh = (not force and os.path.exists(ONELINK_STAMP)
             and os.path.getmtime(ONELINK_STAMP) > newest_input())
    if fresh:
        print("onelink: capture is newer than every input, reused")
    else:
        def comp(n):
            r = sh([PY, "tools/datagen.py", "companions", str(n)])
            return n, r.returncode, (r.stdout + r.stderr).strip()[-200:]
        with ThreadPoolExecutor(jobs) as ex:
            for n, rc, tail in ex.map(comp, code):
                if rc:
                    raise SystemExit("datagen companions %d: %s" % (n, tail))
        r = sh([PY, "tools/arm9data.py"])
        if r.returncode:
            raise SystemExit("arm9data: " + (r.stdout + r.stderr)[-300:])
        link_itcm()
        link_ov230_blobs(lay)
        print("onelink: companions and pads written, %.0f s" % (time.time() - t))
        cap = sh([PY, "tools/onelink.py", "capture", "--jobs", str(jobs)])
        print((cap.stdout.strip().splitlines() or ["capture: no output"])[-1])
        if cap.returncode:
            print("note: some regions did not link identical in the capture:")
            for line in cap.stdout.splitlines():
                if " FAIL" in line:
                    print("  " + line[:200])
        os.makedirs(os.path.dirname(ONELINK_STAMP), exist_ok=True)
        open(ONELINK_STAMP, "w").write("%f" % time.time())
    lk = sh([PY, "tools/onelink.py", "link"])
    lines = [l for l in lk.stdout.splitlines() if not l.startswith("#")]
    for l in lines[-3:]:
        print(l)
    if lk.returncode:
        raise SystemExit("onelink link failed: " + lk.stdout[-800:] + lk.stderr[-400:])
    print("onelink: %.0f s" % (time.time() - t))


# ---------------------------------------------------------------------------
# 2. the pieces with no src/game file
# ---------------------------------------------------------------------------

def compile_const_words(stem, words, outdir):
    """Compile `const unsigned int NAME[n] = {...}` with the game compiler; return the
    bytes of its .rodata (no relocations: the object bytes are the linked bytes)."""
    import gamelink
    os.makedirs(outdir, exist_ok=True)
    path = os.path.join(outdir, stem + ".c")
    body = ",\n".join("  " + ", ".join("0x%08X" % w for w in words[i:i + 4]) for i in range(0, len(words), 4))
    with open(path, "w", newline="\n") as fh:
        fh.write("/* generated by tools/romlink.py at build time; not committed */\n"
                 "const unsigned int %s[%d] = {\n%s\n};\n" % (stem, len(words), body))
    sub = os.path.join(outdir, stem + "_o")
    os.makedirs(sub, exist_ok=True)
    obj, _cmd, log, _rc = gamelink.match.compile_tu(path, "dsi/1.1p1", ["-O4,p"], False, "c99", sub)
    if obj is None:
        raise SystemExit("compile %s: %s" % (stem, log[:300]))
    d, secs, _syms = gamelink.read_elf(obj)
    ro = [s for s in secs if s["name"] == ".rodata" and s["size"]]
    if len(ro) != 1 or ro[0]["size"] != 4 * len(words):
        raise SystemExit("%s: unexpected sections %s" % (stem, [(s["name"], s["size"]) for s in secs]))
    return d[ro[0]["off"]:ro[0]["off"] + ro[0]["size"]]


def autoload_pieces(lay, ext, itcm_len):
    a9 = lay["arm9"]
    img = open(os.path.join(ext, a9["decompressed_file"]), "rb").read()      # words of the small blocks only
    out = {}
    pieces = []           # (name, offset in arm9_dec, bytes, origin)
    for al in a9["autoloads"]:
        if al["kind"] == "ITCM":
            if itcm_len != al["code_size"]:
                raise SystemExit("ITCM link is %d bytes, layout says %d" % (itcm_len, al["code_size"]))
            continue
        off, n = al["src_offset"], al["code_size"]
        words = list(struct.unpack("<%dI" % (n // 4), img[off:off + n]))
        data = compile_const_words("autoload%d_%s" % (al["index"], al["kind"].lower()), words, AUTO)
        pieces.append(("autoload%d %s %08X" % (al["index"], al["kind"], al["ram_start"]), off, data,
                       "C data words from the extract (no src/game file)"))
    # the autoload table: address, size, static initialiser start, bss size per block
    info = a9["build_info"]
    tw = []
    for al in a9["autoloads"]:
        tw += [al["ram_start"], al["code_size"], al["static_init_start"], al["bss_size"]]
    data = compile_const_words("autoload_table", tw, AUTO)
    toff = info["autoload_infos_start"] - a9["load_address"]
    if toff + len(data) != a9["decompressed_size"]:
        raise SystemExit("autoload table does not end the image")
    pieces.append(("autoload table", toff, data, "C words from layout.json"))
    return pieces


def stub_overlay(o):
    """An overlay with no code: code_size zero bytes (its one static initialiser entry is the
    terminator word)."""
    return bytes(o["code_size"])


# ---------------------------------------------------------------------------
# 3-5. pack, ROM, compare
# ---------------------------------------------------------------------------

def diff_ranges(a, b, limit=8):
    """-> (count of differing bytes, first ranges)"""
    n = min(len(a), len(b))
    bad = [i for i in range(n) if a[i] != b[i]] if n <= 4_000_000 else None
    if bad is None:
        import itertools
        bad = []
        step = 1 << 20
        for o in range(0, n, step):
            x, y = a[o:o + step], b[o:o + step]
            if x != y:
                bad += [o + i for i in range(len(x)) if x[i] != y[i]]
    rng = []
    for i in bad:
        if rng and i == rng[-1][1]:
            rng[-1][1] = i + 1
        else:
            rng.append([i, i + 1])
    return len(bad) + abs(len(a) - len(b)), rng[:limit]


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("--relink", action="store_true", help="redo every region link first")
    ap.add_argument("--onelink", action="store_true",
                    help="link every region in one mwldarm run (tools/onelink.py) and cut the images from it")
    ap.add_argument("--recapture", action="store_true", help="with --onelink: redo the capture even if it is fresh")
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--image-fallback", action="store_true",
                    help="a region with no usable link keeps its bytes from the image (listed as such)")
    ap.add_argument("--out", default=os.path.join(BUILD, "rom", "aletheia.nds"))
    ap.add_argument("--report", default=os.path.join(BUILD, "rom", "report.json"))
    a = ap.parse_args(argv)

    import blz
    import build as bld
    lay, ext, man = load_layout()
    a9 = lay["arm9"]
    t0 = time.time()
    if a.relink and a.onelink:
        raise SystemExit("--relink and --onelink are different link methods; pick one")
    if a.relink:
        for line in relink_all(lay, a.jobs):
            print(line)
    one_imgs = None
    if a.onelink:
        onelink_prepare(lay, a.jobs, a.recapture)
        import onelink
        one_imgs = onelink.extract_images()
    code_ids, stub_ids = code_overlay_ids(lay)

    prebuilt = []          # (what, bytes, why): bytes of the final ROM not from our source
    notes = []
    problems = []

    # --- regions ---
    def get(name, size):
        if one_imgs is not None:
            data, info = one_imgs.get(name, (None, dict(ok=False, why="not in the one link")))
            if data is not None and len(data) != size:
                data, info = None, dict(ok=False, why="size %d, layout says %d" % (len(data), size))
        else:
            data, info = load_region(name, size)
        if data is None or not info["ok"]:
            problems.append("%s: %s" % (name, info.get("why")))
            if a.image_fallback:
                return None, info
            return None, info
        if info.get("stale"):
            notes.append("%s: a source file is newer than its link (rerun with --relink)" % name)
        return data, info

    st = a9["static"]
    img9 = open(os.path.join(ext, a9["decompressed_file"]), "rb").read()
    stat, sinfo = get("arm9_main", st["size"])
    itcm_size = a9["autoloads"][0]["code_size"]
    itcm, iinfo = get("itcm", itcm_size)
    ovdata = {}
    ovinfo = {}
    for oid in code_ids:
        o = next(x for x in lay["overlays"] if x["id"] == oid)
        ovdata[oid], ovinfo[oid] = get("ov%03d" % oid, o["code_size"])
    if problems and not a.image_fallback:
        print("regions not usable:")
        for p in problems:
            print("  " + p)
        return 2

    # --- arm9_dec.bin ---
    dec = bytearray(a9["decompressed_size"])
    ref9 = img9
    fall = []         # (what, start, size) bytes taken from the image
    if stat is None:
        dec[st["src_offset"]:st["src_offset"] + st["size"]] = ref9[st["src_offset"]:st["src_offset"] + st["size"]]
        fall.append(("arm9_main (no usable link)", st["src_offset"], st["size"]))
    else:
        dec[st["src_offset"]:st["src_offset"] + st["size"]] = stat
        for g0, g1 in sinfo["gaps"]:
            fall.append(("arm9 static gap %08X" % g0, g0 - st["ram_start"], g1 - g0))
        for g0, g1 in sinfo["standin"]:
            fall.append(("arm9 static .bss stand-in %08X" % g0, g0 - st["ram_start"], g1 - g0))
    al0 = a9["autoloads"][0]
    if itcm is None:
        dec[al0["src_offset"]:al0["src_offset"] + al0["code_size"]] = ref9[al0["src_offset"]:al0["src_offset"] + al0["code_size"]]
        fall.append(("ITCM (no usable link)", al0["src_offset"], al0["code_size"]))
    else:
        dec[al0["src_offset"]:al0["src_offset"] + al0["code_size"]] = itcm
        for g0, g1 in iinfo["gaps"]:
            fall.append(("ITCM gap %08X" % g0, al0["src_offset"] + g0 - al0["ram_start"], g1 - g0))
    pieces = autoload_pieces(lay, ext, itcm_size)
    for name, off, data, origin in pieces:
        dec[off:off + len(data)] = data
    dec = bytes(dec)
    os.makedirs(PACK, exist_ok=True)
    os.makedirs(os.path.join(PACK, "overlays"), exist_ok=True)
    with open(os.path.join(BUILD, "rom", "arm9_dec_romlink.bin"), "wb") as fh:
        fh.write(dec)
    same_dec = dec == img9
    print("arm9_dec.bin from source: %d bytes, %s the original decompressed image"
          % (len(dec), "identical to" if same_dec else "DIFFERENT from"))
    if not same_dec:
        n, rng = diff_ranges(dec, img9)
        print("  %d bytes differ, first ranges %s" % (n, [(hex(x), hex(y)) for x, y in rng]))

    # --- pack ---
    container, packed, iters = bld.pack_arm9(lay, dec)
    with open(os.path.join(PACK, "arm9.bin"), "wb") as fh:
        fh.write(container)
    orig9 = open(os.path.join(ext, "arm9.bin"), "rb").read()
    print("arm9.bin: %d bytes (%d recompression passes), %s the original" % (
        len(container), iters, "identical to" if container == orig9 else "DIFFERENT from"))

    fell_ov = []
    changed = []
    for o in lay["overlays"]:
        oid = o["id"]
        if oid in stub_ids:
            data = stub_overlay(o)
        else:
            data = ovdata[oid]
            if oid == 230 and data is not None:
                # overlay 230 holds most of its code encrypted: the link of src/game/ov230 is the
                # decrypted view, and the file in the ROM is its encryption (tools/ovcrypt.py)
                import ovcrypt
                o230 = next(x for x in lay["overlays"] if x["id"] == 230)
                data = ovcrypt.encrypt(data, o230["ram_start"], ovcrypt.sinit_entries(data, o230))
            if data is None:
                od = open(os.path.join(ext, o["decompressed_file"]), "rb").read()
                data = od
                fell_ov.append(oid)
        if len(data) != o["code_size"]:
            raise SystemExit("ov%03d: %d bytes, layout says %d" % (oid, len(data), o["code_size"]))
        blob = blz.compress(data) if o["compressed"] else data
        with open(os.path.join(PACK, o["file"].replace("/", os.sep)), "wb") as fh:
            fh.write(blob)
        if len(blob) != o["file_size"]:
            changed.append((oid, o["file_size"], len(blob)))
    if changed:
        print("%d overlay file(s) changed size: %s" % (len(changed), changed[:6]))

    # --- ROM ---
    os.makedirs(os.path.dirname(a.out), exist_ok=True)
    r = sh([PY, "tools/ndsrom.py", "build", lay["extract_dir"], "-o", a.out, "--override", PACK])
    print(r.stdout.strip().splitlines()[-1] if r.stdout.strip() else r.stderr.strip())
    if r.returncode:
        print(r.stderr)
        return 3
    rom = open(a.out, "rb").read()
    built_sha = hashlib.sha1(rom).hexdigest()

    # --- compare with the original ---
    orig_path = man["rom_path"]
    orig_sha = man["rom_sha1"]
    orig = None
    if os.path.exists(orig_path):
        orig = open(orig_path, "rb").read()
        if hashlib.sha1(orig).hexdigest() != orig_sha:
            print("note: the file at rom_path no longer has the recorded SHA-1")
            orig_sha = hashlib.sha1(orig).hexdigest()
    verdict = "IDENTICAL" if built_sha == orig_sha else "DIFFERENT"
    print("ROM sha1: built %s  original %s  %s" % (built_sha, orig_sha, verdict))

    per_file = []
    if built_sha != orig_sha and orig is not None:
        for rec in man["regions"] + [dict(name="residue%d" % x["index"], offset=x["offset"], size=x["size"], path=x["path"])
                                     for x in man["residue"]]:
            lo, n = rec["offset"], rec["size"]
            if rom[lo:lo + n] != orig[lo:lo + n]:
                cnt, rng = diff_ranges(rom[lo:lo + n], orig[lo:lo + n], 4)
                per_file.append((rec["path"], cnt, [(hex(lo + x), hex(lo + y)) for x, y in rng]))
        n, rng = diff_ranges(rom, orig, 6)
        print("whole image: %d bytes differ; first ranges %s" % (n, [(hex(x), hex(y)) for x, y in rng]))
        for p in per_file[:30]:
            print("  differs: %s: %d bytes %s" % p)
        print("%d file(s) differ" % len(per_file))
    else:
        print("per file: no file differs")

    # --- bytes that did not come from our source ---
    over = {"arm9.bin"} | {o["file"] for o in lay["overlays"]}
    rows = []
    tot_pre = 0
    groups = {}
    for rec in man["regions"] + [dict(name="residue", offset=x["offset"], size=x["size"], path=x["path"]) for x in man["residue"]]:
        if rec["path"] in over or not rec["size"]:
            continue
        g = "game data files (data/)" if rec["path"].startswith("data/") else rec["path"]
        groups.setdefault(g, [0, 0])
        groups[g][0] += rec["size"]
        groups[g][1] += 1
        tot_pre += rec["size"]
    rows.append(("files taken whole from the user's dump", tot_pre))
    gaps_total = 0
    gap_lines = []
    for nm, off, size in fall:
        gap_lines.append((nm, size))
        gaps_total += size
    for oid in code_ids:
        inf = ovinfo[oid]
        if ovdata[oid] is None:
            gap_lines.append(("ov%03d (no usable link, whole overlay)" % oid, next(x for x in lay["overlays"] if x["id"] == oid)["code_size"]))
            gaps_total += gap_lines[-1][1]
            continue
        for g0, g1 in inf["gaps"]:
            gap_lines.append(("ov%03d gap %08X" % (oid, g0), g1 - g0))
            gaps_total += g1 - g0
        if oid == 230:
            # bytes of the decrypted view that no src/game file writes: link_ov230_blobs() fills
            # them with generated asm so the link has no gap, but they are not from our source
            try:
                for g0, g1 in json.load(open(os.path.join(GLD, "ov230", "blobs.json"))):
                    gap_lines.append(("ov230 generated blob %08X" % g0, g1 - g0))
                    gaps_total += g1 - g0
            except (OSError, ValueError):
                pass
        for g0, g1 in inf["standin"]:
            gap_lines.append(("ov%03d .bss stand-in %08X" % (oid, g0), g1 - g0))
            gaps_total += g1 - g0
    gen_total = 0
    gen_lines = []
    for nm, off, data, origin in pieces:
        gen_lines.append((nm, len(data), origin))
        gen_total += len(data)
    # the data tails (.rodata/.data after the code) are compiled from C companions that
    # tools/datagen.py and tools/arm9data.py write from the user's extract
    tail_total, tail_regions = 0, 0
    for nm in ["arm9"] + ["ov%03d" % i for i in code_ids]:
        dj = os.path.join(BUILD, "datac", nm, "datalink.json")
        if os.path.exists(dj):
            t = json.load(open(dj)).get("tail")
            if t:
                tail_total += int(t[3], 16) - int(t[0], 16)
                tail_regions += 1
    stub_total = sum(o["code_size"] for o in lay["overlays"] if o["id"] in stub_ids)
    rep = dict(sha1_built=built_sha, sha1_original=orig_sha, identical=built_sha == orig_sha,
               arm9_dec_identical=same_dec, arm9_container_identical=container == orig9,
               files_differing=per_file, regions_not_linked=problems, notes=notes,
               prebuilt_files=groups, image_bytes_in_regions=gap_lines, generated_pieces=gen_lines,
               stub_overlays=dict(count=len(stub_ids), bytes=stub_total),
               data_tail_companions=dict(regions=tail_regions, bytes=tail_total), seconds=round(time.time() - t0))
    os.makedirs(os.path.dirname(a.report), exist_ok=True)
    json.dump(rep, open(a.report, "w"), indent=1)

    print("\nbytes of the final ROM that did not come from src/game:")
    for g, (n, c) in sorted(groups.items(), key=lambda kv: -kv[1][0]):
        print("  prebuilt file(s) %-28s %12d bytes in %d file(s)" % (g, n, c))
    print("  image bytes inside the linked regions: %d bytes in %d range(s)" % (gaps_total, len(gap_lines)))
    for nm, n in gap_lines[:12]:
        print("      %-40s %6d" % (nm, n))
    if len(gap_lines) > 12:
        print("      ... %d more" % (len(gap_lines) - 12))
    print("  C generated from layout/extract with no src/game file: %d bytes" % gen_total)
    for nm, n, origin in gen_lines:
        print("      %-40s %6d  %s" % (nm, n, origin))
    print("  data tails compiled from C companions generated from the extract: %d bytes in %d regions"
          % (tail_total, tail_regions))
    print("  overlays with no code, zero bytes from layout.json: %d overlays, %d bytes" % (len(stub_ids), stub_total))
    for n in notes:
        print("note: " + n)
    print("report: %s" % os.path.relpath(a.report, ROOT))
    return 0 if built_sha == orig_sha else 1


if __name__ == "__main__":
    sys.exit(main())
