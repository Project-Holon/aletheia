/*
 * function: func_021B7590
 * address:  0x021B7590
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Guarded tail call of func_021B688C on the field at +0xa4.
 *
 * symbols:
 *   func_021BE100  0x021BE100  thumb  ov172
 *   func_021B688C  0x021B688C  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02992.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_021BE100(int x);
extern int func_021B688C(void *p);

int func_021B7590(int x, char *p)
{
    if (func_021BE100(x) == 1) {
        return func_021B688C(((struct Obj02992 *)p)->fA4);
    }
    return 1;
}
