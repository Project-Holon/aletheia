/*
 * function: func_021B7B80
 * address:  0x021B7B80
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Guarded flag set at +0x28.
 *
 * symbols:
 *   func_021BE100  0x021BE100  thumb  ov172
 *   func_021B69D8  0x021B69D8  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06558.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_021BE100(int x);
extern void func_021B69D8(void *p);

void func_021B7B80(int x, char *p)
{
    if (func_021BE100(x) != 1) {
        return;
    }
    if (((struct Obj06558 *)p)->f24 != 1) {
        return;
    }
    if (((struct Obj06558 *)p)->f28 != 0) {
        return;
    }
    func_021B69D8(((struct Obj06558 *)p)->fA4);
    ((struct Obj06558 *)p)->f28 = 1;
}
