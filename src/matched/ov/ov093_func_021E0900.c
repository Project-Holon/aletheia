/*
 * function: HAND_WAZA_BrickBreakSkipScreens
 * address:  0x021E0900
 * packet:   pkt_ov093_021E0900
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callback passed to BTL_EVENT_SetFactorSkipCheck by HAND_WAZA_BrickBreakSetSkipCheck (pool word 0x021E0901).
 * Not a worklist entry; filed as the witness for that relocation.
 *
 */

int HAND_WAZA_BrickBreakSkipScreens(int a, int b, int c, int d, unsigned short e)
{
    if (c == 2 && e <= 1)
        return 1;
    return 0;
}
