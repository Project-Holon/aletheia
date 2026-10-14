/*
 * function: IRCNET_IsLinkUp
 * address:  0x02179CAC
 * packet:   pkt_02179CAC
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0217AB80  0x0217AB80  data  ov015
 *   d_0217ABA0  0x0217ABA0  data  ov015
 *   IRCNET_IsLinkAlive  0x02179D3C  thumb  ov015
 */

#include "../include/G_s_aba0.h"
#include "../include/G_State.h"

extern struct State d_0217AB80;
extern struct s_aba0 d_0217ABA0;
extern int IRCNET_IsLinkAlive(void);

int IRCNET_IsLinkUp(void)
{
    if (((unsigned char *)&d_0217AB80)[0xc] == 0)
        return 0;
    if (((unsigned char *)&d_0217ABA0)[5] != 0)
        return 1;
    if (((unsigned char *)&d_0217AB80)[0x1d] == 1) {
        if (IRCNET_IsLinkAlive() == 0)
            return 1;
    }
    return 0;
}
