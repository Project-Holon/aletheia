/*
 * function: HAND_WAZA_LeechSeedGetHandlers
 * address: 0x021E1FF8
 * packet: pkt_ov093_021E1FF8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E1E44.c and filed here.
 *
 * symbols:
 *   gLeechSeedHandlers 0x021F250C data ov093 a4
 */

int *HAND_WAZA_LeechSeedGetHandlers(int *p);
extern int gLeechSeedHandlers[];

int *HAND_WAZA_LeechSeedGetHandlers(int *p)
{
    *p = 1;
    return gLeechSeedHandlers;
}
