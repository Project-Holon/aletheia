# Lane U9 — ov107 open SDK rows 0-10 (libmb, mb_parent/mb_fileinfo/mb_gameinfo/mb_task/mb_wm_base)

Slice: `python scratch/a2/open_rows.py ov107 0 11` — 11 rows, index 11 (0x021F4EFC
MBi_ChildCallback) left untouched.

Vendor objects for every row are **byte-identical to the image** (`tools/sdkobj.py`
reports "0 concrete mismatches" for all of them), so every residue below is a pure
reconstruction problem: the source must compile to the vendor object's exact code.

Result: **0 EXACT**. Two rows measurably improved; all parked with a named residue.

## Improvements kept in scratch/u9 (not filed — not EXACT)

- **0x021F2E58 MBi_calc_sendblock** 124 B, **27 → 8 concrete bytes**.
  The parked body ends the outer `if` with a `return;`, which compiles 120 bytes.
  Moving the `return` *inside* the inner `if` (i.e. `if (y <= x) { if (x <= y + 2)
  { e->a = x + 1; return; } } e->a = y;`) reproduces the image's `bxle lr` and the
  shared `e->a = y` fall-through: **124/124 bytes**, 8 bytes out.
  Residue (pure allocator tie-break, 12 spellings identical): image
  `mla ip, r0, r1, r2` / `addne r0, ip, …` / `ldrh r3, [r0,#0x4a]` (element pointer
  in **ip**, `y` in **r3**); ours `mla r3,…` / `ldrh ip, [r0,#0x4a]` (pointer in
  **r3**, `y` in **ip**). Tried: declaration order of all three locals, x/y load
  order, `u16` vs `int` locals, no locals at all (direct `e->a`/`e->b`), a `u8 *p`
  base local, a `u32 base` local, `Ent *mbc` array-subscript form — all give the
  same ip/r3 swap.

- **0x021F3830 MBi_SetSegmentInfo** 348 B, **115 → 110 concrete bytes**.
  Reordering the locals to `int reload_flag; int error_flag; u32 load_last_addr;`
  fixes the case-B register swap (image `error_flag`=r2 / `load_last_addr`=r3; the
  parked order gives r3/r2). Now byte-identical up to +0090.
  Residue (block cross-jump): the inner `size <= 0x40000` test's `reload_flag = 1`
  arm is cross-jumped onto the next arm's `movls r4, #1` (ours emits
  `b 0x…904` / `b 0x…910` at +00B4/+00B8); the image keeps it inline as
  `movls r4, #1; bls 0x…918; b 0x…914`. Tried: inverted inner test (S3, 356 B/135),
  explicit `else { ; }` (S2, 356 B/135), brace/`;` forms — only the empty-branch
  spelling holds 348 B.

## Parked, residue named (first differing instruction, image | ours)

| # | address | bytes | name | residue |
|---|---|---|---|---|
| 1 | 0x021F6658 | 356 | MBi_SetTask | two basins: 348 B / 163 B-out (parked order) and 352 B / 110-111 B-out (any order with `callback` not written first, e.g. `task, active, callback, priority`). Target 356 B needs `mov r5,r0; str r7,[r8,#8]; str r1,[r8,#4]`; both basins keep mwcc's `stmib r8,{r1,r7}` (+4A0). All 8 top-level field orders swept. |
| 2 | 0x021F5904 | 472 | MB_Init | 9 B at +010C/+0110/+011C. Documented compiler wall (two basins). Image `add r6,r6,#1` then `str r1,[r0,#0xc]`, back edge to 0x021F5A00 (hoisted cursor); ours swaps the pair and back-edges to 0x021F59FC (in-loop cursor read). |
| 3 | 0x021F4140 | 356 | MBi_SendFixedBeacon | 63 B, +0010 `ldr r4,[r3,#0x1c] | ldr r0,[r3,#0x1c]` — image keeps `cur` in r4 and `data` in r0; ours `cur`=r0, `data`=r3 (re-using the dying `&sUnlockFunc`). Tried named `cur`/`data` locals (both scopes) — unchanged 63 B; a fully local `cur` for every access drops to 352 B / 223 B-out. |
| 4 | 0x021F42D4 | 612 | MBi_SendVolatBeacon | 401 B, codegen/scheduling (`(v & 3)` as `and #0xff` vs image `bic #0xfc`; `(P->unk4b5 << 2)` not fused to `lsl #0x1a; orr …,lsr #24`). |
| 5 | 0x021F2A44 | 632 | MBi_CommParentSendBlock | 12 B, +0128..+0148 scratch rotation: image `ldr r6,[r5]` / `ldrb r2,[r2,#0x525]` / `mla r6,r2,r4,r6`; ours `ldr r7,[r5]` / `ldrb r6,…` / `mla r2,r6,r4,r7`. Same 632 bytes, same semantics. |
| 6 | 0x021F3544 | 632 | MB_RegisterFile | 8 B, +01A8..+01E4: image `add r7, r6, #0x1e8` (dead `game_reg` reg) / `add r3, r6, #0x258` / `add r6, r0, #1`; ours `add r3, r6, #0x1e8` / `add r6, r6, #0x258` / `add r1, r0, #1`. Every earlier byte matches. |
| 7 | 0x021F2200 | 1216 | MBi_CommParentRecvDataPerChild | 1018 B, allocator wall (`&g_021F6FA0` in sb/r9 in the object vs r5 here; 12-entry switch table vs narrowed 4-entry). |
| 8 | 0x021F2FA0 | 1324 | MB_ReadSegment | 10 B, +04D4..+04E8 — `*(u32 *)(p_cache->p_buf + (_start_AutoloadDoneCallback - BUFROM(main_ram_address))) = 0xE12FFF1E;` Image loads into r1,r2,r3,r0; ours r0,r1,r2,r3 (`str r0,[r3,r1] | str r3,[r2,r0]`). Tried: a `u32 *wp` pointer local and a `u32 off` local — both still 10 B. |
| 9 | 0x021F46C8 | 2004 | MBi_ParentCallback | 1178 B. Sibling **MBi_ChildCallback 0x021F4EFC is itself parked** (1720/2464 B, 1473 diffs, prologue saves {r3..r8,lr} vs image {r3..r8,sb,sl,fp,lr}), so there is no EXACT template to copy. Park. |
