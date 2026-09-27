/*
 * function: func_02030BA4
 * address:  0x02030BA4
 * packet:   pkt_02030BA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02030534 0x02030534 arm
 *   func_02088234 0x02088234 arm
 */

extern void func_02030534(void);
extern void func_02088234(void);

asm void func_02030BA4(void)
{
    stmfd sp!, {r3, lr}
    bl func_02030534
    cmp	r0, #0
    ldmnefd sp!, {r3, pc}
    bl func_02088234
    ldmfd sp!, {r3, pc}
}
