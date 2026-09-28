/*
 * function: func_02066E10
 * address:  0x02066E10
 * packet:   pkt_02066E10
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A8218 0x020A8218 data
 */

extern void g_020A8218(void);
asm void func_02066E10(void)
{
    ldr r1, =g_020A8218
    str r0, [r1]
    bx lr
}
