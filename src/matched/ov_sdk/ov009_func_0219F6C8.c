/*
 * function: func_0219F6C8
 * address:  0x0219F6C8
 * packet:   pkt_ov009_0219F6C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerListFindServerByIP (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_0219E1EC  0x0219E1EC  arm  ov009
 *   func_0219E218  0x0219E218  arm  ov009
 */

struct SBL { char pad0[4]; void *servers; };
extern int func_02184200(const int *p);
extern void *func_02184208(void *a, int n);
extern int func_0219E1EC(const int *p);
extern unsigned short func_0219E218(const unsigned short *p);
int func_0219F6C8(struct SBL *slist, unsigned int ip, unsigned short port)
{
	int numservers;
	void *server;
	int i;
	numservers = func_02184200(slist->servers);
	for (i = 0; i < numservers; i++) {
		server = *(void **)func_02184208(slist->servers, i);
		if (ip == func_0219E1EC(server) && port == func_0219E218(server))
			return i;
	}
	return -1;
}
