/*
 * function: func_02168ECC
 * address:  0x02168ECC
 * packet:   pkt_ov009_02168ECC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GPRecvBuddyRequestCallback (dwc_friend.o)
 *
 * symbols:
 *   g_021AA860  0x021AA860  data
 *   func_02185BD8  0x02185BD8  arm
 *   func_02169BB0  0x02169BB0  arm
 */

extern char g_021AA860[];
extern int func_02185BD8(void **connection, int profile, int checkCache, int blocking,
                         void (*callback)(void **, void *, void *), void *param);
extern void func_02169BB0(void **connection, void *arg);

void func_02168ECC(void **connection, int *arg)
{
    if (*(int *)(*(char **)(g_021AA860 + 0xc) + 0x18) == 0) return;
    func_02185BD8(connection, *arg, 0, 0, (void (*)(void **, void *, void *))func_02169BB0, 0);
}
