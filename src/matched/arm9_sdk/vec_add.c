/*
 * function: VEC_Add
 * address:  0x0207C9D0
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
 * Original (48 bytes, no relocation):
 *   push {r4, lr}
 *   ldr  lr, [r1]
 *   ldr  r3, [r1, #4]
 *   ldm  r0, {r4, ip}
 *   add  ip, ip, r3
 *   add  r4, r4, lr
 *   ldr  r3, [r0, #8]
 *   ldr  r0, [r1, #8]
 *   stm  r2, {r4, ip}
 *   add  r0, r3, r0
 *   str  r0, [r2, #8]
 *   pop  {r4, pc}
 */

typedef int s32;

typedef struct
{
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *c)
{
    c->x = a->x + b->x;
    c->y = a->y + b->y;
    c->z = a->z + b->z;
}
