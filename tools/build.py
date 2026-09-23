#!/usr/bin/env python3
"""
build.py -- reassemble the asm/ listings, splice in the matched C, and prove
the result is byte-identical.

For every region described by layout/layout.json (the ARM9 static module, the
ITCM autoload, the three data autoloads, every overlay and, when its bytes
exist, the DSi-mode block `twl`) this driver:

  1. assembles the listing(s) under asm/ with arm-none-eabi-as
     (-mcpu=arm946e-s, ARM/Thumb selected by the directives in the listing),
  2. links them at the region's load address with a generated linker script,
  3. objcopy's the result to a flat binary,
  4. splices in the bytes of every matched C source (see tools/csrc.py), which
     are compiled with mwccarm, placed and relocated at their real addresses,
     and required to be EXACT before they are allowed anywhere near the image;
     --no-c builds pure assembly instead,
  5. compares it byte for byte with the authoritative original bytes: the
     matching slice of extract/arm9_dec.bin for ARM9 regions, or the
     decompressed / stored overlay file for overlays,
  6. prints PASS / FAIL with first-difference diagnostics.

The listings carry the original encoding of every instruction in a trailing
``/* ADDRESS  XX XX XX XX */`` comment, so a differing byte can be mapped back
to the exact source line that produced it. That is what makes the FAIL output
actionable, and it is also how the quirk list consumed by tools/disasm.py is
generated (see ``--write-quirks``).

Toolchain discovery order:
  1. --toolchain / BW_ARM_TOOLCHAIN (a directory containing arm-none-eabi-as)
  2. tools/gcc-arm/bin, tools/gcc-arm/*/bin
  3. PATH
(implemented once in tools/env.py)

Usage
-----
    python tools/build.py                       # every region, monolithic
    python tools/build.py --split               # ARM9 regions from TUs
    python tools/build.py --only arm9_main itcm
    python tools/build.py --only arm9_main --write-quirks
    python tools/build.py --arm9-image          # rebuild whole arm9_dec.bin
    python tools/build.py --no-c                # pure assembly, for debugging
    python tools/build.py --only twl            # the DSi-mode block alone

Region `twl` (0x02700000, the autoload block of arm9i.bin) joins the run only
when extract/arm9i_dec.bin and asm/twl/twl.s exist, i.e. after delink.py and
disasm.py twl ran with a DSi key (tools/modcrypt.py).  It is compared with
its slice of the decrypted, decompressed arm9i; it is never part of
--arm9-image, --pack or the ARM9 denominator, and `--only arm9` leaves it
out.  Without a key the run is exactly the 242 regions it always was.
"""

import argparse
import json
import os
import re
import struct
import subprocess
import sys
import tempfile
import shutil
import time
from concurrent.futures import ThreadPoolExecutor

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(REPO, "tools"))

import env as toolenv  # noqa: E402  (toolchain discovery, one place)
import csrc    # noqa: E402  (bridge to the matched C sources)
import ndsrom  # noqa: E402  (slot_limits: one implementation of the layout)

# /* 020048A0  10 40 2D E9 */   or  /* 020048A0 */  or with a trailing note
_ANN = re.compile(r"/\*\s*([0-9A-F]{8})(?:\s\s((?:[0-9A-F]{2} ?)+))?")


class BuildError(Exception):
    pass


# ---------------------------------------------------------------------------
# toolchain
# ---------------------------------------------------------------------------

class Toolchain:
    TOOLS = ("as", "ld", "objcopy")

    def __init__(self, bindir, source):
        self.bindir = bindir
        self.source = source
        self.exe = {}
        for t in self.TOOLS:
            self.exe[t] = self._find(bindir, t)

    @staticmethod
    def _find(bindir, tool):
        for name in ("arm-none-eabi-%s.exe" % tool, "arm-none-eabi-%s" % tool):
            if bindir is None:
                p = shutil.which(name)
                if p:
                    return p
            else:
                p = os.path.join(bindir, name)
                if os.path.isfile(p):
                    return p
        raise BuildError("arm-none-eabi-%s not found" % tool)

    def version(self):
        out = subprocess.run([self.exe["as"], "--version"],
                             capture_output=True, text=True)
        return out.stdout.splitlines()[0] if out.stdout else "unknown"


