# sdk9_wm report (libwm, libnwm, libcps; arm9)

43 open rows in territory (libdwcac rows at 0x0205A7CC and 0x0205D01C are not this lane's).
40 filed EXACT/EXACT*, 2 left in pending, 1 not attempted (WM_StepDataSharing, context budget).
All C written from sdkobj/match.py output only; no sdk/ source opened; no pre-existing pending file at any of these addresses.

## Filed (src/matched/arm9_sdk/func_ADDR.c, layout/matched/arm9/pkt_ADDR.json; manifest --verify twice, second pass 0 rewritten)

| address | symbol (object) | bytes | verdict |
| --- | --- | --- | --- |
| 0x0208EAA0 | NWMi_CheckEnableFlag (nwm_init.o) | 40 | EXACT |
| 0x0208EAC8 | WM_SetIndCallback (wm_sync.o) | 68 | EXACT |
| 0x0208EBE4 | WM_ReadStatus (wm_sync.o) | 80 | EXACT |
| 0x0208EC34 | WM_GetMPSendBufferSize (wm_sync.o) | 112 | EXACT |
| 0x0208ECA4 | WM_GetMPReceiveBufferSize (wm_sync.o) | 204 | EXACT |
| 0x0208ED70 | WM_ReadMPData (wm_sync.o) | 240 | EXACT |
| 0x0208EE60 | WM_GetAllowedChannel (wm_sync.o) | 60 | EXACT |
| 0x0208EE9C | WM_GetLinkLevel (wm_sync.o) | 148 | EXACT |
| 0x0208EF30 | WM_GetDispersionBeaconPeriod (wm_sync.o) | 148 | EXACT |
| 0x0208EFC4 | WM_GetDispersionScanPeriod (wm_sync.o) | 152 | EXACT |
| 0x0208F05C | WM_GetOtherElements (wm_sync.o) | 344 | EXACT |
| 0x0208F1B4 | WM_GetNextTgid (wm_sync.o) | 112 | EXACT* |
| 0x0208F234 | WMi_EnableEx (wm_standard.o) | 108 | EXACT |
| 0x0208F2A0 | WM_Disable (wm_standard.o) | 68 | EXACT |
| 0x0208F2E4 | WM_PowerOn (wm_standard.o) | 68 | EXACT |
| 0x0208F328 | WM_PowerOff (wm_standard.o) | 72 | EXACT |
| 0x0208F380 | WM_InitializeForListening (wm_standard.o) | 24 | EXACT |
| 0x0208F398 | WMi_InitializeEx (wm_standard.o) | 104 | EXACT |
| 0x0208F400 | WM_Reset (wm_standard.o) | 60 | EXACT |
| 0x0208F43C | WM_End (wm_standard.o) | 68 | EXACT |
| 0x0208F480 | WM_SetParentParameter (wm_standard.o) | 248 | EXACT |
| 0x0208F578 | WmCheckParentParameter (wm_standard.o) | 80 | EXACT |
| 0x0208F5C8 | WMi_StartParentEx (wm_standard.o) | 124 | EXACT* |
| 0x0208F654 | WM_EndParent (wm_standard.o) | 68 | EXACT |
| 0x0208F698 | WM_StartScanEx (wm_standard.o) | 368 | EXACT |
| 0x0208F808 | WM_EndScan (wm_standard.o) | 68 | EXACT |
| 0x0208F84C | WM_StartConnectEx (wm_standard.o) | 236 | EXACT |
| 0x0208F938 | WM_Disconnect (wm_standard.o) | 240 | EXACT |
| 0x0208FBA8 | WM_StartMPEx (wm_mp.o) | 164 | EXACT |
| 0x0208FC4C | WM_StartMP (wm_mp.o) | 104 | EXACT |
| 0x0208FDEC | WM_EndMP (wm_mp.o) | 120 | EXACT |
| 0x0208FE64 | WM_StartDCF (wm_dcf.o) | 168 | EXACT |
| 0x0208FF0C | WM_SetDCFData (wm_dcf.o) | 208 | EXACT |
| 0x0208FFDC | WM_EndDCF (wm_dcf.o) | 112 | EXACT |
| 0x02090BC4 | WM_SetWEPKey (wm_etc.o) | 124 | EXACT |
| 0x02090C40 | WM_SetWEPKeyEx (wm_etc.o) | 148 | EXACT |
| 0x02090CD4 | WM_SetGameInfo (wm_etc.o) | 196 | EXACT |
| 0x02090D98 | WM_SetBeaconIndication (wm_etc.o) | 84 | EXACT |
| 0x02090DEC | WM_SetLifeTime (wm_etc.o) | 100 | EXACT |
| 0x02090E50 | WM_MeasureChannel (wm_etc.o) | 124 | EXACT |
| 0x | no  | 0x |  |

Total: 40 functions, 5,364 bytes. EXACT* on 0x0208F1B4 and 0x0208F5C8 (a relocation resolved
through a catalog-attested address rather than a matched label: RTC_GetTime and WMi_CheckEnableFlag).

## Pending (src/pending/arm9_sdk/, no shard)

| address | symbol (object) | bytes | verdict | residue |
| --- | --- | --- | --- | --- |
| 0x0208E038 | WmInitCore (wm_system.o, static) | 640 | DIFF | Both counted loops (16 port slots, 10 fifo buffers) are entered in the object with an unconditional `b` to a bottom test; under -O4,p every spelling tried (for, while, goto, outer/inner `i`, enum counter) rotates them and folds the first test. Under -O2,p the whole body matches except an r5/r6 swap (e and bufSize), but WMi_CheckStateEx and WmReceiveFifo in the same object only match at -O4,p, so -O2 is not the object's flag. Next pass: permuter (seeds 12501+) on the loop spelling, or a per-function optimisation pragma test. |
| 0x02061C30 | dacktimer_alarmhandler (libcps.a network.o, static) | 20 | DIFF | network.o is stamped Metrowerks 3.0.0.139 (prebuilt TwlWiFi_base); no tools/mwccarm build writes it. Every available build (1.1p1..1.6sp2, -proc arm7tdmi, -O1..-O4) loads r0 before the tail-call target ip; the object loads ip first, so the two ldr and two pool words are swapped. Compiler blocker, C is one line. |

## Not attempted

- 0x020902D8 WM_StepDataSharing (wm_ds.o, 816 bytes): stopped at the context budget.

## Files written

- src/matched/arm9_sdk/func_<ADDR>.c and layout/matched/arm9/pkt_<ADDR>.json for each of the 40 addresses in the Filed table.
- src/pending/arm9_sdk/func_0208E038.c, src/pending/arm9_sdk/func_02061C30.c.
- this report. Scratch (generator, specs) in scratchpad/sdk9_wm/.

## Catalog / DWARF name disagreements

- 0x0208EAA0: catalog NWMi_CheckEnableFlag (nwm_init.o); libwm objects relocate against it as WMi_CheckEnableFlag (no DWARF declaration).
- 0x0208890C: catalog RTC_GetDate; wm_sync.o (WM_GetNextTgid) relocates against it as RTC_GetTime. Worth checking by the RTC lane.
- 0x0208E4BC is labelled func_0208E4BC in the catalog, symbol WMi_GetSystemWork.
- 0x02061B5C (OS_WakeupThreadDirect) is labelled func_02061B5C.

## Notes for the integrator

- mwcc DWARF drops `const`: WM_StartScanEx (0x0208F698) only matches with `const WMScanExParam *param` (the idiom const-on-a-read-only-source-parameter); DWARF prints the parameter unqualified. const is also used on other read-only pointer parameters (no effect on those bytes).
- Statics used through their image addresses: g_020A872C (WM_GetNextTgid's local static tgid_bak), g_02153B00 (wm_etc.o tmpUserGameInfoBuf), g_02153058 (wm_system.o .bss, same model as WM_Init.c).
- WmCheckParentParameter (0x0208F578) is static in the object; filed as a plain function.
- No asm bodies.
- `manifest --check` currently reports duplicate entries in ov104/ov110 shards from another lane; none involve this lane's shards.

## Next pass

WM_StepDataSharing (0x020902D8), then WmInitCore's loop shape. dacktimer_alarmhandler waits on a 3.0.0.139 compiler build.
