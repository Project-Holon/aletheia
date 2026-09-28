# sdk9_snd_catalog: libsnd, libstd, libmath, libel, libext, libcamera, crt0; SDK catalog conflicts

## Part A: matching

61 functions filed under `src/matched/arm9_sdk/` (60 EXACT, 1 EXACT*), 4,948 bytes. Each
one has its own shard, `layout/matched/arm9/pkt_<ADDR>.json`. `manifest --verify --shard
arm9/pkt_<ADDR>` was run twice over all 61: the first pass reported 60 EXACT + 1 EXACT*,
and the second rewrote 0. Header `status:` lines are copied from that output. All code was
written from the vendor object (sdkobj prototypes, locals, relocations, listing); no file
under `sdk/` was opened. Every object here carries stamp 4.0.0.1024 (dsi/1.1p1), flags
`-O4,p`, lang c99, ARM.

| address | sdk symbol | object | verdict | bytes |
|---|---|---|---|---|
| 0x02081120 | MATH_MD5Init | dgt_md5.o | EXACT | 68 |
| 0x02081164 | MATH_MD5Update | dgt_md5.o | EXACT | 200 |
| 0x0208122C | MATH_MD5GetHash | dgt_md5.o | EXACT | 180 |
| 0x02089330 | SND_StopSeq | snd_interface.o | EXACT | 32 |
| 0x02089350 | SND_PrepareSeq | snd_interface.o | EXACT | 40 |
| 0x02089398 | SND_PauseSeq | snd_interface.o | EXACT | 32 |
| 0x0208948C | SND_SetTrackAllocatableChannel | snd_interface.o | EXACT | 40 |
| 0x020894B4 | SND_StartTimer | snd_interface.o | EXACT | 40 |
| 0x020894DC | SND_StopTimer | snd_interface.o | EXACT | 100 |
| 0x02089540 | SND_SetupAlarm | snd_interface.o | EXACT | 64 |
| 0x02089580 | SND_SetTrackMute | snd_interface.o | EXACT | 48 |
| 0x020895B0 | SND_SetTrackMuteEx | snd_interface.o | EXACT | 40 |
| 0x020895D8 | SND_LockChannel | snd_interface.o | EXACT | 32 |
| 0x020895F8 | SND_UnlockChannel | snd_interface.o | EXACT | 32 |
| 0x02089618 | SND_SetChannelTimer | snd_interface.o | EXACT | 32 |
| 0x02089638 | SND_SetChannelVolume | snd_interface.o | EXACT | 40 |
| 0x02089660 | SND_SetupChannelPcm | snd_interface.o | EXACT | 76 |
| 0x020896AC | SND_InvalidateSeqData | snd_interface.o | EXACT | 32 |
| 0x020896CC | SND_InvalidateBankData | snd_interface.o | EXACT | 32 |
| 0x020896EC | SND_InvalidateWaveData | snd_interface.o | EXACT | 32 |
| 0x0208970C | SND_SetMasterVolume | snd_interface.o | EXACT | 32 |
| 0x0208972C | SND_SetOutputSelector | snd_interface.o | EXACT | 40 |
| 0x02089754 | SND_SetMasterPan | snd_interface.o | EXACT | 32 |
| 0x02089774 | SND_ResetMasterPan | snd_interface.o | EXACT | 32 |
| 0x02089794 | SND_ReadDriverInfo | snd_interface.o | EXACT | 32 |
| 0x020897B4 | SNDi_SetPlayerParam | snd_interface.o | EXACT | 40 |
| 0x020897DC | SNDi_SetTrackParam | snd_interface.o | EXACT | 40 |
| 0x02089804 | PushCommand_impl | snd_interface.o | EXACT | 68 |
| 0x02089848 | SND_Init | snd_main.o | EXACT | 56 |
| 0x02089978 | SND_RecvCommandReply | snd_command.o | EXACT | 256 |
| 0x02089A78 | SND_AllocCommand | snd_command.o | EXACT | 136 |
| 0x02089B00 | SND_PushCommand | snd_command.o | EXACT | 56 |
| 0x02089CD4 | SND_WaitForCommandProc | snd_command.o | EXACT | 108 |
| 0x02089D40 | SND_GetCurrentCommandTag | snd_command.o | EXACT | 44 |
| 0x02089D6C | SND_IsFinishedCommandTag | snd_command.o | EXACT | 80 |
| 0x02089DBC | SND_CountFreeCommand | snd_command.o | EXACT | 60 |
| 0x02089DF8 | SND_CountReservedCommand | snd_command.o | EXACT | 60 |
| 0x02089E50 | PxiFifoCallback | snd_command.o | EXACT | 36 |
| 0x02089E74 | InitPXI | snd_command.o | EXACT | 100 |
| 0x02089ED8 | RequestCommandProc | snd_command.o | EXACT | 40 |
| 0x02089F00 | AllocCommand | snd_command.o | EXACT | 72 |
| 0x02089F48 | IsCommandAvailable | snd_command.o | EXACT | 64 |
| 0x02089F88 | SND_AlarmInit | snd_alarm.o | EXACT | 56 |
| 0x02089FE0 | SNDi_SetAlarmHandler | snd_alarm.o | EXACT | 48 |
| 0x0208A010 | SNDi_CallAlarmHandler | snd_alarm.o | EXACT | 68 |
| 0x0208A07C | SND_GetChannelStatus | snd_work.o | EXACT | 40 |
| 0x0208A0A4 | SND_ReadTrackInfo | snd_work.o | EXACT | 264 |
| 0x0208A1AC | SNDi_GetFinishedCommandTag | snd_work.o | EXACT | 36 |
| 0x0208A1D0 | SNDi_InitSharedWork | snd_work.o | EXACT | 124 |
| 0x0208A24C | SND_CalcChannelVolume | snd_util.o | EXACT | 112 |
| 0x0208A2BC | SND_AssignWaveArc | snd_bank.o | EXACT | 208 |
| 0x0208A38C | SND_DestroyBank | snd_bank.o | EXACT | 152 |
| 0x0208A424 | SND_DestroyWaveArc | snd_bank.o | EXACT | 72 |
| 0x0208A640 | SND_SetWaveDataAddress | snd_bank.o | EXACT | 52 |
| 0x0208A674 | SND_GetWaveDataAddress | snd_bank.o | EXACT | 60 |
| 0x0208CADC | STD_CopyString | std_string.o | EXACT | 52 |
| 0x0208CB10 | STD_CopyLString | std_string.o | EXACT | 260 |
| 0x0208CC14 | STD_SearchString | std_string.o | EXACT | 100 |
| 0x0208CCFC | STD_GetStringNLength | std_string.o | EXACT | 152 |
| 0x0208CD94 | STD_CompareString | std_string.o | EXACT | 184 |
| 0x0208CE4C | STD_CompareNString | std_string.o | EXACT* | 232 |

