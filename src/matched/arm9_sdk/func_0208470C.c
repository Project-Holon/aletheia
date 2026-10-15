/*
 * function: OSi_IrqTimer3
 * address:  0x0208470C
 * packet:   pkt_0208470C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqTimer3.
 *
 * symbols:
 *   OSi_IrqCallback  0x02084614  arm
 */

void OSi_IrqCallback(int dmaNo);

void OSi_IrqTimer3(void)
{
    OSi_IrqCallback(11);
}
