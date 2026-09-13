# SDK symbol recovery and toolchain validation

Two independent pieces of work are recorded here:

1. identifying which SDK library builds the game links, and recovering the
   original symbol names for the code that came out of them
   (`tools/libmatch.py`, output `layout/symbols_sdk.txt`);
2. checking that every TWL-line CodeWarrior compiler in
   `tools/mwccarm/mwccarm/dsi/` actually runs, compiles and links
   (`tools/cw.py`).

Neither depends on any other decompilation project. The archives are read
with a minimal `ar` reader and the objects with a minimal ELF32 reader, both
written for this repository; `libmatch.py` has no third-party dependencies at
all.

Nothing under `sdk/` or `vendor/` is committed. What lands in `layout/` is
addresses, symbol names and library file names.

# Part 1: library identification

## How the matching works

Every `.a` under `sdk/**/lib` (plus the loose `crt0*.o` objects that sit
beside them) is a Unix `ar` archive whose members are CodeWarrior-emitted
ELF32 little-endian ARM relocatables. Useful properties of that output:

* CodeWarrior emits one `PROGBITS` section per function, so a function's
  bytes are exactly its section, and `st_value` is 0 for most function
  symbols. Several sections in one object share the name `.text`, which
  rules out addressing sections by name.
* Relocations are `SHT_RELA` with 12-byte entries. Only two types appear in
  practice: `R_ARM_ABS32` (2) and `R_ARM_PC24` (1).
* ARM mapping symbols (`$a`, `$t`, `$d`) are present, so ARM and Thumb
  functions can be told apart without decoding anything.
* A `.comment` section carries the exact compiler build string.

For each `STT_FUNC` symbol with a non-zero size, `libmatch.py` takes the
section bytes covering the symbol and wildcards every byte the linker would
rewrite: four bytes for `R_ARM_ABS32`, the low three bytes of the word for
`R_ARM_PC24`, four bytes for the Thumb `BL` pair, four bytes for any
relocation type not in the table (conservative by construction). What remains
is a list of concrete byte runs.

Matching is a single pass over the game images. Patterns are indexed by their
concrete prefix, truncated to a multiple of four bytes up to sixteen; ARM
patterns are looked up at word-aligned positions and Thumb patterns at
halfword-aligned positions. A candidate is confirmed by comparing every
concrete run.

Three filters keep the output honest:

* a pattern shorter than 8 bytes, or with fewer than 12 concrete bytes, is
  not indexed at all;
* a pattern that matches in more than 8 distinct places is discarded as too
  generic;
* within each region, surviving candidates are accepted greedily longest
  first, and a candidate that overlaps an already accepted function is
  dropped. That is what removes the false positives where a 12-byte leaf
  function happens to reproduce the middle of a longer one. After this pass
  no two emitted symbols overlap.

A symbol is called corroborated if it is at least 24 bytes long, or if
another function from the same member object matched in the same region.
Symbols that are neither are written with a trailing `?`.

## Which library variant the game links

Each library ships as `.a`, `.thumb.a`, `.TWL.HYB.a`, `.TWL.HYB.thumb.a`,
`.TWL.LTD.a`, `.TWL.LTD.thumb.a`, in `Debug`, `Release` and `Rom` builds.
All eighteen combinations were indexed together and scored on the same scan,
so the comparison is direct. Matched versus indexable functions, all four
trees pooled:

| profile | matched | indexable | fraction |
| --- | --- | --- | --- |
| **Rom / TWL.HYB** | **4647** | 7517 | 61.8% |
| Rom / TWL.LTD | 4562 | 7490 | 60.9% |
| Rom / NTR | 4290 | 6777 | 63.3% |
| Release / TWL.HYB | 4069 | 7653 | 53.2% |
| Release / TWL.LTD | 4008 | 7624 | 52.6% |
| Release / NTR | 3804 | 6941 | 54.8% |
| Rom / TWL.HYB.thumb | 340 | 6569 | 5.2% |
| Rom / TWL.LTD.thumb | 337 | 6549 | 5.1% |
| Rom / NTR.thumb | 326 | 5924 | 5.5% |
| Release / TWL.HYB.thumb | 262 | 6724 | 3.9% |
| Debug / TWL.HYB | 234 | 8972 | 2.6% |
| Debug / TWL.HYB.thumb | 86 | 8264 | 1.0% |

Reading that table:

