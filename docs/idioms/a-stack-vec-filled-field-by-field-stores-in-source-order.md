# A stack Vec filled field by field stores in source order, and that order decides who gets the zero register

summary: a `{x, y, z}` local whose original stores run `y, x, z` (or `x, z, y`) is three member assignments written in that store order, never `Vec v = {0, K, 0};` (a rodata copy, +12-20 bytes) nor `= {0,0,0}` plus one member; and when the zero later feeds a stack argument and a field store after several calls, the order of the three assignments also decides whether 0 or another local takes the free callee-saved register.

Found in: `src/matched/ov/ov021_func_021BFB90.c`, `src/matched/ov/ov021_func_021C04C0.c`, `src/matched/ov/ov021_func_021BFE2C.c`

The ov021 map-event state machines build a position on the stack before
passing its address to `func_0216D8C0` / `func_021C7858`:

```
movs r1, #0xa ; lsls r1, #0xc
str  r1, [sp, #0x24]      /* y first */
add  r1, sp, #0x20
str  r7, [sp, #0x20]      /* x, off the zero register */
str  r7, [sp, #0x28]      /* z */
```

- `Vec v = { 0, 0xA000, 0 };` compiles to a copy from a rodata template:
  SIZE, 20 bytes long.
- `Vec v = { 0, 0, 0 }; v.y = 0xA000;` stores through `add r1, sp, #0x20`
  (`str r7, [r1, #4]` ...), 8 bytes long.
- `Vec v; v.y = 0xA000; v.x = 0; v.z = 0;` is EXACT: the stores follow the
  assignment order.

In `func_021BFE2C` the original stores `x, z` off `r7` and then `y` from a
pool word, and keeps that same zero in r7 for a later stack argument and
`q[3] = 0`, with a sibling call result spilled to `[sp, #0x14]`. Writing
`w.x = 0; w.z = 0; w.y = K;` gave that result r7 instead, dropped a stack
slot and shifted every frame offset (157 bytes, SIZE by 4). A named zero
local `z` did not help (copy-propagated), nor did block-scoping the call
results. Writing the members in memory order, `w.x = 0; w.y = K; w.z = 0;`,
was EXACT: the zero went back to r7 and the scheduler still emitted the two
zero stores first.

So try the member order first, before a zero local or declaration shuffles,
whenever a stack vector's stores and a zero register are both in the diff.
