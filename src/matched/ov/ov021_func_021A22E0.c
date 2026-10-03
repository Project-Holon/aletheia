/*
 * function: func_021A22E0
 * address:  0x021A22E0
 * packet:   pkt_ov021_021A22E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A01AC  0x021A01AC  thumb  ov021
 *   func_021A01CC  0x021A01CC  thumb  ov021
 *   func_021A01B4  0x021A01B4  thumb  ov021
 *   func_021A01BC  0x021A01BC  thumb  ov021
 *   func_021A01D8  0x021A01D8  thumb  ov021
 *   func_021A01A4  0x021A01A4  thumb  ov021
 */

typedef unsigned int u32;

int func_021A01AC(u32 a, u32 b);
int func_021A01CC(u32 a, u32 b);
int func_021A01B4(u32 a, u32 b);
int func_021A01BC(u32 a, u32 b);
void func_021A01D8(u32 x);
int func_021A01A4(u32 a, u32 b);

void func_021A22E0(u32 *p, int a, int b, int c)
{
    if (c == 1) {
        func_021A01AC(p[1], 0);
        func_021A01CC(p[1], 0x1F);
        func_021A01B4(p[1], a);
        func_021A01BC(p[1], b);
        func_021A01D8(p[1]);
        func_021A01A4(p[1], 1);
    }
}
