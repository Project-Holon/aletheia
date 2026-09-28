# sdk9_drivers lane report (arm9 SDK: libspi, libmi, libnvram, librtc, libpxi, libscfg)

The lane wrote all 44 functions from the vendor objects (sdkobj DWARF, relocations and listings)
and never opened any file under `sdk/`. Every file was checked with `match.py one`. Each one's
status line is copied from `manifest --verify --shard arm9/pkt_<ADDR>`. The second verify pass
rewrote 0 entries on all 44 shards. `manifest --check` shows no arm9 duplicates.

Totals: 44 functions, 5,424 bytes. 40 are EXACT and 4 are EXACT*.

## Results (address, SDK symbol, bytes, verdict)

| address | symbol (object) | bytes | verdict |
| --- | --- | --- | --- |
| 0x0208C9C4 | SCFGi_CommonCallback (scfg_proc.o) | 280 | EXACT* |
| 0x02082390 | MIi_DmaFill32Async (mi_dma.o) | 264 | EXACT |
| 0x02088688 | PXIi_HandlerRecvFifoNotEmpty (pxi_fifo.o) | 256 | EXACT |
| 0x02089060 | RTC_ConvertDayToDate (convert.o) | 256 | EXACT |
| 0x02082498 | MIi_DmaCopy32Async (mi_dma.o) | 252 | EXACT |
| 0x020884A4 | PXI_InitFifo (pxi_fifo.o) | 252 | EXACT |
| 0x02082760 | MI_SendGXCommandAsync (mi_dma_gxcommand.o) | 236 | EXACT |
| 0x02082C60 | MI_CpuFill (mi_memory.o) | 228 | EXACT (asm) |
| 0x020834C0 | MI_UncompressLZ8 (mi_uncompress.o) | 224 | EXACT (asm) |
| 0x02082960 | MI_SendGXCommandAsyncFast (mi_dma_gxcommand.o) | 188 | EXACT |
| 0x0208284C | MIi_FIFOCallback (mi_dma_gxcommand.o) | 180 | EXACT |
| 0x020822E8 | MIi_DmaCopy16 (mi_dma.o) | 168 | EXACT |
| 0x02082244 | MIi_DmaCopy32 (mi_dma.o) | 164 | EXACT |
| 0x02088F58 | RTC_ConvertDateToDay (convert.o) | 148 | EXACT |
| 0x020891E0 | RTC_ConvertSecondToDateTime (convert.o) | 148 | EXACT |
| 0x02082680 | MIi_CheckAnotherAutoDMA (mi_dma.o) | 140 | EXACT |
| 0x020821C0 | MIi_DmaFill32 (mi_dma.o) | 132 | EXACT |
| 0x02089160 | RTCi_ConvertSecondToTime (convert.o) | 128 | EXACT |
| 0x020835A0 | MIi_CardDmaCopy32 (mi_dma_card.o) | 124 | EXACT |
| 0x02088944 | RTC_GetDateTimeAsync (external.o) | 124 | EXACT |
| 0x020887F4 | RTC_GetDateAsync (external.o) | 112 | EXACT |
| 0x0208889C | RTC_GetTimeAsync (external.o) | 112 | EXACT |
| 0x02088788 | RTC_Init (external.o) | 108 | EXACT |
| 0x020825F0 | MI_StopDma (mi_dma.o) | 104 | EXACT |
| 0x02082900 | MIi_DMACallback (mi_dma_gxcommand.o) | 96 | EXACT |
| 0x02082594 | MI_WaitDma (mi_dma.o) | 92 | EXACT |
| 0x02089004 | RTC_ConvertDateTimeToSecond (convert.o) | 92 | EXACT |
| 0x0208270C | MIi_CheckDma0SourceAddress (mi_dma.o) | 84 | EXACT |
| 0x02082AC0 | MIi_CpuClearFast (mi_memory.o) | 76 | EXACT (asm) |
| 0x0208C988 | SCFG_SetCpuSpeed (scfg_proc.o) | 60 | EXACT |
| 0x02082B0C | MIi_CpuCopyFast (mi_memory.o) | 56 | EXACT* (asm) |
| 0x02088864 | RTC_GetDate (external.o) | 56 | EXACT |
| 0x0208890C | RTC_GetTime (external.o); catalog says RTC_GetDate | 56 | EXACT |
| 0x020889C0 | RTC_GetDateTime (external.o); catalog says RTC_GetAlarmParam | 56 | EXACT* |
| 0x02082E74 | MI_CpuComp8 (mi_memory.o) | 48 | EXACT |
| 0x02082A1C | MIi_DMAFastCallback (mi_dma_gxcommand.o) | 44 | EXACT |
| 0x02088F2C | RtcSendPxiCommand (internal.o) | 44 | EXACT |
| 0x0208361C | MI_Init (mi_init.o) | 40 | EXACT |
| 0x02084260 | NVRAMi_SyncCallback (nvram.o) | 40 | EXACT* |
| 0x0208C960 | SCFG_Init (scfg_proc.o) | 40 | EXACT |
| 0x020885EC | PXI_IsCallbackReady (pxi_fifo.o) | 36 | EXACT |
| 0x0208C848 | PMi_InsertPostSleepCallbackEx (pm.o) | 36 | EXACT |
| 0x02082B44 | MI_Copy32B (mi_memory.o) | 28 | EXACT (asm) |
| 0x0208B4B8 | MIC_GetLastSamplingAddress (mic.o) | 16 | EXACT |

