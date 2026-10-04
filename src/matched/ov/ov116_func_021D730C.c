/*
 * function: func_021D730C
 * address: 0x021D730C
 * packet: pkt_ov116_021D730C
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202E54C 0x0202E54C thumb
 */
#include "../include/Obj10340.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj0202E54C;
extern void func_0202E54C(struct Obj0202E54C *p);
void func_021D730C(u8 *p)
{
    if (((struct Obj10340 *)p)->f1840) {
        func_0202E54C(((struct Obj10340 *)p)->f1840);
        ((struct Obj10340 *)p)->f1840 = 0;
    }
}
