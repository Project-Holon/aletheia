/*
 * function: func_0219D724
 * address:  0x0219D724
 * packet:   pkt_0219D724
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D530 (0x0216D530) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D530  0x0216D530  thumb
 *   func_021BB3C4  0x021BB3C4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D530(u32);
extern void *func_0216D67C(void *a0);
extern u32 func_021BB3C4(u32, u32);

int func_0219D724(u32 a, u32 b)
{
return func_021BB3C4(func_0216D530((u32)func_0216D67C((void *)a)), b);
}

