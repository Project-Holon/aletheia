/*
 * function: func_0202AE9C
 * address:  0x0202AE9C
 * packet:   pkt_0202AE68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Blocked: call target func_0202AF34 is unlabelled and unmatched (it lives in
 * another lane's packet, pkt_0202AF34). Every concrete byte reproduces.
 * status:   EXACT*
 */
#include "../include/Obj15818.h"

typedef unsigned int u32;

extern int func_0202AD78(int a0);
struct Rec44;
struct Vec12;
extern struct Vec12 *func_02012AA0(struct Rec44 *p);
extern void func_0202AF34(int a, u32 b);

void func_0202AE9C(void *p)
{
    int a = func_0202AD78((int)p);

    func_0202AF34(a, (u32)func_02012AA0((struct Rec44 *)(((struct Obj15818 *)p)->f0)));
}
