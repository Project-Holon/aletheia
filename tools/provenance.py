#!/usr/bin/env python3
"""
provenance.py -- where does every byte of the built ROM come from?

A read-only report over an existing build.  It never rebuilds anything and
never writes into the repository; its only scratch file is a cache under the
system temp directory (see --cache).  No game bytes are printed or stored:
the output is counts, sizes and percentages.

How the ROM is assembled (tools/build.py, tools/csrc.py, tools/ndsrom.py):

  * every ARM9 region (the static module, the ITCM autoload, the three small
    autoloads) and every overlay is reassembled from its listing under asm/;
  * the ranges owned by a matched C entry (layout/matched/) are then
    overwritten by the bytes the compiler produced (csrc.Splice);
  * the reassembled ARM9 image is BLZ-recompressed into build/pack/arm9.bin
    and each compressed overlay into build/pack/overlays/; the ARM9 image tail
    past the last autoload payload (the autoload info table) is copied from
    extract/arm9_dec.bin verbatim;
  * ndsrom.py lays every other manifest region (header, banner, digest
    tables, ARM7, ARM9i, FNT, FAT, y9 table, the NitroFS files, residue) into
    a 0xFF-filled image from extract/, then patches the header CRC and the
    sizes of any container that changed length.

Accounting rules:

  * ARM9 and the overlays are BLZ-compressed on the ROM.  Their categories
    are counted on the DECOMPRESSED image, which is what the listings and
    the C describe.  A separate stored-bytes table (Table A) sums to exactly
    the ROM size and shows what the compression saves.
  * Inside a reassembled image a byte is "compiled from C" when a spliced
    entry covers it (whatever the listing said there), "reassembled code"
    when a listing line carries an encoded instruction, and "reassembled data
    words" for listing data (.word/.byte/...) and for any byte the listing
    leaves to assembler fill (reported separately as gap fill).
  * The DSi-mode block (twl) is only verified by build.py, never packed; the
    ROM carries arm9i.bin copied from extract/, so it is counted as a copied
    binary and not as an image.

Usage:
    python tools/provenance.py                 # text tables
    python tools/provenance.py --json          # machine-readable
    python tools/provenance.py --per-overlay   # one row per overlay
    python tools/provenance.py --verify        # also compare ROM slices with
                                               # the files they were copied from
    python tools/provenance.py --assets        # also count converter-covered
                                               # filesystem files (slow, cached)
    python tools/provenance.py --cache-only    # use the splice cache even if
                                               # stale; never run the compiler

Compiling the matched C is the slow step (minutes).  The extent of each
spliced entry is cached per entry (a hash of the manifest entry and of its
source file), so a run after an unrelated edit only compiles what changed.
"""

import argparse
import hashlib
import json
import os
import re
import struct
import sys
import tempfile
import time

sys.dont_write_bytecode = True   # a read-only tool must not create __pycache__

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(REPO, "tools"))

CACHE_VERSION = 3
CAT_GAP, CAT_CODE, CAT_DATA = 0, 1, 2

_ANN = re.compile(r"/\*\s*([0-9A-F]{8})\s\s((?:[0-9A-F]{2} ?)+)")
_NOBYTES = {".global", ".globl", ".type", ".thumb_func", ".thumb", ".arm",
            ".syntax", ".section", ".end", ".size", ".code", ".text", ".data",
            ".fnstart", ".fnend", ".weak", ".local", ".ltorg", ".pool"}


# ---------------------------------------------------------------------------
# small helpers
# ---------------------------------------------------------------------------

def rel(path):
    return os.path.relpath(path, REPO).replace("\\", "/")


def load_json(path):
    with open(path, "r", encoding="utf-8") as fh:
        return json.load(fh)


def pct(part, whole):
    return 100.0 * part / whole if whole else 0.0


# ---------------------------------------------------------------------------
# listing classifier: code vs data per byte
# ---------------------------------------------------------------------------

