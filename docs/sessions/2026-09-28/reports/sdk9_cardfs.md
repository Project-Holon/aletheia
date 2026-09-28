# sdk9_cardfs report (libcard, libfs, libctrdg, libfatfs; arm9 SDK rows)

Scope: 85 open rows at start. 75 filed EXACT/EXACT* under `src/matched/arm9_sdk/` (7384 bytes), 9 in pending with a real verdict, 1 open row not attempted.

All work from `tools/sdkobj.py` (DWARF prototypes, locals, relocations, types) and `match.py show`; no file under `sdk/` was opened.

## Filed (status copied from `manifest --verify`, second pass rewrote 0 for every shard)

| address | symbol | bytes | status | shard |
|---|---|---|---|---|
| 0x0205912C | CTRDG_IsBitID | 48 | EXACT | arm9/pkt_0205912C |
| 0x02075C38 | CARDi_PeekEventListener | 88 | EXACT | arm9/pkt_02075C38 |
| 0x02075CAC | CARD_Init | 244 | EXACT | arm9/pkt_02075CAC |
| 0x02075E10 | CARD_LockRom | 112 | EXACT | arm9/pkt_02075E10 |
| 0x02075EAC | CARD_UnlockBackup | 40 | EXACT | arm9/pkt_02075EAC |
| 0x02075F4C | CARDi_UnlockResource | 128 | EXACT | arm9/pkt_02075F4C |
| 0x020760B4 | CARDi_InitCommand | 76 | EXACT | arm9/pkt_020760B4 |
| 0x02076100 | CARDi_NotifyEvent | 112 | EXACT | arm9/pkt_02076100 |
| 0x02076170 | CARDi_ExecuteOldTypeTask | 116 | EXACT* | arm9/pkt_02076170 |
| 0x020761E4 | CARDi_OldTypeTaskThread | 76 | EXACT | arm9/pkt_020761E4 |
| 0x02076230 | CARDi_WaitForTask | 120 | EXACT | arm9/pkt_02076230 |
| 0x020762A8 | CARDi_EndTask | 76 | EXACT | arm9/pkt_020762A8 |
| 0x020762F4 | CARDi_GetDmaInterface | 80 | EXACT | arm9/pkt_020762F4 |
| 0x02076360 | CARDi_DCInvalidateSmart | 92 | EXACT | arm9/pkt_02076360 |
| 0x020763BC | CARDi_OnFifoRecv | 52 | EXACT | arm9/pkt_020763BC |
| 0x020763F0 | CARDi_Request | 336 | EXACT | arm9/pkt_020763F0 |
| 0x02076A20 | CARDi_IdentifyBackupCore | 80 | EXACT | arm9/pkt_02076A20 |
| 0x02076A70 | CARDi_BeginBackupCommand | 80 | EXACT | arm9/pkt_02076A70 |
| 0x02076AC0 | CARDi_RequestStreamCommand | 108 | EXACT | arm9/pkt_02076AC0 |
| 0x02076B2C | CARD_IdentifyBackup | 64 | EXACT | arm9/pkt_02076B2C |
| 0x02076B98 | CARD_CancelBackupAsync | 36 | EXACT | arm9/pkt_02076B98 |
| 0x02076BBC | CARDi_SetRomOp | 128 | EXACT | arm9/pkt_02076BBC |
| 0x02076C3C | CARDi_IsNormalMode | 76 | EXACT | arm9/pkt_02076C3C |
| 0x02076C88 | CARDi_StartRomPageTransfer | 72 | EXACT | arm9/pkt_02076C88 |
| 0x02076CD0 | CARDi_ReadRomIDCore | 104 | EXACT | arm9/pkt_02076CD0 |
| 0x02076D38 | CARDi_ReadRomStatusCore | 104 | EXACT | arm9/pkt_02076D38 |
| 0x02076DA0 | CARDi_RefreshRom | 96 | EXACT | arm9/pkt_02076DA0 |
| 0x02076E00 | CARDi_RefreshRomCore | 76 | EXACT | arm9/pkt_02076E00 |
| 0x02076F68 | CARDi_DmaReadPageCallback | 160 | EXACT | arm9/pkt_02076F68 |
| 0x02077008 | CARDi_ReadRomWithDMA | 124 | EXACT | arm9/pkt_02077008 |
| 0x02077084 | CARDi_DmaReadDone | 48 | EXACT | arm9/pkt_02077084 |
| 0x020770B4 | CARDi_IsRomDmaAvailable | 180 | EXACT | arm9/pkt_020770B4 |
| 0x02077168 | CARDi_ReadRomSyncCore | 76 | EXACT | arm9/pkt_02077168 |
| 0x0207733C | CARDi_InitRom | 136 | EXACT | arm9/pkt_0207733C |
| 0x020773DC | CARD_InitPulledOutCallback | 52 | EXACT | arm9/pkt_020773DC |
| 0x02077410 | CARDi_PulledOutCallback | 144 | EXACT* | arm9/pkt_02077410 |
| 0x020774A0 | CARD_SetPulledOutCallback | 16 | EXACT | arm9/pkt_020774A0 |
| 0x02077518 | CARDi_CheckPulledOutCore | 80 | EXACT | arm9/pkt_02077518 |
| 0x02077C78 | FSi_ExecuteAsyncCommand | 132 | EXACT | arm9/pkt_02077C78 |
| 0x02077CFC | FSi_ExecuteSyncCommand | 132 | EXACT | arm9/pkt_02077CFC |
| 0x02077EB8 | FS_FindArchive | 140 | EXACT | arm9/pkt_02077EB8 |
| 0x02077F44 | FS_SetCurrentDirectory | 212 | EXACT | arm9/pkt_02077F44 |
| 0x02078018 | FSi_CopySafeString | 96 | EXACT | arm9/pkt_02078018 |
| 0x02078384 | FS_RegisterArchiveName | 256 | EXACT | arm9/pkt_02078384 |
| 0x02078484 | FS_ReleaseArchiveName | 172 | EXACT | arm9/pkt_02078484 |
| 0x02078540 | FS_MountArchive | 72 | EXACT | arm9/pkt_02078540 |
| 0x02078588 | FS_UnmountArchive | 192 | EXACT | arm9/pkt_02078588 |
| 0x02078648 | FS_SuspendArchive | 144 | EXACT | arm9/pkt_02078648 |
| 0x020786D8 | FS_ResumeArchive | 92 | EXACT | arm9/pkt_020786D8 |
| 0x02078734 | FS_NotifyArchiveAsyncEnd | 108 | EXACT | arm9/pkt_02078734 |
| 0x020787A0 | FSi_DecrementSjisPosition | 64 | EXACT | arm9/pkt_020787A0 |
| 0x02078834 | FSi_DecrementSjisPositionToSlash | 52 | EXACT | arm9/pkt_02078834 |
| 0x02078868 | FSi_TrimSjisTrailingSlash | 68 | EXACT | arm9/pkt_02078868 |
| 0x020788D8 | FS_ConvertPathToFileID | 140 | EXACT | arm9/pkt_020788D8 |
| 0x02078964 | FS_OpenFileDirect | 64 | EXACT | arm9/pkt_02078964 |
| 0x020789A4 | FS_OpenFileFast | 88 | EXACT | arm9/pkt_020789A4 |
| 0x020789FC | FS_OpenFileEx | 132 | EXACT | arm9/pkt_020789FC |
| 0x02078A94 | FS_GetFileLength | 88 | EXACT | arm9/pkt_02078A94 |
| 0x02078AEC | FS_GetFilePosition | 88 | EXACT | arm9/pkt_02078AEC |
| 0x02078B70 | FS_ReadFile | 84 | EXACT | arm9/pkt_02078B70 |
| 0x02078BC4 | FS_WriteFile | 84 | EXACT | arm9/pkt_02078BC4 |
| 0x02078C40 | FSi_InitOverlay | 112 | EXACT | arm9/pkt_02078C40 |
| 0x02078CCC | FS_ClearOverlayImage | 60 | EXACT | arm9/pkt_02078CCC |
| 0x02078EB0 | FS_LoadOverlayImage | 128 | EXACT | arm9/pkt_02078EB0 |
| 0x02079264 | FS_LoadOverlay | 84 | EXACT | arm9/pkt_02079264 |
| 0x0207A890 | FSi_InitMemArchive | 176 | EXACT | arm9/pkt_0207A890 |
| 0x0207A940 | FS_CreateFileFromMemory | 64 | EXACT | arm9/pkt_0207A940 |
| 0x0207AC64 | FS_SetDefaultDMA | 80 | EXACT | arm9/pkt_0207AC64 |
| 0x0207ACD4 | FS_CreateFileFromRom | 48 | EXACT | arm9/pkt_0207ACD4 |
| 0x0207AD30 | FS_IsAvailable | 16 | EXACT | arm9/pkt_0207AD30 |
| 0x02084C68 | FSi_HasEnoughSpaceToCreateUserFile | 16 | EXACT | arm9/pkt_02084C68 |
| 0x02084CEC | FSi_HasEnoughSpaceToCreateUserFile | 16 | EXACT | arm9/pkt_02084CEC |
| 0x02084D68 | FSi_HasEnoughSpaceToCreateUserFile | 16 | EXACT | arm9/pkt_02084D68 |
| 0x0208F224 | FATFS_FormatDrive | 16 | EXACT | arm9/pkt_0208F224 |
| 0x02095B2C | FATFS_FormatDrive | 16 | EXACT | arm9/pkt_02095B2C |

