/*
 * function: PMi_SetDispOffCount
 * address:  0x0208C944
 * packet:   pkt_0208C944
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02153000 0x02153000 data
 */

extern void g_02153000(void);

asm void PMi_SetDispOffCount(void)
{
    ldr r1, =0x02FFFC3C
    ldr r0, =g_02153000
    ldr	r1, [r1]
    str	r1, [r0, #0x10]
    bx	lr
}
