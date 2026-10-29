#!/usr/bin/env python3
"""
ndsrom.py -- Nintendo DS / DSi (TWL) ROM unpacker, repacker and verifier.

Written from scratch for aletheia. Stdlib only, single file.

The guiding principle is *byte-exactness*: every byte of the cartridge image is
either (a) covered by a modelled region that we understand and extract, (b) the
ROM padding byte (0xFF), or (c) captured verbatim by the "residue" pass.  Build
reverses that exactly, so extract -> build is bit-identical by construction.

--------------------------------------------------------------------------
NDS cartridge header (first 0x200 bytes; the header *area* is header_size,
0x4000 on this cart, and the first 0x1000 is what we snapshot as header.bin)
--------------------------------------------------------------------------
  0x000  char[12]  game title            ("POKEMON B")
  0x00C  char[4]   game code             ("IRBO")
  0x010  char[2]   maker code            ("01")
  0x012  u8        unit code             (0x02 = NTR+TWL, i.e. DSi enhanced)
  0x020  u32       arm9 ROM offset
  0x024  u32       arm9 entry address
  0x028  u32       arm9 RAM load address
  0x02C  u32       arm9 size
  0x030  u32       arm7 ROM offset
  0x034  u32       arm7 entry address
  0x038  u32       arm7 RAM load address
  0x03C  u32       arm7 size
  0x040  u32       FNT (file name table) offset
  0x044  u32       FNT size
  0x048  u32       FAT (file allocation table) offset
  0x04C  u32       FAT size
  0x050  u32       arm9 overlay table (y9) offset
  0x054  u32       arm9 overlay table size
  0x058  u32       arm7 overlay table (y7) offset
  0x05C  u32       arm7 overlay table size
  0x068  u32       icon/banner offset
  0x080  u32       total used ROM size (NTR region)
  0x084  u32       header size

DSi extended header fields (only meaningful when unit code has bit 1 set):
  0x1C0  u32       arm9i ROM offset
  0x1C8  u32       arm9i RAM load address
  0x1CC  u32       arm9i size
  0x1D0  u32       arm7i ROM offset
  0x1D8  u32       arm7i RAM load address
  0x1DC  u32       arm7i size
  0x1E0  u32       digest NTR region offset
  0x1E4  u32       digest NTR region length
  0x1E8  u32       digest TWL region offset
  0x1EC  u32       digest TWL region length
  0x1F0  u32       digest sector hashtable offset
  0x1F4  u32       digest sector hashtable length
  0x1F8  u32       digest block hashtable offset
  0x1FC  u32       digest block hashtable length
  0x208  u32       banner size
  0x210  u32       total used ROM size including the DSi (TWL) area

--------------------------------------------------------------------------
Overlay table entry (32 bytes, in y9.bin / y7.bin)
--------------------------------------------------------------------------
  0x00  u32  overlay id
  0x04  u32  RAM load address
  0x08  u32  size to copy
  0x0C  u32  .bss size
  0x10  u32  static initialiser start address
  0x14  u32  static initialiser end address
  0x18  u32  file id  (index into the FAT -> where the overlay bytes live)
  0x1C  u32  compressed size (24 bits) | flags (8 bits)

--------------------------------------------------------------------------
FAT entry (8 bytes each, FAT size / 8 entries, indexed by file id)
--------------------------------------------------------------------------
  0x00  u32  start offset in ROM
  0x04  u32  end offset in ROM (exclusive)

--------------------------------------------------------------------------
FNT -- file name table
--------------------------------------------------------------------------
Main table, 8 bytes per directory, directory 0 = root:
  0x00  u32  offset of this directory's subtable, relative to FNT start
  0x04  u16  file id of the first file in this directory
  0x06  u16  parent directory id  (for the root entry: total directory count)

Sub-table, a sequence of entries terminated by a 0x00 length byte:
  u8 len
     len == 0x00          -> end of this directory
     0x01..0x7F           -> file,      followed by `len` name bytes
     0x81..0xFF           -> directory, followed by (len & 0x7F) name bytes
                             and then a u16 directory id (0xF000 | index)
Files are numbered sequentially from the directory's first file id, in the
order they appear in the sub-table.
"""

import argparse
import hashlib
import json
import os
import re
import struct
import sys

# ---------------------------------------------------------------------------
# constants
# ---------------------------------------------------------------------------

PAD_BYTE = 0xFF          # unused cartridge space is 0xFF filled
HEADER_SNAPSHOT = 0x1000  # bytes of the header area saved as header.bin
OVERLAY_ENTRY_SIZE = 32
FAT_ENTRY_SIZE = 8
FNT_MAIN_ENTRY_SIZE = 8
RESIDUE_COALESCE_GAP = 64  # merge residue runs closer together than this

EXPECTED_GAMECODE = b"IRBO"
try:
    from targets import GAMECODES as KNOWN_GAMECODES   # every cartridge in tools/targets.py
except ImportError:
    KNOWN_GAMECODES = (b"IRBO", b"IRAO")  # Pokemon Black and Pokemon White (USA, Europe)

# characters Windows refuses in a filename, plus the path separators
_UNSAFE_RE = re.compile(rb'[\x00-\x1f<>:"/\\|?*]')
_WIN_RESERVED = {
    "CON", "PRN", "AUX", "NUL",
    *(f"COM{i}" for i in range(1, 10)),
    *(f"LPT{i}" for i in range(1, 10)),
}


class RomError(Exception):
    """Raised for any structural problem; the CLI turns it into a loud error."""


# ---------------------------------------------------------------------------
# small helpers
# ---------------------------------------------------------------------------

def u16(buf, off):
    return struct.unpack_from("<H", buf, off)[0]


def u32(buf, off):
    return struct.unpack_from("<I", buf, off)[0]


