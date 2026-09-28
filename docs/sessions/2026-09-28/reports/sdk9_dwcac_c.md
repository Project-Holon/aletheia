# sdk9_dwcac_c report

Territory: libdwcac wds.o, shop_usb.o, test.o and libdwcaccount dwc_account.o (arm9 open SDK rows).
Start: 46 open rows. Filed 44 matched (5,836 bytes), 2 left in pending as DIFF. No arm9 SDK row in
this territory is still open without a draft.

All files were written from the vendor objects through sdkobj.py and match.py only. No `.c` or `.h`
under `sdk/` was opened. Compiler: every object carries the stamp 4.0.0.1025; all 44 match under
dsi/1.1p1 -O4,p, lang c99. No asm bodies.

## Matched (file src/matched/arm9_sdk/func_ADDR.c, shard layout/matched/arm9/pkt_ADDR.json)

Status copied from `manifest --verify --shard arm9/pkt_ADDR`. Each shard was verified twice and the
second pass rewrote 0.

| address | symbol | object | bytes | status |
|---|---|---|---|---|
| 0x02059240 | DWCi_SetReverseBuddyFlag | | 48 | EXACT |
| 0x02059270 | DWCi_SetExpIsBuddyFriendFlag | | 48 | EXACT |
| 0x020592A0 | DWCi_SetSentBuddyReqFlag | | 48 | EXACT |
| 0x020592D0 | DWC_Acc_CreateFriendKey | | 132 | EXACT |
| 0x02059374 | DWC_Acc_CheckFriendKey | | 68 | EXACT |
| 0x020593B8 | DWC_Acc_FriendKeyToGsProfileId | | 80 | EXACT |
| 0x02059408 | DWCi_Acc_U64ToString32 | | 108 | EXACT |
| 0x02059474 | DWCi_Acc_LoginIdToUserName | | 148 | EXACT |
| 0x02059508 | DWCi_Acc_CreateUserData | | 128 | EXACT |
| 0x02059644 | DWCi_Acc_CheckConsoleUserId | | 108 | EXACT |
| 0x02059718 | DWC_CheckUserData | | 72 | EXACT |
| 0x02059760 | DWC_CheckValidConsole | | 104 | EXACT |
| 0x020597C8 | DWC_CheckHasProfile | | 40 | EXACT |
| 0x020597F0 | DWCi_Acc_SetLoginIdToUserData | | 92 | EXACT* |
| 0x0205987C | DWCi_Acc_ClearDirty | | 72 | EXACT |
| 0x020598C4 | DWC_GetFriendKey | | 40 | EXACT |
| 0x020598EC | DWC_GetGsProfileId | | 96 | EXACT |
| 0x0205994C | DWC_CreateFriendKey | | 52 | EXACT |
| 0x02059980 | DWC_CreateFriendKeyToken | | 60 | EXACT |
| 0x020599BC | DWC_CreateExchangeToken | | 84 | EXACT |
| 0x02059A10 | DWC_SetGsProfileId | | 52 | EXACT* |
| 0x02059A5C | DWC_IsEqualFriendData | | 228 | EXACT |
| 0x0205A2DC | WDSScanCallback | | 492 | EXACT |
| 0x0205A4D4 | WDS_Initialize | | 132 | EXACT |
| 0x0205A558 | WDS_End | | 64 | EXACT |
| 0x0205A598 | WDS_StartScan | | 184 | EXACT |
| 0x0205A650 | WDS_EndScan | | 56 | EXACT |
| 0x0205A688 | WDS_GetApInfoByIndex | | 156 | EXACT |
| 0x0205A724 | WDS_GetApInfoAll | | 168 | EXACT |
| 0x0205A7CC | WDS_DecryptWMBssDesc | | 252 | EXACT |
| 0x0205A8C8 | IsValidApnum | | 52 | EXACT |
| 0x0205A8FC | WDS_IsAvailableForAutoConnect | | 60 | EXACT |
| 0x0205EA70 | DWCi_AC_GetPostalCode | | 140 | EXACT |
| 0x0205EB20 | DWCi_AC_GetNintendoUSBWepKey | | 16 | EXACT |
| 0x0205EC7C | makeUsbWepKey | | 428 | EXACT |
| 0x0205EE28 | codetovalue | | 112 | EXACT |
| 0x0205EE98 | db64 | | 344 | EXACT |
| 0x0205F07C | DWCi_AC_ConnectTest | | 216 | EXACT |
| 0x0205F154 | ConnectTestStart | | 100 | EXACT |
| 0x0205F1B8 | GetIPAddress | | 224 | EXACT |
| 0x0205F2C4 | ConnectTestProcess | | 152 | EXACT |
| 0x0205F3B0 | MakeSOCConfig | | 340 | EXACT |
| 0x0205F504 | ConvAddress | | 84 | EXACT |
| 0x0205F5AC | CheckSetDNS | | 156 | EXACT |

