# Pokemon White: how it differs from Black

First-pass map (milestone 5, "Pokemon White support"). Black is the build target today.
This page says what White changes, how much, and how the build can take a version. No
game bytes are stored here: names, addresses and counts only. The full per-function list
is in `docs/restructure/white_diff.tsv`.

## How this was measured

- `tools/ndsrom.py extract` on the White image (its game-code check is the only thing
  that refuses it: `IRAO` instead of `IRBO`) into `extract_white/` (gitignored).
- `delink.py` on `extract_white/` into `build/white/layout/` (TWL region skipped, see
  "The DSi region").
- `tools/white_diff.py` compares every region of Black and White after aligning the two
  word streams (`difflib`) with relocation wildcards (`tools/white_align.py`): ARM
  B/BL/BLX displacements, Thumb BL/BLX pairs (also across a word boundary) and
  address-like words (RAM, TCM, IO, VRAM) are masked. Function boundaries come from the
  Black disassembly listings.

A word that changes inside an address-like value counts as "constant", not "differs".
So "differs" below is a lower bound on pure code changes; the `constant` rows hold every
function that has at least one changed relocation or constant word.

## Header and layout facts

| Field | Black | White |
|---|---|---|
| title / game code | POKEMON B / IRBO | POKEMON W / IRAO |
| ROM size | 0x10000000 | 0x10000000 |
| ARM9 compressed size | 0x6F898 | 0x6F8A4 (+12) |
| ARM9 decompressed size | 681920 | 681952 (+32) |
| NTR used size (header 0x80) | 0xC3B8E00 | 0xC3B9400 (+0x600) |
| TWL used size (header 0x210) | 0xC45D400 | 0xC45D400 |
| ARM9 load / entry | 0x02004000 / 0x02004800 | same |
| overlay table | 237 entries | 237 entries, same flags |
| NitroFS files | 247 | 247 |
| header CRC16 (0x15E) | 0x8485 | 0xF6BF |
| logo CRC16 (0x15C) | 0xCF56 | 0xCF56 |

Header bytes that differ: title and game code, ARM9 size, NTR size, ARM9i size
(0x1CC), the secure-area CRC, header CRC, digest and HMAC fields (0x300 to 0x3B3),
and the tail 0xF80..0xFFF. Everything else matches.

The ARM9 static module is 32 bytes longer (its end moves from 0x020A9E80 to
0x020A9EA0), so the overlay RAM area starts 0x20 higher: 232 of the 237 overlays load
0x20 higher in White. Only
overlay 88 changes size (17536 to 17568 bytes, +32). The three ITCM/DTCM/VRAM autoload
blocks and their sizes are unchanged.

White's ROM dump keeps non-0xFF filler after the used area (62.5 MB in three residue
blobs). Black's dump has one 12 KB blob. `ndsrom.py` already stores residue verbatim, so
a rebuild works, but the filler is a property of the dump and not game content.

## Regions: headline numbers

243 compared units: the ARM9 static module, the 4 ARM9 autoload blocks, 237 overlays and
overlay 230's decrypted view (`ov230d`). The DSi region is a further row that cannot be
compared (see "The DSi region").

| Class | Units |
|---|---|
| byte-identical | 59 |
| identical after relocation masking (only addresses and constants moved) | 158 |
| real differences beyond masking | 26 (ARM9 static and 25 overlays) |

Of the 25 overlays: 19 have 1 to 5 unmatched words (mostly one version-dependent
immediate each, see below), and 6 have more (ov010 6 words, ov011 13, ov021 84,
ov088 74 on the Black side and 82 on the White side, ov172 8, ov181 70).

Data files (NitroFS): 5 of 247 differ, 242 are identical.

