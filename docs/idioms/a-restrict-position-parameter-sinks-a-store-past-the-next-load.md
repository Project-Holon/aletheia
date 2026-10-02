# A restrict position parameter sinks a store past the next load

summary: four stores `out->a = p[2] - K; out->b = p[2] + K; out->c = p[0] - J;
out->d = p[0] + J;` compile in source order with `p[2]` reloaded after the
first store, because `out` may alias `p`. When the original loads `p[2]` once,
stores `out->b` first, then loads `p[0]` and only then stores `out->a` (held
in a callee-saved register, so the prologue is `push {r3, r4}`), qualify the
source parameter with `__restrict`. Locals, struct copies and reordered
statements do not reproduce this order; the qualifier alone does. Use
`__restrict`, not `restrict`, so the file also compiles without `--lang c99`.

Found in: `src/matched/ov/ov021_func_0218C9C4.c` (0x0218C9C4, ov021)

```
ldr  r3, [r1, #8]
subs r4, r3, r2
adds r2, r3, r2
str  r2, [r0, #4]
ldr  r2, [r1]
...
str  r4, [r0]
```

Related: `a-restrict-table-parameter-hoists-a-load-above-a-store-only-at-a-different-offset.md`.
