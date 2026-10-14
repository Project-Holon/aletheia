/*
 * function: IRCNET_CbIsSendReady
 * address: 0x02179878
 * packet: pkt_ov015_02179878
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
 *   IRCNET_IsSendReady 0x021799FC thumb
 */

typedef unsigned char u8;
unsigned char IRCNET_CbIsSendReady(void);
u8 IRCNET_IsSendReady(void);

unsigned char IRCNET_CbIsSendReady(void)
{
    return IRCNET_IsSendReady();
}
