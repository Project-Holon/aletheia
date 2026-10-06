/*
 * function: func_0216CF6C
 * address:  0x0216CF6C
 * packet:   pkt_ov010_0216CF6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D948  0x0216D948  thumb  ov010
 *   func_0216D76C  0x0216D76C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D508  0x0216D508  thumb  ov010
 *   func_0216E180  0x0216E180  thumb  ov010
 */
#include "../include/Obj00113.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Rec;
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_0216D948(int a0);
extern void func_0216D76C(void *a0);
extern int func_0216D55C(int a0, int a1);
extern void func_0216D508(u32 v);
extern void func_0216E180(void *a0);

void func_0216CF6C(u32 x)
{
    int n;
    u8 *o;
    u32 k = 2;

    n = 0;
    while (func_0216DD1C((struct Ctx *)x, (struct Rec **)(&o), (u32 *)(&n))) {
        if (func_0216D948(x) == 1)
            func_0216D76C(o);
        func_0216D55C((int)o, k);
        func_0216D508(*(u32 *)&((struct Obj00113 *)o)->f88);
        func_0216E180(o);
    }
}
