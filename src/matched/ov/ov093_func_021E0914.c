/*
 * function: HAND_WAZA_GetJumpKickHandlers
 * address: 0x021E0914
 * packet: pkt_ov093_021E0914
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E072C_p02.c and filed here.
 *
 * symbols:
 *   gJumpKickHandlers 0x021F2504 data a4
 */

int *HAND_WAZA_GetJumpKickHandlers(int *p);
extern int gJumpKickHandlers[];

int *HAND_WAZA_GetJumpKickHandlers(int *p)
{
    *p = 1;
    return gJumpKickHandlers;
}
