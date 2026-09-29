/*
 * function: func_021B5700
 * address:  0x021B5700
 * packet:   pkt_ov021_021B5700
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_021B57CC  0x021B57CC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5E4();
extern int func_02158F74();
extern int func_02159B10();
extern u16 *func_02159AE8();
extern int func_0215A5CC();
extern int func_021B57CC();

int func_021B5700(int a0, int a1)
{
    int r6 = func_0215A5F4(a1);
    int s = func_0215A5E4(a1);
    int r7;
    u16 *r5;

    r6 = func_02158F74(r6);
    r7 = func_02159B10(a0, a1);
    r5 = func_02159AE8(a0, a1);
    *r5 = func_021B57CC(s, r6, r7, func_0215A5CC(a1));
    return 0;
}
