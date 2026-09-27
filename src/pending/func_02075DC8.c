/*
 * function: func_02075DC8
 * address:  0x02075DC8
 * packet:   pkt_02075DC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT *
 * symbols:
 *   g_0215019C 0x0215019C data arm9
 */

extern void g_0215019C(void);
asm void func_02075DC8(void)
{
    ldr r1, =g_0215019C
    str r0, [r1]
    bx lr
}
