/*
 * file:     sb_serverbrowsing.c
 * unit:     yes
 * function: ListCallback, EngineCallback, ServerBrowserNewA, ServerBrowserFree, ServerBrowserBeginUpdate2, ServerBrowserLimitUpdateA, ServerBrowserSendMessageToServerA, ServerBrowserSendNatNegotiateCookieToServerA, ServerBrowserRemoveServer, ServerBrowserThink, ServerBrowserHalt, ServerBrowserClear, ServerBrowserState, ServerBrowserGetServer, ServerBrowserCount, ServerBrowserSortA, ServerBrowserGetMyPublicIPAddr
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
 *   gQr2RegKeys  0x021A7C90  data
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
#include "sb_server.h"
#include "sb_queryengine.h"
#include "sb_serverlist.h"
#include "sb_server_types.h"


extern void SBQueryEngineUpdateServer(SBQueryEngine *engine, SBServer *server, int addfront, unsigned int querytype, int usequerychallenge);
extern void SBQueryEngineRemoveServerFromFIFOs(SBQueryEngine *engine, SBServer *server);
extern void SBServerListDisconnect(SBServerList *slist);
#include "darray.h"
struct SBQueryEngine;
extern void SBQueryEngineSetPublicIP(struct SBQueryEngine *engine, unsigned int publicip);
#include "gsmemory.h"
extern void SBServerListCleanup(SBServerList *slist);
struct SBQueryEngine;
extern void SBEngineCleanup(struct SBQueryEngine *engine);
#include "natneg.h"
#include "gsdebug.h"
#include "../arm9/msl_string_str.h"
#include "../arm9/os_printf.h"
extern void SBQueryEngineAddQueryKey(struct SBQueryEngine *engine, unsigned char key);
#include "gsplatformutil.h"
#include "gsplatformsocket.h"
struct SBServerList;
extern int SBSendMessageToServer(struct SBServerList *slist, unsigned int ip, unsigned short port, char *data, int len);
extern int SBSendNatNegotiateCookieToServer(void *slist, unsigned int ip, unsigned short port, int cookie);
extern int SBServerListFindServer(SBServerList *slist, void *findserver);
extern void SBServerListRemoveAt(SBServerList *slist, int index);
extern void SBQueryEngineThink(struct SBQueryEngine *engine);
extern void SBEngineHaltUpdates(struct SBQueryEngine *engine);
extern void SBServerListClear(SBServerList *slist);
extern SBServer *SBServerListNth(SBServerList *slist, int index);
extern int SBServerListCount(void *list);
static void ListCallback(SBServerList *serverlist, int reason, SBServer *server, void *instance);
void EngineCallback(struct SBQueryEngine *unused, int reason, SBServer *server, void *inst);
ServerBrowser *ServerBrowserNewA(char *queryForGamename, char *queryFromGamename, char *queryFromKey, int queryFromVersion, int maxConcUpdates, int queryVersion, int lanBrowse, SBBrowserCB callback, void *instance);
void ServerBrowserFree(ServerBrowser *sb);
int ServerBrowserBeginUpdate2(ServerBrowser *sb, int async, int disconnectOnComplete, unsigned char *basicFields, int numBasicFields, char *serverFilter, int updateOptions, int maxServers);
int ServerBrowserLimitUpdateA(ServerBrowser *sb, int async, int disconnectOnComplete, unsigned char *basicFields, int numBasicFields, char *serverFilter, int maxServers);
int ServerBrowserSendMessageToServerA(ServerBrowser *sb, char *ip, unsigned short port, char *data, int len);
int ServerBrowserSendNatNegotiateCookieToServerA(ServerBrowser *sb, char *ip, unsigned short port, int cookie);
void ServerBrowserRemoveServer(ServerBrowser *sb, SBServer *server);
int ServerBrowserThink(ServerBrowser *sb);
void ServerBrowserHalt(ServerBrowser *sb);
void ServerBrowserClear(ServerBrowser *sb);
int ServerBrowserState(ServerBrowser *sb);
SBServer *ServerBrowserGetServer(ServerBrowser *sb, int index);
int ServerBrowserCount(ServerBrowser *sb);
void ServerBrowserSortA(ServerBrowser *sb, int ascending, char *sortkey, int comparemode);
unsigned int ServerBrowserGetMyPublicIPAddr(const ServerBrowser *browser);
extern int gGsAvailabilityState;
extern char g_021A81DC[];
extern char *gQr2RegKeys[];
extern char g_021A8218[];




/*
 * sdk:      ListCallback (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsin))
 *
 * CLEARED: every byte reproduces; the PC24 to SBQueryEngineSetPublicIP (0x0219D8D8)
 * has no witness: no catalog row, no label, and ov021 overlaps the address.
 */
