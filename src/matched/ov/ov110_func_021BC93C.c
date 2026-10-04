/*
 * function: func_021BC93C, func_021BC964
 * unit: yes
 * address: 0x021BC93C
 * packet: pkt_ov110_021BC93C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: callback func_021BC964 included in unit; function_starts seed.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_0207D658 0x0207D658 arm
 */
#include "../include/Obj04448.h"
#include "../include/Obj08003.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_0207D658(u32 addr, int plane, int brightness);
int func_021BC93C(u8 *p)
{
    if (((struct Obj08003 *)p)->f18==0) {
        if (((struct Obj08003 *)p)->f14==0) {
            func_02030EAC(((struct Obj08003 *)p)->f1C);
            ++((struct Obj08003 *)p)->f18;
            return 1;
        }
    } else return 1;
    return 0;
}
void func_021BC964(void *unused,u8 *p)
{
    int value;
    if (((struct Obj04448 *)p)->f14) {
        ((struct Obj04448 *)p)->f8+=((struct Obj04448 *)p)->f10;
        value=((struct Obj04448 *)p)->f8>>12;
        --((struct Obj04448 *)p)->f14;
    } else value=((struct Obj04448 *)p)->fC>>12;
    func_0207D658(0x4000050,((struct Obj04448 *)p)->f0,value);
}
