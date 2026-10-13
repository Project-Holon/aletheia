/*
 * function: FIELD_GIMMICK_GAUGE_EFFECT_IsEffectActive
 * address:  0x021F37D8
 * packet:   pkt_021F37D8
 * region:   ov060
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Call with a zero second argument then read byte 1 of the result.
 *
 * symbols:
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb
 *
 * Unblocked by matching the leaf at 0x021897BC in ov021: its only coherent
 * code home (ov009 is ARM gpiRecvToBuffer there).
 */

int FIELD_GIMMICK_GAUGE_EFFECT_IsEffectActive(void *p)
{
    void *FIELDMAP_GetCommonWork(void *, int);
    return *(unsigned char *)((char *)FIELDMAP_GetCommonWork(p, 0) + 1);
}
