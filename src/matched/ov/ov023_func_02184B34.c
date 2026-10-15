/*
 * function: OEKAKI_ResetDisplay
 * address:  0x02184B34
 * packet:   pkt_ov023_02184B34
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 */

typedef unsigned short u16;
void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
typedef unsigned int   u32;
void BG_SYS_FreeLayerBuf(u32 i);
void BG_SYS_Delete(void);

void OEKAKI_ResetDisplay(void)
{
    GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, -16);
    GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, -16);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_Delete();
}
