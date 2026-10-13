/*
 * function: HAND_ITEM_GetWaveIncenseHandlers
 * address: 0x021DF90C
 * packet: pkt_ov093_021DF90C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF8E8.c and filed here.
 *
 * symbols:
 *   gWaveIncenseHandlers 0x021F14DC data ov093 a4
 */

int *HAND_ITEM_GetWaveIncenseHandlers(int *p);
extern int gWaveIncenseHandlers[];

int *HAND_ITEM_GetWaveIncenseHandlers(int *p)
{
    *p = 1;
    return gWaveIncenseHandlers;
}
