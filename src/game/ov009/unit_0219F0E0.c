/*
 * file:     unit_0219F0E0.c
 * unit:     yes
 * function: func_0219F0E0, func_0219F288, func_0219F2F8, func_0219F40C, func_0219F48C, func_0219F50C, func_0219F638, func_0219F674, func_0219F6C8, func_0219F738, func_0219F768, func_0219F7B4, func_0219F7C4, func_0219F7D8, func_0219F830, func_0219F888, func_0219F8B0, func_0219F920, func_0219F978, func_0219F9A8, func_0219FAAC
 * address:  0x0219F0E0
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
 *   func_0219E120  0x0219E120  arm  ov009
 *   func_0219E1B8  0x0219E1B8  arm  ov009
 *   func_0219E0C0  0x0219E0C0  arm  ov009
 *   func_020948E0  0x020948E0  arm
 *   func_0209ABF8  0x0209ABF8  arm
 *   _dsub  0x0209AF34  arm
 *   _d2f  0x0209B64C  arm
 *   _fgr  0x0209BBB0  arm
 *   _fls  0x0209BC74  arm
 *   g_021AEB04  0x021AEB04  data
 *   g_021A8230  0x021A8230  data
 *   strlen  0x0209477C  arm
 *   strcmp  0x020948E0  arm
 *   func_021843C8  0x021843C8  arm  ov009
 *   func_02184234  0x02184234  arm  ov009
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   SBServerGetPublicInetAddress  0x0219E1EC  arm  ov009
 *   SBServerGetPublicQueryPortNBO  0x0219E218  arm  ov009
 *   SBServerSetNext  0x0219E264  arm  ov009
 *   func_0218437C  0x0218437C  arm  ov009
 *   SBServerGetNext  0x0219E26C  arm  ov009
 *   func_0219DFF8  0x0219DFF8  arm  ov009
 *   func_0218452C  0x0218452C  arm  ov009
 *   func_02184144  0x02184144  arm  ov009
 *   func_0219DF64  0x0219DF64  arm  ov009
 *   func_0218482C  0x0218482C  arm  ov009
 *   func_0217F1E0  0x0217F1E0  arm  ov009
 *   func_0218474C  0x0218474C  arm  ov009
 *   func_021847BC  0x021847BC  arm  ov009
 *   func_021803BC  0x021803BC  arm  ov009
 *   SBServerListSetLastError  0x021A0A1C  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_020946C8  0x020946C8  arm
 *   SocketStartUp  0x0217F25C  arm  ov009
 *   g_021ACEF8  0x021ACEF8  data
 *   func_0209477C  0x0209477C  arm
 *   func_020949F4  0x020949F4  arm
 *   func_021A02E0  0x021A02E0  arm  ov009
 *   g_021A821C  0x021A821C  data
 *   g_021AEB00  0x021AEB00  data
 */
struct SBQueryEngine;
struct SBServerList;
struct ServerBrowser;
typedef struct SBServer {
    unsigned int publicip;
    unsigned short publicport;
    unsigned int privateip;
    unsigned short privateport;
    unsigned int icmpip;
    unsigned char state;
    unsigned char flags;
    void *keyvals;
    unsigned int updatetime;
    unsigned int querychallenge;
    struct SBServer *next;
    unsigned char splitResponseBitmap;
} SBServer;

typedef struct SBServerFIFO {
    SBServer *first;
    SBServer *last;
    int count;
} SBServerFIFO;

typedef void (*SBEngineCB)(struct SBQueryEngine *engine, int reason, SBServer *server, void *instance);

typedef void (*SBListCB)(struct SBServerList *, int, SBServer *, void *);

typedef void (*SBMaploopCB)(struct SBServerList *slist, void *server, long changeTime, int count, char **mapList, void *instance);

typedef void (*SBPlayerSearchCB)(struct SBServerList *, char *, unsigned int, unsigned short, long, char *, void *);

typedef void (*SBBrowserCB)(struct ServerBrowser *, int, SBServer *, void *);

typedef struct SBQueryEngine {
    int queryversion;
    int maxupdates;
    SBServerFIFO querylist;
    SBServerFIFO pendinglist;
    int querysock;
    int icmpsock;
    unsigned int mypublicip;
    unsigned char serverkeys[40];
    int numserverkeys;
    SBEngineCB ListCallback;
    void *instance;
} SBQueryEngine;