def classify_listing(paths, base, size):
    """(bytearray of CAT_* per byte, stats dict) for one region's listing(s).

    The listing is read the way the assembler reads it: a location counter
    moved by ``.org`` and advanced by every instruction, ``.word`` and
    ``.byte``.  An instruction line carries its original encoding in the
    trailing comment, which gives its width and lets the counter re-sync
    against the annotated address (counted in ``resyncs``).
    """
    cat = bytearray(size)
    stats = {"resyncs": 0, "unknown": {}, "overrun": 0}
    pos = 0
    for path in paths:
        with open(path, "r", encoding="utf-8", errors="replace") as fh:
            for line in fh:
                s = line.strip()
                if not s or s[0] in "/*;@":
                    continue
                if s[0] != ".":
                    m = _ANN.search(line)
                    if m is None:
                        continue                      # a label or a comment
                    n = len(m.group(2).split())
                    addr = int(m.group(1), 16) - base
                    if addr != pos:
                        stats["resyncs"] += 1
                        pos = addr
                    kind = CAT_CODE
                else:
                    tok = s.split(None, 1)
                    d = tok[0]
                    if d == ".org":
                        pos = int(tok[1].split()[0], 0)
                        continue
                    m = _ANN.search(line)
                    if m and d.startswith(".inst"):
                        n = len(m.group(2).split())
                        addr = int(m.group(1), 16) - base
                        if addr != pos:
                            stats["resyncs"] += 1
                            pos = addr
                        kind = CAT_CODE
                    elif d == ".word" or d == ".long" or d == ".int":
                        n = 4 * (tok[1].split("/*")[0].count(",") + 1)
                        kind = CAT_DATA
                    elif d in (".hword", ".short", ".2byte"):
                        n = 2 * (tok[1].split("/*")[0].count(",") + 1)
                        kind = CAT_DATA
                    elif d == ".byte":
                        n = tok[1].split("/*")[0].count(",") + 1
                        kind = CAT_DATA
                    elif d in (".space", ".skip", ".zero"):
                        n = int(tok[1].split(",")[0].split("/*")[0], 0)
                        kind = CAT_DATA
                    elif d in _NOBYTES:
                        continue
                    else:
                        stats["unknown"][d] = stats["unknown"].get(d, 0) + 1
                        continue
                if pos < 0 or pos + n > size:
                    stats["overrun"] += 1
                    n = max(0, min(n, size - pos))
                if n:
                    cat[pos:pos + n] = bytes([kind]) * n
                pos += n
    return cat, stats


# ---------------------------------------------------------------------------
# splices (the compiled C), with a cache outside the repository
# ---------------------------------------------------------------------------

def entry_key(entry):
    """Cache key of one manifest entry: the entry itself and its source file.

    The extent of a splice is the range the entry claims in the original
    image (an EXACT entry reproduces exactly those bytes), so it can only
    move when the manifest entry or its source file changes.
    """
    h = hashlib.sha1(json.dumps(entry, sort_keys=True).encode())
    src = os.path.join(REPO, entry["source"].replace("/", os.sep))
    try:
        with open(src, "rb") as fh:
            h.update(hashlib.sha1(fh.read()).digest())
    except OSError:
        h.update(b"missing")
    return h.hexdigest()


