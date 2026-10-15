# Technical notes

Function-level matching (compiling C and comparing it with the original
bytes) is written up separately in `docs/MATCHING.md`. Compiler traps that
keep recurring are collected in `docs/COMPILER_NOTES.md`. `src/` *is* part of
the build described below: `tools/build.py` compiles every entry of
every `layout/matched/` shard and splices the result into the region image before
verifying it, so the byte-identical ROM is built from the C wherever C
exists and from `asm/` everywhere else. `--no-c` builds pure assembly.


Findings recorded during ROM analysis, for contributors picking up later
milestones.

## General

- The game is built on SDK5 / TWL (DSi-enhanced), not an older NitroSDK
  version.
- Secure area in No-Intro dumps of this title is already decrypted (the
  `E7FFDEFF` marker is present at ROM offset 0x4000). No ARM7 BIOS is needed
  to work with this dump.

## ARM9 binary

- ROM offset: 0x4000
- Size (as stored/compressed on ROM): 0x6F898
- Load address: 0x2004000
- Entry point: 0x2004800
- Compressed with BLZ.
- Build info structure lives at `arm9 + 0xFB0`.

## Build info (from ROM)

- `autoload_infos`: 0x20AA780..0x20AA7C0 (4 entries, 16 bytes each). SDK5
  uses 16-byte autoload entries; earlier (pre-SDK5) NitroSDK builds use a
  12-byte layout, so tooling that assumes the old size will misparse this.
- Autoload blocks start at: 0x20A9E80
- `.bss` range: 0x20A9E80..0x21542C0
- Compressed code end: 0x2073898
- `sdk_version` field: 0x503757C

## Nitrocode footer

There is no nitrocode footer after the ARM9 binary in this ROM; the bytes
where one would normally sit are 0xFF padding. Instead, the build-info offset
is read from the ROM header at offset 0x88 (value: 0xFB0, ARM9-relative).

This is why third-party tools that assume a footer is always present (e.g.
current versions of ds-rom, dsd) fail to parse this ROM's build info
correctly, and why this project uses its own tooling instead.

# Milestone 2 tooling

Three new tools, all stdlib-only except for the Capstone pip package, which
`disasm.py` uses purely as a generic ARM/Thumb instruction decoder.

| tool | what it does |
| --- | --- |
| `tools/blz.py` | BLZ (backwards LZ77) decoder and encoder, library plus CLI |
| `tools/delink.py` | decompresses ARM9 and overlays, writes `layout/layout.json` and `layout/layout.txt` |
| `tools/disasm.py` | emits GNU as listings under `asm/` |

Reproduce everything from a clean checkout with an extracted ROM:

```
pip install capstone
python tools/ndsrom.py extract "Pokemon - Black Version (USA, Europe) (NDSi Enhanced).nds"
python tools/delink.py
python tools/disasm.py arm9
python tools/disasm.py overlay 0 1 21
python tools/disasm.py overlay --all-overlays
```

`layout/` is committed (addresses, sizes and names only). `asm/` and
`extract/` are not: they are derived from copyrighted game code.

## BLZ footer semantics

A BLZ container carries its metadata at the very end. Reading backwards from
the last byte of the container:

```
  [-4:]    u32  inc_len   how much LONGER the decompressed image is
  [-8:-4]  u32  (hdr_len << 24) | enc_len
```

* `inc_len == 0` means the container is stored uncompressed. Nothing else is
  parsed in that case.
* `enc_len` is the low 24 bits. It is the length of the encoded region
  measured backwards from the end of the container, and it *includes* the
  alignment padding and the 8 footer bytes.
* `hdr_len` is the top byte: the size of the trailer that is not part of the
  compressed byte stream, i.e. padding plus the 8 footer bytes. Legal values
  are 0x08..0x0B.

Derived:

```
  dec_len = len(container) - enc_len      verbatim prefix, never encoded
  pak_len = enc_len - hdr_len             compressed byte stream length
  raw_len = dec_len + enc_len + inc_len   decompressed image size
```

The compressed stream is an ordinary LZ77 stream over the *reversed*
plaintext that has itself been reversed, so it decodes back-to-front. Flag
bytes carry 8 tokens, most significant bit first. A clear bit is one literal
byte; a set bit is a big-endian u16 token with `len = (token >> 12) + 3` and
`disp = (token & 0x0FFF) + 3`, copying from `disp` bytes further along
towards the end of the image. Back references can reach into the verbatim
prefix, so the whole image has to live in one buffer while decoding.

This is not reverse-engineered from another decompilation: the game carries
its own decompressor at `0x02004DF4` (`MIi_UncompressBackward` in SDK terms)
and it confirms every field. It does `ldmdb r0, {r1, r2}` on the container
end to fetch the two footer words, `add r2, r0, r2` to get the output end
from `inc_len`, `sub r3, r0, r1, lsr #24` to place the read pointer using
`hdr_len`, and `bic r1, r1, #0xff000000; sub r1, r0, r1` to find the start of
the encoded region from `enc_len`. The match decoder adds 2 to the
displacement field and then indexes from the pre-decrement write pointer,
which is the `+3` above, and derives the length from the token's high byte
with `add ip, ip, #0x20` / `subs ip, ip, #0x10`, which is `(token >> 12) + 3`
iterations.

ARM9 specifics: the secure area (the first 0x4000 bytes) is not special-cased
anywhere. It simply falls inside the verbatim prefix, which is 0x400F bytes
here. `python tools/blz.py decompress extract/arm9.bin --start 0x4000` and
the same command without `--start` therefore produce byte-identical output;
`--start` is an assertion about where the encoded region may begin, not a
different decode.

Measured on this ROM:

```
  arm9.bin   0x6F898 stored -> 0xA67C0 decompressed
             hdr_len 0x0A, enc_len 0x6B889, inc_len 0x36F28, dec_len 0x400F
```

Validation performed: the decompressed image loaded at 0x02004000 ends at
exactly 0x020AA7C0, which equals `autoload_infos_end` from the build info,
and the four 16-byte autoload entries in it are internally consistent (their
payloads tile the block area exactly from `autoload_blocks` up to
`autoload_infos_start`). `delink.py` fails loudly if any of that does not
hold. Separately, all 229 compressed overlays decompress to exactly the size
their overlay table entry declares, which is 229 independent end-to-end
checks of the decoder.

`blz.py compress` reproduces the SDK's own output byte for byte, footer
included, for all 230 compressed containers in this ROM. How that was
recovered is written up under "Matching BLZ compression" below.

## Autoload table: the 4th field

SDK5 autoload info entries are 16 bytes:

```
  +0x00  u32  ram_address        where the block is copied to
  +0x04  u32  code_size          bytes copied from the packed payload area
  +0x08  u32  static_init_start  pointer to a NULL terminated array of
                                 static initialiser function pointers
  +0x0C  u32  bss_size           bytes zeroed right after the block
```

The field at `+0x08` is neither a CRC nor an init callback pointer. The
autoload walker at `0x02004BB4` reads the entry with four post-indexed
`ldr rN, [ip], #4`, and:

* passes field 0 and field 1 to the block copy at `0x02004ED4` as destination
  and length;
