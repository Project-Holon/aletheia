/*
 * function: WORLDTRADE_SEARCH_ExitBgPlanes
 * address:  0x021FDCE4
 * packet:   pkt_021FDCE4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_Delete_03F4  0x020403F4  arm

 *
 * Poke the channel-selection helper with 2, 1, 0, 3 in turn.
 */

typedef unsigned int   u32;
extern void BG_SYS_Delete_03F4(u32 i);

void WORLDTRADE_SEARCH_ExitBgPlanes(void)
{
    BG_SYS_Delete_03F4(2);
    BG_SYS_Delete_03F4(1);
    BG_SYS_Delete_03F4(0);
    BG_SYS_Delete_03F4(3);
}
