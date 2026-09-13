# Roadmap

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

1. **BLZ decompression** (`tools/blz.py`). Decoder and encoder, with the
   container's footer semantics documented in `docs/NOTES.md`. The decoder is
   validated 230 ways: the ARM9 image and all 229 compressed overlays
   decompress to exactly the size their tables declare. The *encoder*
   round-trips but does not yet reproduce the SDK's choice of verbatim
   prefix, so a matching recompressor is still outstanding; see below.
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

- **Matching BLZ recompression.** The ROM `ndsrom.py build` produces still
  embeds the original compressed `arm9.bin`, so a change to the assembly does
  not yet reach the ROM. The decompressed image is proven byte-identical,
  which is exactly the compressor's input, so this is the one missing link in
  the chain and the first thing to fix.
- **Translation units for the overlays**, and a whole-program link so that
  cross-region calls become label references instead of raw encodings.

Output of this milestone: a disassembled, re-buildable source tree that
matches the original image byte-for-byte and is organized enough to start
decompiling incrementally.

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
