/*
 * function: func_021B4FB0
 * address:  0x021B4FB0
 * packet:   pkt_ov021_021B4FB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_021C5BD0  0x021C5BD0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void func_0215897C(void *a, void *b);
extern unsigned short *func_02159AE8(void *a0, void *a1);
extern unsigned int func_02159B10(void *a, void *b);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
struct Big;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_021C5BD0(void *a, u32 b, void *c);

int func_021B4FB0(u32 a, u32 b)
{
    void *r0;
    void *r7;
    u32 r4;
    unsigned short *x;
    u32 y;

    r0 = func_0215A5F4((void *)b);
    r7 = func_0215A5DC((void *)b);
    func_02012EBC(func_020120F4(r7));
    func_0201210C((void *)r7);
    r4 = func_02159B10((void *)a, (void *)b);
    x = func_02159AE8((void *)a, (void *)b);
    if (r4 == 0 || r4 != 1)
        y = 0;
    else
        y = 1;
    func_0215897C(r0, func_021C5BD0(r7, y, x));
    return 1;
}
