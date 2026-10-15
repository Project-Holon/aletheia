/*
 * function: WF2DMAP_OBJDRAW_GetFrameValue
 * address:  0x021C58F8
 * packet:   pkt_021C58F8
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFI_2DCHAR_GetActorCellArgB  0x021C4268  thumb
 *   sWf2dmapSlotValues     0x021C60B6  data  a1
 *
 * Addresses are Black-image addresses.
 */

extern int WIFI_2DCHAR_GetActorCellArgB(char *);
extern unsigned char sWf2dmapSlotValues[];

int WF2DMAP_OBJDRAW_GetFrameValue(char *p, int b)
{
    if (WIFI_2DCHAR_GetActorCellArgB(p) == 2)
        return 0;
    return sWf2dmapSlotValues[b];
}
