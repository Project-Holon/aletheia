/*
 * function: func_021A12DC
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
 *   func_021A059C  0x021A059C  arm  ov009
 *   func_0219F6C8  0x0219F6C8  arm  ov009
 *   func_0219E900  0x0219E900  arm  ov009
 *   func_0219E9D8  0x0219E9D8  arm  ov009
 *   func_0219F7C4  0x0219F7C4  arm  ov009
 *   func_021A060C  0x021A060C  arm  ov009
 *   func_0219F638  0x0219F638  arm  ov009
 */

struct SBL {
	char pad0[0x488];
	void (*cb)(struct SBL *l, int type, void *s, void *ud);
	char pad1[0x494 - 0x48c];
	void *ud;
};
struct SBServer;
struct SBServerList;
extern void func_021A059C(struct SBL *slist, unsigned char *buf, int len, unsigned int *ip, unsigned short *port);
extern int func_0219F6C8(struct SBL *slist, unsigned int ip, unsigned short port);
struct SBServer;
extern struct SBServer *func_0219E900(int unused, unsigned int publicip, unsigned short publicport);
extern int func_0219E9D8(int v);
extern void *func_0219F7C4(struct SBL *slist, int i);
extern int func_021A060C(struct SBL *slist, void *server, char *buf, int len, int usepopularlist);
extern void func_0219F638(struct SBServerList *slist, struct SBServer *server);
int func_021A12DC(struct SBL *slist, char *buf, int len)
{
	void *server;
	unsigned int ip;
	unsigned short port;
	int foundexisting;
	int i;
	if (len < 5)
		return 4;
	func_021A059C(slist, (unsigned char *)buf, len, &ip, &port);
	foundexisting = func_0219F6C8(slist, ip, port);
	if (foundexisting == -1) {
		server = func_0219E900((int)slist, ip, port);
		if (func_0219E9D8((int)server))
			return 5;
	} else {
		server = func_0219F7C4(slist, foundexisting);
	}
	if (func_021A060C(slist, server, buf, len, 0) < 0)
		return 4;
	if (foundexisting == -1)
		func_0219F638((struct SBServerList *)slist, server);
	slist->cb(slist, 1, server, slist->ud);
	return 0;
}
