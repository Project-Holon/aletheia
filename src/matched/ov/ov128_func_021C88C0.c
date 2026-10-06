/*
 * function: func_021C88C0
 * address: 0x021C88C0
 * packet: pkt_ov128_021C88C0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02041090 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj23089.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_02041B6C(u32 bit);
void func_021C88C0(s16 *p, void *unused, u8 *q)
{
    int y = p[1];
    int x;
    u16 *t;
    if (y < 0) y = -y;
    x = p[0];
    if (x < 0) x = -x;
    t = *(u16 * *)&((struct Obj23089 *)q)->f8;
    func_02041090((int)2, (u32)((u8 *)t + 12), (u8)x, (u8)y, (t[0] >> 3) & 255, (t[1] >> 3) & 255);
    func_02041B6C(2);
}
