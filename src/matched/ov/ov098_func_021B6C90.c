/*
 * function: func_021B6C90
 * address:  0x021B6C90
 * packet:   pkt_ov098_021B6C90
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 */
#include "../include/Obj03220.h"

typedef unsigned char u8;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *);

void func_021B6C90(char *p, int flag)
{
    if ((u8)(((struct Obj03220 *)p)->f14 + 0xff) <= 1) {
        if (flag == 0) {
            BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj03220 *)p)->f0)), 0xc);
            BMP_WIN_TransferChars((struct Descriptor *)((struct Obj03220 *)p)->f0);
        }
        ((struct Obj03220 *)p)->f4 = 0;
        ((struct Obj03220 *)p)->f8 = 0x10000;
        ((struct Obj03220 *)p)->fC = 0x52AA;
        ((struct Obj03220 *)p)->f10 = -0x1800;
        ((struct Obj03220 *)p)->f15 = 6;
        ((struct Obj03220 *)p)->f14 = 4;
    }
}
