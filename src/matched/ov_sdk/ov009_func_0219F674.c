/*
 * function: func_0219F674
 * address:  0x0219F674
 * packet:   pkt_ov009_0219F674
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerListFindServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 */

struct SBL { char pad0[4]; void *servers; };
extern int func_02184200(const int *p);
extern void *func_02184208(void *a, int n);
int func_0219F674(struct SBL *slist, void *findserver)
{
	int numservers, i;
	numservers = func_02184200(slist->servers);
	for (i = 0; i < numservers; i++)
		if (findserver == *(void **)func_02184208(slist->servers, i))
			return i;
	return -1;
}
