/*
 * function: IRCNET_Stop
 * address: 0x02179998
 * packet: pkt_ov015_02179998
 * region: ov015
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_0217AB80 0x0217AB80 data ov015 a1
 *   IRC_Shutdown 0x0217A134 arm ov015
 */

#include "../include/G_State.h"

extern struct State d_0217AB80;
extern void IRC_Shutdown(void);
void IRCNET_Stop(void)
{
    if (((unsigned char *)&d_0217AB80)[0xC] == 1) IRC_Shutdown();
    ((unsigned char *)&d_0217AB80)[0xC] = 0;
}
