/*
 * function: func_021F36C8
 * address:  0x021F36C8
 * packet:   pkt_ov056_021F36C8
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Word table lookup in d_021F42B0 ({0x1C, 0x1D, 0x1E, 0x1F}), the table ov056
 * func_021F392C also indexes. Region ov056: of the 33 overlays mapped at this
 * address it is the only one with a function entry here (the bytes before are
 * the tail-call thunk at 0x021F36C0 and its pool word); ov036..ov065 except
 * ov056 are mid-function at 0x021F36C8, ov107 is ARM. Its ov021 caller
 * func_021B5650 passes a 1-based slot minus one (wave A1 witness).
 *
 * symbols:
 *   d_021F42B0  0x021F42B0  data
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern const u32 d_021F42B0[];

u32 func_021F36C8(u32 idx)
{
    return d_021F42B0[idx];
}
