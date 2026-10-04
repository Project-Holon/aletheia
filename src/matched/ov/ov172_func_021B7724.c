/*
 * function: func_021B7724
 * address: 0x021B7724
 * packet: pkt_ov172_021B7724
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj06553.h"
typedef unsigned char u8;
void func_021B7724(void *a, char *b, int c)
{
    int m;
    if (((struct Obj06553 *)b)->f14 == 0) {
        m = 1 << c;
        if (((struct Obj06553 *)b)->f10 & m)
            ((struct Obj06553 *)b)->f10 -= (u8)m;
    }
}
