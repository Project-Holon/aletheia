# Two short-lived pointer loads that cross neither a call nor a join can swap callee-saved and scratch as a front-end allocator tie

summary: when a block loads two pointers from the same base, the first into a
callee-saved register and the second into a scratch, and both die before the
next call, the assignment is a graph-colouring tie rather than a live-range
fact.  Every general source lever (named locals, declaration order, statement
order, inline-vs-local, init-at-declaration, compare polarity, declared widths)
leaves the identical byte count, so the residue is the whole dependent tail and
not the two loads.  Record it; do not keep re-spelling.

Found in: `src/pending/ov_sdk/ov107_func_021F4140.c` (0x021F4140,
MBi_SendFixedBeacon, mb_gameinfo.o, 356 B, 63 B out)

The opening of the image is

```
ldr r3, [pc]        ; sUnlockFunc base
mov r6, r0
ldr r4, [r3, #0x1c] ; cur  -> r4 (callee-saved)
ldr r0, [r3, #0x20] ; data -> r0 (scratch)
add r7, r4, #0x358
add r3, r0, #0x62
cmp r3, r7
```

`cur` dies at the `add`, `data` dies in the else arm before the `MIi_CpuClear16`
call, and neither the branch join nor the call is crossed by either value, so
the allocator is free to put them in either class.  The C that computes
`lastAddr = (unsigned long)sUnlockFunc.cur + 0x358;` then tests
`(unsigned long)sUnlockFunc.data + 0x62 <= lastAddr` compiles to
`cur -> r0`, `data -> r3`, and then every dependent instruction in the 340-byte
tail (all the `bsendBuff` stores, the base loads at +0060/+0064, the `and`/`rsb`
ordering in the else) follows the swapped pair.

The levers measured, each identical in size and mostly in bytes:

* named pointer locals `unsigned char *cur = sUnlockFunc.cur;` /
  `unsigned char *data = sUnlockFunc.data;` used for the block — inert (the
  coalescer rematerialises both);
* a named local for `data + 0x62`, before or after `lastAddr` — inert;
* initialising `lastAddr` at its declaration, or declaring it `unsigned int`
  or `long` — inert;
* writing `cur + 0x358` inline in the condition, or `data + 0x62` inline —
  inert;
* the no-code self-assignment `lastAddr = lastAddr;` — inert.

Two near-misses show where the axis is *not*: assigning the local to the
intermediate value (`lastAddr = (unsigned long)sUnlockFunc.cur;` first, then
`lastAddr + 0x358` in the test) only moves the tie to a different pair
(`data -> r7`, local -> r0, 64 B), and swapping the compare polarity or
operand order measures strictly worse (68-76 B).  This is the same shape as
`a-guard-load-that-folds-into-its-dying-base-register-is-not-a-source-shape.md`
— an allocator tie pinned to a dying pointer load — one size class larger:
there the tie is the two-instruction guard, here it recolours every instruction
that reads either base afterwards.

The practical rule: before spending a wave on the opening block of a function
whose only diff is a two-cycle of loaded pointers and their whole dependent
tail, confirm that neither value crosses a call or a join.  If so, the rest of
the function is downstream of a tie no source spelling moves; write the
residue into the blocker and move on.
