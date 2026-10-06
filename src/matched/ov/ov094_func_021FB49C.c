/*
 * function: func_021FB49C
 * address:  0x021FB49C
 * packet:   pkt_ov094_021FB49C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021FCF2C  0x021FCF2C  thumb  ov094
 *   func_021F8700  0x021F8700  thumb  ov094
 *   func_022097CC  0x022097CC  thumb  ov094
 */
#include "../include/Obj21663.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
extern int func_021FCF2C(int a, int b);
extern int func_021F8700(void);
extern void func_022097CC(int a, int b, int c, int d, int e, int f, int g, int h);

int func_021FB49C(struct Cursor *a, char *b)
{
    int t0, t1, t2, t3, t4, t5, v;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    t2 = func_0201134C(a);
    t3 = func_0201134C(a);
    t4 = func_0201134C(a);
    t5 = func_0201134C(a);
    v = func_021FCF2C((int)a, 14);
    func_022097CC(func_021F8700(), v, t0, t1, t2, t3, t4, t5);
    return ((struct Obj21663 *)b)->f23C;
}
