# w9_nm2: overlay SDK near misses, wave 9, lane 2

Brief: docs/sessions/2026-09-28/ovsdk_brief.md. I opened no `.c`/`.h` under `sdk/` and ran no git
command. Vendor objects were read only through `tools/sdkobj.py`. Each status below is copied from
`manifest --verify --force --shard` output. I stopped at the context budget after 12 of the 20 rows;
rows 13 to 20 were not reached.

## Closed (3 functions, 372 B)

| region | address | function | B | what closed it |
|---|---|---|---|---|
| ov172 | 0x021C19E4 | Yos_JPEGGetMemorySize | 156 | both alignment masks as locals (`mx = samplingx * 8 - 1; dx = (width + mx) & ~mx;` and the same for y) instead of the inline `samplingN * 8 - 1` expressions; the object holds one mask in r4 and the other in a short-lived r2 |
| ov009 | 0x02197A30 | gti2SendAck | 168 | the two 2-byte copies written through pointer locals (`s = (unsigned char *)&dataLength` assigned after `dataLength = 5`, then `d = (unsigned char *)buffer + pos`, `d[0] = s[0]; d[1] = s[1];`); this keeps the address arithmetic in registers instead of folding to sp offsets and the arm is no longer if-converted (144 B to 168 B, then 5 B, then EXACT by assigning `s` after the constant) |
| ov016 | 0x021D1F6C | DWCi_MOV_MBP_AcceptChild | 160 | the pointer is the vendor global `wb`: `extern WPB *g_021DE65C` with `typedef struct { u16 a[7]; } WPB` and `g_021DE65C->a[1] &= m;` in place of the `0x021DE65C` cast; interrupts saved and restored through the real prototypes; callees in ov107 carry an `ov107` hint |

The lever that closed two of them: a value that must stay a register-held pointer or a named temporary
(pointer locals for a 2-byte copy, mask locals) stops the compiler from folding it into an
immediate or a stack offset.

## Improved, still pending

| region | address | function | B | before | after | change |
|---|---|---|---|---|---|---|
| ov015 | 0x0217A034 | IRCi_Send | 152 | 16 B | 10 B | dedicated `buf = g_0217ABD8` assigned after the copy loop and declared before pHeader puts i in ip and the pointers in r6/r5; the last call keeps the pool word |

## Residue (rows still open)

| region | address | function | B | state | tried this wave |
|---|---|---|---|---|---|
| ov015 | 0x0217A034 | IRCi_Send | 152 | DIFF 10 B | left: the object stores sumLo before sumHi (the scheduler swaps them; store order, masks, byte pointer, locals unchanged) and the second loop counter is r1 not ip |
| ov114 | 0x021BACFC | NHTTPi_setReqQueue | 152 | DIFF 17 B | any form that stores field_0x08 after the increment moves id to r6 and req_p to r4 (36 to 48 B) |
| ov114 | 0x021BBA14 | NHTTPi_CancelRequestAsync | 152 | DIFF 66 B | static inline helpers for the flag test, store, both: no change |
| ov016 | 0x021D04BC | taskBegin4 | 156 | DIFF 12 B | x = 176 as argument, cell or MEMSTEP local, branch sense reversed: the compiler keeps mov, str x, ldr MemStep |
| ov009 | 0x021700C8 | DWCi_EncodeBinaryMsgCommand | 160 | DIFF 20 B | u8 local for len * 4, `len *= 4` after the copy, idp pointer local, six store orders: pool base stays r0 |
| ov016 | 0x021B97A8 | InitAtermApcNetwork | 164 | DIFF 173 B (thumb) | struct for the global, no `t` local (folds 0xd0+0xc0), three declaration orders: ours spills maxap to [sp] and hoists 0xc0/0x24d0; the object has no frame |
| ov009 | 0x0215E6B8 | SOCL_Shutdown | 172 | DIFF 120 B | `int open = IsOpen(s); if (open == 0)` brings it to 76 B (draft not updated: the improvement is a spelling I have not confirmed on the final body); the object reloads flags at each of four accesses |
| ov009 | 0x0217D280 HexEncode16, 0x02158524 send_ping, 0x0215D070 SOCL_CreateSocket, 0x0216980C DWCi_GetFriendBuddyStatus, 0x02163438 CPSi_md5_calc, 0x02163CF0 CPSi_sha1_calc, 0x021A174C SBSendNatNegotiateCookieToServer, 0x02168064 DWC_NASLoginAsync | | 172-192 | not reached | |
| ov172 | 0x021BF0B0 | get_matrix_sub | 172 | not reached | |
| ov114 | 0x021CA5E4 | ASN1Skip | 184 | not reached | |

Next pass: apply the pointer-local and named-temporary levers (they closed gti2SendAck and
Yos_JPEGGetMemorySize) to every remaining row whose diff is address or immediate folding;
run the not-reached rows in order. For SOCL_Shutdown, test the `open` local against the full body first.

## Exact file list

Moved (plain `mv`/rewrite from src/pending/ov_sdk to src/matched/ov_sdk), each with a new shard:
- src/matched/ov_sdk/ov172_func_021C19E4.c (layout/matched/ov172/pkt_ov172_021C19E4.json): EXACT
- src/matched/ov_sdk/ov009_func_02197A30.c (layout/matched/ov009/pkt_ov009_02197A30.json): EXACT
- src/matched/ov_sdk/ov016_func_021D1F6C.c (layout/matched/ov016/pkt_ov016_021D1F6C.json): EXACT; renamed from
  src/pending/ov_sdk/func_021D1F6C.c (unprefixed draft, deleted), header packet is now pkt_ov016_021D1F6C

Modified (body and/or header notes):
- src/pending/ov_sdk/ov015_func_0217A034.c: body improved (16 to 10 B), w9_nm2 note
- src/pending/ov_sdk/ov114_func_021BACFC.c, ov114_func_021BBA14.c, ov016_func_021D04BC.c,
  ov009_func_021700C8.c, ov016_func_021B97A8.c, ov009_func_0215E6B8.c: w9_nm2 notes only, bodies unchanged

New: docs/sessions/2026-09-29/reports/w9_nm2.md (this report).
Deleted: src/pending/ov_sdk/ov172_func_021C19E4.c, ov009_func_02197A30.c, func_021D1F6C.c (moved or renamed above).
Not touched: layout/symbols_sdk.json, layout/function_starts.txt.

## Checks

The three shards were verified with `manifest --verify --force --shard` and report EXACT. I did not run
`manifest --check`, `selftest --quick` or a ROM build.
