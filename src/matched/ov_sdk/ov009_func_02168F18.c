/*
 * function: func_02168F18
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
 *   func_02169E18  0x02169E18  arm
 */

extern int func_02185BD8(void **connection, int profile, int checkCache, int blocking,
                         void (*callback)(void **, void *, void *), void *param);
extern void func_02169E18(void *arg);

int func_02168F18(void **connection, int *arg)
{
    func_02185BD8(connection, *arg, 0, 0, (void (*)(void **, void *, void *))func_02169E18, 0);
    return 1;
}