def get_splices(specs, jobs, cache_path, cache_only, log):
    """{region key: [(address, size, name, kind), ...]}, plus a source note.

    Mirrors build.attach_c_sources: the manifest entries are selected and
    compiled by csrc, overlaps are resolved the same way, and an entry is
    attached to the region build.py would give it.  Only entries not in the
    cache (per-entry key, see entry_key) are compiled.
    """
    import csrc
    import match

    cache = {}
    if os.path.isfile(cache_path):
        try:
            doc = load_json(cache_path)
            if doc.get("version") == CACHE_VERSION:
                cache = doc["entries"]
        except (OSError, ValueError, KeyError):
            cache = {}

    def owner(addr, region=None):
        if region is not None:
            for s in specs:
                if s.contains(addr) and (s.key == region or
                                         s.key.startswith(region + "_")):
                    return s
            return None
        for s in specs:
            if s.contains(addr):
                return s
        return None

    entries = csrc.select(csrc.load_manifest(None),
                          lambda a: owner(a) is not None)
    keys = [entry_key(e) for e in entries]
    todo = [(e, k) for e, k in zip(entries, keys) if k not in cache]
    hit = len(entries) - len(todo)
    if todo and cache_only:
        log("--cache-only: %d entr(ies) not in the cache are skipped" %
            len(todo))
        todo = []
    if todo:
        log("compiling %d of %d matched entr(ies) to learn splice extents "
            "(%d cached) ..." % (len(todo), len(entries), hit))
        t0 = time.time()
        match.load_all_regions()
        match.evidence()
        match.sdk_symbols()
        match.matched_symbols()
        from concurrent.futures import ThreadPoolExecutor
        fails = []
        with ThreadPoolExecutor(max_workers=max(1, jobs)) as pool:
            futs = [(e, k, pool.submit(csrc.compile_entry, e))
                    for e, k in todo]
            for e, k, f in futs:
                try:
                    sp = f.result()
                except csrc.CSourceError as exc:
                    fails.append("%s: %s" % (e["name"], exc))
                    continue
                cache[k] = {"size": sp.size, "region": sp.region}
        log("compiled in %.0fs" % (time.time() - t0))
        if fails:
            raise SystemExit("error: %d matched entr(ies) no longer "
                             "reproduce; the build would fail:\n  %s"
                             % (len(fails), "\n  ".join(fails[:10])))
        try:
            os.makedirs(os.path.dirname(cache_path), exist_ok=True)
            with open(cache_path, "w", encoding="utf-8") as fh:
                json.dump({"version": CACHE_VERSION, "entries": cache}, fh)
        except OSError as exc:
            log("warning: cannot write cache: %s" % exc)

    sps = []
    for e, k in zip(entries, keys):
        c = cache.get(k)
        if c is None:
            continue
        sps.append(csrc.Splice(e["name"], int(e["address"], 16),
                               b"\0" * c["size"], e["source"], e["kind"],
                               c["region"]))
    kept, _dropped = csrc.resolve_overlaps(sps)
    out = {s.key: [] for s in specs}
    for sp in kept:
        s = owner(sp.address, sp.region)
        if s is None:
            continue
        if sp.end > s.base + s.size:
            raise SystemExit("error: %s runs past region %s" % (sp.name, s.key))
        out[s.key].append((sp.address, sp.size, sp.name, sp.kind))
    note = ("%d entries: %d from cache, %d compiled now (cache %s)"
            % (len(entries), hit, len(todo), cache_path))
    return out, note, 0


# ---------------------------------------------------------------------------
# images
# ---------------------------------------------------------------------------

class Image:
    """One reassembled region: per-byte category counts."""

    def __init__(self, key, kind, size):
        self.key = key
        self.kind = kind          # arm9 | overlay
        self.size = size
        self.c = self.code = self.data = self.gap = 0
        self.copied = 0           # bytes copied from extract (arm9 info table)
        self.c_entries = 0
        self.c_kinds = {}         # entry kind -> spliced bytes
        self.stats = {}

    def as_dict(self):
        return {"key": self.key, "kind": self.kind, "bytes": self.size,
                "c": self.c, "code": self.code, "data_words": self.data,
                "gap_fill": self.gap, "copied_tail": self.copied,
                "c_entries": self.c_entries}


def account_image(spec, splice_list):
    cat, stats = classify_listing(spec.sources, spec.base, spec.size)
    covered = bytearray(spec.size)          # 1 where a splice owns the byte
    kinds = {}
    for addr, size, _name, kind in splice_list:
        kinds[kind] = kinds.get(kind, 0) + size
        off = addr - spec.base
        covered[off:off + size] = b"\x01" * size
    img = Image(spec.key, "overlay" if spec.key.startswith("ov") else "arm9",
                spec.size)
    img.stats = stats
    img.c_kinds = kinds
    img.c = covered.count(1)
    img.c_entries = len(splice_list)
    # count the listing categories outside the splices without a per-byte loop
    if img.c:
        rest = bytes(c if not v else 3 for c, v in zip(cat, covered))
    else:
        rest = bytes(cat)
    img.code = rest.count(CAT_CODE)
    img.data = rest.count(CAT_DATA)
    img.gap = rest.count(CAT_GAP)
    # gap fill is data as far as provenance goes; keep it visible separately
    return img


