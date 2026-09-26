# A live `adc rd, zero, #0` after `adds` is the high word of a 64-bit add, not a 32-bit carry test

summary: `adds rA, rA, rB` / `adc rD, rz, #0` (with `rz` a hoisted zero) is
produced by taking `(u32)(((u64)x + y) >> 32)`, i.e. the carry word of a 64-bit
addition. The 32-bit overflow test `(x + y) < x` does **not** produce it.

Found in: src/pending/ov114_func_021CDB9C.c (0x021CDB9C, near miss)

The tempting reading of

```
adds r5, r5, r0
adc  r0, lr, #0      ; lr was set to 0 once before the loop
```

is "unsigned overflow of `x + borrow`, i.e. `borrow = (z < x)`". That is wrong
for this front end: `-O4,p` lowers `(x + c) < x` to a compare and select, never
to a carry capture. A controlled compile of

```c
u32 test(u32 x, u32 c) { return (x + c) < x; }
```

gives

```
add  r1, r0, r1
cmp  r0, r1
movhi r0, #1
movls r0, #0
```

whereas

```c
u32 test(u32 x, u32 c) { u64 r = (u64)x + (u64)c; return (u32)(r >> 32); }
```

gives exactly the frame in question:

```
mov  r2, #0
adds r0, r0, r1
adc  r0, r2, #0
```

When one operand is already 32-bit (so its high word is the constant zero),
the zero is hoisted out of a loop into a free register (`lr` here), which is
why the `adc` reads a register the function otherwise never uses. So a function
with `adds`/`adc zero` in a loop is doing 64-bit addition whose high half is
kept; spell the source as a `u64` temporary and take `>> 32`, not as a
comparison.

This is the sibling of
[`random-below-n-is-a-64-bit-multiply-high.md`](random-below-n-is-a-64-bit-multiply-high.md)
and
[`consecutive-ll-udiv-calls-are-one-chained-64-bit-expression.md`](consecutive-ll-udiv-calls-are-one-chained-64-bit-expression.md):
the tell is a helper/high-word the C never names.
