/*
 * function: IRCNET_CbSetRecvCallback
 * address:  0x02179840
 * packet:   pkt_ov015_02179840
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   IRCNET_SetRecvCallback  0x021799B4  thumb ov015
 */

void IRCNET_SetRecvCallback(unsigned v);

int IRCNET_CbSetRecvCallback(int v)
{
    IRCNET_SetRecvCallback(v);
    return 1;
}
