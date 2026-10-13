/*
 * function: HAND_WAZA_SelfDestructGetHandlers
 * address: 0x021E1DC0
 * packet: pkt_ov093_021E1DC0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E1C8C.c and filed here.
 *
 * symbols:
 *   gSelfDestructHandlers 0x021F2C60 data ov093 a4
 */

int *HAND_WAZA_SelfDestructGetHandlers(int *p);
extern int gSelfDestructHandlers[];

int *HAND_WAZA_SelfDestructGetHandlers(int *p)
{
    *p = 3;
    return gSelfDestructHandlers;
}
