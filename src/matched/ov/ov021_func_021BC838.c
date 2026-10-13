/*
 * function: FIELD_PLACE_NAME_ResetSpawnCounts
 * address:  0x021BC838
 * packet:   pkt_ov021_021BC838
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf: clears bytes +0x148 and +0x14B.
 */

void FIELD_PLACE_NAME_ResetSpawnCounts(char *p)
{
    p[0x148] = 0;
    p[0x14b] = 0;
}
