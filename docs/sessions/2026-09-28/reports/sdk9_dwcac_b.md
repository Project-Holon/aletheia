# sdk9_dwcac_b: libdwcac dwc_connectinet.o, beacon.o, connect.o, makelist.o (arm9)

Territory: 37 open arm9 SDK rows, 7,736 bytes. Result: 36 EXACT (7,244 bytes), 1 DIFF in pending.
No file under sdk/ was opened. I wrote every draft from the object (sdkobj, match.py show). No
existing pending file sat at any of these addresses.

All four objects carry the `.comment` stamp 4.0.0.1025, which no tools/mwccarm build writes.
Every function matches with `--cc 1.1p1 -O4,p`, lang c99, ARM.

## Verdicts

Each header `status:` is copied from `manifest --verify`. Every shard was run a second time and
rewrote 0.

| address | symbol (object) | bytes | verdict |
|---|---|---|---|
| 0x0205A938 | DWCi_AC_GetBeacon (beacon.o) | 376 | EXACT |
| 0x0205AAB0 | DWCi_AC_CheckNintendoSSID (beacon.o) | 164 | EXACT |
| 0x0205AB54 | DWCi_AC_IsSupportWPA (beacon.o) | 128 | EXACT |
| 0x0205ABD4 | CompareList (beacon.o) | 124 | EXACT |
| 0x0205AC50 | CompareListDiff (beacon.o) | 148 | EXACT |
| 0x0205ACE4 | AddList (beacon.o) | 392 | EXACT |
| 0x0205AE6C | SetDataListTail (beacon.o) | 104 | EXACT |
| 0x0205AED4 | UpDateList (beacon.o) | 136 | EXACT |
| 0x0205AF5C | SortList (beacon.o) | 492 | DIFF, 151 bytes (pending) |
| 0x0205B33C | DWCi_AC_ConnectAP (connect.o) | 64 | EXACT |
| 0x0205B37C | ConnectStart (connect.o) | 268 | EXACT |
| 0x0205B488 | ConnectAP (connect.o) | 356 | EXACT |
| 0x0205B5EC | GetConnectType (connect.o) | 420 | EXACT |
| 0x0205B7D0 | GetWepKey (connect.o) | 444 | EXACT |
| 0x0205C6AC | DWC_InitInetEx (dwc_connectinet.o) | 100 | EXACT |
| 0x0205C710 | DWC_SetRwinSize | 72 | EXACT |
| 0x0205C758 | DWC_ConnectInetAsync | 196 | EXACT |
| 0x0205C81C | DWC_DebugConnectInetExAsync | 112 | EXACT |
| 0x0205C88C | DWC_CheckInet | 84 | EXACT |
| 0x0205C8E0 | DWC_ProcessInet | 320 | EXACT |
| 0x0205CA20 | DWC_GetInetStatus | 512 | EXACT |
| 0x0205CC20 | DWC_CleanupInet | 140 | EXACT |
| 0x0205CCAC | DWCi_CheckDisconnected | 44 | EXACT* |
| 0x0205CCE4 | DWCi_DivideFullApinfo | 64 | EXACT |
| 0x0205CD24 | DWC_GetApInfo | 352 | EXACT |
| 0x0205CE84 | DWC_CheckWiFiStation | 160 | EXACT* |
| 0x0205CF30 | DWC_CheckNintendoZone | 224 | EXACT |
| 0x0205D01C | DWC_ParseWMBssDesc | 88 | EXACT |
| 0x0205D074 | DWC_UpdateConnection | 112 | EXACT |
| 0x0205D318 | DWCi_AC_MakeSearchList (makelist.o) | 200 | EXACT |
| 0x0205D3E0 | DWCi_AC_CheckFreespot (makelist.o) | 84 | EXACT |
| 0x0205D434 | DWCi_AC_GetSearchListNum (makelist.o) | 60 | EXACT |
| 0x0205D470 | MakeAroundList (makelist.o) | 104 | EXACT |
| 0x0205D4D8 | MakeStealthList (makelist.o) | 176 | EXACT |
| 0x0205D588 | MakeUserList (makelist.o) | 704 | EXACT |
| 0x0205D848 | MakeDifferChannelList (makelist.o) | 140 | EXACT |
| 0x0205D8D4 | CheckDifferChannelStart (makelist.o) | 72 | EXACT |

