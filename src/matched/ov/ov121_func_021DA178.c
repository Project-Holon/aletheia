/*
 * function: func_021DA178
 * address: 0x021DA178
 * packet: pkt_ov121_021DA178
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow the return.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_MENULIST_Main  0x020200CC  thumb  arm9
 *   BMP_MENULIST_GetAttr  0x02020350  thumb  arm9
 */
#include "../include/Obj04493.h"
typedef unsigned int u32;
typedef unsigned char u8;
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
struct PrintSys;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *);
typedef signed int     s32;
struct Obj;
extern s32 BMP_MENULIST_Main(struct Obj *o);
extern u32 BMP_MENULIST_GetAttr(struct Obj *obj, u32 what);
int func_021DA178(char *p)
{
    u32 q = ((struct Obj04493 *)p)->f4;
    int r;
    if (((struct Obj04493 *)p)->fC) {
        if (func_0201C6C4((struct PrintSys *)q,(void *)((u32)func_02045770((struct Descriptor *)((struct Obj04493 *)p)->f8))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)((struct Obj04493 *)p)->f8);
            ((struct Obj04493 *)p)->fC=0;
        }
    }
    r=BMP_MENULIST_Main(((struct Obj04493 *)p)->f10);
    if (r == -2) r=BMP_MENULIST_GetAttr(((struct Obj04493 *)p)->f10,2)-1;
    return r;
}
