# Roadmap

Current state (2026-10-16): milestones 1, 2, 2.5 and 2.75 are done. In milestone
3 the ARM9 static image, ITCM, the DSi `twl` region and 181 of 243 regions link
byte-identical from C; game code is 100.00 percent fully linked and all code is
100.00 percent fully linked (3,390,676 of 3,390,676 bytes, the SDK side
included). The live figures are in `README.md`.

The remaining milestone 3 work is a split campaign, not a move list: the
`__FILE__` anchors prove 76 functions across 36 files that sit in a file other
than their own original, and 88 of the consolidated cases need a file that does
not exist yet (`S/INT13/split_list.tsv`, the wave 13 start list in
`LAUNCHQ.md`).

## Milestone 1: ROM extraction and rebuild (done)

`tools/ndsrom.py` reads a stock ROM, splits it into its constituent parts
(header, ARM9/ARM7 binaries, overlays, filesystem, banner, icon), and can
reassemble those parts into a byte-identical `.nds`. `verify` diffs a rebuilt
ROM against the original to confirm the round trip is lossless. This gives us
a working baseline to decompile against before any code is touched.

## Milestone 2: delink & disassemble (done)

Goal: turn the compressed, linked ARM9 binary + overlays into disassembly we
can read, reassemble byte-identically, and eventually replace piece by piece.

What was built, and where it landed:

1. **BLZ codec** (`tools/blz.py`). Decoder and encoder, with the container's
   footer semantics documented in `docs/NOTES.md`. The decoder is validated
   230 ways: the ARM9 image and all 229 compressed overlays decompress to
   exactly the size their tables declare. The encoder was finished after the
   milestone closed and now *matches*: see milestone 2.5 below.
2. **Autoload/overlay layout** (`tools/delink.py`, `layout/layout.json`). The
   SDK5 build info is parsed, including a second TWL build-info structure and
   16-byte autoload entries, and the tool fails loudly if the recovered
   regions do not tile the image exactly. There is no DTCM autoload block in
   this ROM; DTCM is set up by hand in startup code.
3. **ARM/Thumb disassembly** (`tools/disasm.py`). Mixed ARM/Thumb, recursive
   traversal from real entry points, literal pools reserved before anything
   can claim them, and every guessed function dry-run before it is committed.
   78.5% of ARM9 main and 73.0% of the overlays are classified as code; the
   rest is emitted as data words rather than guessed at.
4. **Reassembly** (`tools/build.py`). Every region assembles, links at its
   load address and compares byte for byte with the original: 242 of 242
   regions PASS (ARM9 main, the ITCM autoload, three data autoloads, 237
   overlays), the whole decompressed ARM9 image matches
   `extract/arm9_dec.bin`, and `ndsrom.py verify` still passes. The mismatch
   classes that had to be fixed in the emission, and the mechanisms that keep
   the encoding exact (`.syntax unified`, `.org` guards, `.inst` escapes, a
   15-address quirk list), are written up in the Reassembly section of
   `docs/NOTES.md`.
5. **Splitting into translation units** (`disasm.py arm9 --split`). ARM9 main
   becomes 30 ordered chunks of 146 to 180 functions under `asm/arm9/src/`,
   the ITCM autoload 3 chunks under `asm/arm9/src_itcm/`, described by the
   committed manifests `layout/units_arm9.json` and `layout/units_itcm.json`.
   Assembling and linking in manifest order reproduces the same bytes as the
   monolithic listing. Overlays are still single listings.

Carried into milestone 3:

- **Translation units for the overlays**, and a whole-program link so that
  cross-region calls become label references instead of raw encodings.

Output of this milestone: a disassembled, re-buildable source tree that
matches the original image byte-for-byte and is organized enough to start
decompiling incrementally.

## Milestone 2.5: matching BLZ recompression (done)

The item carried out of milestone 2. Until this was fixed, `ndsrom.py build`
still embedded the *original* compressed `arm9.bin` and overlays, so a change
to the assembly could not reach the ROM.

- `blz.py compress` reproduces the SDK compressor exactly: 230 of 230
  containers (`arm9.bin` and all 229 compressed overlays) byte-identical,
  footer fields and alignment padding included. The recovered search policy
  (greedy, no self-overlapping matches, nearest displacement wins ties) and
  the retreat fixpoint that picks the verbatim prefix are documented under
  "Matching BLZ compression" in `docs/NOTES.md`.
- `tools/build.py --pack` turns the reassembled regions into ROM-ready
  binaries (recompressed ARM9 plus all 237 overlay files) in `build/pack`.
