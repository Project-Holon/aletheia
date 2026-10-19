# Loop-invariant bases stored after the counter init are written inside the loop

summary: Base pointers that the original stores after the loop counter init are assigned inside
the loop body. mwcc hoists them into the preheader after the counter init.

## Shape

Before an outer loop, the original stores the loop counter first and the base pointers after it:

```
movs  r0, #0
str   r0, [sp, #0x14]     ; i = 0
ldr   r0, [sp, #0xc]
adds  r4, #0x10
adds  r0, r0, r4
str   r0, [sp, #0x28]     ; base1 = p + 0x1f0
ldr   r0, [sp, #0xc]
str   r0, [sp, #0x2c]
adds  r0, #0x10
str   r0, [sp, #0x2c]     ; base0 = p + 0x10
```

A draft that assigns the bases before `for (i = 0; ...)` stores the bases first and `i = 0` last.

## Source

The bases are assigned inside the loop body. mwcc hoists them into the loop preheader, which comes
after the counter init:

```c
for (i = 0; i < 15; i++) {
    base1 = (u16 *)(p + 0x1f0);
    base0 = (u16 *)(p + 0x10);
    ...
```

The hoisted `base0 = p + 0x10` also gives the `str; adds; str` double store to its slot without
an accessor helper.

In the same function, an inner-loop row pointer that the original computes after the `k >> 8`
argument was written inline in the call (`base1 + j * 16 + m`), not as a `src` local.

## Seen in

ov123 func_021D9D3C (wave D9r lane50, with the real `u32` return type of func_02049658).
