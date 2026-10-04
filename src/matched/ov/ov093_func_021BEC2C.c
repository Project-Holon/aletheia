/*
 * function: func_021BEC2C
 * address: 0x021BEC2C
 * packet: pkt_ov093_021BEC2C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BEC08 0x021BEC08 thumb ov093
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 */
#include "../include/Obj09965.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BEC08(u8 *,u8 *);
extern void func_021BA1B4(u8 *,int);
void func_021BEC2C(u8 *p,u8 *a,int c)
{
    if(func_021BEC08(p,a)) {
        if(c==150) func_021BA1B4(*(u8 * *)&((struct Obj09965 *)p)->f4,73);
        else if(c==165) func_021BA1B4(*(u8 * *)&((struct Obj09965 *)p)->f4,74);
    }
}
