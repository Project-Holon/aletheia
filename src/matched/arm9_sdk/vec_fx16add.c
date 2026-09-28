/*
 * function: VEC_Fx16Add
 * address:  0x0207CA30
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Original (56 bytes, no relocation):
 *   push  {r4, lr}
 *   ldrsh r4, [r0]
 *   ldrsh r3, [r1]
 *   ldrsh lr, [r0, #2]
 *   ldrsh ip, [r1, #2]
 *   add   r4, r4, r3
 *   ldrsh r3, [r0, #4]
 *   ldrsh r0, [r1, #4]
 *   add   r1, lr, ip
 *   strh  r4, [r2]
 *   add   r0, r3, r0
 *   strh  r1, [r2, #2]
 *   strh  r0, [r2, #4]
 *   pop   {r4, pc}
 */

typedef short s16;

typedef struct
{
    s16 x;
    s16 y;
    s16 z;
} VecFx16;

void VEC_Fx16Add(const VecFx16 *a, const VecFx16 *b, VecFx16 *c)
{
    c->x = a->x + b->x;
    c->y = a->y + b->y;
    c->z = a->z + b->z;
}
