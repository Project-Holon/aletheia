# Technical notes

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
`layout.json` for documentation and otherwise ignored by the tooling.

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
`arm-none-eabi-gcc` 14.2.1-1.1 Windows x64 zip and unpacked, not installed,
`arm-none-eabi-as`, `-ld` and `-objcopy` are used. `build.py` finds a
toolchain via `--toolchain`, then `BW_ARM_TOOLCHAIN`, then any `bin/`
directory under `tools/gcc-arm/`, then `PATH`, so a distro binutils works
just as well. No compiler is involved yet.

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
# unpack the xpack arm-none-eabi-gcc win32-x64 zip into tools/gcc-arm/
python tools/ndsrom.py extract "Pokemon - Black Version (USA, Europe) (NDSi Enhanced).nds"
python tools/delink.py
python tools/disasm.py arm9 --split
python tools/disasm.py overlay --all
python tools/build.py --arm9-image          # 242 regions, monolithic
python tools/build.py --split --only arm9   # ARM9 regions from their TUs
python tools/build.py --pack                # + recompress into build/pack
python tools/ndsrom.py build extract --override build/pack -o build/pokeblack.nds
python tools/ndsrom.py verify extract build/pokeblack.nds
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

`tools/build.py --pack [DIR]` (default `build/pack`) reassembles every region
as before, then writes ROM-ready binaries into `DIR`: `arm9.bin` compressed
from the reassembled decompressed image with `start=0x4000`, and all 237
overlay files, the 229 compressed ones through `blz.compress` and the 8
stored ones verbatim. It fails loudly if a recompressed file does not fit its
ROM slot.

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