* passes field 2 to the helper at `0x02004D50`, which returns immediately if
  it is zero and otherwise walks the pointed-at array until it reads a zero
  word, appending those words to a global constructor list kept just below
  the DTCM stacks. That makes it a `static_init_start` pointer;
* passes field 3 to the memset at `0x02004F20` together with the end of the
  copy, which makes it `bss_size`.

In this build every block's `static_init_start` happens to equal its own base
address, i.e. each block begins with its (possibly empty, i.e.
zero-terminated immediately) constructor array.

## Autoload entries found

```
  #  kind       ram          code    bss     static_init  src offset in arm9
  0  ITCM       0x01FF8000   0x0820  0x0000  0x01FF8000   0x0A5E80
  1  MAIN_TWL   0x02FE0000   0x00A0  0x0020  0x02FE0000   0x0A66A0
  2  MAIN_TWL   0x02400000   0x0020  0x0000  0x02400000   0x0A6740
  3  VRAM_LCDC  0x06898000   0x0020  0x0000  0x06898000   0x0A6760
```

Surprises here:

* There is **no DTCM autoload block**. DTCM is set up by hand in the startup
  code (`0x020048E4` onwards loads the DTCM base, adds 0x4000 and carves the
  SVC / IRQ / user stacks out of the top) rather than through an autoload
  entry. Tooling that expects an ITCM+DTCM pair will be confused by this ROM.
* Blocks 1..3 land in DSi-only memory (0x02400000 is the start of the DSi
  extended main RAM, 0x02FE0000 is near its top) and in VRAM bank H at
  0x06898000. Loading an autoload block straight into LCDC VRAM is unusual.
  All three are pure data: `disasm.py` classifies 0 bytes of them as code.
* `main`, the static module, covers 0x02004000..0x020A9E80. Its `.bss`
  (0x020A9E80..0x021542C0) starts at the same address as the packed autoload
  payload area, which is normal: the payloads are consumed at boot and then
  overwritten by bss.

## Second (TWL) build info structure

There are **two** build-info structures in the ARM9, not one. The NTR one is
at `arm9 + 0xFB0` as previously documented (9 words, nitrocode 0xDEC00621 /
0x2106C0DE). A shorter TWL one sits just before it at `arm9 + 0xF7C`, six
words, nitrocode 0xDEC01463 / 0x6314C0DE:

```
  +0x00  autoload_infos_start   0x02432DA4
  +0x04  autoload_infos_end     0x02432DB4   (a single 16-byte entry)
  +0x08  autoload_blocks        0x02400004
  +0x0C  compressed_code_end    0x02412F24
  +0x10  nitrocode              0xDEC01463
  +0x14  nitrocode_rev          0x6314C0DE
```

Those addresses are inside `arm9i.bin`, which loads at 0x02400000 and is
0x12F24 bytes long (0x02400000 + 0x12F24 = 0x02412F24, matching the field).
The startup code only walks this table when the DSi header copy in shared
WRAM at 0x02FFE1CC says the cart was booted in TWL mode, so it is recorded in
`layout.json` for documentation. The block it describes is region `twl`
(see "The TWL region" at the end of this file).

## Overlay compression flag

The last word of a 32-byte y9 entry is `compressed_size (24 bits) | flags (8
bits)`:

```
  bit 0 of the flag byte  compressed with the same backwards BLZ as the ARM9
  bit 1 of the flag byte  signed / authenticated
```

Observed on this ROM: 229 overlays have flags 0x03 (compressed and signed)
and 8 have flags 0x02 (signed, stored). No overlay has flags 0x00 or 0x01.
There is no separate forward LZ77 with a 0x10 header anywhere in the overlay
path; the same `MIi_UncompressBackward` routine handles all of them.

Semantics confirmed empirically:

* When bit 0 is set, `compressed_size` is non-zero and equals the overlay
  file's length in the FAT exactly, and the BLZ container occupies the whole
  file. Decompressing it yields exactly `code_size` bytes in every one of the
  229 cases.
* When bit 0 is clear, `compressed_size` is 0 and the file length equals
  `code_size`. The eight uncompressed overlays are ids 1, 2, 7, 37, 79, 80,
  95 and 228.

`delink.py` writes the decoded overlays to `extract/overlays_dec/` and never
modifies the originals in `extract/overlays/`.

## Disassembly coverage

`disasm.py` classifies a byte as code only if a chain of reasoning starting
at a known entry point reached it. Seeds are the ARM9 entry point, static
initialiser arrays, and call targets; literal pools are reserved as data
before anything can claim them; whatever is left is scanned for function
prologues (`stmfd sp!, {..., lr}`, `str lr, [sp, #-4]!`, Thumb
`push {..., lr}`) and each candidate is dry-run first, so a run is only
committed if every instruction decodes and it reaches an unconditional
return or merges into already-trusted code. Everything else is emitted as
`.word` data. Adding that dry-run validation raised ARM9 main coverage from
76.5% to 78.5% while *reducing* the function count from 5441 to 5366, which
is the expected signature of removing false positives.

```
  region                        size       code    code%   functions
  arm9 main                  0x0A5E80   0x08237E   78.5%      5366
  arm9 ITCM autoload         0x000820   0x0005AA   69.7%         9
  arm9 autoload 1/2/3        0x0000E0   0x000000    0.0%         0
  all 237 overlays           0x31B000   0x243F8A   73.0%         -
```

The 21.5% of ARM9 main that stays data is mostly genuine `.rodata` and
`.data`, plus 5009 literal pool words (about 0x4E44 bytes), plus the roughly
0x800 bytes of random filler at the head of the secure area. Jump tables are
a deliberate second source: Thumb `add pc, rN` dispatch tables stop the trace
and the table itself is left as data words rather than guessed at, which is
visible in for example `asm/overlays/ov000.s` at 0x021542E4.

Two things worth knowing about the output:

* Real code does live in the secure area filler. `func_0200421A` is a
  two-instruction `svc #0xb; bx lr` thunk reached by a `blx` from
  0x02090F30, surrounded by random bytes. It is found through the call graph,
  not by sweeping.
* Branch operands and PC-relative loads are rewritten to reference
  `func_`/`loc_`/`pool_` labels, so the listing says what the code means.
  Where an instruction cannot be spelled in a way GNU as re-encodes
  identically, the raw encoding is emitted instead; see the Reassembly
  section below.

# Reassembly

Every region of the game's ARM9 side now assembles back to the exact original
bytes. `tools/build.py` is the driver: it assembles the `asm/` listings, links
them at the region's load address, flattens the result and compares it with
the authoritative original bytes (the matching slice of `extract/arm9_dec.bin`
for ARM9 regions, the `extract/overlays_dec/` file or the stored overlay file
for overlays).

## Toolchain

GNU binutils 2.43.1 for `arm-none-eabi`, taken from the xPack
`arm-none-eabi-gcc` 14.2.1-1.1 zip and unpacked, not installed;
`arm-none-eabi-as`, `-ld` and `-objcopy` are used. All discovery lives in
`tools/env.py`: the ARM `bin/` directory is `--toolchain`, then
`BW_ARM_TOOLCHAIN`, then `tools/gcc-arm/bin` or `tools/gcc-arm/*/bin`, then
`PATH` (a candidate counts only if it holds `arm-none-eabi-as`), so a distro
binutils works just as well. The CodeWarrior compilers live under
`tools/mwccarm/mwccarm/dsi/<version>/`; `python tools/env.py` prints what was
resolved and `python tools/selfcheck.py` exercises one compile and one split
build.

