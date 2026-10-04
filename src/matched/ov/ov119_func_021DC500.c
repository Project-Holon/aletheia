/*
 * function: func_021DC500
 * address: 0x021DC500
 * packet: pkt_ov119_021DC500
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A648 0x0204A648 arm
 *   func_02040618 0x02040618 arm
 */
#include "../include/Obj08059.h"
extern void func_0204A648(int);
typedef unsigned int   u32;
extern void func_02040618(u32 layer, u32 a, u32 b);
void func_021DC500(int a, char *p)
{
    func_0204A648(a);
    if (((struct Obj08059 *)p)->f1084) {
        func_02040618(7, 0, ((struct Obj08059 *)p)->f108C);
        func_02040618(5, 0, ((struct Obj08059 *)p)->f108C);
        ((struct Obj08059 *)p)->f1084 = 0;
    }
}
