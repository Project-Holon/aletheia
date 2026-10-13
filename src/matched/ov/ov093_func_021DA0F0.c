/*
 * function: HAND_TOKUSEI_AddSynchronize
 * address: 0x021DA0F0
 * packet: pkt_ov093_021DA0F0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D9ADC.c and filed here.
 *
 * symbols:
 *   d_021F0810 0x021F0810 data ov093 a4
 */

int *HAND_TOKUSEI_AddSynchronize(int *p);

/* 021DA0FC  shape F1: gate on BTL_EVENT_GetVar(3) */
extern int d_021F0810[];

int *HAND_TOKUSEI_AddSynchronize(int *p)
{
    *p = 1;
    return d_021F0810;
}
