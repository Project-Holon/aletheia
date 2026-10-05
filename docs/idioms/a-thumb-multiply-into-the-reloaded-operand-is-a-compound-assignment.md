# A Thumb multiply whose destination is the reloaded operand is a compound assignment

summary: under dsi/1.1p1 -O4,p Thumb, `x = (w * (b - a)) / 10 + a` (either operand order)
puts the difference in the register of `a` and multiplies into it. When the original
puts the difference in the register of `b` and multiplies into the reloaded `w`, write
the lerp as three statements: `x = b - a; x *= w; x = a + x / 10;`. The order of the
final add (`a + q` or `q + a`) then sets the `adds` operand order.

Found in: src/matched/ov/ov133_func_021B8C6C.c (0x021B8C6C, four lerp blocks).

## The tell

```
ldr  r1, [r0]         ; b
ldr  r0, [sp, #a]     ; a, reloaded
subs r1, r1, r0       ; difference in b's register
ldr  r0, [sp, #w]     ; w reloaded into r0
muls r0, r1, r0       ; product in w's register
```

The one-expression form gives `subs r0,r1,r0; ldr r1,[sp,#w]; muls r0,r1,r0`.
