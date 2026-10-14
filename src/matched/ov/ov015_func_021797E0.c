/*
 * function: IRCNET_CbConnect
 * address:  0x021797E0
 * packet:   pkt_021797E0
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   IRC_Connect  0x02179FC4  arm
 */

void IRC_Connect(void);

int IRCNET_CbConnect(void)
{
    IRC_Connect();
    return 1;
}