Per platform, only the downloads differ:

* Windows: the xPack `arm-none-eabi-gcc` win32-x64 zip into `tools/gcc-arm/`;
  `mwccarm.exe` runs directly. The eidos host toolchain is the xPack
  `mingw-w64-gcc` zip in `tools/gcc-host/`, CMake in `tools/cmake/` and Ninja
  in `tools/ninja/`.
* macOS: the xPack `arm-none-eabi-gcc` darwin zip into `tools/gcc-arm/`, and
  wine (`brew install --cask wine-stable`); the tools prefix every `.exe`
  with `wine64`, else `wine`, found on `PATH`, and stop with a clear error if
  neither exists. For eidos, CMake and Ninja in `tools/cmake/` and
  `tools/ninja/` or on `PATH`, with the system clang.
* Linux: the xPack `arm-none-eabi-gcc` linux zip into `tools/gcc-arm/` and
  the distribution's wine package, used the same way as on macOS. For eidos,
  CMake and Ninja in `tools/cmake/` and `tools/ninja/` or on `PATH`, with the
  system gcc.

Nothing else is platform-specific: the tools locate the repo from their own
path, start child tools with the running interpreter, and put scratch files
in `ALETHEIA_SCRATCH` (default: the system temp directory plus `aletheia`).

Flags that matter:

* `as -mcpu=arm946e-s -EL -W`. The CPU choice is not cosmetic: it restricts
  the assembler to ARMv5TE, which is what the hardware is, and makes it
  reject the Thumb-2 instructions Capstone occasionally decodes out of data
  (see "quirk list" below).
* `.syntax unified` at the top of every listing. Without it GNU as reads the
  divided dialect and rejects most of what Capstone prints, for example
  `adds r4, r1, #0` or `strhne`.
* `ld --use-blx`, and `.ARM.attributes` deliberately *not* discarded by the
  linker script. `ld` decides whether an ARM-to-Thumb call may use a BLX
  immediate from the architecture profile in that section; with the section
  discarded it assumes a pre-v5 target, appends an interworking veneer and
  rewrites the call to reach it. That showed up as a 16-byte-longer ITCM
  block with one wrong instruction, and was the only size mismatch the whole
  exercise produced.

## Keeping the encoding exact

Three mechanisms in `disasm.py`, in order of how much they carry:

1. **`.org` guards.** Every label and every data run is preceded by
   `.org <offset-within-the-region>`. If an instruction assembles to a
   different size, the assembler says so at that exact spot instead of
   silently shifting every following byte, which is what makes a
   first-difference report from a 0xA5E80-byte region actionable at all.
2. **A raw-encoding escape hatch.** Anything that cannot be spelled exactly
   is emitted as `.inst` / `.inst.n` / `.inst.w` with the decode kept in the
   trailing comment. `.inst` rather than `.word` so the assembler still
   treats it as code and the mapping symbols stay right.
3. **A committed quirk list**, `layout/reasm_quirks.json`: addresses only, no
   game bytes. `build.py --write-quirks` fills it in from a real
   assemble-and-compare run, mapping either a differing byte or an assembler
   diagnostic back to the instruction that caused it via the
   `/* ADDRESS  XX XX XX XX */` annotation every code line carries.
   `disasm.py` then emits those addresses raw on the next run. 15 addresses
   in total across 681920 + 3256320 bytes of image.

## Mismatch classes that had to be fixed

Each of these was found by assembling, diffing and mapping the difference
back to a source line, then fixing the emission in `disasm.py` and
regenerating. None of the `asm/` output was hand-edited.

| class | why the bytes differed | fix |
| --- | --- | --- |
| divided vs unified syntax | GNU as defaults to the divided dialect and rejects `adds rX, rY, #0`, `eors`, `strhne`, ... | emit `.syntax unified` |
| ARM modified immediates | the assembler always picks the smallest rotation, so an instruction encoded with a larger one comes back different even though the disassembly is right | `_arm_imm_is_canonical` re-derives the rotation the assembler would choose and forces `.inst` when it differs |
| Thumb `add`/`sub` imm3 with `Rd == Rn` | written out, `adds r2, r2, #1` reads as the imm8 form (T2), so the original imm3 (T1) encoding is unspellable | detected from the encoding (`0x1C00` mask), emitted raw; by far the largest class |
| Thumb high-register `add rX, rY` with two low registers | the assembler reads a flag-setting ADD and only Thumb-2 has the 32-bit non-flag-setting form, so it refuses outright | detected from the encoding (`0x4400` mask), emitted raw |
| Thumb `add rX, sp, rX` | same shape, `Rm == SP`; the assembler reaches for a 32-bit encoding that does not exist here | detected from the encoding, emitted raw |
| Thumb `mov rX, rY` with two low registers | on Thumb-1 that spelling means `lsls`, so the high-register MOV cannot be written | detected from the encoding (`0x4600` mask), emitted raw |
| branches with no label | a call or branch leaving the region (ITCM calling into main, for instance) or landing on bytes not classified as code has nothing to be spelled relative to | emitted raw |
| ARM-to-Thumb `blx` | `ld` inserted a veneer, see the toolchain notes | `--use-blx` plus keeping `.ARM.attributes` |
| non-v5TE decodes | Capstone decodes ARMv7 by default, so a handful of data or jump-table bytes came out as `cbnz`, `cpsid`, `movw`/`movt`, `ldrh.w`, `smlabt r5, sl, r0, pc`, `ldm pc, {...}^` | the assembler rejects them for `arm946e-s`; `build.py` maps the diagnostic back to an address and they land in the quirk list (15 addresses) |

How much ends up as a raw encoding, counted over the final listings:

```
  class                          arm9 main + itcm   237 overlays
  branch leaving the region                   217          67317
  Thumb add/sub imm3, Rd == Rn                829           8328
  ARM non-canonical immediate                   0             54
  Thumb high-reg add / mov, low regs            2             15
  quirk list (non-v5TE decodes)                  3             12
  unresolved pc-relative operand                 0              1
  ------------------------------------------------------------
  total .inst directives                      1051          75727
```

The overlay figure is dominated by one thing: an overlay calls into the ARM9
static module constantly, and a call leaving the region has no label in that
region to be spelled against. That is a consequence of verifying each region
standalone, not a disassembly problem; the listing still shows the resolved
target in the comment. Linking all regions together in one pass would turn
most of those back into ordinary `bl func_...` lines, and is the natural next
step once overlays get translation units of their own.

## Translation units

`python tools/disasm.py arm9 --split` additionally writes ordered chunks and a
committed manifest, alongside the monolithic listing:

```
  region      units  files                  manifest
  arm9_main      30  asm/arm9/src/          layout/units_arm9.json
  arm9_itcm       3  asm/arm9/src_itcm/     layout/units_itcm.json
```

Files are named `<index>_<base address>.s`. ARM9 main units hold 146 to 180
functions each (5366 total). A cut is made at a block boundary once the unit
has collected enough functions, or earlier at a run of data of 0x800 bytes or
more, which is the closest thing to an original object-file boundary a
stripped image offers. Two constraints on where a cut may fall, both learned
the hard way:

