#!/usr/bin/env python3
"""
narc.py -- NARC (Nitro ARChive) reader for aletheia.

Written from scratch for aletheia. Stdlib only, single file.

--------------------------------------------------------------------------
NARC container layout
--------------------------------------------------------------------------
A NARC is a NitroSDK "generic container" (the same chunked-section shape as
NSBMD/NSBTX/etc): a small file header, then a fixed sequence of named
sections. Every size/offset field is little-endian.

File header (16 bytes):
    0x00  char[4]  magic           "NARC"
    0x04  u16      byte_order      0xFFFE  (BOM marker, always this value)
    0x06  u16      version         0x0100  (seen in this ROM)
    0x08  u32      file_size       total size of the NARC, bytes
    0x0C  u16      header_size     size of this header, always 0x10
    0x0E  u16      section_count   number of sections that follow, always 3

Section header, common to every section (8 bytes):
    0x00  char[4]  magic
    0x04  u32      size            size of this section INCLUDING this header

Section 1 -- BTAF (File Allocation Table):
    0x08  u32      file_count
    then file_count entries of:
        u32  start_offset   (relative to the start of GMIF's data, i.e. the
                              byte right after the GMIF section header)
        u32  end_offset

Section 2 -- BTNF (File Name Table), optional in principle but present in
every NARC seen in this ROM. Same directory-table shape as the ROM's own
FNT (see tools/ndsrom.py): a root entry, sub-directories with named
children, and per-directory first-file-id counters. Sub-file names are
rarely meaningful for these game-data archives (usually absent or generic),
so this reader records the raw bytes and does not attempt to resolve a
full path tree; only sub-file *count* and *offset/size* are used elsewhere.

Section 3 -- GMIF (data): 8-byte section header (magic + size) followed
immediately by the concatenated sub-file bytes; BTAF offsets are relative
to right after this header.

--------------------------------------------------------------------------
Sub-file formats
--------------------------------------------------------------------------
Sub-files are identified by sniffing their first bytes:

  * A NITRO chunk magic, stored "backwards" in the file (e.g. tile data is
    "RGCN" on disk, read as NCGR): RGCN/NCGR tiles, RLCN/NCLR palettes,
    RCSN/NSCR screens, RECN/NCER cells, RNAN/NANR cell animations,
    BMD0 NSBMD models, BTX0 NSBTX textures, BCA0 animations, SDAT sound
    archives.
  * A BIOS-style compression header, first byte:
        0x10  LZ77     (GBA/NDS "LZ77 UnComp", forward window)
        0x11  LZ11     (NDS "LZ11", forward window, richer token encoding)
        0x20  Huffman  (4-bit)
        0x28  Huffman  (8-bit)          -- 0x20 | (bits << 0), see below
        0x30  RLE      (run-length)
    followed by a 24-bit little-endian decompressed size.
  * Anything else: an unrecognised / Game Freak custom format (no magic),
    reported as "raw"/"unknown".

LZ77 (0x10) and LZ11 (0x11) are simple enough to decode without pulling in
outside code, so both are implemented below and self-checked against the
header's declared decompressed size wherever they are used. Huffman and RLE
are only sniffed (type identified), not decoded, in this lane.
"""

import argparse
import json
import os
import struct
import sys


class NarcError(Exception):
    """Raised for any malformed or inconsistent NARC container."""


# ---------------------------------------------------------------------------
# BIOS-style compression header sniffing
# ---------------------------------------------------------------------------

COMPRESSION_NAMES = {
    0x10: "LZ77",
    0x11: "LZ11",
    0x24: "Huffman4",  # high nibble 0x20 = Huffman type, low nibble = data-unit bits
    0x28: "Huffman8",
    0x30: "RLE",
}


