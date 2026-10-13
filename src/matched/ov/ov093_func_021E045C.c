/*
 * function: HAND_WAZA_GetConversionHandlers
 * address: 0x021E045C
 * packet: pkt_ov093_021E045C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E0284.c and filed here.
 *
 * symbols:
 *   gHandWazaConversionHandlers 0x021F261C data ov093 a4
 */

int *HAND_WAZA_GetConversionHandlers(int *p);
extern int gHandWazaConversionHandlers[];

int *HAND_WAZA_GetConversionHandlers(int *p)
{
    *p = 1;
    return gHandWazaConversionHandlers;
}
