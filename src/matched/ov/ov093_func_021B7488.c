/*
 * function: func_021B7488
 * address:  0x021B7488
 * packet:   pkt_ov093_021B7488
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8BEC  0x021B8BEC  thumb  ov093
 *   d_021EFD38     0x021EFD38  data   a4
 */
#include "../include/Obj02129.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 func_021B8BEC(u8 *p, u32 k, u8 n);
extern int (*d_021EFD38[7])(u8 *, u8 *);

int func_021B7488(int *sp, u8 *p)
{
    if (*sp == 0) {
        p[0x46b] = 2;
        p[0x428] = 0;
        p[0x429] = 1;
        p[0x42a] = 0;
        p[0x42b] = 1;
        p[0x42c] = 0;
        p[0x42d] = 1;
        p[0x46c] = *(u8 *)(((struct Obj02129 *)p)->f0 + 0x21);
        p[0x46d] = func_021B8BEC(p, p[0x46c], 0);
        *sp = *sp + 1;
        return 0;
    }
    if ((u32)*sp < 7) {
        if (d_021EFD38[*sp](p, p + 0x460)) {
            ((struct Obj02129 *)p)->f460 = 0;
            *sp = *sp + 1;
        }
        return 0;
    }
    return 1;
}
