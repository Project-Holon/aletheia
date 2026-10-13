/*
 * function: GFL_NET_IRC_WIRELESS_SetState
 * address:  0x0203DC68
 * packet:   pkt_0203DAC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * net_irc_wireless.c.  The state setter of the wireless state machine
 * GFL_NET_IRC_WIRELESS_Main: stores the new state at +0x109.  An unlabelled ARM leaf
 * (no lr save), filed as the `matched` witness for GFL_NET_IRC_WIRELESS_Main's 27 calls.
 *
 */

typedef unsigned char u8;

struct Ctx {
    u8 pad_00[0x109];
    u8 state;
};

void GFL_NET_IRC_WIRELESS_SetState(struct Ctx *p, int state)
{
    p->state = state;
}
