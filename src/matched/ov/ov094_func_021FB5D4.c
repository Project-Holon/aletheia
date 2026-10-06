/*
 * function: func_021FB5D4
 * address:  0x021FB5D4
 * packet:   pkt_ov094_021FB5D4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021F8298  0x021F8298  thumb  ov094
 */
#include "../include/Obj21666.h"
typedef unsigned char u8;
typedef unsigned short u16;

extern int func_0201134C(int a);
typedef unsigned int   u32;
extern void func_021F8298(u32 a, u8 b, u8 c, u8 d, u16 e);

int func_021FB5D4(int a, char *b)
{
    int t0, t1, t2, t3, t4;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    t2 = func_0201134C(a);
    t3 = func_0201134C(a);
    t4 = func_0201134C(a);
    func_021F8298(t0, t1, t2, t3, t4);
    return ((struct Obj21666 *)b)->f23C;
}