# ---------------------------------------------------------------------------
# assets: converter-covered filesystem files (opt-in, cached)
# ---------------------------------------------------------------------------

def _asset_worker(args):
    path, relpath = args
    sys.dont_write_bytecode = True
    sys.path.insert(0, os.path.join(REPO, "tools", "assets"))
    import narc
    import verify_all
    size = os.path.getsize(path)
    try:
        n = narc.parse_file(path)
    except Exception:                                   # not a NARC
        return relpath, size, None
    counts = {"pass": 0, "fail": 0, "skipped": 0}
    pass_bytes = 0
    for sf in n.subfiles:
        try:
            raw = n.read(sf.index)
        except Exception:
            counts["fail"] += 1
            continue
        try:
            verdict, _m = verify_all.verify_subfile(raw)
        except Exception:
            verdict = "fail"
        counts[verdict] += 1
        if verdict == "pass":
            pass_bytes += len(raw)
    return relpath, size, {"counts": counts, "pass_bytes": pass_bytes,
                           "subfiles": len(n.subfiles)}


def assets_report(extract, jobs, cache_path, log):
    root = os.path.join(extract, "data")
    files = []
    for r, ds, fs in os.walk(root):
        ds.sort()
        for f in sorted(fs):
            p = os.path.join(r, f)
            files.append((p, os.path.relpath(p, root).replace("\\", "/")))
    cache = {}
    if os.path.isfile(cache_path):
        try:
            cache = load_json(cache_path)
        except (OSError, ValueError):
            cache = {}
    todo, results = [], {}
    for p, r in files:
        st = os.stat(p)
        ent = cache.get(r)
        if ent and ent["size"] == st.st_size and ent["mtime"] == st.st_mtime_ns:
            results[r] = ent
        else:
            todo.append((p, r))
    if todo:
        log("assets: verifying %d filesystem file(s) through the converters "
            "(cached afterwards) ..." % len(todo))
        from concurrent.futures import ProcessPoolExecutor
        with ProcessPoolExecutor(max_workers=max(1, jobs)) as pool:
            for r, size, res in pool.map(_asset_worker, todo, chunksize=1):
                st = os.stat(os.path.join(root, r.replace("/", os.sep)))
                results[r] = {"size": size, "mtime": st.st_mtime_ns,
                              "narc": res}
        try:
            os.makedirs(os.path.dirname(cache_path), exist_ok=True)
            with open(cache_path, "w", encoding="utf-8") as fh:
                json.dump(results, fh)
        except OSError as exc:
            log("warning: cannot write assets cache: %s" % exc)
    narcs = [v for v in results.values() if v.get("narc")]
    full = [v for v in narcs if v["narc"]["subfiles"] and
            v["narc"]["counts"]["pass"] == v["narc"]["subfiles"]]
    sub = {"pass": 0, "fail": 0, "skipped": 0}
    for v in narcs:
        for k in sub:
            sub[k] += v["narc"]["counts"][k]
    return {
        "files": len(results),
        "files_bytes": sum(v["size"] for v in results.values()),
        "narc_files": len(narcs),
        "files_fully_converter_covered": len(full),
        "files_fully_converter_covered_bytes": sum(v["size"] for v in full),
        "subfiles": sub,
        "subfile_pass_bytes": sum(v["narc"]["pass_bytes"] for v in narcs),
        "note": ("a file counts when it is a NARC and every sub-file passes "
                 "verify_all.verify_subfile (LZ layer re-encoded and format "
                 "layer parse/encode byte-identical); the NARC container "
                 "framing itself has no encoder and is not re-checked"),
    }


# ---------------------------------------------------------------------------
# the report
# ---------------------------------------------------------------------------

