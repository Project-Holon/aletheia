# Restructure report (2026-10-10, after round 10)

Handoff for the next session. Goal of this phase: rebuild `src/game/` as the
original source files (one `.c` per translation unit, TU). `src/matched/` stays the
frozen per-function record. Renaming functions is a later, separate step.

## Where it stands

TUs that are one file (file counts from `split_tus.tsv`; estimate 1816 TUs):

| Area | Whole | Percent |
|---|---|---|
| ARM9 | 376 / 406 | 92.6% |
| Overlays | 1229 / 1325 | 92.8% |
| twl | 80 / 82 | 97.6% |
| ITCM | 2 / 3 | 66.7% |
| **Total** | **1687 / 1816** | **92.9%** |

Denominator change in round 6 (+7 TUs): arm9 `unit_02004F94.c` and `unit_02004FD4.c`
(crt0 helpers copied to WRAM, data words around them; their own units like the
other crt0 pieces), arm9 `textprint.c` split out of clact on the game's own
`__FILE__` string (`layout/file_anchors.txt`), and 4 new twl files
(`unit_0273034C.c`, `unit_02702A8C.c`, `unit_02705320.c`, `unit_02702D68.c`) made
separate because their neighbours are still empty asm stand-ins; fold them back
when those become real code. (Round 5 listed 164 split TUs; the recount finds 165
at that commit: ov093 unit_021EFC1C was missed.)

Checks at this commit:
- `python tools/gameverify.py`: 2480 files, all EXACT or MATCH except
  `arm9/unit_020911D4_p09.c` and `_p11.c` (compiler runtime pieces that are not
  contiguous in the image: every function is EXACT with `match.py one`, the TU
  compare cannot line up).
- `python tools/gamecheck.py`: 35511 functions present, 0 missing, 0 doubled.
- 7 files are MATCH (list: `match_files.txt`; was 120 before rounds 6 to 8).
  Every function in them is EXACT on its own; no function is MATCH in
  `layout/matched`. What is left references the 13 hidden functions that could
  not be filed (below) or targets with no outside witness.
- Header `status:` equals the TU verdict everywhere (EXACT* kept where the
  per-function verdict is EXACT*).
- `python tools/match.py selftest`: 329 cases, 0 failures.

Tooling changes in rounds 6 to 8 (so merges keep their evidence):
- `match.py` `SYMBOL_SHAPE_RE` ended in a literal backspace byte instead of ``,
  so a malformed symbols row silently ended the block and hid every later row.
  Fixed; 57 headers with such rows repaired (130 `code` kinds in src/game, 54 in
  src/matched twl/twl_sdk, prose inside blocks); all 56 src/matched entries still
  EXACT/EXACT*. A malformed row now stops the check loudly.
- `restructure.py` validates every row it writes (`fix_symbol_row`).
- New `tools/gamesyms.py`: lints symbols blocks and restores rows lost in a merge
  from the members' src/matched headers (keeps a change only if the verdict is
  equal or better). `gameverify.py` runs the lint first and counts MATCH.
- `match.py`: a hint naming the site's own overlay is treated like no hint (the
  own-window rule decides); it was stricter than no hint before.
- `match.py` whole-file checks: new `member` class (`member_pass()`, run only in
  `run_tu`). A site of a merged file that the per-function rules leave open is
  accepted when it lies in member function F, F has an EXACT/EXACT* entry in
  layout/matched with a src/matched source (not the file under test), F's own
  compile resolves the same field (same offset in F, same relocation type, same
  addend for branches) to value V, a value the file computes itself equals V, and
  the original bytes equal the field written from V. This adapts the evidence
  rule to the file as the unit: per-function rules only looked at the first
  member (vendor objects, `@N` templates, `.bss`/`.data` rows). 9 selftest cases.