* it must be 4-byte aligned, because a Thumb literal load rounds PC down to a
  word boundary and the assembler can only get that right if the unit's own
  base is aligned. Unaligned unit starts produced a flood of
  `invalid offset, target not word aligned`;
* it must not separate a PC-relative load from the pool word it reads.
  `disasm.py` computes those spans and refuses to cut inside one, so no
  literal load ever becomes a cross-object relocation.

Within a unit, `.org` offsets are relative to the unit's own base, so each
file assembles standalone. `func_`/`loc_` labels are global and cross-unit
branches become ordinary relocations the linker resolves; `pool_` labels stay
local by construction. The manifests carry file order, base addresses, sizes
and function counts only, no game bytes.

## Verification matrix

```
  region                     base         size      monolithic   from TUs
  arm9 main                  0x02004000   0x0A5E80  PASS         PASS (30)
  arm9 ITCM autoload         0x01FF8000   0x000820  PASS         PASS (3)
  arm9 autoload 1 MAIN_TWL   0x02FE0000   0x0000A0  PASS         n/a
  arm9 autoload 2 MAIN_TWL   0x02400000   0x000020  PASS         n/a
  arm9 autoload 3 VRAM_LCDC  0x06898000   0x000020  PASS         n/a
  overlays 0..236 (237)      various      0x31B000  PASS (237)   n/a
  ---------------------------------------------------------------------
  whole decompressed ARM9 image vs extract/arm9_dec.bin           PASS
  ROM rebuild + verify                                            PASS
```

242 of 242 regions are byte-identical, by both the monolithic and the
translation-unit path. The whole-image check reassembles the static module and
all four autoload payloads back into their packed positions and compares with
`extract/arm9_dec.bin`; the last 0x40 bytes of that image are the autoload
info table, which is link-time data rather than disassembly and is taken from
the original.

## Reproduce

```
pip install capstone
# unpack the xpack arm-none-eabi-gcc zip for this host into tools/gcc-arm/
python tools/ndsrom.py extract "Pokemon - Black Version (USA, Europe) (NDSi Enhanced).nds"
python tools/delink.py
python tools/disasm.py arm9 --split
python tools/disasm.py overlay --all
python tools/build.py --arm9-image          # 242 regions, monolithic
python tools/build.py --split --only arm9   # ARM9 regions from their TUs
python tools/build.py --split --pack        # + matched C + recompress to build/pack
python tools/build.py --split --no-c        # the same, pure assembly
python tools/ndsrom.py build extract --override build/pack -o build/pokeblack.nds
python tools/ndsrom.py verify extract build/pokeblack.nds
python tools/ndsrom.py verify extract build/pokeblack.nds --structural
```

The C side on its own, without building a ROM:

```
python tools/csrc.py                        # what build.py would splice
```

The compressor can also be exercised on its own against the originals:

```
python tools/blz.py compress extract/arm9_dec.bin --arm9 --reference extract/arm9.bin
python tools/blz.py compress extract/overlays_dec/y9_0012.bin \
    --reference extract/overlays/y9_0012.bin
```

## Matching BLZ compression

`blz.py compress` now reproduces the SDK compressor's output exactly. All 230
compressed containers in this ROM (`arm9.bin` plus the 229 compressed
overlays) are byte-identical, footer fields and alignment padding included,
so the ROM can be rebuilt from reassembled source with no original compressed
binary embedded anywhere.

The oracle is the ROM itself: every original container is a known-correct
answer for a known input. `sdk/TwlSDK/tools/bin/compBLZ.exe` was run as a
*behavioural* reference to confirm the shape of the algorithm (its `-d` trace
prints the retreat loop described below); none of its code was used, and the
shipped implementation is the Python in `tools/blz.py`.

### Search policy

Decoding an original container back into its token stream and comparing that
token-by-token with candidate encoders isolates each decision. Four rules
account for every token in all 230 files, with zero divergences:

* **greedy**, one decision per position, evaluated over the *reversed*
  plaintext. No lazy matching: the encoder never gives up a match here to
  take a longer one at the next position.
* **matches may not overlap themselves**: `length <= displacement`. This was
  the first divergence found. At offset 21 of overlay 12 the plaintext admits
  a length-11 match at displacement 3; the original encodes length 5 at
  displacement 5 instead. Forbidding self-overlap, so that a candidate at
  displacement `d` can only be compared for `d` bytes, explains that and 443
  other positions in the same file. The run-length trick a normal LZ77 gets
  from `disp < len` is simply not used.
* **nearest wins ties**: among all matches of the maximal length, the
  *smallest* displacement is encoded. The opposite tie-break (farthest) costs
  443 tokens in overlay 12, 795 in overlay 11 and 477 in overlay 14, so the
  two policies are easy to tell apart.
* the usual field limits: lengths 3..18, displacements 3..0x1002.

Implementation note: written naively that is a 0x1000-wide scan per position.
`tokenize` instead grows the needle one byte at a time and uses
`bytes.rfind(needle, lo, i)`, which returns the last start position whose
whole needle still fits below `i`. That is precisely "nearest non-overlapping
occurrence", so the tie-break falls out of the primitive, and a position
costs `best_len` C-level scans rather than thousands of Python comparisons.

### Verbatim prefix, hdr_len and inc_len

The decompressor runs in place: both pointers walk backwards, the write
pointer starting `inc_len` bytes above the end of the container and the read
pointer `hdr_len` bytes below it. The write pointer must never drop below the
read pointer, or output would clobber input that has not been read yet.

Track the encoder's own counters at each token boundary, in decode order:
`produced` bytes of plaintext against `consumed` bytes of stream (flag bytes
included). Then

```
  D = produced - consumed
```

is exactly the gap between the two pointers at that moment, and at the final
boundary `D` equals `inc_len + hdr_len` identically, because

```
  raw_len = dec_len + enc_len + inc_len   and   enc_len = pak_len + hdr_len
```

So the encoded region is safe if and only if **no earlier boundary has a
larger `D` than the last one**. `D` is not monotone: a run of literals holds
it flat and loses one more byte per flag byte, so an incompressible stretch
at the *start* of the image (which is the *end* of the reversed plaintext)
drags the final value below an earlier peak.

The SDK does not search for the best safe split. It compresses everything,
and while the result is unsafe it retreats to the **first** boundary whose
`D` exceeds the current total and tries again. That is a fixpoint of

```
  at  <-  min { k <= at : D[k] > D[at] }
```

which is what `_split_point` computes. The result is safe but not optimal:
for overlay 12 the fixpoint sits at `D = 2290` while the global maximum
further along is 2294, so a smarter compressor could have left 20 fewer bytes
unencoded. Reproducing the suboptimality is the point.

`compBLZ.exe -d` prints exactly this loop for that file:

```
  1: source size = 10880  compressed = 8591
    !! Shrink back Compressed region to avoid overwriting.
    !! Expand non-compressed region = +89
  2: source size = 10791  compressed = 8501
```

Truncating never changes the tokens that survive it, because the search is
causal and the cut falls on a token boundary, so the whole fixpoint is
computed from a single compression pass. 122 of the 229 overlays need no
retreat at all, 107 need exactly one, and the ARM9 needs one.

