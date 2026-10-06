/*
 * function: func_0219B508
 * address:  0x0219B508
 * packet:   pkt_ov021_0219B508
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
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0216D6A0(int a0, int a1);
extern int func_0216D63C(char *a0, int a1);

void func_0219B508(u32 a)
{
    u8 *p = func_0216D6A0(a, 9);
    p[3] = func_0216D63C((char *)a, 1);
}