Coverage (`python tools/worklist.py --summary`, `python tools/coveragemap.py`):
ARM9 100% (412048 / 412048 bytes), overlays 99.9766% exact game (one open
function: ov013 0x021B3084, 6 bytes off), twl 100%. Unchanged this round: the
twl stand-ins replaced with real code were already counted, and hidden
functions written into `src/game` are not counted (see "Coverage caveats").

## History of the restructure

| Round | Lanes | Result |
|---|---|---|
| Claude Code (2026-10-06/07) | 114 (ARM9 21, overlay batches 57, unbatched 4, round 2 x24, support 8) | 50% |
| Round 2 relaunch (opencode, Sonnet) | 9 | r2 lanes that died at the usage limit finished |
| `tools/gamepromote.py` | tool | 538 one-member TU folders moved up to `<tu>.c` |
| Round 3 | 18 | 86.5% |
| Round 4 | 19 | 89.6% (pushed afe8c8d40) |
| Round 5 | 19 | 90.9% (pushed 2a101b314) |
| Round 6 (Claude Code, Sonnet, max 4 at once) | 8 | 91.1%: 178 hidden functions filled (strong gamegaps rows 190 -> 14), 4 TUs closed, 10 TUs reduced |
| Tooling wave (symbols rows, shape regex, `member` rule) | 6 | MATCH files 120 -> 13 |
| Round 7 | 4 | 91.5%: ov021 fldeff_splash, fldeff_namipoke, field_g3dobj, field_ground_anime, ircbattlemenu; ov010 scrcmd_musical, game_beacon_search whole |
| Round 8 | 4 | 92.0%: ov021 pdw_postman, fld3d_ci, field_place_name; ov013 unit_021B0D18, unit_021B1498; ov095 unit_06898BFC, ov056 unit_021F36C0, ov106 irc_ranking whole |
| Filing | 3 | 756 hidden functions filed into src/matched and the layout; MATCH files 13 -> 7 |
| Round 9 | 4 | 92.5%: ov021 field_wfbc, ov013 unit_021B23E0, ov010 fldmmdl, ov102/103/105 unit_021B7560, ov018 intrude_field, intrude_subdisp, ov019 union_oneself, ov121 mystery_util whole |
| Round 10 | 4 | 92.9%: ov021 weather_task, fldmmdl_blact; arm9 net_err, unit_02083644, unit_020643CC, unit_0206EB7C, unit_0207312C whole; ov021 field_effect 17 -> 2 (p02 is a second entry label inside func_021A8E10, final) |

Subagents in opencode use `.opencode/agents/lane.md` (model
`anthropic/claude-sonnet-5-5`, not committed; it is local opencode config).

## Levers that worked (keep using)

Full list in `LANE_BRIEF.md` (the lane instructions, copied from the scratchpad).
- **Compiler boundaries are often not real.** A part headed 1.1p1 often builds EXACT
  under its neighbour's compiler (`../2.0/sp2`, `sp1p2`, `1.2`). Test each part once
  under the neighbour's settings, retag, merge. Closed about 30 TUs in rounds 4/5.
  Note: this is an attribution choice when both compilers give the same bytes.
  `compiler: 1.1p1` and `dsi/1.1p1` are the same compiler.
- **Wide caller, narrow callee:** make the caller's own parameter or local narrow
  (`u16 heap`, `short delta`, `u8 idx`) so no narrowing is emitted at the call.
- **One canonical struct per object, by offset**, in every part, then merge.
  Shared headers created: `ov009/wcm_types.h`, `ov009/qr2_types.h`,
  `ov114/ghttp_types.h`, `ov114/nhttp_types.h`, `ov107/mb_wm.h`.
- **Uncovered code between parts is usually plain C:** `return g(a, k);` tail
  stubs, `void f(void) {}` leaves, setters `int *f(int *p){*p=N; return d_Y;}`.
  Write them as hidden functions, verify, inject.
- Prose lines in a header shaped like symbol rows end the symbols block and turn
  EXACT into MATCH: reword them.

## Open work

