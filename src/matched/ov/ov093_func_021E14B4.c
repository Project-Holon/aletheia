/*
 * function: HAND_WAZA_AddDragonRage
 * address: 0x021E14B4
 * packet: pkt_ov093_021E14B4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E1478.c and filed here.
 *
 * symbols:
 *   gDragonRageHandlers 0x021F26EC data ov093 a4
 */

int *HAND_WAZA_AddDragonRage(int *p);

/* 021E14C0  shape F1: gate on BTL_EVENT_GetVar(3) */
extern int gDragonRageHandlers[];

int *HAND_WAZA_AddDragonRage(int *p)
{
    *p = 1;
    return gDragonRageHandlers;
}
