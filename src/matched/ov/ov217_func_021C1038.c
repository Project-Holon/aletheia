/*
 * function: BgTextLabel_SetPalette
 * address: 0x021C1038
 * packet: pkt_ov217_021C1038
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_SetPalette 0x02045798 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BMP_WIN_GetPosX 0x02045758 arm
 *   BMP_WIN_GetPosY 0x02045760 arm
 *   BMP_WIN_GetDispWidth 0x02045748 arm
 *   BMP_WIN_GetDispHeight 0x02045750 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj03954.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
extern void BMP_WIN_SetPalette(struct Descriptor *,u8);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern u8 BMP_WIN_GetPosX(struct Descriptor *);
extern u8 BMP_WIN_GetPosY(struct Descriptor *);
extern u8 BMP_WIN_GetDispWidth(struct Descriptor *);
extern u8 BMP_WIN_GetDispHeight(struct Descriptor *);
extern void BG_SYS_FillTileMap(u32,u8,u8,u8,u8,u8);
extern void func_02041B6C(u32);
void BgTextLabel_SetPalette(u8 *p,u8 palette)
{
    u32 layer;
    u8 x,y,width,height;
    BMP_WIN_SetPalette(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18,palette);
    layer=BMP_WIN_GetBgLayer(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    x=BMP_WIN_GetPosX(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    y=BMP_WIN_GetPosY(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    width=BMP_WIN_GetDispWidth(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    height=BMP_WIN_GetDispHeight(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    BG_SYS_FillTileMap(layer,x,y,width,height,palette);
    if (((struct Obj03954 *)p)->f1C!=0) func_02041B6C(BMP_WIN_GetBgLayer(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18));
}
