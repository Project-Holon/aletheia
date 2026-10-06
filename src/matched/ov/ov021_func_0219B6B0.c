/*
 * function: func_0219B6B0
 * address:  0x0219B6B0
 * packet:   pkt_ov021_0219B6B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6A0  0x0216D6A0  thumb  ov010
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u8 *func_0216D6A0(u32, u32);
extern int func_0216D63C(char *a0, int a1);
extern u16 func_0216D5A8(u8 *p);

void func_0219B6B0(u32 a)
{
    u8 *p = func_0216D6A0(a, 9);
    u32 s;
    u8 v = 1;
    p[3] = func_0216D63C((char *)a, 1);
    s = func_0216D5A8((u8 *)a);
    if (s == 5 || s == 20 || s == 15) {
        v = 0;
    }
    p[5] = v;
}
