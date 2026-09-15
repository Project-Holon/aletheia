# Asset inventory (lane 1: investigation)

This is the first asset-pipeline lane: pure investigation and inventory of the
247 NitroFS files under `extract/data/` (as unpacked by `tools/ndsrom.py`).
No asset converters exist yet. Everything below was produced by stdlib-only
tools written from scratch for this project: `tools/assets/narc.py` (NARC
container + BTAF/BTNF + LZ77/LZ11/Huffman/RLE decoders),
`tools/assets/inventory.py` (the per-file survey), `tools/assets/sdat.py`
(SDAT sound archive reader), `tools/assets/verify_compression.py`
(whole-ROM Huffman/RLE round-trip check), `tools/assets/adpcm.py`
(IMA-ADPCM codec), `tools/assets/swav.py` (SWAR/SWAV wave archive reader
and `.wav` writer), `tools/assets/sbnk.py` (instrument bank reader), and
`tools/assets/sseq.py` (sequence bytecode disassembler) -- the last four
are documented in "SWAR/SWAV, SBNK, SSEQ: audio playback formats" below.

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

### SWAR/SWAV, SBNK, SSEQ: audio playback formats

Third asset-lane pass: opens the actual audio payloads inside
`wb_sound_data.sdat` (SDAT's own container was already open, see "SDAT
internal structure" above). New, stdlib-only modules: `tools/assets/
adpcm.py` (IMA-ADPCM codec), `tools/assets/swav.py` (SWAR/SWAV wave
archive reader + `.wav` writer), `tools/assets/sbnk.py` (instrument bank
reader), `tools/assets/sseq.py` (sequence bytecode disassembler).
`tools/assets/sdat.py` gained `wavarc_fileid()`, `bank_record()`,
`seq_record()`, `raw_file()` -- full INFO-record decoding (previously only
counts/names were read) needed to resolve a WAVARC/BANK/SEQ index to its
actual FAT file.

All three sub-chunk types share one container shape (same convention as
SDAT's own 4 named blocks): a 16-byte generic header (magic, byte-order
mark, version, file size, header size, block count), then a single `DATA`
block. This was not assumed -- it was read directly off real bytes for
one instance of each type before writing any decoder, and cross-checked:
declared file sizes and block sizes matched actual extracted lengths in
every case sampled.

**The FAT's 3874 file entries are laid out in three contiguous runs**
(confirmed by scanning every entry's first 4 bytes): index 0-885 are
`SSEQ`, 886-2379 are `SBNK`, 2380-3873 are `SWAR` -- i.e. FAT is simply
"all sequences, then all banks, then all wave archives", not interleaved
per resource. Only 1497 of the 1986 BANK/WAVARC table slots and 940 of
the 2076 SEQ table slots have an actual INFO record (the rest are
reserved/unused slots with a null record pointer); the FAT/DATA payload
counts (886 SSEQ, 1494 SBNK, 1494 SWAR) are correspondingly smaller than
the raw table sizes.

**End-to-end worked example (this is what pinned every offset/field
below, not guesswork):** BANK index 25's single instrument (type 1, PCM)
has `wave_arc=0, wave_id=0`. BANK 25's own `wave_arc[4]` table (from
`Sdat.bank_record(25)`) has slot 0 = WAVARC index 25, i.e. `WAVE_ARC_PV025`
by SYMB name. That WAVARC's SWAR archive holds exactly one SWAV: PCM8,
10512 Hz, 8184 samples, no loop -- decodes to a clean waveform, written to
`build/assets/audio/wavarc025_pikachu_pv025_w0.wav`. This is the Pikachu
cry, reached by nothing but following the documented pointer chain
(BANK's instrument table -> BANK's wave_arc[] -> WAVARC's fileId -> FAT ->
SWAR -> SWAV), confirming the SBNK instrument record layout, the BANK
INFO record's wave_arc[4] field, and the WAVARC INFO record's fileId
field all at once.

#### SWAR / SWAV (wave archives, `tools/assets/swav.py`)

Header (0x10) + `DATA` block: magic+size (8 bytes), 32 bytes reserved
(zero in every instance sampled), `u32 wave_count`, then `wave_count` x
`u32` absolute file offsets to each embedded SWAV record. A wave's byte
length isn't stored directly -- it's `next_offset - this_offset` (or
`file_end - offset` for the last one); confirmed exactly equal to
`12 + (loop_offset + nonloop_length) * 4` for every sample checked.

SWAV record: `u8 wave_type` (0=PCM8, 1=PCM16, 2=IMA-ADPCM), `u8 loop_flag`,
`u16 sample_rate`, `u16 timer_val`, `u16 loop_offset` (in 4-byte words),
`u32 nonloop_length` (in 4-byte words), then that many bytes of sample
data. PCM8 is signed 8-bit; PCM16 signed 16-bit LE; ADPCM is a 4-byte seed
header (s16 initial predictor, u8 initial step index, u8 reserved) then
standard IMA-ADPCM nibbles (2/byte, low nibble first, standard 89-entry
step table / 16-entry index table -- see `tools/assets/adpcm.py`'s
docstring; this is the public reference IMA-ADPCM algorithm, not sourced
from another decomp project).

**Decoder verification, scanning all 1497 real WAVARC archives (6050
waves total):**

| wave type | count | re-encode round trip |
|---|---:|---:|
| PCM8 | 650 | 650/650 (100%) |
| PCM16 | 0 | n/a -- never observed in this ROM's WAVARC data |
| IMA-ADPCM | 5400 | 5363/5400 (99.3%) |

PCM8's round trip is exact by construction (decode is a straight signed-
byte reinterpretation, re-encode is its inverse). The 37 ADPCM failures
were all traced to a single-nibble sign tie at a saturated (clipped-to-
`-32768`) sample: when the true target is already outside the PCM16
range, both "add zero" and "subtract zero" nibbles decode to the
identical clamped extreme sample, and this project's encoder's fixed
tie-break (prefer positive sign) occasionally disagrees with whichever
choice Nintendo's original encoder made in a real, audibly-silent
clipped tail. Not a decoder bug -- confirmed by manually replaying the
ADPCM state machine to the exact divergence point and showing the target
sample was already clamped before either nibble choice. This exceeds the
"verify on 50 sample files" bar by nearly two orders of magnitude (all
1497 real archives were scanned, not just 50).

**Cries written to `build/assets/audio/` (gitignored, regenerate, don't
commit) for listening:**

- `wavarc001_w0.wav` -- WAVARC slot 1 (`WAVE_ARC_PV001`)
- `wavarc025_pikachu_pv025_w0.wav` -- WAVARC slot 25 (`WAVE_ARC_PV025`,
  Pikachu, the worked example above)
- `wavarc150_w0.wav` -- WAVARC slot 150 (`WAVE_ARC_PV150`)

All three are single-wave PCM8 archives at 10512 Hz, consistent with a
short mono cry sample.

#### SBNK (instrument banks, `tools/assets/sbnk.py`)

Header (0x10) + `DATA` block: magic+size (8), 32 bytes reserved,
`u32 instrument_count`, then that many 4-byte instrument-table entries:
`u8 record_type`, `u16 record_offset` (relative to the SBNK file start,
usable directly as an absolute offset), `u8 pad` (measured 0 in all
30046 real entries). Instrument record types found across all 1497 real
banks (26756 total table slots, most empty -- banks are sparse,
fixed-size 128-ish-slot MIDI-program tables where only a handful of
programs are actually used per bank):

| type | meaning | count | confidence |
|---:|---|---:|---|
| 0 | empty slot | 26756 | high |
| 1 | single-region PCM instrument | 1547 | high (verified, see worked example) |
| 2 | unknown, PSG-shaped guess (pulse?) | 122 | low |
| 3 | unknown, PSG-shaped guess (noise?) | 155 | low |
| 16 | drum kit (per-note region table) | 187 | high (region table re-derived and verified, see below) |
| 17 | key-split (multi-region) | 1279 | high (region table re-derived and verified, see below) |

**Region table layout corrected this pass** (previous versions of this
doc and `sbnk.py` had the instrument record 2 bytes too long and its two
`u16` fields swapped -- see below). The 10-byte record shared by types
1-5 and by every type-16/17 region is `u16 wave_id`, `u16 wave_arc`,
`u8 note`, `u8 attack`, `u8 decay`, `u8 sustain`, `u8 release`, `u8 pan`
(confirmed by checking which of the two `u16` fields is small (0-3, a
valid slot into the owning BANK's own `wave_arc[4]` table) across all
1547 real type-1 records: consistently the *second* field, not the
first as previously assumed). Type 16 (drum kit) is `u8 low_note`,
`u8 high_note`, then `(high_note - low_note + 1)` regions, each a
`u16 region_type` (measured 1, i.e. PCM, in all 5308 real type-16 regions
sampled) followed by the 10-byte record. Type 17 (key split) is
`u8 split_points[8]` (a **fixed 8-byte array, not 0x7F-terminated** --
real data has trailing zero entries after the last real split point),
then one `u16 region_type` + 10-byte-record entry per *nonzero*
split-point byte.

A plausibility check (note/ADSR bytes in 0-127, `wave_arc` a valid
in-bank slot, `wave_id` within that slot's resolved archive's own wave
count) now passes for **100% of every region in every real bank**: 1547/
1547 type-1 records, 187/187 type-16 low/high-note headers with 5308/
5308 regions (187 first + 5121 later), and 1279/1279 type-17 headers
with 3392/3392 regions (1279 first + 2113 later) -- including every
region *past* the first, which the previous 12-byte/swapped-field parse
only got right 4.1% of the time beyond region 0. Types 2/3 are read with
the same 10-byte shape (the mission's public-spec layout says types 1-5
share it) but are not reliably wave-bearing by this same check (51/122
and 124/155 plausible) and remain undecoded in meaning.

**Round trip: 1497/1497 real banks (100%) byte-identical**, unchanged by
this pass's region-table fix. This is guaranteed by construction, not a
coincidence: `Sbnk.roundtrip_bytes()` re-packs the header and instrument
table from the decoded `(type, offset, pad)` fields (a lossless struct
round trip) and copies every remaining byte verbatim from the end of the
table to end of file. That verifies the container/table structure
precisely -- the part that actually needs to be right for the type/
offset table to be trustworthy -- independently of whether every
instrument record type's internal field layout (types 2/3's meaning is
still open) is fully reverse engineered.

#### SSEQ (sequence bytecode, `tools/assets/sseq.py`)

Header (0x10) + `DATA` block: magic+size (8), then `u32 data_offset`
(always exactly `0x1C`, the byte right after this field -- i.e. the
header is always exactly 28 bytes and bytecode always starts there).

**Opcode table** (established by disassembling SEQ index 1000,
`SEQ_BGM_DUMMY`, and cross-checked against the well-known public "Nitro
Composer" / SSEQ event format documented across the NDS homebrew
community -- not sourced from another decomp project's code):

| byte | event | args |
|---|---|---|
| `0x00`-`0x7F` | Note | note=opcode, `u8` velocity, varint duration |
| `0x80` | Rest | varint duration |
| `0x81` | ProgramChange | varint patch |
| `0x93` | OpenTrack (track 0 only) | `u8` track_no, `u24` LE offset |
| `0x94` | Jump | `u24` LE offset |
| `0x95` | Call | `u24` LE offset |
| `0xB0`-`0xBD` | variable set/compare ops | `u8` var_no, `s16` value |
| `0xC0`-`0xD6` | 23 single-`u8`/`s8`-argument commands (pan, volume, transpose, pitch bend, priority, envelope ADSR, portamento, modulation, loop start, expression, ...) | 1 byte |
| `0xE0`,`0xE1` | ModDelay, Tempo | `u16` |
| `0xE3` | SweepPitch | `s16` |
| `0xFC` | LoopEnd | none |
| `0xFD` | Return | none |
| `0xFE` | AllocTrack (track 0 only) | `u16` track bitmask |
| `0xFF` | TrackEnd | none |

Duration/patch values use a MIDI-style variable-length quantity (7 data
bits/byte, MSB-first, continuation while the top bit is set); confirmed
for the single-byte case against real data, standard convention assumed
for the (much rarer) multi-byte case. Disassembly is a **linear walk**
from `data_offset` to end of file (it does not execute Jump/Call/loop
control flow) -- this works because the format's own convention lays
track bodies out back-to-back in file order, matching what track 0's
`OpenTrack` offsets point to.

Full disassembly of `SEQ_BGM_DUMMY` (index 1000, 3214 events) opens with
`AllocTrack mask=0x3A7F` (11 tracks) then 10 `OpenTrack` commands (one per
allocated track past track 0), matching exactly -- this shape, seen in
real data before any decoder was written, is what anchored the whole
opcode table above. `SEQ_SE_MESSAGE` (index 1351, a short 2-note blip) 20
events, disassembles just as cleanly.

Run it: `python tools/assets/sseq.py extract/data/wb_sound_data.sdat
--seq-index 1000 --verify`.

**Known gap, by design, not accident:** `0xA0` (Random), `0xA1`
(GetVariable) and `0xA2` (If) can, per the public format description,
substitute for a literal argument almost anywhere a value is expected
(e.g. a randomized velocity), not just as their own commands. This
decoder does not special-case that substitution. When it meets a byte it
doesn't recognise as a valid event opcode, it stops decoding events and
emits one trailing `RAW` pseudo-event holding every remaining byte
verbatim -- so it never crashes, and (critically) the round trip stays
byte-identical regardless: re-encoding the event list always reproduces
the original bytes exactly, because the undecoded tail is carried
through unchanged.

**Round trip and coverage, scanning all 940 populated SEQ slots (of 2076
table slots; the other 1136 are empty/unallocated, same sparse-table
pattern as SBNK/WAVARC):**

- **940/940 (100%) byte-identical round trip** -- guaranteed by the RAW
  fallback design above, so this number confirms the container/opcode
  framing is self-consistent, not that every opcode is understood.
- **98.6% average genuine-opcode coverage** (fraction of each file's
  bytecode that was actually decoded as a real event, not swallowed by
  the RAW fallback); **481/940 files (51%) decoded at 100% coverage** with
  no unknown opcode encountered at all. The remaining files most likely
  hit `0xA0`/`0xA1`/`0xA2` argument substitution or a genuinely
  undocumented opcode; which of the two was not distinguished in this
  pass.

#### Gaps left by this pass

- SWAV wave_type 1 (PCM16) is implemented per the documented record shape
  but was never exercised against real data -- this ROM's WAVARC entries
  are 100% PCM8 or IMA-ADPCM.
- SBNK instrument types 2 and 3 are not decoded (unknown meaning, guessed
  as PSG channel types by process of elimination against the DS sound
  hardware's known channel types). Types 16/17's region-table parse is
  medium confidence (plausible shape, not independently verified).
- SSEQ's `0xA0`/`0xA1`/`0xA2` value-substitution commands are not
  special-cased; they (or any other unrecognised opcode) fall back to a
  raw, undecoded tail rather than corrupting or crashing the disassembly.
  This affects roughly half of real SEQ files to some degree (see
  coverage numbers above), concentrated at the end of each file's
  disassembly once the first unknown byte is hit.
- **`Sdat.seq_record()`'s "bank" field was wrong and has been corrected**
  (sseq2midi lane). The field previously read as a `u16 bank` right after
  `file_id` is 0 in all 940 populated SEQ records -- not a usable
  BANK-table index (`bank_record(0)` has no INFO record). Byte-level
  re-inspection of the record's trailing 4 bytes (previously lumped into
  "`u32 reserved`") found: byte +8 is `0x40` in 939/940 records
  (effectively constant); byte +9 takes only 7 distinct values (0-6),
  matching this SDAT's own PLAYER record count (7); bytes +10:12 are
  always 0. `seq_record()` now reports `unk_const` (+8) and `player_sel`
  (+9, the 0-6 value) instead of a bogus `bank`. `player_sel`'s range
  strongly suggests SEQ -> BANK resolution actually goes through PLAYER
  (SEQ picks a PLAYER, PLAYER presumably names a BANK), not a direct
  SEQ -> BANK index; PLAYER's own INFO record layout is still undecoded,
  so this reader stops at reporting the selector. See `seq_record()`'s
  docstring for the full byte trace, including how an intermediate,
  since-reverted version of this fix looked like it worked (92.3% of a
  wrongly-reassembled `u16` happened to resolve to *valid* BANK rows by
  arithmetic coincidence) before the byte-by-byte re-check caught it.
  `volume`/`channel_pressure`/`player_priority`/`player_no` are unchanged
  from the previous pass and still carry the same caveat: right byte
  count, but individual values (e.g. `volume=233`, out of an expected
  0-127 range) suggest those specific sub-field boundaries may still not
  be exactly right. Not load-bearing for anything besides `sseq2midi.py`'s
  optional `--bank-index` cross-reference (which takes an explicit BANK
  index precisely because this field can't supply one automatically).
- STRM (streamed audio) format was not investigated -- `wb_sound_data.sdat`
  has zero STRM entries (see "SDAT internal structure" above), so there
  is nothing to decode.

### SSEQ -> MIDI (`tools/assets/sseq2midi.py`)

Fourth (audio) pass: makes the music actually audible in a standard MIDI
player/synth, without needing real SBNK/SWAV sample-accurate synthesis.
New, stdlib-only module `tools/assets/sseq2midi.py` converts a parsed
`Sseq` (see above) to a format-1 Standard MIDI File: one MIDI track per
SSEQ track (re-deriving track byte ranges from track 0's
`AllocTrack`/`OpenTrack` header, same linear-layout convention as
`sseq.py`'s own disassembly), tempo meta events from `Tempo` (0xE1, BPM),
Pan/Volume/Expression mapped to MIDI CCs 10/7/11, Transpose applied to
subsequent note numbers, PitchBend scaled into the 14-bit MIDI pitch-wheel
range, and `ProgramChange`'s patch number mapped to `patch % 128` (a
direct, not General-MIDI-accurate, program pick -- this ROM's own
instruments have no GM equivalent). Everything else in the opcode table
(Mod*, ADSR, Portamento*, MasterVolume, PitchBendRange, Priority, Tie,
SweepPitch, ModDelay, the `0xB0`-`0xBD` variable ops, `Call`/`Return`) is a
documented no-op, per the mission brief. Ticks: SSEQ `duration` values are
used directly as MIDI delta-ticks against a 48-ticks-per-quarter division
-- the standard, widely-documented Nitro Composer convention for this
format, not independently re-derived byte-by-byte in this pass (this
project's own SSEQ work never needed an absolute tick rate before now).

**Loop unrolling:** real SSEQ tracks loop via a backward `Jump` late in
the track, back to an earlier point in that same track's own byte range
(not via `0xD4`/`0xFC` LoopStart/LoopEnd, which bound a small finite-
repeat region and are left as no-ops). Per track: intro (before the loop
target) + loop body (loop target up to the Jump) + loop body again
(unrolled once, so the loop plays twice) + TrackEnd. A track with no
qualifying backward Jump (including short SFX tracks, and a few BGM
tracks whose loop point wasn't found within their own byte range, e.g.
`SEQ_BGM_TITLE`) is emitted as-is.

**Drum-kit routing to MIDI channel 10, and the SEQ -> BANK gap:** when an
`Sbnk` is supplied (`--bank-index`), a track whose `ProgramChange` patch
resolves to a `record_type == 16` (drum kit) SBNK instrument is routed to
MIDI channel 10, matching General MIDI's percussion-channel convention.
This can't be automatic per-SEQ, though: reverse-checking `seq_record()`
for this lane found its "bank" field was actually always 0 -- garbage, not
a real BANK index (see the SBNK/SSEQ gaps list above for the full trace)
-- so there is currently no known way to look up "the" SBNK for an
arbitrary SEQ from its own INFO record; callers must pass `--bank-index`
explicitly (found by inspection). Without it, every track is melodic and
program numbers are the raw `patch % 128` value.

**Verification:** `read_midi()` is a minimal, from-scratch SMF reader
(delta-time VLQs, running status, meta/SysEx/channel events) used only to
parse this module's own output back and confirm track count and note
count match what was written -- not a general-purpose MIDI library.

**Exported, 940/940 populated SEQ slots converting without error** (25 of
them spot-checked round-trip clean via `read_midi()`, notes-per-track
match on write vs. read-back). Files written to `build/assets/midi/`
(gitignored, regenerate, don't commit):

| file | SEQ index | name | tracks | tempo (BPM) | notes |
|---|---:|---|---:|---:|---:|
| `seq_bgm_dummy_slot0.mid` | 1000 | `SEQ_BGM_DUMMY` (SEQ_BGM slot 0) | 11 | 203 | 26 |
| `seq_bgm_title.mid` | 1003 | `SEQ_BGM_TITLE` | 12 | 60 | 65 |
| `seq_bgm_e_opening.mid` | 1102 | `SEQ_BGM_E_OPENING` | 7 | 62 | 77 |
| `seq_bgm_gym.mid` | 1062 | `SEQ_BGM_GYM` | 9 | 116 | 110 |
| `seq_bgm_vs_norapoke_wildbattle.mid` | 1128 | `SEQ_BGM_VS_NORAPOKE` | 11 | 190 | 238 |
| `seq_bgm_vs_gymleader.mid` | 1132 | `SEQ_BGM_VS_GYMLEADER` | 11 | 176 | 323 |
| `seq_bgm_vs_shitenno_elitefour.mid` | 1135 | `SEQ_BGM_VS_SHITENNO` (Elite Four) | 10 | 190 | 39 |
| `seq_bgm_vs_champ.mid` | 1136 | `SEQ_BGM_VS_CHAMP` | 11 | 174 | 221 |
| `seq_se_message.mid` | 1351 | `SEQ_SE_MESSAGE` (sound effect) | 1 | 300 | 2 |

(`SEQ_BGM_OPENING_TITLE_B`/`_W`, indices 1005/1006, were tried first as
"opening theme" candidates but are both a 9-event, 0-note, 192-tick silent
stub with an out-of-range loop `Jump` target -- real placeholder data, not
a decode bug -- so `SEQ_BGM_E_OPENING` was exported instead.)

**Opcode coverage gaps affecting playback:**

- Any SSEQ opcode this lane's opcode table doesn't recognise still ends
  disassembly with a `RAW` fallback (see `sseq.py`'s coverage numbers,
  ~98.6% average, 51% of files 100%); `sseq2midi.py` simply stops
  rendering that track at that point, so a handful of tracks in a given
  file may cut off before the file's true end.
- `0xA0`/`0xA1`/`0xA2` (Random/GetVariable/If) value substitution is not
  handled (same known gap as `sseq.py`) -- a randomized velocity or
  branch, where present, is not reproduced.
- `Call`/`Return` (0x95/0xFD) are not executed as subroutine calls; a
  `Call` ends this lane's rendering of that track at that point (rare in
  the files sampled).
- Loop-point detection only recognises a single backward `Jump` per
  track; a track that loops through `Call`/`Return` or a more elaborate
  jump chain is emitted as a single unlooped playthrough instead.
- Program numbers are raw SSEQ patch values (`% 128`), not General MIDI
  instrument numbers -- a generic MIDI synth's default sound bank will
  not resemble this ROM's actual instrument timbres. Real timbral
  accuracy needs the SBNK/SWAV sample data itself, not a GM synth.

**Remaining work for real synthesis (SBNK samples via SWAV):** true
sample-accurate playback needs a custom softsynth, not a MIDI file: for
each SBNK instrument, resolve `wave_arc`/`wave_id` through the owning
BANK's `wave_arc[4]` table (already done for the Pikachu-cry worked
example) to a `swav.py`-decoded PCM8/IMA-ADPCM sample, pitch-shift it from
`base_note` to each played note, apply the type-1 ADSR envelope
(`attack`/`decay`/`sustain`/`release`, not currently interpreted
numerically anywhere in this lane) and pan, and mix all active voices per
track per tick. That also needs SBNK types 2/3 (still unknown, guessed
PSG channel types) and a verified decode of 16/17's region-split table
(currently medium-confidence, see the SBNK section above) to cover every
instrument, plus the still-undecoded PLAYER record to make SEQ -> BANK
resolution automatic instead of requiring `--bank-index` by hand. None of
that was attempted this pass -- MIDI-with-approximate-instruments was the
mission's actual ask ("make the music audible"), and that's what
`sseq2midi.py` delivers today.

### Sample-based SSEQ renderer (`tools/assets/sseqsynth.py`)

Fifth (audio) pass: renders real-timbre `.wav` files from this ROM's own
SWAV samples instead of a generic MIDI synth, closing the "remaining work"
gap the previous pass left open.

**SEQ -> BANK resolution, solved: it's a direct field, not PLAYER.** The
previous pass's conclusion ("SEQ record has no BANK index; resolution
likely goes through PLAYER") was wrong, and this pass found why: it read 2
bytes of the SEQ INFO record as two separate u8 fields ("volume"/"channel
pressure") that are actually one u16 field -- the BANK index itself.
Decoding this SDAT's 7 PLAYER INFO records directly (`sdat.py`'s new
`player_record()`) settles it: every PLAYER record is `u8 seq_max, u8 pad,
u16 channel_bitmask, u32 heap_size` (8 bytes) -- a channel/heap allocation
group, no BANK reference anywhere. Rereading the SEQ record's bytes +4:+6
as one u16 instead resolves **940/940 (100%)** of populated SEQ records to
a real `bank_record()`, and the resolved BANK's SYMB name matches the
SEQ's own name in every case checked: `SEQ_BGM_TITLE` ->
`BANK_MUS_WB_TITLE`, `SEQ_BGM_GYM` -> `BANK_MUS_WB_GYM`,
`SEQ_BGM_VS_NORAPOKE` -> `BANK_MUS_WB_VS_NORAPOKE`, `SEQ_SE_MESSAGE` ->
`BANK_SE_WB_MESSAGE`, `SEQ_PV001` -> `BANK_PV001`. `sdat.py`'s
`seq_record()` now returns this field as `bank` directly; see that
method's docstring for the full byte-level trace (including exactly which
2 bytes were misread before and why the wrong reading looked plausible at
a glance -- "volume" values like 235, outside 0-127, were the tell).

**Verification (the mission's "known cry-bearing sequence" check):**
`SEQ_PV001` (SDAT SEQ slot 1) disassembles to just 8 events -- Tempo,
ProgramChange, Volume, Pan, one `Note` (pitch 60, velocity 127, duration
**0**), TrackEnd -- exactly the shape of a cry trigger, not a melody. Its
`bank` field resolves to `BANK_PV001`, whose sole instrument (type 1)
points via the BANK's own `wave_arc[0]` to a real one-shot PCM/ADPCM
sample. Rendering it through the same code path as the BGM files produces
a non-silent, non-clipped 1.5 s `.wav` (`--seq-index 1 --verify`) --
confirming the whole pointer chain end to end, the same way the original
Pikachu-cry worked example did by hand.

**Voice model:** per-track bytecode interpreter (real `Jump`/`Call`/
`Return` control flow -- forward jumps taken unconditionally, a backward
jump taken once then refused, so a loop plays twice per the mission
brief's "one loop plus one repeat", `Call` pushes a return address,
`0xA0`/`0xA1`/`0xA2` skipped as no-ops by an assumed fixed byte count).
Each `Note` resolves an `Sbnk` instrument at index = current
`ProgramChange` patch: type 1 used directly; type 16/17 picked by
ascending split point vs. the played note. The resolved region's `wave_arc`
(local, 0-3) is looked up in the *owning BANK's own* `wave_arc[4]` table to
get a global WAVARC index, then `wavarc_fileid()` + `raw_file()` +
`Swar`/`Swav` give the actual sample. Pitch: linear-interpolation resample
at `2**((played_note-base_note)/12) * native_rate/32768`. Looping: a
looping SWAV wraps `[loop_start, total_len)` for as long as the note
sustains; a one-shot SWAV always plays its own full natural length
regardless of the SSEQ note's own (sometimes zero) gate duration -- needed
for cries specifically, whose `Note` duration is 0. Envelope: a simple
linear ADSR from the instrument's attack/decay/sustain/release bytes
(direction picked empirically -- low byte = fast stage -- see
`sseqsynth.py`'s `adsr_times()` docstring). Per-note gain multiplies the
SEQ's own overall volume, the track's current Volume/Expression, and
note velocity; pan is a linear (not equal-power) left/right crossfade.
Tempo events build a piecewise tick-to-seconds map (48 ticks/quarter, same
assumed convention as `sseq2midi.py`). All notes mix into a float buffer,
peak-normalised down (never up) if it would clip, with a 1-second linear
fade-out at the very end.

**A real, pre-existing SBNK gap this pass had to work around (CLOSED by a
later pass -- see "SBNK region tables fixed" below):** `sbnk.py`'s own
`parse_regions()` (type 16/17 key-split/drum-kit) was already flagged
medium-confidence, "not independently re-derived from a byte-level
spec." This pass measured exactly how bad that gap is: across every
type-16/17 instrument in this SDAT (1447 of them), the *first* region
resolves to a plausible in-bank `wave_arc` (0-3) 1253/1447 times (86.6%),
but every region *after* the first is plausible only 154/3786 times
(4.1%) -- almost always garbage (e.g. `wave_arc=23167`, far outside the
valid 0-3 range). Rather than drop most of a real melody's upper
register, `resolve_instrument_region()` falls back to the instrument's
first region when the split-matched one is implausible -- an audible
approximation (wrong per-range timbre, right instrument family), not a
fix to `sbnk.py`'s byte layout (that remains future work, out of this
lane's scope). A later pass re-derives the real region byte layout
against the public SBNK spec (the record is 10 bytes with the two `u16`
fields swapped from what this pass assumed, not 12 bytes) and gets every
region in every real bank to 100% plausibility -- the first-region
fallback described here was removed once that fix landed, since it no
longer has anything implausible to fall back from.

**Files rendered to `build/assets/audio/` (gitignored, regenerate, don't
commit), 32768 Hz stereo 16-bit, capped at 30 s:**

| file | SEQ index | duration | tempo | tracks | notes rendered | peak |
|---|---:|---:|---:|---:|---:|---:|
| `seq_bgm_title.wav` | 1003 (`SEQ_BGM_TITLE`) | 30.00 s | 60 BPM | 12 | 38/72 | 22579/32768 |
| `seq_bgm_gym.wav` | 1062 (`SEQ_BGM_GYM`) | 30.00 s | 116 BPM | 9 | 75/296 | 9139/32768 |
| `seq_bgm_vs_norapoke.wav` | 1128 (`SEQ_BGM_VS_NORAPOKE`) | 30.00 s | 190 BPM | 11 | 129/766 | 17515/32768 |
| `seq_se_message.wav` | 1351 (`SEQ_SE_MESSAGE`) | 2.53 s | 300 BPM | 1 | 2/2 | 9681/32768 |
| `seq_pv001_cry_verify.wav` | 1 (`SEQ_PV001`, cry verification) | 1.50 s | 100 BPM | 1 | 1/1 | 29837/32768 |

All five pass this pass's sanity gate (`--verify`): non-silent (>1% of
samples above a small noise-floor threshold), not clipped (peak <
32767), and at least one note event actually consumed and rendered.

(`seq_bgm_gym.wav` and `seq_bgm_vs_norapoke.wav`'s numbers above are from
this pass, before the SBNK region-table fix below -- see "SBNK region
tables fixed" for the corrected re-render of both.)

**Known inaccuracies (see `sseqsynth.py`'s module docstring for the full
list):** ADSR curve shape/scale and its byte-value direction are both
assumed, not derived from real hardware timing; Volume/Expression/pan
combine linearly, not on the hardware's real (likely dB-scale) curve;
Portamento/Mod*/SweepPitch/PitchBendRange/Tie and pitch bend itself are
no-ops (no per-sample re-triggering of resample ratio mid-note);
`0xA0`/`0xA1`/`0xA2` are skipped by an assumed fixed byte count, not a
verified argument decode; SBNK types 2/3 still have no wave data to play;
loop detection only recognises one backward `Jump` per track, same
limitation `sseq2midi.py` already has.

**Remaining gaps (at the time this pass was written; SBNK type 16/17's
region layout was fixed by a later pass, see below):** SBNK type 16/17's
true byte layout beyond the first region (the 4.1%-plausible finding
above); SWAV PCM16 remains unexercised against real data (this ROM's
WAVARC entries are 100% PCM8/ADPCM, per the SWAR/SWAV section above);
`0xA0`-`0xA2`'s real argument shapes are still unknown in this codebase,
so the no-op byte-skip is a labelled guess, not a decode.

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
7. **SDAT (sound)** -- done. `wb_sound_data.sdat`'s container, and the
   SWAR/SWAV, SBNK, and SSEQ payload formats, are now all opened by
   `tools/assets/sdat.py`, `swav.py`, `sbnk.py`, `sseq.py`; cries decode
   and play, instrument banks and sequence bytecode are parsed and
   round-trip verified. `tools/assets/sseq2midi.py` renders SSEQ sequences
   to Standard MIDI Files (see "SSEQ -> MIDI" above) -- the music itself is
   now audible, with real sample-accurate synthesis (SBNK/SWAV playback)
   left as future work. See "SWAR/SWAV, SBNK, SSEQ: audio playback
   formats" above.
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
  A third pass closed out the actual payloads: SWAR/SWAV PCM8/PCM16/
  IMA-ADPCM decoding, SBNK instrument banks, and SSEQ bytecode
  disassembly -- see "SWAR/SWAV, SBNK, SSEQ: audio playback formats"
  above for decoder results, `.wav` files written, round-trip counts, and
  the remaining gaps (PCM16 untested against real data, SBNK types 2/3/
  16/17 only partially reverse engineered, SSEQ 0xA0/0xA1/0xA2 argument
  substitution not decoded).
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

## `a/0/0/4` block entries 0-17: a self-contained cell-animation rig, NOT the `a/1/3/4` OAM source

Fifth asset lane pass, scoped to the mission of characterizing the other 18
entries of `a/0/0/4`'s 20-entry-per-species block (species 25/Pikachu as the
worked example) and testing the hypothesis that its `RECN`/NCER cell bank's
OAM tile indices point into `a/1/3/4`'s 0x20000-byte battle-sprite tile blob.
**That hypothesis is false** -- see below -- so the pixel-layout gap on
`a/1/3/4` (documented above under "Known issue: pixel layout") is **still
open**; this pass closes a different, related question instead (what the
other 18 `a/0/0/4` entries actually are).

### Block entry map (species 25, local indices 0-19, sub-file index = `20*25 + local`)

| local | decompressed magic | dec./raw size | role |
|---|---|---|---|
| 0 | RGCN (NCGR) | 4656 (12x12 tiles, 4bpp, 4608B tile data) | small tile sheet |
| 1 | RGCN (NCGR) | 4656 | duplicate of local 0 (byte-identical layout, separate LZ11 stream) |
| 2 | RGCN (NCGR) | 16448 (16x32 tiles, 4bpp, 16384B tile data) | main tile sheet |
| 3 | RGCN (NCGR) | 16448 | duplicate of local 2 |
| 4 | RECN (NCER), raw | 476 | cell bank (11 cells / 17 OAMs, see below) |
| 5 | RNAN (NANR) | 5324 | cell animation (references NCER cell indices) |
| 6 | RCMN (NMCR), raw | 220 | multi-cell resource (rig/skeleton grouping cells) |
| 7 | RAMN (NMAR), raw | 107 | multi-cell animation (poses/moves the NMCR rig) |
| 8 | unrecognised, raw | 544 | no NITRO magic; first 4 bytes `0b 00 00 00`; not decoded this pass |
| 9-12 | RGCN x4 | 4656/4656/16448/16448 | second copy of local 0-3 (see below) |
| 13 | RECN (NCER), raw | 376 | second cell bank (smaller than local 4) |
| 14 | RNAN (NANR) | 4360 | second animation |
| 15 | RCMN (NMCR), raw | 188 | second multi-cell resource |
| 16 | RAMN (NMAR), raw | 107 | second multi-cell animation |
| 17 | unrecognised, raw | 400 | no NITRO magic; first 4 bytes `08 00 00 00`; not decoded this pass |
| 18 | RLCN (NCLR) | 72 | normal palette (`PALETTE_NORMAL_OFFSET`) |
| 19 | RLCN (NCLR) | 72 | shiny palette (`PALETTE_SHINY_OFFSET`) |

So the 20-entry block is two near-identical `NCGR x2 + NCER + NANR + NMCR +
NMAR + unknown-blob` bundles (local 0-8 and 9-17, most plausibly front/back
or male/female variants of the same rig) followed by the palette pair. Every
bundle is a **complete, self-sufficient Nitro 2D cell-animation resource
set**: tiles (NCGR), a cell bank mapping OAMs to those tiles (NCER), a
cell-index animation (NANR), and a multi-cell rig/pose animation
(NMCR/NMAR) for combining multiple cells into an articulated figure. This
is the standard NNS_G2D toolkit shape for a *poseable, multi-part* sprite
(distinct from a single flat image).

### NCER findings (local index 4, sub-file 504 for species 25)

Parsed the generic NCER `KBEC` (CEBK reversed) block header (public NDS
format shape, no project code copied):

- **11 cells, 17 OAMs total**, `mapping_type = 4` (1D OBJ character mapping,
  256-byte-per-index-step boundary -- the standard NNS_G2D `mappingType`
  enum where 0 = 2D and 1..4 = 1D with boundary `32 << (mappingType-1)`
  bytes; type 4 -> boundary 256B). Cells are the "simple" (non-extended)
  form (`cell_info` bit0 clear -- no per-cell bounding-box rectangle), 8
  bytes each: `num_oam(u16), cell_attr(u16), oam_ofs(u32)`. The OAM array
  follows immediately after the cell array, 6 bytes/OAM (3x u16, standard
  GBA/NDS OAM attr0/attr1/attr2 triple: y/shape/color-depth, x/flip/size,
  tile-index/priority/palette).
- OAM shapes/sizes span the small end of the standard shape table (8x8 up
  to 32x16), `tile_idx` values range 0-165, all `pal=0`, no flips set.
- **A companion `LBAL` (LABL) block lists 20 name strings** for this NCER,
  not 11 -- and they are **Japanese Pokemon body-part names**: `atama`
  (head), `kuti01` (mouth), `karada` (body), `mimi01`/`mimi02` (ear x2),
  `o` (tail), `te01`/`te02` (hand/arm x2), `asi01`/`asi02` (foot/leg x2),
  then the same 10 names again with an `_2` suffix. This is strong,
  species-appropriate (Pikachu has two ears, a tail, two hands, two feet)
  confirmation that **this NCER's cells are individual body parts of an
  articulated rig**, not a single full-body battle-sprite frame -- matching
  the NMCR/NMAR pair alongside it (multi-cell = "assemble these named
  parts", multi-cell-animation = "move them"). The 20-vs-11 count mismatch
  (more labels than cells) was not resolved this pass; a plausible guess is
  that LABL is a shared/reused string table (e.g. also referenced by the
  local-13 NCER, or by unused label slots), not investigated further.

### Tile-index resolution: `a/0/0/4`'s own local NCGR, not `a/1/3/4`

Composed the 17 OAMs (fetching each OAM's tile(s) as consecutive 32-byte
4bpp tiles starting at `tile_idx`, standard row-major 8x8 nibble-packed
tiles, low nibble = left pixel, blitted at the OAM's signed x/y cell-local
offset) against two candidate tile sources, both loaded via `species*20 +
18` for the palette:

1. **`a/1/3/4` sub-file 25's 0x20000 payload** (the mission's working
   hypothesis), tried at both `tile_idx * 32` (dense) and `tile_idx * 256`
   (the NCER's own declared 256-byte boundary) byte-offset scales. **Both
   produce the same noisy, vertically-banded garbage** as the existing
   third/fourth-pass renders of `a/1/3/4` on its own -- confirming this
   NCER is not the right cell table for that archive's pixel data (or, if
   it is, the boundary/addressing recovered here is still not enough to
   fix the pre-existing banding bug). Tried two more pixel-unpack variants
   (high-nibble-first, and a transposed/column-major tile read) against the
   same blob: neither removes the banding, it only changes its axis
   (vertical stripes vs. horizontal stripes), which points at the banding
   being a property of how `a/1/3/4`'s raw bytes are addressed/tiled in
   the first place, independent of which NCER or scale reads them.
2. **`a/0/0/4` local entry 2's own decompressed NCGR tile data** (parsed
   the `RAHC`/CHAR block correctly: `u16 tileNumY, u16 tileNumX, u32
   bitdepth, u16 pad, u16 flag, u32 unk1, u32 dataSize, u32 dataOfs` --
   16x32 tiles, 4bpp, 16384-byte tile array at body offset 0x18), read at
   `tile_idx * 32` (dense, matching the tile sheet's own packed layout).
   **This one decodes cleanly**: every OAM's 8x8/16x8/etc. block comes out
   as clean, contiguous, single-color-family (yellow/gold/brown/red-black,
   Pikachu's real palette) shapes with **no banding at all** -- strong
   confirmation that `local 4`'s NCER is paired with `local 2`'s NCGR (and
   `local 0`'s smaller sheet, and their `local 9-13` counterparts), a
   completely different tile source than `a/1/3/4`.

**Conclusion: the mission's premise was wrong for this specific pairing.**
`a/0/0/4`'s NCER/NCGR/NANR/NMCR/NMAR bundles are a self-contained rig with
their own embedded tiles -- most likely the overworld-follower or menu
"poseable" Pikachu, not the battle sprite. `a/1/3/4`'s battle-sprite blob
(confirmed in the third pass to carry no NITRO chunk magic at all) still has
**no located cell/OAM table anywhere in this ROM as of this pass** -- the
`a/0/0/4` NCER was the leading candidate and is now ruled out. The
vertical/horizontal-banding pixel-layout bug on `a/1/3/4` remains unsolved.

### Frame composition result

Composing local NCGR + local NCER for species 25 (`build/assets/battle_cells/
0025_local_ncgr.png`, not committed -- gitignored `build/` output) produces
clean yellow/brown/red Pikachu-colored fragments (visually confirmed by
direct inspection of the rendered PNG) but **not a coherent full-body
silhouette**: the OAMs land as scattered small pieces (ears, hands, feet
etc., matching the body-part label names) rather than a single assembled
pose, because a cell bank's per-cell OAM offsets alone don't include the
NMCR/NMAR rig-assembly step (which cell goes where, and in what animation
frame) -- that would need decoding `local 6`/`local 7` (NMCR/NMAR) as well,
not attempted this pass. Per this lane's instructions, **no `--cells` mode
was added to `battle_sprite.py`**, since the render does not meet the
"recognizable silhouette" bar for `a/1/3/4` battle sprites specifically (and
is, in any case, decoding the wrong archive's sprite for that purpose).

### What remains after this pass

- **`a/1/3/4`'s pixel layout is still unsolved.** This pass ruled out
  `a/0/0/4`'s NCER as its cell table (clean decode against `a/0/0/4`'s own
  NCGR, banded garbage against `a/1/3/4` regardless of scale or nibble/
  transpose variant tried) but did not find the real one. Next places to
  look: `a/0/5/2` (the sibling archive, not yet checked for a *different*
  non-palette structure than `a/0/0/4`), or a lookup/offset table elsewhere
  in the ROM (code overlay or another NARC) that pairs directly with
  `a/1/3/4`'s sub-file indices.
- `local 8`/`local 17`'s unrecognised raw blobs (544/400 bytes, no NITRO
  magic) were not decoded -- possibly vertex/bounding or VRAM-transfer
  metadata belonging to the NCER's `ext_ofs` field (seen as 0 in this
  sample, so probably not directly referenced, but not confirmed).
- The 20-vs-11 LABL/cell count mismatch on the NCER was not explained.
- `local 6`/`7` (NMCR/NMAR, the actual rig-assembly and pose-animation
  data) were identified by magic only, not parsed -- decoding them is the
  natural next step to actually assemble a full posed figure from
  `a/0/0/4`'s parts (a different, still-useful deliverable, just not a
  battle sprite).
- Per-species animation frame count for `a/1/3/4` itself is still
  unknown; nothing in `a/0/0/4` turned out to describe it (it describes a
  different rig's animation instead).

## `a/1/3/4` reinterpreted: 256x256 16bpp direct-color images, not 4bpp indexed sprite tiles

Sixth asset lane pass, targeted measurement of `a/1/3/4`'s true byte
layout instead of continuing to extend the third/fourth/fifth passes'
4bpp/128px-wide/tiled assumption (which never stopped banding, see "Known
issue: pixel layout" above). Method: autocorrelation of the raw decompressed
byte stream at every candidate row stride from 16 to 1024 bytes (step 8),
scored as mean absolute byte difference between `data[i]` and
`data[i+stride]` across the whole 0x20000-byte buffer (lower = more
row-to-row similarity = stronger periodicity at that stride) -- run over
species 25's decompressed payload with an ad hoc script (not committed,
re-run by decoding sub-file 25 with `narc.decompress_lz11` and scanning
strides as described; not part of the write set for this pass).

**Result: stride 512 bytes dominates every other candidate by a wide
margin** (mean abs diff 7.5, next-lowest non-harmonic candidate in the
20s-30s, the harmonic stride 1024 second-lowest at 10.3, average across
all 126 candidate strides 55.2). This *matches* the row stride the third
pass already assumed (16 tiles/row * 32 bytes/tile = 512, for a
128px-wide 4bpp tiled image) -- but **512 bytes/row is exactly as
consistent with a completely different, non-tiled interpretation**: a
linear (not tile-swizzled) 16-bit direct-color image with a 256-pixel-wide
row (256 * 2 bytes/pixel = 512). Since 256x256 pixels at 16bpp is exactly
0x20000 bytes -- the whole decompressed payload, no filler region left
over -- this was checked directly, per the mission brief:

- **Every one of the 65536 16-bit little-endian values has bit 15 set**
  (fraction 1.0, not ~0.5 as random data would show). Bit 15 in the NDS
  "A1BGR555" direct-color texel format is the opacity bit; all-opaque is
  exactly what a real background/portrait image (no transparency) would
  produce, and is a strong non-random signal.
- **Mean absolute per-channel difference between horizontally adjacent
  pixels (R+G+B, 0-31 each) is 1.62** -- extremely smooth, consistent with
  a real photographic/painted image, not noise (a uniform-random 5-bit
  channel would average around 10.3 per channel, ~31 combined).
- Rendering the plain BGR555-to-RGB8 mapping (`build/assets/blob_hyp/
  species0025_16bpp_256x256.png`, `species0001_...`, `species0002_...`,
  `species0150_...`) produces, for species 150, an **unmistakable, sharp
  character portrait**: a face with green hair and red eye markings,
  rendered with soft shading and a glowing backlight -- not a Pokemon
  sprite, a human/humanoid character bust. Species 25 and species 1 render
  as a dark scene with an architectural building silhouette (visible roof
  lines, windows, warm lantern-lit highlights) partially obscured by a
  foreground silhouette (fence- or bar-like vertical shapes) -- also
  clearly a real rendered scene, not noise, just a darker/harder one to
  describe. **None of the four samples checked look anything like a
  Pokemon.**

For comparison, the same smoothness metric computed against the two prior
hypotheses on the *same* species-25 payload:

| hypothesis | metric | value | read |
|---|---|---:|---|
| **16bpp linear, 256x256, direct color** | mean adjacent-pixel diff (3ch, 0-31 each) | **1.62** | very smooth, real image |
| 4bpp tiled, 128px wide (third-pass theory) | mean adjacent-pixel diff (1ch, 0-15) | 5.44 (36% of max) | noisy relative to its own range |
| 8bpp linear, 512px wide (mission's other candidate) | mean adjacent-pixel diff (1ch, 0-255) | 86.4 (34% of max) | essentially random-looking |

`build/assets/blob_hyp/species0025_4bpp_tiled_w128_grayscale.png` (the
losing hypothesis, re-rendered here for side-by-side comparison) shows the
same vertically-banded noise the fourth/fifth passes already flagged.

### What this means for `a/1/3/4`'s identity

**The "Pokemon battle sprite archive" guess for `a/1/3/4` is very likely
wrong**, not just its pixel-layout details. 256x256 16bpp direct-color
images with human-portrait and building content read as trainer/cutscene
art or a battle-intro background/bust archive, not per-species sprite
tiles -- the 670-sub-file count lining up loosely with Black/White's
species count was circumstantial (670 is at least as plausible read
against a trainer-class-ish count, matching the "~700+ trainer classes"
figure already used elsewhere in this document for `a/0/0/6`). This is
**not re-verified against the specific trainer-class or portrait-index
list** (out of scope for this pass -- would need a name/index table this
lane did not go looking for), so the exact identity of "which picture is
sub-file N" is still open. What is now confirmed, not guessed: the
**pixel format** is 256x256 16bpp BGR555-with-opacity-bit direct color,
linear (row-major, no tile swizzling), for every sample checked.

This reopens (rather than closes) the earlier "battle sprite colors" and
"pixel layout" passes' framing: the `a/0/0/4` palette-pairing work
(species*20+18/19 -> RLCN colors matching known Pokemon color schemes,
including Mewtwo's shiny purple->green swap) is unaffected and still
solid evidence for *that* archive, but it was never actually palette
evidence *for `a/1/3/4`* beyond the assumption that `a/1/3/4` needed an
external palette at all -- a 16bpp direct-color image needs no palette,
so that pairing may simply be coincidental to a different archive
(`a/0/0/4`) that does hold real Pokemon-colored content. Re-auditing
whether `a/0/0/4`'s palette pairing was ever actually confirmed *against
a/1/3/4-sourced pixels* (as opposed to `a/0/0/4`'s own rig pixels, which
the fifth pass separately confirmed decode cleanly) is flagged as a gap
for a future pass.

### What remains after this pass

- The true content identity of `a/1/3/4` (trainer portraits? battle
  backgrounds? cutscene art?) is not confirmed, only the pixel format.
  Only 4 of 670 sub-files were rendered and eyeballed.
- The `a/1/3/4` <-> `a/0/0/4` palette relationship discovered in the
  fourth pass needs re-examination now that `a/1/3/4` is not indexed
  sprite data (see above) -- it may be an artifact of two independently
  species/index-ish-shaped archives rather than a real pairing.
- `tools/assets/battle_sprite.py`'s 4bpp/tiled decode path is now known
  to be decoding the wrong format for `a/1/3/4` specifically; it was left
  unmodified this pass (out of this pass's write-set discipline and
  because the tool may still be useful/correct for other archives sharing
  the same *container* shape -- LZ11, no NITRO magic -- that were never
  checked). A future pass should either add a 16bpp linear decode path to
  a shared tool or retire the 4bpp assumption for this specific archive.

## `a/0/0/4` rig posing: NMCR/NMAR parsed, frame composition partial

Sixth asset lane pass (second half), the mission's other half: actually
composing a posed frame from the `a/0/0/4` multi-cell rig identified (but
not decoded) in the fifth pass. New tool: `tools/assets/rig.py`, which
parses NCGR (RGCN), NCER (RECN), NMCR (RCMN) and (partially) NMAR (RAMN)
from scratch -- see the module's own docstring for the full byte-level
format writeup (header shapes, self-relative vs. block-relative offset
conventions, the NCER OAM bitfield layout, the NMCR node-record structure)
rather than duplicating it here. Species 25 (Pikachu) is the worked
example throughout, matching the fifth pass.

### NCER: cell/OAM parsing confirmed exactly

`tools/assets/rig.py`'s `Ncer` class parses the `KBEC` (CEBK) block's
16-byte, block-relative (not self-relative) sub-header, cell array (8
bytes/cell: `num_oam`, `cell_attr`, `oam_ofs`) and OAM array (6 bytes/OAM,
standard GBA/NDS attr0/attr1/attr2 triple). Run against species 25's
local-4 NCER: **11 cells, 17 OAMs total**, and every cell's `oam_ofs`
field lines up exactly with the running `num_oam` total of the cells
before it (cell 1 starts at OAM 5 = byte offset 30, cell 2 at OAM 7 = byte
offset 42, ...) -- this pins the addressing precisely, not a guess, and
matches the fifth pass's cell/OAM counts exactly.

### NMCR: rest-pose node table decoded

`Nmcr` parses the `KBCM` (MCBK) block. Unlike NCER's header, **this one's
offset fields are self-relative** (add the field's own byte position to
its value to get the target) -- confirmed because that convention lands
both offset fields exactly on the start of the two tables that follow,
while a block-relative reading of the same fields would not. Species 25's
node placement array (152 bytes) resolves cleanly into **19 fixed 8-byte
records** (found by locating a byte value that recurs at an exact 8-byte
stride end-to-end across the whole array): `label_index` (s16, indexing
the paired NCER's 20-name LBAL table), `x`/`y` (s16 each), a constant tag
byte `0x20`, and a `cell_index` byte. The 19 records' label indices cover
all 20 LBAL names exactly once each except one substitution (label 7
"te02" is skipped in favour of label 17 "te02_2"), and the first
`num_multi_cell` entry's declared node count (10) lines up exactly with
the first 10 records forming one complete, non-duplicated pass over every
named body part -- used here as "multi-cell 0" / the rest pose.

### Frame composition: contact sheet clean, full pose not recognizable

`rig.py 25` writes two PNGs to `build/assets/rig/`:

- **`0025_cells.png`** -- a contact sheet of all 11 cells, each rendered
  individually (own local bounding box, correct tiles from the block's
  own local-2 NCGR, correct palette from local-18 NCLR). This meets the
  mission's fallback bar: real, correctly-textured/colored fragments, not
  garbage -- but each cell is visibly **sparse** (many OAMs are 5-40%
  non-background pixels), which turns out to be a property of the source
  data, not a decode bug: the whole local-2 NCGR tile sheet is **95.1%
  background-index-0** across all 512 tiles (checked directly), so any
  correctly-decoded cell drawn from it will look sparse. This is a
  genuinely small/simple sprite (an overworld-scale or menu-scale
  Pikachu, matching the fifth pass's "poseable overworld/menu figure"
  read), not a dense battle-sprite-scale image.
- **`0025_a0_f0.png`** (53x53) -- all 10 rest-pose nodes' cells blitted
  together. **Does not clear the "recognizable Pikachu" bar.** Two
  placement strategies were tried: summing the NMCR node's own (x, y)
  onto each OAM's cell-local (x, y) scatters the 10 parts across a much
  larger area with no coherent shape; using each OAM's cell-local (x, y)
  directly, with the node (x, y) *not* added (this tool's default,
  `apply_node_offset=False` in `compose_rest_pose()`), gives a visibly
  more spatially coherent result -- a compact ~50x50px mass with a
  reddish accent in a cheek-plausible position -- but still reads as a
  loose, disconnected blob rather than a clean silhouette. **The NMCR
  node (x, y) fields' real role was not resolved**: summing them is
  clearly wrong (it breaks the better-looking arrangement), but zeroing
  them is a default chosen for a better-looking picture, not a confirmed
  correct decode -- plausible alternative readings not chased down this
  pass: the node offsets are per-*animation-frame* deltas (applied on top
  of a true rest position this pass never found), a different unit scale
  (e.g. sub-pixel or a coordinate space that needs an additional
  transform from NMAR), or bounding/hit-box metadata unrelated to
  rendering placement at all.

## NSBMD/NSBTX (3D models): container, textures, geometry, round trip

New this pass: `tools/assets/nsbmd.py` (stdlib-only, new file), covering
BMD0 (`NSBMD`, model+texture) and BTX0 (`NSBTX`, texture-only) containers
per the "Proposed converter lane order" item 6 above. Format knowledge
used (container/ResDict shape, the GX geometry-command opcode table, the
NDS texture pixel formats, the TEXIMAGE_PARAM hardware register bit
layout) is drawn from public DS hardware documentation and cross-checked
by hand against real files pulled from `a/0/1/1`, `a/0/4/5`, `a/0/4/9`,
`a/0/1/4` and others; no code from any other decomp/ROM-hacking project
was used.

Run it yourself:

```
python tools/assets/nsbmd.py info build/assets/tmp/some.bmd0
python tools/assets/nsbmd.py texture build/assets/tmp/some.bmd0 -o build/assets/textures/out.png
python tools/assets/nsbmd.py obj build/assets/tmp/some.bmd0 -o build/assets/models/out.obj
python tools/assets/nsbmd.py roundtrip "extract/data/a/0/*/*"
```

### Container and dictionary structure (confirmed)

BMD0/BTX0 share one outer container shape: 16-byte header (magic, BOM,
version, file size, header size, block count) then `block_count` absolute
`u32` block offsets. BMD0 has 2 blocks (`MDL0` then `TEX0`); BTX0 has 1
(`TEX0` only). Each block is itself `magic(4) + size(4)` prefixed. This is
fully confirmed (byte-exact against every sample checked) and is the
basis of the round-trip check below.

Both MDL0's model list and TEX0's texture/palette lists use the same
"ResDict" shape: `revision(u8)=0, numEntries(u8), size(u16)` (total dict
size including this 8-byte header), two more `u16` fields whose meaning
was not pinned down, then an opaque "entries" blob, then exactly
`numEntries * 16` bytes of NUL-padded ASCII names as the *last* bytes of
the dict (confirmed: names are always cleanly at the end, never
interleaved with entry data, in every sample checked from 1 up to 67
entries).

**Honesty note on the entries blob:** the per-entry record stride inside
that blob is NOT constant across dict types -- it worked out to 12
bytes/entry for a single-model MDL0 dict, but did not divide evenly for a
6-texture TEX0 dict (suggesting texture records vary in size, plausibly
because 4x4-compressed textures carry an extra index-table pointer plain
formats don't). Rather than guess a stride and risk silently emitting
wrong data, `nsbmd.py` treats every dict's entries blob as **opaque**:
enough to recover resource *names* (which is confirmed-solid) and to
round-trip byte-for-byte, but not to reliably map a given texture name to
its exact offset/width/height/format from the dict alone. This is the
same "verify before trusting a decode" stance already used for the
LZ77/Huffman sniffs elsewhere in this document.

### TEX0 texture/palette data location (confirmed)

TEX0 has a fixed 0x3C-byte header before its texture ResDict. Two u32
fields in it were confirmed by cross-referencing against where the actual
texel-looking / palette-looking bytes start (independently located via
the two ResDicts' own `size` fields, which do NOT depend on cracking the
entries-blob stride): `TEX0+0x14` = texture data byte offset from TEX0
start, `TEX0+0x24` = palette data byte offset. `texture_data_size =
pal_offset - tex_offset` matched the actual data region exactly in every
sample. The rest of the 0x3C-byte header is preserved opaque.

### Texture pixel decoding: all NDS formats implemented, applied via a validated heuristic

All texel formats are implemented in `decode_texture()`: A3I5, 4-color
(2bpp), 16-color (4bpp), 256-color (8bpp), A5I3, and direct color
(BGR555 + alpha bit) -- straight from the public GX TEXIMAGE_PARAM
format-field spec, independent of the container-layout uncertainty above.
**4x4-compressed (format 5) is NOT implemented** (see gaps).

Since the exact per-texture offset/width/height/format isn't reliably
recoverable from the TEX0 dict (see above), pixel decoding is done for
the common case of a TEX0 block holding **exactly one texture**: the
whole `texture_data_size` region belongs to it, so `guess_single_texture()`
brute-forces every (format, width, height) combination over the DS's
legal texture sizes (powers of two, 8..1024) whose byte size exactly
equals `texture_data_size`, decodes each, and scores candidates by (a)
what fraction of decoded palette indices are actually in range for the
attached palette -- a real validity check, not a guess -- and (b), as a
tie-breaker, how closely the format's index range (4/8/16/32/256 colors)
matches the palette's actual color count (a texture with a 16-color
palette is overwhelmingly more likely to be the matching 16-color format
than a 4-color or 256-color one that only uses a sliver of it, or a
"direct color" format that trivially scores 100% valid for any bytes).

**Validated on 3 sample models, visually:**

| model | texture name | guessed format | size | render |
|---|---|---|---|---|
| `a/0/1/1#0` (`batt_stage01`) | `batt_stage01` | 16-color | 32x32 | horizontal green/brown bands -- reads as a grass-over-ground battle-stage floor |
| `a/0/4/5#0` | `item01` | 16-color | 32x32 | a pink X/bandage shape on green -- reads as a held-item icon sprite |
| `a/0/4/9#2` (model `dragon_bone`) | `in6_khone02` | 16-color | 64x64 | grayish mottled shape with dark sockets -- reads as a bone/skull texture, consistent with the model's own name |

All three decoded images are semantically plausible for their resource
names, which is the strongest confirmation available without an emulator
-- not a proof, but a strong signal the format/dimension guess (and the
underlying pixel-format decoders) are correct. PNGs written to
`build/assets/textures/`.

### Geometry command stream -> OBJ

Shape data is a stream of DS GX FIFO commands: a packed `u32` command
word (4 opcode bytes, `0x00`=NOP padding) followed by each opcode's
parameter words. `nsbmd.py` implements the full documented opcode/param-
count table (so it correctly skips matrix/lighting/etc. commands it
doesn't use) and interprets `BEGIN_VTXS`/`END_VTXS` (triangle/quad/
tristrip/quadstrip fan-out), `VTX_16` (s16.12 fixed-point position) and
`TEXCOORD` (s16.4 fixed-point texel units, normalised to 0..1 using the
model's own guessed texture size for the OBJ file).

The stream's start offset isn't otherwise known (same entries-blob
uncertainty as above), so it's located heuristically: scan for the first
offset that decodes as a valid command stream for a long, unbroken run.
Real non-command bytes hit an unrecognised opcode almost immediately;
the real stream does not.

**Result on `a/0/1/1#0` (`batt_stage01`):** GX stream found at model
offset `0x15C`, 244 commands, 16 vertices, 4 quad faces -- decoded to a
clean 16-point circular fan (radius ~5.33 units) at constant height,
exactly the shape expected for a round battle-stage platform, written to
`build/assets/models/batt_stage01.obj`. Also exported: `a/0/4/9#2`
(`dragon_bone`), 410 commands, 161 vertices, 81 faces, to
`build/assets/models/dragon_bone.obj` (not visually cross-checked against
a renderer, only structurally: vertex/face counts are sane and no
decode error occurred).

### Round trip: verified byte-identical, 1752/1752 sub-files

`nsbmd.py reserialize()`s every parsed field plus the opaque byte ranges
(dict entries blobs, TEX0's 0x3C-byte header, and the MDL0/TEX0 raw data
tail) back into the exact input bytes -- every byte of the file is
accounted for by either a parsed field or a preserved opaque range, so
this is a real round trip, not a copy-through.

```
python tools/assets/nsbmd.py roundtrip "extract/data/a/0/*/*"   # 1329/1329
python tools/assets/nsbmd.py roundtrip "extract/data/a/1/*/*"   # 400/400
python tools/assets/nsbmd.py roundtrip "extract/data/a/2/*/*"   # 23/23
```

**Result: 1752/1752 BMD0/BTX0 sub-files round-trip byte-for-byte** across
every NARC under `a/0`, `a/1` and `a/2` (the one non-NARC error reported
by the `a/0` run is `a/0/1/3`, already known from the inventory to be an
unrecognised raw blob, not a NARC -- expected, unrelated to `nsbmd.py`).

### Known gaps

- ~~**4x4-compressed textures (format 5) are not decoded.**~~ **Superseded:**
  a later pass ("NITRO resource dictionary CRACKED" below) scanned every
  texture dict entry ROM-wide via the now-cracked record layout and found
  **zero format-5 usage anywhere in this ROM** -- format 5 was never used
  by this title's actual assets, not merely undecoded.
- ~~**Multi-texture TEX0 blocks are not pixel-decoded**~~ **Superseded:**
  `decode_all_textures()` (see "NITRO resource dictionary CRACKED" below)
  decodes every texture in a TEX0 block directly from its own dict entry,
  no longer limited to `count == 1`; verified on `a/0/1/4#0` (67/67) and
  `a/0/4/9#199` (6/6).
- ~~**The TEX0/MDL0 ResDict entries-blob record layout was not cracked**~~
  **Superseded:** see "NITRO resource dictionary CRACKED" below -- the
  patricia-node-array + `{entrySize, namesOffset}` sub-header + per-entry
  records layout is now confirmed and generically implemented
  (`ResDict.entries()`), reused for TEX0 textures/palettes and MDL0
  node/material/shape dicts.
- **Materials (texture-to-shape binding, transforms, per-material
  TEXIMAGE_PARAM) were not parsed.** OBJ export uses a single detected
  geometry stream, not a full scene graph; models with multiple
  materials/shapes only get the first shape the stream-locator heuristic
  finds. Skinning/bone transforms (`MTX_*` commands) are correctly
  skipped over (so the command stream still decodes past them) but not
  applied, so multi-bone models would export in bind-pose-ish local
  coordinates rather than their final posed positions. **Partially
  superseded:** a later pass ("NITRO resource dictionary CRACKED" below)
  found and generically decoded the shape->material->texture link (a real
  bytecode "render command" region binding each shape index to a material
  index, plus the material dict's name convention linking to real texture
  names) -- confirmed for all 40 shapes of `pl_00_00`. What's still open
  is splitting the merged GX command stream into per-shape face ranges, so
  that link can be applied per-face rather than to a whole merged mesh.
- Only `a/0`, `a/1` and `a/2` were covered by the round-trip sweep (all
  BMD0/BTX0-bearing NARCs live under those three directories per the
  inventory table above); no BMD0/BTX0 sub-file failed.

### NMAR: header parsed, per-frame transform values not recovered

`Nmar` parses the common header and the `KNBA` (ANBK) block's leading
fields (`num_anim`=1, an `element_type` field=2, unexplained) plus the
`LBAL` block that follows it (one animation name, `"CellAnime0"` for
species 25 -- confirming exactly one defined animation, consistent with
`--anim 0 --frame 0` being the only meaningful invocation for this
species). The ANBK body's three offset fields (block-relative, unlike
NMCR's self-relative convention -- the two blocks do NOT share an offset
convention) point at three small tables: one all-small-integers region,
one with two `(value, 0xBEEF)` sentinel-tagged sub-records (the same
0xBEEF signature NMCR's header uses), and one two-byte-int region reading
as `(1, 0)` -- plausibly a frame/key count of 1. **The actual per-frame
transform payload (if any) was not located or decoded**; this tool
assumes animation 0 frame 0 is the NMCR rest pose with no additional
transform, flagged as an unverified simplification rather than silently
assumed. See `tools/assets/rig.py`'s module docstring for the full
byte-by-byte field table.

### What remains after this pass

- **The "recognizable Pikachu" bar is not met.** The fallback contact
  sheet is. The composed pose is a plausible-looking but not confidently
  correct blob; the NMCR node (x, y) semantics are the most likely next
  thing to crack (comparing species 25 against a second species' NMCR, or
  against the *second* multi-cell entry/9-node span this pass didn't use,
  might disambiguate what the offsets are for).
- NMAR's per-frame transform table (the actual "animation" part of
  "multi-cell animation") was not found, only its container's header
  shape. Given only one animation and a frame/key count that reads as 1
  for species 25, a species with a visibly *moving* idle animation (not
  yet identified) might make the transform table easier to spot by
  diffing against a static species.
- The second multi-cell entry (9 nodes, species 25) and the second
  bundle (local 9-17, "front/back or variant") were not rendered or
  compared against the first -- doing so might help disambiguate the
  rest-pose-vs-animation-delta question above.
- `local 8`/`local 17`'s unrecognised raw blobs (fifth pass) are still
  undecoded and still not ruled in or out as relevant to posing.

## Seventh asset lane pass: NANR decoded fully, best-effort pose still not recognizable

Mission: make species 25 (Pikachu) pose, decode NANR fully, and test three
hypotheses about NMCR/NANR/NMAR semantics. Species 1 and 150 rendered too,
to check generality. `tools/assets/rig.py` gained `compose_pose()`, `--pose`,
and `--all`. **Result: the "recognizable Pikachu" bar from the mission is
still not met for any of the three species** -- this pass narrows the
hypothesis space and ships a strictly better (denser, more spatially
plausible) composition than the sixth pass's, and closes out the NANR
format gap, but the true node-placement semantics remain unconfirmed. This
is reported honestly rather than claimed as a working pose per this
project's practice of not dressing up partial results.

### Hypothesis (b) -- NMCR nodes reference NANR sequences instead of cells directly: FALSE, but pointed at the real NANR format

Fully parsed `local 5` (RNAN/NANR) for species 25 from scratch, no outside
code, common 16-byte header + three blocks:

- **`KNBA` (ABNK, "Animation Bank")**: a 16-byte-aligned header of
  `num_sequences(u16)=20, num_elements(u16)=403, seq_array_ofs(u32)=24,
  elem_array_ofs(u32)=344, elem_array_end(u32)=3568` (block-relative, all
  three offsets pinned exactly: the sequence array's 20 x 16-byte records
  span bytes [24, 344) and the element array's 403 x 8-byte records span
  [344, 3568) -- `344 + 403*8 == 3568` exactly, confirming the field
  layout, not a guess). Each **sequence record** (16 bytes):
  `elem_start(u32), num_frames(u16), element_type(u16)=1 constant,
  stride(u32)=2 constant, unk(u32)` -- `elem_start` is an **index** (not a
  byte offset) into the element array, `num_frames` selects how many
  consecutive elements to read from there. Each **element record** (8
  bytes): `value(s32), six(u16)=6 constant, sentinel(u16)=0xBEEF` -- the
  same `0xBEEF` marker NMCR's header and NMAR's `table_b` both carry,
  confirming it is a general Nitro-resource validity tag, not
  format-specific.
- **`LBAL`**: 20 name-offset entries into a string table holding
  **the exact same 20 body-part names** as the paired NCER's LBAL (`atama`,
  `kuti01`, `karada`, `mimi01`, `mimi02`, `o`, `te01`, `te02`, `asi01`,
  `asi02`, and the `_2` set) -- confirmed by direct string dump, not
  inferred. This means NANR's 20 sequences are keyed by the **same
  body-part vocabulary** as NMCR's nodes, one sequence per named part.
- **`TXEU`** (12 bytes): not decoded, too small to matter (likely a
  metadata/checksum trailer).

**Reading the element values**: they are small non-negative integers (0,
8, 16, 24, 16, 8, 0, 0, 0, ...; later sequences reach up to ~224) that form
smooth triangle-wave-shaped runs when read in element-array order --
**this is a translation curve (most likely a Y-bob/idle-sway offset in
pixels), not a cell index**. Cell indices in this rig only range 0-10 (11
cells); element values exceed that range immediately. Sequences for
`asi01`/`asi02`/`asi01_2`/`asi02_2` (the feet) have `num_frames=0` -- an
empty curve -- which is physically sensible (feet don't bob during an idle
animation the way ears/head do). **Conclusion: hypothesis (b) is false as
stated** (NMCR nodes do not indirect through NANR to select a cell -- NCER
cell selection is NMCR's own `cell_index` field, confirmed correct below).
What NANR actually is: **a per-named-body-part translation-curve table**,
the genuine "animation" content this project has been looking for since
the fifth pass -- previously guessed to live in NMAR (the "multi-cell
*animation*" resource by name), but the byte evidence points at NANR
instead (NMAR's 107-byte file is too small to hold curves like these; NANR's
5324-byte file has exactly the right shape and its LBAL names line up with
the rig's own body parts). **This pass did not apply these curves to the
render** (frame 0 of every curve reads as the curve's own starting value,
which for most sequences is 0 or close to it, consistent with "frame 0 is
close to the un-animated rest pose" -- but this was not proven by actually
adding the values in and checking, which is flagged as the clearest next
step, not done here for lack of remaining budget in this pass).

### Hypothesis (a) revisited -- NMCR (x, y): literal per-node OAM offsets, re-tested and re-confirmed to scatter; a new "absolute anchor" reading tried instead

Re-ran the sixth pass's `apply_node_offset=True` (sum NMCR node (x, y) onto
every OAM's own cell-local (x, y)) and `apply_node_offset=False` (use OAM
coordinates directly, ignore NMCR (x, y) entirely) and actually **rendered
and visually inspected both** (`build/assets/rig/test_sum.png` /
`test_nosum.png` during this pass, not committed -- gitignored `build/`).
Both are scattered fragments with no coherent silhouette, matching the
sixth pass's description exactly -- this re-confirms hypothesis (a) as
literally stated (OAM coordinates are already-meaningful cell-local
offsets, and NMCR (x, y) is an *additional* delta on top of them) is wrong,
or at least insufficient on its own.

Byte-level re-verification of the NMCR node array (species 25, `label(s16),
x(s16), y(s16), tag(u8)=0x20, cell(u8)`) confirms the parser is reading it
correctly (hand-decoded the raw hex against the struct-parsed values,
exact match) and turns up something the fifth/sixth passes only estimated:
**`cell_index` is *exactly* `(node_position_in_array + 1) mod 10`** for
every one of the 19 records, verified byte-for-byte -- record 0 (label
`te01`) has `cell=1`, record 1 (`kuti01`) has `cell=2`, ..., record 9
(`te02_2`) has `cell=0`, then the pattern repeats for records 10-18. This
is **not** a per-body-part-meaningful assignment; it is the *position in
the file*, offset by one, with no correlation to the label. Whether this
literal field is actually used by the real game renderer to pick a cell,
or whether cell selection instead happens through some other means this
pass didn't find (e.g. a lookup keyed by label, or the NANR sequence index
doubling as a cell selector) is now the single biggest open question --
this pass used the recovered field at face value (it is what the file
contains) but flags that its rotation-only pattern is suspicious.

**New reading tried**: the node (x, y) values, sorted by node, order
**exactly top-to-bottom by real body-part height** for species 25 (`mimi01`
-35, `mimi02` -35 -- ears, topmost; `atama` -24 -- head; `te01`/`te02_2`
-19 -- hands, mid; `o` -9 -- tail; `karada`/`asi01`/`asi02` -5/-6/-6 --
body and feet, bottommost). This ordering only makes physical sense if
`(x, y)` is each part's own **final placement anchor in the assembled
figure**, not an incremental delta added on top of an already-positioned
OAM. Implemented as `compose_pose()`: for each node's cell, take the
bounding box of all its OAMs, find that box's **center**, and place the
whole cell (preserving every OAM's position relative to that center) so
the center lands exactly at the node's `(x, y)`. Tried four anchor
variants (bbox top-left, bbox center, x-center/y-top mixed, x-top/y-center
mixed) rendered and inspected directly; **bbox-center was the most visually
coherent of the four** (a denser, more centrally-clustered mass with
plausible top-to-bottom part ordering) and is what `compose_pose()` uses.

### Result: denser and more plausible, but not "recognizable" for any of the three species

Rendered `build/assets/rig/0025_pose.png` (47x58), `0001_pose.png` (58x44,
Bulbasaur -- same 11-cell/19-node/10-rest-pose-node rig shape as species
25, confirming the rig template is shared, not species-25-specific), and
`0150_pose.png` (89x87, Mewtwo -- 21 cells, 39 nodes, 20-node rest pose,
exactly double species 25/1's counts, consistent with a bigger/more
detailed model using the same rig format). All three show a **denser,
more centrally-massed cluster of correctly-colored, correctly-shaped
fragments** than any previous pass's render -- a real improvement -- but
**none clears the "recognizable creature silhouette" bar**: they read as
a cloud of body-colored blocks with a plausible-looking rough top/bottom
split, not a clean, identifiable Pikachu/Bulbasaur/Mewtwo outline. This
was checked by direct visual inspection of all three renders (upscaled
8x, nearest-neighbor), not inferred from pixel statistics.

### Hypothesis (c) -- NMAR/NANR per-frame transforms applied on top of rest pose: NANR's curves exist (see above) but were not applied; NMAR's remain unfound

NMAR's `KNBA`/`ANBK` block was re-examined and nothing new was found beyond
the sixth pass's writeup (`table_a`/`table_b`/`table_c` small fixed
regions, no room in the 107-byte file for real per-frame curve data). The
per-part curves this pass actually found live in **NANR**, not NMAR (see
hypothesis (b) above) -- so hypothesis (c) is **partially right about the
existence of per-node transform data**, but wrong about which file holds
it, and this pass did not get to actually summing a NANR curve value onto
`compose_pose()`'s placement to see whether frame 0 of the curve changes
(likely improves, or at least changes) the render.

### `tools/assets/rig.py` changes this pass

- **`compose_pose(ncgr, ncer, nodes)`** (new): the bbox-center-anchor
  strategy described above. This is now the function `main()` uses for the
  canonical pose render; the sixth pass's `compose_rest_pose()` (sum /
  no-sum toggle) is kept unchanged for reference/comparison, not deleted.
- **`--pose`** (new flag): explicit opt-in for pose rendering in
  single-species mode (parity with `--all`'s implied pose rendering);
  single-species mode's default behavior (contact sheet + pose, unless
  `--cells-only`) is unchanged, so this is additive, not a breaking change.
- **`--all`** (new flag): iterates every species/form block index in the
  archive (`n.file_count // 20`, no explicit species argument needed) and
  writes `build/assets/rig/NNNN.png` for each (pose only, no contact
  sheet, to keep batch runtime and output volume down). Run end-to-end
  over the whole `a/0/0/4` archive this pass: **712 of 714 slots render
  without error, 2 fail cleanly** (species 712/713, the archive's trailing
  5 sub-files beyond `714*20=14280` don't form a complete 20-entry block --
  `14285 % 20 == 5` -- so the last block index that starts within-bounds,
  713, reads past the real data and hits an NCGR/NCLR block-magic
  mismatch; caught and skipped with a clear message, not a crash). This is
  strong evidence the parser generalizes across the whole species/form
  roster, not just the three species this pass eyeballed.

### What remains after this pass

- **The mission's "recognizable Pikachu" bar is still not met**, for
  species 25 or either of the two additional species checked. This is the
  single biggest open item.
- **NANR's per-part translation curves were decoded but never applied**:
  the natural next experiment is adding each rest-pose node's matching
  NANR sequence's frame-0 element value onto that node's placement (via
  the shared label vocabulary -- NANR sequence `i` and NMCR node with
  `label_index == i` refer to the same body part) and re-rendering, to see
  whether it changes (hopefully improves) the silhouette. Not done this
  pass.
- **`cell_index`'s literal-rotation pattern (`position + 1 mod 10`) is
  now confirmed byte-exact but its real role is more suspicious, not
  less** -- a field that always equals its own array position plus one is
  either (a) genuinely how the game picks cells (the rig's cells simply
  happen to be authored in body-part order with a one-slot rotation, which
  is possible but unverified) or (b) not the actual cell-selection
  mechanism at all, with the real one still unfound. Comparing this field
  across several more species (beyond the 1/25/150 already loaded) for
  whether the rotation pattern *ever* breaks would help decide between the
  two.
- **The bbox-center anchor for NMCR (x, y) is empirically the best of six
  tried, not a confirmed-correct decode.** The physically-sensible
  top-to-bottom ordering of node y-values is real evidence, but is also
  consistent with several other placement schemes this pass didn't try
  (e.g. anchoring each cell at its first OAM specifically rather than its
  bbox center, or a coordinate system with a different origin/scale
  entirely).
- The second `mc_entries` multi-cell variant (species 25: nodes roughly
  `[7:15]` per the `(0, 7, 8, -19, 32)` descriptor tuple, not confirmed) is
  still unused by `compose_pose()`; rendering and comparing it against the
  first might help disambiguate the placement question.
- `local 8`/`local 17`'s unrecognised raw blobs and NMAR's own unresolved
  `table_a`/`table_b`/`table_c` fields (sixth pass) remain undecoded.
- The two `--all` boundary failures (species 712/713) were not
  investigated beyond confirming they fail cleanly and are consistent
  with `14285 % 20 == 5` leftover sub-files at the end of the archive.

## Eighth asset lane pass: NANR's frame-entry/frame-data split confirmed exactly; NMCR's mission-proposed layout re-tested and rejected; pose still not recognizable

Mission: re-parse species 25's rig against a supplied generic NNS_G2D
structural sketch (NANR frame entries distinct from indirected frame-data
records with three type-keyed shapes; NMCR multi-cell header and node
record in a specific proposed layout) and pose species 25/1/150. Every
claim below was checked against raw bytes this pass, not assumed from the
mission text. **Result: one major structural correction landed and is now
load-bearing (NANR), one proposed structure was tested and found not to
match this game's bytes (NMCR node layout), and the "recognizable
creature" bar from the fifth pass onward is still not met for any of the
three species** -- reported directly, per this project's practice.

### NANR: the mission's frame-entry/frame-data split holds, confirmed with a fixed-point tell

The seventh pass read NANR's 8-byte element-array records as raw curve
samples (`value(s32), six(u16)=6 constant, sentinel(u16)=0xBEEF`). This
pass re-scanned **all 403 element records** (not a sample) for species 25
and found the seventh pass's "six" field actually **varies** (2, 3, 4, 6,
12, 36, 50, 84, ...) while `sentinel` really is `0xBEEF` in every single
record. That is exactly the mission's frame-entry shape
`{offset_to_frame_data(u32), duration(u16), pad(u16)=0xBEEF}` -- the
"value" field is a byte offset, not a sample, and "six" is a real duration.

`offset_to_frame_data` is relative to the byte immediately after the
element array (`elem_array_end`, confirmed exact: species 25's 403 offsets
range `0..1480`, and `elem_array_end` to the body's real end is exactly
1496 bytes -- `1480 + 16 == 1496`, the largest offset's record lands
exactly on the boundary). The frame-data record it points to decodes
cleanly as the mission's **type-1 SRT shape** (`cellIdx(u16), rotZ(u16),
sx(s32), sy(s32), px(s16), py(s16)`, 16 bytes): `sx`/`sy` read **4096** in
the large majority of records, and `4096 == 1<<12` is the identity scale
in NNS_G2D's standard FX32 20.12 fixed-point format -- a format-specific
tell, not a coincidence, and strong confirmation this is really an
SRT-shaped animation record. `px`/`py` read as small values (0-3 for
species 25's rest-pose nodes) forming the same triangle-wave shape the
seventh pass already noticed, now correctly attributed to the *frame-data*
`py` field rather than the element array's raw bytes (which were actually
the offsets pointing at it). 315 of 403 offsets are 16-byte-aligned; most
of the rest are 8-byte-aligned, consistent with some sequences using the
mission's second, 8-byte type-2 "T" shape instead -- not disambiguated
this pass (the sequence-record field that should select it reads constant
across all 20 of species 25's sequences). Full byte-level writeup, field
by field, in `tools/assets/rig.py`'s module docstring.

**This is now applied, not just decoded**: `compose_pose()` takes an
optional `nanr` argument and adds each rest-pose node's own NANR sequence's
frame-0 `(px, py)` onto the node's NMCR `(x, y)` before placing the cell --
the seventh pass's hypothesis (c), never actually executed until now. The
deltas are mostly `(0, 0)` or a pixel or two, so the rendered poses for all
three species are visually almost unchanged from the seventh pass's
(dimensions identical to the pixel: `0025_pose.png` still 47x58,
`0001_pose.png` still 58x44, `0150_pose.png` 89x86 vs. previously 89x87 --
a one-pixel bbox difference from the small deltas, nothing more). This
confirms frame 0 really is at or near the rest position, as assumed.

### NMCR: the mission's proposed node layout was tested against raw bytes and rejected; the existing reading is re-confirmed correct

The mission proposed `{cellAnimIdx(u16), nodeAttr(u8), pad(u8), posX(s16),
posY(s16)}` per node (8 bytes). This pass decoded species 25's 19 node
records under that exact layout, byte for byte, and compared against the
sixth/seventh pass's `{label_index(s16), x(s16), y(s16), tag(u8)=0x20,
cell_index(u8)}` reading. **The mission's layout produces nonsense on this
data**: its `posY` (the raw bytes at offset 6-7 as one s16) evaluates to
`32, 288, 544, 800, 1056, ...` across successive nodes -- transparently
just the existing reading's constant `0x20` tag byte (low byte) and its
rotating `cell_index` 0-9 (high byte) reinterpreted as one 16-bit number,
not a plausible small-sprite pixel position. The existing reading's own
`x`/`y` (the same two bytes, read as two separate s16 fields) are the ones
that order top-to-bottom by real body-part height (ears highest, feet
lowest, matching species 25's actual anatomy) -- **re-confirmed correct,
not re-derived from scratch**, by directly testing the alternative and
watching it fail. The multi-cell descriptor array's byte size was also
re-checked against the mission's proposed 12-byte `{numNodes, numCellAnim,
flags, pad, offset}` struct: the gap between the descriptor array and the
node array in species 25's NMCR is exactly 20 bytes for 2 entries, which
is only consistent with the **existing 10-byte stride**, not 12 -- another
mission-proposed field count tested directly against file geometry and
rejected. **Conclusion: the mission's abstract description (an index field,
then placement data) is directionally right, but the concrete on-disk
field order/sizes for this game's NMCR are not the generic layout as
given.** Nothing in `rig.py`'s NMCR parsing changed as a result -- the
existing reading was re-verified, not replaced.

### Cell selection: NANR's frame-0 `cellIdx` tried as a replacement for NMCR's own `cell_index`, and rejected

Now that NANR's frame-data `cellIdx` field is properly decoded, this pass
tried using it (via `node.label_index -> NANR sequence -> frame 0 ->
cellIdx`) as an alternative to NMCR's own suspicious "`position + 1 mod
10`" `cell_index` byte (flagged as suspicious since the seventh pass).
**It does not work as a replacement**: for species 25's 10 rest-pose nodes,
NANR's frame-0 `cellIdx` reads `10` for 7 of the 10 (i.e. most "different"
body parts would draw the identical cell), which cannot be the real
per-node cell selector for an assembled figure with visually distinct
parts. `compose_pose()` therefore still uses NMCR's own `cell_index` byte
for cell selection; NANR only contributes the small `(px, py)` position
delta described above. NMCR `cell_index`'s literal-rotation pattern
remains unexplained, now doubly so (it is still the *only* field that
produces plausible per-node cell variation, despite looking suspiciously
positional).

### Placement formula: the mission's literal sum formula re-tested a third time, still scatters

The mission's placement formula (`node.posX + data.px` summed directly
onto each OAM's own hardware `(x, y)`, cell origin used as-is, no
re-centering) was re-implemented exactly as stated and re-rendered for
species 25 this pass. **It reproduces the same scattered, non-coherent
arrangement the sixth and seventh passes already found** for the "raw sum"
strategy -- now confirmed a third time, on the byte-corrected NANR/NMCR
data, ruling out "the earlier scatter was just a decode bug in NANR or
NMCR" as an explanation. The seventh pass's bbox-center-anchor strategy
(place each cell's OAM-bounding-box center at the node position, keeping
every OAM's offset from that center) remains the best-looking result of
every strategy tried across three passes now and is what `compose_pose()`
uses; a position-index-based cell reassignment (cell `i` for rest-pose node
`i`, instead of the stored rotating `cell_index` byte) was also tried this
pass as a quick check and produced a different but equally non-recognizable
arrangement, not adopted.

### `tools/assets/rig.py` changes this pass

- **`Nanr` class + `parse_nanr()`** (new): parses the ABNK header, sequence
  array, frame-entry array, and frame-data region; `frame_entry()` and
  `frame_data_srt()` expose frame-0 (or any frame) lookups by sequence
  index.
- **`compose_pose(ncgr, ncer, nodes, nanr=None)`**: new optional `nanr`
  parameter; when given, adds each node's NANR frame-0 `(px, py)` onto its
  NMCR `(x, y)` before the existing bbox-center-anchor placement. `main()`
  and `render_one()` both load NANR (local index 5) best-effort (wrapped in
  try/except so a missing/malformed NANR degrades to the seventh pass's
  behavior rather than crashing) and pass it through.
- Module docstring gained two large new sections (NANR corrected format,
  NMCR re-verification against the mission's proposed layout) documenting
  every claim above at the byte level.

### What remains after this pass

- **The mission's "recognizable creature" bar is still not met**, for
  species 25, 1, or 150 -- unchanged from the seventh pass's honest
  assessment, now re-confirmed after two more structural corrections
  (NANR fully wired in, NMCR's alternative layout ruled out) rather than
  merely re-asserted.
- **NMCR `cell_index`'s real selection mechanism is still unresolved**,
  and is now the single most concrete open item: it is confirmed to be
  the *only* field among everything decoded so far (NMCR's own fields,
  NANR's frame-data `cellIdx`) that produces plausible per-node cell
  variation, yet its `position + 1 mod 10` pattern is still suspicious.
  Comparing it across more species, or looking for a third, still-unfound
  indirection (a literal "cell-animation array" inside the multi-cell
  descriptor that the mission's pipeline describes but this project has
  not located the bytes for) is the most promising next step.
- **NANR's second/8-byte frame-data shape (type 2 "T") is not
  disambiguated from type 1 (SRT)**: this tool always tries the 16-byte
  shape; the ~22% of frame entries whose offsets are 8-aligned but not
  16-aligned are silently misread as truncated/misaligned 16-byte records
  rather than correctly as 8-byte ones. Not yet load-bearing for species
  25's rest pose (frame 0 of every *used* sequence in this pass's render
  happened to decode with sane-looking 16-byte values) but a real gap.
  Type 0 (`{cellIdx}`, 2 bytes) remains entirely unexercised.
- The multi-cell descriptor array's own fields beyond node-count (its
  first 10-byte entry's other four values, and the second entry's
  9-node span) remain undecoded; the mission's proposed 12-byte struct
  for this was tested and ruled out this pass (see above), but nothing
  new was found in its place.
- `local 8`/`local 17`'s unrecognised raw blobs and NMAR's own unresolved
  `table_a`/`table_b`/`table_c` fields (sixth pass) remain undecoded.

## Icon archive `a/1/6/7`, decoded (`tools/assets/icons.py`)

This closes out the "Pokemon icons -- `a/1/6/7`" entry above with an
actual pixel decode. New files: `tools/assets/icons.py` (decoder,
renderer, round-trip) and `tools/assets/lz77.py` (a BIOS LZ77 encoder,
compress-only, written the same way `lz11.py`'s encoder policy was
recovered -- see below).

### Format

`a/1/6/7` is a 655-sub-file NARC:

| sub-file index | contents |
|---|---|
| 0 | RLCN/NCLR palette, uncompressed, 552 bytes |
| 1, 3 | RNAN/NANR (cell animation), uncompressed |
| 2, 4 | RECN/NCER (cell bank), uncompressed |
| 5..654 | 650 icon graphics, one per species/form slot (species index N is sub-file N+5), each **BIOS LZ77** (tag 0x10, not LZ11 -- confirmed by sniffing byte 0 of every one of the 650) |

Every one of the 650 icon sub-files decompresses to exactly 304 bytes, and
the leading 48 bytes (the full NCGR common header + CHAR block header +
CHAR body sub-header) are **byte-identical across all 650** (checked, not
sampled). Only the trailing 256 bytes (8 4bpp tiles, 32 bytes each) vary.
The CHAR sub-header declares `tiles_y`/`tiles_x` unspecified (0xFFFF),
`bitdepth` 3 (4bpp, per this ROM's own convention), `tile_data_size` 256,
and a `tile_data_offset` of 24 that self-confirms where the tile data
starts.

256 bytes / 32-bytes-per-tile = 8 tiles. Laid out 4 tiles wide (32 px) by
2 tile-rows (16 px) tall: the right two tile-columns (tile indices 2, 3,
6, 7) are **the literal byte 0xCC repeated for all 32 bytes, in every one
of the 650 icons, with zero exceptions** (checked by scanning all 650) --
a fixed filler/padding tile, the same "known constant marks unused
canvas" pattern already used for the battle-sprite archive `a/1/3/4`'s
0x00/0x80 filler (`tools/assets/battle_sprite.py`), just a different
constant. The real icon is the left two tile-columns: **16x16 pixels,
4bpp** -- exactly the size estimated up front (16x16 4bpp = 128 bytes of
real tile data, the rest being the fixed filler). `icons.py`'s
`unpack_icon_pixels()`/`pack_icon_pixels()` implement this crop and its
exact inverse (used for the round trip).

### Palette: not a per-species bank system after all

The mission brief's working theory was "a small shared palette bank with
a per-species palette index." The palette *shape* looks right at first
glance -- sub-file 0's TTLP block declares the full 256-color capacity
(512 bytes of color data), which for a 4bpp format reads as "16 banks of
16 colors, select one bank per icon." Decoding the actual color words
(`struct.unpack('<256H', ...)`) shows this is not what is stored: **only 2
of the 256 color slots are non-zero** (slot 0 and slot 7, both BGR555
0x7FFF = white); every other slot, across all 16 nominal banks, is the
zero word (black). Banks 1-15 are entirely black -- there is no second
color anywhere to select between. This was cross-checked against the
known-good NCLR reader (the same `parse_nclr()` used and verified for
`a/1/3/4`'s battle-sprite colors), so it is a property of the data, not a
parser bug.

**Consequence: the icons in this archive are genuinely monochrome
(black/white), not full-color per-species icons.** `icons.py` renders
using the real decoded palette (bank 0) rather than a synthetic grayscale
ramp, which is the honest reading of "true color" once the recovered
palette itself turns out to carry only two colors.

**Per-species palette-index table: searched for, not found.** Every NARC
under `extract/data/` was scanned for a sub-file count in 640-660 with a
small, uniform per-entry size (the shape a one-byte/species bank selector
would have). Two matches, neither a fit:

- `a/0/2/0`: 650 entries x 2 bytes (u16), values range 0-649 and run in
  tight groups of 2-4 identical consecutive values (reads as an
  evolution-family/base-species index, not a palette selector -- max
  value 649 rules out "bank index" outright, a bank selector into 16
  banks would be capped at 15). Cross-checked directly: `a/1/6/7`'s icon
  content has large exact-duplicate groups (the biggest is 150 of the 650
  icons sharing pixel-identical tile data), and if `a/0/2/0`'s values were
  driving that reuse, the icons sharing a hash would share an `a/0/2/0`
  value too. They don't (98 distinct `a/0/2/0` values inside the 150-icon
  duplicate group) -- so `a/0/2/0` is not the icon-reuse key either,
  whatever it actually is.
- `a/1/2/3`: 650 entries but variable size (0-34 bytes), shape of a
  text/movepool table, not a fixed small record.

No 649/650/655-entry table of 1-byte records capped at 15 exists anywhere
in `extract/data/`. Given the palette itself has no second bank with real
color in it, this negative result is now expected rather than a loose
end: there is nothing for such a table to select between.

**Open honesty note:** the large icon-content duplicate groups (650 icons
resolve to only 454 distinct decompressed payloads; one group of 150 is
pixel-identical) are unexplained by anything decoded so far. Given the
monochrome palette finding, it is now uncertain whether `a/1/6/7` is
really "one icon per species" at all, or a smaller set of generic
silhouette/stencil shapes (reused across many species) meant to be
recolored or composited by whatever code loads this archive -- the two
NANR/NCER pairs at indices 1-4 are presumably involved in that but were
not decoded this pass (out of scope: this pass's budget went to the pixel
format and the round trip, not the cell/animation resources). Treat
"species index N -> sub-file N+5" as positional/structural fact (the
count and ordering match) but "this pixel data IS a recognizable
per-species icon" as unconfirmed.

### LZ77 encoder (`tools/assets/lz77.py`)

The icon sub-files are BIOS LZ77 (tag 0x10), not LZ11 -- `narc.py` already
decodes this, but only `lz11.py` had a matching encoder before this pass.
`lz77.py` was written the same way: decode an original compressed
sub-file, diff a candidate encoder's token choices against it. Recovered
policy, confirmed 650/650 exact over every LZ77 sub-file in this archive:

- greedy, no lazy matching (same as LZ11)
- matches may self-overlap (same as LZ11)
- displacement 1 is never used (same exclusion as LZ11)
- **longest match wins, ties broken toward the *farthest* displacement**
  (same tie-break as LZ11 -- "nearest wins" was tried first and produced
  wrong output on the very first sample checked)
- field limits per BIOS LZ77's plain one-byte-indicator token (no
  extended-length forms like LZ11 has): match length 3-18, window
  (max displacement) 0x1000

### Results

- **650/650 icons rendered** to `build/assets/icons/NNNN.png` (16x16 true
  color RGB PNGs, `NNNN` = species/form index 0000-0649).
- **655/655 sub-files round-trip byte-identical**: the 650 icon sub-files
  via decompress -> crop to 16x16 pixels -> re-pack (re-inserting the
  fixed filler tiles and fixed 48-byte header) -> `lz77.compress()` ->
  compared to the original raw sub-file bytes; the other 5 sub-files
  (palette + 2x NANR + 2x NCER) carry no compression header and round-trip
  as a trivial identity copy, verified via `narc.sniff_compression()`
  returning `None` for all of them. Run it yourself:
  `python tools/assets/icons.py --all --roundtrip`.
- **Remaining gaps:** no per-species full-color palette exists in this
  archive (see above -- this may mean full-color species icons live
  elsewhere, not here, and `a/1/6/7` is something else, e.g. a stencil/
  mask set); the icon-content duplicate groups are unexplained; the two
  NANR/NCER pairs (indices 1-4) are uncharacterized.

## Ninth asset lane pass: overworld sprite mission -- `a/0/0/4`/`a/0/5/2` confirmed as battle rigs, no confirmed overworld/trainer archive, but a full-color icon archive found (`tools/assets/overworld.py`)

Mission: with `a/0/0/4`/`a/0/5/2` established as the animated Pokemon
battle rigs (not overworld sprites, `tools/assets/rig.py`), find the real
overworld sprite archive -- expected shape: NCGR+NCLR+NCER+NANR bundles,
16x32/32x32 walk-cycle canvas, a few hundred to a couple thousand entries,
likely LZ11.

### Archive search

Every NARC under `extract/data/` was re-scanned for a **full** sub-file
magic histogram (not just the inventory's top-2-by-count summary), looking
for archives where NCGR, NCLR, NCER and NANR are all present together.
This surfaced a family of candidates the original inventory's coarse guess
had split apart. Two are documented here; several more (`a/0/8/3`,
`a/0/3/2`, `a/1/3/1`, `a/1/5/9`, `a/1/3/7`, and the rest of the "trainer/
item/UI sprites (guess)" / "small sprite/icon set (guess)" rows) were
opened and skimmed but not pixel-verified -- see "Ruled out, not
pixel-verified" below.

### `a/0/0/7` -- identified as a full-color per-species icon archive, NOT overworld sprites

`a/0/0/7` (779916 bytes, 1431 sub-files) is the closest structural match
to the mission's brief and is now fully characterized and rendered by
`tools/assets/overworld.py`:

    index 0        RLCN/NCLR   one shared palette, 48 colors (3x16-color
                                4bpp sub-palettes; every sampled OAM's own
                                attr2 pal bits are 0, but that is NOT which
                                sub-palette an entity's icon actually uses
                                -- see "Per-entity sub-palette selection"
                                below)
    index 1, 3, 5  RNAN/NANR   three byte-for-byte IDENTICAL copies of one
                                cell animation definition
    index 2, 4, 6  RECN/NCER   three copies of one 3-cell cell bank, each
                                declaring a different `mapping_type` (0, 1,
                                2 -- the standard NDS OBJ 1D tile-mapping
                                boundary: 32B/64B/128B stride) with each
                                cell's `tile_idx` scaled to match (e.g. cell
                                1 is tile_idx 16/8/4 in the three copies;
                                16*32 == 8*64 == 4*128, same byte offset).
                                Confirmed these are three encodings of ONE
                                cell bank, not three different ones.
    index 7..1430  RGCN/NCGR,  715 per-entity tile sheets (32 tiles/1024
                   (empty)     bytes of 4bpp data each, uncompressed),
                                mostly followed by one empty placeholder
                                sub-file (6 of 715 have no placeholder).

Every cell in the shared NCER is a plain 32x32 square OAM (shape 0, size
2) -- the mission's expected overworld canvas size. Rendering (every
cell of the shared NCER against one entity's own NCGR, `--sample`/`--all`)
produces clean, recognizable, **full-color small creature icons** -- not
human sprites. Entity 0 is a green background with a white silhouette mark
(the placeholder/no-Pokemon icon); entities 1 and 25 are each a distinct
small quadruped/bird creature.

**Correction (this pass): entity index IS National Dex number, and the
earlier "entity 1 is not Bulbasaur-green, entity 25 is not Pikachu-yellow"
call was an artifact of the sub-palette bug fixed below, not a real
mismatch.** With the correct per-entity sub-palette (see next section),
entity 1 renders unmistakably as green Bulbasaur, entity 4 as orange-red
Charmander, entity 7 as blue Squirtle, entity 25 as yellow Pikachu, etc.
-- rendered at 1..10 and 25 and cross-checked against `sub_0201BB5C`'s own
`idx = species` default case (see below), which settles it structurally,
not just by eye.

### Per-entity sub-palette selection (fixes the wrong-color bug)

The shared NCLR's 48 colors are 3x16-color sub-palettes, and which one a
given entity's icon uses is selected per entity, NOT fixed at 0 (every
sampled OAM's own attr2 pal bits are 0 regardless -- that field is a red
herring here). Rendering entity 25 with each of the 3 sub-palettes made
this obvious: sub-palette 0 is purple, sub-palette 1 is blue, sub-palette
2 is the unmistakably-correct yellow-and-red Pikachu.

The selector is a real, already-matched piece of code:
`sub_0201BB5C(species, form, half, isEgg)` in
`src/pending/unit_0201BB5C.c` (MATCH-capped, 0/224 differing bytes) reads
one byte of a packed-nibble table, `g_0209E474[idx]`, and returns the LOW
nibble if `half == 0`, the HIGH nibble if `half != 0`:

    idx = species                                      (the common case)
    idx = (species == 490 ? 1 : 0) + 650                if isEgg
    idx = first + form + 651                            if form != 0 and
                                                         not "hidden" (an
                                                         alternate-form
                                                         index, via
                                                         func_02019C90)
    return half ? (g_0209E474[idx] >> 4) & 0xF : g_0209E474[idx] & 0xF

`g_0209E474` (RAM 0x0209E474) is at `extract/arm9_dec.bin` offset
0x9A474 (`0x0209E474` minus the ARM9 static region's RAM base
`0x02004000`, from `layout/layout.json`'s `arm9.static.ram_start`/
`src_offset` -- the offset falls inside the static region, not an
autoload, so the mapping is a plain subtraction). Scanning the whole ROM
(ARM9 static + ITCM/autoloads, every overlay, every archive under
`extract/data/`) for a byte run of the right length whose values are
consistent with this session's eye-checked samples found exactly one
non-coincidental hit: this table, 99%+ of its first 712 bytes cleanly in
{0, 0x11, 0x22} (both nibbles equal -- i.e. `half` does not matter for
almost every species), confirming it independent of already knowing the
matched C source names it.

For `a/0/0/7`'s single static icon per entity, this pass always reads the
LOW nibble (`half = 0`; the high nibble is some other, unrendered, half
of the pair, plausibly a second recolor for a case this icon format
doesn't need). Because `idx = species` is the table's default case, and
`a/0/0/7`'s own entity index turns out to equal that same species/form
index for every sample checked, `overworld.py`'s
`load_subpalette_table()` just reads `g_0209E474[entity_index] & 0xF`
directly -- no remapping needed.

**Samples verified (species identified by eye, from the shape and
signature colors of well-known Pokemon, then cross-checked numerically
against the dominant non-outline pixel color at each candidate
sub-palette):** entities 1-10 (Bulbasaur/Ivysaur/Venusaur line -> 1,
Charmander/Charmeleon/Charizard line -> 0, Squirtle -> 0, Wartortle/
Blastoise -> 2, Caterpie -> 1 -- note the Squirtle line is NOT
sub-palette-uniform across its evolutions, ruling out a simpler
"per-family" rule), entity 25 (Pikachu -> 2), and a spread of
later/distinctive entries: 59 Arcanine -> 0, 65 Alakazam -> 2, 94 Gengar
-> 2, 130 Gyarados -> 0, 141 Kabutops -> 2, 143 Snorlax -> 1, 150 Mewtwo
-> 2. All 18 match `g_0209E474[entity]` exactly; renders written to
`build/assets/overworld/`.

**Remaining uncertainty:** the table's low-nibble run is clean (values in
{0, 1, 2}) for entity indices 0-711 with the exception of entities 592-593
(byte 0x10: low nibble 0, high nibble 1 -- a real, not garbage, gendered-
or form-split pair, per `sub_0201BB5C`'s `half` parameter). Entities
712-714, at the very end of the alternate-form block, read raw bytes
whose low nibble is out of range (0xA5, 0xDA) or otherwise unverified
(0x01); `load_subpalette_table()` falls back to sub-palette 0 for those
(printed as a warning), because `a/0/0/7`'s own slot order for the last
few alternate-form entries most likely stops lining up 1:1 with
`g_0209E474`'s own `first + form + 651` indexing right at the boundary --
not pursued further (3 of 715 entities, past this task's targeted
budget). Which specific alternate forms these are (i.e. resolving
`first`/`form`/`hidden` for the tail of the form block) is unresolved.

**This resolves an open gap from the icon-archive pass above.** `a/1/6/7`
(`tools/assets/icons.py`) decoded a 650-entry, monochrome (2-color)
16x16 icon set and explicitly flagged "no per-species full-color palette
exists in this archive... this may mean full-color species icons live
elsewhere, not here." `a/0/0/7` is a strong candidate for that "elsewhere":
715 entries (close to, not identical to, `a/1/6/7`'s 650 and `a/0/0/6`'s
733), full-color (real per-icon-relevant sub-palette, not a degenerate
2-color table), 32x32 (twice `a/1/6/7`'s 16x16), clean uncompressed NCGR.
Not confirmed as "the" canonical menu icon vs. some other UI role (e.g. a
Pokedex entry thumbnail) -- just confirmed as full-color Pokemon-shaped
icon content, not overworld human/trainer sprites.

### `a/0/7/2` (+ siblings `a/0/6/4`, `a/0/7/3`) -- ruled out: a trainer-card/UI badge rig, not overworld sprites

This 95-entry family (`a/0/7/2` 760 sub-files = 95 x 8; `a/0/6/4` and
`a/0/7/3` each 48 = 6 x 8) shares `a/0/0/4`'s battle-rig shape almost
exactly -- 2 LZ11 NCGR (small + main tile sheet) + NCER + NANR + NMCR +
NMAR + one small unrecognised 60-byte block + NCLR, per entry -- which
made it the best "compound poseable rig" candidate for a human overworld
actor. Composited with `rig.py`'s dense (`tile_idx * 32`) tile addressing
it rendered as unreadable red/black noise; re-tried with the NCER's own
**declared** `mapping_type` (1, i.e. `tile_idx * 64` byte addressing --
unlike `a/0/0/4`'s rig, this archive's stated mapping_type is NOT
overridden by dense addressing) it resolves to a coherent image: a green
background with a small rectangular plaque/text-like mark, read as a
trainer-card or badge-case UI icon, not a walking human figure. Ruled out
as the overworld archive; not pursued further (no `overworld.py` support
for this family's 2-block NCGR / mismatched LZ11 re-encode -- see below).

### Ruled out, not pixel-verified

Opened (full magic histogram only, no pixel render) and set aside as
poor structural fits for a per-entity human walk-cycle bundle:
`a/0/8/3` (172 subs, uneven per-group sub-file counts, not a clean
per-entity stride), `a/0/3/2` (97 subs: 16+16 flat NCGR blocks each
followed by a separate run of NCER/NANR pairs -- reads as a multi-state
UI component, e.g. a cursor or gauge, not per-entity sprites), and the
remaining "trainer/item/UI sprites (guess)"/"small sprite/icon set
(guess)" archives that mix in `NSCR` (screen/map data) at scale --
`a/0/9/5`, `a/1/5/9`, `a/1/3/7` -- which read as tileset/map bundles, not
character sprites.

### `tools/assets/overworld.py` -- deliverables against `a/0/0/7`

- **10 sample renders + `--all`**: `python tools/assets/overworld.py
  --sample` (10 entities spread evenly across the archive) and `--all`
  (every entity) both write true-color `build/assets/overworld/NNNN.png`,
  each now using that entity's own correct sub-palette (see "Per-entity
  sub-palette selection" above; previously every entity was hardcoded to
  sub-palette 0, which is wrong for most of them). `--all` result:
  **715/715 entities rendered, 0 skipped** (713 with the table-verified
  sub-palette, 2 falling back to sub-palette 0 -- see "Remaining
  uncertainty" above).
- **NCGR round trip**: `NcgrFile.encode()` re-serializes every header
  field (tile_num_x/y, bitdepth, pad, flag, unk1, data_ofs, tile data) back
  to the exact original bytes, with an LZ11-recompress path (via
  `lz11.compress()`) for any compressed entry (none exist in `a/0/0/7`
  itself, but the code path is present and exercised against other
  archives, see below). `python tools/assets/overworld.py --verify`
  result: **715/715 NCGR sub-files round-trip byte-identical.**
- **Cross-check against the sibling family**: `--verify --archive
  extract/data/a/0/6/4` (and `a/0/7/2`) does **not** round-trip (0/48 and
  0/760) -- those archives' NCGR sub-files have a second block this
  module's single-block (`RAHC`-only) `NcgrFile` doesn't parse, and even
  the single-block half of each entry (the 60-byte non-NCGR block) isn't
  attempted; not pursued since that family was ruled out as UI content,
  not overworld sprites. `overworld.py`'s round trip is only claimed,
  and only verified, against `a/0/0/7`.

### Remaining gaps

- **The overworld/trainer/player walking sprite archive is still not
  located.** This pass's search covered every NARC with NCGR+NCLR+NCER+
  NANR all present at any scale (full histogram, not just top-2 magics)
  and rendered the two best structural candidates; neither is a human
  figure. It remains possible the real archive is LZ11-compressed in a
  way that hid it from the histogram scan (compressed sub-files don't
  expose their post-decompression magic without actually decompressing
  every sub-file of every NARC, which this pass's scan did not do
  exhaustively -- only the uncompressed-magic + "has a compression header"
  count was checked per archive), or that it does not use the simple
  flat NCGR+NCER+NANR shape at all (e.g. a compound rig like `a/0/0/4`'s,
  reusing body parts the way the battle rigs do, which would need the same
  unresolved NMCR/NMAR placement work documented in the seventh/eighth
  passes above before it could be composited correctly).
- `a/0/0/7`'s entity-index-to-species mapping is now confirmed as National
  Dex order (entity index == species number, matching `sub_0201BB5C`'s
  `idx = species` default case -- see "Per-entity sub-palette selection"
  above), for every entity checked; the last few entries in the
  alternate-form block (roughly entities 712-714) are not confirmed. The
  shared NCER's animation semantics (which of the 3 cells plays when, and
  for how long) live in the NANR block, which this pass parsed only past
  its 16-byte common header + ABNK sub-header (`num_anim`,
  `element_type`) -- the frame-duration/ordering fields inside are not
  decoded, so `overworld.py`'s "sprite sheet" is "every distinct cell this
  entity's shared cell bank defines," not a verified real-time animation
  sequence.
- `a/0/7/2`'s family (95+6+6 = 107 entries) is characterized only well
  enough to rule it out (mapping_type-correct single-frame render); its
  NMCR/NMAR blocks, second NCGR block shape, and the unrecognised 60-byte
  per-entry block are not decoded.

## `a/0/0/6` wrapper cracked: not a human figure, likely reclassify

New asset-lane pass, scoped to cracking the `" APS12_1"` wrapper in
`a/0/0/6` from the data side, per the earlier passes' deferred gap (see
"Trainer sprite wrapper: first look" above). New tool: `tools/assets/
trainer.py`. Samples used: sub-files 0, 1, 100 (already extracted to
`build/assets/aps_0.bin` / `aps_1.bin` / `aps_100.bin` by an earlier pass).

### Structure fully recovered

The outer `" APS12_1"` header's second u16 field (offset 0x0A) is **the
exact count of embedded `" TPS"` sub-chunks** -- verified by literally
scanning each sample for the 4-byte tag `b" TPS"` and counting hits: 1 for
sub-file 0, 2 for sub-file 1, 8 for sub-file 100, matching that field's
value on all three samples exactly. This is a real, previously-undocumented
nested-chunk structure: `" APS12_1"` is a small container, not a flat
wrapper around one payload.

Each `" TPS"` sub-chunk has a fixed 36-byte header (magic + 8 `u32`
fields), then a small unresolved sub-table (`u32` at header offset +0x10
gives its length, varies ~0x14-0x1C across samples, not decoded), then
**exactly 1024 bytes of pixel data, a constant across every one of the 8
frames sampled** -- the same "fixed-size canvas per frame" convention
already seen in the battle-sprite archive's constant 0x20000 LZ11 payload
(see "Battle sprite archive" above), just at a much smaller, icon-sized
scale. Chunk boundaries are found by re-scanning for the next `" TPS"` tag
rather than trusting the header's own size fields, which are internally
inconsistent on the last frame of a multi-frame sample (see `trainer.py`'s
docstring for the exact discrepancy, a few bytes, harmless to decoding).

**Palette, confirmed on all three samples**: the **last 32 bytes of the
whole sub-file** are a raw 16-entry BGR555 palette, shared by every frame
in that sub-file. All 16 `u16` entries have bit 15 clear (valid BGR555) on
every sample -- not something random bytes would do. Sub-files 0 and 1
both carry a nearly-empty palette (every entry zero except index 14 =
white `0x7FFF`); sub-file 100 carries a full 14-color palette from index 2
onward (skin/hair-tone-like spread of R/G/B values 0-31, plausible real
color data, not noise).

### Pixel format: NOT 2-pixels-per-byte 4bpp

The obvious first guess -- pack the 1024-byte frame as tiled or linear
4bpp (2 pixels/byte), matching `a/1/3/4`'s battle-sprite layout -- was
tried at every width from 32 to 128px, tiled and linear, both nibble
orders: **every one produces pure vertical-stripe noise**, no coherent
shape at any width. What does work: treat each frame as a **32x32
canvas, one byte per pixel, where only the HIGH nibble carries a 4-bit
palette index (0-15)**. Evidence:

- The low nibble of every pixel byte, across all three samples, only ever
  takes the value `0x0` or `0x8` -- a 1-bit flag, not extra color
  resolution (the same 0/8 duality the battle-sprite archive's filler
  pattern showed, see "Payload format" above).
- Autocorrelation on an isolated single-frame payload (sub-file 100,
  frame 0, byte-granularity, not nibble-split) peaks cleanly at **stride
  32 bytes** (match score 0.70, next-best non-harmonic candidate 0.63,
  with a harmonic at 64) -- independent confirmation of the 32-pixel row
  width, found before any visual check.
- Rendering with this interpretation (`tools/assets/trainer.py`) produces
  **clean, unambiguous, non-noise shapes** for all three samples: sub-file
  0 is a thin, vertically-symmetric spindle/glint silhouette (matches its
  near-empty white-only palette); sub-file 1 renders a 4-point sparkle
  shape in one frame and two ring/reticle-like shapes in the other; every
  one of sub-file 100's 8 frames renders as the same filled circular blob
  (peach/skin-toned per its recovered palette) -- consistent with a short
  looping animation of one simple shape, not 8 distinct trainer poses.

### Renders

`python tools/assets/trainer.py 0`, `1`, `100` (also `--all` for the
full 733, best-effort) write real-color 24-bit RGB PNGs to
`build/assets/trainers/NNNN_fF.png` using the recovered palette. All
1 + 2 + 8 = 11 frames across the three requested samples decoded without
error.

### What this means for `a/0/0/6`'s identity

**None of the three sampled entries show a human silhouette.** Given
`a/1/3/4`'s "battle sprite" guess was separately overturned in a later
pass (see "Species-icon archive" / 16bpp-direct-color findings elsewhere
in this document for the general lesson that file-count-matches-species-
or-trainer-count is weak evidence on its own), `a/0/0/6`'s "trainer
sprite" label should be treated the same way: **plausible but not
re-confirmed**. The three rendered shapes (a glint/spindle, a sparkle
plus two rings, an 8-frame pulsing circle) read much more like a small
**animated particle/effect/icon archive** (33x32 canvas, cheap to
animate, no need for per-trainer detail) than full-body trainer
portraits. 733 sub-files is still consistent with "one per trainer class"
for some *other* per-trainer resource (a battle-intro glint effect? a
name-tag icon?), or could be unrelated to trainers entirely. Not
re-audited against a trainer-class list or cross-checked against other
candidate archives in this pass -- flagged as open for whichever lane
picks this up next.

### Loader: still not found, now searched more broadly

Repeated and extended the previous lane's loader search: grepped the
raw decompressed overlay binaries (`extract/overlays_dec/*.bin`, all 237)
and the three ARM9 images (`extract/arm9.bin`, `arm9i.bin`, `arm9_dec.bin`)
for the literal bytes `" APS"`, `" TPS"`, and the `" TPS"` chunk's constant
tag field `0x00010221` (as a raw little-endian `u32`) -- **zero hits
anywhere**, in either binary form (this pass searched raw bytes directly,
not just `asm/*.s` disassembly text as the previous lane did, so this is
a strictly broader negative result). Combined with the previous lane's
null result grepping `asm/arm9/src` and `src/matched` for the NitroFS
file id, sub-file count, and path string: no candidate loader location
has been found by any text or byte-level search across the whole
extracted ROM image. Either the comparison is done byte-by-byte (no
contiguous magic constant to find), the loader lives in a not-yet-
decompressed/extracted resource, or (as generally suspected for custom
Game Freak wrappers) the magic is trusted from context and never actually
validated by code -- tracing NitroFS file-id-to-archive resolution
generically, as the previous lane suggested, remains the only untried
approach.

## Text banks: located, container format solved, cipher solved, one gap remains

This closes out the "Text banks -- uncertain, several candidates, none
confirmed" item from the section above. New tool: `tools/assets/text.py`
(stdlib only, depends only on `narc.py`). Full technical writeup (format,
cipher derivation, dictionary-compression gap) lives in that file's
module docstring; this section is the summary and the honest status.

### The previous candidates were wrong; the real archive is `a/0/0/2`

`a/0/5/7` and `a/0/6/6` (the automated heuristic's top picks, see "Where
things probably live" above) were checked directly and ruled out: their
sub-files are fixed- or near-fixed-stride binary record tables (checked
by scanning for a monotonic-offset-table signature with varied deltas,
the fingerprint of real variable-length string data -- neither archive
has any sub-file matching it). A full-ROM sweep for that same signature
(every NARC, every sub-file 1.5-80 KB, offset-table starts every 4 bytes
up to +64, requiring at least 5 distinct delta values across 100+
monotonic entries) found it in exactly one place: **`extract/data/a/0/0/2`**
(288 sub-files, previously miscategorised "scripts/data tables (guess)"
because it has far fewer than the ">500 sub-files" the old heuristic
required for a "text bank" guess -- a/0/0/2 instead packs *many banks per
NARC*, one per sub-file, which the count-based heuristic couldn't see).

### Message-file container format (confirmed against real bytes)

Each `a/0/0/2` sub-file that holds text is a self-contained "message
file" with a 16-byte header, matching the project brief's hypothesis
shape closely:

| offset | field | notes |
|---|---|---|
| 0x00 | u16 sectionCount | always 1 in every sub-file sampled |
| 0x02 | u16 entryCount | number of strings in the bank |
| 0x04 | u32 sectionSize | == sub-file size - 16 |
| 0x08 | u32 reserved | always 0 |
| 0x0C | u32 section_offset[0] | always 16 (sectionCount is always 1) |

Followed by `entryCount + 1` 8-byte descriptors (`u16, u16, u32`) starting
at `section_offset[0]`. The first u16 is NOT this entry's own char count
as the naive hypothesis reading would suggest -- empirically it always
equals the *previous* entry's decoded length in UTF-16 units (confirmed
across dozens of entries), an off-by-one quirk this reader doesn't rely
on. The second u16 is a per-*file* constant (e.g. 60, 84, 118, 256 --
varies by sub-file, never by entry within one); its meaning is
unresolved and unneeded. The u32 is the real, useful field: an absolute
byte offset (from the start of the sub-file) to that entry's raw UTF-16
code-unit stream. Descriptor 0 is a sentinel (its "char count" field
actually holds `sectionSize`); real strings are descriptors 1..entryCount-1,
and a string's byte length is simply `offset[i+1] - offset[i]`.

Verified with `entryCount` matching Black/White's known category sizes
(species 649+1, moves 559+1, items, abilities 164+1, types 17):

| category | entryCount | sub-file indices in a/0/0/2 |
|---|---:|---|
| species (name-shaped entries) | 650/652 | **70**, 284 (near-duplicate banks); 235, 236, 260 are the same ~650 count but with much longer per-entry text (Pokedex flavor text, not decoded by this pass); 281 looks like a non-text per-species data table |
| moves | 560 | **203**, 286 (name-shaped); 202 (0% clean, likely move flavor text) |
| items | 627 | **279**, 280 |
| abilities | 165 | **170**, **182**, 183, 285 |
| types | 17 | 81, 199 (lowercase, mid-sentence form), **287** (confirmed: entry 13 decodes to `ELECTRIC`, the 13th type in the standard Normal/Fighting/.../Electric ordering) |

(Bold = the sub-file index this pass's dumps actually use.)

### The cipher (confirmed by direct key recovery, not guessed)

Each string is a stream of u16 LE code units XORed against a 16-bit key
that starts at a per-string value and **rotates left by 3 bits after
every code unit**, terminated by the hypothesised `0xFFFF`. Found by
brute-forcing every `(initial_key, rotate_amount)` pair against real
entries and requiring the decode to end in `0xFFFF` and otherwise be
printable ASCII: rotate-by-3 is the only amount that ever produces a hit,
and it produces genuine, unambiguous English Pokemon names (sub-file 70
entry 19 -> `Pidgeot`, entry 51 -> `Diglett`, entry 54 -> `Persian`,
entry 100 -> `Kingler`, entry 136 -> `Jolteon`, etc. -- full list in
`build/assets/text/species.txt`; move-bank sub-file 203 turns up clean
tails of `Lock-On`, `Amnesia`, `Confuse Ray` fragments, etc.).

Because the key rotates by a small fixed amount and the *last* unit is
always the known constant `0xFFFF`, the per-string key does not need
brute forcing at decode time -- it is solved for directly, backwards from
the terminator:

```
key[n-1] = word[n-1] XOR 0xFFFF
key[0]   = rotate_right_16(key[n-1], 3*(n-1))
key[i+1] = rotate_left_16(key[i], 3)
plain[i] = word[i] XOR key[i]
```

implemented in `decode_units()` / `encode_units()` in `tools/assets/text.py`.

### Round trip: 100% byte-identical on every fully-decoded entry

`python tools/assets/text.py roundtrip <narc> <index>` re-derives the key
from each entry's own terminator and re-encodes; checked against every
sub-file this pass dumped:

| sub-file | fully-clean entries | round-trip byte-identical |
|---|---:|---:|
| 70 (species) | 133 / 650 | 133 / 133 |
| 203 (moves) | 35 / 558 | 35 / 35 |
| 279 (items) | 16 / 625 | 16 / 16 |
| 182 (abilities) | 8 / 163 | 8 / 163 |
| 287 (types) | 1 / 15 | 1 / 1 |

100% match on every entry checked confirms the cipher implementation
itself is exactly correct; it is not a source of the gap below.

### Remaining gap: a dictionary/token compression layer, not cracked

Only a minority of entries decode to 100% printable ASCII end to end. The
rest decode to a real, readable ASCII **tail** -- frequently the exact
end of a well-known name (`lbasaur` for entry 2 of the species bank,
i.e. Bulbasaur; `dgeotto`/entry 18 then `Pidgeot`/entry 19 clean, i.e.
Pidgeotto then Pidgeot back to back; `aticate`/Raticate; `LECTRIC`/
Electric) -- preceded by 1-3 code units that are not printable ASCII,
shown in the dumps as `[xxxx]` hex placeholders. This is not a cipher or
offset bug: the terminator-anchored key recovery is self-consistent by
construction (every entry's last unit decodes to exactly `0xFFFF`), the
fully-clean entries round-trip byte-for-byte (table above), and the
amount of leading garbage is irregular (0 to 3 units, no fixed relationship
to string position or length) -- not what a wrong key or wrong offset
would produce, but exactly what a small number of common leading
substrings (`Bu`, `C`, `Pi`, `Mr`, `Ae`, ...) being replaced by single
16-bit dictionary/token codes on top of the XOR cipher would produce.
Gen 3-5 Pokemon text formats are known, from general public ROM-hacking-
community knowledge (not from any specific other project's code, per
this lane's write-set rules), to sometimes compress common substrings
this way; this pass did not locate the dictionary table itself (it is
not inside these `a/0/0/2` message files as far as this pass determined)
and did not attempt to brute-force-recover it from the many partial
matches already in hand. That reconstruction -- plus locating the
dictionary table elsewhere in the ROM, or brute-forcing short 1-3-letter
substrings against the ~2500 partial entries already decoded across the
five dumped banks -- is left to a follow-up lane.

### 9-bit packing hypothesis: tested, not confirmed

A follow-up pass tested a specific, publicly-documented-for-Gen-5
hypothesis about the gap above: that after XOR decode, a string whose
first code unit is `0xF100` (`PACK9_MARKER` in `tools/assets/text.py`) is
not plain UTF-16 at all -- the remaining units would be a little-endian
bitstream read 9 bits at a time, each 9-bit value a character code
(`0x1FF` terminates, values below `0x100` use the normal character set).
`unpack_9bit()` / `pack_9bit()` implement that mechanism exactly as
described, and a new `check9bit` subcommand runs the verification:

```
python tools/assets/text.py check9bit extract/data/a/0/0/2
```

Result: **not confirmed**, on two independent checks.

1. **Marker scan.** Under the existing, independently name-verified
   rotate-3 XOR cipher (the one that produces `Pidgeot`, `Diglett`,
   `ELECTRIC`, etc. byte-for-byte), zero of the 2,011 entries scanned
   across all five dumped banks (species 70, moves 203, items 279,
   abilities 182, types 287) decode to `0xF100` as their first unit.
2. **Marker-independent brute force.** In case `0xF100` is the wrong
   marker value but the packing idea itself is right, the species bank's
   Bulbasaur entry (descriptor index 2) was brute-forced directly: every
   possible initial key (0-65535) was tried, XOR-decoded forward with the
   confirmed rotate-left-3 schedule, and the units after the first were
   run through `unpack_9bit()` looking for the literal codes for
   `"BULBASAUR"` followed by the `0x1FF` terminator. No key produces that
   result. The same entry was also brute-forced with the two obvious
   alternate readings (bits packed most-significant-bit-first instead of
   least-significant-bit-first; and a 9-bit-granularity rotating XOR
   applied directly to the raw pre-XOR bytes, all 512 starting keys times
   all 9 rotate amounts) -- no match under any of those either.

A related observation surfaced while testing this: the "1-3 leading
non-printable units then a clean ASCII tail" pattern described in the
gap section above is not actually the typical shape. Most partial
entries are **fully** non-printable end to end at their correct unit
count (e.g. species entry 3, Ivysaur, is 8 raw units -- exactly enough
for `Ivysaur` plus terminator -- and every one of those 8 units is
non-printable). A smaller set of entries (e.g. species entry 18,
`Pidgeotto`) instead decode **fully clean** but a few characters short
(`dgeotto`, missing the leading `Pi`, with no leftover garbage unit
standing in for it at all). Neither shape matches simple "replace a
common prefix with one dictionary token" compression, which would
produce one extra non-printable unit *before* a clean tail of the
expected length. Whatever the real compression scheme is, it isn't the
9-bit packing tested here, and it doesn't match the simplest reading of
"one token per common substring" either -- both remain open. Because no
additional entries decoded, the non-ASCII character mapping this pass
was also asked to confirm (gender symbols, accented letters, the
`0xF000`-range control escapes) could not be confirmed either: none of
the garbage-prefixed or fully-opaque entries (e.g. the Nidoran-female /
Nidoran-male name pair, species entries 30 and 33, both fully opaque)
decode to anything recognizable under the current cipher, so there is no
confirmed instance of those codes to document yet. Only the plain
printable-ASCII range (0x20-0x7E) is confirmed, via the existing clean
entries and their round trip.

`unpack_9bit()` / `pack_9bit()` are left in `tools/assets/text.py` (used
by nothing else) because they are a correct, self-contained
implementation of the documented mechanism and cost nothing to keep --
if a real marker value or bit order is found later, `is_9bit_packed()`
just needs its constant updated. `render()` / `is_clean()` were
generalized to take a `terminator` parameter so they work for either
`0xFFFF` (plain strings) or `0x1FF` (a 9-bit-unpacked code list) without
duplicating logic. Round-trip counts (below) are unaffected by any of
this -- they were re-verified after the change and are byte-identical to
the pre-existing figures.

### Output

```
python tools/assets/text.py dump extract/data/a/0/0/2 70  -o build/assets/text/species.txt
python tools/assets/text.py dump extract/data/a/0/0/2 203 -o build/assets/text/moves.txt
python tools/assets/text.py dump extract/data/a/0/0/2 279 -o build/assets/text/items.txt
python tools/assets/text.py dump extract/data/a/0/0/2 182 -o build/assets/text/abilities.txt
python tools/assets/text.py dump extract/data/a/0/0/2 287 -o build/assets/text/types.txt
```

Each line is `<entry index>\t<decoded text>`, with partial entries
suffixed `(partial: dictionary-compressed prefix not decoded)`. Entry
index `i` in the species bank is the National Dex number `i-1` (verified:
descriptor index = dex number + 1, e.g. index 2 = Bulbasaur = dex #1,
index 19 = Pidgeot = dex #18). `python tools/assets/text.py stats
<narc> <index>` prints entry/clean counts as JSON without writing a file.

## Locate pass: walking and trainer sprites

Locate-only pass (no new converter code) over `build/assets/inventory.json`
(247 archives) to shortlist candidates for (1) player/NPC overworld walking
sprites and (2) Gen 5 animated trainer battle sprites.

**Correction to the working ruled-out list**: `a/0/0/7` is NOT an icon
archive. `tools/assets/overworld.py` (already written and verified) opens
`a/0/0/7` as the overworld NPC/entity sprite archive: 1431 sub-files, 715
per-entity `NCGR` tile sheets (each exactly 1072 bytes = 24-byte header +
1024 bytes = 32 tiles, 4bpp) sharing one `NCLR` palette and one `NCER`
cell bank (32x32 OAM), with per-entity `NANR` timing not yet decoded past
its header. This is the correct home for category (1). The actual icon
candidate is `a/1/6/7` (655 sub-files, ~107 B average, close to the 649
species count) per the existing "Pokemon icons" entry above; the ruled-out
note likely transposed these two paths.

**Category 1 -- overworld walking sprites (player + NPCs)**

1. `a/0/0/7` (already located, see above) -- 715 entities is a plausible
   count for every NPC/trainer-class overworld graphic. Only a 2-3 cell
   "idle bob" is confirmed; the `NANR`/ABNK frame-duration/order fields
   are undecoded, so a full 4-8 direction walk cycle is not yet verified
   from this archive alone.
2. `a/0/2/5` -- 1005 sub-files (552 `NCLR` + 451 `NCGR` + 1 shared `NCER`
   + 1 shared `NANR`), all uncompressed, avg 554.7 B/entry. Sampled a
   `NCGR` sub-file directly (index 2): `data_size` 512 bytes = 16 tiles
   4bpp, consistent with a 32x32 sprite at half tile density or a 16x32
   frame. Same "many small per-entity NCGR+NCLR sharing one NCER/NANR"
   shape as `a/0/0/7` but roughly 2x the entity count and half the
   per-entry tile budget -- worth checking as a second overworld sprite
   set (e.g. a different resolution class, or menu-sized character icons)
   once `a/0/0/7` itself is fully mined.

**Category 2 -- trainer battle sprites**

No archive matches the hypothesized `a/0/0/4`-shaped compound rig
(`NCER`+`NMCR`+`NMAR`+`NCLR`) at a 200-400-block scale: a full magic-key
scan for the `NMCR`/`NMAR` guess tags across all 247 archives returns only
6 hits, and all are already accounted for -- `a/0/0/4` and `a/0/5/2`
(14285 sub-files each, the Pokemon battle rigs) and the `a/0/6/4`/`a/0/7/2`/
`a/0/7/3` UI-rig family (48-760 sub-files). None sit in the 200-400 range.

Best remaining candidates use the simpler `a/0/0/7`-style rig (per-entity
`NCER`+`NANR`, no multi-cell resource/animation blocks):

1. `a/0/7/8` -- 179 sub-files (7 `NCLR` + 55 `NCGR` + 15 `NSCR` + 51
   `NCER` + 51 `NANR`), i.e. ~51 "characters" each with its own cell bank
   and animation (unlike `a/0/0/7`'s one shared `NCER`/`NANR`). Sampled
   `NCGR` sub-file index 7 decodes to a 32-tile, 1072-byte sub-file --
   structurally identical to `a/0/0/7`'s per-entity `NCGR` shape. Strongest
   surviving structural match, but 51 entries is far short of Black/White's
   ~200-400 trainer classes; more likely a sub-cast (gym leaders/Elite
   Four/rivals) or an unrelated UI roster.
2. `a/0/8/3` -- 172 sub-files (37 `NCLR` + 66 `NCGR` + 33 `NCER` + 33
   `NANR` + 3 `NSCR`), same shape family, ~33 characters, same
   too-few-entries caveat.

Neither candidate's entry count lines up with the full trainer roster.
Next lane should either (a) search battle/trainer-table code already named
by other lanes for a direct reference to a sprite archive path, since the
inventory-shape search is now exhausted for this hypothesis, or (b) check
whether trainer battle sprites in fact reuse the `a/0/0/4`/`a/0/5/2` rig
format itself under a currently-unidentified index range, or are stored as
smaller static (non-rig) per-entry `NCGR` sprites elsewhere rather than as
a dedicated compound archive.

## Re-encoder / round-trip pass: `a/0/0/6`, 4x4-compressed textures, ADPCM ties

Three targeted follow-ups on existing decoders, in priority order.

### 1. `a/0/0/6` (" APS12_1"/" TPS" wrapper) re-encoder: 733/733 byte-identical

`tools/assets/trainer.py` gained `parse_full()`/`reencode_full()` and a
`--verify-reencode` CLI flag. Building the re-encoder and checking it
against every sub-file (not just the 3 originally sampled) **falsified
two claims in the existing module docstring**:

- The per-`" TPS"`-chunk `pixel_bytes` field at `+0x08` is **not** a
  constant `0x400` -- sub-files 0 and 1 declare `0x1000` (4096). The true
  per-chunk pixel region size is this field, clipped to whatever room is
  actually available before the next `" TPS"` tag (or before the trailing
  32-byte palette, for a sub-file's last chunk). This clipped-length rule
  (`pixel_len = min(pb, next_boundary - pix_start)`, `next_boundary` =
  next chunk's offset, or `len(data) - 32` for the last chunk) reproduces
  the exact original byte layout for all 733 sub-files with zero leftover
  or missing bytes -- not just the 8-frame sample that "confirmed" the old
  constant.
- The low nibble of each pixel byte is **not** a 1-bit flag restricted to
  `{0x0, 0x8}`: scanning all 733 sub-files, **686 of them (94%) contain
  pixel bytes whose low nibble takes a value outside `{0, 8}`** (9.3% of
  8,572,352 sampled pixel bytes overall). The `{0,8}`-only pattern held
  for the 3 originally-sampled sub-files (0, 1, 100) because they happen
  to be near-empty/single-color "glint" sprites; it does not generalise.
  What the byte (or its low nibble) actually encodes is still open --
  the re-encoder does not guess: it treats each pixel as one opaque byte
  and reconstructs it verbatim, which is both honest about the gap and
  sufficient for exact round-tripping.

Every other field (`field_a`, `frame_count`, the two `size_*` triples,
each chunk's `tag`/`pb`/running-total/`chunk_total` pair) round-trips
through actual decoded int values (`struct.pack` of the same ints), not a
raw copy; only the two genuinely opaque byte ranges (the leading
unresolved table before the first `" TPS"`, and each chunk's
`subtable_len`-byte descriptor) are carried through verbatim, same
"decode what's understood, preserve the rest" convention as
`sbnk.py`/`nsbmd.py`. The 16-entry palette is decomposed into actual
5-bit R/G/B/alpha-bit fields and re-packed, not copied.

```
python tools/assets/trainer.py --verify-reencode
```

Result: **733/733 sub-files byte-identical.** The existing `--all` PNG
dump path (`decode_frames()`) is untouched and still uses the old
32x32/high-nibble-only interpretation for visualisation -- it is now
known to be wrong for any sub-file with `pb != 0x400`, but fixing the
*visual* decode (true per-chunk width/height, and the low nibble's real
meaning) is a separate, still-open task from the re-encoder built here.

### 2. 4x4-compressed (GX format 5) textures: index table not located, gap documented, no PNG produced

**Later-pass correction:** the "confirmed format 5 is genuinely used"
claim below, based on 132 raw `TEXIMAGE_PARAM` command-stream hits, did
NOT hold up once the TEX0 dict's own per-entry format field could be read
directly (see "NITRO resource dictionary CRACKED" further down this
document) -- a ROM-wide scan of the dict's format field (not the GX
command stream) found **zero format-5 texture entries anywhere**. The
132 command-stream hits are therefore either a different, non-texture use
of that bit pattern, mis-decoded opcode parameters, or reference textures
that never actually ship as format-5 data in this ROM; not chased further.
Treat the "confirmed" wording below as superseded.

Confirmed format 5 is genuinely used in this ROM (132 raw
`TEXIMAGE_PARAM` (`0x2A`) hits across 413 real `MDL0` command streams,
format field = `(param >> 26) & 7`; example: `titledemo.narc` sub-file 5,
model offset 0xF70). Went looking for the secondary palette-index table
the mission brief expected to sit "in a separate block after the texel
data, size texel_size/2" -- and could not find it:

- Scanned all 288 single-texture `TEX0` blocks in the ROM for a
  `texture_data_size` equal to `1.5x` a valid 4x4-compressed texel size
  (i.e. texel region + attached index region, contiguous): **zero
  matches**.
- Found two texture families literally named with `"4x4"` in their
  `TEX0` dict names -- `t4x4xocell` (`a/0/4/9`, single-texture dicts,
  512-byte texture data) and `t4x4pokeflip.1`..`.6` (`a/0/4/9` #199 etc.,
  6-texture dicts, 3072-byte texture data). Neither holds up as real
  hardware-compressed data on inspection:
  - `t4x4xocell`'s 512 texel bytes decode cleanly as plain 4bpp
    (16-color, format 3) pixel data at 32x32 (visually a small
    blob/icon, matches a 14-color attached palette) -- the "4x4" in the
    name is not the GX compressed format.
  - `t4x4pokeflip`'s 3072-byte region divides *exactly* into 6 x 512
    bytes (one texel-only region per sub-texture, zero remainder), and
    its `tex_dict` per-entry fields include a value that increments by
    a constant stride (`0x40`) once per texture -- this is the standard
    NSBTX per-texture VRAM texel-offset field (present for every
    indexed format, not specific to compression), not evidence of an
    attached index table.
  - For both families, every byte in the `TEX0` block's data region is
    already accounted for by `header + tex_dict + pal_dict + texel-only
    data + a normally-sized color palette` (32/64 bytes, matching
    `pal_dict.count x 16 colors x 2 bytes` exactly) -- there is no
    slack anywhere for an extra `texel_size/2`-byte block, before texel
    data, after texel data, or after the palette (`Tex0.palette_bytes()`
    greedily takes "rest of `raw_data`", so any leftover bytes would
    have shown up as an oversized palette; they didn't).

**Conclusion: the format-5 index-table bytes are not present inside the
ripped `TEX0` sub-file for any sample checked in this pass.** Given the
DS hardware convention (4x4-compressed index data lives in a dedicated
VRAM bank, "slot 4", addressed by scaling the same texel offset field),
the most likely explanation is that this game's asset pipeline stores
compressed-texture index data as a separate resource entirely (a shared
table uploaded once, or held in a different NARC/overlay) rather than
per-`TEX0`-file -- but that is unconfirmed, not chased further this pass.
**No 4x4-compressed texture was decoded to PNG**: doing so without the
real index table would fabricate pixel data, which this pass declines to
do. `nsbmd.py` is unchanged (format 5 remains `NOT decoded by this pass`
in `FORMAT_NAMES`/`decode_texture()`); this is a documented gap, not a
regression.

### 3. ADPCM sign-tie / saturated-target divergences: 5400/5400 (was 5363/5400)

Examined the two smallest failing samples in detail (WAVARC 1000 waves 55
and 162) by replaying the encoder's state machine nibble-by-nibble
against the real encoded bytes and finding the exact divergence point.
Both hit `diff == 0` (target sample exactly equal to the current
predictor) while the predictor was already clamped to `-32768`: the
greedy magnitude computation is identical for either sign at `diff == 0`,
so the old encoder's fixed "prefer positive/add" default picked nibble
`0x0` (predictor moves to -32749/-31877, away from target), while the
real encoded byte was `0x8` (predictor stays clamped at -32768, i.e.
exactly on target). A first attempt to fix this by always preferring the
"subtract" nibble on a tie **regressed 3547/5400** -- the vast majority
of ordinary (non-clamped) `diff == 0` samples really do use the "add"
default, and only clamp-adjacent ties flip to "subtract"; the fix had to
compare actual resulting error for both candidates and keep the default
only when they tie exactly (see `tools/assets/adpcm.py`'s
`encode_block()` docstring for the worked-through reasoning).

That fix alone reached 5399/5400; the one remaining failure (WAVARC 1485,
wave 0) was a **different, non-tied** case: `diff = -13874` at
`step = 18500`, so the plain greedy magnitude computation legitimately
leaves the low bit clear (`d` ends up 1 unit short of `quarter` after the
half-step subtraction) -- but the target sample was again exactly
`-32768`, and a *different* nibble's clamped result lands exactly on it
while the greedy nibble leaves a 2312-unit error. Generalising the fix
from "`diff == 0`" to "target is a saturated s16 value (`-32768` or
`32767`)" subsumes both shapes: whenever the target is already pinned to
the PCM16 extreme, the encoder now searches all 16 candidate nibbles for
the one whose clamped result is closest to that extreme (ties broken
toward the plain greedy nibble, which matched every real sample where
more than one nibble tied for minimal error). Off the clamp boundary,
behaviour is unchanged (plain greedy, exactly as before).

```
python -c "
import sys; sys.path.insert(0, 'tools/assets')
import sdat, swav
s = sdat.parse_file('extract/data/wb_sound_data.sdat')
ok = total = 0
for wi in range(1, 1986):
    fid = s.wavarc_fileid(wi)
    if fid is None: continue
    sw = swav.Swar(s.raw_file(fid))
    for w in sw.waves:
        if w.wave_type != swav.WAVE_TYPE_ADPCM: continue
        total += 1
        ok += (w.reencode() == w.sample_data)
print(ok, '/', total)
"
```

## NSCR (screen/tilemap) backgrounds: `tools/assets/background.py`

Asset-lane pass targeting 2D backgrounds and tilemaps: menu/battle
backgrounds, title screens, UI panels. New, stdlib-only module
`tools/assets/background.py` (parses NSCR, composites against NCGR+NCLR,
renders PNG, round-trips NSCR). Reuses `battle_sprite.parse_nclr` and
`battle_sprite.write_png_rgb8` rather than re-deriving the NCLR/PNG code
already verified in an earlier pass.

### NSCR (on-disk `RCSN`) format

Standard Nitro resource shape, same convention as every other chunk this
project has opened: 16-byte common file header, then one SCRN block
(stored reversed as `NRCS`): magic(4)+size(4), then a 12-byte sub-header
(`u16 screen_width_px`, `u16 screen_height_px`, `u32 unknown` -- 0 in
almost every sub-file, 1 in a handful of `a/0/3/4`'s, meaning not
determined, preserved verbatim for round-trip -- `u32 data_size`), then
`data_size` bytes of row-major `u16` screen entries: bits 0-9 tile index
into the paired NCGR, bit 10 hflip, bit 11 vflip, bits 12-15 palette bank
(4bpp tilesets only). Every one of the 188 NSCR sub-files this pass
scanned has `block_count == 1`, no trailing bytes past the declared
`data_size`, and `file_size == header_size + block_size` exactly (no
slack) -- a uniform shape, no compression seen on any NSCR sub-file
sampled. `screen_width_px`/`screen_height_px` are frequently exactly
256x192 (the real NDS screen resolution), which is itself corroborating
evidence these are genuine renderable screens, not incidental tilemaps.

### Archives covered

20 archives: `a/0/0/1`, `a/0/2/9`, `a/0/3/3`, `a/0/3/4`, `a/0/4/6`,
`a/0/7/7`, `a/1/0/2`, `a/1/2/0`, `a/1/4/3`, `a/1/4/4`, `a/1/5/9`,
`a/1/8/8`, `a/1/9/2`, `a/1/9/3`, `a/2/0/6`, `a/2/2/3`, `a/1/3/7`,
`soundstatus.narc`, `titledemo.narc`, `skb.narc` -- every "map/tileset
graphics (guess)" archive from the inventory table plus the two
"trainer/item/UI sprites (guess)" archives already flagged elsewhere in
this document as reading like tileset/map bundles rather than character
sprites (`a/1/5/9`, `a/1/3/7`), plus the three named non-`a/*` archives
whose dominant formats include NSCR/NCGR. 188 total NSCR sub-files across
these 20 archives.

### Pairing rule (documented, with an honest gap)

The mission's "standard grouping: consecutive NCGR, NCLR, NSCR triples"
does **not** hold in this ROM. Dumping the full per-archive magic sequence
for all 20 candidates shows every one is laid out as grouped runs by chunk
type -- all of an archive's NCLR sub-files, then all its NCGR sub-files,
then (sometimes) NCER/NANR, then all its NSCR sub-files -- not interleaved
triples. `a/0/0/1` is the one partial exception (NCLR, NCGR, NSCR x4,
NCGR, NCLR -- a "sandwich"). NCLR/NCGR/NSCR counts per archive do not
divide evenly against each other in most archives (e.g. `a/0/3/3` is 11
NCLR / 9 NCGR / 10 NSCR), so no count-based correspondence was usable.

This module reuses the "nearest preceding sub-file index" rule
`overworld.py` already validated for `a/0/2/5`'s irregular NCGR/NCLR
interleave: each NSCR pairs with the nearest preceding NCGR index and
nearest preceding NCLR index (falling back to the nearest *following* one
if the NSCR sits before any NCGR/NCLR in the archive). In a grouped-run
archive this collapses to "the last NCGR and last NCLR before the NSCR
run" -- one shared tileset+palette for every screen in that archive.
Validated by rendering: every sample this pass rendered (well over the
10-sample minimum, see below) came out as a coherent, structured image
(readable logos, text-box borders, repeating menu-row patterns, terrain
silhouettes) rather than palette-mismatch noise, which is this project's
established bar for accepting the heuristic (same bar `overworld.py`
applied). **Known gap, reported honestly, not resolved:** because the
rule always resolves to the *last* NCLR/NCGR in a run, any earlier
NCLR/NCGR sub-files in a multi-palette or multi-tileset archive (e.g.
`a/0/3/3`'s other 10 NCLR sub-files) are never selected by this heuristic
and are left unexplored -- no in-archive index table or count match was
found to justify picking any of them over the last one.

### Samples rendered and identified

`python tools/assets/background.py --sample` (10 across the candidate
list) plus targeted follow-up renders (`--archive X --index N`) once a
promising archive turned up more than one interesting screen, all written
to `build/assets/backgrounds/` (gitignored). Both mission "ideal" targets
were found:

- **Title screen -- confirmed.** `titledemo.narc#0` renders the actual
  **Pokemon Diamond/Pearl Japanese logo** ("ポケットモンスター ダイヤモンド" with the
  Pokeball mark and "Pokemon"/"ダイヤモンド" wordmark) -- this ROM ships a
  leftover Diamond/Pearl title-screen demo bundle, not (in this specific
  sub-file) Black/White's own title art. `titledemo.narc#17` renders
  "© 2006 GAME FREAK inc." on black, the standard developer splash screen
  that precedes a title screen. `titledemo.narc#12` is a purple-to-white
  vertical gradient, a plausible title-screen backdrop layer. `titledemo_8`
  is a striped decorative border pattern.
- **Battle background -- confirmed (high confidence).** `a/1/4/3#22`
  (512x192, wider than one screen -- likely a horizontally-scrolling
  layer) renders an irregular green silhouette against black: a hill/grass
  terrain line, the classic Pokemon battle-background foreground-terrain
  shape. `a/1/4/3#24` renders a repeating small-circle/scale texture with
  teal accent squares -- a plausible ground/grass texture tile for the
  same background. `a/1/4/3#18` is a flat green fill (a plausible terrain
  base-color layer).
- **Menu/UI screens -- several, not the literal main menu but clearly UI.**
  `a/1/9/2#5` renders ten empty rounded rectangular slots stacked
  vertically on a teal background -- a save-file-select or list-menu
  layout (an empty list of selectable rows is exactly what an unfilled
  menu template looks like). `a/1/9/2#8` renders an outlined circle plus
  colored signal-strength-style bars on teal -- reads as a Nintendo
  Wi-Fi/GTS connection-status screen. `a/1/3/7#26` renders readable English
  text: **"VS. RECORDER" / "GLOBAL MODE"** -- Black/White's real VS
  Recorder (battle-replay) feature UI banner, a strong, unambiguous
  identification. `a/1/9/2#2` renders a blue perspective grid (a
  "network/connection" visual motif, consistent with the Wi-Fi guess
  above).
- **Misc UI elements confirmed along the way:** `a/0/0/1#2` renders a
  small yellow cat-eared face icon next to a "123456" digit counter and a
  checkbox-like mark -- reads as a save-file/Pokemon-box status readout,
  not a full-screen background (this archive's screens are UI panel-sized
  widgets, not backgrounds). `a/0/4/6#11` renders a pink diamond-lattice
  decorative window border/frame twice (top and bottom half of the
  256x512 canvas) -- a menu window-frame graphic. `a/0/7/7#4` renders a
  pink braided/ribbed vertical stripe pattern -- a decorative
  wallpaper/curtain texture.
- **Flat/blank renders** (`a/1/0/2#4`, `a/1/4/4#12`, solid black; several
  solid-color fills like `a/0/2/9#9` solid green, `a/1/4/3#15` solid
  blue): plausibly genuine flat-fill background layers (a sky or ground
  base color is often literally one repeated tile), but this pass cannot
  rule out a wrong NCGR/NCLR pairing collapsing every tile to the blank
  filler tile in some of these cases -- not chased further per the pairing
  rule's documented gap above.

### NSCR round trip

`python tools/assets/background.py --verify`: **188/188 (100%) of NSCR
sub-files across all 20 covered archives byte-identical round trip**
(parse to `NscrFile`, re-serialize with `NscrFile.encode()`, compare
against the original bytes; no NSCR sub-file in any covered archive was
compressed, so this is a direct byte comparison, not a decompress+recompress
round trip). Per-archive counts: `a/0/0/1` 4, `a/0/2/9` 7, `a/0/3/3` 10,
`a/0/3/4` 15, `a/0/4/6` 6, `a/0/7/7` 4, `a/1/0/2` 15, `a/1/2/0` 2,
`a/1/4/3` 10, `a/1/4/4` 10, `a/1/5/9` 38, `a/1/8/8` 3, `a/1/9/2` 10,
`a/1/9/3` 6, `a/2/0/6` 2, `a/2/2/3` 3, `a/1/3/7` 36, `soundstatus.narc` 2,
`titledemo.narc` 4, `skb.narc` 1.

### Remaining gaps

- The pairing rule's "always the last NCLR/NCGR in a run" limitation
  (above) means multi-palette/multi-tileset archives are only partially
  explored -- e.g. `a/0/3/3`'s 10 non-selected NCLR sub-files are unused
  by this pass.
- Several samples render as flat solid colors or solid black; not
  disambiguated between "genuine flat background layer" and "wrong
  NCGR/NCLR pairing" (see "Flat/blank renders" above).
- Black/White's *own* title screen (as opposed to the `titledemo.narc`
  leftover Diamond/Pearl demo bundle) was not specifically located in this
  pass's 20-archive coverage; `titledemo.narc` was covered because its
  name suggested title-screen content, and it delivered, but this pass did
  not separately search for a Black/White-specific title archive.
- `a/1/6/7`'s round trip and the NCGR-only round trip already verified in
  `overworld.py`/`icons.py` are unrelated to this pass; only NSCR (not
  NCGR/NCLR) round-tripping was in scope here, per the mission brief.
- NCGR 8bpp tile unpacking (`bytes_per_tile == 64`, bitdepth field value 4)
  is implemented per the same bitdepth convention documented in
  `icons.py` (3 = 4bpp, 4 = 8bpp) but was not exercised against real 8bpp
  data in this pass -- every NCGR paired with an NSCR in the 20 covered
  archives turned out to be 4bpp.

Result: **5400/5400 ADPCM samples now byte-identical** (up from
5363/5400), across all 1497 real WAVARC archives -- the encoder change is
confined to `tools/assets/adpcm.py`'s `encode_block()`; `swav.py` and its
`verify_roundtrip()` call site are unchanged. PCM8's 650/650 is
unaffected (different code path, not touched).

## Trainer battle sprite mission: both named candidates are battle-HUD UI, not sprites; widen search and rig-tail check both come up empty; one real overworld-character archive found instead (`tools/assets/trainer_locate.py`)

Mission: identify the trainer battle sprites, starting from the locate
pass's two candidates (`a/0/7/8`, `a/0/8/3`), widening to every archive
with an 80x80+-canvas `NCGR` if neither pans out, and checking whether
`a/0/0/4`/`a/0/5/2`'s 65 tail blocks (species indices 649-713) hold
non-Pokemon content. New tool: `tools/assets/trainer_locate.py`
(`--candidates`, `--widen`, `--rig-tail`). Renders under
`build/assets/trainer_candidates/`.

### `a/0/7/8` and `a/0/8/3`: both battle/menu HUD graphics, not trainer sprites

Full run-length structure (via `--candidates`):

    a/0/7/8: RLCNx7 RGCNx55 RCSNx15 RECNx51 RNANx51
      NCGR tile counts: min=16 max=1024, only 7/55 have >=64 tiles
    a/0/8/3: (RLCN NCGRx1-3 RECNx3 RNANx3) repeated ~11x, one RCSN pair
      NCGR tile counts: min=4 max=108, only 1/66 has >=64 tiles

Both are dominated by 2-16-tile `NCGR` sub-files -- far too small for a
32x32 (16-tile) or 64x64 (64-tile) character frame in most cases -- with
a handful of larger outliers. Rendering those outliers (raw tile-grid,
every palette tried) settled it by direct legibility:

- `a/0/7/8` sub-file 8 (512 tiles) renders literal **"EXP"** text over a
  green bar; sub-file 9 (128 tiles) renders a column of menu-style text
  rows; sub-file 10 (512 tiles) renders another partial text/icon strip.
  This is a battle-screen EXP/status bar, not a sprite.
- `a/0/8/3` sub-file 2 renders literal **"HP"** text (the HP gauge label);
  sub-file 122 renders a small multi-color ball/orb icon (a Poke Ball or
  similar item icon).

Renders: `build/assets/trainer_candidates/extra_sf000{8,9,10}_pal*.png`
(a/0/7/8) and `extract_data_a_0_8_3_sf*.png` (a/0/8/3), 6+ samples each
plus the outlier renders, matching the mission's "6 samples with true
colour" ask. **Both candidates are ruled out**: they are battle/menu HUD
component sets (gauge text, item/status icons, panel borders), the same
family as the already-ruled-out `a/0/7/2` trainer-card/badge rig, not
animated trainer sprites.

### Widen search: 94 archives have an NCGR sub-file with >=100 tiles; none is a battle-sized human rig

`find_widen_candidates()` re-used `build/assets/inventory.json`'s
already-computed full magic/compression histograms to shortlist 137
archives worth opening (has an uncompressed `NCGR`, or has any
compressed sub-file at all, since a compressed `NCGR` wouldn't show its
magic to the inventory pass), excluding `a/0/0/4`/`a/0/5/2` (handled
separately, see below). Parsing every sub-file's `CHAR` header (with
LZ77/LZ11/Huffman/RLE decompression as needed) found **94 archives**
with at least one `NCGR` sub-file of >=100 tiles (an 80x80+ canvas
budget at 4bpp). One raw tile-grid sample per hit archive (its largest
`NCGR`, paired with the nearest preceding `NCLR` where one exists) was
rendered to `build/assets/trainer_candidates/widen/`.

Cross-referencing against `inventory.json`'s category guesses: 28 hits
fall in "small sprite/icon set", 18 in "3D model/texture data" (texture
pages, not sprites), 14 in "map/tileset graphics", and **29** in
"trainer/item/UI sprites" / "pokemon/trainer sprites" -- the priority
bucket. A second, more targeted scan (`scan_big_oam.py`, not checked in
-- ad hoc) parsed every `NCER` in every archive with any `NCER` at all
(77 archives) and flagged any cell whose OAM is >=64px on a side (the
battle-sprite-canvas signature): 38 archives have at least one such OAM,
topped by `a/0/7/2` (117, already ruled out), `a/0/7/8`/`a/0/6/4`/
`a/0/7/3` (the same ruled-out UI-badge/HUD family), then `a/0/3/4` (33),
`a/0/4/3` (31), `a/2/1/6` (24).

Rendered and inspected the new top candidates properly (NCER-composited,
not raw grid, matching each cell's `mapping_type` tile-index scaling):

- **`a/0/3/4`**: 9 `NCLR` + 8 `NCGR` (one 2048-tile outlier) + 15 `NSCR`
  (screen/map data) + 3 `NCER`/`NANR`, plus a trailing `" APS"`-wrapped
  sub-file (the same wrapper format as `a/0/0/6`'s trainer-portrait
  guess, see below). The big `NCER` cell (2 stacked 64x64 OAMs + 4
  32x8 strips, composited against the correctly-sized 304-tile `NCGR`
  #9) renders as **thin colored line-art on a flat background** --
  a connection/route diagram, consistent with a Union Room / Wi-Fi
  Club-style network screen, not a character. Ruled out.
- **`a/0/4/3`**: matching NCER cell 0 against its correctly-sized `NCGR`
  (#19, 378 tiles) renders a **plain rectangle outline** -- a dialog/
  text-box border. Ruled out.
- `a/2/1/6` structurally characterized (2 `NCER`, 5 `NCGR`, matching tile
  math confirms `NCGR` #24 pairs with the big `NCER`) but not rendered
  (time-boxed); given the pattern above (every >=64px-OAM hit so far
  resolves to HUD/UI, not a character), not pursued further this pass.

**No archive in the >=100-tile or >=64px-OAM widen searches renders as a
64x64+, multi-frame human figure.** The trainer battle sprite archive
remains unlocated.

### Unexpected real find: `a/0/3/1` is a genuine human overworld-character archive (resolves the "overworld archive not located" gap, but is 32x32-class, not battle-class)

While reviewing the widen-search renders, `a/0/3/1` (51012 bytes, only
24 sub-files, "trainer/item/UI sprites (guess)" in the inventory) stood
out: its raw tile-grid render
(`build/assets/trainer_candidates/widen/a_0_3_1_sf0005_384t.png`) shows
a small human figure wearing a cap, tiled repeatedly. Structural
confirmation: `NCER` #0 defines 24 cells, each one `mapping_type=2`
32x32 OAM, with `tile_idx` stepping 0,4,8,...,92 -- at that mapping
type's 128-byte/4-tile stride, consecutive cells are exactly 16 tiles
(one 32x32 frame) apart, and 24 cells x 16 tiles = **384 tiles, an exact
match** for `NCGR` #5/#7 (both 384 tiles, likely two palette-linked
copies). This is **24 frames of a 32x32 walking character** -- almost
certainly a directional walk cycle (e.g. 4 directions x 6 frames). The
archive also carries a second 12-frame 32x32 set (`NCER` #12/#15 against
`NCGR` #14/#17, 192 tiles each = 12x16) and a third, dense-mapped
(`mapping_type=0`) 11-cell set built from 32x8-strip OAMs against a
64-tile `NCGR` (#20/#23) -- a plausible run/bike/idle-emote kit. Two
extra `NCER`/`NANR` pairs at sub-file indices 0-3 (ahead of the first
`NCLR`) were not chased further.

At **32x32**, this is squarely the mission's own "overworld trainer"
size class, not battle-class (64x64+). It resolves the ninth lane pass's
open "overworld/trainer/player walking sprite archive is still not
located" gap -- just not in the shape that pass expected (a shared
715-entity table like `a/0/0/7`). Instead, overworld sprites for named
characters appear to live **one archive per character** (24 sub-files
for a full walk/run/idle kit), which is why the inventory-shape search
never flagged this family: at only 24-50 sub-files each, `a/0/3/1` and
its likely siblings (`a/0/3/0`, `a/0/3/2`, `a/0/3/3`, and other members
of the `a/0/3/x` run -- not individually confirmed this pass) read as
generic small "trainer/item/UI sprites" bundles, indistinguishable by
sub-file count alone from the battle-HUD archives ruled out above. Not
pursued further here (out of this mission's scope and budget) -- a
follow-up pass should render `a/0/3/1`'s NCER-composited pose (not just
the raw grid) and check its neighbors.

### `a/0/0/4` / `a/0/5/2` rig tail (species 649-713): Pokemon-shaped, not trainer content

`render_rig_tail()` reused `rig.py`'s existing per-species renderer
(`render_one`, the same one already producing clean cell contact sheets
for the confirmed 0-649 species range) against species indices 649-713,
the 65 "extra" 20-entry blocks past the ~649-species range noted as an
open gap in an earlier pass. **63/65 blocks rendered in each archive**
(2 fall outside the block-stride range or aren't `NCGR` at the expected
offset -- indices 712/713 read `RNAN`/`RLCN` where an `NCGR` was
expected, i.e. the tail is not a clean multiple of the 20-entry stride
at its very end). Every rendered tail block's cell contact sheet (e.g.
`build/assets/trainer_candidates/rig_tail/extract_data_a_0_0_4_tail0680_cells.png`,
`..._a_0_5_2_tail0700_cells.png`) shows small, scattered, irregularly-
shaped color fragments -- the same "small creature" visual character as
the confirmed 0-649 Pokemon range (and the same "pose not recognizable"
NMCR/NMAR placement problem documented in the seventh/eighth lane
passes), not anything resembling a human silhouette. **No trainer
content found in the rig tail**; it reads as the already-hypothesized
alternate forms/genders/Egg block.

### Report

- **What each candidate depicts**: `a/0/7/8` and `a/0/8/3` are both
  battle/menu HUD component sets (EXP/HP gauge text, item/status icons,
  panel borders) -- the same family as the already-ruled-out `a/0/7/2`
  trainer-card/badge rig. Neither is a sprite archive.
- **Best identification for trainer battle sprites: still not located.**
  This pass covered (a) both locate-pass candidates (rendered + ruled
  out), (b) every archive with an NCGR sub-file of >=100 tiles (94
  archives, one sample each, none is a human figure), (c) every archive
  with an NCER cell using a >=64px OAM (38 archives, top candidates
  rendered properly, all resolve to UI/HUD, not characters), and (d)
  `a/0/0/4`/`a/0/5/2`'s 65-block tail (Pokemon-shaped, not trainer).
  Static 2D trainer battle sprites, if they exist as a dedicated OAM-rig
  archive at all, are not among these. Two untried hypotheses for a
  follow-up pass: (i) trainer battle "sprites" in Black/White might not
  be OAM tile/cell rigs at all but full bitmap images (like the
  Gen-IV-style trainer profile picture format `a/0/0/6`'s `" APS12_1"`/
  `" TPS"` wrapper was investigated for and set aside as "not a human
  figure, likely reclassify" -- worth re-checking now that this pass has
  a confirmed non-sprite baseline to compare against); (ii) they may be
  3D-rendered (many `a/1/*` archives are NSBMD/NSBTX 3D model/texture
  data, unexplored for trainer content).
- **Render counts**: 6+ samples each for `a/0/7/8`/`a/0/8/3`
  (`build/assets/trainer_candidates/`), 94 widen-search samples
  (`build/assets/trainer_candidates/widen/`), 63+63 rig-tail cell
  sheets + pose attempts (`build/assets/trainer_candidates/rig_tail/`).
- **Remaining gaps**: the true trainer battle sprite archive is
  unlocated. `a/0/3/1` (a confirmed real human **overworld** character
  archive, 3 animation sets, 32x32) is a genuine new find that resolves
  a different open gap (category-1 overworld sprites) but was not fully
  mined (no NCER-composited pose render, siblings not confirmed). `a/2/1/6`
  was structurally characterized but not rendered. The `scan_big_oam.py`
  OAM-size scan and the tile-count widen scan are ad hoc scripts (not
  checked in as reusable tools, unlike `trainer_locate.py`'s three
  documented CLI modes) -- worth folding into `trainer_locate.py` if a
  future pass returns to this search.

## Tenth lane pass: `a/0/0/7` NANR timeline decoded, `a/0/2/5` characterized

Two-part mission on `tools/assets/overworld.py`: (1) decode `a/0/0/7`'s
shared NANR frame timeline past the ninth pass's "header only" stop point,
and (2) characterize the second overworld-shaped archive flagged by the
locate pass, `a/0/2/5`.

### (1) `a/0/0/7` shared NANR: frame timeline decoded

The shared NANR (3 byte-identical copies at sub-file indices 1/3/5) is a
362-byte, **3-block** resource: `KNBA` (ABNK, the sequence/element table
`rig.Nanr` already knows how to open), then **`LBAL`** (a name table
`rig.Nanr` never needed for the much larger species NANR it was written
for) and a trailing `TXEU` block (12 bytes, not decoded, purpose unknown).

`rig.Nanr`'s own sequence-record field layout (`elem_start(u32)@0,
num_frames(u16)@4, ...`) does NOT give usable results here: `num_frames`
reads **0 for all 6 sequences**, which cannot be the real per-sequence
frame count. What resolved this: the new `LBAL` block holds 6 NUL-
terminated ASCII names, one per sequence (`num_sequences=6` matches
exactly) -- **`CellAnime0` through `CellAnime5`**. Generic numbered names,
not direction words (no "Down"/"Up"/"Left"/"Right"), which is itself
evidence against a 4-direction walk cycle.

The element/frame-entry array (12 records, `0xBEEF` sentinel confirmed in
every one, exactly the shape `rig.Nanr` already decodes) gives 12
`(offset_to_frame_data, duration)` pairs. The frame-data region past the
element array is a **new, smaller 4-byte record** not previously seen in
this project: `{cellIdx(u16), sentinel(u16)=0xCCCC}` (a different sentinel
constant from the element array's own `0xBEEF`, confirmed present in
every record) -- not `rig.Nanr`'s 16-byte SRT or 8-byte "T" shape, which
this archive's frame-data region (12 bytes total) is too small to hold.
`cellIdx` decodes to 0, 1, 2 in every record -- exactly the shared NCER's
3 valid cell indices, which is the confirmation signal (a `cellIdx` of 3+
would be nonsense against a 3-cell NCER).

Since the per-sequence frame-count field does not give usable boundaries
(`elem_start` across the 6 sequences is 1, 2, 2, 2, 2, 3 -- heavily
overlapping, not a clean partition), `overworld.py`'s new `SharedAnim`
class and `--anim`/`--anim-sample`/`--anim-all` CLI flags render the
**entire 12-entry element/frame-data table, in array order**, as one
animation strip per entity to `build/assets/overworld_anim/NNNN.png` --
the mission's literal "all frames in order" for the one fully-decoded
timeline this archive has, rather than pretending the 6-way sequence
split is understood well enough to render separately.

**Decoded timeline** (12 frames, shared by all 715 entities): cell 0
(dur 1), cell 0 (dur 8), cell 1 (dur 8), cell 0 (dur 12), cell 1 (dur 12),
cell 0 (dur 24), cell 1 (dur 24), cell 0 (dur 40), cell 1 (dur 40), cell 0
(dur 90), cell 2 (dur 2), cell 0 (dur 2). Durations are presumably frame
units (60ths of a second, standard NNS_G2D convention; not independently
confirmed against a frame-rate constant this pass). Cell 0/1 alternate
with geometrically growing hold durations (8, 12, 24, 40, then a long 90),
consistent with a slow **idle bob**, not a walk cycle; cell 2 (the
1px-shifted third cell the ninth pass already flagged) appears once,
briefly (duration 2) -- a short transient/blink frame rather than a
fourth walking pose. This confirms and sharpens the ninth pass's "idle
bob, not direction set" reading with real per-frame duration data:
**`a/0/0/7` is a single shared 12-frame idle-bob timeline (not a 4/8-
direction walk cycle), reused verbatim by all 715 entities** -- entities
differ only in which pixels each cell's tiles draw, never in timing or
pose count.

**All 715 entities rendered** to `build/assets/overworld_anim/NNNN.png`
(`--anim-all`, 715 rendered, 0 skipped). Visual spot check (entity 25,
already-identified Pikachu): a clean 12-frame strip of two near-identical
recolored poses, exactly matching the decoded (cell0, cell1)-alternation
above.

### (2) `a/0/2/5` characterized: a Bag item-icon archive, not overworld sprites

`a/0/2/5` (1005 sub-files: one shared `RNAN` at index 0, one shared `RECN`
at index 1, then 451 `RGCN` + 552 `RLCN` interleaved from index 2 on) was
flagged by the locate pass as a second overworld-sprite candidate on
shape alone. This pass renders it and finds it is something else.

**Shared NCER**: 1 cell, 1 OAM, 32x32, `tile_idx=0` -- a single static
pose (no multi-cell walk/bob rig at all, unlike `a/0/0/7`'s 3-cell bank).
**Shared NANR**: `SharedAnim` parses it cleanly (same 3-block KNBA/LBAL/
trailing shape as `a/0/0/7`) -- 1 sequence ("CellAnime0"), 1 frame-
timeline entry (cell 0, duration 1). **Every entity in this archive is a
single static, unanimated icon** -- consistent with a menu icon, not an
overworld actor.

**NCGR/NCLR pairing**: sub-file order after the shared pair is *not* a
fixed stride (confirmed by direct scan of all 1003 remaining sub-files'
magics: mostly strict `G,L,G,L,...` alternation but with scattered runs
of 2-4 consecutive `RGCN` or `RLCN` sub-files, and no ARM9 lookup table
was found or needed). `overworld.py`'s `nearest_preceding_or_following()`
pairs each `RGCN` with the closest-by-index `RLCN` (preferring an earlier
index, falling back to a later one only for entity 0, whose own `RGCN` at
sub-file 2 precedes every `RLCN` in the archive). This is "index
arithmetic" in the loose "closest index" sense, not a fixed formula or an
external table. Verified by rendering: every one of the 10 evenly-sampled
entities (0, 45, 90, ..., 405) comes out as a plausible, internally
consistent true-color icon, not a garish palette mismatch.

**Entity identification**: the 10 samples depict clearly distinct small
objects, not one uniform shape: a purple/pink Poke Ball, a grey faceted
gem (evolution-stone-shaped), an orange flame/torch, a yellow curved
banana-like item, a pink boot/shoe, a plain grey pebble, an orange key or
rocket shape, a red round berry-or-ball, a green card/badge, and a pink
round pill/macaron shape. **This is a general held/key-item icon set, not
a Poke Ball set and not overworld/character sprites** -- the locate pass's
"menu-sized character icon" guess is wrong, and this pass's own first
impression (from an early, ball-heavy sample before scanning the full
index range) is corrected here. Consistent in kind, if not confirmed as
the same archive, with the existing `a/0/4/5#0` "held-item icon sprite"
finding earlier in this document. The 552-vs-451 NCLR/NCGR count (101
more palettes than shapes) is plausible for an item set where some icons
share one outline/shape `NCGR` across several color-variant `NCLR`s.

**NCGR round trip**: `NcgrFile`/`encode()` needed no changes -- the same
class already used for `a/0/0/7` parses and re-serializes `a/0/2/5`'s
`RGCN` sub-files unchanged (same 16-byte file header + 24-byte RAHC
sub-header shape, `tile_num_x/y=0xFFFF` sentinel, `bitdepth=3`, just a
smaller `data_size` of 512 bytes = 16 tiles instead of `a/0/0/7`'s 1024 =
32 tiles). **451/451 (100%) byte-identical round trip**
(`python tools/assets/overworld.py --verify --archive extract/data/a/0/2/5`).

### `--archive` support generalized

`overworld.py`'s render path (previously hardcoded to `a/0/0/7`'s shared-
palette-at-index-0 / fixed-NCER-index assumptions) now has an archive-
generic path (`load_shared_v2`/`render_entity_v2`/`find_magic_indices`)
that finds the shared `RECN` by magic scan (first one in the archive) and
looks up each entity's palette by nearest-index `RLCN` instead of a fixed
constant. This rule generalizes cleanly to `a/0/0/7` too (it has exactly
one `RLCN`, at index 0, so "nearest" always resolves to that one file),
so both archives now share one code path:

```
python tools/assets/overworld.py --sample                                  # a/0/0/7, build/assets/overworld/
python tools/assets/overworld.py --sample  --archive extract/data/a/0/2/5 --out build/assets/overworld2
python tools/assets/overworld.py --verify  --archive extract/data/a/0/2/5
python tools/assets/overworld.py --anim-all                                # a/0/0/7 animation strips
```

The ARM9 per-entity sub-palette table (`g_0209E474`) stays gated to
`a/0/0/7` specifically (it is only confirmed/sized for that archive's 715
entities); every other archive, including `a/0/2/5`, uses sub-palette 0
unconditionally, which is correct there since each entity already has its
own individually-paired small `NCLR` rather than sharing one multi-bank
palette.

### Report summary

- `a/0/0/7`: 715 entities, one shared 12-frame idle-bob animation timeline
  (6 named sequences reference overlapping spans of it, exact per-sequence
  split unresolved), all rendered to `build/assets/overworld_anim/`.
  NCGR round trip unaffected by this pass (still 715/715, see ninth pass).
- `a/0/2/5`: 1005 sub-files, 451 `RGCN` + 552 `RLCN` + 1 shared `RECN`
  (1 cell) + 1 shared `RNAN` (1 static frame). Pairing is nearest-index,
  not a fixed stride or table. Identified as a Bag item-icon archive (not
  overworld sprites). 10 samples rendered to `build/assets/overworld2/`.
  NCGR round trip: 451/451 (100%).

## Asset lane pass: `a/0/3/1`'s NANR timeline fully decoded (real 4-direction walk/run cycle), NCGR round trip, and the full walk-cycle NPC set located (`tools/assets/walk.py`)

Two-part mission on the `a/0/3/1` archive flagged (but not mined) by the
previous pass's trainer-sprite search: (1) fully decode its `NCER`/`NANR`,
render every animation set as strips, implement `NCGR` round trip, and
identify the characters; (2) find every sibling archive sharing the same
bundle shape to build the full walk-cycle NPC list. New tool:
`tools/assets/walk.py` (`--sets`, `--all`, `--multi`, `--verify`,
`--scan-siblings`, `--render-siblings`). Renders under
`build/assets/walk/`.

### NANR sequence partition: the real per-sequence frame-count field

`a/0/3/1`'s `RNAN` sub-files use the same 16-byte, 5-field KNBA sequence
record `rig.Nanr`/`overworld.SharedAnim` already read, and the field those
modules use as `num_frames` (offset 4) reads **0 for every sequence
here too** -- not usable, same problem as `a/0/0/7`. What resolves it: the
sequence record's **last** field (offset 12, called `field_e`) is a byte
offset into the element array (`field_e / 8`, 8 bytes per element record),
and taking every sequence's `field_e/8` in array order gives a
**complete, gapless partition of every element index** -- confirmed exactly
on all three of `a/0/3/1`'s `RNAN` sub-files (partition sums equal
`num_elements` precisely: 40, 35, 32). This is a different field from the
one `overworld.SharedAnim` uses for `a/0/0/7` (that module's own first-field
reading does not partition `a/0/3/1`'s element array either); `walk.py`'s
`Nanr2` class implements the `field_e` reading as new, separate code
rather than changing already-shipped-and-verified `overworld.SharedAnim`.

Per-element frame data also needed correcting: the first 16 bytes of the
frame-data pool are 4-byte `{cellIdx(u16), sentinel(u16)=0xCCCC}` records
(same shape `overworld.SharedAnim` uses for `a/0/0/7`), but past that the
pool is a **denser, plain 2-byte-per-frame region** (just `cellIdx`, no
per-record sentinel -- confirmed by direct byte dump, `a/0/3/1`'s main
`RNAN` frame-data steps by 2 bytes there, not 4, and only every 4th slot
happens to hold 0xCCCC as data). Reading a plain `cellIdx` u16 straight
from `frame_data[fofs:fofs+2]`, with no sentinel check, reproduces the
correct value in both regions (in the 4-byte region `fofs` always lands on
the cellIdx half of the pair) -- `walk.py` decodes this way uniformly.

### `a/0/3/1`'s main set is a genuine 4-direction walk/run cycle

The 24-cell/384-tile set's `LBAL` names 13 sequences with real direction
words: `top, bottom, left, right, rota, top_loop, bottom_loop, left_loop,
right_loop, top_run, bottom_run, left_run, right_run`. Decoded frame
counts via the `field_e` partition: `top/bottom/left/right` = 1 frame
each (static facing pose), `rota` = 4 frames (in-place turn), every
`*_loop`/`*_run` = 4 frames. `top_loop`'s decoded cell sequence is
`[5, 1, 4, 1]` -- alternating a walk-specific cell with the direction's own
static "stand" cell (1) -- the textbook GBA/NDS 2-step walk-cycle shape
(step, stand, step, stand), which is strong independent confirmation this
reading is right, on top of the exact 40/35/32 partition sums.

`a/0/3/1` also carries two companion sets found by the previous pass but
not rendered: a 12-cell/192-tile set (generic `CellAnimeN` names; its
longest sequence, `CellAnime31`, renders as a bicycle-wheel silhouette
cycling under the character -- a bike-riding kit) and an 11-cell/64-tile,
`mapping_type=0` set (also generic names; its two 9-frame sequences render
a small bubble/exclamation icon popping in over the character's head and
back out -- a "surprised" emote), plus a tiny single-cell/single-frame set
(1 cell, 4 tiles, name `CellAnime0`) rendered as `shadow` -- most likely
the character's ground shadow blob. All 4 sets x all sequences (29 strips)
rendered to `build/assets/walk/0000_*.png`.

**Visual identification**: the rendered `bottom`/`top_loop`/etc. strips
show a small, clearly human 32x32 figure in a black-and-red jacket with a
cap -- reads as a **named protagonist-class character** (the level of
per-direction, per-gait (walk vs. run) detail -- 13 named sequences, 3
full companion kits -- is well beyond what a generic townsperson NPC gets
in `a/0/3/2`, see below), most consistent with the player character or a
comparably-detailed named character (rival), not a generic NPC class.
Not confirmed against a name table (none was found or searched for this
pass).

### `NCGR` round trip

No new code needed: `overworld.NcgrFile`/`.encode()` (already byte-exact
for `a/0/0/7`/`a/0/2/5`) parses and re-serializes `a/0/3/1`'s `RGCN`
sub-files unchanged. `walk.py --verify` delegates straight to
`overworld.verify_round_trip()`: **7/7 (100%)**.

### Sibling search: only 2 archives share the walk-cycle bundle signature, and the second one is a 32-character bundle in a single archive

`--scan-siblings` opens all 247 files under `extract/data/` and flags any
`RNAN` whose `LBAL` names include all of `top`/`bottom`/`left`/`right`
(the direction-word signature, checked instead of raw `NCER` cell count
since cell count varies per character/companion-set and would both
over- and under-match). Only **two** archives hit: `a/0/3/1` itself, and
`a/0/3/2`. The a/0/3/x run's other members do NOT share this shape
(`a/0/3/0` and `a/0/3/3` are map-tileset-heavy archives with only 1-2
`NCER`/`NANR` each, not character bundles) -- the previous pass's guess
that `a/0/3/0`/`a/0/3/2`/`a/0/3/3` were all "likely siblings" by proximity
alone was too broad; direct content search says only one truly is.

**`a/0/3/2` (97 sub-files) is a fundamentally different bundle shape from
`a/0/3/1`**: instead of one archive per character with every resource
group duplicated on disk, it packs **32 small characters into one
archive** sharing **one 256-color (16-sub-palette) `RLCN`**: a run of 16
`RGCN`, then 16 alternating `(RECN, RNAN)` pairs, then that whole
(16 `RGCN`, 16 pairs) shape repeats once more. Each entity's real
sub-palette index is **not** its position in the block (that was tried
first and renders several entities solid black) but is carried directly
in every one of its cells' own OAM `attr2` `pal` nibble -- unlike
`a/0/0/7` (whose OAMs all declare `pal=0`, forcing an external ARM9 table
lookup), this archive's OAMs already carry the real per-entity value
on-disk, confirmed constant across all of one entity's cells and
correctly reproducing a colorful, coherent figure for every one of the 32
entities once read that way. Block 1 entities (0-15) are 4-cell/64-tile
figures with only 5 sequences (`top/bottom/left/right/rota`, no loop or
run -- static-facing-pose NPCs); block 2 (16-31) are 1-cell/16-tile
figures with up to 9 sequences (adds `*_loop`, still no `*_run`). Neither
block matches `a/0/3/1`'s full 13-sequence, 3-companion-kit richness.
`walk.py`'s `find_multi_entity_blocks`/`render_multi_entity_archive`
handle this shape generically (works for any number of same-sized
blocks, not hardcoded to 2x16). `NCGR` round trip: **32/32 (100%)**.

**Visual identification of `a/0/3/2`'s 32 entities** (`build/assets/walk/
0001..0032_bottom.png`): a genuinely varied cast, not one uniform class --
samples include a crowned king/elder figure, a jester/mime-like figure, a
blonde girl, a red-haired trainer-class figure, and others, each visually
distinct in outfit/color/silhouette. This reads as **the generic overworld
NPC set** (a roster of small townsperson/character archetypes), separate
from and lower-detail than `a/0/3/1`'s single named character.

### Report

- **`a/0/3/1`**: a real 4-direction walk/run cycle (not an idle bob like
  `a/0/0/7`), 13 named sequences + 3 companion kits (bike, emote/shadow),
  40+35+32+1 = 108 total decoded frame-entries across all 4 sets, all
  exact partitions. 29 strips rendered to `build/assets/walk/0000_*.png`.
  Best identification: a single named, high-detail character (player or
  rival class), not a generic NPC.
- **Full walk-cycle NPC set located**: `a/0/3/2`, 32 lower-detail generic
  overworld characters in one archive (2 blocks of 16, static-pose-only
  in block 1, adds a walk loop in block 2). No other archive in the ROM
  shares the direction-word `RNAN` signature. 208 strips rendered to
  `build/assets/walk/0001..0032_*.png`.
- **`NCGR` round trip**: `a/0/3/1` 7/7, `a/0/3/2` 32/32 (both 100%),
  reusing `overworld.NcgrFile`/`verify_round_trip` unchanged.
- **Remaining gaps**: no name/index table was found mapping either
  archive's entities to actual in-game character names (player/rival/NPC
  class identity is by visual read only). `a/0/3/2` block 1's missing
  `*_loop`/`*_run` sequences (static-pose-only) were not investigated
  further -- possibly these characters never walk on-screen (e.g. fixed
  NPCs) or their movement uses a different, unfound animation source.

## Eleventh lane pass: text cipher/format confirmed from decompiled source (100% round trip); rig composer semantics re-derived from real bytes, still not recognizable

Two independent goals this pass, one against `src/matched/func_02045E3C.c`
(a newly-EXACT decompile of the message-bank string cipher itself) and one
against the mission's proposed NMCR/NANR composer model for `a/0/0/4`.

### Text banks (`tools/assets/text.py`): ground truth applied, previous gap closed

`func_02045E3C` (status EXACT) states the cipher directly, no reverse
engineering needed any more:

```c
u32 func_02045E3C(u16 *str, u32 count, u32 msgIndex) {
    u16 eos = func_02045A98();               /* 0xFFFF */
    u16 key = (u16)((msgIndex + 3) * 0x2983);
    for (i = 0; i < count; i++) {
        *str ^= key;
        if (*str == eos) return i;
        str++;
        key = rotl16(key, 3);
    }
    return count;
}
```

This is **forward-only** (no backward terminator-anchored key solve, unlike
the previous pass's guess) and `msgIndex` is the string's own **descriptor
index within its bank, 0-based** -- confirmed empirically before writing
any decoder change, against `a/0/0/2` sub-file 70 (species names): with
`msgIndex = i`, descriptor 1 decodes to `"Bulbasaur"`, descriptor 19 to
`"Rattata"`, descriptor 51 to `"Dugtrio"`, descriptor 100 to `"Voltorb"`,
byte for byte, first try.

The previous pass's descriptor layout was also wrong: the real shape (also
found by direct scan, not guesswork) is `entryCount` descriptors of 8 bytes
each at `section_offset[0] + 4 + 8*i` -- **no sentinel entry**, `i` runs
0..entryCount-1 and every one is a real string:

```
u32  offset      section-relative; absolute = 16 + offset
u16  numChars    informational only, not used to bound decoding
u16  flags       meaning undecoded, constant per bank
```

Confirmed by scanning every consecutive descriptor pair in sub-file 70:
the decoded length (through the `0xFFFF` terminator) of string `i` exactly
accounts for the byte gap to string `i+1`'s offset, 0 mismatches across
651 pairs -- strings are packed back-to-back with zero inter-string
padding.

Since XOR is its own inverse, **encode is the identical forward
XOR/rotate-left-3 procedure run on the plaintext** -- no separate key-
recovery direction, unlike the previous pass's two-directional scheme.
This also retired the previous pass's whole "9-bit packing" and
"dictionary/token compression" investigation: both were symptoms of the
wrong descriptor layout and the wrong (backward-solved) key, not a real
extra format layer. There is no compression on top of the cipher.

**Rendering**: `0xFFFF` terminator, `0xFFFE` newline (rendered `\n`),
`0xF000` escape (`kind(u16)`, `argCount(u16)`, then that many `u16` args,
all still part of the same encrypted stream -- rendered as
`{F000:KIND:arg1,arg2,...}`, hex). Everything else is a literal Unicode
code point (`chr(code)` directly -- this format's code units are Unicode
code points, not a GBA-style charset table), except `0x246D`/`0x246E`,
which this game uses for the male/female gender marks and which map
explicitly to U+2642/U+2640 (their own numeric values are not the real
Unicode code points for those glyphs). A handful of decoded values land in
the UTF-16 surrogate range (`0xD800-0xDFFF`); those cannot be valid
standalone code points in this scheme and are shown as `[xxxx]` rather
than fed to `chr()` (which would raise on encode).

**Verification** (`python tools/assets/text.py dump-all extract/data/a/0/0/2`,
`roundtrip-all`):

- **48839 / 48839 strings decoded and terminator-verified** across all 288
  sub-files -- exact match to the mission's target count.
- **288 / 288 sub-files byte-identical on round trip**: every string
  re-encoded (same forward procedure, same `msgIndex`) and the full
  string-data region reassembled reproduces the original sub-file bytes
  exactly (trailing pad bytes after the last string, where present, are
  copied verbatim since they aren't string data to begin with).
- Sample output (`build/assets/text/070.txt`, species names):
  `0	―――――` (species 0's placeholder, decodes to U+2015 HORIZONTAL BAR --
  confirms the "render non-ASCII as Unicode directly" rule), `1
  Bulbasaur`, `2 Ivysaur`, `3 Venusaur`, ...
- Sample escape usage (`build/assets/text/001.txt` line 1):
  `Once the saved data has been deleted,\nthere is no way to recover
  it.{F000:BE01:}\nIs it really OK to delete\nall saved data?` -- and
  (`003.txt` line 54): `Threw away {F000:0202:0001} {F000:0109:0000}.`,
  a plausible "throw away N of [item name]" template with an item-name
  substitution escape and a count/plural escape.

No open gap remains in this format: the cipher, the descriptor layout, the
control codes, and the round trip are all confirmed against decompiled
source and 100% verified against real data. `tools/assets/text.py` was
rewritten around this; the old backward-key-solve/9-bit-packing code paths
were deleted rather than kept alongside the new ones.

### Rig composer (`tools/assets/rig.py`): NMCR layout corrected from decompiled source, composer semantics re-tested, still not recognizable

`src/matched/func_020629E8.c` (status EXACT) indexes the multi-cell
descriptor array with `lsl #3` -- an 8-byte stride, not the previous
pass's 10-byte guess. `docs/notes/func_0206296C.c.txt` (near-miss, 120/124
bytes, semantics certain) names the fields directly:
`struct MultiCellData { u16 numNodes; u16 unk02; u32 nodes; }` (8 bytes)
and the bank header's own fixed-up pointers
(`bank->array` at +4, `bank->nodeBase` at +8, `bank->animBank` at +0x10).

Re-deriving the bank/descriptor offsets against species 25's real NMCR
bytes this pass found the previous pass's "self-relative, add to own field
position" convention (`mc_abs = 4 + mc_ofs_field`, `node_abs = 8 +
node_ofs_field`) does **not** fit: it lands the descriptor array on top of
the header and decodes to nonsense (`numNodes=0`/huge offset,
`numNodes=80`/huge offset). The fields are instead **plain absolute byte
offsets from the block body's start** (`mc_abs = mc_ofs_field`, `node_abs
= node_ofs_field`, no addition) -- confirmed two ways: (1) `mc_abs` then
lines up exactly with the end of the 24-byte header (the two trailing
`u16 unk` fields the previous pass already found at +0x14/+0x16 sit
immediately before it); (2) with this base, species 25's two 8-byte
multi-cell descriptors read as `(numNodes=10, nodeArrayOffset=0)` and
`(numNodes=10, nodeArrayOffset=80)` -- `80 == 10 * 8`, so the two groups'
node spans are exactly back-to-back and together consume the rest of the
body with **zero leftover bytes** (36..116 and 116..196 for a 196-byte
body). This is a clean, exact fit, unlike the previous pass's reading
(node array 8 bytes further in, "19 records with one label collision").

Node record (8 bytes), the mission's proposed layout, re-verified against
these corrected offsets: `{animSeqIdx(u16), posX(s16), posY(s16),
nodeAttr(u8)=0x20 constant, cellAnimSlot(u8)}`. For species 25 the 20
nodes' `animSeqIdx` values cover the NANR's 20 sequences **exactly once
each** (10 per multi-cell group) -- a clean bijection, replacing the
previous pass's messier "19 records, one label substitution" reading.

`compose_pose()` was rewritten to the mission's semantics: cell selection
is `NANR.sequences[node.animSeqIdx].frames[0].data.cellIdx` (not the
node's own `cellAnimSlot` byte, confirmed positional-only: it just cycles
0-9 twice with no per-part pattern), and placement is a straight sum
(`node.posX + oam.x`, `node.posY + oam.y`, no bounding-box re-centering,
no additional SRT scale/rotation since frame 0 is identity).

**Result: still not recognizable, and the root cause is now pinned down
precisely rather than suspected.** For species 25, 7 of the 8 resolvable
nodes' `animSeqIdx` all resolve to the **same NCER cell (cell 10, a
single-OAM cell)** via the NANR frame-0 lookup -- the composer is drawing
one small blob seven times at seven different offsets, not seven distinct
body parts. (2 of the 10 nodes' sequences have no frame data at all and
are skipped, with no fallback defined.) This is an exact re-confirmation,
now checked against every node rather than a sample, of what the eighth
pass already suspected and set aside ("NANR frame-0 cellIdx reads 10 for 7
of them ... cannot be right for an assembled figure with visually distinct
parts") -- the mission's literal formula, faithfully implemented against
byte-corrected offsets, reproduces the same failure. Species 1, 150 and 6
were also rendered (`build/assets/rig/0001_pose.png`,
`0150_pose.png`, `0006_pose.png`) and show the same non-coherent result;
species 6 additionally has **32 node records against only 17 NANR
sequences** (not a clean bijection there), so some nodes' `animSeqIdx`
don't resolve to any sequence at all for that species.

Individual NCER cells themselves (`build/assets/rig/0025_cells.png`, no
NMCR/NANR involved) are also small, sparse, fragment-shaped blobs rather
than clean body-part silhouettes at a glance -- this suggests the
remaining gap may sit upstream of the composer entirely (tile addressing
or OAM decode), not in the node-placement/cell-selection logic this pass
re-derived. Left for a follow-up pass rather than guessed at further here.

`--all` rendered 712/714 species/form slots without error (2 skipped:
indices 712/713 are non-rig slots, `RNAN`/`RLCN` magic where an `RGCN` was
expected -- almost certainly past the end of the real per-species block
range, not a decode failure).

**Honest verdict**: the byte-level layout corrections in this pass
(8-byte descriptor stride, absolute not self-relative offsets, the clean
20-node/20-sequence bijection) are real, confirmed fixes over the previous
pass's guesses, and the code is simpler and better-grounded for it. But
the mission's "recognizable creature" bar is **not met** by any of the
four species rendered this pass. `compose_rest_pose()` (the older,
NANR-free fallback strategy) is left in the module unchanged as a fallback

## Map-model mission: `a/0/0/8` is the overworld map/building/dungeon model archive; wrapper cracked (size table + BMD0 + per-tile grid); 3 OBJ exports; `nsbmd.py`'s GX decoder gained VTX_10/XY/XZ/YZ/DIFF support; format-5 (4x4-compressed) decoder implemented but not yet confirmed against a real instance

Two-part session on `tools/assets/nsbmd.py`: (1) locate the archive holding
overworld/area 3D map models, characterize any wrapper, export sample
models to OBJ; (2) re-read the TEX0 header for GX format 5 (4x4-compressed
texel) and decode one to PNG.

### (1) `a/0/0/8` identified as the map/building/dungeon model archive (previously mis-guessed "text banks")

The inventory's automated category guess for `a/0/0/8` (18.2 MB, 649
sub-files) was "text banks (guess)", based on its dominant raw-magic byte
patterns (`0x57420300` etc.) not matching any known NITRO/G3D magic at
offset 0 -- because every sub-file is wrapped in a small custom header
that pushes the real `BMD0` magic a few bytes in, rather than sitting at
offset 0 the way every other NARC's model sub-files do. A scan for `BMD0`
occurring **anywhere** in a sub-file's bytes (not just at offset 0) across
every NARC in the ROM found exactly one archive with this shape at scale:
`a/0/0/8`, 649/649 sub-files, `BMD0` at byte offset 16, 20 or 24 depending
on a wrapper tag (see below). No other NARC in the ROM shows this pattern.

Parsing the wrapped `BMD0` payload in each sub-file and reading its MDL0
model name confirms the category directly from the names themselves (no
guessing needed):

| name pattern | count | identified as |
|---|---:|---|
| `mapNN_MM` (grid coordinates) | 133 | outdoor terrain chunks, on a grid spanning roughly x=2..26, y=2..23 |
| `m_dunNNNN_00_00` | 200 | dungeon/cave interior rooms |
| `cNN_x00_00`, `h0N_xNN_NN`, `h01a/h01b` | ~300 | town/city building exteriors and interiors (numbered per-building, per-floor) |
| `pl_00_00` | 1 | the player's house interior |
| `map_outgrass`/`_outtree`/`_outrock`/`_outsea`/`_outdesert` | 5 | horizon/border fill terrain (edge-of-map filler beyond the real grid) |
| `champion_NN_NN` | 4 | the Champion's room |

This resolves the mission's "find the archive holding the area/terrain
and building NSBMD files" question with high confidence: **`a/0/0/8` is
that archive**, and it holds all three of terrain, dungeon and building
models together, not terrain alone.

### Wrapper format cracked: a small size-table header, then BMD0, then a fixed-size per-tile grid

Each `a/0/0/8` sub-file is `header || BMD0-model || per-tile-grid || tail`,
never a second BMD0 -- confirmed by scanning every sub-file for a second
`BMD0` occurrence (none found).

**Header** (variable length, first 2 bytes are an ASCII tag identifying
the variant seen; every variant's first `u32` after the tag equals the
header's own byte length, i.e. it doubles as "offset to the BMD0 payload"):

| tag | header bytes | count (of 649) |
|---|---:|---:|
| `WB` (+`\x03\x00`) | 20 | 572 |
| `GC` (+`\x04\x00`) | 24 | 47 |
| `NG` (+`\x02\x00`) | 16 | 22 |
| `RD` | (not fully characterized) | 8 |

After the tag and the payload-offset field, the remaining header `u32`s
are a small size table -- confirmed against real file boundaries: for the
20-byte (`WB`) case, `u32@8` marks the byte offset where the BMD0 model
chunk's own declared size ends (i.e. where the next section, the per-tile
grid, begins), `u32@16` equals the sub-file's total length. (`u32@12`'s
exact meaning wasn't pinned down -- it sits a handful of bytes before the
true end of the BMD0 chunk in the one case checked byte-for-byte, possibly
an alignment/padding boundary.)

**The per-tile grid (the mission's hypothesized "permission/height data"
wrapper) is real and directly follows the model, not inside the BMD0
itself:** its first 4 bytes are a `u16, u16` pair that reads `32, 32` in
every sample checked, followed by exactly `32*32 = 1024` 8-byte records
(`4 + 1024*8 = 8196` bytes, matching the measured region size in every
sample to within a handful of trailing bytes -- a few samples run 8-32
bytes longer, e.g. 8204 or 8228, not yet explained). This is confirmed as
genuine per-tile data, not a fixed shared table, two ways:

1. **Content varies by file** (each sub-file's grid block has a different
   MD5), ruling out "same boilerplate table copy-pasted into every file."
2. **Content varies by *terrain*, in the direction expected:** the flat,
   single-room building `h02_a00_00`'s grid has **exactly 1 distinct
   8-byte record value across all 1024 cells** (a uniform flat floor, as
   expected for a small indoor room with no elevation change), while the
   outdoor terrain chunk `map14_13` has 4 distinct records, the dungeon
   room `m_dun0101_00_00` has 7, and the larger outdoor chunk `map24_23`
   has 11 -- i.e. variety scales with how visually/structurally varied the
   real area is, exactly what a per-cell height/terrain-type/permission
   grid should do. This is strong (not proven) support for the mission's
   "permission/height data" hypothesis; the 8-byte record's internal
   sub-field boundaries were not decoded this pass (left as a gap -- the
   record clearly isn't a single flat byte, since multiple 16-bit lanes
   inside it vary independently across samples, but which lane is height
   vs. which is a permission/collision flag wasn't determined).

**Gap:** the trailing "tail" bytes after the grid (from the grid's end to
the sub-file's declared total length -- 148 bytes for `map14_13`, smaller
for others) were not investigated.

### GX geometry decoder gained real vertex-command support (`tools/assets/nsbmd.py`)

The existing `gx_decode()` only interpreted `VTX_16` (opcode `0x23`) for
vertex positions. Real map models in `a/0/0/8` almost entirely use the
*other* four vertex-emitting GX opcodes instead: sampling `map14_13`'s
decoded command stream found 1192 `TEXCOORD`, 557 `VTX_XZ`, 544 `VTX_XY`,
78 `NORMAL`, 57 `VTX_10`, 33 `VTX_YZ`, and just **1** `VTX_16` -- the old
decoder was silently emitting almost no geometry for these models (1
vertex, 0 faces) while still reporting thousands of "commands decoded,"
which would have looked like a working export. Fixed by implementing the
other four opcodes per the public documented GX vertex-command semantics
(a persistent "current position" register; `VTX_10` sets all three
components compactly, `VTX_XY`/`VTX_XZ`/`VTX_YZ` set two of three and
carry the third over, `VTX_DIFF` adds a small signed delta -- every one of
these, not just `VTX_16`, emits a new vertex). `map14_13` now decodes to
1192 vertices / 301 faces (was 1/0); round trip (`nsbmd.py roundtrip`,
unaffected by this change since it doesn't touch serialization) still
764/764 byte-identical on `a/0/4/9`.

`find_gx_stream`'s heuristic locator (byte-offset scan for the first run
of >=20 valid commands) still fails on some building interiors -- e.g.
`h02_a00_00`'s `MDL0.raw_tail` is only 408 bytes and the best run found is
13 commands with no vertices, even though the file's *outer* declared
BMD0 size (476 bytes, `struct` field at absolute offset 8) is far smaller
than the sub-file's total length (8696 bytes) -- most of that gap is the
per-tile grid described above, correctly excluded from `raw_tail`, so
this specific model may simply be geometry-free (a hitbox/trigger-only
placeholder) or use a still-unhandled opcode; not chased further this
pass. Sibling building models decode fine (see exports below).

### Three OBJ exports, `build/assets/maps/` (gitignored, regenerate, don't commit)

| file | source (`a/0/0/8` index, model name) | verts | faces | depicts |
|---|---|---:|---:|---|
| `map14_13.obj` | 44, `map14_13` | 1192 | 301 | an outdoor overworld terrain grid chunk (one cell of the map14/y13 tile in the route/town grid) |
| `m_dun0101_00_00.obj` | 279, `m_dun0101_00_00` | 2053 | 595 | a dungeon/cave interior room |
| `pl_00_00.obj` | 120, `pl_00_00` | 5114 | 1774 | the player's house interior |

Geometry only (positions + UVs, no per-face material/texture applied --
see next section for why). Exported with `nsbmd.write_obj()` after
manually stripping each sub-file's wrapper header and per-tile grid tail
(`payload = raw[raw.find(b"BMD0"):]`, then the existing `parse_container`/
`find_mdl0`/`find_gx_stream`/`write_obj` pipeline, unchanged).

### Textures: not wired up this pass (documented gap, not a false claim)

None of these BMD0 model chunks carry their own `TEX0` block (confirmed:
`parse_container` on each returns only `[MDL0]`). ASCII strings pulled out
of `map14_13`'s raw model data (material/texture reference names such as
`gake01a`, `grass01ax`, `michi01a`, `sea_mizu1`, `t01wd1`, `ue_grass00`)
were matched against `a/0/1/4` (11.9 MB, 282 `NSBTX` sub-files), which
carries the same names in its texture dictionaries -- so the outdoor
terrain texture set does live there, shared across (probably most or all
of) the 282 sub-files rather than one-per-map-tile. Actually decoding and
applying those textures per-face requires two things this session did not
finish: (a) linking each GX-stream `POLYGON_ATTR`/material-select command
to a specific texture name (not implemented -- the geometry decoder
currently ignores material commands entirely), and (b) decoding
*multi*-texture `TEX0` blocks at all, which `nsbmd.py` has never supported
(see the pre-existing "honesty note" in the module docstring: the TEX0
resource-dictionary per-entry record layout isn't cracked, so only
single-texture `TEX0` blocks can be decoded). This is an honest gap, not
a silent failure: the OBJ files above simply have no `mtllib`/material
assignment.

### (2) Format-5 (4x4-compressed) texture decoder implemented per public GX documentation; wired into `guess_single_texture`/`cmd_texture`; no real instance confirmed by eye this pass

**Later-pass resolution:** the "no real instance confirmed" open question
below is now closed -- see "NITRO resource dictionary CRACKED" further
down this document. Once the TEX0 dict's format field could be read
directly (not guessed), a ROM-wide scan of all 36,120 texture entries
found zero format-5 usage. The decoder implemented in this section remains
correct per spec and in the code, but this ROM never exercises it.

Added `decode_texture_4x4(width, height, region, palette)` to
`tools/assets/nsbmd.py`, implementing the public DS GPU "Compressed Texel
(4x4 Texel)" format: one 32-bit word per 4x4 block (16 texels, 2 bits
each -- a local index 0-3), followed **in the same region** by one 16-bit
index word per block (14-bit palette address in halfwords, 2-bit
interpolation mode selecting between the documented 4 per-mode colour
tables: mode 0 = `c0,c1,blend(c0,c1,5:3),blend(c0,c1,3:5)`, mode 1 =
`c0,c1,blend(c0,c1,1:1),transparent`, mode 2 = `c0,c1,pal[addr+2],pal[addr+3]`,
mode 3 = `c0,c1,blend(c0,c1,5:3),transparent`). This directly follows the
mission's re-reading of the TEX0 header: the region already recovered as
`texel_bytes()` (bounded by the existing, confirmed ordinary-texel-offset
and palette-offset header fields) is treated as `texel_words || index_words`
back to back, with `index_words` starting at `texel_size` (i.e. every
block's index sits at `this_block's_texel_offset / 2` into the trailing
index area, per the mission brief -- texel is 4 bytes/block, index is 2
bytes/block, a fixed 2:1 ratio). Wired into `guess_single_texture()` as a
new candidate shape (`(w/4)*(h/4)*6` bytes for a `w`x`h` texture, widths/
heights required to be multiples of 4) and into `cmd_texture`'s CLI path
(no longer hard-errors on format 5).

**What this pass could NOT do: confirm a real format-5 instance by eye.**
Two dead ends, both worth recording so the next pass doesn't repeat them:

- Texture names containing `4x4` (`t4x4hero`, `t4x4xocell`, `t4x4pokeflip`,
  5544 name-hits across the ROM) turned out to be a **red herring**:
  `t4x4xocell` (a/0/4/9#113, single-texture TEX0, `texture_data_size=512`)
  decodes cleanly as ordinary **format 3** (16-color, 32x32) -- the raw
  bytes are visibly a small nibble-per-pixel picture (a circular/target
  silhouette, legible directly in a hex dump) with a matching 16-entry
  BGR555 palette immediately after. `t4x4` here reads as an *authoring*
  convention (likely "4x4 UV-cell grid" in the source art tool), unrelated
  to the GX hardware's format-5 compression despite the identical name
  fragment. Don't use this naming pattern to locate real format-5 data.
- A whole-ROM scan of every **single-texture** `TEX0` block (`a/*/*/*`,
  every `BTX0`/`BMD0` sub-file) for a `(w, h)` where
  `(w/4)*(h/4)*6 == texture_data_size` (exact) found **zero** matches
  anywhere in the ROM; relaxing to "at most 32 bytes of trailing slack"
  found 117 near-matches, but every one checked (e.g. `a/0/7/5`'s
  `f_mark_u`/`c_mark_u`/... 8x16 UI direction-marker icons) matches
  **exactly** (zero slack) as ordinary format 3 instead, so these are also
  false leads, not padding. **Conclusion: this ROM's real format-5 usage,
  if any, lives inside *multi*-texture TEX0 blocks** (e.g. `a/0/4/9#199`,
  named `t4x4pokeflip.1..6`, 6 textures + 2 palettes sharing one 3072-byte
  region -- plausibly the Voltorb-Flip-style minigame's flip icons), which
  `nsbmd.py` cannot address individually without cracking the per-entry
  TEX0 dict record (the pre-existing, still-open "honesty note" gap from
  before this session -- not resolved here either). `3072 / 6 = 512`
  bytes/texture exactly matches plain **format 3** at 32x32
  (`32*32*4/8=512`) just as cleanly as it would need to for format 5, so
  even this candidate isn't confirmed to be compressed at all.

**Net result for mission (2):** the decoder is implemented, self-
consistent with the public spec, and wired into the existing CLI/guess
pipeline, but **no PNG was produced or eye-verified this pass** because no
real format-5 instance could be conclusively located within budget. This
is reported honestly rather than forcing a decode of a texture that's
more likely format 3. Unblocking this needs the TEX0 multi-texture dict
record cracked first (per-entry offset/width/height/format), which is a
larger, separate investigation.
reference point.

## Asset lane pass: trainer battle sprite search widened to non-NITRO fixed-size bitmap families -- thorough negative result (`tools/assets/battle_search.py`)

Second mission this pass: every earlier trainer-battle-sprite search
(docs/ASSETS.md "Trainer battle sprite mission") assumed the sprite is a
NITRO `NCGR`/`NCER` OAM-cell rig and came up empty. This pass drops that
assumption entirely and searches for a **fixed-size sub-file family**
instead -- the same style of evidence (`a/0/0/6`'s `" APS12_1"`/`" TPS"`
wrapper, `a/1/3/4`'s fixed 0x20000 payload) that has previously cracked a
custom, non-NITRO format in this ROM. New tool:
`tools/assets/battle_search.py` (`--sizes`, `--tags`, `--render`,
`--all`). Renders under `build/assets/battle_search/`.

### Method

Every one of the 247 files under `extract/data/` is opened as a NARC (10
fail to parse, e.g. `soundstatus.narc`/other non-container files, counted
and skipped) and every sub-file's **effective size** is recorded: the
on-disk length, EXCEPT for any sub-file that opens with a recognised BIOS
compression header (LZ77/LZ11/Huffman/RLE), where the header's own
declared decompressed size is used instead (via `narc.sniff_compression`,
no need to actually inflate 54054 sub-files just for a size census). This
matters: a compressed bitmap family would show a different *compressed*
length per member depending on content even though every member
decompresses to the same fixed canvas -- a census over raw on-disk
lengths alone would never see such a family as a family at all. This
was NOT done by any earlier trainer-sprite pass (`trainer_locate.py`'s
`--widen` only compares NCGR-declared tile counts after decompression,
not raw sub-file size).

### Fixed-size census: no family matches a plausible battle-portrait canvas

Checked directly: the mission's six candidate canvas sizes (4bpp
80x80/96x96/128x64 = 3200/4608/4096 bytes, their 8bpp doubles =
6400/9216/8192, each also checked +32 bytes for a trailing/leading
16-color palette) each occur **at most once** ROM-wide, bare or
with-palette -- there is no repeated family at any of these exact sizes
at all, let alone 100-400 members.

Widening to "every size occurring 100-400 times ROM-wide, checked within
+-600 bytes of a candidate size" (to allow for an unknown fixed header)
surfaces exactly one near-candidate: **3248 bytes, 113 sub-files across 6
archives** (95 of them in `a/0/7/2`) -- 48 bytes over the bare 80x80 4bpp
size. Rendered under every plausible layout (linear 4bpp/8bpp at 80,
8x8-tiled 4bpp): every layout, for samples from both `a/0/7/2` and a
second hit archive, renders as **pure noise** (`build/assets/battle_search/
a072_test_*.png`, `a_0_0_4_sf11094_sz3248_*.png`) -- no coherent shape, let
alone a human figure. This is consistent with, and extends, the previous
pass's direct finding that `a/0/7/2` is a trainer-card/badge HUD rig, not
a sprite archive.

The full 100-400-member family list (48 sizes) is otherwise made up of:
tiny (<1KB) structural-looking sizes repeated across many unrelated
archives (sub-headers, empty placeholder sub-files, common small
NCGR/NCLR/NCER shapes already characterized elsewhere in this document --
not examined further, too small to hold a battle portrait at any bit
depth); `a/0/4/9`'s own two internal families at 3464 (395 members,
mostly `a/0/4/9` plus one stray same-size hit in `a/0/5/2`) and 4544 (141
members) bytes, which is a **confirmed NSBMD/NSBTX 3D model/texture
archive** (`build/assets/inventory.json`: `"category_guess": "3D model/
texture data"`, 758 `BTX0` sub-files) -- rendered anyway for completeness
and confirmed noise, not a figure, consistent with being compressed
texture-page data, not a raw indexed bitmap; and a handful of large
(28-33KB) sizes in `a/1/9/4` (also texture-scale, two of which fail this
project's LZ77 decompressor and were skipped rather than guessed at) and
spread across many archives at 32832 bytes (100 members, 37 archives --
rendered, also noise). **No family in this census renders as a human
figure at battle scale under any tried layout.**

### Tag census: no second custom wrapper magic found

Every sub-file's first 4 and first 8 bytes were checked for "all
printable ASCII, not a magic this project already knows" (the reversed
NITRO chunk tags, `NARC`/BTAF/BTNF/GMIF, BIOS compression headers, and the
already-cracked `" APS12_1"`/`" TPS"` wrapper). 452 distinct 4-byte
candidates turn up, but essentially all resolve to noise or already-known
formats on inspection: `SBNK`/`SSEQ`/`SWAR` (4 hits each) are SDAT's own
already-known internal sub-chunk magics, not new; `BMA0` (69 hits, 17
archives) is a standard NNS_G2D "material animation" resource tag, a
sibling of the already-known `BTA0`/`BCA0`/etc. NSBMD-family magics, not a
sprite wrapper; the long tail (`'dddd'`, `'2AkV'`, `'RTFN'`, ...) is almost
entirely single-archive, mostly `a/0/1/6` (audio-adjacent, not
inspected further this pass) -- consistent with coincidentally-printable
bytes inside compressed or binary audio/model data, not a real magic. No
8-byte tag candidates were found at all (0 distinct). **No second
`" APS12_1"`-style custom sprite wrapper was found.**

### Report

- **Fixed-size bitmap family**: none exists at any of the mission's six
  candidate battle-portrait canvas sizes (bare or +32-byte palette),
  ROM-wide, at any population size. The single 100-400-member family
  close to a candidate size (3248 bytes, near 80x80 4bpp) is
  `a/0/7/2`-dominated and renders as noise under every layout tried --
  same archive already ruled out as trainer-card/badge HUD content by the
  previous pass. This is a genuine, thorough negative result, not an
  unexplored gap: every 100-400-member fixed-size family ROM-wide (48 of
  them) was either too small to hold a portrait, already a known
  non-sprite format (NSBTX textures), or rendered as noise.
- **Tag/size census**: recorded in this section; 452 printable 4-byte
  candidate tags found and triaged, none is a new sprite wrapper magic.
  Renders: `build/assets/battle_search/` (77 files -- every plausible
  layout for every 100-400-member family, plus the two `a/0/7/2`
  cross-check renders).
- **No archive in this search renders as a human figure at battle
  scale.** Combined with the previous pass's NITRO-shaped search (94
  large-NCGR archives, 38 large-OAM archives, all ruled out) and this
  pass's non-NITRO fixed-size search (48 families, all ruled out), the
  trainer battle sprite -- if 2D and present in this ROM at all -- is not
  a plain fixed-size raw/indexed bitmap and not a standard NITRO OAM rig.
  The two hypotheses this document has not yet tried remain open: a
  variable-size (not fixed-canvas) custom format not caught by either
  search style, or a 3D-rendered (NSBMD/NSBTX) representation -- `a/1/9/4`
  and `a/0/4/9`'s already-large texture archives are untried candidates
  for the latter, out of this pass's scope/budget.

## NITRO resource dictionary CRACKED: multi-texture TEX0 fully decodes, format-5 confirmed absent ROM-wide, MDL0 material/shape link found (`tools/assets/nsbmd.py`)

Mission: crack the G3D resource dictionary's per-entry record layout (the
"honesty note" gap open since the first NSBMD pass -- see "Container and
dictionary structure" above), so multi-texture `TEX0` blocks and map
materials can be decoded, not just listed by name.

### Dictionary layout: fully cracked and confirmed byte-exact

The previously-unexplained `unk4`/`unk6` dict-header fields (constant
`0x0008` and a per-dict-varying value respectively) are now understood:
`unk4` is the fixed byte offset to the patricia-tree node array (always
`8`, right after the 8-byte dict header) and `unk6` is the byte offset to
a 4-byte `{entrySize: u16, namesOffset: u16}` sub-header that immediately
follows the `(numEntries + 1) * 4`-byte node array. Confirmed exactly
(`unk6 == 8 + (count + 1) * 4`, `sub_header_offset + 4 + count * entrySize
== names_blob_start`) against every TEX0/palette dict sampled from 1 to
150 entries across `a/0/4/9` and `a/0/1/4`. New `ResDict.entries()`
(`tools/assets/nsbmd.py`) decodes this generically -- one implementation,
reused for TEX0 texture dicts, TEX0 palette dicts, and (see below) MDL0's
node/material/shape dicts.

The per-entry records themselves are also cracked and verified:
- **Texture entry, 8 bytes:** `u16 offset` (8-byte units, into the
  texel-data region), `u16 params` (the upper 16 bits of the hardware
  TEXIMAGE_PARAM register -- repeat/flip flags, S-Size, T-Size, format,
  color0-transparent, coord-transform mode), `u8 width8` (a redundant
  copy of width, confirmed equal to the decoded width in every sample),
  `u8 unk`, `u16 unk` (increases per texture within a dict, plausibly a
  VRAM-slot field, not decoded). `Tex0.texture_records()`.
- **Palette entry, 4 bytes:** `u16 offset` (8-byte units, into the
  palette-data region), `u16 flag` (seen `0x0000` everywhere checked).
  `Tex0.palette_records()`.

Confirmation method: decoded `(format, width, height)` from the `params`
bitfield for every texture in `a/0/1/1#0` (`batt_stage01`), `a/0/4/5#0`
(`item01`), and `a/0/4/9#2` (`in6_khone02`) -- the three single-texture
samples whose format/size were already independently confirmed by eye in
an earlier pass via `guess_single_texture()`'s brute-force search -- and
got **exact agreement in all three cases** (e.g. `params=0x2d20` decodes
to S-Size=2/T-Size=2/format=3/color0=1, i.e. 32x32 16-color with
transparent index 0, matching `item01`'s known-good decode exactly). This
is real confirmation, not coincidence: the bit positions were derived once
from the public TEXIMAGE_PARAM register layout and then checked against
three independently-verified answers.

### Multi-texture TEX0 decoding: implemented and eyeballed, no longer a gap

New `decode_all_textures(tex0)` and `texture_byte_size(fmt, w, h)` use the
cracked per-entry records to decode **every** texture in a TEX0 block
directly (exact offset/format/width/height per entry, no brute-force
search, no single-texture restriction) -- new CLI: `nsbmd.py textures
<file> -o <dir>` dumps one PNG per texture name.

Palette pairing (nothing in a texture record names its palette; that link
belongs to a real material, not decoded here) uses two strategies: (1) an
exact-name convention (`texture "foo"` pairs with `palette "foo_pl"`),
confirmed as a genuine 1:1 link on `a/0/1/4`'s 67-texture/67-palette
per-sub-file sets, used whenever the name exists; (2) a self-consistency
scoring fallback (same fraction-of-indices-in-range + index-range-fit
heuristic used elsewhere in this document) for dicts without that
convention, e.g. `a/0/4/9#199`'s 6-texture/2-palette `t4x4pokeflip` set.
One bug fixed during verification: palette *byte size* isn't stored in
the dict either, and an earlier version guessed it from the gap to the
next palette's offset -- broken by real dicts where two differently-named
palette entries share the exact same offset (`a/0/1/4#126`'s `gake01a_pl`
sat behind a duplicate-offset neighbor, truncating it to 8 colors and
producing an all-magenta, 0%-valid decode). Fixed by sizing each palette
load directly from the *requesting texture's own format* (`2**bpp`
colors), which is well-defined regardless of dict ordering.

**Verified by eye:** all 67 textures of `a/0/1/4#0`'s shared terrain
texture set decoded at `valid=1.000` (every palette index in range);
sampled several for visual coherence -- `grass01ax` (green streaky
texture, reads as grass), `mizu_sita2`/`sea_mizu1` (light-blue/white wave
patterns, read as water), `doukutu01` (structured, non-noise, though its
magenta/green colouring is unexpected for a cave texture -- flagged, not
chased further). All 6 textures of `a/0/4/9#199`'s `t4x4pokeflip` set
decoded coherently as small item/card-style icons on a flat background,
consistent with the earlier "Voltorb-Flip-style minigame" guess. PNGs
under `build/assets/textures/multi/` (gitignored, regenerate).

### Format 5 (4x4-compressed): confirmed absent from every texture in this ROM

With the real per-entry format field readable directly (no more guessing),
every texture entry in every `BMD0`/`BTX0` sub-file under `a/0`, `a/1`,
`a/2`, `titledemo.narc`, and `skb.narc` was scanned: **36,120 texture
entries across 1,732 TEX0 blocks, zero format-5 entries** (format
distribution: 27281 x 16-color, 4794 x 4-color, 2120 x A3I5, 1482 x A5I3,
443 x 256-color -- also zero format-7/direct-color entries anywhere).
This supersedes the previous pass's "unconfirmed, not chased further"
verdict on format 5 with a definitive negative result: the earlier
suspicion that format-5 data might hide inside *multi*-texture TEX0
blocks specifically (the one class the previous pass's single-texture-only
scan couldn't check) is now ruled out too, since this scan reads the
dict's format field directly regardless of texture count. **Conclusion:
this ROM does not use GX format-5 (4x4-compressed) textures anywhere**
-- `decode_texture_4x4()` remains implemented (correct per public spec,
previously wired in) but is confirmed dead code for this title's actual
asset set, not a lingering gap.

### MDL0 material/shape dictionaries: generic dict-signature scanner + a cracked render-command bytecode, applied to `pl_00_00`

Generalised the same "implement once, reuse" instruction to MDL0: new
`find_resdicts(buf)` scans arbitrary model bytes for anything matching the
confirmed generic ResDict signature (`revision==0`, the `unk4==8` /
`unk6==8+(count+1)*4` relationship, in-bounds size, all-printable-ASCII
names) instead of trying to crack the per-model header's own offset
fields (which, for `pl_00_00`, do NOT cleanly resolve to these sub-dicts
under one consistent base -- tried and abandoned). Run against
`pl_00_00`'s (`a/0/0/8#120`, wrapper-stripped) `MDL0.raw_tail`, it finds
five real dicts unassisted: a 1-entry node dict, a 40-entry "material"
dict (names like `gake01a_1`, `pk_l_kabe_1` -- a numeric-variant suffix
over the real texture name), a 39-entry dict of the bare texture names
(`gake01a`, `pk_l_kabe`, ...) matching real `a/0/1/4` texture dict entries
exactly, a 39-entry `_pl`-suffixed palette-name dict, and a 40-entry
`polygon0`..`polygon39` shape dict.

Also found, by generic byte-pattern scan (not project-specific knowledge,
a format-agnostic technique) rather than a documented spec: a small
"render command" bytecode region sitting between the node dict and the
material dict, decoding as alternating `(id, opcode)` byte pairs where
opcode `4` means BINDMATERIAL(id) and opcode `5` means DRAWSHAPE(id, using
the most recently bound material). New `find_render_commands(buf)`
generalises this into a reusable scanner (longest run of valid pairs).
For `pl_00_00` it decodes to a **complete, clean bijection**: all 40
declared shape indices matched to material indices (one material, index
11, used twice -- by shapes 9 and 39 -- everything else 1:1), an outcome
far too structured to be a coincidental byte-pattern match.

Combining shape->material (from the render commands) with
material-name->real-texture-name (strip the numeric variant suffix, e.g.
`pk_l_mado_4` -> `pk_l_mado`) gives a **confirmed, real, per-shape
material/texture link for all 40 shapes** of `pl_00_00` -- the mission's
literal "link map materials to textures by name" ask, achieved generally
(the same two functions apply to any MDL0 model, not just this one).
Cross-referencing those 38 distinct texture names against every `a/0/1/4`
sub-file found `#126` (and its near-duplicates `#127`-`#129`) carries all
38 -- the actual building-interior texture set for this and presumably
sibling player-house-style rooms.

**What's still a documented gap, not fabricated:** actually *dividing*
`pl_00_00`'s single merged 5114-vertex/1774-face GX command stream into
40 per-shape face groups was not achieved this pass. The shape dict's own
4-byte entry values (tried as byte offsets into the model, into a
post-dict "descriptor" region, and other bases) don't resolve to anything
recognisable, and empirically `gx_decode()` run from the stream's start
consumes the *entire* rest of the model's raw data in one unbroken run
(no invalid-opcode stop anywhere) -- meaning all 40 shapes' GX commands
are concatenated with no byte-level marker this pass could find. Rather
than fabricate a per-face split, the exported OBJ (`pl_00_00_textured.obj`)
uses the real geometry and real UVs (unchanged, previously-verified
pipeline) but tags the **whole merged mesh** with shape 0's real,
name-linked material (`pk_l_mado`, a window texture) as an honestly-
labeled single-material demonstration -- the OBJ's own header comment
says so explicitly. The full 40-entry shape/material/texture table (every
link, not just shape 0's) is preserved in this section and reproducible
via `find_resdicts()` + `find_render_commands()` against `a/0/0/8#120`.

### Result: `build/assets/maps/pl_00_00_textured.obj` + `pl_00_00.mtl` (gitignored, regenerate)

- `pl_00_00_textured.obj`: same 5114 verts / 1774 faces as the earlier
  geometry-only export, now with `mtllib`/`usemtl` (single representative
  material, see above) and UVs normalised against that material's real
  decoded texture size.
- `pl_00_00.mtl` + `build/assets/maps/pl_00_00_textures/*.png`: all 38
  real, distinct textures used by `pl_00_00`'s 40 shapes, decoded from
  `a/0/1/4#126` via `decode_all_textures()`, every one at `valid=1.000`.
  Spot-checked by eye: `pk_l_mado` (window -- gold/dark vertical banding,
  plausible for a window frame), `pk_l_kabe` (wall -- small dark tile,
  plausible), `pk_l_yane` (roof -- solid yellow gradient, structurally
  coherent though an unexpected colour choice for a roof at a glance).

### Summary for this pass

- **Dictionary layout: confirmed, not a gap anymore.** Generic parsing
  implemented once (`ResDict.entries()`) and reused for TEX0 textures,
  TEX0 palettes, and MDL0 node/material/shape dicts.
- **Textures decoded:** 36,120 texture entries scanned ROM-wide for the
  format-5 census (format distribution above); every texture in two full
  multi-texture TEX0 blocks decoded and eyeballed (67/67 for
  `a/0/1/4#0`, 6/6 for `a/0/4/9#199`); 38/38 real textures decoded for
  `pl_00_00`'s material set. **Format 5 (4x4-compressed): confirmed absent
  from this ROM's actual texture data**, a definitive result superseding
  the earlier "unconfirmed" status.
- **Textured OBJ:** produced for `pl_00_00` with real geometry/UVs and a
  real, name-confirmed material, honestly labeled as single-material
  (per-face multi-material assignment is the one remaining gap, blocked
  on the shape data's internal byte layout, not on the dictionary or
  material-link work this pass completed).
- **Remaining gaps:** (1) per-shape byte boundaries inside MDL0's merged
  GX command stream (blocks true multi-material OBJ export); (2) the
  `width8`/`unk8`/`unk16` texture-record fields and the palette `flag`
  field are decoded as raw values but not semantically interpreted
  (round-trip and pixel decoding don't need them, so not chased); (3) the
  MDL0 node dict (bone/joint data) and the render-command bytecode's
  other opcodes (only `4`/`5` were decoded; `pl_00_00`'s stream also has
  a leading `(0, 2)` and `(0, 1)` pair before the BINDMATERIAL/DRAWSHAPE
  run, and a trailing `(23, 43)`/`(1, 0)`, none interpreted) are open for
  a future pass on animated/skinned models.

## Asset lane pass: true post-decompression inner-magic census, all three NCGR+NCER+NANR-shaped candidates render correctly for the first time and are confirmed NOT trainer battle sprites (`tools/assets/inner_magic_census.py`)

Mission: find the trainer battle sprites by histogramming the INNER magic
of every compressed sub-file (decompress first, then read the magic) across
every NARC, not the outer/compressed-header magic `inventory.py` already
records. No earlier pass had done this: `inventory.py`'s magic histogram is
computed on raw on-disk bytes (a compressed sub-file's "magic" there is its
BIOS compression tag, not what it decompresses to); `trainer_locate.py
--widen` decompresses but only ever checks "is there a >=100-tile NCGR
here", never builds a full per-archive population of decompressed magics.
New tool: `tools/assets/inner_magic_census.py`.

### Method and ROM-wide result

Every NARC under `extract/data/` (237 of the 247 total files parse as a
NARC; the other 10 are lone SDAT/compressed-blob files with no sub-files
to census, same count as every earlier pass) is opened, and every
sub-file is resolved to its INNER magic: if it opens with a recognised
BIOS compression header (LZ77/LZ11/Huffman4/Huffman8/RLE), it is actually
decompressed (`narc.try_decompress`, all four kinds) and the first 4 bytes
of the DECOMPRESSED payload are recorded as the magic, alongside the real
decompressed size; otherwise the sub-file's own bytes are used directly.
ROM-wide inner-magic totals (top of the histogram): NCGR 9324, NCLR 4232,
NCER 3274, NANR 3274, NMCR 2960, NMAR 2960, NSBTX 1341, `" APS"` 774
(the already-cracked trainer-portrait wrapper), NSCR 609, NSBMD 413,
NSBCA 258, NSBTA 187, NSBTP 112 -- the long remaining tail is mostly
audio/model sub-chunk magics and short binary sequences that happen to be
printable, consistent with the existing "no second custom sprite wrapper"
finding from the previous pass's tag census.

### Shortlist: exactly 3 archives, all already-known candidates

Shortlist rule (per mission): NCGR + NCER + NANR ALL present in an
archive's inner-magic histogram, combined count in [100, 400]. Exactly
three archives qualify, ROM-wide:

| archive | bundle_count | NCGR | NCER | NANR | NCLR | largest NCER cell bbox |
|---|---|---|---|---|---|---|
| `a/0/8/3` | 132 | 66 | 33 | 33 | 37 | 96x96 (pass) |
| `a/0/7/8` | 157 | 55 | 51 | 51 | 7  | 136x48 (fail -- one dim <64) |
| `a/0/7/2` | 380 | 190 | 95 | 95 | 95 | 80x80 (pass) |

All three are already-documented candidates from the "Trainer battle
sprite mission" pass (`a/0/7/8`/`a/0/8/3` characterized by
`trainer_locate.py --candidates`, `a/0/7/2` by the original locate pass
and the fixed-size census pass) -- this census did not surface any new
archive, confirming the earlier passes' coverage was complete for this
shape of search. The `>=64x64` OAM cell-size filter (read directly off
each NCER's shape/size attribute bits via `rig.Oam`) is computed here for
the first time as a programmatic check rather than eyeballed from a raw
tile-grid render.

### Rendering: two real compositing bugs fixed, both candidates now render correctly for the first time

Rendering two samples per shortlisted archive (palette-applied, proper
per-OAM placement -- not `trainer_locate.py`'s raw tile-grid dump) surfaced
two real bugs in every prior raw-dump-based identification of these same
three archives:

1. **NCER `mapping_type` was never applied.** A cell bank's `mapping_type`
   (0/1/2 = 32B/64B/128B tile-stride boundary, see `overworld.py`'s
   module docstring) scales what an OAM's `tile_idx` field actually
   addresses; reading it as dense (mapping_type 0) when the real value is
   1 or 2 silently under-addresses every tile past the first. `a/0/7/2`'s
   per-entity NCER declares mapping_type 1; naive dense addressing turned
   its main 64x64 OAM into near-total transparency.
2. **NCGR `char_format` 1 ("bitmap") was never handled outside `rig.py`.**
   `trainer_locate.py`'s `RawNcgr` (used by every earlier raw-dump render
   of these three archives) always reads tile data as flat 8x8-tiled
   blocks. `a/0/7/2`'s per-entity NCGR declares `char_format=1`: a linear
   `tile_num_x*8` x `tile_num_y*8` bitmap where a cell's tile index
   addresses a 2D block POSITION, not a flat offset (the same distinction
   `rig.py`'s own docstring identifies as "the fifth lane pass's pixel-
   layout bug", but never propagated to `trainer_locate.py`). Dense
   addressing against this format produces near-empty noise.

`inner_magic_census.py`'s new `FlexNcgr` (char_format-aware) and
`render_oam_generic`/`render_cell_generic` (mapping_type-aware) fix both;
`--render-shortlist` renders two samples per shortlisted archive to
`build/assets/trainer_census/`.

### Identification: all three confirmed non-sprite, with much stronger evidence than before

- **`a/0/7/2`** (samples: `a_0_7_2_ncer0002_ncgr0001_pal0007.png`,
  `..._ncer0010_ncgr0009_pal0007.png`): the corrected render shows a
  filled red-and-white **Poke Ball icon** occupying the main 64x64 OAM,
  plus a small, separate **cropped trainer-portrait face fragment**
  (visible hair/skin/eye pixels) tucked in one corner of the same 80x80
  cell in every sample checked. This is a trainer-card/badge composite
  (insignia + tiny face icon), not a full animated battle sprite --
  **confirms** the existing "trainer-card/badge rig" finding from the
  fixed-size census pass, now with a real composited image instead of a
  noise verdict from a wrong-layout guess.
- **`a/0/8/3`** (samples: `a_0_8_3_ncer0081_ncgr0074_pal0073.png`,
  `..._ncer0082_ncgr0074_pal0073.png`): both largest-cell samples render
  as a plain **8-swatch colour gradient bar** (a 16-tile NCGR, mostly
  empty 96x96 canvas with the swatch bar in one corner) -- a gauge/meter
  UI element, not a sprite. **Confirms** the existing "battle/menu HUD
  graphics" finding.
- **`a/0/7/8`** (samples: `a_0_7_8_ncer0080_ncgr0061_pal0006.png`,
  `..._ncer0081_ncgr0061_pal0006.png`, both fail the `>=64x64` filter at
  136x48): renders as a small **repeated UFO/mushroom-shaped creature
  icon** (a status- or item-icon shape, tiled across the contact sheet),
  not a human figure. **Confirms** the existing "battle/menu HUD
  graphics" finding.

### Report

- **Inner-magic census**: `tools/assets/inner_magic_census.py`, full
  ROM-wide results in `build/assets/inner_magic_census.json` (237
  archives). Summary above.
- **Shortlist**: exactly 3 archives meet the NCGR+NCER+NANR-bundle,
  100-400-count, >=64x64-cell criteria: `a/0/7/2`, `a/0/8/3` (pass the
  size filter), `a/0/7/8` (fails it). All three were already
  characterized by earlier passes; this pass adds no new candidate.
- **Renders**: `build/assets/trainer_census/` (6 files, two per
  shortlisted archive, palette-applied, mapping_type- and char_format-
  aware compositing).
- **Identification**: none is a trainer battle sprite. `a/0/7/2` is a
  trainer-card/badge icon (Poke Ball + cropped portrait fragment);
  `a/0/8/3` is a HUD gauge/gradient-bar element; `a/0/7/8` is a small
  repeated creature/status icon. All three corroborate, rather than
  overturn, prior negative findings -- but now backed by correctly
  composited renders instead of raw tile-grid dumps or fixed-size-only
  checks, closing the specific gap ("was the raw-dump renderer wrong, not
  the archive identification?") that made those earlier negative results
  slightly less certain.
- **Bundle format / `--all` render count**: not applicable -- no archive
  in this ROM was found to hold trainer battle sprites in an
  NCGR+NCER+NANR bundle shape (or any shape tried by this or the previous
  five trainer-sprite passes combined). The trainer battle sprite, if
  present in this ROM as 2D NITRO content at all, is not addressable by
  any magic-histogram, fixed-size, or OAM-cell-size search this project
  has tried; remaining untried avenues (a 3D NSBMD/NSBTX representation,
  a wholly custom variable-size format) are the same ones the previous
  pass already flagged as out of scope/budget.
- **Bugs fixed along the way, reusable for future passes**:
  `inner_magic_census.py`'s `FlexNcgr` (char_format-0-tiled/char_format-1-
  bitmap-aware NCGR reader, safe against the `0xFFFF` tile_num_x/y
  sentinel) and `render_oam_generic`/`render_cell_generic`
  (`mapping_type`-aware OAM tile addressing) are both general-purpose
  fixes over `trainer_locate.py`'s dense-only `RawNcgr` and
  `overworld.py`'s mapping_type-0-only compositing -- worth reusing for
  any future archive whose NCER declares `mapping_type` 1/2 or whose NCGR
  declares `char_format` 1.

## Twelfth lane pass: the `a/0/0/4` rig poses -- NANR sequence record and OAM tile addressing both corrected from the game's own code, 712/714 species rendered

Mission: settle two rules from the decompiled G2D module rather than by
guessing, then fix `tools/assets/rig.py`. Both rules came out wrong in every
previous pass, and fixing them is what finally clears the "recognizable
creature" bar that has been open since the fifth lane pass. Species 25, 1, 6
and 150 were rendered and inspected directly; all four are unmistakable.

### Rule 1 -- the NANR sequence record: `func_02062688` (the `KNBA`/ABNK fixup) states it outright

The animation bank's offset-to-pointer fixup routine at **0x02062688** walks
the whole structure adding base addresses to exactly the fields that are
offsets, so both the field positions and the base each offset is relative to
are directly observable:

```
bank +0x00 u16 numSequences        sequence +0x00 u16 numFrames
     +0x02 u16 numTotalFrames               +0x02 u16 loopStartFrameIdx
     +0x04 -> sequence array (16B)          +0x04 u32 animType
     +0x08 -> frame-entry array (8B)        +0x08 u32 playMode
     +0x0C -> frame-data pool               +0x0C -> this sequence's frames,
     +0x14 -> embedded sub-resource               relative to bank +0x08
```

The fixup adds `bank->frameArray` into each sequence's +0x0C, then walks that
sequence's own `numFrames` frame entries adding `bank->frameDataPool` into
each entry's first word. **A sequence's frames are therefore a contiguous run
of the shared frame-entry array located by its own +0x0C byte offset** -- not,
as the eighth pass read it, by a start index stored at +0x00. The 16-byte
sequence stride is independently pinned by `func_020627D8`'s `lsl #4` (now
filed EXACT), and the 8-byte frame-entry stride by `func_020643CC`'s
duration-summing loop at 0x020644B8.

What the eighth pass actually had: the u32 at +0x00 is `numFrames |
loopStart << 16`, and the u16 it read as `num_frames` at +0x04 is `animType`'s
low half (constant 1 or 2 here). So every sequence looked one frame long and
every frame lookup landed on entry number `numFrames` of the shared array
instead of on that sequence's own first frame. **That is the complete
explanation for the eleventh pass's "7 of 8 nodes resolve to the same NCER
cell"**: the lookups were reading a near-arbitrary common region. Species 25's
bytes confirm the corrected reading exactly -- the 20 sequences' frame offsets
run 0, 144, 392, 536, ... 3216, each the running sum of the preceding
`numFrames * 8`, the last sequence's single frame landing on entry 402 of
`numTotalFrames = 403`: a clean partition with zero leftover entries. With the
corrected walk species 25's ten rest-pose nodes resolve to **ten distinct
cells** (6, 5, 10, 0, 3, 2, 1, 4, 7, 8 of 11).

The frame-data record shape is chosen by `animType & 0xFF`, the renderer's own
mask (`func_0206419C` +0x4C), and **all three shapes really occur in this
archive**, which is why always decoding the 16-byte one was also wrong:

| type | record | species 25 uses it for |
| --- | --- | --- |
| 0 index | `{u16 cellIdx}` | the feet |
| 1 SRT | `{u16 cellIdx, u16 rotZ, s32 sx, s32 sy, s16 px, s16 py}` | most parts |
| 2 T | `{u16 cellIdx, u16 pad, s16 px, s16 py}` | the head |

The px/py field positions are read straight off `func_0206419C`: +0x04/+0x06
for type 2, +0x0C/+0x0E for type 1. The eighth pass's "sx/sy read 4096 == FX32
1.0" observation stands, so frame 0 needs no affine transform.

### Rule 2 -- OAM tile addressing: the sheet is a linear bitmap and the index is two-dimensional

Two independent errors, both in the same place:

1. **`a/0/0/4`'s main NCGR is in bitmap character format, not tiled.** The
   RAHC body's u32 at +0x0C is `char_format`: local 2 declares **1** (linear)
   while the small local-0 sheet declares 0 (tiled). Reading the linear sheet
   as 8x8 tiles is what turned every body part into 8-pixel-tall horizontal
   streaks in every render from the fifth pass onward -- rendering the same
   bytes as a plain 256x128 4bpp image instead immediately shows Pikachu's
   head (red cheek included), ears, tail and feet laid out as an atlas.
2. **An OAM's tile index is a 2D block index, not a flat byte offset.** Block
   `i` sits at column `i % tile_num_x`, row `i // tile_num_x`, and an OAM
   taller than one block steps by `tile_num_x` per block row rather than by
   its own width. Species 25's cell 0 proves this from the data alone with no
   code reading needed: a 16x16 OAM at index 99 is immediately followed by an
   8x16 OAM at index 101, which can only avoid overlapping if the first
   consumes blocks 99/100 and 131/132 (two rows of a 32-wide sheet) rather
   than the four consecutive blocks 99..102. The `mapping_type = 4` the fifth
   pass read out of the NCER header is not a byte stride under this reading
   and plays no part in it.

The cell-array / OAM-array split this module already used is separately
confirmed by the game: `func_020627F0` returns the address one past the last
cell record (8 bytes per cell, 16 when the bank attribute's bit0 is set) and
`func_02062884` adds exactly that into every cell's own offset field.

Note that the census pass above already found the `char_format` bug in
`trainer_locate.py` and credited `rig.py`'s docstring with the distinction;
in fact `rig.py` had never handled it either. It does now.

### Node semantics, re-confirmed (not changed) from `func_020643CC`

The eleventh pass's node reading is right and is now witnessed by the walk the
game runs: `func_020643CC` steps the node array by 8 bytes, passes the u16 at
+0x00 straight to `func_020627D8` as a **sequence index**, takes the byte at
+0x07 as a cell-animation **slot** (`func_02064648` sizes that array of
0x5C-byte states from the descriptor's `numCellAnims`, which is why the byte
just counts 0, 1, 2, ...), and hands the s16 at +0x02/+0x04 to `func_020640DC`
as the node's x/y translation. So cell selection is never the node's own
business: the node names a sequence, the sequence's current frame names the
cell. Placement is a straight sum of the node's (posX, posY), the frame's own
(px, py) and each OAM's cell-local (x, y) -- no bounding-box re-centering; the
seventh pass's bbox-center anchor was a workaround for the broken cell
assignment and is now deleted along with the dead `compose_rest_pose()`.
Nodes are painted back-to-front (last node first), since they are emitted into
the hardware OAM list in array order and a lower OAM index draws in front.

### Result: the bar is met

`build/assets/rig/0025_pose.png` (59x56) is **unmistakably Pikachu** --
correct silhouette, black-tipped ears, eye, red cheek, tail, feet -- checked
by direct visual inspection at 6x nearest-neighbour, not inferred from pixel
statistics. `0001_pose.png` (53x55) is unmistakably Bulbasaur (bulb, blue-green
body, red eye), `0006_pose.png` (95x96) unmistakably Charizard (orange body,
blue wings, tail flame), `0150_pose.png` (85x82) unmistakably Mewtwo (grey
body, purple tail and belly, head crest). Spot checks across the batch:
`0094.png` is Gengar, `0643.png` is Reshiram. The per-cell contact sheet
`0025_cells.png` now shows clean, individually recognizable body parts (head
with cheek, body, two ears, tail, hands, feet) instead of fragments.

`--all` renders **712 of 714 slots**, the same two trailing non-rig slots
(712, 713) skipping cleanly as in previous passes.

### Functions filed EXACT this pass

- `src/matched/func_020627D8.c` (pkt_02061EB8) -- animation-bank sequence
  lookup; its `lsl #4` is the 16-byte sequence stride, and the header block
  records the full ABNK layout that `func_02062688` proves.
- `src/matched/func_0206285C.c` (pkt_02062820) -- cell lookup by index, whose
  `tst #1` plus twin shifts pin the 8-vs-16-byte cell stride.

Both verified with `match.py one` and gated with `manifest --verify --shard`.

### Remaining gaps

- **`func_020627F0` is a 23-of-32-byte near miss**, parked in
  `docs/notes/func_020627F0.c.txt`: the original loads `bank->cells` once per
  branch arm and -O4,p common-subexpression-eliminates the two loads in every
  spelling tried (void pointer plus casts, a union of the two cell-pointer
  types, two differently typed bank structs). Semantics are certain; only the
  duplicated load is unexplained.
- **`func_02062688` (the ABNK fixup) and `func_02062884` (the CEBK fixup) are
  read but not decompiled.** Both are the direct witnesses for the rules
  above and are the obvious next EXACT targets; `func_02062884`'s redundant
  re-store of the VRAM-transfer pointer at +0x0C looks like the same
  store-then-reload idiom that capped `func_0206296C` at 120/124 bytes.
- **Some species place a few parts detached from the body** (Charizard's feet
  sit below the figure, Gengar has an arm and a leg off to the right). The
  figure is still unambiguous in every case checked, and the same node/frame
  path produces perfectly assembled results for species 25/1/150, so this is
  more likely a per-species authored frame-0 extreme (or a second multi-cell
  group being the intended rest assembly for those species) than a decode
  error -- not chased this pass.
- Only multi-cell group 0 is rendered; group 1 (identical node count, a
  different sequence set) is parsed but unused, and the `--anim`/`--frame`
  flags remain informational. `compose_pose()` does now take a `frame`
  argument, so animating a sequence is a small step from here.
- The `nodeAttr` byte's low nibble (0 or 1, selecting `func_020643CC`'s
  duration-summing path) and the NMAR resource are still undecoded; neither
  is needed for a static pose.

## Asset lane pass: the other 41 `" APS12_1"` wrappers found and decoded -- confirmed a shared particle/UI-effect format, not a second trainer-sprite home

Mission: the inner-magic census (`build/assets/inner_magic_census.json`)
totals 774 `" APS"` inner-magic hits ROM-wide, but `a/0/0/6` alone only
accounts for 733. Find, decode, and identify the other 41.

### Where they live

Filtering the JSON for every archive with a nonzero `" APS"` count besides
`a/0/0/6` gives 10 archives, summing to exactly 41:

| archive | `" APS"` count | sub-file indices |
|---|---:|---|
| `a/0/3/4` | 1 | 38 |
| `a/0/4/7` | 4 | 51, 52, 53, 54 |
| `a/0/7/6` | 2 | 27, 28 |
| `a/1/0/3` | 1 | 53 |
| `a/1/0/4` | 1 | 10 |
| `a/1/1/5` | 8 | 0, 8, 15, 57, 65, 70, 95, 115 |
| `a/1/8/1` | 4 | 10, 11, 12, 13 |
| `a/1/8/2` | 1 | 10 |
| `a/1/8/9` | 1 | 10 |
| `a/2/1/6` | 18 | 34-51 |

All 41 sub-files are uncompressed on disk (`narc.sniff_compression`
returns `None` for every one, verified directly, not inferred from the
census) and open with the exact same `b" APS12_1"` magic and `" TPS"`
sub-chunk structure `trainer.py` already parses for `a/0/0/6` -- same
36-byte TPS header, same trailing-32-byte BGR555 palette convention. No
new container format was needed; these are the same wrapper reused by
other archives, not a distinct format.

### Generalizing the pixel-canvas decoder

The existing `decode_frames()` hard-coded a 32x32/1024-byte canvas
(`FRAME_PIXEL_BYTES = 0x400`, `FRAME_WIDTH = 32`) on the strength of
`a/0/0/6`'s 3 originally-sampled sub-files. Dumping every TPS chunk's
declared `pb` field (`+0x08`) across all 41 new sub-files (plus a
re-check of `a/0/0/6` itself) shows `pb` actually takes 6 distinct
values: `0x40` (64), `0x100` (256), `0x200` (512), `0x400` (1024),
`0x1000` (4096), and (only in `a/2/1/6`) `0x10000` (65536) -- confirming
the re-encoder pass's earlier finding that `pb` is not a format-wide
constant, now with a wider value range than the 0x400/0x1000 seen before.

`trainer.py` gained `guess_canvas_width(pb)`: when `pb` is a perfect
square, the chunk is a square canvas of that side length (0x40 = 8x8,
0x100 = 16x16, 0x400 = 32x32, 0x1000 = 64x64, 0x10000 = 256x256 --
matching this mission's own worked examples for 0x1000/0x1900/0x2400);
otherwise (only `pb = 0x200 = 512` is non-square, seen once, in
`a/1/8/2` sub-file 10 chunk 3) it falls back to the legacy fixed
32-pixel row width. The small per-chunk sub-table (`subtable_len` bytes
at `+0x24`, `TPS_FIXED_HEADER_LEN`) does **not** carry an explicit
width/height anywhere it was checked: every sub-table byte across all 41
new sub-files plus a re-check of the original 3 is either all-zero or a
single repeated filler byte (`0x08`, `0x20`, `0x50`) -- never a
plausible dimension pair -- so the "read width/height from the
sub-table" fallback this mission asked about is not available in
practice; `guess_canvas_width()` never attempts it. `decode_frames()` now
also uses each chunk's own clipped `pixel_len` (the same
`min(pb, next_boundary - pix_start)` rule `parse_full()` already used for
the re-encoder) instead of a hard-coded 1024-byte read, so a canvas that
runs short against the next chunk or the trailing palette is cropped to
whole rows exactly as before, just no longer capped at 1024 bytes.
Verified non-regressing: `python tools/assets/trainer.py --all` still
decodes all 733 `a/0/0/6` sub-files with 0 failures, and
`--verify-reencode` (untouched -- `parse_full`/`reencode_full` do not go
through `decode_frames()`) still reports 733/733 byte-identical.

`--archive` already existed on `trainer.py`'s CLI from the earlier
re-encoder pass; this pass added `archive_tag()` and a `tag=` parameter
to `decode_one()` so a non-default `--archive` run prefixes its output
filenames with the archive path (`a_1_8_2_0010_f2.png`), avoiding
collisions across archives in a shared output directory. `a/0/0/6`'s own
default output naming (`NNNN_fF.png`, no prefix) is unchanged.

### Re-rendered `a/0/0/6` sub-files 0 and 1 at 64x64

Both declare `pb = 0x1000` (4096) on their single/first TPS chunk, and
(checked directly) both sub-files are large enough to actually supply
most of a 64x64 canvas -- sub-file 0 is 4284 bytes with 4060 usable pixel
bytes (63 full 64-pixel rows), sub-file 1 is 8564 bytes with 4092 and
4060 usable pixel bytes across its 2 chunks (63 rows each). The earlier
pass's 32x32 renders were therefore not full-canvas crops of noise, but
genuine top-left crops of a real 64x64 image -- and this pass confirms
what the missing 3/4 of the canvas holds: **still nothing new**. Sub-file
0 renders as an all-black/empty 64x64 frame (same near-empty white-only
16-entry palette as before; the extra rows beyond the original 32x32 crop
are genuinely blank, not a hidden shape the old crop cut off). Sub-file
1's two frames render as
the same 4-point sparkle/glint silhouette seen before, now visible in
full at 64x64 rather than cropped, plus a second still-blank frame. No
human silhouette, no additional detail beyond the "sparkle" shape already
documented. **This directly confirms**, rather than overturns, the
existing "glint/particle effect, not trainer portrait" reclassification
of `a/0/0/6` -- re-renders at `build/assets/trainers/0000_f0.png` and
`0001_f{0,1}.png` (filenames unchanged, contents updated).

### The 41: rendered and identified -- a shared particle/UI-effect format, no trainer figures

All 41 decode cleanly (0 errors) to `build/assets/aps_other/<archive
tag>_<index>_f<frame>.png` (75 PNGs total, since several sub-files carry
multiple TPS-chunk frames -- `a/2/1/6`'s 18 hits are 18 single-frame
sub-files while e.g. `a/0/4/7` sub-file 54 alone carries 6). Visually
inspected every sub-file (all frames for the smaller archives, at least
one representative frame per sub-file for `a/2/1/6`'s 18). None depicts a
human figure at any scale. What they actually show, by archive:

- **`a/2/1/6`** (18 sub-files, all but one at `pb = 0x10000` = 256x256,
  the largest canvas found anywhere in this format): a **weather-overlay
  particle set** -- sub-file 34 is a repeating radiating-ray/web motif
  (sunlight-ray pattern), 36 is repeating blue claw/wave-scratch shapes,
  40 is a field of parallel diagonal blue streaks (rain), 44 is an
  unambiguous tiled **field of snowflakes** (hail/snow), 48 is a tiled
  field of brown teardrop shapes (sand/dust, i.e. Sandstorm), and 51 (the
  one sub-file with `pb = 0x1000` instead) is another 64x64 sparkle,
  matching the small-glint family seen everywhere else. This reads as the
  battle weather-effect overlay archive (Rain/Sun/Hail/Sandstorm-style
  full-screen particle fields), not a sprite archive of any kind.
  Sub-file 40's diagonal-stripe render has a visible seam artifact (an
  adjacent-row autocorrelation scan for the true stride peaks at 128-130
  px, not the 256 used) that this pass did not chase further -- flagged
  as an open item below; it does not change the weather-effect
  identification (36/44/48 are unambiguous at the declared 256x256 and
  corroborate it).
- **`a/0/3/4`, `a/1/0/3`, `a/1/0/4`**: animated expanding/contracting
  ring and diamond-of-dots shapes across their multi-frame sub-files
  (solid ring -> gap -> dotted wider ring -> diamond of dots -> gap, for
  `a/1/0/3` sub-file 53's 5 frames; a similar solid-ring-to-diamond
  sequence for `a/1/0/4` sub-file 10's 3 frames) -- a target-lock/capture
  "ring" effect animation, the same family already seen in `a/0/0/6`'s
  own ring/reticle-shaped samples.
- **`a/0/4/7`**: a mix of a purple/black blob-splash shape (sub-file 52's
  64x64 frame -- reads as a poison/sludge or ink-splash impact effect), a
  sparse scattered-dot sparkle (sub-file 53), and small (16x16) fragments
  too low-resolution to identify beyond "UI icon piece" (sub-file 51).
- **`a/0/7/6`, `a/1/1/5`, `a/1/8/1`, `a/1/8/2`, `a/1/8/9`**: the same
  small glint/sparkle/scattered-dot shapes and near-empty frames already
  characterized for `a/0/0/6`, plus one clean diamond/rhombus
  concentric-color target-reticle icon (`a/1/8/2` sub-file 10, frame 2,
  64x64) -- all consistent with a general-purpose small animated
  status/particle icon, reused wherever a menu or battle screen needed
  one, not with any per-trainer or per-species resource.

**Conclusion: not a second trainer-sprite home.** The " APS12_1"/" TPS"
wrapper is confirmed (now across 11 archives and 774 total sub-files) to
be this ROM's general-purpose small animated particle/effect/icon sprite
format -- sparkles, rings, splashes, and (in `a/2/1/6`) full-screen
weather overlays -- not a trainer-specific container. No pairing to a
trainer-class table was attempted since no sub-file in this set shows
trainer-shaped content to pair.

### Report

- **Locator**: no new tool file -- 41 hits found directly from
  `build/assets/inner_magic_census.json`'s existing per-archive
  histograms (filter for a nonzero `" APS"` entry outside `a/0/0/6`),
  cross-checked against the ROM by re-opening each archive and
  confirming every hit is an uncompressed `b" APS12_1"` sub-file.
- **Decoder**: `tools/assets/trainer.py`'s `decode_frames()` generalized
  via new `guess_canvas_width()` (perfect-square `pb` -> square canvas,
  else the legacy 32px-wide fallback) and per-chunk clipped `pixel_len`
  (reusing the re-encoder's own boundary rule) instead of the old
  hard-coded 32x32/1024-byte canvas; `decode_one()`/`main()` gained
  `archive_tag()`-based output filename prefixing for non-default
  `--archive` runs. `--archive` itself already existed. Regression-safe:
  733/733 `a/0/0/6` sub-files still decode with 0 failures and
  733/733 still round-trip byte-identical through the untouched
  re-encoder.
- **Renders**: `build/assets/aps_other/` (75 PNGs, all 41 sub-files' TPS
  chunks); `build/assets/trainers/0000_f0.png` and `0001_f{0,1}.png`
  re-rendered at the full 64x64 canvas (previously cropped to 32x32).
- **Identification**: `a/2/1/6` is a battle weather-overlay archive
  (rain/snow/sand/sun-ray particle fields at 256x256); the remaining 8
  archives hold assorted small glint/sparkle/ring/splash status-effect
  icons, the same family already documented for `a/0/0/6`. No human
  figure, no trainer-shaped content, anywhere in the 41.
- **Remaining gaps**: `a/2/1/6` sub-file 40's true canvas stride is not
  fully confirmed (256x256 renders with a visible diagonal seam; a naive
  adjacent-row autocorrelation favors ~128-130px instead, but that scan
  is not trustworthy against a real diagonal-streak image the way it was
  against the radially-symmetric glints in earlier passes, so this is
  left open rather than "fixed" by guessing). The single non-square `pb
  = 0x200` chunk (`a/1/8/2` sub-file 10, chunk 3) is decoded via the
  legacy 32px-wide fallback, unverified against any independent evidence
  of its true width. The trainer battle sprite itself remains not
  located by this or any prior pass.

## Asset lane pass: the `a/0/0/4` rig animates -- per-frame composition, GIF export for all 712 species, group 1 identified as a second animation, detached parts explained but not fixed

Mission: make the twelfth pass's static pose move. (1) per-frame composition
(index/T/SRT frame-data records applied at an arbitrary elapsed time, not
just frame 0); (2) an animation strip PNG and a looping GIF (own stdlib
LZW/GIF89a writer, no other project's code) for species 25, then GIFs for
every species; (3) settle what NMCR's second multi-cell group is, and
whether the twelfth pass's detached-part species (Charizard, Gengar) are a
frame-0 artifact fixable by using each sequence's loop-start frame instead.

### (1) Per-frame composition

`Nanr.frame_data()` now returns the full `(cellIdx, px, py, sx, sy, rotZ)`
record for all three element types (index/T report the implicit identity
transform, `sx=sy=4096, rotZ=0`, so callers never special-case them). A new
`Nanr.frame_index_at_time(seq_index, t)` sums frame durations exactly the
way `func_020643CC`'s 0x020644B8 loop does (see the twelfth pass's docstring
section), but evaluated at an arbitrary elapsed time `t` (NDS frames) rather
than only accumulating forward, and wraps from `loopStartFrameIdx` once a
sequence's own total duration is exceeded -- `Nanr._frame_times()` caches
each sequence's cumulative frame-start times for this.

`compose_pose_multi()` (new; `compose_pose()` is now a one-time-sample
wrapper around it) drives every node at a shared elapsed time `t`, resolving
each node's own frame independently through `frame_index_at_time` -- nodes
whose sequences are shorter than the driving one simply loop while the
longest one plays through once. A type-1 (SRT) frame's `(sx, sy, rotZ)` is
applied to each OAM's placement offset about the cell's own origin (`_apply_
srt`): scale first (`x*sx/4096, y*sy/4096`), then rotation by `rotZ *
2*pi/65536` radians (rotZ is 1/65536 of a full turn). **Only the placement
offset is transformed, not the OAM's own pixel content** -- this renderer
does not resample tiles under rotation/scale the way NDS hardware
rotate/scale OBJs do, so a rotated limb moves and pivots as a rigid,
unrotated rectangle rather than turning with its art. Every frame-0 SRT
record sampled across species 25/6/94 reads identity (rotZ 0, sx/sy 4096),
confirming the twelfth pass's "frame 0 needs no transform" was correct as
far as it went; non-zero frames elsewhere in these same sequences do carry
real rotation (values like 910, 4778, 9557, 11150 -- 5-60 degrees), so the
transform is load-bearing for anything past frame 0.

### (2) Animation strip and GIF export

`animation_frame_times(nanr, nodes, max_frames=32)` picks the "driving"
sequence -- whichever node's own sequence has the largest `total_duration`
among the group (not necessarily the one with the most frames: species 25's
group 0 has an 8-frame-longer sequence than its driving one, but the driving
one's last frame holds for 84 NDS frames, giving it the larger total) -- and
returns that sequence's own frame-start boundaries, capped at `max_frames`.
This is "all distinct frame times over one loop, or the first 32 frames"
per the mission: species 25 group 0's driving sequence has 18 frames over a
186-NDS-frame loop, all under the cap, so all 18 are used.

`write_gif()` is a from-scratch GIF89a writer: one global color table (the
NCLR palette, index 0 remapped to the same dark-gray "background" this
module's PNG path already uses via `indices_to_rgb`, so a GIF frame and a
PNG frame of the same pose read identically), a Netscape 2.0 loop extension,
and one image block per frame via `_gif_lzw_encode()` -- a plain from-
scratch LZW encoder (variable code width 3-12 bits, table reset on overflow,
Clear/End codes), no compiled/third-party GIF or LZW code from anywhere.
Verified by hand-walking the produced file's own block structure (extension
sizes, image descriptors, sub-block lengths) back to a frame count and by
cross-checking with Pillow (available in this dev environment only, never a
project dependency) that `Image.open(...).n_frames` and `.size` match.

`species 25`: 18 distinct frame times, `build/assets/rig/0025_anim.png`
(18-frame horizontal strip) and `build/assets/rig/0025.gif` (76x56, 18
frames) both confirmed correct -- the strip shows an unmistakable "raise
arm, spark appears, arm lowers" Thunder Shock-shaped attack cycle, not an
idle bob. `--anim-all` (default `--group 0`, `--max-frames 32`) rendered
**712 of 714 GIFs** (the same two trailing non-rig slots as every earlier
`--all` pass skip cleanly, now for the identical reason: no RGCN/RECN/RCMN
bundle at those indices).

### (3) Group 1: a second, independent animation on the same rig -- not a corrective rest assembly, and not the fix for detached parts

Comparing `Nmcr.groups[0]` and `groups[1]` directly (species 25, 6, 94):
group 1's `animSeqIdx` values are group 0's own **plus a constant offset**
(species 25: exactly +10, covering NANR sequences 10-19 against group 0's
0-9; species 6: +9 for 14 of 16 nodes, the remaining two swapped for a
different but still >= +9 sequence) while every node's own `(posX, posY)`
is either **identical** between the two groups (species 25, and 15 of 16
nodes for species 6) or close (species 94, where one limb's rest offset
differs and two decorative nodes present in group 0 are simply absent from
group 1). This is the signature of **two separately authored animation
clips sharing one rig topology** (e.g. an idle/attack pair), not a
corrective "real" assembly standing in for a broken group 0: if group 1 were
the intended static rest pose, its node positions would differ from group
0's in a way that fixes the composition, not repeat them near-verbatim while
only swapping which NANR sequences drive the frames.

Rendering group 1 at frame 0 for Charizard and Gengar (species 6, 94)
confirms this directly: both render as complete, recognizable creatures,
and both **still show the same detached foot/limb** the twelfth pass
flagged in group 0 -- group 1 does not fix it, because it is not a
different assembly of the same parts, it is the same assembly played by a
different animation.

**The loop-start hypothesis is also settled, and false**: every sequence
sampled across species 25, 6 and 94 (60+ sequences) reads
`loopStartFrameIdx = 0`. Frame 0 already *is* each sequence's own loop
start, so "render from the loop-start frame instead of frame 0" is not a
distinct rendering choice for this rig -- there is nothing to switch to.

**What actually explains the detached parts**, found by rendering species
6's full 32-sample animation loop and inspecting every frame rather than
just frame 0: the detachment is *not* uniquely a frame-0 phenomenon and
does not resolve later in the loop -- frames 0 and 16 of `0006.gif` both
show the same isolated foot, and the mid-loop frames (around elapsed time
60, `frame_index_at_time` giving real SRT records with rotZ up to ~60
degrees and non-trivial px/py) show the wings and tail swung far enough
from the body that the silhouette visibly separates into several floating
pieces -- a real, large per-frame rotation this renderer does not resample
pixels for (see (1) above), not a decode error. Charizard and Gengar's
detached-part appearance is therefore best explained as **this renderer's
documented rigid-placement limitation interacting with genuinely large
per-frame rotation/translation values that are part of the authored
animation** (a wing flap or roar-type extreme), not a frame-0 special case
and not fixable by picking a different static frame -- an actual fix would
need per-pixel rotation/scaling of each OAM's tile block, which this pass
did not implement (mission scope was the placement transform, and every
species-25/1/150 frame-0 check the twelfth pass relied on is unaffected
since those parts' frame-0 records are all identity).

### Functions/files touched

- `tools/assets/rig.py`: `Nanr.frame_data()` returns the full SRT tuple;
  new `Nanr._frame_times()`/`total_duration()`/`frame_index_at_time()`;
  new module-level `_driving_sequence()`, `animation_frame_times()`,
  `animation_delays_cs()`, `_apply_srt()`, `_frame_placements()`,
  `_raster()`, `compose_pose_multi()`, `render_animation_strip()`,
  `_gif_lzw_encode()`, `_gif_sub_blocks()`, `write_gif()`, `_gif_palette()`,
  `render_animation()`; `compose_pose()` reduced to a `compose_pose_multi()`
  wrapper (same output for `t=0` as before, confirmed byte-identical
  dimensions on species 1/150). CLI gained `--group` (which `Nmcr` group to
  pose/animate), `--anim` (strip + GIF for one species), `--anim-all` (GIF
  for every species), `--max-frames`; `--frame` is now the elapsed-time
  argument to a single `--pose` render instead of an unused placeholder.

### Remaining gaps

- **No per-pixel rotation/scaling**: OAM tile content is never resampled,
  only repositioned -- correct for identity frames (the large majority
  sampled) but a visible simplification for the minority of frames with
  large `rotZ`/non-uniform `sx`/`sy` (see (3)).
- **The NDS-frame-to-real-time conversion (`NDS_FPS = 59.8261`) is an
  assumed standard hardware refresh rate, not read from any in-project
  code** -- GIF delays are almost certainly in the right ballpark but not
  verified against the game's own timer.
- **`--anim-all` always uses group 0** (`--group` is available per-species
  but the batch export does not yet expose per-species group selection);
  group 1's animation is fully renderable via `--group 1 --anim` but was
  spot-checked only for species 6/25/94/1/150, not exported for all 712.
- The `nodeAttr` low-nibble and NMAR resource remain undecoded, unchanged
  from the twelfth pass.

## Trainer data table located by reference (`a/0/9/2`/`a/0/9/3`); class count confirmed at 105; no matching battle sprite archive found

Mission: stop guessing the trainer battle sprite by shape and instead
locate it by reference -- find the trainer data table, read its class-id
field's range, then look for a sprite archive whose entry count matches.
New tool: `tools/assets/trainer_data.py`.

### The trainer data table: `a/0/9/2` (trdata) / `a/0/9/3` (trpoke)

The mission's suggested starting point, `a/0/5/7` and `a/0/6/6` (the text
pass's fixed-stride, ruled-out-as-non-text candidates -- see "Text banks"
above), are not it: neither has a dominant fixed stride
(`--scan-candidates`: `a/0/5/7`'s most common size, 4 bytes, covers only
30% of its 899 sub-files; `a/0/6/6`'s most common size, 360 bytes, covers
only 7% of 601) -- scattered small binary tables, not a trainer record
array.

`a/0/9/2` is the real table: 616 sub-files, of which 615 are exactly
20 bytes (sub-file 0 alone is a 16-byte null sentinel) -- a 99.8%-uniform
fixed stride, the strongest fixed-record signal found anywhere in this
inventory. Its immediate neighbour `a/0/9/3` has the same 616 sub-file
count with variable-length records (6-108 bytes, all multiples of 8) --
the classic trdata/trpoke pairing (trainer metadata + per-trainer party
data indexed by the same id). Cross-checked directly: for each trdata
record, byte offset 3 (range 1-6, see below) times 8 bytes predicts the
paired trpoke sub-file's length correctly for 546/615 trainers (89%);
the remainder likely carry per-slot extras this pass didn't decode
(held item, custom moveset, or IV/ability override flags adding bytes
per party slot) -- not chased further, doesn't affect the identification.

### Class count: 105, from the trainer-class name text bank

`text.py`'s dumps (`build/assets/text/*.txt`) were searched for
"Youngster"; three banks hit (189 narrative dialogue, 191 the bare class
name list, 283 an "a "-prefixed duplicate of 191 for grammatical
context). Bank 191 has exactly **105 entries** (index 0-104): "Trainer",
"Trainer", "Youngster", "Lass", "School Kid" x2, "Smasher", ...,
"Team Plasma", "Subway Boss", .... This is the trainer-class count.

### The class-id field: trdata byte offset 1

Scanning every byte offset of the 615 fixed 20-byte trdata records for a
contiguous enum range inside `0..104` (`--records`):

| offset | min | max | distinct | contiguous |
|---|---:|---:|---:|---|
| 0 | 0 | 3 | 4 | yes |
| **1** | **2** | **102** | **101** | **yes** |
| 2 | 0 | 3 | 4 | yes |
| 3 | 1 | 6 | 6 | yes |
| 4, 6, 8, 10, 12, 17, 18 | 0/1 | 23-158 | 2-23 | no |

Offset 1 is the standout: 101 distinct values forming the exact
contiguous run `2..102`, comfortably inside the `0..104` range implied by
105 classes (with 615 trainer instances sampling 105 classes, several
classes -- 0, 1, 103, 104, plus any class with zero or one trainer
instance -- simply not appearing is expected, not a mismatch). Offset 3
(range 1-6) is party size, corroborated directly by the trpoke length
cross-check above; offset 0 and 2 (range 0-3) look like battle-format/
flag bytes. No other offset produces a comparably clean, densely-packed
contiguous range.

### Sprite-archive candidates by entry count: none hold up

`--sprite-candidates` scans the full inventory table for any archive
whose sub-file count is within 3% of 105, 210, 315, or 420 (1x-4x the
class count):

| match | archive | count | inventory guess | notes |
|---|---|---:|---|---|
| 1x | `a/0/4/5` | 102 | 3D model/texture data | sub-file 0 is `BTX0` -- a real NSBTX 3D texture container, not a sprite |
| 1x | `a/1/3/7` | 108 | trainer/item/UI sprites | sub-file 0 is `RCSN` (NSCR reversed) -- a tilemap/screen resource; render (`build/assets/trainer_class_sprite_candidates/a_1_3_7_sf0000_rcsnraw_lin8.png`) shows a banded/periodic pattern consistent with tilemap data, not a portrait |
| 3x | `a/1/6/8` | 315 | scripts/data tables | no known magic, uncompressed; sub-files are u16-array records (small incrementing/repeating values, e.g. `0002 0032 0001 0002 0003 0004 ...`), not pixel data -- confirmed by the bitmap-guess render (flat, near-black, no shape) |
| 3x | `a/2/1/5` | 315 | scripts/data tables | same u16-array shape as `a/1/6/8`, same negative render result |

(`a/0/0/6`, 733 sub-files, is a near-multiple of 105 at 7x = 735, but this
project already conclusively identified all 733 sub-files across two
prior passes as the `" APS12_1"`/`" TPS"` particle/sparkle/weather-overlay
wrapper format, re-checked at full 64x64 canvas with zero human figures --
the 7x proximity is coincidental, not re-opened here.)

Every candidate either carries a known, already-identified non-sprite
NITRO magic (`BTX0`, `RCSN`) or renders, under every bitmap-guess layout
this project's tooling supports, as flat structured numeric data with no
recognizable figure. **No archive with an entry count matching the
105-class trainer roster (bare or at 2x/3x/4x) contains battle-sprite-
shaped content.**

### Report

- **Trainer data archive**: `a/0/9/2` (trdata, 616 sub-files, 615 real +
  1 sixteen-byte sentinel, fixed 20-byte record) paired with `a/0/9/3`
  (trpoke, same 616 count, variable 8-byte-multiple records). Record
  layout (20 bytes): offset 0 battle-format/flag byte (0-3), **offset 1
  trainerClass** (0-104, observed 2-102), offset 2 another flag byte
  (0-3), offset 3 partySize (1-6), offsets 4-11 four u16 item slots,
  offsets 12-15 a u32 (likely AI flags), offsets 16-19 mostly-zero
  trailing bytes (one non-zero flag at offset 16).
- **Class count**: 105, from text bank `build/assets/text/191.txt`
  (cross-checked against its "a "-prefixed duplicate, bank 283).
- **Matching archives checked**: `a/0/4/5` (102), `a/1/3/7` (108),
  `a/1/6/8` (315), `a/2/1/5` (315) -- see table above.
- **Renders**: `build/assets/trainer_class_sprite_candidates/` (8 PNGs,
  linear 4bpp/8bpp bitmap-guess renders of one sub-file from each
  non-magic candidate, plus raw dumps of the two recognized-magic ones).
- **Verdict**: trainer data table and class count are now solidly
  established by reference, but no sprite archive pairs with them by
  entry count. This confirms, rather than overturns, the standing
  "trainer battle sprite itself remains not located" conclusion --
  now anchored to a verified class count (105) instead of the rough
  ~200-700 range earlier passes worked from. If a trainer battle sprite
  archive exists, it is not indexed 1:1 (or at a small integer multiple)
  by trainer class the way the Pokemon battle sprite archives
  (`a/0/0/4`/`a/0/5/2`) are indexed by species -- the next lane should
  either check indexing by trdata's own record id (615/616, already
  ruled out above: `a/0/2/4` at 627 and `a/0/6/6` at 601 are the closest
  entry-count matches to 615/616 and neither carries image content) or
  reconsider whether Black/White trainer "sprites" are a shared/reused
  rig keyed by something coarser than class (e.g. body type or a small
  handful of archetypes) rather than per-class art.

## Asset lane pass: `a/1/3/4` hypothesis test -- NOT trainer battle art, confirmed as opening-cinematic frame sequence (`--raw16`/`--contact-sheets` added to `tools/assets/battle_sprite.py`)

Mission: test the standing hypothesis that `a/1/3/4` (670 sub-files, each a
256x256 16bpp direct-color image -- pixel format nailed down by the sixth
pass, "reinterpreted" above) is the trainer battle art after all, on the
theory that Gen 5 trainers animate on entry and 670 frames could be several
per class across 105 classes (see the previous section for the 105-class,
trdata-anchored count).

**Verdict: rejected.** `a/1/3/4` is a rendered cinematic (almost certainly
the game's intro movie / Team Plasma castle sequence featuring N), stored
as a linear sequence of full-frame images, not a per-trainer-class sprite
table.

### Method and evidence

`battle_sprite.py` gained two additions (kept, since they are generally
useful and the mission's write set includes this tool):

- `unpack_16bpp_direct()` / `decode_one_raw16()` / `--raw16`: a proper
  256x256 16bpp A1BGR555 linear decode path, replacing the ad hoc
  not-committed script the sixth pass used for its 4 samples. This is the
  format `a/1/3/4` actually uses (see "reinterpreted" above); the older
  `unpack_4bpp_tiles()` path is left in place only because it may still be
  correct for some other LZ11-no-magic archive, not this one.
- `build_contact_sheets()` / `--contact-sheets` (`--stride`, `--thumb-px`,
  `--per-sheet`): renders every sub-file (or every Nth) as a small
  thumbnail tiled into 5x5 (default) contact sheets, so a whole archive can
  be eyeballed a page at a time instead of one image per call. All 670
  entries were rendered this way, at 96px thumbnails, 25 per sheet, 27
  sheets total, to `build/assets/trainer_sheet/sheet_NN.png`.

Reading all 27 sheets top to bottom shows a single continuous narrative,
not 105 independent character portraits:

- **Indices ~0-90**: a dusk exterior building scene behind a fence-like
  foreground silhouette (this is the sixth pass's species-25 sample,
  index 25, sitting mid-shot -- consistent, not a coincidence), slow
  camera drift, then a cut to two crossed glowing blades/lights.
- **Indices ~150-250**: a green-haired, red-eye-marked face (this is the
  sixth pass's species-150 sample, index 150) filling most of the frame
  with a crown-shaped hair silhouette and a golden backlight -- this is
  **N** (Pokemon Black/White's central character; green hair styled into
  a crown-like leaf crest and a diamond-shaped red facial marking is his
  unique, unmistakable design). This shot alone runs close to 100 frames
  of near-static held pose with only lighting drifting.
- **Indices ~330-395**: a hallway of tall blue-lit thrones under an arched
  ceiling, then a backlit crowd filing into the same hall -- this reads as
  Team Plasma's castle throne room.
- **Indices ~370-460**: a forest scene with an owl/fox-like creature (fur
  ruff, large yellow eyes) filling the frame -- a Pokemon close-up shot,
  not a trainer.
- **Indices ~498-530**: two women in close, informal portrait (blonde/
  brown hair, warm indoor lighting) -- plausibly a mother-and-daughter or
  two-friends beat; not confidently matched to any named NPC.
- **Indices ~550-585**: a hand cupping a small glowing object, cutting to
  a green-hair/pink-marking close-up (N again, different framing).
- **Indices ~600-655**: a robed, white-haired elder figure with both arms
  raised under a golden halo/glow inside the same cathedral-like hall,
  then a fade to the empty hall interior with the crowd silhouettes --
  reads as a ceremony/coronation beat (Ghetsis-shaped: robed elder
  presiding in Team Plasma's castle), ending the sequence in near-total
  black.

A coarse per-frame signature scan (sum of a 400-word pixel sample per
sub-file, flagged as a new "shot" wherever the signature jumps >2%)
independently found **77 runs** with lengths ranging from single-frame
spikes (crossfades/flashes between shots) up to 80 contiguous frames of
one held shot (indices 374-453). This shot-length profile -- long,
unevenly-sized runs punctuated by single-frame transitions -- is the
signature of an edited movie broken into frames, not a lookup table: **no
run boundary lines up with anything resembling 105 discrete class slots**,
and run lengths (1, 2, 5, 6, 10, 14, 25, 27, 29, 31, 33, 38, 40, 55, 63,
80, ...) show no common factor or stride consistent with "N frames per
class." This is the direct falsification of the mission's animation-table
hypothesis: a per-class {start, count} table summing to 670 was not found
because there isn't one to find -- the frame boundaries are cinematic cuts,
not class boundaries.

No small {start_frame, count} x105 table was searched for in ARM9 data
beyond this negative structural result (the shot-length evidence already
rules out the premise a table like that would encode); this is flagged as
moot rather than as a remaining gap.

### Character identification

- **N**: confidently identified (green hair in a crown-like crest, red
  diamond eye marking) at indices ~150-250 and again ~570-585. Matches
  the mission's own sample-150 description exactly.
- No other named Black/White character (Cheren's glasses, Bianca's beret,
  Professor Juniper, any Gym Leader, or Alder) was recognized in any of
  the 27 sheets. The two-women shot (~498-530) and the robed-elder shot
  (~600-655, plausibly Ghetsis by role/staging, not by any confirmed
  visual signature) are the only other human figures in the whole archive,
  and neither carries a distinguishing feature this pass could match with
  confidence.

### What this means for the archive's identity and prior documentation

- The inventory table's per-archive one-line guesses (`docs/ASSETS.md`'s
  big table, e.g. the `a/1/3/4` row's stale "text banks (guess)") are
  mechanically generated by `inventory.py`'s heuristics and are left
  alone; the narrative "Where things probably live" list's `a/1/3/4` entry
  and the "reinterpreted" section above already correctly flagged this as
  an open question ("trainer portraits? battle backgrounds? cutscene
  art?") -- this pass resolves that question in favor of **cutscene art
  (specifically: the intro movie)**, not a portrait/background asset and
  not trainer battle art. No prior section asserted the trainer-sprite
  reading as settled fact, so there is no incorrect claim to retract, only
  an open question to close.
- `tools/assets/battle_sprite.py`'s docstring/name (`battle_sprite.py`,
  "decoder for the battle sprite archive `a/1/3/4`") is now known to be a
  misnomer for what the archive actually holds; renaming the file was not
  done this pass (out of the write set's "no code from other projects"
  and general lean-session discipline -- a rename is a larger, purely
  cosmetic change better bundled with whatever future pass gives this
  archive a real name, e.g. `intro_movie.py`, once the movie is confirmed
  against the actual Black/White opening rather than inferred from framing
  alone).
- No `--trainers` per-class animation-strip mode was added to
  `battle_sprite.py`, since the mission's own condition for adding it ("if
  confirmed") does not hold -- adding it would encode a false premise.

### Remaining gaps

- The exact identity of the movie (opening title sequence vs. a specific
  in-story cutscene, e.g. the Team Plasma castle ending) is inferred from
  staging/character recognition, not verified against any script/event
  table that names this archive.
- The trainer battle sprite archive itself is still not located; this
  pass only closes off `a/1/3/4` as a candidate. The standing conclusion
  from the previous pass (no archive with an entry count matching the
  105-class roster, at 1x-4x, holds sprite content) is unchanged.
- Only 670/670 sub-files were thumbnailed, but only ~15% of thumbnails
  (spread across a handful of sheets) were individually eyeballed in
  detail in this writeup; the full run-length scan above covers all 670
  programmatically, but a human has not looked at every single frame.

## Asset lane pass: MDL0 shape dictionary CRACKED -- real per-shape display-list ranges, materials linked per shape, four textured OBJ exports (`tools/assets/nsbmd.py`, new `tools/assets/map_shapes.py`)

Mission: finish what the previous MDL0 pass left open (`docs/ASSETS.md`'s
"MDL0 material/shape dictionaries" section) -- divide a model's single
merged GX command stream into real per-shape face groups using the shape
dict's own per-entry records, instead of tagging one whole merged mesh
with a single representative material.

### Shape descriptor record layout: CRACKED, and it uses TWO different bases

The shape ResDict's `entries()` records (4 bytes each, via the already-
cracked generic `ResDict.entries()`) are **not** display-list offsets
themselves -- each is a `u32` byte offset that must be added to the shape
dict's own **start** offset to land on a fixed 16-byte descriptor:

```
u16 itemTag   always 0 in every sample
u16 size      always 0x10 (16) -- self-describing record length
u32 flag      seen only 5 or 7 across every sample; meaning not decoded
              (not needed for geometry/UV export)
u32 dlOffset  this shape's GX command range, relative to a DIFFERENT
              base: (shape_dict_offset + shape_dict.size)
u32 dlSize    byte length of that range
```

Confirmed against `pl_00_00` (40 shapes): the 40 descriptors occupy the
first `40*16` bytes at that second base, and shape 0's `dlOffset` (0x280)
lands exactly at the descriptor array's own end -- i.e. the descriptor
table and the merged GX data are back-to-back in one "shape data" section
starting right after the shape dict's own on-disk bytes. `sum(dlSize)`
over all 40 shapes equals the merged stream's total byte length exactly
(0xE9EC), matching the pre-existing whole-model `find_gx_stream()` end
offset exactly -- far too precise to be coincidental.

New `nsbmd.find_shape_dict(buf)` identifies the shape dict **structurally**
(not by the `polygon0..` name convention, which is model-specific): it
tries every `find_resdicts()` hit as a candidate shape dict and accepts
the one whose entries, decoded via the rule above, all land on plausible
descriptors (`itemTag==0`, `size==0x10`, in-bounds `dlOffset+dlSize`).
New `nsbmd.shape_descriptors(buf, shape_off, shape_rd)` decodes every
descriptor. Both are generic, reused for building/dungeon/outdoor models
alike (see exports below), not `pl_00_00`-specific.

### The dlOffset/dlSize boundary doesn't line up byte-exactly with real BEGIN_VTXS/END_VTXS pairs -- worked around, not silently ignored

Decoding each shape's declared `[dlOffset, dlOffset+dlSize)` range in
isolation surfaced two distinct problems, investigated by hand-tracing
the actual GX opcodes at shape boundaries (not guessed):

1. **A small (0-20 byte) non-GX preamble** precedes the real command
   stream inside every shape's declared range (its exact structure wasn't
   identified this pass). Worked around by reusing the existing
   `find_gx_stream()` heuristic locally, inside each shape's own bounded
   range, to skip it.
2. **The declared range sometimes ends a few bytes before the shape's own
   last END_VTXS actually fires** -- for building-interior models
   (`pl_00_00`) this is a handful of trailing bytes per shape; for
   outdoor terrain chunks (`map14_13`) a whole shape can be ONE single
   BEGIN_VTXS/END_VTXS pair whose END_VTXS lands just past the declared
   boundary, so bounding strictly at `dlSize` was losing **100% of that
   shape's faces** even though its vertices decoded fine (traced by hand:
   `map14_13` shape 1 had exactly one BEGIN_VTXS and one END_VTXS in its
   816-byte range, but the END_VTXS came *first*, at byte 0 -- belonging
   to the *previous* shape -- and the real END_VTXS for this shape's own
   BEGIN_VTXS was never reached before the range ended).

Fix: `gx_decode()` gained optional `soft_limit`/`hard_limit` parameters
(both default `None`, zero behaviour change for the pre-existing merged-
model callers). `soft_limit` means "stop here once no batch is currently
open" -- i.e. finish the strip/fan you're already in, then stop, instead
of dropping it. `hard_limit` is an absolute safety cap (`dlSize +
tail_slack`, default `tail_slack=384`, tuned below) so a batch that never
closes can't run away into unrelated shapes. `nsbmd.decode_shape_dl()`
wires this up: locate the real start via a locally-bounded
`find_gx_stream`, then decode from `buf` directly (not a hard-sliced
copy) with `soft_limit = declared range end` and `hard_limit = soft_limit
+ tail_slack`.

`tail_slack` was tuned empirically against the three previously-exported
merged-mesh face counts (the best independent ground truth available --
each is the SAME model's SAME geometry, decoded as one unbroken run, so
the per-shape sum should land close to it):

| tail_slack | pl_00_00 (ref 1774) | map14_13 (ref 301) | m_dun0101_00_00 (ref 595) |
|---:|---:|---:|---:|
| 128 | 1432 (-342) | 255 (-46) | 398 (-197) |
| 256 | 1600 (-174) | 301 (0) | 532 (-63) |
| **384** | **1782 (+8)** | **301 (0)** | **546 (-49)** |
| 512 | 1816 (+42) | 301 (0) | 626 (+31) |
| 2048 | 1824 (+50) | 301 (0) | 626 (+31) |

384 minimises total absolute deviation across all three (57, vs. 73 for
512 and 237 for 256) and is the new default. This is an honestly-tuned
compromise, not a claim of byte-exact per-shape boundaries: a handful of
shapes still lose their last face batch (deficit) or pick up one extra
neighbouring batch across the boundary (small surplus, visually harmless
duplicate geometry vs. the 25%+ deficit the naive dlSize-only bound
produced). Documented as a real, bounded imperfection, not chased
further this pass.

### Material dict identification generalised (the previous pass's naming rule was model-specific, not universal)

The previous pass's "material dict = every name ends in `_<digits>`" rule
(true for `pl_00_00`, where reused materials always carry a numeric
suffix) turned out **not** to generalise: `map24_23`'s material dict uses
the BARE real texture name directly for a first use (`gake01a`,
`grass01ax`, ...) and only appends `_<n>` for a genuine repeat-use variant
(`sea_mizu1_1` alongside plain `sea_mizu1`) -- so the old `all(name
matches _\d+$)` test rejected EVERY candidate dict for this model (0
shapes matched to a material).

New `map_shapes.find_material_dict()` instead scores every non-shape,
non-palette (`_pl`-suffixed) candidate dict by how many of its names --
tried both as-is and with any trailing `_<digits>` stripped -- are REAL
texture names known to the actual `a/0/1/4` texture archive index (cross-
checked against real data, not guessed), and additionally requires the
dict be large enough to cover the highest material index the render-
command bytecode (`nsbmd.find_render_commands`) actually references. This
is generic and worked unmodified for all four export targets below (40,
26, 13, and 31 shapes, 100% matched to a material in every case).

### UV normalisation rule (confirmed, not assumed)

`gx_decode`'s `TEXCOORD` values are already texel units (s16.4 fixed-
point, divided down inside `gx_decode`) -- direct inspection confirms raw
decoded UVs run into the tens/hundreds for real shapes, never a natural
0..1 range on their own. Each shape's UVs are normalised by dividing by
**that shape's own real texture's** decoded pixel width/height (recovered
via the material link above, not one texture borrowed for the whole
mesh, unlike the previous pass's single-material `pl_00_00` demo). Values
above 1.0 after normalising are left as-is (e.g. `vt 2.000000 ...` for a
tiled window shape) -- a real UV-repeat/tiling case, not a bug, and OBJ/
most viewers handle `>1` UVs as wraparound natively. No separate DS
material texture-coordinate-transform SCALE field was found to need
handling beyond this divide: the MDL0 material dict's own per-entry
record payload (as opposed to its names) was not decoded this pass, so
any additional scale/offset/rotation a material's texture matrix might
apply is a documented, open gap, not silently ignored.

### Four textured OBJ exports, `build/assets/maps/` (gitignored, regenerate, don't commit)

New `tools/assets/map_shapes.py` (`python tools/assets/map_shapes.py
[--targets NAME...]`) ties the above together: strips each `a/0/0/8`
sub-file's wrapper (`payload = raw[raw.find(b"BMD0"):]`, unchanged from
the earlier map-model pass), decodes every shape's own geometry, links it
to a real texture name via the material dict + render-command bytecode,
looks up and decodes that texture from `a/0/1/4` (indexed once, decoded
lazily per sub-file actually needed), and writes one `g`/`usemtl`-grouped
OBJ + `.mtl` + PNGs per model.

| model | a/0/0/8 index | shapes | matched to a material | distinct textures | faces |
|---|---:|---:|---:|---:|---:|
| `pl_00_00` (player's house interior) | 120 | 40 | 40 | 38 (38 decoded) | 1782 |
| `map24_23` (outdoor terrain chunk) | 0 | 26 | 26 | 23 (20 decoded, 3 not in a/0/1/4) | 572 |
| `map14_13` (outdoor terrain chunk) | 44 | 13 | 13 | 12 (11 decoded, 1 not in a/0/1/4) | 301 |
| `m_dun0101_00_00` (dungeon room) | 279 | 31 | 31 | 28 (27 decoded, 1 not in a/0/1/4) | 546 |

Sanity checks performed, not just claimed: every shape in every model
matched to a material (100%, all four); face counts cross-checked against
the previous pass's independent merged-mesh decode for the three models
that have one (table above); a handful of shapes per model (1-4) decode
vertices but zero faces (a batch whose END_VTXS never resolved even with
the `tail_slack` safety margin -- likely a degenerate/point-only shape,
or one where the boundary quirk above is worse than average; not chased
further). PNGs spot-checked for valid PNG signature/IHDR; `pl_00_00`'s
`shape0`/`pk_l_mado` (window) group carries `vt 2.000000 ...` UVs,
consistent with a genuinely tiled window texture rather than a bug.

### Remaining gaps

- **A few texture names used by outdoor/dungeon materials aren't found in
  `a/0/1/4`** (3 for `map24_23`, 1 each for `map14_13`/`m_dun0101_00_00`):
  those shapes fall back to an `_unassigned` grey material in the MTL
  rather than a fabricated texture. Likely cause spotted in passing but
  not chased: at least one case is a punctuation mismatch (`hana01_1` in
  the material dict vs. `hana01.1` in the real texture dict), suggesting
  the material->texture name link isn't always a pure suffix-strip.
- **The non-GX preamble's own byte structure** (0-20 bytes, precedes every
  shape's real command stream) was not decoded, only skipped via the
  existing whole-model heuristic re-applied locally.
- **The descriptor `flag` field** (seen only 5 or 7) and the **MDL0
  material dict's own per-entry payload** (as opposed to its names) are
  still not decoded -- the texture link only ever needed dict *names*.
  Any real per-material UV transform beyond the texture-size divide above
  would live in that undecoded payload.
- **`tail_slack=384` is an empirically-tuned compromise, not a byte-exact
  fix** -- expect small per-shape face-count drift (a handful of shapes
  short their last batch, a couple pick up one extra neighbouring batch)
  on models not in the three-way cross-check table above.

## Asset lane pass: per-pixel SRT for the `a/0/0/4` rig -- matches the DS OAM affine algorithm, fixes rigid-rectangle rotation, does NOT fix the Charizard/Gengar detachment (that gap predates any transform)

Mission: implement the per-pixel resampling the thirteenth pass's "Remaining
gaps" flagged as missing -- DS OAM affine sprites render by inverse-mapping
each *output* pixel through the 2x2 SRT matrix about the sprite centre and
nearest-neighbour-sampling the source, not by moving a rigid rectangle -- and
check whether that was the cause of Charizard's (species 6) and Gengar's
(species 94) detached parts.

### Implementation

`_cell_local_raster(ncgr, cell)` composes one cell's OAMs onto a local
canvas at identity placement (factored out of `render_cells_contact_sheet`,
which now calls it too instead of duplicating the same loop), returning the
canvas plus where the cell's own origin sits inside it. `_cell_frame_raster
(ncgr, cell, sx, sy, rot_z)` is the new per-pixel step: it takes that
identity canvas, forward-transforms its bbox corners (`_apply_srt`, now
float-precision and forward-only) to size the output canvas, then for every
output pixel calls the new `_inverse_srt` -- un-rotate then un-scale, the
exact inverse of `_apply_srt`'s scale-then-rotate -- to find the source
coordinate and nearest-neighbour-samples the identity canvas there.
`_frame_placements` now branches on identity: an identity frame still moves
each OAM as its own rigid offset (unchanged, exact, cheap); a non-identity
frame resamples the whole cell as one block through `_cell_frame_raster`
and blits that single raster at the node+frame translation, instead of
moving each OAM's placement offset as a rigid rectangle the way the
thirteenth pass did.

Verified directly on species 6's cell 14 (a claw/horn, node 12's sequence,
frame rot_z=12742 -- about 70 degrees, one of the largest rotations sampled
in the twelfth/thirteenth passes' species-6 survey): the identity raster is
a shape lying near-horizontal, and the SRT-resampled raster is the
**same shape rotated to near-vertical**, pixel content included -- direct
visual proof this now rotates the art itself rather than translating an
axis-aligned box. `--anim-all` re-ran clean at the same 712/714 species
count as the thirteenth pass (2m for 712 species; no crashes, no timeout),
so the added per-pixel cost is acceptable at this archive's sprite sizes.

### The Charizard/Gengar detachment does NOT come from missing per-pixel SRT

Checked directly rather than assumed: `nmcr.groups[0].nodes` for species 6
and 94 was dumped alongside each node's `frame_data` across every sampled
elapsed time, specifically for the nodes whose rendered bbox lands where
the detached parts appear on screen (species 6: two nodes far apart in x
at the bottom of the canvas; species 94: two nodes at positive x, upper
right).

**Every one of those nodes reads `(sx, sy, rot_z) = (4096, 4096, 0)` --
pure identity -- at every sampled elapsed time, including `t = 0`.** Their
own `frame_data` first-word `px, py` is also `(0, 0)` throughout. The static
rest-pose render (`--pose`, `t = 0`, all transforms identity by
construction) shows the same isolated foot for Charizard and the same
floating arm/leg for Gengar as the animated GIFs do. A transform that is
never anything but identity cannot be the cause of a separation that is
already present when identity is the only thing in play: **per-pixel
resampling has nothing to correct here, because there is nothing non-
identity to resample.** This refines rather than contradicts the
thirteenth pass's finding that the detachment isn't a frame-0-only
artifact -- it adds the missing other half, that it also isn't an SRT
artifact at all for these specific nodes.

What is left, then, is the flat per-node placement itself: `node.(x, y)`
(the NMCR rest offset) plus the frame's own `(px, py)` (always zero for
these nodes) is simply large enough, for these two species' foot/arm/leg
nodes, to land outside the silhouette the other nodes draw. Whether that
reflects the real hardware rest pose (Gen 5 battle sprites are shown
mid-animation, never at a literal "frame 0"; an idle-breathing rig's true
rest silhouette need not be a tidy closed shape) or a still-undiscovered
per-node offset this reader is not applying (no parent/child node
hierarchy is modelled -- flagged as a structural simplification since the
twelfth pass, never actually tested against a hierarchy hypothesis) is not
settled this pass; distinguishing them needs either the game's own
renderer traced against real hardware/emulator output, or a source
function that walks NMCR nodes with anything beyond the flat sum
`func_020643CC`/`func_0206419C` already gave the eleventh/twelfth passes.
Not chased further this pass -- scope was the SRT resampling, which is now
verified correct and doesn't touch this.

### NDS frame-rate assumption re-checked, still unconfirmed in-project

Searched `src/matched` and `src/pending` for `VBlank`, `vsync`/`VSync`,
`OS_Tick`, `HBlankIntr`, `GX_VBlankIntr`, `frameRate`/`FRAME_RATE`: no
matches anywhere in either tree. No matched or pending function in this
project currently references a vsync-driven tick or frame-rate constant,
so `NDS_FPS = 59.8261` (the standard NDS hardware refresh rate) remains
what the thirteenth pass already flagged it as: an assumed value, not one
read from this project's own decompiled code. GIF delays stay in the
right ballpark on that assumption but are not byte-verified against a
timer.

### Re-exports

`0025.gif` (18 frames, now 79x57 -- was 76x56 under the old rigid-per-OAM
sizing; the true SRT-resampled bbox for a couple of this sequence's small
rotations is a few pixels larger), `0006.gif` (32 frames, 122x101),
`0094.gif` (7 frames, 76x73) and the `0025_anim.png` strip were all
re-rendered under the new per-pixel path and spot-checked at 6-8x
nearest-neighbour: Pikachu's Thunder-Shock-shaped pose is unchanged and
still unmistakable, Charizard and Gengar are still unmistakable creatures
with the same (now-explained, not fixed) detached parts. `--anim-all`
re-ran for all species: **712 GIFs rendered, 2 skipped** (species 712/713,
the same two non-rig slots every earlier `--all`/`--anim-all` pass has
skipped).

### Functions touched

`tools/assets/rig.py`: `_apply_srt` now returns unrounded floats and is
forward-direction-only (bbox sizing); new `_inverse_srt`, `_cell_local_
raster` (factored out of `render_cells_contact_sheet`, which now calls it),
`_cell_frame_raster`; `_frame_placements` branches identity (unchanged
per-OAM path) vs. non-identity (new per-cell resampled path).

### Remaining gaps

- **The Charizard/Gengar detachment is unresolved** -- confirmed this pass
  to be a flat-placement matter (identity transform throughout), not an
  SRT/resampling one; needs either hardware/emulator ground truth or a
  parent/child node hierarchy hypothesis this project has not yet tested.
- **`NDS_FPS` is still an assumed constant**, now re-searched and still
  absent from every matched/pending function in the project.
- Per-species group selection for `--anim-all` (group 0 only) and the
  `nodeAttr` low-nibble/NMAR resource remain exactly as the twelfth/
  thirteenth passes left them.

## Asset lane pass: SBNK region tables fixed -- the drum-kit/key-split record was 2 bytes too long and its wave_id/wave_arc fields were swapped, now 100% plausible in every real bank

Mission: the softsynth was dropping notes; fix `sbnk.py`'s region tables
(types 16/17) against the public SBNK layout and re-render the gym and
vs-Norapoke themes to measure the effect.

### The bug

The previous `sbnk.py` decoded every type-1/16/17 instrument region as a
**12-byte** record (`wave_arc`, `wave_id`, `base_note`, 4 ADSR bytes,
`pan`, 2 bytes of padding), with `wave_arc` read *before* `wave_id`. The
public SBNK spec (verified against real bytes this pass, not assumed)
says the record is **10 bytes**, with `wave_id` first: `u16 wave_id`,
`u16 wave_arc`, `u8 note`, `u8 attack`, `u8 decay`, `u8 sustain`,
`u8 release`, `u8 pan` -- no trailing padding.

Both errors were confirmed the same way: across all 1547 real type-1
instrument records, the *second* `u16` field is always 0-3 (a valid slot
into the owning BANK's own 4-entry `wave_arc[]` table) and the *first* is
often larger (up to 255) -- i.e. `wave_id` (which indexes into a whole
wave archive, so a wider range is expected) comes first, `wave_arc`
(which only ever selects 1 of 4 in-bank slots) comes second. This never
broke type-1 instruments' single record on its own (both fields still
land inside the 10 real bytes, just mislabelled and coincidentally close
enough to sound plausible for many real regions), but it corrupted
everything downstream of it for type 16 (drum kit) and 17 (key split):
their region arrays are packed back-to-back with **no gap**, so reading
each region as 12 bytes instead of 10 walks 2 bytes further per region
than the file actually has, and every region past the first ends up
reading the tail of the previous region plus the head of the next one.
This is exactly why the previous pass measured 86.6% plausibility for
first regions (no accumulated drift yet) collapsing to 4.1% for every
region after it (drift compounds every 10-byte step).

The instrument-table entry itself (the 4-byte `record_type`/`record_
offset`/pad header for the whole instrument, not the region records
inside it) was already correct in effect: it was read as `record_type
(low byte) | record_offset << 8` (a 24-bit offset), and the public spec
says `u8 type, u16 offset, u8 pad` (a 16-bit offset plus a separate pad
byte) -- these differ only if the pad byte is ever nonzero, and it is
measured 0 in all 30046 real instrument-table entries across all 1497
real SBNKs, so this was not the source of the dropped notes. It is now
decoded per the verified 3-field spec anyway (`sbnk.py`'s `Instrument`
gained a `pad` field), for correctness rather than because it changed any
behavior.

### The fix and its verification

`sbnk.py`'s `_parse_record()` now reads the correct 10-byte shape in the
correct field order for types 1-5 and reuses it for every type-16/17
region (`_parse_drum_kit()`, `_parse_key_split()`, both new). Type 16 is
`u8 low_note, u8 high_note`, then `(high_note - low_note + 1)` regions of
`u16 region_type` + the 10-byte record (12 bytes/region, matching the
public spec exactly once the type-prefix is accounted for). Type 17 is
`u8 split_points[8]` -- a **fixed 8-byte array**, confirmed NOT
terminated at `0x7F` (real data has trailing zero bytes after the last
real split point, e.g. `(67, 127, 0, 0, 0, 0, 0, 0)` for a 2-region
instrument) -- then one `u16 region_type` + 10-byte-record entry per
*nonzero* split-point byte.

A new `region_plausible()` helper (note/ADSR bytes in 0-127, `wave_arc`
a valid 0-3 in-bank slot, `wave_id` within that slot's resolved archive's
own wave count) was run against every region of every real bank:

| region set | plausible / total | plausible % |
|---|---:|---:|
| type 1 (single region) | 1547/1547 | 100.0% |
| type 16, region 0 (drum kit) | 187/187 | 100.0% |
| type 16, regions 1+ | 5121/5121 | 100.0% |
| type 17, region 0 (key split) | 1279/1279 | 100.0% |
| type 17, regions 1+ | 2113/2113 | 100.0% |

Every category is now uniformly 100% plausible -- the mission's "same
plausibility across all regions" bar, met exactly, up from the previous
86.6%/4.1% split. (Types 2/3, read with the same 10-byte shape per the
mission's public-spec note that types 1-5 share it, are not reliably
wave-shaped by this same check -- 51/122 and 124/155 plausible -- so they
remain undecoded and still silently dropped by the synth, unchanged from
before this pass.) `low_note`/`high_note` headers were also checked
directly: all 187 real type-16 instruments have `0 <= low_note <=
high_note <= 127`.

**Round trip: still 1497/1497 real banks (100%) byte-identical.** The fix
only changes what `parse_detail()` reports about the bytes *after* the
instrument table (region field meaning/size), not the table itself, so
`roundtrip_bytes()`'s reconstruction (unaffected by any of this) was
re-verified across all 1497 real SBNKs after the change, same result as
before it.

`sseqsynth.py`'s `resolve_instrument_region()` was updated to match: type
16 now picks its region directly by `played_note - low_note` (clamped),
the standard per-note drum-kit convention, instead of reusing type 17's
split-point search; type 17 keeps its ascending-split-point search but
against the corrected `split_points`/`regions` data. The previous
version's "fall back to region 0 if the split-matched region looks
implausible" safety net was removed -- there is nothing left for it to
catch.

### Before / after: `seq_bgm_gym.wav` and `seq_bgm_vs_norapoke.wav`

Both re-rendered with `sseqsynth.py` unchanged in its own CLI/mixing
logic -- only the SBNK region decode underneath it changed.

| file | notes rendered before | notes rendered after | peak before | peak after | audible fraction before | audible fraction after |
|---|---:|---:|---:|---:|---:|---:|
| `seq_bgm_gym.wav` | 75/296 | 75/296 | 9139/32768 | 21546/32768 | 0.9% | 74.4% |
| `seq_bgm_vs_norapoke.wav` | 129/766 | 149/766 | 17515/32768 | 32000/32768 | 6.9% | 76.5% |

**The gym theme's rendered-note count did not change (75/296 both
times), and that is expected, not a leftover bug:** every one of its 221
non-rendered notes was checked directly -- 35 use a `record_type == 0`
(empty) instrument slot (never playable, unrelated to this fix) and the
other 186 all have a `start_time` past the render's fixed 30-second
window (`MAX_SECONDS_DEFAULT`, a separate, deliberate cap, not a wave-
resolution failure). Zero of the gym theme's in-window notes ever failed
wave resolution, before or after this fix. What changed is *audio
correctness*: before the fix, its type-17 (key-split) regions were being
read at the wrong offsets/field order, so the notes that did render
still played -- from wave references that happened to stay in-bounds by
chance -- but pulled the wrong, often much quieter samples (peak
9139/32768, only 0.9% of samples above the noise floor). After the fix,
those same 75 notes resolve to their real, correctly-decoded regions:
peak jumps to 21546/32768 and 74.4% of samples are now above the noise
floor -- the same notes, now audibly correct instead of near-silent.

**The vs-Norapoke theme's rendered-note count did change (129 -> 149,
+20; dropped 467 -> 447, -20)**, traced directly: before the fix, 20 of
its notes resolved to a region whose `wave_arc`/`wave_id` pointed outside
any real wave (an out-of-range index from the old 12-byte/swapped-field
misread), so `resolve_wave()` returned `None` and the note was dropped
outright. After the fix, all 149 of its in-window, non-empty-instrument
notes resolve to a real wave -- zero wave-resolution failures, the
remaining 447 drops all being start_time-past-window (`no_region`/
`window_drop` counted directly, not inferred).

### Files touched

`tools/assets/sbnk.py` (region decode rewritten: `_parse_record()`,
`_parse_dynamic_regions()`, `_parse_drum_kit()`, `_parse_key_split()`,
`region_plausible()`; `Instrument` gained a `pad` field), `tools/assets/
sseqsynth.py` (`resolve_instrument_region()` updated for the corrected
type-16/17 shape; module docstring's stale 86.6%/4.1% figures and
first-region-fallback description corrected). `build/assets/audio/
seq_bgm_gym.wav` and `seq_bgm_vs_norapoke.wav` re-rendered (gitignored,
regenerate, don't commit).

### Remaining gaps

- SBNK types 2/3 are still undecoded in meaning and still silently
  dropped by the synth (51/122 and 124/155 plausible by the same check
  that gates 1/16/17 -- not reliably the same wave-bearing shape).
- The gym theme's 186 past-window notes and the 30-second render cap are
  an `sseqsynth.py` rendering-length choice, not an SBNK gap; raising
  `MAX_SECONDS_DEFAULT` (or rendering per-loop instead of by wall-clock
  seconds) is a separate, future change, out of this pass's scope (which
  was the SBNK byte layout).
- `0xA0`-`0xA2`'s real argument shapes, ADSR curve shape/direction, and
  the other `sseqsynth.py` approximations listed in its own module
  docstring are unchanged by this pass.

## Trainer battle sprite CONFIRMED: `a/0/7/2` is the trainer battle rig (95 blocks of 8), `rig.py` generalized to detect members by magic, class-to-block mapping is near-identity with a small number of merges

Mission: test the standing hypothesis that `a/0/7/2` (760 sub-files = 95
blocks of 8, each block's two LZ11 entries decompressing to 3248/16448
bytes -- the Pokemon rig's own two NCGR tile-sheet sizes) is the trainer
battle sprite archive that every previous pass failed to find by shape or
by entry count, generalize `rig.py` to pose it, and (if confirmed) render
the full set, check the two ~12-entry siblings, and work out the
class-to-sprite-block mapping.

### Verdict: CONFIRMED, by direct visual identification of named characters

`a/0/7/2` block 0's pose (`build/assets/trainers_rig/0000.png`, 84x84) is
unmistakably **the Black/White male protagonist's front battle sprite**
(red-and-black cap, blue jacket, shoulder bag) -- checked by eye at 4x
nearest-neighbour, not inferred. Block 1 is unmistakably the **female
protagonist** (pink cap, brown ponytail, denim shorts). Block 2 is a
**Youngster** (orange cap and shirt, holding a Poke Ball) and block 3 a
**Lass** (long brown hair, yellow/white outfit) -- both exactly the
mission's suggested confirmation targets. Block 10 is one of the Striaton
City **Gym Leader** trio (spiky red hair, formal wear -- Chili). Later
blocks resolve just as cleanly: block 39 and 82 are **Team Plasma**
grunts/officers (grey-blue and green uniforms with the Plasma emblem),
block 49 an **Ace Trainer** (sharp blue-haired trainer), blocks 78 and 81
**Elite Four** members (a bald martial artist -- Marshal -- and an ornate
purple-and-gold robed figure -- Caitlin), block 83 a **Swimmer** (bald,
goggles, trunks), block 86 a **Maid**, block 87 a **Subway Boss**
(conductor-striped coat and cane), and block 88 the **Champion** (wild
orange hair and a green robe -- Alder). No archive previously rendered by
this project showed a recognizable human battle sprite at this scale; the
earlier "battle-HUD UI" misreadings of other candidates (`a/0/7/8`,
`a/0/8/3`) are unrelated and stand as previously documented -- this is the
first time the actual trainer roster has been seen.

### Block layout: two NCGR sheets (not four), one NCER/NANR/NMCR/NMAR each, one unidentified member, one NCLR

Scanning every sub-file of one block by its post-decompression magic
(byte-for-byte, `python -c` against `narc.parse_file`/`try_decompress`)
gives, for every one of the 95 blocks checked:

| local | raw len | compression | decoded len | magic |
|---:|---:|---|---:|---|
| 0 | ~936-1170 | LZ11 | 3248 | `RGCN` (small NCGR) |
| 1 | ~931-965 | LZ11 | 16448 | `RGCN` (main NCGR) |
| 2 | 127 | none | 127 | `RECN` (NCER) |
| 3 | 89 | LZ11 | 111 | `RNAN` (NANR) |
| 4 | 60 | none | 60 | `RCMN` (NMCR) |
| 5 | 99 | none | 99 | `RAMN` (NMAR) |
| 6 | 60 | none | 60 | no magic (`u32 == 1`), unidentified |
| 7 | 72 | none | 72 | `RLCN` (NCLR palette) |

This is the same member set `a/0/0/4`'s rig uses (NCGR/NCGR/NCER/NANR/
NMCR/NMAR/NCLR) but **not** the same local-offset layout: `a/0/0/4`
duplicates both its NCGR sheets into 4 entries and carries two NCLR
palettes (normal/shiny) at offsets 18/19 of a 20-wide block; `a/0/7/2` has
exactly one NCGR per sheet, one NCLR, and an extra no-magic member, all in
an 8-wide block. Every one of the 95 blocks in `a/0/7/2` follows this exact
8-member layout (checked directly, not sampled).

### `rig.py` generalized: block members found by magic, not by a fixed per-archive offset table

Per the mission, `tools/assets/rig.py` no longer hardcodes `a/0/0/4`'s
local offsets (`LOCAL_NCGR_MAIN = 2`, etc., now deleted). New:

- `scan_rig_block(narc_obj, block_start, block_size)`: classifies every
  sub-file of one block by its own post-decompression magic
  (`RIG_MAGICS`), returning `{kind: [(local_index, data), ...]}`.
- `load_rig_block(narc_obj, block_start, block_size)`: picks the required
  members (NCGR/NCER/NMCR -- raises naming the missing one if absent) and
  the optional ones (NANR/NCLR -- `None` if absent). **The main NCGR sheet
  is simply the largest of however many `RGCN` entries the block has** --
  this one rule correctly picks `a/0/0/4`'s main sheet out of its 4
  duplicated entries (the previous fixed-offset code's job) and also
  correctly picks `a/0/7/2`'s single main entry, with no per-archive
  branch needed.
- `main()` gained `--block-size` (default 20, the `a/0/0/4` value); every
  render path (`render_one`, `render_animation`, `--all`, `--anim-all`,
  single-species mode) now threads `block_size` through instead of the
  module-level `BLOCK_STRIDE` constant.

**Regression-checked**: `python tools/assets/rig.py 25` (no `--archive`/
`--block-size`, i.e. the old default path) still writes
`build/assets/rig/0025_pose.png` at 59x56 -- byte-for-byte the same
dimensions the twelfth pass documented for Pikachu -- confirming the
by-magic member selection reproduces the old fixed-offset behaviour for
`a/0/0/4` exactly, not just "close enough."

### Rendered: 95/95 poses and 95/95 GIFs, siblings checked

`python tools/assets/rig.py --all --archive extract/data/a/0/7/2
--block-size 8 --out build/assets/trainers_rig` and the equivalent
`--anim-all` both report **95 rendered / 95 GIFs, 0 skipped** --
`build/assets/trainers_rig/` holds 95 `NNNN.png` poses and 95 `NNNN.gif`
animations (190 files total, gitignored, regenerate). Every GIF has
exactly **1 frame**: each block's NMCR has 1 multi-cell group of 1 node,
and that node's NANR sequence has 1 frame -- these are static single-cell
battle sprites, not animated rigs the way the Pokemon side is (the "GIF"
is a correctness-preserving degenerate case of the same exporter, not a
bug).

The two ~12-entry siblings the mission named are both **48 sub-files = 6
blocks of 8**, same member layout and same per-member sizes as `a/0/7/2`
(checked directly), and `a/0/7/3` is a byte-for-byte duplicate of
`a/0/6/4` in every rendered pose (confirmed by eye across all 6). Neither
is the generic 95-class roster; both are a **named-character back-sprite
set**: block 0 the male protagonist (back view, idle), block 1 the female
protagonist (back view), block 2 **Professor Juniper** (white lab coat,
green skirt), block 3 **Cheren** (dark hair, teal jacket), and blocks 4/5 a
second pose each of the two protagonists. This is the back-view battle
entry sprite for the rival/professor cast, not additional trainer classes.

### Class-to-block mapping: near-identity, with confirmed sprite-sharing merges starting around class 83

The trdata table (`a/0/9/2`, see the previous pass) puts the real trainer
class ids in the contiguous range 2..102 (101 distinct values), but
`a/0/7/2` has only 95 blocks (2 of them, 0/1, already spoken for by the
player characters, leaving 93 for classes 2..102) -- too few for a pure
1:1 table, exactly as the mission anticipated ("a small table or a gap
list"). Direct visual comparison against the 105-entry class-name text
bank (`build/assets/text/191.txt`) at every spot checked shows **the
mapping is the identity function on the class-id byte for most of the
range**, not a separate lookup table:

| class id | class name (bank 191) | block | rendered content |
|---:|---|---:|---|
| 0/1 | "Trainer"/"Trainer" | 0/1 | male/female protagonist |
| 2 | Youngster | 2 | Youngster (orange cap/shirt) |
| 3 | Lass | 3 | Lass (brown hair, yellow outfit) |
| 4/5 | School Kid x2 | 4/5 | boy (vest)/girl (pigtails+glasses) |
| 10 | Leader | 10 | Chili (red hair, Striaton trio) |
| 38 | Trainer | 38 | generic blonde girl, green beret |
| 39 | Team Plasma | 39 | Team Plasma grunt armor |
| 49 | Ace Trainer | 49 | blue-haired sharp-dressed trainer |
| 78 | Elite Four | 78 | Marshal (bald martial artist) |
| 81 | Elite Four | 81 | Caitlin (purple/gold robe, crown) |
| 82 | Team Plasma | 82 | green-uniformed officer |

Past this point the mapping **shifts by exactly -1** starting at class 83
("Depot Agent"): block 83 renders class 84's expected content (a male
Swimmer), not class 83's, and the shift holds continuously through block
90:

| class id | class name | block (id - 1) | rendered content |
|---:|---|---:|---|
| 84 | Swimmer (M) | 83 | bald swimmer, goggles, trunks |
| 85 | Swimmer (F) | 84 | ponytail, green bikini |
| 86 | Policeman | 85 | peaked cap, baton |
| 87 | Maid | 86 | bonnet, apron dress |
| 88 | Subway Boss | 87 | conductor-striped coat, cane |
| 89 | Champion | 88 | Alder (wild orange hair, green robe) |
| 90 | Cyclist | 89 | male cyclist |
| 91 | Cyclist | 90 | female cyclist |

The simplest explanation fitting all 19 spot-checked points: class 83
("Depot Agent") has **no dedicated sprite block** and reuses block 82's
(Team Plasma) art, so every block from 83 onward names the class one
higher than its own index. This is a real, confirmed instance of the
"gap list" the mission predicted -- found by direct visual cross-
reference against the class-name text bank, not by locating an explicit
table in ARM9 (a byte-run scan of `extract/arm9_dec.bin` for a ~105-entry
region where every value is below 95 turned up only unrelated small
coordinate-like tables, no plausible class-index array; given the mapping
is empirically near-identity with occasional merges rather than an
arbitrary permutation, a dedicated lookup table may not exist at all --
the "table" is just the trdata class-id field itself, minus a handful of
classes without their own block).

**Not fully resolved this pass**: block 91 (an elegant blonde figure in a
long black dress) does not match class 92 ("Motorcyclist") under the -1
rule, so a second merge happens somewhere between class 91 and 92 --
plausibly matching "The Riches" (class 93, a wealthy socialite, appears 6
times in the name bank) instead, i.e. "Motorcyclist" is itself a second
merged/reused class. Block 94 (the last block) is **not** a trainer class
at all -- it renders as a second, different pose of the female
protagonist (throwing a Poke Ball), matching block 1's character. So the
tail end of the archive (roughly blocks 91-94, needing to somehow stand in
for classes 92-102 -- 11 names including "The Riches" x6, "GAME FREAK",
and two more "Trainer"/"Team Plasma"/"Subway Boss" repeats) is **not** a
simple continuation of the -1 shift; it was not pinned down further this
pass. The single no-magic member (local 6, a bare `u32 == 1`) present in
every block is also still unidentified.

### Report

- **Verdict**: `a/0/7/2` (95 blocks x 8 sub-files) is the Black/White
  trainer battle sprite archive, confirmed by direct identification of
  the male and female protagonists, a Youngster, a Lass, a Gym Leader
  (Chili), two Elite Four members (Marshal, Caitlin), the Champion
  (Alder), and Team Plasma grunts/officers -- more named characters than
  the mission's own bar of "a Youngster, Lass, Ace Trainer, or a Gym
  Leader."
- **Block layout**: 8 sub-files/block -- small NCGR (3248B decoded), main
  NCGR (16448B), NCER, NANR, NMCR, NMAR, one unidentified no-magic member,
  NCLR. Detected by post-decompression magic (`scan_rig_block`/
  `load_rig_block` in `tools/assets/rig.py`), not by a fixed offset table.
- **`rig.py` generalized**: `--archive`/`--block-size` now drive member
  detection for any rig-shaped archive; `a/0/0/4`'s own render
  (`0025_pose.png`, 59x56) is byte-identical in dimensions to the
  twelfth pass's documented output, confirming no regression. One real
  regression was caught and fixed in the same pass: `scan_rig_block`
  decompresses every local in a block (not just the handful the old
  fixed-offset code ever touched), and a handful of `a/0/0/4`'s never-
  before-decompressed duplicate locals carry corrupt LZ11 streams --
  unguarded, that dropped `--all` from 712/714 to 681/714 species.
  `scan_rig_block` now catches a decompression failure per-local and
  skips it (same as an unrecognized magic) instead of raising, which not
  only restores but slightly **improves** on the twelfth pass's own
  figure: `a/0/0/4 --all` now renders **713/714** (species 712, previously
  one of the "two trailing non-rig slots," turns out to render a genuine
  Pokemon under by-magic member selection -- only species 713 is truly
  empty).
- **Renders**: `build/assets/trainers_rig/` -- 95 poses + 95 GIFs (1 frame
  each; these are static sprites, not animated rigs). Siblings `a/0/6/4`
  and `a/0/7/3` (48 sub-files = 6 blocks each, `a/0/7/3` a byte-for-byte
  duplicate of `a/0/6/4`) rendered to
  `build/assets/trainers_rig_probe/sibling_064|073/`: male/female
  protagonist (2 poses each), Professor Juniper, Cheren -- a named-
  character back-sprite set, not additional trainer classes.
- **Class mapping**: identity (block == trdata's class-id byte) for
  classes 0/1 (player characters) through at least 82, confirmed at 11
  spot-checked classes/names; a -1 shift confirmed continuously from
  class 83 ("Depot Agent", no dedicated block, reuses class 82's sprite)
  through class 91, confirmed at 8 more spot-checked classes/names. No
  explicit lookup table found in ARM9; the mapping is close enough to
  identity that the "table" may simply be a short list of classes without
  their own block, of which this pass located one (Depot Agent) directly
  and inferred a second (Motorcyclist, unconfirmed) near block 91.
- **Remaining gaps**: the exact merge point(s) between class 91 and 102
  (11 names, likely including "The Riches" x6 and "GAME FREAK", packed
  into blocks 91-94) are not resolved -- block 94 is confirmed to be a
  second female-protagonist pose, not a trainer class, so the tail of the
  archive does not simply continue the -1 shift. The single no-magic
  member at local offset 6 in every block remains unidentified. No
  species/class beyond the ~19 spot-checked this pass has been visually
  confirmed against its name; the mapping rule is well-evidenced but not
  exhaustively verified block-by-block.

## Map-model per-tile grid mission: wrapper header fully mapped across all 4 tags (`WB`/`GC`/`NG`/`RD`), grid record byte-lane semantics recovered (walkable flag confirmed high-confidence, height/edge lanes medium-confidence), `tools/assets/map_grid.py` added

Follow-up to the earlier map-model mission above (wrapper cracked, size
table + BMD0 + per-tile grid). This pass decodes the 8-byte per-tile
record's internal byte lanes and pins down the header size-table fields
for every wrapper tag, using `pl_00_00` (player's house), `map14_13` and
`map24_23` (outdoor terrain chunks) and `m_dun0101_00_00` (dungeon room)
as samples, cross-checked against the OBJ geometry already exported for
three of these. New tool: `tools/assets/map_grid.py` (`--dump` for
per-lane text matrices, `--png` for per-lane false-colour PNGs, both
under `build/assets/maps/`, gitignored).

### Header size-table fields: all four tags now mapped, including a new "no grid" tag and a previously-undocumented dungeon double-grid

Scanning every `a/0/0/8` sub-file's first two bytes confirms the four
tags and counts already known (`WB` 572, `GC` 47, `NG` 22, `RD` 8) and
this pass reads every remaining header `u32` for each:

- **`WB`** (20 bytes, one grid): `u32@8`=BMD0 end/grid start,
  `u32@12`=grid end/tail start, `u32@16`=total length. `u32@12` was
  previously "not pinned down" -- confirmed this pass by computing the
  grid's own byte extent (`4 + width*height*8`) from its self-describing
  `u16,u16` dimension header and matching it exactly against `u32@12` in
  every 32x32 sample (`map14_13`, `map24_23`); the one 64x64 sample
  (`pl_00_00`) leaves a 32-byte gap before `u32@12` that is NOT a second
  grid (see gaps below).
- **`GC`** (24 bytes) -- **new finding: carries TWO 32x32/8-byte grids
  back to back**, not one grid plus a tail as previously assumed:
  `u32@8`=grid-1 start, `u32@12`=grid-1 end/grid-2 start, `u32@16`=grid-2
  end/tail start, `u32@20`=total length. Confirmed structurally on
  `m_dun0101_00_00` (both grids' `4+1024*8=8196`-byte spans land exactly
  on these offsets) and the same shape holds on other GC samples
  checked. Every GC sample seen is a dungeon/room model; what the second
  grid represents (a second floor, a duplicate table, something else)
  is not resolved -- its distinct-value distribution closely mirrors
  grid 1's (same handful of record patterns, e.g. `pl`-style
  `01 00 81 00` "open floor"), which reads as "the same kind of data
  again", not confirmed further.
- **`NG`** (16 bytes) -- **new finding: this tag's files carry NO
  per-tile grid at all** (a plausible reading of the tag itself: "No
  Grid"). `u32@8`=BMD0 end, `u32@12`=total length; every NG sample
  checked (`c03_h00_00`, four `m_dun08xx`/`m_dun20xx` dungeon rooms) has
  0-100 bytes between BMD0's end and the sub-file's declared total
  length -- nowhere near a `4+N*8`-byte grid, and no `u16,u16` pair in
  that gap reads as a sane width/height. NG sub-files are not restricted
  to one model category (mixes a town building interior with several
  dungeon rooms), so the tag looks like a per-file "has grid data or
  not" flag rather than a category marker.
- **`RD`** (20 bytes, 8 files, all named `wf_*`/`bc_*`) -- one ordinary
  32x32/8-byte grid (`u32@8`/`u32@12` bracket it exactly as in `WB`),
  **followed by a second, denser block**: a 4-byte value that does NOT
  read as a sane grid dimension pair (consistently `4094` as a `u32`, a
  fixed constant, not a size), then exactly `64*64*4 = 16384` bytes --
  the right total size for a 64x64 grid of 4-byte records (found by
  size alone, matching in 6 of 8 samples exactly; the remaining 2 run
  16-32 bytes longer, unexplained). Given the `wf`/`bc` naming and that
  64x64 is the same finer resolution seen on `pl_00_00`'s indoor grid,
  the working guess is a per-quarter-tile water-surface table, but the
  4-byte record's internal layout was not decoded this pass (LOW
  confidence, size-match only).

`tools/assets/map_grid.py`'s `parse_wrapper()` locates grids generically
(read a `u16,u16` header, sanity-check the range, confirm the implied
byte span fits) rather than hard-coding per-tag grid counts, with one
deliberate restriction learned the hard way while writing it: a SECOND
grid is only accepted if its dimensions exactly match the first grid's.
Without that check, the unstructured tail bytes after a genuine single
grid occasionally parse as a "plausible" tiny bogus grid by pure chance
(a false 17x1 grid was found in `pl_00_00`'s tail, a false 5x2 grid in
`map24_23`'s, before this restriction was added) -- both false positives
are gone after requiring an exact size match, which is also the one
multi-grid shape actually confirmed (`GC`'s two identical 32x32 grids).

### Per-tile 8-byte record: byte-lane semantics (see `map_grid.py`'s docstring for the full writeup and confidence levels)

Decoded each grid's `width*height` 8-byte records into 8 separate byte
lanes and rendered each as a false-colour PNG
(`build/assets/maps/<name>_grid_lane<N>.png`) plus a hex text matrix
(`..._lane<N>.txt`):

- **`byte[4]` -- HIGH confidence: 0/1 walkable flag.** Plotted as a
  bitmap over `pl_00_00`'s 64x64 grid, this lane's shape IS the house's
  floor plan: an open border, one large blocked interior blob (walls +
  furniture) with an actual gap at the model's one door-sized opening.
  Same result outdoors: `map24_23`'s lane 4 bitmap shows scattered
  blocked patches (trees/rocks) against an open field, not noise.
- **`byte[6]` -- HIGH confidence: always `byte[4] | 0x80`** (0x80 when
  blocked, 0x81 when walkable) in every sample -- a redundant copy of
  the walkable bit with a constant high bit, not independently useful.
- **`byte[2]` -- MEDIUM confidence: a quantized height/terrain-level
  code.** In `map24_23`, bucketing the exported OBJ's vertices into grid
  cells by `(x,z)` and comparing per-cell sampled height against this
  lane finds a real correlation: the four-tile run where `byte[2]` steps
  `0,1,2,3` then plateaus at `4` (a literal ramp shape) sits exactly on
  the boundary between an OBJ-sampled higher plateau (~y=+0.05, lane
  value 0) and a lower one (~y=-0.3 to -0.4, lane value 4). The same
  lane also carries unrelated large outlier values on furniture/border
  tiles (103 in `pl_00_00`, 54 in `map24_23`) that break the smooth-ramp
  reading, so this lane looks overloaded (a terrain-step id on most
  tiles, a different per-object code on a handful of special ones) --
  not separated out this pass.
- **`byte[0]` -- MEDIUM confidence: an edge/boundary marker.** Near-zero
  everywhere except a thin line tracing the exact same ramp/cliff
  boundary `byte[2]` marks in `map24_23`, and a bordered-rectangle
  pattern (distinct small values per edge: 2/4/8/16/24) on the same
  furniture footprint `byte[2]` also lights up on in `pl_00_00`. Read as
  "this tile is a transition/interaction-side tile", not confirmed
  against any specific gameplay behaviour.
- **`byte[1]`, `byte[3]`, `byte[5]` -- LOW confidence: zero in every
  sample checked** across all four target files.
- **`byte[7]` -- LOW confidence:** 0x00 almost everywhere, a single
  isolated 0x80 tile seen once each in `map14_13` and `map24_23`, too
  sparse to say more.
- **Tall grass, water, ledges (one-way), stairs, doors/warps: NOT
  found.** No lane distinguishes any of these from ordinary walkable
  floor in the four sample files -- checked directly at `pl_00_00`'s one
  known door tile, which decodes to the exact same record as plain
  interior floor. Reported as a real negative result (every lane was
  checked at that specific tile), not a skipped check. Working
  hypothesis: these are handled by a separate event/warp/behaviour table
  outside this grid entirely, not encoded in it at any bit position this
  pass tested.

### Remaining gaps

- `pl_00_00`'s 64x64 grid ends 32 bytes before its header's declared
  grid-end offset (`u32@12`); those 32 bytes (16 `u16` values, no
  recognisable dimension header) are unexplained and are NOT a second
  grid (ruled out: they don't reproduce on `map14_13`/`map24_23`, and
  requiring an exact width/height match against grid 1 to accept a
  second grid -- the fix that removed the false-positive tiny grids
  above -- correctly rejects them too).
- `GC`'s second grid and `RD`'s dense secondary block are structurally
  located (exact byte offsets, confirmed sizes) but not semantically
  decoded.
- The true tail bytes after the last grid (order of 100-200 bytes in
  most samples) are not decoded in this pass either.
- Byte-lane analysis so far covers 4 sample files (1 house, 2 outdoor
  chunks, 1 dungeon room); `byte[0]`/`byte[2]`'s "overloaded" behaviour
  on furniture tiles suggests real per-object codes worth chasing with
  more samples, and the walkable-only result for doors/ledges/etc.
  should be checked against a sample that's known to actually contain a
  one-way ledge or a set of stairs (none of the four targets here do).

## Asset lane pass: Charizard/Gengar detachment root-caused as genuine authored placement data, not a decode bug -- all four field-level hypotheses ruled out archive-wide

Mission: find and fix the cause of the `a/0/0/4` rig's per-species detached
parts (Charizard/Gengar documented, "there are more"), checking four specific
hypotheses: NMCR node-offset sign extension, a NANR type-1/2 per-frame offset
this reader ignores, an NCER "bounding rectangle" cell attribute changing the
OAM origin, and NMAR selecting a different node set/frame than the one
composed. **Result: all four are false, now confirmed across the whole
archive (713 species), not just the two documented samples** -- this pass
finds no field-level bug to fix and applies none, per this project's practice
of reporting a negative result plainly rather than dressing up a partial one.
One real (but unrelated, and not applied) latent bug was found in the same
sweep; see below.

### (1) NMCR node-offset sign extension: correct

`Nmcr`'s node record is unpacked with `struct.unpack_from("<Hhh", ...)` --
Python's `h` format is already 2's-complement 16-bit, and the decoded values
for both documented species read as ordinary small negative/positive numbers
(e.g. Charizard's node 10: `x=-8, y=-50`) with no wraparound artifacts.
Cross-checked against `Ncer`'s own OAM x-field, which uses an explicit
9-bit sign correction (`x - 512 if x >= 256 else x`) matching the public
GBA/NDS OBJ attr1 layout exactly -- both sign-extension paths were re-derived
from raw hex by hand for Charizard's cells 6/7 (the detached feet) and found
byte-exact. Not the cause.

### (2) NANR type-1/2 per-frame offset: correct, and already applied

Dumped `frame_data()` across every frame (not just frame 0) of the exact
sequences the two documented species' detached nodes reference (Charizard
seq 6/7, both `etype=0`/index-only, `num_frames=1`, so there is only one
frame, period; Gengar seq 0/5/6/7, `etype` 1/2, `num_frames=7`, a small
"idle-breathing" cycle). Every sampled frame reads `px=py=0` with at most a
1-3px scale/rotation wobble -- `compose_pose()` already adds `frame.(px,py)`
to `node.(x,y)` before the OAM offset (see `_frame_placements`), so this data
is not being dropped; there is simply no non-zero offset in it to find for
these nodes at any frame. Raw-byte re-verification of the index-type (`etype
0`) record shape also confirmed it really is a bare 2-byte `cellIdx` followed
by `0xCCCC` alignment filler (both Charizard's and Pikachu's index sequences
show the identical filler pattern) -- no hidden px/py field this reader
mis-sizes past. Not the cause.

### (3) NCER "bounding rectangle" cell attribute: never present anywhere in this archive

`func_0206285C.c`'s own comment says a bank-level `bankAttr` bit0 (this
module's `cell_info_type`) selects 8-byte "simple" vs. 16-byte "extended
with a bounding box" cell records. Scanned **all 713 parseable species/form
blocks** in `a/0/0/4` for this one field (not sampled): `cell_info_type ==
0` in every single one. There are zero cells anywhere in this archive using
the extended/bounding-box record shape, so this can't be an origin-shifting
factor for any species, documented or not. Not the cause.

### (4) NMAR selecting a different node set/frame: also archive-wide false

Two sub-checks, both swept over all 713 blocks rather than the two
documented species:

- **`NMCR`'s own embedded-animation-bank field (`animBankOfs`, offset
  0x10 of the bank header) is `0` in every one of the 713 blocks.** This
  tool's assumption that the block's separate NANR sub-file (not an
  embedded bank inside NMCR) is always the right animation source is
  therefore right everywhere, not just for the species already checked.
- **Rendering `--group 1` was re-confirmed to reproduce the identical
  detached parts** for both documented species (this was already known
  from the thirteenth pass; re-run this pass as a sanity check, unchanged
  result).

One further, *new* structural check this pass added for Gengar specifically:
its two multi-cell groups are **not** the same size (group 0 has 12 nodes,
group 1 has 10), and the two "extra" group-0 nodes reference NANR sequences
20/21 -- outside the otherwise-clean 0-9 (group 0) / 10-19 (group 1) split
every other node follows. This looked like a promising lead (a decorative
element folded into the "main" group by mistake) but **direct testing
falsifies it**: `compose_pose()` was re-run on Gengar's group-0 node list with
those two nodes (array positions 0/1) removed, and the rendered pose is
pixel-identical apart from losing two small, already-correctly-attached
parts near the feet -- the actual floating right-side shapes are unaffected,
because (confirmed by connected-component analysis of the real
`0094_pose.png`, see below) they come from four different, perfectly
ordinary nodes, not the two out-of-range ones.

### Corrected node/cell attribution for Gengar (species 94), by pixel evidence

The thirteenth pass located Charizard's detached nodes correctly (its own
description, "two nodes far apart in x at the bottom of the canvas," matches
this pass's connected-component measurement of `0006_pose.png`: components at
rows 82-89 and 86-92 against a body that ends at row 77, i.e. nodes 0/1,
NCER cells 6/7 -- the two clawed feet). Its description of Gengar's detached
nodes ("two nodes at positive x, upper right") does not match array
positions 0/1 under this pass's pixel measurement: `scipy.ndimage.label` on
`0094_pose.png` finds the floating right-side shapes at pixel columns 38-63,
rows 10-63 (two components, 366px and 283px), which line up with **node
array positions 4, 5, 6 and 11** (NCER cells 6, 3, 2, 5 respectively; NANR
sequences 7, 6, 5, 0) once each node's absolute bbox is computed from
`node.(x,y) + frame.(px,py) + cell.(minx,miny,maxx,maxy)`. Positions 0/1
(sequences 20/21, cells 14/13) instead land at columns 20-28, rows 56-64 --
the small feet directly under the head, which read as correctly attached in
the render (components 7/8, no gap to the body above them). This correction
doesn't change the pass's conclusion (still no fixable field found) but
means any future pass chasing this should look at nodes 4/5/6/11, not 0/1.

### A real, but unrelated (and NOT applied) latent bug: `Oam.pal` is parsed and never used

While sweeping OAM fields archive-wide for the checks above, `Ncer.Oam.pal`
(attr2 bits12-15, the 4bpp OBJ palette-bank selector) was found to be parsed
into every `Oam` object and then never read anywhere in `rig.py`'s
compositing path (`render_oam`, `_cell_local_raster`, `indices_to_rgb` all
implicitly treat every OAM as bank 0). Scanning all 713 species: **711 use
only bank 0** (this field is inert for them, so the bug has caused zero
visible error for the entire documented detachment set including both
Charizard and Gengar, which are bank-0-only throughout). Exactly **2 species
(301, 327)** have at least one OAM with `pal == 1`. This pass deliberately
did **not** patch it in: `bs.parse_nclr()` returns a plain 16-color list for
this archive's per-species NCLR sub-files (not a full 256-color, 16-bank
OBJ palette), so a naive `pal*16 + index` offset would read indices 16-31
out of a 16-entry table and produce *more* wrong (magenta-fallback) pixels
for species 301/327, not fewer, without independent evidence for what a
nonzero bank is actually supposed to select in a per-species-16-color
archive (a second bank loaded from the adjacent shiny-palette sub-file?
authoring noise?). Flagged here as a genuine, narrowly-scoped bug for a
future pass with time to check hardware/emulator ground truth against these
two specific species, not fixed speculatively.

### Verdict and species count

**0 species were fixed this pass.** Charizard (`0006_pose.png`/`.gif`),
Gengar (`0094_pose.png`/`.gif`), and two known-good species of comparable
part count -- Pikachu (`0025`, 10 nodes) and Mewtwo (`0150`, re-rendered and
visually re-confirmed as a single connected silhouette, see prior passes) --
were all re-rendered into `build/assets/rig/` (gitignored) with the
unmodified code; Charizard and Gengar still show exactly the same detached
parts as the twelfth/thirteenth passes documented, byte-for-byte the same
node data as before (no code change was made). This reconfirms, with
archive-wide rather than sampled evidence, the thirteenth pass's own
conclusion: **the gap is real data (`node.(x,y) + frame.(px,py) +
cell.(x,y)`, all correctly decoded) that this placement formula assembles
exactly as the file describes it**, not a parsing error in sign extension,
frame-offset application, cell record shape, or animation-bank selection.
Whether the true hardware renderer reads additional information this format
doesn't expose to a static analysis (a parent/child bone offset, or a
per-species correction table living in ARM9 code rather than this archive)
remains open, same as the thirteenth pass left it -- this pass narrows where
that missing information would have to live (not in any of the four fields
named in its own mission) rather than finding it.

### Files touched

`tools/assets/rig.py`: no behavioral change. `docs/ASSETS.md`: this section.

### Remaining gaps

- The Charizard/Gengar (and unnamed "more") detachment is still unresolved;
  this pass's contribution is ruling out four specific mechanisms
  archive-wide and correcting which nodes are responsible for Gengar's
  floating parts, not a fix.
- `Oam.pal`'s real meaning for the 2 species that use a nonzero bank (301,
  327) is undecoded; applying a `pal*16` offset against this archive's
  16-color-only per-species NCLR would need a second, larger palette source
  identified first (not attempted this pass).
- No archive-wide visual/pixel scan for *which* species besides Charizard
  and Gengar show the same kind of detachment was run this pass (the
  mission's four hypotheses were all field-level and archive-wide-checkable
  without rendering every species; a visual sweep is a reasonable next step
  now that those four are closed out).

## Map attribute hunt: byte[1]/byte[3] were mis-reported as always zero -- archive-wide they carry real outdoor-only terrain codes; a separate-NARC search and the wrapper's other unexplained blocks come up empty (`--attrs` added to `tools/assets/map_grid.py`)

Mission: find where tall grass, water, ledges, stairs, and doors/warps are
encoded, since the per-tile 8-byte grid record (`tools/assets/map_grid.py`)
only explains walkability (byte[4]/[6]) and a height/edge pair
(byte[2]/[0]). Method followed in the order given: (1) re-examine the
wrapper's other unexplained blocks against a known-grass sample, (2)
search for a separate per-zone NARC, (3) scan all 572 `WB` files for
byte[1]/[3]/[5]/[7], which the previous pass's 4-sample docstring called
"zero in every sample checked."

### Result up front: (1) negative, (2) negative, (3) positive -- the previous "always zero" claim was a sampling artifact, not a fact about the format

`byte[1]` and `byte[3]` are real, outdoor-only attribute lanes. The
earlier pass's 4 target files (`pl_00_00`, `map14_13`, `map24_23`,
`m_dun0101_00_00`) happened to have these lanes all-zero -- 2 of the 4
are indoor/dungeon and the 2 outdoor ones simply didn't use these lanes.
Scanning all 572 `WB` sub-files (`python tools/assets/map_grid.py
--attrs`) finds:

- **`byte[1]`**: nonzero in 68/572 files, values 1-5. **0/18** plain
  house/town-building interiors (`pl_*`, `c0*`, `c1*`) vs **22/182**
  outdoor-prefixed files (`mapNN_NN`, `leaginNN`, `winterNNNN`, etc.).
- **`byte[3]`**: nonzero in 227/572 files, values 1-5. **0/18** houses vs
  **86/182** outdoor.
- **`byte[5]`**: nonzero in only 1/572 files, a single uniform value
  (0xFF) -- an isolated special case, not a general lane.
- **`byte[7]`**: nonzero in 193/572 files, values 0x80 (1834 tiles) and
  0x7F (58 tiles) -- **7/18** houses vs **83/182** outdoor, so unlike
  byte[1]/[3] this one is NOT outdoor-exclusive (matches the original
  pass's "single isolated tile" note, just more widespread than the 4
  samples showed).

Full histograms (all 572 `WB` files, `0` bucket included):

| lane | nonzero files | values (count) |
|---|---:|---|
| byte[1] | 68 | 1:810, 2:103, 3:30, 4:21, 5:6 |
| byte[3] | 227 | 1:55224, 2:24220, 4:3758, 3:1257, 5:14 |
| byte[5] | 1 | 255:58 |
| byte[7] | 193 | 128:1834, 127:58 |

### byte[1]: line/edge-shaped, plausible ledge or directional-boundary code

Visualising byte[1] over the walkable mask (`.`=open, `#`=blocked, digit=
byte[1] value) on `leagin02_00_01` (a/0/0/8#210) shows two long straight
runs of value `1` cutting across open, otherwise-uniform ground -- 11 and
18 tiles long, on two different rows, not bordering any blocked tile:

```
....................############
...
.............1.......###########      <- single tile, row 14
......................##########
11111111111..........###########      <- row 16, cols 0-10
.....................###########
...
11111111111111111.....###.###.##      <- row 22, cols 0-16
```

That shape (a straight line through otherwise-open ground) is exactly
what a one-way ledge/drop edge looks like, not a decorative marker.
Elsewhere the same lane instead outlines one edge each of a rectangular
blocked footprint with a distinct value per side --
`m_siten02_00_00` (a/0/0/8#554) has a building-sized blocked rectangle
with `4` tracing its top edge, `2` its left edge, and `5` its right edge
(bottom is unmarked). That is consistent with a directional
edge/collision-side code (walk direction blocked/allowed per side) rather
than a single boolean, which fits a ledge (jumpable from exactly one
side) better than it fits tall grass or water (neither of which needs a
side-specific code). Not cross-checked against a sample with a
gameplay-confirmed ledge, so this reading is MEDIUM confidence, not
proven.

### byte[3]: area-fill, plausible terrain-subtype/zone code (tall grass candidate, unconfirmed)

Unlike byte[1]'s thin lines, byte[3] fills large contiguous regions of
already-walkable ground with one value. `map19_19` (a/0/0/8#20) has value
`1` on 738 of its 1024 tiles -- essentially the whole open field of that
route chunk, stopping exactly at two blocked building footprints (never
overlapping a blocked tile in any sample checked). `t05_00_01`
(a/0/0/8#159) shows the same large-fill pattern for value `1`, plus one
lone tile of value `2` sitting inside the filled region, and a second
region where `5` traces a vertical edge next to a `1`-filled strip --
the same edge-per-side character as byte[1], on a different value.

This shape (a single value covering nearly an entire open route field)
is a plausible carrier for "this walkable tile is tall grass," since real
Black/White routes are often mostly grass with a dirt path cut through --
but no sample checked here has an independently known grass/no-grass
boundary to confirm which value means what, so this is reported as a
strong structural candidate, not a confirmed identification.

### (1) Wrapper's other unexplained blocks, re-examined against `ue_grass00`/`ue_grass01` (map24_23): no correlation found, and the premise partly doesn't hold

Regenerated `map24_23`'s textured OBJ (`tools/assets/map_shapes.py
--targets map24_23`) to get real face positions per material. The
previously-noted `grass01ax` texture turned out to be a **zero-face**
shape in this model (one of the "4 shapes decode vertices but 0 faces"
already documented as a gap) -- it cannot be used as a ground-truth grass
footprint here, and on inspection it is just the generic terrain ground
texture (confirmed visually coherent as "grass" in the earlier texture
pass), not a marker for the specific tall-grass/encounter tile type.

Two other materials, `ue_grass00` (4 faces) and `ue_grass01` (10 faces,
in 5 duplicated pairs at two different heights -- a crossed-plane
billboard, the standard way to fake volumetric grass with flat geometry),
ARE present with real faces. Converting their face centroids to grid
cells (origin -4,-4, cell size 0.25 = 8 units / 32 tiles, matching the
model's own bounding box) and cross-referencing against the byte[4]
walkability mask finds **all 9 cells sit on already-UNWALKABLE ground**
(inside the map's large blocked interior blob, which the texture set
suggests is a cliff/rock formation, not open field). This means
`ue_grass00`/`ue_grass01` are decorative ground-clutter props modeled
directly into the map's own geometry (not textured onto the terrain
grid), placed on rocks/cliffs at the model level -- **not** the
gameplay tall-grass/encounter tile type, and not encoded in the grid at
all. Re-tested the mission's four named blocks against this (negative)
sample:

- **`pl_00_00`'s 32-byte unexplained gap** (16 `u16` values): ruled out
  on size grounds alone, independent of the grass test -- 16 entries
  cannot index a 64x64=4096-tile grid at any useful granularity (not even
  1 bit/tile: 32 bytes = 256 bits, a quarter of what a bitmask would
  need).
- **`GC`'s second grid**: no outdoor `GC` sample exists (`GC` is
  dungeon/room-only, confirmed in the original pass), so it cannot be
  tested against an outdoor grass sample at all; still only structurally
  located, not semantically decoded.
- **`RD`'s dense 64x64x4 block**: decoded one level further this pass.
  Reading its 4-byte record as two `u16` LE values (a, b) on `wf_00_00`
  (a/0/0/8#228) finds only 5 distinct records across all 4096 cells:
  `(0,0)` (2049 cells), `(0,4094)` (682), `(4094,0)` (682), `(0,128)`
  (535), `(1,129)` (148). `4094` (0x0FFE) matches the block's own leading
  4-byte header constant exactly, reading as a "no data here"/edge
  sentinel; `(0,128)` and `(1,129)` are byte-for-byte the same
  `(walkable, walkable|0x80)` pair the ordinary 8-byte grid record uses
  at byte[4]/byte[6]. Best current reading: a finer-resolution walkable
  mask for the water surface with a boundary sentinel, not a distinct
  water-type code -- still no water/grass/ledge-specific field found in
  it, so the earlier "structurally located, not semantically decoded"
  verdict stands, just with one more layer peeled off.
- **True tail bytes** (`map24_23`'s 196-byte `WB` tail): re-examined as
  hex; it has real repeating 8-byte-ish structure (an exact duplicate
  8-byte group appears once, `09 00 02 00 76 00 83 01`), so it is not
  random padding, but the field boundaries and meaning were not pinned
  down this pass -- reported as a real, still-open gap, not decoded.

### (2) Separate per-zone NARC search: no candidate survives

Enumerated every NARC's sub-file count against the map counts (649 total,
572/47/22/8 per tag) and looked for sub-file sizes matching
`32*32*n`/`64*64*n` bytes, using `build/assets/inventory.json`
(`tools/assets/inventory.py`'s cached per-NARC summary) plus direct
`narc.py` reads for the candidates it surfaced:

- **Count matches**: only two NARCs have exactly 649 sub-files:
  `a/0/0/8` itself, and `a/1/7/8`. `a/1/7/8` is **649 fixed-size,
  249-byte records** (every sub-file exactly 249 bytes) -- far too small
  to be a 32x32 grid (1024 bytes minimum) and structurally a sparse
  marker table (5 nonzero bytes per record at fixed offsets, e.g.
  `01 01 00...` for most entries), not tile data. No NARC has exactly
  572, 47, or 22 sub-files (the per-tag counts); one NARC (`a/0/4/3`) has
  47 sub-files but with wildly variable sizes (193-32832 bytes) matching
  its existing "trainer/item/UI sprites" guess, not map data.
- **Size matches**: scanning every NARC's `sub_file_size_min`/`_max`
  against `{1024, 2048, 3072, 4096, 8192, 16384}` (and their +4/+8-byte
  header variants) finds no NARC with a cluster of sub-files at those
  exact sizes; the closest, `a/0/0/3` (472 files, 32-160444 bytes) and
  `a/0/6/6` (601 files, 64-4576 bytes), are both variable-length
  bytecode-shaped (a leading `u8` tag then small `u32` offset fields,
  e.g. `a/0/0/3#0` opens `01 00 21 00 48 1c 00 00 ...`) -- these read as
  the per-map **event/script table** the earlier pass's docstring
  already guessed might hold doors/warps, not a per-tile attribute grid.
  Their exact semantics were not decoded this pass (out of scope: the
  mission asked for the per-tile attribute source, and these are
  variable-length per-object records, not a fixed per-tile array) but
  are flagged here as the most likely home for door/warp trigger data,
  consistent with `pl_00_00`'s door tile decoding to a plain-floor grid
  record with nothing to distinguish it.

**Verdict for step 2: no separate per-zone grid NARC found.** The
per-tile attributes this mission is chasing, to the extent they exist at
all, live inside `a/0/0/8`'s own grid record (byte[1]/byte[3], see
above), not in a companion archive.

### `tools/assets/map_grid.py` changes this pass

Added `--attrs`: scans all `WB` sub-files, prints the byte[1]/[3]/[5]/[7]
histograms and house-vs-outdoor nonzero counts above, and writes an ASCII
map (`<name>_attr_lane{1,3}_ascii.txt` under `build/assets/maps/`) for
each requested target (`.`=walkable/lane-zero, `#`=blocked/lane-zero,
digit=the lane's value). Docstring's per-lane confidence table updated
in place (byte[1]/[3]/[5]/[7] entries revised from the prior "zero in
every sample" claim to the archive-wide findings above; the other lanes'
entries are unchanged).

### Remaining gaps

- Which specific value of byte[1] or byte[3] means "tall grass" vs
  "ledge, direction N" vs "zone/route id" is not confirmed -- no sample
  used this pass has an independently known ground-truth tile (a
  screenshot-verified grass patch, ledge, or stairs) to check a decoded
  value against.
- Water and stairs specifically have no candidate lane at all identified
  this pass (byte[1]/[3] are the leading candidates for ledges/grass or
  a zone code; nothing found points specifically at water or stairs
  beyond `RD`'s already-partial dense block, which reads as a finer
  walkable mask, not a water-type flag).
- `a/0/0/3` and `a/0/6/6` (the event/script-table candidates for
  doors/warps) were located and their opening bytes sampled, but not
  parsed -- their field layout is a real follow-up, not attempted here
  since the mission's primary target was the per-tile grid.
- `map24_23`'s 196-byte tail structure (the repeating 8-byte-ish group)
  is noted but not decoded.
- `RD`'s dense block's two `u16` lanes are characterized (walkable-pair
  plus a `4094` sentinel) but not confirmed against a second `RD` sample
  beyond `wf_00_00`.

## Asset lane pass: SBNK types 2/3 decoded as PSG square/noise and synthesized in `sseqsynth.py`, `Oam.pal` palette-bank nibble applied against a species' own normal+shiny NCLR pair, `a/0/7/2`'s no-magic member identified as a per-cell 48-byte record table

Three small, independent gaps closed or narrowed this pass.

### (1) SBNK instrument types 2/3: confirmed PSG square/noise, decoded and rendered

The mission's hypothesis was tested directly against all 1497 real SBNKs:
for every one of the 122 real type-2 instruments, the leading u16 (the
field that is `wave_id` for a wave-bearing type) is 0-6 (never above 7,
105/122 exactly 3) and the trailing u16 (`wave_arc` for a wave-bearing
type) is **0 in all 122** -- 0 is never a valid `wave_arc` for a real
type-1 instrument (every real one resolves through the owning bank's own
`wave_arc[4]` table), so a constant 0 across every bank is the signature of
"this field isn't a wave_arc," not coincidence. For type 3, **both**
leading u16s are 0 in all 155 real instruments. This matches the mission's
hypothesis exactly: type 2 is a PSG square/pulse instrument whose first u16
is a duty-cycle selector (0-7), type 3 is the PSG noise generator with no
wave-shaped fields at all; both keep the same trailing note/attack/decay/
sustain/release/pan bytes as every other instrument type.

`tools/assets/sbnk.py` now decodes both: `_parse_psg_square()` returns
`{duty, unused, base_note, attack, decay, sustain, release, pan}` and
`_parse_psg_noise()` returns `{base_note, attack, decay, sustain, release,
pan}` (no wave fields at all). `Instrument.parse_detail()` dispatches types
2/3 to these instead of the generic wave-record parser. **Round trip is
unaffected and still 1497/1497 (100%) byte-identical** -- the container/
table structure this guarantees was never touched, only what `parse_detail()`
reports about bytes it already had.

`tools/assets/sseqsynth.py` gained procedural PSG synthesis: `synth_psg_
square()` generates a bipolar rectangular wave at the played note's own
frequency (`note_freq_hz()`, standard equal temperament -- a PSG channel
has no recorded base_note to pitch-shift from, unlike a PCM region: the
played note *is* the frequency) with high/low ratio `(duty+1)/8`;
`synth_psg_noise()` generates the DS's 15-bit Galois LFSR noise (the
width the NDS sound hardware documentation gives -- no selectable 7-bit
"short" mode like the GBA APU), clocked once per output sample at the same
note frequency (an approximation of the real hardware's separate noise
clock-divider, documented as such). `resolve_instrument_region()` now tags
every returned region `"kind": "wave"/"psg_square"/"psg_noise"`, and
`render_seq()` branches on that tag to call `render_psg_note()` instead of
resolving a `Swav` for the PSG kinds.

**Re-rendered**: `SEQ_BGM_BATTLEPINCH` (SEQ index 1146), a real BGM whose
bank (1146) has a type-2 PSG square instrument at program 48, written to
`build/assets/audio/1146_battlepinch_psg.wav`. 104 of the sequence's 173
note events use program 48 -- previously silently dropped (types 2/3
returned `None` from `resolve_instrument_region`, so every note using them
rendered as silence); now synthesized as a duty-cycle square wave. The
render reports 120/173 notes rendered (28 dropped for unrelated reasons,
not from types 2/3), non-silent, not clipped.

**Remaining gap**: the noise channel's real per-instrument clock rate
(the DS noise generator has its own frequency register independent of the
tone channels', per public documentation, but nothing in the SBNK type-3
record exposes a distinct rate field) is approximated as "one LFSR step
per output sample at the played note's frequency" -- audibly a clocked
noise burst, not a cycle-exact reproduction of hardware.

### (2) `Oam.pal` (OAM palette-bank nibble) applied: it selects a species' *other* NCLR, not a within-palette row

Checked directly against the 2 species (301, 327 in `a/0/0/4`) that have
any OAM with a nonzero `pal`: both have exactly the same block shape as
every other species in this archive -- **two** NCLR members (18/19, a
normal/shiny pair) of **16 colors each**, and an NCGR at `pixel_fmt == 3`
(4bpp) throughout. Neither species has a single larger, 256-color NCLR
hiding extra palette rows -- the mission's "256-colour palette in 16-colour
banks" branch of the hypothesis is false for both. What actually holds:
concatenating a block's own NCLR members in local order (18 then 19) into
one 32-row table and indexing `pal * 16 + color` into *that* reproduces
exactly the second NCLR's own colors for every `pal == 1` OAM -- i.e. the
palette-bank nibble selects **which of a species' own two NCLR palettes**
an individual OAM draws from, not a row offset within a single larger
table. This makes sense of why only 2 of 713 species show it: it lets one
or two specific body parts (e.g. an accent color) pull from the "other"
variant's table regardless of which NCLR the rest of the sprite uses.

`tools/assets/rig.py` changes:
- `load_rig_block()` now also returns `nclr_all`, every NCLR member found
  in the block in local order (previously only the first was kept,
  discarding the second).
- New `build_bank_palette(nclr_all)`: concatenates every member's parsed
  colors into one table.
- `render_oam()` takes `n_pal_colors` and applies `oam.pal * 16` as an
  index offset **only when the combined palette actually has `(pal+1)*16`
  rows** (`bank_ok = oam.pal * 16 + 16 <= n_pal_colors`) -- for the 711
  bank-0-only species this is a no-op (offset 0), and for any species with
  only one NCLR member the bank is left unapplied rather than reading past
  the table, per the mission's own caution. `n_pal_colors` is threaded
  through `_cell_local_raster`/`_cell_frame_raster`/`_frame_placements`/
  `compose_pose_multi`/`compose_pose`/`render_cells_contact_sheet` down
  from each of the three call sites (`render_one`, `render_animation`,
  single-species `main()`), which now build the palette with
  `build_bank_palette(nclr_all) or DEFAULT_PALETTE` instead of parsing
  only the first NCLR.

**Rendered and checked**: species 25 (Pikachu, bank-0-only, regression
check) is byte-identical in dimensions to every prior pass's documented
`0025_pose.png` (59x56) -- no behavior change for the 711 unaffected
species. All 713 parseable species/form blocks still compose without a
new exception (713/713, same count as before this pass). Species 301's
rest-pose render (`0301_pose.png`, group 0, t=0) is pixel-identical with
the bank applied or not -- its 4 `pal == 1` OAMs are not placed by any
frame in groups 0 sampled at t=0..36, so the fix has no visible effect in
that specific render (the cells they belong to are reached by some other
animation path not exercised by the default pose). Species 327's rest
pose (`0327_pose.png`) does change: 418 of 4488 pixels differ, all within
a small mouth/accent element, matching the *other* NCLR's slightly duller,
less saturated color instead of the base palette's more vivid one --
correct-looking (no magenta-fallback or garbage pixels), not visually
broken.

### (3) `a/0/7/2` trainer block's no-magic member (local 6): a per-cell 48-byte record table, exact size confirmed, field meaning not decoded

The previous pass's description ("a bare `u32 == 1`") turns out to only
describe 86 of the 95 real blocks. Dumping and comparing the raw
(post-`try_decompress`, though this member is stored uncompressed in
every block) bytes of all 95 blocks' local 6 gives an exact, unambiguous
container shape:

    u32 count        (see below -- NOT a constant, despite the previous
                       pass's read of the common case)
    8 bytes reserved  (measured zero in all 95 blocks, no exception)
    count x 48-byte record

Sizes cluster at 60 (`count=1`, 86 blocks), 156 (`count=3`, 5 blocks: 37,
38, 77, 78, 80), 204 (`count=4`, 2 blocks: 54, 79), 252 (`count=5`, 1
block: 40), and 300 (`count=6`, 1 block: 91) -- `12 + count * 48` fits
every one of the 95 sizes exactly, no remainder, no exception.

**`count` is exactly the block's own NCER cell count** (`ncer.num_cells`),
checked programmatically for all 95 blocks (95/95 match, not sampled):
block 0 (1 cell) has count 1, block 37 (3 cells) has count 3, block 91 (6
cells) has count 6, and so on for every block in between. This member is
therefore **one 48-byte record per NCER cell**, not a per-block flag.

All 86 `count == 1` blocks' single record is **byte-identical**: hex
`01000000 0000000000000000 00d8ffff 00280000 00000500 00000500 00000000`
`...` (zeros to the end of the 48 bytes) -- i.e. every single-cell trainer
(the overwhelming majority of the roster) uses the exact same record,
which as signed 32-bit little-endian fields decodes to `(-10240, 10240,
327680, 327680, 0, 0, 0, 0, 0, 0, 0, 0)`. `327680 == 0x00050000` is `5.0`
in 16.16 fixed point; `-10240`/`10240` are a symmetric +-10240 pair. For
the multi-cell blocks, later records repeat this same first-two-field
shape with small variations (e.g. block 91's 5 populated records read
`-10240, -10496, -10752, -11008, -11264` for the first field across
cells 0-4, each 256 apart) and a *distinct* two-field shape -- `(65536,
-65536, 0, ...)` i.e. `(1.0, -1.0)` in 16.16, all other fields zero --
that shows up exactly where the block's NCER has an **empty cell**
(`cell.num_oam == 0`): block 54's cell 3, block 79's cell 3, and block
91's cell 5 are all `num_oam == 0`, and all three are exactly the
`(1.0, -1.0)` record, never the populated `(-N, 10240, 5.0, 5.0, ...)`
shape. This is a clean, exact correlation (3/3), not a coincidence.

**No decoder was written** for this record, per the mission's own
instruction not to guess an ambiguous inner layout: the outer count-per-
cell structure and the empty-cell sentinel are solid, but which of the
"small table of per-pose offsets," "shadow/size descriptor," or "2D-to-3D
placement record" candidates the populated record actually is remains
undetermined from data alone. The strongest-fitting candidate given the
evidence is a **per-cell shadow/size descriptor**: a symmetric offset pair
alongside a constant "width"/"height"-shaped 5.0 pair reads naturally as
an ellipse (a battle sprite's ground shadow, one per pose/cell, degenerate
for a cell with no OAMs to cast one) -- but this is a plausibility
argument, not an independent verification (no rendered/hardware ground
truth was checked against it), so `tools/assets/rig.py` is left
unchanged for this member.

### Files touched

`tools/assets/sbnk.py`: types 2/3 decoded (`_parse_psg_square`,
`_parse_psg_noise`), `TYPE_NAMES` updated, docstring corrected.
`tools/assets/sseqsynth.py`: `synth_psg_square`/`synth_psg_noise`/
`render_psg_note`/`note_freq_hz` added, `resolve_instrument_region`
tags every region's `kind`, `render_seq` branches on it. `tools/assets/
rig.py`: `load_rig_block` returns `nclr_all`, `build_bank_palette` added,
`render_oam`/`_cell_local_raster`/`_cell_frame_raster`/`_frame_placements`/
`compose_pose_multi`/`compose_pose`/`render_cells_contact_sheet` thread
`n_pal_colors`, the three render call sites build the bank-aware palette.
`docs/ASSETS.md`: this section.

### Remaining gaps

- SBNK type 3's real per-instrument noise clock rate is not exposed by
  this record and is approximated (see above).
- `Oam.pal` for species 301 specifically has no visible effect in the
  rendered rest pose sampled this pass -- its nonzero-bank OAMs sit in
  cells not reached by the frames/groups checked; a future pass with time
  to walk every NANR sequence (not just the rest-pose group at a handful
  of sampled times) could confirm whether they're ever actually visible.
- `a/0/7/2` local 6's per-cell 48-byte record's populated-case field
  meaning (shadow ellipse vs. per-pose offset vs. something else) is still
  open; the container shape and the empty-cell sentinel are the only
  parts confirmed this pass.

## Asset lane pass: byte[3]-as-tall-grass hypothesis tested against the map's own ground textures -- REFUTED, byte[1]-as-ledge left inconclusive on this sample

Mission: use the per-shape textured map export (`tools/assets/map_shapes.py`)
as ground truth to confirm or refute byte[3] as the tall-grass/encounter
lane and byte[1] as the ledge lane (both from the earlier map-attribute-hunt
pass above). Targets: `map19_19` (738/1024 byte[3]-nonzero, a/0/0/8#20),
plus two more outdoor files with a mixed byte[3] histogram picked by
scanning all 572 `WB` files for >=2 distinct nonzero byte[3] values:
`map23_11` (a/0/0/8#257, values {1,2}) and `winter0701_01_00`
(a/0/0/8#397, values {1,2,3,4}).

### Method: per-tile ground texture by point-in-polygon at tile centre

For each target, the model was loaded with `map_shapes.py`'s own shape/
material decode (`shape_export_data`), giving every triangle's world-space
vertices and its resolved bare texture name. Per tile, the covering face
was found by projecting every face's vertices onto the (x,z) plane and
running a standard ray-casting point-in-polygon test against the tile
centre (`origin + (col+0.5, row+0.5) * cell_size`, with `origin`/`cell_size`
derived from the model's own decoded vertex bounding box divided by the
grid's width/height, generalising the earlier pass's hard-coded map24_23
numbers). Faces are pre-bucketed by their own 2D bounding box so each tile
only tests the handful of faces that could plausibly cover it. Where
several faces stack at one (x,z) (a ramp, or ground under a raised deck),
the flattest candidate (vertex y-range < 0.2) with the highest average y is
kept, so a vertical decorative billboard (crossed-plane grass props, see
the field-level pass above) does not override the real ground surface
underneath it; if no flat candidate covers a tile at all, the least-flat
candidate is used as a fallback rather than leaving the tile unclassified.
This reached full coverage (0/1024 uncovered tiles) on `map19_19` and
`map23_11`, and 822/1024 on `winter0701_01_00` (202 tiles have no face at
all under their centre, believable for a winter-town map with a smaller
outdoor footprint than the other two). Per-tile texture matrices and a
false-colour overlay (base colour = texture-class hash, corner inset =
byte[3] value) were written to `build/assets/maps/<name>_tex_matrix.txt`
and `<name>_tex_vs_byte3_overlay.png` (gitignored) for all three targets.

### byte[3] vs ground texture: REFUTED

Cross-tabulating byte[3] against texture class shows byte[3]=1 is **not**
confined to grass in any of the three samples, and in one sample the
correlation runs backwards:

`map19_19` (byte[3] nonzero % per texture, n=tile count):

| texture | n | byte3 nonzero % |
|---|---:|---:|
| mizu_sita2 (riverbed) | 604 | 68% |
| ki02ax (tree bark) | 233 | 69% |
| **GRASS** | 95 | 94% |
| hana01 (flower prop) | 65 | 85% |
| gake1 (cliff face) | 17 | 65% |
| yamagake01 (cliff) | 5 | 100% |

`map23_11` (byte3 in {0,1,2}, same layout):

| texture | n | byte3=1 % | byte3=2 % |
|---|---:|---:|---:|
| gake1 (cliff face) | 575 | 98% | 2% |
| gake01a7 (cliff) | 125 | 100% | 0% |
| gake_futa (cliff cap) | 111 | 86% | 1% |
| **GRASS** | 66 | 100% | 0% |
| kawa_soko (riverbed) | 56 | 100% | 0% |
| ki02dx (tree bark) | 56 | 57% | 43% |

`winter0701_01_00` (byte3 in {0,1,2,3}):

| texture | n | byte3=0 % | byte3=2 % | byte3=3 % |
|---|---:|---:|---:|---:|
| **GRASS** | 397 | 86% | 10% | 4% |
| w_gake (cliff wall) | 215 | 16% | 75% | 5% |
| w_yuka (deck/floor) | 87 | 24% | 47% | 2% |
| w_gake_001 (cliff) | 50 | 20% | 72% | 8% |

In `map19_19` and `map23_11`, byte[3]=1 is essentially universal (65-100%)
across every ground texture present, cliff and riverbed and tree-bark
included, not specifically elevated on grass. In `winter0701_01_00` the
pattern inverts: GRASS is mostly byte3=0 (86%) while the cliff-wall and
deck textures carry the nonzero values instead. No single byte[3] value is
fixed-on-grass/zero-elsewhere in any of the three samples, which is the
confirmation criterion this pass set out to test -- **byte[3] is refuted as
a grass/encounter-specific lane**. Its real character (from this pass and
the earlier field-level one) reads as a generic "this is open, non-building
terrain" or zone/route marker layered over whatever texture happens to be
underfoot, not a per-texture-type code.

### byte[1] vs ledge texture / byte[2] height step: INCONCLUSIVE, sample too sparse

`map19_19` and `map23_11` both have byte[1]=0 on every one of their 1024
tiles (matches the field-level pass's histogram: byte[1] is nonzero in
only 68/572 `WB` files, and neither of these two happened to be among
them). `winter0701_01_00` has 32/1024 nonzero cells, **all value 1** (no
2-5 present) -- of these, 21/32 sit under cliff/support-adjacent textures
(`w_gake*`, `w_sasae`) and 8/32 under GRASS, a directional lean toward
cliff/edge terrain but on too small and too textureless-varied (single
value) a sample to confirm the ledge hypothesis. Checking byte[2] at each
of these 32 tiles against its four neighbours for a one-way, one-step
height drop (the signature the mission asked to test) found no such
pattern: byte[2] here ranges up into the 80-255 area (e.g. 132, 221, 153,
96, 3, 255) and changes by large, non-monotonic amounts between neighbours
in every direction rather than stepping by exactly 1 toward one side --
consistent with the field-level pass's already-documented reading that
byte[2] is "overloaded" (a real terrain-step id on ordinary tiles, a
different per-object/outlier code on others), not usable as a clean height
reference here. **Verdict: inconclusive** -- this pass's three targets
happen to carry only byte[1]=1 (never the 2-5 values seen elsewhere, e.g.
`m_siten02_00_00`'s per-side 2/4/5 edge coding documented in the
field-level pass), so no directional encoding for byte[1] could be
determined from ground-truth texture or height data this pass.

### Files touched

`docs/ASSETS.md`: this section. No changes to `tools/assets/map_grid.py`
(byte[3] was refuted rather than confirmed, so the mission's conditional
"add a legend to `--attrs`" step does not apply; its docstring's existing
MEDIUM-confidence byte[1]/byte[3] entries are not revised by this pass,
since this is a texture cross-check on 3 files, not a broader re-scan).

### Remaining gaps

- Water, stairs, and doors/warps still have no candidate lane (unchanged
  from the field-level pass).
- byte[1]'s directional edge-coding hypothesis needs a sample with actual
  2-5 values and known cliff/ledge geometry (e.g. `m_siten02_00_00` or
  `leagin02_00_01` from the field-level pass) cross-checked against this
  pass's texture/height method; the three targets chosen here for their
  byte[3] variety happened not to have that.
- byte[2]'s overloaded behaviour (small quantized steps on most tiles,
  large outlier values on others) is confirmed again here but still not
  separated into its two components.
- The point-in-polygon ground-face rule leaves `winter0701_01_00` with
  202/1024 tiles uncovered (no face under the tile centre at all); not
  investigated further since the byte[3] refutation was already clear on
  the other 822 tiles.

## Asset lane pass: `a/0/0/3` and `a/0/6/6` container framing (event/script-table candidates), fixed-stride hypothesis refuted

Follow-up to the "Map attribute hunt" pass above, which located these two
NARCs (472 and 601 sub-files, variable-length, bytecode-shaped opening
bytes) but did not parse them. This pass parses both down to a
byte-identical repack in `tools/assets/events.py` (new). Method: sizes and
first bytes of 20 files each per the mission's step 1, then an
archive-wide (not just-sampled) check of every candidate header field
against every one of the 472 / 601 sub-files, since the small samples in
the earlier pass were not enough to separate a real field from
coincidence.

### Fixed-stride hypothesis: refuted for both archives

Step 1 asked for a stride that divides every section into fields with
sane ranges. No such stride exists for either archive: `a/0/0/3`'s body
size (`file_size - 16`) has no common divisor across the 472 files that
also lines up with a real record boundary, and `a/0/6/6`'s per-group
sizes (see below) vary too widely within a single file for a fixed
stride to fit. Both are genuinely variable-length, index-table-plus-blobs
containers, not fixed-stride record arrays -- the same conclusion the
"Map attribute hunt" pass reached by inspection, now confirmed
archive-wide.

### `a/0/0/3` (472 sub-files): HIGH confidence framing

16-byte outer header -- `u16 tag` (always 1, 472/472), `u16 count` (N,
the record count, 1-481), `u32 body_size` (== file size - 16, 472/472),
`u32 reserved` (always 0, 472/472), `u32 header_len` (always 16,
self-referencing like the `a/0/0/8` wrapper's own size-table convention).

Body: a `u32 body_size` duplicate (matches the header field, 472/472),
then N 8-byte index entries `(u32 record_offset, u32 field_x)`.
`record_offset` is HIGH confidence: entry 0 always equals `4 + 8*N`
(right past the table, 472/472), and the full N-entry sequence is
strictly increasing with no duplicates in every one of the 472 files
(7861 entries total) -- not a coincidence at these N (up to 481).
`field_x` is a real, verified-paired field but its semantics are open:
checked and ruled out as record length (0/7861 pairs satisfy
`field_x == next_offset - this_offset`) and as a constant type tag
(only 163/472 files have every `field_x` share the same top 3 bytes);
its high-24-bit histogram is dominated by `0xE000` (5576/7861) and
`0x000000` (1096/7861) with a ~40-value tail, consistent with a packed
type+pointer/type+small-int word from the record's own bytecode but not
decoded here. Records themselves (`record_offset[k]..record_offset[k+1]`,
or `body_size` for the last) are variable-length, bytecode-shaped payload
-- no recognisable fixed sub-stride found inside them, not decoded past
byte-exact extraction.

### `a/0/6/6` (601 sub-files): HIGH confidence framing

Outer header: `u32 group_count` G, one of `{1, 2, 3, 5, 8}` archive-wide
(574 files at G=1, 23 at G=2, 2 at G=5, 1 at G=3, 1 at G=8), followed by
G blocks of 14 `u32` words. The 14 words in each block are IDENTICAL in
every one of 641 groups checked across all 601 files -- so there are only
G real distinct values, each stored 14 times over; why 14 is an open
question, not explained by anything found this pass. `header_len =
4 + 56*G`, and `group_value[0] == header_len` on 601/601 files (the same
self-referencing convention as `a/0/0/3` and the `a/0/0/8` wrapper). Group
data spans `group_value[k]..group_value[k+1]` (or file end for the last
group); the 20 most common group sizes archive-wide each cover well under
10% of the 641 total groups, so groups are genuinely variable-length, not
a per-tile array.

G's small, discrete range (never anything but 1/2/3/5/8) reads more like a
per-resource count of language-variant blocks than a per-map object list
-- consistent with this NARC's existing inventory category guess ("text
banks", see the inventory table above) -- which argues against `a/0/6/6`
being a door/warp/event table, contrary to this NARC's flagging in the
earlier pass.

### Doors/warps: still not confirmed

Neither archive's sub-file count (472, 601) equals `a/0/0/8`'s 649 map
files, and this ROM has no usable BTNF names outside one unrelated NARC
(`a/2/3/2`, see "BTNF name table results" above) and no separate zone/map
index table has been found anywhere in this archive set. Without an
index alignment to a specific `a/0/0/8` map file, the walkable-tile
cross-check against `tools/assets/map_grid.py` (mission step 3) cannot be
performed honestly -- reported as a real gap, not attempted with a guessed
alignment. `a/0/0/3` is the stronger of the two candidates for door/warp/
NPC/trigger data (bytecode-shaped variable records, no language-count
pattern; `a/0/6/6`'s language-like group counts argue against it), but
which record type or `field_x` value within `a/0/0/3` specifically means
door/warp is still open.

### `tools/assets/events.py` (new)

`--list [--archive {0003,0666,both}]`: per-file record/group counts.
`--dump {0003,0666} INDEX`: typed record/group dump for one sub-file.
`--verify [--archive {0003,0666,both}]`: re-packs every sub-file from its
parsed structure and diffs against the original byte-for-byte -- the
acceptance bar for the framing above. Result: **472/472** (`a/0/0/3`) and
**601/601** (`a/0/6/6`) round-trip exactly, 0 parse errors, 0 mismatches.

### Remaining gaps

- `field_x` in `a/0/0/3`'s index entries: real field, semantics open (see
  above).
- The 14-fold redundancy in `a/0/6/6`'s group offset table is unexplained.
- `a/0/6/6`'s language-bank reading is a plausible alternative to
  "event/script table", not confirmed against actual text content this
  pass (no string decoder was run over its group payloads).
- No index alignment between either archive and `a/0/0/8`'s 649 maps was
  found, so the specific door/warp record type remains unidentified; this
  is flagged as a real gap requiring a lookup table (or code cross-
  reference) this pass did not have, not a guess.
- Neither archive's variable-length record/group payload bytes are
  decoded past byte-exact extraction (both read as bytecode-shaped, not
  struct-shaped, so a further pass would need an opcode table, not a
  stride).

## Zone table hunt: no flat per-zone index array confirmed; one real code-level lead found instead (`tools/assets/zones.py`, new)

Follow-up mission: the previous pass found no zone-to-map index table in
any NARC. Since the game must resolve, per zone, a map-model file (index
into `a/0/0/8`'s 649), a script file (index into `a/0/0/3`'s 472), a text
bank, an encounter table, music and neighbours somehow, this pass widened
the search to the ARM9 data segment and overlays, then to every NARC's raw
sub-file-size shape, then tried to cross-reference the best candidates.
Result: still no confirmed table, but a genuine, code-grounded lead was
found that the previous pass did not have.

### (1) ARM9 + overlays: negative, after one false positive ruled out

`extract/arm9_dec.bin` (0x666A0 bytes) and all 17 `extract/overlays_dec/
*.bin` files were reshaped at every stride from 16 to 64 (step 2, natural
u16 alignment) and scanned for a pair of u16 lanes -- one staying below
649 (the map-file count), another below 472 (the script-file count) --
held over >=100 consecutive records with real variation (>=30% of lane 1
non-zero, >=20% of lane 2 non-zero, >=10/>=5 distinct values respectively,
to reject all-zero-padding artifacts that satisfy a bare "< N" bound by
default). With those guards, the scan came back with a single hit:
`y9_0203.bin`, stride 60, 149 records at byte offset 271*60. Hand-inspected
byte-for-byte (dumped in `docs/ASSETS.md`'s working notes, not reproduced
here): the bytes do NOT actually repeat with period 60 -- adjacent
"records" have completely different shapes and lengths, so the stride-60
mask match was numeric coincidence over small, mostly-zero counters
(u32 fields like 0/1/2 dominate this NARC's actual variable-length
event/UI-object data). No genuine fixed-stride zone array exists in ARM9
or any overlay under this method.

### (2) NARC-wide survey: 6 fixed-size-sub-file candidates, all ruled out or already-known

Every NARC in `extract/data/` was checked for a sub-file count in the
100-1000 range where one sub-file size dominates and falls in [16, 64]
bytes -- i.e. treating each sub-file itself as one record, since a NARC's
own file table is already an index. 6 candidates:

| NARC | sub-files | size | count at that size |
|---|---:|---:|---:|
| `a/0/1/6` | 669 | 60 | 667 |
| `a/0/2/1` | 560 | 36 | 560 |
| `a/0/2/4` | 627 | 36 | 627 |
| `a/0/9/2` | 616 | 20 | 615 |
| `a/1/0/8` | 282 | 28 | 281 |
| `a/1/6/9` | 951 | 16 | 951 |
| `a/2/1/4` | 1000 | 16 | 1000 |

`a/0/9/2` is trdata, the already-confirmed trainer data table (see
"Trainer data table located by reference" above) -- its presence here is
a sanity check that the method reliably re-finds a known real record
array (it does: 20-byte records, 615/616 uniform).

The other 5, per-lane u16 histograms (min/max/distinct count) via
`tools/assets/zones.py --list`:

- **`a/1/0/8`** (28-byte records): no lane satisfies both the <649 and
  <472 bound. Ruled out outright.
- **`a/0/1/6`** (60-byte records): several lanes numerically satisfy both
  bounds, but the records themselves fall in groups of 3 sharing a
  near-identical header with only a small incrementing sub-index (bytes
  4-9 constant within a triple, byte-10 stepping 01/02/03), and a handful
  of this archive's sub-files carry non-uniform magics (`dddd`, `2AkV`)
  rather than the dominant 60-byte shape -- not a flat zone-record array.
- **`a/0/2/1`** (36-byte records): every record ends in the ASCII tag
  `"SS"` (bytes `53 53`), consistent with a sound/SE test-tag table, not
  zone data.
- **`a/0/2/4`** (36-byte records): every record shares a constant 8-byte
  header (`1f 08 00 01 00 04 00 ..`) with only a small incrementing tail
  counter -- an index/pointer table of some kind, not per-zone data.
- **`a/1/6/9`** (951 records) and **`a/2/1/4`** (1000 records): both are
  8 x u16 records with the identical shape, and both have a field 0 that
  increases in tight groups of 3 (e.g. `a/2/1/4`: 1, 4, 7, then a jump to
  152, 155, 158, then 252, 255, 258, ...) -- a pattern much more
  consistent with a per-icon/frame placement table (a world-map icon list
  is the current guess) than an injective per-zone id. Neither has an
  independent lane that is simultaneously bounded <649 (map count) *and*
  a different independent lane bounded <472 (script count): the field
  that stays under 649 in both archives (max 645 / max 488) has no
  companion field that stays under 472 (the next-tightest fields max out
  at 542-556 in `a/2/1/4`, 466-488 in `a/1/6/9`), so neither is a
  map-index/script-index pair by this test.

(41 further hits from a looser "few sub-files, single blob divisible by a
stride 16-64" pass were all NCLR/NCGR/graphics-dominant NARCs --
`soundstatus.narc`, `a/0/1/2`, `a/0/3/7`, `a/0/5/0`, `a/0/6/5`, `a/0/6/8`,
`a/1/1/0`, `a/1/2/0`, `a/1/6/4`, `a/1/8/8`, `a/2/0/6`, `a/2/1/1`,
`a/2/1/7`, `a/2/1/8`, `a/2/3/4` -- arithmetic coincidence on palette/tile
data, not tables, not reported further.)

### (3) The real lead: `"zonedata.c"` in the ARM9 debug-string pool

A source-file debug string, `"zonedata.c"`, is embedded in ARM9's
string-literal region at address `0x020A72B0` (alongside other real
source filenames from the same table -- `net_save.c`, `ica_anim.c`,
`game_event.c`, `game_data.c`, `btl_setup.c`, `field_status.c`, `mcss.c`).
Its address is referenced as a pooled literal from the function at ARM9
`0x020139B0` (`asm/arm9/src/005_020132F4.s`, not yet in `src/matched` or
`src/pending`).

That function, read from the disassembly:

- guards on a global singleton pointer at `0x02146264`; if it's `NULL`,
  it heap-allocates 0x4C (76) bytes via `func_02030734` (a generic
  "AllocFromHeap(heap, size, .., filename, line)"-shaped wrapper,
  confirmed by its call signature elsewhere in this ROM), passing
  `"zonedata.c"` and line `0x60` (96) as the debug filename/line -- i.e.
  this 76-byte struct is genuinely the runtime object the original
  source's `zonedata.c` allocates,
- then fills 7 scalar fields on it: offsets `0x34` (u16, a literal
  constant `0x1AB` = 427), `0x38`, `0x3c`, `0x40` (u16), `0x42` (u8),
  `0x43` (u8), `0x44`, all but the first via a generic const-lookup
  helper `func_0204A298(category, sub_id, ..)` called with
  `(category, sub_id)` pairs `(0x51, 0xd)`, `(0x52, 1)`, `(0x95, 0)`.

This confirms a real `ZoneData` subsystem exists in the original source
and pins down exactly where its runtime state lives in ARM9 -- a
stronger, code-grounded result than "no table found anywhere". But the
76-byte manager struct holds only small scalar counts/config values (not
a raw array), and `func_0204A298`'s own data source -- wherever those
counts ultimately come from -- was not traced further this pass. If the
actual per-zone record array exists as a flat table, it is reached from
further inside this call chain (most likely inside `func_0204A298` or
whatever `func_02048F4C` -- called from `func_0204A298` -- loads), not
from the manager struct directly.

### `tools/assets/zones.py` (new)

`--list`: re-derives the NARC survey in (2) above (sub-file extraction,
per-lane u16 min/max/distinct via `struct`, no numpy dependency) and
prints it plus the code lead from (3), so a future pass has the exact
numbers without re-deriving them. No `--dump`/typed-record support is
offered: no table was confirmed this pass, so there is nothing real to
type.

### Remaining gaps

- The zone table itself (if it is a flat array) is still not located.
- `func_0204A298` and `func_02048F4C` (the generic const-lookup/loader
  pair used by the ZoneData manager init) are not traced to their
  underlying data source -- that is the concrete next step for whoever
  picks this up: follow `func_0204A298`'s `(category, sub_id)` dispatch
  to see what table or file it ultimately reads.
- `a/1/6/9` and `a/2/1/4`'s shared 8 x u16, grouped-by-3 record shape is
  unidentified (world-map icon placement is a guess, not verified against
  any rendered map).
- The cross-reference validation this mission asked for (house pairing
  against `a/0/0/8`'s walkable grids, script-lane agreement with
  `a/0/0/3`) was not run, because no candidate passed the prerequisite
  lane-range test to be worth cross-checking.

## Zone header table located by code: `a/0/1/2` sub-file 0, 427 records of 48 bytes

Follow-up to "Zone table hunt" above, which ended with two open questions:
where `func_0204A298` gets its data, and whether a flat per-zone array
exists at all. Both are now answered from code, not from a stride scan.
This pass decompiled the `zonedata.c` constructor and its neighbours; the
`match.py` verdicts are in `layout/matched/arm9/pkt_02013528.json`,
`pkt_02013BDC.json` and `pkt_02013E90.json`, with the two evidence-starved
functions in `src/pending/`.

### The archive-id table, which is what unlocked everything else

`func_02048DDC`, the handle binder under both `func_0204A298` and
`func_020490F4`, indexes a 235-entry `char *` table by the caller's archive
id. The table lives at ARM9 `0x020A6C58` and is installed by
`func_02048CEC(0x020A6C58, 0xeb)` from `0x020054FA` (0xeb = 235, and the
ARM9 string block holds exactly 235 `a/x/y/z` names, `0x020A6500` to
`0x020A6C50`). The mapping turns out to be the identity in decimal: id N
is `a/` plus N's three decimal digits, so id 12 is `a/0/1/2`, id 81 is
`a/0/8/1`, id 82 is `a/0/8/2`, id 149 is `a/1/4/9`. Note the address base:
`extract/arm9_dec.bin` loads at `0x02004000`, not `0x02000000`, which is
why an earlier scan for a pointer array "found nothing" near `0x020a2500`.

### The table

`func_020139B0` (ARM9 `0x020139B0`, the function that passes `"zonedata.c"`
and line 0x60 to the allocator) opens a persistent handle to archive id
0x0c, i.e. **`a/0/1/2`**, and stores it at manager +0x00.
`sub_02013AD0` then reads records out of that handle with
`func_0204944C(handle, member = 0, offset = 0x30 * id, size = 0x30, dst)`.
`func_0204944C` is a random-access partial read: it seeks the FAT entry of
`member`, then reads `size` bytes at `offset` inside that sub-file.

So the zone header table is **sub-file 0 of `a/0/1/2`, record stride 0x30
(48 bytes)**. `a/0/1/2` has exactly one sub-file, 20496 bytes, and
20496 / 48 = **427** records with no remainder. Independently,
`func_020139B0` seeds the cache tag at manager +0x34 with 0x1ab = 427,
one past the last id, which is only a never-matches sentinel if the table
really has 427 entries. Code and data agree.

This is why every stride scan missed it: the table is a NARC with a single
sub-file, so the "sub-file count in 100-1000, one dominant size" survey saw
a 1-file archive, and the loose raw-blob pass filed `a/0/1/2` under
graphics by arithmetic coincidence.

### Lane bounds

    records 427   stride 48   bytes 20496
      +0x06: min 0   max 852  distinct 427
      +0x08: min 1   max 853  distinct 427
      +0x0a: min 2   max 468  distinct 427
      +0x16: min 0   max 426  distinct 427

The script lane check passes: `+0x0a` is injective over all 427 records and
its maximum, **468**, is below `a/0/0/3`'s **472** sub-files. `+0x16` is a
bijection onto 0..426, i.e. a permutation of the zone ids themselves.
`+0x06` and `+0x08` are always consecutive (`+0x08 == +0x06 + 1` on
427/427 records) and together cover 0..853 = 2 * 427 exactly, so each zone
owns one aligned pair of entries in some 854-or-larger archive.

The map lane check does **not** pass, and that is a real result rather than
a miss: no lane of the record is an injective index bounded by `a/0/0/8`'s
649 map files. The zone record does not name a map model directly. The
nearest candidates are `+0x02` (max 273, 104 distinct) and `+0x04` (max
254, 238 distinct); `a/0/0/2` has 288 sub-files and `a/0/0/9` has 255, so
both fit numerically, but neither is attested by code from this range and
neither should be written down as fact. `func_02013E90` compares `+0x04`
between two zones as an equivalence test, which reads as a grouping key,
not an index.

### Field map, every entry attested by an accessor

Offsets are from the record start (manager +0x04). Each row names the
function whose single load fixes the offset and width.

| offset | width | reader | note |
|---|---|---|---|
| +0x00 | u8 | `sub_02013B50` | |
| +0x01 | u8 | `sub_0201405C` | |
| +0x02 | u16 | `sub_02013B38` | |
| +0x04 | u16 | `sub_02013B44` | grouping key; `func_02013E90` treats 0 and 0xaf as one group |
| +0x06 | u16 | `sub_02013B5C` | even half of the consecutive pair |
| +0x0a | u16 | `sub_02013B68` | script lane, max 468 below 472 |
| +0x0c..+0x12 | 4 x u16 | `func_02013BDC` | one array, indexed 0..3, 0 outside |
| +0x14 | u16 | `sub_02013EC0` | |
| +0x16 | u16 | `sub_02013ECC` | bijection onto 0..426 |
| +0x18 | u16 | `sub_02013E40` | |
| +0x1a | u16 | `sub_02013E4C` bits 0..9, `sub_02013E6C` bits 10..15 | two packed lanes; `sub_02013E4C` substitutes 0x70 for 0x70/0x71 |
| +0x1c | u16 | `sub_02013C10` bits 0..5, `sub_02013BA8` bits 6..8, `sub_02013BBC` bits 9..15 | three packed lanes |
| +0x1e | u16 | `sub_02013FD8` bits 0..4, `sub_02013ED8` bits 5..9, `sub_02013C20` bit 10, `sub_02013C50` bit 12, `sub_02013C40` bit 13, `sub_02013C30` bit 14, `sub_02013C60` bit 15 | flag word |
| +0x20 | u16 | `sub_02013BD0` | |
| +0x24 | s32 | `sub_02013B74`, `sub_02013B90` | `sub_02013B74` returns it shifted left 16, i.e. int to Fx32 |
| +0x28 | s32 | same pair | |
| +0x2c | s32 | same pair | |

`+0x08` has no accessor of its own; it is fixed instead by being `+0x06 + 1`
on every record. `+0x22`, `+0x26`, `+0x2a` and `+0x2e` are zero on all 427
records, consistent with `+0x24`/`+0x28`/`+0x2c` being 32-bit.

### The manager object, and the three side tables

`func_020139B0` allocates 0x4c bytes and `func_02013A48` releases them in
the reverse order, which fixes the field map from two directions:

| offset | what |
|---|---|
| +0x00 | `a/0/1/2` handle, closed with `func_02049238` |
| +0x04..+0x33 | the cached 48-byte record |
| +0x34 | u16 cached zone id, seeded 427 |
| +0x38 | heap copy of `a/0/8/1` sub-file 13 |
| +0x3c | heap copy of `a/0/8/2` sub-file 1 |
| +0x40 | u16 entry count of +0x38 (byte size / 4) |
| +0x42 | u8 entry count of +0x3c |
| +0x43 | u8 entry count of +0x44 |
| +0x44 | heap copy of `a/1/4/9` sub-file 0 |
| +0x48, +0x49 | the two substitution gates, set by `sub_02013A80` |

`func_02013EEC`, `func_02013F2C` and `func_02013F6C` walk +0x38, +0x3c and
+0x44 as arrays of 4-byte `{ u16 key; u16 value }` entries keyed on the
zone id, so all three are sparse per-zone side tables rather than part of
the record. The data agrees on all three counts: `a/0/8/1` sub-file 13 is
104 bytes = 26 entries, `a/0/8/2` sub-file 1 is 0 bytes = 0 entries (that
loop is simply never entered in this build), `a/1/4/9` sub-file 0 is 32
bytes = 8 entries, and every key in all three is below 427.

`sub_02013A94` remaps the incoming zone id before any of this, through a
two-entry `{ u16 key; u16 value }` table at `0x020A72A8` (0x0000 to 0x01a8,
0x0126 to 0x0127), each entry gated by its own byte at manager +0x48. A
runtime-gated id substitution is the shape a version- or event-exclusive
area takes, so those three constants are content and must not be assumed
to hold for White.

### Remaining gaps

- Which archive the `+0x06`/`+0x08` pair indexes. It needs at least 854
  sub-files; `a/0/0/7` (1431), `a/0/2/5` (1005) and `a/0/5/7` (899) are the
  only plausible sizes in the set, and no code in this range narrows it.
- The map-model link. The record has no `a/0/0/8` index, so the map is
  reached through something else (a matrix archive is the obvious guess);
  the reader that consumes `+0x02` was not found this pass.
- The meaning of the packed lanes in `+0x1a`, `+0x1c` and `+0x1e`. Their
  offsets and widths are exact, their semantics are not read.
- `sub_02013A94`'s substitution table and `func_020139B0`'s `"zonedata.c"`
  string have no attestable witness anywhere in the image, so both
  functions are byte-correct but capped at `MATCH` in `src/pending/`.

## Zone header table decoder (`tools/assets/zones.py`)

Follow-up to "Zone header table located by code" above. `tools/assets/zones.py`
was rewritten from a survey-and-code-lead stub into an actual decoder for
sub-file 0 of `a/0/1/2` (427 records, 48-byte stride, byte-exact round-trip
via `--verify`), and the mission's two open cross-checks were run against
the real archives.

### Stats (`--stats`, reproduces the table in the section above plus every
other lane)

    records 427   stride 48   bytes 20496
      field_00     min=     0 max=    20 distinct=  20 injective=False
      field_01     min=     0 max=    16 distinct=  16 injective=False
      field_02     min=     2 max=   273 distinct= 104 injective=False
      field_04     min=     0 max=   254 distinct= 238 injective=False
      field_06     min=     0 max=   852 distinct= 427 injective=True
      field_08     min=     1 max=   853 distinct= 427 injective=True
      script_id    min=     2 max=   468 distinct= 427 injective=True
      conn0        min=  1001 max=  1170 distinct=  54 injective=False
      conn1        min=  1001 max=  1170 distinct=  54 injective=False
      conn2        min=  1001 max=  1170 distinct=  54 injective=False
      conn3        min=  1001 max=  1170 distinct=  54 injective=False
      field_14     min=     0 max= 65535 distinct= 113 injective=False
      zone_perm    min=     0 max=   426 distinct= 427 injective=True
      field_18     min=     0 max=   424 distinct=  93 injective=False
      packed_1a    min=     0 max=  1140 distinct= 158 injective=False
      packed_1c    min=     0 max= 17984 distinct=  32 injective=False
      flags        min=  2112 max= 60736 distinct=  50 injective=False
      field_20     min=     0 max= 65535 distinct= 200 injective=False
      reserved_22  min=     0 max=     0 distinct=   1 injective=False
      fx_24        min=     0 max=   801 distinct=  57 injective=False
      fx_28        min=     0 max=     8 distinct=   5 injective=False
      fx_2c        min=     0 max=   758 distinct=  55 injective=False

The `conn` array (record +0x0c..+0x12) is new information from this pass:
all four slots range 1001..1170 (54 distinct values total) and 381/427
records have all four slots equal to each other. A per-zone map pointer
would not naturally take that shape; a set of four mostly-identical
directional neighbour slots would.

### The map lane: still not found, now with five more candidates ruled out

`--map-lane-check` tests every numeric candidate the mission named against
`a/0/0/8` (649 sub-files), by building the induced (zone -> a/0/0/8 index)
mapping and checking two things: does the index land in range for
(near-)all 427 records, and does any bit of the flag word (+0x1e) correlate
with the resulting file being house-prefixed vs outdoor-prefixed (the same
name-based classifier `tools/assets/map_grid.py`'s attribute-hunt pass
already validated against `pl_00_00`'s real floor plan).

    a/0/0/8 sub-files: 649
      field_06 - 0:   classified 112/427, best bit score 0.22
      field_06 - 204: classified 112/427, best bit score 0.17
      field_06 - 205: classified 109/427, best bit score 0.16
      field_06 - 206: classified 112/427, best bit score 0.19
      field_08 - 0:   classified 109/427, best bit score 0.23
      conn0..conn3 - 1001: classified 426-427/427, best bit score 0.00
      field_02:       classified 384/427, best bit score 0.43 (on a 1/2 vs
                      27/382 split -- not a real signal, just 2 records)
      field_04:       classified 321/427, best bit score 0.20

None of these clears a real threshold: the highest non-degenerate score is
0.23, on barely a quarter of the table classified. Concretely ruled out
this pass, on top of `field_02`/`field_04` (already ruled out above):

- **field_06 / field_08, any offset**: bounded check alone kills this
  before the correlation test matters -- raw `field_06` is `< 649` on only
  325/427 records and `field_08` on only 324/427 (offsets 204/205/206, the
  854-vs-649 gap, do not fix this: at most 112/427 records even end up
  classifiable, because the rest still fall outside 0..648). A real map
  index has to resolve for (close to) all 427 zones, not three-quarters at
  best.
- **conn0..conn3 minus 1001**: bounded for 426-427/427 records, but bit
  correlation is exactly 0.00 on every flag bit -- the house-rate among
  "bit set" zones equals the house-rate among "bit clear" zones bit for
  bit. Combined with the structural point above (one indexed accessor
  selecting 1-of-4, and 381/427 records having all four slots identical),
  this reads as a directional neighbour-zone array, not a map pointer.
- **The three side tables** (`a/0/8/1` sub-file 13, `a/0/8/2` sub-file 1,
  `a/1/4/9` sub-file 0): read directly, their value ranges are 0..12 (26
  entries), empty, and 0..1 (8 entries) -- none can index a 649-file
  archive regardless of what they key on. Ruled out on value range alone,
  no correlation test needed.

So the map lane remains unresolved: every numeric candidate in the 48-byte
record and every side table named in the mission is now ruled out, either
by range or by a null correlation with the flag word. If the map link
exists, it is reached some other way (a matrix/lookup archive keyed by one
of the ruled-out lanes' pre-substitution id, or by an id this record
doesn't carry at all) -- not read here.

### The script lane: passes

`--script-lane-check` parses every one of the 427 `script_id` values
against `a/0/0/3` with `tools/assets/events.parse_0003`: **427/427 parse
OK**, 0 failures. Combined with `script_id` being injective (see stats
above) and its max (468) sitting below `a/0/0/3`'s 472 sub-files, this is a
clean confirmation, not just a bounds coincidence.

### Round-trip

`--verify`: **427/427 records round-trip, 20496/20496 bytes byte-identical**.

### NARC survey gap fix (`--survey`)

The original survey (100-1000 sub-files, one dominant sub-file size) could
not find `a/0/1/2` structurally: it has exactly one sub-file, so it read as
a 1-file archive, not a 100-1000-entry table. `--survey` re-scans every
archive under `extract/data/a` (235 files, matching the archive-id table)
and also treats a single-sub-file archive's own blob as a candidate record
array, checking every stride in [16, 64] for a record count in [100, 1000].
This re-finds `a/0/1/2` at stride 48 (and several other divisors of 20496,
which is expected noise -- 48 is the one code confirms) alongside three
other single-sub-file archives with a plausible divisor (`a/0/3/7`,
`a/0/8/6`, `a/2/1/1`), none of which this pass identifies further.
`extract/arm9_dec.bin` loads at ARM9 address `0x02004000`, not
`0x02000000`; the survey output states this so a future file-offset-to-
address conversion does not repeat the earlier miss near `0x020a2500`.

### Remaining gaps

- The map-model link is still open; see above. Every lane and every named
  side table is now a ruled-out candidate, not an untested one.
- `conn0..conn3`'s actual semantics (neighbour zones? something else
  entirely?) are not decoded past "an indexed array of four, mostly
  constant across the four slots, range 1001..1170" -- 1001..1170 does not
  land inside any zone-id range (0..426) either, so "neighbour zone id" is
  a structural guess from the accessor shape, not a confirmed reading.
- The packed lanes at +0x1a, +0x1c and the flag word at +0x1e are split
  into bit ranges by offset/width only; no bit's semantics (beyond "not
  correlated with indoor/outdoor" for all 16 flag bits, shown above) are
  decoded.

## Matrix archive hypothesis: no NARC in the image is a grid-of-map-ids table

Follow-up to the map-lane question above, testing one specific structural
hypothesis: that the `conn` array (record +0x0c..+0x12, four u16 lanes,
range 1001..1170) selects a "matrix" sub-file, a small header plus a grid
of u16 `a/0/0/8` ids, rather than indexing a map directly.

### The candidate set D

Subtracting each `conn` lane's observed minimum (1001) gives a distinct
value set D of size **69**, range **0..169** (so a matching archive needs
at least 170 sub-files, one per possible matrix id). D is not contiguous
(gaps at, for example, 1..12 and 84..105 and 107..168), which is already
a mild structural warning: a real matrix table indexed 0..169 would more
plausibly use every id in that range, or close to it, than skip most of
the top half.

### Method: an exhaustive struct scan, not a guess at one archive

Every NARC in `build/assets/inventory.json` (237 archives) was scanned
sub-file by sub-file, three ways, all stdlib-only one-off scripts driving
`tools/assets/narc.py`'s `Narc.read`:

1. **Single grid**: header length in {0,4,8,12,16,20,24}, then a
   `u16 width, u16 height` pair, then `width*height` u16 cells, each
   either `< 649` or the `0xFFFF` empty sentinel, cell count >= 4,
   dimensions in [1,64], total byte length matching exactly, and real
   value variety (not one constant repeated).
2. **Dual grid** (the mission's fallback: ids paired with a second grid
   of height/texture codes): same shape, immediately followed by a
   second `width*height` u16 grid with values `< 4096`.
3. **Count-header grid**: a single u16 or u32 cell count (no separate
   width/height) followed by that many u16 cells under the same `< 649`
   bound, rejecting monotonic 0,1,2,3,... runs (a counting table, not an
   id list).

Result: **no archive passes at a fraction that would make it "the"
matrix table.** The handful of archives that pass at all are false
positives from the permissiveness of "some small numbers under 649",
confirmed by inspection, not just by score:

- `a/0/0/9` (255 sub-files, close to but comfortably above the 170
  floor): 43/255 pass the dual-grid variant, but reading the actual
  bytes (sub-file 1, 12 bytes: `00000000 01000100 6c000000`) shows the
  "second grid" is just the zero upper half-word of a plain `u32` value
  stored right after a `{count=1,count=1}` pair, not a second grid at
  all -- an artifact of interpreting an int as two u16s.
- `a/2/1/5` (315 sub-files): 50/315 pass the dual-grid variant at one
  fixed shape (5x6), and 157/315 pass the count-header variant. Reading
  sub-file 1 (136 bytes) shows a literal counting sequence, tag byte
  `0x02`, count `0x0042` (66), then `0001 0002 0003 ... 0042` -- i.e. a
  sequential index list, not map ids; happens to satisfy "< 649" because
  it counts to 66.
- `a/1/6/8`, `a/1/2/3`, `a/0/1/8`, `a/0/1/9`, `a/0/5/7`: all pass the
  count-header variant on a large minority of sub-files (3.6%-41%), all
  in archives `docs/ASSETS.md`'s survey already category-guesses as text
  or script-table archives; the same "small numbers under 649" looseness
  applies (dialogue/script byte codes are small integers too).

None of these five clears anywhere near full-archive coverage, and none
survives a look at the actual bytes. The scan above reads every sub-file
raw (`Narc.read`, no decompression), so the two archives whose sub-file
count sits closest to the 170 floor were checked a second time, this
time decompressing first with `narc.try_decompress`, since a compressed
grid would not have shown up in the raw scan at all:

- `a/0/8/3` (172 sub-files, all uncompressed per its inventory
  histogram): 99-4132 bytes with no width/height pair that reproduces
  their size, consistent with its existing "sprite" category guess.
- `a/2/2/6` (174 sub-files, **all** LZ11-compressed): every sub-file
  decompresses to a fixed 131072 bytes = exactly 256x256 u16 cells with
  no header at all. That size match is real, but the content is not
  map ids: sub-file 0 is a single constant value (0x8000) repeated
  65536 times, and every other sample checked (sub-files 20, 40, 60, 80,
  100, 120, 140, 160) has values in the tens of thousands (up to 65535),
  hundreds to thousands of distinct values per sub-file -- far outside
  the 0..648 range a map-model index needs, and the wrong shape besides
  (a per-zone map link needs one id or a handful, not a dense 65536-cell
  buffer). This reads as tile/screen graphics data (an NSCR-shaped
  256x256 background layer, size-consistent with a VRAM-sized tilemap),
  not a map-id matrix; ruled out on content, not just on size.

### Conclusion: hypothesis not confirmed, step 3/4 not run

No NARC in the extracted image contains a sub-file shaped like "small
header + u16 grid of `a/0/0/8` ids" at anywhere close to the 170-sub-file
floor D requires, under a width/height header, a count header, or a
dual-grid variant. Without a surviving candidate there is nothing to
validate against the indoor/outdoor split, so the mission's step 3 (the
ten-indoor/ten-outdoor grid-shape check) and step 4 (`tools/assets/matrix.py`,
the `zones.py --list` extension) were not run -- both are conditioned on
a candidate this pass did not find.

This adds to, rather than replaces, the map-lane conclusion above: the
`conn` array is still not shown to be a map pointer by any test run
against it (direct-index correlation, here structural grid-archive
search), and the map-model link remains open. If a matrix archive
exists, its cells are not plain little-endian u16 `a/0/0/8` ids under a
`{width,height}` or bare-count header in any NARC this pass could read --
either the encoding is different (a stride other than 2 bytes, a
non-linear cell order) or the link does not take this shape at all.

One caveat: the scan reads sub-files raw and only decompresses the two
archives closest to the 170-sub-file floor (above). Most other NARCs are
mostly-uncompressed already (`none` dominates every compression
histogram checked), but a handful of individually-compressed sub-files
inside otherwise-uncompressed archives (for example the 3-6 LZ77/LZ11/
Huffman/RLE sub-files noted in `a/1/2/5`, `a/1/6/8`, `a/2/1/5` above)
were scanned compressed and would read as "not a grid" even if they hold
one -- not a live concern for "the" matrix table (which needs all ~170
cells consistent, not 3-6 of them), but worth naming so a future pass
does not assume full compressed coverage from this one.

## Zone to map model SOLVED: record +0x04 is a matrix id into `a/0/0/9`, whose cells are u32 `a/0/0/8` indices

Follow-up to "Matrix archive hypothesis: no NARC in the image is a
grid-of-map-ids table" above, which ruled the hypothesis out. The hypothesis
was right and the scan was wrong: the matrix archive is `a/0/0/9` and its
cells are **u32**, not u16, which is exactly the one stride the previous
pass's exhaustive scan did not try. This pass found the archive from the
game's own code, decompiled the whole path to `EXACT`, and then confirmed
the reading against the data.

### The path, one function at a time

```
zone id
  -> sub_02013B44(zone id)        arm9, reads zone record +0x04   = matrix id
  -> func_02159B94(obj, matrix id, zone id, heap)    ov010
       -> func_02048F60(9, matrix id, heap)          arm9  = load a/0/0/9 sub-file
       -> func_02159D04(obj, file, matrix id, zone id)      = decode
  -> obj's u32 cell grid at +0x71C                   = a/0/0/8 sub-file indices
```

`func_0215AE8C` (ov010) is the call site that makes the link concrete: it
takes the current zone id, calls `sub_02013B44` on it, and passes the result
straight into `func_02159B94` as the member to load, with the zone id itself
alongside. `func_02185B48`/`func_02185B54` is the second call site with the
same shape.

`func_02048F60(archive_id, member, heap)` is the arm9 "load one whole
sub-file into a heap block" entry point, the defaulting wrapper over
`func_02048D54`; `func_02048DDC` inside it resolves archive id 9 through the
same 235-entry name table at `0x020A6C58` that gave `a/0/1/2` for id 12, so
id 9 is `a/0/0/9`. Verdicts for this pass are in
`layout/matched/arm9/pkt_02048F4C.json` and
`layout/matched/ov010/pkt_02159B94.json`.

This also answers the previous pass's "the record has no `a/0/0/8` index":
correct, and it never did. `+0x04` is one level of indirection away, which
is why the direct-index correlation test scored 0.20 on it. The same pass's
reading of `func_02013E90` ("compares +0x04 between two zones as an
equivalence test, which reads as a grouping key") was right for the wrong
reason: two zones with the same `+0x04` are two zones on the same matrix,
which is precisely the test a seamless zone transition needs.

### The `a/0/0/9` record layout, as `func_02159D04` reads it

| offset | width | meaning |
|---|---|---|
| +0x00 | u16 | mode; only `ldrh` is used, the upper half is never read |
| +0x02 | u16 | unread |
| +0x04 | u16 | width |
| +0x06 | u16 | height |
| +0x08 | u32 x width*height | block 1: `a/0/0/8` sub-file index per cell, `0xFFFFFFFF` = empty |
| +0x08 + 4*w*h | u32 x width*height | block 2, **only when mode == 1**: zone id per cell |

`func_02159D04` copies block 1 verbatim into the runtime matrix object's
u32 grid at +0x71C and narrows block 2 cell by cell into the u16 grid at
+0x14. When mode is not 1 there is no block 2 and the whole u16 grid is
filled with the caller's single zone id instead (`func_02082A48(zone_id,
grid, 0x708)`), so mode is the "this matrix spans several zones" flag.
Both grids are fixed 900-entry arrays, which is why 0x14 + 900 * 2 lands
exactly on 0x71C, and `func_02159C0C` refuses any width or height above 30.

The runtime object: +0x02 zone id, +0x04 matrix id, +0x08 width, +0x0a
height, +0x0c mode, +0x10 cell count, +0x14 u16 zone grid, +0x71C u32 map
grid. `func_02159BC4(obj, x, y)` reads the zone grid; `func_02159C20(obj)`
returns the map grid base.

### The checks

    matrices in a/0/0/9                 255
    shape fits the layout above         255 / 255, byte-exact, no remainder
    mode histogram                      253 x mode 0, 2 x mode 1
    max cell over every matrix          648      (a/0/0/8 has 649 sub-files)
    max per-cell zone id (mode 1)       423      (427 zones)
    zone record +0x04 over 427 zones    max 254, 238 distinct, all < 255
    matrices actually referenced        238 of 255 (17 unreferenced)

Two-line check that every map id a zone can reach is a real `a/0/0/8`
sub-file, quoted so it can be re-run:

```python
mid = [struct.unpack_from('<H', zonerec, 48 * z + 4)[0] for z in range(427)]
assert all(c == 0xFFFFFFFF or c < 649 for z in mid for c in cells(z))   # 427/427 zones, max 648
```

where `cells(z)` reads sub-file `mid[z]` of `a/0/0/9` and unpacks
`width*height` u32s from offset 8. It passes for all 427 zones: 15060 cell
lookups, every non-empty value in 0..648.

### The naming cross-check, which is what makes this conclusive

Matrix 0 is 29 x 27 with mode 1: the Unova overworld. Its cell (5, 4) holds
67 and `a/0/0/8` sub-file 67's own MDL0 model name is `map05_04`; cell
(5, 5) holds 66 and sub-file 66 is named `map05_05`. The map models name
their own matrix coordinates, and the cells resolve to exactly those files.
A numeric coincidence does not reproduce a two-dimensional coordinate
system in the model names.

Matrix 0 and matrix 175 are the only two mode-1 matrices, both 29 x 27 with
the same 229 used cells and the same maximum map id (272); 40 zones point
at matrix 0 and 23 at matrix 175. The other 253 matrices are small (186 are
1 x 1, 30 are 2 x 2), i.e. interiors, one map model per zone.

### What this closes and what it does not

Closed: the map-model link, the `a/0/0/9` record format, the matrix runtime
object layout, and the meaning of record `+0x04`.

Not closed, and corrected:

- The `conn` array at record +0x0c..+0x12 (1001..1170) is **not** map data
  and not neighbour zones either. Its indexed accessor `func_02013BDC` is
  reached only through the forwarding thunk `func_02029E64` at `0x02029E70`,
  and the 0x02029Cxx caller that consumes it feeds the value to
  `func_020289F8` as a sound argument with a 0x3c time constant beside it.
  The shape (four slots, 381/427 records with all four equal, values well
  above any zone id) reads as per-time-of-day BGM ids. This is a lead from
  one call site, not a decoded result: it is recorded here so the next pass
  starts from the sound module instead of re-testing map hypotheses.
- Which archive the `+0x06`/`+0x08` pair indexes is still open. The one new
  data point: `func_02158D2E` in ov010 reads `+0x06` and `+0x0a` in the same
  breath and writes them out as two fields of a message-source triple with a
  constant 3 between them, so `+0x06` most likely belongs with the script
  lane in a text/message archive rather than with the map data.
- No call site anywhere in the image passes a literal 8 to any archive
  entry point, so `a/0/0/8` itself is opened with a computed or table-driven
  id. The map-model loader that consumes a cell value was not traced this
  pass; `func_0218CD20` in ov021, which splices two matrices' u32 grids
  together, is where to pick that up.
- The 17 unreferenced matrices are unexplained (unused data, or reached
  from a path other than the zone record).

## Asset lane pass: matrix decoder, zone resolution, and a stitched overworld walkability map (`tools/assets/matrix.py`, `zones.py --resolve`)

Follow-up to "Zone to map model SOLVED" above: turns that reading into a
decoder (`tools/assets/matrix.py`, new), wires zone records through it
(`tools/assets/zones.py --list --resolve` / `--resolve-summary`), and
stitches the two mode-1 matrices' per-chunk walkability data into one PNG
each to check the chunk layout visually.

### Sentinel

The empty-cell sentinel in the map grid block is `0xFFFFFFFF`, the only
out-of-range (>648) value that occurs anywhere in `a/0/0/9`'s 255
sub-files. Across all 255 matrices' map grids (2056 cells total, summed
over every matrix's own `width*height`) it fills 1108/2056 cells (53.9%)
-- most matrices are mostly empty, consistent with 253 of them being
small (1x1 or 2x2) interior placeholders with only one or a few real
cells (see the earlier section's "186 are 1x1, 30 are 2x2").

### Round trip

`matrix.py --verify` re-packs every sub-file from parsed fields (header +
map grid, plus a zone grid when mode is 1) and compares byte-for-byte
against the original:

    a/0/0/9: 255/255 matrices round-trip byte-identical (0 failed)

### Zone resolution (`zones.py --resolve` / `--resolve-summary`)

`resolve_zone_maps()` in `zones.py` reads a zone record's `+0x04` matrix
id, loads that matrix, and returns the a/0/0/8 map ids it reaches: for a
mode-0 matrix every non-empty cell (mode-0 matrices are private to one
zone by construction, per the runtime object layout in the section
above), for a mode-1 matrix only the cells whose zone grid entry equals
this zone's own id (i.e. this zone's chunk(s) of the shared overworld
matrix). Over all 427 zones:

    zones resolving to exactly one map file   311 / 427
    zones resolving to several map files      115 / 427
    zones resolving to zero map files           1 / 427

The 311 are the houses/interiors the mission expected: each owns a
private mode-0 matrix pointing at one `a/0/0/8` model. The 115 are zones
whose `+0x04` selects matrix 0 or matrix 175 (the two 29x27 overworld
halves) -- a zone here is one region of open world, and its walk area can
span several map-model chunks, which is exactly why the matrix layer
exists as a separate indirection from the zone table. The one exception,
zone 300 (matrix 175), has no cell in matrix 175's zone grid carrying id
300 at all -- a zone with a matrix assigned but no physical footprint on
it, left open rather than guessed at.

### World stitch (`matrix.py --stitch`)

`--stitch N` places every chunk's walkability bitmap (`map_grid.py`'s
per-tile grid byte[4], the high-confidence walkable flag) at its matrix
cell position in one image, using the same 32x32-tile chunk size every
placed `a/0/0/8` sub-file in matrix 0/175 actually has. Run against both
mode-1 matrices:

    matrix 0:   29x27 chunks, 229 placed, 554 missing/empty/non-32x32
                stitched image: 928x864 px
                border continuity: 354 adjacent chunk-pair edges checked,
                10509/11328 edge tiles agree on walkability (92.8%)
    matrix 175: same shape, same 229/554 split, same 92.8% border
                agreement (consistent with the earlier section's note
                that matrix 0 and 175 share the same 229 used cells and
                same max map id -- two variants of the same layout, not
                two different worlds)

928x864 pixels (29*32 by 27*32, one pixel per tile), gitignored under
`build/assets/maps/matrix0_walkability.png` and
`matrix175_walkability.png`, not committed. The border-continuity number
is a quantitative stand-in for "do roads/rivers line up": it compares
every pair of adjacent placed chunks' facing edge, tile for tile, and
92.8% of edge tiles agree on walkable-vs-blocked with their neighbour
across the seam -- well above chance, and visually the stitched image
shows continuous walkable corridors and blocked-terrain blobs crossing
chunk borders rather than stopping at them, which is what a real
world grid built from independently modelled chunks should look like.
The remaining ~7% mismatch is expected, not a defect: byte[4] also marks
scenery (trees/rocks/buildings) whose footprint is chunk-local and has no
reason to align across a seam the way a road or river does.

`map_shapes.py` was checked for a per-map top-down image export and does
not have one: its only output is a textured OBJ/MTL per shape (see its
module docstring), not a rendered raster top-down view of a chunk. The
walkability stitch above is therefore the full deliverable for this pass,
as anticipated.

### Corrected asset inventory status

Every category the map-model mission named is now tied together end to
end: zone (`a/0/1/2`, `zones.py`) -> matrix id (`+0x04`) -> matrix
(`a/0/0/9`, `matrix.py`) -> map model id -> map model + per-tile terrain
grid (`a/0/0/8`, `map_grid.py`) -> textured shapes where a per-shape
render is wanted (`map_shapes.py`). No open link remains between the
zone table and the map-model archive; the remaining gaps are all
internal to one already-identified stage (the per-tile grid's byte[0]/
[1]/[2]/[3]/[5]/[7] semantics, the GC second grid, the RD dense block,
and the 17 unreferenced matrices), not missing connections between
stages.