| File | Black | White |
|---|---|---|
| a/0/8/6 | 3356 | 3356 (5 bytes differ) |
| a/1/2/6 | 35284 | 35284 (382 bytes differ) |
| a/1/7/8 | 168792 | 168792 (296 bytes differ) |
| a/0/2/6 | 22228 | 22528 (+300) |
| a/2/3/1 | 1208900 | 1210248 (+1348) |

Other units: the banner differs (2789 bytes, title text), the overlay and file
allocation tables differ only in the entries that follow from the size changes, and the
DSi-side binaries are not comparable (see "The DSi region").

## Functions (per-function rows in white_diff.tsv)

| Kind | Functions | Meaning |
|---|---|---|
| same | 10590 | raw bytes identical at the same region offset |
| constant | 18133 | same offset, only relocation or constant words differ |
| shifted | 7097 | same code at a different region offset (ARM9 after 0x02011C40) |
| differs | 71 (1632 bytes in total) | code differs beyond relocations |
| new | 41 ranges (2212 bytes in total) | White-only bytes, no Black twin |

The row counts include the small helper entries the listings label as functions, so the
figures are listing entries, not a count of C functions.

`differs` by region: ARM9 15 (452 bytes), ov021 5 (336), ov088 5 (296), ov181 7 (280),
and 1 to 4 small ones in 21 other overlays. 45 of the 71 differ by one word. The
single-word cases are version-dependent immediates: Thumb `mov rN, #imm` or `ldr`
operands that change by one (for example 0x15 to 0x14, 0x0F to 0x0E) in ov012, ov032,
ov099, ov114, ov116, ov119, ov125, ov093, ov206, ov225 and others. These are the
natural `#if VERSION` sites. The larger rows are real code changes:

- ARM9 0x02026A60 (360 bytes differ, plus 52 new bytes beside it at 0x02026A88 and
  0x02026AB4): the biggest single change in the main module.
- ARM9 0x0209D850 (24 bytes) and 12-byte changes at 0x020139B0 and 0x02084AB0.
- ARM9 data tail, 0x020A6518 to 0x020A9BDC: about 1.8 KB of White-only bytes in 11
  ranges, plus unmatched words in the data after the last code. This reads as a table
  that grew or was rewritten; treat it as data, not functions.
- ov021 0x021B6708 (252 bytes) and 0x021B6934 (56), with 8 small new ranges (212
  bytes); ov088 0x021B965C (124), 0x021BAB64 (116) and 0x021BD3B8 (48) with 7 new
  ranges (120 bytes); ov181 seven functions (280 bytes), the largest at 0x021BAB00
  (144); ov172 0x021BA280 (32); ov111 0x021C842C (16).

Code with no Black twin is therefore small: about 2.2 KB total, most of it in the ARM9
tail and in ov021, ov088, ov181.

## Overlay 230