def sniff_compression(data):
    """Return (type_name, decoded_size) if ``data`` opens with a BIOS-style
    compression header, else None. Does not decode anything.

    NOTE: an earlier version of this function accepted tag byte 0x20 as
    "Huffman4". 0x20 is NOT a valid Huffman header on its own -- the real
    BIOS Huffman tag packs the data-unit width (4 or 8) into the LOW nibble
    and the type id (2) into the HIGH nibble, so the only valid tags are
    0x24 (4-bit) and 0x28 (8-bit); 0x20 would claim a 0-bit data unit, which
    the BIOS decompressor itself rejects. Accepting bare 0x20 produced
    false-positive "Huffman4" hits on any sub-file that merely happens to
    start with byte 0x20 (notably the ASCII space in a/0/0/6's " APS"
    trainer-sprite wrapper magic) -- confirmed by round-trip verification in
    tools/assets/verify_compression.py, which found 0/800 of the old sniff's
    hits decoded to their "declared" size. Fixed here to require the
    high nibble be exactly 0x20 and the low nibble be 4 or 8.
    """
    if len(data) < 4:
        return None
    tag = data[0]
    kind = None
    if tag in (0x10, 0x11, 0x30):
        kind = COMPRESSION_NAMES.get(tag)
    elif (tag & 0xF0) == 0x20 and (tag & 0x0F) in (4, 8):
        kind = COMPRESSION_NAMES.get(tag)
    if kind is None:
        return None
    size = data[1] | (data[2] << 8) | (data[3] << 16)
    return (kind, size)


# ---------------------------------------------------------------------------
# LZ77 (0x10) / LZ11 (0x11) decompression -- forward window, BIOS style.
# Not to be confused with blz.py's BLZ (backward LZ77) used for ARM9/overlays.
# ---------------------------------------------------------------------------

def decompress_lz77(data):
    """Decode a BIOS "LZ77 UnComp" (type 0x10) container. Returns bytes."""
    if len(data) < 4 or data[0] != 0x10:
        raise NarcError("not an LZ77 (0x10) container")
    dec_size = data[1] | (data[2] << 8) | (data[3] << 16)
    out = bytearray()
    sp = 4
    n = len(data)
    while len(out) < dec_size:
        if sp >= n:
            raise NarcError("LZ77 stream ran out before reaching declared size")
        flags = data[sp]
        sp += 1
        for bit in range(8):
            if len(out) >= dec_size:
                break
            if flags & (0x80 >> bit):
                if sp + 1 >= n:
                    raise NarcError("LZ77 stream ran out inside a match token")
                b0, b1 = data[sp], data[sp + 1]
                sp += 2
                length = (b0 >> 4) + 3
                disp = ((b0 & 0x0F) << 8) | b1
                disp += 1
                if disp > len(out):
                    raise NarcError("LZ77 match reaches before the start of output")
                base = len(out) - disp
                for i in range(length):
                    out.append(out[base + i])
            else:
                if sp >= n:
                    raise NarcError("LZ77 stream ran out on a literal byte")
                out.append(data[sp])
                sp += 1
    if n - sp > 3:
        # A genuine BIOS LZ77 stream consumes (up to 3 bytes of trailing
        # NARC sub-file padding aside) its entire container -- see
        # verify_all.py's `_compressed_match` docstring for the same 0-3
        # byte tolerance, confirmed on `a/1/7/3`. Reaching the declared
        # decompressed size this far short of the sub-file's end means tag
        # byte 0x10 was not a real LZ77 header, just a coincidental first
        # byte of some other (plain/custom) format -- e.g. `a/0/2/1`'s
        # fixed 36-byte move records, several of which start with 0x10/0x11
        # as a data field, not a compression tag.
        raise NarcError("LZ77 declared size reached far short of the "
                         "container end -- not a real compressed stream")
    return bytes(out[:dec_size])


