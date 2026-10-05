/*
 * function: func_0219BB84
 * address:  0x0219BB84
 * packet:   pkt_0219BB84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216DA50 (0x0216DA50) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216DA50  0x0216DA50  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17960.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216DA50(u32);
extern u32 func_02197EDC(u32, u32, u32, u32);

int func_0219BB84(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC(a, b, c, d) == 0) {
    return 0;
}
func_0216DA50(a);
((struct Obj17960 *)((u8 *)(b)))->f0 = 0;
return 0;
}