Object column: 0x02059xxx rows are dwc_account.o, 0x0205A2DC to 0x0205A8FC are wds.o,
0x0205EA70 to 0x0205EE98 are shop_usb.o, 0x0205F07C to 0x0205F5AC are test.o.

The two EXACT* entries (0x02059A10, 0x020597F0) are EXACT* because of the listing extent, not the
code: in each case the image listing runs past the compiled size, or the target is labelled as a
game-unknown function (DWCi_Acc_SetGsProfileId at 0x02059100).

## Pending (src/pending/arm9_sdk/, no shard)

- 0x02059588 DWCi_Acc_CreateTempLoginId (188 bytes), DIFF with a 4-byte residue. Everything matches
  except one load in the `buffer[i] ^= buffer[i-1]` entropy-mixing loop: the image reads buffer[i]
  indexed (`ldr r1, [r4, r2, lsl #2]`) and we read it through the CSE'd `&buffer[i]` base
  (`ldr r1, [r0]`). The body uses a MATHRandContext32 with inline MATH_InitRand32/MATH_Rand32
  (these are what put buffer[7] into a u64 before DWC_Auth_GetId). Tried: (int)/(long) casts on
  either subscript, pointer spellings, operand order, and permuter seeds 12201 and 12203 (best
  still 4 bytes out).
- 0x0205EB30 decodeSSID (252 bytes), DIFF. The prologue, 24-byte table copy, db64 call and both
  mask-xor loops match (the xor loops need `buf[i] = buf[i] ^ key[i]` to get the ldrsb). The
  in-place cycle walk does not: the image keeps two registers for the same u8 index and reloads
  ctable_inv through each. Tried 512 brute-forced statement spellings (scratchpad brute.py and
  brute2.py) and permuter seed 12202; the best is still 33 lines off.

Both pending files are my own drafts. A pending file already existed at 0x02059240, 0x02059270,
0x020592A0, 0x020597C8, 0x020598C4 and 0x0205F504. I did not read any of them. Each was deleted
when my own matched file for that address was filed.

## Catalog and DWARF name disagreements

- 0x020596B0 is labelled DWC_GHTTPCleanupRootCAList in the catalog, but dwc_account.o's relocation
  names it DWCi_Acc_IsValidLoginId.
- 0x0208F370 is labelled FSi_HasEnoughSpaceToCreateUserFile, but wds.o's relocation names it
  WM_Initialize.
- 0x020590F0 is labelled unit_020590F0; DWARF calls it DWCi_Acc_SetPlayerId.
- wds.o has an Itanium-mangled local static,
  `_ZZ20WDS_DecryptWMBssDesc...E5magic` (at 0x020A1618, 4 bytes). The rest of the object matches
  as C99.
- shop_usb.o: MASKkey0/1 and SHMASKkey0/1 are four `char *` words at 0x020A80B0 that the object
  addresses from one base. The drafts use `extern char *g_020A80B0[4]`: decodeSSID uses [2]
  then [0], and makeUsbWepKey uses [1] then [3]. Which name belongs to which slot is not known.

## Idioms observed (no new idiom files written)

- codetovalue: `(long)(c - 'a') + 26` keeps the sub/add pair unfolded.
- WDS_End: `if (errcode == 2) errcode = 0; return errcode;` shares the zero register. Used for all
  the WDS wrappers so they have the same shape.
- db64: the destsize guard is `if (destsize >= x) { srcmod = ...; srcmax = ...; } else return -1;`,
  which gives the predicated hs assignments.
- ConvAddress: accumulating `address = 0; address |= ...` gives the image's `orr r3, r3, #0`.
- ConnectTestProcess: nesting the checks as if/else (success path first) gives the shared-tail
  returns.

## Next pass

Only the two pending near misses remain in this territory, 0x02059588 and 0x0205EB30.

Scratch: scratchpad/sdk9_dwcac_c/ (run.py, file.py, brute*.py, permuter outputs).
