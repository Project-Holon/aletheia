# A hoisted stack address in a register is a block-local byte pointer

Shape in the original (ARM, ov125 func_021D824C):

```
    mvn  r4, #0            ; loop-invariant constants
    sub  r5, r4, #5
    add  r8, sp, #8        ; &word, hoisted into the loop preheader
loop:
    ...
    ldr  r3, [r6, #0x260]
    ldrb r0, [r3]
    ...
    strb r0, [r8]          ; byte stores through the register, not [sp, #8]
```

The address of a stack local sits in a callee-saved register and is set in the
loop preheader, after the other hoisted constants. A struct copy
`*(W4 *)&word = *src` or a function-level pointer local does not give this: the
first stores to `[sp, #8]` directly, the second sets the pointer at its
assignment point.

Source that matches: byte copies through a `u8 *` declared inside the loop
block, so loop-invariant code motion hoists the address:

```c
if (count >= 4 && word == -1) {
    u8 *h = (u8 *)&word;
    u8 *q = (u8 *)d_021D9E40[0x260 / 4];
    h[0] = q[0]; h[1] = q[1]; h[2] = q[2]; h[3] = q[3];
}
```

A related point from the same function: a success tail (`destroy(); return 1;`)
that sits after the loop's back branch in the original is `break;` in the loop
plus the tail statements after the loop.
