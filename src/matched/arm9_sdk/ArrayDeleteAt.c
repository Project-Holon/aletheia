/*
 * function: ArrayDeleteAt
 * address:  0x02005D90
 * packet:   pkt_02005D90
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005F90 0x02005F90 thumb
 *   func_02005D34 0x02005D34 thumb
 */

extern void func_02005F90(void);
typedef unsigned int   u32;
extern void *func_02005D34(u32 a0, u32 a1);
asm void ArrayDeleteAt(void)
{
    push {r3, r4, r5, lr}
    add r5, r0, #0
    add r4, r1, #0
    bl func_02005F90
    add r0, r5, #0
    add r1, r4, #0
    bl func_02005D34
    pop {r3, r4, r5, pc}
}
