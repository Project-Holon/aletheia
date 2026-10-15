/*
 * function: WORLDTRADE_DETAIL_ExitBgPlanes
 * address:  0x021FC2A4
 * packet:   pkt_021FC2A4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm

 *
 * Poke the channel-selection helper with 0, 1, 2, 3 in turn.
 */

typedef unsigned int   u32;
extern void BG_SYS_FreeLayerBuf(u32 i);

void WORLDTRADE_DETAIL_ExitBgPlanes(void)
{
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(3);
}
