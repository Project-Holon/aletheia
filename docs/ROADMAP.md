# Roadmap

## Milestone 1: ROM extraction and rebuild (done)

`tools/ndsrom.py` reads a stock ROM, splits it into its constituent parts
(header, ARM9/ARM7 binaries, overlays, filesystem, banner, icon), and can
reassemble those parts into a byte-identical `.nds`. `verify` diffs a rebuilt
ROM against the original to confirm the round trip is lossless. This gives us
a working baseline to decompile against before any code is touched.

## Milestone 2: delink & disassemble

Goal: turn the compressed, linked ARM9 binary + overlays into disassembly we
can read and eventually replace piece by piece.

Planned approach:

1. **BLZ decompression**: the ARM9 binary is BLZ-compressed on the ROM; write
   a decompressor (and, later, a matching recompressor) so we can work with
   the expanded image and still rebuild a matching compressed blob.
2. **Autoload/overlay layout**: parse the SDK5-style build info (autoload
   info table, block table, bss range) embedded in the ARM9 image to recover
   where each autoload block (including the main NitroSDK static autoload)
   and overlay is expected to land in RAM. This is what lets us split one
   flat binary into separate, correctly-based regions instead of guessing.
3. **ARM/Thumb disassembly**: a disassembler covering the ARM9's mixed
   ARM/Thumb code, good enough to identify function boundaries, calls, and
   data references (literal pools, jump tables) without hand correction for
   the common cases.
4. **Splitting into translation units**: group disassembled functions/data
   into per-file chunks (by symbol boundaries and cross references) so the
   output can live as normal assembly files in a build tree, one step short
   of C.

Output of this milestone: a disassembled, re-buildable source tree that
still matches the original ROM byte-for-byte, but is organized enough to
start decompiling incrementally.

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
