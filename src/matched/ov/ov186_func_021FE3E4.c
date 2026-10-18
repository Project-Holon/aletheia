/*
 * function: BR_UTIL_StepSpiral
 * address: 0x021FE3E4
 * packet: pkt_ov186_021FE3E4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: pass 2 2026-10-06 P2L30: EXACT (c and c99). The twin shape of
 *   BR_UTIL_StepOrbit (x, y products, then x += f0, y += f4, then the two
 *   stores) gives the original tail; with common subexpressions on, the
 *   front end turns the two radius reads into one temp and hoists it to
 *   right after the angle load. #pragma opt_common_subs off keeps the read
 *   inline at its first use (between the two table reads); a named index
 *   local i = (angle >> 4) * 2 then gives the shared index the pragma no
 *   longer finds. Earlier lanes: 26 (P19 lane 5), 15 (G6L8).
 * symbols:
 *   FX_SinCosTable_ 0x020A1B38 data a2
 */
#pragma opt_common_subs off
extern const short FX_SinCosTable_[];
int BR_UTIL_StepSpiral(char *p, int *out, int step)
{
    int angle, i, x, y;
    angle = (unsigned short)(*(unsigned short *)(p + 0x12) + 0xFFFF * step / *(int *)(p + 0x14));
    i = (angle >> 4) * 2;
    x = (FX_SinCosTable_[i + 1] * *(unsigned short *)(p + 0x10)) >> 12;
    y = (FX_SinCosTable_[i] * *(unsigned short *)(p + 0x10)) >> 12;
    x += *(int *)p;
    y += *(int *)(p + 4);
    *(int *)(p + 8) = x;
    *(int *)(p + 12) = y;
    if (out) { out[0] = x; out[1] = y; }
    return step == *(int *)(p + 0x14);
}
#pragma opt_common_subs reset