Overlay 230 differs in 193 of its 6816 bytes, in the encrypted file and in the decrypted
view alike. The earlier "one byte" difference in the decryptor
(0x021889E4..0x02188B48) is a relocation, not a constant of the scheme: White loads the
overlay at 0x02187F20 instead of 0x02187F00, and the one differing byte is the low byte of
the pool word END (0x02188B3C, the overlay's end address: 0xA0 in Black, 0xC0 in White).
KEY, DELTA, the bias and the cipher are the same.

`tools/ovcrypt.py` now takes both games. The version is the overlay's load address
(`VERSIONS`: shift 0x00 Black, 0x20 White); every address it pins moves by the shift, and each
version has its own SHA-1 for the three spans it reads (decryptor, cipher, dispatcher; the
White decryptor and dispatcher differ only in pool words, the cipher span hashes the same).
A load address that is neither is refused as before. For White it opens both layers: 5
initialisers, 28 first-layer ranges and 18 sealed bodies (46 ranges, the same counts as
Black), every range a clean ARM function, and `encrypt()` of the view gives the White file
back. `ovcrypt.py selftest` still passes its 12 Black cases, and `gamelink.py 230` still
links Black.

Aligned against Black, the `ov230d` view is identical after relocation masking: 18
functions byte-identical, 35 with only address words moved, nothing else (185 changed
words, all address constants). So overlay 230's code is the same source in both games.

## The DSi region

The `twl` region (arm9i) cannot be compared, and the reason is not the key. The DSi key
file was available and `modcrypt.py` derives White's key from its header, but White's
arm9i has nothing to decrypt: the whole DSi part of the dump, ROM 0x0C400000..0x0C45D400
(93 pages of 4 KiB, covering the arm9i, arm7i and digest areas), is one 4 KiB page repeated
93 times. That page is also found at ROM 0x8000 (the ARM9's first compressed page), so the
dump tool filled the region with a wrapped read of the NTR area instead of the DSi data.
This explains the missing BLZ footer: the last 8 bytes of "arm9i.bin" are the end of the
filler page, not a footer (the 0x1000-byte period is visible in the raw bytes, and a
modcrypt pass turns the plain filler into noise). Black's arm9i has the usual footer and
varied content.

What the header still gives: White's arm9i container is 0x12F1C bytes (Black 0x12F24, 8
fewer), and the ARM9's TWL build info differs only in `compressed_code_end` (8 lower). The
autoload entry and the rest of the build info are identical. That is one row in
`white_diff.tsv` (`twl`, kind `region-unavailable`, 8 bytes). A comparison needs a dump
that includes the DSi area (a DSi-mode dump of White).

## Version build proof (overlay 116)

Overlay 116 (8032 bytes, the smallest overlay in the "1 to 5 words" group) is built for
White from the same files as Black: `src/game/ov116/wifi_bsubway.c` has one version site,
the message index in `WIFI_BSUBWAY_StatusCheckMessage` (15 in Black, 14 in White; the
`movs r1, #imm` that differed):

    #if VERSION == VERSION_WHITE
    #define BSUBWAY_PROFANITY_MSG 14
    #else
    #define BSUBWAY_PROFANITY_MSG 15
    #endif

`src/game/version.h` defines `VERSION_BLACK`, `VERSION_WHITE` and defaults `VERSION` to Black,
so a build with no flag is Black. `tools/match.compile_tu` adds `-d VERSION=2` when the
environment variable `ALETHEIA_VERSION` is `white`. `tools/gamelink.py N --version white`
(or `ALETHEIA_VERSION=white`) sets that and links for White:

- Link planning stays in Black addresses. Every address written to the linker command file
  (region origins, absolute symbols, callee stubs) goes through `tools/white_map.py`:
  overlay RAM and the static bss move +0x20; ARM9 callees and data go to their White
  address through the word alignment of the two ARM9 images (blocks that line up, plus
  same-length runs of changed words such as GAME_VERSION_Code at 0x0209DF08 to 0x0209DF20);
  an ARM9 address with no White twin fails the run. The map is cached in
  `build/white/arm9_map.json`.
- The gaps between files (540 bytes of data and padding in ov116) come from
  `extract_white/`, and the linked image is compared with White's overlay.
- Output goes to `build/gamelink/ov116_white/`; `ov.json` records the version.

Result: `gamelink.py 116 --version white` links 262 stubs and 19 absolute symbols and gives
an image byte-identical to White's overlay 116 (8032 bytes, load 0x021D6680). Black:
`gamelink.py 116` and `gameverify.py --file src/game/ov116/wifi_bsubway.c` stay exact, and
`gamelink.py 230` and the gamelink selftest still pass. Negative control: the same White
link with the VERSION flag suppressed fails on exactly one word (0x021D6C92, the
message index).

The other single-word sites (about 45 in other overlays) need the same treatment: a version
site in the source and an overlay of equal size in both games. An overlay whose size
differs (ov088, +32 bytes) and the ARM9 static module need a White layout with moved file
addresses, which this link mode does not do yet.

## White link of all overlays (wave 19)

`python tools/whitelink.py [--jobs N] [--black] [ids...]` runs `gamelink.py N --version white`
(or without the flag with `--black`) for every overlay that has a source directory and writes
`build/whitelink.tsv` (PASS or FAIL, the differing words). Result: 166 of 180 overlays link
byte-identical to White's overlay from the same `src/game` files as Black (ov116 was 1 of 84
before this wave). Black is unchanged: `gameverify.py` is exact for every file edited, and the
Black link passes for every overlay that no other lane had broken at the time.

