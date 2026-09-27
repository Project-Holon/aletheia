/*
 * function: CARD_SetPulledOutCallback
 * address:  0x02066DEC
 * packet:   pkt_02066DEC
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
asm void CARD_SetPulledOutCallback(void)
{
    ldr r1, =g_02148B2C
    str r0, [r1, #8]
    bx lr
}
