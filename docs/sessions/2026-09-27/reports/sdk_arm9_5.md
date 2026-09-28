# sdk_arm9_5 lane report (2026-09-28, relaunch)

All work was done under dsi/1.1p1 with no pins, from vendor objects only. No file under sdk/ was opened.

**Salvaged from the cut run: 47 sources, all re-verified** (44 EXACT, 3 EXACT*). Each shard was verified twice, and the second pass rewrote nothing.
- PM_GoSleepMode callees and pm.o: PMi_WaitBusy*, PMi_CallCallbackAndUnlock, PMi_WaitVBlank, PMi_TryToSendPxiData(+TillSuccess), PMi_SendSleepStart, PM_SendUtilityCommand(+Async), PMi_SetLED(+Async), PM_SetBackLight(+Async), PM_ForceToPowerOff(+Async), PMi_ForceToPowerOff, PM_GetBattery, PM_GetBackLight, PM_GetAmp, PMi_SendPxiData, PMi_PreSleepForDma, PMi_SetLCDPower, PM_SetLCDPower, PM_GetLEDPattern, PMi_LCDOnAvoidReset.
- os_interrupt.o: OS_SetIrqFunction, OS_GetIrqFunction, OSi_EnterDmaCallback*, OSi_EnterNDmaCallback (the NDMA veneer), OS_SetIrqMask, OS_DisableIrqMask, OS_ResetRequestIrqMask, OS_SetIrqStackChecker*. Also OS_SpinWaitSysCycles.
- ctrdg: CTRDG_IsExisting, CTRDGi_ChangeLatestAccessCycle, CTRDGi_RestoreAccessCycle, CTRDGi_UnlockByProcessor.
- wm_system.o: WM_Init, WMi_SendCommandDirect, WMi_CheckIdle, WMi_GetStatusAddress, WMi_RegisterSleepCallback, WmSleepCallback.
- Roots: FS_NormalizePath, MTX_Inverse33, MTX_FrustumW, TPi_TpCallback.

**Left over from earlier lanes** (EXACT, never committed): sdk_arm9_3's CARDi_IdentifyBackupCore2 and MTX_Concat44 (sources and shards). Also sdk_arm9_4's shard pkt_0208E3A0 (WMi_SendCommand), whose source is tracked.

**New in this run: nothing closed.**
- WmInitCore 0208E038 is still a near miss. The original keeps both loop entry tests. I re-measured the draft at 624/640 bytes (the note had said 640/640) and tried five more loop spellings. Permuter seed 8901 was spent in the cut run.
- WM_StepDataSharing 020902D8: the fresh-draft pass is still 3 instructions out. I tried the 24 legal child-block orders and the scope and shadowing layouts. The permuter was not rerun.
- Both notes carry dated sdk_arm9_5 markers.

**Integrator:**
- Stage the 47 sources above plus the 2 leftover sources.
- Stage the 50 arm9 shards (47 + 2 + pkt_0208E3A0). The pkt list is the untracked `layout/matched/arm9/pkt_0*.json`, minus pkt_02015FBC, 02015FD4 and 02051A34, which are not this lane's.
- Stage docs/notes/pkt_0208E038.c.txt (new) and the appends to pkt_020902D8.c.txt.
- Decide whether MTX_Concat44 and CARDi_IdentifyBackupCore2 (vendor source text) are acceptable.

**Remainder:**
- WM_StepDataSharing, WmInitCore.
- Largest open arm9 rows: MATH_QSort 02081BE4, MTX_Concat43 0207B9F0, FSi_FindPathDefault 02079558, MTX_OrthoW 0207C554, GX_SetBankForBG 0207FDCC, MATH_SHA1GetHash 020814C0, TP_CalcCalibrateParam 0208AF18.

Seeds: none.
