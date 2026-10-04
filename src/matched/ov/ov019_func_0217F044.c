/*
 * function: func_0217F044
 * address: 0x0217F044
 * packet: pkt_ov019_0217F044
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201ED04 0x0201ED04 thumb
 */
#include "../include/Obj09417.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WordSet;
extern void func_0201ED04(struct WordSet *p);
void func_0217F044(u8 *p)
{
    if (((struct Obj09417 *)p)->f2804 != 0) {
        func_0201ED04(((struct Obj09417 *)p)->f2804);
        ((struct Obj09417 *)p)->f2804 = 0;
    }
}
