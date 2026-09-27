/*
 * function: func_0208469C
 * address:  0x0208469C
 * packet:   pkt_0208469C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_irqTable.o OSi_IrqDma0; libmatch named the address CameraStandbyCallback.
 *
 * symbols:
 *   OSi_IrqCallback  0x02084614  arm
 */

void OSi_IrqCallback(int dmaNo);

void func_0208469C(void)
{
    OSi_IrqCallback(0);
}