def sha1_of(data):
    return hashlib.sha1(data).hexdigest()


def crc16(data, init=0xFFFF):
    """The CRC-16 the NDS header uses: reflected, poly 0xA001, init 0xFFFF.

    Verified against this cartridge rather than assumed: the stored header CRC
    at 0x15E reproduces over header[0x000..0x15D] and the stored Nintendo logo
    CRC at 0x15C reproduces over header[0x0C0..0x15B].
    """
    crc = init
    for b in data:
        crc ^= b
        for _ in range(8):
            crc = (crc >> 1) ^ 0xA001 if crc & 1 else crc >> 1
    return crc & 0xFFFF


def header_crc(rom):
    return crc16(rom[0x000:0x15E])


def logo_crc(rom):
    return crc16(rom[0x0C0:0x15C])


# ---------------------------------------------------------------------------
# ROM slots: how far a region may grow before it hits the next one
# ---------------------------------------------------------------------------

def slot_limits(man):
    """{relpath: {offset, size, limit}} for every placed file in the manifest.

    ``limit`` is how many bytes the file may occupy without colliding with
    whatever the extracted layout puts next (another region, or a residue
    blob), i.e. the size of its slot including the 0xFF padding that follows
    it.  This is what makes a variable-size repack possible without moving
    anything: a container may grow into its own padding and no further, and
    exceeding it is a loud failure rather than a silently corrupted image.
    """
    iv = []
    for r in man["regions"]:
        if r["size"] and r.get("path"):
            iv.append((r["offset"], r["size"], r["path"]))
    for r in man.get("residue", []):
        if r["size"]:
            iv.append((r["offset"], r["size"], r["path"]))
    iv.sort()
    starts = sorted(s for s, _n, _p in iv)
    rom_size = man["rom_size"]
    out = {}
    import bisect
    for off, size, path in iv:
        i = bisect.bisect_right(starts, off)
        nxt = starts[i] if i < len(starts) else rom_size
        out[path] = {"offset": off, "size": size, "limit": nxt - off}
    return out


def sanitize_name(raw):
    """Turn a raw FNT name into something safe to put on a Windows filesystem.

    NitroFS names are plain ASCII in practice, but we never trust input bytes.
    The manifest keeps the original name so nothing is lost.
    """
    safe = _UNSAFE_RE.sub(b"_", raw)
    name = safe.decode("ascii", errors="replace").replace("�", "_")
    name = name.rstrip(" .")           # Windows strips these silently
    if not name:
        name = "_"
    if name.split(".")[0].upper() in _WIN_RESERVED:
        name = "_" + name
    return name


def ensure_parent(path):
    parent = os.path.dirname(path)
    if parent:
        os.makedirs(parent, exist_ok=True)


# ---------------------------------------------------------------------------
# region bookkeeping
# ---------------------------------------------------------------------------

class RegionMap:
    """Collects (offset, size, path) regions and checks they never overlap."""

    def __init__(self, rom_size):
        self.rom_size = rom_size
        self.regions = []   # list of dicts, manifest-ready

    def add(self, name, offset, size, path, **extra):
        if size == 0:
            # Empty FAT slots are legal; record them for documentation only.
            rec = {"name": name, "offset": offset, "size": 0, "path": None}
            rec.update(extra)
            self.regions.append(rec)
            return rec
        if offset < 0 or offset + size > self.rom_size:
            raise RomError(
                f"region {name!r} at 0x{offset:X}+0x{size:X} runs past the end "
                f"of the ROM (0x{self.rom_size:X})"
            )
        rec = {"name": name, "offset": offset, "size": size, "path": path}
        rec.update(extra)
        self.regions.append(rec)
        return rec

    def occupied_intervals(self):
        """Sorted, merged list of (start, end) covered by non-empty regions."""
        iv = sorted((r["offset"], r["offset"] + r["size"])
                    for r in self.regions if r["size"])
        merged = []
        for start, end in iv:
            if merged and start < merged[-1][1]:
                raise RomError(
                    f"overlapping regions detected near 0x{start:X} "
                    f"(previous region ends at 0x{merged[-1][1]:X})"
                )
            if merged and start == merged[-1][1]:
                merged[-1][1] = end
            else:
                merged.append([start, end])
        return [(a, b) for a, b in merged]


# ---------------------------------------------------------------------------
# NitroFS parsing
# ---------------------------------------------------------------------------

def parse_fat(rom, fat_off, fat_size):
    """Return a list of (start, end) tuples, one per file id."""
    if fat_size % FAT_ENTRY_SIZE:
        raise RomError(
            f"FAT size 0x{fat_size:X} is not a multiple of "
            f"{FAT_ENTRY_SIZE} bytes"
        )
    count = fat_size // FAT_ENTRY_SIZE
    fat = []
    for i in range(count):
        base = fat_off + i * FAT_ENTRY_SIZE
        start = u32(rom, base)
        end = u32(rom, base + 4)
        if end < start:
            raise RomError(
                f"FAT entry {i}: end 0x{end:X} precedes start 0x{start:X}"
            )
        if end > len(rom):
            raise RomError(
                f"FAT entry {i}: end 0x{end:X} runs past the end of the ROM"
            )
        fat.append((start, end))
    return fat


