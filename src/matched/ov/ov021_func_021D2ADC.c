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

extern u32 func_0215A5DC(u32 a);
extern u32 func_02159B10(u32 a, u32 b);
extern void *func_020120F4(void *p);
extern void *func_02012EBC(void *p);
extern void *func_02008C58(void *p);
extern void func_02008DAC(void *p, u32 a, u32 b);

int func_021D2ADC(u32 a, u32 b)
{
    u32 x = func_0215A5DC(b);
    u32 k1 = func_02159B10(a, b);
    u32 k2 = func_02159B10(a, b);

    func_02008DAC(func_02008C58(func_02012EBC(func_020120F4((void *)x))), k1, k2);
    return 0;
}