How the address differences are handled, without changing Black's output:

- Callee stubs and absolute symbols go through `tools/white_map.py`. Overlays whose code
  moved inside them (ov021, ov088, ov172, ov181, ov203, ov204) have a per-overlay word
  alignment (`to_white_ov`, cached in `build/white/ovmap_ovNNN.json`). A callee in such an
  overlay is mapped by the region a file header names for it (`symbols:` rows may end in
  `ov021`, or `data ov088 a4`); with no region the irregular overlay that has a function
  starting at that address is used (`guess_callee_region`).
- Address literals in the C sources (`0x021B3C20` and the like) are Black addresses. For a
  White build `tools/match.compile_tu` compiles a copy of the file with every 0x02xxxxxx
  literal mapped (`white_map.remap_source`); literals outside the ARM9 module and every
  overlay (memory-map limits such as 0x02300000) stay.
- Constants that really differ are named in `src/game/version.h`: `PM_VERSION_ID` (21 Black,
  20 White), `PM_VERSION_MASK` (1 << version id), `PM_VERSION_BIT` (the version bit of a
  per-version flag), `MSG_PROFANITY_NOTICE` (15 Black, 14 White). A few sites keep a local
  `#if VERSION == VERSION_WHITE` (ov107 multiboot message ids and icon paths, ov225 message
  archive 62 or 63). 20 files carry a switch.

Wave 19, part 2: the irregular overlays (ov021, ov088, ov172, ov181, ov203, ov204) link in White
coordinates: each file goes to its White start, the gaps between files are read off that, and
addresses inside the overlay and its bss go through the block alignment (`white_map.to_white_ov`,
`to_black_ov`). Real White code differences are now version switches: the version id (`PM_VERSION_ID`),
`PM_VERSION_BIT`, `PM_VERSION_MASK`, `PM_VERSION_LEGEND_SPECIES` (0x283 Black, 0x284 White) and local
`#if VERSION == VERSION_WHITE` blocks (staff roll fade colours, title demo frames and extra tile clears
in ov088, zone data init and BGM id in the ARM9, a tail call in `crt0`). The ARM9 static module and ITCM
link for White (`gamelink.py arm9_main itcm --version white`); the SVC thunks of the secure area sit at
other offsets in White and are placed by their swi number, the two compressed-end build-info values come
from White's layout. `extract_white` was re-made from the current white.nds (the old one came from a
different dump). Still open: ov010 (`event_battle`, 3 words), data mode for White.

## White ROM from src/game (wave 19, WHITE5)

`python tools/romlink.py --version white` builds `build/rom/white.nds`: layout from
`build/white/layout/layout.json`, extract `extract_white/`, regions from the plain-mode links in
`build/gamelink/<region>_white/` (`--relink` runs `whitelink.py` and the ARM9 and ITCM links first),
overlay 230 sealed again by `ovcrypt.encrypt`, report in `build/rom/report_white.json`. Data mode and
`--onelink` do not exist for White: the gaps inside regions (data tails, padding, the secure-area
filler) come from the image. With every region taken from a link the result is IDENTICAL to the
original (SHA-1 0c43d714...) as soon as all overlays pass; with `--image-fallback` a region that does
not link keeps its image bytes and is listed. Today ov010 is the only overlay that fails
(`event_battle.c`, see below).

