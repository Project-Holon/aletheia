/*
 * function: BTL_ITEM_GetWeakenDamageFlyingHandlers
 * address: 0x021DDBB8
 * packet: pkt_ov093_021DDBB8
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
 *   gBtlItemWeakenDamageFlyingHandlers 0x021F17DC data ov093 a4
 */

int *BTL_ITEM_GetWeakenDamageFlyingHandlers(int *p);

/* 021DDBC4  shape F2: two stack constants (2, 0) */
extern int gBtlItemWeakenDamageFlyingHandlers[];

int *BTL_ITEM_GetWeakenDamageFlyingHandlers(int *p)
{
    *p = 2;
    return gBtlItemWeakenDamageFlyingHandlers;
}
