/*
 * function: FIELD_PLACE_NAME_HasWindow
 * address:  0x021BD140
 * packet:   pkt_ov021_021BD140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZONEDATA_GetPlaceNameWindow  0x02013E6C  thumb  arm9
 */

typedef unsigned int   u32;
extern u32 ZONEDATA_GetPlaceNameWindow(u32 id);

void FIELD_PLACE_NAME_HasWindow(void *a, int b, int c)
{
    ZONEDATA_GetPlaceNameWindow((u32)a);
}