* **The game links the `Rom` build.** `Release` trails it by about 600
  functions and `Debug` is nowhere, at 2.6%. `Rom` is the SDK's `FINALROM`
  configuration. The libraries label themselves: CodeWarrior encodes the
  preprocessor configuration into an anonymous-enum DWARF type name, and the
  same object in the three builds of `libos.TWL.HYB.a` carries

  ```
    Rom      ..._CW_MAJOR_VER_3_FINALROM_LINK_ISTD_TS_TWL_TWLHYB_C_h
    Release  ..._CW_MAJOR_VER_3_LINK_ISTD_RELEASE_TS_TWL_TWLHYB_C_h
    Debug    ..._CW_MAJOR_VER_3_DEBUG_LINK_ISTD_TS_TWL_TWLHYB_C_h
  ```

  so the winning profile is independently confirmed to be the FINALROM one.
  The same strings start with `twl_h_16M_ARM9_CODE_ARM_...`, which is the
  library's own record that it was built for ARM9, ARM code, TWL hybrid.
* **The game links the ARM (non-Thumb) variants.** The `.thumb` libraries
  score 5% against 62%. The 5% is not noise: it is the handful of objects
  that are Thumb in both variants, so the same pattern is present in each.
* **The game links `TWL.HYB`.** `TWL.HYB` beats `TWL.LTD` by 85 functions
  and `NTR` by 357. NTR's higher *fraction* (63.3%) is an artifact: the NTR
  variant does not ship the TWL-only libraries at all, so its denominator is
  740 functions smaller.

  The decisive evidence is not the table, it is the startup object. All three
  `crt0` variants ship in `sdk/TwlSDK/lib/ARM9-TS/Rom/`, and ten of their
  eleven functions (`INITi_Copy32`, `INITi_Fill32`, and so on) are
  byte-identical across variants, so those cannot discriminate. `_start` can,
  and it differs in all three: 316 bytes in `crt0.o`, 512 in
  `crt0.HYB.TWL.o`, 528 in `crt0.LTD.TWL.o`. Only the HYB one matches the
  bytes at the ARM9 entry point 0x02004800. HYB is the hybrid NTR/TWL
  startup, which is what a DSi-enhanced cartridge needs, and it is what the
  game uses. (`crt0.HYB.TWL.o` therefore scores 11/11 and `crt0.LTD.TWL.o`
  10/11, the whole difference being `_start`.)

So: **Rom build, TWL.HYB variant, ARM instruction set.**

## Which compiler built the SDK libraries

The `.comment` sections give this away directly (`python tools/libmatch.py
comments --only Rom`):

| tree | build string | objects |
| --- | --- | --- |
| TwlSDK | Metrowerks C/C++ for ARM 4.0.0.1024 | 1563 |
| TwlDWC | Metrowerks C/C++ for ARM 4.0.0.1025 | 1368 |
| TwlDWC | Metrowerks C/C++ for ARM 4.0.0.1024 | 102 |
| TwlDWC | Metrowerks C/C++ for ARM 3.0.0.126 | 24 |
| TwlWiFi_base | Metrowerks C/C++ for ARM 4.0.0.1024 | 274 |
| TwlWiFi_base | Metrowerks C/C++ for ARM 3.0.0.139 | 12 |
| TwlWiFi | Metrowerks C/C++ for ARM 4.0.0.1024 | 6 |

Build 1024 is `tools/mwccarm/mwccarm/dsi/1.1p1`, which is present. Build 1025
is not in the collection: the nearest are 1024 (`1.1p1`) and 1026 (`1.2`).
The 3.0.0.x objects are prebuilt GameSpy blobs that Nintendo shipped as-is.

This tells us how the *libraries* were built. It does not yet tell us which
compiler built the game's own code; pinning that down needs per-function
match experiments, which is later work.

## Results

```
  regions scanned                 242 (ARM9 static, 4 autoload blocks, 237 overlays)
  bytes scanned               3938176
  archives indexed               1398
  unique function patterns      34618
  indexable patterns            31837
  symbols resolved               4426
  of those, corroborated         4376   (50 marked ? in the output)
  overlapping emitted symbols       0
```

Per SDK tree:

| tree | symbols |
| --- | --- |
| TwlDWC | 2715 |
| TwlSDK | 1261 |
| TwlWiFi_base | 341 |
| TwlWiFi | 109 |

`sdk/TwlWiFi/` holds only `libcps`, a newer copy of the library that also
exists under `sdk/TwlWiFi_base/TwlWiFi/`. The two are not byte-identical and
the `sdk/TwlWiFi/` copy scores better (112/134 against 108/134), so that is
the one the game links; the split in the table above is just an attribution
artifact. Counted together the WiFi stack contributes 450 symbols.

