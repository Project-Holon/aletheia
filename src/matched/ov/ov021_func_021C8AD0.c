/*
 * function: func_021C8AD0
 * address:  0x021C8AD0
 * packet:   pkt_ov021_021C8AD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C8A9C  0x021C8A9C  thumb  ov021
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   _u32_div_f     0x0209C2B0  arm
 */
#include "../include/Obj00876.h"

typedef unsigned int   u32;
extern int func_021C8A9C(u32 a);
extern void func_0216D550(u32 *p, u32 v);
extern void func_0216D5E0(int a, int b);
extern void func_0216D548(u32 *p, u32 v);

void func_021C8AD0(char *p)
{
    int d = func_021C8A9C((u32)p);

    ((struct Obj00876 *)p)->f18 = ((struct Obj00876 *)p)->f18 + 1;
    if (((struct Obj00876 *)p)->f18 % d == 0) {
        ((struct Obj00876 *)p)->f14 = (((struct Obj00876 *)p)->f14 + 1) % 4;
        func_0216D550((u32 *)(*(int *)&((struct Obj00876 *)p)->fC), 8);
        func_0216D5E0(*(int *)&((struct Obj00876 *)p)->fC, ((struct Obj00876 *)p)->f14);
        func_0216D548((u32 *)(*(int *)&((struct Obj00876 *)p)->fC), 8);
    }
}
