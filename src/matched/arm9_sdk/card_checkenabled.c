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
 *   CARD_IsEnabled   0x02075DA0  arm
 *   OS_Terminate   0x02088234  arm
 *
 * Original (24 bytes):
 *   push  {r3, lr}
 *   bl    #0x02075DA0
 *   cmp   r0, #0
 *   popne {r3, pc}
 *   bl    #0x02088234
 *   pop   {r3, pc}
 */

extern void *CARD_IsEnabled(void);
extern void OS_Terminate(void);

void CARD_CheckEnabled(void)
{
    if (CARD_IsEnabled() != 0)
        return;
    OS_Terminate();
}
