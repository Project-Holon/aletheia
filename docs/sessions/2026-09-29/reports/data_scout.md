# data_scout: typing the code-section data (scouting report)

Read-only scout, 2026-09-29. Addresses, sizes, counts and category names only; no game bytes.
Scripts lived in the session scratchpad (a listing parser plus a shape classifier), not in the repo.

## Summary

- The data that is genuinely standalone in code sections is small: 340,772 B in the image
  (ARM9 50,700 B + 237 overlays 290,044 B + ITCM 28 B), about 7,000 objects, plus 918,208 B of
  .bss (ARM9 697,408 B, overlays 220,800 B). The NitroFS holds 198,008,820 B in 247 files, so code-section
  data is about 0.17% of the game's file bytes.
- The headline "data" figure in listing headers (ARM9 0x22254 = 139,860 B; overlays about 877 KB) is mostly
  not data. Literal pools and function-internal switch tables plus unreached case bodies make up most of it,
  and matched C already reproduces those as part of each function extent.
- A byte-exact typed-data build is feasible but is a tooling project first: match.py and csrc.py handle code
  sections only. Estimate: 2 to 3 waves of tooling, then about 5 to 8 waves of mostly mechanical lanes for
  strings, zero runs, bss, simple tables and pointer tables. Roughly 100 KB of mixed and high-entropy data is
  the hard tail.

## 1. Quantity

Method: parsed every listing (asm/arm9/main.s, itcm.s, asm/overlays/ov000..ov236) line by line. Address comes
from the `/* ADDR */` comments or `.org`; a `.word` under a `pool_XXXXXXXX:` label is a literal pool word; any
other `.word`/`.byte` is "data"; lines with instruction bytes are code. Code totals reproduce the listing
headers exactly (ARM9 539,692 B code, 139,860 B non-code). Runs = consecutive non-pool data lines.
"Tail" = data runs starting after the last code byte of the region (where rodata/data/tables sit).
"Interleaved" = data runs before the last code byte.

| region | image B | code B | pool B (pool_ labels) | non-pool data B | tail B | interleaved B | .bss B (not in image) |
|---|---:|---:|---:|---:|---:|---:|---:|
| arm9 main | 679,552 | 539,692 | 22,148 | 117,712 | 50,700 | 67,012 | 697,408 |
| itcm | 2,080 | 1,826 | 124 | 130 | 28 | 102 | 0 |
| 237 overlays | 3,256,320 | 2,379,630 | 107,148 | 769,542 | 290,044 | 479,498 | 220,800 |

ARM9 tail is 0x0209D86C..0x020A9E80. Runs: ARM9 1,984, overlays 15,978. .data vs .rodata are not
distinguishable from the listing (no section directives; a single `.text.arm9_main`), so they are reported
together as "initialised data"; .bss comes from the listing headers (`bss A..B`). Note datascan reports
15,788 B pool-owned over 1,971 runs for ARM9, versus 22,148 B for pool_-labelled words here (about 6.4 KB
difference, presumably labelled words datascan treats as data-referenced); the tail figure is not affected.

Why interleaved data is not standalone: ARM9 has 67,012 B interleaved. The four largest interleaved runs
(0x0203DCA8, 0x02056AA0, 0x02032D08, 0x02099D6C, 0.8 to 1.9 KB each) each follow `addls pc, pc, r0, lsl #2`
plus a `b`; another (0x020193D4) follows a Thumb `add pc, r0` halfword table. That is a switch dispatch whose
branch slots and case bodies the disassembler emitted as words. The matcher's extent rule (function extent =
distance to the next label, match.target_extent) puts those bytes inside matched functions (ARM9 is at 100%
matched). For overlays, a code-signature heuristic (BL pairs plus push/pop-lr density) flags about 65% of the
479 KB interleaved as Thumb-code-like (about 314 KB; calibrated against ARM9, where the same heuristic
overflags 11 to 17 KB, so treat as +/-10%). So the overlay interleaved figure is unreached code and switch
tables, not data. Typing should start from the tail only. Caveat: an overlay whose last function was never
found puts trailing code in "tail"; only 2.6% of tail bytes (8.8 KB, 2 objects) look code-like, mostly one
8 KB high-entropy ARM9 table that the heuristic misflags.

