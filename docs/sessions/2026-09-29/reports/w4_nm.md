# w4_nm: strcat unit member, ov009 ping stub, near-miss retries

Brief: docs/sessions/2026-09-28/ovsdk_brief.md. I opened no `.c`/`.h` under `sdk/` and read
vendor objects only through `tools/sdkobj.py` and its module functions.

## Part 1: ARM9 strcat and the ov009 stub

### strcat 0x020948B0 (unit_02094860)

- `match.py tu` on `src/matched/arm9/unit_02094860.c` gives EXACT: 2 code sections,
  func_02094860 (80 B) at 0x02094860 and func_020948B0 (48 B) at 0x020948B0, 0 relocations.
  The unit's own source already defines func_020948B0 at that address, and those bytes
  are part of the EXACT comparison.
- On the vendor side, strcat has no catalog row (it is a runtime-library function with no
  DWARF in the SDK objects). The overlay rows that call it are located with 0 concrete
  mismatches: BucketConcat, gpiSaveKeysToBuffer and value_for_key. Each names `strcat` in a
  PC24 relocation, and the image's `bl` at that slot decodes to 0x020948B0. The object's
  name and our compiled unit therefore agree on the address independently.
- The header `function:` line is now `func_02094860, func_020948B0`, which is how other
  units list several members. `manifest --verify --force --shard arm9/pkt_02094798` gives
  EXACT, and the shard's `functions` list now names both members. A second plain verify
  rewrote 0.
- `worklist.py --refresh` then `--summary`: ARM9 coverage by bytes is still
  **100.0000%** (400610 / 400610), with 0 open functions.
- This unblocked 3 files, now EXACT and moved to matched: 0x02193F00 value_for_key,
  0x0218DA40 gpiSaveKeysToBuffer and 0x02193A90 BucketConcat. I rewrote their stale
  blocker notes.

### gpiPeerPingReplyCallback, ov009 0x0218F880 (4 B, `bx lr`)

The evidence is the same kind w3_tools used for its stubs:
- The member symbol gpiPeerPingReplyCallback in libdwcgsgp.TWL.HYB.a(gpipeer.o) is 4 bytes
  and matches the image with 0 mismatches. It has no relocation inside it.
- gpiStartConnect is located with 0 concrete mismatches. Its ABS32 relocation at +0x3C4
  names gpiPeerPingReplyCallback, and the image word at 0x0218A5FC is 0x0218F880.

What I changed:
- Seeded `overlay_009 0x0218F880` in `layout/function_starts.txt` with a witness comment.
  No `asm/` file had changed in the previous 3 minutes; `disasm.py overlay 9` then gave
  1615 functions (was 1614).
- Added a catalog row to `layout/symbols_sdk.json`: size 4, concrete 4, dupes 1,
  siblings 24, `referenced: true`, placed before gpiPeerAddOp. No existing row changed.
- Wrote the stub `src/matched/ov_sdk/ov009_func_0218F880.c`, which verifies EXACT.
- Side effect: `pkt_ov009_0218F7B8` (gpiPeerAcceptedCallback) went from EXACT* to EXACT
  because its extent now stops at 0x0218F880. I changed its header to EXACT.
- ov009 0x0218A238 gpiStartConnect now has 45 of 45 relocations resolved. It is EXACT and
  moved to matched.

## Part 2: near misses

