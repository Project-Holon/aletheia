/*
 * function: HAND_WAZA_AddSleepTalk
 * address: 0x021E6CD0
 * packet: pkt_ov093_021E6CD0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E6AD8_p02.c and filed here.
 *
 * symbols:
 *   gSleepTalkHandlers 0x021F2BB8 data ov093 a4
 */

extern int gSleepTalkHandlers[];
int *HAND_WAZA_AddSleepTalk(int *p);

int *HAND_WAZA_AddSleepTalk(int *p)
{
    *p = 3;
    return gSleepTalkHandlers;
}
