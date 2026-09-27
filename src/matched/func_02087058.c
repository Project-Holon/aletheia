/*
 * function: func_02087058
 * address:  0x02087058
 * packet:   pkt_02087058
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02151330 0x02151330 data
 */

extern void g_02151330(void);
asm void func_02087058(void)
{
    ldr r0, =g_02151330
    ldrh r0, [r0]
    bx lr
}
