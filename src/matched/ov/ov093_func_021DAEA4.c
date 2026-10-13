/*
 * function: HAND_TOKUSEI_DampRemoveSkipCheck
 * address: 0x021DAEA4
 * packet: pkt_ov093_021DAEA4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DA624.c and filed here.
 *
 * symbols:
 *   BTL_EVENT_ClearFactorSkipCheck 0x021D7324 thumb ov093
 */

typedef unsigned char u8;
extern void BTL_EVENT_ClearFactorSkipCheck();
void HAND_TOKUSEI_DampRemoveSkipCheck(u8 *p);

void HAND_TOKUSEI_DampRemoveSkipCheck(u8 *p)
{
    BTL_EVENT_ClearFactorSkipCheck(p);
}