Files written: `src/matched/arm9_sdk/func_<ADDR>.c` and `layout/matched/arm9/pkt_<ADDR>.json`
for each address above (61 of each).

Pending files replaced (not read):
- The 25 existing `src/pending/arm9_sdk/func_<ADDR>.c` files at snd_interface.o addresses
  (0x02089330 .. 0x02089804) were deleted, because those addresses are now matched from my
  own drafts.
- `src/pending/arm9_sdk/INITi_DoAutoload.c` and `src/pending/arm9_sdk/MATH_CalcHMACSHA1.c`
  were deleted and replaced by my own `func_02004BB4.c` and `func_020816FC.c` (below).

### Pending (my own drafts, `src/pending/arm9_sdk/`)

| address | symbol | status | residue |
|---|---|---|---|
| 0x020898A8 | SND_CommandInit (snd_command.o), 208 B | DIFF | Only the free-list loop differs. The original enters it with `b` to the test (not rotated). Every C spelling tried at -O4,p (for, while, goto, permuter seed 12902) peels the first test. The same C is EXACT at -O2, but the rest of snd_command.o only matches at -O4,p, so a spelling is missing; the flags are right. |
| 0x020816FC | MATH_CalcHMACSHA1 (dgt_sha1.o), 148 B | MATCH | Byte-correct. The one wildcard is the pool word for the compiler-generated initializer template of the local `hash2funcs` (`@12151` in the object, image 0x020A5CB8). C cannot name that symbol. match.py needs a way to name an anonymous initializer by address. |
| 0x02004BB4 | INITi_DoAutoload (crt0.HYB.TWL.o), 412 B | MATCH | Byte-correct asm. The tail `b _start_AutoloadDoneCallback` (0x02004EA8) is unresolved because that address has no witness outside this body. 0x02004EA8 is a 4-byte `bx lr` weak stub. It is labelled as the start of a 64-byte extent that overlaps the matched INITi_IsRunOnTwl (0x02004EB4). Splitting that label, or matching the stub, should make this EXACT. |

asm body and its evidence line: func_02004BB4 (INITi_DoAutoload): "crt0 code that runs before C (no C runtime yet, fixed-register stack juggling around its calls) and needs mcr p15 cache ops."

### Near misses solved, idioms worth noting

- SND_ReadTrackInfo (0x0208A0A4): the address conversion only matches as a static inline that takes `(p, info->workAddress, info)`, with the base loaded before the null test. Permuter seed 12901 pointed at the argument order.
- SND_PushCommand: the tail-merged stores need both arms written out (`list = end = cmd` / `end->next = cmd; end = cmd`). With the obvious shared tail, the base is reloaded.
- STD_CompareString / CopyLString: `(a ^ b) == 0` gives `teq`. For CompareString, declaring the locals in the reverse of the DWARF listing fixes the register colouring.
- MATH_MD5GetHash: the 64-bit length store has to be one `unsigned long long` store. Two 32-bit halves swap the register pair.
- snd_command.o statics form one .bss block addressed from sFreeList: +0 freeList, +4 finishedTag, +8 reserveList, +0xC reserveListEnd, +0x10 freeListEnd, +0x14 queueRead, +0x18 queueWrite, +0x1C waitingCount, +0x20 currentTag, plus 0x02151490 sWaitingCommandListQueue. The already-matched SND_FlushCommand labels +4 as freeListEnd, which is misleading but does not affect its bytes.

### Open rows in territory not matched: catalog false positives

These rows are not SDK code, and matching them as SDK would inflate the SDK figure:

- EL_LinkFileEx 0x020312CC and 0x020312F8. The object's EL_LoadLibraryfromFile call lands on func_020314F4 and sub_020314DC, which are matched game procsys code.
- EL_GetGlobalAdr 0x02035010, 0x02035040, 0x02035138, 0x020351F8, and EL_Export 0x02026C1C, 0x02026C78 (thumb). The catalog places EL_Export 10 times and EL_GetGlobalAdr 4 times. No other el.o function is placed in arm9, and each copy calls its own neighbour.
- CameraStandbyCallback 0x02033400. Its CAMERA_I2CActivateCore call lands on MIi_CpuClear32.
- EXT_TestResetCounter 0x02067CFC. This is a 20-byte "store 0 to a global", and no other ext_scrntest.o function is placed in arm9.

Open rows left in territory after this pass: 0x020898A8 (DIFF), 0x020816FC and 0x02004BB4 (MATCH), and the 9 false positives above.

## Part B: catalog conflicts (132 rows of `summary.sdk_conflicts`)

### Method

For each address, `tools/sdkobj.py` gave the catalog symbol's object, its listing and its relocation targets. All 132 listings show 0 concrete mismatches, so the bytes cannot decide between names. Two tests judged each name:

1. **Relocation consistency.** Each PC24 target that the object names (symbol X) has to land on an image address that is X, either by matched name or by a catalog placement of X outside the conflict rows. If X is placed at some other address, the body at this address is not the catalog symbol.
2. **Sibling placement.** A global function is defined once per region. When copies compete, the real one sits inside a run of placed functions from the same object (within a few hundred bytes, in object order).

Verdicts:

