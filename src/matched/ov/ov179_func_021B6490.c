/*
 * function: func_021B6490
 * address:  0x021B6490
 * packet:   pkt_021B6490
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020221A4  0x020221A4  thumb
 */
#include "../include/Obj24472.h"
typedef unsigned int u32;

extern u32 func_020221A4(void);

u32 func_021B6490(char *p)
{
    if (func_020221A4() == 1)
        return ((struct Obj24472 *)p)->f6054;
    return 2;
}
