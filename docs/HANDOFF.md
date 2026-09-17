# Handoff state (2026-09-16)

Written for whoever picks the project up next, human or agent. Everything below is
reproducible from the repo plus the owner's own ROM dump; nothing here depends on
the previous session's memory.

## Where things stand (2026-09-16, end of day)

- Repositories: the decompilation is aletheia (this repo), the native port is
  eidos, the modding suite is kenon (empty, planned), all under the GitHub
  organisation Project-Holon. Local checkouts: `Documents/aletheia` (this
  repo, folder name kept), `Documents/eidos`, `Documents/kenon`,
  `Documents/holon` (the org profile repo `.github-private`). A junction
  `aletheia/eidos` points at the eidos checkout so one VS Code window shows
  both; it is git-ignored.
- Code: 20.0457 percent of ARM9 game code matched byte for byte (1957 matched
  functions, 80296 of 400564 bytes, `python tools/worklist.py --summary`),
  plus matched functions in overlays ov010 and ov021 that the summary does not
  count. Every matched function is spliced into the build and the rebuilt ROM
  is byte-identical (sha1 26ad0b9967aa279c4a266ee69f52b9b2332399a5).
  Recent waves closed whole subsystems: tcbl.c (task callback lists, incl.
  the register), the heap layer (allocator, free, expanded heap), palanm.c,
  arc_tool.c, net.c, wm_icon.c, gf_standard.c, g3d_light.c, bmp.c loader,
  field_sound_system.c task pairs, the message loader, both script VMs.
- Harness: seven witness classes (local, label incl. ARM9-to-overlay with a
  region hint as the fourth token of a symbols line, literal incl. hidden
  pools, string incl. control characters in the preceding run, veneer,
  matched, sdk, runtime for calls into the MSL runtime listed in
  `layout/runtime_arm9.txt`); EXACT requires every relocation attested
  (adjacency is not evidence); selftest 74 cases. One translation unit
  (0x020524C8-0x020585DC, skeleton math) is compiled `-proc arm7tdmi`;
  `layout/proc_hints.txt` and `worklist --targets` show it.
- Assets: every one of the 247 NitroFS files is identified and decodes and
  repacks byte-identically (`python tools/assets/verify_all.py`, 0 failures).
  The world data chain (zone header, scripts, matrices, map models, terrain
  records, event data, encounters), the core data tables and both script VMs
  are decoded from our own matched readers. Samples for review are exported by
  the asset tools into `Documents/bw_asset_samples` (outside the repo).
- Port (eidos): ILP32 is the reference configuration (i686 MinGW from the
  toolchain zip under `tools/gcc-host/`; LP64 builds through a switch).
  Running on the host through matched code: archive readers, text cipher,
  personal data and stat formula, the heap layer, the task callback list.
  Engine done and tested: 2D (OBJ, BG, affine, windows, colour effects;
  pixel-identical to `tools/assets/rig.py` and `background.py`), the DS frame
  loop and SDL2 platform layer, audio (SDAT/SBNK/SWAR/SSEQ and a 16-channel
  mixer, bit-identical to `tools/assets/sseqsynth.py` on three sequences), and
  3D (fx32 pipeline, matrix stack, display-list interpreter, NSBMD/NSBTX, all
  seven texture formats, a software rasteriser, and the MDL0 node dictionary:
  record layout, translation, full rotation, scale, parent/child tree and
  shape binding; the packed rotation completion is provisional, see
  `eidos/docs/g3d-nodes.md`). The 3D output can be a layer inside the 2D
  per-pixel compositor, so a BG can sit in front of or behind it and the
  colour effects blend with 3D pixels. The file layer resolves a NitroFS path
  through an optional file-granular mod overlay (`sdk/vfs.c`). 14 tests, all
  passing in both pointer widths. `eidos/docs/status.md` groups the port's
  work by dependency: done, open without decomp, and blocked on this repo
  (boot path, heap arena 0x0202FC48, DS sound driver, cinematic, gameplay).
  Next on the port side: the first-run asset extractor (orchestrate `tools/`
  or a self-contained C unpacker), member-level NARC overlay, and a DS frame
  for the rasteriser oracle.

## How to continue

1. Read `docs/AGENT-BRIEF.md` (matching rules, attestation classes, write set),
   `docs/PARALLEL.md` (commands, packets, tooling) and `docs/MATCHING.md`
   (idiom index) before touching `src/`.
2. Targets: `python tools/worklist.py --targets` (skip anything inside the MSL
   runtime ranges in `layout/runtime_arm9.txt`; the documented one-instruction
   near misses in `docs/notes/` are not worth re-attempting without a new lever).
3. Integration after a batch of matches, in this order: `python tools/match.py
   manifest --verify` (twice when entries in one shard witness each other),
   `python tools/match.py idioms`, `python tools/build.py --split --pack`,
   `python tools/ndsrom.py build extract --override build/pack -o
   build/pokeblack.nds`, `python tools/ndsrom.py verify extract
   build/pokeblack.nds`, `python tools/worklist.py --refresh`. Commit code and
   asset changes separately. Stage explicit file lists, never whole directories,
   if more than one agent writes the tree.
4. Seeds for unlabelled functions go in `layout/function_starts.txt`
   (region, address, isa, comment naming the witness), then regenerate with
   `python tools/disasm.py arm9 --split` and confirm `python tools/build.py
   --split --pack --no-c` still passes 242/242.

## Open items, smallest first

- `tools/assets/sseqsynth.py`: PSG noise runs at the channel timer rate
  with the hardware LFSR (carry XORs 0x6000) and mixes at 16-bit scale. The
  noise level relative to PCM (a quarter of full scale) is a chosen constant;
  no decompiled code attests it. Treat any claim that it matches a hardware
  volume divider as unverified.
- `gfl_font.dat`: glyph order known from the data (kana 1-166, two digit sets
  168-187, capitals 188-213, lowercase 214-239, punctuation 240-259), 288/288
  records round trip. No code references the file by name; the "GFL_ prefix"
  identification in the session log below is a guess, not a traced consumer.