def find_toolchain(explicit=None):
    cands = toolenv.arm_toolchain_candidates(explicit)
    problems = []
    for bindir, src in cands:
        try:
            return Toolchain(bindir, src)
        except BuildError as exc:
            problems.append("%s: %s" % (src, exc))
    raise BuildError("no ARM binutils found\n  " + "\n  ".join(problems)
                     + "\n\nInstall one, e.g. unpack the xpack "
                       "arm-none-eabi-gcc zip into tools/gcc-arm/.")


# ---------------------------------------------------------------------------
# regions
# ---------------------------------------------------------------------------

class RegionSpec:
    def __init__(self, key, name, base, original, sources, manifest=None):
        self.key = key            # short name used on the command line
        self.name = name          # section identity used by disasm.py
        self.base = base
        self.original = original  # bytes
        self.sources = sources    # list of .s paths (monolithic: exactly one)
        self.manifest = manifest  # layout/units_*.json path, or None
        self.splices = []         # csrc.Splice objects landing in this region

    @property
    def size(self):
        return len(self.original)

    def contains(self, addr):
        return self.base <= addr < self.base + self.size

    def apply_splices(self, image):
        """Overwrite the C-derived ranges in a freshly linked region image.

        Splicing flat bytes is sound here because both sides are already
        placed: the assembled region was linked at ``self.base`` and each
        Splice was compiled, laid out and relocated at its own address by
        tools/csrc.py.  A real mwld link of the C objects together with the
        assembly objects is the eventual shape and would replace this, but it
        would resolve the same addresses to the same bytes.
        """
        if not self.splices:
            return image
        out = bytearray(image)
        for sp in self.splices:
            off = sp.address - self.base
            if off < 0 or off + sp.size > len(out):
                raise BuildError(
                    "C splice %s at 0x%08X+%d does not fit region %s"
                    % (sp.name, sp.address, sp.size, self.key))
            out[off:off + sp.size] = sp.data
        return bytes(out)


def _read(path):
    if not os.path.isfile(path):
        raise BuildError("missing %s" % path)
    with open(path, "rb") as fh:
        return fh.read()


def region_specs(layout, extract_dir, asm_dir, layout_dir, split=False):
    a9 = layout["arm9"]
    image = _read(os.path.join(extract_dir, "arm9_dec.bin"))
    specs = []

    def add(key, name, base, original, listing, manifest_name=None):
        path = os.path.join(asm_dir, listing)
        sources = [path]
        manifest = None
        if split and manifest_name:
            mpath = os.path.join(layout_dir, manifest_name)
            if os.path.isfile(mpath):
                with open(mpath, "r", encoding="utf-8") as fh:
                    man = json.load(fh)
                manifest = mpath
                sources = [os.path.join(REPO, u["file"]) for u in man["units"]]
        specs.append(RegionSpec(key, name, base, original, sources, manifest))

    st = a9["static"]
    add("arm9_main", "arm9_main", st["ram_start"],
        image[st["src_offset"]:st["src_offset"] + st["size"]],
        os.path.join("arm9", "main.s"), "units_arm9.json")

    seen = {}
    for al in a9["autoloads"]:
        kind = al["kind"].lower()
        name = "arm9_%s" % kind
        if kind in ("main_twl", "other") or name in seen:
            name = "arm9_autoload%d_%s" % (al["index"], kind)
        seen[name] = True
        listing = os.path.join("arm9", name.replace("arm9_", "") + ".s")
        data = image[al["src_offset"]:al["src_offset"] + al["code_size"]]
        man = "units_itcm.json" if kind == "itcm" else None
        add(name.replace("arm9_", "") if kind == "itcm" else name,
            name, al["ram_start"], data, listing, man)

    for o in layout["overlays"]:
        listing = os.path.join("overlays", "ov%03d.s" % o["id"])
        if not os.path.isfile(os.path.join(asm_dir, listing)):
            continue
        orig = _read(os.path.join(extract_dir,
                                  o["decompressed_file"].replace("/", os.sep)))
        specs.append(RegionSpec("ov%03d" % o["id"], "overlay_%03d" % o["id"],
                                o["ram_start"], orig,
                                [os.path.join(asm_dir, listing)]))

    tw = layout.get("twl")
    if tw:
        listing = os.path.join(asm_dir, "twl", "twl.s")
        dec = os.path.join(extract_dir, tw["decompressed_file"])
        if os.path.isfile(listing) and os.path.isfile(dec):
            img = _read(dec)
            specs.append(RegionSpec(
                "twl", "twl", tw["ram_start"],
                img[tw["src_offset"]:tw["src_offset"] + tw["code_size"]],
                [listing]))
    return specs


