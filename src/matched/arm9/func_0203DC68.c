/*
 * function: func_0203DC68
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
 * func_0203DC70: stores the new state at +0x109.  An unlabelled ARM leaf
 * (no lr save), filed as the `matched` witness for func_0203DC70's 27 calls.
 *
 */

typedef unsigned char u8;

struct Ctx {
    u8 pad_00[0x109];
    u8 state;
};

void func_0203DC68(struct Ctx *p, int state)
{
    p->state = state;
}
