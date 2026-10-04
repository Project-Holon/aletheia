/*
 * function: func_021B841C
 * address: 0x021B841C
 * packet: pkt_ov067_021B841C
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj09864.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
int func_021B841C(u8 *p, int n)
{
    if (n < 0) return ((struct Obj09864 *)p)->f62;
    return ((struct Obj09864 *)p)->f64 - ((struct Obj09864 *)p)->f62;
}
