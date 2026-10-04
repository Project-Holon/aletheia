/*
 * function: func_0219DC34
 * address:  0x0219DC34
 * packet:   pkt_0219DC34
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
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02163F10(u32);
extern u32 func_0216D5E0(u32, u32, u32, u32);
extern void func_0216D674(void *p, u16 v);
extern u32 func_0216D7CC(u32);

int func_0219DC34(u32 a, u32 b, u32 c, u32 d)
{
func_0216D5E0(a, ((b << 16) >> 16), c, d);
func_0216D674((void *)a, 0);
func_02163F10(a);
return func_0216D7CC(a);
}