- 51 small tables in `tools/assets/tables.py` have exact framing and round
  trip, but no attested reader; two levels of register tracing found two more
  readers and two artifacts (`docs/ASSETS.md`, "Archive readers, second
  level"). Their domains stay guesses until a reader is traced.
- Rig rendering: painter order (lower OAM index on top), sentinel-dimension
  NCGRs and background pairing by coverage were all fixed from the composer
  code; Charizard and Gengar attach and have eyes (verified in the samples).
  Species with non-identity SRT frames render through the engine's 8.8 affine
  path; rig.py's float path differs on texel edges (about 2 percent of
  pixels on species 88), the engine is the reference.
- `src/pending/` holds byte-correct files blocked on a witness; each header
  names the blocker.
- Tooling: `match.py show` needs `--region` for overlay addresses and
  mis-renders unlabelled Thumb leaves as ARM; `manifest --verify` counts
  EXACT* in its "not EXACT" line; no attestation class exists for a data
  table referenced by exactly one pool word (blocks gf_font.c's dispatchers
  and the clact.c handler tables); the clact.c chain is parked on 0x02065CE4
  and 0x02065BD0 (register allocation policy, see docs/notes).

Pokémon White is the planned second target; every tool is parameterised by the
extracted layout, so the work is a second `extract/` plus per-target layout files.

## Review of the helper session (2026-09-16, waves 1 to 8 below)

Findings from re-verifying the nine helper commits (b3dfbeb to 917bb6a):

- The matches are real. All 118 new functions re-verify byte-exact with
  `match.py`, reassembly is 242/242 and the ROM is byte-identical. Two of them
  closed targets earlier notes had written off: `sub_02045EC0` (fan-in 526,
  the "one scheduled lsl" near miss) and the word-at-a-time `strcmp` at
  `0x020948E0`. Lesson: a documented near miss is not permanent; a fresh
  reading can find the source shape.
- The shard statuses were wrong for 36 entries: 30 read `EXACT` where the
  regenerated listings give `EXACT*` (unlabelled follower) and 6 the other
  way. The helper verified against listings that did not match the committed
  `layout/function_starts.txt` and committed a `layout/units_arm9.json` that
  `disasm.py` does not reproduce. Rule: after pulling or after touching the
  seed file, run `python tools/disasm.py arm9 --split` before any
  `manifest --verify`, and never hand-edit `layout/units_*.json`; they are
  generated.
- The handoff prose it wrote overstated several asset items (see the
  corrected open-items list above). Rule: the attested record is
  `docs/ASSETS.md`; a handoff entry may only say "verified" when it cites the
  tool run and the numbers.
- One em dash and one doubled percent sign slipped into docs and a commit
  message. Rule: no em dashes anywhere; read the commit message once before
  committing.
- `unit_020749B4` overrules the SDK symbol `FATFS_FormatDrive`. The harness
  permits a byte-exact game match at an SDK address, but SDK-symbol addresses
  are normally vendor library code and not targets; check
  `layout/symbols_sdk.txt` before spending effort at such an address.
- Nothing in the helper's C reads as transplanted from another project; the
  headers, typedef block and extern lists follow this repo's shape.

The helper's own per-wave log follows, kept as written except for the
corrections noted here.

## Session Updates (2026-09-16T00:15:00+01:00)

### Progress & Status
- **ARM9 Matched Coverage**: Increased from 15.68% (62,740 B / 1,505 functions) to **16.36%** (65,452 B / 1,559 functions across 495 packets).
- **Rebuilt ROM Byte-Identity**: Verified 100% byte-identical (`sha1: 26ad0b9967aa279c4a266ee69f52b9b2332399a5`).
- **All 242 Overlays**: PASS.

### Graduated EXACT Units in this Session
1. **`unit_02012FF0`** (`0x02012FF0..0x02013020`, 48 B, ARM):
   - `func_02012FF0` (12 B), `func_02012FFC` (36 B). Shard `pkt_02012F08.json`.
2. **`unit_02013020`** (`0x02013020..0x0201306C`, 76 B, ARM):
   - `func_02013020` (76 B). Shard `pkt_02012F08.json`.
3. **`unit_0204152C`** (`0x0204152C..0x0204162C`, 256 B, ARM):
   - `func_0204152C` (68 B), `func_02041570` (68 B), `func_020415B4` (120 B switch table). Shard `pkt_0204152C.json`.
4. **`unit_0204162C`** (`0x0204162C..0x020416D4`, 168 B, ARM):
   - 6 functions: `func_0204162C` through `func_020416B8` (28 B each). Shard `pkt_0204152C.json`.
5. **`unit_0204994C`** (`0x0204994C..0x02049A18`, 204 B, ARM):
   - `func_0204994C` (68 B), `func_02049990` (68 B), `func_020499D4` (68 B). Shard `pkt_0204994C.json`.
6. **`func_0204A03C`** (`0x0204A03C..0x0204A07C`, 64 B, ARM):
   - Shard `pkt_0204A03C.json`.
7. **`unit_0204A07C`** (`0x0204A07C..0x0204A0FC`, 128 B, ARM):
   - `func_0204A07C` (64 B), `func_0204A0BC` (64 B). Reciprocal outside witness with `unit_0204A0FC` for `func_02062920`. Shard `pkt_0204A03C.json`.
8. **`unit_0204A0FC`** (`0x0204A0FC..0x0204A1BC`, 192 B, ARM):
   - `func_0204A0FC` (64 B), `func_0204A13C` (64 B), `func_0204A17C` (64 B). Shard `pkt_0204A03C.json`.
9. **`func_0204A380`** (`0x0204A380..0x0204A39C`, 28 B, ARM):
   - Shard `pkt_0204A03C.json`.
10. **`func_02060468`** (`0x02060468..0x02060480`, 24 B, ARM):
    - DList initialization function. Shard `pkt_02060468.json`.
11. **`unit_02060614`** (`0x02060614..0x020606A8`, 148 B, ARM):
    - `func_02060614` (24 B), `func_0206062C` (20 B), `func_02060640` (104 B recursive search). Shard `pkt_02060468.json`.
12. **`unit_020742E4`** (`0x020742E4..0x0207457C`, 664 B, ARM, Fan-In 41):
    - 9 header accessor functions. Shard `pkt_020742E4.json`.
13. **`func_0207457C`** (`0x0207457C..0x020745A4`, 40 B, ARM):
    - Shard `pkt_0207457C.json`.
