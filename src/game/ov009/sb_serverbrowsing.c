/*
 * file:     sb_serverbrowsing.c
 * unit:     yes
 * function: func_0219E9F4, EngineCallback, ServerBrowserNewA, ServerBrowserFree, ServerBrowserBeginUpdate2, ServerBrowserLimitUpdateA, ServerBrowserSendMessageToServerA, ServerBrowserSendNatNegotiateCookieToServerA, ServerBrowserRemoveServer, ServerBrowserThink, ServerBrowserHalt, ServerBrowserClear, ServerBrowserState, ServerBrowserGetServer, ServerBrowserCount, ServerBrowserSortA, ServerBrowserGetMyPublicIPAddr
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
 * Public address of this console, as the list server reported it.
 *
 * symbols:
 *   SBQueryEngineUpdateServer  0x0219D928  arm  ov009
 *   SBQueryEngineRemoveServerFromFIFOs  0x0219DF04  arm  ov009
 *   SBServerListDisconnect  0x021A02E0  arm  ov009
 *   ArrayLength  0x02184200  arm  ov009
 *   SBQueryEngineSetPublicIP  0x0219D8D8  arm  ov009
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   SBServerListInit  0x0219F9A8  arm  ov009
 *   SBQueryEngineInit  0x0219D864  arm  ov009
 *   gGsAvailabilityState  0x021ACEF8  data
 *   SBServerListCleanup  0x021A0340  arm  ov009
 *   SBEngineCleanup  0x0219D8FC  arm  ov009
 *   NNFreeNegotiateList  0x0219922C  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   strlen  0x0209477C  arm
 *   OS_SPrintf  0x02084F40  arm
 *   SBQueryEngineAddQueryKey  0x0219DEE8  arm  ov009
 *   SBServerListConnectAndQuery  0x0219FFD4  arm  ov009
 *   msleep  0x0217F2BC  arm  ov009
 *   g_021A81DC  0x021A81DC  data
 *   g_021A7C90  0x021A7C90  data
 *   g_021A8218  0x021A8218  data
 *   inet_addr  0x0217ED38  arm  ov009
 *   SBSendMessageToServer  0x021A1620  arm  ov009
 *   SBSendNatNegotiateCookieToServer  0x021A174C  arm  ov009
 *   SBServerListFindServer  0x0219F674  arm  ov009
 *   SBServerListRemoveAt  0x0219F768  arm  ov009
 *   NNThink  0x0219A4A4  arm  ov009
 *   SBQueryEngineThink  0x0219DE88  arm  ov009
 *   SBListThink  0x021A1928  arm  ov009
 *   SBEngineHaltUpdates  0x0219D8E0  arm  ov009
 *   SBServerListClear  0x0219F830  arm  ov009
 *   SBServerListNth  0x0219F7C4  arm
 *   SBServerListCount  0x0219F7B4  arm
 *   strcpy  0x02094798  arm
 *   SBServerListSort  0x0219F50C  arm  ov009
 */
#include "sb_server_types.h"

typedef void (*BrowserCB)(ServerBrowser *, int, SBServer *, void *);

struct SortInfo {
    char sortkey[255];
    int comparemode;
};

extern void SBQueryEngineUpdateServer(SBQueryEngine *engine, SBServer *server, int addfront, unsigned int querytype, int usequerychallenge);
extern void SBQueryEngineRemoveServerFromFIFOs(SBQueryEngine *engine, SBServer *server);
extern void SBServerListDisconnect(SBServerList *slist);
extern int ArrayLength(const int *p);
extern void SBQueryEngineSetPublicIP(int *engine, int publicip);
extern void *gsimalloc(unsigned long size);
extern void SBServerListInit(void *slist, char *queryForGamename, char *queryFromGamename, char *queryFromKey,
                          int queryFromVersion, int lanBrowse, void *callback, void *instance);
extern void SBQueryEngineInit(void *engine, int maxupdates, int queryversion, int lanBrowse,
                          void *callback, void *instance);
