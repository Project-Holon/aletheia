/*
 * function: func_021B4C98
 * address:  0x021B4C98
 * packet:   pkt_ov021_021B4C98
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
 *   func_0201210C  0x0201210C  thumb
 *   func_020124AC  0x020124AC  thumb
 *   abs_id_4       0x00000004  data
 *   func_021542C0  0x021542C0  thumb  ov000
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 a;
    u32 b;
} Pair;

extern u8 abs_id_4[];
extern u32 func_0215A5F4(u32 a);
extern u32 func_0215A5DC(u32 a);
extern void func_0215897C(u32 a, u32 b);
extern u32 func_0201210C(u32 a);
extern u32 func_020124AC(u32 a, const void *b, void *c, Pair *d);
extern void func_021542C0(void);

int func_021B4C98(u32 a, u32 b)
{
    Pair p;
    u32 r5;
    u32 r4;

    r5 = func_0215A5F4(b);
    r4 = func_0215A5DC(b);
    p.a = func_0201210C(r4);
    p.b = 0;
    func_0215897C(r5, func_020124AC(r4, abs_id_4, (void *)func_021542C0, &p));
    return 1;
}
