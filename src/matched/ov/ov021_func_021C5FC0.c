/*
 * function: func_021C5FC0
 * address:  0x021C5FC0
 * packet:   pkt_ov021_021C5FC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Wait step: 1 on a key press, 2 on timeout, otherwise 0.
 */
#include "../include/Obj07564.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_020362DC(void);

int func_021C5FC0(u8 *p, u32 lim)
{
    u32 n = ((struct Obj07564 *)p)->f60;

    ((struct Obj07564 *)p)->f60 = n + 1;
    if (n < lim) {
        if (func_020362DC() & 1) {
            ((struct Obj07564 *)p)->f60 = 0;
            return 1;
        }
    } else {
        ((struct Obj07564 *)p)->f60 = 0;
        return 2;
    }
    return 0;
}
