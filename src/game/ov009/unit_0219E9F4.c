/*
 * file:     unit_0219E9F4.c
 * unit:     yes
 * function: func_0219E9F4, func_0219EBC4, func_0219EC74, func_0219ED4C, func_0219ED80, func_0219EED4, func_0219EF08, func_0219EF60, func_0219EFA8, func_0219EFD0, func_0219EFF0, func_0219F00C, func_0219F024, func_0219F058, func_0219F068, func_0219F078
 * address:  0x0219E9F4
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
 *   func_0219D928  0x0219D928  arm  ov009
 *   func_0219DF04  0x0219DF04  arm  ov009
 *   func_021A02E0  0x021A02E0  arm  ov009
 *   func_02184200  0x02184200  arm  ov009
 *   func_0219D8D8  0x0219D8D8  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_0219F9A8  0x0219F9A8  arm  ov009
 *   func_0219D864  0x0219D864  arm  ov009
 *   g_021ACEF8  0x021ACEF8  data
 *   func_021A0340  0x021A0340  arm  ov009
 *   func_0219D8FC  0x0219D8FC  arm  ov009
 *   func_0219922C  0x0219922C  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   strlen  0x0209477C  arm
 *   OS_SPrintf  0x02084F40  arm
 *   func_0219DEE8  0x0219DEE8  arm  ov009
 *   func_0219FFD4  0x0219FFD4  arm  ov009
 *   func_0217F2BC  0x0217F2BC  arm  ov009
 *   g_021A81DC  0x021A81DC  data
 *   g_021A7C90  0x021A7C90  data
 *   g_021A8218  0x021A8218  data
 *   func_0217ED38  0x0217ED38  arm  ov009
 *   func_021A1620  0x021A1620  arm  ov009
 *   func_021A174C  0x021A174C  arm  ov009
 *   func_0219F674  0x0219F674  arm  ov009
 *   func_0219F768  0x0219F768  arm  ov009
 *   func_0219A4A4  0x0219A4A4  arm  ov009
 *   func_0219DE88  0x0219DE88  arm  ov009
 *   func_021A1928  0x021A1928  arm  ov009
 *   func_0219D8E0  0x0219D8E0  arm  ov009
 *   func_0219F830  0x0219F830  arm  ov009
 *   func_0219F7C4  0x0219F7C4  arm
 *   func_0219F7B4  0x0219F7B4  arm
 *   func_02094798  0x02094798  arm
 *   func_0219F50C  0x0219F50C  arm  ov009
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
    unsigned char sortkey[256];
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

typedef void (*BrowserCB)(ServerBrowser *, int, SBServer *, void *);

struct SortInfo {
    char sortkey[255];
    int comparemode;
};

extern void func_0219D928(SBQueryEngine *engine, SBServer *server, int addfront, unsigned int querytype, int usequerychallenge);
extern void func_0219DF04(SBQueryEngine *engine, SBServer *server);
extern void func_021A02E0(SBServerList *slist);
extern int func_02184200(const int *p);
extern void func_0219D8D8(int *engine, int publicip);
extern void *func_0217EAB0(unsigned long size);
extern void func_0219F9A8(void *slist, char *queryForGamename, char *queryFromGamename, char *queryFromKey,
                          int queryFromVersion, int lanBrowse, void *callback, void *instance);
extern void func_0219D864(void *engine, int maxupdates, int queryversion, int lanBrowse,
                          void *callback, void *instance);
extern void func_021A0340(SBServerList *slist);
extern void func_0219D8FC(void *engine);
extern void func_0219922C(void);
extern void func_0217EAE0(void *ptr);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern unsigned long strlen(const char *s);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern void func_0219DEE8(char *p, int v);
extern int func_0219FFD4(SBServerList *slist, char *fieldList, char *serverFilter, int options, int maxServers);
extern void func_0217F2BC(unsigned int msec);
extern int func_0217ED38(int a);
extern int func_021A1620(void *slist, unsigned int ip, unsigned short port, char *data, int len);
extern int func_021A174C(void *slist, unsigned int ip, unsigned short port, int cookie);
extern int func_0219F674(SBServerList *slist, void *findserver);
extern void func_0219F768(SBServerList *slist, int index);
extern void func_0219A4A4(void *p);
extern void func_0219DE88(void *p);
extern int func_021A1928(int *p);
extern void func_0219D8E0(char *p);
extern void func_0219F830(SBServerList *slist);
extern int func_0219F7C4(int *p);
extern void func_0219F7B4(char *p);
extern char *func_02094798(char *dst, const char *src);
extern void func_0219F50C(void *slist, int ascending, struct SortInfo sortinfo);
void func_0219E9F4(SBServerList *serverlist, int reason, SBServer *server, void *instance);
void func_0219EBC4(int unused, unsigned int reason, SBServer *server, void *inst);
/* * sdk: ServerBrowserNewA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o)) */ ServerBrowser *func_0219EC74(char *queryForGamename, char *queryFromGamename, char *queryFromKey, int queryFromVersion, int maxConcUpdates, int queryVersion, int lanBrowse, BrowserCB callback, void *instance);
/* * sdk: ServerBrowserFree (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o)) */ void func_0219ED4C(ServerBrowser *sb);
int func_0219ED80(ServerBrowser *sb, int async, int disconnectOnComplete, unsigned char *basicFields, int numBasicFields, char *serverFilter, int updateOptions, int maxServers);
int func_0219EED4(ServerBrowser *sb, int async, int disconnectOnComplete, unsigned char *basicFields, int numBasicFields, char *serverFilter, int maxServers);
/* * sdk: ServerBrowserSendMessageToServerA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o)) */ int func_0219EF08(ServerBrowser *sb, char *ip, unsigned short port, char *data, int len);
/* * sdk: ServerBrowserSendNatNegotiateCookieToServerA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o)) */ int func_0219EF60(ServerBrowser *sb, char *ip, unsigned short port, int cookie);
/* * sdk: ServerBrowserRemoveServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o)) */ void func_0219EFA8(ServerBrowser *sb, SBServer *server);
/* * Releases the object and the block 0x60 bytes in. */ int func_0219EFD0(char *p);
/* * Prepares the block 0x60 bytes in and then the object itself. */ void func_0219EFF0(char *p);
/* * Calls the two block helpers sixty bytes apart. */ void func_0219F00C(char *p);
/* * Maps the +0x10 sign and the +0x60 state word to a small mode code. */ int func_0219F024(char *p);
void func_0219F058(char *p);
/* * Tail call on the object 0x60 bytes in. * * (ov009's listing emits it as a .word run, ov021's as Thumb code), so * neither `label` nor `sole-ref/code` can attest the ABS32 site. Witness * class: label / sole-ref/code. */ void func_0219F068(char *p);
/* * sdk: ServerBrowserSortA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o)) */ void func_0219F078(ServerBrowser *sb, int ascending, char *sortkey, int comparemode);
extern int g_021ACEF8;
extern char g_021A81DC[];
extern char *g_021A7C90[];
extern char g_021A8218[];



