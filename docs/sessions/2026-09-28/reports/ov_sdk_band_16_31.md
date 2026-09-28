# ov_sdk size band 16-31, 2026-09-28

All 19 open overlay-SDK functions in the 16-31 byte band were matched to
EXACT/EXACT* (17 EXACT, 2 EXACT*) and their shards written; the band now
enumerates 0 functions. Four lanes, grouped by vendor object (`sdkobj.py`).

| region | addr | symbol | object | verdict | bytes |
|---|---|---|---|---|---|
| ov009 | 0x0215BBF0 | dacktimer_alarmhandler | network.o | EXACT | 20 |
| ov009 | 0x02177ED8 | DWC_Auth_GetCustomNas | dwc_auth.o | EXACT | 16 |
| ov009 | 0x021644B4 | get64bits | biginteger.o | EXACT | 28 (asm void) |
| ov009 | 0x0216007C | CPS_GetSslHandshakePriority | ssl.o | EXACT | 16 |
| ov010 | 0x0215FA1C | DSPi_WaitForPipe | dsp_pipe.o | EXACT | 24 |
| ov013 | 0x021B23C8 | OS_InitIrqTable | os_interrupt.o | EXACT | 24 |
| ov014 | 0x02177A94 | CTRDGi_IsTaskAvailable | ctrdg_task.o | EXACT | 20 |
| ov014 | 0x0217850C | DWCi_MOV_WH_StateOutEndChild | dwc_mov_wh.o | EXACT* | 22 |
| ov014 | 0x02178CC4 | DWCi_MOV_WH_StateOutEndChild | dwc_mov_wh.o | EXACT* | 22 |
| ov014 | 0x02178964 | DWCi_MOV_WH_StateInEndParent | dwc_mov_wh.o | EXACT | 28 |
| ov016 | 0x021C44D8 | NWMi_ForceUnloadDeviceCallback | nwm_unloaddev.o | EXACT | 20 |
| ov016 | 0x021C7CE4 | DWCi_SceneSetError | sceneseterror.o | EXACT | 28 |
| ov016 | 0x021D240C | DWCi_MOV_MBP_Cancel | dwc_mov_mbp.o | EXACT | 20 |
| ov016 | 0x021D5450 | DWCi_LSTlDelete | list.o | EXACT | 28 |
| ov016 | 0x021D6D70 | DWCi_LSTlDelete | list.o | EXACT | 28 |
| ov029 | 0x021F2BF0 | CTRDG_IsAgbCartridge | ctrdg.o | EXACT | 32 |
| ov107 | 0x021F6610 | CTRDGi_IsTaskAvailable | ctrdg_task.o | EXACT | 28 |
| ov175 | 0x021DF20C | DWC_ScGetConnectionId | dwc_sc.o | EXACT | 24 |
| ov179 | 0x021B6278 | OSi_VBlankIntr | os_attention.o | EXACT | 24 |

`manifest --check`: clean, 7573 shards (was 7554).

## Notes for the next pass

- **`CTRDGi_IsTaskAvailable` is ambiguous in `symbols_sdk.json`** (11 rows). A
  bare `bl`/`blx` resolves to the wrong address; pin `addr + isa + ovNNN` on
  the `symbols:` line.
- **`get64bits` (biginteger.o)** is a hand-written `asm void` body: the natural
  C (`*(u64 *)(s-3)`) compiles to a packed 32-bit load pair, not the original's
  four `ldrh` + two `orr ...,lsl #16`. Same family as `get48bits_2/3`.
- **`sdkobj.py` can mis-signature-match a row**: for `CTRDG_IsAgbCartridge`
  (ov029) it reported the vendor body `CTRDG_IsExisting() && ...` (26 B, caps
  at MATCH*), but the resident image code takes a pointer (`p[0x45B]`, then
  `blx CTRDGi_IsAgbCartridgeAtInit`) and is 32 B. Its "0 concrete mismatches"
  line zeroes all four bytes of every Thumb call, so two different bodies can
  look identical. Trust `match.py show` over `sdkobj`'s listing. Documented in
  the file header.
- **`DWCi_LSTlDelete`** reproduces the `push {r0-r3}` home area via
  `DWCi_HEAPlFree_((void **)&list)` (address-of a register parameter).
- ov014's `DWCi_MOV_WH_StateInEndParent` calls the arm9 `WM_EndParent` at
  **0x0208F808**, distinct from the arm9 static module's 0x0208F654 pinned by
  the sibling `ov014_func_021784F0.c`; the per-file `symbols:` block resolved
  it.
- ov175's `scGetConnectionId` is an **unlabelled ARM leaf** at 0x021DFA98
  (`.word` run in the listing); it attests only as `sole-ref/data` with the
  explicit `ov175` hint.

## Next band (32-63) recon

- ov175: `0x021DD290` sakeSetProfile (60, sakemain.o),
  `0x021DFF78` sciReportSetPlayerConnectionId (40, scireport.o),
  `0x021DFFA0` sciReportSetPlayerTeamIndex (40, scireport.o).
- ov010: none.
