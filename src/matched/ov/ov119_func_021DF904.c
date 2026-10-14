/*
 * function: POKETRADE_NEGO_ExitMarkers
 * address:  0x021DF904
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tear the object down when it is in the first state.
 *
 * symbols:
 *   POKETRADE_PROC_IsHostSide  0x021D8AA8  thumb  ov119
 *   POKETRADE_2D_RegisterMarkerResources  0x021E57FC  thumb  ov119
 */

extern int POKETRADE_PROC_IsHostSide(void *p);
extern void POKETRADE_2D_RegisterMarkerResources(int p);

void POKETRADE_NEGO_ExitMarkers(void *p)
{
    if (POKETRADE_PROC_IsHostSide(p))
        POKETRADE_2D_RegisterMarkerResources((int)p);
}

