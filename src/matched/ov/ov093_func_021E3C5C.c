/*
 * unit:     yes
 * function: func_021E3C5C, func_021E3CA4
 * address:  0x021E3C5C
 * packet:   pkt_ov093_021E3C5C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D69AC  0x021D69AC  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F2FF8     0x021F2FF8  data   a4
 */
#include "../include/Obj06270.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void *func_021C7CF4(int *p, int i);
extern u8 *func_021C88A4(void *a, int k, int c);
extern unsigned char func_021D69AC(unsigned char *base, int idx);
extern void func_021C88C8(void *a, void *p);
extern int d_021F2FF8[];

void func_021E3C5C(void *a, int b, int c)
{
    void *q;
    u8 *p;

    q = func_021C7CF4(a, b);
    p = func_021C88A4(a, 0x26, b);
    p[6] = func_021D69AC(q, 3) + 1;
    p[4] = b;
    p[5] = 3;
    ((struct Obj06270 *)p)->f0 = (((struct Obj06270 *)p)->f0 & 0xfeffffff) | ((c & 1) << 24);
    func_021C88C8(a, p);
}

int *func_021E3CA4(int *p)
{
    *p = 7;
    return d_021F2FF8;
}
