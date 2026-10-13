/*
 * function: WCM_SearchAsync
 * address:  0x02165144
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Dispatches on whether either argument is missing.
 *
 * symbols:
 *   WCM_EndSearchAsync  0x02165204  arm  ov009
 *   WCM_BeginSearchAsync  0x02165164  arm  ov009
 */

extern long WCM_EndSearchAsync(int a, int b);
extern long WCM_BeginSearchAsync(void *bssid, void *essid, unsigned long option);

void WCM_SearchAsync(void *a, void *b, unsigned long a2)
{
    if (a == 0 || b == 0) {
        WCM_EndSearchAsync((int)a, (int)b);
        return;
    }

    WCM_BeginSearchAsync(a, b, a2);
}

