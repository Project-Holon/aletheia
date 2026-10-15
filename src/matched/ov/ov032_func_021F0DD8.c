/*
 * function: BEACON_VIEW_PlaySe
 * address:  0x021F0DD8
 * packet:   pkt_ov032_021F0DD8
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_PlaySe 0x021F0DD8 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */

extern void GFL_USE_PlaySeDefaultVolume(unsigned int a);

void BEACON_VIEW_PlaySe(unsigned int a)
{
    GFL_USE_PlaySeDefaultVolume(a);
}