# ---------------------------------------------------------------------------
# matched C sources
# ---------------------------------------------------------------------------

def attach_c_sources(specs, manifest, jobs=1):
    """Compile every applicable matched entry and hang it on its region.

    Only entries that land inside a region this run is actually building are
    compiled, so ``--only ov012`` does not pay for the ARM9's C.  A failure
    propagates as csrc.CSourceError and the caller turns it into a build
    failure: there is no path here that quietly keeps the assembly.
    """
    def owner(addr, region=None):
        # Overlays share load addresses, so the manifest entry's region
        # decides; the address alone only picks the first overlay in order.
        if region is not None:
            # match.py names the static image "arm9"; its build specs are
            # arm9_main and the arm9_autoload* blocks, which do not overlap.
            for s in specs:
                if s.contains(addr) and (s.key == region
                                         or s.key.startswith(region + "_")):
                    return s
            return None
        for s in specs:
            if s.contains(addr):
                return s
        return None

    kept, dropped = csrc.build_splices(manifest,
                                       keep=lambda a: owner(a) is not None,
                                       jobs=jobs)
    total = 0
    for sp in kept:
        s = owner(sp.address, sp.region)
        if s is None:
            raise csrc.CSourceError(
                "%s at 0x%08X names region %s, which is not being built"
                % (sp.name, sp.address, sp.region))
        if sp.end > s.base + s.size:
            raise csrc.CSourceError(
                "%s at 0x%08X+%d runs past region %s"
                % (sp.name, sp.address, sp.size, s.key))
        s.splices.append(sp)
        total += sp.size
    for s in specs:
        s.splices.sort(key=lambda sp: sp.address)
    return len(kept), total


# ---------------------------------------------------------------------------
# annotation index (address -> source line)
# ---------------------------------------------------------------------------

def index_annotations(paths, by_line=False):
    """address -> (path, lineno, original bytes or None, source text).

    With ``by_line`` also returns (path, lineno) -> address, which is what
    turns an assembler diagnostic into a quirk entry.
    """
    idx = {}
    lines = {}
    for path in paths:
        with open(path, "r", encoding="utf-8", errors="replace") as fh:
            for lineno, line in enumerate(fh, 1):
                if "/*" not in line:
                    continue
                m = _ANN.search(line)
                if not m:
                    continue
                addr = int(m.group(1), 16)
                raw = None
                if m.group(2):
                    raw = bytes(int(b, 16) for b in m.group(2).split())
                idx[addr] = (path, lineno, raw, line.split("/*")[0].strip())
                if by_line and raw is not None:
                    lines[(os.path.normcase(os.path.abspath(path)),
                           lineno)] = addr
    return (idx, lines) if by_line else idx


_ASM_DIAG = re.compile(r"^(.*?):(\d+): (?:Error|Warning): (.*)$")


def parse_asm_errors(text, line_index):
    """Assembler diagnostics -> [(address, message)] plus anything unmapped."""
    mapped, unmapped = [], []
    for line in text.splitlines():
        m = _ASM_DIAG.match(line.strip())
        if not m:
            continue
        path, lineno, msg = m.group(1), int(m.group(2)), m.group(3)
        key = (os.path.normcase(os.path.abspath(path)), lineno)
        addr = line_index.get(key)
        if addr is None:
            unmapped.append(line.strip())
        else:
            mapped.append((addr, msg))
    return mapped, unmapped


