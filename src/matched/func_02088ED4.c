/*
 * function: func_02088ED4
 * address:  0x02088ED4
 * packet:   pkt_02088ED4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_0215142C 0x0215142C data
 */

extern void g_0215142C(void);

asm void func_02088ED4(void)
{
    ldr ip, =g_0215142C
loc_02088ED8:
    ldr	r0, [ip]
    cmp	r0, #1
    beq loc_02088ED8
    bx	lr
}
