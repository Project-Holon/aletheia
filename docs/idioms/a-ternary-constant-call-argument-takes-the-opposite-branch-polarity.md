# A constant ternary used as a call argument takes the opposite branch polarity and register from the equivalent if/else

summary: `f(cond ? 0 : 1)` emits the two calls with the *inverted* test
(`bne` where the original has `beq`) and colours the surrounding pointer and
result the other way; spelling it as an explicit `if`/`else` with the call in
each arm reproduces the original exactly.

Found in: `src/matched/ov195_func_022053E8.c` (0x022053E8)

The dispatcher passes a boolean to `func_020355D8` that is the negation of a
mask test, twice:

```c
func_0203630C() & 3) != 0 ? 0 : 1
```

Written inline, the whole function is a register-rotated diff: the argument
pointer that the original keeps in `r4` lands in `r5`, the `r = 0` result that
the original keeps in `r5` lands in `r4`, and each ternary's `beq`/`bne` comes
out inverted (64 concrete bytes over a byte-identical 132-byte function):

```
  tst   r0, r1
  bne   .L1          ; original: beq .L1
  ...
.L1:
  movs  r0, #1
  b     .call
```

Repeating the call in both arms of an ordinary `if`/`else` is what the
original C must have been:

```c
if ((func_0203630C() & 3) != 0)
    func_020355D8(0);
else
    func_020355D8(1);
```

With that, the pointer stays in `r4`, the result in `r5`, the test is `beq`,
and the function is byte for byte the image.

This is the mirror of
`docs/idioms/a-ternary-flag-is-materialised-first-a-relational-one-is-folded-into-the-call.md`,
where a ternary is the *fix*. There the ternary is folded into a larger
argument expression; here it is the entire argument, and the front end picks
the polarity of the branch as a function of which arm of the ternary it puts
first. When a ternary argument and the equivalent if/else produce the same
instructions in the opposite polarity, the if/else is the source shape.

What does not move it: declaring `int r` (any spelling of its zero), naming
the argument pointer `p = a`, or writing the two call sites with a local
boolean. The if/else statements are the whole of it.
