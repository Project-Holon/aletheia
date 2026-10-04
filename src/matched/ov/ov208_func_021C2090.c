/*
 * function: func_021C2090
 * address:  0x021C2090
 * packet:   pkt_ov208_021C2090
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3F4  0x0204B3F4  arm
 */
#include "../include/Obj00081.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct Obj;
extern u32 func_0204B3F4(struct Obj *p);

void func_021C2090(void *unused, u8 *p)
{
    if (func_0204B3F4((struct Obj *)(*(int *)&((struct Obj00081 *)p)->fC8)) == 0) {
        if (*(int *)&((struct Obj00081 *)p)->f90 == 0) {
            p[0x414] = 1;
        } else {
            p[0x414] = 2;
        }
    }
}
