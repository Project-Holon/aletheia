/*
 * function: func_021B4E58
 * address:  0x021B4E58
 * packet:   pkt_ov021_021B4E58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_021CD2A4  0x021CD2A4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void func_0215897C(void *a, void *b);
extern unsigned short *func_02159AE8(void *a0, void *a1);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_021CD2A4(void *a, void *b, u32 c, u32 d, void *e);

int func_021B4E58(u32 a, u32 b)
{
    void *r6;
    void *r7;
    void *z;

    r6 = func_0215A5F4((void *)b);
    r7 = func_0215A5DC((void *)b);
    z = func_0201210C((void *)r7);
    func_0215897C(r6, func_021CD2A4(r7, z, 0, 5, func_02159AE8((void *)a, (void *)b)));
    return 1;
}