Files: `src/matched/arm9_sdk/func_<ADDR>.c` and `layout/matched/arm9/pkt_<ADDR>.json` for each address above (one function per shard).

## Pending (`src/pending/arm9_sdk/func_<ADDR>.c`, verdict from `match.py one`)

| address | verdict | residue |
|---|---|---|
| 0x020911A0 | MATCH* | bytes identical; the ABS32 to CTRDGi_DummyCallback (0x020911D4) has no witness because that static has no catalog row, so the site stays wildcarded |
| 0x020774C0 | MATCH | bytes identical; the PC24 to PMi_ExecutePostExitCallbackList (0x027315A8, TWL ltdmain) has no witness outside this function |
| 0x0207AB10 | MATCH | bytes identical; ABS32 sites to FSi_ReadDummyCallback (0x0207AAF8) and FSi_WriteDummyCallback (0x0207AB00) have no witness, both 8-byte statics without catalog rows |
| 0x02075ED4 | DIFF | EXACT under -O4,s and -O2,p; under -O4,p the wait loop is peeled with an entry guard where the image branches to a bottom test, no source spelling found (while, for-break, goto all rotate) |
| 0x0207608C | DIFF | p and the zero swap registers (image: p in r2, zero in r0 loaded first); enum-typed target, inline OS_InitThreadQueue, order variants and 1500-iteration permuter all 18 bytes out |
| 0x02076E4C | DIFF | structure right; image enters the page loop by a branch to the bottom test (no guard), keeps n=512 in a register for the length<n test, and spills retval/cachedPage in the other order |
| 0x0207902C | MATCH | bytes identical; ABS32 sites to the linker symbols SDK_LTDAUTOLOAD_LTDMAIN_START (0x02700000) and SDK_LTDAUTOLOAD_LTDMAIN_BSS_END (0x02735B40) have no witness outside this function |
| 0x02078D34 | MATCH | bytes identical; ABS32 site to the absolute linker symbol SDK_OVERLAY_NUMBER (0xED) has no witness outside this function |

