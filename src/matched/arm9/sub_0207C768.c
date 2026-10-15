/*
 * function: FX_Div
 * address:  0x0207C768
 * packet:   pkt_0207C768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   FX_DivAsync   0x0207C930  arm
 *   FX_GetDivResult   0x0207C86C  arm
 *
 * Start the hardware unit through FX_DivAsync with the caller's two
 * operands, then block on it and return its result through FX_GetDivResult.
 * Both arguments reach FX_DivAsync as leftovers in r0/r1; nothing is
 * spent setting them up
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FX_Div.c \
 *       --func FX_Div --addr 0x0207C768 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void FX_DivAsync(u32 a, u32 b);
extern u32  FX_GetDivResult(void);

u32 FX_Div(u32 a, u32 b)
{
    FX_DivAsync(a, b);
    return FX_GetDivResult();
}
