/*
 * function: SBServerListRemoveAt
 * address:  0x0219F768
 * packet:   pkt_ov009_0219F768
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerListRemoveAt (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_02184208  0x02184208  arm  ov009
 *   func_0218437C  0x0218437C  arm  ov009
 *   AddServerToDeadlist  0x0219F738  arm  ov009
 */

struct SBS;
struct SBL {
	char pad0[4];
	void *servers;
	char pad1[0x480 - 8];
	char pad2[8];
	void (*cb)(struct SBL *l, int type, struct SBS *s, void *ud);
	char pad3[0x494 - 0x48c];
	void *ud;
};
extern void *func_02184208(void *a, int n);
extern void func_0218437C(int a, int b);
struct SBServer;
struct SBServerList;
extern void AddServerToDeadlist(struct SBServerList *slist, struct SBServer *server);
void SBServerListRemoveAt(struct SBL *slist, int index)
{
	struct SBS *server;
	server = *(struct SBS **)func_02184208(slist->servers, index);
	slist->cb(slist, 2, server, slist->ud);
	func_0218437C((int)slist->servers, index);
	AddServerToDeadlist((struct SBServerList *)slist, (struct SBServer *)server);
}