typedef struct SBSortInfo {
    char sortkey[256];
    int comparemode;
} SBSortInfo;

typedef struct SBServerList {
    int state;
    void *servers;
    void *keylist;
    char queryforgamename[36];
    char queryfromgamename[36];
    char queryfromkey[32];
    char mychallenge[8];
    unsigned char *inbuffer;
    int inbufferlen;
    char *popularvalues[255];
    int numpopularvalues;
    int expectedelements;
    SBListCB ListCallback;
    SBMaploopCB MaploopCallback;
    SBPlayerSearchCB PlayerSearchCallback;
    void *instance;
    SBSortInfo currsortinfo;
    SBSortInfo prevsortinfo;
    int sortascending;
    unsigned int mypublicip;
    unsigned int srcip;
    unsigned short defaultport;
    char *lasterror;
    int slsocket;
    unsigned int lanstarttime;
    int fromgamever;
    char cryptkey[0x108];
    int queryoptions;
    int pstate;
    unsigned short backendgameflags;
    char *mLanAdapterOverride;
    SBServer *deadlist;
} SBServerList;

typedef struct ServerBrowser {
    SBQueryEngine engine;
    SBServerList list;
    int disconnectFlag;
    int dontUpdateList;
    unsigned int triggerIP;
    unsigned short triggerPort;
    SBBrowserCB BrowserCallback;
    void *ConnectCallback;
    void *instance;
} ServerBrowser;

struct G_021AEB04 {
    int pad;
    SBServerList *slist;
};

typedef struct {
    int pad0;
    SBServerList *slist;
} SBSortGlobals;

struct Ref { char *str; int refcount; };

typedef unsigned int   u32;

typedef unsigned char  u8;