### 1. Unmatched code (priority)
`tools/gamegaps.py` (new) lists code bytes that no `src/game` function compiles.
Current report: `gamegaps.tsv` / `gamegaps_summary.txt` in this folder.
- 2026-10-10: twl 0x027315E0 (power-off sequence), ov132 0x021FD4D0, ov175
  0x021DFA98, ov210 0x021C06F8 now EXACT. Still open: ov013 0x021B3084 (6 B
  off), ov039 0x021F36FC (18 B off, spill order), ov070 0x021B86B8 (4 B short),
  the twl stand-ins below. Drafts in the session scratchpad r9/uncov/.
- After round 6: 12 strong hidden pieces, 1948 bytes (was 190 pieces). They are:
  ov009 0x0217EA58/64/70, three plain ARM veneers
  (`ldr ip,[pc]; bx ip`) that gamegaps misclassifies as leaves (veneers are not
  work; tool fix: recognise this form); twl 0x027315E0 (312 B, draft 8 bytes off,
  `scratchpad r6/gmisc/d19.txt`); ov039, ov070, ov095 x2 (below); ov132
  0x021FD4D0 (40 B), ov175 0x021DFA98 (8 B), ov210 0x021C06F8 (4 B), ov230
  0x02189954 (encrypted view).
- Round 6 found 8 "labeled" strong rows that are K&R definitions gamegaps cannot
  parse (ov021 0x02198E44, 0x02198E60, 0x0219A528, 0x0219BF60, 0x0219C0D4,
  0x021A0EE4; ov010 0x0216E51C; ov016 0x021B979C is a static). Tool fix: read
  K&R definitions and statics.
