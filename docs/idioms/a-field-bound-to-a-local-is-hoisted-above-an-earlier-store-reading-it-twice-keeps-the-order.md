# A field bound to a local is hoisted above an earlier store; reading the struct field in each statement keeps the original order

summary: when the original stores one field (`str r0,[r4,#0x50]`) and only then loads
another (`ldr r0,[r4,#0x48]`), or loads a bound into a scratch register after a
branch (`ldr r2,[r0,#0x58]`) instead of keeping it in a callee-saved one, the source
reads the struct field directly in each statement; binding it to a local (`t = q->f48;`,
`lim = p->f58;`) makes mwcc hoist the load above the store and changes the register pair.

Found in: src/matched/ov/ov094_func_02207DA0.c (0x02207DA0), src/matched/ov/ov094_func_02207EA8.c (0x02207EA8)

02207DA0 begins `q->f50 = 0x80000000; q->f68 = q->f48 - n; if (q->f48 < 0) q->f48 = 0;`.
With `t = q->f48;` the only difference was the prologue order (load of f48 before
the store of the 0x80000000 constant, r1/r0 swapped): 2 instructions moved, function
size unchanged. Writing `q->f68 = q->f48 - n; if (q->f48 < 0)` gave EXACT*.

02207EA8 clamps `a` so that `f54 + a` stays within [0, f58]. With `lim = p->f58;`
the compiler kept `f54` in r4 (extra push/pop, 4 bytes longer); writing
`x = t + a; if (x > p->f58) a -= x - p->f58;` gave the original's r3/r2 pairing
and no callee-saved register.

Other spellings tried on 02207EA8 (all the same wrong code): `t + a` written inline
twice, `t += a`. Only removing the local for the bound changed it.
