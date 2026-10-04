/*
 * function: func_021BD73C
 * address:  0x021BD73C
 * packet:   pkt_021BD73C
 * region:   ov216
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02035C60 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 */
#include "../include/Obj10950.h"

typedef unsigned int u32;

extern int func_02035C60(void);
extern u32 func_020362DC(void);

int func_021BD73C(char *p)
{
    unsigned char c;
    if (func_02035C60() != 0 || (func_020362DC() & 1) != 0)
    {
        ((struct Obj10950 *)p)->f1 = 0;
        return 0;
    }
    c = ((struct Obj10950 *)p)->f1;
    ((struct Obj10950 *)p)->f1 = c - 1;
    if (c != 0)
    {
        return 1;
    }
    return 0;
}
