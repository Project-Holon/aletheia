/*
 * function: FIELD_BUILDMODEL_InitAnimSetNone
 * address:  0x0218C02C
 * packet:   pkt_ov021_0218C02C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Entry of the gBuildModelAnimInitTable dispatch table (pool word 0x0218C02D at +0x0 and
 * +0x18), called by FIELD_BUILDMODEL_InitAnimSet as fn(a, out): clears out[2..5].
 *
 * symbols:
 */

typedef unsigned int u32;

void FIELD_BUILDMODEL_InitAnimSetNone(void *a, u32 *out)
{
    int i;

    for (i = 0; i < 4; i++) {
        out[2 + i] = 0;
    }
}
