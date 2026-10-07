/*
 * function: func_0217A60C
 * address:  0x0217A60C
 * packet:   pkt_ov015_0217A60C
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      IRCi_Init (libirc.a irc_internal.o)
 *
 * symbols:
 *   func_02084EB8  0x02084EB8  arm
 *   g_0217AAB4     0x0217AAB4  data
 *   g_0217AC90     0x0217AC90  data
 */

#include "../include/G_IRCParam.h"

extern long func_02084EB8(void);
extern unsigned short g_0217AAB4;
extern struct IRCParam g_0217AC90;

void func_0217A60C(void)
{
    (*(int *)&g_0217AC90) = 1;
    if (g_0217AAB4 != 0xFFFD)
        return;
    g_0217AAB4 = func_02084EB8();
}
