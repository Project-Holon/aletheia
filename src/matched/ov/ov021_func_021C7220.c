/*
 * function: func_021C7220
 * address:  0x021C7220
 * packet:   pkt_ov021_021C7220
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021C6C70  0x021C6C70  thumb  ov021
 *   func_021C6CCC  0x021C6CCC  thumb  ov021
 *   func_021C7418  0x021C7418  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 */
#include "../include/Obj05087.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_02188C84(u8 *p);
extern void *func_021C6C70(u32 h, int size, void *fn);
extern u32 func_021C6CCC(u8 *p);
extern void func_021C7418(void);
extern u16 func_0216D5F8(void *p);

void *func_021C7220(u32 a, u16 b, int c, u32 d)
{
    void *o;
    u8 *p;

    o = func_021C6C70(func_02188C84((u8 *)a), 0x10, (void *)func_021C7418);
    p = (u8 *)func_021C6CCC(o);
    ((struct Obj05087 *)p)->f0 = a;
    ((struct Obj05087 *)p)->f4 = d;
    ((struct Obj05087 *)p)->f8 = 0;
    ((struct Obj05087 *)p)->fA = b;
    p[0xc] = c;
    ((struct Obj05087 *)p)->fE = func_0216D5F8((void *)d);
    return o;
}
