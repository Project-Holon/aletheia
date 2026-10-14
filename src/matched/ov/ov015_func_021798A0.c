/*
 * function: IRCNET_CbGetLinkState
 * address:  0x021798A0
 * packet:   pkt_021798A0
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   IRCNET_IsLinkAlive  0x02179D3C  thumb  ov015
 */

extern int IRCNET_IsLinkAlive(void);

int IRCNET_CbGetLinkState(void)
{
    if (IRCNET_IsLinkAlive())
        return 3;
    return 0;
}
