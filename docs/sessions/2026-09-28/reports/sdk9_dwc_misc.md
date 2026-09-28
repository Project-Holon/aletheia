# sdk9_dwc_misc report, 2026-09-28

Lane territory: libncfg, libdwcbm, libdwccommon, libdwcauth, libdwcmatch, libdwcutil
(ARM and Thumb), libdwcgscommon (arm9 open SDK rows). No `.c`/`.h` under `sdk/` was opened;
all work is from `tools/sdkobj.py`, `match.py show` and the idiom index.

Totals: 42 functions filed EXACT/EXACT* (5,832 bytes), 5 left in pending as DIFF,
2 catalog rows rejected as false positives. Every filed function sits in its own packet
`pkt_<ADDR>`, except NCFG_WriteBackupMemory, whose packet `pkt_0205F7C8` already held three
check.o entries (func_02060368, func_02060394, func_0206043C). All shards were re-verified
twice; the second pass rewrote 0.

## Filed (src/matched/arm9_sdk/func_<ADDR>.c, shard layout/matched/arm9/pkt_<ADDR>.json)

| address | sdk symbol (object) | bytes | verdict |
|---|---|---|---|
| 0x0200B424 | DWCi_HEAPlEnd (libdwcutil thumb, heap.o), Thumb | 20 | EXACT* |
| 0x02050790 | DWCi_LSTlPopFront (libdwcutil, list.o) | 16 | EXACT |
| 0x0208B788 | DWC_Netcheck_SetAllow302 (libdwcauth, dwc_netcheck.o) | 16 | EXACT |
| 0x0208F644 | DWC_IsSendableReliable (libdwcmatch, dwc_transport.o) | 16 | EXACT |
| 0x0205A17C | DWC_AllocEx (libdwccommon, dwc_memfunc.o) | 52 | EXACT |
| 0x02059F6C | DWC_InitForProduction (dwc_init.o) | 60 | EXACT |
| 0x02059E38 | DWC_GetLastErrorEx (dwc_error.o) | 224 | EXACT |
| 0x02059B40 | DWC_Base64Encode (dwc_base64.o) | 380 | EXACT |
| 0x0205F648 | NCFGi_InitBackupMemory (libncfg, backup.o) | 184 | EXACT |
| 0x0205F72C | NCFG_ReadBackupMemory (backup.o) | 156 | EXACT |
| 0x0205F7C8 | NCFG_WriteBackupMemory (backup.o), packet pkt_0205F7C8 | 216 | EXACT |
| 0x0205F8A0 | getSlotInfo (backup.o) | 208 | EXACT |
| 0x0205F970 | ReadNVRAM (backup.o) | 104 | EXACT |
| 0x0205F9D8 | WriteNVRAM (backup.o; catalog says ReadNVRAM) | 104 | EXACT |
| 0x0205FA40 | VerifyNVRAM (backup.o; catalog says ReadNVRAM) | 104 | EXACT |
| 0x0205FAC0 | NCFG_CheckConfig (info.o) | 92 | EXACT |
| 0x0205FB1C | NCFG_CheckConfigEx (info.o) | 112 | EXACT |
| 0x0205FB8C | checkConfig (info.o) | 544 | EXACT |
| 0x0205FDAC | checkConfigEx (info.o) | 448 | EXACT |
| 0x0205FF6C | initPage (info.o) | 44 | EXACT |
| 0x0205FF98 | initPageEx (info.o) | 44 | EXACT |
| 0x0205FFC4 | readAllSlots (info.o) | 124 | EXACT |
| 0x02060040 | readAllExSlots (info.o) | 84 | EXACT |
| 0x02060094 | writeAllSlots (info.o) | 172 | EXACT |
| 0x02060140 | writeAllExSlots (info.o) | 148 | EXACT |
| 0x020601D4 | NCFGi_CheckApInfo (check.o) | 80 | EXACT |
| 0x02060224 | NCFGi_CheckApInfoEx (check.o) | 120 | EXACT |
| 0x0206029C | NCFGi_CheckIpInfo (check.o) | 204 | EXACT |
| 0x020603BC | NCFGi_CheckIp (check.o) | 128 | EXACT |
| 0x020585DC | ReadSlotInfo (libdwcbm, dwc_backup.o) | 88 | EXACT |
| 0x02058664 | ReadSlotInfoEx (dwc_backup.o) | 88 | EXACT |
| 0x02058518 | DWCi_BM_GetWiFiInfo (dwc_backup.o) | 196 | EXACT |
| 0x020586BC | DWCi_BM_SetWiFiInfo (dwc_backup.o) | 180 | EXACT |
| 0x02058784 | DWCi_BACKUPlWritePage (dwc_backup.o) | 92 | EXACT |
| 0x020587F8 | DWCi_BACKUPlConvMaskCidr (dwc_backup.o) | 68 | EXACT* |
| 0x02058868 | DWC_BACKUPlCheckIp (dwc_backup.o) | 104 | EXACT |
| 0x020589D0 | DWC_BM_Init (dwc_bm_init.o) | 108 | EXACT |
| 0x02058A3C | DWCi_Util_WiFiId_scrambleUid (util_wifiidtool.o) | 388 | EXACT |
| 0x02058D88 | DWCi_AUTH_MakeWiFiID (util_wifiidtool.o) | 72 | EXACT |
| 0x02058DD0 | DWCi_AUTH_UpDateWiFiID (util_wifiidtool.o) | 80 | EXACT |
| 0x02058FB4 | DWC_Auth_GetId (util_wifiidtool.o) | 84 | EXACT |
| 0x02059008 | DWC_Auth_CheckWiFiIDNeedCreate (util_wifiidtool.o) | 80 | EXACT |

