/*
 * function: POKETRADE_NEGO_ResetMarkers
 * address:  0x021DF8E0
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reset the two sub-objects and the decoder when in the first state.
 *
 * symbols:
 *   POKETRADE_PROC_IsHostSide  0x021D8AA8  thumb  ov119
 *   POKETRADE_2D_DeleteMarkerButtonPair  0x021E68B4  thumb  ov119
 *   POKETRADE_2D_ReleaseMarkerResources  0x021E5868  thumb  ov119
 */

extern int POKETRADE_PROC_IsHostSide(void *p);
extern void POKETRADE_2D_DeleteMarkerButtonPair(int p, int n);
extern void POKETRADE_2D_ReleaseMarkerResources(char *p);

void POKETRADE_NEGO_ResetMarkers(void *p)
{
    int i;

    if (POKETRADE_PROC_IsHostSide(p) == 0)
        return;
    for (i = 0; i < 2; i++)
        POKETRADE_2D_DeleteMarkerButtonPair((int)p, i);
    POKETRADE_2D_ReleaseMarkerResources(p);
}

