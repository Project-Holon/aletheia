/*
 * function: func_021BB120
 * address: 0x021BB120
 * packet: pkt_ov068_021BB120
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj13145.h"
typedef unsigned char u8;
typedef void (*Callback)(void *, void *, int);
void func_021BB120(u8 *p)
{
    if (((struct Obj13145 *)p)->f4 == 0)
        (*(Callback *)p)(p, p + 8, ((struct Obj13145 *)p)->fC);
}
