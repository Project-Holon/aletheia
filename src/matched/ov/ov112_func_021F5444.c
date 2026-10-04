/*
 * function: func_021F5444
 * address: 0x021F5444
 * packet: pkt_ov112_021F5444
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F6230 0x021F6230 thumb ov112
 */
#include "../include/Obj22542.h"
typedef unsigned char u8;
extern void func_021F6230(u8 *, int);
void func_021F5444(u8 *p, int a)
{
    func_021F6230(*(u8 * *)&((struct Obj22542 *)p)->f4, a);
}
