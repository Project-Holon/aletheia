# Lane T28 — ov114 open SDK rows 10–18 (CRYPTO/NHTTP/DWC/GHI)

Measured 2026-09-30. Slice: `python scratch/a2/open_rows.py ov114 10 9` → 8 rows
(0x021CC674 … 0x021CD210). **0 of 8 closed.** ~90 compiles, wall clock ≈ 80 min.
Every residue below was read from a live `match.py one … --diff` and, for the first time on
this slice, from the vendor object via `python tools/sdkobj.py <addr> --region ov114`.

Harness line (all rows, `--lang c99 --arm --cc 1.1p1`):

```
python tools/match.py one --src src/pending/ov_sdk/ov114_func_<ADDR>.c \
    --func <name> --addr 0x<ADDR> --region ov114 --arm --cc 1.1p1 --lang c99 --diff
```

`--func` is the name the *draft* defines, which for 0x021C7644 / 0x021C68BC / 0x021BD7E8 /
0x021C3218 / 0x021CD210 is the SDK name (`DWCi_Ndi_response_list`, `req_callback`,
`NHTTPi_ThreadSendProc`, `ghiPostStateDoPosting`, `CRYPTOi__BN_mod_exp_mont`), not `func_<ADDR>`.

## Rows (all DIFF, measured this lane)

| address | image B | compiled B | concrete | reloc | first differing instruction | residue class |
|---|---|---|---|---|---|---|
| 0x021CC674 | 408 | 408 | 43 | 2/2 | +0000 image `push {r3,r4,r5,r6,r7,r8,sb,sl,fp,lr}` \| ours `push {r4,…,sl,lr}` | regalloc (mask/tab pair swapped, `0xff` in fp vs sl) |
| 0x021BC740 | 484 | 484 | 142 | 10/10 | +0020 image `str r0,[sp,#0xc]` \| ours `mov sl,r0` | threadInfo_p spilled in object, kept in sl here |
| **0x021C9B64** | 568 | 568 | **6** | 23/23 | +0084 image `ldr r3,[pc,#0x19c]` \| ours `ldr ip,[pc,#0x19c]` | 20-byte copy: src/dst pair (r3,ip) vs (ip,r3) |
| 0x021C7644 | 640 | 724 | 507 | 10/10 | +0030 image `ldr r1,[pc,#0x244]` \| ours `ldr r1,[pc,#0x298]` | ours 84 B **larger**; first real shape split at +0080 (see below) |
| 0x021C68BC | 648 | 664 | 513 | 17/17 | +0008 image `mov r8,r0` \| ours `mov r7,r0` | regalloc from the prologue on |
| 0x021BD7E8 | 896 | 896 | 46 | 32/32 | +0014 image `mov r6,r0` \| ours `mov r7,r0` | global r6/r7 swap of two pointer groups |
| 0x021C3218 | 1564 | 628 | 537 | 15/17 | +0000 image `push {r4,…,sl,lr}` \| ours `push {r3,…,pc}` | **draft is a truncated stub**: ours returns at +0x270 (628 B), the object runs to +0x61C |
| 0x021CD210 | 1908 | 1764 | 1505 | 37/37 | +0000 image `push {r4,…,fp,lr}` \| ours `push {r3,…,fp,lr}` | frame: object `sub sp,#0x6c`, ours `#0x78` |

## What `sdkobj.py` settled (the reusable finding)

The DWARF of the defining object gives the real prototype, the real local list **with the
register each local actually owns**, and the callee names. Three rows' drafts disagree with it in
ways that are not visible from the diff alone:

- **0x021C9B64** `DWCi_EncSessionCompleteCallback(char *buf, int len, enum @enum result)`;
  `buf` r5, `len` r7 (draft matches both); `hextbl[17]` fb+0, `tmpbuf[52]` fb+17 (draft matches);
  `hash` r4 (draft matches). The object has **six** ABS32 targets — `g_session`, `@16117`,
  `g_session+0x30` (secretkey), `@16432`, `g_session+0x74` (lastHash), `@16433` — and the
  20-byte copy reads `g_session+0x30` **into r3**, writing `tmpbuf` **through ip**. Only 6 single
  register-field bytes (3 instructions' worth) differ. 14 spellings reproduce them all: struct
  assign, `Key20` temp, pointer locals both orders, `&tmpbuf[0]`, `+0`, `(void*)`, `(const Key20*)`,
  a named dst-first block, `memcpy(...,20)` (552 B — not inlined as a struct copy), a 20-iteration
  byte loop (560 B). MWCC emits the load of the source address first and the `add <dst>, sp, #0x11`
  second in *both*, so the pair is an allocator tie-break, not a statement order.
- **0x021BD7E8** `NHTTPi_ThreadSendProc(struct _NHTTPThreadData *threadData_p)` — one param, r4.
  DWARF locals: `stat` **r7**, `urlLength` r10, `bgnEndInfo_p` r9, `req_p` r8, `threadInfo_p`/
  `connection_p`/`mutexInfo_p`/`reqInfo_p`/`sysInfo_p` r0 (no home), `datalist_p` r2,
  `isMultipartForm` r1, and **`char *commBuf_p`**, a local the draft does not have. Draft already
  matches r8/r9/r10; the whole 46-byte residue is that the object colours `{mutexInfo_p,
  connection_p, stat}` to r7 and `{sysInfo_p, threadInfo_p}` to r6, ours the other way round.
- **0x021BC740** `static int NHTTPi_RecvProxyConnectHeader(void)` — **no parameters**; locals are
  `totalRecvbyte` r8, `connectFlag` fb+8, `endFlag` r14, `recvbyte` r11, `i` r12, `tmpbuf[512]`
  fb+16, `res_p` r7, `req_p` r6, `commBuf_p` r0, `mutexInfo_p` r5, `bgnEndInfo_p` r4,
  `threadInfo_p`/`reqInfo_p`/`sysInfo_p` r0. The draft has `tmp_p` where the object has
  `commBuf_p` and a `volatile int endFlag` where the object keeps `endFlag` in **r14**; the frame
  (tmpbuf fb+16, connectFlag fb+8) is already identical. This row's draft header records 24,674
  declaration/qualifier permutations bottoming at 142 B, so it was not re-ground here.
- **0x021C7644** `DWCi_Ndi_response_list(void *res, struct tagDWCi_Ndi_HTTPREQ *hrq)`;
  locals `tempBuf[104]` fb+24, `body` fb+20, `bodyBufSize` fb+16, `contentlen` fb+12, `n` fb+8,
  `pfi` r8, `bgn` r7, `state` r6, `p` r5, `bodyLen` r4; callees `DWCi_Ndi_strToInt`,
  `DWCi_Ndi_memcpy`, `DWCi_Ndi_getDecodeLenBASE64`, `NHTTP_GetBodyBuffer`.
- **0x021C68BC** `req_callback(void *res, enum @enum event, void *arg)`, res r8 / event r10 /
  arg r4; the object holds `callback` r6, `reason` r5, `result` r9, `pos` r9, `serverError` r7,
  with `hrq` fb+4, `strHttpStatus` fb+16, `bodyBufSize` fb+20 — the draft's `mov r8,r0` at +0008
  is already the wrong group.
- **0x021C3218** `ghiPostStateDoPosting(state r8, connection r7, first, last)`; two
  `struct GSIDimeHeader header` slots (fb+8, fb+20), a `char buffer[2048]` at fb+32, and it calls
  the four `ghiPost*StateDoPosting` siblings plus `ghiTrySendThenBuffer`, `gsiSafeStrcpyA`,
  `OS_SPrintf`. Our draft compiles 628 B against 1564 B — it implements the head of the function
  and returns at +0x270 where the object is still in its first post-write path. **Needs writing,
  not spelling.**
- **0x021CC674 / 0x021CD210** — `sdkobj.py` reports *no DWARF subprogram* for either
  (`crypto_bobj1.o` carries no subprogram DIE for these names), so no register assignment is
  recoverable from this archive. Both rows also differ in body size (408/408 but 43 concrete;
  1908 vs 1764 B with the frame 0x6c vs 0x78), so the drafts' local/frame layout is wrong before
  any allocator question is reached.

## Levers measured, and what they bought

- **0x021BD7E8** — 20 declaration-order permutations (each of the 15 locals first, plus four
  group orders, plus full reverse): **all 896 B / 46 diffs**, identical first mismatch; adding the
  DWARF's `commBuf_p` at each of 15 declaration positions: **all 46**; using `commBuf_p` at the
  SocSend and both memclr sites: 89; `unsigned int stat`: 888 B / 89; leaving the DWARF order
  wholesale: 46 (and 100–103 when `stat` is pulled out of the top slot). Three spelling families
  (temp for the sysInfo result, inlining `reqInfo_p`, typed-vs-`void*` pointers) are inert.
  Confirms the earlier lane's 14 permutations on this pair.
- **0x021C9B64** — 14 spellings (listed above): 12 give exactly 6; `memcpy` gives 552 B, the
  byte loop 560 B. The 6 bytes are one allocator tie-break.
- **0x021BC740** — not re-ground (header records a 24,674-permutation sweep at 142 B).
- Nothing was filed: no shard was written, no source outside `src/pending/ov_sdk/` was touched
  except the copies in `scratch/lt28/var/`.

## Cheapest follow-ups

1. 0x021C9B64 — 6 bytes, one source/dest register pair. Whoever finds the spelling that makes
   MWCC take r3 for the loaded source address and ip for `sp+0x11` closes it; everything else in
   the function (23/23 relocs, frame, both copy idioms) is already byte-identical.
2. 0x021BD7E8 — 46 bytes, one colour swap. The object's answer is known exactly (r7 = stat +
   mutex/connection, r6 = sysInfo/threadInfo); what is missing is the source property that makes
   the colourer pick that order. 34 permutations so far, all inert.
3. 0x021C3218 — write the missing ~234 instructions (0x270…0x61C); DWARF gives the buffer
   (2048 B at fb+32) and the four `ghiPost*StateDoPosting` callees to structure it.
