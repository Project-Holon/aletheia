# A named 64-bit product over element pointers keeps the sum in place

summary: a 3:1 fixed-point blend `((s64)v * 3 + v_sub) >> 2` canonicalises
to `adds lo, v_sub, lo`; naming the product (`w = (s64)v * 3; (w + v_sub)`)
gives the image's `adds lo, lo, v_sub` but only colours right when the two
keys are read through element pointers, not by subscript.

Found in: src/matched/func_0206F4C8.c (0x0206F4C8)

The image (ARM, ../2.0/sp2p2 -O4,p), s32 arm of a vector-2 key sampler:

    ldr   r6, [r1, r2, lsl #3]    ; v = key[idx].s
    mov   ip, #3
    umull r5, r4, r6, ip
    asr   lr, r6, #0x1f
    ldr   r6, [r1, r3, lsl #3]    ; v_sub = key[idx_sub].s, same register
    mla   r4, lr, ip, r4
    adds  r5, r5, r6              ; product low word first

With `v = p[idx].s; v_sub = p[idx_sub].s;` and the product unnamed, every
spelling (operand order, casts, 3LL, the sum through a local) emits
`adds r5, r6, r5` (2 bytes out). Naming the product over the same subscripts
fixes the operand order but sign-extends v in place and moves v_sub to lr (27
out). Taking `const S *pv = base + idx, *pv_sub = base + idx_sub;` and reading
`pv->s` / `pv_sub->s` with the named product is EXACT for the whole arm: the
loads still use the scaled-register form, the element pointers only change
the colouring order. The unrelated s16 arm of the same function wanted the
opposite (subscripts), so try the element-pointer form per arm.
