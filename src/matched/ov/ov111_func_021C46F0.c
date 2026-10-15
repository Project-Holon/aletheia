/*
 * function: VIEWER_MAIN_ExitBg
 * address:  0x021C46F0
 * packet:   pkt_ov111_021C46F0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   BG_SYS_FillScrollArea  0x02040618  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_FillScrollArea(u32 bgId, u32 which, u32 value);
extern void BG_SYS_FreeLayerBuf(u32 bgId);
extern void BG_SYS_Delete(void);

void VIEWER_MAIN_ExitBg(void)
{
    BG_SYS_SetMainPlaneVisible(0x1F, 0);
    BG_SYS_SetSubPlaneVisible(0x1F, 0);
    BG_SYS_FillScrollArea(5, 0, 0);
    BG_SYS_FillScrollArea(5, 3, 0);
    BG_SYS_FillScrollArea(3, 0, 0);
    BG_SYS_FillScrollArea(3, 3, 0);
    BG_SYS_FreeLayerBuf(7);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_Delete();
}
