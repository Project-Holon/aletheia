/*
 * function: WORLDTRADE_BOX_ExitBgPlanes
 * address:  0x021F5358
 * packet:   pkt_021F5358
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
 * Poke the channel-selection helper with 2, 1, 0, 3 in turn.
 */

typedef unsigned int   u32;
extern void BG_SYS_FreeLayerBuf(u32 i);

void WORLDTRADE_BOX_ExitBgPlanes(void)
{
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_FreeLayerBuf(3);
}
