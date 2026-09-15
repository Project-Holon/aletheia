# Handoff state (2026-09-16)

Written for whoever picks the project up next, human or agent. Everything below is
reproducible from the repo plus the owner's own ROM dump; nothing here depends on
the previous session's memory.

## Where things stand

- Code: 15.79 percent of ARM9 game code matched byte for byte (1510 labelled
  functions, 63180 of 400048 bytes, `python tools/worklist.py --summary`), plus
  matched functions in overlays ov010 and ov021 that the summary does not count.
  Every matched function is spliced into the build and the rebuilt ROM is
  byte-identical (sha1 26ad0b9967aa279c4a266ee69f52b9b2332399a5).
- Assets: every one of the 247 NitroFS files is identified and decodes and
  repacks byte-identically with the tools under `tools/assets/`
  (`python tools/assets/verify_all.py` reports 0 failures; custom formats are
  handled by their own tools, see the coverage census in `docs/ASSETS.md`).
  The world data chain (zone header, scripts, matrices, map models, terrain
  records, event data, encounters) and the core data tables (personal, moves,
  items, learnsets, evolutions, egg moves, cries) are field-mapped from our own
  decompiled readers. Both script VMs (field and battle effect) disassemble.

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
  with the hardware LFSR (carry XORs 0x6000) and mixes at 16-bit scale; the
  noise level relative to PCM (a quarter of full scale) corresponds to the
  standard hardware volume divider (SOUNDxCNT div4 / 25%) used by DS PSG channels.
- `gfl_font.dat`: identified as NitroFS root File ID 237 (`0x00ED`), Game Freak
  Library internal monospaced/debug font (`GFL_` prefix, matching `gfl_use.c` at
  0x020A7004). Glyph mapping (kana 1-166, digits 168-187, capitals 188-213,
  lowercase 214-239, punctuation 240-259) verified 288/288 glyph records byte-identical.
- 51 small tables in `tools/assets/tables.py`: verified 8,217/8,217 records
  round-trip byte-identical across all 86 registered archives. Readers for 15+
  archives identified via register tracing (`fieldmap.c`, `poke_tool.c`, etc.);
  remaining unmapped tables have exact framing and zero byte diffs on round trip.
- The a/0/0/4 rig detachment (Charizard, Gengar): VERIFIED. Species 6 and 94
  rendered with `rig.py --pose` and `--anim`; all limbs, wings, and facial cells
  remain attached and properly aligned under the flip and double-size compositor rules.
- `src/pending/` holds byte-correct files blocked on a witness; each header
  names the blocker.
- Tooling: `attest_string` should accept tab, newline and carriage return
  inside a preceding printable run; `disasm.py` does not index a literal pool
  inside a `.byte` run of unlabelled leaves; `match.py show` needs `--region`
  for overlay addresses.

Pokémon White is the planned second target; every tool is parameterised by the
extracted layout, so the work is a second `extract/` plus per-target layout files.

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

