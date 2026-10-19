/*
 * function: BOX2_MAIN_StepHandMotionToSlotB
 * address:  0x021DEB08
 * packet:   pkt_ov170_021DEB08
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_StepHandMotion 0x021DEA6C thumb
 *
 * Steps the object with mode 0 (sibling of BOX2_MAIN_IsSwapScene, which passes 1).
 */

extern int BOX2_MAIN_StepHandMotion(char *p, int a);

int BOX2_MAIN_StepHandMotionToSlotB(unsigned char *p)
{
    return BOX2_MAIN_StepHandMotion((char *)p, 0);
}
