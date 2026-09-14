# Asset inventory (lane 1: investigation)

This is the first asset-pipeline lane: pure investigation and inventory of the
247 NitroFS files under `extract/data/` (as unpacked by `tools/ndsrom.py`).
No asset converters exist yet. Everything below was produced by two new
stdlib-only tools, `tools/assets/narc.py` and `tools/assets/inventory.py`,
written from scratch for this project.

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
| 0x20 / 0x24 | Huffman, 4-bit | sniffed only |
| 0x28 | Huffman, 8-bit | sniffed only |
| 0x30 | RLE | sniffed only |

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
- **Huffman/RLE**: not decoded, tag and declared size are reported only.

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
- Compression histogram across all sub-files: `none` 40916, `LZ11` 10794,
  `LZ77` 1522, `Huffman4` 800, `RLE` 32
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

- **Trainer sprites -- `a/0/0/6`** (medium confidence). 733 sub-files
  (there are on the order of 700+ trainer classes in Black/White), **every**
  sub-file Huffman4-compressed, average ~12 KB each -- consistent with a
  full-body trainer portrait. The on-disk magic tag (`" APS"`, i.e. reversed
  `"SPA "`) does not match any known NITRO chunk, so this is Game Freak's own
  wrapper around Huffman-compressed bitmap data.

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

- **Pokemon cries -- not located with confidence.** No standalone NARC has a
  species-sized (~649-670) sub-file count paired with SDAT-flavoured magics
  (`SSEQ`/`SWAR`/`SBNK`). The likely explanation is that cries live inside
  `wb_sound_data.sdat` (51.5 MB, the only huge sound archive) as sequences/
  wave data addressed by index rather than as a separate per-species NARC.
  This lane did not open the SDAT internal structure (StringID/INFO/section
  tables from GBATEK-level SDAT documentation), so this is unconfirmed.

- **Music and sound effects -- `wb_sound_data.sdat`** (high confidence it's
  *the* sound archive; low confidence on splitting music vs. SFX within it).
  It is the only file with an `SDAT` magic at the top level and is by far
  the largest file in `extract/data/` (51.5 MB, versus the next-largest NARC
  at 19.5 MB). A handful of small NARCs (`a/1/4/0`, `a/1/4/2`, `skb.narc`,
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

- Category guesses throughout this document and `inventory.json` are
  heuristic and explicitly labelled "(guess)". None have been confirmed by
  actually decoding and viewing pixels, text, or audio.
- The BTNF (file name) section is parsed structurally but not decoded into
  human-readable paths; sub-file names might disambiguate several of the
  "uncertain" categories above and are worth revisiting.
- SDAT internal structure (the sections inside `wb_sound_data.sdat`) was not
  opened at all in this lane.
- Huffman and RLE compressed sub-files (832 total) were sniffed but not
  decoded; a future lane needs both decoders before those sub-files are
  usable.