- **catalog wrong:** the object symbol at that address is not the catalog name. The matched name is right, or it is a placeholder for a game function.
- **matched name wrong:** the catalog name is right, and the matched file has a placeholder or wrong name.
- **both wrong:** neither name is the symbol at that address.
- **same symbol:** both names agree and nothing contradicts them.
- **undetermined:** no relocation or sibling separates the candidates.

Totals: catalog wrong 63 (60 plain, 2 by uniqueness, 1 from the Pre/Post pair), undetermined 27, same symbol 22, both wrong 12, matched name wrong 8.

### Real name disputes (these change a name)

- **gx_load2d.o, 14 rows (0x0207E888..0x0207F274).** The catalog claims GXS_LoadBG0Scr and GXS_LoadBG0Char at 8 addresses each. The matched GX_/GXS_LoadBGnScr/Char names are right, because each body calls the G2/G2S_GetBGnScrPtr/CharPtr with its own name. Catalog wrong.
- **gx_vramcnt.o, 10 rows (0x02080908..0x020809F0).** These are **GX_ResetBankFor{OBJ, BGExtPltt, OBJExtPltt, Tex, TexPltt, ClearImage, SubBG, SubOBJ, SubBGExtPltt, SubOBJExtPltt}**, not GX_DisableBankFor*.
  - They call resetBankForX_ (0x020808BC), and their run starts at GX_ResetBankForBG 0x020808F4.
  - The Disable family is the second run, 0x02080AD8..0x02080C23, behind disableBankForX_ (0x02080A18).
  - GXS_BeginLoadBGExtPltt (0x0207F5B0) calls 0x020809C8 as GX_ResetBankForSubBGExtPltt, which confirms the split.
  - The four matched files named GX_DisableBankFor{BGExtPltt, OBJExtPltt, SubBGExtPltt, SubOBJExtPltt} (0x0208091C, 0x02080940, 0x020809C8, 0x020809F0) have the wrong name.
- **0x0207A568** is FSi_GetFilePositionIfProc (it calls FSi_ROMFAT_GetFilePosition), not FSi_GetFileLengthIfProc.
- **OS_KillThread is 0x02085638.** It calls OS_KillThreadWithPriority, the next function. 0x0200AD9C, matched as OS_KillThread, is not: it calls MI_CpuCopy8 at that point.
- **Placeholders that should take the catalog name:** 0x02075DC8 CARD_Enable, 0x0208B798 MicWaitBusy, 0x02082658 MI_StopAllDma, 0x0208475C OS_InitIrqTable, 0x02080C34 GX_GetBankForOBJExtPltt, 0x02080BAC GX_DisableBankForSubBG and 0x02080BC0 GX_DisableBankForSubOBJ.
- **Matched files with an SDK name they are not:** 0x020271DC OS_SetPrintBlockingMode, 0x0202A170 gsXmlFreeReader, 0x0204960C NHTTPi_GetConnection, 0x02066DEC CARD_SetPulledOutCallback (the real one is 0x020774A0), 0x02078C18 CRYPTOi__BN_lshift1, 0x0207ACB4 DWC_StartUtilityEx and 0x02085D0C DWCi_CMNlFontFlag. Each one calls, under the object's callee name, a function the image knows by another name.
- **Other catalog issues found along the way:**
  - OSi_DoLockByWord (0x02084C1C) and OSi_DoTryLockByWord (0x02084CFC) look swapped: OS_LockCartridge calls 0x02084CFC as OSi_DoLockByWord.
  - Across the pm.o Append, Prepend, InsertEx and Delete placements, the catalog calls two different lists (0x0215301C and 0x02153004) "PMi_PostSleepCallbackList". Half of those rows are therefore the Pre variants.
  - 0x02084CEC and 0x02084D68 are catalogued as FSi_HasEnoughSpaceToCreateUserFile but are called as OS_LockByWord.

### Corrections table

"object symbol" is the symbol at that address according to the tests above. "game" means no SDK symbol (a game or third-party function of the same shape). "?" means undetermined.

