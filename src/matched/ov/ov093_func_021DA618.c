/*
 * function: HAND_TOKUSEI_AddAnticipation
 * address: 0x021DA618
 * packet: pkt_ov093_021DA618
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DA3D8.c and filed here.
 *
 * symbols:
 *   gAnticipationHandlers 0x021F09A0 data ov093 a4
 */

extern int gAnticipationHandlers[];
int *HAND_TOKUSEI_AddAnticipation(int *p);

int *HAND_TOKUSEI_AddAnticipation(int *p)
{
    *p = 2;
    return gAnticipationHandlers;
}
