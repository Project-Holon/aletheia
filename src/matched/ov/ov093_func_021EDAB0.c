/*
 * function: func_021EDAB0
 * address:  0x021EDAB0
 * packet:   pkt_ov093_021EDAB0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EDA3C  0x021EDA3C  thumb  ov093
 *   func_021EDF4C  0x021EDF4C  thumb  ov093
 *   func_021F8504  0x021F8504  thumb  ov094
 */
#include "../include/Obj21611.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct W;
extern int func_021EDA3C(u8 *, u32);
extern void func_021EDF4C(u8 *);
extern void func_021F8504(u32, u32, u32);
void func_021EDAB0(u8 *p, u32 x)
{
    u8 k = func_021EDA3C(*(u8 * *)&((struct Obj21611 *)p)->f134, x);
    func_021EDF4C(p + 0x90 + k * 0x24);
    if (k == 0)
        func_021F8504(0, 1, 0);
}
