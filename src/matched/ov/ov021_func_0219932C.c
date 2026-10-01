/*
 * function: func_0219932C
 * address:  0x0219932C
 * packet:   pkt_ov021_0219932C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct (2026-10-01).  Sole blocker: the ABS32 pool word for the const
 * Vec initialiser is an ov021 data start that another overlay mapped over the
 * same window also starts an object at, so the symbols hint is contested and
 * no single-reference witness exists.  No C change needed to promote.
 *
 * 2026-10-01: the own-overlay data hint is dropped from symbols: so the
 *   own-window rule (code running in ov021 can only see ov021's bytes in its
 *   window) fixes the overlay; with the hint the tool refused it as contested.
 *
 * symbols:
 *   func_0219912C  0x0219912C  thumb  ov021
 *   d_021D4C10     0x021D4C10  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef struct { int x, y, z; } Vec;
extern const Vec d_021D4C10;
extern void func_0219912C(u32 a, Vec *b, u32 c, u32 d, u32 e, u8 f);

int func_0219932C(u32 a)
{
    Vec t = d_021D4C10;
    func_0219912C(a, &t, 2, 1, 8, 3);
    return 1;
}
