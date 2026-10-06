/*
 * function: func_021EEB74
 * address:  0x021EEB74
 * packet:   pkt_ov025_021EEB74
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021EEB74  0x021EEB74  thumb  ov025
 *   func_021EEEE0  0x021EEEE0  thumb  ov025
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A223C  0x021A223C  thumb  ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   func_02014A10  0x02014A10  thumb
 */

typedef unsigned char  u8;
extern int *func_021A21B8(int *p);
extern int func_021A223C(unsigned char *o, int arg);
extern void func_021A232C(u8 *p, int a, int b, int c, int d);
extern int func_021A2108(unsigned int a, int b, int c);
extern int func_021A23B0(unsigned int a);
extern void func_021A2160(unsigned char *o, unsigned int v, int i);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 func_02014A10(u32 i);
extern void func_021EEEE0(int, int *);

int func_021EEB74(int a, int b, int c)
{
    int *p;
    int t;

    p = func_021A21B8((int *)a);
    t = func_021A223C((unsigned char *)a, c);
    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
            func_021A232C((u8 *)a, 4, 0x7B18, 0x5A, b);
            func_021A2108(a, 0x3E, func_02014A10(4));
        }
    } else if (func_021A23B0(a) != 0 && t != 0) {
        func_021A2160((unsigned char *)a, 1, 0);
        return 1;
    }
    func_021EEEE0(a, p);
    return 0;
}
