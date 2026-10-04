/*
 * function: func_021BF528
 * address: 0x021BF528
 * packet: pkt_ov204_021BF528
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020200CC 0x020200CC thumb
 */
#include "../include/Obj14624.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern int func_020200CC(struct Obj *);
void func_021BF528(u8 *p)
{
    u8 *q=p+36;
    ((struct Obj14624 *)q)->f8=func_020200CC(*(struct Obj * *)&((struct Obj14624 *)q)->f0);
}
