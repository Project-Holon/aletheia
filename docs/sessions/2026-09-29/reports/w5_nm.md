# w5_nm: overlay SDK near misses, two progress-callback stubs

Brief: docs/sessions/2026-09-28/ovsdk_brief.md. I opened no `.c`/`.h` under `sdk/`. I read
the vendor objects only through `tools/sdkobj.py` and its module functions. Each status
below is copied from `manifest --verify --force --shard` output, and a second plain verify
rewrote 0 for every shard.

## Part 1: near misses closed (10 rows, 1,076 B)

| region | address | function | B | what closed it |
|---|---|---|---|---|
| ov175 | 0x021DD290 | sakeSetProfile | 60 | `memcpy(sake->loginTicket, loginTicket, 25)` through string.h. The parameter must be `const char *` (the DWARF has `char *`); with plain `char *` the copy compiles 4 bytes longer |
| ov016 | 0x021D603C | DWCi_GXlVisible | 84 | read the plane mask into a local first, then read DISPCNT again inside the store expression (get-then-set). Reading both values into locals up front swapped r0 and r2 |
| ov016 | 0x021D6090 | DWCi_GXlInvisible | 92 | same shape, with `v & ~plane` |
| ov009 | 0x0219E0C0 | SBServerGetStringValueA | 96 | one guard, `if (ptr == 0 \|\| strlen(ptr->value) == 0) return def; return ptr->value;`, with strlen from string.h |
| ov009 | 0x0219E274 | CheckValidKey | 96 | fill InvalidKeys with one 8-byte struct assignment (both loads happen before either store). See the evidence note below |
| ov009 | 0x02176FD4 | DWC_SendReliableBitmap | 112 | `aidbit = (aid != 0) ? (1 << aid) : 1;`: the conditional expression keeps the two constant 1s in separate registers (r7/r8) |
| ov114 | 0x021C23E4 | ghiNewPost | 120 | the 7x4 byte loop is `memset(post, 0, sizeof(GHIPost))` through string.h, after the null check |
| ov009 | 0x021A1254 | ProcessDeleteServer | 136 | two string.h memcpy calls, ip first and then port |
| ov016 | 0x021D5BC0 | taskLoad | 136 | written from the DWARF (`bool *renew`, `MemFont->bg[n]`, a `renew == &MemFont->renew[0]` test). The object reads `work` from r1 although the DWARF lists only `work`, so the task's first argument (unnamed in the vendor) is spelled `task` |
| ov114 | 0x021BA590 | NHTTPi_compareToken | 144 | case fold `(((c) >= 'A') & ((c) <= 'Z')) ? (c) + 0x20 : (c)` (bitwise AND of the two range tests) in `while (fold(*p1) == fold(*p2)) { terminator test; ++ }` then `return -1` |

New idioms worth indexing:
- A `mov #1 / movlt #0 / tst` flag pair comes from `&` between two comparisons used as a
  conditional-expression test.
- A constant reused in two roles stays in two registers when one use is a conditional
  expression.
- A memset of a small struct inlines as a byte-store loop.
- string.h `memcpy` with a `const` source can differ from a non-const one.

Evidence note for CheckValidKey: the vendor initializer is `@13711` at 0x021A8120. Its body
is two relocated string pointers (0x021A8128, 0x021A8118), which the `template` class
cannot compare (it compares raw bytes). So I declared the address as the data label
`g_021A8120`, and it resolves as `sole-ref`, the same witness the old draft used. The
integrator may prefer to see this attested as a template once the tooling can handle
relocated template words.

## Part 2: stubs (w3_tools procedure)

| region | address | vendor symbol (member) | B | witness |
|---|---|---|---|---|
| ov009 | 0x02174FE4 | DWCi_NNProgressCallback (dwc_match.o, static) | 4 | DWCi_DoNatNegotiationAsync (0 mismatches) +0xB8 ABS32, image word 0x02174FE4 at 0x0216FEEC |
| ov009 | 0x0219BA54 | NatNegProgressCallback (qr2.o, static) | 4 | qr_process_client_message (0 mismatches) +0x1AC ABS32, image word 0x0219BA54 at 0x0219C550 |

For each stub:
- The member symbol is 4 bytes of `bx lr`, has 0 mismatches and no relocation inside it.
- Every located row of the same object was scanned. Each has exactly one relocation that
  names the stub, and it agrees with the stub address.

What I changed:
- Before editing, no file under asm/ had changed in the previous 2 minutes.
- Seeded both starts in `layout/function_starts.txt` with witness comments, then ran
  `disasm.py overlay 9`: 1617 functions (was 1615).
- Added catalog rows to `layout/symbols_sdk.json`: size 4, concrete 4, dupes 1,
  `referenced: true`. Siblings are the counts after insertion: dwc_match.o 155, qr2.o 35.
  Both rows are in (address, name) order. No existing row changed (26 added lines).
- Unblocked: ov009 0x0216FE34 DWCi_DoNatNegotiationAsync (188 B) went from MATCH to EXACT
  and moved to matched.
- ov009 0x0219C3A4 qr_process_client_message stays MATCH. Its only open site is now
  `@13818` at 0x021A1B64: that byte pattern occurs three times in ov009, and the copy at
  NNMagicData is not a template, so elimination (prong b) cannot apply. I updated its note.
