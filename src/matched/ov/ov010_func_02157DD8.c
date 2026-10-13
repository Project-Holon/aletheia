/*
 * function: DELIVERY_IRC_Create
 * address: 0x02157DD8
 * packet: pkt_ov010_02157DD8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082D44 0x02082D44 arm
 *   d_02172878 0x02172878 data a1
 */
#include "../include/Obj18743.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02082D44(void *, void *, u32);
extern const char d_02172878[];
void *DELIVERY_IRC_Create(u8 *p)
{
    void *q = func_02030734(((struct Obj18743 *)p)->f6, 0x684, 1, d_02172878, 0x1CD);
    func_02082D44(p, q, 0x7C);
    return q;
}
