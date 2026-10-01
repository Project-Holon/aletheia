/*
 * function: func_0219C150
 * address:  0x0219C150
 * packet:   pkt_ov021_0219C150
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219C338  0x0219C338  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0219C338(u32, u8 *, u32);

int func_0219C150(u32 a, u8 *s)
{
    func_0219C338(a, s, 12);
    s[0]++;
    return 1;
}
