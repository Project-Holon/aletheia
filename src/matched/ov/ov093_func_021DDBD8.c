/*
 * function: BTL_ITEM_GetWeakenDamagePsychicHandlers
 * address: 0x021DDBD8
 * packet: pkt_ov093_021DDBD8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DDBA4.c and filed here.
 *
 * symbols:
 *   gBtlItemWeakenDamagePsychicHandlers 0x021F172C data ov093 a4
 */

int *BTL_ITEM_GetWeakenDamagePsychicHandlers(int *p);
extern int gBtlItemWeakenDamagePsychicHandlers[];

int *BTL_ITEM_GetWeakenDamagePsychicHandlers(int *p)
{
    *p = 2;
    return gBtlItemWeakenDamagePsychicHandlers;
}
