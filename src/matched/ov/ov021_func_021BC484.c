/*
 * function: func_021BC484
 * address:  0x021BC484
 * packet:   pkt_ov021_021BC484
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD0B0  0x021BD0B0  thumb  ov021
 *   func_021BD0A4  0x021BD0A4  thumb  ov021
 *   func_021BCC3C  0x021BCC3C  thumb  ov021
 *   func_021BCC80  0x021BCC80  thumb  ov021
 *   func_021BCD34  0x021BCD34  thumb  ov021
 *   func_021BCD70  0x021BCD70  thumb  ov021
 *   func_021BCD84  0x021BCD84  thumb  ov021
 *   func_021BCDD8  0x021BCDD8  thumb  ov021
 *   func_021BCE88  0x021BCE88  thumb  ov021
 *   func_021BC970  0x021BC970  thumb  ov021
 */

extern void func_021BD0B0(int a);
extern int func_021BD0A4(int a);
extern void func_021BCC3C(int a);
extern void func_021BCC80(int a);
extern void func_021BCD34(int a);
extern void func_021BCD70(int a);
extern void func_021BCD84(int a);
extern void func_021BCDD8(int a);
extern void func_021BCE88(int a);
extern void func_021BC970(int a);

void func_021BC484(int a)
{
    func_021BD0B0(a);
    switch (func_021BD0A4(a)) {
    case 0:
        func_021BCC3C(a);
        break;
    case 1:
        func_021BCC80(a);
        break;
    case 2:
        func_021BCD34(a);
        break;
    case 3:
        func_021BCD70(a);
        break;
    case 4:
        func_021BCD84(a);
        break;
    case 5:
        func_021BCDD8(a);
        break;
    case 6:
        func_021BCE88(a);
        break;
    }
    func_021BC970(a);
}
