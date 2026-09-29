# w6_ev: evidence repair after the cross-overlay witness fix

All 16 of our entries that lost a witness to the w6_tools fix verify EXACT again. Every hint
names the overlay whose catalog row or bytes hold the target, and each one rests on evidence
written in its file header. No entry is left demoted. The owner update asked for all 3 demoted
entries to end up EXACT, and they do: each has independent evidence, set out below.

## Step 1: one-token fixes (13 entries)

For each changed `symbols:` line, symbols_sdk.json has exactly one row at the callee address,
and it belongs to the hinted overlay (checked by script over every changed line).

| file (src/matched/ov_sdk/) | lines changed | before | after |
|---|---|---|---|
| ov175_func_021DE840.c | 0217EAE0 ov175 -> ov009 | MATCH | EXACT |
| ov175_func_021DD84C.c | 021834D0, 021834E8, 0218372C, 0217EAB0, 0217EAE0 ov175 -> ov009 | MATCH | EXACT |
| ov175_func_021DF734.c | 021BF520 ov175 -> ov114 | MATCH | EXACT |
| ov175_func_021DF968.c | 0217D254 ov175 -> ov009 | MATCH | EXACT |
| ov175_func_021E0774.c | 021819B0, 021829AC, 02182A2C, 02182E90, 02182CF0, 02181DE8, 02181D84, 0217FD7C ov175 -> ov009 | MATCH | EXACT |
| ov175_func_021DF4FC.c | 021BF8C0 ov175 -> ov114 | MATCH | EXACT |
| ov175_func_021E0FE8.c | 021834D0, 021834E8, 02183A24 ov175 -> ov009 | MATCH | EXACT |
| ov175_func_021E0C68.c | 021834D0, 021834E8, 02183A24, 0218372C ov175 -> ov009 | MATCH | EXACT |
| ov009_func_02180080.c | 021C2324 ov009 -> ov114 | MATCH | EXACT |
| ov016_func_021D1E54.c | 021F5E7C ov016 -> ov107 | MATCH | EXACT |
| ov114_func_021C1804.c | 02162248 ov010 -> ov009 | MATCH | EXACT |
| ov016_func_021C8230.c (endScene2) | DWCi_SceneSetSelectAp data -> arm (single ov016 row) | MATCH | EXACT |
| ov016_func_021CA7B4.c (endScene1) | DWCi_SceneSetSelectAp data -> arm | MATCH | EXACT |

The header status was EXACT in all 13, and forced verify confirmed it, so no status line
changed. Forced verify rewrote 12 shards. ov009/pkt_02180080 already recorded EXACT, so it
was not rewritten.

## Step 2: demote 3

- ov009 func_0217CCCC: set to MATCH, then a forced verify removed
  layout/matched/ov009/pkt_ov009_0217CCCC.json. The source moved to src/pending/ov_sdk/.
  Note: `--shard` only knows shards that have a source under src/matched, so removal has to
  happen before the move.
- arm9 func_02010AC4 and func_020120C0: ARM9 units (layout/units_arm9.json) are assembly
  only. The C comes from the manifest shards, so demotion means dropping the shard entry,
  and the listing supplies the bytes. I set status MATCH and let a forced verify remove
  arm9/pkt_02010AC4.json. Both sources moved to src/pending/arm9/, and a forced verify then
  rewrote arm9/pkt_020120B4.json with only func_020120B4 (still EXACT*).
- Build in the demoted state: plain `build.py --split --pack` stops on
  src/matched/ov/ov010_func_02167BFC.c (MATCH, refusing to splice). That is the other
  developer's existing drift (w6_tools, "Not caused by the fix"), not these changes. I ran
  `build.py --split --pack --c-manifest <scratch>`: the full manifest minus the 8
  pre-existing drift entries and the 10 entries in Step 4. Result: 243 PASS, 0 FAIL, whole
  ARM9 image PASS, BLZ pack OK. `--split --only arm9 --arm9-image` with the real manifest
  also passed.

## Step 3: evidence, all 3 restored

- **ov009 func_0217CCCC** (+0x98 PC24 to 0x021C204C; symbols_sdk has an ov016 procInit1
  row and an ov114 ghttpCleanup row).
  - `tools/sdkobj.py --region ov009 0x0217CCCC` locates libdwcgscommon.TWL.HYB.a(gscore.o)
    with 0 concrete mismatches of 170. Its +0x98 relocation names `ghttpCleanup`.
  - The only row with that name in symbols_sdk.json is ov114 (libdwcgsghttp ghttpmain.o),
    at 0x021C204C.
  - Hint `ov114` is set, with an `evidence:` note. The site now attests as `label` (ov114
    label, ov114 branch at 021BF594).
  - Verdict EXACT. The file went back to src/matched/ov_sdk/, and the shard was rewritten.
