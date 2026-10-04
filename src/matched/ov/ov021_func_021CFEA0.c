/*
 * function: func_021CFEA0
 * address:  0x021CFEA0
 * packet:   pkt_ov021_021CFEA0
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
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02009590  0x02009590  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern unsigned int func_02159B10(void *a, void *b);
extern u16 *func_02159AE8(void *a0, void *a1);
typedef unsigned char  u8;
struct Big;
struct Ctx;
struct Sub02009470Obj;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern u8 *func_02012944(void *p);
extern u8 func_02009590(void *a, u32 b, u32 c);

int func_021CFEA0(u32 a, u32 b)
{
    u32 k, h, g;
    void *x;
    u16 *out;

    func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    k = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    h = (u32)func_020120F4(x);
    g = (u32)func_02009470(func_02012EBC((struct Big *)h));
    *out = func_02009590((void *)g, (u32)func_02012944((void *)h), k);
    return 0;
}