The DSi block needs no re-encryption: White's DSi area in this dump is one repeated filler page (see "The
DSi region"), `ndsrom.py` stores it as it is, and its extract and build round-trip byte-identical for both
games (Black 26ad0b99..., White 0c43d714...); no change to `ndsrom.py` was needed.

Secure area, 0x02004600: Black has libsyscall filler there (noise around the SVC thunks, thunk `swi 0x0E`
at 0x02004632). White has a 92-byte ARM routine (17 instructions and 6 pool words, the thunk moved to
0x0200465C) that compares a word at 0x02187F84 with a constant, stores five words at offsets 8, 0x148,
0xA8 and 0x1E8 of that block when it matches, then sets one byte at 0x02180A00+0xA, and returns; the White
crt0 `_exit` tail-calls it in place of `bx lr`. That is 92 + 4 = 96 bytes, the exact size of the difference
between two dumps of the same cartridge. It is not game code: it writes overlay-area RAM at startup, which
no SDK function does, and it exists only in this dump. It is treated like Black's secure-area filler (image
data, never source); the branch stays in `crt0.c` under the White switch with a comment, so the build
matches this image.

## Not done

- ARM9i / TWL region: not in the dump (see "The DSi region").
- Function rows inside the ARM9 secure area (first 0x800 bytes of the module). They are
  encrypted with the game code as key, so they differ by construction; they are
  excluded from the alignment.
- Data inside overlays and the ARM9 is compared as words, not by table. A table lane
  should split the 5 changed data files and the ARM9 data tail into structs.

## Plan: building White from the same source

1. **Version define.** Done for the mechanism (`src/game/version.h`, `--version white`,
   proven on overlay 116); the rest is adding sites. The ~45 single-immediate differences become `#if` or a named constant in
   the few functions involved. The listing gives each address.
2. **Separate layout for shifted code.** The ARM9 static module and every overlay base
   move by +0x20 (and ov088 grows by 0x20). Keep Black's layout files as they are and
   add `layout/white/` generated by `delink.py` (it already produces a correct
   `layout.json` for White: build info, autoload table and overlay table all parse).
   The 0x18 to 0x20 byte insertions in the ARM9 (0x02011C40, 0x02013A38, 0x02013C0C,
   0x02026A60, 0x020A6500) are real source differences, not layout noise: each needs a
   version branch or a larger buffer in the owning translation unit.
3. **Data.** Five NitroFS files differ and one ARM9 data tail grows. Data is generated
   from the user's own extract (`tools/datagen.py`), so a White extract produces White
   data with no source change; the version-specific tables should be kept as
   extract-driven, not copied.
4. **romlink for White.** `ndsrom.py` needs its game-code check made a parameter (a
   `--gamecode` option or a manifest field, not a hard-coded constant). With that,
   `romlink.py` takes `extract_white/` as the base image and the White layout, links
   the same object files, and checks byte identity against `white.nds` using the same
   `ndsrom.py verify` path. Residue blobs (including the large filler) are carried as
   they are today.
5. **Order of work.** (a) White layout and a link of the unchanged functions (about 98
   percent of listing entries are same, constant or shifted and need no new code);
   (b) the one-word version immediates; (c) the ~26 functions with larger differences
   and 2.2 KB of new code, ARM9 0x02026A60 first; (d) ov230 and the ARM9 tail data;
   (e) the TWL side (needs a dump with the DSi area).

Estimate: the matching work for White is on the order of 25 to 30 function-sized
changes plus 45 one-word switches and a few tables, against about 36,000 functions
that carry over unchanged. The build and layout plumbing (items 2 and 4) is the larger
part of the effort.

## Reproduce

    python tools/ndsrom.py extract white.nds -o extract_white   (needs the game-code check relaxed)
    python tools/delink.py -e extract_white -l build/white/layout
    python tools/white_diff.py
    python tools/ovcrypt.py selftest
    python tools/gamelink.py 116 --version white     (needs build/white/layout and extract_white)

