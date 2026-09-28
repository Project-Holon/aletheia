# sdk9_dwcac_a report

Lane: ARM9 SDK, libdwcac.TWL.HYB.a objects search.o, dwc_ac.o, nintendospot.o,
error.o, retry.o, start.o. All 43 open rows in the territory are matched: 43 EXACT,
7,700 bytes. `sdkobj.py --open --region arm9` lists no libdwcac rows for these six
objects now.

Every file was written from the vendor object only (the DWARF prototype, locals and
relocations from `sdkobj.py`, and the listing from `match.py show`). No `.c` or `.h`
under `sdk/` was opened. Compiler 1.1p1, flags `-O4,p`, lang c99, ARM. The objects are
stamped 4.0.0.1025, and 1.1p1 reproduces all of them. There are no asm bodies.

## Verdicts

Each status was copied from `manifest --verify`. Each shard was verified again at the
end, and every one rewrote 0.

| address | symbol | object | bytes | verdict |
|---|---|---|---|---|
| 0x0205B98C | DWC_AC_Create | dwc_ac.o | 748 | EXACT |
| 0x0205BC78 | DWC_AC_Process | dwc_ac.o | 236 | EXACT |
| 0x0205BD64 | DWC_AC_GetStatus | dwc_ac.o | 108 | EXACT |
| 0x0205BDD0 | DWC_AC_GetApType | dwc_ac.o | 48 | EXACT |
| 0x0205BE00 | DWC_AC_GetApSpotInfo | dwc_ac.o | 88 | EXACT |
| 0x0205BE6C | DWC_AC_Destroy | dwc_ac.o | 60 | EXACT |
| 0x0205BEA8 | DWC_AC_SetSpecifyApEx | dwc_ac.o | 116 | EXACT |
| 0x0205BF1C | DWC_AC_SetSpecifyAp | dwc_ac.o | 184 | EXACT |
| 0x0205C038 | DWCi_AC_Alloc | dwc_ac.o | 72 | EXACT |
| 0x0205C080 | DWCi_AC_Free | dwc_ac.o | 108 | EXACT |
| 0x0205C0EC | DWCi_AC_FreeAll | dwc_ac.o | 296 | EXACT |
| 0x0205C214 | DWCi_AC_GetMemPtr | dwc_ac.o | 72 | EXACT |
| 0x0205C25C | DWCi_AC_SetPhase | dwc_ac.o | 104 | EXACT |
| 0x0205C31C | DWCi_AC_SetApType | dwc_ac.o | 148 | EXACT |
| 0x0205C3B0 | DWCi_AC_CopyExSetting | dwc_ac.o | 280 | EXACT |
| 0x0205C4C8 | DWCi_ConvConnectAPType | dwc_ac.o | 96 | EXACT |
| 0x0205C528 | Free_Disused | dwc_ac.o | 52 | EXACT |
| 0x0205C55C | CheckDuplicate | dwc_ac.o | 164 | EXACT |
| 0x0205C600 | CheckEULA | dwc_ac.o | 112 | EXACT |
| 0x0205C670 | CheckWirelessPowerON | dwc_ac.o | 60 | EXACT |
| 0x0205D108 | DWCi_AC_GetResult | error.o | 112 | EXACT |
| 0x0205D1E4 | GetNotFoundInet | error.o | 308 | EXACT |
| 0x0205D91C | DWC_AC_StartupGetWDSInfo | nintendospot.o | 112 | EXACT |
| 0x0205D98C | DWC_AC_ProcessGetWDSInfo | nintendospot.o | 716 | EXACT |
| 0x0205DCC8 | WDS_Initialize_CB | nintendospot.o | 20 | EXACT |
| 0x0205DCDC | WDS_StartScan_CB | nintendospot.o | 20 | EXACT |
| 0x0205DCF0 | WDS_EndScan_CB | nintendospot.o | 20 | EXACT |
| 0x0205DD04 | WDS_End_CB | nintendospot.o | 20 | EXACT |
| 0x0205DD18 | WDS_Error_End_CB | nintendospot.o | 20 | EXACT |
| 0x0205DD2C | DWCi_AC_ConnectRetryAP | retry.o | 216 | EXACT |
| 0x0205DE04 | DWCi_AC_SearchAP | search.o | 360 | EXACT |
| 0x0205DFA8 | DWCi_AC_SearchReStart | search.o | 360 | EXACT |
| 0x0205E110 | SearchAround1stLap | search.o | 108 | EXACT |
| 0x0205E1D0 | SearchAround | search.o | 204 | EXACT |
| 0x0205E29C | SearchDifferChannel | search.o | 424 | EXACT |
| 0x0205E444 | SearchStealth | search.o | 332 | EXACT |
| 0x0205E590 | NextSearchCheck | search.o | 188 | EXACT |
| 0x0205E64C | SearchEndCheck | search.o | 324 | EXACT |
| 0x0205E790 | CheckStartStealthSearch | search.o | 136 | EXACT |
| 0x0205E818 | GetStartChannel | search.o | 164 | EXACT |
| 0x0205E8BC | GetNextAroundChannel | search.o | 152 | EXACT |
| 0x0205E954 | GetNextStealthChannel | search.o | 180 | EXACT |
| 0x0205EFF0 | DWCi_AC_Start | start.o | 140 | EXACT |