## Files written

- 36 files: `src/matched/arm9_sdk/func_<ADDR>.c` for every EXACT/EXACT* address above.
- 36 shards: `layout/matched/arm9/pkt_<ADDR>.json`, one for each of the same addresses.
- 1 file: `src/pending/arm9_sdk/func_0205AF5C.c` (DIFF, no shard).
- Scratch: `scratchpad/sdk9_dwcac_b/` (gitignored).

No asm bodies.

## Near miss

- SortList 0x0205AF5C, DIFF 151 bytes. Size and registers match. The residue is branch layout:
  the object reaches one shared `swap = 1` block from four sites, while this source gets
  conditional moves (movhs/movls) and a slightly different block order. Several if/else and `||`
  shapes were tried. Permuter seed 12102 (600 iterations) found no gain. Next step: restructure
  around a single shared assignment (for example a `goto` to one `swap = 1` label, or an
  else-chain whose leaves are all `swap = 1`).

## Findings for the idiom index and the next lanes

- **strncmp is pure in these objects.** The object keeps loads of `*bssdesc` and `wk` fields
  live across `strncmp` (CompareList, CompareListDiff, AddList). Declaring
  `extern int strncmp(...) __attribute__((pure));` reproduces this; mwcc 1.1p1 accepts it. With
  a plain prototype the loads are redone after each call. This is worth an idiom entry. Other
  libdwcac lanes should expect the same wherever a loop calls strncmp.
- **Static .bss pairs addressed off the section base.** dwc_connectinet.o's statics `stateOld`
  and `stpInetCntl` are reached through one literal at 0x02146AD4 plus an offset (+0, +4). I
  spelled this as one `extern INETBSS g_02146AD4` struct holding both.
- **Local declaration order.** DWARF lists locals in reverse declaration order. Following that
  fixed register allocation in GetConnectType, MakeUserList, MakeStealthList and
  CheckDifferChannelStart.
- **Local-array initialiser.** DWCi_AC_IsSupportWPA initialises the local `wpaTag` from an
  anonymous constant (@16091 = 00 50 F2 01, at 0x020A161C), copied byte by byte. I spelled it
  as a struct copy from `extern const WPATAG g_020A161C` inside the branch. MakeStealthList's
  anonymous SSID literal @16449 is `g_020A80A4`.
- **GetWepKey** needs fallthrough pointer steps (`case 2: info++; case 1: info++; case 0:`),
  plus an explicit empty `case 20`, to get the object's jump table and cascaded adds.
- **AddList** compares BSSIDs through an inline taking `const void *`, cast to bytes inside.
  With `const u8 *` parameters the flag chain matches but the addressing does not.
- **UpDateList / SetDataListTail** need the RSSI in an `unsigned short` temporary. That
  temporary is not in the DWARF (likely a macro in the original).

## Catalog and DWARF disagreements

- DWC_InitInetEx: DWARF gives three parameters, but ssl_priority is read from r3, and
  DWC_GetInetStatus passes 1 in r2. The real prototype has a 4th, unused parameter in slot 3
  (probably powerMode). I declared it as `unsigned short unused`.
- `sdkobj` names the .bss relocation base `_ZZ17DWC_GetInetStatusvE8stateOld` for every
  access. The +4 word is actually `stpInetCntl`.
- tagACWORK bitfield widths are not in the `--types` dump. I inferred them from code:
  - byte 0x14BB: powerMode:2, authMode:2, aroundCount:4
  - byte 0x14BC: connectType:4, skipNetCheck:1, useDSWireless:1, duplicateFlag:1, wpaSetting:1
  - tagACSL byte 0: find:4, duplicate:4
  - tagACFL byte 3: channel:7, find:1

## Next pass

Only SortList (0x0205AF5C) is left in this territory.
