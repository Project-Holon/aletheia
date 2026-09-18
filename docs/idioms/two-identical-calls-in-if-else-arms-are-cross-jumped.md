# Two identical calls in the arms of an if/else are cross-jumped: only the differing argument is set up in each arm

summary: writing the same call in both arms of an `if`/`else` whose only
difference is one constant argument produces one call site with the constant
materialised separately in each arm, not two calls; the equivalent shape that
assigns the constant to a local first materialises the value early and
reallocates registers, and a ternary sends the constant through a different
path again.

Found in: src/matched/func_0202F2AC.c (0x0202F2AC)

The original is a six-argument call whose last argument is a stacked `0` or
`1`:

```
0202F2C0  cmp r0, #1
0202F2C2  bne 0x202f2cc
0202F2C4  ldr r0, [sp, #0x20]      ; the caller's a4
0202F2C6  str r0, [sp]             ; argument 5, written in the arm
0202F2C8  movs r0, #0              ; argument 6
0202F2CA  b 0x202f2d2
0202F2CC  ldr r0, [sp, #0x20]
0202F2CE  str r0, [sp]
0202F2D0  movs r0, #1
0202F2D2  str r0, [sp, #4]
...
0202F2DC  bl #0x202f358            ; one call site
```

That is `if (cond) f(a0, a1, a2, a3, a4, 0); else f(a0, a1, a2, a3, a4, 1);`
after mwcc cross-jumps the two call sequences and keeps the differing
constant in each arm.  Writing the same thing as

```c
    u32 flag;
    if (v == 1) flag = 0; else flag = 1;
    f(a0, a1, a2, a3, a4, flag);
```

gives one arm fewer (the constant is preselected into a callee-saved
register), and the ternary `u32 flag = (v == 1) ? 0 : 1;` materialises the
zero before the call as well.  Both are byte-different over the function's
whole tail, so the duplicated call is the spelling to reach for.
