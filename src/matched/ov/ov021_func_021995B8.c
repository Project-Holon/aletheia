/*
 * function: func_021995B8
 * address:  0x021995B8
 * packet:   pkt_ov021_021995B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219912C  0x0219912C  thumb  ov021
 *   d_021D4B74  0x021D4B74  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
extern const Vec d_021D4B74;
extern void func_0219912C(u32 a, Vec *b, u32 c, u32 d, u32 e, u8 f);

int func_021995B8(u32 a)
{
    Vec t = d_021D4B74;
    func_0219912C(a, &t, 3, 2, 2, 5);
    return 1;
}
