/*
 * function: func_02087244
 * address:  0x02087244
 * packet:   pkt_02087244
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT *
 * symbols:
 *   g_02151340 0x02151340 data arm9
 */

extern void g_02151340(void);
asm void func_02087244(void)
{
    ldr r0, =g_02151340
    ldrh r0, [r0]
    bx lr
}
