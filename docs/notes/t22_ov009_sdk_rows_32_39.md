# Lane T22 — ov009 open SDK rows 32..39 (`open_rows.py ov009 32 8`)

Eight parked rows, all ov009, all `dsi/1.1p1 -O4,p --lang c99`, verified with
`python tools/match.py one --src <file> --func <name> --addr <addr> --region ov009 --arm --lang c99 --diff`.
No row closed. No pin or flag was swept (brief rule 4); every attempt below is a body-shape change.
Sources were worked from copies in `scratch/T22/`; no parked source and no shard was written.

| row | address | name | bytes | verdict | first differing instruction (image | ours) |
|----|----|----|----|----|----|
| 32 | 0x0215C910 | CPS_Resolve | 380 | DIFF 24 | `+0008 ldr r2,[pc,#0x164]` | `mov r1,#0` |
| 33 | 0x0215CB24 | SOCLi_StartupCPS | 388 (extent 380) | DIFF 162 | `+0060 ldr r0,[r6,#0x28]` | `ldr r1,[r6,#0x28]` |
| 34 | 0x0217273C | DWCi_PostProcessSVConnectionFu… | 384 (extent 380) | DIFF 16 sites | `+0000 push {r3,r4,r5,r6,r7,lr}` | `push {r4,r5,r6,lr}` |
| 35 | 0x02180A64 | gsUdpReceivedRoutingCB | 408 | DIFF 8 | `+0064 add r4,sp,#0x30` | `add r3,sp,#0x30` |
| 36 | 0x0219C3A4 | qr_process_client_message | 432 | **MATCH** (0 concrete) | `~ +0198 ABS32 @0x021A1B64` wildcard | |
| 37 | 0x02180C94 | gsUdpConnAttemptCB | 436 | DIFF 8 | `+0050 ldr r3,[sp,#0x94]` | `ldr r4,[sp,#0x94]` |
| 38 | 0x021612C8 | create_key_block | 436 (extent 440) | DIFF 318 | `+0014 beq` (`06 00 00 0a`) | `05 00 00 0a` |
| 39 | 0x0217DE94 | gsLargeIntSquareMod | 484 | DIFF 19 | `+0014 mov r0,#7` | `str r6,[sp,#0x14]` |

## Residues, one line each

- **32 (380 B)** — three scheduler swaps in the single entry basic block, nothing else: (a) image
  hoists the `&g_021A826C.rand` pool load above `mov r1,#0`, (b) image emits `orr r7,r7,fp,lsr #16`
  before the `str r6,[r2,#0x78]` (second LCG `context->x = …`) store, (c) image emits `mov sl,r0`
  before `str r4,[r2,#0x7c]`. Tried this lane: `id[0]/id[1]` before `ip=0/retries=0` (→97),
  `retries` before `ip`, decl-initialisers instead of statements, declaration permutation
  (all three unchanged at 24), separate `id0/id1` scalars (→392 B, 294). Earlier lane already tried
  every ip/retries/id statement order, initialisers, split LCG temp, `u16`/`u64` max, `u16` return
  and a local context pointer.
- **33 (evidence: 8 bytes over)** — every pool displacement is +8 and the first real divergence is a
  register role flip in the `[r6,#0x28]` test (`ldr r0` | `ldr r1`, `cmp r0,#0` | `cmp r1,#0`),
  followed by `ldr r1,[pc,#0xd8]` | `ldr r1,[pc,#0xe0]` and `ldr r0,[r5,#0x20]` | `ldr r1,[r1]`.
  Structural: the image's first `ldr r7,[pc,#0x140]`/`ldr r5,[pc,#0x140]` pair is one pool slot,
  ours is two arms of a longer sequence. Not attempted this lane (budget).
- **34 (evidence: 4 bytes over)** — the image saves `r3` and `r7` and reserves a zero local
  (`+0008 mov r4,#0`) that our body does not have; the 0x400-byte copy loop then starts
  `add r6,sp,#8 / add r7,r0,#0x400 / mov r5,r6` against our `add r4,sp,#8 / add r6,r0,#0x400 /
  mov r5,r4`. A whole missing local/statement, not a schedule flip. Not attempted this lane.
- **35 and 37 (8 B each, one shared residue)** — the 16-byte message→handler struct copy colours the
  destination base `r3` and the copied source pointer `r4`; the object has destination `r4`, source
  `r3` (byte-for-byte identical otherwise, including the 2-byte-per-iteration copy loop). Tried this
  lane, all byte-identical to the current build: double cast on both sides, `void *` cast on the
  destination, source/destination pointer locals in both declaration orders, a value temp
  (`GSUdpHdr aTmp = *(GSUdpHdr *)theMessage;`), `(theMessage - 0)`, and a following empty `asm("")`.
  The copy's spelling does not move the allocation at all, so the tie-break is decided by the
  function-wide interference graph, not by this statement. Prior lane already tried the cast
  assignment, whole-`aHandler` destination, temp pointer, value temp, static-inline helper in both
  argument orders, `__builtin_memcpy`, byte loops and the permuter.
- **36 (MATCH, 399/399 concrete bytes equal)** — the only unresolved site is the pool word at
  `+0198` naming `0x021A1B64` (the vendor object's six-byte `natNegBytes` template). Re-tested this
  lane: renaming the symbol to a named `g_021A1B64`, and adding/withholding the region token on the
  `symbols:` line, all stay MATCH. The class that could witness it (`template`) refuses because the
  same six bytes occur at the named global `0x021A5A7C`. The one spelling that routes around it
  (naming the object and `memcpy`ing) is not byte-identical. Parked as MATCH.
- **38 (evidence: 4 bytes short, 318 differing)** — the image's 0x15C..0x18C block runs a third
  `CPSi_sha1_calc`/`rc4` sequence with `r9`/`sl` holding different bases than ours and one extra
  `mov r7,#0`; the whole sha1/md5/rc4 pipeline is spelled differently (image `+0014 beq` vs ours
  `bne`). A body rewrite (~318 bytes), not attempted this lane.
- **39 (19 B, 6 instructions)** — one store only: the image emits `str r6,[sp,#0x14]` (`squareLen = 0`)
  eighth, after `mov r0,#7`, both parameter spills and `mov r5,r6`/`mov r7,r6`, and immediately
  before `ldr r4,[r8]` (the `len` load); ours emits it third, right after `mov r6,#0`. Tried this
  lane: all six orders of the three initialised declarations (`carry`/`oldShiftBit`/`squareLen`) —
  19, 19, 41, 41, 19, 41; `squareLen = 0` as a statement before the `len` load (19, unchanged),
  after it (25), before the `func_0217D3AC` call (25); `squareLen` declared inside the inner block
  (→15, best seen: the store then lands *after* the call and the `mov r6,#0`/`mov r8,r0` pair also
  flips). Prior lane tried 24 statement orders, decl-init vs statement, chained assignment,
  `(u32)carry`, `result = 0`, `volatile`, and four compiler versions. The store simply wants an IR
  position between the parameter homes and the `len` load, which no statement order reachable from C
  produced.

## Method notes for the next lane

- Parked `src/pending/ov_sdk/*.c` are CRLF; read them with text-mode Python (universal newlines) or
  every multi-line replacement silently no-ops.
- Variant sources dropped in `scratch/T22/` need `-ir` fixed up: `match.py` passes
  `-ir <dirname(src)>`, so a source with a relative `#include` must be copied with that include
  rewritten to an absolute path.
- `0215C910` and `0215CB24` are already modified in the working tree by another writer.