14. **`func_020745A4`** (`0x020745A4..0x0207466C`, 200 B, ARM):
    - Chunked stream reader. Shard `pkt_0207457C.json`.
15. **`func_0207466C`** (`0x0207466C..0x02074694`, 40 B, ARM):
    - Shard `pkt_0207457C.json`.
16. **`func_02074694`** (`0x02074694..0x020746B0`, 28 B, ARM):
    - Shard `pkt_0207457C.json`.
17. **`func_0208E4BC`** (`0x0208E4BC..0x0208E4CC`, 16 B, ARM, Fan-In 20):
    - Shard `pkt_0208E4BC.json`.
18. **`unit_02092344`** (`0x02092344..0x020923C4`, 128 B, ARM):
    - `func_02092344` (68 B), `func_02092388` (60 B). Shard `pkt_02092120.json`.
19. **`func_020923C4`** (44 B, ARM), **`func_020923F0`** (44 B, ARM):
    - Shard `pkt_02092120.json`.
20. **`unit_02094860`** (`0x02094860..0x020949F4`, 404 B, ARM):
    - `func_02094860` (128 B), `func_020948E0` (276 B). Shard `pkt_02094798.json`.
21. **`unit_020949F4`** (`0x020949F4..0x02094B20`, 300 B, ARM):
    - `func_020949F4` (108 B), `func_02094A60` (192 B). Shard `pkt_02094798.json`.
22. **`func_02094B20`** (`0x02094B20..0x02094B3C`, 28 B, ARM):
    - Shard `pkt_02094798.json`.
23. **`unit_02027710`**, **`unit_0203AD74`**, **`sub_02045EC0`**:
    - Graduated and verified EXACT into respective shards.

### Documented Technical Notes
- `docs/notes/dlist_ops.c.txt`: 5 DList operations (`0x02060480..0x02060614`) differing only in 9 bytes of load scheduling around count increment.
- `docs/notes/func_02049A18.c.txt`: 296 B ARM function, logic matches 100%, register scheduling differences documented.
- `docs/notes/func_020948E0.c.txt` & `docs/notes/func_02094A60.c.txt`: Logic matches 100%, scheduling differences documented.

## Session Update, 2026-09-16 00:45 (Wave 2)

### Milestone Progress
- **Coverage**: Reached **16.4425%** (65,780 / 400,060 bytes).
- **Functions Matched**: 1,578 functions matched (+19 functions in Wave 2).
- **ROM Verification**: Rebuilt ROM byte-identical (`sha1: 26ad0b9967aa279c4a266ee69f52b9b2332399a5`) with 242/242 component tests passing.
- **SDK Overrule**: `0x020749B4 FATFS_FormatDrive -> unit_020749B4` (15 total).

### Matched and Graduated Units in Wave 2
1. **`unit_020749B4`** (`0x020749B4..0x02074A54`, 160 B, ARM, Shard `pkt_020749C4.json`):
   - Sound system helper translation unit with 4 functions:
     - `func_020749B4` (16 B, tail-call thunk to `func_02060468`)
     - `func_020749C4` (52 B, list initialization & entry insert)
     - `func_020749F8` (60 B, allocator & queue append)
     - `func_02074A34` (32 B, SND command processing & flushing)
   - All 9 internal and external relocations 100% resolved without wildcards.
2. **Sound Subsystem & Lerp Functions** (`pkt_02075794.json`):
   - `func_02075A94` (36 B, ARM): Reference-counted decrement and destructor dispatch.
   - `func_02075B94` (24 B, ARM): Linear interpolation (lerp) object zero-initialization.
   - `func_02075C08` (24 B, ARM): Lerp step increment if below duration.
   - `func_02075C20` (24 B, ARM): Lerp completion check (`step >= duration`).
3. **Tail-Call Forwarder Thunks to `func_020307B0` (`OS_FreeToHeap` wrapper)**:
   - `func_02011264` (8 B, Thumb, Shard `pkt_02011264.json`)
   - `func_02028784` (8 B, Thumb, Shard `pkt_02028590.json`)
   - `func_02029F44` (8 B, Thumb, Shard `pkt_02029D44.json`)
   - `func_0202AF28` (8 B, Thumb, Shard `pkt_0202AEBC.json`)
   - `func_0202B1EC` (8 B, Thumb, Shard `pkt_0202AFFC.json`)
   - `func_0202C140` (8 B, Thumb, Shard `pkt_0202C124.json`)
   - `func_02031590` (12 B, ARM, Shard `pkt_020314F4.json`)
   - `func_02048AC4` (12 B, ARM, Shard `pkt_02047E88.json`)
   - `func_0204DC64` (12 B, ARM, Shard `pkt_0204DACC.json`)
   - `func_0204E010` (12 B, ARM, Shard `pkt_0204DD08.json`)
   - `func_0204E0C4` (12 B, ARM, Shard `pkt_0204E0C4.json`)



---

## 2026-09-16 - Wave 3: Graduated 19 Isolated/Clean Work Packets across arm9 (+204 B Net, 22 New Matched Functions)

### Status & Metrics
- **ROM State**: 100% byte-identical (`sha1: 26ad0b9967aa279c4a266ee69f52b9b2332399a5`).
- **All 242 Build Checks Passing**: `242 PASS, 0 FAIL`.
- **arm9 Decomp Coverage**: **16.4935%** (65,984 / 400,060 B across 1,600 matched functions).
- **Open Packets**: Decreased from 500 to 481 (19 packets dissolved).

### Key Functions Graduated in Wave 3
1. **`pkt_02004EAC` (8 B, ARM, 2 funcs)**:
   - `func_02004EAC` (4 B, ARM): Empty stub (`src/matched/unit_02004EAC.c`).
   - `func_02004EB0` (4 B, ARM): Empty stub (`src/matched/unit_02004EAC.c`).
2. **`pkt_0200B37C` (24 B, Thumb, 1 func)**:
   - `func_0200B37C` (24 B, Thumb): Header and array zeroing loop (`src/matched/func_0200B37C.c`).
3. **`pkt_020113D0` (8 B, Thumb, 1 func)**:
   - `func_020113D0` (8 B, Thumb): Struct flag and value store (`src/matched/func_020113D0.c`).
