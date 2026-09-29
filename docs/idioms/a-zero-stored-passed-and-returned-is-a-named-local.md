# A zero that is stored, passed and returned is one named local assigned in memory order

summary: when the original keeps a `movs rN, #0` live across a call and reuses it as the return value, write `z = 0;` once (between the field stores, in memory order) and use `z` for the stores, the call arguments and `return z`; literals fold and the register is never kept.

Found in: `src/matched/ov/ov012_func_021746A8.c`, `src/matched/ov/ov012_func_021746FC.c`

Both functions build a three-word struct on the stack, call a six-argument
callee with `0, 0` as the last two stack arguments, bump a byte counter and
return 0. The original holds the zero in a callee-saved register (r7 / r4) from
before the struct stores to the final `adds r0, rN, #0` return.

Spelling `s.b = 0; f(..., 0, 0); return 0;` folds every zero and produces a
different push list and no live register. Spelling

```c
    z = 0;
    s.b = z;
    *out = f(a, c, K, &s, z, z);
    ...
    return z;
```

reproduces it, but only when `z = 0` sits between `s.a` and `s.c` (the order of
the stores in memory). Putting it first or last differs by a two-instruction
swap of `movs rN, #0` and the `lsls` of the previous constant.

The guard is `if (*cnt == 0) { body } else { return 1; }` followed by the counter
increment, not an early `return 1`: the early-return spelling moves the
`return 1` epilogue in front of the body.