def build_report(args, log):
    import build as buildmod
    import ndsrom

    extract = os.path.abspath(args.extract)
    layout_dir = os.path.join(REPO, "layout")
    layout = load_json(os.path.join(layout_dir, "layout.json"))
    man = load_json(os.path.join(extract, "manifest.json"))
    pack = os.path.join(args.build, "pack")
    rom_path = os.path.join(args.build, "pokeblack.nds")
    if not os.path.isdir(pack):
        raise SystemExit("error: %s missing; run tools/build.py --pack first"
                         % rel(pack))

    rom_size = man["rom_size"]
    specs = buildmod.region_specs(layout, extract, os.path.join(REPO, "asm"),
                                  layout_dir, split=False)
    specs = [s for s in specs if s.key != "twl"]

    cache_path = args.cache or os.path.join(
        tempfile.gettempdir(), "aletheia", "provenance_splices.json")
    splices, splice_note, _ = get_splices(specs, args.jobs, cache_path,
                                          args.cache_only, log)

    images = []
    for s in specs:
        images.append(account_image(s, splices.get(s.key, [])))

    # ---- the ARM9 image tail (autoload info table), copied from extract ----
    a9 = layout["arm9"]
    dec_size = a9["decompressed_size"]
    arm9_payload = sum(i.size for i in images if i.kind == "arm9")
    tail = dec_size - arm9_payload
    if tail < 0:
        raise SystemExit("error: ARM9 regions exceed the decompressed image")
    tail_img = Image("arm9_tail", "arm9", tail)
    tail_img.copied = tail
    images.append(tail_img)

    arm9_imgs = [i for i in images if i.kind == "arm9"]
    ov_imgs = [i for i in images if i.kind == "overlay"]

    # ---- stored (on-ROM) sizes ----
    def stored(relpath, fallback):
        p = os.path.join(pack, relpath.replace("/", os.sep))
        return os.path.getsize(p) if os.path.isfile(p) else fallback

    arm9_stored = stored("arm9.bin", a9["rom_size"])
    ov_stored = 0
    ov_dec = 0
    ov_missing = 0
    for o in layout["overlays"]:
        p = os.path.join(pack, o["file"].replace("/", os.sep))
        if not os.path.isfile(p):
            ov_missing += 1
        ov_stored += stored(o["file"], o["file_size"])
        ov_dec += o["code_size"]

    groups = {"header": 0, "digest": 0, "banner": 0, "arm7": 0, "arm7i": 0,
              "arm9i": 0, "fnt": 0, "fat": 0, "y9": 0, "fs": 0,
              "fs_files": 0, "residue": 0}
    for r in man["regions"]:
        n, sz = r["name"], r["size"]
        if not sz:
            continue
        if n in ("header", "header_ext"):
            groups["header"] += sz
        elif n.startswith("digest_"):
            groups["digest"] += sz
        elif n == "banner":
            groups["banner"] += sz
        elif n.startswith("fs:"):
            groups["fs"] += sz
            groups["fs_files"] += 1
        elif n in groups:
            groups[n] += sz
        elif n == "arm9" or n.startswith("overlay_"):
            pass
        else:
            raise SystemExit("error: unclassified manifest region %r" % n)
    groups["residue"] = sum(r["size"] for r in man.get("residue", []))

    copied_bin = (groups["arm7"] + groups["arm7i"] + groups["arm9i"] +
                  groups["fnt"] + groups["fat"] + groups["y9"] +
                  groups["residue"])
    hdr_sig = groups["header"] + groups["digest"] + groups["banner"]
    stored_content = (arm9_stored + ov_stored + groups["fs"] + copied_bin +
                      hdr_sig)
    padding = rom_size - stored_content
    used = man.get("used_rom_size_twl", man.get("used_rom_size_ntr", rom_size))
    pad_tail = max(0, rom_size - used)
    pad_interior = padding - pad_tail

    img_c = sum(i.c for i in images)
    img_code = sum(i.code for i in images)
    img_data = sum(i.data + i.gap for i in images)
    img_gap = sum(i.gap for i in images)
    img_copied = sum(i.copied for i in images)
    img_total = arm9_payload + tail + ov_dec
    if img_c + img_code + img_data + img_copied != img_total:
        raise SystemExit("internal error: image categories do not sum")

    accounted = img_total + groups["fs"] + copied_bin + hdr_sig + padding
    cats = [
        ("compiled from our C (spliced matched entries)", img_c, True),
        ("reassembled from listings (code)", img_code, True),
        ("reassembled from listings (data words)", img_data, True),
        ("filesystem files copied from extract", groups["fs"], False),
        ("ARM7 and other binaries copied",
         copied_bin + img_copied, False),
        ("header, signature, digest tables, banner", hdr_sig, False),
        ("padding (0xFF fill)", padding, False),
    ]
    rep = {
        "rom_size": rom_size,
        "rom_sha1_manifest": man.get("rom_sha1"),
        "built_rom_present": os.path.isfile(rom_path),
        "accounted_total": accounted,
        "images_total": img_total,
        "splice_source": splice_note,
        "categories": [
            {"name": n, "bytes": b,
             "pct_of_rom": pct(b, rom_size),
             "pct_of_accounted": pct(b, accounted),
             "pct_of_images": pct(b, img_total) if im else None}
            for n, b, im in cats],
        "stored_view": {
            "arm9_container": arm9_stored,
            "overlay_containers": ov_stored,
            "filesystem": groups["fs"],
            "copied_binaries": copied_bin,
            "header_signature_banner": hdr_sig,
            "padding": padding,
            "padding_interior": pad_interior,
            "padding_after_used_rom": pad_tail,
            "total": stored_content + padding,
        },
        "compression": {
            "arm9_stored": arm9_stored, "arm9_decompressed": dec_size,
            "overlays_stored": ov_stored, "overlays_decompressed": ov_dec,
            "overlays_missing_from_pack": ov_missing,
        },
        "details": {
            "gap_fill_bytes_in_data": img_gap,
            "c_bytes_by_entry_kind": _kind_sum(images),
            "copied_binaries": {k: groups[k] for k in
                                ("arm7", "arm7i", "arm9i", "fnt", "fat",
                                 "y9", "residue")},
            "arm9_info_table_bytes": tail,
            "header_signature_banner": {k: groups[k] for k in
                                        ("header", "digest", "banner")},
            "fs_files": groups["fs_files"],
        },
        "regions": {
            "arm9": {**_sum_images(arm9_imgs), "stored": arm9_stored,
                     "parts": [i.as_dict() for i in arm9_imgs]},
            "overlays": {**_sum_images(ov_imgs), "stored": ov_stored,
                         "count": len(ov_imgs)},
            "arm7": {"stored": groups["arm7"], "copied": groups["arm7"]},
            "arm7i": {"stored": groups["arm7i"], "copied": groups["arm7i"]},
            "arm9i": {"stored": groups["arm9i"], "copied": groups["arm9i"]},
            "filesystem": {"stored": groups["fs"], "files": groups["fs_files"],
                           "copied": groups["fs"]},
        },
        "listing_checks": {
            i.key: {"resyncs": i.stats.get("resyncs", 0),
                    "unknown_directives": i.stats.get("unknown", {}),
                    "overrun": i.stats.get("overrun", 0)}
            for i in images if i.stats and (i.stats.get("resyncs") or
                                            i.stats.get("unknown") or
                                            i.stats.get("overrun"))},
    }
    if args.per_overlay:
        rep["overlays"] = [i.as_dict() for i in ov_imgs]
    if args.verify:
        rep["verify"] = verify_rom(man, layout, extract, pack, rom_path)
    if args.assets:
        acache = os.path.join(tempfile.gettempdir(), "aletheia",
                              "provenance_assets.json")
        rep["assets"] = assets_report(extract, args.jobs, acache, log)
    return rep


