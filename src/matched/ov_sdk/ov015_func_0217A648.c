/*
 * function: func_0217A648
 * address:  0x0217A648
 * packet:   pkt_ov015_0217A648
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      IRCi_End (libirc.a irc_internal.o)
 *
 * symbols:
 *   func_02084F10  0x02084F10  arm
 *   g_0217AAB4     0x0217AAB4  data
 */

extern void func_02084F10(unsigned short lockID);
extern unsigned short g_0217AAB4;

void func_0217A648(void)
{
    if (g_0217AAB4 == -3)
        return;
    func_02084F10(g_0217AAB4);
    g_0217AAB4 = -3;
}
