# A 1-or-2 selector written as a ternary first in a sum keeps its scratch register

summary: `x = (f ? 3 : 4) + p->a * 5;` gives the original's `movs r2,#3 ... adds r0,r2,r0` shape, while an if-assigned local `t` or `p->a * 5 + t` allocates the selector into r0 and the load into r1.

Found in: `src/matched/ov/ov046_func_021F3BFC.c`, `src/matched/ov/ov046_func_021F3C8C.c`

## The shape

Original (both functions): `ldr r0,[q,#4]; movs r2,#3; cmp r0,#0; beq L; movs r2,#4; L: ldr r1,[q]; lsls r0,r1,#2; adds r0,r1,r0; adds r0,r2,r0; strb r0,[q,#0xc]`.

## Spellings

- `t = 3; if (q->a4) t = 4; q->c = t + q->a0*5;` and `q->a0*5 + t`: selector lands in r0, wrong registers.
- `q->a0 * 5 + (q->a4 == 0 ? 3 : 4)`: right registers, last `adds` operands swapped.
- `(q->a4 == 0 ? 3 : 4) + q->a0 * 5`: EXACT. Note the `== 0 ? small : large` polarity; `q->a4 ? 4 : 3` inverts the branch.
