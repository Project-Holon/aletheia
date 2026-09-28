# sdk_arm9_3 lane report (2026-09-28, relaunch)

All 21 functions are EXACT under dsi/1.1p1, with no pins. The permuter was not used.

**Salvaged from the cut run** (all re-verified EXACT; each shard verified twice, and the second pass rewrote nothing):
FSi_InvokeCommand 02077758, FSi_GetPathDefault 0207976C (its shard was missing; the verify created it),
FSi_IsEventCommand 02077634, FSi_EndCommand 0207765C, FSi_WaitForArchiveCompletion 02077700,
FSi_SeekDirDirect 02079364, FSi_TranslateCommand 02079BFC, FS_InitFile 020788AC, MI_Copy48B 02082B7C,
OSi_InsertLinkToQueue 02084FCC, OS_SleepThread 020857B0, STD_GetStringLength 0208CC78.

**New in this run:**

| function | addr | what closed it |
|---|---|---|
| ProcessBlock (MD5) | 02080D68 | F/G/H/I and the rotate as inline functions, and kp declared first |
| MTX_Inverse43 | 0207B67C | cofactors as fx32 in declaration order, and det10 written `_10*_22 - _12*_20` |
| CARDi_IdentifyBackupCore2 | 020766D8 | vendor source body, EXACT on the first compile |
| NVRAMi_ReadCallback | 020837B8 | `result` preset before the if-chain |
| NVRAMi_VerifyDataArray, NVRAMi_ReadDataBytes | 020842A0, 020843B4 | leaves, first draft |
| NVRAMi_VerifyCallback | 02083FA0 | the `arg[1] != 0` branch placed first, cb at function scope |
| NVRAMi_WriteCallback | 020839E8 | volatile arg, an inline MIN, `result` preset before tempSize, and case 2's `seq = 4` after the reset call |
| MTX_Concat44 | 0207BE14 | the vendor `*ab = tmp;` struct copy (not the MI_Copy64B asm) |

Both near misses are closed, and each note has a dated closing marker.

**Key finding:** sdk/TwlSDK/build/libraries holds about 90 vendor .c files (card, fs, fx_mtx44, os, mi, gx,
wm, spi, snd, mb, wxc). Their bodies compile EXACT. There is an idiom file for this.
Three new idiom files: sdk-rows-have-vendor-source-under-sdk-build-libraries,
struct-assignment-copy-is-ldm-stm-with-spilled-pointers, inline-functions-allocate-differently-from-macros.

**Integrator:**
- Stage the 12 salvaged sources and shards, plus the 9 new sources, their shards (pkt_02080D68 0207B67C
  020766D8 020837B8 020842A0 020843B4 02083FA0 020839E8 0207BE14), the two note appends and the three idiom files.
- `manifest --check` reports two duplicates. Both are other lanes' shards (ov010 021605C0, ov093 021E8918).
- Two matched sources (CARDi_IdentifyBackupCore2 and MTX_Concat44) contain vendor SDK source text. Decide
  whether that is acceptable for the repo.

**Next roots** (largest open arm9 rows): WM_StepDataSharing 020902D8, MI_CpuMove 02083194,
PM_GoSleepMode 0208C154, MI_CpuCopy 02082EA4, FS_NormalizePath 02078078, MTX_Inverse33 0207B0A4,
WmInitCore 0208E038, TPi_TpCallback 0208A6B0, WM_StartDataSharing 0209004C, MTX_FrustumW 0207C1D0.
Most of these have vendor source. Seeds: none.
