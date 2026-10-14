/*
 * function: POKETRADE_NEGO_SetOfferMarkersState
 * address:  0x021DF7AC
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
 *   POKETRADE_2D_SetMarkerActorVisible  0x021E6790  thumb  ov119
 */

extern int POKETRADE_PROC_IsHostSide(void *p);
extern void POKETRADE_2D_SetMarkerActorVisible(void *p, int i, int a);

void POKETRADE_NEGO_SetOfferMarkersState(void *p, int a)
{
    int i;

    if (POKETRADE_PROC_IsHostSide(p) == 0)
        return;
    for (i = 0; i < 4; i++)
        POKETRADE_2D_SetMarkerActorVisible(p, i, a);
}

