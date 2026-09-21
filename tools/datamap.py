#!/usr/bin/env python3
"""Build layout/data_objects.txt: a data-object map for the ARM9 data area.

WHY THIS EXISTS

The `sole-ref` evidence class (docs/AGENT-BRIEF.md section 5) accepts a data
address only when something the project already carries says an OBJECT BEGINS
there.  Until this map existed, the only boundaries available inside the ARM9
data area were the listings' own block starts, and disasm.py emits the whole
rodata tail 0x0209D86C-0x020A8FE4 as ONE block: 47 kB with exactly one start.
Every table reference into it was therefore refused as "interior", even when
half a dozen unrelated functions across the image point at exactly that word.

This tool recovers the boundaries from sources that are all OUTSIDE any range
a matcher compares:

  1. pool     a literal-pool word, in any ARM9 unit listing or any overlay
              listing, whose value lands in an ARM9 data section.  Somebody
              loads that address into a register, so an object begins there.
              Every referrer is recorded, because the sole-ref check has to be
              able to discard a candidate's OWN reference: a lone reference
              must never mark its own start.  Targets in the ARM9 bss ranges
              of layout/layout.json count too: no listing covers bss because
              bss is not in the image, but a pool word into it is still a
              reference to an object that begins there.
  2. string   a NUL-terminated printable ASCII run in a data section.  The run
              start is an object; the byte after a terminator is another one
              when it too begins a printable run.
  3. data-decl  a `symbols:` line of kind `data` in a src/matched/*.c whose
              entry is EXACT/EXACT* in a shard (layout/matched/*/*.json).  A
              verified declaration is a statement about the address that a
              compilation already proved reproduces the image.
  4. table-guess  HEURISTIC, clearly labelled as such and never a boundary
              anything else depends on: a run of words in which a fixed stride
              repeats (the same low bits / the same near-pointer pattern every
              N bytes) is marked at its first record.  Kept separate so a
              reader can ignore the whole class.

OUTPUT

layout/data_objects.txt, one line per object start, sorted by address:

    region  start  kind  evidence

`evidence` for a pool start lists the referring sites, so a consumer can ask
"is every referrer inside lo..hi?" and refuse the start if so.

Regenerate with:  python3 tools/datamap.py
"""

import json
import os
import re
import sys
from collections import defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "layout", "data_objects.txt")

# How many referrer sites to print per pool start.  A start with dozens of
# referrers needs no more than a handful to be attested from outside any one
# range; the count is printed in full so nothing is silently dropped.
MAX_REFERRERS = 6

_LINE_ADDR_RE = re.compile(r"/\*\s*([0-9A-Fa-f]{8})[\s*]")
_DATA_DIRECTIVE_RE = re.compile(
    r"^\s*\.(word|byte|short|hword|2byte|4byte|ascii|asciz|string|space|zero)\b")
_WORD_RE = re.compile(
    r"^\s*\.word\s+0x([0-9A-Fa-f]{8})\s+/\*\s*([0-9A-Fa-f]{8})")
_POOL_DEF_RE = re.compile(r"^pool_([0-9A-Fa-f]{8}):")
_LABEL_DEF_RE = re.compile(r"^func_([0-9A-Fa-f]{8}):")


# ---------------------------------------------------------------------------
# the ARM9 data sections
# ---------------------------------------------------------------------------

def listing_files():
    """Every listing scanned for pool words: all of ARM9 and all overlays."""
    out = []
    for sub in ("src", "src_itcm"):
        d = os.path.join(ROOT, "asm", "arm9", sub)
        if os.path.isdir(d):
            out += [os.path.join(d, f) for f in sorted(os.listdir(d))
                    if f.endswith(".s")]
    d = os.path.join(ROOT, "asm", "overlays")
    if os.path.isdir(d):
        out += [os.path.join(d, f) for f in sorted(os.listdir(d))
                if f.endswith(".s")]
    return out


def arm9_listing_files():
    """Only the ARM9 unit listings: these classify the ARM9 image's bytes."""
    out = []
    for sub in ("src", "src_itcm"):
        d = os.path.join(ROOT, "asm", "arm9", sub)
        if os.path.isdir(d):
            out += [os.path.join(d, f) for f in sorted(os.listdir(d))
                    if f.endswith(".s")]
    return out


