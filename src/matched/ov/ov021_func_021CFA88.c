/*
 * function: func_021CFA88
 * address:  0x021CFA88
 * packet:   pkt_ov021_021CFA88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02008854  0x02008854  thumb
 *   func_02008990  0x02008990  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(void *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_02008854(void *p);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u16 func_02008990(void *p);

int func_021CFA88(void *a, void *b)
{
    void *h;
    u16 *q;

    func_0215A5F4(b);
    h = func_02008854(func_02012EBC(func_020120F4((void *)func_0215A5DC(b))));
    q = func_02159AE8(a, b);
    *q = func_02008990(h);
    return 0;
}
