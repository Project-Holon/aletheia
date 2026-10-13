/*
 * function: BTL_CLIENT_StepChoiceMode1
 * address: 0x021D0D44
 * packet: pkt_ov093_021D0D44
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
 *   func_021D0E7C 0x021D0E7C thumb
 */

typedef unsigned char u8;
int BTL_CLIENT_StepChoiceMode1(u8 *p, int *state);
int func_021D0E7C(u8 *p, int *state, u8 param);

int BTL_CLIENT_StepChoiceMode1(u8 *p, int *state)
{
    return func_021D0E7C(p, state, 1);
}
