/*
 * function: BTL_REC_ReadEntry
 * address:  0x021EE63C
 * packet:   pkt_ov093_021EE63C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

unsigned short *BTL_REC_ReadEntry(unsigned short *a, unsigned int *b)
{
    *b = *a;
    return a + 4;
}
