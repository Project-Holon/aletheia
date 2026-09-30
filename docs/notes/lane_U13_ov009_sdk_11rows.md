# Lane U13 — ov009 SDK slice (11 rows)

Slice `scratch/a2/slices/u13.txt`. All 11 rows were parked at DIFF/MATCH on entry; two closed.

## Filed

| address | function | bytes | verdict | shard |
|---|---|---|---|---|
| 0x02180A64 | gsUdpReceivedRoutingCB (gsudpengine.o) | 408 | EXACT | ov009/pkt_ov009_02180A64 |
| 0x02180C94 | gsUdpConnAttemptCB (gsudpengine.o) | 436 | EXACT | ov009/pkt_ov009_02180C94 |

Both had the identical 8-byte residue (lane w2_o2): the 16-byte message copy
coloured destination r3 / source r4 where the object has destination r4 /
source r3. The close is `memcpy(&dst, src, sizeof(dst))` **with the house
`arm9_sdk/libc/string.h` prototype** — declaring memcpy in the .c itself (or
omitting the include) emits a real call, which is why w2_o2 recorded "memcpy (a
real call)". Identical close to `ov009_func_0217ECA4` (sendto). This is the same
shape as the idiom about mwcc treating memcpy/strcpy as intrinsics only from a
header named string.h.

## Parked, with the residue confirmed or narrowed

- **0x0217DE94 gsLargeIntSquareMod** (484 == 484, 19 bytes): the only difference
  is the *scheduling* of `str r6,[sp,#0x14]` (squareLen = 0). Image order:
  carry=0, param save, call arg, mod/dest spills, carry-low, oldShiftBit=0,
  squareLen=0, len load. Ours hoists squareLen=0 five slots, to just after
  `mov r6,#0`. **Exhausted here**: all 24 permutations of
  {carry, oldShiftBit, result, squareLen} as declaration initialisers, the 6
  orderings as bare statements, all 4 positions of `int len = lint->mLength;`
  as a declaration initialiser, plus 11 further declaration-shape variants —
  **every one lands on exactly the same 9 instructions and 19 bytes**. Also
  `--cc ../2.0/base` 492, `../2.0/sp1p2` 492, `../1.2/sp3` 508. Not an ordering
  or a build difference: the front end schedules the store; no spelling found.
  Worth knowing for 0x021894D8/0x0217D... neighbours: this is the scheduler, not
  the allocator.

- **0x021674BC WcmWmcbConnect** (552 == 552, 12 bytes): three empty `return;`
  arms reached straight from a jump table — image emits a fresh
  `pop {r4,r5,r6,pc}` in the table slot (+0088 state-6 arm, +00B8 phase default,
  +00C8 phase 11), dsi/1.1p1 emits `b <shared pop>` there. Confirmed with 8
  further spellings (phase `default:` first, `case 11:`/`default:` split,
  `case 6:` first in the state switch, `case 0x1a` before `case 6`, braces
  around the arm, same-line spellings, `case 6:` moved after `default:`) — all
  stay at exactly 12 bytes. Not case order and not grouping.

- **0x02189780 gpiRecvToBuffer** (520 vs 524): unchanged. Covered by
  `docs/idioms/a-varargs-counter-increment-is-scheduled-before-a-later-format-pointer.md`
  and additionally **capped at MATCH by evidence** (g_021A4568 / g_021A458C
  have no witness outside 02189780..02189988). Not fileable even if the
  scheduling were cracked.

- **0x0217CF5C gsCryptRSAVerifySignedHash** (564 vs 556, +8): instruction
  sequence agrees from +0000 to +007C; the two residues are exactly as the
  parked note says — (a) the image keeps `sigLen` in r2 from +007C to the memcpy
  at +00B8 (`lsr r8, r2,#2` reuses it) where this spelling reloads
  `ldr r2,[sp,#0x140]` at +00A8, and (b) the image keeps `i+1` as its own value
  (`add r0, r1, #0x22`) where this spelling folds to `i+0x23`. Every other
  mismatch in the 344 is the pool shift from those 8 bytes. **Still capped
  below EXACT**: the two initialiser-template absolutes (@13305 0x021A19E8,
  @13307 0x021A19D8) have no overlay attestation class, so the ceiling is MATCH*
  and it cannot be filed under the current rules. Do not spend budget on it.

- **0x0219C3A4 qr_process_client_message** (432 == 432): already **MATCH** —
  every one of the 399 concrete bytes equal; the single wildcarded site is the
  ABS32 at +0198 (@13818 -> 0x021A1B64), which has no class witness (its only
  image word is this function's own pool word). Re-checked the one escape route
  the parked note names: `memcpy(natNegBytes, g_021A1B64, 6)` against an extern
  at 0x021A1B64 **with the string.h intrinsic** — it does inline (so the note's
  "a real call" reading is superseded) but it still diffs **75 concrete bytes**,
  exactly the count the note recorded, and the site stays `[wildcard]`. Not a
  path forward. No shard written (MATCH is not in MATCHED_STATUS).

- **0x021612C8 create_key_block** (436 vs 440): the f32==4/5 size selection is
  branch-first in the image (`moveq`/`streq` predicated block) and
  branch-then-predicated here, plus the len/p register swap (image len=sb,
  p=fp). Deep reshape; unchanged.

- **0x021573C4 CPS_Startup** (536 == 536, 188 bytes): first divergence +0008
  `mov r4, r0` | `mov r5, r0`; whole-function colouring. Unchanged. Note the two
  ABS32 sites at +01D8/+01E0 (func_021573B8 / func_021573BC) are unresolved only
  for want of a region token on their `symbols:` line in the parked source; add
  `ov009` there before any future attempt, but the colouring residue dominates.

- **0x02160A7C rcv_certificate** (592 vs 544, +48): first divergence +0004
  `push {r3,r4,r5,r6,r7,r8,sb,sl,fp,lr}` | `push {r4,...,lr}`. Body shape, not a
  boundary problem (vendor object is byte-identical to the image). Unchanged;
  see docs/notes/ov009_rcv_certificate.md.

- **0x0217273C DWCi_PostProcessSVConnectionFullmesh** (384 vs 380): the image
  keeps a zero in r4 for the whole function (`mov r4,#0` at +0008, consumed by
  `strb r4,[r0,#0x620]` and both `movne r0, r4` error returns) and pushes
  r3-r7; this draft folds the zeros to immediates. Tried the
  declaration-initialiser idiom (`int result = 0;` as a declaration, in three
  positions) — identical 177 bytes, no hoist. Need a shape that forces the
  result local into a callee-saved register across the first call.
