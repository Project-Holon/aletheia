/*
 * function: BTL_CLIENT_StepChoiceMode2
 * address: 0x021D0D38
 * packet: pkt_ov093_021D0D38
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/btl_server_p125.c and filed here.
 *
 * symbols:
 *   BTL_CLIENT_StepChooseReplacement 0x021D0E7C thumb
 */

typedef unsigned char u8;
int BTL_CLIENT_StepChoiceMode2(u8 *p, int *state);
int BTL_CLIENT_StepChooseReplacement(u8 *p, int *state, u8 param);

int BTL_CLIENT_StepChoiceMode2(u8 *p, int *state)
{
    return BTL_CLIENT_StepChooseReplacement(p, state, 2);
}
