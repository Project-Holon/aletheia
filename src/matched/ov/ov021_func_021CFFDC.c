/*
 * function: func_021CFFDC
 * address:  0x021CFFDC
 * packet:   pkt_ov021_021CFFDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02009470  0x02009470  thumb
 *   sub_020095FC  0x020095FC  thumb
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
extern void *func_020120F4(void *p);
extern void *func_02012EBC(void *p);
extern void *func_02009470(void *p);
extern u32 func_02159B10(u32 a, u32 b);
extern void sub_020095FC(void *p, u8 v);

int func_021CFFDC(u32 a, u32 b)
{
    void *x;
    u8 v;

    func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    v = func_02159B10(a, b);
    sub_020095FC(func_02009470(func_02012EBC(func_020120F4((void *)x))), v);
    return 0;
}
