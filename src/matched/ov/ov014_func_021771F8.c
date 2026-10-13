/*
 * function: NET_WHPIPE_IsWhIdle
 * address:  0x021771F8
 * packet:   pkt_ov014_021771F8
 * region:   ov014
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * sdk:      NET_WHPIPE_IsWhIdle (libdwcghttp.TWL.HYB.thumb.a(dwc_ghttp.o))
 *
 * symbols:
 *   WIH_GetSysState  0x02178E4C  thumb  ov014
 */

extern int WIH_GetSysState(char *url);

int NET_WHPIPE_IsWhIdle(char *url)
{
    if (WIH_GetSysState(url) == 1)
        return 1;
    return 0;
}
