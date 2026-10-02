/*
 * function: func_021B1D20
 * address:  0x021B1D20
 * packet:   pkt_ov021_021B1D20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A2F48  0x021A2F48  thumb  ov021
 *   func_021A2F54  0x021A2F54  thumb  ov021
 *   func_020113D0  0x020113D0  thumb
 *   func_021B1CFC  0x021B1CFC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern u32 *func_02158F58(u32);
extern u32 func_02011330(u32);
extern void *func_02188CB4(unsigned char *p);
extern void func_021A2F48(u32, u32);
extern int func_021A2F54(u32);
extern void func_020113D0(u32, int (*)());
extern int func_021B1CFC();

int func_021B1D20(u32 a, u32 b)
{
    u32 *e;
    u32 v;
    void *o;

    e = func_02158F58(func_0215A5F4((void *)b));
    v = func_02011330(a);
    o = func_02188CB4(e[1]);
    func_021A2F48(o, v);
    if (func_021A2F54(o) == 1)
        return 0;
    func_020113D0(a, func_021B1CFC);
    return 1;
}