extern void SBServerListCleanup(SBServerList *slist);
extern void SBEngineCleanup(void *engine);
extern void NNFreeNegotiateList(void);
extern void gsifree(void *ptr);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern unsigned long strlen(const char *s);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern void SBQueryEngineAddQueryKey(char *p, int v);
extern int SBServerListConnectAndQuery(SBServerList *slist, char *fieldList, char *serverFilter, int options, int maxServers);
extern void msleep(unsigned int msec);
extern int inet_addr(int a);
extern int SBSendMessageToServer(void *slist, unsigned int ip, unsigned short port, char *data, int len);
extern int SBSendNatNegotiateCookieToServer(void *slist, unsigned int ip, unsigned short port, int cookie);
extern int SBServerListFindServer(SBServerList *slist, void *findserver);
extern void SBServerListRemoveAt(SBServerList *slist, int index);
extern void NNThink(void *p);
extern void SBQueryEngineThink(void *p);
extern int SBListThink(int *p);
extern void SBEngineHaltUpdates(char *p);
extern void SBServerListClear(SBServerList *slist);
extern SBServer *SBServerListNth(SBServerList *slist, int index);
extern void SBServerListCount(char *p);
extern char *strcpy(char *dst, const char *src);
extern void SBServerListSort(void *slist, int ascending, struct SortInfo sortinfo);
void func_0219E9F4(SBServerList *serverlist, int reason, SBServer *server, void *instance);
void EngineCallback(int unused, unsigned int reason, SBServer *server, void *inst);
ServerBrowser *ServerBrowserNewA(char *queryForGamename, char *queryFromGamename, char *queryFromKey, int queryFromVersion, int maxConcUpdates, int queryVersion, int lanBrowse, BrowserCB callback, void *instance);
void ServerBrowserFree(ServerBrowser *sb);
int ServerBrowserBeginUpdate2(ServerBrowser *sb, int async, int disconnectOnComplete, unsigned char *basicFields, int numBasicFields, char *serverFilter, int updateOptions, int maxServers);
int ServerBrowserLimitUpdateA(ServerBrowser *sb, int async, int disconnectOnComplete, unsigned char *basicFields, int numBasicFields, char *serverFilter, int maxServers);
int ServerBrowserSendMessageToServerA(ServerBrowser *sb, char *ip, unsigned short port, char *data, int len);
int ServerBrowserSendNatNegotiateCookieToServerA(ServerBrowser *sb, char *ip, unsigned short port, int cookie);
void ServerBrowserRemoveServer(ServerBrowser *sb, SBServer *server);
int ServerBrowserThink(char *p);
void ServerBrowserHalt(char *p);
void ServerBrowserClear(char *p);
int ServerBrowserState(char *p);
SBServer *ServerBrowserGetServer(ServerBrowser *sb, int index);
void ServerBrowserCount(char *p);
void ServerBrowserSortA(ServerBrowser *sb, int ascending, char *sortkey, int comparemode);
unsigned int ServerBrowserGetMyPublicIPAddr(const ServerBrowser *browser);
extern int gGsAvailabilityState;
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
            SBQueryEngineUpdateServer(&sb->engine, server, 0, qtype, 1);
        else
            SBQueryEngineUpdateServer(&sb->engine, server, 0, qtype, 0);
        break;
    case 1:
        if (!(server->state & 0x43))
            sb->BrowserCallback(sb, 2, server, sb->instance);
        else
            sb->BrowserCallback(sb, 1, server, sb->instance);
        break;
    case 2:
        if (server->state & 0x2c)
            SBQueryEngineRemoveServerFromFIFOs(&sb->engine, server);
        sb->BrowserCallback(sb, 3, server, sb->instance);
        break;
    case 3:
        if (sb->disconnectFlag)
            SBServerListDisconnect((SBServerList *)serverlist);
        if (ArrayLength(serverlist->servers) == 0 || sb->engine.querylist.count == 0)
            sb->BrowserCallback(sb, 4, 0, sb->instance);
        break;
    case 5:
        sb->BrowserCallback(sb, 5, 0, sb->instance);
        break;
    case 6:
        SBQueryEngineSetPublicIP((int *)(&sb->engine), sb->list.mypublicip);
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
void EngineCallback(int unused, unsigned int reason, SBServer *server, void *inst)
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
ServerBrowser *ServerBrowserNewA(char *queryForGamename, char *queryFromGamename, char *queryFromKey,
                                    int queryFromVersion, int maxConcUpdates, int queryVersion,
                                    int lanBrowse, BrowserCB callback, void *instance)
{
    ServerBrowser *sb;

    if (lanBrowse == 0 && gGsAvailabilityState != 1)
        return 0;
    sb = gsimalloc(0x858);
    if (sb == 0)
        return 0;
    sb->BrowserCallback = callback;
    sb->ConnectCallback = 0;
    sb->instance = instance;
    sb->dontUpdateList = 0;
    SBServerListInit(&sb->list, queryForGamename, queryFromGamename, queryFromKey, queryFromVersion,
                  lanBrowse, func_0219E9F4, sb);
    SBQueryEngineInit(sb, maxConcUpdates, queryVersion, lanBrowse, EngineCallback, sb);
    return sb;
}





/*
 * sdk:      ServerBrowserFree (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
void ServerBrowserFree(ServerBrowser *sb)
{
    SBServerListCleanup(&sb->list);
    SBEngineCleanup(&sb->engine);
    if (sb->ConnectCallback != 0)
        NNFreeNegotiateList();
    gsifree(sb);
}





/*
 * sdk:      ServerBrowserBeginUpdate2 (libdwcgsserverbrowsing.TWL.HYB.a sb_serverbrowsing.o)
 */
