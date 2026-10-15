/*
 * function: ServerBrowserNewA
 * address:  0x0219EC74
 * packet:   pkt_ov009_0219EC74
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ServerBrowserNewA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 *
 * symbols:
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   SBServerListInit  0x0219F9A8  arm  ov009
 *   SBQueryEngineInit  0x0219D864  arm  ov009
 *   func_0219E9F4  0x0219E9F4  arm  ov009
 *   EngineCallback  0x0219EBC4  arm  ov009
 *   gGsAvailabilityState  0x021ACEF8  data
 */

struct SBServer;
struct ServerBrowser;

typedef void (*BrowserCB)(struct ServerBrowser *, int, struct SBServer *, void *);

struct ServerBrowser {
    char pad[0x60];
    char list[0x840 - 0x60];
    int dontUpdate;
    char pad2[0x84c - 0x844];
    BrowserCB BrowserCallback;
    void *ConnectCallback;
    void *instance;
};

extern void *gsimalloc(unsigned long size);
extern void SBServerListInit(void *slist, char *queryForGamename, char *queryFromGamename, char *queryFromKey,
                          int queryFromVersion, int lanBrowse, void *callback, void *instance);
extern void SBQueryEngineInit(void *engine, int maxupdates, int queryversion, int lanBrowse,
                          void *callback, void *instance);
struct SBServerList;
extern void func_0219E9F4(struct SBServerList *serverlist, int reason, struct SBServer *server, void *instance);
extern void EngineCallback(int unused, unsigned int reason, struct SBServer *server, void *inst);
extern int gGsAvailabilityState;

struct ServerBrowser *ServerBrowserNewA(char *queryForGamename, char *queryFromGamename, char *queryFromKey,
                                    int queryFromVersion, int maxConcUpdates, int queryVersion,
                                    int lanBrowse, BrowserCB callback, void *instance)
{
    struct ServerBrowser *sb;

    if (lanBrowse == 0 && gGsAvailabilityState != 1)
        return 0;
    sb = gsimalloc(0x858);
    if (sb == 0)
        return 0;
    sb->BrowserCallback = callback;
    sb->ConnectCallback = 0;
    sb->instance = instance;
    sb->dontUpdate = 0;
    SBServerListInit(&sb->list, queryForGamename, queryFromGamename, queryFromKey, queryFromVersion,
                  lanBrowse, func_0219E9F4, sb);
    SBQueryEngineInit(sb, maxConcUpdates, queryVersion, lanBrowse, EngineCallback, sb);
    return sb;
}
