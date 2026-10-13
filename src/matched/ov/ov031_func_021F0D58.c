/*
 * function: UNION_SUBDISP_GetKnobStep
 * address:  0x021F0D58
 * packet:   pkt_021F0D58
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_SUBDISP_GetKnobStep 0x021F0D58 thumb
 *   func_0209C2B0 0x0209C2B0 arm
 */

typedef unsigned int u32;

extern u32 func_0209C2B0(u32 a, u32 b);

u32 UNION_SUBDISP_GetKnobStep(void *unused, u32 d)
{
    return func_0209C2B0(0x8000, d);
}
