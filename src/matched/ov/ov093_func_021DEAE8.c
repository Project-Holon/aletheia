/*
 * function: HAND_ITEM_GetFocusBandHandlers
 * address: 0x021DEAE8
 * packet: pkt_ov093_021DEAE8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DE980.c and filed here.
 *
 * symbols:
 *   gFocusBandHandlers 0x021F191C data a4
 */

int *HAND_ITEM_GetFocusBandHandlers(int *p);
extern int gFocusBandHandlers;

/*
 * lever: int n = (unsigned char)HAND_ITEM_GetParam(a,2) schedules the
 * narrowing in r0 then r1. An inline call cast costs an extra copy (62 B).
 */
int *HAND_ITEM_GetFocusBandHandlers(int *p)
{
    *p = 3;
    return &gFocusBandHandlers;
}
