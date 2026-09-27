/*
 * function: DWC_AC_CancelGetWDSInfo
 * address:  0x0205DC58
 * packet:   pkt_0205DC58
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146ADC 0x02146ADC data
 */

extern void g_02146ADC(void);

asm void DWC_AC_CancelGetWDSInfo(void)
{
    ldr r0, =g_02146ADC
    ldr	r1, [r0, #8]
    cmp	r1, #4
    moveq	r1, #5
    streq	r1, [r0, #8]
    bx	lr
}
