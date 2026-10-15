/*
 * function: SBServerListCleanup
 * address:  0x021A0340
 * packet:   pkt_ov009_021A0340
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerListCleanup (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   SBServerListDisconnect  0x021A02E0  arm  ov009
 *   SBServerListClear  0x0219F830  arm  ov009
 *   func_0219DFC0  0x0219DFC0  arm  ov009
 *   func_021841B0  0x021841B0  arm  ov009
 */

struct SBServerList {
    char pad[4];
    void *servers;
};

struct SBL;
extern void SBServerListDisconnect(struct SBL *slist);
extern void SBServerListClear(struct SBL *slist);
extern void func_0219DFC0(struct SBServerList *slist);
extern void func_021841B0(void *array);

void SBServerListCleanup(struct SBServerList *slist)
{
    SBServerListDisconnect((struct SBL *)slist);
    SBServerListClear((struct SBL *)slist);
    func_0219DFC0(slist);
    if (slist->servers != 0)
        func_021841B0(slist->servers);
    slist->servers = 0;
}
