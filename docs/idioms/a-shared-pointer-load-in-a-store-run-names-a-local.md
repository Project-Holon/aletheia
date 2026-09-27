# A shared pointer load in a store run names a local

summary: when each store re-reads a global pointer (so the same `ldr` repeats
before every `str`), the one place two stores share a single load is the one
place the source bound that pointer to a local for just those stores.

Found in: `src/matched/func_021689BC.c` (0x021689BC) and
`src/matched/func_0216CC28.c` (0x0216CC28)

The DWC field-fillers write every field as a fresh expression, e.g.
`*(int *)(*(char **)(g_021AA860 + 0xc) + 4) = a1;`, because the real source has
no single local holding the block.  This compiler therefore emits a reload
before every store:

```
ldr r0, [r7, #0xc]
str r4, [r0, #8]
ldr r0, [r7, #0xc]
str r4, [r0, #0xc]
```

The tell is a **gap** in that rhythm: two (or three) consecutive stores fed by
one load, e.g.

```
ldr r0, [r7, #0xc]
str r4, [r0, #0xc]
str r4, [r0, #0x10]
str r5, [r0, #0x14]
ldr r0, [r7, #0xc]
str r3, [r0, #0x18]
```

The original source bound the pointer to a local for that run, then went back to
the fresh expression.  Reproduce it by introducing a local scoped to exactly
those stores:

```c
char *q = *(char **)(g_021AA860 + 0xc);
*(int *)(q + 0xc) = 0;
*(int *)(q + 0x10) = 0;
*(int *)(q + 0x14) = n;
```

Writing all three through the global expression instead costs one extra `ldr`
(two instructions / eight bytes for a pair), which is a `SIZE` diff, while
binding a local over the *whole* function instead **removes** every reload and
is far more wrong.  func_0216CC28 is the same shape with a getter: the
`+0x5f0`/`+0x5f4` pair is the single shared load in an otherwise per-store
`bl func_02175F3C` run.
