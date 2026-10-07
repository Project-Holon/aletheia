/*
 * file:     unit_0219F0E0_p02.c
 * unit:     yes
 * function: func_0219F50C, func_0219F638, func_0219F674, func_0219F6C8, func_0219F738
 * address:  0x0219F50C
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
 *   strlen  0x0209477C  arm
 *   strcmp  0x020948E0  arm
 *   func_021843C8  0x021843C8  arm  ov009
 *   func_0219F288  0x0219F288  arm  ov009
 *   func_0219F2F8  0x0219F2F8  arm  ov009
 *   func_0219F40C  0x0219F40C  arm  ov009
 *   func_0219F48C  0x0219F48C  arm  ov009
 *   g_021AEB04  0x021AEB04  data
 *   func_02184234  0x02184234  arm  ov009
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_0219E1EC  0x0219E1EC  arm  ov009
 *   func_0219E218  0x0219E218  arm  ov009
 *   func_0219E264  0x0219E264  arm  ov009
 */
struct SBServer;
typedef struct {
    char sortkey[255];
    int comparemode;
} SBSortInfo;

typedef struct {
    int state;
    void *servers;
    char pad8[0x490];
    SBSortInfo currsortinfo;
    SBSortInfo prevsortinfo;
    int sortascending;
} SBServerList_0219F50C;

typedef struct {
    int pad0;
    SBServerList_0219F50C *slist;
} SBSortGlobals;

struct SBServerList_0219F638 {
    char pad0[4];
    void *servers;
    char pad1[0x488 - 8];
    void (*ListCallback)(struct SBServerList_0219F638 *, int, struct SBServer *, void *);
    char pad2[8];
    void *instance;
};

struct SBL { char pad0[4]; void *servers; };

struct SBServerList_0219F738 {
    char pad[0x7d8];
    struct SBServer *deadlist;
};

extern unsigned long strlen(const char *s);
extern int strcmp(const char *a, const char *b);
extern void func_021843C8(int *p, int b);
extern int func_0219F288(void *entry1, void *entry2);
extern int func_0219F2F8(void *entry1, void *entry2);
extern int func_0219F40C(void *entry1, void *entry2);
extern int func_0219F48C(void *entry1, void *entry2);
extern void func_02184234(void *array, void *newElem);
extern int func_02184200(const int *p);
extern void *func_02184208(void *a, int n);
extern int func_0219E1EC(const int *p);
extern unsigned short func_0219E218(const unsigned short *p);
extern void func_0219E264(int *p, int v);
void func_0219F50C(SBServerList_0219F50C *slist, int ascending, SBSortInfo sortinfo);
void func_0219F638(struct SBServerList_0219F638 *slist, struct SBServer *server);
int func_0219F674(struct SBL *slist, void *findserver);
int func_0219F6C8(struct SBL *slist, unsigned int ip, unsigned short port);
void func_0219F738(struct SBServerList_0219F738 *slist, struct SBServer *server);
extern SBSortGlobals g_021AEB04;


/*
 * sdk:      SBServerListSort (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 */
void func_0219F50C(SBServerList_0219F50C *slist, int ascending, SBSortInfo sortinfo)
{
    int (*comparator)(void *, void *);

    switch (sortinfo.comparemode) {
    case 0:
        comparator = func_0219F288;
        break;
    case 1:
        comparator = func_0219F2F8;
        break;
    case 2:
        comparator = func_0219F40C;
        break;
    case 3:
        comparator = func_0219F48C;
        break;
    default:
        comparator = func_0219F48C;
        break;
    }
    if (strlen(slist->prevsortinfo.sortkey) == 0) {
        slist->prevsortinfo = sortinfo;
    } else if (strcmp(sortinfo.sortkey, slist->currsortinfo.sortkey) != 0) {
        slist->prevsortinfo = slist->currsortinfo;
    }
    slist->currsortinfo = sortinfo;
    slist->sortascending = ascending;
    g_021AEB04.slist = slist;
    func_021843C8(slist->servers, (int)comparator);
}


/*
 * sdk:      SBServerListAppendServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219F638(struct SBServerList_0219F638 *slist, struct SBServer *server)
{
    func_02184234(slist->servers, &server);
    slist->ListCallback(slist, 0, server, slist->instance);
}

/*
 * sdk:      SBServerListFindServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int func_0219F674(struct SBL *slist, void *findserver)
{
	int numservers, i;
	numservers = func_02184200(slist->servers);
	for (i = 0; i < numservers; i++)
		if (findserver == *(void **)func_02184208(slist->servers, i))
			return i;
	return -1;
}

/*
 * sdk:      SBServerListFindServerByIP (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
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


/*
 * sdk:      AddServerToDeadlist (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219F738(struct SBServerList_0219F738 *slist, struct SBServer *server)
{
    if (slist->deadlist == 0)
        func_0219E264((int *)server, 0);
    else
        func_0219E264((int *)server, (int)slist->deadlist);
    slist->deadlist = server;
}
