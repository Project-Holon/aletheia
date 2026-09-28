# sdk9_drivers_2 lane report (arm9 SDK: libnvram nvram.o, libspi pm.o, tp.o, mic.o)

This pass closes the last 23 open rows in the territory. Every function was written from the
vendor object (sdkobj DWARF, relocations and listings, plus `match.py show`). No file under
`sdk/` was opened. I did not read or build on any file in `src/pending/arm9_sdk/`.

Every file was checked with `match.py one`. Each header's status line is copied from
`manifest --verify --shard arm9/pkt_<ADDR>`. On all 23 shards the second verify pass rewrote 0.
`manifest --check` reports no arm9 duplicates. After this pass,
`sdkobj.py --open --region arm9` lists no rows from nvram.o, pm.o, tp.o or mic.o.

Totals: 23 functions, 5,140 bytes. 22 are EXACT and 1 is EXACT*. None needed an asm body.

## Results (address, SDK symbol, bytes, verdict)

| address | symbol (object) | bytes | verdict |
| --- | --- | --- | --- |
| 0x0208AF18 | TP_CalcCalibrateParam (tp.o) | 492 | EXACT |
| 0x0208ADB4 | TP_GetLatestRawPointInAuto (tp.o) | 340 | EXACT* |
| 0x0208B2BC | MIC_StartAutoSamplingAsync (mic.o) | 304 | EXACT |
| 0x0208B950 | PMi_CommonCallback (pm.o) | 288 | EXACT |
| 0x0208B104 | TP_GetCalibratedPoint (tp.o) | 284 | EXACT |
| 0x0208B650 | MicStartAutoSampling (mic.o) | 268 | EXACT |
| 0x0208AC0C | TP_RequestAutoSamplingStartAsync (tp.o) | 264 | EXACT |
| 0x0208B548 | MicCommonCallback (mic.o) | 264 | EXACT |
| 0x02083844 | NVRAMi_Read (nvram.o) | 240 | EXACT |
| 0x02083DC8 | NVRAMi_Write (nvram.o); catalog says NVRAMi_Read | 240 | EXACT |
| 0x020840F8 | NVRAMi_Verify (nvram.o); catalog says NVRAMi_Read | 240 | EXACT |
| 0x0208AA2C | TP_SetCalibrateParam (tp.o) | 240 | EXACT |
| 0x02083EB8 | NVRAMi_VerifyAsync (nvram.o) | 232 | EXACT |
| 0x02083644 | NVRAMi_Init (nvram.o) | 192 | EXACT |
| 0x02083704 | NVRAMi_ReadAsync (nvram.o) | 180 | EXACT |
| 0x02083934 | NVRAMi_WriteAsync (nvram.o) | 180 | EXACT |
| 0x0208AD14 | TP_RequestAutoSamplingStopAsync (tp.o) | 160 | EXACT |
| 0x0208AB1C | TP_RequestSamplingAsync (tp.o) | 156 | EXACT |
| 0x0208A998 | TP_GetUserInfo (tp.o) | 148 | EXACT |
| 0x0208C6FC | PMi_InsertList (pm.o) | 140 | EXACT |
| 0x0208A924 | TP_Init (tp.o) | 116 | EXACT |
| 0x0208C788 | PMi_DeleteList (pm.o) | 88 | EXACT |
| 0x0208ABB8 | TP_WaitRawResult (tp.o) | 84 | EXACT |

TP_GetLatestRawPointInAuto is EXACT* because the image listing runs 16 bytes past the function,
into TP_GetLatestIndexInAuto at 0x0208AF08. The compiled function is 340 bytes and the listing
says 356. Every compared byte matches.

## Files and shards written

- `src/matched/arm9_sdk/func_<ADDR>.c` and `layout/matched/arm9/pkt_<ADDR>.json` for each of the
  23 addresses listed above.
- Two pending files were at my addresses: `src/pending/arm9_sdk/TP_CalcCalibrateParam.c` and
  `src/pending/arm9_sdk/func_0208B2BC.c`. I did not read either one. I deleted both with plain
  `rm` (no git command). My own drafts from the object replace them in `src/matched/`.
  `docs/notes/pkt_0208AF18.c.txt` still refers to the old draft. I did not touch it.
