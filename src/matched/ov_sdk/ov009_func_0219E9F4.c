/*
 * function: func_0219E9F4
 * address:  0x0219E9F4
 * packet:   pkt_ov009_0219E9F4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ListCallback (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsin))
 *
 * CLEARED: every byte reproduces; the PC24 to SBQueryEngineSetPublicIP (0x0219D8D8)
 * has no witness: no catalog row, no label, and ov021 overlaps the address.
 *
 * symbols:
 *   func_0219D928  0x0219D928  arm  ov009
 *   func_0219DF04  0x0219DF04  arm  ov009
 *   func_021A02E0  0x021A02E0  arm  ov009
 *   func_02184200  0x02184200  arm  ov009
 *   func_0219D8D8  0x0219D8D8  arm  ov009
 */

typedef struct SBServer {
    unsigned int publicip;
    unsigned short publicport;
    unsigned int privateip;
    unsigned short privateport;
    unsigned int icmpip;
    unsigned char state;
    unsigned char flags;
} SBServer;
typedef struct {
    SBServer *first;
    SBServer *last;
    int count;
} SBServerFIFO;
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
    void *ListCallback;
    void *instance;
} SBQueryEngine;
typedef struct SBServerList {
    int state;
    void *servers;
    char pad8[0x6a4 - 8];
    unsigned int mypublicip;
    char pad6a8[0x7d0 - 0x6a8];
    unsigned short backendgameflags;
    char *mLanAdapterOverride;
    SBServer *deadlist;
} SBServerList;
typedef struct ServerBrowser ServerBrowser;
struct ServerBrowser {
    SBQueryEngine engine;
    SBServerList list;
    int disconnectFlag;
    int dontUpdate;
    unsigned int triggerIP;
    unsigned short triggerPort;
    void (*BrowserCallback)(ServerBrowser *, int, SBServer *, void *);
    void *ConnectCallback;
    void *instance;
};

extern void func_0219D928(struct SBQueryEngine *engine, struct SBServer *server, int addfront, unsigned int querytype, int usequerychallenge);
extern void func_0219DF04(SBQueryEngine *engine, SBServer *server);
extern void func_021A02E0(SBServerList *slist);
extern int func_02184200(const int *p);
extern void func_0219D8D8(SBQueryEngine *engine, unsigned int ip);

void func_0219E9F4(SBServerList *serverlist, int reason, SBServer *server, void *instance)
{
    ServerBrowser *sb = (ServerBrowser *)instance;
    int qtype;

    switch (reason) {
    case 0:
        sb->BrowserCallback(sb, 0, server, sb->instance);
        if ((server->state & 3) && (server->state & 0x40))
            break;
        if ((server->state & 0x2c) || sb->dontUpdate)
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
            func_021A02E0(serverlist);
        if (func_02184200(serverlist->servers) == 0 || sb->engine.querylist.count == 0)
            sb->BrowserCallback(sb, 4, 0, sb->instance);
        break;
    case 5:
        sb->BrowserCallback(sb, 5, 0, sb->instance);
        break;
    case 6:
        func_0219D8D8(&sb->engine, sb->list.mypublicip);
        break;
    case 4:
    case 7:
        break;
    }
    if (server != 0 && server->publicip == sb->triggerIP && server->publicport == sb->triggerPort)
        sb->triggerIP = 0;
}
