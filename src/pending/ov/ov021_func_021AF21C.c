/*
 * function: func_021AF21C
 * address:  0x021AF21C
 * packet:   pkt_ov021_021AF21C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker: func_02158F88 (0x02158F88, ov010, thumb) is an unlabelled ov010
 * leaf (adds r0, #0x40; bx lr: returns p + 0x40) in the word run after
 * func_02158F58, outside this lane's write set. Every concrete byte matches;
 * filing that leaf makes this EXACT. (2026-10-01)
 *
 * symbols:
 *   func_02158F88  0x02158F88  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u8 *func_02158F88(u32 a);
extern int func_02006148(u32 a);

void func_021AF21C(u32 a, u32 b)
{
    u8 *p = func_02158F88(a);

    *p |= 1 << func_02006148(b);
}