def decompress_lz11(data):
    """Decode an NDS LZ11 (type 0x11) container. Returns bytes."""
    if len(data) < 4 or data[0] != 0x11:
        raise NarcError("not an LZ11 (0x11) container")
    dec_size = data[1] | (data[2] << 8) | (data[3] << 16)
    sp = 4
    n = len(data)
    if dec_size == 0:
        # Extended size form: 4 more bytes hold a 32-bit size.
        if sp + 4 > n:
            raise NarcError("LZ11 extended size field truncated")
        dec_size = struct.unpack_from("<I", data, sp)[0]
        sp += 4
    out = bytearray()
    while len(out) < dec_size:
        if sp >= n:
            raise NarcError("LZ11 stream ran out before reaching declared size")
        flags = data[sp]
        sp += 1
        for bit in range(8):
            if len(out) >= dec_size:
                break
            if not (flags & (0x80 >> bit)):
                if sp >= n:
                    raise NarcError("LZ11 stream ran out on a literal byte")
                out.append(data[sp])
                sp += 1
                continue
            if sp >= n:
                raise NarcError("LZ11 stream ran out reading a token")
            b0 = data[sp]
            sp += 1
            indicator = b0 >> 4
            if indicator == 0:
                # 8-bit length field: length 0x11..0x110
                if sp + 1 >= n:
                    raise NarcError("LZ11 stream ran out in an 8-bit-length token")
                length = ((b0 & 0x0F) << 4) | (data[sp] >> 4)
                length += 0x11
                disp = ((data[sp] & 0x0F) << 8) | data[sp + 1]
                disp += 1
                sp += 2
            elif indicator == 1:
                # 16-bit length field: length 0x111..0x10110
                if sp + 2 >= n:
                    raise NarcError("LZ11 stream ran out in a 16-bit-length token")
                length = ((b0 & 0x0F) << 12) | (data[sp] << 4) | (data[sp + 1] >> 4)
                length += 0x111
                disp = ((data[sp + 1] & 0x0F) << 8) | data[sp + 2]
                disp += 1
                sp += 3
            else:
                # Normal token: length 3..0x10
                if sp >= n:
                    raise NarcError("LZ11 stream ran out in a normal token")
                length = indicator + 1
                disp = ((b0 & 0x0F) << 8) | data[sp]
                disp += 1
                sp += 1
            if disp > len(out):
                raise NarcError("LZ11 match reaches before the start of output")
            base = len(out) - disp
            for i in range(length):
                out.append(out[base + i])
    if n - sp > 3:
        # Same false-positive-tag guard as `decompress_lz77` above, for the
        # LZ11 (0x11) tag byte -- see that function's comment.
        raise NarcError("LZ11 declared size reached far short of the "
                         "container end -- not a real compressed stream")
    return bytes(out[:dec_size])


def decompress_huffman(data):
    """Decode a BIOS Huffman container (type 0x20/0x24 = 4-bit data units,
    0x28 = 8-bit data units). Returns bytes.

    Header (GBATEK "16h Huffman Decompression"):
        byte 0     low nibble = data unit size in bits (4 or 8),
                   high nibble = compression type (2)
        bytes 1-3  24-bit LE decompressed size, in bytes
        byte 4     tree size byte S; the tree table is (S+1)*2 bytes and
                   starts immediately after this byte (tree_table[0] is the
                   root node)
        ...        tree table
        ...        compressed bitstream: 32-bit LE words, consumed MSB-first
                   (bit 31 down to bit 0), each bit selecting the node-0 or
                   node-1 child while walking the tree from the root

    Each non-leaf tree node byte is:
        bits 0-5  offset used to locate both children:
                    child0 = (this_node_addr & ~1) + offset*2 + 2
                    child1 = child0 + 1
                  (this_node_addr is the node's byte offset counted from the
                  tree-size byte, i.e. the size byte itself is address 0 and
                  the root node is address 1)
        bit 6     if set, child1 is a leaf (data) node
        bit 7     if set, child0 is a leaf (data) node
    A leaf node byte holds the data unit value in its low bits.

    Data units are packed into output bytes as they come off the tree: for
    4-bit units the first unit decoded goes into the low nibble of the next
    output byte and the second into the high nibble; for 8-bit units each
    leaf is already a whole output byte.
    """
    if len(data) < 5 or (data[0] & 0xF0) != 0x20:
        raise NarcError("not a Huffman (0x20/0x24/0x28) container")
    data_bits = data[0] & 0x0F
    if data_bits not in (1, 2, 4, 8):
        raise NarcError(f"Huffman data unit size {data_bits} bits is not supported")
    dec_size = data[1] | (data[2] << 8) | (data[3] << 16)
    tree_size_byte = data[4]
    tree_table_len = (tree_size_byte + 1) * 2
    tree_base = 4  # offset of the tree-size byte itself; addresses count from here
    bitstream_start = 5 + tree_table_len
    n = len(data)

    def node_byte(addr):
        pos = tree_base + addr
        if pos >= n:
            raise NarcError("Huffman tree node address runs past end of data")
        return data[pos]

    out = bytearray()
    acc = 0
    acc_bits = 0
    sp = bitstream_start
    if sp > n:
        raise NarcError("Huffman bitstream starts past end of data")

    cur_addr = 1  # root node address (tree_base + 1 == first tree table byte)
    cur_is_leaf = False
    word = 0
    word_bits_left = 0
    while len(out) < dec_size:
        if word_bits_left == 0:
            if sp + 4 > n:
                raise NarcError("Huffman bitstream ran out before reaching declared size")
            word = data[sp] | (data[sp + 1] << 8) | (data[sp + 2] << 16) | (data[sp + 3] << 24)
            sp += 4
            word_bits_left = 32
        word_bits_left -= 1
        bit = (word >> word_bits_left) & 1

        node = node_byte(cur_addr)
        offset = node & 0x3F
        child_base = (cur_addr & ~1) + offset * 2 + 2
        if bit == 0:
            child_addr = child_base
            child_is_leaf = bool(node & 0x80)
        else:
            child_addr = child_base + 1
            child_is_leaf = bool(node & 0x40)

        if child_is_leaf:
            value = node_byte(child_addr) & ((1 << data_bits) - 1)
            acc |= value << acc_bits
            acc_bits += data_bits
            while acc_bits >= 8:
                out.append(acc & 0xFF)
                acc >>= 8
                acc_bits -= 8
            cur_addr = 1
        else:
            cur_addr = child_addr
    return bytes(out[:dec_size])