Byte-identical MATCH rows (0x020911A0, 0x020774C0, 0x0207AB10, 0x0207902C, 0x02078D34) only lack a witness for one relocation target: uncatalogued statics (CTRDGi_DummyCallback 0x020911D4, FSi_ReadDummyCallback 0x0207AAF8, FSi_WriteDummyCallback 0x0207AB00), a TWL ltdmain callee (0x027315A8), or linker symbols (SDK_LTDAUTOLOAD_LTDMAIN_START/BSS_END, SDK_OVERLAY_NUMBER). They become EXACT once those targets gain rows or witnesses; the C does not need to change.

Pending files replaced: `src/pending/arm9_sdk/func_020911A0.c` was overwritten with my own draft from the object. The old pending files `FS_StartOverlay.c` (0x0207902C) and `FS_LoadOverlayInfo.c` (0x02078D34) were deleted unread and replaced by `func_0207902C.c` and `func_02078D34.c` written from the object. `CARDi_RequestStreamCommandCore.c` (0x02076540) was left untouched (not attempted).

## Shape notes (worth an idiom entry)

- FS archive flag predicates must be `static inline BOOL FS_IsArchiveLoaded(volatile const FSArchive *arc) { return (arc->flag & 2) ? 1 : 0; }`. The `volatile const` parameter is what makes mwcc materialise the bool (`tst; movne #1; moveq #0; cmp #0`) as the image does (FS_UnmountArchive, FSi_InitMemArchive, FS_FindArchive, FSi_InitRomArchive). A plain `const` parameter folds the test into one `tst/beq`. FS_Resume/SuspendArchive match with a plain `const` inline because the result feeds `== 0`.
- A static list head that the image loads through two literal-pool words (one for reads, one for `&head`) is spelled with two extern names at the same address: the section base (`fsi_archive_state`, `cardi_hook_state`) for reads and the DWARF symbol (`arc_list`, `CARDiHookChain`) for the address taken by `pp`. Used in FS_ReleaseArchiveName, FS_RegisterArchiveName, CARDi_NotifyEvent. The object's relocations are section-relative for the reads, which is the basis.
- FSi_ExecuteSyncCommand needs the command read through an inline accessor (`FSi_GetCurrentCommand(file)`) so the `stat` word is reloaded after the `if` test.
- CARDi_Request needs `*(volatile u32 *)&p->flag` on the first test so the flag is reloaded before the `|= 2`; no non-volatile spelling found.
- FS_ReadFile/FS_WriteFile: `if (send) length = arg->length; else if (error == 6) length = -1; else length = arg->length; return length;` (reusing the parameter) is the only spelling that gives the image's predicated tail.
- FS_ConvertPathToFileID: declaration order baseid, arg, relpath, file gives the image stack layout (file below relpath).

