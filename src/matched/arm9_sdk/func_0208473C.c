/*
 * function: OSi_IrqNDma2
 * address:  0x0208473C
 * packet:   pkt_0208473C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqNDma2.
 *
 * symbols:
 *   OSi_IrqCallback  0x02084614  arm
 */

void OSi_IrqCallback(int dmaNo);

void OSi_IrqNDma2(void)
{
    OSi_IrqCallback(6);
}
