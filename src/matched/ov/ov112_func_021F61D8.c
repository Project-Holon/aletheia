/*
 * function: func_021F61D8
 * address: 0x021F61D8
 * packet: pkt_ov112_021F61D8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj04460.h"
typedef unsigned int u32;
extern void func_020307B0(void *);
void func_021F61D8(char *a, char *p)
{
    func_020307B0(((struct Obj04460 *)p)->f0);
    func_020307B0(((struct Obj04460 *)p)->f10);
    func_020307B0(((struct Obj04460 *)p)->f8);
    func_020307B0(((struct Obj04460 *)p)->f18);
    func_020307B0(((struct Obj04460 *)p)->f8C);
    func_020307B0(((struct Obj04460 *)p)->f20);
    (*(u32 **)(a+4))[((struct Obj04460 *)p)->fF0] = 0;
    func_020307B0(p);
}