Everything else follows:

```
  dec_len = start + (len(rev) - produced_at_split)
  pak_len = consumed_at_split
  hdr_len = 8 + (-(dec_len + pak_len) mod 4)      padding byte is 0xFF
  enc_len = pak_len + hdr_len
  inc_len = raw_len - (dec_len + enc_len)
```

The observed `hdr_len` distribution over the 229 overlays (102 / 33 / 54 / 40
for 0x08 / 0x09 / 0x0A / 0x0B) matches that formula exactly, which also pins
down that the file length, not the stream length, is what gets aligned to 4.

### Two details that only show up at the seams

* **Stale flag bits.** The SDK builds the whole stream and then cuts it
  short, so the flag byte of the group the cut lands in keeps the bits of the
  tokens that were dropped. Re-emitting only the surviving tokens produces a
  cleaner flag byte and a one-byte difference: overlay 13 wants `0x88` at
  file offset 76 where a clean re-emit gives `0x80`. The decoder stops on the
  output count and never looks at those bits, but they are part of the bytes
  we have to reproduce. 22 of the 229 overlays land mid-group and need this.
* **The ARM9 secure area.** `compress` takes `start` as a *minimum* verbatim
  prefix. For the ARM9 it must be `blz.ARM9_SECURE_AREA` (0x4000): the secure
  area is never encoded. Left at 0, the retreat fixpoint happily settles at
  `dec_len = 0xB3D` and produces a 2812-byte-smaller container that would be
  wrong. With the floor in place the fixpoint lands at 0x400F, which is the
  original's value, so the secure area never needed special casing beyond
  being a lower bound.

### Cost

Single-threaded CPython 3.11: the ARM9 (0xA67C0 bytes in, 0x6F898 out)
compresses in about 1.6 s, and all 229 overlays together in about 8 s.
`tools/build.py --pack` recompresses the ARM9 plus all 237 overlays in about
10 s, which is noise next to assembling 242 regions.

## Source to ROM in one chain

`tools/build.py --pack [DIR]` (default `build/pack`) rebuilds every region as
before, then writes ROM-ready binaries into `DIR`: `arm9.bin` compressed from
the rebuilt decompressed image with `start=0x4000`, and all 237 overlay
files, the 229 compressed ones through `blz.compress` and the 8 stored ones
verbatim.

"Rebuilds every region" now means assemble `asm/`, link, and then splice in
the bytes of every matched C source. That step is `tools/csrc.py`, which
compiles each manifest entry with mwccarm at the flags the
entry was verified under, places and relocates it at its real address through
`match.py`'s own resolver, and refuses anything that is not `EXACT` or that
still carries a relocation wildcard. 12 entries, 442 bytes, all inside
`arm9_main`. The build fails with a `match.py`-style diff rather than falling
back to the assembly; see "How C enters the build" in `docs/MATCHING.md` for
why the mechanism is a byte splice and what a real `mwld` link would change.

```
python tools/build.py --split --pack
    [*] C sources: 12 entr(ies), 0x1BA (442) byte(s) spliced from src/
    arm9_main   0x02004000   0x00A5E80   PASS [30 TUs] [12 C, 0x1BA bytes]
    242 PASS, 0 FAIL
```

`tools/ndsrom.py build --override DIR` then prefers any file present in `DIR`
over the extracted original, and reports how many it took. For the unmodified
tree that is 238 files and the result still verifies:

```
  238 file(s) taken from the override directory
  sha1 26ad0b9967aa279c4a266ee69f52b9b2332399a5
  PASS: rebuilt ROM is byte-identical to the original
```

That was also checked with `extract/arm9.bin` and `extract/overlays/` moved
out of the way entirely, so nothing can be silently falling back to an
original. There are now no embedded original binaries anywhere in the ARM9
side of the chain: assembly to ROM is closed.

# Modified rebuild boots

Everything above only proves the chain can reproduce the original bytes. A
byte-identical rebuild says nothing about whether a rebuild with *different*
bytes is still a working cartridge image: the ROM carries DSi digest tables
and an RSA signature over content we would be changing, and the ARM9 is BLZ
containers whose size is pinned by the ROM layout. This section records the
experiment that closed that gap.

## Emulator

melonDS 1.1, `melonDS-1.1-windows-x86_64.zip` from the upstream GitHub
releases, unpacked into `tools/melonds/` (gitignored). It is a single
43 MB exe with no installer and writes a portable `melonDS.toml` next to
itself. `melonDS.exe <rom>` direct-boots. The defaults it writes are exactly
what this test wants:

```
  [Emu]
  DirectBoot          = true
  ExternalBIOSEnable  = false     # use the built-in BIOS/firmware replacements
  ConsoleType         = 0         # 0 = DS (NTR), 1 = DSi (TWL)
```

So no DS BIOS or firmware dump is needed, and the cartridge is booted as an
NTR cartridge even though it is DSi-enhanced. `[Instance0.Gdb] Enabled = true`
turns on melonDS's GDB stub (ARM9 on port 3333, ARM7 on 3334), which is how
the RAM check below was done: connect, send a `0x03` interrupt, then an
`m<addr>,<len>` packet. That is a much sharper instrument than a screenshot
and does not need savestate-format knowledge.

## Baseline

`build/pokeblack.nds` (sha1 `26ad0b9967aa279c4a266ee69f52b9b2332399a5`, i.e.
the byte-identical rebuild) boots. melonDS reaches 60/60 fps, plays the
Game Freak / intro sequence and arrives at the Reshiram/Zekrom title art.
Screenshots are not committed (binary, and they are game art); the window
title alone, `[60/60] melonDS 1.1`, is already a useful signal because a
crashed or spinning ARM9 does not hold the frame limiter at 60.

## The change

A detour patched into the ARM9 startup path, in
`asm/arm9/src/000_02004000.s`. The stub body is placed in the random filler
that occupies the head of the secure area (`0x02004000..0x020047FC`), which
carries no labels and is referenced by nothing, and the entry path is
diverted into it by overwriting one instruction:

```
  ; stub, replacing 7 words of unreferenced secure-area filler
  bw_magic_stub:
      ldr  r0, bw_magic_value     /* 020047D0 */
      ldr  r1, bw_magic_addr      /* 020047D4 */
      str  r0, [r1]               /* 020047D8 */
      mov  r0, #0                 /* 020047DC   displaced from 0200480C */
      b    bw_magic_return        /* 020047E0 */
  bw_magic_value:
      .word 0xBDEC0DE5            /* 020047E4 */
  bw_magic_addr:
      .word 0x02003F00            /* 020047E8 */

  ; at the patch site, inside func_02004800
      b    bw_magic_stub          /* 0200480C, was: mov r0, #0 */
  bw_magic_return:
      ldr  r1, pool_020049AC      /* 02004810 */
```

Three things make this a safe victim. `0x0200480C` is reached after
`bl func_02004A14` at `0x02004808`, so the MPU and TCMs are already
configured and a store to main RAM is legal. `r0` is dead on entry to that
instruction (it is about to be overwritten with 0) and `r1` is dead as well
(it is loaded at `0x02004810`), so the stub needs no save/restore.
`0x02003F00` is in the 16 KB of main RAM below the ARM9 load address
(`0x02004000`), which this build never touches.

