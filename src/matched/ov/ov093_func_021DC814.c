/*
 * function: BTL_ABILITY_GetZenModeHandlers
 * address: 0x021DC814
 * packet: pkt_ov093_021DC814
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DC6EC.c and filed here.
 *
 * symbols:
 *   gZenModeHandlers 0x021F0B48 data ov093 a4
 */

int *BTL_ABILITY_GetZenModeHandlers(int *p);

/*
 * lever: scalar u16/u8 stack inputs; named result preserves cmp operand order.
 */
extern int gZenModeHandlers[];

int *BTL_ABILITY_GetZenModeHandlers(int *p)
{
    *p = 3;
    return gZenModeHandlers;
}
