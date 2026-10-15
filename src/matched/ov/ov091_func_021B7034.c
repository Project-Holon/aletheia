/*
 * function: POKELIST_ShutdownBgPlane0
 * address:  0x021B7034
 * packet:   pkt_021B7034
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 */

typedef unsigned int   u32;
void BG_SYS_FreeLayerBuf(u32 i);

void POKELIST_ShutdownBgPlane0(void)
{
    BG_SYS_FreeLayerBuf(0);
}
