# aletheia

A decompilation project for Pokémon Black (and eventually White).

This project shares no code with any existing decompilation effort. All tooling
(ROM extraction/rebuilding, disassembly, build system) is written independently
for this repository.

## Overlays

237 overlays, 2,183,302 game code bytes (+563,602 SDK bytes), 29,042 labelled functions (971 of them linker veneers, counted as neither),
  2,183,286 matched (99.9993% of game), plus 3,236 SDK functions (563,602 bytes) matched.
Bytes are instruction bytes on both sides, the measure used for ARM9: literal pools
and data runs are not counted as matched or as work. The listings were
regenerated this phase with the new function starts (hidden functions found
from pointer tables and call targets), so the byte totals grew.

Fully linked: 100.00% of game code (2,630,598 of 2,630,598 bytes) and 100.00% of
all code (3,390,676 of 3,390,676 bytes). This is code in whole source files
whose functions are all exact, linked by `mwldarm` from our own objects into a
byte-identical region (`tools/linkstats.py`; `progress/report.json` is the
decomp.dev report). 181 of 243 regions link byte-identical with every file,
ARM9 and the battle overlay ov093 included. 158 ARM9 functions (9,192 bytes)
that sit in NitroSDK, NitroSystem and DWC objects are now counted as SDK code,
not game code (`layout/sdk_class_extra.json`).

![Overlay coverage map](docs/coverage_overlays.svg)

## ARM9 main binary

436,024 of 436,032 game bytes, 5,326 functions, byte-matching (the worklist still lists one 8-byte linker veneer at 0x02072788 as open). SDK: 1,366 of 1,366 functions matched (148,406 of 148,406 bytes). The ARM9 static image now links byte-identical from our objects.

![ARM9 coverage map](docs/coverage_map.svg)

## DSi `twl` region and ARM9 autoloads

twl: 222 functions, 48,976 SDK bytes, all matched, in 48 files: one file per
SDK object, with the vendor names (`camera_api.c`, `dsp_pipe.c`, `nwm_*.c`, ...).
It links byte-identical from our objects. ITCM 100%. The DSi-mode `twl` block and the ARM9
autoload blocks (ITCM, the two MAIN_TWL stubs and VRAM_LCDC) are not part of
the ARM9 static image or the overlays, so they have a map of their own.

![TWL/ITCM/autoload coverage map](docs/coverage_twl.svg)


## Goal

Fully decompile Pokémon Black (and eventually White) to readable, buildable C source that produces a
byte-matching ROM.

## Status

### Decompilation (aletheia)

- [x] **Milestone 1**: ROM extraction and rebuild
  - [x] Extract ROM filesystem with `tools/ndsrom.py`
  - [x] Rebuild a byte-matching, launchable `.nds`
  - [x] Verify the rebuilt ROM boots in melonDS (other emulators and hardware untested)
- [x] **Milestone 2**: Delink, disassemble, and prove reassembly
  - [x] BLZ-decompress and delink ARM9 binary + all 237 overlays
  - [x] Disassemble with `tools/disasm.py` (ARM/Thumb, code/data split)
  - [x] Reassemble byte-identically (`tools/build.py`: 242 of 242 regions PASS; 243 of 243 with the DSi-mode region `twl`, decrypted with a user-supplied key)
  - [x] Split ARM9 into ordered translation units
  - [x] Decrypt overlay 230's self-encrypting code for disassembly (`tools/ovcrypt.py` replays the game's own decryptor; no key needed)
