# Restructure report (2026-10-12, after round 17)

Handoff for the next session. Goal of this phase: rebuild `src/game/` as the
original source files (one `.c` per translation unit, TU). `src/matched/` stays the
frozen per-function record. Renaming functions is a later, separate step.

## Where it stands

TUs that are one file (`python tools/tucount.py`; counted from the files, a
TU split at a real boundary counts once as split):

| Area | Whole | Percent |
|---|---|---|
| ARM9 | 399 / 404 | 98.8% |
| Overlays | 1472 / 1486 | 99.1% |
| twl | 82 / 83 | 98.8% |
| ITCM | 4 / 4 | 100% |
| **Total** | **1957 / 1977** | **99.0%** |

Round 17 drops the old 1816 estimate (the user, 2026-10-12: the estimate may
move freely with evidence). The figure is now the file count itself.

Denominator change in round 16 (+2 TUs): arm9 `app_keycursor.c` (out of
app_taskmenu) and `tpoke_data.c` (out of tr_tool), split on the game's own
`__FILE__` strings. Evidence that linker veneers are not file boundaries: the
`__FILE__` anchors of camera_system.c sit on both sides of veneer blocks, so the
linker places veneers between the sections of one object.

Denominator change in round 6 (+7 TUs): arm9 `unit_02004F94.c` and `unit_02004FD4.c`
(crt0 helpers copied to WRAM, data words around them; their own units like the
other crt0 pieces), arm9 `textprint.c` split out of clact on the game's own
`__FILE__` string (`layout/file_anchors.txt`), and 4 new twl files
(`unit_0273034C.c`, `unit_02702A8C.c`, `unit_02705320.c`, `unit_02702D68.c`) made
separate because their neighbours are still empty asm stand-ins; fold them back
when those become real code. (Round 5 listed 164 split TUs; the recount finds 165
at that commit: ov093 unit_021EFC1C was missed.)
Later (lanes CR1, CR2): the crt0 pieces `unit_02004800.c`, `unit_02004DF4.c`,
`unit_02004EA8.c`, `unit_02004EB4.c`, `unit_02004F94.c` and `unit_02004FD4.c` are one
file again, `src/game/arm9/crt0.c` (code and data of crt0.HYB.TWL.o, SDK names,
EXACT; see BUILD_FROM_GAME.md).

Checks at this commit:
- `python tools/gameverify.py`: 1850 files, all EXACT or MATCH except
  `arm9/unit_020911D4_p03.c` and `_p05.c` (compiler runtime pieces that are not
  contiguous in the image).
- `python tools/gamecheck.py`: 35483 functions present, 0 missing, 0 doubled.
- 5 files are MATCH (`match_files.txt`); ov214 btl_rec_sel_graphic became EXACT
  (two objects had one name `config`).
- `python tools/match.py selftest`: 340 cases, 0 failures.
- `python tools/gamelink.py`: all 166 whole overlays and ITCM link
  byte-identical with mwldarm; arm9_main links 408 of 409 files identical (the
  skipped one is unit_020911D4, being rewritten).

Tooling changes in round 17:
- `tools/build.py --game`, `tools/gamebuild.py`: build regions from src/game.
- `tools/gamelink.py`: real link with mwldarm (typed ARM/Thumb stub objects,
  -interworking, one veneer per far call site, data sections at their
  addresses). See `BUILD_FROM_GAME.md`.
- `tools/mwccdbg/regalloc.py`: the simplify replay reads spill costs lazily,
  as the real allocator does (reproduces 14 captures).
- `tools/tucount.py`, `tools/tumerge.py` (greedy veneer-aware merge),
  `tools/gameverify.py --file`: lane tools now in the repo (a session crash
  emptied the scratchpad on 2026-10-12).

Tooling changes in round 16 (approved by the user, 2026-10-11):
- `match.py` `layout_tu(image=...)` / `linker_gap()`: between two sections of a
  TU, the 16-byte `bx pc; nop; ldr ip,[pc]; bx ip; .word` and 8-byte
  `ldr pc,[pc,#-4]; .word` linker veneers (and the 2-byte Thumb nop or zero fill
  before one) are taken from the image, so source holds no linker output. A
  source `asm` veneer at that place is compared, not taken.
- `match.py` `_veneer_route()`: a branch to a target out of range (or with no
  other witness) resolves when the image's branch lands on a linker veneer whose
  pointer word is that target. Calls name the real function, as in the
  original source.
- `match.py` `local_isa` (from the `$a`/`$t` mapping symbols): a file that mixes
  ARM and Thumb with `#pragma thumb on/off` resolves each local function with
  its own ISA (BL vs BLX, the Thumb bit on pool words).