def describe_diff(spec, rebuilt, idx, limit=6):
    lines = []
    orig = spec.original
    if len(rebuilt) != len(orig):
        lines.append("    size: original 0x%X, rebuilt 0x%X (delta %+d)"
                     % (len(orig), len(rebuilt), len(rebuilt) - len(orig)))
    n = min(len(orig), len(rebuilt))
    diffs = []
    i = 0
    while i < n and len(diffs) < limit:
        if orig[i] != rebuilt[i]:
            j = i
            while j < n and orig[j] != rebuilt[j] and j - i < 16:
                j += 1
            diffs.append((i, j))
            i = j
        else:
            i += 1
    total = sum(1 for k in range(n) if orig[k] != rebuilt[k])
    lines.append("    %d differing byte(s)" % total)
    for start, stop in diffs:
        addr = spec.base + start
        # find the annotated line that covers this address
        owner = None
        for back in range(0, 8):
            probe = (addr - back)
            if probe in idx:
                owner = (probe, idx[probe])
                break
        lines.append("    +0x%06X (0x%08X)  orig %s  rebuilt %s"
                     % (start, addr,
                        orig[start:stop].hex(" ").upper(),
                        rebuilt[start:stop].hex(" ").upper()))
        if owner:
            paddr, (path, lineno, raw, text) = owner
            lines.append("        %s:%d  0x%08X  %s"
                         % (os.path.relpath(path, REPO).replace("\\", "/"),
                            lineno, paddr, text))
    return "\n".join(lines)


def mismatching_addresses(spec, rebuilt, idx):
    """Addresses of annotated instructions whose bytes were not reproduced.

    Only meaningful when the rebuilt image has the same length as the
    original, which means no instruction changed size and the annotation
    offsets still line up.
    """
    out = []
    if len(rebuilt) != len(spec.original):
        return None
    for addr, (path, lineno, raw, text) in idx.items():
        if raw is None:
            continue
        off = addr - spec.base
        if off < 0 or off + len(raw) > len(rebuilt):
            continue
        if rebuilt[off:off + len(raw)] != raw:
            out.append(addr)
    return sorted(out)


# ---------------------------------------------------------------------------
# assemble / link / compare
# ---------------------------------------------------------------------------

LD_TEMPLATE = """\
OUTPUT_FORMAT("elf32-littlearm")
SECTIONS
{
  . = %(base)#x;
  .text : { %(inputs)s }
  /DISCARD/ : { *(.comment) *(.note*) }
}
"""
# .ARM.attributes is deliberately NOT discarded: ld reads the architecture
# profile from it to decide whether a BLX immediate is available. Without it
# ld assumes a pre-v5 target and inserts an ARM-to-Thumb veneer instead of
# resolving the call in place, which changes both the bytes and the size.
# The section is not SHF_ALLOC, so objcopy -O binary drops it anyway.


class AsmFailure(BuildError):
    def __init__(self, message, diagnostics):
        BuildError.__init__(self, message)
        self.diagnostics = diagnostics      # raw assembler output


def assemble(tc, spec, workdir, verbose=False):
    objs = []
    for i, src in enumerate(spec.sources):
        if not os.path.isfile(src):
            raise BuildError("missing listing %s" % src)
        obj = os.path.join(workdir, "u%04d.o" % i)
        cmd = [tc.exe["as"], "-mcpu=arm946e-s", "-EL", "-W",
               "-o", obj, src]
        r = subprocess.run(cmd, capture_output=True, text=True)
        if r.returncode != 0:
            out = (r.stderr or r.stdout)
            msg = out.strip().splitlines()
            raise AsmFailure("as failed on %s\n      %s"
                             % (os.path.relpath(src, REPO),
                                "\n      ".join(msg[:20])), out)
        objs.append(obj)
    return objs


def link(tc, spec, objs, workdir):
    script = os.path.join(workdir, "link.ld")
    if len(objs) == 1:
        inputs = "*(.text*)"
    else:
        # Keep the translation units in manifest order.
        inputs = " ".join("%s(.text*)" % os.path.basename(o).replace("\\", "/")
                          for o in objs)
    with open(script, "w", encoding="utf-8", newline="\n") as fh:
        fh.write(LD_TEMPLATE % {"base": spec.base, "inputs": inputs})
    elf = os.path.join(workdir, "out.elf")
    # --use-blx: let ld resolve an ARM->Thumb call with a BLX immediate, which
    # is what the original build did. Without it ld appends an interworking
    # veneer and rewrites the call to reach it.
    cmd = [tc.exe["ld"], "-T", "link.ld", "--no-warn-mismatch", "--use-blx",
           "-e", "0", "-o", "out.elf"] + [os.path.basename(o) for o in objs]
    r = subprocess.run(cmd, capture_output=True, text=True, cwd=workdir)
    if r.returncode != 0:
        msg = (r.stderr or r.stdout).strip().splitlines()
        raise BuildError("ld failed\n      " + "\n      ".join(msg[:25]))
    flat = os.path.join(workdir, "out.bin")
    r = subprocess.run([tc.exe["objcopy"], "-O", "binary", elf, flat],
                       capture_output=True, text=True)
    if r.returncode != 0:
        raise BuildError("objcopy failed\n      " + (r.stderr or r.stdout))
    return _read(flat)


