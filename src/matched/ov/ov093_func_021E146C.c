/*
 * function: HAND_WAZA_AddSuperFang
 * address: 0x021E146C
 * packet: pkt_ov093_021E146C
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
 *   gSuperFangHandlers 0x021F25A4 data ov093 a4
 */

int *HAND_WAZA_AddSuperFang(int *p);
extern int gSuperFangHandlers[];

int *HAND_WAZA_AddSuperFang(int *p)
{
    *p = 1;
    return gSuperFangHandlers;
}
