/*
 * function: func_02199584
 * address:  0x02199584
 * packet:   pkt_ov021_02199584
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219912C  0x0219912C  thumb  ov021
 *   d_021D4B80  0x021D4B80  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
extern const Vec d_021D4B80;
extern void func_0219912C(u32 a, Vec *b, u32 c, u32 d, u32 e, u8 f);

int func_02199584(u32 a)
{
    Vec t = d_021D4B80;
    func_0219912C(a, &t, 0, 1, 2, 5);
    return 1;
}
