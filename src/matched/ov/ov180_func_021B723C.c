/*
 * unit: yes
 * function: func_021B723C, func_021B7268
 * address: 0x021B723C
 * packet: pkt_ov180_021B723C
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 0x021B7268 store-return stub included in this verified unit.
 * symbols:
 *   func_0202208C 0x0202208C thumb
 */
#include "../include/Obj00299.h"
#include "../include/Obj24489.h"
typedef unsigned int   u32;
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
int func_021B723C(char *p,int value,int duration) {
    func_0202208C(0,0,0,0,duration,1,141);
    ((struct Obj24489 *)p)->f9194=value;
    return 2;
}
int func_021B7268(char *p,int value) {
    ((struct Obj00299 *)p)->f9188=value;
    ((struct Obj00299 *)p)->f9194=((struct Obj00299 *)p)->f918C;
    return 3;
}
