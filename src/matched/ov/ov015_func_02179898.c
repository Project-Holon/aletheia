/*
 * function: IRCNET_CbGetRunning
 * address: 0x02179898
 * packet: pkt_ov015_02179898
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
 *   IRCNET_IsRunning 0x021799F0 thumb
 */

unsigned char IRCNET_CbGetRunning(void);
unsigned char IRCNET_IsRunning(void);

unsigned char IRCNET_CbGetRunning(void)
{
    return IRCNET_IsRunning();
}
