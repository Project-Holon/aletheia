/*
 * function: func_021B654C
 * address:  0x021B654C
 * packet:   pkt_ov021_021B654C
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
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_021CC500  0x021CC500  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern u32 func_02159B10(void *, void *);
extern void func_0215897C(void *vm, void *task);
extern void *func_021CC500(void *a, u32 b, u32 c);

u32 func_021B654C(void *a, void *b)
{
    void *r7 = func_0215A5F4(b);
    void *x = func_0215A5DC(b);
    u32 t = func_02159B10(a, b);
    u32 u = func_02159B10(a, b);
    func_0215897C(r7, func_021CC500(x, (u8)t, (u8)u));
    return 1;
}
