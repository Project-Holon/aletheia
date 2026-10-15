/*
 * function: SBServerListClear
 * address:  0x0219F830
 * packet:   pkt_ov009_0219F830
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerListClear (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   ArrayLength  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   AddServerToDeadlist  0x0219F738  arm  ov009
 *   func_0218452C  0x0218452C  arm  ov009
 *   SBFreeDeadList  0x0219F7D8  arm  ov009
 */

struct SBL { char pad0[4]; void *servers; };
extern int ArrayLength(const int *p);
extern void *func_02184208(void *a, int n);
struct SBServer;
struct SBServerList;
extern void AddServerToDeadlist(struct SBServerList *slist, struct SBServer *server);
extern void func_0218452C(void *a);
extern void SBFreeDeadList(struct SBL *l);
void SBServerListClear(struct SBL *slist)
{
	int i;
	int nservers;
	nservers = ArrayLength(slist->servers);
	for (i = 0; i < nservers; i++)
		AddServerToDeadlist((struct SBServerList *)slist, *(void **)func_02184208(slist->servers, i));
	func_0218452C(slist->servers);
	SBFreeDeadList(slist);
}
