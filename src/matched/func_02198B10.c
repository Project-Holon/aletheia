/*
 * function: func_02198B10
 * address:  0x02198B10
 * packet:   pkt_02198B10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D7CC (0x0216D7CC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D550(u32, u32, u32, u32);
extern u32 func_0216D7CC(u32);

int func_02198B10(u32 a, u32 b, u32 c, u32 d)
{
func_0216D550(a, 8, c, d);
func_0216D7CC(a);
return 1;
}

