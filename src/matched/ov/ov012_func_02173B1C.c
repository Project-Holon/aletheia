/*
 * function: func_02173B1C
 * address: 0x02173B1C
 * packet: pkt_ov012_02173B1C
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012950 0x02012950 thumb
 *   func_02008494 0x02008494 thumb
 */
#include "../include/Obj12445.h"
#include "../include/Obj19250.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Sub24;
struct Rec44;
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern void func_02008494(void *src, void *dst);
void func_02173B1C(u32 a, int b, void *c, u8 *p)
{
    func_02008494(c, func_02012950(*(struct Sub24 * *)&((struct Obj19250 *)(*(u8 * *)&((struct Obj12445 *)p)->f0))->f8, a));
    p[0x288b] |= (u8)(1 << a);
}
