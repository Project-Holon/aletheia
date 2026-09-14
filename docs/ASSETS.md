# Asset inventory (lane 1: investigation)

This is the first asset-pipeline lane: pure investigation and inventory of the
247 NitroFS files under `extract/data/` (as unpacked by `tools/ndsrom.py`).
No asset converters exist yet. Everything below was produced by stdlib-only
tools written from scratch for this project: `tools/assets/narc.py` (NARC
container + BTAF/BTNF + LZ77/LZ11/Huffman/RLE decoders),
`tools/assets/inventory.py` (the per-file survey), `tools/assets/sdat.py`
(SDAT sound archive reader), and `tools/assets/verify_compression.py`
(whole-ROM Huffman/RLE round-trip check).

Run it yourself:

```
python tools/assets/inventory.py
```

This prints the table below to stdout and writes the full machine-readable
result (per-file magic/compression histograms, sizes) to
`build/assets/inventory.json` (gitignored; regenerate, don't commit).

To look inside one NARC:

```
python tools/assets/narc.py list extract/data/a/0/0/0
python tools/assets/narc.py info extract/data/a/0/0/0
python tools/assets/narc.py extract extract/data/a/0/0/0 2 -o build/assets/out.bin --decompress
```

## Format notes

### NARC container

A NARC is the NitroSDK "generic container" shape: a 16-byte file header,
then three fixed sections, each itself `magic(4) + size(4) + body`:

- **BTAF** (`u32 file_count` then `file_count` pairs of `(start, end)` u32
  offsets, relative to the byte right after the GMIF section header)
- **BTNF** (file name table; same directory-tree shape as the ROM's own FNT.
  Present in every NARC in this ROM. Not decoded into paths by this lane --
  the names are rarely informative for game-data archives and sub-file count
  and content are what matter for the inventory)
- **GMIF** (`magic + size` header, then the concatenated sub-file bytes)

`tools/assets/narc.py` parses all three sections and exposes sub-files by
index (offset, size, first-4-bytes magic). All 237 NARCs in this ROM parsed
cleanly with this layout; no variant section orders or missing sections were
seen.

### Compression header sniffing

Many sub-files (and a few whole top-level files) open with a BIOS-style
compression header: byte 0 is the type tag, bytes 1..3 are the 24-bit LE
decompressed size.

| tag | type | decoded in this lane? |
|---|---|---|
| 0x10 | LZ77 ("LZ77 UnComp") | yes |
| 0x11 | LZ11 | yes |
| 0x24 | Huffman, 4-bit | decoded (see below) |
| 0x28 | Huffman, 8-bit | decoded (see below) |
| 0x30 | RLE | decoded (see below) |

LZ77 and LZ11 were quick to write (both are simple forward-window token
streams, unrelated to `tools/blz.py`'s BLZ which is a *backward* LZ77 used
only for ARM9/overlays) and are included, self-checked against the header's
declared decompressed size on every sub-file scanned:

- **LZ11**: every sniffed instance across the sampled sub-files (4660+ during
  spot checks, 10794 total per the full inventory run) decoded and matched
  the declared size exactly. High confidence the decoder is correct.
- **LZ77**: 909 of 953 sniffed instances (out of 1522 total tag-0x10
  sub-files) decoded and matched the declared size; 44 raised a decode error
  (match offset before the start of output). Those are very likely **false
  positives of the sniff**, not decoder bugs: a tag byte of 0x10 with a
  plausible-looking 24-bit size can occur by chance in any binary blob
  (Game Freak's many custom formats have no magic and start with arbitrary
  bytes). `narc.py extract --decompress` reports these as errors rather than
  emitting garbage. Do not trust an LZ77 sniff blindly; verify the round trip
  before treating a hit as real.
- **Huffman/RLE**: decoded in this lane (`decompress_huffman()` for 0x24/
  0x28, `decompress_rle()` for 0x30, both in `tools/assets/narc.py`). See
  "Huffman/RLE decoder verification" below for the full result -- the
  short version is that the decoders are correct (verified against
  hand-built synthetic test vectors), but this ROM's NARCs contain
  essentially **no genuine BIOS-Huffman or BIOS-RLE compressed sub-files**:
  the tag-byte sniff used by the previous lane had a bug that made it match
  false positives, and after fixing the sniff, the small number of
  remaining tag matches are themselves almost all false positives (a tiny
  custom-format data record whose first byte coincidentally looks like a
  compression header).

### Huffman/RLE decoder verification

`tools/assets/narc.py` now implements `decompress_huffman()` (BIOS-style
0x24 four-bit and 0x28 eight-bit variants, per the public GBATEK-documented
tree-table algorithm: a byte0 type/width tag, 24-bit declared size, a
tree-size byte, a binary tree of 8-bit nodes reached by walking a 32-bit-word
bitstream MSB-first, data units packed LSB-first into output bytes) and
`decompress_rle()` (0x30: alternating compressed-run/literal-run blocks).
Both were validated two ways:

1. **Synthetic self-test** (not committed as a test file, run ad hoc): a
   hand-built 3-symbol Huffman8 tree (root node with two leaf children) and
   a hand-built RLE stream (one compressed run + one literal run) both
   decoded to the exact expected bytes. This confirms the decoder logic
   itself is correct against the documented algorithm.
2. **Whole-ROM scan** (`tools/assets/verify_compression.py`, run over every
   NARC in `extract/data/`): found and attempted to decode every sub-file
   whose first byte matches a Huffman or RLE tag, comparing decoded length
   against the header's declared size.

While writing the verifier, a **bug was found and fixed** in
`sniff_compression()`: the previous lane's condition for recognising a
Huffman tag accidentally matched bare byte `0x20` (which is not a valid
Huffman header -- the low nibble must be 4 or 8, since it encodes the
data-unit width) instead of the intended `0x24`/`0x28`. `0x20` is the ASCII
space character, so this sniff was mostly firing on `a/0/0/6`'s `" APS"`
trainer-sprite wrapper magic (byte 0 is the space in `" APS"`) -- explaining
the previous lane's reported "800 Huffman4 sub-files, all in `a/0/0/6`".
None of those 800 are real Huffman data; `narc.py`'s sniff now requires
`(tag & 0xF0) == 0x20 and (tag & 0x0F) in (4, 8)`.

With the fixed sniff, the whole-ROM scan finds far fewer candidates, and
almost none decode cleanly:

| kind | tag matches found | decoded size == declared | notes |
|---|---:|---:|---|
| Huffman4 (0x24) | 21 | 3 | the 3 "passes" all declare 0-13 bytes of output -- too small to be meaningful confirmation, likely also coincidental |
| Huffman8 (0x28) | 62 | 8 | same caveat: passes are all 0-2 declared bytes |
| RLE (0x30) | 32 | 7 | passes are 0-1 declared bytes |

Every *failing* match has an absurd implied compression ratio (e.g. a
16-byte sub-file "declaring" an 88,322-byte decompressed size -- physically
impossible for BIOS RLE, whose maximum ratio is about 65:1), which is the
signature of a tag byte matching by chance inside a small, fixed-size
Game Freak data record rather than a real compression header. All of these
false positives live in the NARCs already flagged in the inventory as
"text banks (guess)" / "scripts/data tables (guess)" -- archives of
hundreds of tiny (2-180 byte) per-entry binary records, exactly where a
1-in-256-ish coincidental tag match is expected to turn up occasionally.

**Conclusion: this ROM's extracted NARCs contain no confirmed genuine
BIOS-Huffman or BIOS-RLE compressed sub-file.** The decoders are written,
correct, and ready for the moment a real one turns up (e.g. inside an
as-yet-unopened custom wrapper, or a file this lane didn't scan), but there
is currently no confirmed asset that needs them. This directly overturns
the previous lane's inventory claim of "832 Huffman/RLE sub-files" and the
"trainer sprites are Huffman4-compressed" theory for `a/0/0/6` (see below).

### NITRO/G3D magics observed

Sub-file magics are stored "reversed" on disk (e.g. tile data is bytes
`RGCN`, the resource named NCGR read backwards):

| on-disk | resource | count (all NARCs) |
|---|---|---:|
| `RLCN` | NCLR (palette) | 4232 |
| `RECN` | NCER (cell bank) | 3274 |
| `RCMN` | NMCR, multi-cell resource (guess) | 2960 |
| `RAMN` | NMAR, multi-cell animation resource (guess) | 2960 |
| `RGCN` | NCGR (tile/character data) | 1880 |
| `BTX0` | NSBTX (texture) | 1341 |
| `RCSN` | NSCR (screen/map) | 503 |
| `BMD0` | NSBMD (model) | 413 |
| `RNAN` | NANR (cell animation) | 314 |
| `BCA0` | NSBCA (joint animation) | 258 |
| `BTA0` | NSBTA (texture SRT animation) | 187 |
| `BTP0` | NSBTP (texture pattern animation) | 112 |
| `BMA0` | NSBMA (material color animation) | 69 |
| `BVA0` | NSBVA (visibility animation) | 31 |
| `SDAT` | sound archive (top-level or embedded) | 3 |
| `SBNK`/`SSEQ`/`SWAR` | SDAT sub-chunks (bank/sequence/wave archive) | 4 each |

`RCMN`/`RAMN` are a guess at the expansion (by analogy with `RECN`/`RNAN` ->
NCER/NANR, "multi-cell" and "multi-cell-animation" is the most consistent
reading of their pairing with NCER/NANR in the same archives, but this is
**not verified** against any spec). None of these needed a footnote from
outside documentation; all read directly off the bytes.

28641 sub-files (about half the total) carry **no** recognisable magic and
**no** compression header: Game Freak's own custom formats (species/move/
item/trainer data tables, scripts, text, and a few oddities like `RIFF`-
tagged blobs in `a/2/1/2`). Decoding any of these is out of scope for this
lane.

## Inventory summary

- **247** NitroFS files: **237 NARC**, **10 raw** (a single blob, or an
  unrecognised format)
- **54054** total sub-files across all NARCs
- Compression histogram across all sub-files (corrected -- see "Huffman/RLE
  decoder verification" above; the original `Huffman4` figure of 800 was a
  sniff bug, all 800 hits were false positives on `a/0/0/6`'s `" APS"`
  wrapper magic): `none` ~41693, `LZ11` 10794, `LZ77` 1522, `Huffman4` 21
  (tag matches, ~3 plausibly real), `Huffman8` 62 (tag matches, ~8
  plausibly real), `RLE` 32 (tag matches, ~7 plausibly real)
- Automated category-guess breakdown (heuristic over magic/count/size only,
  see `guess_category()` in `tools/assets/inventory.py`):

  | category guess | files |
  |---|---:|
  | scripts/data tables | 77 |
  | 3D model/texture data | 51 |
  | trainer/item/UI sprites | 30 |
  | small sprite/icon set | 30 |
  | map/tileset graphics | 18 |
  | text banks | 18 |
  | unknown raw format | 7 |
  | unknown | 5 |
  | pokemon/trainer sprites | 4 |
  | sound (SDAT archive) | 3 |
  | pokemon battle sprites | 2 |
  | single compressed blob | 2 |

The automated guess is coarse (it only looks at magic/count/size, not
content) and gets outranked below by manual, evidence-based candidates for
the specific categories this project cares about first. Treat the table
below as a starting index, not a verified map.

### Full per-file table

`path` is relative to `extract/data/`. `dominant formats` lists the top 2
sub-file magics by count (a blank entry means "no recognised magic, no
compression header": a raw custom-format sub-file; a `0x...` entry is a
hex dump of an unrecognised 4-byte magic).

| path | size | type | subs | dominant formats | category guess |
|---|---:|---|---:|---|---|
| a/0/0/0 | 2924 | NARC | 5 | NCGR (tile/character data) x3, NCLR (palette) x2 | small sprite/icon set (guess) |
| a/0/0/1 | 54228 | NARC | 8 | NSCR (screen/map) x4, NCLR (palette) x2 | map/tileset graphics (guess) |
| a/0/0/2 | 3054740 | NARC | 288 | 0x0100ee01 x21, 0x01000000 x18 | scripts/data tables (guess) |
| a/0/0/3 | 1603248 | NARC | 472 | 0x01000100 x125, 0x01000200 x41 | scripts/data tables (guess) |
| a/0/0/4 | 7889304 | NARC | 14285 |  x2464, 0x11404000 x1618 | pokemon battle sprites (guess) |
| a/0/0/5 | 39236 | NARC | 13 | NCGR (tile/character data) x8, NCLR (palette) x5 | small sprite/icon set (guess) |
| a/0/0/6 | 9042232 | NARC | 733 |  APS x733 | text banks (guess) |
| a/0/0/7 | 779916 | NARC | 1431 | NCGR (tile/character data) x715,  x709 | pokemon/trainer sprites (guess) |
| a/0/0/8 | 18199420 | NARC | 649 | 0x57420300 x572, 0x47430400 x47 | text banks (guess) |
| a/0/0/9 | 18620 | NARC | 255 | 0x00000000 x253, 0x01000000 x2 | scripts/data tables (guess) |
| a/0/1/0 | 812 | NARC | 1 | 0x00000000 x1 | scripts/data tables (guess) |
| a/0/1/1 | 2823204 | NARC | 222 | NSBMD (model) x61, NSCR (screen/map) x59 | 3D model/texture data (guess) |
| a/0/1/2 | 20556 | NARC | 1 | 0x04104a00 x1 | scripts/data tables (guess) |
| a/0/1/3 | 2820 | raw | 0 | 0x00000000 x1 | unknown raw format |
| a/0/1/4 | 11946732 | NARC | 282 | NSBTX (texture) x282 | 3D model/texture data (guess) |
| a/0/1/5 | 172 | NARC | 5 | 0x00008410 x2, 0x00004049 x1 | scripts/data tables (guess) |
| a/0/1/6 | 46780 | NARC | 669 | dddd x6, 2AkV x5 | text banks (guess) |
| a/0/1/7 | 3348 | NARC | 8 | 0x00000000 x8 | scripts/data tables (guess) |
| a/0/1/8 | 46904 | NARC | 668 | 0x21000100 x105, 0x0a000100 x45 | text banks (guess) |
| a/0/1/9 | 34788 | NARC | 668 | 0x00000000 x365, 0x04001e00 x22 | text banks (guess) |
| a/0/2/0 | 7852 | NARC | 650 | 0x8500 x8, 0x0901 x5 | text banks (guess) |
| a/0/2/1 | 24692 | NARC | 560 | 0x000d0000 x40, 0x00020000 x20 | text banks (guess) |
| a/0/2/2 | 3800 | NARC | 3 | NCLR (palette) x1, NCGR (tile/character data) x1 | map/tileset graphics (guess) |
| a/0/2/3 | 650120 | NARC | 8 | NFTR variant (font, guess) x5, NCLR (palette) x3 | unknown |
| a/0/2/4 | 27640 | NARC | 627 | 0x00000000 x168, 0xe8030000 x85 | text banks (guess) |
| a/0/2/5 | 565576 | NARC | 1005 | NCLR (palette) x552, NCGR (tile/character data) x451 | pokemon/trainer sprites (guess) |
| a/0/2/6 | 22228 | NARC | 15 | NCLR (palette) x4, 0x10240600 x4 | small sprite/icon set (guess) |
| a/0/2/7 | 85968 | NARC | 17 | NCGR (tile/character data) x7, NCLR (palette) x3 | small sprite/icon set (guess) |
| a/0/2/8 | 68224 | NARC | 17 | NCLR (palette) x5, NCGR (tile/character data) x4 | small sprite/icon set (guess) |
| a/0/2/9 | 79564 | NARC | 18 | NSCR (screen/map) x7, NCLR (palette) x4 | small sprite/icon set (guess) |
| a/0/3/0 | 109492 | NARC | 35 | NCGR (tile/character data) x14, NCLR (palette) x6 | trainer/item/UI sprites (guess) |
| a/0/3/1 | 51012 | NARC | 24 | NCER (cell bank) x7, NANR (cell animation) x7 | trainer/item/UI sprites (guess) |
| a/0/3/2 | 60324 | NARC | 97 | NCGR (tile/character data) x32, NCER (cell bank) x32 | trainer/item/UI sprites (guess) |
| a/0/3/3 | 97944 | NARC | 33 | NCLR (palette) x11, NSCR (screen/map) x10 | trainer/item/UI sprites (guess) |
| a/0/3/4 | 192004 | NARC | 39 | NSCR (screen/map) x15, NCLR (palette) x9 | trainer/item/UI sprites (guess) |
| a/0/3/5 | 7780 | NARC | 16 | NCLR (palette) x4, 0x10240600 x2 | small sprite/icon set (guess) |
| a/0/3/6 | 28172 | NARC | 14 | 0x11240800 x3, NCER (cell bank) x2 | small sprite/icon set (guess) |
| a/0/3/7 | 5436 | NARC | 1 | 0x3019080f x1 | scripts/data tables (guess) |
| a/0/3/8 | 636 | NARC | 1 | 0x03090200 x1 | scripts/data tables (guess) |
| a/0/3/9 | 16468 | NARC | 18 | 0x11240800 x9, NCLR (palette) x3 | small sprite/icon set (guess) |
| a/0/4/0 | 195596 | NARC | 53 | NCLR (palette) x25, NSCR (screen/map) x12 | 3D model/texture data (guess) |
| a/0/4/1 | 114144 | NARC | 33 | NCLR (palette) x16, NCGR (tile/character data) x16 | map/tileset graphics (guess) |
| a/0/4/2 | 1500 | NARC | 1 | 0xc4030000 x1 | scripts/data tables (guess) |
| a/0/4/3 | 175336 | NARC | 47 | NCGR (tile/character data) x14, NSCR (screen/map) x11 | trainer/item/UI sprites (guess) |
| a/0/4/4 | 55112 | NARC | 12 | NCLR (palette) x4, NCGR (tile/character data) x3 | small sprite/icon set (guess) |
| a/0/4/5 | 91248 | NARC | 102 | NSBTX (texture) x101, 0x22000000 x1 | 3D model/texture data (guess) |
| a/0/4/6 | 92312 | NARC | 27 | NCGR (tile/character data) x7, NSCR (screen/map) x6 | 3D model/texture data (guess) |
| a/0/4/7 | 624420 | NARC | 80 | 0x38000000 x25, NCGR (tile/character data) x8 | 3D model/texture data (guess) |
| a/0/4/8 | 22436 | NARC | 1 | 0x1f030000 x1 | scripts/data tables (guess) |
| a/0/4/9 | 3645668 | NARC | 764 | NSBTX (texture) x758, NSBMD (model) x6 | 3D model/texture data (guess) |
| a/0/5/0 | 4780 | NARC | 2 | NCLR (palette) x1, NCGR (tile/character data) x1 | small sprite/icon set (guess) |
| a/0/5/1 | 1672 | NARC | 9 | NCER (cell bank) x3, NANR (cell animation) x3 | small sprite/icon set (guess) |
| a/0/5/2 | 8914092 | NARC | 14285 |  x2464, 0x11301200 x1618 | pokemon battle sprites (guess) |
| a/0/5/3 | 3296 | NARC | 19 | 0x00000000 x18, 0x58660000 x1 | scripts/data tables (guess) |
| a/0/5/4 | 10928 | NARC | 11 | NCGR (tile/character data) x3, NCLR (palette) x2 | small sprite/icon set (guess) |
| a/0/5/5 | 8960 | NARC | 29 | NCGR (tile/character data) x26, NCER (cell bank) x1 | trainer/item/UI sprites (guess) |
| a/0/5/6 | 72308 | NARC | 44 | NCGR (tile/character data) x11, NANR (cell animation) x9 | 3D model/texture data (guess) |
| a/0/5/7 | 447336 | NARC | 899 | 0x00000000 x266, 0x02000000 x131 | text banks (guess) |
| a/0/5/8 | 8876 | NARC | 17 | 0x1a000e00 x1, 0x1a003d00 x1 | scripts/data tables (guess) |
| a/0/5/9 | 89292 | NARC | 18 | NCLR (palette) x5, NCGR (tile/character data) x5 | small sprite/icon set (guess) |
| a/0/6/0 | 1732 | NARC | 1 | 0xed000000 x1 | scripts/data tables (guess) |
| a/0/6/1 | 44180 | NARC | 56 | 0x04000000 x56 | scripts/data tables (guess) |
| a/0/6/2 | 7932 | NARC | 10 | 0x04000000 x10 | scripts/data tables (guess) |
| a/0/6/3 | 44504 | NARC | 17 | NSCR (screen/map) x10, NCLR (palette) x3 | small sprite/icon set (guess) |
| a/0/6/4 | 51376 | NARC | 48 | 0x11b00c00 x6, 0x11404000 x6 | trainer/item/UI sprites (guess) |
| a/0/6/5 | 33436 | NARC | 2 | NCGR (tile/character data) x1, NCLR (palette) x1 | small sprite/icon set (guess) |
| a/0/6/6 | 435516 | NARC | 601 | 0x01000000 x574, 0x02000000 x23 | text banks (guess) |
| a/0/6/7 | 47252 | NARC | 98 | 0x01000000 x96, 0x02000000 x2 | scripts/data tables (guess) |
| a/0/6/8 | 10968 | NARC | 3 | NCGR (tile/character data) x1, NCLR (palette) x1 | map/tileset graphics (guess) |
| a/0/6/9 | 84028 | NARC | 29 | NSBTA (texture SRT animation) x29 | scripts/data tables (guess) |
| a/0/7/0 | 24200 | NARC | 6 | 0x01000000 x3, 0x05000000 x2 | scripts/data tables (guess) |
| a/0/7/1 | 65652 | NARC | 39 | NCGR (tile/character data) x12, NCER (cell bank) x10 | trainer/item/UI sprites (guess) |
| a/0/7/2 | 254480 | NARC | 760 | 0x11b00c00 x95, 0x11404000 x95 | pokemon/trainer sprites (guess) |
| a/0/7/3 | 51376 | NARC | 48 | 0x11b00c00 x6, 0x11404000 x6 | trainer/item/UI sprites (guess) |
| a/0/7/4 | 956 | NARC | 1 | NSBMD (model) x1 | 3D model/texture data (guess) |
| a/0/7/5 | 488456 | NARC | 151 | NSBMD (model) x49, NSBTX (texture) x47 | 3D model/texture data (guess) |
| a/0/7/6 | 90200 | NARC | 29 | NCGR (tile/character data) x9, NCLR (palette) x7 | trainer/item/UI sprites (guess) |
| a/0/7/7 | 75500 | NARC | 8 | NSCR (screen/map) x4, NCGR (tile/character data) x3 | map/tileset graphics (guess) |
| a/0/7/8 | 170496 | NARC | 179 | NCGR (tile/character data) x55, NCER (cell bank) x51 | trainer/item/UI sprites (guess) |
| a/0/7/9 | 164308 | NARC | 34 | 0x524c0500 x17, 0x03000000 x3 | scripts/data tables (guess) |
| a/0/8/0 | 132 | NARC | 1 | 0x98a30000 x1 | scripts/data tables (guess) |
| a/0/8/1 | 372 | NARC | 14 | 0x9f7f0000 x4, 0xd0070000 x1 | scripts/data tables (guess) |
| a/0/8/2 | 848 | NARC | 2 | 0x04000000 x1,  x1 | scripts/data tables (guess) |
| a/0/8/3 | 73488 | NARC | 172 | NCGR (tile/character data) x66, NCLR (palette) x37 | trainer/item/UI sprites (guess) |
| a/0/8/4 | 5384 | NARC | 4 | NCLR (palette) x2, NCGR (tile/character data) x1 | map/tileset graphics (guess) |
| a/0/8/5 | 177788 | NARC | 21 | NCGR (tile/character data) x7, NCLR (palette) x5 | trainer/item/UI sprites (guess) |
| a/0/8/6 | 3356 | NARC | 1 | 0x85010100 x1 | scripts/data tables (guess) |
| a/0/8/7 | 168 | NARC | 1 | 0x23fb0307 x1 | scripts/data tables (guess) |
| a/0/8/8 | 184160 | NARC | 40 | NCGR (tile/character data) x11, NCLR (palette) x11 | trainer/item/UI sprites (guess) |
| a/0/8/9 | 42088 | NARC | 24 | NCGR (tile/character data) x5, NSCR (screen/map) x5 | 3D model/texture data (guess) |
| a/0/9/0 | 7108 | NARC | 1 | 0x01000000 x1 | scripts/data tables (guess) |
| a/0/9/1 | 1292 | NARC | 1 | 0x00000000 x1 | scripts/data tables (guess) |
| a/0/9/2 | 17296 | NARC | 616 | 0x00270001 x18, 0x001b0001 x15 | text banks (guess) |
| a/0/9/3 | 17144 | NARC | 616 | 0x00000a00 x35, 0x64004000 x23 | text banks (guess) |
| a/0/9/4 | 312980 | NARC | 53 | NCGR (tile/character data) x19, NSCR (screen/map) x19 | 3D model/texture data (guess) |
| a/0/9/5 | 1916912 | NARC | 165 | NCGR (tile/character data) x60, NCLR (palette) x60 | trainer/item/UI sprites (guess) |
| a/0/9/6 | 52720 | NARC | 42 | NCLR (palette) x9, 0x10240500 x6 | trainer/item/UI sprites (guess) |
| a/0/9/7 | 25232 | NARC | 2 | 0x00000000 x1, 0x44008501 x1 | scripts/data tables (guess) |
| a/0/9/8 | 12676 | NARC | 10 | 0x01000200 x2, 0x00000000 x1 | scripts/data tables (guess) |
| a/0/9/9 | 12348 | NARC | 17 | 0x10240100 x4, 0x10580000 x3 | small sprite/icon set (guess) |
| a/1/0/0 | 17712 | NARC | 20 | 0x10240600 x16, 0x10640f00 x1 | unknown |
| a/1/0/1 | 732 | NARC | 1 | 0xf9000000 x1 | scripts/data tables (guess) |
| a/1/0/2 | 75088 | NARC | 31 | NSCR (screen/map) x15, NCGR (tile/character data) x5 | 3D model/texture data (guess) |
| a/1/0/3 | 1883984 | NARC | 64 | NSBCA (animation) x20, NSBMD (model) x20 | 3D model/texture data (guess) |
| a/1/0/4 | 257708 | NARC | 13 | NSBCA (animation) x3, NSBMD (model) x3 | 3D model/texture data (guess) |
| a/1/0/5 | 5736 | NARC | 29 | 0x00000106 x1, 0x01000206 x1 | scripts/data tables (guess) |
| a/1/0/6 | 22864 | NARC | 20 | NCLR (palette) x5, NCGR (tile/character data) x5 | trainer/item/UI sprites (guess) |
| a/1/0/7 | 155952 | NARC | 39 | NSBTA (texture SRT animation) x17, NSBCA (animation) x8 | 3D model/texture data (guess) |
| a/1/0/8 | 10228 | NARC | 282 | 0x01000000 x281, 0x02000000 x1 | scripts/data tables (guess) |
| a/1/0/9 | 256 | NARC | 17 | 0x05000000 x1, 0x0600ffff x1 | scripts/data tables (guess) |
| a/1/1/0 | 33440 | NARC | 2 | NSBMD (model) x1, NSBCA (animation) x1 | 3D model/texture data (guess) |
| a/1/1/1 | 25144 | NARC | 6 | 0x00501428 x1, 0x01000400 x1 | scripts/data tables (guess) |
| a/1/1/2 | 23876 | NARC | 6 | 0x03145028 x1, 0x01000300 x1 | scripts/data tables (guess) |
| a/1/1/3 | 24000 | NARC | 6 | 0x01282850 x1, 0x01000300 x1 | scripts/data tables (guess) |
| a/1/1/4 | 23876 | NARC | 6 | 0x02282814 x1, 0x01000400 x1 | scripts/data tables (guess) |
| a/1/1/5 | 2878656 | NARC | 183 | NSBMD (model) x60, NSBCA (animation) x42 | 3D model/texture data (guess) |
| a/1/1/6 | 92312 | NARC | 79 | NCLR (palette) x29, 0x10c03400 x24 | trainer/item/UI sprites (guess) |
| a/1/1/7 | 2384 | NARC | 53 | 0x08000000 x17, 0x0f000000 x16 | scripts/data tables (guess) |
| a/1/1/8 | 22348 | NARC | 11 | NSCR (screen/map) x5, NCGR (tile/character data) x2 | small sprite/icon set (guess) |
| a/1/1/9 | 832 | NARC | 9 | 0x0d000500 x3, 0x0000 x3 | scripts/data tables (guess) |
| a/1/2/0 | 50508 | NARC | 5 | NCGR (tile/character data) x2, NSCR (screen/map) x2 | map/tileset graphics (guess) |
| a/1/2/1 | 62356 | NARC | 23 | 0x50000000 x8, NSBCA (animation) x4 | 3D model/texture data (guess) |
| a/1/2/2 | 31264 | NARC | 15 | NSBMD (model) x6, NSBCA (animation) x6 | 3D model/texture data (guess) |
| a/1/2/3 | 13140 | NARC | 650 | 0x0000 x389, 0x0a005701 x4 | text banks (guess) |
| a/1/2/4 | 56196 | NARC | 29 | NCGR (tile/character data) x8, NCER (cell bank) x6 | trainer/item/UI sprites (guess) |
| a/1/2/5 | 131304 | NARC | 428 | 0x60000000 x25, 0x2c000000 x25 | scripts/data tables (guess) |
| a/1/2/6 | 35284 | NARC | 112 | 0x03000000 x39, 0x03000100 x25 | scripts/data tables (guess) |
| a/1/2/7 | 50012 | NARC | 7 | 0xc4090000 x2, 0x78000000 x2 | 3D model/texture data (guess) |
| a/1/2/8 | 56992 | NARC | 8 | NCLR (palette) x3, NCGR (tile/character data) x2 | small sprite/icon set (guess) |
| a/1/2/9 | 465644 | NARC | 12 | NSBCA (animation) x6, NSBMD (model) x6 | 3D model/texture data (guess) |
| a/1/3/0 | 113136 | NARC | 36 | NSBTP (texture pattern animation) x20, NSBTA (texture SRT animation) x14 | 3D model/texture data (guess) |
| a/1/3/1 | 693020 | NARC | 69 | NCGR (tile/character data) x31, NCLR (palette) x18 | trainer/item/UI sprites (guess) |
| a/1/3/2 | 292 | NARC | 5 | 0x10000000 x1, 0x61000000 x1 | scripts/data tables (guess) |
| a/1/3/3 | 52652 | NARC | 12 | NSCR (screen/map) x6, NCLR (palette) x2 | small sprite/icon set (guess) |
| a/1/3/4 | 19509524 | NARC | 670 | 0x11000002 x670 | text banks (guess) |
| a/1/3/5 | 37260 | NARC | 28 | NSBCA (animation) x12, NSBMD (model) x8 | 3D model/texture data (guess) |
| a/1/3/6 | 548 | NARC | 31 | 0xd6007f06 x1, 0xd7007f02 x1 | scripts/data tables (guess) |
| a/1/3/7 | 160984 | NARC | 108 | NCLR (palette) x41, NSCR (screen/map) x36 | trainer/item/UI sprites (guess) |
| a/1/3/8 | 26132 | NARC | 8 | NSBTA (texture SRT animation) x4, NSBMD (model) x3 | 3D model/texture data (guess) |
| a/1/3/9 | 52420 | NARC | 12 | NCLR (palette) x4, NCGR (tile/character data) x4 | map/tileset graphics (guess) |
| a/1/4/0 | 93668 | NARC | 7 | NCLR (palette) x2, NCGR (tile/character data) x2 | sound (SDAT archive) |
| a/1/4/1 | 22192 | NARC | 14 | NCLR (palette) x4, NCGR (tile/character data) x4 | small sprite/icon set (guess) |
| a/1/4/2 | 342860 | NARC | 39 | NSBTX (texture) x24, NCLR (palette) x4 | sound (SDAT archive) |
| a/1/4/3 | 152488 | NARC | 28 | NSCR (screen/map) x10, NCLR (palette) x6 | trainer/item/UI sprites (guess) |
| a/1/4/4 | 134516 | NARC | 24 | NSCR (screen/map) x10, NCLR (palette) x5 | trainer/item/UI sprites (guess) |
| a/1/4/5 | 43456 | NARC | 8 | NCLR (palette) x4, NSCR (screen/map) x3 | map/tileset graphics (guess) |
| a/1/4/6 | 412 | NARC | 10 | 0x98000000 x1, 0x99000000 x1 | scripts/data tables (guess) |
| a/1/4/7 | 192 | NARC | 3 | 0x2b040000 x1, 0x22040000 x1 | scripts/data tables (guess) |
| a/1/4/8 | 110800 | NARC | 18 | 0xe8030000 x4, 0x58020000 x4 | 3D model/texture data (guess) |
| a/1/4/9 | 92 | NARC | 1 | 0x44010000 x1 | scripts/data tables (guess) |
| a/1/5/0 | 407364 | NARC | 32 | NSBMD (model) x12, NSBTP (texture pattern animation) x8 | 3D model/texture data (guess) |
| a/1/5/1 | 109252 | NARC | 12 | NCLR (palette) x4, NCGR (tile/character data) x4 | map/tileset graphics (guess) |
| a/1/5/2 | 3740 | NARC | 3 | 0x01000000 x1, 0x22000000 x1 | scripts/data tables (guess) |
| a/1/5/3 | 60708 | NARC | 9 | NSBCA (animation) x4, NSBMD (model) x3 | 3D model/texture data (guess) |
| a/1/5/4 | 3996 | NARC | 37 | 0x0c000200 x2, 0x35000200 x2 | scripts/data tables (guess) |
| a/1/5/5 | 46844 | NARC | 48 | NCLR (palette) x15, 0x10240600 x13 | trainer/item/UI sprites (guess) |
| a/1/5/6 | 149164 | NARC | 46 | 0x0400080c x44, 0x04000818 x2 | scripts/data tables (guess) |
| a/1/5/7 | 51428 | NARC | 26 | NSBTA (texture SRT animation) x15, NSBMD (model) x8 | 3D model/texture data (guess) |
| a/1/5/8 | 1100 | NARC | 5 | 0x01000100 x1, 0x05001900 x1 | scripts/data tables (guess) |
| a/1/5/9 | 535720 | NARC | 113 | NSCR (screen/map) x38, NCGR (tile/character data) x33 | trainer/item/UI sprites (guess) |
| a/1/6/0 | 11699360 | NARC | 252 | NSBMD (model) x81, NSBCA (animation) x52 | 3D model/texture data (guess) |
| a/1/6/1 | 3852 | NARC | 5 | 0x10240600 x3, NCLR (palette) x1 | unknown |
| a/1/6/2 | 71316 | NARC | 19 | NSBCA (animation) x12, NSBMD (model) x5 | 3D model/texture data (guess) |
| a/1/6/3 | 416 | NARC | 7 | 0xfa2000d5 x1, 0x4a1d00d5 x1 | scripts/data tables (guess) |
| a/1/6/4 | 11596 | NARC | 5 | NCGR (tile/character data) x2, NSCR (screen/map) x2 | map/tileset graphics (guess) |
| a/1/6/5 | 1560 | NARC | 13 | 0x00000000 x1, 0x01000000 x1 | scripts/data tables (guess) |
| a/1/6/6 | 448 | NARC | 9 | 0x00000000 x7, 0x14000000 x1 | scripts/data tables (guess) |
| a/1/6/7 | 76604 | NARC | 655 | 0x10300100 x650, NANR (cell animation) x2 | pokemon/trainer sprites (guess) |
| a/1/6/8 | 37160 | NARC | 315 | 0x55002300 x6, 0x02003200 x5 | scripts/data tables (guess) |
| a/1/6/9 | 22876 | NARC | 951 | 0x41005e00 x4, 0xad01f700 x4 | text banks (guess) |
| a/1/7/0 | 274724 | NARC | 37 | NCLR (palette) x7, NCGR (tile/character data) x6 | 3D model/texture data (guess) |
| a/1/7/1 | 44400 | NARC | 14 | 0x51005007 x1, 0x5100c000 x1 | scripts/data tables (guess) |
| a/1/7/2 | 244544 | NARC | 27 | NCLR (palette) x8, NCGR (tile/character data) x7 | trainer/item/UI sprites (guess) |
| a/1/7/3 | 32860 | NARC | 35 | NCGR (tile/character data) x14, NCLR (palette) x6 | trainer/item/UI sprites (guess) |
| a/1/7/4 | 3220 | NARC | 24 | 0x5c000000 x2, 0x83000000 x2 | scripts/data tables (guess) |
| a/1/7/5 | 140 | NARC | 2 | 0x00000000 x2 | scripts/data tables (guess) |
| a/1/7/6 | 1578480 | NARC | 52 | NSBTX (texture) x52 | 3D model/texture data (guess) |
| a/1/7/7 | 1135876 | NARC | 64 | NSBTX (texture) x64 | 3D model/texture data (guess) |
| a/1/7/8 | 168792 | NARC | 649 | 0x01010000 x435, 0x01000000 x199 | text banks (guess) |
| a/1/7/9 | 3652 | NARC | 50 | 0x07000000 x1, 0x08000000 x1 | scripts/data tables (guess) |
| a/1/8/0 | 60792 | NARC | 44 | 0x10402000 x22, NCLR (palette) x22 | unknown |
| a/1/8/1 | 138256 | NARC | 35 | NSBCA (animation) x6, NSBMA (material color animation) x6 | 3D model/texture data (guess) |
| a/1/8/2 | 39072 | NARC | 11 | NCGR (tile/character data) x2, NANR (cell animation) x1 | 3D model/texture data (guess) |
| a/1/8/3 | 186876 | NARC | 28 | NSBMD (model) x12, NSCR (screen/map) x6 | 3D model/texture data (guess) |
| a/1/8/4 | 69508 | NARC | 17 | NCLR (palette) x6, NCGR (tile/character data) x4 | small sprite/icon set (guess) |
| a/1/8/5 | 84 | NARC | 2 | 0x1f040000 x1, 0x21040000 x1 | scripts/data tables (guess) |
| a/1/8/6 | 468 | NARC | 7 | 0x37005a00 x2, 0x19003c00 x1 | scripts/data tables (guess) |
| a/1/8/7 | 109764 | NARC | 12 | NCLR (palette) x4, NCGR (tile/character data) x4 | map/tileset graphics (guess) |
| a/1/8/8 | 11056 | NARC | 5 | NSCR (screen/map) x3, NCLR (palette) x1 | map/tileset graphics (guess) |
| a/1/8/9 | 35084 | NARC | 11 | NCGR (tile/character data) x2, NANR (cell animation) x1 | 3D model/texture data (guess) |
| a/1/9/0 | 69356 | NARC | 7 | NSBMD (model) x3, NSBTA (texture SRT animation) x3 | 3D model/texture data (guess) |
| a/1/9/1 | 20024 | NARC | 9 | NCGR (tile/character data) x3, NCLR (palette) x2 | small sprite/icon set (guess) |
| a/1/9/2 | 105128 | NARC | 23 | NSCR (screen/map) x10, NCGR (tile/character data) x8 | trainer/item/UI sprites (guess) |
| a/1/9/3 | 20892 | NARC | 14 | NSCR (screen/map) x6, NCGR (tile/character data) x4 | small sprite/icon set (guess) |
| a/1/9/4 | 7876 | NARC | 652 | 0x10296e00 x230, 0x10297800 x130 | text banks (guess) |
| a/1/9/5 | 14408 | NARC | 14 | NCGR (tile/character data) x4, NCER (cell bank) x3 | small sprite/icon set (guess) |
| a/1/9/6 | 2608 | NARC | 7 | NCLR (palette) x2, 0x10240600 x1 | small sprite/icon set (guess) |
| a/1/9/7 | 152180 | NARC | 8 | NSBMD (model) x5, NCGR (tile/character data) x1 | 3D model/texture data (guess) |
| a/1/9/8 | 316 | NARC | 1 | 0x10400400 x1 | scripts/data tables (guess) |
| a/1/9/9 | 5448 | NARC | 11 | NCLR (palette) x3, 0x10240800 x2 | small sprite/icon set (guess) |
| a/2/0/0 | 4312 | NARC | 3 | NCGR (tile/character data) x1, NCLR (palette) x1 | map/tileset graphics (guess) |
| a/2/0/1 | 39764 | NARC | 8 | NCLR (palette) x2, NCGR (tile/character data) x2 | small sprite/icon set (guess) |
| a/2/0/2 | 109020 | NARC | 10 | NCLR (palette) x3, NCGR (tile/character data) x3 | small sprite/icon set (guess) |
| a/2/0/3 | 11276 | NARC | 4 | 0x78000000 x1, 0x28000000 x1 | scripts/data tables (guess) |
| a/2/0/4 | 29092 | NARC | 8 | NSBMD (model) x2, NSBCA (animation) x2 | 3D model/texture data (guess) |
| a/2/0/5 | 291408 | NARC | 40 | NCLR (palette) x12, NCGR (tile/character data) x6 | 3D model/texture data (guess) |
| a/2/0/6 | 20228 | NARC | 4 | NSCR (screen/map) x2, NCLR (palette) x1 | map/tileset graphics (guess) |
| a/2/0/7 | 58508 | NARC | 1 | NSBMD (model) x1 | 3D model/texture data (guess) |
| a/2/0/8 | 1228 | NARC | 4 | 0x44020000 x1, 0x6a000000 x1 | scripts/data tables (guess) |
| a/2/0/9 | 916 | NARC | 1 | 0x00000100 x1 | scripts/data tables (guess) |
| a/2/1/0 | 11928 | NARC | 9 | NSBMD (model) x3, NSBTA (texture SRT animation) x3 | 3D model/texture data (guess) |
| a/2/1/1 | 4588 | NARC | 1 | 0x01000200 x1 | scripts/data tables (guess) |
| a/2/1/2 | 34708 | NARC | 2 | RIFF x2 | scripts/data tables (guess) |
| a/2/1/3 | 3500 | NARC | 8 | 0x11240600 x4, 0x11402000 x2 | unknown |
| a/2/1/4 | 24052 | NARC | 1000 | 0x00000000 x12, 0x72021f02 x3 | text banks (guess) |
| a/2/1/5 | 41780 | NARC | 315 | 0x3d005800 x5, 0x3e005800 x5 | scripts/data tables (guess) |
| a/2/1/6 | 1353488 | NARC | 52 | NCLR (palette) x21,  APS x18 | trainer/item/UI sprites (guess) |
| a/2/1/7 | 9564 | NARC | 2 | NSBMD (model) x1, NSBTA (texture SRT animation) x1 | 3D model/texture data (guess) |
| a/2/1/8 | 9516 | NARC | 4 | NSBMD (model) x1, NSBCA (animation) x1 | 3D model/texture data (guess) |
| a/2/1/9 | 66120 | NARC | 10 | NSBTP (texture pattern animation) x3, NSBMD (model) x2 | 3D model/texture data (guess) |
| a/2/2/0 | 531688 | NARC | 13 | 0x00000000 x2, NCLR (palette) x2 | 3D model/texture data (guess) |
| a/2/2/1 | 23788 | NARC | 7 | 0x411673ec x1, 0x42166eec x1 | scripts/data tables (guess) |
| a/2/2/2 | 27956 | NARC | 6 | NSBMD (model) x6 | 3D model/texture data (guess) |
| a/2/2/3 | 12472 | NARC | 13 | NSCR (screen/map) x3, NCLR (palette) x2 | small sprite/icon set (guess) |
| a/2/2/4 | 228 | NARC | 4 | 0xffff0000 x4 | scripts/data tables (guess) |
| a/2/2/5 | 1898452 | NARC | 151 | 0x11000002 x151 | scripts/data tables (guess) |
| a/2/2/6 | 4367532 | NARC | 174 | 0x11000002 x174 | scripts/data tables (guess) |
| a/2/2/7 | 556 | NARC | 1 | 0x000a1020 x1 | scripts/data tables (guess) |
| a/2/2/8 | 56140 | NARC | 6 | NSBMD (model) x2, NSBCA (animation) x2 | 3D model/texture data (guess) |
| a/2/2/9 | 4451172 | NARC | 52 | 0x41423a00 x9, 0x41423e00 x8 | scripts/data tables (guess) |
| a/2/3/0 | 4602664 | NARC | 64 | 0x41424c00 x32, 0x41425000 x6 | scripts/data tables (guess) |
| a/2/3/1 | 1208900 | NARC | 73 | 0x10008001 x73 | scripts/data tables (guess) |
| a/2/3/2 | 708 | NARC | 1 | 0x00010101 x1 | scripts/data tables (guess) |
| a/2/3/3 | 256 | NARC | 2 | 0x10300100 x2 | scripts/data tables (guess) |
| a/2/3/4 | 5848 | NARC | 3 | NCLR (palette) x1, NCGR (tile/character data) x1 | map/tileset graphics (guess) |
| dl_rom/child2_r_eng.srl | 1369088 | raw | 0 | SYAC x1 | unknown raw format |
| dl_rom/child_r_eng.srl | 1369088 | raw | 0 | SYAC x1 | unknown raw format |
| dl_rom/icon_b.char | 512 | raw | 0 | 0xdddddddd x1 | unknown raw format |
| dl_rom/icon_b.plt | 32 | raw | 0 | 0x736eda31 x1 | unknown raw format |
| dl_rom/icon_w.char | 512 | raw | 0 | UUUU x1 | unknown raw format |
| dl_rom/icon_w.plt | 32 | raw | 0 | 1FQ! x1 | unknown raw format |
| dwc/utility.bin | 929852 | raw | 0 | 0x10000000 x1 | single compressed blob (guess: font/graphic) |
| gfl_font.dat | 2320 | raw | 0 | 0x10000000 x1 | single compressed blob (guess: font/graphic) |
| skb.narc | 60336 | NARC | 6 | NCGR (tile/character data) x4, NCLR (palette) x1 | map/tileset graphics (guess) |
| soundstatus.narc | 12164 | NARC | 4 | NSCR (screen/map) x2, NCGR (tile/character data) x1 | map/tileset graphics (guess) |
| titledemo.narc | 227088 | NARC | 20 | NCLR (palette) x7, NCGR (tile/character data) x5 | 3D model/texture data (guess) |
| wb_sound_data.sdat | 51533312 | raw | 0 | SDAT (sound archive) x1 | sound (SDAT archive) |

### BTNF name table results

`tools/assets/narc.py`'s `Narc._parse_btnf()` now decodes the BTNF section
into a real `{file_id: path}` map (same directory-table shape as the ROM's
own FNT, see `tools/ndsrom.py`'s `parse_fnt()`), and each `SubFile` carries
its resolved `.name` when one exists. Scanning all 237 NARCs:

- **1 / 237 NARCs** has any usable BTNF names at all: `a/2/3/2`, whose
  single sub-file is named `battle_pocket.dat`.
- **1 / 54054** total sub-files carries a name.

This confirms the original inventory's note in passing ("sub-file names are
rarely meaningful for these game-data archives") -- essentially every NARC
in this ROM was built with an empty/degenerate BTNF subtable (root entry
present, no children), so BTNF decoding does not help disambiguate any of
the "uncertain category" archives discussed elsewhere in this document.
The one exception (`battle_pocket.dat`) is consistent with `a/2/3/2` being
UI-related data (a "pocket" of the bag/battle menu), for whatever that's
worth as a single data point.

### SDAT internal structure (`wb_sound_data.sdat`)

`tools/assets/sdat.py` (new, stdlib-only) parses the SDAT container: the
0x40-byte file header, then the SYMB (name tables), INFO (per-entry
metadata, counts only decoded here), FAT (absolute file offset/size table),
and FILE (raw sub-file data) blocks, per the public NitroSDK SDAT layout
(header + 4 named blocks; SYMB/INFO each hold 8 fixed-order record tables:
SEQ, SEQARC, BANK, WAVARC, PLAYER, GROUP, PLAYER2, STRM). Run it with:

```
python tools/assets/sdat.py extract/data/wb_sound_data.sdat --json build/assets/sdat_summary.json
```

Results for `wb_sound_data.sdat` (51,533,312 bytes, SYMB present, 3874 FAT
file entries):

| resource type | count |
|---|---:|
| SEQ (SSEQ, sequenced music/jingles/SFX-sequences) | 2076 |
| BANK (SBNK, instrument banks) | 1986 |
| WAVARC (SWAR, wave archives) | 1986 |
| PLAYER | 7 |
| GROUP | 1 |
| SEQARC, PLAYER2, STRM | 0 (none present) |

No `STRM` (streamed audio) entries exist in this archive.

**SEQ naming breakdown** (940 of 2076 SEQ slots have a SYMB name; the rest
are unnamed but still present, offset-0 name pointer):

| prefix | count | likely meaning |
|---|---:|---|
| `SEQ_SE_...` | 726 | sound-effect sequences |
| `SEQ_BGM_...` | 179 | background music tracks |
| `SEQ_ME_...` | 32 | "music effect" jingles (level-up, evolution, etc.) |
| `SEQ_PV...` | 3 | unclear, only 3 instances |

**Cries identified with high confidence, by naming pattern in BANK/WAVARC,
not SEQ:** WAVARC (and BANK, in lockstep -- both tables are 1986 entries
long and indexed identically) slots **1 through 650** are named either
`WAVE_ARC_PV###` (494 of them, e.g. `WAVE_ARC_PV001`) or
`WAVE_ARC_PMWB_###` (156 of them, e.g. `WAVE_ARC_PMWB_657`, where `###` is
a species/form index). `PMWB` reads as "Pokemon [Black/White]". 494 + 156 =
**650**, matching Black/White's 649 species (+1, likely a 1-based index
with slot 0 reserved/empty). Slot 0 and every slot from 651 onward are
either unnamed or carry `WAVE_SE_...`/`BANK_SE_...` names (sound-effect
banks, e.g. `WAVE_SE_WB_FLD_176`, `WAVE_SE_WB_SYS_101`) -- i.e. the cry
block is a contiguous, cleanly-bounded index range at the front of the
BANK/WAVARC tables. This directly resolves the previous lane's "cries not
located" gap: **cries are `wb_sound_data.sdat` BANK/WAVARC entries 1-650**,
not a separate NARC and not SEQ sequences. Decoding the actual PCM sample
data out of those WAVARC entries (via FAT offset/size) is left to the SDAT
converter lane.

**Music vs. effects split (by SEQ naming, heuristic):** `SEQ_BGM_*` (179)
is music; `SEQ_SE_*` (726) and `SEQ_ME_*` (32) are effects/jingles played
through the sequence player (separate from the raw WAVARC sound-effect
banks used for cries and simple blips). This is a naming-pattern heuristic,
not verified by listening to decoded audio.

## Where things probably live (guesses, ranked by evidence)

These are the answers to "where do I find X to build the next converter
lane." All are guesses inferred from magic/count/size shape, not from any
outside file list or wiki. Confidence is noted per entry.

- **Pokemon overworld/menu character sprites -- `a/0/0/4` and `a/0/5/2`**
  (medium confidence). Both are ~14285 sub-files (identical count), ~8-9 MB,
  and are the only archives in the ROM with `NCER`+`NMCR`+`NMAR`+`NCLR`
  present together at scale (cell banks + multi-cell + multi-cell-animation
  resources + palettes, no `NCGR` tile chunks visible at the top magic
  level -- tiles are likely nested inside the custom-tagged/LZ11-compressed
  sub-blobs that dominate the histogram). 14285 / 649 species is about 22
  sub-resources per species, consistent with a walking/direction/animation
  sprite set rather than the two static battle-sprite frames. The two
  archives (near-identical shape, different sizes) are plausibly two
  variants, e.g. normal vs. shiny, or two resolutions.

- **Pokemon battle sprites -- `a/1/3/4`** (medium confidence). 670 sub-files
  (649 species plus formes/genders), **every** sub-file LZ11-compressed,
  average ~29 KB compressed each -- large enough for an animated multi-frame
  battle sprite, too few sub-files for a per-frame-per-species table. No
  legible magic inside (custom Game Freak tile format), so the pixel layout
  itself is still unknown.

- **Trainer sprites -- `a/0/0/6`** (medium confidence on location, **Huffman4
  theory retracted**). 733 sub-files (there are on the order of 700+ trainer
  classes in Black/White), average ~12 KB each -- consistent with a
  full-body trainer portrait. The on-disk magic tag is `" APS"` (i.e.
  reversed `"SPA "`), which does not match any known NITRO chunk, so this is
  Game Freak's own wrapper. **The previous lane's claim that every sub-file
  is Huffman4-compressed was a sniff false positive**: byte 0 of `" APS"` is
  the ASCII space `0x20`, which a bug in `sniff_compression()` matched as a
  (invalid) Huffman tag -- see "Huffman/RLE decoder verification" above.
  With the sniff fixed, these sub-files carry no recognised BIOS compression
  header at all; whatever compression (if any) Game Freak used for the
  pixel data lives *after* the `" APS"` header, and its shape has not been
  determined by this pass (the trainer-sprite loader/wrapper investigation
  was deferred to a future lane to stay within this pass's budget).

- **Pokemon icons (not confirmed as "item icons") -- `a/1/6/7`**
  (low-medium confidence). 655 sub-files, average only ~107 bytes each --
  small enough for a 4bpp icon-sized tile (e.g. 16x16 = 128 bytes). 655 is
  close to the species count (649) plus a handful of extras (egg icon,
  "?" icon), which favours species icons over item icons. **Item icons are
  not confidently located** -- no archive in the table has a sub-file count
  close to Black/White's item count (~638) with a similarly small average
  size and no better magic evidence; `a/0/7/2` (760 sub-files, ~326 B
  average) is the next-best candidate but the count doesn't line up as
  cleanly. This needs the next lane's actual pixel decoding to disambiguate.

- **Pokemon cries -- located, high confidence.** `wb_sound_data.sdat`'s
  BANK and WAVARC (SBNK/SWAR) tables carry entries 1-650 named
  `WAVE_ARC_PV###` / `WAVE_ARC_PMWB_###` (and the matching `BANK_PV###` /
  `BANK_SE...` on the BANK side) -- 650 = 649 Black/White species + 1. See
  "SDAT internal structure" above for the full breakdown. This was resolved
  by opening the SDAT SYMB/INFO block structure with the new
  `tools/assets/sdat.py`.

- **Music and sound effects -- `wb_sound_data.sdat`** (high confidence; see
  "SDAT internal structure" above for the actual SEQ_BGM/SEQ_SE/SEQ_ME
  naming split, now opened and no longer a guess). It is the only file with
  an `SDAT` magic at the top level and is by far the largest file in
  `extract/data/` (51.5 MB, versus the next-largest NARC at 19.5 MB). A
  handful of small NARCs (`a/1/4/0`, `a/1/4/2`, `skb.narc`,
  `soundstatus.narc`) also turned up incidentally but their dominant
  sub-file magics are graphics (`NCLR`/`NCGR`/`NSBTX`), not sound -- they are
  more likely UI elements *about* sound (e.g. a sound-test menu) than sound
  data itself.

- **Text banks -- uncertain, several candidates, none confirmed.** The
  automated heuristic flags 18 files as "text banks" purely because they
  have >500 sub-files and no graphics magic, but most of those
  (`a/0/1/6`, `a/0/1/8`, `a/0/1/9`, `a/0/2/0`, `a/0/2/1`, `a/0/2/4`,
  `a/0/9/2`, `a/0/9/3`, `a/1/2/3`, `a/1/6/9`, `a/1/9/4`, `a/2/1/4`) have a
  tiny average sub-file size (2-60 bytes) -- too small and too regular for
  variable-length message strings, and much more likely per-species/per-item
  **fixed-size binary data tables** (base stats, level-up moves, etc.), not
  text. The better text-bank candidates are the ones with a *larger and more
  variable* average size and no graphics/model magic: **`a/0/5/7`** (899
  sub-files, ~490 B average) and **`a/0/6/6`** (601 sub-files, ~717 B
  average). Neither is confirmed; confirming requires decoding Black/White's
  character encoding, which is out of scope for this lane.

## Proposed converter lane order

Ordered by (a) how well-understood the container/pixel format already is
from this inventory, and (b) how useful the output is for other lanes (e.g.
trainer/Pokemon sprites are useful reference material once other formats are
being reverse engineered against known visuals).

1. **NARC extraction lane** (mostly done): harden `tools/assets/narc.py`
   into a general extract-all-subfiles tool with LZ11/LZ77 auto-decompress,
   writing to `build/assets/<narc>/NNNN.bin`. Needed by every lane below.
2. **NCGR/NCLR/NSCR -> PNG (tilemap graphics)**: the best-understood format
   family here (4232 NCLR + 1880 NCGR + 503 NSCR instances, standard NITRO
   tile+palette+screen chunks with documented public layouts: tile depth,
   palette count, and screen entries are all in the chunk headers). Start
   with the small, clearly-identified archives (`a/0/0/0`, `a/0/2/2`,
   `skb.narc`, tileset-guess files) to validate the chunk parser before
   tackling the bigger, custom-wrapped sprite archives.
3. **Trainer sprites (`a/0/0/6`)**: needs a Huffman4 decoder (not written in
   this lane) plus whatever raw bitmap layout Game Freak wrapped around it.
   Medium difficulty, high payoff (700+ visually verifiable sprites make a
   good testbed for the custom tile format).
4. **Pokemon battle sprites (`a/1/3/4`)**: needs the LZ11 decoder (already
   written, `tools/assets/narc.py`) plus the same custom bitmap layout as
   (3). Verifiable against 649 well-known sprites.
5. **Pokemon overworld/menu sprites (`a/0/0/4`, `a/0/5/2`)**: needs NCER/
   NMCR/NMAR cell-animation decoding on top of (3)/(4)'s bitmap format --
   more moving parts, do after the static sprite formats are solid.
6. **NSBMD/NSBTX (3D models)**: well-identified (413 BMD0 + 1341 BTX0
   instances, public G3D chunk documentation exists), but lower priority
   since Black/White is a 2D game and these are a minority of assets
   (trophies, some battle backgrounds/effects).
7. **SDAT (sound)**: `wb_sound_data.sdat` is large and self-contained;
   needs its own INFO/STRM/section-table reader (not attempted here) before
   cries/music/SFX can be split out and converted.
8. **Text banks**: lowest priority for this list since even the *location*
   of the real text data is unconfirmed (see above) and decoding needs the
   character encoding table, which does not exist yet in this project.

## Known gaps / honesty notes

(Updated by the second asset-lane pass: Huffman/RLE decoders, BTNF
decoding, and SDAT internals were closed out this pass; the trainer-sprite
wrapper investigation in `a/0/0/6` was deferred to stay within budget.)

- Category guesses throughout this document and `inventory.json` are
  heuristic and explicitly labelled "(guess)". None have been confirmed by
  actually decoding and viewing pixels, text, or audio.
- BTNF is now decoded into real paths (`Narc._parse_btnf()` in
  `tools/assets/narc.py`), but it turned out not to help: only 1 of 54054
  sub-files across all 237 NARCs carries a name (`a/2/3/2`'s single
  sub-file, `battle_pocket.dat`). See "BTNF name table results" above.
- SDAT internal structure (SYMB/INFO/FAT/FILE inside `wb_sound_data.sdat`)
  is now opened by `tools/assets/sdat.py`: counts, names, and a cry/music/
  effect split by naming pattern are in "SDAT internal structure" above.
  Not yet done: decoding the actual SSEQ/SBNK/SWAR/PCM payloads (only the
  container-level table of contents was read).
- Huffman4/Huffman8/RLE decoders are now implemented
  (`decompress_huffman()`, `decompress_rle()` in `tools/assets/narc.py`)
  and validated against hand-built synthetic test vectors. However, a sniff
  bug in the previous lane's `sniff_compression()` is now fixed, and with
  it fixed, **this ROM's NARCs contain no confirmed genuine BIOS-Huffman or
  BIOS-RLE compressed sub-file** -- see "Huffman/RLE decoder verification"
  above. The trainer-sprite wrapper in `a/0/0/6` (previously thought to be
  Huffman4) is NOT BIOS-Huffman-compressed; its real format is still
  unknown and needs a fresh investigation (byte-level structure inspection,
  cross-referencing the ARM9 loader) that this pass did not have budget for.
- `tools/assets/verify_compression.py` (new) re-runs the Huffman4/Huffman8/
  RLE round-trip check over the whole ROM; re-run it if `narc.py`'s sniff or
  decoders change.

### Trainer sprite wrapper: first look

Sub-files 0, 1 and 100 of `a/0/0/6` (NitroFS file id 248 per
`extract/manifest.json`) were extracted to `build/assets/` and hex-dumped.
All three share the same 64-byte-visible header layout (offsets in bytes,
values little-endian):

| offset | aps_0 (0x10BC B) | aps_1 (0x2174 B) | aps_100 (0x224C B) | guess |
|---|---|---|---|---|
| 0x00-0x07 | `" APS12_1"` | same | same | 8-byte ASCII magic/version tag, constant across all sampled sub-files |
| 0x08 | `0x00010001` | `0x00020002` | `0x00080001` | two u16: low16 and high16 both look like counts (1/1, 2/2, 8/1) -- possibly (sub-object count, frame count) or similar |
| 0x0C | `0x00000000` | same | same | reserved/padding |
| 0x10 | `0x78` (120) | `0x10c` (268) | `0x64` (100) | size of a leading chunk (not obviously proportional to the count field) |
| 0x14 | `0x1024` (4132) | `0x2048` (8264) | `0x21c8` (8648) | size of a second, larger chunk |
| 0x18 | `0x98` (152) | `0x12c` (300) | `0x84` (132) | size of a trailing chunk |
| 0x1C | `0x00000000` | same | same | reserved |
| 0x20 | `0x00004702` | `0x00014701` | `0x0020c800` | unclear; low byte differs, does not look like a plain size |
| 0x24-0x2C | all zero | all zero | all zero | reserved/padding |
| 0x30 onward | `0x1000`, `0x1c8d`, ... | `0xbe5`, `0x169a`, ... | `0x1000`, `0`, ... | more size-like or count-like fields, not yet decoded |
| last 4 bytes | `0x10000000` | `0x10000000` | `0x10000000` | constant sentinel/type word across all three samples |

The field at offset 0x14 plus the field at offset 0x18 equals the total
sub-file size exactly for all three samples (0x1024+0x98=0x10BC,
0x2048+0x12c=0x2174, 0x21c8+0x84=0x224c), so the wrapper appears to be a
two-chunk container (a larger payload chunk followed by a smaller trailer
chunk), with the offset-0x10 field as a possible third/leading chunk size
that is not part of that sum. No LZ77/LZ11/Huffman/RLE tag byte was found
immediately after the header (the previous "Huffman4" sniff hit was the
`" APS"` magic itself, not a real compression tag -- see above).

Searched the full 4284/8564/8780-byte dumps for `NCGR`/`RGCN` and
`NCLR`/`RLCN` magics (both orientations): none found in any of the three
samples. So this is not a NARC-in-NARC or a plain NDS graphics container
wrapped in a custom prefix -- the pixel/palette data, if present, is raw
and un-tagged. Consistent with that: aps_0 and aps_1 both end in the bytes
`... ff 7f 00 00`, and `0x7FFF` is the standard BGR555 "white" sentinel,
suggesting an embedded raw 16-bit palette tail (aps_100, with count field
8/1 instead of 1/1, has substantially more non-zero trailing bytes instead
of ending on a single `7fff`, consistent with multiple palette-like
entries for a multi-object record). This is circumstantial, not confirmed.

**Loader search.** Grepped `asm/arm9/src/*.s` and `src/matched/*.c` for:
the NitroFS file id `248`/`0xF8` (too common a small integer to be useful
-- 29 `.s` files contain a bare `248`, none obviously related), the
sub-file count `733`/`0x2DD`, the path string `a/0/0/6`, and the magic
word `0x53504120` (`" APS"`) as a `.word`/`.4byte` literal. None of the
count, path-string, or magic-word searches produced any hits anywhere in
`asm/arm9/src` or `src/matched`. This is consistent with the archive being
opened by numeric NitroFS file id resolved through a runtime table (not a
literal path string or magic compiled into ARM9 code), and/or with the
actual loader function not yet being present in `asm/arm9/src` or
`src/matched` (513 matched `.c` files and 119 `.s` files exist, but this
project is still early in decomp coverage). No loader candidate function
was identified in this pass; finding it will likely require tracing
NitroFS file-id-to-archive resolution generically (e.g. via the
`data/a/0/0/*` sibling archives that are already better understood, or via
whatever function opens `a/0/0/7`'s NCGR-containing NARC, since `a/0/0/6`
and `a/0/0/7` are adjacent trainer-sprite-related archives) rather than by
grepping for constants specific to `a/0/0/6`.

## Battle sprite archive (`a/1/3/4`): payload format, PNG decode, LZ11 codec

This is the third asset lane pass, focused specifically on `a/1/3/4`, the
670-sub-file archive proposed above as Black/White's Pokemon battle sprite
archive (649 species + forms/genders). New tools: `tools/assets/
battle_sprite.py` (payload -> PNG) and `tools/assets/lz11.py` (LZ11
encoder, complementing `narc.py`'s existing decoder).

### Payload format

Every one of the 670 sub-files is LZ11-compressed (confirmed for indices
0, 1, 25, 150 and, incidentally, all 670 via the round-trip check below),
and **every sub-file's LZ11 header declares exactly 0x020000 (131072)
bytes of decompressed output** -- not a coincidence of the four samples,
a format-level constant.

The decompressed payload has **no NITRO chunk magic anywhere** (no RGCN/
NCGR, RLCN/NCLR, RECN/NCER, RNAN/NANR) and **no embedded palette**: bare
custom tile data, nothing else recognisable. Layout, recovered by
comparing the four decompressed samples against each other (no outside
documentation used):

- Sub-file 0 (presumably an unused/reserved species-0 slot) decodes to
  the 2-byte pattern `00 80` repeated for the full 131072 bytes -- a
  filler/background value, confirmed as such below, not real pixel data.
- Diffing the other three samples against this filler isolates where real
  tile data lives. The boundary between "real content" and "filler"
  recurs at a clean **512-byte stride**: for sub-file 25, content spans of
  ~330-370 bytes alternate with filler at exactly `0x0, 0x200, 0x400, ...`
  for 32 rows, then the remaining `0x1C000` bytes are pure filler. For
  sub-file 1 the per-row content-start offset drifts smoothly (137, 137,
  139, 139, 139, 141, ...) across successive 512-byte rows -- a diagonal,
  i.e. consistent with a real silhouette edge, not noise.
- 512 bytes / 32 bytes-per-4bpp-tile (8x8 pixels) = **16 tiles**. Standard
  NDS 2D tile addressing (`tile_index = tile_row * tiles_per_row +
  tile_col`) with 16 tiles/row reproduces the observed 512-byte row stride
  exactly: **image width 128 px, 4bpp**.
- 131072 bytes / 512 bytes-per-tile-row = 256 tile-rows = **2048 px of
  vertical canvas**, of which real content only occupies a leading
  fraction for the smaller samples (144 tile-rows / 1152 px for species 1,
  32 tile-rows / 256 px for species 25) -- consistent with a fixed
  worst-case canvas (sized for the largest sprite, e.g. Wailord) with
  unused rows left as filler for everything else.
- Nibble-value histogram inside the real-content region for species 25:
  values `0x0` and `0x8` (the two nibbles of the filler pattern) still
  dominate at 28.7% and 19.6% respectively (48% combined), with the
  remaining 14 palette indices spread across the rest -- i.e. the filler
  pattern doubles as the actual background/transparent index inside real
  sprite data too, not just in the reserved slot-0 placeholder. This is
  corroborating evidence for the 4bpp/width-128 read: an 8bpp reading of
  the same bytes has no comparably dominant single background value (top
  two byte values cover only 34%, spread over many more distinct bytes).
- **Not independently confirmed**: an average-run-length scan across
  candidate widths (32 through 512 px, 4bpp/8bpp, tiled/linear) failed to
  discriminate between them -- all candidates score close to the same low
  average run (~1.28 nibbles for 4bpp, ~1.0 for 8bpp), which is more
  consistent with heavily dithered pixel art (a known Gen4/5 sprite
  shading technique) defeating that heuristic than with the width choice
  being wrong, but this was not cross-checked against a recovered
  palette (none exists in this archive) or a known-good reference image.
  **No palette exists anywhere in `a/1/3/4`**, so true pixel *color*
  cannot be reconstructed from this archive alone.
- 128 x 2048 at 4bpp is also a plausible **multi-frame animation strip**
  (16 stacked 128x128 frames), and the two small samples using exactly
  32 tile-rows (2 frames' worth) is consistent with a simple 2-frame idle
  "breathing" animation -- plausible given Black/White's known battle
  sprite animation style, but not verified by locating actual frame
  boundaries or an animation-timing table.

### PNG decoder (`tools/assets/battle_sprite.py`)

Renders index-as-grayscale (4bpp index * 17, filling 0-255) since no
palette is recoverable from this archive. Usage:

```
python tools/assets/battle_sprite.py 25 --trim
python tools/assets/battle_sprite.py --all --trim
```

(As of the fourth lane pass, add `--palette-archive extract/data/a/0/0/4`
to either invocation for a real-color RGB PNG instead of grayscale, `--shiny`
for the shiny-slot palette, and `--all --sanity` to print the species
1/25/150 dominant-color sanity check instead of writing files. See "Battle
sprite colors" below.)

`--trim` crops the output to the last non-filler 512-byte row so small
sprites don't ship as mostly-blank 128x2048 PNGs. All **670/670**
sub-files decoded without error in `--all` mode, written to
`build/assets/battle/NNNN.png` (gitignored). Not independently visually
confirmed by this pass (no image viewer available here) -- the user
should open a few PNGs (e.g. `0025.png`, `0150.png`) to sanity-check that
recognisable silhouettes appear; per-row nonzero-pixel-count profiles
computed ad hoc during this investigation showed smooth, non-random
variation over height for every sample checked, consistent with real
shapes rather than garbage.

### LZ11 encoder (`tools/assets/lz11.py`) and round-trip result

Written the same way `tools/blz.py`'s BLZ encoder was recovered (see
"Matching BLZ compression" in `docs/NOTES.md`): decode an original
compressed sub-file to its token stream, diff a candidate encoder's
choices against it token-by-token, and adjust policy at the first
divergence. Unlike BLZ (backward, in-place, with a verbatim-prefix safety
margin to reconstruct), LZ11 is a plain forward LZ77 variant encoding
every byte, so the recovered policy is just the match search:

- **greedy**, no lazy matching -- confirmed sufficient (no divergence
  attributable to lazy evaluation on any of the 670 sub-files).
- **matches may self-overlap** (`length` may exceed `displacement`, the
  classic LZ77 run trick) -- required; species-0's entire 131072-byte
  filler payload compresses to 15 bytes using exactly this.
- **displacement 1 is never used**, even where it is the only way to
  encode a short repeated-byte run cheaper than literals. First
  divergence: sub-file 25, plaintext offset 194, a run of four identical
  bytes left as four literals despite a legal length-3/disp-1 match being
  available.
- **longest match wins; ties broken by *farthest* displacement** -- the
  opposite of BLZ's nearest-wins rule. First divergence: sub-file 25,
  plaintext offset ~65810, where matches of equal maximal length exist at
  displacement 2 and displacement 0x1000 (the search window maximum) and
  the original encodes the 0x1000 one.
- Field limits match the existing decoder in `narc.py`: match length
  3..0x10110, displacement 1..0x1000 (with 1 excluded per above), and the
  shortest of the three token forms that can express a given length is
  always used (not an independent choice -- the length ranges are
  disjoint).

**Result: 670/670 sub-files round-trip byte-for-byte**
(`compress(decompress(x)) == x` for every sub-file in `a/1/3/4`, header
bytes and all), confirmed by an ad hoc harness (not committed as a script
per this lane's write-set; re-run it by decompressing every sub-file with
`narc.py`'s `decompress_lz11` and re-encoding with `lz11.compress`). Full
archive round trip took about 160 s single-threaded CPython 3.11 (a
hash-chain match finder over up to 131072 bytes per sub-file, 670
sub-files).

### What remains (as of the third lane pass)

- The battle-sprite pixel format's exact frame/animation layout (frame
  count, frame boundaries within the 2048px canvas, whether the "2 frames"
  guess for small sprites is right) is not resolved -- needs either a
  recovered palette (to render real colors and visually confirm frame
  cuts) or a cross-reference to whatever code loads this archive and any
  accompanying OAM/cell table.
- No palette source for these sprites has been located in `a/1/3/4`
  itself; it likely lives in a companion archive or is supplied by the
  loader from a fixed table, neither investigated here.
- `tools/assets/lz11.py`'s encoder policy is fully recovered and verified
  (670/670), but only against this one archive; it has not been re-run
  against the other ~10,100 LZ11 sub-files elsewhere in the ROM to check
  the policy generalises (expected to, since nothing here is specific to
  battle sprites, but not confirmed).

**Update (fourth lane pass, see "Battle sprite colors" below): the palette
gap and the LZ11-generalisation gap are now closed.** The frame/animation
layout gap is still open, and in fact got more interesting: coloring the
sprites with a confirmed-correct palette shows the current pixel unpacking
does *not* produce a clean silhouette (see "Known issue: pixel layout"
below) -- the width/tiling recovery from the third pass needs another look.

## Battle sprite colors (`a/0/0/4` palette archive)

Fourth asset lane pass, scoped to the single open item that mattered most
for making the 670 `a/1/3/4` battle sprites visually useful: finding their
color palettes. New capability: `tools/assets/battle_sprite.py` now takes
`--palette-archive`/`--palette-index`/`--shiny` and can render real RGB PNGs
instead of index-as-grayscale; the LZ11 encoder in `tools/assets/lz11.py`
was also cross-checked against a second archive.

### Palette archive: not where the obvious guess pointed

The obvious first guess -- an archive adjacent to `a/1/3/4` in the `a/1/3/x`
or `a/1/4/x` numbering, sized for ~670 or ~1340 small (32-byte-ish) RLCN/
NCLR or raw-BGR555 sub-files -- **does not exist**. A full scan of all 237
NARCs (every sub-file's first-4-bytes magic, every LZ11-declared
decompressed size) found:

- No archive anywhere in the ROM has an RLCN (NCLR) sub-file count between
  600 and 700 (or 1300 and 1400). The closest by RLCN count are `a/0/0/4`
  and `a/0/5/2` (1457 RLCN sub-files each, out of 14285 total) and `a/0/2/5`
  (552 of 1005).
- No archive has a cluster of sub-files whose raw size, or LZ11-declared
  decompressed size, is exactly 32 bytes (the size of a 16-color BGR555
  table) in the 500-1400 total-sub-file range.

So the palette isn't a dedicated per-species palette-only archive at all.
It turned out to live inside **`a/0/0/4`** (and, identically, its sibling
`a/0/5/2`) -- the pair of 14285-sub-file archives this document's earlier
pass guessed were "Pokemon overworld/menu sprites". They still might be
that, but they are *also* usable directly as the battle-sprite palette
source, because the color data is species-indexed and correct (see the
sanity check below) regardless of what the rest of that archive's content
turns out to be.

**Structure.** `a/0/0/4` sub-files repeat in a clean, fixed-size **20-entry
block per species/form index**: a fixed leading pattern of tagged/typed
sub-resources (`RECN`/NCER, `RCMN`, `RAMN`, several LZ11-compressed blobs)
followed by **two RLCN (NCLR) palettes at local offsets 18 and 19** --
confirmed by walking every RLCN sub-file index in the archive: 1457 hits,
and the gap between consecutive hits is exactly 1 (within a pair) or 19
(between pairs) for all but one of the 1456 gaps. So for species/form index
`N`:

```
normal palette index = 20*N + 18
shiny  palette index = 20*N + 19
```

(`tools/assets/battle_sprite.py`'s `PALETTE_STRIDE`/`PALETTE_NORMAL_OFFSET`/
`PALETTE_SHINY_OFFSET`, and `palette_index_for()`.)

Each RLCN sub-file is a standard Nitro NCLR resource (generic NDS graphics
container format, not project-specific): 16-byte common file header, one
`TTLP` block whose body is `bitdepth(u16), padding(u16), reserved(u32),
data_size(u32), color_offset(u32)` followed by the BGR555 color table at
`color_offset`. `parse_nclr()` in `battle_sprite.py` decodes this generically
(any RLCN sub-file, not just these ones).

14285 / 20 = 714.25, i.e. this archive has room for ~714 species/form
blocks, more than `a/1/3/4`'s 670 -- consistent with `a/0/0/4` carrying a
wider set of overworld/menu-relevant forms than just the battle-sprite set,
with the base ~649 species most likely still in dex order at the front
(see sanity check below) and the extra ~65 blocks' species/form order
relative to `a/1/3/4`'s tail (indices 649-669, the "forms and genders"
slots) **not verified** -- a real gap, noted below.

### Sanity check: species 1 / 25 / 150

`python tools/assets/battle_sprite.py --all --sanity` decodes species 1
(Bulbasaur), 25 (Pikachu) and 150 (Mewtwo) from `a/1/3/4`, loads their
`a/0/0/4` palette via the formula above, and prints the dominant non-
background palette colors (indices 0 and 8 excluded as background/filler,
per the third pass's finding that those two nibble values double as the
in-sprite background index):

| species | top colors (RGB, % of foreground pixels) |
|---|---|
| 1 Bulbasaur | white 44%, teal (57,148,148) 32%, green (131,238,197) 24% |
| 25 Pikachu | red (197,32,24) 18%, gold (246,189,32) 12%, gray 11%, red-brown (230,90,65) 10%, orange (222,148,0) 7% |
| 150 Mewtwo | violet (180,74,238) 14%, violet (148,65,189) 13%, blue (0,0,246) 12%, violet (106,49,156) 11%, black 7% |

Read at face value the Pikachu list looks red-led, not yellow-led -- but the
yellow/gold/orange family (indices 2-5 of its palette: bright yellow,
yellow, gold, orange) sums to a plurality once you add the entries outside
the top-5 cutoff, and the reds are Pikachu's cheek/cheek-shading colors,
present but a minority. Bulbasaur's white+teal+green is plausibly its
light-belly/dark-skin/highlight shading. **The strongest confirmation is
Mewtwo's shiny palette**: `palette_index_for(150, shiny=True)` (index 3019)
decodes to the *same* first 8 colors as the normal palette (whites/grays,
including the identical background/outline entries) but swaps Mewtwo's
signature purple family -- (180,74,238), (148,65,189), (106,49,156) -- for
a **lime-green** family -- (164,230,90), (123,205,49), (82,156,0),
(24,98,0) -- which is exactly Mewtwo's well-known shiny recolor (purple ->
green). This is strong, specific, hard-to-fake evidence that the
`species*20 + 18/19` indexing is correctly aligned to species identity, at
least for these three low-to-mid dex numbers.

`python tools/assets/battle_sprite.py --all --trim --palette-archive
extract/data/a/0/0/4 --out build/assets/battle_color` colored **all 670/670**
sub-files without error (gitignored output, not committed, per this lane's
write set).

### Known issue: pixel layout doesn't yet produce a clean silhouette

Rendering the color PNGs surfaced a problem the third pass's grayscale
renders **also have**, not something the palette work introduced: opening
`build/assets/battle_color/0025.png` (Pikachu) shows a noisy, vertically-
banded pattern, not a recognisable silhouette, and the pre-existing
grayscale render (`battle_sprite.py 25 --trim` with no palette) has the
identical banding when viewed side by side. The third pass's "smooth,
non-random row-profile" self-check was evidently not sufficient to catch
this -- a column-noise pattern can still have a smooth per-row *count*
profile. **The `CANVAS_WIDTH_PX = 128` / 16-tiles-per-row addressing
recovered in the third pass needs re-examination**; the third pass's own
notes already flagged the width heuristic as "not independently confirmed"
and this is the confirmation that it likely needs revisiting. This is a
pixel-layout problem, separate from and downstream of the palette work in
this pass -- the palette *identification* (which 16 colors belong to which
species) is solid on the evidence above; the *unpacking* of which pixel
gets which of those 16 indices is not yet right.

### LZ11 cross-check on a second archive

To check whether `tools/assets/lz11.py`'s encoder policy (recovered only
against `a/1/3/4` in the third pass) generalises ROM-wide, 200 LZ11
sub-files of **`a/0/7/2`** (760 sub-files, `pokemon/trainer sprites (guess)`
category, unrelated content to battle sprites) were decompressed with
`narc.decompress_lz11` and re-compressed with `lz11.compress`:

**Result: 200/200 round-trip byte-for-byte** (`compress(decompress(x)) ==
x` for every one of the first 200 LZ11-tagged sub-files in `a/0/7/2`, in
about 38 s). This is a second, independent archive with no relationship to
`a/1/3/4` beyond "also uses LZ11", so this is good evidence the encoder
policy recovered in the third pass (greedy, self-overlapping matches,
displacement 1 excluded, farthest-match tie-break) is a ROM-wide constant
of Game Freak's LZ11 encoder, not something specific to the battle-sprite
archive.

### What remains after this pass

- **Pixel layout is still wrong** (see above) -- the highest-priority
  follow-up. A future pass should re-derive the tile width/addressing from
  scratch, this time checking the *pixel content itself* (does a candidate
  layout produce contiguous, connected regions of a small number of
  palette indices, the signature of real sprite art) rather than a row-
  profile heuristic.
- `a/0/0/4` / `a/0/5/2`'s block structure was only densely checked for the
  first ~30 blocks (species 0-1) and spot-checked at 3 more (species 25,
  150); the ~65 "extra" blocks beyond the ~649-species range (14285/20 =
  714.25 possible blocks vs. `a/1/3/4`'s 670 sub-files) have **not** been
  matched up against `a/1/3/4`'s own tail indices (649-669, the forms/
  genders slots) -- the normal-species mapping (`index = 20*N + 18`) is
  verified by color content up to species 150; the form-slot mapping past
  649 is an unverified extrapolation of the same formula.
- Neither `a/0/0/4` nor `a/0/5/2`'s *non*-palette sub-resources (the
  `RECN`/`RCMN`/`RAMN`/LZ11-blob entries that make up the other 18 of each
  20-entry block) were investigated in this pass; whether these archives
  really are "overworld/menu sprites" (the third pass's guess) or something
  else entirely (e.g. a general per-species resource table that happens to
  also hold the battle palette) is still open.
