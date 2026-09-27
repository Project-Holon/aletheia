/*
 * function: func_020307C8
 * address:  0x020307C8
 * packet:   pkt_020307C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02030238 0x02030238 arm
 *   func_02088234 0x02088234 arm
 */

extern void func_02030238(void);
extern void func_02088234(void);

asm void func_020307C8(void)
{
    stmfd sp!, {r3, lr}
    bl func_02030238
    cmp	r0, #0
    ldmnefd sp!, {r3, pc}
    bl func_02088234
    ldmfd sp!, {r3, pc}
}
