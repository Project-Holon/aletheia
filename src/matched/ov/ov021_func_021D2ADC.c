/*
 * function: func_021D2ADC
 * address:  0x021D2ADC
 * packet:   pkt_ov021_021D2ADC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008C58  0x02008C58  thumb
 *   func_02008DAC  0x02008DAC  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern unsigned int func_02159B10(void *a, void *b);
struct Big;
struct Ctx;
struct Sub02008C20Obj;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern u32 func_02008DAC(struct Sub02008C20Obj *obj, int i, u32 delta);

int func_021D2ADC(u32 a, u32 b)
{
    void *x = func_0215A5DC((void *)b);
    u32 k1 = func_02159B10((void *)a, (void *)b);
    u32 k2 = func_02159B10((void *)a, (void *)b);

    func_02008DAC(func_02008C58(func_02012EBC(func_020120F4((void *)x))), k1, k2);
    return 0;
}