| address | catalog name | matched name | object symbol | verdict | evidence |
|---|---|---|---|---|---|
| 0x02005D90 | ArrayDeleteAt | ArrayDeleteAt | ArrayDeleteAt | same symbol | names agree; no contradicting relocation |
| 0x02008500 | CallbackForJpeg | sub_02008500 | game | catalog wrong | calls 0x02045924 as OS_SignalEvent (real one 0x02088398) |
| 0x0200AD9C | OS_KillThread | OS_KillThread | game | both wrong | calls MI_CpuCopy8 where OS_KillThread calls OS_KillThreadWithPriority; real one is 0x02085638 |
| 0x0200B424 | DWCi_HEAPlEnd | func_0200B424 | game | catalog wrong | calls sub_020307B0 (a free wrapper) as NNS_FndDestroyExpHeap |
| 0x02010054 | CTRDGi_IsTaskAvailable | CTRDGi_IsTaskAvailable_02010054 | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x02022D78 | gpiFreeMessage | func_02022D78 | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x02026C1C | EL_Export | func_02026C1C | game | catalog wrong | EL_Export placed at 10 addresses; no other el.o function is placed in arm9; each copy calls its own neighbour as ELi_Export |
| 0x02026C78 | EL_Export | func_02026C78 | game | catalog wrong | EL_Export placed at 10 addresses; no other el.o function is placed in arm9; each copy calls its own neighbour as ELi_Export |
| 0x020271DC | OS_SetPrintBlockingMode | OS_SetPrintBlockingMode | game | both wrong | calls an OS_IsRunOnTwl copy at 0x0202708C (real one 0x02085D3C); no os_printf.o placement within 0x5D000 |
| 0x0202A170 | gsXmlFreeReader | gsXmlFreeReader | game | both wrong | calls sub_020307B0 both as ArrayFree and as gsifree |
| 0x020307B0 | ENV_SetResourceSet | sub_020307B0 | game | catalog wrong | ENV_SetResourceSet placed 7 times with 7 different ENVi_ClearLinkList targets (0x02049238 calls FS_CloseFile) |
| 0x020307C8 | CARD_CheckEnabled | func_020307C8 | game | catalog wrong | calls its own CARD_IsEnabled lookalike, not 0x02075DA0 |
| 0x02030BA4 | CARD_CheckEnabled | func_02030BA4 | game | catalog wrong | calls its own CARD_IsEnabled lookalike, not 0x02075DA0 |
| 0x0203129C | GXS_BeginLoadBGExtPltt | func_0203129C | game | catalog wrong | callee func_02031354 is not GX_ResetBankForSubBGExtPltt (0x020809C8) |
| 0x02031948 | FSi_ConvertStringSjisToUnicode | FSi_ConvertStringSjisToUnicode | ? | undetermined | no fs_file.o placement within 0x46000; STD_ConvertStringSjisToUnicode is not placed |
| 0x020345DC | FreeBucketSet | func_020345DC | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x02034704 | DWCi_ChangeScene | func_02034704 | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x02034F84 | EL_Export | func_02034F84 | game | catalog wrong | EL_Export placed at 10 addresses; no other el.o function is placed in arm9; each copy calls its own neighbour as ELi_Export |
| 0x02034FB8 | EL_Export | func_02034FB8 | game | catalog wrong | EL_Export placed at 10 addresses; no other el.o function is placed in arm9; each copy calls its own neighbour as ELi_Export |
| 0x02034FE8 | EL_Export | func_02034FE8 | game | catalog wrong | EL_Export placed at 10 addresses; no other el.o function is placed in arm9; each copy calls its own neighbour as ELi_Export |
| 0x0203516C | EL_Export | func_0203516C | game | catalog wrong | EL_Export placed at 10 addresses; no other el.o function is placed in arm9; each copy calls its own neighbour as ELi_Export |
| 0x020351A0 | EL_Export | func_020351A0 | game | catalog wrong | EL_Export placed at 10 addresses; no other el.o function is placed in arm9; each copy calls its own neighbour as ELi_Export |
| 0x020351D0 | EL_Export | func_020351D0 | game | catalog wrong | EL_Export placed at 10 addresses; no other el.o function is placed in arm9; each copy calls its own neighbour as ELi_Export |
| 0x02035390 | DWCi_IsFold | DWCi_IsFold | DWCi_IsFold | same symbol | names agree; no contradicting relocation |
| 0x02035614 | EL_Export | sub_02035614 | game | catalog wrong | EL_Export placed at 10 addresses; no other el.o function is placed in arm9; each copy calls its own neighbour as ELi_Export |
| 0x02035BA4 | NHTTP_CleanupAsync | func_02035BA4 | game | catalog wrong | three copies share one NHTTPi_GetSystemInfoP target (0x02035224); duplicate of 0x0206074C |
| 0x02035C08 | NHTTP_CleanupAsync | func_02035C08 | game | catalog wrong | three copies share one NHTTPi_GetSystemInfoP target (0x02035224); duplicate of 0x0206074C |
| 0x02035C20 | ENV_SetResourceSet | func_02035C20 | game | catalog wrong | ENV_SetResourceSet placed 7 times with 7 different ENVi_ClearLinkList targets (0x02049238 calls FS_CloseFile) |
| 0x02035C48 | ENV_SetResourceSet | func_02035C48 | game | catalog wrong | ENV_SetResourceSet placed 7 times with 7 different ENVi_ClearLinkList targets (0x02049238 calls FS_CloseFile) |
| 0x020362A4 | NHTTP_CleanupAsync | func_020362A4 | game | catalog wrong | three copies share one NHTTPi_GetSystemInfoP target (0x02035224); duplicate of 0x0206074C |
| 0x020366A8 | DWCi_IsShutdownMatch | func_020366A8 | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x02037224 | IRC_SetUnitNumber | func_02037224 | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x0203A7EC | DWC_IsValidFriendData | func_0203A7EC | game | catalog wrong | calls its own DWCi_Acc_GetFlag_DataType lookalike, not 0x0205911C |
| 0x0203A804 | DWC_IsValidFriendData | func_0203A804 | game | catalog wrong | calls its own DWCi_Acc_GetFlag_DataType lookalike, not 0x0205911C |
| 0x0203CDBC | DWCi_IsShutdownMatch | func_0203CDBC | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x0203D788 | CARD_GetThreadPriority | func_0203D788 | game | catalog wrong | 0x384B0 from any card_api.o placement, and 0x0203CDBC calls it as DWCi_GetMatchCnt |
| 0x0203DA4C | CTRDGi_IsTaskAvailable | func_0203DA4C | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x02040AE0 | FSi_HasEnoughSpaceToCreateUserFile | func_02040AE0 | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x020414AC | ENV_SetResourceSet | func_020414AC | game | catalog wrong | ENV_SetResourceSet placed 7 times with 7 different ENVi_ClearLinkList targets (0x02049238 calls FS_CloseFile) |
| 0x02045A98 | GX_GetBankForLCDC | func_02045A98 | game | catalog wrong | GX_GetBankForLCDC is 0x02080C54 inside the gx_vramcnt run; this is a 16-byte getter of the same shape |
| 0x020461D4 | IRC_SetUnitNumber | sub_020461D4 | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x020461E4 | DWCi_Language | DWCi_Language | DWCi_Language | same symbol | names agree; no contradicting relocation |
| 0x02047250 | DWCi_LSTlPopFront | DWCi_LSTlPopFront | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x02048F4C | WCM_SendDCFData | func_02048F4C | game | catalog wrong | calls func_02048D00, the same callee as the FSi_ConvertStringSjisToUnicode-shaped 0x02048F74: one-call wrappers, not cpsif.o |
| 0x02048F60 | WCM_SendDCFData | func_02048F60 | game | catalog wrong | as 0x02048F4C (callee func_02048D54) |
| 0x02048F74 | FSi_ConvertStringSjisToUnicode | func_02048F74 | game | catalog wrong | wrapper whose callee is shared with a WCM_SendDCFData-shaped wrapper |
| 0x02048F88 | FSi_ConvertStringSjisToUnicode | func_02048F88 | game | catalog wrong | wrapper whose callee is shared with a WCM_SendDCFData-shaped wrapper |
| 0x02049238 | ENV_SetResourceSet | func_02049238 | game | catalog wrong | ENV_SetResourceSet placed 7 times with 7 different ENVi_ClearLinkList targets (0x02049238 calls FS_CloseFile) |
| 0x0204960C | NHTTPi_GetConnection | NHTTPi_GetConnection | game | both wrong | calls 0x02078B44 (FS_SeekFile) as NHTTPi_ControlConnectionList |
| 0x0204B084 | ENV_SetResourceSet | func_0204B084 | game | catalog wrong | ENV_SetResourceSet placed 7 times with 7 different ENVi_ClearLinkList targets (0x02049238 calls FS_CloseFile) |
| 0x0204E6E0 | CARD_GetBackupSectorSize | func_0204E6E0 | ? | undetermined | near a second card_backup placement (CARD_GetCurrentBackupType 0x0204EA38); duplicate of 0x02076B6C |
| 0x020514F4 | KeyValHashKey | func_020514F4 | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x02051620 | KeyValHashKey | KeyValHashKey | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x020588D0 | DWC_BACKUPlCheckAddress | DWC_BACKUPlCheckAddress | DWC_BACKUPlCheckAddress | same symbol | names agree; no contradicting relocation |
| 0x020596B0 | DWC_GHTTPCleanupRootCAList | func_020596B0 | game | catalog wrong | calls 0x0205911C (DWCi_Acc_GetFlag_DataType) as ghttpCleanupRootCAList |
| 0x020596D8 | DWC_IsValidFriendData | DWC_IsValidFriendData | DWC_IsValidFriendData | same symbol | callee DWCi_Acc_GetFlag_DataType agrees, 0x10 after DWCi_Acc_IsAuthentic |
| 0x0205A11C | CARDi_CommandBegin | CARDi_CommandBegin | CARDi_CommandBegin | same symbol | names agree; no contradicting relocation |
| 0x0206074C | NHTTP_CleanupAsync | NHTTP_CleanupAsync | NHTTP_CleanupAsync | same symbol | callees are its own neighbours (0x020606A8, 0x020605B4), near NHTTPi_InitRequestInfo 0x02061DF0 |
| 0x02061DF0 | NHTTPi_InitRequestInfo | NHTTPi_InitRequestInfo | NHTTPi_InitRequestInfo | same symbol | in the nhttp run beside 0x0206074C |
| 0x02061EA4 | DWCi_TSKlForm | DWCi_TSKlForm | DWCi_TSKlForm | same symbol | names agree; no contradicting relocation |
| 0x02062810 | DWCi_LSTlPushBack | func_02062810 | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x0206295C | DWCi_LSTlPushBack | func_0206295C | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x0206434C | ENV_SetResourceSet | ENV_SetResourceSet | ENV_SetResourceSet? | undetermined | callees nearby (0x0206419C, 0x02062FF0) but unnamed; env_system.o not corroborated (0x020913BC is wrong) |
| 0x02066DEC | CARD_SetPulledOutCallback | CARD_SetPulledOutCallback | game | both wrong | CARD_SetPulledOutCallback is 0x020774A0 inside the card_pullout.o run |
| 0x02066DFC | CTRDGi_CallbackForSetPhi | CTRDGi_CallbackForSetPhi | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x02066E10 | CARD_Enable | func_02066E10 | game | catalog wrong | duplicate of the global CARD_Enable placed at 0x02075DC8 |
| 0x0206DB24 | CTRDGi_IsTaskAvailable | CTRDGi_IsTaskAvailable | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x0206DBF4 | NHTTPi_InitRequestInfo | func_0206DBF4 | ? | catalog wrong (by uniqueness) | no relocation to test; duplicate of the global at 0x02061DF0 |
| 0x02072E9C | NHTTPi_InitRequestInfo | func_02072E9C | ? | catalog wrong (by uniqueness) | no relocation to test; duplicate of the global at 0x02061DF0 |
| 0x02073BE0 | DWC_IsSendableReliable | func_02073BE0 | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x020749B4 | FATFS_FormatDrive | unit_020749B4 | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x02074A54 | DWCi_IsShutdownMatch | DWCi_IsShutdownMatch | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x02075DB0 | CARD_CheckEnabled | CARD_CheckEnabled | CARD_CheckEnabled | same symbol | callee CARD_IsEnabled 0x02075DA0 agrees |
| 0x02075DC8 | CARD_Enable | func_02075DC8 | CARD_Enable | matched name wrong | CARD_Enable: flush between CARD_IsEnabled and CARD_GetResultCode in card_api.o run |
| 0x02076B6C | CARD_GetBackupSectorSize | CARD_GetBackupSectorSize | CARD_GetBackupSectorSize | same symbol | 0x2C before CARD_CancelBackupAsync |
| 0x02078C18 | CRYPTOi__BN_lshift1 | CRYPTOi__BN_lshift1 | game | both wrong | calls 0x020789FC (FS_OpenFileEx) as CRYPTOi__BN_lshift |
| 0x0207A528 | FSi_GetFileLengthIfProc | FSi_GetFileLengthIfProc | FSi_GetFileLengthIfProc | same symbol | callee FSi_ROMFAT_GetFileLength agrees |
| 0x0207A568 | FSi_GetFileLengthIfProc | FSi_GetFilePositionIfProc | FSi_GetFilePositionIfProc | catalog wrong | calls FSi_ROMFAT_GetFilePosition 0x0207A218; matched name agrees |
| 0x0207ACB4 | DWC_StartUtilityEx | DWC_StartUtilityEx | game | both wrong | calls FS_LoadArchiveTables as DWC_StartUtility |
| 0x0207E888 | GXS_LoadBG0Scr | GX_LoadBG0Scr | GX_LoadBG0Scr | catalog wrong | calls the image G2/G2S_Get*ScrPtr that names it; GXS_LoadBG0Scr is 0x0207E944 |
| 0x0207E944 | GXS_LoadBG0Scr | GXS_LoadBG0Scr | GXS_LoadBG0Scr | same symbol | callee G2S_GetBG0ScrPtr agrees |
| 0x0207EA00 | GXS_LoadBG0Scr | GX_LoadBG1Scr | GX_LoadBG1Scr | catalog wrong | calls the image G2/G2S_Get*ScrPtr that names it; GXS_LoadBG0Scr is 0x0207E944 |
| 0x0207EABC | GXS_LoadBG0Scr | GXS_LoadBG1Scr | GXS_LoadBG1Scr | catalog wrong | calls the image G2/G2S_Get*ScrPtr that names it; GXS_LoadBG0Scr is 0x0207E944 |
| 0x0207EB78 | GXS_LoadBG0Scr | GX_LoadBG2Scr | GX_LoadBG2Scr | catalog wrong | calls the image G2/G2S_Get*ScrPtr that names it; GXS_LoadBG0Scr is 0x0207E944 |
| 0x0207EC34 | GXS_LoadBG0Scr | GXS_LoadBG2Scr | GXS_LoadBG2Scr | catalog wrong | calls the image G2/G2S_Get*ScrPtr that names it; GXS_LoadBG0Scr is 0x0207E944 |
| 0x0207ECF0 | GXS_LoadBG0Scr | GX_LoadBG3Scr | GX_LoadBG3Scr | catalog wrong | calls the image G2/G2S_Get*ScrPtr that names it; GXS_LoadBG0Scr is 0x0207E944 |
| 0x0207EDAC | GXS_LoadBG0Scr | GXS_LoadBG3Scr | GXS_LoadBG3Scr | catalog wrong | calls the image G2/G2S_Get*ScrPtr that names it; GXS_LoadBG0Scr is 0x0207E944 |
| 0x0207EE68 | GXS_LoadBG0Char | GX_LoadBG0Char | GX_LoadBG0Char | catalog wrong | calls the image G2/G2S_Get*CharPtr that names it; GXS_LoadBG0Char is 0x0207EEFC |
| 0x0207EEFC | GXS_LoadBG0Char | GXS_LoadBG0Char | GXS_LoadBG0Char | same symbol | callee G2S_GetBG0CharPtr agrees |
| 0x0207EF90 | GXS_LoadBG0Char | GX_LoadBG1Char | GX_LoadBG1Char | catalog wrong | calls the image G2/G2S_Get*CharPtr that names it; GXS_LoadBG0Char is 0x0207EEFC |
| 0x0207F024 | GXS_LoadBG0Char | GXS_LoadBG1Char | GXS_LoadBG1Char | catalog wrong | calls the image G2/G2S_Get*CharPtr that names it; GXS_LoadBG0Char is 0x0207EEFC |
| 0x0207F0B8 | GXS_LoadBG0Char | GX_LoadBG2Char | GX_LoadBG2Char | catalog wrong | calls the image G2/G2S_Get*CharPtr that names it; GXS_LoadBG0Char is 0x0207EEFC |
| 0x0207F14C | GXS_LoadBG0Char | GXS_LoadBG2Char | GXS_LoadBG2Char | catalog wrong | calls the image G2/G2S_Get*CharPtr that names it; GXS_LoadBG0Char is 0x0207EEFC |
| 0x0207F1E0 | GXS_LoadBG0Char | GX_LoadBG3Char | GX_LoadBG3Char | catalog wrong | calls the image G2/G2S_Get*CharPtr that names it; GXS_LoadBG0Char is 0x0207EEFC |
| 0x0207F274 | GXS_LoadBG0Char | GXS_LoadBG3Char | GXS_LoadBG3Char | catalog wrong | calls the image G2/G2S_Get*CharPtr that names it; GXS_LoadBG0Char is 0x0207EEFC |
| 0x0207F5B0 | GXS_BeginLoadBGExtPltt | GXS_BeginLoadBGExtPltt | GXS_BeginLoadBGExtPltt | same symbol | callee 0x020809C8 is GX_ResetBankForSubBGExtPltt |
| 0x02080908 | GX_DisableBankForOBJ | func_02080908 | GX_ResetBankForOBJ | catalog wrong | calls resetBankForX_ (0x020808BC), not disableBankForX_; Reset run starts at GX_ResetBankForBG 0x020808F4; the Disable twin sits in 0x02080AD8..0x02080C23 |
| 0x0208091C | GX_DisableBankForBGExtPltt | GX_DisableBankForBGExtPltt | GX_ResetBankForBGExtPltt | both wrong | calls resetBankForX_ (0x020808BC), not disableBankForX_; Reset run starts at GX_ResetBankForBG 0x020808F4; the Disable twin sits in 0x02080AD8..0x02080C23 |
| 0x02080940 | GX_DisableBankForOBJExtPltt | GX_DisableBankForOBJExtPltt | GX_ResetBankForOBJExtPltt | both wrong | calls resetBankForX_ (0x020808BC), not disableBankForX_; Reset run starts at GX_ResetBankForBG 0x020808F4; the Disable twin sits in 0x02080AD8..0x02080C23 |
| 0x02080964 | GX_DisableBankForTex | func_02080964 | GX_ResetBankForTex | catalog wrong | calls resetBankForX_ (0x020808BC), not disableBankForX_; Reset run starts at GX_ResetBankForBG 0x020808F4; the Disable twin sits in 0x02080AD8..0x02080C23 |
| 0x02080978 | GX_DisableBankForTexPltt | func_02080978 | GX_ResetBankForTexPltt | catalog wrong | calls resetBankForX_ (0x020808BC), not disableBankForX_; Reset run starts at GX_ResetBankForBG 0x020808F4; the Disable twin sits in 0x02080AD8..0x02080C23 |
| 0x0208098C | GX_DisableBankForClearImage | func_0208098C | GX_ResetBankForClearImage | catalog wrong | calls resetBankForX_ (0x020808BC), not disableBankForX_; Reset run starts at GX_ResetBankForBG 0x020808F4; the Disable twin sits in 0x02080AD8..0x02080C23 |
| 0x020809A0 | GX_DisableBankForSubBG | func_020809A0 | GX_ResetBankForSubBG | catalog wrong | calls resetBankForX_ (0x020808BC), not disableBankForX_; Reset run starts at GX_ResetBankForBG 0x020808F4; the Disable twin sits in 0x02080AD8..0x02080C23 |
| 0x020809B4 | GX_DisableBankForSubOBJ | func_020809B4 | GX_ResetBankForSubOBJ | catalog wrong | calls resetBankForX_ (0x020808BC), not disableBankForX_; Reset run starts at GX_ResetBankForBG 0x020808F4; the Disable twin sits in 0x02080AD8..0x02080C23 |
| 0x020809C8 | GX_DisableBankForSubBGExtPltt | GX_DisableBankForSubBGExtPltt | GX_ResetBankForSubBGExtPltt | both wrong | calls resetBankForX_ (0x020808BC), not disableBankForX_; Reset run starts at GX_ResetBankForBG 0x020808F4; the Disable twin sits in 0x02080AD8..0x02080C23 |
| 0x020809F0 | GX_DisableBankForSubOBJExtPltt | GX_DisableBankForSubOBJExtPltt | GX_ResetBankForSubOBJExtPltt | both wrong | calls resetBankForX_ (0x020808BC), not disableBankForX_; Reset run starts at GX_ResetBankForBG 0x020808F4; the Disable twin sits in 0x02080AD8..0x02080C23 |
| 0x02080BAC | GX_DisableBankForSubBG | func_02080BAC | GX_DisableBankForSubBG | matched name wrong | calls disableBankForX_ 0x02080A18, inside the Disable run; placeholder should take the catalog name |
| 0x02080BC0 | GX_DisableBankForSubOBJ | func_02080BC0 | GX_DisableBankForSubOBJ | matched name wrong | calls disableBankForX_ 0x02080A18, inside the Disable run; placeholder should take the catalog name |
| 0x02080C34 | GX_GetBankForOBJExtPltt | func_02080C34 | GX_GetBankForOBJExtPltt | matched name wrong | inside the GX_GetBankFor* run (GX_GetBankForOBJ 0x02080C24 +0x10); copy at 0x0208AF08 is the stray |
| 0x020821B0 | MI_SetWramBank | MI_SetWramBank | MI_SetWramBank | same symbol | names agree; no contradicting relocation |
| 0x02082658 | MI_StopAllDma | func_02082658 | MI_StopAllDma | matched name wrong | MI_StopAllDma: callee MI_StopDma agrees, 0x28 before MIi_CheckAnotherAutoDMA |
| 0x02082A7C | MIi_CpuClear32 | MIi_CpuClear32 | MIi_CpuClear32 | same symbol | names agree; no contradicting relocation |
| 0x020842A0 | NVRAMi_VerifyDataArray | NVRAMi_VerifyDataArray | NVRAMi_VerifyDataArray | same symbol | names agree; no contradicting relocation |
| 0x0208475C | OS_InitIrqTable | func_0208475C | OS_InitIrqTable | matched name wrong | OS_InitIrqTable: 0x18 before OS_SetIrqFunction |
| 0x02084DA4 | OS_LockCartridge | OS_LockCartridge | OS_LockCartridge | same symbol | OSi_AllocateCartridgeBus agrees; its OSi_DoLockByWord target 0x02084CFC is catalogued OSi_DoTryLockByWord, so that pair (0x02084C1C/0x02084CFC) looks swapped |
| 0x02084E10 | OS_LockCard | func_02084E10 | game | catalog wrong | calls 0x02084E98 (OSi_FreeCardBus) where OS_LockCard calls OSi_AllocateCardBus |
| 0x02084E38 | OS_LockCard | OS_LockCard | OS_LockCard | same symbol | callee OSi_AllocateCardBus 0x02084E54 agrees |
| 0x02085638 | OS_KillThread | func_02085638 | OS_KillThread | matched name wrong | OS_KillThread: calls OS_KillThreadWithPriority 0x0208565C (the next function) |
| 0x02085D0C | DWCi_CMNlFontFlag | DWCi_CMNlFontFlag | game | both wrong | calls 0x02087B04 (OS_GetBootType) as DWCi_Language |
| 0x02086CE0 | OS_GetDTCMAddress | OS_GetDTCMAddress | OS_GetDTCMAddress | same symbol | names agree; no contradicting relocation |
| 0x02087058 | GX_GetBankForLCDC | func_02087058 | game | catalog wrong | GX_GetBankForLCDC is 0x02080C54 inside the gx_vramcnt run; this is a 16-byte getter of the same shape |
| 0x02087244 | GX_GetBankForLCDC | func_02087244 | game | catalog wrong | GX_GetBankForLCDC is 0x02080C54 inside the gx_vramcnt run; this is a 16-byte getter of the same shape |
| 0x02087DC4 | OS_IsAvailableWireless | OS_IsAvailableWireless | OS_IsAvailableWireless | same symbol | names agree; no contradicting relocation |
| 0x02088118 | CTRDGi_CallbackForSetPhi | func_02088118 | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x02088ED4 | MicWaitBusy | func_02088ED4 | game | catalog wrong | duplicate of MicWaitBusy (0x0208B798), 0x2378 from mic.o run |
| 0x0208B798 | MicWaitBusy | func_0208B798 | MicWaitBusy | matched name wrong | MicWaitBusy: 0x3C after MicStopAutoSampling in mic.o run |
| 0x0208C86C | PM_DeletePostSleepCallback | func_0208C86C | PM_Delete{Pre|Post}SleepCallback | catalog wrong (one of the pair) | 0x0208C86C and 0x0208C884 delete from different lists (0x0215301C vs 0x02153004); only one can be PM_DeletePostSleepCallback. The catalog also names both lists "Post" across Append/Prepend/InsertEx |
| 0x0208C884 | PM_DeletePostSleepCallback | PM_DeletePostSleepCallback | PM_Delete{Pre|Post}SleepCallback | undetermined | see 0x0208C86C |
| 0x0208F370 | FSi_HasEnoughSpaceToCreateUserFile | FSi_HasEnoughSpaceToCreateUserFile | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x020913BC | ENV_PrependResourceSet | func_020913BC | game | catalog wrong | calls OS_ReferentSize as ENV_InsertResourceSet |
| 0x020913E8 | ghiFreeTempBuffer | ghiFreeTempBuffer | ? | undetermined | no discriminating relocation and no placed sibling of the object |
| 0x020946C8 | CARD_Enable | func_020946C8 | game | catalog wrong | duplicate of the global CARD_Enable placed at 0x02075DC8 |