## Files and shards written

- Sources: `src/matched/arm9_sdk/func_<ADDR>.c` for the 43 addresses above.
- Shards: `layout/matched/arm9/pkt_<ADDR>.json`, one per address above (43 new shards).
- Deleted: `src/pending/arm9_sdk/func_0205BD64.c`, `func_0205BDD0.c` and
  `func_0205BE00.c`. These were earlier pending drafts at three of my addresses. I did
  not open them. They are replaced by my own matched files written from the object.
- Scratch: `scratchpad/sdk9_dwcac_a/` (bodies, shared type prelude, build and filing scripts).

## Notes on types and data

- dwc_ac.o statics: a single block at 0x02146AC0. It is modelled as `static struct
  s_ac_work { wcmBuffer; socConfig; netCheck; acHold; acWork; }`, and the offsets map to
  the `DWCi_AC_GetMemPtr` name bits 2, 4, 8, 1 and 0x10. I used the symbol name
  `s_ac_work` because the already-matched `DWCi_AC_GetPhase` file uses it. The order of
  socConfig and netCheck at +4 and +8 is inferred from the sizes each is allocated with
  (SOCConfig is 0x58 bytes, netCheck is 0xc bytes).
- nintendospot.o statics: a block at 0x02146ADC. It is modelled as `static struct s_nspot
  { gDwcWdsWork; wdsSysBuf; gAppstate; }`. The existing matched
  `DWC_AC_CleanupGetWDSInfo` file names the same address `gDwcWdsWork` with generic
  fields. The integrator may want to normalise the two.
- Bitfields recovered from code (mwcc allocates them LSB first):
  - ACWORK+0x14bb: powerMode:2, authMode:2, aroundCount:4.
  - ACWORK+0x14bc: connectType:4, skipNetCheck:1, useDSWireless:1, duplicateFlag:1,
    wpaSetting:1.
  - ACHOLD+0xb: findAP:4, ipCollision:4.
  - NCFGSlotInfo(Ex)+0xe6: wepMode:2.
  - tagACFL byte 3, bit 7: `searched`.
  - tagACSL byte 0: state:4.
- `tagDWCACOption` (config+0xa) is modelled as a u8 connectType followed by two 4-bit
  fields. The layout is inferred from the extract/insert code, not taken from DWARF.
- Some field names that DWARF does not give are placeholders: ACFL b0/b1/b2,
  NCFGSlotInfoEx f000/f020, and the WDSApInfo pad fields.
- There are faithful oddities in the vendor code:
  - `DWC_AC_Create`: the connectType 0xd branch tests `userInfoEx[2].wpaMode >= 0x10`
    and then `userInfoEx[1].wpaMode != 0xff`.
  - `SearchDifferChannel` and `SearchReStart`: the WCM_SearchAsync option is truncated
    to u16, which drops the 0x300000 flag.
  - `DWCi_AC_CopyExSetting`: the range tests only match when spelled `(u8)(x + 0xf0) <= 3`
    and `(u8)(type + 0xee) <= 1`.
- Locals where DWARF and my C differ: FreeAll's block locals `wk` are typed `void *`
  where DWARF has SOCConfig * and DWCNetcheckParam *, with identical bytes. Create needs
  an `hd` local that DWARF does not list. CheckDuplicate caches `connectNo`, `num` and
  `wk` in locals, while DWARF lists only `i` and `ssid1`. GetNextAroundChannel needs a
  separate u16 mask plus a u16 `ch` holding the WCM_GetAllowedChannel result (found with
  permuter seed 12001).

## Catalog and DWARF name disagreements

None. Every catalog name matched the DWARF subprogram name.

## Near misses

None. There is nothing left pending.

## Next pass

Nothing remains in this territory. The only other libdwcac-adjacent open row I saw is
`DWC_GetLastErrorEx` (0x02059E38, 224 bytes). It is in libdwccommon dwc_error.o, outside
this lane, so I left it alone.
