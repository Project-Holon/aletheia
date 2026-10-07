/*
 * function: func_0206216C
 * address:  0x0206216C
 * packet:   pkt_02061D0C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The heap-handle builder that pairs with the validator func_020621FC.
 * Round the request up to sixteen (0x10 for zero), refuse 0x7FFF0 and above,
 * ask func_02061EA4 for the block through the 0x02146B9x heap pair the flag
 * selects, and pack the answer: bits 3..18 of the returned address in the low
 * half, size/16 in bits 16..30, the caller's flag in bit 31.
 *
 * Two spelling details are load-bearing:
 *   - ../2.0/sp2, not dsi/1.1p1, exactly as its sibling func_020624C8: on
 *     1.1p1 the same C does not reproduce the two-arm call shape.
 *   - the packed handle is written size-high FIRST,
 *     `((n >> 4) << 16) | ((local << 13) >> 16) | (flag << 31)`; the other
 *     order swaps r0 and r1 through the final four instructions, the
 *     accumulator naming its second operand.
 *
 * symbols:
 *   g_02146B94     0x02146B94  data
 *   g_02146B98     0x02146B98  data
 *   g_02146B9C     0x02146B9C  data
 *   func_02061EA4  0x02061EA4  arm
 */

#include "../include/G_Cfg.h"

typedef unsigned int u32;

extern struct Cfg g_02146B94;
extern u32 g_02146B98, g_02146B9C;
extern u32 func_02061EA4(u32 a, u32 b, u32 *out, u32 size);

u32 func_0206216C(u32 size, u32 flag)
{
    u32 n = (size == 0) ? 0x10 : (size + 0xf) & ~0xf;
    u32 local, r;

    if (n >= 0x7fff0) return 0;
    if (flag != 0) r = func_02061EA4((u32)&g_02146B98, (u32)&g_02146B9C, &local, n);
    else           r = func_02061EA4((u32)&(*(u32 *)&g_02146B94), (u32)&g_02146B9C, &local, n);
    if (r == 0) return 0;
    return ((n >> 4) << 16) | ((local << 13) >> 16) | (flag << 31);
}
