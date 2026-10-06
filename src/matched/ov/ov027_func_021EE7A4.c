/*
 * function: func_021EE7A4
 * address:  0x021EE7A4
 * packet:   pkt_ov027_021EE7A4
 * region:   ov027
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A223C  0x021A223C  thumb  ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_02014A10  0x02014A10  thumb
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   func_021EEAF4  0x021EEAF4  thumb  ov027
 */

typedef unsigned char  u8;
int *func_021A21B8(int *p);
int func_021A223C(unsigned char *o, int arg);
void func_021A232C(u8 *p, int a, int b, int c, int d);
typedef unsigned short u16;
typedef unsigned int   u32;
u16 func_02014A10(u32 i);
int func_021A2108(u32 a, int b, int c);
int func_021A23B0(u32 a);
void func_021A2160(unsigned char *o, unsigned int v, int i);
void func_021EEAF4(int a, int *p);

int func_021EE7A4(int a, int b, int c)
{
    int *p = func_021A21B8((int *)a);
    int t = func_021A223C((unsigned char *)a, c);

    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
            func_021A232C((u8 *)a, 8, 0x7f5e, 0x5a, b);
            func_021A2108(a, 0x3e, func_02014A10(3));
        }
    } else if (func_021A23B0(a) != 0 && t != 0) {
        func_021A2160((unsigned char *)a, 1, 0);
        return 1;
    }
    func_021EEAF4(a, p);
    return 0;
}
