/*
 * function: FIELD_PLACE_NAME_ReleaseWindow
 * address:  0x021BC63C
 * packet:   pkt_ov021_021BC63C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLACE_NAME_FreeBgChars  0x021BC704  thumb  ov021
 *   FIELD_PLACE_NAME_DeleteBmpWin  0x021BD07C  thumb  ov021
 */

extern void func_020414AC(int a);
extern void FIELD_PLACE_NAME_FreeBgChars(void *p);
extern void FIELD_PLACE_NAME_DeleteBmpWin(void *p);

void FIELD_PLACE_NAME_ReleaseWindow(void *p)
{
    func_020414AC(3);
    FIELD_PLACE_NAME_FreeBgChars(p);
    FIELD_PLACE_NAME_DeleteBmpWin(p);
}
