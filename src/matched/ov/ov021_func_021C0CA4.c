/*
 * function: func_021C0CA4
 * address:  0x021C0CA4
 * packet:   pkt_ov021_021C0CA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A5728  0x021A5728  thumb  ov021
 *   func_021A572C  0x021A572C  thumb  ov021
 *   func_021A3AB8  0x021A3AB8  thumb  ov021
 *   func_021A44BC  0x021A44BC  thumb  ov021
 *   func_021C0CE4  0x021C0CE4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021A5728(int a);
extern void func_021A572C(int a);
extern int func_021A3AB8(int a, int b);
extern int func_021A44BC(int a, int b);
extern int func_021C0CE4(int a, int b, int c);

int func_021C0CA4(int a, int b, int c, int d)
{
    int r7, r4;
    r7 = func_021A5728(a);
    func_021A572C(a);
    r4 = func_021A3AB8(r7, c);
    if (func_021A44BC(a, r4) == 0)
        return 0;
    r7 = func_021C0CE4(a, r4, d);
    if (r7 == 0)
        return 0;
    return r7;
}
