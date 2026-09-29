# w8_nm: overlay SDK near misses, wave 8

Brief: docs/sessions/2026-09-28/ovsdk_brief.md. I opened no `.c`/`.h` under `sdk/` and ran no
git command. I read the vendor objects only through `tools/sdkobj.py` and its module functions
(one scratchpad script importing `sdkobj`). Each status below is copied from
`manifest --verify --force --shard` output, and a second plain verify rewrote 0 for every shard.

## Closed (9 functions, 632 B)

| region | address | function | B | what closed it |
|---|---|---|---|---|
| ov114 | 0x021B9C78 | NHTTPi_CpsAuthCallbackForDebug | 8 | new stub (`mov r0,#0; bx lr`), `int (void)` per the DWARF; w3_tools procedure, evidence below |
| ov114 | 0x021B9E3C | NHTTPi_SocSSLConnect | 144 | the stub above; the C is unchanged |
| ov175 | 0x021DFF78 | sciReportSetPlayerConnectionId | 40 | offset built in steps: `off = 0x44; off += index * 20;` |
| ov175 | 0x021DFFA0 | sciReportSetPlayerTeamIndex | 40 | the same, then `off += 16;` (the connection id size) |
| ov016 | 0x021CEF50 | DWCi_SEARCHlEnd | 52 | the object's `bne` goes back to the call: `while (WM_GetAllowedChannel() != 0x8000) {}` then the free; the two identical pool words (MemSearch) take a second extern `g_021DE640_b` |
| ov016 | 0x021C7960 | dispCaret | 84 | a static inline position setter whose expression has the y term before the x term |
| ov107 | 0x021F6890 | MBi_MakeParentSendBuffer | 120 | `const` header parameter with the `*ptr++` spelling and `hdr->type` in the switch (no u16 locals) |
| ov016 | 0x021D600C | DWCi_Coord2Rect | 48 | `const COORD *` inputs, plain four assignments |
| ov016 | 0x021D6B04 | DWCi_TPlCheckATrigger | 96 | `const AREA *` input, plain four assignments into `r` (inline helpers and x/y/w/h locals dropped) |

New lever: a `const` pointer parameter lets 1.1p1 load every field before the first store
through another pointer. It closed three rows here, and all three had the "loads interleaved
with stores" register pattern.

### Stub evidence (w3_tools procedure)

- NHTTPi_CpsAuthCallbackForDebug is a local symbol of nhttp_socket_ntr, 8 bytes
  (`0000a0e3 1eff2fe1`). Its vendor symbol matches the image at 0x021B9C78 with 0 mismatches,
  and it contains no relocation.
- NHTTPi_SocSSLConnect (located, 0 mismatches) relocates it at +0x88 with ABS32. The image
  word at 0x021B9EC4 is 0x021B9C78.
- No relocation disagrees, and the evidence comes only from ov114.
- **Catalog:** 1 row added to `layout/symbols_sdk.json` in (address, name) order, between
  NHTTPi_CpsAuthCallback and NHTTPi_SetSSLseed. It has `concrete = size = 8`, `dupes = 1`,
  `siblings = 13` (the ov114 nhttp_socket_ntr count after the insert) and
  `"referenced": true`. The dump is `json.dumps(indent=1, ensure_ascii=False)` with no
  trailing newline, which round-trips the old file byte-identical.
- **Seed:** 1 seed with a witness comment in `layout/function_starts.txt`, in a new block
  after the w7_nm block.
- **Listing:** `find asm -mmin -2` was empty. I then ran `python tools/disasm.py overlay 114`,
  which gave 480 funcs. 0x021B9C78 now prints as `func_021B9C78`, and the pool word prints
  `-> func_021B9C78`.
- **Side effect:** none. `ov114/pkt_ov114_021B9C6C` (the preceding NHTTPi_CpsAuthCallback)
  re-verifies with 0 rewritten and stays EXACT*, as before.

### Notes on the closers

- **TPlCheckATrigger:** it keeps the pre-existing `volatile unsigned short *` cast for the
  fold test at 0x02FFFFA8. The header says why: it is a fixed address with no variable, so the
  vendor DWARF cannot show a volatile there either way.
- **dispCaret:** the helper is file-local (`SetObjPosition`), and the header says it is inlined.

## Improved, still pending

| region | address | function | B | before | after | change |
|---|---|---|---|---|---|---|
| ov114 | 0x021BACFC | NHTTPi_setReqQueue | 152 | 46 B | 17 B | storing `list_p->id` before the increment puts listInfo_p, req_p and id in r6, r5, r4 |
| ov114 | 0x021BBA14 | NHTTPi_CancelRequestAsync | 152 | 75 B | 66 B | locals in reverse DWARF order (rc first) put rc, mutexInfo_p and reqCurrent_p in r4, r5, r6. The rest is a one-instruction shift |
| ov016 | 0x021D3638 | DWCi_MOV_WH_Initialize | 120 | 15 B | 5 B | `int r = 0; ... if (call) r = 1; return r;` puts 0 in r5 and 1 in r4 |

## Residue (rows still open)

