/*
 * function: func_021DCFD4
 * address:  0x021DCFD4
 * packet:   pkt_021DCFD4
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DE0AC  0x021DE0AC  thumb  ov171
 */
#include "../include/Obj14288.h"
typedef unsigned int u32;

extern int func_021DE0AC(void *p, u32 v);

u32 func_021DCFD4(char *p)
{
    if (func_021DE0AC(p, ((struct Obj14288 *)p)->fC64) == 0)
        return ((struct Obj14288 *)p)->fC68;
    return 3;
}
