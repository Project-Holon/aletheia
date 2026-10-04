/*
 * function: func_021CA248
 * address: 0x021CA248
 * packet: pkt_ov093_021CA248
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021C1D60 0x021C1D60 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021B9934(char *p, int i);
extern int func_021C1D60(u8 *, u8 *, u32);
u8 func_021CA248(u8 *p, const u8 *q)
{
    u8 r;
    if (func_021C1D60(p, func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[4]), q[5])) r = 1;
    else r = 0;
    return r;
}