Note the constraint that shaped the choice of *where* to patch, and which no
longer applies. At the time, `build.py --pack` required the recompressed ARM9
container to be exactly `0x6F898` bytes, because that is the size the ROM
header and the layout reserve for it. A general code change will not land on
that size by luck. This patch did, and not by luck: it lives entirely inside
the BLZ **verbatim prefix**, the first `dec_len = 0x400F` bytes of the
decompressed image, which are stored uncompressed. Bytes `0x7D0..0x80F` are
in that prefix, so the compressed token stream was untouched and the
container came out the same length with the same footer.

Any change above `0x0200800E` moves the compressed size, and the chain then
needs the ARM9 slot size, the header `arm9 size` field and the build info
`compressed_code_end` recomputed together. That is what the next section
does, so the restriction is gone.

## Chain

```
python tools/build.py --split --pack
    241 PASS, 1 FAIL              # arm9_main FAILs on purpose: 32 bytes differ
    whole ARM9 image: FAIL        # same 32 bytes
    BLZ recompression: 238 file(s) -> build/pack
python tools/ndsrom.py build extract --override build/pack -o build/pokeblack_mod.nds
python tools/ndsrom.py verify extract build/pokeblack_mod.nds   # FAIL, expected
```

The `FAIL` lines are the point: the reassembly harness is comparing against
the original bytes, and the bytes deliberately differ. Nothing else in the
242 regions moved.

## Results

```
  artefact                         sha1                                        size
  original / baseline ROM          26ad0b9967aa279c4a266ee69f52b9b2332399a5    0x10000000
  modified ROM                     281f64d2ffd0a84ca281295b665aa7cefa31439a    0x10000000
  original arm9.bin container      b1d62c124b481f22040a36781ae3ed0f3c622379    0x6F898
  modified arm9.bin container      25732d707235cf9423f31890bad94b9926d6979e    0x6F898
```

The two ROMs differ in exactly 32 bytes, at ROM offsets
`0x000047D0..0x0000480F`, which is ARM9-container offsets `0x7D0..0x80F`.
Same container length, same footer, no other region touched.

The modified ROM boots. It reaches 60/60 fps and shows the same intro at the
same wall-clock offsets as the baseline: the white flash at 12 s and the
intro cutscene at 30 s are indistinguishable between the two runs.

And the store landed. Read out of the running emulator over the GDB stub,
eight seconds into the modified ROM:

```
  0x02003F00  BDEC0DE5 00000000 00000000 00000000    <- the magic
  0x020047D0  E59F000C E59F100C E5810000 E3A00000    <- the stub, in RAM
              EA00000A BDEC0DE5 02003F00 75497C85
  0x0200480C  EAFFFFEF E59F1194                      <- b -0x44, the detour
```

`EAFFFFEF` at `0x0200480C` branches to `0x020047D0`; `EA00000A` at
`0x020047E0` branches back to `0x02004810`. The decompressor ran over our
recompressed container, our code executed, and the value is sitting in main
RAM while the game plays. This is the first end-to-end demonstration that
the project can produce a *modified* working ROM, not just a copy.

## DSi digest tables and the TWL signature

The header fields on this cart:

```
  digest NTR region      offset 0x00004000   length 0x0BFD5C00
  digest TWL region      offset 0x0C403000   length 0x0005A400
  digest sector table    offset 0x0BFD9C00   length 0x003C0F00
  digest block table     offset 0x0C39AC00   length 0x0001E078
```

The tables are SHA1-HMAC, 20 bytes per entry. 0x3C0F00 / 20 = 196800 sector
entries and 0x1E078 / 20 = 6150 block entries, so the sector size is 0x400
and a block covers 32 sectors, which is the usual TWL shape. The digested
NTR region starts at the ARM9 container, so our 32 changed bytes at ROM
`0x47D0` sit in **sector 1 of block 0**, squarely inside the digest
coverage. Both that sector hash and its block hash are now stale, the block
table is in turn covered by the header, and the RSA signature in the header
area (`extract/header_ext.bin`, the region above our 0x1000 header snapshot)
no longer matches either. `ndsrom.py` replays all of that verbatim, so the
modified ROM ships digests and a signature that do not describe its content.

**None of it matters for an NTR-mode boot, confirmed empirically.** The
modified ROM boots and runs on melonDS with `ConsoleType = 0`. This is the
expected result and the reason is structural rather than emulator-specific:
the digest tables and the signature are only consulted by the DSi launcher
and the TWL cartridge path. An NTR boot reads the header, DMAs the ARM9 and
ARM7 binaries and jumps; there is no hash check anywhere in that path, and
the game's own startup code does not look at them either (nothing in the
reassembled ARM9 references the digest table addresses). The residue pass in
`ndsrom.py` preserving the stale tables byte for byte is therefore correct
behaviour for this workflow, not an oversight: it keeps the image exact for
the byte-identical case and is simply inert for the modified case.

What is *not* shown here: whether the modified ROM would boot in TWL mode.
That needs a DSi NAND and DSi BIOS images, which this project does not have
and will not carry, so it stays untested. A decomp that wants DSi-mode
output will have to recompute both hash tables and re-sign the header, and
re-signing is not possible without the private key. The practical conclusion
is that modified builds of this title are NTR-mode artefacts.

No anti-tamper behaviour was observed in the game itself: no checksum
mismatch screen, no boot stall, no difference from the baseline run.

## Restoring the tree

The change was reverted and the chain rerun, so the committed state still
produces the byte-identical ROM:

```
  242 regions              241 PASS + 1 PASS (arm9_main back to PASS)
  whole ARM9 image         PASS
  sha1 26ad0b9967aa279c4a266ee69f52b9b2332399a5
  PASS: rebuilt ROM is byte-identical to the original
```

# Variable-size repack

The experiment above had to be designed around a limitation: a recompressed
container had to come out at exactly the length the original ROM carried,
which meant only changes inside the BLZ verbatim prefix were possible. That
limitation is gone. A container may now come out any length that still fits
its slot, and the chain recomputes everything that describes it.

## The slots, and how much slack there really is

A file's slot is its ROM offset up to wherever the extracted layout puts the
next thing, another region or a residue blob. `ndsrom.slot_limits()` computes
that from `extract/manifest.json` and it is the single implementation both
tools use, so `build.py --pack` and `ndsrom.py build` cannot disagree about
what fits.

```
  file          offset     content    slot       padding to the next file
  arm9.bin      0x004000   0x06F898   0x06FA00   0x168 (360 bytes)
  y9_0172.bin   0x24F800   0x00CA74   0x00CC00   0x18C (396 bytes)
```

The ARM9's next neighbour is the overlay table `y9` at ROM `0x73A00`, not the
FNT: the ARM9 container ends at `0x73898` and 360 bytes of 0xFF padding
follow. Overlay slots are the same shape, each file padded up to the next
0x200 boundary, so overlay slack runs from 0 (ov015, whose file already ends
on the boundary) to 0x1F4. Exceeding a slot is a loud failure that names the
numbers rather than a corrupted image:

