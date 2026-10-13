/*
 * function: FADE_GetSpeed
 * address:  0x0204E6E0
 * packet:   pkt_0204E6E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A7C 0x02146A7C data
 */

extern void g_02146A7C(void);

asm void FADE_GetSpeed(void)
{
    ldr r0, =g_02146A7C
    ldr	r0, [r0]
    ldr	r0, [r0, #0x1c]
    bx	lr
}
