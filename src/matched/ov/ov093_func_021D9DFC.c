/*
 * function: HAND_TOKUSEI_AddEffectSpore
 * address: 0x021D9DFC
 * packet: pkt_ov093_021D9DFC
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
 *   gEffectSporeHandlers 0x021F0830 data ov093 a4
 */

int *HAND_TOKUSEI_AddEffectSpore(int *p);
extern int gEffectSporeHandlers[];

int *HAND_TOKUSEI_AddEffectSpore(int *p)
{
    *p = 1;
    return gEffectSporeHandlers;
}
