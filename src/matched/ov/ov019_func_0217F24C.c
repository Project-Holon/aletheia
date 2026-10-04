/*
 * function: func_0217F24C
 * address: 0x0217F24C
 * packet: pkt_ov019_0217F24C
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021909BC 0x021909BC thumb ov021
 */
#include "../include/Obj00033.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021909BC(u32 a);
void func_0217F24C(u8 *p)
{
    if (((struct Obj00033 *)p)->f2814 != 0) {
        func_021909BC((u32)(((struct Obj00033 *)p)->f2814));
        ((struct Obj00033 *)p)->f2814 = 0;
    }
}
