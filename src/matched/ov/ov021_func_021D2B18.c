/*
 * function: func_021D2B18
 * address:  0x021D2B18
 * packet:   pkt_ov021_021D2B18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008C58  0x02008C58  thumb
 *   func_02008DFC  0x02008DFC  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern u32 func_02159B10(u32 a, u32 b);
struct Big;
struct Ctx;
struct Sub02008C20Obj;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_02008DFC(struct Sub02008C20Obj *obj, int i);

int func_021D2B18(u32 a, u32 b)
{
    void *x = func_0215A5DC((void *)b);
    u32 k = func_02159B10(a, b);
    u16 *q = func_02159AE8((void *)a, (void *)b);

    *q = func_02008DFC(func_02008C58(func_02012EBC(func_020120F4((void *)x))), k);
    return 0;
}
