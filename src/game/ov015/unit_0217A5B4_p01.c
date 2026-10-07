/*
 * file:     unit_0217A5B4_p01.c
 * unit:     yes
 * function: func_0217A5B4, func_0217A60C, func_0217A648
 * address:  0x0217A5B4
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020870D0  0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm
 *   func_02084EB8  0x02084EB8  arm
 *   g_0217AAB4     0x0217AAB4  data
 *   g_0217AC90     0x0217AC90  data
 *   func_02084F10  0x02084F10  arm
 */
#include "../../matched/include/G_IRCParam.h"

extern unsigned long long func_020870D0(void);
extern long func_02084EB8(void);
extern void func_02084F10(unsigned short lockID);
void func_0217A5B4(void);
void func_0217A60C(void);
void func_0217A648(void);
extern unsigned short g_0217AAB4;
extern struct IRCParam g_0217AC90;


/*
 * sdk:      IRCi_WaitCommand (libirc.a irc_internal.o)
 */
void func_0217A5B4(void)
{
    unsigned long long time;

    time = func_020870D0();
    while ((func_020870D0() - time) * 64000 / 0x82EA < 60)
        ;
}


/*
 * sdk:      IRCi_Init (libirc.a irc_internal.o)
 */
void func_0217A60C(void)
{
    (*(int *)&g_0217AC90) = 1;
    if (g_0217AAB4 != 0xFFFD)
        return;
    g_0217AAB4 = func_02084EB8();
}


/*
 * sdk:      IRCi_End (libirc.a irc_internal.o)
 */
void func_0217A648(void)
{
    if (g_0217AAB4 == -3)
        return;
    func_02084F10(g_0217AAB4);
    g_0217AAB4 = -3;
}
