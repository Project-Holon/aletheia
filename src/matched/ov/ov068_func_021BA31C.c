/*
 * function: OPTION_MENU_IsTextDone
 * address:  0x021BA31C
 * packet:   pkt_ov068_021BA31C
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Switch with `case 0: default: return 1;` written first puts the shared
 * return right after the dispatch, as in the original.
 *
 * symbols:
 *   func_02028484  0x02028484  thumb
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 */
#include "../include/Obj03658.h"

typedef unsigned char u8;
typedef unsigned int  u32;

typedef signed int     s32;
struct Blk;
struct PrintSys;
extern s32 func_02028484(struct Blk *blk, void *h);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);

int OPTION_MENU_IsTextDone(u8 *p)
{
    u32 t;

    switch (((struct Obj03658 *)p)->f28) {
    case 0:
    default:
        return 1;
    case 2:
        t = ((struct Obj03658 *)p)->f24;
        if (p[0x20] != 0) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)t, (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj03658 *)p)->f1C))) == 0) {
                BMP_WIN_TransferChars((struct Descriptor *)((struct Obj03658 *)p)->f1C);
                p[0x20] = 0;
            }
        }
        if (p[0x20] == 0) {
            return 1;
        }
        return 0;
    case 1:
        return func_02028484((struct Blk *)(p + 0x2c), (void *)(((struct Obj03658 *)p)->f8));
    }
}
