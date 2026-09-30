# An argument equal to a local's known constant names the local, not the literal

summary: when the image passes a callee-saved local to a call on a path where that local's value is provably a specific constant, writing the literal at the call site (`f(1)`) is a byte diff from writing the local (`f(x)`); the register that held the local is still the argument source (`mov r0, rX` vs `mov r0, #1`) even though both compute the same value.

Found in: src/pending/ov_sdk/ov009_func_02174FE8.c (0x02174FE8, DWCi_NNCompletedCallback, ov009, dsi/1.1p1)

At 0x02174FE8+0x0198 the image is

```
cmp  r4, #1
bne  ...
mov  r0, r4          <- r4 is gt2Result, known to be 1 on this arm
bl   DWCi_HandleGT2Error
```

The transcribed C had `if (gt2Result == 1) { DWCi_HandleGT2Error(1); return; }`,
which compiled to `mov r0, #1` and cost two concrete bytes at one site. The
source the vendor wrote passed the local: `DWCi_HandleGT2Error(gt2Result)`.
Because the guard proved `gt2Result == 1`, the optimiser did not fold the
argument to the immediate and kept the live register as the source.

The lever is narrow but general and it is easy to miss when a whole function is
"one register swap": an immediate-vs-register mismatch on a comparison-guarded
call site is *not* part of the surrounding register rotation, it is a source
bug. Grep the two-column diff for a line where the ORIGINAL operand is a
register and the COMPILED one is a `#immediate` (or the reverse) on a call's
argument set-up; before attributing it to allocation, check whether that
register holds a value the immediately preceding compare already pinned.

The same tell applies to any `if (x == K) f(K);` shape: prefer `f(x)` when
the image loads the local rather than rematerialising `K`. It only moves bytes
when the constant is small enough to be a `mov #imm`; the fix is exact and
independent of every declaration-order and colouring lever applied around it.