Where the symbols land:

| region | symbols |
| --- | --- |
| ov009 | 1472 |
| arm9 (static module) | 1268 |
| ov016 | 916 |
| ov114 | 388 |
| ov175 | 159 |
| ov107 | 87 |
| ov172 | 45 |
| ov015 | 17 |
| ov014 | 16 |
| ov093 | 11 |
| arm9 ITCM autoload | 10 |
| ov021 | 9 |
| 15 further overlays | 28 |

That distribution is itself a consistency check. The networking stack is not
spread across the ROM: it is concentrated in overlay 9 (DWC and GameSpy),
overlay 16, and overlay 114, with the OS, GX, FS, card and SPI parts of the
SDK in the always-resident ARM9 static module. 214 of the 4426 symbols are
Thumb.

Top libraries by matched function count (matched / indexable; the full table
is appended as comments to `layout/symbols_sdk.txt` and in
`layout/symbols_sdk.json`). 69 distinct `Rom/TWL.HYB` libraries contributed
at least one symbol.

| library | matched | of | fraction |
| --- | --- | --- | --- |
| `TwlDWC/lib/ARM9-TS/Rom/libdwcutil.TWL.HYB.a` | 848 | 905 | 93.7% |
| `TwlDWC/lib/ARM9-TS/Rom/libdwcmatch.TWL.HYB.a` | 307 | 358 | 85.8% |
| `TwlSDK/lib/ARM9-TS/Rom/libos.TWL.HYB.a` | 235 | 413 | 56.9% |
| `TwlDWC/lib/gamespy/ARM9-TS/Rom/libdwcgscommon.TWL.HYB.a` | 225 | 330 | 68.2% |
| `TwlDWC/lib/gamespy/ARM9-TS/Rom/libdwcgsgp.TWL.HYB.a` | 162 | 230 | 70.4% |
| `TwlSDK/lib/ARM9-TS/Rom/libgx.TWL.HYB.a` | 160 | 323 | 49.5% |
| `TwlWiFi_base/TwlWiFi/lib/ARM9-TS/Rom/libnhttp.TWL.HYB.a` | 151 | 184 | 82.1% |
| `TwlDWC/lib/ARM9-TS/Rom/libdwcac.TWL.HYB.a` | 136 | 150 | 90.7% |
| `TwlDWC/lib/gamespy/ARM9-TS/Rom/libdwcgsserverbrowsing.TWL.HYB.a` | 123 | 157 | 78.3% |
| `TwlDWC/lib/gamespy/ARM9-TS/Rom/libdwcgsgt2.TWL.HYB.a` | 121 | 168 | 72.0% |
| `TwlSDK/lib/ARM9-TS/Rom/libfs.TWL.HYB.a` | 115 | 190 | 60.5% |
| `TwlDWC/lib/ARM9-TS/Rom/libsoc.TWL.HYB.a` | 112 | 132 | 84.9% |
| `TwlWiFi/lib/ARM9-TS/Rom/libcps.TWL.HYB.a` | 112 | 134 | 83.6% |
| `TwlWiFi_base/TwlWiFi/lib/ARM9-TS/Rom/libssl.TWL.HYB.a` | 99 | 103 | 96.1% |
| `TwlDWC/lib/gamespy/ARM9-TS/Rom/libdwcgsghttp.TWL.HYB.a` | 94 | 121 | 77.7% |
| `TwlSDK/lib/ARM9-TS/Rom/libmb.TWL.HYB.a` | 92 | 204 | 45.1% |
| `TwlSDK/lib/ARM9-TS/Rom/libspi.TWL.HYB.a` | 82 | 110 | 74.6% |
| `TwlSDK/lib/ARM9-TS/Rom/libwm.TWL.HYB.a` | 76 | 99 | 76.8% |
| `TwlWiFi_base/TwlWiFi/lib/ARM9-TS/Rom/libwcm.TWL.HYB.a` | 76 | 92 | 82.6% |
| `TwlDWC/lib/ARM9-TS/Rom/libdwcauth.TWL.HYB.a` | 75 | 85 | 88.2% |

A fraction well above 90% (`libssl` at 96.1% of 103, `libdwcsc` at 94.6%,
`libdwcutil` at 93.7% of 905, `libnvram` at 21/21, `libdwcnas` at 7/7)
means the game links that exact
library build and almost every function in it. A middling fraction such as
`libos` at 56.9% is expected and not a warning sign: the library holds
functions the game never references, which are dropped at link time, plus
inline assembly functions with no relocations that fail the size filters.

