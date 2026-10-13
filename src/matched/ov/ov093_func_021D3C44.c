/*
 * function: func_021D3C44
 * address: 0x021D3C44
 * packet: pkt_ov093_021D3C44
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: narrow extern arguments follow explicit caller truncation.
 * symbols:
 *   BTL_CLIENT_AddPoints 0x021CD9F4 thumb ov093
 *   func_021B9B10 0x021B9B10 thumb ov093
 */
#include "../include/Obj06231.h"
typedef unsigned char u8;
extern void BTL_CLIENT_AddPoints(u8 *p, u8 n);
extern void func_021B9B10(u8 *, u8, int);
int func_021D3C44(u8 *p, int unused, unsigned int *a)
{
    u8 index = a[0];
    u8 value = a[1];
    if (index == p[0x1a6]) BTL_CLIENT_AddPoints(p, value);
    else func_021B9B10(*(u8 * *)&((struct Obj06231 *)p)->f0, index, value);
    return 1;
}
