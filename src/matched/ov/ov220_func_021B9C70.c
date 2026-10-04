/*
 * function: func_021B9C70
 * address: 0x021B9C70
 * packet: pkt_ov220_021B9C70
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 */
#include "../include/Obj01297.h"
struct Obj;
extern void func_0204B3B4(struct Obj *);
extern void func_0204AFD8(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
void func_021B9C70(unsigned char *p)
{
    unsigned char i;
    if(p[0x84]) {
        for(i=0;i<p[0x84];i++) func_0204B3B4(*(struct Obj **)(p+0x94+4*i));
        func_0204AFD8(((struct Obj01297 *)p)->f90);
        func_0204A8D4(((struct Obj01297 *)p)->f88);
        func_0204ADA4(((struct Obj01297 *)p)->f8C);
    }
}
