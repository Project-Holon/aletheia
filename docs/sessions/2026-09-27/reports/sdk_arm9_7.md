# sdk_arm9_7 lane report (2026-09-28)

All work used dsi/1.1p1 with no pins and came from vendor objects only (sdkobj, `match.py show`, the idiom index). I did not open any file under sdk/.

**84 EXACT.** Six of them are EXACT* because their extent swallows a neighbour: FSi_OpenFileFastDefault, FSi_WriteFileDefault, FSi_ROMFAT_OpenFile, FSi_ROMFAT_OpenDirectory, FSi_ROMFAT_Unmount and FS_UnloadArchiveTables. Every shard was verified twice, the second pass rewrote nothing, and `manifest --check` is clean.

- Roots: GX_LoadTex, SND_GetNextInstData, FSi_NextCommand, SND_FlushCommand, FX_Atan2Idx, CARDi_ReadRom, GX_Init, WMi_StartMP.
- FSi_NextCommand closed when each arm restores interrupts itself; the cross-jumped copy leaves the image's `b` hop.
- gx_load3d.o is complete (9 functions). gx_load2d.o has 34: all BG screen and char loaders, the palette, OAM and OBJ loaders, and the ext-palette begin/load/end functions.
- fs_proc_default.o: every linked row (33 functions). Also FSi_SendCommand from fs_archive.o.

**Not closed** (dated notes are in docs/notes):
- MATCH: FS_LoadOverlayInfo. The only wildcard is SDK_OVERLAY_NUMBER, an absolute linker symbol with no second site in the image.
- DIFF: CARDi_RequestStreamCommandCore (a 21-line register rotation, permuter seed 9702).
- DIFF: MTX_RotAxis33 (292 of 340 bytes; the draft does not CSE t*x).
- DIFF: VEC_Fx16Normalize (one smulbb scheduled early, seed 9703).
- DIFF: FS_StartOverlay (ret should be in r3). It is capped at MATCH anyway: two linker symbols have no witness.
- Permuter seed 9701 went to FSi_NextCommand before it closed by hand.

**New idioms:** two-dma-calls-under-one-ndma-test-are-one-explicit-branch, a-chained-assignment-stores-the-rightmost-target-first.

**Integrator:**
- Stage the 84 src/matched files: every `status: EXACT`/`EXACT*` file carrying a `sdk_arm9_7`-era TwlSDK header in gx_load3d, gx_load2d, fs_proc_default, fs_archive, snd, card_rom, gx.o, wm_mp or fx_atanidx.
- Stage their 84 shards arm9/pkt_<addr>: 020771B4 02077AD8 02077D80 02079304 02079390 0207942C 02079AE8 02079B70 02079B94 02079BC4 02079CCC 02079D10 02079D54 02079DAC 02079ED4 02079F60 02079FA4 02079FEC 0207A040 0207A070 0207A0A4 0207A0D8 0207A10C 0207A140 0207A190 0207A234 0207A270 0207A2E0 0207A40C 0207A45C 0207A484 0207A4B0 0207A528 0207A568 0207A5C8 0207A708 0207CFB8 0207D204 0207E3D0 0207E468 0207E51C 0207E5D0 0207E684 0207E708 0207E780 0207E804 0207E888..0207F274 (16) 0207F308 0207F394 0207F428 0207F47C 0207F4C4 0207F560 0207F5C8 0207F65C 0207F6C0 0207F754 0207F7A0 0207F7FC 0207F9B4 0207FA0C 0207FA40 0207FADC 0207FBBC 0207FC48 0207FCE4 02089B38 0208A48C 0208FA28.
- Stage the five pending files, the five notes and the two idiom files.
- symbols_sdk.txt labels the eight screen loaders GXS_LoadBG0Scr and the eight char loaders GXS_LoadBG0Char. Their G2 callees prove the real names (GX_/GXS_LoadBG0..3Scr/Char), and the files use those names.
- An absolute-linker-symbol attestation rule would close FS_LoadOverlayInfo.

**Seed:** 0x02079BF4 (`mov r0,#0; bx lr`), which is FSi_IgnoredCommand by object order. It is unlabelled, and FSi_WriteFileDefault's extent swallows it.

**Remainder:** gx_vramcnt.o (SetBankFor ClearImage, TexPltt, BGExtPltt, OBJExtPltt, ARM7, SubBG, SubOBJ, SubBGExtPltt, SubOBJExtPltt, resetBankForX_, disableBankForX_, the second Disable* copies), then WM_StartScanEx, OSi_VAlarmHandler, WM_GetOtherElements, FSi_InitRomArchive, TP_GetLatestRawPointInAuto, CARDi_Request, OS_InitThread (linker symbols), MIC_StartAutoSamplingAsync, and the four DIFFs above. TP_CalcCalibrateParam, WmInitCore and WM_StepDataSharing were not attempted.
