/*
 * function: OSi_IrqDma2
 * address:  0x020846BC
 * packet:   pkt_020846BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqDma2.
 *
 * symbols:
 *   OSi_IrqCallback  0x02084614  arm
 */

void OSi_IrqCallback(int dmaNo);

void OSi_IrqDma2(void)
{
    OSi_IrqCallback(2);
}
