/*
 * function: HAND_TOKUSEI_AddTrace
 * address: 0x021DA144
 * packet: pkt_ov093_021DA144
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
 *   gTraceHandlers 0x021F07F8 data ov093 a4
 */

int *HAND_TOKUSEI_AddTrace(int *p);
extern int gTraceHandlers[];

int *HAND_TOKUSEI_AddTrace(int *p)
{
    *p = 1;
    return gTraceHandlers;
}
