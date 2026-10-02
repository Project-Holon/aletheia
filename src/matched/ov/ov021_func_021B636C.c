/*
 * function: func_021B636C
 * address:  0x021B636C
 * packet:   pkt_ov021_021B636C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A2E4  0x0215A2E4  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 * func_0215A2E4's prototype is copied from its matched source
 * (ov010_func_0215A2E4.c: last parameter unsigned short). With that
 * parameter fed from a u16 local (func_02159B10 returning u16), the third
 * stack store lands before the r2/r3 reloads; a u32 local needs a
 * narrowing and schedules it after them.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *func_02159AE8(void *a0, void *a1);
extern u16 func_02159B10(u32 a, u32 b);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(void *p);
extern int func_0215A2E4(int a, int b, int c, u16 *d, u16 *e, int f, unsigned short g);
extern void func_0215897C(u32 a, u32 b);

int func_021B636C(u32 a, u32 b)
{
    u16 *t10;
    u16 *t6;
    u16 tc;
    u16 t4;
    void *p7;
    void *p5;

    t10 = func_02159AE8((void *)a, (void *)b);
    t6 = func_02159AE8((void *)a, (void *)b);
    tc = func_02159B10(a, b);
    t4 = func_02159B10(a, b);
    p7 = func_0215A5F4((void *)b);
    p5 = func_0215A5DC((void *)b);
    func_0215897C(p7, func_0215A2E4(p5, func_0201210C(), tc, t10, t6, t4 == 0, t4));
    return 1;
}
