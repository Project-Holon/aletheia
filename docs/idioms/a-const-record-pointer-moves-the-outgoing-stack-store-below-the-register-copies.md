# A const record pointer moves the outgoing stack store below the register copies

summary: when a run of identical 5-argument calls differs only in that ours
stores the stack argument (`str rN, [sp]`) before the last register copy
(`adds r2, r5, #0`) in all but the final call, while the original copies first
in every call, declare the pointer the in-between loads read through
(`q[2]` feeding the argument-producing call) `const`. Same family as
`a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md`,
but the instruction that moves is the stack store, not the load.

Found in: src/matched/ov/ov021_func_021B86A4.c (0x021B86A4)

```
original                          plain u32 *q
ldr  r0, [sp, #0x10]   ; row      ldr  r0, [sp, #0x10]
ldr  r3, [sp, #0x30]   ; a5       ldr  r3, [sp, #0x30]
adds r2, r5, #0        ; t        str  r6, [sp]          ; flag = 1
str  r6, [sp]          ; flag     adds r2, r5, #0
bl   func_021B8514                bl   func_021B8514
ldr  r0, [r4, #8]      ; q[2]     ldr  r0, [r4, #8]
```

Each call is `func_021B8514(row, func_021B93D4(q[2]), t, a5, 1)`. The last
of the three calls already matched with `u32 *q` (no `q[2]` load follows
it). `void f(u8 *t, const u32 *q, ...)` with `const u32 *` on the two callee
prototypes that take q makes all three EXACT; `#pragma scheduling off`,
inline wrappers for the call, a named flag local, literal type spellings,
dir locals and `do { } while (0)` blocks were all inert.
