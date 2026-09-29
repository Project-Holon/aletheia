# A byte range guard with a decrement is tested inline, not through a u8 local

summary: `cmp r0,#0; beq X; subs r0,#1; lsls/lsrs #24; cmp r1,#0x18; blo` (the `subs` after the zero test) is `if (v == 0 || (u8)(v - 1) >= 0x18) t = 0x1f; else t = v - 1;`; a `u8 t = v - 1;` local ahead of the test hoists the `subs` above the zero compare.

Found in: `src/matched/ov/ov093_func_021E8070.c`, `ov093_func_021E80C0.c`,
`ov093_func_021E8104.c`.

Tried: `t = v - 1; if (v == 0 || t >= 0x18) t = 0x1f;` (subs hoisted, +2 bytes);
nested `if (v == 0) ... else { t = v - 1; if (t >= 0x18) ... }` (extra `b`);
`t = 0x1f; if (v != 0) {...}` (result lands in r0 and needs a copy).

Also in these three: the result is left in r1 because the next `bl` takes it as
its second argument (the callee reads only r0, but the caller's live r1 is a
passed argument, so the extern carries two parameters).
