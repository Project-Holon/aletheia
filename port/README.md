# port/ -- the native port

The declared end state of this project is an open-source native port of
Pokemon Black: one executable, cross-platform, moddable, with every asset
extracted from the player's own ROM the first time it runs. This directory is
the skeleton that proves the loop is real, end to end, on a small slice:
matched game C, compiled for the host, running over assets pulled out of the
ROM by `tools/assets/`, checked against expected values computed
independently.

Nothing here is a rewrite of the game. The only game code in the port is the
byte-verified C under `src/matched/`, compiled unchanged.

## Architecture

Three layers, and the boundary between them is the whole design.

**1. Matched translation units, compiled in place.** `port/CMakeLists.txt`
names files under `src/matched/` directly. The same files are compiled by
`tools/csrc.py` with mwccarm and spliced into the DS image, where they must
still produce the original bytes. There is no copy, no fork and no
port-specific variant: one file, two compilers, and a rule (below) about what
may be done to it.

**2. A shim standing where the SDK was**, under `port/sdk/`. On the DS the
game links against TwlSDK: `FS_ReadFile`, `OS_AllocFromHeap`, the `MI_Cpu*`
family and so on. `layout/symbols_sdk.txt` identifies those by address, which
is how the matched sources reach them (an `extern func_02078B70` *is*
`FS_ReadFile`). The shim is our own code, written against nothing but those
names and the matched call sites that use them. One file per SDK module:

| file | what it stands in for |
| --- | --- |
| `sdk/types.h` | the scalar vocabulary: u8..s64, fx32, BOOL, the fixed-point macros, endian-clean readers |
| `sdk/port.h` | the port's own API: data root, archives, panic |
| `sdk/fs.c` | FS: `FS_SeekFile`, `FS_ReadFile`, `FS_CloseFile` onto stdio |
| `sdk/os_alloc.c` | OS heap: `OS_AllocFromHeap`/`OS_FreeToHeap` and the game's debug-allocator wrappers `func_02030734`/`func_020307B0`, onto malloc |
| `sdk/mi.c` | MI: the `MI_CpuCopy*` / `MI_CpuFill*` family onto memcpy/memset |
| `sdk/narc.c` | the data root, the NARC container reader, and the ARM9 rodata window |
| `sdk/game_globals.c` | the ARM9 *objects* the matched code names (`g_Sink`, `g_0214652C`, `g_02146270`, `func_02019B04_Table`, the assert strings) |
| `sdk/aliases.c` | forwarders for addresses two matched files spell two different ways |
| `sdk/panic.c` | the one place the port gives up |

The SDK headers under `sdk/` at the repository root are reference for
declarations only. Nothing from them is copied here, and the port must stay
buildable by somebody who has their own ROM and nothing else.

**3. Stubs**, under `port/stubs/`, one symbol per file, in two shapes:

- `stub_ADDRESS.c` aborts naming the DS address. This is the honest shape for
  a game function that is not decompiled yet and whose behaviour is not
  attested anywhere. If a test reaches one, the test was wrong about its
  closure and says so loudly.
- `reimpl_ADDRESS.c` is a hand-written reimplementation whose header cites
  where the behaviour is attested: a matched caller, a `docs/notes/` entry, an
  asset tool that round-trips against it. Never a guess. These are *not*
  claimed to be byte-matching; when the real function is decompiled, the file
  is deleted and the matched source takes its place in the source list.

One symbol per file is load bearing: the port is a static archive, so a stub
is only pulled in when nothing else defines its symbol. That is what lets
`tests/test_stats.c` supply its own substitute for one function without
displacing any other.

**Assets** come from the player's own ROM. `tools/ndsrom.py extract` writes
`extract/`, and the port opens files under `extract/data` (the NitroFS tree)
and `extract/arm9_dec.bin` (for the constant tables that live in the ARM9
image rather than in a file). No game data is in this repository, and none is
produced by a build.

## Growing the source list

`port/CMakeLists.txt` carries a curated list of matched TUs. It is grown
mechanically, not by guessing:

```
python tools/port/closure.py --seed-func func_02018A7C
python tools/port/closure.py --seed-func func_02018A7C --cmake
python tools/port/closure.py --list-closed
```

`closure.py` reads the manifest shards in `layout/matched/` and the `extern`
declarations and `symbols:` header blocks of the matched sources, walks the
call graph through matched files only, and sorts every remaining reference
into one class:

- `matched` -- another matched source defines it; link that one too.
- `sdk` / `runtime` -- an SDK library symbol or an MSL runtime helper; it
  belongs in `port/sdk/`.
- `alias` -- a matched function referenced under a different name prefix than
  the file that defines it uses. The DS build resolves relocations by
  address and does not care; a host linker resolves by name and does. Each one
  needs a forwarder in `port/sdk/aliases.c`.
- `open` -- a game function at a known address that nothing in `src/matched/`
  defines yet; it needs a `port/stubs/` entry.
- `data` -- a global object; it needs a `port/sdk/game_globals.c` entry.

The point of the script is that the closure report and the linker always
agree. A name in the report that has no home is a link error waiting to
happen, and a link error that the report did not predict is a bug in the
script.

## Building

