/*
 * function: DWCi_GPRecvBuddyAuthCallback
 * address:  0x02168F18
 * packet:   pkt_ov009_02168F18
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GPRecvBuddyAuthCallback (dwc_friend.o)
 *
 * symbols:
 *   func_02185BD8  0x02185BD8  arm
 *   DWCi_GPGetInfoCallback_RecvAuthMessage  0x02169E18  arm
 */

extern int func_02185BD8(void **connection, int profile, int checkCache, int blocking,
                         void (*callback)(void **, void *, void *), void *param);
extern void DWCi_GPGetInfoCallback_RecvAuthMessage(void *arg);

int DWCi_GPRecvBuddyAuthCallback(void **connection, int *arg)
{
    func_02185BD8(connection, *arg, 0, 0, (void (*)(void **, void *, void *))DWCi_GPGetInfoCallback_RecvAuthMessage, 0);
    return 1;
}
