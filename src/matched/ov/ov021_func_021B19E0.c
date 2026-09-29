/*
 * function: func_021B19E0
 * address:  0x021B19E0
 * packet:   pkt_ov021_021B19E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D63C  0x0216D63C  thumb  ov010
 */

typedef unsigned short u16;

int func_02159B10(int a, int b);
u16 *func_02159AE8(int a, int b);
int func_0215A5EC(int b);
int func_0216DE94(int a, int b);
u16 func_0216D63C(int a, int b);

int func_021B19E0(int a, int b)
{
    int r7;
    unsigned int r4;
    u16 *r6;
    int r0;

    r7 = func_02159B10(a, b);
    r4 = func_02159B10(a, b);
    r6 = func_02159AE8(a, b);
    r0 = func_0216DE94(func_0215A5EC(b), r7);
    if (r4 <= 2 && r0 != 0) {
        *r6 = func_0216D63C(r0, r4);
    }
    return 0;
}
