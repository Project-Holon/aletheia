/*
 * file:     unit_02064D70_p15.c
 * function: func_02066754
 * address:  0x02066754
 * packet:   pkt_02066754
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 2x3 fixed-point matrix concatenation, ab = a * b with the translation row
 * of b added (MTX_Concat22-style, fx32 = 20.12).  When ab aliases b the
 * result goes to a stack temporary and is block-copied back.
 *
 * COMPILER PIN ../2.0/sp2, "kept branches" (docs/FRONTEND-PINS.md): the image
 * leaves the copy-back guard as `addne sp, sp, #0x18` (0x020667F0) plus
 * `popne {r3, r4, r5, r6, r7, pc}` (0x0206685C) ahead of an unpredicated
 * ldm/stm pair; 1.1p1 -O4,p predicates the four-instruction copy into
 * ldmeq/stmeq/ldmeq/stmeq and lands at 260 (const inputs) or 284 bytes.
 *
 * Lever: docs/notes/pkt_02066754.c.txt had this at 292/107 with `const
 * volatile` inputs and hand-hoisted products; none of that is needed.  The
 * plain SDK spelling -- one expression per element, `a0*b0 + a1*b1` so the
 * SECOND product is the smull and the first the smlal accumulator -- is
 * byte-exact under the pin.  The per-element reloads come from the stores
 * through p, which may alias a and b.
 */
typedef int fx32;
typedef long long fx64;

typedef struct MtxFx23 {
    fx32 m[3][2];
} MtxFx23;

#define FX32_SHIFT 12

void func_02066754(const MtxFx23 *a, const MtxFx23 *b, MtxFx23 *ab)
{
    MtxFx23 tmp;
    MtxFx23 *p;

    if (ab == b)
        p = &tmp;
    else
        p = ab;

    p->m[0][0] = (fx32)(((fx64)a->m[0][0] * b->m[0][0] + (fx64)a->m[0][1] * b->m[1][0]) >> FX32_SHIFT);
    p->m[0][1] = (fx32)(((fx64)a->m[0][0] * b->m[0][1] + (fx64)a->m[0][1] * b->m[1][1]) >> FX32_SHIFT);
    p->m[1][0] = (fx32)(((fx64)a->m[1][0] * b->m[0][0] + (fx64)a->m[1][1] * b->m[1][0]) >> FX32_SHIFT);
    p->m[1][1] = (fx32)(((fx64)a->m[1][0] * b->m[0][1] + (fx64)a->m[1][1] * b->m[1][1]) >> FX32_SHIFT);
    p->m[2][0] = (fx32)(((fx64)a->m[2][0] * b->m[0][0] + (fx64)a->m[2][1] * b->m[1][0]) >> FX32_SHIFT) + b->m[2][0];
    p->m[2][1] = (fx32)(((fx64)a->m[2][0] * b->m[0][1] + (fx64)a->m[2][1] * b->m[1][1]) >> FX32_SHIFT) + b->m[2][1];

    if (p == &tmp)
        *ab = tmp;
}