Top 20 regions by non-pool data size (data = tail + interleaved; tail is the standalone part):

| region | image B | data B | tail B | bss B |
|---|---:|---:|---:|---:|
| arm9 | 679,552 | 117,712 | 50,700 | 697,408 |
| ov021 | 354,304 | 81,332 | 45,168 | 65,600 |
| ov093 | 252,448 | 59,662 | 15,848 | 10,816 |
| ov009 | 340,224 | 54,614 | 20,064 | 26,816 |
| ov010 | 121,408 | 33,818 | 7,402 | 32 |
| ov175 | 67,904 | 32,818 | 7,960 | 2,240 |
| ov016 | 155,456 | 31,738 | 12,676 | 9,920 |
| ov170 | 84,960 | 25,326 | 7,344 | 0 |
| ov172 | 75,744 | 24,114 | 3,186 | 15,456 |
| ov203 | 25,408 | 17,548 | 16,964 | 0 |
| ov094 | 84,416 | 15,964 | 4,664 | 32 |
| ov110 | 42,784 | 15,368 | 9,332 | 0 |
| ov018 | 36,160 | 14,900 | 1,730 | 0 |
| ov121 | 38,304 | 14,826 | 1,818 | 32 |
| ov095 | 26,560 | 14,550 | 4,590 | 448 |
| ov114 | 91,072 | 13,464 | 7,556 | 18,656 |
| ov019 | 23,040 | 12,008 | 2,110 | 0 |
| ov208 | 52,288 | 11,952 | 3,490 | 0 |
| ov183 | 34,528 | 11,850 | 1,880 | 0 |
| ov135 | 64,000 | 10,452 | 5,078 | 32 |

Ranked by tail alone: arm9, ov021, ov009, ov203, ov093, ov016, ov110, ov175, ov114, ov010, ov170, ov099
(5,736), ov135, ov217 (4,716), ov094. Largest .bss besides ARM9: ov021 65,600, ov119 49,184, ov009 26,816,
ov114 18,656, ov172 15,456.

Object counts (boundaries from: run starts, pool-word targets inside runs, and for ARM9 the 1,529 rows of
layout/data_objects.txt): 6,979 objects in the tail (ARM9 911, overlays 6,067, ITCM 1); 22,317 if interleaved
runs are included (not meaningful). It is a lower bound: unreferenced or base+offset-accessed interior objects
merge. The listings carry no per-object labels (one `d_` label in ARM9, 5,537 `pool_` labels); data_objects.txt
is the only object map (ARM9: 1,090 pool, 347 string, 35 table-guess, 2 data-decl, 1 range rows, 342 of them
in .bss). Tail objects by size: <=16 B 3,776 (35.7 KB), <=64 B 2,482 (83.4 KB), <=256 B 545 (66.7 KB),
<=1 KB 144 (68.8 KB), >1 KB 32 (86.2 KB).

## 2. Shape

Method: every tail object (not a sample; 6,979 objects, 340,772 B) was classified from bytes plus listing
annotations, first match wins: all-zero; string (printable runs cover >=90% incl. NULs, >=35% printable, has
NUL); size%4==0 and >=50% of words in 0x02000000..0x021FFFFF (or 0x01FF8xxx / 0x02FExxxx) = pointer table,
and if the listing annotates `-> func_X` or the words carry the Thumb bit = function/jump table; 20% to 50%
pointer words = mixed struct with pointers; stride test (2..64 B, >=50% of byte columns have a >=60% dominant
value) = fixed-stride numeric table; <=16 B = small misc; the rest "binary/mixed". Weakness: boundaries merge
neighbours, and a byte-column test cannot see 32-bit fields with many distinct values, so "binary/mixed" is an
upper bound.

Tail, by bytes (all regions, 340,772 B):

