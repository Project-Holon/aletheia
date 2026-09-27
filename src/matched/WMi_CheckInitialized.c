/*
 * function: WMi_CheckInitialized
 * address:  0x0208E4CC
 * packet:   pkt_0208E4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02153058 0x02153058 data
 */

extern void g_02153058(void);

asm void WMi_CheckInitialized(void)
{
    ldr r0, =g_02153058
    ldrh	r0, [r0]
    cmp	r0, #0
    movne	r0, #0
    moveq	r0, #3
    bx	lr
}
