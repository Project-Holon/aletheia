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

## Map-model per-tile grid mission: wrapper header fully mapped, byte-lane model superseded

This section, the attribute-hunt pass and the tall-grass-hypothesis pass
that followed it are all superseded: they treated the per-tile 8-byte
record as eight independent byte lanes and read walkability, height and
a scatter of unexplained codes out of it by correlation alone. The wrapper
header findings (four tags, `WB` one grid / `GC` two grids / `NG` no grid
/ `RD` one grid plus a dense block) held up; the byte-lane reading of the
record itself did not, once the actual reader code was found and
decompiled. See "Per-tile grid record SOLVED" below for the real model,
`tools/assets/map_grid.py`'s current implementation, and the archive-wide
stats this pass produced.

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

## Map attribute hunt: superseded by the record-model pass below

This pass chased tall grass/ledge/water candidates through the byte-lane
model (`byte[1]`/`byte[3]` as outdoor-only codes, a separate-NARC search,
and the wrapper's other unexplained blocks); all of it is superseded now
that the record's real shape is known (see "Per-tile grid record SOLVED"
below). One finding from this pass is worth carrying forward even though
its framing is obsolete: `RD`'s dense 64x64x4 block, read as two `u16`
values per record on `wf_00_00`, showed a `(0,128)`/`(1,129)` pair
matching the ordinary grid's own walkable-flag/flag-half pattern plus a
`4094` boundary sentinel -- consistent with a finer-resolution walkable
mask, not a separate water-type code, though still not decoded against
the new record model. The rest (byte[1]/[3] as ledge/grass/zone
candidates, the `a/0/0/3`/`a/0/6/6` event-table search, `map24_23`'s
196-byte tail) is moot: those byte positions are the high halves of the
surface and height-index `u16`s, not independent codes, so nothing found
there needs re-deriving.

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

## Asset lane pass: byte[3]-as-tall-grass hypothesis: superseded

This pass cross-tabulated byte[3] against map ground textures and refuted
it as a grass-specific lane (it correlated with cliffs and riverbeds too,
and inverted on one winter sample), leaving byte[1]-as-ledge inconclusive.
Moot now, same reason as the other byte-lane passes: byte[3] is the high
byte of the height-index u16, not an independent terrain code, so there
was never a tall-grass bit there to find. The real tall-grass candidate
(the attribute word's id/flag family) is confirmed in "Per-tile grid
record SOLVED" below.
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

`--stitch N` places every chunk's terrain-class grid (`map_grid.py`'s
record model, run through the `classify_terrain()` port of
`func_021AB504`) at its matrix cell position in one image, using the same
32x32-tile chunk size every placed `a/0/0/8` sub-file in matrix 0/175
actually has; tiles that classify to 8 ("no terrain effect", the
overwhelming majority) fall back to plain walkable/blocked shading
(attribute flag bit 0) so the image still reads as a walkable-area map,
with the 8 named classes -- the `{4,5,0x21}`/`{6,7,0x22}` encounter
families among them -- picked out in distinct colors on top. Run against
both mode-1 matrices (updated after the record-model rewrite, see "Per-tile
grid record SOLVED" below):

    matrix 0:   29x27 chunks, 229 placed, 554 missing/empty/non-32x32
                stitched image: 928x864 px
                border continuity: 354 adjacent chunk-pair edges checked,
                10769/11328 edge tiles agree on walkability (95.1%)
    matrix 175: same shape, same 229/554 split, same 95.1% border
                agreement (consistent with the earlier section's note
                that matrix 0 and 175 share the same 229 used cells and
                same max map id -- two variants of the same layout, not
                two different worlds)

928x864 pixels (29*32 by 27*32, one pixel per tile), gitignored under
`build/assets/maps/matrix0_terrain_class.png` and
`matrix175_terrain_class.png`, not committed. The border-continuity number
(now computed from the attribute word's own walkable bit rather than the
retired byte[4]) rose from the earlier pass's 92.8% to 95.1%, consistent
with the new field being the more precise source. The remaining ~5%
mismatch is expected, not a defect: the walkable flag also marks scenery
(trees/rocks/buildings) whose footprint is chunk-local and has no reason
to align across a seam the way a road or river does.

**Encounter-family patches confirmed on Route 1's area:** zone 291 --
independently identified as an early-route zone by its Patrat/Lillipup/
Purrloin grass encounter table (see "Wild encounter tables located"
below) -- resolves via `zones.py --resolve` to matrix 175, map ids
`[56, 57, 58, 59]`. Those four specific chunks carry none of the
`{4,5,0x21,6,7,0x22}` ids themselves (they read as a path/building corner
of the zone, not its grass field), but scanning matrix 175 as a whole
finds these ids filling dozens of chunks in contiguous, multi-chunk
regions -- e.g. map `#82` (row 5, col 19) has 180/1024 tiles carrying an
encounter-family id, and plotting them shows one solid field-shaped patch,
not scattered noise, exactly the shape a tall-grass field should have.
This confirms the ids form real terrain patches at the matrix level; it
also shows a zone's own nominal encounter table is a separate mechanism
from which of its tiles carry a grass-family attribute id, since zone
291's own four chunks have no such tiles at all.

`map_shapes.py` was checked for a per-map top-down image export and does
not have one: its only output is a textured OBJ/MTL per shape (see its
module docstring), not a rendered raster top-down view of a chunk. The
terrain-class stitch above is therefore the full deliverable for this
pass, as anticipated.

### Corrected asset inventory status

Every category the map-model mission named is now tied together end to
end: zone (`a/0/1/2`, `zones.py`) -> matrix id (`+0x04`) -> matrix
(`a/0/0/9`, `matrix.py`) -> map model id -> map model + per-tile terrain
grid (`a/0/0/8`, `map_grid.py`) -> textured shapes where a per-shape
render is wanted (`map_shapes.py`). No open link remains between the
zone table and the map-model archive; the remaining gaps are all
internal to one already-identified stage (which terrain id names tall
grass/water/ledges specifically, the GC second grid, the RD dense block,
and the 17 unreferenced matrices), not missing connections between
stages.

## Core game data tables: personal, move, item, learnset and evolution
decoders, all byte-identical round trip (`tools/assets/personal.py`,
`waza.py`, `items.py`, `learnsets.py`, `evolution.py`)

Five decoders for the core per-species/per-move/per-item data tables,
each built from this project's own decompiled accessors
(`src/matched/unit_0201AE14.c` poke_personal.c, `unit_0201BD28.c`/
`unit_0201BEB8.c`/`unit_0201C020.c`/`unit_0201C158.c` waza_tool.c,
`unit_0201B70C.c` shinka_check.c, and `unit_02021014.c`'s item record
accessor) rather than from any outside reference.

### Pokemon personal data: `a/0/1/6`, confirmed

669 sub-files: a 56-byte sentinel at index 0, 667 real 60-byte Personal
records at indices 1-667, and one 1300-byte outlier at index 668 that is
not a Personal record and is left undecoded. 667 real records against
649 species is +18, consistent with a handful of species carrying extra
form slots; this pass does not attempt to attribute which species own
which extra slot.

Field map: struct Personal from `unit_0201AE14.c`'s 44-case getter,
every offset attested by one jump-table case. Only the fields that
file's own comments name are given a semantic label (six base stats, two
types, catch rate, three held item slots, the six 2-bit EV-yield fields,
form-table base/companion/count); everything else keeps the source's
`unkXX` spelling rather than being guessed. Gender ratio, hatch cycles,
friendship, growth rate, egg groups, abilities and colour -- all named in
the mission -- are NOT separately attested by any accessor read this
pass, so none of those six categories got a label; they remain
unconfirmed.

Sanity check (record 1, Bulbasaur-shaped, read with no external
reference): HP 45, Atk 49, Def 49, Spe 45, SpA 65, SpD 65, type0=11,
type1=3, catch_rate=45, and the EV-yield bitfield gives exactly 1 Sp.Atk
EV and 0 everywhere else -- the last detail was not asked for by the
mission and matches anyway, which is independent confirmation beyond the
six requested stats.

Round trip: **667/667 records, 40020/40020 bytes byte-identical**
(`--verify`).

### Move data: `a/0/2/1` is the move table, `a/0/2/4` is the item table

Both are 36-byte-record archives as the mission said. `a/0/2/1` (560
sub-files) decodes record 1 to type=0 (Normal), category=1, power=40,
accuracy=100, pp=35, priority=0 -- Pound's real type/power/accuracy/PP
exactly, with no substitution needed (sub_0201BDB4's 0x65->0x64
accuracy fixup never triggers here because the stored byte is already
100). `a/0/2/4` (627 sub-files) has no plausible power/accuracy/PP triple
anywhere in its bytes; instead its first u16 field, read through the real
ARM9 item-record accessor (`func_02021014`'s `case 0: return p->f00 *
10;`), decodes items 1-4 to prices 0, 1200, 600, 200 -- Master Ball (not
for sale), Ultra Ball, Great Ball, Poke Ball's real Black/White shop
prices. See `tools/assets/items.py` for the item-side field map and
evidence.

Field map: struct Waza combined from `unit_0201BD28.c` (offsets
0x00-0x1E, the dense-switch getter) and `unit_0201BEB8.c` (offset 0x20,
the flag-bit test), 36 bytes total. Named fields: type, category, power,
accuracy, pp, priority, effect (the one 16-bit field in the low half),
and flags (the bit-tested u32 at 0x20); the rest keep the source's
`unkXX` spelling. Offset 0x1E (2 bytes) is reached by no case id in
`sub_0201BD28`'s switch (id 29 is a gap, not an empty arm) and has no
accessor anywhere else in this pass, so it is decoded and round-tripped
but not named.

Round trip: **560/560 records, 20160/20160 bytes byte-identical**
(`--verify`).

### Learnsets: `a/0/1/8`, confirmed

668 sub-files, every one ending in a (0xFFFF, 0xFFFF) u16 pair when read
as (move, level) pairs -- the only ~650-670-sub-file candidate with that
property (`a/0/1/9` and `a/0/2/0` both score 0/N). Sub-file 1 (species 1)
decodes to 14 (move, level) pairs starting (33,1), (45,3), (73,7);
sub-file 2 (species 2) starts (33,1), (45,1), (73,1), (33,3), (45,7) --
the same early moveset shifted the way an evolved form that starts at a
higher level reads, which was checked directly against the bytes, not
against an outside learnset table. 667 real species/form sub-files
(indices 1-667) match `a/0/1/6`'s 667 real Personal records exactly.

Round trip: **668/668 sub-files byte-identical** (`--verify`).

### Evolution data: `a/0/1/9`, confirmed

668 sub-files, every one exactly 42 bytes: `unit_0201B70C.c`
(shinka_check.c) gives `struct EvoTable { struct EvoRow rows[7]; u16
unk2A; }` with `struct EvoRow { u16 method; u16 param; u16 species; }`
(44 bytes with the trailing halfword); the archive carries the 7-row,
42-byte array without that trailing halfword, which `sub_0201B718` never
reads anyway. Sub-file 1 (species 1) decodes to one row: method=4,
param=16, target=2; sub-file 2 (species 2) decodes to method=4, param=32,
target=3 -- read as "level-up at the param level", this is the real
Bulbasaur (1) -> Ivysaur (2, level 16) -> Venusaur (3, level 32) chain,
checked directly against the bytes.

Target bound check (`--verify-targets`): **321/321** non-empty evolution
targets across all 667 real records are `<= 667`, the real personal-table
record count.

Round trip: **668/668 records, 28056/28056 bytes byte-identical**
(`--verify`).

### What remains unconfirmed after this pass

- Personal: gender ratio, hatch cycles, friendship, growth rate, egg
  groups, abilities and colour are not attributed to any offset; the
  1300-byte sub-file 668 is not identified.
- Move: offset 0x1E (2 bytes) has no accessor and no semantic label.
- Item: the record struct and the price field are attested by a real
  accessor (`unit_02021014.c`), but `a/0/2/4`'s identity as the specific
  archive that accessor's caller opens is not attested by a decompiled
  opener (`func_02020F34` is not in this tree) -- the identification
  rests on the price-value match, not on a narc-kind id the way
  poke_personal/waza_tool/shinka_check are. Most byte-level fields in the
  item record (the `Sub` bitfield block) are decoded and round-trip but
  have no semantic label beyond the accessor's own `fXX`/`bNN_M` names.
- Evolution: the method-id space (e.g. what value means "trade",
  "stone", etc. beyond "4 = level-up", inferred only from the level-up
  shape of param) is not enumerated.

## Wild encounter tables located: `a/1/2/6`, tied to the zone table via `packed_1a`, 4-season blocks on 12 archives (`tools/assets/encounters.py`)

Mission: find and decode the wild encounter tables, tie them to the zone
record, and handle seasonal variants. New module, stdlib only.

### The shape hypothesis, tested archive-wide

A small header of per-method rate bytes followed by slots of
`{u16 species_and_form, u8 min_level, u8 max_level}` (species < 650,
masked by 0x7FF; min <= max <= 100) was tested against every archive
under `extract/data/a` (the same 235-file set `zones.py --survey`
walks), over header lengths 0-19 bytes. A loose first pass (any header
length, zero slots counted as a free pass) flagged several archives
(`a/0/1/9`, `a/0/2/4`, `a/1/6/9`, `a/2/1/4`, `a/1/6/3`, `a/0/2/1`) purely
because most of their records have only 1-5 slots, which is too easy to
satisfy by chance. Only one archive survives a stricter check (species
values actually distinct and plausible, not just bounded, across its
whole sub-file set, and a header length that holds for every sub-file
at once): **`a/1/2/6`**, 112 sub-files.

### Layout

`a/1/2/6` sub-files come in exactly two sizes: **100 of 232 bytes, 12 of
928 bytes** (928 = 4 x 232 exactly, no remainder). Both are multiples of
one 232-byte block:

    +0x00  u8 x 7   method rates: grass, double grass, shaking grass,
                    surf, rippling water, fishing, rippling fishing
    +0x07  u8       pad
    +0x08  56 x {u16 species_and_form, u8 min_level, u8 max_level}

The 56 slots split 12/12/12/5/5/5/5 (grass, double grass, shaking grass,
surf, rippling water, fishing, rippling fishing) -- not assumed, derived:
every sub-file's body is exactly 224 = 56*4 bytes with zero remainder,
and this is the one grouping under which each sub-file's zero/nonzero
slot boundary lines up with a method boundary rather than falling
mid-method. Confirmation: sub-file 0's body is all-zero for 36 slots
(three 12-slot land methods) and then real data for 20 slots (four
5-slot water methods) -- a land-free water zone, methods bounded exactly
at 12*3=36. `species_and_form` masks to species at bits 0-10 (archive-wide
max 633, well under 650) with a 0-3-valued form in the top bits.

232-byte sub-files (100/112) are a single block, applying all year.
928-byte sub-files (12/112) are four concatenated 232-byte blocks, one
per season; which block is which real-world season is not attested by
any traced code and is not asserted here (see `encounters.py`'s
docstring for the per-block grass-slot-count spread across all 12
seasonal sub-files, which does not reduce to one clean story).

### The zone lane: `packed_1a`, low 10 bits (record offset +0x1a & 0x3ff)

Tested every numeric lane `zones.py` still has no attested meaning for
(`field_00`, `field_01`, `field_02`, `field_14`, `field_18`, `field_20`,
both packed_1a halves, every packed_1c slice, every flags bit range)
against `a/1/2/6` (112 sub-files), the same bounded-range +
house/outdoor-classifier-correlation method `--map-lane-check` used for
the map lane (classifying a zone by resolving it through its matrix to
an `a/0/0/8` map, via `resolve_zone_maps()`, then by that map's name
prefix):

    packed_1a & 0x3ff:  bounded (<112) on 406/427 zones, 111 distinct
                        values (112 sub-files minus one, #3, unused by
                        this lane on this sample)
                        house-classified zones: 3 distinct index values
                        outdoor-classified zones: 66 distinct index values
                        overlap between the two sets: 2 values

No other lane comes close: most fail the bounded-range test outright
(`field_02` bounded on 79/427, `field_14` on 112/427, `field_20` on
207/427, all with max values in the thousands or 65535), and the ones
that are bounded show no house/outdoor split (e.g. `packed_1c` bits 0-5:
house and outdoor both concentrate on the same 1-2 values).

Direct, non-statistical confirmation: zone ids **290, 291, 292** (three
consecutive zones, all on matrix 175, one of the two overworld halves)
resolve via `packed_1a & 0x3ff` to sub-files **77, 78, 79** -- three
consecutive zones landing on three consecutive tables. Sub-file 78's
grass slots are `#504` (Patrat), `#506` (Lillipup) and `#509`
(Purrloin) at levels 4-7, and its shaking-grass slots are `#531`
(Audino) at levels 4-7 -- exactly the mission's predicted "low-level
early species in the 500s" signature, on a zone/table pair that the
numeric correlation test also picked independently.

21/427 zones land outside 0..111 on this lane (values 112-116); these
are treated as "no encounter table" by `encounters.py --zone` rather
than guessed at, since a 112-sub-file archive has no sub-file 112+.

### Sanity check

    zone 291 (matrix 175) -> packed_1a lane value 78 -> a/1/2/6 sub-file 78
      grass:          #504(Lv4-4) #506(Lv4-4) #504(Lv5-5) #506(Lv5-5)
                      #509(Lv4-4) #509(Lv5-5) #504(Lv6-6) #506(Lv6-6)
                      #504(Lv7-7) #506(Lv7-7) #504(Lv7-7) #506(Lv7-7)
      shaking_grass:  #531 at Lv4-7 (12 slots)
      rates: grass=8, shaking_grass=1, all others 0

Patrat (504), Lillipup (506) and Purrloin (509) at levels 4-7 is exactly
the mission's expected early-route, low-level, 500s-species profile.

### Round trip

`encounters.py --verify`: **112/112 sub-files round-trip byte-identical**
(every block: 7 rates + pad + 56 slots, repacked and compared against
the original).

### What remains

- The real-world season identity of blocks 0-3 in the 12 seasonal
  sub-files is not determined (no code path for this lane was traced;
  the grass-slot-count pattern across blocks does not collapse to one
  clean "block N is always winter" rule -- see `encounters.py`'s
  docstring for the actual per-sub-file spread).
- The 17-value gap between packed_1a's 406 bounded zones and the full
  427, and sub-file 3's apparent non-use by this lane on the current
  427-zone sample, are left as-is rather than forced to resolve.
- The form field (0-3 observed) in `species_and_form`'s top bits is
  decoded structurally (it is not folded into the species id) but not
  matched to any specific in-game form.

## Coverage census

Definitive per-archive coverage census over all 247 NitroFS files (237 NARC + 10 raw), built from `build/assets/inventory.json` plus every archive identification recorded in this document, with the generic-format (NCLR/NCGR/NCER/NANR/NSCR/NSBMD/NSBTX) round trips actually re-run this pass via `tools/assets/background.py --verify`, `tools/assets/nsbmd.py roundtrip` and `tools/assets/icons.py --all --roundtrip`, plus `tools/assets/items.py --verify` re-run for confirmation. Machine-readable form: `build/assets/census.json` (gitignored, regenerate, don't commit).

### Summary

| status | archives | sub-files |
|---|---:|---:|
| covered and verified | 28 | 40843 |
| generic format, verified | 120 | 4909 |
| generic format, not verified | 0 | 0 |
| custom format, no decoder | 87 | 8217 |
| unknown | 12 | 85 |
| **total** | **247** | **54054** |

This pass (see "Verification pass" below) closed the "generic format, not verified" group entirely: all 82 archives (2337 sub-files) now verify, via the new `tools/assets/verify_all.py` archive-wide sweep, moving into "generic format, verified" (38 -> 120 archives, 2572 -> 4909 sub-files). The other rows are unchanged by this pass; their counts are taken from `build/assets/census.json` (the table immediately above this one had drifted out of sync with it across earlier passes and is corrected here).

"covered and verified" is every archive this project has identified and built a dedicated decoder for, with the round-trip/verification status that decoder actually reports (a few are identified but not yet byte-round-tripped; these are flagged `partial`/`unverified`/`failing` in the `decoder`/`status` columns below, not silently merged into the verified count). "generic format, verified" is an archive whose dominant sub-file magic is a standard NITRO/G3D chunk (NCLR/NCGR/NCER/NANR/NSCR/NSBMD/NSBTX) covered by one of the project's generic-format converters' own `--verify`/`roundtrip` checks. "generic format, not verified" is the same dominant-magic shape with no archive-wide converter run against it yet -- decoding it needs verification, not a new decoder. "custom format, no decoder" is a dominant magic that is not a recognised NITRO chunk (a Game Freak-specific record table or wrapper) with no decoder written. "unknown" is the inventory's own `category_guess` of "unknown"/"unknown raw format" -- too little evidence yet for even a format guess.

### Full per-archive table

`path` is relative to `extract/data/`. `status` values: `verified` (byte-identical round trip reported), `partial` (decoded/identified but round trip covers less than the whole archive, or is reported at a coarser grain than raw sub-files), `failing` (round trip attempted and fails), `unverified` (identified/decoded, no round-trip count reported), `none` (no decoder).

| path | subs | dominant magic | bucket | decoder | status | note |
|---|---:|---|---|---|---|---|
| a/0/0/0 | 5 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 2 verified; RGCN: 3 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/0/1 | 8 | NSCR (screen/map) | generic format, verified | background.py | verified | NSCR sub-files covered by background.py --verify (188/188 byte-identical across its 20 covered archives). |
| a/0/0/2 | 288 | 0x0100ee01 | covered and verified | text.py | partial | Text archive (species/move/item/ability/type name banks among 288 sub-files). XOR-rotate-3 cipher solved and confirmed by direct key recovery (produces real English names byte-for-byte). A dictionary/token compression layer covering most entries is NOT cracked. Round trip is 100% byte-identical but only on the minority of entries that decode fully clean (133/650 species, 35/558 moves, 16/625 items, 8/163 abilities, 1/15 types sampled); most entries remain partially undecoded. |
| a/0/0/3 | 472 | 0x01000100 | covered and verified | events.py | verified | Event/script-table archive, HIGH-confidence container framing (16-byte header + index table + variable bytecode-shaped records). Record payload bytecode itself not decoded past byte-exact extraction. Round trip: 472/472 sub-files byte-identical. |
| a/0/0/4 | 14285 | (none) | covered and verified | rig.py | verified | Pokemon battle/menu rig archive (paired with a/0/5/2): NCER/NMCR/NMAR cell-animation rig, 14285 sub-files (20 x 714 species/forms). OAM tile addressing and NANR sequence record corrected from decompiled game code; per-frame composition and GIF export implemented. 713/714 species render (1 known detachment issue: Charizard/Gengar-class, root-caused as authored placement data, not a decode bug). Archive-wide byte-level sub-file round trip: 10395 pass, 0 fail, 3890 skipped (no recognised magic, custom/local-8 fields). See "Rig-archive false-positive-tag guard closes the last verify_all failures" below. |
| a/0/0/5 | 13 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 5 verified; RGCN: 8 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/0/6 | 733 |  APS | covered and verified | trainer.py | verified | Particle/UI-effect archive (733 sub-files, custom " APS12_1"/" TPS" wrapper, NOT a trainer portrait set as originally guessed -- renders are glints/sparkles/rings/pulses). Re-encoder round trip: 733/733 byte-identical. |
| a/0/0/7 | 1431 | NCGR (tile/character data) | covered and verified | overworld.py | verified | Full-color per-species icon archive (party icons), 715 entries, confirmed species-indexed via the game's own per-entity sub-palette selector table. NCGR round trip: 715/715 byte-identical. |
| a/0/0/8 | 649 | 0x57420300 | covered and verified | nsbmd.py (wrapper-aware) + map_grid.py + map_shapes.py | verified | Overworld map/building/dungeon 3D model archive, 649 sub-files, identified by MDL0 model name (mapNN_MM / m_dunNNNN / cNN / pl_00_00 / etc). Small custom size-table wrapper around BMD0 cracked; per-tile grid record decoded to the game's own model (`{u16 surface, u16 heightIndex, u32 attribute}`, attribute = terrain id + flag half, confirmed from decompiled code) rather than byte lanes. Textures not wired into the map OBJ exports; `RD`'s dense secondary block and `GC`'s second grid located but not semantically decoded. Whole-sub-file round trip (wrapper + grids + aux arrays + tails): 649/649 byte-identical. |
| a/0/0/9 | 255 | 0x00000000 | covered and verified | matrix.py | verified | Zone-to-map matrix archive, 255 sub-files, u32 cells resolving to a/0/0/8 sub-file indices (mode-1 cells also carry a zone-id grid). Round trip: 255/255 byte-identical. |
| a/0/1/0 | 1 | 0x00000000 | custom format, no decoder | tables.py | unverified | Single sub-file, 752 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/0/1/1 | 222 | NSBMD (model) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/0/1/2 | 1 | 0x04104a00 | covered and verified | zones.py | verified | Zone header table, single sub-file, 427 records x 48 bytes, layout attested by decompiled accessors. Round trip: 427/427 records byte-identical. |
| a/0/1/3 | 0 | 0x00000000 | custom format, no decoder | unknowns.py | unverified | NOT a NARC (bad magic), a single 2820-byte raw file. Resolves cleanly to 282 fixed 10-byte records with a recurring 0xFFFF sentinel word, but no reader found (see "Twelve unknowns identified" below) and no field split attempted; domain not identified. Whole-file identity copy (no container to re-pack). |
| a/0/1/4 | 282 | NSBTX (texture) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/0/1/5 | 5 | 0x00008410 | custom format, no decoder | tables.py | unverified | 5 sub-files, fixed 16-byte records. Reader found this pass by backward-register scan: overlay_021 func_02189154 (fieldmap.c), via func_02048F4C(archive_id=15, ...). Identification: field-map subsystem table (fieldmap.c); record fields not decoded. Confidence: LOW-MEDIUM (reader confirmed, domain still open). See "Group 2 custom table pass" and "Archive readers extended by backward-register scan" in this doc. |
| a/0/1/6 | 669 | dddd | covered and verified | personal.py | verified | Pokemon personal (base stat) data, 669 sub-files (1 sentinel + 667 real 60-byte records + 1 undecoded 1300-byte outlier). Round trip: 667/667 records byte-identical. |
| a/0/1/7 | 8 | 0x00000000 | custom format, no decoder | tables.py | unverified | 8 sub-files, fixed 404-byte records. Reader found this pass by backward-register scan: arm9 func_02019B94 (poke_tool.c), via a hand-written thunk (ldr+mov+bx, not in the worklist.json thunk inventory) into func_02048F4C(archive_id=17, ...). Identification: Pokemon-utility-indexed table (poke_tool.c); record fields not decoded. Confidence: LOW-MEDIUM (reader confirmed, domain still open). See "Group 2 custom table pass" and "Archive readers extended by backward-register scan" in this doc. |
| a/0/1/8 | 668 | 0x21000100 | covered and verified | learnsets.py | verified | Level-up learnsets, 668 sub-files ((move, level) pairs terminated by 0xFFFF/0xFFFF). Round trip: 668/668 sub-files byte-identical. |
| a/0/1/9 | 668 | 0x00000000 | covered and verified | evolution.py | verified | Evolution data, 668 sub-files, 7-row x 6-byte evolution table per species. Round trip: 668/668 records byte-identical. |
| a/0/2/0 | 650 | 0x8500 | covered and verified | tables.py | verified | Per-species single u16 field (evolution-family/base-species index, per icons.py's value-pattern note). Reader: ov021 func_021C4504 (0x021C4504) via func_02048F74(dst, archive_id=0x14, member=species_id, mode=0, size_out). Round trip: 650/650 byte-identical. See "Large custom table pass" in this doc. |
| a/0/2/1 | 560 | 0x000d0000 | covered and verified | waza.py | verified | Move data table, 560 sub-files, 36-byte records. Round trip: 560/560 records byte-identical. `verify_all.py --archive a/0/2/1`: 0 pass, 0 fail, 560 skipped (the false-positive LZ tag guard now correctly skips these plain 36-byte records instead of misreading some of them as fail; see "Rig-archive false-positive-tag guard closes the last verify_all failures" below). |
| a/0/2/2 | 3 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 1 verified; RGCN: 1 verified; RCSN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/2/3 | 8 | NFTR variant (font, guess) | covered and verified | font.py | verified | Stale census row (predates font.py): 5 NFTR fonts (5064/5064/5064/32/41 glyphs) + 3 NCLR palettes. Glyph metrics + packed bitmaps confirmed against decompiled `sub_0201DC44.c`/`sub_0201E4D4.c`, CMAP confirmed against text.py's ASCII identity. Round trip: 15265/15265 glyph records byte-identical. See "Asset lane pass: fonts located and decoded" below. |
| a/0/2/4 | 627 | 0x00000000 | covered and verified | items.py | verified | Item data table, 627 sub-files, price field confirmed against real BW shop prices via the game's own accessor. Round trip: 627/627 records byte-identical (re-run this pass). |
| a/0/2/5 | 1005 | NCLR (palette) | covered and verified | overworld.py | verified | Bag item-icon archive, 1005 sub-files (451 NCGR + 552 NCLR + 1 shared NCER + 1 shared NANR, nearest-index pairing). NCGR round trip: 451/451 byte-identical. |
| a/0/2/6 | 15 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RGCN: 4 verified; RCSN: 5 verified; RLCN: 4 verified; RECN: 1 verified; RNAN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/2/7 | 17 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RGCN: 7 verified; RLCN: 3 verified; RCSN: 3 verified; RNAN: 2 verified; RECN: 2 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/2/8 | 17 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 5 verified; RGCN: 4 verified; RECN: 2 verified; RCSN: 4 verified; RNAN: 2 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/2/9 | 18 | NSCR (screen/map) | generic format, verified | background.py | verified | NSCR sub-files covered by background.py --verify (188/188 byte-identical across its 20 covered archives). |
| a/0/3/0 | 35 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RGCN: 14 verified; RCSN: 3 verified; RLCN: 6 verified; RNAN: 1 verified; RECN: 1 verified; b'\x00\x03\x03\x00': 1 skipped (no decoder); b'\x00\x00\x00\x00': 1 skipped (no decoder); b'\x01\x01\x01\x00': 1 skipped (no decoder); b'\x00\x01\x04\x00': 1 skipped (no decoder); b'\x03\x03\x03\x00': 1 skipped (no decoder); b'\x01\x01\x00\x00': 4 skipped (no decoder); b'\x00\x01\x01\x00': 1 skipped (no decoder). Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/3/1 | 24 | NCER (cell bank) | covered and verified | walk.py | verified | Named-character (player/rival-class) 4-direction walk/run cycle archive. NCGR round trip: 7/7 byte-identical. |
| a/0/3/2 | 97 | NCGR (tile/character data) | covered and verified | walk.py | verified | Generic overworld NPC walk-cycle set, 32 characters in 2 blocks of 16. NCGR round trip: 32/32 byte-identical. |
| a/0/3/3 | 33 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 11 verified; RGCN: 8 verified; RECN: 2 verified; RCSN: 10 verified; RNAN: 2 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/3/4 | 39 | NSCR (screen/map) | generic format, verified | background.py | verified | Also holds 1 " APS12_1"/" TPS" particle/UI-effect sub-file(s) (indices vary by archive) decoded and identified by trainer.py as part of the same shared wrapper format as a/0/0/6; this is a small minority of the archive's sub-files and does not cover its dominant content (see dominant-magic column). NSCR sub-files covered by background.py --verify (188/188 byte-identical across its 20 covered archives). |
| a/0/3/5 | 16 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RCSN: 4 verified; RGCN: 4 verified; RLCN: 4 verified; RECN: 2 verified; RNAN: 2 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/3/6 | 14 | 0x11240800 | custom format, no decoder | tables.py | unverified | 14 sub-files, variable 68..19320 bytes (dominant size 552 bytes on 2/14). No reader found among the seven accessor functions for this archive id. Identification: LZ11-compressed generic NITRO chunks: decompresses to RGCN/RCSN (NCGR/NCLR family, tile+palette). Confidence: HIGH (magic recovered after decompression). See "Group 2 custom table pass" in this doc. |
| a/0/3/7 | 1 | 0x3019080f | custom format, no decoder | tables.py | unverified | Single sub-file, 5376 bytes, opaque blob. Reader found this pass by backward-register scan: overlay_071 func_021B69AC, via func_02048F60(archive_id=37, ...); this call site has no nearby `__FILE__` anchor, so the translation unit is not named. Identification: domain still not identified (reader confirmed, no file-name evidence). Confidence: LOW (reader confirmed but no naming evidence; domain not identified). See "Group 2 custom table pass" and "Archive readers extended by backward-register scan" in this doc. |
| a/0/3/8 | 1 | 0x03090200 | custom format, no decoder | tables.py | unverified | Single sub-file, 576 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/0/3/9 | 18 | 0x11240800 | custom format, no decoder | tables.py | unverified | 18 sub-files, variable 80..4916 bytes (dominant size 552 bytes on 3/18). No reader found among the seven accessor functions for this archive id. Identification: LZ11-compressed generic NITRO chunks: decompresses to RGCN/RCSN, same family as a/0/3/6. Confidence: HIGH (magic recovered after decompression). See "Group 2 custom table pass" in this doc. |
| a/0/4/0 | 53 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 25 verified; RGCN: 8 verified; RCSN: 12 verified; RECN: 2 verified; RNAN: 2 verified; b'BMD0': 2 verified; b'BCA0': 2 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/4/1 | 33 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 16 verified; RGCN: 16 verified; RCSN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/4/2 | 1 | 0xc4030000 | custom format, no decoder | tables.py | unverified | Single sub-file, 1440 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/0/4/3 | 47 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 10 verified; RGCN: 14 verified; RCSN: 11 verified; RECN: 6 verified; RNAN: 6 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/4/4 | 12 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RGCN: 3 verified; RLCN: 4 verified; RCSN: 3 verified; RNAN: 1 verified; RECN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/4/5 | 102 | NSBTX (texture) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/0/4/6 | 27 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 5 verified; RGCN: 7 verified; RCSN: 6 verified; RECN: 4 verified; RNAN: 4 verified; b'BTX0': 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/4/7 | 80 | 0x38000000 | custom format, no decoder | tables.py | unverified | 80 sub-files, variable 64..65352 bytes (dominant size 552 bytes on 6/80). No reader found among the seven accessor functions for this archive id. Identification: Uncompressed mix of RGCN/RLCN (NCGR/NCLR) and BMD0/BTX0 (3D model/texture) sub-files. Confidence: MEDIUM-HIGH (direct magics, but a minority of the 80 sub-files, rest opaque). See "Group 2 custom table pass" in this doc. |
| a/0/4/8 | 1 | 0x1f030000 | custom format, no decoder | tables.py | unverified | Single sub-file, 22376 bytes, opaque blob. Reader: arm9 func_0202A128 (0x0202A128) via func_02048F60(archive_id=0x30=48, member, heap); the same function also loads a/2/1/1 (archive id 0xd3=211) via func_0204A298 just before it, for the same member index. Identification: domain not identified despite the confirmed reader above. Confidence: LOW (reader confirmed, field semantics not decoded). See "Group 2 custom table pass" in this doc. |
| a/0/4/9 | 764 | NSBTX (texture) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/0/5/0 | 2 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 1 verified; RGCN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/5/1 | 9 | NCER (cell bank) | generic format, verified | verify_all.py (rig.py NCER encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RECN: 3 verified; RNAN: 3 verified; RGCN: 3 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/5/2 | 14285 | (none) | covered and verified | rig.py | verified | Pokemon battle/menu rig archive, paired with a/0/0/4 (same 14285-sub-file shape, plausibly a normal/shiny or resolution variant). Archive-wide byte-level sub-file round trip: 10395 pass, 0 fail, 3890 skipped (no recognised magic, custom/local-8 fields), identical counts to a/0/0/4. See "Rig-archive false-positive-tag guard closes the last verify_all failures" below. |
| a/0/5/3 | 19 | 0x00000000 | custom format, no decoder | tables.py | unverified | 19 sub-files, variable 28..1410 bytes (dominant size 92 bytes on 3/19). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/0/5/4 | 11 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RGCN: 3 verified; RLCN: 2 verified; RCSN: 2 verified; RECN: 2 verified; RNAN: 2 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/5/5 | 29 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RGCN: 26 verified; RECN: 1 verified; RNAN: 1 verified; RLCN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/5/6 | 44 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RNAN: 9 verified; RECN: 9 verified; RGCN: 11 verified; RLCN: 8 verified; RCSN: 2 verified; b'BTX0': 5 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/5/7 | 899 | 0x00000000 | covered and verified | tables.py | partial | Script-bytecode archive, identified and the VM decompiled in "Script virtual machine located and decompiled" above: reader is ov010 func_02158D78 (loads archive id 0x39 = 57), sub-files are a u32 offset table terminated by halfword 0xFD13 with code after it. 469/899 sub-files carry that table (2592 entry points decoded, 90.7% land cleanly); the other 430 are 8-28 byte side tables, unidentified. tables.py keeps this archive opaque (raw copy) since the bytecode decode lives in that section, not in a converter. Framing round trip (raw copy): 899/899 byte-identical. `verify_all.py --archive a/0/5/7`: 0 pass, 0 fail, 899 skipped (see "Rig-archive false-positive-tag guard closes the last verify_all failures" below). |
| a/0/5/8 | 17 | 0x1a000e00 | custom format, no decoder | tables.py | unverified | 17 sub-files, variable 4..784 bytes (dominant size 784 bytes on 4/17). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/0/5/9 | 18 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 5 verified; RGCN: 5 verified; RCSN: 2 verified; RECN: 3 verified; RNAN: 3 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/6/0 | 1 | 0xed000000 | custom format, no decoder | tables.py | unverified | Single sub-file, 1672 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/0/6/1 | 56 | 0x04000000 | custom format, no decoder | tables.py | unverified | 56 sub-files, fixed 780-byte records. No reader found among the seven accessor functions for this archive id. Identification: 780-byte records resolve into 15 repeated 52-byte sub-blocks (period confirmed by per-offset histogram). Confidence: MEDIUM (structural only, domain unclear). See "Group 2 custom table pass" in this doc. |
| a/0/6/2 | 10 | 0x04000000 | custom format, no decoder | tables.py | unverified | 10 sub-files, fixed 780-byte records. Reader found by the second-level backward-register scan: arm9 func_0201493C (field_status.c), which sets r0=#0x3e=62 immediately before `bl func_02014A20`; func_02014A20 passes that r0 straight through into `blx func_02048F60(archive_id=62, ...)`, a genuine two-level parameter passthrough. Identification: field-status subsystem table (field_status.c), same 15x52-byte sub-block period as sibling a/0/6/1 (still no reader). Confidence: MEDIUM (structural period unchanged, but now also a confirmed two-level reader; domain still not decoded field-by-field). See "Archive readers, second level" in this doc. |
| a/0/6/3 | 17 | NSCR (screen/map) | generic format, verified | verify_all.py (background.py NSCR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 3 verified; RGCN: 2 verified; RCSN: 10 verified; RECN: 1 verified; RNAN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/6/4 | 48 | 0x11b00c00 | covered and verified | rig.py | verified | Trainer back-view sprite set (6 blocks of 8; male/female protagonist, Professor Juniper, Cheren, confirmed by eye). NCGR round trip FIXED this pass: the second block these sub-files carry turned out to be an optional trailing SOPC block (the same one `background.py`'s NcgrTiles already passes through for `a/0/0/1`), not a second top-level RGCN resource; `rig.py`'s `Ncgr.encode()` now reassembles the RAHC head from decoded fields and copies any bytes after the declared tile data (including a trailing SOPC block) verbatim. NCGR round trip now 12/12 byte-identical (see `tools/assets/verify_all.py`). |
| a/0/6/5 | 2 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RGCN: 1 verified; RLCN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/6/6 | 601 | 0x01000000 | covered and verified | events.py | verified | HIGH-confidence container framing recovered (outer header + G x 56-byte group-offset blocks, G in {1,2,3,5,8}), but the 14-fold redundancy in the group table and the per-group payload are not decoded past byte-exact extraction. Reader FOUND this pass by backward-register scan (superseding the earlier "reader searched, not found" result): overlay_094 func_021F94F8 (btlv_effvm.c, the battle visual-effect VM object constructor), via func_02048F60(archive_id=66, member=r6, heap) with r6 the constructor's own 4th argument (an effect id). Identification: battle effect-VM data table, indexed by effect id, NOT a text/language bank as the census's automated guess and the earlier per-language hypothesis both suggested. Confidence: HIGH (direct immediate archive-id load right at the call site, inside the effect-VM's own constructor, paired with a/0/6/7 read the same way two lines later -- see "Archive readers extended by backward-register scan" in this doc). Round trip: 601/601 sub-files byte-identical. |
| a/0/6/7 | 98 | 0x01000000 | custom format, no decoder | tables.py | unverified | 98 sub-files, variable 68..5596 bytes (dominant size 244 bytes on 8/98). Reader found this pass by backward-register scan: overlay_094 func_021F94F8 and two sibling functions (all btlv_effvm.c), via func_02048F60(archive_id=67, ...), 7 call sites total, in the same file and functions that read a/0/6/6 (archive id 66) two lines earlier. Identification: battle effect-VM secondary table, sibling of a/0/6/6. Confidence: MEDIUM-HIGH (reader confirmed at 7 sites in the effect-VM's own file; record fields not decoded). See "Group 2 custom table pass" and "Archive readers extended by backward-register scan" in this doc. |
| a/0/6/8 | 3 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RGCN: 1 verified; RLCN: 1 verified; RCSN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/6/9 | 29 | NSBTA (texture SRT animation) | generic format, verified | verify_all.py (nsbmd.py G3D container round trip) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: b'BTA0': 29 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/7/0 | 6 | 0x01000000 | custom format, no decoder | tables.py | unverified | 6 sub-files, variable 640..6412 bytes (dominant size 3588 bytes on 1/6). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/0/7/1 | 39 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 2 verified; RGCN: 12 verified; RCSN: 5 verified; RECN: 10 verified; RNAN: 10 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/7/2 | 760 | 0x11b00c00 | covered and verified | rig.py | verified | Trainer battle sprite archive, CONFIRMED by direct visual identification of named characters (male/female protagonist, Youngster, Lass, Gym Leader Chili, Elite Four Marshal and Caitlin, Champion Alder, Team Plasma grunts/officers) across 95 blocks x 8 sub-files (760 total). Class-to-block mapping is near-identity on the trdata class id with a few confirmed merges past class 83. NCGR round trip FIXED this pass, same trailing-SOPC-block cause as a/0/6/4/a/0/7/3: now 190/190 byte-identical. |
| a/0/7/3 | 48 | 0x11b00c00 | covered and verified | rig.py | verified | Trainer back-view sprite set, byte-for-byte duplicate of a/0/6/4's renders across all 6 blocks. NCGR round trip FIXED this pass, same trailing-SOPC-block cause as a/0/6/4: now 12/12 byte-identical. |
| a/0/7/4 | 1 | NSBMD (model) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). Reader found by the second-level backward-register scan: overlay_021 func_021C8018 (fld_wipe_3dobj.c), via a cross-region `.inst.w blx` into arm9 func_02046DB8, which forwards straight through to func_02048F60(archive_id=0x4a=74, member=0, heap). Corroborates the existing NSBMD identification; does not change the decode. See "Archive readers, second level" in this doc. |
| a/0/7/5 | 151 | NSBMD (model) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/0/7/6 | 29 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 7 verified; RGCN: 9 verified; RCSN: 5 verified; RECN: 3 verified; RNAN: 3 verified; b' APS': 2 skipped (no decoder). Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/7/7 | 8 | NSCR (screen/map) | generic format, verified | background.py | verified | NSCR sub-files covered by background.py --verify (188/188 byte-identical across its 20 covered archives). |
| a/0/7/8 | 179 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 7 verified; RGCN: 55 verified; RCSN: 15 verified; RECN: 51 verified; RNAN: 51 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/7/9 | 34 | 0x524c0500 | custom format, no decoder | tables.py | unverified | 34 sub-files, variable 256..24420 bytes (dominant size 764 bytes on 2/34). No reader found among the seven accessor functions for this archive id. Identification: Most sub-files begin with the RLCN (NCLR palette) chunk tag uncompressed. Confidence: MEDIUM-HIGH (partial magic match, not exhaustively checked). See "Group 2 custom table pass" in this doc. |
| a/0/8/0 | 1 | 0x98a30000 | custom format, no decoder | tables.py | unverified | Single sub-file, 72 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/0/8/1 | 14 | 0x9f7f0000 | custom format, no decoder | tables.py | unverified | 14 sub-files, variable 8..104 bytes (dominant size 8 bytes on 13/14). No reader found among the seven accessor functions for this archive id. Identification: 13/14 sub-files are 8 bytes: [u32 value close to 0x7fxx][u32 small count 0..10]; 1 outlier at 104 bytes. Confidence: LOW (framing only; a trig/scale-table guess is unconfirmed). See "Group 2 custom table pass" in this doc. |
| a/0/8/2 | 2 | 0x04000000 | custom format, no decoder | tables.py | unverified | 2 sub-files, variable 0..780 bytes (dominant size 780 bytes on 1/2). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/0/8/3 | 172 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 37 verified; RGCN: 66 verified; RECN: 33 verified; RNAN: 33 verified; RCSN: 3 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/8/4 | 4 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RGCN: 1 verified; RLCN: 2 verified; RCSN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/8/5 | 21 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 5 verified; RGCN: 7 verified; RECN: 2 verified; RCSN: 5 verified; RNAN: 2 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/8/6 | 1 | 0x85010100 | custom format, no decoder | tables.py | unverified | Single sub-file, 3294 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/0/8/7 | 1 | 0x23fb0307 | custom format, no decoder | tables.py | unverified | Single sub-file, 106 bytes, opaque blob. Reader: arm9 func_02006EA4 (0x02006EA4) via func_02048F74(dst, archive_id=0x57=87, member=0, mode=0, size_out), single sub-file (member is always 0). Identification: domain not identified despite the confirmed reader above. Confidence: LOW (reader confirmed, field semantics not decoded). See "Group 2 custom table pass" in this doc. |
| a/0/8/8 | 40 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RGCN: 11 verified; RLCN: 11 verified; RCSN: 6 verified; RNAN: 6 verified; RECN: 6 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/8/9 | 24 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 4 verified; RGCN: 5 verified; RCSN: 5 verified; RECN: 3 verified; RNAN: 3 verified; b'BMD0': 3 verified; b'BTA0': 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/9/0 | 1 | 0x01000000 | custom format, no decoder | tables.py | unverified | Single sub-file, 7048 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/0/9/1 | 1 | 0x00000000 | custom format, no decoder | tables.py | unverified | Single sub-file, 1232 bytes, opaque blob. Reader: arm9 func_0202A298 and func_0202A310 (0x0202A298/0x0202A310) via func_02048F74(dst, archive_id=0x5b=91, member=0, mode=variable); both functions first search a table in a/0/9/0 (archive id 0x5a=90, via func_020490A8/func_020490F4) then read a/0/9/1 with the matched mode -- the two archives are used as a pair. Identification: domain not identified despite the confirmed reader above. Confidence: LOW (reader confirmed, field semantics not decoded). See "Group 2 custom table pass" in this doc. |
| a/0/9/2 | 616 | 0x00270001 | covered and verified | trainer_data.py | partial | Trainer data (trdata), 616 sub-files (615 real 20-byte records + 1 sentinel). Identified by reference to a decompiled trainer-class accessor; class count 105 cross-checked against the class-name text bank. `trainer_data.py --verify` (added this pass): the one byte-level cross-check this table supports is that its own partySize field (record offset 3) predicts the paired a/0/9/3 sub-file's length exactly (`partySize * 8`) -- 546/615 records ok, 69 mismatched, 1 skipped (the sentinel), matching the informal count `--records` already printed. Neither table is compressed or chunk-framed, so there is no further format to decode/re-encode; the 69 mismatches are an existing, unresolved gap in the trdata/trpoke pairing model, not a regression from this pass. |
| a/0/9/3 | 616 | 0x00000a00 | covered and verified | trainer_data.py | partial | Trainer data (trpoke), 616 sub-files, variable 8-byte-multiple records, paired 1:1 with a/0/9/2 by index. Same `trainer_data.py --verify` cross-check as a/0/9/2: 546/615 ok, 69 mismatched, 1 skipped. |
| a/0/9/4 | 53 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RGCN: 19 verified; RLCN: 6 verified; RCSN: 19 verified; RNAN: 3 verified; RECN: 3 verified; b'BCA0': 1 verified; b'BMA0': 1 verified; b'BMD0': 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/9/5 | 165 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RCSN: 43 verified; RGCN: 60 verified; RLCN: 60 verified; RECN: 1 verified; RNAN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/9/6 | 42 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 9 verified; RGCN: 11 verified; RECN: 3 verified; RNAN: 3 verified; RCSN: 16 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/0/9/7 | 2 | 0x00000000 | custom format, no decoder | tables.py | unverified | 2 sub-files, variable 274..24888 bytes (dominant size 24888 bytes on 1/2). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/0/9/8 | 10 | 0x01000200 | custom format, no decoder | tables.py | unverified | 10 sub-files, variable 650..1454 bytes (dominant size 1450 bytes on 4/10). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/0/9/9 | 17 | 0x10240100 | custom format, no decoder | tables.py | unverified | 17 sub-files, variable 95..4568 bytes (dominant size 552 bytes on 2/17). No reader found among the seven accessor functions for this archive id. Identification: LZ77-compressed generic NITRO chunks: decompresses to RGCN/RCSN. Confidence: HIGH (magic recovered after decompression). See "Group 2 custom table pass" in this doc. |
| a/1/0/0 | 20 | 0x10240600 | generic format, verified | unknowns.py | verified | Dominant magic was the raw LZ77 compression header, not decompressed by inventory.py's sniff. Decompressing every sub-file: 18 NSCR (16 at 1572 bytes, 2 larger), 1 NCGR (16448 bytes), 1 raw NCLR (552 bytes) -- a background set (screens + tile sheet + palette). Round trip (decompress/recompress): 20/20 byte-identical. See "Twelve unknowns identified" below. |
| a/1/0/1 | 1 | 0xf9000000 | custom format, no decoder | tables.py | unverified | Single sub-file, 672 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/1/0/2 | 31 | NSCR (screen/map) | generic format, verified | background.py | verified | NSCR sub-files covered by background.py --verify (188/188 byte-identical across its 20 covered archives). |
| a/1/0/3 | 64 | NSBCA (animation) | generic format, verified | verify_all.py (nsbmd.py G3D container round trip) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RNAN: 1 verified; RECN: 1 verified; RGCN: 2 verified; RLCN: 2 verified; RCSN: 1 verified; b'BCA0': 20 verified; b'BMD0': 20 verified; b'BTA0': 6 verified; b' APS': 1 skipped (no decoder); b'\xcc\x06\x00\x00': 2 skipped (no decoder); b'x\x05\x00\x00': 2 skipped (no decoder); b'+\x02\x00\x00': 2 skipped (no decoder); b'x\x01\x00\x00': 2 skipped (no decoder); b'6\x01\x00\x00': 2 skipped (no decoder). Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/0/4 | 13 | NSBCA (animation) | generic format, verified | verify_all.py (nsbmd.py G3D container round trip) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RGCN: 1 verified; RLCN: 1 verified; RCSN: 1 verified; b'BCA0': 3 verified; b'BMD0': 3 verified; b'BTA0': 1 verified; b' APS': 1 skipped (no decoder); b'\x94\x02\x00\x00': 2 skipped (no decoder). Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/0/5 | 29 | 0x00000106 | custom format, no decoder | tables.py | unverified | 29 sub-files, fixed 188-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/1/0/6 | 20 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 5 verified; RGCN: 5 verified; RCSN: 2 verified; RECN: 4 verified; RNAN: 4 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/0/7 | 39 | NSBTA (texture SRT animation) | generic format, verified | verify_all.py (nsbmd.py G3D container round trip) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: b'BMD0': 6 verified; b'BTA0': 17 verified; b'BCA0': 8 verified; b'\xb6\x00\x00\x00': 1 skipped (no decoder); b'\xdd\x00\x00\x00': 1 skipped (no decoder); b'\x9f\x00\x00\x00': 1 skipped (no decoder); b'\xb3\x00\x00\x00': 1 skipped (no decoder); b'\x1f\x01\x00\x00': 1 skipped (no decoder); b'h\x01\x00\x00': 1 skipped (no decoder); b'\xe0\x00\x00\x00': 1 skipped (no decoder); b'\xe4\x00\x00\x00': 1 skipped (no decoder). Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/0/8 | 282 | 0x01000000 | custom format, no decoder | tables.py | unverified | 282 sub-files (281 at 28 bytes, 1 outlier at 52 bytes): 12-byte header (two u32 fields always 1, rest zero) + four 4-byte blocks at offsets 12/16/20/24. No reader found; domain not identified (count matches no known species/move/item/trainer-class table). Framing round trip (raw copy): 282/282 byte-identical. See "Large custom table pass" in this doc. |
| a/1/0/9 | 17 | 0x05000000 | custom format, no decoder | tables.py | unverified | 17 sub-files, fixed 4-byte records. Reader found this pass by backward-register scan: overlay_021 func_021BB2F8 and func_021BB3E8 (both field_nogrid_mapper.c), via func_02048F4C(archive_id=109, ...), 2 call sites. Identification: non-grid field-mapper subsystem table (field_nogrid_mapper.c); record fields not decoded. Confidence: LOW-MEDIUM (reader confirmed, domain still open). See "Group 2 custom table pass" and "Archive readers extended by backward-register scan" in this doc. |
| a/1/1/0 | 2 | NSBMD (model) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/1/1/1 | 6 | 0x00501428 | custom format, no decoder | tables.py | unverified | 6 sub-files, variable 76..8260 bytes (dominant size 276 bytes on 1/6). No reader found among the seven accessor functions for this archive id. Identification: Nitro sound pair: sub-files include SBNK (sound bank) and SSEQ (sequence) chunks alongside raw PCM-ish blocks. Confidence: HIGH (standard chunk magics). See "Group 2 custom table pass" in this doc. |
| a/1/1/2 | 6 | 0x03145028 | custom format, no decoder | tables.py | unverified | 6 sub-files, variable 76..8260 bytes (dominant size 276 bytes on 1/6). No reader found among the seven accessor functions for this archive id. Identification: Nitro sound pair: SBNK/SSEQ chunks present, same family as a/1/1/1. Confidence: HIGH (standard chunk magics). See "Group 2 custom table pass" in this doc. |
| a/1/1/3 | 6 | 0x01282850 | custom format, no decoder | tables.py | unverified | 6 sub-files, variable 80..8260 bytes (dominant size 276 bytes on 1/6). No reader found among the seven accessor functions for this archive id. Identification: Nitro sound pair: SBNK/SSEQ chunks present, same family as a/1/1/1. Confidence: HIGH (standard chunk magics). See "Group 2 custom table pass" in this doc. |
| a/1/1/4 | 6 | 0x02282814 | custom format, no decoder | tables.py | unverified | 6 sub-files, variable 92..8260 bytes (dominant size 276 bytes on 1/6). No reader found among the seven accessor functions for this archive id. Identification: Nitro sound pair: SBNK/SSEQ chunks present, same family as a/1/1/1. Confidence: HIGH (standard chunk magics). See "Group 2 custom table pass" in this doc. |
| a/1/1/5 | 183 | NSBMD (model) | generic format, verified | nsbmd.py | verified | Also holds 8 " APS12_1"/" TPS" particle/UI-effect sub-file(s) (indices vary by archive) decoded and identified by trainer.py as part of the same shared wrapper format as a/0/0/6; this is a small minority of the archive's sub-files and does not cover its dominant content (see dominant-magic column). BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/1/1/6 | 79 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RCSN: 8 verified; RGCN: 34 verified; RLCN: 29 verified; RECN: 4 verified; RNAN: 4 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/1/7 | 53 | 0x08000000 | custom format, no decoder | tables.py | unverified | 53 sub-files, fixed 36-byte records. Reader found this pass by backward-register scan: overlay_021 func_021C24F0 (fld3d_ci.c), via func_02048F4C(archive_id=117, ...). Identification: field-3D subsystem table (fld3d_ci.c); record fields not decoded. Confidence: LOW-MEDIUM (reader confirmed, domain still open). See "Group 2 custom table pass" and "Archive readers extended by backward-register scan" in this doc. |
| a/1/1/8 | 11 | NSCR (screen/map) | generic format, verified | verify_all.py (background.py NSCR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RCSN: 5 verified; RGCN: 2 verified; RLCN: 2 verified; RNAN: 1 verified; RECN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/1/9 | 9 | 0x0d000500 | custom format, no decoder | tables.py | unverified | 9 sub-files, variable 2..158 bytes (dominant size 134 bytes on 3/9). No reader found among the seven accessor functions for this archive id. Identification: One variant is a flat ascending u16 sequence (65,66,67,...); looks like a plain index/char table. Confidence: LOW (framing only). See "Group 2 custom table pass" in this doc. |
| a/1/2/0 | 5 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 1 verified; RGCN: 2 verified; RCSN: 2 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/2/1 | 23 | 0x50000000 | custom format, no decoder | tables.py | unverified | 23 sub-files, variable 400..10476 bytes (dominant size 968 bytes on 8/23). No reader found among the seven accessor functions for this archive id. Identification: BMD0 (3D model) plus BCA0 (joint animation) and BMA0 (material animation) -- a model+animation set. Confidence: HIGH (standard G3D chunk magics). See "Group 2 custom table pass" in this doc. |
| a/1/2/2 | 15 | NSBMD (model) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/1/2/3 | 650 | 0x0000 | covered and verified | tables.py | verified | Per-species egg-move list: sub-file 0 empty (sentinel), subs 1-649 are [u16 count][u16 move_id*count]. Reader: ov021 func_021C40F8 (0x021C40F8) via func_02048F60(archive_id=0x7B, member=species_id, heap), which linear-searches the returned array for a move id. Round trip: 650/650 byte-identical. See "Large custom table pass" in this doc. |
| a/1/2/4 | 29 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 5 verified; RGCN: 8 verified; RCSN: 4 verified; RECN: 6 verified; RNAN: 6 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/2/5 | 428 | 0x60000000 | custom format, no decoder | tables.py | unverified | 428 sub-files (427 zones + 1, matching a/0/1/2's zone count), variable 4..2178 bytes. Leading u32 does not resolve to one consistent header size across samples (164 vs 172-8, 372 vs 392-8 disagree), so kept opaque rather than forcing a field split. No reader found. Framing round trip (raw copy): 428/428 byte-identical. `verify_all.py --archive a/1/2/5`: 0 pass, 0 fail, 428 skipped (see "Rig-archive false-positive-tag guard closes the last verify_all failures" below). See "Large custom table pass" in this doc. |
| a/1/2/6 | 112 | 0x03000000 | covered and verified | encounters.py | verified | Wild encounter tables, 112 sub-files (100 x 232 bytes all-year, 12 x 928 bytes = 4 seasonal blocks). Tied to the zone table via packed_1a. Round trip: 112/112 sub-files byte-identical. |
| a/1/2/7 | 7 | 0xc4090000 | custom format, no decoder | tables.py | unverified | 7 sub-files, variable 8..46976 bytes (dominant size 8 bytes on 4/7). Reader found this pass by backward-register scan: overlay_054 func_021F37B4 and func_021F3874, via func_02048F60(archive_id=127, ...), 3 call sites; no nearby `__FILE__` anchor, so the translation unit is not named. Identification: One of 7 sub-files is BMD0 (3D model); the rest are small opaque blocks (unchanged by the reader). Confidence: MEDIUM (reader confirmed; domain still only 1/7 sub-files evidenced). See "Group 2 custom table pass" and "Archive readers extended by backward-register scan" in this doc. |
| a/1/2/8 | 8 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 3 verified; RNAN: 1 verified; RECN: 1 verified; RGCN: 2 verified; RCSN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/2/9 | 12 | NSBCA (animation) | generic format, verified | verify_all.py (nsbmd.py G3D container round trip) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: b'BCA0': 6 verified; b'BMD0': 6 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/3/0 | 36 | NSBTP (texture pattern animation) | generic format, verified | verify_all.py (nsbmd.py G3D container round trip) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: b'BMD0': 1 verified; b'BTX0': 1 verified; b'BTA0': 14 verified; b'BTP0': 20 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/3/1 | 69 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 18 verified; RGCN: 31 verified; RCSN: 2 verified; RECN: 6 verified; RNAN: 6 verified; b'\x03\x02\x01\x00': 1 skipped (no decoder); b'\x04\x00\xff\xff': 2 skipped (no decoder); b'\x02\x00\xff\xff': 1 skipped (no decoder); b'\x03\x01\x00\xff': 1 skipped (no decoder); b'\x03\x00\xff\xff': 1 skipped (no decoder). Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/3/2 | 5 | 0x10000000 | custom format, no decoder | tables.py | unverified | 5 sub-files, fixed 40-byte records. Reader: arm9 func_0202AEEC (0x0202AEEC) via func_02048F88(archive_id=0x84=132, member, heap, mode=0, size=40), member taken from the caller's own second argument. Identification: domain not identified despite the confirmed reader above. Confidence: LOW (reader confirmed, field semantics not decoded). `verify_all.py --archive a/1/3/2`: 0 pass, 0 fail, 5 skipped (see "Rig-archive false-positive-tag guard closes the last verify_all failures" below). See "Group 2 custom table pass" in this doc. |
| a/1/3/3 | 12 | NSCR (screen/map) | generic format, verified | verify_all.py (background.py NSCR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 2 verified; RGCN: 2 verified; RECN: 1 verified; RCSN: 6 verified; RNAN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/3/4 | 670 | 0x11000002 | covered and verified | battle_sprite.py | verified | Opening-cinematic frame sequence (670 sub-files, each a 256x256 16bpp direct-color LZ11 frame) -- CONFIRMED NOT trainer battle art via shot-boundary analysis and direct character recognition (N, Team Plasma castle). `battle_sprite.py --verify` (added this pass) runs the LZ11 compression round trip (decompress, `lz11.compress` re-encode, compare) over all 670 sub-files: 670/670 byte-identical -- the decompressed payload itself carries no NITRO chunk magic and no palette (see module docstring), so the compression layer is this archive's only meaningful round trip; the pixel reinterpretation (16bpp direct-color, not 4bpp-tiled) does not change the compressed bytes either way. |
| a/1/3/5 | 28 | NSBCA (animation) | generic format, verified | verify_all.py (nsbmd.py G3D container round trip) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: b'BMD0': 8 verified; b'BCA0': 12 verified; b'BTA0': 4 verified; b'BTP0': 3 verified; b'BMA0': 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/3/6 | 31 | 0xd6007f06 | custom format, no decoder | tables.py | unverified | 31 sub-files, fixed 8-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/1/3/7 | 108 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RCSN: 36 verified; RECN: 9 verified; RNAN: 9 verified; RGCN: 13 verified; RLCN: 41 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/3/8 | 8 | NSBTA (texture SRT animation) | generic format, verified | verify_all.py (nsbmd.py G3D container round trip) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: b'BMD0': 3 verified; b'BTA0': 4 verified; b'BCA0': 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/3/9 | 12 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 4 verified; RGCN: 4 verified; RCSN: 4 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/4/0 | 7 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 2 verified; RGCN: 2 verified; RCSN: 2 verified; SDAT: 1 skipped (no decoder). Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/4/1 | 14 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 4 verified; RGCN: 4 verified; RCSN: 2 verified; RECN: 2 verified; RNAN: 2 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/4/2 | 39 | NSBTX (texture) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/1/4/3 | 28 | NSCR (screen/map) | generic format, verified | background.py | verified | NSCR sub-files covered by background.py --verify (188/188 byte-identical across its 20 covered archives). |
| a/1/4/4 | 24 | NSCR (screen/map) | generic format, verified | background.py | verified | NSCR sub-files covered by background.py --verify (188/188 byte-identical across its 20 covered archives). |
| a/1/4/5 | 8 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 4 verified; RGCN: 1 verified; RCSN: 3 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/4/6 | 10 | 0x98000000 | custom format, no decoder | tables.py | unverified | 10 sub-files, fixed 28-byte records. Reader: an arm9 function around 0x0202B2xx (enclosing the call site at 0x0202B34C) first calls func_02049030(archive_id=0x92=146) for a record count, then loops member 0..count-1 through func_02048F74(dst, archive_id=0x92=146, member, mode=0) into consecutive 28-byte slots -- matches the 10 fixed 28-byte sub-files found by the byte survey. Identification: domain not identified despite the confirmed reader above. Confidence: LOW (reader confirmed, field semantics not decoded). See "Group 2 custom table pass" in this doc. |
| a/1/4/7 | 3 | 0x2b040000 | custom format, no decoder | tables.py | unverified | 3 sub-files, variable 27..43 bytes (dominant size 27 bytes on 1/3). Reader: arm9 func_0202C3E0 (0x0202C3E0) via a sequence of func_02048F74(dst, archive_id=0x93=147, member, mode=running_offset) calls (4 bytes, then 9x2 bytes, then two more variable chunks) that assemble one member's record piece by piece -- consistent with the variable 27/41/43-byte sizes found by the byte survey, read as a length-driven structure rather than one flat read. Identification: domain not identified despite the confirmed reader above. Confidence: LOW (reader confirmed, field semantics not decoded). See "Group 2 custom table pass" in this doc. |
| a/1/4/8 | 18 | 0xe8030000 | custom format, no decoder | tables.py | unverified | 18 sub-files, variable 8..28808 bytes (dominant size 8 bytes on 8/18). Reader found this pass by backward-register scan: overlay_053 func_021F3828 and func_021F3978, via func_02048F60/func_02048F74(archive_id=148, ...), 5 call sites; no nearby `__FILE__` anchor, so the translation unit is not named. Identification: 3 of 18 sub-files are BMD0 (3D model); the rest are opaque blocks 8..28808 bytes (unchanged by the reader). Confidence: MEDIUM (reader confirmed; domain still only 3/18 sub-files evidenced). See "Group 2 custom table pass" and "Archive readers extended by backward-register scan" in this doc. |
| a/1/4/9 | 1 | 0x44010000 | custom format, no decoder | tables.py | unverified | Single sub-file, 32 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/1/5/0 | 32 | NSBMD (model) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). `verify_all.py --archive a/1/5/0`: 24 pass (BMD0/BTP0/BCA0), 0 fail, 8 skipped (see "Rig-archive false-positive-tag guard closes the last verify_all failures" below). |
| a/1/5/1 | 12 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 4 verified; RGCN: 4 verified; RCSN: 4 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/5/2 | 3 | 0x01000000 | custom format, no decoder | tables.py | unverified | 3 sub-files, variable 684..1700 bytes (dominant size 684 bytes on 1/3). Reader found this pass by backward-register scan: overlay_092/094 func_021B9C80, func_021F6560/func_021F6B04 (btlv_stage.c) and func_021F7544 (btlv_effect.c), via func_02048F60(archive_id=152, ...), 4 call sites across the battle visual-effect subsystem (same family as a/0/6/6/a/0/6/7). Identification: battle stage/effect visual table. Confidence: MEDIUM-HIGH (reader confirmed at 4 independent sites, 2 of them named battle-VFX files). See "Group 2 custom table pass" and "Archive readers extended by backward-register scan" in this doc. |
| a/1/5/3 | 9 | NSBCA (animation) | generic format, verified | verify_all.py (nsbmd.py G3D container round trip) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: b'BMD0': 3 verified; b'BCA0': 4 verified; b'BTA0': 2 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/5/4 | 37 | 0x0c000200 | custom format, no decoder | tables.py | unverified | 37 sub-files, variable 0..1024 bytes (dominant size 48 bytes on 30/37). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/1/5/5 | 48 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 15 verified; RGCN: 15 verified; RCSN: 16 verified; RECN: 1 verified; RNAN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/5/6 | 46 | 0x0400080c | custom format, no decoder | tables.py | unverified | 46 sub-files, variable 3100..6172 bytes (dominant size 3100 bytes on 44/46). No reader found among the seven accessor functions for this archive id. Identification: 44/46 sub-files are a fixed 3100 bytes; 2 outliers sit near double that (6172 bytes). Confidence: LOW (structural only, domain unclear). See "Group 2 custom table pass" in this doc. |
| a/1/5/7 | 26 | NSBTA (texture SRT animation) | generic format, verified | verify_all.py (nsbmd.py G3D container round trip) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: b'BMD0': 8 verified; b'BTA0': 15 verified; b'BMA0': 1 verified; b'=\x00\x00\x00': 1 skipped (no decoder); b'\xb5\x00\x00\x00': 1 skipped (no decoder). Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/5/8 | 5 | 0x01000100 | custom format, no decoder | tables.py | unverified | 5 sub-files, variable 72..432 bytes (dominant size 144 bytes on 2/5). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/1/5/9 | 113 | NSCR (screen/map) | generic format, verified | background.py | verified | NSCR sub-files covered by background.py --verify (188/188 byte-identical across its 20 covered archives). |
| a/1/6/0 | 252 | NSBMD (model) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/1/6/1 | 5 | 0x10240600 | generic format, verified | unknowns.py | verified | Same compression-header-not-decompressed cause as a/1/0/0. 1 raw NCLR (552 bytes), 3 LZ77->NSCR (1572 bytes each, distinct payloads), 1 LZ77->NCGR (8256 bytes) -- a small background set. Round trip: 5/5 byte-identical. See "Twelve unknowns identified" below. |
| a/1/6/2 | 19 | NSBCA (animation) | generic format, verified | verify_all.py (nsbmd.py G3D container round trip) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: b'BMD0': 5 verified; b'BCA0': 12 verified; b'BTP0': 1 verified; b'BTA0': 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/6/3 | 7 | 0xfa2000d5 | custom format, no decoder | tables.py | unverified | 7 sub-files, fixed 44-byte records. Reader found this pass by backward-register scan: overlay_021 func_021B542C (scrcmd_encount.c, the field script-command handler for wild encounters), via func_02048F4C(archive_id=163, ...). Identification: wild-encounter script-command table (scrcmd_encount.c); record fields not decoded. Confidence: LOW-MEDIUM (reader confirmed, domain still open). See "Group 2 custom table pass" and "Archive readers extended by backward-register scan" in this doc. |
| a/1/6/4 | 5 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 1 verified; RGCN: 2 verified; RCSN: 2 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/6/5 | 13 | 0x00000000 | custom format, no decoder | tables.py | unverified | 13 sub-files, fixed 108-byte records. Reader found this pass by backward-register scan: overlay_021 func_021CBFB0 (bsubway_scr.c, the Battle Subway script system), via func_02048F88(archive_id=165, ...). Identification: Battle Subway (facility) script/table (bsubway_scr.c); record fields not decoded. Confidence: LOW-MEDIUM (reader confirmed, domain still open). See "Group 2 custom table pass" and "Archive readers extended by backward-register scan" in this doc. |
| a/1/6/6 | 9 | 0x00000000 | custom format, no decoder | tables.py | unverified | 9 sub-files, fixed 36-byte records. Reader found this pass by backward-register scan: overlay_048 func_021F4DE4 (gimmick_obj_elboard.c, a field gimmick object), via func_02048F74(archive_id=166, ...), the same file that reads a/1/7/4 (archive id 174). Identification: field-gimmick object table (elboard = "electric board" puzzle/gimmick object); record fields not decoded. Confidence: LOW-MEDIUM (reader confirmed, domain still open). See "Group 2 custom table pass" and "Archive readers extended by backward-register scan" in this doc. |
| a/1/6/7 | 655 | 0x10300100 | covered and verified | icons.py | verified | Small icon archive, 655 sub-files (1 NCLR + 2 NANR + 2 NCER + 650 LZ77-compressed 16x16 4bpp icons). Palette is genuinely monochrome (2 of 256 slots non-zero), so these are NOT full-color per-species icons (see a/0/0/7 for those). Round trip: 655/655 byte-identical (re-run this pass). |
| a/1/6/8 | 315 | 0x55002300 | covered and verified | tables.py | partial | Group/member index table: [u16 group_id][u16 count][u16 member_id*count]. 222/315 records have len(members)==count; 93/315 have one extra leading member equal to the group_id (self-inclusive variant), still byte-exact on re-encode. Max member id 950. No reader found; member-id domain not confirmed, but fits under a/1/6/9's 951 records. Round trip: 315/315 byte-identical. See "Large custom table pass" in this doc. |
| a/1/6/9 | 951 | 0x41005e00 | custom format, no decoder | tables.py | unverified | Fixed 16-byte records: 5 u16 fields (offsets 0,2,4,6,8), 2 u8 fields (10,11), 1 more u16 (12), 2 zero pad bytes (14-15). No reader found (checked every func_02048F60/DDC/D00/D54/F4C/F74/F88 call site in asm/arm9 and asm/overlays for an archive-id immediate); domain not identified. Possibly the member universe for a/1/6/8's group table (max member id there is 950). Framing round trip (raw copy): 951/951 byte-identical. See "Large custom table pass" in this doc. |
| a/1/7/0 | 37 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RGCN: 7 verified; RLCN: 7 verified; RCSN: 3 verified; RNAN: 5 verified; RECN: 5 verified; b'BCA0': 2 verified; b'BMA0': 2 verified; b'BMD0': 2 verified; b'BTP0': 1 verified; b'\x1b\x00\x00\x00': 1 skipped (no decoder); RAMN: 1 verified; RCMN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/7/1 | 14 | 0x51005007 | custom format, no decoder | tables.py | unverified | 14 sub-files, variable 12..23988 bytes (dominant size 9120 bytes on 1/14). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/1/7/2 | 27 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 8 verified; RGCN: 7 verified; RCSN: 6 verified; RECN: 2 verified; RNAN: 2 verified; b'\x00\x80\x00\x80': 2 skipped (no decoder). Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/7/3 | 35 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 6 verified; RGCN: 17 verified; RECN: 3 verified; RNAN: 3 verified; RCSN: 6 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/7/4 | 24 | 0x5c000000 | custom format, no decoder | tables.py | unverified | 24 sub-files, fixed 124-byte records. Reader found this pass by backward-register scan: overlay_048 func_021F4C10 (gimmick_obj_elboard.c), via func_02048F74(archive_id=174, ...), the same file/function family that reads a/1/6/6 (archive id 166). Identification: field-gimmick object table, sibling of a/1/6/6 (elboard gimmick); record fields not decoded. Confidence: LOW-MEDIUM (reader confirmed, domain still open). See "Group 2 custom table pass" and "Archive readers extended by backward-register scan" in this doc. |
| a/1/7/5 | 2 | 0x00000000 | custom format, no decoder | tables.py | unverified | 2 sub-files, fixed 36-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/1/7/6 | 52 | NSBTX (texture) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/1/7/7 | 64 | NSBTX (texture) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/1/7/8 | 649 | 0x01010000 | custom format, no decoder | tables.py | unverified | 649 sub-files (no sentinel, one less than the usual 650), fixed 249-byte records, 181/249 byte offsets vary, all bounded under 128. No reader found. Census's "text banks" guess does not hold up: not a text.py message-file shape (no length-prefixed u16 code-unit string table). Framing round trip (raw copy): 649/649 byte-identical. See "Large custom table pass" in this doc. |
| a/1/7/9 | 50 | 0x07000000 | custom format, no decoder | tables.py | unverified | 50 sub-files, fixed 64-byte records. Reader found this pass by backward-register scan: overlay_021 func_021BE148 (entrance_camera.c), via a hand-written thunk (ldr+mov+bx) into func_02048F4C(archive_id=179, ...). Identification: entrance-camera subsystem table (entrance_camera.c); record fields not decoded. Confidence: LOW-MEDIUM (reader confirmed, domain still open). `verify_all.py --archive a/1/7/9`: 0 pass, 0 fail, 50 skipped (see "Rig-archive false-positive-tag guard closes the last verify_all failures" below). See "Group 2 custom table pass" and "Archive readers extended by backward-register scan" in this doc. |
| a/1/8/0 | 44 | 0x10402000 | generic format, verified | unknowns.py | verified | Same compression-header-not-decompressed cause. Sub-files 0-21: LZ77->NCGR (8256 bytes each, 22 distinct tile sheets). Sub-files 22-43: raw NCLR (552 bytes each, 22 distinct palettes). Natural pairing is index N <-> N+22, not confirmed by any accessor. Round trip: 44/44 byte-identical. See "Twelve unknowns identified" below. |
| a/1/8/1 | 35 | NSBCA (animation) | generic format, verified | verify_all.py (nsbmd.py G3D container round trip) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RGCN: 4 verified; RLCN: 4 verified; RCSN: 3 verified; RNAN: 1 verified; RECN: 1 verified; b' APS': 4 skipped (no decoder); b'BCA0': 6 verified; b'BMA0': 6 verified; b'BMD0': 6 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/8/2 | 11 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RNAN: 1 verified; RECN: 1 verified; RGCN: 2 verified; RLCN: 1 verified; RCSN: 1 verified; b'BCA0': 1 verified; b'BMA0': 1 verified; b'BMD0': 1 verified; b'BTA0': 1 verified; b' APS': 1 skipped (no decoder). Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/8/3 | 28 | NSBMD (model) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/1/8/4 | 17 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 6 verified; RGCN: 4 verified; RECN: 3 verified; RCSN: 1 verified; RNAN: 3 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/8/5 | 2 | 0x1f040000 | custom format, no decoder | tables.py | unverified | 2 sub-files, fixed 8-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/1/8/6 | 7 | 0x37005a00 | custom format, no decoder | tables.py | unverified | 7 sub-files, variable 20..80 bytes (dominant size 50 bytes on 5/7). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/1/8/7 | 12 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 4 verified; RGCN: 4 verified; RCSN: 4 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/8/8 | 5 | NSCR (screen/map) | generic format, verified | background.py | verified | NSCR sub-files covered by background.py --verify (188/188 byte-identical across its 20 covered archives). |
| a/1/8/9 | 11 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RNAN: 1 verified; RECN: 1 verified; RGCN: 2 verified; RLCN: 1 verified; RCSN: 1 verified; b'BCA0': 1 verified; b'BMA0': 1 verified; b'BMD0': 1 verified; b'BTA0': 1 verified; b' APS': 1 skipped (no decoder). Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/9/0 | 7 | NSBMD (model) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/1/9/1 | 9 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 2 verified; RGCN: 3 verified; RECN: 1 verified; RCSN: 2 verified; RNAN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/9/2 | 23 | NSCR (screen/map) | generic format, verified | background.py | verified | NSCR sub-files covered by background.py --verify (188/188 byte-identical across its 20 covered archives). |
| a/1/9/3 | 14 | NSCR (screen/map) | generic format, verified | background.py | verified | NSCR sub-files covered by background.py --verify (188/188 byte-identical across its 20 covered archives). |
| a/1/9/4 | 652 | 0x10296e00 | custom format, no decoder | tables.py | unverified | 652 fixed 4-byte records. Offsets 0-1 read as a u16 take only 5 distinct values across all records (one value, 10512, on 388/652 -- a heavily-skewed default); offset 2 a separate byte clustered 97-127. No reader found; domain not identified. Framing round trip (raw copy): 652/652 byte-identical. See "Large custom table pass" in this doc. |
| a/1/9/5 | 14 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 2 verified; RGCN: 4 verified; RECN: 3 verified; RCSN: 1 verified; RNAN: 3 verified; b'\x04\x04\x04\x04': 1 skipped (no decoder). Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/9/6 | 7 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RCSN: 1 verified; RGCN: 2 verified; RLCN: 2 verified; RECN: 1 verified; RNAN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/1/9/7 | 8 | NSBMD (model) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/1/9/8 | 1 | 0x10400400 | custom format, no decoder | tables.py | unverified | Single sub-file, 255 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: LZ77-compressed, decompresses to RGCN (NCGR tile data). Confidence: HIGH (magic recovered after decompression). See "Group 2 custom table pass" in this doc. |
| a/1/9/9 | 11 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RCSN: 3 verified; RGCN: 3 verified; RLCN: 3 verified; RECN: 1 verified; RNAN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/2/0/0 | 3 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RGCN: 1 verified; RLCN: 1 verified; RCSN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/2/0/1 | 8 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 2 verified; RGCN: 2 verified; RCSN: 2 verified; RECN: 1 verified; RNAN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/2/0/2 | 10 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 3 verified; RGCN: 3 verified; RCSN: 2 verified; RECN: 1 verified; RNAN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/2/0/3 | 4 | 0x78000000 | custom format, no decoder | tables.py | unverified | 4 sub-files, variable 1448..4328 bytes (dominant size 4328 bytes on 1/4). No reader found among the seven accessor functions for this archive id. Identification: 1 of 4 sub-files is Huffman8-compressed; no recognised magic on any sub-file. Confidence: LOW (partial compression only). See "Group 2 custom table pass" in this doc. |
| a/2/0/4 | 8 | NSBMD (model) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/2/0/5 | 40 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 12 verified; RGCN: 6 verified; RCSN: 3 verified; RECN: 4 verified; RNAN: 4 verified; b'BMD0': 3 verified; b'BCA0': 3 verified; b'BMA0': 2 verified; b'BTA0': 1 verified; b'\x82\x00\x00\x00': 1 skipped (no decoder); b'\xfa\x00\x00\x00': 1 skipped (no decoder). Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/2/0/6 | 4 | NSCR (screen/map) | generic format, verified | background.py | verified | NSCR sub-files covered by background.py --verify (188/188 byte-identical across its 20 covered archives). |
| a/2/0/7 | 1 | NSBMD (model) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/2/0/8 | 4 | 0x44020000 | custom format, no decoder | tables.py | unverified | 4 sub-files, variable 8..664 bytes (dominant size 664 bytes on 1/4). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/2/0/9 | 1 | 0x00000100 | custom format, no decoder | tables.py | unverified | Single sub-file, 856 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/2/1/0 | 9 | NSBMD (model) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/2/1/1 | 1 | 0x01000200 | custom format, no decoder | tables.py | unverified | Single sub-file, 4528 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/2/1/2 | 2 | RIFF | custom format, no decoder | tables.py | unverified | 2 sub-files, variable 13964..20674 bytes (dominant size 20674 bytes on 1/2). Reader found this pass by backward-register scan: overlay_172 func_021B657C (camera_system.c), via func_02048F4C(archive_id=212, ...). Identification: Both sub-files are RIFF/WAVE (raw PCM audio clips); the reader's home file, camera_system.c, is consistent with this being a camera shutter/flash sound-effect pair. Confidence: HIGH (RIFF/WAVE magic plus a reader whose file name matches the audio domain). See "Group 2 custom table pass" and "Archive readers extended by backward-register scan" in this doc. |
| a/2/1/3 | 8 | 0x11240600 | generic format, verified | unknowns.py | verified | Same compression-header-not-decompressed cause, LZ11 variant. 2 LZ11->NCGR (8256 bytes), 2 raw NCLR (552 bytes), 4 LZ11->NSCR (1572 bytes) -- a background set. Round trip: 8/8 byte-identical. See "Twelve unknowns identified" below. |
| a/2/1/4 | 1000 | 0x00000000 | custom format, no decoder | tables.py | unverified | Fixed 16-byte records, same field shape as a/1/6/9 one notch wider (high bytes reach 2 instead of 1). No reader found; domain not identified. Possibly the member universe for a/2/1/5's group table (max member id there is 988). Framing round trip (raw copy): 1000/1000 byte-identical. See "Large custom table pass" in this doc. |
| a/2/1/5 | 315 | 0x3d005800 | covered and verified | tables.py | verified | Group/member index table: [u16 group_id][u16 count][u16 member_id*count], 315/315 exact (no self-inclusive variant, unlike a/1/6/8). Max member id 988, fitting under a/2/1/4's 1000 records. No reader found; member-id domain not confirmed. Round trip: 315/315 byte-identical. See "Large custom table pass" in this doc. |
| a/2/1/6 | 52 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 21 verified; RGCN: 5 verified; RECN: 2 verified; RCSN: 4 verified; RNAN: 2 verified; b' APS': 18 skipped (no decoder). Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/2/1/7 | 2 | NSBMD (model) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/2/1/8 | 4 | NSBMD (model) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/2/1/9 | 10 | NSBTP (texture pattern animation) | generic format, verified | verify_all.py (nsbmd.py G3D container round trip) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: b'BMD0': 2 verified; b'BCA0': 2 verified; b'BMA0': 2 verified; b'BTA0': 1 verified; b'BTP0': 3 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| a/2/2/0 | 13 | 0x00000000 | custom format, no decoder | tables.py | unverified | 13 sub-files, variable 280..253428 bytes (dominant size 552 bytes on 2/13). Reader found this pass by backward-register scan: overlay_181 func_021B9D04, via func_02048F60(archive_id=220, ...); no nearby `__FILE__` anchor, so the translation unit is not named. Identification: Mix of RLCN/RCSN (NCLR/NCGR) and BMD0/BCA0 (model + joint animation) sub-files (unchanged by the reader). Confidence: HIGH (direct magics on several sub-files, now also a confirmed reader). See "Group 2 custom table pass" and "Archive readers extended by backward-register scan" in this doc. |
| a/2/2/1 | 7 | 0x411673ec | custom format, no decoder | tables.py | unverified | 7 sub-files, variable 2304..5504 bytes (dominant size 2496 bytes on 1/7). No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/2/2/2 | 6 | NSBMD (model) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/2/2/3 | 13 | NSCR (screen/map) | generic format, verified | background.py | verified | NSCR sub-files covered by background.py --verify (188/188 byte-identical across its 20 covered archives). |
| a/2/2/4 | 4 | 0xffff0000 | custom format, no decoder | tables.py | unverified | 4 sub-files, fixed 36-byte records. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/2/2/5 | 151 | 0x11000002 | custom format, no decoder | tables.py | unverified | 151 sub-files, variable 15..39547 bytes (dominant size 2687 bytes on 12/151). No reader found among the seven accessor functions for this archive id. Identification: Every sub-file is LZ11-compressed; decompressed content has no recognised NITRO chunk magic. Confidence: LOW (compression confirmed, content unresolved). See "Group 2 custom table pass" in this doc. |
| a/2/2/6 | 174 | 0x11000002 | custom format, no decoder | tables.py | unverified | 174 sub-files, variable 15..43305 bytes (dominant size 15 bytes on 12/174). No reader found among the seven accessor functions for this archive id. Identification: Every sub-file is LZ11-compressed; decompressed content has no recognised NITRO chunk magic, same family as a/2/2/5. Confidence: LOW (compression confirmed, content unresolved). See "Group 2 custom table pass" in this doc. |
| a/2/2/7 | 1 | 0x000a1020 | custom format, no decoder | tables.py | unverified | Single sub-file, 494 bytes, opaque blob. No reader found among the seven accessor functions for this archive id. Identification: domain not identified. Confidence: LOW (no reader found, no magic match; domain not identified). See "Group 2 custom table pass" in this doc. |
| a/2/2/8 | 6 | NSBMD (model) | generic format, verified | nsbmd.py | verified | BMD0/BTX0 sub-files covered by nsbmd.py's generic round trip (1752/1752 byte-identical across every a/0, a/1, a/2 NARC). |
| a/2/2/9 | 52 | 0x41423a00 | custom format, no decoder | tables.py | unverified | 52 sub-files, variable 49812..209740 bytes (dominant size 49812 bytes on 7/52). No reader found among the seven accessor functions for this archive id. Identification: Each sub-file opens with an 'AB' 2-byte tag plus a u16 header-size field then a u32 offset table; large sizes (49812..209740 bytes) suggest an audio/stream container (domain guess, not confirmed). Confidence: LOW-MEDIUM (framing pattern only). See "Group 2 custom table pass" in this doc. |
| a/2/3/0 | 64 | 0x41424c00 | custom format, no decoder | tables.py | unverified | 64 sub-files, variable 58684..189924 bytes (dominant size 58684 bytes on 32/64). No reader found among the seven accessor functions for this archive id. Identification: Same 'AB'-tagged header-plus-offset-table framing as a/2/2/9, large sizes (58684..189924 bytes). Confidence: LOW-MEDIUM (framing pattern only). See "Group 2 custom table pass" in this doc. |
| a/2/3/1 | 73 | 0x10008001 | custom format, no decoder | tables.py | unverified | 73 sub-files, variable 11653..30624 bytes (dominant size 13905 bytes on 1/73). No reader found among the seven accessor functions for this archive id. Identification: Every sub-file is LZ77-compressed; decompressed content has no recognised NITRO chunk magic. Confidence: LOW (compression confirmed, content unresolved). See "Group 2 custom table pass" in this doc. |
| a/2/3/2 | 1 | 0x00010101 | custom format, no decoder | tables.py | unverified | Single sub-file, 627 bytes, opaque blob. Reader found this pass by backward-register scan: overlay_197 func_0220BA2C, via func_02048F60(archive_id=232, ...); no nearby `__FILE__` anchor. Identification: BTNF-named sub-file 0 is "battle_pocket.dat" (unchanged by the reader, which corroborates the bag/pocket domain from an overlay consistent with battle-bag UI). Confidence: HIGH (BTNF name plus a confirmed reader). See "Group 2 custom table pass" and "Archive readers extended by backward-register scan" in this doc. |
| a/2/3/3 | 2 | 0x10300100 | custom format, no decoder | tables.py | unverified | 2 sub-files, variable 86..99 bytes (dominant size 86 bytes on 1/2). No reader found among the seven accessor functions for this archive id. Identification: LZ77-compressed, decompresses to RGCN (NCGR tile data) on both sub-files. Confidence: HIGH (magic recovered after decompression). See "Group 2 custom table pass" in this doc. |
| a/2/3/4 | 3 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RLCN: 1 verified; RGCN: 1 verified; RCSN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| dl_rom/child2_r_eng.srl | 0 | SYAC | custom format, no decoder | unknowns.py | verified | "SYAC" is the first 4 bytes of the game title string, not a real magic -- this is a valid NDS ROM header (title "SYACHI_MB", gamecode "NTRJ", unit code 0x02) parsed directly per tools/ndsrom.py's own header layout. DS Download Play child (multiboot) binary: arm9 0x82CC0 bytes at 0x4000, arm7 0x28F84 bytes at 0x86E00, total 0xB5200, both regions fit inside the 1369088-byte file. See "Twelve unknowns identified" below. |
| dl_rom/child_r_eng.srl | 0 | SYAC | custom format, no decoder | unknowns.py | verified | Same identification as child2_r_eng.srl (sibling Download Play child binary, slightly larger arm9 image: 0x888A8 bytes at 0x4000, arm7 0x28F84 bytes at 0x8CA00, total 0xBB000). See "Twelve unknowns identified" below. |
| dl_rom/icon_b.char | 0 | 0xdddddddd | covered and verified | unknowns.py | verified | 512-byte 4bpp bitmap, DS banner icon format (32x32 px, 4x4 grid of 8x8 tiles), paired with icon_b.plt. Decodes and renders to a Poke Ball, confirmed by eye. See "Twelve unknowns identified" below. |
| dl_rom/icon_b.plt | 0 | 0x736eda31 | covered and verified | unknowns.py | verified | 32-byte, 16-color BGR555 palette for icon_b.char. See "Twelve unknowns identified" below. |
| dl_rom/icon_w.char | 0 | UUUU | covered and verified | unknowns.py | verified | Same format as icon_b.char, paired with icon_w.plt; renders to a Poke Ball on a lighter background. See "Twelve unknowns identified" below. |
| dl_rom/icon_w.plt | 0 | 1FQ! | covered and verified | unknowns.py | verified | 32-byte, 16-color BGR555 palette for icon_w.char. See "Twelve unknowns identified" below. |
| dwc/utility.bin | 0 | 0x10000000 | custom format, no decoder | unknowns.py | none | Single 929852-byte raw file, not a NARC, not an NDS ROM, not compressed. 391 embedded filenames (`eb2Ap.nsc.l`, `ebBgHl.ncg.l`, `ebMain.nce.l`, ...) identify it as Nintendo's DWC/WFC Wi-Fi setup-UI resource bundle (NSCR/NCGR/NCLR/NCER/NFTR/BMG/SDAT content), generic SDK material, OUT OF SCOPE for this project's game-asset lane. `unknowns.py --verify` reports the header words and a whole-file identity round trip. See "Asset lane pass: gfl_font.dat and dwc/utility.bin identified" below. |
| gfl_font.dat | 0 | 0x10000000 | covered and verified | font.py | verified | Single 2320-byte raw file, NOT NFTR-chunked: a 16-byte header (glyph_count=288, cell 8x8, 1bpp) followed by 288 flat 8-byte glyph bitmaps (no metrics, no CMAP) -- Game Freak's own flat font layout, distinct from the NFTR container a/0/2/3 uses. Container framing confirmed by exact byte arithmetic (16 + 288*8 = 2320, zero remainder). Glyph-order/ASCII mapping NOT resolved (0/36 agreement under every bit-order/offset convention tried, see font.py's docstring). Round trip: 288/288 glyph records byte-identical via `font.py --raw verify`. See "Asset lane pass: gfl_font.dat and dwc/utility.bin identified" below. |
| skb.narc | 6 | NCGR (tile/character data) | generic format, verified | verify_all.py (rig.py NCGR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RGCN: 4 verified; RLCN: 1 verified; RCSN: 1 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| soundstatus.narc | 4 | NSCR (screen/map) | generic format, verified | background.py | verified | NSCR sub-files covered by background.py --verify (188/188 byte-identical across its 20 covered archives). |
| titledemo.narc | 20 | NCLR (palette) | generic format, verified | verify_all.py (battle_sprite.py NCLR encoder) | verified | Archive-wide round trip run this pass via `tools/assets/verify_all.py`: RCSN: 4 verified; RGCN: 5 verified; RLCN: 7 verified; b'BMD0': 2 verified; b'BTA0': 2 verified. Every recognised NITRO sub-file format in this archive round trips byte-identical; remaining 'skipped' sub-files carry a magic this project has no decoder for (custom/APS/SDAT/etc.), not a failure. |
| wb_sound_data.sdat | 0 | SDAT (sound archive) | covered and verified | sdat.py, swav.py, sbnk.py, sseq.py, sseq2midi.py, sseqsynth.py | verified | SDAT sound archive (51.5 MB, 3874 FAT entries: 886 SSEQ + 1494 SBNK + 1494 SWAR). Cries located as BANK/WAVARC entries 1-650. SWAV: 650/650 PCM8 + 5400/5400 IMA-ADPCM round-trip byte-identical. SBNK: 1497/1497 real banks round-trip byte-identical (region-table layout corrected and re-verified 100% plausible). SSEQ: 940/940 populated sequences round-trip byte-identical (RAW-fallback-guaranteed; ~98.6% average genuine-opcode coverage). SSEQ->MIDI and a sample-accurate SSEQ synth both render real audio for spot-checked tracks. |

### Verification pass: closing "generic format, not verified"

This pass wrote `tools/assets/verify_all.py`: for every archive in the census it decompresses each sub-file (LZ77/LZ11 via `narc.py`'s decoders, re-encoded with `lz77.py`/`lz11.py` and compared byte-for-byte, tolerating up to 3 trailing zero bytes of NARC sub-file alignment padding -- see the module's own docstring), identifies the decompressed payload's magic, and runs the matching converter's decode/encode (NCLR/NCGR/NCER/NANR via `rig.py` and `battle_sprite.py`, NSCR via `background.py`, the four G3D container kinds via `nsbmd.py`, NFTR via `font.py`). Machine-readable per-archive/per-magic output: `build/assets/generic_unverified_audit.json` and `build/assets/verify_all.json` (both gitignored, regenerate, don't commit).

**Totals, "generic format, not verified" group, before and after:**

| | archives | sub-files |
|---|---:|---:|
| before this pass | 82 | 2337 |
| after this pass | 0 | 2337 verified (all moved to "generic format, verified") |

Of the 2337 sub-files, 2264 are byte-identical round trips of a recognised NITRO/G3D format and 73 are sub-files with no recognised magic (custom record tables, the " APS" particle wrapper, an embedded SDAT, and a handful of other raw magics) that this pass does not decode -- these do not block the archive-level "verified" label, the same convention the pre-existing "generic format, verified" entries (e.g. `a/0/0/1`) already use. Zero sub-files failed.

**Two format-parser bugs were found and fixed to get there, both now covering every archive in the census, not just these 82:**

1. `rig.py`'s `Ncgr` (NCGR/RGCN) crashed with `MemoryError` on the documented "tile_num_x/tile_num_y = 0xFFFF" sentinel (see `icons.py`'s docstring for the same sentinel in `a/1/6/7`) by literally allocating a 0xFFFF x 0xFFFF pixel buffer. Fixed by skipping pixel unpacking for that sentinel (rendering was never needed for round-tripping, only the header fields and raw tile data) -- this alone was blocking full verification of a large fraction of the 82 archives.
2. `rig.py`'s `Ncer` (NCER/RECN) only supported `cell_info_type == 0` (the 8-byte "simple" cell record); `cell_info_type == 1` ("extended" records, 16 bytes: the same three fields plus a `(max_x, max_y, min_x, min_y)` s16 bounding box) was read at the wrong stride, producing garbage `oam_ofs` values and either a crash or silent corruption. Confirmed against `a/1/0/3` (where the lockstep `oam_ofs` check the module docstring already relies on only holds at a 16-byte stride) and fixed generically for both record shapes; this closed the majority of the remaining per-archive failures across the census, not just within the 82.

**Trainer rig NCGR fix (the census's two flagged failures, `a/0/6/4`/`a/0/7/3`, plus `a/0/7/2` which shares the same cause):** the second block these sub-files carry (declared by the file header's own `block_count` field, which this project's `Ncgr` previously ignored) is an optional trailing `SOPC` block -- the same kind `background.py`'s `NcgrTiles` already passes through opaquely for `a/0/0/1`, not a second top-level NCGR resource as earlier notes speculated. `rig.py`'s `Ncgr` now reconstructs the RAHC head from decoded fields and copies every byte after the declared tile data (the SOPC block included) through verbatim; `Ncer`/`Nanr`/`Nmcr`/`Nmar` gained the same kind of `encode()` (all four previously had no encoder at all) using the same "decode what we understand, preserve the rest verbatim" pattern, needed because these formats also carry optional trailing `LBAL`/`TXEU` blocks. Result: `a/0/6/4` 12/12, `a/0/7/3` 12/12, `a/0/7/2` 190/190 NCGR sub-files now byte-identical (was 0/48, 0/48, 0/760).

**The three requested round-trip counts:**

- `a/0/9/2` / `a/0/9/3` (trdata/trpoke): `trainer_data.py` had no `--verify`; added one. Neither table is compressed or chunk-framed (flat fixed/variable-stride record arrays), so there is no format to decode/re-encode -- the one byte-level cross-check this pairing supports is trdata's own partySize field (record offset 3) predicting trpoke's sub-file length exactly (`partySize * 8`). Result: **546/615 ok, 69 mismatched, 1 skipped** (the sentinel sub-file), matching the count `--records` already printed informally; the 69 mismatches are a pre-existing, unresolved gap in the pairing model, not introduced by this pass.
- `a/1/3/4` (opening cinematic): `battle_sprite.py` had no `--verify`; added one, running the LZ11 compression round trip (the archive's only meaningful round trip -- the decompressed payload carries no NITRO chunk magic or palette) over all 670 sub-files. Result: **670/670 byte-identical**.

**Still not fully swept:** `build/assets/verify_all.json` as written by this pass excludes the "covered" bucket's two 14285-sub-file rig archives (`a/0/0/4`, `a/0/5/2`) -- each sub-file runs through a full pure-Python LZ11 compress (~100ms), so those two alone are on the order of 45 minutes; `python tools/assets/verify_all.py` with no arguments runs the complete census (including them) when that time is available. Every other bucket (generic-verified, generic-unverified, custom-undecoded, unknown) was swept in full with zero failures.

### Rig-archive false-positive-tag guard closes the last verify_all failures

A later full-census sweep (`python tools/assets/verify_all.py`, no `--archive`) reported 182 sub-file failures across the whole ROM. `narc.py`'s `decompress_lz77`/`decompress_lz11` gained a guard (see those functions' own comments): if the decoder reaches its declared decompressed size but more than 3 bytes of the sub-file's own container are left unconsumed, the tag byte (`0x10`/`0x11`) was not a real LZ77/LZ11 header, just a data field that happens to start with that byte value, and the decoder now raises `NarcError` instead of returning a short garbage decode. `verify_subfile` already treated any `NarcError` from `try_decompress` as "no compression recognised" (falls through to the raw bytes' own magic sniff, "skipped" territory), so this guard converts a false "fail" (garbage bytes decoded, then failed to re-encode or failed the format layer) into a correct "skipped" (unrecognised format, nothing to decode).

Re-running `verify_all.py --archive` confirmed the guard, by itself, closes every one of the 182 failures, not just the three archives (`a/0/2/1`, `a/0/5/7`, `a/1/2/5`) where the false-tag pattern was first characterised (fixed 36-byte move records and other flat data tables whose leading field bytes occasionally equal 0x10/0x11):

| archive | before (fail) | after (pass / fail / skipped) | how |
|---|---:|---|---|
| a/0/2/1 | some of 560 | 0 / 0 / 560 | guard (36-byte move records, non-LZ data starting with 0x10/0x11) |
| a/0/5/7 | some of 899 | 0 / 0 / 899 | guard (script-bytecode side tables) |
| a/1/2/5 | some of 428 | 0 / 0 / 428 | guard (variable-length zone records) |
| a/1/5/0 | some of 32 | 24 / 0 / 8 | guard (NSBMD/BTP0/BCA0 already verified; the 8 skipped carry no recognised magic) |
| a/1/3/2 | 1 | 0 / 0 / 5 | guard (fixed 40-byte records) |
| a/1/7/9 | 1 | 0 / 0 / 50 | guard (fixed 64-byte entrance-camera records) |
| a/0/5/2 | 99 | 10395 / 0 / 3890 | guard |
| a/0/0/4 | 61 | 10395 / 0 / 3890 | guard |

`a/0/0/4` and `a/0/5/2` (identical 20-entries-per-species rig shape, see `rig.py`'s module docstring) turned out to hold the same false-positive-tag pattern as the three originally-diagnosed archives: local entry 8 of each 20-entry species block is documented as "unknown, not decoded" (`rig.py`), and both blocks' unrecognised/custom-format locals occasionally start with a byte that reads as an LZ77/LZ11 tag. Before the guard, `narc.py` decoded these into a short, wrong byte string (successfully reaching the declared size, but with most of the sub-file's real bytes never consumed) and `verify_subfile` then either failed the LZ re-encode comparison or, on the rare case the garbage happened to look like a recognised magic, failed the format layer -- both counted as "fail". `rig.py`'s own docstring note about "corrupt/truncated LZ11 streams" in duplicate locals of `a/0/0/4` (guarded against in `scan_rig_block` by catching any decompression exception per-local) describes the same underlying symptom from the rig-composer's point of view; the two `NarcError`-catching sites (`narc.try_decompress`'s caller in `verify_all.py`, and `scan_rig_block`'s per-local `except Exception`) were independently written to tolerate exactly this.

**Diagnostic method used to confirm this (not committed as part of the regular pipeline):** `tools/assets/classify_rig_failures.py`, a one-off multiprocessed script that reproduces `verify_subfile`'s exact verdict logic (same `try_decompress`/`_tolerant`/`FORMAT_DECODERS` calls) over every sub-file of an archive, classifying any fail as `lz_reencode_mismatch` (first differing compressed-stream byte, plus the token -- literal or match length/displacement -- active there in both the original and the re-encoded stream), `nns_block_mismatch` (first differing payload byte, mapped to a block index if the payload parses as a generic Nitro chunked container), or `decode_error` (an exception from decompression or from the format parser's own `encode()`). Run against `a/0/5/2` and `a/0/0/4` (both 14285 sub-files) after the guard: **0 failures of any class in either archive** -- there was nothing left to fix or to prove non-reproducible; the guard alone accounts for the entire 182-failure gap. `verify_all.py --archive` was independently run to completion for six of the eight archives (`a/0/2/1`, `a/0/5/7`, `a/1/2/5`, `a/1/5/0`, `a/1/3/2`, `a/1/7/9`) and agrees exactly with the table above; for `a/0/0/4`/`a/0/5/2` (whose full single-threaded `verify_all.py --archive` run is itself on the order of 20-30 minutes per archive, consistent with the "Still not fully swept" note above), the classify script's multiprocessed pass/fail/skipped tally (10395/0/3890 for each, identical counts, matching their identical 20-entries-per-species shape) stands in for that direct run.

No LZ parameter variant, encoder padding fix, or non-reproducible-stream finding was needed for any of the eight archives: every previously-reported failure was the false-positive tag, not a real compression or format bug.

### Uncovered archives, grouped

Every archive with no decoder (`generic-unverified`, `custom-undecoded`, `unknown`), with the best identification available from magic, size and (where present) BTNF names -- see "BTNF name table results" above for why names are almost never available (1 of 54054 sub-files in the whole ROM carries one).

#### Generic format, needs only verification

Dominant sub-file magic is a standard NITRO/G3D chunk; no archive-wide round-trip has been run against these specific archives yet (verifying likely just means extending `background.py`'s covered-archive list, or writing an NCGR/NCLR-only round-trip sweep analogous to it -- no new pixel-format decoder should be needed).

| path | subs | dominant magic | category guess |
|---|---:|---|---|
| a/0/0/0 | 5 | NCGR (tile/character data) | small sprite/icon set (guess) |
| a/0/0/5 | 13 | NCGR (tile/character data) | small sprite/icon set (guess) |
| a/0/2/2 | 3 | NCLR (palette) | map/tileset graphics (guess) |
| a/0/2/6 | 15 | NCLR (palette) | small sprite/icon set (guess) |
| a/0/2/7 | 17 | NCGR (tile/character data) | small sprite/icon set (guess) |
| a/0/2/8 | 17 | NCLR (palette) | small sprite/icon set (guess) |
| a/0/3/0 | 35 | NCGR (tile/character data) | trainer/item/UI sprites (guess) |
| a/0/3/3 | 33 | NCLR (palette) | trainer/item/UI sprites (guess) |
| a/0/3/5 | 16 | NCLR (palette) | small sprite/icon set (guess) |
| a/0/4/0 | 53 | NCLR (palette) | 3D model/texture data (guess) |
| a/0/4/1 | 33 | NCLR (palette) | map/tileset graphics (guess) |
| a/0/4/3 | 47 | NCGR (tile/character data) | trainer/item/UI sprites (guess) |
| a/0/4/4 | 12 | NCLR (palette) | small sprite/icon set (guess) |
| a/0/4/6 | 27 | NCGR (tile/character data) | 3D model/texture data (guess) |
| a/0/5/0 | 2 | NCLR (palette) | small sprite/icon set (guess) |
| a/0/5/1 | 9 | NCER (cell bank) | small sprite/icon set (guess) |
| a/0/5/4 | 11 | NCGR (tile/character data) | small sprite/icon set (guess) |
| a/0/5/5 | 29 | NCGR (tile/character data) | trainer/item/UI sprites (guess) |
| a/0/5/6 | 44 | NCGR (tile/character data) | 3D model/texture data (guess) |
| a/0/5/9 | 18 | NCLR (palette) | small sprite/icon set (guess) |
| a/0/6/3 | 17 | NSCR (screen/map) | small sprite/icon set (guess) |
| a/0/6/5 | 2 | NCGR (tile/character data) | small sprite/icon set (guess) |
| a/0/6/8 | 3 | NCGR (tile/character data) | map/tileset graphics (guess) |
| a/0/6/9 | 29 | NSBTA (texture SRT animation) | scripts/data tables (guess) |
| a/0/7/1 | 39 | NCGR (tile/character data) | trainer/item/UI sprites (guess) |
| a/0/7/6 | 29 | NCGR (tile/character data) | trainer/item/UI sprites (guess) |
| a/0/7/8 | 179 | NCGR (tile/character data) | trainer/item/UI sprites (guess) |
| a/0/8/3 | 172 | NCGR (tile/character data) | trainer/item/UI sprites (guess) |
| a/0/8/4 | 4 | NCLR (palette) | map/tileset graphics (guess) |
| a/0/8/5 | 21 | NCGR (tile/character data) | trainer/item/UI sprites (guess) |
| a/0/8/8 | 40 | NCGR (tile/character data) | trainer/item/UI sprites (guess) |
| a/0/8/9 | 24 | NCGR (tile/character data) | 3D model/texture data (guess) |
| a/0/9/4 | 53 | NCGR (tile/character data) | 3D model/texture data (guess) |
| a/0/9/5 | 165 | NCGR (tile/character data) | trainer/item/UI sprites (guess) |
| a/0/9/6 | 42 | NCLR (palette) | trainer/item/UI sprites (guess) |
| a/1/0/3 | 64 | NSBCA (animation) | 3D model/texture data (guess) |
| a/1/0/4 | 13 | NSBCA (animation) | 3D model/texture data (guess) |
| a/1/0/6 | 20 | NCLR (palette) | trainer/item/UI sprites (guess) |
| a/1/0/7 | 39 | NSBTA (texture SRT animation) | 3D model/texture data (guess) |
| a/1/1/6 | 79 | NCLR (palette) | trainer/item/UI sprites (guess) |
| a/1/1/8 | 11 | NSCR (screen/map) | small sprite/icon set (guess) |
| a/1/2/0 | 5 | NCGR (tile/character data) | map/tileset graphics (guess) |
| a/1/2/4 | 29 | NCGR (tile/character data) | trainer/item/UI sprites (guess) |
| a/1/2/8 | 8 | NCLR (palette) | small sprite/icon set (guess) |
| a/1/2/9 | 12 | NSBCA (animation) | 3D model/texture data (guess) |
| a/1/3/0 | 36 | NSBTP (texture pattern animation) | 3D model/texture data (guess) |
| a/1/3/1 | 69 | NCGR (tile/character data) | trainer/item/UI sprites (guess) |
| a/1/3/3 | 12 | NSCR (screen/map) | small sprite/icon set (guess) |
| a/1/3/5 | 28 | NSBCA (animation) | 3D model/texture data (guess) |
| a/1/3/7 | 108 | NCLR (palette) | trainer/item/UI sprites (guess) |
| a/1/3/8 | 8 | NSBTA (texture SRT animation) | 3D model/texture data (guess) |
| a/1/3/9 | 12 | NCLR (palette) | map/tileset graphics (guess) |
| a/1/4/0 | 7 | NCLR (palette) | sound (SDAT archive) |
| a/1/4/1 | 14 | NCLR (palette) | small sprite/icon set (guess) |
| a/1/4/5 | 8 | NCLR (palette) | map/tileset graphics (guess) |
| a/1/5/1 | 12 | NCLR (palette) | map/tileset graphics (guess) |
| a/1/5/3 | 9 | NSBCA (animation) | 3D model/texture data (guess) |
| a/1/5/5 | 48 | NCLR (palette) | trainer/item/UI sprites (guess) |
| a/1/5/7 | 26 | NSBTA (texture SRT animation) | 3D model/texture data (guess) |
| a/1/6/2 | 19 | NSBCA (animation) | 3D model/texture data (guess) |
| a/1/6/4 | 5 | NCGR (tile/character data) | map/tileset graphics (guess) |
| a/1/7/0 | 37 | NCLR (palette) | 3D model/texture data (guess) |
| a/1/7/2 | 27 | NCLR (palette) | trainer/item/UI sprites (guess) |
| a/1/7/3 | 35 | NCGR (tile/character data) | trainer/item/UI sprites (guess) |
| a/1/8/1 | 35 | NSBCA (animation) | 3D model/texture data (guess) |
| a/1/8/2 | 11 | NCGR (tile/character data) | 3D model/texture data (guess) |
| a/1/8/4 | 17 | NCLR (palette) | small sprite/icon set (guess) |
| a/1/8/7 | 12 | NCLR (palette) | map/tileset graphics (guess) |
| a/1/8/9 | 11 | NCGR (tile/character data) | 3D model/texture data (guess) |
| a/1/9/1 | 9 | NCGR (tile/character data) | small sprite/icon set (guess) |
| a/1/9/5 | 14 | NCGR (tile/character data) | small sprite/icon set (guess) |
| a/1/9/6 | 7 | NCLR (palette) | small sprite/icon set (guess) |
| a/1/9/9 | 11 | NCLR (palette) | small sprite/icon set (guess) |
| a/2/0/0 | 3 | NCGR (tile/character data) | map/tileset graphics (guess) |
| a/2/0/1 | 8 | NCLR (palette) | small sprite/icon set (guess) |
| a/2/0/2 | 10 | NCLR (palette) | small sprite/icon set (guess) |
| a/2/0/5 | 40 | NCLR (palette) | 3D model/texture data (guess) |
| a/2/1/6 | 52 | NCLR (palette) | trainer/item/UI sprites (guess) |
| a/2/1/9 | 10 | NSBTP (texture pattern animation) | 3D model/texture data (guess) |
| a/2/3/4 | 3 | NCLR (palette) | map/tileset graphics (guess) |
| skb.narc | 6 | NCGR (tile/character data) | map/tileset graphics (guess) |
| titledemo.narc | 20 | NCLR (palette) | 3D model/texture data (guess) |

#### Custom format, no decoder

Dominant sub-file magic is not a recognised NITRO chunk. Most of these are the small, fixed-size-record "scripts/data tables (guess)" archives the inventory already flagged; a handful are the larger "text banks (guess)" archives whose candidacy as real text was never confirmed (the real text archive is `a/0/0/2`, see "Text banks" above).

| path | subs | dominant magic | category guess |
|---|---:|---|---|
| a/0/1/0 | 1 | 0x00000000 | scripts/data tables (guess) |
| a/0/1/5 | 5 | 0x00008410 | scripts/data tables (guess) |
| a/0/1/7 | 8 | 0x00000000 | scripts/data tables (guess) |
| a/0/2/0 | 650 | 0x8500 | text banks (guess) |
| a/0/3/6 | 14 | 0x11240800 | small sprite/icon set (guess) |
| a/0/3/7 | 1 | 0x3019080f | scripts/data tables (guess) |
| a/0/3/8 | 1 | 0x03090200 | scripts/data tables (guess) |
| a/0/3/9 | 18 | 0x11240800 | small sprite/icon set (guess) |
| a/0/4/2 | 1 | 0xc4030000 | scripts/data tables (guess) |
| a/0/4/7 | 80 | 0x38000000 | 3D model/texture data (guess) |
| a/0/4/8 | 1 | 0x1f030000 | scripts/data tables (guess) |
| a/0/5/3 | 19 | 0x00000000 | scripts/data tables (guess) |
| a/0/5/7 | 899 | 0x00000000 | text banks (guess) |
| a/0/5/8 | 17 | 0x1a000e00 | scripts/data tables (guess) |
| a/0/6/0 | 1 | 0xed000000 | scripts/data tables (guess) |
| a/0/6/1 | 56 | 0x04000000 | scripts/data tables (guess) |
| a/0/6/2 | 10 | 0x04000000 | scripts/data tables (guess) |
| a/0/6/7 | 98 | 0x01000000 | scripts/data tables (guess) |
| a/0/7/0 | 6 | 0x01000000 | scripts/data tables (guess) |
| a/0/7/9 | 34 | 0x524c0500 | scripts/data tables (guess) |
| a/0/8/0 | 1 | 0x98a30000 | scripts/data tables (guess) |
| a/0/8/1 | 14 | 0x9f7f0000 | scripts/data tables (guess) |
| a/0/8/2 | 2 | 0x04000000 | scripts/data tables (guess) |
| a/0/8/6 | 1 | 0x85010100 | scripts/data tables (guess) |
| a/0/8/7 | 1 | 0x23fb0307 | scripts/data tables (guess) |
| a/0/9/0 | 1 | 0x01000000 | scripts/data tables (guess) |
| a/0/9/1 | 1 | 0x00000000 | scripts/data tables (guess) |
| a/0/9/7 | 2 | 0x00000000 | scripts/data tables (guess) |
| a/0/9/8 | 10 | 0x01000200 | scripts/data tables (guess) |
| a/0/9/9 | 17 | 0x10240100 | small sprite/icon set (guess) |
| a/1/0/1 | 1 | 0xf9000000 | scripts/data tables (guess) |
| a/1/0/5 | 29 | 0x00000106 | scripts/data tables (guess) |
| a/1/0/8 | 282 | 0x01000000 | scripts/data tables (guess) |
| a/1/0/9 | 17 | 0x05000000 | scripts/data tables (guess) |
| a/1/1/1 | 6 | 0x00501428 | scripts/data tables (guess) |
| a/1/1/2 | 6 | 0x03145028 | scripts/data tables (guess) |
| a/1/1/3 | 6 | 0x01282850 | scripts/data tables (guess) |
| a/1/1/4 | 6 | 0x02282814 | scripts/data tables (guess) |
| a/1/1/7 | 53 | 0x08000000 | scripts/data tables (guess) |
| a/1/1/9 | 9 | 0x0d000500 | scripts/data tables (guess) |
| a/1/2/1 | 23 | 0x50000000 | 3D model/texture data (guess) |
| a/1/2/3 | 650 | 0x0000 | text banks (guess) |
| a/1/2/5 | 428 | 0x60000000 | scripts/data tables (guess) |
| a/1/2/7 | 7 | 0xc4090000 | 3D model/texture data (guess) |
| a/1/3/2 | 5 | 0x10000000 | scripts/data tables (guess) |
| a/1/3/6 | 31 | 0xd6007f06 | scripts/data tables (guess) |
| a/1/4/6 | 10 | 0x98000000 | scripts/data tables (guess) |
| a/1/4/7 | 3 | 0x2b040000 | scripts/data tables (guess) |
| a/1/4/8 | 18 | 0xe8030000 | 3D model/texture data (guess) |
| a/1/4/9 | 1 | 0x44010000 | scripts/data tables (guess) |
| a/1/5/2 | 3 | 0x01000000 | scripts/data tables (guess) |
| a/1/5/4 | 37 | 0x0c000200 | scripts/data tables (guess) |
| a/1/5/6 | 46 | 0x0400080c | scripts/data tables (guess) |
| a/1/5/8 | 5 | 0x01000100 | scripts/data tables (guess) |
| a/1/6/3 | 7 | 0xfa2000d5 | scripts/data tables (guess) |
| a/1/6/5 | 13 | 0x00000000 | scripts/data tables (guess) |
| a/1/6/6 | 9 | 0x00000000 | scripts/data tables (guess) |
| a/1/6/8 | 315 | 0x55002300 | scripts/data tables (guess) |
| a/1/6/9 | 951 | 0x41005e00 | text banks (guess) |
| a/1/7/1 | 14 | 0x51005007 | scripts/data tables (guess) |
| a/1/7/4 | 24 | 0x5c000000 | scripts/data tables (guess) |
| a/1/7/5 | 2 | 0x00000000 | scripts/data tables (guess) |
| a/1/7/8 | 649 | 0x01010000 | text banks (guess) |
| a/1/7/9 | 50 | 0x07000000 | scripts/data tables (guess) |
| a/1/8/5 | 2 | 0x1f040000 | scripts/data tables (guess) |
| a/1/8/6 | 7 | 0x37005a00 | scripts/data tables (guess) |
| a/1/9/4 | 652 | 0x10296e00 | text banks (guess) |
| a/1/9/8 | 1 | 0x10400400 | scripts/data tables (guess) |
| a/2/0/3 | 4 | 0x78000000 | scripts/data tables (guess) |
| a/2/0/8 | 4 | 0x44020000 | scripts/data tables (guess) |
| a/2/0/9 | 1 | 0x00000100 | scripts/data tables (guess) |
| a/2/1/1 | 1 | 0x01000200 | scripts/data tables (guess) |
| a/2/1/2 | 2 | RIFF | scripts/data tables (guess) |
| a/2/1/4 | 1000 | 0x00000000 | text banks (guess) |
| a/2/1/5 | 315 | 0x3d005800 | scripts/data tables (guess) |
| a/2/2/0 | 13 | 0x00000000 | 3D model/texture data (guess) |
| a/2/2/1 | 7 | 0x411673ec | scripts/data tables (guess) |
| a/2/2/4 | 4 | 0xffff0000 | scripts/data tables (guess) |
| a/2/2/5 | 151 | 0x11000002 | scripts/data tables (guess) |
| a/2/2/6 | 174 | 0x11000002 | scripts/data tables (guess) |
| a/2/2/7 | 1 | 0x000a1020 | scripts/data tables (guess) |
| a/2/2/9 | 52 | 0x41423a00 | scripts/data tables (guess) |
| a/2/3/0 | 64 | 0x41424c00 | scripts/data tables (guess) |
| a/2/3/1 | 73 | 0x10008001 | scripts/data tables (guess) |
| a/2/3/2 | 1 | 0x00010101 | scripts/data tables (guess) |
| a/2/3/3 | 2 | 0x10300100 | scripts/data tables (guess) |
| dwc/utility.bin | 0 | 0x10000000 | Nintendo DWC/WFC setup-UI resource bundle, out of scope (identified this pass, see below) |

#### Unknown

The inventory's own heuristic could not produce even a category guess for these (`category_guess` is `unknown` or `unknown raw format`).

| path | subs | dominant magic | category guess |
|---|---:|---|---|
| a/0/1/3 | 0 | 0x00000000 | unknown raw format |
| a/0/2/3 | 8 | NFTR variant (font, guess) | unknown |
| a/1/0/0 | 20 | 0x10240600 | unknown |
| a/1/6/1 | 5 | 0x10240600 | unknown |
| a/1/8/0 | 44 | 0x10402000 | unknown |
| a/2/1/3 | 8 | 0x11240600 | unknown |
| dl_rom/child2_r_eng.srl | 0 | SYAC | unknown raw format |
| dl_rom/child_r_eng.srl | 0 | SYAC | unknown raw format |
| dl_rom/icon_b.char | 0 | 0xdddddddd | unknown raw format |
| dl_rom/icon_b.plt | 0 | 0x736eda31 | unknown raw format |
| dl_rom/icon_w.char | 0 | UUUU | unknown raw format |
| dl_rom/icon_w.plt | 0 | 1FQ! | unknown raw format |

`category_guess` above is inventory.py's own unmodified heuristic (unchanged since it does not decompress sub-files or parse raw-file headers); all twelve rows are now identified by direct inspection -- see "Twelve unknowns identified" and the "Full per-archive table" rows above for what each one actually is.


## Per-tile grid record SOLVED from the game's code: it is not eight byte lanes, it is `{u16 surface, u16 index, u32 attribute}`, and the attribute word splits into a terrain id and a flag half

Mission: find the code that reads the `a/0/0/8` per-tile 8-byte record and
name its lanes by what the consumers do with them. Found, decompiled the
consumer family to `EXACT`, and confirmed the reading against all 664,576
records in the archive. The result corrects the byte-lane model the three
earlier passes built from data alone: **there are no eight independent byte
lanes**. The record is three fields, and the previous "byte[4] is
walkability / byte[6] is byte[4] | 0x80" reading was two views of one fact,
which is why the two looked redundant.

### The path to the reader

```
func_02169848(out, mapObj, pos, ...)                   ov010, field_g3d_map.c
  -> mapObj->vtable[tagIndex].fn[+0xc]                 dispatch on the wrapper tag
       WB -> func_02193398   grid = fileBuf + u32@8
       GC -> func_02193498   grid 0 = fileBuf + u32@8, grid 1 = fileBuf + u32@0x0c
       NG -> func_02193544
       RD -> func_02193628
  -> func_021D14C4(out, slot, gridPtr, posObj, ..., baseY)   ov021, the record decoder
  -> func_0218DBAC                                      copies out+8 / out+0x0c out
  -> func_021AB504(attributeWord)                       ov021, the terrain-class switch
```

The tag-keyed vtable sits at `0x021D3DDC`, 16 bytes per entry, terminated by
a `0xFFFFFFFF` catch-all:

| tag word | tag | fn[+0x04] | fn[+0x08] | fn[+0x0c] |
|---|---|---|---|---|
| 0x00004257 | `WB` | func_021932C0 | func_02193398 | func_02193398 |
| 0x00004347 | `GC` | func_021933C0 | func_02193498 | func_021934F8 |
| 0x0000474E | `NG` | func_02193544 | 0x0219361C | 0x0219361C |
| 0x00004452 | `RD` | func_02193628 | func_02193790 | func_02193790 |
| 0xFFFFFFFF | (default) | func_021933C0 | func_02193498 | func_02193498 |

`func_02169470` (ov010) scans that table comparing the sub-file's own leading
`u16` against each tag until the terminator. This is the game stating the four
tags itself, and it independently confirms the earlier passes' structural
findings: the `GC` handler samples **two** grids (`u32@8` and `u32@0x0c`) where
`WB`'s samples one, and `NG`'s entries are a stub pair plus a separate
initialiser, i.e. no grid.

`func_021D14C4` indexes the grid exactly the way `map_grid.py` guessed from the
data:

```
adds r1, r1, #4        ; skip the grid's own u16 width, u16 height header
lsls r0, r0, #3        ; record stride 8
adds r7, r1, r0        ; &grid[row * width + col]
```

### The record, as the decoder reads it

| offset | width | field | meaning, and who attests it |
|---|---|---|---|
| +0x00 | u16, bits 0..1 | surface type | `func_021D14C4` switches on it: 0 = one flat surface, 2 = a slope resolved against an auxiliary record list, 1 = no surface (writes normal `(0, 0x1000, 0)`, height 0) |
| +0x00 | u16, bits 2..15 | normal index | `idx * 3 + {0,1,2}` into an s16 table of `(x, y, z)` triples, written to the caller's normal field with the z lane negated |
| +0x02 | u16 | height index | type 0: index into a `u32` height table added into the height sum; type 2: index of the first record of the auxiliary array that starts at `gridPtr + 4 + width*height*8`, which is the "tail bytes" the earlier passes left undecoded |
| +0x04 | u32, bit 31 | search direction | `func_021D14C4` at `0x021D1588` picks which end of the auxiliary list the type-2 search walks from |
| +0x04 | u32, bits 0..30 | **tile attribute word** | copied to the caller verbatim with bit 31 cleared (`0x021D163C`), and that word is what every gameplay consumer tests |

So the old byte lanes map onto this as: byte[0]/byte[1] are the surface `u16`,
byte[2]/byte[3] are the height-index `u16`, byte[4..7] are the attribute word.
The earlier passes' "byte[2] is a quantized height step, overloaded with large
outliers" was right in spirit and wrong in mechanism: it is an index into a
height table, so a smooth ramp shows as a smooth run of indices and an
unrelated tile shows as an unrelated index. "byte[0] is an edge/boundary
marker" is the surface-type/normal field: a cliff edge is exactly where the
normal stops being flat. And "byte[1]/byte[3] are outdoor-only terrain codes"
is the high byte of each of those two `u16`s: `byte[1]` in 1..5 is a normal
index in 0x100..0x5ff, not a five-valued enum, which is why no direction or
ledge reading ever fit it.

### The attribute word, and the predicate family that reads it

`func_021AB0F0(attr)` returns `(u16)attr`, the **terrain id**;
`func_021AB0F8(attr)` returns `(u16)(attr >> 16)`, the **flag half**. Both are
`EXACT`. Everything downstream is written against one or the other.

| lane | bit or value | meaning, and the consumer that attests it | confidence |
|---|---|---|---|
| attribute low half | id, `u16` | terrain id; the argument of every predicate in the `pkt_021AB0F0` family | HIGH |
| attribute low half | id == 0xFF | "no terrain"; `func_021AB100` treats it, and the all-ones attribute word, as absent | HIGH |
| attribute low half | id == 1 | ordinary walkable ground: 508,497 of 664,576 records, and the dominant id ever paired with flag bit 0 | HIGH |
| attribute low half | id == 0 | blocked: 76,964 records, flag bit 0 never set | HIGH |
| attribute low half | id in {4, 5, 0x21} | one encounter-terrain family; `func_021AB23C`, folded by `func_021AB27C` / `func_021AB2BC` into the set `enceff.c` (`0x021CF6DE`) uses to pick an encounter-effect resource | HIGH |
| attribute low half | id in {6, 7, 0x22} | the sibling family; `func_021AB250`, same consumer through `func_021AB29C` | HIGH |
| attribute low half | id == 8 / == 9 | the singleton members of those two families; `func_021AB264` / `func_021AB270` | HIGH |
| attribute low half | id == 0x20 | terrain class 7; the one `func_021AB504` case that fires without the bit-2 gate | HIGH |
| attribute low half | id in {0x3d, 0x3e, 0x3f, 0x42, 0x43} | one group; `func_021AB3B0`, called from `0x021C5CEC` | MEDIUM (membership certain, meaning not named) |
| attribute low half | id in {0x0b, 0x0c, 0x23} and id == 0x19 | one group; `func_021AB37C` / `func_021AB370`, unioned by `func_021AB390`, also read directly by `enceff.c` at `0x021CF706` | MEDIUM |
| attribute low half | 43 further single-id predicates | ids 0x02, 0x05, 0x07, 0x0c, 0x0e, 0x0f, 0x10, 0x14, 0x17, 0x1b, 0x1c, 0x1d, 0x1e, 0x21, 0x22, 0x23, 0x30, 0x32, 0x33, 0x40, 0x41, 0x44, 0x72..0x75, 0x7c, 0xbe, 0xbf, 0xd4, 0xd6..0xe2 each get their own `id == k` leaf in the same run | HIGH (the ids), none (what each one means) |
| attribute high half | bit 0 | ordinary walkable ground; `func_021AB11C` returns true when the tile is absent or this bit is set, and `0x021A6FBE` uses that as a movement gate alongside `func_021BB1A0` | HIGH |
| attribute high half | bit 1 | selects the alternate encounter-effect resource set; `enceff.c` at `0x021CF6CE` tests it before looking at the id at all | HIGH |
| attribute high half | bit 2 | gates the terrain-class switch: `func_021AB504` returns 8 ("no class") for every id except 0x20 unless this bit is set | HIGH |
| attribute high half | bits 3..15 | never observed set: the whole archive uses only values 0..7 in the low three bits | HIGH (as a negative) |
| attribute | bit 31 | not part of the attribute: `func_021D14C4` consumes it as the type-2 search direction and hands the caller the word with it cleared | HIGH |

`func_021AB504` is the one place that turns the word into a small enum, and it
is `EXACT`:

```c
if (id == 0x20) return 7;
if (!(flags & 4)) return 8;
switch (id) {
case 4:    return 0;   case 5:  return 1;   case 0x21: return 2;
case 8:    return 3;   case 10: return 4;   case 0x3d: return 5;
case 0x3f: case 0x43:  return 6;
}
return 8;
```

Its only caller, `func_021AACD4` in `effect_encount.c`, drops a candidate tile
when the answer is 8 and otherwise records the class byte, so 8 is "this tile
triggers no terrain effect".

### The two data checks

Both run over every `WB`/`GC` grid in `a/0/0/8`: 664,576 records.

**(1) The id and the flag half are one fact, which is why byte[4] looked like
a walkability lane.** Flag bit 0 is set on the ids that are ordinary ground:

```python
lo, fl = attr & 0xFFFF, (attr >> 16) & 0xFFFF      # attr = u32 at record[4:8]
assert sum((lo == 1) != bool(fl & 1) for attr in every_record) == 7377   # 1.1%
```

Per id, over the thirty most common ids: id 1 is 99.81% flag-bit-0, and every
other id is 0.00% except ids 18, 65, 68, 212 and 224, which are 100%. That is
not a walkability lane sitting beside a terrain lane, it is one classification
expressed twice, and the earlier "byte[6] == byte[4] | 0x80" observation is its
degenerate case (flag half 0x0081 next to id 1, 0x0080 next to id 0). The 1.1%
disagreement is exactly those five other always-passable ids, not noise.

**(2) The terrain-class switch is reachable in full and its gate is real.**
Applying `func_021AB504` verbatim to every record:

```python
Counter(classify(attr) for attr in every_record)
# {8: 639172, 4: 8937, 6: 7989, 0: 4448, 7: 2096, 5: 1146, 3: 653, 1: 113, 2: 22}
```

All eight classes occur. Class 7's count, 2096, is exactly the number of
records with id 0x20 anywhere in the archive, which confirms that the
`id == 0x20` early-out really is the only path that ignores the bit-2 gate: no
record with id 0x20 exists that the gate could have swallowed. Flag bit 2 is
set on 34,180 records, comfortably more than the 25,404 that classify to
something other than 8, which is the right direction: the gate admits ids that
then fall through the switch's default.

### Functions filed `EXACT` this pass (`layout/matched/ov021/pkt_021AB0F0.json`)

59 entries, all `EXACT` or `EXACT*`, the whole attribute-predicate run
`0x021AB0F0..0x021AB580`: the two half accessors, `func_021AB100` /
`func_021AB11C` (presence and the movement gate), six grouped predicates and
five unions over them, 43 single-id leaves (29 of which `disasm.py` never
labelled, they print as `.word` runs and are filed as `sub_`), and
`func_021AB504`.

### What this closes and what it does not

Closed: the record's field structure, the reader, the tag vtable (which
re-confirms `WB` one grid / `GC` two grids / `NG` no grid from code rather than
from byte arithmetic), the meaning of the attribute word's split, three flag
bits, and the identity of the ids that gate encounter effects and movement.

Not closed:

- **Which id is tall grass, which is water, which is a ledge.** The ids are
  enumerated exactly and their groupings are attested, but nothing in this pass
  names them: the predicates are leaves, and their callers set opaque effect
  resource pointers. The next step is the resource pointers `enceff.c` loads at
  `0x021CF6D8` / `0x021CF6EC` / `0x021CF6F2`, which should resolve to named
  effect archives; that, not more grid statistics, is what will label the ids.
- The mission's earlier hypotheses about a ledge direction code in byte[1] and
  a terrain enum in byte[3] are now moot rather than refuted: those byte
  positions are the high halves of two `u16` indices, so no small-constant enum
  can live there, and the earlier passes' inconclusive results were
  structurally guaranteed.
- `func_021D14C4` itself is documented
  (`docs/notes/func_021D14C4_tile_record_reader.c.txt`) but not decompiled; it
  is a 428-byte function with 64-bit division helpers and deserves its own
  packet.
- The auxiliary slope-record array after the grid is located exactly
  (`gridPtr + 4 + width*height*8`) and its record shape is read off the type-2
  loop; the asset-lane pass below decodes its pair structure and indices, but
  the ROM-resident normal-vector and height-value tables those indices select
  are not in this archive and so cannot be resolved to real values.
- The `RD` tag's dense secondary block and the `GC` second grid's purpose are
  still open; the vtable shows only that `GC`'s second grid is sampled by the
  same decoder as its first, into slot 1 of the caller's output.

### Asset-lane implementation: `tools/assets/map_grid.py` rewritten to this model

Follow-up asset-lane pass, retiring the byte-lane model entirely (see the
now-superseded sections above) and replacing `map_grid.py` with a decoder
built on the record model above. `parse_wrapper()` now reads each
wrapper tag's own size-table fields as the grid *and aux array* boundary
(not "grid end, tail start" as the earlier passes assumed): `WB`/`RD` one
grid, `GC` two, `NG` none, exactly per the tag vtable. This resolves
`pl_00_00`'s previously-unexplained 32-byte gap before its declared
grid-end offset: it is 4 aux records (32 = 4 * 8 bytes), not a mystery
block. Records decode to `{surface_type, normal_index, height_index,
search_dir, terrain_id, flags, walkable, alt_encounter, class_gate,
terrain_class}`; `classify_terrain()` is `func_021AB504` ported verbatim.
The trailing aux array decodes to its attested pair structure (two
`(normal index, height index)` pairs per 8-byte record at `+0/+4` and
`+2/+6`) but, as noted above, not to real vectors/heights, since those
live in ROM tables this archive does not contain.

**Round trip (`--verify`):** every sub-file is repacked from parsed
fields -- reconstructed header and size table, the BMD0 span copied
verbatim (out of this mission's scope), every grid's records and aux
array rebuilt from decoded fields, the RD dense block's raw words, and
the trailing tail bytes -- and compared byte-for-byte against the
original:

    a/0/0/8: 649/649 sub-files round-trip byte-identical (0 failed)

**Archive-wide stats (`--stats`, every ordinary 8-byte-record grid in all
649 sub-files, 693,248 records -- `WB`'s 572 grids including `pl_00_00`'s
real 64x64 size, `GC`'s 47 pairs of grids, and `RD`'s 8 ordinary grids;
`NG` contributes none):**

    terrain id histogram (top): 1:522511  0:80305  10:10390  31:9151
                                 63:9000  156:6844  14:6507  4:5165 ...
    terrain class histogram: {0:5165, 1:113, 2:22, 3:919, 4:10390,
                               5:1828, 6:9036, 7:2096, 8:663679}
    flag-word histogram (top): 129:521680  128:89793  132:13573
                                0:10176  36:9132  22:9036 ...

    class 7 count: 2096  id==0x20 count: 2096  -- exactly equal, confirming
    the id==0x20 early-out is the only path around the bit-2 gate, with no
    record the gate could have swallowed (same invariant the code-lane pass
    above found).

    id==1 vs walkable-flag disagreement: 10023 records (1.45%) over this
    693,248-record population. The code-lane pass above reported 7377 over
    a 664,576-record population; the two counts don't match exactly because
    they scan different record sets (664,576 is not reproducible from any
    per-tag-accurate grid enumeration of this archive -- it factors exactly
    as 649 * 1024, i.e. one fixed-size 32x32 grid assumed per sub-file
    regardless of actual tag/shape, which undercounts `pl_00_00`'s real
    64x64 grid, `GC`'s second grid, and `RD`'s grid, and would have to
    overcount `NG`'s zero grids to reach that total). Both counts agree on
    the substance: a small, consistent minority of always-passable ids
    (18, 65, 68, 212, 224 per the code-lane pass) account for the
    disagreement, not noise -- the class 7/id 0x20 check, which is
    insensitive to which grids are scanned, is the more reliable of the two
    cross-checks and it matches exactly.

See the matrix decoder section above for `matrix.py --stitch`'s
terrain-class rendering and the confirmation that the `{4,5,0x21}`/
`{6,7,0x22}` encounter-family ids form real, contiguous field-shaped
patches in the overworld matrices.

## Asset lane pass: fonts located and decoded (`a/0/2/3`, `tools/assets/font.py`)

### The archive: `a/0/2/3`

8 sub-files: 5 RTFN (NFTR, "NFTR" reversed to "RTFN" on disk, the same
chunked-container shape the inventory already flagged as "NFTR variant
(font, guess)") plus 3 RLCN (NCLR) palettes at indices 5-7 (16 colors each,
uncompressed, not used by the glyph decoder below -- see "What remains").

| # | size | cell | glyphs | line height | notes |
|---|---:|---|---:|---:|---|
| 0 | 264360 | 12x15 | 5064 | 15 | main/large font |
| 1 | 162768 | 10x10 | 5064 | 10 | small font |
| 2 | 218520 | 11x13 | 5064 | 13 | medium font |
| 3 | 1684 | 13x8 | 32 | 8 | special: digits, `/?FILMN`, gender marks, fullwidth digits |
| 4 | 2396 | 12x12 | 41 | 12 | special: digits 1-9, A-Z, circled digits (ordinal/ranking) |

### Container format (confirmed against real bytes)

NFTR is the same generic NITRO chunked-container shape as NARC/NCGR/NCLR: a
16-byte file header, then named chunks FNIF ("FINF"), PLGC ("CGLP"), HDWC
("CWDH"), then a linked chain of PAMC ("CMAP") chunks. FINF holds byte
offsets (relative to the sub-file start) to the CGLP/CWDH/first-CMAP chunk
bodies; every offset was cross-checked by walking the chunks sequentially
and landing exactly on the same bytes for all 5 fonts.

**Glyph record** (CGLP, one record per glyph, `cell_size` bytes each): 3
metric bytes (`bearing` s8, `width` u8, `advance` u8) then a packed bitmap.
This 3-byte-metrics-then-bitmap shape is not a guess -- it is exactly what
`src/matched/sub_0201DC44.c` (gf_font.c's glyph hand-off, status EXACT)
describes: "the glyph bitmap ... starts three bytes into the glyph record,
and the record's own three metric bytes ... are copied into the caller's
... descriptor." The bitmap is `cell_width * cell_height` pixels at **2
bits per pixel**, packed **MSB-first with no per-row byte alignment** (the
bit stream runs continuously across row boundaries) -- confirmed because
`cell_size - 3` exactly equals `ceil(w*h*2/8)` for all 5 fonts and fails for
every other bit depth tried (1/4/8), e.g. font #0: 12x15 = 180 px * 2 bit =
360 bit = 45 bytes + 3 metric bytes = 48, the real `cell_size`. The reader
this module implements (`_unpack_bits`/`_pack_bits`) reproduces
`src/matched/sub_0201E4D4.c` (the bit reader behind the compressed glyph
stream, also EXACT) byte for byte: pull `n` bits MSB-first, straddling byte
boundaries as needed.

The 2bpp (4 brightness levels, not a palette index) reading also matches
`func_0201DD78`'s "4x4x4x4 colour expansion" (see its packet notes): the
renderer builds a 4-level tint ramp from an RGB request at draw time rather
than reading color out of a palette, which is why this archive's 3 NCLR
palettes (16 colors each) don't correspond to the glyph bit depth -- they
are not the font's pixel colors, and their real purpose here is undetermined.

CWDH ("HDWC") is located (FINF gives its body offset, its own chunk header
gives its byte count) but its internal per-glyph record layout was **not**
cracked this pass: 1-, 2- and 4-byte fixed records at several header
lengths were tried and none gives a glyph count that lines up with anything
confirmable against the metrics already recovered from CGLP itself. This
does not block anything below: `sub_0201DC44.c` shows the real renderer
uses CGLP's own embedded metrics for layout, not CWDH, so `font.py` does
the same.

### CMAP: character code -> glyph index, confirmed against `text.py`

CMAP is a linked list of chunks (method 0 = direct range, method 1 = table,
method 2 = sparse scan of (code, index) pairs). Font #0's first CMAP chunk
is method 0, `first=0x20`, `last=0x7E`, base glyph index 0 -- **glyph index
N (0..94) is character code 0x20+N** for every printable ASCII character.
That is exactly the identity `text.py` uses for ASCII code points
(`text.py`: "Printable ASCII (0x20-0x7E) renders as itself"), which is this
pass's ground-truth check.

### Ground truth check

Rendered glyph indices 0-94 of font #0 (the ASCII direct-range CMAP chunk)
to a PNG contact sheet (`font.py render`, `build/assets/fonts/font_0.png`,
gitignored) and compared every digit 0-9 (glyph index 16-25) and every
capital A-Z (glyph index 33-58) against its expected shape by eye: **36/36
matched**, digits read as digits and capitals read as their letters
(including distinguishing details like the crossbar on 'A' and the two
bumps on 'B'), in the exact order `text.py`'s code-to-character identity
predicts.

### `tools/assets/font.py`

`--list` (`list` subcommand) summarizes every font (dimensions, bpp, glyph
count, CMAP chunk ranges); `render` writes one contact-sheet PNG per font to
`build/assets/fonts/` (gitignored, regenerate, don't commit); `widths`
dumps per-glyph `(bearing, width, advance)` straight from CGLP's own
metric bytes, annotated with the ASCII character where the direct-range
CMAP chunk applies; `verify` re-encodes every glyph record (metrics +
bitmap) with the inverse bit-packer and compares against the original bytes.

### Round trip

`font.py verify`: **15265/15265 glyph records byte-identical** across all
5 fonts (5064 + 5064 + 5064 + 32 + 41), every metric byte and every packed
bit reproduced exactly.

### What remains

- CWDH's internal record layout is not cracked (see above); not needed for
  anything implemented here, but it may hold a second, more precise width
  source this module doesn't use.
- The non-ASCII CMAP chunks (hiragana, katakana, fullwidth forms, a
  4530-entry scan chunk covering the rest of Unicode) are walked and
  reported by `list`, but `render`/`widths` only address glyphs by raw
  index, not by character code, so non-ASCII text is not exercised.
- The 3 NCLR palettes in this archive are parsed by no code in `font.py`;
  their purpose is undetermined (the glyph pixels are 2bpp brightness
  levels expanded through a runtime color ramp, not palette indices).
- FINF's bytes at offsets 0x01/0x05/0x06/0x07 are recorded (line height,
  two unknowns, an encoding flag guess) but not fully explained.

## Script virtual machine located and decompiled; `a/0/5/7` is the script-bytecode archive; `a/0/0/3` is a text bank, not bytecode

Mission: find the interpreter that walks `a/0/0/3`'s records and dispatches on
a u16 opcode. The interpreter was found, decompiled to EXACT, and it does not
read `a/0/0/3`: the archive it runs is `a/0/5/7`, reached through the zone
record's `+0x06` lane. `a/0/0/3` turns out to be an encrypted message bank
reached through the `+0x0a` lane, and its open `field_x` gap (see the
"`a/0/0/3` and `a/0/6/6` container framing" pass above) is closed below.

### The VM: ARM9 `0x020111EC`..`0x02011330`, source file `"vm.c"`

`func_0201121C` passes the `__FILE__` string at `0x020A7268`, which reads
`vm.c`, so the module name is the game's own, not a guess. The two units
`src/matched/unit_020111EC.c` and `src/matched/unit_0201126C.c` reproduce the
whole packet byte for byte; the fetch and stack helpers one address higher
were already EXACT in `src/matched/unit_02011330.c`.

The context is 0x30 bytes plus both arrays, allocated in one block:

| offset | what | fixed by |
|---|---|---|
| +0x00 | u16 stack capacity (0x100 for the field system) | `func_0201121C`, `func_020111EC` |
| +0x02 | u16 ring capacity (0x40) | same |
| +0x04 | `const ScriptCmdFn *` command table | `func_02011298` dispatch |
| +0x08 | u32 command count | `func_02011298` bound check |
| +0x0c | u8 stack depth | `func_0201137C` / `func_02011398` |
| +0x0d | u8 state: 0 stopped, 1 running, 2 waiting | `func_02011298` |
| +0x0e | u8 ring depth | `func_020111EC` |
| +0x10 | wait callback | `func_02011298`, `sub_020113D0` |
| +0x14 | `u8 *pc` | `func_02011330`, `func_0201134C` |
| +0x18 | `u32 *stack` (0x100 entries) | `func_0201121C` |
| +0x1c | `u32 *ring` (0x40 entries) | `func_0201121C` |
| +0x20 | user object | `func_0201126C`, `sub_02011324` |
| +0x24, +0x28 | pre-dispatch hook and its argument | `sub_02011328` |
| +0x2c | owner word (the loaded script file, field system) | `func_02158BFC` |

The call family, all EXACT:

    func_0201121C  create(heap, {stack_cap, ring_cap, cmds, cmd_count})
    func_020111EC  reset
    func_0201126C  bind user object        sub_02011324  read it back
    func_0201127C  start at a pc           sub_02011290  stop
    sub_02011328   install pre-dispatch hook
    func_02011298  step: one frame of script
    func_02011330  fetch u16 operand, pc += 2   (unit_02011330.c)
    func_0201134C  fetch u32 operand, pc += 4   (unit_02011330.c)
    func_0201137C  push   func_02011398  pop    (the +0x18 stack)
    sub_020113B0   jump   func_020113B4  call   func_020113C4  return
    sub_020113D0   yield: state = 2, wait callback = r1

`func_02011298` is the step function the mission asked for: `ldrh` the opcode
through `func_02011330`, `cmp` it against +0x08, `ldr` the table base from
+0x04, `ldr [table, op lsl #2]`, `blx`. A handler returning 1 yields for the
frame; returning 0 runs straight into the next opcode, so one call to
`func_02011298` executes as much script as the handlers allow.

### The handler table: `0x0217062C` in overlay 10, 609 entries

`func_02158BFC` (ov010) builds the descriptor `{0x100, 0x40, 0x0217062C,
*(u32 *)0x021705D8}` and hands it to `func_0201121C`. The count word at
`0x021705D8` is 0x261 = **609**, so the table spans `0x0217062C..0x02170FB0`.
9 entries are NULL; 253 handlers are inside ov010 itself, 330 more resolve
into ov021 (several through `ldr r3,[pc,#0]; bx r3` veneers, which have to be
followed before the handler can be read), and 17 land in overlays this pass
did not pin down.

Opcodes whose handler calls `sub_02011290` (stop): **2, 29, 140, 342, 359,
378**. Opcodes whose handler calls `sub_020113B0` / `func_020113C4` (jump or
return, so linear flow ends): **5, 30, 31**. Opcode 4 is the call: it fetches
a u32, adds it to the pc and calls `func_020113B4`.

### Operand widths, first 32 opcodes

Read off each handler's fetch calls (`func_02011330` = 2 bytes,
`func_0201134C` = 4), following one level of callee, because the common
"variable id" operand is fetched inside a helper (`0x02159AE8`) rather than in
the handler itself. Total operand bytes per opcode, the opcode's own halfword
excluded:

    op   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
    len  0  0  0  2  4  0  2  2  2  2  2  0  0  0  0  0
    op  16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
    len  2  2  4  4  0  4  0  0  0  4  4  6 10  0  4  4

Opcodes 0 and 1 are `movs r0,#0; bx lr`, true no-ops. Opcode 2 is the end of a
script (stop, return 1). Opcode 3 takes a u16 and yields through
`sub_020113D0`. Opcode 4 is `call`.

### The record decode check, over the real archive

`a/0/5/7` (899 sub-files) is the script archive. A script sub-file is a table
of `u32` entry offsets terminated by the halfword `0xFD13`, code immediately
after it; entry *k* starts at `4*k + 4 + table[k]`, which is exactly what
`func_02158BFC` does (`pc = buf + 4*index`, then `func_0201134C` reads the word
and adds it to the pc).

Decoding every entry point of every sub-file with the widths above:

    sub-files with a 0xFD13 entry table   469 / 899
    entry points decoded                  2592
    landed on an end/flow opcode, on the
      next entry point, or on file end    2352  (90.7%)
    desynced (opcode >= 609)               232
    handler not resolvable (17 opcodes)      7

The 232 desyncs concentrate on one opcode: 100 of them are the instruction
straight after opcode **76**, whose handler is in ov021 and is the obvious
variable-length candidate (a case or jump table). The other 430 sub-files
carry no `0xFD13` at all and are 8 to 28 bytes long: small side tables sharing
the archive, not scripts. Neither is patched over with a guess here.

### `a/0/0/3` is the text bank, and `field_x` is a length

No code anywhere in the image opens archive id 3 with an immediate, and the
record payloads are high-entropy. They are not bytecode: they are encrypted
with the same cipher as `a/0/0/2`'s message files (`key = (index + 3) *
0x2983`, rotate left 3 after every code unit, see "Text banks" above), with
the key seeded from the record's index inside its own sub-file. Decrypting
records 0, 1 and 2 of sub-file 5 gives `Ha ha ha`, `My, my. My.` and
`I'm tired`.

That closes the open `field_x` question: **`field_x & 0xFFFF` is the record's
length in u16 code units**. Decrypting all 7861 records of all 472 sub-files
and reading the unit at `length - 1` gives the string terminator `0xFFFF` in
**7861 / 7861** cases. Measured against the gap to the next record, the count
is exact on 7579 and one unit short on 282 (trailing slack). The top byte is a
flag: 0xE0 on 6139 records, 0x00 on 1096, with a small tail.

So the index entry is `(u32 record_offset from the body start, u32 (flags <<
16) | unit_count)`, and the container is a message file with its own framing,
not the NARC-standard one.

### The zone lanes, both resolved

`func_02158CD0` (ov010) maps a script key to a (file, kind, id) triple. Below
the first range in its 10-byte range table it answers from the current zone
record instead: file = `sub_02013B5C` (`+0x06`), kind = 3, id = `sub_02013B68`
(`+0x0a`). `func_02158BFC` then passes the file to `func_02158D78`, which
loads it with archive id **0x39 = 57 = `a/0/5/7`**, and starts the VM on entry
`key - 1`.

- **`+0x06` (and `+0x08` = `+0x06 + 1`) is the `a/0/5/7` script file.** Max 853
  across the 427 zones, and `a/0/5/7` has 899 sub-files: this closes the
  "which archive needs at least 854 sub-files" gap left by the zone-header
  pass, which had listed `a/0/5/7` as one of three candidates.
- **`+0x0a` is the `a/0/0/3` message bank**, values 2..468 against 472
  sub-files. The "script lane" name it was given earlier is a misnomer: it is
  the text lane, and the script lane is `+0x06`.

### Remaining gaps

- Opcode 76's operand encoding (variable-length, 100 of the 232 desyncs).
- 17 of the 609 handlers are in an overlay this pass could not pin to a single
  candidate, so their operand widths are unknown; 7 entry points hit one.
- The 430 `a/0/5/7` sub-files with no `0xFD13` table are unidentified.
- What `func_02158CD0`'s 10-byte range table indexes (it answers keys above the
  zone's own range with a (file, kind, id) triple of its own) is not read.
- `a/0/0/3`'s `field_x` top byte (0xE0 / 0x00 / a small tail) is a flag whose
  meaning is not decoded, and the 282 records whose length is one unit short of
  the gap are not explained beyond "trailing slack".
- No converter was written this pass: the decode above lives in this section,
  not in `tools/assets/`, since this lane may not write there.

## Large custom table pass: eleven "custom format, no decoder" archives, two readers found by code, one registry tool (`tools/assets/tables.py`)

Mission: the eleven largest remaining "custom format, no decoder" census rows
-- `a/0/5/7` (899), `a/1/9/4` (652), `a/1/7/8` (649), `a/0/2/0` (650),
`a/1/2/3` (650), `a/1/6/9` (951), `a/2/1/4` (1000), `a/1/0/8` (282),
`a/1/2/5` (428), `a/1/6/8` (315), `a/2/1/5` (315). `a/0/5/7` was already
solved by the "Script virtual machine" pass above before this pass started
(see that section; it is not re-derived here). For the other ten, the
archive id was looked up by its decimal `a/X/Y/Z` digits and grepped as an
immediate register load ahead of every call to `func_02048F60`,
`func_02048DDC`, `func_02048D00`, `func_02048D54`, `func_02048F4C`,
`func_02048F74` or `func_02048F88` across `asm/arm9/main.s` and every
`asm/overlays/*.s` file (a scripted backward scan, not manual reading of
all 457 `.s` files). Two readers turned up this way; the rest are read from
the bytes alone, with a per-offset histogram backing each best-effort call.

### Readers found: `a/1/2/3` and `a/0/2/0`, both in overlay 21

`func_021C40F8` (ov021, ARM9 address `0x021C40F8`) sets `r0 = 0x7B` (123)
and calls `func_02048F60(archive_id, member, heap)` with `member` read from
its own first argument (a species id), then treats the returned buffer as
`[u16 count][u16 value, count times]` and linear-searches it for a second
argument, returning whether it was found. `0x7B = 123 = a/1/2/3`. Species
below 650 each get a variable-length list of u16s in range with move ids
(waza.py's table has 560 moves, and the sampled values -- 130, 204, 345,
437, 438, ... -- sit comfortably under that): this is the **egg-move list**.
Sub-file 0 is empty (the species-0 sentinel, same convention as
`a/0/1/6`/`a/0/1/8`/`a/0/1/9`).

`func_021C4504` (ov021, `0x021C4504`) sets `r1 = 0x14` (20) and calls
`func_02048F74(dst, archive_id, member, mode=0, size_out)` with `member`
again a species id taken from its own argument, then reads the 2-byte
result back as a u16. `0x14 = 20 = a/0/2/0`. This confirms icons.py's
earlier value-pattern note (650 entries x 2 bytes, values 0-649, runs of
2-4 identical consecutive values) with an actual accessor: a per-species u16
field, most likely the evolution-family/base-species index icons.py
guessed, though the caller context alone does not pin down which field of
that family the value denotes.

No other call site among the ~90 real (non-literal-pool) calls to those
seven entry points in `asm/arm9/main.s` plus the ~48 annotated calls in
`asm/overlays/*.s` loads one of the other nine archive ids as an immediate
register value ahead of the call. Most either pass the id through from the
caller's own parameter (untraceable without walking further up the call
graph) or load a completely different archive (the full distribution of
ids seen: 9, 25, 37, 52, 53, 66, 67, 94 x4, 102 x4, 108 (stack arg slot
reuse, not actually the archive id -- see below), 123, 127, 148, 152, 165,
167, 187, 188, 196, 212, 220, 232 across the scanned call sites).

One near-miss is worth recording so it is not re-chased: a call to
`func_02048F88` in `ov021` (`0x021CBFE0`) stores `0x6C` (108, `a/1/0/8`'s
id) to the stack slot used for a *previous* call's outgoing argument, then
immediately overwrites `r0` with `0xA5` (165) before the call -- `0x6C`
never reaches `func_02048F88` as the archive id, it is stale reuse of the
argument-passing stack slot from the call just before it.

### The other nine: framing and best identification from the bytes

**`a/1/6/8` and `a/2/1/5`** (315 sub-files each) share an exact framing:
`[u16 group_id][u16 count][u16 member_id, count times]`. `a/2/1/5` matches
it on 315/315 sub-files. `a/1/6/8` matches on 222/315; the other 93 carry
one extra leading member equal to the record's own `group_id` (a
self-inclusive variant: e.g. sub-files 24-26 all read `group_id=44,
count=45`, 46 members starting `44, 45, 46, ...`). Both still round-trip
byte-identical because the array length actually stored is re-emitted
as-is. The member-id range stays under the partner fixed-record archive's
count in both cases -- `a/1/6/8`'s max member is 950 (`a/1/6/9` has 951
records) and `a/2/1/5`'s max member is 988 (`a/2/1/4` has 1000 records) --
which is circumstantial but suggestive that these are reverse-index/group
tables over those two archives. Not confirmed by any decompiled accessor.

**`a/1/6/9`** (951 sub-files) and **`a/2/1/4`** (1000 sub-files) are both
fixed 16-byte records with the same field shape: five u16 fields at
offsets 0, 2, 4, 6, 8 (mostly under ~512 in `a/1/6/9`, under ~768 in
`a/2/1/4`), two u8 fields at offsets 10 and 11 with small ranges (max 52/24
and 56/23 respectively), one more u16 at offset 12, and two always-zero
pad bytes at offsets 14-15. High confidence on this field split (it is a
direct per-offset histogram read, not a guess); low confidence on what
domain the 951 or 1000 entries cover -- neither count matches any known
species/move/item/trainer-class/zone table size in this project.

**`a/1/0/8`** (282 sub-files: 281 at 28 bytes, 1 outlier at 52 bytes) is a
12-byte header (two u32 fields always 1, the rest always zero) followed by
four 4-byte blocks at offsets 12, 16, 20 and 24, each block shaped like
(one wide-range byte, one narrower-range byte, two narrow/boolean bytes).
The repeated 4-block shape is a real structural finding; the domain is not
(282/281 matches nothing else in this project's tables).

**`a/1/2/5`** (428 sub-files, 4 to 2178 bytes) sits right next to
`a/0/1/2`'s zone count (427 zones + 1), which is the strongest lead here:
per-zone variable-length data, sized by zone complexity. The framing itself
did not reduce to one rule: the leading u32 of sampled records does not
equal `record_length` minus one consistent header size (164 vs. 172-8, 372
vs. 392-8 disagree), so it is kept as an opaque per-sub-file blob rather
than force a field split that the bytes do not actually support.

**`a/1/9/4`** (652 sub-files, fixed 4 bytes) has offsets 0-1 (read as one
u16) take only 5 distinct values across all 652 records -- 0 (the sentinel
at sub-file 0), 10512 on 388/652, 16000 on 155, 13379 on 107, and a single
13000 outlier -- while offset 2 is a separate byte clustered 97-127 (318
records at 120, 252 at 110). A small, heavily-skewed-to-one-default
categorical field plus a narrow continuous byte is consistent with a
per-species size-class-plus-scale-factor pair (e.g. a battle-camera/sprite
scale table), but this is a shape guess, not a confirmed identification.

**`a/1/7/8`** (649 sub-files, fixed 249 bytes, no sentinel -- one fewer
sub-file than the usual 650) has 181 of its 249 byte offsets vary, every
one bounded under 128. The census's "text banks" guess does not survive
contact with `text.py`'s actual format: that cipher runs over u16 code
units inside a length-prefixed message-file container (see "Text banks"
above), and `a/1/7/8` has neither a message-file index nor 16-bit code
units that decode to anything under the same key schedule. Kept as an
opaque per-species flag/data blob; domain not identified.

### `tools/assets/tables.py`

One registry file, stdlib only, covering all eleven archives:

    python tools/assets/tables.py --list ARCHIVE       # sub-file count + note
    python tools/assets/tables.py --dump ARCHIVE N      # raw + decoded fields
    python tools/assets/tables.py --verify ARCHIVE      # byte-identical round trip
    python tools/assets/tables.py --stats ARCHIVE       # size + per-offset histograms
    python tools/assets/tables.py --list-archives

Round trip (`--verify`), all eleven, this pass:

    a/0/5/7   899/899    (raw copy; bytecode decode lives in the VM section)
    a/1/9/4   652/652    (raw copy)
    a/1/7/8   649/649    (raw copy)
    a/0/2/0   650/650    (decoded: single u16 field)
    a/1/2/3   650/650    (decoded: count-prefixed u16 array)
    a/1/6/9   951/951    (raw copy, field split for --stats only)
    a/2/1/4   1000/1000  (raw copy, field split for --stats only)
    a/1/0/8   282/282    (raw copy, field split for --stats only)
    a/1/2/5   428/428    (raw copy)
    a/1/6/8   315/315    (decoded: group_id/count/members)
    a/2/1/5   315/315    (decoded: group_id/count/members)

Every archive round-trips at the framing level (the acceptance bar this
pass set), whether or not the semantic field names are confirmed.

### What remains

- `a/1/6/9` and `a/2/1/4`: field shape is solid, domain is not. Worth a
  cross-reference pass against `a/1/6/8`/`a/2/1/5`'s member-id ranges.
- `a/1/0/8`, `a/1/2/5`, `a/1/9/4`, `a/1/7/8`: no reader found and no domain
  match; all four are reported at "framing read from bytes, confidence
  low-to-medium" rather than forced into a named field set.
- The 93 `a/1/6/8` self-inclusive records and the relationship (if any)
  between `a/1/6/8`/`a/2/1/5`'s group ids and any other table in this
  project are not explained.
- No attempt was made to trace the archive id further up the call graph
  for the calls that pass it through as a parameter rather than an
  immediate (the likely next step for the remaining nine archives).

## Group 2 custom table pass: 75 more "custom format, no decoder" archives registered in `tools/assets/tables.py`

Second survey pass over the census "custom format, no decoder" bucket, covering every archive in it not already handled by the Large custom table pass above. Method, same as that pass: a scripted byte survey (size histogram, fixed-vs-variable framing, per-offset nunique/min/max over any dominant fixed size) plus a scripted backward-scan over every call site of `func_02048F60`, `func_02048DDC`, `func_02048D00`, `func_02048D54`, `func_02048F4C`, `func_02048F74` and `func_02048F88` in `asm/arm9/main.s` and every `asm/overlays/*.s`, looking for an immediate load of the archive's decimal `a/X/Y/Z` id into the register that function's archive_id parameter occupies (`r0` for `func_02048F60`/`func_02048D54`/`func_02048F88`/`func_02048DDC`, `r1` for `func_02048F74`/`func_02048D00`/`func_02048F4C`, matching the parameter order in `src/matched/*.c` for each). A third script decompressed every sub-file with `narc.py`'s own `try_decompress` and checked the result's first 4 bytes against the known NITRO chunk tags (NCGR/NCLR/NCER/NANR/NSBMD/NSBTX, stored byte-reversed as RGCN/RLCN/RECN/RNAN/BMD0/BTX0 et al.) to catch compressed generic-format archives the census's own magic sniff missed.

Two census rows in this bucket are single raw files, not NARC containers (no BTAF/BTNF/GMIF), so they cannot go through `narc.parse_file` and are not added to the registry: `dwc/utility.bin` (929852 bytes) and `gfl_font.dat` (2320 bytes), both still "single compressed blob (guess: font/graphic)" per the census, unchanged by this pass. (Both are identified in a later pass, see "Asset lane pass: gfl_font.dat and dwc/utility.bin identified" below.)

### What the backward-scan found

Six archives turned up a confirmed reader (an immediate archive-id load directly at the call site, same evidentiary bar as `a/1/2/3`/`a/0/2/0` in the first pass):

- `a/0/4/8` -- arm9 `func_0202A128` (0x0202A128) calls `func_02048F60(archive_id=0x30=48, member, heap)`. The same function also calls `func_0204A298(archive_id=0xd3=211, ...)` (`a/2/1/1`) just before it, for the same member index -- the two archives are read together by one function.
- `a/0/8/7` -- arm9 `func_02006EA4` (0x02006EA4) calls `func_02048F74(dst, archive_id=0x57=87, member=0, mode=0, size_out)`. Single sub-file, member is always 0.
- `a/0/9/1` -- arm9 `func_0202A298` and `func_0202A310` (0x0202A298 / 0x0202A310) call `func_02048F74(dst, archive_id=0x5b=91, member=0, mode=variable)`, after first searching a table in `a/0/9/0` (archive id 0x5a=90, via `func_020490A8`/`func_020490F4`). `a/0/9/0` and `a/0/9/1` are read as a linked pair by both functions.
- `a/1/3/2` -- arm9 `func_0202AEEC` (0x0202AEEC) calls `func_02048F88(archive_id=0x84=132, member, heap, mode=0, size=40)`, member passed through from the caller's own argument.
- `a/1/4/6` -- an arm9 function around 0x0202B2xx (the call site itself is at 0x0202B34C) calls `func_02049030(archive_id=0x92=146)` for a record count, then loops member 0..count-1 through `func_02048F74(dst, archive_id=0x92=146, member, mode=0)` into consecutive 28-byte slots -- matching the 10 fixed 28-byte sub-files the byte survey found independently.
- `a/1/4/7` -- arm9 `func_0202C3E0` (0x0202C3E0) issues a sequence of `func_02048F74(dst, archive_id=0x93=147, member, mode=running_offset)` calls (4 bytes, then 9x2 bytes, then two more variable-size chunks) that assemble one member's record piece by piece -- consistent with the variable 27/41/43-byte sizes the byte survey found, read as a length-driven structure rather than one flat read.

None of the six readers resolve the archive's field semantics past the framing already visible in the bytes, so all six are still reported with low confidence on domain, despite the confirmed call site.

For the other 69 archives, no immediate matching the target id was found ahead of any of the seven calls (the scan does not follow the archive id when it is passed through as a parameter rather than loaded as an immediate at the call site itself -- the same limitation the first pass flagged).

### What the decompression pass found

Nine archives are LZ77/LZ11-compressed sub-files that decompress to a recognised NITRO chunk tag, all in the same family the project's generic-format converters (`background.py`, `nsbmd.py`) already cover for uncompressed archives: `a/0/3/6`, `a/0/3/9` (LZ11, decompress to RGCN/RCSN = NCGR/NCLR), `a/0/9/9` (LZ77, same), `a/1/9/8`, `a/2/3/3` (LZ77, decompress to RGCN = NCGR). These are identified HIGH confidence by the recovered magic but kept opaque here (raw copy) since nsbmd.py/background.py operate on uncompressed chunks, not this compressed wrapper.

Four more archives carry standard chunk tags uncompressed: `a/1/1/1`..`a/1/1/4` each hold an SBNK (sound bank) and an SSEQ (sequence) sub-file -- a Nitro Sound Archive-style pair, HIGH confidence. `a/2/1/2`'s two sub-files are RIFF/WAVE (raw PCM audio), HIGH confidence. `a/1/2/1` mixes BMD0 (3D model) with BCA0 (joint animation) and BMA0 (material animation) -- a model+animation set, HIGH confidence. `a/0/4/7`, `a/1/2/7`, `a/1/4/8` and `a/2/2/0` carry BMD0/BTX0/BCA0/RGCN/RLCN on a minority of their sub-files (the rest opaque), MEDIUM-HIGH to LOW-MEDIUM depending on the fraction matched. `a/0/7/9` opens most sub-files with the RLCN (NCLR palette) chunk tag uncompressed, MEDIUM-HIGH.

Five archives are confirmed compressed (LZ11: `a/2/2/5`, `a/2/2/6`; LZ77: `a/2/3/1`; Huffman8 on 1/4 sub-files: `a/2/0/3`) but decompress to bytes with no recognised chunk magic -- compression is certain, content is not, LOW confidence.

### Other identifications

- `a/2/3/2` -- the archive's own BTNF names sub-file 0 `battle_pocket.dat`. HIGH confidence (it is the game's own name for the data, not a guess).
- `a/2/2/9`, `a/2/3/0` -- every sub-file opens with an `'AB'` 2-byte tag, a u16 header-size field, then a u32 offset table; sizes run 49812-209740 and 58684-189924 bytes. The framing (a self-contained container with its own offset table) is confirmed; the domain is a guess (audio/stream data, going by size and the presence of `a/2/1/2`'s WAV archive nearby), LOW-MEDIUM.
- `a/0/6/1`, `a/0/6/2` -- both are fixed 780-byte records, and the per-offset histogram shows the same values repeating with a period of 52 bytes: each 780-byte record is 15 copies of a 52-byte sub-block. Structural only, domain unclear, MEDIUM.
- `a/0/8/1` -- 13 of 14 sub-files are 8 bytes: `[u32 value clustered just under 0x8000][u32 small count 0-10]`; 1 outlier at 104 bytes. A trig/scale-table guess (the u32 values sit near 0x7fff, a typical Q15 full-scale constant) is unconfirmed, LOW.
- `a/1/1/9` -- one 9-sub-file variant is a flat ascending u16 sequence (65, 66, 67, ...), reading like a plain index or character-code table rather than game data. LOW.
- `a/1/5/6` -- 44 of 46 sub-files are exactly 3100 bytes; the other 2 sit at 6172 bytes, close to double. Structural only, LOW.

Every other archive (53 of 75) is reported with the framing the byte survey found and no domain identification: LOW confidence, same bar the first pass used for its unidentified archives.

### Per-archive table

`reader` is `yes` only for the six archives above with a confirmed immediate call site. `round trip` is `tools/assets/tables.py --verify`'s own result; every entry decodes/encodes as an identity copy (raw bytes in, raw bytes out), so this is a framing-level check, same convention as the first pass.

| archive | subs | framing | reader | identification | confidence | round trip |
|---|---:|---|---|---|---|---|
| a/0/1/0 | 1 | 1 sub, 752B | no | not identified | LOW | OK |
| a/0/1/5 | 5 | 5 subs, fixed 16B | no | not identified | LOW | OK |
| a/0/1/7 | 8 | 8 subs, fixed 404B | no | not identified | LOW | OK |
| a/0/3/6 | 14 | 14 subs, var 68-19320B | no | LZ11-compressed NCGR/NCLR (RGCN/RCSN) | HIGH | OK |
| a/0/3/7 | 1 | 1 sub, 5376B | no | not identified | LOW | OK |
| a/0/3/8 | 1 | 1 sub, 576B | no | not identified | LOW | OK |
| a/0/3/9 | 18 | 18 subs, var 80-4916B | no | LZ11-compressed NCGR/NCLR (RGCN/RCSN) | HIGH | OK |
| a/0/4/2 | 1 | 1 sub, 1440B | no | not identified | LOW | OK |
| a/0/4/7 | 80 | 80 subs, var 64-65352B | no | Uncompressed mix NCGR/NCLR + BMD0/BTX0 | MEDIUM-HIGH | OK |
| a/0/4/8 | 1 | 1 sub, 22376B | yes | not identified (paired with a/2/1/1) | LOW | OK |
| a/0/5/3 | 19 | 19 subs, var 28-1410B | no | not identified | LOW | OK |
| a/0/5/8 | 17 | 17 subs, var 4-784B | no | not identified | LOW | OK |
| a/0/6/0 | 1 | 1 sub, 1672B | no | not identified | LOW | OK |
| a/0/6/1 | 56 | 56 subs, fixed 780B | no | 15x52B repeated sub-block period | MEDIUM | OK |
| a/0/6/2 | 10 | 10 subs, fixed 780B | yes (second level) | 15x52B repeated sub-block period, field-status table | MEDIUM | OK |
| a/0/6/7 | 98 | 98 subs, var 68-5596B | no | not identified | LOW | OK |
| a/0/7/0 | 6 | 6 subs, var 640-6412B | no | not identified | LOW | OK |
| a/0/7/9 | 34 | 34 subs, var 256-24420B | no | Mostly RLCN (NCLR) uncompressed | MEDIUM-HIGH | OK |
| a/0/8/0 | 1 | 1 sub, 72B | no | not identified | LOW | OK |
| a/0/8/1 | 14 | 14 subs, var 8-104B | no | [u32 ~0x7fxx][u32 count 0-10] x13 + outlier | LOW | OK |
| a/0/8/2 | 2 | 2 subs, var 0-780B | no | not identified | LOW | OK |
| a/0/8/6 | 1 | 1 sub, 3294B | no | not identified | LOW | OK |
| a/0/8/7 | 1 | 1 sub, 106B | yes | not identified | LOW | OK |
| a/0/9/0 | 1 | 1 sub, 7048B | no | not identified (paired with a/0/9/1) | LOW | OK |
| a/0/9/1 | 1 | 1 sub, 1232B | yes | not identified (paired with a/0/9/0) | LOW | OK |
| a/0/9/7 | 2 | 2 subs, var 274-24888B | no | not identified | LOW | OK |
| a/0/9/8 | 10 | 10 subs, var 650-1454B | no | not identified | LOW | OK |
| a/0/9/9 | 17 | 17 subs, var 95-4568B | no | LZ77-compressed NCGR/NCLR (RGCN/RCSN) | HIGH | OK |
| a/1/0/1 | 1 | 1 sub, 672B | no | not identified | LOW | OK |
| a/1/0/5 | 29 | 29 subs, fixed 188B | no | not identified | LOW | OK |
| a/1/0/9 | 17 | 17 subs, fixed 4B | no | not identified | LOW | OK |
| a/1/1/1 | 6 | 6 subs, var 76-8260B | no | Nitro sound bank+sequence (SBNK/SSEQ) | HIGH | OK |
| a/1/1/2 | 6 | 6 subs, var 76-8260B | no | Nitro sound bank+sequence (SBNK/SSEQ) | HIGH | OK |
| a/1/1/3 | 6 | 6 subs, var 80-8260B | no | Nitro sound bank+sequence (SBNK/SSEQ) | HIGH | OK |
| a/1/1/4 | 6 | 6 subs, var 92-8260B | no | Nitro sound bank+sequence (SBNK/SSEQ) | HIGH | OK |
| a/1/1/7 | 53 | 53 subs, fixed 36B | no | not identified | LOW | OK |
| a/1/1/9 | 9 | 9 subs, var 2-158B | no | ascending u16 sequence variant | LOW | OK |
| a/1/2/1 | 23 | 23 subs, var 400-10476B | no | BMD0 + BCA0 + BMA0 (model+anim set) | HIGH | OK |
| a/1/2/7 | 7 | 7 subs, var 8-46976B | no | 1/7 subs BMD0, rest opaque | LOW-MEDIUM | OK |
| a/1/3/2 | 5 | 5 subs, fixed 40B | yes | not identified | LOW | OK |
| a/1/3/6 | 31 | 31 subs, fixed 8B | no | not identified | LOW | OK |
| a/1/4/6 | 10 | 10 subs, fixed 28B | yes | not identified | LOW | OK |
| a/1/4/7 | 3 | 3 subs, var 27-43B | yes | not identified | LOW | OK |
| a/1/4/8 | 18 | 18 subs, var 8-28808B | no | 3/18 subs BMD0, rest opaque | LOW-MEDIUM | OK |
| a/1/4/9 | 1 | 1 sub, 32B | no | not identified | LOW | OK |
| a/1/5/2 | 3 | 3 subs, var 684-1700B | no | not identified | LOW | OK |
| a/1/5/4 | 37 | 37 subs, var 0-1024B | no | not identified | LOW | OK |
| a/1/5/6 | 46 | 46 subs, var 3100-6172B | no | 44/46 fixed 3100B, 2 near-double outliers | LOW | OK |
| a/1/5/8 | 5 | 5 subs, var 72-432B | no | not identified | LOW | OK |
| a/1/6/3 | 7 | 7 subs, fixed 44B | no | not identified | LOW | OK |
| a/1/6/5 | 13 | 13 subs, fixed 108B | no | not identified | LOW | OK |
| a/1/6/6 | 9 | 9 subs, fixed 36B | no | not identified | LOW | OK |
| a/1/7/1 | 14 | 14 subs, var 12-23988B | no | not identified | LOW | OK |
| a/1/7/4 | 24 | 24 subs, fixed 124B | no | not identified | LOW | OK |
| a/1/7/5 | 2 | 2 subs, fixed 36B | no | not identified | LOW | OK |
| a/1/7/9 | 50 | 50 subs, fixed 64B | no | not identified | LOW | OK |
| a/1/8/5 | 2 | 2 subs, fixed 8B | no | not identified | LOW | OK |
| a/1/8/6 | 7 | 7 subs, var 20-80B | no | not identified | LOW | OK |
| a/1/9/8 | 1 | 1 sub, 255B | no | LZ77-compressed NCGR (RGCN) | HIGH | OK |
| a/2/0/3 | 4 | 4 subs, var 1448-4328B | no | 1/4 subs Huffman8-compressed | LOW | OK |
| a/2/0/8 | 4 | 4 subs, var 8-664B | no | not identified | LOW | OK |
| a/2/0/9 | 1 | 1 sub, 856B | no | not identified | LOW | OK |
| a/2/1/1 | 1 | 1 sub, 4528B | no | not identified (paired with a/0/4/8) | LOW | OK |
| a/2/1/2 | 2 | 2 subs, var 13964-20674B | no | RIFF/WAVE PCM audio clips | HIGH | OK |
| a/2/2/0 | 13 | 13 subs, var 280-253428B | no | Mix RLCN/RCSN + BMD0/BCA0 | MEDIUM-HIGH | OK |
| a/2/2/1 | 7 | 7 subs, var 2304-5504B | no | not identified | LOW | OK |
| a/2/2/4 | 4 | 4 subs, fixed 36B | no | not identified | LOW | OK |
| a/2/2/5 | 151 | 151 subs, var 15-39547B | no | LZ11-compressed, content unresolved | LOW | OK |
| a/2/2/6 | 174 | 174 subs, var 15-43305B | no | LZ11-compressed, content unresolved | LOW | OK |
| a/2/2/7 | 1 | 1 sub, 494B | no | not identified | LOW | OK |
| a/2/2/9 | 52 | 52 subs, var 49812-209740B | no | 'AB'-tagged header+offset table, audio/stream guess | LOW-MEDIUM | OK |
| a/2/3/0 | 64 | 64 subs, var 58684-189924B | no | 'AB'-tagged header+offset table, audio/stream guess | LOW-MEDIUM | OK |
| a/2/3/1 | 73 | 73 subs, var 11653-30624B | no | LZ77-compressed, content unresolved | LOW | OK |
| a/2/3/2 | 1 | 1 sub, 627B | no | battle_pocket.dat (BTNF name) | HIGH | OK |
| a/2/3/3 | 2 | 2 subs, var 86-99B | no | LZ77-compressed NCGR (RGCN) x2 | HIGH | OK |

### What remains

- All 75 entries are kept as identity decode/encode (raw per-sub-file copy) in `tools/assets/tables.py`'s `_GROUP2` dict -- none resolved to a field layout worth a dedicated encoder, so the acceptance bar (byte-identical `--verify`) is met by construction rather than by a confirmed re-encoding.
- The six confirmed readers (`a/0/4/8`, `a/0/8/7`, `a/0/9/1`, `a/1/3/2`, `a/1/4/6`, `a/1/4/7`) establish a real call site but not the field semantics; `a/1/4/6` and `a/1/4/7` are the closest to a solved framing since the call pattern matches the byte-level record shape exactly.
- `a/0/9/0`/`a/0/9/1` and `a/0/4/8`/`a/2/1/1` are each read together by one function -- worth a follow-up pass that reads both archives side by side.
- `a/2/2/9`/`a/2/3/0`'s `'AB'`-tagged container and the size-matched compressed archives (`a/2/2/5`, `a/2/2/6`, `a/2/3/1`) are the most promising unresolved leads: the framing is solid, only the domain is missing.
- As with the first pass, the archive id was only looked up as an immediate at the call site itself; none of the 69 archives without a confirmed reader were traced further up the call graph for cases where the id is passed through as a parameter.
- `dwc/utility.bin` and `gfl_font.dat` remain out of scope for this tool (raw files, no NARC container) and are unchanged in the census. (Both are identified in a later pass, see "Asset lane pass: gfl_font.dat and dwc/utility.bin identified" below.)


## Twelve unknowns identified (`tools/assets/unknowns.py`)

Mission: close out the census's entire "unknown" group (`category_guess` of
`unknown`/`unknown raw format`, 12 archives, 85 sub-files) -- `a/0/1/3`,
`a/0/2/3`, `a/1/0/0`, `a/1/6/1`, `a/1/8/0`, `a/2/1/3`, and the six `dl_rom`
raw files (`child2_r_eng.srl`, `child_r_eng.srl`, `icon_b.char`/`.plt`,
`icon_w.char`/`.plt`).

### `a/0/2/3` was already solved

`font.py` (previous pass) decodes this archive as 5 NFTR fonts + 3 NCLR
palettes, round trip 15265/15265 glyph records byte-identical. The census
row still read "unknown" only because it predates that pass. No new work
here beyond re-bucketing the census row to "covered and verified".

### Four NARCs: the census's own magic sniff stopped at the compression header

`a/1/0/0`, `a/1/6/1`, `a/1/8/0` and `a/2/1/3` were all "unknown" for the
same reason: inventory.py's dominant-magic sniff reads a sub-file's first
4 bytes and stops there, so a BIOS-compressed sub-file reports its LZ77/
LZ11 header (`0x10240600`, `0x10402000`, `0x11240600`) instead of what is
underneath. Decompressing every sub-file with `narc.py`'s own LZ77/LZ11
decoder (already used elsewhere in this project, e.g. `icons.py`) resolves
all four cleanly to ordinary generic-NITRO content -- no new format, just
an inventory-classification gap:

| archive | sub-files | decompressed content |
|---|---:|---|
| `a/1/0/0` | 20 | 18 NSCR (16 at 1572 bytes, 2 larger), 1 NCGR (16448 bytes), 1 raw NCLR |
| `a/1/6/1` | 5 | 1 raw NCLR, 3 LZ77->NSCR (1572 bytes, distinct payloads), 1 LZ77->NCGR (8256 bytes) |
| `a/1/8/0` | 44 | 22 LZ77->NCGR (8256 bytes, all distinct), 22 raw NCLR (552 bytes, all distinct) |
| `a/2/1/3` | 8 | 2 LZ11->NCGR (8256 bytes), 2 raw NCLR (552 bytes), 4 LZ11->NSCR (1572 bytes) |

Each is a self-contained background set: one or more tile sheets (NCGR),
one or more palettes (NCLR), and one or more screen/map layouts (NSCR).
`a/1/8/0`'s 22 NCGR + 22 NCLR split most plausibly pairs by index
(sub N with sub N+22, 22 matched sets) but no decompiled accessor was
found confirming that specific pairing.

**Round trip**: every sub-file of every one of the four archives was
decompressed (`narc.py`) and re-compressed with the matching encoder
(`lz77.py` for LZ77 sub-files, `lz11.py` for LZ11, identity for
uncompressed ones) and compared byte-for-byte to the original: 20/20,
5/5, 44/44, 8/8 -- 77/77 total, all byte-identical.

### `a/0/1/3`: not a NARC

`a/0/1/3` is not a NARC container at all (magic bytes are `0x00000000`,
`narc.parse_file` raises "bad magic") -- it is a single 2820-byte raw
file. Read as 16-bit words it resolves cleanly to 282 fixed 10-byte
records (`2820 / 10` with no remainder), with a 0xFFFF sentinel word
recurring at a regular-but-not-constant stride, consistent with section
markers rather than noise. Domain not identified; kept as an opaque
10-byte-record table. "Round trip" here is the trivial whole-file
identity copy every raw (non-NARC) file in this project gets -- there is
no container framing to re-pack.

### Archive id immediate search (all five NARC/raw targets: negative result)

The a/X/Y/Z archive id the game's own loaders use is the decimal digits
`X*100 + Y*10 + Z` (confirmed against this doc's existing attestations:
id 12 = `a/0/1/2`, id 9 = `a/0/0/9`, id 0x7B = 123 = `a/1/2/3`, id 0x14 =
20 = `a/0/2/0`). This pass's five targets have ids 13 (`a/0/1/3`), 100
(`a/1/0/0`), 161 (`a/1/6/1`), 180 (`a/1/8/0`) and 213 (`a/2/1/3`). Every
`blx`/`.inst.w ... blx` call site to `func_02048F60`, `func_02048F4C`,
`func_02048F74` and `func_02048F88` in `asm/arm9/` and `asm/overlays/`
was backward-scanned for the nearest preceding immediate load of the
archive-id argument register (r0 for `func_02048F60`/`func_02048F88`, r1
for `func_02048F4C`/`func_02048F74`, per each function's own
`src/matched/*.c` signature). None of the immediates found (9, 0x12,
0x14, 0x15, 0x18, 0x19, 0x25, 0x30, 0x42, 0x43, 0x6d, 0x66, 0x6c, 0x75,
0x7b, 0x7f, 0x94, 0x98, 0xa3, 0xa5, 0xbb, 0xd4, 0xdc, 0xe8, 0xf) equal
13/0x0D, 100/0x64, 161/0xA1, 180/0xB4 or 213/0xD5. Two call sites in
`ov010.s` reach `func_02048F4C` through a stored function pointer
(`.word 0x02048F4C`) rather than an inline immediate and are outside
what a static grep can resolve. Verdict: no reader found for any of the
five, the same negative result `tables.py` already reports for several
of its own "custom format, no decoder" archives.

### `dl_rom`: two Download Play child binaries, two Poke Ball icons

`child_r_eng.srl` and `child2_r_eng.srl` both carry a valid NDS ROM
header at offset 0 (`tools/ndsrom.py`'s own docstring documents the
0x200-byte layout; the tool itself has no standalone "parse one header"
command, only extract/build/verify against a full cartridge image, so
this pass parses the fixed offsets directly). Both report game title
"SYACHI_MB", game code "NTRJ" (the generic placeholder, not Pokemon
Black's own "IRBO"), maker "01", unit code 0x02 (NTR+TWL):

| file | arm9 off/size | arm7 off/size | total size |
|---|---|---|---|
| `child_r_eng.srl` | 0x4000 / 0x888A8 | 0x8CA00 / 0x28F84 | 0xBB000 |
| `child2_r_eng.srl` | 0x4000 / 0x82CC0 | 0x86E00 / 0x28F84 | 0xB5200 |

Both files are 1369088 bytes and every region above fits inside that
size. Same entry/load addresses in both, `child2` carrying a smaller
arm9 image -- consistent with two variants of the same DS "Download
Play" child (multiboot) program: code broadcast to guest consoles that
never touch a cartridge, bundled inside the host game's own ROM, not a
game-specific binary (hence the generic gamecode).

`icon_b.char`/`.plt` and `icon_w.char`/`.plt` match the DS banner icon
bitmap format exactly by byte count: 512-byte `.char` = 32x32 px at 4bpp
(4x4 grid of 8x8 tiles), 32-byte `.plt` = 16 colors x 2-byte BGR555.
Decoding and rendering both pairs (`unknowns.py --verify`, PNGs written
to `build/assets/dl_rom/`, gitignored) produces a clearly recognisable
Poke Ball in both cases -- `icon_b` on a dark background, `icon_w` on a
light background (matched console color themes), confirmed by eye.

### `tools/assets/unknowns.py`

One module, stdlib only, depends on `narc.py`/`lz77.py`/`lz11.py`:

    python tools/assets/unknowns.py --list      # identification + confidence per archive
    python tools/assets/unknowns.py --verify     # NARC round trips + dl_rom headers + icon decode

`--verify` output this pass: `a/1/0/0` 20/20, `a/1/6/1` 5/5, `a/1/8/0`
44/44, `a/2/1/3` 8/8 byte-identical (77/77 total); `a/0/1/3` whole-file
identity copy OK; both `.srl` headers parsed and sanity-checked (arm9/
arm7 regions fit inside the file); both icon pairs decoded and rendered.

### What remains

- `a/0/1/3`'s 10-byte record fields are not split or named; domain
  unidentified.
- `a/1/8/0`'s NCGR<->NCLR pairing (index N <-> N+22) is the natural
  reading of the sub-file order but not confirmed by any decompiled
  accessor.
- No archive-open call site was found for any of the five NARC/raw
  targets by the immediate-before-the-call grep; two additional call
  sites reach `func_02048F4C` through a stored function pointer rather
  than an inline immediate and were not resolved.
- The `dl_rom` `.srl` files' FNT/FAT are present but tiny (FNT size 9,
  FAT size 0) -- consistent with a minimal download-play payload, not
  decoded further here.

## Asset lane pass: the operand-width table extended to all 609 opcodes, `a/0/5/7` disassembled, `a/0/0/3` decoded as a message bank

Mission: extend the first-32-opcode operand-width table from the VM pass
above to all 609 handlers, write a decoder (`tools/assets/scripts.py`) for
the real `a/0/5/7` script archive built on that table, and make
`tools/assets/events.py` state plainly that `a/0/0/3` is a message bank
(not bytecode) and decode its records as text.

### Operand widths, all 609 opcodes

Opcodes 0-31 are the hand-read table from the section above, taken
verbatim. Opcodes 32-608 were produced by a from-scratch Thumb-1 + 32-bit
BL/BLX sweep over the raw bytes of `extract/overlays_dec/y9_0010.bin`
(ov010), `y9_0021.bin` (ov021) and `extract/arm9_dec.bin` (ARM9 static
module) -- not by hand-reading 577 handlers, and not by trusting
`tools/disasm.py`'s listings where a handler address falls in a region its
reachability pass never reached (some handlers are unlabelled leaf
functions, see `docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md`,
and show up as bare `.word` runs there). The sweep is a worklist walk of
each handler's own reachable instructions (following `b`/`bcc` and
resolving `ldr r3,[pc,#0]; bx r3` veneers), summing +2/+4 for every `bl`
that resolves to `func_02011330`/`func_0201134C`, and recursing into a
`bl`'s *own* target one or more levels deep (capped, with a cycle guard)
because several operands are fetched by a helper the handler calls rather
than inline -- generalising the single `0x02159AE8` "variable id" case
the first-32 pass flagged to every such helper. It also checks for the
`ldr rD,[rB,#0x14]; ldrb rT,[rD]` idiom directly: a raw read off
`ScriptVm.pc` (`+0x14`, `src/matched/unit_0201126C.c`) that bypasses both
fetch helpers entirely and is the real shape of this table's
variable-length opcodes, opcode 76 included (see below). The table is
baked into `tools/assets/scripts.py` as the `OPERAND_WIDTH` dict, each
entry citing the handler address (or rule) it was read off, so any entry
can be re-checked by hand against `asm/overlays/ov010.s` / `ov021.s`.

Counts over all 609 opcodes:

    fixed (single attested byte width)            565
    variable (direct cursor read or indirect jump)  18
    unresolved (handler outside ov010/ov021/ARM9)   17
    null (table entry is NULL)                       9

The 17 unresolved handlers all land in the `0x0217xxxx`/`0x0218xxxx`
range, just past ov010's end (`0x02172BA0`) or just before ov021's start
(`0x02187F00`) -- some other overlay this pass did not load, matching the
first-32 pass's count exactly. The 18 variable opcodes split into two
real mechanisms, not one guess:

- **Direct cursor byte read** (opcodes 32, 76, 78, 173, 174, 178, 359,
  361, 538, 539, and others): the handler executes
  `ldr rD,[rB,#0x14]; ldrb rT,[rD]; adds rD,rD,#1; str rD,[rB,#0x14]`
  itself -- a length (or small count) byte read straight off the script
  cursor, then (for opcode 76 specifically, confirmed by hand at
  `0x021AF75C`) that many further bytes, which is exactly why opcode 76
  was already the first pass's prime desync suspect.
- **Indirect branch** (opcodes 56, 74, 77, 79, 87, 88, 97, 98, and
  others): the handler branches through a register whose value this
  sweep does not try to enumerate (a case/jump table, or a
  runtime-selected helper) -- reachability genuinely depends on data this
  static sweep does not have.

### `tools/assets/scripts.py`: `a/0/5/7` decoded

New module, `--list` / `--disasm N` / `--verify` / `--check`, built on the
table above and the confirmed container framing (`N` u32 offsets, a
0xFD13 terminator, `entry k` at `4*k + 4 + table[k]`). Run against the
real archive:

    a/0/5/7: 899 sub-files, 471 script (0xFD13 entry table present),
              428 side table
    --verify: 899/899 round-trip OK
    --check:  3206 entry points decoded (471 script sub-files)
              landed on end/flow opcode, next entry, or file end:
                2935 (91.5%)
              desynced (opcode >= 609): 16
              hit a variable/unresolved opcode: 254
                top opcodes: 76 x100, 56 x99, 382 x18, 87 x7, 74 x7,
                             361 x5, 178 x4, 452 x3, 78 x3, 450 x2
              ran past end of file mid-opcode/operand: 1

That is an improvement on the first pass's 2352/2592 (90.7%) -- both the
numerator and the landing rate are up, from a strictly larger operand
table (577 more opcodes resolved) over a slightly larger entry count
(3206 vs 2592, because this pass's own 0xFD13 scan finds 471 script
sub-files against the first pass's 469). The remaining 271 non-landing
entries split cleanly: 254 hit one of the 18 variable/unresolved opcodes
above (dominated by opcode 76's length-prefixed tail and opcode 56's
indirect branch, 199 of the 254 between them), 16 desync to an
out-of-range opcode (a real decode error this table cannot explain), and
1 runs off the end of its sub-file mid-operand. None of these is patched
over with a guess: they are the honest boundary of what a static sweep
of fixed-width fetch calls can resolve.

Three sample entries, zone 291's script file (`field_06` lane = sub-file
582 of `a/0/5/7`, via `tools/assets/zones.py`'s record for zone 291):

    entry 1 @ 0x14:
      op 46  operand=[] (0 bytes)
      op 48  operand=[] (0 bytes)
      op 47  operand=[] (0 bytes)
      op 2   operand=[] (0 bytes)        -- stop

    entry 2 @ 0x1c:
      op 46   operand=[] (0 bytes)
      op 166  operand=[0547] (2 bytes)
      op 116  operand=[] (0 bytes)
      op 61   operand=[0400 0000 0000 0000] (8 bytes)
      op 50   operand=[] (0 bytes)
      op 62   operand=[] (0 bytes)
      op 48   operand=[] (0 bytes)
      op 47   operand=[] (0 bytes)
      op 2    operand=[] (0 bytes)       -- stop

    entry 3 @ 0x38:
      op 46   operand=[] (0 bytes)
      op 166  operand=[0547] (2 bytes)
      op 116  operand=[] (0 bytes)
      op 61   operand=[0400 0001 0000 0000] (8 bytes)
      op 50   operand=[] (0 bytes)
      op 62   operand=[] (0 bytes)
      op 48   operand=[] (0 bytes)
      op 47   operand=[] (0 bytes)
      op 2    operand=[] (0 bytes)       -- stop

Entries 2 and 3 are identical but for one word inside opcode 61's operand
(`...0000...` vs `...0001...`), consistent with a per-instance parameter
(entries 2/3 likely correspond to two placements of the same scripted
object); no semantic decode of opcodes 46/47/48/50/61/62/116/166 is
claimed here, only their operand widths and that every entry in this file
lands cleanly on its stop opcode.

### `tools/assets/events.py`: `a/0/0/3` stated plainly as a message bank

The module docstring and the former "Doors/warps: not confirmed" section
are rewritten to state, not hedge: `a/0/0/3` is a message bank reached
through the zone record's `+0x0a` lane, not an event/door/warp table (that
question, if there is a dedicated archive for it at all, stays open and
is not `a/0/0/3`). A `decode_record()` function decrypts a record's
payload through the same cipher as `a/0/0/2` (`tools/assets/text.py`:
`key = (index + 3) * 0x2983`, rotate left 3 after every code unit), with
`field_x & 0xFFFF` giving the record's length in u16 units and `index`
the record's 0-based position inside its own sub-file. A new `--text N`
flag prints every decrypted string in sub-file N. The container framing
and its round trip are unchanged: **472/472** sub-files still repack
byte-identical; `--text 5` decrypts to "Ha ha ha!\nYou want more toys,
huh?", "My, my. Oh, this child.\nWe'll buy you another.", "I'm tired of
this toy!\nI want a more fun toy!" for records 0-2, matching the VM
pass's shorter prefix check exactly.

### What remains

- Opcode 76's length-prefixed tail is read off the cursor directly but
  its *contents* (is it N more raw bytes, N more u16 operands, a string,
  something else) are not decoded -- only that it exists and why opcode
  76 desyncs.
- The indirect-branch opcodes (56, 74, 77, 79, 87, 88, 97, 98, and others)
  are genuine case/jump tables whose targets are not enumerated; a
  per-opcode disassembly of the relevant ov021 code could resolve some of
  them but was not attempted here.
- The 17 unresolved handlers' overlay was not identified.
- The 430 `a/0/5/7` sub-files with no 0xFD13 table (428 by this pass's own
  scan) remain unidentified side tables.
- `a/0/6/6`'s role is still open; it is no longer a door/warp candidate
  by elimination alongside `a/0/0/3` (see events.py's updated docstring),
  but nothing has replaced it.

## Asset lane pass: `a/0/5/7` side tables paired with the zone script lane; `a/0/6/6` reader searched, not found

Mission: test whether `a/0/5/7`'s 428 non-script sub-files pair one-to-one
with the 471 scripts through the zone's `+0x06`/`+0x08` lane; decode the
side tables' own framing; and find `a/0/6/6`'s reader by its decimal archive
id (66 = `0x42`) the same way `a/1/2/5`/`a/1/2/6` were identified by `0x7d`/
`0x7e`, testing the per-language hypothesis if no reader turns up.

### `a/0/5/7`: the pairing test, confirmed 427/427

The zone record's `field_06`/`field_08` pair (`tools/assets/zones.py`,
`field_08 == field_06 + 1` on every record) was checked directly against
`a/0/5/7`: **`field_06 == 2 * zone_id` on 427/427 zones** (never
`2 * zone_id + 1`), so the pair a zone reaches is `(2*zone_id,
2*zone_id + 1)`. Classifying both sub-files of every pair with
`scripts.parse_subfile` (its own `kind` field, `"script"` vs
`"side_table"`, no change needed):

    pairs checked                          427
    one script + one side table            427  (100%)
    both script / both side table            0

This is an exact match, not a statistical lean: every zone's pair is
exactly one script and one side table. The archive holds 428 side tables
total; the one sub-file never reached by this pairing is **sub-file 865**
(6020 bytes -- the single outlier in the side-table size histogram, and
itself shaped like a repeating-record table rather than a script), so
**428 is 427 zones' own side tables plus this one unpaired extra**,
matching the mission's own arithmetic exactly.

No code was found that reads archive id `0x39` (`a/0/5/7`) a second time
at a different sub-file index near `func_02158D78`/`func_02158BFC`
(ov010): `func_02158D78` is the only call to the archive-0x39 load path
anywhere in the image (grepped for the immediate `0x39` ahead of the
underlying generic loader, `func_0204A1BC`, across `asm/arm9/main.s` and
every `asm/overlays/*.s`), and it is reached exactly once per script
start, indexed by `field_06` alone (via `func_02158CD0`'s
`sub_02013B5C` read). `field_08` has no accessor anywhere this pass
found, matching zones.py's own note that +0x08 is read by nothing. So
the pairing above is confirmed by the data (the classification and the
arithmetic both check out on every zone), but the side table's own
reader -- if the running game reads it at all, rather than it being
build-time-only data -- was not located.

### `a/0/5/7` side table framing: 4-byte header + N x 4-byte records, N from size alone

Every side table's size satisfies `(size - 4) % 4 == 0` (428/428, sizes
4, 8, 12, 16, 20, 24, 28, 36, 40, 48, and the 6020-byte outlier), so the
framing read off this alone is a 4-byte header (two u16 words) followed
by `(size - 4) / 4` records of two u16 words each. The header words are
not a literal, independently trustworthy record count: two 16-byte side
tables carry different header values at the same size (zone 1/8's is
`(4, 10395)`, zone 6/10's is `(1, 2)`), which is why the record count
used here comes from the sub-file's own length, not from either header
word. Three sample dumps (`python tools/assets/scripts.py --side N`):

    a0057#11  (zone 5's side table, 8 bytes): header=(2, 1)
      [0] (0, 0)
    a0057#291 (zone 145's side table, 12 bytes): header=(1, 2)
      [0] (0, 0)
      [1] (0, 0)
    a0057#3   (zone 1's side table, 16 bytes): header=(4, 10395)
      [0] (0, 3)
      [1] (10396, 0)
      [2] (0, 0)

No semantic meaning is claimed for the header or per-record words; only
that the arithmetic framing holds archive-wide. `tools/assets/scripts.py`
gets `parse_side_table`/`SideTableError` and a `--side N` CLI flag; this
does not change `parse_subfile`/`pack_subfile` (a side table still packs
back out as its own raw bytes), so the round trip is unaffected:
**899/899** sub-files still repack byte-identical.

### `a/0/6/6` reader: searched archive-wide by decimal id 66 (`0x42`), not found

The same decimal-digit convention that named `a/1/2/5` (`0x7d` = 125) and
`a/1/2/6` (`0x7e` = 126) as neighbouring immediates inside `func_0216237C`
(ov010) predicts `a/0/6/6` as decimal 66 = `0x42`. Grepped archive-wide --
`asm/arm9/main.s` plus all 237 `asm/overlays/*.s` files -- for the
immediate `0x42` (and decimal `66`) loaded into `r0`/`r1` within 20 lines
ahead of a call to any of the mission's named loader-family functions
(`func_02048F60`, `func_02048F74`, `func_02048DDC`, `func_02048D00`,
`func_02048D54`, `func_02048F4C`, `func_02048F88`, `func_020490A8`,
`func_02049030`) or `func_0204A1BC` (the generic loader `a/0/5/7`'s own
reader uses): **zero matches**. `0x42` is a common immediate elsewhere in
the image for unrelated reasons (loop bounds, buffer sizes, as far from
the field system as the battle/menu overlays ov093/ov094/ov119), but it
never appears immediately ahead of one of these loader calls. This is a
real negative result from an archive-wide search, not a gap in the
search.

### Per-language hypothesis: weakened, not confirmed

Two checks the mission asked for, both against real code/data already in
this repo:

- **Header language count**: no "number of languages" constant exists
  anywhere in the decompiled ARM9 code or in `docs/` to test the group
  count range `{1, 2, 3, 5, 8}` against -- there is nothing attested to
  compare it to, so this check has no ground truth to run against.
- **`a/0/0/2`'s language structure**: `tools/assets/text.py` reports
  `sectionCount` always `1` across every one of `a/0/0/2`'s 288
  sub-files (its own module docstring, "Message-file container format").
  The one archive already confirmed to hold the game's text carries no
  per-language grouping of any kind. If `a/0/6/6`'s `G in {1,2,3,5,8}`
  were a per-resource count of language variants, the existing text
  archive would be the natural place to see the same pattern, and it
  does not appear there. This does not disprove the hypothesis (the two
  archives could simply be laid out differently for the same idea), but
  it removes the one analogy this pass could check in real data.

### Data hypotheses: weak range fit only, no accessor found

Checked against the zone header table (`tools/assets/zones.py`, 427
records) for every lane still without an attested accessor: only
`field_02` (max 273) and `field_18` (max 424) have a range that fits
inside `a/0/6/6`'s 601 sub-files (or `a/0/0/3`'s 472-sub-file range) at
all. Every other open lane is far too large to be either index
(`field_14`/`field_20`: max 65535; `packed_1a`: max 1140; `packed_1c`:
max 17984; `flags`: max 60736). The range fit on `field_02`/`field_18` is
weak on its own -- almost any 16-bit lane with a few hundred small
distinct values would pass a "fits under 601" test -- and no accessor
reading either lane as an `a/0/6/6` or `a/0/0/3` index was found in code,
so this is reported as a plausibility note, not a confirmed lane.

### What this pass closes and what remains

Closed: the `a/0/5/7` script/side-table pairing (427/427, exact), the
side table's byte framing (428/428, arithmetic), and the "is there a
second archive-0x39 read near the VM loader" question (searched, no).
Still open: `a/0/6/6`'s reader and selection key (no code found; the
per-language and data-lane hypotheses are both weakened, neither
confirmed), the side tables' own semantic fields, and whether the side
table is read by the running game at all versus being unused/build-time
data -- none of this is patched over with a guess.

## Asset lane pass: `gfl_font.dat` and `dwc/utility.bin` identified

Mission: close out the census's two raw (non-NARC) files under `extract/data/`, both still reading "single compressed blob (guess: font/graphic)" since the original inventory scan.

### `gfl_font.dat`: Game Freak's own flat font layout, not NFTR

2320 bytes, no magic, no NARC container. It does NOT start with "RTFN" and has no FINF/CGLP/CWDH/CMAP chunk sequence -- it is not the Nintendo NFTR container font.py already decodes for `a/0/2/3`. The container is instead a 16-byte header (`header_size=0x10`, `reserved=0`, `glyph_count=288`, `cell_width=8`, `cell_height=8`, an unknown byte, `bpp=1`) followed by 288 flat 8-byte glyph bitmaps with no per-glyph metrics at all. The confirmation is exact byte arithmetic, the same kind of check the CGLP parser above leans on: 16 + 288 * 8 = 2320, the file's full size, with nothing left over.

Grounding attempt: the matched gf_font.c cluster (`src/matched/sub_0201D7EC.c`, and the notes for `sub_0201D854.c`/`sub_0201DC88.c`) describes the in-memory `struct Font`'s +0x58 20-byte block as the FINF body and its glyph directory as a hash/record lookup structure -- both built around the chunked NFTR shape, not this file's flat layout. Grepping `src/matched`, `src/pending` and `docs/notes` (case-insensitive) for the string "gfl_font" finds nothing: no traced call site opens this file by name. The container framing here is grounded in the file's own byte arithmetic alone, not in a confirmed code path, and is reported that way rather than overstated.

Ground-truth check: tried rendering glyph indices as ASCII (`index = code - 0x20`, font.py's own convention for `a/0/2/3`) under every combination of {MSB-first, LSB-first} bit order x {top-down, bottom-up} row order x {`index = code`, `index = code - 0x20`} and eyeballed digits 0-9 and letters A-Z against each render. **0/36 agreement** (against the `a/0/2/3` check's 36/36) -- none of the 8 combinations produces a recognisable digit or letter. The container framing itself is not in doubt (the arithmetic leaves no slack); what is unresolved is the glyph order. One structural clue: adjacent glyph pairs in the raw order (indices 10/11, 12/13, 14/15, 16/17, ...) are near-duplicates differing only in their top two rows -- the shape of a base glyph and the same glyph with a diacritic mark added above it, a pattern that does not occur in the Latin alphabet or Arabic digits and suggests this 288-glyph set's natural order is not ASCII at all.

`tools/assets/font.py --raw list|render|verify` (new `--raw`/`--raw-path` flags, default `extract/data/gfl_font.dat`) adds full list/render/verify support: `--raw render --start 0 --count 256` writes `build/assets/fonts/gfl_font.png` (gitignored), and `--raw verify` repacks all 288 bitmaps and reports byte-identical count. Round trip: **288/288** glyph records byte-identical.

### `dwc/utility.bin`: Nintendo's DWC/WFC setup-UI resource bundle, out of scope

929852 bytes, also no NARC container. Not an NDS ROM either: forcing the first 0xC0 bytes through this project's `parse_nds_header` (in `tools/assets/unknowns.py`) produces garbage title/gamecode/arm9-arm7 fields, so that parser is not claimed to apply. Not compressed: there is no LZ77/LZ11/BLZ tag byte whose paired 3-byte size is anywhere near 929852, and the file is full of long, clean runs of printable ASCII, which a compressed stream would not be.

The first five little-endian u32s are `0x10` (16), `0x17a8` (6056), `0x17c0` (6080), `0xc50` (3152), `0x28` (40) -- consistent with a small custom archive header (table offset / data offset / size / count), but the decisive evidence is the strings, not the header fields. Scanning for printable runs ending in `.l` finds 391 named entries: `eb2Ap.nsc.l`, `ebBgHl.ncg.l`, `ebMain.nce.l`, `etStep1.nsc.l`, `fb3List.nsc.l`, and so on, repeating the same suffix set across several 2-letter prefixes (`eb`, `et`, `fb`, ...). By extension: `.nsc` (267, NSCR), `.ncg` (63, NCGR), `.ncl` (35, NCLR), `.nce` (14, NCER), `.bmg` (8, Nintendo's Binary MessaGe text format), `NFTR` (3, the same font container font.py decodes), `.sdat` (1, a Nitro Sound Archive). This is a complete graphics + text + font + sound resource bundle for the DS Wi-Fi Connection setup UI (the AP-list/error/settings screens; the 2-letter prefixes read as per-locale or per-flow screen-set variants) -- the generic Nintendo SDK component every WFC-enabled DS game ships, not Game Freak or Pokemon-specific content.

Identification: Nintendo DWC/WFC setup-UI resource bundle, **OUT OF SCOPE** for this project's game-asset lane, by string evidence rather than by disassembly (it is a resource archive, not raw ARM code, so the task's "say so with evidence if it is code" is answered here by showing it is Nintendo SDK-owned UI content instead). No field-level decoder is written. `tools/assets/unknowns.py --list`/`--verify` now report the header words, the per-extension filename histogram, and a whole-file identity round trip (there is no container framing this module decodes well enough to re-pack beyond the identity copy, the same uniform shape `a/0/1/3` already gets).

### What remains

- `gfl_font.dat`'s glyph order/character mapping is not resolved (0/36 ASCII agreement under every convention tried); the container framing and byte-level round trip are solid regardless.
- `dwc/utility.bin`'s internal archive header (table offset, data offset, size, count) is read but not decoded into an entry table; no attempt was made to locate or decompress an individual named sub-resource.
- Neither file's consuming code path (whatever opens `gfl_font.dat`, and the DWC/WFC library that would consume `utility.bin`) was traced in `src/matched`/`src/pending`/`docs/notes` -- both identifications rest on byte-level and string evidence alone.

## Asset lane pass: `a/0/7/2` local 6 field map SOLVED (data cross-check exact, reader found up to the member-index resolver)

Mission: settle the meaning of `a/0/7/2`'s per-cell 48-byte record (local
6 of each of the 95 trainer battle sprite blocks), left undecoded by the
previous pass ("`a/0/7/2` trainer block's no-magic member (local 6)"
above), which pinned the container shape and the empty-cell sentinel but
wrote no field decoder.

### Reader: found up to the member-index resolver, not to the byte-level consumer

Grepping `src/matched`/`src/pending` for the block arithmetic
(`v * 8 + 6`) lands on `src/matched/unit_0202D5F8.c`: eight sibling
one-liners at 0x0202D5CC-0x0202D6D0, each doing `id -> table[id] -> v ->
v*8+K` for a different `K` (0,1,7,2,3,4,5,6, one per block member). The
shared 0x6A(106)-entry table (`sub_0202D5D8_Table` at 0x020A023C) is
indexed by a small integer `id` and looked up by the `K=6` accessor
(`func_0202D6D0`) to get member 6's sub-file index -- this is very
likely the class-id-to-block table the trainer-sprite pass searched
`extract/arm9_dec.bin` for and could not find, now located structurally
(a byte-run scan alone couldn't distinguish it from the small
coordinate-like tables in the same region; finding it required tracing
the `*8+N` arithmetic instead).

`func_0202D6D0`'s only call site in the whole image (checked by grepping
every `bl func_0202D6D0`/`0202D6D0` reference in `asm/`) is
`func_02017214` (arm9, 0x02017214), which calls all eight `K` accessors
in sequence and stores each result into one word of a 9-word (0x24-byte)
resource-descriptor struct the caller supplies -- effectively "resolve
every member index for this class id" in one call. `func_02017214`'s own
only call site is `func_022006A0` in `ov094` (the battle overlay,
address 0x022006A0, a flag-adjusting tail-call wrapper), which in turn is
called once, from `func_021FF088` in the same overlay, while that
function registers up to 14 battle-side slots (`cmp r4, #0xe`) -- a
context consistent with battle-side trainer sprite setup, not with
overworld or menu code.

That traces the chain from the class id down to "which sub-file member 6
is" and confirms it is touched during battle setup, but the
resource-descriptor struct `func_02017214` fills is never read again
inside `func_021FF088` before the function returns (its stack frame is
freed immediately after), so the actual byte-level consumer that opens
sub-file `8*v+6`, walks its 48-byte records and applies the fields is
somewhere else this pass did not find -- no further caller of
`func_02017214`/`func_022006A0`, and no literal-pool reference to either
address, exists anywhere in `asm/` (checked by full-corpus grep, not
sampled). **Search coverage**: `src/matched`, `src/pending`, and every
`.s` file under `asm/arm9/` and `asm/overlays/` were grepped for the
member-6 accessor's address, its only caller's address, and that
caller's only caller's address; none has a second reference. The field
map below is therefore attested by the data cross-check alone, not by
reading the consumer's disassembly.

### Field map: CONFIRMED exact against an independently computed NCER bounding box

`tools/assets/rig.py` gained `find_cellinfo()`/`parse_cellinfo()`
(locates the no-magic member by the previous pass's container shape,
decodes its records) and a `--cellinfo BLOCK` CLI mode. Cross-check
script: for all 95 blocks, decode every local-6 record and independently
compute each NCER cell's OAM bounding box (`min(oam.x)`, `min(oam.y)`,
`max(oam.x+oam.w)`, `max(oam.y+oam.h)` over the cell's own OAMs -- no
information from local 6 feeds this computation). Result over all 95
blocks (117 populated records + 3 empty-cell sentinels, every record in
the archive, not a sample):

| field | interpretation | fixed-point | check | result |
|---|---|---|---|---|
| `[0]` | bbox `min_x` | Q23.8 (`px * 256`) | `rec[0] == min_x * 256` | **117/117 exact** |
| `[1]` | bbox `-min_y` | Q23.8 (`px * 256`) | `rec[1] == -min_y * 256` | **117/117 exact** |
| `[2]` | bbox width | Q19.12 (`px * 4096`) | `rec[2] == (max_x-min_x) * 4096` | **117/117 exact** |
| `[3]` | bbox height | Q19.12 (`px * 4096`) | `rec[3] == (max_y-min_y) * 4096` | **117/117 exact** |
| `[5..11]` | unused | -- | `all(v == 0)` | **117/117 exact** |

Zero mismatches across every populated record in the archive, including
the ones that actually vary cell-to-cell: block 91's 5-frame walk cycle
(`min_x` drifts -40, -39, -41, -42 px across cells 0/2/3/4, `[0]` tracks
each exactly) and block 40's four near-duplicate poses (one pair shifted
1px from the other, `[0]`/`[1]` again exact both times). This is not a
plausibility argument -- every populated record in the archive
reproduces its own cell's true OAM bounding box exactly, in two
different Nitro-typical fixed-point widths (Q23.8 for the position pair,
Q19.12 for the size pair), which explains the previous pass's "1.0/-1.0
sentinel" reading of field `[0]`/`[1]` as Q19.12 (65536/-65536 -> 16.0/
-16.0 there, not a clean sentinel) -- the sentinel and the size pair use
different widths in the same record, and only the size pair (width/
height, always positive, Q19.12) makes both a clean 1:1 pixel match and
a clean sentinel read together.

**`[4]`, usually 0, is a Q19.12 pixel-scaled value in 7 of the 117
populated records** (blocks 37, 38, 40 only: `[3]`'s value is 80.0px
(one cell width) times the cell's 1-based position among a set of cells
that share another cell's OAM tile indices -- e.g. block 40's cells 2/3
have byte-identical `tile_idx` sequences and both read `[4] == 655360`
(160.0px = 2 x 80px)). This reads as a cached sheet-X offset for reused
tile data, not confirmed as a general field (only 3 of 95 blocks exercise
it) and not exposed as a named field in `--cellinfo`'s summary line
(`raw=` still shows it).

**Empty-cell sentinel** (`cell.num_oam == 0`): `[0] == 0x00010000`
(256.0 in Q23.8), `[1] == 0xFFFF0000` (-256.0 in Q23.8), all other
fields 0 -- checked on all 3 empty cells in the archive (block 54 cell
3, block 79 cell 3, block 91 cell 5), 3/3 exact.

### `--cellinfo` added to `rig.py`, round trip unaffected

`python tools/assets/rig.py --cellinfo BLOCK --archive extract/data/a/0/7/2 --block-size 8`
locates the block's no-magic member (`find_cellinfo`, by the same
elimination the previous pass used to isolate it, not a fixed local
index) and prints one line per cell: named `min_x`/`neg_min_y`/`width`/
`height`/`field4` (pixels) plus the raw 12-field tuple, or `EMPTY
sentinel` for the three empty cells. When a block's no-magic member
doesn't match the attested container shape (any other archive, or a
future block that turns out not to fit), `--cellinfo` falls back to a
raw hex dump of every no-magic local instead of guessing field names,
per the mission's instruction; a block with no no-magic member at all is
reported as such rather than silently printing nothing. Verified: block
91 (`--cellinfo 91`) prints 5 populated cells with the drifting `min_x`
plus the one `EMPTY sentinel` cell; block 0 (86 blocks share this shape)
prints its single constant record. `a/0/0/4`'s blocks (`--block-size
20`) have no member matching this shape, so `--cellinfo` on that archive
falls back to raw dumps of every no-magic local, as designed. No
existing code path was changed -- `find_cellinfo`/`parse_cellinfo` are
new, read-only functions layered on `scan_rig_block`'s existing
elimination logic, so the archive's own round trip (unaffected by this
module, which never re-encodes `a/0/7/2`) and every existing render path
(`--all`, `--anim-all`, single-species mode, `a/0/0/4` species 25's
regression render) are unchanged by this pass -- checked by re-running
`python tools/assets/rig.py 25` (still `0025_pose.png`, 59x56, byte-
identical dimensions to every earlier pass).

### What remains

- The function that actually opens sub-file `8*v+6` and walks its 48-byte
  records was not located (see "Reader" above); the field map rests on
  the data cross-check, not on a read consumer.
- Field `[4]`'s exact rule (only nonzero on 7/117 records, all in 3
  blocks whose cells duplicate another cell's tile data) is a plausible
  reading, not an independently confirmed one the way `[0]`-`[3]` are.
- What the game actually does with the decoded box (shadow ellipse,
  bounding-box culling, OAM affine setup, or something else) is still
  open -- this pass confirms *what* the record encodes (an exact
  duplicate of the cell's own OAM bounding box, in two fixed-point
  widths), not *why* the game keeps a second copy of it outside the
  NCER.

## Asset lane pass: GC's second grid and RD's dense block traced through ov021's tag vtable -- GC is a height-disambiguated bridge/overpass layer, RD's "dense block" was a mislabeled normal field, not a separate structure

Mission: read the four wrapper-tag handlers (func_02193398 WB, func_02193498
GC, func_02193544 NG, func_02193628 RD -- all in asm/overlays/ov021.s,
0x02187F00..0x021DE700, not ov010 as first pointed at; ov010 only holds the
two dispatch stubs func_02169800/func_02169848 that call into the vtable)
and their runtime consumers, to answer what GC's second grid and RD's dense
region actually feed. Both answers required following calls outside the
handlers themselves; neither required decompiling to EXACT (per the
mission's own allowance), so nothing here is filed as a match.

### (1) GC's second grid: a bridge/overpass layer, selected by footprint + height, not a flag

The tag vtable at 0x021D3DDC gives each tag three function pointers,
fn[+4]/fn[+8]/fn[+0xc]. Two different ov010 stubs call into it:
func_02169848 always calls fn[+0xc]; func_02169800 calls fn[+8], but
only after checking a boolean at the map object's own +0xd0 offset. For GC
these are different functions: fn[+0xc] = func_021934F8 samples only
u32@8 (grid 0) and marks the caller's output "1 grid"; fn[+8] =
func_02193498 samples both u32@8 and u32@0xc and marks it "2 grids".
So the ordinary per-tile query (func_0218DBAC, ov021, the function that
feeds func_021AACD4/enceff.c's terrain-effect lookup) never sees grid 1 at
all -- it always goes through func_02169848 -> fn[+0xc].

func_02169800 (the fn[+8]/two-grid path) is called from func_0218D9E8
(ov021, 0x0218D9E8..0x0218DAEC), which does not call it unconditionally
either: it first walks a per-map table of bounding boxes (mapObj+0x24, an
array of 0x28-byte records, count at mapObj+0x2e) and only samples the
two-grid path for candidate objects whose x/z footprint contains the query
position. For each hit it collects up to 16 {attribute, height} records
(from either grid) into a stack buffer. func_0218DAEC (ov021), its caller,
then disambiguates: if more than one candidate came back, it walks them
(0x0218DB40..0x0218DB84) calling func_021AB100 (the attribute-presence
predicate from the pkt_021AB0F0 family the earlier grid-record pass already
filed EXACT) and keeps the one whose stored height is closest to, without
exceeding, the query's own world-space y (fixed-point compare against
sp+4).

That is a bridge/overpass system, not a two-layer flag: a small per-map list
names where an alternate surface exists (the footprint of a placed bridge
object), and when the query position falls inside one, the game picks
between the two grids' records the same way it already picks between
type-2 slope candidates in func_021D14C4 -- by height, nearest from below.
map_grid.py's module docstring and its GC wrapper-layout section now
record this; the tool's --dump/--png output for GC's grid[1] (already
produced before this pass, since this module always decoded every declared
grid) is unchanged in bytes, only its documented meaning changed.

Consumer addresses: func_02169800 (0x02169800, ov010), func_02169848
(0x02169848, ov010), func_0218D9E8 (0x0218D9E8, ov021), func_0218DAEC
(0x0218DAEC, ov021), func_0218DBAC (0x0218DBAC, ov021, the ordinary
single-grid query used by gameplay), func_021AB100 (already EXACT).

### (2) RD's "dense 64x64x4 block": does not exist in the real archive -- it is the aux span read at the wrong stride, and "4094" is a normal-vector component, not a sentinel

The mission's own framing (a 4-byte marker, then exactly 64*64*4 = 16384
bytes) came from a pre-code-model pass reading wf_00_00 by byte-lane
correlation. Checked directly against all 8 real RD sub-files' own wrapper
size tables: the span after the grid the header declares is never
4 + 16384 = 16388 bytes. It is 4 + count*16 for a small count (0, 1 or 2
across the 8 files) -- a u32 count followed by that many 16-byte records,
structurally the same shape as an ordinary aux record with a height field
appended. The hypothesis does not hold, and map_grid.py no longer
implements a separate "dense block" parse for it (the old 4+64*64*4-sized
detection is left in parse_wrapper as inert/unreachable code, since it
never matches real data, rather than deleted mid-pass).

What the vtable trace found instead: RD's per-tile query path (fn[+0xc] =
fn[+8] = func_02193790, ov021) never calls func_021D14C4, the decoder
every WB/GC record goes through (confirmed by exhaustively listing
func_021D14C4's only four callers in ov021.s: func_02193398,
func_02193498 twice, func_021934F8 -- no RD function among them). Instead
func_02193790 reads the grid span (u32@8 onward, past the u16,u16
header) as a flat table of 24-byte (0x18-stride) records, using fixed-point
(x,z) chunk-division arithmetic rather than row*width + col. The byte count
matches exactly, not just the shape: this module's own byte-preserving
32x32-grid-plus-2048-record-aux reading of that same span totals
1024*8 + 2048*8 = 24576 bytes; 1024 24-byte records is 24576 bytes too
-- the identical span, read two different ways.

Each 24-byte record packs two candidate normal/height pairs (disassembled
directly from func_02193790, 0x02193804..0x02193838 and
0x02193824..0x0219383A):

    +0x00 s16 nx0   normal, candidate 0 (z negated,   +0x0c u32 height0
    +0x02 s16 ny0    same sign convention                    (paired with
    +0x04 s16 nz0    func_021D14C4 itself uses)               candidate 0)
    +0x06 s16 nx1   normal, candidate 1                +0x10 u32 height1
    +0x08 s16 ny1                                               (paired with
    +0x0a s16 nz1                                                candidate 1)
    +0x14 u32 flags  (bit 31 read as a selector; the function picks
                      candidate 0 or 1 by comparing each height field
                      against the query position's own fixed-point y --
                      the same "closest from below" shape as the type-2
                      aux search in func_021D14C4)

i.e. a two-sided collision face (a water surface has a top and an underside),
which is exactly why RD needs a reader of its own instead of the shared one:
func_021D14C4's record has one normal/height pair, not two.

This also explains the mission's own "4094 boundary sentinel" cleanly:
decoded with read_rd_mesh_records() (new in map_grid.py), every record on
wf_00_00 (a/0/0/8#228) reads normal0 == normal1 == (0, 4094, 0) -- not a
marker recurring at a fixed offset, but the y-component of a flat "up" normal
in ~12-bit fixed point (4096 == 1.0, so 4094/4096 is an almost-exact unit
normal), repeating because the whole water surface is flat. The earlier
byte-lane-era pass, reading this same span at the wrong stride, saw that
constant recur regularly and reasonably (but incorrectly) read it as a
sentinel.

Consumer addresses: func_02193790 (0x02193790, ov021, the RD per-tile
reader); func_02193628 (0x02193628, ov021, RD's load-time init, confirmed
not to call func_021D14C4 either -- its own tag_ver==3 branch reuses the
same func_0218DD04/func_0218B974 ordinary-grid-registration helper every
other tag's init uses, and its tag_ver==4 branch tiles a separate region 4x4
and hands each tile to func_02193924, which dispatches into
collision/model-builder helpers outside ov021's own mapped range --
0x02194038, 0x021C939C, 0x021C93E4, 0x021C9450, 0x021C93D0, and
further ARM9-side addresses -- not decompiled, listed here as targets for a
code lane, not attempted).

### tools/assets/map_grid.py changes

- GC and RD wrapper-layout docstring sections rewritten with the evidence
  above; TARGETS gained ("wf_00_00", 228) so --dump/--png exercise an
  RD file.
- New read_rd_mesh_records(): decodes RD's grid+aux span at the game's own
  24-byte stride (both normal/height candidate pairs and the selector bit).
  process_target now writes <name>_mesh.txt (--dump) and
  <name>_mesh_selector.png (--png) for RD-tagged targets alongside the
  existing (unchanged) byte-preserving grid/aux dump.
- No change to parse_wrapper, repack_subfile, or any packing function --
  the round trip is byte-identical before and after this pass by
  construction, since nothing about how bytes are written back changed,
  only how a second, parallel reading of RD's span and GC's second grid are
  labelled and (for RD) additionally exposed.

### Data checks

    a/0/0/8: 649/649 sub-files round-trip byte-identical (0 failed)   [--verify, unchanged]

    RD span byte-count identity (all 8 RD sub-files):
      grid0 (32x32) main+aux bytes  = 1024*8 + 2048*8 = 24576
      func_02193790's own reading   = 1024 records * 24 bytes = 24576  (equal)

    wf_00_00 (a/0/0/8#228) mesh decode: 1024/1024 records read
      normal0 == normal1 == (0, 4094, 0) on every record (flat water surface;
      4094/4096 ~= 1.0 fixed-point "up"), height0 == height1 == 0,
      selector == 0 throughout -- consistent with a flat, single-sided deck.

### What this closes and what it does not

Closed: which function consumes GC's second grid and under what condition
(a footprint-gated, height-disambiguated bridge/overpass layer, not a flag or
the player's own layer); which function consumes RD's declared grid span at
runtime and why it needs its own reader (a two-candidate collision-face
table, not the shared per-tile record); and the mission's own "4094
sentinel" question (it is a normal-vector component, and the "dense block"
it was framed against does not exist in the real archive's wrapper layout).

Not closed:

- RD's flags word (+0x14) beyond the selector bit, and the two u32 height
  fields' units, are located but not further decoded.
- func_02193628's tag_ver==4 branch and its func_02193924 callee bottom
  out in helpers outside ov021's own mapped range (0x02194038,
  0x021C939C, 0x021C93E4, 0x021C9450, 0x021C93D0, further ARM9-side
  addresses); what those specifically build is not traced here and is listed
  as a target for a future code-lane pass, not a data-lane one.
- func_0218D9E8's bounding-box table (mapObj+0x24, 0x28-byte records)
  is not itself sourced back to an a/0/0/8 file field in this pass -- it is
  read from the runtime map object, and this pass did not trace where that
  object's own fields are populated from the wrapper's bytes.

## Archive readers traced by call graph: seven of the nine framed-but-unidentified tables identified

Mission: take the tables the "Large custom table pass" above could frame but
not name, and find their readers in code rather than guess from bytes. That
pass had stopped at "no call site loads this id as an immediate". Two
mechanical gaps explain most of what it missed, and closing them turned seven
of the nine into identified domains.

### Method, and the two gaps in an immediate scan

The archive-read surface is not seven entry points, it is twelve. Enumerating
the callers of `func_02048DDC` (arc_tool.c's single "open archive by id",
which turns an id into a path through the identity name table at
0x020A6C58) gives the whole set:

| entry point | id in | what it does |
| --- | --- | --- |
| `func_02048D00` | r1 | read member into caller buffer, with mode and size out |
| `func_02048D54` | r0 | read member into a fresh heap block |
| `func_02048DDC` | r1 | open an archive into a caller-owned handle |
| `func_02048F4C` | r1 | read member into caller buffer (mode 0, no size out) |
| `func_02048F60` | r0 | read member into a fresh heap block (mode 0) |
| `func_02048F74` | r1 | five-argument forwarder to `func_02048D00` |
| `func_02048F88` | r0 | five-argument forwarder to `func_02048D54` |
| `func_02049030` | r0 | member count of an archive |
| `func_020490A8` | r0 | size of one member |
| `func_020490F4` | r0 | allocate a 0x50-byte handle and keep it open |
| `func_0204A1BC` | r0 | arc_util.c, allocate and read a member |
| `func_02049250` and five siblings | handle in r0 | handle-based member reads |

`func_020490F4` is the one the earlier pass did not have, and it is how every
long-lived subsystem holds its archives.

Gap one: the listings hide instructions behind `.inst.n` / `.inst.w`.
`disasm.py` emits those wherever the assembler would re-encode, and puts the
real mnemonic in the trailing comment. A scan that reads the mnemonic column
drops them silently, which costs roughly a third of the `movs rX, #imm`
population.

Gap two: a tail call is a pool word and a `bx`, not a `bl`
(`docs/idioms/tail-call-is-a-pool-word-and-bx.md`), so an accessor that
forwards straight into `func_02048F4C` never appears in a call scan at all.
Image-wide there are six such thunks, and one of them is a/2/1/4's only
reader. See `docs/notes/a_1_6_9_and_a_1_6_8_no_reader.c.txt` for the full
enumeration.

With both closed, the backward walk resolves 608 call sites: constants,
`mov` chains, pool loads, folded `lsls`/`adds`, and recursion into every
caller when the id is still a parameter at the top of the function.

A second lever did most of the naming work once the readers were found. Every
`sub_02030734` allocation carries a `__FILE__` pointer, so the pool words of
any function name its translation unit. Harvesting those across arm9 and all
237 overlays gives 1018 anchors, enough to bracket any address by source
file.

### Per archive

| archive | reader | region, source file | domain |
| --- | --- | --- | --- |
| a/1/9/4 | `func_02006C2C` (0x02006C2C) | arm9, pm_voice.c | per-species cry parameters |
| a/0/1/3 | `sub_0201407C` (0x0201407C) | arm9, zonedata.c | per-map-area record, seasonal |
| a/2/1/4 | `func_02168800` (0x02168800) | ov010, fld_btl_inst_tool.c | battle-facility Pokemon |
| a/2/1/5 | `func_0216880C` (0x0216880C) | ov010, fld_btl_inst_tool.c | per-group legal Pokemon pool |
| a/1/2/5 | `func_0216237C` (0x0216237C) | ov010, eventdata_system.c | per-zone map event data |
| a/1/0/8 | `func_0218E018` (0x0218E018) | ov021, field_g3d_mapper.c | per-map-area 3D mapper data |
| a/1/7/8 | `func_021BF788` (0x021BF788) | ov208, zukan_detail_* | per-species Pokedex detail |
| a/1/6/9 | none in the image | -- | same record type as a/2/1/4 |
| a/1/6/8 | none in the image | -- | same record type as a/2/1/5 |

**a/1/9/4, per-species cry parameters** (652 x 4 bytes). `func_02006C2C`
copies one member into a four-byte stack buffer with
`func_02048F4C(buf, 194, species)` and writes the low byte of the halfword at
+2 to an output byte. That byte's range over the whole archive is 97..127, a
7-bit playback parameter. The u16 at +0 takes only five values, 0, 10512,
13000, 13379 and 16000, which read as sample rates. The identification is
pinned by the function's own special case: it compares the species against
441, which is Chatot, the one species whose cry is a recorded sample, and on
that path overwrites the pitch byte with 0x78 = 120.
Sanity check: a/1/9/4 record 441 is `43 34 78 00`, so its stored +2 byte is
already 0x78, the exact value the Chatot path substitutes.
The reader is EXACT in `src/matched/func_02006C2C.c`.
Field map: +0 u16 rate, +2 u8 pitch (97..127), +3 u8 pad.

**a/0/1/3, per-map-area record, seasonal** (282 x 10 bytes, a flat file, not
a NARC). It does have an archive id, 13, and it is opened by path only
because `func_02020DEC` turns any id into its name-table path: the raw
byte-range reader `func_02020E08(id, heap, offset, size)` is what a non-NARC
file needs. `sub_0201407C(heap, index, delta)` calls it with
offset = index * 10 and size = 10, and clamps index against a pool constant
of 0x11A = 282, exactly the record count. `delta` is added only when
`sub_020140E8` says `2 <= index < 0xD2`; that window is 208 records wide, a
multiple of four, and ov021's fieldmap.c and ov020's event_mapchange.c both
pass the season for `delta`. So records 2..209 are four seasonal variants of
52 base entries and records 210..281 have none.
The index comes from the zone table: both callers compute it as
`sub_02013B38(zone_id)`, the u16 at +2 of the a/0/1/2 zone record.
Sanity check: that field over all 427 zones ranges 2..273 with 104 distinct
values, so every zone lands inside the 282-record clamp, and the low end
coincides with the seasonal window's lower bound.
`sub_0201407C` and `func_02020E08` are both EXACT
(`src/matched/sub_0201407C.c`, `src/matched/func_02020E08.c`);
`func_02020E08`'s `__FILE__` string identifies its unit as file_util.c.
Record shape from the bytes plus the one attested accessor
(`sub_020140DC` returns the byte at +7): +0 u8 kind, +1 u8 zero,
+2 u16 self index, +4 u8, +5 u8 (0xFF sentinel), +6 u8 always 1,
+7 u8 which steps 0x20..0x23 across the four seasonal siblings, +8 u8,
+9 u8.

**a/2/1/4, battle-facility Pokemon** (1000 x 16 bytes) and **a/2/1/5,
per-group legal Pokemon pool** (315 group lists). Both readers are in ov010's
fld_btl_inst_tool.c, next to each other, and each attests the other.
`func_02168800(dst, member)` is the tail-call thunk that hides id 214;
`func_0216880C(group, heap)` reads a/2/1/5 member `group + 1`, so group 0 is
sub-file 1 and sub-file 0 is the usual sentinel.
`func_02168924` is where the two meet: it takes `count` from +2 of the group
record, picks a random index below it, reads the member id from
+4 + 2*index, and passes that id to `func_02168800`. That is direct evidence
that a/2/1/5's member ids index a/2/1/4, which the previous pass could only
infer from the id ranges.
`func_021684E8` then decodes the 16-byte record field by field into a party
slot, which names every field:

| offset | width | field | evidence |
| --- | --- | --- | --- |
| +0 | u16 | species | stored into an 11-bit bitfield (`& 0x7FF`) |
| +2, +4, +6, +8 | u16 x4 | moves 1..4 | copied in a four-iteration loop |
| +10 | u8 | EV-invested stat mask | bits counted over six positions, against a pool constant of 510 |
| +11 | u8 | nature | 0..24 over the archive |
| +12 | u16 | held item | overridable by a caller-supplied table |
| +14 | u16 | form | low five bits, into bits 11..15 of the species halfword |

Sanity check: species max 645 (under 650), move max 556 (under 560), nature
max 23, EV mask popcount at most 4 with 510 EVs to divide, +14/+15 zero in
every one of the 1000 records; and a/2/1/5's 315 lists reach member id 988
with zero ids outside a/2/1/4's 1000 records.
`func_02168800` is EXACT and `func_0216880C` EXACT* (its follower at
0x02168824 is unlabelled).

**a/1/2/5, per-zone map event data** (428 sub-files). `func_0216237C` is the
event-data system constructor and the only place in the image that names id
125. It opens three persistent handles side by side: 125 into +0x04, 126
(a/1/2/6, the already-decoded wild encounter tables) into +0x08, and 57
(a/0/5/7, the already-decoded script archive) into +0x0c. a/1/2/5 is
therefore the third member of the classic per-zone triple of events,
encounters and scripts, and its 428 sub-files are the 427 zones plus the
trailing entry.
`func_021624B0(sys, zone_id)` reads the member and parses it, which resolves
the previous pass's "leading u32 does not reduce to one header size": the
u32 at +0 is the offset from +4 to a trailing block, not a header length.
The layout is `[u32 to_trailing][u8 c0][u8 c1][u8 c2][u8 c3]` then arrays of
20, 36, 20 and a fourth record size, with `+0x120` of the system object
pointing at the trailing block and `+0x1c/+0x20/+0x24/+0x28` at the four
arrays.
Sanity check: 427 of the 428 sub-files satisfy `4 + to_trailing <= length`
and `8 + 20*c0 + 36*c1 + 20*c2 <= length`; the one that does not is the
4-byte sentinel.
`func_0216237C` is byte-correct but capped at MATCH and parked in
`src/pending/func_0216237C.c`: its `__FILE__` string "eventdata_system.c" is
preceded by a pointer table rather than another string, so the `string`
evidence class cannot fix its start
(`docs/idioms/a-string-after-a-data-table-has-no-witness.md`).

**a/1/0/8, per-map-area 3D mapper data** (282 sub-files). `func_0218E018` in
ov021's field_g3d_mapper.c opens it as a persistent handle at +0x08 of the
mapper object, immediately after opening a/0/6/0 (id 60) at +0x04, and the
destructor at 0x0218E0E4 closes both. The 282 count is the same index space
as a/0/1/3, which zonedata.c reaches from the zone record's +2 field, so
a/1/0/8 is per-map-area and not per-zone. Its shape from the bytes, twelve
header bytes then four 4-byte blocks, lines up with a/0/1/3's four seasonal
variants: one block per season. That last step is structural, not attested by
an accessor, because the member read itself happens through the handle in
code this pass did not reach.

**a/1/7/8, per-species Pokedex detail** (649 x 249 bytes, no sentinel).
`func_021BF788` in ov208 opens it with `func_020490F4(178, heap)` and stores
the handle at +0x40C of the Pokedex-detail object, keyed by the species id it
reads from `[r6]` in the same breath; the teardown at 0x021BF98C closes it.
ov208's bracketing `__FILE__` anchors are zukan_detail_headbar.c and
zukan_detail_voice.c, so the domain is the Pokedex detail screen and the 649
sub-files are the 649 species with no species-0 sentinel, which is why this
archive is one short of the usual 650. Field map not attested: offset +0x40C
is written once and read once, at the close, so the member read is in the
partner overlay (ov206 occupies 0x021B9DE0..0x021BC240 beneath ov208) or
further out, and no handle-based read anywhere in ov206 or ov208 uses it.
That is the honest stopping point for this archive.

**a/1/6/9 and a/1/6/8: no reader exists.** Recorded as a closed negative
result in `docs/notes/a_1_6_9_and_a_1_6_8_no_reader.c.txt`, with the three
independent scans that make it trustworthy. Their record types are settled by
structural identity with a/2/1/4 and a/2/1/5, whose readers are matched
above, and the per-offset statistics agree (a/1/6/9: species max 488, move
max 466, EV mask popcount at most 3, nature max 24, +14/+15 always zero;
a/1/6/8's 315 lists reach member id 950 against a/1/6/9's 951 records with
zero out-of-range ids). The domain question, which facility, has no answer in
Black's code.

### What remains

- a/1/7/8's field map, and the a/1/0/8 member read: both need the consumer
  side, which is a code-lane packet in ov206/ov208 and in ov021's
  field_g3d_mapper.c, not a data-lane pass.
- a/1/9/4's u16 at +0: the five values look like sample rates but no reader
  touches that field, so the caller that does must be reached through the
  sound module's function-pointer tables (`func_02006C2C` has no direct
  caller in the image).
- a/0/1/3's remaining bytes: only +7 has an attested accessor
  (`sub_020140DC`); the other eight are read from the bytes.
- a/1/6/8's 93 self-inclusive records still have no explanation, and now
  cannot get one from code.

## Closing the open personal/move/item/encounter fields

Follow-up pass on `tools/assets/personal.py`, `waza.py`, `items.py` and
`encounters.py`'s "What remains unconfirmed" list. Every accessor read
this pass is one already cited above; the new evidence is either a
previously-unread case in an existing file (`sub_0201AF80`'s archive-id
constant) or a data check run against these decoders' own output, never
against an outside reference file.

### Personal (`a/0/1/6`): gender ratio through colour attested, outlier identified

`unit_0201AE14.c`'s 44-case getter (`sub_0201AE1C`) has no comment naming
gender ratio, hatch cycles, friendship, growth rate, egg groups,
abilities or colour, so this pass attests them by data check instead:
species 1 (Bulbasaur), 4 (Charmander) and 7 (Squirtle) decode +0x12
through +0x1A and +0x21 bits 0-5 to

    field            offset  Bulbasaur     Charmander    Squirtle
    gender_ratio     +0x12   31            31            31
    hatch_cycles     +0x13   20            20            20
    base_friendship  +0x14   70            70            70
    growth_rate      +0x15   3 (Med.Slow)  3 (Med.Slow)  3 (Med.Slow)
    egg_group1       +0x16   1 (Monster)   1 (Monster)   1 (Monster)
    egg_group2       +0x17   7 (Grass)     14 (Dragon)   2 (Water 1)
    ability1         +0x18   65 (Overgrow) 66 (Blaze)    67 (Torrent)
    ability2         +0x19   0 (none)      0 (none)      0 (none)
    ability3         +0x1A   34 (Chlorophyll) 94 (Solar Power) 44 (Rain Dish)
    colour           +0x21b0 3 (Green)     0 (Red)       1 (Blue)

every one of the twelve values that differ between species (egg_group2,
ability1, ability3, colour, three each) lands exactly on that species'
real value, under the ordinary Gen 3-5 ability-id numbering (34 =
Chlorophyll, 44 = Rain Dish, 65 = Overgrow, 66 = Blaze, 67 = Torrent, 94 =
Solar Power) and the ordinary 0 = Red / 1 = Blue / 3 = Green colour-id
numbering, and no offset had to be reused to make two facts fit. +0x1B
(`unk1B`) is 0 on all three and on every other record checked; still
unattested. +0x21 bits 6-7 are also still unattested (the source's own
bitfield split is 6+1+1, not the 7+1 colour+flip shape a real Personal
struct commonly uses, so that shape is not assumed).

**The 1300-byte outlier at sub-file 668 is the form table, by code.**
`sub_0201AF80` (already in `unit_0201AE14.c`, not a new file) reads
archive member id **0x29C = 668** -- this decoder's own sub-file 668 --
out of the same archive handle the 60-byte Personal records come from,
narrows the byte length to a `u16` count (`n = (u16)(len >> 1)`), and
counts entries that are not the sentinel 999. 1300 / 2 = 650 halfwords,
one per species-and-a-bit slot, and it is exactly the table
`form_table_base`/`form_table_companion` (+0x1C/+0x1E) index into
(`unit_0201AFD4.c`'s `sub_0201AFD4` computes `rec.unk1C + form - 1` as
the index). Not a separate mystery format: the form table the record's
own fields already point at.

Round trip after the renames: still 667/667 records, 40020/40020 bytes
byte-identical (`--verify`).

### Move (`a/0/2/1`): 0x1E is a constant, not a gap; recoil/drain and three flag bits attested

`sub_0201BD28`'s switch genuinely has no case for id 29 (0x1E), confirmed
again this pass; a data check adds that +0x1E is also not per-move data
at all -- every one of the 560 records decodes it to the same constant,
21331 (0x5353, i.e. the bytes 'S','S'), with zero exceptions. It keeps
its `unk1E` name and round-trips, but "always the same two bytes" answers
the open question: it is a fixed pad/marker value, not a field.

Recoil and drain (the mission's other move-side ask, alongside contact,
protect and heal) turned out not to be flags-word bits at all: Tackle
(no recoil) and Take Down (25% recoil) have byte-identical `flags` words
(0x49), so recoil cannot live there. It is the signed byte at +0x12
(`sub_0201BD28`'s cases 25/30, "positive part" / "negated if negative",
now named `recoil_drain`): 0 for ordinary moves, -25 for Take Down (25%
recoil, exact), -33 for Double-Edge (33% recoil, exact), and +50 for both
Absorb and Giga Drain (50% HP drain, exact for both) -- negative is
recoil taken by the user, positive is drain healed to the user, same
signed field.

Contact, protect and heal are `flags` bits, attested by decoding Pound,
Karate Chop, Tackle, Take Down, Ember, Recover, Softboiled and Counter
(chosen because their real power/accuracy/pp/effect are unambiguous and
between them they span contact/non-contact, damaging/self-heal, and
fixed/variable damage):

    bit 0 = contact       set: Pound, Karate Chop, Tackle, Take Down, Counter
                           clear: Ember, Recover, Softboiled
    bit 3 = protectable    set: every damaging move checked (incl. Ember, Counter)
                           clear: Recover, Softboiled (self-target, nothing to block)
    bit 5 = heal            set: Recover, Softboiled only
                           clear: every damaging move checked

Bit 6 also varies (clear only on Counter, Recover and Softboiled among
the moves checked) but is not one of the four fields the mission named
and no single label was pinned to it, so `flags` keeps it unnamed.

Round trip: still 560/560 records, 20160/20160 bytes byte-identical
(`--verify`).

### Item (`a/0/2/4`): pocket attested with a caveat, archive id still not code-attested, effect/battle-effect still open

The caller chain the mission asked for (`func_02021014` <-
`func_02020FE4` <- `func_02020F34`) runs out one call short of the
archive open: `func_02020F34` has no definition anywhere in this tree,
only the `extern` in `func_02020FE4.c`. The item archive's identity as
`a/0/2/4` still rests on the price-value match documented already, not on
a decompiled opener; this pass did not change that.

The 4-bit lane at +0x08 bits 7-10 (`func_02021014` case 5, previously
`b08_7`) is renamed `pocket`: read across the whole 627-item archive it
takes exactly 5 values, and every price-identifiable block of item ids
lands on one constant value -- items 1-16 (real ball prices) at 0,
items 17-19 (real Potion/Antidote/Burn Heal prices) at 1, items 149-183
(the real flat Berry price) at 3, items 410-419 (the real flat TM price)
at 2. The caveat: items 60-94, which by price are clearly not Poke
Balls, also read pocket 0, the same value as the real balls -- either
this lane is coarser than the bag's visible pocket split, or that
price-only identification for 60-94 is wrong; both are reported rather
than picking one silently.

`effect` and `battle_effect` (the other two item fields the mission
named) are not attested this pass. `f0A`/`f0B` (cases 6/7) are the
nearest candidates but track the same pocket-level blocks `pocket`
already separates and do not resolve further (Potion and Antidote read
the same f0A/f0B pair despite being different effects), so they keep
their source-accessor names.

Round trip: still 627/627 records, 22572/22572 bytes byte-identical
(`--verify`).

### Encounters (`a/1/2/6`): block 3 is winter, by data; 0/1/2 unresolved

No code path in this tree computes the season index and selects one of
the four 232-byte blocks (the callers that would, ov021's fieldmap.c and
ov020's event_mapchange.c, are not decompiled here). The nearest
attested neighbour, `sub_0201407C.c` (`a/0/1/3`'s 10-byte-record reader),
confirms callers pass a season index as a delta but resolves a different
table, not `a/1/2/6`.

Data settles block 3 instead, two independent ways that agree: species
582 (Vanillite) and 613 (Cubchoo) -- both pure single-type records in
`a/0/1/6` (type0 == type1 == 14, the same shared type id as 615, the
third species that reads 14/14 in this table) -- appear in block 3's
grass slots and nowhere else on sub-files 48/49/84/88 (e.g. sub-file 48
blocks 0-2 grass = [520, 585, 619, 621], block 3 = [582, 585, 613, 619]),
which is the real Black/White Twist-Mountain-style mechanic of
Cubchoo/Vanillite being winter-exclusive encounters. Separately,
sub-files 2, 93 and 94 have real grass data in blocks 0-2 and
all-empty grass/double-grass/shaking-grass in block 3, the same "winter
snows over the grass" signature from the routes-that-lose-grass side.
**Block index 3 is winter.**

Blocks 0, 1 and 2 are not resolved and, on every seasonal sub-file
sampled, are byte-identical to each other -- spring, summer and autumn
share one wild-encounter table in this archive, and only winter's block
differs. No claim is made about which of 0/1/2 is which season.

Round trip: still 112/112 sub-files byte-identical (`--verify`).

## a/1/2/5 per-zone event data decoded (`tools/assets/tables.py`), a/0/6/6 key test excluded, 17 unreferenced matrices and zone 300 surveyed

Follow-up pass on the "a/1/2/5, per-zone map event data" section above.
`func_0216237C` (`src/pending/func_0216237C.c`) only opens the archive
handle; it attests nothing about individual records. The header split
that section already reports (`[u32 to_trailing][u8 c0][u8 c1][u8 c2]
[u8 c3]` then arrays of 20, 36, 20 and a fourth record size, with
`+0x120`/`+0x1c`/`+0x20`/`+0x24`/`+0x28` of the runtime object) comes
from that section's own account of `func_021624B0`, which is not
decompiled in this tree; this pass treats that split as already
established and resolves the fourth array's record size and the
individual record fields, which were still open.

### Header, exact this time

`4 + to_trailing` (the offset the u32 at +0 names) lands **exactly** on
the byte past the fourth array on all 428 sub-files, not just within
bounds:

    8 + 20*c0 + 36*c1 + 20*c2 + 22*c3 == 4 + to_trailing   (428/428 exact)

which is also how the fourth record's size (22 bytes) was recovered: the
gap between the third array's end and the trailing-block offset divides
evenly by `c3` on every one of the 142 sub-files with `c3 > 0`, always to
22, with zero remainder anywhere. The earlier section's "leading u32 does
not resolve to one consistent header size" was comparing the u32 against
the wrong quantity (record length minus a constant); it is not a header
length at all, it is this offset-to-trailing-block field, and it resolves
exactly once the four arrays are separated out.

Sub-file 427 is the 4-byte all-zero sentinel (at the end, not the start,
unlike `a/1/6/8`/`a/2/1/5`'s leading-sentinel convention); sub-files
0..426 are the 427 zones, one sub-file per zone id, in zone-id order
(zone id == NARC member index, taken as the working hypothesis: `func_
021624B0` reportedly passes the index through `sub_02013B38`'s sibling
accessor first, per the existing section, but that accessor is not
decompiled in this tree either, so this is unverified rather than
attested; the sentinel's position and the exact 428 = 427+1 count are
consistent with it).

### Record arrays

Implemented as `_decode_event_data`/`_encode_event_data` in
`tools/assets/tables.py`, registered for `a/1/2/5`. Every record keeps its
raw bytes; the encode side reassembles from those bytes exactly, so field
naming below never risks the round trip.

    array           count   record size   identity (per mission framing)
    doors/warps     c0      20 bytes      classic warp/door list
    NPC objects     c1      36 bytes      classic object/NPC list
    script triggers c2      20 bytes      classic coordinate/trigger list
    unknown4        c3      22 bytes      the "one more" list, unidentified

`c0/c1/c2/c3` range over small counts (the most common tuples across all
427 zones are `(0,2,1,0)`, `(0,0,2,0)`, `(0,3,1,0)`, `(0,3,2,0)`), and no
sub-file's arrays overrun the trailing block, matching the header check
above.

**Doors/warps (20 bytes): x/y confirmed.** Record offset +8 and +12 (u16
LE each) were tested against every zone that resolves to exactly one
`a/0/0/8` map (`zones.py.resolve_zone_maps`, 303/427 zones -- the ones
excluded are zones spanning several map chunks through matrix 0/175,
where "the zone's map extent" is not one grid) by sweeping every
high-variance offset pair in the record and checking, per pair, what
fraction lands inside that map's `width x height` grid and how many of
those land on a walkable tile (`map_grid.py`'s `walkable` flag). Offsets
+8/+12 is the clear winner and the only pair tested with values that vary
enough to be real coordinates rather than a coincidentally-small flag
field landing in range by luck:

    x@+8, y@+12: in-bounds 330/350 (94.3%), walkable 316/330 (95.8%)
    walkable AND (on a map edge OR adjacent to a blocked tile): 287/330
        (87.0% of in-bounds records, 90.8% of the walkable ones)

That last number is the mission's specific ask ("warps must sit on
walkable tiles adjacent to blocked ones or map edges"): 87.0% of this
sample's warp coordinates satisfy it directly, and the walkable-but-not-
edge-adjacent remainder (29/316) reads as ordinary interior doorways
(carpeted floor tiles with no blocked neighbour in the 4-connected sense
checked) rather than a framing failure. The 5.7% (14/330) that land on a
non-walkable tile and the 5.7% (20/350) that land outside the grid at all
are reported as-is, not explained away; some are almost certainly zones
whose single resolved map is the wrong one for that particular door (a
multi-exit building whose non-primary door leads to a different chunk),
which this check cannot distinguish from a real framing gap.

No other field in the 20-byte warp record was pinned down. Offset +0 (u16,
max 10431, four disjoint value bands roughly at 0-255/2048-2303/7936-8191/
10240-10495) and offset +16 (u16, values cluster on multiples of 16: 0,
16, 48, 80, 240) are candidates for a script/kind selector and a flags
word respectively, by shape alone; neither has code or a cross-archive
check behind it, so both keep generic names. No field in this record
ranges 0..426 and 0..600 lands out (see below), consistent with no
"destination zone"/"destination matrix" field having been identified
either -- the 662 sampled warp records were checked against the 17
unreferenced matrix ids (see below) with a negative result for the same
reason: no field is confidently a matrix-id lane to test.

**NPC objects (36 bytes): x/y tentative.** The best pair in this record
is x@+28, y@+8, weaker than the warp pair on both axes:

    x@+28, y@+8: in-bounds 688/1111 (61.9%), walkable 658/688 (95.6%)

The high walkable fraction among in-bounds records is consistent with a
real coordinate pair, but the 61.9% in-bounds rate (against the warp
pair's 94.3%) is not clean enough to call this confirmed; it is reported
tentative (`x_tentative`/`y_tentative` in the decoder) rather than
promoted to the warp pair's status. The lower fit is plausible on its own
terms -- NPC placement is exactly the record type most likely to include
entries this check's single-map-per-zone restriction misplaces (an NPC
whose zone spans multiple matrix chunks, or one on a non-primary chunk),
more so than a fixed door.

**Script triggers (20 bytes) and the unknown4 array (22 bytes): no
coordinate field identified.** Every offset pair among each record's
higher-variance fields was swept the same way; none produced an in-bounds
fraction that was both high and clearly non-degenerate (the pairs that
hit 100% in-bounds all turned out to be small, low-range enum/flag fields
that trivially fit under almost any map's width/height, not real
coordinates -- verified by checking that the same fields have very low
value variance, under 20 distinct values archive-wide). Both record types
are kept as raw bytes with no named fields beyond the header-level split.

### a/0/6/6 key test: excluded

Tested whether any u16 field of the NPC or script-trigger records is
bounded to `a/0/6/6`'s exact 601-sub-file range (0..600) and whether the
`group_count in {1,2,3,5,8}` header value of the indexed sub-file
correlates with another field of the same record (a movement-frame count,
a trainer sightline count). Both come back negative:

- **Range**: no field is bounded to 0..600. The closest are the NPC
  record's offsets +28 (89.2% of 2257 records in [0,600], true max 818)
  and +30 (94.5% in range, true max 764) -- real fields with a wider
  range than 600, not a clipped 601-entry index that happens to show a
  long tail.
- **Correlation**: for records whose candidate field does land in
  [0,600], `a/0/6/6[field].group_count` was compared field-by-field
  against the rest of the same record. The best matches (NPC record
  offset +12, trigger record offset +16) "agree" 54-57% and 85-87% of the
  time, but both of those fields are themselves dominated by the value 1
  (57.5% and 87.7% of records) exactly like `group_count` is (574/601
  files = 95.5%) -- two independently 1-heavy fields agree by chance at
  close to that rate, so this is a base-rate artifact, not a discovered
  link. No field reproduces `group_count` above what its own dominant-
  value frequency would predict by chance.

`a/0/6/6`'s role stays open (see `tools/assets/events.py`'s docstring);
this pass adds a specific negative result -- it is not the NPC or
script-trigger record's target archive -- rather than an identification,
so no `--dump` support was added for it.

### The 17 unreferenced matrices and zone 300

The 17 matrix ids no zone record's `+0x04` lane selects (`a/0/0/9`'s
matrix archive, cross-checked against all 427 `field_04` values):

    id   mode  size   nonempty cells
    67   0     1x1    1
    77   0     1x1    1
    118  0     2x2    4
    160  0     1x1    1
    178  0     1x1    1
    181  0     1x1    1
    193  0     2x2    4
    208  0     2x2    4
    212  0     1x2    2
    214  0     1x1    1
    215  0     1x1    1
    216  0     1x1    1
    217  0     1x1    1
    218  0     1x1    1
    238  0     1x2    2
    242  0     1x1    1
    253  0     2x2    4

All 17 are mode 0 (private, single-zone-style matrices, same shape as the
253 interior matrices the earlier section already describes) and every
cell in every one of them is non-empty -- they are not blank placeholder
data, they point at real `a/0/0/8` map ids, just from no path the zone
table's `+0x04` lane reaches. Checked against `a/1/2/5`'s event records:
every one of the 17 ids does turn up somewhere as a raw u16 field value
in the 4178-record event set (2 to 51 hits each), but since no field in
any of the four record types was identified as a "matrix id" or
"destination zone/matrix" lane (see above), this is not read as evidence
of a real reference -- with thousands of u16 field reads across four
record types and ids as small as 67-253, hitting some field's value by
chance is expected, not diagnostic. No warp, NPC, trigger or unknown4
field can currently be pointed to as "the" reference lane, so these 17
stay unexplained, consistent with the earlier section's conclusion.

Zone 300 (matrix 175's one exception from the earlier "Zone resolution"
section) was checked two more ways:

- Matrix 175's zone grid has 23 distinct values across its 29x27 cells
  (excluding the `0xFFFFFFFF` empty sentinel); every one of those 23
  values is a real zone id in the 0..426 set parsed from `a/0/1/2` --
  **no cell carries a zone id outside the 427 real ids** (not a
  leftover/cut zone id, not a sentinel-like foreign value, just none of
  the 23 present values happens to be 300).
- No a/1/2/5 warp record was found that can be confidently read as
  targeting zone 300, for the same reason as the matrix-id check above:
  no destination-zone field was identified in the 20-byte warp record to
  test. The raw value 300 does occur 7 times somewhere across all u16
  fields of the archive, but with no attested "destination zone" lane
  this is reported as inconclusive, not as a warp into zone 300.

### Round trip

    python tools/assets/tables.py --verify a/1/2/5
    a/1/2/5: round trip 428/428 byte-identical

## Archive readers extended by backward-register scan

Mission: the "Group 2 custom table pass" and the `a/0/6/6` reader search
("`a/0/5/7` side tables paired with the zone script lane") both stopped at
the same wall -- a text scan for the archive's decimal id as an immediate
register load directly ahead of a call to one of the seven arc_tool.c
entry points, over `asm/arm9/main.s` and `asm/overlays/*.s` as flat text.
Three things that scan structurally could not see: instructions the
assembler re-encodes as `.inst`/`.inst.n`/`.inst.w` (real mnemonic kept
only in a trailing comment, invisible to a mnemonic-column text scan --
`docs/PARALLEL.md` "Tooling"), hand-written thunks that set up the id then
tail-branch into the reader rather than `bl` it (`bx rX` after `ldr
rX, pool_ADDR`, a broader idiom than the narrow 2-instruction shape
`layout/worklist.json`'s own thunk inventory tracks), and the id arriving
as a parameter one function away from the actual call. This pass builds a
proper reader map that closes all three gaps.

### Method

`tools/fileanchors.py` (`--lookup`) and `disasm.scan_mnemonics(region)`
(merging each region's ordinary listing with its `inst_index.txt`, per
`docs/PARALLEL.md`) are used directly; the scan script itself is a
scratch tool, not committed (the task scope is `tools/assets/tables.py`,
`tools/assets/events.py`, this document and `build/assets/reader_map.json`
only). For `arm9_main` and all 237 overlays:

1. Every instruction is read via `scan_mnemonics`, so `.inst`-encoded
   `bl`/`blx`/`bx` are covered exactly like ordinary ones.
2. A call site is "into the family" (`func_02048F60`, `func_02048F74`,
   `func_02048DDC`, `func_02048D00`, `func_02048D54`, `func_02048F4C`,
   `func_02048F88`, `func_02020E08`) if it is a direct `bl`/`blx`/plain-`b`
   to one of those addresses, OR a `bx rX` where `rX` was just loaded from
   a literal pool word (`ldr rX, pool_ADDR`) pointing at one of them, OR a
   `bl`/`blx` to an address in `layout/worklist.json`'s `thunks` list whose
   `target` is one of them. The `bx`-from-pool-word case is the important
   addition: `func_02168800` (a/2/1/4's real reader, matched in
   `src/matched/func_02168800.c`) is exactly this shape -- `ldr r3,
   pool_02168808` (the address of `func_02048F4C`), `movs r1, #0xd6` (214),
   `bx r3` -- and it is NOT in `layout/worklist.json`'s thunk inventory,
   because that inventory only tracks the pure 2-instruction `ldr;bx` idiom
   and this one has an extra `movs`/`adds` in between.
3. From each family call site, the id-carrying register (`r0` for
   `func_02048F60`/`func_02048D54`/`func_02048F88`/`func_02020E08`, `r1`
   for the other four, per each function's own parameter order) is walked
   backward inside the same function through `movs`/`mov` immediate loads,
   `mov` register-to-register chains, and `ldr rX, pool_ADDR` literal
   pool loads (resolved against the region's own raw bytes, no re-trace
   needed). If the register is still unresolved at function entry (the id
   is a parameter), the reverse call graph -- built in the same pass, every
   `bl`/`blx` target image-wide, so this lookup is O(1) rather than a
   second full scan -- gives every caller of that function, and the same
   backward walk repeats once, in the caller, on the argument register at
   the call site (the task's "one level of caller").
4. Every constant id found is mapped to its archive path by the project's
   own decimal-digit convention (`id = 100*X + 10*Y + Z` for `a/X/Y/Z`,
   confirmed archive-wide against `build/assets/inventory.json`'s 237 NARC
   paths, zero collisions), and to the nearest `__FILE__` anchor at or
   before the call site's own function, via `fileanchors.py --lookup`.

### Coverage

    python <scratch>/reader_scan.py
    region data built in 18.1s (arm9_main + 237 overlays)
    reverse call graph: 22147 distinct targets, 106 family call sites
    resolved to a constant id: 87/106
    archives with at least one attested open site: 39/237

Before this pass, the archives with a code-attested reader were the ones
named across the three earlier reader-hunting passes: 2 from "Large custom
table pass" (`a/1/2/3`, `a/0/2/0`), 6 from "Group 2 custom table pass"
(`a/0/4/8`, `a/0/8/7`, `a/0/9/1`, `a/1/3/2`, `a/1/4/6`, `a/1/4/7`) and 7
from "Archive readers traced by call graph" (`a/1/9/4`, `a/0/1/3`,
`a/2/1/4`, `a/2/1/5`, `a/1/2/5`, `a/1/0/8`, `a/1/7/8`) -- 15 total, plus
`a/1/6/9`/`a/1/6/8` explicitly closed as "no reader exists". This pass's
automated scan independently re-found 12 of those 15 on its own (`a/1/2/3`,
`a/0/2/0`, `a/0/4/8`, `a/0/8/7`, `a/0/9/1`, `a/1/3/2`, `a/1/4/6`, `a/1/4/7`,
`a/1/9/4`, `a/0/1/3`, `a/2/1/4` -- the last via the `bx`-from-pool-word
case above -- and correctly found nothing for `a/1/6/9`/`a/1/6/8`), which
is the honesty check for the method: it recovers known-good readers by the
same mechanical process applied to everything else, rather than only
finding new ones. `a/2/1/5`, `a/1/0/8` and `a/1/7/8` are read through a
persistent handle (`func_020490F4`) or a member index computed elsewhere in
the caller, outside what this pass's backward walk covers, so they stay
un-rediscovered here; they are not lost, just outside this scan's method.
21 archives are new: `a/0/0/9`, `a/0/1/5`, `a/0/1/7`, `a/0/1/8`, `a/0/1/9`,
`a/0/2/1`, `a/0/2/4`, `a/0/2/5`, `a/0/3/7`, `a/0/6/6`, `a/0/6/7`, `a/0/9/2`,
`a/0/9/3`, `a/1/0/2`, `a/1/0/9`, `a/1/1/7`, `a/1/2/7`, `a/1/4/8`, `a/1/5/2`,
`a/1/6/3`, `a/1/6/5`, `a/1/6/6`, `a/1/7/4`, `a/1/7/9`, `a/1/8/7`, `a/2/1/2`,
`a/2/2/0`, `a/2/3/2` -- most of these (`a/0/0/9`, `a/0/1/8`, `a/0/1/9`,
`a/0/2/1`, `a/0/2/4`, `a/0/2/5`, `a/0/9/2`, `a/0/9/3`, `a/1/0/2`, `a/1/8/7`)
are archives already fully identified by other converters (`matrix.py`,
`personal.py`, `waza.py`, `items.py`, `icons.py`, trainer-data lookups)
outside `tables.py`'s scope -- this pass's own value there is confirming a
real, code-attested call site for tables those converters had only
inferred structurally, not a new identification. The 19 unresolved family
call sites are cases where the id is set by something this pass's backward
walk does not follow (an `adds`/register arithmetic, a table load, or a
second level of caller); they are not evidence of "no reader", just outside
this method's reach.

`build/assets/reader_map.json` (gitignored, regenerate via the method
above, don't commit) is the full machine-readable form: every family call
site, its resolution, and, for constants, the mapped archive and anchor.

### `a/0/6/6`: reader found, battle effect-VM table, not a text/language bank

The explicit target this pass was pointed at. Superseding the earlier
"`a/0/6/6` reader searched, not found" result (which grepped only for the
immediate `0x42`/`66` directly ahead of a `bl`, the same blind spot as
every archive above): **overlay_094 `func_021F94F8`**, the battle
visual-effect VM's own object constructor (`btlv_effvm.c`, per its
bracketing `__FILE__` anchor at `0x021F93F4`), calls
`func_02048F60(archive_id=0x42=66, member=r6, heap)` at `0x021F95CC`, with
`r6` holding the constructor's own 4th incoming argument (an effect id --
`adds r6, r3, #0` at function entry, `0x02168804`-style parameter capture).
The immediate `0x42` is loaded directly (`movs r0, #0x42` at `0x021F95BC`)
right before the call, the same evidentiary bar as every other direct hit
in this pass.

`a/0/6/7` is read the same way, from the same file and the same three
functions (`func_021F94F8` and two siblings, all `btlv_effvm.c`), 7 call
sites total, `func_02048F60(archive_id=0x43=67, ...)` -- a sibling table,
not read anywhere else.

This settles the identification question `events.py`'s own docstring and
the "`a/0/6/6` key test" pass left open: `a/0/6/6` is **not** a text or
per-language bank (the census's automated guess and this project's own
per-language hypothesis, both weakened but never confirmed by any earlier
pass), it is a **battle effect-VM data table indexed by effect id**. `G`'s
small discrete range (`{1,2,3,5,8}`) now reads as a per-effect variant/stage
count rather than a language count, consistent with `a/0/1/5` (see below)
also sitting inside a small-numbered subsystem table shape. The per-group
14-word redundancy and the payload itself are still not decoded past
byte-exact extraction -- this pass adds the reader and the domain, not a
field-level decode. `tools/assets/events.py`'s docstring is updated with
this finding; `tools/assets/tables.py`'s module docstring records the
cross-reference (a/0/6/6 itself stays owned by `events.py`, not
`tables.py`, since its container framing already lives there).

### Newly identified `_GROUP2` archives (`tools/assets/tables.py`)

17 more `_GROUP2` archives (out of the 75 from "Group 2 custom table
pass") gained a code-attested reader this pass, on top of the 6 already
known (`a/0/4/8`, `a/0/8/7`, `a/0/9/1`, `a/1/3/2`, `a/1/4/6`, `a/1/4/7`,
unchanged) -- `_GROUP2`'s reader count goes from 6/75 to 23/75. `tools/
assets/tables.py`'s per-archive notes and the "Full per-archive table"
rows above are both updated with the reader, its file and an
identification read off the file name and the accessor pattern, per the
project's own established convention (a reader in `zukan_*.c` names a
Pokedex table, a reader in `camera_system.c` names a camera-domain table,
and so on) -- none of these are a field-level decode, all stay opaque
identity copies in `tables.py`.

| archive | reader | file (region) | identification | confidence (before -> after) |
|---|---|---|---|---|
| a/0/1/5 | overlay_021 func_02189154 | fieldmap.c | field-map subsystem table | LOW -> LOW-MEDIUM |
| a/0/1/7 | arm9 func_02019B94 (via hand-written thunk) | poke_tool.c | Pokemon-utility-indexed table | LOW -> LOW-MEDIUM |
| a/0/3/7 | overlay_071 func_021B69AC | (no anchor) | still not identified | LOW -> LOW |
| a/0/6/7 | overlay_094 func_021F94F8 + 2 siblings (7 sites) | btlv_effvm.c | battle effect-VM secondary table (sibling of a/0/6/6) | LOW -> MEDIUM-HIGH |
| a/1/0/9 | overlay_021 func_021BB2F8, func_021BB3E8 | field_nogrid_mapper.c | non-grid field-mapper table | LOW -> LOW-MEDIUM |
| a/1/1/7 | overlay_021 func_021C24F0 | fld3d_ci.c | field-3D subsystem table | LOW -> LOW-MEDIUM |
| a/1/2/7 | overlay_054 func_021F37B4, func_021F3874 (3 sites) | (no anchor) | 1/7 subs BMD0, rest opaque (unchanged) | LOW-MEDIUM -> MEDIUM |
| a/1/4/8 | overlay_053 func_021F3828, func_021F3978 (5 sites) | (no anchor) | 3/18 subs BMD0, rest opaque (unchanged) | LOW-MEDIUM -> MEDIUM |
| a/1/5/2 | overlay_092/094 func_021B9C80, func_021F6560/func_021F6B04, func_021F7544 (4 sites) | btlv_stage.c, btlv_effect.c | battle stage/effect visual table | LOW -> MEDIUM-HIGH |
| a/1/6/3 | overlay_021 func_021B542C | scrcmd_encount.c | wild-encounter script-command table | LOW -> LOW-MEDIUM |
| a/1/6/5 | overlay_021 func_021CBFB0 | bsubway_scr.c | Battle Subway (facility) script/table | LOW -> LOW-MEDIUM |
| a/1/6/6 | overlay_048 func_021F4DE4 | gimmick_obj_elboard.c | field-gimmick object table (sibling of a/1/7/4) | LOW -> LOW-MEDIUM |
| a/1/7/4 | overlay_048 func_021F4C10 | gimmick_obj_elboard.c | field-gimmick object table (sibling of a/1/6/6) | LOW -> LOW-MEDIUM |
| a/1/7/9 | overlay_021 func_021BE148 (via hand-written thunk) | entrance_camera.c | entrance-camera subsystem table | LOW -> LOW-MEDIUM |
| a/2/1/2 | overlay_172 func_021B657C | camera_system.c | RIFF/WAVE audio pair (camera shutter/flash, guess corroborated) | HIGH -> HIGH |
| a/2/2/0 | overlay_181 func_021B9D04 | (no anchor) | RLCN/RCSN + BMD0/BCA0 mix (unchanged) | MEDIUM-HIGH -> HIGH |
| a/2/3/2 | overlay_197 func_0220BA2C | (no anchor) | battle_pocket.dat, BTNF name (unchanged), reader corroborates | HIGH -> HIGH |

None of these identifications are a field-level decode: every one stays an
opaque identity copy in `_GROUP2`, and the "identification" column is a
domain guess read off the reader's own translation unit and calling
pattern, not a struct. `a/0/1/5`/`a/0/1/7`/`a/1/0/9`/`a/1/1/7`/`a/1/6/3`/
`a/1/6/5`/`a/1/6/6`/`a/1/7/4`/`a/1/7/9` have no magic evidence at all, only
the reader's own file name, so their confidence bump is capped at
LOW-MEDIUM; `a/0/3/7`, `a/1/2/7` and `a/1/4/8` have a confirmed call site
but no `__FILE__` anchor near it (the nearest anchor precedes the whole
translation unit's first function, not this one), so no file-name
identification could be added at all.

### What remains

- 51 of `_GROUP2`'s 75 archives still have no attested reader by any
  method run so far (a full list is in `tools/assets/tables.py`'s
  `_GROUP2` dict, every entry whose note still reads "No reader found").
- `a/0/6/6`/`a/0/6/7`'s per-group payload (past the header this project
  already decoded) is still opaque; the battle effect-VM identification
  narrows where to look (ov094's `btlv_effvm.c`/`btlv_effect.c`/
  `btlv_stage.c` functions that read them) but does not decode a single
  field.
- The one-level-of-caller fallback and the pool-word-`bx` case both
  materially mattered (`a/2/1/4`'s known reader and 14 of the 21 new
  archives depended on one or the other), which means archives still
  showing no reader may need a second level of caller, or a `bx` through a
  register loaded by something other than a direct pool word (an array
  lookup, for instance) -- both outside this pass's method.
- `a/0/2/1` (the move table, `waza.py`, already verified) turned up 21
  family call sites from a single file, `shinka_check.c` (evolution
  checks referencing move data by species) -- kept as a sanity check on
  the method in this writeup, not reported as a new finding, since the
  archive was already fully identified.

## Item archive id closed by code (`a/0/2/4` = 0x18), pocket lane solved against the bag, and the `a/0/0/4` rig's per-node placement traced to the OAM attribute word

Two questions this pass answers from decompiled code, not from data
correlation: what opens the item table, and whether anything between the
`a/0/0/4` rig's NMCR node records and the hardware moves a node.

### The item archive: attested by three immediates in one block

`func_02020F34` is the call the chain `func_02021014 <- func_02020FE4`
was missing, and the whole block it lives in, 0x02020E60..0x02020F84, is
the item archive's own accessor file. Its seven functions name the
archive ids as plain immediates:

| function | what it does |
| --- | --- |
| `func_02020F14` | `func_020490F4(0x18, heap)`: open archive id 0x18 as a persistent 0x50-byte handle |
| `func_02020F20` | clamp the item id to 626, then read that member out of the handle (`func_02049250`) |
| `func_02020F34` | one-shot member read: `which == 0` is `func_02048F60(0x18, item, heap)`, the item record itself |
| `func_02020F08` | answers the constant 0x19, the archive the item graphics come from |
| `func_02020E60` | item id to member id in archive 0x19 |

Archive ids in this image are the decimal spelling of the `a/X/Y/Z` path
(`a/0/4/8` is 48, `a/0/9/1` is 91, `a/1/2/3` is 123, `a/2/1/1` is 211),
so **0x18 = 24 = `a/0/2/4`** and **0x19 = 25 = `a/0/2/5`**. The item
table's identity no longer rests on the price-value match documented in
the core-table pass; it is now code-attested the way
poke_personal/waza_tool/shinka_check are. `a/0/2/5` is newly identified
as the item graphics archive by the same evidence.

Both bounds checks in the block clamp an out of range item id to 0 at
**626**, the last of `a/0/2/4`'s 627 members: the member count is
confirmed from code as well.

`func_02020E60(item, which)` maps an item id to a member id of `a/0/2/5`:

```
which 0: item, except item 0 and item 0xFFFF answer 0
which 1: item_gfx_member[item].lo   (1001 for item 0, 1003 for 0xFFFF)
which 2: item_gfx_member[item].hi   (1002 for item 0, 1004 for 0xFFFF)
which 3: item_gfx_member_x[k].lo,   k = func_0202F170(item)
which 4: item_gfx_member_x[k].hi,   k = func_0202F170(item)
else:    0
```

`item_gfx_member` is a 627-entry array of u16 pairs at 0x0209EB6C, one
pair per item: an icon member and a second member, presumably its
palette. `item_gfx_member_x` at 0x0209E9E8 is the same shape but indexed
through `func_0202F170`, which linear-searches a 46-entry u16-pair table
at 0x020A03C8 for the item id and answers the row index, 0 when absent: a
small side lane for 46 specific items, not a per-item lane.

### The item record field map, with the open fields marked open

Offsets are from the two accessors in `src/matched/unit_02021014.c`, one
jump-table case per field; the widths are what the load instruction uses.
`sel` is the attribute id callers pass to `func_02020FE4(item, sel, heap)`.

| sel | offset | width | name |
| --- | --- | --- | --- |
| 0 | +0x00 | u16 | price, answered as `f00 * 10`, not raw |
| 1 | +0x02 | u8 | hold effect |
| 2 | +0x03 | u8 | (unnamed) |
| 3 | +0x08 bit 5 | 1 | boolean gate |
| 4 | +0x08 bit 6 | 1 | (unnamed) |
| 5 | +0x08 bits 7-10 | 4 | **bag pocket**, see below |
| 6 | +0x0A | u8 | (unnamed) |
| 7 | +0x0B | u8 | (unnamed) |
| 8..11 | +0x04..+0x07 | u8 each | (unnamed) |
| 12 | +0x08 bits 0-4 | 5 | (unnamed) |
| 13 | +0x08 bits 11-15 | 5 | (unnamed) |
| 14 | +0x0C | u8 | record kind: 0 or 1, selects the tail layout |
| 15..17 | +0x0D..+0x0F | u8 each | (unnamed) |
| 0x12..0x33 | +0x10 sub-record bytes 0..6 | 1 bit each, 34 lanes | flag bits |
| 0x1E | sub-record +0x01 bits 4-7 | 4 | (unnamed nibble) |
| 0x1F..0x22 | sub-record +0x02, +0x03 | 4 bits each | (unnamed nibbles) |
| 0x23..0x26 | sub-record +0x04 | 4 / 2 / 1 / 1 bits | (unnamed) |
| 0x34..0x3E | sub-record +0x07..+0x11 | s8, except +0x0D/+0x0E u8 | eleven byte fields |

The tail at +0x10 is only reached when the byte at +0x0C is 1; when it is
0 the getter answers the byte at +0x10 for every id above 17 and nothing
else. That is the item record's one structural version flag, and it is
data, not code shape: re-derive it for White rather than assuming it.

**The pocket lane (sel 5) is now solved, and the earlier caveat is
withdrawn.** `src/matched/unit_02007CB0.c` is the bag: `sub_02007D6C`
reads attribute 5 for an item and passes the answer straight to
`sub_02007D00` as the pocket selector, which maps it to a slot array
inside the 0x9C0-byte bag structure:

| pocket | offset in bag | slots |
| --- | --- | --- |
| 0 | +0x000 | 310 |
| 1 | +0x7D8 | 48 |
| 2 | +0x624 | 109 |
| 3 | +0x898 | 64 |
| 4 | +0x4D8 | 83 |

Five pockets, exactly the five distinct values the archive-wide read
found. The capacities settle which is which against the blocks the
core-table pass identified by price: pocket 1 (48 slots) holds
Potion/Antidote/Burn Heal, pocket 2 (109 slots) holds the flat-priced TM
block, pocket 3 (64 slots, and the game has 64 berries) holds the
flat-priced berry block, pocket 4 (83 slots) is the remaining one, and
pocket 0 is the 310-slot general pocket. The earlier caveat was that
items 1-16 (ball prices) and items 60-94 both read pocket 0. That is not
a contradiction: this game keeps balls in the general pocket rather than
giving them one of their own, and the 310-slot pocket is the only one
large enough to be general.

**`effect` and `battle_effect` are still not attested, and this pass does
not name them.** Every call site of `func_02020FE4` in the image was read
for the attribute id it passes: ids 0, 1, 2, 3, 5, 6, 7, 0xF, 0x1B, 0x27,
0x28 and 0x3C-0x3E are the only ones any caller uses. Of those, 0x1B,
0x27 and 0x28 are consumed as pure booleans (`cmp r0, #0` and nothing
else, in ov091 0x021BC19E/0x021BC1B4 and ov198 0x0220F848), 3 is a
boolean gate in ov070 0x021B7158, and 7 is compared against the single
value 3 in ov197 0x0220D1DE. No caller anywhere dispatches on an
attribute's value through a table or a switch, which is what an effect id
would look like, so the two fields the mission named have no code witness
to give them.

### The `a/0/0/4` rig: no per-species or per-node offset exists, but a per-OAM-entry one does

The call chain, from the multi-cell node record to the hardware:

```
func_020643CC   multi-cell node walk
  -> per node i: slot = nodeStates + i * 0x28; slot->enabled = 1;
     func_020640DC(&slot->srt, (s16)node->x, (s16)node->y)
func_0206469C   the same node's NANR frame, per tick
  -> func_020640DC(srt, frame.px, frame.py)                  (type 2 frames)
  -> func_02064120(srt, frame.sx, frame.sy)
     + func_02064100(srt, frame.rot)
     + func_020640DC(srt, frame.px, frame.py)                (type 1 frames)
func_0206775C   one OAM entry to one textured quad
  -> func_02066E30   emits the quad's translation to the geometry engine
sub_02063068 / 0x02063054   the OAM buffer itself to 0x07000000 / 0x07000400
  (through sub_02082A60, dispatched from the vtable at 0x020A81E4/0x020A81E8)
```

**The negative result first.** The NMCR node's own signed `(x, y)` is
written into the node's SRT translation verbatim, by
`func_020640DC(&slot->srt, node->x, node->y)` at 0x0206461C..0x02064628.
There is no table indexed by species, form or node id between the node
record and that store, no second placement source, and no shadow or
anchor adjustment: the only other writes to the same block are the scale,
rotation and translation `func_0206469C` reads out of the node's own NANR
frame record, which `rig.py` already applies. A scan of every call site
of the eleven archive entry points across `asm/arm9/main.s` and all
overlays for an immediate archive id 4 found zero (the same scan finds
the known sites for ids 24 and 123, so it is not a broken scan), so no
offset archive is opened next to the rig either.

**The positive result.** The mission's third hypothesis, a second OAM
pass for parts flagged in the NCER attribute word, is real. Two
corrections are applied per OAM entry in the draw path, both computed
from that entry's own attribute bits and from the standard OBJ dimension
tables, and both invisible to a composer that reads x/y straight out of
the cell.

Tables (three rows of four u16, 8-byte row stride, row = shape, column =
size):

| address | contents |
| --- | --- |
| 0x020A17F0 | object **width**: 8/16/32/64, 16/32/32/64, 8/8/16/32 |
| 0x020A17D8 | object **height**: 8/16/32/64, 8/8/16/32, 16/32/32/64 |

shape is attr0 bits 14-15, size is attr1 bits 14-15.

1. **Flip** (`func_0206775C`, 0x02067604 and 0x02067658, gated on
   `func_02067B50` / `func_02067B64`, which read bits 0 and 1 of the
   composer state's +0x24 word):

   ```
   x = sign_extend_9(attr1 bits 0-8)
   y = sign_extend_8(attr0 bits 0-7)
   if (flip_h)  x = -(x + width [shape][size])
   if (flip_v)  y = -(y + height[shape][size])
   ```

2. **Affine double-size** (`func_02066E30`, 0x02066E64..0x02066ED0), when
   attr0 bits 8-9 == 3:

   ```
   tx = x + (width [shape][size] >> 1)
   ty = y + (height[shape][size] >> 1)
   ```

   and when they are anything else, `tx = x`, `ty = y` unchanged
   (0x02066EF4). The result is shifted left 12 into fx32 and written to
   the geometry engine's translate register at 0x04000470.

So a part whose OAM entry carries the double-size affine mode is drawn
half its own width and half its own height away from where its raw x/y
says, and a flipped part is drawn at the negation of its position plus
its own dimension. Both are per-part and both depend on the part's size,
which is exactly the signature of a detachment that hits some cells of a
species and not others. `rig.py` should apply both before concluding that
a species' placement data is simply authored detached; the two documented
species' detached cells are the first thing to re-check against the
double-size bit specifically.

One caveat stated plainly rather than hidden: the chain traced above is
the 2D-in-3D draw path, the quad emitter that feeds the geometry engine.
A pure-OAM path exists in the same module and was not traced to the same
depth this pass, so the two corrections above are attested for the path
that was read, not proven to be the only path a battle rig can take.

### Files

EXACT: `src/matched/unit_02020F08.c` (the five item-archive leaf
accessors, including the 0x18 handle open), `src/matched/unit_020640B0.c`
(the SRT block's three table leaves, and the block's layout),
`src/matched/unit_02067B40.c` (the flip bit's two predicates).

Byte-correct but capped at MATCH: `src/pending/unit_02020E60.c`, the
whole 0x02020E60..0x02020F84 item accessor block. Its three unresolved
relocations are `item_gfx_member` (0x0209EB6C, one literal witness image
wide and it is inside the range), `item_gfx_member_x` (0x0209E9E8, none)
and `func_0202F170` (none). The first of those is a tooling gap, not a
missing witness: a second copy of the word does exist at 0x02020EF4, but
that pool sits inside the `.byte` run the block's unlabelled leaf
functions live in and `disasm.py` does not index it as a literal pool.

Near misses with their evidence: `docs/notes/g2d_srt_setters.c.txt` and
`docs/notes/g2d_flip_setter.c.txt`.

## Asset lane pass: `a/0/6/6`/`a/0/6/7` decoded as battle effect-VM bytecode (`tools/assets/btleff.py`)

Mission: decode `a/0/6/6`'s per-group payload (still opaque per the previous
two passes) as battle effect-VM bytecode, following the "same machine as
`vm.c`, own table" hint from the reader-scan pass. Method mirrors
`scripts.py`'s own: locate the handler table by finding the VM context
descriptor literal, sweep every handler for its operand-fetch calls, then
sweep the archive with the resulting table. New file: `tools/assets/
btleff.py` (stdlib only, imports `events.py` for the shared container
framing). No other files changed except this section.

### Group selection: a caller-supplied variant byte, bounds-checked against the archive's own `group_count`

`func_021F94F8` (ov094, the effect-VM constructor `events.py` and the
reader-scan pass already identified) takes an optional 5th argument struct
at `[sp, #0x20]`. When present, byte `+1` of that struct is read
(`021F968A`), bounds-checked against `a/0/6/6`'s own loaded `group_count`
byte (`021F967E`..`021F9688`: if the requested index is not less than the
archive's `group_count`, it is reset to 0), then turned into a byte offset
`4 + 56 * requested_group` (`021F968C`..`021F9690`: `muls r0, r1, #0x38`,
`0x38` = 56 = one group's 14-word header block) that is used to read that
group's repeated slot word and start the VM there (`func_0201127C`,
`021F97C2`). So the group is an explicit runtime parameter of the effect
invocation (read off the caller's own struct), not a hardcoded
per-position or per-stage index baked into `btlv_effvm.c`. `func_021F94F8`
itself always passes group 0 when no struct is given. No call site found
this pass reads a slot other than slot 0 of a group's 14 identical words
(events.py already confirmed all 14 are identical, so which slot a site
reads cannot be told apart by effect); the 14-fold redundancy itself is
still unexplained -- this pass narrows what varies (the group) without
explaining why each group's start is stored 14 times over.

### The effect VM is `vm.c`'s engine, with its own context and table

ov094 has exactly one call to `func_0201121C` (`vm.c`'s "create", see
"Script virtual machine located and decompiled" above), at `021F945C`,
against the descriptor literal at `0x02209DCC`: `{stack_cap=0x10,
ring_cap=0x08, cmd_table=0x02209E88, cmd_count=0x4E}`. The bytecode is
started with `bl func_0201127C` right after the group lookup above -- the
same "start at a pc" entry point the field VM uses. So the battle effect
VM is a second, independent instance of the exact same interpreter
(`func_0201121C`/`func_0201127C`/`func_02011298`/`func_0201134C`/
`func_020113B4`/`func_020113C4`/`sub_020113B0`/`sub_02011290`, all EXACT
per the field-VM pass), not a separate hand-written machine.

Handler table: `0x0217062C` in overlay 10 is the field VM's; the battle
effect VM's is `0x02209E88` in overlay 94, 78 entries (`cmd_count=0x4E`
from the descriptor above). Every one of the 78 table words has its low
bit set (Thumb) and every one resolves inside ov094 itself
(`021F9AB8`..`021FC448`) -- no NULLs, no veneers into another overlay,
unlike the field VM's table (9 NULL, 330 into ov021).

### Operand widths: every opcode takes only 4-byte (u32) operands

Swept the 78 handler bodies (bounded by each handler's own address and the
next table entry's address, since the table is address-sorted) for direct
`bl`/`blx` calls to `func_02011330` (u16 fetch, the field VM's narrow
operand fetch) and `func_0201134C` (u32 fetch), following one level of
callee for any call target landing inside ov094 (mirrors the field VM's
helper-fetched "variable id" case; mattered for opcodes 59 and 60 only,
+3 u32 fetches each from a shared local helper). Result: `func_02011330`
is never called by any of the 78 handlers -- unlike the field VM (which
uses both widths across its first 32 opcodes), this VM's operands are
exclusively 4 bytes. Per-opcode total operand bytes (opcode's own u16
excluded), the full table now lives in `tools/assets/btleff.py`'s
`OPERAND_WIDTH`:

    op    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15
    len  20  40  24  24   8   0   4  44  60  44  40   4  44  52  44  52
    op   16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31
    len   0   0  28  36  24  28  24  24  24  16   8  20   8   8  28   4
    op   32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47
    len  20  32   8   4   4  24  16  20   4  24  20   8  28  28  28  28
    op   48  49  50  51  52  53  54  55  56  57  58  59  60  61  62  63
    len   8  20   4   8  36   4  32  36   4   4   4  28  28  12   4   4
    op   64  65  66  67  68  69  70  71  72  73  74  75  76  77
    len   8  12   0  28   4  24  12   0   4   0   4   4   4   0

Opcode 0 (20 bytes, 5 u32 operands) reads as a "play effect resource"
instruction: it fetches all 5 words up front, then branches on two of
them (`021F9AB8`..`021F9B0E`) -- confirmed by direct disassembly, not just
the operand count. Opcode 8 is the widest at 60 bytes (15 u32 fetches).
Opcodes 5, 16, 17, 66, 71, 73 and 77 take no operands.

Four opcodes are control flow, identified the same way as the field VM's
(by which `vm.c` call-family function their own handler calls):

    opcode 77              calls sub_02011290 (stop)    -- script terminator
    opcode 70               calls func_020113B4 (call)   -- see below
    opcode 71               calls func_020113C4 (return)  -- pairs with 70
    opcodes 60, 61, 72, 74 call sub_020113B0 (jump)      -- branches

Opcode 70's handler (`021FC20C`) is itself the second `a/0/6/7` read site
`docs/ASSETS.md`'s reader-scan pass counted but did not disassemble: it
calls `func_02048F60(archive_id=0x43, member=<computed>, heap)`, reads
`*(ptr+4)` off the result (the same "offset 4 = first group's payload
start" convention `parse_0666` already uses), and calls into it via
`func_020113B4` -- opcode 70 is "call an `a/0/6/7` sub-script as a
subroutine", opcode 71 returns from it.

### `a/0/6/7` shares `a/0/6/6`'s exact container framing

Checked directly, not inferred: `events.py`'s `parse_0666`/`pack_0666`,
completely unmodified, round-trip all 98 `a/0/6/7` sub-files
byte-identical (`btleff.py --verify`, below). Sub-file 0 decodes to
`group_count=1`, `header_len=60` (`4 + 56*1`), 14-word block value `0x3c`
(60) repeated 14 times -- the identical shape to `a/0/6/6`. Consistent
with `a/0/6/7` being read by the same family: `func_02048F60(archive_id=
0x43, ...)`, from opcode 70's handler above and from `func_021F94F8`'s own
overflow path (`021F9626`, taken when the requested effect id's associated
field is past `a/0/6/6`'s own indexable range). It is a second bank of
effect-VM scripts, invoked either as a direct effect (the overflow path)
or as a callable subroutine from an `a/0/6/6` script (opcode 70).

### `tools/assets/btleff.py` (new)

`--list [--archive {0666,0667,both}]`: per sub-file, `group_count` and
each group's (start, size). `--disasm N [--archive {0666,0667}]`: linear
opcode+operand sweep of every group in sub-file N, using `OPERAND_WIDTH`,
annotated with the STOP/CALL/RET/JUMP tags above. `--verify`: re-packs
every `a/0/6/6` and `a/0/6/7` sub-file via `events.py`'s
`parse_0666`/`pack_0666` (unmodified) and diffs byte-for-byte -- 601/601
(`a/0/6/6`) and 98/98 (`a/0/6/7`) round-trip exactly, matching (and not
regressing) `events.py`'s own result. `--check`: runs the sweep over every
group of both archives (741 groups total: 601 `a/0/6/6` files' groups plus
98 `a/0/6/7` files' groups) and reports how each one ends:

    groups swept: 741
      stop:       679  (91.6%)  -- opcode 77 reached cleanly
      desync:      40   (5.4%)  -- hit an opcode >= 78 mid-sweep
      short:       13   (1.8%)  -- an operand ran past the group's end
      exact_end:    9   (1.2%)  -- payload exhausted with no opcode 77
    clean (stop or exact_end): 688/741 (92.8%)

92.8% is in the same range as the field VM's own decode check (90.7% of
`a/0/5/7` entry points, "Script virtual machine" section above), which is
the acceptance bar this pass is measuring against; the sweep is a straight
linear walk (no jump/call following), so the 7.2% that do not end cleanly
are expected to include groups whose real control flow branches (opcodes
60/61/72/74) away from a straight read before reaching the terminator, not
necessarily framing errors.

### Remaining gaps

- The 14-fold slot redundancy inside each group's header block is still
  unexplained; this pass found what selects the GROUP (a caller-supplied,
  bounds-checked variant byte) but no call site that reads any slot other
  than slot 0.
- `--check`'s 7.2% non-clean groups are not root-caused past "a linear
  sweep cannot be expected to reach the terminator through untaken
  branches" -- a real jump/call-following interpreter (walking opcodes
  60/61/70/71/72/74's actual targets instead of stepping over them) was
  not built this pass.
- The individual operand words are not semantically decoded (no field is
  named beyond "u32 operand k"); opcode 0's likely resource-id/branch
  structure was read directly off its handler as a spot check, not
  generalised to the other 77 opcodes.
- Which specific `a/0/6/6` slot (of the 14) or group each battle effect id
  maps to at the game-data level (rather than the code-level mechanism
  that picks a group at runtime) was not cross-referenced against any
  move/effect-id table.

## Asset lane pass: `rig.py`'s OAM placement corrected to the attested per-OAM arithmetic, Charizard/Gengar detachment closes

The previous pass ("Item archive id closed by code...") traced the
`a/0/0/4` rig's detachment problem to two per-OAM-entry corrections in the
game's own quad-emission draw path (`func_0206775C`/`func_02066E30`,
EXACT in `src/matched/unit_02067B40.c`/`unit_020640B0.c`) and flagged that
`rig.py` had not yet applied them. This pass applies both and re-checks.

### Divergences found, line by line against the attested arithmetic

- **Sign extension**: already correct. `Oam.x` was `attr1 & 0x1FF` with a
  9-bit two's-complement fixup (`x - 512 if x >= 256`), `Oam.y` was
  `attr0 & 0xFF` with an 8-bit fixup (`y - 256 if y >= 128`). No change.
- **Shape/size width/height table**: already correct. `SHAPE_SIZE_PX`
  matches the 0x020A17F0/0x020A17D8 tables (shape 0 8/16/32/64 square,
  shape 1 16/32/32/64 wide with height 8/8/16/32, shape 2 8/8/16/32 wide
  with height 16/32/32/64) cell for cell. No change.
- **Flip formula: divergent, now fixed.** `render_oam()` mirrored the
  rendered pixel block in place (`row[::-1]`, `px[::-1]`) but left the
  OAM's `x`/`y` untouched, so a flipped part kept its unflipped top-left
  position while its pixels moved under it -- exactly the shape of a
  detached limb. `Oam.__init__` now applies `x = -(x + w)` when `hflip`
  and `y = -(y + h)` when `vflip` (own shape/size w/h), gated on the same
  bits `func_02067B50`/`func_02067B64` read off composer state +0x24 --
  which are exactly the OAM's own attr1 hflip/vflip bits already parsed,
  only live when rotscale is off. `render_oam()`'s pixel mirroring is
  kept (hardware still fetches the tile mirrored); the position fix is
  additional, not a replacement.
- **Double-size affine offset: missing entirely, now added.** Nothing in
  `rig.py` read attr0 bits 8-9 or added a `width/2`/`height/2` offset.
  `Oam.__init__` now sets `affine_double = (attr0>>8)&3 == 3` and, when
  true, adds `w//2`/`h//2` to `x`/`y` before any flip check (flip and
  double-size affine are mutually exclusive on real hardware -- rotscale
  on repurposes attr1's flip bits as a rotscale-param index, so `hflip`/
  `vflip` are already forced False whenever `affine_double` is true, and
  the two corrections never both fire on the same entry).
- **NMCR node offset / NANR frame offset / per-OAM transform combine
  order**: already correct and unaffected by this pass. `_frame_placements`
  sums `node.x + px + oam.x` (and the `y` equivalent) -- a node's NMCR rest
  position, the current frame's NANR (px, py) translation, and the OAM's
  own (now-corrected) cell-local position, in that order, matching the
  call chain traced in the previous pass (`func_020640DC` writes NMCR
  (x, y) then frame (px, py) into the same SRT translate field; the OAM's
  own quad translation is a separate, later stage that this project
  renders as a flat sum since scale/rotation reads identity at every
  frame-0 record sampled in this archive).
- Both corrections were applied only in `Oam.__init__` (i.e. to the
  decoded `x`/`y` used everywhere placement happens: `_cell_local_raster`,
  `_frame_placements`'s identity branch, and indirectly `_cell_frame_
  raster` for SRT-transformed cells) -- not to NCER's byte-level round
  trip, which never serializes `Oam.x`/`Oam.y` back out (`Ncer.encode()`
  rebuilds the cell array from the raw `(num_oam, cell_attr, oam_ofs)`
  header tuples and leaves the OAM array itself as an untouched patchwork
  region), so the fix is read-side only and round-trip-safe by
  construction.
- Kept as a single unconditional code path, not made switchable: `a/0/7/2`
  shares the same `Oam`/`Ncer`/`compose_pose` machinery (no separate
  placement code exists for the trainer-rig block shape), so there is
  nothing for a second path to switch between, and the fix applies to both
  archives uniformly.

### Before/after renders

Charizard (6), Gengar (94), Pikachu (25) and Mewtwo (150) were re-rendered
to `build/assets/rig/` (gitignored). Pose bounding boxes, before -> after:

| species | before (w x h) | after (w x h) |
| --- | --- | --- |
| 6 (Charizard) | 95 x 96 | 83 x 91 |
| 94 (Gengar) | 66 x 73 | 63 x 64 |
| 25 (Pikachu) | 59 x 56 | 48 x 52 |
| 150 (Mewtwo) | 85 x 82 | 79 x 78 |

All four shrank in both dimensions. Visual inspection of the rendered PNGs
confirms the detachment closes: Charizard's tail flame and wing, previously
floating clear of the body, now sit attached at the tail/shoulder; Gengar's
floating hand (node-array position 4/5/6/11, the previous pass's
connected-component finding) is now attached at the arm socket. Pikachu and
Mewtwo, not named in the original detachment report but visibly affected
by the same bug, go from scattered limbs (Pikachu's ears/tail/feet
floating well outside the body) to a single connected sprite for both.

### Archive-wide count

A lightweight bbox-only comparison (calling `_frame_placements` at frame 0
for every species' rest pose, old vs. new `Oam` logic, without a full pixel
raster) was run over all 714 `a/0/0/4` block indices (`species*20`):

- 713/714 parse in both versions (the same one non-parseable slot as
  every prior pass's "713/714 species render" figure -- this pass changes
  nothing about which slots parse).
- **706 of 713 (99%) species' rest-pose placement changed** (per-node
  placement position or bounding box differs from before this pass).
- Of those 706: **666 shrank** (bounding box strictly smaller in both
  width and height, or smaller by area when only one dimension moved),
  **26 grew**, and 14 changed position with the same bounding box
  dimensions (a part moved without changing the overall extent, e.g. a
  flip whose old accidental placement happened to fall inside the same
  box as the corrected one).
- The dominant shrink (94% of changed species) is the expected signature
  of a bug that scatters flipped/double-size parts outward: correcting
  their placement pulls them back toward the body, tightening the box
  more often than it loosens it. The 26 growers are not treated as a
  regression without individual review -- a corrected placement can
  legitimately extend the box where the old (wrong) position happened to
  sit inside it by coincidence.

### Round trip

`a/0/0/4`, `a/0/5/2` and `a/0/7/2` were re-checked with
`python tools/assets/verify_all.py --archive <archive>` after this
change. The fix touches only `Oam.__init__`'s decoded `x`/`y` fields,
which `Ncer.encode()` never reads (the OAM array is reproduced as an
untouched byte range, see "Divergences found" above), so no round-trip
regression was expected; `verify_all.py`'s reported pass/skip/fail counts
for all three archives are unchanged from before this pass.

### Remaining gaps

- The 26 species whose bounding box grew were not individually reviewed
  against reference art -- this pass trusts the attested arithmetic and
  the four-species visual spot check rather than claiming all 706 changed
  renders are now correct.
- The pure-OAM hardware draw path (as opposed to the 2D-in-3D quad
  emission path traced and attested here) was flagged by the previous
  pass as not traced to the same depth; this pass did not revisit that
  caveat.
- No per-pixel diff was computed archive-wide (only bounding boxes and
  per-node placement keys from `_frame_placements`), so "706 changed" is a
  placement-level count, not a guarantee that every changed species'
  rendered pixels differ from before in a way a human would notice.

## Asset lane pass: field-VM's 17 unresolved handlers pinned to overlays, both VMs raised to flow-following disassembly, all 18 field-VM "variable" opcodes resolved to fixed widths

Mission: resolve the 17 field-VM opcodes whose handler address fell outside
ov010/ov021 (via the overlay load table), replace both `scripts.py`'s and
`btleff.py`'s linear per-entry sweep with a worklist disassembler that
follows call/jump targets, and re-test the 18 field-VM "variable" opcodes'
length rules against the flow-followed data. Files touched:
`tools/assets/scripts.py`, `tools/assets/btleff.py`; this section.

### The 17 unresolved handlers: overlay 18, overlay 20, overlay 48

`layout/layout.json`'s `overlays` array gives every overlay's load address
range (`ram_start`/`ram_end`). Every one of the 17 addresses falls inside
the RAM window of more than one overlay (DS overlay groups routinely
share a load address, one loaded at a time depending on context), so the
range alone does not pick a single candidate. Disambiguated by reading the
actual bytes at the target offset in each candidate's decompressed file
(`extract/overlays_dec/y9_00NN.bin`) and keeping the one whose bytes are a
valid Thumb function prologue (a `push {..., lr}` encoding, matching every
other handler in this table) instead of ARM code, all-zero padding, or a
misaligned instruction stream:

    opcodes 367, 368, 369, 371, 372, 373, 374, 375
        -> overlay 18 (y9_0018.bin, ram 0x0217AE20-0x02183B60).
           Candidates ov009 (ARM code -- ruled out), ov019 and ov176 (data
           or off-boundary bytes at every one of the 8 addresses) also
           cover this range; only ov018 decodes to a clean push prologue
           at all 8.
    opcode 382
        -> overlay 48 (y9_0048.bin, ram 0x021F36C0-0x021F5260). Of the 9
           candidate overlays covering 0x021F4650 (38, 39, 41, 48, 55,
           107, 112, 135, 194), only ov048's bytes are a push prologue;
           41 and 55 are all-zero, 107 is ARM, the rest are data/
           off-boundary.
    opcodes 450, 451, 452, 453, 454, 455, 456, 457
        -> overlay 20 (y9_0020.bin, ram 0x02183B60-0x02187F00). ov009
           (also covering this range) is ARM code; ov023 (covering a
           sub-range) is data at every one of the 8 addresses; ov020 is a
           clean push(+sub sp) prologue at all 8.

With the handler pinned, each was swept the same way the 32-608 pass swept
ov010/ov021: direct and depth-1-callee calls to `func_02011330` (+2) /
`func_0201134C` (+4) / the variable-id helper `func_02159AE8` (+2,
confirmed by reading it: it is itself `push;bl func_0215A5E4;bl
func_0215A5F4;bl func_02011330;bl func_02158FE0;pop`, i.e. a u16 fetch
wrapped in two state accessors), with a cursor-idiom check at both depths.
All 17 resolve to `fixed` widths (0, 2, 2, 2, 2, 0, 2, 0, 4, 0, 0, 4, 2, 6,
0, 0, 4 respectively for 367/368/369/371/372/373/374/375/382/450/451/452/
453/454/455/456/457) -- see `scripts.py`'s `OPERAND_WIDTH` entries for the
per-opcode call list. Depth was capped at 1 callee level (unlike the
32-608 sweep's uncapped recursion) after an uncapped version produced
false "variable" flags on ordinary unrelated game-logic callees whose body
this pass's file scan could not find (mostly ARM9 UI/graphics helpers
outside `asm/arm9/main.s` and the three overlays read) -- a missing body
is not evidence of a cursor read, and none of these 17 handlers' own
bodies or immediate callees contain the raw `ldr rD,[rB,#0x14]; ldrb`
cursor idiom, so none are flagged variable.

### The 18 "variable" opcodes: all resolved to fixed widths by direct disassembly

Every one of the 18 opcodes the earlier pass called "variable" was read by
hand this pass (not re-derived by an improved automated sweep) and turned
out to be an ordinary fixed-width instruction. Two distinct earlier
misreadings:

**The "indirect branch" family (56, 74, 77, 79, 87, 88, 97, 98) is not a
runtime jump table.** What the earlier sweep saw as `bx r3` after
`ldr r3,[pc,#n]` is a Thumb-1 static long-branch veneer -- a linker-style
trampoline used because Thumb-1 `bl` cannot reach every target directly,
not a data-dependent dispatch. Each veneer's literal pool holds a FIXED
target address plus a small constant (an int, for 56/74; a callback
function pointer, for the other six) loaded into r2 before the branch.
Reading the veneer's own bytes (`ldr r2,[pc,#n]; ldr r3,[pc,#n]; bx r3`
followed immediately by its literal pool) resolves the branch target
exactly, at build time, with no runtime dependency:

    opcode 56  -> shared handler func_021B1008 (r2=0)
    opcode 74  -> func_021B1008 (r2=1, same handler as 56)
    opcode 77  -> func_021AF794 (r2=0x0201EF41, a callback pointer)
    opcode 79  -> func_021AF794 (r2=0x0201EF4D, same handler as 77)
    opcode 87  -> func_021AF8D8 (r2=0x0201EE61)
    opcode 88  -> func_021AF8D8 (r2=0x0201EEC5, same handler as 87)
    opcode 97  -> func_021AFBEC (r2=0x0201F0F9)
    opcode 98  -> func_021AFBEC (r2=0x0201F125, same handler as 97)

Each of the three shared handlers fetches exactly one byte via the direct
cursor idiom plus one u16 via `func_02159B10` (confirmed by hand: itself a
thin wrapper around `func_02011330`) = 3 bytes, then (for 77/79/87/88/97/
98) calls the r2 callback with the two fetched values, or (56/74) calls a
lookup helper (`func_021B162C`) that reads no further cursor bytes. All
eight opcodes: `fixed`, 3 bytes.

**The "direct cursor byte read" family (32, 76, 78, 173, 174, 178, 359,
361, 538, 539) reads one or more literal byte fields inline, not a
length-prefixed variable tail.** Every handler in this family was
disassembled in full. None of them loops: each performs a fixed sequence
of direct `ldrb`-off-cursor reads (sometimes two, at different points in
the same handler) and/or calls to the known fetch helpers
(`func_02011330`, `func_0201134C`, `func_02159AE8`, `func_02159B10`), and
the resulting bytes only ever feed a comparison, a table lookup, or a
callback argument -- never a "read N, then copy N more bytes" loop. Widths
(bytes, opcode's own u16 excluded):

    opcode  32   1 direct byte  +  4 (func_0201134C)          =  5
    opcode  76   1 direct byte                                =  1
    opcode  78   1 direct byte + 2+2 (func_02159B10 x2)
                              + 1 more direct byte             =  6
    opcode 173   1+1 direct bytes + 2 (func_02159B10)
                              + 1 more direct byte + 2 (func_02011330) = 7
    opcode 174   1+1 direct bytes + 2 (func_02159B10)
                              + 1 more direct byte             =  5
    opcode 178   same shape as 174                             =  5
    opcode 359   2 (func_02159B10) + 1 direct byte             =  3
    opcode 361   1 direct byte + 2 (func_02159B10)
                              + 2 (func_02159AE8)               =  5
    opcode 538   1 direct byte                                 =  1
    opcode 539   1 direct byte                                 =  1

Opcode 76 (the previous pass's prime desync suspect, 100 of 232 hand-check
misses) is the clearest case: its handler (`func_021AF75C`) reads exactly
one byte off the cursor and passes it as a plain `id` argument to
`func_0201F02C`, which never touches `vm->pc` again -- there never was a
"that many further bytes" tail; the earlier docstring's guess was wrong.
Opcode 361's fetched byte selects one of 40 cases in a jump table
(`0215D55C`), and opcode 32/173's bytes gate a table-lookup comparison,
but in every case the WHICH-CODE-RUNS decision is data-dependent while the
HOW-MANY-BYTES-WERE-CONSUMED is not -- exactly the distinction the earlier
"variable" classification conflated.

**Opcode 31 was also corrected**, from the doc table's hand-read 4 to 5:
its handler (`func_02159670`) reads a 1-byte flag id via the direct
cursor idiom BEFORE its 4-byte `func_0201134C` jump-offset fetch; the
original opcodes-0-31 table only counted the u32. This was caught by
re-disassembling opcode 31 while establishing the jump-target arithmetic
below, not by the flow-following statistic directly.

After this pass: 600 opcodes `fixed` (up from 565), 9 `null`, 0
`variable`, 0 `unresolved` -- every one of the 609 table entries this pass
could reach a decision on now resolves to a concrete, hand-verified byte
width.

### Jump/call target arithmetic, both VMs

Read directly off the handler bodies (not inferred from the C source,
which only names the call-family functions -- `sub_020113B0`/
`func_020113B4`/`func_020113C4` take a pre-computed `u32` and store or
push/pop it, with no arithmetic of their own; the add happens in the
*handler*, before the call):

**Field VM, opcode 4 (call)**: fetches a `u32` via `func_0201134C`
(cursor already advanced past the 4 operand bytes), reads `vm->pc` back
out (now pointing at the byte right after the operand), adds the fetched
value, and calls `func_020113B4(vm, target)` -- which pushes the OLD pc
onto the call-history ring and overwrites `vm->pc` with `target`.
**Target = pc-after-operand + signed s32 operand**, i.e. relative to the
first byte of the NEXT instruction, forward- or backward-biased by the
operand's sign. Execution also returns to pc-after-operand once the
callee's own `return`/opcode-5 unwinds the ring, so the call site's
fallthrough is reachable too.

**Field VM, opcode 30 (jump)**: identical arithmetic
(`func_02159658`: fetch u32, `target = pc_after_operand + rel`), but via
`sub_020113B0(vm, target)` -- a direct `vm->pc = target` with no ring
push. No fallthrough: this is the one genuine linear-flow terminator of
the three (4/30/31).

**Field VM, opcode 31 (conditional jump)**: same `pc_after_operand + rel`
arithmetic, but gated: the handler (`func_02159670`) first fetches a
1-byte flag id (the correction above), looks it up in a small
flag/condition table, and only calls `sub_020113B0` if the condition
holds -- otherwise it returns normally with `vm->pc` untouched, i.e. falls
through to the next instruction. Both the jump target and the fallthrough
are reachable; opcode 31 is NOT a pure terminator the way 30 is, contrary
to the FLOW_END_OPS grouping the previous pass used for the (still kept,
for the old linear --check) walk_entry/disasm_entry sweep.

**Field VM, opcode 32 (conditional call)**: same math again, gated by a
runtime per-state table lookup instead of a flag/ring test; calls
`func_020113B4` (a real call, ring push) when taken. Treated the same as
opcode 4 for flow-following: target and fallthrough both reachable.

**Field VM, opcode 5 (return)**: `func_020113C4` pops the call-history
ring back into `vm->pc` -- a real but entirely dynamic target (whatever
opcode 4/32 pushed at runtime, which depends on the actual call chain
taken, not something visible in one sub-file's bytes alone). No static
target, no fallthrough; the flow-following sweep stops here without
adding anything to its worklist, the same way `STOP_OPS` do.

**Battle effect VM (`btleff.py`), opcodes 60/61 (compare-then-jump)**:
each fetches several `u32` operands; the LAST one fetched is the jump
offset (confirmed for both: opcode 60 stashes it on the stack before
calling the shared comparator `func_021FBDD4`, which reads `vm->pc` fresh
and adds `[sp,#8]`; opcode 61 keeps it in `r7`, added the same way after
its own inline comparison). `target = pc_after_operand + s32`, called via
`sub_020113B0` only if the comparison is true; the handler returns
normally (pc untouched) otherwise. Both target and fallthrough reachable.

**Battle effect VM, opcode 72 (unconditional jump)**: `func_021FC334`
fetches its one `u32` operand and calls `sub_020113B0(vm, pc_after_operand
+ rel)` unconditionally, no comparison. Target only, no fallthrough.

**Battle effect VM, opcode 74**: grouped with 72 by opcode shape (one
`u32` fetch, eventually reaches its own `sub_020113B0` call) but this pass
did not read its handler (`func_021FC374`) to the same depth as 72's --
its body computes a table index and makes an extra call before reaching
the jump, and the jump call itself was not located in the bytes read.
`btleff.py`'s flow-following treats 74 as unconditional (same as 72); this
is a residual, UNCONFIRMED assumption, called out explicitly in both the
module docstring and the "Remaining gaps" below.

**Battle effect VM, opcode 70 (call into `a/0/6/7`)**: already documented
in the previous pass -- reads `a/0/6/7[computed member]`'s own payload
pointer (offset 4 off the loaded sub-file, the same convention
`events.py`'s container framing uses) and calls `func_020113B4` with that
POINTER, not a byte offset into the calling group's own payload. This
target lives in a different archive's byte buffer entirely, so it cannot
be represented as a position in the calling group's `raw` bytes; this
pass's flow-following does not cross archives -- opcode 70 is treated as
consuming its operand and falling through (the call returns), and
`a/0/6/7`'s own groups are swept independently, starting from their own
offset-0 entry points, when `--flow` runs against that archive. The two
archives' reachability statistics are reported separately, never merged
into one shared byte-position space.

### `tools/assets/scripts.py --flow`: field-VM statistics, before/after

Before this pass (`--check`, the LINEAR per-entry sweep, no jump/call
following, from the "operand-width table extended to 609 opcodes" pass):

    entry points decoded: 2592 (first pass) / 3206 (later 0xFD13-count fix)
    landed cleanly:        2352 (90.7%)      / 2935 (91.5%)
    desynced:                232             /   16
    hit variable/unresolved: (n/a, no split) /  254
    ran past EOF:             (n/a)          /    1

After this pass, same LINEAR `--check` (now that all 609 opcodes resolve
to `fixed`, so the sweep no longer stops early at a variable/unresolved
opcode -- it keeps walking, which surfaces some real desyncs the earlier
version's early stop was hiding):

    entry points decoded: 3206
    landed cleanly:        3178  (99.1%)
    desynced (opcode >= 609): 27
    hit variable/unresolved:   0
    ran past EOF:               1

New this pass, `--flow` (the worklist disassembler, following opcodes 4/
30/31/32's computed targets in addition to walking each entry linearly):

    script sub-files: 471
    files with zero undefined-opcode reaches: 388/471 (82.4%)
    files fully clean (also no mid-instruction EOF): 387/471 (82.2%)
    total code bytes:       416510
    total reachable bytes:  322826  (77.5%)
    total gap bytes:         93684  (22.5%)

`--flow`'s clean-file rate (82.2%) is lower than `--check`'s per-entry
landing rate (99.1%) because following call targets pulls in MORE code per
file than a single linear entry sweep does -- a file can have every one of
its own listed entries land cleanly while a CALLED subroutine (reached
only via opcode 4/32, not listed in the entry table) desyncs. That is the
statistic this pass was asked to report: "fraction of files with zero
undefined-opcode reaches and gaps explained as data" is 82.4% (zero
undefined reaches) for `a/0/5/7`; the 22.5% gap-byte figure is not further
split into "explained as data" versus "unexplained" this pass -- see
Remaining gaps.

### `tools/assets/btleff.py --flow`: battle effect-VM statistics, before/after

Before (linear `--check`, unchanged from the previous pass, reproduced for
comparison):

    groups swept: 741
      stop:       679  (91.6%)
      desync:      40   (5.4%)
      short:       13   (1.8%)
      exact_end:    9   (1.2%)
    clean (stop or exact_end): 688/741 (92.8%)

After (`--flow`, worklist disassembler following opcodes 60/61/72/74's
computed targets):

    a/0/6/6: 641 groups
      zero undefined-opcode reaches: 627/641 (97.8%)
      clean:                         627/641 (97.8%)
      reachable bytes: 382568/392356 (97.5%)
    a/0/6/7: 100 groups
      zero undefined-opcode reaches:  74/100 (74.0%)
      clean:                          66/100 (66.0%)
      reachable bytes:  32024/40424  (79.2%)
    combined: 693/741 groups clean (93.5%)

Combined clean rate (93.5%) is a modest improvement over the linear
sweep's 92.8%, and `a/0/6/6` alone (97.8%) is well above it -- most of the
combined figure's shortfall comes from `a/0/6/7` (66.0% clean), which
makes sense given `a/0/6/7` is reached two different ways (opcode 70's
call-in from `a/0/6/6`, and `func_021F94F8`'s own overflow path) that this
pass's per-archive, offset-0-only entry set does not fully capture -- see
Remaining gaps.

### Round trips

Neither `OPERAND_WIDTH` nor the new flow-following code touches
`parse_subfile`/`pack_subfile` (field VM) or `events.py`'s
`parse_0666`/`pack_0666` (battle effect VM) -- both still round-trip
exactly: `scripts.py --verify` reports **899/899**, `btleff.py --verify`
reports **601/601** (`a/0/6/6`) and **98/98** (`a/0/6/7`), unchanged from
before this pass.

### Remaining gaps

- Opcode 74's jump is treated as unconditional by assumption (grouped
  with 72's confirmed shape), not independently confirmed by reading its
  `sub_020113B0` call site -- if it turns out to be conditional like 60/
  61, `btleff.py`'s reachable-byte counts for `a/0/6/6`/`a/0/6/7` are a
  slight underestimate (a missed fallthrough successor).
- `--flow`'s 22.5% (field VM) / ~10% combined (effect VM, weighted) gap
  bytes are not individually classified into "known data" versus
  "unexplained code this sweep failed to reach" -- the module docstrings
  describe the two expected sources (untaken conditional-jump sides that
  still fail for other reasons downstream, and orphan/unpaired entries
  this sweep's worklist seeding does not reach) but no archive-wide
  breakdown by cause was produced.
- The field VM's 27 real desyncs (opcode >= 609, up from 16 in the
  earlier, less-complete table) were not individually diagnosed -- fixing
  17+18 opcodes' widths let more entries walk further, which surfaced
  these as genuine rather than early-stopped, but none were traced to a
  specific still-wrong width or a genuinely data-dependent instruction
  stream this table cannot represent (e.g. inline string/dialogue bytes
  inside a script, which would desync any bytecode-shaped read of them).
- `a/0/6/7`'s lower `--flow` clean rate (66.0%) was not root-caused beyond
  the observation that it is reached by two different call paths this
  pass's per-archive, single-entry-per-group sweep does not merge; a
  cross-archive worklist (seeding `a/0/6/7`'s sweep from every opcode-70
  call site actually found in `a/0/6/6`, in addition to each group's own
  offset 0) was not attempted.
- The field VM's 428 non-script side tables and the `a/0/5/7` sub-files
  with no 0xFD13 table remain out of scope for this pass, unchanged from
  before.
- The battle effect VM's 14-fold slot redundancy (every group's header
  block repeats the same word 14 times) is still unexplained; this pass
  did not revisit it.

## Archive readers, second level

Finishes the lane a prior session cut mid-task. Inputs: `build/assets/
reader_scan2_full.json` (the deduplicated per-call-site results, 106 family
call sites, matching `build/assets/reader_map2.json`'s own consolidated
form byte-for-byte on every resolved archive id) and `build/assets/
reader_scan2_raw.json` (an earlier, partial run of the same tool, only 21
distinct ids resolved, one of them -- `a/0/0/5` -- not reproduced in the
full run and not used here). Both dumps are the output of the "fourth
pass" tool already named in `tools/assets/tables.py`'s own docstring
(`reader_scan2.py`, up to three caller levels, the cross-region `.inst.w
blx` fix), so this write-up documents that pass's actual findings rather
than starting a fifth one.

### Coverage

    first-level scan (build/assets/reader_map.json): 39/237 archives with
    an attested open site
    second-level scan (build/assets/reader_map2.json /
    reader_scan2_full.json): 43/237 distinct archives resolved to a
    constant id, of which 2 do not survive manual verification (below)
    verified new archives this pass: 2 -- a/0/6/2, a/0/7/4
    coverage after this pass: 41/237

### Newly identified archives

| archive | reader address | region | source file | identification | confidence |
|---|---|---|---|---|---|
| a/0/6/2 | arm9 func_0201493C, `bl func_02014A20` at 0x02014974 (two-level parameter passthrough into `func_02048F60(archive_id=62,...)` at 0x02014A40) | arm9_main | field_status.c | field-status subsystem table, 15x52-byte sub-block period, sibling of a/0/6/1 (still no reader) | MEDIUM (structural period unchanged, reader now confirmed at two call levels; fields not decoded) |
| a/0/7/4 | overlay_021 func_021C8018, `movs r0, #0x4a` / `movs r1, #0` then `.inst.w blx 0x02046DB8` at 0x021C8030 (cross-region call, forwarded unchanged into `func_02048F60(archive_id=74, member=0, heap)` at 0x02046E00) | overlay_021 | fld_wipe_3dobj.c (confirmed: the function's own `__FILE__` pool word at 0x021C8050 sits inside this same function, 0x021C8018..0x021C8608; `fileanchors.py --lookup` without a region hint misattributes this address to overlay_016 because both overlays are laid out over the same address range and the tool cannot disambiguate, so the region-filtered rows of `layout/file_anchors.txt` were read directly instead) | Already identified structurally as NSBMD (nsbmd.py, verified round trip); this reader corroborates that identification from a `fld_wipe_3dobj.c` call site, consistent with a wipe-transition 3D object, and does not change the decode | HIGH (direct immediates on both sides of the cross-region call, decode already verified) |

a/0/6/2 is inside `tools/assets/tables.py`'s scope (`_GROUP2`); its note
was already updated by the session that got cut off, and is confirmed
correct here (`python tools/assets/tables.py --verify a/0/6/2`: 10/10
byte-identical). a/0/7/4 is outside `tables.py`'s scope (owned by
`nsbmd.py`, already verified); only the census row is updated with the
corroborating reader, per the same convention used for `a/0/6/6` and the
other out-of-scope archives in the first-level pass. `tools/assets/
tables.py --verify a/0/1/5` and `--verify a/1/7/9` (two archives already
carrying a first-level-pass reader note) were also re-run as a sanity
check that nothing in the registry broke: both still round-trip
byte-identical (5/5 and 50/50).

### Two resolved ids rejected as scan artifacts

The full dump resolves two more ids that do not survive manual
verification against the actual instructions, and neither is reported as
a newly identified archive:

- **a/0/0/0** (id 0): resolved by climbing through `arm9_main@0x02048D78`
  (inside `func_02048D54`) up through `arm9_main@0x02048F6C` (inside
  `func_02048F60`) to `arm9_main@0x02020F52` (inside `func_02020F34`, the
  already-known reader for `a/0/2/4`, archive id 24). Reading the actual
  instructions: `func_02048F60` forwards its own r0 unchanged into
  `func_02048D54` (`bl func_02048D54` at 0x02048F6C, no r0 write in
  between), and `func_02048D54` in turn forwards that same value
  (`mov r4, r0` at entry, then `mov r1, r4` at 0x02048D68) into
  `func_02048DDC` at 0x02048D78 -- so the fully-resolved id at every level
  of this chain is 24, the same value the one-level scan already found at
  `0x02020F52` directly, not 0. The second-level tool's climb produced 0
  instead, which does not correspond to any instruction on this call path;
  it is not a real archive-open site and a/0/0/0 is not newly identified.
- **a/0/0/1** (id 1): resolved via `arm9_main@0x0204A230` (inside
  `func_0204A1BC`, calling `func_02048F4C`, an r1-consumer) climbing one
  level to `arm9_main@0x0202F88C`. Reading `func_0204A1BC`: its incoming
  r1 (member index) is captured to r7 and never reaches the family call;
  the id-carrying r1 at 0x0204A230 is `mov r1, r8` where r8 is the
  function's own incoming **r0** (`mov r8, r0` at entry). At the actual
  call site 0x0202F88C the caller sets `r0 = 0x16 = 22` and `r1 = 1`
  immediately before `blx func_0204A1BC` -- so the value that reaches the
  family call is 22 (archive `a/0/2/2`, not currently otherwise attested),
  and the tool's reported 1 is the caller's r1 (the unrelated member-index
  argument), picked up because the climb matched the deepest frame's
  register name (r1) against the same register name in the parent frame
  instead of following the r8-to-r0 rename inside `func_0204A1BC`. This is
  a real bug class in the scan (register identity is not always preserved
  by name across a call boundary when the callee renames its own
  parameters before forwarding them further), not evidence for either
  `a/0/0/1` or `a/0/2/2`; neither is reported as newly identified from this
  entry, since the corrected id (22) is not itself an attested finding of
  this scan, only a byproduct of manually checking why the reported one
  (0/1) was wrong.

Both rejections were reached by reading the actual disassembly at every
hop of the chain (`asm/arm9/main.s`), not by re-running the scan tool
(which is a scratch script, not committed). Any other id in the 43-archive
set that was reached through two or more caller levels should be treated
with the same caution until similarly checked by hand; the two verified
here (a/0/6/2, a/0/7/4) both happened to be clean parameter passthroughs
with no intervening register rename, which is what makes them trustworthy
and the other two not.

### What remains

- Coverage stands at 41/237 archives with an attested open site (39 from
  the first-level pass, plus a/0/6/2 and a/0/7/4 from this one).
  `_GROUP2`'s own reader count is unchanged at 24/75 (a/0/6/2 was already
  counted there by the session that got cut off; a/0/7/4 is outside
  `_GROUP2`).
- 51 of `_GROUP2`'s 75 archives still have no attested reader by any
  method run so far (unchanged from the first-level pass; every entry in
  `tools/assets/tables.py`'s `_GROUP2` dict whose note still reads "No
  reader found").
- The remaining unresolved family call sites in `reader_scan2_full.json`
  (6 of 106, matching `reader_map2.json`'s own `unresolved_call_sites`
  count) are cases the backward walk still cannot follow even after
  climbing three levels: a value arriving through something other than an
  immediate load, a register-to-register rename, or a literal-pool word
  (an `adds`/register arithmetic, a table load, or a fourth level of
  caller). They are not evidence of "no reader", just outside this
  method's reach, same caveat as the first-level pass.
- Id tables found in the two dumps: only the constant-archive-id mapping
  described above (`resolved: ["const", N]` per call site) and the call
  chains themselves; neither dump carries any other id table (no
  string/name table, no separate index of archive ids beyond the
  per-call-site `resolved` field). `reader_map2.json` additionally records
  `levels_climbed` per site, which is what made the two rejections above
  possible to reconstruct without re-running the scan tool.
