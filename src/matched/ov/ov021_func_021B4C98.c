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
 *   func_021542C0  0x021542C0  thumb  ov004
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    void *a;
    u32 b;
} Pair;

extern u8 abs_id_4[];
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void func_0215897C(void *a, void *b);
struct Ctx;
struct Pair;
extern void *func_0201210C(const struct Ctx *p);
struct Desc;
extern struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern int func_021542C0(int x, struct Pair *p);

int func_021B4C98(u32 a, u32 b)
{
    Pair p;
    void *r5;
    void *r4;

    r5 = func_0215A5F4((void *)b);
    r4 = func_0215A5DC((void *)b);
    p.a = func_0201210C((void *)r4);
    p.b = 0;
    func_0215897C(r5, func_020124AC(r4, (u32)abs_id_4, (void *)func_021542C0, (u32)(&p)));
    return 1;
}
