/*
 * function: func_021B2890
 * address:  0x021B2890
 * packet:   pkt_ov021_021B2890
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
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012984  0x02012984  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 * func_021BE92C reads its last two stack arguments with ldrb, so they are
 * u8 parameters: the narrowing then happens once at the call, scheduled
 * the way the original has it. A (u8) cast at the call site or a u8 local
 * feeding int parameters schedules the zero store after the shift pair.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern u32 func_020120F4(void);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02012984(u32 a);
extern u32 func_021BE92C(void *a, void *b, int c, int d, int e, u8 f, u8 g);
extern void func_0215897C(void *a, u32 b);

int func_021B2890(u32 a, u32 b)
{
    void *x;
    void *y;
    u32 p;
    void *q;
    u32 z;

    x = func_0215A5F4((void *)b);
    y = func_0215A5DC((void *)b);
    p = func_020120F4();
    q = func_0201210C((void *)y);
    z = func_02012984(p);
    func_0215897C(x, func_021BE92C(y, q, 3, 0, 0, z, z));
    return 0;
}
