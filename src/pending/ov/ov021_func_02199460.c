/*
 * function: func_02199460
 * address:  0x02199460
 * packet:   pkt_ov021_02199460
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct (2026-10-01).  Sole blocker: the ABS32 pool word for the const
 * Vec initialiser is an ov021 data start that another overlay mapped over the
 * same window also starts an object at, so the symbols hint is contested and
 * no single-reference witness exists.  No C change needed to promote.
 *
 * symbols:
 *   func_0219912C  0x0219912C  thumb  ov021
 *   d_021D4BC8     0x021D4BC8  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef struct { int x, y, z; } Vec;
extern const Vec d_021D4BC8;
extern void func_0219912C(u32 a, Vec *b, u32 c, u32 d, u32 e, u8 f);

int func_02199460(u32 a)
{
    Vec t = d_021D4BC8;
    func_0219912C(a, &t, 2, 3, 8, 3);
    return 1;
}