## Anchors

`docs/NOTES.md` names five addresses in the startup path from first
principles. All five are recovered, with real SDK names, and they are
mutually consistent (all five come from the same two objects):

| address | NOTES.md description | recovered name | source |
| --- | --- | --- | --- |
| 0x02004BB4 | autoload walker | `INITi_DoAutoload` | `crt0.HYB.TWL.o` |
| 0x02004D50 | static initialiser collector | `INITi_ShelterStaticInitializer` | `crt0.HYB.TWL.o` |
| 0x02004DF4 | `MIi_UncompressBackward` | `MIi_UncompressBLZ` | `libmi.TWL.HYB.a(mi_secureuncompr)` |
| 0x02004ED4 | block copy | `INITi_Copy32` | `crt0.HYB.TWL.o` |
| 0x02004F20 | block clear | `INITi_Fill32` | `crt0.HYB.TWL.o` |

Member object names are stored in the `ar` header's 16-character field and
are truncated there by the archiver, so `mi_secureuncompr` above is
`mi_secureuncompress.o` with the tail cut off. `libmatch.py` reports what the
archive stores rather than guessing the rest.

Note on 0x02004DF4: NOTES.md called it `MIi_UncompressBackward`, which is the
NitroSDK name for that routine. In SDK5 / TwlSDK the same code is exported as
`MIi_UncompressBLZ` from `mi_secureuncompress.o`. The behaviour documented in
NOTES.md is unchanged; only the name is. The recovered name is the one the
library actually uses and is what the project should use going forward.

The surrounding startup code names came out of the same run and corroborate
each other:

```
  02004800  _start                          crt0.HYB.TWL.o
  02004A00  INITi_CpuClear32                crt0.HYB.TWL.o
  02004A14  INITi_InitCoprocessor           crt0.HYB.TWL.o
  02004A98  INITi_InitRegion                crt0.HYB.TWL.o
  02004BB4  INITi_DoAutoload                crt0.HYB.TWL.o
  02004D50  INITi_ShelterStaticInitializer  crt0.HYB.TWL.o
  02004DA0  INITi_CallStaticInitializers    crt0.HYB.TWL.o
  02004DF4  MIi_UncompressBLZ               libmi.TWL.HYB.a
  02004EB4  INITi_IsRunOnTwl                crt0.HYB.TWL.o
  02004ED4  INITi_Copy32                    crt0.HYB.TWL.o
  02004F20  INITi_Fill32                    crt0.HYB.TWL.o
```

`_start` at 0x02004800 is the ARM9 entry point recorded in `layout.json`, and
`INITi_IsRunOnTwl` at 0x02004EB4 is the routine NOTES.md describes as reading
the DSi header copy in shared WRAM to decide whether to walk the TWL autoload
table. Both were predicted by the earlier analysis and both fell out of the
pattern match independently.

## Output format

`layout/symbols_sdk.txt`, sorted by address:

```
  ADDRESS  SYMBOL                          library(member object)  region  [?]
```

The region is `arm9` for the static module, `arm9_autoload<N>_<KIND>` for an
autoload block, or `ov<NNN>` for an overlay. A trailing `?` marks the 50
weakly-supported symbols described above. The per-library summary is appended
to the same file as comment lines. `layout/symbols_sdk.json` carries the same
data plus the variant-profile and per-library tables in machine-readable form.

## Known limitations

* Only `STT_FUNC` symbols are emitted. `libmatch.py --data` will also pattern
  a library's data symbols, but that was not enabled for the committed run:
  data patterns are mostly relocation words and match poorly.
* Static functions with the same name in different objects (the DWC
  `sceneXXX.o` family all define `endScene1`, `procInit1` and so on) resolve
  to many addresses. That is correct, but the member object attributed to any
  one of them is a best guess when several objects contain byte-identical
  code.
* Functions whose every distinguishing byte is relocated, and functions under
  the size floor, cannot be matched at all. This is the main reason a
  library's fraction is not 100%.

# Part 2: compiler smoke test

`tools/mwccarm/mwccarm/dsi/` holds nine TWL-line CodeWarrior toolchains.
Each directory has `mwccarm.exe`, `mwasmarm.exe` and `mwldarm.exe`, which run
natively on Windows. `tools/cw.py smoke` compiles and links one trivial
ARMv5TE translation unit with each of them and validates the resulting ELF.

