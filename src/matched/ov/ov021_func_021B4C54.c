/*
 * function: func_021B4C54
 * address:  0x021B4C54
 * packet:   pkt_ov021_021B4C54
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
 *   abs_id_6       0x00000006  data
 *   func_02154C20  0x02154C20  thumb  ov006
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 a;
    u32 b;
} Pair;

extern u8 abs_id_6[];
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void func_0215897C(u32 a, u32 b);
extern void *func_0201210C(void *p);
extern u32 func_020124AC(u32 a, const void *b, void *c, Pair *d);
extern void func_02154C20(void);

int func_021B4C54(u32 a, u32 b)
{
    Pair p;
    void *r5;
    void *r4;

    r5 = func_0215A5F4((void *)b);
    r4 = func_0215A5DC((void *)b);
    p.a = func_0201210C((void *)r4);
    p.b = 0;
    func_0215897C(r5, func_020124AC(r4, abs_id_6, (void *)func_02154C20, &p));
    return 1;
}
