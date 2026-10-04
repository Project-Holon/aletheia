/*
 * function: func_021EE988
 * address:  0x021EE988
 * packet:   pkt_ov028_021EE988
 * region:   ov028
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE988  0x021EE988  thumb  ov028
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_02014A10  0x02014A10  thumb
 */

typedef unsigned char  u8;
extern int *func_021A21B8(int *p);
extern void func_021A232C(u8 *p, int a, int b, int c, int d);
extern void func_021A2108(int, int, int);
extern int func_021A23B0(int);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 func_02014A10(u32 i);

int func_021EE988(int a, int b)
{
    int *p = func_021A21B8((int *)a);

    if (p[1] == 0) {
        func_021A232C((u8 *)a, p[11], p[12], 0x5A, b);
        func_021A2108(a, 0x3E, func_02014A10(p[0]));
        p[1] = p[1] - 1;
    } else if (func_021A23B0(a) != 0) {
        return 1;
    }
    return 0;
}
