/*
 * function: func_021BABFC
 * address:  0x021BABFC
 * packet:   pkt_021BABFC
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ClearLayerEx  0x02041570  arm
 *
 * Addresses are Black-image addresses.
 */

extern int BG_SYS_ClearLayerEx(int, int);

int func_021BABFC(void)
{
    return BG_SYS_ClearLayerEx(2, 0xd000);
}
