/*
 * function: IRCNET_CbIsLinkAlive
 * address: 0x02179890
 * packet: pkt_ov015_02179890
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
 *   IRCNET_IsLinkAlive 0x02179D3C thumb ov015
 */

int IRCNET_IsLinkAlive(void);
int IRCNET_CbIsLinkAlive(void);

int IRCNET_CbIsLinkAlive(void)
{
    return IRCNET_IsLinkAlive();
}
