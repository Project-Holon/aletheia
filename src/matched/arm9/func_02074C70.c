/*
 * function: func_02074C70
 * address:  0x02074C70
 * packet:   pkt_02074A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj11687.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


extern void *func_02074388(int index);
extern u32 func_02074FA8(u32, u32, u32);
extern u32 func_0207466C(u32);
u32 func_02074C70(u32 a, u32 b, u32 c, u32 d, u32 *out) {
    void *p = func_02074388(a);
    u32 r;
    if (p == 0) return 3;
    if (b & 8) {
        r = func_02074FA8(((struct Obj11687 *)p)->f0, c, d);
        if (r == 0) return 7;
    } else {
        r = func_0207466C(((struct Obj11687 *)p)->f0);
    }
    if (out != 0) *out = r;
    return 0;
}
