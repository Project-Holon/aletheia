/*
 * function: HAND_TOKUSEI_GetSwarmHandlers
 * address: 0x021D8CA0
 * packet: pkt_ov093_021D8CA0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D8B50.c and filed here.
 *
 * symbols:
 *   gSwarmHandlers 0x021F0640 data ov093 a4
 */

int *HAND_TOKUSEI_GetSwarmHandlers(int *p);
extern int gSwarmHandlers[];

int *HAND_TOKUSEI_GetSwarmHandlers(int *p)
{
    *p = 1;
    return gSwarmHandlers;
}
