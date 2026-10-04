/*
 * function: func_021989EC
 * address:  0x021989EC
 * packet:   pkt_021989EC
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
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0216D674(void *p, u16 v);
extern u32 func_0216D6BC(u32, u32, u32, u32);
extern u32 func_0216D7CC(u32);

int func_021989EC(u32 a, u32 b, u32 c, u32 d)
{
*(u32 *)((u8 *)(func_0216D6BC(a, 8, c, d)) + 4) = (8 << 13);
func_0216D674((void *)a, 0);
func_0216D7CC(a);
return 1;
}

