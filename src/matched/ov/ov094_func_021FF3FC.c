/*
 * function: BTLV_MCSS_GetSlotPositionForRule
 * address:  0x021FF3FC
 * packet:   pkt_021FD1CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvMcssSlotPosSingle  0x0220A050  data  ov094
 *   gBtlvMcssSlotPosDouble  0x0220A080  data  ov094
 *   gBtlvMcssSlotPosTriple  0x0220A158  data  ov094
 *   gBtlvMcssSlotPosRotation  0x0220A1A0  data  ov094
 *
 * Unlabelled: no func_ label in the listing (leaf, saves no lr); reached
 * by bl from BTLV_EFFVM_ParticleStartCallback.
 */
typedef struct {
    int x, y, z;
} Vec3;

extern const Vec3 gBtlvMcssSlotPosSingle[];
extern const Vec3 gBtlvMcssSlotPosDouble[];
extern const Vec3 gBtlvMcssSlotPosTriple[];
extern const Vec3 gBtlvMcssSlotPosRotation[];

void BTLV_MCSS_GetSlotPositionForRule(const Vec3 *def, Vec3 *out, int idx, int kind)
{
    switch (idx) {
    case 0:
    case 1:
        def = &gBtlvMcssSlotPosSingle[idx];
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        if (kind == 3)
            def = &gBtlvMcssSlotPosRotation[idx - 2];
        else if (kind == 2)
            def = &gBtlvMcssSlotPosTriple[idx - 2];
        else
            def = &gBtlvMcssSlotPosDouble[idx - 2];
        break;
    case 6:
    case 7:
        if (kind == 3)
            def = &gBtlvMcssSlotPosRotation[idx - 2];
        else
            def = &gBtlvMcssSlotPosTriple[idx - 2];
        break;
    }
    out->x = def->x;
    out->y = def->y;
    out->z = def->z;
}
