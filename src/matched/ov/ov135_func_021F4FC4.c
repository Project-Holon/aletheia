/*
 * function: func_021F4FC4
 * address:  0x021F4FC4
 * packet:   pkt_021F4FC4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */
#include "../include/Obj00018.h"

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cfg;
struct Descriptor;
extern void TIME_ICON_Delete(u8 *p);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 v);

void func_021F4FC4(u8 *p)
{
    if (((struct Obj00018 *)p)->fDF8 != 0) {
        TIME_ICON_Delete((u8 *)(((struct Obj00018 *)p)->fDF8));
        ((struct Obj00018 *)p)->fDF8 = 0;
        BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj00018 *)p)->fD40));
        func_020409B4(func_02045730((struct Descriptor *)(((struct Obj00018 *)p)->fD40)));
    }
}