- **arm9 func_020120C0** (+0x14 ABS32 s0x021D359C; the address is in ov021 data and ov114
  bss).
  - The same call passes ov021_id (0x15, attested `overlay_id`) and the pointer into the
    proc system. Path: func_020120B4 -> func_02031348 -> func_020314F4 -> func_02031538,
    which stores the id at Proc+4 and the pointer at Proc+0 (ProcData).
  - func_020315F0 (EXACT) loads overlay Proc+4 through func_02034AC4 before it calls any
    ProcData callback. So ov021 is resident whenever the pointer is dereferenced.
  - Independent check of the target object: ov021's words at 0x021D359C are
    0x02187F01/0x02187FD1/0x02187FE9. These are three Thumb pointers, each to a `func_`
    label in ov021's own listing (an init/main/end table). ov114 has only bss there.
  - Hint `ov021` is set, with an `evidence:` note. The site attests as `data_table` from
    ov021's bytes. Verdict EXACT, back in src/matched/arm9/, and the pkt_020120B4 shard
    again holds 2 entries.
- **arm9 func_02010AC4** (+0xCC ABS32 d_021DA9A8; the address is in the windows of ov016,
  ov021, ov123, ov125 and ov175).
  - Case 1 passes ov123_id (0x7B, attested `overlay_id`) and the pointer in the same
    func_020312CC call. The proc-system path is the same as above, so ov123 is resident
    whenever the pointer is dereferenced.
  - Independent check: ov123's words at 0x021DA9A8 are 0x021DA479/0x021DA54D/0x021DA5D1,
    three Thumb pointers to ov123 `func_` labels. ov125 has bss there. ov016, ov021 and
    ov175 hold words that are not pointers (0x20102..., 0x196..., 0x2800E986...).
  - Hint `ov123` is set, with an `evidence:` note. The site attests as `sole-ref`. Verdict
    EXACT, back in src/matched/arm9/, and arm9/pkt_02010AC4.json was rewritten.

The selftest end-to-end case that expects func_02010AC4 EXACT did not need changing. The
entry is EXACT again.

## Step 4

I appended a heading "Entries that lost a witness when the cross-overlay leak was closed
(wave 6)" to docs/sessions/2026-09-29/overlay_game_verify_note.md. It has a short cause
paragraph and the table of the 10 entries. Two of them live at src/matched/ov/func_021BB3C4.c
and src/matched/ov/func_021BD1D4.c, without an ovNNN_ prefix. Their files are untouched.

## Files changed

- Edited, symbols token only (13): the files in the Step 1 table.
- Edited, hint plus `evidence:` note; status ends EXACT; each went to pending and back to its
  original path (3):
  - src/matched/ov_sdk/ov009_func_0217CCCC.c
  - src/matched/arm9/func_020120C0.c
  - src/matched/arm9/func_02010AC4.c
- Shards rewritten (12):
  - layout/matched/ov175/pkt_ov175_{021DE840,021DD84C,021DF734,021DF968,021E0774,021DF4FC,021E0FE8,021E0C68}.json
  - layout/matched/ov016/pkt_ov016_{021D1E54,021C8230,021CA7B4}.json
  - layout/matched/ov114/pkt_ov114_021C1804.json
- Shards removed, then rewritten (2): layout/matched/ov009/pkt_ov009_0217CCCC.json and
  layout/matched/arm9/pkt_02010AC4.json.
- Shard rewritten twice, ending with its 2 entries again (1): layout/matched/arm9/pkt_020120B4.json.
- Doc appended: docs/sessions/2026-09-29/overlay_game_verify_note.md.
- Nothing left in src/pending from this lane.

## Final checks

- `python tools/match.py manifest --check`: clean (10,438 shard files, no duplicates, no
  unread json).
- `python tools/match.py selftest` (full): 295 cases, 0 failures. This includes the
  end-to-end func_02010AC4 EXACT case.
- `python tools/build.py --split --pack --c-manifest <scratch: all shards minus the 18 other-developer MATCH entries>`
  in the final state: 243 PASS, 0 FAIL, whole ARM9 image PASS, pack OK. With no
  `--c-manifest`, the build still stops on the other developer's ov010 func_02167BFC (MATCH),
  which already failed before this lane.
