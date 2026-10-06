/*
 * function: func_020846DC
 * address:  0x020846DC
 * packet:   pkt_020846DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqTimer0.
 *
 * symbols:
 *   OSi_IrqCallback  0x02084614  arm
 */

void OSi_IrqCallback(int dmaNo);

void func_020846DC(void)
{
    OSi_IrqCallback(8);
}
