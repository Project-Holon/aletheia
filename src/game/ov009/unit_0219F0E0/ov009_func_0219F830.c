/*
 * function: func_0219F830
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
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_0219F738  0x0219F738  arm  ov009
 *   func_0218452C  0x0218452C  arm  ov009
 *   func_0219F7D8  0x0219F7D8  arm  ov009
 */

struct SBL { char pad0[4]; void *servers; };
extern int func_02184200(const int *p);
extern void *func_02184208(void *a, int n);
struct SBServer;
struct SBServerList;
extern void func_0219F738(struct SBServerList *slist, struct SBServer *server);
extern void func_0218452C(void *a);
extern void func_0219F7D8(struct SBL *l);
void func_0219F830(struct SBL *slist)
{
	int i;
	int nservers;
	nservers = func_02184200(slist->servers);
	for (i = 0; i < nservers; i++)
		func_0219F738((struct SBServerList *)slist, *(void **)func_02184208(slist->servers, i));
	func_0218452C(slist->servers);
	func_0219F7D8(slist);
}