def parse_fnt(rom, fnt_off, fnt_size):
    """Walk the FNT and return a list of (relative_path, file_id) tuples.

    Paths use forward slashes; components are already sanitized.
    """
    if fnt_size < FNT_MAIN_ENTRY_SIZE:
        raise RomError(f"FNT size 0x{fnt_size:X} is too small to hold a root")
    fnt = rom[fnt_off:fnt_off + fnt_size]

    # The root entry's "parent id" field doubles as the directory count.
    dir_count = u16(fnt, 6)
    if dir_count == 0 or dir_count * FNT_MAIN_ENTRY_SIZE > fnt_size:
        raise RomError(
            f"FNT reports {dir_count} directories, which does not fit in "
            f"0x{fnt_size:X} bytes"
        )

    files = []          # (path, file_id)
    seen_ids = set()

    def walk(dir_index, prefix):
        if dir_index >= dir_count:
            raise RomError(f"FNT directory index {dir_index} is out of range")
        base = dir_index * FNT_MAIN_ENTRY_SIZE
        sub_off = u32(fnt, base)
        next_file_id = u16(fnt, base + 4)
        if sub_off >= fnt_size:
            raise RomError(
                f"FNT directory {dir_index}: subtable offset 0x{sub_off:X} "
                f"is outside the FNT (size 0x{fnt_size:X})"
            )
        p = sub_off
        while True:
            if p >= fnt_size:
                raise RomError(
                    f"FNT directory {dir_index}: subtable ran off the end "
                    "without a terminator"
                )
            length = fnt[p]
            p += 1
            if length == 0x00:
                break                      # end of directory
            is_dir = bool(length & 0x80)
            name_len = length & 0x7F
            if name_len == 0:
                raise RomError(
                    f"FNT directory {dir_index}: zero-length name at "
                    f"offset 0x{p - 1:X}"
                )
            raw = bytes(fnt[p:p + name_len])
            p += name_len
            name = sanitize_name(raw)
            if is_dir:
                if p + 2 > fnt_size:
                    raise RomError(
                        f"FNT directory {dir_index}: truncated subdirectory id"
                    )
                sub_id = u16(fnt, p)
                p += 2
                # Directory ids are 0xF000 | index.
                walk(sub_id & 0x0FFF, prefix + name + "/")
            else:
                fid = next_file_id
                next_file_id += 1
                if fid in seen_ids:
                    raise RomError(f"FNT lists file id {fid} more than once")
                seen_ids.add(fid)
                files.append((prefix + name, fid))

    walk(0, "")
    return files


# ---------------------------------------------------------------------------
# extract
# ---------------------------------------------------------------------------

