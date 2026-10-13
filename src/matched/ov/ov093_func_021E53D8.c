/*
 * function: HAND_WAZA_AddTailwind
 * address: 0x021E53D8
 * packet: pkt_ov093_021E53D8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E535C.c and filed here.
 *
 * symbols:
 *   gTailwindHandlers 0x021F25EC data ov093 a4
 */

int *HAND_WAZA_AddTailwind(int *p);
extern int gTailwindHandlers[];

int *HAND_WAZA_AddTailwind(int *p)
{
    *p = 1;
    return gTailwindHandlers;
}
