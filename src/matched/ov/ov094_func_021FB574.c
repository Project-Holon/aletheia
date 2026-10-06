/*
 * function: func_021FB574
 * address:  0x021FB574
 * packet:   pkt_ov094_021FB574
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0207D63C  0x0207D63C  arm
 */
#include "../include/Obj13588.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
extern void func_0207D63C(int reg, int a, int b, int c, int d);

int func_021FB574(struct Cursor *a, unsigned int *b)
{
    int t2;

    func_0201134C(a);
    func_0201134C(a);
    t2 = func_0201134C(a);
    func_0201134C(a);
    func_0201134C(a);
    func_0201134C(a);
    if (t2 == 0x1f)
        func_0207D63C(0x04000050, 2, 0x3d, 0x1f, 7);
    else
        func_0207D63C(0x04000050, 10, 0x35, 0x1f, t2);
    *b |= 0x20;
    return ((struct Obj13588 *)b)->f23C;
}
