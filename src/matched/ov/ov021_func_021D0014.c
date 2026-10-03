/*
 * function: func_021D0014
 * address:  0x021D0014
 * packet:   pkt_ov021_021D0014
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02009470  0x02009470  thumb
 *   sub_02009618  0x02009618  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Big;
struct Ctx;
struct Sub02009470Obj;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern u32 func_02159B10(u32 a, u32 b);
extern void sub_02009618(struct Sub02009470Obj *obj, int value);

int func_021D0014(u32 a, u32 b)
{
    void *x;
    u8 v;

    func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    v = func_02159B10(a, b);
    sub_02009618(func_02009470(func_02012EBC(func_020120F4((void *)x))), v);
    return 0;
}
