/*
 * function: func_021BC390
 * address: 0x021BC390
 * packet: pkt_ov093_021BC390
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021BC3AE, then matched func_021BC3B0.
 * symbols:
 *   func_021BC3B0 0x021BC3B0 thumb ov093
 */
#include "../include/Obj05189.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BC3B0(int *);
int func_021BC390(u8 *p)
{
    int result = 0;
    u32 *out = *(u32 * *)&((struct Obj05189 *)p)->fC;
    out[0] = 0;
    out[1] = 0;
    func_021BC3B0((int *)p);
    if (**(u32 * *)&((struct Obj05189 *)p)->fC) result = 1;
    return result;
}
