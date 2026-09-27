/*
 * function: func_0208B798
 * address:  0x0208B798
 * packet:   pkt_0208B798
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02152FE4 0x02152FE4 data
 */

extern void g_02152FE4(void);

asm void func_0208B798(void)
{
    ldr ip, =g_02152FE4
loc_0208B79C:
    ldr	r0, [ip]
    cmp	r0, #1
    beq loc_0208B79C
    bx	lr
}