def cmd_extract(args):
    rom_path = os.path.abspath(args.rom)
    out_dir = os.path.abspath(args.out)

    with open(rom_path, "rb") as fh:
        rom = fh.read()
    rom_size = len(rom)
    print(f"[*] read {rom_path}")
    print(f"    size 0x{rom_size:X} ({rom_size} bytes)")

    rom_sha1 = sha1_of(rom)
    print(f"    sha1 {rom_sha1}")

    # --- header sanity -----------------------------------------------------
    gamecode = rom[0x0C:0x10]
    if gamecode not in KNOWN_GAMECODES:
        raise RomError(
            f"unexpected game code {gamecode!r}; expected one of "
            f"{KNOWN_GAMECODES!r} (a cartridge listed in tools/targets.py)"
        )
    unit_code = rom[0x12]
    is_twl = bool(unit_code & 0x02)
    header_size = u32(rom, 0x84)
    title = rom[0x00:0x0C].rstrip(b"\x00").decode("ascii", "replace")
    print(f"    title {title!r}  gamecode {gamecode.decode()}  "
          f"unitcode 0x{unit_code:02X} (TWL={is_twl})")
    if header_size < HEADER_SNAPSHOT:
        raise RomError(f"header size 0x{header_size:X} is implausibly small")

    rmap = RegionMap(rom_size)
    os.makedirs(out_dir, exist_ok=True)

    def dump(name, offset, size, relpath, **extra):
        """Write [offset, offset+size) to out_dir/relpath and record it."""
        rec = rmap.add(name, offset, size, relpath, **extra)
        if size:
            full = os.path.join(out_dir, relpath.replace("/", os.sep))
            ensure_parent(full)
            with open(full, "wb") as f:
                f.write(rom[offset:offset + size])
        return rec

    # --- header ------------------------------------------------------------
    dump("header", 0, HEADER_SNAPSHOT, "header.bin")
    # The header *area* is header_size (0x4000 here); everything above our
    # 0x1000 snapshot is the DSi extended header / signature space.
    if header_size > HEADER_SNAPSHOT:
        dump("header_ext", HEADER_SNAPSHOT, header_size - HEADER_SNAPSHOT,
             "header_ext.bin")

    # --- arm9 / arm7 -------------------------------------------------------
    arm9_off, arm9_size = u32(rom, 0x20), u32(rom, 0x2C)
    arm7_off, arm7_size = u32(rom, 0x30), u32(rom, 0x3C)
    dump("arm9", arm9_off, arm9_size, "arm9.bin",
         load=u32(rom, 0x28), entry=u32(rom, 0x24))
    dump("arm7", arm7_off, arm7_size, "arm7.bin",
         load=u32(rom, 0x38), entry=u32(rom, 0x34))
    print(f"    arm9 0x{arm9_off:X}+0x{arm9_size:X}  "
          f"arm7 0x{arm7_off:X}+0x{arm7_size:X}")

    # --- FNT / FAT ---------------------------------------------------------
    fnt_off, fnt_size = u32(rom, 0x40), u32(rom, 0x44)
    fat_off, fat_size = u32(rom, 0x48), u32(rom, 0x4C)
    dump("fnt", fnt_off, fnt_size, "fnt.bin")
    dump("fat", fat_off, fat_size, "fat.bin")
    fat = parse_fat(rom, fat_off, fat_size)
    print(f"    FAT 0x{fat_off:X}+0x{fat_size:X} -> {len(fat)} entries")

    # --- overlay tables and overlay files ----------------------------------
    overlay_meta = []
    used_by_overlay = set()
    for tag, toff_field, tsize_field in (("y9", 0x50, 0x54), ("y7", 0x58, 0x5C)):
        toff, tsize = u32(rom, toff_field), u32(rom, tsize_field)
        if tsize == 0:
            continue
        if tsize % OVERLAY_ENTRY_SIZE:
            raise RomError(
                f"{tag} table size 0x{tsize:X} is not a multiple of "
                f"{OVERLAY_ENTRY_SIZE}"
            )
        dump(tag, toff, tsize, f"{tag}.bin")
        count = tsize // OVERLAY_ENTRY_SIZE
        print(f"    {tag} 0x{toff:X}+0x{tsize:X} -> {count} overlays")
        for i in range(count):
            e = toff + i * OVERLAY_ENTRY_SIZE
            ov_id = u32(rom, e + 0x00)
            file_id = u32(rom, e + 0x18)
            if file_id >= len(fat):
                raise RomError(
                    f"{tag} overlay {i}: file id {file_id} is outside the FAT "
                    f"({len(fat)} entries)"
                )
            start, end = fat[file_id]
            relpath = f"overlays/{tag}_{ov_id:04d}.bin"
            dump(f"overlay_{tag}_{ov_id}", start, end - start, relpath,
                 file_id=file_id, overlay_id=ov_id, table=tag,
                 load=u32(rom, e + 0x04), bss_size=u32(rom, e + 0x0C))
            used_by_overlay.add(file_id)
            overlay_meta.append(relpath)

    # --- NitroFS files -----------------------------------------------------
    fs_files = parse_fnt(rom, fnt_off, fnt_size)
    print(f"    FNT 0x{fnt_off:X}+0x{fnt_size:X} -> {len(fs_files)} files")
    data_count = 0
    for relpath, fid in fs_files:
        if fid >= len(fat):
            raise RomError(
                f"NitroFS file {relpath!r}: file id {fid} is outside the FAT"
            )
        if fid in used_by_overlay:
            raise RomError(
                f"NitroFS file {relpath!r} claims file id {fid}, which is "
                "already used by an overlay"
            )
        start, end = fat[fid]
        dump(f"fs:{relpath}", start, end - start, "data/" + relpath,
             file_id=fid, fs_path=relpath)
        data_count += 1

    # Any FAT slot nobody referenced: extract it anyway so the round-trip is
    # not relying on the residue pass for real file data.
    referenced = used_by_overlay | {f for _, f in fs_files}
    orphans = 0
    for fid, (start, end) in enumerate(fat):
        if fid in referenced or end <= start:
            continue
        dump(f"orphan_{fid}", start, end - start,
             f"orphans/{fid:04d}.bin", file_id=fid)
        orphans += 1
    if orphans:
        print(f"    {orphans} FAT entries not referenced by FNT or overlays")

    # --- banner ------------------------------------------------------------
    # Banner version (u16 at banner+0) tells us how big it is:
    #   0x0001 original, 0x0002 +Chinese, 0x0003 +Korean, 0x0103 DSi animated
    banner_off = u32(rom, 0x68)
    if banner_off:
        banner_ver = u16(rom, banner_off)
        by_version = {0x0001: 0x0840, 0x0002: 0x0940,
                      0x0003: 0x0A40, 0x0103: 0x23C0}
        hdr_banner_size = u32(rom, 0x208) if is_twl else 0
        banner_size = by_version.get(banner_ver)
        if banner_size is None:
            # Unknown version: trust the header field, else a safe maximum.
            banner_size = hdr_banner_size or 0x23C0
            print(f"    [!] unknown banner version 0x{banner_ver:04X}, "
                  f"using size 0x{banner_size:X}")
        elif hdr_banner_size and hdr_banner_size != banner_size:
            # Header wins -- it is what the hardware reads.
            print(f"    [!] banner version 0x{banner_ver:04X} implies "
                  f"0x{banner_size:X} but header says 0x{hdr_banner_size:X}; "
                  "using the header value")
            banner_size = hdr_banner_size
        dump("banner", banner_off, banner_size, "banner.bin",
             version=banner_ver)
        print(f"    banner 0x{banner_off:X}+0x{banner_size:X} "
              f"(version 0x{banner_ver:04X})")

    # --- DSi (TWL) regions -------------------------------------------------
    if is_twl:
        a9i_off, a9i_size = u32(rom, 0x1C0), u32(rom, 0x1CC)
        a7i_off, a7i_size = u32(rom, 0x1D0), u32(rom, 0x1DC)
        if a9i_size:
            dump("arm9i", a9i_off, a9i_size, "arm9i.bin", load=u32(rom, 0x1C8))
        if a7i_size:
            dump("arm7i", a7i_off, a7i_size, "arm7i.bin", load=u32(rom, 0x1D8))
        print(f"    arm9i 0x{a9i_off:X}+0x{a9i_size:X}  "
              f"arm7i 0x{a7i_off:X}+0x{a7i_size:X}")

        # The DSi digest (hash) tables sit in their own large regions; model
        # them so the residue pass does not have to swallow several megabytes.
        for name, off_field, size_field, relpath in (
            ("digest_sector", 0x1F0, 0x1F4, "digest_sector.bin"),
            ("digest_block", 0x1F8, 0x1FC, "digest_block.bin"),
        ):
            off, size = u32(rom, off_field), u32(rom, size_field)
            if size:
                dump(name, off, size, relpath)
                print(f"    {name} 0x{off:X}+0x{size:X}")

    # --- residue pass ------------------------------------------------------
    # Everything that is neither a modelled region nor 0xFF padding gets saved
    # verbatim. This is what makes the rebuild byte-exact no matter what odd
    # structures (signatures, download-play headers, alignment junk) exist.
    print("[*] residue scan ...")
    residues = []
    occupied = rmap.occupied_intervals()
    gaps = []
    cursor = 0
    for start, end in occupied:
        if start > cursor:
            gaps.append((cursor, start))
        cursor = max(cursor, end)
    if cursor < rom_size:
        gaps.append((cursor, rom_size))

    nonpad = re.compile(b"[^\xff]+")
    res_dir = os.path.join(out_dir, "residue")
    runs = []
    for gap_start, gap_end in gaps:
        chunk = rom[gap_start:gap_end]
        gap_runs = []
        for m in nonpad.finditer(chunk):
            s = gap_start + m.start()
            e = gap_start + m.end()
            # Coalesce with the previous run *of this same gap* when only a
            # little padding separates them, so we do not emit thousands of
            # tiny files. Merging never crosses a modelled region, because
            # runs from different gaps are kept apart.
            if gap_runs and s - gap_runs[-1][1] < RESIDUE_COALESCE_GAP:
                gap_runs[-1][1] = e
            else:
                gap_runs.append([s, e])
        runs.extend(gap_runs)

    total_residue = 0
    for i, (s, e) in enumerate(runs):
        relpath = f"residue/{i:04d}.bin"
        full = os.path.join(res_dir, f"{i:04d}.bin")
        ensure_parent(full)
        with open(full, "wb") as f:
            f.write(rom[s:e])
        residues.append({"index": i, "offset": s, "size": e - s,
                         "path": relpath})
        total_residue += e - s
    print(f"    {len(residues)} residue blob(s), "
          f"0x{total_residue:X} ({total_residue}) bytes total")

    # --- manifest ----------------------------------------------------------
    manifest = {
        "tool": "ndsrom.py",
        "version": 1,
        "rom_path": rom_path,
        "rom_size": rom_size,
        "rom_sha1": rom_sha1,
        "pad_byte": PAD_BYTE,
        "title": title,
        "gamecode": gamecode.decode("ascii"),
        "unit_code": unit_code,
        "header_size": header_size,
        "used_rom_size_ntr": u32(rom, 0x80),
        "used_rom_size_twl": u32(rom, 0x210) if is_twl else None,
        "counts": {
            "regions": len([r for r in rmap.regions if r["size"]]),
            "fs_files": data_count,
            "overlays": len(overlay_meta),
            "orphan_fat_files": orphans,
            "residue_blobs": len(residues),
            "residue_bytes": total_residue,
        },
        "regions": rmap.regions,
        "residue": residues,
    }
    mpath = os.path.join(out_dir, "manifest.json")
    with open(mpath, "w", encoding="utf-8") as f:
        json.dump(manifest, f, indent=1)
    print(f"[*] wrote {mpath}")
    print(f"[*] extracted {manifest['counts']['regions']} regions "
          f"({data_count} NitroFS files, {len(overlay_meta)} overlays)")
    return 0


