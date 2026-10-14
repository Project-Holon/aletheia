/*
 * function: WORLDTRADE_SUBLCD_GetSlotAnimBase
 * address:  0x021FFBC0
 * packet:   pkt_021FFBC0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *

 *
 * Index helper: returns index times 4 plus 0xe.
 */

int WORLDTRADE_SUBLCD_GetSlotAnimBase(int i)
{
    return (i << 2) + 0xe;
}
