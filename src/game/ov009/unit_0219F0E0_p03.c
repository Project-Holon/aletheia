/*
 * file:     unit_0219F0E0_p03.c
 * unit:     yes
 * function: func_0219F768, func_0219F7B4
 * address:  0x0219F768
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02184208  0x02184208  arm  ov009
 *   func_0218437C  0x0218437C  arm  ov009
 *   func_0219F738  0x0219F738  arm  ov009
 *   func_02184200    0x02184200  arm
 */
struct SBS;
struct SBServer;
struct SBServerList;
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
extern void func_0219F738(struct SBServerList *slist, struct SBServer *server);
extern int func_02184200(const int *p);
void func_0219F768(struct SBL *slist, int index);
void DWCi_LSTlPopFront(void *list);

/*
 * sdk:      SBServerListRemoveAt (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219F768(struct SBL *slist, int index)
{
	struct SBS *server;
	server = *(struct SBS **)func_02184208(slist->servers, index);
	slist->cb(slist, 2, server, slist->ud);
	func_0218437C((int)slist->servers, index);
	func_0219F738((struct SBServerList *)slist, (struct SBServer *)server);
}


void DWCi_LSTlPopFront(void *list)
{
    func_02184200(*(void **)((char *)list + 4));
}
