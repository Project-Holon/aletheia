# A flag set after the call that consumes its input shares that input's register

summary: `flag = 1; if (*f(t, 1) == 0) flag = 0;` gives the flag its own callee-saved register because `t` is still live at the `bl`; binding the call result first (`p = f(t, 1); flag = 1; if (*p == 0) flag = 0;`) lets the front end hoist the `movs` above the `bl` anyway and colours the flag with `t`'s register.

Found in: `src/matched/ov/ov059_func_021F3CB8.c` (0x021F3CB8),
`src/matched/ov/ov059_func_021F3C6C.c` (0x021F3C6C); the same source order is
what `src/matched/ov/ov059_func_021F3AA0.c` already uses.

The original of both functions reads `adds r0, r4, #0; movs r1, #1; movs r4, #1;
bl func_021897BC; ldr r0, [r0]; cmp r0, #0; bne L; movs r4, #0`. The flag `movs
r4, #1` sits between the argument setup and the `bl`, yet it lands in `r4`, the
register that held the call's first argument. Writing the flag assignment before
the call in the source (`flag = 1;` then `if (*f(t, 1) == 0)`) produced the same
instructions with `t` and `flag` in different registers (one extra callee-saved
register, `push {r4, r5, r6, lr}` instead of `push {r3, r4, r5, lr}`), and no
declaration order or type change (`u16`, `unsigned`, `int` for `t`) fixed it.

Bind the call result to a pointer local first, then assign the flag:

```
p = func_021897BC(t, 1);
flag = 1;
if (*p == 0) {
    flag = 0;
}
```

The scheduler still hoists `movs r4, #1` above the `bl` (the output bytes are the
same), but the interference graph now has `t` dead before `flag` is defined, so
both take `r4`.

Tried and no change: declaration order of `t`/`s`/`flag` (all six permutations),
`flag = *p != 0`, `func_021897BC(t, flag = 1)`, an int-typed `t`.
