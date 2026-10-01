# An unsigned switch keeps negative sentinels out of the low case table

summary: switch ((u32)r) keeps cases 0..4 in their own Thumb table and tests case -2 after its range guard; switch (r) merges the signed -2..4 range, and unsigned ordering also moves a lone positive case ahead of -2/-1 in a short compare chain.

Found in: `src/matched/ov/ov135_func_021FB164.c`, `src/matched/ov/ov135_func_021FB964.c`, and `src/matched/ov/ov135_func_021FB674.c`.

The first two handlers switch on a call result with shared cases 0..4 and a separate case -2. The original emits `cmp r5,#4; bhi` followed by a five-entry table. The out-of-range path tests -2, branches to that arm, then branches to the exit for other values.

```c
int r = func_021F9CDC(p, p + 0x60);
switch ((u32)r) {
case 0: case 1: case 2: case 3: case 4:
    /* ordinary selection */
    break;
case -2:
    /* cancellation */
    break;
}
```

With the signed switch value, dsi/1.1p1 -O4,p builds a seven-entry -2..4 table and compiles 124 bytes against the original 128. Moving -2 into an `if` in the default builds the five-entry table but places its comparison after the ordinary arm, compiling 126 bytes. Casting the original switch value to u32 produces EXACT at both addresses without changing their case bodies.

In func_021FB674, cases -2, 10 and -1 plus default initially compile to the right 144-byte size but test -2/-1 before 10 and retain -2 in r6 across the cancellation calls. The same unsigned cast tests 10 first, then -2/-1, and derives the stored -2 from a live 20 with subtract, matching EXACT. Keep source arm order unchanged: the cast changes dispatch ordering and constant reuse while preserving body layout.
