/*
 * function: func_0219EC74
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
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_0219F9A8  0x0219F9A8  arm  ov009
 *   func_0219D864  0x0219D864  arm  ov009
 *   func_0219E9F4  0x0219E9F4  arm  ov009
 *   func_0219EBC4  0x0219EBC4  arm  ov009
 *   g_021ACEF8  0x021ACEF8  data
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

extern void *func_0217EAB0(unsigned long size);
extern void func_0219F9A8(void *slist, char *queryForGamename, char *queryFromGamename, char *queryFromKey,
                          int queryFromVersion, int lanBrowse, void *callback, void *instance);
extern void func_0219D864(void *engine, int maxupdates, int queryversion, int lanBrowse,
                          void *callback, void *instance);
extern void func_0219E9F4(void);
extern void func_0219EBC4(void);
extern int g_021ACEF8;

struct ServerBrowser *func_0219EC74(char *queryForGamename, char *queryFromGamename, char *queryFromKey,
                                    int queryFromVersion, int maxConcUpdates, int queryVersion,
                                    int lanBrowse, BrowserCB callback, void *instance)
{
    struct ServerBrowser *sb;

    if (lanBrowse == 0 && g_021ACEF8 != 1)
        return 0;
    sb = func_0217EAB0(0x858);
    if (sb == 0)
        return 0;
    sb->BrowserCallback = callback;
    sb->ConnectCallback = 0;
    sb->instance = instance;
    sb->dontUpdate = 0;
    func_0219F9A8(&sb->list, queryForGamename, queryFromGamename, queryFromKey, queryFromVersion,
                  lanBrowse, func_0219E9F4, sb);
    func_0219D864(sb, maxConcUpdates, queryVersion, lanBrowse, func_0219EBC4, sb);
    return sb;
}
