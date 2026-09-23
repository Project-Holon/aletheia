/*
 * function: func_0203DC4C
 * address:  0x0203DC4C
 * packet:   pkt_0203DAC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * net_irc_wireless.c.  Callback installed at +0x2C by func_0203D8F0 and
 * by states 4 and 14 of func_0203DC70: flags +0x103 of the live context.
 * An unlabelled ARM leaf.
 *
 * symbols:
 *   g_021469F0     0x021469F0  data
 */

typedef unsigned char u8;

struct Ctx {
    u8 pad_00[0x103];
    u8 f103;
};

extern struct Ctx *g_021469F0;

void func_0203DC4C(void)
{
    struct Ctx *p = g_021469F0;

    if (p != 0)
        p->f103 = 1;
}
