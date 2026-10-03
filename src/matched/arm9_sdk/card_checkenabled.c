/*
 * function: CARD_CheckEnabled
 * address:  0x02075DB0
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02075DA0   0x02075DA0  arm
 *   func_02088234   0x02088234  arm
 *
 * Original (24 bytes):
 *   push  {r3, lr}
 *   bl    #0x02075DA0
 *   cmp   r0, #0
 *   popne {r3, pc}
 *   bl    #0x02088234
 *   pop   {r3, pc}
 */

extern void *func_02075DA0(void);
extern void func_02088234(void);

void CARD_CheckEnabled(void)
{
    if (func_02075DA0() != 0)
        return;
    func_02088234();
}
