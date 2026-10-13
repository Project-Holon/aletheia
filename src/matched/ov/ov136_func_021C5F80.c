/*
 * function: func_021C5F80
 * address: 0x021C5F80
 * packet: pkt_ov136_021C5F80
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 */
#include "../include/Obj14191.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_021C5F80(void *unused, void *text, u8 *slot, void *owner, int x, int y, u32 mode, u16 color, int align)
{
    if (align == 1)
        x -= func_0201D304(text, mode, 0);
    else if (align == 2)
        x -= func_0201D304(text, mode, 0) >> 1;
    PRINTSYS_PrintQueColor(owner, (u32)BMP_WIN_GetBmp(((struct Obj14191 *)slot)->f0), (s16)x, (s16)y, (u32)text, mode, color);
    slot[4] = 1;
}
