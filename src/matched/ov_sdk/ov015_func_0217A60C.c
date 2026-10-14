/*
 * function: IRCi_Init
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
 *   OS_GetLockID  0x02084EB8  arm
 *   gIrcLockId     0x0217AAB4  data
 *   gIrcCommParamAlias2     0x0217AC90  data
 */

#include "../include/G_IRCParam.h"

extern long OS_GetLockID(void);
extern unsigned short gIrcLockId;
extern struct IRCParam gIrcCommParamAlias2;

void IRCi_Init(void)
{
    (*(int *)&gIrcCommParamAlias2) = 1;
    if (gIrcLockId != 0xFFFD)
        return;
    gIrcLockId = OS_GetLockID();
}