- [~] **Milestone 3**: Incremental decompilation to matching C
  - [x] Build system compiles C and links against remaining assembly
  - [x] Pokémon data field map and the message text cipher (`src/matched/`)
  - [x] Stat calculator, pokeparty.c, level-up and evolution logic
  - [x] About 1000 original source filenames recovered from `__FILE__` anchors (`layout/file_anchors.txt`)
  - [x] ARM9 main binary: all game-written functions ship as verified C (436,024 game bytes), and so do the NitroSDK / NitroSystem library code (148,406 of 148,406 bytes) and the compiler runtime (MSL, soft-float; 10,360 of 10,360 bytes)
  - [x] ITCM, the data autoloads and the DSi-mode `twl` region: all code matched; `twl` is one C file per SDK object (48 files, 48,976 of 48,976 SDK bytes)
  - Verified means recompiled and byte-identical to the original at every integration; unmatched functions are carried as reassembled listings so the ROM always rebuilds byte for byte.
  - [ ] Boot path: system init, overlay loader, `tcbl.c`, `bg_sys.c`,
        `palanm.c`, `clact.c`, `gf_font.c`, title and field managers
  - [ ] Field and battle loop call trees
  - [ ] Overlays: 24,835 game functions are matched (2,183,286 of 2,183,302 game instruction bytes, 99.9993%), plus 3,236 of 3,236 SDK functions (563,602 of 563,602 SDK instruction bytes) matched; regions that do not link from objects yet are still carried as reassembled listings
  - [ ] 100% matching across the whole ROM
  - [~] One C file per original source file (`src/game/`): 1,212 `.c` files, 1,212 of 1,212 translation units whole and byte-exact (`docs/restructure/REPORT.md`)
  - [~] Build from `src/game`: `tools/build.py --game` rebuilds every region whose files are whole; `tools/gamelink.py` links 181 of 243 regions (ARM9, ITCM, `twl` and 178 overlays) byte-identical with the original `mwldarm` linker; fully linked: 100.00% of game code, 100.00% of all code (data between files still comes from the extracted image: `docs/restructure/BUILD_FROM_GAME.md`)
  - [~] Source cleanup (`src/game`): per-file structs and shared `_types.h` headers instead of per-function views, merged and split files, descriptive names for functions, types, fields and locals. Finished: ARM9; the field, network and one-file overlays (ov009 to ov065); the tool and menu overlays ov070 (item menu), ov071, ov088 and ov091; the gimmick overlays (merged and renamed); the battle overlay ov093 (btl_main, btl_client, btl_server_flow, the btlv_core and btlv_scu view files, btl_field, and the hand_tokusei, hand_item, hand_waza and hand_common handler files with their HAND_TOKUSEI_, HAND_ITEM_, HAND_WAZA_ and HAND_COMMON_ prefixes); ov094 (split into its 13 original files); ov095 (handlers, view, status and record files); ov096 to ov106, ov110, ov114 and ov175 (the Wi-Fi, IRC, phrase-input, HTTP and ranking libraries and game code); the ov099 Wi-Fi Club; and every merge group that was refused earlier in ARM9, ov009 and ov016. Wave 5 added ov013 (vct), ov015 (irc, irc_internal, ircnet), the ov010 to ov014 and ov021 unit files (11 named scrcmd, event and field files), about 25 small overlays and ITCM (mi_dma, os_irqhandler, os_reset, scfg_proc), the shared IR headers of ov101 to ov106, ov107 (libmb SDK files and mb_comm_sys), ov119 (pokemon trade), ov123 (gsync and pdwacc), ov125, ov135 (14 world trade files), ov136 (mail), ov137 (guru2), ov170 (box2 header), ov171 (dendou view), ov172 (14 ctvt, camera and ssp files), ov180 (hall of fame), ov186 to ov188 (battle recorder), ov208 and ov209 (zukan detail and list), ov217 (research, 11 files) and typed ov094 btlv files; the battle record and poke_tool types are unified in ARM9. Wave 6 added the four small-overlay sweep blocks (ov111/112/117/118, ov115/116/120/121, ov127/128/129/132/133/134 and ov173/178/179/183/185/198), ov094 btlv_input, ov119 (pokemon trade), ov123 (gsync), ov135 (world trade), ov137 (guru2_main), ov170 (box2 retyped to BoxWork), ov172 (ctvt), ov186 (br_proc_sys), ov208 (zukan detail), ov209 (zukan list) and ov217 (research), plus the ARM9 os, mi, heap, lib, save and sound clusters; the shared headers folded this wave are nns_fnd_types.h, nns_snd_types.h, snd_shared_types.h, dwc_svl_types.h, namein_args.h, os_system_work_types.h and frame_list_params.h. Wave 7 finished the restructure: the tree now holds one file per original source file, with no `unit_` or placeholder names and no `unplaced` directories left. It added four sweep blocks plus ov095/122/131/174/176/177, which finished the last boundaries; three anchor-confirmed splits in ov174, ov176 and ov177; the arm9 graphics cluster, two logic groups, the filesystem, wifi and msl_c_lib clusters, all named; ov009 named from the SDK symbol table; and the ov137 (guru2 conversion), ov170 (macro removal), ov172 (ctvt_comm), ov186 (br_btn), ov119 (TradeRequest), ov217 and ov209 continuations. Wave 8 added the ten naming continuations (ov210-215, ov181-199, ov203-207, ov216-222, ov223-231, ov111-118, ov115-121, ov127-134, ov132-198, ov175-195), the arm9 graphics, logic and wifi clusters, ov009 named from the SDK symbol table, and the ov137/170/172/186/119/209/217 continuations; then it split 61 aggregated files into their originals: the ov203/ov204/ov212/ov215/ov127/ov115/ov121/ov118/ov132/ov195 overlays and the arm9 bmp, menu, oam, font, g3d, tcbl, mcss, mystery_data, touchpanel, msl_c_lib (ten-way), nns_fnd_unitheap and bsubway_savedata pieces, plus the double3Ddisp and billboard merge. Wave 9 shaped 24 lanes around removing the `Obj` view pattern: 5,052 view references across the overlays were folded into real structs and 12 regions reached zero views (7,345 `Obj` references remain across 109 files, down from 12,397 across 164), with new owner headers for ov211, ov215, ov204, ov198, ov173, ov210, ov133, ov128 and ov121, and three recurring compiler facts recorded in `docs/COMPILER_NOTES.md`; then it split the last two aggregated originals, ov133 into dup_fitting.c and dup_fitting_item.c and arm9 misc_savedata.c into misc_savedata.c, battle_examination.c and misc_savedata_2.c. Wave 10 shaped 22 lanes around finishing the `Obj` removal: the two opaque PROSYS spellings `struct Obj0203159C` and `struct S020315D4` resolved to `struct Proc` across 886 references in 325 files, four standing per-file `*_shared_types.h` folded into their owner headers, and the five compiler-note corrections applied, so 3,874 `Obj` references remain across 37 files and 15 regions reached zero views; `docs/COMPILER_NOTES.md` now carries the refinements. Three gap-fix lanes followed wave 10: arm9 `ui_p02.c` was folded into one whole `ui.c` (54 functions), the ov194 `namein_graphic` range was split into five originals at their real boundaries (`namein_graphic_main.c`, `namein_graphic_field.c`, `namein_graphic.c`, `namein_data.c`, `nsbtx_to_clwk.c`), the per-function verify path was generalised to a non-contiguous C piece (`contiguous: no`), and the H1 hand-written marker was applied to the 33 `cw_runtime` asm bodies (a comment-only change, awaiting owner confirmation); game code is now fully linked at 100.00 percent. 36,186 functions carry names (36 functions still have address names; the earlier counts were undercounts, the counter missed single-line definitions); 0 unit_ files, 0 unplaced dirs and 0 placeholder files remain. The svc stubs of ARM9 are split into their own files. The unit file names of ARM9, ov009 and ov016 were replaced by the original or SDK object names (848 files). The other overlays carry address names except where a function was named from the SDK or from a lane table. Every file stays byte-exact (`tools/gameverify.py`). `src/matched` is the raw evidence store: it holds one function per file, with per-function views by construction, so it is NOT in scope for "cleaned" and its `Obj` views are expected. Wave 11 integrated the lane rename maps tree-wide (365 address names down to 36), folded the last shared `Obj` views and the hoisted headers, and recorded the INV-C pointer-word search shape.