## Flags

Compiler flags, the mwccarm spelling of the era:

```
-proc arm946e -O4,p -enum int -lang c99 -Cpp_exceptions off
-interworking -char signed -gccext,on -msgstyle gcc -W all -ir .
```

All nine front ends accept that set unchanged.

Linking needed one discovery. `mwldarm` has no `-nostdlib`; with no linker
command file it falls back to a built-in one that references the SDK runtime
and fails with `File not found: STATICINIT`. A self-contained link therefore
has to supply its own LCF, and in CodeWarrior's LCF dialect only the *first*
section placed into a segment uses `>`; every later one must use `>>` or the
linker rejects it with `Segment main already allocated`:

```
MEMORY {
    main (RWX) : ORIGIN = 0x02000000, LENGTH = 0x00100000
}

SECTIONS {
    .text   : { *(.text) }          >  main
    .rodata : { *(.rodata) }        >> main
    .data   : { *(.data) }          >> main
    .bss    : { *(.bss) *(COMMON) } >> main
}
```

with `mwldarm -m SmokeEntry -o smoke.elf smoke.lcf smoke.o`. `cw.py` also
sets `MWLibraries` and `MWLibraryFiles` in the child environment, purely to
silence two usage warnings.

The result is checked, not just assumed: `cw.py` parses the output and
requires ELF32 little-endian, `EM_ARM`, `ET_EXEC`, and an entry point inside
the range the linker script declares.

## Versions

All nine compile and link. `mwasmarm` and `mwldarm` are reported for
completeness; the smoke test drives `mwccarm` and `mwldarm`.

| dir | mwccarm | mwasmarm | mwldarm | compile | link | entry |
| --- | --- | --- | --- | --- | --- | --- |
| `dsi/1.1` | 4.0 build 1018 | 1.0 build 26 | 2.0 build 96 | ok | ok | 0x02000050 |
| `dsi/1.1p1` | 4.0 build 1024 | 1.0 build 26 | 2.0 build 96 | ok | ok | 0x02000050 |
| `dsi/1.2` | 4.0 build 1026 | 1.0 build 27 | 2.0 build 98 | ok | ok | 0x02000050 |
| `dsi/1.2p1` | 4.0 build 1027 | 1.0 build 27 | 2.0 build 99 | ok | ok | 0x02000050 |
| `dsi/1.2p2` | 4.0 build 1028 | 1.0 build 27 | 2.0 build 99 | ok | ok | 0x02000050 |
| `dsi/1.3` | 4.0 build 1034 | 1.0 build 27 | 2.0 build 99 | ok | ok | 0x02000050 |
| `dsi/1.3p1` | 4.0 build 1036 | 1.0 build 27 | 2.0 build 99 | ok | ok | 0x02000050 |
| `dsi/1.6sp1` | 4.0 build 1051 | 1.0 build 27 | 2.0 build 99 | ok | ok | 0x02000050 |
| `dsi/1.6sp2` | 4.0 build 1051 | 1.0 build 27 | 2.0 build 99 | ok | ok | 0x02000050 |

Two things worth recording:

* `dsi/1.6sp1/mwccarm.exe` and `dsi/1.6sp2/mwccarm.exe` are byte-identical
  (same MD5), both reporting build 1051 with a runtime build date of
  2011-07-15. Treat them as one compiler. The collection has no 1.4 or 1.5.
* The banner says "Freescale C/C++ for Embedded ARM", version 4.0, while the
  `.comment` string the same compiler writes into its objects says
  "Metrowerks C/C++ for ARM 4.0.0.<build>". The build number is the field
  that connects the two, which is how the library survey in Part 1 maps
  build 1024 onto `dsi/1.1p1`.

This is plumbing validation only. It does not claim any of these versions
reproduces the game's code; establishing that is per-function work for later.

# Reproduce

```
python tools/delink.py                          # if extract/ is not populated yet
python tools/libmatch.py scan                   # writes layout/symbols_sdk.*
python tools/libmatch.py comments --only Rom    # compiler build strings per tree
python tools/cw.py versions                     # toolchain banners
python tools/cw.py smoke                        # compile + link all nine
python tools/cw.py smoke --markdown             # the table above
```

`libmatch.py scan` takes about 17 seconds and needs no pip packages.
Useful switches: `--only <substring>` restricts the archives by path,
`--no-overlays` scans only the ARM9 image, `--data` additionally patterns
data symbols, `--demos` includes the SDK demo helper libraries.