- I did not stage or commit anything. I ran manifest only with `--shard` on my own 23 packets.

## Catalog and DWARF disagreements

- **0x02083DC8 is NVRAMi_Write.** The catalog calls it NVRAMi_Read. It calls 0x02083934
  (NVRAMi_WriteAsync).
- **0x020840F8 is NVRAMi_Verify.** The catalog calls it NVRAMi_Read. It calls 0x02083EB8
  (NVRAMi_VerifyAsync).
- The three sync wrappers are 240 bytes each and have identical DWARF. nvram.o has one 240-byte
  symbol for each name (NVRAMi_Read, NVRAMi_Write, NVRAMi_Verify). sdkobj assigned the Read DWARF
  to all three, and it names the callee in all three `NVRAMi_ReadAsync`. The callee name is
  wrong for two of them.
- Three DWARF prototypes are shorter than the real signature:
  - PMi_CommonCallback's DWARF shows `(data, err)`. The body reads r1 and r2, so it is the
    3-argument PXI FIFO callback, `(tag, data, err)`.
  - MicCommonCallback has the same issue.
  - This matches SCFGi_CommonCallback and RtcCommonCallback from the first pass.
- sdkobj resolves PMi_ProceedToExit to 0x027314A4 and PMi_BatteryLowCallbackInfo to 0x02732FB0.
  Both addresses are outside the main arm9 range. I used them as given, and the match resolves
  them.

## Shape levers (not visible in the DWARF)

- **TP_GetUserInfo:** needs a base-pointer local, `NvTpPoints *w = (NvTpPoints *)0x02FFFC80`.
  This is the same lever as the first pass's `OSSystemWork *w`. Without it the compiler folds
  0x02FFFC80+0x58 into one pool constant.
- **TP_RequestAutoSamplingStartAsync:**
  - The inline's send result is tested through an explicit `(u8)` cast at the call site, which
    gives `tst r7, #0xff`.
  - A BOOL or u8 return type alone gives `cmp #0`.
- **TP_CalcCalibrateParam and TP_SetCalibrateParam:**
  - The divider denominator must be a plain (non-volatile) `u64` store. That is what lets the
    second divide use `stm`. Both files use the same `CP_SetDiv32_32` inline.
  - TP_CalcCalibrateParam also has to compute `ry_width` before `dy_width`, although the DWARF
    declares `ry_width` first.
- **MicCommonCallback:** the switch operand must be `(u16)(data & 0xff)`. The plain mask swaps
  r5 and r6.
- **MIC_StartAutoSamplingAsync:** the loop flag must be written as
  `flags = (u8)(loop ? (flags | 0x10) & 0xff : flags & 0xff)`. This gives andne/andeq and then an
  `and` into r4. The if form, the unmasked ternary and the or-of-ternary each allocate the join
  differently.
- **PMi_CommonCallback:** the no-op case labels (0x62 in the outer switch; 1, 2 and 3 in the
  inner one) must be written explicitly. Without them the two switches become compare chains
  instead of jump tables.
- **PMi_InsertList:** the locals must be declared `p` before `pre`. The other order swaps r2
  and r3.
- **Bss layout:** tp.o, mic.o and pm.o address their statics from the section base, one pool
  word per function. I wrote this as one extern struct at the section address:
  - `g_02152FA4` for tp.o. TP_Init's `initial` is at +0 and tpState is at +4. The calibration
    block (`TPiCalibrateParam`) is at +0x1C, which is the `tpState+0x18` relocation.
  - `g_02152FE0` for mic.o.
  - `s_02153000` for pm.o.
  - For nvram.o I reused the matched NVRAMi_ReadCallback preamble (`NVRAMWork nvramw`).
- **NVRAMi_Read, Write and Verify:** the not-initialised test is `OSi_ThreadInfo.current`
  (+4), read directly.

## Next pass

Nothing is left in this territory. The integrator should re-verify the 23 shards listed above.
`docs/notes/pkt_0208AF18.c.txt` refers to the deleted pending draft and can be retired.
Permuter seeds 13001 to 13099 were not needed.
