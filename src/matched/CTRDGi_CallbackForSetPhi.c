/*
 * function: CTRDGi_CallbackForSetPhi
 * address:  0x02066DFC
 * packet:   pkt_02066DFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02148B2C 0x02148B2C data
 */

extern void g_02148B2C(void);

asm void CTRDGi_CallbackForSetPhi(void)
{
    ldr r0, =g_02148B2C
    mov	r1, #0
    str	r1, [r0, #4]
    bx	lr
}