```
error: region 'arm9': 'arm9.bin' is 457596 (0x6FB7C) bytes but its ROM slot at
0x4000 holds only 457216 (0x6FA00) before the next file starts at 0x73A00.
The slot is 456856 bytes of content plus 360 of padding, so this needs 380
byte(s) more than exist. Moving the files that follow is not implemented.
```

Moving the files that follow would buy far more room (the NTR area ends at
`0xC3B8E00` in a 0x10000000 image), but it means rewriting every FAT entry
and every offset in the header, and it invalidates the DSi digest tables in a
way the current slack-only approach does not. It is the obvious next step if
a region ever needs more than its padding.

## What has to be recomputed, and where each length is written down

A container's length is recorded in more than one place, and every one of them
has to move together or the ROM is inconsistent.

| field | where | who recomputes it |
| --- | --- | --- |
| ARM9 container length | ROM header 0x2C | `ndsrom.py build` |
| `compressed_code_end` | ARM9 build info, `arm9 + 0xFB0 + 0x14` | `build.py --pack` |
| overlay file extent | FAT entry for its file id, start and end | `ndsrom.py build` |
| overlay compressed size | y9 entry `+0x1C`, low 24 bits | `ndsrom.py build` |
| header CRC | ROM header 0x15E | `ndsrom.py build` |

`compressed_code_end` is the interesting one, because it is a fixpoint rather
than an assignment. It holds `load_address + compressed length`, and the
startup code hands that address to the in-place decompressor, so it has to be
right or nothing boots. But it lives at image offset 0xFC4, which is *inside*
the image being compressed. Being in the verbatim prefix means it is never
itself encoded, but it does not mean it is irrelevant: back-references from
the encoded region reach up to 0x1002 bytes into the prefix, so changing it
can move a token and therefore change the very length it records.
`pack_arm9()` iterates, compressing, writing the length the result implies
and compressing again, until the field the image carries is the one the
container wants. In the experiment below it converged on the second pass, and
that second pass is where 4 of the 228 bytes of growth came from. The loop
gives up loudly after 8 rounds rather than looping forever.

The header CRC at 0x15E is recomputed unconditionally. The formula is not
assumed: CRC-16 reflected, polynomial 0xA001, init 0xFFFF over
`header[0x000..0x15D]` reproduces the stored 0x8485 on this cart, and the same
routine reproduces the stored Nintendo logo CRC at 0x15C over
`header[0x0C0..0x15B]`. Recomputing it is a no-op for the byte-identical
build, which is how it is checked.

## The secure area CRC at 0x6C, and why it is not recomputed

GBATEK puts a secure area CRC-16 at header 0x6C, and this cart carries
0x8B9B. It is **not recomputable from this dump**, and nothing pretends
otherwise. The field covers the *encrypted* secure area as it exists on
cartridge; No-Intro dumps of this title carry a decrypted one (the
`E7FFDEFF` marker at ROM 0x4000). Measured, over the decrypted bytes:

```
  ROM[0x4000..0x8000]                       0x3DDE   (init 0xFFFF)
  the same with 'encryObj' at 0x4000        0xB4B0
  ROM[0x4000..0x4800]                       0xD474
  stored                                    0x8B9B
```

Reproducing it would need the KEY1 Blowfish tables from an ARM7 BIOS to
re-encrypt the first 2 KB, which this project does not carry. So the field is
left as it is and `verify --structural` reports it as a note rather than a
pass or a fail. This is the same class of residue as the DSi digest tables
and the RSA signature, which are likewise left stale for the reasons recorded
above: none of the three is consulted on an NTR boot.

## The proof

A deliberate size-changing edit in two places, both runs of zero data words
that become incompressible when filled with a deterministic pseudorandom
pattern:

```
  region      address                  words  bytes  what it is
  arm9_main   0x020A10FC..0x020A11DC     56    224   blank glyphs in the font
                                                     bitmap table at 0x020A1000
  ov172       0x021C4E88..0x021C4F88     64    256   zero padding inside ov172
```

Both are edits to the tracked `asm/` listings, both are above the verbatim
prefix so they land in the compressed token stream, and each grows its
container by about the number of bytes it makes incompressible. The chain:

```
python tools/build.py --split --pack
    240 PASS, 2 FAIL           # arm9_main 223 bytes, ov172 255 bytes, on purpose
    whole ARM9 image: FAIL     # same bytes
    arm9 slot: 0x6FA00 at 0x4000, original content 0x6F898, 0x168 of padding
    arm9 build info: compressed_code_end updated to match the new container
    arm9:   0x6F898 -> 0x6F97C (+228), slot 0x6FA00, 0x84 byte(s) of slack left
    ov172:  0x0CA74 -> 0x0CB78 (+260), slot 0x0CC00, 0x88 byte(s) of slack left
python tools/ndsrom.py build extract --override build/pack -o build/pokeblack_mod.nds
    2 container(s) changed size; updating the header and the tables
    header 0x2C arm9 size 0x6F898 -> 0x6F97C
    overlay 172: FAT end 0x25C274 -> 0x25C378, y9 compressed_size 51828 -> 52088
    header CRC 0x8485 -> 0x2C38
python tools/ndsrom.py verify extract build/pokeblack_mod.nds --structural
    PASS
```

Results:

```
  artefact                          sha1                                        size
  baseline (byte-identical)         26ad0b9967aa279c4a266ee69f52b9b2332399a5    0x10000000
  size-changed modified ROM         b101fcf0040a2f9d43a42e99b1c05188cb4239cb    0x10000000
  arm9.bin container, baseline                                                  0x6F898
  arm9.bin container, modified                                                  0x6F97C  (+228)
  y9_0172.bin, baseline                                                         0x0CA74
  y9_0172.bin, modified                                                         0x0CB78  (+260)
```

**It boots.** melonDS 1.1, `ConsoleType = 0`, direct boot: 60/60 fps
throughout, the white flash at 12 s and the intro cutscene at 36 s are
indistinguishable from the baseline run captured the same way. That is a
sharper result than it looks: a wrong `compressed_code_end` or a wrong header
0x2C would not produce a subtly wrong game, it would fail to decompress the
ARM9 at all and never reach the first frame.

What the boot does *not* cover is the overlay half. ov172 is not loaded
during the intro, so the evidence that its FAT entry and its y9
`compressed_size` were updated correctly is the structural check, which
cross-references both against each other and against the file's actual
extent, not the screen.

The edit was then reverted and the chain rerun:

```
  242 PASS, 0 FAIL
  whole ARM9 image: PASS
  sha1 26ad0b9967aa279c4a266ee69f52b9b2332399a5
  PASS: rebuilt ROM is byte-identical to the original
```

## Structural verification

`ndsrom.py verify --structural` is the check that still says something about a
ROM that is deliberately not byte-identical, where a sha1 comparison can only
say "different". It reads the built image and cross-checks every length and
offset against the thing it describes:

* the header CRC at 0x15E and the logo CRC at 0x15C, recomputed;
* the secure area CRC at 0x6C, reported as unrecomputable rather than passed;
* ARM9, ARM7, FNT, FAT, y9 and y7 all inside the image;
* the ARM9 build info's `compressed_code_end` against what header 0x2C
  implies, which is the two independent records of the container length
  agreeing;
