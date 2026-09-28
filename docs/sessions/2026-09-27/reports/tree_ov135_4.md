# tree_ov135_4 (ov135, plus four ov114 seeds)

## Seeds (layout/function_starts.txt, listings ov135 and ov114 regenerated)

- ov135 0x021FAC84 (Thumb, `return -1`): pointer word 0x021FAC85 at ov135 0x02203C48, the head of the worldtrade_enter proc table. Matched as EXACT\* (2 bytes of padding). func_021FAC50 is now plain EXACT.
- ov114 0x021B97F4, 0x021B99F0, 0x021B99F4 and 0x021B9A14 (Thumb leaves, checked as real code): each is witnessed by a bl in ov135 func_022010BC. func_021B99DC stays EXACT\*.
- Shards verified twice, the second pass rewrote nothing: pkt_021FAC84, pkt_021FAC50 and ov114 pkt_021B9500.
- 022010BC is still MATCH. The only blocker left is ARM9 0x0200FB4C, and its header now says so.

ovstats lines (code, matched, funcs, matched funcs):
- Before: ov135 50490/35256/526/302; ov114 75076/1544/472/52.
- After the seeds: ov135 50496/35256/527/303; ov114 75132/1500/476/52. The ov114 figure dropped by 44 bytes because 021B99DC lost the data run it had swallowed.
- End of the lane: ov135 50496/30994/527/337; ov114 75132/984/476/52. The byte drop comes from commit 1b4bb91a, which now counts instruction bytes only. It is not a regression.

## Prototype fixes (bytes identical, shards re-verified twice)

- 021FCF28: now `(int y)`. The callee ignores r0, but the caller really passes it.
- 021FDD00: now `(void *p)`. Its header status was also corrected to EXACT\*.
- 0220052C: now returns `int`. It tail-calls 02035C08, which returns int.
- 022026BC: now `u32 (void *mon)`. It passes the pointer through to 020185F4.
- 021FC8A8: now `u16`. The caller stores the result without narrowing.
- The same pass also fixed:
  - 021FC008: returns int from 021F88D8.
  - 021F4FF4: now takes u32 parameters. The caller declarations in 021FE9DC and 021FEAE0 were aligned to match.
  - 021F7F80: now `u16`.
  - 02202608: now `void *(u32 heap)`.

## Roots

All twelve roots were matched, 36 new files in total. The eleven roots filed EXACT are 021FB800, 021F601C, 021F61D4, 021FA15C, 021F57EC, 021F5CFC, 021F8358, 021FB3D8, 021F4580, 021FEC00 and 02200ED8. The callees filed with them are 021F4E30, 021F4E64, 021F6B40, 021F6BC4, 021F6474, 021F6D14, 021F88D8, 021F6BA4, 021F6C48, 021F6CDC, 021F5CA4, 021F5F60, 021F5A7C, 021F5B8C, 021F5E44, 021FB26C, 021F4864, 021F49A8, 021F5074, 021F489C, 022029F8, 02202770, 021F99F0 and 021FAC84.

Each one is src/matched/ov/ov135_func_X.c with layout/matched/ov135/pkt_X.json, verified twice. What closed them:
- Unsigned switch.
- Declaration order.
- Inverted conditions.
- The SDK inline window helpers.
- The ov114_id and ov067_id overlay-id symbols.

Pending:
- 021F8554: MATCH. It is blocked on the ARM9 getters 0x0200960C and 0x02009628, which the listing prints as .word data.
- 021F8BE8 (root): DIFF by one unthreaded hop. The permuter ran once with seed 11601 and did not help. Notes are in docs/notes/pkt_021F8BE8.c.txt.
- 021FF384: not attempted.

## Integrator

- Request ARM9 seeds 0x0200960C and 0x02009628.
- ARM9 prototype mismatches:
  - 0201F878 is called with 5 arguments.
  - 02031324 and 0203159C are used for their return values but declared void.
  - 020185F4 is declared void(void).
- 021F9CDC declares tbl_02203324 as `u8 *const[]`, but it is an int table.

Next roots: 022002A0, 021FBA84, 021F46A8, 021FAEE0, 021FFDA8, 021FA9C8, 021FD3CC, 021FC06C, 021F73DC and 021FC3E0.
