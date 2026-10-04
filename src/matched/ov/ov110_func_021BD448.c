/*
 * function: func_021BD448
 * address: 0x021BD448
 * packet: pkt_ov110_021BD448
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02082D44 0x02082D44 arm
 */
#include "../include/Obj22378.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_02082D44(const void *,void *,u32);
void func_021BD448(u8 *p,int i)
{
    func_0204B6F4(*(void **)(p+i*4+0x70),2,1);
    func_02082D44(p+0x98,p+0xac,10);
    ((struct Obj22378 *)p)->fB8=0;
}
