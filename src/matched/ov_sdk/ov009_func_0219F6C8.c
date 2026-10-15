/*
 * function: SBServerListFindServerByIP
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
 *   ArrayLength  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   SBServerGetPublicInetAddress  0x0219E1EC  arm  ov009
 *   SBServerGetPublicQueryPortNBO  0x0219E218  arm  ov009
 */

struct SBL { char pad0[4]; void *servers; };
extern int ArrayLength(const int *p);
extern void *func_02184208(void *a, int n);
extern int SBServerGetPublicInetAddress(const int *p);
extern unsigned short SBServerGetPublicQueryPortNBO(const unsigned short *p);
int SBServerListFindServerByIP(struct SBL *slist, unsigned int ip, unsigned short port)
{
	int numservers;
	void *server;
	int i;
	numservers = ArrayLength(slist->servers);
	for (i = 0; i < numservers; i++) {
		server = *(void **)func_02184208(slist->servers, i);
		if (ip == SBServerGetPublicInetAddress(server) && port == SBServerGetPublicQueryPortNBO(server))
			return i;
	}
	return -1;
}
