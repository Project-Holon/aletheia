/*
 * function: HAND_SIDE_GetHandlersStealthRock
 * address: 0x06899260
 * packet: pkt_ov095_06899260
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Follower after the fixed linker veneer at 06899250; ends at 0689926C.
 * symbols:
 *   gHandSideStealthRockHandlers 0x0689D728 data a4
 */
extern unsigned char gHandSideStealthRockHandlers[];

void *HAND_SIDE_GetHandlersStealthRock(int *p)
{
    *p = 1;
    return gHandSideStealthRockHandlers;
}
