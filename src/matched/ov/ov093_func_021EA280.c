/*
 * function: func_021EA280
 * address:  0x021EA280
 * packet:   pkt_ov093_021EA280
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E9100  0x021E9100  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 */
#include "../include/Obj06283.h"
#include "../include/Obj13557.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *func_021E9100(u8 *p, int n);
extern int func_021B8D8C(void *p, void *a, u32 b);

void func_021EA280(char *ctx, u8 n, int b, const u8 *c, u16 e)
{
    u8 *t;
    u32 i;

    t = func_021E9100((u8 *)ctx, 0x14);
    ((struct Obj06283 *)t)->fC = b;
    t[6] = n;
    ((struct Obj06283 *)t)->f10 = e;
    ((struct Obj06283 *)t)->f8 = 0;
    for (i = 0; i < n; i++) {
        t[i] = func_021B8D8C(((struct Obj13557 *)ctx)->f0, ((struct Obj13557 *)ctx)->f8, c[i]);
    }
}