- `tools/ndsrom.py build --override DIR` prefers those over the extracted
  originals. The result verifies at sha1
  `26ad0b9967aa279c4a266ee69f52b9b2332399a5`, with 238 files coming from the
  recompressed set, and still does so with the originals moved out of the
  tree entirely.

The chain is now closed end to end: edit `asm/`, assemble, link, recompress,
repack, and the ROM is byte-identical when nothing was changed.

## Milestone 2.75: variable-size repack (done)

The item carried out of the "Modified rebuild boots" experiment. Until this
was fixed, a recompressed container had to come out at exactly the length the
original ROM carried, so only changes inside the BLZ verbatim prefix could
ever reach a working ROM.

- `build.py --pack` lets a container change length and checks it against its
  ROM slot, that is its offset up to the next file, padding included. The
  ARM9 slot is 0x6FA00 at 0x4000 against 0x6F898 of content, so 360 bytes of
  slack; overlay slots give 0 to 0x1F4. Exceeding one is a loud failure that
  names the numbers.
- The ARM9 build info's `compressed_code_end` is recomputed to a fixpoint,
  because the field lives inside the image being compressed.
- `ndsrom.py build` updates the header's ARM9 size at 0x2C, the FAT entry of
  every resized overlay, the y9 `compressed_size` field, and the header CRC
  at 0x15E. The secure area CRC at 0x6C covers the encrypted secure area and
  is not recomputable from a decrypted dump; the DSi digest tables and the
  RSA signature stay stale, which an NTR boot does not care about.
- `ndsrom.py verify --structural` cross-checks the header and the tables
  against the actual layout, so a deliberately modified ROM gets a meaningful
  check instead of only a sha1 mismatch.
- Proven end to end: a 224-byte edit in the ARM9 and a 256-byte edit in ov172
  grow their containers by 228 and 260 bytes, the ROM builds at sha1
  `b101fcf0040a2f9d43a42e99b1c05188cb4239cb`, passes the structural check and
  boots to the same intro as the baseline; reverting restores
  `26ad0b9967aa279c4a266ee69f52b9b2332399a5`. Written up under "Variable-size
  repack" in `docs/NOTES.md`.

Carried forward: relocating the files that follow a region, which would buy
far more than a slot's padding but means rewriting every FAT entry and every
header offset.

## Milestone 3: incremental decompilation

Goal: replace disassembly with C, function by function, without ever
breaking the matching build.

Approach:

- Pick one function at a time, write a C equivalent, compile it with the
  project's toolchain, and diff the resulting machine code against the
  original disassembly.
- Only accept a function as "decompiled" once it produces identical (or
  intentionally, explicitly noted non-matching) code.
- Repeat across the ARM9 and all overlays until the whole build is C, with
  the final ROM still verified byte-identical to the original dump.

Done so far:

- The matching harness, `tools/match.py`, with relocation resolution under an
  attestation rule, plus the compiler calibration against four SDK functions.
  14 entries are EXACT: eight game functions, two whole translation units and
  the four calibration functions. See `docs/MATCHING.md`.
- **`src/` is wired into the shipping build.** `tools/build.py` compiles every
  manifest entry through `tools/csrc.py` and splices the
  result into the region image before verifying it, so the byte-identical ROM
  is built from the C wherever C exists. A regression fails the build with a
  `match.py`-style diff instead of falling back to the assembly, and `--no-c`
  builds pure assembly for debugging. 12 entries, 442 bytes, 242 of 242
  regions still PASS.

Carried forward:

- A real `mwld` link of the C objects together with the assembly objects,
  replacing the byte splice, so that C can define symbols the assembly refers
  to by name.
- Translation units for the overlays, and a whole-program link so that
  cross-region calls become label references instead of raw encodings.

## Planned: Pokémon White as a second build target

Pokémon White (gamecode IRAO) is a planned second target of this same source
tree, the way sibling versions are handled in other matching projects: one
tree, a version flag, per-version data. This is a standing constraint on
design decisions made today, before any White work starts:

- Nothing may hard-code the Black target where a second one could exist:
  extract paths, layout files, shard directories (`layout/matched/arm9/` will
  gain a per-target dimension), manifest schemas, and build entry points must
  stay parameterizable by target.
- Addresses in `symbols:` blocks, shards, and the worklist are addresses in
  the BLACK image. When White lands, entries gain per-version addresses and
  verdicts; do not treat an address as version-neutral in new schema fields.
- Version-specific behavior found while matching (a constant, a table, a
  branch that smells like a version flag) should be noted in the source file
  header when spotted, not silently folded in.
- Expected payoff: most units verify byte-identical against White, and the
  White binary becomes a second witness pool for attestation, likely closing
  several single-caller near misses.
