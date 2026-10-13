/*
 * function: BTL_ITEM_GetWeakenDamageFightingHandlers
 * address: 0x021DDB58
 * packet: pkt_ov093_021DDB58
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DDB24.c and filed here.
 *
 * symbols:
 *   gBtlItemWeakenDamageFightingHandlers 0x021F171C data ov093 a4
 */

int *BTL_ITEM_GetWeakenDamageFightingHandlers(int *p);
extern int gBtlItemWeakenDamageFightingHandlers[];

int *BTL_ITEM_GetWeakenDamageFightingHandlers(int *p)
{
    *p = 2;
    return gBtlItemWeakenDamageFightingHandlers;
}
