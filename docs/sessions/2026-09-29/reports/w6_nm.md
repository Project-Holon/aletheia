# w6_nm: overlay SDK near misses, wave 6

Brief: docs/sessions/2026-09-28/ovsdk_brief.md. I opened no `.c`/`.h` under `sdk/` and ran
no git commands. I read the vendor objects only through `tools/sdkobj.py`. Each status
below is copied from `manifest --verify --force --shard` output, and a second plain verify
rewrote 0 for every shard.

## Closed (5 rows, 408 B)

| region | address | function | B | what closed it |
|---|---|---|---|---|
| ov016 | 0x021D5904 | DWCi_FNTlEnd | 76 | second pool word for MemFont spelled through the alias `g_021DE680_free` (same address) for the `DWCi_HEAPlFree_` argument |
| ov016 | 0x021BD7F4 | DWCi_ICONlEnd | 64 | same idiom, alias `g_021DE558_b` for `&MemIcon`. I also wrote the header (the draft had none) |
| ov016 | 0x021D4A20 | DWCi_ARClEnd | 116 | same idiom: `MemArchive` became extern (it was a static in the draft), plus `MemArchive_b` for the last free. `rom:/` stays `template` |
| ov009 | 0x02167EA0 | DWCi_Np_GetAppGameName | 56 | same idiom: `g_021AA828_b[4] = 0` for the store. The vendor pools `s_romHeaderGameCode` twice (+0x2C, +0x34) |
| ov009 | 0x02194AD8 | gti2VerifyChallenge | 156 | both comparisons written as `? 1 : 0` conditional expressions, as in the GameSpy CALCULATE_ODDMODE form: `(b[i-1] & 1) ^ (i & 1) ^ oddmode ^ (b[0] & 1) ^ ((b[0] < 79) ? 1 : 0) ^ ((b[i-1] < b[0]) ? 1 : 0)`. An exhaustive search over all 1,680 xor bracketings and term orders with plain comparisons found no match |

For the four duplicated-pool rows, `sdkobj.py` shows both pool words relocated against the
one vendor static (MemFont, MemIcon, MemArchive, s_romHeaderGameCode). The image holds that
address in both words. The aliases are not vendor names, and the integrator may rename them.
Evidence note: `match.py` resolved `g_021DE558`/`g_021DE558_b` (ICONlEnd) as `string x1, e.g.
021DE555`, not `sole-ref`. The written shard records no evidence entry for it. The vendor
relocations agree with the address, but the integrator may want to check why the `string`
class claims a `.bss` pointer.

New idiom: when mwcc emits a single-bit xor chain with operands in the wrong order, try
`(cmp) ? 1 : 0` in place of the bare comparison.

## Residue (rows still open)