class Result:
    def __init__(self, spec):
        self.spec = spec
        self.ok = False
        self.error = None
        self.detail = ""
        self.rebuilt = None
        self.bad_addrs = None
        self.rejected = []


def build_region(tc, spec, keep_dir=None, want_quirks=False):
    res = Result(spec)
    workdir = keep_dir or tempfile.mkdtemp(prefix="bwasm_")
    os.makedirs(workdir, exist_ok=True)
    try:
        objs = assemble(tc, spec, workdir)
        rebuilt = spec.apply_splices(link(tc, spec, objs, workdir))
        res.rebuilt = rebuilt
        if rebuilt == spec.original:
            res.ok = True
        else:
            idx = index_annotations(spec.sources)
            res.detail = describe_diff(spec, rebuilt, idx)
            if want_quirks:
                res.bad_addrs = mismatching_addresses(spec, rebuilt, idx)
    except AsmFailure as exc:
        res.error = str(exc)
        idx, lines = index_annotations(spec.sources, by_line=True)
        mapped, unmapped = parse_asm_errors(exc.diagnostics, lines)
        res.rejected = mapped
        if want_quirks:
            res.bad_addrs = sorted(set(a for a, _ in mapped))
        if unmapped:
            res.error += ("\n      (%d diagnostic(s) could not be mapped to "
                          "an instruction, e.g. %s)"
                          % (len(unmapped), unmapped[0]))
    except BuildError as exc:
        res.error = str(exc)
    finally:
        if keep_dir is None:
            shutil.rmtree(workdir, ignore_errors=True)
    return res


# ---------------------------------------------------------------------------
# whole-ARM9-image reassembly
# ---------------------------------------------------------------------------

def rebuild_arm9_image(layout, results, extract_dir, out_path):
    a9 = layout["arm9"]
    image = bytearray(_read(os.path.join(extract_dir, "arm9_dec.bin")))
    want = bytearray(len(image))
    st = a9["static"]
    by_base = {r.spec.base: r for r in results}
    covered = 0
    # Region load address -> where its payload sits in the packed image.
    mapping = [(st["ram_start"], st["src_offset"], st["size"])]
    for al in a9["autoloads"]:
        mapping.append((al["ram_start"], al["src_offset"], al["code_size"]))
    missing = []
    for base, src_off, size in mapping:
        r = by_base.get(base)
        if r is None or r.rebuilt is None or len(r.rebuilt) != size:
            missing.append("0x%08X" % base)
            want[src_off:src_off + size] = image[src_off:src_off + size]
            continue
        want[src_off:src_off + size] = r.rebuilt
        covered += size
    # The tail of arm9_dec.bin past the last autoload payload is the autoload
    # info table itself, which is data the linker emits, not disassembly.
    tail_start = max(s + n for _, s, n in mapping)
    want[tail_start:] = image[tail_start:]
    os.makedirs(os.path.dirname(out_path) or ".", exist_ok=True)
    with open(out_path, "wb") as fh:
        fh.write(want)
    return bytes(want) == bytes(image), covered, missing, tail_start


# ---------------------------------------------------------------------------
# recompression: turn reassembled images back into ROM-ready binaries
# ---------------------------------------------------------------------------

def pack_arm9(layout, image):
    """BLZ-recompress the ARM9 image, keeping its build info self-consistent.

    The NTR build info at ``arm9 + build_info_offset`` carries
    ``compressed_code_end``, which is the load address plus the *compressed*
    container's length, and the startup code hands that address to the
    in-place decompressor.  So the field depends on the compression and the
    compression depends on the field.  The dependency is real rather than
    theoretical: the field sits at image offset 0xFC4, inside the BLZ verbatim
    prefix, and while a prefix byte is never itself encoded, back-references
    from the encoded region can reach into the prefix, so changing it can move
    a token.

    It is also a contraction in practice, so the fixpoint is reached by
    iterating: compress, write the length the result implies, compress again,
    stop when the field the image carries is the one the container wants.

    Returns (container, image, iterations).
    """
    import blz
    img = bytearray(image)
    off = layout["arm9"]["build_info_offset"] + 0x14
    load = layout["arm9"]["load_address"]
    data = None
    for it in range(1, 9):
        data = blz.compress(bytes(img), blz.ARM9_SECURE_AREA)
        want = load + len(data)
        if struct.unpack_from("<I", img, off)[0] == want:
            return data, bytes(img), it
        struct.pack_into("<I", img, off, want)
    raise BuildError(
        "the ARM9 build info's compressed_code_end did not settle after 8 "
        "recompressions; the container length is oscillating")


