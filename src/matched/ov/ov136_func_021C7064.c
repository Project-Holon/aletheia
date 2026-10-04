/*
 * function: func_021C7064
 * address:  0x021C7064
 * packet:   pkt_ov136_021C7064
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C66B8 0x021C66B8 thumb
 *   func_021C714C 0x021C714C thumb
 *   func_021C7298 0x021C7298 thumb
 */
#include "../include/Obj10608.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C66B8(u8 *, int, u32);
extern void func_021C7298(void *p, int v);
extern int func_021C714C(u8 *p, u32 v);
void func_021C7064(u8 *p)
{
    func_021C66B8(*(u8 * *)&((struct Obj10608 *)p)->f8, 2, 0);
    func_021C7298(*(u8 * *)&((struct Obj10608 *)p)->f8, 1);
    func_021C714C(p, 0x16);
}
