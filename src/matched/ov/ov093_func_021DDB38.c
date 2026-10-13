/*
 * function: BTL_ITEM_GetWeakenDamageIceHandlers
 * address: 0x021DDB38
 * packet: pkt_ov093_021DDB38
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
 *   gBtlItemWeakenDamageIceHandlers 0x021F17AC data ov093 a4
 */

int *BTL_ITEM_GetWeakenDamageIceHandlers(int *p);

/* 021DDB44  shape F2: two stack constants (0xe, 0) */
extern int gBtlItemWeakenDamageIceHandlers[];

int *BTL_ITEM_GetWeakenDamageIceHandlers(int *p)
{
    *p = 2;
    return gBtlItemWeakenDamageIceHandlers;
}
