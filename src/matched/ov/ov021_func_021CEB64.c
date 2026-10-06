/*
 * function: func_021CEB64
 * address:  0x021CEB64
 * packet:   pkt_ov021_021CEB64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021909BC  0x021909BC  thumb  ov021
 */
#include "../include/Obj07591.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021909BC(void *a);

void func_021CEB64(u8 *p)
{
    if (((struct Obj07591 *)p)->f140 != 0) {
        func_021909BC((void *)(((struct Obj07591 *)p)->f140));
        ((struct Obj07591 *)p)->f140 = 0;
        p[0x40e] = 0;
    }
}
