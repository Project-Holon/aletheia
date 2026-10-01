/*
 * function: func_021992CC
 * address:  0x021992CC
 * packet:   pkt_ov021_021992CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219912C  0x0219912C  thumb  ov021
 *   d_021D41E0     0x021D41E0  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef struct { int x, y, z; } Vec;
extern const Vec d_021D41E0;
extern void func_0219912C(u32 a, Vec *b, u32 c, u32 d, u32 e, u8 f);

int func_021992CC(u32 a)
{
    Vec t = d_021D41E0;
    func_0219912C(a, &t, 0, 3, 8, 3);
    return 1;
}
