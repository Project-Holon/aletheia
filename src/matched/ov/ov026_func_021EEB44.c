/*
 * function: func_021EEB44
 * address:  0x021EEB44
 * packet:   pkt_ov026_021EEB44
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEB44  0x021EEB44  thumb  ov026
 *   func_021EEF0C  0x021EEF0C  thumb  ov026
 *   func_02014A10  0x02014A10  thumb
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A2154  0x021A2154  thumb  ov021
 *   func_021A2130  0x021A2130  thumb  ov021
 *   func_021A25DC  0x021A25DC  thumb  ov021
 *   func_021A213C  0x021A213C  thumb  ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_021A25BC  0x021A25BC  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   func_021A223C  0x021A223C  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 */

typedef signed short s16;

typedef unsigned char  u8;
extern int *func_021A21B8(int *p);
extern int func_021A2108(unsigned int a, int b, int c);
extern void func_021A2154(u8 *p, unsigned int b, unsigned int c);
extern void func_021A2130(u8 *p, unsigned int b, unsigned int c, unsigned int d);
extern void func_021A25DC(u8 *p, int a);
extern int func_021A213C(u8 *p);
extern void func_021A232C(u8 *p, int a, int b, int c, int d);
extern void func_021A25BC(unsigned char *o, int arg);
extern void func_021A2160(unsigned char *o, unsigned int v, int i);
extern int func_021A223C(unsigned char *o, int arg);
extern int func_021A23B0(unsigned int a);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 func_02014A10(u32 i);
extern void func_021EEF0C(int a, int *b);

int func_021EEB44(u8 *a, int b, int c)
{
    s16 *p;
    int t;
    int u;

    p = (s16 *)func_021A21B8((int *)a);
    switch (p[0]) {
    case 0:
        func_021A2108((unsigned int)a, 0x3E, func_02014A10(6));
        p[0] = p[0] + 1;
        p[1] = 0x5A;
        break;
    case 1:
        p[1] = p[1] - 1;
        if (p[1] < 0) {
            p[0] = p[0] + 1;
        }
        break;
    case 2:
        func_021A2154(a, 0x28C6, 8);
        p[1] = 0x10;
        p[0] = p[0] + 1;
        break;
    case 3:
        p[1] = p[1] - 1;
        if (p[1] < 0) {
            func_021A2130(a, 0x23DE, 4, 0x3C);
            func_021A25DC((u8 *)a, 0x692);
            p[0] = p[0] + 1;
        }
        break;
    case 4:
        if (func_021A213C((u8 *)a) == 0) {
            func_021A232C((u8 *)a, 9, 0x7F80, 0x50, b);
            p[0] = p[0] + 1;
            p[1] = 0x30;
        }
        break;
    case 5:
        p[1] = p[1] - 1;
        if (p[1] == 0) {
            func_021A25BC((unsigned char *)a, 0x690);
            func_021A2160((unsigned char *)a, 1, 0);
        }
        t = func_021A223C((unsigned char *)a, c);
        u = func_021A23B0((int)a);
        if (t != 0 && u != 0) {
            return 1;
        }
        break;
    }
    func_021EEF0C((int)a, (int *)p);
    return 0;
}
