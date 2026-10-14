/*
 * function: BTLV_EFFECT_GetBitMask
 * address:  0x021F935C
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFECT_GetBitMask   0x021F935C  thumb
 *
 * lane O10 candidate
 */

int BTLV_EFFECT_GetBitMask(int x)
{
    return 1 << x;
}

