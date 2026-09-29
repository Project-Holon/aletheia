/*
 * function: func_0217A5B4
 * address:  0x0217A5B4
 * packet:   pkt_ov015_0217A5B4
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      IRCi_WaitCommand (libirc.a irc_internal.o)
 *
 * symbols:
 *   func_020870D0  0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm
 */

extern unsigned long long func_020870D0(void);

void func_0217A5B4(void)
{
    unsigned long long time;

    time = func_020870D0();
    while ((func_020870D0() - time) * 64000 / 0x82EA < 60)
        ;
}
