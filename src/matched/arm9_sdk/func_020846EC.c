/*
 * function: OSi_IrqTimer1
 * address:  0x020846EC
 * packet:   pkt_020846EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqTimer1.
 *
 * symbols:
 *   OSi_IrqCallback  0x02084614  arm
 */

void OSi_IrqCallback(int dmaNo);

void OSi_IrqTimer1(void)
{
    OSi_IrqCallback(9);
}
