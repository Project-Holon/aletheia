/*
 * function: func_02199088
 * address:  0x02199088
 * packet:   pkt_02199088
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D7CC (0x0216D7CC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_02199034  0x02199034  thumb  ov021
 *   func_0216D7CC  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D7CC(u32);
extern int func_02199034(u32 a, u32 b, u32 c, u32 d);

int func_02199088(u32 a, u32 b, u32 c, u32 d)
{
func_02199034(a, 2, 40, d);
func_0216D7CC(a);
return 0;
}

