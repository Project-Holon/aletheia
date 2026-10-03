/*
 * function: func_021EE770
 * address:  0x021EE770
 * packet:   pkt_ov028_021EE770
 * region:   ov028
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_02014A10  0x02014A10  thumb
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 */

int *func_021A21B8(int a);
void func_021A232C(int a, int b, int c, int d, int e);
typedef unsigned short u16;
typedef unsigned int   u32;
u16 func_02014A10(u32 i);
int func_021A2108(int a, int b, int c);
int func_021A23B0(int a);

int func_021EE770(int a, int b)
{
    int *p = func_021A21B8(a);

    if (*p == 0) {
        func_021A232C(a, p[10], p[11], 0x5a, b);
        func_021A2108(a, 0x3e, func_02014A10(9));
        *p = *p - 1;
    } else if (func_021A23B0(a) != 0) {
        return 1;
    }
    return 0;
}