- `gamecheck.py` skips addresses that hold a linker veneer.
- About 140 src/game files lost their `asm` veneer stand-ins (calls now name
  the target, with a symbols row carrying the target's ISA).

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
| Round 11 | 4 | 92.9% (no TU closed, big ones reduced): arm9 net_state 56 -> 46 (NetCmd, Votes, Entry canonical), button_man 10 -> 5, ov010 eventdata_system 10 -> 8, ov021 fld_trade 3 -> 2 (TradeWork), ov135 worldtrade_box 7 -> 6, ov208 zukan_detail_graphic 14 -> 13 |
| Round 12 | 4 | 92.9% (no TU closed, structs): arm9 unit_02064D70 15 -> 4 (RendererBss and SDK-style types), net_state 46 -> 36 (NetState 0x64 bytes for g_021469DC), clact 11 -> 6, particle 6 -> 4; ov208 zukan_detail_form 4 -> 3 (Ov208Form); ov135 worldtrade_types.h with one Menu (no part count change) |
| Round 13 | 4 | 93.0%: ov135 worldtrade_enter and ov010 musical_dressup_sys whole; arm9 net_state 36 -> 25 (NetCtx 0x354 bytes with named vtable; func_0203D798 is the same object), ov208 zukan_detail_graphic 13 -> 7 (zukan_detail_types.h: Ov208Mgr, Ov208Scene...), ov010 comm_player 11 -> 2, event_field_proclink 12 -> 2, ov135 worldtrade_box 6 -> 5; ov135 shared Work (0x132C bytes) in worldtrade_types.h applied to all 14 parts; afterwards event_field_proclink 2 -> 1 with a hidden tail-call function (the 8-byte stub was not a veneer): 93.1% |
| Round 14 | 4 | 94.1% (19 TUs): the tail-call stubs (8-byte Thumb `ldr r3,[pc]; bx r3`, 12-byte ARM `ldr ip,[pc]; bx ip`) are compiled code, not veneers: about 100 written as hidden functions; arm9 iss_city_sys, iss_road_sys, iss_3ds_sys, backup_system, unit_02059108, unit_02059858, unit_02072374, unit_02079304; ov009 unit_0215F650, unit_02164D64, unit_02165B80, unit_0217F130; ov014 net_whpipe; ov015 unit_02179824, unit_02179CAC; ov114 ghttpEncryption, unit_021C2284; ov125 unit_021D7CEC; ov093 unit_021DA624 whole; net_state 25 -> 20 |
| Round 15 | 5 | 94.4%: ov135 worldtrade_box and worldtrade_adapter, ov208 zukan_detail_form, arm9 net_state (20 -> 1) and g3d_system whole; 48 more hidden functions filed (35559 functions); the table figures above (ARM9/Overlays rows) were not recomputed per area. Not done: 16 overlay tail stubs are labelled but not in the 24,513-function count (decision pending); ov095/ov039/ov070/twl matches still open |
| Round 16 | 20 | 97.4% (102 -> 48 split TUs): veneers taken from the image (19 ov093/ov095 TUs whole at once, btl_server 131 -> 26); `#pragma thumb` closes ISA switches (ov013 unit_021AEB20, ov121 mystery_net, ov125 gds_rap, ov172 ctvt_comm, ITCM unit_01FF82A8, arm9 gfl_use); one struct per object across ov009 (unit_0216F014, unit_0215FDA4, unit_02180410, unit_0216A1F4, unit_0216C858, unit_0216870C, unit_0217576C, unit_02166880, unit_02176DEC, unit_0219BA58, GPI family x4); ov010 comm_player, scrcmd_proc, symbol_map, script_work (fp casts gone); ov218 un_select, ov055 unit_021F39C0, ov114 nhttp_rap, arm9 particle, ica_anime, bgm_info, unit_0207AD58/ADC4/B598 whole; twl func_0272EC38, func_0272EFB0 written |
| Round 17 | 30+ | 99.0% (48 -> 20 split TUs): ov009 dwc_rap, unit_0216AB20 (one DWCstMatchControl header); ov010 eventdata_system (goto stand-ins rewritten); all of ov095; ov172 camera_system and ctvt_draw (no asm); ov177; ov183 br_codein; ov198 unit_0220BC70 (non-const table array); ov204, ov208; arm9 clact, wipe_sub, pokeparty, bmp_menulist, btl_setup, unit_02067FE4; twl unit_02731718; ov039 0x021F36FC matched (u8 callee parameter) and its TU whole; btl_server 26 -> 5 (one Server struct) |

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

### 2. TUs still split (20)
List: `split_tus.tsv`; blockers in each TU's `MERGE.md`.
- Real boundaries (evidence in MERGE.md): arm9 button_man (compiler change,
  arm7tdmi part), unit_02061B2C and unit_02064D70 (compiler change),
  unit_02060468 (two library objects), unit_020911D4 (libc and fdlibm files,
  interleaved runtime members); ov016 unit_021B97A8, unit_021BA2F8 (static vs
  extern helper, -ipa settings); ov021 field_effect (second entry label);
  ov067 ui_scene, ov194 namein_graphic, ov021 fld_trade, ov038 unit_021F36C0
  (callers compiled against a different declaration than the callee).
- Waiting on an unmatched function: ov013 unit_021B3018 (0x021B3084, 6 bytes,
  alias set), ov070 itemmenu (0x021B86B8, 44 bytes, register colouring).
- .bss/.data layout: ov009 unit_021573C4, ov016 unit_021D0040, ov107
  unit_021F3D04, unit_021F4560 (analyses in MERGE.md).
- Open work: ov093 btl_server (5 parts: narrowing at three call sites and one
  literal pool entry), twl unit_0272E9E8 (func_0272F0BC register allocation,
  64-byte key blob needs a build-time data include).

### 3. Readability debt (from lane reports)
- **Mis-classified "veneers" (found 2026-10-11).** `gamegaps` calls every 8-byte
  Thumb `ldr r3,[pc]; bx r3; .word target` stub and every 12-byte ARM
  `ldr ip,[pc]; bx ip; .word target` stub a veneer. They are NOT: mwcc emits
  exactly these for a tail call (Thumb tail call = `ldr r3,=g; bx r3`; the ARM
  form is already noted in tools/ovstats.py as compiler output, ov009
  func_0216F008). Only `bx pc; nop; ldr ip,[pc]; bx ip; .word` (Thumb->ARM, 16
  bytes) and `ldr pc,[pc,#-4]` are linker veneers. ov010 event_field_proclink
  closed this way: `void func_0216171C(void) { func_020307B0(); }` is EXACT and
  the two parts merged. gamegaps rows of that shape (28 8-byte Thumb + 71 12-byte
  ARM, 2026-10-11 list) are hidden functions: write them as `g(...)` tail-call
  functions (match the argument shuffle the stub does, if any) and re-try the
  merges they block: arm9 iss_city_sys, iss_road_sys, iss_3ds_sys,
  unit_02072374, unit_02079304, unit_02059858; ov014 net_whpipe, unit_021771F8;
  ov015 unit_02179824, unit_02179CAC; ov018 intrude_subdisp area; ov009
  unit_0215F650, unit_02164D64, unit_02165B80, unit_0216AB20, unit_0217F130
  (the 3 stubs at 0x0217EA58/64/70 too); ov114 unit_021C2284, ghttpEncryption;
  ov125 unit_021D7CEC; ov107 unit_021F4560; ov093 unit_021DA624 p01 (check).
  Done in round 14 (see the Round 14 row): tools/gamegaps.py now reports the two
  stub forms as `leaf` (note `tailstub`), reads K&R definitions, and keeps only the
  16-byte `bx pc; nop; ldr ip,[pc]; bx ip` form, `ldr pc,[pc,#-4]` and the ov230
  entries as `veneer` (916 rows left). Idiom: docs/idioms/tail-call-stub-is-code-not-a-veneer.md.
  About 100 stub functions are only in src/game, not yet filed in src/matched.
- Compiler behaviour worth knowing when converting raw-offset code to fields:
  `(p + i*stride) + const` (original) vs `p->row[i].x` (hoists `p + base`): the
  second changes the code; ov208 zukan_detail_form p02/p03 still uses W()/H()
  macros for this reason (`e = (struct F *)((u8 *)p + i * 0x28); e->row[0].x`
  closes one function but needs `short x, y` in the row).
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

**Filed again (2026-10-11).** 48 more hidden functions got a label, a per-function file and a shard `pkt_<region>_<ADDR>` (arm9 15, ov009 3, ov010 1, ov014 6, ov015 13, ov018 2, ov021 4, ov093 2, twl 2; all EXACT). This includes the 12 of the 13 left over last time: func_0202B720..func_0202B7AC and func_021A1298 and func_021E5968 needed `symbols:` rows or an `extern` that the merged file did not carry for their callee (the callee has a matched entry, which is a valid witness). Not filed: ov132 func_021FBA6C (a 0x4C0-byte function, stays MATCH: the function-pointer and data pool words have no witness). The 71 arm9 and 16 overlay tail-call stubs of round 14 already have a listing label (ovstats counts the overlay ones as veneers); they are not hidden and were not filed. 19 neighbour shards re-verified, whole manifest twice with `--force`: 0 rewritten, `manifest --check` clean. Coverage did not move (the bytes were already counted). The src/game header of iss_3ds_sys.c got four witnessed `symbols:` rows and verifies EXACT now.

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

So "94.4%" means 1714 of the 1816 estimated TUs are one file.

## Tools
- `tools/restructure.py` builds/merges; `tools/gamepromote.py` moves one-piece TUs
  up; `tools/gameverify.py` TU verification; `tools/gamecheck.py` present-once
  check; `tools/gamefix.py`, `tools/gameincludes.py`, `tools/restorenotes.py`
  (`--dedupe`; not idempotent with identical notes on twin functions: run once);
  `tools/gamegaps.py` uncovered code; `tools/tuboundary.py` boundary evidence.
- Lane drivers (greedy merge plus harmonizer `go20.py`/`hzlib20.py`, canonical
  struct templates `canon36.py`/`canon195.py`, injectors) live in the session
  scratchpad, not in the repo:
  `the session scratch directory`.
  If that folder is gone, the lane briefs here still describe the method.

## Standing rules (unchanged)
No permuter, brute force or sweeps. Never open .c/.h under `sdk/`. Header
`status:` equals the match.py verdict. Never edit symbol rows only to turn MATCH
into EXACT. Explicit staging; no Co-Authored-By. No ROMs, game data or keys in git.
No em dashes or emoji.
