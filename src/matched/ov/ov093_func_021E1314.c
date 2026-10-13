/*
 * function: HAND_WAZA_AddTrap
 * address: 0x021E1314
 * packet: pkt_ov093_021E1314
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E12A4.c and filed here.
 *
 * symbols:
 *   gBindSickHandlers 0x021F2918 data ov093 a4
 */

int *HAND_WAZA_AddTrap(int *p);
extern int gBindSickHandlers[];

int *HAND_WAZA_AddTrap(int *p)
{
    *p = 2;
    return gBindSickHandlers;
}