| class | bytes | share | objects |
|---|---:|---:|---:|
| fixed-stride numeric tables | 146,023 | 42.9% | 1,751 |
| binary/mixed, no stride found | 62,913 | 18.5% | 214 |
| strings (NUL-terminated printable) | 46,507 | 13.6% | 1,987 |
| function/jump/handler pointer tables | 34,332 | 10.1% | 830 |
| mixed structs containing pointers | 16,920 | 5.0% | 128 |
| small misc (<=16 B) | 11,828 | 3.5% | 1,583 |
| data pointer tables | 9,856 | 2.9% | 152 |
| code-like (probably false positive, see above) | 8,768 | 2.6% | 2 |
| zero-filled | 3,625 | 1.1% | 332 |

ARM9 tail alone (50,700 B): binary/mixed 42.8% (mostly high-entropy blocks of 0.5 to 4.7 KB with nearly every
byte nonzero, consistent with SDK crypto/CRC/lookup tables or font data), numeric stride 17.1%, code-like 16.4%
(the one 8 KB high-entropy table, misflagged), strings 11.4% (457 objects), function tables 4.5%, pointer
tables 3.0%, mixed-with-pointers 2.4%. Overlay tails (290,044 B): numeric 47.0%, binary 14.1%, strings 14.0%
(1,530 objects), function/handler tables 11.1% (789 objects), mixed-with-pointers 5.4%, data pointer tables
2.9%, zero 1.2%. The biggest known function table is the 609-entry field script command handler table in ov010
(docs/ASSETS.md).

Hard-to-type share: pointer tables, function tables and mixed pointer structs 18% of tail bytes (about 61 KB,
1,110 objects); binary/mixed 18.5% (63 KB, 214 objects); everything else (numeric, strings, zero, small) about
63% (215 KB, about 5,650 objects).

## 3. Where the moddable game data lives

