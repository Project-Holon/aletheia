/*
 * function: B_BAG_MAIN_ExitBg
 * address:  0x0220D6B8
 * packet:   pkt_0220D6B8
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 */

typedef unsigned int   u32;
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_FreeLayerBuf(u32 i);

void B_BAG_MAIN_ExitBg(void)
{
    BG_SYS_SetSubPlaneVisible(0x1f, 0);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(7);
}