For all four EXACT* entries, the image listing extent is longer than the compiled function
(the note is "listing says the original is N bytes"). Every compared byte matches.

## Files and shards written

- `src/matched/arm9_sdk/func_<ADDR>.c` and `layout/matched/arm9/pkt_<ADDR>.json` for each
  address listed above (44 of each).
- Three pending files were at my addresses: `src/pending/arm9_sdk/func_02082AC0.c`,
  `func_02082B0C.c` and `func_0208361C.c`. I did not read them. I deleted them with plain `rm`
  (no git command), and my own drafts from the object replace them in `src/matched/`.
- `git status` also shows modified shards that are not mine (for example
  `pkt_0200421A.json` and the coverage svgs). They come from other lanes. I ran manifest
  only with `--shard` on my own packets.

## asm bodies (each file carries its evidence line)

- MI_Copy32B: a fixed-register ldm/stm block copy (`ldm r0!, {r2, r3, r12}`).
- MIi_CpuCopyFast: an eight-register fixed ldm/stm block copy. The DWARF subprogram has no variables.
- MIi_CpuClearFast: an eight-register fixed stm fill. The DWARF subprogram has no variables.
- MI_CpuFill: a computed jump into a strb run (`add pc, pc, r3, lsl #2`) and a push in the
  middle of the body. The DWARF subprogram has no variables.
- MI_UncompressLZ8: uses `swpb`, which has no C spelling. The DWARF subprogram has no variables.

## Catalog and DWARF disagreements

- 0x0208890C is catalogued as RTC_GetDate. It calls 0x0208889C (RTC_GetTimeAsync), so it is
  **RTC_GetTime**.
- 0x020889C0 is catalogued as RTC_GetAlarmParam. It calls 0x02088944 (RTC_GetDateTimeAsync)
  with (date, time, cb, 0), so it is **RTC_GetDateTime**. sdkobj names the callee
  RTC_GetAlarmParamAsync; that name is wrong.
- sDayOfYear is at 0x020A86F4. The pool word 0x020A86F0 in RTC_ConvertDateToDay is
  `sDayOfYear - 4`, because it indexes `[month - 1]`. The data label g_020A86F0 is not the
  object start.
- SCFGi_CommonCallback's DWARF lists only `pxiData`. The real signature is the 3-argument PXI
  callback (the data arrives in r1). This is the same case as RtcCommonCallback.
- Locals that are not in the DWARF, needed for the match:
  - PXI_IsCallbackReady needs an `OSSystemWork *w` pointer local. Without it the
    0x02FFFC00+0x388 base is folded into two `add`s.
  - MIi_FIFOCallback uses a `length` local; the DWARF lists only `src`.
- Shape levers:
  - PXI_InitFifo needs an inline `OS_GetSystemWork()` and a non-volatile `pxiHandleChecker`.
  - The DMA register address has to be written as `REG_DMA0SAD_ADDR + (dmaNo * 3 + 2) * 4`
    (integer form). The pointer form and the `dmaNo * 12` form give `mul`.
  - MIi_CheckDma0SourceAddress needs a `switch (dir)`.
  - The GX callbacks call through an inline `MIi_CallCallback(cb, arg)`, which loads the
    argument before the test.
  - sDayOfYear must be non-const, so that ConvertDayToDate reloads it after the store.

## Next pass

I stopped because context passed the 150k budget. These are the remaining open rows in the
territory, all libnvram and libspi:

- libspi pm.o: PMi_DeleteList 88, PMi_InsertList 140, PMi_CommonCallback 288.
- libspi tp.o:
  - TP_WaitRawResult 84, TP_Init 116, TP_GetUserInfo 148
  - TP_RequestSamplingAsync 156, TP_RequestAutoSamplingStopAsync 160
  - TP_SetCalibrateParam 240, TP_RequestAutoSamplingStartAsync 264
  - TP_GetCalibratedPoint 284, TP_GetLatestRawPointInAuto 340
  - TP_CalcCalibrateParam 492 (a pending file exists)
- libspi mic.o: MicCommonCallback 264, MicStartAutoSampling 268, MIC_StartAutoSamplingAsync 304 (a pending file exists).
- libnvram nvram.o:
  - NVRAMi_Init 192, NVRAMi_ReadAsync 180, NVRAMi_WriteAsync 180, NVRAMi_VerifyAsync 232
  - three 240-byte rows catalogued as NVRAMi_Read (0x02083844, 0x02083DC8, 0x020840F8)
  - Only one symbol can own the name NVRAMi_Read, so the catalog has mislabelled at least two
    of the three. Name them from their callees, the same way as the RTC case.

Tip: the RTC, PXI, DMA and GX preambles in these files (struct layouts, bss wrappers) can be
reused as they are.
