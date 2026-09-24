/*
 * function: func_021BE1A0
 * address:  0x021BE1A0
 * packet:   pkt_021BE1A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_02162370 (0x02162370) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_021BE180  0x021BE180  thumb  ov021
 *   func_02162370  0x02162370  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02162370(u32);
extern u32 func_021BE180(u32, u32, u32, u32);

int func_021BE1A0(u32 a, u32 b, u32 c, u32 d)
{
return func_02162370(*(u32 *)((u8 *)(func_021BE180(a, b, c, d))));
}

