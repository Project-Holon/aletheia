# A `const` source pointer moves a field load up next to the call that precedes it

summary: when the only diff is scheduling (the original loads a field right after a `bl`, before copying r0 into the next argument register, and ours loads it after the stack-argument setup), declare the read-only record parameter `const T *`; the loads then schedule like the original with no other change.

Found in: `src/matched/ov/ov010_func_021613CC.c` (0x021613CC), `src/matched/ov/ov010_func_02161554.c` (0x02161554)

Both functions read a request record (`src`) and hand its fields to calls whose
argument is another call's result. The original reads

```
bl   func_0202138C
ldr  r2, [r4, #0x3c]     /* the record field, straight after the call */
adds r3, r0, #0          /* then the result moves into r3 */
movs r0, #4
lsls r2, r2, #0x18
str  r0, [sp]
```

and without `const` we emitted `adds r3, r0, #0; movs r0, #4; str r0, [sp];
ldr r2, [r4, #0x3c]`, same size, 24 and 14 concrete bytes wrong. Rewriting the
arguments as locals, a `u8` parameter, a `& 0xFF`, or a K&R declaration changed
nothing. `const Src *src` on the parameter made both EXACT. The tell is a diff
that is a pure permutation of the same instructions around a call.

Related: when the callee's result is returned (`return f(...)`), a later store
through the parameter must pick `r1` rather than `r0` because `r0` is live; that
was the second half of 0x021613CC.
