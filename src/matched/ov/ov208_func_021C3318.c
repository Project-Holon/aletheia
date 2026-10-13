/*
 * function: func_021C3318
 * address: 0x021C3318
 * packet: pkt_ov208_021C3318
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj00146.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys; struct Descriptor; struct Cfg;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
void func_021C3318(u16 *heap, u8 *p, int key)
{
    struct Descriptor *d;
    if (((struct Obj00146 *)p)->f10 != 0) {
        if (PRINTSYS_QUE_IsExistTarget(*(struct PrintSys * *)&((struct Obj00146 *)p)->f8, BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj00146 *)p)->fC)) == 0) {
            d = *(struct Descriptor * *)&((struct Obj00146 *)p)->fC;
            BMP_WIN_TransferChars(d);
            BMP_WIN_MakeScreen((struct Cfg *)d);
            func_02041B6C(BMP_WIN_GetBgLayer(d));
            ((struct Obj00146 *)p)->f10 = 0;
        }
    }
}