Requirements: CMake 3.16+, a C99 compiler (GCC, Clang or MSVC), Python 3.11+
for the fixture generator, and an `extract/` produced from your own ROM. The
standard library is the only dependency. SDL2 will be needed once there is
something to draw; this lane needs none of it.

```
python tools/ndsrom.py extract "<your-rom>.nds" -o extract
cmake -S port -B build/port -DBW_DATA_ROOT=extract/data
cmake --build build/port
ctest --test-dir build/port --output-on-failure
```

`BW_DATA_ROOT` is resolved against the repository root when it is relative.
The tests also accept the data root as `argv[1]` and fall back to the
`BW_DATA_ROOT` environment variable, so they can be run by hand.

If CMake is not available, `tools/port/hostbuild.py` builds the same source
lists (read straight out of `port/CMakeLists.txt`, so the two cannot drift)
with whatever compiler it can find:

```
python tools/port/hostbuild.py --probe    # report what is installed
python tools/port/hostbuild.py            # native build and run
python tools/port/hostbuild.py --check    # cross compile and link only
```

`--check` uses the `arm-none-eabi-gcc` already in `tools/gcc-arm/`. It proves
every source compiles clean and that the symbol closure is complete, because
the link fails on the first missing name. It cannot run the tests: what comes
out is an ARM ELF and there is no runner for it.

## Portability rules

These are not style preferences. Breaking any of them either breaks the DS
build or makes the port quietly compute different numbers.

**1. A matched file may not change without the DS re-verify in the same
commit.** If a matched source genuinely has to change to build on a host, the
change is only allowed together with, in the same commit:

```
python tools/build.py --split --pack
python tools/ndsrom.py build extract --override build/pack -o build/pokeblack.nds
python tools/ndsrom.py verify extract build/pokeblack.nds
```

and a PASS. The strong preference is not to touch `src/matched/` at all:
portability belongs in the port layer, as a shim, a wrapper include that
predeclares something before the matched file's own extern, or an alias
forwarder.

**2. 32-bit types are explicit.** The DS is LP32; the host may be LP64 or
LLP64. Port code uses `u8`/`u16`/`u32`/`s32` from `sdk/types.h`, which are
defined from `stdint`, never bare `int` or `long` for a value that has a
width in the game's data.

**3. Fixed point stays as it is.** `fx32` is 1.19.12 integer arithmetic, and
the game's numbers are decided by its truncation and rounding. Never convert
a fixed-point value through a float to "simplify" it; `FX_MUL` and `FX_DIV`
keep the 64-bit intermediate the DS runtime helper provides.

**4. Reads out of extracted files are endian-clean.** Every byte in
`extract/` is little-endian whatever the host is. Use `bw_rd16`/`bw_rd32`;
never cast a `const u8 *` into a `const u32 *` and dereference it, which is a
big-endian bug and an unaligned-access bug at once.

**5. No pointer may be stored in a struct the game's layout owns.** The
matched `struct ArcFile` is `u8 file[0x48]; u32 imageBase; u16 fatOffset;
u16 count;`, four-byte aligned. The FS shim owns those 0x48 bytes and stores
an *index* into a table of open `FILE *`, not the pointer, so the struct
neither grows nor needs eight-byte alignment on a 64-bit host. `sdk/fs.c`
asserts the size at compile time.

**6. `char` is signed.** `-char signed` is part of the pinned DS compiler
configuration; the CMake build passes `-fsigned-char` (`/J` on MSVC) so the
host agrees.

## What is substituted, and why

`tests/test_stats.c` runs the real `func_02018A7C`, the real archive chain and
the real nature table, but supplies its own `func_02017E1C` (get field by id),
`func_02017E40` (set field by id) and `func_02018598` (nature) over a flat
id-indexed array. All three are matched; their closure reaches the Pokemon
record's encryption layer (`func_02018D10` / `func_02018D6C`) and the two
large field dispatchers, and building a valid encrypted party record is a
milestone of its own. The interface `func_02018A7C` uses is exactly those
three functions, so the formula under test is untouched by the substitution.
The next milestone closes it.

## Known type mismatches

Two definitions in `sdk/game_globals.c` deliberately differ from the matched
file's own declaration. Both are findings about the matched code, not
conveniences, and both are recorded in that file's header:

- `g_02146270` is declared in `src/matched/unit_02019C54.c` with a 0x10-byte
  payload, but `src/matched/unit_0201ADA4.c` writes 0x3C bytes into it (the
  personal record's size). The declaration is an under-estimate that is
  harmless on the DS, where the object is a global with the rest of the
  record after it. The port defines it at the true size.
- `func_02019B04_Table` is declared `const` in
  `src/matched/unit_02019B04.c`. The port cannot define it const, because its
  contents are game data copied in at run time from the player's own
  `extract/arm9_dec.bin`. A definition whose qualifiers differ from another
  translation unit's declaration is outside what C99 guarantees; it links and
  behaves correctly on every toolchain this port targets, and the alternative
  is editing a matched file.

A third, not yet load bearing: some matched sources declare
`OS_AllocFromHeap` / `OS_FreeToHeap` with all-`u32` parameters, because on the
DS a pointer is a u32 and the matcher only needs the relocation. On an LP64
host such a declaration cannot carry a pointer. Neither function is in the
current closure; when a TU that declares them that way enters it, the fix is a
wrapper include in the port layer, never an edit to the matched file.