def _kind_sum(imgs):
    out = {}
    for i in imgs:
        for k, v in i.c_kinds.items():
            out[k] = out.get(k, 0) + v
    return dict(sorted(out.items()))


def _sum_images(imgs):
    return {"image_bytes": sum(i.size for i in imgs),
            "c": sum(i.c for i in imgs),
            "code": sum(i.code for i in imgs),
            "data_words": sum(i.data + i.gap for i in imgs),
            "copied_tail": sum(i.copied for i in imgs),
            "c_entries": sum(i.c_entries for i in imgs)}


# ---------------------------------------------------------------------------
# --verify: the ROM really contains what the accounting says
# ---------------------------------------------------------------------------

def verify_rom(man, layout, extract, pack, rom_path):
    if not os.path.isfile(rom_path):
        return {"error": "build/pokeblack.nds not present"}
    ok = bad = 0
    patched = {}
    problems = []
    with open(rom_path, "rb") as rom:
        for r in man["regions"] + [dict(x, name="residue_%s" % x.get("index"))
                                   for x in man.get("residue", [])]:
            if not r["size"] or not r.get("path"):
                continue
            n = r["name"]
            src = os.path.join(pack, r["path"].replace("/", os.sep))
            if not (n == "arm9" or n.startswith("overlay_")) or \
                    not os.path.isfile(src):
                src = os.path.join(extract, r["path"].replace("/", os.sep))
            if not os.path.isfile(src):
                problems.append("%s: source missing" % n)
                continue
            with open(src, "rb") as fh:
                want = fh.read()
            rom.seek(r["offset"])
            got = rom.read(len(want))
            if got == want:
                ok += 1
            else:
                bad += 1
                diff = sum(1 for a, b in zip(got, want) if a != b)
                patched[n] = diff
    return {"regions_identical_to_source": ok,
            "regions_that_differ": bad,
            "differing_bytes_by_region": patched,
            "problems": problems,
            "note": ("differences are the header CRC, FAT and y9 entries "
                     "ndsrom.py patches when a recompressed container "
                     "changed length")}


