/*
 * function: FLD_EXP_OBJ_SetAnimePaused
 * address:  0x021BE6B0
 * packet:   pkt_ov021_021BE6B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: strb r1, [r0].
 *
 * symbols:
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb
 */

void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v)
{
    p[0] = v;
}
