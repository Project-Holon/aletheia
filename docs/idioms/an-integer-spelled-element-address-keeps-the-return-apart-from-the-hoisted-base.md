# An element address spelled in integer arithmetic keeps the returned address apart from the hoisted loop base

summary: in a search loop that calls `f(&base[i])` and returns `&base[i]` on a hit, the struct
subscript lets mwcc reuse the hoisted `p + 0x28` register for the return, and the offset stays in
a register. When the image instead spills `i * size` to the stack and rebuilds `p + 0x28` from `p`
in the hit block (`ldr r0,[sp]; adds r5,#0x28; adds r0,r5,r0`), write both addresses as
`(u32)p + 0x28 + i * size`.

Found in: src/matched/ov208_func_021BD404.c (0x021BD404)

The image:

```asm
    adds r6, r5, #0
    adds r6, #0x28          ; hoisted base for the call argument
loop:
    movs r0, #0x38
    muls r0, r4, r0
    str  r0, [sp]           ; offset spilled across the call
    adds r0, r6, r0
    bl   key_of
    cmp  r7, r0
    bne  next
    ldr  r0, [sp]
    adds r5, #0x28          ; base rebuilt from p, not r6
    adds r0, r5, r0
    pop  {r3-r7, pc}
```

`&p->recs[i]` in both places returns `r6 + off` (18 bytes out). Mixing one struct subscript with
one `char *` sum stops the offset from being shared (16 bytes out). Only the integer form in both
places, `(struct Rec *)((u32)p + 0x28 + i * 0x38)`, gives the spilled offset and the rebuilt base.
An unrelated old pending draft (`int a0` parameter, `a0 + 0x28 + i * 0x38`) had the same shape of
source and was two bytes short only because its loop guard was written as an explicit `if`.
