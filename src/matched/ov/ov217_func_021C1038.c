/*
 * function: func_021C1038
 * address: 0x021C1038
 * packet: pkt_ov217_021C1038
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_SetPalette 0x02045798 arm
 *   func_02045730 0x02045730 arm
 *   func_02045758 0x02045758 arm
 *   func_02045760 0x02045760 arm
 *   func_02045748 0x02045748 arm
 *   func_02045750 0x02045750 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj03954.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
extern void BMP_WIN_SetPalette(struct Descriptor *,u8);
extern u8 func_02045730(struct Descriptor *);
extern u8 func_02045758(struct Descriptor *);
extern u8 func_02045760(struct Descriptor *);
extern u8 func_02045748(struct Descriptor *);
extern u8 func_02045750(struct Descriptor *);
extern void func_020413B0(u32,u8,u8,u8,u8,u8);
extern void func_02041B6C(u32);
void func_021C1038(u8 *p,u8 palette)
{
    u32 layer;
    u8 x,y,width,height;
    BMP_WIN_SetPalette(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18,palette);
    layer=func_02045730(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    x=func_02045758(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    y=func_02045760(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    width=func_02045748(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    height=func_02045750(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    func_020413B0(layer,x,y,width,height,palette);
    if (((struct Obj03954 *)p)->f1C!=0) func_02041B6C(func_02045730(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18));
}