No asm bodies: every file is C.

## Files and shards written

- `src/matched/arm9_sdk/func_<ADDR>.c` for the 42 addresses above.
- `layout/matched/arm9/pkt_<ADDR>.json` for the same addresses (41 new shards), plus one entry
  added to the existing `layout/matched/arm9/pkt_0205F7C8.json`.
- Pending: `src/pending/arm9_sdk/func_02059FA8.c`, `func_02058904.c`, `func_02059CBC.c`,
  `func_02058E20.c`, `func_02058BC0.c` (all new, status DIFF, with a notes line).
- Removed: `src/pending/arm9_sdk/func_0205FF6C.c`, `func_0205FF98.c`, `func_0205FFC4.c`,
  `func_02060040.c`. Earlier pending drafts existed at these addresses. I did not read them.
  I wrote my own versions from the object, filed them as matched, and deleted the old
  pending copies so each address has only one source.

## Near misses (pending, DIFF)

- 0x02059FA8 DWCi_Init (dwc_init.o, 356 bytes): 15 bytes off. Everything matches except the
  two inlined host-name copies ("sdkdev.gamespy.com" / "gamestats.gs.nintendowifi.net" into
  StatsServerHostname). In those copies the object has dst in r4 and src in r3, and the
  literal pool follows that order; this draft has them the other way round. I tried strcpy,
  memcpy, struct assignment, a union destination, a temporary and an explicit loop, and
  none changed the order. Separately, StatsServerHostname (0x021A5850) has no witness
  outside this function, so that literal stays wildcarded however the C is written.
- 0x02059CBC DWC_Base64Decode (348): 13 bytes off. The count of non-'*' characters is in ip
  and i is in r5. The object has the count in r5, i in r6 and the /8 result in ip. The rest
  of the function is exact.
- 0x02058904 DWCi_BACKUPlConvWifiInfo (dwc_backup.o, 204): 99 bytes off. The object loads
  `notAttestedId` into `tmp` with two plain `ldr`; this draft gets `ldm`/`stm` plus one
  more callee-saved register. The statics use the laid-out struct (Address, then Wifi),
  which does match the object's writes through Address+9/+0xe/+0xf.
- 0x02058E20 DWCi_AUTH_RemakeWiFiID (404) and 0x02058BC0 DWCi_AUTH_GetNewWiFiInfo (456):
  in both, the object keeps the LCG state (x*0x5D588B65+0x269EC3) in a u32 register that is
  separate from the s64 `seed`. DWARF lists no such variable, so it probably comes from an
  inlined helper or a block-scope local. This draft routes the state through `seed` or a
  block local, which leaves register and scheduling residue. Both functions add
  OS_GetTick's *address* to the seed, not a call result, which is a real quirk of the object.

The permuter (seeds 12301 to 12304) made no progress on any of these. Its output for
0x02058E20 did not compile.

## Catalog and DWARF disagreements

- `setsockopt` rows at 0x02091390 and 0x020913A8 (libdwcgscommon, gsplatformsocket) are
  false positives. The real functions start 4 bytes earlier, at 0x0209138C and 0x020913A4
  (`mov r2, r0` first). Both are already matched game-side as `src/matched/arm9/func_0209138C.c`
  and `func_020913A4.c` (tail calls into 0x020868E0 and 0x020869E8). The 16-byte suffix only
  looks like setsockopt's `mov r0,#0; sub r1,r0,#1; bx ip`. These rows should be dropped
  from the open list.
- 0x0205F9D8 and 0x0205FA40 are catalogued as ReadNVRAM. NCFG_WriteBackupMemory's PC24
  relocations name them WriteNVRAM and VerifyNVRAM. Their callees (0x02083DC8, 0x020840F8,
  catalogued as NVRAMi_Read) are therefore probably NVRAMi_Write and NVRAMi_Verify. I named
  them `func_02083DC8` and `func_020840F8`.
- The DWARF declaration for DWC_Netcheck_SetAllow302 gives `DWCHttp *DWChttp`, but the code
  stores at &DWChttp+0x10 with no dereference, so it is filed as an object.
- DWARF declarations drop an argument: DWC_Free, WriteSlotInfo (both take a third argument
  in the code) and NCFGi_CheckApInfoEx's call site in checkConfigEx (two arguments).
- OSi_ReferSymbol in DWC_InitForProduction resolves to 0x02004EB0 (`func_02004EB0`, shown as
  game/unknown).
- The `.comment` stamp on these DWC objects is 4.0.0.1025, and no local mwccarm build
  writes it. Everything was built with dsi/1.1p1 as the brief says.

## Shape notes for the integrator

- NCFG types (`NCFGApInfo`, `NCFGApInfoEx`, `NCFGSlotInfo`, `NCFGSlotInfoEx`,
  `NCFGConfig(Ex)`) are the same text in every libncfg/libdwcbm file. `NCFGSlotInfoEx` is
  ap + wifi + crc, then apEx (NCFGApInfoEx) + rsv + crcEx. The layout was confirmed by
  checkConfigEx and writeAllExSlots.
- Three files use the "statics in their laid-out order" extern struct:
  NCFGi_InitBackupMemory (FormatVersionNumber, nvramBuf, nvramBuf2), DWCi_BM_SetWiFiInfo
  and ConvWifiInfo (Address, Wifi). The object reaches later statics off the first one's
  literal, a section-relative `.bss` reference that the `symbols:` grammar cannot name.

## Next pass

Only the 5 pending near misses remain in this territory; nothing open is left untried.
The best leads are DWC_Base64Decode (13 bytes, register assignment only) and DWCi_Init
(src/dst order in two inlined copies).
