# rederive_a report, 2026-09-28

Lane rederive_a rewrote 32 ARM9 SDK files from the vendor objects only (tools/sdkobj.py, match.py show, the idiom index). All 32 reached EXACT or EXACT* and replaced the repo file with a plain copy of the new draft. Every file uses compiler dsi/1.1p1, flags -O4,p, lang c99, ARM.

For every address below: no existing version was read. The old file, its git history and the other side-session files in rederive_list.txt were never opened, grepped or diffed; only the path was used. No .c or .h under sdk/ was read, and no SDK header is #included (the drafts were checked with --no-sdk-include).

| address | sdk symbol | re-derived | verdict (manifest --verify) | packet |
|---|---|---|---|---|
| 0x02059214 | DWCi_SetBuddyFriendData | yes | EXACT | pkt_02059214 |
| 0x0205BFEC | DWCi_AC_InsertApInfo | yes | EXACT | pkt_0205BFEC |
| 0x0205C018 | DWCi_AC_InvalidatePriorityWPA | yes | EXACT | pkt_0205C018 |
| 0x0205C2E4 | DWCi_AC_SetError | yes | EXACT | pkt_0205C2E4 |
| 0x0205D0E4 | DWCi_AC_Error | yes | EXACT | pkt_0205D0E4 |
| 0x0205DC74 | DWC_AC_CleanupGetWDSInfo | yes | EXACT* | pkt_0205DC74 |
| 0x0205DF6C | DWCi_AC_SetStealthChannel | yes | EXACT | pkt_0205DC74 |
| 0x0205E17C | SearchAround2ndLap | yes | EXACT | pkt_0205DC74 |
| 0x0205EA08 | DWCi_AC_CheckNintendoShopAP | yes | EXACT | pkt_0205DC74 |
| 0x0205EA44 | DWCi_AC_GetNintendoShopWepKey | yes | EXACT | pkt_0205DC74 |
| 0x0205EAFC | DWCi_AC_CheckNintendoUsbAP | yes | EXACT* | pkt_0205DC74 |
| 0x0205EC2C | makeShopWepKey | yes | EXACT | pkt_0205DC74 |
| 0x0205F298 | ConnectTestCreate | yes | EXACT | pkt_0205DC74 |
| 0x0205F35C | ConnectTestEnd | yes | EXACT | pkt_0205DC74 |
| 0x0205F384 | ConnectTestRetry | yes | EXACT | pkt_0205DC74 |
| 0x0205F558 | ConvNetMask | yes | EXACT | pkt_0205DC74 |
| 0x0205F700 | NCFG_GetFormatVersion | yes | EXACT | pkt_0205DC74 |
| 0x02060368 | NCFGi_ConvMaskAddr | yes | EXACT | pkt_0205F7C8 |
| 0x02060394 | NCFGi_CheckSsid | yes | EXACT | pkt_0205F7C8 |
| 0x0206043C | NCFGi_CheckAddress | yes | EXACT | pkt_0205F7C8 |
| 0x02078360 | FS_InitArchive | yes | EXACT | pkt_02078360 |
| 0x02078B44 | FS_SeekFile | yes | EXACT | pkt_02078B44 |
| 0x02078D08 | FS_GetOverlayFileID | yes | EXACT | pkt_02078D08 |
| 0x0207A980 | FSi_IsUnreadableRomOffset | yes | EXACT | pkt_0207A980 |
| 0x0207A9C8 | FSi_OnRomReadDone | yes | EXACT | pkt_0207A9C8 |
| 0x0207A9EC | FSi_ReadRomCallback | yes | EXACT | pkt_0207A9EC |
| 0x0207AD04 | FS_Init | yes | EXACT* | pkt_0207AD04 |
| 0x0207BDB4 | MTX_Identity44_ | yes | EXACT | pkt_0207BDB4 |
| 0x0207BDE0 | MTX_Copy44To43_ | yes | EXACT | pkt_0207BDE0 |
| 0x0207D3AC | GX_HBlankIntr | yes | EXACT | pkt_0207D3AC |
| 0x0207D3E4 | GX_VBlankIntr | yes | EXACT | pkt_0207D3E4 |
| 0x0207D42C | GX_DispOff | yes | EXACT | pkt_0207D42C |

## Files and shards

- Files: src/matched/arm9_sdk/func_XXXXXXXX.c for the 32 addresses above.
- Shards verified (each kept its existing packet): arm9/pkt_02059214, pkt_0205BFEC, pkt_0205C018, pkt_0205C2E4, pkt_0205D0E4, pkt_0205DC74, pkt_0205F7C8, pkt_02078360, pkt_02078B44, pkt_02078D08, pkt_0207A980, pkt_0207A9C8, pkt_0207A9EC, pkt_0207AD04, pkt_0207BDB4, pkt_0207BDE0, pkt_0207D3AC, pkt_0207D3E4, pkt_0207D42C. A final `manifest --verify` pass over all 19 rewrote 0, and every header status and packet agrees with its shard. None of these shard files differs from HEAD.
- Header status lines were copied from the `manifest --verify` output.

## Notes

- asm bodies (2): MTX_Identity44_ (0x0207BDB4): `stmia r0!` runs over fixed registers; MTX_Copy44To43_ (0x0207BDE0): an `ldmia r0!/stmia r1!, {r2, r3, r12}` block copy. Each header carries an `asm:` line naming that instruction.
- String literals that are not unique in the image: the template attestation refused "NWCUSBAP" (0x0205EAFC, vendor @16393) and "rom" (0x0207A980, vendor @12296) because their bytes also occur elsewhere in the image. Each file declares the string as an address-named extern (g_020A8124, g_020A84B0) with a symbols: line and a comment naming the vendor @N. "NDWCSHAP" (0x0205EA08) attested as a template, so that file uses a literal.
- Section-relative .bss: 0x0205DC74 (nintendospot.o: gDwcWdsWork at +0, wdsSysBuf at +4), 0x02078D08 (fs_overlay.o: FS_StartOverlay's static `once` at +0, then FSiOverlayContext) and 0x0207AD04 (fs_api.o is_init) define in-file statics and give a `.bss 0xADDR data` symbols line. The two statics in 0x0205DC74 needed explicit `= NULL` initializers before MW would address them off one base. The `once` slot in 0x02078D08 is a file-scope placeholder, because the real variable is a function static inside FS_StartOverlay.
- Bitfield widths in tagACWORK at 0x14BB/0x14BC (powerMode/authMode 2 bits each, aroundCount 4; connectType 4, then four 1-bit flags) are guesses: they agree with the bit positions the code uses, but --types does not print widths.
- Struct field names outside the DWARF dump (FSOverlayInfoHeader fields other than file_id, CARDRomHeader +0x92 `twl_ltd_area_rom_offset`) are placeholders. Only the offsets are backed by the object.
- 0x0205DC74: the listing extent says 184 bytes but sdkobj gives 84. The shorter size matched.
- Incident, repaired: my install script first gave 0x0205DF6C the packet pkt_0205DF6C, and a forced verify created a stray layout/matched/arm9/pkt_0205DF6C.json. I deleted that file, put the header back on pkt_0205DC74 and re-verified. pkt_0205DC74 now matches HEAD.
- Worktree note: about 719 layout/ files, tools/match.py and some other src/matched/arm9_sdk files show as modified in git status. Those changes came from other activity, not from this lane.
- Nothing is left for a next pass from this list.
