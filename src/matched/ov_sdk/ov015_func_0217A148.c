/*
 * function: IRC_Send
 * address:  0x0217A148
 * packet:   pkt_02179F28
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   d_0217ABA8  0x0217ABA8  data  ov015
 *   d_0217AAB0  0x0217AAB0  data  ov015
 *   IRCi_Send  0x0217A034  arm  ov015
 */

#include "../include/G_ov015_0217ABA8.h"

extern struct G_ov015_0217ABA8 d_0217ABA8;
extern unsigned char d_0217AAB0[];
extern void IRCi_Send(int a0, int a1, int a2, int a3);

void IRC_Send(int a0, int a1, int a2)
{
    if (*(int *)(((char *)&d_0217ABA8) + 0x24))
        IRCi_Send(a0, a1, a2, d_0217AAB0[0]);
}
