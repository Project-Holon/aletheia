/*
 * function: func_021EF614
 * address:  0x021EF614
 * packet:   pkt_ov026_021EF614
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   func_021A25BC  0x021A25BC  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020056EC(u32 v);
extern void func_021A232C(u8 *p, int a, int b, int c, int d);
extern void func_021A2160(unsigned char *o, unsigned int v, int i);
extern void func_021A25BC(unsigned char *o, int arg);

void func_021EF614(int a, u16 *p, int c, int d)
{
    u32 r = func_020056EC(0);
    p[8] = 1;
    p[7] = r % 400 + 0x3C;
    p[6] = 0;
    if (d == 0) {
        func_021A232C((u8 *)a, 9, 0x7F80, 10, c);
        func_021A2160((unsigned char *)a, 0, 1);
        func_021A25BC((unsigned char *)a, 0x690);
    }
}
