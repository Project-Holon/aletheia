/*
 * function: func_02180080
 * address:  0x02180080
 * packet:   pkt_02180080
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Destructor: releases three optional sub-objects then the object itself, and
 * always reports success.
 *
 * symbols:
 *   func_02181DA0  0x02181DA0  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_021C2324  0x021C2324  arm  ov114
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_02181DA0(int x);
void func_0217EAE0(void *p);
void func_021C2324(int x, int y);

int func_02180080(int *p)
{
    if (p[5])
        func_02181DA0(p[5]);
    if (p[6])
        func_0217EAE0((void *)p[6]);
    if (p[7])
        func_021C2324(p[10], p[7]);
    func_0217EAE0((void *)((int)p));
    return 1;
}