The repo knows (docs/ASSETS.md, tools/assets/*.py): 247 NitroFS files (198 MB), 237 NARCs with 54,054
sub-files, plus the sound SDAT. Decoders exist for, all NARC-resident: species personal data (a/0/1/6), level-up
learnsets (a/0/1/8), evolutions (a/0/1/9), move data (a/0/2/1), item data (a/0/2/4), wild encounters (a/1/2/6),
zone headers (a/0/1/2), trainer data, text banks, field scripts (a/0/5/7), maps, models, sprites and audio. So
essentially all gameplay tables people mod (species stats, moves, items, learnsets, evolutions, encounters,
trainers, text, scripts, maps, sprites) are in the filesystem and already readable. Code-section data is about
0.17% of file bytes (340 KB vs 198 MB); I would put the code-resident share of "interesting for modding" tables
well under 5% by count (confidence: medium-high, from the docs' table inventory).

Kinds of tables that do sit in code sections (names only, inferred from shape and the docs; not decoded):
dispatch and handler tables (field script command handlers, battle/effect VM handlers, state-machine and
overlay-entry function tables), per-state and per-menu function pointer arrays, source-file-name and assertion
strings (the `__FILE__` pool; layout/file_anchors.txt has 1,026 such anchors), archive-id and file-id lookup
arrays used by the NARC loaders, small per-species or per-form correction and mapping arrays (docs/ASSETS.md
mentions one in ARM9 code), UI/layout descriptors and window/OAM/BG init structs (mixed structs with pointers),
animation and step tables, fixed-point and lookup tables, and SDK library data (CRC, crypto, hash tables in
vendor objects). The mod-relevant subset is the pointer-and-handler part (script commands, battle effects,
state tables) rather than numbers.

## 4. Current tooling: what exists and what is missing

- tools/build.py assembles asm/ listings (`.word`/`.byte` verbatim, `.org`-pinned), links at the region
  address, and splices verified C bytes over code ranges. Data is always reproduced from the listing, so it is
  byte-identical by construction and no C is involved.
- tools/csrc.py `Splice` = (region, offset, bytes) built only from compiled function or whole-TU code.
  tools/match.py `layout_tu()` lays out only PROGBITS sections with SHF_EXECINSTR (CodeWarrior emits one
  section per function, aligned to 4, zero-filled gaps); `tu` mode compares a code-only image via
  `resolve_relocations()`. Non-executable sections (.rodata/.data/.sdata) and .bss (NOBITS) are never read.
  `extract_function()` collects `@N` anonymous initializer templates only as evidence for a relocation rule,
  not as placed data.
- How matched C references data today: extern `g_XXXXXXXX` names with `symbols:` header lines
  (`name 0xADDR data [aN] [ovNNN]`), parsed by `declared_symbols()`. Whether the address is legitimate is
  decided by evidence classes in match.py (`attest_string`, `attest_data_table`, `attest_sole_ref_data`,
  overlay variants, `bss_addresses_probe`, `data_object_map`). They check that an address is a plausible object
  start (string boundary, pool-word witness, declared bss range, sole reference); they never verify an object's
  contents. Corpus: 16,849 matched C files declare 3,228 distinct (region, address) data symbols, 841 of them
  ARM9 (505 in the tail, 302 in .bss, 34 below the tail). 927 of the 3,228 are declared in two or more files
  (386 in four or more, maximum 52), each with its own ad-hoc local type (e.g. structs with `pad0` fillers), so
  no per-object type unification exists yet.
- SDK data: vendor DWARF exists for SDK objects (tools/sdkobj.py) and the vendor archives contain the
  .rodata/.data sections themselves, so SDK-owned data could be placed from vendor object bytes without writing
  C. layout/symbols_sdk.json lists functions only, no data symbols.
- layout/data_objects.txt (tools/datamap.py) is the only object map: starts only, no sizes, types, section
  (rodata/data) or TU owner; `table-guess` rows are documented as heuristic.
- There is no `port/` directory in this repo (eidos is the companion repo), so the port-side consumer is not
  measurable here.

Missing for a data-in-C build:
1. Section model: which bytes are .rodata, .data, .sdata-like, .bss. Not in the listings; needs ARM9 header,
   autoload and static-initialiser info plus write/const-usage evidence. Also the original mwld ordering (per
   TU, in link order) and per-object alignment and padding.
2. A data TU layout: extend `layout_tu` to non-exec sections, apply the fill rule between objects, compare
   object by object at fixed addresses. MWCC's rules for `const` placement, string literal pooling and dedup
   inside a TU (order of first use), and zero-initialised statics landing in .bss must be reproduced; this is
   where per-object surprises will appear.
3. Relocations inside data: every ABS32 word in a pointer or function table needs a named target. Function
   targets already have `func_XXXXXXXX` labels and the Thumb bit; data targets need registry names. With both
   endpoints defined objects, the independent-witness rule can become "target is a registered object at that
   address and ISA", simpler than the current evidence classes. Cross-TU references need one global symbol map
   (name to address) emitted from a registry.
4. A verifier: per-object EXACT/MATCH result recorded in shards next to layout/matched, with csrc's
   never-fall-back splice semantics. Sizes and boundaries must come from the registry, not datamap heuristics.
5. Name and type recovery. There is no debug info for game data. Types can come only from consumer code
   (strides and field offsets in matched C, the 3,228 declared symbols), pointer-target kinds, and string/zero
   patterns. The bytes are the ground truth (a struct is right if it round-trips); naming stays manual.
6. Policy: LEGAL.md says src/ is unlicensed derived source and that "no extracted archives, converted assets,
   disassembly listings" are distributed. Table initialisers in C are game data content. Either treat them like
   the rest of src/ (owner decision), or commit only registry, types and a generator and emit the initialisers
   from the user's ROM at build time (still byte-identical and consistent with "no game data in the repo", but
   not human-editable source).

## 5. Difficulty and plan

Effort classes (bytes are tail-only; "lane" = one Opus/Sonnet lane of the current wave pattern):

| class | bytes | objects | difficulty | rough effort after tooling |
|---|---:|---:|---|---|
| zero-filled runs, .bss objects | 3.6 KB tail; 918 KB .bss | 332; 342 ARM9 rows plus overlay rows | easy; .bss needs sizes and order from access evidence | 1 Sonnet lane per 3 to 4 overlays; ARM9 .bss 1 Opus lane |
| strings | 46.5 KB | 1,987 | easy, mechanical; per-TU pooling/order is the only risk | 2 Sonnet lanes |
| plain fixed-stride numeric tables | 146 KB | 1,751 | easy to medium; bytes are cheap, types (field widths, signedness, struct vs array) need consumer code | 5 to 6 Sonnet lanes; unify types via the 927 multi-declared symbols |
| function/jump/handler tables | 34 KB | 830 | medium; targets already labelled, mostly generatable; ISA bit and order must match | 2 lanes plus a generator |
| data pointer tables, mixed pointer structs | 27 KB | 280 | hard; each target must be a registered object; data shared across units | 2 to 3 Opus lanes |
| binary/mixed, no stride | 63 KB | 214 | hard; likely SDK or font/curve tables: SDK via vendor object bytes, rest needs consumer analysis | 2 Opus lanes; expect a residual of raw byte arrays |
| small misc (<=16 B) | 11.8 KB | 1,583 | easy but noisy (padding, single flags) | fold into neighbouring objects |

Staged plan:
- Stage 0 (decision, no work): settle item 6 above and the denominator (proposal: tail data plus .bss,
  excluding literal pools, function-internal switch tables and unreached case bodies, all already counted by
  function C). Adding a data row to the coverage figures moves them, so flag it first.
- Stage 1 (tooling, 2 to 3 waves, mostly Opus): data object registry (JSON: start, size, section, align, name,
  type, owner region/TU, SDK or game) replacing the guess-level parts of data_objects.txt; data TU layout in
  match.py (non-exec sections, fill, .bss sizing); relocation resolution against the registry; csrc/build data
  splice; shards and `manifest --verify` rows; selftest; end-to-end pilot on one overlay (ov203: 16,964 B tail,
  no bss, 55 runs).
- Stage 2 (ARM9 tail, 50.7 KB, about 911 objects, 1 to 2 waves): strings first (457 objects), then the largest
  tables; postpone SDK blobs and place them from vendor bytes.
- Stage 3 (overlays by tail size, 290 KB, 3 to 4 waves): ov021, ov009, ov093, ov016, ov110, ov175, ov114, ov010,
  ov170 first (about 130 KB together); generate function tables; type numeric tables from consumer code.
- Stage 4 (.bss, 918 KB, about 2 waves): mostly naming and sizing addresses that matched C already uses (302 ARM9
  bss symbols declared today); large buffers are cheap, dense small state structs are the work.
- Stage 5 (residual: unknown structs, SDK blobs): typed byte arrays plus a size/round-trip proof.

Total about 8 to 11 waves at the eight-lane cadence; waves 1 to 3 decide whether the MWCC section rules are
tractable. Biggest risks: (a) MWCC .rodata/.data placement and string pooling per TU may not reproduce the
observed order without the true TU boundaries (units_arm9.json has only 32 coarse splits, not compiler TUs);
(b) no section split in the listings; (c) shared data with unknown owner TU (386 symbols declared four or more
times); (d) heuristic object boundaries.

What it unlocks:
- Modding: the large gameplay tables are already outside the code, so this does not unlock stat, move or
  encounter editing (tools/assets covers that). It unlocks code-side modding: adding script commands, battle
  effects and menu states (handler and dispatch tables become growable arrays) and, with matched functions, a
  relinkable build where addresses can shift instead of fixed-address patches. Today any inserted code or data
  breaks every hard-coded `g_XXXXXXXX` address.
- Native port (eidos): matched C uses `extern g_XXXXXXXX` at DS addresses, which a native build cannot honour.
  Named typed data objects give real globals, pointer tables holding real function addresses, and .bss as
  ordinary zero-initialised storage. Without them the port needs a DS-address shim for every data reference
  (3,228 symbols today).
