# Thumb `movs r0,#0; mvns r0,r0; muls` is `x *= -1`, while `x = x * -1` folds to `rsbs`

summary: in Thumb, `*(int *)(s + 4) = *(int *)(s + 4) * -1;` compiles to `ldr; rsbs r0,r0,#0; str`, but the compound `*(int *)(s + 4) *= -1;` keeps a real multiply (`movs r0,#0; mvns r0,r0; muls r0,r1,r0`, or -1 CSE'd off an already-live 31 as `subs r4,#0x20`).

Found in: src/matched/ov/ov043_func_021F41B8.c, src/matched/ov/ov043_func_021F4210.c

The image spends a register on -1 and multiplies. Spelling the store as
`f = f * -1` gives 4 bytes less (`rsbs`) and a DIFF; `f *= -1` is EXACT in both
functions. (The ARM-side sibling, where the source multiplied by 0xffffffff,
is `a-multiply-by-minus-one-is-strength-reduced-but-by-0xffffffff-is-not.md`.)

Also seen in the same two files: an unlabelled follower of a 176-byte extent
was a pool word plus an unlabelled leaf, so the verdict was EXACT*.
