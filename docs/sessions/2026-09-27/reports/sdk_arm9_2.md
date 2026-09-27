# sdk_arm9_2 lane report (2026-09-27)

31 EXACT/EXACT*, all dsi/1.1p1 (no pins). Two trees, 33 functions, two near misses.

**WmReceiveFifo 0x0208E5BC** (10): WmReceiveFifo, WM_Finish, WMi_CheckStateEx, OS_Terminate,
OSi_SendToPxi, PXI_SendWordByFifo, PXI_SetFifoRecvCallback, FATFSi_IsInitialized (twl 0x02704318,
an unlabelled 12-byte leaf; shard twl/pkt_02704318), MI_CpuFill8 and MI_CpuCopy8 (asm, EXACT*).

**NVRAMi_WriteCallback 0x020839E8** (23): 22 callees EXACT: NVRAMi_PageWrite, _SoftwareReset,
_WriteEnable, _WriteDisable, _ReadStatusRegister, _AlarmHandler, _Callback; OS_GetTick, OS_SetAlarm,
OSi_InsertAlarm, OSi_SetTimer, OSi_EnterTimerCallback, OS_EnableIrqMask; OS_WakeupThread,
OSi_RemoveLinkFromQueue, OSi_RescheduleThread, OS_SelectThread; OS_SaveContext, OS_LoadContext,
CP_SaveContext, CPi_RestoreContext (asm). The root is a near miss:
docs/notes/pkt_020839E8.c.txt (1000 B vs 992: result register and switch head).

**MTX_Concat44 0x0207BE14**: near miss (spill/scheduling; 864 B vs 956), docs/notes/pkt_0207BE14.c.txt.

What closed them: first drafts from DWARF plus the image. Levers: OS_GetTick needs the tick counter
volatile; PXI_SetFifoRecvCallback needs OS_GetSystemWork() as an inline function (the macro folds
0x02FFFC00+0x388 into one pool word); OSi_EnterTimerCallback writes `1 << (timerNo + 3)`.
Statics use section-relative structs (wm_system, os_tick, os_alarm, os_thread, os_terminate, nvram
.bss). Taking a global's address uses its own symbol, but a direct access goes through the section
base (OSi_ThreadInfo, nvramTemp).

Shards verified twice (second pass: 0 rewritten): arm9/pkt_ 020775B8 020775F8 02082BCC 02082D44
02084204 02084288 020842D8 02084304 02084330 020844A8 02084570 020848F8 02084968 02084A84 02085044
020851A0 02085800 02085890 02085C08 02085C54 020870D0 02087180 02087264 0208738C 02088234 020885A0
02088610 0208E2B8 0208E52C 0208E5BC; twl/pkt_02704318. `manifest --check` clean.

Remaining roots, not started: ProcessBlock 0x02080D68, FSi_InvokeCommand 0x02077758,
FSi_GetPathDefault 0x0207976C, MTX_Inverse43 0x0207B67C, CARDi_IdentifyBackupCore2 0x020766D8.
Also open: NVRAMi_ReadCallback 0x020837B8, NVRAMi_VerifyCallback 0x02083FA0.

Integrator: the one twl shard is new (FATFSi_IsInitialized).
