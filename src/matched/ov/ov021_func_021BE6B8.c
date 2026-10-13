/*
 * function: FLD_EXP_OBJ_SetAnimeLoop
 * address:  0x021BE6B8
 * packet:   pkt_ov021_021BE6B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: strb r1, [r0, #1].
 *
 * symbols:
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb
 */

void FLD_EXP_OBJ_SetAnimeLoop(unsigned char *p, int v)
{
    p[1] = v;
}
