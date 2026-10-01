/*
 * function: func_0219A87C
 * address:  0x0219A87C
 * packet:   pkt_ov021_0219A87C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0219B358  0x0219B358  thumb  ov021
 *   func_0219B374  0x0219B374  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u8 *func_0216D684(u32, u32);
extern int func_0219B358(u32);
extern void func_0219B374(u32, void *);

void func_0219A87C(u32 a)
{
    u8 *p = func_0216D684(a, 8);
    if (func_0219B358(a) == 1) {
        func_0219B374(a, p + 4);
    }
}
