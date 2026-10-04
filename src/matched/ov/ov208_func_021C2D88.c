/*
 * function: func_021C2D88
 * address: 0x021C2D88
 * packet: pkt_ov208_021C2D88
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
#include "../include/Obj05541.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
void func_021C2D88(void *unused, u8 *p)
{
    u8 i;
    for (i = 0; i < 7; i++)
        func_0204B3B4(*(struct Obj **)(p + i * 4 + 0x9c));
    func_0204ADA4(((struct Obj05541 *)p)->f88);
    func_0204A8D4(((struct Obj05541 *)p)->f84);
    func_0204AFD8(((struct Obj05541 *)p)->f8C);
    func_0204ADA4(((struct Obj05541 *)p)->f94);
    func_0204A8D4(((struct Obj05541 *)p)->f90);
    func_0204AFD8(((struct Obj05541 *)p)->f98);
}
