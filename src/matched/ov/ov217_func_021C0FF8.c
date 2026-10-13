/*
 * function: func_021C0FF8
 * address: 0x021C0FF8
 * packet: pkt_ov217_021C0FF8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: two zero padding bytes at 0x021C1036, not a follower.
 * symbols:
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj06716.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *);
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_ClearScreen(struct Descriptor *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_02041B6C(u32);
void func_021C0FF8(u8 *p,int visible)
{
    if (((struct Obj06716 *)p)->f1C==0 && visible!=0) {
        struct Descriptor *d=*(struct Descriptor * *)&((struct Obj06716 *)p)->f18;
        BMP_WIN_TransferChars(d);
        BMP_WIN_MakeScreen((struct Cfg *)d);
        func_02041B6C(BMP_WIN_GetBgLayer(d));
    } else if (((struct Obj06716 *)p)->f1C!=0 && visible==0) {
        struct Descriptor *d=*(struct Descriptor * *)&((struct Obj06716 *)p)->f18;
        BMP_WIN_ClearScreen(d);
        func_02041B6C(BMP_WIN_GetBgLayer(d));
    }
    ((struct Obj06716 *)p)->f1C=visible;
}
