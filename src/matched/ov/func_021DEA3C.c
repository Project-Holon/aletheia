/*
 * function: BOX2_MAIN_StartHandMotionToBoxSlot
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
 *   BOX2_MAIN_StartHandMotionToSlot  0x021DE8B4  thumb  ov170
 *
 * Same call with the fifth argument fixed to 1.
 */



extern void BOX2_MAIN_StartHandMotionToSlot(unsigned char *p, int slot, unsigned idx, int mode, int flag);
void BOX2_MAIN_StartHandMotionToBoxSlot(int a, int b, int c, int d)
{
    BOX2_MAIN_StartHandMotionToSlot((unsigned char *)a, b, c, d, 1);
}