int ServerBrowserBeginUpdate2(ServerBrowser *sb, int async, int disconnectOnComplete, unsigned char *basicFields,
                  int numBasicFields, char *serverFilter, int updateOptions, int maxServers)
{
    char keyList[256] = {0};
    int listLen = 0;
    int i;
    int keylen;
    int err;
    char *key;

    if (numBasicFields > 40) {
        gsDebugFormat(4, (char *)4, 2, g_021A81DC);
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
        SBQueryEngineAddQueryKey((char *)sb, basicFields[i]);
    }
    err = SBServerListConnectAndQuery(&sb->list, keyList, serverFilter, updateOptions, maxServers);
    if (err != 0 || async)
        return err;
    while (sb->list.state == 3 || (sb->engine.querylist.count > 0 && err == 0)) {
        msleep(10);
        err = ServerBrowserThink((char *)sb);
    }
    return err;
}




/*
 * sdk:      ServerBrowserLimitUpdateA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
int ServerBrowserLimitUpdateA(ServerBrowser *sb, int async, int disconnectOnComplete,
                  unsigned char *basicFields, int numBasicFields, char *serverFilter, int maxServers)
{
    return ServerBrowserBeginUpdate2(sb, async, disconnectOnComplete, basicFields, numBasicFields,
                         serverFilter, 0x80, maxServers);
}




/*
 * sdk:      ServerBrowserSendMessageToServerA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
int ServerBrowserSendMessageToServerA(ServerBrowser *sb, char *ip, unsigned short port, char *data, int len)
{
    return SBSendMessageToServer(&sb->list, inet_addr((int)ip),
                         (unsigned short)(((port >> 8) & 0xff) | ((port << 8) & 0xff00)), data, len);
}




/*
 * sdk:      ServerBrowserSendNatNegotiateCookieToServerA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
int ServerBrowserSendNatNegotiateCookieToServerA(ServerBrowser *sb, char *ip, unsigned short port, int cookie)
{
    return SBSendNatNegotiateCookieToServer(&sb->list, inet_addr((int)ip),
                         (unsigned short)(((port >> 8) & 0xff) | ((port << 8) & 0xff00)), cookie);
}




/*
 * sdk:      ServerBrowserRemoveServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
void ServerBrowserRemoveServer(ServerBrowser *sb, SBServer *server)
{
    int i;

    i = SBServerListFindServer((SBServerList *)(&sb->list), server);
    if (i != -1)
        SBServerListRemoveAt((SBServerList *)(&sb->list), i);
}




/*
 * Releases the object and the block 0x60 bytes in.
 */
int ServerBrowserThink(char *p)
{
    NNThink(p);
    SBQueryEngineThink(p);
    return SBListThink((int *)(p + 0x60));
}




/*
 * Prepares the block 0x60 bytes in and then the object itself.
 */
void ServerBrowserHalt(char *p)
{
    SBServerListDisconnect((SBServerList *)(p + 0x60));
    SBEngineHaltUpdates(p);
}




/*
 * Calls the two block helpers sixty bytes apart.
 */
void ServerBrowserClear(char *p)
{
    ServerBrowserHalt(p);
    SBServerListClear((SBServerList *)(p + 0x60));
}



/*
 * Maps the +0x10 sign and the +0x60 state word to a small mode code.
 */
int ServerBrowserState(char *p)
{
    int v;

    if (*(int *)(p + 0x10) > 0) return 2;
    v = *(int *)(p + 0x60);
    if (v == 3 || v == 0) return 1;
    if (v == 1) return 0;
    return 3;
}




SBServer *ServerBrowserGetServer(ServerBrowser *sb, int index)
{
    return SBServerListNth(&sb->list, index);
}




/*
 * Tail call on the object 0x60 bytes in.
 *
 *   (ov009's listing emits it as a .word run, ov021's as Thumb code), so
 *   neither `label` nor `sole-ref/code` can attest the ABS32 site.  Witness
 *   class: label / sole-ref/code.
 */
void ServerBrowserCount(char *p)
{
    SBServerListCount(p + 0x60);
}




/*
 * sdk:      ServerBrowserSortA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
void ServerBrowserSortA(ServerBrowser *sb, int ascending, char *sortkey, int comparemode)
{
    struct SortInfo info;

    info.comparemode = comparemode;
    strcpy(info.sortkey, sortkey);
    SBServerListSort(&sb->list, ascending, info);
}


unsigned int ServerBrowserGetMyPublicIPAddr(const ServerBrowser *browser)
{
    return browser->list.mypublicip;
}
