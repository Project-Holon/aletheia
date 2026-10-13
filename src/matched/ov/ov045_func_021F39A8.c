/*
 * function: GIMMICK45_IsSwitchOn
 * address:  0x021F39A8
 * packet:   pkt_ov045_021F39A8
 * region:   ov045
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: whether slot i of the word table is non-zero.
 *
 * symbols:
 *   GIMMICK45_IsSwitchOn  0x021F39A8  thumb
 */

int GIMMICK45_IsSwitchOn(int *p, int i)
{
    return p[i] != 0;
}
