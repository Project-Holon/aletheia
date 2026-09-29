# w9_nm: overlay SDK near misses, wave 9

Brief: docs/sessions/2026-09-28/ovsdk_brief.md. I opened no `.c`/`.h` under `sdk/` and ran no git command.
Vendor objects were read only through `tools/sdkobj.py`. Statuses are copied from `match.py one` and
`manifest --verify --force --shard` output; a second plain verify of the touched shards rewrote 0.
`manifest --check`: clean. No ROM build was run.

## Closed (3 functions, 268 B)

| region | address | function | B | what closed it |
|---|---|---|---|---|
| ov009 | 0x02160130 | get_rootCA | 76 | a guarded do-while: `if (n > 0) { list = con->rootCa; do { ... i++; } while (i < n); }`; the list load lands after the loop-entry compare, as in the object |
| ov114 | 0x021BA25C | NHTTPi_getUrlEncodedSize2 | 116 | an explicit `if (len > 0) { for (; i < len; i++) ... }` around the loop gives the object's guard (cmp, preloaded ldrsb, cmpgt) |
| ov114 | 0x021BAF2C | getcharFromHdrRecvBuf | 76 | `const struct _NHTTPRes *res_p`: both scheduling swaps (add before strlt, ldr 0x34 before str) disappear; the const-input lever again |

All three are EXACT. getcharFromHdrRecvBuf lives in the shared shard pkt_ov114_021BAED4 (5 entries, all EXACT).

New levers: (1) an explicit guard `if` around a loop (do-while or for) picks the object's preheader shape;
(2) `const` on the struct parameter also fixes "ldr after str" swaps when the stores go through other pointers.

## Improved, still pending

| region | address | function | before | after | change |
|---|---|---|---|---|---|
| ov172 | 0x021C0370 | GetWord | 27 B | 7 B | `word = (unsigned short)src[cur] | word;` in the little-endian arm; the big-endian arm is now byte-identical and both arms branch |

## Residue (rows still open)

| region | address | function | B | state | tried this wave |
|---|---|---|---|---|---|
| ov009 | 0x0215E2C0 | SOCLi_GetWriteBufferFreeSize | 36 | DIFF 4 B | object loads +0 into r1 and +2 into r0 (result reg = out); 14 spellings incl. declaration orders, u16 locals, split subtract, const pointers, direct expression, if-return |
| ov009 | 0x0217D8E0 | gsLargeIntDiv | 36 | SIZE | not moved (vendor DWARF puts divisor in r14, dest in r12); no new spelling beyond w4 to w7 |
| ov009 | 0x021990A0 | GetClientUniqueID | 52 | DIFF 1 insn | not retried, w8 covered it |
| ov172 | 0x021C0370 | GetWord | 80 | DIFF 7 B | LE arm wants zext(word) first and the byte shifted in the orr; 14 spellings |
| ov172 | 0x021C2050 | SSP_YUV422ToYUV888 | 96 | DIFF 35 B | object keeps yuyv in r1, Cb base in r4, schedules the third pair's mask before the first store; explicit cb pointer, DWARF decl order, size split, while form, result locals: 35 to 44 B |
| ov009 | 0x02167E20 | WcmWmcbSetDCFDataAsync | 104 | DIFF (100 vs 104 B) | `~4`, if/else, padded arm, volatile result: arm always if-converted |
| ov009 | 0x0215D3C8 | SOCLi_InitCommandPipe | 116 | DIFF 22 B | object loads ldrh stacksize and ldrb prio before the pool load; locals (u32, u16/u8, both orders), thread local, swapped prototype: 22 B |
| ov009 | 0x02163E40 | CPSi_rc4_init | 120 | DIFF 21 B | register roles only (m r4, temp r3/r0); decl orders, separate counter, casts |
| ov016 | 0x021D3638 | DWCi_MOV_WH_Initialize | 120 | DIFF 5 B | five more return spellings, all 15 B or worse than the w8 form |
| ov009 | 0x02166600 | WCMi_MergeToBuffer | 128 | DIFF 84 B | switch hoists `mov r6,r1` above the compares in every spelling; object tests 1 then 2 then default; the byte swap should be `((len & 0xff) << 8) | ((len & 0xff00) >> 8)` |
| ov015 | 0x02179F74 | IRC_Init | 80 | DIFF 11 B | locals for 0xff and 0, chained stores, `-1`: unchanged |
| ov016 | 0x021D06A4 / 0x021D04BC | taskEnd0 / taskBegin4 | 144/156 | DIFF 12 B | const-qualified MemStep (macro cast, member, cell[]) and a `MEMSTEP *const` local: cell load still after the x store |
| ov016 | 0x021D0DE0 | cbWm | 148 | DIFF | object keeps the st != 0 arm as popne/mov/strb/pop (148 B), compile predicates it (144 B); 5 arm spellings and the inline setSt helper |
| ov009 | 0x0215F0F0 | SOCLi_IsIPv4ValidDNSAddr | 148 | DIFF | isA as if/return chains is worse (99 to 101 B); object branches on isA with no result temp |
| ov009 | 0x0215E588 | SOCLi_GetOptimumSendBufLen | 152 | DIFF 21 B | object loads winSize in r3, mss in r2 and the g_021AA450 base before the first compare; mss/buf locals: 21 to 27 B |
| ov114 | 0x021BA988 | NHTTPi_CleanupAsync | 140 | DIFF 2 B | not retried (socket loads to r0, object r2) |
| ov009 | 0x02195EC4 | gti2ConnectionError | 152 | DIFF | not reached |

Rows not attempted: gti2ConnectionError (context). Next pass: try the "guard if around the loop" lever on
any remaining row with a preheader mismatch (rc4_init, YUV422); WCMi_MergeToBuffer needs an if-chain
that keeps `mov r6,r1` in the default arm (try `if (id == 1 || id != 2)` forms).

## Exact file list

New: docs/sessions/2026-09-29/reports/w9_nm.md (this report)

Moved (plain `mv`) from src/pending/ov_sdk to src/matched/ov_sdk:
- ov009_func_02160130.c (shard layout/matched/ov009/pkt_ov009_02160130.json, new): body, header status EXACT, note
- ov114_func_021BA25C.c (shard layout/matched/ov114/pkt_ov114_021BA25C.json, new): body, header, note
- ov114_func_021BAF2C.c (existing shard layout/matched/ov114/pkt_ov114_021BAED4.json, entry rewritten to EXACT): body, header, old blocker text replaced by a note

Modified (pending, header notes only unless stated):
- src/pending/ov_sdk/ov172_func_021C0370.c: body improved (27 B to 7 B) plus note
- ov009_func_0215E2C0.c, ov009_func_0217D8E0.c, ov172_func_021C2050.c, ov009_func_02167E20.c, ov009_func_0215D3C8.c, ov009_func_02163E40.c, ov016_func_021D3638.c, ov009_func_02166600.c, ov015_func_02179F74.c, ov016_func_021D06A4.c, ov016_func_021D04BC.c, ov016_func_021D0DE0.c, ov009_func_0215F0F0.c, ov009_func_0215E588.c, ov114_func_021BA988.c, ov009_func_02195EC4.c, ov009_func_021990A0.c: w9_nm note only

Deleted: none (the three pending copies were moved). No volatile was added anywhere.
