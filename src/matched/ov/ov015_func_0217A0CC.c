/*
 * function: IRCi_Finish
 * address:  0x0217A0CC
 * packet:   pkt_ov015_0217A0CC
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    2026-10-05 wave P18 lane 8: libirc finish. When the field at d_0217ABA8 + 0x24 is set, and the field at
 *           +0x18 and the argument n are both zero, sends a 0xF4 frame through IRCi_Send. Then calls the
 *           callback stored at +0xC with n when it is set, and resets the state with IRCi_ResetState.
 *
 * symbols:
 *   IRCi_Send  0x0217A034  arm    ov015
 *   IRCi_ResetState  0x02179F48  arm    ov015
 *   d_0217ABA8     0x0217ABA8  data   ov015
 *   g_0217AAB0     0x0217AAB0  data   ov015
 */

#include "../include/G_ov015_0217ABA8.h"

extern struct G_ov015_0217ABA8 d_0217ABA8;
extern unsigned char g_0217AAB0[];
extern void IRCi_Send(unsigned char *data, unsigned char size, int command, unsigned char id);
extern void IRCi_ResetState(void);

void IRCi_Finish(int n)
{
    void (*cb)(int);

    if (*(int *)(((char *)&d_0217ABA8) + 0x24) != 0 && *(int *)(((char *)&d_0217ABA8) + 0x18) == 0 && n == 0)
        IRCi_Send(0, 0, 0xF4, g_0217AAB0[0]);
    cb = *(void (**)(int))(((char *)&d_0217ABA8) + 0xC);
    if (cb != 0)
        cb(n);
    IRCi_ResetState();
}
