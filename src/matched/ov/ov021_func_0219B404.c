/*
 * function: func_0219B404
 * address:  0x0219B404
 * packet:   pkt_ov021_0219B404
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D550  0x0216D550  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 *func_0216D550(u32 *p, u32 v);

void func_0219B404(u32 a, u8 *s)
{
    if (s[2] == 0) {
        func_0216D550((u32 *)a, 8);
    }
}
