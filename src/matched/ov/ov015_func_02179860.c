/*
 * function: IRCNET_CbIsLinkUp
 * address: 0x02179860
 * packet: pkt_ov015_02179860
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
 *   IRCNET_IsLinkUp 0x02179CAC thumb ov015
 */

extern int IRCNET_IsLinkUp(void);
int IRCNET_CbIsLinkUp(void);

int IRCNET_CbIsLinkUp(void)
{
    return IRCNET_IsLinkUp();
}