## Name disagreements and symbol notes

- 0x02084C68, 0x02084CEC, 0x02084D68 are all catalogued as FSi_HasEnoughSpaceToCreateUserFile (identical 16-byte `r3 = 0` tail stubs); their targets are catalogued as OSi_DoLockByWord (0x02084C1C), OSi_DoUnlockByWord (0x02084C78), OSi_DoTryLockByWord (0x02084CFC). Byte identity only; the real identities of these three stubs and their callees are uncertain.
- 0x0208F224 and 0x02095B2C are both catalogued as FATFS_FormatDrive; 0x0208F234 (its callee) is catalogued as WMi_EnableEx in one row and FATFSi_FormatDriveEx by the relocation.
- 0x0205915C/0x02059194 (CTRDG_IsExisting, CTRDGi_IsBitIDAtInit by relocation) are catalogued as DWCi_IsBuddyFriendData / DWCi_IsReverseBuddyFriendData.
- 0x02087244 (OS_IsAlarmAvailable by relocation) is catalogued as GX_GetBankForLCDC.
- 0x0207A568 is FSi_GetFilePositionIfProc by relocation, catalogued as FSi_GetFileLengthIfProc.
- 0x02150D20 is named `_ZZ15FS_StartOverlay...once` by the tool; the object uses it as the fs_overlay.o .bss base (once at +0, FSiOverlayContext at +4). Files use `fsi_overlay_state` / `FSiOverlayContext`.
- Adjacent statics addressed from one base (CARDiSlotResetCount +0/+4/+8, cardi_rom_base +0/+4/+0xC, fsi_default_dma_no +0/+4, CARDiEnableCacheInvalidationDC +0/+4, arc_list +0/+4) are modelled as small structs named after the catalog symbol.

## asm bodies

None.

## Next pass

- 0x02076540 CARDi_RequestStreamCommandCore (408 bytes, card_backup.o), not attempted; an old pending file `CARDi_RequestStreamCommandCore.c` exists there.
- 0x0207608C CARDi_InitResourceLock (40 bytes): register swap only; try more permuter seeds or an idiom search for "constant zero loaded before the base address".
- 0x02075ED4 CARDi_LockResource and 0x02076E4C CARDi_ReadRomWithCPU: both need a loop entered by a branch to its bottom test. FSi_ExecuteSyncCommand gets that shape from a two-term `&&` condition; a compound or otherwise non-duplicable test is the likely lever. LockResource is EXACT under -O4,s, but card_common.o/card_rom.o have functions that differ under -O4,s, so the flag change is not supported.
- Match the uncatalogued statics 0x020911D4, 0x0207AAF8, 0x0207AB00 (tiny) to promote 0x020911A0 and 0x0207AB10.

Permuter seeds used: 12701 to 12706.