4. **`pkt_02022424` (12 B, Thumb, 1 func)**:
   - `func_02022424` (12 B, Thumb): Coordinate / bounding box array setter (`src/matched/func_02022424.c`).
5. **`pkt_02034FA0` (24 B, ARM, 1 func)**:
   - `func_02034FA0` (24 B, ARM): Byte flag mask clear operation (`src/matched/func_02034FA0.c`).
6. **`pkt_020588FC` (8 B, ARM, 1 func)**:
   - `func_020588FC` (8 B, ARM): Boolean true constant getter (`src/matched/func_020588FC.c`).
7. **`pkt_020590A4` (8 B, ARM, 1 func)**:
   - `func_020590A4` (8 B, ARM): Offset +8 pointer access (`src/matched/func_020590A4.c`).
8. **`pkt_020590C0` (8 B, ARM, 1 func)**:
   - `func_020590C0` (8 B, ARM): Offset +4 pointer access (`src/matched/func_020590C0.c`).
9. **`pkt_020590F0` (24 B, ARM, 3 funcs)**:
   - `func_020590F0` (8 B, ARM): Field store to +8 (`src/matched/unit_020590F0.c`).
   - `func_020590F8` (8 B, ARM): Contiguous pair store via `stmib` (`src/matched/unit_020590F0.c`).
   - `func_02059100` (8 B, ARM): Field store to +4 (`src/matched/unit_020590F0.c`).
10. **`pkt_0205A12C` (8 B, ARM, 1 func)**:
    - `func_0205A12C` (8 B, ARM): Header prefix pointer adjust (`src/matched/func_0205A12C.c`).
11. **`pkt_0205D1BC` (8 B, ARM, 1 func)**:
    - `func_0205D1BC` (8 B, ARM): Constant `~5` return (`src/matched/func_0205D1BC.c`).
12. **`pkt_0207A7BC` (8 B, ARM, 1 func)**:
    - `func_0207A7BC` (8 B, ARM): Offset +0x24 pointer access (`src/matched/func_0207A7BC.c`).
13. **`pkt_0207AB08` (8 B, ARM, 1 func)**:
    - `func_0207AB08` (8 B, ARM): Constant `0` return (`src/matched/func_0207AB08.c`).
14. **`pkt_020834B8` (8 B, ARM, 1 func)**:
    - `func_020834B8` (8 B, ARM): Atomic swap wrapper via `swp` (`src/matched/func_020834B8.c`).
15. **`pkt_02084EB0` (8 B, ARM, 1 func)**:
    - `func_02084EB0` (8 B, ARM): Halfword field read at +4 (`src/matched/func_02084EB0.c`).
16. **`pkt_02085A30` (8 B, ARM, 1 func)**:
    - `func_02085A30` (8 B, ARM): Offset +0x70 pointer access (`src/matched/func_02085A30.c`).
17. **`pkt_02085B94` (8 B, ARM, 1 func)**:
    - `func_02085B94` (8 B, ARM): Value store to +0xb4 (`src/matched/func_02085B94.c`).
18. **`pkt_02087EA0` (8 B, ARM, 1 func)**:
    - `func_02087EA0` (8 B, ARM): Count leading zeros via `clz` (`src/matched/func_02087EA0.c`).
19. **`pkt_0208A638` (8 B, ARM, 1 func)**:
    - `func_0208A638` (8 B, ARM): Offset +0x38 pointer access (`src/matched/func_0208A638.c`).



---

## 2026-09-16 - Wave 4: Graduated 6 Work Packets across arm9 (+120 B Net, 7 New Matched Functions)

### Status & Metrics
- **ROM State**: 100% byte-identical (`sha1: 26ad0b9967aa279c4a266ee69f52b9b2332399a5`).
- **All 242 Build Checks Passing**: `242 PASS, 0 FAIL`.
- **arm9 Decomp Coverage**: **16.5235%** (66,104 / 400,060 B across 1,607 matched functions).
- **Open Packets**: Decreased from 481 to 475 (6 packets dissolved).

### Key Functions Graduated in Wave 4
1. **`pkt_02030F04` (48 B, ARM, 1 func)**:
   - `func_02030F04` (48 B, ARM): Doubly-linked list head pop / unlinking routine (`src/matched/func_02030F04.c`).
2. **`pkt_020627F0` (32 B, ARM, 1 func)**:
   - `func_020627F0` (32 B, ARM): Flag-conditional offset shift index lookup (`src/matched/func_020627F0.c`).
3. **`pkt_02031324` (24 B, ARM, 2 funcs completed)**:
   - `func_02031324` (12 B, ARM): Forwarder thunk to `func_02031354` in `procsys.c` (`src/matched/func_02031324.c`).
   - `func_02031330` (12 B, ARM): Forwarder thunk to `func_020313EC` in `procsys.c` (`src/matched/func_02031330.c`).
   - Note: Packet `pkt_02031324` is now 100% complete and fully dissolved.
4. **`pkt_0203F028` (12 B, ARM, 1 func)**:
   - `func_0203F028` (12 B, ARM): Forwarder thunk to `STD_CompareString` (`0x0208CD94`) (`src/matched/func_0203F028.c`).
5. **`pkt_02084FA8` (12 B, ARM, 1 func)**:
   - `func_02084FA8` (12 B, ARM): Forwarder thunk to `STD_TVSNPrintf` (`0x0208D834`) (`src/matched/func_02084FA8.c`).
6. **`pkt_02085D88` (12 B, ARM, 1 func)**:
   - `func_02085D88` (12 B, ARM): Forwarder thunk to `OS_IsRunOnTwl` (`0x02085D3C`) (`src/matched/func_02085D88.c`).

### Technical Insights
- All SDK library forwarders (`STD_CompareString`, `STD_TVSNPrintf`, `OS_IsRunOnTwl`) possess official SDK attestation, enabling clean zero-mismatch relocations.
- Re-analyzed packet boundaries for partial shards (`pkt_02031324`), successfully dissolving the remainder of the packet.
- Strict 100% byte-identical ROM reassembly preserved.


---

## 2026-09-16 - Wave 5: Graduated 6 Work Packets across arm9 (+116 B Net, 7 New Matched Functions)

