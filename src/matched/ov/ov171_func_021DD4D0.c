/*
 * function: func_021DD4D0
 * address: 0x021DD4D0
 * packet: pkt_ov171_021DD4D0
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202208C 0x0202208C thumb
 */
#include "../include/Obj24054.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
int func_021DD4D0(u8 *p,u32 value)
{
    func_0202208C(0,0,0,0,6,1,140);
    ((struct Obj24054 *)p)->fC74=value;
    return 2;
}
