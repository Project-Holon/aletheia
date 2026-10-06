/*
 * function: func_0219B374
 * address:  0x0219B374
 * packet:   pkt_ov021_0219B374
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u16 func_0216D5A8(u8 *p);

void func_0219B374(u32 a, u8 *s)
{
    u32 v = func_0216D5A8((u8 *)a);
    if (v == 7 || v == 17) {
        s[1] = 0;
    } else {
        s[1] = 1;
    }
}
