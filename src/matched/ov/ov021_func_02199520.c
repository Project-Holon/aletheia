/*
 * function: func_02199520
 * address:  0x02199520
 * packet:   pkt_ov021_02199520
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219912C  0x0219912C  thumb  ov021
 *   d_021D4B98  0x021D4B98  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
extern const Vec d_021D4B98;
extern void func_0219912C(u32 a, Vec *b, u32 c, u32 d, u32 e, u8 f);

int func_02199520(u32 a)
{
    Vec t = d_021D4B98;
    func_0219912C(a, &t, 2, 3, 4, 4);
    return 1;
}
