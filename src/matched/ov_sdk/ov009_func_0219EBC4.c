/*
 * function: EngineCallback
 * address:  0x0219EBC4
 * packet:   pkt_ov009_0219EBC4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      EngineCallback (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 *
 * symbols:
 */

struct SBServer {
    unsigned int publicip;
    unsigned short publicport;
};

struct ServerBrowser {
    char pad[0x844];
    unsigned int triggerIP;
    unsigned short triggerPort;
    void (*BrowserCallback)(struct ServerBrowser *, int, struct SBServer *, void *);
    void *ConnectCallback;
    void *instance;
};

void EngineCallback(int unused, unsigned int reason, struct SBServer *server, void *inst)
{
    struct ServerBrowser *sb = inst;

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
