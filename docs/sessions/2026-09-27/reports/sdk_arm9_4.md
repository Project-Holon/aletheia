# sdk_arm9_4 lane report (2026-09-28)

22 functions are EXACT/EXACT* under dsi/1.1p1, with no pins. There is one near miss. Every function was derived from the image, the vendor object (sdkobj DWARF, relocations, .bss offsets) and the idiom index. No file under sdk/ was opened.

**WM_StepDataSharing tree (wm_ds.o and its callees, 20 functions).** EXACT: WM_StartDataSharing, WM_EndDataSharing, WM_GetSharedDataAddress, and the statics WmDataSharingSetDataCallback, WmDataSharingReceiveCallback_Parent and _Child, WmDataSharingReceiveData, WmDataSharingSendDataSet and WmGetSharedDataAddress. Also EXACT: WM_GetAID, WM_GetConnectedAIDs, WM_SetPortCallback, WM_SetMPDataToPortEx, WMi_SendCommand, WmGetCommandBuffer4Arm7, OS_SendMessage, OS_ReceiveMessage, OS_JamMessage and MATH_CountPopulation.
The root is a near miss: 816/816 bytes, 3 instructions differ (see docs/notes/pkt_020902D8.c.txt).

**MI_CpuMove (EXACT*) and MI_CpuCopy (EXACT).** Both are hand-written asm, transcribed from the image into pre-UAL asm.

**PM_GoSleepMode: EXACT.** The IME swaps are an inline helper, and temporaries pin the wake-flag order.

What closed them:
- `% 4u` index wraps.
- `u16 connectedAIDs = 1;` as a declaration initialiser. New idiom: a-constant-loaded-at-entry-into-a-callee-saved-register-is-a-declaration-initialiser.
- Updating the parameter and passing it (`aidBitmap |= ...`).
- Empty switch arms (7, 9, 25, 26) in the child callback.

Shards were verified twice. The second pass rewrote nothing. They are: arm9/pkt_0208E9EC 0208EA1C 02090608 020908F8 020909C8 02090B6C 02090B18 02080D24 0209028C 0208EB0C 0208FCB4 02085DBC 02085E50 02085EF0 0208E340 0208E3A0 020906E0 02090814 0209004C 02083194 02082EA4 0208C154. `manifest --check` is clean.

Permuter: seed 8301, on WM_StepDataSharing only. It gave no improvement.

**Remainder for the next lane:**
- PM_GoSleepMode's open callees: OS_DisableIrqMask 02084998, OS_SetIrqMask 0208493C, CTRDG_IsExisting 02090F50, PM_GetBackLight 0208BFD0, OS_SpinWaitSysCycles 02087A04, PM_SetBackLight 0208BDD8, PMi_WaitVBlank 0208B87C, PMi_PreSleepForDma 0208C0AC, PMi_SendSleepStart 0208BBB8, PMi_SetLCDPower 0208C44C, PMi_SetLED 0208BD28, PM_ForceToPowerOff 0208BEA4. The pm.o .bss is at 0x02153000; offsets are in the PM_GoSleepMode header.
- Roots not started: FS_NormalizePath 02078078, MTX_Inverse33 0207B0A4, WmInitCore 0208E038, TPi_TpCallback 0208A6B0, MTX_FrustumW 0207C1D0.
- Open rows in wm_system.o: WM_Init, WMi_CheckIdle, WMi_GetStatusAddress, WMi_RegisterSleepCallback, WMi_SendCommandDirect.

**Integrator:** stage the 22 sources and shards above, the note and the idiom file. Seeds: none.
