/*
 * function: STARTMENU_TeardownBackgrounds
 * address:  0x021BAB20
 * packet:   pkt_ov088_021BAB20
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: inferred extent runs two bytes long; the follower at 0x021BAB62 is
 * an unlabelled leaf (no lr save) that disasm.py did not label.
 *
 * symbols:
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 */

typedef unsigned int   u32;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BG_SYS_Delete(void);

void STARTMENU_TeardownBackgrounds(void)
{
    BG_SYS_SetMainPlaneVisible(0xf, 0);
    BG_SYS_SetSubPlaneVisible(7, 0);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_Delete();
}
