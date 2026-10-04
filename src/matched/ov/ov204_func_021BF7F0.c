/*
 * function: func_021BF7F0
 * address: 0x021BF7F0
 * packet: pkt_ov204_021BF7F0
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02016374 0x02016374 thumb
 */
#include "../include/Obj10882.h"
typedef unsigned char u8;
extern void func_02016374(void *);
void func_021BF7F0(u8 *p)
{
    ((struct Obj10882 *)p)->f4=1;
    if(((struct Obj10882 *)p)->f8==1)func_02016374(((struct Obj10882 *)p)->f0);
}