| region | address | function | B | result | what closed it / residue |
|---|---|---|---|---|---|
| ov009 | 0x02193A90 | BucketConcat | 116 | EXACT, moved | strcat unit member (Part 1) |
| ov009 | 0x02196CC8 | gti2HandleClosed | 56 | EXACT, moved | callee prototyped with enum parameters (GT2Result, GT2CloseReason) and the reason as an enum conditional; goto-shaped exit `if (!x) return 0; return 1;` |
| ov009 | 0x02196514 | gti2HandleClose | 68 | EXACT, moved | same two levers |
| ov009 | 0x0219B6CC | enum_local_ips | 112 | EXACT, moved | `memcpy(&local_ip_list[i], addr, sizeof(struct SOCInAddr))` through string.h; the struct assignment gave the converse ip/lr roles |
| ov009 | 0x02197BD4 | gti2SendClosedOnSocket | 136 | EXACT, moved | both 2-byte copies are string.h memcpy; the magic source is the literal "\xFE\xFE", which attests as `template` (@14988 at 0x021A5948, unique in ov009) |
| ov009 | 0x0217ECA4 | sendto | 84 | EXACT, moved | `memcpy(&remoteAddr, addr, sizeof(remoteAddr))` through string.h. The old note said "memcpy" had been tried, but without the intrinsic prototype |
| ov009 | 0x02164490 | get48bits_2 | 16 | DIFF | tried `|` / `+` / `^` combinations, a u64/u32 union and shift-accumulate; MWCC always adds an `orr hi,#0` or an add with carry. The sibling get48bits_3 is an asm body |
| ov009 | 0x021644B4 | get64bits | 28 | pending (asm reference) | same u64 assembly problem; not retried further |
| ov009 | 0x0217D8E0 | gsLargeIntDiv | 36 | DIFF 17 B | tried direct args, a static callee prototype, casts, and compilers dsi/1.1, 1.2, 1.2p1, 1.6sp2, 2.0/sp1p2; none reproduces the lr/ip parameter shuffle |
| ov175 | 0x021DFF78 | sciReportSetPlayerConnectionId | 40 | MATCH-level 4 B | enum return type, the DWARF local, and a scripted sweep of constant splits, init forms and call forms; the buffer lands in ip instead of r0 |
| ov175 | 0x021DFFA0 | sciReportSetPlayerTeamIndex | 40 | 4 B | same sweep; ip/r3 roles |
| ov009 | 0x021990A0 | GetClientUniqueID | 52 | 3 B | K&R/unsigned/long prototypes and several spellings of 0x7fffffff; the constant is always derived from r0 == 1 (`sub`) instead of `mvn` |
| ov114 | 0x021BAD94 | NHTTPi_findReqQueue | 76 | 14 B | do/while, for, goto and return loops are all worse; reading the head through two access paths still leaves head/cursor r3/ip swapped |
| ov009 | 0x0217EFB8 | getlocalhost | 128 | MATCH | byte-correct; the `.bss+0` slot (0x021AD0F4) is unattested because the `.bss` rule is ARM9-only (w3_tools). This needs tooling, not C |

Not attempted, for budget. Current residue in concrete bytes:
- 0x021DD290 sakeSetProfile: 41
- 0x021D603C DWCi_GXlVisible: 12
- 0x021D6090 DWCi_GXlInvisible: 22
- 0x0219E0C0 SBServerGetStringValueA: 25
- 0x0219E274 CheckValidKey: 16
- 0x02167E20 WcmWmcbSetDCFDataAsync: 35
- 0x0219E2D4 mytok: 22
- 0x02176FD4 DWC_SendReliableBitmap: 87
- 0x021BAF2C getcharFromHdrRecvBuf: 14
- 0x021C23E4 ghiNewPost: 31
- 0x021A1254 ProcessDeleteServer: 21

The memcpy/string.h lever closed three of the four copy-shaped rows here. The next pass
should try it first on any row with a struct or byte copy.

Totals: 9 files moved from pending to EXACT (2,624 B), plus 1 new stub (4 B). Of the 9, 3
were unblocked by strcat (value_for_key, gpiSaveKeysToBuffer, BucketConcat), 1 by the
stub (gpiStartConnect), and 5 closed by C changes.

## Other findings

- `src/matched/ov_sdk/ov009_func_02175EB4.c` (not mine) says `status: MATCH` in its
  header, but its shard verifies EXACT. The integrator should correct the header.
- Process slip: I ran one read-only `git status` (output suppressed) while checking file
  times. It changed nothing. No other git commands were used.

## Exact file list

Modified:
- src/matched/arm9/unit_02094860.c (function: line)
- layout/matched/arm9/pkt_02094798.json
- layout/function_starts.txt (1 seed and comment)
- layout/symbols_sdk.json (1 row added)
- src/matched/ov_sdk/ov009_func_0218F7B8.c (status EXACT* to EXACT), layout/matched/ov009/pkt_ov009_0218F7B8.json
- notes only: src/pending/ov_sdk/ov009_func_02164490.c, ov009_func_021644B4.c, ov009_func_0217D8E0.c,
  ov009_func_021990A0.c, ov114_func_021BAD94.c, ov175_func_021DFF78.c, ov175_func_021DFFA0.c

New:
- src/matched/ov_sdk/ov009_func_0218F880.c, layout/matched/ov009/pkt_ov009_0218F880.json

Moved from src/pending/ov_sdk to src/matched/ov_sdk (with plain `mv`; the owner stages
them), each with its shard at layout/matched/ov009/pkt_ov009_<ADDR>.json:
- ov009_func_02193F00.c, ov009_func_0218DA40.c, ov009_func_02193A90.c, ov009_func_0218A238.c,
  ov009_func_02196CC8.c, ov009_func_02196514.c, ov009_func_0219B6CC.c, ov009_func_02197BD4.c,
  ov009_func_0217ECA4.c

Regenerated, untracked: asm/overlays/ov009.s. The worklist was refreshed.

## Checks

- Every shard above: `manifest --verify --force`, then a plain `--verify` that rewrote 0.
  All are EXACT.
- `manifest --check`: clean (9283 shard files).
- ARM9 coverage: 100.0000%.
