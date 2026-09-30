# An enum local materialises a large complement constant instead of folding it off an adjacent constant

summary: when a function passes a small constant (for example `1`) in one
argument register and `0x7fffffff` in the next, mwccarm folds the large value
as `reg - 0x80000002` off the register that already holds the small constant;
declaring the large bound as an enum *local* (`HighMax hi = HIGH_MAX;`) stops
the fold and emits the image's `mvn rd, #0x80000000`, where a bare enum
constant or a plain `int` local still folds.

Found in: src/pending/ov_sdk/ov009_func_021990A0.c (0x021990A0)

The image sets up `func_0217F7AC(1, 0x7fffffff)` like this:

```
021990BC  mov r0, #1
021990C0  mvn r1, #0x80000000      /* 0x7fffffff as ~0x80000000 */
021990C4  bl  func_0217F7AC
```

With the obvious `func_0217F7AC(1, 0x7fffffff)` under dsi/1.1p1 the backend
notices that r0 already holds `1` and rematerialises the bound from it:

```
mov r0, #1
sub r1, r0, #0x80000002            /* 1 - 0x80000002 == 0x7fffffff */
```

`0x80000002` is encodable (imm8 `0x0a`, rotate 1), so the rewrite is a legal
one-instruction encoding and neither form is shorter; the compiler simply
prefers deriving from the live register. Every arithmetic spelling of the
constant (`(1 << 31) - 1`, `0x80000000u - 1`, `~0x80000000`, `~0u >> 1`,
`INT_MAX`) folds back to the same constant and gets the same `sub`. A bare
enum constant passed straight to the call also folds.

What breaks the fold is the value's *type object* being an enum local, which
mwcc does not propagate (see
an-enum-type-keeps-values-out-of-constant-folding.md):

```c
typedef enum { HIGH_MAX = 0x7fffffff } HighMax;
...
HighMax hi = HIGH_MAX;
g.clientID = func_0217F7AC(1, hi);
```

now emits `mvn r1, #0x80000000` exactly. The residual hazard is ordering: the
enum local's materialisation is scheduled before the low literal's `mov r0, #1`
(`mvn r1; mov r0`), and if the low argument is escalated to an enum local too
the order is restored but the compiler re-derives the bound off the adjacent
`r0 == 1` and the `sub` comes back. The lever is real but does not by itself pin
both instructions; a source shape that gets `mov r0` first *and* keeps the enum
materialisation is still wanted.
