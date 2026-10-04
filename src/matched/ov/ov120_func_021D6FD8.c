/*
 * function: func_021D6FD8
 * address: 0x021D6FD8
 * packet: pkt_ov120_021D6FD8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_0204B92C 0x0204B92C arm
 */
#include "../include/Obj10395.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
struct Actor;
struct Obj;
extern void func_0204B9A0(struct Actor *a);
extern void func_0204B92C(struct Obj *p, u32 v);
void func_021D6FD8(u8 *p, u32 flag)
{
    if (((struct Obj10395 *)p)->f140 != 0) {
        func_0204B9A0(((struct Obj10395 *)p)->f140);
        func_0204B92C(((struct Obj10395 *)p)->f140, flag);
    }
}