def decompress_rle(data):
    """Decode a BIOS RLE container (type 0x30). Returns bytes.

    Header: byte 0 = 0x30, bytes 1-3 = 24-bit LE decompressed size. Then a
    stream of (flag byte, payload) blocks:
      - flag bit 7 set:   compressed run, length = (flag & 0x7F) + 3,
                          followed by one byte repeated `length` times
      - flag bit 7 clear: literal run, length = (flag & 0x7F) + 1,
                          followed by `length` literal bytes
    """
    if len(data) < 4 or data[0] != 0x30:
        raise NarcError("not an RLE (0x30) container")
    dec_size = data[1] | (data[2] << 8) | (data[3] << 16)
    out = bytearray()
    sp = 4
    n = len(data)
    while len(out) < dec_size:
        if sp >= n:
            raise NarcError("RLE stream ran out before reaching declared size")
        flag = data[sp]
        sp += 1
        if flag & 0x80:
            length = (flag & 0x7F) + 3
            if sp >= n:
                raise NarcError("RLE stream ran out inside a compressed run")
            b = data[sp]
            sp += 1
            out.extend([b] * length)
        else:
            length = (flag & 0x7F) + 1
            if sp + length > n:
                raise NarcError("RLE stream ran out inside a literal run")
            out.extend(data[sp:sp + length])
            sp += length
    return bytes(out[:dec_size])


def try_decompress(data):
    """Best-effort decompress of a sub-file. Returns (kind, decoded_bytes)
    or (kind, None) if the kind is known but decoding failed, or
    (None, None) if no compression header is recognised."""
    info = sniff_compression(data)
    if info is None:
        return (None, None)
    kind, dec_size = info
    if kind == "LZ77":
        return (kind, decompress_lz77(data))
    if kind == "LZ11":
        return (kind, decompress_lz11(data))
    if kind in ("Huffman4", "Huffman8"):
        return (kind, decompress_huffman(data))
    if kind == "RLE":
        return (kind, decompress_rle(data))
    return (kind, None)


# ---------------------------------------------------------------------------
# NARC parsing
# ---------------------------------------------------------------------------

class SubFile:
    __slots__ = ("index", "offset", "size", "magic", "name")

    def __init__(self, index, offset, size, magic, name=None):
        self.index = index
        self.offset = offset
        self.size = size
        self.magic = magic
        self.name = name  # BTNF path, or None if this NARC has no usable names

    def __repr__(self):
        return (f"SubFile(#{self.index}, off=0x{self.offset:X}, size=0x{self.size:X}, "
                f"magic={self.magic!r}, name={self.name!r})")


