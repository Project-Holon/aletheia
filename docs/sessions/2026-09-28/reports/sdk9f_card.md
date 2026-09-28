# sdk9f_card report (libcard, arm9 SDK rows, final lane)

All work comes from `tools/sdkobj.py`, `match.py one/show`, the permuter, and the Rom line-table
dump already in `scratchpad/sdk9w3_card/lines.txt`. No `.c`/`.h` under `sdk/` was opened. No git
writes. No asm statements and no asm mode were used.

## Result

| address | symbol | bytes | verdict |
|---|---|---|---|
| 0x0207608C | CARDi_InitResourceLock (card_common.o) | 40 | EXACT (manifest --verify --force) |
| 0x02076E4C | CARDi_ReadRomWithCPU (card_rom.o) | 284 | DIFF, 280/284 (unchanged) |
| 0x02076540 | CARDi_RequestStreamCommandCore (card_backup.o, static) | 408 | DIFF, 408/408, 21 bytes (register permutation only, unchanged) |

## Files and shards written

- `src/matched/arm9_sdk/func_0207608C.c` (new, written from the object). Status EXACT is copied from
  `manifest --verify --force --shard arm9/pkt_0207608C`. The first pass wrote the shard (1 rewritten).
  The second and third passes rewrote 0.
- `layout/matched/arm9/pkt_0207608C.json` (new shard, one entry).
- `src/pending/arm9_sdk/func_0207608C.c`: deleted, unread. It is superseded by the matched file.
- `src/pending/arm9_sdk/func_02076E4C.c` and `src/pending/arm9_sdk/CARDi_RequestStreamCommandCore.c`
  (this session's drafts): only notes lines were added, and the bodies are unchanged. The DIFF status
  comes from `match.py one`.

## 0x0207608C CARDi_InitResourceLock

The lever is a cast on the base, `CARDiCommon *p = (CARDiCommon *)&cardi_common;`. That puts p in r2
and loads the zero into r0 first, which matches the image. It also agrees with the DWARF, which has
one local `p`. With plain `&cardi_common`, `*const p`, a separate assignment, or direct
`cardi_common.` accesses, the result is 18 bytes out, the same swap the first pass reported. The body
is `lock_owner = -3; lock_ref = 0; lock_target = NONE;` followed by an inline `OS_InitThreadQueue`
(the object has no call; stores go tail then head). The struct layout matches the sibling
`func_02075F4C.c` and the DWARF CARDiCommon.

## 0x02076E4C CARDi_ReadRomWithCPU (near miss, 4 bytes short)

None of the following moved the `cmp r8,#0x200`, which the image has as `mov r0,r7; cmp r8,r0`:

- n initialised from a page-size variable: a function-scope `u32 page`, a block `const`, `sizeof(CARDi_cache_buf)`, or a `const pageSize` next to cacheBuffer.
- `n` assigned separately, assigned in both arms, or assigned only in the else arm.
- casts through `unsigned int`, `(u32)(int)`, `(u32)(void *)` and `(u8 *)`.
- `(0, n)`, `n + 0`, a ternary on the compare, and the whole condition as a ternary.
- `n > length`.
- `MATH_ROUNDDOWN(offset, n)` and `MIN(length, n - mod)`.
- the condition split into an else-if chain (much worse), and the arm statements reordered.

A function-scope `static u32 page_size` does produce `cmp r8,r7`, but it adds a load and is not
evidenced.

Diagnostics:

- Under `#pragma opt_propagation off`, adding any one of opt_lifetimes, opt_common_subs,
  opt_loop_invariants, opt_strength_reduction, opt_dead_*, or opt_unroll_loops still leaves 10 bytes.
  The only remaining difference is the poll loop, which rotates by one register (image word r3, ctrl r2, data r1).
- In that mode, splitting `word++` out of the store gets to 7 bytes.

This fits the third pass's reading: the missing copy is n's own vreg (line 372, DWARF r0), and
allocating it first takes r0.

The permuter (seed 14001, 400 anneal) found nothing value-preserving. Its best rewrite reads the
global cached_page instead of the local, which is rejected.

## 0x02076540 CARDi_RequestStreamCommandCore (near miss, 21 bytes)

New finding: how the four callee-saved registers r4 to r7 get assigned. I ran the cross product of
the 4 declaration orders and const on each local (256 compiles), plus a head statement-order sweep
(120 orders of the four assignments and OSi_ReferSymbol).

- Non-const locals take r4 upward in declaration order. The hoisted buffer address comes after them.
- A `const req_type` goes last, after the buffer. `const` on req_mode or retry_count changes nothing.
- The image order is buf, req_type, req_mode, size, so the buffer comes first.
- The closest result is size declared first, then non-const type, mode and retry (12 bytes out,
  req_type r5 and req_mode r6 correct, only size and buf swapped). That contradicts the DWARF
  declaration order (req_type, req_mode, retry_count, size, len), so it was not adopted.

Also tried, with no change to the permutation:

- size assigned as a statement, before or after OSi_ReferSymbol, or in an explicit else.
- size as a const ternary initialiser (79 bytes out).
- a `u8 *buf` local, const or not, at each position (58 to 61 bytes out).
- a switch on req_type.
- a ternary do-while condition, and `!= 0`.
- every order of the tail `src/dst/len` updates, the cancel-block order, and the RECV arm order.
- the MIN spelling (gt, le, ge, non-const len).

The permuter (seeds 14002 and 14003, 300 each, from the 12-byte variant) did not improve on 12.

## Catalog / DWARF names

No disagreements. CARDi_InitResourceLock's DWARF gives `p` as r0. In the image p is r2, so this
DWARF location is not reliable for register-level evidence.

## asm bodies

None.

## Next pass

- 0x02076540: find a spelling that makes the hoisted buffer address the first allocated callee-saved
  vreg without reordering the declarations. The rule measured above (non-const declarations in order,
  then hoisted temporaries, then const req_type) is the starting point. Nothing written as a local
  worked, and the Debug build has no extra local.
- 0x02076E4C: this needs a non-asm construct that keeps n's vreg from being copy-propagated at the
  compare only. Every source spelling tried folds the compare. This row probably stays pending unless
  the coordinator accepts pragma-level evidence.