/*
 * sdk:      ListCallback (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsin))
 *
 * CLEARED: every byte reproduces; the PC24 to SBQueryEngineSetPublicIP (0x0219D8D8)
 * has no witness: no catalog row, no label, and ov021 overlaps the address.
 */
void func_0219E9F4(SBServerList *serverlist, int reason, SBServer *server, void *instance)
{
    ServerBrowser *sb = (ServerBrowser *)instance;
    int qtype;

    switch (reason) {
    case 0:
        sb->BrowserCallback(sb, 0, server, sb->instance);
        if ((server->state & 3) && (server->state & 0x40))
            break;
        if ((server->state & 0x2c) || sb->dontUpdateList)
            break;
        if (server->flags & 1) {
            if (sb->list.state == 0 || sb->engine.numserverkeys == 0)
                qtype = 1;
            else
                qtype = 0;
        } else
            qtype = 2;
        if (serverlist->backendgameflags & 0x80)
            func_0219D928(&sb->engine, server, 0, qtype, 1);
        else
            func_0219D928(&sb->engine, server, 0, qtype, 0);
        break;
    case 1:
        if (!(server->state & 0x43))
            sb->BrowserCallback(sb, 2, server, sb->instance);
        else
            sb->BrowserCallback(sb, 1, server, sb->instance);
        break;
    case 2:
        if (server->state & 0x2c)
            func_0219DF04(&sb->engine, server);
        sb->BrowserCallback(sb, 3, server, sb->instance);
        break;
    case 3:
        if (sb->disconnectFlag)
            func_021A02E0((SBServerList *)serverlist);
        if (func_02184200(serverlist->servers) == 0 || sb->engine.querylist.count == 0)
            sb->BrowserCallback(sb, 4, 0, sb->instance);
        break;
    case 5:
        sb->BrowserCallback(sb, 5, 0, sb->instance);
        break;
    case 6:
        func_0219D8D8((int *)(&sb->engine), sb->list.mypublicip);
        break;
    case 4:
    case 7:
        break;
    }
    if (server != 0 && server->publicip == sb->triggerIP && server->publicport == sb->triggerPort)
        sb->triggerIP = 0;
}




