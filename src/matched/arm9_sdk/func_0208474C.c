/*
 * function: OSi_IrqNDma3
 * address:  0x0208474C
 * packet:   pkt_0208474C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqNDma3.
 *
 * symbols:
 *   OSi_IrqCallback  0x02084614  arm
 */

void OSi_IrqCallback(int dmaNo);

void OSi_IrqNDma3(void)
{
    OSi_IrqCallback(7);
}
