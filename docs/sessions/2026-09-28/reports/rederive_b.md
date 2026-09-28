# rederive_b, 2026-09-28

Lane rederive_b re-derived 31 ARM9 SDK functions from the vendor objects only
(`tools/sdkobj.py`, `tools/match.py show`/`one`, the idiom index). For every address below,
no existing version of the file (nor its git history, nor any other path in
`rederive_list.txt`) was opened, read, grepped or diffed; only the path was used. The new C
was written in the lane scratchpad, verified with `match.py one`, then copied over the repo
path and verified with `match.py manifest --verify --force --shard arm9/pkt_XXXXXXXX`
(a second non-forced pass rewrote 0 in every case). Header `status:` is copied from that
manifest output. No permuter runs were needed (seeds 15101 to 15199 unused).

## Results

All 31 re-derived. Files written: `src/matched/arm9_sdk/func_<addr>.c` for each address
below; shards verified (not edited by hand): `layout/matched/arm9/pkt_<addr>.json`.

| address | sdk symbol (object) | re-derived | verdict | bytes |
|---|---|---|---|---|
| 0x0207D46C | GX_DispOn (gx.o) | yes | EXACT | 68 |
| 0x0207D4B0 | GX_SetGraphicsMode (gx.o) | yes | EXACT | 104 |
| 0x0207D55C | GXx_GetMasterBrightness_ (gx.o) | yes | EXACT | 64 |
| 0x0207DF60 | G2_GetBG0ScrPtr (gx_bgcnt.o) | yes | EXACT | 52 |
| 0x0207DFB4 | G2_GetBG1ScrPtr (gx_bgcnt.o) | yes | EXACT | 52 |
| 0x0207E1F8 | G2_GetBG0CharPtr (gx_bgcnt.o) | yes | EXACT | 52 |
| 0x0207E24C | G2_GetBG1CharPtr (gx_bgcnt.o) | yes | EXACT | 52 |
| 0x02081940 | MATHi_CRC8InitTable (crc.o) | yes | EXACT | 64 |
| 0x02081980 | MATHi_CRC8Update (crc.o) | yes | EXACT | 56 |
| 0x020819B8 | MATHi_CRC16InitTable (crc.o) | yes | EXACT | 68 |
| 0x020819FC | MATHi_CRC16InitTableRev (crc.o) | yes | EXACT | 68 |
| 0x02081A40 | MATHi_CRC16Update (crc.o) | yes | EXACT | 64 |
| 0x02081A80 | MATHi_CRC16UpdateRev (crc.o) | yes | EXACT | 64 |
| 0x02081AC0 | MATHi_CRC32InitTableRev (crc.o) | yes | EXACT | 64 |
| 0x02081B00 | MATHi_CRC32UpdateRev (crc.o) | yes | EXACT | 60 |
| 0x02081B3C | MATH_CalcCRC8 (crc.o) | yes | EXACT | 40 |
| 0x02081B64 | MATH_CalcCRC16 (crc.o) | yes | EXACT | 40 |
| 0x02081B8C | MATH_CalcCRC16CCITT (crc.o) | yes | EXACT | 44 |
| 0x02081BB8 | MATH_CalcCRC32 (crc.o) | yes | EXACT* | 44 |
| 0x02082BA0 | MI_Copy64B (mi_memory.o) | yes | EXACT (asm) | 44 |
| 0x02086284 | DC_FlushAll (os_cache.o) | yes | EXACT (asm) | 52 |
| 0x020862F0 | DC_FlushRange (os_cache.o) | yes | EXACT (asm) | 36 |
| 0x02086348 | OSi_WaitVCount0 (os_init.o) | yes | EXACT (asm) | 32 |
| 0x0208B24C | MIC_Init (mic.o) | yes | EXACT | 112 |
| 0x0208B3EC | MIC_StartAutoSampling (mic.o) | yes | EXACT | 56 |
| 0x0208B424 | MIC_StopAutoSamplingAsync (mic.o) | yes | EXACT | 92 |
| 0x0208B480 | MIC_StopAutoSampling (mic.o) | yes | EXACT* | 56 |
| 0x0208B4C8 | MIC_StartLimitedSamplingAsync (mic.o) | yes | EXACT | 56 |
| 0x0208B500 | MIC_StartLimitedSampling (mic.o) | yes | EXACT | 40 |
| 0x0208B528 | MIC_StopLimitedSampling (mic.o) | yes | EXACT | 32 |
| 0x0208B75C | MicStopAutoSampling (mic.o) | yes | EXACT* | 44 |

Each row: no existing version of this file was read; the C was written from the vendor
object only. EXACT* rows are the compared bytes identical with the listing extent running
past the function (the next label is unmapped), as the manifest reports.

Not re-derived: none.

## asm bodies and their evidence line

- 0x02082BA0 MI_Copy64B: fixed-register ldm/stm block copy (r2, r3, r12, then r0 reused as a
  data register); no DW_TAG_variable children.
- 0x02086284 DC_FlushAll: mcr p15 c7,c10,4 and c7,c14,2; no DW_TAG_variable children.
- 0x020862F0 DC_FlushRange: mcr p15 c7,c10,4 and c7,c14,1; no DW_TAG_variable children.
- 0x02086348 OSi_WaitVCount0: no-prologue r12 code that stores the register base itself
  (0x04000000, bit 0 clear) into IME; no DW_TAG_variable children.

## Notes

- gx_bgcnt.o getters: the image reads BGxCNT before DISPCNT through a separate pool word, so
  the BGCNT field is read in a static inline helper into a local before `baseBlock` is
  computed. The DWARF lists only `baseBlock`; the extra local (`screenBase`/`charBase`) is
  the helper's result. Folding it into the return expression gives DISPCNT first (44 bytes,
  DIFF).
- mic.o: `micInitialized` (u16, 0x02152FE0) and `micWork` (28 bytes, 0x02152FE4) are reached
  through one pool word, so the section is modelled as one struct `mic_bss` at 0x02152FE0
  (section-struct idiom). micWork layout used: lock +0, callback +4, arg +8, result +0xC,
  three words not touched by these functions.
- No catalog/DWARF name disagreements seen.
