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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_02188C84(u8 *p);
extern void *func_02188CB4(unsigned char *p);
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

    *(u32 *)e = a;
    t = func_021A3074((void *)x);
    *(void **)(e + 4) = t;
    *(u16 *)(e + 8) = 0;
    *(u16 *)(e + 10) = b;
    e[12] = c;
    *(u16 *)(e + 14) = func_0216D5F8(t);
    return r;
}
