# Handoff state (2026-09-16)

Written for whoever picks the project up next, human or agent. Everything below is
reproducible from the repo plus the owner's own ROM dump; nothing here depends on
the previous session's memory.

## Where things stand

- Code: 15.68 percent of ARM9 game code matched byte for byte (1505 labelled
  functions, 62740 of 400048 bytes, `python tools/worklist.py --summary`), plus
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

- `tools/assets/sseqsynth.py`: PSG noise now runs at the channel timer rate
  with the hardware LFSR (carry XORs 0x6000) and mixes at 16-bit scale; the
  noise level relative to PCM (a quarter of full scale) is a chosen constant,
  not attested.
- `gfl_font.dat` glyph order is known from the data (kana 1-166, two digit
  sets at 168-187, capitals 188-213, lowercase 214-239, punctuation 240-259);
  no consumer references the file by name anywhere in the image.
- 51 small tables in `tools/assets/tables.py` have exact framing but no
  attested reader; two levels of register tracing found two more and two
  artifacts (`docs/ASSETS.md`, "Archive readers, second level"). The rest
  reach their open calls through table-driven ids or deeper chains.
- The a/0/0/4 rig detachment (Charizard, Gengar): `rig.py` now applies the
  attested flip and double-size rules; the before/after comparison was not
  reported. Render species 6 and 94 and check.
- `src/pending/` holds byte-correct files blocked on a witness; each header
  names the blocker.
- Tooling: `attest_string` should accept tab, newline and carriage return
  inside a preceding printable run; `disasm.py` does not index a literal pool
  inside a `.byte` run of unlabelled leaves; `match.py show` needs `--region`
  for overlay addresses.

Pokémon White is the planned second target; every tool is parameterised by the
extracted layout, so the work is a second `extract/` plus per-target layout files.