### Proposed minimal change to tools/libmatch.py (not applied)

**Cause.**
- `collect()` deduplicates patterns by (name, bytes). Functions whose masked bytes are identical therefore become separate patterns that hit the same addresses.
- The greedy pass breaks ties with `patterns[pi].name`, and nothing stops one global name from taking every address it hits (up to MAX_HITS = 8).
- Alphabetically `GXS_` < `GX_` and `GX_Disable` < `GX_Reset`, so one name took each whole family.
- Separately, a short global that also matches same-shaped game code keeps whichever copy the tie-break reaches first.

**Fix.**
- Break ties by the object's section order (the link order) instead of by name.
- Place a global name at most once per region. Among its copies, prefer the one with the most same-object neighbours that hit uniquely nearby.
- Statics (STB_LOCAL) stay exempt, because libdwcutil's scene objects legitimately repeat them.

```diff
--- a/tools/libmatch.py
+++ b/tools/libmatch.py
@@ class Pattern:
     __slots__ = ("name", "data", "runs", "thumb", "size", "concrete", "key", "klen",
-                 "koff", "alts", "order")
+                 "koff", "alts", "order", "glob")
@@ def __init__(self, name, data, runs, thumb, alts=()):
         self.order = (0, 0)       # (section index, offset) in the source object
+        self.glob = True          # STB_GLOBAL/WEAK: defined once per region
@@ def build_patterns(obj, want_data=False):
         pat = Pattern(name, bytes(blob), runs, thumb, sorted(set(alts)))
         pat.order = (shndx, value)
+        pat.glob = bind != 0      # STB_LOCAL statics may legitimately repeat
         out.append(pat)
@@ def run(args):
     cands = defaultdict(list)
+    # Support for one hit: other functions of the same object that hit exactly
+    # once within 4 KiB.  Picks the real copy of a global among lookalikes.
+    obj_funcs = getattr(collect, "obj_funcs", {})
+    sibs = defaultdict(set)                  # pattern -> patterns of its object
+    for funcs_list in obj_funcs.values():
+        for funcs in funcs_list:
+            for pi in funcs:
+                sibs[pi].update(funcs)
+    once = {pi: next(iter(set(l))) for pi, l in hits.items() if len(set(l)) == 1}
+    def support(pi, reg, addr):
+        return sum(1 for pj in sibs[pi] if pj != pi and pj in once
+                   and once[pj][0] == reg and abs(once[pj][1] - addr) <= 0x1000)
     for pi, locs in hits.items():
         uniq = sorted(set(locs))
         if len(uniq) > MAX_HITS:
             continue
         p = patterns[pi]
         for reg, addr in uniq:
-            cands[reg].append((addr, p.size, p.concrete, prov_score(pi), pi))
+            cands[reg].append((addr, p.size, p.concrete, prov_score(pi), pi,
+                               support(pi, reg, addr)))
@@
     for reg, lst in cands.items():
-        lst.sort(key=lambda c: (-c[1], -c[2], -c[3], patterns[c[4]].name))
+        # Same-bytes families (GX_/GXS_LoadBGnScr, GX_Reset/DisableBankForX)
+        # are split by link order; copies of one name by object support.
+        lst.sort(key=lambda c: (-c[1], -c[2], -c[3], -c[5],
+                                patterns[c[4]].order, c[0]))
         taken = taken_by_reg[reg] = []      # sorted list of (start, end)
-        for addr, size, concrete, sc, pi in lst:
+        placed = set()                      # global names placed in reg
+        for addr, size, concrete, sc, pi, _sup in lst:
+            if patterns[pi].glob and patterns[pi].name in placed:
+                continue                    # leave the address to a twin
             end = addr + size
@@
             taken.append((addr, end))
             taken.sort()
             resolved[(reg, addr)] = pi
+            placed.add(patterns[pi].name)
```