`tools/white_diff.py` writes `docs/restructure/white_diff.tsv` and
`build/white/summary.json`.

## Verified retail dump (probe of 2026-10-19)

`white.nds` is now the No-Intro dump (decrypted SHA-1 bc696a0dfb448c7b3a8a206f0f8214411a039208).
It was extracted into `extract_white_retail/` (gitignored) and delinked into
`build/white_retail/layout/`, then compared with the earlier extract (SHA-1 0c43d714...), file by file.

Result: the two dumps differ in exactly 96 bytes of the ARM9 image and nowhere else.

| Item | Result |
| --- | --- |
| Secure area 0x02004000..0x02004800 | Only 0x02004600..0x0200465B (92 bytes, all different) differs. The rest, including the SVC thunk at 0x0200465C, is identical. |
| 0x02004600 routine | Absent. The 92 bytes are noise filler like Black's libsyscall filler (91 non-zero bytes, no code structure). |
| crt0 tail (`_exit`, ARM9 offset 0xEA4) | Retail has `bx lr` there. The old dump had a branch to 0x02004600 (1 word differs). |
| Residues and padding | One residue blob (0x3000 bytes, same bytes as before). The two extra blobs in the old `extract_white/residue/` (0001, 0002) are stale files from an earlier extract; the old manifest lists one blob only. |
| arm7, arm7i, arm9i, banner, header, header_ext | Identical. |
| DSi digest block and sector digests | Identical. |
| NitroFS files, fat, fnt, y9, all 237 overlays | Identical. |
| `layout.json` | Identical except the `extract_dir` field; `layout.txt` identical. |
| ARM9 decompressed | Differs only at the same 96 bytes. |

Round trip: `ndsrom.py build extract_white_retail` gives SHA-1 bc696a0d... (identical to `white.nds`).

DSi TWL region (0x02700000..0x02732DA0): decodes with the modcrypt key constant from the key file
(`delink.py` found it in the environment setup), stream consumed exactly, 0x32DB4 bytes;
`arm9i_dec.bin` is identical to the old one.

The routine was therefore a dump-tool patch: the clean dump has no `INITi_SecureAreaPatch`.

### What the next White wave must change

1. `src/game/arm9/crt0.c`: delete the `#if VERSION == VERSION_WHITE` branch to
   `INITi_SecureAreaPatch` in `_exit` (keep plain `bx lr` for both versions), the
   `extern void INITi_SecureAreaPatch(void);` (line 58) and its line in the header comment (line 28).
   Remove any symbol or layout entry for 0x02004600 as a function if one exists.
2. The 92 bytes at 0x02004600 become ordinary secure-area filler data (regenerated by `arm9data.py`
   from the new image, like Black's); check that White's filler array no longer starts a function there.
3. Replace `extract_white/` with `extract_white_retail/` (re-run the extract and delinked layout, then
   delete the stale `residue/0001.bin` and `residue/0002.bin`), and regenerate `build/white/layout`.
4. Update the expected SHA-1 in this page (lines about "SHA-1 0c43d714...") and in any tool or
   report that prints it; `romlink.py --version white` should then report IDENTICAL against bc696a0d...
5. Re-run `whitelink.py` / `gamelink.py arm9_main itcm --version white`, `white_diff.py` and the
   ARM9 verify; only the secure-area filler and the one crt0 word should move. ov010 stays open.
6. Delete the "not retail" paragraph above once step 1 is done.

No change is needed to `ndsrom.py`, `delink.py`, the DSi handling or the overlay links.

## Retail build (2026-10-19)

`python tools/romlink.py --version white --relink` builds white.nds from src/game and the result
is byte-identical with the verified No-Intro dump (SHA-1 bc696a0dfb448c7b3a8a206f0f8214411a039208).
The secure-area patch branch of the earlier dump is gone from crt0.c; White's startup returns with
`bx lr` as Black's does.
