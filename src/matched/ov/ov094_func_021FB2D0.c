/*
 * function: func_021FB2D0
 * address:  0x021FB2D0
 * packet:   pkt_ov094_021FB2D0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021FCF2C  0x021FCF2C  thumb  ov094
 *   func_021F7F58  0x021F7F58  thumb  ov094
 */
#include "../include/Obj13586.h"
extern int func_0201134C(int a);
extern int func_021FCF2C(int a, int b);
typedef unsigned int   u32;
extern void func_021F7F58(int a, u32 b, u32 c, u32 d, u32 e);

int func_021FB2D0(int a, char *b)
{
    int t0, t1, t2, t3, t4;

    t0 = func_0201134C(a);
    t1 = func_021FCF2C(a, func_0201134C(a));
    t2 = func_0201134C(a);
    t3 = func_0201134C(a);
    t4 = func_0201134C(a);
    if (t0 == -1)
        t0 = ((struct Obj13586 *)b)->f4;
    func_021F7F58(t0, t1, t2, t3, t4);
    return ((struct Obj13586 *)b)->f23C;
}
