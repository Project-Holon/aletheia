/*
 * function: WMi_SetCallbackTable
 * address:  0x0208E328
 * packet:   pkt_0208E328
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

asm void WMi_SetCallbackTable(void)
{
    ldr r2, =g_02153058
    ldr	r2, [r2, #4]
    add	r0, r2, r0, lsl #2
    str	r1, [r0, #0x18]
    bx	lr
}