| region | address | function | B | state | tried this wave |
|---|---|---|---|---|---|
| ov009 | 0x021990A0 | GetClientUniqueID | 52 | DIFF 1 insn | every compiler build (dsi 1.1 to 1.6sp2, mwcc 1.2); -O4,s, -O3, -O2, -O1; -opt nopeephole, noschedule, nocse, nopropagation, nostrength. All give `sub r1,r0,#0x80000002`, even -O1, so the choice is made in code generation. natneg.o is stamped 1025, which no build here writes |
| ov114 | 0x021BACFC | NHTTPi_setReqQueue | 152 | DIFF 17 B | the object reloads idRequest into r2 and stores list_p->id after the increment. Explicit reload spellings (`= x + 1`, `+= 1`, `++`, post-increment in the assignment, chained assignment) and moving the req/-1 stores give 17 to 46 B |
| ov114 | 0x021BBA14 | NHTTPi_CancelRequestAsync | 152 | DIFF 66 B | the object reloads `reqCurrent_p->field_0x0c` for the store after the predicated test. Not fixed by nested ifs (2 or 3 levels), rc = 1 first, `!*p`, an unsigned or volatile-cast deref, or a listInfo_p local |
| ov016 | 0x021D3638 | DWCi_MOV_WH_Initialize | 120 | DIFF 5 B | the object returns with `moveq r0,r5; movne r0,r4`. The result local is not in the DWARF. Tried `? 1 : 0`, `!!`, `!= 0`, if/else returns in both senses, set-then-clear, the call result in a local, cc 1.1/1.2/1.2p1/1.3 |
| ov015 | 0x02179F74 | IRC_Init | 80 | DIFF 11 B | all 24 store orders, each with and without the DWARF local `size`: none under 11 B |
| ov009 | 0x021700C8 | DWCi_EncodeBinaryMsgCommand | 160 | DIFF 20 B | `len *= 4` and `len <<= 2` before the header stores, a u8-cast length store: unchanged (the object computes len * 4 into r0 before the id base goes into ip) |
| ov016 | 0x021D06A4 | taskEnd0 | 144 | DIFF 12 B | only looked at. The object loads step_bss.MemStep before it stores `x = 152` in the else arm. Run it with `--lang c99` (the draft uses `_Bool`) |
| ov114 | 0x021BA988 | NHTTPi_CleanupAsync | 140 | DIFF 2 insn | only looked at. The object keeps r0 and r1 live after GetConnectionListLength (the socket goes to r2), which suggests a used 64-bit or two-register result. Earlier waves tried a u64 prototype |
| ov009 | 0x0217D8E0 | gsLargeIntDiv | 36 | SIZE | not retried |
| ov114 | 0x021BAF2C | getcharFromHdrRecvBuf | 116 | DIFF 14 B | not retried |
| ov015 | 0x0217A034 | IRCi_Send | 152 | DIFF 16 B | not reached |
| ov016 | 0x021D04BC | taskBegin4 | 156 | DIFF | not reached (same object as taskEnd0) |
| ov016 | 0x021D0DE0 | cbWm | 148 | DIFF | not reached |
| ov009 | 0x02167E20, 0x0215D3C8, 0x0215F0F0, 0x02195EC4 | WcmWmcbSetDCFDataAsync, SOCLi_InitCommandPipe, SOCLi_IsIPv4ValidDNSAddr, gti2ConnectionError | 104-152 | DIFF | not reached |

Next pass: try the `const` parameter lever first on every remaining row that reads through one
pointer and writes through another. Candidates are taskEnd0/taskBegin4, IRCi_Send,
EncodeBinaryMsgCommand, SOCLi_InitCommandPipe and gti2ConnectionError. Then try the
split-offset form (`x = A; x += B;`) wherever a sum is CSE'd into the wrong register.

## Exact file list

New:
- src/matched/ov_sdk/ov114_func_021B9C78.c (layout/matched/ov114/pkt_ov114_021B9C78.json)
- docs/sessions/2026-09-29/reports/w8_nm.md (this report)

Moved (plain `mv`) from src/pending/ov_sdk to src/matched/ov_sdk, each with a new shard:
- ov114_func_021B9E3C.c (layout/matched/ov114/pkt_ov114_021B9E3C.json): header status only
- ov175_func_021DFF78.c (layout/matched/ov175/pkt_ov175_021DFF78.json): body and header (near-miss notes replaced by a note)
- ov175_func_021DFFA0.c (layout/matched/ov175/pkt_ov175_021DFFA0.json): body and header
- ov016_func_021CEF50.c (layout/matched/ov016/pkt_ov016_021CEF50.json): body, `_b` extern, header
- ov016_func_021C7960.c (layout/matched/ov016/pkt_ov016_021C7960.json): body and header
- ov107_func_021F6890.c (layout/matched/ov107/pkt_ov107_021F6890.json): body and header
- ov016_func_021D600C.c (layout/matched/ov016/pkt_ov016_021D600C.json): body and header
- ov016_func_021D6B04.c (layout/matched/ov016/pkt_ov016_021D6B04.json): body and header

Modified:
- layout/symbols_sdk.json (1 row added, nothing else changed)
- layout/function_starts.txt (1 seed with a comment block)
- src/pending/ov_sdk/ov114_func_021BACFC.c, ov114_func_021BBA14.c, ov016_func_021D3638.c: body improved, w8_nm note
- src/pending/ov_sdk/ov009_func_021990A0.c, ov015_func_02179F74.c, ov009_func_021700C8.c: w8_nm notes only, bodies unchanged

Regenerated, untracked: asm/overlays/ov114.s.

Deleted: none.

## Checks

- All 9 shards pass `manifest --verify --force`. A plain verify then rewrote 0, and all are EXACT.
- `manifest --check`: clean (11542 shard files, no duplicates).
- `selftest --quick`: 289 cases, 0 failures.
- No ROM build was run.
