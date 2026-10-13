/*
 * function: OEKAKI_OnMemberLeft
 * address:  0x021848CC
 * packet:   pkt_ov023_021848CC
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled empty callback (a lone bx lr after OEKAKI_OnMemberJoined's pool);
 * OEKAKI_Main hands its address to ov022 UNION_APP_SetCallbacks. Blocker of
 * ov023 OEKAKI_Main.
 */

void OEKAKI_OnMemberLeft(void)
{
}