* every FAT entry well formed, no two FAT files overlapping, and no FAT file
  colliding with the header area or any fixed region;
* every y9 and y7 entry against the FAT: a compressed overlay's
  `compressed_size` must equal its FAT extent, a stored one must have
  `compressed_size` zero and a FAT extent equal to its code size.

It passes on the baseline and on the size-changed ROM, and it is what would
have caught any of the five fields above being left stale.

## Library C in the denominator (2026-09-23)

MSL library C counts as game code in the exact and reproduced coverage figures, because no MSL archives exist on disk to give a pattern basis for excluding them. The runtime table (`layout/runtime_arm9.txt`) excludes only hand-written assembly, never MSL C.

## The TWL region (2026-09-24)

`arm9i.bin` (ROM 0x0C403000, 0x12F24 bytes, BLZ, 0x32DB4 decompressed at
0x02400000) ends in one autoload entry: image + 4, 0x32DA0 bytes, copied to
0x02700000 on TWL boot, 0x2DA0 of bss after it, static initialisers at
0x0272E9D4. `tools/delink.py` declares it in `layout.json` as region `twl`
(0x02700000..0x02732DA0; the bss is not part of the region). The declaration
is key-free: BLZ decodes from the end, so the table never depends on the
encrypted front.

The bytes are not. Header 0x1C bit 1 enables modcrypt, and area 1 (header
0x220/0x224) is ROM 0x0C403000 + 0x4000, the first 0x4000 bytes of arm9i;
undecrypted, they corrupt the payload up to about 0x02707090.
`tools/modcrypt.py` implements the decryption (AES-128-CTR, KeyX from
"Nintendo" and the game code, KeyY from the ARM9i HMAC at header 0x350,
counter from header 0x300, the key-scrambler step of the DSi AES engine). The
scrambler constant is read at run time from a file the user supplies
(`--dsi-key` / `ALETHEIA_DSI_KEY`: 16 bytes, little endian; `--dsi-bios` /
`ALETHEIA_DSI_BIOS`: a dump scanned for those 16 bytes) and checked against
its SHA-1; no file in the repo holds it, and `.gitignore` excludes `*.key`
and BIOS-like names. A 64 KB DSi ARM9 BIOS dump does not contain the
constant (it lives in the AES hardware; the dump was scanned in both byte
orders and all rotations), so only a key file works.

With a key, delink.py writes `extract/arm9i_dec.bin` only if the decrypted
BLZ stream is consumed to its last byte (all 229 compressed overlays are;
the undecrypted arm9i leaves 8172 bytes unread) and the clear tail is
unchanged. `disasm.py twl` then writes `asm/twl/twl.s` (seeds: the static
initialiser array and `function_starts.txt` rows for `twl`; then trace, pools
and prologue sweep; branches from the ARM9 image are not seeds), `build.py`
adds region `twl` (243 regions; `--only twl` alone; never in `--only arm9`,
`--arm9-image` or `--pack`) and needs its own `--write-quirks` rounds, and
`match.py` accepts a `twl` fourth token on `symbols:` lines (the overlay
`label` rule with one candidate). Without a key everything skips the region
and the build stays at 242 regions. The region is outside the ARM9
denominator. The plumbing was exercised end to end on the undecrypted
payload before a key was available.

Verified on plaintext with a user-supplied key file (the 16 bytes in the
order stored, little endian, i.e. reversed from the printed big-number
form, pass the SHA-1 check as they are). The decrypted BLZ stream is
consumed to its last byte (0x32DB4 bytes out), and the formerly corrupt
front now reads as ordinary ARM code: 168 of the listing's 305 functions
start below 0x02707090. `build.py --only twl` passes byte for byte on the
first round with no new quirks, and the full build is 243 of 243 PASS. The
ARM9 denominator is unchanged (400306 bytes).

func_0206DC00 stays MATCH. 0x027300F0 and 0x0272FEF4 are traced ARM
function starts in asm/twl/twl.s (push prologues, found by the prologue
sweep), so rules 1 and 2 of the `twl` label rule hold, but a raw scan of
the decrypted twl image, the ARM9 image and all 237 overlays finds no bl,
b, blx or pool word (ARM or Thumb) that targets either address other than
the two `bl` in func_0206DC00 itself (0x0206DCA4, 0x0206DD40), which lie
inside the compared range. Rule 3 has no witness in this ROM; the two
relocations stay wildcarded.

## Overlay 230's own decryptor (region `ov230d`, 2026-09-24)

Overlay 230 (y9 entry 230, 0x02187F00..0x021899A0) encrypts most of its own
code. Each of its five static initialisers is a three-instruction entry
thunk (`orr r0, pc, #0; adds r0, r0, #4; bne loc_02188A48`) whose argument
is the table right after it: (start + 0x1600, size + 0x021899A0 + 0x1600)
pairs, ended by a zero start word. The decryptor keeps branch words as
branches (B and BL swap, the offset field gains the pool constant
0xFFFFFA7E, i.e. moves by -0x582 words) and XORs every other word with a key rolled from the previous
plaintext and ciphertext; it then flushes the range and zeroes its own
thunk and table. 28 ranges come out: four tables of 0x24-byte ARM thunk
slots (the table at 0x02188414 names the six slots 0x021882A0 + n * 0x3C),
the dispatcher at 0x02188C60 with its two helpers, and seven more
functions. The dispatcher decrypts, calls and re-encrypts a second-layer
body at call time; that layer is not replayed.

`tools/ovcrypt.py` (stdlib) replays the decryptor on a copy of
`extract/overlays_dec/y9_0230.bin`. Its parameters (END, KEY, DELTA, the
bias) are read from the decryptor's own pool words and immediates after the
decryptor bytes pass a SHA-1 check, and each table address is computed from
its thunk's immediates. It refuses the whole overlay unless every range is
whole words inside ov230, disjoint from every other range, the decryptor,
the thunks and the tables, changed by decryption, and a clean ARM function:
a walk from its first word reaches every word, never leaves the range
(no fall-through or `b` into the next slot), and ends in an unconditional
return. `python tools/ovcrypt.py write` (also run by delink.py) writes the
derived view `extract/ov230d.bin`; `python tools/disasm.py ov230d` lists it
as `asm/ov230d/ov230d.s`, seeding every range start and refusing the listing
unless Capstone traces each range as one function of code. The ROM files,
`asm/overlays/ov230.s` and the ROM rebuild are unchanged: build.py never
reads the view. The replay agrees byte for byte with the independent
emulation lane H2 wrote.

`match.py` takes a fourth `symbols:` token `ov230d`, which follows the
`twl` design: it is required, and the plain `ov230` token keeps meaning
the ROM listing. A target resolves only at a checked range start that the
decrypted listing labels with the declared ISA, and only while
`extract/ov230d.bin` equals a fresh decryption. With an outside branch the
class is `label`; without one it is `sole-ref/code`: the label sits on
decrypted code the game runs, not on ciphertext. In the other direction a
`func_` label in ov230's ROM listing inside a decrypted range is a label on
ciphertext, and the overlay `label` and `sole-ref/code` rules refuse it.
func_02011D9C (ica_anime) BLXes slots 0, 3 and 4 right after it loads
ov230. With the token it is EXACT, 25 of 25 sites resolved.