- Side effects: the new starts shortened two extents, so `pkt_ov009_02174ED0` and
  `pkt_ov009_0219B918` went from EXACT* to EXACT. I changed both headers to EXACT.

## Part 3: residue

| region | address | function | B | result | residue |
|---|---|---|---|---|---|
| ov009 | 0x0219E2D4 | mytok | 104 | DIFF to MATCH (byte-correct) | The DWARF's function-local static `thestr` plus `*thestr++ = '\0'` gives every byte. Our compiler emits the function-local static as `.bss+0`, while the vendor relocates the named local static `_ZZ5mytokPccE6thestr`. A file-scope static or extern resolves as sole-ref but costs 9 bytes. This needs tooling, as getlocalhost does |
| ov114 | 0x021BA988 | NHTTPi_CleanupAsync | 140 | DIFF 111 B to 2 B | Rewritten from the DWARF: CheckCurrentThread(threadInfo_p, TRUE), and SocClose(NULL, 0) then socket = -1. Remaining difference: the socket load goes to r2 in the image and r0 here |
| ov016 | 0x021D4A20 | DWCi_ARClEnd | 116 | DIFF, 3 B and 4 B short | The vendor pools the static MemArchive twice (+0x6C and +0x70); 1.1p1 reuses r4. The `rom:/` string now resolves as `template`. I did not try a second extern name, because the vendor relocates both words against one name |
| ov009 | 0x02167E20 | WcmWmcbSetDCFDataAsync | 104 | DIFF 35 | if-conversion of the `-5` arm; 12 more spellings listed in the file |
| ov114 | 0x021BAF2C | getcharFromHdrRecvBuf | 116 | DIFF 14 | load/store scheduling; 9 more spellings plus cc 1.2 to 1.6sp2 |
| ov016 | 0x021D06A4 | taskEnd0 | 144 | DIFF 12 | cell load and x store order; 6 more spellings |
| ov009 | 0x021990A0 | GetClientUniqueID | 52 | 3 B | also cc 1.2 to 1.6sp2 (3 B) and 2.0 (23 B); -O4,s, -O3,p, -O2 and -O4 all give the same result |

Not retried: get48bits_2, get64bits, gsLargeIntDiv, the two sciReport rows,
NHTTPi_findReqQueue and getlocalhost (all in w4_nm's table).

## Exact file list

New in src/matched/ov_sdk, each with a new shard `layout/matched/<ovNNN>/pkt_<ovNNN>_<ADDR>.json`:
- ov175_func_021DD290.c
- ov016_func_021D603C.c, ov016_func_021D6090.c, ov016_func_021D5BC0.c
- ov009_func_0219E0C0.c, ov009_func_0219E274.c, ov009_func_02176FD4.c, ov009_func_021A1254.c
- ov114_func_021C23E4.c, ov114_func_021BA590.c
- ov009_func_02174FE4.c, ov009_func_0219BA54.c (stubs)

Moved (plain `mv`) from src/pending/ov_sdk to src/matched/ov_sdk, with a new shard:
- ov009_func_0216FE34.c (layout/matched/ov009/pkt_ov009_0216FE34.json)

Deleted from src/pending/ov_sdk (replaced by the matched files above):
- ov175_func_021DD290.c, ov016_func_021D603C.c, ov016_func_021D6090.c, func_021D5BC0.c
  (this name had no overlay prefix; the matched file is ov016_func_021D5BC0.c),
  ov009_func_0219E0C0.c, ov009_func_0219E274.c, ov009_func_02176FD4.c,
  ov009_func_021A1254.c, ov114_func_021C23E4.c, ov114_func_021BA590.c

Modified:
- layout/function_starts.txt (2 seeds plus a comment block)
- layout/symbols_sdk.json (2 rows added)
- src/matched/ov_sdk/ov009_func_02174ED0.c, layout/matched/ov009/pkt_ov009_02174ED0.json (EXACT* to EXACT)
- src/matched/ov_sdk/ov009_func_0219B918.c, layout/matched/ov009/pkt_ov009_0219B918.json (EXACT* to EXACT)
- Pending, rewritten body and note: src/pending/ov_sdk/ov009_func_0219E2D4.c,
  ov114_func_021BA988.c, ov016_func_021D4A20.c
- Pending, note only: src/pending/ov_sdk/ov009_func_02167E20.c, ov114_func_021BAF2C.c,
  ov016_func_021D06A4.c, ov009_func_0219C3A4.c

Regenerated, untracked: asm/overlays/ov009.s. I did not refresh the worklist or coverage.

## Checks

- Each shard above passes `manifest --verify --force`, then a plain verify that rewrote 0.
  All are EXACT.
- `manifest --check`: clean (10287 shard files).
- `selftest --quick`: 281 cases, 0 failures.

## Process slip

I ran one read-only `git diff --stat layout/symbols_sdk.json` to count the added lines. It
changed nothing. No other git commands were used.

Totals: 11 functions to EXACT (1,264 B: 10 near misses plus DoNatNegotiationAsync), 2 new
stubs (8 B), and 2 existing shards went from EXACT* to EXACT.
