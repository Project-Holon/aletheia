/*
 * function: OSi_IrqDma1
 * address:  0x020846AC
 * packet:   pkt_020846AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_irqTable.o OSi_IrqDma1; libmatch named the address DWC_EnableHotspot.
 *
 * symbols:
 *   OSi_IrqCallback  0x02084614  arm
 */

void OSi_IrqCallback(int dmaNo);

void OSi_IrqDma1(void)
{
    OSi_IrqCallback(1);
}
