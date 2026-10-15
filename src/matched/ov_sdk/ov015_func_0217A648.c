/*
 * function: IRCi_End
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
 *   OS_ReleaseLockID  0x02084F10  arm
 *   gIrcLockId     0x0217AAB4  data
 */

extern void OS_ReleaseLockID(unsigned short lockID);
extern unsigned short gIrcLockId;

void IRCi_End(void)
{
    if (gIrcLockId == -3)
        return;
    OS_ReleaseLockID(gIrcLockId);
    gIrcLockId = -3;
}
