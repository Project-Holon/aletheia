/*
 * function: BTL_POKEPARAM_SetNeutralStatStages
 * address:  0x021D53C8
 * packet:   pkt_021D53C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_SetNeutralStatStages   0x021D53C8  thumb ov093
 *
 * Unlabelled ov093 leaf: writes 6 into the first seven bytes of its argument.
 * Matched to provide the `matched` witness for the two pending files that call
 * it (BTL_POKEPARAM_InitStatStages, BTL_POKEPARAM_ResetStatStages).
 */

void BTL_POKEPARAM_SetNeutralStatStages(unsigned char *p)
{
    p[0] = 6;
    p[1] = 6;
    p[2] = 6;
    p[3] = 6;
    p[4] = 6;
    p[5] = 6;
    p[6] = 6;
}
