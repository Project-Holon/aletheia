/*
 * function: FIELD_PLAYER_FinishFormChange
 * address:  0x021A2F60
 * packet:   pkt_ov021_021A2F60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (a .word run in the ov021 listing): tail-calls
 * FIELD_PLAYER_CORE_FinishFormChange with the word at offset 4.  Callee of FIELD_EVENT_CHECK_LedgeJumpTaskMain.
 *
 * symbols:
 *   FIELD_PLAYER_CORE_FinishFormChange  0x021A3CE8  thumb
 * Addresses are Black-image addresses.
 */

extern void FIELD_PLAYER_CORE_FinishFormChange(int a);

void FIELD_PLAYER_FinishFormChange(int *p)
{
    FIELD_PLAYER_CORE_FinishFormChange(p[1]);
}