# ---------------------------------------------------------------------------
# build
# ---------------------------------------------------------------------------

def load_manifest(in_dir):
    mpath = os.path.join(in_dir, "manifest.json")
    if not os.path.isfile(mpath):
        raise RomError(f"no manifest.json in {in_dir!r}; run `extract` first")
    with open(mpath, "r", encoding="utf-8") as f:
        return json.load(f)


RESIZABLE = ("arm9", "overlay_")


def _is_resizable(rec):
    name = rec["name"]
    return name == "arm9" or name.startswith("overlay_")


def apply_layout_patches(rom, man, resized, verbose=True):
    """Make the header and the tables describe the image we actually built.

    Called only when some container came out a different size than the one the
    original ROM carried.  Everything patched here is a length that is written
    down in more than one place, so leaving any of them stale means a ROM whose
    tables disagree with its content:

      * ROM header 0x2C, the ARM9 size the cartridge loader DMAs;
      * the FAT entry of every resized overlay (its start stays put, its end
        follows the new length);
      * the y9 overlay table's ``compressed_size`` field, the low 24 bits of
        the entry's last word;
      * the header CRC at 0x15E, which covers all of the above that lives in
        the header.

    Deliberately NOT patched, and why:

      * the DSi digest sector/block tables and the RSA signature above the
        0x1000 header snapshot.  Those cannot be recomputed without the
        signing key, they are consulted only by the DSi launcher and the TWL
        cartridge path, and an NTR-mode boot of a modified ROM with stale
        tables is proven to work (docs/NOTES.md, "Modified rebuild boots").
      * the secure area CRC at 0x6C.  It describes the *encrypted* secure
        area, and No-Intro dumps of this title carry a decrypted one: the
        stored 0x8B9B does not reproduce over ROM[0x4000..0x8000] in any
        spelling, so there is nothing here to recompute.  See
        ``verify --structural``, which reports it rather than pretending.

    ``resized`` is [(manifest record, new size)].
    """
    fat_off, fat_size = u32(rom, 0x48), u32(rom, 0x4C)
    tables = {"y9": (u32(rom, 0x50), u32(rom, 0x54)),
              "y7": (u32(rom, 0x58), u32(rom, 0x5C))}
    notes = []

    for rec, newsize in resized:
        old = rec["size"]
        if rec["name"] == "arm9":
            struct.pack_into("<I", rom, 0x2C, newsize)
            notes.append(f"header 0x2C arm9 size 0x{old:X} -> 0x{newsize:X}")
            continue

        fid = rec.get("file_id")
        tag = rec.get("table")
        if fid is None or tag not in tables:
            raise RomError(
                f"region {rec['name']!r} changed size but carries no file id "
                "or overlay table tag; cannot update the tables"
            )
        if (fid + 1) * FAT_ENTRY_SIZE > fat_size:
            raise RomError(f"file id {fid} is outside the FAT")
        start = rec["offset"]
        struct.pack_into("<II", rom, fat_off + fid * FAT_ENTRY_SIZE,
                         start, start + newsize)

        toff, tsize = tables[tag]
        entry = None
        for i in range(tsize // OVERLAY_ENTRY_SIZE):
            e = toff + i * OVERLAY_ENTRY_SIZE
            if u32(rom, e + 0x18) == fid:
                entry = e
                break
        if entry is None:
            raise RomError(
                f"no {tag} entry references file id {fid}, so the overlay's "
                "compressed size cannot be updated"
            )
        last = u32(rom, entry + 0x1C)
        flags = last >> 24
        if not (flags & 1):
            raise RomError(
                f"overlay {rec.get('overlay_id')} is stored uncompressed, so "
                f"a size change from {old} to {newsize} means its code size "
                "changed too; that needs the overlay table's size and bss "
                "fields recomputed, which this tool does not attempt"
            )
        if newsize > 0xFFFFFF:
            raise RomError(f"overlay {rec.get('overlay_id')} is too large for "
                           "the 24-bit compressed size field")
        struct.pack_into("<I", rom, entry + 0x1C,
                         (flags << 24) | newsize)
        notes.append(
            f"overlay {rec.get('overlay_id')}: FAT end 0x{start + old:X} -> "
            f"0x{start + newsize:X}, y9 compressed_size {old} -> {newsize}")

    before = u16(rom, 0x15E)
    after = header_crc(rom)
    struct.pack_into("<H", rom, 0x15E, after)
    notes.append(f"header CRC 0x{before:04X} -> 0x{after:04X}")

    if verbose:
        for n in notes:
            print(f"    {n}")
    return notes


def cmd_build(args):
    in_dir = os.path.abspath(args.dir)
    out_path = os.path.abspath(args.out)
    man = load_manifest(in_dir)
    overrides = [os.path.abspath(d) for d in getattr(args, "override", [])]
    allow_resize = not getattr(args, "fixed_size", False)

    rom_size = man["rom_size"]
    pad = man.get("pad_byte", PAD_BYTE)
    print(f"[*] building 0x{rom_size:X} byte image, padding 0x{pad:02X}")
    for d in overrides:
        print(f"    override directory {d}")
    rom = bytearray([pad]) * rom_size
    slots = slot_limits(man)

    written = 0
    overridden = 0
    resized = []

    def resolve(relpath):
        nonlocal overridden
        rel = relpath.replace("/", os.sep)
        for d in overrides:
            cand = os.path.join(d, rel)
            if os.path.isfile(cand):
                overridden += 1
                return cand
        return os.path.join(in_dir, rel)

    def place(relpath, offset, size, what, rec=None):
        """Write one file at its recorded offset.

        A file whose length differs from the manifest is normally a bug, and
        stays fatal.  The one case where it is legitimate is a recompressed
        ARM9 container or overlay whose compressed size moved: that is allowed
        as long as it still fits its slot, and the tables are fixed up
        afterwards by apply_layout_patches().
        """
        nonlocal written
        full = resolve(relpath)
        try:
            with open(full, "rb") as f:
                data = f.read()
        except OSError as exc:
            raise RomError(f"{what}: cannot read {full!r}: {exc}") from exc
        n = len(data)
        if n != size:
            if not (allow_resize and rec is not None and _is_resizable(rec)):
                raise RomError(
                    f"{what}: {relpath!r} is {n} bytes but the manifest "
                    f"says {size}"
                )
            limit = slots.get(relpath, {}).get("limit", size)
            if n > limit:
                raise RomError(
                    f"{what}: {relpath!r} is {n} (0x{n:X}) bytes but its ROM "
                    f"slot at 0x{offset:X} holds only {limit} (0x{limit:X}) "
                    f"before the next file starts at 0x{offset + limit:X}. "
                    f"The slot is {size} bytes of content plus "
                    f"{limit - size} of padding, so this needs "
                    f"{n - limit} byte(s) more than exist. Moving the files "
                    "that follow is not implemented."
                )
            resized.append((rec, n))
        if offset + n > rom_size:
            raise RomError(
                f"{what}: 0x{offset:X}+0x{n:X} runs past the end of the ROM"
            )
        rom[offset:offset + n] = data
        written += n

    for rec in man["regions"]:
        if not rec["size"]:
            continue
        place(rec["path"], rec["offset"], rec["size"],
              f"region {rec['name']!r}", rec)

    for rec in man["residue"]:
        place(rec["path"], rec["offset"], rec["size"],
              f"residue {rec['index']}")

    if resized:
        print(f"[*] {len(resized)} container(s) changed size; updating the "
              "header and the tables")
        for rec, n in resized:
            slot = slots.get(rec["path"], {})
            limit = slot.get("limit", rec["size"])
            print(f"    {rec['name']:<16} 0x{rec['size']:X} -> 0x{n:X} "
                  f"({n - rec['size']:+d}), slot 0x{limit:X}, "
                  f"0x{limit - n:X} byte(s) of slack left")
        apply_layout_patches(rom, man, resized)
        used = max(rec["offset"] + n for rec, n in resized)
        if used > man["used_rom_size_ntr"]:
            raise RomError(
                f"a resized container now ends at 0x{used:X}, past the "
                f"header's used-ROM-size 0x{man['used_rom_size_ntr']:X}"
            )

    ensure_parent(out_path)
    with open(out_path, "wb") as f:
        f.write(rom)

    digest = sha1_of(rom)
    print(f"[*] wrote {out_path}")
    print(f"    placed {len(man['regions'])} region records + "
          f"{len(man['residue'])} residue blobs "
          f"(0x{written:X} bytes of content)")
    if overrides:
        print(f"    {overridden} file(s) taken from the override "
              f"director{'y' if len(overrides) == 1 else 'ies'}")
    print(f"    sha1 {digest}")
    return 0


# ---------------------------------------------------------------------------
# verify
# ---------------------------------------------------------------------------

def hexdump(data, base, highlight=None, width=16):
    lines = []
    for off in range(0, len(data), width):
        chunk = data[off:off + width]
        hexpart = " ".join(f"{b:02X}" for b in chunk)
        txt = "".join(chr(b) if 0x20 <= b < 0x7F else "." for b in chunk)
        mark = ""
        if highlight is not None and off <= highlight - base < off + width:
            mark = "  <--"
        lines.append(f"  {base + off:08X}  {hexpart:<{width * 3}} |{txt}|{mark}")
    return "\n".join(lines)


def check_structure(rom, man=None):
    """Header fields against the actual layout.  Returns (checks, problems).

    This is the check that still says something about a ROM that is *not*
    byte-identical to the original, which a sha1 comparison cannot.  Every
    length and offset in the header and the tables is cross-checked against
    the thing it describes, so a repack that grew a container and forgot to
    update one of the several places its size is written down fails here
    instead of failing on hardware.

    What it cannot check, and says so rather than passing silently: the DSi
    digest tables and the RSA signature (no key), and the secure area CRC at
    0x6C, which describes the encrypted secure area that a decrypted dump does
    not carry.
    """
    checks, problems = [], []

    def ok(name, good, detail=""):
        checks.append((name, bool(good), detail))
        if not good:
            problems.append(f"{name}: {detail}")

    n = len(rom)
    arm9_off, arm9_size = u32(rom, 0x20), u32(rom, 0x2C)
    arm9_load = u32(rom, 0x28)
    arm7_off, arm7_size = u32(rom, 0x30), u32(rom, 0x3C)
    fnt_off, fnt_size = u32(rom, 0x40), u32(rom, 0x44)
    fat_off, fat_size = u32(rom, 0x48), u32(rom, 0x4C)
    used_ntr = u32(rom, 0x80)
    header_size = u32(rom, 0x84)

    ok("header CRC 0x15E", u16(rom, 0x15E) == header_crc(rom),
       f"stored 0x{u16(rom, 0x15E):04X}, computed 0x{header_crc(rom):04X}")
    ok("logo CRC 0x15C", u16(rom, 0x15C) == logo_crc(rom),
       f"stored 0x{u16(rom, 0x15C):04X}, computed 0x{logo_crc(rom):04X}")
    checks.append(("secure area CRC 0x6C", None,
                   f"stored 0x{u16(rom, 0x6C):04X}; covers the *encrypted* "
                   "secure area, not recomputable from a decrypted dump"))

    fixed = [("arm9", arm9_off, arm9_size), ("arm7", arm7_off, arm7_size),
             ("fnt", fnt_off, fnt_size), ("fat", fat_off, fat_size),
             ("y9", u32(rom, 0x50), u32(rom, 0x54)),
             ("y7", u32(rom, 0x58), u32(rom, 0x5C))]
    for name, off, size in fixed:
        if size:
            ok(f"{name} within the ROM", off + size <= n,
               f"0x{off:X}+0x{size:X} vs 0x{n:X}")
    ok("used ROM size 0x80", used_ntr <= n,
       f"0x{used_ntr:X} vs image 0x{n:X}")
    ok("header size 0x84", header_size <= n, f"0x{header_size:X}")

    # The ARM9 build info repeats the container's end address; it is inside
    # the BLZ verbatim prefix, so it can be read straight out of the ROM.
    bi = u32(rom, 0x88)
    if bi and arm9_off + bi + 0x24 <= n:
        want = arm9_load + arm9_size
        got = u32(rom, arm9_off + bi + 0x14)
        nitro = u32(rom, arm9_off + bi + 0x1C)
        if nitro == 0xDEC00621:
            ok("arm9 build info compressed_code_end", got == want,
               f"build info says 0x{got:08X}, header 0x2C implies 0x{want:08X}")
        else:
            checks.append(("arm9 build info", None,
                           f"no nitrocode at arm9+0x{bi:X}, not checked"))

    # Every FAT file: inside the ROM, non-inverted, and not colliding with a
    # fixed region or with another file.
    spans = [(off, off + size, name) for name, off, size in fixed if size]
    spans.append((0, header_size, "header area"))
    bad_fat = 0
    files = []
    if fat_size % FAT_ENTRY_SIZE == 0 and fat_off + fat_size <= n:
        for i in range(fat_size // FAT_ENTRY_SIZE):
            s = u32(rom, fat_off + i * FAT_ENTRY_SIZE)
            e = u32(rom, fat_off + i * FAT_ENTRY_SIZE + 4)
            if e == 0 and s == 0:
                continue
            if e < s or e > n:
                bad_fat += 1
                continue
            files.append((s, e, i))
        ok("FAT entries well formed", bad_fat == 0,
           f"{bad_fat} entr(ies) inverted or past the end of the image")
        files.sort()
        overlaps = 0
        for k in range(1, len(files)):
            if files[k][0] < files[k - 1][1]:
                overlaps += 1
        ok("FAT files do not overlap each other", overlaps == 0,
           f"{overlaps} overlapping pair(s)")
        clash = []
        for s, e, i in files:
            for a, b, name in spans:
                if s < b and a < e:
                    clash.append((i, name))
        ok("FAT files clear of the fixed regions", not clash,
           ", ".join(f"file {i} overlaps {nm}" for i, nm in clash[:4]))

    # Overlay tables against the FAT.
    byid = {i: (s, e) for s, e, i in files}
    for tag, toff_f, tsize_f in (("y9", 0x50, 0x54), ("y7", 0x58, 0x5C)):
        toff, tsize = u32(rom, toff_f), u32(rom, tsize_f)
        if not tsize or toff + tsize > n or tsize % OVERLAY_ENTRY_SIZE:
            continue
        wrong = []
        for i in range(tsize // OVERLAY_ENTRY_SIZE):
            e = toff + i * OVERLAY_ENTRY_SIZE
            ov_id = u32(rom, e + 0x00)
            code_size = u32(rom, e + 0x08)
            fid = u32(rom, e + 0x18)
            last = u32(rom, e + 0x1C)
            comp_size, flags = last & 0xFFFFFF, last >> 24
            span = byid.get(fid)
            if span is None:
                wrong.append(f"overlay {ov_id}: file id {fid} has no FAT entry")
                continue
            length = span[1] - span[0]
            if flags & 1:
                if comp_size != length:
                    wrong.append(
                        f"overlay {ov_id}: compressed_size {comp_size} but "
                        f"the FAT gives {length} bytes")
            else:
                if comp_size:
                    wrong.append(f"overlay {ov_id}: stored but "
                                 f"compressed_size is {comp_size}")
                elif length != code_size:
                    wrong.append(
                        f"overlay {ov_id}: stored, FAT gives {length} bytes "
                        f"but the table's code size is {code_size}")
        ok(f"{tag} entries agree with the FAT", not wrong,
           "; ".join(wrong[:4]) + (f" (+{len(wrong) - 4} more)"
                                   if len(wrong) > 4 else ""))

    if man is not None:
        ok("image size", len(rom) == man["rom_size"],
           f"{len(rom)} vs {man['rom_size']}")
    return checks, problems


def print_structure(rom, man=None):
    checks, problems = check_structure(rom, man)
    print("[*] structural checks (header and tables against the layout)")
    for name, good, detail in checks:
        mark = "PASS" if good else ("FAIL" if good is False else "note")
        print(f"    {mark}  {name}" + (f"  --  {detail}" if detail else ""))
    print()
    if problems:
        print(f"FAIL: {len(problems)} structural problem(s)")
        return 1
    print("PASS: the header and the tables describe this image consistently")
    return 0


def cmd_verify(args):
    in_dir = os.path.abspath(args.dir)
    built_path = os.path.abspath(args.built)
    man = load_manifest(in_dir)

    with open(built_path, "rb") as f:
        built = f.read()
    digest = sha1_of(built)
    expected = man["rom_sha1"]

    print(f"[*] built    {built_path}")
    print(f"    size     {len(built)} (expected {man['rom_size']})")
    print(f"    sha1     {digest}")
    print(f"    expected {expected}")

    if getattr(args, "structural", False):
        print()
        return print_structure(built, man)

    if digest == expected and len(built) == man["rom_size"]:
        print("PASS: rebuilt ROM is byte-identical to the original")
        return 0

    print("FAIL: rebuilt ROM does not match the original")
    print("      (a modified build is expected to; "
          "run `verify --structural` for a check that still applies)")

    orig_path = man["rom_path"]
    if not os.path.isfile(orig_path):
        print(f"  (original ROM not found at {orig_path!r}; "
              "cannot show a byte diff)")
        return 1
    with open(orig_path, "rb") as f:
        orig = f.read()

    if len(orig) != len(built):
        print(f"  size mismatch: original {len(orig)}, built {len(built)}")

    diffs = []
    limit = min(len(orig), len(built))
    # Compare in blocks so we only scan byte-by-byte where something differs.
    block = 1 << 16
    pos = 0
    while pos < limit and len(diffs) < 10:
        end = min(pos + block, limit)
        if orig[pos:end] != built[pos:end]:
            for i in range(pos, end):
                if orig[i] != built[i]:
                    diffs.append(i)
                    if len(diffs) >= 10:
                        break
        pos = end

    if diffs:
        print(f"  first {len(diffs)} differing offset(s):")
        for off in diffs:
            print(f"    0x{off:08X}: original 0x{orig[off]:02X} "
                  f"!= built 0x{built[off]:02X}")
        first = diffs[0]
        base = max(0, (first - 32) & ~0xF)
        stop = min(limit, base + 96)
        print(f"  context at 0x{first:08X} -- original:")
        print(hexdump(orig[base:stop], base, first))
        print("  built:")
        print(hexdump(built[base:stop], base, first))
    return 1


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main(argv=None):
    ap = argparse.ArgumentParser(
        prog="ndsrom.py",
        description="Unpack, repack and verify NDS/DSi cartridge images.",
    )
    sub = ap.add_subparsers(dest="cmd", required=True)

    p = sub.add_parser("extract", help="unpack a ROM into a directory")
    p.add_argument("rom")
    p.add_argument("-o", "--out", default="extract")
    p.set_defaults(func=cmd_extract)

    p = sub.add_parser("build", help="repack an extracted directory into a ROM")
    p.add_argument("dir")
    p.add_argument("-o", "--out", default=os.path.join("build", "out.nds"))
    p.add_argument("--override", metavar="DIR", action="append", default=[],
                   help="take any file that exists under DIR from there "
                        "instead of from the extracted directory; may be "
                        "given more than once, earliest wins. Used to build a "
                        "ROM from recompressed binaries (tools/build.py "
                        "--pack) without consulting the originals")
    p.add_argument("--fixed-size", action="store_true",
                   help="refuse any override whose size differs from the "
                        "original, instead of growing it into its slot and "
                        "updating the header and the tables")
    p.set_defaults(func=cmd_build)

    p = sub.add_parser("verify", help="compare a built ROM against the manifest")
    p.add_argument("dir")
    p.add_argument("built")
    p.add_argument("--structural", action="store_true",
                   help="check the header fields and the tables against the "
                        "actual layout instead of comparing sha1s. This is "
                        "the check that still means something for a "
                        "deliberately modified ROM")
    p.set_defaults(func=cmd_verify)

    args = ap.parse_args(argv)
    try:
        return args.func(args)
    except RomError as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
