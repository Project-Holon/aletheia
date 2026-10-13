/*
 * function: IRCNET_IsSender
 * address:  0x02179C98
 * packet:   pkt_ov015_02179C98
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * sdk:      IRCNET_IsSender (libdwcghttp.TWL.HYB.thumb.a(dwc_ghttp.o))
 *
 * symbols:
 *   IRCNET_GetSenderFlag  0x02179D30  thumb  ov015
 */

extern int IRCNET_GetSenderFlag(char *url);

int IRCNET_IsSender(char *url)
{
    if (IRCNET_GetSenderFlag(url) == 1)
        return 1;
    return 0;
}
