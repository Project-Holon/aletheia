# Restructure report (2026-10-09)

Handoff for the next session. Goal of this phase: rebuild `src/game/` as the
original source files (one `.c` per translation unit, TU). `src/matched/` stays the
frozen per-function record. Renaming functions is a later, separate step.

## Where it stands

TUs that are one file (`python tools/gamecheck.py`, file counts from `split_tus.tsv`):

| Area | Whole | Percent |
|---|---|---|
| ARM9 | 368 / 403 | 91.3% |
| Overlays | 1199 / 1325 | 90.5% |
| twl | 76 / 78 | 97.4% |
| ITCM | 2 / 3 | 66.7% |
| **Total** | **1645 / 1809** | **90.9%** |

Checks at this commit:
- `python tools/gameverify.py`: 2737 files, all EXACT or MATCH except
  `arm9/unit_020911D4_p11.c` and `_p13.c` (compiler runtime pieces that are not
  contiguous in the image: every function is EXACT with `match.py one`, the TU
  compare cannot line up; headers keep EXACT with a note).
- `python tools/gamecheck.py`: 34756 functions present, 0 missing, 0 doubled.
- Header `status:` equals the TU verdict everywhere (EXACT* kept where the
  per-function verdict is EXACT*).

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
| Round 5 | 19 | 90.9% (this commit) |

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
- 262 code pieces, 9224 bytes (231 strong, 31 weak; 223 hidden, 39 labeled).
- **28 pieces (1132 bytes) are EXACT in `layout/matched` but not defined in
  `src/game`** (for example ov021 0x02198E44, ov013 0x021B3924). gamecheck does not
  see them. Fix first: put them back into their TUs.
- 13 header `function:` entries with no definition (for example arm9 `mcss.c`
  0x02014D90, 0x02015590).
- Largest pieces: ov039 0x021F36FC (824 B; draft 18 bytes off, only spill-slot
  order, `scratchpad r5g01/ov039_func_021F36FC_best18.c`, see the TU's MERGE.md),
  ov070 0x021B86B8 (588 B, not decoded), ov013 0x021B3084 (460 B, the last
  unmatched game function, notes in `src/pending/ov/ov013_func_021B3084.c` pass 7:
  the original needs one extra non-emitting node after `str thr`), ov230 several
  (decrypted view, numbers not clean), ov107 0x021F1230 (320 B, blocks
  mb_comm_sys p01|p02), twl 0x027315E0 (312 B), ov036 0x021F3980 (252 B).
- ov095 unit_0689CB3C leaves at 0x0689CCB4 / 0x0689CCF8: right shape, the compiler
  keeps `p->n` in a register where the original reloads it.
- **twl stand-ins** (empty `asm void f(void) {}` that report EXACT without byte
  compare): still 13 in unit_0272E9E8 (func_0272EA74, EC38, EE98, EFB0, F0BC, F368,
  F570, F740, F8A8, F9C4, FE54, FEF4, FFC8) and 4 in unit_02731718 (027323A8,
  02732944, 02732A64/02732A70, which look like one function). Done this round:
  all 29 of unit_0273042C, func_02701AA0, func_02731AF0, and 3 in unit_0272E9E8
  (`src/matched/twl*`, shard `twl_sys` re-verified).

### 2. TUs still split (164)
List with piece counts: `split_tus.tsv`. Each TU folder has a `MERGE.md` with its
blockers. Biggest: ov093 btl_server (131 parts, 114 real veneers; 16 non-veneer
boundaries listed), arm9 net_state (58; g_021469D4/D8/DC/E0/F0 structs not
started), ov009 unit_021573C4 (34), ov172 camera_system (31, strictly alternating
ARM/Thumb: real), ov021 weather_task (32), fldmmdl_blact (24), ov009 unit_0216F014
(23, DWCstMatchControl family needs one shared header), ov009 unit_0215FDA4 (18),
field_effect (19), ov208 zukan_detail_graphic (14), arm9 unit_020911D4 (16),
unit_02064D70 (15), clact (13). About 80 to 100 of the 164 are real boundaries
(veneers, ARM/Thumb, compiler, SDK stand-ins), so the ceiling is roughly 93 to 95%.

### 3. Readability debt (from lane reports)
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
- `FINAL_TODO`: lane r2_02 dropped the region word from 9 contested ov093 data
  symbol rows to turn MATCH into EXACT. Check that this does not weaken the
  witness rule; restore and accept MATCH if it does.
- ov175 `unit_021DD56C/ov175_func_021DD56C.c`: EXACT in src/matched, but DIFF as a
  TU without its lang setting; left in its folder.
- `btlv_effvm`, `field_msgbg`: now single files (renamed by gamepromote).
- Coverage caveats: 190 gap drafts lie inside another function's listing extent
  (bytes counted, compiled by nobody until injected as hidden functions); the
  hidden functions in `src/game` are not in `src/matched`/layout. Filing them in
  `src/matched` + `layout/function_starts.txt` is a separate job (pattern:
  commit b913cdd40).

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

**To do.** File them properly: (1) a label per function in
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

So "90.9%" means 1645 of the 1809 estimated TUs are one file.

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