class Narc:
    """A parsed NARC container. ``data`` is kept so sub-files can be sliced
    out lazily without copying up front."""

    def __init__(self, data, path=None):
        self.path = path
        self.data = data
        self._parse()

    def _parse(self):
        data = self.data
        if len(data) < 16:
            raise NarcError("file too small for a NARC header")
        magic, byte_order, version, file_size, header_size, section_count = \
            struct.unpack_from("<4sHHIHH", data, 0)
        if magic != b"NARC":
            raise NarcError(f"bad magic {magic!r}, expected b'NARC'")
        self.byte_order = byte_order
        self.version = version
        self.file_size = file_size
        self.header_size = header_size
        self.section_count = section_count

        pos = header_size
        btaf = self._read_section(pos, b"BTAF")
        pos += btaf["size"]
        btnf = self._read_section(pos, b"BTNF")
        pos += btnf["size"]
        gmif = self._read_section(pos, b"GMIF")

        # --- BTAF: file allocation table ---
        btaf_body = btaf["body"]
        file_count = struct.unpack_from("<I", btaf_body, 0)[0]
        entries = []
        off = 4
        for i in range(file_count):
            if off + 8 > len(btaf_body):
                raise NarcError(f"BTAF truncated at entry {i}")
            start, end = struct.unpack_from("<II", btaf_body, off)
            off += 8
            entries.append((start, end))
        self.file_count = file_count
        self._alloc = entries

        # --- BTNF: file name table ---
        self.btnf_raw = btnf["body"]
        self.names = self._parse_btnf(btnf["body"])  # {file_id: path} or {}

        # --- GMIF: data section ---
        self.gmif_offset_in_file = gmif["header_offset"] + 8  # past magic+size
        gmif_body = gmif["body"]
        self.gmif_size = gmif["size"]

        self.subfiles = []
        for i, (start, end) in enumerate(entries):
            size = end - start
            if start < 0 or end > len(gmif_body) or size < 0:
                raise NarcError(
                    f"sub-file {i} range 0x{start:X}..0x{end:X} is outside "
                    f"the GMIF data (0x{len(gmif_body):X} bytes)"
                )
            sub = gmif_body[start:end]
            magic = sub[:4] if len(sub) >= 4 else sub
            self.subfiles.append(SubFile(i, self.gmif_offset_in_file + start, size, magic,
                                          name=self.names.get(i)))
        self._gmif_body = gmif_body

    def _parse_btnf(self, fnt):
        """Decode a BTNF file-name table into {file_id: path}.

        Same directory-table shape as the ROM's own FNT (see
        tools/ndsrom.py's parse_fnt): a main table of 8-byte directory
        entries (root's entry doubles its "parent id" field as the total
        directory count), each with a sub-table of
        length-prefixed (dir-bit | name-length, name[, u16 sub-dir-id])
        entries, terminated by a zero length byte. File ids are assigned
        sequentially from each directory's first-file-id counter, in the
        order entries appear in that directory's sub-table -- the same
        order BTAF assigns sub-file indices, so file_id lines up with
        this NARC's sub-file index.

        Returns {} if the table is empty/degenerate (a single root entry
        with no sub-table content, as seen in many NARCs in this ROM).
        """
        names = {}
        if len(fnt) < 8:
            return names
        dir_count = struct.unpack_from("<H", fnt, 6)[0]
        if dir_count == 0 or dir_count * 8 > len(fnt):
            return names

        def sanitize(raw):
            try:
                s = raw.decode("ascii")
            except UnicodeDecodeError:
                return raw.hex()
            return "".join(c if (32 <= ord(c) < 127 and c not in '<>:"/\\|?*') else "_"
                            for c in s) or "_"

        def walk(dir_index, prefix, depth):
            if depth > 64 or dir_index >= dir_count:
                return  # guard against a malformed/cyclic table
            base = dir_index * 8
            sub_off = struct.unpack_from("<I", fnt, base)[0]
            next_file_id = struct.unpack_from("<H", fnt, base + 4)[0]
            if sub_off >= len(fnt):
                return
            p = sub_off
            while p < len(fnt):
                length = fnt[p]
                p += 1
                if length == 0x00:
                    break
                is_dir = bool(length & 0x80)
                name_len = length & 0x7F
                if name_len == 0 or p + name_len > len(fnt):
                    break
                raw = bytes(fnt[p:p + name_len])
                p += name_len
                name = sanitize(raw)
                if is_dir:
                    if p + 2 > len(fnt):
                        break
                    sub_id = struct.unpack_from("<H", fnt, p)[0]
                    p += 2
                    walk(sub_id & 0x0FFF, prefix + name + "/", depth + 1)
                else:
                    names[next_file_id] = prefix + name
                    next_file_id += 1

        walk(0, "", 0)
        return names

    def _read_section(self, pos, expect_magic):
        data = self.data
        if pos + 8 > len(data):
            raise NarcError(f"section at 0x{pos:X} runs past end of file "
                             f"(expected {expect_magic!r})")
        magic, size = struct.unpack_from("<4sI", data, pos)
        if magic != expect_magic:
            raise NarcError(f"expected section {expect_magic!r} at 0x{pos:X}, "
                             f"found {magic!r}")
        if pos + size > len(data):
            raise NarcError(f"section {expect_magic!r} at 0x{pos:X} claims "
                             f"size 0x{size:X}, past end of file")
        return {
            "magic": magic,
            "size": size,
            "header_offset": pos,
            "body": data[pos + 8:pos + size],
        }

    def read(self, index):
        """Return the raw bytes of sub-file ``index``."""
        start, end = self._alloc[index]
        return self._gmif_body[start:end]

    def extract(self, index, out_path):
        raw = self.read(index)
        parent = os.path.dirname(os.path.abspath(out_path))
        if parent:
            os.makedirs(parent, exist_ok=True)
        with open(out_path, "wb") as fh:
            fh.write(raw)
        return len(raw)