### Status & Metrics
- **ROM State**: 100% byte-identical (`sha1: 26ad0b9967aa279c4a266ee69f52b9b2332399a5`).
- **All 242 Build Checks Passing**: `242 PASS, 0 FAIL`.
- **arm9 Decomp Coverage**: **16.5525%** (66,220 / 400,060 B across 1,614 matched functions).
- **Open Packets**: Decreased from 475 to 469 (6 packets dissolved).

### Key Functions Graduated in Wave 5
1. **`pkt_0204DC70` (48 B code, 56 B extent, ARM, 1 func)**:
   - `func_0204DC70` (48 B, ARM): Hardware display control register synchronizer (`REG_DISPCNT` / `REG_DB_DISPCNT` bitmask updater) (`src/matched/func_0204DC70.c`).
2. **`pkt_02089880` (24 B code, 40 B extent, ARM, 2 funcs)**:
   - `func_02089880` (12 B, ARM): Static forwarder to `func_02086028` (`src/matched/func_02089880.c`).
   - `func_02089894` (12 B, ARM): Static forwarder to `func_02086078` (`src/matched/func_02089894.c`).
   - Fully dissolved packet.
3. **`pkt_0205A10C` (12 B code, 16 B extent, ARM, 1 func)**:
   - `func_0205A10C` (12 B, ARM): Pointer getter for `0x02146AAC` (`src/matched/func_0205A10C.c`).
4. **`pkt_02075DA0` (12 B code, 16 B extent, ARM, 1 func)**:
   - `func_02075DA0` (12 B, ARM): Pointer getter for `0x0215019C` (`src/matched/func_02075DA0.c`).
5. **`pkt_020774B0` (12 B code, 16 B extent, ARM, 1 func)**:
   - `func_020774B0` (12 B, ARM): Struct member getter for `0x02150B00.unk04` (`src/matched/func_020774B0.c`).
6. **`pkt_0203D1B4` (8 B code, 12 B extent, ARM, 1 func completed)**:
   - `func_0203D1B4` (8 B, ARM): Tail-call forwarder to `func_020399EC` (`src/matched/func_0203D1B4.c`). Completed all 13 functions, fully dissolving shard `pkt_0203D1B4.json`.

### Technical Insights
- Used ternary predication idiom `(which == 1) ? (*(vu32 *)0x04000000 & 0x00300010) : (*(vu32 *)0x04001000 & 0x00300010)` to produce exact branchless `ldreq`/`ldrne` conditionally predicated loads in `func_0204DC70`.
- All 242 ROM validation checks passing with byte-identical ROM hash.

---

## 2026-09-16 - Wave 6: Graduated 8 Work Packets across arm9 (+244 B Net, 9 New Matched Functions)

### Status & Metrics
- **ROM State**: 100% byte-identical (`sha1: 26ad0b9967aa279c4a266ee69f52b9b2332399a5`).
- **All 242 Build Checks Passing**: `242 PASS, 0 FAIL`.
- **arm9 Decomp Coverage**: **16.6135%** (66,464 / 400,060 B across 1,623 matched functions).
- **Open Packets**: Decreased from 469 to 461 (8 packets dissolved).

### Key Functions Graduated in Wave 6
1. **`pkt_0204961C` (60 B code, 60 B extent, ARM, 2 funcs completed)**:
   - `func_0204961C` (8 B, ARM): Halfword field reader at offset +0x4E (`src/matched/unit_0204961C.c`).
   - `func_02049624` (52 B, ARM): 7-argument forwarder dispatching through `func_0204A1BC` and `func_0204968C` (`src/matched/unit_0204961C.c`).
   - Packet `pkt_0204961C` is now 100% complete and fully dissolved.
2. **`pkt_0201C6FC` (36 B code, 40 B extent, Thumb, 1 func)**:
   - `sub_0201C6FC` (36 B, Thumb): Forwarder to `sub_0201C808` and `sub_0201C758` (`src/matched/func_0201C6FC.c`). Shard `pkt_0201C6FC.json` complete and dissolved.
3. **`pkt_02037200` (32 B code, 36 B extent, ARM, 1 func)**:
   - `func_02037200` (32 B, ARM): Handler validity check and callback dispatch (`src/matched/func_02037200.c`). Shard `pkt_02037200.json` complete and dissolved.
4. **`pkt_020414C4` (32 B code, 40 B extent, ARM, 1 func)**:
   - `func_020414C4` (32 B, ARM): Indexed struct pointer tail call to `func_02040B94` (`src/matched/func_020414C4.c`). Shard `pkt_020414C4.json` complete and dissolved.
5. **`pkt_02011D60` (26 B code, 28 B extent, Thumb, 1 func)**:
   - `func_02011D60` (26 B, Thumb): Sound / channel sequence trigger invoking `func_0203064C(9, 5, 5 << 10)`, `func_02011F24()`, and `func_020306F0(5)` (`src/matched/func_02011D60.c`). Shard `pkt_02011D60.json` complete and dissolved.
6. **`pkt_020242C0` (24 B code, 24 B extent, Thumb, 1 func)**:
   - `func_020242C0` (24 B, Thumb): Double delegate invoking slot initialiser `func_020242A4(a, b)` and processor `func_02024598(a, b, c)` (`src/matched/func_020242C0.c`). Shard `pkt_020242C0.json` complete and dissolved.
7. **`pkt_02006E18` (18 B code, 20 B extent, Thumb, 1 func)**:
   - `func_02006E18` (18 B, Thumb): Allocation delegate retrieving resource via `func_02006E2C()` and passing to `func_02007BD0(a0, res)` (`src/matched/func_02006E18.c`). Shard `pkt_02006E18.json` complete and dissolved.
8. **`pkt_0207C778` (16 B code, 16 B extent, ARM, 1 func)**:
   - `func_0207C778` (16 B, ARM): Dual subroutine invoker calling `func_0207C8A0()` and `func_0207C86C()` (`src/matched/func_0207C778.c`). Shard `pkt_0207C778.json` complete and dissolved.