def scan_arm9_data():
    """(data_addrs, code_addrs, func_labels) for the ARM9 image.

    A byte is `data` when an ARM9 unit listing emits a .word/.byte/... datum
    at it, and `code` when it emits an instruction.  The listings overlap; the
    union is taken, and code wins, exactly as tools/match.py does it.
    """
    data = set()
    code = set()
    labels = set()
    for path in arm9_listing_files():
        with open(path, "r", errors="replace") as fh:
            for line in fh:
                m = _LABEL_DEF_RE.match(line)
                if m:
                    labels.add(int(m.group(1), 16))
                    continue
                ma = _LINE_ADDR_RE.search(line)
                if ma is None:
                    continue
                addr = int(ma.group(1), 16)
                if _DATA_DIRECTIVE_RE.match(line):
                    data.add(addr)
                else:
                    code.add(addr)
    data -= code
    return data, code, labels


def bss_ranges():
    """(lo, hi) for every ARM9 bss range layout/layout.json declares.

    No listing covers bss, because bss is not in the image, but a pool word
    pointing into it is still a reference to an object that begins there --
    and those are exactly the objects a `data` relocation names most often.
    The layout's own bss_start/bss_end is the boundary evidence, the same way
    tools/match.py's in_data_section() treats it.
    """
    with open(os.path.join(ROOT, "layout", "layout.json")) as fh:
        lay = json.load(fh)
    out = []
    a9 = lay.get("arm9") or {}
    for blk in [a9.get("static") or {}] + list(a9.get("autoloads") or []):
        lo, hi = blk.get("bss_start"), blk.get("bss_end")
        if lo and hi and hi > lo:
            out.append((lo, hi))
    return sorted(out)


def data_ranges(data):
    """Contiguous (lo, hi) runs of data addresses, hi exclusive."""
    s = sorted(data)
    if not s:
        return []
    out = []
    st = pv = s[0]
    for a in s[1:]:
        if a - pv > 4:
            out.append((st, pv + 4))
            st = a
        pv = a
    out.append((st, pv + 4))
    return out


def in_ranges(ranges, addr):
    import bisect
    i = bisect.bisect_right([lo for lo, _ in ranges], addr) - 1
    return i >= 0 and ranges[i][0] <= addr < ranges[i][1]


def func_extents(code, labels):
    """[(lo, hi)] for every traced function, so its interior is never data."""
    import bisect
    all_code = sorted(code)
    out = []
    for a in sorted(labels):
        i = bisect.bisect_right(all_code, a)
        end = a
        while i < len(all_code) and all_code[i] - end <= 4:
            end = all_code[i]
            i += 1
        out.append((a, end + 4))
    return out


# ---------------------------------------------------------------------------
# source 1: cross-references (pool words)
# ---------------------------------------------------------------------------

def scan_pool_words(ranges):
    """{target: [(site, region)]} for every pool word landing in ARM9 data.

    A `.word` counts only when it sits under a `pool_XXXXXXXX:` label, which
    is disasm.py's own statement that the word is a literal pool entry and not
    a table datum.  That keeps the class to real references.
    """
    refs = defaultdict(list)
    for path in listing_files():
        region = os.path.splitext(os.path.basename(path))[0]
        if os.sep + "src" in path and "overlays" not in path:
            # arm9 unit listing: the region is the ARM9 static module
            region = "arm9:" + region
        pools = set()
        with open(path, "r", errors="replace") as fh:
            for line in fh:
                m = _POOL_DEF_RE.match(line)
                if m:
                    pools.add(int(m.group(1), 16))
                    continue
                m = _WORD_RE.match(line)
                if m is None:
                    continue
                site = int(m.group(2), 16)
                if site not in pools:
                    continue
                val = int(m.group(1), 16)
                if in_ranges(ranges, val):
                    refs[val].append((site, region))
    return refs


# ---------------------------------------------------------------------------
# source 2: strings
# ---------------------------------------------------------------------------

PRINTABLE = set(range(0x20, 0x7F)) | {0x09, 0x0A, 0x0D}
MIN_STRING = 4


def load_arm9_image():
    """(base, bytes) for the ARM9 static module."""
    with open(os.path.join(ROOT, "layout", "layout.json")) as fh:
        layout = json.load(fh)
    a9 = layout["arm9"]
    extract = os.path.join(ROOT, layout.get("extract_dir", "extract"))
    path = os.path.join(extract, a9["decompressed_file"])
    with open(path, "rb") as fh:
        img = fh.read()
    st = a9["static"]
    return st["ram_start"], img[st["src_offset"]:st["src_offset"] + st["size"]]


