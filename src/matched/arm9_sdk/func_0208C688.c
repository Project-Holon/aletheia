/*
 * function: func_0208C688
 * address:  0x0208C688
 * packet:   pkt_0208C688
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     spi/ARM9/pm.o PM_GetLCDPower.
 */

int func_0208C688(void)
{
    return (*(volatile unsigned short *)0x04000304 & 1) ? 1 : 0;
}