### Technical Insights
- Multi-argument stack calling convention in ARM matches cleanly by chaining callee return value directly into subsequent caller invocation (`unit_0204961C.c`).
- Thumb one-function translation unit wrapping (`match.py tu`) accurately accounts for two-byte padding boundaries in Thumb routines (`func_02006E18.c` and `func_02011D60.c`).
- 100% byte-identical ROM hash preserved across all 242 regions.

---

## [2026-09-16 08:25:00] Wave 7 Handoff Report

### Status Overview
- **Build Status**: `242 PASS, 0 FAIL` across all ROM overlays and ARM9 regions.
- **arm9 Decomp Coverage**: **16.6980%** (66,802 / 400,060 B across 1,631 matched functions).
- **Open Packets**: Reduced from 461 to 454 (7 packets completely dissolved).
- **Progress in Wave**: +338 bytes net, 8 new matched functions.

### Packets Dissolved in Wave 7
1. **`pkt_0204B604` (84 B code, 84 B extent, ARM, 1 func)**:
   - `func_0204B604` (84 B, ARM): Setter/clearer for 2-bit bitfield `f_14` (bits 20..21) of `struct Actor` at offset +0x60 (`src/matched/func_0204B604.c`). Shard `pkt_0204B604.json` complete and dissolved.
2. **`pkt_02035BBC` (76 B code, 76 B extent, ARM, 1 func)**:
   - `func_02035BBC` (76 B, ARM): Subroutine dispatcher evaluating context status and parameters via `func_02035750`, `func_020357C0`, `func_02035760`, `func_02035780`, and `func_02035ADC` (`src/matched/func_02035BBC.c`). Shard `pkt_02035BBC.json` complete and dissolved.
3. **`pkt_02024534` (58 B code, 60 B extent, Thumb, 1 func)**:
   - `func_02024534` (58 B, Thumb): 8-byte 4-halfword header and payload equality comparator (`src/matched/unit_02024534.c`). Shard `pkt_02024534.json` complete and dissolved.
4. **`pkt_0202EB14` (46 B code, 56 B extent, Thumb, 1 func)**:
   - `func_0202EB14` (46 B, Thumb): Device status bitfield validator querying `func_0202EB0C` and bits 0 and 5 of `func_02087E60()` (`src/matched/unit_0202EB14.c`). Shard `pkt_0202EB14.json` complete and dissolved.
5. **`pkt_020222A8` (34 B code, 36 B extent, Thumb, 2 funcs)**:
   - `func_020222A8` and `func_020222AA` (34 B, Thumb): ABI parameter home area capture (`push {r0, r1, r2, r3}`) passing pointer `&a` to `func_0207E3D0` and `func_0207E468` (`src/matched/unit_020222A8.c`). Shard `pkt_020222A8.json` complete and dissolved.
6. **`pkt_02008AF0` (24 B code, 36 B extent, Thumb, 1 func)**:
   - `func_02008AF0` (24 B, Thumb): Memory clear via `func_02082AC0(0, obj, 0x5C)` (`MIi_CpuClearFast`) and forwarder to `func_02008B9C((u8 *)obj + 0x10)` (`src/matched/func_02008AF0.c`). Shard `pkt_02008AF0.json` complete and dissolved.
7. **`pkt_020882C0` (16 B code, 16 B extent, ARM, 1 func)**:
   - `func_020882C0` (16 B, ARM): Service loop initialization calling `func_02087988()` and entering `while (1) { func_020882D0(); }` (`src/matched/func_020882C0.c`). Shard `pkt_020882C0.json` complete and dissolved.

### Technical Insights
- Parameter home area pattern (`push {r0..r3}`) in Thumb functions taking address of register argument (`&a`) is cleanly matched via `unit: yes` translation unit wrapping (`unit_020222A8.c`).
- Predicated ARM bitfield mutations (`lsl`, `orr`, `bic`, `str`) with conditional early return are matched with inverted condition testing (`func_0204B604.c`).
- Pipeline scheduling under `-O4,p` requires awareness of load stall fillings when matching register assignments.

---

## [2026-09-16 09:40:00] Wave 8 Handoff Report

### Status Overview
- **Build Status**: `242 PASS, 0 FAIL` across all ROM overlays and ARM9 regions.
- **arm9 Decomp Coverage**: **16.7450%** (66,990 / 400,060 B across 1,636 matched functions).
- **Open Packets**: Reduced from 454 to 449 (5 packets completely dissolved).
- **Progress in Wave**: +188 bytes net, 6 new matched functions.

### Packets Dissolved in Wave 8
1. **`pkt_020344C8` (64 B code, 64 B extent, ARM, 1 func)**:
   - `func_020344C8` (64 B, ARM): Iterates over linked/contiguous node array testing node status with `func_020344C4` (`src/matched/func_020344C8.c`). Shard `pkt_020344C8.json` complete and dissolved.
2. **`pkt_02009590` (56 B code, 56 B extent, Thumb, 1 func)**:
   - `unit_02009590` (56 B, Thumb): Game unit dispatching events via `func_02009584` and checking state with `func_0200856C` (`src/matched/unit_02009590.c`). Shard `pkt_02009590.json` complete and dissolved.
3. **`pkt_02006368` (34 B code, 36 B extent, Thumb, 1 func)**:
   - `func_02006368` (34 B, Thumb): Background task deactivator invoking `func_0208574C()` and updating state via `func_020855BC()` (`src/matched/func_02006368.c`). Shard `pkt_02006368.json` complete and dissolved.
4. **`pkt_0202C124` (18 B code, 20 B extent, Thumb, 2 funcs)**:
   - `func_0202C124` (18 B, Thumb) and reunited sister `func_0202C140`: Heap allocation wrapper delegating to allocator `func_02030734` (`src/matched/func_0202C124.c`). Shard `pkt_0202C124.json` complete and dissolved.
5. **`pkt_020312B4` (16 B code, 16 B extent, ARM, 1 func)**:
   - `func_020312B4` (16 B, ARM): Tail call loading global pointer `g_02146990` and jumping to `func_020313EC` (`src/matched/func_020312B4.c`). Shard `pkt_020312B4.json` complete and dissolved.

### Technical Insights
- Multi-function packets sharing static local state or reunited sister symbols (`pkt_0202C124`) dissolve cleanly once all member routines are matched in the same translation unit.
- Maintained 100% byte-identical ROM hash across all 242 regions.
- Added `scratch/` directory to `.gitignore` to prevent test harnesses and scratch objects from cluttering git working tree.