/*
 * sdk:      EngineCallback (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
void func_0219EBC4(int unused, unsigned int reason, SBServer *server, void *inst)
{
    ServerBrowser *sb = inst;

    switch (reason) {
    case 1:
        sb->BrowserCallback(sb, 2, server, sb->instance);
        break;
    case 0:
        sb->BrowserCallback(sb, 1, server, sb->instance);
        break;
    case 2:
        sb->BrowserCallback(sb, 4, server, sb->instance);
        break;
    case 3:
        sb->BrowserCallback(sb, 6, server, sb->instance);
        return;
    }
    if (server != 0 && server->publicip == sb->triggerIP && server->publicport == sb->triggerPort)
        sb->triggerIP = 0;
}




/*
 * sdk:      ServerBrowserNewA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
ServerBrowser *func_0219EC74(char *queryForGamename, char *queryFromGamename, char *queryFromKey,
                                    int queryFromVersion, int maxConcUpdates, int queryVersion,
                                    int lanBrowse, BrowserCB callback, void *instance)
{
    ServerBrowser *sb;

    if (lanBrowse == 0 && g_021ACEF8 != 1)
        return 0;
    sb = func_0217EAB0(0x858);
    if (sb == 0)
        return 0;
    sb->BrowserCallback = callback;
    sb->ConnectCallback = 0;
    sb->instance = instance;
    sb->dontUpdateList = 0;
    func_0219F9A8(&sb->list, queryForGamename, queryFromGamename, queryFromKey, queryFromVersion,
                  lanBrowse, func_0219E9F4, sb);
    func_0219D864(sb, maxConcUpdates, queryVersion, lanBrowse, func_0219EBC4, sb);
    return sb;
}




/*
 * sdk:      ServerBrowserFree (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
void func_0219ED4C(ServerBrowser *sb)
{
    func_021A0340(&sb->list);
    func_0219D8FC(&sb->engine);
    if (sb->ConnectCallback != 0)
        func_0219922C();
    func_0217EAE0(sb);
}




/*
 * sdk:      ServerBrowserBeginUpdate2 (libdwcgsserverbrowsing.TWL.HYB.a sb_serverbrowsing.o)
 */
