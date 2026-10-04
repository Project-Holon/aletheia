/*
 * function: func_021A39E4
 * address:  0x021A39E4
 * packet:   pkt_ov021_021A39E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 */
#include "../include/Obj12729.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void *func_021A3960(u8 *p);
int func_0216D7A8(void *p, unsigned int v);

int func_021A39E4(u8 *p)
{
    if (func_0216D7A8(func_021A3960(p), 0) != 0xFFFF) {
        if (((struct Obj12729 *)p)->f2C == 1)
            return 1;
        (((struct Obj12729 *)p)->f2C)++;
    }
    return 0;
}
