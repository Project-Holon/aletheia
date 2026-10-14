/*
 * function: POKETRADE_NEGO_TickMarkerTimers
 * address:  0x021DF868
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Count the two arm timers down and re-arm the ones that expired.
 *
 * symbols:
 *   POKETRADE_PROC_IsHostSide  0x021D8AA8  thumb  ov119
 *   POKETRADE_2D_DeleteMarkerButtonPair  0x021E68B4  thumb  ov119
 */

extern int POKETRADE_PROC_IsHostSide(void *p);
extern void POKETRADE_2D_DeleteMarkerButtonPair(int p, int n);

void POKETRADE_NEGO_TickMarkerTimers(void *p)
{
    int i;

    if (POKETRADE_PROC_IsHostSide(p) == 0)
        return;
    for (i = 0; i < 2; i++) {
        if (((unsigned char *)p)[0x11e4 + i] == 0)
            continue;
        ((unsigned char *)p)[0x11e4 + i]--;
        if (((unsigned char *)p)[0x11e4 + i] == 0)
            POKETRADE_2D_DeleteMarkerButtonPair((int)p, i);
    }
}