### Wave 9 Next Steps & Priority Targets
- Priority candidate: `pkt_0204BC94` / `pkt_0204B954` or small ARM/Thumb call wrappers.
- Continue rapid dissolved-packet waves toward the 25.0% coverage milestone.

---

## [2026-09-17 14:35:00] Waves 1-3 Handoff Report

### Status Overview
- **Build Status**: `242 PASS, 0 FAIL` across all ROM overlays and ARM9 regions.
- **arm9 Decomp Coverage**: **19.2944%** (77,284 / 400,552 B across 1,810 matched functions).
- **ROM Verification**: **PASS** (`sha1 26ad0b9967aa279c4a266ee69f52b9b2332399a5`).
- **Open Packets**: 459 packets remaining.

### Recent Progress in Waves 1–3
1. **`pkt_0204A600` (`clact.c`)**:
   - `func_0204A600` (72 B, ARM, `MATCH`), `func_0204A648` (80 B, ARM, `MATCH`), `func_0204A698` (48 B, ARM, `EXACT`) matched in `src/matched/unit_0204A600.c` (`commit 4dc2e80`).
2. **`pkt_02040618` & `pkt_0201D83C`**:
   - `func_0201D83C` (22 B, Thumb, `MATCH*` in `gf_font.c`).
   - `func_020407E8` (28 B, ARM, `EXACT`) and `func_02040804` (28 B, ARM, `EXACT`) matched in `src/matched/unit_02040618.c` (`commit 8328287`, `commit 9992072`, `commit 0291430`).
3. **`pkt_02034AC4` (`gf_overlay.c`, 224 B code, fan-in 114)**:
   - `sub_02034AC4` (224 B, ARM, `MATCH*` in `src/matched/sub_02034AC4.c`): Overlay loader and slot registration manager.
4. **`pkt_02041300` (172 B code, fan-in 224)**:
   - `func_02041300` (172 B, ARM, `MATCH*` in `src/matched/func_02041300.c`): Surface color-depth dispatcher and blitter selector.
5. **`pkt_0204AC18` (`clact.c`, 208 B code, fan-in 129)**:
   - `sub_0204AC18` (208 B, ARM, `MATCH*` in `src/matched/sub_0204AC18.c`): Cell actor system secondary table registration allocator.
6. **`pkt_0203D3F8` (`net.c`, 204 B code, fan-in 88)**:
   - `func_0203D3F8` (204 B, ARM, `MATCH*` in `src/matched/func_0203D3F8.c`): Eight-argument multiplayer network packet transmission handler.

### `eidos` Native Port Alignment
- Landed NSBMD 3D node dictionary, bone matrix hierarchy, shape binding, and host rasteriser additions in `eidos` (`commit 26785a8`). Verified via `python tools/hostbuild.py` (31 text, 44 stats, 49 tcbl checks all PASS with 0 failures).
- Host toolchain configured with GCC 14.2 shim under `aletheia/tools/gcc-host/xpack-mingw-w64-gcc-14.2.0-1/bin/`.
- DeepSeek's NSBMD rotation packing implementation marked provisional in documentation; exact bitwise decoding formula will be derived from `NNS_G3D` matrix evaluation routines in `aletheia`.

### Technical Guidelines & Multi-Agent Collaboration Rules
- **Explicit File Staging**: Always stage explicit file paths (`git add <file1> <file2>...`) to prevent picking up concurrent work across multiple agent lanes. Never use directory-level `git add .`.
- **Relocations & Attestation**: Functions in `src/matched/` require status `EXACT` or `MATCH*` with populated `symbols:` documentation blocks in C source headers.
- **Commit Formatting**: Graduate-level technical prose only; no em-dashes, no emojis, no `Co-Authored-By` footer lines.

---

## [2026-09-17] eidos port session: node dictionary, file layer, 2D/3D stack

All of this is in the `eidos` repository; nothing in this repo changed.

### engine/g3d: MDL0 node dictionary (`eidos` 7673232)

Decoded the node record (active-low presence bits for translation, a packed
or full rotation, and scale), both rotation forms, the parent/child tree in
the render-command section and the per-shape node binding;
`g3d_render_model` now applies each shape's node and ancestor transforms.
Byte evidence is in `eidos/docs/g3d-nodes.md`.

Independently re-verified from the raw bytes, not from the implementation:

- the node record lengths tile exactly to the render-command start in 649 of
  649 `a/0/0/8` models (740 across the corpus);
- the full rotation's stored 12 bytes are orthonormal (21 of 21) and their
  cross product equals `(header, field.y, field.z)` to 1 LSB on 21 of 21
  nodes. The header field is a sign-extended `s16`; reading it unsigned puts
  a third-row x of -3299 at +62237 and fails the check;
- every packed node's two stored components are a unit pair;
- `staffroll_b`'s parent bytes reproduce its named biped exactly
  (pelvis root; head->neck->chest; l_foot->l_shin->l_thigh->pelvis).

### The packed rotation is provisional (`eidos` 26785a8)

The packed form stores only two components. That they are the third row's y
and z, and that the completion is the x-turn, is an assumption, not a decode,
and the documentation says so. Evidence against it: across all 740 models
there are 0 joints packed in one model and full in another (the rotation form
is fixed per joint), so no twin can fix the missing component; and of the 21
full rotations only 2 have `row2.x == 0`, neither with `row0 == (1,0,0)`, so
the zero-roll family the completion assumes is not what the full form uses.

What would settle it is this repo's side: the paired BCA0 joint animation's
frame 0 for a packed joint (the companions exist, `staffroll_b` and
`staffroll_w` in `a/2/2/0`), or the ARM9 routine that expands a node record
into a matrix (the `NNS_G3D` matrix evaluation). The `NNS_G3D` route is a
decompilation target, not a port task.

### Milestone 6 file layer (`eidos` 0ae0a82)

`sdk/vfs.c` owns the data root and an optional mod overlay root and resolves
a NitroFS path through them, overlay first. File granular only: it replaces a
whole NitroFS file, not one member inside a NARC. `tests/test_vfs.c` checks
precedence, fallthrough, trailing separators and clearing the overlay.