- Largest pieces: ov039 0x021F36FC (824 B; draft 18 bytes off, only spill-slot
  order, `scratchpad r5g01/ov039_func_021F36FC_best18.c`, see the TU's MERGE.md),
  ov070 0x021B86B8 (588 B, not decoded), ov013 0x021B3084 (460 B, the last
  unmatched game function, notes in `src/pending/ov/ov013_func_021B3084.c` pass 7:
  the original needs one extra non-emitting node after `str thr`), ov230 several
  (decrypted view, numbers not clean), twl 0x027315E0 (312 B). Done in round 6:
  ov107 0x021F1230 (320 B, mb_comm_sys now one file).
- Parked `volatile` matches (2026-10-09, not applied: no plausible reason in the
  original source; review later; notes in each TU's MERGE.md): ov095
  unit_0689CB3C leaves 0x0689CCB4 / 0x0689CCF8 match only with the loop bound
  read as `*(volatile u8 *)&p->n`; ov088 startmenu p01|p02 merges only with
  `volatile u8 bg` on func_021BBB84.
- **twl stand-ins** (empty `asm void f(void) {}` that report EXACT without byte
  compare): still 13 in unit_0272E9E8 (func_0272EA74, EC38, EE98, EFB0, F0BC, F368,
  F570, F740, F8A8, F9C4, FE54, FEF4, FFC8) and 4 in unit_02731718 (027323A8,
  02732944, 02732A64/02732A70, which look like one function). Done this round:
  all 29 of unit_0273042C, func_02701AA0, func_02731AF0, and 3 in unit_0272E9E8
  (`src/matched/twl*`, shard `twl_sys` re-verified).

### 2. TUs still split (129)
List with piece counts: `split_tus.tsv` (columns: region, tu, parts, folder
members). Each TU folder has a `MERGE.md` with its blockers. Not reached yet:
ov021 field_effect, field_wfbc, weather_task (30), fldmmdl_blact (14), fld_trade
(4); ov010 comm_player, event_field_proclink, eventdata_system,
musical_dressup_sys, scrcmd_proc, script_work, symbol_map, fldmmdl; ov013
unit_021B23E0 (Pool/N plan in MERGE.md); ov018 intrude_field, intrude_subdisp;
ov019 union_oneself; arm9 net_state and the struct-view arm9 TUs; ov135, ov194,
ov198, ov208, ov218, ov172 ctvt_draw, ov121 mystery_util. ov102/103/105
unit_021B7560 were blocked by the data-witness rule only: retry with the `member`
rule. Biggest: ov093 btl_server (131 parts, 114 real veneers; 16 non-veneer
boundaries listed), arm9 net_state (56; g_021469D4/D8/DC/E0/F0 structs not
started), ov009 unit_021573C4 (34), ov172 camera_system (31, strictly alternating
ARM/Thumb: real), ov021 weather_task (32), fldmmdl_blact (24), ov009 unit_0216F014
(23, DWCstMatchControl family needs one shared header), ov009 unit_0215FDA4 (18),
field_effect (19), ov208 zukan_detail_graphic (14), arm9 unit_020911D4 (16),
unit_02064D70 (15), clact (13). About 80 to 100 of the 164 are real boundaries
(veneers, ARM/Thumb, compiler, SDK stand-ins), so the ceiling is roughly 93 to 95%.

### 3. Readability debt (from lane reports)
- Calls through `((void *(*)())f)(...)` to get a call with no prototype in view
  (the original had an implicit declaration of a callee defined later with
  narrow parameters; -lang c99 forbids implicit declarations): ov010
  script_work_p02, symbol_map_p01, ov121 mystery_util. Cleaner option: build
  those files without c99 if the bytes stay, and drop the casts.
- Hidden functions written after the filing are only in src/game: ov021
  field_effect 0x021AB474, 0x021AB490, 0x021AB4A4 (plus the 13 that could not be
  filed). File them the same way.
- Per-part renamed typedefs instead of one struct: ov135 worldtrade_adapter
  (`Work_vXXXX`), ov072 townmap (`W_*`, `Pos_*`), ov217 research_top
  (`S_021BC8E4`...), dwc_rap_p01 (one renamed view), ov009 unit_0217956C
  (`DWCHttp_*` per view, raw `http + 0x1a34`).
- `u8 *` offset access left: ov136 mb_seq func_021C6E18, ov208 zukan_detail_form
  p02..p04 (`W()`/`H()` macros), union_comm p07, arm9 net_state vtable calls.
- Raw function addresses: ov120 gtsnego_disp (`0x021D4FF5`, `0x021D4931`).
- K&R definitions and unprototyped externs used where callers disagree (listed in
  the MERGE.md files and lane notes).
- Invented field names everywhere (by offset); names are for the renaming phase.

### 4. Caveats and decisions to review
- Resolved (2026-10-09): lane r2_02 dropped the region word from 9 contested ov093
  data symbol rows, which turned MATCH into EXACT. This does not weaken the
  witness rule. In `match._overlay_pool()` the site's own overlay fixes the
  address whenever its window holds it, with or without a hint (overlays sharing a
  window are never resident together). The "contested" refusal is only applied
  when a hint is present (`self_hint_accepted()`). So a hint naming the site's own
  overlay was stricter than no hint, and dropping it lets the own-window rule
  decide. Kept as is. Possible tool fix later: treat a hint equal to the site's
  region like no hint.
- ov175 `unit_021DD56C/ov175_func_021DD56C.c`: EXACT in src/matched, but DIFF as a
  TU without its lang setting; left in its folder.
- `btlv_effvm`, `field_msgbg`: now single files (renamed by gamepromote).
- Coverage caveats: 190 gap drafts lie inside another function's listing extent
  (bytes counted, compiled by nobody until injected as hidden functions); the
  hidden functions in `src/game` are not in `src/matched`/layout. Filing them in
  `src/matched` + `layout/function_starts.txt` is a separate job (pattern:
  commit b913cdd40).

## Follow-up lanes (2026-10-09, after round 5)

- **Lost functions (lane f1):** 13 of the 28 EXACT-but-missing functions are now in
  their TUs (ov195, ov168, ov136, ov170, ov185, ov013 021B3924, ov046, ov047, ov036
  021F3980, ov048, ov068, ov103; ov093 021EFCE4 sits in its own file
  `ov093/unit_021EFC1C/` after a 16-byte uncovered veneer). gamegaps now reports
  15 lost pieces (328 bytes) and 9 header entries; all remaining ones are
  gamegaps blind spots: multi-line K&R definitions its regex does not read,
  `alarmCallback` mapped to the wrong address, and six arm9 `push {r0-r3}`
  vararg heads defined under their body labels. Fix in `tools/gamegaps.py`.
  mcss.c header no longer lists the branch targets 0x02014D90 and 0x02015590.
- **twl stand-ins:** now real C: func_0272FE54, func_0272FEF4, func_0272FFC8,
  func_0272EE98, func_02732944 (shard twl_sys re-verified, stable). Left: 9 in
  unit_0272E9E8 (EC38 best 40 bytes off; EFB0, F0BC, F368, F570, F740, F8A8, F9C4,
  EA74 not started) and 02732A64 and 027323A8 in unit_02731718.
- **02732A64/02732A70 are one 268-byte function:** nothing branches or calls to
  0x02732A70 (the only reference is the pool word to 0x02732A64). Drop the
  func_02732A70 entry from `layout/function_starts.txt` when that function is
  written. Best drafts (not EXACT): 02732A64 8 bytes short (`cmp #1; b` dispatch),
  027323A8 12 bytes short (loop guard, pool-loaded 1).

## Hidden functions: how they were found, matched and stored

**What they are.** Small functions the original listing never labelled: setters,
tail-call stubs (`return g(a, k);`), empty `bx lr` leaves, a few larger leaves.
Their bytes sit inside a neighbouring function's listing extent, so coverage
already counted them, but no matched file compiled them.

**How they were found.** A merge of two adjacent parts in `src/game` comes out DIFF
(usually a shift of a few bytes) when uncovered code sits between them. Lanes read
the bytes between the parts, decoded them, and found a function there. Earlier gap
passes (`gapmatch`, `gapmatch2`, `gapmatch3` in the session scratchpad) drafted 474
such functions; the dedupe found 190 of them inside a matched function's listed
range. Since round 5, `tools/gamegaps.py` lists every code range no `src/game`
function compiles (`gamegaps.tsv`, `gamegaps_summary.txt`).

**Are they matched?** Yes, inside `src/game`. Each was written as C, verified on its
own, then injected into its TU, and the merged TU verifies EXACT or MATCH with
`tools/gameverify.py`. Not counted exactly; from the lane reports it is several
hundred (about 280 setters in ov093, about 60 in ov021, plus ov099, ov095, ov009,
ov011, ov012, ov013, ov014, ov015, ov023, ov052, ov056, ov096, ov098, ov119, ov132,
ov135, ov172, ov173, ov210, ov212, arm9 and others). Names are `func_<ADDR>`.

**Where they are.** Only in `src/game/<region>/<tu>.c`. They were NOT added to
`layout/function_starts.txt` and NOT filed as per-function files in
`src/matched/<region>/`. The only exception is twl: the stand-ins replaced in
round 5 already had labels and `src/matched` files, and those files were updated in
place (shard `twl_sys` re-verified).

**Filed (2026-10-10).** 756 hidden functions now have a label in
`layout/function_starts.txt`, a per-function file in `src/matched/` and their own
shard `pkt_<region>_<ADDR>` (EXACT 663, EXACT* 95 at filing; arm9 75, twl 13,
overlays 668, ov093 alone 394). Neighbour entries whose extent shrank were
re-verified, then the whole manifest twice (`--force`); nothing got worse. One SDK
entry (ov175 DWC_ScGetConnectionId) needed its symbols row changed from data to
arm, since its target is now labelled code. 13 were not filed and stay only in
`src/game`: arm9 func_0202B720..func_0202B7AC (10, MATCH: call target
func_0202B1FC has no outside witness), ov021 func_021A1298 and ov132
func_021FBA6C (MATCH), ov093 func_021E5968 (undeclared d_021F2584). The 101 arm9
functions that have a listing label but no entry of their own are members of
game_unit entries (implied or under a `sub_` name) and are counted through them;
two filed duplicates of that kind (0x0202C630, 0x0202C634 in unit_0202C5F0) were
removed again. 14 src/matched headers had a `packet:` name that differed from
their tracked shard (every forced verify recreated a duplicate shard); fixed.
Coverage after filing: overlays 24,513 of 24,514 game functions, 1,886,692 of
1,887,132 game bytes (99.9767%; the denominator grew by 6,244 bytes that were
outside every drawn function before); twl 216 bytes moved from game to SDK (SDK
code inside a game neighbour's extent), still 100%; ARM9 unchanged at 100%. The
match.py selftest fixtures for sole-ref/self and the map lone case used
0x02004F94, which is the crt0 helper and code: moved to 0x02005050.

**Original to-do (done above).** File them properly: (1) a label per function in
`layout/function_starts.txt` (this shrinks the neighbour's extent), (2) a
per-function file in `src/matched/<region>/` taken from the `src/game` copy,
(3) re-verify the affected shards twice. Commit `b913cdd40` (319 functions) is the
pattern. Mostly scriptable: locate them with `gamegaps.py` against the layout,
extract the definitions from `src/game`. Coverage figures should not move, since
the bytes are already counted; only the attribution changes.

## How many files did the original have?

Not known. 1809 is an estimate: `tools/tuboundary.py` proposed the boundaries from
evidence (the game's `__FILE__` strings, compiler or flag changes, linker veneers,
shared strings and data), and lanes adjusted them (1812 became 1809).
- 274 TUs carry a real name from a `__FILE__` string. Those boundaries are solid.
  It is a floor, not an estimate: only files that use asserts or debug prints
  leave their name.
- 1535 are `unit_XXXXXXXX`, inferred from weaker evidence.
- Errors go both ways. A byte-exact merge does not prove one file (ov214
  `btl_rec_sel_graphic` has its own `__FILE__` inside what was one unit), and some
  "real" boundaries were not (about 30 ARM9 compiler boundaries closed in rounds 4
  and 5).
- Best guess: the real number is much closer to 1809 than to 274, roughly 1500 to
  2000. The SDK, NitroSystem, DWC and GameSpy libraries alone are many small
  objects, and the Gen 4 Pokemon decomps have source trees of that size.
- Evidence not used yet: alignment gaps between each file's data block, one static
  initialiser entry per file with globals, overlay edges as outer bounds.

So "92.9%" means 1687 of the 1816 estimated TUs are one file.

## Tools
- `tools/restructure.py` builds/merges; `tools/gamepromote.py` moves one-piece TUs
  up; `tools/gameverify.py` TU verification; `tools/gamecheck.py` present-once
  check; `tools/gamefix.py`, `tools/gameincludes.py`, `tools/restorenotes.py`
  (`--dedupe`; not idempotent with identical notes on twin functions: run once);
  `tools/gamegaps.py` uncovered code; `tools/tuboundary.py` boundary evidence.
- Lane drivers (greedy merge plus harmonizer `go20.py`/`hzlib20.py`, canonical
  struct templates `canon36.py`/`canon195.py`, injectors) live in the session
  scratchpad, not in the repo:
  `<home>/AppData/Local/Temp/claude/<project>/d965be22-e087-410a-b91d-ae680804241d/scratchpad/`.
  If that folder is gone, the lane briefs here still describe the method.

## Standing rules (unchanged)
No permuter, brute force or sweeps. Never open .c/.h under `sdk/`. Header
`status:` equals the match.py verdict. Never edit symbol rows only to turn MATCH
into EXACT. Explicit staging; no Co-Authored-By. No ROMs, game data or keys in git.
No em dashes or emoji.