int func_0219ED80(ServerBrowser *sb, int async, int disconnectOnComplete, unsigned char *basicFields,
                  int numBasicFields, char *serverFilter, int updateOptions, int maxServers)
{
    char keyList[256] = {0};
    int listLen = 0;
    int i;
    int keylen;
    int err;
    char *key;

    if (numBasicFields > 40) {
        func_0217D254(4, (char *)4, 2, g_021A81DC);
        return 6;
    }
    sb->disconnectFlag = disconnectOnComplete;
    sb->engine.numserverkeys = 0;
    for (i = 0; i < numBasicFields; i++) {
        key = g_021A7C90[basicFields[i]];
        keylen = strlen(key);
        if (listLen + keylen + 1 >= 256)
            break;
        listLen += OS_SPrintf(keyList + listLen, g_021A8218, key);
        func_0219DEE8((char *)sb, basicFields[i]);
    }
    err = func_0219FFD4(&sb->list, keyList, serverFilter, updateOptions, maxServers);
    if (err != 0 || async)
        return err;
    while (sb->list.state == 3 || (sb->engine.querylist.count > 0 && err == 0)) {
        func_0217F2BC(10);
        err = func_0219EFD0((char *)sb);
    }
    return err;
}



/*
 * sdk:      ServerBrowserLimitUpdateA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
int func_0219EED4(ServerBrowser *sb, int async, int disconnectOnComplete,
                  unsigned char *basicFields, int numBasicFields, char *serverFilter, int maxServers)
{
    return func_0219ED80(sb, async, disconnectOnComplete, basicFields, numBasicFields,
                         serverFilter, 0x80, maxServers);
}



/*
 * sdk:      ServerBrowserSendMessageToServerA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
int func_0219EF08(ServerBrowser *sb, char *ip, unsigned short port, char *data, int len)
{
    return func_021A1620(&sb->list, func_0217ED38((int)ip),
                         (unsigned short)(((port >> 8) & 0xff) | ((port << 8) & 0xff00)), data, len);
}



/*
 * sdk:      ServerBrowserSendNatNegotiateCookieToServerA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
int func_0219EF60(ServerBrowser *sb, char *ip, unsigned short port, int cookie)
{
    return func_021A174C(&sb->list, func_0217ED38((int)ip),
                         (unsigned short)(((port >> 8) & 0xff) | ((port << 8) & 0xff00)), cookie);
}



/*
 * sdk:      ServerBrowserRemoveServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
void func_0219EFA8(ServerBrowser *sb, SBServer *server)
{
    int i;

    i = func_0219F674((SBServerList *)(&sb->list), server);
    if (i != -1)
        func_0219F768((SBServerList *)(&sb->list), i);
}



/*
 * Releases the object and the block 0x60 bytes in.
 */
int func_0219EFD0(char *p)
{
    func_0219A4A4(p);
    func_0219DE88(p);
    return func_021A1928((int *)(p + 0x60));
}



/*
 * Prepares the block 0x60 bytes in and then the object itself.
 */
void func_0219EFF0(char *p)
{
    func_021A02E0((SBServerList *)(p + 0x60));
    func_0219D8E0(p);
}



/*
 * Calls the two block helpers sixty bytes apart.
 */
void func_0219F00C(char *p)
{
    func_0219EFF0(p);
    func_0219F830((SBServerList *)(p + 0x60));
}


/*
 * Maps the +0x10 sign and the +0x60 state word to a small mode code.
 */
int func_0219F024(char *p)
{
    int v;

    if (*(int *)(p + 0x10) > 0) return 2;
    v = *(int *)(p + 0x60);
    if (v == 3 || v == 0) return 1;
    if (v == 1) return 0;
    return 3;
}



void func_0219F058(char *p)
{
    func_0219F7C4((int *)(p + 0x60));
}



/*
 * Tail call on the object 0x60 bytes in.
 *
 *   (ov009's listing emits it as a .word run, ov021's as Thumb code), so
 *   neither `label` nor `sole-ref/code` can attest the ABS32 site.  Witness
 *   class: label / sole-ref/code.
 */
void func_0219F068(char *p)
{
    func_0219F7B4(p + 0x60);
}



/*
 * sdk:      ServerBrowserSortA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
void func_0219F078(ServerBrowser *sb, int ascending, char *sortkey, int comparemode)
{
    struct SortInfo info;

    info.comparemode = comparemode;
    func_02094798(info.sortkey, sortkey);
    func_0219F50C(&sb->list, ascending, info);
}