- [ ] **Milestone 4**: Native PC port ([eidos](https://github.com/Project-Holon/eidos))
- [ ] **Milestone 5**: Pokémon White support

Companion project: [eidos](https://github.com/Project-Holon/eidos) is the native runtime engine and PC port companion to aletheia.

See [docs/ROADMAP.md](docs/ROADMAP.md) for the planned approach, and
[docs/NOTES.md](docs/NOTES.md) for technical findings recorded along the way.

## Requirements

- Python 3.11+
- Your own legally dumped ROM of Pokémon Black (USA, Europe) (NDSi Enhanced)
  - SHA1: `26ad0b9967aa279c4a266ee69f52b9b2332399a5`
  - Size: 268435456 bytes
  - Place it in the repo root (any `*.nds` filename works; commands below
    take the path as an argument)
- Optional, only for the DSi-mode region `twl`: the 16-byte DSi AES
  key-scrambler constant in a file you keep outside the repo, passed as
  `--dsi-key` or `ALETHEIA_DSI_KEY` (a DSi ARM9 BIOS dump does not contain
  it); it is never committed, and without it the build is the usual 242
  regions.

## Usage

```
python tools/ndsrom.py extract "<your-rom>.nds" -o extract
python tools/ndsrom.py build extract -o build/pokeblack.nds
python tools/ndsrom.py verify extract build/pokeblack.nds
```

The rebuilt ROM runs in melonDS, DeSmuME, or on real hardware via flashcart.

To delink, disassemble and prove the disassembly reassembles byte-identically:

```
pip install capstone
python tools/delink.py
python tools/disasm.py arm9 --split
python tools/disasm.py overlay --all
python tools/build.py --arm9-image          # all 242 regions
python tools/build.py --split --only arm9   # ARM9 from its translation units
```

### Setup per platform

Every tool is plain Python 3 (stdlib, plus `capstone` for the disassembler) and
finds what it needs through `tools/env.py`; `python tools/env.py` prints what
it resolved and `python tools/selfcheck.py` compiles one matched function and
runs one split build.

- **Windows**: unpack the xPack `arm-none-eabi-gcc` win32-x64 zip into
  `tools/gcc-arm/`. The CodeWarrior compilers in `tools/mwccarm/` run
  directly. For the eidos port, unpack the xPack `mingw-w64-gcc`, CMake and
  Ninja Windows zips into `tools/gcc-host/`, `tools/cmake/` and `tools/ninja/`.
- **macOS**: unpack the xPack `arm-none-eabi-gcc` darwin zip (x64 or arm64)
  into `tools/gcc-arm/`, and install wine (`brew install --cask wine-stable`)
  so `mwccarm.exe` can run. For eidos, unpack the CMake and Ninja macOS
  archives into `tools/cmake/` and `tools/ninja/`, or rely on Xcode's clang
  and any CMake/Ninja on `PATH`.
- **Linux**: unpack the xPack `arm-none-eabi-gcc` linux-x64 (or arm64) archive
  into `tools/gcc-arm/`, and install wine from the distribution
  (`apt install wine` or equivalent). For eidos, unpack the CMake and Ninja
  Linux archives into `tools/cmake/` and `tools/ninja/`, or use the system
  gcc, cmake and ninja on `PATH`.

Nothing else is platform-specific. `--toolchain` or `BW_ARM_TOOLCHAIN` can
point at any other `bin/` directory holding `arm-none-eabi-as`, a binutils on
`PATH` is used as a last resort, and `ALETHEIA_SCRATCH` moves the scratch
directory (default: the system temp directory plus `aletheia`). See
[docs/NOTES.md](docs/NOTES.md) for details.

## Acknowledgments

Development of this project is assisted by Anthropic's Claude (via Claude
Code); tooling and documentation are produced with its help under human
direction and review.

## License and legal

The tooling, layout files, documentation and build scripts are released under
the MIT License (`LICENSE`). The reverse-engineered game source under `src/`
is distributed without a license grant and remains the property of Nintendo,
Creatures Inc. and GAME FREAK inc.; see `LEGAL.md`. This repository contains
no game data of any kind: you must dump your own cartridge to use any of it.

## Repository layout notes

`extract/` and `build/` are gitignored on purpose (they are generated from
your own ROM dump) and must never be committed.

Sources are sorted under `src/matched/` and `src/pending/` by region and kind:
`arm9`, `arm9_sdk`, `itcm_sdk`, `ov`, `ov_sdk`, `twl`, `twl_sdk`.
