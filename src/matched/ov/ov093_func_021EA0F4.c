/*
 * function: func_021EA0F4
 * address:  0x021EA0F4
 * packet:   pkt_ov093_021EA0F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9100  0x021E9100  thumb  ov093
 *   func_021EA160  0x021EA160  thumb  ov093
 */
#include "../include/Obj07842.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 pad00[0x1c];
    u32 f1c;
    u32 f20;
    void *f24;
    int f28;
};

extern u8 *func_021E9100(u8 *p, int n);
extern int func_021EA160(int *st, char *ctx);

void func_021EA0F4(struct S *s, u32 a, u32 b, u32 c)
{
    u8 *t;

    t = func_021E9100((u8 *)s, 0xc);
    ((struct Obj07842 *)t)->f4 = c;
    t[0xa] = b;
    ((struct Obj07842 *)t)->f8 = 0;
    ((struct Obj07842 *)t)->f0 = a;
    s->f1c = 0;
    s->f20 = (u32)func_021EA160;
    s->f24 = s;
    s->f28 = 0;
}
