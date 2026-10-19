/*
 * function: HAND_TOKUSEI_AddRockHead
 * address: 0x021DA114
 * packet: pkt_ov093_021DA114
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
 *   gMoldBreakerHandlerEntries 0x021F0808 data ov093 a4
 */

int *HAND_TOKUSEI_AddRockHead(int *p);

/* 021DA120  shape F1: gate on BTL_EVENT_GetVar(2) */
extern int gMoldBreakerHandlerEntries[];

int *HAND_TOKUSEI_AddRockHead(int *p)
{
    *p = 1;
    return gMoldBreakerHandlerEntries;
}
