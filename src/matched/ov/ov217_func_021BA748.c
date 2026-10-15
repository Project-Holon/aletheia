/*
 * function: RESEARCH_TOP_ExitOverlayBackgrounds
 * address:  0x021BA748
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   RESEARCH_TOP_ExitOverlayBackgrounds  0x021BA748  thumb  ov217
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm  arm9
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 BG_SYS_FreeLayerBuf();
extern void BMP_WIN_Exit(void);
u32 RESEARCH_TOP_ExitOverlayBackgrounds(void)
{
    BMP_WIN_Exit();
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(7);
    return BG_SYS_FreeLayerBuf(6);
}

