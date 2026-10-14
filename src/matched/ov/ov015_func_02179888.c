/*
 * function: IRCNET_CbIsConnected
 * address: 0x02179888
 * packet: pkt_ov015_02179888
 * region: ov015
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov015/unit_02179824.c and filed here.
 *
 * symbols:
 *   IRCNET_IsConnected 0x02179D78 thumb ov015
 */

extern int IRCNET_IsConnected(void);
int IRCNET_CbIsConnected(void);

int IRCNET_CbIsConnected(void)
{
    return IRCNET_IsConnected();
}