def scan_strings(ranges, base, blob):
    """Starts of NUL-terminated printable ASCII runs inside data ranges.

    The first run in a range is a start; after each terminator, the next byte
    is a start too when it also begins a printable run.  A run has to be at
    least MIN_STRING characters to count, which keeps stray printable bytes in
    a numeric table from manufacturing boundaries.
    """
    starts = set()
    for lo, hi in ranges:
        i = lo
        end = min(hi, base + len(blob))
        while i < end:
            j = i
            while j < end and blob[j - base] in PRINTABLE:
                j += 1
            if j > i and j < end and blob[j - base] == 0 and j - i >= MIN_STRING:
                starts.add(i)
                # skip the terminator (and any NUL padding): the next byte
                # that begins a printable run is another object.
                k = j
                while k < end and blob[k - base] == 0:
                    k += 1
                i = k
            else:
                i = j + 1 if j > i else i + 1
    return starts


# ---------------------------------------------------------------------------
# source 3: verified declarations
# ---------------------------------------------------------------------------

_SYMLINE_RE = re.compile(
    r"^\s*\*?\s*([A-Za-z_][\w]*)\s+(0x[0-9A-Fa-f]{8})\s+(\w+)")


def verified_sources():
    """Source paths with an EXACT/EXACT* entry in some shard."""
    out = set()
    d = os.path.join(ROOT, "layout", "matched")
    for dirpath, _dirs, files in os.walk(d):
        for f in files:
            if not f.endswith(".json"):
                continue
            try:
                with open(os.path.join(dirpath, f)) as fh:
                    doc = json.load(fh)
            except (OSError, ValueError):
                continue
            for e in doc.get("functions") or []:
                if (e.get("status") or "").rstrip("*") == "EXACT":
                    src = e.get("source")
                    if src:
                        out.add(src)
    return out


def scan_declarations(ranges):
    """{addr: [source files]} for data symbols declared by verified sources."""
    ok = verified_sources()
    decls = defaultdict(list)
    d = os.path.join(ROOT, "src", "matched")
    if not os.path.isdir(d):
        return decls
    for f in sorted(os.listdir(d)):
        if not f.endswith((".c", ".cpp")):
            continue
        rel = os.path.join("src", "matched", f)
        if rel not in ok:
            continue
        in_syms = False
        with open(os.path.join(d, f), "r", errors="replace") as fh:
            for line in fh:
                s = line.strip().lstrip("*").strip()
                if s.startswith("symbols:"):
                    in_syms = True
                    continue
                if not in_syms:
                    continue
                if not s or s.endswith("*/") or ":" in s.split(" ")[0]:
                    if not _SYMLINE_RE.match(line):
                        in_syms = False
                        continue
                m = _SYMLINE_RE.match(line)
                if m is None:
                    in_syms = False
                    continue
                if m.group(3) != "data":
                    continue
                addr = int(m.group(2), 16)
                if in_ranges(ranges, addr):
                    decls[addr].append(rel)
    return decls


# ---------------------------------------------------------------------------
# source 4: periodic record structure (heuristic)
# ---------------------------------------------------------------------------

def scan_table_guesses(ranges, base, blob, known):
    """First record of a run in which a fixed word stride visibly repeats.

    HEURISTIC, and labelled as one in the output.  The test is deliberately
    narrow: inside a data run, look for at least MIN_RECORDS consecutive
    records of a stride in 8/12/16/20/24/32 bytes where the word at the same
    offset in every record is a plausible ARM9 pointer (0x02000000..0x02400000)
    or is zero in every record.  Only the FIRST record of such a group is
    marked, and only when nothing stronger already marks it.
    """
    MIN_RECORDS = 6
    STRIDES = (8, 12, 16, 20, 24, 32)
    out = {}
    for lo, hi in ranges:
        end = min(hi, base + len(blob))
        if end - lo < 64:
            continue
        words = {}

        def w(a):
            if a not in words:
                off = a - base
                words[a] = int.from_bytes(blob[off:off + 4], "little")
            return words[a]

        for stride in STRIDES:
            a = lo
            while a + stride * MIN_RECORDS <= end:
                if a in out:
                    a += 4
                    continue
                n = 0
                b = a
                while b + stride <= end:
                    v = w(b)
                    if not (0x02000000 <= v < 0x02400000):
                        break
                    n += 1
                    b += stride
                if n >= MIN_RECORDS:
                    if a not in known:
                        out[a] = (stride, n)
                    a = b
                else:
                    a += 4
    return out


# ---------------------------------------------------------------------------
# output
# ---------------------------------------------------------------------------

