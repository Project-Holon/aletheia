/*
 * function: func_021D909C
 * address: 0x021D909C
 * packet: pkt_ov131_021D909C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj04510.h"
typedef unsigned char u8;
struct Descriptor;
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);
void func_021D909C(u8 *a,u8 *p)
{
    ((struct Obj04510 *)p)->f0=0;
    if(((struct Obj04510 *)p)->f20!=0) {
        func_020452E8(((struct Obj04510 *)p)->f20);
        ((struct Obj04510 *)p)->f20=0;
    }
    if(((struct Obj04510 *)p)->f24!=0) {
        func_020452E8(((struct Obj04510 *)p)->f24);
        ((struct Obj04510 *)p)->f24=0;
    }
}