| region | address | function | B | state | what I tried (new this wave) |
|---|---|---|---|---|---|
| ov009 | 0x021990A0 | GetClientUniqueID | 52 | DIFF 1 insn | result local, hi/lo locals, `-(int)0x80000001`, if-block form, function-pointer call, cc 1.1, lang c++: always `sub r1,r0,#0x80000002` (derived from r0 == 1). This looks like a peephole the vendor's 4.0.0.1025 build lacks |
| ov175 | 0x021DFF78 | sciReportSetPlayerConnectionId | 40 | DIFF 3 insn | `&buffer[off]` (char and unsigned char), `= 0` then assignment, sizeof-derived offsets, const `[16]` GUID, casts: the buffer still lands in ip |
| ov175 | 0x021DFFA0 | sciReportSetPlayerTeamIndex | 40 | DIFF 4 | not retried (same shape as above) |
| ov114 | 0x021BA988 | NHTTPi_CleanupAsync | 140 | DIFF 2 insn | socket local, length in a dead if or `\|\| 1` nest, length local, u64 length prototype, typed NULL: socket still loads to r0 (the image uses r2) |
| ov016 | 0x021D3638 | DWCi_MOV_WH_Initialize | 120 | DIFF 13 | goto exits with a shared label (both senses), a result local through goto, u8 return and callee types: the 0/1 register roles stay swapped |
| ov009 | 0x0217D8E0 | gsLargeIntDiv | 36 | SIZE 32 vs 36 | a static callee declared, and one defined after the caller in the same TU: no lr/ip shuffle |
| ov016 | 0x021D06A4 | taskEnd0 | 144 | DIFF 12 B | store as a call argument (assignment and comma forms), the literal in the call, a threaded end flag, clamp then recheck. Note: the DWARF lists an extra `GXOamAttr *obj` local, but taskBegin4 has the same residue without it |
| ov016 | 0x021D04BC | taskBegin4 | 156 | DIFF 12 B | same residue as taskEnd0 (the cell load sits after the `x = 176` store); not retried separately |
| ov009 | 0x02164490, 0x021644B4 | get48bits_2, get64bits | 16, 28 | pending | not retried |
| ov114 | 0x021BAD94 | NHTTPi_findReqQueue | 76 | DIFF 10 | not retried |
| ov009 | 0x02167E20 | WcmWmcbSetDCFDataAsync | 104 | DIFF 10 | not retried |
| ov114 | 0x021BAF2C | getcharFromHdrRecvBuf | 116 | DIFF 4 | not retried |
| ov009 | 0x0217EFB8 | getlocalhost | 128 | MATCH | needs tooling (overlay `.bss` rule) |
| ov009 | 0x02195EC4 | gti2ConnectionError | 152 | DIFF 13 | not reached |
| ov114 | 0x021BACFC | NHTTPi_setReqQueue | 152 | DIFF 22 | not reached |
| ov114 | 0x021BBA14 | NHTTPi_CancelRequestAsync | 152 | DIFF 27 | not reached |
| ov009 | 0x021700C8 | DWCi_EncodeBinaryMsgCommand | 160 | DIFF 15 | not reached |
| ov016 | 0x021D1F6C | DWCi_MOV_MBP_AcceptChild | 160 | DIFF 25 | not reached (file `func_021D1F6C.c` has no overlay prefix) |
| ov016 | 0x021B97A8 | InitAtermApcNetwork | 164 | DIFF 93 (thumb) | not reached |
| ov009 | 0x02197A30 | gti2SendAck | 168 | DIFF 32 | not reached |

Tooling note: taskEnd0 and taskBegin4 report CCERR (`_Bool`) under `match.py one` unless
`--lang c99` is passed. Their headers say c99, so manifest verify is not affected.
No stub callee blocked any row this wave, so I did not use the w3_tools procedure.

## Exact file list

Moved (plain `mv`) from src/pending/ov_sdk to src/matched/ov_sdk and edited, each with a
new shard `layout/matched/<ovNNN>/pkt_<ovNNN>_<ADDR>.json`:
- ov016_func_021D5904.c (layout/matched/ov016/pkt_ov016_021D5904.json)
- ov016_func_021BD7F4.c (layout/matched/ov016/pkt_ov016_021BD7F4.json)
- ov016_func_021D4A20.c (layout/matched/ov016/pkt_ov016_021D4A20.json)
- ov009_func_02167EA0.c (layout/matched/ov009/pkt_ov009_02167EA0.json)
- ov009_func_02194AD8.c (layout/matched/ov009/pkt_ov009_02194AD8.json)

New files: none except this report and the 5 shards above. Deleted: none. The 5 pending
files moved, so none of them remains in pending.

Modified (header note only; bodies are unchanged) in src/pending/ov_sdk/:
- ov009_func_021990A0.c, ov175_func_021DFF78.c, ov114_func_021BA988.c,
  ov016_func_021D3638.c, ov009_func_0217D8E0.c, ov016_func_021D06A4.c

Not touched: layout/function_starts.txt, layout/symbols_sdk.json, asm/.

## Checks

- Each of the 5 shards passes `manifest --verify --force`, and a plain verify then rewrote 0. All are EXACT.
- `manifest --check`: clean (10370 shard files).
- `selftest --quick`: 281 cases, 0 failures.

Totals: 5 functions to EXACT (408 B). 20 rows remain open.
Next pass: the unreached 150-170 B rows, getcharFromHdrRecvBuf (4 insns), and a
tooling look at getlocalhost and mytok (overlay `.bss` or named local statics).
