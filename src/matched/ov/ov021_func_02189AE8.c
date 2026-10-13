/*
 * function: FIELDMAP_IsMmdlDrawEnabled
 * address:  0x02189AE8
 * packet:   pkt_ov021_02189AE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Leaf: 0 for id 0x3f, else 0 when ZONEDATA_IsZone96Pair() reports 1, else 1.
 * Callee of FIELDMAP_SetupMmdlSys.  EXACT* because the unlabelled follower
 * (0x02189B04) has no seed; no byte differs.
 *
 * symbols:
 *   ZONEDATA_IsZone96Pair  0x02013CE0  thumb
 */

typedef unsigned int   u32;
extern u32 ZONEDATA_IsZone96Pair(u32 id);

int FIELDMAP_IsMmdlDrawEnabled(int a)
{
    if (a == 0x3f)
        return 0;
    if (ZONEDATA_IsZone96Pair(a) == 1)
        return 0;
    return 1;
}