### Milestone 4 2D/3D integration (`eidos` 6f8362b)

`G2dLayer3d` puts the 3D output inside `g2d_frame_stack` at a priority and a
hardware layer number, so a 2D BG can sit in front of or behind it, a window
can hide it, and the colour effects blend with a 3D pixel. `g2d` takes a raw
RGBA buffer and does not depend on `g3d`. `tests/test_compose3d.c` checks the
stack, priority, window and blend cases (18 checks).

### Tracking doc (`eidos/docs/status.md`, added in 6f8362b)

Groups the port's work by dependency rather than by milestone: done without
decomp, open without decomp, and blocked on this repo with the blocking
function named. It is the file to update when a status changes.

All eidos tests pass at 14 of 14 in both the LP64 and the ILP32
configuration.

### Not done, for the record

- First-run asset extractor (Milestone 6), still needs a design decision:
  orchestrate aletheia's `tools/` or write a self-contained C unpacker.
- Member-level NARC overlay.
- A DS frame to give the 3D rasteriser an oracle; it is the one engine piece
  with no source of truth in the tree.
- Everything in `eidos/docs/status.md`'s blocked list, which needs this
  repo's decompilation (boot path, heap arena 0x0202FC48, DS sound driver,
  cinematic, gameplay).

---

## [2026-09-17 16:10:00] Wave 4 Handoff Report

### Status Overview
- **Build Status**: `242 PASS, 0 FAIL` across all ROM overlays and ARM9 regions.
- **arm9 Decomp Coverage**: **19.0991%** (76,502 / 400,552 B across 1,807 matched functions).
- **ROM Verification**: **PASS** (`sha1 26ad0b9967aa279c4a266ee69f52b9b2332399a5`).
- **Open Packets**: 464 open packets.

### Graduated & Matched Units in Wave 4
1. **`pkt_020923B0` (`unit_020923B0.c`, 128 B code, 3 funcs, ARM)**:
   - `func_020923B0` (20 B, ARM, `EXACT`): Pointer wrapper for `func_02092430`.
   - `func_020923C4` (44 B, ARM, `EXACT`): `memchr` byte search routine.
   - `func_020923F0` (64 B, ARM, `EXACT`): `memcmp` memory comparison routine.
   - Packet `pkt_020923B0` completely dissolved.
2. **`pkt_02092430` (`func_02092430.c`, 172 B code, 1 func, ARM)**:
   - `func_02092430` (172 B, ARM, `EXACT`): Word-aligned optimized memory fill (`memset`). Shard `pkt_02092430.json` complete and dissolved.

---

## [2026-09-17 17:03:00] Wave 6 Handoff Report

### Status Overview
- **Build Status**: `242 PASS, 0 FAIL` across all ROM overlays and ARM9 regions.
- **Spliced Matched Coverage**: **19.0562%** (76,330 / 400,552 B across 1,803 matched functions).
- **Unspliced Code in `src/pending/`**: **123 C files** (~17,290 B / 4.31% of game code).
- **Combined Code Written**: **~93,620 B (~23.37% total game code decompiled)**.
- **ROM Verification**: **PASS** (`sha1 26ad0b9967aa279c4a266ee69f52b9b2332399a5`).

### Progress & Units in Wave 6
1. **`src/pending/func_0201D83C.c`** (22 B, Thumb) & **`src/pending/func_0201DADC.c`** (20 B, Thumb):
   - Fully written, byte-matching C implementations moved to `src/pending/` to preserve 100% clean build splicing.
2. **`src/pending/unit_02060468.c`** (92 B, ARM):
   - Ring buffer data structure routines (`func_02060468`, `func_02060480`, `func_020604AC`) written and parked in `src/pending/` pending load scheduling alignment.

---

## [2026-09-17] 20 percent push, waves 1 and 2

### Status
- **arm9 Coverage**: 19.7601 -> **20.0457 percent** (79152 -> 80296 of
  400564 game bytes, 1917 -> 1957 matched functions).
- **Build**: `242 PASS, 0 FAIL`; rebuilt ROM byte-identical
  (`sha1 26ad0b9967aa279c4a266ee69f52b9b2332399a5`);
  `manifest --verify` clean; `selftest` 74/74; idiom index unchanged.

### Wave 1 (commit `9947f01`, coverage 19.8061)
Nine EXACT: the paired field stores at 0x02067AA0/0x02067AAC, the field
store at 0x02031288, the tail-call thunks 0x02078C28, 0x02080964,
0x02080B98 and 0x0208EA80, the SVC-stub helper 0x02087AE4 and the poll
loop 0x02084C1C. Seven MATCH-capped near misses were parked in
`src/pending/` with the blocking site named in each header.

### Wave 2 (commit `1dff420`, coverage 20.0457)
- **Blocker unlocks**: 0x020339B4 and 0x02036E80 are now EXACT, which
  promoted the parked 0x0203195C and 0x020370C8 to EXACT. 0x020339B4
  also remains the witness that `src/pending/sub_020331D0.c` waits on.
- **New EXACT**: 24 small ARM accessors and helpers from a scan of the
  open pool for functions with no `bl` and no pool reference (field
  getters/setters, a table indexer, `abs`, linked-list totals, an
  indirect-dispatch shim and a status-register pair updater). The full
  list is in the commit message.
- **MATCH parked**: func_0203386C, func_020364D4, func_0203C900,
  func_02061158, func_02062884, each blocked on one unlabelled or
  single-caller callee.
- **Standards fix**: `src/matched/func_0201F73C.c` was a MATCH-capped
  duplicate of the already-parked `src/pending/func_0201F73C.c`
  (pkt_0201F5BC, a documented near miss on 0x0201F628). The duplicate
  and its `pkt_0201F5DC` shard were removed. The earlier-missing shard
  for the tracked EXACT `unit_02060614` (pkt_02060468) was recorded, so
  it is now counted and spliced.

### Reusable method
The high-yield pattern this wave was: after matching a function, re-run
`match.py one` over every file in `src/pending/` and promote any that
just crossed to EXACT, then pick new targets by scanning the open pool
for no-call/no-pool leaves (`tools/disasm.scan_mnemonics`). Over half
the wave's bytes came from those small accessors.



