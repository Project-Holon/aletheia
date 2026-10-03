/*
 * function: func_021CFEF0
 * address:  0x021CFEF0
 * packet:   pkt_ov021_021CFEF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02009470  0x02009470  thumb
 *   sub_020095C8  0x020095C8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
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
extern u16 *func_02159AE8(void *a0, void *a1);
extern u8 sub_020095C8(const struct Sub02009470Obj *obj);

int func_021CFEF0(u32 a, u32 b)
{
    void *x;
    u16 *q;

    func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    q = func_02159AE8((void *)a, (void *)b);
    *q = sub_020095C8(func_02009470(func_02012EBC(func_020120F4((void *)x))));
    return 0;
}
