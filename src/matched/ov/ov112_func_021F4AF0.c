/*
 * function: func_021F4AF0
 * address: 0x021F4AF0
 * packet: pkt_ov112_021F4AF0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4F74 0x021F4F74 thumb ov112
 */
#include "../include/Obj22518.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021F4F74(u16 *, int);
int func_021F4AF0(u8 *p, int index)
{
    return func_021F4F74(*(u16 * *)&((struct Obj22518 *)p)->f20, index);
}
