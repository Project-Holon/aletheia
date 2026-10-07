/*
 * file:     unit_0219E9F4_p01.c
 * unit:     yes
 * function: func_0219EC74, func_0219ED4C
 * address:  0x0219EC74
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
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_0219F9A8  0x0219F9A8  arm  ov009
 *   func_0219D864  0x0219D864  arm  ov009
 *   func_0219E9F4  0x0219E9F4  arm  ov009
 *   func_0219EBC4  0x0219EBC4  arm  ov009
 *   g_021ACEF8  0x021ACEF8  data
 *   func_021A0340  0x021A0340  arm  ov009
 *   func_0219D8FC  0x0219D8FC  arm  ov009
 *   func_0219922C  0x0219922C  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 */
struct SBServer;
struct ServerBrowser_0219EC74;
struct SBServerList;
typedef void (*BrowserCB)(struct ServerBrowser_0219EC74 *, int, struct SBServer *, void *);

struct ServerBrowser_0219EC74 {
    char pad[0x60];
    char list[0x840 - 0x60];
    int dontUpdate;
    char pad2[0x84c - 0x844];
    BrowserCB BrowserCallback;
    void *ConnectCallback;
    void *instance;
};

struct ServerBrowser_0219ED4C {
    char engine[0x60];
    char list[0x850 - 0x60];
    void *ConnectCallback;
};

extern void *func_0217EAB0(unsigned long size);
extern void func_0219F9A8(void *slist, char *queryForGamename, char *queryFromGamename, char *queryFromKey,
                          int queryFromVersion, int lanBrowse, void *callback, void *instance);
extern void func_0219D864(void *engine, int maxupdates, int queryversion, int lanBrowse,
                          void *callback, void *instance);
extern void func_0219E9F4(struct SBServerList *serverlist, int reason, struct SBServer *server, void *instance);
extern void func_0219EBC4(int unused, unsigned int reason, struct SBServer *server, void *inst);
extern void func_021A0340(struct SBServerList *slist);
extern void func_0219D8FC(void *engine);
extern void func_0219922C(void);
extern void func_0217EAE0(void *ptr);
struct ServerBrowser_0219EC74 *func_0219EC74(char *queryForGamename, char *queryFromGamename, char *queryFromKey, int queryFromVersion, int maxConcUpdates, int queryVersion, int lanBrowse, BrowserCB callback, void *instance);
void func_0219ED4C(struct ServerBrowser_0219ED4C *sb);
extern int g_021ACEF8;


/*
 * sdk:      ServerBrowserNewA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
struct ServerBrowser_0219EC74 *func_0219EC74(char *queryForGamename, char *queryFromGamename, char *queryFromKey,
                                    int queryFromVersion, int maxConcUpdates, int queryVersion,
                                    int lanBrowse, BrowserCB callback, void *instance)
{
    struct ServerBrowser_0219EC74 *sb;

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


/*
 * sdk:      ServerBrowserFree (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
void func_0219ED4C(struct ServerBrowser_0219ED4C *sb)
{
    func_021A0340((struct SBServerList *)(&sb->list));
    func_0219D8FC(&sb->engine);
    if (sb->ConnectCallback != 0)
        func_0219922C();
    func_0217EAE0(sb);
}
