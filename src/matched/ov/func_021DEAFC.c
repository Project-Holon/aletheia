/*
 * function: BOX2_MAIN_StepHandMotionToSlot
 * address:  0x021DEAFC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_StepHandMotion  0x021DEA6C  thumb  ov170
 *
 * Set the flag on the object.
 */

extern int BOX2_MAIN_StepHandMotion(char *p, int a);

int BOX2_MAIN_StepHandMotionToSlot(int a)
{
    return BOX2_MAIN_StepHandMotion((char *)a, 1);
}

