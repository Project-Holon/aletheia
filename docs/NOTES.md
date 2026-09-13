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

`blz.py compress` exists and round-trips (`decompress(compress(x)) == x`,
checked by the CLI on every run), but it does not yet reproduce the SDK's
choice of verbatim prefix, which the SDK sizes so that the hardware's
*in place* decompression never lets the write pointer overtake the read
pointer. Do not use it to build a ROM that has to boot until that property
has been verified.

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
  Where Capstone renders an instruction in a form GNU as would re-encode
  differently (a modified immediate printed as `#imm, #rot`), the bytes are
  emitted as `.word` with the decode in a comment instead. On this ROM that
  case does not currently occur in any classified instruction. Reassembly has
  not been demonstrated yet.
