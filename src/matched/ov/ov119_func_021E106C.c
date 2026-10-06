/*
 * function: func_021E106C
 * address: 0x021E106C
 * packet: pkt_ov119_021E106C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj05330.h"
typedef unsigned char  u8;
struct Descriptor;
extern void func_0202F038(u8 *p);
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);
void func_021E106C(char *p)
{
    if (((struct Obj05330 *)p)->f5F0) {
        func_0202F038(((struct Obj05330 *)p)->f5F0);
        ((struct Obj05330 *)p)->f5F0 = 0;
    }
    if (((struct Obj05330 *)p)->f71C) {
        func_020452E8(((struct Obj05330 *)p)->f71C);
        ((struct Obj05330 *)p)->f71C = 0;
    }
}
