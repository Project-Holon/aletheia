/*
 * function: func_021F22E8
 * address:  0x021F22E8
 * packet:   pkt_021F22E8
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj05509.h"

typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_WIN_TransferChars(struct Descriptor *d);

int func_021F22E8(unsigned char *p)
{
    int c = p[0x30];
    int r4 = ((struct Obj05509 *)p)->f38;

    if (c != 0) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)r4, (void *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj05509 *)p)->f2C))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)((struct Obj05509 *)p)->f2C);
            p[0x30] = 0;
        }
    }
    return p[0x30] == 0;
}
