/*
 * function: POKETRADE_NEGO_UpdateOfferMarkers
 * address:  0x021DF7D0
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Init the four sub-objects when the object is in the first state.
 *
 * symbols:
 *   POKETRADE_PROC_IsHostSide  0x021D8AA8  thumb  ov119
 *   POKETRADE_2D_DeleteMarkerActor  0x021E67A8  thumb  ov119
 */

extern int POKETRADE_PROC_IsHostSide(void *p);
extern void POKETRADE_2D_DeleteMarkerActor(void *p, int i);

void POKETRADE_NEGO_UpdateOfferMarkers(void *p)
{
    int i;

    if (POKETRADE_PROC_IsHostSide(p) == 0)
        return;
    for (i = 0; i < 4; i++)
        POKETRADE_2D_DeleteMarkerActor(p, i);
}

