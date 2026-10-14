/*
 * function: IRCNET_CbHasPeer
 * address: 0x02179880
 * packet: pkt_ov015_02179880
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
 *   IRCNET_HasPeer 0x02179D68 thumb ov015
 */

extern unsigned char IRCNET_HasPeer(void);
unsigned char IRCNET_CbHasPeer(void);

unsigned char IRCNET_CbHasPeer(void)
{
    return IRCNET_HasPeer();
}