def parse(data, path=None):
    return Narc(data, path=path)


def parse_file(path):
    with open(path, "rb") as fh:
        data = fh.read()
    return Narc(data, path=path)


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def _magic_repr(magic):
    try:
        return magic.decode("ascii")
    except UnicodeDecodeError:
        return magic.hex()


def cmd_list(args):
    narc = parse_file(args.input)
    print(f"[*] {args.input}: NARC, {narc.file_size} bytes, "
          f"{narc.file_count} sub-files")
    named = sum(1 for s in narc.subfiles if s.name)
    if named:
        print(f"[*] BTNF names present for {named}/{narc.file_count} sub-files")
    for sub in narc.subfiles:
        comp = sniff_compression(narc.read(sub.index))
        comp_s = f" compressed={comp[0]} dec_size=0x{comp[1]:X}" if comp else ""
        name_s = f"  name={sub.name}" if sub.name else ""
        print(f"  #{sub.index:4d}  off=0x{sub.offset:08X}  "
              f"size=0x{sub.size:08X}  magic={_magic_repr(sub.magic):8s}{comp_s}{name_s}")
    return 0


def cmd_extract(args):
    narc = parse_file(args.input)
    if args.index >= narc.file_count:
        print(f"error: index {args.index} out of range "
              f"(0..{narc.file_count - 1})", file=sys.stderr)
        return 2
    raw = narc.read(args.index)
    out_path = args.output
    written = raw
    if args.decompress:
        kind, dec = try_decompress(raw)
        if dec is not None:
            written = dec
            print(f"[*] decompressed {kind}: 0x{len(raw):X} -> 0x{len(dec):X} bytes")
        elif kind is not None:
            print(f"[!] sub-file is {kind}-compressed; decoder not implemented "
                  f"in this lane, writing raw bytes", file=sys.stderr)
        else:
            print("[*] sub-file is not compression-header-tagged, writing raw bytes")
    parent = os.path.dirname(os.path.abspath(out_path))
    if parent:
        os.makedirs(parent, exist_ok=True)
    with open(out_path, "wb") as fh:
        fh.write(written)
    print(f"[*] wrote {out_path} (0x{len(written):X} bytes)")
    return 0


def cmd_info(args):
    narc = parse_file(args.input)
    info = {
        "path": args.input,
        "file_size": narc.file_size,
        "header_size": narc.header_size,
        "file_count": narc.file_count,
        "gmif_offset": narc.gmif_offset_in_file,
        "gmif_size": narc.gmif_size,
    }
    print(json.dumps(info, indent=2))
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(
        prog="narc.py",
        description="Parse and inspect NARC (Nitro ARChive) containers.",
    )
    sub = ap.add_subparsers(dest="cmd", required=True)

    p = sub.add_parser("list", help="list a NARC's sub-files")
    p.add_argument("input")
    p.set_defaults(func=cmd_list)

    p = sub.add_parser("extract", help="extract one sub-file")
    p.add_argument("input")
    p.add_argument("index", type=int)
    p.add_argument("-o", "--output", required=True)
    p.add_argument("--decompress", action="store_true",
                   help="attempt LZ77/LZ11 decompression before writing")
    p.set_defaults(func=cmd_extract)

    p = sub.add_parser("info", help="print header/section summary as JSON")
    p.add_argument("input")
    p.set_defaults(func=cmd_info)

    args = ap.parse_args(argv)
    try:
        return args.func(args)
    except NarcError as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