**Scope and caveats.**
- Pass 2 (adjacency) already works from object order, so it is unchanged.
- `order` only compares meaningfully within one object. Across objects the tie-break stays arbitrary, as the name tie-break was.
- Support is ordered before link order. A copy inside its object's run therefore beats a lone game lookalike. That fixes CARD_CheckEnabled, CARD_Enable, MicWaitBusy, OS_KillThread and GX_GetBankForLCDC.

**Follow-up (not minimal, and flagged because it moves the SDK denominator).** Drop a placement when a named PC24 target of the object is placed at a different address in the same region (test 1 above).
- This would remove most of the 63 catalog-wrong rows (EL_*, ENV_*, the DWC wrappers), which no ordering rule can fix.
- It needs `build_patterns` to keep relocation symbol names.

## Next pass

- 0x020898A8 SND_CommandInit: find the -O4,p spelling that keeps the loop unrotated.
- 0x02004EA8: split the label (a 4-byte `bx lr`, _start_AutoloadDoneCallback) so that INITi_DoAutoload verifies EXACT.
- match.py: support naming an anonymous initializer by address (needed for MATH_CalcHMACSHA1).
- Integrator:
  - Rename the four GX_DisableBankFor* matched files at 0x0208091C, 0x02080940, 0x020809C8 and 0x020809F0 to GX_ResetBankFor*.
  - Apply the other renames under "Real name disputes".
  - Decide whether the 9 libel/libext/libcamera open rows leave the SDK union.
- Permuter seeds used: 12901 (0x0208A0A4, solved) and 12902 (0x020898A8, no match).
