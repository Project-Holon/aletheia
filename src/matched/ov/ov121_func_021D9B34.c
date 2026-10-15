/*
 * function: MYSTERY_UTIL_IsMessageDone
 * address: 0x021D9B34
 * packet: pkt_ov121_021D9B34
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero padding bytes at 0x021D9B9A.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb  arm9
 */
#include "../include/Obj02179.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
struct PrintSys;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *);
int MYSTERY_UTIL_IsMessageDone(u8 *p)
{
    u32 q;
    if (((struct Obj02179 *)p)->f24 == 0) {
        q = ((struct Obj02179 *)p)->f8;
        if (p[4]) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)q, (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02179 *)p)->f0))) == 0) {
                BMP_WIN_TransferChars((struct Descriptor *)((struct Obj02179 *)p)->f0);
                p[4] = 0;
            }
        }
        if (p[4] == 0) return 1;
        return 0;
    } else {
        if (p[4]) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)(((struct Obj02179 *)p)->f8), (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02179 *)p)->f0))) == 0)
                p[4] = 0;
        }
        if (p[4] == 0) return 1;
        return 0;
    }
}
