/*
 * function: func_021C66C8
 * address: 0x021C66C8
 * packet: pkt_ov208_021C66C8
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
#include "../include/Obj03368.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
void func_021C66C8(void *unused,u8 *p)
{
    u8 i;
    for(i=0;i<4;i++)func_0204B3B4(*(struct Obj **)(p+i*0x28+0x618));
    for(i=0;i<4;i++)func_0204B3B4(*(struct Obj **)(p+i*4+0x5e4));
    func_0204ADA4(((struct Obj03368 *)p)->f5C4);
    func_0204A8D4(((struct Obj03368 *)p)->f5C0);
    func_0204AFD8(((struct Obj03368 *)p)->f5C8);
    func_0204ADA4(((struct Obj03368 *)p)->f5D0);
    func_0204A8D4(((struct Obj03368 *)p)->f5CC);
    func_0204AFD8(((struct Obj03368 *)p)->f5D4);
    func_0204ADA4(((struct Obj03368 *)p)->f5DC);
    func_0204A8D4(((struct Obj03368 *)p)->f5D8);
    func_0204AFD8(((struct Obj03368 *)p)->f5E0);
}
