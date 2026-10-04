/*
 * function: func_021C7178
 * address:  0x021C7178
 * packet:   pkt_ov136_021C7178
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0202208C   0x0202208C  thumb
 */
#include "../include/Obj23637.h"
#include "../include/Obj23638.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
int func_021C7178(u8 *p, u32 v)
{
    func_0202208C((void *)0, 0, 0, 0, 6, 1, 0x66);
    ((struct Obj23638 *)(*(u8 * *)&((struct Obj23637 *)p)->f8))->f308 = v;
    return 2;
}
