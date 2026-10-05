# An instruction the scheduler will not hoist sits after a cross-jumped join

summary: when the image keeps a store before a constant load that the build always
schedules first (`str r0,[sp,#K]; movs r5,#0` in the image, the reverse in the
build), look for a block boundary between them. A ternary or if/else that only
selects a constant, followed by calls, is often an if/else with the calls written in
each arm. Cross-jumping merges the identical tails, so the join label (and the
block boundary) sits after the last merged statement, and the scheduler cannot move
the next block's instructions above it.

Found in: src/matched/ov/ov172_func_021B71B8.c (0x021B71B8, ov172, Thumb), wave D9.

The image:

```
cmp r0,#1; bne L1
movs r5,#2; b L2
L1: movs r5,#1
L2: lsls r5,r5,#12
adds r0,r5,#0; blx f; str r0,[sp,#0x38]
adds r0,r5,#0; blx f; str r0,[sp,#0x44]
movs r5,#0            <- next block
str r5,[sp,#0x3c]; str r5,[sp,#0x40]; ...; blx g
```

`s = q->f20 == 1 ? 0x2000 : 0x1000; m[0] = f(s); m[3] = f(s); m[1] = 0; m[2] = 0;`
gives the same instructions, but `movs r5,#0` lands before `str r0,[sp,#0x44]`
(4 bytes). Five lanes tried store orders, struct shapes, inline helpers, types:
all flat. Writing the calls in each arm closes it:

```c
if (q->f20 == 1) {
    m[0] = f(0x2000);
    m[3] = f(0x2000);
} else {
    m[0] = f(0x1000);
    m[3] = f(0x1000);
}
m[1] = 0;
m[2] = 0;
g((void *)0x04000030, m, 0, 0, 0, 0);
```

The tell: the image builds the selected constant as `movs rK,#a` / `movs rK,#b` in the
arms and one shared `lsls` (or other tail), and an instruction right after the
merged tail never moves up in any build. Compare with
a-constant-shifted-in-a-merged-tail-is-a-statement-repeated-in-each-arm.md.
