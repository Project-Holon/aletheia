/*
 * function: func_021EDB20
 * address:  0x021EDB20
 * packet:   pkt_ov093_021EDB20
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EDA3C  0x021EDA3C  thumb  ov093
 *   func_021EDFC4  0x021EDFC4  thumb  ov093
 */
#include "../include/Obj21614.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021EDA3C(u8 *, u32);
extern int func_021EDFC4(u8 *);
void func_021EDB20(u8 *p, u32 x)
{
    func_021EDFC4(p + 0x90 + func_021EDA3C(*(u8 * *)&((struct Obj21614 *)p)->f134, x) * 0x24);
}
