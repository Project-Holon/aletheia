/*
 * function: FIELD_GIMMICK_SWITCH_TOGGLE_IsRequirementMet
 * address:  0x021F3908
 * packet:   pkt_021F3908
 * region:   ov045
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two parallel halfword tables; the second at 0x021F3B62 is declared without a
 * region token so the function's own ov045 window fixes it.
 *
 * symbols:
 *   sSwitchToggleRequirementSwitchIndex  0x021F3B60  data  ov045
 *   sSwitchToggleRequirementState  0x021F3B62  data
 */

extern unsigned short sSwitchToggleRequirementSwitchIndex[];
extern unsigned short sSwitchToggleRequirementState[];

int FIELD_GIMMICK_SWITCH_TOGGLE_IsRequirementMet(char *a0, int a1)
{
    unsigned short v = (unsigned short)(*(unsigned int *)(a0 + sSwitchToggleRequirementSwitchIndex[a1 * 2] * 4) != 0);

    return v == sSwitchToggleRequirementState[a1 * 2];
}