extern int func_0219E120(SBServer *server, char *key, int idefault);
extern double func_0219E1B8(SBServer *server, char *key, double fdefault);
extern char *func_0219E0C0(SBServer *server, char *keyname, char *def);
extern int func_020948E0(const char *a, const char *b);
extern int func_0209ABF8(const char *a, const char *b);
extern unsigned long strlen(const char *s);
extern int strcmp(const char *a, const char *b);
extern void func_021843C8(int *p, int b);
extern void func_02184234(void *array, void *newElem);
extern int func_02184200(const int *p);
extern void *func_02184208();
extern int SBServerGetPublicInetAddress(const int *p);
extern unsigned short SBServerGetPublicQueryPortNBO(const unsigned short *p);
extern void SBServerSetNext(int *p, int v);
extern void func_0218437C(int a, int b);
extern int SBServerGetNext(const int *p);
extern void func_0219DFF8(void *elem);
extern void func_0218452C(void *a);
extern void *func_02184144(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void *func_0219DF64(void *l);
extern struct Ref *func_0218482C(void *t, void *k);
extern char *func_0217F1E0(char *s);
extern void func_0218474C(void *t, void *e);
extern int func_021847BC(void *t, void *k);
extern int func_021803BC(char *dst, const char *src, unsigned int n);
extern void SBServerListSetLastError(int *p, int v);
extern unsigned int func_0217F264(void);
extern void func_020946C8(unsigned int seed);
extern void SocketStartUp(void);
extern int func_0209477C(const u8 *s);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern void func_021A02E0(SBServerList *slist);
/* * sdk: prevKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) * * _d2f (0x0209B64C) is a recorded MSL runtime row (layout/runtime_arm9.txt), matched in * src/matched/arm9/d2f.c, so its call sites are attested. */ int func_0219F0E0(SBServer *server1, SBServer *server2);
/* * sdk: IntKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ int func_0219F288(void *entry1, void *entry2);
/* * sdk: FloatKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o) * * _d2f (0x0209B64C) is a recorded MSL runtime row (layout/runtime_arm9.txt), matched in * src/matched/arm9/d2f.c, so its call sites are attested. */ int func_0219F2F8(void *entry1, void *entry2);
/* * sdk: StrCaseKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ int func_0219F40C(void *entry1, void *entry2);
/* * sdk: StrNoCaseKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ int func_0219F48C(void *entry1, void *entry2);
/* * sdk: SBServerListSort (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o) */ void func_0219F50C(SBServerList *slist, int ascending, SBSortInfo sortinfo);
/* * sdk: SBServerListAppendServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ void func_0219F638(SBServerList *slist, SBServer *server);
/* * sdk: SBServerListFindServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ int func_0219F674(SBServerList *slist, void *findserver);
/* * sdk: SBServerListFindServerByIP (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ int func_0219F6C8(SBServerList *slist, unsigned int ip, unsigned short port);
/* * sdk: AddServerToDeadlist (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ void func_0219F738(SBServerList *slist, SBServer *server);
/* * sdk: SBServerListRemoveAt (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ void func_0219F768(SBServerList *slist, int index);
void SBServerListCount(void *list);
int func_0219F7C4(int *p);
void func_0219F7D8(SBServerList *slist);
void func_0219F830(SBServerList *slist);
/* * sdk: SBAllocateServerList (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ void func_0219F888(SBServerList *slist);
/* * sdk: SBRefStr (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ char *func_0219F8B0(void *slist, char *str);
/* * sdk: SBReleaseStr (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ void func_0219F920(void *slist, char *str);
/* * sdk: NTSLengthSB (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ int func_0219F978(char *buf, int len);
/* * sdk: SBServerListInit (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o) */ void func_0219F9A8(SBServerList *slist, char *queryForGamename, char *queryFromGamename, char *queryFromKey, int queryFromVersion, int lanBrowse, SBListCB callback, void *instance);
/* * sdk: ErrorDisconnect (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ void func_0219FAAC(SBServerList *slist);
extern struct G_021AEB04 g_021AEB04;
extern volatile unsigned char g_021A8230[];
extern int g_021ACEF8;
extern char *g_021A821C;
extern void *g_021AEB00;






/*
 * sdk:      prevKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * _d2f (0x0209B64C) is a recorded MSL runtime row (layout/runtime_arm9.txt), matched in
 * src/matched/arm9/d2f.c, so its call sites are attested.
 */
int func_0219F0E0(SBServer *server1, SBServer *server2)
{
    char *prevsortkey;
    int diff;
    double f;

    prevsortkey = g_021AEB04.slist->prevsortinfo.sortkey;
    switch (g_021AEB04.slist->prevsortinfo.comparemode) {
    case 0:
        diff = func_0219E120(server1, prevsortkey, 0) - func_0219E120(server2, prevsortkey, 0);
        break;
    case 1:
        f = func_0219E1B8(server1, prevsortkey, 0) - func_0219E1B8(server2, prevsortkey, 0);
        if (!g_021AEB04.slist->sortascending)
            f = 0 - f;
        if ((float)f > 0)
            return 1;
        if ((float)f < 0)
            return -1;
        return 0;
    case 2:
        diff = func_020948E0(func_0219E0C0((SBServer *)server1, prevsortkey, (char *)g_021A8230), func_0219E0C0((SBServer *)server2, prevsortkey, (char *)g_021A8230));
        break;
    case 3:
        diff = func_0209ABF8(func_0219E0C0((SBServer *)server1, prevsortkey, (char *)g_021A8230), func_0219E0C0((SBServer *)server2, prevsortkey, (char *)g_021A8230));
        break;
    default:
        return 0;
    }
    if (!g_021AEB04.slist->sortascending)
        diff = -diff;
    return diff;
}





/*
 * sdk:      IntKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int func_0219F288(void *entry1, void *entry2)
{
	char *currsortkey;
	int diff;
	void *server1;
	void *server2;
	server1 = *(void **)entry1;
	server2 = *(void **)entry2;
	currsortkey = g_021AEB04.slist->currsortinfo.sortkey;
	diff = func_0219E120(server1, currsortkey, 0) - func_0219E120(server2, currsortkey, 0);
	if (diff == 0)
		return func_0219F0E0(server1, server2);
	if (g_021AEB04.slist->sortascending == 0)
		diff = -diff;
	return diff;
}






/*
 * sdk:      FloatKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 *
 * _d2f (0x0209B64C) is a recorded MSL runtime row (layout/runtime_arm9.txt), matched in
 * src/matched/arm9/d2f.c, so its call sites are attested.
 */
int func_0219F2F8(void *entry1, void *entry2)
{
    SBServer *server1 = *(SBServer **)entry1;
    SBServer *server2 = *(SBServer **)entry2;
    double f;
    char *currsortkey = g_021AEB04.slist->currsortinfo.sortkey;

    f = func_0219E1B8(server1, currsortkey, 0) - func_0219E1B8(server2, currsortkey, 0);
    if (!((float)f > 0 || (float)f < 0))
        return func_0219F0E0(server1, server2);
    if (!g_021AEB04.slist->sortascending)
        f = 0 - f;
    if ((float)f > 0)
        return 1;
    if ((float)f < 0)
        return -1;
    return 0;
}





/*
 * sdk:      StrCaseKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int func_0219F40C(void *entry1, void *entry2)
{
	char *currsortkey;
	int diff;
	void *server1;
	void *server2;
	server1 = *(void **)entry1;
	server2 = *(void **)entry2;
	currsortkey = g_021AEB04.slist->currsortinfo.sortkey;
	diff = func_020948E0(func_0219E0C0(server1, currsortkey, (char *)g_021A8230), func_0219E0C0(server2, currsortkey, (char *)g_021A8230));
	if (diff == 0)
		return func_0219F0E0(server1, server2);
	if (g_021AEB04.slist->sortascending == 0)
		diff = -diff;
	return diff;
}





/*
 * sdk:      StrNoCaseKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int func_0219F48C(void *entry1, void *entry2)
{
	char *currsortkey;
	int diff;
	void *server1;
	void *server2;
	server1 = *(void **)entry1;
	server2 = *(void **)entry2;
	currsortkey = g_021AEB04.slist->currsortinfo.sortkey;
	diff = func_0209ABF8(func_0219E0C0(server1, currsortkey, (char *)g_021A8230), func_0219E0C0(server2, currsortkey, (char *)g_021A8230));
	if (diff == 0)
		return func_0219F0E0(server1, server2);
	if (g_021AEB04.slist->sortascending == 0)
		diff = -diff;
	return diff;
}






/*
 * sdk:      SBServerListSort (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 */
void func_0219F50C(SBServerList *slist, int ascending, SBSortInfo sortinfo)
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
void func_0219F638(SBServerList *slist, SBServer *server)
{
    func_02184234(slist->servers, &server);
    slist->ListCallback(slist, 0, server, slist->instance);
}





/*
 * sdk:      SBServerListFindServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int func_0219F674(SBServerList *slist, void *findserver)
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
int func_0219F6C8(SBServerList *slist, unsigned int ip, unsigned short port)
{
	int numservers;
	void *server;
	int i;
	numservers = func_02184200(slist->servers);
	for (i = 0; i < numservers; i++) {
		server = *(void **)func_02184208(slist->servers, i);
		if (ip == SBServerGetPublicInetAddress(server) && port == SBServerGetPublicQueryPortNBO(server))
			return i;
	}
	return -1;
}






/*
 * sdk:      AddServerToDeadlist (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219F738(SBServerList *slist, SBServer *server)
{
    if (slist->deadlist == 0)
        SBServerSetNext((int *)server, 0);
    else
        SBServerSetNext((int *)server, (int)slist->deadlist);
    slist->deadlist = server;
}




/*
 * sdk:      SBServerListRemoveAt (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219F768(SBServerList *slist, int index)
{
	SBServer *server;
	server = *(SBServer **)func_02184208(slist->servers, index);
	slist->ListCallback(slist, 2, server, slist->instance);
	func_0218437C((int)slist->servers, index);
	func_0219F738((SBServerList *)slist, (SBServer *)server);
}





void SBServerListCount(void *list)
{
    func_02184200(*(void **)((char *)list + 4));
}




/*
 * Word at the block func_02184208 returns, on the word at +4.
 */
int func_0219F7C4(int *p)
{
    return *(int *)func_02184208(p[1]);
}



/*
 * sdk:      SBFreeDeadList (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219F7D8(SBServerList *slist)
{
	void *next;
	void *server;
	next = slist->deadlist;
	if (next == 0)
		return;
	for (server = next; server != 0; server = next) {
		next = (void *)SBServerGetNext(server);
		func_0219DFF8(&server);
	}
	slist->deadlist = 0;
}



/*
 * sdk:      SBServerListClear (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219F830(SBServerList *slist)
{
	int i;
	int nservers;
	nservers = func_02184200(slist->servers);
	for (i = 0; i < nservers; i++)
		func_0219F738((SBServerList *)slist, *(void **)func_02184208(slist->servers, i));
	func_0218452C(slist->servers);
	func_0219F7D8(slist);
}




/*
 * sdk:      SBAllocateServerList (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219F888(SBServerList *slist)
{
    slist->servers = func_02184144(4, 100, 0);
    slist->deadlist = 0;
}



/*
 * sdk:      SBRefStr (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
char *func_0219F8B0(void *slist, char *str)
{
	struct Ref ref;
	struct Ref *val;
	ref.str = str;
	val = func_0218482C(func_0219DF64(slist), &ref);
	if (val != 0) {
		val->refcount++;
		return val->str;
	}
	ref.str = func_0217F1E0(str);
	ref.refcount = 1;
	func_0218474C(func_0219DF64(slist), &ref);
	return ref.str;
}



/*
 * sdk:      SBReleaseStr (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219F920(void *slist, char *str)
{
	struct Ref ref;
	struct Ref *val;
	ref.str = str;
	val = func_0218482C(func_0219DF64(slist), &ref);
	if (val == 0)
		return;
	if (--val->refcount == 0)
		func_021847BC(func_0219DF64(slist), &ref);
}



/*
 * sdk:      NTSLengthSB (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int func_0219F978(char *buf, int len)
{
    int i;

    for (i = 0; i < len; i++) {
        if (buf[i] == 0)
            return i + 1;
    }
    return -1;
}




/*
 * sdk:      SBServerListInit (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 */
void func_0219F9A8(SBServerList *slist, char *queryForGamename, char *queryFromGamename, char *queryFromKey,
                   int queryFromVersion, int lanBrowse, SBListCB callback,
                   void *instance)
{
    if (!lanBrowse && g_021ACEF8 != 1)
        return;
    slist->state = 1;
    func_0219F888(slist);
    func_0219DF64(slist);
    func_021803BC(slist->queryforgamename, queryForGamename, 36);
    func_021803BC(slist->queryfromgamename, queryFromGamename, 36);
    func_021803BC(slist->queryfromkey, queryFromKey, 32);
    slist->ListCallback = callback;
    slist->MaploopCallback = 0;
    slist->mypublicip = 0;
    slist->inbuffer = 0;
    slist->inbufferlen = 0;
    slist->keylist = 0;
    slist->numpopularvalues = 0;
    slist->srcip = 0;
    slist->instance = instance;
    slist->slsocket = -1;
    slist->expectedelements = -1;
    slist->fromgamever = queryFromVersion;
    slist->currsortinfo.sortkey[0] = g_021A8230[0];
    slist->prevsortinfo.sortkey[0] = g_021A8230[0];
    SBServerListSetLastError((int *)slist, (int)((char *)(unsigned char *)g_021A8230));
    slist->mLanAdapterOverride = 0;
    slist->backendgameflags = 0x80;
    func_020946C8(func_0217F264());
    SocketStartUp();
}



/*
 * sdk:      ErrorDisconnect (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219FAAC(SBServerList *slist)
{
	int len = slist->inbufferlen;
	char *q;
	if (len > 0 && len > (unsigned int)func_0209477C((const u8 *)(q = g_021A821C))) {
		char *e = g_021A821C;
		char *s = (char *)slist->inbuffer;
		if (func_020949F4((const u8 *)s, (const u8 *)e, (unsigned int)func_0209477C((const u8 *)e)) == 0) {
			SBServerListSetLastError((int *)slist, (int)(s + (unsigned int)func_0209477C((const u8 *)q)));
			slist->ListCallback(slist, 5, g_021AEB00, slist->instance);
		}
	}
	slist->ListCallback(slist, 4, g_021AEB00, slist->instance);
	func_021A02E0(slist);
}
