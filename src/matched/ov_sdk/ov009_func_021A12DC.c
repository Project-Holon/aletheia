/*
 * function: ProcessPushServer
 * address:  0x021A12DC
 * packet:   pkt_ov009_021A12DC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessPushServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   ParseServerIPPort  0x021A059C  arm  ov009
 *   SBServerListFindServerByIP  0x0219F6C8  arm  ov009
 *   SBAllocServer  0x0219E900  arm  ov009
 *   SBIsNullServer  0x0219E9D8  arm  ov009
 *   SBServerListNth  0x0219F7C4  arm  ov009
 *   ParseServer  0x021A060C  arm  ov009
 *   SBServerListAppendServer  0x0219F638  arm  ov009
 */

struct SBL {
	char pad0[0x488];
	void (*cb)(struct SBL *l, int type, void *s, void *ud);
	char pad1[0x494 - 0x48c];
	void *ud;
};
struct SBServer;
struct SBServerList;
extern void ParseServerIPPort(struct SBL *slist, unsigned char *buf, int len, unsigned int *ip, unsigned short *port);
extern int SBServerListFindServerByIP(struct SBL *slist, unsigned int ip, unsigned short port);
struct SBServer;
extern struct SBServer *SBAllocServer(int unused, unsigned int publicip, unsigned short publicport);
extern int SBIsNullServer(int v);
extern void *SBServerListNth(struct SBL *slist, int i);
extern int ParseServer(struct SBL *slist, void *server, char *buf, int len, int usepopularlist);
extern void SBServerListAppendServer(struct SBServerList *slist, struct SBServer *server);
int ProcessPushServer(struct SBL *slist, char *buf, int len)
{
	void *server;
	unsigned int ip;
	unsigned short port;
	int foundexisting;
	int i;
	if (len < 5)
		return 4;
	ParseServerIPPort(slist, (unsigned char *)buf, len, &ip, &port);
	foundexisting = SBServerListFindServerByIP(slist, ip, port);
	if (foundexisting == -1) {
		server = SBAllocServer((int)slist, ip, port);
		if (SBIsNullServer((int)server))
			return 5;
	} else {
		server = SBServerListNth(slist, foundexisting);
	}
	if (ParseServer(slist, server, buf, len, 0) < 0)
		return 4;
	if (foundexisting == -1)
		SBServerListAppendServer((struct SBServerList *)slist, server);
	slist->cb(slist, 1, server, slist->ud);
	return 0;
}
