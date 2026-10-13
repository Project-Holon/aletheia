/*
 * file:     unit_02179810.c
 * function: IRCNET_IsNotRunning
 * address:  0x02179810
 * packet:   pkt_ov015_02179810
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * sdk:      IRCNET_IsNotRunning (libdwcmatch.TWL.HYB.thumb.a(dwc_match.o))
 *
 * symbols:
 *   IRCNET_IsRunning  0x021799F0  thumb  ov015
 */

extern unsigned char IRCNET_IsRunning(void);

int IRCNET_IsNotRunning(void)
{
    if (IRCNET_IsRunning() == 0)
        return 1;
    return 0;
}