def pack_binaries(layout, results, arm9_image, pack_dir, slots=None,
                  strict=False):
    """Write BLZ-recompressed arm9.bin and all overlay files into pack_dir.

    Nothing here reads the original compressed binaries: the ARM9 container is
    built from the reassembled decompressed image and every overlay from its
    reassembled region.

    A container that came out a different length than the original is not an
    error any more.  It is checked against the *slot* it occupies in the ROM,
    that is its offset up to wherever the extracted layout puts the next file,
    padding included; ndsrom.py then updates the header and the tables.
    ``strict`` restores the old behaviour of demanding the original size, and
    ``slots`` is ndsrom.slot_limits() over the extract manifest.  Returns
    (written, problems, changes).
    """
    import blz

    by_key = {r.spec.key: r for r in results}
    problems = []
    changes = []
    written = 0

    def put(relpath, data, want_size, what):
        nonlocal written
        n = len(data)
        if want_size is not None and n != want_size:
            if strict:
                problems.append("%s: recompressed to %d bytes, ROM slot is %d "
                                "(--pack-fixed-size)" % (what, n, want_size))
                return
            limit = (slots or {}).get(relpath, {}).get("limit")
            if limit is None:
                problems.append("%s: recompressed to %d bytes, original %d, "
                                "and no slot is recorded for %s"
                                % (what, n, want_size, relpath))
                return
            if n > limit:
                problems.append(
                    "%s: recompressed to %d (0x%X) bytes but its ROM slot "
                    "holds only %d (0x%X); %d byte(s) too many"
                    % (what, n, n, limit, limit, n - limit))
                return
            changes.append((what, relpath, want_size, n, limit))
        path = os.path.join(pack_dir, relpath.replace("/", os.sep))
        os.makedirs(os.path.dirname(path) or ".", exist_ok=True)
        with open(path, "wb") as fh:
            fh.write(data)
        written += 1

    container, _img, iters = pack_arm9(layout, arm9_image)
    if iters > 1:
        changes.append(("arm9 build info", "arm9.bin", None, None, None))
    put("arm9.bin", container, layout["arm9"]["rom_size"], "arm9")

    for o in layout["overlays"]:
        key = "ov%03d" % o["id"]
        r = by_key.get(key)
        if r is None or r.rebuilt is None:
            problems.append("%s: not reassembled in this run" % key)
            continue
        if len(r.rebuilt) != o["code_size"]:
            problems.append("%s: reassembled to %d bytes, expected %d"
                            % (key, len(r.rebuilt), o["code_size"]))
            continue
        data = blz.compress(r.rebuilt) if o["compressed"] else r.rebuilt
        put(o["file"], data, o["file_size"], key)

    return written, problems, changes


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main(argv=None):
    ap = argparse.ArgumentParser(
        prog="build.py",
        description="Reassemble asm/ listings and verify byte-identity.")
    ap.add_argument("-e", "--extract", default=os.path.join(REPO, "extract"))
    ap.add_argument("-l", "--layout", default=os.path.join(REPO, "layout"))
    ap.add_argument("-a", "--asm", default=os.path.join(REPO, "asm"))
    ap.add_argument("-b", "--build", default=os.path.join(REPO, "build"))
    ap.add_argument("--toolchain", help="directory holding arm-none-eabi-as")
    ap.add_argument("--only", nargs="+", metavar="KEY",
                    help="build only these regions (arm9_main, itcm, "
                         "ov012, twl, ...); 'overlays' means every overlay, "
                         "'arm9' the ARM9 image's regions")
    ap.add_argument("--split", action="store_true",
                    help="build ARM9 regions from their translation units "
                         "(layout/units_*.json) instead of the monolithic "
                         "listing")
    ap.add_argument("--no-c", action="store_true",
                    help="do not compile or splice the matched C sources; "
                         "build the regions from asm/ alone. For debugging an "
                         "assembly problem without the compiler in the way")
    ap.add_argument("--c-manifest", default=None,
                    help="one manifest shard file instead of every shard "
                         "under layout/matched/")
    ap.add_argument("--write-quirks", action="store_true",
                    help="record instructions the assembler re-encoded into "
                         "layout/reasm_quirks.json for tools/disasm.py")
    ap.add_argument("--arm9-image", action="store_true",
                    help="also reassemble the whole decompressed ARM9 image "
                         "and compare with extract/arm9_dec.bin")
    ap.add_argument("--pack", nargs="?", metavar="DIR",
                    const=os.path.join(REPO, "build", "pack"),
                    help="BLZ-recompress the reassembled ARM9 image and every "
                         "overlay into DIR (default build/pack), ready for "
                         "'ndsrom.py build --override DIR'. Implies "
                         "--arm9-image")
    ap.add_argument("--pack-fixed-size", action="store_true",
                    help="fail if a recompressed container is not exactly the "
                         "size the original ROM carried, instead of letting "
                         "it grow into the padding of its ROM slot")
    ap.add_argument("-j", "--jobs", type=int, default=os.cpu_count() or 4)
    ap.add_argument("--keep", metavar="DIR",
                    help="keep intermediate objects in DIR (single region)")
    args = ap.parse_args(argv)

    with open(os.path.join(args.layout, "layout.json"), "r",
              encoding="utf-8") as fh:
        layout = json.load(fh)

    try:
        tc = find_toolchain(args.toolchain)
    except BuildError as exc:
        print("error: %s" % exc, file=sys.stderr)
        return 2
    print("[*] assembler: %s" % tc.version())
    print("[*]   from %s (%s)" % (tc.bindir or "PATH", tc.source))

    specs = region_specs(layout, args.extract, args.asm, args.layout,
                         split=args.split)
    if args.only:
        want = set(args.only)
        chosen = []
        for s in specs:
            if s.key in want or s.name in want:
                chosen.append(s)
            elif "overlays" in want and s.key.startswith("ov"):
                chosen.append(s)
            elif ("arm9" in want and not s.key.startswith("ov")
                  and s.key != "twl"):
                chosen.append(s)
        specs = chosen
    if not specs:
        print("error: no matching regions", file=sys.stderr)
        return 2

    print("[*] %d region(s)%s" % (len(specs),
                                  " (translation units)" if args.split else ""))

    if not args.no_c:
        try:
            nspliced, nbytes = attach_c_sources(specs, args.c_manifest,
                                                jobs=args.jobs)
        except csrc.CSourceError as exc:
            print()
            print("error: matched C source regression: %s" % exc,
                  file=sys.stderr)
            if exc.detail:
                print(exc.detail, file=sys.stderr)
            print("\n[*] the build does NOT fall back to asm/ for a matched "
                  "entry.\n    Fix the C, or pass --no-c to build pure "
                  "assembly while debugging.", file=sys.stderr)
            return 1
        if nspliced:
            print("[*] C sources: %d entr(ies), 0x%X (%d) byte(s) spliced "
                  "from src/" % (nspliced, nbytes, nbytes))
        else:
            print("[*] C sources: nothing applies to the selected region(s)")
    else:
        print("[*] C sources: disabled (--no-c), building pure assembly")

    results = []
    if args.keep and len(specs) == 1:
        results = [build_region(tc, specs[0], keep_dir=args.keep,
                                want_quirks=args.write_quirks)]
    else:
        with ThreadPoolExecutor(max_workers=max(1, args.jobs)) as pool:
            futs = [pool.submit(build_region, tc, s, None, args.write_quirks)
                    for s in specs]
            for f in futs:
                results.append(f.result())

    npass = nfail = 0
    print()
    print("    %-14s %-12s %10s   %s" % ("region", "base", "size", "result"))
    for r in results:
        s = r.spec
        if r.ok:
            npass += 1
            verdict = "PASS"
        else:
            nfail += 1
            verdict = "FAIL"
        nunits = (" [%d TUs]" % len(s.sources)) if len(s.sources) > 1 else ""
        if s.splices:
            nunits += " [%d C, 0x%X bytes]" % (
                len(s.splices), sum(sp.size for sp in s.splices))
        print("    %-14s 0x%08X   0x%07X   %s%s"
              % (s.key, s.base, s.size, verdict, nunits))
        if r.error:
            print("      error: %s" % r.error)
            if r.rejected:
                kinds = {}
                for _, msg in r.rejected:
                    key = re.sub(r"`.*'", "`...'", msg)
                    kinds[key] = kinds.get(key, 0) + 1
                print("      %d instruction(s) rejected, %d distinct "
                      "diagnostic(s):" % (len(r.rejected), len(kinds)))
                for key, cnt in sorted(kinds.items(), key=lambda kv: -kv[1]):
                    print("        %6d  %s" % (cnt, key))
        elif not r.ok:
            print(r.detail)

    print()
    print("[*] %d PASS, %d FAIL" % (npass, nfail))

    if args.write_quirks:
        path = os.path.join(args.layout, "reasm_quirks.json")
        existing = {"tool": "build.py", "version": 1,
                    "note": "addresses of instructions GNU as re-encodes "
                            "differently; disasm.py emits these as raw "
                            ".inst/.word so the bytes stay exact. Addresses "
                            "only, no game data.",
                    "regions": {}}
        if os.path.isfile(path):
            with open(path, "r", encoding="utf-8") as fh:
                existing = json.load(fh)
                existing.setdefault("regions", {})
        added = 0
        for r in results:
            if r.bad_addrs is None:
                continue
            cur = set(existing["regions"].get(r.spec.name, []))
            new = set("0x%08X" % a for a in r.bad_addrs)
            added += len(new - cur)
            existing["regions"][r.spec.name] = sorted(cur | new)
        with open(path, "w", encoding="utf-8", newline="\n") as fh:
            json.dump(existing, fh, indent=1, sort_keys=True)
            fh.write("\n")
        print("[*] quirks: %d new address(es) -> %s"
              % (added, os.path.relpath(path, REPO).replace("\\", "/")))

    arm9_image = None
    if args.arm9_image or args.pack:
        out = os.path.join(args.build, "arm9_dec_rebuilt.bin")
        ok, covered, missing, tail = rebuild_arm9_image(
            layout, results, args.extract, out)
        arm9_image = _read(out)
        print()
        print("[*] whole ARM9 image: %s" % ("PASS" if ok else "FAIL"))
        print("    0x%X bytes came from reassembly, 0x%X..end is the autoload "
              "info table (data)" % (covered, tail))
        if missing:
            print("    not rebuilt: %s" % ", ".join(missing))
        print("    wrote %s" % os.path.relpath(out, REPO).replace("\\", "/"))
        if not ok:
            nfail += 1

    if args.pack:
        t0 = time.time()
        slots = None
        mpath = os.path.join(args.extract, "manifest.json")
        if os.path.isfile(mpath):
            with open(mpath, "r", encoding="utf-8") as fh:
                slots = ndsrom.slot_limits(json.load(fh))
        written, problems, changes = pack_binaries(
            layout, results, arm9_image, args.pack, slots,
            strict=args.pack_fixed_size)
        print()
        print("[*] BLZ recompression: %d file(s) -> %s (%.1fs)"
              % (written, os.path.relpath(args.pack, REPO).replace("\\", "/"),
                 time.time() - t0))
        if slots:
            s = slots.get("arm9.bin", {})
            print("    arm9 slot: 0x%X at 0x%X, original content 0x%X, "
                  "0x%X byte(s) of padding to the next file"
                  % (s.get("limit", 0), s.get("offset", 0), s.get("size", 0),
                     s.get("limit", 0) - s.get("size", 0)))
        for what, relpath, old, new, limit in changes:
            if old is None:
                print("    %s: compressed_code_end updated to match the new "
                      "container length" % what)
            else:
                print("    %s: 0x%X -> 0x%X (%+d), slot 0x%X, 0x%X byte(s) "
                      "of slack left" % (what, old, new, new - old, limit,
                                         limit - new))
        for p in problems:
            print("    problem: %s" % p)
        if problems:
            nfail += 1

    return 0 if nfail == 0 else 1


if __name__ == "__main__":
    try:
        sys.exit(main())
    except BuildError as exc:
        print("error: %s" % exc, file=sys.stderr)
        sys.exit(2)
