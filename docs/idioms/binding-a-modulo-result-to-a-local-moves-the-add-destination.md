# A modulo result bound to a local moves the add's destination and the early return

summary: In `x = f() % n; return x + min;` the `%` result lands in a local
first, so the compiler keeps `min` in a callee-saved register, emits the
early-return guard as a conditional `popeq`, and returns with a direct
`add r0, r1, r5`; folding it into one expression `return f() % n + min;`
instead branches to a shared epilogue and adds a `mov r0, r5`.

Found in: src/matched/ov009_func_0217F7AC.c (0x0217F7AC)

Util_RandInt:

```c
if (range == 0)
    return min;
r = func_0217F774() % range;
return r + min;
```

The original emits, in this order:

```
subs r4, r1, r5      ; range = max - min
popeq {r3, r4, r5, pc}
bl   longrand
mov  r1, r4
bl   _u32_div_f      ; quotient r0, remainder r1
add  r0, r1, r5      ; remainder + min
pop  {r3, r4, r5, pc}
```

The one-expression spelling gives the same 36-byte size but a different
shape: the guard becomes `beq <epilogue>`, the sum is accumulated into the
callee-saved `min` register (`add r5, r5, r1`), and the return needs an extra
`mov r0, r5` plus a duplicated `pop` (40 bytes).  `%` on the unsigned operands
calls the runtime division entry at 0x0209C2B0, declared `_u32_div_f` in the
`symbols:` block so the runtime class can witness it.
