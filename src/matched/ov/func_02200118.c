/*
 * function: WORLDTRADE_TITLE_ExitBgPlanesSub
 * address:  0x02200118
 * packet:   pkt_02200118
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_Delete_03F4  0x020403F4  arm

 *
 * Poke channels 2, 1 and 0 in that order.
 */

typedef unsigned int   u32;
extern void BG_SYS_Delete_03F4(u32 i);

void WORLDTRADE_TITLE_ExitBgPlanesSub(void)
{
    BG_SYS_Delete_03F4(2);
    BG_SYS_Delete_03F4(1);
    BG_SYS_Delete_03F4(0);
}