static void ListCallback(SBServerList *serverlist, int reason, SBServer *server, void *instance)
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
        SBQueryEngineSetPublicIP((struct SBQueryEngine *)(&sb->engine), sb->list.mypublicip);
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
void EngineCallback(struct SBQueryEngine *unused, int reason, SBServer *server, void *inst)
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
                                    int lanBrowse, SBBrowserCB callback, void *instance)
{
    ServerBrowser *sb;

    if (lanBrowse == 0 && gGsAvailabilityState != 1)
        return 0;
    sb = gsimalloc(sizeof(*sb));
    if (sb == 0)
        return 0;
    sb->BrowserCallback = callback;
    sb->ConnectCallback = 0;
    sb->instance = instance;
    sb->dontUpdateList = 0;
    SBServerListInit(&sb->list, queryForGamename, queryFromGamename, queryFromKey, queryFromVersion,
                  lanBrowse, ListCallback, sb);
    SBQueryEngineInit(&sb->engine, maxConcUpdates, queryVersion, lanBrowse, EngineCallback, sb);
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
        gsDebugFormat((int)4, (int)4, 2, g_021A81DC);
        return 6;
    }
    sb->disconnectFlag = disconnectOnComplete;
    sb->engine.numserverkeys = 0;
    for (i = 0; i < numBasicFields; i++) {
        key = gQr2RegKeys[basicFields[i]];
        keylen = strlen(key);
        if (listLen + keylen + 1 >= 256)
            break;
        listLen += OS_SPrintf(keyList + listLen, g_021A8218, key);
        SBQueryEngineAddQueryKey((struct SBQueryEngine *)sb, basicFields[i]);
    }
    err = SBServerListConnectAndQuery(&sb->list, keyList, serverFilter, updateOptions, maxServers);
    if (err != 0 || async)
        return err;
    while (sb->list.state == 3 || (sb->engine.querylist.count > 0 && err == 0)) {
        msleep(10);
        err = ServerBrowserThink(sb);
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
    return SBSendMessageToServer(&sb->list, inet_addr(ip),
                         (unsigned short)(((port >> 8) & 0xff) | ((port << 8) & 0xff00)), data, len);
}




/*
 * sdk:      ServerBrowserSendNatNegotiateCookieToServerA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
int ServerBrowserSendNatNegotiateCookieToServerA(ServerBrowser *sb, char *ip, unsigned short port, int cookie)
{
    return SBSendNatNegotiateCookieToServer(&sb->list, inet_addr(ip),
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
int ServerBrowserThink(ServerBrowser *sb)
{
    NNThink();
    SBQueryEngineThink(&sb->engine);
    return SBListThink(&sb->list);
}




/*
 * Prepares the block 0x60 bytes in and then the object itself.
 */
void ServerBrowserHalt(ServerBrowser *sb)
{
    SBServerListDisconnect(&sb->list);
    SBEngineHaltUpdates(&sb->engine);
}




/*
 * Calls the two block helpers sixty bytes apart.
 */
void ServerBrowserClear(ServerBrowser *sb)
{
    ServerBrowserHalt(sb);
    SBServerListClear(&sb->list);
}



/*
 * Maps the +0x10 sign and the +0x60 state word to a small mode code.
 */
int ServerBrowserState(ServerBrowser *sb)
{
    int v;

    if (sb->engine.querylist.count > 0) return 2;
    v = sb->list.state;
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
int ServerBrowserCount(ServerBrowser *sb)
{
    return SBServerListCount(&sb->list);
}




/*
 * sdk:      ServerBrowserSortA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
void ServerBrowserSortA(ServerBrowser *sb, int ascending, char *sortkey, int comparemode)
{
    SBSortInfo info;

    info.comparemode = comparemode;
    strcpy(info.sortkey, sortkey);
    SBServerListSort(&sb->list, ascending, info);
}


unsigned int ServerBrowserGetMyPublicIPAddr(const ServerBrowser *browser)
{
    return browser->list.mypublicip;
}
