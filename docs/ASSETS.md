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
`u32 instrument_count`, then that many `u32` instrument-table entries
packed as `record_type (low byte) | record_offset << 8` (absolute file
offset, 0 for empty slots). Instrument record types found across all 1497
real banks (26756 total table slots, most empty -- banks are sparse,
fixed-size 128-ish-slot MIDI-program tables where only a handful of
programs are actually used per bank):

| type | meaning | count | confidence |
|---:|---|---:|---|
| 0 | empty slot | 26756 | high |
| 1 | single-region PCM instrument | 1547 | high (verified, see worked example) |
| 2 | unknown, PSG-shaped guess (pulse?) | 122 | low |
| 3 | unknown, PSG-shaped guess (noise?) | 155 | low |
| 16 | drum kit (per-note region table) | 187 | medium (best-effort region parse) |
| 17 | key-split (multi-region) | 1279 | medium (best-effort region parse) |

Type 1's 12-byte record (`wave_arc`, `wave_id`, `base_note`, `attack`,
`decay`, `sustain`, `release`, `pan`, 2 bytes padding) is fully decoded
and confirmed. Types 16/17 are parsed as a leading run of ascending `u8`
split-point note values (terminated at `0x7F`) followed by one 12-byte
PCM-shaped record per split point (`sbnk.parse_regions()`); this matches
the visual shape of real data (ascending note bytes, plausible envelope/
pan values in the trailing bytes) but was not independently re-derived
from a byte-level spec, so it's reported as medium confidence. Types 2/3
are not decoded at all (low confidence even on what they represent).

**Round trip: 1497/1497 real banks (100%) byte-identical.** This is
guaranteed by construction, not a coincidence: `Sbnk.roundtrip_bytes()`
re-packs the header and instrument table from the decoded
`(type, offset)` fields (a lossless struct round trip) and copies every
remaining byte verbatim from the end of the table to end of file. That
verifies the container/table structure precisely -- the part that
actually needs to be right for the type/offset table to be trustworthy --
without requiring every instrument type's internal field layout (notably
2/3/16/17) to be fully reverse engineered first.

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
- The BANK/SEQ INFO record fields beyond `file_id`/`wave_arc`/`bank`
  (volume, channel_pressure, player_priority, player_no in
  `Sdat.seq_record()`) are a structurally-plausible field-count guess
  (right total byte count, byte offsets confirmed against real BANK/
  WAVARC cross-references for `file_id` and `wave_arc` specifically) but
  individual field values observed (e.g. `volume=233`, out of the
  expected 0-127 range) suggest the exact sub-field boundaries within
  those bytes are not fully correct. Not load-bearing for anything in
  this pass (no `.wav`/decode output depends on them), so left as a
  labelled guess rather than chased further.
- STRM (streamed audio) format was not investigated -- `wb_sound_data.sdat`
  has zero STRM entries (see "SDAT internal structure" above), so there
  is nothing to decode.

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
   round-trip verified. See "SWAR/SWAV, SBNK, SSEQ: audio playback
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
                                4bpp sub-palettes; every sampled OAM uses
                                sub-palette 0)
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
small quadruped/bird creature, confirmed by direct visual inspection, not
inferred from pixel statistics. Entity indices do **not** follow National
Dex order (entity 1 is not Bulbasaur-green, entity 25 is not
Pikachu-yellow), so whatever internal index this is, it is not the
Pokedex number directly.

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
  (every entity) both write true-color `build/assets/overworld/NNNN.png`.
  `--all` result: **715/715 entities rendered, 0 skipped.**
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
- `a/0/0/7`'s entity-index-to-species mapping is unconfirmed (not National
  Dex order); the shared NCER's animation semantics (which of the 3 cells
  plays when, and for how long) live in the NANR block, which this pass
  parsed only past its 16-byte common header + ABNK sub-header
  (`num_anim`, `element_type`) -- the frame-duration/ordering fields inside
  are not decoded, so `overworld.py`'s "sprite sheet" is "every distinct
  cell this entity's shared cell bank defines," not a verified real-time
  animation sequence.
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
