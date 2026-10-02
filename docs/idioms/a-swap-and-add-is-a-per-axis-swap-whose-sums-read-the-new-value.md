# A swap-and-add is a per-axis swap whose sums read the new value

summary: `a' = b; b' = a + b` over a 12-byte vector, compiled field-wise with
one spill, where the image spills old a.z (and keeps b.z in ip) but your compile
spills a middle b component, comes from a per-axis swap through temps from a
(`tx = a.x; a.x = b.x;` for x, y, z in turn) followed by sums that read the new
a: `b.x = tx + a.x`. Writing `tx + b.x`, `b.x + tx` or `a.x + tx` instead leaves
the add operands reversed; grouping the three temps first moves the spill.

Found in: src/matched/ov/ov094_func_021FD1CC.c (0x021FD1CC, ov094, Thumb)

The image, 0x021FD532..0x021FD556:

```
ldr r0, [sp, #0xc0]     ; old a.z
ldr r2, [sp, #0xb8]     ; old a.x
ldr r1, [sp, #0xac]     ; old b.x
str r0, [sp, #0x10]     ; spill old a.z
ldr r0, [sp, #0xb4]     ; old b.z
ldr r3, [sp, #0xbc]     ; old a.y
ldr r7, [sp, #0xb0]     ; old b.y
mov ip, r0
str r0, [sp, #0xc0]     ; a.z = b.z
adds r0, r2, r1         ; old a.x + old b.x
...
```

What matches:

```c
tx = a.x;
a.x = b.x;
ty = a.y;
a.y = b.y;
tz = a.z;
a.z = b.z;
b.x = tx + a.x;
b.y = ty + a.y;
b.z = tz + a.z;
```

Measured and wrong: three temps then three copies then three sums (any axis
order, spill moves to the second axis's b value, 31 to 34 bytes); temps from b
(no spill, the frame shrinks by 4 and every offset moves); a `Vec` temp or
`a = b` (frame grows, or ldm/stm); six explicit temps (10 to 13 bytes,
register permutation); a VEC_Set-style inline setter (32 bytes); the sum
operand spelled `b.x + tx` or `tx + b.x` after the interleaved swap (4 bytes,
add operands reversed). Temp names and declaration order are inert.
