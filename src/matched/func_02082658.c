/*
 * function: func_02082658
 * address:  0x02082658
 * packet:   pkt_02082658
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MI_StopDma  0x020825F0  arm
 */

void MI_StopDma(unsigned int dmaNo);

void func_02082658(void)
{
    MI_StopDma(0);
    MI_StopDma(1);
    MI_StopDma(2);
    MI_StopDma(3);
}