# ---------------------------------------------------------------------------
# text output
# ---------------------------------------------------------------------------

def fmt_pct(v):
    return "%7.3f%%" % v if v is not None else "%8s" % "-"


def print_text(rep, per_overlay):
    rs = rep["rom_size"]
    print("Provenance of the built ROM (0x%X = %d bytes)" % (rs, rs))
    print("splice extents: %s" % rep["splice_source"])
    print()
    print("Table A: stored bytes on the ROM (sums to the ROM size)")
    sv = rep["stored_view"]
    rows = [("ARM9 container (BLZ)", sv["arm9_container"]),
            ("overlay containers (BLZ or stored)", sv["overlay_containers"]),
            ("filesystem files", sv["filesystem"]),
            ("ARM7, ARM9i, FNT, FAT, y9, residue", sv["copied_binaries"]),
            ("header, digest tables, banner", sv["header_signature_banner"]),
            ("padding: gaps and container slack", sv["padding_interior"]),
            ("padding: after the used ROM size", sv["padding_after_used_rom"])]
    for n, b in rows:
        print("  %-42s %12d  %s" % (n, b, fmt_pct(pct(b, rs))))
    print("  %-42s %12d  %s" % ("total", sv["total"], fmt_pct(pct(sv["total"], rs))))
    c = rep["compression"]
    print("  compression: arm9 %d -> %d bytes, overlays %d -> %d bytes"
          % (c["arm9_stored"], c["arm9_decompressed"],
             c["overlays_stored"], c["overlays_decompressed"]))
    print()
    print("Table B: provenance by category. ARM9 and overlay bytes are counted "
          "on the")
    print("decompressed images, so the total exceeds the ROM size by the "
          "compression saving.")
    print("  %-46s %13s %9s %9s %9s" % ("category", "bytes", "of ROM",
                                        "of total", "of images"))
    for k in rep["categories"]:
        print("  %-46s %13d %s %s %s"
              % (k["name"], k["bytes"], fmt_pct(k["pct_of_rom"]),
                 fmt_pct(k["pct_of_accounted"]), fmt_pct(k["pct_of_images"])))
    print("  %-46s %13d" % ("accounted total", rep["accounted_total"]))
    print("  %-46s %13d" % ("code+data images (ARM9 + overlays, decompressed)",
                            rep["images_total"]))
    d = rep["details"]
    print("  C bytes by manifest entry kind: %s" % ", ".join(
        "%s %d" % kv for kv in d["c_bytes_by_entry_kind"].items()))
    print("  (data words include %d byte(s) of assembler gap fill; the ARM9 "
          "autoload info table, %d bytes, is copied from extract and counted "
          "with the copied binaries)" % (d["gap_fill_bytes_in_data"],
                                         d["arm9_info_table_bytes"]))
    print()
    print("Table C: by region")
    print("  %-14s %11s %11s %11s %11s %11s %8s"
          % ("region", "stored", "image", "C", "code", "data words", "C of img"))
    for name in ("arm9", "overlays"):
        r = rep["regions"][name]
        extra = " (%d)" % r["count"] if name == "overlays" else ""
        print("  %-14s %11d %11d %11d %11d %11d %s"
              % (name + extra, r["stored"], r["image_bytes"], r["c"],
                 r["code"], r["data_words"],
                 fmt_pct(pct(r["c"], r["image_bytes"]))))
    for p in rep["regions"]["arm9"]["parts"]:
        print("    %-12s %11s %11d %11d %11d %11d %s"
              % (p["key"], "", p["bytes"], p["c"], p["code"],
                 p["data_words"] + p["gap_fill"],
                 fmt_pct(pct(p["c"], p["bytes"]))))
    for name in ("arm7", "arm7i", "arm9i"):
        r = rep["regions"][name]
        print("  %-14s %11d %11s   copied from extract" % (name, r["stored"], ""))
    r = rep["regions"]["filesystem"]
    print("  %-14s %11d %11s   %d files copied from extract"
          % ("filesystem", r["stored"], "", r["files"]))
    if per_overlay:
        print()
        print("Per overlay: %-6s %9s %9s %9s %9s %8s"
              % ("id", "bytes", "C", "code", "data", "C%"))
        for o in rep["overlays"]:
            print("  %-6s %9d %9d %9d %9d %s"
                  % (o["key"], o["bytes"], o["c"], o["code"],
                     o["data_words"] + o["gap_fill"],
                     fmt_pct(pct(o["c"], o["bytes"]))))
    lc = rep["listing_checks"]
    if lc:
        print()
        print("Listing parser notes (should be empty):")
        for k, v in sorted(lc.items()):
            print("  %s: %s" % (k, v))
    if "verify" in rep:
        v = rep["verify"]
        print()
        print("Verify against the built ROM:")
        if "error" in v:
            print("  " + v["error"])
        else:
            print("  %d region(s) byte-identical to their source file, %d "
                  "differ %s" % (v["regions_identical_to_source"],
                                 v["regions_that_differ"],
                                 v["differing_bytes_by_region"] or ""))
            if v["regions_that_differ"]:
                print("  (%s)" % v["note"])
    if "assets" in rep:
        a = rep["assets"]
        print()
        print("Filesystem files whose converters round-trip today:")
        print("  %d of %d files (%d bytes of %d) are NARCs whose every "
              "sub-file passes"
              % (a["files_fully_converter_covered"], a["files"],
                 a["files_fully_converter_covered_bytes"], a["files_bytes"]))
        s = a["subfiles"]
        print("  sub-files in %d NARCs: %d pass, %d skipped, %d fail "
              "(%d bytes pass)"
              % (a["narc_files"], s["pass"], s["skipped"], s["fail"],
                 a["subfile_pass_bytes"]))
        print("  (%s)" % a["note"])


def main(argv=None):
    ap = argparse.ArgumentParser(
        description="Read-only report of where every ROM byte comes from.")
    ap.add_argument("-e", "--extract", default=os.path.join(REPO, "extract"))
    ap.add_argument("-b", "--build", default=os.path.join(REPO, "build"))
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--per-overlay", action="store_true")
    ap.add_argument("--verify", action="store_true")
    ap.add_argument("--assets", action="store_true")
    ap.add_argument("--cache", default=None,
                    help="splice cache file (default: <tmp>/aletheia/"
                         "provenance_splices.json)")
    ap.add_argument("--cache-only", action="store_true")
    ap.add_argument("-j", "--jobs", type=int, default=os.cpu_count() or 4)
    args = ap.parse_args(argv)

    def log(msg):
        print("[*] " + msg, file=sys.stderr)

    rep = build_report(args, log)
    if args.json:
        json.dump(rep, sys.stdout, indent=1)
        sys.stdout.write("\n")
    else:
        print_text(rep, args.per_overlay)
    return 0


if __name__ == "__main__":
    sys.exit(main())
