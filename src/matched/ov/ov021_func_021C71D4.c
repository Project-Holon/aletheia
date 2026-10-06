/*
 * function: func_021C71D4
 * address:  0x021C71D4
 * packet:   pkt_ov021_021C71D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021C6C70  0x021C6C70  thumb  ov021
 *   func_021C6CCC  0x021C6CCC  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021C7418  0x021C7418  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05086.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_02188C84(u8 *p);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021C6C70(u32 heap, u32 n, void *cb);
extern u32 func_021C6CCC(u8 *p);
extern void *func_021A3074(unsigned char *p);
extern u16 func_0216D5F8(void *a);
extern void func_021C7418(void);

void *func_021C71D4(u32 a, u32 b, u32 c)
{
    u32 heap = func_02188C84((u8 *)a);
    void *x = func_02188CB4((void *)a);
    void *r = func_021C6C70(heap, 0x10, (void *)func_021C7418);
    u8 *e = (u8 *)func_021C6CCC(r);
    void *t;

    ((struct Obj05086 *)e)->f0 = a;
    t = func_021A3074((void *)x);
    ((struct Obj05086 *)e)->f4 = t;
    ((struct Obj05086 *)e)->f8 = 0;
    ((struct Obj05086 *)e)->fA = b;
    e[12] = c;
    ((struct Obj05086 *)e)->fE = func_0216D5F8(t);
    return r;
}