HEADER = """\
# data_objects.txt -- the ARM9 data-object map
#
# Object starts inside the ARM9 data sections, recovered from sources that
# all lie OUTSIDE any byte range a matcher compares.  This is what gives the
# `sole-ref` evidence class real boundaries: without it, disasm.py's block
# structure emits the whole rodata tail as one 47 kB run with a single start
# and every reference into it is refused as "interior".
#
# generated by tools/datamap.py; regenerate with `python3 tools/datamap.py`
# addresses, kinds and referrer sites only; contains no game data
#
# columns, whitespace-separated:
#   region      the region the object lives in (arm9 today)
#   start       the address the object begins at, 0x-prefixed, 8 hex digits
#   kind        pool | string | data-decl | table-guess
#   evidence    where the boundary comes from.  For `pool` it is
#               "pool word at <addr> in <region>[, ...][ (+N more)]": every
#               listed site is a literal-pool word somewhere in the image
#               whose value is this address.  A consumer checking a range
#               lo..hi MUST discard the sites inside lo..hi: a lone reference
#               never attests its own start.  For `string` it is the run's
#               length and what fixes the start.  For `data-decl` it is the
#               verified source file that declares the symbol.  For
#               `table-guess` it is the stride and record count, and the kind
#               is a HEURISTIC that nothing else should be built on.
#
# kinds, by strength:
#   pool         strongest: an instruction stream loads this exact address.
#                Covers the rodata sections and the declared bss ranges.
#   data-decl    a `symbols:` data line of a src/matched file whose entry is
#                EXACT/EXACT* in a shard.
#   string       a NUL-terminated printable run, its start fixed by the
#                preceding terminator.
#   table-guess  HEURISTIC ONLY.  Periodic record structure, no witness.
"""


def main(argv):
    quiet = "--quiet" in argv
    data, code, labels = scan_arm9_data()
    ranges = data_ranges(data)
    # an address inside a traced function is never a data object, whatever a
    # stray listing line says.
    extents = func_extents(code, labels)

    def in_code(addr):
        import bisect
        i = bisect.bisect_right([lo for lo, _ in extents], addr) - 1
        return i >= 0 and extents[i][0] <= addr < extents[i][1]

    if not quiet:
        print("data ranges: %d, %d bytes" %
              (len(ranges), sum(h - l for l, h in ranges)), file=sys.stderr)

    # Pool words may also point into bss, which no listing covers; the
    # layout's declared bss range is the boundary evidence there.  Strings
    # and the stride heuristic need image bytes and so stay out of bss.
    bss = bss_ranges()
    pool_ranges = sorted(ranges + bss)
    if not quiet:
        print("bss ranges: %d, %d bytes" %
              (len(bss), sum(h - l for l, h in bss)), file=sys.stderr)

    pools = scan_pool_words(pool_ranges)
    base, blob = load_arm9_image()
    strings = scan_strings(ranges, base, blob)
    decls = scan_declarations(ranges)

    rows = {}   # addr -> (kind, evidence)
    for addr, sites in sorted(pools.items()):
        if in_code(addr):
            continue
        shown = sites[:MAX_REFERRERS]
        ev = ", ".join("pool word at 0x%08X in %s" % (s, r) for s, r in shown)
        if len(sites) > len(shown):
            ev += " (+%d more)" % (len(sites) - len(shown))
        rows[addr] = ("pool", ev)
    for addr, srcs in sorted(decls.items()):
        if in_code(addr):
            continue
        ev = "data symbol declared by " + ", ".join(sorted(set(srcs)))
        if addr in rows:
            rows[addr] = (rows[addr][0], rows[addr][1] + "; " + ev)
        else:
            rows[addr] = ("data-decl", ev)
    for addr in sorted(strings):
        if in_code(addr) or addr in rows:
            continue
        n = 0
        while blob[addr - base + n] in PRINTABLE:
            n += 1
        rows[addr] = ("string",
                      "NUL-terminated run of %d chars, start fixed by the "
                      "preceding terminator" % n)
    guesses = scan_table_guesses(ranges, base, blob, set(rows))
    for addr, (stride, n) in sorted(guesses.items()):
        if in_code(addr) or addr in rows:
            continue
        rows[addr] = ("table-guess",
                      "HEURISTIC: %d records of stride %d" % (n, stride))

    lines = [HEADER]
    counts = defaultdict(int)
    for addr in sorted(rows):
        kind, ev = rows[addr]
        counts[kind] += 1
        lines.append("arm9  0x%08X  %-11s  %s" % (addr, kind, ev))
    with open(OUT, "w") as fh:
        fh.write("\n".join(lines) + "\n")
    if not quiet:
        for k in sorted(counts):
            print("  %-12s %6d" % (k, counts[k]), file=sys.stderr)
        print("wrote %s: %d object starts" % (OUT, len(rows)), file=sys.stderr)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
