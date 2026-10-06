/*
 * function: func_021DFD64
 * address:  0x021DFD64
 * packet:   pkt_ov119_021DFD64
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02005E9C  0x02005E9C  thumb
 */
#include "../include/Obj22749.h"

typedef unsigned char u8;

extern int func_02005E9C(void);

void func_021DFD64(void *p)
{
    u8 *b = p;

    func_02005E9C();
    ((struct Obj22749 *)b)->f11F8 -= 1;
}
