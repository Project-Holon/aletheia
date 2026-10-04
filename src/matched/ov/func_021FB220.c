/*
 * function: func_021FB220
 * address:  0x021FB220
 * packet:   pkt_021FB220
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020355C4  0x020355C4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *
 * State select before the notify call.
 */
#include "../include/Obj09235.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern u8 func_020355C4(void);
struct Obj;
extern void func_0204B3DC(struct Obj *a, unsigned int b);

int func_021FB220(u8 *p)
{
    u32 v;
    int n;

    if (func_020355C4() == 1) {
        v = ((struct Obj09235 *)p)->f8;
        n = 0;
    } else {
        v = ((struct Obj09235 *)p)->f8;
        n = 1;
    }
    func_0204B3DC((struct Obj *)v, n);
    ((struct Obj09235 *)p)->f48 = 0xa;
    return -1;
}

