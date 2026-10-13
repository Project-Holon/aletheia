/*
 * function: HAND_TOKUSEI_DampAddSkipCheck
 * address: 0x021DAE94
 * packet: pkt_ov093_021DAE94
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DA624_p01.c and filed here.
 *
 * symbols:
 *   BTL_EVENT_SetFactorSkipCheck 0x021D7320 thumb ov093
 *   HAND_TOKUSEI_DampSkipAftermath 0x021DAEC4 thumb ov093
 */

typedef unsigned int u32;
void BTL_EVENT_SetFactorSkipCheck(void *p, u32 v);
int HAND_TOKUSEI_DampSkipAftermath(int a, int b, int c, int d, unsigned short e);
void HAND_TOKUSEI_DampAddSkipCheck(void *p);

void HAND_TOKUSEI_DampAddSkipCheck(void *p)
{
    BTL_EVENT_SetFactorSkipCheck(p, (u32)HAND_TOKUSEI_DampSkipAftermath);
}
