/*
 * function: BOX2_MAIN_PlaceMonSceneFromBox
 * address:  0x021DEA3C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_PlaceMonScene  0x021DE8B4  thumb  ov170
 *
 * Same call with the fifth argument fixed to 1.
 */



extern void BOX2_MAIN_PlaceMonScene(unsigned char *p, int slot, unsigned idx, int mode, int flag);
void BOX2_MAIN_PlaceMonSceneFromBox(int a, int b, int c, int d)
{
    BOX2_MAIN_PlaceMonScene((unsigned char *)a, b, c, d, 1);
}
