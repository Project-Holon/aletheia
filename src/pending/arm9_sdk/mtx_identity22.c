/*
 * function: MTX_Identity22_
 * address:  0x0207AD40
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
 * Original (24 bytes, no relocation):
 *   mov  r1, #0
 *   mov  r2, #0x1000
 *   mov  r3, #0
 *   stm  r0!, {r2, r3}
 *   stm  r0!, {r1, r2}
 *   bx   lr
 *
 * The paired stm runs are one 16-byte aggregate assignment of the identity
 * matrix; FX_ONE is 0x1000 in 20.12 fixed point.
 */

typedef unsigned int u32;

typedef struct
{
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} Mtx22;

void MTX_Identity22_(Mtx22 *m)
{
    Mtx22 t = {0x1000, 0, 0, 0x1000};
    *m = t;
}
