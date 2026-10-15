/*
 * function: ZKNSEARCH_MAIN_RedrawSubWindow
 * address:  0x021BED1C
 * packet:   pkt_ov210_021BED1C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKNSEARCH_MAIN_MakeWindowScreen 0x021BE49C thumb ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
extern void ZKNSEARCH_MAIN_MakeWindowScreen(u8 *p);

void ZKNSEARCH_MAIN_RedrawSubWindow(int p)
{
    ZKNSEARCH_MAIN_MakeWindowScreen((u8 *)(p + 0x1a4));
}
